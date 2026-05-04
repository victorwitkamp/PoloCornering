/* VagOperationDelegate::getReadCanOverUdsSubmoduleCodingId @ 0126fbaa */


/* VagOperationDelegate::getReadCanOverUdsSubmoduleCodingId(unsigned char) */

int __thiscall
VagOperationDelegate::getReadCanOverUdsSubmoduleCodingId(VagOperationDelegate *this,uchar param_1)

{
  int iVar1;
  
  iVar1 = 0x3610;
  if (-1 < (char)param_1) {
    iVar1 = 0x610;
  }
  return (param_1 & 0x7f) + iVar1;
}


