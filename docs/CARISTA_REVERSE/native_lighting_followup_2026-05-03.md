# Native Lighting Follow-Up - 2026-05-03

Scope: offline `libCarista.so` archaeology only. No live vehicle probing was run for this follow-up.

## Ghidra workflow correction

The broad lighting probe was changed so it no longer decompiles by default. The safe default is now refs-only; decompilation is opt-in with `--decompile` and bounded per key.

Useful artifacts:

- `carista_apk_analysis/ghidra_scripts/ExportCaristaLightSettingProbe.java`
- `carista_apk_analysis/ghidra_light_probe_fast/light_setting_string_refs.md`
- `carista_apk_analysis/ghidra_scripts/ExportCaristaInstructionWindows.java`
- `carista_apk_analysis/ghidra_instruction_windows/*.txt`
- `CaristaReproduction/VagCanSettings.py`
- `docs/CARISTA_REVERSE/generated/vag_can_settings_recoveries.json`

For future native digs, prefer hardcoded instruction-window targets over broad decompiler runs.

The current typed offline view is:

```powershell
python -m CaristaReproduction --vag-can-settings-recoveries
```

This view intentionally marks unresolved constructor leads as not write-safe.

The helper chain is now typed from focused Ghidra exports:

- `0x010B1930 -> 0x010C0418` constructs `VagUdsAdaptationSetting`.
- `0x010B5A98 -> 0x010D4140` constructs `VagUdsCodingSetting`.
- `0x010B19D0 -> 0x010C0708` constructs `VagUdsCodingSetting`.

Those class names are now reflected in `VagCanSettings.getPq25SettingRecoveries`.

The repeatable command for this focused native export is:

```powershell
.\carista_apk_analysis\setup_ghidra_re.ps1 -ExportAddressTargets
```

## Fog-cornering enum correction

The older ARM left and right fog-cornering branches are both `VagUdsAdaptationSetting` type `7`, offset `5`, mask `FF`, but the `car_setting_on` enum differs by side. Later x86 and argument tracing shows these are only two guarded branches under the visible keys, not proven PQ25/6R availability.

| Setting | Raw address | Offset | Mask | Recovered choices |
| --- | ---: | ---: | ---: | --- |
| `car_setting_cornering_lights_via_fogs_left` | `055C` | `5` | `FF` | `00=off`, `16=on`, `1E=enabled_coming_home_or_leaving_home` |
| `car_setting_cornering_lights_via_fogs_right` | `055D` | `5` | `FF` | `00=off`, `17=on`, `1E=enabled_coming_home_or_leaving_home` |

Evidence:

- `cornering_fogs_left_ref_1_01082988.txt`: `movw r0,#0x55c`, `movs r1,#0x5`, `movs r2,#0xff`, `movs r1,#0x1e`, `movs r2,#0x16`.
- `cornering_fogs_left_ref_2_01082A4A.txt`: second left variant confirms `0x55c`, offset `5`, `0x1e`, `0x16`.
- `cornering_fogs_right_ref_1_01082B78.txt`: `movw r0,#0x55d`, `movs r1,#0x5`, `movs r2,#0xff`, `movs r1,#0x1e`, `movs r2,#0x17`.
- `cornering_fogs_right_ref_2_01082C34.txt`: second right variant confirms `0x55d`, offset `5`, `0x1e`, `0x17`.

Deeper argument tracing changes the availability interpretation:

- Preferred x86 `0x012da25a -> 0x0136c910 -> PLT 0x0197e2f0` resolves to a `VagUdsAdaptationSetting` helper for the left key. Its whitelist comes from GOT `[EBX-0x2AA4]` `VagWhitelists::CENTRAL_ELEC_MQB_ALL`, combined with GOT `[EBX-0x2C9C]` `VagWhitelists::CENTRAL_ELEC_MK8`.
- Preferred x86 `0x012da39a -> 0x01356f90 -> PLT 0x0197d6f0` resolves to a `VagUdsAdaptationSetting` helper for the left key. It pushes GOT `[EBX-0x2C94]` `VagWhitelists::UDS_CAN_GATEWAY_MEB` and GOT `[EBX-0x5DF4]` `VagUdsEcu::CAN_GATEWAY`.
- Preferred x86 `0x012da5a9 -> 0x01368690 -> PLT 0x0197e0a0` resolves to a `VagUdsAdaptationSetting` helper for the right key and uses the same `CENTRAL_ELEC_MQB_ALL` plus `CENTRAL_ELEC_MK8` whitelist family.
- Preferred x86 `0x012da6e9 -> 0x0136caf0 -> PLT 0x0197e300` resolves to a `VagUdsAdaptationSetting` helper for the right key and uses the same `UDS_CAN_GATEWAY_MEB` plus `CAN_GATEWAY` guard.
- Older ARM `01082988` and `01082B78` use `VagUdsEcu::CENTRAL_ELEC` with a `CENTRAL_ELEC_MQB_ALL` / `CENTRAL_ELEC_MK8`-derived whitelist.
- Older ARM `01082A4A` and `01082C34` use `VagUdsEcu::CAN_GATEWAY` with `VagWhitelists::UDS_CAN_GATEWAY_MEB`.
- No recovered per-side `055C` / `055D` constructor branch is currently guarded by `CENTRAL_ELEC_6R`, `CENTRAL_ELEC_6R_5C_7E_7H`, or `CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S`.

Safety boundary remains unchanged: native type `7` dispatch reads these as `22055C` / `22055D`, and both returned `7F2231` live on this BCM/session. There is still no safe raw payload seed for `2E055C` / `2E055D`.

## CH/LH targets now visible in native code

The refs-only probe shows `FUN_0105f6c0` is the central VAG lighting constructor area for coming-home/leaving-home and fog-adjacent settings.

High-value refs now exported to instruction windows:

