


#ifndef SEEN_DEFS_S0_0_RE4
#define SEEN_DEFS_S0_0_RE4

typedef u4(*minimal_fn_s0_re4_type)();
typedef void(*run_s0_0_re4_type)(u4& retv, minimal_fn_s0_re4_type fn);
typedef run_s0_0_re4_type s0_0_re4_dispatch_array [1];

#endif //  SEEN_DEFS_S0_0_RE4

#ifdef FULL_INCLUDE

#include "fn-array-s0_0_re4.cpp"

s0_0_re4_dispatch_array* init_s0_0_re4_dispatch_array()
{
 s0_0_re4_dispatch_array* result = (s0_0_re4_dispatch_array*) new run_s0_0_re4_type[1];
 
 (*result)[0] = &_f_4_;
}

void run_s0_0_re4(u4 code, minimal_fn_s0_re4_type fn, u4& retv)
{
 code %= 10;
 static s0_0_re4_dispatch_array* dispatch_array = init_s0_0_re4_dispatch_array();
 run_s0_0_re4_type f = (*dispatch_array)[code];
 f(retv, fn);
}

#endif //def FULL_INCLUDE
