/* VagCanShortAdaptationSetting::generateBitmask @ 011003a0 */


/* VagCanShortAdaptationSetting::generateBitmask(int, int) */

undefined1 VagCanShortAdaptationSetting::generateBitmask(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_013f49c0(0xffffffff,0xffffffff,0x40 - param_2);
  uVar2 = FUN_013f47cc((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),param_1);
  uVar1 = FUN_013f49c0((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(param_1 / 8) * 8);
  return uVar1;
}


