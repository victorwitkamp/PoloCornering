/* Target address 012da210 */
/* Function internalRunCommand<VagUdsRoutineStateModel> @ 012da150 */


/* BroadcastCommandResult<VagUdsRoutineStateModel>
   ConnectionManager::internalRunCommand<VagUdsRoutineStateModel>(std::__ndk1::shared_ptr<Command<VagUdsRoutineStateModel>
   > const&, bool, std::__ndk1::shared_ptr<State::OnStateUpdateListener> const&) */

void ConnectionManager::internalRunCommand<VagUdsRoutineStateModel>
               (shared_ptr *param_1,bool param_2,shared_ptr *param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  ConnectionManager *this;
  ConnectionManager *pCVar5;
  int in_r3;
  int iVar6;
  undefined8 uVar7;
  undefined4 *in_stack_00000000;
  undefined4 local_9c;
  int local_94;
  undefined4 local_78;
  int local_70;
  int *local_54 [2];
  BroadcastCommandResult<VagUdsRoutineStateModel> aBStack_4c [24];
  int *local_34;
  int local_28;
  
  this = (ConnectionManager *)(uint)param_2;
  local_28 = __stack_chk_guard;
  std::__ndk1::recursive_mutex::lock();
  BroadcastCommandResult<VagUdsRoutineStateModel>::BroadcastCommandResult(aBStack_4c);
  (**(code **)(**(int **)param_3 + 8))(&local_9c);
  ByteUtils::getHexString((ByteUtils *)&local_78,(vector *)&local_9c);
  iVar6 = local_70;
  if ((local_78 & 1) == 0) {
    iVar6 = (int)&local_78 + 1;
  }
  Log::d("Running command \"%s\"",iVar6);
  std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
  ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                &local_78);
  FUN_00cb7f50((shared_ptr *)&local_9c);
  DataMemoryBarrier(0x1b);
  iVar6 = 0;
  this[0x5a] = (ConnectionManager)0x0;
  pCVar5 = this + 0x1c;
  DataMemoryBarrier(0x1b);
  do {
    std::__ndk1::mutex::lock();
    this[0x2c] = (ConnectionManager)0x0;
    std::__ndk1::mutex::unlock();
    FUN_00d2a684((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                 &local_78,this + 0x14);
    uVar2 = local_78;
    FUN_00d19b7a((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                 &local_78);
    if (uVar2 == 0) {
      iVar3 = isCanceled(this);
      if (iVar3 != 0) {
        iVar6 = -1000;
        goto LAB_012da4d4;
      }
      establishConnection((shared_ptr *)&local_9c);
      iVar3 = (**(code **)(*local_9c + 0xc))();
      piVar1 = local_9c;
      if (iVar3 == 0) {
        (**(code **)(*(int *)local_9c[2] + 0xc))
                  ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *
                   )&local_78);
        FUN_00d2c488(local_54,piVar1 + 4,
                     (basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                      *)&local_78);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)&local_78);
        setElm((shared_ptr *)this);
        iVar3 = (**(code **)(*local_54[0] + 0x10))();
        if ((iVar3 == -0x17) || (iVar4 = State::isError(iVar3), iVar4 == 0)) {
          uVar7 = (**(code **)(*local_54[0] + 0x13c))();
          *(undefined8 *)(this + 0x30) = uVar7;
          DeviceLatestInfo::onDeviceConnected
                    ((DeviceLatestInfo *)App::DEVICE_LATEST_INFO,(shared_ptr *)(local_9c + 2),
                     iVar3 == -0x17);
          Statistics::onDeviceConnSucceeded(*(Statistics **)(this + 4));
          FUN_00d19b7a(local_54);
          FUN_00d2b340((shared_ptr *)&local_9c);
          goto LAB_012da2ce;
        }
        resetConnection(this);
        BroadcastCommandResult<VagUdsRoutineStateModel>::BroadcastCommandResult
                  ((BroadcastCommandResult<VagUdsRoutineStateModel> *)param_1,iVar3);
        FUN_00d19b7a(local_54);
      }
      else {
        resetConnection(this);
        BroadcastCommandResult<VagUdsRoutineStateModel>::BroadcastCommandResult
                  ((BroadcastCommandResult<VagUdsRoutineStateModel> *)param_1,local_9c[1]);
      }
      FUN_00d2b340(&local_9c);
      goto LAB_012da4da;
    }
