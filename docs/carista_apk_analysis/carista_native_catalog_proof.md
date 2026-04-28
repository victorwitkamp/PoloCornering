# Carista Native Catalog Proof Pass

Date: 2026-04-28

This pass re-extracts the ARM native library and records byte-level proof anchors. It does not invent a write tuple.

## Fresh Extraction

Source path: `carista_apk_analysis/reacquire_20260424/carista_9.8.2.xapk!config.armeabi_v7a.apk!lib/armeabi-v7a/libCarista.so`

| Artifact | Path | Size | SHA-256 |
|---|---|---:|---|
| source XAPK | `carista_apk_analysis/reacquire_20260424/carista_9.8.2.xapk` | 67485813 | `250b36ced2aa66b59df059bbdf25fdf2942c48991c1e34740d310b3398558781` |
| sibling base APK | `carista_apk_analysis/reacquire_20260424/carista_9.8.2.apk` | 5417 | `deb5e94f5a89fbcad0fe7fe4fc74a4af7b6f5e8b2fc97bf6fdc51c04b20fde45` |
| previous extracted libCarista.so | `carista_apk_analysis/extracted/libCarista.so` | 22611320 | `eac6217741a7501a4072ea32610b54088646f0a1d3fc90b0ee8cb1201410b69b` |
| config.armeabi_v7a.apk | `carista_apk_analysis/reextracted_native_proof/carista_9.8.2/config.armeabi_v7a.apk` | 29344505 | `bedb54e0408dd0daf2b085da681e48de6821d0120657838e74dae41687b26e3c` |
| libCarista.so | `carista_apk_analysis/reextracted_native_proof/carista_9.8.2/lib/armeabi-v7a/libCarista.so` | 22611320 | `eac6217741a7501a4072ea32610b54088646f0a1d3fc90b0ee8cb1201410b69b` |

Freshly re-extracted `libCarista.so` matches the previous extracted library hash.

## Native Symbol Anchors

| Label | Symbol | Address | Size | Status |
|---|---|---:|---:|---|
| VagOperationDelegate::writeRawValue | `_ZN20VagOperationDelegate13writeRawValueEyRKNSt6__ndk16vectorIhNS0_9allocatorIhEEEERKNS0_10shared_ptrI8ProgressEE` | `0x01261140` | 704 | present |
| VagOperationDelegate::writeVagCanCodingValue | `_ZN20VagOperationDelegate22writeVagCanCodingValueEyRKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE` | `0x01263CEC` | 324 | present |
| VagOperationDelegate::writeVagUdsValue(raw-key) | `_ZN20VagOperationDelegate16writeVagUdsValueEyRKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE` | `0x0126379C` | 68 | present |
| VagOperationDelegate::writeVagUdsValue(ecu,did) | `_ZN20VagOperationDelegate16writeVagUdsValueEP3EcutRKNSt6__ndk16vectorIhNS2_9allocatorIhEEEE` | `0x012637E0` | 1060 | present |
| VagOperationDelegate::writeVagCanAdaptationValue | `_ZN20VagOperationDelegate26writeVagCanAdaptationValueEyNSt6__ndk16vectorIhNS0_9allocatorIhEEEERKNS0_10shared_ptrI8ProgressEE` | `0x01262DB0` | 268 | present |
| VagOperationDelegate::getCodingRawAddress | `_ZN20VagOperationDelegate19getCodingRawAddressEP3Ecut` | `0x0125BE08` | 492 | present |
| VagOperationDelegate::getSettingRawAddress | `_ZN20VagOperationDelegate20getSettingRawAddressERKNSt6__ndk110shared_ptrI7SettingEE` | `0x012620EC` | 204 | present |
| WriteVagCodingCommand::getRequest | `_ZNK21WriteVagCodingCommand10getRequestEv` | `0x00D032BC` | 300 | present |
| WriteVagCodingCommand::ctor | `_ZN21WriteVagCodingCommandC1EP3EcuRKNSt6__ndk16vectorIhNS2_9allocatorIhEEEERKNS2_10shared_ptrIS7_EEN10VagEcuInfo10CodingTypeESC_` | `0x00D03048` | 552 | present |
| WriteDataByIdentifierCommand::getRequest | `_ZNK28WriteDataByIdentifierCommand10getRequestEv` | `0x00CF80B4` | 120 | present |
| WriteDataByIdentifierCommand::ctor | `_ZN28WriteDataByIdentifierCommandC1EP3EcutRKNSt6__ndk16vectorIhNS2_9allocatorIhEEEEj` | `0x00CF8034` | 68 | present |
| GetVagCanEcuInfoCommand::processEcuInfo | `_ZNK23GetVagCanEcuInfoCommand14processEcuInfoERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE` | `0x00CF8654` | 888 | present |
| VagOperationDelegate vtable | `_ZTV20VagOperationDelegate` | `0x014AA62C` | 548 | present |

