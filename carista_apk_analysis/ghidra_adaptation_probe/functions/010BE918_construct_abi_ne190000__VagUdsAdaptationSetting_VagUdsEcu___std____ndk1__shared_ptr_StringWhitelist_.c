/* std::__ndk1::allocator<VagUdsAdaptationSetting>::construct[abi:ne190000]<VagUdsAdaptationSetting,VagUdsEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,int,int,char_const(&)[40],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>const&> @ 010be918 */


/* void 
   std::__ndk1::allocator<VagUdsAdaptationSetting>::construct[abi:ne190000]<VagUdsAdaptationSetting,
   VagUdsEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, int, int, int, char const (&) [40],
   std::__ndk1::shared_ptr<MultipleChoiceInterpretation> const&>(VagUdsAdaptationSetting*,
   VagUdsEcu*&, std::__ndk1::shared_ptr<StringWhitelist> const&, int&&, int&&, int&&, char const (&)
   [40], std::__ndk1::shared_ptr<MultipleChoiceInterpretation> const&) */

void std::__ndk1::allocator<VagUdsAdaptationSetting>::
     construct_abi_ne190000_<VagUdsAdaptationSetting,VagUdsEcu*&,std::__ndk1::shared_ptr<StringWhitelist>const&,int,int,int,char_const(&)[40],std::__ndk1::shared_ptr<MultipleChoiceInterpretation>const&>
               (VagUdsAdaptationSetting *param_1,VagUdsEcu **param_2,shared_ptr *param_3,
               int *param_4,int *param_5,int *param_6,char *param_7,shared_ptr *param_8)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined1 *unaff_r7;
  undefined4 unaff_r8;
  uint uVar7;
  undefined4 uVar8;
  bool in_ZR;
  bool in_CY;
  
  if (!in_CY || in_ZR) {
    register0x00000054 = (BADSPACEBASE *)&stack0xffffffec;
  }
  if (in_CY && !in_ZR) {
    unaff_r7 = (undefined1 *)((int)register0x00000054 + 0xc);
  }
  *(undefined4 *)((int)register0x00000054 + -4) = unaff_r8;
  uVar8 = *(undefined4 *)(unaff_r7 + 0x14);
  *(undefined4 *)((int)register0x00000054 + -8) = __stack_chk_guard;
  uVar5 = **(uint **)(unaff_r7 + 0x10);
  uVar6 = **(undefined4 **)(unaff_r7 + 0xc);
  uVar7 = **(uint **)(unaff_r7 + 8);
  uVar2 = *(undefined4 *)param_3;
  iVar3 = (*(undefined4 **)(unaff_r7 + 0x18))[1];
  *(undefined4 *)((int)register0x00000054 + -0x10) = **(undefined4 **)(unaff_r7 + 0x18);
  *(int *)((int)register0x00000054 + -0xc) = iVar3;
  if (iVar3 != 0) {
    piVar4 = (int *)(iVar3 + 4);
    do {
      ExclusiveAccess(piVar4);
      bVar1 = (bool)hasExclusiveAccess(piVar4);
    } while (!bVar1);
    *piVar4 = *piVar4 + 1;
  }
  *(undefined4 *)((int)register0x00000054 + -0x14) = 2;
  *(undefined4 *)((int)register0x00000054 + -0x1c) = uVar8;
  *(undefined1 **)((int)register0x00000054 + -0x18) =
       (undefined1 *)((int)register0x00000054 + -0x10);
  *(undefined4 *)((int)register0x00000054 + -0x24) = uVar6;
  *(uint *)((int)register0x00000054 + -0x20) = uVar5 & 0xff;
  VagUdsAdaptationSetting::VagUdsAdaptationSetting
            ((VagUdsAdaptationSetting *)param_2,uVar2,param_4,uVar7 & 0xffff);
                    /* WARNING: Subroutine does not return */
  FUN_00cd2748((undefined1 *)((int)register0x00000054 + -0x10));
}


