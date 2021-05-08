


#ifndef SEEN_DEFS_S01_0_RE2
#define SEEN_DEFS_S01_0_RE2

typedef u2(*minimal_fn_s0_re2_type)();
typedef u2(_min_::*minimal_fn_s1_re2_type)();
typedef void(*run_s01_0_re2_type)(u2& retv, minimal_fn_s0_re2_type fn,
  minimal_fn_s1_re2_type sfn, void* _this);
typedef run_s01_0_re2_type s01_0_re2_dispatch_array [1];

#endif //  SEEN_DEFS_S01_0_RE2

#ifdef FULL_INCLUDE

#include "fn-array-s01_0_re2.cpp"

s01_0_re2_dispatch_array* init_s01_0_re2_dispatch_array()
{
 s01_0_re2_dispatch_array* result = (s01_0_re2_dispatch_array*) new run_s01_0_re2_type[1];
 
 (*result)[0] = &_f_2_;
 return result;
}

void run_s01_0_re2(u4 code, minimal_fn_s0_re2_type fn,
   minimal_fn_s1_re2_type sfn, u2& retv, void* _this)
{
 code %= 1;
 static s01_0_re2_dispatch_array* dispatch_array = init_s01_0_re2_dispatch_array();
 run_s01_0_re2_type f = (*dispatch_array)[code];
 f(retv, fn, sfn, _this);
}

#endif //def FULL_INCLUDE