LAB_012da2ce:
    (**(code **)(*(int *)*in_stack_00000000 + 8))((int *)*in_stack_00000000,5);
    if (*(int **)pCVar5 == (int *)0x0) {
LAB_012da36c:
      (**(code **)(**(int **)(*(int *)param_3 + 4) + 8))
                ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                 &local_78);
      FUN_00d2a684((shared_ptr *)local_54,this + 0x14);
      CommunicatorFactory::newCommunicator
                ((CommunicatorFactory *)&local_9c,(basic_string *)&local_78,(shared_ptr *)local_54);
      FUN_00d2c4bc(pCVar5,(shared_ptr *)&local_9c);
      FUN_00d29bd0((shared_ptr *)&local_9c);
      FUN_00d19b7a((shared_ptr *)local_54);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)&local_78);
    }
    else {
      (**(code **)(**(int **)pCVar5 + 8))
                ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *)
                 &local_78);
      (**(code **)(**(int **)(*(int *)param_3 + 4) + 8))((shared_ptr *)&local_9c);
      iVar3 = FUN_00cfa744((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                            *)&local_78,(shared_ptr *)&local_9c);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)&local_9c);
      std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>::
      ~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                     *)&local_78);
      if (iVar3 != 0) {
        (**(code **)(**(int **)pCVar5 + 8))
                  ((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>> *
                   )&local_78);
        iVar3 = local_70;
        uVar2 = local_78;
        (**(code **)(**(int **)(*(int *)param_3 + 4) + 8))((shared_ptr *)&local_9c);
        if ((uVar2 & 1) == 0) {
          iVar3 = (int)&local_78 + 1;
        }
        iVar4 = local_94;
        if (((uint)local_9c & 1) == 0) {
          iVar4 = (int)&local_9c + 1;
        }
        Log::d("Existing communicator is %s but command needs %s; dropping.",iVar3,iVar4);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)&local_9c);
        std::__ndk1::basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
        ::~basic_string((basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>
                         *)&local_78);
        resetCommunicator(this);
      }
      if (*(int *)pCVar5 == 0) goto LAB_012da36c;
    }
    if (in_r3 == 0) {
      Communicator::runCommand<VagUdsRoutineStateModel>
                ((shared_ptr *)&local_78,*(shared_ptr **)pCVar5);
      BroadcastCommandResult<VagUdsRoutineStateModel>::single
                ((BroadcastCommandResult<VagUdsRoutineStateModel> *)&local_9c,
                 *(Ecu **)(*(int *)param_3 + 4),(Result *)&local_78);
      Result<std::__ndk1::unordered_map<Ecu*,Result<VagUdsRoutineStateModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<VagUdsRoutineStateModel,void>>>>,void>
      ::operator=((Result<std::__ndk1::unordered_map<Ecu*,Result<VagUdsRoutineStateModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<VagUdsRoutineStateModel,void>>>>,void>
                   *)aBStack_4c,(Result *)&local_9c);
      Result<std::__ndk1::unordered_map<Ecu*,Result<VagUdsRoutineStateModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<VagUdsRoutineStateModel,void>>>>,void>
      ::~Result((Result<std::__ndk1::unordered_map<Ecu*,Result<VagUdsRoutineStateModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<VagUdsRoutineStateModel,void>>>>,void>
                 *)&local_9c);
      Result<VagUdsRoutineStateModel,void>::~Result
                ((Result<VagUdsRoutineStateModel,void> *)&local_78);
    }
    else {
      Communicator::runBroadcastCommand<VagUdsRoutineStateModel>
                ((Communicator *)&local_78,*(shared_ptr **)pCVar5,param_3);
      Result<std::__ndk1::unordered_map<Ecu*,Result<VagUdsRoutineStateModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<VagUdsRoutineStateModel,void>>>>,void>
      ::operator=((Result<std::__ndk1::unordered_map<Ecu*,Result<VagUdsRoutineStateModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<VagUdsRoutineStateModel,void>>>>,void>
                   *)aBStack_4c,(Result *)&local_78);
      Result<std::__ndk1::unordered_map<Ecu*,Result<VagUdsRoutineStateModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<VagUdsRoutineStateModel,void>>>>,void>
      ::~Result((Result<std::__ndk1::unordered_map<Ecu*,Result<VagUdsRoutineStateModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<VagUdsRoutineStateModel,void>>>>,void>
                 *)&local_78);
    }
  } while (((*(char *)(*(int *)param_3 + 0xd) != '\0') && (iVar6 < 3)) &&
          (iVar6 = iVar6 + 1, *local_34 == -4));
  iVar6 = DeviceLatestInfo::isDefective((DeviceLatestInfo *)App::DEVICE_LATEST_INFO);
  if ((iVar6 == 0) || (*local_34 != -4)) {
    BroadcastCommandResult<VagUdsRoutineStateModel>::BroadcastCommandResult
              ((BroadcastCommandResult<VagUdsRoutineStateModel> *)param_1,aBStack_4c);
  }
  else {
    iVar6 = -0x17;
LAB_012da4d4:
    BroadcastCommandResult<VagUdsRoutineStateModel>::BroadcastCommandResult
              ((BroadcastCommandResult<VagUdsRoutineStateModel> *)param_1,iVar6);
  }
LAB_012da4da:
  Result<std::__ndk1::unordered_map<Ecu*,Result<VagUdsRoutineStateModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<VagUdsRoutineStateModel,void>>>>,void>
  ::~Result((Result<std::__ndk1::unordered_map<Ecu*,Result<VagUdsRoutineStateModel,void>,std::__ndk1::hash<Ecu*>,std::__ndk1::equal_to<Ecu*>,std::__ndk1::allocator<std::__ndk1::pair<Ecu*const,Result<VagUdsRoutineStateModel,void>>>>,void>
             *)aBStack_4c);
  std::__ndk1::recursive_mutex::unlock();
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


