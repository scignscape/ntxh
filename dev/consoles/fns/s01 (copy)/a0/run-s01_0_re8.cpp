


#ifndef SEEN_DEFS_S01_0_RE8
#define SEEN_DEFS_S01_0_RE8

typedef n8(*minimal_fn_s0_re8_type)();
typedef n8(_min_::*minimal_fn_s0_re8_type)();
typedef void(*run_s01_0_re8_type)(n8& retv, minimal_fn_s0_re8_type fn,
  minimal_fn_s1_re8_type sfn);
typedef run_s01_0_re8_type s01_0_re8_dispatch_array [1];

#endif //  SEEN_DEFS_S01_0_RE8

#ifdef FULL_INCLUDE

#include "fn-array-s01_0_re8.cpp"

s01_0_re8_dispatch_array* init_s01_0_re8_dispatch_array()
{
 s01_0_re8_dispatch_array* result = (s01_0_re8_dispatch_array*) new run_s01_0_re8_type[1];
 
 (*result)[0] = &_f_8_;
}

void run_s01_0_re8(u4 code, minimal_fn_s01_re8_type fn, n8& retv)
{
 code %= 1;
 static s01_0_re8_dispatch_array* dispatch_array = init_s01_0_re8_dispatch_array();
 run_s01_0_re8_type f = (*dispatch_array)[code];
 f(retv, fn);
}

#endif //def FULL_INCLUDE
