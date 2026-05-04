/* VagOperationDelegate::writeVagUdsValue @ 0127379c */


/* VagOperationDelegate::writeVagUdsValue(unsigned long long, std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&) */

void VagOperationDelegate::writeVagUdsValue(ulonglong param_1,vector *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 in_stack_00000000;
  undefined1 *puVar4;
  
  piVar3 = (int *)(param_1 >> 0x20);
  puVar4 = &stack0xfffffff8;
  uVar1 = (**(code **)(*piVar3 + 0x154))(piVar3);
  uVar2 = (**(code **)(*piVar3 + 0x158))(piVar3,*(code **)(*piVar3 + 0x158),param_2);
  (**(code **)(*piVar3 + 0x1c4))((int)param_1,piVar3,uVar1,uVar2,in_stack_00000000,puVar4);
  return;
}


