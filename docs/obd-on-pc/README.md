# OBD On PC

## Progress So Far - 2026-04-16

This folder is for a VW Polo 6R troubleshooting session. The owner clarified the car is PQ25, not PQ26/MQB. That matters because the earlier `70E -> 778` BCM target and `22055C` / `22055D` light-channel reads come from Car Scanner's PQ26/MQB coding database and did not work on this car.

Keep everything read-only unless explicitly deciding otherwise later.

Blocked or do-not-send services:

```text
27...  security access
2E...  UDS write data
31...  UDS routine control
3B...  KWP write data by local identifier
```

### Backup Extraction Result

The Android Car Scanner backup was decoded before this PC work.

Important extracted files:

```text
phone_extract/coding_extracted_summary.txt
phone_extract/coding_extracted.json
car_scanner_coding_extraction_report.md
```

The backup contained coding for only these units:

```text
Unit 01 engine:
  request 7E0, response 7E8
  0600 = 001100D6202400080000

Unit 17 cluster:
  request 714, response 77E
  0600 = 140801
```

No unit 09 / BCM coding was present in the extracted Car Scanner backup.

### Adapter And COM Ports

Two Bluetooth OBD adapters were seen:

```text
Cheap OBDII clone:
  device OBDII
  address 00:10:CC:4F:36:03
  COM8
  reports ELM327 v2.1

Carista:
  device Carista
  address 88:1B:99:68:41:8D
  COM10
  reports ELM327 v1.5
```

The Carista address matches the adapter stored in the Car Scanner backup, so `COM10` is the right adapter to continue with.

### UDS Results

The cheap `COM8` adapter could read the engine but failed to reach non-engine modules reliably.

The Carista `COM10` adapter worked better:

```text
7E0 -> 7E8, 220600:
  positive, engine coding = 001100D6202400080000

714 -> 77E, 220600:
  positive, cluster coding = 140801
```

A full VAG UDS header discovery with Carista found these positive `220600` responders:

```text
7E0 -> 7E8: 001100D6202400080000
714 -> 77E: 140801
715 -> 77F: 003232
711 -> 77B: 000000
```

Positive `22F190` responders:

```text
7E0 -> 7E8: WVWZZZ6RZCY230414
714 -> 77E: WVW... partial/multiframe VIN
715 -> 77F: WVW... partial/multiframe VIN
711 -> 77B: WVW... partial/multiframe VIN
```

Important negative finding:

```text
70E -> 778:
  220600 = NO DATA
  22F190 = NO DATA
  22055C = NO DATA
  22055D = NO DATA
```

This means the PQ26/MQB BCM path is not reachable or not applicable here.

The raw UDS discovery logs for the rejected PQ26/MQB path were deleted during
cleanup. The retained conclusion is:

```text
70E -> 778 did not answer for 220600, 22F190, 22055C, or 22055D.
Continue with the PQ25 TP2.0 unit 20 path.
```

### Car Scanner Reverse Engineering Notes

Car Scanner's `VagUnitHelper` maps VAG unit `09` like this for UDS:

```text
unit 09 UDS request header: 70E
unit 09 UDS response header: 778
```

Car Scanner's VAG ECU list also gives unit `09` a VW TP2.0 address:

```text
unit 09 TP2.0 address: 20
unit 09 name: Onboard supply control unit
```

For PQ26/MQB exterior-light coding, Car Scanner uses:

```text
055C left fog/cornering-light channel
055D right fog/cornering-light channel
function 16 = left cornering
function 17 = right cornering
```

Those `055C` / `055D` addresses did not answer on this PQ25 car via UDS.

### Carista Android Findings

The Android Carista app was downloaded as an APKPure XAPK and inspected read-only.

Important files:

```text
docs/carista_apk_analysis/carista_android_analysis_notes.md
docs/carista_apk_analysis/carista_tp20_research_update.md
docs/carista_apk_analysis/carista_relevant_evidence.md
docs/carista_apk_analysis/carista_tp20_candidate_strings.txt
```

