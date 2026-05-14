# OBD On PC

This folder contains the live PC-side entrypoints for the Polo 6R / PQ25 BCM
work.

Core rule: recovered Carista behavior belongs in `CaristaReproduction/`. Files
here may open COM ports, call package APIs, launch PowerShell wrappers, and
store logs, but they must not grow independent Carista protocol/session or
operation logic.

Current manual procedures live in
`docs/OBD_DIAGNOSTICS/pq25_manual_procedures.md`. Evidence checked against logs
lives in `docs/OBD_DIAGNOSTICS/pq25_evidence_matrix.md`.

## Current State

Latest retained in-car read-only state, captured on 2026-05-08:

```text
220600 -> 6206003AB02BBF08A10000003008006D2B0CD000C0412F60820000200000000000
220601 -> 6206011E
220606 -> 620606001800018000
22F1A5 -> 62F1A50005F3C7E719
```

Derived zero-based byte facts:

```text
byte 12 = 6D: bit 0 set, bit 6 set
byte 21 = 82: bit 7 set, bit 5 clear, bit 2 clear
byte 23 = 00: bit 2 clear
```

The earlier fog/cornering symptom was later traced to a physical switch problem,
not a missing BCM cornering-enable bit. The recovered coding paths remain useful
for future diagnostic or rollback sessions.

## Active Runners

```text
pq25_read_monitor.ps1      PowerShell launcher for read-only polling
pq25_read_monitor.py       read-only TP2.0/KWP/UDS monitor
pq25_write_session.ps1     PowerShell launcher for guarded write sessions
pq25_write_session.py      guarded coding write planner/writer
_tp20_transport.py         shared ELM327/TP2.0 transport
```

The PowerShell launchers choose `.venv\Scripts\python.exe` when present.

Read-only examples:

```powershell
.\obd-on-pc\pq25_read_monitor.ps1 -Profile coding -Cycles 1 -Label current_coding
.\obd-on-pc\pq25_read_monitor.ps1 -Profile all-safe -Cycles 1 -Label bcm_all_safe
.\obd-on-pc\pq25_read_monitor.ps1 -Kwp21Range 10,1F -Cycles 1 -Label kwp21_10_1f
.\obd-on-pc\pq25_read_monitor.ps1 -Did22Range 0550,056F -Cycles 1 -Label did22_0550_056f
.\obd-on-pc\pq25_read_monitor.ps1 -VagAdaptationKind short -VagAdaptationChannel 2F -Cycles 1 -Label short_adapt_2f
```

Write-plan examples:

```powershell
.\obd-on-pc\pq25_write_session.ps1 -Operation restore-expert-backup
.\obd-on-pc\pq25_write_session.ps1 -SetBit byte21-bit2 -ClearBit byte21-bit7
.\obd-on-pc\pq25_write_session.ps1 -ClearBit byte12-bit0
```

Confirmed writes use the same command plus `-Write` and still require typing
literal `YES`:

```powershell
.\obd-on-pc\pq25_write_session.ps1 -Operation restore-expert-backup -Write
```

## Guardrails

The read monitor blocks `27`, `2E`, `31`, and `3B` for arbitrary commands. It
accepts read-service prefixes `18`, `19`, `1A`, `21`, `22`, and exact `24`
reads. The VAG adaptation mode is a specific Carista read sequence, not a broad
routine scan.

The write session always performs a fresh read phase first, derives the target
from the current coding, saves a Carista-shaped write plan, asks for `YES`, then
verifies by re-reading `220600`.

Carista-shaped write sequence:

```text
2EF199 + YYMMDD
2EF198 + workshop-code payload from fresh 22F1A5
2E0600 + full 30-byte coding
fresh 220600 verification
```

## Log Locations

New live-run output defaults to `obd-on-pc/logs/`.

Retained evidence used by documentation is kept under:

```text
docs/OBD_DIAGNOSTICS/session_artifacts/
```

Do not use archived JSON/TXT artifacts as new write seeds unless the matching
current read path and Carista runtime branch are proven again on the car.
