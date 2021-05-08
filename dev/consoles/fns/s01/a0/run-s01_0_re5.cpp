


#ifndef SEEN_DEFS_S01_0_RE5
#define SEEN_DEFS_S01_0_RE5

typedef QByteArray(*minimal_fn_s0_re5_type)();
typedef QByteArray(_min_::*minimal_fn_s1_re5_type)();
typedef void(*run_s01_0_re5_type)(QByteArray& retv, minimal_fn_s0_re5_type fn,
  minimal_fn_s1_re5_type sfn, void* _this);
typedef run_s01_0_re5_type s01_0_re5_dispatch_array [1];

#endif //  SEEN_DEFS_S01_0_RE5

#ifdef FULL_INCLUDE

#include "fn-array-s01_0_re5.cpp"

s01_0_re5_dispatch_array* init_s01_0_re5_dispatch_array()
{
 s01_0_re5_dispatch_array* result = (s01_0_re5_dispatch_array*) new run_s01_0_re5_type[1];
 
 (*result)[0] = &_f_5_;
 return result;
}

void run_s01_0_re5(u4 code, minimal_fn_s0_re5_type fn,
   minimal_fn_s1_re5_type sfn, QByteArray& retv, void* _this)
{
 code %= 1;
 static s01_0_re5_dispatch_array* dispatch_array = init_s01_0_re5_dispatch_array();
 run_s01_0_re5_type f = (*dispatch_array)[code];
 f(retv, fn, sfn, _this);
}

#endif //def FULL_INCLUDE
