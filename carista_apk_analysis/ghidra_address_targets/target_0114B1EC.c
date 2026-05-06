/* Target address 0114b1ec */
/* Function VagSetting @ 0114b1ec */


/* VagSetting::VagSetting(std::__ndk1::shared_ptr<StringWhitelist> const&, VagSetting::Type, Ecu*,
   unsigned short, int, std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> >
   const&, char const*, std::__ndk1::shared_ptr<Interpretation> const&,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned long long, std::__ndk1::allocator<unsigned
   long long> > const> const&, Setting::Consistency, VagSetting::AvailBy) */

void __thiscall VagSetting::VagSetting(void)

{
  undefined4 *puVar1;
  undefined1 in_stack_0000001c;
  
  puVar1 = (undefined4 *)WhitelistBasedSetting<StringWhitelist>::WhitelistBasedSetting();
  *(undefined1 *)(puVar1 + 0x17) = in_stack_0000001c;
  *puVar1 = &PTR__WhitelistBasedSetting_014b54c0;
  return;
}


