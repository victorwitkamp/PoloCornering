# PQ25 Carista Setting Catalog

Date: 2026-05-06

**Historical catalog note (2026-05-14):** this file preserves the generated
2026-05-06 catalog. For the current retained in-car state, use
`../OBD_DIAGNOSTICS/pq25_evidence_matrix.md`. The latest retained coding is
`3AB02BBF08A10000003008006D2B0CD000C0412F60820000200000000000`, so older rows
showing byte 21 as `A2`/`A6` are historical context, not current state.

This is an offline catalog for the Polo/PQ25 BCM work. It joins Carista app resources/native strings, the current 30-byte long coding, the supplied/reference coding, and the local PQ25 candidate bit map.

It is not a Carista live `ReadValuesOperation.getAvailableItems()` dump. Rows marked unmapped are visible in the app resources but not proved supported on this exact BCM.

## Outputs

```text
carista_apk_analysis/pq25_carista_settings_catalog.csv
carista_apk_analysis/pq25_carista_longcoding_bits.csv
carista_apk_analysis/pq25_carista_setting_catalog.json
docs/CARISTA_REVERSE/pq25_carista_setting_catalog.md
```

## Summary

- App-visible Carista setting/resource rows: `3669`
- Lighting-related rows: `742`
- Rows mapped to PQ25 long-coding bits: `9`
- Long-coding bits emitted: `240`
- Candidate/mapped long-coding bits: `15`
- Bits differing from supplied/reference coding: `2`

## Current Read/Write Method Boundary

- Long coding read: TP2.0 unit 20 direct read 220600; positive response is 620600 + 30-byte coding.
- Guarded full-coding write: Validated guarded path: 2EF199 date, inline 22F1A5, 2EF198 workshop code, then 2E0600 + full 30-byte coding. The former live runner was removed after use..
- Native compact Carista setting write: Native Carista setting path appears to build 3B9A + 6-byte value + 4-byte rawAddress4 + tail; rawAddress4/coding type/tail are not recovered for this BCM.
- Native UDS raw-value setting write: Native Carista type 7/8 raw-value settings dispatch to WriteDataByIdentifier 2E<DID> after F199/F198; 055C/055D type 7 direct reads returned 7F2231 live, so no safe raw payload seed is available for those settings.
- Native adaptation/routine path: Carista VAG CAN adaptation/routine path is 31B8/31BA/31B9/31BA/32B8 with short id 0103 and long id 010A; native proof applies to raw types 0/1, not the recovered 055C/055D raw type 7 settings.

## Highest-Value Unresolved Settings

These are the settings to recover before more in-car writes.

| Key | Label | Bits | Current | Reference | Status | Priority |
|---|---|---|---|---|---|---|
| `car_setting_cornering_lights_via_fogs_left` | Left cornering light (using fog light) | - | - | - | native_vag_uds_adaptation_candidate | alternate_vag_path_recovery_target |
| `car_setting_cornering_lights_via_fogs_right` | Right cornering light (using fog light) | - | - | - | native_vag_uds_adaptation_candidate | alternate_vag_path_recovery_target |
| `car_setting_left_fog_light_as` | Use the left fog light as… | - | - | - | direct_label_resolved_non_vag_ford | alternate_vag_path_recovery_target |
| `car_setting_right_fog_light_as` | Use the right fog light as… | - | - | - | direct_label_resolved_non_vag_ford | alternate_vag_path_recovery_target |

## Settings Mapped To PQ25 Bits

| Key | Label | Bits | Current | Reference | Status | Priority |
|---|---|---|---|---|---|---|
| `car_setting_assist_dr_lights` | Assistant Driving Light (ADL) | byte 22 bit 5 | clear (412F60A20000) | clear (412F60A60000) | mapped_to_external_pq25_candidate | low_context |
| `car_setting_coming_home_via_fogs` | Use fog lights as coming-home lights | byte 13 bit 6 | set (2C680ED000C8) | set (6C680ED000C8) | mapped_to_external_pq25_candidate | low_context |
| `car_setting_coming_home_via_low_beams` | Use low beams as coming-home lights | byte 13 bit 6 | set (2C680ED000C8) | set (6C680ED000C8) | mapped_to_external_pq25_candidate | low_context |
| `car_setting_coming_leaving_home_output` | Coming/leaving-home lights use… | byte 13 bit 6 | set (2C680ED000C8) | set (6C680ED000C8) | mapped_to_external_pq25_candidate | low_context |
| `car_setting_cornerig_lights_with_turn_signal` | Activate cornering lights with turn signal | byte 21 bit 2 | clear (412F60A20000) | set (412F60A60000) | mapped_to_long_coding_candidate_but_live_behavior_ruled_out | resolved_for_current_symptom |
| `car_setting_cornering_lights_via_fogs` | Cornering lights (using fog lights) | byte 12 bit 6 | clear (2C680ED000C8) | set (6C680ED000C8) | mapped_to_long_coding_candidate_but_live_behavior_ruled_out | resolved_for_current_symptom |
| `car_setting_cornering_lights_via_fogs_experimental` | Cornering lights (using fog lights) (experimental) | byte 12 bit 6 | clear (2C680ED000C8) | set (6C680ED000C8) | mapped_to_same_bit_as_cornering_lights_via_fogs | resolved_for_current_symptom |
| `car_setting_cornering_lights_with_turn_signals` | Turn on cornering lights when turn signal is on | byte 21 bit 2 | clear (412F60A20000) | set (412F60A60000) | mapped_to_same_bit_as_turn_signal_cornering | resolved_for_current_symptom |
| `car_setting_use_cornering_lights` | Use cornering lights… | byte 12 bit 6 | clear (2C680ED000C8) | set (6C680ED000C8) | mapped_to_same_bit_as_cornering_lights_via_fogs | resolved_for_current_symptom |

