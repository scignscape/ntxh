
#ifndef SEEN_DEFS_S01_Xof2_RE9
#define SEEN_DEFS_S01_Xof2_RE9

typedef void*(*minimal_fn_s0_re9_type)();
typedef void*(_min_::*minimal_fn_s1_re9_type)();
typedef void(*run_s01_Xof2_re9_type)(u1 ac, void*& retv,  QVector<n8>& arg1s,
  minimal_fn_s0_re9_type fn, minimal_fn_s1_re9_type sfn, void* _this);
typedef run_s01_Xof2_re9_type s01_Xof2_re9_dispatch_array [10];

#endif //  SEEN_DEFS_S01_Xof1_REvoid*

#ifdef FULL_INCLUDE

 
//#include "./dev/consoles/fns/aXof1/aXof1-re9/fn_0.cpp" // #0
//#include "./dev/consoles/fns/aXof1/aXof1-re9/fn_1.cpp" // #1
//#include "./dev/consoles/fns/aXof1/aXof1-re9/fn_2.cpp" // #2
//#include "./dev/consoles/fns/aXof1/aXof1-re9/fn_3.cpp" // #3
//#include "./dev/consoles/fns/aXof1/aXof1-re9/fn_4.cpp" // #4
//#include "./dev/consoles/fns/aXof1/aXof1-re9/fn_5.cpp" // #5
//#include "./dev/consoles/fns/aXof1/aXof1-re9/fn_6.cpp" // #6
//#include "./dev/consoles/fns/aXof1/aXof1-re9/fn_7.cpp" // #7
//#include "./dev/consoles/fns/aXof1/aXof1-re9/fn_8.cpp" // #8
#include "./dev/consoles/fns/aXof2/aXof2-re9/fn_34.cpp" // #9


s01_Xof2_re9_dispatch_array* init_s01_Xof2_re9_dispatch_array()
{
 s01_Xof2_re9_dispatch_array* result = (s01_Xof2_re9_dispatch_array*) new run_s01_Xof2_re9_type[44];
 
 //(*result)[0] = &_f_X0_9_;
// (*result)[1] = &_f_X1_9_;
// (*result)[2] = &_f_X2_9_;
// (*result)[3] = &_f_X3_9_;
// (*result)[4] = &_f_X4_9_;
// (*result)[5] = &_f_X5_9_;
// (*result)[6] = &_f_X6_9_;
// (*result)[7] = &_f_X7_9_;
// (*result)[8] = &_f_X8_9_;
// (*result)[9] = &_f_X9_9_;

 (*result)[24] = &_f_X34_9_;

 return result;
}


void run_s01_Xof2_re9(u1 ac_pattern, u1 index, minimal_fn_s0_re9_type fn,
  minimal_fn_s1_re9_type sfn, QVector<n8>& args, void*& retv,  void* _this)
{
 u1 ac = (ac_pattern >> 5) + 3;
 u1 distinct_type_pattern_binary = ac_pattern & 63;

 static s01_Xof2_re9_dispatch_array* dispatch_array = init_s01_Xof2_re9_dispatch_array();
 run_s01_Xof2_re9_type f = (*dispatch_array)[index];
 f(ac_pattern, retv, args, fn, sfn, _this);
}

#endif //def FULL_INCLUDE
   
