


#ifndef SEEN_DEFS_S01_1_RE3
#define SEEN_DEFS_S01_1_RE3

typedef QString(*minimal_fn_s0_re3_type)();
typedef QString(_min_::*minimal_fn_s0_re3_type)();
typedef void(*run_s01_1_re3_type)(QString& retv, n8 arg1, minimal_fn_s0_re3_type fn,
  minimal_fn_s1_re3_type sfn);
typedef run_s01_1_re3_type s01_1_re3_dispatch_array [10];

#endif //  SEEN_DEFS_S01_1_RE3

#ifdef FULL_INCLUDE

#include "fn-array-s01_1_re3.cpp"

s01_1_re3_dispatch_array* init_s01_1_re3_dispatch_array()
{
 s01_1_re3_dispatch_array* result = (s01_1_re3_dispatch_array*) new run_s01_1_re3_type[10];
 
 (*result)[0] = &_f_30_;
 (*result)[1] = &_f_31_;
 (*result)[2] = &_f_32_;
 (*result)[3] = &_f_33_;
 (*result)[4] = &_f_34_;
 (*result)[5] = &_f_35_;
 (*result)[6] = &_f_36_;
 (*result)[7] = &_f_37_;
 (*result)[8] = &_f_38_;
 (*result)[9] = &_f_39_;
}

void run_s01_1_re3(u4 code, minimal_fn_s01_re3_type fn, QString& retv, n8 a1)
{
 code %= 10;
 static s01_1_re3_dispatch_array* dispatch_array = init_s01_1_re3_dispatch_array();
 run_s01_1_re3_type f = (*dispatch_array)[code];
 f(retv, a1,fn);
}

#endif //def FULL_INCLUDE
