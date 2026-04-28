/*
 * VagCanCommunicator_receive
 * ELF symbol address: 0x00D188A4
 * Ghidra address: 0x00D288A4 (ELF + 0x10000 image delta)
 * ELF symbol size: 84 bytes
 * Symbol: _ZN18VagCanCommunicator7receiveEv
 * Program: libCarista.so
 * Resolved function: VagCanCommunicator::receive @ 00d288a4
 * Signature: undefined __stdcall receive(void)
 * Return type: undefined
 * Function body: [[00d288a4, 00d288e3]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e3820
 *   VagCanCommunicator::receive @ 01403d30 -> COMPUTED_CALL from 01403d38
 * Direct callees/references:
 *   READ 00d288f0 from 00d288aa
 *   READ 014da87c from 00d288b0
 *   READ 015a7014 from 00d288b2
 *   WRITE Stack[-0x14] from 00d288b4
 *   UNCONDITIONAL_CALL Communicator::readResponses @ 01402cc0 from 00d288b8
 *   READ Stack[-0x20] from 00d288bc
 *   UNCONDITIONAL_CALL std::__ndk1::list<std::__ndk1::shared_ptr<Communicator::Packet>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Communicator::Packet>>>::__insert_with_sentinel[abi:ne190000]<std::__ndk1::__wrap_iter<std::__ndk1::shared_ptr<Communicator::Packet>*>,std::__ndk1::__wrap_iter<std::__ndk1::shared_ptr<Communicator::Packet>*>> @ 01403d90 from 00d288c6
 *   UNCONDITIONAL_CALL FUN_00d1a800 @ 00d1a800 from 00d288cc
 *   READ Stack[-0x14] from 00d288d0
 *   READ 00d288f4 from 00d288d2
 *   READ 014da87c from 00d288d6
 *   READ 015a7014 from 00d288d8
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00d288e0
 */

/* Ghidra function: VagCanCommunicator::receive @ 00d288a4 */

/* First instructions after recreation:
 * Memory bytes: dfb506af04461148214678440068006803906846daf202e2dde9002304f11c00
 * 00d288a4: push {r0,r1,r2,r3,r4,r6,r7,lr}
 * 00d288a6: add r7,sp,#0x18
 * 00d288a8: mov r4,r0
 * 00d288aa: ldr r0,[0x00d288f0]
 * 00d288ac: mov r1,r4
 * 00d288ae: add r0,pc
 * 00d288b0: ldr r0,[r0,#0x0]
 * 00d288b2: ldr r0,[r0,#0x0]
 * 00d288b4: str r0,[sp,#0xc]
 * 00d288b6: mov r0,sp
 * 00d288b8: blx 0x01402cc0
 * 00d288bc: ldrd r2,r3,[sp,#0x0]
 * 00d288c0: add.w r0,r4,#0x1c
 * 00d288c4: mov r1,r0
 * 00d288c6: blx 0x01403d90
 * 00d288ca: mov r0,sp
 * 00d288cc: bl 0x00d1a800
 * 00d288d0: ldr r0,[sp,#0xc]
 * 00d288d2: ldr r1,[0x00d288f4]
 * 00d288d4: add r1,pc
 * 00d288d6: ldr r1,[r1,#0x0]
 * 00d288d8: ldr r1,[r1,#0x0]
 * 00d288da: cmp r1,r0
 * 00d288dc: it eq
 */


/* VagCanCommunicator::receive() */

undefined8 VagCanCommunicator::receive(void)

{
  int in_r0;
  undefined4 in_r1;
  int local_20;
  undefined4 uStack_1c;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_20 = in_r0;
  uStack_1c = in_r1;
  Communicator::readResponses();
  std::__ndk1::
  list<std::__ndk1::shared_ptr<Communicator::Packet>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Communicator::Packet>>>
  ::
  __insert_with_sentinel_abi_ne190000_<std::__ndk1::__wrap_iter<std::__ndk1::shared_ptr<Communicator::Packet>*>,std::__ndk1::__wrap_iter<std::__ndk1::shared_ptr<Communicator::Packet>*>>
            ((list<std::__ndk1::shared_ptr<Communicator::Packet>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Communicator::Packet>>>
              *)(in_r0 + 0x1c),
             (list<std::__ndk1::shared_ptr<Communicator::Packet>,std::__ndk1::allocator<std::__ndk1::shared_ptr<Communicator::Packet>>>
              *)(in_r0 + 0x1c),local_20,uStack_1c);
  FUN_00d1a800(&local_20);
  if (__stack_chk_guard == local_14) {
    return CONCAT44(uStack_1c,local_20);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


