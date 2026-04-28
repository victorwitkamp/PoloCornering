# Carista Write Tuple Recovery

This is an offline static report. It does not use a phone trace.

## Resolved Native Anchors

| Symbol | Address | Size |
|---|---:|---:|
| ReadVagCanLongCodingCommand::getRequest | `0x00D0249C` | 20 |
| WriteVagCodingCommand::getRequest | `0x00D032BC` | 300 |
| WriteVagCodingCommand::ctor | `0x00D03048` | 552 |
| VagSetting::insertValue | `0x0113B246` | 22 |
| ByteUtils::insertValue | `0x012D8890` | 344 |
| VagOperationDelegate::getSettingRawAddress | `0x012620EC` | 204 |
| VagOperationDelegate::writeVagCanCodingValue | `0x01263CEC` | 324 |
| VagCanLongCodingSetting::ctor_bit | `0x0104F500` | 120 |
| VagCanLongCodingSetting::ctor_vector | `0x0104F484` | 124 |

## Request Builders

- Long-coding read literal resolves to `1A9A` at `0x007381E6`.
- Write-coding literal resolves to `3B9A` at `0x008C8D6C`.
- Corrected Ghidra headless exports are generated in `carista_apk_analysis/ghidra_exports`.
- Ghidra loads this ELF with a `+0x10000` image-base delta, so the exporter records both ELF symbol addresses and Ghidra addresses.
- Coding-type lookup bytes for coding types `0..5` are: `00 10 10 03 10 10`.

Static request shape recovered from `WriteVagCodingCommand::getRequest`:

```text
3B9A
+ 6-byte coding value vector
+ 4-byte coding raw-address vector
+ coding-type-dependent tail
```

The constructor enforces:

```text
value vector length       = 6
raw-address vector length = 4
coding type 2 tail length = 3
```

Corrected `WriteVagCodingCommand::getRequest` pseudocode proves the suffix split:

```text
type 2:     selector byte + 3-byte tail vector
other type: selector byte + (tail length + 1) + tail bytes + FF
```

The constructor stores the fields used by the serializer at fixed offsets:

```text
this + 0x10 -> 6-byte value vector
this + 0x1c -> shared 4-byte raw-address/component-id vector
this + 0x24 -> coding type enum
this + 0x28 -> shared tail/short-coding vector
```

## Insert-Value Model

`VagSetting::insertValue` forwards into `ByteUtils::insertValue`. The recovered model is:

```text
result = copy(current_raw_value)
for each byte in setting mask:
    result[offset + i] = (current[offset + i] & ~mask[i]) | masked_requested_value[i]
```

The important object fields used by that path are:

```text
VagSetting + 0x18 = byte offset inside the raw value
VagSetting + 0x1C = mask/vector object used for the setting
```

For a one-bit long-coding setting, the mask vector is expected to contain the target bit mask.

## Writer Flow Findings

The lower writer path now looks like this:

```text
ChangeSettingOperation
-> OperationDelegate::changeSettingInternal
-> VagOperationDelegate::insertValue
-> VagOperationDelegate::getSettingRawAddress
-> VagOperationDelegate::writeRawValue
-> VagOperationDelegate::writeVagCanCodingValue
-> WriteVagCodingCommand
```

`writeVagCanCodingValue` does not receive a raw full-coding blob. It receives a 64-bit raw-value key plus the compact value vector. It then resolves ECU coding metadata before constructing `WriteVagCodingCommand`.

Corrected Ghidra pseudocode of `writeVagCanCodingValue` shows:

```text
- the raw value is cached by the 64-bit key before the write command is built
- ECU metadata is queried/cached before the command is built
- coding type 2 is preserved
- non-type-2 coding is normalized to type 3
- a sentinel metadata path forces coding type 5
- the final command still goes through the 6-byte value + 4-byte raw-address + tail constructor
- the 4-byte vector passed to the constructor is taken from parsed `VagEcuInfo` metadata, not from the visible `0600` DID
```

The important native bridge is now explicit:

```text
writeVagCanCodingValue(...)
-> read/cached VagEcuInfo for the target ECU
-> use metadata at the coding-info object (`+0x2c`) as the 4-byte raw-address vector
-> pass coding type and tail vector to WriteVagCodingCommand
```

`readEcuInfoCached` first checks whether the cached `VagEcuInfo` already contains the required/optional masks. If not, it calls the live ECU-info reader and stores the result. `readVagCanEcuInfo` runs `GetVagCanEcuInfoCommand`, validates the returned `VagEcuInfoWithCoding`, and stores coding raw-address metadata for the main ECU and submodules. This is a cache/read path, not a static fallback table that can derive the tuple from `220600` alone.

The Java/Dex bridge confirms the same high-level boundary:

