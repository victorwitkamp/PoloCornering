/*
 * VagEcuInfo_getWorkshopCodeForWriting
 * ELF symbol address: 0x0110CD38
 * Ghidra address: 0x0111CD38 (ELF + 0x10000 image delta)
 * ELF symbol size: 692 bytes
 * Symbol: _ZN10VagEcuInfo25getWorkshopCodeForWritingEv
 * Program: libCarista.so
 * Resolved function: VagEcuInfo::getWorkshopCodeForWriting @ 0111cd38
 * Signature: undefined __stdcall getWorkshopCodeForWriting(void)
 * Return type: undefined
 * Function body: [[0111cd38, 0111cf6b]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014b519c
 *   <no function> -> DATA from 014b51f4
 * Direct callees/references:
 *   READ 0111cfd0 from 0111cd44
 *   READ 014da87c from 0111cd48
 *   READ 015a7014 from 0111cd4a
 *   WRITE Stack[-0x28] from 0111cd4c
 *   WRITE Stack[-0xa0] from 0111cd52
 *   WRITE Stack[-0xa8] from 0111cd54
 *   CONDITIONAL_JUMP VagEcuInfo::getWorkshopCodeForWriting @ 0111cd38 from 0111cd58
 *   CONDITIONAL_JUMP VagEcuInfo::getWorkshopCodeForWriting @ 0111cd38 from 0111cd62
 *   UNCONDITIONAL_CALL FUN_00cdbb80 @ 00cdbb80 from 0111cd66
 *   UNCONDITIONAL_JUMP VagEcuInfo::getWorkshopCodeForWriting @ 0111cd38 from 0111cd6a
 *   WRITE Stack[-0x6c] from 0111cd6c
 *   WRITE Stack[-0x70] from 0111cd70
 *   UNCONDITIONAL_CALL FUN_0111cfec @ 0111cfec from 0111cd78
 *   WRITE Stack[-0xb0] from 0111cd7c
 *   READ 0111cfd8 from 0111cd7e
 *   READ 014f691c from 0111cd82
 *   CONDITIONAL_JUMP VagEcuInfo::getWorkshopCodeForWriting @ 0111cd38 from 0111cd8a
 *   READ 014f6920 from 0111cd8c
 *   READ 014f6924 from 0111cd8c
 *   WRITE Stack[-0xac] from 0111cd98
 *   READ Stack[-0xac] from 0111cd9e
 *   CONDITIONAL_JUMP VagEcuInfo::getWorkshopCodeForWriting @ 0111cd38 from 0111cda2
 *   UNCONDITIONAL_CALL ByteUtils::extractValue @ 01400d20 from 0111cdae
 *   UNCONDITIONAL_CALL _ZN9ByteUtils7getLongERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE @ 013ff0d0 from 0111cdb4
 *   CONDITIONAL_JUMP VagEcuInfo::getWorkshopCodeForWriting @ 0111cd38 from 0111cdba
 *   UNCONDITIONAL_CALL ByteUtils::getBytesFromLong @ 01401170 from 0111cdc6
 *   WRITE Stack[-0xb8] from 0111cdd2
 *   UNCONDITIONAL_CALL ByteUtils::insertValue @ 0140de10 from 0111cdd6
 *   UNCONDITIONAL_CALL FUN_00cda396 @ 00cda396 from 0111cdde
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 0111cde4
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 0111cdea
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 0111cdf0
 *   UNCONDITIONAL_JUMP VagEcuInfo::getWorkshopCodeForWriting @ 0111cd38 from 0111cdf8
 *   READ Stack[-0xb0] from 0111cdfc
 *   READ Stack[-0xa8] from 0111cdfe
 *   WRITE Stack[-0xa0] from 0111ce04
 *   WRITE Stack[-0xa8] from 0111ce06
 *   UNCONDITIONAL_JUMP VagEcuInfo::getWorkshopCodeForWriting @ 0111cd38 from 0111ce0a
 *   UNCONDITIONAL_CALL FUN_00cd5ef0 @ 00cd5ef0 from 0111ce0e
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 0111ce14
 *   READ Stack[-0x28] from 0111ce18
 *   READ 0111cfd4 from 0111ce1a
 *   READ 014da87c from 0111ce1e
 *   READ 015a7014 from 0111ce20
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 0111ce2e
 *   READ 0111cfdc from 0111ce32
 *   PARAM 014f691c from 0111ce34
 *   UNCONDITIONAL_CALL __cxa_guard_acquire @ 013fd340 from 0111ce38
 *   CONDITIONAL_JUMP VagEcuInfo::getWorkshopCodeForWriting @ 0111cd38 from 0111ce3e
 *   WRITE Stack[-0x70] from 0111ce4c
 *   UNCONDITIONAL_CALL FUN_00cdb87c @ 00cdb87c from 0111ce60
 *   WRITE Stack[-0x5c] from 0111ce68
 *   WRITE Stack[-0x60] from 0111ce6a
 *   WRITE Stack[-0x58] from 0111ce72
 *   UNCONDITIONAL_CALL FUN_00cdb87c @ 00cdb87c from 0111ce86
 *   WRITE Stack[-0x48] from 0111ce90
 *   WRITE Stack[-0x40] from 0111ce94
 *   WRITE Stack[-0x86] from 0111ce9a
 *   WRITE Stack[-0x44] from 0111cea2
 *   WRITE Stack[-0x88] from 0111cea4
 *   UNCONDITIONAL_CALL FUN_00cdb87c @ 00cdb87c from 0111ceb0
 *   WRITE 014f6920 from 0111ceba
 *   WRITE Stack[-0x2c] from 0111cebe
 *   WRITE 014f6924 from 0111cec0
 *   WRITE 014f6928 from 0111cec0
 *   WRITE Stack[-0x30] from 0111cec4
 *   WRITE Stack[-0x90] from 0111cec6
 *   DATA 014f6920 from 0111ceca
 *   WRITE Stack[-0x94] from 0111ceca
 *   UNCONDITIONAL_CALL operator.new @ 013fa790 from 0111cece
 *   WRITE 014f6928 from 0111ced8
 *   WRITE Stack[-0x9c] from 0111cee0
 *   WRITE 014f6920 from 0111cee4
 *   WRITE 014f6924 from 0111cee4
 *   WRITE Stack[-0x74] from 0111ceea
 *   WRITE Stack[-0x78] from 0111cef0
 *   DATA 014f6928 from 0111cef4
 *   WRITE Stack[-0x80] from 0111cef4
 *   CONDITIONAL_JUMP VagEcuInfo::getWorkshopCodeForWriting @ 0111cd38 from 0111cefc
 *   READ Stack[-0x70] from 0111cf06
 *   UNCONDITIONAL_CALL FUN_00cd5ef0 @ 00cd5ef0 from 0111cf0a
 *   READ Stack[-0x60] from 0111cf0e
 *   READ Stack[-0x98] from 0111cf1a
 *   WRITE Stack[-0x98] from 0111cf20
 *   UNCONDITIONAL_JUMP VagEcuInfo::getWorkshopCodeForWriting @ 0111cd38 from 0111cf22
 *   WRITE Stack[-0x74] from 0111cf26
 *   UNCONDITIONAL_CALL FUN_0111d6c2 @ 0111d6c2 from 0111cf2c
 *   WRITE 014f6924 from 0111cf32
 *   WRITE Stack[-0x90] from 0111cf36
 *   UNCONDITIONAL_CALL FUN_0111d6ae @ 0111d6ae from 0111cf3c
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 0111cf46
 *   CONDITIONAL_JUMP VagEcuInfo::getWorkshopCodeForWriting @ 0111cd38 from 0111cf50
 *   READ 0111cfe0 from 0111cf52
 *   PARAM 014f6920 from 0111cf54
 *   READ 0111cfe4 from 0111cf58
 *   PARAM FUN_0111cffc @ 0111cffc from 0111cf5c
 *   PARAM 014371d0 from 0111cf5e
 *   UNCONDITIONAL_CALL <EXTERNAL>::__cxa_atexit @ 013fa330 from 0111cf60
 *   PARAM 014f691c from 0111cf64
 *   UNCONDITIONAL_CALL __cxa_guard_release @ 013fd350 from 0111cf66
 *   UNCONDITIONAL_JUMP VagEcuInfo::getWorkshopCodeForWriting @ 0111cd38 from 0111cf6a
 */

