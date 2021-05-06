


#ifndef SEEN_DEFS_S0_1_RE1
#define SEEN_DEFS_S0_1_RE1

typedef u1(*minimal_fn_s0_re1_type)();
typedef void(*run_s0_1_re1_type)(u1& retv, n8 arg1, minimal_fn_s0_re1_type fn);
typedef run_s0_1_re1_type s0_1_re1_dispatch_array [10];

#endif //  SEEN_DEFS_S0_1_RE1

#ifdef FULL_INCLUDE

#include "fn-array-s0_1_re1.cpp"

s0_1_re1_dispatch_array* init_s0_1_re1_dispatch_array()
{
 s0_1_re1_dispatch_array* result = (s0_1_re1_dispatch_array*) new run_s0_1_re1_type[10];
 
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
}

void run_s0_1_re1(u4 code, minimal_fn_s0_re1_type fn, u1& retv, n8 a1)
{
 code %= 100;
 static s0_1_re1_dispatch_array* dispatch_array = init_s0_1_re1_dispatch_array();
 run_s0_1_re1_type f = (*dispatch_array)[code];
 f(retv, a1,fn);
}

#endif //def FULL_INCLUDE
