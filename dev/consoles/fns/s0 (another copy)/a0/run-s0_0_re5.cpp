


#ifndef SEEN_DEFS_S0_0_RE5
#define SEEN_DEFS_S0_0_RE5

typedef QByteArray(*minimal_fn_s0_re5_type)();
typedef void(*run_s0_0_re5_type)(QByteArray& retv, minimal_fn_s0_re5_type fn);
typedef run_s0_0_re5_type s0_0_re5_dispatch_array [1];

#endif //  SEEN_DEFS_S0_0_RE5

#ifdef FULL_INCLUDE

#include "fn-array-s0_0_re5.cpp"

s0_0_re5_dispatch_array* init_s0_0_re5_dispatch_array()
{
 s0_0_re5_dispatch_array* result = (s0_0_re5_dispatch_array*) new run_s0_0_re5_type[1];
 
 (*result)[0] = &_f_5_;
}

void run_s0_0_re5(u4 code, minimal_fn_s0_re5_type fn, QByteArray& retv)
{
 code %= 1;
 static s0_0_re5_dispatch_array* dispatch_array = init_s0_0_re5_dispatch_array();
 run_s0_0_re5_type f = (*dispatch_array)[code];
 f(retv, fn);
}

#endif //def FULL_INCLUDE
