# BCM Light Capture Analysis

Sources:

- `logs\bcm_confirmed_baseline_20260501_1816_bcm_light_capture.json`
- `logs\bcm_confirmed_fault_20260502_0001_bcm_light_capture.json`
- `logs\bcm_repeat_fault_20260502_0002_bcm_light_capture.json`
- `logs\bcm_off_after_fault_20260502_0003_bcm_light_capture.json`
- `logs\bcm_parking_no_fog_20260502_0004_bcm_light_capture.json`

DBC signal reference: `C:\Users\victo\Downloads\PoloCornering\reference\opendbc\opendbc__dbc__vw_pq.dbc`

## Diagnostic Status Summary

| command | state | status | payload_bytes | observations | payload |
|---|---|---|---|---|---|
| 220600 | clean_baseline_off | positive | 33 | 1 | 6206003AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000 |
| 220600 | confirmed_fault_right_fog_on | positive | 33 | 1 | 6206003AB02BBF08A10000003008006D6B0CD000C0412F60860000200000000000 |
| 220600 | off_after_fault | no_response |  | 1 |  |
| 220600 | parking_no_fog_after_fault | positive | 33 | 1 | 6206003AB02BBF08A10000003008006D6B0CD000C0412F60860000200000000000 |
| 220600 | repeat_fault_right_fog_on | positive | 33 | 1 | 6206003AB02BBF08A10000003008006D6B0CD000C0412F60860000200000000000 |

## Diagnostic Read Deltas

| command | baseline_state | state | repeat | byte_index | baseline_byte | state_byte | bit_deltas |
|---|---|---|---|---|---|---|---|
| 220600 | clean_baseline_off | confirmed_fault_right_fog_on | 1 | 16 | 2B | 6B | b6:0->1 |
| 220600 | clean_baseline_off | repeat_fault_right_fog_on | 1 | 16 | 2B | 6B | b6:0->1 |
| 220600 | clean_baseline_off | parking_no_fog_after_fault | 1 | 16 | 2B | 6B | b6:0->1 |

## Repeat Instability

No rows.

## Raw CAN Headers

No rows.

## State-Specific Raw CAN Payloads

No rows.

## Raw CAN Signal Deltas

No rows.

## Reading This

- Diagnostic deltas are the strongest clues because they are request/response scoped to the BCM TP2.0 channel.
- Repeat instability means the same state did not reproduce cleanly; repeat before treating it as a lamp clue.
- Raw CAN rows are weaker because ELM monitor-all can drop frames, but state-specific payloads are good targets for repeated captures.
