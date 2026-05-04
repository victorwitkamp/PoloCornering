/* OperationDelegate::onConnectedProtocol @ 0123e4a8 */


/* OperationDelegate::onConnectedProtocol() */

void __thiscall OperationDelegate::onConnectedProtocol(OperationDelegate *this)

{
  int *piVar1;
  VehicleProtocol *pVVar2;
  int iVar3;
  shared_ptr asStack_9c [8];
  StringUtils aSStack_94 [12];
  basic_string abStack_88 [12];
  VehicleProtocol aVStack_7c [12];
  basic_string abStack_70 [12];
  undefined1 auStack_64 [12];
  basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> abStack_58 [12];
  Param aPStack_4c [48];
  int local_1c;
  
  piVar1 = (int *)App::ANALYTICS;
  local_1c = __stack_chk_guard;
  FUN_00cb4d44(abStack_58,"vehicle_connect");
  FUN_00cb4d44(abStack_70,"protocol");
  pVVar2 = (VehicleProtocol *)(**(code **)(*(int *)this + 0x10))(this);
  VehicleProtocol::toString(aVStack_7c,pVVar2);
  iVar3 = Analytics::Event::Param::Param(aPStack_4c,abStack_70,(basic_string *)aVStack_7c);
  FUN_00cb4d44(abStack_88,"chassis_id");
  (**(code **)(*(int *)this + 0x34))(asStack_9c,this);
  StringUtils::toString(aSStack_94,asStack_9c);
  Analytics::Event::Param::Param((Param *)(iVar3 + 0x18),abStack_88,(basic_string *)aSStack_94);
  FUN_00ce429c(auStack_64,aPStack_4c,2);
  (**(code **)(*piVar1 + 8))(piVar1,abStack_58,auStack_64);
  FUN_00ce431c(auStack_64);
  iVar3 = 0x18;
  do {
    Analytics::Event::Param::~Param(aPStack_4c + iVar3);
    iVar3 = iVar3 + -0x18;
  } while (iVar3 != -0x18);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                aSStack_94);
  FUN_00cbba38(asStack_9c);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                abStack_88);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                aVStack_7c);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                abStack_70);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string(abStack_58);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


