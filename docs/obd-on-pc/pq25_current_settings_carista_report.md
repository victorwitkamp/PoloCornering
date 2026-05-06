# PQ25 BCM Current Settings And Carista Mapping Report

Date: 2026-04-28

## Controller

```text
Vehicle focus: VW Polo 6R / PQ25
Module: 09 Central Electronics / BCM / J519
Part: 6R0937087K
TP2.0 unit: 20
```

## Current Coding State

Current verified baseline:

```text
3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000
```

Supplied/reference coding:

```text
3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

The supplied/reference coding is not behavior-proven as a fix. It differs only
at byte `12` bit `6` and byte `21` bit `2`.

## Mapped And Tested Settings

| Carista setting family | Location | Current | Reference | Live result |
|---|---:|---|---|---|
| `car_setting_cornering_lights_via_fogs`, `car_setting_use_cornering_lights` | byte 12 bit 6 | clear | set | live-written both ways; visible behavior unchanged |
| `car_setting_cornerig_lights_with_turn_signal`, `car_setting_cornering_lights_with_turn_signals` | byte 21 bit 2 | clear | set | live-written both ways; visible behavior unchanged |

These mappings are still useful, but they are resolved for the current symptom:
they should not drive another blind write.

## Context-Only Candidates

| Location | Current | Reference | Status |
|---:|---|---|---|
| byte 13 bit 6 | set | set | CH/LH/fog-vs-low-beam context only; not a current diff |
| byte 21 bit 5 | set | set | fog/high-beam context only; not a current diff |
| byte 21 bit 7 | set | set | fog/turn-light install context only; not a current diff |
| byte 22 bit 5 | clear | clear | ADL context only; not a current diff |

Do not flip context bits without Carista proof that a specific setting uses that
bit on this exact BCM.

## Current Unresolved Carista Settings

Carista's own instruction names three related settings. The first family is the
already-tested long-coding trigger/fog-cornering mapping. The unresolved pieces
are:

```text
car_setting_left_fog_light_as
car_setting_right_fog_light_as
```

2026-05-06 x86 follow-up shows those exact direct labels resolve in
`FordSettings::getSettings`, not `VagCanSettings::getSettings`. A VW/PQ25
equivalent still needs a recovered runtime Setting object, alternate VAG key,
or ReadValuesOperation value path before any live write.

## Current Catalog

Use the generated PQ25 catalog as the active map:

```text
docs/carista_apk_analysis/pq25_carista_setting_catalog.md
carista_apk_analysis/pq25_carista_settings_catalog.csv
carista_apk_analysis/pq25_carista_longcoding_bits.csv
carista_apk_analysis/pq25_carista_setting_catalog.json
```

Older static maps are retained only as background evidence.