```text
SettingRef.nativeId exists on the Java side
ChangeSettingOperation.initNative(Setting, byte[], ReadValuesOperation) creates the native operation
GetEcuInfoOperation exposes getCodingRawAddress(short), supportsSingleCoding(), and supportsMultiCoding()
```

## Raw-Address Model

`VagOperationDelegate::getSettingRawAddress` branches on `VagSetting::Type` from the setting object:

```text
type 9 or 5 -> submodule-aware raw-address helper
type 4      -> alternate raw-address helper
other types -> base raw-address/coding-address path
```

The long-coding constructors feed the VAG CAN coding-setting base with type `3`, so this BCM is expected to use the base coding-address path unless a catalog wrapper changes the type.

Important implication: the missing `rawAddress4` is probably not just the visible DID `0600`. The live `2E0600 + full coding` attempt was parsed by the BCM but rejected with `7F2E22`, while the blind `3B9A + 30-byte coding` attempt produced no useful response. Those results fit the compact Carista tuple model.

## Current Coding Chunks

Carista's writer validates a 6-byte coding value. Splitting the 30-byte BCM coding into 6-byte chunks gives two changed chunks between current and known-good:

| Chunk | Bytes | Current 6-byte value | Target 6-byte value | Changed bits |
|---:|---:|---|---|---|
| 2 | 12-17 | `2C680ED000C8` | `6C680ED000C8` | byte 12 bit 6: clear -> set |
| 3 | 18-23 | `412F60A20000` | `412F60A60000` | byte 21 bit 2: clear -> set |

## Tuple Candidates To Recover

The value side is now narrow if the 6-byte chunk model is correct:

```text
base fog-cornering tuple value:  6C680ED000C8
turn-signal tuple value:        412F60A60000
```

The still-missing pieces are the 4-byte raw-address vectors and exact tail bytes for those chunks. Those are derived from ECU metadata and Carista's setting catalog, not from the visible long-coding string alone.

The latest Ghidra pass corrected the raw-address proof boundary. Static decompilation shows that `WriteVagCodingCommand` receives its 4-byte rawAddress4, coding selector, and tail vector through parsed/cached `VagEcuInfo` populated by positive `1A9B` / `5A9B` ECU-info parsing, not directly from the `31B80000` ECU-list response and not from the visible `220600` long-coding DID.

Recovered `1A9B` parser offsets after stripping the positive `5A9B` prefix:

```text
payload[0x0c:0x10] -> rawAddress4
payload[0x10]      -> coding selector
payload[0x11:0x14] -> tail for type-2/type-4 selector branches
payload[0x14:0x1a] -> stored 6-byte coding value
```

The embedded 1K0937049S-style simulator has a positive `1A9B` and proves the parser with rawAddress4 `B0373034`, selector `10`, coding type `3`, empty tail, and suffix `0301FF`. The BCM25/5C0937087E simulator has direct `220600` coding and a `31B80000` list, but its `1A9B` response is negative, so it does not prove the final rawAddress4 for that profile either.

The actual `6R0937087K` workspace evidence has direct `220600` coding but no positive `1A9B` / `5A9B` response. The corrected native path makes the consequence stronger: the full `3B9A` tuple for this car is not recoverable from current coding alone. Only the two target value6 chunks are proven until the missing `VagEcuInfo` metadata bytes are recovered.

The dedicated offline report is generated by:

```text
carista_apk_analysis/analyze_carista_offline_tuple_candidates.py
carista_offline_tuple_candidate_report.md
```

## Next Static Target

The next offline target is now narrower: recover a positive `1A9B` response for the actual `6R0937087K` or reconstruct the same bytes from a native catalog/data-flow path. In parallel, recover the `VagCanLongCodingSetting` catalog entries around byte 12 bit 6 and byte 21 bit 2. The fields to recover for each entry are:

```text
setting name key
VagSetting type
raw-address/coding-address key
byte offset
mask vector
interpretation values
coding tail bytes used by WriteVagCodingCommand
```

Without an actual positive `1A9B` metadata bridge, a native catalog equivalent, or a phone trace, do not treat any complete `3B9A` tuple as proven.

## Static Catalog Boundary

Additional static checks found no simple raw pointer table from the Carista resource strings or Android numeric resource ids into the native setting catalog. A branch scan from `VagCanSettings::getSettings()` to the named `VagCanLongCodingSetting` constructor/emplace wrappers also found no direct call sites.

A broader `VagCanSettings::getSettings()` disassembly scan also found no direct `car_setting_*` C-string references. The `car_setting_*` names are present in `libCarista.so`, but the setting catalog does not expose them as a straightforward label -> constructor -> write tuple table.

Practical meaning:

```text
The catalog is not exposed as an easy string -> constructor -> tuple table.
The remaining tuple inputs likely require deeper data-flow reconstruction or a phone trace.
```

An offline composer exists for the final step once the missing bytes are recovered:

```text
obd-on-pc/compose_carista_3b9a_tuple.py
```
