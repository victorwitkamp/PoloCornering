# BCM Light-State Capture

Started: `2026-05-03T21:04:13.149`
Last updated: `2026-05-03T21:05:27.852`
Run id: `chlh_220601_missing_switches_20260503`
Completed: `True`
Interrupted: `False`

This capture is read-only. It sends only the configured diagnostic read commands and blocks services `27`, `2E`, `31`, and `3B`.

## Inputs

- Port: `COM10`
- Unit: `20`
- Read profile: `bcm_light_debug`
- States: `switch_left, right_pull_once, right_pull_twice, middle_left_turn`
- Repeats: `1`
- Raw CAN window: `0 ms`

## Changed Diagnostic Payloads

No diagnostic read payload changed from the first captured payload for the same command.

## Command Matrix

### `220601`
Carista-shaped UDS companion DID from the current BCM identity/status sweep

| State | Repeat | Status | Payload bytes | Payload |
|---|---:|---|---:|---|
| `switch_left` | 1 | `positive` | 4 | `6206011E` |
| `right_pull_once` | 1 | `positive` | 4 | `6206011E` |
| `right_pull_twice` | 1 | `positive` | 4 | `6206011E` |

## Raw CAN

Raw CAN capture was disabled or retained no frames.

## Notes

- A changed payload is a clue, not a decoded lamp state by itself.
- Raw CAN monitor-all output from an ELM adapter can drop frames on a busy bus; use repeated captures for proof.
- If no payload changes across lamp states, the missing lamp-state path is probably behind an unrecovered Carista `ReadValuesOperation` setting/value implementation.
