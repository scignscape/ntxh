
#ifndef SEEN_DEFS_S01_Xof1_RE6
#define SEEN_DEFS_S01_Xof1_RE6

typedef r8(*minimal_fn_s0_re6_type)();
typedef r8(_min_::*minimal_fn_s1_re6_type)();
typedef void(*run_s01_Xof1_re6_type)(u1 ac, r8& retv,  QVector<n8>& args,
  minimal_fn_s0_re6_type fn, minimal_fn_s1_re6_type sfn, void** _this);
typedef run_s01_Xof1_re6_type s01_Xof1_re6_dispatch_array [10];

#endif //  SEEN_DEFS_S01_Xof1_RE6

#ifdef FULL_INCLUDE

 
#include "./dev/consoles/fns/aXof1/aXof1-re6/fn_0.cpp" // #0
#include "./dev/consoles/fns/aXof1/aXof1-re6/fn_1.cpp" // #1
#include "./dev/consoles/fns/aXof1/aXof1-re6/fn_2.cpp" // #2
#include "./dev/consoles/fns/aXof1/aXof1-re6/fn_3.cpp" // #3
#include "./dev/consoles/fns/aXof1/aXof1-re6/fn_4.cpp" // #4
#include "./dev/consoles/fns/aXof1/aXof1-re6/fn_5.cpp" // #5
#include "./dev/consoles/fns/aXof1/aXof1-re6/fn_6.cpp" // #6
#include "./dev/consoles/fns/aXof1/aXof1-re6/fn_7.cpp" // #7
#include "./dev/consoles/fns/aXof1/aXof1-re6/fn_8.cpp" // #8
#include "./dev/consoles/fns/aXof1/aXof1-re6/fn_9.cpp" // #9


s01_Xof1_re6_dispatch_array* init_s01_Xof1_re6_dispatch_array()
{
 s01_Xof1_re6_dispatch_array* result = (s01_Xof1_re6_dispatch_array*) new run_s01_Xof1_re6_type[10];
 
 (*result)[0] = &_f_X0_6_;
 (*result)[1] = &_f_X1_6_;
 (*result)[2] = &_f_X2_6_;
 (*result)[3] = &_f_X3_6_;
 (*result)[4] = &_f_X4_6_;
 (*result)[5] = &_f_X5_6_;
 (*result)[6] = &_f_X6_6_;
 (*result)[7] = &_f_X7_6_;
 (*result)[8] = &_f_X8_6_;
 (*result)[9] = &_f_X9_6_;

 return result;
}


void run_s01_Xof1_re6(u1 ac, u1 index, minimal_fn_s0_re6_type fn,
  minimal_fn_s1_re6_type sfn, QVector<n8>& args, r8& retv,  void** _this)
{
 static s01_Xof1_re6_dispatch_array* dispatch_array = init_s01_Xof1_re6_dispatch_array();
 run_s01_Xof1_re6_type f = (*dispatch_array)[index];
 f(ac, retv, args, fn, sfn, _this);
}

#endif //def FULL_INCLUDE
   