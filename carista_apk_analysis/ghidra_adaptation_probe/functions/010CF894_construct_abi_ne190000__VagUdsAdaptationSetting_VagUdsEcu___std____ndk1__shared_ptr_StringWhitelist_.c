/* std::__ndk1::allocator<VagUdsAdaptationSetting>::construct[abi:ne190000]<VagUdsAdaptationSetting,VagUdsEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,int,int,char_const(&)[34],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>const&> @ 010cf894 */


/* void 
   std::__ndk1::allocator<VagUdsAdaptationSetting>::construct[abi:ne190000]<VagUdsAdaptationSetting,
   VagUdsEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, int, int, int, char const (&) [34],
   std::__ndk1::shared_ptr<MultipleChoiceInterpretation> const&>(VagUdsAdaptationSetting*,
   VagUdsEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, int&&, int&&, int&&, char const (&)
   [34], std::__ndk1::shared_ptr<MultipleChoiceInterpretation> const&) */

void __thiscall
std::__ndk1::allocator<VagUdsAdaptationSetting>::
construct_abi_ne190000_<VagUdsAdaptationSetting,VagUdsEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,int,int,char_const(&)[34],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>const&>
          (allocator<VagUdsAdaptationSetting> *this,VagUdsAdaptationSetting *param_1,
          VagUdsEcu **param_2,shared_ptr *param_3,int *param_4,int *param_5,int *param_6,
          char *param_7,shared_ptr *param_8)

{
  bool bVar1;
  VagUdsEcu *pVVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_24;
  int iStack_20;
  undefined4 local_1c;
  
  local_1c = __stack_chk_guard;
  uVar4 = *param_6;
  iVar5 = *param_5;
  uVar6 = *param_4;
  pVVar2 = *param_2;
  local_24 = *(undefined4 *)param_8;
  iStack_20 = *(int *)(param_8 + 4);
  if (iStack_20 != 0) {
    piVar3 = (int *)(iStack_20 + 4);
    do {
      ExclusiveAccess(piVar3);
      bVar1 = (bool)hasExclusiveAccess(piVar3);
    } while (!bVar1);
    *piVar3 = *piVar3 + 1;
  }
  VagUdsAdaptationSetting::VagUdsAdaptationSetting
            (param_1,pVVar2,param_3,uVar6 & 0xffff,iVar5,uVar4 & 0xff,param_7,&local_24,2);
                    /* WARNING: Subroutine does not return */
  FUN_00cd2748(&local_24);
}


