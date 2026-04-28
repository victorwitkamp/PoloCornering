# PQ25 Long-Coding Change Plan

Purpose: prepare the offline steps after a successful `1A9A` read. This file
does not authorize writing to the car. The live scripts still block write,
security, and routine-control services.

## 2026-04-28 Update

The current best path is Carista's UDS DID `0600` writer, not the old `3B9A`
tuple hypothesis.

Recovered sequence:

```text
2EF199 + YYMMDD
2EF198 + workshop-code payload from 22F1A5
2E0600 + full 30-byte target coding
```

For this BCM, the latest live `22F1A5` payload was `0005F3C7E719`, and the
target coding remains:

```text
3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

Use `write_carista_uds_coding.py` for dry-run planning and guarded execution.
It re-reads `220600` before any write and verifies `220600` after the write.

## Inputs Needed

After the next car run, we need one of these:

```text
preferred current path: direct 220600 positive response, usually starting with 620600...
or, if the Carista/KWP path is later recovered, a 1A9A positive response starting with 5A9A...
or the extracted 30-byte long-coding payload after either prefix
```

Known-good reference currently stored locally:

```text
obd-on-pc/lcode/6R0937087K_cornering_enabled_longcoding.txt
```

Reference value:

```text
3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

## First Offline Check

If the next scan captures a raw `620600...` or `5A9A...` response, run:

```powershell
python .\decode_pq25_longcoding.py --coding 620600...
```

Then compare it against the known-good coding:

```powershell
python .\prepare_pq25_coding_change.py --current 5A9A...
```

For the current stable direct-read wrapper, the decoder reads the generated JSON
summary directly:

```powershell
python .\decode_pq25_longcoding.py --coding-file .\logs\pq25_next_baseline_220600_direct_read_summary.json --output .\logs\pq25_next_baseline_220600_settings_report.txt
```

## Candidate Change Profiles

The safest profile is report-only:

```powershell
python .\prepare_pq25_coding_change.py --current 5A9A... --profile report-only
```

Minimal cornering candidate:

```powershell
python .\prepare_pq25_coding_change.py --current 5A9A... --profile cornering-minimal
```

This only sets:

```text
byte 12 bit 6 = base fog-light cornering function
byte 21 bit 2 = turn-signal-triggered cornering assist
```

More aggressive reference-matching candidate:

```powershell
python .\prepare_pq25_coding_change.py --current 5A9A... --profile match-working-focus-bytes
```

This copies focus bytes from the known-good coding:

```text
byte 12
byte 13
byte 21
byte 22
```

Use that only if the minimal profile does not explain the current coding delta,
because byte `13` includes parking/CH/LH behavior and byte `22` is only
semi-trustworthy ADL context.

## Write Strategy

Do not write through the ELM script in the next session.

Preferred practical order:

```text
1. Capture current long coding.
2. Decode and compare locally.
3. Produce a proposed coding string.
4. Review exact byte changes.
5. Keep the Carista adapter as the primary read/verify path because it is the
  hardware that already reaches this BCM reliably.
6. Only attempt a write path that matches Carista's structured coding builder,
  or a separate proven tool that can operate on this BCM without guessing.
7. Immediately re-read coding and store the before/after strings.
```

Carista-first practical note:

```text
VCDS is still useful as an offline long-coding helper reference, but the local
VCDS installer only exposed generic helper families. The live adapter path that
already works on this car is Carista/TP2.0 unit 20 on COM10.
```

The blocked raw diagnostic services remain:

```text
27...  security access
2E...  UDS write data
31...  routine control
3B...  KWP write data
```

Those should not be enabled in the Python probe unless we explicitly decide to
build a separate write tool after the read path is proven and the exact coding
payload format is verified.

## Prepared Writer

A separate guarded writer is prepared here:

```text
obd-on-pc/write_pq25_longcoding.py
```

It does not alter the read-only probe. It defaults to dry-run and prepares the
guarded full-coding write shapes that have been considered:

```text
2E0600 + 30-byte long coding
obsolete: 3B9A + 30-byte long coding
```

The Carista-derived evidence behind this hypothesis is:

