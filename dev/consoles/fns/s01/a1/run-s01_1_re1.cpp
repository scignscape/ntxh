


#ifndef SEEN_DEFS_S01_1_RE1
#define SEEN_DEFS_S01_1_RE1

typedef u1(*minimal_fn_s0_re1_type)();
typedef u1(_min_::*minimal_fn_s1_re1_type)();
typedef void(*run_s01_1_re1_type)(u1& retv, n8 arg1, minimal_fn_s0_re1_type fn,
  minimal_fn_s1_re1_type sfn, void* _this);
typedef run_s01_1_re1_type s01_1_re1_dispatch_array [10];

#endif //  SEEN_DEFS_S01_1_RE1

#ifdef FULL_INCLUDE

#include "fn-array-s01_1_re1.cpp"

s01_1_re1_dispatch_array* init_s01_1_re1_dispatch_array()
{
 s01_1_re1_dispatch_array* result = (s01_1_re1_dispatch_array*) new run_s01_1_re1_type[10];
 
 (*result)[0] = &_f_10_;
 (*result)[1] = &_f_11_;
 (*result)[2] = &_f_12_;
 (*result)[3] = &_f_13_;
 (*result)[4] = &_f_14_;
 (*result)[5] = &_f_15_;
 (*result)[6] = &_f_16_;
 (*result)[7] = &_f_17_;
 (*result)[8] = &_f_18_;
 (*result)[9] = &_f_19_;
 return result;
}

void run_s01_1_re1(u4 code, minimal_fn_s0_re1_type fn,
   minimal_fn_s1_re1_type sfn, u1& retv, n8 a1, void* _this)
{
 code %= 10;
 static s01_1_re1_dispatch_array* dispatch_array = init_s01_1_re1_dispatch_array();
 run_s01_1_re1_type f = (*dispatch_array)[code];
 f(retv, a1,fn, sfn, _this);
}

#endif //def FULL_INCLUDE
