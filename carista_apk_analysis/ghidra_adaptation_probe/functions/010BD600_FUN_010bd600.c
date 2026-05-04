/* FUN_010bd600 @ 010bd600 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_010bd600(undefined4 *param_1,undefined4 param_2,shared_ptr *param_3,int *param_4,int *param_5,
            shared_ptr *param_6,char *param_7,shared_ptr *param_8,undefined4 param_9,
            undefined4 param_10,__shared_ptr_emplace *param_11,int param_12)

{
  bool bVar1;
  __shared_ptr_emplace *p_Var2;
  int *piVar3;
  shared_ptr<VagUdsAdaptationSetting> *unaff_r4;
  char in_CY;
  allocator<VagUdsAdaptationSetting> aStack_15;
  int local_14;
  
  if (in_CY != '\0') {
    FUN_014162a0();
    p_Var2 = param_11;
    param_11 = (__shared_ptr_emplace *)0x0;
    std::__ndk1::shared_ptr<VagUdsAdaptationSetting>::
    __create_with_control_block_abi_ne190000_<VagUdsAdaptationSetting,std::__ndk1::__shared_ptr_emplace<VagUdsAdaptationSetting,std::__ndk1::allocator<VagUdsAdaptationSetting>>>
              (unaff_r4,(VagUdsAdaptationSetting *)(p_Var2 + 0x10),p_Var2);
    FUN_010bd57c(&param_9);
    if (**(int **)(iRam010bd604 + 0x10bd5e4) == param_12) {
      return CONCAT44(**(int **)(iRam010bd604 + 0x10bd5e4),param_12);
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  if (((uint)param_1 & 0x80000000) == 0) {
    local_14 = __stack_chk_guard;
    param_1[2] = 0;
    *param_1 = &PTR____shared_ptr_emplace_014b4de4;
    param_1[1] = 0;
    std::__ndk1::allocator<VagUdsAdaptationSetting>::
    construct_abi_ne190000_<VagUdsAdaptationSetting,VagUdsEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,int,int,char_const(&)[27],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>const&>
              (&aStack_15,(VagUdsAdaptationSetting *)(param_1 + 4),(VagUdsEcu **)((int)param_1 << 1)
               ,param_3,param_4,param_5,(int *)param_6,param_7,param_8);
    if (__stack_chk_guard == local_14) {
      return CONCAT44(__stack_chk_guard,param_1);
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_14);
  }
  if (param_1 != (undefined4 *)0x0) {
    piVar3 = param_1 + 1;
    do {
      ExclusiveAccess(piVar3);
      bVar1 = (bool)hasExclusiveAccess(piVar3);
    } while (!bVar1);
    *piVar3 = *piVar3 + 1;
  }
  param_6 = param_3;
  param_7 = (char *)param_1;
  _ZNSt6__ndk18weak_ptrI7SettingEaSIS1_TnNS_9enable_ifIXsr17__compatible_withIT_S1_EE5valueEiE4typeELi0EEERS2_RKNS_10shared_ptrIS5_EE
            ((int)param_1 << 1,&param_6);
  FUN_00cc67b0(&param_6);
  if ((shared_ptr *)**(int **)(FUN_010bd572 + 0x10bd566) == param_8) {
    return CONCAT44(param_6,param_5);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


