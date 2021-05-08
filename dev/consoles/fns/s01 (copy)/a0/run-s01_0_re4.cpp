


#ifndef SEEN_DEFS_S01_0_RE4
#define SEEN_DEFS_S01_0_RE4

typedef u4(*minimal_fn_s0_re4_type)();
typedef u4(_min_::*minimal_fn_s0_re4_type)();
typedef void(*run_s01_0_re4_type)(u4& retv, minimal_fn_s0_re4_type fn,
  minimal_fn_s1_re4_type sfn);
typedef run_s01_0_re4_type s01_0_re4_dispatch_array [1];

#endif //  SEEN_DEFS_S01_0_RE4

#ifdef FULL_INCLUDE

#include "fn-array-s01_0_re4.cpp"

s01_0_re4_dispatch_array* init_s01_0_re4_dispatch_array()
{
 s01_0_re4_dispatch_array* result = (s01_0_re4_dispatch_array*) new run_s01_0_re4_type[1];
 
 (*result)[0] = &_f_4_;
}

void run_s01_0_re4(u4 code, minimal_fn_s01_re4_type fn, u4& retv)
{
 code %= 1;
 static s01_0_re4_dispatch_array* dispatch_array = init_s01_0_re4_dispatch_array();
 run_s01_0_re4_type f = (*dispatch_array)[code];
 f(retv, fn);
}

#endif //def FULL_INCLUDE
