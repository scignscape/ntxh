


#ifndef SEEN_DEFS_S01_1_RE8
#define SEEN_DEFS_S01_1_RE8

typedef n8(*minimal_fn_s0_re8_type)();
typedef n8(_min_::*minimal_fn_s0_re8_type)();
typedef void(*run_s01_1_re8_type)(n8& retv, n8 arg1, minimal_fn_s0_re8_type fn,
  minimal_fn_s1_re8_type sfn);
typedef run_s01_1_re8_type s01_1_re8_dispatch_array [10];

#endif //  SEEN_DEFS_S01_1_RE8

#ifdef FULL_INCLUDE

#include "fn-array-s01_1_re8.cpp"

s01_1_re8_dispatch_array* init_s01_1_re8_dispatch_array()
{
 s01_1_re8_dispatch_array* result = (s01_1_re8_dispatch_array*) new run_s01_1_re8_type[10];
 
 (*result)[0] = &_f_80_;
 (*result)[1] = &_f_81_;
 (*result)[2] = &_f_82_;
 (*result)[3] = &_f_83_;
 (*result)[4] = &_f_84_;
 (*result)[5] = &_f_85_;
 (*result)[6] = &_f_86_;
 (*result)[7] = &_f_87_;
 (*result)[8] = &_f_88_;
 (*result)[9] = &_f_89_;
}

void run_s01_1_re8(u4 code, minimal_fn_s01_re8_type fn, n8& retv, n8 a1)
{
 code %= 10;
 static s01_1_re8_dispatch_array* dispatch_array = init_s01_1_re8_dispatch_array();
 run_s01_1_re8_type f = (*dispatch_array)[code];
 f(retv, a1,fn);
}

#endif //def FULL_INCLUDE
