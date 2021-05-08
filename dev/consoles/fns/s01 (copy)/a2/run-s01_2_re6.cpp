


#ifndef SEEN_DEFS_S01_2_RE6
#define SEEN_DEFS_S01_2_RE6

typedef r8(*minimal_fn_s0_re6_type)();
typedef r8(_min_::*minimal_fn_s0_re6_type)();
typedef void(*run_s01_2_re6_type)(r8& retv, n8 arg1, n8 arg2, minimal_fn_s0_re6_type fn,
  minimal_fn_s1_re6_type sfn);
typedef run_s01_2_re6_type s01_2_re6_dispatch_array [100];

#endif //  SEEN_DEFS_S01_2_RE6

#ifdef FULL_INCLUDE

#include "fn-array-s01_2_re6.cpp"

s01_2_re6_dispatch_array* init_s01_2_re6_dispatch_array()
{
 s01_2_re6_dispatch_array* result = (s01_2_re6_dispatch_array*) new run_s01_2_re6_type[100];
 
 (*result)[0] = &_f_600_;
 (*result)[1] = &_f_601_;
 (*result)[2] = &_f_602_;
 (*result)[3] = &_f_603_;
 (*result)[4] = &_f_604_;
 (*result)[5] = &_f_605_;
 (*result)[6] = &_f_606_;
 (*result)[7] = &_f_607_;
 (*result)[8] = &_f_608_;
 (*result)[9] = &_f_609_;
 (*result)[10] = &_f_610_;
 (*result)[11] = &_f_611_;
 (*result)[12] = &_f_612_;
 (*result)[13] = &_f_613_;
 (*result)[14] = &_f_614_;
 (*result)[15] = &_f_615_;
 (*result)[16] = &_f_616_;
 (*result)[17] = &_f_617_;
 (*result)[18] = &_f_618_;
 (*result)[19] = &_f_619_;
 (*result)[20] = &_f_620_;
 (*result)[21] = &_f_621_;
 (*result)[22] = &_f_622_;
 (*result)[23] = &_f_623_;
 (*result)[24] = &_f_624_;
 (*result)[25] = &_f_625_;
 (*result)[26] = &_f_626_;
 (*result)[27] = &_f_627_;
 (*result)[28] = &_f_628_;
 (*result)[29] = &_f_629_;
 (*result)[30] = &_f_630_;
 (*result)[31] = &_f_631_;
 (*result)[32] = &_f_632_;
 (*result)[33] = &_f_633_;
 (*result)[34] = &_f_634_;
 (*result)[35] = &_f_635_;
 (*result)[36] = &_f_636_;
 (*result)[37] = &_f_637_;
 (*result)[38] = &_f_638_;
 (*result)[39] = &_f_639_;
 (*result)[40] = &_f_640_;
 (*result)[41] = &_f_641_;
 (*result)[42] = &_f_642_;
 (*result)[43] = &_f_643_;
 (*result)[44] = &_f_644_;
 (*result)[45] = &_f_645_;
 (*result)[46] = &_f_646_;
 (*result)[47] = &_f_647_;
 (*result)[48] = &_f_648_;
 (*result)[49] = &_f_649_;
 (*result)[50] = &_f_650_;
 (*result)[51] = &_f_651_;
 (*result)[52] = &_f_652_;
 (*result)[53] = &_f_653_;
 (*result)[54] = &_f_654_;
 (*result)[55] = &_f_655_;
 (*result)[56] = &_f_656_;
 (*result)[57] = &_f_657_;
 (*result)[58] = &_f_658_;
 (*result)[59] = &_f_659_;
 (*result)[60] = &_f_660_;
 (*result)[61] = &_f_661_;
 (*result)[62] = &_f_662_;
 (*result)[63] = &_f_663_;
 (*result)[64] = &_f_664_;
 (*result)[65] = &_f_665_;
 (*result)[66] = &_f_666_;
 (*result)[67] = &_f_667_;
 (*result)[68] = &_f_668_;
 (*result)[69] = &_f_669_;
 (*result)[70] = &_f_670_;
 (*result)[71] = &_f_671_;
 (*result)[72] = &_f_672_;
 (*result)[73] = &_f_673_;
 (*result)[74] = &_f_674_;
 (*result)[75] = &_f_675_;
 (*result)[76] = &_f_676_;
 (*result)[77] = &_f_677_;
 (*result)[78] = &_f_678_;
 (*result)[79] = &_f_679_;
 (*result)[80] = &_f_680_;
 (*result)[81] = &_f_681_;
 (*result)[82] = &_f_682_;
 (*result)[83] = &_f_683_;
 (*result)[84] = &_f_684_;
 (*result)[85] = &_f_685_;
 (*result)[86] = &_f_686_;
 (*result)[87] = &_f_687_;
 (*result)[88] = &_f_688_;
 (*result)[89] = &_f_689_;
 (*result)[90] = &_f_690_;
 (*result)[91] = &_f_691_;
 (*result)[92] = &_f_692_;
 (*result)[93] = &_f_693_;
 (*result)[94] = &_f_694_;
 (*result)[95] = &_f_695_;
 (*result)[96] = &_f_696_;
 (*result)[97] = &_f_697_;
 (*result)[98] = &_f_698_;
 (*result)[99] = &_f_699_;
}

void run_s01_2_re6(u4 code, minimal_fn_s01_re6_type fn, r8& retv, n8 a1, n8 a2)
{
 code %= 100;
 static s01_2_re6_dispatch_array* dispatch_array = init_s01_2_re6_dispatch_array();
 run_s01_2_re6_type f = (*dispatch_array)[code];
 f(retv, a1,a2,fn);
}

#endif //def FULL_INCLUDE