The raw APK/XAPK extraction and full string dumps were deleted after their
useful findings were summarized. The small targeted TP2.0 candidate string file
was kept because it is still useful if we need to re-check Carista-derived
command names. Carista's VAG logic was mostly in `libCarista.so`; the useful
clue is that native strings contained simulator data for `ECU VAGCAN20`,
matching the TP2.0 unit address `20` that already opens on this Polo.

Prioritized read-only TP2.0/KWP reads from the Carista data:

```text
1A9B  ECU/component identity
1A91  ECU identity/coding-related block
1A9A  likely long coding or coding-related block
1A86  software/version dataset block
```

Carista also contains VAGCAN20 UDS-style read examples that may be worth trying through the same TP2.0 channel after KWP sequencing works:

```text
220600, 220601, 220606
22F17E, 22F187, 22F189, 22F18C, 22F191, 22F197
22F1A3, 22F1A5, 22F1AA, 22F1DF
```

The simulator includes `31B80000`, but that is routine control and remains blocked.

Carista also gives a guarded write-coding clue:

```text
ReadVagCanLongCodingCommand -> 1A9A
VagCanLongCodingSetting exists in libCarista.so
VagOperationDelegate::writeVagCanCodingValue exists in libCarista.so
literal 3B9A appeared in the native string dump and is preserved in
../carista_apk_analysis/carista_relevant_evidence.md
```

Working interpretation:

```text
read long coding:  1A9A -> 5A9A + coding
write coding:      3B9A exists, but it is a structured value/address builder,
                   not 3B9A + the complete long-coding bytes
```

This is not treated as proven. The prepared writer is dry-run by default and
requires explicit execution confirmations.

### VW TP2.0 Progress

A new script was added:

```text
vw_tp20_readonly_probe.py
```

It is intended for PQ25 VW TP2.0 modules and currently targets unit `09` with TP2.0 address `20`.

Important successful TP2.0 result:

```text
open request on CAN header 200:
  payload 20C00010000301

BCM/channel setup response:
  22000D00003380301

decoded TP2.0 channel:
  send header   = 338
  listen header = 300
```

The TP2.0 channel parameters were successfully read in some runs:

```text
300A10F8AFF4FFF

decoded:
  block = 15
  T1 = 138
  T2 = 255
  T3 = 79
  T4 = 255
```

Opening the diagnostic session worked:

```text
request frame:
  1000021089

response:
  3001000025089

decoded positive response:
  5089
```

After ACKing with `B1`, the ECU returned:

```text
300A8
```

Current blocker:

```text
1A9B, 1A9A, 1A91, 1A90, 1A88, 220600, and 22F190 returned NO DATA after the channel/session opened.
Direct reads without 1089 also returned NO DATA.
```

### Live Scan - 2026-04-17

Carista on `COM10` was connected and responding:

```text
ELM327 v1.5
protocol = ISO 15765-4 (CAN 11/500)
voltage = 14.2V to 14.4V
```

Unit 09 / PQ25 TP2.0 channel opening is confirmed:

```text
request:  20C00010000301
response: 22000D00003380301
decoded:  send=338, listen=300
```

The minimal parameter request is still the right baseline, but it is intermittent:

```text
A00F8AFF32FF sometimes returns:
  22000D00003380301
  300A10F8AFF4FFF

decoded:
  block = 15
  T1 = 138
  T2 = 255
  T3 = 79
  T4 = 255
```

Session results from the live scan:

```text
1089 = positive when the parameter request answered, response 5089
108B = negative 7F1012
1085 = negative 7F1022
1001 = negative 7F1012
1002 = no response in this run
1003 = no response in this run
```

The current blocker is after positive `1089`. `1A9A` was tried with TP2.0 request counters `0`, `1`, `2`, and `3`; every successful session followed by the read produced:

```text
300A8
```

So the BCM is intentionally disconnecting the TP2.0 channel after those read attempts. `1A9F` also produced `300A8` after a positive `1089`. Skipping the channel parameter request opened the channel but made `1089` return no response.