## Candidate Long-Coding Bits

| Byte | Bit | Current | Reference | Candidate | Carista keys | Status | Tested |
|---:|---:|---|---|---|---|---|---|
| 0 | 0 | 3A clear | 3A clear | [low] Front fog lights installed; weak cross-platform reference only | - | long_coding_candidate_without_recovered_carista_setting | not live-isolated |
| 12 | 6 | 2C clear | 6C set | [high] Turn/Cornering Lights installed/active; Carista maps this to cornering lights using fog lights | car_setting_cornering_lights_via_fogs; car_setting_cornering_lights_via_fogs_experimental; car_setting_use_cornering_lights | mapped_to_long_coding_candidate_but_live_behavior_ruled_out; mapped_to_same_bit_as_cornering_lights_via_fogs | live written both ways and behavior unchanged; do not retest blindly |
| 13 | 0 | 68 clear | 68 clear | [medium] Parking Lights ON only without ignition ON possible | - | long_coding_candidate_without_recovered_carista_setting | not live-isolated |
| 13 | 1 | 68 clear | 68 clear | [medium] Parking Lights Function active | - | long_coding_candidate_without_recovered_carista_setting | not live-isolated |
| 13 | 3 | 68 set | 68 set | [medium] Brake Light Activation via Body Control Module (BCM) | - | long_coding_candidate_without_recovered_carista_setting | not live-isolated |
| 13 | 5 | 68 set | 68 set | [medium] Interior Light Enabling via Rear Lid | - | long_coding_candidate_without_recovered_carista_setting | not live-isolated |
| 13 | 6 | 68 set | 68 set | [medium] Coming-Home/Leaving-Home variant; external labels say 0=fog lights,1=low beam | car_setting_coming_home_via_fogs; car_setting_coming_home_via_low_beams; car_setting_coming_leaving_home_output | mapped_to_external_pq25_candidate | not live-isolated |
| 16 | 5 | 00 clear | 00 clear | [low] Lamp Diagnostics for Rear Fog Light(s) active | - | long_coding_candidate_without_recovered_carista_setting | not live-isolated |
| 18 | 2 | 41 clear | 41 clear | [low] Cold diagnosis front fog lights active; weak cross-platform reference only | - | long_coding_candidate_without_recovered_carista_setting | not live-isolated |
| 18 | 3 | 41 clear | 41 clear | [low] Cold diagnosis rear fog lights active; weak cross-platform reference only | - | long_coding_candidate_without_recovered_carista_setting | not live-isolated |
| 19 | 5 | 2F set | 2F set | [low] Lamp Diagnostics for Fog Lights and/or Cornering/Turn Lights active | - | long_coding_candidate_without_recovered_carista_setting | not live-isolated |
| 21 | 2 | A2 clear | A6 set | [high] Cornering/Turn Lights via Turn Signal active; Carista maps this to turn-signal-triggered cornering | car_setting_cornerig_lights_with_turn_signal; car_setting_cornering_lights_with_turn_signals | mapped_to_long_coding_candidate_but_live_behavior_ruled_out; mapped_to_same_bit_as_turn_signal_cornering | live written both ways and behavior unchanged; do not retest blindly |
| 21 | 5 | A2 set | A6 set | [medium] Fog Lights inactive with High Beams active | - | long_coding_candidate_without_recovered_carista_setting | not live-isolated |
| 21 | 7 | A2 set | A6 set | [medium] Front Fog Lights with Turn Lights installed | - | long_coding_candidate_without_recovered_carista_setting | not live-isolated |
| 22 | 5 | 00 clear | 00 clear | [medium] Assistant Driving Light (ADL) active | car_setting_assist_dr_lights | mapped_to_external_pq25_candidate | not live-isolated |

## Bits That Differ From The Supplied/Reference Coding

| Byte | Bit | Current | Reference | Candidate | Carista keys | Status | Tested |
|---:|---:|---|---|---|---|---|---|
| 12 | 6 | 2C clear | 6C set | [high] Turn/Cornering Lights installed/active; Carista maps this to cornering lights using fog lights | car_setting_cornering_lights_via_fogs; car_setting_cornering_lights_via_fogs_experimental; car_setting_use_cornering_lights | mapped_to_long_coding_candidate_but_live_behavior_ruled_out; mapped_to_same_bit_as_cornering_lights_via_fogs | live written both ways and behavior unchanged; do not retest blindly |
| 21 | 2 | A2 clear | A6 set | [high] Cornering/Turn Lights via Turn Signal active; Carista maps this to turn-signal-triggered cornering | car_setting_cornerig_lights_with_turn_signal; car_setting_cornering_lights_with_turn_signals | mapped_to_long_coding_candidate_but_live_behavior_ruled_out; mapped_to_same_bit_as_turn_signal_cornering | live written both ways and behavior unchanged; do not retest blindly |

## Interpretation

The two bits that differ from the supplied/reference coding are already live-tested and did not visibly change the reported fog/indicator behavior. The best current lead is therefore not another blind flip of byte 12/21, nor the direct `left_fog_light_as` / `right_fog_light_as` resource keys now proven Ford-only on x86. The remaining target is an alternate VW/PQ25 VAG key, availability sub-object, or ReadValuesOperation value path behind equivalent fog-role behavior.

For every other long-coding bit, this catalog intentionally says `unknown_long_coding_bit` unless there is a local candidate label or a Carista setting key tied to it. That keeps the map useful without turning resource strings into false proof.
