/* Target address 012e8890 */
/* Function insertValue @ 012e8890 */


/* ByteUtils::insertValue(std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> >
   const&, unsigned int, std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> >
   const&, std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> > const&) */

void __thiscall
ByteUtils::insertValue(ByteUtils *this,vector *param_1,uint param_2,vector *param_3,vector *param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  byte *pbVar6;
  IllegalArgumentException *this_00;
  undefined4 extraout_r1;
  uint uVar7;
  undefined8 uVar8;
  
  iVar4 = __stack_chk_guard;
  if ((uint)(*(int *)(param_1 + 4) - *(int *)param_1) <
      (*(int *)(param_3 + 4) + param_2) - *(int *)param_3) {
    this_00 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(&stack0xffffffcc,"ByteUtils::insertValue: bitmask doesn\'t fit within rawValue");
    IllegalArgumentException::IllegalArgumentException(this_00,(basic_string *)&stack0xffffffcc);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this_00,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  FUN_00cd5ef0(this,param_1,*(int *)(param_1 + 4),param_3,param_1,param_2);
  if ((uint)(*(int *)(param_4 + 4) - *(int *)param_4) < 9) {
    uVar8 = _ZN9ByteUtils7getLongERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE(param_4);
    uVar5 = getLsbOffset(param_3);
    FUN_013f47cc((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar5);
    getBytesFromLong(CONCAT44(extraout_r1,&stack0xffffffcc));
    for (uVar7 = 0; uVar7 < (uint)(*(int *)(param_3 + 4) - *(int *)param_3); uVar7 = uVar7 + 1) {
      pbVar6 = (byte *)FUN_00cdeb2c(param_1,param_2 + uVar7);
      bVar1 = *pbVar6;
      bVar3 = *(byte *)(*(int *)param_3 + uVar7);
      pbVar6 = (byte *)FUN_00cdfbb0(&stack0xffffffcc,
                                    (*(int *)param_3 - *(int *)(param_3 + 4)) + uVar7 + 8);
      bVar2 = *pbVar6;
      pbVar6 = (byte *)FUN_00cdfbb0(this,param_2 + uVar7);
      *pbVar6 = bVar1 & ~bVar3 | bVar2;
    }
    FUN_00cb7f50(&stack0xffffffcc);
  }
  else if (*(int *)(param_3 + 4) != *(int *)param_3) {
    __aeabi_memmove(*(int *)this + param_2,*(int *)param_4,*(int *)(param_3 + 4) - *(int *)param_3);
  }
  if (__stack_chk_guard != iVar4) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