Useful logs from this scan:

```text
logs/pq25_live_20260417_session_minimal_session_sweep_summary.csv
logs/pq25_live_20260417_read_1089_minimal_none_100_read_sweep_summary.csv
logs/pq25_live_20260417_counter_1A9A_none_100_counter_sweep_summary.csv
logs/pq25_live_20260417_counter_1A9A_ctr0_2_repeat_counter_sweep_summary.csv
logs/pq25_live_20260417_skip_params_1A9A_read_sweep_summary.csv
```

Interpretation:

```text
COM port, adapter, TP2.0 unit address 20, and channel decode are correct.
The remaining problem is post-session read sequencing or the exact read identifier/session needed by this BCM.
Do not keep sweeping 1A9A counters blindly; all tested counters disconnect cleanly.
```

### VCDS Reference - 2026-04-24

An extracted VCDS 26.3.0 install was reviewed as an offline reference. The
current extracted installer is outside this project folder:

```text
C:\Users\victo\Downloads\VCDS-Release-26.3.0-Installer
```

Most important VCDS finding:

```text
Polo 6R / module 09 redirects to:
  Labels\6R-09.lbl
  Labels\6R0-937-08x-09.CLB
```

That confirms the BCM family for this car is the `6R0-937-08x` J519 family used on PQ25 Polo 6R cars.

What VCDS helps with:

```text
- confirms module 09 on this platform is long-coding capable
- confirms Ross-Tech expects LCode / Long Coding Helper support for this BCM family
- gives a strong cross-check that we are targeting the right controller family
```

Important limitation:

```text
The actual 6R0 long-coding definitions are stored in the compiled file
6R0-937-08x-09.CLB, not a plain-text LBL file.
That means the exact byte/bit descriptions are not directly grep-able from the
extracted files alone.
```

The exact redirect for this BCM family is:

```text
REDIRECT,6R0-937-08x-09.CLB,6R0-937-087-???   ; High+
```

That matches the supplied controller `6R0937087K`, but does not expose the CLB
bit labels as plaintext. Current notes are in:

```text
vcds_pq25_reference_notes.md
```

What can still be inferred from VCDS:

```text
Comparable J519 long-coding files in VCDS repeatedly use items like:
  Front Fog Lights installed
  Turn Lights via Fog Lights
  Cold Diagnosis Front Fog Lights active
  Cold Diagnosis Rear Fog Lights active
  Front Fog Light Dimming

These match the general cornering-light / fog-light themes we already suspected,
but they do not prove the exact byte/bit positions for the 6R0 BCM.
```

Practical implication for the next attempt:

```text
VCDS is useful as a decoder/reference once we have the BCM long-coding payload
or if we can connect with a real VCDS interface later.
It does not remove the current blocker: we still need the correct TP2.0
post-session read sequence to get the coding out of the BCM.
```

### Working BCM Long Coding Reference - 2026-04-24

The owner later supplied a known-good BCM coding from a time when the cornering
lights were working again:

