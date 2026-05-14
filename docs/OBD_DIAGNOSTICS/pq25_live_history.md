# PQ25 Live History

Date: 2026-05-14

This is the condensed live-car history for the Polo 6R / PQ25 BCM work. Current
manual procedures are in `pq25_manual_procedures.md`; claim-to-log validation is
in `pq25_evidence_matrix.md`.

## Controller And Transport

```text
Vehicle: VW Polo 6R / PQ25
Module: 09 Central Electronics / BCM / J519
Part: 6R0937087K
Component: BCM PQ25 H+4
Software: 0254
TP2.0 unit address: 20
Adapter: Carista ELM327 on COM10 at 38400 baud
Open request: 20C00010000301
Data channel: send 338, listen 300
Carista exact params: A00194FF82FF
Polo-proven fallback params: A00F8AFF32FF
```

Safety boundary:

```text
Do not send raw 27, 2E, 31, or 3B unless the session is explicitly a guarded
write or the exact Carista adaptation read routine implemented by the project.
```

## Current Retained State

Latest retained in-car read-only state, captured on 2026-05-08:

```text
220600 -> 6206003AB02BBF08A10000003008006D2B0CD000C0412F60820000200000000000
220601 -> 6206011E
220606 -> 620606001800018000
22F1A5 -> 62F1A50005F3C7E719
```

Current zero-based byte facts:

```text
byte 12 = 6D: bit 0 set, bit 6 set
byte 21 = 82: bit 7 set, bit 5 clear, bit 2 clear
byte 23 = 00: bit 2 clear
```

This is the expert-backup family with the turn-signal fog trigger cleared. The
full expert backup differs only at byte 21 bit 2:

```text
current retained coding: 3AB02BBF08A10000003008006D2B0CD000C0412F60820000200000000000
full expert backup:      3AB02BBF08A10000003008006D2B0CD000C0412F60860000200000000000
```

## Timeline

### 2026-04-28 Baseline And Reference

Earlier baseline:

```text
3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000
```

Supplied/reference coding:

```text
3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

The only two differences were byte 12 bit 6 and byte 21 bit 2. Both were later
written and verified, but neither fixed the visible symptom as a standalone
change.

### 2026-04-29 Drive Diagnostics

Read-only drive diagnostics found stable BCM reads:

```text
220600 -> 620600 + 30-byte coding
220601 -> 6206011E
220606 -> 620606001800018000
22F187 -> 6R0937087K
22F189 -> 0254
22F197 -> BCM PQ25 H+4
```

No safe read command from that pass exposed a changing lamp-output state,
fog-switch state, or cornering trigger state. Generic UDS scans found other
responders, but did not change the BCM write path.

### 2026-05-01 To 2026-05-05 Coding Writes

The Carista-shaped DID `0600` full-coding write path was proven and verified:

```text
2EF199 + YYMMDD
22F1A5 inline workshop-code read
2EF198 + workshop-code payload
2E0600 + full 30-byte coding
fresh 220600 verification
```

The byte 12 bit 6 plus byte 21 bit 2 target persisted, but physical fog/cornering
behavior did not change. That made the direct cornering-enable bits behavior-
disproven as a standalone repair.

### 2026-05-07 DRL-Via-Fogs Test And Rollback

Recovered Carista branch:

```text
car_setting_drl_via_fogs
DID 0600 byte 23 mask 0x04
whitelist CENTRAL_ELEC_6R_5C_7E_7H
```

The test wrote byte 23 bit 2 and verified the coding change. Physical behavior
did not change, so DRL-via-fogs is behavior-disproven for the original symptom.

The car was then brought back to the expert-backup family with byte 21 bit 2
cleared:

```text
3AB02BBF08A10000003008006D2B0CD000C0412F60820000200000000000
```

### 2026-05-08 Active Troubleshooting

The live runner was adjusted for this ELM clone:

```text
send channel parameters before ATCRA300
prefer Polo-proven A00F8AFF32FF when exact Carista params do not answer
use ATST32 for response collection
fail cleanly if 220600 is shorter than 30 coding bytes
```

Read-only troubleshooting confirmed the latest retained state above.

Companion reads during the still-on state:

```text
1802FF00 -> 5800
1902FF -> 7F1911
22F187 -> 62F1873652303933373038374B20
22F189 -> 62F18930323534
22F197 -> 62F19742434D205051323520482B3420
220601 -> 6206011E
220606 -> 620606001800018000
```

`1802FF00 -> 5800` decodes as zero reported BCM DTC records on that path.
`1902FF -> 7F1911` decodes as service-not-supported.

Passive `ATMA` monitoring repeatedly produced no useful frames through this
ELM/gateway path, while active diagnostics still worked. The project therefore
uses active TP2.0/UDS/KWP polling with guarded writes, not passive ELM monitor
capture, for this adapter.

KWP `21xx` measuring blocks were the first positive live monitor family:

```text
2101..210F -> positive except 2100
```

The retained off/on comparison only changed `2102`, and the decoded changes are
supply-voltage fields, not fog-switch state. Continue scanning from `2110` in
small chunks when more live search is needed.

## Known Bits

| Location | Recovered meaning | Latest retained state |
|---:|---|---|
| byte 12 bit 0 | Scandinavian/Nordic parking/Standlicht behavior | set |
| byte 12 bit 6 | base fog-light cornering / use-cornering family | set |
| byte 21 bit 2 | turn-signal-triggered cornering assist | clear |
| byte 21 bit 5 | turn off fogs with high beam | clear in latest retained coding |
| byte 21 bit 7 | cornering/fog experimental capability | set |
| byte 23 bit 2 | DRL via fogs | clear |

Guarded set/clear flags exist for all known bits through
`obd-on-pc/pq25_write_session.ps1`.

## Current Procedure Pointers

Read:

```powershell
.\obd-on-pc\pq25_read_monitor.ps1 -Profile all-safe -Cycles 1 -Label bcm_all_safe
```

Dry-run a write plan:

```powershell
.\obd-on-pc\pq25_write_session.ps1 -Operation restore-expert-backup
.\obd-on-pc\pq25_write_session.ps1 -SetBit byte21-bit2 -ClearBit byte12-bit0
```

Confirmed write:

```powershell
.\obd-on-pc\pq25_write_session.ps1 -Operation restore-expert-backup -Write
```

The runner reads fresh current coding, changes only the selected target bits or
operation target, writes only after literal `YES`, and verifies with a fresh
`220600`.

## Rejected Direct Reads

Do not repeat these by default; they already returned negative evidence on this
BCM/session:

```text
22055C, 22055D, 22110E, 22056D, 220550, 220551, 220D01, 220A58, 220A57
```

`220601 -> 6206011E` remains an important role clue, but no recovered 6R/PQ25
Carista write path ties DID `0601` to a writable Setting object. It is not a
write seed.

## Current Conclusion

The original fog/cornering symptom is no longer treated as another missing
cornering-enable bit. All recovered direct 6R/PQ25 cornering or DRL-via-fogs
`0600` bits are either already set, explicitly tested, or behavior-disproven for
that symptom. Future software work should focus on read-only evidence and
Carista runtime branch recovery; future writes should stay within the guarded
`pq25_write_session` path.
