# OBD On PC

This folder contains PC-side entrypoints for the Polo 6R / PQ25 BCM work.

Core rule: recovered Carista behavior belongs in `CaristaReproduction/`. Files
here may open COM ports, call package APIs, launch PowerShell wrappers, and
store logs, but they must not grow independent Carista protocol/session or
operation logic.

## Active Car Session

Date: 2026-05-07

Vehicle/controller:

```text
VW Polo 6R / PQ25
Module 09 / BCM / J519
Part: 6R0937087K
TP2.0 unit address: 20
Adapter: Carista on COM10 at 38400 baud
```

Latest 2026-05-08 in-car read-only state:

```text
220600 -> 6206003AB02BBF08A10000003008006D2B0CD000C0412F60820000200000000000
220601 -> 6206011E
220606 -> 620606001800018000
22F1A5 -> 62F1A50005F3C7E719
```

The DRL-via-fogs write was tested in the car on 2026-05-07 and did not fix the
visible behavior. The car is now on the expert-backup family with the
turn-signal fog trigger cleared (`byte 21 = 82`). This is a diagnostic state:
if both fogs are still steady-on in the plain low-beam position, the symptom is
not caused by byte 21 bit 2 or byte 23 bit 2.

Expert backup target:

```text
3AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000
```

This is the backup supplied by the previous coder and previously restored and
verified by `220600` readback. It is the correct coding to restore the car to
that expert-backed baseline. It is not proof that the fog/cornering symptom is
fixed.

The failed hypothesis was Carista's recovered `car_setting_drl_via_fogs` branch:

```text
DID 0600 byte 23 mask 0x04
whitelist CENTRAL_ELEC_6R_5C_7E_7H
interpretation YES_NO
```

It is now behavior-disproven for this symptom.

## Run Order At The Car

Read-only first:

```powershell
cd C:\Users\victo\Downloads\PoloCornering
.\obd-on-pc\run_restore_expert_backup_session.ps1
```

For switch/fog-state polling, use the active read-only monitor. Passive `ATMA`
monitoring has not produced frames with this ELM/gateway path, but repeated
TP2.0 reads work:

```powershell
.\obd-on-pc\run_bcm_active_monitor.ps1 -Label fog_switch_toggle
```

Default monitor profile `switch` polls `220601`, `220606`, and `1802FF00`. The
wrapper blocks `27`, `2E`, `31`, and `3B`, and the Python monitor only accepts
read-service prefixes `18`, `19`, `1A`, `21`, `22`, and `24`.

Available active monitor profiles:

```powershell
.\obd-on-pc\run_bcm_active_monitor.ps1 -ListProfiles
.\obd-on-pc\run_bcm_active_monitor.ps1 -Profile switch -Cycles 8 -Label fog_switch_toggle
.\obd-on-pc\run_bcm_active_monitor.ps1 -Profile identity -Cycles 1 -Label bcm_identity
.\obd-on-pc\run_bcm_active_monitor.ps1 -Profile carista-core -Cycles 1 -Label carista_core_reads
.\obd-on-pc\run_bcm_active_monitor.ps1 -Profile all-safe -Cycles 1 -Label bcm_all_safe_reads
.\obd-on-pc\run_bcm_active_monitor.ps1 -Profile fog-role-candidates -Cycles 1 -Label fog_role_candidates
.\obd-on-pc\run_bcm_active_monitor.ps1 -Profile scaling-known-dids -Cycles 1 -Label scaling_known_dids
.\obd-on-pc\run_bcm_active_monitor.ps1 -Profile kwp21-early -Cycles 2 -Label kwp21_switch_compare
.\obd-on-pc\run_bcm_active_monitor.ps1 -Kwp21Range 10,1F -Cycles 1 -Label kwp21_10_1f
.\obd-on-pc\run_bcm_active_monitor.ps1 -Did22Range 0550,056F -Cycles 1 -Label did22_0550_056f
.\obd-on-pc\run_bcm_active_monitor.ps1 -Service1ARange 80,9F -Cycles 1 -Label service1a_80_9f
```

If VCDS/ODIS is available, module 09 UDS Measuring Values are the better live
monitor for switch-state proof. Search for terms such as `fog`, `front fog`,
`light switch`, `terminal 58`, `turn signal`, `cornering`, `steering angle`,
and `G85`; those named values may expose a switch/input state that the known
Carista/ELM reads do not.

