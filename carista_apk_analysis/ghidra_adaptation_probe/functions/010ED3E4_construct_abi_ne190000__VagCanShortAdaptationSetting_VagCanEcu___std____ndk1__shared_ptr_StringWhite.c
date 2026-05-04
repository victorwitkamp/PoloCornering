/* std::__ndk1::allocator<VagCanShortAdaptationSetting>::construct[abi:ne190000]<VagCanShortAdaptationSetting,VagCanEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,int,int,char_const(&)[39],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>const&> @ 010ed3e4 */


/* void 
   std::__ndk1::allocator<VagCanShortAdaptationSetting>::construct[abi:ne190000]<VagCanShortAdaptationSetting,
   VagCanEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, int, int, int, char const (&) [39],
   std::__ndk1::shared_ptr<MultipleChoiceInterpretation> const&>(VagCanShortAdaptationSetting*,
   VagCanEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, int&&, int&&, int&&, char const (&)
   [39], std::__ndk1::shared_ptr<MultipleChoiceInterpretation> const&) */

void __thiscall
std::__ndk1::allocator<VagCanShortAdaptationSetting>::
construct_abi_ne190000_<VagCanShortAdaptationSetting,VagCanEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,int,int,char_const(&)[39],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>const&>
          (allocator<VagCanShortAdaptationSetting> *this,VagCanShortAdaptationSetting *param_1,
          VagCanEcu **param_2,shared_ptr *param_3,int *param_4,int *param_5,int *param_6,
          char *param_7,shared_ptr *param_8)

{
  bool bVar1;
  VagCanEcu *pVVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_24;
  int iStack_20;
  undefined4 local_1c;
  
  local_1c = __stack_chk_guard;
  iVar6 = *param_6;
  iVar5 = *param_5;
  iVar4 = *param_4;
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
  VagCanShortAdaptationSetting::VagCanShortAdaptationSetting
            (param_1,pVVar2,param_3,(uchar)iVar4,iVar5,iVar6,param_7,(shared_ptr *)&local_24);
                    /* WARNING: Subroutine does not return */
  FUN_00cd2748(&local_24);
}


