/* VagUdsSubmoduleCodingSetting::~VagUdsSubmoduleCodingSetting @ 011d7528 */


/* VagUdsSubmoduleCodingSetting::~VagUdsSubmoduleCodingSetting() */

void __thiscall
VagUdsSubmoduleCodingSetting::~VagUdsSubmoduleCodingSetting(VagUdsSubmoduleCodingSetting *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)WhitelistBasedSetting<StringWhitelist>::~WhitelistBasedSetting
                             ((WhitelistBasedSetting<StringWhitelist> *)this);
  operator_delete(pvVar1);
  return;
}