WriteDataByIdentifier-related native symbols:

| Symbol | Address | Size |
|---|---:|---:|
| `_ZN28WriteDataByIdentifierCommandC1EP3EcutRKNSt6__ndk16vectorIhNS2_9allocatorIhEEEEj` | `0x00CF8034` | 68 |
| `_ZN28WriteDataByIdentifierCommandC2EP3EcutRKNSt6__ndk16vectorIhNS2_9allocatorIhEEEEj` | `0x00CF8034` | 68 |
| `_ZN28WriteDataByIdentifierCommandD1Ev` | `0x00CF8078` | 40 |
| `_ZN28WriteDataByIdentifierCommandD2Ev` | `0x00CF8078` | 40 |
| `_ZN28WriteDataByIdentifierCommandD0Ev` | `0x00CF80A0` | 20 |
| `_ZNK28WriteDataByIdentifierCommand10getRequestEv` | `0x00CF80B4` | 120 |
| `_ZNK28WriteDataByIdentifierCommand14processPayloadERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE` | `0x00CF812C` | 10 |
| `_ZNSt6__ndk120__shared_ptr_emplaceI28WriteDataByIdentifierCommandNS_9allocatorIS1_EEEC2B8ne190000IJRP3EcuRKtNS_6vectorIhNS2_IhEEEEES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_` | `0x01271D10` | 100 |
| `_ZNSt6__ndk19allocatorI28WriteDataByIdentifierCommandE9constructB8ne190000IS1_JRP3EcuRKtNS_6vectorIhNS0_IhEEEEEEEvPT_DpOT0_` | `0x01271D74` | 36 |
| `_ZNSt6__ndk120__shared_ptr_emplaceI28WriteDataByIdentifierCommandNS_9allocatorIS1_EEEC2B8ne190000IJRP3EcuRKtRKNS_6vectorIhNS2_IhEEEEES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_` | `0x01271FC8` | 100 |
| `_ZNSt6__ndk19allocatorI28WriteDataByIdentifierCommandE9constructB8ne190000IS1_JRP3EcuRKtRKNS_6vectorIhNS0_IhEEEEEEEvPT_DpOT0_` | `0x0127202C` | 36 |
| `_ZNSt6__ndk120__shared_ptr_emplaceI28WriteDataByIdentifierCommandNS_9allocatorIS1_EEEC2B8ne190000IJRKP3EcuRKtRNS_6vectorIhNS2_IhEEEEES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_` | `0x0127DB24` | 100 |
| `_ZNSt6__ndk19allocatorI28WriteDataByIdentifierCommandE9constructB8ne190000IS1_JRKP3EcuRKtRNS_6vectorIhNS0_IhEEEEEEEvPT_DpOT0_` | `0x0127DB88` | 36 |
| `_ZNSt6__ndk120__shared_ptr_emplaceI28WriteDataByIdentifierCommandNS_9allocatorIS1_EEEC2B8ne190000IJRKP3EcuRKtNS_6vectorIhNS2_IhEEEEES3_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES3_DpOT_` | `0x01281918` | 100 |

## Vtable Dispatch Proof

The offsets below are relative to the C++ vptr address point (`_ZTV20VagOperationDelegate + 8`). These are the virtual slots used by `writeRawValue` and ECU-info helpers.

