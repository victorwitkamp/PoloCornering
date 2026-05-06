/* Target address 0136c910 */
/* Function SimultaneousMultiply @ 0136c774 */


/* CryptoPP::ECP::SimultaneousMultiply(CryptoPP::ECPPoint*, CryptoPP::ECPPoint const&,
   CryptoPP::Integer const*, unsigned int) const */

void __thiscall
CryptoPP::ECP::SimultaneousMultiply
          (ECP *this,ECPPoint *param_1,ECPPoint *param_2,Integer *param_3,uint param_4)

{
  Integer *pIVar1;
  undefined4 *puVar2;
  ECPPoint *pEVar3;
  ECPPoint *pEVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  ProjectivePoint *pPVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  vector<unsigned_int,std::__ndk1::allocator<unsigned_int>> *pvVar12;
  int iVar13;
  void *pvVar14;
  ProjectivePoint *pPVar15;
  logic_error *this_00;
  Integer *pIVar16;
  Integer **ppIVar17;
  uint *puVar18;
  int *piVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;
  int iVar23;
  Integer *pIVar24;
  uint uVar25;
  uint uVar26;
  undefined4 *puVar27;
  undefined4 *local_1b0;
  undefined4 *local_1a8;
  ECPPoint *local_1a4;
  ECPPoint *local_1a0;
  undefined4 local_19c;
  undefined **local_198;
  undefined **local_194;
  Integer **local_190;
  Integer **local_18c;
  Integer **local_188;
  void *local_184;
  undefined **local_180;
  undefined **local_17c;
  void *local_178;
  void *local_174;
  void *local_170;
  void *local_16c;
  undefined4 local_168;
  uint local_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 *local_158;
  undefined4 *local_154;
  undefined4 *local_150;
  undefined4 *local_14c;
  undefined4 *local_148;
  undefined4 *local_144;
  undefined4 *local_140;
  undefined4 *local_13c;
  undefined4 *local_138;
  ProjectiveDoubling aPStack_134 [4];
  ProjectivePoint aPStack_130 [4];
  int *local_12c;
  Integer *local_54;
  Integer *local_50;
  Integer *local_4c;
  Integer *pIStack_48;
  void *local_44;
  ProjectivePoint *local_3c;
  ProjectivePoint *local_38;
  ProjectivePoint *local_34;
  uint uStack_30;
  void *local_2c;
  
  iVar11 = (**(code **)(**(int **)(this + 8) + 100))();
  if (iVar11 == 0) {
    ECP((ECP *)aPStack_134,this,true);
    if (param_2[0x34] == (ECPPoint)0x0) {
      (**(code **)(*local_12c + 0x68))(&local_3c,local_12c,param_2 + 4);
      (**(code **)(*local_12c + 0x68))(&local_54,local_12c,param_2 + 0x1c);
      local_198 = &PTR__ECPPoint_014cd268;
      Integer::Integer((Integer *)&local_194,(Integer *)&local_3c);
      Integer::Integer((Integer *)&local_17c,(Integer *)&local_54);
      local_164 = local_164 & 0xffffff00;
      local_3c = (ProjectivePoint *)&PTR__Integer_014c27a8;
      pIVar24 = pIStack_48;
      if (local_4c < pIStack_48) {
        pIVar24 = local_4c;
      }
      if (pIVar24 != (Integer *)0x0) {
        pIVar24 = pIVar24 + 1;
        do {
          *(undefined4 *)((int)local_44 + (int)pIVar24 * 4 + -8) = 0;
          pIVar24 = pIVar24 + -1;
        } while (pIVar24 != (Integer *)0x1);
      }
      local_54 = (Integer *)local_3c;
      UnalignedDeallocate(local_44);
      pPVar15 = (ProjectivePoint *)uStack_30;
      if (local_34 < uStack_30) {
        pPVar15 = local_34;
      }
      if (pPVar15 != (ProjectivePoint *)0x0) {
        iVar11 = (int)pPVar15 + 1;
        do {
          *(undefined4 *)((int)local_2c + iVar11 * 4 + -8) = 0;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 1);
      }
      UnalignedDeallocate(local_2c);
    }
    else {
      local_198 = &PTR__ECPPoint_014cd268;
      Integer::Integer((Integer *)&local_194,(Integer *)(param_2 + 4));
      Integer::Integer((Integer *)&local_17c,(Integer *)(param_2 + 0x1c));
      local_164 = CONCAT31(local_164._1_3_,param_2[0x34]);
    }
    SimultaneousMultiply((ECP *)aPStack_134,param_1,(ECPPoint *)&local_198,param_3,param_4);
    local_198 = &PTR__ECPPoint_014cd268;
    pvVar14 = local_170;
    if (local_174 < local_170) {
      pvVar14 = local_174;
    }
    if (pvVar14 != (void *)0x0) {
      iVar11 = (int)pvVar14 + 1;
      do {
        *(undefined4 *)((int)local_16c + iVar11 * 4 + -8) = 0;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 1);
    }
    local_17c = &PTR__Integer_014c27a8;
    UnalignedDeallocate(local_16c);
    ppIVar17 = local_188;
    if (local_18c < local_188) {
      ppIVar17 = local_18c;
    }
    if (ppIVar17 != (Integer **)0x0) {
      iVar11 = (int)ppIVar17 + 1;
      do {
        *(undefined4 *)((int)local_184 + iVar11 * 4 + -8) = 0;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 1);
    }
    local_194 = &PTR__Integer_014c27a8;
    UnalignedDeallocate(local_184);
    if (param_4 != 0) {
      uVar25 = 0;
      do {
        pEVar3 = param_1 + uVar25 * 0x38 + 0x34;
        if (*pEVar3 == (ECPPoint)0x0) {
          (**(code **)(*local_12c + 0x6c))(&local_3c,local_12c,param_1 + uVar25 * 0x38 + 4);
          (**(code **)(*local_12c + 0x6c))(&local_54,local_12c,param_1 + uVar25 * 0x38 + 0x1c);
          local_198 = &PTR__ECPPoint_014cd268;
          Integer::Integer((Integer *)&local_194,(Integer *)&local_3c);
          Integer::Integer((Integer *)&local_17c,(Integer *)&local_54);
          local_164 = local_164 & 0xffffff00;
          pIVar24 = pIStack_48;
          if (local_4c < pIStack_48) {
            pIVar24 = local_4c;
          }
          if (pIVar24 != (Integer *)0x0) {
            pIVar24 = pIVar24 + 1;
            do {
              *(undefined4 *)((int)local_44 + (int)pIVar24 * 4 + -8) = 0;
              pIVar24 = pIVar24 + -1;
            } while (pIVar24 != (Integer *)0x1);
          }
          local_54 = (Integer *)&PTR__Integer_014c27a8;
          UnalignedDeallocate(local_44);
          pPVar15 = (ProjectivePoint *)uStack_30;
          if (local_34 < uStack_30) {
            pPVar15 = local_34;
          }
          if (pPVar15 != (ProjectivePoint *)0x0) {
            iVar11 = (int)pPVar15 + 1;
            do {
              *(undefined4 *)((int)local_2c + iVar11 * 4 + -8) = 0;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 1);
          }
          local_3c = (ProjectivePoint *)&PTR__Integer_014c27a8;
          UnalignedDeallocate(local_2c);
        }
        else {
          local_198 = &PTR__ECPPoint_014cd268;
          Integer::Integer((Integer *)&local_194,(Integer *)(param_1 + uVar25 * 0x38 + 4));
          Integer::Integer((Integer *)&local_17c,(Integer *)(param_1 + uVar25 * 0x38 + 0x1c));
          local_164 = CONCAT31(local_164._1_3_,*pEVar3);
        }
        Integer::operator=((Integer *)(param_1 + uVar25 * 0x38 + 4),(Integer *)&local_194);
        Integer::operator=((Integer *)(param_1 + uVar25 * 0x38 + 0x1c),(Integer *)&local_17c);
        *pEVar3 = local_164._0_1_;
        local_198 = &PTR__ECPPoint_014cd268;
        pvVar14 = local_170;
        if (local_174 < local_170) {
          pvVar14 = local_174;
        }
        if (pvVar14 != (void *)0x0) {
          iVar11 = (int)pvVar14 + 1;
          do {
            *(undefined4 *)((int)local_16c + iVar11 * 4 + -8) = 0;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 1);
        }
        local_17c = &PTR__Integer_014c27a8;
        UnalignedDeallocate(local_16c);
        ppIVar17 = local_188;
        if (local_18c < local_188) {
          ppIVar17 = local_18c;
        }
        if (ppIVar17 != (Integer **)0x0) {
          iVar11 = (int)ppIVar17 + 1;
          do {
            *(undefined4 *)((int)local_184 + iVar11 * 4 + -8) = 0;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 1);
        }
        local_194 = &PTR__Integer_014c27a8;
        UnalignedDeallocate(local_184);
        uVar25 = uVar25 + 1;
      } while (uVar25 < param_4);
    }
    ~ECP((ECP *)aPStack_134);
    return;
  }
  ProjectiveDoubling::ProjectiveDoubling
            (aPStack_134,*(ModularArithmetic **)(this + 8),(Integer *)(this + 0xc),
             (Integer *)(this + 0x24),param_2);
  local_3c = (ProjectivePoint *)0x0;
  local_38 = (ProjectivePoint *)0x0;
  local_34 = (ProjectivePoint *)0x0;
  local_54 = (Integer *)0x0;
  local_50 = (Integer *)0x0;
  local_4c = (Integer *)0x0;
  if (param_4 != 0) {
    local_188 = &local_4c;
    local_18c = (Integer **)0x0;
    if (0x3ffffff < param_4) {
      this_00 = (logic_error *)__cxa_allocate_exception(8);
      std::logic_error::logic_error
                (this_00,"allocator<T>::allocate(size_t n) \'n\' exceeds maximum supported size");
      *(undefined ***)this_00 = &PTR__domain_error_014d8664;
                    /* WARNING: Subroutine does not return */
      __cxa_throw(this_00,&std::length_error::typeinfo,std::domain_error::~domain_error);
    }
    local_54 = operator_new(param_4 << 6);
    local_4c = local_54 + param_4 * 0x40;
    local_194 = (undefined **)0x0;
    local_190 = (Integer **)0x0;
    local_18c = (Integer **)0x0;
    local_198 = (undefined **)0x0;
    local_50 = local_54;
    std::__ndk1::
    __split_buffer<CryptoPP::WindowSlider,std::__ndk1::allocator<CryptoPP::WindowSlider>&>::
    ~__split_buffer((__split_buffer<CryptoPP::WindowSlider,std::__ndk1::allocator<CryptoPP::WindowSlider>&>
                     *)&local_198);
  }
  local_140 = (undefined4 *)0x0;
  local_13c = (undefined4 *)0x0;
  local_138 = (undefined4 *)0x0;
  if (param_4 != 0) {
    local_140 = operator_new(param_4 * 0xc);
    puVar27 = local_140 + param_4 * 3;
    local_138 = puVar27;
    __aeabi_memclr4(local_140,param_4 * 0xc);
    local_13c = puVar27;
  }
  puVar27 = (undefined4 *)0x0;
  local_14c = (undefined4 *)0x0;
  local_148 = (undefined4 *)0x0;
  local_144 = (undefined4 *)0x0;
  if (param_4 == 0) {
    local_1a8 = (undefined4 *)0x0;
  }
  else {
    local_1a8 = operator_new(param_4 * 0xc);
    local_14c = local_1a8;
    local_144 = local_1a8 + param_4 * 3;
    __aeabi_memclr4(local_1a8,param_4 * 0xc);
    local_148 = local_1a8 + param_4 * 3;
  }
  puVar2 = local_148;
  local_158 = (undefined4 *)0x0;
  local_154 = (undefined4 *)0x0;
  local_150 = (undefined4 *)0x0;
  if (param_4 == 0) {
    local_1b0 = (undefined4 *)0x0;
  }
  else {
    local_158 = operator_new(param_4 * 0xc);
    puVar27 = local_158 + param_4 * 3;
    local_150 = puVar27;
    __aeabi_memclr4(local_158,param_4 * 0xc);
    uVar25 = 0;
    local_154 = puVar27;
    do {
      bVar9 = (bool)(**(code **)(*(int *)this + 0x18))(this);
      WindowSlider::WindowSlider((WindowSlider *)&local_198,param_3,bVar9,5);
      pIVar24 = local_50;
      if (local_50 < local_4c) {
        Integer::Integer(local_50,(Integer *)&local_198);
        Integer::Integer(pIVar24 + 0x18,(Integer *)&local_180);
        *(undefined4 *)(pIVar24 + 0x30) = local_168;
        *(uint *)(pIVar24 + 0x34) = local_164;
        *(undefined4 *)(pIVar24 + 0x38) = uStack_160;
        *(undefined4 *)(pIVar24 + 0x3c) = uStack_15c;
        local_50 = local_50 + 0x40;
      }
      else {
        std::__ndk1::vector<CryptoPP::WindowSlider,std::__ndk1::allocator<CryptoPP::WindowSlider>>::
        __push_back_slow_path<CryptoPP::WindowSlider>
                  ((vector<CryptoPP::WindowSlider,std::__ndk1::allocator<CryptoPP::WindowSlider>> *)
                   &local_54,(WindowSlider *)&local_198);
      }
      pvVar14 = local_174;
      if (local_178 < local_174) {
        pvVar14 = local_178;
      }
      if (pvVar14 != (void *)0x0) {
        iVar11 = (int)pvVar14 + 1;
        do {
          *(undefined4 *)((int)local_170 + iVar11 * 4 + -8) = 0;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 1);
      }
      local_180 = &PTR__Integer_014c27a8;
      UnalignedDeallocate(local_170);
      ppIVar17 = local_18c;
      if (local_190 < local_18c) {
        ppIVar17 = local_190;
      }
      if (ppIVar17 != (Integer **)0x0) {
        iVar11 = (int)ppIVar17 + 1;
        do {
          local_188[iVar11 + -2] = (Integer *)0x0;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 1);
      }
      local_198 = &PTR__Integer_014c27a8;
      UnalignedDeallocate(local_188);
      WindowSlider::FindNextWindow((WindowSlider *)(local_54 + uVar25 * 0x40));
      puVar7 = local_140;
      puVar6 = local_14c;
      puVar5 = local_158;
      uVar25 = uVar25 + 1;
      param_3 = param_3 + 0x18;
    } while (uVar25 < param_4);
    local_1b0 = local_158;
    local_1a8 = local_14c;
    if (param_4 != 0) {
      local_1b0 = local_158;
      pIVar24 = (Integer *)0x0;
      local_158 = puVar5;
      do {
        iVar13 = 0;
        iVar11 = 0;
        uVar25 = 0;
        bVar10 = false;
        bVar9 = false;
        do {
          pIVar16 = local_54 + iVar11;
          pIVar1 = pIVar16 + 0x3f;
          if (*pIVar1 == (Integer)0x0) {
            pIVar16 = *(Integer **)(pIVar16 + 0x34);
          }
          if (*pIVar1 == (Integer)0x0 && pIVar24 == pIVar16) {
            if (!bVar10) {
              if (local_38 == local_34) {
                std::__ndk1::
                vector<CryptoPP::ProjectivePoint,std::__ndk1::allocator<CryptoPP::ProjectivePoint>>
                ::__push_back_slow_path<CryptoPP::ProjectivePoint_const&>
                          ((vector<CryptoPP::ProjectivePoint,std::__ndk1::allocator<CryptoPP::ProjectivePoint>>
                            *)&local_3c,aPStack_130);
              }
              else {
                ProjectivePoint::ProjectivePoint(local_38,aPStack_130);
                local_38 = local_38 + 0x48;
              }
            }
            pvVar12 = (vector<unsigned_int,std::__ndk1::allocator<unsigned_int>> *)
                      ((int)puVar5 + iVar13);
            puVar18 = *(uint **)(pvVar12 + 4);
            if (puVar18 == *(uint **)(pvVar12 + 8)) {
              std::__ndk1::vector<unsigned_int,std::__ndk1::allocator<unsigned_int>>::
              __push_back_slow_path<unsigned_int_const&>(pvVar12,(uint *)(local_54 + iVar11 + 0x38))
              ;
            }
            else {
              *puVar18 = *(uint *)(local_54 + iVar11 + 0x38);
              *(uint **)(pvVar12 + 4) = puVar18 + 1;
            }
            local_198 = (undefined **)(((int)local_38 - (int)local_3c >> 3) * 0x38e38e39 + -1);
            pvVar12 = (vector<unsigned_int,std::__ndk1::allocator<unsigned_int>> *)
                      ((int)puVar7 + iVar13);
            piVar19 = *(int **)(pvVar12 + 4);
            if (piVar19 < *(int **)(pvVar12 + 8)) {
              *piVar19 = (int)local_198;
              *(int **)(pvVar12 + 4) = piVar19 + 1;
            }
            else {
              std::__ndk1::vector<unsigned_int,std::__ndk1::allocator<unsigned_int>>::
              __push_back_slow_path<unsigned_int>(pvVar12,(uint *)&local_198);
            }
            pIVar1 = local_54;
            iVar23 = (int)puVar6 + iVar13;
            uVar26 = *(uint *)(iVar23 + 4);
            iVar20 = *(int *)(iVar23 + 8);
            if (uVar26 == iVar20 * 0x20) {
              if ((int)(uVar26 + 1) < 0) {
                    /* WARNING: Subroutine does not return */
                std::__ndk1::__vector_base_common<true>::__throw_length_error();
              }
              if (uVar26 < 0x3fffffff) {
                uVar26 = uVar26 + 0x20 & 0xffffffe0;
                if (uVar26 <= (uint)(iVar20 * 0x40)) {
                  uVar26 = iVar20 << 6;
                }
              }
              else {
                uVar26 = 0x7fffffff;
              }
              FUN_00d3def0(iVar23,uVar26);
              uVar26 = *(uint *)(iVar23 + 4);
            }
            *(uint *)(iVar23 + 4) = uVar26 + 1;
            iVar20 = *(int *)((int)puVar6 + iVar13);
            uVar21 = 1 << (uVar26 & 0x1f);
            uVar22 = *(uint *)(iVar20 + (uVar26 >> 5) * 4);
            if (pIVar1[iVar11 + 0x3d] == (Integer)0x0) {
              uVar22 = uVar22 & ~uVar21;
            }
            else {
              uVar22 = uVar21 | uVar22;
            }
            *(uint *)(iVar20 + (uVar26 >> 5) * 4) = uVar22;
            WindowSlider::FindNextWindow((WindowSlider *)(local_54 + iVar11));
            bVar10 = true;
            if (!bVar9) goto LAB_0136cd68;
LAB_0136cc68:
            bVar9 = true;
          }
          else {
            if (bVar9) goto LAB_0136cc68;
LAB_0136cd68:
            bVar9 = local_54[iVar11 + 0x3f] == (Integer)0x0;
          }
          uVar25 = uVar25 + 1;
          iVar13 = iVar13 + 0xc;
          iVar11 = iVar11 + 0x40;
        } while (uVar25 < param_4);
        if (!bVar9) break;
        ProjectiveDoubling::Double(aPStack_134);
        pIVar24 = pIVar24 + 1;
      } while (param_4 != 0);
    }
  }
  ParallelInvert<CryptoPP::Integer,CryptoPP::ZIterator>(*(undefined4 *)(this + 8),local_3c,local_38)
  ;
  if (local_38 != local_3c) {
    uVar25 = 0;
    iVar11 = 0x30;
    do {
      iVar13 = Integer::operator!((Integer *)(local_3c + iVar11));
      if (iVar13 == 0) {
        pIVar24 = (Integer *)
                  (**(code **)(**(int **)(this + 8) + 0x40))
                            (*(int **)(this + 8),local_3c + iVar11 + -0x18);
        Integer::operator=((Integer *)(local_3c + iVar11 + -0x18),pIVar24);
        pIVar24 = (Integer *)
                  (**(code **)(**(int **)(this + 8) + 0x48))(*(int **)(this + 8),local_3c + iVar11);
        Integer::operator=((Integer *)(local_3c + iVar11),pIVar24);
        pIVar24 = (Integer *)
                  (**(code **)(**(int **)(this + 8) + 0x40))
                            (*(int **)(this + 8),local_3c + iVar11 + -0x30);
        Integer::operator=((Integer *)(local_3c + iVar11 + -0x30),pIVar24);
        pIVar24 = (Integer *)
                  (**(code **)(**(int **)(this + 8) + 0x40))
                            (*(int **)(this + 8),local_3c + iVar11 + -0x18);
        Integer::operator=((Integer *)(local_3c + iVar11 + -0x18),pIVar24);
      }
      iVar11 = iVar11 + 0x48;
      uVar25 = uVar25 + 1;
    } while (uVar25 < (uint)(((int)local_38 - (int)local_3c >> 3) * 0x38e38e39));
  }
  puVar5 = local_140;
  local_1a4 = (ECPPoint *)0x0;
  local_1a0 = (ECPPoint *)0x0;
  local_19c = 0;
  if (param_4 != 0) {
    uVar25 = 0;
    do {
      piVar19 = puVar5 + uVar25 * 3;
      std::__ndk1::
      vector<CryptoPP::BaseAndExponent<CryptoPP::ECPPoint,CryptoPP::Integer>,std::__ndk1::allocator<CryptoPP::BaseAndExponent<CryptoPP::ECPPoint,CryptoPP::Integer>>>
      ::resize((vector<CryptoPP::BaseAndExponent<CryptoPP::ECPPoint,CryptoPP::Integer>,std::__ndk1::allocator<CryptoPP::BaseAndExponent<CryptoPP::ECPPoint,CryptoPP::Integer>>>
                *)&local_1a4,piVar19[1] - puVar5[uVar25 * 3] >> 2);
      if (piVar19[1] != puVar5[uVar25 * 3]) {
        uVar26 = 0;
        do {
          pIVar24 = (Integer *)(local_3c + *(int *)(*piVar19 + uVar26 * 4) * 0x48);
          iVar11 = Integer::operator!(pIVar24 + 0x30);
          if (iVar11 == 0) {
            local_1a4[uVar26 * 0x50 + 0x34] = (ECPPoint)0x0;
            Integer::operator=((Integer *)(local_1a4 + uVar26 * 0x50 + 4),pIVar24);
            if ((*(uint *)(local_1a8[uVar25 * 3] + (uVar26 >> 5) * 4) & 1 << (uVar26 & 0x1f)) == 0)
            {
              Integer::operator=((Integer *)(local_1a4 + uVar26 * 0x50 + 0x1c),pIVar24 + 0x18);
            }
            else {
              pIVar24 = (Integer *)
                        (**(code **)(**(int **)(this + 8) + 0x14))
                                  (*(int **)(this + 8),pIVar24 + 0x18);
              Integer::operator=((Integer *)(local_1a4 + uVar26 * 0x50 + 0x1c),pIVar24);
            }
          }
          else {
            local_1a4[uVar26 * 0x50 + 0x34] = (ECPPoint)0x1;
          }
          Integer::Integer((Integer *)&local_198,0,0,
                           *(undefined4 *)(local_1b0[uVar25 * 3] + uVar26 * 4));
          Integer::operator=((Integer *)(local_1a4 + uVar26 * 0x50 + 0x38),(Integer *)&local_198);
          local_198 = &PTR__Integer_014c27a8;
          ppIVar17 = local_18c;
          if (local_190 < local_18c) {
            ppIVar17 = local_190;
          }
          if (ppIVar17 != (Integer **)0x0) {
            iVar11 = (int)ppIVar17 + 1;
            do {
              local_188[iVar11 + -2] = (Integer *)0x0;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 1);
          }
          UnalignedDeallocate(local_188);
          uVar26 = uVar26 + 1;
        } while (uVar26 < (uint)(piVar19[1] - *piVar19 >> 2));
      }
      GeneralCascadeMultiplication<CryptoPP::ECPPoint,std::__ndk1::__wrap_iter<CryptoPP::BaseAndExponent<CryptoPP::ECPPoint,CryptoPP::Integer>*>>
                ((CryptoPP *)&local_198,this,local_1a4,local_1a0);
      Integer::operator=((Integer *)(param_1 + uVar25 * 0x38 + 4),(Integer *)&local_194);
      Integer::operator=((Integer *)(param_1 + uVar25 * 0x38 + 0x1c),(Integer *)&local_17c);
      param_1[uVar25 * 0x38 + 0x34] = local_164._0_1_;
      local_17c = &PTR__Integer_014c27a8;
      local_198 = &PTR__ECPPoint_014cd268;
      pvVar14 = local_170;
      if (local_174 < local_170) {
        pvVar14 = local_174;
      }
      if (pvVar14 != (void *)0x0) {
        iVar11 = (int)pvVar14 + 1;
        do {
          *(undefined4 *)((int)local_16c + iVar11 * 4 + -8) = 0;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 1);
      }
      UnalignedDeallocate(local_16c);
      local_194 = &PTR__Integer_014c27a8;
      ppIVar17 = local_188;
      if (local_18c < local_188) {
        ppIVar17 = local_18c;
      }
      if (ppIVar17 != (Integer **)0x0) {
        iVar11 = (int)ppIVar17 + 1;
        do {
          *(undefined4 *)((int)local_184 + iVar11 * 4 + -8) = 0;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 1);
      }
      UnalignedDeallocate(local_184);
      pEVar3 = local_1a4;
      uVar25 = uVar25 + 1;
    } while (uVar25 < param_4);
    pEVar4 = local_1a0;
    if (local_1a4 != (ECPPoint *)0x0) {
      while (pEVar4 != pEVar3) {
        pvVar14 = *(void **)(pEVar4 + -8);
        *(undefined ***)(pEVar4 + -0x18) = &PTR__Integer_014c27a8;
        uVar25 = *(uint *)(pEVar4 + -0xc);
        if (*(uint *)(pEVar4 + -0x10) < *(uint *)(pEVar4 + -0xc)) {
          uVar25 = *(uint *)(pEVar4 + -0x10);
        }
        if (uVar25 != 0) {
          iVar11 = uVar25 + 1;
          do {
            *(undefined4 *)((int)pvVar14 + iVar11 * 4 + -8) = 0;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 1);
        }
        UnalignedDeallocate(pvVar14);
        ECPPoint::~ECPPoint(pEVar4 + -0x50);
        pEVar4 = pEVar4 + -0x50;
      }
      local_1a0 = pEVar3;
      operator_delete(local_1a4);
    }
  }
  if (local_1b0 != (undefined4 *)0x0) {
    while (puVar5 = puVar27, puVar5 != local_1b0) {
      puVar27 = puVar5 + -3;
      pvVar14 = (void *)*puVar27;
      if (pvVar14 != (void *)0x0) {
        puVar5[-2] = pvVar14;
        operator_delete(pvVar14);
      }
    }
    local_154 = local_1b0;
    operator_delete(local_1b0);
  }
  if (local_1a8 != (undefined4 *)0x0) {
    while (puVar2 != local_1a8) {
      puVar2 = puVar2 + -3;
      if ((void *)*puVar2 != (void *)0x0) {
        operator_delete((void *)*puVar2);
      }
    }
    local_148 = local_1a8;
    operator_delete(local_1a8);
  }
  puVar2 = local_140;
  puVar27 = local_13c;
  if (local_140 != (undefined4 *)0x0) {
    while (puVar5 = puVar27, puVar5 != puVar2) {
      puVar27 = puVar5 + -3;
      pvVar14 = (void *)*puVar27;
      if (pvVar14 != (void *)0x0) {
        puVar5[-2] = pvVar14;
        operator_delete(pvVar14);
      }
    }
    local_13c = puVar2;
    operator_delete(local_140);
  }
  std::__ndk1::__vector_base<CryptoPP::WindowSlider,std::__ndk1::allocator<CryptoPP::WindowSlider>>
  ::~__vector_base((__vector_base<CryptoPP::WindowSlider,std::__ndk1::allocator<CryptoPP::WindowSlider>>
                    *)&local_54);
  pPVar8 = local_3c;
  pPVar15 = local_38;
  if (local_3c != (ProjectivePoint *)0x0) {
    for (; pPVar15 != pPVar8;
        pPVar15 = (ProjectivePoint *)ProjectivePoint::~ProjectivePoint(pPVar15 + -0x48)) {
    }
    local_38 = pPVar8;
    operator_delete(local_3c);
  }
  ProjectiveDoubling::~ProjectiveDoubling(aPStack_134);
  return;
}


