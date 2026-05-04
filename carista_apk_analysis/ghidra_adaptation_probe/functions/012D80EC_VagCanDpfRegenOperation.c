/* VagCanDpfRegenOperation::VagCanDpfRegenOperation @ 012d80ec */


/* VagCanDpfRegenOperation::VagCanDpfRegenOperation(std::__ndk1::shared_ptr<ConnectionManager>
   const&, std::__ndk1::shared_ptr<VagBasicSettingTool> const&,
   std::__ndk1::shared_ptr<ReadValuesOperation> const&) */

void __thiscall
VagCanDpfRegenOperation::VagCanDpfRegenOperation
          (VagCanDpfRegenOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3
          )

{
  byte bVar1;
  bool bVar2;
  int *piVar3;
  uint in_fpscr;
  undefined4 extraout_s1;
  undefined4 extraout_s2;
  undefined4 extraout_s3;
  int local_3c [2];
  int local_34 [2];
  undefined4 local_2c;
  int iStack_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  local_2c = *(undefined4 *)param_2;
  iStack_28 = *(int *)(param_2 + 4);
  if (iStack_28 != 0) {
    piVar3 = (int *)(iStack_28 + 4);
    do {
      ExclusiveAccess(piVar3);
      bVar2 = (bool)hasExclusiveAccess(piVar3);
    } while (!bVar2);
    *piVar3 = *piVar3 + 1;
  }
  FUN_012d81bc(local_34,param_2);
  bVar1 = *(byte *)(local_34[0] + 0xa8);
  FUN_012d81bc(local_3c,param_2);
  VectorUnsignedToFloat((uint)*(byte *)(local_3c[0] + 0xa9),(byte)(in_fpscr >> 0x15) & 3);
  VectorUnsignedToFloat((uint)bVar1,(byte)(in_fpscr >> 0x15) & 3);
  DpfRegenGenericOperation::DpfRegenGenericOperation
            ((DpfRegenGenericOperation *)this,param_1,(shared_ptr *)&local_2c,param_3,
             (double)CONCAT44(extraout_s1,(uint)bVar1),(double)CONCAT44(extraout_s3,extraout_s2));
  FUN_012d8208(local_3c);
  FUN_012d8208(local_34);
  FUN_00cc67b0(&local_2c);
  *(undefined ***)this = &PTR__VagCanDpfRegenOperation_014bf1f0;
  if (__stack_chk_guard == local_24) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_24);
}


