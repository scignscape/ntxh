


#ifndef SEEN_DEFS_S0_0_RE0
#define SEEN_DEFS_S0_0_RE0

typedef void(*minimal_fn_s0_re0_type)();
typedef void(*run_s0_0_re0_type)(minimal_fn_s0_re0_type fn);
typedef run_s0_0_re0_type s0_0_re0_dispatch_array [1];

#endif //  SEEN_DEFS_S0_0_RE0

#ifdef FULL_INCLUDE

#include "fn-array-s0_0_re0.cpp"

s0_0_re0_dispatch_array* init_s0_0_re0_dispatch_array()
{
 s0_0_re0_dispatch_array* result = (s0_0_re0_dispatch_array*) new run_s0_0_re0_type[1];
 
 (*result)[0] = &_f_0_;
}

void run_s0_0_re0(u4 code, minimal_fn_s0_re0_type fn)
{
 code %= 1;
 static s0_0_re0_dispatch_array* dispatch_array = init_s0_0_re0_dispatch_array();
 run_s0_0_re0_type f = (*dispatch_array)[code];
 f(fn);
}

#endif //def FULL_INCLUDE
