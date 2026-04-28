/*
 * GetVagUdsEcuWorkshopCodeCommand_ctor
 * ELF symbol address: 0x00D0505C
 * Ghidra address: 0x00D1505C (ELF + 0x10000 image delta)
 * ELF symbol size: 56 bytes
 * Symbol: _ZN31GetVagUdsEcuWorkshopCodeCommandC1EP3Ecu
 * Program: libCarista.so
 * Resolved function: GetVagUdsEcuWorkshopCodeCommand::GetVagUdsEcuWorkshopCodeCommand @ 00d1505c
 * Signature: undefined __thiscall GetVagUdsEcuWorkshopCodeCommand(GetVagUdsEcuWorkshopCodeCommand * this, Ecu * param_1)
 * Return type: undefined
 * Function body: [[00d1505c, 00d15085]]
 * Parameters:
 *   [0] GetVagUdsEcuWorkshopCodeCommand * this
 *   [1] Ecu * param_1
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e31d4
 *   GetVagUdsEcuWorkshopCodeCommand::GetVagUdsEcuWorkshopCodeCommand @ 01402400 -> COMPUTED_CALL from 01402408
 * Direct callees/references:
 *   READ 00d15088 from 00d15060
 *   READ 00d1508c from 00d15062
 *   READ 014dabb4 from 00d15068
 *   READ 014dabb8 from 00d1506a
 *   READ 00c89e4c from 00d1506c
 *   READ 00c89e50 from 00d1506e
 *   UNCONDITIONAL_CALL ReadDataByIdentifierCommand<BytesModel>::ReadDataByIdentifierCommand @ 013fe4f0 from 00d15076
 *   READ 00d15090 from 00d1507a
 *   READ 014db344 from 00d1507e
 *   DATA 0143c838 from 00d15082
 */

/* Ghidra function: GetVagUdsEcuWorkshopCodeCommand::GetVagUdsEcuWorkshopCodeCommand @ 00d1505c */

/* First instructions after recreation:
 * Memory bytes: 80b56f46094a0a4b7a447b4412681b6812681b6813434ff2a512e9f23ce20549
 * 00d1505c: push {r7,lr}
 * 00d1505e: mov r7,sp
 * 00d15060: ldr r2,[0x00d15088]
 * 00d15062: ldr r3,[0x00d1508c]
 * 00d15064: add r2,pc
 * 00d15066: add r3,pc
 * 00d15068: ldr r2,[r2,#0x0]
 * 00d1506a: ldr r3,[r3,#0x0]
 * 00d1506c: ldr r2,[r2,#0x0]
 * 00d1506e: ldr r3,[r3,#0x0]
 * 00d15070: orrs r3,r2
 * 00d15072: movw r2,#0xf1a5
 * 00d15076: blx 0x013fe4f0
 * 00d1507a: ldr r1,[0x00d15090]
 * 00d1507c: add r1,pc
 * 00d1507e: ldr r1,[r1,#0x0]
 * 00d15080: adds r1,#0x8
 * 00d15082: str r1,[r0,#0x0]
 * 00d15084: pop {r7,pc}
 * 00d15094: b.w 0x013f7f68
 * 00d15098: push {r4,r6,r7,lr}
 * 00d1509a: add r7,sp,#0x8
 * 00d1509c: mov r4,r0
 * 00d1509e: blx 0x014023f0
 */


/* GetVagUdsEcuWorkshopCodeCommand::GetVagUdsEcuWorkshopCodeCommand(Ecu*) */

void __thiscall
GetVagUdsEcuWorkshopCodeCommand::GetVagUdsEcuWorkshopCodeCommand
          (GetVagUdsEcuWorkshopCodeCommand *this,Ecu *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           ReadDataByIdentifierCommand<BytesModel>::ReadDataByIdentifierCommand
                     ((ReadDataByIdentifierCommand<BytesModel> *)this,param_1,0xf1a5,3);
  *puVar1 = &PTR__GetVagUdsEcuWorkshopCodeCommand_0143c838;
  return;
}