- `car_setting_coming_home_req_rls`: refs at `0107671a`, `01076772`, `010767e0`, `01076964`.
- `car_setting_coming_home`: refs at `01076860`, `010768ba`, `01076910`.
- `car_setting_coming_home_mode`: refs at `01076ab4`, `01076b5e`, `01076bf4`, `01076d10`, `01076dd0`, `01076e68`.
- `car_setting_coming_leaving_home_output`: refs at `010775ee`, `010775f0`, `01077694`, `01079282`, `01079316`.
- `car_setting_coming_home_via_low_beams`: ref at `010776d8`.
- `car_setting_coming_home_via_fogs`: ref at `01077c50`.
- `car_setting_coming_home_duration`: refs at `0107813e` and nearby duration variants.
- `car_setting_leaving_home_req_rls`: refs at `0107879a`, `01078896`, `010789bc`, `01078a14`.
- `car_setting_leaving_home_duration`: refs at `01078c66` and nearby duration variants.
- `car_setting_enabled_coming_home_or_leaving_home`: refs include the fog-cornering enum constructors at `0108292a`, `010829ec`, `01082b1a`, `01082bd4`.

## Recovered CH/LH constructor details

These details are useful leads, but they are not yet complete write plans.

| Setting area | Evidence recovered |
| --- | --- |
| `coming_home_req_rls` | A constructor window shows `0x0A57`, offset `0x02`, mask/value field `0x04` before `car_setting_coming_home_req_rls`; nearby variants use additional masks such as `0x80`, `0x11/0x20`, and `0x0A/0x04`. |
| `coming_home` | A constructor window shows `0x0A57`, offset `0x04`, mask/value field `0x40` before `car_setting_coming_home`; nearby variants show other small masks/values under the same key. |
| `coming_home_mode` | A constructor window shows `0x0A57`, offset `0x02`, count/mask `0x03`, with choices consistent with `0=disabled`, `1=manual`, `2=automatic`. |
| `coming_leaving_home_output` | Choice lists are explicitly `car_setting_fogs` and `car_setting_low_beams`; one constructor window uses raw-ish id `0x110E`, offset/count `0x02`. |
| `coming_home_via_low_beams` | Constructor uses immediate fields `0x10` and `0x06` before the key, then calls a VAG helper. This looks like a bit-style setting, not a direct `055C/055D`-style raw DID. |
| `coming_home_via_fogs` | Constructor uses immediate fields `0x20` and `0x06` before the key, then calls a VAG helper. Nearby settings include `0x056D`, offset `0x05`, mask `FF`, choices `0`/`1E`, but that adjacent block is a separate CH/LH output-role setting. |
| `coming_home_duration` | Duration choices include 10-60 second labels; windows show `0x0A57`, offset `0x03` or `0x05`, mask `FF`, with max-like `0x5A` and step-like `0x0A` fields in nearby constructors. |
| `leaving_home_req_rls` | Constructor windows show bit-style values such as `0x20/0x00`, then variants for `car_setting_leaving_home` and `car_setting_leaving_home_req_rls`. More targeted windows are needed before modeling. |
| `leaving_home_duration` | Duration choices include 10-60 second labels; a constructor window shows `0x0A57`, offset `0x05`, mask `FF`, max-like `0x5A`, and step-like `0x0A`. |

## Troubleshooting implication

The `1E=enabled_coming_home_or_leaving_home` value appearing in the fog-cornering side settings is no longer just a string-level clue; it is attached to the exact `055C`/`055D` constructors. The CH/LH native area is therefore a strong offline troubleshooting target for the fog behavior, especially `coming_home_via_fogs`, `coming_leaving_home_output`, and the CH/LH duration/mode/RLS settings.

Still, the only live-proven path for `055C`/`055D` is rejected direct RDBI, so the next step should remain offline constructor recovery or a Carista-shaped positive read proof, not blind writes.

---

## Second-Pass Deeper RE — 2026-05-03

Scope: static instruction-window review + Ghidra address-target exports. No live vehicle work.

### Helper export confirmations

All previously listed helper chains were re-confirmed from the bounded decompilation exports:

| Call site | Callee | Class allocated |
|---|---|---|
| `010B71D0` | `010DAEDC` | `VagUdsCodingSetting` |
| `010B1980` | `010C0590` | `VagUdsAdaptationSetting` |
| `010B7F38` | `010DEE9C` | `VagUdsAdaptationSetting` |
| `010B1930` | `010C0418` | `VagUdsAdaptationSetting` |
| `010B74A0` | `010DBC4C` | `VagUdsCodingSetting` |

`010DEE9C` takes an extra `vector<uint64_t>` argument — it is the overloaded `VagUdsAdaptationSetting` constructor with an additional allowed-values list. This is consistent with the mixed adaptation variants seen in `turn_off_fogs_with_high_beam`.

### `drl_via_fogs` cluster — key findings

- The key has six `FUN_0105f6c0` construction sites with three distinct helper types.
- One `010B1980 -> 010C0590 -> VagUdsAdaptationSetting` path embeds raw address `0x055C`, offset `6`, mask `FF`, choices `0x00=car_setting_disabled` / `0x14=car_setting_enabled`.
- Other paths use `010B71D0 -> 010DAEDC -> VagUdsCodingSetting` (immediate pairs `0x17/0x04`, `0x11/0x10`, `0x0E/0x02`, `0x02/0x08`) and likely a long-coding variant.
- **None of these is write-safe on its own.** The `055C` raw address in the adaptation variant is the same DID that returned `7F2231` for the offset-5 `055C` read. Without a positive `22055C` response there is no confirmed raw payload length, so `2E055C` is not safe regardless of the byte offset.
- The runtime branch that Carista selects for the exact part `6R0937087K` is not yet known.

### `turn_off_fogs_with_high_beam` cluster — key findings

- The key also has six `FUN_0105f6c0` construction sites.
- Two UDS adaptation variants go through `010B7F38 -> 010DEE9C -> VagUdsAdaptationSetting`:
  - First variant: raw address `0x0D01`, fields `1/1` adjacent.
  - Second variant: raw address `0x0A58`, fields `4/0` adjacent.
- Additional paths use `010B69C0` (UDS coding, immediate pairs `0x20/0x15`, `0x04/0x0E`, `0x02/0x04`, `0x01/0x0F`) and `010B8480` (long-coding, immediate pair `0x20/0x11`).
- Direct-read candidates `220D01` and `220A58` were live-tested on 2026-05-05 and both returned `7F2231`. Treat the UDS adaptation variants as negative direct-read evidence on this BCM/session.

