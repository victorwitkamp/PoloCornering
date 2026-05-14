# PQ25 Evidence Matrix

Date: 2026-05-14

This matrix lists the current working claims and the repo evidence that supports
them. Claims marked "human observation" are useful context but are not directly
validated by diagnostic logs.

## Current In-Car State

| Claim | Evidence | Status |
|---|---|---|
| Latest retained 2026-05-08 coding is `3AB02BBF08A10000003008006D2B0CD000C0412F60820000200000000000`. | `docs/OBD_DIAGNOSTICS/session_artifacts/diagnose_still_on_20260508_080202.json`; `docs/OBD_DIAGNOSTICS/session_artifacts/bcm_all_safe_reads_20260508_083940.json` | Log-validated |
| `220601 -> 6206011E`. | Same 2026-05-08 files; earlier repeated captures in `chlh_220601_*` and `readonly_*` artifacts | Log-validated |
| `220606 -> 620606001800018000`. | Same 2026-05-08 files and earlier direct reads | Log-validated |
| Workshop-code payload is `0005F3C7E719`. | `22F1A5 -> 62F1A50005F3C7E719` in `bcm_all_safe_reads_20260508_083940.json`; write-plan files use the same payload | Log-validated |
| Current byte facts are byte 12 = `6D`, byte 21 = `82`, byte 23 = `00`. | Derived from latest `220600` coding | Log-validated derivation |
| 2026-05-08 BCM DTC path returned no records on `1802FF00`. | `diagnose_still_on_20260508_080202.json`; decoder output for `5800` reports count `0` | Log/tool-validated |
| `1902FF` is not supported in this BCM TP2.0 session. | `1902FF -> 7F1911`; decoder maps `11` to service-not-supported | Log/tool-validated |

## Known Bits

| Location | Recovered meaning | Latest state | Evidence |
|---:|---|---|---|
| byte 12 bit 0 | Nordic/Standlicht parking behavior | set | Latest byte 12 `6D`; guarded set/clear supported by `pq25_write_session.py` |
| byte 12 bit 6 | base cornering via fogs | set | Latest byte 12 `6D`; Carista current-settings view renders this as set |
| byte 21 bit 2 | turn-signal cornering assist | clear | Latest byte 21 `82`; full expert backup sets byte 21 to `86` |
| byte 21 bit 5 | turn off fogs with high beam | clear in latest retained coding | Latest byte 21 `82`; older byte `A6` state had it set |
| byte 21 bit 7 | cornering/fog experimental | set | Latest byte 21 `82`; recovered Carista branch maps byte 21 mask `0x80` |
| byte 23 bit 2 | DRL via fogs | clear | Latest byte 23 `00`; `drl_via_fogs_20260507_132841_write_plan.json` shows prior set test changed byte 23 `00 -> 04` |

Important correction: older notes that say byte 21 was currently `A6` describe
the pre-rollback/expert-write state. The latest retained 2026-05-08 diagnostic
state is byte 21 `82`.

## Write Evidence

| Claim | Evidence | Status |
|---|---|---|
| Carista-shaped DID `0600` write sequence is `2EF199`, `2EF198`, then `2E0600`, followed by fresh `220600` verification. | `CaristaReproduction.VagOperationDelegate.build_carista_uds_coding_write_plan`; retained write-plan JSON files | Code/log-validated |
| DRL-via-fogs test set byte 23 bit 2 only. | `docs/OBD_DIAGNOSTICS/session_artifacts/drl_via_fogs_20260507_132841_write_plan.json`, changed byte `23: 00 -> 04` | Plan/log-validated |
| Restore-to-expert-family/no-turn-signal-fogs write target cleared byte 21 bit 2 and restored byte 23 to `00`. | `restore_expert_backup_no_turn_signal_fogs_20260507_164848_write_plan.json`; latest 2026-05-08 read matches the target | Plan plus log-validated |
| Setting byte 21 bit 2 from latest state changes byte 21 `82 -> 86`. | `set_byte21_bit2_20260508_141959_write_plan.json`; offline `--uds-write-plan` output | Plan/tool-validated |
| Combined set byte 21 bit 2 and clear byte 12 bit 0 changes byte 12 `6D -> 6C` and byte 21 `82 -> 86`. | `set_byte21_bit2_clear_byte12_bit0_20260508_142330_write_plan.json` | Plan-validated |

