/*
 * GetVagUdsEcuWorkshopCodeCommand_processPayload
 * ELF symbol address: 0x00D050AC
 * Ghidra address: 0x00D150AC (ELF + 0x10000 image delta)
 * ELF symbol size: 104 bytes
 * Symbol: _ZNK31GetVagUdsEcuWorkshopCodeCommand14processPayloadERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE
 * Program: libCarista.so
 * Resolved function: GetVagUdsEcuWorkshopCodeCommand::processPayload @ 00d150ac
 * Signature: undefined __stdcall processPayload(vector * param_1)
 * Return type: undefined
 * Function body: [[00d150ac, 00d15101]]
 * Parameters:
 *   [0] vector * param_1
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 0143c850
 * Direct callees/references:
 *   READ 00d1510c from 00d150b4
 *   READ 014da87c from 00d150b8
 *   READ 015a7014 from 00d150ba
 *   WRITE Stack[-0x14] from 00d150bc
 *   CONDITIONAL_JUMP GetVagUdsEcuWorkshopCodeCommand::processPayload @ 00d150ac from 00d150c6
 *   UNCONDITIONAL_CALL BytesModel::BytesModel @ 013fdb50 from 00d150ce
 *   UNCONDITIONAL_CALL Result<BytesModel,void>::done<BytesModel> @ 013fdb60 from 00d150d6
 *   UNCONDITIONAL_CALL BytesModel::~BytesModel @ 013fdb70 from 00d150dc
 *   UNCONDITIONAL_JUMP GetVagUdsEcuWorkshopCodeCommand::processPayload @ 00d150ac from 00d150e0
 *   UNCONDITIONAL_CALL Result<BytesModel,void>::Result @ 013fdba0 from 00d150e8
 *   READ Stack[-0x14] from 00d150ec
 *   READ 00d15110 from 00d150ee
 *   READ 014da87c from 00d150f2
 *   READ 015a7014 from 00d150f4
 *   UNCONDITIONAL_CALL <EXTERNAL>::__stack_chk_fail @ 013fa400 from 00d150fe
 */

/* Ghidra function: GetVagUdsEcuWorkshopCodeCommand::processPayload @ 00d150ac */

/* First instructions after recreation:
 * Memory bytes: b0b502af86b0044615487844006800680590d2e90001081a06280cd101ad1146
 * 00d150ac: push {r4,r5,r7,lr}
 * 00d150ae: add r7,sp,#0x8
 * 00d150b0: sub sp,#0x18
 * 00d150b2: mov r4,r0
 * 00d150b4: ldr r0,[0x00d1510c]
 * 00d150b6: add r0,pc
 * 00d150b8: ldr r0,[r0,#0x0]
 * 00d150ba: ldr r0,[r0,#0x0]
 * 00d150bc: str r0,[sp,#0x14]
 * 00d150be: ldrd r0,r1,[r2,#0x0]
 * 00d150c2: subs r0,r1,r0
 * 00d150c4: cmp r0,#0x6
 * 00d150c6: bne 0x00d150e2
 * 00d150c8: add r5,sp,#0x4
 * 00d150ca: mov r1,r2
 * 00d150cc: mov r0,r5
 * 00d150ce: blx 0x013fdb50
 * 00d150d2: mov r0,r4
 * 00d150d4: mov r1,r5
 * 00d150d6: blx 0x013fdb60
 * 00d150da: add r0,sp,#0x4
 * 00d150dc: blx 0x013fdb70
 * 00d150e0: b 0x00d150ec
 * 00d150e2: mov r0,r4
 */


/* GetVagUdsEcuWorkshopCodeCommand::processPayload(std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&) const */

void GetVagUdsEcuWorkshopCodeCommand::processPayload(vector *param_1)

{
  vector *in_r2;
  BytesModel aBStack_24 [16];
  int local_14;
  
  local_14 = __stack_chk_guard;
  if (*(int *)(in_r2 + 4) - *(int *)in_r2 == 6) {
    BytesModel::BytesModel(aBStack_24,in_r2);
    Result<BytesModel,void>::done<BytesModel>((type *)param_1);
    BytesModel::~BytesModel(aBStack_24);
  }
  else {
    Result<BytesModel,void>::Result((Result<BytesModel,void> *)param_1,-6);
  }
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


