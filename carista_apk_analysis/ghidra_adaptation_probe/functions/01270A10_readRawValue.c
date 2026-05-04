/* VagOperationDelegate::readRawValue @ 01270a10 */


/* VagOperationDelegate::readRawValue(unsigned long long, bool) */

void VagOperationDelegate::readRawValue(ulonglong param_1,bool param_2)

{
  ushort uVar1;
  shared_ptr *this;
  undefined4 uVar2;
  int iVar3;
  IllegalArgumentException *this_00;
  shared_ptr *psVar4;
  code *pcVar5;
  uchar uStack_65;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  vector *local_50 [2];
  undefined4 local_48;
  undefined4 local_44;
  int local_24;
  
  psVar4 = (shared_ptr *)(param_1 >> 0x20);
  this = (shared_ptr *)param_1;
  local_24 = __stack_chk_guard;
  uVar2 = (**(code **)(*(int *)psVar4 + 0x15c))(psVar4);
  switch(uVar2) {
  case 0:
  case 1:
    pcVar5 = *(code **)(*(int *)psVar4 + 0x1a4);
    break;
  case 2:
  case 4:
    uVar2 = (**(code **)(*(int *)psVar4 + 0x154))(psVar4,*(code **)(*(int *)psVar4 + 0x154),param_2)
    ;
    (**(code **)(*(int *)psVar4 + 0x198))((Result<VagEcuInfo,void> *)&local_48,psVar4,uVar2);
    iVar3 = Result<VagEcuInfo,void>::isFail((Result<VagEcuInfo,void> *)&local_48);
    if (iVar3 == 0) {
      (**(code **)(*(int *)psVar4 + 0xa4))(local_50,psVar4,param_2);
      if (local_50[0] == (vector *)0x0) {
        Result<BytesModel,void>::Result((Result<BytesModel,void> *)this,-0xb);
      }
      else {
        BytesModel::BytesModel((BytesModel *)&local_60,local_50[0]);
        Result<BytesModel,void>::done<BytesModel>((type *)this);
        BytesModel::~BytesModel((BytesModel *)&local_60);
      }
      FUN_00cbcfda(local_50);
    }
    else {
      Result<VagEcuInfo,void>::stateAs<BytesModel,void>();
    }
    Result<VagEcuInfo,void>::~Result((Result<VagEcuInfo,void> *)&local_48);
    goto LAB_01270bde;
  case 3:
    local_64 = (**(code **)(*(int *)psVar4 + 0x154))
                         (psVar4,*(code **)(*(int *)psVar4 + 0x154),param_2);
    FUN_01270cb0(&local_60,&local_64);
    local_48 = local_60;
    local_44 = uStack_5c;
    local_60 = 0;
    uStack_5c = 0;
    Progress::NUL((Progress *)local_50);
    OperationDelegate::runCommand<BytesModel>(this,psVar4);
    FUN_011e01a0(local_50);
    FUN_011e4f74(&local_48);
    FUN_01270ce4(&local_60);
    goto LAB_01270bde;
  case 5:
    uVar2 = (**(code **)(*(int *)psVar4 + 0x180))(psVar4,*(code **)(*(int *)psVar4 + 0x180),param_2)
    ;
    pcVar5 = *(code **)(*(int *)psVar4 + 0x1e4);
    goto LAB_01270b0c;
  case 6:
    local_64 = (**(code **)(*(int *)psVar4 + 0x154))
                         (psVar4,*(code **)(*(int *)psVar4 + 0x154),param_2);
    uVar1 = (**(code **)(*(int *)psVar4 + 0x158))(psVar4,*(code **)(*(int *)psVar4 + 0x158),param_2)
    ;
    uStack_65 = Math::toExact<unsigned_char,unsigned_short>(uVar1);
    FUN_0124e338(&local_60,&local_64,&uStack_65);
    local_48 = local_60;
    local_44 = uStack_5c;
    local_60 = 0;
    uStack_5c = 0;
    Progress::NUL((Progress *)local_50);
    OperationDelegate::runCommand<BytesModel>(this,psVar4);
    FUN_011e01a0(local_50);
    FUN_011e4f74(&local_48);
    FUN_011e4fcc(&local_60);
    goto LAB_01270bde;
  case 7:
    pcVar5 = *(code **)(*(int *)psVar4 + 0x1ac);
    break;
  case 8:
    pcVar5 = *(code **)(*(int *)psVar4 + 0x1b0);
    break;
  case 9:
    uVar2 = (**(code **)(*(int *)psVar4 + 0x180))(psVar4,*(code **)(*(int *)psVar4 + 0x180),param_2)
    ;
    pcVar5 = *(code **)(*(int *)psVar4 + 0x1d4);
LAB_01270b0c:
    (*pcVar5)(psVar4,uVar2);
    pcVar5 = *(code **)(*(int *)psVar4 + 0x1b4);
    break;
  case 10:
    Result<BytesModel,void>::Result((Result<BytesModel,void> *)this,-10);
    goto LAB_01270bde;
  default:
    this_00 = (IllegalArgumentException *)__cxa_allocate_exception(8);
    FUN_00cb4d44(&local_48,"Invalid VAG setting type");
    IllegalArgumentException::IllegalArgumentException(this_00,(basic_string *)&local_48);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(this_00,&IllegalArgumentException::typeinfo,
                IllegalStateException::~IllegalStateException);
  }
  (*pcVar5)(this,psVar4,param_2);
LAB_01270bde:
  if (__stack_chk_guard == local_24) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


