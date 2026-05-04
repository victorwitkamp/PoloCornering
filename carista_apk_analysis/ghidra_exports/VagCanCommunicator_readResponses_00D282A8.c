/*
 * VagCanCommunicator_readResponses
 * ELF symbol address: 0x00D182A8
 * Ghidra address: 0x00D282A8 (ELF + 0x10000 image delta)
 * ELF symbol size: 1532 bytes
 * Symbol: _ZN18VagCanCommunicator13readResponsesEv
 * Program: libCarista.so
 * Resolved function: VagCanCommunicator::readResponses @ 00d282a8
 * Signature: undefined __stdcall readResponses(void)
 * Return type: undefined
 * Function body: [[00d282a8, 00d2873f] [00d28760, 00d287ef]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 0143dab4
 * Direct callees/references:
 *   WRITE Stack[-0x74] from 00d282b2
 *   READ 00d28878 from 00d282b4
 *   READ 014da87c from 00d282ba
 *   READ 015a7014 from 00d282bc
 *   WRITE Stack[-0x28] from 00d282be
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d282c4
 *   UNCONDITIONAL_CALL VagCanCommunicator::receive @ 01403d30 from 00d282d0
 *   WRITE Stack[-0x30] from 00d282dc
 *   WRITE Stack[-0x38] from 00d282e0
 *   WRITE Stack[-0x40] from 00d282e4
 *   UNCONDITIONAL_CALL VagCanCommunicator::consecutiveNegRespCount @ 01403d40 from 00d282ec
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d282f2
 *   READ Stack[-0x40] from 00d282f6
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d2830e
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d28314
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d2831a
 *   UNCONDITIONAL_CALL VagCanCommunicator::receiveMore @ 01403d50 from 00d2831e
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d2832a
 *   WRITE Stack[-0x48] from 00d28334
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d28338
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d28348
 *   UNCONDITIONAL_CALL FUN_00d2825c @ 00d2825c from 00d2834c
 *   READ Stack[-0x48] from 00d28350
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d28358
 *   UNCONDITIONAL_CALL FUN_00d1a378 @ 00d1a378 from 00d2835c
 *   UNCONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d28360
 *   UNCONDITIONAL_CALL VagCanCommunicator::parsePacket @ 01403ce0 from 00d28368
 *   READ Stack[-0x50] from 00d2836c
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d28374
 *   READ Stack[-0x50] from 00d28376
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d2837e
 *   READ Stack[-0x48] from 00d28380
 *   READ 00d28740 from 00d2838e
 *   PARAM 006d39af from 00d28390
 *   UNCONDITIONAL_CALL Log::w @ 013facb0 from 00d28392
 *   UNCONDITIONAL_CALL FUN_00d27d2c @ 00d27d2c from 00d28398
 *   UNCONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d2839c
 *   READ Stack[-0x50] from 00d2839e
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d283a4
 *   READ 00d28744 from 00d283a6
 *   PARAM 006ba450 from 00d283a8
 *   UNCONDITIONAL_CALL Log::d @ 013fb5b0 from 00d283aa
 *   UNCONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d283ae
 *   READ Stack[-0x50] from 00d283b8
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d283ba
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d283d2
 *   WRITE Stack[-0x78] from 00d283d8
 *   UNCONDITIONAL_CALL VagCanCommunicator::shouldEnable7fxx78Hack @ 01403d60 from 00d283da
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d283e0
 *   READ 00d28748 from 00d283e2
 *   PARAM 0078c24b from 00d283e4
 *   UNCONDITIONAL_CALL Log::d @ 013fb5b0 from 00d283e6
 *   READ Stack[-0x50] from 00d283ea
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d283f0
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d283fc
 *   READ Stack[-0x50] from 00d283fe
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d28412
 *   UNCONDITIONAL_CALL VagCanCommunicator::shouldEnable7fxx78Hack @ 01403d60 from 00d28418
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d2841e
 *   UNCONDITIONAL_CALL operator+= @ 013fd410 from 00d2842a
 *   READ Stack[-0x50] from 00d2842e
 *   READ 00d2874c from 00d28432
 *   DATA 014db410 from 00d28438
 *   WRITE Stack[-0x78] from 00d28438
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d2843a
 *   READ 00d28750 from 00d2843e
 *   PARAM 00bebf97 from 00d28444
 *   UNCONDITIONAL_CALL operator""__b @ 013fd3f0 from 00d28448
 *   UNCONDITIONAL_CALL ByteUtils::startsWith @ 013fd670 from 00d28450
 *   READ Stack[-0x34] from 00d28456
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 00d2845c
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d28474
 *   READ 00d28754 from 00d28476
 *   PARAM 00ab2940 from 00d28478
 *   UNCONDITIONAL_CALL Log::w @ 013facb0 from 00d2847a
 *   UNCONDITIONAL_CALL FUN_00cdfbb0 @ 00cdfbb0 from 00d28482
 *   UNCONDITIONAL_CALL ByteUtils::subrange @ 013fd600 from 00d28496
 *   READ Stack[-0x78] from 00d2849a
 *   READ 014db410 from 00d284a2
 *   PARAM 00c8f60c from 00d284a2
 *   UNCONDITIONAL_CALL FUN_00d28a58 @ 00d28a58 from 00d284a6
 *   UNCONDITIONAL_CALL FUN_00d1aaa4 @ 00d1aaa4 from 00d284ae
 *   UNCONDITIONAL_CALL FUN_00d1a378 @ 00d1a378 from 00d284c2
 *   UNCONDITIONAL_CALL FUN_00cb7f50 @ 00cb7f50 from 00d284c8
 *   READ Stack[-0x34] from 00d284cc
 *   WRITE Stack[-0x30] from 00d284ce
 *   READ Stack[-0x50] from 00d284d0
 *   UNCONDITIONAL_CALL VagCanCommunicator::sendAck @ 01403d70 from 00d284da
 *   UNCONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d284de
 *   READ 00d28758 from 00d284e0
 *   READ Stack[-0x78] from 00d284e4
 *   PARAM 00c6da04 from 00d284e6
 *   UNCONDITIONAL_CALL Log::w @ 013facb0 from 00d284e8
 *   UNCONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d284ec
 *   READ 00d2875c from 00d284ee
 *   PARAM 0092693d from 00d284f4
 *   UNCONDITIONAL_CALL Log::w @ 013facb0 from 00d284f6
 *   UNCONDITIONAL_CALL FUN_00d28e2a @ 00d28e2a from 00d284fc
 *   UNCONDITIONAL_CALL VagCanCommunicator::sendNack @ 01403d80 from 00d28504
 *   UNCONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d28508
 *   READ Stack[-0x50] from 00d2850a
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d28510
 *   READ Stack[-0x34] from 00d2851a
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d28522
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d28526
 *   UNCONDITIONAL_CALL ByteUtils::getShort @ 013fe290 from 00d2852a
 *   READ Stack[-0x50] from 00d28532
 *   WRITE Stack[-0x7c] from 00d28534
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d28546
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d28552
 *   READ Stack[-0x34] from 00d28554
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d2855c
 *   UNCONDITIONAL_CALL FUN_00cdfbb0 @ 00cdfbb0 from 00d28562
 *   READ Stack[-0x50] from 00d28572
 *   UNCONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d28576
 *   UNCONDITIONAL_CALL VagCanCommunicator::sendAck @ 01403d70 from 00d28586
 *   READ Stack[-0x34] from 00d2858a
 *   CONDITIONAL_JUMP VagCanCommunicator::readResponses @ 00d282a8 from 00d28596
 *   UNCONDITIONAL_CALL ByteUtils::getShort @ 013fdcf0 from 00d2859a
 *   UNCONDITIONAL_CALL Math::toExact<unsigned_short,unsigned_int> @ 01402b80 from 00d285a4
 */

