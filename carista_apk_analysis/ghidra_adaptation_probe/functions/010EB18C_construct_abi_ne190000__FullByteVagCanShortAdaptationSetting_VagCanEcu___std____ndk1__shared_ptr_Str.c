/* std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>::construct[abi:ne190000]<FullByteVagCanShortAdaptationSetting,VagCanEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,char_const(&)[41],std::__ndk1::shared_ptr<NumericalInterpretation>,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_long_long,std::__ndk1::allocator<unsigned_long_long>>const>const&> @ 010eb18c */


/* void 
   std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>::construct[abi:ne190000]<FullByteVagCanShortAdaptationSetting,
   VagCanEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, int, char const (&) [41],
   std::__ndk1::shared_ptr<NumericalInterpretation>,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned long long, std::__ndk1::allocator<unsigned
   long long> > const> const&>(FullByteVagCanShortAdaptationSetting*, VagCanEcu*&,
   std::__ndk1::shared_ptr<StringWhitelist> const&, int&&, char const (&) [41],
   std::__ndk1::shared_ptr<NumericalInterpretation>&&,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned long long, std::__ndk1::allocator<unsigned
   long long> > const> const&) */

void __thiscall
std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>::
construct_abi_ne190000_<FullByteVagCanShortAdaptationSetting,VagCanEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,char_const(&)[41],std::__ndk1::shared_ptr<NumericalInterpretation>,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_long_long,std::__ndk1::allocator<unsigned_long_long>>const>const&>
          (allocator<FullByteVagCanShortAdaptationSetting> *this,
          FullByteVagCanShortAdaptationSetting *param_1,VagCanEcu **param_2,shared_ptr *param_3,
          int *param_4,char *param_5,shared_ptr *param_6,shared_ptr *param_7)

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
            (param_1,pVVar2,param_3,(uchar)iVar1,param_5,(shared_ptr *)&local_24,param_7);
                    /* WARNING: Subroutine does not return */
  FUN_00cd2748(&local_24);
}


