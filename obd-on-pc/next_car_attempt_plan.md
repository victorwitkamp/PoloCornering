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

2026-05-06 engine-running read-only context snapshot:

```text
log summary:
obd-on-pc/logs/live_minimum_context_retry_ack_20260506_193832_summary.json

220600 -> 6206003AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
coding  ->   3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
220601 -> 6206011E
220606 -> 620606001800018000
22F1A5 -> 62F1A50005F3C7E719
```

This confirms the target `0600` coding still persists with the engine running.
The live wrapper initially saw only the first frame of multi-frame responses;
the complete retry proved that ECU application response frames beginning with
`0x0` must be ACKed with the same recovered `B((seq + 1) & 0x0F)` rule before
the remaining response frames arrive.

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

The preferred x86 static pass now changes how to treat those labels. The direct
resource keys are not VW/PQ25 setting objects:

```text
car_setting_fog_when               -> FordSettings::getSettings / FordCodingSetting
car_setting_left_fog_light_as      -> FordSettings::getSettings / FordUdsSetting
car_setting_right_fog_light_as     -> FordSettings::getSettings / FordUdsSetting
car_setting_use_cornering_lights   -> FordSettings choice label in the same block
cornering one-touch turn-signal    -> BmwESettings::getSettings / BmwESetting
```

So do not chase those exact labels as direct VW write targets. A VW/PQ25
equivalent, if present, must be reached through a different VAG key,
availability sub-object, or ReadValuesOperation value path.

Offline Ghidra evidence still gives a related per-side VAG-path target for each
side, but x86 branch selection now makes it a negative PQ25 clue rather than the
current write lead:

```text
car_setting_cornering_lights_via_fogs_left  -> VagUdsAdaptationSetting DID/raw address 055C, byte offset 5, mask FF
car_setting_cornering_lights_via_fogs_right -> VagUdsAdaptationSetting DID/raw address 055D, byte offset 5, mask FF
left choice values:  00=off, 16=on, 1E=enabled coming-home/leaving-home
right choice values: 00=off, 17=on, 1E=enabled coming-home/leaving-home
```

2026-05-06 constructor follow-up strengthened the negative boundary:

```text
left variant 1:  01082988 -> 010B90CC -> 010E44E8 -> VagUdsAdaptationSetting
left variant 2:  01082A4A -> 010B5620 -> 010D2BD0 -> VagUdsAdaptationSetting
right variant 1: 01082B78 -> 010B8574 -> 010E0DE8 -> VagUdsAdaptationSetting
right variant 2: 01082C34 -> 010B9120 -> 010E466C -> VagUdsAdaptationSetting
x86 same-key branches are MQB/MK8 or gateway/MEB scoped, not 6R/PQ25
```

The current explanation is therefore narrower: the `0600` long-coding target
enabled the known Carista-shaped cornering bits, but those bits are already set
or behavior-disproven. The fog outputs still appear to be assigned to a steady
low-beam / coming-leaving-home role through a path not yet recovered as a PQ25
Carista setting.

The likely repair is not another blind cornering-bit write. The remaining
repair hypothesis is an unrecovered output-role/prerequisite path, not the
known per-side `055C` / `055D` type-7 branch:

```text
an alternate VW/PQ25 fog-role key
a ReadValuesOperation value object that maps visible role labels to another raw value
a coming/leaving-home output/master branch that makes fogs the steady output
```

This is still an explanation and reconstruction target, not a live instruction.

## Actual Fix Path Now

The next step toward actually fixing the fogs is to prove or kill the stored
role-conflict hypothesis, not to flip another long-coding bit.

Current best evidence:

```text
220601 -> 6206011E
```

2026-05-07 current-state in-car read-only confirmation, using the exact
Carista TP2.0 channel parameter request `A00194FF82FF`, returned:

```text
220600 -> 6206003AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
220601 -> 6206011E
220606 -> 620606001800018000
22F1A5 -> 62F1A50005F3C7E719
```

