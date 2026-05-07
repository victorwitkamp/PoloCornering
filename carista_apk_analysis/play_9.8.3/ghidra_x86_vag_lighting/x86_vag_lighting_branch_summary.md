# Play 9.8.3 x86 VAG Lighting Branch Export

Program: `libCarista.so`
Image base: `00010000`
Recovered x86 VA mapping: `Ghidra address - image base`

## Branch Windows

| Label | Address | Setting key | Recovered shape | Function |
|---|---:|---|---|---|
| `coming_home_via_fogs` | `012c929b` | `car_setting_coming_home_via_fogs` | lighting output branch cluster; x86 direct branch observed as non-6R/B8-style until availability is recovered | `<none>` |
| `drl_via_fogs` | `012cde7b` | `car_setting_drl_via_fogs` | official x86 6R/PQ25 branch later pushes CENTRAL_ELEC_6R_5C_7E_7H, DID 0600 byte 0x17 mask 0x04 | `<none>` |
| `turn_off_fogs_with_high_beam` | `012d4db5` | `car_setting_turn_off_fogs_with_high_beam` | official x86 6R/PQ25 branch later pushes CENTRAL_ELEC_6R_5C_7E_7H, DID 0600 byte 0x15 mask 0x20 | `<none>` |
| `fog_lights_on_reverse_d1d` | `012d62e6` | `car_setting_fog_lights_on_reverse` | DID/raw address 0x0D1D branch family guarded by MK7/6C/MQB/MK8/gateway whitelists, not recovered 6R/PQ25 whitelists | `<none>` |
| `cornering_lights_via_fogs` | `012d9ed4` | `car_setting_cornering_lights_via_fogs` | official x86 6R/PQ25 branch later pushes CENTRAL_ELEC_6R_5C_7E_7H, DID 0600 byte 0x0C mask 0x40 | `<none>` |
| `cornering_lights_via_fogs_experimental` | `012da0bd` | `car_setting_cornering_lights_via_fogs_experimental` | official x86 6R/PQ25 branch later pushes CENTRAL_ELEC_6R_5C_7E_7H, DID 0600 byte 0x15 mask 0x80 | `<none>` |
| `cornering_lights_via_fogs_left` | `012da210` | `car_setting_cornering_lights_via_fogs_left` | same-key x86 branches use MQB/MK8 or gateway/MEB guards; nearby immediates include 0x055C offset 5 mask 0xFF | `<none>` |
| `cornering_lights_via_fogs_right` | `012da55f` | `car_setting_cornering_lights_via_fogs_right` | same-key x86 branches use MQB/MK8 or gateway/MEB guards; nearby immediates include 0x055D offset 5 mask 0xFF | `<none>` |
| `cornering_lights_with_turn_signals` | `012da72c` | `car_setting_cornering_lights_with_turn_signals` | official x86 explicit turn-signal 6R/PQ25 branch later pushes CENTRAL_ELEC_6R_5C_7E_7H_EXP_1S, DID 0600 byte 0x15 mask 0x04 | `<none>` |
| `cornering_lights_activation_d1d` | `012da8bd` | `car_setting_cornering_lights_activation` | DID/raw address 0x0D1D activation branch family guarded by MK7/6C/MQB/B8 whitelists/access codes, not recovered 6R/PQ25 whitelists | `<none>` |
| `cornering_lights_min_activation_speed_d1d` | `012daf54` | `car_setting_cornering_lights_min_activation_speed` | DID/raw address 0x0D1D offset 3 mask 0xFF branch family guarded by MK7/MQB/gateway-style guards | `<none>` |
| `cornering_lights_max_activation_speed_d1d` | `012db176` | `car_setting_cornering_lights_max_activation_speed` | DID/raw address 0x0D1D offset 4 mask 0xFF branch family guarded by MK7/MQB/gateway-style guards | `<none>` |

## Decompiled Helper Targets

