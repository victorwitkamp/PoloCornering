# BCM Light-State Capture

Started: `2026-05-03T20:41:40.892`
Last updated: `2026-05-03T20:44:21.602`
Run id: `chlh_fog_capture_20260503`
Completed: `True`
Interrupted: `False`

This capture is read-only. It sends only the configured diagnostic read commands and blocks services `27`, `2E`, `31`, and `3B`.

## Inputs

- Port: `COM10`
- Unit: `20`
- Read profile: `bcm_ch_lh_debug`
- States: `baseline_off, parking_fog_off, parking_fog_on, lowbeam_fog_off, lowbeam_fog_on, left_turn, right_turn`
- Repeats: `1`
- Raw CAN window: `0 ms`

## Changed Diagnostic Payloads

No diagnostic read payload changed from the first captured payload for the same command.

## Command Matrix

### `220600`
direct long-coding read DID; latest live baseline returns 620600 + 30-byte coding

| State | Repeat | Status | Payload bytes | Payload |
|---|---:|---|---:|---|
| `baseline_off` | 1 | `no_response` |  | `` |
| `parking_fog_off` | 1 | `no_response` |  | `` |
| `parking_fog_on` | 1 | `no_response` |  | `` |
| `lowbeam_fog_off` | 1 | `no_response` |  | `` |
| `lowbeam_fog_on` | 1 | `no_response` |  | `` |
| `left_turn` | 1 | `no_response` |  | `` |
| `right_turn` | 1 | `no_response` |  | `` |

### `220601`
Carista-shaped UDS companion DID from the current BCM identity/status sweep

| State | Repeat | Status | Payload bytes | Payload |
|---|---:|---|---:|---|
| `baseline_off` | 1 | `no_response` |  | `` |
| `parking_fog_off` | 1 | `no_response` |  | `` |
| `parking_fog_on` | 1 | `no_response` |  | `` |
| `lowbeam_fog_off` | 1 | `no_response` |  | `` |
| `lowbeam_fog_on` | 1 | `no_response` |  | `` |
| `left_turn` | 1 | `no_response` |  | `` |
| `right_turn` | 1 | `no_response` |  | `` |

### `220606`
Carista-shaped UDS companion DID; previous live response was 620606001800018000

| State | Repeat | Status | Payload bytes | Payload |
|---|---:|---|---:|---|
| `baseline_off` | 1 | `no_response` |  | `` |
| `parking_fog_off` | 1 | `no_response` |  | `` |
| `parking_fog_on` | 1 | `no_response` |  | `` |
| `lowbeam_fog_off` | 1 | `no_response` |  | `` |
| `lowbeam_fog_on` | 1 | `no_response` |  | `` |
| `left_turn` | 1 | `no_response` |  | `` |
| `right_turn` | 1 | `no_response` |  | `` |

### `22055C`

| State | Repeat | Status | Payload bytes | Payload |
|---|---:|---|---:|---|
| `baseline_off` | 1 | `no_response` |  | `` |
| `parking_fog_off` | 1 | `no_response` |  | `` |
| `parking_fog_on` | 1 | `no_response` |  | `` |
| `lowbeam_fog_off` | 1 | `no_response` |  | `` |
| `lowbeam_fog_on` | 1 | `no_response` |  | `` |
| `left_turn` | 1 | `no_response` |  | `` |
| `right_turn` | 1 | `no_response` |  | `` |

### `22055D`

| State | Repeat | Status | Payload bytes | Payload |
|---|---:|---|---:|---|
| `baseline_off` | 1 | `no_response` |  | `` |
| `parking_fog_off` | 1 | `no_response` |  | `` |
| `parking_fog_on` | 1 | `no_response` |  | `` |
| `lowbeam_fog_off` | 1 | `no_response` |  | `` |
| `lowbeam_fog_on` | 1 | `no_response` |  | `` |
| `left_turn` | 1 | `no_response` |  | `` |
| `right_turn` | 1 | `no_response` |  | `` |

### `1A9A`
ReadVagCanLongCodingCommand_getRequest / long coding

| State | Repeat | Status | Payload bytes | Payload |
|---|---:|---|---:|---|
| `baseline_off` | 1 | `no_response` |  | `` |
| `parking_fog_off` | 1 | `no_response` |  | `` |
| `parking_fog_on` | 1 | `no_response` |  | `` |
| `lowbeam_fog_off` | 1 | `no_response` |  | `` |
| `lowbeam_fog_on` | 1 | `no_response` |  | `` |
| `left_turn` | 1 | `no_response` |  | `` |
| `right_turn` | 1 | `no_response` |  | `` |

### `1A91`
Carista VAGCAN20 simulator identity/coding-related block

| State | Repeat | Status | Payload bytes | Payload |
|---|---:|---|---:|---|
| `baseline_off` | 1 | `no_response` |  | `` |
| `parking_fog_off` | 1 | `no_response` |  | `` |
| `parking_fog_on` | 1 | `no_response` |  | `` |
| `lowbeam_fog_off` | 1 | `no_response` |  | `` |
| `lowbeam_fog_on` | 1 | `no_response` |  | `` |
| `left_turn` | 1 | `no_response` |  | `` |
| `right_turn` | 1 | `no_response` |  | `` |

### `1802FF00`
read-only DTC/status read retained for BCM lighting debug snapshots; previous live response was 58020C9820038B20

| State | Repeat | Status | Payload bytes | Payload |
|---|---:|---|---:|---|
| `baseline_off` | 1 | `no_response` |  | `` |
| `parking_fog_off` | 1 | `no_response` |  | `` |
| `parking_fog_on` | 1 | `no_response` |  | `` |
| `lowbeam_fog_off` | 1 | `no_response` |  | `` |
| `lowbeam_fog_on` | 1 | `no_response` |  | `` |
| `left_turn` | 1 | `no_response` |  | `` |
| `right_turn` | 1 | `no_response` |  | `` |

### `1902FF`
read-only DTC/status read retained for BCM lighting debug snapshots; previous live response was 7F1911

| State | Repeat | Status | Payload bytes | Payload |
|---|---:|---|---:|---|
| `baseline_off` | 1 | `no_response` |  | `` |
| `parking_fog_off` | 1 | `no_response` |  | `` |
| `parking_fog_on` | 1 | `no_response` |  | `` |
| `lowbeam_fog_off` | 1 | `no_response` |  | `` |
| `lowbeam_fog_on` | 1 | `no_response` |  | `` |
| `left_turn` | 1 | `no_response` |  | `` |
| `right_turn` | 1 | `no_response` |  | `` |

## Raw CAN

Raw CAN capture was disabled or retained no frames.

## Notes

- A changed payload is a clue, not a decoded lamp state by itself.
- Raw CAN monitor-all output from an ELM adapter can drop frames on a busy bus; use repeated captures for proof.
- If no payload changes across lamp states, the missing lamp-state path is probably behind an unrecovered Carista `ReadValuesOperation` setting/value implementation.
