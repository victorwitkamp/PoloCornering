# Carista Recovery Summary

Date: 2026-05-07

This file is the compact current status for the Carista reproduction work. It
replaces the older split status/gap/evidence notes and points to the detailed
catalogs and branch exports when more context is needed.

## Superseded Files

```text
docs/carista_apk_analysis/carista_reverse_engineering_status.md
docs/carista_apk_analysis/carista_replication_gap_analysis.md
docs/carista_apk_analysis/carista_relevant_evidence.md
```

## Scope

The goal is a close-as-possible reproduction of recovered Carista behavior for
VW Polo 6R / PQ25 BCM work. Recovered protocol/session/operation logic belongs
under `CaristaReproduction/`. Adapter entrypoints in `obd-on-pc/` must stay thin
and temporary.

## Current Anchors

Vehicle/controller:

```text
VW Polo 6R / PQ25 BCM J519
Part: 6R0937087K
TP2.0 unit: 20
Open request: 20C00010000301
Send/listen: 338 / 300
Carista exact params: A00194FF82FF
Polo fallback params: A00F8AFF32FF
```

TP2.0 behavior now modeled locally:

```text
A3 keep-alive
A8 disconnect
B(seq+1) ACK
9(seq) NACK/not-ready
outgoing payloads use a two-byte length prefix
positive response extraction uses the 12-bit length prefix
non-final request frames use ATST04
final/response frames use ATST20
```

Recovered command builders modeled locally:

```text
ReadDataByIdentifierCommand::getRequest       -> 22 + DID
WriteDataByIdentifierCommand::getRequest      -> 2E + DID + payload
GetVagCanEcuInfoCommand::getRequest           -> 1A9B
GetVagCanEcuListCommand::getRequest           -> 1A9F
ReadVagCanLongCodingCommand::getRequest       -> 1A9A
WriteVagCodingCommand::getRequest             -> structured 3B9A family, not full-coding blob
```

## Proven Write Shape

The active BCM long-coding write path is the UDS DID `0600` Carista-shaped
sequence:

```text
2EF199 + YYMMDD
22F1A5 inline workshop-code read
2EF198 + workshop-code payload
2E0600 + full 30-byte coding
fresh 220600 verification
```

`F199` and `F198` are Carista metadata pre-writes. Their negative response
`7F2E31` is nonfatal under Carista's `isFatalFail` gate. The final `2E0600`
write must still succeed and be verified by a fresh `220600` read.

## Current PQ25 Setting Facts

Official/recovered 6R/PQ25 long-coding branches now represented in
`CaristaReproduction`:

| Setting key | DID/location | Status |
|---|---|---|
| `car_setting_cornering_lights_via_fogs` | `0600` byte 12 mask `0x40` | set; behavior-disproven standalone |
| `car_setting_cornering_lights_via_fogs_experimental` | `0600` byte 21 mask `0x80` | set; not sufficient standalone |
| `car_setting_cornering_lights_with_turn_signals` | `0600` byte 21 mask `0x04` | set; behavior-disproven standalone |
| `car_setting_turn_off_fogs_with_high_beam` | `0600` byte 21 mask `0x20` | set; matches high-beam fog cutoff |
| `car_setting_drl_via_fogs` | `0600` byte 23 mask `0x04` | tested; behavior-disproven for this symptom |

Current live reads:

```text
220600 -> 6206003AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
220601 -> 6206011E
220606 -> 620606001800018000
22F1A5 -> 62F1A50005F3C7E719
```

The 2026-05-07 in-car DRL-via-fogs test wrote byte 23 bit 2 and verified the
coding change, but it did not fix the visible behavior. The next live target is
restoring the expert backup:

```text
3AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000
```

## Ruled-Out Or Background Paths

Do not treat these as current write targets:

```text
blind 3B9A + full 30-byte coding
default 1089 session before DID 0600 write
byte 12 bit 6 alone
byte 21 bit 2 alone
byte 12 bit 6 + byte 21 bit 2 as the whole fix
DRL-via-fogs byte 23 bit 2 as the missing visible fix
055C / 055D direct UDS adaptation writes
front_fogs_with_low_beams direct label path from FordSettings
fog_when / left_fog_light_as / right_fog_light_as direct labels from FordSettings
```

Direct reads already rejected on this BCM/session:

```text
22055C, 22055D, 22110E, 22056D, 220550, 220551, 220D01, 220A58, 220A57
```

The `220601 -> 1E` value remains a strong stored-role clue. Play 9.8.3 x86 also
contains a readable `ECU VAGCAN20 220601: 6206011E` simulator/sample-response
row, but no recovered 6R/PQ25 Carista write path ties DID `0601` to a writable
Setting object. It is not a write seed.

## Detailed Evidence To Keep

Current generated/catalog outputs:

```text
docs/carista_apk_analysis/pq25_carista_setting_catalog.md
carista_apk_analysis/pq25_carista_setting_catalog.json
carista_apk_analysis/pq25_carista_settings_catalog.csv
carista_apk_analysis/pq25_carista_longcoding_bits.csv
```

Durable Play 9.8.3 x86 branch evidence:

```text
carista_apk_analysis/play_9.8.3/ghidra_x86_vag_lighting/x86_vag_lighting_branch_summary.md
carista_apk_analysis/play_9.8.3/ghidra_x86_vag_lighting/branches/
```

Validation command:

```powershell
python carista_apk_analysis/validate_carista_reproduction.py
```

Useful CLI views:

```powershell
python -m CaristaReproduction --read-values-plan
python -m CaristaReproduction --current-settings --coding <30-byte-coding>
python -m CaristaReproduction --uds-write-plan --coding <current-coding> --target-coding 3AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000 --workshop-code 0005F3C7E719
```

## Open Work

1. Restore the expert backup coding through the temporary thin runner in
   `obd-on-pc/`.
2. Remove the temporary live runner after the restore unless an immediate retry
   is needed.
3. Focus the remaining investigation on unresolved role ownership, not another
   direct `0600` cornering bit.

## Unresolved Issues To Focus

1. Paired front-fog request / switch input: determine whether the BCM is seeing
   the front-fog request active in the plain low-beam/headlight switch position.
   If yes, inspect the switch/request path around `T73a/7` before searching for
   another coding bit.
2. Output wiring / per-side ownership: verify whether the one-bulb H8 fogs are
   wired to separate BCM-controlled paths (`T73b/9`, `T73b/10`, supply
   `T73b/11`) or an ordinary/bridged front-fog path. Software cannot create
   visible per-side cornering without left/right output ownership.
3. `220601 -> 6206011E`: keep as the strongest software clue because `1E`
   overlaps the recovered per-side role enum, but do not write `0601` until a
   Carista runtime Setting/current-value path is recovered.
4. Missing VAG/PQ25 role path: the direct visible labels
   `front_fogs_with_low_beams`, `fog_when`, `left_fog_light_as`, and
   `right_fog_light_as` are non-VAG/Ford paths in recovered code. Look for an
   alternate VAG key, availability sub-object, or `ReadValuesOperation` value
   path instead.
5. Blocked write seeds: do not build writes from `055C`, `055D`, `056C`,
   `0D04`, `0D1D`, or static enum values until current payload length, selected
   branch, and requested-choice bytes are proven for `6R0937087K`.