Behavior notes such as "DRL via fogs did not fix the symptom" are retained as
human observation. The logs validate the coding change, not the visible lamp
behavior.

## Read And Scan Evidence

| Claim | Evidence | Status |
|---|---|---|
| Passive `ATMA` monitoring through this ELM/gateway path produced no usable light-context frames. | `fog_icon_green_monitor_20260508_080718.txt`, `hard_monitor_probe_20260508_081033.txt`, `interactive_monitor_toggle_20260508_081249.txt`, `monitor_protocol_sweep_20260508_081741.txt` | Log-validated limitation |
| Active diagnostic polling still worked while passive monitor failed. | `monitor_fix_attempt_20260508_081531.txt` includes a valid `0100` response | Log-validated |
| `all-safe` profile returned stable known reads and rejected Carista-core `1A9A/1A9B/1A9F`. | `bcm_all_safe_reads_20260508_083940.json` | Log-validated |
| `1089` setup is not useful for current `1A9A/1A9B/1A9F` reads. | `carista_1a_after_1089_setup_20260508_084538.json` | Log-validated |
| KWP `2101` through `210F` are positive measuring-block reads, but off/on comparison only changed `2102` voltage fields. | `kwp21_00_0f_probe_20260508_084738.json`; `kwp21_lights_off_20260508_085221.json`; `kwp21_lowbeam_fog_on_20260508_085416.json`; `kwp21_switch_compare_on_20260508_085624.json`; `analyze_kwp21_measurements.py` output | Log/tool-validated |
| Direct per-side/fog-role candidates `22055C`, `22055D`, `22110E`, `22056D`, `220550`, `220551`, `220D01`, and `220A58` rejected with `7F2231` in retained sessions. | `pq25_live_direct_055c_055d_minimal_*`, `pq25_live_direct_22056D_*`, `pq25_live_direct_22110E_*`, `readonly_adjacent_20260507_133841.json`, `readonly_optional_role_20260507_134000.json` | Log-validated |

## Carista Reverse Evidence

| Claim | Evidence | Status |
|---|---|---|
| `car_setting_cornering_lights_via_fogs` maps to DID `0600` byte 12 mask `0x40`. | `CaristaReproduction.VagCanSettings`; `docs/CARISTA_REVERSE/carista_recovery_summary.md` | Static/code-validated |
| `car_setting_cornering_lights_via_fogs_experimental` maps to DID `0600` byte 21 mask `0x80`. | Same | Static/code-validated |
| `car_setting_cornering_lights_with_turn_signals` maps to DID `0600` byte 21 mask `0x04`. | Same | Static/code-validated |
| `car_setting_drl_via_fogs` maps to DID `0600` byte 23 mask `0x04`. | Same plus 2026-05-07 write plan | Static/code/log-validated |
| VAG adaptation read routine uses exact `31B8/31BA/31B9/31BA/32B8`, not a broad routine scan. | `CaristaReproduction.Commands.VagCanAdaptationCommands`; `CaristaReproduction.VagOperationDelegate` | Static/code-validated |

## Current Conclusion

The retained logs validate the current coding and the guarded write paths. They
do not expose a live fog-switch bit through the known safe TP2.0 reads. The next
software scan with this adapter should continue KWP `21xx` chunks and small
read-only DID ranges. Writes should be limited to `pq25_write_session.ps1` dry
runs followed by explicit `-Write` confirmation.
