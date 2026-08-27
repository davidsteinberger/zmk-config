---
name: draw
description: Regenerate the keymap visualization (draw/base.svg) from config/base.keymap using keymap-drawer. Use after editing the base keymap's layers or combos, or when the user asks to "draw", "visualize", or "render" the keymap.
---

Run:

```
just draw
```

This parses `config/base.keymap` (including the `Combos` virtual layer) into `draw/config.yaml` via `keymap -c draw/config.yaml parse -z config/base.keymap --virtual-layers Combos`, writing `draw/base.yaml`, then renders `draw/base.svg` targeting the `ferris/sweep` physical layout.

`draw/base.yaml` is gitignored — only `draw/base.svg` and `draw/config.yaml` are meant to be committed. Requires the Nix dev shell active (provides `keymap-drawer`).

Only run this after changes to `config/base.keymap` specifically — per-board keymap files (`config/go60.keymap`, `config/cradio.keymap`, etc.) aren't covered by this visualization.

## Known issue, verified currently broken

Running `just draw` right now fails at the `yq` step with `jq: error (at <stdin>:1): Cannot iterate over null (null)` (exit 5). Root cause, confirmed by tracing it: `config/base.keymap` has `#include "combos.dtsi"` (around line 72), but no file named `combos.dtsi` exists anywhere in this repo or its vendored trees. `keymap parse` silently ignores the missing include rather than erroring, so the generated `draw/base.yaml` has no `combos:` key at all — then `yq -Yi '.combos.[].l = ["Combos"]' draw/base.yaml` tries to iterate that null key and fails.

This means the combos virtual layer is currently not renderable via `just draw` on this branch until `combos.dtsi` is restored (or the `#include` is removed/repointed) — this looks like it was dropped during the recent "refactor" restructuring (see `git log -- config/base.keymap`). It does **not** block firmware builds for `go60`/`cradio`/`glove80` since those keymaps don't include `base.keymap`. Flag this to the user rather than silently patching it — it's their call whether to restore the file or repoint the include.
