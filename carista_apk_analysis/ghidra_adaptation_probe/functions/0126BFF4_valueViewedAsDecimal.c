/* VagOperationDelegate::valueViewedAsDecimal @ 0126bff4 */


/* VagOperationDelegate::valueViewedAsDecimal(unsigned long long) */

bool VagOperationDelegate::valueViewedAsDecimal(ulonglong param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(int *)param_1 + 0x15c))();
  return (uVar1 & 0xfd) == 0;
}


