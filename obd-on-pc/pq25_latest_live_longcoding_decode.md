# PQ25 BCM Latest Live Long-Coding Decode

Date: 2026-04-26

Source capture:

```text
log:        obd-on-pc/logs/pq25_post_session_write_verify_direct_read_summary.json
read_result 6206003AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000
coding:     3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000
```

Known-good working reference:

```text
3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

Interpretation summary:

- The live BCM coding still differs from the known-good working coding only at byte 12 and byte 21.
- The two highest-confidence cornering-light bits are both clear in the live car.
- That keeps the BCM in the non-working cornering-light state even though the rest of the known focus bytes already match.

## Byte Table

| Byte | Hex | Binary | Note |
|---:|---:|---:|---|
| 00 | `3A` | `00111010` | low-confidence fog-related cross-platform refs only |
| 01 | `B8` | `10111000` | unmapped |
| 02 | `2B` | `00101011` | unmapped |
| 03 | `9F` | `10011111` | unmapped |
| 04 | `08` | `00001000` | unmapped |
| 05 | `A1` | `10100001` | unmapped |
| 06 | `00` | `00000000` | unmapped |
| 07 | `00` | `00000000` | unmapped |
| 08 | `00` | `00000000` | unmapped |
| 09 | `30` | `00110000` | unmapped |
| 10 | `08` | `00001000` | unmapped |
| 11 | `00` | `00000000` | unmapped |
| 12 | `2C` | `00101100` | differs from known-good `6C`; base cornering area |
| 13 | `68` | `01101000` | matches known-good; CH/LH and parking-light group |
| 14 | `0E` | `00001110` | unmapped |
| 15 | `D0` | `11010000` | unmapped |
| 16 | `00` | `00000000` | unmapped |
| 17 | `C8` | `11001000` | unmapped |
| 18 | `41` | `01000001` | low-confidence fog-diagnostics cross-platform refs only |
| 19 | `2F` | `00101111` | older low-confidence reference exists; not trusted |
| 20 | `60` | `01100000` | unmapped |
| 21 | `A2` | `10100010` | differs from known-good `A6`; turn-signal cornering area |
| 22 | `00` | `00000000` | matches known-good; probable ADL-related area |
| 23 | `00` | `00000000` | unmapped |
| 24 | `20` | `00100000` | unmapped |
| 25 | `00` | `00000000` | unmapped |
| 26 | `00` | `00000000` | unmapped |
| 27 | `00` | `00000000` | unmapped |
| 28 | `00` | `00000000` | unmapped |
| 29 | `00` | `00000000` | unmapped |

## Every Currently Identifiable Setting

These are all settings that can be named with some level of confidence from the
current workspace evidence. Everything else in the 30-byte string is still
unmapped.

| Byte | Bit | Confidence | Current state | Setting |
|---:|---:|---|---|---|
| 12 | 6 | high | clear / off | Base fog-light cornering function |
| 21 | 2 | high | clear / off | Turn-signal-triggered cornering assist |
| 13 | 6 | medium | set | Coming/Leaving Home fog-vs-low-beam selector; label still disputed |
| 13 | 0 | medium | clear | Parking-light behavior group member |
| 13 | 1 | medium | clear | Parking-light behavior group member |
| 13 | 3 | medium | set | Parking-light behavior group member |
| 21 | 7 | medium | set | Fog-related capability/install bit; exact label still uncertain |
| 22 | 5 | medium | clear | Probable ADL-related bit |
| 00 | 0 | low | clear | Front fog lights installed; weak cross-platform reference only |
| 18 | 2 | low | clear | Cold diagnosis front fog lights active; weak cross-platform reference only |
| 18 | 3 | low | clear | Cold diagnosis rear fog lights active; weak cross-platform reference only |

## What Differs From The Working Coding

Only these two bytes differ from the known-good working reference:

```text
byte 12: 2C -> 6C
byte 21: A2 -> A6
```

Those byte changes correspond to the two highest-confidence cornering bits:

```text
byte 12 bit 6: clear -> set
byte 21 bit 2: clear -> set
```

The other currently important focus bytes already match the working coding:

```text
byte 13: 68 == 68
byte 22: 00 == 00
```

## Practical Meaning For The Next Attempt

- The current car state is still the pre-fix coding state.
- The minimal proven target remains restoring byte 12 bit 6 and byte 21 bit 2 to the set state without disturbing the rest of the coding.
- Because Carista's native write path is now known to use a structured `3B9A` builder rather than a 30-byte blob, the write implementation still has to be fixed before another live attempt is trustworthy.

## Unknown Settings

- The remaining bytes and bits in this 30-byte coding string are not confidently mapped in this workspace yet.
- VCDS text labels helped with comparable central-electrics themes, but they do not provide a trustworthy full 6R0-937-087K bit-by-bit decode.
- Treat any unnamed bit as unknown, not disabled or irrelevant.