/* Ghidra function: VagCanCommunicator::readResponses @ 00d282a8 */

/* First instructions after recreation:
 * Memory bytes: f0b503af2de9000f97b00390dff8c0057844006800681690486a002840f07c82
 * 00d282a8: push {r4,r5,r6,r7,lr}
 * 00d282aa: add r7,sp,#0xc
 * 00d282ac: push {r8,r9,r10,r11}
 * 00d282b0: sub sp,#0x5c
 * 00d282b2: str r0,[sp,#0xc]
 * 00d282b4: ldr.w r0,[0x00d28878]
 * 00d282b8: add r0,pc
 * 00d282ba: ldr r0,[r0,#0x0]
 * 00d282bc: ldr r0,[r0,#0x0]
 * 00d282be: str r0,[sp,#0x58]
 * 00d282c0: ldr r0,[r1,#0x24]
 * 00d282c2: cmp r0,#0x0
 * 00d282c4: bne.w 0x00d287c0
 * 00d282c8: mov r0,r1
 * 00d282ca: mov r5,r1
 * 00d282cc: add.w r6,r1,#0x1c
 * 00d282d0: blx 0x01403d30
 * 00d282d4: mov.w r9,#0x0
 * 00d282d8: mov.w r11,#0x0
 * 00d282dc: strd r9,r9,[sp,#0x50]
 * 00d282e0: strd r9,r9,[sp,#0x48]
 * 00d282e4: strd r9,r9,[sp,#0x40]
 * 00d282e8: add r4,sp,#0x10
 * 00d282ea: add r0,sp,#0x40
 */


