


#ifndef SEEN_DEFS_S0_0_RE6
#define SEEN_DEFS_S0_0_RE6

typedef r8(*minimal_fn_s0_re6_type)();
typedef void(*run_s0_0_re6_type)(r8& retv, minimal_fn_s0_re6_type fn);
typedef run_s0_0_re6_type s0_0_re6_dispatch_array [1];

#endif //  SEEN_DEFS_S0_0_RE6

#ifdef FULL_INCLUDE

#include "fn-array-s0_0_re6.cpp"

s0_0_re6_dispatch_array* init_s0_0_re6_dispatch_array()
{
 s0_0_re6_dispatch_array* result = (s0_0_re6_dispatch_array*) new run_s0_0_re6_type[1];
 
 (*result)[0] = &_f_6_;
}

void run_s0_0_re6(u4 code, minimal_fn_s0_re6_type fn, r8& retv)
{
 code %= 10;
 static s0_0_re6_dispatch_array* dispatch_array = init_s0_0_re6_dispatch_array();
 run_s0_0_re6_type f = (*dispatch_array)[code];
 f(retv, fn);
}

#endif //def FULL_INCLUDE
