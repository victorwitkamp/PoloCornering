# PQ25 BCM Current Settings And Carista Mapping Report

Date: 2026-05-06

## Controller

```text
Vehicle focus: VW Polo 6R / PQ25
Module: 09 Central Electronics / BCM / J519
Part: 6R0937087K
TP2.0 unit: 20
```

## Current Coding State

Fresh engine-running read-only snapshot:

```text
220600 -> 6206003AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
coding  ->   3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
220601 -> 6206011E
220606 -> 620606001800018000
22F1A5 -> 62F1A50005F3C7E719
```

Generated JSON companion:

```text
docs/obd-on-pc/pq25_current_settings_carista_report.json
```

The generated report now prefers recovered official x86 PQ25/6R DID 0600
byte/mask branches over older catalog-only bit hints when rendering current
values. It also leaves branch-specific selector rows as `unknown` when recovered
Carista evidence shows conflicting encodings rather than one selected PQ25
branch.

The current coding is the previously write-proven target. It persisted with the
engine running, but it is behavior-disproven as a standalone fix: the front fogs
still behave as steady low-beam-linked outputs with high-beam inhibit, not as
turn-signal-triggered cornering lights.

## Mapped And Tested Settings

| Carista setting family | Location | Current | Live result |
|---|---:|---|---|
| `car_setting_cornering_lights_via_fogs`, `car_setting_use_cornering_lights` | byte 12 bit 6 | set | live-written and behavior-disproven as a standalone fix |
| `car_setting_cornerig_lights_with_turn_signal`, `car_setting_cornering_lights_with_turn_signals` | byte 21 bit 2 | set | live-written and behavior-disproven as a standalone fix |

These mappings are still useful, but they are resolved for the current symptom:
they should not drive another blind write.

## Context-Only Candidates

| Recovered branch | Location | Current byte/state | Status |
|---:|---|---|---|
| `car_setting_cornering_lights_via_fogs_experimental` | byte 21 mask 0x80 | byte 21 = A6, set | already enabled; behavior-disproven as a standalone fix |
| `car_setting_turn_off_fogs_with_high_beam` | byte 21 mask 0x20 | byte 21 = A6, set | matches observed high-beam fog cutoff; not a missing cornering trigger |
| `car_setting_drl_via_fogs` | byte 23 mask 0x04 | byte 23 = 00, clear | DRL/fog clue only, not the observed turn-signal cornering symptom |
| `car_setting_assist_dr_lights` | byte 22 mask 0x20 | byte 22 = 00, clear | lower-priority ADL clue |
| `car_setting_coming_leaving_home_output` | branch-specific `110E`, byte 13 mask 0x40, or byte 17 mask 0x08 | unknown | output selector evidence only; runtime branch and enum are unresolved |

Do not flip context bits without Carista proof that a specific setting uses that
bit on this exact BCM.

## Current Unresolved Carista Settings

Carista's own instruction names three related settings. The first family is now
already enabled and behavior-disproven as a standalone fix. The unresolved
visible-label pieces are:

```text
car_setting_left_fog_light_as
car_setting_right_fog_light_as
```

2026-05-06 x86 follow-up shows those exact direct labels resolve in
`FordSettings::getSettings`, not `VagCanSettings::getSettings`. A VW/PQ25
equivalent still needs a recovered runtime Setting object, alternate VAG key,
or ReadValuesOperation value path before any live write.

The VAG per-side candidates `car_setting_cornering_lights_via_fogs_left/right`
still recover `055C` / `055D` offset `5` mask `FF`, but their selected branches
are MQB/MK8 or gateway/MEB. The older ARM region includes `5Q0937084*` and
`6C093708*` part patterns, not `6R0937087K`, and both direct reads already
returned `7F2231`.

The strongest next repair clue is the positive companion read `220601 ->
6206011E`. The trailing `1E` matches Carista's recovered
`car_setting_enabled_coming_home_or_leaving_home` choice in the per-side
fog-role tables, while switch-state reads show it is stable configuration/status
rather than a live switch state. This is not a write seed yet: no recovered
6R/PQ25 setting branch ties DID `0601` to a writable Carista object, and the
nearby `055C` / `055D` branches still reject direct reads.

## Current Catalog

Use the generated PQ25 catalog as the active map:

```text
docs/carista_apk_analysis/pq25_carista_setting_catalog.md
carista_apk_analysis/pq25_carista_settings_catalog.csv
carista_apk_analysis/pq25_carista_longcoding_bits.csv
carista_apk_analysis/pq25_carista_setting_catalog.json
```

Older static maps are retained only as background evidence.
