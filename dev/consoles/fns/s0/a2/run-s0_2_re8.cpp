


#ifndef SEEN_DEFS_S0_2_RE8
#define SEEN_DEFS_S0_2_RE8

typedef n8(*minimal_fn_s0_re8_type)();
typedef void(*run_s0_2_re8_type)(n8& retv, n8 arg1, n8 arg2, minimal_fn_s0_re8_type fn);
typedef run_s0_2_re8_type s0_2_re8_dispatch_array [100];

#endif //  SEEN_DEFS_S0_2_RE8

#ifdef FULL_INCLUDE

#include "fn-array-s0_2_re8.cpp"

s0_2_re8_dispatch_array* init_s0_2_re8_dispatch_array()
{
 s0_2_re8_dispatch_array* result = (s0_2_re8_dispatch_array*) new run_s0_2_re8_type[100];
 
 (*result)[0] = &_f_800_;
 (*result)[1] = &_f_801_;
 (*result)[2] = &_f_802_;
 (*result)[3] = &_f_803_;
 (*result)[4] = &_f_804_;
 (*result)[5] = &_f_805_;
 (*result)[6] = &_f_806_;
 (*result)[7] = &_f_807_;
 (*result)[8] = &_f_808_;
 (*result)[9] = &_f_809_;
 (*result)[10] = &_f_810_;
 (*result)[11] = &_f_811_;
 (*result)[12] = &_f_812_;
 (*result)[13] = &_f_813_;
 (*result)[14] = &_f_814_;
 (*result)[15] = &_f_815_;
 (*result)[16] = &_f_816_;
 (*result)[17] = &_f_817_;
 (*result)[18] = &_f_818_;
 (*result)[19] = &_f_819_;
 (*result)[20] = &_f_820_;
 (*result)[21] = &_f_821_;
 (*result)[22] = &_f_822_;
 (*result)[23] = &_f_823_;
 (*result)[24] = &_f_824_;
 (*result)[25] = &_f_825_;
 (*result)[26] = &_f_826_;
 (*result)[27] = &_f_827_;
 (*result)[28] = &_f_828_;
 (*result)[29] = &_f_829_;
 (*result)[30] = &_f_830_;
 (*result)[31] = &_f_831_;
 (*result)[32] = &_f_832_;
 (*result)[33] = &_f_833_;
 (*result)[34] = &_f_834_;
 (*result)[35] = &_f_835_;
 (*result)[36] = &_f_836_;
 (*result)[37] = &_f_837_;
 (*result)[38] = &_f_838_;
 (*result)[39] = &_f_839_;
 (*result)[40] = &_f_840_;
 (*result)[41] = &_f_841_;
 (*result)[42] = &_f_842_;
 (*result)[43] = &_f_843_;
 (*result)[44] = &_f_844_;
 (*result)[45] = &_f_845_;
 (*result)[46] = &_f_846_;
 (*result)[47] = &_f_847_;
 (*result)[48] = &_f_848_;
 (*result)[49] = &_f_849_;
 (*result)[50] = &_f_850_;
 (*result)[51] = &_f_851_;
 (*result)[52] = &_f_852_;
 (*result)[53] = &_f_853_;
 (*result)[54] = &_f_854_;
 (*result)[55] = &_f_855_;
 (*result)[56] = &_f_856_;
 (*result)[57] = &_f_857_;
 (*result)[58] = &_f_858_;
 (*result)[59] = &_f_859_;
 (*result)[60] = &_f_860_;
 (*result)[61] = &_f_861_;
 (*result)[62] = &_f_862_;
 (*result)[63] = &_f_863_;
 (*result)[64] = &_f_864_;
 (*result)[65] = &_f_865_;
 (*result)[66] = &_f_866_;
 (*result)[67] = &_f_867_;
 (*result)[68] = &_f_868_;
 (*result)[69] = &_f_869_;
 (*result)[70] = &_f_870_;
 (*result)[71] = &_f_871_;
 (*result)[72] = &_f_872_;
 (*result)[73] = &_f_873_;
 (*result)[74] = &_f_874_;
 (*result)[75] = &_f_875_;
 (*result)[76] = &_f_876_;
 (*result)[77] = &_f_877_;
 (*result)[78] = &_f_878_;
 (*result)[79] = &_f_879_;
 (*result)[80] = &_f_880_;
 (*result)[81] = &_f_881_;
 (*result)[82] = &_f_882_;
 (*result)[83] = &_f_883_;
 (*result)[84] = &_f_884_;
 (*result)[85] = &_f_885_;
 (*result)[86] = &_f_886_;
 (*result)[87] = &_f_887_;
 (*result)[88] = &_f_888_;
 (*result)[89] = &_f_889_;
 (*result)[90] = &_f_890_;
 (*result)[91] = &_f_891_;
 (*result)[92] = &_f_892_;
 (*result)[93] = &_f_893_;
 (*result)[94] = &_f_894_;
 (*result)[95] = &_f_895_;
 (*result)[96] = &_f_896_;
 (*result)[97] = &_f_897_;
 (*result)[98] = &_f_898_;
 (*result)[99] = &_f_899_;
}

void run_s0_2_re8(u4 code, minimal_fn_s0_re8_type fn, n8& retv, n8 a1, n8 a2, n8 a3)
{
 code %= 1000;
 static s0_2_re8_dispatch_array* dispatch_array = init_s0_2_re8_dispatch_array();
 run_s0_2_re8_type f = (*dispatch_array)[code];
 f(retv, a1, a2, a3, fn);
}

#endif //def FULL_INCLUDE