### `coming_leaving_home_output` — partial new finding

- Instruction window `010775EE` confirms helper `010B1930 -> 010C0418 -> VagUdsAdaptationSetting` with raw address `0x110E`, choice list `car_setting_fogs` / `car_setting_low_beams`.
- Instruction window `01079282` shows a second construction path calling `bl 0x010b4218`; `target_010B4218.c` calls `010CCBC8`, and `target_010CCBC8.c` constructs `VagUdsCodingSetting`.
- Choice encoding is branch-specific. The `110E` adaptation branch and the DID `0600` byte `0D` / mask `40` coding branch store `car_setting_fogs=00` and `car_setting_low_beams=01`; the DID `0600` byte `11` / mask `08` coding branch stores `car_setting_fogs=01` and `car_setting_low_beams=00`.
- Status: this setting is now known to be mixed, with a UDS adaptation path and two UDS coding variants. `22110E` only covers the adaptation path and returned `7F2231` live on 2026-05-05. The UDS coding variants are now typed as DID `0600` byte/mask `0D/40` and `11/08`; runtime branch selection still needs recovery before writing.

### `car_setting_left_fog_light_as` / `car_setting_right_fog_light_as` — still non-VAG

- The refs-only probe confirms both keys' first string references land only in `FUN_00E314FE`, which is the non-VW / Ford-path constructor zone.
- No reference was found in `FUN_0105f6c0` for either of these highest-priority keys.
- The preferred Play 9.8.3 x86 sweep now confirms the same negative fact without relying on ARM windows:
  - `car_setting_fog_when`: `0x00e72b62` in `_ZN12FordSettings11getSettingsEv`; constructor call `0x00e72bc1 -> 0x00ee30b0 -> FordCodingSetting`.
  - `car_setting_left_fog_light_as`: `0x00e73135` in `_ZN12FordSettings11getSettingsEv`; constructor call `0x00e73194 -> 0x00ee03b0 -> FordUdsSetting`.
  - `car_setting_right_fog_light_as`: `0x00e7376f` in `_ZN12FordSettings11getSettingsEv`; constructor call `0x00e737ce -> 0x00ee59f0 -> FordUdsSetting`.
  - `car_setting_use_cornering_lights` and typo-preserved `car_setting_cornerig_lights_with_turn_signal` appear in the same Ford window as choice labels, not VAG/PQ25 settings.
  - `car_setting_cornering_lights_with_turn_signals_one_touch` is in `_ZN12BmwESettings11getSettingsEv` at `0x00d39204` with `BmwESetting` constructor calls, not VAG/PQ25.
- The VAG/PQ25 availability path for `left_fog_light_as` / `right_fog_light_as` must be reached via a different mechanism — either a different outer function, a sub-object, or the `ReadValuesOperation` vtable. This is the main remaining static RE gap.

### `car_setting_assist_dr_lights` — confirmed

- Instruction window `0108252C` confirms helper `010B74A0 -> 010DBC4C -> VagUdsCodingSetting`, immediate pair `0x20 / 0x16` immediately before the key label.
- The `0x16` field is byte index 22 (decimal); `0x20` is the bit-mask value, consistent with byte 22 bit 5 in the candidate table.

### `MultipleChoiceInterpretation` singleton encoding

Static init `00D54B34` initializes the common choice-table singletons used by the recovered boolean branches:

| Singleton | Address | Compact requested values |
|---|---:|---|
| `MultipleChoiceInterpretation::YES_NO` | `014f1fd8` | `car_setting_no=00`, `car_setting_yes=01` |
| `MultipleChoiceInterpretation::ENABLED_DISABLED` | `014f1ff0` | `car_setting_disabled=00`, `car_setting_enabled=01` |

The compact value is still branch-local input to `VagSetting::insertValue`; it is not a standalone write payload. It does prove the requested-choice side for recovered DID `0600` bitmask branches such as `coming_home_via_low_beams`, `coming_home_via_fogs`, `coming_home`, `leaving_home`, `turn_off_fogs_with_high_beam`, and `assist_dr_lights`.

### Safety boundary summary

| DID / raw address | Current status |
|---|---|
| `22055C` | Rejected live as `7F2231`. Blocks both `drl_via_fogs` adaptation variant (offset 6) and `cornering_fogs_left` (offset 5). |
| `22055D` | Rejected live as `7F2231`. Blocks `cornering_fogs_right` (offset 5). |
| `22110E` | Rejected live as `7F2231` on 2026-05-05. Blocks the direct adaptation path only; the second `coming_leaving_home_output` path is typed as `VagUdsCodingSetting` via `010B4218 -> 010CCBC8`. |
| `22056D` | Rejected live as `7F2231` on 2026-05-05. Blocks the nearby `coming_home_via_fogs` direct adaptation candidate. |
| `220550` | Rejected live as `7F2231` on 2026-05-05. Blocks the nearby `coming_home_via_fogs` raw channel candidate. |
| `220551` | Rejected live as `7F2231` on 2026-05-05. Blocks the nearby `coming_home_via_fogs` raw channel candidate. |
| `220A57` | Rejected live as `7F2231` on 2026-05-05. Blocks the shared CH/LH direct UDS adaptation branch but not the VAG short-adaptation, UDS coding, or long-coding alternatives. |
| `220D01` | Rejected live as `7F2231` on 2026-05-05. Blocks one `turn_off_fogs_with_high_beam` adaptation variant. |
| `220A58` | Rejected live as `7F2231` on 2026-05-05. Blocks the nearby `turn_off_fogs_with_high_beam` adaptation variant. |

Do not write any of these until the corresponding positive read payload is obtained, the full byte-length is confirmed, and the correct runtime variant for `6R0937087K` is identified.

Conclusion for blocked reads: more work is needed, but not more blind retries of these same direct `22` requests in the normal TP2.0 session. The useful path is to recover Carista's runtime branch selection and exact packing for the UDS coding, long-coding, and VAG short-adaptation constructors that sit beside the rejected UDS adaptation DIDs.

---

