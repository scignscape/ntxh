


#ifndef SEEN_DEFS_S01_0_RE6
#define SEEN_DEFS_S01_0_RE6

typedef r8(*minimal_fn_s0_re6_type)();
typedef r8(_min_::*minimal_fn_s0_re6_type)();
typedef void(*run_s01_0_re6_type)(r8& retv, minimal_fn_s0_re6_type fn,
  minimal_fn_s1_re6_type sfn);
typedef run_s01_0_re6_type s01_0_re6_dispatch_array [1];

#endif //  SEEN_DEFS_S01_0_RE6

#ifdef FULL_INCLUDE

#include "fn-array-s01_0_re6.cpp"

s01_0_re6_dispatch_array* init_s01_0_re6_dispatch_array()
{
 s01_0_re6_dispatch_array* result = (s01_0_re6_dispatch_array*) new run_s01_0_re6_type[1];
 
 (*result)[0] = &_f_6_;
}

void run_s01_0_re6(u4 code, minimal_fn_s01_re6_type fn, r8& retv)
{
 code %= 1;
 static s01_0_re6_dispatch_array* dispatch_array = init_s01_0_re6_dispatch_array();
 run_s01_0_re6_type f = (*dispatch_array)[code];
 f(retv, fn);
}

#endif //def FULL_INCLUDE
