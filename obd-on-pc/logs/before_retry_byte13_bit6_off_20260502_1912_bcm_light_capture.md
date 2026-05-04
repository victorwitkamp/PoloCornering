# BCM Light-State Capture

Started: `2026-05-02T19:11:59.167`
Last updated: `2026-05-02T19:12:09.039`
Run id: `before_retry_byte13_bit6_off_20260502_1912`
Completed: `True`
Interrupted: `False`

This capture is read-only. It sends only the configured diagnostic read commands and blocks services `27`, `2E`, `31`, and `3B`.

## Inputs

- Port: `COM10`
- Unit: `20`
- Read profile: `bcm_light_debug`
- States: `before_retry_byte13_bit6_off`
- Repeats: `1`
- Raw CAN window: `0 ms`

## Changed Diagnostic Payloads

No diagnostic read payload changed from the first captured payload for the same command.

## Command Matrix

### `220600`
direct long-coding read DID; latest live baseline returns 620600 + 30-byte coding

| State | Repeat | Status | Payload bytes | Payload |
|---|---:|---|---:|---|
| `before_retry_byte13_bit6_off` | 1 | `positive` | 33 | `6206003AB02BBF08A10000003008006D6B0CD000C0412F60860000200000000000` |

## Raw CAN

Raw CAN capture was disabled or retained no frames.

## Notes

- A changed payload is a clue, not a decoded lamp state by itself.
- Raw CAN monitor-all output from an ELM adapter can drop frames on a busy bus; use repeated captures for proof.
- If no payload changes across lamp states, the missing lamp-state path is probably behind an unrecovered Carista `ReadValuesOperation` setting/value implementation.