## Broad PQ25 CH/LH Constructor Pass - 2026-05-04

Scope: static instruction-window review plus focused Ghidra address-target exports. No live vehicle work.

New wrapper/callee exports added to `ExportCaristaAddressTargets.java` and generated under `carista_apk_analysis/ghidra_address_targets/`:

| Setting area | Newly typed helper chain |
|---|---|
| `coming_home_req_rls` | `010B6B3C -> 010D8FE4 -> VagUdsAdaptationSetting`; `010B6B90 -> 010D917C -> VagCanLongCodingSetting`; `010B0D5C -> 010BC860 -> VagUdsCodingSetting`; `010B19D0 -> 010C0708 -> VagUdsCodingSetting` |
| `coming_home` | `010B6BDC -> 010D92EC -> VagUdsAdaptationSetting`; `010B2040 -> 010C2700 -> VagUdsCodingSetting`; `010B3AF0 -> 010CA958 -> VagUdsCodingSetting` |
| `coming_home_mode` | `010B6C30 -> 010D9484 -> VagUdsAdaptationSetting`; `010B6C84 -> 010D9608 -> VagCanLongCodingSetting` |
| `coming_home_duration` | `010B704C -> 010DA7BC -> FullByteVagCanShortAdaptationSetting`; `010B7094 -> 010DA910 -> VagUdsAdaptationSetting` |
| `leaving_home_req_rls` | `010B7184 -> 010DAD6C -> VagCanLongCodingSetting`; plus `010B19D0 -> 010C0708 -> VagUdsCodingSetting` |
| `leaving_home` | `010B71D0 -> 010DAEDC -> VagUdsCodingSetting`; `010B0C78 -> 010BC404 -> VagUdsCodingSetting` |
| `leaving_home_duration` | `010B1708 -> 010BF9DC -> FullByteVagCanShortAdaptationSetting`; `010B72C4 -> 010DB380 -> VagUdsAdaptationSetting`; `010B7318 -> 010DB504 -> VagUdsAdaptationSetting`; `010B7368 -> 010DB67C -> VagUdsAdaptationSetting` |

Important recovered fields:

- `coming_home_req_rls`: one adaptation branch uses raw address `0x0A57`, offset `2`, mask/value field `0x04`.
- `coming_home`: one adaptation branch uses raw address `0x0A57`, offset `4`, mask/value field `0x40`.
- `coming_home_mode`: one adaptation branch uses raw address `0x0A57`, offset/count `2/3`; choice table maps disabled/manual/automatic to `00/01/02`.
- `coming_home_duration`: one UDS adaptation branch uses raw address `0x0A57`, offset `3`, mask `FF`, with duration values from `0A` to `3C`; a VAG short-adaptation branch is also present.
- `leaving_home_duration`: one UDS adaptation branch uses raw address `0x0A57`, offset `5`, mask `FF`, with duration values from `0A` to `3C`; a VAG short-adaptation branch is also present.
- `coming_leaving_home_output`: the second coding path now has direct `VagUdsCodingSetting` proof and the instruction window shows coding-like immediate pairs `40/0D` and `08/11` before the `010B4218` calls. Field order is still unresolved.

Safety impact:

- `220A57` is now live-rejected as `7F2231` for several CH/LH adaptation branches, so it is negative evidence for the direct UDS adaptation path rather than a retry target.
- Mixed settings in this cluster must be branch-selected before use. The same visible Carista key can map to UDS adaptation, VAG short adaptation, UDS coding, or long-coding constructors depending on the runtime branch.
- The `VagCanSettings` Python recovery map and `vag_can_settings_recoveries.json` now carry these broader PQ25 entries so the reproduction has code-level proof anchors, not only markdown notes.

---

## ReadValuesOperation Runtime Flow Pass - 2026-05-04

Scope: static Ghidra address-target exports only. No live vehicle work.

New exports added to `ExportCaristaAddressTargets.java` and generated under `carista_apk_analysis/ghidra_address_targets/`:

| Native method | Address | Proof impact |
|---|---:|---|
| `ReadValuesOperation::getAvailableItems` | `012CD520` | JNI slot `0x7C` maps to the base method, which returns the native available-items map at `this + 0x68`. |
| `ReadValuesOperation::getSettingValue` | `012CD694` | JNI slot `0x8C` maps to the base method, which reads raw bytes through delegate slot `0xA8` and applies the setting extraction slot `0x1C`. |
| `ReadValuesOperation::readItemAvailabilityAndValues` | `012CDE08` | Builds the runtime availability map; calls delegate slot `0xE0` for availability, raw-address slot `0x148`, and raw-value/multi-read slots for values. |
| `ReadValuesOperation::isItemAvailable` | `012CD820` | Checks the map at `this + 0x7C` and rejects wrong-length or unrecognized current values. |
| `VagOperationDelegate::getSettingAvailability` | `012703D0` | Checks ECU presence and setting/ECU type compatibility, then calls `getVagSettingAvailabilityForEcu`. |
| `VagOperationDelegate::getVagSettingAvailabilityForEcu` | `0127075C` | Uses the setting type byte plus VIN-derived PDX/file identifiers and ECU ASAM/revision data before invoking the setting availability predicate object. |
| `VagOperationDelegate::readRawValue` | `01270A10` | Switches by native raw type: `0/1` CAN adaptation, `7` UDS adaptation, `8` UDS coding, `5/9` UDS submodule, `10` no read. |
| `VagOperationDelegate::readRawValuesMulti` | `01270CF8` | Batches dynamic raw reads in chunks of six after cache checks. |
| `VagOperationDelegate::getSettingRawAddress` | `012720EC` | Adds VAG submodule raw-address handling for types `4`, `5`, and `9`. |

Raw branch callees were also exported: `0127236C` (`readVagCanAdaptationValue`), `01272A1C` (`readVagUdsValue`), `01272AD0` (`readVagUdsCodingValue`), and `01272CE0` (`readVagUdsSubmoduleValue`).

Deeper availability trace:

