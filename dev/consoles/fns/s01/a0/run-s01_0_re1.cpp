


#ifndef SEEN_DEFS_S01_0_RE1
#define SEEN_DEFS_S01_0_RE1

typedef u1(*minimal_fn_s0_re1_type)();
typedef u1(_min_::*minimal_fn_s1_re1_type)();
typedef void(*run_s01_0_re1_type)(u1& retv, minimal_fn_s0_re1_type fn,
  minimal_fn_s1_re1_type sfn, void* _this);
typedef run_s01_0_re1_type s01_0_re1_dispatch_array [1];

#endif //  SEEN_DEFS_S01_0_RE1

#ifdef FULL_INCLUDE

#include "fn-array-s01_0_re1.cpp"

s01_0_re1_dispatch_array* init_s01_0_re1_dispatch_array()
{
 s01_0_re1_dispatch_array* result = (s01_0_re1_dispatch_array*) new run_s01_0_re1_type[1];
 
 (*result)[0] = &_f_1_;
 return result;
}

void run_s01_0_re1(u4 code, minimal_fn_s0_re1_type fn,
   minimal_fn_s1_re1_type sfn, u1& retv, void* _this)
{
 code %= 1;
 static s01_0_re1_dispatch_array* dispatch_array = init_s01_0_re1_dispatch_array();
 run_s01_0_re1_type f = (*dispatch_array)[code];
 f(retv, fn, sfn, _this);
}

#endif //def FULL_INCLUDE