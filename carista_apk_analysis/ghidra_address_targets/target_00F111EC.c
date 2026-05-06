/* Target address 00f111ec */
/* Function _INIT_116 @ 00f111ec */


void _INIT_116(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined1 uStack_71;
  undefined8 local_70;
  undefined4 local_68;
  int iStack_64;
  undefined1 uStack_60;
  undefined1 uStack_5f;
  undefined2 uStack_5e;
  int iStack_5c;
  undefined4 local_58;
  int iStack_54;
  undefined4 local_4c;
  undefined4 local_48;
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> abStack_40 [12];
  vector avStack_34 [12];
  int local_28;
  
  local_28 = __stack_chk_guard;
  FUN_00cb4d44(abStack_40,&DAT_00ad5a21);
  FUN_00d22d0c(avStack_34,abStack_40,1);
  local_70 = 0x3008060504030200;
  local_68 = 0x38343332;
  iStack_64 = 0x62524442;
  uStack_60 = 0x72;
  uStack_5f = 0xa3;
  uStack_5e = 0xb2b1;
  iStack_5c = CONCAT31(iStack_5c._1_3_,0xb3);
  FUN_00cdb87c(&local_4c,&local_70,0x15);
  NissanWhitelist::from((NissanWhitelist *)&NissanLiveData::WL_ABS,avStack_34,(vector *)&local_4c);
  FUN_00cb7f50(&local_4c);
  FUN_00cbe2dc(avStack_34);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string(abStack_40);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_ABS,&DAT_014371d0);
  FUN_00cb4d44(avStack_34,&DAT_00ad5a21);
  FUN_00d22d0c(&local_70,avStack_34,1);
  local_4c._0_2_ = 0xa000;
  FUN_00cdb87c(abStack_40,&local_4c,2);
  NissanWhitelist::from
            ((NissanWhitelist *)&NissanLiveData::WL_ECM_CAN_ECCS_DOC3,(vector *)&local_70,
             (vector *)abStack_40);
  FUN_00cb7f50(abStack_40);
  FUN_00cbe2dc(&local_70);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                avStack_34);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_ECM_CAN_ECCS_DOC3,&DAT_014371d0);
  FUN_00cb4d44(avStack_34,&DAT_00ad5a21);
  FUN_00d22d0c(&local_70,avStack_34,1);
  local_4c = CONCAT22(local_4c._2_2_,0x6160);
  FUN_00cdb87c(abStack_40,&local_4c,2);
  NissanWhitelist::from
            ((NissanWhitelist *)&NissanLiveData::WL_ECM_CAN_ECCS_K4M,(vector *)&local_70,
             (vector *)abStack_40);
  FUN_00cb7f50(abStack_40);
  FUN_00cbe2dc(&local_70);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                avStack_34);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_ECM_CAN_ECCS_K4M,&DAT_014371d0);
  FUN_00cb4d44(avStack_34,&DAT_00ad5a21);
  FUN_00d22d0c(&local_70,avStack_34,1);
  local_4c = CONCAT31(local_4c._1_3_,0x80);
  FUN_00cdb87c(abStack_40,&local_4c,1);
  NissanWhitelist::from
            ((NissanWhitelist *)&NissanLiveData::WL_ECM_CAN_ECCS_D4D,(vector *)&local_70,
             (vector *)abStack_40);
  FUN_00cb7f50(abStack_40);
  FUN_00cbe2dc(&local_70);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                avStack_34);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_ECM_CAN_ECCS_D4D,&DAT_014371d0);
  FUN_00cb4d44(avStack_34,&DAT_00ad5a21);
  FUN_00d22d0c(&local_70,avStack_34,1);
  local_48 = CONCAT22(local_48._2_2_,0xd5d4);
  local_4c = 0xd3d1d001;
  FUN_00cdb87c(abStack_40,&local_4c,6);
  NissanWhitelist::from
            ((NissanWhitelist *)&NissanLiveData::WL_ECM_UDS_ECCS,(vector *)&local_70,
             (vector *)abStack_40);
  FUN_00cb7f50(abStack_40);
  FUN_00cbe2dc(&local_70);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                avStack_34);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_ECM_UDS_ECCS,&DAT_014371d0);
  FUN_00cb4d44(avStack_34,&DAT_00ad5a21);
  FUN_00d22d0c(&local_70,avStack_34,1);
  local_4c = CONCAT13(local_4c._3_1_,0x460000);
  local_4c._0_2_ = 0x4543;
  FUN_00cdb87c(abStack_40,&local_4c,3);
  NissanWhitelist::from
            ((NissanWhitelist *)&NissanLiveData::WL_ECM_CAN_ED,(vector *)&local_70,
             (vector *)abStack_40);
  FUN_00cb7f50(abStack_40);
  FUN_00cbe2dc(&local_70);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                avStack_34);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_ECM_CAN_ED,&DAT_014371d0);
  FUN_00cb4d44(avStack_34,&DAT_00ad5a21);
  FUN_00d22d0c(&local_70,avStack_34,1);
  local_4c = CONCAT22(local_4c._2_2_,0x601);
  FUN_00cdb87c(abStack_40,&local_4c,2);
  NissanWhitelist::from
            ((NissanWhitelist *)&NissanLiveData::WL_ECM_CAN_ED1,(vector *)&local_70,
             (vector *)abStack_40);
  FUN_00cb7f50(abStack_40);
  FUN_00cbe2dc(&local_70);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                avStack_34);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_ECM_CAN_ED1,&DAT_014371d0);
  FUN_00cb4d44(avStack_34,&DAT_00ad5a21);
  FUN_00d22d0c(&local_70,avStack_34,1);
  local_4c = CONCAT13(local_4c._3_1_,0x50000);
  local_4c = CONCAT22(local_4c._2_2_,0x302);
  FUN_00cdb87c(abStack_40,&local_4c,3);
  NissanWhitelist::from
            ((NissanWhitelist *)&NissanLiveData::WL_ECM_CAN_ED3,(vector *)&local_70,
             (vector *)abStack_40);
  FUN_00cb7f50(abStack_40);
  FUN_00cbe2dc(&local_70);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                avStack_34);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_ECM_CAN_ED3,&DAT_014371d0);
  local_70 = CONCAT44(NissanLiveData::WL_ECM_CAN_ED1._4_4_,
                      (undefined4)NissanLiveData::WL_ECM_CAN_ED1);
  if (NissanLiveData::WL_ECM_CAN_ED1._4_4_ != 0) {
    piVar2 = (int *)(NissanLiveData::WL_ECM_CAN_ED1._4_4_ + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  local_68 = (undefined4)NissanLiveData::WL_ECM_CAN_ED3;
  iStack_64 = NissanLiveData::WL_ECM_CAN_ED3._4_4_;
  if (NissanLiveData::WL_ECM_CAN_ED3._4_4_ != 0) {
    piVar2 = (int *)(NissanLiveData::WL_ECM_CAN_ED3._4_4_ + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  NissanWhitelist::merge(&NissanLiveData::WL_ECM_CAN_ED1_ED3,&local_70,2);
  iVar3 = 8;
  do {
    FUN_00f0a196((int)&local_70 + iVar3);
    iVar3 = iVar3 + -8;
  } while (iVar3 != -8);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_ECM_CAN_ED1_ED3,&DAT_014371d0);
  FUN_00cb4d44(avStack_34,&DAT_00ad5a21);
  FUN_00d22d0c(&local_70,avStack_34,1);
  local_4c._0_2_ = 0x7170;
  FUN_00cdb87c(abStack_40,&local_4c,2);
  NissanWhitelist::from
            ((NissanWhitelist *)&NissanLiveData::WL_ECM_CAN_ED4,(vector *)&local_70,
             (vector *)abStack_40);
  FUN_00cb7f50(abStack_40);
  FUN_00cbe2dc(&local_70);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                avStack_34);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_ECM_CAN_ED4,&DAT_014371d0);
  FUN_00cb4d44(avStack_34,&DAT_00ad5a21);
  FUN_00d22d0c(&local_70,avStack_34,1);
  local_4c._0_2_ = 0x6c21;
  FUN_00cdb87c(abStack_40,&local_4c,2);
  NissanWhitelist::from
            ((NissanWhitelist *)&NissanLiveData::WL_ECM_CAN_ED5,(vector *)&local_70,
             (vector *)abStack_40);
  FUN_00cb7f50(abStack_40);
  FUN_00cbe2dc(&local_70);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                avStack_34);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_ECM_CAN_ED5,&DAT_014371d0);
  FUN_00cb4d44(avStack_34,&DAT_00ad5a21);
  FUN_00d22d0c(&local_70,avStack_34,1);
  local_4c = CONCAT22(local_4c._2_2_,0x4431);
  FUN_00cdb87c(abStack_40,&local_4c,2);
  NissanWhitelist::from
            ((NissanWhitelist *)&NissanLiveData::WL_ECM_CAN_ED6,(vector *)&local_70,
             (vector *)abStack_40);
  FUN_00cb7f50(abStack_40);
  FUN_00cbe2dc(&local_70);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                avStack_34);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_ECM_CAN_ED6,&DAT_014371d0);
  local_70 = CONCAT44(NissanLiveData::WL_ECM_CAN_ED4._4_4_,
                      (undefined4)NissanLiveData::WL_ECM_CAN_ED4);
  if (NissanLiveData::WL_ECM_CAN_ED4._4_4_ != 0) {
    piVar2 = (int *)(NissanLiveData::WL_ECM_CAN_ED4._4_4_ + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  local_68 = (undefined4)NissanLiveData::WL_ECM_CAN_ED5;
  iStack_64 = NissanLiveData::WL_ECM_CAN_ED5._4_4_;
  if (NissanLiveData::WL_ECM_CAN_ED5._4_4_ != 0) {
    piVar2 = (int *)(NissanLiveData::WL_ECM_CAN_ED5._4_4_ + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  iStack_5c = NissanLiveData::WL_ECM_CAN_ED6._4_4_;
  uStack_60 = (undefined1)(undefined4)NissanLiveData::WL_ECM_CAN_ED6;
  uStack_5f = (undefined1)((uint)(undefined4)NissanLiveData::WL_ECM_CAN_ED6 >> 8);
  uStack_5e = (undefined2)((uint)(undefined4)NissanLiveData::WL_ECM_CAN_ED6 >> 0x10);
  if (NissanLiveData::WL_ECM_CAN_ED6._4_4_ != 0) {
    piVar2 = (int *)(NissanLiveData::WL_ECM_CAN_ED6._4_4_ + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  NissanWhitelist::merge(&NissanLiveData::WL_ECM_CAN_ED4_ED5_ED6,&local_70,3);
  iVar3 = 0x10;
  do {
    FUN_00f0a196((int)&local_70 + iVar3);
    iVar3 = iVar3 + -8;
  } while (iVar3 != -8);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_ECM_CAN_ED4_ED5_ED6,&DAT_014371d0);
  FUN_00cb4d44(avStack_34,&DAT_00ad5a21);
  FUN_00d22d0c(&local_70,avStack_34,1);
  local_4c = CONCAT31(local_4c._1_3_,0x47);
  FUN_00cdb87c(abStack_40,&local_4c,1);
  NissanWhitelist::from
            ((NissanWhitelist *)&NissanLiveData::WL_ECM_CAN_ED7,(vector *)&local_70,
             (vector *)abStack_40);
  FUN_00cb7f50(abStack_40);
  FUN_00cbe2dc(&local_70);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                avStack_34);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_ECM_CAN_ED7,&DAT_014371d0);
  FUN_00cb4d44(avStack_34,&DAT_00ad5a21);
  FUN_00d22d0c(&local_70,avStack_34,1);
  local_4c._0_2_ = 0x4e4b;
  FUN_00cdb87c(abStack_40,&local_4c,2);
  NissanWhitelist::from
            ((NissanWhitelist *)&NissanLiveData::WL_ECM_CAN_ED_K9KGen5,(vector *)&local_70,
             (vector *)abStack_40);
  FUN_00cb7f50(abStack_40);
  FUN_00cbe2dc(&local_70);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                avStack_34);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_ECM_CAN_ED_K9KGen5,&DAT_014371d0);
  FUN_00cb4d44(avStack_34,&DAT_00ad5a21);
  FUN_00d22d0c(&local_70,avStack_34,1);
  local_4c = CONCAT22(local_4c._2_2_,0x4f4a);
  FUN_00cdb87c(abStack_40,&local_4c,2);
  NissanWhitelist::from
            ((NissanWhitelist *)&NissanLiveData::WL_ECM_CAN_ED_K9KGen6,(vector *)&local_70,
             (vector *)abStack_40);
  FUN_00cb7f50(abStack_40);
  FUN_00cbe2dc(&local_70);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                avStack_34);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_ECM_CAN_ED_K9KGen6,&DAT_014371d0);
  local_70 = CONCAT44(NissanLiveData::WL_ECM_CAN_ED._4_4_,(undefined4)NissanLiveData::WL_ECM_CAN_ED)
  ;
  if (NissanLiveData::WL_ECM_CAN_ED._4_4_ != 0) {
    piVar2 = (int *)(NissanLiveData::WL_ECM_CAN_ED._4_4_ + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  local_68 = (undefined4)NissanLiveData::WL_ECM_CAN_ED7;
  iStack_64 = NissanLiveData::WL_ECM_CAN_ED7._4_4_;
  if (NissanLiveData::WL_ECM_CAN_ED7._4_4_ != 0) {
    piVar2 = (int *)(NissanLiveData::WL_ECM_CAN_ED7._4_4_ + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  iStack_5c = NissanLiveData::WL_ECM_CAN_ED_K9KGen5._4_4_;
  uStack_60 = (undefined1)(undefined4)NissanLiveData::WL_ECM_CAN_ED_K9KGen5;
  uStack_5f = (undefined1)((uint)(undefined4)NissanLiveData::WL_ECM_CAN_ED_K9KGen5 >> 8);
  uStack_5e = (undefined2)((uint)(undefined4)NissanLiveData::WL_ECM_CAN_ED_K9KGen5 >> 0x10);
  if (NissanLiveData::WL_ECM_CAN_ED_K9KGen5._4_4_ != 0) {
    piVar2 = (int *)(NissanLiveData::WL_ECM_CAN_ED_K9KGen5._4_4_ + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  local_58 = (undefined4)NissanLiveData::WL_ECM_CAN_ED_K9KGen6;
  iStack_54 = NissanLiveData::WL_ECM_CAN_ED_K9KGen6._4_4_;
  if (NissanLiveData::WL_ECM_CAN_ED_K9KGen6._4_4_ != 0) {
    piVar2 = (int *)(NissanLiveData::WL_ECM_CAN_ED_K9KGen6._4_4_ + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  NissanWhitelist::merge(&NissanLiveData::WL_ECM_CAN_ED_ED7_K9KGen5_K9KGen6,&local_70,4);
  iVar3 = 0x18;
  do {
    FUN_00f0a196((int)&local_70 + iVar3);
    iVar3 = iVar3 + -8;
  } while (iVar3 != -8);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_ECM_CAN_ED_ED7_K9KGen5_K9KGen6,&DAT_014371d0);
  FUN_00cb4d44(avStack_34,&DAT_00ad5a21);
  FUN_00d22d0c(&local_70,avStack_34,1);
  local_48 = CONCAT31(local_48._1_3_,0xf2);
  local_4c = 0xf1f0cbca;
  FUN_00cdb87c(abStack_40,&local_4c,5);
  NissanWhitelist::from
            ((NissanWhitelist *)&NissanLiveData::WL_ECM_UDS_ED,(vector *)&local_70,
             (vector *)abStack_40);
  FUN_00cb7f50(abStack_40);
  FUN_00cbe2dc(&local_70);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                avStack_34);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_ECM_UDS_ED,&DAT_014371d0);
  local_70 = CONCAT44(NissanLiveData::WL_ECM_CAN_ECCS_DOC3._4_4_,
                      (undefined4)NissanLiveData::WL_ECM_CAN_ECCS_DOC3);
  if (NissanLiveData::WL_ECM_CAN_ECCS_DOC3._4_4_ != 0) {
    piVar2 = (int *)(NissanLiveData::WL_ECM_CAN_ECCS_DOC3._4_4_ + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  local_68 = (undefined4)NissanLiveData::WL_ECM_UDS_ECCS;
  iStack_64 = NissanLiveData::WL_ECM_UDS_ECCS._4_4_;
  if (NissanLiveData::WL_ECM_UDS_ECCS._4_4_ != 0) {
    piVar2 = (int *)(NissanLiveData::WL_ECM_UDS_ECCS._4_4_ + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  iStack_5c = NissanLiveData::WL_ECM_CAN_ED1_ED3._4_4_;
  uStack_60 = (undefined1)(undefined4)NissanLiveData::WL_ECM_CAN_ED1_ED3;
  uStack_5f = (undefined1)((uint)(undefined4)NissanLiveData::WL_ECM_CAN_ED1_ED3 >> 8);
  uStack_5e = (undefined2)((uint)(undefined4)NissanLiveData::WL_ECM_CAN_ED1_ED3 >> 0x10);
  if (NissanLiveData::WL_ECM_CAN_ED1_ED3._4_4_ != 0) {
    piVar2 = (int *)(NissanLiveData::WL_ECM_CAN_ED1_ED3._4_4_ + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  NissanWhitelist::merge(&NissanLiveData::WL_ECM_UDS_TYPE1,&local_70,3);
  iVar3 = 0x10;
  do {
    FUN_00f0a196((int)&local_70 + iVar3);
    iVar3 = iVar3 + -8;
  } while (iVar3 != -8);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_ECM_UDS_TYPE1,&DAT_014371d0);
  local_70 = CONCAT44(NissanLiveData::WL_ECM_CAN_ECCS_D4D._4_4_,
                      (undefined4)NissanLiveData::WL_ECM_CAN_ECCS_D4D);
  if (NissanLiveData::WL_ECM_CAN_ECCS_D4D._4_4_ != 0) {
    piVar2 = (int *)(NissanLiveData::WL_ECM_CAN_ECCS_D4D._4_4_ + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  local_68 = (undefined4)NissanLiveData::WL_ECM_CAN_ED_ED7_K9KGen5_K9KGen6;
  iStack_64 = NissanLiveData::WL_ECM_CAN_ED_ED7_K9KGen5_K9KGen6._4_4_;
  if (NissanLiveData::WL_ECM_CAN_ED_ED7_K9KGen5_K9KGen6._4_4_ != 0) {
    piVar2 = (int *)(NissanLiveData::WL_ECM_CAN_ED_ED7_K9KGen5_K9KGen6._4_4_ + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  iStack_5c = NissanLiveData::WL_ECM_UDS_ED._4_4_;
  uStack_60 = (undefined1)(undefined4)NissanLiveData::WL_ECM_UDS_ED;
  uStack_5f = (undefined1)((uint)(undefined4)NissanLiveData::WL_ECM_UDS_ED >> 8);
  uStack_5e = (undefined2)((uint)(undefined4)NissanLiveData::WL_ECM_UDS_ED >> 0x10);
  if (NissanLiveData::WL_ECM_UDS_ED._4_4_ != 0) {
    piVar2 = (int *)(NissanLiveData::WL_ECM_UDS_ED._4_4_ + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  NissanWhitelist::merge(&NissanLiveData::WL_ECM_UDS_TYPE2,&local_70,3);
  iVar3 = 0x10;
  do {
    FUN_00f0a196((int)&local_70 + iVar3);
    iVar3 = iVar3 + -8;
  } while (iVar3 != -8);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_ECM_UDS_TYPE2,&DAT_014371d0);
  FUN_00cb4d44(abStack_40,&DAT_00ad5a21);
  FUN_00d22d0c(avStack_34,abStack_40,1);
  local_70 = 0x4b4a474645210601;
  local_68 = 0xbfbe4f4e;
  iStack_64 = 0xf1f0cbca;
  uStack_60 = 0xf2;
  FUN_00cdb87c(&local_4c,&local_70,0x11);
  NissanWhitelist::from
            ((NissanWhitelist *)&NissanLiveData::WL_ECM_MILEAGE_2006,avStack_34,(vector *)&local_4c)
  ;
  FUN_00cb7f50(&local_4c);
  FUN_00cbe2dc(avStack_34);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string(abStack_40);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_ECM_MILEAGE_2006,&DAT_014371d0);
  FUN_00cb4d44(abStack_40,&DAT_00ad5a21);
  FUN_00d22d0c(avStack_34,abStack_40,1);
  local_70 = 0x1a19181514111000;
  local_68 = 0x2925241b;
  iStack_64 = 0x33322b2a;
  uStack_60 = 0x36;
  uStack_5f = 0x37;
  uStack_5e = 0x3938;
  iStack_5c = 0x4241403c;
  local_58 = 0x35544847;
  FUN_00cdb87c(&local_4c,&local_70,0x1c);
  NissanWhitelist::from
            ((NissanWhitelist *)&NissanLiveData::WL_HVAC_CAN,avStack_34,(vector *)&local_4c);
  FUN_00cb7f50(&local_4c);
  FUN_00cbe2dc(avStack_34);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string(abStack_40);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_HVAC_CAN,&DAT_014371d0);
  FUN_00cb4d44(avStack_34,&DAT_00ad5a21);
  FUN_00d22d0c(&local_70,avStack_34,1);
  local_48._0_1_ = 0x6b;
  local_4c = 0x66656260;
  FUN_00cdb87c(abStack_40,&local_4c,5);
  NissanWhitelist::from
            ((NissanWhitelist *)&NissanLiveData::WL_HVAC_UDS,(vector *)&local_70,
             (vector *)abStack_40);
  FUN_00cb7f50(abStack_40);
  FUN_00cbe2dc(&local_70);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                avStack_34);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_HVAC_UDS,&DAT_014371d0);
  FUN_00cb4d44(avStack_34,&DAT_00ad5a21);
  FUN_00d22d0c(&local_70,avStack_34,1);
  local_48 = CONCAT31(local_48._1_3_,0x5b);
  local_4c = 0x5a595857;
  FUN_00cdb87c(abStack_40,&local_4c,5);
  NissanWhitelist::from
            ((NissanWhitelist *)&NissanLiveData::WL_LBC_CAN,(vector *)&local_70,(vector *)abStack_40
            );
  FUN_00cb7f50(abStack_40);
  FUN_00cbe2dc(&local_70);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                avStack_34);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_LBC_CAN,&DAT_014371d0);
  local_70 = CONCAT44(NissanLiveData::WL_LBC_CAN._4_4_,(undefined4)NissanLiveData::WL_LBC_CAN);
  if (NissanLiveData::WL_LBC_CAN._4_4_ != 0) {
    piVar2 = (int *)(NissanLiveData::WL_LBC_CAN._4_4_ + 4);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
  }
  FUN_00cb4d44(abStack_40,&DAT_00ad5a21);
  FUN_00d22d0c(avStack_34,abStack_40,1);
  uStack_71 = 0x56;
  FUN_00cdb87c(&local_4c,&uStack_71,1);
  NissanWhitelist::from((NissanWhitelist *)&local_68,avStack_34,(vector *)&local_4c);
  NissanWhitelist::merge(&NissanLiveData::WL_LBC_CAN_ADD_VDIAG_56,&local_70,2);
  iVar3 = 8;
  do {
    FUN_00f0a196((int)&local_70 + iVar3);
    iVar3 = iVar3 + -8;
  } while (iVar3 != -8);
  FUN_00cb7f50(&local_4c);
  FUN_00cbe2dc(avStack_34);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string(abStack_40);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_LBC_CAN_ADD_VDIAG_56,&DAT_014371d0);
  FUN_00cb4d44(avStack_34,&DAT_00ad5a21);
  FUN_00d22d0c(&local_70,avStack_34,1);
  local_4c = CONCAT31(local_4c._1_3_,0x18);
  FUN_00cdb87c(abStack_40,&local_4c,1);
  NissanWhitelist::from
            ((NissanWhitelist *)&NissanLiveData::WL_TRANSMISION_UDS_DCT,(vector *)&local_70,
             (vector *)abStack_40);
  FUN_00cb7f50(abStack_40);
  FUN_00cbe2dc(&local_70);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                avStack_34);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_TRANSMISION_UDS_DCT,&DAT_014371d0);
  FUN_00cb4d44(abStack_40,&DAT_00ad5a21);
  FUN_00d22d0c(avStack_34,abStack_40,1);
  local_70 = 0x1716151413121110;
  local_68 = 0x1b1a1918;
  iStack_64 = 0x8281381c;
  uStack_60 = 0xc2;
  uStack_5f = 0xc3;
  FUN_00cdb87c(&local_4c,&local_70,0x12);
  NissanWhitelist::from
            ((NissanWhitelist *)&NissanLiveData::WL_INSTRUMENTS_ODOMETER_CAN,avStack_34,
             (vector *)&local_4c);
  FUN_00cb7f50(&local_4c);
  FUN_00cbe2dc(avStack_34);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string(abStack_40);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_INSTRUMENTS_ODOMETER_CAN,&DAT_014371d0);
  FUN_00cb4d44(avStack_34,&DAT_00ad5a21);
  FUN_00d22d0c(&local_70,avStack_34,1);
  local_48 = 0x54515027;
  local_4c = 0x24252220;
  FUN_00cdb87c(abStack_40,&local_4c,8);
  NissanWhitelist::from
            ((NissanWhitelist *)&NissanLiveData::WL_INSTRUMENTS_ODOMETER_UDS,(vector *)&local_70,
             (vector *)abStack_40);
  FUN_00cb7f50(abStack_40);
  FUN_00cbe2dc(&local_70);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                avStack_34);
  __cxa_atexit(0xf0a197,&NissanLiveData::WL_INSTRUMENTS_ODOMETER_UDS,&DAT_014371d0);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


