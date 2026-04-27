# Carista Reverse-Engineering Status

Date: 2026-04-27

Purpose: consolidate the Carista reverse-engineering work for the VW Polo 6R /
PQ25 BCM cornering-light investigation so the offline path can continue even
while the phone is unavailable.

## Scope

The working goal is not generic APK reversing. The target is the exact Carista
write path for PQ25 cornering-light settings on BCM `6R0937087K`, using the
Carista adapter and Carista's own setting model instead of another blind full-
coding write attempt.

## What Was Done

### Car / protocol groundwork

- The live Carista adapter path to BCM unit 09 was stabilized through TP2.0
  unit `20`.
- The proven live TP2.0 channel open is:

```text
20C00010000301
```

- The live car response decoded to:

```text
send header   = 338
listen header = 300
```

- The direct long-coding read path is stable through:

```text
220600
```

- The current long coding was captured and compared against the known-good
  cornering-enabled coding. The remaining delta is two bits:

```text
byte 12 bit 6
byte 21 bit 2
```

### Carista APK / XAPK acquisition and unpacking

- Carista Android `9.8.2` was reacquired and unpacked as a split bundle.
- The active recovered bundle is under:

```text
carista_apk_analysis/reacquire_20260424/xapk_unpacked
```

- The important split layout is:

```text
com.prizmos.carista.apk
config.armeabi_v7a.apk
config.hdpi.apk
```

- The currently relevant native library is:

```text
reacquire_20260424/split_armv7_unpacked/lib/armeabi-v7a/libCarista.so
```

- LIEF confirmed that this library is `ARCH.ARM` / `ELF32`, which established
  that the real patch and analysis target is the ARMv7 split, not an arm64
  build.

### Static reverse-engineering of Carista's VAG path

- The high-level Volkswagen path in Carista was confirmed to live mainly in
  `libCarista.so`, not plain Java/Kotlin.
- Relevant VAG symbols and simulator content confirmed that PQ25 central
  electrics is handled through Carista's `VAGCAN20` / TP2.0 path, not the newer
  `70E` UDS path used on newer platforms.
- Native analysis recovered these key request builders:

```text
1A9B = ECU/component info
1A9F = ECU list/info
1A9A = long coding read
3B9A = real write-coding family literal
```

- TP2.0 control behavior was clarified:

```text
A3 = keep-alive
A8 = disconnect
B? = ACK
9? = NACK
```

- ACK behavior was recovered as:

```text
B0 | ((seq + 1) & 0x0F)
```

- The exact Carista channel-parameter payload was extracted from native code:

```text
A00194FF82FF
```

- Live testing showed that this exact Carista payload is not the practical fix
  on this specific car. The proven minimal request remains:

```text
A00F8AFF32FF
```

### Structured write-model recovery

- The old model `3B9A + full 30-byte coding` was disproven.
- The old model `2E0600 + full 30-byte coding shaped to mimic Carista` was also
  demoted to a diagnostic clue only.
- Static analysis of `WriteVagCodingCommand` showed that Carista builds a
  structured request, not a full BCM coding blob write.
- The current best request-shape reconstruction is:

```text
3B9A
+ 6-byte coding value
+ 4-byte coding raw address
+ coding-type-dependent tail
```

- Additional disassembly proved that the raw address is not a pasted `0600`
  constant. It is derived from ECU metadata by:

```text
GetEcuInfoOperation::getCodingRawAddress
VagOperationDelegate::getCodingRawAddress
```

- The write path was tightened further to a higher-level setting model:

```text
ChangeSettingOperation(shared_ptr<Setting>, vector<byte>)
OperationDelegate::changeSettingInternal(...)
VagOperationDelegate::insertValue(...)
VagOperationDelegate::getSettingRawAddress(shared_ptr<Setting>)
VagOperationDelegate::writeVagCanCodingValue(uint64, vector<byte>)
WriteRawValuesOperation(vector<pair<uint64, vector<byte>>>)
```

- Practical implication: a normal Carista UI toggle is converted into a compact
  setting-specific coding value before the final write command is built.

### Java / resource bridge recovery

- Java-side `SettingRef` analysis confirmed that `SettingRef` stores a native
  long identifier and exposes native name/event lookup methods.
- JNI exports were identified for:

