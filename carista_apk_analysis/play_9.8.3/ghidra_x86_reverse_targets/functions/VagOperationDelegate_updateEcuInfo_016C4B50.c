/* Target VagOperationDelegate_updateEcuInfo @ 016c4b50 (Ghidra 016d4b50) */
/* Size: 477 bytes */
/* Reason: updates cached VagEcuInfo from command results */
/* Function: _ZN20VagOperationDelegate13updateEcuInfoEP3EcuRK6ResultI10VagEcuInfovE @ 016c4b50 */

/* Symbols at target:
 * Function _ZN20VagOperationDelegate13updateEcuInfoEP3EcuRK6ResultI10VagEcuInfovE
 */


void _ZN20VagOperationDelegate13updateEcuInfoEP3EcuRK6ResultI10VagEcuInfovE
               (int *param_1,undefined4 **param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  undefined4 **ppuVar4;
  char cVar5;
  int **ppiVar6;
  int in_GS_OFFSET;
  bool bVar7;
  undefined1 *puStack_78;
  int *piStack_74;
  int *piStack_70;
  undefined4 **ppuStack_6c;
  int *piStack_68;
  undefined4 **ppuStack_64;
  undefined1 *puStack_60;
  byte bStack_4d;
  undefined4 auStack_4c [3];
  int *piStack_40;
  int *piStack_38;
  int *piStack_34;
  undefined1 uStack_25;
  undefined4 *puStack_24;
  undefined1 auStack_20 [8];
  int *piStack_18;
  int iStack_14;
  
  ppuVar4 = param_2;
  iStack_14 = *(int *)(in_GS_OFFSET + 0x14);
  ppuStack_6c = (undefined4 **)**(undefined4 **)(param_3 + 0x18);
  bStack_4d = 1;
  piStack_70 = (int *)0x16d4b88;
  cVar5 = func_0x0197ecf0();
  if (cVar5 == '\0') {
    bStack_4d = **(int **)(param_3 + 0x18) == 0;
  }
  ppuStack_64 = ppuVar4;
  piStack_68 = param_1;
  ppuStack_6c = (undefined4 **)auStack_4c;
  piStack_70 = (int *)0x16d4baf;
  (**(code **)(*param_1 + 0x1f8))();
  ppiVar6 = &piStack_70;
  piStack_70 = (int *)*piStack_34;
  piStack_74 = (int *)0x16d4bbf;
  cVar5 = func_0x01983900();
  bVar7 = true;
  if (cVar5 == '\0') {
    bVar7 = *piStack_34 == -5;
  }
  if ((**(int **)(param_3 + 0x18) == 1) || (bStack_4d = bStack_4d | bVar7, bStack_4d == 0)) {
    ppuStack_6c = ppuVar4;
    piStack_74 = (int *)0x16d4bf3;
    piStack_70 = (int *)auStack_20;
    (*(code *)(*ppuVar4)[4])();
    piStack_70 = piStack_18;
    if ((auStack_20._0_4_ & 1) == 0) {
      piStack_70 = (int *)(auStack_20 + 1);
    }
    ppuStack_6c = (undefined4 **)*piStack_34;
    piStack_68 = (int *)**(undefined4 **)(param_3 + 0x18);
    piStack_74 = (int *)&UNK_00a0dbe2;
    puStack_78 = (undefined1 *)0x16d4c2b;
    func_0x0197ec60();
    if ((auStack_20._0_4_ & 1) != 0) {
      piStack_74 = piStack_18;
      puStack_78 = &LAB_016d4c3c;
      func_0x0197e150();
    }
    piStack_70 = param_1 + 0x4b;
    ppuStack_6c = &param_2;
    puStack_60 = &uStack_25;
    ppuStack_64 = &puStack_24;
    piStack_68 = (int *)&UNK_00a64554;
    puStack_78 = (undefined1 *)0x16d4c70;
    piStack_74 = (int *)auStack_20;
    puStack_24 = ppuStack_6c;
    func_0x01993820();
    ppiVar6 = (int **)&puStack_78;
    puStack_78 = (undefined1 *)(auStack_20._0_4_ + 0xc);
    piStack_74 = (int *)param_3;
    func_0x01993830();
  }
  auStack_4c[0] = 0x1a1eab0;
  if (piStack_38 != (int *)0x0) {
    LOCK();
    piVar1 = piStack_38 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      iVar2 = *piStack_38;
      *ppiVar6 = piStack_38;
      pcVar3 = *(code **)(iVar2 + 8);
      ppiVar6[-1] = (int *)0x16d4cb1;
      (*pcVar3)();
      *ppiVar6 = piStack_38;
      ppiVar6[-1] = (int *)&LAB_016d4cb9;
      func_0x0197e1b0();
    }
  }
  if (piStack_40 != (int *)0x0) {
    LOCK();
    piVar1 = piStack_40 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      iVar2 = *piStack_40;
      *ppiVar6 = piStack_40;
      pcVar3 = *(code **)(iVar2 + 8);
      ppiVar6[-1] = (int *)0x16d4cd6;
      (*pcVar3)();
      *ppiVar6 = piStack_40;
      ppiVar6[-1] = (int *)&LAB_016d4cde;
      func_0x0197e1b0();
    }
  }
  if (*(int *)(in_GS_OFFSET + 0x14) != iStack_14) {
    ppiVar6[-1] = (int *)0x16d4d2d;
    func_0x0197e230();
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  return;
}



/* Entry instruction preview:
 * 016c4b50: PUSH EBP
 */