| Label | Address | Reason | Function |
|---|---:|---|---|
| `VagCanSettings_getSettings` | `012a20c0` | owning constructor-list function; exported as metadata and branch windows only because the function is huge | `_ZN14VagCanSettings11getSettingsEv @ 012a20c0` |
| `VagUdsCodingSetting_cornering_fogs` | `01358fd0` | callee reached by car_setting_cornering_lights_via_fogs 6R/PQ25 branch; PLT relocation resolves to `VagUdsCodingSetting` | `<none>` |
| `VagUdsCodingSetting_cornering_fogs_experimental` | `0135eaf0` | callee reached by car_setting_cornering_lights_via_fogs_experimental 6R/PQ25 branch | `<none>` |
| `VagUdsCodingSetting_cornering_turn_signals` | `0135e920` | callee reached by car_setting_cornering_lights_with_turn_signals 6R/PQ25 branch | `<none>` |
| `VagUdsCodingSetting_drl_via_fogs` | `01361520` | callee reached by car_setting_drl_via_fogs 6R/PQ25 branch; PLT relocation resolves to `VagUdsCodingSetting` | `<none>` |
| `VagUdsCodingSetting_turn_off_fogs_high_beam` | `0135e580` | callee reached by car_setting_turn_off_fogs_with_high_beam 6R/PQ25 branch | `<none>` |
| `VagCanLongCodingSetting_turn_off_fogs_high_beam_mk5` | `01368100` | non-6R same-key helper reached by car_setting_turn_off_fogs_with_high_beam; PLT relocation resolves to `VagCanLongCodingSetting` | `<none>` |
| `VagUdsAdaptationSetting_left_fog_role_mqb` | `0136c910` | x86 left-side same-key UDS adaptation helper using MQB/MK8-style guards | `<none>` |
| `VagUdsAdaptationSetting_left_fog_role_gateway` | `01356f90` | x86 left-side same-key UDS adaptation helper using gateway/MEB-style guards | `<none>` |
| `VagUdsAdaptationSetting_right_fog_role_mqb` | `01368690` | x86 right-side same-key UDS adaptation helper using MQB/MK8-style guards | `<none>` |
| `VagUdsAdaptationSetting_right_fog_role` | `0136caf0` | x86 right-side same-key helper using gateway/MEB-style guards | `<none>` |
| `VagUdsAdaptationSetting_fog_reverse_mk7` | `013591a0` | D1D fog-on-reverse helper reached from MK7/gateway variants | `<none>` |
| `VagUdsAdaptationSetting_fog_reverse_mk7_new` | `013691d0` | D1D fog-on-reverse helper reached from MK7_NEW/MK8 variant | `<none>` |
| `VagUdsAdaptationSetting_cornering_activation` | `0133e9f0` | D1D cornering activation helper reached from MK7_6C and MK7_NEW_MQBA0 variants | `<none>` |
| `VagUdsCodingSetting_cornering_activation_b8` | `0135e750` | D1D-adjacent B8 UDS-coding helper in the activation cluster | `<none>` |
| `VagUdsAdaptationSetting_cornering_speed` | `0136ccc0` | D1D min/max activation-speed helper reached from MK7_ALL variants | `<none>` |
| `VagUdsAdaptationSetting_cornering_speed_mk7_new` | `0136cea0` | D1D min/max activation-speed helper reached from MK7_6C and MK7_NEW_MQBA0 variants | `<none>` |
| `VagUdsAdaptationSetting_cornering_speed_mk8` | `0136d080` | D1D max activation-speed helper reached from MK7_NEW/MK8-derived variant | `<none>` |
| `VagSetting_isSubmodule` | `01426dd0` | vtable slot +0x3C predicate target recovered from VagOperationDelegate availability routing | `_ZNK10VagSetting11isSubmoduleEv @ 01426dd0` |
| `VagOperationDelegate_getVagSettingAvailabilityForEcu` | `016b4180` | x86 availability function that calls VagSetting::isSubmodule before normal AvailBy/StringWhitelist handling | `_ZN20VagOperationDelegate31getVagSettingAvailabilityForEcuERKNSt6__ndk110shared_ptrI10VagSettingEERKNS1_I10VagEcuInfoEE @ 016b4180` |
| `StringWhitelist_itemMatches` | `00cd97b0` | x86 StringWhitelist::itemMatches behavior recovered from Play 9.8.3 | `_ZNK15StringWhitelist11itemMatchesERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEES8_ @ 00cd97b0` |
