/*
 * VagCanPacket_toRawBytesForSending
 * ELF symbol address: 0x00D1740C
 * Ghidra address: 0x00D2740C (ELF + 0x10000 image delta)
 * ELF symbol size: 180 bytes
 * Symbol: _ZN18VagCanCommunicator12VagCanPacket20toRawBytesForSendingEv
 * Program: libCarista.so
 * Resolved function: VagCanCommunicator::VagCanPacket::toRawBytesForSending @ 00d2740c
 * Signature: undefined __stdcall toRawBytesForSending(void)
 * Return type: undefined
 * Function body: [[00d2740c, 00d2748b]]
 * Parameters:
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 0143da84
 * Direct callees/references:
 *   READ 00d274ac from 00d27414
 *   READ 014da87c from 00d2741a
 *   READ 015a7014 from 00d2741c
 *   WRITE Stack[-0x14] from 00d2741e
 *   CONDITIONAL_JUMP VagCanCommunicator::VagCanPacket::toRawBytesForSending @ 00d2740c from 00d27428
 *   UNCONDITIONAL_CALL _ZplIhTnPNSt6__ndk19enable_ifIXsr7is_sameIhT_EE5valueES2_E4typeELPh0EENS0_6vectorIhNS0_9allocatorIhEEEES2_RKSA_ @ 013fd4d0 from 00d27436
 *   READ Stack[-0x14] from 00d2743a
 *   READ 00d274bc from 00d2743c
 *   READ 014da87c from 00d27440
 *   READ 015a7014 from 00d27442
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00d2744c
 *   UNCONDITIONAL_CALL __cxa_allocate_exception @ 013fa5d0 from 00d27452
 *   UNCONDITIONAL_CALL _ZN11StringUtils8toStringIN18VagCanCommunicator6OpCodeETnPNSt6__ndk19enable_ifIXntsr13is_arithmeticIT_EE5valueEvE4typeELPv0EEENS3_12basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERKS5_ @ 01403cb0 from 00d2745e
 *   READ 00d274b0 from 00d27464
 *   PARAM 00a54c1c from 00d27468
 *   UNCONDITIONAL_CALL FUN_00cbe7e4 @ 00cbe7e4 from 00d2746a
 *   UNCONDITIONAL_CALL IllegalStateException::IllegalStateException @ 013fadb0 from 00d27474
 *   READ 00d274b4 from 00d2747a
 *   READ 014da944 from 00d2747e
 *   PARAM 01437dd4 from 00d2747e
 *   READ 00d274b8 from 00d27480
 *   READ 014da948 from 00d27484
 *   PARAM IllegalStateException::~IllegalStateException @ 00cdb326 from 00d27484
 *   UNCONDITIONAL_CALL __cxa_throw @ 013fa5f0 from 00d27488
 */

/* Ghidra function: VagCanCommunicator::VagCanPacket::toRawBytesForSending @ 00d2740c */

/* First instructions after recreation:
 * Memory bytes: b0b502af88b0044625480d467844006800680790086881682846884790b1a87a
 * 00d2740c: push {r4,r5,r7,lr}
 * 00d2740e: add r7,sp,#0x8
 * 00d27410: sub sp,#0x20
 * 00d27412: mov r4,r0
 * 00d27414: ldr r0,[0x00d274ac]
 * 00d27416: mov r5,r1
 * 00d27418: add r0,pc
 * 00d2741a: ldr r0,[r0,#0x0]
 * 00d2741c: ldr r0,[r0,#0x0]
 * 00d2741e: str r0,[sp,#0x1c]
 * 00d27420: ldr r0,[r1,#0x0]
 * 00d27422: ldr r1,[r0,#0x8]
 * 00d27424: mov r0,r5
 * 00d27426: blx r1
 * 00d27428: cbz r0,0x00d27450
 * 00d2742a: ldrb r0,[r5,#0xa]
 * 00d2742c: add.w r2,r5,#0xc
 * 00d27430: ldrb r1,[r5,#0xb]
 * 00d27432: orrs r1,r0
 * 00d27434: mov r0,r4
 * 00d27436: blx 0x013fd4d0
 * 00d2743a: ldr r0,[sp,#0x1c]
 * 00d2743c: ldr r1,[0x00d274bc]
 * 00d2743e: add r1,pc
 */


/* VagCanCommunicator::VagCanPacket::toRawBytesForSending() */

void VagCanCommunicator::VagCanPacket::toRawBytesForSending(void)

{
  int iVar1;
  IllegalStateException *this;
  int *in_r1;
  undefined1 auStack_2c [12];
  basic_string abStack_20 [12];
  int local_14;
  
  local_14 = __stack_chk_guard;
  iVar1 = (**(code **)(*in_r1 + 8))();
  if (iVar1 == 0) {
    this = (IllegalStateException *)__cxa_allocate_exception(8);
    _ZN11StringUtils8toStringIN18VagCanCommunicator6OpCodeETnPNSt6__ndk19enable_ifIXntsr13is_arithmeticIT_EE5valueEvE4typeELPv0EEENS3_12basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERKS5_
              (auStack_2c,(int)in_r1 + 10);
    FUN_00cbe7e4(abStack_20,"Cannot send an invalid packet w/ opCode: ",auStack_2c);
    IllegalStateException::IllegalStateException(this,abStack_20);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this,&IllegalStateException::typeinfo,IllegalStateException::~IllegalStateException)
    ;
  }
  _ZplIhTnPNSt6__ndk19enable_ifIXsr7is_sameIhT_EE5valueES2_E4typeELPh0EENS0_6vectorIhNS0_9allocatorIhEEEES2_RKSA_
            ();
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


