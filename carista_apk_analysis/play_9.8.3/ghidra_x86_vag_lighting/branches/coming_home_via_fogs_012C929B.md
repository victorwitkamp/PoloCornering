# coming_home_via_fogs

Target address: `012c929b` (Ghidra `012d929b`)
Setting key: `car_setting_coming_home_via_fogs`
Recovered shape: lighting output branch cluster; x86 direct branch observed as non-6R/B8-style until availability is recovered
Function: `<none>`

## 6R/PQ25 Status

**CONFIRMED NO 6R BRANCH** (2026-05-08 deep RE pass).

All sub-branches in this cluster use non-6R whitelists:
- `car_setting_coming_leaving_home_via_reverse_left/right` → `CENTRAL_ELEC_MK7_ALL` + access code `UDS_CENTRAL_ELEC_MK7`
- `car_setting_coming_home_via_fogs` (at `012c929b`) → `CENTRAL_ELEC_B8`
- `car_setting_coming_leaving_home_turn_signal_left/right` → `CENTRAL_ELEC_MQB_ALL` + access code `UDS_CENTRAL_ELEC_MK7`

There is no 6R/PQ25 sub-branch for any coming-home fog setting in this cluster.
On 6R/PQ25, the coming-home fog output role is controlled only by DID 0600
long-coding bit: byte 13, bit 6 (mask 0x40), mapped to
`car_setting_coming_home_via_fogs` / `car_setting_coming_leaving_home_output`
in the catalog.  No separate UDS adaptation DID exists for this function on PQ25.

`B8` branch parameters for reference (NOT 6R):
  byte_index = 6, mask = 0x20 (bit 5), YES_NO, VagCanEcu::CENTRAL_ELEC,
  callee = SUB_01340190

## Instruction Window

