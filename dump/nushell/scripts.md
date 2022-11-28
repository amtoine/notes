# SOME `nushell` SCRIPTS

## https://discord.com/channels/601130461678272522/601130461678272524/1038560974229229579
```bash
let data = (
    fetch "http://loripsum.net/api/1000/short/headers" |
    split words |
    sort |
    each {
        |i| 
        {name: $i}
    } |
    into df |
    unique
)  
```

## https://discord.com/channels/601130461678272522/614593951969574961/1038611113014730762
```bash
def tolink [name: string] {
    let url = $in
    let pre = "\e]8;;"
    let sp = "\e\\"
    $"($pre)($url)($sp)($name)($pre)($sp)"

}
```**USAGE**:
```bash
$nu.home-path | tolink HOME
```

## https://discord.com/channels/601130461678272522/615253963645911060/1038782903338930236
```bash
def words [
  filename: string # Text file
] {
  let stopwords = (open ~/GD/TEKST/stopord.txt | lines | into df)
  let corpus = (open $filename | str downcase | split words | into df)
  let mask = ($corpus | is-in $stopwords)
  let tidy = ($corpus | filter-with ($mask | df-not))
  let frequency = ($tidy | value-counts)
  let sorted = ($frequency | sort-by counts | reverse)
  $sorted
}
```

## wait-until
```bash
def wait-until [
    cond: block
    retry_interval: duration = 500ms
    timeout: duration = 3sec
] {
    if not (do $cond) {
        sleep $retry_interval
        if $timeout <= 0sec {
            false
        } else {
            wait-until $cond $retry_interval ($timeout - $retry_interval)
        }
    }
}
```

## https://discord.com/channels/601130461678272522/615253963645911060/1040176867782688778
> Takes a new screenshot using maim and copies to clipboard + save to screenshots folder
```bash
#!/usr/bin/env nu

maim -s | xclip -selection clipboard -t image/png

if ($env.LAST_EXIT_CODE == 0) {
    let file = ("screenshot-" + (date now | date format %F_%T) + ".png")
    let path = ($env.HOME | path join "Media/Screenshots" | path join $file)
    xclip -selection clipboard -t image/png -o | save $path)    
}
```

## https://discord.com/channels/601130461678272522/615253963645911060/1040309468774277150
**Parse urls pipeline**
```zsh
def parse-urls [] {
    $in | 
      parse -r '(https?:\/\/(?:www\.)?[-a-zA-Z0-9@:%._\+~#=]{1,256}\.[a-zA-Z0-9()]{1,6}\b(?:[-a-zA-Z0-9()@:%_\+.~#?&\/=]*))' | 
      rename urls
}
```
Example:
```zsh
fetch https://builder.blender.org/download | parse-urls | find -r ".dmg$"
```

## https://discord.com/channels/601130461678272522/614593951969574961/1041156340699123712
Does this work on linux?
```bash
alias ips = (ifconfig -a | lines | find "inet " | split column " " | get column2 | rotate --ccw | insert extern (curl -s ifconfig.me))
```

## https://discord.com/channels/601130461678272522/615253963645911060/1041154674616700978
```bash
def rand_color () {
   let rgb = [(random integer 1..255) (random integer 1..255) (random integer 1..255)]
   $"#($rgb |each {|it| let v = ($it |fmt |get upperhex|str replace "0x" ""); if $v in (seq 1 9 |each { |it| $it |into string}) {$v |str lpad -l 2 -c "0"} else { $v }  }| str collect )"
}


def color_char ($c:string) {
   $"(ansi -e { fg: (rand_color) bg: (rand_color) attr: b })($c)(ansi reset)"
}

def color_echo (
...rest # text
--word(-w) # by word
) {
  if $word {
    $rest | each { |it|  color_char $it } |str collect " "
  } else {
    $rest |str collect " " | split chars | each { |it|  color_char $it } |str collect
  }
}
```

## https://discord.com/channels/601130461678272522/615253963645911060/1041716927803961384
```bash
# Asks user for confirmation 
export def confirm [
    --affirmative="Yes"    # The title of the affirmative action
    --negative="No"        # The title of the negative action
    --timeout=0            # Timeout for confirmation ($GUM_CONFIRM_TIMEOUT)
] {
    let cmd = (gum confirm --affirmative $affirmative --negative $negative --timeout $timeout | complete)
    $cmd.exit_code == 0
}

# Interactive PR checkout
export def "git icheckout" [] {
    let prs = (gh pr list | lines | parse "{pr_id}\t{title}\t{rest}"| str trim | reject rest)
    $prs | to csv | gum choose | from csv --noheaders | get column1 | gh pr checkout $in
}


# Interactive Brew uninstall
def "ibrew uninstall" [] {
    brew list | gum choose --no-limit | split row "\n" | each {|it| brew uninstall $it}
}
```

## command palette
I've been enjoying using this thing. It brings up an fzf "command palette" menu of available operations (i.e. nushell commands you want to run for side effects, but you don't need to actually type them into a prompt and hit enter)
```rust
# M-x keybinding in config.nu:
# {
#   name: M-x
#   modifier: alt
#   keycode: char_x
#   mode: [emacs, vi_normal, vi_insert]
#   event: [
#     {
#       send: executehostcommand,
#       cmd: "M-x"
#     }
#   ]
# }

export def M-x [] {
  let cmd = (COMMANDS | str join "\n"
                      | fzf '--height' 10 '--layout' reverse-list)
  if $cmd == 'app' {
    open-app
  } else if $cmd == 'book' {
    open-book
  } else if $cmd == 'project' {
    my-tmux-project-switcher
  }
}

def COMMANDS [] {
  ['app' 'book' 'project']
}

def open-app [] {
  fd -d 1 '.+\.app' /Applications /System/Applications /System/Applications/Utilities
    | rg -r '$2$1' '^(.*/([^/]+)\.app)/$'
    | fzf '--with-nth' 1 '-d' /
    | str replace '[^/]+/' '/'
    | and-then { ^open $in }
}

def open-book [] {
  fd -d 1 '.+\.pdf' `~/MyBooks`
  | fzf '-d' / '--with-nth' 7
  | str trim -r
  | and-then { ^open $in }
}

def fzf [...args] {
  ^fzf --cycle --info hidden --ansi --color light --exact --prompt='  ' --bind right:accept,left:abort $args | str trim -r
}

def and-then [block: block] {
  if not ($in | is-empty) {
    do $block
  }
}
```