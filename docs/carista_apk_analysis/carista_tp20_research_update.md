# Carista TP2.0 Research Update

Date: 2026-04-16

Purpose: capture the useful offline findings from Carista Android 9.8.2 for the VW Polo 6R / PQ25 BCM unit 09 cornering-light investigation. This is read-only research. The live scripts still block `27...`, `2E...`, `31...`, and `3B...` in scripted mode.

## High-confidence Carista protocol flow

Carista's Volkswagen TP2.0 logic was found in
`arm64_apk/lib/arm64-v8a/libCarista.so`, mainly in `VagCanCommunicator`. The raw
APK extraction was deleted after cleanup; the compact evidence is preserved in
`carista_relevant_evidence.md`.

For PQ25 unit 09, Carista follows this shape:

1. Open a TP2.0 channel to unit address `20` using CAN header `200`.
2. The open request matches the known-good live request:

```text
20C00010000301
```

3. The live Polo responded:

```text
22000D00003380301
```

Decoded:

```text
tester send header = 338
tester listen header = 300
```

4. After the channel is open, Carista builds this channel-parameter setup:

```text
A00194FF82FF
```

This came directly from disassembly of `VagCanCommunicator::establishEcuComm`. The proven live request is still `A00F8AFF32FF`, so `vw_tp20_readonly_probe.py` now keeps the Carista-exact payload as an explicit comparison mode instead of the default.

Update after the 2026-04-16 evening live mini-test:

```text
Trying A00194FF82FF first opened the channel but did not lead to a 1089
session response. Earlier successful sessions used A00F8AFF32FF first and
received 300A10F8AFF4FFF. The script now defaults back to the proven
single-request A00F8AFF32FF minimal profile and keeps A00194FF82FF as an
explicit --parameter-profile carista comparison.
```

5. Carista treats these TP2.0 control bytes specially:

```text
A3 = keep-alive packet; Carista logs and ignores it.
A8 = channel disconnected; Carista closes/clears the channel state.
B? = ACK packet.
9? = NACK packet.
```

This changes the interpretation of our live logs: `300A8` is not "no data"; it is a TP2.0 channel disconnect frame from the ECU.

## ACK behavior

Carista's `sendAck(seq, flush)` computes:

```text
ACK = B0 | ((seq + 1) & 0x0F)
```

So for an ECU data response with sequence `0`, Carista sends `B1`. That part of our experiment was conceptually correct.

The problem is now narrower: after the `1089` session response, our channel is still getting disconnected (`300A8`) when we try to continue.

## Comparison With Current Probe - 2026-04-24

What now matches Carista well enough to treat as likely correct:

```text
- TP2.0 open-channel target is unit 20, and the live car consistently opens there.
- The live Polo still accepts session 1089 and returns 5089 on the minimal path.
- Carista's read builders 1A9B and 1A9A are both plausible on this platform.
- A8 is correctly interpreted as ECU disconnect, not empty/no-data.
- B1 is correctly interpreted as the ACK for ECU sequence 0.
```

What the latest live work ruled out:

```text
- the exact Carista channel-parameter payload A00194FF82FF is not the practical fix on this car
- skipping the parameter read is not the fix
- the broader legacy parameter retry set is not the fix
- changing the first outgoing read counter to 0, 1, 2, or 3 is not the fix
- switching the first post-session read from 1A9B to 1A9A is not the fix
- removing the 100 ms post-session wait is not the fix
- preserving buffered UART bytes before the first read did not reveal any hidden late frames
```

The highest-confidence current live baseline is:

```text
open channel on unit 20
send minimal parameter request A00F8AFF32FF
receive 300A10F8AFF4FFF
send 1089 as TP2.0 counter 0
receive 3001000025089
send first post-session read as TP2.0 counter 1
receive immediate 300A8 disconnect for both 1A9B and 1A9A
```

Practical interpretation:

```text
The remaining mismatch with Carista is no longer "wrong adapter", "wrong unit",
or "wrong high-level read identifier".

The most likely missing piece is a communicator-level behavior around the first
post-session application request: control-flow ordering, intermediate control
handling, or receive-state handling that is not captured by the simple
request/wait/read shape in vw_tp20_readonly_probe.py.
```

## Carista read commands found in native code

