
#ifndef SEEN_DEFS_S01_Xof2_RE4
#define SEEN_DEFS_S01_Xof2_RE4

typedef u4(*minimal_fn_s0_re4_type)();
typedef u4(_min_::*minimal_fn_s1_re4_type)();
typedef void(*run_s01_Xof2_re4_type)(u1 ac, u4& retv,  QVector<n8>& args,
  minimal_fn_s0_re4_type fn, minimal_fn_s1_re4_type sfn, void** _this);
typedef run_s01_Xof2_re4_type s01_Xof2_re4_dispatch_array [10];

#endif //  SEEN_DEFS_S01_Xof2_RE4

#ifdef FULL_INCLUDE

 
 // fn_01.cpp (#0) skipped
 // fn_02.cpp (#1) skipped
 // fn_03.cpp (#2) skipped
 // fn_04.cpp (#3) skipped
 // fn_05.cpp (#4) skipped
#include "../dev/consoles/fns/aXof2/aXof2-re4/fn_06.cpp" // #5
 // fn_07.cpp (#6) skipped
#include "../dev/consoles/fns/aXof2/aXof2-re4/fn_08.cpp" // #7
 // fn_09.cpp (#8) skipped
 // fn_12.cpp (#9) skipped
 // fn_13.cpp (#10) skipped
 // fn_14.cpp (#11) skipped
 // fn_15.cpp (#12) skipped
 // fn_16.cpp (#13) skipped
 // fn_17.cpp (#14) skipped
 // fn_18.cpp (#15) skipped
 // fn_19.cpp (#16) skipped
 // fn_23.cpp (#17) skipped
 // fn_24.cpp (#18) skipped
 // fn_25.cpp (#19) skipped
 // fn_26.cpp (#20) skipped
 // fn_27.cpp (#21) skipped
 // fn_28.cpp (#22) skipped
 // fn_29.cpp (#23) skipped
 // fn_34.cpp (#24) skipped
 // fn_35.cpp (#25) skipped
 // fn_36.cpp (#26) skipped
 // fn_37.cpp (#27) skipped
 // fn_38.cpp (#28) skipped
 // fn_39.cpp (#29) skipped
 // fn_45.cpp (#30) skipped
 // fn_46.cpp (#31) skipped
 // fn_47.cpp (#32) skipped
 // fn_48.cpp (#33) skipped
 // fn_49.cpp (#34) skipped
 // fn_56.cpp (#35) skipped
 // fn_57.cpp (#36) skipped
 // fn_58.cpp (#37) skipped
 // fn_59.cpp (#38) skipped
 // fn_67.cpp (#39) skipped
#include "../dev/consoles/fns/aXof2/aXof2-re4/fn_68.cpp" // #40
 // fn_69.cpp (#41) skipped
 // fn_78.cpp (#42) skipped
 // fn_79.cpp (#43) skipped
 // fn_89.cpp (#44) skipped

s01_Xof2_re4_dispatch_array* init_s01_Xof2_re4_dispatch_array()
{
 s01_Xof2_re4_dispatch_array* result = (s01_Xof2_re4_dispatch_array*) new run_s01_Xof2_re4_type[45];
 
 (*result)[0] = nullptr;
 (*result)[1] = nullptr;
 (*result)[2] = nullptr;
 (*result)[3] = nullptr;
 (*result)[4] = nullptr;
 (*result)[5] = &_f_X06_4_;
 (*result)[6] = nullptr;
 (*result)[7] = &_f_X08_4_;
 (*result)[8] = nullptr;
 (*result)[9] = nullptr;
 (*result)[10] = nullptr;
 (*result)[11] = nullptr;
 (*result)[12] = nullptr;
 (*result)[13] = nullptr;
 (*result)[14] = nullptr;
 (*result)[15] = nullptr;
 (*result)[16] = nullptr;
 (*result)[17] = nullptr;
 (*result)[18] = nullptr;
 (*result)[19] = nullptr;
 (*result)[20] = nullptr;
 (*result)[21] = nullptr;
 (*result)[22] = nullptr;
 (*result)[23] = nullptr;
 (*result)[24] = nullptr;
 (*result)[25] = nullptr;
 (*result)[26] = nullptr;
 (*result)[27] = nullptr;
 (*result)[28] = nullptr;
 (*result)[29] = nullptr;
 (*result)[30] = nullptr;
 (*result)[31] = nullptr;
 (*result)[32] = nullptr;
 (*result)[33] = nullptr;
 (*result)[34] = nullptr;
 (*result)[35] = nullptr;
 (*result)[36] = nullptr;
 (*result)[37] = nullptr;
 (*result)[38] = nullptr;
 (*result)[39] = nullptr;
 (*result)[40] = &_f_X68_4_;
 (*result)[41] = nullptr;
 (*result)[42] = nullptr;
 (*result)[43] = nullptr;
 (*result)[44] = nullptr;

 return result;
}


void run_s01_Xof2_re4(u1 ac_pattern, u1 index, minimal_fn_s0_re4_type fn,
  minimal_fn_s1_re4_type sfn, QVector<n8>& args, u4& retv,  void** _this)
{
 static s01_Xof2_re4_dispatch_array* dispatch_array = init_s01_Xof2_re4_dispatch_array();
 run_s01_Xof2_re4_type f = (*dispatch_array)[index];
 f(ac_pattern, retv, args, fn, sfn, _this);
}

#endif //def FULL_INCLUDE
   