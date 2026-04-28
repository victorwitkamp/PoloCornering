# Next Car Attempt Plan

Purpose: keep the next live session short, focused, and reversible.

## Current State

Latest confirmed broken coding:

```text
3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000
```

Known working cornering-enabled coding:

```text
3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

Only two bytes should change:

```text
byte 12: 2C -> 6C  (byte 12 bit 6, fog-light cornering)
byte 21: A2 -> A6  (byte 21 bit 2, turn-signal cornering trigger)
```

If a fresh read differs in any other byte, stop and decode that new state first.

## Latest Carista RE Finding

The current best write model is no longer the old `3B9A` tuple path.

Ghidra exports now show:

```text
VagUdsCodingSetting(ecu, vector) hardcodes DID 0600 and setting type 8.
writeRawValue dispatches type 8 to writeVagUdsValue.
WriteDataByIdentifierCommand serializes 2E + DID + payload.
writeVagUdsValue sends:
  2EF199 + date payload
  2EF198 + workshop-code payload
  2E0600 + target coding payload
```

The earlier direct `2E0600 + full coding` reached the BCM and failed with
`7F2E22`, so the payload/DID was meaningful. The missing part was probably the
Carista pre-write sequence, not TP2.0 framing.

The live `22F1A5` result already gave the workshop-code payload Carista needs:

```text
22F1A5 -> 62F1A50005F3C7E719
F198 payload = 0005F3C7E719
```

`VagEcuInfo::getWorkshopCodeForWriting()` accepts a 6-byte workshop code and
only fills default WSC/importer/equipment fields if those subfields are zero.
The live payload is nonzero, so the next writer uses it as-is.

## Exact Negative-Response / ACK Proof - 2026-04-28

Fresh read-only Ghidra exports under `carista_apk_analysis/ghidra_exports_exact_flow/`
prove the F199/F198 metadata behavior and the TP2.0 ACK rule:

```text
BaseCommand_extractState maps UDS 7F xx 31 to Carista state -32.
State_Set_obd2NegativeResponse contains -32.
State_Set_fatalError is [-12, -1, -7, -4, -16, -51, -1000] and does not contain -32.
Result_EmptyModel_isFatalFail delegates to State::isFatalError.
writeVagUdsValue checks F199 and F198 with isFatalFail, not generic isFail.
```

Therefore a metadata pre-write response of `7F2E31` is an OBD2 negative
response in Carista, but it is not fatal at the F199/F198 gates. The guarded
writer may continue past exactly F199/F198 `7F2E31` when
`--allow-unsupported-metadata-prewrite` is explicit; the final `2E0600` coding
write must still be positive and verified by a fresh `220600` read.

The same export pass proves the ACK timing:

```text
VagCanCommunicator_readResponses ACKs accepted data packets inside the receive loop.
VagCanCommunicator_sendAck(seq,bool) sends opcode 0xB0 with (seq + 1) & 0x0F.
VagCanPacket_toRawBytesForSending serializes opcode | sequence as the first raw byte.
```

For the observed frames this means `B5` for the completed baseline `220600`
response ending at sequence 4, and `B6` for the single-frame F199 `7F2E31`
response at sequence 5.

Local writer status: `write_carista_uds_coding.py` has been repaired after the
bad ACK-timing patch and now compiles cleanly with `py_compile`. Do not run live
vehicle writes until the user is back in the car and confirms.

Follow-up static audit found and fixed one more replication mismatch: native
`generateOutgoingPackets` consumes one outgoing TP2.0 sequence number per
generated data packet, not once per logical UDS request. The writer now advances
the counter by the number of TP2.0 frames sent. For write-counter `0`, the
expected dry-run starts are now F199 `20/11`, F198 `22/13`, and final DID 0600
`24/25/26/27/18`.

Remaining non-exact areas are documented in
`carista_apk_analysis/carista_replication_gap_analysis.md`; the main live risk
is still transport/session envelope fidelity, not the `2EF199` / `2EF198` /
`2E0600` request payloads themselves.

2026-04-28 later live result: native `sendRequest` was disassembled and the
writer now mirrors its transmit behavior: non-final request packets use
`ATST04`, final request packets use `ATST20`, and the sender expects `B{next
outgoing seq}` before processing the application response. If that ACK is not
seen, it retransmits the same generated packets once after about 50 ms.

With that patch, the live sequence still stopped at the final target write:

```text
baseline 220600: positive, coding unchanged/broken
F199: 7F2E31, ACKed and tolerated as nonfatal metadata pre-write
F198: 6EF198 positive
0600: sent frames 25/26/27/28/19, expected transmit ACK BA
0600 retry: same frames sent once more, still no BA, no UDS response
post-attempt read-only 220600: positive, coding still unchanged/broken
```

Then a read-only Carista-exact channel-parameter probe using native
`A00194FF82FF` got `NO DATA`; the following `220600` in that channel also got
`NO DATA`. A subsequent minimal-profile recovery read also got `NO DATA`, so
stop live traffic until the ignition/adapter has been reset.

## Before Writing

From `obd-on-pc`, run the read-only validation wrapper:

```powershell
.\run_next_carista_validation.ps1 -Port COM10
```

It does:

```text
1. opens TP2.0 unit 20
2. reads 220600 current coding
3. reads 22F1A5 workshop-code payload
4. decodes current coding
5. prints a dry-run Carista UDS write plan
```

No `2E`, `27`, `31`, or `3B` write/routine/security service is sent by that
wrapper.

Expected dry-run requests if the car is still in the known broken state:

```text
2EF199YYMMDD
2EF1980005F3C7E719
2E06003AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

