/* std::__ndk1::allocator<VagUdsAdaptationSetting>::construct[abi:ne190000]<VagUdsAdaptationSetting,VagUdsEcu*&,std::__ndk1::shared_ptr<StringWhitelist>,int,int,int,char_const(&)[35],std::__ndk1::shared_ptr<NumericalInterpretation>,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_long_long,std::__ndk1::allocator<unsigned_long_long>>const>const&> @ 010cdfa8 */


/* void 
   std::__ndk1::allocator<VagUdsAdaptationSetting>::construct[abi:ne190000]<VagUdsAdaptationSetting,
   VagUdsEcu*&, std::__ndk1::shared_ptr<StringWhitelist>, int, int, int, char const (&) [35],
   std::__ndk1::shared_ptr<NumericalInterpretation>,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned long long, std::__ndk1::allocator<unsigned
   long long> > const> const&>(VagUdsAdaptationSetting*, VagUdsEcu*&,
   std::__ndk1::shared_ptr<StringWhitelist>&&, int&&, int&&, int&&, char const (&) [35],
   std::__ndk1::shared_ptr<NumericalInterpretation>&&,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned long long, std::__ndk1::allocator<unsigned
   long long> > const> const&) */

void __thiscall
std::__ndk1::allocator<VagUdsAdaptationSetting>::
construct_abi_ne190000_<VagUdsAdaptationSetting,VagUdsEcu*&,std::__ndk1::shared_ptr<StringWhitelist>,int,int,int,char_const(&)[35],std::__ndk1::shared_ptr<NumericalInterpretation>,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_long_long,std::__ndk1::allocator<unsigned_long_long>>const>const&>
          (allocator<VagUdsAdaptationSetting> *this,VagUdsAdaptationSetting *param_1,
          VagUdsEcu **param_2,shared_ptr *param_3,int *param_4,int *param_5,int *param_6,
          char *param_7,shared_ptr *param_8,shared_ptr *param_9)

{
  int iVar1;
  int iVar2;
  VagUdsEcu *pVVar3;
  int iVar4;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  
  local_1c = __stack_chk_guard;
  iVar1 = *param_6;
  iVar2 = *param_4;
  pVVar3 = *param_2;
  iVar4 = *param_5;
  local_24 = *(undefined4 *)param_8;
  uStack_20 = *(undefined4 *)(param_8 + 4);
  *(undefined4 *)param_8 = 0;
  *(undefined4 *)(param_8 + 4) = 0;
  VagUdsAdaptationSetting::VagUdsAdaptationSetting
            (param_1,pVVar3,param_3,(short)iVar2,iVar4,(char)iVar1,param_7,&local_24,param_9,2);
                    /* WARNING: Subroutine does not return */
  FUN_00cd2748(&local_24);
}


