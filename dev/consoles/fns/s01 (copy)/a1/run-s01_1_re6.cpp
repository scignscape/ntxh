


#ifndef SEEN_DEFS_S01_1_RE6
#define SEEN_DEFS_S01_1_RE6

typedef r8(*minimal_fn_s0_re6_type)();
typedef r8(_min_::*minimal_fn_s0_re6_type)();
typedef void(*run_s01_1_re6_type)(r8& retv, n8 arg1, minimal_fn_s0_re6_type fn,
  minimal_fn_s1_re6_type sfn);
typedef run_s01_1_re6_type s01_1_re6_dispatch_array [10];

#endif //  SEEN_DEFS_S01_1_RE6

#ifdef FULL_INCLUDE

#include "fn-array-s01_1_re6.cpp"

s01_1_re6_dispatch_array* init_s01_1_re6_dispatch_array()
{
 s01_1_re6_dispatch_array* result = (s01_1_re6_dispatch_array*) new run_s01_1_re6_type[10];
 
 (*result)[0] = &_f_60_;
 (*result)[1] = &_f_61_;
 (*result)[2] = &_f_62_;
 (*result)[3] = &_f_63_;
 (*result)[4] = &_f_64_;
 (*result)[5] = &_f_65_;
 (*result)[6] = &_f_66_;
 (*result)[7] = &_f_67_;
 (*result)[8] = &_f_68_;
 (*result)[9] = &_f_69_;
}

void run_s01_1_re6(u4 code, minimal_fn_s01_re6_type fn, r8& retv, n8 a1)
{
 code %= 10;
 static s01_1_re6_dispatch_array* dispatch_array = init_s01_1_re6_dispatch_array();
 run_s01_1_re6_type f = (*dispatch_array)[code];
 f(retv, a1,fn);
}

#endif //def FULL_INCLUDE
