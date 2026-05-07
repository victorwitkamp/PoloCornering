/* Target VagOperationDelegate_getVagSettingAvailabilityForSubmodule @ 016c97d0 (Ghidra 016d97d0) */
/* Size: 311 bytes */
/* Reason: recovered submodule availability helper that scans VagEcuInfo +0x10 */
/* Function: _ZN20VagOperationDelegate37getVagSettingAvailabilityForSubmoduleERKNSt6__ndk110shared_ptrI10VagSettingEERKNS1_I10VagEcuInfoEE @ 016c97d0 */

/* Symbols at target:
 * Function _ZN20VagOperationDelegate37getVagSettingAvailabilityForSubmoduleERKNSt6__ndk110shared_ptrI10VagSettingEERKNS1_I10VagEcuInfoEE
 */


/* WARNING: Removing unreachable block (ram,0x016d98e7) */

int _ZN20VagOperationDelegate37getVagSettingAvailabilityForSubmoduleERKNSt6__ndk110shared_ptrI10VagSettingEERKNS1_I10VagEcuInfoEE
              (undefined4 param_1,int *param_2,int *param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int in_GS_OFFSET;
  byte abStack_20 [8];
  undefined4 uStack_18;
  int iStack_14;
  
  iStack_14 = *(int *)(in_GS_OFFSET + 0x14);
  cVar4 = (**(code **)(*(int *)*param_2 + 0x3c))((int *)*param_2);
  if (cVar4 == '\0') {
    uVar6 = func_0x0197e1d0(8);
    func_0x00bbb1c0(abStack_20,&UNK_0093301c);
    func_0x0197e1e0(uVar6,abStack_20);
    if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
      uVar6 = func_0x0197e200(uVar6,&_ZTI24IllegalArgumentException,
                              _ZN29UnsupportedOperationExceptionD1Ev);
      if ((abStack_20[0] & 1) != 0) {
        func_0x0197e150(uStack_18);
      }
      if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
        func_0x0197a750(uVar6);
      }
    }
  }
  else {
    puVar1 = *(undefined4 **)(*param_3 + 0x10);
    iVar5 = 0;
    if (puVar1 != (undefined4 *)0x0) {
      piVar2 = (int *)puVar1[1];
      for (piVar7 = (int *)*puVar1; piVar7 != piVar2; piVar7 = piVar7 + 2) {
        if (((*piVar7 != 0) && (iVar5 = *(int *)(*piVar7 + 8), iVar5 != 0)) &&
           (iVar5 = (**(code **)(**(int **)(*param_2 + 0x54) + 0x10))
                              (*(int **)(*param_2 + 0x54),iVar5), iVar5 != 0)) goto LAB_016d9850;
      }
      iVar5 = 0;
    }
LAB_016d9850:
    if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
      return iVar5;
    }
  }
  func_0x0197e230();
  pcVar3 = (code *)swi(3);
  iVar5 = (*pcVar3)();
  return iVar5;
}



/* Entry instruction preview:
 * 016c97d0: PUSH EBP
 */