The ELM path now has one measuring-block style profile: `kwp21-early` polls
`2101` through `210F`. Hold one physical switch state for a full cycle, then
change state for the next cycle; each cycle is slow because the ELM runner opens
a fresh TP2.0 channel per read.

Compare saved KWP service-21 snapshots offline with:

```powershell
.\.venv\Scripts\python.exe .\obd-on-pc\analyze_kwp21_measurements.py .\obd-on-pc\logs\<off>.json .\obd-on-pc\logs\<on>.json
```

The 2026-05-08 `2101` through `210F` off/on captures only changed `2102`, and
the changed fields decode as supply-voltage values. Continue the search in
16-local-identifier chunks with `-Kwp21Range`; start at `10,1F`.

For read-only DID discovery, use `-Did22Range` in small chunks. Useful next
chunks are the fog-role area (`0550,056F`), the current coding companions
(`0600,060F`), and the CH/LH/fog-adjacent area (`0D00,0D1F`). Treat positive
payloads as read seeds only; a write still needs the selected recovered Setting
object, current payload length, requested-choice bytes, and a fresh readback.

For KWP `1A` local-ID discovery, use `-Service1ARange` in small chunks. The
highest-value first range is `80,9F`, because Carista's own core probes are
`1A9A`, `1A9B`, and `1A9F`. Earlier direct attempts rejected those three in the
current session, so this is a low-expectation identity/config sweep rather than
a likely switch-state monitor.

Service `24` is allowed only as exact commands or the small `scaling-known-dids`
profile. It is a read-only scaling-data request for known DIDs, not a live-value
or write path.

Do not use `1089` as a normal monitor setup. It returns `5089`, but this BCM
then closes the TP2.0 channel, and it does not make `1A9A`, `1A9B`, or `1A9F`
usable after reconnect. The positive monitor family found so far is `21xx`,
and it answered without `1089`.

Continue only if the read-only phase shows the live coding does not already
match the expert backup target:

```text
3AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000
```

Then run the gated write:

```powershell
.\obd-on-pc\run_restore_expert_backup_session.ps1 -Write
```

If the goal is to restore the expert backup but also turn off the recovered
turn-signal-triggered fog behavior, use this target instead. It keeps the expert
backup coding and clears only DID `0600` byte 21 bit 2:

```powershell
.\obd-on-pc\run_restore_expert_backup_session.ps1 -DisableTurnSignalFogs
.\obd-on-pc\run_restore_expert_backup_session.ps1 -DisableTurnSignalFogs -Write
```

That target is:

```text
3AB02BBF08A10000003008006D2B0CD000C0412F60820000200000000000
```

For controlled hypothesis tests, the wrapper exposes set and clear switches for
all known relevant DID `0600` bits. These operations read fresh `220600`, change
only the selected known bits, preserve every other current byte, then ask for
literal `YES` before any `2E` write:

| Bit | Set flag | Clear flag |
|---|---|---|
| byte 12 bit 0 | `-SetByte12Bit0` | `-ClearByte12Bit0` |
| byte 12 bit 6 | `-SetByte12Bit6` | `-ClearByte12Bit6` |
| byte 21 bit 2 | `-SetByte21Bit2` | `-ClearByte21Bit2` |
| byte 21 bit 5 | `-SetByte21Bit5` | `-ClearByte21Bit5` |
| byte 21 bit 7 | `-SetByte21Bit7` | `-ClearByte21Bit7` |
| byte 23 bit 2 | `-SetByte23Bit2` / `-SetDrlViaFogs` | `-ClearByte23Bit2` / `-ClearDrlViaFogs` |

```powershell
.\obd-on-pc\run_restore_expert_backup_session.ps1 -ClearByte12Bit0
.\obd-on-pc\run_restore_expert_backup_session.ps1 -ClearByte12Bit0 -Write
.\obd-on-pc\run_restore_expert_backup_session.ps1 -SetByte21Bit2
.\obd-on-pc\run_restore_expert_backup_session.ps1 -ClearDrlViaFogs
.\obd-on-pc\run_restore_expert_backup_session.ps1 -SetByte21Bit2 -ClearByte21Bit7 -Write
```

The runner rejects contradictory set/clear requests for the same physical bit.
For example, do not combine `-SetByte23Bit2` with `-ClearDrlViaFogs`.

From the latest 2026-05-08 diagnostic state, useful one-bit targets are:

```text
clear byte 12 bit 0: 3AB02BBF08A10000003008006C2B0CD000C0412F60820000200000000000
set byte 21 bit 2:   3AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000
set byte 21 bit 5:   3AB02BBF08A10000003008006D2B0CD000C0412F60A20000200000000000
clear byte 21 bit 7: 3AB02BBF08A10000003008006D2B0CD000C0412F60020000200000000000
set byte 23 bit 2:   3AB02BBF08A10000003008006D2B0CD000C0412F60820004200000000000
```

Bits that are already in the requested state become no-ops after the fresh read.
For example, the latest diagnostic state already has byte 23 bit 2 clear, so
`-ClearDrlViaFogs` is a no-op unless a later read shows byte 23 changed back to
`04`.

Byte 21 bit 7 maps to Carista's
`car_setting_cornering_lights_via_fogs_experimental`: DID `0600`, byte `0x15`
mask `0x80`, YES/NO, guarded by the same `CENTRAL_ELEC_6R_5C_7E_7H` whitelist as
the base 6R/PQ25 cornering-fogs setting. It appears to be an alternate
experimental enable for cornering lights using fogs, not a per-side output role
or wiring assignment. It has been set during failed live tests, so clearing it
is a controlled negative/rollback test rather than a known repair.

The write wrapper still asks for literal `YES` before any `2E` write. After a
successful restore, key-cycle the car and verify ordinary lighting behavior.

## Active Runner Boundary

Current temporary live runner files:

```text
run_bcm_coding_session.py
run_bcm_active_monitor.py
run_bcm_active_monitor.ps1
run_restore_expert_backup_session.ps1
```

They are intentionally temporary and thin:

- serial/ELM327 I/O stays here;
- TP2.0 packet generation, ACKs, read response extraction, request builders,
  write-plan building, and coding edits come from `CaristaReproduction`;
- remove these runner files after the restore session unless an immediate retry is
  needed.

Read-only guardrail:

```text
Do not send 27, 2E, 31, or 3B unless explicitly doing a confirmed write/routine operation.
```

## Carista-Shaped Write Evidence

Recovered and live-proven sequence:

```text
2EF199 + YYMMDD
22F1A5 inline workshop-code read
2EF198 + workshop-code payload
2E0600 + full 30-byte coding
fresh 220600 verification
```

Important TP2.0 details:

```text
open request: 20C00010000301
send header: 338
listen header: 300
Carista exact channel params: A00194FF82FF
Polo fallback channel params: A00F8AFF32FF
ACK ECU response seq N with B((N + 1) & 0x0F)
advance outgoing counter per generated TP2.0 data frame
use ATST04 for non-final write frames
use ATST32 for live response collection on this ELM clone
use at least 130 ms between outgoing TP2.0 data frames
```

`7F2E31` on `F199` is nonfatal Carista metadata behavior. The `F198` workshop
pre-write and final `0600` write are treated more strictly by the runner; the
final coding must be verified by a fresh `220600` read.

## Historical Conclusions

The DID `0600` target that set byte 12 bit 6 and byte 21 bit 2 is already
proven, persisted, and behavior-disproven as a standalone fix. Do not repeat it
as a blind fix.

Known context:

```text
byte 12 bit 0: Scandinavian/Nordic parking/Standlicht behavior, set in latest 2026-05-08 coding; guarded set/clear operation prepared
byte 12 bit 6: base fog-light cornering family, set; guarded set/clear operation prepared
byte 21 bit 2: turn-signal-triggered cornering assist, clear in 2026-05-08 diagnostic coding; guarded set/clear operation prepared
byte 21 bit 5: turn off fogs with high beam, clear in 2026-05-08 diagnostic coding; guarded set/clear operation prepared
byte 21 bit 7: cornering/fog experimental capability, set; guarded set/clear operation prepared
byte 23 bit 2: DRL via fogs, clear after rollback; tested and behavior-disproven for this symptom; guarded set/clear operation prepared
```

One-bulb H8 fog assemblies are not the same as R-Line/GTI H8 + P21W fog/DRL
assemblies. On the one-bulb setup, a front-fog, DRL, parking, or static-
cornering role can occupy the same H8 output, so a per-side cornering request
may have no visible effect while that bulb is already commanded on as a paired
role. This supports restoring the expert backup before doing more diagnosis.

Rejected direct reads that should not be repeated by default:

```text
22055C, 22055D, 22110E, 22056D, 220550, 220551, 220D01, 220A58, 220A57
```

`220601 -> 6206011E` remains a strong stored-role clue. Play 9.8.3 x86 also
contains a readable `ECU VAGCAN20 220601: 6206011E` simulator/sample-response
row, but no recovered 6R/PQ25 Carista write path ties DID `0601` to a writable
setting. It is not a write seed.

## Unresolved Focus

After the expert-backup restore, the remaining issue should be treated as role
ownership, not another cornering-enable bit.

Priority 1 is proving whether the fogs are being requested as ordinary paired
front fogs. Check whether the front fog indicator is lit while the switch is in
the plain low-beam/headlight position, and whether pulling or pushing the fog
switch changes that state independently. If the indicator or fog state behaves
as if the switch is already pulled, focus on the light-switch input path,
especially the front-fog request input around `T73a/7`.

Priority 2 is proving the lamp output wiring path. For this one-bulb H8 setup,
software can only create per-side cornering if the lamps are actually on
separate BCM-controlled outputs. The unresolved physical distinction is ordinary
front-fog wiring versus BCM/static-cornering wiring: verify separate left/right
paths to `T73b/9` and `T73b/10`, supply on `T73b/11`, and the fuse path called
out in the wiring references.

Priority 3 is the software clue `220601 -> 6206011E`. It overlaps Carista's
recovered `car_setting_enabled_coming_home_or_leaving_home` enum in per-side
fog-role tables, but the x86 recovery has no decoded `0601` Setting constructor
for `6R0937087K`. Treat it as a role clue to explain, not as `2E0601` payload
material.

Priority 4 is offline recovery of the real VAG/PQ25 fog-role path, if one
exists. The direct visible labels `front_fogs_with_low_beams`, `fog_when`,
`left_fog_light_as`, and `right_fog_light_as` resolve to non-VAG/Ford paths in
the recovered code. The current target is an alternate VAG key, availability
sub-object, or `ReadValuesOperation` value path that exposes equivalent role
behavior on this BCM.

Do not build a write from `0601`, `055C`, `055D`, `0D04`, `0D1D`, or `056C`
until a positive current read path or recovered Carista runtime branch supplies
the current payload length, selected Setting object, and requested-choice bytes.

## Durable Tools To Keep

```text
scan_vag_uds_headers.py          generic read-only UDS scanner
analyze_bcm_light_capture.py     offline capture analyzer
decode_diagnostic_payload.py     offline KWP/UDS DTC/status payload decoder
decode_pq25_longcoding.py        long-coding decoder helper
pq25_can_reference.py            local raw-CAN annotation reference
dbc_signal_decoder.py            DBC signal decoding helper
```

The DTC/status decoder is offline only and is useful for saved `1802FF00`,
`1902FF`, and negative-response payloads already present in the logs:

```powershell
python .\obd-on-pc\decode_diagnostic_payload.py 58010C9820 590299C4010008 7F1911
python .\obd-on-pc\decode_diagnostic_payload.py --from-file .\obd-on-pc\logs\bcm_fault_status_20260502_1905_direct_read_summary.json
```

External diagnostic projects are useful as design references, not drop-in
replacements for the Carista TP2.0 reproduction. The practical ideas to borrow
are strict response validation, DTC/status decoding before new probing,
command caution categories, structured ECU profiles, and eventually a separated
transport layer for non-ELM CAN adapters.

For broader read-only UDS discovery:

```powershell
python .\obd-on-pc\scan_vag_uds_headers.py --port COM10 --baud 38400 --run-id uds_scan
```

For recovered Carista offline views:

```powershell
python -m CaristaReproduction --read-values-plan
python -m CaristaReproduction --current-settings --coding <30-byte-coding>
```

## Consolidated Docs

Current summaries:

```text
../docs/obd-on-pc/pq25_live_history.md
../docs/carista_apk_analysis/carista_recovery_summary.md
../CaristaReproduction/README.md
```

Retained detail/reference docs:

```text
../docs/obd-on-pc/polo_6r_vehicle_info_for_coding_expert.md
../docs/obd-on-pc/vcds_pq25_reference_notes.md
../docs/obd-on-pc/pq25_opendbc_light_context.md
../docs/obd-on-pc/drive_20260429_diagnostic_collection_report.md
../docs/carista_apk_analysis/pq25_carista_setting_catalog.md
```