| Slot | Offset | Relocation address | Target | Target address |
|---|---:|---:|---|---:|
| generic raw-address formatter | `+0x17C` | `0x014AA7B0` | `_ZN20VagOperationDelegate13getRawAddressEN10VagSetting4TypeEP3Ecut` | `0x0125BCB4` |
| read ECU info cached | `+0x194` | `0x014AA7C8` | `_ZN20VagOperationDelegate17readEcuInfoCachedEP3Ecujj` | `0x01266BD0` |
| write ordinary raw value | `+0x1B8` | `0x014AA7EC` | `_ZN20VagOperationDelegate26writeVagCanAdaptationValueEyNSt6__ndk16vectorIhNS0_9allocatorIhEEEERKNS0_10shared_ptrI8ProgressEE` | `0x01262DB0` |
| write UDS raw value | `+0x1C0` | `0x014AA7F4` | `_ZN20VagOperationDelegate16writeVagUdsValueEyRKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE` | `0x0126379C` |
| write UDS ECU/DID value | `+0x1C4` | `0x014AA7F8` | `_ZN20VagOperationDelegate16writeVagUdsValueEP3EcutRKNSt6__ndk16vectorIhNS2_9allocatorIhEEEE` | `0x012637E0` |
| write VAG-CAN coding | `+0x1C8` | `0x014AA7FC` | `_ZN20VagOperationDelegate22writeVagCanCodingValueEyRKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE` | `0x01263CEC` |
| write VAG-CAN submodule coding | `+0x1CC` | `0x014AA800` | `_ZN20VagOperationDelegate31writeVagCanSubmoduleCodingValueEyRKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE` | `0x01263E8C` |
| connected ECU-info cache | `+0x1F8` | `0x014AA82C` | `_ZN20VagOperationDelegate10getEcuInfoEP3Ecu` | `0x0126918C` |

## Command Builder Proof

Selected instruction anchors from the freshly extracted library:

| Source | Instruction | Finding |
|---|---|---|
| VagOperationDelegate::writeVagUdsValue(raw-key) `0x012637AE` | `ldr.w r1, [r0, #0x154]` | loads virtual slot +0x154 to resolve the ECU from the raw key |
| VagOperationDelegate::writeVagUdsValue(raw-key) `0x012637BE` | `ldr.w r1, [r0, #0x158]` | loads virtual slot +0x158 to resolve the raw short/DID from the raw key |
| VagOperationDelegate::writeVagUdsValue(raw-key) `0x012637CE` | `ldr.w r5, [r0, #0x1c4]` | loads virtual slot +0x1C4, which the fresh vtable maps to writeVagUdsValue(ecu,did) |
| VagOperationDelegate::writeVagUdsValue(raw-key) `0x012637D8` | `blx r5` | dispatches into the ECU/DID UDS writer |
| VagOperationDelegate::writeVagUdsValue(ecu,did) `0x012637FE` | `strh r3, [r7, #-0x1e]` | stores the DID argument as a 16-bit value for later command construction |
| VagOperationDelegate::writeVagUdsValue(ecu,did) `0x01263A10` | `add r0, sp, #0x54` | sets up a local UDS command-builder path |
| VagOperationDelegate::writeVagUdsValue(ecu,did) `0x01263A14` | `sub.w r2, r7, #0x1e` | passes the saved DID pointer into that local command-builder path |
| VagOperationDelegate::writeVagUdsValue(ecu,did) `0x01263A18` | `bl #0x1263cb1` | branches to the local command-builder helper inside writeVagUdsValue(ecu,did) |
| WriteDataByIdentifierCommand::getRequest `0x00CF80CC` | `ldrh r1, [r1, #0x10]` | loads the stored DID halfword from the command object |
| WriteDataByIdentifierCommand::getRequest `0x00CF80D8` | `movs r1, #0x2e` | prepends UDS service byte 0x2E |
| WriteDataByIdentifierCommand::getRequest `0x00CF80E0` | `add.w r2, r5, #0x14` | appends the payload vector after service and DID |

Immediate constants in request builders:

