# TOC
- [:1st_place_medal: Important items](#1st_place_medal-important-items-toc)
- [:2nd_place_medal: Secondary items](#2nd_place_medal-secondary-items-toc)
- [:heavy_check_mark: Done items](#heavy_check_mark-done-items-toc)
- the [appendix](appendix.md)

## :1st_place_medal: Important items [[TOC](#toc)]
- [ ] (11/18) nushell
  - [ ] nufmt
  - [ ] overwrite part of `config.hooks` for instance (see [appendix G](appendix.md#appendix-G))
  - [ ] (1/5) plugins
    - [ ] KDL (`... | from kdl`) https://discord.com/channels/601130461678272522/601130461678272524/1062487391312543784
    - [ ] RON (`... | from ron`) ?
    - [ ] hash functions
    - [ ] encoding methods
    - [x] example `nu_plugin_len` to compute length of strings with `"..." | my_str_len`
  - [ ] (0/1) completions
    - [ ] `rustup`
  - [ ] `asciinema edit` to edit `asciicast`s
  - [ ] `youtube list` to get lists of playlists and videos in playlists, possibly the feed itself and edit playlists?
  - [x] allow `Examples` in plugins: related to https://github.com/nushell/nushell/issues/7827 (see [this comment of @fdncred](https://github.com/phenax/bsp-layout/issues/10#issuecomment-1407394499))
  - [x] extract data from https://raw.githubusercontent.com/openssl/openssl/81fc390fd96ad9fae21cda919513fb696cd24028/crypto/ec/ec_curve.c
  - [x] see closure's content (see [appendix C](appendix.md#appendix-C))
  - [x] allow `table -e` to be used in pipes
  - [x] odd prompt (see [appendix D](appendix.md#appendix-D)) => artifact of ubuntu
  - [x] transport gpg keys in an archive (see [appendix E](appendix.md#appendix-E))
  - [x] give different colors to "deprecated" sub commands in `help <command>` => deprecated commands go away with releases
  - [x] `nu --default-config --no-banner` feature request
  - [x] colored output in `nushell`
  - [x] more hash functions to `hash` ?
  - [x] (2/2) issues
    - [x] decode / encode (see [appendix A](appendix.md#appendix-A))
    - [x] add `vim` bindings to `explore` and make that configurable
  - [x] (2/2) modules
      - [x] ghq
      - [x] `gpg {export,import}`

- [ ] (0/2) vim
  - [ ] margin when scrolling
  - [ ] center the line when scrolling

- [ ] (0/2) websites
    - [ ] personal
    - [ ] notes

- [ ] (1/5) `rust`
    - [x] book
    - [ ] gitox
    - [ ] left-wm
    - [ ] (0/3) traductions
        - [ ] bspwm
        - [ ] dmenu
        - [ ] sxhkd
    - [ ] RON

- [ ] (1/2) `git` + `fzf`
    - [x] try minimal things [`git-fzf`]
    - [ ] implement `magit` but outside emacs

- [ ] pre-commit hooks to run formatting or generate files

- [~] test savannah

## :2nd_place_medal: Secondary items [[TOC](#toc)]
- [ ] [New window never go on master](https://github.com/phenax/bsp-layout/issues/10#issuecomment-1407394499)

- [ ] fix `rofi` applications

- [ ] (2/4) mail manager
    - [x] setup `mu`
    - [x] add credentials to `pass`
    - [ ] find a terminal-based mail client
    - [ ] implement `mu4e` but outside emacs

- [ ] (1/2) *suckless*
    - [x] fix `dmenu` with [`bakkeby/dmenu-flexipatch`]
    - [ ] contribute to [`bakkeby/dmenu-flexipatch`]

- [ ] (0/2) Pac-Man
    - [~] read full [Pac-Man dossier]
    - [ ] implement it in `rust`

- [ ] (2/4) [`obncc`]
    - [x] [website](https://github.com/amtoine/obncc/tree/gh-pages)
    - [x] make the website pretty
    - [ ] [`racket` *ADN*]
    - [~] play with the syntax as structured data

- [ ] (0/5) sound
    - [ ] `pipewire`
    - [ ] `pulsemixer`
    - [ ] `amixer`
    - [ ] [`amtoine-sound`]
    - [ ] fix `moc`

- [ ] (1/2) bootloader
    - [x] which one? -> *`systemd` boot manager*
    - [ ] configure it? wallpaper?

- [ ] helix (pacman+oberon, cargo+other)

## :heavy_check_mark: Done items [[TOC](#toc)]
- [x] (4/4) dragoon
  - [x] test equipment and ask for "teletravail"
  - [x] thesis subjects
  - [x] fiche de paie aux impots
  - [x] calculs salaire

- [x] (2/2) archinstall
    - [x] config files
    - [x] track the dependencies with [`amtoine-upl`]

- [x] (2/2) `passmenu`
    - [x] `nushell` script to emulate `passmenu`: [`pass-menu`]
    - [x] repair `dmenu`

- [x] goatfiles
    - [x] lunarvim

- [x] check [`charmbracelet/vhs`]
- [x] check the chatbox of CIC

- [x] install `rust` via `rustup` (see [appendix B](appendix.md#appendix-B))

[`amtoine-sound`]: https://github.com/amtoine/scripts/blob/main/scripts/amtoine-sound
[`amtoine-upl`]: https://github.com/amtoine/scripts/blob/main/scripts/amtoine-upl
[`pass-menu`]: https://github.com/amtoine/dotfiles/blob/main/.config/nushell/scripts/functions.nu#L188
[`bakkeby/dmenu-flexipatch`]: https://github.com/bakkeby/dmenu-flexipatch
[`obncc`]: https://github.com/amtoine/obncc
[`racket` *ADN*]: https://adn.isae-supaero.fr/enrol/index.php?id=790
[`git-fzf`]: https://github.com/amtoine/dotfiles/blob/git-fzf/.config/nushell/scripts/gf.nu
[Pac-Man dossier]: https://www.gamedeveloper.com/design/the-pac-man-dossier
[`charmbracelet/vhs`]: https://github.com/charmbracelet/vhs
