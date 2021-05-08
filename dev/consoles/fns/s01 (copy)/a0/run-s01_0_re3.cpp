


#ifndef SEEN_DEFS_S01_0_RE3
#define SEEN_DEFS_S01_0_RE3

typedef QString(*minimal_fn_s0_re3_type)();
typedef QString(_min_::*minimal_fn_s0_re3_type)();
typedef void(*run_s01_0_re3_type)(QString& retv, minimal_fn_s0_re3_type fn,
  minimal_fn_s1_re3_type sfn);
typedef run_s01_0_re3_type s01_0_re3_dispatch_array [1];

#endif //  SEEN_DEFS_S01_0_RE3

#ifdef FULL_INCLUDE

#include "fn-array-s01_0_re3.cpp"

s01_0_re3_dispatch_array* init_s01_0_re3_dispatch_array()
{
 s01_0_re3_dispatch_array* result = (s01_0_re3_dispatch_array*) new run_s01_0_re3_type[1];
 
 (*result)[0] = &_f_3_;
}

void run_s01_0_re3(u4 code, minimal_fn_s01_re3_type fn, QString& retv)
{
 code %= 1;
 static s01_0_re3_dispatch_array* dispatch_array = init_s01_0_re3_dispatch_array();
 run_s01_0_re3_type f = (*dispatch_array)[code];
 f(retv, fn);
}

#endif //def FULL_INCLUDE
