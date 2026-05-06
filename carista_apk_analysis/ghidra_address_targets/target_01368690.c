/* Target address 01368690 */
/* Function operator() @ 01368624 */


/* CryptoPP::AssignFromHelperClass<CryptoPP::DL_PublicKey<CryptoPP::Integer>,
   CryptoPP::DL_PublicKey<CryptoPP::Integer> >&
   CryptoPP::AssignFromHelperClass<CryptoPP::DL_PublicKey<CryptoPP::Integer>,
   CryptoPP::DL_PublicKey<CryptoPP::Integer> >::TEMPNAMEPLACEHOLDERVALUE(char const*, void
   (CryptoPP::DL_PublicKey<CryptoPP::Integer>::*)(CryptoPP::Integer const&)) */

AssignFromHelperClass *
CryptoPP::
AssignFromHelperClass<CryptoPP::DL_PublicKey<CryptoPP::Integer>,CryptoPP::DL_PublicKey<CryptoPP::Integer>>
::operator()(char *param_1,_func_void_Integer_ptr *param_2)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  void *pvVar5;
  undefined4 *puVar6;
  size_t sVar7;
  byte *pbVar8;
  code *in_r2;
  uint in_r3;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined4 local_68;
  undefined4 local_64;
  void *local_60;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined2 local_3c;
  byte local_3a;
  undefined **local_38 [2];
  uint local_30;
  uint uStack_2c;
  void *local_28;
  
  if (param_1[8] != '\0') {
    return param_1;
  }
  Integer::Integer((Integer *)local_38);
  iVar2 = (**(code **)(**(int **)(param_1 + 4) + 8))
                    (*(int **)(param_1 + 4),param_2,&Integer::typeinfo,(Integer *)local_38);
  if (iVar2 != 0) {
    piVar3 = (int *)(*(int *)param_1 + ((int)in_r3 >> 1));
    if ((in_r3 & 1) != 0) {
      in_r2 = *(code **)(in_r2 + *piVar3);
    }
    (*in_r2)(piVar3,local_38);
    local_38[0] = &PTR__Integer_014c27a8;
    if (local_30 < uStack_2c) {
      uStack_2c = local_30;
    }
    if (uStack_2c != 0) {
      iVar2 = uStack_2c + 1;
      do {
        *(undefined4 *)((int)local_28 + iVar2 * 4 + -8) = 0;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 1);
    }
    UnalignedDeallocate(local_28);
    return param_1;
  }
  puVar4 = (undefined4 *)__cxa_allocate_exception(0x14);
  local_60 = (void *)0x0;
  local_68 = 0;
  local_64 = 0;
  pvVar5 = operator_new(0x30);
  local_68 = 0x31;
  local_64 = 0x27;
  local_60 = pvVar5;
  __aeabi_memcpy(pvVar5,"N8CryptoPP12DL_PublicKeyINS_7IntegerEEE",0x27);
  *(undefined1 *)((int)pvVar5 + 0x27) = 0;
  puVar6 = (undefined4 *)
           std::__ndk1::
           basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::append
                     ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                       *)&local_68,": Missing required parameter \'",0x1e);
  local_58 = *puVar6;
  uStack_54 = puVar6[1];
  uStack_50 = puVar6[2];
  *puVar6 = 0;
  puVar6[1] = 0;
  puVar6[2] = 0;
  sVar7 = strlen((char *)param_2);
  puVar6 = (undefined4 *)
           std::__ndk1::
           basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::append
                     ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                       *)&local_58,(char *)param_2,sVar7);
  local_48 = *puVar6;
  uStack_44 = puVar6[1];
  uStack_40 = puVar6[2];
  *puVar6 = 0;
  puVar6[1] = 0;
  puVar6[2] = 0;
  pbVar8 = (byte *)std::__ndk1::
                   basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
                   append((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                           *)&local_48,"\'",1);
  bVar1 = *pbVar8;
  local_3a = pbVar8[3];
  local_3c = *(undefined2 *)(pbVar8 + 1);
  uVar9 = *(uint *)(pbVar8 + 4);
  uVar10 = *(undefined4 *)(pbVar8 + 8);
  pbVar8[0] = 0;
  pbVar8[1] = 0;
  pbVar8[2] = 0;
  pbVar8[3] = 0;
  pbVar8[4] = 0;
  pbVar8[5] = 0;
  pbVar8[6] = 0;
  pbVar8[7] = 0;
  pbVar8[8] = 0;
  pbVar8[9] = 0;
  pbVar8[10] = 0;
  pbVar8[0xb] = 0;
  puVar4[3] = 0;
  puVar4[4] = 0;
  *puVar4 = &PTR__Exception_01437e7c;
  puVar4[1] = 1;
  puVar4[2] = 0;
  if ((bVar1 & 1) == 0) {
    *(byte *)(puVar4 + 2) = bVar1;
    *(byte *)((int)puVar4 + 0xb) = local_3a;
    *(undefined2 *)((int)puVar4 + 9) = local_3c;
    puVar4[3] = uVar9;
    puVar4[4] = uVar10;
    goto LAB_013687c4;
  }
  if (0xffffffef < uVar9) {
    std::__ndk1::__basic_string_common<true>::__throw_length_error();
  }
  if (uVar9 < 0xb) {
    pvVar5 = (void *)((int)puVar4 + 9);
    *(char *)(puVar4 + 2) = (char)(uVar9 << 1);
    if (uVar9 != 0) goto LAB_013687b6;
  }
  else {
    uVar11 = uVar9 + 0x10 & 0xfffffff0;
    pvVar5 = operator_new(uVar11);
    puVar4[2] = uVar11 | 1;
    puVar4[3] = uVar9;
    puVar4[4] = pvVar5;
LAB_013687b6:
    __aeabi_memcpy(pvVar5,uVar10,uVar9);
  }
  *(undefined1 *)((int)pvVar5 + uVar9) = 0;
LAB_013687c4:
  *puVar4 = &PTR__Exception_01438488;
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar4,&InvalidArgument::typeinfo,Exception::~Exception);
}


