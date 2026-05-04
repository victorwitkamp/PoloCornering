/* std::__ndk1::allocator<FullByteVagUdsAdaptationSetting>::construct[abi:ne190000]<FullByteVagUdsAdaptationSetting,VagUdsEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,short,char_const(&)[30],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>> @ 010fc854 */


/* void 
   std::__ndk1::allocator<FullByteVagUdsAdaptationSetting>::construct[abi:ne190000]<FullByteVagUdsAdaptationSetting,
   VagUdsEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, short, char const (&) [30],
   std::__ndk1::shared_ptr<MultipleChoiceInterpretation> >(FullByteVagUdsAdaptationSetting*,
   VagUdsEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, short&&, char const (&) [30],
   std::__ndk1::shared_ptr<MultipleChoiceInterpretation>&&) */

void __thiscall
std::__ndk1::allocator<FullByteVagUdsAdaptationSetting>::
construct_abi_ne190000_<FullByteVagUdsAdaptationSetting,VagUdsEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,short,char_const(&)[30],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>>
          (allocator<FullByteVagUdsAdaptationSetting> *this,FullByteVagUdsAdaptationSetting *param_1
          ,VagUdsEcu **param_2,shared_ptr *param_3,short *param_4,char *param_5,shared_ptr *param_6)

{
  short sVar1;
  VagUdsEcu *pVVar2;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  
  local_1c = __stack_chk_guard;
  sVar1 = *param_4;
  pVVar2 = *param_2;
  local_24 = *(undefined4 *)param_6;
  uStack_20 = *(undefined4 *)(param_6 + 4);
  *(undefined4 *)param_6 = 0;
  *(undefined4 *)(param_6 + 4) = 0;
  FullByteVagUdsAdaptationSetting::FullByteVagUdsAdaptationSetting
            (param_1,pVVar2,param_3,sVar1,param_5,&local_24,2);
                    /* WARNING: Subroutine does not return */
  FUN_00cd2748(&local_24);
}


