/* Target address 00e2d9f4 */
/* Function WhitelistBasedSetting @ 00e2d9f4 */


/* WhitelistBasedSetting<StringWhitelist>::WhitelistBasedSetting(std::__ndk1::shared_ptr<StringWhitelist>
   const&, unsigned char, Ecu*, unsigned short, int, std::__ndk1::vector<unsigned char,
   std::__ndk1::allocator<unsigned char> > const&, char const*,
   std::__ndk1::shared_ptr<Interpretation> const&,
   std::__ndk1::shared_ptr<std::__ndk1::vector<unsigned long long, std::__ndk1::allocator<unsigned
   long long> > const> const&, Setting::Consistency, unsigned long long) */

void WhitelistBasedSetting<StringWhitelist>::WhitelistBasedSetting
               (Setting *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
               undefined4 param_13,undefined4 param_14)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  
  puVar2 = (undefined4 *)
           Setting::Setting(param_1,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10
                            ,param_11,param_13,param_14);
  *puVar2 = &PTR__WhitelistBasedSetting_014635d8;
  iVar3 = param_2[1];
  puVar2[0x15] = *param_2;
  puVar2[0x16] = iVar3;
  if (iVar3 != 0) {
    piVar4 = (int *)(iVar3 + 4);
    do {
      ExclusiveAccess(piVar4);
      bVar1 = (bool)hasExclusiveAccess(piVar4);
    } while (!bVar1);
    *piVar4 = *piVar4 + 1;
  }
  return;
}


