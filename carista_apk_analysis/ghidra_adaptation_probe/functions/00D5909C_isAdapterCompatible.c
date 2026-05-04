/* Setting::isAdapterCompatible @ 00d5909c */


/* Setting::isAdapterCompatible(Elm::AdapterType) */

bool Setting::isAdapterCompatible(int param_1,undefined4 param_2,uint param_3,uint param_4)

{
  return (*(uint *)(param_1 + 0x40) & param_3) != 0 || (*(uint *)(param_1 + 0x44) & param_4) != 0;
}


