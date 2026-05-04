/* VagOperationDelegate::readMileageInternal @ 0126f580 */


/* VagOperationDelegate::readMileageInternal() */

void __thiscall VagOperationDelegate::readMileageInternal(VagOperationDelegate *this)

{
  VagLiveData::getVehicleMileageLiveData();
  OperationDelegate::readMileageFromLiveData((vector *)this);
  return;
}


