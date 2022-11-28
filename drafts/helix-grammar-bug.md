## `arch` package
```bash
> helix --version
helix 22.08.1
> pacman -Q | grep helix
helix 22.08.1-1
```
installed with `pacman -S helix`

i get language support out of the box except for the `oberon` language i've configured in `~/.config/helix/languages.toml` and `~/.config/helix/runtime/queries/oberon/`
i see that information in `helix --health` and by trying some files

and i have permission issues with
```bash
> helix --grammar fetch
Fetching 107 grammars
107 grammars failed to fetch
    Failure xxx/107: Could not create grammar directory "/var/lib/helix/runtime/grammars/sources/xxx"
```
and of course 
```bash
> helix --grammar build
Building 107 grammars
107 grammars failed to build
    Failure xxx/107: Failed to read directory "/var/lib/helix/runtime/grammars/sources/xxx". Did you use 'hx --grammar fetch'?
```
because `helix --grammar fetch` failed

## *build from source*
```bash
> hx --version
helix 22.08.1 (fc811726)
> cargo install --list | grep "^helix" -A1
helix-term v0.6.0 (/home/amtoine/.local/share/ghq/github.com/helix-editor/helix/helix-term):
    hx
```
installed with
```bash
git clone https://github.com/helix-editor/helix
cargo install --path helix-term
```

according to `hx --health` i get no language support for all the languages except `oberon` which works in  this setup :open_mouth: 

and regarding the grammar, it appears to work
```bash
> hx --grammar fetch
Fetching 123 grammars
123 up to date git grammars
> hx --grammar build
Building 123 grammars
123 grammars already built
```
but still only `oberon` supported :thinking: 

and i've tried the "*build from source*" method with revisions
- fc811726: the current `master`
- 66276ce6: the tag `22.08.1`
- ac1b7d8d: the tag `v0.6.0`

and it did not change the behaviour above!

## conclusion
i'm quite confused about what is happening :confused: 
do you guys have any idea about what i have on my system and how i could fix this and have language support for all the languages, buil-in ones and `oberon`? :yum:

## some other things
```bash
> sudo cp -r /var/lib/helix/runtime/queries/pascal/ /var/lib/helix/runtime/queries/oberon
> sudo helix --grammar fetch
> sudo helix --grammar build
```
