


#ifndef SEEN_DEFS_S01_1_RE0
#define SEEN_DEFS_S01_1_RE0

typedef void(*minimal_fn_s0_re0_type)();
typedef void(_min_::*minimal_fn_s1_re0_type)();
typedef void(*run_s01_1_re0_type)(n8 arg1, minimal_fn_s0_re0_type fn,
  minimal_fn_s1_re0_type sfn, void* _this);
typedef run_s01_1_re0_type s01_1_re0_dispatch_array [10];

#endif //  SEEN_DEFS_S01_1_RE0

#ifdef FULL_INCLUDE

#include "fn-array-s01_1_re0.cpp"

s01_1_re0_dispatch_array* init_s01_1_re0_dispatch_array()
{
 s01_1_re0_dispatch_array* result = (s01_1_re0_dispatch_array*) new run_s01_1_re0_type[10];
 
 (*result)[0] = &_f_00_;
 (*result)[1] = &_f_01_;
 (*result)[2] = &_f_02_;
 (*result)[3] = &_f_03_;
 (*result)[4] = &_f_04_;
 (*result)[5] = &_f_05_;
 (*result)[6] = &_f_06_;
 (*result)[7] = &_f_07_;
 (*result)[8] = &_f_08_;
 (*result)[9] = &_f_09_;
 return result;
}

void run_s01_1_re0(u4 code, minimal_fn_s0_re0_type fn,
   minimal_fn_s1_re0_type sfn, n8 a1, void* _this)
{
 code %= 10;
 static s01_1_re0_dispatch_array* dispatch_array = init_s01_1_re0_dispatch_array();
 run_s01_1_re0_type f = (*dispatch_array)[code];
 f(a1,fn, sfn, _this);
}

#endif //def FULL_INCLUDE
