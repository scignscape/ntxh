


#ifndef SEEN_DEFS_S0_0_RE7
#define SEEN_DEFS_S0_0_RE7

typedef QVariant(*minimal_fn_s0_re7_type)();
typedef void(*run_s0_0_re7_type)(QVariant& retv, minimal_fn_s0_re7_type fn);
typedef run_s0_0_re7_type s0_0_re7_dispatch_array [1];

#endif //  SEEN_DEFS_S0_0_RE7

#ifdef FULL_INCLUDE

#include "fn-array-s0_0_re7.cpp"

s0_0_re7_dispatch_array* init_s0_0_re7_dispatch_array()
{
 s0_0_re7_dispatch_array* result = (s0_0_re7_dispatch_array*) new run_s0_0_re7_type[1];
 
 (*result)[0] = &_f_7_;
}

void run_s0_0_re7(u4 code, minimal_fn_s0_re7_type fn, QVariant& retv)
{
 code %= 1;
 static s0_0_re7_dispatch_array* dispatch_array = init_s0_0_re7_dispatch_array();
 run_s0_0_re7_type f = (*dispatch_array)[code];
 f(retv, fn);
}

#endif //def FULL_INCLUDE
