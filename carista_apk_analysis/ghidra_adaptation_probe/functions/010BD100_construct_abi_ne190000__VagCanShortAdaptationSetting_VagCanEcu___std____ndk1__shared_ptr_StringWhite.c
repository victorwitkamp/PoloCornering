/* std::__ndk1::allocator<VagCanShortAdaptationSetting>::construct[abi:ne190000]<VagCanShortAdaptationSetting,VagCanEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,int,int,char_const(&)[29],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>const&,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_long_long,std::__ndk1::allocator<unsigned_long_long>>const>const&> @ 010bd100 */


/* void 
   std::__ndk1::allocator<VagCanShortAdaptationSetting>::construct[abi:ne190000]<VagCanShortAdaptationSetting,
   VagCanEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, int, int, int, char const (&) [29],
   std::__ndk1::shared_ptr<MultipleChoiceInterpretation> const&,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned long long, std::__ndk1::allocator<unsigned
   long long> > const> const&>(VagCanShortAdaptationSetting*, VagCanEcu*&,
   std::__ndk1::shared_ptr<StringWhitelist> const&, int&&, int&&, int&&, char const (&) [29],
   std::__ndk1::shared_ptr<MultipleChoiceInterpretation> const&,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned long long, std::__ndk1::allocator<unsigned
   long long> > const> const&) */

void __thiscall
std::__ndk1::allocator<VagCanShortAdaptationSetting>::
construct_abi_ne190000_<VagCanShortAdaptationSetting,VagCanEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,int,int,char_const(&)[29],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>const&,std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned_long_long,std::__ndk1::allocator<unsigned_long_long>>const>const&>
          (allocator<VagCanShortAdaptationSetting> *this,VagCanShortAdaptationSetting *param_1,
          VagCanEcu **param_2,shared_ptr *param_3,int *param_4,int *param_5,int *param_6,
          char *param_7,shared_ptr *param_8,shared_ptr *param_9)

{
  bool bVar1;
  VagCanEcu *pVVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = *param_6;
  iVar5 = *param_5;
  iVar6 = *param_4;
  pVVar2 = *param_2;
  if (*(int *)(param_8 + 4) != 0) {
    piVar3 = (int *)(*(int *)(param_8 + 4) + 4);
    do {
      ExclusiveAccess(piVar3);
      bVar1 = (bool)hasExclusiveAccess(piVar3);
    } while (!bVar1);
    *piVar3 = *piVar3 + 1;
  }
  VagCanShortAdaptationSetting::VagCanShortAdaptationSetting
            (param_1,pVVar2,param_3,(uchar)iVar6,iVar5,(uchar)iVar4,param_7,
             (shared_ptr *)&stack0xffffffd4,param_9);
                    /* WARNING: Subroutine does not return */
  FUN_00cd2748(&stack0xffffffd4);
}


