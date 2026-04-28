# Carista Relevant Evidence

This file keeps the useful Carista findings after deleting the raw APK/XAPK,
extracted APK folders, and full string dumps.

## Source

Carista OBD2 Android 9.8.2 / package `com.prizmos.carista`.

Original raw material was extracted locally, inspected, and then deleted during
cleanup:

```text
Carista_OBD2_9.8.2_APKPure.xapk
xapk_extracted/
base_apk/
arm64_apk/
strings/
```

## TP2.0 Channel

Carista's Volkswagen TP2.0 logic matched the live Polo PQ25 BCM behavior:

```text
unit 09 / VAGCAN20 / TP2.0 address: 20
open request observed live: 20C00010000301
open response observed live: 22000D00003380301
decoded send header: 338
decoded listen header: 300
```

Carista exact channel-parameter setup found from the native code:

```text
A00194FF82FF
```

Known-good minimal setup for this Polo remains:

```text
A00F8AFF32FF
```

## TP2.0 Control Frames

Native behavior and live logs line up with these labels:

```text
A3 = TP2.0 keep-alive; Carista ignores it
A8 = TP2.0 disconnect/close frame
B? = TP2.0 ACK
9? = TP2.0 NACK
ACK rule = B0 | ((sequence + 1) & 0x0F)
```

## Read Commands

Carista native command builders identified:

```text
GetVagCanEcuInfoCommand::getRequest       -> 1A9B
GetVagCanEcuListCommand::getRequest       -> 1A9F
ReadVagCanLongCodingCommand::getRequest   -> 1A9A
```

Simulator examples found for VAGCAN20:

```text
ECU VAGCAN20 1A9B: 5A9B314B30393337303439532020B037303410000000000000000000426F72646E65747A2D534720312E302048333020
ECU VAGCAN20 1A91: 5A910D314B3039333730343953202A04303633033236FF
ECU VAGCAN20 1A9A: 5A9A000000000000B03730341012EC8F8F2600041800001400001400000000FF
ECU VAGCAN20 1A86: 5A860F3030303030303031313032373039204256422D39303632322E30392E303430304833303030303037303431343031FF
```

## Write-Coding Clue

Native symbols and strings found in the Carista extraction:

```text
VagCanLongCodingSetting
VagOperationDelegate::writeVagCanCodingValue
ReadVagCanLongCodingCommand::getRequest
literal 3B9A
```

Working interpretation:

```text
read long coding:  1A9A -> 5A9A + coding
write coding:      3B9A is real, but it is a structured setting write
```

Reanalysis on 2026-04-25 found that
`WriteVagCodingCommand::getRequest` starts with `3B9A`, but it does not simply
append the complete BCM long-coding string. The native builder appends a coding
value, a raw coding address, a coding-type byte, and additional length/data
fields. For most branches it also appends `FF`.

Deeper ARMv7 `libCarista.so` disassembly on 2026-04-25 tightened that further.
The relevant resolved symbols are:

```text
ReadVagCanLongCodingCommand::getRequest
WriteVagCodingCommand::WriteVagCodingCommand
WriteVagCodingCommand::getRequest
VagOperationDelegate::getCodingRawAddress
VagOperationDelegate::writeVagCanCodingValue
```

Concrete findings from that pass:

```text
Read builder literal:  1A9A
Write builder literal: 3B9A
coding-type lookup bytes: 10 10 03 10 10 31
constructor checks: 6-byte value vector, 4-byte raw-address vector
special branch check: 3-byte trailing vector for one coding type
```

Corrected Ghidra decompilation on 2026-04-28 fixed the earlier address-boundary problem. Ghidra loads this ELF with a `+0x10000` image-base delta; the reliable exports are the files whose headers show both ELF and Ghidra addresses in `carista_apk_analysis/ghidra_exports`.

The corrected `WriteVagCodingCommand::getRequest` semantics are:

```text
3B9A + value6 + rawAddress4 + suffix

type 2 suffix:     selector + 3-byte tail
non-type-2 suffix: selector + (tail length + 1) + tail bytes + FF
```

The corrected constructor stores:

```text
this + 0x10 = 6-byte value vector
this + 0x1c = shared 4-byte raw-address/component-id vector
this + 0x24 = coding type enum
this + 0x28 = shared tail/short-coding vector
```

Additional getter-path findings from the next disassembly pass:

```text
GetEcuInfoOperation::getCodingRawAddress(uint16_t) dispatches through ECU-info metadata
VagOperationDelegate::getCodingRawAddress(Ecu*, uint16_t) branches on that metadata before formatting the raw address
one branch selects coding-family widths 2 or 3
another branch falls back through a different helper path and a wider formatter path
```

