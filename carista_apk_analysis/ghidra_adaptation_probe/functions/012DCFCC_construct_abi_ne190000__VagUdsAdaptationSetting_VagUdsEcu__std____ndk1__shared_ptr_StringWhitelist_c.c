/* std::__ndk1::allocator<VagUdsAdaptationSetting>::construct[abi:ne190000]<VagUdsAdaptationSetting,VagUdsEcu*,std::__ndk1::shared_ptr<StringWhitelist>const&,unsigned_short_const&,int,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>&,char_const(&)[24],decltype(nullptr),std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_long_long,std::__ndk1::allocator<unsigned_long_long>>const>const&> @ 012dcfcc */


/* void 
   std::__ndk1::allocator<VagUdsAdaptationSetting>::construct[abi:ne190000]<VagUdsAdaptationSetting,
   VagUdsEcu*, std::__ndk1::shared_ptr<StringWhitelist> const&, unsigned short const&, int,
   std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> >&, char const (&) [24],
   decltype(nullptr), std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned long long,
   std::__ndk1::allocator<unsigned long long> > const> const&>(VagUdsAdaptationSetting*,
   VagUdsEcu*&&, std::__ndk1::shared_ptr<StringWhitelist> const&, unsigned short const&, int&&,
   std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> >&, char const (&) [24],
   decltype(nullptr)&&, std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned long long,
   std::__ndk1::allocator<unsigned long long> > const> const&) */

void __thiscall
std::__ndk1::allocator<VagUdsAdaptationSetting>::
construct_abi_ne190000_<VagUdsAdaptationSetting,VagUdsEcu*,std::__ndk1::shared_ptr<StringWhitelist>const&,unsigned_short_const&,int,std::__ndk1::vector<unsigned_char,std::__ndk1::allocator<unsigned_char>>&,char_const(&)[24],decltype(nullptr),std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_long_long,std::__ndk1::allocator<unsigned_long_long>>const>const&>
          (allocator<VagUdsAdaptationSetting> *this,VagUdsAdaptationSetting *param_1,
          VagUdsEcu **param_2,shared_ptr *param_3,ushort *param_4,int *param_5,vector *param_6,
          char *param_7,_func_decltype_nullptr **param_8,shared_ptr *param_9)

{
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  local_14 = __stack_chk_guard;
  local_1c = 0;
  uStack_18 = 0;
  VagUdsAdaptationSetting::VagUdsAdaptationSetting
            (param_1,*param_2,param_3,*param_4,*param_5,param_6,param_7,&local_1c,param_9,2);
                    /* WARNING: Subroutine does not return */
  FUN_00cd2748(&local_1c);
}


