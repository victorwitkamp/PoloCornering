/* VagUdsAdaptationSetting::~VagUdsAdaptationSetting @ 0118a398 */


/* VagUdsAdaptationSetting::~VagUdsAdaptationSetting() */

void __thiscall VagUdsAdaptationSetting::~VagUdsAdaptationSetting(VagUdsAdaptationSetting *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)WhitelistBasedSetting<StringWhitelist>::~WhitelistBasedSetting
                             ((WhitelistBasedSetting<StringWhitelist> *)this);
  operator_delete(pvVar1);
  return;
}