| Source | Instruction | Value |
|---|---|---:|
| WriteDataByIdentifierCommand::getRequest `0x00CF80D8` | `movs r1, #0x2e` | `0x2E` |
| WriteVagCodingCommand::getRequest `0x00D0334A` | `movs r2, #0xff` | `0xFF` |

ASCII request-token counts in the native library:

| Token | Count |
|---|---:|
| `1A9A` | 33 |
| `1A9B` | 459 |
| `3B9A` | 1 |

Representative request-token locations:

| Token | File offset | Virtual address | Context |
|---|---:|---:|---|
| `1A9A` | `0x007381E6` | `0x007381E6` | `.311100.2106.2F.1A9A.31BB. dataIds a` |
| `1A9A` | `0x0081296A` | `0x0081296A` | `00004275001700051A9A170113CB62BB1702` |
| `1A9A` | `0x008E2872` | `0x008E2872` | `FF.ECU VAGCAN1F 1A9A: 5A9A0006462204` |
| `1A9A` | `0x008E2E1A` | `0x008E2E1A` | `12.ECU VAGCAN01 1A9A: 7F1A12.ECU VAG` |
| `1A9A` | `0x008E3262` | `0x008E3262` | `31.ECU VAGCAN03 1A9A: 7F1A31.ECU VAG` |
| `1A9A` | `0x008E3624` | `0x008E3624` | `12.ECU VAGCAN09 1A9A: 7F1A12.ECU VAG` |
| `1A9B` | `0x008E27C8` | `0x008E27C8` | `1..ECU VAGCAN1F 1A9B: 5A9B314B303930` |
| `1A9B` | `0x008E2D52` | `0x008E2D52` | `11.ECU VAGCAN01 1A9B: 5A9B3036413930` |
| `1A9B` | `0x008E3188` | `0x008E3188` | `11.ECU VAGCAN15 1A9B: -5.ECU VAGCAN1` |
| `1A9B` | `0x008E319E` | `0x008E319E` | `-5.ECU VAGCAN16 1A9B: -5.ECU VAGCAN0` |
| `1A9B` | `0x008E31B4` | `0x008E31B4` | `-5.ECU VAGCAN02 1A9B: -5.ECU VAGCAN0` |
| `1A9B` | `0x008E31CA` | `0x008E31CA` | `-5.ECU VAGCAN03 1A9B: 7F1A78.5A9B314` |
| `3B9A` | `0x008C8D6E` | `0x008C8D6E` | `alid length!.FF.3B9A.GetVagUdsEcuLis` |

## writeRawValue Type Dispatch Cross-Check

Ghidra export: `carista_apk_analysis/ghidra_exports/VagOperationDelegate_writeRawValue_01271140.c` SHA-256 `4743bf2ea5d97270ced5b1b216e3b5157a766a367e34286b11819e3c4c59d186`

This decompile rendering is a cross-check only; the slot identities above were revalidated from the fresh ELF relocation table.

