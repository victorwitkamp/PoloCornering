/* std::__ndk1::allocator<VagUdsAdaptationSetting>::construct[abi:ne190000]<VagUdsAdaptationSetting,VagUdsEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,int,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,char_const(&)[41],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>> @ 010d2864 */


/* void 
   std::__ndk1::allocator<VagUdsAdaptationSetting>::construct[abi:ne190000]<VagUdsAdaptationSetting,
   VagUdsEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, int, int,
   std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> >, char const (&) [41],
   std::__ndk1::shared_ptr<MultipleChoiceInterpretation> >(VagUdsAdaptationSetting*, VagUdsEcu*&,
   std::__ndk1::shared_ptr<StringWhitelist> const&, int&&, int&&, std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> >&&, char const (&) [41],
   std::__ndk1::shared_ptr<MultipleChoiceInterpretation>&&) */

void __thiscall
std::__ndk1::allocator<VagUdsAdaptationSetting>::
construct_abi_ne190000_<VagUdsAdaptationSetting,VagUdsEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,int,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,char_const(&)[41],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>>
          (allocator<VagUdsAdaptationSetting> *this,VagUdsAdaptationSetting *param_1,
          VagUdsEcu **param_2,shared_ptr *param_3,int *param_4,int *param_5,vector *param_6,
          char *param_7,shared_ptr *param_8)

{
  int iVar1;
  VagUdsEcu *pVVar2;
  int iVar3;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  
  local_1c = __stack_chk_guard;
  local_24 = *(undefined4 *)param_8;
  uStack_20 = *(undefined4 *)(param_8 + 4);
  iVar1 = *param_4;
  pVVar2 = *param_2;
  iVar3 = *param_5;
  *(undefined4 *)param_8 = 0;
  *(undefined4 *)(param_8 + 4) = 0;
  VagUdsAdaptationSetting::VagUdsAdaptationSetting
            (param_1,pVVar2,param_3,(short)iVar1,iVar3,param_6,param_7,&local_24,2);
                    /* WARNING: Subroutine does not return */
  FUN_00cd2748(&local_24);
}


