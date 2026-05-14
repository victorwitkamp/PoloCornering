# PQ25 Manual Car Procedures

Date: 2026-05-14

These are the reproducible procedures for the Polo 6R / PQ25 BCM work. Run
commands from the repository root.

All live procedures use `obd-on-pc` entrypoints that call
`CaristaReproduction` for request builders, coding-bit edits, write-plan
construction, Carista result handling, and VAG adaptation request sequences.

## Preflight

Vehicle/controller:

```text
VW Polo 6R / PQ25
Module 09 / BCM / J519
Part: 6R0937087K
TP2.0 unit: 20
Adapter: Carista ELM327 on COM10 at 38400 baud
```

Safety boundary:

```text
Do not send raw 27, 2E, 31, or 3B outside the guarded scripts.
Use dry-run write planning before every write.
Use --write only after the dry run produces the expected target.
```

The current validated in-car coding from 2026-05-08 is:

```text
3AB02BBF08A10000003008006D2B0CD000C0412F60820000200000000000
```

## Read Current State

Current coding only:

```powershell
.\obd-on-pc\pq25_read_monitor.ps1 -Profile coding -Cycles 1 -Label current_coding
```

Identity and workshop-code context:

```powershell
.\obd-on-pc\pq25_read_monitor.ps1 -Profile identity -Cycles 1 -Label bcm_identity
```

Full known-safe BCM snapshot:

```powershell
.\obd-on-pc\pq25_read_monitor.ps1 -Profile all-safe -Cycles 1 -Label bcm_all_safe
```

Carista-shaped BCM DTC status read:

```powershell
.\obd-on-pc\pq25_read_monitor.ps1 -Profile carista-dtc -Cycles 1 -Label bcm_carista_dtc
```

Known retained DTC detail probes:

```powershell
.\obd-on-pc\pq25_read_monitor.ps1 -Profile carista-dtc-detail-known -Cycles 1 -Label bcm_carista_dtc_detail_known
```

The detail-known profile is read-only, but it is still a narrow follow-up tool.
Use it only when you want to reproduce the retained `C40100` detail path; a
future module-aware UDS runner should discover DTCs first and then read detail
records for the DTCs found in that same run.

Carista-shaped module-aware UDS header scan:

```powershell
.\.venv\Scripts\python.exe .\obd-on-pc\scan_vag_uds_headers.py --headers 711,714 --profile carista-dtc --timeout 2.5 --run-id pq25_carista_dtc_headers
```

Known retained DTC detail over UDS headers:

```powershell
.\.venv\Scripts\python.exe .\obd-on-pc\scan_vag_uds_headers.py --headers 714 --profile carista-dtc-detail-known --timeout 2.5 --run-id pq25_carista_dtc_detail_known_714
```

The UDS header scanner now gets its built-in identity and Carista DTC requests
from `CaristaReproduction`. It retries a read-only request once by default after
`7F xx 78` response-pending, which mirrors the recovered Carista behavior of not
treating response-pending as a final failure.

List all read profiles:

```powershell
.\obd-on-pc\pq25_read_monitor.ps1 -ListProfiles
```

## Switch And Fog-State Polling

Use this when changing the light switch or fog switch by hand:

```powershell
.\obd-on-pc\pq25_read_monitor.ps1 -Profile switch -Cycles 8 -Pause 1 -Label fog_switch_toggle
```

The known `switch` profile polls `220601`, `220606`, and `1802FF00`. Earlier
2026-05-08 captures showed no switch-state variation in those payloads, so this
is a regression check, not the strongest live monitor.

## Measuring-Block Search

The only positive live measuring-block family found through this ELM/TP2.0 path
is KWP service `21xx`. Scan it in small chunks.

Capture an off state and an on state for the same range:

```powershell
.\obd-on-pc\pq25_read_monitor.ps1 -Kwp21Range 10,1F -Cycles 1 -Label kwp21_10_1f_off
.\obd-on-pc\pq25_read_monitor.ps1 -Kwp21Range 10,1F -Cycles 1 -Label kwp21_10_1f_on
```

Compare saved captures:

```powershell
.\.venv\Scripts\python.exe .\obd-on-pc\analyze_kwp21_measurements.py .\obd-on-pc\logs\<off>.json .\obd-on-pc\logs\<on>.json
```

The retained `2101` through `210F` off/on captures only changed `2102`, and the
decoded changes were supply-voltage drift. Continue from `10,1F`, then
`20,2F`, and so on.

## Read-Only Discovery

Fog-role candidate DIDs:

```powershell
.\obd-on-pc\pq25_read_monitor.ps1 -Profile fog-role-candidates -Cycles 1 -Label fog_role_candidates
```

Known-DID scaling metadata:

```powershell
.\obd-on-pc\pq25_read_monitor.ps1 -Profile scaling-known-dids -Cycles 1 -Label scaling_known_dids
```

Small DID ranges:

```powershell
.\obd-on-pc\pq25_read_monitor.ps1 -Did22Range 0550,056F -Cycles 1 -Label did22_0550_056f
.\obd-on-pc\pq25_read_monitor.ps1 -Did22Range 0600,060F -Cycles 1 -Label did22_0600_060f
.\obd-on-pc\pq25_read_monitor.ps1 -Did22Range 0D00,0D1F -Cycles 1 -Label did22_0d00_0d1f
```

KWP service `1A` identity/config ranges:

```powershell
.\obd-on-pc\pq25_read_monitor.ps1 -Service1ARange 80,9F -Cycles 1 -Label service1a_80_9f
```

