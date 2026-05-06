/* Target address 012e807c */
/* Function _ZN9ByteUtils7getLongERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE @ 012e807c */


/* WARNING: Removing unreachable block (ram,0x012e80c0) */

void _ZN9ByteUtils7getLongERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  IllegalArgumentException *this;
  uint uVar1;
  int *piStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_14 = __stack_chk_guard;
  uVar1 = param_1[1] - *param_1;
  if (8 < uVar1) {
    piStack_20 = param_1;
    uStack_1c = param_2;
    uStack_18 = param_3;
    this = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44((basic_string *)&piStack_20,"A long can fit a max of 8 bytes");
    IllegalArgumentException::IllegalArgumentException(this,(basic_string *)&piStack_20);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  for (; uVar1 != 0; uVar1 = uVar1 - 1) {
  }
  return;
}


