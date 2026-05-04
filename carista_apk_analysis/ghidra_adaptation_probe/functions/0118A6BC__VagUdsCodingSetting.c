/* VagUdsCodingSetting::~VagUdsCodingSetting @ 0118a6bc */


/* VagUdsCodingSetting::~VagUdsCodingSetting() */

void __thiscall VagUdsCodingSetting::~VagUdsCodingSetting(VagUdsCodingSetting *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)WhitelistBasedSetting<StringWhitelist>::~WhitelistBasedSetting
                             ((WhitelistBasedSetting<StringWhitelist> *)this);
  operator_delete(pvVar1);
  return;
}


