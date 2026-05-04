/* std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>::construct[abi:ne190000]<FullByteVagCanShortAdaptationSetting,VagCanEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,char_const(&)[40],decltype(nullptr)> @ 012825fc */


/* void 
   std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>::construct[abi:ne190000]<FullByteVagCanShortAdaptationSetting,
   VagCanEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, int, char const (&) [40],
   decltype(nullptr)>(FullByteVagCanShortAdaptationSetting*, VagCanEcu*&,
   std::__ndk1::shared_ptr<StringWhitelist> const&, int&&, char const (&) [40], decltype(nullptr)&&)
    */

void std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>::
     construct_abi_ne190000_<FullByteVagCanShortAdaptationSetting,VagCanEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,char_const(&)[40],decltype(nullptr)>
               (FullByteVagCanShortAdaptationSetting *param_1,VagCanEcu **param_2,
               shared_ptr *param_3,int *param_4,char *param_5,_func_decltype_nullptr **param_6)

{
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  local_14 = __stack_chk_guard;
  local_1c = 0;
  uStack_18 = 0;
  FullByteVagCanShortAdaptationSetting::FullByteVagCanShortAdaptationSetting
            ((FullByteVagCanShortAdaptationSetting *)param_2,*(VagCanEcu **)param_3,
             (shared_ptr *)param_4,*param_5,(char *)param_6,(shared_ptr *)&local_1c);
                    /* WARNING: Subroutine does not return */
  FUN_00cd2748(&local_1c);
}


