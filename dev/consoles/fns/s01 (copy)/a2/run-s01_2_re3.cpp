


#ifndef SEEN_DEFS_S01_2_RE3
#define SEEN_DEFS_S01_2_RE3

typedef QString(*minimal_fn_s0_re3_type)();
typedef QString(_min_::*minimal_fn_s0_re3_type)();
typedef void(*run_s01_2_re3_type)(QString& retv, n8 arg1, n8 arg2, minimal_fn_s0_re3_type fn,
  minimal_fn_s1_re3_type sfn);
typedef run_s01_2_re3_type s01_2_re3_dispatch_array [100];

#endif //  SEEN_DEFS_S01_2_RE3

#ifdef FULL_INCLUDE

#include "fn-array-s01_2_re3.cpp"

s01_2_re3_dispatch_array* init_s01_2_re3_dispatch_array()
{
 s01_2_re3_dispatch_array* result = (s01_2_re3_dispatch_array*) new run_s01_2_re3_type[100];
 
 (*result)[0] = &_f_300_;
 (*result)[1] = &_f_301_;
 (*result)[2] = &_f_302_;
 (*result)[3] = &_f_303_;
 (*result)[4] = &_f_304_;
 (*result)[5] = &_f_305_;
 (*result)[6] = &_f_306_;
 (*result)[7] = &_f_307_;
 (*result)[8] = &_f_308_;
 (*result)[9] = &_f_309_;
 (*result)[10] = &_f_310_;
 (*result)[11] = &_f_311_;
 (*result)[12] = &_f_312_;
 (*result)[13] = &_f_313_;
 (*result)[14] = &_f_314_;
 (*result)[15] = &_f_315_;
 (*result)[16] = &_f_316_;
 (*result)[17] = &_f_317_;
 (*result)[18] = &_f_318_;
 (*result)[19] = &_f_319_;
 (*result)[20] = &_f_320_;
 (*result)[21] = &_f_321_;
 (*result)[22] = &_f_322_;
 (*result)[23] = &_f_323_;
 (*result)[24] = &_f_324_;
 (*result)[25] = &_f_325_;
 (*result)[26] = &_f_326_;
 (*result)[27] = &_f_327_;
 (*result)[28] = &_f_328_;
 (*result)[29] = &_f_329_;
 (*result)[30] = &_f_330_;
 (*result)[31] = &_f_331_;
 (*result)[32] = &_f_332_;
 (*result)[33] = &_f_333_;
 (*result)[34] = &_f_334_;
 (*result)[35] = &_f_335_;
 (*result)[36] = &_f_336_;
 (*result)[37] = &_f_337_;
 (*result)[38] = &_f_338_;
 (*result)[39] = &_f_339_;
 (*result)[40] = &_f_340_;
 (*result)[41] = &_f_341_;
 (*result)[42] = &_f_342_;
 (*result)[43] = &_f_343_;
 (*result)[44] = &_f_344_;
 (*result)[45] = &_f_345_;
 (*result)[46] = &_f_346_;
 (*result)[47] = &_f_347_;
 (*result)[48] = &_f_348_;
 (*result)[49] = &_f_349_;
 (*result)[50] = &_f_350_;
 (*result)[51] = &_f_351_;
 (*result)[52] = &_f_352_;
 (*result)[53] = &_f_353_;
 (*result)[54] = &_f_354_;
 (*result)[55] = &_f_355_;
 (*result)[56] = &_f_356_;
 (*result)[57] = &_f_357_;
 (*result)[58] = &_f_358_;
 (*result)[59] = &_f_359_;
 (*result)[60] = &_f_360_;
 (*result)[61] = &_f_361_;
 (*result)[62] = &_f_362_;
 (*result)[63] = &_f_363_;
 (*result)[64] = &_f_364_;
 (*result)[65] = &_f_365_;
 (*result)[66] = &_f_366_;
 (*result)[67] = &_f_367_;
 (*result)[68] = &_f_368_;
 (*result)[69] = &_f_369_;
 (*result)[70] = &_f_370_;
 (*result)[71] = &_f_371_;
 (*result)[72] = &_f_372_;
 (*result)[73] = &_f_373_;
 (*result)[74] = &_f_374_;
 (*result)[75] = &_f_375_;
 (*result)[76] = &_f_376_;
 (*result)[77] = &_f_377_;
 (*result)[78] = &_f_378_;
 (*result)[79] = &_f_379_;
 (*result)[80] = &_f_380_;
 (*result)[81] = &_f_381_;
 (*result)[82] = &_f_382_;
 (*result)[83] = &_f_383_;
 (*result)[84] = &_f_384_;
 (*result)[85] = &_f_385_;
 (*result)[86] = &_f_386_;
 (*result)[87] = &_f_387_;
 (*result)[88] = &_f_388_;
 (*result)[89] = &_f_389_;
 (*result)[90] = &_f_390_;
 (*result)[91] = &_f_391_;
 (*result)[92] = &_f_392_;
 (*result)[93] = &_f_393_;
 (*result)[94] = &_f_394_;
 (*result)[95] = &_f_395_;
 (*result)[96] = &_f_396_;
 (*result)[97] = &_f_397_;
 (*result)[98] = &_f_398_;
 (*result)[99] = &_f_399_;
}

void run_s01_2_re3(u4 code, minimal_fn_s01_re3_type fn, QString& retv, n8 a1, n8 a2)
{
 code %= 100;
 static s01_2_re3_dispatch_array* dispatch_array = init_s01_2_re3_dispatch_array();
 run_s01_2_re3_type f = (*dispatch_array)[code];
 f(retv, a1,a2,fn);
}

#endif //def FULL_INCLUDE