```text
Part #: 6R0937087K
Component: BCM PQ25 H+4
Software version: 0254
Long coding:
3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

That coding is 30 bytes long. The current PQ25 focus bytes are:

```text
byte 12 = 6C
byte 13 = 68
byte 21 = A6
byte 22 = 00
```

Higher-confidence bits from that coding:

```text
byte 12 bit 6 = set   (base fog-light cornering function)
byte 21 bit 2 = set   (turn-signal-triggered cornering assist)
```

Medium-confidence bits from that coding:

```text
byte 13 bit 6 = set   (CH/LH fog-vs-low-beam selector, but docs and Carista UI disagree)
byte 13 bits 0,1,3    (parking-light behavior group)
byte 21 bit 7 = set   (fog-related capability/install bit, exact label uncertain)
byte 22 bit 5 = clear (probable ADL-related bit)
```

This is stronger evidence than the earlier simulator sample. The current best
offline target area for cornering-light analysis is:

```text
bytes 12, 13, 21, and 22
```

Related offline helper files created from this finding:

```text
obd-on-pc/lcode/pq25_6r0_937_08x_cornering_candidates.xpl
obd-on-pc/lcode/6R0937087K_cornering_enabled_longcoding.txt
obd-on-pc/decode_pq25_longcoding.py
CaristaReproduction/
obd-on-pc/compose_carista_3b9a_tuple.py
obd-on-pc/write_carista_3b9a_tuple.py
docs/obd-on-pc/pq25_longcoding_change_plan.md
docs/obd-on-pc/pq25_bcm_6R0937087K_longcoding_report.md
```

The latest `vw_tp20_readonly_probe.py` update now:

```text
- adds Carista-derived read profiles: carista_kwp, carista_uds, carista_all, legacy
- adds 1A9F to carista_kwp after disassembling Carista's GetVagCanEcuListCommand
- defaults to the proven minimal TP2.0 channel parameter request `A00F8AFF32FF`
- keeps the broader old retry set available with `--parameter-profile legacy`
- keeps Carista's exact TP2.0 channel parameter setup `A00194FF82FF` available with `--parameter-profile carista`
- adds `--skip-channel-parameters` for an isolated open-channel/session test
- adds a counter_sweep mode for outgoing TP2.0 read sequence experiments
- adds a pre_read_sweep mode to vary session counter, pre-read control frames, delay, and first read counter
- closes TP2.0 with the Carista-style one-byte A8 disconnect, not the old A80 typo
- keeps every collection attempt isolated with ATZ and a fresh TP2.0 channel
- only auto-ACKs incomplete multi-frame read replies
- classifies `A8` ECU replies as `disconnect` in summaries instead of vague raw frames
- labels Carista-derived requests and TP2.0 control frames in logs/JSON summaries
- adds direct_read mode for the successful TP2.0 direct `220600` read path
- removed the older duplicated `carista_collect` mode; use `run_next_carista_validation.ps1` for the focused field run
- still blocks 27..., 2E..., 31..., and 3B... in scripted mode
```

`decode_pq25_longcoding.py` now turns a raw coding string or direct-read JSON
summary into a settings report. It compares the current coding against the
known-good cornering-enabled reference, prints the known candidate bits, derives
the changed 6-byte Carista value chunks for the cornering fix, and includes a
full byte/bit table with unknown bits explicitly marked.

Additional Carista native-library research is written here:

```text
../carista_apk_analysis/carista_tp20_research_update.md
../carista_apk_analysis/carista_reverse_engineering_status.md
../carista_apk_analysis/carista_pq25_cornering_static_map.md
../carista_apk_analysis/carista_supported_settings_map.md
../carista_apk_analysis/carista_write_tuple_recovery_report.md
```

Important new interpretation:

```text
300A8 is a TP2.0 channel-disconnect frame, not a normal empty read.
Carista ignores A3 keep-alives.
Carista ACKs ECU data sequence 0 with B1.
```

Carista's channel parameter setup from `libCarista.so`:

```text
A00194FF82FF
```

Important live-test correction:

```text
The 2026-04-16 evening mini-test opened the TP2.0 channel on COM10 but did not
get a session response after trying Carista's A00194FF82FF parameter setup first.
Earlier successful runs used A00F8AFF32FF first and received 300A10F8AFF4FFF.
So the script now defaults back to the proven single-request A00F8AFF32FF path.
```

### Carista Comparison - 2026-04-24

The latest offline Carista review and live TP2.0 probes now line up on the
high-level path:

```text
- unit 09 on this PQ25 car is still best treated as TP2.0 unit 20
- 1089 is still the only repeatable positive diagnostic session in the current probe
- 1A9B and 1A9A are still the most credible first post-session reads because Carista has native builders for both
- 300A8 is correctly treated as ECU channel disconnect, not ordinary no-data
```

What the newer isolated runs ruled out:

```text
- skip-channel-parameters is not the fix
- Carista-exact A00194FF82FF is not the fix on this car
- the legacy parameter retry set is not the fix
- first-read counters 0, 1, 2, and 3 all still disconnect on the minimal path
- switching from 1A9B to 1A9A does not change the first-read disconnect behavior
- removing the 100 ms wait does not change the first-read disconnect behavior
- capture-oriented logging did not reveal any buffered UART frames being lost before the first read
```

The current highest-confidence live baseline is now:

```text
1. open TP2.0 channel on unit 20
2. send A00F8AFF32FF
3. receive 300A10F8AFF4FFF
4. send 1089 as TP2.0 counter 0
5. receive 5089
6. send the first post-session read as TP2.0 counter 1
7. receive immediate 300A8 for both 1A9B and 1A9A
```

Working interpretation:

```text
The remaining mismatch with Carista is probably not the adapter, unit address,
or high-level read identifier anymore.