- `target_0127075C.c` reads the setting `AvailBy` byte from `Setting/VagSetting + 0x5C`.
- Before the `AvailBy` switch, a setting vtable slot at `+0x3C` can divert into `LAB_01427fe0`; that special predicate path is still unresolved.
- `AvailBy=2` uses the ECU tag string from `VagEcuInfo + 0x08` and calls the setting `StringWhitelist::itemMatches`.
- `AvailBy` values `0/1/3/4` require `VagEcuInfo + 0x04 == 2`, obtain ECU ASAM/revision through delegate slot `0x194`, build a `VagVin::getVagFileIdentifier`, then call `StringWhitelist::itemMatches`. Values `1` and `4` use request mask `0xC0`; values `0` and `3` use `0x40`. `AvailBy=4` first derives VIN/PDX and logs `Vehicle missing from PDX mapping` if no mapping exists.
- `AvailBy=5` uses VIN/PDX only, builds a file identifier without ASAM/revision strings, then calls `StringWhitelist::itemMatches`.
- `target_012703D0.c` treats the `getVagSettingAvailabilityForEcu` return value `2` as available and logs `is available for ECU w/ tag %s`.

Constructor default `AvailBy` findings:

- `VagCanShortAdaptationSetting` constructors at `01100110` / `01100074` / `01100218` / `011003D0` pass `AvailBy=2`.
- `VagCanCodingSetting` at `01058240` stores `2` before its `VagSetting` call; `VagCanLongCodingSetting` wrappers `0105F484` / `0105F500` delegate through that constructor.
- The no-`AvailBy` `VagUdsCodingSetting` / `VagCanEcu` make_shared construct body at `010BC94C` passes `AvailBy=2`.
- Sampled no-`AvailBy` `VagUdsAdaptationSetting` make_shared construct bodies (`010E0EE4`, `010D29D8`, `010D4EE0`, `010C5440`, `010DD1FC`) pass `AvailBy=2`.

Impact on the open gaps:

- The Java vtable slot targets are now proven for the base `ReadValuesOperation`; the remaining branch-selection gap has moved into the per-setting availability predicate/sub-object used by `VagOperationDelegate::getVagSettingAvailabilityForEcu`.
- For the normal no-`AvailBy` branches recovered so far, branch availability is selected by the constructor `StringWhitelist` matching the ECU tag, not by the raw DID or setting type alone.
- `left_fog_light_as` / `right_fog_light_as` still have no VAG constructor proof. The next static target is the availability predicate map or setting sub-object path, not the Java JNI bridge.
- The raw-type switch confirms why the reproduction must keep UDS adaptation reads, UDS coding reads, VAG CAN adaptation reads, and submodule reads separate. A visible Carista setting key is not enough to infer the raw read/write path.

---

## Fog Role Constructor Pass - 2026-05-06

Scope: static Ghidra address-target exports only, plus synthesis with the 2026-05-05 live behavior. No live vehicle write was performed.

The left/right `cornering_lights_via_fogs_*` constructor proof is now stronger on the older ARM native path. The second right-side constructor callee was added to `ExportCaristaAddressTargets.java` and regenerated with:

```powershell
.\carista_apk_analysis\setup_ghidra_re.ps1 -ExportAddressTargets
```

Newly confirmed helper chains:

| Setting | Call site | Wrapper | Constructor callee | Class allocated |
|---|---:|---:|---:|---|
| `car_setting_cornering_lights_via_fogs_left` | `01082988` | `010B90CC` | `010E44E8` | `VagUdsAdaptationSetting` |
| `car_setting_cornering_lights_via_fogs_left` | `01082A4A` | `010B5620` | `010D2BD0` | `VagUdsAdaptationSetting` |
| `car_setting_cornering_lights_via_fogs_right` | `01082B78` | `010B8574` | `010E0DE8` | `VagUdsAdaptationSetting` |
| `car_setting_cornering_lights_via_fogs_right` | `01082C34` | `010B9120` | `010E466C` | `VagUdsAdaptationSetting` |

`target_010E47E4.c` was also generated and confirms another `VagUdsAdaptationSetting` constructor callee behind wrapper `010B9170`; that wrapper is retained as typed background evidence, but it is not referenced by the current `01082988` / `01082A4A` / `01082B78` / `01082C34` fog-role windows.

Live-behavior explanation:

- The persisted `0600` long-coding target turned on the Carista-shaped cornering master bits, but the physical fogs still behave as steady low-beam-linked outputs and turn off with high beam.
- That behavior fits a role/output conflict more than a missing cornering master bit: the fog outputs appear to be assigned to a coming-home/leaving-home or low-beam-linked role, so turn-signal input never gets visible ownership of them.
- The strongest static clue is that Carista's per-side fog-role tables carry `1E=car_setting_enabled_coming_home_or_leaving_home` next to `16` for left-cornering and `17` for right-cornering, and the car repeatedly returned stable `220601 -> 6206011E` across switch states.

Possible fix path, still blocked from live write:

1. Prove which runtime branch Carista selects for `6R0937087K` for the two per-side role settings and the CH/LH output settings.
2. Find a positive read path for the current per-side role payload, or prove an alternate Carista read/cache/source path that supplies the raw bytes Carista would write.
3. Only after that proof, evaluate whether the matched repair is per-side role `1E -> 16/17`, a CH/LH output/master change, or both.

Safety boundary remains unchanged: the recovered type `7` path reads the per-side role objects as direct UDS raw DIDs `22055C` / `22055D`, and the car returned `7F2231` for both. There is still no safe seed for `2E055C` / `2E055D`, and no write should be built from the static choice table alone.

2026-05-06 companion-DID follow-up:

- `0601=1E` is now the top actual-fix clue. Historical switch-state reads kept
  `6206011E` stable across switch left/middle/right, pulled-fog states, and
  turn-signal states, so it behaves like stored configuration/status.
- The `1E` byte matches the recovered `car_setting_enabled_coming_home_or_leaving_home`
  enum in the per-side fog-role tables, but no official x86 6R/PQ25 branch or
  positive raw read ties DID `0601` to a writable Carista object yet.
- `0606=001800018000` remains a weaker companion: successful isolated reads
  reassembled to that same payload, but the retained switch-state sweeps do not
  prove any lamp-state correlation.