```text
SettingRef_getNameResIdNative
SettingRef_toEventStringNative
SettingCategory_valuesNative
JniHelper::getNativePointer<Setting>
JniHelper::getNativePointer<ReadValuesOperation>
```

- The cornering-related Carista resource keys were recovered offline, including:

```text
car_setting_cornering_lights
car_setting_cornering_lights_activation
car_setting_cornering_lights_via_fogs
car_setting_cornering_lights_via_fogs_left
car_setting_cornering_lights_via_fogs_right
car_setting_cornerig_lights_with_turn_signal
car_setting_cornering_lights_with_turn_signals
```

- Today's apktool/smali pass established the concrete Java/native availability
  bridge:

```text
ReadValuesOperation.getAvailableItems() -> Map<SettingCategory, Setting[]>
CheckSettingsOperation.initNative(Operation) -> native availability entry point
SettingCategory.getValues() -> valuesNative()
SettingCategory equality -> nativeId-based
Setting -> full native-backed model with getEcu/getInstruction/getInterpretation/getNameResId/toEventString
ChangeSettingOperation(Setting, byte[], ReadValuesOperation)
```

- Practical implication from that pass:

```text
Java is not where Carista decides which PQ25 settings are available.
The actual per-BCM available-setting map is returned from native code.
Java receives full Setting objects plus current byte[] values from ReadValuesOperation.
The requested compact byte[] exists before the native writer path begins.
```

- A further smali pass recovered the Java-side requested-value encoding rules
  used by the change-setting screen:

```text
wr/f + zr/f build per-setting UI state and later convert the chosen UI state into (oldValue, newValue)

MultipleChoiceInterpretation:
  PossibleValue(value:J, nameResId:String)
  newValue = rightmost(originalLen) bytes of mi/t1.U(value)

NumericalInterpretation:
  newValue = rightmost(originalLen) bytes of mi/t1.U(start + increment * selectedIndex)

TextInterpretation:
  newValue = StringUtils.getBytes(userText)

mi/t1.W([B) decodes current values as big-endian unsigned numbers
mi/t1.U(J) encodes 8-byte big-endian numbers
```

### Offline PQ25 cornering-label map

- Copilot's live trace/Gadget route remains useful, but it currently cannot be
  exercised because the phone is not available.
- The offline static mapper now records the Carista resource labels, Android
  resource ids, native string locations, and the practical mapping against this
  Polo's known-good coding delta:

```text
carista_apk_analysis/map_carista_pq25_cornering.py
carista_apk_analysis/carista_pq25_cornering_static_map.md
carista_apk_analysis/carista_pq25_cornering_static_map.json
```

- A broader generated map now covers all app-visible Carista `car_setting_*`
  resource labels and whether each label is also present as a native
  `libCarista.so` string:

```text
carista_apk_analysis/build_carista_supported_settings_map.py
carista_apk_analysis/carista_supported_settings_map.md
carista_apk_analysis/carista_supported_settings_map.csv
carista_apk_analysis/carista_supported_settings_map.json
```

  Current generated counts:

```text
3669 app-visible car_setting_* labels
3619 labels also present as native strings
742 lighting-related labels by heuristic category
9 PQ25 BCM mapped rows
5 pending cornering write-target rows
```

- Practical current mapping for this BCM:

```text
car_setting_cornering_lights_via_fogs
car_setting_cornering_lights_via_fogs_experimental
car_setting_use_cornering_lights
  -> byte 12 bit 6, base fog-light cornering function

car_setting_cornerig_lights_with_turn_signal
car_setting_cornering_lights_with_turn_signals
  -> byte 21 bit 2, turn-signal-triggered cornering assist
```

- Static analysis found the native strings, but did not find simple direct code
  xrefs from those labels into `VagCanSettings::getSettings()`. Treat this as a
  practical map from app label to known-good coding delta, not proof of the
  exact Carista write tuple.

- A follow-up disassembly scan of `VagCanSettings::getSettings()` found zero
  direct `car_setting_*` C-string references and no direct Android resource-id
  references for the cornering labels. The function does contain/generated-use
  many `VagCanLongCodingSetting` template instantiations, but the label bridge
  is not a simple pointer or resource-id table.

### Tooling built during the RE work

- Static analysis script:

```text
carista_apk_analysis/analyze_carista_write_builder.py
carista_apk_analysis/analyze_carista_write_tuple.py
carista_apk_analysis/map_carista_pq25_cornering.py
carista_apk_analysis/build_carista_supported_settings_map.py
```

