/* std::__ndk1::allocator<VagCanShortAdaptationSetting>::construct[abi:ne190000]<VagCanShortAdaptationSetting,VagCanEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,int,int,char_const(&)[29],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_long_long,std::__ndk1::allocator<unsigned_long_long>>const>const&> @ 010bec3c */


/* void 
   std::__ndk1::allocator<VagCanShortAdaptationSetting>::construct[abi:ne190000]<VagCanShortAdaptationSetting,
   VagCanEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, int, int, int, char const (&) [29],
   std::__ndk1::shared_ptr<MultipleChoiceInterpretation>,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned long long, std::__ndk1::allocator<unsigned
   long long> > const> const&>(VagCanShortAdaptationSetting*, VagCanEcu*&,
   std::__ndk1::shared_ptr<StringWhitelist> const&, int&&, int&&, int&&, char const (&) [29],
   std::__ndk1::shared_ptr<MultipleChoiceInterpretation>&&,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned long long, std::__ndk1::allocator<unsigned
   long long> > const> const&) */

void __thiscall
std::__ndk1::allocator<VagCanShortAdaptationSetting>::
construct_abi_ne190000_<VagCanShortAdaptationSetting,VagCanEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,int,int,char_const(&)[29],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_long_long,std::__ndk1::allocator<unsigned_long_long>>const>const&>
          (allocator<VagCanShortAdaptationSetting> *this,VagCanShortAdaptationSetting *param_1,
          VagCanEcu **param_2,shared_ptr *param_3,int *param_4,int *param_5,int *param_6,
          char *param_7,shared_ptr *param_8,shared_ptr *param_9)

{
  int iVar1;
  int iVar2;
  VagCanEcu *pVVar3;
  int iVar4;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  
  local_1c = __stack_chk_guard;
  iVar1 = *param_6;
  iVar2 = *param_4;
  pVVar3 = *param_2;
  iVar4 = *param_5;
  local_24 = *(undefined4 *)param_8;
  uStack_20 = *(undefined4 *)(param_8 + 4);
  *(undefined4 *)param_8 = 0;
  *(undefined4 *)(param_8 + 4) = 0;
  VagCanShortAdaptationSetting::VagCanShortAdaptationSetting
            (param_1,pVVar3,param_3,(uchar)iVar2,iVar4,(uchar)iVar1,param_7,(shared_ptr *)&local_24,
             param_9);
                    /* WARNING: Subroutine does not return */
  FUN_00cd2748(&local_24);
}


