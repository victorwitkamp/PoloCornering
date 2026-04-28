/*
 * VagCanCommunicator_establishEcuComm
 * ELF symbol address: 0x00D1765C
 * Ghidra address: 0x00D2765C (ELF + 0x10000 image delta)
 * ELF symbol size: 1036 bytes
 * Symbol: _ZN18VagCanCommunicator16establishEcuCommEP3Ecu
 * Program: libCarista.so
 * Resolved function: VagCanCommunicator::establishEcuComm @ 00d2765c
 * Signature: undefined __thiscall establishEcuComm(VagCanCommunicator * this, Ecu * param_1)
 * Return type: undefined
 * Function body: [[00d2765c, 00d279bd]]
 * Parameters:
 *   [0] VagCanCommunicator * this
 *   [1] Ecu * param_1
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 0143da94
 * Direct callees/references:
 *   WRITE Stack[-0x74] from 00d27666
 *   READ 00d27a48 from 00d2766a
 *   READ 014da87c from 00d27670
 *   READ 015a7014 from 00d27672
 *   WRITE Stack[-0x28] from 00d27674
 *   READ 00d279f4 from 00d27676
 *   READ 014da9c0 from 00d2767a
 *   READ 014f1440 from 00d2767c
 *   UNCONDITIONAL_CALL DeviceLatestInfo::isDefective @ 013fb720 from 00d2767e
 *   CONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d27682
 *   UNCONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d27688
 *   READ 00d279f8 from 00d27694
 *   READ 014db3e0 from 00d27698
 *   READ 00c8f314 from 00d2769a
 *   CONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d2769e
 *   READ Stack[-0x50] from 00d276ae
 *   READ Stack[-0x48] from 00d276b2
 *   READ 00d279fc from 00d276ba
 *   PARAM 0082cff0 from 00d276bc
 *   UNCONDITIONAL_CALL Log::e @ 013fa760 from 00d276be
 *   UNCONDITIONAL_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 013fa600 from 00d276c4
 *   UNCONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d276cc
 *   READ Stack[-0x74] from 00d276ce
 *   UNCONDITIONAL_CALL Math::toExact<unsigned_short,int> @ 014007f0 from 00d276de
 *   WRITE Stack[-0x78] from 00d276e2
 *   WRITE Stack[-0x2f] from 00d276e8
 *   READ 00d27a44 from 00d276f0
 *   DATA 001000c0 from 00d276f4
 *   WRITE Stack[-0x33] from 00d276f4
 *   WRITE Stack[-0x34] from 00d276fc
 *   UNCONDITIONAL_CALL FUN_00cdb87c @ 00cdb87c from 00d27702
 *   CONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d27712
 *   WRITE Stack[-0x70] from 00d27718
 *   READ Stack[-0x78] from 00d27728
 *   CONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d27732
 *   WRITE Stack[-0x58] from 00d2773a
 *   WRITE Stack[-0x60] from 00d2773e
 *   CONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d27746
 *   UNCONDITIONAL_CALL Communicator::readResponses @ 01402cc0 from 00d2775a
 *   WRITE Stack[-0x44] from 00d27760
 *   UNCONDITIONAL_CALL FUN_00d1a6c4 @ 00d1a6c4 from 00d27768
 *   UNCONDITIONAL_CALL Communicator::filterByStatusInPlace @ 01402e40 from 00d27772
 *   UNCONDITIONAL_CALL FUN_00d1a7c8 @ 00d1a7c8 from 00d27778
 *   DATA Stack[-0x34] from 00d2777c
 *   CONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d27782
 *   UNCONDITIONAL_CALL VagCanCommunicator::parsePacket @ 01403cd0 from 00d2778e
 *   READ Stack[-0x6c] from 00d27792
 *   READ Stack[-0x6c] from 00d2779c
 *   CONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d2779e
 *   CONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d277a4
 *   CONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d277ac
 *   UNCONDITIONAL_CALL FUN_00d27cd4 @ 00d27cd4 from 00d277b2
 *   READ Stack[-0x6c] from 00d277b6
 *   CONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d277be
 *   READ Stack[-0x6c] from 00d277c0
 *   CONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d277c6
 *   UNCONDITIONAL_CALL FUN_00d27d2c @ 00d27d2c from 00d277ca
 *   UNCONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d277d0
 *   UNCONDITIONAL_CALL FUN_00d27cd4 @ 00d27cd4 from 00d277d6
 *   UNCONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d277da
 *   UNCONDITIONAL_CALL ThreadUtils::sleep @ 014037e0 from 00d277e0
 *   UNCONDITIONAL_CALL FUN_00d27d2c @ 00d27d2c from 00d277e6
 *   READ Stack[-0x58] from 00d277ea
 *   CONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d277ec
 *   UNCONDITIONAL_CALL FUN_00d1a800 @ 00d1a800 from 00d277f2
 *   UNCONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d277fa
 *   UNCONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d277fe
 *   READ Stack[-0x74] from 00d27800
 *   UNCONDITIONAL_CALL Communicator::trackEcuCommEstablish @ 01402c60 from 00d27806
 *   UNCONDITIONAL_CALL FUN_00d1a800 @ 00d1a800 from 00d2780e
 *   READ Stack[-0x58] from 00d2781c
 *   CONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d2781e
 *   READ Stack[-0x60] from 00d27820
 *   CONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d27822
 *   UNCONDITIONAL_CALL FUN_00d27cd4 @ 00d27cd4 from 00d27828
 *   READ Stack[-0x58] from 00d2782c
 *   UNCONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d2782e
 *   CONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d27832
 *   CONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d27862
 *   UNCONDITIONAL_CALL FUN_00cdb87c @ 00cdb87c from 00d27876
 *   READ 00d27a50 from 00d2787a
 *   PARAM 006d39a6 from 00d27880
 *   UNCONDITIONAL_CALL operator""__b @ 013fd3f0 from 00d27882
 *   UNCONDITIONAL_CALL operator+ @ 013fd470 from 00d2788c
 *   READ 00d27a54 from 00d2789e
 *   COMPUTED_CALL FUN_00cb7f50 @ 00cb7f50 from 00d278a4
 *   COMPUTED_CALL FUN_00cb7f50 @ 00cb7f50 from 00d278a8
 *   COMPUTED_CALL FUN_00cb7f50 @ 00cb7f50 from 00d278ac
 *   UNCONDITIONAL_CALL Communicator::readResponses @ 01402cc0 from 00d278b2
 *   WRITE Stack[-0x44] from 00d278b8
 *   UNCONDITIONAL_CALL FUN_00d1a6c4 @ 00d1a6c4 from 00d278c0
 *   UNCONDITIONAL_CALL Communicator::filterByStatusInPlace @ 01402e40 from 00d278c8
 *   UNCONDITIONAL_CALL FUN_00d1a7c8 @ 00d1a7c8 from 00d278ce
 *   READ Stack[-0x34] from 00d278d2
 *   CONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d278d8
 *   UNCONDITIONAL_CALL VagCanCommunicator::parsePacket @ 01403ce0 from 00d278e2
 *   READ Stack[-0x6c] from 00d278e6
 *   CONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d278ec
 *   UNCONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d278f4
 *   READ 00d27a58 from 00d278f6
 *   PARAM 0082d07d from 00d278f8
 *   UNCONDITIONAL_CALL Log::d @ 013fb5b0 from 00d278fa
 *   UNCONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d27900
 *   READ 00d27a60 from 00d27902
 *   PARAM 00926912 from 00d27904
 *   UNCONDITIONAL_CALL Log::d @ 013fb5b0 from 00d27906
 *   UNCONDITIONAL_CALL FUN_00d27d2c @ 00d27d2c from 00d2790e
 *   UNCONDITIONAL_CALL FUN_00d1a800 @ 00d1a800 from 00d27914
 *   CONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d2791a
 *   CONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d27920
 *   UNCONDITIONAL_CALL VagCanCommunicator::sendDisconnect @ 01403cf0 from 00d27924
 *   UNCONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d2792a
 *   UNCONDITIONAL_JUMP VagCanCommunicator::establishEcuComm @ 00d2765c from 00d2792e
 *   READ Stack[-0x74] from 00d27930
 *   READ Stack[-0x34] from 00d2793a
 *   READ Stack[-0x2c] from 00d2793e
 *   READ 00d27a5c from 00d27948
 *   PARAM 00ab2911 from 00d2794a
 *   UNCONDITIONAL_CALL Log::d @ 013fb5b0 from 00d2794c
 *   UNCONDITIONAL_CALL std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::~basic_string @ 013fa600 from 00d27952
 */

