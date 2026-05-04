/* Setting::isRawValueLengthSupported @ 00d58f24 */


/* Setting::isRawValueLengthSupported(unsigned int) const */

void __thiscall Setting::isRawValueLengthSupported(Setting *this,uint param_1)

{
  ByteUtils::isRawValueLengthSupported
            (*(uint *)(this + 0x18),*(int *)(this + 0x20) - *(int *)(this + 0x1c),param_1);
  return;
}


