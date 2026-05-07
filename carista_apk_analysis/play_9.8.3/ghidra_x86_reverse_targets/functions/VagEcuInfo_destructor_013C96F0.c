/* Target VagEcuInfo_destructor @ 013c96f0 (Ghidra 013d96f0) */
/* Size: 458 bytes */
/* Reason: VagEcuInfo destructor, useful for field/refcount layout */
/* Function: _ZN10VagEcuInfoD2Ev @ 013c96f0 */

/* Symbols at target:
 * Function _ZN10VagEcuInfoD2Ev
 * Label _ZN10VagEcuInfoD1Ev
 */


void _ZN10VagEcuInfoD2Ev(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  *param_1 = 0x1a199fc;
  piVar3 = (int *)param_1[0x18];
  if (piVar3 != (int *)0x0) {
    LOCK();
    piVar1 = piVar3 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      func_0x0197e1b0(piVar3);
    }
  }
  piVar3 = (int *)param_1[0x16];
  if (piVar3 != (int *)0x0) {
    LOCK();
    piVar1 = piVar3 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      func_0x0197e1b0(piVar3);
    }
  }
  piVar3 = (int *)param_1[0x14];
  if (piVar3 != (int *)0x0) {
    LOCK();
    piVar1 = piVar3 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      func_0x0197e1b0(piVar3);
    }
  }
  piVar3 = (int *)param_1[0x12];
  if (piVar3 != (int *)0x0) {
    LOCK();
    piVar1 = piVar3 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      func_0x0197e1b0(piVar3);
    }
  }
  piVar3 = (int *)param_1[0x10];
  if (piVar3 != (int *)0x0) {
    LOCK();
    piVar1 = piVar3 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      func_0x0197e1b0(piVar3);
    }
  }
  piVar3 = (int *)param_1[0xe];
  if (piVar3 != (int *)0x0) {
    LOCK();
    piVar1 = piVar3 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      func_0x0197e1b0(piVar3);
    }
  }
  piVar3 = (int *)param_1[0xc];
  if (piVar3 != (int *)0x0) {
    LOCK();
    piVar1 = piVar3 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      func_0x0197e1b0(piVar3);
    }
  }
  piVar3 = (int *)param_1[10];
  if (piVar3 != (int *)0x0) {
    LOCK();
    piVar1 = piVar3 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      func_0x0197e1b0(piVar3);
    }
  }
  piVar3 = (int *)param_1[7];
  if (piVar3 != (int *)0x0) {
    LOCK();
    piVar1 = piVar3 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      func_0x0197e1b0(piVar3);
    }
  }
  piVar3 = (int *)param_1[5];
  if (piVar3 != (int *)0x0) {
    LOCK();
    piVar1 = piVar3 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      func_0x0197e1b0(piVar3);
    }
  }
  piVar3 = (int *)param_1[3];
  if (piVar3 != (int *)0x0) {
    LOCK();
    piVar1 = piVar3 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      func_0x0197e1b0(piVar3);
    }
  }
  func_0x01984df0(param_1);
  return;
}



/* Entry instruction preview:
 * 013c96f0: PUSH EBP
 */