The most likely missing behavior is inside the communicator choreography around
the first post-session request: a control-handling detail, receive-state rule,
or request ordering nuance that our simplified probe still does not mirror.
```

Carista's read/coding command builders found so far:

```text
1A9B  ECU/component info
1A9F  ECU list/info command
1A9A  long coding command
```

Carista's long-coding write clue found so far:

```text
VagCanLongCodingSetting and writeVagCanCodingValue exist in libCarista.so.
The native string set contains literal 3B9A.
Latest disassembly shows 3B9A is a structured Carista coding write builder,
not 3B9A + the complete long-coding bytes.
```

The prepared writer keeps the obsolete full-coding `3B9A` shape behind an
explicit override only. The strongest Carista-shaped model is now:

```text
3B9A + 6-byte value + 4-byte coding raw address + coding-type-dependent tail
```

The direct full-coding `2E0600 + 30-byte coding` path was parsed by the BCM but
rejected with `7F2E22`, so it remains useful evidence, not a solved write path.

Latest offline Carista setting-label mapping, with no phone trace available:

```text
car_setting_cornering_lights_via_fogs
car_setting_cornering_lights_via_fogs_experimental
car_setting_use_cornering_lights
  -> byte 12 bit 6, base fog-light cornering function

car_setting_cornerig_lights_with_turn_signal
car_setting_cornering_lights_with_turn_signals
  -> byte 21 bit 2, turn-signal-triggered cornering assist
