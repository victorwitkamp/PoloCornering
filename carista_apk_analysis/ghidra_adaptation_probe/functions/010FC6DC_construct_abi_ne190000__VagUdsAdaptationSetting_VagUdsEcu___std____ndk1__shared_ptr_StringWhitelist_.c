/* std::__ndk1::allocator<VagUdsAdaptationSetting>::construct[abi:ne190000]<VagUdsAdaptationSetting,VagUdsEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,short,int,int,char_const(&)[17],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>const&> @ 010fc6dc */


/* void 
   std::__ndk1::allocator<VagUdsAdaptationSetting>::construct[abi:ne190000]<VagUdsAdaptationSetting,
   VagUdsEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, short, int, int, char const (&)
   [17], std::__ndk1::shared_ptr<MultipleChoiceInterpretation> const&>(VagUdsAdaptationSetting*,
   VagUdsEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, short&&, int&&, int&&, char const
   (&) [17], std::__ndk1::shared_ptr<MultipleChoiceInterpretation> const&) */

void __thiscall
std::__ndk1::allocator<VagUdsAdaptationSetting>::
construct_abi_ne190000_<VagUdsAdaptationSetting,VagUdsEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,short,int,int,char_const(&)[17],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>const&>
          (allocator<VagUdsAdaptationSetting> *this,VagUdsAdaptationSetting *param_1,
          VagUdsEcu **param_2,shared_ptr *param_3,short *param_4,int *param_5,int *param_6,
          char *param_7,shared_ptr *param_8)

{
  short sVar1;
  bool bVar2;
  VagUdsEcu *pVVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_24;
  int iStack_20;
  undefined4 local_1c;
  
  local_1c = __stack_chk_guard;
  uVar6 = *param_6;
  iVar5 = *param_5;
  sVar1 = *param_4;
  pVVar3 = *param_2;
  local_24 = *(undefined4 *)param_8;
  iStack_20 = *(int *)(param_8 + 4);
  if (iStack_20 != 0) {
    piVar4 = (int *)(iStack_20 + 4);
    do {
      ExclusiveAccess(piVar4);
      bVar2 = (bool)hasExclusiveAccess(piVar4);
    } while (!bVar2);
    *piVar4 = *piVar4 + 1;
  }
  VagUdsAdaptationSetting::VagUdsAdaptationSetting
            (param_1,pVVar3,param_3,sVar1,iVar5,uVar6 & 0xff,param_7,&local_24,2);
                    /* WARNING: Subroutine does not return */
  FUN_00cd2748(&local_24);
}


