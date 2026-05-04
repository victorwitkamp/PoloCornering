/* std::__ndk1::allocator<VagCanShortAdaptationSetting>::construct[abi:ne190000]<VagCanShortAdaptationSetting,VagCanEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,int,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,char_const(&)[43],std::__ndk1::shared_ptr<NumericalInterpretation>> @ 010cf130 */


/* void 
   std::__ndk1::allocator<VagCanShortAdaptationSetting>::construct[abi:ne190000]<VagCanShortAdaptationSetting,
   VagCanEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, int, int,
   std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> >, char const (&) [43],
   std::__ndk1::shared_ptr<NumericalInterpretation> >(VagCanShortAdaptationSetting*, VagCanEcu*&,
   std::__ndk1::shared_ptr<StringWhitelist> const&, int&&, int&&, std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> >&&, char const (&) [43],
   std::__ndk1::shared_ptr<NumericalInterpretation>&&) */

void __thiscall
std::__ndk1::allocator<VagCanShortAdaptationSetting>::
construct_abi_ne190000_<VagCanShortAdaptationSetting,VagCanEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,int,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,char_const(&)[43],std::__ndk1::shared_ptr<NumericalInterpretation>>
          (allocator<VagCanShortAdaptationSetting> *this,VagCanShortAdaptationSetting *param_1,
          VagCanEcu **param_2,shared_ptr *param_3,int *param_4,int *param_5,vector *param_6,
          char *param_7,shared_ptr *param_8)

{
  int iVar1;
  VagCanEcu *pVVar2;
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
  VagCanShortAdaptationSetting::VagCanShortAdaptationSetting
            (param_1,pVVar2,param_3,(uchar)iVar1,iVar3,param_6,param_7,(shared_ptr *)&local_24);
                    /* WARNING: Subroutine does not return */
  FUN_00cd2748(&local_24);
}


