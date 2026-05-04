/*
 * Communicator_runCommand_EmptyModel
 * ELF symbol address: 0x011DC844
 * Ghidra address: 0x011EC844 (ELF + 0x10000 image delta)
 * ELF symbol size: 2072 bytes
 * Symbol: _ZN12Communicator10runCommandI10EmptyModelEE6ResultIT_vERKNSt6__ndk110shared_ptrI7CommandIS3_EEERKNS6_I10StatisticsEE
 * Program: libCarista.so
 * Resolved function: Communicator::runCommand<EmptyModel> @ 011ec844
 * Signature: Result __stdcall runCommand<EmptyModel>(shared_ptr * param_1, shared_ptr * param_2)
 * Return type: /Demangler/CanProtocol/Result
pack(disabled)
Structure Result {
}
Length: 0 Alignment: 1

 * Function body: [[011ec844, 011ecbd1] [011ecc0c, 011ecd17]]
 * Parameters:
 *   [0] shared_ptr * param_1
 *   [1] shared_ptr * param_2
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014ea86c
 *   Communicator::runCommand<EmptyModel> @ 0141fe60 -> COMPUTED_CALL from 0141fe68
 * Direct callees/references:
 *   WRITE Stack[-0x174] from 011ec84e
 *   READ 011ed044 from 011ec852
 *   READ 014da87c from 011ec85c
 *   READ 015a7014 from 011ec85e
 *   WRITE Stack[-0x28] from 011ec860
 *   WRITE Stack[-0x164] from 011ec864
 *   CONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011ec866
 *   UNCONDITIONAL_CALL Communicator::initialize @ 01402e20 from 011ec86a
 *   UNCONDITIONAL_CALL Result<EmptyModel,void>::Result @ 0141fee0 from 011ec870
 *   WRITE Stack[-0x16c] from 011ec882
 *   WRITE Stack[-0x170] from 011ec888
 *   WRITE Stack[-0x14c] from 011ec88e
 *   WRITE Stack[-0x158] from 011ec892
 *   WRITE Stack[-0x160] from 011ec894
 *   READ 011ecbd4 from 011ec896
 *   READ 011ecbd8 from 011ec89e
 *   DATA 014da898 from 011ec8a2
 *   WRITE Stack[-0x15c] from 011ec8a2
 *   CONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011ec8a4
 *   CONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011ec8aa
 *   CONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011ec8ae
 *   READ 011ecbdc from 011ec8b0
 *   PARAM 00c6dac1 from 011ec8b2
 *   UNCONDITIONAL_CALL Log::d @ 013fb5b0 from 011ec8b4
 *   UNCONDITIONAL_CALL ThreadUtils::sleep @ 014037e0 from 011ec8bc
 *   WRITE Stack[-0x14c] from 011ec8c2
 *   CONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011ec8cc
 *   CONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011ec8d4
 *   CONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011ec8da
 *   UNCONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011ec8dc
 *   UNCONDITIONAL_CALL Communicator::establishEcuCommWithStats @ 01402c70 from 011ec8e4
 *   CONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011ec8ec
 *   WRITE Stack[-0x154] from 011ec8f0
 *   CONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011ec8f2
 *   READ Stack[-0x94] from 011ec8f4
 *   CONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011ec8fa
 *   CONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011ec90e
 *   UNCONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011ec916
 *   CONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011ec92a
 *   UNCONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011ec932
 *   UNCONDITIONAL_CALL Communicator::TimeoutSpec::getCommandTimeout @ 01402960 from 011ec93a
 *   UNCONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011ec940
 *   READ Stack[-0x154] from 011ec946
 *   UNCONDITIONAL_CALL Communicator::TimeoutSpec::getCommandTimeout @ 01402960 from 011ec948
 *   READ 011ecbe0 from 011ec94e
 *   PARAM 0093feb5 from 011ec952
 *   UNCONDITIONAL_CALL Log::d @ 013fb5b0 from 011ec954
 *   READ Stack[-0x14c] from 011ec958
 *   WRITE Stack[-0x178] from 011ec964
 *   UNCONDITIONAL_CALL Communicator::internalExecuteCommand<EmptyModel> @ 0141fec0 from 011ec96a
 *   UNCONDITIONAL_CALL BroadcastCommandResult<EmptyModel>::extractCommandResult @ 0141fe00 from 011ec97a
 *   UNCONDITIONAL_CALL Result<EmptyModel,void>::operator= @ 0141fef0 from 011ec984
 *   UNCONDITIONAL_CALL Result<EmptyModel,void>::~Result @ 013fd720 from 011ec98a
 *   CONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011ec994
 *   READ 011ecbe4 from 011ec996
 *   READ 014db42c from 011ec99a
 *   PARAM 014f1828 from 011ec99a
 *   UNCONDITIONAL_CALL Result<EmptyModel,void>::isIn @ 0141ff00 from 011ec99e
 *   WRITE Stack[-0x150] from 011ec9a2
 *   UNCONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011ec9a8
 *   WRITE Stack[-0x150] from 011ec9ac
 *   READ Stack[-0x94] from 011ec9ae
 *   READ Stack[-0x14c] from 011ec9b8
 *   CONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011ec9c0
 *   READ 014daadc from 011ec9c4
 *   WRITE Stack[-0x168] from 011ec9c8
 *   READ 014f1418 from 011ec9ca
 *   READ 011ecbe8 from 011ec9ce
 *   PARAM 006d39ed from 011ec9d2
 *   UNCONDITIONAL_CALL FUN_00cb4d44 @ 00cb4d44 from 011ec9d4
 *   READ 011ecbec from 011ec9da
 *   PARAM 0082cde2 from 011ec9de
 *   UNCONDITIONAL_CALL FUN_00cb4d44 @ 00cb4d44 from 011ec9e0
 *   READ Stack[-0x94] from 011ec9e4
 *   UNCONDITIONAL_CALL Analytics::Event::Param::Param @ 01402210 from 011ec9ec
 *   READ 011ecbf0 from 011ec9f0
 *   PARAM 00a54c04 from 011ec9f4
 *   UNCONDITIONAL_CALL FUN_00cb4d44 @ 00cb4d44 from 011ec9f6
 *   READ Stack[-0x164] from 011ec9fc
 *   READ Stack[-0x16c] from 011eca06
 *   UNCONDITIONAL_CALL Analytics::Event::Param::Param @ 013fe2c0 from 011eca0c
 *   READ 011ecbf4 from 011eca10
 *   PARAM 0082cf19 from 011eca14
 *   UNCONDITIONAL_CALL FUN_00cb4d44 @ 00cb4d44 from 011eca16
 *   READ Stack[-0x170] from 011eca2a
 *   UNCONDITIONAL_CALL Analytics::Event::Param::Param @ 013fe2c0 from 011eca30
 *   READ 011ecbf8 from 011eca34
 *   PARAM 006d3a14 from 011eca38
 *   UNCONDITIONAL_CALL FUN_00cb4d44 @ 00cb4d44 from 011eca3a
 *   UNCONDITIONAL_CALL ByteUtils::getHexString @ 013fd820 from 011eca52
 *   UNCONDITIONAL_CALL Analytics::Event::Param::Param @ 013fe2c0 from 011eca5c
 *   UNCONDITIONAL_CALL FUN_00ce429c @ 00ce429c from 011eca6a
 *   UNCONDITIONAL_CALL FUN_00ce431c @ 00ce431c from 011eca80
 *   READ Stack[-0x164] from 011eca84
 *   UNCONDITIONAL_CALL Analytics::Event::Param::~Param @ 013fa5a0 from 011eca92
 *   CONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011eca9c
 *   READ Stack[-0x15c] from 011eca9e
 *   READ 014da898 from 011ecaa0
 *   COMPUTED_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 0130ff6e from 011ecaa4
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 011ecaa8
 *   COMPUTED_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 0130ff6e from 011ecaae
 *   COMPUTED_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 0130ff6e from 011ecab2
 *   COMPUTED_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 0130ff6e from 011ecab6
 *   COMPUTED_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 0130ff6e from 011ecaba
 *   COMPUTED_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 0130ff6e from 011ecabe
 *   COMPUTED_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 0130ff6e from 011ecac2
 *   COMPUTED_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 0130ff6e from 011ecac6
 *   READ Stack[-0x94] from 011ecac8
 *   READ Stack[-0x168] from 011ecacc
 *   CONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011ecad4
 *   READ Stack[-0x160] from 011ecad6
 *   WRITE Stack[-0x150] from 011ecae2
 *   UNCONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011ecae4
 *   WRITE Stack[-0x160] from 011ecae8
 *   READ Stack[-0x158] from 011ecaf2
 *   WRITE Stack[-0x158] from 011ecaf8
 *   UNCONDITIONAL_CALL Result<std::__ndk1::unordered_map<Ecu*,Result<EmptyModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<EmptyModel,void>>>>,void>::~Result @ 0141fe10 from 011ecafc
 *   READ Stack[-0x154] from 011ecb00
 *   READ Stack[-0x150] from 011ecb02
 *   UNCONDITIONAL_JUMP Communicator::runCommand<EmptyModel> @ 011ec844 from 011ecb06
 */

