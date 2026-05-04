/* VagUdsEcu::getId @ 0118c14c */


/* VagUdsEcu::getId() const */

void __thiscall VagUdsEcu::getId(VagUdsEcu *this)

{
  Math::toExact<unsigned_short,unsigned_int>(*(uint *)(this + 0x18) & 0x7fff);
  return;
}


