


#ifndef SEEN_DEFS_S01_2_RE1
#define SEEN_DEFS_S01_2_RE1

typedef u1(*minimal_fn_s0_re1_type)();
typedef u1(_min_::*minimal_fn_s0_re1_type)();
typedef void(*run_s01_2_re1_type)(u1& retv, n8 arg1, n8 arg2, minimal_fn_s0_re1_type fn,
  minimal_fn_s1_re1_type sfn);
typedef run_s01_2_re1_type s01_2_re1_dispatch_array [100];

#endif //  SEEN_DEFS_S01_2_RE1

#ifdef FULL_INCLUDE

#include "fn-array-s01_2_re1.cpp"

s01_2_re1_dispatch_array* init_s01_2_re1_dispatch_array()
{
 s01_2_re1_dispatch_array* result = (s01_2_re1_dispatch_array*) new run_s01_2_re1_type[100];
 
 (*result)[0] = &_f_100_;
 (*result)[1] = &_f_101_;
 (*result)[2] = &_f_102_;
 (*result)[3] = &_f_103_;
 (*result)[4] = &_f_104_;
 (*result)[5] = &_f_105_;
 (*result)[6] = &_f_106_;
 (*result)[7] = &_f_107_;
 (*result)[8] = &_f_108_;
 (*result)[9] = &_f_109_;
 (*result)[10] = &_f_110_;
 (*result)[11] = &_f_111_;
 (*result)[12] = &_f_112_;
 (*result)[13] = &_f_113_;
 (*result)[14] = &_f_114_;
 (*result)[15] = &_f_115_;
 (*result)[16] = &_f_116_;
 (*result)[17] = &_f_117_;
 (*result)[18] = &_f_118_;
 (*result)[19] = &_f_119_;
 (*result)[20] = &_f_120_;
 (*result)[21] = &_f_121_;
 (*result)[22] = &_f_122_;
 (*result)[23] = &_f_123_;
 (*result)[24] = &_f_124_;
 (*result)[25] = &_f_125_;
 (*result)[26] = &_f_126_;
 (*result)[27] = &_f_127_;
 (*result)[28] = &_f_128_;
 (*result)[29] = &_f_129_;
 (*result)[30] = &_f_130_;
 (*result)[31] = &_f_131_;
 (*result)[32] = &_f_132_;
 (*result)[33] = &_f_133_;
 (*result)[34] = &_f_134_;
 (*result)[35] = &_f_135_;
 (*result)[36] = &_f_136_;
 (*result)[37] = &_f_137_;
 (*result)[38] = &_f_138_;
 (*result)[39] = &_f_139_;
 (*result)[40] = &_f_140_;
 (*result)[41] = &_f_141_;
 (*result)[42] = &_f_142_;
 (*result)[43] = &_f_143_;
 (*result)[44] = &_f_144_;
 (*result)[45] = &_f_145_;
 (*result)[46] = &_f_146_;
 (*result)[47] = &_f_147_;
 (*result)[48] = &_f_148_;
 (*result)[49] = &_f_149_;
 (*result)[50] = &_f_150_;
 (*result)[51] = &_f_151_;
 (*result)[52] = &_f_152_;
 (*result)[53] = &_f_153_;
 (*result)[54] = &_f_154_;
 (*result)[55] = &_f_155_;
 (*result)[56] = &_f_156_;
 (*result)[57] = &_f_157_;
 (*result)[58] = &_f_158_;
 (*result)[59] = &_f_159_;
 (*result)[60] = &_f_160_;
 (*result)[61] = &_f_161_;
 (*result)[62] = &_f_162_;
 (*result)[63] = &_f_163_;
 (*result)[64] = &_f_164_;
 (*result)[65] = &_f_165_;
 (*result)[66] = &_f_166_;
 (*result)[67] = &_f_167_;
 (*result)[68] = &_f_168_;
 (*result)[69] = &_f_169_;
 (*result)[70] = &_f_170_;
 (*result)[71] = &_f_171_;
 (*result)[72] = &_f_172_;
 (*result)[73] = &_f_173_;
 (*result)[74] = &_f_174_;
 (*result)[75] = &_f_175_;
 (*result)[76] = &_f_176_;
 (*result)[77] = &_f_177_;
 (*result)[78] = &_f_178_;
 (*result)[79] = &_f_179_;
 (*result)[80] = &_f_180_;
 (*result)[81] = &_f_181_;
 (*result)[82] = &_f_182_;
 (*result)[83] = &_f_183_;
 (*result)[84] = &_f_184_;
 (*result)[85] = &_f_185_;
 (*result)[86] = &_f_186_;
 (*result)[87] = &_f_187_;
 (*result)[88] = &_f_188_;
 (*result)[89] = &_f_189_;
 (*result)[90] = &_f_190_;
 (*result)[91] = &_f_191_;
 (*result)[92] = &_f_192_;
 (*result)[93] = &_f_193_;
 (*result)[94] = &_f_194_;
 (*result)[95] = &_f_195_;
 (*result)[96] = &_f_196_;
 (*result)[97] = &_f_197_;
 (*result)[98] = &_f_198_;
 (*result)[99] = &_f_199_;
}

void run_s01_2_re1(u4 code, minimal_fn_s01_re1_type fn, u1& retv, n8 a1, n8 a2)
{
 code %= 100;
 static s01_2_re1_dispatch_array* dispatch_array = init_s01_2_re1_dispatch_array();
 run_s01_2_re1_type f = (*dispatch_array)[code];
 f(retv, a1,a2,fn);
}

#endif //def FULL_INCLUDE
