


#ifndef SEEN_DEFS_S0_0_RE1
#define SEEN_DEFS_S0_0_RE1

typedef u1(*minimal_fn_s0_re1_type)();
typedef void(*run_s0_0_re1_type)(u1& retv, minimal_fn_s0_re1_type fn);
typedef run_s0_0_re1_type s0_0_re1_dispatch_array [1];

#endif //  SEEN_DEFS_S0_0_RE1

#ifdef FULL_INCLUDE

#include "fn-array-s0_0_re1.cpp"

s0_0_re1_dispatch_array* init_s0_0_re1_dispatch_array()
{
 s0_0_re1_dispatch_array* result = (s0_0_re1_dispatch_array*) new run_s0_0_re1_type[1];
 
 (*result)[0] = &_f_1_;
}

void run_s0_0_re1(u4 code, minimal_fn_s0_re1_type fn, u1& retv)
{
 code %= 1;
 static s0_0_re1_dispatch_array* dispatch_array = init_s0_0_re1_dispatch_array();
 run_s0_0_re1_type f = (*dispatch_array)[code];
 f(retv, fn);
}

#endif //def FULL_INCLUDE
