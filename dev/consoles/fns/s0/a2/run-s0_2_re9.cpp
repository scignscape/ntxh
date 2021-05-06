


#ifndef SEEN_DEFS_S0_2_RE9
#define SEEN_DEFS_S0_2_RE9

typedef void*(*minimal_fn_s0_re9_type)();
typedef void(*run_s0_2_re9_type)(void*& retv, n8 arg1, n8 arg2, minimal_fn_s0_re9_type fn);
typedef run_s0_2_re9_type s0_2_re9_dispatch_array [100];

#endif //  SEEN_DEFS_S0_2_RE9

#ifdef FULL_INCLUDE

#include "fn-array-s0_2_re9.cpp"

s0_2_re9_dispatch_array* init_s0_2_re9_dispatch_array()
{
 s0_2_re9_dispatch_array* result = (s0_2_re9_dispatch_array*) new run_s0_2_re9_type[100];
 
 (*result)[0] = &_f_900_;
 (*result)[1] = &_f_901_;
 (*result)[2] = &_f_902_;
 (*result)[3] = &_f_903_;
 (*result)[4] = &_f_904_;
 (*result)[5] = &_f_905_;
 (*result)[6] = &_f_906_;
 (*result)[7] = &_f_907_;
 (*result)[8] = &_f_908_;
 (*result)[9] = &_f_909_;
 (*result)[10] = &_f_910_;
 (*result)[11] = &_f_911_;
 (*result)[12] = &_f_912_;
 (*result)[13] = &_f_913_;
 (*result)[14] = &_f_914_;
 (*result)[15] = &_f_915_;
 (*result)[16] = &_f_916_;
 (*result)[17] = &_f_917_;
 (*result)[18] = &_f_918_;
 (*result)[19] = &_f_919_;
 (*result)[20] = &_f_920_;
 (*result)[21] = &_f_921_;
 (*result)[22] = &_f_922_;
 (*result)[23] = &_f_923_;
 (*result)[24] = &_f_924_;
 (*result)[25] = &_f_925_;
 (*result)[26] = &_f_926_;
 (*result)[27] = &_f_927_;
 (*result)[28] = &_f_928_;
 (*result)[29] = &_f_929_;
 (*result)[30] = &_f_930_;
 (*result)[31] = &_f_931_;
 (*result)[32] = &_f_932_;
 (*result)[33] = &_f_933_;
 (*result)[34] = &_f_934_;
 (*result)[35] = &_f_935_;
 (*result)[36] = &_f_936_;
 (*result)[37] = &_f_937_;
 (*result)[38] = &_f_938_;
 (*result)[39] = &_f_939_;
 (*result)[40] = &_f_940_;
 (*result)[41] = &_f_941_;
 (*result)[42] = &_f_942_;
 (*result)[43] = &_f_943_;
 (*result)[44] = &_f_944_;
 (*result)[45] = &_f_945_;
 (*result)[46] = &_f_946_;
 (*result)[47] = &_f_947_;
 (*result)[48] = &_f_948_;
 (*result)[49] = &_f_949_;
 (*result)[50] = &_f_950_;
 (*result)[51] = &_f_951_;
 (*result)[52] = &_f_952_;
 (*result)[53] = &_f_953_;
 (*result)[54] = &_f_954_;
 (*result)[55] = &_f_955_;
 (*result)[56] = &_f_956_;
 (*result)[57] = &_f_957_;
 (*result)[58] = &_f_958_;
 (*result)[59] = &_f_959_;
 (*result)[60] = &_f_960_;
 (*result)[61] = &_f_961_;
 (*result)[62] = &_f_962_;
 (*result)[63] = &_f_963_;
 (*result)[64] = &_f_964_;
 (*result)[65] = &_f_965_;
 (*result)[66] = &_f_966_;
 (*result)[67] = &_f_967_;
 (*result)[68] = &_f_968_;
 (*result)[69] = &_f_969_;
 (*result)[70] = &_f_970_;
 (*result)[71] = &_f_971_;
 (*result)[72] = &_f_972_;
 (*result)[73] = &_f_973_;
 (*result)[74] = &_f_974_;
 (*result)[75] = &_f_975_;
 (*result)[76] = &_f_976_;
 (*result)[77] = &_f_977_;
 (*result)[78] = &_f_978_;
 (*result)[79] = &_f_979_;
 (*result)[80] = &_f_980_;
 (*result)[81] = &_f_981_;
 (*result)[82] = &_f_982_;
 (*result)[83] = &_f_983_;
 (*result)[84] = &_f_984_;
 (*result)[85] = &_f_985_;
 (*result)[86] = &_f_986_;
 (*result)[87] = &_f_987_;
 (*result)[88] = &_f_988_;
 (*result)[89] = &_f_989_;
 (*result)[90] = &_f_990_;
 (*result)[91] = &_f_991_;
 (*result)[92] = &_f_992_;
 (*result)[93] = &_f_993_;
 (*result)[94] = &_f_994_;
 (*result)[95] = &_f_995_;
 (*result)[96] = &_f_996_;
 (*result)[97] = &_f_997_;
 (*result)[98] = &_f_998_;
 (*result)[99] = &_f_999_;
}

void run_s0_2_re9(u4 code, minimal_fn_s0_re9_type fn, void*& retv, n8 a1, n8 a2)
{
 code %= 1000;
 static s0_2_re9_dispatch_array* dispatch_array = init_s0_2_re9_dispatch_array();
 run_s0_2_re9_type f = (*dispatch_array)[code];
 f(retv, a1,a2,fn);
}

#endif //def FULL_INCLUDE