/* Ghidra function: Communicator::runCommand<EmptyModel> @ 011ec844 */

/* First instructions after recreation:
 * Memory bytes: f0b503af2de9000fd5b001909846dff8f00792468b467844006800685490087b
 * 011ec844: push {r4,r5,r6,r7,lr}
 * 011ec846: add r7,sp,#0xc
 * 011ec848: push {r8,r9,r10,r11}
 * 011ec84c: sub sp,#0x154
 * 011ec84e: str r0,[sp,#0x4]
 * 011ec850: mov r8,r3
 * 011ec852: ldr.w r0,[0x011ed044]
 * 011ec856: mov r10,r2
 * 011ec858: mov r11,r1
 * 011ec85a: add r0,pc
 * 011ec85c: ldr r0,[r0,#0x0]
 * 011ec85e: ldr r0,[r0,#0x0]
 * 011ec860: str r0,[sp,#0x150]
 * 011ec862: ldrb r0,[r1,#0xc]
 * 011ec864: str r1,[sp,#0x14]
 * 011ec866: cbnz r0,0x011ec86e
 * 011ec868: mov r0,r11
 * 011ec86a: blx 0x01402e20
 * 011ec86e: add r0,sp,#0xcc
 * 011ec870: blx 0x0141fee0
 * 011ec874: add r0,sp,#0xf0
 * 011ec876: movs r4,#0x0
 * 011ec878: add.w r1,r0,#0x30
 * 011ec87c: add.w r6,r0,#0x48
 */