Disassembly of exported command classes shows these request builders:

```text
GetVagCanEcuInfoCommand::getRequest       -> 1A9B
GetVagCanEcuListCommand::getRequest       -> 1A9F
ReadVagCanLongCodingCommand::getRequest   -> 1A9A
```

Carista simulator data also contains useful VAGCAN20 examples:

```text
1A9B -> ECU/component identity
1A91 -> identity/coding-related block
1A9A -> long coding / coding-related block
1A86 -> software/version dataset block
```

`vw_tp20_readonly_probe.py` now includes `1A9F` in the `carista_kwp` read profile.

## Carista write-coding evidence

The local native string extraction gives a plausible write path, but not a
fully proven one.

Useful hits from the deleted `strings/libCarista_strings.txt` dump:

```text
VagCanLongCodingSetting
VagOperationDelegate::writeVagCanCodingValue
ReadVagCanLongCodingCommand::getRequest
3B9A
```

Relevant line references:

```text
ReadVagCanLongCodingCommand symbols: around line 10008 and 16448
VagCanLongCodingSetting symbols: around line 8944
writeVagCanCodingValue symbol: line 7697
literal 3B9A: line 86816
VAGCAN20 1A9A simulator response: line 89629
```

Working interpretation:

```text
read long coding:  1A9A -> 5A9A + coding
write coding:      3B9A is real, but it is a structured setting/coding-fragment write
```

The same evidence is preserved in `carista_relevant_evidence.md`.

Deeper ARMv7 disassembly now rules out the old simple `3B9A + 30-byte long
coding` model as the main path. `WriteVagCodingCommand::getRequest` assembles:

```text
3B9A + 6-byte value + 4-byte coding raw address + coding-type-dependent tail
```

`VagOperationDelegate::getCodingRawAddress` derives that raw address from ECU
metadata. It is not just a hardcoded `0600` pasted into the command.

The 2026-04-27 pass added the setting-write chain to the evidence:

```text
ChangeSettingOperation::execute
VagOperationDelegate::insertValue
VagSetting::insertValue
ByteUtils::insertValue
VagCanLongCodingSetting constructors
WriteRawValuesOperation::execute
```

This confirms that a normal Carista UI toggle can be transformed into a small
coding value by the selected setting object before `WriteVagCodingCommand` is
created. It also leaves a real gap: the concrete setting object and the exact
value/raw-address vectors for `6R0937087K` cornering lights are still not
identified.

The next bridge pass tightened that model again:

```text
ChangeSettingOperation is constructed from shared_ptr<Setting> plus value bytes.
WriteRawValuesOperation is constructed from vector<pair<uint64, value-bytes>>.
OperationDelegate::changeSettingInternal is the bridge from Setting objects to brand-specific write logic.
VagOperationDelegate overrides insertValue, getSettingRawAddress, writeRawValue, and writeVagCanCodingValue.
VagCanSettings::getSettings() is a large compiled catalog in libCarista.so.
SettingRef JNI exposes getNameResIdNative and toEventStringNative, and SettingCategory exposes valuesNative.
```

Current interpretation:

```text
- The missing cornering-light tuple is now best understood as a compiled Setting-object problem, not just a missing raw uint64 key.
- SettingRef.nativeId remains a strong bridge candidate into that native catalog.
- The current evidence still does not prove that SettingRef.nativeId itself is the raw key passed to writeVagCanCodingValue.
```

Live writes attempted on 2026-04-25:

```text
3B9A + full target long coding: no useful response, readback unchanged
2E0600 + full target long coding: negative response 7F2E22
1089 session then 2E0600: immediate A8 disconnect on the first write frame
```

So the next field run should not repeat blind full-coding `3B9A` or the known
bad `1089 -> 2E0600` sequence as the default path.

## Adaptation/routine findings

The adaptation path is not plain `ADAPTxx` as a raw request. `ADAPTxx` appears only as a Carista simulator label.

Disassembly shows:

```text
StartReadVagCanRoutineCommand::getRequest       -> 31B8 + 16-bit id
StopReadVagCanRoutineCommand::getRequest        -> 32B8 + 16-bit id
PreReadVagCanAdaptationDataCommand::getRequest  -> 31BA + 16-bit id
ReadVagCanAdaptationDataCommand::getRequest     -> 31BA + 16-bit id
SetVagCanAdaptationChannelCommand::getRequest   -> 31B9 + 16-bit id + 1 byte
```