/* Ghidra function: VagEcuInfo::getWorkshopCodeForWriting @ 0111cd38 */

/* First instructions after recreation:
 * Memory bytes: f0b503af2de9000fa5b00446a24878440068006824900020496a0690cde90400
 * 0111cd38: push {r4,r5,r6,r7,lr}
 * 0111cd3a: add r7,sp,#0xc
 * 0111cd3c: push {r8,r9,r10,r11}
 * 0111cd40: sub sp,#0x94
 * 0111cd42: mov r4,r0
 * 0111cd44: ldr r0,[0x0111cfd0]
 * 0111cd46: add r0,pc
 * 0111cd48: ldr r0,[r0,#0x0]
 * 0111cd4a: ldr r0,[r0,#0x0]
 * 0111cd4c: str r0,[sp,#0x90]
 * 0111cd4e: movs r0,#0x0
 * 0111cd50: ldr r1,[r1,#0x24]
 * 0111cd52: str r0,[sp,#0x18]
 * 0111cd54: strd r0,r0,[sp,#0x10]
 * 0111cd58: cbz r1,0x0111cd6c
 * 0111cd5a: ldrd r0,r2,[r1,#0x0]
 * 0111cd5e: subs r0,r2,r0
 * 0111cd60: cmp r0,#0x6
 * 0111cd62: bne 0x0111ce0c
 * 0111cd64: add r0,sp,#0x10
 * 0111cd66: bl 0x00cdbb80
 * 0111cd6a: b 0x0111cd7c
 * 0111cd6c: strh.w r0,[sp,#0x4c]
 * 0111cd70: str r0,[sp,#0x48]
 */


/* VagEcuInfo::getWorkshopCodeForWriting() */

void VagEcuInfo::getWorkshopCodeForWriting(void)