Retained log:

```text
obd-on-pc/logs/readonly_tp20_20260507_075726_tp20_readonly_context.json
```

The trailing `1E` is byte-for-byte equal to Carista's recovered
`car_setting_enabled_coming_home_or_leaving_home` choice in the older VAG
per-side fog-role tables:

```text
left  055C offset 5 mask FF: 00=off, 16=on, 1E=enabled coming-home/leaving-home
right 055D offset 5 mask FF: 00=off, 17=on, 1E=enabled coming-home/leaving-home
```

That makes `0601=1E` the strongest current repair clue: the front fog outputs
may be owned by a coming/leaving-home or low-beam-linked role while the known
cornering master bits are already set.

What this does not prove:

```text
do not write 2E0601
do not write 2E055C or 2E055D
do not treat 1E -> 16/17 as a payload until a positive current path is recovered
```

`0606=001800018000` is weaker. Successful isolated reads reassembled to that
same payload, but the switch-state sweeps mostly produced `no_response` or
`disconnect`, so there is no proven lamp-state correlation for `0606` yet.

The useful next live proof is therefore a focused read-only correlation pass:

```text
for each state, open a fresh TP2.0 channel, read only 220600, 220601, 220606, 22F1A5
states: low beam off/on, high beam, front fogs, rear fog, left indicator, right indicator, steering angle left/right
record manual lamp observation and input state for each state
if possible, also capture raw CAN headers 390, 392, 0D0, 0C2, 1A0, 320, 470
```

The proof target is simple:

```text
If 0601 stays 1E while raw CAN proves the BCM sees blinkers/fogs/high-beam, 0601 is stored role/configuration.
If 0601 changes after an external Carista/VCDS visible setting change, use that before/after delta to recover the real write path.
If 0606 changes with a lamp state, decode it as live/status first, not as a repair payload.
```

The lowest-risk path to a real repair is a before/after capture around a known
UI-level change made by Carista or VCDS, with this reproduction recording the
diagnostic delta. The local reproduction should only send a repair write after
that delta or an equivalent native branch proves the constructor, current
payload, target branch, selected availability predicate, and requested-choice
encoding.

The x86-led static pass is still negative for an owned `0601` path: the Play
9.8.3 x86 scan found zero decoded instruction operands for `0x0601`,
`0x220601`, or `0x620601`, and no decoded instruction reference tying
`car_setting_enabled_coming_home_or_leaving_home` to DID `0601`. Treat ARM
part-pattern evidence only as corroboration; the ARM per-side region shows
`5Q0937084*` / `6C093708*`, not `6R0937087K`.

That is still a blocked read-first lead, not a write instruction. Offline native
recovery now shows raw type 7 dispatches through `readVagUdsValue` and
`ReadRawDataByIdentifierCommand`, so Carista's direct native read request for
these raw addresses is exactly `22055C` / `22055D`. Those requests were rejected
live, so a positive current raw payload and payload length are still missing
before any `2E055C` / `2E055D` write can be considered.

