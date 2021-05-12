
#ifndef SEEN_DEFS_S01_4of1_RE9
#define SEEN_DEFS_S01_4of1_RE9

typedef void*(*minimal_fn_s0_re9_type)();
typedef void*(_min_::*minimal_fn_s1_re9_type)();
typedef void(*run_s01_4of1_re9_type)(u4 pattern, void*& retv, n8 arg1, n8 arg2, n8 arg3, n8 arg4, minimal_fn_s0_re9_type fn,
  minimal_fn_s1_re9_type sfn, void* _this);
typedef run_s01_4of1_re9_type s01_4of1_re9_dispatch_array [120];

#endif //  SEEN_DEFS_S01_4of1_RE9

#ifdef FULL_INCLUDE

 
#include "./dev/consoles/fns/a4of1-r9/fn4012.cpp" // #0

s01_4of3_re9_dispatch_array* init_s01_4of1_re9_dispatch_array()
{
 s01_4of3_re9_dispatch_array* result = (s01_4of1_re9_dispatch_array*) new run_s01_4of3_re9_type[120];
 
 (*result)[0] = &_f_4012_9_;
 (*result)[1] = &_f_4013_9_;
 (*result)[2] = &_f_4014_9_;
 (*result)[3] = &_f_4015_9_;
 (*result)[4] = &_f_4016_9_;
 (*result)[5] = &_f_4017_9_;
 (*result)[6] = &_f_4018_9_;
 (*result)[7] = &_f_4019_9_;
 (*result)[8] = &_f_4023_9_;
 (*result)[9] = &_f_4024_9_;
 (*result)[10] = &_f_4025_9_;
 (*result)[11] = &_f_4026_9_;
 (*result)[12] = &_f_4027_9_;
 (*result)[13] = &_f_4028_9_;
 (*result)[14] = &_f_4029_9_;
 (*result)[15] = &_f_4034_9_;
 (*result)[16] = &_f_4035_9_;
 (*result)[17] = &_f_4036_9_;
 (*result)[18] = &_f_4037_9_;
 (*result)[19] = &_f_4038_9_;
 (*result)[20] = &_f_4039_9_;
 (*result)[21] = &_f_4045_9_;
 (*result)[22] = &_f_4046_9_;
 (*result)[23] = &_f_4047_9_;
 (*result)[24] = &_f_4048_9_;
 (*result)[25] = &_f_4049_9_;
 (*result)[26] = &_f_4056_9_;
 (*result)[27] = &_f_4057_9_;
 (*result)[28] = &_f_4058_9_;
 (*result)[29] = &_f_4059_9_;
 (*result)[30] = &_f_4067_9_;
 (*result)[31] = &_f_4068_9_;
 (*result)[32] = &_f_4069_9_;
 (*result)[33] = &_f_4078_9_;
 (*result)[34] = &_f_4079_9_;
 (*result)[35] = &_f_4089_9_;
 (*result)[36] = &_f_4123_9_;
 (*result)[37] = &_f_4124_9_;
 (*result)[38] = &_f_4125_9_;
 (*result)[39] = &_f_4126_9_;
 (*result)[40] = &_f_4127_9_;
 (*result)[41] = &_f_4128_9_;
 (*result)[42] = &_f_4129_9_;
 (*result)[43] = &_f_4134_9_;
 (*result)[44] = &_f_4135_9_;
 (*result)[45] = &_f_4136_9_;
 (*result)[46] = &_f_4137_9_;
 (*result)[47] = &_f_4138_9_;
 (*result)[48] = &_f_4139_9_;
 (*result)[49] = &_f_4145_9_;
 (*result)[50] = &_f_4146_9_;
 (*result)[51] = &_f_4147_9_;
 (*result)[52] = &_f_4148_9_;
 (*result)[53] = &_f_4149_9_;
 (*result)[54] = &_f_4156_9_;
 (*result)[55] = &_f_4157_9_;
 (*result)[56] = &_f_4158_9_;
 (*result)[57] = &_f_4159_9_;
 (*result)[58] = &_f_4167_9_;
 (*result)[59] = &_f_4168_9_;
 (*result)[60] = &_f_4169_9_;
 (*result)[61] = &_f_4178_9_;
 (*result)[62] = &_f_4179_9_;
 (*result)[63] = &_f_4189_9_;
 (*result)[64] = &_f_4234_9_;
 (*result)[65] = &_f_4235_9_;
 (*result)[66] = &_f_4236_9_;
 (*result)[67] = &_f_4237_9_;
 (*result)[68] = &_f_4238_9_;
 (*result)[69] = &_f_4239_9_;
 (*result)[70] = &_f_4245_9_;
 (*result)[71] = &_f_4246_9_;
 (*result)[72] = &_f_4247_9_;
 (*result)[73] = &_f_4248_9_;
 (*result)[74] = &_f_4249_9_;
 (*result)[75] = &_f_4256_9_;
 (*result)[76] = &_f_4257_9_;
 (*result)[77] = &_f_4258_9_;
 (*result)[78] = &_f_4259_9_;
 (*result)[79] = &_f_4267_9_;
 (*result)[80] = &_f_4268_9_;
 (*result)[81] = &_f_4269_9_;
 (*result)[82] = &_f_4278_9_;
 (*result)[83] = &_f_4279_9_;
 (*result)[84] = &_f_4289_9_;
 (*result)[85] = &_f_4345_9_;
 (*result)[86] = &_f_4346_9_;
 (*result)[87] = &_f_4347_9_;
 (*result)[88] = &_f_4348_9_;
 (*result)[89] = &_f_4349_9_;
 (*result)[90] = &_f_4356_9_;
 (*result)[91] = &_f_4357_9_;
 (*result)[92] = &_f_4358_9_;
 (*result)[93] = &_f_4359_9_;
 (*result)[94] = &_f_4367_9_;
 (*result)[95] = &_f_4368_9_;
 (*result)[96] = &_f_4369_9_;
 (*result)[97] = &_f_4378_9_;
 (*result)[98] = &_f_4379_9_;
 (*result)[99] = &_f_4389_9_;
 (*result)[100] = &_f_4456_9_;
 (*result)[101] = &_f_4457_9_;
 (*result)[102] = &_f_4458_9_;
 (*result)[103] = &_f_4459_9_;
 (*result)[104] = &_f_4467_9_;
 (*result)[105] = &_f_4468_9_;
 (*result)[106] = &_f_4469_9_;
 (*result)[107] = &_f_4478_9_;
 (*result)[108] = &_f_4479_9_;
 (*result)[109] = &_f_4489_9_;
 (*result)[110] = &_f_4567_9_;
 (*result)[111] = &_f_4568_9_;
 (*result)[112] = &_f_4569_9_;
 (*result)[113] = &_f_4578_9_;
 (*result)[114] = &_f_4579_9_;
 (*result)[115] = &_f_4589_9_;
 (*result)[116] = &_f_4678_9_;
 (*result)[117] = &_f_4679_9_;
 (*result)[118] = &_f_4689_9_;
 (*result)[119] = &_f_4789_9_;

 return result;
}


void run_s01_4of3_re9(u4 pattern, u4 index, minimal_fn_s0_re9_type fn,
  minimal_fn_s1_re9_type sfn, n8 arg1, n8 arg2, n8 arg3, n8 arg4, void*& retv,  void* _this)
{
 static s01_4of3_re9_dispatch_array* dispatch_array = init_s01_4of3_re9_dispatch_array();
 run_s01_4of3_re9_type f = (*dispatch_array)[index];
 f(pattern, retv, arg1, arg2, arg3, arg4, fn, sfn, _this);
}

#endif //def FULL_INCLUDE
   
