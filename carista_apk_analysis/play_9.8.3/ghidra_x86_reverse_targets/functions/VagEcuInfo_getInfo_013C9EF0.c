/* Target VagEcuInfo_getInfo @ 013c9ef0 (Ghidra 013d9ef0) */
/* Size: 794 bytes */
/* Reason: native VagEcuInfo::getInfo accessor for the value used by whitelist availability matching */
/* Function: _ZNK10VagEcuInfo7getInfoEv @ 013c9ef0 */

/* Symbols at target:
 * Function _ZNK10VagEcuInfo7getInfoEv
 */


undefined4 _ZNK10VagEcuInfo7getInfoEv(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  int *piVar4;
  undefined4 uVar5;
  int in_GS_OFFSET;
  uint uStack_64;
  undefined4 uStack_60;
  undefined4 *puStack_5c;
  undefined4 uStack_58;
  int *piStack_54;
  uint uStack_50;
  undefined4 uStack_4c;
  undefined4 *puStack_48;
  undefined4 uStack_44;
  int *piStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined4 *puStack_34;
  undefined4 uStack_30;
  int *piStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  undefined4 *puStack_20;
  undefined4 uStack_1c;
  int *piStack_18;
  int iStack_14;
  
  iStack_14 = *(int *)(in_GS_OFFSET + 0x14);
  puStack_5c = (undefined4 *)func_0x0197e0c0(0x18);
  uStack_64 = 0x19;
  uStack_60 = 0x15;
  *(undefined8 *)((int)puStack_5c + 0xd) = 0x7265626d756e5f74;
  *puStack_5c = 0x6c6c7566;
  puStack_5c[1] = 0x6163735f;
  puStack_5c[2] = 0x61705f6e;
  puStack_5c[3] = 0x6e5f7472;
  *(undefined1 *)((int)puStack_5c + 0x15) = 0;
  uStack_58 = *(undefined4 *)(param_2 + 8);
  piStack_54 = *(int **)(param_2 + 0xc);
  if (piStack_54 != (int *)0x0) {
    LOCK();
    piStack_54[1] = piStack_54[1] + 1;
    UNLOCK();
  }
  puStack_48 = (undefined4 *)func_0x0197e0c0(0x20);
  uStack_50 = 0x21;
  uStack_4c = 0x18;
  *(undefined8 *)(puStack_48 + 4) = 0x656d616e5f746e65;
  *puStack_48 = 0x6c6c7566;
  puStack_48[1] = 0x6163735f;
  puStack_48[2] = 0x6f635f6e;
  puStack_48[3] = 0x6e6f706d;
  *(undefined1 *)(puStack_48 + 6) = 0;
  uStack_44 = *(undefined4 *)(param_2 + 0x34);
  piStack_40 = *(int **)(param_2 + 0x38);
  if (piStack_40 != (int *)0x0) {
    LOCK();
    piStack_40[1] = piStack_40[1] + 1;
    UNLOCK();
  }
  puStack_34 = (undefined4 *)func_0x0197e0c0(0x18);
  uStack_3c = 0x19;
  uStack_38 = 0x14;
  *puStack_34 = 0x6c6c7566;
  puStack_34[1] = 0x6163735f;
  puStack_34[2] = 0x77735f6e;
  puStack_34[3] = 0x7265765f;
  puStack_34[4] = 0x6e6f6973;
  *(undefined1 *)(puStack_34 + 5) = 0;
  uStack_30 = *(undefined4 *)(param_2 + 0x3c);
  piStack_2c = *(int **)(param_2 + 0x40);
  if (piStack_2c != (int *)0x0) {
    LOCK();
    piStack_2c[1] = piStack_2c[1] + 1;
    UNLOCK();
  }
  puStack_20 = (undefined4 *)func_0x0197e0c0(0x18);
  uStack_28 = 0x19;
  uStack_24 = 0x16;
  *(undefined8 *)((int)puStack_20 + 0xe) = 0x746573617461645f;
  *puStack_20 = 0x6c6c7566;
  puStack_20[1] = 0x6163735f;
  puStack_20[2] = 0x73615f6e;
  puStack_20[3] = 0x645f6d61;
  *(undefined1 *)((int)puStack_20 + 0x16) = 0;
  uStack_1c = *(undefined4 *)(param_2 + 0x44);
  piStack_18 = *(int **)(param_2 + 0x48);
  if (piStack_18 != (int *)0x0) {
    LOCK();
    piStack_18[1] = piStack_18[1] + 1;
    UNLOCK();
  }
  func_0x00d0d760(param_1,CONCAT44(4,&uStack_64));
  piVar4 = piStack_18;
  if (piStack_18 != (int *)0x0) {
    LOCK();
    piVar1 = piStack_18 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piStack_18 + 8))(piStack_18);
      func_0x0197e1b0(piVar4);
    }
  }
  if ((uStack_28 & 1) != 0) {
    func_0x0197e150(puStack_20);
  }
  piVar4 = piStack_2c;
  if (piStack_2c != (int *)0x0) {
    LOCK();
    piVar1 = piStack_2c + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piStack_2c + 8))(piStack_2c);
      func_0x0197e1b0(piVar4);
    }
  }
  if ((uStack_3c & 1) != 0) {
    func_0x0197e150(puStack_34);
  }
  piVar4 = piStack_40;
  if (piStack_40 != (int *)0x0) {
    LOCK();
    piVar1 = piStack_40 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piStack_40 + 8))(piStack_40);
      func_0x0197e1b0(piVar4);
    }
  }
  if ((uStack_50 & 1) != 0) {
    func_0x0197e150(puStack_48);
  }
  piVar4 = piStack_54;
  if (piStack_54 != (int *)0x0) {
    LOCK();
    piVar1 = piStack_54 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*piStack_54 + 8))(piStack_54);
      func_0x0197e1b0(piVar4);
    }
  }
  if ((uStack_64 & 1) != 0) {
    func_0x0197e150(puStack_5c);
  }
  if (*(int *)(in_GS_OFFSET + 0x14) != iStack_14) {
    func_0x0197e230();
    pcVar3 = (code *)swi(3);
    uVar5 = (*pcVar3)();
    return uVar5;
  }
  return param_1;
}



/* Entry instruction preview:
 * 013c9ef0: PUSH EBP
 */
