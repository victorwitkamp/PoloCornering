/*
 * VagCanCommunicator_postInitialize
 * ELF symbol address: 0x00D1759C
 * Ghidra address: 0x00D2759C (ELF + 0x10000 image delta)
 * ELF symbol size: 192 bytes
 * Symbol: _ZN18VagCanCommunicator14postInitializeEv
 * Program: libCarista.so
 * Resolved function: VagCanCommunicator::postInitialize @ 00d2759c
 * Signature: undefined __thiscall postInitialize(VagCanCommunicator * this)
 * Return type: undefined
 * Function body: [[00d2759c, 00d2764f]]
 * Parameters:
 *   [0] VagCanCommunicator * this
 * Direct callers:
 *   <no function> -> EXTERNAL from Entry Point
 *   <no function> -> DATA from 0143dad0
 * Direct callees/references:
 *   READ 00d27650 from 00d275a2
 *   READ 014da9c0 from 00d275a6
 *   READ 014f1440 from 00d275a8
 *   UNCONDITIONAL_CALL DeviceLatestInfo::isDefective @ 013fb720 from 00d275aa
 *   CONDITIONAL_JUMP VagCanCommunicator::postInitialize @ 00d2759c from 00d275ae
 *   READ 00d27654 from 00d275b0
 *   PARAM 0072e361 from 00d275b2
 *   UNCONDITIONAL_CALL Log::d @ 013fb5b0 from 00d275b4
 *   READ 00d27658 from 00d275e4
 *   READ 014db3e0 from 00d275e8
 *   READ 00c8f314 from 00d275ea
 *   CONDITIONAL_JUMP VagCanCommunicator::postInitialize @ 00d2759c from 00d275ee
 *   CONDITIONAL_JUMP VagCanCommunicator::postInitialize @ 00d2759c from 00d2762e
 *   UNCONDITIONAL_JUMP VagCanCommunicator::postInitialize @ 00d2759c from 00d27634
 *   CONDITIONAL_JUMP VagCanCommunicator::postInitialize @ 00d2759c from 00d2763e
 *   DATA Stack[-0x8] from 00d2764a
 */

/* Ghidra function: VagCanCommunicator::postInitialize @ 00d2759c */

/* First instructions after recreation:
 * Memory bytes: d0b502af04462b48784400680068d4f2bae0f8b928487844d3f2fce760680168
 * 00d2759c: push {r4,r6,r7,lr}
 * 00d2759e: add r7,sp,#0x8
 * 00d275a0: mov r4,r0
 * 00d275a2: ldr r0,[0x00d27650]
 * 00d275a4: add r0,pc
 * 00d275a6: ldr r0,[r0,#0x0]
 * 00d275a8: ldr r0,[r0,#0x0]
 * 00d275aa: blx 0x013fb720
 * 00d275ae: cbnz r0,0x00d275f0
 * 00d275b0: ldr r0,[0x00d27654]
 * 00d275b2: add r0,pc
 * 00d275b4: blx 0x013fb5b0
 * 00d275b8: ldr r0,[r4,#0x4]
 * 00d275ba: ldr r1,[r0,#0x0]
 * 00d275bc: ldr r2,[r1,#0x30]
 * 00d275be: movs r1,#0x1
 * 00d275c0: blx r2
 * 00d275c2: ldr r0,[r4,#0x4]
 * 00d275c4: ldr r1,[r0,#0x0]
 * 00d275c6: ldr.w r2,[r1,#0x90]
 * 00d275ca: movs r1,#0x0
 * 00d275cc: blx r2
 * 00d275ce: ldr r0,[r4,#0x4]
 * 00d275d0: ldr r1,[r0,#0x0]
 */


/* VagCanCommunicator::postInitialize() */

void __thiscall VagCanCommunicator::postInitialize(VagCanCommunicator *this)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  iVar1 = DeviceLatestInfo::isDefective((DeviceLatestInfo *)App::DEVICE_LATEST_INFO);
  if (iVar1 == 0) {
    Log::d("Additionally initializing ELM chip for VAG CAN communication...");
    (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),1);
    (**(code **)(**(int **)(this + 4) + 0x90))(*(int **)(this + 4),0);
    (**(code **)(**(int **)(this + 4) + 0x98))(*(int **)(this + 4),0);
    iVar1 = (**(code **)(**(int **)(this + 4) + 0x118))();
    if (0x8b < iVar1) {
      (**(code **)(**(int **)(this + 4) + 0x38))(*(int **)(this + 4),6);
      (**(code **)(**(int **)(this + 4) + 0xf4))(*(int **)(this + 4),0);
      (**(code **)(**(int **)(this + 4) + 0xf0))(*(int **)(this + 4),1);
      (**(code **)(**(int **)(this + 4) + 0x8c))();
      iVar1 = (**(code **)(**(int **)(this + 4) + 0x124))();
      piVar2 = *(int **)(this + 4);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(*piVar2 + 0x128))();
        if (iVar1 == 0) {
          return;
        }
        piVar2 = *(int **)(this + 4);
        puVar3 = (undefined4 *)(*piVar2 + 0xc0);
      }
      else {
        puVar3 = (undefined4 *)(*piVar2 + 0xb0);
      }
                    /* WARNING: Could not recover jumptable at 0x00d2764e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*puVar3)(piVar2,0);
      return;
    }
  }
  return;
}


