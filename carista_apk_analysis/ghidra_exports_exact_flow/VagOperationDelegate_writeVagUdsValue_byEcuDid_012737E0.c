/*
 * VagOperationDelegate_writeVagUdsValue_byEcuDid
 * ELF symbol address: 0x012637E0
 * Ghidra address: 0x012737E0 (ELF + 0x10000 image delta)
 * ELF symbol size: 1060 bytes
 * Symbol: _ZN20VagOperationDelegate16writeVagUdsValueEP3EcutRKNSt6__ndk16vectorIhNS2_9allocatorIhEEEE
 * Program: libCarista.so
 * Resolved function: VagOperationDelegate::writeVagUdsValue @ 012737e0
 * Signature: undefined __stdcall writeVagUdsValue(Ecu * param_1, ushort param_2, vector * param_3)
 * Return type: undefined
 * Function body: [[012737e0, 01273af3]]
 * Parameters:
 *   [0] Ecu * param_1
 *   [1] ushort param_2
 *   [2] vector * param_3
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014ba7f8
 * Direct callees/references:
 *   WRITE Stack[-0x24] from 012737ea
 *   READ 01273bd4 from 012737ee
 *   READ 014da87c from 012737f8
 *   READ 015a7014 from 012737fa
 *   WRITE Stack[-0x1c] from 012737fc
 *   READ 01273ba4 from 01273802
 *   READ 014daaf0 from 01273806
 *   READ 014f1448 from 01273808
 *   READ Stack[-0x60] from 01273812
 *   UNCONDITIONAL_CALL Clock::toTmUtc @ 014281a0 from 01273818
 *   READ Stack[-0x40] from 0127381c
 *   UNCONDITIONAL_CALL FUN_013f4cb0 @ 013f4cb0 from 01273820
 *   READ 01273ba8 from 01273828
 *   PARAM 00b60524 from 0127382c
 *   UNCONDITIONAL_CALL StringUtils::format @ 013fd2a0 from 0127382e
 *   UNCONDITIONAL_CALL ByteUtils::getByte @ 01403710 from 01273834
 *   READ Stack[-0x44] from 0127383c
 *   READ 01273bd8 from 01273842
 *   PARAM 00b60524 from 01273844
 *   UNCONDITIONAL_CALL StringUtils::format @ 013fd2a0 from 01273846
 *   UNCONDITIONAL_CALL ByteUtils::getByte @ 01403710 from 0127384c
 *   READ Stack[-0x48] from 01273854
 *   READ 01273bdc from 01273858
 *   PARAM 00b60524 from 0127385a
 *   UNCONDITIONAL_CALL StringUtils::format @ 013fd2a0 from 0127385c
 *   UNCONDITIONAL_CALL ByteUtils::getByte @ 01403710 from 01273862
 *   UNCONDITIONAL_CALL FUN_00cdb87c @ 00cdb87c from 01273872
 *   READ 01273be0 from 01273876
 *   READ 014dfcc0 from 0127387a
 *   PARAM 00c9d59a from 0127387a
 *   UNCONDITIONAL_CALL FUN_01273c04 @ 01273c04 from 01273882
 *   READ Stack[-0x94] from 01273886
 *   WRITE Stack[-0x8c] from 0127388a
 *   WRITE Stack[-0x88] from 0127388e
 *   WRITE Stack[-0x94] from 01273890
 *   UNCONDITIONAL_CALL Progress::NUL @ 0141f070 from 01273896
 *   UNCONDITIONAL_CALL OperationDelegate::runCommand<EmptyModel> @ 0141f520 from 012738a2
 *   UNCONDITIONAL_CALL FUN_011e01a0 @ 011e01a0 from 012738a8
 *   UNCONDITIONAL_CALL FUN_011e4048 @ 011e4048 from 012738ae
 *   UNCONDITIONAL_CALL FUN_011e558c @ 011e558c from 012738b4
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 012738ba
 *   READ 01273be4 from 012738be
 *   READ 014da898 from 012738c2
 *   COMPUTED_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 0130ff6e from 012738c6
 *   COMPUTED_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 0130ff6e from 012738ca
 *   COMPUTED_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 0130ff6e from 012738ce
 *   UNCONDITIONAL_CALL Result<EmptyModel,void>::isFatalFail @ 0141f790 from 012738d2
 *   CONDITIONAL_JUMP VagOperationDelegate::writeVagUdsValue @ 012737e0 from 012738d6
 *   UNCONDITIONAL_CALL Result<EmptyModel,void>::Result @ 0141f540 from 012738dc
 *   UNCONDITIONAL_JUMP VagOperationDelegate::writeVagUdsValue @ 012737e0 from 012738e0
 *   READ 01273be8 from 012738e2
 *   READ Stack[-0x24] from 012738e4
 *   READ 014de510 from 012738e8
 *   READ 014f7b58 from 012738ea
 *   CONDITIONAL_JUMP VagOperationDelegate::writeVagUdsValue @ 012737e0 from 012738f6
 *   READ 01273bec from 012738f8
 *   READ 014de4c4 from 012738fc
 *   READ 014f7ad0 from 012738fe
 *   CONDITIONAL_JUMP VagOperationDelegate::writeVagUdsValue @ 012737e0 from 0127390a
 *   READ 01273bf0 from 0127390e
 *   PARAM 00c86965 from 01273912
 *   UNCONDITIONAL_CALL operator""__b @ 013fd3f0 from 01273914
 *   READ 01273bf4 from 01273918
 *   READ 014dabb4 from 0127391c
 *   PARAM 00c89e4c from 0127391c
 *   UNCONDITIONAL_CALL FUN_01273c40 @ 01273c40 from 01273924
 *   READ Stack[-0xac] from 01273928
 *   WRITE Stack[-0xa0] from 0127392c
 *   WRITE Stack[-0x9c] from 01273930
 *   WRITE Stack[-0xac] from 01273932
 *   UNCONDITIONAL_CALL Progress::NUL @ 0141f070 from 01273938
 *   UNCONDITIONAL_CALL OperationDelegate::runCommand<BytesListModel> @ 0141f920 from 01273944
 *   UNCONDITIONAL_CALL FUN_011e01a0 @ 011e01a0 from 0127394a
 *   UNCONDITIONAL_CALL FUN_00d2b5d4 @ 00d2b5d4 from 01273950
 *   UNCONDITIONAL_CALL FUN_00d2b5e6 @ 00d2b5e6 from 01273956
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 0127395c
 *   UNCONDITIONAL_CALL Result<BytesListModel,void>::isFatalFail @ 01404080 from 01273962
 *   CONDITIONAL_JUMP VagOperationDelegate::writeVagUdsValue @ 012737e0 from 01273966
 *   UNCONDITIONAL_CALL Result<BytesListModel,void>::stateAs<EmptyModel,void> @ 01425420 from 0127396c
 *   UNCONDITIONAL_CALL Result<BytesListModel,void>::~Result @ 013fdac0 from 01273972
 *   UNCONDITIONAL_JUMP VagOperationDelegate::writeVagUdsValue @ 012737e0 from 01273976
 *   UNCONDITIONAL_CALL Result<BytesListModel,void>::~Result @ 013fdac0 from 0127397a
 *   READ Stack[-0x24] from 0127397e
 *   READ Stack[-0xe0] from 0127398c
 *   READ 01273bf8 from 01273998
 *   READ 014dfcc4 from 0127399c
 *   PARAM 00c9d598 from 0127399c
 *   UNCONDITIONAL_CALL FUN_01273c04 @ 01273c04 from 012739a4
 *   READ Stack[-0x8c] from 012739a8
 *   WRITE Stack[-0xac] from 012739ac
 *   WRITE Stack[-0xa8] from 012739b0
 *   WRITE Stack[-0x8c] from 012739b2
 *   UNCONDITIONAL_CALL Progress::NUL @ 0141f070 from 012739b8
 *   UNCONDITIONAL_CALL OperationDelegate::runCommand<EmptyModel> @ 0141f520 from 012739c4
 *   UNCONDITIONAL_CALL FUN_011e01a0 @ 011e01a0 from 012739ca
 *   UNCONDITIONAL_CALL FUN_011e4048 @ 011e4048 from 012739d0
 *   UNCONDITIONAL_CALL FUN_011e558c @ 011e558c from 012739d6
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 012739dc
 *   UNCONDITIONAL_CALL Result<VagEcuInfo,void>::~Result @ 01427dd0 from 012739e2
 *   UNCONDITIONAL_CALL Result<EmptyModel,void>::isFatalFail @ 0141f790 from 012739e8
 *   CONDITIONAL_JUMP VagOperationDelegate::writeVagUdsValue @ 012737e0 from 012739ec
 *   UNCONDITIONAL_CALL Result<EmptyModel,void>::Result @ 0141f540 from 012739f2
 *   UNCONDITIONAL_JUMP VagOperationDelegate::writeVagUdsValue @ 012737e0 from 012739f6
 *   READ 01273bfc from 012739f8
 *   READ Stack[-0x24] from 012739fa
 *   READ 014db310 from 012739fe
 *   PARAM 014f7a7c from 012739fe
 *   READ 014f7a7c from 01273a00
 *   CONDITIONAL_JUMP VagOperationDelegate::writeVagUdsValue @ 012737e0 from 01273a0c
 *   READ Stack[0x0] from 01273a0e
 *   UNCONDITIONAL_CALL FUN_01273cb0 @ 01273cb0 from 01273a18
 *   READ Stack[-0xac] from 01273a1c
 *   WRITE Stack[-0xa0] from 01273a20
 *   WRITE Stack[-0x9c] from 01273a24
 *   WRITE Stack[-0xac] from 01273a26
 *   UNCONDITIONAL_CALL Progress::NUL @ 0141f070 from 01273a2c
 *   UNCONDITIONAL_CALL OperationDelegate::runCommand<EmptyModel> @ 0141f520 from 01273a38
 *   UNCONDITIONAL_CALL FUN_011e01a0 @ 011e01a0 from 01273a3e
 *   UNCONDITIONAL_CALL FUN_011e4048 @ 011e4048 from 01273a44
 *   UNCONDITIONAL_CALL FUN_011e558c @ 011e558c from 01273a4a
 */

