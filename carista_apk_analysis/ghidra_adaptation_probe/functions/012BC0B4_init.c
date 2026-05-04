/* LiveDataOperation::init @ 012bc0b4 */


/* LiveDataOperation::init(std::__ndk1::shared_ptr<ReadValuesOperation> const&, bool) */

void __thiscall LiveDataOperation::init(LiveDataOperation *this,shared_ptr *param_1,bool param_2)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  IllegalStateException *this_00;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int local_40;
  int iStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  int local_30;
  int iStack_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  FUN_012bc228(this + 0x84,0,0);
  piVar6 = *(int **)(this + 0x7c);
  for (piVar5 = *(int **)(this + 0x78); piVar5 != piVar6; piVar5 = piVar5 + 2) {
    local_30 = *piVar5;
    iStack_2c = piVar5[1];
    piVar2 = *(int **)param_1;
    if (iStack_2c != 0) {
      piVar4 = (int *)(iStack_2c + 4);
      do {
        ExclusiveAccess(piVar4);
        bVar1 = (bool)hasExclusiveAccess(piVar4);
      } while (!bVar1);
      *piVar4 = *piVar4 + 1;
    }
    iVar3 = (**(code **)(*piVar2 + 0x94))(piVar2,&local_30);
    FUN_00cc67b0(&local_30);
    if (iVar3 != 0) {
      local_40 = *piVar5;
      iStack_3c = piVar5[1];
      if (iStack_3c != 0) {
        piVar2 = (int *)(iStack_3c + 4);
        do {
          ExclusiveAccess(piVar2);
          bVar1 = (bool)hasExclusiveAccess(piVar2);
        } while (!bVar1);
        *piVar2 = *piVar2 + 1;
      }
      local_38 = 0;
      uStack_34 = 0;
      FUN_012bc23a(this + 0x84,
                   (pair<std::__ndk1::shared_ptr<Setting>,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>>
                    *)&local_40);
      std::__ndk1::
      pair<std::__ndk1::shared_ptr<Setting>,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>>
      ::~pair((pair<std::__ndk1::shared_ptr<Setting>,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>>>
               *)&local_40);
    }
  }
  if ((*(int *)(this + 0x84) == *(int *)(this + 0x88)) && (param_2)) {
    this_00 = (IllegalStateException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(&local_40,
                 "None of this live data tool\'s parameters were available at availability check!");
    IllegalStateException::IllegalStateException(this_00,(basic_string *)&local_40);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this_00,&IllegalStateException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  (**(code **)(**(int **)param_1 + 0x14))(&local_40);
  iVar3 = local_40;
  FUN_00d5a8a2(&local_40);
  if (iVar3 != 0) {
    (**(code **)(**(int **)param_1 + 0x14))((shared_ptr *)&local_40);
    Operation::setDelegate((Operation *)this,(shared_ptr *)&local_40);
    FUN_00d5a8a2(&local_40);
  }
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 100) = 0;
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


