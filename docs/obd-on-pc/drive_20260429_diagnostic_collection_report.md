# Drive Diagnostic Collection Report

Date: 2026-04-29

## Scope

Live collection was performed through the Carista Bluetooth adapter on `COM10`
at `38400` baud while the car was running/driving. The collection was read-only.

Blocked services remained excluded:

```text
27 security access
2E write data by identifier
31 routine control
3B write data by local identifier
```

New helper scripts:

```text
obd-on-pc/collect_drive_diagnostics.ps1
obd-on-pc/scan_vag_uds_headers.py
```

Main log groups:

```text
obd-on-pc/logs/drive_20260429_1008_live_*
obd-on-pc/logs/drive_20260429_1046_all_uds_ecus_fixed_uds_header_scan.*
obd-on-pc/logs/drive_20260429_1048_other_ecus_dtc_identity_uds_header_scan.*
obd-on-pc/logs/drive_20260429_1050_pending_dtc_retry_uds_header_scan.*
```

## BCM Drive Collection

The BCM TP2.0 drive collector produced 40 summary files before being stopped to
free `COM10` for other ECU scans.

Important result:

```text
No read command produced more than one distinct payload.
```

That means the currently known Carista-compatible BCM read set behaved as static
identity/coding/status data during the drive. It did not expose a changing
lamp-output state, lamp reason, fog-switch state, or cornering-light trigger
state.

Stable BCM payloads seen:

| Command | Stable payload |
|---|---|
| `220600` | `6206003AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000` |
| `220601` | `6206011E` |
| `220606` | `620606001800018000` |
| `22F187` | `62F1873652303933373038374B20` |
| `22F189` | `62F18930323534` |
| `22F18C` | `62F18C3034333420303533313230393937` |
| `22F191` | `62F1913652303933373038372020` |
| `22F197` | `62F19742434D205051323520482B3420` |
| `22F1A3` | `62F1A3483436` |
| `22F1AA` | `62F1AA4A35313920` |
| `22F1DF` | `62F1DF40` |
| `1802FF00` | `58010C9820` |
| `1902FF` | `7F1911` |

Decoded BCM identity highlights:

```text
Part/DID F187: 6R0937087K
Software/DID F189: 0254
Component/DID F197: BCM PQ25 H+4
Workshop/application-ish DID F1AA: J519
Current coding/DID 0600:
  3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000
```

Current interpretation:

```text
The known BCM reads are useful for identity and coding verification.
They are not enough to debug why a fog/cornering output is active.
The missing path is still Carista's native ReadValuesOperation setting/value map.
```

## UDS ECU Discovery

The generic UDS scanner was adjusted to use the same ELM setup that works for
normal UDS modules:

```text
ATCAF1
ATV0
```

The first TP2.0-style setup `ATCAF0`/`ATV1` found no UDS responders, while a
manual check proved engine and cluster were alive. After the setup fix, the
broad scan found these UDS responders:

| Request | Response | Evidence |
|---|---|---|
| `7E0` | `7E8` | Engine |
| `711` | `77B` | UDS responder, exact module not identified from current payloads |
| `714` | `77E` | Cluster / instruments path from previous evidence |
| `715` | `77F` | UDS responder, exact module not identified from current payloads |

No other headers in the scanned `700..71F` and `7E0..7E7` ranges responded.

## Other ECU Data

### Engine `7E0 -> 7E8`

| Command | Payload | Decoded note |
|---|---|---|
| `220600` | `620600001100D6202400080000` | engine coding `001100D6202400080000` |
| `22F190` | `62F1905756575A5A5A36525A4359323330343134` | VIN `WVWZZZ6RZCY230414` |
| `22F187` | `62F1873033463930363037304744` | part `03F906070GD` |
| `22F189` | `62F18935343636` | software `5466` |
| `22F197` | `62F19753494D4F5331302E3232410000` | component `SIMOS10.22A` |
| `22F191` | `62F191303346393037333039414A` | `03F907309AJ` |
| `22F1A3` | `62F1A3483130` | `H10` |
| `22F1AA` | `62F1AA4A36323320` | `J623` |
| `22F1DF` | `62F1DF40` | raw `40` |
| `1902FF` | `7F1978` | response pending only, even with longer timeout |
| `1802FF00` | `001C1C50AAAAAA` | raw response retained; do not over-interpret yet |

### Header `711 -> 77B`

| Command | Payload | Decoded note |
|---|---|---|
| `220600` | `620600000000` | coding-like value `000000` |
| `22F190` | `62F190575657` | partial VIN prefix only in this scan |
| `22F187` | `62F187354B30` | `5K0` |
| `22F191` | `62F191354B30` | `5K0` |
| `22F1DF` | `62F1DF40` | raw `40` |
| `1902FF` | `590299D20000` | UDS `19/02` positive response with status availability mask `99`; incomplete `DTCAndStatusRecord` leaves trailing raw bytes `D20000` without a status byte |

### Cluster `714 -> 77E`

| Command | Payload | Decoded note |
|---|---|---|
| `220600` | `620600140801` | cluster coding `140801` |
| `22F190` | `62F190575657` | partial VIN prefix only in this scan |
| `22F187` | `62F187365230` | `6R0` |
| `22F191` | `62F191365230` | `6R0` |
| `22F18C` | `62F18C303030` | `000` |
| `22F1DF` | `62F1DF40` | raw `40` |
| `1902FF` | `590299C4010008` | UDS `19/02` positive response with status availability mask `99`; one complete DTC record `C40100` (SAE-format candidate `U0401:00`) status `08` = `confirmedDTC` |
| `1802FF00` | `7F1811` | service not supported |

### Header `715 -> 77F`

| Command | Payload | Decoded note |
|---|---|---|
| `220600` | `620600003232` | coding-like value `003232` |
| `22F190` | `62F190575657` | partial VIN prefix only in this scan |
| `22F187` | `62F187365230` | `6R0` |
| `22F17E` | `62F17E2D2D2D` | `---` |
| `22F1AA` | `62F1AA4A3233` | `J23` |
| `1902FF` | `7F1978` | response pending only, even with longer timeout |

## Practical Conclusions

The BCM long coding was verified repeatedly and stayed at:

```text
3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000
```

The drive did not reveal a changing BCM live-data DID from the currently known
safe read set. For the cornering-light problem, the next useful work is still
offline/native:

```text
Recover the concrete Carista ReadValuesOperation setting/value path for:
  car_setting_fog_when
  car_setting_left_fog_light_as
  car_setting_right_fog_light_as
```

The other-ECU scans were successful enough to establish a small module inventory
and preserve raw DTC/status responses for later decoding, especially:

```text
  BCM/KWP 1802FF00: 58020C9820038B20 -> DTC candidates 03224 and 00907, status 0x20 raw bit b5
  711->77B 1902FF: 590299D20000 -> incomplete UDS DTC/status record after availability mask 0x99
  714->77E 1902FF: 590299C4010008 -> DTC C40100, SAE-format candidate U0401:00, confirmedDTC
```

Those raw `59...` payloads should be decoded separately before treating them as
actionable faults.
