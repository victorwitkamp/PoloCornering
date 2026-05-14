# PoloCornering

This project captures the Polo/PQ25 lighting investigation, the Carista reverse
engineering work, and the reproducible tools used for in-car OBD diagnostics.

## Documentation Layout

`docs/` has two top-level folders:

| Folder | Purpose |
|---|---|
| `docs/CARISTA_REVERSE/` | Carista reverse-engineering notes, recovered settings, and generated reverse-analysis artifacts. |
| `docs/OBD_DIAGNOSTICS/` | Live-car OBD evidence, manual procedures, diagnostic reports, and retained session artifacts. |

Start with:

| File | Purpose |
|---|---|
| `docs/OBD_DIAGNOSTICS/pq25_manual_procedures.md` | Reproducible manual car procedures for reading, scanning, dry-run write planning, and confirmed writes. |
| `docs/OBD_DIAGNOSTICS/pq25_evidence_matrix.md` | Current findings checked against retained logs and generated Carista evidence. |
| `docs/OBD_DIAGNOSTICS/pq25_live_history.md` | Condensed chronological history of the live Polo/PQ25 sessions. |
| `docs/CARISTA_REVERSE/carista_recovery_summary.md` | Current reverse-engineering status for the Carista reproduction. |
| `docs/CARISTA_REVERSE/pq25_future_diagnostics_roadmap.md` | Prioritized open Carista reverse paths for future PQ25/Polo diagnostics. |
| `docs/CARISTA_REVERSE/generated/diagnostics_plan.json` | Generated Carista-shaped DTC/detail request plan and transport findings. |
| `docs/CARISTA_REVERSE/pq25_carista_setting_catalog.md` | Historical generated setting catalog; use the evidence matrix for current in-car state. |

## Live Tool Boundary

Use these entrypoints for future in-car work:

```powershell
.\obd-on-pc\pq25_read_monitor.ps1
.\obd-on-pc\pq25_write_session.ps1
.\.venv\Scripts\python.exe .\obd-on-pc\scan_vag_uds_headers.py --list-profiles
```

The PowerShell wrappers only choose Python and forward arguments. The Python
entrypoints import request builders, write-plan construction, coding-bit helpers,
diagnostic request profiles, and Carista result handling from
`CaristaReproduction/`.

New live-run output is written by default to `obd-on-pc/logs/`. Curated evidence
that supports the docs belongs under `docs/OBD_DIAGNOSTICS/session_artifacts/`.
