/*
 * GetVagCanEcuInfoCommand_processEcuInfo
 * ELF symbol address: 0x00CF8654
 * Ghidra address: 0x00D08654 (ELF + 0x10000 image delta)
 * ELF symbol size: 888 bytes
 * Symbol: _ZNK23GetVagCanEcuInfoCommand14processEcuInfoERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE
 * Program: libCarista.so
 * Resolved function: GetVagCanEcuInfoCommand::processEcuInfo @ 00d08654
 * Signature: undefined __stdcall processEcuInfo(vector * param_1)
 * Return type: undefined
 * Function body: [[00d08654, 00d08919]]
 * Parameters:
 *   [0] vector * param_1
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 0143bcf4
 * Direct callees/references:
 *   READ 00d089a0 from 00d08660
 *   READ 014da87c from 00d08664
 *   READ 015a7014 from 00d08666
 *   WRITE Stack[-0x24] from 00d08668
 *   CONDITIONAL_JUMP GetVagCanEcuInfoCommand::processEcuInfo @ 00d08654 from 00d08672
 *   READ 00d089a4 from 00d08674
 *   PARAM 00c4a57b from 00d08676
 *   UNCONDITIONAL_CALL Log::e @ 013fa760 from 00d08678
 *   UNCONDITIONAL_CALL Result<VagEcuInfoWithCoding,void>::Result @ 01401310 from 00d08682
 *   UNCONDITIONAL_JUMP GetVagCanEcuInfoCommand::processEcuInfo @ 00d08654 from 00d08686
 *   UNCONDITIONAL_CALL operator.new @ 013fa790 from 00d0868c
 *   WRITE Stack[-0x28] from 00d08692
 *   WRITE Stack[-0x2c] from 00d08694
 *   WRITE Stack[-0x30] from 00d08698
 *   UNCONDITIONAL_CALL StringUtils::trim @ 013fee40 from 00d086ae
 *   UNCONDITIONAL_CALL FUN_00cbe908 @ 00cbe908 from 00d086ba
 *   UNCONDITIONAL_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 013fa600 from 00d086c0
 *   UNCONDITIONAL_CALL StringUtils::latin1ToUtf8 @ 013fece0 from 00d086c8
 *   UNCONDITIONAL_CALL FUN_00cbe908 @ 00cbe908 from 00d086d2
 *   UNCONDITIONAL_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 013fa600 from 00d086d8
 *   WRITE Stack[-0x4c] from 00d086de
 *   CONDITIONAL_JUMP GetVagCanEcuInfoCommand::processEcuInfo @ 00d08654 from 00d086e8
 *   CONDITIONAL_JUMP GetVagCanEcuInfoCommand::processEcuInfo @ 00d08654 from 00d086ec
 *   WRITE Stack[-0x44] from 00d086f0
 *   UNCONDITIONAL_CALL ByteUtils::subrange @ 013fd600 from 00d086fa
 *   UNCONDITIONAL_CALL FUN_00cbd868 @ 00cbd868 from 00d08702
 *   UNCONDITIONAL_JUMP GetVagCanEcuInfoCommand::processEcuInfo @ 00d08654 from 00d08706
 *   UNCONDITIONAL_JUMP GetVagCanEcuInfoCommand::processEcuInfo @ 00d08654 from 00d0870a
 *   CONDITIONAL_JUMP GetVagCanEcuInfoCommand::processEcuInfo @ 00d08654 from 00d08710
 *   WRITE Stack[-0x44] from 00d08714
 *   UNCONDITIONAL_CALL ByteUtils::subrange @ 013fd600 from 00d0871e
 *   UNCONDITIONAL_CALL FUN_00cbd868 @ 00cbd868 from 00d08726
 *   UNCONDITIONAL_CALL FUN_00d089cc @ 00d089cc from 00d08730
 *   UNCONDITIONAL_CALL FUN_00cbd77c @ 00cbd77c from 00d08736
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 00d0873c
 *   UNCONDITIONAL_JUMP GetVagCanEcuInfoCommand::processEcuInfo @ 00d08654 from 00d08740
 *   WRITE Stack[-0x44] from 00d08744
 *   UNCONDITIONAL_CALL ByteUtils::subrange @ 013fd600 from 00d0874e
 *   UNCONDITIONAL_CALL FUN_00cbd868 @ 00cbd868 from 00d0875a
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 00d08760
 *   UNCONDITIONAL_CALL ByteUtils::subrange @ 013fd600 from 00d0876c
 *   UNCONDITIONAL_CALL FUN_00cbd868 @ 00cbd868 from 00d08778
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 00d0877e
 *   WRITE Stack[-0x40] from 00d08784
 *   WRITE Stack[-0x38] from 00d08788
 *   CONDITIONAL_JUMP GetVagCanEcuInfoCommand::processEcuInfo @ 00d08654 from 00d08792
 *   UNCONDITIONAL_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::__init @ 013fa360 from 00d087a4
 *   UNCONDITIONAL_CALL FUN_00cbe908 @ 00cbe908 from 00d087b0
 *   UNCONDITIONAL_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 013fa600 from 00d087b6
 *   UNCONDITIONAL_CALL StringUtils::latin1ToUtf8 @ 013fece0 from 00d087be
 *   UNCONDITIONAL_CALL FUN_00cbe908 @ 00cbe908 from 00d087ca
 *   UNCONDITIONAL_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 013fa600 from 00d087d0
 *   UNCONDITIONAL_CALL StringUtils::trim @ 013fee40 from 00d087d8
 *   UNCONDITIONAL_CALL FUN_00cbe908 @ 00cbe908 from 00d087e2
 *   UNCONDITIONAL_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 013fa600 from 00d087e8
 *   READ 00d089ac from 00d087ec
 *   READ 014f1658 from 00d087f0
 *   CONDITIONAL_JUMP GetVagCanEcuInfoCommand::processEcuInfo @ 00d08654 from 00d087f8
 *   READ 00d089c0 from 00d087fc
 *   PARAM 006d3872 from 00d087fe
 *   UNCONDITIONAL_CALL FUN_00cb4d44 @ 00cb4d44 from 00d08800
 *   PARAM 014f165c from 00d08806
 *   WRITE Stack[-0xd0] from 00d08808
 *   UNCONDITIONAL_CALL FUN_00d08a7e @ 00d08a7e from 00d08810
 *   UNCONDITIONAL_CALL FUN_00cbe908 @ 00cbe908 from 00d0881a
 *   UNCONDITIONAL_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 013fa600 from 00d08820
 *   UNCONDITIONAL_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 013fa600 from 00d08826
 *   WRITE Stack[-0x78] from 00d0882c
 *   UNCONDITIONAL_CALL FUN_00cfc754 @ 00cfc754 from 00d08832
 *   UNCONDITIONAL_CALL FUN_00d084e8 @ 00d084e8 from 00d08838
 *   UNCONDITIONAL_CALL FUN_00d08b44 @ 00d08b44 from 00d08840
 *   UNCONDITIONAL_CALL FUN_00cfc754 @ 00cfc754 from 00d0884a
 *   WRITE Stack[-0x94] from 00d08850
 *   WRITE Stack[-0x9c] from 00d08852
 *   WRITE Stack[-0xa4] from 00d08856
 *   WRITE Stack[-0xa8] from 00d08860
 *   WRITE Stack[-0xb0] from 00d08862
 *   WRITE Stack[-0xd0] from 00d0886e
 *   WRITE Stack[-0xc8] from 00d08874
 *   WRITE Stack[-0xbc] from 00d08878
 *   WRITE Stack[-0xb4] from 00d0887c
 *   UNCONDITIONAL_CALL FUN_00d08ad8 @ 00d08ad8 from 00d08886
 *   UNCONDITIONAL_CALL Result<VagEcuInfoWithCoding,void>::done @ 01401320 from 00d0888e
 *   UNCONDITIONAL_CALL FUN_00d08630 @ 00d08630 from 00d08894
 *   UNCONDITIONAL_CALL FUN_00cbd6dc @ 00cbd6dc from 00d0889a
 *   UNCONDITIONAL_CALL FUN_00d08b74 @ 00d08b74 from 00d088a0
 *   UNCONDITIONAL_CALL FUN_00d08642 @ 00d08642 from 00d088a6
 *   UNCONDITIONAL_CALL FUN_00cbd6dc @ 00cbd6dc from 00d088ac
 *   UNCONDITIONAL_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 013fa600 from 00d088b2
 *   READ 00d089c4 from 00d088b8
 *   COMPUTED_CALL FUN_00cbd77c @ 00cbd77c from 00d088bc
 *   COMPUTED_CALL FUN_00cbd77c @ 00cbd77c from 00d088c0
 *   COMPUTED_CALL FUN_00cbd77c @ 00cbd77c from 00d088c4
 *   UNCONDITIONAL_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 013fa600 from 00d088c8
 *   READ Stack[-0x24] from 00d088cc
 *   READ 00d089a8 from 00d088ce
 *   READ 014da87c from 00d088d2
 *   READ 015a7014 from 00d088d4
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00d088e2
 *   READ 00d089b0 from 00d088e6
 *   PARAM 014f1658 from 00d088ea
 *   UNCONDITIONAL_CALL __cxa_guard_acquire @ 013fd340 from 00d088ec
 *   CONDITIONAL_JUMP GetVagCanEcuInfoCommand::processEcuInfo @ 00d08654 from 00d088f2
 *   READ 00d089b4 from 00d088f4
 *   PARAM 00899fdc from 00d088fa
 *   PARAM 014f165c from 00d088fc
 *   UNCONDITIONAL_CALL FUN_00d08a18 @ 00d08a18 from 00d088fe
 *   READ 00d089b8 from 00d08902
 *   PARAM 014f165c from 00d08904
 *   READ 00d089bc from 00d08906
 *   PARAM 014371d0 from 00d0890a
 *   READ 014db1f8 from 00d0890c
 *   PARAM std::__ndk1::basic_regex<char,std::__ndk1::regex_traits<char>>::~basic_regex @ 00d08a68 from 00d0890c
 *   UNCONDITIONAL_CALL <EXTERNAL>::__cxa_atexit @ 013fa330 from 00d0890e
 *   PARAM 014f1658 from 00d08912
 *   UNCONDITIONAL_CALL __cxa_guard_release @ 013fd350 from 00d08914
 *   UNCONDITIONAL_JUMP GetVagCanEcuInfoCommand::processEcuInfo @ 00d08654 from 00d08918
 */

