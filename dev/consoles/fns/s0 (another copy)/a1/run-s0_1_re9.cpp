


#ifndef SEEN_DEFS_S0_1_RE9
#define SEEN_DEFS_S0_1_RE9

typedef void*(*minimal_fn_s0_re9_type)();
typedef void(*run_s0_1_re9_type)(void*& retv, n8 arg1, minimal_fn_s0_re9_type fn);
typedef run_s0_1_re9_type s0_1_re9_dispatch_array [10];

#endif //  SEEN_DEFS_S0_1_RE9

#ifdef FULL_INCLUDE

#include "fn-array-s0_1_re9.cpp"

s0_1_re9_dispatch_array* init_s0_1_re9_dispatch_array()
{
 s0_1_re9_dispatch_array* result = (s0_1_re9_dispatch_array*) new run_s0_1_re9_type[10];
 
 (*result)[0] = &_f_90_;
 (*result)[1] = &_f_91_;
 (*result)[2] = &_f_92_;
 (*result)[3] = &_f_93_;
 (*result)[4] = &_f_94_;
 (*result)[5] = &_f_95_;
 (*result)[6] = &_f_96_;
 (*result)[7] = &_f_97_;
 (*result)[8] = &_f_98_;
 (*result)[9] = &_f_99_;
}

void run_s0_1_re9(u4 code, minimal_fn_s0_re9_type fn, void*& retv, n8 a1)
{
 code %= 10;
 static s0_1_re9_dispatch_array* dispatch_array = init_s0_1_re9_dispatch_array();
 run_s0_1_re9_type f = (*dispatch_array)[code];
 f(retv, a1,fn);
}

#endif //def FULL_INCLUDE
