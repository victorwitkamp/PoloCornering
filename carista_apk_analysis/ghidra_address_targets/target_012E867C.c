/* Target address 012e867c */
/* Function extractValue @ 012e867c */


/* ByteUtils::extractValue(std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char>
   > const&, unsigned int, std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char>
   > const&) */

void __thiscall
ByteUtils::extractValue(ByteUtils *this,vector *param_1,uint param_2,vector *param_3)

{
  int iVar1;
  byte *pbVar2;
  undefined4 uVar3;
  IllegalArgumentException *this_00;
  undefined4 extraout_r1;
  uint uVar4;
  int unaff_r4;
  int unaff_r5;
  undefined8 uVar5;
  vector *pvStack_3c;
  uint uStack_38;
  vector *pvStack_34;
  
  iVar1 = __stack_chk_guard;
  uVar4 = *(int *)(param_3 + 4) - *(int *)param_3;
  pvStack_3c = param_1;
  uStack_38 = param_2;
  pvStack_34 = param_3;
  if ((uint)(*(int *)(param_1 + 4) - *(int *)param_1) < uVar4 + param_2) {
    this_00 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(&stack0xffffffd0,"ByteUtils::extractValue: bitmask doesn\'t fit within rawValue");
    IllegalArgumentException::IllegalArgumentException(this_00,(basic_string *)&stack0xffffffd0);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this_00,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  if (uVar4 < 9) {
    FUN_00cd5ef0(&stack0xffffffd0,param_3,*(int *)(param_1 + 4),uVar4,this);
    for (uVar4 = 0; uVar4 < (uint)(unaff_r5 - unaff_r4); uVar4 = uVar4 + 1) {
      pbVar2 = (byte *)FUN_00cdeb2c(param_1,param_2 + uVar4);
      *(byte *)(unaff_r4 + uVar4) = *pbVar2 & *(byte *)(unaff_r4 + uVar4);
    }
    uVar5 = _ZN9ByteUtils7getLongERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE(&stack0xffffffd0);
    uVar3 = getLsbOffset(param_3);
    FUN_013f49c0((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),uVar3);
    getBytesFromLong(CONCAT44(extraout_r1,&pvStack_3c));
    ContainerUtils::subrange<unsigned_char>
              ((ContainerUtils *)this,(vector *)&pvStack_3c,
               (*(int *)param_3 - *(int *)(param_3 + 4)) + 8,0xffffffff);
    FUN_00cb7f50(&pvStack_3c);
    FUN_00cb7f50(&stack0xffffffd0);
  }
  else {
    ContainerUtils::subrange<unsigned_char>((ContainerUtils *)this,param_1,param_2,uVar4);
  }
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


