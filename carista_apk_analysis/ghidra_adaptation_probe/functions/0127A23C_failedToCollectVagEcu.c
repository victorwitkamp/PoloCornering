/* VagOperationDelegate::failedToCollectVagEcu @ 0127a23c */


/* VagOperationDelegate::failedToCollectVagEcu(DebugData const&, VagEcu*) */

void __thiscall
VagOperationDelegate::failedToCollectVagEcu
          (VagOperationDelegate *this,DebugData *param_1,VagEcu *param_2)

{
  int iVar1;
  undefined4 uVar2;
  IllegalArgumentException *this_00;
  Ecu *pEVar3;
  basic_string abStack_40 [12];
  basic_string abStack_34 [12];
  basic_string abStack_28 [12];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  if ((*(int *)(param_2 + 0x14) == 0) || (*(int *)(param_2 + 0x18) == 0)) {
    this_00 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(abStack_28,
                 "failedToCollect must be given a VagEcu that has both CAN and UDS versions");
    IllegalArgumentException::IllegalArgumentException(this_00,abStack_28);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this_00,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  iVar1 = DebugData::contains((Ecu *)param_1);
  if ((iVar1 != 0) && (iVar1 = DebugData::contains((Ecu *)param_1), iVar1 != 0)) {
    pEVar3 = *(Ecu **)(param_2 + 0x14);
    FUN_00cb4d44(abStack_28,&DAT_00a54ba7);
    iVar1 = DebugData::containsPositiveResponse(param_1,pEVar3,abStack_28);
    if (iVar1 == 0) {
      pEVar3 = *(Ecu **)(param_2 + 0x14);
      FUN_00cb4d44(abStack_34,"22F187");
      iVar1 = DebugData::containsPositiveResponse(param_1,pEVar3,abStack_34);
      if (iVar1 == 0) {
        pEVar3 = *(Ecu **)(param_2 + 0x18);
        FUN_00cb4d44(abStack_40,"22F187");
        iVar1 = DebugData::containsPositiveResponse(param_1,pEVar3,abStack_40);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_40);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_34);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)abStack_28);
        if (iVar1 == 0) {
          uVar2 = 1;
          goto LAB_0127a2b4;
        }
        goto LAB_0127a2b2;
      }
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)abStack_34);
    }
    std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
    ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                  abStack_28);
  }
LAB_0127a2b2:
  uVar2 = 0;
LAB_0127a2b4:
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}


