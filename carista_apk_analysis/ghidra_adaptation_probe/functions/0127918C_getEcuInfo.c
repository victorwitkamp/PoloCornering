/* VagOperationDelegate::getEcuInfo @ 0127918c */


/* VagOperationDelegate::getEcuInfo(Ecu*) */

void VagOperationDelegate::getEcuInfo(Ecu *param_1)

{
  int iVar1;
  uint uVar2;
  Result *pRVar3;
  int iVar4;
  Result<VagEcuInfo,void> *this;
  int in_r1;
  Ecu *in_r2;
  __hash_table<std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::__unordered_map_hasher<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,true>,std::__ndk1::__unordered_map_equal<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::hash<Ecu*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>>>
  *this_00;
  undefined4 local_70;
  Ecu *local_6c [6];
  int *local_54;
  Ecu *local_48;
  Ecu *local_44 [6];
  int *local_2c;
  Ecu *local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_20 = in_r2;
  if ((in_r2 == (Ecu *)0x0) || (iVar1 = __dynamic_cast(), iVar1 == 0)) {
    this_00 = (__hash_table<std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::__unordered_map_hasher<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,true>,std::__ndk1::__unordered_map_equal<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::hash<Ecu*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>>>
               *)(in_r1 + 300);
    uVar2 = std::__ndk1::
            __hash_table<std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::__unordered_map_hasher<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,true>,std::__ndk1::__unordered_map_equal<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::hash<Ecu*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>>>
            ::__count_unique<Ecu*>(this_00,&local_20);
    if (uVar2 != 0) {
      pRVar3 = (Result *)FUN_0127930c(this_00,&local_20);
      Result<VagEcuInfo,void>::Result((Result<VagEcuInfo,void> *)param_1,pRVar3);
      goto LAB_012792cc;
    }
    iVar1 = VagEcu::getEquivalent(local_20);
    local_44[0] = *(Ecu **)(iVar1 + 0x14);
    if (local_20 == local_44[0]) {
      local_44[0] = *(Ecu **)(iVar1 + 0x18);
    }
    uVar2 = std::__ndk1::
            __hash_table<std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::__unordered_map_hasher<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,true>,std::__ndk1::__unordered_map_equal<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::hash<Ecu*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>>>
            ::__count_unique<Ecu*>(this_00,local_44);
    if (uVar2 == 0) {
LAB_01279280:
      iVar1 = 0;
    }
    else {
      this = (Result<VagEcuInfo,void> *)FUN_0127930c(this_00,local_44);
      iVar1 = Result<VagEcuInfo,void>::isVehicleResponse(this);
      if (iVar1 == 0) goto LAB_01279280;
      iVar1 = -5;
    }
    Result<VagEcuInfo,void>::Result((Result<VagEcuInfo,void> *)param_1,iVar1);
    goto LAB_012792cc;
  }
  if (*(Ecu **)(iVar1 + 0x14) == (Ecu *)0x0) {
LAB_0127920c:
    Result<VagEcuInfo,void>::Result((Result<VagEcuInfo,void> *)local_44,0);
  }
  else {
    local_6c[0] = *(Ecu **)(iVar1 + 0x14);
    uVar2 = std::__ndk1::
            __hash_table<std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::__unordered_map_hasher<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,true>,std::__ndk1::__unordered_map_equal<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::hash<Ecu*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>>>
            ::__count_unique<Ecu*>
                      ((__hash_table<std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::__unordered_map_hasher<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,true>,std::__ndk1::__unordered_map_equal<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::hash<Ecu*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>>>
                        *)(in_r1 + 300),local_6c);
    if (uVar2 == 0) goto LAB_0127920c;
    local_48 = *(Ecu **)(iVar1 + 0x14);
    pRVar3 = (Result *)
             FUN_0127930c((__hash_table<std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::__unordered_map_hasher<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,true>,std::__ndk1::__unordered_map_equal<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::hash<Ecu*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>>>
                           *)(in_r1 + 300),&local_48);
    Result<VagEcuInfo,void>::Result((Result<VagEcuInfo,void> *)local_44,pRVar3);
  }
  iVar4 = Result<VagEcuInfo,void>::isVehicleResponse((Result<VagEcuInfo,void> *)local_44);
  if ((iVar4 == 0) && (*(Ecu **)(iVar1 + 0x18) != (Ecu *)0x0)) {
    local_48 = *(Ecu **)(iVar1 + 0x18);
    uVar2 = std::__ndk1::
            __hash_table<std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::__unordered_map_hasher<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,true>,std::__ndk1::__unordered_map_equal<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::hash<Ecu*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>>>
            ::__count_unique<Ecu*>
                      ((__hash_table<std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::__unordered_map_hasher<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,true>,std::__ndk1::__unordered_map_equal<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::hash<Ecu*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>>>
                        *)(in_r1 + 300),&local_48);
    if (uVar2 == 0) {
      Result<VagEcuInfo,void>::Result((Result<VagEcuInfo,void> *)local_6c,0);
    }
    else {
      local_70 = *(undefined4 *)(iVar1 + 0x18);
      pRVar3 = (Result *)
               FUN_0127930c((__hash_table<std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::__unordered_map_hasher<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,true>,std::__ndk1::__unordered_map_equal<Ecu*,std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::hash<Ecu*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<Ecu*,Result<VagEcuInfo,void>>>>
                             *)(in_r1 + 300),&local_70);
      Result<VagEcuInfo,void>::Result((Result<VagEcuInfo,void> *)local_6c,pRVar3);
    }
    iVar1 = Result<VagEcuInfo,void>::isVehicleResponse((Result<VagEcuInfo,void> *)local_6c);
    if (iVar1 == 0) {
      if ((*local_2c == -5) && (*local_54 == -5)) {
        pRVar3 = (Result *)local_44;
        goto LAB_0127929c;
      }
      Result<VagEcuInfo,void>::Result((Result<VagEcuInfo,void> *)param_1,0);
    }
    else {
      pRVar3 = (Result *)local_6c;
LAB_0127929c:
      Result<VagEcuInfo,void>::Result((Result<VagEcuInfo,void> *)param_1,pRVar3);
    }
    Result<VagEcuInfo,void>::~Result((Result<VagEcuInfo,void> *)local_6c);
  }
  else {
    Result<VagEcuInfo,void>::Result((Result<VagEcuInfo,void> *)param_1,(Result *)local_44);
  }
  Result<VagEcuInfo,void>::~Result((Result<VagEcuInfo,void> *)local_44);
LAB_012792cc:
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


