/* std::__ndk1::allocator<VagUdsAdaptationSetting>::construct[abi:ne190000]<VagUdsAdaptationSetting,VagUdsEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,int,int,char_const(&)[42],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>const&,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_long_long,std::__ndk1::allocator<unsigned_long_long>>const>const&> @ 010df130 */


/* void 
   std::__ndk1::allocator<VagUdsAdaptationSetting>::construct[abi:ne190000]<VagUdsAdaptationSetting,
   VagUdsEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, int, int, int, char const (&) [42],
   std::__ndk1::shared_ptr<MultipleChoiceInterpretation> const&,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned long long, std::__ndk1::allocator<unsigned
   long long> > const> const&>(VagUdsAdaptationSetting*, VagUdsEcu*&,
   std::__ndk1::shared_ptr<StringWhitelist> const&, int&&, int&&, int&&, char const (&) [42],
   std::__ndk1::shared_ptr<MultipleChoiceInterpretation> const&,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned long long, std::__ndk1::allocator<unsigned
   long long> > const> const&) */

void __thiscall
std::__ndk1::allocator<VagUdsAdaptationSetting>::
construct_abi_ne190000_<VagUdsAdaptationSetting,VagUdsEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,int,int,char_const(&)[42],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>const&,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_long_long,std::__ndk1::allocator<unsigned_long_long>>const>const&>
          (allocator<VagUdsAdaptationSetting> *this,VagUdsAdaptationSetting *param_1,
          VagUdsEcu **param_2,shared_ptr *param_3,int *param_4,int *param_5,int *param_6,
          char *param_7,shared_ptr *param_8,shared_ptr *param_9)

{
  bool bVar1;
  VagUdsEcu *pVVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_2c;
  int iStack_28;
  undefined4 local_24;
  
  local_24 = __stack_chk_guard;
  uVar4 = *param_6;
  iVar5 = *param_5;
  uVar6 = *param_4;
  pVVar2 = *param_2;
  local_2c = *(undefined4 *)param_8;
  iStack_28 = *(int *)(param_8 + 4);
  if (iStack_28 != 0) {
    piVar3 = (int *)(iStack_28 + 4);
    do {
      ExclusiveAccess(piVar3);
      bVar1 = (bool)hasExclusiveAccess(piVar3);
    } while (!bVar1);
    *piVar3 = *piVar3 + 1;
  }
  VagUdsAdaptationSetting::VagUdsAdaptationSetting
            (param_1,pVVar2,param_3,uVar6 & 0xffff,iVar5,uVar4 & 0xff,param_7,&local_2c,param_9,2);
                    /* WARNING: Subroutine does not return */
  FUN_00cd2748(&local_2c);
}