That strengthens one important constraint: the 4-byte raw-address object used by
the write builder is ECU-family-derived metadata, not just a hardcoded `0600`
literal pasted into every request.

The next symbol pass also corrected the apparent write-call signature:

```text
VagOperationDelegate::writeVagCanCodingValue(unsigned long long, vector<byte>)
```

Practical implications from that disassembly slice:

```text
- the function caches the raw value by a 64-bit key before building the command
- ECU info is read/cached before the command is built
- one virtual helper is called with that key and its result is normalized to coding-family values 2 or 3
- one sentinel path forces that family value to 5 instead
- the 4-byte raw-address vector is taken from parsed `VagEcuInfo` metadata (`coding-info + 0x2c` in the corrected decompile)
- the write builder is therefore keyed by a higher-level setting identifier plus ECU metadata, not by a direct raw full-coding blob API
```

The next validated bridge pass widened that model further:

```text
ChangeSettingOperation(shared_ptr<Setting>, vector<byte>)
WriteRawValuesOperation(vector<pair<uint64, vector<byte>>>)
OperationDelegate::changeSettingInternal(shared_ptr<Setting>, vector<byte>, Progress)
VagOperationDelegate::insertValue(...)
VagOperationDelegate::getSettingRawAddress(shared_ptr<Setting>)
VagOperationDelegate::writeRawValue(uint64, vector<byte>, Progress)
VagOperationDelegate::writeVagCanCodingValue(uint64, vector<byte>)
VagCanSettings::getSettings() size ~= 333252 bytes
SettingRef_getNameResIdNative / SettingRef_toEventStringNative / SettingCategory_valuesNative
```

Practical implications from that bridge pass:

```text
- Carista's normal setting-change path stays on shared_ptr<Setting> objects until OperationDelegate::changeSettingInternal.
- Raw uint64 writes are a separate lower-level path, not the only write model exposed by the app.
- The strongest remaining offline target is now the compiled VagCanSettings catalog plus the SettingRef JNI bridge.
- SettingRef.nativeId is still only a bridge candidate; it is not yet proven to be the same thing as the raw write key used by writeVagCanCodingValue.
```

The current best request-shape reconstruction is:

```text
3B9A
+ 6-byte coding value
+ 4-byte coding raw address
+ coding-type-dependent tail
```

That is materially different from both previous blind hypotheses:

```text
not: 3B9A + full 30-byte long coding
not: 2E0600 + full 30-byte long coding shaped to mimic Carista
```

The strongest practical interpretation now is that Carista writes a structured
setting or coding fragment, not a full BCM coding blob.

Latest writer-flow finding:

```text
ChangeSettingOperation
-> OperationDelegate::changeSettingInternal
-> VagOperationDelegate::insertValue
-> VagOperationDelegate::getSettingRawAddress
-> VagOperationDelegate::writeRawValue
-> VagOperationDelegate::writeVagCanCodingValue
-> WriteVagCodingCommand
```

`writeVagCanCodingValue` takes a 64-bit raw-value key plus compact value bytes,
not a 30-byte long-coding blob. It caches by that key, reads/caches ECU metadata,
uses the parsed coding-info raw-address vector, preserves coding type 2,
normalizes most other coding to type 3, and has a sentinel path that forces type
5. No corrected native path was found that derives the missing rawAddress4/tail
from the `220600` long-coding bytes alone.

Dex-side bridge check with Androguard confirmed:

```text
SettingRef.nativeId
ChangeSettingOperation.initNative(Setting, byte[], ReadValuesOperation)
GetEcuInfoOperation.getCodingRawAddress(short)
GetEcuInfoOperation.supportsSingleCoding()
GetEcuInfoOperation.supportsMultiCoding()
```

Additional Java/smali bridge checks from the apktool decode tightened that
boundary further:

```text
ReadValuesOperation.getAvailableItems() -> Map<SettingCategory, Setting[]>
CheckSettingsOperation.initNative(Operation) -> native availability entry point
Setting is the full abstract model with getEcu/getInstruction/getInterpretation/getNameResId/toEventString
SettingCategory.getValues() -> valuesNative(); equality is based on nativeId
ChangeSettingOperation is created from Setting + requested byte[] + originating ReadValuesOperation
SettingRef is a thin Parcelable/nativeId handle, but the normal write path consumes Setting, not SettingRef
```

Practical implications from that pass:

```text
- Java does not appear to decide BCM-specific setting availability itself.
- The actual per-car setting list is returned from native code through CheckSettingsOperation / ReadValuesOperation.
- The UI groups that native map by SettingCategory nativeId and then reads per-setting current bytes through getSettingValue(setting).
- The requested compact byte[] already exists on the Java side before ChangeSettingOperation crosses into the native writer.
- The remaining bridge is therefore: native availability/catalog selection + how the UI-selected value bytes correspond to the final insertValue/write tuple.
```