The specialized adaptation command constructors use:

```text
short adaptation basic id = 0x0103, likely request 31BA0103
long adaptation basic id  = 0x010A, likely request 31BA010A
```

The VAGCAN20 simulator contains:

```text
31B80000 -> 71B8010601020103010701080114
```

That looks like a Carista routine/discovery step, but it starts with `31`, so it remains blocked in our read-only scripts until you explicitly decide otherwise.

## PQ25 cornering-light coding context

Online VCDS/PQ25 references line up with the idea that Polo 6R cornering lights are mostly long-coding bits, not the newer PQ26/MQB `055C` / `055D` UDS light-channel records.

Older Polo 6R / PQ25 long-coding references pointed to these targets once `1A9A` works:

```text
Byte 12 bit 6 = Turn/Cornering Lights installed/active
Byte 21 bit 2 = Cornering/Turn Lights via turn signal active
Byte 21 bit 7 = Front Fog Lights with turn/cornering lights installed
Byte 19 bit 5 = Lamp diagnostics for fog/cornering/turn lights active (older, lower-confidence reference)
```

The most important bit for "cornering lights work at all" appears to be byte `12`, bit `6`.

One Carista VAGCAN20 simulator `1A9A` response contains this long-coding payload after the `5A9A` marker:

```text
000000000000B03730341012EC8F8F2600041800001400001400000000FF
```

In that sample:

```text
byte 12 = EC, so bit 6 is set
byte 21 = 14, so bit 2 is set
```

That does not prove the same values apply to this car, but it supports using `1A9A` as the next read target.

Sources checked:

- https://vwforum.ro/topic/82461-info-detaliere-coduri-modul-09-central-electronics/
- https://vag-repair.com/seat-ibiza-6j-vcds-ajout-options-cachees/
- https://www.vag-coding.net/vw/polo-5-6r/polo-5-6r-corner-lights/

## Next field-run recommendation

This section is now mostly historical. The 2026-04-24 live work narrowed the
main boundary further than the earlier field plan.

Current offline-first recommendation:

```text
1. Compare the Carista communicator flow around the first post-session request.
2. Derive one targeted sequencing change from that comparison.
3. Only then do another focused car run.
```

The earlier field commands are kept below as retained history.

Use the updated script with the Carista adapter on `COM10`:

```powershell
cd "c:\Users\victo\Downloads\2026-04-14 17-26-52\obd-on-pc"
python .\vw_tp20_readonly_probe.py --mode session_sweep --port COM10 --baud 38400 --parameter-profile minimal --run-id pq25_session_minimal
python .\vw_tp20_readonly_probe.py --mode pre_read_sweep --port COM10 --baud 38400 --parameter-profile minimal --session 1089 --read-command 1A9B --session-counters 0 --pre-read-sequences none,A3,A3+B1 --delays-ms 0,50 --read-counters 0,1,2 --stop-on-read-response --run-id pq25_pre_1A9B
python .\vw_tp20_readonly_probe.py --mode pre_read_sweep --port COM10 --baud 38400 --parameter-profile minimal --session 1089 --read-command 1A9B --session-counters 1,2 --pre-read-sequences none,A3 --delays-ms 0 --read-counters 1,2,3 --stop-on-read-response --run-id pq25_pre_1A9B_sctr
python .\vw_tp20_readonly_probe.py --mode pre_read_sweep --port COM10 --baud 38400 --parameter-profile minimal --session 1089 --read-command 1A9A --session-counters 0 --pre-read-sequences none,A3,A3+B1 --delays-ms 0,50 --read-counters 0,1,2 --stop-on-read-response --run-id pq25_pre_1A9A
python .\vw_tp20_readonly_probe.py --mode read_sweep --port COM10 --baud 38400 --skip-channel-parameters --session 1089 --ack none --delay-ms 100 --read-commands 1A9A --run-id pq25_1A9A_skip_params
```

The immediate goal is now narrower than before:

```text
1. get any post-session read past the recurring 300A8 disconnect
2. use 1A9B first as the least ambitious KWP identity read
3. only then retry 1A9A long coding
```
