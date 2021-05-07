


#ifndef SEEN_DEFS_S0_2_RE5
#define SEEN_DEFS_S0_2_RE5

typedef QByteArray(*minimal_fn_s0_re5_type)();
typedef void(*run_s0_2_re5_type)(QByteArray& retv, n8 arg1, n8 arg2, minimal_fn_s0_re5_type fn);
typedef run_s0_2_re5_type s0_2_re5_dispatch_array [100];

#endif //  SEEN_DEFS_S0_2_RE5

#ifdef FULL_INCLUDE

#include "fn-array-s0_2_re5.cpp"

s0_2_re5_dispatch_array* init_s0_2_re5_dispatch_array()
{
 s0_2_re5_dispatch_array* result = (s0_2_re5_dispatch_array*) new run_s0_2_re5_type[100];
 
 (*result)[0] = &_f_500_;
 (*result)[1] = &_f_501_;
 (*result)[2] = &_f_502_;
 (*result)[3] = &_f_503_;
 (*result)[4] = &_f_504_;
 (*result)[5] = &_f_505_;
 (*result)[6] = &_f_506_;
 (*result)[7] = &_f_507_;
 (*result)[8] = &_f_508_;
 (*result)[9] = &_f_509_;
 (*result)[10] = &_f_510_;
 (*result)[11] = &_f_511_;
 (*result)[12] = &_f_512_;
 (*result)[13] = &_f_513_;
 (*result)[14] = &_f_514_;
 (*result)[15] = &_f_515_;
 (*result)[16] = &_f_516_;
 (*result)[17] = &_f_517_;
 (*result)[18] = &_f_518_;
 (*result)[19] = &_f_519_;
 (*result)[20] = &_f_520_;
 (*result)[21] = &_f_521_;
 (*result)[22] = &_f_522_;
 (*result)[23] = &_f_523_;
 (*result)[24] = &_f_524_;
 (*result)[25] = &_f_525_;
 (*result)[26] = &_f_526_;
 (*result)[27] = &_f_527_;
 (*result)[28] = &_f_528_;
 (*result)[29] = &_f_529_;
 (*result)[30] = &_f_530_;
 (*result)[31] = &_f_531_;
 (*result)[32] = &_f_532_;
 (*result)[33] = &_f_533_;
 (*result)[34] = &_f_534_;
 (*result)[35] = &_f_535_;
 (*result)[36] = &_f_536_;
 (*result)[37] = &_f_537_;
 (*result)[38] = &_f_538_;
 (*result)[39] = &_f_539_;
 (*result)[40] = &_f_540_;
 (*result)[41] = &_f_541_;
 (*result)[42] = &_f_542_;
 (*result)[43] = &_f_543_;
 (*result)[44] = &_f_544_;
 (*result)[45] = &_f_545_;
 (*result)[46] = &_f_546_;
 (*result)[47] = &_f_547_;
 (*result)[48] = &_f_548_;
 (*result)[49] = &_f_549_;
 (*result)[50] = &_f_550_;
 (*result)[51] = &_f_551_;
 (*result)[52] = &_f_552_;
 (*result)[53] = &_f_553_;
 (*result)[54] = &_f_554_;
 (*result)[55] = &_f_555_;
 (*result)[56] = &_f_556_;
 (*result)[57] = &_f_557_;
 (*result)[58] = &_f_558_;
 (*result)[59] = &_f_559_;
 (*result)[60] = &_f_560_;
 (*result)[61] = &_f_561_;
 (*result)[62] = &_f_562_;
 (*result)[63] = &_f_563_;
 (*result)[64] = &_f_564_;
 (*result)[65] = &_f_565_;
 (*result)[66] = &_f_566_;
 (*result)[67] = &_f_567_;
 (*result)[68] = &_f_568_;
 (*result)[69] = &_f_569_;
 (*result)[70] = &_f_570_;
 (*result)[71] = &_f_571_;
 (*result)[72] = &_f_572_;
 (*result)[73] = &_f_573_;
 (*result)[74] = &_f_574_;
 (*result)[75] = &_f_575_;
 (*result)[76] = &_f_576_;
 (*result)[77] = &_f_577_;
 (*result)[78] = &_f_578_;
 (*result)[79] = &_f_579_;
 (*result)[80] = &_f_580_;
 (*result)[81] = &_f_581_;
 (*result)[82] = &_f_582_;
 (*result)[83] = &_f_583_;
 (*result)[84] = &_f_584_;
 (*result)[85] = &_f_585_;
 (*result)[86] = &_f_586_;
 (*result)[87] = &_f_587_;
 (*result)[88] = &_f_588_;
 (*result)[89] = &_f_589_;
 (*result)[90] = &_f_590_;
 (*result)[91] = &_f_591_;
 (*result)[92] = &_f_592_;
 (*result)[93] = &_f_593_;
 (*result)[94] = &_f_594_;
 (*result)[95] = &_f_595_;
 (*result)[96] = &_f_596_;
 (*result)[97] = &_f_597_;
 (*result)[98] = &_f_598_;
 (*result)[99] = &_f_599_;
}

void run_s0_2_re5(u4 code, minimal_fn_s0_re5_type fn, QByteArray& retv, n8 a1, n8 a2)
{
 code %= 100;
 static s0_2_re5_dispatch_array* dispatch_array = init_s0_2_re5_dispatch_array();
 run_s0_2_re5_type f = (*dispatch_array)[code];
 f(retv, a1,a2,fn);
}

#endif //def FULL_INCLUDE