/* VagCanCommunicator::readResponses() */

void VagCanCommunicator::readResponses(void)

{
  char cVar1;
  VagCanCommunicator *pVVar2;
  int iVar3;
  byte bVar4;
  short sVar5;
  ushort uVar6;
  int *in_r0;
  uint uVar7;
  int iVar8;
  int *piVar9;
  char *pcVar10;
  IllegalStateException *this;
  VagCanCommunicator VVar11;
  VagCanCommunicator *in_r1;
  vector *extraout_r2;
  VagCanCommunicator *pVVar12;
  uint uVar13;
  uint uVar14;
  undefined4 uVar15;
  bool bVar16;
  bool bVar17;
  ByteUtils aBStack_70 [12];
  undefined1 auStack_64 [8];
  int local_5c;
  int iStack_58;
  VagCanCommunicator *local_50 [2];
  int local_48;
  int iStack_44;
  int local_40;
  int iStack_3c;
  int local_38;
  int local_34;
  int local_30;
  undefined4 uStack_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (*(int *)(in_r1 + 0x24) != 0) {
    this = (IllegalStateException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(&local_34,
                 "VagCanCommunicator::readVagCanResponses() called with non-empty receivedPackets");
    IllegalStateException::IllegalStateException(this,(basic_string *)&local_34);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this,&IllegalStateException::typeinfo,IllegalStateException::~IllegalStateException)
    ;
  }
  pVVar12 = in_r1 + 0x1c;
  receive();
  uVar14 = 0;
  bVar17 = false;
  local_30 = 0;
  uStack_2c = 0;
  local_38 = 0;
  local_34 = 0;
  local_40 = 0;
  iStack_3c = 0;
LAB_00d282ea:
  do {
    uVar7 = consecutiveNegRespCount((vector *)&local_40);
    if (0x1e < uVar7) {
      Log::e("Reached limit for # of negative responses; giving up and terminating connection.");
      (**(code **)(*(int *)in_r1 + 0x38))();
LAB_00d28734:
      *in_r0 = 0;
      in_r0[1] = 0;
      in_r0[2] = 0;
      goto LAB_00d28792;
    }
    bVar16 = (bool)(bVar17 | local_40 == iStack_3c);
    iVar8 = *(int *)(in_r1 + 0x24);
    if (((iVar8 == 0) && (bVar16)) && (uVar14 < 2)) {
      receiveMore(in_r1);
      iVar8 = *(int *)(in_r1 + 0x24);
      uVar14 = uVar14 + 1;
    }
    if (iVar8 == 0) {
      if (bVar16) {
        (**(code **)(*(int *)in_r1 + 0x38))();
        goto LAB_00d28734;
      }
      goto LAB_00d28782;
    }
    local_48 = *(int *)(*(int *)(in_r1 + 0x20) + 8);
    iStack_44 = *(int *)(*(int *)(in_r1 + 0x20) + 0xc);
    if (iStack_44 != 0) {
      piVar9 = (int *)(iStack_44 + 4);
      do {
        ExclusiveAccess(piVar9);
        bVar16 = (bool)hasExclusiveAccess(piVar9);
      } while (!bVar16);
      *piVar9 = *piVar9 + 1;
    }
    FUN_00d2825c(pVVar12);
    if (*(int *)(local_48 + 4) != 1) {
LAB_00d2835a:
      FUN_00d1a378(&local_48);
      goto LAB_00d282ea;
    }
    parsePacket((VagCanCommunicator *)local_50,(basic_string *)(local_48 + 0xc));
    iVar8 = (**(code **)(*(int *)local_50[0] + 8))();
    if ((iVar8 == 0) || (iVar8 = (**(code **)(*(int *)local_50[0] + 0xc))(), iVar8 != 0)) {
      iVar8 = *(int *)(local_48 + 0x14);
      if ((*(byte *)(local_48 + 0xc) & 1) == 0) {
        iVar8 = local_48 + 0xd;
      }
      Log::w("Skipping invalid or bogus packet: %s",iVar8);
LAB_00d28396:
      FUN_00d27d2c(local_50);
      goto LAB_00d2835a;
    }
    if (local_50[0][10] == (VagCanCommunicator)0xa3) {
      Log::d("Ignoring keep-alive packet");
      goto LAB_00d28396;
    }
    iVar8 = (**(code **)(*(int *)local_50[0] + 0x10))();
    if (iVar8 != 0) {
      VVar11 = local_50[0][0xb];
      uVar7 = (uint)(byte)VVar11;
      uVar13 = (uint)(byte)in_r1[0x2a];
      if (uVar7 <= uVar13) {
        VVar11 = (VagCanCommunicator)((char)VVar11 + 0xf);
      }
      if (7 < (byte)VVar11 - uVar13) {
        iVar8 = shouldEnable7fxx78Hack(local_50[0],(vector *)(local_50[0] + 0xc));
        if (iVar8 == 0) {
          Log::w("Ignoring packet w/ seq # %X because we\'ve already seen up to %X",uVar7,uVar13);
          goto LAB_00d28396;
        }
        Log::d("Enabling 7fxx78 hack");
      }
    }
    if (local_50[0][10] == (VagCanCommunicator)0xa8) {
      Log::w("Channel disconnected.");
      (**(code **)(*(int *)in_r1 + 0x38))();
      FUN_00d28e2a(pVVar12);
      FUN_00d27d2c(local_50);
      FUN_00d1a378(&local_48);
      goto LAB_00d28782;
    }
    iVar8 = (**(code **)(*(int *)local_50[0] + 0x10))();
    pVVar2 = local_50[0];
    if (iVar8 == 0) goto LAB_00d28396;
    VVar11 = local_50[0][0xb];
    uVar14 = (byte)in_r1[0x2a] + 1 & 0xf;
    if (((byte)VVar11 != uVar14) &&
       (iVar8 = shouldEnable7fxx78Hack
                          ((VagCanCommunicator *)((byte)in_r1[0x2a] + 1),
                           (vector *)(local_50[0] + 0xc)), iVar8 == 0)) {
      Log::w("We got seq # %X, but were expecting %X. Sending ACK_WAIT.",(uint)(byte)VVar11,uVar14);
      FUN_00d28e2a(pVVar12);
      sendNack(in_r1,(uchar)uVar14);
LAB_00d285f8:
      uVar14 = 0;
      goto LAB_00d28396;
    }
    in_r1[0x2a] = VVar11;
    operator+=((vector *)&local_34,(vector *)(pVVar2 + 0xc));
    VVar11 = local_50[0][10];
    if (VVar11 != (VagCanCommunicator)0x20) goto LAB_00d2854c;
    operator____b((char *)&local_5c,0xbebf97);
    bVar4 = ByteUtils::startsWith((ByteUtils *)&local_34,(vector *)&local_5c,extraout_r2);
    iVar3 = local_30;
    iVar8 = local_34;
    FUN_00cb7f50(&local_5c);
    if ((3U < (uint)(iVar3 - iVar8) & bVar4) == 1) {
      Log::w("HACK activated: interpreting this frame as an error msg that expects an ACK");
      pcVar10 = (char *)FUN_00cdfbb0(&local_34,3);
      cVar1 = *pcVar10;
      uVar15 = *(undefined4 *)(in_r1 + 0x10);
      ByteUtils::subrange((ByteUtils *)&local_5c,(vector *)&local_34,1,3);
      FUN_00d28a58(aBStack_70,&State::DONE,uVar15,&local_5c);
      FUN_00d1aaa4(&local_40,aBStack_70);
      bVar17 = (bool)(bVar17 | cVar1 == 'x');
      FUN_00d1a378(aBStack_70);
      FUN_00cb7f50(&local_5c);
      local_30 = local_34;
      sendAck(in_r1,(uchar)local_50[0][0xb],bVar17);
      goto LAB_00d285f8;
    }
    VVar11 = local_50[0][10];
    if (VVar11 == (VagCanCommunicator)0x20) {
      uVar14 = *(int *)(local_50[0] + 0x10) - *(int *)(local_50[0] + 0xc);
      if ((local_30 - local_34 == uVar14) && (2 < uVar14)) {
        sVar5 = ByteUtils::getShort((vector *)(local_50[0] + 0xc),0);
        if (((int)sVar5 & 0xfffU) <=
            (*(int *)(local_50[0] + 0x10) - *(int *)(local_50[0] + 0xc)) - 2U) {
          Log::w("HACK2 activated: interpreting this frame as a stand-alone msg that expects an ACK"
                );
          uVar15 = *(undefined4 *)(in_r1 + 0x10);
          ByteUtils::subrange((ByteUtils *)&local_5c,(vector *)(local_50[0] + 0xc),2,
                              (int)sVar5 & 0xfffU);
          FUN_00d28a58(aBStack_70,&State::DONE,uVar15,(ByteUtils *)&local_5c);
          FUN_00d1aaa4(&local_40,aBStack_70);
          FUN_00d1a378(aBStack_70);
          FUN_00cb7f50(&local_5c);
          local_30 = local_34;
          sendAck(in_r1,(uchar)local_50[0][0xb],SUB21((ushort)sVar5 >> 0xf,0));
          uVar14 = 0;
          goto LAB_00d28396;
        }
        VVar11 = local_50[0][10];
        goto LAB_00d2854c;
      }
    }
    else {
LAB_00d2854c:
      if (((byte)VVar11 | 0x10) == 0x10) {
        if ((uint)(local_30 - local_34) < 2) {
          bVar16 = false;
        }
        else {
          pcVar10 = (char *)FUN_00cdfbb0(&local_34,0);
          bVar16 = *pcVar10 < '\0';
          VVar11 = local_50[0][10];
        }
        sendAck(in_r1,(uchar)local_50[0][0xb],(bool)(bVar16 | VVar11 == (VagCanCommunicator)0x0));
      }
    }
    uVar14 = local_30 - local_34;
    if (uVar14 < 2) {
LAB_00d285ac:
      if (((byte)local_50[0][10] | 0x20) != 0x30) goto LAB_00d285f8;
    }
    else {
      uVar7 = ByteUtils::getShort((vector *)&local_34);
      uVar6 = Math::toExact<unsigned_short,unsigned_int>((uVar7 & 0xfff) + 2);
      if (uVar14 < uVar6) goto LAB_00d285ac;
    }
    FUN_00cd5ef0(&local_5c,&local_34);
    local_30 = local_34;
    if ((uint)(iStack_58 - local_5c) < 2) {
      Log::e("Invalid TP2.0 message: cannot extract length");
      FUN_00d28aa4(aBStack_70,&State::TRANSPORT_LAYER_ERROR,*(undefined4 *)(in_r1 + 0x10));
      FUN_00d1aaa4(&local_40,aBStack_70);
LAB_00d2863c:
      FUN_00d1a378(aBStack_70);
      iVar8 = 3;
    }
    else {
      uVar14 = ByteUtils::getShort((vector *)&local_5c);
      uVar14 = uVar14 & 0xfff;
      if ((uVar14 == 0) || ((iStack_58 - local_5c) - 2U < uVar14)) {
        Log::e("Zero or mismatched receive length: was supposed to be %u but is %zu",uVar14);
        FUN_00d28aa4(aBStack_70,&State::TRANSPORT_LAYER_ERROR,*(undefined4 *)(in_r1 + 0x10));
        FUN_00d1aaa4(&local_40,aBStack_70);
        goto LAB_00d2863c;
      }
      pcVar10 = (char *)FUN_00cdfbb0(&local_5c,0);
      bVar17 = *pcVar10 < '\0';
      uVar15 = *(undefined4 *)(in_r1 + 0x10);
      ByteUtils::subrange(aBStack_70,(vector *)&local_5c,2,uVar14);
      FUN_00d28a58(auStack_64,&State::DONE,uVar15,aBStack_70);
      FUN_00d1aaa4(&local_40,auStack_64);
      FUN_00d1a378(auStack_64);
      FUN_00cb7f50(aBStack_70);
      iVar8 = 0;
    }
    FUN_00cb7f50(&local_5c);
    FUN_00d27d2c(local_50);
    FUN_00d1a378(&local_48);
    uVar14 = 0;
    if (iVar8 != 0) {
      if (iVar8 == 3) {
LAB_00d28782:
        *in_r0 = local_40;
        in_r0[1] = iStack_3c;
        in_r0[2] = local_38;
        local_38 = 0;
        local_40 = 0;
        iStack_3c = 0;
      }
LAB_00d28792:
      FUN_00d1a800(&local_40);
      FUN_00cb7f50(&local_34);
      if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
  } while( true );
}


