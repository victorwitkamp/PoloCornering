/* FUN_012806b0 @ 012806b0 */


void FUN_012806b0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 0x10))();
                    /* WARNING: Could not recover jumptable at 0x012806ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 4) + 0x1c))(*(int **)(param_1 + 4),100);
  return;
}