- The next proof step is a focused read-only before/after or state-correlation
  capture, preferably with raw CAN light-context headers, not a direct write.

2026-05-06 x86 `0601` static recovery pass:

- Primary authority is still official Play 9.8.3 x86 `libCarista.so`; ARM is
  only corroboration when it explains older tables or part-pattern scope.
- `carista_apk_analysis/scan_x86_0601_static_evidence.py` disassembles the x86
  library with Capstone/pyelftools and found zero decoded instruction operands
  for `0x0601`, `0x0606`, `0x220601`, `0x220606`, `0x620601`, or `0x620606`.
- The x86 binary contains `car_setting_enabled_coming_home_or_leaving_home` in
  `.rodata` at `0x006D0F27`, but the same scan found no decoded instruction
  reference or raw pointer tying that enum string to DID `0601`.
- The only exported target-level `0x0601` hit inspected so far is a
  `NissanLiveData` whitelist initializer, not a VAG setting constructor. Other
  x86 raw/ascii hits are symbol/relocation, PDX, unwind, or table noise until a
  decoded VAG constructor or `ReadValuesOperation` path proves otherwise.
- One x86 readable simulator/sample-response row does mirror this car's value:
  `ECU VAGCAN20 220601: 6206011E` with
  `220606: 620606001800038000`. Treat that as sample-response evidence, not a
  recovered `0601` Setting constructor or write path.
- Current classification: `0601=1E` is a strong live role clue, but x86 does not
  yet prove whether it is stored config, status/current-value container, or a
  read-only mirror of another setting.
- The next static choke point is therefore still
  `VagOperationDelegate::getVagSettingAvailabilityForEcu`: recover the special
  setting predicate/vtable slot `+0x3C`, then dump the selected
  `StringWhitelist` contents for normal `AvailBy=2` branches and match those to
  `6R0937087K`.

2026-05-07 turn-signal-cornering bit review, updated with the latest retained
2026-05-08 coding:

- Latest retained coding has byte `0x15 = 82`, so byte 21 bit 2
  (`car_setting_cornering_lights_with_turn_signals`) is clear. Full expert
  backup sets byte `0x15` to `86`.
- Official x86 evidence keeps this setting narrow: `0x012da72c -> 0x012da761`
  passes `CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S`, byte `0x15`, mask `0x04`, and
  `YES_NO`. The branch has no fog/low-beam role choice table and no per-side
  output mapping.
- External PQ25/VCDS references agree with that interpretation. VAG-Coding's
  Polo 6R note says Byte 21 Bit 2 activates cornering lights with the fog lamps
  when the indicator is active. The Seat Ibiza 6J/PQ25 VCDS note describes the
  same bit as a blinker trigger: below about 15-20 km/h, cornering fogs can
  activate from steering angle and/or the blinker; disabling the bit removes the
  blinker trigger while steering-angle cornering remains.
- Therefore Byte 21 Bit 2 being enabled is normal if the goal is
  turn-signal-triggered cornering. It can make a cornering lamp stay on while
  waiting with the blinker on, but it does not explain both front fogs being
  steadily on in the headlight switch position with no useful left/right
  ownership.
- The steady paired-fog symptom remains more consistent with a separate
  fog-switch request, output-role/CH-LH assignment, BCM wiring, or unsupported
  per-side output on this `087K` BCM. Do not use Byte 21 Bit 2 as the next fix
  lever except as a temporary baseline-off comparison.
- External Polo 6R retrofit discussions also keep wiring in scope: front fog /
  turning-light harnesses route the two fog outputs to BCM plug B pins 9 and 10
  and permanent supply to B11, while other setups distinguish switch-powered
  fogs from BCM-controlled cornering/static-cornering lamps. If both fogs are
  steady in the headlight switch position with no fog pull, that is more likely
  a fog-request/wiring/output-role issue than the Byte 21 Bit 2 trigger bit.

External references retained for this distinction:

```text
https://www.vag-coding.fr/vw/polo-5-6r/polo-5-6r-corner-lights-avec-clignotant/
https://automobiles.fredericbazin.fr/PDF/TutoVCDS/PDF/Ibiza%206J%20VCDS%20Options%20EN.pdf
https://vwforum.ro/topic/82461-info-detaliere-coduri-modul-09-central-electronics/
https://www.mypolo.nl/xenforo/threads/bochtverlichting-en-mistlampen.17681/page-2#post-293870
https://www.uk-polos.net/viewtopic.php?p=553138
```

2026-05-07 cause narrowing after DRL-via-fogs failed, updated with the latest
retained 2026-05-08 coding:

- The latest retained coding has byte `0x0C` mask `0x40` and byte `0x15` mask
  `0x80` set. Byte `0x15` masks `0x04` and `0x20`, and byte `0x17` mask `0x04`,
  are clear after rollback. Static x86 evidence gives no remaining direct
  `0600` cornering trigger branch for `6R0937087K`.
- The observed behavior is a paired front-fog request: both fogs are steady in
  the low-beam/headlight switch position and go off with high beam. That is
  exactly what the already-set `turn_off_fogs_with_high_beam` bit would do to a
  normal front-fog request. It is not evidence that the blinker-trigger bit is
  wrong.
- The top practical hypothesis is now switch input or wiring: the BCM may be
  receiving the front-fog switch request on `T73a/7` whenever low beams are on,
  or the lamps may be wired through an ordinary/bridged fog circuit instead of
  independent BCM static-cornering outputs. Factory switch behavior is
  pull-to-front-fog, so front fogs on in the plain low-beam position should be
  treated as abnormal unless the car has a deliberate non-factory module.
- PQ25 wiring references identify `T73b/9` and `T73b/10` as the separate left
  and right cornering/fog outputs and `T73b/11` as the supply path. External
  retrofit notes also distinguish fuse 54 ordinary fog wiring from fuse 57
  BCM-controlled static-cornering wiring. If the car is on the ordinary/bridged
  path, software bits cannot produce left/right ownership.
