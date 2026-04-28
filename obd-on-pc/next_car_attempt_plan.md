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
  --coding 3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000 `
  --workshop-code 0005F3C7E719 `
  --confirm-target 3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000 `
  --execute `
  --i-understand-this-writes-bcm-coding
```

The writer always re-reads `220600` before writing and refuses to continue if
the live coding differs from the expected current coding. After the write
sequence it immediately re-reads `220600` and requires exact target match.

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
