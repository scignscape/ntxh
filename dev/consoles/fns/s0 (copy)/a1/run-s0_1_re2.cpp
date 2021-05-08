


#ifndef SEEN_DEFS_S0_1_RE2
#define SEEN_DEFS_S0_1_RE2

typedef u2(*minimal_fn_s0_re2_type)();
typedef void(*run_s0_1_re2_type)(u2& retv, n8 arg1, minimal_fn_s0_re2_type fn);
typedef run_s0_1_re2_type s0_1_re2_dispatch_array [10];

#endif //  SEEN_DEFS_S0_1_RE2

#ifdef FULL_INCLUDE

#include "fn-array-s0_1_re2.cpp"

s0_1_re2_dispatch_array* init_s0_1_re2_dispatch_array()
{
 s0_1_re2_dispatch_array* result = (s0_1_re2_dispatch_array*) new run_s0_1_re2_type[10];
 
 (*result)[0] = &_f_20_;
 (*result)[1] = &_f_21_;
 (*result)[2] = &_f_22_;
 (*result)[3] = &_f_23_;
 (*result)[4] = &_f_24_;
 (*result)[5] = &_f_25_;
 (*result)[6] = &_f_26_;
 (*result)[7] = &_f_27_;
 (*result)[8] = &_f_28_;
 (*result)[9] = &_f_29_;
}

void run_s0_1_re2(u4 code, minimal_fn_s0_re2_type fn, u2& retv, n8 a1)
{
 code %= 10;
 static s0_1_re2_dispatch_array* dispatch_array = init_s0_1_re2_dispatch_array();
 run_s0_1_re2_type f = (*dispatch_array)[code];
 f(retv, a1,fn);
}

#endif //def FULL_INCLUDE