- Ross-Tech thread `26139` is directly relevant: a PQ25 `6R7 937 087 H` retrofit
  accepted byte 21 bits 2/7 but did not work until byte 12 bit 6 was also set
  and the light-switch wire was corrected to `T73a/7`; the thread also calls out
  `T73b/11` terminal-30 supply. Its final coding changed byte 12 bit 6 and byte
  21 bits 2/7, which are already set on this Polo. That makes the thread
  supporting evidence for wiring/state/role ownership, not a new coding bit.
- Byte 12 bit 0 is related to the wider parking/DRL wiring problem space but is
  not proven as the current direct cause. External Polo 6R references describe it as
  Scandinavian/Nordic mode (`parking lights ON with terminal 15 ON`) and warn
  that it can disrupt fog behavior in sidelights/parking-light mode because the
  BCM treats the signal as DRL/parking-light state. The latest 2026-05-08
  captured coding has byte `0x0C = 6D`, so bit 0 is set. Earlier controlled
  codings with byte `0x0C = 6C` make this a live-tested axis, but not a
  recovered Carista role selector or safe standalone fix.
- The strongest remaining software clue is still `220601 -> 6206011E`, because
  `1E` overlaps the per-side role enum value
  `car_setting_enabled_coming_home_or_leaving_home`. This remains a read-only
  clue only: x86 static recovery has found no decoded `0601` Setting constructor,
  and direct `055C` / `055D` reads reject on this BCM.

Next car-session inspection path, no new write implied:

1. Confirm whether the front fog indicator is lit when the fogs are on in the
   low-beam/headlight switch position without pulling the switch. If yes, the
   BCM likely sees an active front-fog request.
2. Check whether pulling/pushing the fog switch changes the fog state or
   indicator independently. If it does not, suspect `T73a/7` or light-switch pin
   wiring.
3. Track byte 12 bit 0 explicitly in any future coding snapshot. It is a
   parking/DRL/Standlicht mode bit, not a recovered cornering-output selector.
4. Inspect the fuse/wiring path: fuse 54 ordinary front-fog path versus fuse 57
   BCM/static-cornering path; verify separate wires to `T73b/9` and `T73b/10`
   and supply on `T73b/11`.
5. Only after that, continue static work on `0601` / CH-LH role ownership. Do
   not write `0601`, `055C`, or `055D` from the current evidence.

Additional external references retained for the wiring/output-owner hypothesis:

```text
https://polo.blue/bcm-pq25-t73a-t73b/
https://polo.blue/info-about-bcm-pq25/
https://uk-polos.net/viewtopic.php?p=576321
https://www.clubpolo.co.uk/topic/312041-where-to-find-the-bcm-number-on-a-6r/
https://portal-diagnostov.com/en/2021/01/24/6645648-vw-polo-2010-daytime-running-light-and-fog-lights-wiring-diagrams-pin/
https://uk-polos.net/viewtopic.php?sid=17958e1f0bb230ca944f00c1c477e7a6&start=45&t=74767
https://www.vwpolo.net/switching_lights_on_and_off-128.html
https://forums.ross-tech.com/index.php?threads/26139/
https://uk-polos.net/viewtopic.php?p=589389
https://uk-polos.net/viewtopic.php?start=15&t=77188
https://uk-polos.net/viewtopic.php?p=492025
```

---

## UDS Coding Constructor Packing Pass - 2026-05-06

Scope: static constructor export synthesis only. No live vehicle work.

The named `VagUdsCodingSetting` constructor exports prove the older ARM immediate pairs are not standalone raw DIDs. They are DID `0600` coding masks:

- `VagUdsCodingSetting(Ecu*, StringWhitelist, int, vector<unsigned char>, ...)` calls `VagSetting` with raw address `0x0600` and type `8`.
- `VagUdsCodingSetting(Ecu*, StringWhitelist, int, unsigned char, ...)` first builds a one-byte vector, then calls the vector constructor.
- The constructor `int` is the `VagSetting` offset field used by `VagSetting::insertValue`; the byte/vector is the mask vector.

Newly typed lighting packing:

| Setting | Helper chain | DID `0600` coding packing |
|---|---|---|
| `car_setting_coming_home_req_rls` | `010B0D5C -> 010BC860 -> VagUdsCodingSetting`; `010B19D0 -> 010C0708 -> VagUdsCodingSetting` | byte `0x11`, mask `0x20`; byte `0x0A`, mask `0x04` |
| `car_setting_coming_home` | `010B2040 -> 010C2700 -> VagUdsCodingSetting`; `010B3AF0 -> 010CA958 -> VagUdsCodingSetting` | byte `0x06`, mask `0x02`; byte `0x07`, mask `0x01` |
| `car_setting_coming_leaving_home_output` | `010B4218 -> 010CCBC8 -> VagUdsCodingSetting` | byte `0x0D`, mask `0x40`; byte `0x11`, mask `0x08` |
| `car_setting_coming_home_via_low_beams` | `010B5A98 -> 010D4140 -> VagUdsCodingSetting` | byte `0x06`, mask `0x10` |
| `car_setting_coming_home_via_fogs` | `010B19D0 -> 010C0708 -> VagUdsCodingSetting` | byte `0x06`, mask `0x20` |
| `car_setting_leaving_home_req_rls` | `010B19D0 -> 010C0708 -> VagUdsCodingSetting` | byte `0x0A`, mask `0x02` |
| `car_setting_leaving_home` | `010B71D0 -> 010DAEDC -> VagUdsCodingSetting`; `010B0C78 -> 010BC404 -> VagUdsCodingSetting` | byte `0x06`, mask `0x04`; byte `0x07`, mask `0x08` |
| `car_setting_turn_off_fogs_with_high_beam` | `010B69C0 -> 010D88A0 -> VagUdsCodingSetting` | byte `0x15`, mask `0x20`; byte `0x0E`, mask `0x04`; byte `0x04`, mask `0x02` |
| `car_setting_turn_off_fogs_with_high_beam` | `010B8480 -> 010E0970 -> VagCanLongCodingSetting` | long-coding byte `0x11`, mask `0x20` |
| `car_setting_assist_dr_lights` | `010B74A0 -> 010DBC4C -> VagUdsCodingSetting` | byte `0x16`, mask `0x20` |

Impact:

