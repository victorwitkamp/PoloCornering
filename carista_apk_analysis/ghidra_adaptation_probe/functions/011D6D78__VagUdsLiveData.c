/* VagUdsLiveData::~VagUdsLiveData @ 011d6d78 */


/* VagUdsLiveData::~VagUdsLiveData() */

void __thiscall VagUdsLiveData::~VagUdsLiveData(VagUdsLiveData *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)WhitelistBasedSetting<StringWhitelist>::~WhitelistBasedSetting
                             ((WhitelistBasedSetting<StringWhitelist> *)this);
  operator_delete(pvVar1);
  return;
}


