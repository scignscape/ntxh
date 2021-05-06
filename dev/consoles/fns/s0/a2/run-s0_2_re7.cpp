


#ifndef SEEN_DEFS_S0_2_RE7
#define SEEN_DEFS_S0_2_RE7

typedef QVariant(*minimal_fn_s0_re7_type)();
typedef void(*run_s0_2_re7_type)(QVariant& retv, n8 arg1, n8 arg2, minimal_fn_s0_re7_type fn);
typedef run_s0_2_re7_type s0_2_re7_dispatch_array [100];

#endif //  SEEN_DEFS_S0_2_RE7

#ifdef FULL_INCLUDE

#include "fn-array-s0_2_re7.cpp"

s0_2_re7_dispatch_array* init_s0_2_re7_dispatch_array()
{
 s0_2_re7_dispatch_array* result = (s0_2_re7_dispatch_array*) new run_s0_2_re7_type[100];
 
 (*result)[0] = &_f_700_;
 (*result)[1] = &_f_701_;
 (*result)[2] = &_f_702_;
 (*result)[3] = &_f_703_;
 (*result)[4] = &_f_704_;
 (*result)[5] = &_f_705_;
 (*result)[6] = &_f_706_;
 (*result)[7] = &_f_707_;
 (*result)[8] = &_f_708_;
 (*result)[9] = &_f_709_;
 (*result)[10] = &_f_710_;
 (*result)[11] = &_f_711_;
 (*result)[12] = &_f_712_;
 (*result)[13] = &_f_713_;
 (*result)[14] = &_f_714_;
 (*result)[15] = &_f_715_;
 (*result)[16] = &_f_716_;
 (*result)[17] = &_f_717_;
 (*result)[18] = &_f_718_;
 (*result)[19] = &_f_719_;
 (*result)[20] = &_f_720_;
 (*result)[21] = &_f_721_;
 (*result)[22] = &_f_722_;
 (*result)[23] = &_f_723_;
 (*result)[24] = &_f_724_;
 (*result)[25] = &_f_725_;
 (*result)[26] = &_f_726_;
 (*result)[27] = &_f_727_;
 (*result)[28] = &_f_728_;
 (*result)[29] = &_f_729_;
 (*result)[30] = &_f_730_;
 (*result)[31] = &_f_731_;
 (*result)[32] = &_f_732_;
 (*result)[33] = &_f_733_;
 (*result)[34] = &_f_734_;
 (*result)[35] = &_f_735_;
 (*result)[36] = &_f_736_;
 (*result)[37] = &_f_737_;
 (*result)[38] = &_f_738_;
 (*result)[39] = &_f_739_;
 (*result)[40] = &_f_740_;
 (*result)[41] = &_f_741_;
 (*result)[42] = &_f_742_;
 (*result)[43] = &_f_743_;
 (*result)[44] = &_f_744_;
 (*result)[45] = &_f_745_;
 (*result)[46] = &_f_746_;
 (*result)[47] = &_f_747_;
 (*result)[48] = &_f_748_;
 (*result)[49] = &_f_749_;
 (*result)[50] = &_f_750_;
 (*result)[51] = &_f_751_;
 (*result)[52] = &_f_752_;
 (*result)[53] = &_f_753_;
 (*result)[54] = &_f_754_;
 (*result)[55] = &_f_755_;
 (*result)[56] = &_f_756_;
 (*result)[57] = &_f_757_;
 (*result)[58] = &_f_758_;
 (*result)[59] = &_f_759_;
 (*result)[60] = &_f_760_;
 (*result)[61] = &_f_761_;
 (*result)[62] = &_f_762_;
 (*result)[63] = &_f_763_;
 (*result)[64] = &_f_764_;
 (*result)[65] = &_f_765_;
 (*result)[66] = &_f_766_;
 (*result)[67] = &_f_767_;
 (*result)[68] = &_f_768_;
 (*result)[69] = &_f_769_;
 (*result)[70] = &_f_770_;
 (*result)[71] = &_f_771_;
 (*result)[72] = &_f_772_;
 (*result)[73] = &_f_773_;
 (*result)[74] = &_f_774_;
 (*result)[75] = &_f_775_;
 (*result)[76] = &_f_776_;
 (*result)[77] = &_f_777_;
 (*result)[78] = &_f_778_;
 (*result)[79] = &_f_779_;
 (*result)[80] = &_f_780_;
 (*result)[81] = &_f_781_;
 (*result)[82] = &_f_782_;
 (*result)[83] = &_f_783_;
 (*result)[84] = &_f_784_;
 (*result)[85] = &_f_785_;
 (*result)[86] = &_f_786_;
 (*result)[87] = &_f_787_;
 (*result)[88] = &_f_788_;
 (*result)[89] = &_f_789_;
 (*result)[90] = &_f_790_;
 (*result)[91] = &_f_791_;
 (*result)[92] = &_f_792_;
 (*result)[93] = &_f_793_;
 (*result)[94] = &_f_794_;
 (*result)[95] = &_f_795_;
 (*result)[96] = &_f_796_;
 (*result)[97] = &_f_797_;
 (*result)[98] = &_f_798_;
 (*result)[99] = &_f_799_;
}

void run_s0_2_re7(u4 code, minimal_fn_s0_re7_type fn, QVariant& retv, n8 a1, n8 a2, n8 a3)
{
 code %= 1000;
 static s0_2_re7_dispatch_array* dispatch_array = init_s0_2_re7_dispatch_array();
 run_s0_2_re7_type f = (*dispatch_array)[code];
 f(retv, a1, a2, a3, fn);
}

#endif //def FULL_INCLUDE
