/* std::__ndk1::allocator<VagUdsAdaptationSetting>::construct[abi:ne190000]<VagUdsAdaptationSetting,VagUdsEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,short,int,int,char_const(&)[43],std::__ndk1::shared_ptr<NumericalInterpretation>> @ 010fe878 */


/* void 
   std::__ndk1::allocator<VagUdsAdaptationSetting>::construct[abi:ne190000]<VagUdsAdaptationSetting,
   VagUdsEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, short, int, int, char const (&)
   [43], std::__ndk1::shared_ptr<NumericalInterpretation> >(VagUdsAdaptationSetting*, VagUdsEcu*&,
   std::__ndk1::shared_ptr<StringWhitelist> const&, short&&, int&&, int&&, char const (&) [43],
   std::__ndk1::shared_ptr<NumericalInterpretation>&&) */

void __thiscall
std::__ndk1::allocator<VagUdsAdaptationSetting>::
construct_abi_ne190000_<VagUdsAdaptationSetting,VagUdsEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,short,int,int,char_const(&)[43],std::__ndk1::shared_ptr<NumericalInterpretation>>
          (allocator<VagUdsAdaptationSetting> *this,VagUdsAdaptationSetting *param_1,
          VagUdsEcu **param_2,shared_ptr *param_3,short *param_4,int *param_5,int *param_6,
          char *param_7,shared_ptr *param_8)

{
  short sVar1;
  int iVar2;
  VagUdsEcu *pVVar3;
  int iVar4;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  
  local_1c = __stack_chk_guard;
  iVar2 = *param_6;
  sVar1 = *param_4;
  pVVar3 = *param_2;
  iVar4 = *param_5;
  local_24 = *(undefined4 *)param_8;
  uStack_20 = *(undefined4 *)(param_8 + 4);
  *(undefined4 *)param_8 = 0;
  *(undefined4 *)(param_8 + 4) = 0;
  VagUdsAdaptationSetting::VagUdsAdaptationSetting
            (param_1,pVVar3,param_3,sVar1,iVar4,(char)iVar2,param_7,&local_24,2);
                    /* WARNING: Subroutine does not return */
  FUN_00cd2748(&local_24);
}


