# PQ25 BCM Long-Coding Reference

Date: 2026-04-28

Controller:

```text
Part #: 6R0937087K
Component: BCM PQ25 H+4
Software version: 0254
```

## Coding Values

Current verified baseline:

```text
3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000
```

Supplied/reference coding:

```text
3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

The supplied/reference coding was useful for narrowing the search, but it is not
behavior-proven as the correct fix for the current car state.

## Differing Bits

| Byte | Bit | Baseline | Reference | Carista mapping | Live result |
|---:|---:|---|---|---|---|
| 12 | 6 | clear | set | fog-cornering / use-cornering family | written and verified; behavior unchanged |
| 21 | 2 | clear | set | turn-signal cornering trigger family | written and verified; behavior unchanged |

These bits are real mappings, but they are no longer active guesses for the
visible symptom.

## Context Bits

| Byte | Bit | Baseline | Reference | Meaning confidence |
|---:|---:|---|---|---|
| 13 | 6 | set | set | medium CH/LH/fog-vs-low-beam context |
| 21 | 5 | set | set | medium fog/high-beam context |
| 21 | 7 | set | set | medium fog/turn-light install context |
| 22 | 5 | clear | clear | medium ADL context |
| 00 | 0 | clear | clear | low cross-platform fog install reference only |
| 18 | 2 | clear | clear | low front fog cold diagnosis reference only |
| 18 | 3 | clear | clear | low rear fog cold diagnosis reference only |

Context bits are not write targets. They either already match the reference or
come from weaker cross-platform labels.

## Active Interpretation

The latest Carista/PQ25 catalog is the active map:

```text
docs/carista_apk_analysis/pq25_carista_setting_catalog.md
```

It marks byte `12` bit `6` and byte `21` bit `2` as mapped but live
behavior-ruled-out for the current symptom. The highest unresolved settings are:

```text
car_setting_left_fog_light_as
car_setting_right_fog_light_as
```

Until those are mapped to a proven method, this long-coding reference should be
used for decoding and recovery only, not for random bit flips.