- Local RE Python requirements now include:

```text
capstone
pyelftools
androguard
```

- Live trace host tooling and summarizer:

```text
run_carista_cornering_trace.py
carista_cornering_trace.js
summarize_carista_cornering_trace.py
run_carista_cornering_capture.ps1
```

- Gadget patch/build tooling for the stock-phone path:

```text
build_carista_gadget_apks.py
carista_gadget_patch_workflow.md
gadget_patch_out/
```

## What Was Accomplished

### High-confidence technical outcomes

- The correct write problem is now much narrower than it was at the start.
- The investigation has moved from "which service should we brute-force" to
  "which exact Carista setting object and write tuple corresponds to cornering
  lights on this BCM".
- The following important false paths were ruled out:

```text
- blind full-coding 3B9A write
- blind full-coding 2E0600 write as the final solution
- the assumption that one hardcoded 0600 raw address is sufficient
- the assumption that MQB/PQ26-style 70E cornering clues control this car
```

- The structured Carista write chain is now established at a useful level:

```text
ChangeSettingOperation
-> OperationDelegate::changeSettingInternal
-> VagOperationDelegate::insertValue
-> VagOperationDelegate::getSettingRawAddress
-> VagOperationDelegate::writeRawValue
-> VagOperationDelegate::writeVagCanCodingValue
-> WriteVagCodingCommand
```

- The latest lower-writer disassembly tightened the tuple model:

```text
writeVagCanCodingValue receives a 64-bit raw-value key plus compact value bytes
the raw value is cached by that key
ECU metadata is queried with that key to choose the coding type
coding type 2 is preserved
most other coding is normalized to type 3
a sentinel metadata path forces type 5
```

- Dex inspection with Androguard confirmed the Java/native bridge classes that
  matter for a future trace or deeper static bridge:

```text
SettingRef.nativeId
ChangeSettingOperation.initNative(Setting, byte[], ReadValuesOperation)
GetEcuInfoOperation.getCodingRawAddress(short)
GetEcuInfoOperation.supportsSingleCoding()
GetEcuInfoOperation.supportsMultiCoding()
```

- The smali pass sharpened the actual availability and write-value boundary:

```text
available settings for the car/module come back as Map<SettingCategory, Setting[]>
the map is owned by native ReadValuesOperation / CheckSettingsOperation
the normal write path takes a full Setting plus requested byte[]
SettingRef is a handle class, but not the direct ChangeSettingOperation input
```

- The Java-side requested-value bytes are now partially de-obfuscated too:

```text
multiple-choice and numerical settings use deterministic length-preserving big-endian numeric encodings
text settings use direct StringUtils byte conversion
```

- The phone-side instrumentation boundary was diagnosed precisely instead of
  being left as a generic Frida failure.

### Operational outcomes

- ADB / Frida environment setup was pushed as far as possible on the stock
  Samsung phone.
- The exact blocker was identified: no rooted `frida-server`, app not
  debuggable, and stock Android preventing the direct live attach path.
- A full fallback path was then built and validated locally:

```text
patch libCarista.so
inject libgadget.so + libgadget.config.so into config.armeabi_v7a.apk
zipalign and sign the split set
install through adb install-multiple
trace through localhost Gadget forwarding
```

- That patch/sign pipeline now works locally end to end.

## What Is Still Open

The main unresolved problem is now specific:

```text
which native Setting catalog entry Carista selects for the cornering-light labels,
and which metadata bytes that entry contributes to the final 3B9A tuple
```

Everything else now serves that mapping problem.

The byte/bit effect is now known well enough for the two relevant cornering
settings on this specific BCM. The generated settings map also marks the likely
6-byte final value chunks:

```text
byte 12 bit 6 target chunk: 6C680ED000C8
byte 21 bit 2 target chunk: 412F60A60000
```

What remains unknown is the rest of the compact Carista write tuple:

```text
4-byte raw-address vector
coding type / tail bytes
required session or state precondition
```

### 1. App setting -> native setting mapping

The cornering resource keys visible in the app are known, but the exact native
`Setting` entry used for `6R0937087K` is still not mapped.

What is still missing is the bridge from:

```text
app-visible cornering setting name
-> SettingRef / event string / resource id
-> native Setting catalog entry
```

More precisely after the smali pass:

