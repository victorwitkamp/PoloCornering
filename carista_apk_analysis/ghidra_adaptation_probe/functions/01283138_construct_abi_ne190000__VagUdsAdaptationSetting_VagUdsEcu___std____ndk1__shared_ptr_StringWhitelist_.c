/* std::__ndk1::allocator<VagUdsAdaptationSetting>::construct[abi:ne190000]<VagUdsAdaptationSetting,VagUdsEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,short,int,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,char_const(&)[41],decltype(nullptr)> @ 01283138 */


/* void 
   std::__ndk1::allocator<VagUdsAdaptationSetting>::construct[abi:ne190000]<VagUdsAdaptationSetting,
   VagUdsEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, short, int,
   std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> >, char const (&) [41],
   decltype(nullptr)>(VagUdsAdaptationSetting*, VagUdsEcu*&,
   std::__ndk1::shared_ptr<StringWhitelist> const&, short&&, int&&, std::__ndk1::vector<unsigned
   char, std::__ndk1::allocator<unsigned char> >&&, char const (&) [41], decltype(nullptr)&&) */

void std::__ndk1::allocator<VagUdsAdaptationSetting>::
     construct_abi_ne190000_<VagUdsAdaptationSetting,VagUdsEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,short,int,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>,char_const(&)[41],decltype(nullptr)>
               (VagUdsAdaptationSetting *param_1,VagUdsEcu **param_2,shared_ptr *param_3,
               short *param_4,int *param_5,vector *param_6,char *param_7,
               _func_decltype_nullptr **param_8)

{
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  local_14 = __stack_chk_guard;
  local_1c = 0;
  uStack_18 = 0;
  VagUdsAdaptationSetting::VagUdsAdaptationSetting
            ((VagUdsAdaptationSetting *)param_2,*(undefined4 *)param_3,param_4,(short)*param_5,
             *(undefined4 *)param_6,param_7,param_8,&local_1c,2);
                    /* WARNING: Subroutine does not return */
  FUN_00cd2748(&local_1c);
}


