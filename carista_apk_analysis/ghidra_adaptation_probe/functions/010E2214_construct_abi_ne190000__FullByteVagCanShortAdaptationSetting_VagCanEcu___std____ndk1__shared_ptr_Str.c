/* std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>::construct[abi:ne190000]<FullByteVagCanShortAdaptationSetting,VagCanEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,char_const(&)[27],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>const&> @ 010e2214 */


/* void 
   std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>::construct[abi:ne190000]<FullByteVagCanShortAdaptationSetting,
   VagCanEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, int, char const (&) [27],
   std::__ndk1::shared_ptr<MultipleChoiceInterpretation>
   const&>(FullByteVagCanShortAdaptationSetting*, VagCanEcu*&,
   std::__ndk1::shared_ptr<StringWhitelist> const&, int&&, char const (&) [27],
   std::__ndk1::shared_ptr<MultipleChoiceInterpretation> const&) */

void __thiscall
std::__ndk1::allocator<FullByteVagCanShortAdaptationSetting>::
construct_abi_ne190000_<FullByteVagCanShortAdaptationSetting,VagCanEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,char_const(&)[27],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>const&>
          (allocator<FullByteVagCanShortAdaptationSetting> *this,
          FullByteVagCanShortAdaptationSetting *param_1,VagCanEcu **param_2,shared_ptr *param_3,
          int *param_4,char *param_5,shared_ptr *param_6)

{
  bool bVar1;
  VagCanEcu *pVVar2;
  int iVar3;
  int *piVar4;
  undefined4 local_24;
  int iStack_20;
  undefined4 local_1c;
  
  local_1c = __stack_chk_guard;
  iVar3 = *param_4;
  pVVar2 = *param_2;
  local_24 = *(undefined4 *)param_6;
  iStack_20 = *(int *)(param_6 + 4);
  if (iStack_20 != 0) {
    piVar4 = (int *)(iStack_20 + 4);
    do {
      ExclusiveAccess(piVar4);
      bVar1 = (bool)hasExclusiveAccess(piVar4);
    } while (!bVar1);
    *piVar4 = *piVar4 + 1;
  }
  FullByteVagCanShortAdaptationSetting::FullByteVagCanShortAdaptationSetting
            (param_1,pVVar2,param_3,(uchar)iVar3,param_5,(shared_ptr *)&local_24);
                    /* WARNING: Subroutine does not return */
  FUN_00cd2748(&local_24);
}


