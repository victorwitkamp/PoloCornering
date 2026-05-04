# VW Polo 6R Vehicle Information for Coding Review

Generated: 2026-05-01

Restored live coding: 2026-05-01 17:58, verified by `220600` readback.

Post-restart live read: 2026-05-02 19:00-19:01, verified by repeated `220600` readback.

## Vehicle Identity

| Field | Value |
|---|---|
| VIN | `WVWZZZ6RZCY230414` |
| Manufacturer/WMI | `WVW` - Volkswagen passenger car |
| Chassis / platform code from VIN | `6R` |
| Model family | Polo 6R / PQ25 |
| Model year code | `C` - 2012 model year code |
| Plant code | `Y` |
| Serial number | `230414` |

## Current BCM / Central Electronics

| Field | Value |
|---|---|
| Module | `09` - Central electronics / BCM / J519 |
| Part number | `6R0937087K` |
| Component | `BCM PQ25 H+4` |
| Software version | `0254` |
| ASAM/ODX identifier | none reported |
| Coding length | 30 bytes |
| Current coding | `3AB02BBF08A10000003008006D6B0CD000C0412F60860000200000000000` |
| Immediate post-restore coding | `3AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000` |
| Previous pre-restore coding | `3AB82B9F08A10000003008006C680ED000C8410F60860000200000000000` |

## Historical Backup Coding

Source: Backup supplied by the previous coder who coded the car a long time ago.

Status: Restored live and verified by `220600` readback on 2026-05-01.

Post-restart note: Repeated `220600` reads on 2026-05-02 returned byte 13 as `6B`, not the immediate post-restore `2B`.

| Field | Value |
|---|---|
| Backup coding | `3AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000` |
| Coding length | 30 bytes |

## Immediate Post-Restore Coding vs Post-Restart Live Read

Byte numbering is zero-based for the 30-byte coding. The analyzer reports this as response byte 16 because `220600` payloads include the three-byte `62 06 00` prefix.

| Byte | Immediate post-restore | Post-restart live | Changed bits |
|---:|---|---|---|
| 13 | `2B` | `6B` | 6 |

Repeated evidence:

| Capture | `220600` coding |
|---|---|
| 2026-05-02 confirmed fault state | `3AB02BBF08A10000003008006D6B0CD000C0412F60860000200000000000` |
| 2026-05-02 repeated same fault state | `3AB02BBF08A10000003008006D6B0CD000C0412F60860000200000000000` |
| 2026-05-02 parking lights/no fog state | `3AB02BBF08A10000003008006D6B0CD000C0412F60860000200000000000` |

Raw `ATMA` monitor windows retained 0 frames with this ELM327 clone, so passive CAN monitor evidence was not captured.

## Read-Only Status/Fault Evidence

Captured in the confirmed visible fault state on 2026-05-02.

| Command | Response | Note |
|---|---|---|
| `1802FF00` | `58010C9820` | Same stable payload seen in earlier 2026-04-29 diagnostic collection; not a new fog-specific clue by itself. |
| `1902FF` | `7F1911` | Negative response / unsupported service variant on this path. |

## Pre-Restore Coding vs Restored Historical Backup

Byte numbering is zero-based, VCDS/LCode-style.

| Byte | Pre-restore | Restored | Changed bits |
|---:|---|---|---|
| 01 | `B8` | `B0` | 3 |
| 03 | `9F` | `BF` | 5 |
| 12 | `6C` | `6D` | 0 |
| 13 | `68` | `2B` | 0, 1, 6 |
| 14 | `0E` | `0C` | 1 |
| 17 | `C8` | `C0` | 3 |
| 19 | `0F` | `2F` | 5 |

## Known/Interpreted Label Differences vs Restored Historical Backup

These are only the changed bits for which a current working label is available.

| Byte | Bit | Pre-restore | Restored | Label / interpretation |
|---:|---:|---|---|---|
| 13 | 0 | Clear / inactive | Set / active | Parking lights ON only without ignition ON possible |
| 13 | 1 | Clear / inactive | Set / active | Parking lights function active |
| 13 | 6 | Set / active | Clear / inactive | Coming-home/leaving-home variant |
| 19 | 5 | Clear / inactive | Set / active | Lamp diagnostics for fog/cornering/turn lights active |

## ECU Inventory

Source: ECU information report from Carista 9.6.3 for Android. The central-electronics coding in the table is the current known BCM coding value.