/* Ghidra function: VagCanCommunicator::establishEcuComm @ 00d2765c */

/* First instructions after recreation:
 * Memory bytes: f0b503af2de9000f95b001910546dff8dc037844006800681490df4878440068
 * 00d2765c: push {r4,r5,r6,r7,lr}
 * 00d2765e: add r7,sp,#0xc
 * 00d27660: push {r8,r9,r10,r11}
 * 00d27664: sub sp,#0x54
 * 00d27666: str r1,[sp,#0x4]
 * 00d27668: mov r5,r0
 * 00d2766a: ldr.w r0,[0x00d27a48]
 * 00d2766e: add r0,pc
 * 00d27670: ldr r0,[r0,#0x0]
 * 00d27672: ldr r0,[r0,#0x0]
 * 00d27674: str r0,[sp,#0x50]
 * 00d27676: ldr r0,[0x00d279f4]
 * 00d27678: add r0,pc
 * 00d2767a: ldr r0,[r0,#0x0]
 * 00d2767c: ldr r0,[r0,#0x0]
 * 00d2767e: blx 0x013fb720
 * 00d27682: cbz r0,0x00d2768a
 * 00d27684: mvn r4,#0x16
 * 00d27688: b 0x00d279a2
 * 00d2768a: ldr r0,[r5,#0x4]
 * 00d2768c: ldr r1,[r0,#0x0]
 * 00d2768e: ldr.w r1,[r1,#0x118]
 * 00d27692: blx r1
 * 00d27694: ldr r1,[0x00d279f8]
 */