```c
    switch(uVar2) {
    case 0:
    case 1:
      uVar2 = FUN_00cd5ef0(auStack_e0,param_5);
      (**(code **)(*param_2 + 0x1b8))(aRStack_d4,param_2,param_3,param_4,uVar2,param_6);
      FUN_00cb7f50(auStack_e0);
      Result<BytesModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
      ::Result(param_1,*local_bc,psStack_b8);
      Result<BytesModel,void>::~Result(aRStack_d4);
      goto LAB_01271338;
    case 2:
    case 3:
      (**(code **)(*param_2 + 0x1c8))(aRStack_d4,param_2,param_3,param_4,param_5);
      break;
    case 4:
      (**(code **)(*param_2 + 0x1cc))(aRStack_d4,param_2,param_3,param_4,param_5);
      break;
    case 5:
      uVar2 = (**(code **)(*param_2 + 0x154))(param_2,*(code **)(*param_2 + 0x154),param_3,param_4);
      uVar4 = (**(code **)(*param_2 + 0x180))(param_2,*(code **)(*param_2 + 0x180),param_3,param_4);
      uVar4 = (**(code **)(*param_2 + 0x1e0))(param_2,uVar4);
      (**(code **)(*param_2 + 0x1c4))(aRStack_d4,param_2,uVar2,uVar4,param_5);
      break;
    default:
      this = (IllegalArgumentException *)__cxa_allocate_exception(8);
      FUN_00cb4d44(aRStack_d4,"Invalid VAG setting type");
      IllegalArgumentException::IllegalArgumentException(this,(basic_string *)aRStack_d4);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(this,&IllegalArgumentException::typeinfo,
                  IllegalStateException::~IllegalStateException);
    case 7:
    case 8:
      (**(code **)(*param_2 + 0x1c0))(aRStack_d4,param_2,param_3,param_4,param_5);
      break;
    case 9:
      uVar2 = (**(code **)(*param_2 + 0x154))(param_2,*(code **)(*param_2 + 0x154),param_3,param_4);
      uVar4 = (**(code **)(*param_2 + 0x180))(param_2,*(code **)(*param_2 + 0x180),param_3,param_4);
      uVar4 = (**(code **)(*param_2 + 0x1d4))(param_2,uVar4);
      (**(code **)(*param_2 + 0x1c4))(aRStack_d4,param_2,uVar2,uVar4,param_5);
    }
    Result<EmptyModel,void>::operator=(aRStack_b0,(Result *)aRStack_d4);
    Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)aRStack_d4);
    Result<EmptyModel,void>::
    stateAs<BytesModel,std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>
              ();
LAB_01271338:
    Result<EmptyModel,void>::~Result(aRStack_b0);
  }
  RunOnScopeExit::~RunOnScopeExit(aRStack_48);
LAB_01271344:
```

## Live UDS Fingerprint

These are positive reads from the existing in-car logs with answered TP2.0 channel parameters where available.

| Command | Response | Channel params | Summary |
|---|---|---|---|
| `220600` | `6206003AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000` | answered (block=15, T1=138, T2=255, T3=79, T4=255) | `obd-on-pc/logs/pq25_carista_validation_same_channel_uds_identity_retry_1_direct_sequence_summary.json` |
| `220601` | `6206011E` | answered (block=15, T1=138, T2=255, T3=79, T4=255) | `obd-on-pc/logs/pq25_carista_validation_retry_220601_3_direct_read_summary.json` |
| `220606` | `620606001800018000` | answered (block=15, T1=138, T2=255, T3=79, T4=255) | `obd-on-pc/logs/pq25_carista_validation_retry_220606_8_direct_read_summary.json` |
| `22F187` | `62F1873652303933373038374B20` | answered (block=15, T1=138, T2=255, T3=79, T4=255) | `obd-on-pc/logs/pq25_carista_validation_retry_22F187_3_direct_read_summary.json` |
| `22F191` | `62F1913652303933373038372020` | answered (block=15, T1=138, T2=255, T3=79, T4=255) | `obd-on-pc/logs/pq25_carista_validation_isolated_uds_identity_direct_read_summary.json` |
| `22F197` | `62F19742434D205051323520482B3420` | answered (block=15, T1=138, T2=255, T3=79, T4=255) | `obd-on-pc/logs/pq25_carista_validation_retry_22F197_7_direct_read_summary.json` |
| `22F1A3` | `62F1A3483436` | answered (block=15, T1=138, T2=255, T3=79, T4=255) | `obd-on-pc/logs/pq25_carista_validation_isolated_uds_identity_direct_read_summary.json` |
| `22F1A5` | `62F1A50005F3C7E719` | answered (block=15, T1=138, T2=255, T3=79, T4=255) | `obd-on-pc/logs/pq25_carista_validation_isolated_uds_identity_direct_read_summary.json` |
| `22F1AA` | `62F1AA4A35313920` | answered (block=15, T1=138, T2=255, T3=79, T4=255) | `obd-on-pc/logs/pq25_carista_validation_isolated_uds_identity_direct_read_summary.json` |
| `22F1DF` | `62F1DF40` | answered (block=15, T1=138, T2=255, T3=79, T4=255) | `obd-on-pc/logs/pq25_carista_validation_isolated_uds_identity_direct_read_summary.json` |

## Embedded Profile Binding

Top embedded VAGCAN20 profile comparisons against the live fingerprint:

