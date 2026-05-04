/* VagSetting::insertValue @ 0114b246 */


/* VagSetting::insertValue(std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char>
   > const&, std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> > const&)
   const */

void VagSetting::insertValue(vector *param_1,vector *param_2)

{
  vector *in_r2;
  vector *in_r3;
  
  ByteUtils::insertValue((ByteUtils *)param_1,in_r2,*(uint *)(param_2 + 0x18),param_2 + 0x1c,in_r3);
  return;
}