If a future recovered Carista path produces a positive current value of `1E`,
do not treat that as a standalone fault. Carista names `1E` as a
coming-home/leaving-home enabled choice in the rejected per-side tables, and
historical reads repeatedly returned `220601 -> 6206011E`. The proof step would
then be to evaluate the matched combination: fog role, coming/leaving-home
output selection, and any master coming/leaving-home enable state. Until that
positive path exists, there is no payload seed for `1E -> 16/17`.

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
1. Treat 220601 -> 1E as the top repair clue and prove whether it is stored fog-role/CH-LH configuration.
2. Keep x86 as primary authority; use ARM only as corroboration for older tables and part-pattern scope.
3. Resolve the special getVagSettingAvailabilityForEcu vtable +0x3C predicate path.
4. Dump constructor StringWhitelist contents for the AvailBy=2 VAG branches and match them to 6R0937087K.
5. Find any alternate VW/PQ25 VAG key or ReadValuesOperation value object behind the visible fog-role behavior.
6. Trace 220606 -> 001800018000 only after fresh captures show whether it is live state or stable status.
7. Keep requested-choice encoding branch-specific; do not promote compact choice values to write payloads without a positive current path.
```

## 2026-05-08 Deep RE Round Findings

A full re-read of all 12 recovered branch files plus the helpers table produced
the following closures and one new open hypothesis.

### Closed (no 6R branch, not a fix path)

- `coming_home_via_fogs` (`012C929B`): all sub-branches use MK7/B8/MQB
  whitelists.  No 6R sub-branch exists.  Coming-home fog role on 6R/PQ25
  is controlled only by long-coding bits in DID 0600 (byte 13, bit 6).
- `cornering_lights_activation_d1d` (`012DA8BD`): DID 0x0D1D, guarded by
  MK7/6C/MQB/B8 whitelists/access codes.  Not applicable to 6R.
- `cornering_lights_min/max_activation_speed_d1d` (`012DAF54`, `012DB176`):
  also DID 0x0D1D, also non-6R.
- `car_setting_use_cornering_lights`: maps to the same byte 12 bit 6 as
  `car_setting_cornering_lights_via_fogs`.  Not a separate prerequisite.

### New open hypothesis: DRL-via-fogs enabling individual fog output control

`car_setting_drl_via_fogs` has an official 6R/PQ25 branch recovered at
`012CDE7B`:

```text
DID 0600 byte 0x17 (23), mask 0x04 (bit 2)
whitelist: CENTRAL_ELEC_6R_5C_7E_7H
interpretation: YES_NO
callee: VagUdsCodingSetting_drl_via_fogs (01361520 file VA)
```

In the current live coding (2026-05-07) byte 23 = `0x00`, so bit 2 is
**CLEAR** (DRL via fogs disabled).

Five named 6R constructors are now modelled in
`CaristaReproduction/VagUdsCodingSetting.py`:

```text
VagUdsCodingSetting_cornering_fogs()            -> byte 12, mask 0x40
VagUdsCodingSetting_cornering_fogs_experimental() -> byte 21, mask 0x80
VagUdsCodingSetting_cornering_turn_signals()    -> byte 21, mask 0x04
VagUdsCodingSetting_drl_via_fogs()              -> byte 23, mask 0x04  (NEW; currently CLEAR)
VagUdsCodingSetting_turn_off_fogs_high_beam()   -> byte 21, mask 0x20
```

**Hypothesis**: Some PQ25 BCM implementations use the DRL-via-fogs coding bit
to gate individual left/right fog output control.  When only the cornering bits
are set but DRL-via-fogs remains clear, the BCM may continue driving both fog
outputs together as a single pair, preventing per-side cornering activation.

This is NOT confirmed.  The recommended proof step is a before/after
correlation read-only pass in the car:

```text
1. Read 220600 baseline (expect 3AB82B9F...6C680ED000C8412F60A6...)
2. Ask Carista or VCDS to enable DRL via fogs for the 6R (if shown as available).
3. Re-read 220600 and check whether byte 23 bit 2 changes.
4. With DRL-via-fogs set, test the cornering fog behavior (indicator + slow speed).
5. If behavior changes, the hypothesis is confirmed and we have the write path.
6. If not, this bit is also ruled out.
```

Do not write `2E0600` with byte 23 bit 2 set until the correlation test has
a positive read-only result or a direct Carista-visible UI path is confirmed.

If another live read-only session is needed, keep it to positive baseline/context
reads unless a newly recovered branch changes the hypothesis:

```text
220600  current long coding
220601  strongest stored-role clue, previously 6206011E
220606  weaker companion clue, previously 620606001800018000
22F1A5  workshop-code/status context
```

If a temporary live runner is needed, create it outside `CaristaReproduction`,
call only recovered `CaristaReproduction` symbols, and remove that runner after
the session.
