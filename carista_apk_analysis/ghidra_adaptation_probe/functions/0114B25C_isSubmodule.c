/* VagSetting::isSubmodule @ 0114b25c */


/* VagSetting::isSubmodule() const */

uint __thiscall VagSetting::isSubmodule(VagSetting *this)

{
  return (uint)((byte)this[0xc] < 10) & 0x230U >> (uint)(byte)this[0xc];
}


