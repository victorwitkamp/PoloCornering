/* VagCanSingleActuatorOperation::VagCanSingleActuatorOperation @ 012d8b30 */


/* VagCanSingleActuatorOperation::VagCanSingleActuatorOperation(std::__ndk1::shared_ptr<ConnectionManager>
   const&, std::__ndk1::shared_ptr<VagBasicSettingTool> const&,
   std::__ndk1::shared_ptr<ReadValuesOperation> const&) */

void __thiscall
VagCanSingleActuatorOperation::VagCanSingleActuatorOperation
          (VagCanSingleActuatorOperation *this,shared_ptr *param_1,shared_ptr *param_2,
          shared_ptr *param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           VagCanRoutineBasedOperation::VagCanRoutineBasedOperation
                     ((VagCanRoutineBasedOperation *)this,param_1,param_2,param_3);
  *puVar1 = &PTR__VagCanSingleActuatorOperation_014bf414;
  return;
}


