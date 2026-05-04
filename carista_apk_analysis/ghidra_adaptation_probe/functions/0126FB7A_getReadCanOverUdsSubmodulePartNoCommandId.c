/* VagOperationDelegate::getReadCanOverUdsSubmodulePartNoCommandId @ 0126fb7a */


/* VagOperationDelegate::getReadCanOverUdsSubmodulePartNoCommandId(unsigned char) */

int __thiscall
VagOperationDelegate::getReadCanOverUdsSubmodulePartNoCommandId
          (VagOperationDelegate *this,uchar param_1)

{
  int iVar1;
  
  iVar1 = 0x3640;
  if (-1 < (char)param_1) {
    iVar1 = 0x640;
  }
  return (param_1 & 0x7f) + iVar1;
}


