/* FUN_01280796 @ 01280796 */


void FUN_01280796(int param_1,Result *param_2)

{
  std::__ndk1::mutex::lock();
  Result<VagRestoreData,void>::operator=(*(Result<VagRestoreData,void> **)(param_1 + 8),param_2);
  std::__ndk1::mutex::unlock();
  std::__ndk1::condition_variable::notify_all();
  return;
}


