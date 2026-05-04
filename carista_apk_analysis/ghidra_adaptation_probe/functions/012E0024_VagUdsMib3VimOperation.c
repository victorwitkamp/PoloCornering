/* VagUdsMib3VimOperation::VagUdsMib3VimOperation @ 012e0024 */


/* VagUdsMib3VimOperation::VagUdsMib3VimOperation(std::__ndk1::shared_ptr<ConnectionManager> const&,
   std::__ndk1::shared_ptr<VagBasicSettingTool> const&, std::__ndk1::shared_ptr<ReadValuesOperation>
   const&, std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> > const&,
   std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> > const&,
   std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char> > const&) */

VagUdsMib3VimOperation * __thiscall
VagUdsMib3VimOperation::VagUdsMib3VimOperation
          (VagUdsMib3VimOperation *this,shared_ptr *param_1,shared_ptr *param_2,shared_ptr *param_3,
          vector *param_4,vector *param_5,vector *param_6)

{
  VagUdsVimOperation::VagUdsVimOperation
            ((VagUdsVimOperation *)this,param_1,param_2,param_3,
             (LibStr *)&LibStr::enable_vim_disclaimer_msg);
  *(undefined ***)this = &PTR__VagUdsMib3VimOperation_014bfae8;
  FUN_00cd5ef0(this + 300,param_4);
  FUN_00cd5ef0(this + 0x138,param_5);
  FUN_00cd5ef0(this + 0x144,param_6);
  return this;
}


