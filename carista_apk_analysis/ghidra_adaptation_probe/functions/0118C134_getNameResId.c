/* VagUdsEcu::getNameResId @ 0118c134 */


/* VagUdsEcu::getNameResId() const */

void VagUdsEcu::getNameResId(void)

{
  int *piVar1;
  Ecu *in_r1;
  
  piVar1 = (int *)VagEcu::getEquivalent(in_r1);
  (**(code **)(*piVar1 + 0x14))();
  return;
}


