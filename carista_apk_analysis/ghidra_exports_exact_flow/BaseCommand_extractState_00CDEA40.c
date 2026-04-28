/*
 * BaseCommand_extractState
 * ELF symbol address: 0x00CCEA40
 * Ghidra address: 0x00CDEA40 (ELF + 0x10000 image delta)
 * ELF symbol size: 236 bytes
 * Symbol: _ZN11BaseCommand12extractStateERKNSt6__ndk16vectorIhNS0_9allocatorIhEEEE
 * Program: libCarista.so
 * Resolved function: BaseCommand::extractState @ 00cdea40
 * Signature: undefined __stdcall extractState(vector * param_1)
 * Return type: undefined
 * Function body: [[00cdea40, 00cdea9b] [00cdeaae, 00cdeab7] [00cdeac0, 00cdeacd] [00cdead2, 00cdeb2b]]
 * Parameters:
 *   [0] vector * param_1
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 014e1e40
 *   BaseCommand::extractState @ 013fd5b0 -> COMPUTED_CALL from 013fd5b8
 * Direct callees/references:
 *   CONDITIONAL_JUMP BaseCommand::extractState @ 00cdea40 from 00cdea4e
 *   UNCONDITIONAL_CALL FUN_00cdeb2c @ 00cdeb2c from 00cdea54
 *   CONDITIONAL_JUMP BaseCommand::extractState @ 00cdea40 from 00cdea5c
 *   UNCONDITIONAL_CALL FUN_00cdeb2c @ 00cdeb2c from 00cdea62
 *   CONDITIONAL_JUMP BaseCommand::extractState @ 00cdea40 from 00cdea6e
 *   CONDITIONAL_JUMP BaseCommand::extractState @ 00cdea40 from 00cdea76
 *   CONDITIONAL_JUMP BaseCommand::extractState @ 00cdea40 from 00cdea7e
 *   CONDITIONAL_JUMP BaseCommand::extractState @ 00cdea40 from 00cdea82
 *   CONDITIONAL_JUMP BaseCommand::extractState @ 00cdea40 from 00cdea88
 *   CONDITIONAL_JUMP BaseCommand::extractState @ 00cdea40 from 00cdea8c
 *   COMPUTED_JUMP BaseCommand::extractState @ 00cdea40 from 00cdea98
 *   COMPUTED_JUMP BaseCommand::extractState @ 00cdea40 from 00cdeab4
 *   COMPUTED_JUMP BaseCommand::extractState @ 00cdea40 from 00cdeaca
 *   DATA 00cdeabe from 00cdeaca
 */

/* Ghidra function: BaseCommand::extractState @ 00cdea40 */

/* First instructions after recreation:
 * Memory bytes: d0b502af0446d0e90001081a032821d12046002100f06af800787f281ad12046
 * 00cdea40: push {r4,r6,r7,lr}
 * 00cdea42: add r7,sp,#0x8
 * 00cdea44: mov r4,r0
 * 00cdea46: ldrd r0,r1,[r0,#0x0]
 * 00cdea4a: subs r0,r1,r0
 * 00cdea4c: cmp r0,#0x3
 * 00cdea4e: bne 0x00cdea94
 * 00cdea50: mov r0,r4
 * 00cdea52: movs r1,#0x0
 * 00cdea54: bl 0x00cdeb2c
 * 00cdea58: ldrb r0,[r0,#0x0]
 * 00cdea5a: cmp r0,#0x7f
 * 00cdea5c: bne 0x00cdea94
 * 00cdea5e: mov r0,r4
 * 00cdea60: movs r1,#0x2
 * 00cdea62: bl 0x00cdeb2c
 * 00cdea66: ldrb r0,[r0,#0x0]
 * 00cdea68: sub.w r1,r0,#0x78
 * 00cdea6c: cmp r1,#0x10
 * 00cdea6e: bls 0x00cdea98
 * 00cdea70: sub.w r1,r0,#0x31
 * 00cdea74: cmp r1,#0x6
 * 00cdea76: bls 0x00cdeab4
 * 00cdea78: sub.w r1,r0,#0x10
 */


/* BaseCommand::extractState(std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned
   char> > const&) */

undefined4 BaseCommand::extractState(vector *param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if ((*(int *)(param_1 + 4) - *(int *)param_1 != 3) ||
     (pcVar2 = (char *)FUN_00cdeb2c(param_1,0), *pcVar2 != '\x7f')) {
    return 1;
  }
  pcVar2 = (char *)FUN_00cdeb2c(param_1,2);
  cVar1 = *pcVar2;
  switch(cVar1) {
  case 'x':
    return 0xffffffef;
  case 'y':
  case 'z':
  case '{':
  case '|':
  case '}':
  case -0x7e:
  case -0x7b:
  case -0x7a:
  case -0x79:
    goto switchD_00cdeab4_caseD_32;
  case '~':
  case '\x7f':
    return 0xffffffdd;
  case -0x80:
    return 0xffffffd7;
  case -0x7f:
  case -0x7d:
    return 0xffffffe3;
  case -0x7c:
    return 0xffffffd3;
  case -0x78:
    return 0xffffffe2;
  default:
    switch(cVar1) {
    case '1':
      return 0xffffffe0;
    case '2':
    case '4':
      break;
    case '3':
      return 0xffffffe1;
    case '5':
      return 0xffffffdc;
    case '6':
      return 0xffffffcf;
    case '7':
      return 0xffffffd0;
    default:
      uVar3 = 0xffffffda;
      switch(cVar1) {
      case '\x10':
        goto switchD_00cdeaca_caseD_10;
      case '\x11':
        return 0xffffffd9;
      case '\x12':
        return 0xffffffd8;
      case '\x13':
        return 0xffffffd5;
      default:
        if (cVar1 == '!') {
          return 0xffffffea;
        }
        if (cVar1 == '\"') {
          return 0xffffffde;
        }
        if (cVar1 == '$') {
          return 0xffffffdf;
        }
      }
    }
switchD_00cdeab4_caseD_32:
    uVar3 = 0xfffffff6;
switchD_00cdeaca_caseD_10:
    return uVar3;
  }
}


