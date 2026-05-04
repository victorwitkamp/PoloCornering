# PQ25 BCM Latest Live Long-Coding Decode

Date: 2026-04-28

## Latest Verified Baseline

The car was restored to this verified baseline after the live write tests:

```text
3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000
```

Read method:

```text
TP2.0 unit 20 direct UDS read 220600
positive response: 620600 + 30-byte coding
```

## Supplied/Reference Comparison

Supplied/reference coding:

```text
3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

Only two bits differ:

```text
byte 12 bit 6: baseline clear, supplied/reference set
byte 21 bit 2: baseline clear, supplied/reference set
```

Both differences were written and verified during the live session. The visible
fog/cornering behavior was unchanged, so the latest interpretation is:

```text
byte 12 bit 6: mapped, tested, not the visible fix by itself
byte 21 bit 2: mapped, tested, not the visible fix by itself
```

## Current Focus Bits

| Byte | Baseline | Reference | Current interpretation |
|---:|---|---|---|
| 12 | `2C` | `6C` | Carista fog-cornering/use-cornering family; behavior-ruled-out for current symptom |
| 13 | `68` | `68` | CH/LH/parking-light context; not a current diff |
| 21 | `A2` | `A6` | Carista turn-signal-trigger family; behavior-ruled-out for current symptom |
| 22 | `00` | `00` | ADL context; not a current diff |

## Diagnostic Follow-Up

Post-test diagnostic/status reads found no fog-specific smoking gun:

```text
1902FF   -> 7F1911
1802FF00 -> 58020C9820038B20
220606   -> 620606001800018000
```

## Current Lead

Do not infer that every fog/cornering issue is solved by byte `12` or byte `21`.
The active lead is the pair of unresolved per-side fog-role settings:

```text
car_setting_left_fog_light_as
car_setting_right_fog_light_as
```

Unknown bits in the 30-byte long coding remain unknown. Do not turn them into
write targets without a Carista-backed setting/value/method link.