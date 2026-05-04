/* VagOperationDelegate::getSettingsContentControl @ 0126f95c */


/* VagOperationDelegate::getSettingsContentControl(int, bool) */

void __thiscall
VagOperationDelegate::getSettingsContentControl(VagOperationDelegate *this,int param_1,bool param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)param_1 + 0x184))(param_1,VagUdsEcu::CENTRAL_ELEC);
  if ((param_2 < 0x1e) && (iVar1 != 0)) {
    ContentControl::UPCOMING_MODEL_FEW_SETTINGS_SCREEN((ContentControl *)this);
    return;
  }
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  return;
}