| Profile | Exact matches | Compared | Notes | Evidence |
|---:|---:|---:|---|---|
| 6 | 3 | 10 | UDS-style 220600 coding profile; has 31B80000 coding-address list | 220600: sim=6206007B994BB808AB0B0000382000240884CD00C2502E60000000300000000000 live=6206003AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000 (byte 3: 7B->3A; byte 4: 99->B8; byte 5: 4B->2B; byte 6: B8->9F; byte 8: AB->A1; byte 9: 0B->00; byte 12: 38->30; byte 13: 20->08)<br>220601: sim=6206011E live=6206011E (exact)<br>220606: sim=620606001800038000 live=620606001800018000 (byte 6: 03->01)<br>22F187: sim=62F1873543303933373038374520 live=62F1873652303933373038374B20 (byte 3: 35->36; byte 4: 43->52; byte 12: 45->4B)<br>22F191: sim=62F1913543303933373038374120 live=62F1913652303933373038372020 (byte 3: 35->36; byte 4: 43->52; byte 12: 41->20)<br>22F197: sim=62F19742434D3235204A4C4220483320 live=62F19742434D205051323520482B3420 (byte 6: 32->20; byte 7: 35->50; byte 8: 20->51; byte 9: 4A->32; byte 10: 4C->35; byte 11: 42->20; byte 12: 20->48; byte 13: 48->2B)<br>22F1A3: sim=62F1A3483636 live=62F1A3483436 (byte 4: 36->34)<br>22F1A5: sim=62F1A5000000000042 live=62F1A50005F3C7E719 (byte 4: 00->05; byte 5: 00->F3; byte 6: 00->C7; byte 7: 00->E7; byte 8: 42->19) |
| 2 | 0 | 10 | has 31B80000 coding-address list; has positive 1A9B metadata | 220600: sim=7F2211 live=6206003AB82B9F08A10000003008002C680ED000C8412F60A20000200000000000 (different)<br>220601: sim=7F2211 live=6206011E (different)<br>220606: sim=7F2211 live=620606001800018000 (different)<br>22F187: sim=7F2211 live=62F1873652303933373038374B20 (different)<br>22F191: sim=7F2211 live=62F1913652303933373038372020 (different)<br>22F197: sim=7F2211 live=62F19742434D205051323520482B3420 (different)<br>22F1A3: sim=7F2211 live=62F1A3483436 (different)<br>22F1A5: sim=7F2211 live=62F1A50005F3C7E719 (different) |

UDS-style embedded coding profiles:

### Profile 6

Identity: `1A9B=...; 22F187=b..5C0937087E ; 22F191=b..5C0937087A ; 22F197=b..BCM25 JLB H3 ; 22F1A3=b..H66; 22F1AA=b..J519 ; 22F1DF=b..@`

Coding source: `220600 -> 6206007B994BB808AB0B0000382000240884CD00C2502E60000000300000000000`

31B80000 shorts: `0106 0102 0103 0107 0108 0114`

Positive 1A9B metadata: `False`

## Coding Delta Proof

The only value bytes still proven from the current/known-good coding pair are:

| Chunk | Bytes | Current | Target | Changed bits |
|---:|---:|---|---|---|
| 2 | 12-17 | `2C680ED000C8` | `6C680ED000C8` | byte 12 bit 6: False->True |
| 3 | 18-23 | `412F60A20000` | `412F60A60000` | byte 21 bit 2: False->True |

## Proof Result

Proved from the fresh native library:

- `WriteVagCodingCommand::getRequest` and the `3B9A` token exist in the extracted ELF; that is the compact VAG-CAN coding command path.
- `WriteDataByIdentifierCommand::getRequest` exists and its request builder contains immediate `0x2E`; that is the UDS WriteDataByIdentifier request shape.
- `VagOperationDelegate::writeVagUdsValue(raw-key)` extracts ECU and DID from the raw key, then dispatches to the ECU/DID UDS writer slot.
- `VagOperationDelegate::writeRawValue` dispatches setting types 7/8 into the UDS raw-value slot and types 2/3 into the VAG-CAN coding slot; the slot targets are revalidated above from fresh ELF relocations.
- The actual BCM live data binds strongly to Carista's UDS-style VAGCAN20/BCM25 family, not to the positive-`5A9B` KWP profile.

