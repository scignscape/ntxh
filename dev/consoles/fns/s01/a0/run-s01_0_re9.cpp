


#ifndef SEEN_DEFS_S01_0_RE9
#define SEEN_DEFS_S01_0_RE9

typedef void*(*minimal_fn_s0_re9_type)();
typedef void*(_min_::*minimal_fn_s1_re9_type)();
typedef void(*run_s01_0_re9_type)(void*& retv, minimal_fn_s0_re9_type fn,
  minimal_fn_s1_re9_type sfn, void* _this);
typedef run_s01_0_re9_type s01_0_re9_dispatch_array [1];

#endif //  SEEN_DEFS_S01_0_RE9

#ifdef FULL_INCLUDE

#include "fn-array-s01_0_re9.cpp"

s01_0_re9_dispatch_array* init_s01_0_re9_dispatch_array()
{
 s01_0_re9_dispatch_array* result = (s01_0_re9_dispatch_array*) new run_s01_0_re9_type[1];
 
 (*result)[0] = &_f_9_;
 return result;
}

void run_s01_0_re9(u4 code, minimal_fn_s0_re9_type fn,
   minimal_fn_s1_re9_type sfn, void*& retv, void* _this)
{
 code %= 1;
 static s01_0_re9_dispatch_array* dispatch_array = init_s01_0_re9_dispatch_array();
 run_s01_0_re9_type f = (*dispatch_array)[code];
 f(retv, fn, sfn, _this);
}

#endif //def FULL_INCLUDE