/* Ghidra function: GetVagCanEcuInfoCommand::processEcuInfo @ 00d08654 */

/* First instructions after recreation:
 * Memory bytes: f0b503af2de90007acb08246cf487844006800682b90d2e90040001b192809d8
 * 00d08654: push {r4,r5,r6,r7,lr}
 * 00d08656: add r7,sp,#0xc
 * 00d08658: push {r8,r9,r10}
 * 00d0865c: sub sp,#0xb0
 * 00d0865e: mov r10,r0
 * 00d08660: ldr r0,[0x00d089a0]
 * 00d08662: add r0,pc
 * 00d08664: ldr r0,[r0,#0x0]
 * 00d08666: ldr r0,[r0,#0x0]
 * 00d08668: str r0,[sp,#0xac]
 * 00d0866a: ldrd r4,r0,[r2,#0x0]
 * 00d0866e: subs r0,r0,r4
 * 00d08670: cmp r0,#0x19
 * 00d08672: bhi 0x00d08688
 * 00d08674: ldr r0,[0x00d089a4]
 * 00d08676: add r0,pc
 * 00d08678: blx 0x013fa760
 * 00d0867c: mov r0,r10
 * 00d0867e: mvn r1,#0x5
 * 00d08682: blx 0x01401310
 * 00d08686: b 0x00d088cc
 * 00d08688: movs r0,#0x10
 * 00d0868a: mov r6,r2
 * 00d0868c: blx 0x013fa790
 */


