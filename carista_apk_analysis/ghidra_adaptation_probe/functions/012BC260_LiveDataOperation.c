/* LiveDataOperation::LiveDataOperation @ 012bc260 */


/* LiveDataOperation::LiveDataOperation(std::__ndk1::shared_ptr<ConnectionManager> const&,
   std::__ndk1::shared_ptr<Setting> const&, std::__ndk1::shared_ptr<ReadValuesOperation> const&) */

void __thiscall
LiveDataOperation::LiveDataOperation
          (LiveDataOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3)

{
  LiveDataTool *pLVar1;
  undefined4 uVar2;
  vector *pvVar3;
  IllegalArgumentException *pIVar4;
  int iVar5;
  int iVar6;
  vector *pvVar7;
  int local_44 [2];
  LiveDataTool *local_3c [3];
  LiveDataTool *local_30 [2];
  int local_28;
  
  local_28 = __stack_chk_guard;
  Operation::Operation((Operation *)this,param_1);
  this[0x6a] = (LiveDataOperation)0x0;
  *(undefined2 *)(this + 0x68) = 0;
  *(undefined ***)this = &PTR__LiveDataOperation_014bda58;
  *(undefined8 *)(this + 0x6c) = 0;
  *(undefined8 *)(this + 0x74) = 0;
  *(undefined8 *)(this + 0x7c) = 0;
  *(undefined8 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x8c) = 0;
  FUN_011e3768(local_30,param_2);
  pvVar7 = (vector *)(this + 0x78);
  if (local_30[0] == (LiveDataTool *)0x0) {
    FUN_011e7154(local_44,param_2);
    if (local_44[0] == 0) {
      pIVar4 = (IllegalArgumentException *)__cxa_allocate_exception(8);
      FUN_00cb4d44(local_3c,"Unknown tool passed to LiveDataOperation");
      IllegalArgumentException::IllegalArgumentException(pIVar4,(basic_string *)local_3c);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(pIVar4,&IllegalArgumentException::typeinfo,
                  IllegalStateException::~IllegalStateException);
    }
    FUN_012b6964(local_3c,param_2);
    pLVar1 = local_3c[0];
    FUN_00d5c3f2(local_3c);
    if (pLVar1 != (LiveDataTool *)0x0) {
      this[0x6a] = (LiveDataOperation)0x1;
    }
    iVar6 = *(int *)(local_44[0] + 0x28);
    for (iVar5 = *(int *)(local_44[0] + 0x24); iVar5 != iVar6; iVar5 = iVar5 + 8) {
      FUN_011e3768(local_3c,iVar5);
      if (local_3c[0] == (LiveDataTool *)0x0) {
        FUN_00d6f39a(pvVar7,iVar5);
      }
      else {
        pvVar3 = (vector *)LiveDataTool::getParams(local_3c[0]);
        ContainerUtils::addAll<std::__ndk1::shared_ptr<Setting>>(pvVar7,pvVar3);
      }
      FUN_00ccc814(local_3c);
    }
    if (*(int *)(this + 0x78) != *(int *)(this + 0x7c)) {
      init(this,param_3,(bool)this[0x6a]);
    }
    FUN_011e71a0(local_44);
  }
  else {
    FUN_012bc470(local_3c,local_30);
    FUN_00ccc708(local_3c);
    if (local_3c[0] != (LiveDataTool *)0x0) {
      this[0x6a] = (LiveDataOperation)0x1;
    }
    uVar2 = LiveDataTool::getParams(local_30[0]);
    FUN_011e01d6(pvVar7,uVar2);
    if (*(int *)(this + 0x78) == *(int *)(this + 0x7c)) {
      pIVar4 = (IllegalArgumentException *)__cxa_allocate_exception(8);
      FUN_00cb4d44(local_3c,"ReadLiveDataOperation params array shouldn\'t be of zero length");
      IllegalArgumentException::IllegalArgumentException(pIVar4,(basic_string *)local_3c);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(pIVar4,&IllegalArgumentException::typeinfo,
                  IllegalStateException::~IllegalStateException);
    }
    init(this,param_3,true);
  }
  FUN_00ccc814(local_30);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_28);
  }
  return;
}