`YYMMDD` is generated from the current date, matching Carista's date-write code.

## Guarded Write Candidate

The prepared writer is:

```powershell
python .\write_carista_uds_coding.py --coding-file .\logs\pq25_carista_validation_baseline_220600_direct_read_summary.json --workshop-code-file .\logs\pq25_carista_validation_baseline_220600_direct_read_summary.json
```

That command is dry-run only.

Execution requires all guards:

```powershell
python .\write_carista_uds_coding.py `
  --coding-file .\logs\pq25_next_carista_uds_prep_direct_read_summary.json `
  --workshop-code-file .\logs\pq25_next_carista_uds_prep_direct_read_summary.json `
  --confirm-target 3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000 `
  --allow-unsupported-metadata-prewrite `
  --run-id pq25_cornering_direct_write_after_prep `
  --execute `
  --i-understand-this-writes-bcm-coding
```

The writer always re-reads `220600` before writing and refuses to continue if
the live coding differs from the expected current coding. After the write
sequence it immediately re-reads `220600` and requires exact target match.

2026-04-28 live retry notes:

```text
1. First guarded F199 write attempt closed with 300A8 immediately after a
  fresh multi-frame 220600 baseline read. The writer now ACKs completed ECU
  responses before sending the next TP2.0 application request; for the
  observed baseline response this is B5 for final response sequence 4.
2. After B5, F199 reached the ECU and returned 7F2E31. Native
  writeVagUdsValue checks metadata pre-writes with isFatalFail, so the writer
  has an explicit --allow-unsupported-metadata-prewrite option that may
  continue past F199/F198 7F2E31 only; the final 2E0600 coding write still
  must be positive and verified by 220600.
3. The latest attempt showed F199 7F2E31 repeated three times and then 300A8
  before the host could ACK it. The next test should use the new shorter
  metadata final-frame timing defaults so the first single-frame negative can
  be ACKed with B6 before deciding whether to continue.
```

These changes affect TP2.0 cleanup/timing and metadata pre-write fatality only;
they do not change the Carista-derived `2EF199`, `2EF198`, or `2E0600` payloads.

## No-Go List

Do not repeat these unless a new reason appears:

```text
blind full-coding 3B9A
old 1089 -> 2E0600 branch
positive-1A9B hunting as the main path
31B8-derived rawAddress guesses
any 27 security-access experiment
```

Optional `1A9B` comparison still exists:

```powershell
.\run_next_carista_validation.ps1 -Port COM10 -IncludeKwpComparison
```

Use it only as a comparison, not as the main repair path.
