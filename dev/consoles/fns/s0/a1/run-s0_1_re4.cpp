


#ifndef SEEN_DEFS_S0_1_RE4
#define SEEN_DEFS_S0_1_RE4

typedef u4(*minimal_fn_s0_re4_type)();
typedef void(*run_s0_1_re4_type)(u4& retv, n8 arg1, minimal_fn_s0_re4_type fn);
typedef run_s0_1_re4_type s0_1_re4_dispatch_array [10];

#endif //  SEEN_DEFS_S0_1_RE4

#ifdef FULL_INCLUDE

#include "fn-array-s0_1_re4.cpp"

s0_1_re4_dispatch_array* init_s0_1_re4_dispatch_array()
{
 s0_1_re4_dispatch_array* result = (s0_1_re4_dispatch_array*) new run_s0_1_re4_type[10];
 
 (*result)[0] = &_f_40_;
 (*result)[1] = &_f_41_;
 (*result)[2] = &_f_42_;
 (*result)[3] = &_f_43_;
 (*result)[4] = &_f_44_;
 (*result)[5] = &_f_45_;
 (*result)[6] = &_f_46_;
 (*result)[7] = &_f_47_;
 (*result)[8] = &_f_48_;
 (*result)[9] = &_f_49_;
}

void run_s0_1_re4(u4 code, minimal_fn_s0_re4_type fn, u4& retv, n8 a1)
{
 code %= 100;
 static s0_1_re4_dispatch_array* dispatch_array = init_s0_1_re4_dispatch_array();
 run_s0_1_re4_type f = (*dispatch_array)[code];
 f(retv, a1,fn);
}

#endif //def FULL_INCLUDE
