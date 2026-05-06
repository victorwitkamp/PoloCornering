/* Target address 012e83e8 */
/* Function getBytesFromLong @ 012e83e8 */


/* ByteUtils::getBytesFromLong(unsigned long long) */

void ByteUtils::getBytesFromLong(ulonglong param_1)

{
  int *piVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  
  piVar1 = (int *)FUN_00cbd800((int)param_1,8);
  *(char *)*piVar1 = (char)((uint)in_r3 >> 0x18);
  *(char *)(*piVar1 + 1) = (char)((uint)in_r3 >> 0x10);
  *(char *)(*piVar1 + 2) = (char)((uint)in_r3 >> 8);
  *(char *)(*piVar1 + 3) = (char)in_r3;
  *(char *)(*piVar1 + 4) = (char)((uint)in_r2 >> 0x18);
  *(char *)(*piVar1 + 5) = (char)((uint)in_r2 >> 0x10);
  *(char *)(*piVar1 + 6) = (char)((uint)in_r2 >> 8);
  *(char *)(*piVar1 + 7) = (char)in_r2;
  return;
}