{
  undefined4 *in_r0;
  int iVar1;
  uint *puVar2;
  int in_r1;
  int *piVar3;
  uint uVar4;
  uint *puVar5;
  longlong lVar6;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 local_a0;
  uint *local_9c;
  uint *local_98;
  undefined4 *local_94;
  undefined1 local_90;
  undefined2 local_88;
  undefined1 local_86;
  undefined2 uStack_85;
  undefined2 uStack_83;
  undefined1 uStack_81;
  undefined4 *local_80;
  uint **ppuStack_7c;
  uint **local_78;
  undefined1 local_74;
  uint local_70;
  undefined2 local_6c [6];
  uint local_60 [3];
  undefined1 auStack_54 [12];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined1 auStack_3c [12];
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  piVar3 = *(int **)(in_r1 + 0x24);
  local_a0 = 0;
  local_a8 = 0;
  uStack_a4 = 0;
  if (piVar3 == (int *)0x0) {
    local_6c[0] = 0;
    local_70 = 0;
    FUN_0111cfec(&local_a8,&local_70,6);
  }
  else {
    if (piVar3[1] - *piVar3 != 6) {
      FUN_00cd5ef0();
      goto LAB_0111ce12;
    }
    FUN_00cdbb80(&local_a8);
  }
  DataMemoryBarrier(0x1b);
  if (((DAT_014f691c & 1) == 0) && (iVar1 = __cxa_guard_acquire(), iVar1 != 0)) {
    uStack_81 = 0xf8;
    local_70 = 0;
    uStack_83 = 0xffff;
    FUN_00cdb87c(local_6c,&uStack_83,3);
    local_60[1] = 0;
    local_60[0] = 0x3039;
    local_60[2] = 2;
    uStack_85 = 0xfe07;
    FUN_00cdb87c(auStack_54,&uStack_85,2);
    local_48 = 0x7b;
    local_40 = 3;
    local_86 = 0xff;
    local_44 = 0;
    local_88 = 0xff01;
    FUN_00cdb87c(auStack_3c,&local_88,3);
    DAT_014f6920 = (uint *)0x0;
    local_2c = 0;
    DAT_014f6924 = (uint *)0x0;
    DAT_014f6928 = (uint *)0x0;
    local_30 = 0x3039;
    local_90 = 0;
    local_94 = &DAT_014f6920;
    puVar2 = operator_new(0x48);
    DAT_014f6928 = puVar2 + 0x12;
    local_74 = 0;
    local_78 = &local_98;
    ppuStack_7c = &local_9c;
    local_80 = &DAT_014f6928;
    DAT_014f6920 = puVar2;
    DAT_014f6924 = puVar2;
    local_9c = puVar2;
    for (iVar1 = 0; local_98 = puVar2, iVar1 != 0x48; iVar1 = iVar1 + 0x18) {
      *puVar2 = *(uint *)((int)local_6c + iVar1 + -4);
      FUN_00cd5ef0(puVar2 + 1,(int)local_6c + iVar1);
      uVar4 = *(uint *)((int)local_60 + iVar1 + 4);
      puVar2[4] = *(uint *)((int)local_60 + iVar1);
      puVar2[5] = uVar4;
      puVar2 = local_98 + 6;
    }
    local_74 = 1;
    FUN_0111d6c2(&local_80);
    local_90 = 1;
    DAT_014f6924 = puVar2;
    FUN_0111d6ae(&local_94);
    iVar1 = 0x34;
    do {
      FUN_00cb7f50((int)local_6c + iVar1 + -4);
      iVar1 = iVar1 + -0x18;
    } while (iVar1 != -0x14);
    __cxa_atexit(0x111cffd,&DAT_014f6920,&DAT_014371d0);
    __cxa_guard_release(&DAT_014f691c);
  }
  puVar2 = DAT_014f6924;
  for (puVar5 = DAT_014f6920; puVar5 != puVar2; puVar5 = puVar5 + 6) {
    ByteUtils::extractValue
              ((ByteUtils *)&local_70,(vector *)&local_a8,*puVar5,(vector *)(puVar5 + 1));
    lVar6 = _ZN9ByteUtils7getLongERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE((ByteUtils *)&local_70);
    if (lVar6 == 0) {
      uVar4 = *puVar5;
      ByteUtils::getBytesFromLong(ZEXT48((vector *)&local_94));
      ByteUtils::insertValue
                ((ByteUtils *)&local_80,(vector *)&local_a8,uVar4,(vector *)(puVar5 + 1),
                 (vector *)&local_94);
      FUN_00cda396((vector *)&local_a8,(ByteUtils *)&local_80);
      FUN_00cb7f50((ByteUtils *)&local_80);
      FUN_00cb7f50((vector *)&local_94);
    }
    FUN_00cb7f50((ByteUtils *)&local_70);
  }
  *in_r0 = local_a8;
  in_r0[1] = uStack_a4;
  in_r0[2] = local_a0;
  local_a0 = 0;
  local_a8 = 0;
  uStack_a4 = 0;
LAB_0111ce12:
  FUN_00cb7f50(&local_a8);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


