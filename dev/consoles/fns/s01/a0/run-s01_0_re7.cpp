


#ifndef SEEN_DEFS_S01_0_RE7
#define SEEN_DEFS_S01_0_RE7

typedef QVariant(*minimal_fn_s0_re7_type)();
typedef QVariant(_min_::*minimal_fn_s1_re7_type)();
typedef void(*run_s01_0_re7_type)(QVariant& retv, minimal_fn_s0_re7_type fn,
  minimal_fn_s1_re7_type sfn, void* _this);
typedef run_s01_0_re7_type s01_0_re7_dispatch_array [1];

#endif //  SEEN_DEFS_S01_0_RE7

#ifdef FULL_INCLUDE

#include "fn-array-s01_0_re7.cpp"

s01_0_re7_dispatch_array* init_s01_0_re7_dispatch_array()
{
 s01_0_re7_dispatch_array* result = (s01_0_re7_dispatch_array*) new run_s01_0_re7_type[1];
 
 (*result)[0] = &_f_7_;
 return result;
}

void run_s01_0_re7(u4 code, minimal_fn_s0_re7_type fn,
   minimal_fn_s1_re7_type sfn, QVariant& retv, void* _this)
{
 code %= 1;
 static s01_0_re7_dispatch_array* dispatch_array = init_s01_0_re7_dispatch_array();
 run_s01_0_re7_type f = (*dispatch_array)[code];
 f(retv, fn, sfn, _this);
}

#endif //def FULL_INCLUDE
