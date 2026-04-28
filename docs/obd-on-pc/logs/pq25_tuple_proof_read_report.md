# Carista Tuple-Proof Read Summary

This report summarizes the read-only in-car proof attempt for Carista `3B9A` tuple metadata.

## Inputs

- `logs\pq25_tuple_proof_baseline_220600_direct_read_summary.json`
- `logs\pq25_tuple_proof_direct_1A9B_direct_read_summary.json`
- `logs\pq25_tuple_proof_direct_carista_kwp_direct_read_summary.json`
- `logs\pq25_tuple_proof_pre_1A9B_pre_read_sweep_summary.json`
- `logs\pq25_tuple_proof_pre_1A9B_sctr_pre_read_sweep_summary.json`
- `logs\pq25_tuple_proof_skip_params_1A9B_read_sweep_summary.json`

## Fresh Coding

```text
3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000
```

## 1A9B Attempts

| Attempt | Mode | Session | Pre-read | Read counter | Status | Result |
|---|---|---|---|---:|---|---|
| `direct_ctr0_1A9B` | `direct_read` | `direct` | `none` | `0` | `negative` | `7F1A11` |
| `direct_ctr0_1A9B` | `direct_read` | `direct` | `none` | `0` | `no_response` | `<empty>` |
| `pre_1089_sctr0_none_0ms_rctr0_read_1A9B` | `pre_read_sweep` | `1089` | `none` | `0` | `disconnect` | `<empty>` |
| `pre_1089_sctr0_none_0ms_rctr1_read_1A9B` | `pre_read_sweep` | `1089` | `none` | `1` | `` | `<empty>` |
| `pre_1089_sctr0_none_0ms_rctr2_read_1A9B` | `pre_read_sweep` | `1089` | `none` | `2` | `` | `<empty>` |
| `pre_1089_sctr0_none_50ms_rctr0_read_1A9B` | `pre_read_sweep` | `1089` | `none` | `0` | `` | `<empty>` |
| `pre_1089_sctr0_none_50ms_rctr1_read_1A9B` | `pre_read_sweep` | `1089` | `none` | `1` | `disconnect` | `<empty>` |
| `pre_1089_sctr0_none_50ms_rctr2_read_1A9B` | `pre_read_sweep` | `1089` | `none` | `2` | `` | `<empty>` |
| `pre_1089_sctr0_A3_0ms_rctr0_read_1A9B` | `pre_read_sweep` | `1089` | `A3` | `0` | `` | `<empty>` |
| `pre_1089_sctr0_A3_0ms_rctr1_read_1A9B` | `pre_read_sweep` | `1089` | `A3` | `1` | `` | `<empty>` |
| `pre_1089_sctr0_A3_0ms_rctr2_read_1A9B` | `pre_read_sweep` | `1089` | `A3` | `2` | `` | `<empty>` |
| `pre_1089_sctr0_A3_50ms_rctr0_read_1A9B` | `pre_read_sweep` | `1089` | `A3` | `0` | `disconnect` | `<empty>` |
| `pre_1089_sctr0_A3_50ms_rctr1_read_1A9B` | `pre_read_sweep` | `1089` | `A3` | `1` | `` | `<empty>` |
| `pre_1089_sctr0_A3_50ms_rctr2_read_1A9B` | `pre_read_sweep` | `1089` | `A3` | `2` | `disconnect` | `<empty>` |
| `pre_1089_sctr0_A3+B1_0ms_rctr0_read_1A9B` | `pre_read_sweep` | `1089` | `A3+B1` | `0` | `disconnect` | `<empty>` |
| `pre_1089_sctr0_A3+B1_0ms_rctr1_read_1A9B` | `pre_read_sweep` | `1089` | `A3+B1` | `1` | `disconnect` | `<empty>` |
| `pre_1089_sctr0_A3+B1_0ms_rctr2_read_1A9B` | `pre_read_sweep` | `1089` | `A3+B1` | `2` | `` | `<empty>` |
| `pre_1089_sctr0_A3+B1_50ms_rctr0_read_1A9B` | `pre_read_sweep` | `1089` | `A3+B1` | `0` | `disconnect` | `<empty>` |
| `pre_1089_sctr0_A3+B1_50ms_rctr1_read_1A9B` | `pre_read_sweep` | `1089` | `A3+B1` | `1` | `disconnect` | `<empty>` |
| `pre_1089_sctr0_A3+B1_50ms_rctr2_read_1A9B` | `pre_read_sweep` | `1089` | `A3+B1` | `2` | `disconnect` | `<empty>` |
| `pre_1089_sctr1_none_0ms_rctr1_read_1A9B` | `pre_read_sweep` | `1089` | `none` | `1` | `` | `<empty>` |
| `pre_1089_sctr1_none_0ms_rctr2_read_1A9B` | `pre_read_sweep` | `1089` | `none` | `2` | `` | `<empty>` |
| `pre_1089_sctr1_none_0ms_rctr3_read_1A9B` | `pre_read_sweep` | `1089` | `none` | `3` | `` | `<empty>` |
| `pre_1089_sctr1_A3_0ms_rctr1_read_1A9B` | `pre_read_sweep` | `1089` | `A3` | `1` | `` | `<empty>` |
| `pre_1089_sctr1_A3_0ms_rctr2_read_1A9B` | `pre_read_sweep` | `1089` | `A3` | `2` | `` | `<empty>` |
| `pre_1089_sctr1_A3_0ms_rctr3_read_1A9B` | `pre_read_sweep` | `1089` | `A3` | `3` | `` | `<empty>` |
| `pre_1089_sctr2_none_0ms_rctr1_read_1A9B` | `pre_read_sweep` | `1089` | `none` | `1` | `` | `<empty>` |
| `pre_1089_sctr2_none_0ms_rctr2_read_1A9B` | `pre_read_sweep` | `1089` | `none` | `2` | `` | `<empty>` |
| `pre_1089_sctr2_none_0ms_rctr3_read_1A9B` | `pre_read_sweep` | `1089` | `none` | `3` | `` | `<empty>` |
| `pre_1089_sctr2_A3_0ms_rctr1_read_1A9B` | `pre_read_sweep` | `1089` | `A3` | `1` | `` | `<empty>` |
| `pre_1089_sctr2_A3_0ms_rctr2_read_1A9B` | `pre_read_sweep` | `1089` | `A3` | `2` | `` | `<empty>` |
| `pre_1089_sctr2_A3_0ms_rctr3_read_1A9B` | `pre_read_sweep` | `1089` | `A3` | `3` | `` | `<empty>` |
| `read_1089_none_100ms_1A9B` | `read_sweep` | `1089` | `none` | `` | `` | `<empty>` |

## Tuple Metadata Proof

No positive `5A9B` response was found. The actual tuple is still not proven; do not use any placeholder rawAddress4.

Fallback/session-counter reads were included and still did not produce `5A9B`. Stop the in-car tuple-proof read attempt and keep the logs as negative evidence.
