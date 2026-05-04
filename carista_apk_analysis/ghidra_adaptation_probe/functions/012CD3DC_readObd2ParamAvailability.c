/* ReadValuesOperation::readObd2ParamAvailability @ 012cd3dc */


/* ReadValuesOperation::readObd2ParamAvailability(std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,
   std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting> > > const&,
   std::__ndk1::shared_ptr<Progress::Steps> const&) */

void __thiscall
ReadValuesOperation::readObd2ParamAvailability
          (ReadValuesOperation *this,vector *param_1,shared_ptr *param_2)

{
  byte bVar1;
  bool bVar2;
  uchar uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined4 uVar8;
  Ecu aEStack_4c [28];
  undefined4 *local_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  piVar7 = *(int **)param_1;
  piVar4 = *(int **)(param_1 + 4);
  do {
    if ((piVar7 == piVar4) || (iVar5 = Operation::isCanceled((Operation *)this), iVar5 != 0)) break;
    uVar8 = *(undefined4 *)(this + 0x34);
    uVar3 = Obd2Ecu::getInstance();
    Math::toExact<unsigned_char,unsigned_short>(*(ushort *)(*piVar7 + 0x14));
    Obd2System::getAvailabilityByPid(aEStack_4c,(uchar)uVar8,uVar3);
    (**(code **)(**(int **)param_2 + 0x2c))();
    iVar5 = Result<bool,void>::isFatalFail((Result<bool,void> *)aEStack_4c);
    if (iVar5 == 0) {
      iVar5 = Result<bool,void>::isFail((Result<bool,void> *)aEStack_4c);
      if (iVar5 == 0) {
        bVar1 = *(byte *)*local_30;
        piVar6 = (int *)FUN_012cd4cc(this + 0x7c,piVar7);
        bVar2 = true;
        *piVar6 = (uint)bVar1 << 1;
      }
      else {
        bVar2 = false;
      }
    }
    else {
      bVar2 = false;
    }
    Result<bool,void>::~Result((Result<bool,void> *)aEStack_4c);
    piVar7 = piVar7 + 2;
  } while (bVar2);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_28);
  }
  return;
}


