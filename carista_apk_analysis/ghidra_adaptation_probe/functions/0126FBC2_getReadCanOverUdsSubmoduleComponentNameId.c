/* VagOperationDelegate::getReadCanOverUdsSubmoduleComponentNameId @ 0126fbc2 */


/* VagOperationDelegate::getReadCanOverUdsSubmoduleComponentNameId(unsigned char) */

int __thiscall
VagOperationDelegate::getReadCanOverUdsSubmoduleComponentNameId
          (VagOperationDelegate *this,uchar param_1)

{
  int iVar1;
  
  iVar1 = 0x3730;
  if (-1 < (char)param_1) {
    iVar1 = 0x730;
  }
  return (param_1 & 0x7f) + iVar1;
}


