/* OperationDelegate::getRawAddress @ 012427d4 */


/* OperationDelegate::getRawAddress(unsigned char, Ecu*, unsigned short) */

ulonglong __thiscall
OperationDelegate::getRawAddress(OperationDelegate *this,uchar param_1,Ecu *param_2,ushort param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)param_2 + 0xc))(param_2);
  return (ulonglong)CONCAT14(param_1,(uint)param_3 | iVar1 << 0x10);
}