The next decoded-smali pass recovered that UI-selected byte encoding path too:

```text
wr/f + zr/f build the change-setting UI model and later convert the chosen UI state into an (oldValue, newValue) byte-pair.

MultipleChoiceInterpretation:
- exposes possibleValues[]
- each PossibleValue is (value:J, nameResId:String)
- Java encodes value:J with mi/t1.U(J) -> 8-byte big-endian
- Java trims that to the original setting-value length with Luc/d.o(..., 8-len, 8)
- the selected option's trimmed byte[] becomes the requested newValue

NumericalInterpretation:
- Java computes numericValue = start + increment * selectedIndex
- Java encodes numericValue with mi/t1.U(J)
- Java trims to the original setting-value length with the same right-trim rule
- that trimmed byte[] becomes the requested newValue

TextInterpretation:
- Java converts the user-entered string with StringUtils.getBytes(text)
- those bytes become the requested newValue

mi/t1.W([B) decodes existing values as big-endian unsigned numbers
mi/t1.U(J) encodes big-endian 8-byte numbers
```

This is the strongest offline evidence so far that the compact requested
setting value is fully decided on the Java side once the native Setting and its
Interpretation are available.

So the remaining missing write-tuple inputs are tied to the native
Setting/catalog entry and ECU metadata.

## PQ25 Cornering Setting Map

Offline static mapping was added here:

```text
carista_apk_analysis/map_carista_pq25_cornering.py
carista_apk_analysis/carista_pq25_cornering_static_map.md
carista_apk_analysis/carista_pq25_cornering_static_map.json
```

The mapper confirms that the relevant Carista labels exist in both decoded
resources and `libCarista.so`, including:

```text
car_setting_cornering_lights_via_fogs
car_setting_cornering_lights_via_fogs_experimental
car_setting_use_cornering_lights
car_setting_cornerig_lights_with_turn_signal
car_setting_cornering_lights_with_turn_signals
```

No simple direct native xrefs were found from those string keys to the giant
`VagCanSettings::getSettings()` catalog. That means the static bridge is still
not complete, but the practical map for this BCM is now narrow:

```text
byte 12 bit 6 = Carista fog-light cornering / use fogs for cornering
byte 21 bit 2 = Carista turn-signal cornering trigger
```

Current live coding has both bits clear. The known-good cornering-enabled coding
has both bits set.

Additional native symbol extraction from the reacquired `libCarista.so` kept
the same conclusion and tightened the next reverse-engineering target:

```text
GetEcuInfoOperation_getCodingRawAddress
GetEcuInfoOperation_supportsSingleCoding
GetEcuInfoOperation_supportsMultiCoding
VagOperationDelegate::getCodingRawAddress
VagOperationDelegate::writeVagCanCodingValue
VagEcuInfo::CodingType
```

Working interpretation:

```text
- Carista resolves a coding raw address per ECU instead of assuming one fixed write target.
- Carista distinguishes at least single-coding vs multi-coding flows.
- The successful live parse of 2E0600 is useful because it matches the obvious raw address,
  but it is still missing Carista's coding-type and builder-specific framing/state.
```

Live result: the simple `3B9A + full 30-byte coding` attempt produced no useful
reply and readback stayed unchanged. Treat that shape as obsolete unless it is
being retested deliberately.

Live result: the direct `2E0600 + 30-byte coding` attempt reached a parsed
negative response `7F2E22`, which means the BCM recognized the service/address
but rejected the current conditions. The `1089` session retry was worse: the
BCM sent an immediate `A8` disconnect on the first write frame.

Practical Carista-first conclusion:

```text
1. Keep using the Carista adapter/TP2.0 unit 20 path for reads and verification.
2. Do not repeat blind 3B9A or default 1089-based did-0600 writes.
3. For this live BCM, prioritize the UDS type-8 coding path over 3B9A metadata hunting.
4. The recovered Carista UDS sequence is F199 date, F198 workshop code, then 0600 coding.
```

## Updated UDS Write-Path Evidence - 2026-04-28

The later Ghidra pass recovered the missing part of the UDS branch:

```text
VagUdsCodingSetting(ecu, vector) -> setting type 8, DID 0600
writeRawValue type 8             -> writeVagUdsValue
WriteDataByIdentifierCommand     -> 2E + DID + payload
writeVagUdsValue                 -> F199 date, F198 workshop code, then requested DID
```

`GetVagUdsEcuWorkshopCodeCommand` reads DID `F1A5` and requires exactly six
payload bytes. The live positive read was:

```text
22F1A5 -> 62F1A50005F3C7E719
```

