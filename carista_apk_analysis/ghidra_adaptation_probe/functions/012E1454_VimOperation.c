/* VimOperation::VimOperation @ 012e1454 */


/* VimOperation::VimOperation(std::__ndk1::shared_ptr<ConnectionManager> const&,
   std::__ndk1::shared_ptr<Setting> const&, std::__ndk1::shared_ptr<ReadValuesOperation> const&,
   LibStr const&) */

VimOperation * __thiscall
VimOperation::VimOperation
          (VimOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3,
          LibStr *param_4)

{
  GenericToolOperation::GenericToolOperation((GenericToolOperation *)this,param_1,param_2,param_3);
  *(undefined ***)this = &PTR__VimOperation_014bffe0;
  FUN_00d46d48(this + 0x10c,param_4);
  *(undefined4 *)(this + 0x124) = 0;
  *(undefined4 *)(this + 0x128) = 0;
  this[0x120] = (VimOperation)0x0;
  return this;
}


