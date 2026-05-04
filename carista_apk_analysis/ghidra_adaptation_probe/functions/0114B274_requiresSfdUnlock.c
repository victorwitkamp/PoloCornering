/* VagSetting::requiresSfdUnlock @ 0114b274 */


/* VagSetting::requiresSfdUnlock() const */

bool __thiscall VagSetting::requiresSfdUnlock(VagSetting *this)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = (**(code **)(*(int *)this + 0x14))(this);
  if (iVar1 == 0) {
    bVar2 = false;
  }
  else {
    bVar2 = false;
    iVar1 = __dynamic_cast(iVar1,&Ecu::typeinfo,&VagUdsEcu::typeinfo,0);
    if (iVar1 != 0) {
      bVar2 = (byte)this[0xc] - 7 < 3;
    }
  }
  return bVar2;
}


