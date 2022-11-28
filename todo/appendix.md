## Appendix A
```bash
> "CAIYECAIIAg" | decode base64
Error:
  × value could not be base64 decoded
   ╭─[entry #62:1:1]
 1 │ "CAIYECAIIAg" | decode base64
   ·                 ──────┬──────
   ·                       ╰── invalid base64 input for character set standard
   ╰────
```

## Appendix B
content of `~/.rustup/settings.toml`
```toml
default_host_triple = "x86_64-unknown-linux-gnu"
default_toolchain = "nightly-x86_64-unknown-linux-gnu"
profile = "default"
version = "12"

[overrides]
```

## Appendix C
```
~/.l/s/g/g/g/nu_scripts (bleeding): $env.PROMPT_COMMAND_RIGHT
<Closure 1945>
```

## Appendix D
```
~/.l/s/g/g/g/nu_scripts (bleeding): def create_left_prompt [] {
)))     let path_segment = if (is-admin) {
)))         $"(ansi red_bold)(spwd)"
)))     } else {
)))         $"(ansi green)(spwd)"
)))     }
)))
)))     let branch = (do -i { git branch --show-current } | str trim)
)))
)))     if ($branch == '') {
)))         $path_segment
)))     } else {
)))         $path_segment + $" (ansi reset)\((ansi yellow_bold)($branch)(ansi reset)\)"
)))     }
))) }
~/.l/s/g/g/g/nu_scripts (bleeding): create_left_prompt
~/.l/sh/gi/gi/go/nu_scripts (bleeding)
```

## Appendix E
```
> mkdir foo
> "this is foo" | save foo/foo.txt
> "this is bar" | save foo/bar.txt
> "this is baz" | save foo/baz.txt
```
```
> tar cvf foo.tar foo/*
foo/bar.txt
foo/baz.txt
foo/foo.txt
> tar tvf foo.tar
-rw-r--r-- a.stevan/disc    11 2023-01-31 15:39 foo/bar.txt
-rw-r--r-- a.stevan/disc    11 2023-01-31 15:39 foo/baz.txt
-rw-r--r-- a.stevan/disc    11 2023-01-31 15:39 foo/foo.txt
> gpg --output foo.tar.gpg.asc --armor --symmetric foo.tar
```
```
> rm foo/ foo.tar -rf
╭───┬─────────────────────────────────────╮
│ 0 │ deleted /home/disc/a.stevan/foo.tar │
│ 1 │ deleted /home/disc/a.stevan/foo     │
╰───┴─────────────────────────────────────╯
```
```
> gpg --decrypt foo.tar.gpg.asc | save foo.tar
gpg: AES256.CFB encrypted data
gpg: encrypted with 1 passphrase
> tar xvf foo.tar
foo/bar.txt
foo/baz.txt
foo/foo.txt
> ls foo/
╭───┬─────────────┬──────┬──────┬──────────────╮
│ # │    name     │ type │ size │   modified   │
├───┼─────────────┼──────┼──────┼──────────────┤
│ 0 │ foo/bar.txt │ file │ 11 B │ a minute ago │
│ 1 │ foo/baz.txt │ file │ 11 B │ a minute ago │
│ 2 │ foo/foo.txt │ file │ 11 B │ a minute ago │
╰───┴─────────────┴──────┴──────┴──────────────╯
```

## Appendix F
```
> ls | table --collapse
╭──────┬──────┬──────┬────────────────────────╮
│ name │ type │ size │        modified        │
 ──────┴─────┬┴─────┬┴──────────┬─────────────
│ Cargo.lock │ file │ 120.6 KiB │ 5 hours ago │
 ──────────── ────── ───────┬───┴─────────────
│ Cargo.toml │ file │ 139 B │   5 hours ago   │
 ───────────┬┴─────┬┴──────┬┴─────────────────
│ README.md │ file │ 957 B │    2 days ago    │
 ──────┬────┴┬─────┴───┬───┴──────────────────
│ core │ dir │ 4.0 KiB │     2 weeks ago      │
 ──────┴─────┴─┬──────┬┴────────┬─────────────
│ rustfmt.toml │ file │ 2.0 KiB │ 2 days ago  │
 ─────────┬────┴┬─────┴───┬─────┴─────────────
│ scripts │ dir │ 4.0 KiB │     a day ago     │
 ────────┬┴────┬┴────────┬┴───────────────────
│ target │ dir │ 4.0 KiB │    4 hours ago     │
╰────────┴─────┴─────────┴────────────────────╯
```

## Appendix G
```
def merge-test [mine] {
    let default = {
      foo: {value: 1, msg: "this is foo"}
      bar: {something: [3.14, 2.18], desc: "this is bar"}
    }

    $default | merge $mine | table -e
}
```
```
> merge-test {}
╭─────┬──────────────────────────────╮
│     │ ╭───────┬─────────────╮      │
│ foo │ │ value │ 1           │      │
│     │ │ msg   │ this is foo │      │
│     │ ╰───────┴─────────────╯      │
│     │ ╭───────────┬──────────────╮ │
│ bar │ │           │ ╭───┬──────╮ │ │
│     │ │ something │ │ 0 │ 3.14 │ │ │
│     │ │           │ │ 1 │ 2.18 │ │ │
│     │ │           │ ╰───┴──────╯ │ │
│     │ │ desc      │ this is bar  │ │
│     │ ╰───────────┴──────────────╯ │
╰─────┴──────────────────────────────╯
> merge-test {baz: "this is baz"}
╭─────┬──────────────────────────────╮
│     │ ╭───────┬─────────────╮      │
│ foo │ │ value │ 1           │      │
│     │ │ msg   │ this is foo │      │
│     │ ╰───────┴─────────────╯      │
│     │ ╭───────────┬──────────────╮ │
│ bar │ │           │ ╭───┬──────╮ │ │
│     │ │ something │ │ 0 │ 3.14 │ │ │
│     │ │           │ │ 1 │ 2.18 │ │ │
│     │ │           │ ╰───┴──────╯ │ │
│     │ │ desc      │ this is bar  │ │
│     │ ╰───────────┴──────────────╯ │
│ baz │ this is baz                  │
╰─────┴──────────────────────────────╯
> merge-test {foo: {value: -1}}
╭─────┬──────────────────────────────╮
│     │ ╭───────┬────╮               │
│ foo │ │ value │ -1 │               │
│     │ ╰───────┴────╯               │
│     │ ╭───────────┬──────────────╮ │
│ bar │ │           │ ╭───┬──────╮ │ │
│     │ │ something │ │ 0 │ 3.14 │ │ │
│     │ │           │ │ 1 │ 2.18 │ │ │
│     │ │           │ ╰───┴──────╯ │ │
│     │ │ desc      │ this is bar  │ │
│     │ ╰───────────┴──────────────╯ │
╰─────┴──────────────────────────────╯
> merge-test {bar: {other: "this is another thing"}}}
╭─────┬──────────────────────────────────────╮
│     │ ╭───────┬─────────────╮              │
│ foo │ │ value │ 1           │              │
│     │ │ msg   │ this is foo │              │
│     │ ╰───────┴─────────────╯              │
│     │ ╭───────┬──────────────────────────╮ │
│ bar │ │ other │ "this is another thing"} │ │
│     │ ╰───────┴──────────────────────────╯ │
╰─────┴──────────────────────────────────────╯
```

