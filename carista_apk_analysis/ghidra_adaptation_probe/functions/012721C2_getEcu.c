/* VagOperationDelegate::getEcu @ 012721c2 */


/* VagOperationDelegate::getEcu(unsigned long long) */

void VagOperationDelegate::getEcu(ulonglong param_1)

{
  int iVar1;
  uint in_r2;
  
  iVar1 = VagCanEcu::containsId((ushort)(in_r2 >> 0x10));
  if (iVar1 != 0) {
    (*(code *)&LAB_01415af0)(in_r2 >> 0x10);
    return;
  }
  (*(code *)&LAB_0141d7a0)(in_r2 >> 0x10);
  return;
}