So the recovered Carista-shaped write candidate for the known target coding is:

```text
2EF199YYMMDD
2EF1980005F3C7E719
2E06003AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

The prepared guarded writer is:

```text
obd-on-pc/write_carista_uds_coding.py
```

It performs a fresh `220600` read before writing, refuses unexpected current
coding, sends the recovered Carista UDS sequence, then verifies `220600`.

## Offline 31B8 Simulator Metadata Pass

The no-phone static pass added a repeatable analyzer for Carista's embedded
VAGCAN20 simulator records:

```text
carista_apk_analysis/analyze_carista_offline_tuple_candidates.py
carista_apk_analysis/carista_offline_tuple_candidate_report.md
carista_apk_analysis/carista_offline_tuple_candidate_report.json
```

That analyzer reads `libCarista.so` from the extracted split path, the ARM split
APK, or the XAPK, then parses the embedded `ECU VAGCAN20 ...` records.

The two useful `31B80000` metadata responses are:

```text
1K0937049S-style profile: 71B8010301040106010801020107
    decoded shorts: 0103 0104 0106 0108 0102 0107

BCM25/5C0937087E profile: 71B8010601020103010701080114
    decoded shorts: 0106 0102 0103 0107 0108 0114
```

The BCM25 profile is the closest embedded analogue because it also contains a
direct `220600` long-coding sample and identifies as central electrics:

```text
22F187 -> 5C0937087E
22F191 -> 5C0937087A
22F197 -> BCM25 JLB H3
220600 -> 30-byte coding sample
```

Updated interpretation after the deeper parser pass:

```text
31B80000 / 71B8 exposes compact ECU-list coding-address shorts.
It does not directly populate the 4-byte rawAddress4 consumed by WriteVagCodingCommand.
The final rawAddress4/coding selector/tail come from positive 1A9B / 5A9B ECU-info parsing.
```

The recovered `GetVagCanEcuInfoCommand::processEcuInfo` offsets, after
stripping the positive `5A9B` prefix, are:

```text
payload[0x0c:0x10] -> rawAddress4
payload[0x10]      -> coding selector
payload[0x11:0x14] -> tail for type-2/type-4 selector branches
payload[0x14:0x1a] -> stored 6-byte coding value
```

The embedded 1K0937049S-style simulator proves that parser with a real positive
`1A9B` response: rawAddress4 `B0373034`, selector `10`, Carista coding type
`3`, empty tail, and writer suffix `0301FF`.

The closest BCM25 profile has direct `220600` data and the `0106` short in
`31B8`, but its `1A9B` response is negative. That means `00200106` is no longer
a defensible rawAddress4 proof; keep the generated examples only as rejected
proof attempts, not write candidates.

For the actual `6R0937087K` evidence in this workspace, the proven final pieces
remain only:

```text
base fog value6:     6C680ED000C8
turn-signal value6:  412F60A60000
```

The complete tuple still requires a positive `1A9B` for this ECU, or a native
catalog/data-flow equivalent that proves those same metadata bytes.

## In-Car Tuple-Proof Read Attempt - 2026-04-28

The prepared no-phone tuple-proof workflow was run read-only against the car on
`COM10`.

Fresh direct `220600` still showed the known broken coding:

```text
3AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000
```

The proof target, positive `5A9B`, was not captured:

```text
direct 1A9B: 7F1A11 on one run, no response on another
1089 + pre-read 1A9B variants: no 5A9B
fallback session-counter variants: no 5A9B
skip-parameters 1089/read_sweep 1A9B: no 5A9B
direct carista_kwp profile: 1A9F/1A9A no response; 1A91/1A86 7F1A11
```

Evidence files:

```text
obd-on-pc/logs/pq25_tuple_proof_read_report.md
obd-on-pc/logs/pq25_tuple_proof_read_report.json
obd-on-pc/logs/pq25_tuple_proof_direct_carista_kwp_direct_read_summary.json
```

This is negative evidence for the current adapter-only `1A9B` sequencing path,
not proof of a complete tuple. The missing metadata must now come from a new
offline sequencing hypothesis, native catalog/data-flow recovery, or a future
phone/Carista trace.

## Adaptation/Routine Clues

Carista native command builders identified:

```text
StartReadVagCanRoutineCommand::getRequest       -> 31B8 + 16-bit id
StopReadVagCanRoutineCommand::getRequest        -> 32B8 + 16-bit id
PreReadVagCanAdaptationDataCommand::getRequest  -> 31BA + 16-bit id
ReadVagCanAdaptationDataCommand::getRequest     -> 31BA + 16-bit id
SetVagCanAdaptationChannelCommand::getRequest   -> 31B9 + 16-bit id + 1 byte
```

These remain blocked in read-only scripts.
