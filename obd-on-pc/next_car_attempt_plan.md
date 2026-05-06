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

Last verified coding before the latest Carista-side change:

```text
3AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000
```

That value is no longer assumed to be the live value. Carista has changed the
coding since this file was last updated, so the next car session must read
`220600` first and treat that fresh payload as the only current baseline.

Last physical result before the latest Carista-side change:

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

Current first write target after the fresh read:

```text
3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

2026-05-05 live result:

```text
fresh current 220600 read:
3AB02BBF08A10000003008006C6A0CD000C0412F60860000200000000000

guarded 2E0600 write target:
3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000

fresh verification 220600 read:
3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000

positive validation reads:
220601 -> 6206011E
220606 -> 620606001800018000
22F1A5 -> 62F1A50005F3C7E719

negative validation reads:
22110E, 22056D, 220550, 220551, 220D01, 220A58, 220A57 -> 7F2231
```

The target coding is now write-proven and behavior-disproven as a standalone
fix: the ECU accepted the recovered Carista-shaped DID `0600` write and a fresh
channel verified the target bytes, but the physical fog/cornering behavior below
still does not match cornering-lamp behavior.

Back-in-car persistence check:

```text
2026-05-05 13:30 fresh 220600 read:
6206003AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

The target coding persisted after returning to the car.

Physical behavior with the target coding persisted:

```text
switch left: front fogs off; only headlights observed
switch middle: front fogs on with low beam
switch right, not pulled: headlights + front fogs + low beam
switch right, not pulled, left indicator: front fogs stay steadily on
switch right, not pulled, right indicator: front fogs stay steadily on
switch right, pulled once: no front-fog behavior difference
switch right, pulled twice: no front-fog behavior difference; rear fog behaves as expected
high beam on: front fogs turn off
```

This points away from a missing cornering-bit write. Both front fog outputs are
being driven as a steady low-beam-linked function with high-beam inhibit, not as
left/right cornering outputs triggered by turn input.

This is the supplied/reference cornering-enabled coding in
`obd-on-pc/lcode/6R0937087K_cornering_enabled_longcoding.txt`. It remains a
verified rollback/reference value, but it is no longer an active standalone fix
candidate for the visible symptom.

## Historical Write Evidence

The former live BCM write runner was removed. Its live-proven request sequence
is retained here as evidence for recovered Carista behavior:

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
the full supplied/reference coding as a standalone fix
byte 13 bit 6 / coming-home-leaving-home variant after the restored D2B coding persisted across restarts
055C/055D-style newer platform lamp-channel reads
unsupported hardware/input blame without new evidence
```

## Current Lead

The 2026-05-05 physical behavior makes the next lead more specific than
cornering enablement: the front fog outputs behave like they are configured to
activate with low beams and to turn off with high beams.

Recovered/catalog keys that match this behavior:

```text
car_setting_front_fogs_with_low_beams
car_setting_turn_off_fogs_with_high_beam
car_setting_fogs_with_high_beam_restriction
```

`car_setting_turn_off_fogs_with_high_beam` is consistent with the observed high
beam cutoff and with the candidate long-coding bit `byte 21 bit 5`, so it is not
the primary fault by itself. The exact `car_setting_front_fogs_with_low_beams`
direct reference has now been reconstructed as `FordUdsSetting`, not a VAG/PQ25
setting path. It explains why the catalog label matched the symptom, but it does
not provide a VW read/write method. Do not invent a write for it.

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

2026-05-06 constructor follow-up strengthened this VAG path rather than
opening a write path:

```text
left variant 1:  01082988 -> 010B90CC -> 010E44E8 -> VagUdsAdaptationSetting
left variant 2:  01082A4A -> 010B5620 -> 010D2BD0 -> VagUdsAdaptationSetting
right variant 1: 01082B78 -> 010B8574 -> 010E0DE8 -> VagUdsAdaptationSetting
right variant 2: 01082C34 -> 010B9120 -> 010E466C -> VagUdsAdaptationSetting
```

The current explanation is therefore: the `0600` long-coding target enabled the
known Carista-shaped cornering master bits, but the fog outputs still appear to
be assigned to a steady low-beam / coming-leaving-home role. In that state the
low-beam/high-beam logic owns the lamps, so turn input cannot produce visible
left/right cornering behavior.

The likely repair is not another blind cornering-bit write. The likely repair
is one of these matched Carista-side combinations:

```text
change left/right fog role from 1E to 16/17
change a coming/leaving-home output or master setting so fogs stop being the steady output
change both, if Carista's runtime branch expects the role and CH/LH output settings to move together
```

This is still an explanation and reconstruction target, not a live instruction.

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

2026-05-05 fresh-channel validation also proved the nearby CH/LH and fog/high-
beam direct UDS adaptation candidates are not useful retry targets in the
normal session:

```text
22110E -> 7F2231
22056D -> 7F2231
220550 -> 7F2231
220551 -> 7F2231
220D01 -> 7F2231
220A58 -> 7F2231
220A57 -> 7F2231
```

These blocked reads need more reconstruction work, not more blind direct-read
work. The useful next path is static/native branch selection, requested-choice
encoding, and any remaining long-coding / VAG short-adaptation constructor
packing beside the rejected type-7 UDS adaptation branches. The UDS coding
constructor shape is now recovered for the relevant DID `0600` byte/mask pairs.

The generated catalog for the broader setting map is:

```text
docs/carista_apk_analysis/pq25_carista_setting_catalog.md
carista_apk_analysis/pq25_carista_settings_catalog.csv
carista_apk_analysis/pq25_carista_longcoding_bits.csv
carista_apk_analysis/pq25_carista_setting_catalog.json
```

Use that catalog as the current map. Older static maps are background evidence
only.

## Next Work

No new live write is in scope. The DID `0600` target write is already proven,
verified, persisted, and behavior-disproven as a standalone fix. Do not rerun it
unless a fresh rollback/verification task explicitly requires it.

Do not repeat these direct reads by default:

```text
22055C, 22055D, 22110E, 22056D, 220550, 220551, 220D01, 220A58, 220A57
```

Each has clean `7F2231` evidence on this BCM/session. Retest only if static
recovery finds a recovered Carista precondition, alternate session, security
state, or different transport path for that exact constructor branch.

The next high-value work is offline reconstruction:

```text
1. Recover runtime branch selection for 6R0937087K in VagOperationDelegate::getVagSettingAvailabilityForEcu.
2. Resolve requested-choice encoding for the recovered VagUdsCodingSetting DID 0600 byte/mask variants.
3. Map VagCanLongCodingSetting variants beside the rejected adaptation DIDs.
4. Map FullByteVagCanShortAdaptationSetting branches for CH/LH duration/output where present.
5. Trace the positive companion reads 220601 -> 1E and 220606 -> 001800018000 back to recovered native setting/value branches.
```

If another live read-only session is needed, keep it to positive baseline/context
reads unless a newly recovered branch changes the hypothesis:

```text
220600  current long coding
220601  stable companion clue, previously 6206011E
220606  stable companion clue, previously 620606001800018000
22F1A5  workshop-code/status context
```

If a temporary live runner is needed, create it outside `CaristaReproduction`,
call only recovered `CaristaReproduction` symbols, and remove that runner after
the session.