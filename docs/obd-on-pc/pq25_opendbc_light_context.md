# PQ25 openDBC Light Context

Date: 2026-05-01

## Source

Downloaded public openDBC Volkswagen PQ references into `reference/opendbc/`:

- `opendbc__dbc__vw_pq.dbc`
- `opendbc__car__volkswagen__carstate.py`
- `opendbc__safety__modes__volkswagen_pq.h`
- `LICENSE`

The retained DBC is used only as offline reference material for read-only raw
CAN annotation. The live tools still do not transmit non-read diagnostic/write
services.

## Useful Raw CAN Headers

| Header | openDBC message | Why it matters for fog/cornering debug |
|---|---|---|
| `390` | `Gate_Komf_1` | BCM comfort/lamp state: reverse, left/right blinkers, low beam, high beam, front fog, brake light. |
| `392` | `Gate_Komf_2` | BCM companion lamp state: indicator telltales, light sensor, rear fog, AFL switch. |
| `0D0` | `Lenkhilfe_3` | EPS steering angle and driver torque; cornering may be gated on steering angle. |
| `0C2` | `Lenkwinkel_1` | Steering wheel angle/rate cross-check. |
| `1A0` | `Bremse_1` | Vehicle speed and brake-light switch. |
| `288` | `Motor_2` | Engine brake switch context. |
| `320` | `Kombi_1` | Cluster indicator telltales and speed. |
| `470` | `BSG_Kombi` | BCM-to-cluster lamp/telltale state including reverse and turn indicators. |

## New Capture Preset

Use this focused raw-CAN pass when checking whether the BCM sees the physical
inputs needed for cornering logic:

```powershell
cd C:\Users\victo\Downloads\PoloCornering\obd-on-pc
.\run_bcm_light_capture.ps1 -Port COM10 -ReadProfile bcm_light_fast -States "baseline_off,left_turn,right_turn,lowbeam_fog_on,highbeam,reverse" -RawCanSeconds 5 -RawHeaders pq25_light_context -Repeats 2
```

The analyzer will decode known payloads in the state-specific raw CAN report
and will also parse the downloaded VW PQ DBC into a signal-level delta report:

```text
logs/<run_id>_raw_signal_deltas.csv
```

That CSV compares the most common decoded signal value in each state against
`baseline_off`. For example, header `390` rows can show `GK1_Blinker_li`
changing from `0` to `1`, or `GK1_Nebel_ein` changing when the fog switch is
actually seen by the BCM.

The DBC path is optional on the analyzer:

```powershell
python .\analyze_bcm_light_capture.py .\logs\<run_id>_bcm_light_capture.json --dbc-path ..\reference\opendbc\opendbc__dbc__vw_pq.dbc --output-prefix <run_id>
```

Use `--no-dbc` only if you want the older payload-only reports.

## Why This Helps

This lets us separate three questions that were previously blurred together:

1. Does the BCM see the driver inputs, such as turn signal, low beam, fog, high beam, and steering?
2. Do the diagnostic BCM payloads change when those inputs change?
3. If both are true but the lamp still does not behave, is the missing piece likely a coding/adaptation value rather than a switch or steering-state issue?