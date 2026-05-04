/* std::__ndk1::allocator<VagCanShortAdaptationSetting>::construct[abi:ne190000]<VagCanShortAdaptationSetting,VagCanEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,int,int,char_const(&)[39],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>> @ 010e83b8 */


/* void 
   std::__ndk1::allocator<VagCanShortAdaptationSetting>::construct[abi:ne190000]<VagCanShortAdaptationSetting,
   VagCanEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, int, int, int, char const (&) [39],
   std::__ndk1::shared_ptr<MultipleChoiceInterpretation> >(VagCanShortAdaptationSetting*,
   VagCanEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, int&&, int&&, int&&, char const (&)
   [39], std::__ndk1::shared_ptr<MultipleChoiceInterpretation>&&) */

void __thiscall
std::__ndk1::allocator<VagCanShortAdaptationSetting>::
construct_abi_ne190000_<VagCanShortAdaptationSetting,VagCanEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,int,int,char_const(&)[39],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>>
          (allocator<VagCanShortAdaptationSetting> *this,VagCanShortAdaptationSetting *param_1,
          VagCanEcu **param_2,shared_ptr *param_3,int *param_4,int *param_5,int *param_6,
          char *param_7,shared_ptr *param_8)

{
  int iVar1;
  VagCanEcu *pVVar2;
  int iVar3;
  int iVar4;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  
  local_1c = __stack_chk_guard;
  iVar3 = *param_6;
  iVar1 = *param_4;
  pVVar2 = *param_2;
  iVar4 = *param_5;
  local_24 = *(undefined4 *)param_8;
  uStack_20 = *(undefined4 *)(param_8 + 4);
  *(undefined4 *)param_8 = 0;
  *(undefined4 *)(param_8 + 4) = 0;
  VagCanShortAdaptationSetting::VagCanShortAdaptationSetting
            (param_1,pVVar2,param_3,(uchar)iVar1,iVar4,iVar3,param_7,(shared_ptr *)&local_24);
                    /* WARNING: Subroutine does not return */
  FUN_00cd2748(&local_24);
}


