


#ifndef SEEN_DEFS_S01_2_RE4
#define SEEN_DEFS_S01_2_RE4

typedef u4(*minimal_fn_s0_re4_type)();
typedef u4(_min_::*minimal_fn_s0_re4_type)();
typedef void(*run_s01_2_re4_type)(u4& retv, n8 arg1, n8 arg2, minimal_fn_s0_re4_type fn,
  minimal_fn_s1_re4_type sfn);
typedef run_s01_2_re4_type s01_2_re4_dispatch_array [100];

#endif //  SEEN_DEFS_S01_2_RE4

#ifdef FULL_INCLUDE

#include "fn-array-s01_2_re4.cpp"

s01_2_re4_dispatch_array* init_s01_2_re4_dispatch_array()
{
 s01_2_re4_dispatch_array* result = (s01_2_re4_dispatch_array*) new run_s01_2_re4_type[100];
 
 (*result)[0] = &_f_400_;
 (*result)[1] = &_f_401_;
 (*result)[2] = &_f_402_;
 (*result)[3] = &_f_403_;
 (*result)[4] = &_f_404_;
 (*result)[5] = &_f_405_;
 (*result)[6] = &_f_406_;
 (*result)[7] = &_f_407_;
 (*result)[8] = &_f_408_;
 (*result)[9] = &_f_409_;
 (*result)[10] = &_f_410_;
 (*result)[11] = &_f_411_;
 (*result)[12] = &_f_412_;
 (*result)[13] = &_f_413_;
 (*result)[14] = &_f_414_;
 (*result)[15] = &_f_415_;
 (*result)[16] = &_f_416_;
 (*result)[17] = &_f_417_;
 (*result)[18] = &_f_418_;
 (*result)[19] = &_f_419_;
 (*result)[20] = &_f_420_;
 (*result)[21] = &_f_421_;
 (*result)[22] = &_f_422_;
 (*result)[23] = &_f_423_;
 (*result)[24] = &_f_424_;
 (*result)[25] = &_f_425_;
 (*result)[26] = &_f_426_;
 (*result)[27] = &_f_427_;
 (*result)[28] = &_f_428_;
 (*result)[29] = &_f_429_;
 (*result)[30] = &_f_430_;
 (*result)[31] = &_f_431_;
 (*result)[32] = &_f_432_;
 (*result)[33] = &_f_433_;
 (*result)[34] = &_f_434_;
 (*result)[35] = &_f_435_;
 (*result)[36] = &_f_436_;
 (*result)[37] = &_f_437_;
 (*result)[38] = &_f_438_;
 (*result)[39] = &_f_439_;
 (*result)[40] = &_f_440_;
 (*result)[41] = &_f_441_;
 (*result)[42] = &_f_442_;
 (*result)[43] = &_f_443_;
 (*result)[44] = &_f_444_;
 (*result)[45] = &_f_445_;
 (*result)[46] = &_f_446_;
 (*result)[47] = &_f_447_;
 (*result)[48] = &_f_448_;
 (*result)[49] = &_f_449_;
 (*result)[50] = &_f_450_;
 (*result)[51] = &_f_451_;
 (*result)[52] = &_f_452_;
 (*result)[53] = &_f_453_;
 (*result)[54] = &_f_454_;
 (*result)[55] = &_f_455_;
 (*result)[56] = &_f_456_;
 (*result)[57] = &_f_457_;
 (*result)[58] = &_f_458_;
 (*result)[59] = &_f_459_;
 (*result)[60] = &_f_460_;
 (*result)[61] = &_f_461_;
 (*result)[62] = &_f_462_;
 (*result)[63] = &_f_463_;
 (*result)[64] = &_f_464_;
 (*result)[65] = &_f_465_;
 (*result)[66] = &_f_466_;
 (*result)[67] = &_f_467_;
 (*result)[68] = &_f_468_;
 (*result)[69] = &_f_469_;
 (*result)[70] = &_f_470_;
 (*result)[71] = &_f_471_;
 (*result)[72] = &_f_472_;
 (*result)[73] = &_f_473_;
 (*result)[74] = &_f_474_;
 (*result)[75] = &_f_475_;
 (*result)[76] = &_f_476_;
 (*result)[77] = &_f_477_;
 (*result)[78] = &_f_478_;
 (*result)[79] = &_f_479_;
 (*result)[80] = &_f_480_;
 (*result)[81] = &_f_481_;
 (*result)[82] = &_f_482_;
 (*result)[83] = &_f_483_;
 (*result)[84] = &_f_484_;
 (*result)[85] = &_f_485_;
 (*result)[86] = &_f_486_;
 (*result)[87] = &_f_487_;
 (*result)[88] = &_f_488_;
 (*result)[89] = &_f_489_;
 (*result)[90] = &_f_490_;
 (*result)[91] = &_f_491_;
 (*result)[92] = &_f_492_;
 (*result)[93] = &_f_493_;
 (*result)[94] = &_f_494_;
 (*result)[95] = &_f_495_;
 (*result)[96] = &_f_496_;
 (*result)[97] = &_f_497_;
 (*result)[98] = &_f_498_;
 (*result)[99] = &_f_499_;
}

void run_s01_2_re4(u4 code, minimal_fn_s01_re4_type fn, u4& retv, n8 a1, n8 a2)
{
 code %= 100;
 static s01_2_re4_dispatch_array* dispatch_array = init_s01_2_re4_dispatch_array();
 run_s01_2_re4_type f = (*dispatch_array)[code];
 f(retv, a1,a2,fn);
}

#endif //def FULL_INCLUDE
