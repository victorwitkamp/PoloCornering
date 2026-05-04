/* VagOperationDelegate::runAdaptSettingAndLiveDataDebugCommands @ 0127a858 */


/* VagOperationDelegate::runAdaptSettingAndLiveDataDebugCommands(std::__ndk1::shared_ptr<Setting>,
   Ecu*, std::__ndk1::unordered_set<unsigned char, std::__ndk1::hash<unsigned char>,
   std::__ndk1::equal_to<unsigned char>, std::__ndk1::allocator<unsigned char> >&,
   std::__ndk1::unordered_set<unsigned char, std::__ndk1::hash<unsigned char>,
   std::__ndk1::equal_to<unsigned char>, std::__ndk1::allocator<unsigned char> >&,
   std::__ndk1::unordered_set<unsigned short, std::__ndk1::hash<unsigned short>,
   std::__ndk1::equal_to<unsigned short>, std::__ndk1::allocator<unsigned short> >&, DebugData&,
   std::__ndk1::shared_ptr<Progress> const&) */

void __thiscall
VagOperationDelegate::runAdaptSettingAndLiveDataDebugCommands
          (VagOperationDelegate *this,int *param_2,Ecu *param_3,
          __hash_table<unsigned_char,std::__ndk1::hash<unsigned_char>,std::__ndk1::equal_to<unsigned_char>,std::__ndk1::allocator<unsigned_char>>
          *param_4,__hash_table<unsigned_char,std::__ndk1::hash<unsigned_char>,std::__ndk1::equal_to<unsigned_char>,std::__ndk1::allocator<unsigned_char>>
                   *param_5,
          __hash_table<unsigned_short,std::__ndk1::hash<unsigned_short>,std::__ndk1::equal_to<unsigned_short>,std::__ndk1::allocator<unsigned_short>>
          *param_6,DebugData *param_7,undefined4 param_8)

