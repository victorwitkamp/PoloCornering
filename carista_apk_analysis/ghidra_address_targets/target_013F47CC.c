/* Target address 013f47cc */
/* Function FUN_013f47cc @ 013f47cc */


longlong FUN_013f47cc(uint param_1,uint param_2,uint param_3)

{
  if ((param_3 & 0x20) == 0) {
    if (param_3 != 0) {
      param_2 = param_2 << (param_3 & 0xff) | param_1 >> (0x20 - param_3 & 0xff);
      param_1 = param_1 << (param_3 & 0xff);
    }
    return CONCAT44(param_2,param_1);
  }
  return (ulonglong)(param_1 << (param_3 - 0x20 & 0xff)) << 0x20;
}


