/* Target MultiResponseCommand_VagEcuInfoWithCoding_processResponses @ 00c39e60 (Ghidra 00c49e60) */
/* Size: 297 bytes */
/* Reason: generic multi-response command wrapper used by GetVagCanEcuInfoCommand */
/* Function: _ZNK20MultiResponseCommandI20VagEcuInfoWithCodingE16processResponsesERKNSt6__ndk16vectorINS3_IhNS2_9allocatorIhEEEENS4_IS6_EEEE @ 00c39e60 */

/* Symbols at target:
 * Function _ZNK20MultiResponseCommandI20VagEcuInfoWithCodingE16processResponsesERKNSt6__ndk16vectorINS3_IhNS2_9allocatorIhEEEENS4_IS6_EEEE
 */


undefined4 *
_ZNK20MultiResponseCommandI20VagEcuInfoWithCodingE16processResponsesERKNSt6__ndk16vectorINS3_IhNS2_9allocatorIhEEEENS4_IS6_EEEE
          (undefined4 *param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  char cVar5;
  undefined4 *puVar6;
  undefined4 **ppuVar7;
  int in_GS_OFFSET;
  undefined4 uStack_54;
  undefined4 *puStack_50;
  int *piStack_4c;
  int *piStack_48;
  undefined4 uStack_44;
  int aiStack_38 [3];
  int *piStack_2c;
  int *piStack_24;
  undefined4 *puStack_20;
  int *piStack_1c;
  int iStack_14;
  
  iStack_14 = *(int *)(in_GS_OFFSET + 0x14);
  uStack_44 = param_3;
  piStack_48 = param_2;
  piStack_4c = aiStack_38;
  puStack_50 = (undefined4 *)0xc49e98;
  (**(code **)(*param_2 + 0xc))();
  ppuVar7 = &puStack_50;
  puStack_50 = (undefined4 *)*puStack_20;
  uStack_54 = 0xc49ea8;
  cVar5 = func_0x0197e390();
  if (cVar5 == '\0') {
    piStack_48 = (int *)*piStack_1c;
    piStack_4c = param_2;
    puStack_50 = param_1;
    uStack_54 = 0xc49ef4;
    (**(code **)(*param_2 + 0x18))();
    ppuVar7 = (undefined4 **)&uStack_54;
  }
  else {
    uVar3 = *puStack_20;
    *param_1 = 0x19a08d0;
    param_1[1] = uVar3;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = param_1 + 1;
    param_1[7] = param_1 + 2;
    param_1[8] = param_1 + 4;
  }
  aiStack_38[0] = 0x199dc10;
  if (piStack_24 != (int *)0x0) {
    LOCK();
    piVar1 = piStack_24 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      iVar2 = *piStack_24;
      *ppuVar7 = piStack_24;
      pcVar4 = *(code **)(iVar2 + 8);
      ppuVar7[-1] = (undefined4 *)0xc49f20;
      (*pcVar4)();
      *ppuVar7 = piStack_24;
      ppuVar7[-1] = (undefined4 *)&LAB_00c49f28;
      func_0x0197e1b0();
    }
  }
  if (piStack_2c != (int *)0x0) {
    LOCK();
    piVar1 = piStack_2c + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      iVar2 = *piStack_2c;
      *ppuVar7 = piStack_2c;
      pcVar4 = *(code **)(iVar2 + 8);
      ppuVar7[-1] = (undefined4 *)0xc49f45;
      (*pcVar4)();
      *ppuVar7 = piStack_2c;
      ppuVar7[-1] = (undefined4 *)&LAB_00c49f4d;
      func_0x0197e1b0();
    }
  }
  if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
    return param_1;
  }
  ppuVar7[-1] = (undefined4 *)0xc49f89;
  func_0x0197e230();
  pcVar4 = (code *)swi(3);
  puVar6 = (undefined4 *)(*pcVar4)();
  return puVar6;
}



/* Entry instruction preview:
 * 00c39e60: PUSH EBP
 */
