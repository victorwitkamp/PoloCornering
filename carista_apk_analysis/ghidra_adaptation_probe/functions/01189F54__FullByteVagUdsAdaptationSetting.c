/* FullByteVagUdsAdaptationSetting::~FullByteVagUdsAdaptationSetting @ 01189f54 */


/* FullByteVagUdsAdaptationSetting::~FullByteVagUdsAdaptationSetting() */

void __thiscall
FullByteVagUdsAdaptationSetting::~FullByteVagUdsAdaptationSetting
          (FullByteVagUdsAdaptationSetting *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)WhitelistBasedSetting<StringWhitelist>::~WhitelistBasedSetting
                             ((WhitelistBasedSetting<StringWhitelist> *)this);
  operator_delete(pvVar1);
  return;
}