```text
native CheckSettingsOperation
-> ReadValuesOperation.getAvailableItems()
-> SettingCategory/nativeId bucket
-> Setting object returned for this BCM
```

### 2. Native setting -> compact Carista write value mapping

For the real cornering setting, the unresolved question is still which compact
Java-side requested value bytes Carista emits before native `insertValue`
expands them into the final raw coding value. The likely final 6-byte value
chunks are known from the working/non-working coding delta, but they are not the
same thing as the UI requested-value byte array.

Still missing for the real cornering-light setting:

```text
- Java/UI requested value bytes
- resolved 4-byte raw address
- coding family / coding type
- trailing tail bytes
- any companion metadata required by the builder
```

In other words, the write path is known in shape, but the real cornering value
payload is not yet recovered.

### 3. Compact Carista write value -> actual BCM coding mapping

The final write target is not a full 30-byte long-coding blob. Carista appears
to write a smaller structured fragment.

What is still open is how that compact fragment corresponds to the actual coding
change on this BCM, especially the two known missing bits:

```text
byte 12 bit 6
byte 21 bit 2
```

So the missing bridge is not just Java-to-native. It is also:

```text
app setting
-> compact Carista value bytes
-> exact BCM coding-bit effect
```

### 4. Identity mapping between the remaining handles

Still not proven:

```text
SettingRef.nativeId
native Setting*
uint64 key used by writeRawValue / writeVagCanCodingValue
compiled VagCanSettings catalog entry
```

This matters because it is likely the remaining key needed to connect the app's
setting model to the actual write tuple.

### 5. Can the setting-to-value-to-coding mapping be reconstructed fully offline?

This is still open. Live tracing is the shortest route when the phone works,
but the remaining offline path may still recover enough to reconstruct the
cornering-setting value mapping without the phone.

## Current Blockers

### Phone-side blocker

Right now the phone is unavailable, so the Gadget install-and-trace path cannot
be exercised.

### Offline blocker

The strongest offline blocker is no longer transport or APK tooling. It is the
remaining mapping problem:

```text
app-visible setting
-> native Setting catalog entry
-> compact value bytes produced by insertValue
-> actual coding effect on the BCM
```

Today's smali pass removed one uncertainty from that chain:

```text
the availability map itself is native and returns full Setting objects
```

This turn removed another uncertainty:

```text
for multiple-choice and numerical settings, the requested compact byte[] is built on the Java side from explicit numeric interpretation metadata
```

So the remaining hard part is now the native catalog/data-flow layer, not the
Java grouping layer.

That is the missing chain needed to stop guessing at writes.

## Best Offline RE Targets From Here

Until the phone is available again, the highest-value static work is:

### 1. JNI constructor / init path tracing

Recover the exact JNI path that turns Java-side setting references into native
`Setting*` pointers and operation objects. This should narrow whether
`SettingRef.nativeId` is a handle, a direct pointer, or an intermediate lookup
token.

The most useful concrete targets after today's pass are now:

```text
CheckSettingsOperation.initNative(Operation)
ChangeSettingOperation.initNative(Setting, byte[], ReadValuesOperation)
SettingRef.getNameResIdNative / toEventStringNative
SettingCategory.valuesNative
```

### 2. VagCanSettings catalog analysis

Push deeper into `VagCanSettings::getSettings()` and nearby data structures to
locate the compiled catalog entries associated with the recovered cornering
resource keys.

### 3. Cornering-setting neighborhood mapping

Use the recovered cornering resource strings and event strings as anchors to map
nearby setting records, candidate IDs, and possible coding metadata, with the
specific aim of recovering which app-visible cornering toggle produces which
compact coding value.

### 4. insertValue path recovery

Trace how `VagOperationDelegate::insertValue`, `VagSetting::insertValue`, and
`ByteUtils::insertValue` transform a high-level setting value into the compact
6-byte coding payload, ideally for both toggle states so the emitted value bytes
can be related back to the actual coding-bit change.

## Practical Resume Point

If continuing offline right now, the best next slice is:

```text
map the Java/JNI SettingRef bridge into the native Setting catalog,
locate the real cornering setting entry inside VagCanSettings,
and then try to recover the compact value bytes that Carista would emit
for that setting without relying on the phone
```

This is the shortest remaining static path toward the final missing bridge from
app-visible setting -> Carista value bytes -> actual coding effect.