/* Result<EmptyModel, void>
   Communicator::runCommand<EmptyModel>(std::__ndk1::shared_ptr<Command<EmptyModel> > const&,
   std::__ndk1::shared_ptr<Statistics> const&) */

void Communicator::runCommand<EmptyModel>(shared_ptr *param_1,shared_ptr *param_2)

{
  byte bVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  TimeoutSpec *pTVar5;
  int iVar6;
  bool bVar7;
  Ecu *pEVar8;
  int *in_r2;
  int iVar9;
  shared_ptr *in_r3;
  uint uVar10;
  undefined4 uVar11;
  int local_160;
  uint local_150;
  vector avStack_148 [12];
  ByteUtils aBStack_13c [12];
  basic_string abStack_130 [12];
  basic_string abStack_124 [12];
  basic_string abStack_118 [12];
  basic_string abStack_10c [12];
  basic_string abStack_100 [12];
  basic_string abStack_f4 [12];
  basic_string abStack_e8 [12];
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> abStack_dc [12];
  shared_ptr asStack_d0 [36];
  Result<EmptyModel,void> aRStack_ac [24];
  int *local_94;
  Ecu aEStack_88 [24];
  Param aPStack_70 [24];
  Param aPStack_58 [24];
  Param aPStack_40 [24];
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (param_2[0xc] == (shared_ptr)0x0) {
    initialize((Communicator *)param_2);
  }
  Result<EmptyModel,void>::Result(aRStack_ac);
  uVar10 = 0;
  local_150 = 1;
  bVar1 = *(byte *)(*in_r2 + 0xe);
  bVar7 = false;
  local_160 = 0;
  while ((piVar2 = (int *)App::ANALYTICS, uVar10 < 4 && ((local_150 & 1) != 0))) {
    if (uVar10 != 0) {
      Log::d("Executing command returned NO DATA or ECU was busy; retrying...");
      ThreadUtils::sleep(300);
      bVar1 = 0;
    }
    puVar3 = *(undefined4 **)(param_2 + 0x10);
    if (puVar3 == (undefined4 *)0x0) {
      pEVar8 = *(Ecu **)(*in_r2 + 4);
LAB_011ec8e0:
      iVar4 = establishEcuCommWithStats((Communicator *)param_2,pEVar8,in_r3);
      if (iVar4 != 1) {
        Result<EmptyModel,void>::Result((Result<EmptyModel,void> *)param_1,iVar4);
        goto LAB_011eccf8;
      }
    }
    else {
      pEVar8 = *(Ecu **)(*in_r2 + 4);
      if (((Ecu *)*puVar3 != pEVar8) || (pEVar8 = (Ecu *)*puVar3, *(char *)(puVar3 + 1) != '\0'))
      goto LAB_011ec8e0;
    }
    if ((uVar10 == 0) || (*local_94 != -0x11)) {
      iVar4 = (**(code **)(**(int **)(param_2 + 4) + 0x140))();
      if (iVar4 == 0) {
        pTVar5 = (TimeoutSpec *)(**(code **)(*(int *)param_2 + 0x34))(param_2);
        TimeoutSpec::getCommandTimeout(pTVar5,0);
      }
      else {
        (**(code **)(*(int *)param_2 + 0x34))(param_2);
      }
    }
    else {
      iVar4 = (**(code **)(**(int **)(param_2 + 4) + 0x140))();
      if (iVar4 == 0) {
        pTVar5 = (TimeoutSpec *)(**(code **)(*(int *)param_2 + 0x34))(param_2);
        uVar11 = TimeoutSpec::getCommandTimeout(pTVar5,uVar10);
      }
      else {
        iVar4 = (**(code **)(*(int *)param_2 + 0x34))(param_2);
        uVar11 = *(undefined4 *)(iVar4 + 0x10);
      }
      Log::d("Executing command returned RESPONSE PENDING; retrying with a timeout of %zu ms...",
             uVar11);
    }
    internalExecuteCommand<EmptyModel>(asStack_d0,(uint)param_2,SUB41(in_r2,0));
    BroadcastCommandResult<EmptyModel>::extractCommandResult(aEStack_88);
    Result<EmptyModel,void>::operator=(aRStack_ac,(Result *)aEStack_88);
    Result<EmptyModel,void>::~Result((Result<EmptyModel,void> *)aEStack_88);
    iVar4 = *in_r2;
    if (*(char *)(iVar4 + 0xd) == '\0') {
      local_150 = 0;
    }
    else {
      local_150 = Result<EmptyModel,void>::isIn(aRStack_ac,(Set *)RETRY_COMMAND_STATES);
      iVar4 = *in_r2;
    }
    piVar2 = (int *)App::ANALYTICS;
    iVar9 = *local_94;
    iVar6 = iVar9;
    if (((*(byte *)(iVar4 + 0xe) ^ 1 | bVar1) & 1) == 0) {
      FUN_00cb4d44(abStack_dc,"adaptive_timeout_explicitly_turned_off");
      FUN_00cb4d44(abStack_f4,"state");
      Analytics::Event::Param::Param((Param *)aEStack_88,abStack_f4,*local_94);
      FUN_00cb4d44(abStack_100,"communicator");
      (**(code **)(*(int *)param_2 + 8))(abStack_10c);
      Analytics::Event::Param::Param(aPStack_70,abStack_100,abStack_10c);
      FUN_00cb4d44(abStack_118,&DAT_0082cf19);
      (**(code **)(**(int **)(*in_r2 + 4) + 0x10))(abStack_124);
      Analytics::Event::Param::Param(aPStack_58,abStack_118,abStack_124);
      FUN_00cb4d44(abStack_130,"command");
      (**(code **)(*(int *)*in_r2 + 8))(avStack_148);
      ByteUtils::getHexString(aBStack_13c,avStack_148);
      Analytics::Event::Param::Param(aPStack_40,abStack_130,(basic_string *)aBStack_13c);
      FUN_00ce429c(abStack_e8,aEStack_88,4);
      (**(code **)(*piVar2 + 8))(piVar2,abStack_dc,abStack_e8);
      FUN_00ce431c(abStack_e8);
      iVar4 = 0x48;
      do {
        Analytics::Event::Param::~Param((Param *)(aEStack_88 + iVar4));
        iVar4 = iVar4 + -0x18;
      } while (iVar4 != -0x18);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)aBStack_13c);
      FUN_00cb7f50(avStack_148);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_130);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_124);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_118);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_10c);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_100);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_f4);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string(abStack_dc);
      iVar6 = *local_94;
    }
    if (iVar6 == -0xb) {
      local_160 = local_160 + 1;
      if (local_160 == 2) {
        local_160 = 2;
        local_150 = 0;
      }
    }
    else {
      local_160 = 0;
    }
    bVar7 = (bool)(bVar7 | iVar9 == -0x2e);
    Result<std::__ndk1::unordered_map<Ecu*,Result<EmptyModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<EmptyModel,void>>>>,void>
    ::~Result((Result<std::__ndk1::unordered_map<Ecu*,Result<EmptyModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<EmptyModel,void>>>>,void>
               *)asStack_d0);
    uVar10 = uVar10 + 1;
  }
  if (*local_94 == -0x2e) {
    FUN_00cb4d44(asStack_d0,"command_failed_with_can_error");
    FUN_00cb4d44(abStack_e8,"communicator");
    (**(code **)(*(int *)param_2 + 8))(abStack_f4,param_2);
    Analytics::Event::Param::Param((Param *)aEStack_88,abStack_e8,abStack_f4);
    FUN_00cb4d44(abStack_100,&DAT_0082cf19);
    (**(code **)(**(int **)(*in_r2 + 4) + 0x10))(abStack_10c);
    Analytics::Event::Param::Param(aPStack_70,abStack_100,abStack_10c);
    FUN_00cb4d44(abStack_118,"command");
    (**(code **)(*(int *)*in_r2 + 8))(abStack_130);
    ByteUtils::getHexString((ByteUtils *)abStack_124,(vector *)abStack_130);
    Analytics::Event::Param::Param(aPStack_58,abStack_118,abStack_124);
    FUN_00ce429c(abStack_dc,aEStack_88,3);
    (**(code **)(*piVar2 + 8))(piVar2,asStack_d0,abStack_dc);
    FUN_00ce431c(abStack_dc);
    iVar4 = 0x30;
    do {
      Analytics::Event::Param::~Param((Param *)(aEStack_88 + iVar4));
      iVar4 = iVar4 + -0x18;
    } while (iVar4 != -0x18);
  }
  else {
    if (!bVar7) goto LAB_011eccf0;
    FUN_00cb4d44(asStack_d0,"command_retry_success_after_can_error");
    FUN_00cb4d44(abStack_e8,"communicator");
    (**(code **)(*(int *)param_2 + 8))(abStack_f4,param_2);
    Analytics::Event::Param::Param((Param *)aEStack_88,abStack_e8,abStack_f4);
    FUN_00cb4d44(abStack_100,&DAT_0082cf19);
    (**(code **)(**(int **)(*in_r2 + 4) + 0x10))(abStack_10c);
    Analytics::Event::Param::Param(aPStack_70,abStack_100,abStack_10c);
    FUN_00cb4d44(abStack_118,"command");
    (**(code **)(*(int *)*in_r2 + 8))(abStack_130);
    ByteUtils::getHexString((ByteUtils *)abStack_124,(vector *)abStack_130);
    Analytics::Event::Param::Param(aPStack_58,abStack_118,abStack_124);
    FUN_00ce429c(abStack_dc,aEStack_88,3);
    (**(code **)(*piVar2 + 8))(piVar2,asStack_d0,abStack_dc);
    FUN_00ce431c(abStack_dc);
    iVar4 = 0x30;
    do {
      Analytics::Event::Param::~Param((Param *)(aEStack_88 + iVar4));
      iVar4 = iVar4 + -0x18;
    } while (iVar4 != -0x18);
  }
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                abStack_124);
  FUN_00cb7f50(abStack_130);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                abStack_118);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                abStack_10c);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                abStack_100);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                abStack_f4);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                abStack_e8);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                asStack_d0);
LAB_011eccf0:
  Result<EmptyModel,void>::Result((Result<EmptyModel,void> *)param_1,(Result *)aRStack_ac);
LAB_011eccf8:
  Result<EmptyModel,void>::~Result(aRStack_ac);
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


