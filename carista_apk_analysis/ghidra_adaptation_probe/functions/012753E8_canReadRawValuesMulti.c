/* VagOperationDelegate::canReadRawValuesMulti @ 012753e8 */


/* VagOperationDelegate::canReadRawValuesMulti(std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,
   std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting> > > const&) */

void VagOperationDelegate::canReadRawValuesMulti(vector *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *in_r1;
  int unaff_r5;
  undefined4 *puVar5;
  
  iVar1 = __stack_chk_guard;
  if (0xf < (uint)(in_r1[1] - *in_r1)) {
    puVar2 = (undefined4 *)FUN_00cf82e4();
    iVar3 = (**(code **)(*(int *)*puVar2 + 0x14))();
    puVar2 = (undefined4 *)*in_r1;
    puVar5 = (undefined4 *)in_r1[1];
    do {
      if (((puVar2 == puVar5) || (iVar4 = (**(code **)(*(int *)*puVar2 + 0x14))(), iVar4 == 0)) ||
         (iVar4 = __dynamic_cast(iVar4,&Ecu::typeinfo,&VagUdsEcu::typeinfo,0), iVar4 == 0)) break;
      FUN_012754c0(&stack0xffffffd0,puVar2);
      if (unaff_r5 == 0) {
        FUN_010bbffc(&stack0xffffffd0);
        break;
      }
      iVar4 = (**(code **)(*(int *)*puVar2 + 0x14))();
      FUN_010bbffc(&stack0xffffffd0);
      puVar2 = puVar2 + 2;
    } while (iVar3 == iVar4);
  }
  if (__stack_chk_guard == iVar1) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar1);
}


