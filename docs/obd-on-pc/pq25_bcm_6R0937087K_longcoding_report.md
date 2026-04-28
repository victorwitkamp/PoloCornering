# PQ25 BCM Long Coding Reference

Date: 2026-04-24

Controller:

```text
Part #: 6R0937087K
Component: BCM PQ25 H+4
Software version: 0254
```

Known-good long coding where cornering lights were working again:

```text
3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

Length:

```text
30 bytes
```

## Byte Table

| Byte | Hex | Binary |
|---:|---:|---:|
| 00 | `3A` | `00111010` |
| 01 | `B8` | `10111000` |
| 02 | `2B` | `00101011` |
| 03 | `9F` | `10011111` |
| 04 | `08` | `00001000` |
| 05 | `A1` | `10100001` |
| 06 | `00` | `00000000` |
| 07 | `00` | `00000000` |
| 08 | `00` | `00000000` |
| 09 | `30` | `00110000` |
| 10 | `08` | `00001000` |
| 11 | `00` | `00000000` |
| 12 | `6C` | `01101100` |
| 13 | `68` | `01101000` |
| 14 | `0E` | `00001110` |
| 15 | `D0` | `11010000` |
| 16 | `00` | `00000000` |
| 17 | `C8` | `11001000` |
| 18 | `41` | `01000001` |
| 19 | `2F` | `00101111` |
| 20 | `60` | `01100000` |
| 21 | `A6` | `10100110` |
| 22 | `00` | `00000000` |
| 23 | `00` | `00000000` |
| 24 | `20` | `00100000` |
| 25 | `00` | `00000000` |
| 26 | `00` | `00000000` |
| 27 | `00` | `00000000` |
| 28 | `00` | `00000000` |
| 29 | `00` | `00000000` |

## Focus Bytes

These are the bytes that currently matter most for the PQ25 cornering-light
discussion:

| Byte | Hex | Binary | Notes |
|---:|---:|---:|---|
| 12 | `6C` | `01101100` | base cornering-light area |
| 13 | `68` | `01101000` | CH/LH and parking-light related area |
| 21 | `A6` | `10100110` | turn-signal cornering and fog-related area |
| 22 | `00` | `00000000` | probable ADL-related bit currently off |

## Higher-Confidence Bits

These are the bits with the best practical confidence from the supplied working
coding plus earlier observed coding deltas:

| Byte | Bit | Value | State | Candidate meaning |
|---:|---:|---:|---|---|
| 12 | 6 | `6C` | set | Base fog-light cornering function |
| 21 | 2 | `A6` | set | Turn-signal-triggered cornering assist |

The strongest practical support is:

- byte `12` bit `6` matches the observed `2C -> 6C` change
- byte `21` bit `2` matches the observed `A2 -> A6` change

## Medium-Confidence Bits

These are useful, but the exact public labels are not clean enough to treat them
as fully settled:

| Byte | Bit | Value | State | Candidate meaning |
|---:|---:|---:|---|---|
| 13 | 6 | `68` | set | Coming/Leaving Home fog-vs-low-beam selector |
| 13 | 0 | `68` | clear | Parking-light behavior group member |
| 13 | 1 | `68` | clear | Parking-light behavior group member |
| 13 | 3 | `68` | set | Parking-light behavior group member |
| 21 | 7 | `A6` | set | Fog-related capability/install bit |
| 22 | 5 | `00` | clear | Probable ADL-related bit |

Notes:

- byte `13` bit `6` is documented in older PQ25 references, but your Carista UI
  showing low beams means the label is not fully trustworthy on this BCM/app
  combination
- byte `13` bits `0`, `1`, and `3` clearly belong to the parking-light group,
  but not with enough confidence to map one Carista toggle to one exact bit
- byte `21` bit `7` is fog-related, but the exact label is still muddy
- byte `22` bit `5` looks ADL-related, but should still be treated as a
  semi-trustworthy mapping

## Dropped From The Confident Set

Byte `19` bit `5` was previously treated as more important than it deserved.
With the current evidence, it should not be treated as part of the strong PQ25
cornering-light map.

## Weaker Cross-Platform References

These came from comparable J519 labels in VCDS. They are still useful background,
but they should not drive conclusions on this BCM:

| Byte | Bit | Value | State | Reference meaning |
|---:|---:|---:|---|---|
| 00 | 0 | `3A` | clear | Front Fog Lights installed |
| 18 | 2 | `41` | clear | Cold Diagnosis Front Fog Lights active |
| 18 | 3 | `41` | clear | Cold Diagnosis Rear Fog Lights active |

## Offline VCDS Helper Prep

Created files for standalone LCode work:

```text
obd-on-pc/lcode/pq25_6r0_937_08x_cornering_candidates.xpl
obd-on-pc/lcode/6R0937087K_cornering_enabled_longcoding.txt
obd-on-pc/decode_pq25_longcoding.py
```

Practical use:

1. Open `LCode.exe`.
2. Paste the long-coding string above.
3. Load `pq25_6r0_937_08x_cornering_candidates.xpl`.
4. Check bytes `12`, `13`, `21`, and `22` first.

Local decoder example:

```text
python decode_pq25_longcoding.py --coding-file lcode/6R0937087K_cornering_enabled_longcoding.txt
```

## Practical Reading Of This Coding

This specific working coding says, with the current confidence levels:

- cornering via fogs = on
- turn-signal cornering assist = on
- ADL = off
- CH/LH and parking-light behavior are still influenced by byte `13`
- some additional fog-related behavior is still present around byte `21`

That fits the coding better than the earlier broader candidate set, but it still
does not fully explain the real-world fog behavior by itself. The remaining
possibilities are:

- a less-well-documented neighboring fog bit
- switch/input logic outside the small set above

So for the next extraction or comparison attempt, bytes `12`, `13`, `21`, and
`22` should be treated as the primary area of interest.