/* VagCanCommunicator::establishEcuComm(Ecu*) */

void __thiscall VagCanCommunicator::establishEcuComm(VagCanCommunicator *this,Ecu *param_1)

{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  int *local_6c [3];
  int local_60;
  undefined4 uStack_5c;
  int local_58;
  undefined4 uStack_54;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> local_50;
  undefined1 auStack_4f [7];
  undefined1 *local_48;
  undefined4 local_44 [3];
  undefined2 uStack_36;
  undefined4 local_34;
  undefined1 uStack_30;
  undefined2 local_2f;
  undefined1 uStack_2d;
  int local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  iVar3 = DeviceLatestInfo::isDefective((DeviceLatestInfo *)App::DEVICE_LATEST_INFO);
  if (iVar3 == 0) {
    iVar3 = (**(code **)(**(int **)(this + 4) + 0x118))();
    if (iVar3 < 0x8c) {
      (**(code **)(**(int **)(this + 4) + 0x11c))(&local_50);
      if (((byte)local_50 & 1) == 0) {
        local_48 = auStack_4f;
      }
      Log::e("ELM327 version is too old (%s); aborting",local_48);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string(&local_50);
    }
    else {
      *(undefined2 *)(this + 0x29) = 0xf00;
      uVar2 = Math::toExact<unsigned_short,int>((byte)param_1[0x11] + 0x200);
      local_2f = 0x103;
      uStack_30 = 0;
      local_34 = (int *)CONCAT31(0x1000c0,param_1[0x11]);
      FUN_00cdb87c(&local_50,(vector *)&local_34,7);
      bVar1 = false;
      for (iVar3 = 0; iVar3 != 2; iVar3 = iVar3 + 1) {
        (**(code **)(**(int **)(this + 4) + 0x5c))(*(int **)(this + 4),0x40);
        iVar4 = (**(code **)(**(int **)(this + 4) + 0x6c))(*(int **)(this + 4),0x200,uVar2);
        if (iVar4 == -0x17) goto LAB_00d2799c;
        local_58 = 0;
        uStack_54 = 0;
        local_60 = 0;
        uStack_5c = 0;
        for (uVar9 = 0; uVar9 != 4; uVar9 = uVar9 + 1) {
          (**(code **)(**(int **)(this + 4) + 0x16c))(*(int **)(this + 4),&local_50,1);
          Communicator::readResponses();
          local_44[0] = 1;
          FUN_00d1a6c4((VagCanCommunicator *)local_6c,local_44,1);
          Communicator::filterByStatusInPlace((vector *)&local_34,(vector *)local_6c);
          FUN_00d1a7c8((VagCanCommunicator *)local_6c);
          piVar7 = (int *)CONCAT13(uStack_2d,CONCAT21(local_2f,uStack_30));
          for (piVar6 = local_34; piVar6 != piVar7; piVar6 = piVar6 + 2) {
            parsePacket((VagCanCommunicator *)local_6c,(basic_string *)(*piVar6 + 0xc),true);
            iVar4 = (**(code **)(*local_6c[0] + 8))();
            if ((iVar4 != 0) && (*(char *)((int)local_6c[0] + 10) == -0x30)) {
              FUN_00d27cd4(&local_58,(VagCanCommunicator *)local_6c);
LAB_00d277e4:
              FUN_00d27d2c((VagCanCommunicator *)local_6c);
              break;
            }
            iVar4 = (**(code **)(*local_6c[0] + 8))();
            if (iVar4 != 0) {
              FUN_00d27cd4(&local_60,(VagCanCommunicator *)local_6c);
            }
            iVar4 = (**(code **)(*local_6c[0] + 8))();
            if ((iVar4 != 0) && (*(char *)((int)local_6c[0] + 10) == -0x29)) {
              ThreadUtils::sleep(2000);
              goto LAB_00d277e4;
            }
            FUN_00d27d2c((VagCanCommunicator *)local_6c);
          }
          if (local_58 != 0) {
            Communicator::trackEcuCommEstablish((Communicator *)this,param_1,uVar9);
            FUN_00d1a800((vector *)&local_34);
            bVar1 = false;
            if (uVar9 < 4) {
              bVar1 = true;
            }
            goto LAB_00d2781c;
          }
          FUN_00d1a800((vector *)&local_34);
        }
        bVar1 = false;
LAB_00d2781c:
        if ((local_58 == 0) && (local_60 != 0)) {
          FUN_00d27cd4(&local_58,&local_60);
LAB_00d27834:
          pbVar5 = *(byte **)(local_58 + 0xc);
          (**(code **)(**(int **)(this + 4) + 0x6c))
                    (*(int **)(this + 4),(uint)pbVar5[2] | (pbVar5[3] & 0xf) << 8,
                     (uint)*pbVar5 | (pbVar5[1] & 0xf) << 8);
          bVar1 = false;
          iVar4 = 5;
          do {
            iVar4 = iVar4 + -1;
            if (iVar4 == 0) break;
            piVar7 = *(int **)(this + 4);
            uStack_36 = 0x1a0;
            FUN_00cdb87c((VagCanCommunicator *)local_6c,&uStack_36,2);
            operator____b((char *)local_44,0x6d39a6);
            operator+((vector *)&local_34,(vector *)local_6c);
            (**(code **)(*piVar7 + 0x16c))(piVar7,(vector *)&local_34,2);
            FUN_00cb7f50((vector *)&local_34);
            FUN_00cb7f50(local_44);
            FUN_00cb7f50((VagCanCommunicator *)local_6c);
            Communicator::readResponses();
            local_44[0] = 1;
            FUN_00d1a6c4((VagCanCommunicator *)local_6c,local_44,1);
            Communicator::filterByStatusInPlace((vector *)&local_34,(vector *)local_6c);
            FUN_00d1a7c8((VagCanCommunicator *)local_6c);
            if (local_34 == (int *)CONCAT13(uStack_2d,CONCAT21(local_2f,uStack_30))) {
              Log::d("Failed to get channel param response.");
              iVar8 = 0xc;
            }
            else {
              parsePacket((VagCanCommunicator *)local_6c,(basic_string *)(*local_34 + 0xc));
              if (*(char *)((int)local_6c[0] + 10) == -0x5f) {
                bVar1 = true;
                iVar8 = 10;
              }
              else {
                Log::d("Failed to get channel param response: %02X");
                iVar8 = 0xc;
              }
              FUN_00d27d2c((VagCanCommunicator *)local_6c);
            }
            FUN_00d1a800((vector *)&local_34);
          } while (iVar8 == 0xc);
          if (bVar1) {
            iVar4 = 2;
          }
          else {
            sendDisconnect(this);
            iVar4 = 0;
          }
        }
        else {
          if (bVar1) goto LAB_00d27834;
          (**(code **)(*(int *)param_1 + 0x10))((vector *)&local_34);
          iVar4 = local_2c;
          if (((uint)local_34 & 1) == 0) {
            iVar4 = (int)&local_34 + 1;
          }
          Log::d("Failed to open communication channel to ECU %s",iVar4);
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)&local_34);
          bVar1 = false;
          iVar4 = 1;
        }
        FUN_00d27d2c(&local_60);
        FUN_00d27d2c(&local_58);
        if (iVar4 != 0) {
          if (iVar4 != 2) goto LAB_00d2799c;
          break;
        }
      }
      if (bVar1) {
        this[0x28] = (VagCanCommunicator)0x1;
      }
      else {
        Log::e("Failed to get channel param response even after retrying.");
      }
LAB_00d2799c:
      FUN_00cb7f50(&local_50);
    }
  }
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_28);
}


