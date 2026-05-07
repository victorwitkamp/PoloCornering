# Play 9.8.3 x86 Reverse Target Export

Program: `libCarista.so`
Image base: `00010000`
Recovered x86 VA mapping: `Ghidra address - image base`

| Label | Recovered VA | Size | Reason | Function |
|---|---:|---:|---|---|
| `GetVagCanEcuInfoCommand_ctor` | `00c389e0` | `66` | command object constructor for VAG CAN ECU-info command | `_ZN23GetVagCanEcuInfoCommandC2EP9VagCanEcu @ 00c389e0` |
| `GetVagCanEcuInfoCommand_getRequest` | `00c38a90` | `49` | builds the recovered 1A9B ECU-info request | `_ZNK23GetVagCanEcuInfoCommand10getRequestEv @ 00c38a90` |
| `GetVagCanEcuInfoCommand_processPayloads` | `00c38ad0` | `1317` | multi-response ECU-info parser that builds the VagEcuInfo +0x10 submodule vector | `_ZNK23GetVagCanEcuInfoCommand15processPayloadsERKNSt6__ndk16vectorINS1_IhNS0_9allocatorIhEEEENS2_IS4_EEEE @ 00c38ad0` |
| `GetVagCanEcuInfoCommand_processEcuInfo` | `00c39240` | `2741` | single-payload ECU-info parser for part/info string, coding type, rawAddress4, tail, initial coding, and optional suffix text | `_ZNK23GetVagCanEcuInfoCommand14processEcuInfoERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE @ 00c39240` |
| `MultiResponseCommand_VagEcuInfoWithCoding_processResponses` | `00c39e60` | `297` | generic multi-response command wrapper used by GetVagCanEcuInfoCommand | `_ZNK20MultiResponseCommandI20VagEcuInfoWithCodingE16processResponsesERKNSt6__ndk16vectorINS3_IhNS2_9allocatorIhEEEENS4_IS6_EEEE @ 00c39e60` |
| `GetSubmoduleIdsOverUdsCommand_ctor` | `00c4e900` | `72` | UDS submodule-ID command constructor | `_ZN29GetSubmoduleIdsOverUdsCommandC2EP3Ecu @ 00c4e900` |
| `GetSubmoduleIdsOverUdsCommand_processPayload` | `00c4e9b0` | `1129` | UDS submodule-ID payload parser | `_ZNK29GetSubmoduleIdsOverUdsCommand14processPayloadERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE @ 00c4e9b0` |
| `GetSubmoduleIdsOverUdsCommand_addSubmodulesIdsToResult` | `00c4ee20` | `353` | helper that appends recovered submodule IDs to a result vector | `_ZNK29GetSubmoduleIdsOverUdsCommand24addSubmodulesIdsToResultEPNSt6__ndk16vectorIhNS0_9allocatorIhEEEERKS4_b @ 00c4ee20` |
| `GetVagUdsSubmoduleIdsCommand_ctor` | `00c51e40` | `72` | alternate VAG UDS submodule-ID command constructor | `_ZN28GetVagUdsSubmoduleIdsCommandC2EP3Ecu @ 00c51e40` |
| `GetVagUdsSubmoduleIdsCommand_processPayload` | `00c51ef0` | `748` | alternate VAG UDS submodule-ID payload parser | `_ZNK28GetVagUdsSubmoduleIdsCommand14processPayloadERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE @ 00c51ef0` |
| `VagEcuInfo_merge` | `013c9310` | `386` | shared_ptr<VagEcuInfo> merge helper | `_ZN10VagEcuInfo5mergeERKNSt6__ndk110shared_ptrIS_EES4_ @ 013c9310` |
| `VagEcuInfo_ctor_short` | `013c94a0` | `263` | short VagEcuInfo constructor overload | `_ZN10VagEcuInfoC2ENS_7CmdTypeERKNSt6__ndk110shared_ptrINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEEERKNS2_INS1_6vectorINS2_IS_EENS6_ISD_EEEEEERKNS2_INS1_13unordered_mapIS8_hNS1_4hashIS8_EENS1_8equal_toIS8_EENS6_INS1_4pairIKS8_hEEEEEEEENS_10CodingTypeERKNS2_IKNSC_IhNS6_IhEEEEEES12_SB_ @ 013c94a0` |
| `VagEcuInfo_ctor_full` | `013c95b0` | `305` | full VagEcuInfo constructor overload that stores the submodule vector at +0x10/+0x14 | `_ZN10VagEcuInfoC2ENS_7CmdTypeERKNSt6__ndk110shared_ptrINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEEERKNS2_INS1_6vectorINS2_IS_EENS6_ISD_EEEEEERKNS2_INS1_13unordered_mapIS8_hNS1_4hashIS8_EENS1_8equal_toIS8_EENS6_INS1_4pairIKS8_hEEEEEEEENS_10CodingTypeERKNS2_IKNSC_IhNS6_IhEEEEEES12_SB_SB_SB_SB_RKNS2_IbEERKNS2_INS1_13unordered_setItNSK_ItEENSM_ItEENS6_ItEEEEEE @ 013c95b0` |
| `VagEcuInfo_destructor` | `013c96f0` | `458` | VagEcuInfo destructor, useful for field/refcount layout | `_ZN10VagEcuInfoD2Ev @ 013c96f0` |
| `VagEcuInfo_equals` | `013c98f0` | `1012` | VagEcuInfo equality comparison, useful for field layout | `_ZNK10VagEcuInfoeqERKS_ @ 013c98f0` |
| `VagEcuInfo_getInfo` | `013c9ef0` | `794` | native VagEcuInfo::getInfo accessor for the value used by whitelist availability matching | `_ZNK10VagEcuInfo7getInfoEv @ 013c9ef0` |
| `VagEcuInfo_getCapabilities` | `013ca210` | `21` | native VagEcuInfo capability accessor | `_ZNK10VagEcuInfo15getCapabilitiesEv @ 013ca210` |
| `VagEcuInfo_containsAll` | `013ca230` | `131` | native VagEcuInfo capability-mask helper | `_ZN10VagEcuInfo11containsAllEj @ 013ca230` |
| `VagEcuInfo_getWorkshopCodeForWriting` | `013ca2c0` | `1258` | workshop-code construction used by UDS write sequences | `_ZN10VagEcuInfo25getWorkshopCodeForWritingEv @ 013ca2c0` |
| `VagEcuInfo_cloneWith` | `013ca9f0` | `240` | VagEcuInfo cloneWith(CodingType) overload | `_ZN10VagEcuInfo9cloneWithENS_10CodingTypeE @ 013ca9f0` |
| `VagEcuInfoWithCoding_ctor_short` | `013cb670` | `499` | short VagEcuInfoWithCoding constructor overload | `_ZN20VagEcuInfoWithCodingC2EN10VagEcuInfo7CmdTypeERKNSt6__ndk110shared_ptrINS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEEERKNS3_INS2_6vectorINS3_IS0_EENS7_ISE_EEEEEERKNS3_INS2_13unordered_mapIS9_hNS2_4hashIS9_EENS2_8equal_toIS9_EENS7_INS2_4pairIKS9_hEEEEEEEENS0_10CodingTypeERKNS3_IKNSD_IhNS7_IhEEEEEES13_S13_SC_ @ 013cb670` |
| `VagEcuInfoWithCoding_ctor_full` | `013cb870` | `126` | full VagEcuInfoWithCoding constructor overload | `_ZN20VagEcuInfoWithCodingC2EN10VagEcuInfo7CmdTypeERKNSt6__ndk110shared_ptrINS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEEERKNS3_INS2_6vectorINS3_IS0_EENS7_ISE_EEEEEERKNS3_INS2_13unordered_mapIS9_hNS2_4hashIS9_EENS2_8equal_toIS9_EENS7_INS2_4pairIKS9_hEEEEEEEENS0_10CodingTypeERKNS3_IKNSD_IhNS7_IhEEEEEES13_S13_SC_SC_SC_SC_RKNS3_IbEERKNS3_INS2_13unordered_setItNSL_ItEENSN_ItEENS7_ItEEEEEE @ 013cb870` |
| `VagEcuInfoWithCoding_getInfo` | `013cb980` | `1848` | VagEcuInfoWithCoding::getInfo accessor with coding metadata | `_ZNK20VagEcuInfoWithCoding7getInfoEv @ 013cb980` |
| `VagEcuInfoWithCoding_equals` | `013cc0c0` | `805` | VagEcuInfoWithCoding equality comparison, useful for field layout | `_ZNK20VagEcuInfoWithCodingeqERKS_ @ 013cc0c0` |
| `VagOperationDelegate_getVagSettingAvailabilityForEcu` | `016b4180` | `1342` | availability router that calls VagSetting::isSubmodule before AvailBy handling | `_ZN20VagOperationDelegate31getVagSettingAvailabilityForEcuERKNSt6__ndk110shared_ptrI10VagSettingEERKNS1_I10VagEcuInfoEE @ 016b4180` |
| `VagOperationDelegate_readVagUdsSubmoduleValue` | `016b9dc0` | `421` | raw read path for UDS submodule settings | `_ZN20VagOperationDelegate24readVagUdsSubmoduleValueEyt @ 016b9dc0` |
| `VagOperationDelegate_updateEcuInfo` | `016c4b50` | `477` | updates cached VagEcuInfo from command results | `_ZN20VagOperationDelegate13updateEcuInfoEP3EcuRK6ResultI10VagEcuInfovE @ 016c4b50` |
| `VagOperationDelegate_validateVagCanEcuInfo` | `016c5b00` | `725` | validates VAG CAN ECU-info results | `_ZN20VagOperationDelegate21validateVagCanEcuInfoEP3EcuRK6ResultI10VagEcuInfovE @ 016c5b00` |
| `VagOperationDelegate_readVagEcuInfoWithUdsCommands` | `016c5de0` | `9993` | large UDS ECU-info read orchestration around submodule commands | `_ZN20VagOperationDelegate29readVagEcuInfoWithUdsCommandsEP3Ecujj @ 016c5de0` |
| `VagOperationDelegate_getVagSettingAvailabilityForSubmodule` | `016c97d0` | `311` | recovered submodule availability helper that scans VagEcuInfo +0x10 | `_ZN20VagOperationDelegate37getVagSettingAvailabilityForSubmoduleERKNSt6__ndk110shared_ptrI10VagSettingEERKNS1_I10VagEcuInfoEE @ 016c97d0` |
