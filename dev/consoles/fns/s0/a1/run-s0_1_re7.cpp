


#ifndef SEEN_DEFS_S0_1_RE7
#define SEEN_DEFS_S0_1_RE7

typedef QVariant(*minimal_fn_s0_re7_type)();
typedef void(*run_s0_1_re7_type)(QVariant& retv, n8 arg1, minimal_fn_s0_re7_type fn);
typedef run_s0_1_re7_type s0_1_re7_dispatch_array [10];

#endif //  SEEN_DEFS_S0_1_RE7

#ifdef FULL_INCLUDE

#include "fn-array-s0_1_re7.cpp"

s0_1_re7_dispatch_array* init_s0_1_re7_dispatch_array()
{
 s0_1_re7_dispatch_array* result = (s0_1_re7_dispatch_array*) new run_s0_1_re7_type[10];
 
 (*result)[0] = &_f_70_;
 (*result)[1] = &_f_71_;
 (*result)[2] = &_f_72_;
 (*result)[3] = &_f_73_;
 (*result)[4] = &_f_74_;
 (*result)[5] = &_f_75_;
 (*result)[6] = &_f_76_;
 (*result)[7] = &_f_77_;
 (*result)[8] = &_f_78_;
 (*result)[9] = &_f_79_;
}

void run_s0_1_re7(u4 code, minimal_fn_s0_re7_type fn, QVariant& retv, n8 a1, n8 a2, n8 a3)
{
 code %= 100;
 static s0_1_re7_dispatch_array* dispatch_array = init_s0_1_re7_dispatch_array();
 run_s0_1_re7_type f = (*dispatch_array)[code];
 f(retv, a1, a2, a3, fn);
}

#endif //def FULL_INCLUDE
