


#ifndef SEEN_DEFS_S01_1_RE5
#define SEEN_DEFS_S01_1_RE5

typedef QByteArray(*minimal_fn_s0_re5_type)();
typedef QByteArray(_min_::*minimal_fn_s1_re5_type)();
typedef void(*run_s01_1_re5_type)(QByteArray& retv, n8 arg1, minimal_fn_s0_re5_type fn,
  minimal_fn_s1_re5_type sfn, void* _this);
typedef run_s01_1_re5_type s01_1_re5_dispatch_array [10];

#endif //  SEEN_DEFS_S01_1_RE5

#ifdef FULL_INCLUDE

#include "fn-array-s01_1_re5.cpp"

s01_1_re5_dispatch_array* init_s01_1_re5_dispatch_array()
{
 s01_1_re5_dispatch_array* result = (s01_1_re5_dispatch_array*) new run_s01_1_re5_type[10];
 
 (*result)[0] = &_f_50_;
 (*result)[1] = &_f_51_;
 (*result)[2] = &_f_52_;
 (*result)[3] = &_f_53_;
 (*result)[4] = &_f_54_;
 (*result)[5] = &_f_55_;
 (*result)[6] = &_f_56_;
 (*result)[7] = &_f_57_;
 (*result)[8] = &_f_58_;
 (*result)[9] = &_f_59_;
 return result;
}

void run_s01_1_re5(u4 code, minimal_fn_s0_re5_type fn,
   minimal_fn_s1_re5_type sfn, QByteArray& retv, n8 a1, void* _this)
{
 code %= 10;
 static s01_1_re5_dispatch_array* dispatch_array = init_s01_1_re5_dispatch_array();
 run_s01_1_re5_type f = (*dispatch_array)[code];
 f(retv, a1,fn, sfn, _this);
}

#endif //def FULL_INCLUDE