Positive reads are read seeds only. They are not write authorization until a
matching recovered Carista Setting object, current payload length, and requested
choice bytes are proven.

## Offline Response Decoding

Decode retained or newly captured diagnostic payloads without touching the car:

```powershell
.\.venv\Scripts\python.exe .\obd-on-pc\decode_diagnostic_payload.py 58010C9820 590299C4010008 5906C4010008 62F1873652303933373038374B20 62F1A50005F3C7E719
```

Extract and decode known response payloads from a saved log:

```powershell
.\.venv\Scripts\python.exe .\obd-on-pc\decode_diagnostic_payload.py --from-file .\docs\OBD_DIAGNOSTICS\session_artifacts\drive_20260429_1055_dtc_detail_711_714_uds_header_scan.txt
```

The decoder now identifies KWP `58` DTC records, UDS `59 02` DTC status,
UDS `59 04`/`59 06` DTC detail records, UDS `62` DID values, KWP `5A` local
identifier values, and `7F` negative responses such as `7F1978`
`responsePending`.

## VAG Adaptation Reads

Use only the exact Carista VAG CAN adaptation read routine implemented by
`CaristaReproduction.Commands.VagCanAdaptationCommands`.

Short adaptation channel example:

```powershell
.\obd-on-pc\pq25_read_monitor.ps1 -VagAdaptationKind short -VagAdaptationChannel 2F -Cycles 1 -Label short_adapt_2f
```

Long adaptation channel example:

```powershell
.\obd-on-pc\pq25_read_monitor.ps1 -VagAdaptationKind long -VagAdaptationChannel 2F -Cycles 1 -Label long_adapt_2f
```

The routine sequence is:

```text
31B8 + basic id
31BA + basic id
31B9 + basic id + channel
31BA + basic id
32B8 + basic id
```

Do not broad-scan service `31`, `32`, or `33`.

## Dry-Run Write Plans

Dry runs connect to the car, read fresh `220600` and `22F1A5`, derive the target
from current coding, and save a Carista-shaped write plan. They do not send
`2E0600` unless `-Write` is also provided.

Restore full expert backup:

```powershell
.\obd-on-pc\pq25_write_session.ps1 -Operation restore-expert-backup
```

Restore expert-backup family with turn-signal fog trigger cleared:

```powershell
.\obd-on-pc\pq25_write_session.ps1 -Operation restore-expert-backup-no-turn-signal-fogs
```

One-bit or combined bit target:

```powershell
.\obd-on-pc\pq25_write_session.ps1 -SetBit byte21-bit2
.\obd-on-pc\pq25_write_session.ps1 -ClearBit byte12-bit0 -ClearBit byte21-bit7
.\obd-on-pc\pq25_write_session.ps1 -SetBit byte21-bit2 -ClearBit byte12-bit0
```

Exact 30-byte coding target:

```powershell
.\obd-on-pc\pq25_write_session.ps1 -ToCoding "3AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000"
```

## Confirmed Writes

Repeat the same command with `-Write`. The runner still asks for literal `YES`
before sending the write sequence.

```powershell
.\obd-on-pc\pq25_write_session.ps1 -Operation restore-expert-backup -Write
.\obd-on-pc\pq25_write_session.ps1 -SetBit byte21-bit2 -Write
.\obd-on-pc\pq25_write_session.ps1 -ClearBit byte12-bit0 -ClearBit byte21-bit7 -Write
```

The write sequence is always:

```text
2EF199 + YYMMDD
2EF198 + workshop-code payload from fresh 22F1A5
2E0600 + full 30-byte coding
fresh 220600 verification
```

After any write, verify independently:

```powershell
.\obd-on-pc\pq25_read_monitor.ps1 -Profile coding -Cycles 1 -Label post_write_coding
```

Supported bit names:

| Bit name | Location | Meaning |
|---|---|---|
| `byte12-bit0` | byte 12 bit 0 | Nordic/Standlicht parking behavior |
| `byte12-bit6` | byte 12 bit 6 | Base cornering via fogs |
| `byte21-bit2` | byte 21 bit 2 | Turn-signal cornering assist |
| `byte21-bit5` | byte 21 bit 5 | Turn off fogs with high beam |
| `byte21-bit7` | byte 21 bit 7 | Cornering/fog experimental |
| `byte23-bit2` / `drl-via-fogs` | byte 23 bit 2 | DRL via fogs |

Supported operation names:

| Operation | Target |
|---|---|
| `restore-expert-backup` | `3AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000` |
| `restore-expert-backup-no-turn-signal-fogs` | `3AB02BBF08A10000003008006D2B0CD000C0412F60820000200000000000` |
| `clear-byte12-bit0` | Fresh current coding with byte 12 bit 0 cleared |
| `drl-via-fogs` | Fresh current coding with byte 23 bit 2 set |

## Offline Carista Checks

Render current settings from a coding value:

```powershell
.\.venv\Scripts\python.exe -m CaristaReproduction --current-settings --coding 3AB02BBF08A10000003008006D2B0CD000C0412F60820000200000000000
```

Render an offline write plan without connecting to the car:

```powershell
.\.venv\Scripts\python.exe -m CaristaReproduction --uds-write-plan --coding 3AB02BBF08A10000003008006D2B0CD000C0412F60820000200000000000 --target-coding 3AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000 --workshop-code 0005F3C7E719
```

Validate the reproduction package:

```powershell
.\.venv\Scripts\python.exe carista_apk_analysis\validate_carista_reproduction.py
```

Render the recovered Carista diagnostics plan:

```powershell
.\.venv\Scripts\python.exe -m CaristaReproduction --diagnostics-plan --no-full-log
```
