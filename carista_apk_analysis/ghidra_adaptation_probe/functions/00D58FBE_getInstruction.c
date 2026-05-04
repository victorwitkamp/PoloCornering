/* Setting::getInstruction @ 00d58fbe */


/* Setting::getInstruction() const */

void Setting::getInstruction(void)

{
  bool bVar1;
  undefined4 *in_r0;
  int *piVar2;
  int in_r1;
  int iVar3;
  
  iVar3 = *(int *)(in_r1 + 0x50);
  *in_r0 = *(undefined4 *)(in_r1 + 0x4c);
  in_r0[1] = iVar3;
  if (iVar3 != 0) {
    piVar2 = (int *)(iVar3 + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  return;
}