- `012c90c9` `MOV dword ptr [ESP],ESI`
- `012c90cc` `CALL 0x00c17c90` refs: `UNCONDITIONAL_CALL -> 00c07c90` `sym=SUB_00c17c90`
- `012c90d1` `ADD ESP,0x10` scalars: `0x10`
- `012c90d4` `SUB ESP,0x8` scalars: `0x8`
- `012c90d7` `LEA EAX,[EBP + 0xffff0dfc]` scalars: `0xFFFF0DFC`
- `012c90dd` `PUSH ESI`
- `012c90de` `PUSH EAX`
- `012c90df` `CALL 0x00c17c10` refs: `UNCONDITIONAL_CALL -> 00c07c10` `sym=SUB_00c17c10`
- `012c90e4` `ADD ESP,0xc` scalars: `0xC`
- `012c90e7` `SUB ESP,0x8` scalars: `0x8`
- `012c90ea` `LEA EDX,[EBX + 0xfef03a92]` scalars: `0xFEF03A92` recovered: `ebx->str=0x009390aa:car_setting_coming_leaving_home_via_reverse_left`
- `012c90f0` `MOV EAX,dword ptr [EBX + 0xffffd578]` scalars: `0xFFFFD578` recovered: `ebx->got=0x01a32b90:_ZN13VagWhitelists20CENTRAL_ELEC_MK7_ALLE`
- `012c90f6` `LEA ESI,[EBP + 0xffff0e10]` scalars: `0xFFFF0E10`
- `012c90fc` `PUSH dword ptr [EBP + 0xfffe8bd8]` scalars: `0xFFFE8BD8` recovered: `local-0x17428->got=0x01a3264c:_ZN13VagAccessCode20UDS_CENTRAL_ELEC_MK7E`
- `012c9102` `LEA ECX,[EBP + 0xffff0dfc]` scalars: `0xFFFF0DFC`
- `012c9108` `PUSH ECX`
- `012c9109` `PUSH EDX` recovered: `EDX->str=0x009390aa:car_setting_coming_leaving_home_via_reverse_left`
- `012c910a` `LEA ECX,[EBP + 0xffff0e04]` scalars: `0xFFFF0E04`
- `012c9110` `PUSH ECX`
- `012c9111` `LEA ECX,[EBP + 0xffff0e08]` scalars: `0xFFFF0E08`
- `012c9117` `PUSH ECX`
- `012c9118` `LEA ECX,[EBP + 0xffff0e0c]` scalars: `0xFFFF0E0C`
- `012c911e` `PUSH ECX`
- `012c911f` `MOV dword ptr [EBP + 0xfffe8bc0],EAX` scalars: `0xFFFE8BC0` recovered: `EAX->got=0x01a32b90:_ZN13VagWhitelists20CENTRAL_ELEC_MK7_ALLE`
- `012c9125` `PUSH EAX` recovered: `EAX->got=0x01a32b90:_ZN13VagWhitelists20CENTRAL_ELEC_MK7_ALLE`
- `012c9126` `PUSH dword ptr [EBP + 0xfffe8be0]` scalars: `0xFFFE8BE0` recovered: `local-0x17420->got=0x01a328b4:_ZN9VagUdsEcu12CENTRAL_ELECE`
- `012c912c` `LEA EAX,[EBP + 0xffff7420]` scalars: `0xFFFF7420`
- `012c9132` `PUSH EAX`
- `012c9133` `PUSH ESI`
- `012c9134` `CALL 0x01358190` refs: `UNCONDITIONAL_CALL -> 01348190` `sym=SUB_01358190`
- `012c9139` `ADD ESP,0x2c` scalars: `0x2C`
- `012c913c` `MOVSD XMM0,qword ptr [EBP + 0xffff0e10]` scalars: `0xFFFF0E10`
- `012c9144` `MOVSD qword ptr [EBP + 0xffffb240],XMM0` scalars: `0xFFFFB240`
- `012c914c` `MOV dword ptr [EBP + 0xffff0e10],0x0` scalars: `0xFFFF0E10` `0x0`
- `012c9156` `MOV dword ptr [EBP + 0xffff0e14],0x0` scalars: `0xFFFF0E14` `0x0`
- `012c9160` `LEA EDI,[EBP + 0xffffb248]` scalars: `0xFFFFB248`
- `012c9166` `MOV dword ptr [EBP + 0xffff0ddc],0x56d` scalars: `0xFFFF0DDC` `0x56D`
- `012c9170` `MOV dword ptr [EBP + 0xffff0dd8],0x5` scalars: `0xFFFF0DD8` `0x5`
- `012c917a` `MOV dword ptr [EBP + 0xffff0dd4],0xff` scalars: `0xFFFF0DD4` `0xFF`
- `012c9184` `MOV dword ptr [EBP + 0xffffae7c],0x0` scalars: `0xFFFFAE7C` `0x0`
- `012c918e` `MOV dword ptr [EBP + 0xffffae78],0x0` scalars: `0xFFFFAE78` `0x0`
- `012c9198` `MOV EAX,dword ptr [EBP + 0xfffe8ba4]` scalars: `0xFFFE8BA4` recovered: `local-0x1745c->str=0x00970e3a:car_setting_disabled`
- `012c919e` `MOV dword ptr [EBP + 0xffffae80],EAX` scalars: `0xFFFFAE80` recovered: `EAX->str=0x00970e3a:car_setting_disabled`
- `012c91a4` `MOV dword ptr [EBP + 0xffffae88],0x0` scalars: `0xFFFFAE88` `0x0`
- `012c91ae` `MOV dword ptr [EBP + 0xffffae84],0x1e` scalars: `0xFFFFAE84` `0x1E`
- `012c91b8` `MOV EAX,dword ptr [EBP + 0xfffe8b54]` scalars: `0xFFFE8B54` recovered: `local-0x174ac->str=0x00a1f438:car_setting_enabled`
- `012c91be` `MOV dword ptr [EBP + 0xffffae8c],EAX` scalars: `0xFFFFAE8C` recovered: `EAX->str=0x00a1f438:car_setting_enabled`
- `012c91c4` `LEA EAX,[EBP + 0xffffae78]` scalars: `0xFFFFAE78`
- `012c91ca` `MOV dword ptr [EBP + 0xffff0db8],EAX` scalars: `0xFFFF0DB8`
- `012c91d0` `MOV dword ptr [EBP + 0xffff0dbc],0x2` scalars: `0xFFFF0DBC` `0x2`
- `012c91da` `SUB ESP,0x10` scalars: `0x10`
- `012c91dd` `MOVSD XMM0,qword ptr [EBP + 0xffff0db8]` scalars: `0xFFFF0DB8`
- `012c91e5` `MOVSD qword ptr [ESP + 0x4],XMM0` scalars: `0x4`
- `012c91eb` `LEA ESI,[EBP + 0xffff0dc0]` scalars: `0xFFFF0DC0`
- `012c91f1` `MOV dword ptr [ESP],ESI`
- `012c91f4` `CALL 0x00c17c90` refs: `UNCONDITIONAL_CALL -> 00c07c90` `sym=SUB_00c17c90`
- `012c91f9` `ADD ESP,0x10` scalars: `0x10`
- `012c91fc` `SUB ESP,0x8` scalars: `0x8`
- `012c91ff` `LEA EAX,[EBP + 0xffff0dcc]` scalars: `0xFFFF0DCC`
- `012c9205` `PUSH ESI`
- `012c9206` `PUSH EAX`
- `012c9207` `CALL 0x00c17c10` refs: `UNCONDITIONAL_CALL -> 00c07c10` `sym=SUB_00c17c10`
- `012c920c` `ADD ESP,0xc` scalars: `0xC`
- `012c920f` `SUB ESP,0x8` scalars: `0x8`
- `012c9212` `LEA EAX,[EBX + 0xfeb04713]` scalars: `0xFEB04713` recovered: `ebx->str=0x00539d2b:car_setting_coming_leaving_home_via_reverse_right`
- `012c9218` `LEA ESI,[EBP + 0xffff0ddc]` scalars: `0xFFFF0DDC`
- `012c921e` `LEA EDX,[EBP + 0xffff0de0]` scalars: `0xFFFF0DE0`
- `012c9224` `PUSH dword ptr [EBP + 0xfffe8bd8]` scalars: `0xFFFE8BD8` recovered: `local-0x17428->got=0x01a3264c:_ZN13VagAccessCode20UDS_CENTRAL_ELEC_MK7E`
- `012c922a` `LEA ECX,[EBP + 0xffff0dcc]` scalars: `0xFFFF0DCC`
- `012c9230` `PUSH ECX`
- `012c9231` `PUSH EAX` recovered: `EAX->str=0x00539d2b:car_setting_coming_leaving_home_via_reverse_right`
- `012c9232` `LEA EAX,[EBP + 0xffff0dd4]` scalars: `0xFFFF0DD4`
- `012c9238` `PUSH EAX`
- `012c9239` `LEA EAX,[EBP + 0xffff0dd8]` scalars: `0xFFFF0DD8`
- `012c923f` `PUSH EAX`
- `012c9240` `PUSH ESI`
- `012c9241` `PUSH dword ptr [EBP + 0xfffe8bc0]` scalars: `0xFFFE8BC0` recovered: `local-0x17440->got=0x01a32b90:_ZN13VagWhitelists20CENTRAL_ELEC_MK7_ALLE`
- `012c9247` `PUSH dword ptr [EBP + 0xfffe8be0]` scalars: `0xFFFE8BE0` recovered: `local-0x17420->got=0x01a328b4:_ZN9VagUdsEcu12CENTRAL_ELECE`
- `012c924d` `LEA EAX,[EBP + 0xffff7420]` scalars: `0xFFFF7420`
- `012c9253` `PUSH EAX`
- `012c9254` `PUSH EDX`
- `012c9255` `CALL 0x0136d2e0` refs: `UNCONDITIONAL_CALL -> 0135d2e0` `sym=SUB_0136d2e0`
- `012c925a` `ADD ESP,0x2c` scalars: `0x2C`
- `012c925d` `MOVSD XMM0,qword ptr [EBP + 0xffff0de0]` scalars: `0xFFFF0DE0`
- `012c9265` `MOVSD qword ptr [EBP + 0xffffb248],XMM0` scalars: `0xFFFFB248`
- `012c926d` `MOV dword ptr [EBP + 0xffff0de0],0x0` scalars: `0xFFFF0DE0` `0x0`
- `012c9277` `MOV dword ptr [EBP + 0xffff0de4],0x0` scalars: `0xFFFF0DE4` `0x0`
- `012c9281` `LEA EDI,[EBP + 0xffffb250]` scalars: `0xFFFFB250`
- `012c9287` `MOV dword ptr [EBP + 0xffff0dac],0x6` scalars: `0xFFFF0DAC` `0x6`
- `012c9291` `MOV dword ptr [EBP + 0xffff0da8],0x20` scalars: `0xFFFF0DA8` `0x20`
- `012c929b` **=>** `LEA EAX,[EBX + 0xfecb6e65]` scalars: `0xFECB6E65` recovered: `ebx->str=0x006ec47d:car_setting_coming_home_via_fogs`
- `012c92a1` `LEA ECX,[EBP + 0xffff0da8]` scalars: `0xFFFF0DA8`
- `012c92a7` `LEA EDX,[EBP + 0xffff0dac]` scalars: `0xFFFF0DAC`
- `012c92ad` `LEA ESI,[EBP + 0xffff0db0]` scalars: `0xFFFF0DB0`
- `012c92b3` `PUSH dword ptr [EBP + 0xfffe8be4]` scalars: `0xFFFE8BE4` recovered: `local-0x1741c->got=0x01a2fd78:_ZN28MultipleChoiceInterpretation6YES_NOE`
- `012c92b9` `PUSH EAX` recovered: `EAX->str=0x006ec47d:car_setting_coming_home_via_fogs`
- `012c92ba` `PUSH ECX`
- `012c92bb` `PUSH EDX`
- `012c92bc` `PUSH dword ptr [EBP + 0xfffe8b74]` scalars: `0xFFFE8B74` recovered: `local-0x1748c->got=0x01a3287c:_ZN13VagWhitelists15CENTRAL_ELEC_B8E`
- `012c92c2` `PUSH dword ptr [EBP + 0xfffe8bcc]` scalars: `0xFFFE8BCC` recovered: `local-0x17434->got=0x01a327bc:_ZN9VagCanEcu12CENTRAL_ELECE`
- `012c92c8` `LEA EAX,[EBP + 0xffff7420]` scalars: `0xFFFF7420`
- `012c92ce` `PUSH EAX`
- `012c92cf` `PUSH ESI`
- `012c92d0` `CALL 0x01350190` refs: `UNCONDITIONAL_CALL -> 01340190` `sym=SUB_01350190`
- `012c92d5` `ADD ESP,0x1c` scalars: `0x1C`
- `012c92d8` `MOVSD XMM0,qword ptr [EBP + 0xffff0db0]` scalars: `0xFFFF0DB0`
- `012c92e0` `MOVSD qword ptr [EBP + 0xffffb250],XMM0` scalars: `0xFFFFB250`
- `012c92e8` `MOV dword ptr [EBP + 0xffff0db0],0x0` scalars: `0xFFFF0DB0` `0x0`
- `012c92f2` `MOV dword ptr [EBP + 0xffff0db4],0x0` scalars: `0xFFFF0DB4` `0x0`
- `012c92fc` `LEA EDI,[EBP + 0xffffb258]` scalars: `0xFFFFB258`
- `012c9302` `MOV dword ptr [EBP + 0xffff0d9c],0x550` scalars: `0xFFFF0D9C` `0x550`
- `012c930c` `MOV dword ptr [EBP + 0xffff0d98],0xd` scalars: `0xFFFF0D98` `0xD`
- `012c9316` `MOV dword ptr [EBP + 0xffff0d94],0xff` scalars: `0xFFFF0D94` `0xFF`
- `012c9320` `MOV dword ptr [EBP + 0xffffae64],0x0` scalars: `0xFFFFAE64` `0x0`
- `012c932a` `MOV dword ptr [EBP + 0xffffae60],0x0` scalars: `0xFFFFAE60` `0x0`
- `012c9334` `MOV EAX,dword ptr [EBP + 0xfffe8ba4]` scalars: `0xFFFE8BA4` recovered: `local-0x1745c->str=0x00970e3a:car_setting_disabled`
- `012c933a` `MOV dword ptr [EBP + 0xffffae68],EAX` scalars: `0xFFFFAE68` recovered: `EAX->str=0x00970e3a:car_setting_disabled`
- `012c9340` `MOV dword ptr [EBP + 0xffffae70],0x0` scalars: `0xFFFFAE70` `0x0`
- `012c934a` `MOV dword ptr [EBP + 0xffffae6c],0x1e` scalars: `0xFFFFAE6C` `0x1E`
- `012c9354` `MOV EAX,dword ptr [EBP + 0xfffe8b54]` scalars: `0xFFFE8B54` recovered: `local-0x174ac->str=0x00a1f438:car_setting_enabled`
- `012c935a` `MOV dword ptr [EBP + 0xffffae74],EAX` scalars: `0xFFFFAE74` recovered: `EAX->str=0x00a1f438:car_setting_enabled`
- `012c9360` `LEA EAX,[EBP + 0xffffae60]` scalars: `0xFFFFAE60`
- `012c9366` `MOV dword ptr [EBP + 0xffff0d78],EAX` scalars: `0xFFFF0D78`
- `012c936c` `MOV dword ptr [EBP + 0xffff0d7c],0x2` scalars: `0xFFFF0D7C` `0x2`
- `012c9376` `SUB ESP,0x10` scalars: `0x10`
- `012c9379` `MOVSD XMM0,qword ptr [EBP + 0xffff0d78]` scalars: `0xFFFF0D78`
- `012c9381` `MOVSD qword ptr [ESP + 0x4],XMM0` scalars: `0x4`
- `012c9387` `LEA ESI,[EBP + 0xffff0d80]` scalars: `0xFFFF0D80`
- `012c938d` `MOV dword ptr [ESP],ESI`
- `012c9390` `CALL 0x00c17c90` refs: `UNCONDITIONAL_CALL -> 00c07c90` `sym=SUB_00c17c90`
- `012c9395` `ADD ESP,0x10` scalars: `0x10`
- `012c9398` `SUB ESP,0x8` scalars: `0x8`
- `012c939b` `LEA EAX,[EBP + 0xffff0d8c]` scalars: `0xFFFF0D8C`
- `012c93a1` `PUSH ESI`
- `012c93a2` `PUSH EAX`
- `012c93a3` `CALL 0x00c17c10` refs: `UNCONDITIONAL_CALL -> 00c07c10` `sym=SUB_00c17c10`
- `012c93a8` `ADD ESP,0xc` scalars: `0xC`
- `012c93ab` `SUB ESP,0x8` scalars: `0x8`
- `012c93ae` `LEA EAX,[EBX + 0xfeb1bf4b]` scalars: `0xFEB1BF4B` recovered: `ebx->str=0x00551563:car_setting_coming_leaving_home_turn_signal_left`
- `012c93b4` `LEA ESI,[EBP + 0xffff0d9c]` scalars: `0xFFFF0D9C`
- `012c93ba` `LEA EDX,[EBP + 0xffff0da0]` scalars: `0xFFFF0DA0`
- `012c93c0` `PUSH dword ptr [EBP + 0xfffe8bd8]` scalars: `0xFFFE8BD8` recovered: `local-0x17428->got=0x01a3264c:_ZN13VagAccessCode20UDS_CENTRAL_ELEC_MK7E`
- `012c93c6` `LEA ECX,[EBP + 0xffff0d8c]` scalars: `0xFFFF0D8C`
- `012c93cc` `PUSH ECX`
- `012c93cd` `PUSH EAX` recovered: `EAX->str=0x00551563:car_setting_coming_leaving_home_turn_signal_left`
- `012c93ce` `LEA EAX,[EBP + 0xffff0d94]` scalars: `0xFFFF0D94`
- `012c93d4` `PUSH EAX`
- `012c93d5` `LEA EAX,[EBP + 0xffff0d98]` scalars: `0xFFFF0D98`
- `012c93db` `PUSH EAX`
- `012c93dc` `PUSH ESI`
- `012c93dd` `PUSH dword ptr [EBP + 0xfffe8b90]` scalars: `0xFFFE8B90` recovered: `local-0x17470->got=0x01a32b74:_ZN13VagWhitelists20CENTRAL_ELEC_MQB_ALLE`
- `012c93e3` `PUSH dword ptr [EBP + 0xfffe8be0]` scalars: `0xFFFE8BE0` recovered: `local-0x17420->got=0x01a328b4:_ZN9VagUdsEcu12CENTRAL_ELECE`
- `012c93e9` `LEA EAX,[EBP + 0xffff7420]` scalars: `0xFFFF7420`
- `012c93ef` `PUSH EAX`
- `012c93f0` `PUSH EDX`
- `012c93f1` `CALL 0x01358190` refs: `UNCONDITIONAL_CALL -> 01348190` `sym=SUB_01358190`
- `012c93f6` `ADD ESP,0x2c` scalars: `0x2C`
- `012c93f9` `MOVSD XMM0,qword ptr [EBP + 0xffff0da0]` scalars: `0xFFFF0DA0`
- `012c9401` `MOVSD qword ptr [EBP + 0xffffb258],XMM0` scalars: `0xFFFFB258`
- `012c9409` `MOV dword ptr [EBP + 0xffff0da0],0x0` scalars: `0xFFFF0DA0` `0x0`
- `012c9413` `MOV dword ptr [EBP + 0xffff0da4],0x0` scalars: `0xFFFF0DA4` `0x0`
- `012c941d` `LEA EDI,[EBP + 0xffffb260]` scalars: `0xFFFFB260`
- `012c9423` `MOV dword ptr [EBP + 0xffff0d6c],0x551` scalars: `0xFFFF0D6C` `0x551`
- `012c942d` `MOV dword ptr [EBP + 0xffff0d68],0xd` scalars: `0xFFFF0D68` `0xD`
- `012c9437` `MOV dword ptr [EBP + 0xffff0d64],0xff` scalars: `0xFFFF0D64` `0xFF`
- `012c9441` `MOV dword ptr [EBP + 0xffffae4c],0x0` scalars: `0xFFFFAE4C` `0x0`
- `012c944b` `MOV dword ptr [EBP + 0xffffae48],0x0` scalars: `0xFFFFAE48` `0x0`
- `012c9455` `MOV EAX,dword ptr [EBP + 0xfffe8ba4]` scalars: `0xFFFE8BA4` recovered: `local-0x1745c->str=0x00970e3a:car_setting_disabled`
- `012c945b` `MOV dword ptr [EBP + 0xffffae50],EAX` scalars: `0xFFFFAE50` recovered: `EAX->str=0x00970e3a:car_setting_disabled`
- `012c9461` `MOV dword ptr [EBP + 0xffffae58],0x0` scalars: `0xFFFFAE58` `0x0`
- `012c946b` `MOV dword ptr [EBP + 0xffffae54],0x1e` scalars: `0xFFFFAE54` `0x1E`
- `012c9475` `MOV EAX,dword ptr [EBP + 0xfffe8b54]` scalars: `0xFFFE8B54` recovered: `local-0x174ac->str=0x00a1f438:car_setting_enabled`
- `012c947b` `MOV dword ptr [EBP + 0xffffae5c],EAX` scalars: `0xFFFFAE5C` recovered: `EAX->str=0x00a1f438:car_setting_enabled`
- `012c9481` `LEA EAX,[EBP + 0xffffae48]` scalars: `0xFFFFAE48`
- `012c9487` `MOV dword ptr [EBP + 0xffff0d48],EAX` scalars: `0xFFFF0D48`
- `012c948d` `MOV dword ptr [EBP + 0xffff0d4c],0x2` scalars: `0xFFFF0D4C` `0x2`
- `012c9497` `SUB ESP,0x10` scalars: `0x10`
- `012c949a` `MOVSD XMM0,qword ptr [EBP + 0xffff0d48]` scalars: `0xFFFF0D48`
- `012c94a2` `MOVSD qword ptr [ESP + 0x4],XMM0` scalars: `0x4`
- `012c94a8` `LEA ESI,[EBP + 0xffff0d50]` scalars: `0xFFFF0D50`
- `012c94ae` `MOV dword ptr [ESP],ESI`
- `012c94b1` `CALL 0x00c17c90` refs: `UNCONDITIONAL_CALL -> 00c07c90` `sym=SUB_00c17c90`
- `012c94b6` `ADD ESP,0x10` scalars: `0x10`
- `012c94b9` `SUB ESP,0x8` scalars: `0x8`
- `012c94bc` `LEA EAX,[EBP + 0xffff0d5c]` scalars: `0xFFFF0D5C`
- `012c94c2` `PUSH ESI`
- `012c94c3` `PUSH EAX`
- `012c94c4` `CALL 0x00c17c10` refs: `UNCONDITIONAL_CALL -> 00c07c10` `sym=SUB_00c17c10`
- `012c94c9` `ADD ESP,0xc` scalars: `0xC`
- `012c94cc` `SUB ESP,0x8` scalars: `0x8`
- `012c94cf` `LEA EAX,[EBX + 0xfeeec2ed]` scalars: `0xFEEEC2ED` recovered: `ebx->str=0x00921905:car_setting_coming_leaving_home_turn_signal_right`
- `012c94d5` `LEA ESI,[EBP + 0xffff0d6c]` scalars: `0xFFFF0D6C`
- `012c94db` `LEA EDX,[EBP + 0xffff0d70]` scalars: `0xFFFF0D70`
- `012c94e1` `PUSH dword ptr [EBP + 0xfffe8bd8]` scalars: `0xFFFE8BD8` recovered: `local-0x17428->got=0x01a3264c:_ZN13VagAccessCode20UDS_CENTRAL_ELEC_MK7E`
- `012c94e7` `LEA ECX,[EBP + 0xffff0d5c]` scalars: `0xFFFF0D5C`
- `012c94ed` `PUSH ECX`
- `012c94ee` `PUSH EAX` recovered: `EAX->str=0x00921905:car_setting_coming_leaving_home_turn_signal_right`
- `012c94ef` `LEA EAX,[EBP + 0xffff0d64]` scalars: `0xFFFF0D64`
- `012c94f5` `PUSH EAX`
- `012c94f6` `LEA EAX,[EBP + 0xffff0d68]` scalars: `0xFFFF0D68`
- `012c94fc` `PUSH EAX`
- `012c94fd` `PUSH ESI`
- `012c94fe` `PUSH dword ptr [EBP + 0xfffe8b90]` scalars: `0xFFFE8B90` recovered: `local-0x17470->got=0x01a32b74:_ZN13VagWhitelists20CENTRAL_ELEC_MQB_ALLE`
- `012c9504` `PUSH dword ptr [EBP + 0xfffe8be0]` scalars: `0xFFFE8BE0` recovered: `local-0x17420->got=0x01a328b4:_ZN9VagUdsEcu12CENTRAL_ELECE`
- `012c950a` `LEA EAX,[EBP + 0xffff7420]` scalars: `0xFFFF7420`
- `012c9510` `PUSH EAX`
- `012c9511` `PUSH EDX`
- `012c9512` `CALL 0x0136d2e0` refs: `UNCONDITIONAL_CALL -> 0135d2e0` `sym=SUB_0136d2e0`
- `012c9517` `ADD ESP,0x2c` scalars: `0x2C`
- `012c951a` `MOVSD XMM0,qword ptr [EBP + 0xffff0d70]` scalars: `0xFFFF0D70`
