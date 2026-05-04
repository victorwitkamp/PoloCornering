/* VagOperationDelegate::writeVagUdsValue @ 012737e0 */


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


