---
name: build
description: Build one or more ZMK firmware targets from build.yaml using `just build`, to verify a keymap/config change compiles. Use after editing files under config/ (keymaps, .conf, .dtsi overlays) when the user wants to confirm the change builds, or when asked to "build", "flash", or "compile" a board/shield.
---

Build targets are defined in `build.yaml` at the repo root (board/shield/snippet/artifact combos). Run `just list` to see the exact current set — it changes as boards are added/removed, don't assume a name from memory.

Run from the repo root:

```
just build <expr> [west_args]
```

`<expr>` matches against board, shield, or artifact names **currently in `build.yaml`** — check with `just list` first. As of this writing that's `cradio_left`/`cradio_right` (board `nice_nano_v2`), `glove80_lh`/`glove80_rh`, `go60_lh`/`go60_rh`; expr `go60`, `glove80`, or `cradio` matches both sides of that board. Board names like `corneish_zen`/`planck_rev6` have keymaps under `config/` but are **not** currently wired into `build.yaml`, so `just build corneish_zen` fails with `No matching targets found` — that's not a build error, it means the target needs to be added to `build.yaml`'s `include` list first.

A zero exit code plus the produced `firmware/<artifact>.uf2`/`.bin` is sufficient verification — `just build` already fails loudly (non-zero exit) on a broken keymap/config, so no further output inspection is needed. No need to flash a device to confirm correctness.

Requires the Nix dev shell (`nix develop`) or direnv to be active — if `west`/`just` aren't found, run commands inside `nix develop --command <cmd>`. In an active shell (`west`/`just`/`yq`/`keymap` resolving directly), ARM firmware builds (`just build <target>`) work as-is — no extra environment fixes needed (unlike `just test`).

If the build fails due to a missing/stale dependency tree, `just update` (re-runs `west update`) is the usual fix before re-trying — do not delete `.west`/`zmk` (`just clean-all`) unless asked, since that forces a full re-fetch.
