/*
 * WriteDataByIdentifierCommand_ctor
 * ELF symbol address: 0x00CF8034
 * Ghidra address: 0x00D08034 (ELF + 0x10000 image delta)
 * ELF symbol size: 68 bytes
 * Symbol: _ZN28WriteDataByIdentifierCommandC1EP3EcutRKNSt6__ndk16vectorIhNS2_9allocatorIhEEEEj
 * Program: libCarista.so
 * Resolved function: WriteDataByIdentifierCommand::WriteDataByIdentifierCommand @ 00d08034
 * Signature: undefined __thiscall WriteDataByIdentifierCommand(WriteDataByIdentifierCommand * this, Ecu * param_1, ushort param_2, vector * param_3, uint param_4)
 * Return type: undefined
 * Function body: [[00d08034, 00d08067]]
 * Parameters:
 *   [0] WriteDataByIdentifierCommand * this
 *   [1] Ecu * param_1
 *   [2] ushort param_2
 *   [3] vector * param_3
 *   [4] uint param_4
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e22e0
 *   <no function> -> DATA from 014e2d7c
 *   WriteDataByIdentifierCommand::WriteDataByIdentifierCommand @ 013fe830 -> COMPUTED_CALL from 013fe838
 *   WriteDataByIdentifierCommand::WriteDataByIdentifierCommand @ 014012a0 -> COMPUTED_CALL from 014012a8
 * Direct callees/references:
 *   READ Stack[0x0] from 00d0803e
 *   UNCONDITIONAL_CALL SingleResponseCommand<EmptyModel>::SingleResponseCommand @ 013fdc10 from 00d08046
 *   READ 00d08074 from 00d0804c
 *   READ 014db1e8 from 00d08050
 *   DATA 0143bca8 from 00d08054
 *   UNCONDITIONAL_CALL FUN_00cd5ef0 @ 00cd5ef0 from 00d0805c
 */

/* Ghidra function: WriteDataByIdentifierCommand::WriteDataByIdentifierCommand @ 00d08034 */

/* First instructions after recreation:
 * Memory bytes: f0b503af4df804bd1d46bb68164601220446f5f2e4e506820948784400680830
 * 00d08034: push {r4,r5,r6,r7,lr}
 * 00d08036: add r7,sp,#0xc
 * 00d08038: push.w r11
 * 00d0803c: mov r5,r3
 * 00d0803e: ldr r3,[r7,#0x8]
 * 00d08040: mov r6,r2
 * 00d08042: movs r2,#0x1
 * 00d08044: mov r4,r0
 * 00d08046: blx 0x013fdc10
 * 00d0804a: strh r6,[r0,#0x10]
 * 00d0804c: ldr r0,[0x00d08074]
 * 00d0804e: add r0,pc
 * 00d08050: ldr r0,[r0,#0x0]
 * 00d08052: adds r0,#0x8
 * 00d08054: str r0,[r4,#0x0]
 * 00d08056: add.w r0,r4,#0x14
 * 00d0805a: mov r1,r5
 * 00d0805c: bl 0x00cd5ef0
 * 00d08060: mov r0,r4
 * 00d08062: pop.w r11
 * 00d08066: pop {r4,r5,r6,r7,pc}
 * 00d08078: push {r4,r6,r7,lr}
 * 00d0807a: add r7,sp,#0x8
 * 00d0807c: mov r4,r0
 */


/* WriteDataByIdentifierCommand::WriteDataByIdentifierCommand(Ecu*, unsigned short,
   std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> > const&, unsigned int)
    */

WriteDataByIdentifierCommand * __thiscall
WriteDataByIdentifierCommand::WriteDataByIdentifierCommand
          (WriteDataByIdentifierCommand *this,Ecu *param_1,ushort param_2,vector *param_3,
          uint param_4)

{
  int iVar1;
  
  iVar1 = SingleResponseCommand<EmptyModel>::SingleResponseCommand
                    ((SingleResponseCommand<EmptyModel> *)this,param_1,1,param_4);
  *(ushort *)(iVar1 + 0x10) = param_2;
  *(undefined ***)this = &PTR__WriteDataByIdentifierCommand_0143bca8;
  FUN_00cd5ef0(this + 0x14,param_3);
  return this;
}