Additional UDS write-path recovery from the exported Ghidra functions:

- `VagUdsCodingSetting(ecu, vector)` hardcodes setting type `8` and DID `0x0600`.
- `writeRawValue` sends type `8` through `writeVagUdsValue`.
- `writeVagUdsValue(ecu,did,value)` first writes `DATE_WRITE_ID` (`0xF199`), then `WORKSHOP_CODE_WRITE_ID` (`0xF198`), then the requested DID.
- `GetVagUdsEcuWorkshopCodeCommand` reads DID `0xF1A5` and accepts exactly 6 payload bytes.
- `VagEcuInfo::getWorkshopCodeForWriting()` uses the 6-byte workshop-code payload if present and fills only zero WSC/importer/equipment fields with defaults.

For the live BCM payload `22F1A5 -> 62F1A50005F3C7E719`, Carista's `F198`
payload should therefore be `0005F3C7E719`.

The next guarded write candidate is:

```text
2EF199YYMMDD
2EF1980005F3C7E719
2E06003AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000
```

## Negative-Response Fatality Proof

Additional exact-flow exports prove how Carista treats the live F199/F198
response `7F2E31`:

| Export | Finding |
|---|---|
| `BaseCommand_extractState_00CDEA40.c` | UDS `7F xx 31` returns `0xffffffe0`, which is signed state `-32`. |
| `State_Set_obd2NegativeResponse_00D379A8.c` | The OBD2-negative-response set contains `-32`. |
| `State_Set_fatalError_00D3787C.c` | The fatal set is `[-12, -1, -7, -4, -16, -51, -1000]`; it does not contain `-32`. |
| `State_isError_00D37858.c` | Generic error status is the sign bit, so `-32` is an error. |
| `Result_EmptyModel_isFatalFail_011E620E.c` | `isFatalFail` delegates to `State::isFatalError`, not generic `isError`. |
| `VagOperationDelegate_writeVagUdsValue_byEcuDid_012737E0.c` | F199 and F198 metadata writes are gated with `isFatalFail`; the final target DID write is returned normally. |

Conclusion: `7F2E31` on `F199` or `F198` is a Carista OBD2-negative-response
state, but it is not fatal for the metadata pre-write gates. This proves why the
local guarded writer may continue past exactly F199/F198 `7F2E31` when the user
explicitly enables that behavior, while still requiring the final `2E0600` write
to be positive.

## TP2.0 ACK Timing Proof

The same exact-flow export pass proves that Carista ACKs accepted ECU data
frames inside the receive loop, before treating the application response as
complete:

| Export | Finding |
|---|---|
| `VagCanCommunicator_readResponses_00D282A8.c` | Accepted data packets are accumulated and ACKed in the receive loop. |
| `VagCanCommunicator_sendAck_seq_00D28A94.c` | `sendAck(seq,bool)` calls the opcode overload with `0xB0` and `(seq + 1) & 0x0F`. |
| `VagCanCommunicator_sendAck_opcode_00D28AD8.c` | The ACK packet is sent through the ELM communicator and then receive is called again. |
| `VagCanPacket_toRawBytesForSending_00D2740C.c` | Raw send bytes start with `opcode | sequence`, followed by payload. |

For the live traces, this yields ACK `B5` for the completed multi-frame
`220600` response ending at sequence 4, and ACK `B6` for the single-frame F199
`7F2E31` response at sequence 5.

Still not proved:

- Whether the BCM will accept the final `2E0600` coding write after Carista-style
  handling of the nonfatal `F199`/`F198` metadata negatives.
- Whether the target write should start at a specific TP2.0 application counter, though previous reads/writes show the BCM understands ordinary counters.

Operational boundary: do not promote any `31B8`-derived `3B9A` tuple or blind `2E0600`
full-coding request to a write. The next live attempt should use the guarded
writer that re-reads `220600`, confirms the exact two-byte delta, sends the
Carista UDS pre-write sequence, writes DID `0600`, then immediately verifies
`220600`.

