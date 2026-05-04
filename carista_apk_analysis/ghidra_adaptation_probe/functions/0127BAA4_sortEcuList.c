/* VagOperationDelegate::sortEcuList @ 0127baa4 */


/* VagOperationDelegate::sortEcuList(EcuList const&) */

void VagOperationDelegate::sortEcuList(EcuList *param_1)

{
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 *local_34;
  undefined4 *puStack_30;
  int local_24;
  
  local_24 = __stack_chk_guard;
  VagEcu::values((VagEcu *)&local_34);
  local_3c = 0;
  local_44 = 0;
  uStack_40 = 0;
  FUN_0120c774(&local_44,(int)puStack_30 - (int)local_34 >> 2);
  for (; local_34 != puStack_30; local_34 = local_34 + 1) {
    local_38 = *local_34;
    FUN_00cc8c48(&local_44,&local_38);
  }
  FUN_01114b98(&local_34);
  EcuList::getOrderedBy((vector *)&local_34);
  Result<EcuList_const,void>::done<EcuList_const>((type *)param_1);
  FUN_00ce44e8(&local_34);
  FUN_00cc8d6c(&local_44);
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