/* GetVagCanEcuInfoCommand::processEcuInfo(std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&) const */

void GetVagCanEcuInfoCommand::processEcuInfo(vector *param_1)

{
  uint uVar1;
  int iVar2;
  vector *in_r2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined4 local_a4;
  undefined4 uStack_a0;
  undefined4 local_9c;
  undefined4 uStack_98;
  undefined4 local_94;
  undefined1 auStack_90 [8];
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [8];
  undefined4 local_78;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> abStack_74 [12];
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> abStack_68 [12];
  undefined1 auStack_5c [8];
  undefined1 auStack_54 [8];
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 *local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  puVar3 = *(undefined8 **)in_r2;
  if ((uint)(*(int *)(in_r2 + 4) - (int)puVar3) < 0x1a) {
    Log::e("ECU info payload is too short");
    Result<VagEcuInfoWithCoding,void>::Result((Result<VagEcuInfoWithCoding,void> *)param_1,-6);
    goto LAB_00d088cc;
  }
  local_28 = operator_new(0x10);
  local_2c = 0xc;
  local_30 = 0x11;
  uVar4 = *puVar3;
  *(undefined4 *)(local_28 + 1) = *(undefined4 *)(puVar3 + 1);
  *(undefined1 *)((int)local_28 + 0xc) = 0;
  *local_28 = uVar4;
  StringUtils::trim((StringUtils *)&local_40,(basic_string *)&local_30);
  FUN_00cbe908(&local_30,
               (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
               &local_40);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                &local_40);
  StringUtils::latin1ToUtf8((basic_string *)&local_40);
  FUN_00cbe908(&local_30,
               (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
               &local_40);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                &local_40);
  local_4c = 0;
  uStack_48 = 0;
  uVar1 = (uint)*(byte *)(*(int *)in_r2 + 0x10);
  if (uVar1 == 0x10) {
    local_44 = 3;
  }
  else {
    if (uVar1 == 3) {
      local_44 = 2;
      ByteUtils::subrange((ByteUtils *)&local_40,in_r2,0x11,3);
      FUN_00cbd868(abStack_68,&local_40);
    }
    else {
      if (0xe < uVar1 - 0x21) {
        local_44 = 1;
        goto LAB_00d08746;
      }
      local_44 = 4;
      ByteUtils::subrange((ByteUtils *)&local_40,in_r2,0x11,3);
      FUN_00cbd868(abStack_68,&local_40);
    }
    FUN_00d089cc(&local_4c,abStack_68);
    FUN_00cbd77c(abStack_68);
    FUN_00cb7f50(&local_40);
  }
LAB_00d08746:
  ByteUtils::subrange((ByteUtils *)&local_40,in_r2,0x14,6);
  FUN_00cbd868(auStack_54,&local_40);
  FUN_00cb7f50(&local_40);
  ByteUtils::subrange((ByteUtils *)&local_40,in_r2,0xc,4);
  FUN_00cbd868(auStack_5c,&local_40);
  FUN_00cb7f50(&local_40);
  local_40 = 0;
  uStack_3c = 0;
  local_38 = 0;
  uVar1 = *(int *)(in_r2 + 4) - *(int *)in_r2;
  if (0x1a < uVar1) {
    uVar1 = uVar1 - 0x1a;
    if (0xf < uVar1) {
      uVar1 = 0x10;
    }
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    __init(abStack_68,(char *)(*(int *)in_r2 + 0x1a),uVar1);
    FUN_00cbe908(&local_40,abStack_68);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string(abStack_68);
    StringUtils::latin1ToUtf8((basic_string *)abStack_68);
    FUN_00cbe908((basic_string *)&local_40,abStack_68);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string(abStack_68);
    StringUtils::trim((StringUtils *)abStack_68,(basic_string *)&local_40);
    FUN_00cbe908(&local_40,abStack_68);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string(abStack_68);
    DataMemoryBarrier(0x1b);
    if (((DAT_014f1658 & 1) == 0) && (iVar2 = __cxa_guard_acquire(&DAT_014f1658), iVar2 != 0)) {
      FUN_00d08a18(&DAT_014f165c,&DAT_00899fdc,0);
      __cxa_atexit(std::__ndk1::basic_regex<char,std::__ndk1::regex_traits<char>>::~basic_regex,
                   &DAT_014f165c,&DAT_014371d0);
      __cxa_guard_release(&DAT_014f1658);
    }
    FUN_00cb4d44(abStack_74,&DAT_006d3872);
    FUN_00d08a7e(abStack_68,&local_40,&DAT_014f165c,abStack_74,0);
    FUN_00cbe908(&local_40,abStack_68);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string(abStack_68);
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string(abStack_74);
  }
  local_78 = 1;
  FUN_00cfc754(abStack_74,&local_30);
  FUN_00d084e8(auStack_80);
  FUN_00d08b44(auStack_88);
  FUN_00cfc754(auStack_90,&local_40);
  local_94 = 0;
  local_9c = 0;
  uStack_98 = 0;
  local_a4 = 0;
  uStack_a0 = 0;
  FUN_00d08ad8(abStack_68,&local_78,abStack_74,auStack_80,auStack_88,&local_44,&local_4c,auStack_54,
               auStack_5c,auStack_90,&local_94,&uStack_98,&local_9c,&uStack_a0,&local_a4);
  Result<VagEcuInfoWithCoding,void>::done
            ((Result<VagEcuInfoWithCoding,void> *)param_1,(shared_ptr *)abStack_68);
  FUN_00d08630(abStack_68);
  FUN_00cbd6dc(auStack_90);
  FUN_00d08b74(auStack_88);
  FUN_00d08642(auStack_80);
  FUN_00cbd6dc(abStack_74);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                &local_40);
  FUN_00cbd77c(auStack_5c);
  FUN_00cbd77c(auStack_54);
  FUN_00cbd77c(&local_4c);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                &local_30);
LAB_00d088cc:
  if (__stack_chk_guard == local_24) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


