/* VagOperationDelegate::mergeMk8EcuList @ 01278f3c */


/* VagOperationDelegate::mergeMk8EcuList(BroadcastCommandResult<EcuListModel> const&) */

void VagOperationDelegate::mergeMk8EcuList(BroadcastCommandResult *param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  IllegalStateException *this;
  undefined4 uVar6;
  Result<std::__ndk1::unordered_map<Ecu*,Result<EcuListModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<EcuListModel,void>>>>,void>
  *in_r2;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int local_74;
  undefined4 local_70;
  int iStack_6c;
  basic_string abStack_68 [12];
  Result<EcuListModel,void> aRStack_5c [24];
  int *local_44;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  iVar2 = Result<std::__ndk1::unordered_map<Ecu*,Result<EcuListModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<EcuListModel,void>>>>,void>
          ::isFail(in_r2);
  if (iVar2 == 0) {
    local_30 = 0;
    local_38 = 0;
    uStack_34 = 0;
    puVar3 = (undefined4 *)VagUdsEcu::values();
    puVar7 = (undefined4 *)*puVar3;
    puVar3 = (undefined4 *)puVar3[1];
    local_74 = -6;
    for (; puVar7 != puVar3; puVar7 = puVar7 + 1) {
      (**(code **)(*(int *)in_r2 + 8))(aRStack_5c,in_r2,*puVar7);
      iVar2 = Result<EcuListModel,void>::isFail(aRStack_5c);
      if (iVar2 == 0) {
        puVar4 = (undefined4 *)EcuList::getEntries();
        puVar8 = (undefined4 *)puVar4[1];
        for (puVar4 = (undefined4 *)*puVar4; puVar4 != puVar8; puVar4 = puVar4 + 4) {
          if (*(char *)(puVar4 + 1) == '\0') {
            this = (IllegalStateException *)__cxa_allocate_exception(8);
            FUN_00cb4d44(abStack_68,"Entries should be confirmed!");
            IllegalStateException::IllegalStateException(this,abStack_68);
                    /* WARNING: Subroutine does not return */
            __cxa_throw(this,&IllegalStateException::typeinfo,
                        IllegalStateException::~IllegalStateException);
          }
          uVar6 = *puVar4;
          local_70 = puVar4[2];
          iStack_6c = puVar4[3];
          if (iStack_6c != 0) {
            piVar5 = (int *)(iStack_6c + 4);
            do {
              ExclusiveAccess(piVar5);
              bVar1 = (bool)hasExclusiveAccess(piVar5);
            } while (!bVar1);
            *piVar5 = *piVar5 + 1;
          }
          EcuList::addConfirmedEntry((EcuList *)&local_38,uVar6,&local_70);
          FUN_00ce456a(&local_70);
        }
      }
      else {
        local_74 = *local_44;
      }
      Result<EcuListModel,void>::~Result(aRStack_5c);
    }
    iVar2 = EcuList::empty((EcuList *)&local_38);
    if (iVar2 == 0) {
      FUN_00ce4398(aRStack_5c,&local_38);
      Result<EcuListModel,void>::done((Result<EcuListModel,void> *)param_1,(shared_ptr *)aRStack_5c)
      ;
      FUN_00ce43cc(aRStack_5c);
    }
    else {
      Result<EcuListModel,void>::Result((Result<EcuListModel,void> *)param_1,local_74);
    }
    FUN_00ce44e8(&local_38);
  }
  else {
    Result<EcuListModel,void>::Result((Result<EcuListModel,void> *)param_1,**(int **)(in_r2 + 0x18))
    ;
  }
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


