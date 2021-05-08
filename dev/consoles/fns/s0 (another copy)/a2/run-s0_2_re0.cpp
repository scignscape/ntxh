


#ifndef SEEN_DEFS_S0_2_RE0
#define SEEN_DEFS_S0_2_RE0

typedef void(*minimal_fn_s0_re0_type)();
typedef void(*run_s0_2_re0_type)(n8 arg1, n8 arg2, minimal_fn_s0_re0_type fn);
typedef run_s0_2_re0_type s0_2_re0_dispatch_array [100];

#endif //  SEEN_DEFS_S0_2_RE0

#ifdef FULL_INCLUDE

#include "fn-array-s0_2_re0.cpp"

s0_2_re0_dispatch_array* init_s0_2_re0_dispatch_array()
{
 s0_2_re0_dispatch_array* result = (s0_2_re0_dispatch_array*) new run_s0_2_re0_type[100];
 
 (*result)[0] = &_f_000_;
 (*result)[1] = &_f_001_;
 (*result)[2] = &_f_002_;
 (*result)[3] = &_f_003_;
 (*result)[4] = &_f_004_;
 (*result)[5] = &_f_005_;
 (*result)[6] = &_f_006_;
 (*result)[7] = &_f_007_;
 (*result)[8] = &_f_008_;
 (*result)[9] = &_f_009_;
 (*result)[10] = &_f_010_;
 (*result)[11] = &_f_011_;
 (*result)[12] = &_f_012_;
 (*result)[13] = &_f_013_;
 (*result)[14] = &_f_014_;
 (*result)[15] = &_f_015_;
 (*result)[16] = &_f_016_;
 (*result)[17] = &_f_017_;
 (*result)[18] = &_f_018_;
 (*result)[19] = &_f_019_;
 (*result)[20] = &_f_020_;
 (*result)[21] = &_f_021_;
 (*result)[22] = &_f_022_;
 (*result)[23] = &_f_023_;
 (*result)[24] = &_f_024_;
 (*result)[25] = &_f_025_;
 (*result)[26] = &_f_026_;
 (*result)[27] = &_f_027_;
 (*result)[28] = &_f_028_;
 (*result)[29] = &_f_029_;
 (*result)[30] = &_f_030_;
 (*result)[31] = &_f_031_;
 (*result)[32] = &_f_032_;
 (*result)[33] = &_f_033_;
 (*result)[34] = &_f_034_;
 (*result)[35] = &_f_035_;
 (*result)[36] = &_f_036_;
 (*result)[37] = &_f_037_;
 (*result)[38] = &_f_038_;
 (*result)[39] = &_f_039_;
 (*result)[40] = &_f_040_;
 (*result)[41] = &_f_041_;
 (*result)[42] = &_f_042_;
 (*result)[43] = &_f_043_;
 (*result)[44] = &_f_044_;
 (*result)[45] = &_f_045_;
 (*result)[46] = &_f_046_;
 (*result)[47] = &_f_047_;
 (*result)[48] = &_f_048_;
 (*result)[49] = &_f_049_;
 (*result)[50] = &_f_050_;
 (*result)[51] = &_f_051_;
 (*result)[52] = &_f_052_;
 (*result)[53] = &_f_053_;
 (*result)[54] = &_f_054_;
 (*result)[55] = &_f_055_;
 (*result)[56] = &_f_056_;
 (*result)[57] = &_f_057_;
 (*result)[58] = &_f_058_;
 (*result)[59] = &_f_059_;
 (*result)[60] = &_f_060_;
 (*result)[61] = &_f_061_;
 (*result)[62] = &_f_062_;
 (*result)[63] = &_f_063_;
 (*result)[64] = &_f_064_;
 (*result)[65] = &_f_065_;
 (*result)[66] = &_f_066_;
 (*result)[67] = &_f_067_;
 (*result)[68] = &_f_068_;
 (*result)[69] = &_f_069_;
 (*result)[70] = &_f_070_;
 (*result)[71] = &_f_071_;
 (*result)[72] = &_f_072_;
 (*result)[73] = &_f_073_;
 (*result)[74] = &_f_074_;
 (*result)[75] = &_f_075_;
 (*result)[76] = &_f_076_;
 (*result)[77] = &_f_077_;
 (*result)[78] = &_f_078_;
 (*result)[79] = &_f_079_;
 (*result)[80] = &_f_080_;
 (*result)[81] = &_f_081_;
 (*result)[82] = &_f_082_;
 (*result)[83] = &_f_083_;
 (*result)[84] = &_f_084_;
 (*result)[85] = &_f_085_;
 (*result)[86] = &_f_086_;
 (*result)[87] = &_f_087_;
 (*result)[88] = &_f_088_;
 (*result)[89] = &_f_089_;
 (*result)[90] = &_f_090_;
 (*result)[91] = &_f_091_;
 (*result)[92] = &_f_092_;
 (*result)[93] = &_f_093_;
 (*result)[94] = &_f_094_;
 (*result)[95] = &_f_095_;
 (*result)[96] = &_f_096_;
 (*result)[97] = &_f_097_;
 (*result)[98] = &_f_098_;
 (*result)[99] = &_f_099_;
}

void run_s0_2_re0(u4 code, minimal_fn_s0_re0_type fn, n8 a1, n8 a2)
{
 code %= 100;
 static s0_2_re0_dispatch_array* dispatch_array = init_s0_2_re0_dispatch_array();
 run_s0_2_re0_type f = (*dispatch_array)[code];
 f(a1,a2,fn);
}

#endif //def FULL_INCLUDE