/* Ghidra function: VagOperationDelegate::writeVagUdsValue @ 012737e0 */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df8048dbab037928046dff8e4030d461e46784400680068399027f8
 * 012737e0: push {r4,r5,r6,r7,lr}
 * 012737e2: add r7,sp,#0xc
 * 012737e4: push.w r8
 * 012737e8: sub sp,#0xe8
 * 012737ea: str r2,[sp,#0xdc]
 * 012737ec: mov r8,r0
 * 012737ee: ldr.w r0,[0x01273bd4]
 * 012737f2: mov r5,r1
 * 012737f4: mov r6,r3
 * 012737f6: add r0,pc
 * 012737f8: ldr r0,[r0,#0x0]
 * 012737fa: ldr r0,[r0,#0x0]
 * 012737fc: str r0,[sp,#0xe4]
 * 012737fe: strh r3,[r7,#-0x1e]
 * 01273802: ldr r0,[0x01273ba4]
 * 01273804: add r0,pc
 * 01273806: ldr r0,[r0,#0x0]
 * 01273808: ldr r1,[r0,#0x0]
 * 0127380a: ldr r0,[r1,#0x0]
 * 0127380c: ldr r2,[r0,#0x8]
 * 0127380e: add r0,sp,#0xa0
 * 01273810: blx r2
 * 01273812: ldrd r2,r3,[sp,#0xa0]
 * 01273816: add r0,sp,#0xac
 */


/* VagOperationDelegate::writeVagUdsValue(Ecu*, unsigned short, std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&) */

void VagOperationDelegate::writeVagUdsValue(Ecu *param_1,ushort param_2,vector *param_3)

{
  int iVar1;
  vector *pvVar2;
  shared_ptr *psVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  vector *in_r3;
  undefined4 in_stack_00000000;
  basic_string abStack_fc [24];
  int *local_e4;
  undefined4 *local_e0;
  shared_ptr asStack_d8 [36];
  Progress aPStack_b4 [8];
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_94;
  undefined4 uStack_90;
  undefined4 local_8c;
  undefined4 local_88;
  shared_ptr asStack_84 [36];
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined1 auStack_54 [12];
  undefined4 local_48;
  int local_44;
  undefined4 local_40;
  undefined2 uStack_26;
  vector *local_24;
  undefined1 uStack_1f;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  int local_1c;
  
  psVar3 = (shared_ptr *)(uint)param_2;
  local_1c = __stack_chk_guard;
  uStack_26 = SUB42(in_r3,0);
  local_24 = param_3;
  (**(code **)(*(int *)App::CLOCK + 8))(&local_60);
  Clock::toTmUtc(auStack_54,extraout_r1,local_60,uStack_5c);
  FUN_013f4cb0(local_40,100);
  StringUtils::format((char *)abStack_fc,&DAT_00b60524,extraout_r1_00);
  uStack_1f = ByteUtils::getByte(abStack_fc);
  StringUtils::format((char *)&local_a0,&DAT_00b60524,local_44 + 1);
  uStack_1e = ByteUtils::getByte((basic_string *)&local_a0);
  StringUtils::format((char *)&local_ac,&DAT_00b60524,local_48);
  uStack_1d = ByteUtils::getByte((basic_string *)&local_ac);
  FUN_00cdb87c(asStack_d8,&uStack_1f,3);
  FUN_01273c04(&local_94,&local_24,&DATE_WRITE_ID,asStack_d8);
  local_8c = local_94;
  local_88 = uStack_90;
  local_94 = 0;
  uStack_90 = 0;
  Progress::NUL(aPStack_b4);
  OperationDelegate::runCommand<EmptyModel>(asStack_84,psVar3);
  FUN_011e01a0(aPStack_b4);
  FUN_011e4048(&local_8c);
  FUN_011e558c(&local_94);
  FUN_00cb7f50(asStack_d8);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                &local_ac);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                &local_a0);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                abStack_fc);
  iVar1 = Result<EmptyModel,void>::isFatalFail((Result<EmptyModel,void> *)asStack_84);
  if (iVar1 != 0) {
    Result<EmptyModel,void>::Result((Result<EmptyModel,void> *)param_1,(Result *)asStack_84);
    goto LAB_01273acc;
  }
  pvVar2 = VagUdsEcu::INFOTAINMENT;
  if (local_24 == VagUdsEcu::INFOTAINMENT) {
    pvVar2 = (vector *)0x243f;
  }
  if (local_24 == VagUdsEcu::INFOTAINMENT && in_r3 == pvVar2) {
LAB_0127390c:
    operator____b((char *)abStack_fc,0xc86965);
    FUN_01273c40(&local_ac,&local_24,abStack_fc,&BaseCommand::OPT_RETRIABLE);
    local_a0 = local_ac;
    local_9c = local_a8;
    local_ac = 0;
    local_a8 = 0;
    Progress::NUL((Progress *)&local_8c);
    OperationDelegate::runCommand<BytesListModel>(asStack_d8,psVar3);
    FUN_011e01a0(&local_8c);
    FUN_00d2b5d4(&local_a0);
    FUN_00d2b5e6(&local_ac);
    FUN_00cb7f50(abStack_fc);
    iVar1 = Result<BytesListModel,void>::isFatalFail((Result<BytesListModel,void> *)asStack_d8);
    if (iVar1 != 0) {
      Result<BytesListModel,void>::stateAs<EmptyModel,void>();
      Result<BytesListModel,void>::~Result((Result<BytesListModel,void> *)asStack_d8);
      goto LAB_01273acc;
    }
    Result<BytesListModel,void>::~Result((Result<BytesListModel,void> *)asStack_d8);
  }
  else {
    pvVar2 = VagUdsEcu::INSTRUMENT_CLUSTER;
    if (local_24 == VagUdsEcu::INSTRUMENT_CLUSTER) {
      pvVar2 = (vector *)0x511;
    }
    if (local_24 == VagUdsEcu::INSTRUMENT_CLUSTER && in_r3 == pvVar2) goto LAB_0127390c;
  }
  (**(code **)(*(int *)psVar3 + 0x1f8))(abStack_fc,psVar3,local_24);
  (**(code **)(*(int *)*local_e0 + 0x14))(&local_a0);
  FUN_01273c04(&local_8c,&local_24,&WORKSHOP_CODE_WRITE_ID,&local_a0);
  local_ac = local_8c;
  local_a8 = local_88;
  local_8c = 0;
  local_88 = 0;
  Progress::NUL((Progress *)&local_94);
  OperationDelegate::runCommand<EmptyModel>(asStack_d8,psVar3);
  FUN_011e01a0(&local_94);
  FUN_011e4048(&local_ac);
  FUN_011e558c(&local_8c);
  FUN_00cb7f50(&local_a0);
  Result<VagEcuInfo,void>::~Result((Result<VagEcuInfo,void> *)abStack_fc);
  iVar1 = Result<EmptyModel,void>::isFatalFail((Result<EmptyModel,void> *)asStack_d8);
  if (iVar1 == 0) {
    pvVar2 = VagUdsEcu::CAN_GATEWAY;
    if (local_24 == VagUdsEcu::CAN_GATEWAY) {
      pvVar2 = (vector *)0x31d;
    }
    if (local_24 == VagUdsEcu::CAN_GATEWAY && in_r3 == pvVar2) {
      local_94 = CONCAT31(local_94._1_3_,3);
      FUN_01273c7c(&local_ac,&VagUdsEcu::CAN_GATEWAY,&local_94);
      local_a0 = local_ac;
      local_9c = local_a8;
      local_ac = 0;
      local_a8 = 0;
      Progress::NUL((Progress *)&local_8c);
      OperationDelegate::runCommand<EmptyModel>((shared_ptr *)abStack_fc,psVar3);
      FUN_011e01a0(&local_8c);
      FUN_011e4048(&local_a0);
      FUN_011ff7b8(&local_ac);
      iVar1 = Result<EmptyModel,void>::isFail((Result<EmptyModel,void> *)abStack_fc);
      if (iVar1 == 0) {
        Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)abStack_fc);
        goto LAB_01273a0e;
      }
      Result<EmptyModel,void>::stateAs<EmptyModel,void>();
    }
    else {
LAB_01273a0e:
      FUN_01273cb0(&local_ac,&local_24,&uStack_26,in_stack_00000000);
      local_a0 = local_ac;
      local_9c = local_a8;
      local_ac = 0;
      local_a8 = 0;
      Progress::NUL((Progress *)&local_8c);
      OperationDelegate::runCommand<EmptyModel>((shared_ptr *)abStack_fc,psVar3);
      FUN_011e01a0(&local_8c);
      FUN_011e4048(&local_a0);
      FUN_011e558c(&local_ac);
      if ((*local_e4 == -6) || (*local_e4 == -0xb)) {
        Result<EmptyModel,void>::Result((Result<EmptyModel,void> *)param_1,-0x2a);
      }
      else {
        Result<EmptyModel,void>::Result((Result<EmptyModel,void> *)param_1,(Result *)abStack_fc);
      }
    }
    Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)abStack_fc);
  }
  else {
    Result<EmptyModel,void>::Result((Result<EmptyModel,void> *)param_1,(Result *)asStack_d8);
  }
  Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)asStack_d8);
LAB_01273acc:
  Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)asStack_84);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