{
  byte bVar1;
  uchar uVar2;
  int *piVar3;
  Ecu *pEVar4;
  uint uVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  ByteUtils local_ac [12];
  undefined4 local_a0;
  undefined4 uStack_9c;
  int *local_84;
  Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
  local_7c;
  uchar local_7b;
  ByteUtils aBStack_58 [36];
  ByteUtils aBStack_34 [12];
  int local_28;
  
  local_28 = __stack_chk_guard;
  piVar3 = (int *)*param_2;
  if ((short)piVar3[5] != 0) {
    bVar1 = *(byte *)(piVar3 + 3);
    pEVar4 = (Ecu *)(**(code **)(*piVar3 + 0x14))();
    if ((bVar1 < 2) && (pEVar4 == param_3)) {
      uVar2 = Math::toExact<unsigned_char,unsigned_short>(*(ushort *)(*param_2 + 0x14));
      local_a0 = CONCAT31(local_a0._1_3_,uVar2);
      uVar5 = std::__ndk1::
              __hash_table<unsigned_char,std::__ndk1::hash<unsigned_char>,std::__ndk1::equal_to<unsigned_char>,std::__ndk1::allocator<unsigned_char>>
              ::__count_unique<unsigned_char>(param_4,(uchar *)&local_a0);
      if (uVar5 == 0) {
        if (*(int *)(*param_2 + 0x38) != 0) {
          local_a0 = 0;
          uStack_9c = 0;
          (**(code **)(*(int *)this + 0x128))(this,param_3,*(int *)(*param_2 + 0x38),&local_a0);
          FUN_011e01a0(&local_a0);
          iVar6 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
          if (iVar6 != 0) {
            Log::e("Failed to unlock UDS sec access; skipping...");
            goto LAB_0127aba0;
          }
        }
        uVar8 = (**(code **)(*(int *)this + 0x148))(this,param_2);
        (**(code **)(*(int *)this + 0x1a4))
                  (&local_a0,this,(int)uVar8,(int)((ulonglong)uVar8 >> 0x20));
        local_7c = (Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
                    )Math::toExact<unsigned_char,unsigned_short>(*(ushort *)(*param_2 + 0x14));
        FUN_0127ac44(aBStack_58,param_4,&local_7c);
        iVar6 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
        if (iVar6 == 0) {
          Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
          ::Result((Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
                    *)aBStack_58);
          iVar6 = Result<BytesModel,void>::isFail((Result<BytesModel,void> *)&local_a0);
          if (iVar6 == 0) {
            ByteUtils::getHexString(aBStack_34,(vector *)(*local_84 + 4));
            FUN_00d22d0c(local_ac,aBStack_34,1);
            Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
            ::
            done<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>>
                      ((type *)&local_7c);
            Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
            ::operator=((Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
                         *)aBStack_58,(Result *)&local_7c);
            Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
            ::~Result(&local_7c);
            FUN_00cbe2dc(local_ac);
            std::__ndk1::
            basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
            ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                           *)aBStack_34);
          }
          else {
            Result<BytesModel,void>::
            stateAs<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
                      ();
            Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
            ::operator=((Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
                         *)aBStack_58,(Result *)&local_7c);
            Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
            ::~Result(&local_7c);
          }
          puVar7 = LONGADAPT_STR;
          if (bVar1 == 0) {
            puVar7 = ADAPT_STR;
          }
          uVar2 = Math::toExact<unsigned_char,unsigned_short>(*(ushort *)(*param_2 + 0x14));
          ByteUtils::getHexString(local_ac,uVar2);
          FUN_00d55d84(&local_7c,puVar7,local_ac);
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)local_ac);
          DebugData::addResult(param_7,param_3,(basic_string *)&local_7c,(Result *)aBStack_58);
          std::__ndk1::
          basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
          ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)&local_7c);
          Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
          ::~Result((Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
                     *)aBStack_58);
        }
        Result<BytesModel,void>::~Result((Result<BytesModel,void> *)&local_a0);
      }
    }
    else if (bVar1 == 6 && pEVar4 == param_3) {
      uVar2 = Math::toExact<unsigned_char,unsigned_short>(*(ushort *)(*param_2 + 0x14));
      local_a0 = CONCAT31(local_a0._1_3_,uVar2);
      uVar5 = std::__ndk1::
              __hash_table<unsigned_char,std::__ndk1::hash<unsigned_char>,std::__ndk1::equal_to<unsigned_char>,std::__ndk1::allocator<unsigned_char>>
              ::__count_unique<unsigned_char>(param_5,(uchar *)&local_a0);
      if (uVar5 == 0) {
        ByteUtils::getBytesFromShort(aBStack_58,*(ushort *)(*param_2 + 0x14));
        ByteUtils::subrange((ByteUtils *)&local_a0,(vector *)aBStack_58,1,0xffffffff);
        FUN_00cb7f50(aBStack_58);
        local_7c = (Result<std::__ndk1::vector<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>,std::__ndk1::allocator<std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>>>,void>
                    )0x21;
        local_7b = Math::toExact<unsigned_char,unsigned_short>(*(ushort *)(*param_2 + 0x14));
        FUN_00cdb87c(aBStack_58,&local_7c,2);
        (**(code **)(*(int *)this + 0x170))(this,param_3,aBStack_58,1,param_7,param_8);
        iVar6 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
        if (iVar6 == 0) {
          local_ac[0] = (ByteUtils)
                        Math::toExact<unsigned_char,unsigned_short>(*(ushort *)(*param_2 + 0x14));
          FUN_0127ac44(&local_7c,param_5,local_ac);
          FUN_00cb7f50(aBStack_58);
          FUN_00cb7f50(&local_a0);
        }
        else {
          FUN_00cb7f50(aBStack_58);
          FUN_00cb7f50(&local_a0);
        }
      }
    }
    else if ((bVar1 == 7 && pEVar4 == param_3) &&
            (uVar5 = std::__ndk1::
                     __hash_table<unsigned_short,std::__ndk1::hash<unsigned_short>,std::__ndk1::equal_to<unsigned_short>,std::__ndk1::allocator<unsigned_short>>
                     ::__count_unique<unsigned_short>(param_6,(ushort *)(*param_2 + 0x14)),
            uVar5 == 0)) {
      iVar6 = *param_2;
      if (*(int *)(iVar6 + 0x38) != 0) {
        local_a0 = 0;
        uStack_9c = 0;
        (**(code **)(*(int *)this + 0x128))(this,param_3,*(int *)(iVar6 + 0x38),&local_a0);
        FUN_011e01a0(&local_a0);
        iVar6 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
        if (iVar6 != 0) {
          Log::e("Failed to unlock UDS sec access; skipping...");
          goto LAB_0127aba0;
        }
        iVar6 = *param_2;
      }
      ByteUtils::getBytesFromShort(aBStack_58,*(ushort *)(iVar6 + 0x14));
      _ZplIhTnPNSt6__ndk19enable_ifIXsr7is_sameIhT_EE5valueES2_E4typeELPh0EENS0_6vectorIhNS0_9allocatorIhEEEES2_OSA_
                (&local_a0,0x22,aBStack_58);
      FUN_00cb7f50(aBStack_58);
      (**(code **)(*(int *)this + 0x170))(this,param_3,&local_a0,1,param_7,param_8);
      iVar6 = State::Set::contains((int)OperationDelegate::DEBUG_DATA_GIVE_UP_ECU_STATES);
      if (iVar6 == 0) {
        FUN_00d155ac(aBStack_58,param_6,*param_2 + 0x14);
      }
      FUN_00cb7f50(&local_a0);
    }
  }
LAB_0127aba0:
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_28);
  }
  return;
}


