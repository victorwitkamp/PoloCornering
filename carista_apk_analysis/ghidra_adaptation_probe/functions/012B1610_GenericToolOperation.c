/* GenericToolOperation::GenericToolOperation @ 012b1610 */


/* GenericToolOperation::GenericToolOperation(std::__ndk1::shared_ptr<ConnectionManager> const&,
   std::__ndk1::shared_ptr<Setting> const&, std::__ndk1::shared_ptr<ReadValuesOperation> const&) */

void __thiscall
GenericToolOperation::GenericToolOperation
          (GenericToolOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  VehicleProtocol *pVVar4;
  IllegalArgumentException *this_00;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int *local_80 [2];
  shared_ptr asStack_78 [8];
  int *local_70 [2];
  int *local_68 [2];
  shared_ptr asStack_60 [8];
  int local_58 [2];
  shared_ptr asStack_50 [12];
  int local_44 [2];
  int local_3c;
  undefined1 *puStack_28;
  
  puStack_28 = &stack0xfffffff8;
  local_3c = __stack_chk_guard;
  LiveDataOperation::LiveDataOperation((LiveDataOperation *)this,param_1,param_2,param_3);
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x98) = 0;
  *(undefined8 *)(this + 0xa0) = 0;
  *(undefined8 *)(this + 0xa8) = 0;
  *(undefined4 *)(this + 0xb0) = 0;
  *(undefined ***)this = &PTR__GenericToolOperation_014bd1f4;
  iVar2 = *(int *)(param_2 + 4);
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)param_2;
  *(int *)(this + 0xb8) = iVar2;
  if (iVar2 != 0) {
    piVar3 = (int *)(iVar2 + 4);
    do {
      ExclusiveAccess(piVar3);
      bVar1 = (bool)hasExclusiveAccess(piVar3);
    } while (!bVar1);
    *piVar3 = *piVar3 + 1;
  }
  iVar2 = *(int *)(param_3 + 4);
  *(undefined4 *)(this + 0xbc) = *(undefined4 *)param_3;
  *(int *)(this + 0xc0) = iVar2;
  if (iVar2 != 0) {
    piVar3 = (int *)(iVar2 + 4);
    do {
      ExclusiveAccess(piVar3);
      bVar1 = (bool)hasExclusiveAccess(piVar3);
    } while (!bVar1);
    *piVar3 = *piVar3 + 1;
  }
  uVar5 = 0;
  uVar6 = 0;
  uVar7 = 0;
  uVar8 = 0;
  *(undefined4 *)(this + 0xe2) = 0;
  *(undefined8 *)(this + 0xc4) = 0;
  *(undefined8 *)(this + 0xcc) = 0;
  *(undefined8 *)(this + 0xd4) = 0;
  *(undefined8 *)(this + 0xdc) = 0;
  *(undefined4 *)(this + 0xe6) = 0;
  RichState::NONE((RichState *)(this + 0xec));
  *(undefined4 *)(this + 0xf4) = uVar5;
  *(undefined4 *)(this + 0xf8) = uVar6;
  *(undefined4 *)(this + 0xfc) = uVar7;
  *(undefined4 *)(this + 0x100) = uVar8;
  *(undefined4 *)(this + 0x108) = 0;
  *(undefined4 *)(this + 0x104) = 0;
  FUN_011e7154(local_44,param_2);
  if (local_44[0] == 0) {
    this_00 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(asStack_50,"Tool passed to GenericToolOperation is not a GenericTool");
    IllegalArgumentException::IllegalArgumentException(this_00,(basic_string *)asStack_50);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this_00,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  Log::d("Generic tool started: %s",*(undefined4 *)(*(int *)param_2 + 0x28));
  (**(code **)(**(int **)param_3 + 0x14))(asStack_50);
  Operation::setDelegate((Operation *)this,asStack_50);
  FUN_00d5a8a2(asStack_50);
  (**(code **)(*(int *)this + 0x14))(local_58,this);
  iVar2 = local_58[0];
  if (local_58[0] == 0) {
    FUN_00cb4d44(asStack_50,&DAT_0082cf5e);
  }
  else {
    (**(code **)(*(int *)this + 0x14))(local_68,this);
    (**(code **)(*local_68[0] + 0x34))(asStack_60);
    StringUtils::toString((StringUtils *)asStack_50,asStack_60);
  }
  FUN_00cbe908(this + 0xc4,
               (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
               asStack_50);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                asStack_50);
  if (iVar2 != 0) {
    FUN_00cbba38(asStack_60);
    FUN_00d5a8a2(local_68);
  }
  FUN_00d5a8a2(local_58);
  (**(code **)(*(int *)this + 0x14))(local_58,this);
  iVar2 = local_58[0];
  if (local_58[0] == 0) {
    FUN_00cb4d44(asStack_50,&DAT_0082cf5e);
  }
  else {
    (**(code **)(*(int *)this + 0x14))(local_70,this);
    pVVar4 = (VehicleProtocol *)(**(code **)(*local_70[0] + 0x10))();
    VehicleProtocol::toString((VehicleProtocol *)asStack_50,pVVar4);
  }
  FUN_00cbe908(this + 0xd0,
               (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
               asStack_50);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                asStack_50);
  if (iVar2 != 0) {
    FUN_00d5a8a2(local_70);
  }
  FUN_00d5a8a2(local_58);
  (**(code **)(*(int *)this + 0x14))(local_58,this);
  if (local_58[0] == 0) {
    FUN_00cb4d44(asStack_50,&DAT_0082cf5e);
  }
  else {
    (**(code **)(*(int *)this + 0x14))(local_80,this);
    (**(code **)(*local_80[0] + 0x28))(asStack_78);
    StringUtils::toString((StringUtils *)asStack_50,asStack_78);
  }
  FUN_00cbe908(this + 0xdc,
               (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
               asStack_50);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                asStack_50);
  if (local_58[0] != 0) {
    FUN_00cbba38(asStack_78);
    FUN_00d5a8a2(local_80);
  }
  FUN_00d5a8a2(local_58);
  getAvailableItems((vector *)asStack_50);
  FUN_012a3162(this + 0x9c,asStack_50);
  FUN_00ccc71c(asStack_50);
  getAvailableItems((vector *)asStack_50);
  FUN_012a3162((vector *)(this + 0xa8),asStack_50);
  FUN_00ccc71c(asStack_50);
  getAvailableItems((vector *)asStack_50);
  ContainerUtils::addAll<std::__ndk1::shared_ptr<Setting>>
            ((vector *)(this + 0xa8),(vector *)asStack_50);
  FUN_00ccc71c(asStack_50);
  FUN_011e71a0(local_44);
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_3c);
  }
  return;
}


