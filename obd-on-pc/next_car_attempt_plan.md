# Next Car Attempt Plan

Purpose: keep the next live work short, evidence-driven, and aligned with the
working BCM write path that has now been proven on the car.

## Current Boundary

Vehicle/controller:

```text
VW Polo 6R / PQ25 BCM J519 / unit 09
TP2.0 unit address: 20
Part: 6R0937087K
Adapter: COM10 at 38400 baud
```

Current verified baseline coding:

```text
3AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000
```

Latest physical result:

```text
After the 2026-05-03 guarded rewrite and multiple car restarts, coding stayed at byte 13 = 2B, but the fog lights are still always on.
```

Earlier supplied/reference coding differed only at:

```text
byte 12 bit 6: clear -> set
byte 21 bit 2: clear -> set
```

Both bits were live-written and verified. The visible fog/cornering symptom was
unchanged, so do not retest those two bits blindly.

## Working Write Path

The working BCM write path is the guarded Carista-shaped UDS DID `0600` writer:

```text
obd-on-pc/write_carista_uds_coding.py
```

The live-proven request sequence is:

```text
2EF199 + YYMMDD
22F1A5 inline workshop-code read
2EF198 + workshop-code payload
2E0600 + full 30-byte coding
```

Important TP2.0 details that must remain intact:

```text
open request: 20C00010000301
send header: 338
listen header: 300
channel params used successfully: A00F8AFF32FF -> A10F8AFF4FFF
ACK ECU response seq N with B((N + 1) & 0x0F)
advance outgoing counter per TP2.0 data frame
use ATST04 for non-final write frames
use ATST20 for final/response frames
use about 130 ms between outgoing TP2.0 data frames
do not add the old long passive wait between F198 and final 2E0600
```

`7F2E31` on `F199` or `F198` is nonfatal Carista metadata behavior. The final
`2E0600` write still must return `6E0600` and be verified by a fresh `220600`
read.

## Ruled Out

These are no longer active fix candidates for the current symptom:

```text
blind 3B9A + full 30-byte coding
default 1089 session before DID 0600 write
repeating 1A9B/1A9A metadata sweeps without a new sequencing hypothesis
byte 12 bit 6 alone
byte 21 bit 2 alone
byte 12 bit 6 plus byte 21 bit 2 together
byte 13 bit 6 / coming-home-leaving-home variant after the restored D2B coding persisted across restarts
055C/055D-style newer platform lamp-channel reads
unsupported hardware/input blame without new evidence
```

## Current Lead

Carista's own instruction says the cornering/fog function depends on three
settings:

```text
Use fog lights when...
Use the left fog light as...
Use the right fog light as...
```

The first family maps to the already-tested long-coding bits. The highest-value
unresolved settings are now:

```text
car_setting_left_fog_light_as
car_setting_right_fog_light_as
```

Offline Ghidra evidence now gives a concrete related VAG-path target for each
side:

```text
car_setting_cornering_lights_via_fogs_left  -> VagUdsAdaptationSetting DID/raw address 055C, byte offset 5, mask FF
car_setting_cornering_lights_via_fogs_right -> VagUdsAdaptationSetting DID/raw address 055D, byte offset 5, mask FF
left choice values:  00=off, 16=on, 1E=enabled coming-home/leaving-home
right choice values: 00=off, 17=on, 1E=enabled coming-home/leaving-home
```

That is still a blocked read-first lead, not a write instruction. Offline native
recovery now shows raw type 7 dispatches through `readVagUdsValue` and
`ReadRawDataByIdentifierCommand`, so Carista's direct native read request for
these raw addresses is exactly `22055C` / `22055D`. Those requests were rejected
live, so a positive current raw payload and payload length are still missing
before any `2E055C` / `2E055D` write can be considered.

If a positive read shows byte 5 is `1E`, do not treat that as a standalone
fault. Carista names `1E` as the coming-home/leaving-home enabled choice, and
historical reads repeatedly returned `220601 -> 6206011E`. The next proof step
is to evaluate the matched combination: per-side fog role, coming/leaving-home
output selection, and any master coming/leaving-home enable state. The repair
may be `1E -> 16`, a separate coming/leaving-home output change, or both as a
Carista-consistent combination.

2026-05-03 live read-only follow-up proved two more boundaries:

```text
220601 stayed 6206011E across switch-left, switch-middle, switch-right,
right-position pulled once, right-position pulled twice, and middle-position
with right turn signal.

22055C -> 7F2231
22055D -> 7F2231
```

So `0601=1E` is a stable configuration/status clue rather than a live switch
state, and `055C/055D` are not readable as simple UDS DIDs on this
BCM/session. Offline recovery also found Carista's separate VAG CAN adaptation
routine sequence (`31B8`, `31BA`, `31B9`, `31BA`, `32B8`; short basic id
`0103`, long basic id `010A`), but that sequence is used for raw types `0/1`,
not the raw type `7` `VagUdsAdaptationSetting` objects recovered for
`055C/055D`. Do not attempt `2E055C` / `2E055D` writes.

The generated catalog for the broader setting map is:

```text
docs/carista_apk_analysis/pq25_carista_setting_catalog.md
carista_apk_analysis/pq25_carista_settings_catalog.csv
carista_apk_analysis/pq25_carista_longcoding_bits.csv
carista_apk_analysis/pq25_carista_setting_catalog.json
```

Use that catalog as the current map. Older static maps are background evidence
only.

## Next Session

Only do a short read/confirm pass unless a new Carista proof artifact exists.

Recommended order:

```text
1. Read 220600 and confirm the current baseline coding.
2. If coding differs from the baseline above, stop and decode that new state.
3. If coding matches, do not probe 055C/055D again unless a new native proof artifact identifies a path other than the already-rejected raw type 7 RDBI path.
4. If either value reads as 1E, also capture 220601 and any recovered coming/leaving-home output/master settings before deciding on a write.
5. Do not flip unknown byte 21, byte 22, diagnostics, or lamp-channel bits.
6. Only run write_carista_uds_coding.py when intentionally restoring or testing a fully reviewed 30-byte target.
```

The next useful proof is not another random long-coding bit. It is a recovered
Carista runtime setting object, DID, adaptation channel, or write tuple for the
left/right fog-role settings.