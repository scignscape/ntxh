


#ifndef SEEN_DEFS_S0_0_RE2
#define SEEN_DEFS_S0_0_RE2

typedef u2(*minimal_fn_s0_re2_type)();
typedef void(*run_s0_0_re2_type)(u2& retv, minimal_fn_s0_re2_type fn);
typedef run_s0_0_re2_type s0_0_re2_dispatch_array [1];

#endif //  SEEN_DEFS_S0_0_RE2

#ifdef FULL_INCLUDE

#include "fn-array-s0_0_re2.cpp"

s0_0_re2_dispatch_array* init_s0_0_re2_dispatch_array()
{
 s0_0_re2_dispatch_array* result = (s0_0_re2_dispatch_array*) new run_s0_0_re2_type[1];
 
 (*result)[0] = &_f_2_;
}

void run_s0_0_re2(u4 code, minimal_fn_s0_re2_type fn, u2& retv)
{
 code %= 1;
 static s0_0_re2_dispatch_array* dispatch_array = init_s0_0_re2_dispatch_array();
 run_s0_0_re2_type f = (*dispatch_array)[code];
 f(retv, fn);
}

#endif //def FULL_INCLUDE