```

The native resource strings are present, but no direct native xrefs from those
keys into `VagCanSettings::getSettings()` were found. This is a practical
label-to-bit map for this BCM, not the exact Carista `3B9A` write tuple.

The broader offline Carista settings map was regenerated from Android resources
and `libCarista.so`:

```text
../carista_apk_analysis/build_carista_supported_settings_map.py
../carista_apk_analysis/carista_supported_settings_map.md
../carista_apk_analysis/carista_supported_settings_map.csv
../carista_apk_analysis/carista_supported_settings_map.json
```

That map contains `3669` app-visible `car_setting_*` labels, `3619` matching
native strings, and marks only the two cornering chunks as pending write
targets:

```text
byte 12 bit 6 target chunk: 6C680ED000C8
byte 21 bit 2 target chunk: 412F60A60000
```

Current full settings/write-state report:

```text
pq25_current_settings_carista_report.md
```

Shared Python reproduction of the recovered Carista native helpers:

```text
CaristaReproduction/
```

It contains the recovered names used by the next in-car validation flow:

```text
GetVagCanEcuInfoCommand_getRequest      -> 1A9B
ReadVagCanLongCodingCommand_getRequest  -> 1A9A
GetVagCanEcuInfoCommand_processEcuInfo  -> positive 5A9B parser
WriteVagCodingCommand_getRequest        -> 3B9A tuple serializer
```

Offline composer for a future proven Carista-shaped tuple:

```text
compose_carista_3b9a_tuple.py
```

The composer can now recreate the two candidate cornering value chunks directly
from a live long-coding read, without hand-copying the 6-byte chunk:

```powershell
python .\compose_carista_3b9a_tuple.py --coding <current-longcoding> --cornering-fix base-fog
python .\compose_carista_3b9a_tuple.py --coding <current-longcoding> --cornering-fix turn-signal
```

It still refuses to print a complete `3B9A` request unless real recovered
`rawAddress4` and `codingType` values are supplied; placeholder raw-address bytes
must not be used for an in-car write.

The next in-car write-readiness wrapper is:

```text
run_next_cornering_write_prep.ps1
```

It performs the fresh `220600` read, regenerates the settings report, and writes
dry-run plans for both cornering tuples. With recovered tuple metadata supplied,
it also prints the complete structured `3B9A` request and TP2.0 frame plan, but
it still does not execute writes.

The guarded sender for a reviewed recovered tuple is:

```text
write_carista_3b9a_tuple.py
```

It defaults to dry-run. Execution requires an exact `--confirm-request` match and
`--i-understand-this-writes-bcm-coding`.

The next adapter-only metadata validation wrapper is:

```text
run_next_carista_validation.ps1
```

It replaces the older tuple-proof sweep wrapper. The default path is deliberately
short: fresh `220600`, direct `1A9B`/`1A9A` with the known-good minimal parameter
profile, direct `1A9B`/`1A9A` with Carista's decompiled parameter profile, then
automatic `5A9B` parsing through `CaristaReproduction/`.

The same wrapper also runs:

```powershell
python ..\CaristaReproduction --validate-workflow ...
```

That validates the current coding load, PQ25 supported-setting mapping, ECU-info
metadata gate, and final tuple construction gate. The JSON gate report is written
to `docs/obd-on-pc/logs/pq25_carista_repro_workflow.json`.

Carista's adaptation path appears to use `31B8`, `31BA`, `31B9`, and `32B8` routine/adaptation commands. Those remain blocked in scripted mode.

Older external PQ25/Polo 6R coding references pointed to these long-coding locations for cornering lights:

```text
Byte 12 bit 6 = Turn/Cornering Lights installed/active
Byte 21 bit 2 = Cornering/Turn Lights via turn signal active
Byte 21 bit 7 = Front Fog Lights with turn/cornering lights installed
Byte 19 bit 5 = Lamp diagnostics for fog/cornering/turn lights active (older, lower-confidence reference)
```

Latest live direct-read result after the write experiments:

```text
direct TP2.0 220600 read works and returns the current 30-byte BCM coding
current coding   = 3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000
known-good coding = 3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
only differences  = byte 12 bit 6 and byte 21 bit 2 are currently clear
bytes 13 and 22 already match the known-good reference
```

So the next in-car read target is no longer broad discovery. It is a short
baseline `220600` capture plus focused Carista `1A9B`/`1A9A` validation through
`run_next_carista_validation.ps1`.

Most useful TP2.0 logs:

```text
logs/vw_tp20_unit09_Carista_COM10_attempt4.txt
logs/vw_tp20_unit09_Carista_COM10_attempt6.txt
logs/vw_tp20_unit09_Carista_COM10_attempt7.txt
logs/vw_tp20_unit09_Carista_COM10_direct_reads.txt
```

### Pre-Read Sweep Follow-Up - 2026-04-24

The focused `1A9B` pre-read sweeps were completed and narrowed the remaining
live unknowns:

```text
logs/pq25_pre_1A9B_pre_read_sweep_summary.json
logs/pq25_pre_1A9B_sctr_pre_read_sweep_summary.json
```

What they proved:

```text
- session counter 0 is still the only repeatable positive 1089 -> 5089 path
- with session counter 0, 1A9B still ends in TP2.0 disconnect for read counters 0, 1, and 2 at both 0 ms and 50 ms when using no pre-read control frames
- A3 and A3+B1 do not help; some combinations still disconnect, others make 1089 go quiet before the read
- session counters 1 and 2 do not reproduce a clean positive 1089; they only produce no-response or raw-frame session results
```

Updated interpretation:

```text
Keep session counter 0.
Do not repeat the none/A3/A3+B1 or session-counter 1/2 sweeps.
The next untested boundary is B1-first pre-read control ordering: B1 and B1+A3.
```

The B1-first follow-up was then run:

```text
logs/pq25_pre_1A9B_b1_pre_read_sweep_summary.json
```

What that proved:

```text
- B1 is not the missing setup frame for this branch
- when 1089 is positive, sending B1 or B1+A3 causes an immediate 300A8 TP2.0 disconnect before any 1A9B request is sent
- when the minimal parameter request does not answer, the run falls back to default timings and 1089 usually goes quiet again
```

Updated interpretation after the B1-first run:

```text
All tested pre-read control shapes are now exhausted for session counter 0: none, A3, A3+B1, B1, and B1+A3.
Session counters 1 and 2 are also exhausted for this branch.
The next nearby live question is parameter handling, not pre-read sequencing.
```

### Next Car Run

The older live branch plan below is kept as history, but it is no longer the
best first move. The offline-first recommendation is now:

```text
1. inspect the Carista communicator flow around the first post-session read
2. derive one focused sequencing change from that comparison
3. only then do another car run
```

Retained field-run history:

Run these from `obd-on-pc` with the Carista adapter on `COM10`.

Shortest low-typing option for the next branch:

```powershell
.\run_next_carista_validation.ps1 -Port COM10
```

That default run captures a fresh direct `220600` baseline, tries the recovered
Carista `1A9B`/`1A9A` read builders with minimal and Carista-exact parameter
profiles, then writes `docs/obd-on-pc/logs/pq25_carista_validation_report.md`.

Only retest the older `1089` session branch if deliberately collecting a single
negative-control comparison:

```powershell
.\run_next_carista_validation.ps1 -Port COM10 -IncludeSessionComparison
```

First confirm the baseline session behavior:

```powershell
python vw_tp20_readonly_probe.py --mode session_sweep --port COM10 --parameter-profile minimal --run-id pq25_session
```

All nearby pre-read control-order experiments are now exhausted, so the next branch isolates parameter handling instead.

If the channel opens but the minimal parameter read keeps making `1089` go quiet, start with the no-parameter comparison on the least ambitious read:

```powershell
python vw_tp20_readonly_probe.py --mode read_sweep --port COM10 --skip-channel-parameters --session 1089 --ack none --delay-ms 100 --read-commands 1A9B --run-id pq25_skip_params_1A9B
```

Then compare the Carista-exact parameter setup once:

```powershell
python vw_tp20_readonly_probe.py --mode read_sweep --port COM10 --parameter-profile carista --session 1089 --ack none --delay-ms 100 --read-commands 1A9B --run-id pq25_carista_params_1A9B
```

If the minimal parameter request still does not answer reliably but the channel opens, compare the broader legacy retry set once:

```powershell
python vw_tp20_readonly_probe.py --mode read_sweep --port COM10 --parameter-profile legacy --session 1089 --ack none --delay-ms 100 --read-commands 1A9B --run-id pq25_legacy_params_1A9B
```

Only if one of those `1A9B` parameter-handling comparisons gets past the disconnect should `1A9A` be retried with the same parameter choice:

```powershell
python vw_tp20_readonly_probe.py --mode read_sweep --port COM10 --skip-channel-parameters --session 1089 --ack none --delay-ms 100 --read-commands 1A9A --run-id pq25_skip_params_1A9A
```

```powershell
python vw_tp20_readonly_probe.py --mode read_sweep --port COM10 --parameter-profile carista --session 1089 --ack none --delay-ms 100 --read-commands 1A9A --run-id pq25_carista_params_1A9A
```

```powershell
python vw_tp20_readonly_probe.py --mode read_sweep --port COM10 --parameter-profile legacy --session 1089 --ack none --delay-ms 100 --read-commands 1A9A --run-id pq25_legacy_params_1A9A
```

Do not go back to the already-failed pre-read grids unless new evidence says this BCM expects a different TP2.0 control family entirely.

Do not spend more time on the PQ26/MQB `70E` + `22055C/22055D` path unless new evidence says this BCM also supports it. The car owner says this is PQ25, and the live tests support that.

## Original Tooling Notes

Read-only Windows Bluetooth logger for an ELM327-compatible adapter. It sends safe AT setup commands plus UDS reads that were already useful in the Android test:

```text
220600
22F190
```

It does not send write, security access, or routine-control commands.

## Safety

The tooling here is read-only.

Allowed command classes in the UDS logger:

```text
AT...
22....  UDS ReadDataByIdentifier
1003    optional diagnostic-session setup when --vw-session-setup is used
```

Allowed command classes in the TP2.0 unit 09 probe:

```text
AT...
A0/A8/B... TP2.0 channel/control frames
10....     diagnostic session requests
1A....     KWP read by local identifier
22....     UDS ReadDataByIdentifier style reads
```

Do not add these while troubleshooting:

```text
2E...  write data
27...  security access
31...  routine control
3B...  KWP write data by local identifier
```

## Setup

1. Pair Windows with the Bluetooth OBD adapter.
2. Open Device Manager.
3. Look under `Ports (COM & LPT)` or Bluetooth serial services.
4. Note the COM port, for example `COM5` or `COM7`.
5. Install Python dependencies:

```powershell
python -m pip install -r requirements.txt
```

You can list visible serial ports with:

```powershell
python elm_readonly_logger.py --list-ports
```

## Run

For the current PQ25 unit 09 work, use the TP2.0 commands in `Next Car Run` above. The older UDS BCM/cornering-light probe below is retained for reference:

```powershell
python vw_bcm_readonly_probe.py --port COM10 --baud 38400
```

To aim directly at the BCM cornering-light values found from the Car Scanner coding database:

```powershell
python vw_bcm_readonly_probe.py --port COM10 --baud 38400 --headers 70E --cornering --vw-session-setup
python vw_bcm_readonly_probe.py --port COM10 --baud 38400 --headers 70E --commands "22055C,22055D"
```

If non-OBD modules return `NO DATA`, try the Car Scanner-style read setup:

```powershell
python vw_bcm_readonly_probe.py --port COM10 --baud 38400 --vw-session-setup
```

The VAG BCM/body-control candidate from Car Scanner's header mapping is:

```text
Unit 09: request 70E, response 778
```

Cornering/fog-light channel reads from the Car Scanner PQ26 exterior-light database:

```text
22055C  left front fog/cornering light channel
22055D  right front fog/cornering light channel
```

Start with `38400` baud:

```powershell
python elm_readonly_logger.py --port COM5 --baud 38400
```

If that does not work, try:

```powershell
python elm_readonly_logger.py --port COM5 --baud 9600
python elm_readonly_logger.py --port COM5 --baud 115200
```

Logs are written under:

```text
logs\
```

You can choose an explicit output file:

```powershell
python elm_readonly_logger.py --port COM5 --baud 38400 --output logs\polo_raw_read.txt
```

## What The Script Sends

ELM setup:

```text
ATZ
ATE0
ATL0
ATS0
ATH1
ATAL
ATSP6
ATDP
ATRV
```

Known checks:

```text
ATSH7E0
220600

ATSH714
220600
```

BCM/header sweep:

```text
709, 70A, 70B, 710, 711, 712, 713, 715, 716
```

For each header it sends:

```text
ATSH<header>
220600
22F190
```

With `--cornering`, it also sends:

```text
22055C
22055D
```

## Expected Problems

Cheap Bluetooth ELM clones can be inconsistent on Windows. Common fixes:

- Check that the adapter is paired and assigned a COM port.
- Try the outgoing Bluetooth serial COM port if Windows creates more than one.
- Try `38400`, then `9600`, then `115200`.
- Close other apps that might hold the COM port.
- Keep the laptop close to the adapter.
