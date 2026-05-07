# drl_via_fogs

Target address: `012cde7b` (Ghidra `012dde7b`)
Setting key: `car_setting_drl_via_fogs`
Recovered shape: official x86 6R/PQ25 branch later pushes CENTRAL_ELEC_6R_5C_7E_7H, DID 0600 byte 0x17 mask 0x04
Function: `<none>`

## 6R/PQ25 Constructor Summary (Deep RE 2026-05-08)

**Read path** (fully recovered):
- UDS read: `22 0600` → 30-byte response
- Extract: `VagSetting_extractValue(coding, offset=23, mask="04")`
  - `ByteUtils_getLsbOffset("04") = 2`; result = `(byte_23 & 0x04) >> 2`
  - Returns `"00"` = `car_setting_no` = DRL via fogs DISABLED
  - Returns `"01"` = `car_setting_yes` = DRL via fogs ENABLED
- Current live BCM (2026-05-07): byte 23 = `0x00` → `"00"` = DISABLED

**Write path** (guarded 2E0600, same sequence proven for cornering bits):
- Compute target: `VagSetting_insertValue(coding, offset=23, mask="04", requested="01")`
  - `ByteUtils_getLsbOffset("04") = 2`; shifted = `0x01 << 2 = 0x04`; byte 23 = `(0x00 & ~0x04) | 0x04 = 0x04`
- Current coding: `3AB82B9F08A10000003008006C680ED000C8412F60A60000200000000000`
- Target coding : `3AB82B9F08A10000003008006C680ED000C8412F60A60004200000000000` (byte 23: `00`→`04`)
- Sequence: `2EF199 YYMMDD` → `22F1A5` → `2EF198 workshop-code` → `2E0600 [target]` → `22 0600` verify

**Carista software — NO inter-setting dependency:**

`VagOperationDelegate::getVagSettingAvailabilityForEcu` (016b4180) evaluates each
`VagSetting` independently via `StringWhitelist::itemMatches`. Both `drl_via_fogs`
(byte 23 mask 0x04) and `cornering_lights_via_fogs` (byte 12 mask 0x40) are
independently available for `6R0937087K` through `CENTRAL_ELEC_6R_5C_7E_7H`.
No Carista software path gates one on the other.

After construction, caller dispatches vtable slot `+0x30` (method index 12) on the
setting object to push it into the settings collection — this is a ref-counted
object lifetime call, not an ECU read or write.

**BCM firmware hypothesis (not confirmed from Carista code):**

Physical observation: fogs activate as a steady paired output with low-beam linkage
and high-beam inhibit. No per-side cornering response to indicator inputs even though
all 4 cornering coding bits (byte 12 bit 6, byte 21 bits 2/5/7) are set.

Hypothesis: the DRL-via-fogs bit (byte 23, bit 2) may instruct the BCM firmware to
assign the fog hardware output channels to the per-side DRL driver path instead of
the single paired front-fog driver path. Without it the fog relays have no individual
addressing and cornering commands cannot route to left or right output independently.

This is the only CENTRAL_ELEC_6R_5C_7E_7H DID 0600 coding bit not set in the
current live BCM. All other relevant 6R bits are set and behaviour-disproven.

## Symbols At Target
- <none>

## Instruction Window