```text
- Carista treats this platform as VAGCAN20 / TP2.0 unit 20, matching the live
  open-channel result from the Polo BCM.
- Carista's ReadVagCanLongCodingCommand request is 1A9A, with 5A9A... simulator
  responses that look like long-coding payloads.
- Carista native symbols include VagCanLongCodingSetting and
  VagOperationDelegate::writeVagCanCodingValue.
- The same native string corpus contained a literal 3B9A; the raw dump was
  deleted after cleanup and the relevant hit is preserved in
  carista_apk_analysis/carista_relevant_evidence.md.
- 2026-04-25 reanalysis of WriteVagCodingCommand::getRequest shows 3B9A is
  structured as value + raw-address + coding-type + length/data, not simply
  3B9A + complete long coding.
```

This changes the practical write plan. The simple 3B9A full-coding attempt is
now considered a failed/obsolete hypothesis; the live BCM gave no useful reply.
The full-coding UDS shape `2E0600 + coding` was parsed by the BCM, but returned
`7F2E22`, meaning the missing piece is the correct precondition/session rather
than TP2.0 framing.

The next live retry must also account for this additional boundary:

```text
session 1089 + did-0600 is currently a known-bad path
```

Live logs showed:

```text
1089 -> 5089 was positive
first did-0600 write frame after that caused immediate A8 disconnect
```

So the current writer should not default to the 1089 path. The only write shape
that reached a meaningful ECU decision was direct `2E0600 + coding`, which was
then rejected with `7F2E22`.

## Carista-First Next Attempt

For the next field run, prioritize what the Carista research actually proved:

```text
1. Use the Carista adapter on COM10.
2. Capture a fresh direct 220600 read before changing anything.
3. Generate the smallest intentional target coding delta offline.
4. Do not reuse blind 3B9A full-coding frames.
5. Do not reuse session 1089 as the default write preamble.
6. If another raw write test is chosen, treat direct 2E0600 as the only parsed
   baseline and compare it against Carista's coding raw-address/coding-type flow.
7. Re-read 220600 immediately after any attempt.
```

What Carista now tells us about the missing piece:

```text
- it has an ECU-specific coding raw address
- it distinguishes single-coding vs multi-coding
- it wraps the write in a structured setting builder instead of sending the
  whole long-coding string as a blind blob
```

Current live-capture decode after the failed write attempts:

```text
current coding   = 3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000
known-good coding = 3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
only differing bytes = 12 and 21
byte 12 bit 6 is currently clear
byte 21 bit 2 is currently clear
byte 13 and byte 22 already match the known-good coding
```

That means the next coding target is still small and well-bounded even though
the write transport is not solved yet.

The deeper constructor/request disassembly narrows that builder further:

```text
- fixed write literal is 3B9A
- constructor expects a 6-byte value vector
- constructor expects a 4-byte coding raw-address vector
- one coding-type branch expects a 3-byte trailing vector
- the request tail is keyed by a coding-type lookup table, not just raw coding length
```

So the current Carista-shaped model is:

```text
3B9A + 6-byte value + 4-byte raw address + coding-type-dependent tail
```

The raw-address getter path now also shows that Carista does not appear to use a
single blind constant for every ECU. `VagOperationDelegate::getCodingRawAddress`
first resolves ECU metadata, then branches through coding-family-dependent raw-
address formatting before returning the 4-byte address object used by the write
builder.

That is why the current full-blob writer is only useful as a negative-result
boundary marker. It does not match the Carista builder closely enough to be the
main repair path.

That makes the next useful engineering target clear: derive Carista's exact
coding builder before trusting another scripted write attempt.

Because that payload is too large for one CAN frame, the writer builds TP2.0
multi-frame tester frames. For the synthetic earlier delta `2C -> 6C` and
`A2 -> A6`, the dry-run command is:

```powershell
python .\write_pq25_longcoding.py --expected-current 3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000 --target 3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

The default dry-run now uses the `did-0600` method because it is the only
full-coding write shape the BCM parsed live. Repeating the obsolete full-coding
`3B9A` shape requires an explicit extra override.

Execution requires all of these:

```text
--execute
--confirm-target <same target string>
--i-understand-this-writes-bcm-coding
```

Do not execute it until:

```text
1. a fresh 1A9A current coding read has been captured,
2. the proposed target has been generated and reviewed,
3. the byte diff is small and intentional,
4. the car is stable on battery/engine power,
5. there is a backup path to restore the original coding.
```
