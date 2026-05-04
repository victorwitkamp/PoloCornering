/* std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>::construct[abi:ne190000]<FullByteVagCanShortAdaptationSetting,VagCanEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,char_const(&)[33],decltype(nullptr),Setting::Consistency> @ 01114124 */


/* void 
   std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>::construct[abi:ne190000]<FullByteVagCanShortAdaptationSetting,
   VagCanEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, int, char const (&) [33],
   decltype(nullptr), Setting::Consistency>(FullByteVagCanShortAdaptationSetting*, VagCanEcu*&,
   std::__ndk1::shared_ptr<StringWhitelist> const&, int&&, char const (&) [33], decltype(nullptr)&&,
   Setting::Consistency&&) */

void __thiscall
std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>::
construct_abi_ne190000_<FullByteVagCanShortAdaptationSetting,VagCanEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,char_const(&)[33],decltype(nullptr),Setting::Consistency>
          (allocator<FullByteVagCanShortAdaptationSetting> *this,
          FullByteVagCanShortAdaptationSetting *param_1,VagCanEcu **param_2,shared_ptr *param_3,
          int *param_4,char *param_5,_func_decltype_nullptr **param_6,Consistency *param_7)

{
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  local_14 = __stack_chk_guard;
  local_1c = 0;
  uStack_18 = 0;
  FullByteVagCanShortAdaptationSetting::FullByteVagCanShortAdaptationSetting
            (param_1,*param_2,param_3,(char)*param_4,param_5,&local_1c,*(undefined4 *)param_7);
                    /* WARNING: Subroutine does not return */
  FUN_00cd2748(&local_1c);
}


