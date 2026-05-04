/* OperationDelegate::putCachedRawValue @ 01241534 */


/* OperationDelegate::putCachedRawValue(std::__ndk1::shared_ptr<Setting> const&,
   std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> > const&) */

void __thiscall
OperationDelegate::putCachedRawValue(OperationDelegate *this,shared_ptr *param_1,vector *param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar2 = (**(code **)(*(int *)this + 0x148))(this);
  uVar1 = (undefined4)((ulonglong)uVar2 >> 0x20);
  (**(code **)(*(int *)this + 0xac))(this,uVar1,(int)uVar2,uVar1,param_2);
  return;
}


