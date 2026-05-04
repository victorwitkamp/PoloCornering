/* std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>::construct[abi:ne190000]<FullByteVagCanShortAdaptationSetting,VagCanEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,char_const(&)[29],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>> @ 010d30f4 */


/* void 
   std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>::construct[abi:ne190000]<FullByteVagCanShortAdaptationSetting,
   VagCanEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, int, char const (&) [29],
   std::__ndk1::shared_ptr<MultipleChoiceInterpretation> >(FullByteVagCanShortAdaptationSetting*,
   VagCanEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, int&&, char const (&) [29],
   std::__ndk1::shared_ptr<MultipleChoiceInterpretation>&&) */

void __thiscall
std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>::
construct_abi_ne190000_<FullByteVagCanShortAdaptationSetting,VagCanEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,char_const(&)[29],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>>
          (allocator<FullByteVagCanShortAdaptationSetting> *this,
          FullByteVagCanShortAdaptationSetting *param_1,VagCanEcu **param_2,shared_ptr *param_3,
          int *param_4,char *param_5,shared_ptr *param_6)

{
  int iVar1;
  VagCanEcu *pVVar2;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  
  local_1c = __stack_chk_guard;
  iVar1 = *param_4;
  pVVar2 = *param_2;
  local_24 = *(undefined4 *)param_6;
  uStack_20 = *(undefined4 *)(param_6 + 4);
  *(undefined4 *)param_6 = 0;
  *(undefined4 *)(param_6 + 4) = 0;
  FullByteVagCanShortAdaptationSetting::FullByteVagCanShortAdaptationSetting
            (param_1,pVVar2,param_3,(uchar)iVar1,param_5,(shared_ptr *)&local_24);
                    /* WARNING: Subroutine does not return */
  FUN_00cd2748(&local_24);
}


