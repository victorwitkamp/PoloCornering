/* Target address 013f49c0 */
/* Function FUN_013f49c0 @ 013f49c0 */


ulonglong FUN_013f49c0(uint param_1,uint param_2,uint param_3)

{
  if ((param_3 & 0x20) == 0) {
    if (param_3 != 0) {
      param_1 = param_2 << (0x20 - param_3 & 0xff) | param_1 >> (param_3 & 0xff);
      param_2 = param_2 >> (param_3 & 0xff);
    }
    return CONCAT44(param_2,param_1);
  }
  return (ulonglong)(param_2 >> (param_3 - 0x20 & 0xff));
}


