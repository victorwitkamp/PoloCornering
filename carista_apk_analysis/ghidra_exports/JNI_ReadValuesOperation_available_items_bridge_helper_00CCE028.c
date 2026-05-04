/*
 * JNI_ReadValuesOperation_available_items_bridge_helper
 * ELF symbol address: 0x00CBE028
 * Ghidra address: 0x00CCE028 (ELF + 0x10000 image delta)
 * ELF symbol size: 52 bytes
 * Symbol: local helper called by ReadValuesOperation_getAvailableItems
 * Program: libCarista.so
 * Resolved function: FUN_00cce028 @ 00cce028
 * Signature: undefined FUN_00cce028(void)
 * Return type: undefined
 * Function body: [[00cce028, 00cce051]]
 * Parameters:
 * Direct callers:
 *   Java_com_prizmos_carista_library_operation_ReadValuesOperation_getAvailableItems @ 00ccdb9c -> UNCONDITIONAL_CALL from 00ccdbc4
 *   SettingDto::findInSettings @ 00d5a6b0 -> UNCONDITIONAL_CALL from 00d5a6d8
 *   BmwECanOperationDelegate::getBannedSettings @ 011dff30 -> UNCONDITIONAL_CALL from 011dff6a
 *   BmwEOperationDelegate::runDebugCommands @ 011e6aec -> UNCONDITIONAL_CALL from 011e6b36
 *   BmwEOperationDelegate::runDebugCommands @ 011e6aec -> UNCONDITIONAL_CALL from 011e6b4a
 *   BmwEOperationDelegate::runDebugCommands @ 011e6aec -> UNCONDITIONAL_CALL from 011e6b5e
 *   BmwFOperationDelegate::runDebugCommandsLiveData @ 011f92e0 -> UNCONDITIONAL_CALL from 011f930c
 *   BmwFOperationDelegate::runDebugCommandsLiveData @ 011f92e0 -> UNCONDITIONAL_CALL from 011f9320
 *   BmwFOperationDelegate::runDebugCommandsLiveData @ 011f92e0 -> UNCONDITIONAL_CALL from 011f9334
 *   BmwFOperationDelegate::getBannedSettings @ 011fa67c -> UNCONDITIONAL_CALL from 011fa6ac
 *   FordOperationDelegate::runLiveDataAndSettingCommand @ 01215114 -> UNCONDITIONAL_CALL from 0121513e
 *   FordOperationDelegate::runLiveDataAndSettingCommand @ 01215114 -> UNCONDITIONAL_CALL from 01215152
 *   NissanOperationDelegate::getBannedSettings @ 0122ad98 -> UNCONDITIONAL_CALL from 0122add2
 *   ToyotaOperationDelegate::getBannedSettings @ 012587f0 -> UNCONDITIONAL_CALL from 01258830
 *   ToyotaOperationDelegate::runDebugCommandsCanSettingsAndTools @ 0125c5ac -> UNCONDITIONAL_CALL from 0125c620
 *   ToyotaOperationDelegate::runDebugCommandsCanSettingsAndTools @ 0125c5ac -> UNCONDITIONAL_CALL from 0125c62c
 *   ToyotaOperationDelegate::runDebugCommandsCanLiveData @ 0125ca98 -> UNCONDITIONAL_CALL from 0125cb2a
 *   ToyotaOperationDelegate::runDebugCommandsCanLiveData @ 0125ca98 -> UNCONDITIONAL_CALL from 0125cb36
 *   ToyotaOperationDelegate::runDebugCommandsUdsItems @ 0125ce70 -> UNCONDITIONAL_CALL from 0125cea4
 *   ToyotaOperationDelegate::runDebugCommandsUdsItems @ 0125ce70 -> UNCONDITIONAL_CALL from 0125ceb0
 *   ToyotaOperationDelegate::runDebugCommandsUdsItems @ 0125ce70 -> UNCONDITIONAL_CALL from 0125cebc
 *   VagOperationDelegate::getBannedSettings @ 0126fbe8 -> UNCONDITIONAL_CALL from 0126fc18
 *   VagOperationDelegate::runAdaptationAndLiveDataDebugCommands @ 0127a4fc -> UNCONDITIONAL_CALL from 0127a51e
 *   VagOperationDelegate::runAdaptationAndLiveDataDebugCommands @ 0127a4fc -> UNCONDITIONAL_CALL from 0127a52a
 *   VagOperationDelegate::runAdaptationAndLiveDataDebugCommands @ 0127a4fc -> UNCONDITIONAL_CALL from 0127a536
 *   CarHealthCheckAvailabilityOperation::getStaticItems @ 01295084 -> UNCONDITIONAL_CALL from 012950ae
 *   CheckLiveDataOperation::getStaticItems @ 012a1528 -> UNCONDITIONAL_CALL from 012a1536
 * Direct callees/references:
 *   UNCONDITIONAL_CALL std::__ndk1::__hash_table<std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::__unordered_map_hasher<SettingCategory*,std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::hash<SettingCategory*>,std::__ndk1::equal_to<SettingCategory*>,true>,std::__ndk1::__unordered_map_equal<SettingCategory*,std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::equal_to<SettingCategory*>,std::__ndk1::hash<SettingCategory*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>>>::__rehash<true> @ 013fba00 from 00cce040
 *   UNCONDITIONAL_CALL std::__ndk1::unordered_map<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>,std::__ndk1::hash<SettingCategory*>,std::__ndk1::equal_to<SettingCategory*>,std::__ndk1::allocator<std::__ndk1::pair<SettingCategory*const,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>>>::insert<std::__ndk1::__hash_map_const_iterator<std::__ndk1::__hash_const_iterator<std::__ndk1::__hash_node<std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,void*>*>>> @ 013fba10 from 00cce04a
 */

