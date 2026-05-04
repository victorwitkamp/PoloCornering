/* Setting::extractValue @ 00d5921c */


/* Setting::extractValue(std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> >
   const&) const */

void Setting::extractValue(vector *param_1)

{
  int in_r1;
  vector *in_r2;
  
  ByteUtils::extractValue
            ((ByteUtils *)param_1,in_r2,*(uint *)(in_r1 + 0x18),(vector *)(in_r1 + 0x1c));
  return;
}


