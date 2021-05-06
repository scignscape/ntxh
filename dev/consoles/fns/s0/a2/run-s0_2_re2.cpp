


#ifndef SEEN_DEFS_S0_2_RE2
#define SEEN_DEFS_S0_2_RE2

typedef u2(*minimal_fn_s0_re2_type)();
typedef void(*run_s0_2_re2_type)(u2& retv, n8 arg1, n8 arg2, minimal_fn_s0_re2_type fn);
typedef run_s0_2_re2_type s0_2_re2_dispatch_array [100];

#endif //  SEEN_DEFS_S0_2_RE2

#ifdef FULL_INCLUDE

#include "fn-array-s0_2_re2.cpp"

s0_2_re2_dispatch_array* init_s0_2_re2_dispatch_array()
{
 s0_2_re2_dispatch_array* result = (s0_2_re2_dispatch_array*) new run_s0_2_re2_type[100];
 
 (*result)[0] = &_f_200_;
 (*result)[1] = &_f_201_;
 (*result)[2] = &_f_202_;
 (*result)[3] = &_f_203_;
 (*result)[4] = &_f_204_;
 (*result)[5] = &_f_205_;
 (*result)[6] = &_f_206_;
 (*result)[7] = &_f_207_;
 (*result)[8] = &_f_208_;
 (*result)[9] = &_f_209_;
 (*result)[10] = &_f_210_;
 (*result)[11] = &_f_211_;
 (*result)[12] = &_f_212_;
 (*result)[13] = &_f_213_;
 (*result)[14] = &_f_214_;
 (*result)[15] = &_f_215_;
 (*result)[16] = &_f_216_;
 (*result)[17] = &_f_217_;
 (*result)[18] = &_f_218_;
 (*result)[19] = &_f_219_;
 (*result)[20] = &_f_220_;
 (*result)[21] = &_f_221_;
 (*result)[22] = &_f_222_;
 (*result)[23] = &_f_223_;
 (*result)[24] = &_f_224_;
 (*result)[25] = &_f_225_;
 (*result)[26] = &_f_226_;
 (*result)[27] = &_f_227_;
 (*result)[28] = &_f_228_;
 (*result)[29] = &_f_229_;
 (*result)[30] = &_f_230_;
 (*result)[31] = &_f_231_;
 (*result)[32] = &_f_232_;
 (*result)[33] = &_f_233_;
 (*result)[34] = &_f_234_;
 (*result)[35] = &_f_235_;
 (*result)[36] = &_f_236_;
 (*result)[37] = &_f_237_;
 (*result)[38] = &_f_238_;
 (*result)[39] = &_f_239_;
 (*result)[40] = &_f_240_;
 (*result)[41] = &_f_241_;
 (*result)[42] = &_f_242_;
 (*result)[43] = &_f_243_;
 (*result)[44] = &_f_244_;
 (*result)[45] = &_f_245_;
 (*result)[46] = &_f_246_;
 (*result)[47] = &_f_247_;
 (*result)[48] = &_f_248_;
 (*result)[49] = &_f_249_;
 (*result)[50] = &_f_250_;
 (*result)[51] = &_f_251_;
 (*result)[52] = &_f_252_;
 (*result)[53] = &_f_253_;
 (*result)[54] = &_f_254_;
 (*result)[55] = &_f_255_;
 (*result)[56] = &_f_256_;
 (*result)[57] = &_f_257_;
 (*result)[58] = &_f_258_;
 (*result)[59] = &_f_259_;
 (*result)[60] = &_f_260_;
 (*result)[61] = &_f_261_;
 (*result)[62] = &_f_262_;
 (*result)[63] = &_f_263_;
 (*result)[64] = &_f_264_;
 (*result)[65] = &_f_265_;
 (*result)[66] = &_f_266_;
 (*result)[67] = &_f_267_;
 (*result)[68] = &_f_268_;
 (*result)[69] = &_f_269_;
 (*result)[70] = &_f_270_;
 (*result)[71] = &_f_271_;
 (*result)[72] = &_f_272_;
 (*result)[73] = &_f_273_;
 (*result)[74] = &_f_274_;
 (*result)[75] = &_f_275_;
 (*result)[76] = &_f_276_;
 (*result)[77] = &_f_277_;
 (*result)[78] = &_f_278_;
 (*result)[79] = &_f_279_;
 (*result)[80] = &_f_280_;
 (*result)[81] = &_f_281_;
 (*result)[82] = &_f_282_;
 (*result)[83] = &_f_283_;
 (*result)[84] = &_f_284_;
 (*result)[85] = &_f_285_;
 (*result)[86] = &_f_286_;
 (*result)[87] = &_f_287_;
 (*result)[88] = &_f_288_;
 (*result)[89] = &_f_289_;
 (*result)[90] = &_f_290_;
 (*result)[91] = &_f_291_;
 (*result)[92] = &_f_292_;
 (*result)[93] = &_f_293_;
 (*result)[94] = &_f_294_;
 (*result)[95] = &_f_295_;
 (*result)[96] = &_f_296_;
 (*result)[97] = &_f_297_;
 (*result)[98] = &_f_298_;
 (*result)[99] = &_f_299_;
}

void run_s0_2_re2(u4 code, minimal_fn_s0_re2_type fn, u2& retv, n8 a1, n8 a2, n8 a3)
{
 code %= 1000;
 static s0_2_re2_dispatch_array* dispatch_array = init_s0_2_re2_dispatch_array();
 run_s0_2_re2_type f = (*dispatch_array)[code];
 f(retv, a1, a2, a3, fn);
}

#endif //def FULL_INCLUDE
