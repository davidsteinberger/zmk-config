# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with
code in this repository.

## What this is

David's personal [ZMK](https://zmk.dev/) keyboard firmware config (a fork of
urob's zmk-config). A shared 34-key-core base layout (`config/custom.keymap`) is
reused across the physical boards actually built: Cradio, Glove80, and `go60`
(his own custom board with a Cirque trackpad) — see `build.yaml` for the full
list. Most day-to-day work is editing keymaps/behaviors under `config/`, not
touching firmware internals.

Notable layout features of `custom.keymap` (see `readme.md` for details):
timerless homerow mods, combos instead of a symbol layer.

## Vendored / fetched directories — do not edit as project code

`zmk/`, `zephyr/`, `modules/`, `.west/`, `cirque-input-module/`, `bootloader/`,
`tools/` are all gitignored and fetched by `west update` per the manifest at
`config/west.yml` — they are not tracked in this repo's history. Treat them as
read-only upstream/vendored source, not as project files to modify. If a change
seems to require editing something under these paths, it almost always means the
fix belongs in `config/` instead (e.g. an overlay `.dtsi`/`.conf`/module
reference), or the manifest revision needs bumping.

`config/miryoku/` is git-tracked but is reference material (mappings for ~70
community keyboard layouts) — treat it as read-only unless told otherwise.

## Build system

Builds go through `just` (a Justfile), which wraps `west`/Zephyr and is itself
the source of truth — read the Justfile for exact flags. Key commands:

- `just build <expr> [west_args]` — builds targets from `build.yaml` matching
  `<expr>` (matches board/shield/artifact name), output copied to
  `firmware/<artifact>.uf2`.
- `just list` — lists all available build targets.
- `just init` — first-time setup:
  `west init -l config; west update --fetch-opt=--filter=blob:none; west zephyr-export`.
- `just update` — re-run `west update` after changing `config/west.yml`.
- `just draw` — regenerates the keymap visualization (`draw/base.svg`) from
  `config/base.keymap` via `keymap-drawer`.
- `just test <testpath> [--no-build] [--verbose] [--auto-accept]` — builds a
  native_posix_64 test binary and diffs its output against a
  `keycode_events.snapshot`.
- `just clean` / `just clean-all` — remove `.build`/`firmware`, or also
  `.west`/`zmk` (forces a full re-fetch on next build).

The dev shell is Nix-managed (`flake.nix`, direnv via `.envrc`) — commands
generally assume `nix develop` (or direnv) is active, and pin the Zephyr
SDK/toolchain version.

## Repo conventions

- `.prettierrc` sets `proseWrap: always` — applies to Markdown/YAML, not to
  `.keymap`/`.dtsi` devicetree files (no formatter configured for those).
- `build.yaml` is the single source of truth for which board/shield/snippet
  combos build in CI and locally via `just build`/`just list`.
- CI (`.github/workflows/`) builds on push to `config/**`/`build.yaml` via a
  reusable upstream workflow; `test-build-env.yml` exercises `just init` /
  `just build planck` / `just draw` across Linux/macOS runners as an environment
  sanity check.
