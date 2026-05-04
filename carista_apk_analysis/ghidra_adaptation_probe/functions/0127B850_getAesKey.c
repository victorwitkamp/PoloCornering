/* VagOperationDelegate::getAesKey @ 0127b850 */


/* VagOperationDelegate::getAesKey() */

void __thiscall VagOperationDelegate::getAesKey(VagOperationDelegate *this)

{
  byte bVar1;
  longlong lVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  IllegalStateException *this_00;
  undefined1 extraout_r1;
  byte bVar7;
  int *piVar8;
  uint uVar9;
  int extraout_r1_00;
  undefined1 extraout_r2;
  uint extraout_r2_00;
  uint extraout_r3;
  uint uVar10;
  undefined1 *puVar11;
  uint uVar12;
  byte *pbVar13;
  byte *pbVar14;
  byte *pbVar15;
  basic_string abStack_64 [12];
  byte *local_58 [2];
  int local_50;
  int local_4c;
  undefined4 local_48;
  int local_44 [3];
  undefined8 local_38;
  undefined8 uStack_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  uVar4 = VagCanSettings::getSettings();
  iVar5 = FUN_00d5ad40(uVar4,&SettingCategory::OTHER);
  iVar5 = *(int *)(*(int *)(iVar5 + 4) + -8);
  piVar8 = (int *)(iVar5 + 0x2c);
  iVar6 = *piVar8;
  iVar5 = *(int *)(iVar5 + 0x30);
  local_38 = *(undefined8 *)piVar8;
  if (iVar5 != 0) {
    piVar8 = (int *)(iVar5 + 4);
    do {
      ExclusiveAccess(piVar8);
      bVar3 = (bool)hasExclusiveAccess(piVar8);
    } while (!bVar3);
    *piVar8 = *piVar8 + 1;
  }
  func_0x00cb9fec(local_44,iVar6 + 4);
  FUN_00cba550(&local_38);
  local_38 = 0x6f714e301ea698de;
  uStack_30 = 0xbcfaaadcbc22a778;
  FUN_00cdb87c(this,&local_38,0x10);
  FUN_00cbd800(&local_38,0x10);
  pbVar15 = *(byte **)this;
  pbVar14 = *(byte **)(this + 4);
  puVar11 = (byte *)local_38;
  for (; pbVar15 != pbVar14; pbVar15 = pbVar15 + 1) {
    uVar9 = (uint)*pbVar15;
    iVar5 = local_44[0] + (uVar9 & 7) * 0x10;
    uVar10 = *(uint *)(iVar5 + 0x80);
    uVar12 = *(uint *)(iVar5 + 0x84);
    lVar2 = (ulonglong)*(uint *)(local_44[0] + (uVar9 & 7) * 0x10) * (ulonglong)uVar9;
    FUN_013f5290((int)lVar2,*(int *)(iVar5 + 4) * uVar9 + (int)((ulonglong)lVar2 >> 0x20),0xff,0);
    FUN_013f5290(extraout_r2_00 ^ uVar10,extraout_r3 ^ uVar12,0xff,0);
    *puVar11 = extraout_r2;
    puVar11 = puVar11 + 1;
  }
  pbVar14 = *(byte **)this;
  pbVar15 = *(byte **)(this + 4);
  puVar11 = (byte *)local_38;
  for (; pbVar14 != pbVar15; pbVar14 = pbVar14 + 1) {
    FUN_013f5274(*pbVar14 ^ 0x4a40,0xff);
    *puVar11 = extraout_r1;
    puVar11 = puVar11 + 1;
  }
  local_48 = 0;
  local_50 = 0;
  local_4c = 0;
  iVar5 = LONGADAPT_STR._8_4_;
  uVar9 = LONGADAPT_STR._4_4_;
  if ((LONGADAPT_STR[0] & 1) == 0) {
    uVar9 = (uint)(LONGADAPT_STR[0] >> 1);
    iVar5 = 0x14f8ec5;
  }
  _ZNSt6__ndk16vectorIhNS_9allocatorIhEEE6insertIPKcTnNS_9enable_ifIXaasr31__has_forward_iterator_categoryIT_EE5valuesr16is_constructibleIhNS_15iterator_traitsIS8_E9referenceEEE5valueEiE4typeELi0EEENS_11__wrap_iterIPhEENSE_IPKhEES8_S8_
            (&local_50,0,iVar5,iVar5 + uVar9);
  FUN_00cb4d44(abStack_64,"WVPZZALKZGP940432");
  VagVin::getPdx((VagVin *)local_58,abStack_64);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                abStack_64);
  if (local_58[0] == (byte *)0x0) {
    this_00 = (IllegalStateException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(abStack_64,"PDX is nullptr");
    IllegalStateException::IllegalStateException(this_00,abStack_64);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this_00,&IllegalStateException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  uVar9 = *(uint *)(local_58[0] + 4);
  pbVar14 = *(byte **)(local_58[0] + 8);
  if ((*local_58[0] & 1) == 0) {
    uVar9 = (uint)(*local_58[0] >> 1);
    pbVar14 = local_58[0] + 1;
  }
  _ZNSt6__ndk16vectorIhNS_9allocatorIhEEE6insertIPKcTnNS_9enable_ifIXaasr31__has_forward_iterator_categoryIT_EE5valuesr16is_constructibleIhNS_15iterator_traitsIS8_E9referenceEEE5valueEiE4typeELi0EEENS_11__wrap_iterIPhEENSE_IPKhEES8_S8_
            (&local_50,local_4c,pbVar14,pbVar14 + uVar9);
  pbVar13 = *(byte **)(this + 4);
  pbVar14 = *(byte **)this;
  pbVar15 = (byte *)local_38;
  while (iVar5 = local_50, pbVar14 != pbVar13) {
    bVar1 = *pbVar14;
    FUN_013f5274(bVar1,local_4c - local_50);
    bVar1 = *(byte *)(iVar5 + extraout_r1_00) ^ bVar1;
    bVar7 = 0;
    if (bVar1 != 0xff) {
      bVar7 = bVar1;
    }
    *pbVar15 = bVar7;
    pbVar14 = pbVar14 + 1;
    pbVar15 = pbVar15 + 1;
  }
  FUN_00cbd6dc(local_58);
  FUN_00cb7f50(&local_50);
  FUN_00cb7f50(&local_38);
  FUN_00cba04c(local_44);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