/* Ghidra function: FUN_00cce028 @ 00cce028 */

/* First instructions after recreation:
 * Memory bytes: b0b502afc0ef500004460d4640f98d0a09690160696820462df3dee4a9682046
 * 00cce028: push {r4,r5,r7,lr}
 * 00cce02a: add r7,sp,#0x8
 * 00cce02c: vmov.i32 q8,#0
 * 00cce030: mov r4,r0
 * 00cce032: mov r5,r1
 * 00cce034: vst1.32 {d16,d17},[r0]!
 * 00cce038: ldr r1,[r1,#0x10]
 * 00cce03a: str r1,[r0,#0x0]
 * 00cce03c: ldr r1,[r5,#0x4]
 * 00cce03e: mov r0,r4
 * 00cce040: blx 0x013fba00
 * 00cce044: ldr r1,[r5,#0x8]
 * 00cce046: mov r0,r4
 * 00cce048: movs r2,#0x0
 * 00cce04a: blx 0x013fba10
 * 00cce04e: mov r0,r4
 * 00cce050: pop {r4,r5,r7,pc}
 * 00cce05c: push {r4,r5,r6,r7,lr}
 * 00cce05e: add r7,sp,#0xc
 * 00cce060: push.w r8
 * 00cce064: sub sp,#0x20
 * 00cce066: mov r4,r0
 * 00cce068: ldr r0,[0x00cce1bc]
 * 00cce06a: mov r5,r1
 */


__hash_table<std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::__unordered_map_hasher<SettingCategory*,std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::hash<SettingCategory*>,std::__ndk1::equal_to<SettingCategory*>,true>,std::__ndk1::__unordered_map_equal<SettingCategory*,std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::equal_to<SettingCategory*>,std::__ndk1::hash<SettingCategory*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>>>
* FUN_00cce028(__hash_table<std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::__unordered_map_hasher<SettingCategory*,std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::hash<SettingCategory*>,std::__ndk1::equal_to<SettingCategory*>,true>,std::__ndk1::__unordered_map_equal<SettingCategory*,std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::equal_to<SettingCategory*>,std::__ndk1::hash<SettingCategory*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>>>
               *param_1,int param_2)

{
  *(undefined8 *)param_1 = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  std::__ndk1::
  __hash_table<std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::__unordered_map_hasher<SettingCategory*,std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::hash<SettingCategory*>,std::__ndk1::equal_to<SettingCategory*>,true>,std::__ndk1::__unordered_map_equal<SettingCategory*,std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,std::__ndk1::equal_to<SettingCategory*>,std::__ndk1::hash<SettingCategory*>,true>,std::__ndk1::allocator<std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>>>
  ::__rehash<true>(param_1,*(uint *)(param_2 + 4));
  std::__ndk1::
  unordered_map<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>,std::__ndk1::hash<SettingCategory*>,std::__ndk1::equal_to<SettingCategory*>,std::__ndk1::allocator<std::__ndk1::pair<SettingCategory*const,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>>>
  ::
  insert<std::__ndk1::__hash_map_const_iterator<std::__ndk1::__hash_const_iterator<std::__ndk1::__hash_node<std::__ndk1::__hash_value_type<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>,void*>*>>>
            ((unordered_map<SettingCategory*,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>,std::__ndk1::hash<SettingCategory*>,std::__ndk1::equal_to<SettingCategory*>,std::__ndk1::allocator<std::__ndk1::pair<SettingCategory*const,std::__ndk1::vector<std::__ndk1::shared_ptr<Setting>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Setting>>>>>>
              *)param_1,*(undefined4 *)(param_2 + 8),0);
  return param_1;
}


