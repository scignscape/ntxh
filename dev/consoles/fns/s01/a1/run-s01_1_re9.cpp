


#ifndef SEEN_DEFS_S01_1_RE9
#define SEEN_DEFS_S01_1_RE9

typedef void*(*minimal_fn_s0_re9_type)();
typedef void*(_min_::*minimal_fn_s1_re9_type)();
typedef void(*run_s01_1_re9_type)(void*& retv, n8 arg1, minimal_fn_s0_re9_type fn,
  minimal_fn_s1_re9_type sfn, void* _this);
typedef run_s01_1_re9_type s01_1_re9_dispatch_array [10];

#endif //  SEEN_DEFS_S01_1_RE9

#ifdef FULL_INCLUDE

#include "fn-array-s01_1_re9.cpp"

s01_1_re9_dispatch_array* init_s01_1_re9_dispatch_array()
{
 s01_1_re9_dispatch_array* result = (s01_1_re9_dispatch_array*) new run_s01_1_re9_type[10];
 
 (*result)[0] = &_f_90_;
 (*result)[1] = &_f_91_;
 (*result)[2] = &_f_92_;
 (*result)[3] = &_f_93_;
 (*result)[4] = &_f_94_;
 (*result)[5] = &_f_95_;
 (*result)[6] = &_f_96_;
 (*result)[7] = &_f_97_;
 (*result)[8] = &_f_98_;
 (*result)[9] = &_f_99_;
 return result;
}

void run_s01_1_re9(u4 code, minimal_fn_s0_re9_type fn,
   minimal_fn_s1_re9_type sfn, void*& retv, n8 a1, void* _this)
{
 code %= 10;
 static s01_1_re9_dispatch_array* dispatch_array = init_s01_1_re9_dispatch_array();
 run_s01_1_re9_type f = (*dispatch_array)[code];
 f(retv, a1,fn, sfn, _this);
}

#endif //def FULL_INCLUDE
