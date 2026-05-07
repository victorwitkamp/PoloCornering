/* Target VagOperationDelegate_readVagUdsSubmoduleValue @ 016b9dc0 (Ghidra 016c9dc0) */
/* Size: 421 bytes */
/* Reason: raw read path for UDS submodule settings */
/* Function: _ZN20VagOperationDelegate24readVagUdsSubmoduleValueEyt @ 016b9dc0 */

/* Symbols at target:
 * Function _ZN20VagOperationDelegate24readVagUdsSubmoduleValueEyt
 */


undefined4
_ZN20VagOperationDelegate24readVagUdsSubmoduleValueEyt
          (undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined2 param_5)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_GS_OFFSET;
  undefined1 auStack_2c [4];
  int *piStack_28;
  undefined4 uStack_24;
  int *piStack_20;
  int *piStack_1c;
  int *piStack_18;
  int iStack_14;
  
  iStack_14 = *(int *)(in_GS_OFFSET + 0x14);
  uVar4 = (**(code **)(*param_2 + 0x154))(param_2,param_3,param_4);
  piVar5 = (int *)func_0x0197e0c0(0x20);
  piVar5[1] = 0;
  piVar5[2] = 0;
  *piVar5 = 0x1a1b53c;
  func_0x01981870(piVar5 + 3,uVar4,param_5);
  uStack_24 = 0;
  piStack_20 = (int *)0x0;
  piStack_1c = piVar5 + 3;
  piStack_18 = piVar5;
  func_0x019909b0(auStack_2c);
  func_0x01990c40(param_1,param_2,&piStack_1c,auStack_2c);
  if (piStack_28 != (int *)0x0) {
    LOCK();
    piVar5 = piStack_28 + 1;
    iVar2 = *piVar5;
    *piVar5 = *piVar5 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piStack_28 + 8))(piStack_28);
      func_0x0197e1b0(piStack_28);
    }
  }
  piVar5 = piStack_18;
  if (piStack_18 != (int *)0x0) {
    LOCK();
    piVar1 = piStack_18 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piStack_18 + 8))(piStack_18);
      func_0x0197e1b0(piVar5);
    }
  }
  piVar5 = piStack_20;
  if (piStack_20 != (int *)0x0) {
    LOCK();
    piVar1 = piStack_20 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piStack_20 + 8))(piStack_20);
      func_0x0197e1b0(piVar5);
    }
  }
  if (*(int *)(in_GS_OFFSET + 0x14) == iStack_14) {
    return param_1;
  }
  func_0x0197e230();
  pcVar3 = (code *)swi(3);
  uVar4 = (*pcVar3)();
  return uVar4;
}



/* Entry instruction preview:
 * 016b9dc0: PUSH EBP
 */
