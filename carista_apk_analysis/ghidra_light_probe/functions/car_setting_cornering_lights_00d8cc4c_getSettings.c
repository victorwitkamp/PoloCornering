/*
 * Setting key: car_setting_cornering_lights
 * Function: getSettings @ 00d8cc4c
 */

/* decompilation failed */
/*
 * 00d8cc4c: push {r4,r5,r6,r7,lr}
 * 00d8cc4e: add r7,sp,#0xc
 * 00d8cc50: push {r7,r8,r9,r10,r11}
 * 00d8cc54: vpush {d8}
 * 00d8cc58: sub.w sp,sp,#0xb200
 * 00d8cc5c: sub sp,#0x60
 * 00d8cc5e: ldr r0,[0x00d8cca4]
 * 00d8cc60: add r0,pc
 * 00d8cc62: ldr r0,[r0,#0x0]
 * 00d8cc64: ldr r0,[r0,#0x0]
 * 00d8cc66: str.w r0,[r7,#-0x34]
 * 00d8cc6a: ldr r4,[0x00d8cca8]
 * 00d8cc6c: add r4,pc
 * 00d8cc6e: ldrb r0,[r4,#0x0]
 * 00d8cc70: dmb #0x1b
 * 00d8cc74: lsls r0,r0,#0x1f
 * 00d8cc76: beq 0x00d8ccb0
 * 00d8cc78: ldr.w r0,[r7,#-0x34]
 * 00d8cc7c: ldr r1,[0x00d8ccac]
 * 00d8cc7e: add r1,pc
 * 00d8cc80: ldr r1,[r1,#0x0]
 * 00d8cc82: ldr r1,[r1,#0x0]
 * 00d8cc84: cmp r1,r0
 * 00d8cc86: itttt eq
 * 00d8cc88: add.eq.w r0,r4,#0x14
 * 00d8cc8c: add.eq.w sp,sp,#0xb200
 * 00d8cc90: add.eq sp,#0x60
 * 00d8cc92: vpop.eq {d8}
 * 00d8cc96: ittt eq
 * 00d8cc98: add.eq sp,#0x4
 * 00d8cc9a: pop.eq.w {r8,r9,r10,r11}
 * 00d8cc9e: pop.eq {r4,r5,r6,r7,pc}
 * 00d8cca0: blx 0x013fa400
 */