- `012cdca7` `PUSH dword ptr [EBP + 0xfffe8be0]` scalars: `0xFFFE8BE0` recovered: `local-0x17420->got=0x01a328b4:_ZN9VagUdsEcu12CENTRAL_ELECE`
- `012cdcad` `LEA EAX,[EBP + 0xffff7420]` scalars: `0xFFFF7420`
- `012cdcb3` `PUSH EAX`
- `012cdcb4` `PUSH EDX`
- `012cdcb5` `CALL 0x01370de0` refs: `UNCONDITIONAL_CALL -> 01360de0` `sym=SUB_01370de0`
- `012cdcba` `ADD ESP,0x2c` scalars: `0x2C`
- `012cdcbd` `MOVSD XMM0,qword ptr [EBP + 0xffff0200]` scalars: `0xFFFF0200`
- `012cdcc5` `MOVSD qword ptr [EBP + 0xffffa840],XMM0` scalars: `0xFFFFA840`
- `012cdccd` `MOV dword ptr [EBP + 0xffff0200],0x0` scalars: `0xFFFF0200` `0x0`
- `012cdcd7` `MOV dword ptr [EBP + 0xffff0204],0x0` scalars: `0xFFFF0204` `0x0`
- `012cdce1` `LEA EDI,[EBP + 0xffffa848]` scalars: `0xFFFFA848`
- `012cdce7` `MOV dword ptr [EBP + 0xffff01c0],0xf` scalars: `0xFFFF01C0` `0xF`
- `012cdcf1` `MOV dword ptr [EBP + 0xffff01bc],0x40` scalars: `0xFFFF01BC` `0x40`
- `012cdcfb` `LEA EAX,[EBP + 0xffff01bc]` scalars: `0xFFFF01BC`
- `012cdd01` `LEA ECX,[EBP + 0xffff01c0]` scalars: `0xFFFF01C0`
- `012cdd07` `LEA EDX,[EBP + 0xffff01c4]` scalars: `0xFFFF01C4`
- `012cdd0d` `PUSH dword ptr [EBP + 0xfffe8be4]` scalars: `0xFFFE8BE4` recovered: `local-0x1741c->got=0x01a2fd78:_ZN28MultipleChoiceInterpretation6YES_NOE`
- `012cdd13` `PUSH dword ptr [EBP + 0xfffe8b78]` scalars: `0xFFFE8B78` recovered: `local-0x17488->str=0x00526857:car_setting_drl_via_separate_lights`
- `012cdd19` `PUSH EAX`
- `012cdd1a` `PUSH ECX`
- `012cdd1b` `PUSH dword ptr [EBP + 0xfffe8b34]` scalars: `0xFFFE8B34` recovered: `local-0x174cc->got=0x01a32b84:_ZN13VagWhitelists22CENTRAL_ELEC_MK6_8X_B7E`
- `012cdd21` `PUSH dword ptr [EBP + 0xfffe8bcc]` scalars: `0xFFFE8BCC` recovered: `local-0x17434->got=0x01a327bc:_ZN9VagCanEcu12CENTRAL_ELECE`
- `012cdd27` `LEA EAX,[EBP + 0xffff7420]` scalars: `0xFFFF7420`
- `012cdd2d` `PUSH EAX`
- `012cdd2e` `PUSH EDX`
- `012cdd2f` `CALL 0x01355b60` refs: `UNCONDITIONAL_CALL -> 01345b60` `sym=SUB_01355b60`
- `012cdd34` `ADD ESP,0x1c` scalars: `0x1C`
- `012cdd37` `MOV ESI,dword ptr [EBP + 0xffff01c4]` scalars: `0xFFFF01C4`
- `012cdd3d` `SUB ESP,0x8` scalars: `0x8`
- `012cdd40` `LEA EAX,[EBX + 0xfebf7e90]` scalars: `0xFEBF7E90` recovered: `ebx->str=0x0062d4a8:car_setting_instruction_drl_via_separate_lights_mk6_8x_b7`
- `012cdd46` `LEA ECX,[EBP + 0xffff01b0]` scalars: `0xFFFF01B0`
- `012cdd4c` `PUSH EAX` recovered: `EAX->str=0x0062d4a8:car_setting_instruction_drl_via_separate_lights_mk6_8x_b7`
- `012cdd4d` `PUSH ECX`
- `012cdd4e` `CALL 0x00bbb1c0` refs: `UNCONDITIONAL_CALL -> 00bab1c0` `sym=SUB_00bbb1c0`
- `012cdd53` `ADD ESP,0x10` scalars: `0x10`
- `012cdd56` `MOV EAX,dword ptr [ESI]`
- `012cdd58` `MOV EAX,dword ptr [EAX + 0x28]` scalars: `0x28`
- `012cdd5b` `SUB ESP,0x4` scalars: `0x4`
- `012cdd5e` `LEA ECX,[EBP + 0xffff01b0]` scalars: `0xFFFF01B0`
- `012cdd64` `PUSH ECX`
- `012cdd65` `PUSH ESI`
- `012cdd66` `PUSH EDI`
- `012cdd67` `CALL EAX`
- `012cdd69` `ADD ESP,0xc` scalars: `0xC`
- `012cdd6c` `LEA EDI,[EBP + 0xffffa850]` scalars: `0xFFFFA850`
- `012cdd72` `MOV dword ptr [EBP + 0xffff01a4],0x3` scalars: `0xFFFF01A4` `0x3`
- `012cdd7c` `MOV dword ptr [EBP + 0xffff01a0],0x10` scalars: `0xFFFF01A0` `0x10`
- `012cdd86` `LEA EAX,[EBP + 0xffff01a0]` scalars: `0xFFFF01A0`
- `012cdd8c` `LEA ECX,[EBP + 0xffff01a4]` scalars: `0xFFFF01A4`
- `012cdd92` `LEA EDX,[EBP + 0xffff01a8]` scalars: `0xFFFF01A8`
- `012cdd98` `PUSH dword ptr [EBP + 0xfffe8be4]` scalars: `0xFFFE8BE4` recovered: `local-0x1741c->got=0x01a2fd78:_ZN28MultipleChoiceInterpretation6YES_NOE`
- `012cdd9e` `PUSH dword ptr [EBP + 0xfffe8b78]` scalars: `0xFFFE8B78` recovered: `local-0x17488->str=0x00526857:car_setting_drl_via_separate_lights`
- `012cdda4` `PUSH EAX`
- `012cdda5` `PUSH ECX`
- `012cdda6` `PUSH dword ptr [EBP + 0xfffe8b74]` scalars: `0xFFFE8B74` recovered: `local-0x1748c->got=0x01a3287c:_ZN13VagWhitelists15CENTRAL_ELEC_B8E`
- `012cddac` `PUSH dword ptr [EBP + 0xfffe8bcc]` scalars: `0xFFFE8BCC` recovered: `local-0x17434->got=0x01a327bc:_ZN9VagCanEcu12CENTRAL_ELECE`
- `012cddb2` `LEA EAX,[EBP + 0xffff7420]` scalars: `0xFFFF7420`
- `012cddb8` `PUSH EAX`
- `012cddb9` `PUSH EDX`
- `012cddba` `CALL 0x01355b60` refs: `UNCONDITIONAL_CALL -> 01345b60` `sym=SUB_01355b60`
- `012cddbf` `ADD ESP,0x1c` scalars: `0x1C`
- `012cddc2` `MOVSD XMM0,qword ptr [EBP + 0xffff01a8]` scalars: `0xFFFF01A8`
- `012cddca` `MOVSD qword ptr [EBP + 0xffffa850],XMM0` scalars: `0xFFFFA850`
- `012cddd2` `MOV dword ptr [EBP + 0xffff01a8],0x0` scalars: `0xFFFF01A8` `0x0`
- `012cdddc` `MOV dword ptr [EBP + 0xffff01ac],0x0` scalars: `0xFFFF01AC` `0x0`
- `012cdde6` `LEA EDI,[EBP + 0xffffa858]` scalars: `0xFFFFA858`
- `012cddec` `MOV dword ptr [EBP + 0xffff0194],0x2` scalars: `0xFFFF0194` `0x2`
- `012cddf6` `MOV dword ptr [EBP + 0xffff0190],0x10` scalars: `0xFFFF0190` `0x10`
- `012cde00` `LEA EAX,[EBX + 0xfef3163c]` scalars: `0xFEF3163C` recovered: `ebx->str=0x00966c54:car_setting_drl_via_leds_where_applicable`
- `012cde06` `LEA ECX,[EBP + 0xffff0190]` scalars: `0xFFFF0190`
- `012cde0c` `LEA EDX,[EBP + 0xffff0194]` scalars: `0xFFFF0194`
- `012cde12` `LEA ESI,[EBP + 0xffff0198]` scalars: `0xFFFF0198`
- `012cde18` `PUSH dword ptr [EBP + 0xfffe8be4]` scalars: `0xFFFE8BE4` recovered: `local-0x1741c->got=0x01a2fd78:_ZN28MultipleChoiceInterpretation6YES_NOE`
- `012cde1e` `PUSH EAX` recovered: `EAX->str=0x00966c54:car_setting_drl_via_leds_where_applicable`
- `012cde1f` `PUSH ECX`
- `012cde20` `PUSH EDX`
- `012cde21` `PUSH dword ptr [EBP + 0xfffe8b74]` scalars: `0xFFFE8B74` recovered: `local-0x1748c->got=0x01a3287c:_ZN13VagWhitelists15CENTRAL_ELEC_B8E`
- `012cde27` `PUSH dword ptr [EBP + 0xfffe8bcc]` scalars: `0xFFFE8BCC` recovered: `local-0x17434->got=0x01a327bc:_ZN9VagCanEcu12CENTRAL_ELECE`
- `012cde2d` `LEA EAX,[EBP + 0xffff7420]` scalars: `0xFFFF7420`
- `012cde33` `PUSH EAX`
- `012cde34` `PUSH ESI`
- `012cde35` `CALL 0x01355f00` refs: `UNCONDITIONAL_CALL -> 01345f00` `sym=SUB_01355f00`
- `012cde3a` `ADD ESP,0x1c` scalars: `0x1C`
- `012cde3d` `MOVSD XMM0,qword ptr [EBP + 0xffff0198]` scalars: `0xFFFF0198`
- `012cde45` `MOVSD qword ptr [EBP + 0xffffa858],XMM0` scalars: `0xFFFFA858`
- `012cde4d` `MOV dword ptr [EBP + 0xffff0198],0x0` scalars: `0xFFFF0198` `0x0`
- `012cde57` `MOV dword ptr [EBP + 0xffff019c],0x0` scalars: `0xFFFF019C` `0x0`
- `012cde61` `LEA EDI,[EBP + 0xffffa860]` scalars: `0xFFFFA860`
- `012cde67` `MOV dword ptr [EBP + 0xffff0184],0x17` scalars: `0xFFFF0184` `0x17`
- `012cde71` `MOV dword ptr [EBP + 0xffff0180],0x4` scalars: `0xFFFF0180` `0x4`
- `012cde7b` **=>** `LEA ESI,[EBX + 0xfece7f28]` scalars: `0xFECE7F28` recovered: `ebx->str=0x0071d540:car_setting_drl_via_fogs`
- `012cde81` `LEA EAX,[EBP + 0xffff0180]` scalars: `0xFFFF0180`
- `012cde87` `LEA ECX,[EBP + 0xffff0184]` scalars: `0xFFFF0184`
- `012cde8d` `LEA EDX,[EBP + 0xffff0188]` scalars: `0xFFFF0188`
- `012cde93` `PUSH dword ptr [EBP + 0xfffe8be4]` scalars: `0xFFFE8BE4` recovered: `local-0x1741c->got=0x01a2fd78:_ZN28MultipleChoiceInterpretation6YES_NOE`
- `012cde99` `MOV dword ptr [EBP + 0xfffe8b98],ESI` scalars: `0xFFFE8B98` recovered: `ESI->str=0x0071d540:car_setting_drl_via_fogs`
- `012cde9f` `PUSH ESI` recovered: `ESI->str=0x0071d540:car_setting_drl_via_fogs`
- `012cdea0` `PUSH EAX`
- `012cdea1` `PUSH ECX`
- `012cdea2` `PUSH dword ptr [EBP + 0xfffe8b3c]` scalars: `0xFFFE8B3C` recovered: `local-0x174c4->got=0x01a32b6c:_ZN13VagWhitelists24CENTRAL_ELEC_6R_5C_7E_7HE`
- `012cdea8` `PUSH dword ptr [EBP + 0xfffe8bcc]` scalars: `0xFFFE8BCC` recovered: `local-0x17434->got=0x01a327bc:_ZN9VagCanEcu12CENTRAL_ELECE`
- `012cdeae` `LEA EAX,[EBP + 0xffff7420]` scalars: `0xFFFF7420`
- `012cdeb4` `PUSH EAX`
- `012cdeb5` `PUSH EDX`
- `012cdeb6` `CALL 0x01371520` refs: `UNCONDITIONAL_CALL -> 01361520` `sym=SUB_01371520`
- `012cdebb` `ADD ESP,0x1c` scalars: `0x1C`
- `012cdebe` `MOV EAX,dword ptr [EBP + 0xffff0188]` scalars: `0xFFFF0188`
- `012cdec4` `MOV ECX,dword ptr [EAX]`
- `012cdec6` `MOV ECX,dword ptr [ECX + 0x30]` scalars: `0x30`
- `012cdec9` `SUB ESP,0x8` scalars: `0x8`
- `012cdecc` `PUSH EAX`
- `012cdecd` `PUSH EDI`
- `012cdece` `CALL ECX`
- `012cded0` `ADD ESP,0xc` scalars: `0xC`
- `012cded3` `LEA EDI,[EBP + 0xffffa868]` scalars: `0xFFFFA868`
- `012cded9` `MOV dword ptr [EBP + 0xffff0174],0x11` scalars: `0xFFFF0174` `0x11`
- `012cdee3` `MOV dword ptr [EBP + 0xffff0170],0x10` scalars: `0xFFFF0170` `0x10`
- `012cdeed` `LEA EAX,[EBP + 0xffff0170]` scalars: `0xFFFF0170`
- `012cdef3` `LEA ECX,[EBP + 0xffff0174]` scalars: `0xFFFF0174`
- `012cdef9` `MOV ESI,dword ptr [EBX + 0xffffd5a0]` scalars: `0xFFFFD5A0` recovered: `ebx->got=0x01a32bb8:_ZN13VagWhitelists21CENTRAL_ELEC_MK5_HIGHE`
- `012cdeff` `LEA EDX,[EBP + 0xffff0178]` scalars: `0xFFFF0178`
- `012cdf05` `PUSH dword ptr [EBP + 0xfffe8be4]` scalars: `0xFFFE8BE4` recovered: `local-0x1741c->got=0x01a2fd78:_ZN28MultipleChoiceInterpretation6YES_NOE`
- `012cdf0b` `PUSH dword ptr [EBP + 0xfffe8b98]` scalars: `0xFFFE8B98` recovered: `local-0x17468->str=0x0071d540:car_setting_drl_via_fogs`
- `012cdf11` `PUSH EAX`
- `012cdf12` `PUSH ECX`
- `012cdf13` `MOV dword ptr [EBP + 0xfffe8b20],ESI` scalars: `0xFFFE8B20` recovered: `ESI->got=0x01a32bb8:_ZN13VagWhitelists21CENTRAL_ELEC_MK5_HIGHE`
- `012cdf19` `PUSH ESI` recovered: `ESI->got=0x01a32bb8:_ZN13VagWhitelists21CENTRAL_ELEC_MK5_HIGHE`
- `012cdf1a` `PUSH dword ptr [EBP + 0xfffe8bcc]` scalars: `0xFFFE8BCC` recovered: `local-0x17434->got=0x01a327bc:_ZN9VagCanEcu12CENTRAL_ELECE`
- `012cdf20` `LEA EAX,[EBP + 0xffff7420]` scalars: `0xFFFF7420`
- `012cdf26` `PUSH EAX`
- `012cdf27` `PUSH EDX`
- `012cdf28` `CALL 0x01373440` refs: `UNCONDITIONAL_CALL -> 01363440` `sym=SUB_01373440`
- `012cdf2d` `ADD ESP,0x1c` scalars: `0x1C`
- `012cdf30` `MOVSD XMM0,qword ptr [EBP + 0xffff0178]` scalars: `0xFFFF0178`
- `012cdf38` `MOVSD qword ptr [EBP + 0xffffa868],XMM0` scalars: `0xFFFFA868`
- `012cdf40` `MOV dword ptr [EBP + 0xffff0178],0x0` scalars: `0xFFFF0178` `0x0`
- `012cdf4a` `MOV dword ptr [EBP + 0xffff017c],0x0` scalars: `0xFFFF017C` `0x0`
- `012cdf54` `LEA EDI,[EBP + 0xffffa870]` scalars: `0xFFFFA870`
- `012cdf5a` `MOV dword ptr [EBP + 0xffff0164],0xe` scalars: `0xFFFF0164` `0xE`
- `012cdf64` `MOV dword ptr [EBP + 0xffff0160],0x2` scalars: `0xFFFF0160` `0x2`
- `012cdf6e` `LEA EAX,[EBP + 0xffff0160]` scalars: `0xFFFF0160`
- `012cdf74` `LEA ECX,[EBP + 0xffff0164]` scalars: `0xFFFF0164`
- `012cdf7a` `LEA EDX,[EBP + 0xffff0168]` scalars: `0xFFFF0168`
- `012cdf80` `PUSH dword ptr [EBP + 0xfffe8be4]` scalars: `0xFFFE8BE4` recovered: `local-0x1741c->got=0x01a2fd78:_ZN28MultipleChoiceInterpretation6YES_NOE`
- `012cdf86` `PUSH dword ptr [EBP + 0xfffe8b98]` scalars: `0xFFFE8B98` recovered: `local-0x17468->str=0x0071d540:car_setting_drl_via_fogs`
- `012cdf8c` `PUSH EAX`
- `012cdf8d` `PUSH ECX`
- `012cdf8e` `PUSH dword ptr [EBP + 0xfffe8b34]` scalars: `0xFFFE8B34` recovered: `local-0x174cc->got=0x01a32b84:_ZN13VagWhitelists22CENTRAL_ELEC_MK6_8X_B7E`
- `012cdf94` `PUSH dword ptr [EBP + 0xfffe8bcc]` scalars: `0xFFFE8BCC` recovered: `local-0x17434->got=0x01a327bc:_ZN9VagCanEcu12CENTRAL_ELECE`
- `012cdf9a` `LEA EAX,[EBP + 0xffff7420]` scalars: `0xFFFF7420`
- `012cdfa0` `PUSH EAX`
- `012cdfa1` `PUSH EDX`
- `012cdfa2` `CALL 0x01371520` refs: `UNCONDITIONAL_CALL -> 01361520` `sym=SUB_01371520`
- `012cdfa7` `ADD ESP,0x1c` scalars: `0x1C`
- `012cdfaa` `MOV ESI,dword ptr [EBP + 0xffff0168]` scalars: `0xFFFF0168`
- `012cdfb0` `SUB ESP,0x8` scalars: `0x8`
- `012cdfb3` `LEA EAX,[EBX + 0xfebd1a34]` scalars: `0xFEBD1A34` recovered: `ebx->str=0x0060704c:car_setting_instruction_drl_via_fogs_mk6_8x_b7`
- `012cdfb9` `LEA ECX,[EBP + 0xffff0154]` scalars: `0xFFFF0154`
- `012cdfbf` `PUSH EAX` recovered: `EAX->str=0x0060704c:car_setting_instruction_drl_via_fogs_mk6_8x_b7`
- `012cdfc0` `PUSH ECX`
- `012cdfc1` `CALL 0x00bbb1c0` refs: `UNCONDITIONAL_CALL -> 00bab1c0` `sym=SUB_00bbb1c0`
- `012cdfc6` `ADD ESP,0x10` scalars: `0x10`
- `012cdfc9` `MOV EAX,dword ptr [ESI]`
- `012cdfcb` `MOV EAX,dword ptr [EAX + 0x28]` scalars: `0x28`
- `012cdfce` `SUB ESP,0x4` scalars: `0x4`
- `012cdfd1` `LEA ECX,[EBP + 0xffff0154]` scalars: `0xFFFF0154`
- `012cdfd7` `PUSH ECX`
- `012cdfd8` `PUSH ESI`
- `012cdfd9` `PUSH EDI`
- `012cdfda` `CALL EAX`
- `012cdfdc` `ADD ESP,0xc` scalars: `0xC`
- `012cdfdf` `LEA EDI,[EBP + 0xffffa878]` scalars: `0xFFFFA878`
- `012cdfe5` `MOV dword ptr [EBP + 0xffff0144],0x2` scalars: `0xFFFF0144` `0x2`
- `012cdfef` `MOV dword ptr [EBP + 0xffff0140],0x8` scalars: `0xFFFF0140` `0x8`
- `012cdff9` `LEA EAX,[EBP + 0xffff0140]` scalars: `0xFFFF0140`
- `012cdfff` `LEA ECX,[EBP + 0xffff0144]` scalars: `0xFFFF0144`
- `012ce005` `LEA EDX,[EBP + 0xffff0148]` scalars: `0xFFFF0148`
- `012ce00b` `PUSH dword ptr [EBP + 0xfffe8be4]` scalars: `0xFFFE8BE4` recovered: `local-0x1741c->got=0x01a2fd78:_ZN28MultipleChoiceInterpretation6YES_NOE`
- `012ce011` `PUSH dword ptr [EBP + 0xfffe8b98]` scalars: `0xFFFE8B98` recovered: `local-0x17468->str=0x0071d540:car_setting_drl_via_fogs`
- `012ce017` `PUSH EAX`
- `012ce018` `PUSH ECX`
- `012ce019` `PUSH dword ptr [EBP + 0xfffe8b74]` scalars: `0xFFFE8B74` recovered: `local-0x1748c->got=0x01a3287c:_ZN13VagWhitelists15CENTRAL_ELEC_B8E`
- `012ce01f` `PUSH dword ptr [EBP + 0xfffe8bcc]` scalars: `0xFFFE8BCC` recovered: `local-0x17434->got=0x01a327bc:_ZN9VagCanEcu12CENTRAL_ELECE`
- `012ce025` `LEA EAX,[EBP + 0xffff7420]` scalars: `0xFFFF7420`
- `012ce02b` `PUSH EAX`
- `012ce02c` `PUSH EDX`
- `012ce02d` `CALL 0x01371520` refs: `UNCONDITIONAL_CALL -> 01361520` `sym=SUB_01371520`
- `012ce032` `ADD ESP,0x1c` scalars: `0x1C`
- `012ce035` `MOVSD XMM0,qword ptr [EBP + 0xffff0148]` scalars: `0xFFFF0148`
- `012ce03d` `MOVSD qword ptr [EBP + 0xffffa878],XMM0` scalars: `0xFFFFA878`
- `012ce045` `MOV dword ptr [EBP + 0xffff0148],0x0` scalars: `0xFFFF0148` `0x0`
- `012ce04f` `MOV dword ptr [EBP + 0xffff014c],0x0` scalars: `0xFFFF014C` `0x0`
- `012ce059` `LEA EDI,[EBP + 0xffffa880]` scalars: `0xFFFFA880`
- `012ce05f` `MOV dword ptr [EBP + 0xffff0134],0x55c` scalars: `0xFFFF0134` `0x55C`
- `012ce069` `MOV dword ptr [EBP + 0xffff0130],0x6` scalars: `0xFFFF0130` `0x6`
- `012ce073` `MOV dword ptr [EBP + 0xffff012c],0xff` scalars: `0xFFFF012C` `0xFF`
- `012ce07d` `MOV dword ptr [EBP + 0xffffa55c],0x0` scalars: `0xFFFFA55C` `0x0`
- `012ce087` `MOV dword ptr [EBP + 0xffffa558],0x14` scalars: `0xFFFFA558` `0x14`
- `012ce091` `MOV EAX,dword ptr [EBP + 0xfffe8b54]` scalars: `0xFFFE8B54` recovered: `local-0x174ac->str=0x00a1f438:car_setting_enabled`
- `012ce097` `MOV dword ptr [EBP + 0xffffa560],EAX` scalars: `0xFFFFA560` recovered: `EAX->str=0x00a1f438:car_setting_enabled`
- `012ce09d` `MOV dword ptr [EBP + 0xffffa568],0x0` scalars: `0xFFFFA568` `0x0`
- `012ce0a7` `MOV dword ptr [EBP + 0xffffa564],0x0` scalars: `0xFFFFA564` `0x0`
- `012ce0b1` `MOV EAX,dword ptr [EBP + 0xfffe8ba4]` scalars: `0xFFFE8BA4` recovered: `local-0x1745c->str=0x00970e3a:car_setting_disabled`
- `012ce0b7` `MOV dword ptr [EBP + 0xffffa56c],EAX` scalars: `0xFFFFA56C` recovered: `EAX->str=0x00970e3a:car_setting_disabled`
- `012ce0bd` `LEA EAX,[EBP + 0xffffa558]` scalars: `0xFFFFA558`
- `012ce0c3` `MOV dword ptr [EBP + 0xffff0110],EAX` scalars: `0xFFFF0110`
- `012ce0c9` `MOV dword ptr [EBP + 0xffff0114],0x2` scalars: `0xFFFF0114` `0x2`
- `012ce0d3` `SUB ESP,0x10` scalars: `0x10`
- `012ce0d6` `MOVSD XMM0,qword ptr [EBP + 0xffff0110]` scalars: `0xFFFF0110`
- `012ce0de` `MOVSD qword ptr [ESP + 0x4],XMM0` scalars: `0x4`
