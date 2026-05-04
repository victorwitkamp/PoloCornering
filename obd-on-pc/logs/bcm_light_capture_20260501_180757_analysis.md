# BCM Light Capture Analysis

Sources:

- `logs\bcm_light_capture_20260501_180757_bcm_light_capture.json`

DBC signal reference: `C:\Users\victo\Downloads\PoloCornering\reference\opendbc\opendbc__dbc__vw_pq.dbc`

## Diagnostic Status Summary

| command | state | status | payload_bytes | observations | payload |
|---|---|---|---|---|---|
| 1802FF00 | baseline_off | no_response |  | 1 |  |
| 1802FF00 | left_turn | no_response |  | 1 |  |
| 1802FF00 | lowbeam_fog_on | no_response |  | 1 |  |
| 1902FF | baseline_off | no_response |  | 1 |  |
| 1902FF | left_turn | no_response |  | 1 |  |
| 1902FF | lowbeam_fog_on | no_response |  | 1 |  |
| 1A91 | baseline_off | no_response |  | 1 |  |
| 1A91 | left_turn | no_response |  | 1 |  |
| 1A91 | lowbeam_fog_on | no_response |  | 1 |  |
| 1A9A | baseline_off | no_response |  | 1 |  |
| 1A9A | left_turn | no_response |  | 1 |  |
| 1A9A | lowbeam_fog_on | no_response |  | 1 |  |
| 220600 | baseline_off | no_response |  | 1 |  |
| 220600 | left_turn | no_response |  | 1 |  |
| 220600 | lowbeam_fog_off | positive | 33 | 1 | 6206003AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000 |
| 220600 | lowbeam_fog_on | no_response |  | 1 |  |
| 220600 | parking_fog_off | positive | 33 | 1 | 6206003AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000 |
| 220600 | parking_fog_on | positive | 33 | 1 | 6206003AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000 |
| 220600 | right_turn | positive | 33 | 1 | 6206003AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000 |
| 220606 | baseline_off | no_response |  | 1 |  |
| 220606 | left_turn | no_response |  | 1 |  |
| 220606 | lowbeam_fog_off | disconnect |  | 1 |  |
| 220606 | lowbeam_fog_on | no_response |  | 1 |  |
| 220606 | parking_fog_off | disconnect |  | 1 |  |
| 220606 | parking_fog_on | disconnect |  | 1 |  |
| 220606 | right_turn | disconnect |  | 1 |  |

## Diagnostic Read Deltas

No rows.

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