| System | Part number | Component | Software | ASAM/ODX identifier | Coding | Fault codes |
|---|---|---|---|---|---|---|
| CAN network gateway | `6N0909901` | `GW-K-CAN TP20` | `0254` | none | `002200` | none reported |
| Engine | `03F906070GD` | `SIMOS10.22A` | `5466` | `EV_ECM12TFS02103F906070GD` | `001100D6202400080000` | none reported |
| Airbags | `6R0959655K` | `VW10Airbag022` | `0020` | `EV_AirbaVW10BPAVW250` | `003232` | none reported |
| Instrument cluster | `6R0920860H` | `KOMBI` | `0505` | `EV_Kombi_UDS_VDD_RM09` | `140801` | none reported |
| Immobilizer | `5K0953234` | `IMMO` | `0505` | `EV_Immo_UDS_VDD_RM09` | `000000` | none reported |
| Heater & air conditioning | `6R0820045N` | `Man AC` | `0202` | none | none | none reported |
| Central electronics | `6R0937087K` | `BCM PQ25 H+4` | `0254` | none | `3AB02BBF08A10000003008006D6B0CD000C0412F60860000200000000000` | none reported |

## Current BCM Coding by Byte

Byte numbering is zero-based, VCDS/LCode-style.

| Byte | Hex | Binary | Set bits |
|---:|---|---|---|
| 00 | `3A` | `00111010` | 1, 3, 4, 5 |
| 01 | `B0` | `10110000` | 4, 5, 7 |
| 02 | `2B` | `00101011` | 0, 1, 3, 5 |
| 03 | `BF` | `10111111` | 0, 1, 2, 3, 4, 5, 7 |
| 04 | `08` | `00001000` | 3 |
| 05 | `A1` | `10100001` | 0, 5, 7 |
| 06 | `00` | `00000000` | none |
| 07 | `00` | `00000000` | none |
| 08 | `00` | `00000000` | none |
| 09 | `30` | `00110000` | 4, 5 |
| 10 | `08` | `00001000` | 3 |
| 11 | `00` | `00000000` | none |
| 12 | `6D` | `01101101` | 0, 2, 3, 5, 6 |
| 13 | `6B` | `01101011` | 0, 1, 3, 5, 6 |
| 14 | `0C` | `00001100` | 2, 3 |
| 15 | `D0` | `11010000` | 4, 6, 7 |
| 16 | `00` | `00000000` | none |
| 17 | `C0` | `11000000` | 6, 7 |
| 18 | `41` | `01000001` | 0, 6 |
| 19 | `2F` | `00101111` | 0, 1, 2, 3, 5 |
| 20 | `60` | `01100000` | 5, 6 |
| 21 | `86` | `10000110` | 1, 2, 7 |
| 22 | `00` | `00000000` | none |
| 23 | `00` | `00000000` | none |
| 24 | `20` | `00100000` | 5 |
| 25 | `00` | `00000000` | none |
| 26 | `00` | `00000000` | none |
| 27 | `00` | `00000000` | none |
| 28 | `00` | `00000000` | none |
| 29 | `00` | `00000000` | none |

## Current Interpreted BCM Settings

These labels are best-effort PQ25/Carista-style interpretations. The raw coding string and byte table above are the authoritative data.

| Byte | Bit | Current state | Current byte | Label / interpretation |
|---:|---:|---|---|---|
| 12 | 6 | Set / active | `6D` | Turn/Cornering lights installed/active |
| 13 | 0 | Set / active | `6B` | Parking lights ON only without ignition ON possible |
| 13 | 1 | Set / active | `6B` | Parking lights function active |
| 13 | 3 | Set / active | `6B` | Brake light activation via BCM |
| 13 | 5 | Set / active | `6B` | Interior light enabling via rear lid |
| 13 | 6 | Set / active | `6B` | Coming-home/leaving-home variant |
| 16 | 5 | Clear / inactive | `00` | Rear fog lamp diagnostics active |
| 19 | 5 | Set / active | `2F` | Lamp diagnostics for fog/cornering/turn lights active |
| 21 | 2 | Set / active | `86` | Cornering/turn lights via turn signal active |
| 21 | 5 | Clear / inactive | `86` | Fog lights inactive with high beams active |
| 21 | 7 | Set / active | `86` | Front fog lights with turn/cornering lights installed |
| 22 | 5 | Clear / inactive | `00` | Assistant Driving Light candidate |