- The coding branch packing for the most relevant CH/LH and fog/high-beam settings is now recovered as DID `0600` byte/mask data.
- This still is not a live write plan. The unresolved part is now runtime branch selection and requested-choice encoding, not the DID/byte/mask shape for these UDS coding branches.
- The rejected adaptation reads remain negative evidence for their direct type-7 branches only; they do not disprove the adjacent DID `0600` coding branches.

---

## x86-Preferred PQ25 Branch Selection Pass - 2026-05-06

Scope: official Play 9.8.3 x86 `libCarista.so` static tracing only. No live
vehicle work.

The x86 constructor argument trace now resolves several `AvailBy=2` whitelist
branches against the `6R0937087K` ECU-tag route:

| Setting | x86 6R/PQ25 branch fact | Current car implication |
|---|---|---|
| `car_setting_coming_home_req_rls` | Reused-key branch `0x012c74fe -> 0x0133b390`, `CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S`, DID `0600` byte `0x0A`, mask `0x04`; adjacent `coming_home_menu_default_req_rls` is MK7/6C raw `0x0D04` adaptation evidence. | PQ25 CH/LH prerequisite branch is now x86-confirmed, but it is not a `0601` owner path and not a standalone cornering-fog write plan. |
| `car_setting_cornering_lights_via_fogs` | `0x012d9f7b -> 0x01358fd0`, `CENTRAL_ELEC_6R_5C_7E_7H`, byte `0x0C`, mask `0x40` | Already set in live coding; behavior-disproven as standalone fix. |
| `car_setting_cornering_lights_via_fogs_experimental` | `0x012da0f2 -> 0x0135eaf0`, `CENTRAL_ELEC_6R_5C_7E_7H`, byte `0x15`, mask `0x80` | Latest retained byte `0x15 = 0x82`; bit set. |
| `car_setting_cornering_lights_with_turn_signals` | `0x012da761 -> 0x0135e920`, `CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S`, byte `0x15`, mask `0x04` | Latest retained byte `0x15 = 0x82`; bit clear. Full expert backup sets byte `0x15` to `0x86`. |
| `car_setting_drl_via_fogs` | `0x012cdeb6 -> 0x01361520`, `CENTRAL_ELEC_6R_5C_7E_7H`, byte `0x17`, mask `0x04` | Set by the 2026-05-07 live write; behavior unchanged; latest retained coding has it clear after rollback. |
| `car_setting_turn_off_fogs_with_high_beam` | `0x012d4dea -> 0x0135e580`, `CENTRAL_ELEC_6R_5C_7E_7H`, byte `0x15`, mask `0x20` | Latest retained byte `0x15 = 0x82`; bit clear. Older byte `0xA6` state had it set. |
| `car_setting_assist_dr_lights` | `0x012d9bad -> 0x013625a0`, `CENTRAL_ELEC_6R_5C_7E_7H`, byte `0x16`, mask `0x20` | Clear on current car; lower-priority ADL clue. |

Negative x86 branch-selection facts:

- `car_setting_coming_home_req_rls` now has a recovered x86 6R/PQ25 DID `0600`
  byte `0x0A` mask `0x04` branch, but this is a CH/LH prerequisite branch, not
  the unresolved `0601` role owner.
- `car_setting_coming_leaving_home_output` direct x86 branches are
  `CENTRAL_ELEC_MK8` or `UDS_CAN_GATEWAY_MEB`; no x86 6R/PQ25 branch is
  recovered.
- `car_setting_coming_home_via_low_beams` and
  `car_setting_coming_home_via_fogs` direct x86 branches are B8-scoped; the
  older ARM DID `0600` branches remain build/version evidence, not x86 6R proof.
- The per-side `055C` / `055D` role branches remain MQB/MK8 or gateway/MEB
  scoped on x86, matching the earlier ARM-negative conclusion. The older ARM
  per-side region also loads part-number patterns `5Q0937084*` and
  `6C093708*`, but no `6R0937087K` / `6R0-937-08x` pattern was recovered for
  the `055C` or `055D` paths.
- A preferred x86 sweep found no decoded instruction operand immediate `0x0601`
  or `0x0606`; the positive live companion reads stay unresolved companions, not
  recovered native setting branches.

Near-term car-read conclusion:

- Do not retest byte `0x0C` mask `0x40`, byte `0x15` mask `0x80`, or byte
  `0x15` mask `0x04` as standalone fixes; they are either set in the latest
  retained coding or behavior-disproven from earlier enabled tests.
- The remaining likely gap is an output-role/prerequisite path not exposed by the
  direct per-side `055C` / `055D` branches.

## VW/PQ25 Fog Output-Role / Prerequisite Pass - 2026-05-06

The output-role path is now separated into three buckets for the actual
`6R0937087K` car:

| Bucket | Evidence | Current conclusion |
|---|---|---|
| Recovered 6R/PQ25 prerequisites | `cornering_lights_via_fogs`, `cornering_lights_via_fogs_experimental`, `cornering_lights_with_turn_signals`, and `turn_off_fogs_with_high_beam` all have x86 6R/PQ25 DID `0600` byte/mask branches. | These masks are either set in the latest retained coding or behavior-disproven from earlier enabled tests; none is a standalone output-role fix. |
| Per-side fog role/output branches | `cornering_lights_via_fogs_left/right` recover `055C`/`055D` offset `5` mask `FF`, but x86 guards are MQB/MK8 or gateway/MEB. ARM neighbors include `5Q0937084*` and `6C093708*`, not `6R0937087K`. | Do not promote these to the Polo path without a separate special-predicate proof or positive raw payload. |
| CH/LH output selector | `coming_leaving_home_output` has branch-specific `110E`, DID `0600` byte `0x0D` mask `0x40`, and DID `0600` byte `0x11` mask `0x08` encodings. `22110E` rejected live and x86 direct branches are MK8/gateway scoped. | Current value is intentionally reported as unknown because the choice encoding flips by branch. |

This makes the present gap narrower: find a recovered VAG branch or runtime
`ReadValuesOperation` value object that is actually selected for `6R0937087K`,
instead of reusing the Ford direct labels or the non-6R per-side `055C`/`055D`
constructors.
