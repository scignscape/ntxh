


#ifndef SEEN_DEFS_S0_1_RE0
#define SEEN_DEFS_S0_1_RE0

typedef void(*minimal_fn_s0_re0_type)();
typedef void(*run_s0_1_re0_type)(n8 arg1, minimal_fn_s0_re0_type fn);
typedef run_s0_1_re0_type s0_1_re0_dispatch_array [10];

#endif //  SEEN_DEFS_S0_1_RE0

#ifdef FULL_INCLUDE

#include "fn-array-s0_1_re0.cpp"

s0_1_re0_dispatch_array* init_s0_1_re0_dispatch_array()
{
 s0_1_re0_dispatch_array* result = (s0_1_re0_dispatch_array*) new run_s0_1_re0_type[10];
 
 (*result)[0] = &_f_00_;
 (*result)[1] = &_f_01_;
 (*result)[2] = &_f_02_;
 (*result)[3] = &_f_03_;
 (*result)[4] = &_f_04_;
 (*result)[5] = &_f_05_;
 (*result)[6] = &_f_06_;
 (*result)[7] = &_f_07_;
 (*result)[8] = &_f_08_;
 (*result)[9] = &_f_09_;
}

void run_s0_1_re0(u4 code, minimal_fn_s0_re0_type fn, n8 a1, n8 a2, n8 a3)
{
 code %= 100;
 static s0_1_re0_dispatch_array* dispatch_array = init_s0_1_re0_dispatch_array();
 run_s0_1_re0_type f = (*dispatch_array)[code];
 f(a1, a2, a3, fn);
}

#endif //def FULL_INCLUDE
