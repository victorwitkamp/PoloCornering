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
- `docs/carista_apk_analysis/vag_can_settings_recoveries.json`

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

The left and right fog-cornering settings are both `VagUdsAdaptationSetting` type `7`, offset `5`, mask `FF`, but the `car_setting_on` enum differs by side.

| Setting | Raw address | Offset | Mask | Recovered choices |
| --- | ---: | ---: | ---: | --- |
| `car_setting_cornering_lights_via_fogs_left` | `055C` | `5` | `FF` | `00=off`, `16=on`, `1E=enabled_coming_home_or_leaving_home` |
| `car_setting_cornering_lights_via_fogs_right` | `055D` | `5` | `FF` | `00=off`, `17=on`, `1E=enabled_coming_home_or_leaving_home` |

Evidence:

- `cornering_fogs_left_ref_1_01082988.txt`: `movw r0,#0x55c`, `movs r1,#0x5`, `movs r2,#0xff`, `movs r1,#0x1e`, `movs r2,#0x16`.
- `cornering_fogs_left_ref_2_01082A4A.txt`: second left variant confirms `0x55c`, offset `5`, `0x1e`, `0x16`.
- `cornering_fogs_right_ref_1_01082B78.txt`: `movw r0,#0x55d`, `movs r1,#0x5`, `movs r2,#0xff`, `movs r1,#0x1e`, `movs r2,#0x17`.
- `cornering_fogs_right_ref_2_01082C34.txt`: second right variant confirms `0x55d`, offset `5`, `0x1e`, `0x17`.

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
- Status: this setting is now known to be mixed, with a UDS adaptation path and two UDS coding variants. `22110E` only covers the adaptation path and returned `7F2231` live on 2026-05-05. The UDS coding variants are now typed as DID `0600` byte/mask `0D/40` and `11/08`; runtime branch selection and requested-choice encoding still need recovery before writing.

### `car_setting_left_fog_light_as` / `car_setting_right_fog_light_as` — still non-VAG

- The refs-only probe confirms both keys' first string references land only in `FUN_00E314FE`, which is the non-VW / Ford-path constructor zone.
- No reference was found in `FUN_0105f6c0` for either of these highest-priority keys.
- The VAG/PQ25 availability path for `left_fog_light_as` / `right_fog_light_as` must be reached via a different mechanism — either a different outer function, a sub-object, or the `ReadValuesOperation` vtable. This is the main remaining static RE gap.

### `car_setting_assist_dr_lights` — confirmed

- Instruction window `0108252C` confirms helper `010B74A0 -> 010DBC4C -> VagUdsCodingSetting`, immediate pair `0x20 / 0x16` immediately before the key label.
- The `0x16` field is byte index 22 (decimal); `0x20` is the bit-mask value, consistent with byte 22 bit 5 in the candidate table.

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

Impact on the open gaps:

- The Java vtable slot targets are now proven for the base `ReadValuesOperation`; the remaining branch-selection gap has moved into the per-setting availability predicate/sub-object used by `VagOperationDelegate::getVagSettingAvailabilityForEcu`.
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
