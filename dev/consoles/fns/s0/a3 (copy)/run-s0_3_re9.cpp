


#ifndef SEEN_DEFS_S0_3_RE9
#define SEEN_DEFS_S0_3_RE9

typedef void*(*minimal_fn_s0_re9_type)();
typedef void(*run_s0_3_re9_type)(void*& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re9_type fn);
typedef run_s0_3_re9_type s0_3_re9_dispatch_array [1000];

#endif //  SEEN_DEFS_S0_3_RE9

#ifdef FULL_INCLUDE

#include "fn-array-s0_3_re9.cpp"

s0_3_re9_dispatch_array* init_s0_3_re9_dispatch_array()
{
 s0_3_re9_dispatch_array* result = (s0_3_re9_dispatch_array*) new run_s0_3_re9_type[1000];
 
 (*result)[0] = &_f_9000_;
 (*result)[1] = &_f_9001_;
 (*result)[2] = &_f_9002_;
 (*result)[3] = &_f_9003_;
 (*result)[4] = &_f_9004_;
 (*result)[5] = &_f_9005_;
 (*result)[6] = &_f_9006_;
 (*result)[7] = &_f_9007_;
 (*result)[8] = &_f_9008_;
 (*result)[9] = &_f_9009_;
 (*result)[10] = &_f_9010_;
 (*result)[11] = &_f_9011_;
 (*result)[12] = &_f_9012_;
 (*result)[13] = &_f_9013_;
 (*result)[14] = &_f_9014_;
 (*result)[15] = &_f_9015_;
 (*result)[16] = &_f_9016_;
 (*result)[17] = &_f_9017_;
 (*result)[18] = &_f_9018_;
 (*result)[19] = &_f_9019_;
 (*result)[20] = &_f_9020_;
 (*result)[21] = &_f_9021_;
 (*result)[22] = &_f_9022_;
 (*result)[23] = &_f_9023_;
 (*result)[24] = &_f_9024_;
 (*result)[25] = &_f_9025_;
 (*result)[26] = &_f_9026_;
 (*result)[27] = &_f_9027_;
 (*result)[28] = &_f_9028_;
 (*result)[29] = &_f_9029_;
 (*result)[30] = &_f_9030_;
 (*result)[31] = &_f_9031_;
 (*result)[32] = &_f_9032_;
 (*result)[33] = &_f_9033_;
 (*result)[34] = &_f_9034_;
 (*result)[35] = &_f_9035_;
 (*result)[36] = &_f_9036_;
 (*result)[37] = &_f_9037_;
 (*result)[38] = &_f_9038_;
 (*result)[39] = &_f_9039_;
 (*result)[40] = &_f_9040_;
 (*result)[41] = &_f_9041_;
 (*result)[42] = &_f_9042_;
 (*result)[43] = &_f_9043_;
 (*result)[44] = &_f_9044_;
 (*result)[45] = &_f_9045_;
 (*result)[46] = &_f_9046_;
 (*result)[47] = &_f_9047_;
 (*result)[48] = &_f_9048_;
 (*result)[49] = &_f_9049_;
 (*result)[50] = &_f_9050_;
 (*result)[51] = &_f_9051_;
 (*result)[52] = &_f_9052_;
 (*result)[53] = &_f_9053_;
 (*result)[54] = &_f_9054_;
 (*result)[55] = &_f_9055_;
 (*result)[56] = &_f_9056_;
 (*result)[57] = &_f_9057_;
 (*result)[58] = &_f_9058_;
 (*result)[59] = &_f_9059_;
 (*result)[60] = &_f_9060_;
 (*result)[61] = &_f_9061_;
 (*result)[62] = &_f_9062_;
 (*result)[63] = &_f_9063_;
 (*result)[64] = &_f_9064_;
 (*result)[65] = &_f_9065_;
 (*result)[66] = &_f_9066_;
 (*result)[67] = &_f_9067_;
 (*result)[68] = &_f_9068_;
 (*result)[69] = &_f_9069_;
 (*result)[70] = &_f_9070_;
 (*result)[71] = &_f_9071_;
 (*result)[72] = &_f_9072_;
 (*result)[73] = &_f_9073_;
 (*result)[74] = &_f_9074_;
 (*result)[75] = &_f_9075_;
 (*result)[76] = &_f_9076_;
 (*result)[77] = &_f_9077_;
 (*result)[78] = &_f_9078_;
 (*result)[79] = &_f_9079_;
 (*result)[80] = &_f_9080_;
 (*result)[81] = &_f_9081_;
 (*result)[82] = &_f_9082_;
 (*result)[83] = &_f_9083_;
 (*result)[84] = &_f_9084_;
 (*result)[85] = &_f_9085_;
 (*result)[86] = &_f_9086_;
 (*result)[87] = &_f_9087_;
 (*result)[88] = &_f_9088_;
 (*result)[89] = &_f_9089_;
 (*result)[90] = &_f_9090_;
 (*result)[91] = &_f_9091_;
 (*result)[92] = &_f_9092_;
 (*result)[93] = &_f_9093_;
 (*result)[94] = &_f_9094_;
 (*result)[95] = &_f_9095_;
 (*result)[96] = &_f_9096_;
 (*result)[97] = &_f_9097_;
 (*result)[98] = &_f_9098_;
 (*result)[99] = &_f_9099_;
 (*result)[100] = &_f_9100_;
 (*result)[101] = &_f_9101_;
 (*result)[102] = &_f_9102_;
 (*result)[103] = &_f_9103_;
 (*result)[104] = &_f_9104_;
 (*result)[105] = &_f_9105_;
 (*result)[106] = &_f_9106_;
 (*result)[107] = &_f_9107_;
 (*result)[108] = &_f_9108_;
 (*result)[109] = &_f_9109_;
 (*result)[110] = &_f_9110_;
 (*result)[111] = &_f_9111_;
 (*result)[112] = &_f_9112_;
 (*result)[113] = &_f_9113_;
 (*result)[114] = &_f_9114_;
 (*result)[115] = &_f_9115_;
 (*result)[116] = &_f_9116_;
 (*result)[117] = &_f_9117_;
 (*result)[118] = &_f_9118_;
 (*result)[119] = &_f_9119_;
 (*result)[120] = &_f_9120_;
 (*result)[121] = &_f_9121_;
 (*result)[122] = &_f_9122_;
 (*result)[123] = &_f_9123_;
 (*result)[124] = &_f_9124_;
 (*result)[125] = &_f_9125_;
 (*result)[126] = &_f_9126_;
 (*result)[127] = &_f_9127_;
 (*result)[128] = &_f_9128_;
 (*result)[129] = &_f_9129_;
 (*result)[130] = &_f_9130_;
 (*result)[131] = &_f_9131_;
 (*result)[132] = &_f_9132_;
 (*result)[133] = &_f_9133_;
 (*result)[134] = &_f_9134_;
 (*result)[135] = &_f_9135_;
 (*result)[136] = &_f_9136_;
 (*result)[137] = &_f_9137_;
 (*result)[138] = &_f_9138_;
 (*result)[139] = &_f_9139_;
 (*result)[140] = &_f_9140_;
 (*result)[141] = &_f_9141_;
 (*result)[142] = &_f_9142_;
 (*result)[143] = &_f_9143_;
 (*result)[144] = &_f_9144_;
 (*result)[145] = &_f_9145_;
 (*result)[146] = &_f_9146_;
 (*result)[147] = &_f_9147_;
 (*result)[148] = &_f_9148_;
 (*result)[149] = &_f_9149_;
 (*result)[150] = &_f_9150_;
 (*result)[151] = &_f_9151_;
 (*result)[152] = &_f_9152_;
 (*result)[153] = &_f_9153_;
 (*result)[154] = &_f_9154_;
 (*result)[155] = &_f_9155_;
 (*result)[156] = &_f_9156_;
 (*result)[157] = &_f_9157_;
 (*result)[158] = &_f_9158_;
 (*result)[159] = &_f_9159_;
 (*result)[160] = &_f_9160_;
 (*result)[161] = &_f_9161_;
 (*result)[162] = &_f_9162_;
 (*result)[163] = &_f_9163_;
 (*result)[164] = &_f_9164_;
 (*result)[165] = &_f_9165_;
 (*result)[166] = &_f_9166_;
 (*result)[167] = &_f_9167_;
 (*result)[168] = &_f_9168_;
 (*result)[169] = &_f_9169_;
 (*result)[170] = &_f_9170_;
 (*result)[171] = &_f_9171_;
 (*result)[172] = &_f_9172_;
 (*result)[173] = &_f_9173_;
 (*result)[174] = &_f_9174_;
 (*result)[175] = &_f_9175_;
 (*result)[176] = &_f_9176_;
 (*result)[177] = &_f_9177_;
 (*result)[178] = &_f_9178_;
 (*result)[179] = &_f_9179_;
 (*result)[180] = &_f_9180_;
 (*result)[181] = &_f_9181_;
 (*result)[182] = &_f_9182_;
 (*result)[183] = &_f_9183_;
 (*result)[184] = &_f_9184_;
 (*result)[185] = &_f_9185_;
 (*result)[186] = &_f_9186_;
 (*result)[187] = &_f_9187_;
 (*result)[188] = &_f_9188_;
 (*result)[189] = &_f_9189_;
 (*result)[190] = &_f_9190_;
 (*result)[191] = &_f_9191_;
 (*result)[192] = &_f_9192_;
 (*result)[193] = &_f_9193_;
 (*result)[194] = &_f_9194_;
 (*result)[195] = &_f_9195_;
 (*result)[196] = &_f_9196_;
 (*result)[197] = &_f_9197_;
 (*result)[198] = &_f_9198_;
 (*result)[199] = &_f_9199_;
 (*result)[200] = &_f_9200_;
 (*result)[201] = &_f_9201_;
 (*result)[202] = &_f_9202_;
 (*result)[203] = &_f_9203_;
 (*result)[204] = &_f_9204_;
 (*result)[205] = &_f_9205_;
 (*result)[206] = &_f_9206_;
 (*result)[207] = &_f_9207_;
 (*result)[208] = &_f_9208_;
 (*result)[209] = &_f_9209_;
 (*result)[210] = &_f_9210_;
 (*result)[211] = &_f_9211_;
 (*result)[212] = &_f_9212_;
 (*result)[213] = &_f_9213_;
 (*result)[214] = &_f_9214_;
 (*result)[215] = &_f_9215_;
 (*result)[216] = &_f_9216_;
 (*result)[217] = &_f_9217_;
 (*result)[218] = &_f_9218_;
 (*result)[219] = &_f_9219_;
 (*result)[220] = &_f_9220_;
 (*result)[221] = &_f_9221_;
 (*result)[222] = &_f_9222_;
 (*result)[223] = &_f_9223_;
 (*result)[224] = &_f_9224_;
 (*result)[225] = &_f_9225_;
 (*result)[226] = &_f_9226_;
 (*result)[227] = &_f_9227_;
 (*result)[228] = &_f_9228_;
 (*result)[229] = &_f_9229_;
 (*result)[230] = &_f_9230_;
 (*result)[231] = &_f_9231_;
 (*result)[232] = &_f_9232_;
 (*result)[233] = &_f_9233_;
 (*result)[234] = &_f_9234_;
 (*result)[235] = &_f_9235_;
 (*result)[236] = &_f_9236_;
 (*result)[237] = &_f_9237_;
 (*result)[238] = &_f_9238_;
 (*result)[239] = &_f_9239_;
 (*result)[240] = &_f_9240_;
 (*result)[241] = &_f_9241_;
 (*result)[242] = &_f_9242_;
 (*result)[243] = &_f_9243_;
 (*result)[244] = &_f_9244_;
 (*result)[245] = &_f_9245_;
 (*result)[246] = &_f_9246_;
 (*result)[247] = &_f_9247_;
 (*result)[248] = &_f_9248_;
 (*result)[249] = &_f_9249_;
 (*result)[250] = &_f_9250_;
 (*result)[251] = &_f_9251_;
 (*result)[252] = &_f_9252_;
 (*result)[253] = &_f_9253_;
 (*result)[254] = &_f_9254_;
 (*result)[255] = &_f_9255_;
 (*result)[256] = &_f_9256_;
 (*result)[257] = &_f_9257_;
 (*result)[258] = &_f_9258_;
 (*result)[259] = &_f_9259_;
 (*result)[260] = &_f_9260_;
 (*result)[261] = &_f_9261_;
 (*result)[262] = &_f_9262_;
 (*result)[263] = &_f_9263_;
 (*result)[264] = &_f_9264_;
 (*result)[265] = &_f_9265_;
 (*result)[266] = &_f_9266_;
 (*result)[267] = &_f_9267_;
 (*result)[268] = &_f_9268_;
 (*result)[269] = &_f_9269_;
 (*result)[270] = &_f_9270_;
 (*result)[271] = &_f_9271_;
 (*result)[272] = &_f_9272_;
 (*result)[273] = &_f_9273_;
 (*result)[274] = &_f_9274_;
 (*result)[275] = &_f_9275_;
 (*result)[276] = &_f_9276_;
 (*result)[277] = &_f_9277_;
 (*result)[278] = &_f_9278_;
 (*result)[279] = &_f_9279_;
 (*result)[280] = &_f_9280_;
 (*result)[281] = &_f_9281_;
 (*result)[282] = &_f_9282_;
 (*result)[283] = &_f_9283_;
 (*result)[284] = &_f_9284_;
 (*result)[285] = &_f_9285_;
 (*result)[286] = &_f_9286_;
 (*result)[287] = &_f_9287_;
 (*result)[288] = &_f_9288_;
 (*result)[289] = &_f_9289_;
 (*result)[290] = &_f_9290_;
 (*result)[291] = &_f_9291_;
 (*result)[292] = &_f_9292_;
 (*result)[293] = &_f_9293_;
 (*result)[294] = &_f_9294_;
 (*result)[295] = &_f_9295_;
 (*result)[296] = &_f_9296_;
 (*result)[297] = &_f_9297_;
 (*result)[298] = &_f_9298_;
 (*result)[299] = &_f_9299_;
 (*result)[300] = &_f_9300_;
 (*result)[301] = &_f_9301_;
 (*result)[302] = &_f_9302_;
 (*result)[303] = &_f_9303_;
 (*result)[304] = &_f_9304_;
 (*result)[305] = &_f_9305_;
 (*result)[306] = &_f_9306_;
 (*result)[307] = &_f_9307_;
 (*result)[308] = &_f_9308_;
 (*result)[309] = &_f_9309_;
 (*result)[310] = &_f_9310_;
 (*result)[311] = &_f_9311_;
 (*result)[312] = &_f_9312_;
 (*result)[313] = &_f_9313_;
 (*result)[314] = &_f_9314_;
 (*result)[315] = &_f_9315_;
 (*result)[316] = &_f_9316_;
 (*result)[317] = &_f_9317_;
 (*result)[318] = &_f_9318_;
 (*result)[319] = &_f_9319_;
 (*result)[320] = &_f_9320_;
 (*result)[321] = &_f_9321_;
 (*result)[322] = &_f_9322_;
 (*result)[323] = &_f_9323_;
 (*result)[324] = &_f_9324_;
 (*result)[325] = &_f_9325_;
 (*result)[326] = &_f_9326_;
 (*result)[327] = &_f_9327_;
 (*result)[328] = &_f_9328_;
 (*result)[329] = &_f_9329_;
 (*result)[330] = &_f_9330_;
 (*result)[331] = &_f_9331_;
 (*result)[332] = &_f_9332_;
 (*result)[333] = &_f_9333_;
 (*result)[334] = &_f_9334_;
 (*result)[335] = &_f_9335_;
 (*result)[336] = &_f_9336_;
 (*result)[337] = &_f_9337_;
 (*result)[338] = &_f_9338_;
 (*result)[339] = &_f_9339_;
 (*result)[340] = &_f_9340_;
 (*result)[341] = &_f_9341_;
 (*result)[342] = &_f_9342_;
 (*result)[343] = &_f_9343_;
 (*result)[344] = &_f_9344_;
 (*result)[345] = &_f_9345_;
 (*result)[346] = &_f_9346_;
 (*result)[347] = &_f_9347_;
 (*result)[348] = &_f_9348_;
 (*result)[349] = &_f_9349_;
 (*result)[350] = &_f_9350_;
 (*result)[351] = &_f_9351_;
 (*result)[352] = &_f_9352_;
 (*result)[353] = &_f_9353_;
 (*result)[354] = &_f_9354_;
 (*result)[355] = &_f_9355_;
 (*result)[356] = &_f_9356_;
 (*result)[357] = &_f_9357_;
 (*result)[358] = &_f_9358_;
 (*result)[359] = &_f_9359_;
 (*result)[360] = &_f_9360_;
 (*result)[361] = &_f_9361_;
 (*result)[362] = &_f_9362_;
 (*result)[363] = &_f_9363_;
 (*result)[364] = &_f_9364_;
 (*result)[365] = &_f_9365_;
 (*result)[366] = &_f_9366_;
 (*result)[367] = &_f_9367_;
 (*result)[368] = &_f_9368_;
 (*result)[369] = &_f_9369_;
 (*result)[370] = &_f_9370_;
 (*result)[371] = &_f_9371_;
 (*result)[372] = &_f_9372_;
 (*result)[373] = &_f_9373_;
 (*result)[374] = &_f_9374_;
 (*result)[375] = &_f_9375_;
 (*result)[376] = &_f_9376_;
 (*result)[377] = &_f_9377_;
 (*result)[378] = &_f_9378_;
 (*result)[379] = &_f_9379_;
 (*result)[380] = &_f_9380_;
 (*result)[381] = &_f_9381_;
 (*result)[382] = &_f_9382_;
 (*result)[383] = &_f_9383_;
 (*result)[384] = &_f_9384_;
 (*result)[385] = &_f_9385_;
 (*result)[386] = &_f_9386_;
 (*result)[387] = &_f_9387_;
 (*result)[388] = &_f_9388_;
 (*result)[389] = &_f_9389_;
 (*result)[390] = &_f_9390_;
 (*result)[391] = &_f_9391_;
 (*result)[392] = &_f_9392_;
 (*result)[393] = &_f_9393_;
 (*result)[394] = &_f_9394_;
 (*result)[395] = &_f_9395_;
 (*result)[396] = &_f_9396_;
 (*result)[397] = &_f_9397_;
 (*result)[398] = &_f_9398_;
 (*result)[399] = &_f_9399_;
 (*result)[400] = &_f_9400_;
 (*result)[401] = &_f_9401_;
 (*result)[402] = &_f_9402_;
 (*result)[403] = &_f_9403_;
 (*result)[404] = &_f_9404_;
 (*result)[405] = &_f_9405_;
 (*result)[406] = &_f_9406_;
 (*result)[407] = &_f_9407_;
 (*result)[408] = &_f_9408_;
 (*result)[409] = &_f_9409_;
 (*result)[410] = &_f_9410_;
 (*result)[411] = &_f_9411_;
 (*result)[412] = &_f_9412_;
 (*result)[413] = &_f_9413_;
 (*result)[414] = &_f_9414_;
 (*result)[415] = &_f_9415_;
 (*result)[416] = &_f_9416_;
 (*result)[417] = &_f_9417_;
 (*result)[418] = &_f_9418_;
 (*result)[419] = &_f_9419_;
 (*result)[420] = &_f_9420_;
 (*result)[421] = &_f_9421_;
 (*result)[422] = &_f_9422_;
 (*result)[423] = &_f_9423_;
 (*result)[424] = &_f_9424_;
 (*result)[425] = &_f_9425_;
 (*result)[426] = &_f_9426_;
 (*result)[427] = &_f_9427_;
 (*result)[428] = &_f_9428_;
 (*result)[429] = &_f_9429_;
 (*result)[430] = &_f_9430_;
 (*result)[431] = &_f_9431_;
 (*result)[432] = &_f_9432_;
 (*result)[433] = &_f_9433_;
 (*result)[434] = &_f_9434_;
 (*result)[435] = &_f_9435_;
 (*result)[436] = &_f_9436_;
 (*result)[437] = &_f_9437_;
 (*result)[438] = &_f_9438_;
 (*result)[439] = &_f_9439_;
 (*result)[440] = &_f_9440_;
 (*result)[441] = &_f_9441_;
 (*result)[442] = &_f_9442_;
 (*result)[443] = &_f_9443_;
 (*result)[444] = &_f_9444_;
 (*result)[445] = &_f_9445_;
 (*result)[446] = &_f_9446_;
 (*result)[447] = &_f_9447_;
 (*result)[448] = &_f_9448_;
 (*result)[449] = &_f_9449_;
 (*result)[450] = &_f_9450_;
 (*result)[451] = &_f_9451_;
 (*result)[452] = &_f_9452_;
 (*result)[453] = &_f_9453_;
 (*result)[454] = &_f_9454_;
 (*result)[455] = &_f_9455_;
 (*result)[456] = &_f_9456_;
 (*result)[457] = &_f_9457_;
 (*result)[458] = &_f_9458_;
 (*result)[459] = &_f_9459_;
 (*result)[460] = &_f_9460_;
 (*result)[461] = &_f_9461_;
 (*result)[462] = &_f_9462_;
 (*result)[463] = &_f_9463_;
 (*result)[464] = &_f_9464_;
 (*result)[465] = &_f_9465_;
 (*result)[466] = &_f_9466_;
 (*result)[467] = &_f_9467_;
 (*result)[468] = &_f_9468_;
 (*result)[469] = &_f_9469_;
 (*result)[470] = &_f_9470_;
 (*result)[471] = &_f_9471_;
 (*result)[472] = &_f_9472_;
 (*result)[473] = &_f_9473_;
 (*result)[474] = &_f_9474_;
 (*result)[475] = &_f_9475_;
 (*result)[476] = &_f_9476_;
 (*result)[477] = &_f_9477_;
 (*result)[478] = &_f_9478_;
 (*result)[479] = &_f_9479_;
 (*result)[480] = &_f_9480_;
 (*result)[481] = &_f_9481_;
 (*result)[482] = &_f_9482_;
 (*result)[483] = &_f_9483_;
 (*result)[484] = &_f_9484_;
 (*result)[485] = &_f_9485_;
 (*result)[486] = &_f_9486_;
 (*result)[487] = &_f_9487_;
 (*result)[488] = &_f_9488_;
 (*result)[489] = &_f_9489_;
 (*result)[490] = &_f_9490_;
 (*result)[491] = &_f_9491_;
 (*result)[492] = &_f_9492_;
 (*result)[493] = &_f_9493_;
 (*result)[494] = &_f_9494_;
 (*result)[495] = &_f_9495_;
 (*result)[496] = &_f_9496_;
 (*result)[497] = &_f_9497_;
 (*result)[498] = &_f_9498_;
 (*result)[499] = &_f_9499_;
 (*result)[500] = &_f_9500_;
 (*result)[501] = &_f_9501_;
 (*result)[502] = &_f_9502_;
 (*result)[503] = &_f_9503_;
 (*result)[504] = &_f_9504_;
 (*result)[505] = &_f_9505_;
 (*result)[506] = &_f_9506_;
 (*result)[507] = &_f_9507_;
 (*result)[508] = &_f_9508_;
 (*result)[509] = &_f_9509_;
 (*result)[510] = &_f_9510_;
 (*result)[511] = &_f_9511_;
 (*result)[512] = &_f_9512_;
 (*result)[513] = &_f_9513_;
 (*result)[514] = &_f_9514_;
 (*result)[515] = &_f_9515_;
 (*result)[516] = &_f_9516_;
 (*result)[517] = &_f_9517_;
 (*result)[518] = &_f_9518_;
 (*result)[519] = &_f_9519_;
 (*result)[520] = &_f_9520_;
 (*result)[521] = &_f_9521_;
 (*result)[522] = &_f_9522_;
 (*result)[523] = &_f_9523_;
 (*result)[524] = &_f_9524_;
 (*result)[525] = &_f_9525_;
 (*result)[526] = &_f_9526_;
 (*result)[527] = &_f_9527_;
 (*result)[528] = &_f_9528_;
 (*result)[529] = &_f_9529_;
 (*result)[530] = &_f_9530_;
 (*result)[531] = &_f_9531_;
 (*result)[532] = &_f_9532_;
 (*result)[533] = &_f_9533_;
 (*result)[534] = &_f_9534_;
 (*result)[535] = &_f_9535_;
 (*result)[536] = &_f_9536_;
 (*result)[537] = &_f_9537_;
 (*result)[538] = &_f_9538_;
 (*result)[539] = &_f_9539_;
 (*result)[540] = &_f_9540_;
 (*result)[541] = &_f_9541_;
 (*result)[542] = &_f_9542_;
 (*result)[543] = &_f_9543_;
 (*result)[544] = &_f_9544_;
 (*result)[545] = &_f_9545_;
 (*result)[546] = &_f_9546_;
 (*result)[547] = &_f_9547_;
 (*result)[548] = &_f_9548_;
 (*result)[549] = &_f_9549_;
 (*result)[550] = &_f_9550_;
 (*result)[551] = &_f_9551_;
 (*result)[552] = &_f_9552_;
 (*result)[553] = &_f_9553_;
 (*result)[554] = &_f_9554_;
 (*result)[555] = &_f_9555_;
 (*result)[556] = &_f_9556_;
 (*result)[557] = &_f_9557_;
 (*result)[558] = &_f_9558_;
 (*result)[559] = &_f_9559_;
 (*result)[560] = &_f_9560_;
 (*result)[561] = &_f_9561_;
 (*result)[562] = &_f_9562_;
 (*result)[563] = &_f_9563_;
 (*result)[564] = &_f_9564_;
 (*result)[565] = &_f_9565_;
 (*result)[566] = &_f_9566_;
 (*result)[567] = &_f_9567_;
 (*result)[568] = &_f_9568_;
 (*result)[569] = &_f_9569_;
 (*result)[570] = &_f_9570_;
 (*result)[571] = &_f_9571_;
 (*result)[572] = &_f_9572_;
 (*result)[573] = &_f_9573_;
 (*result)[574] = &_f_9574_;
 (*result)[575] = &_f_9575_;
 (*result)[576] = &_f_9576_;
 (*result)[577] = &_f_9577_;
 (*result)[578] = &_f_9578_;
 (*result)[579] = &_f_9579_;
 (*result)[580] = &_f_9580_;
 (*result)[581] = &_f_9581_;
 (*result)[582] = &_f_9582_;
 (*result)[583] = &_f_9583_;
 (*result)[584] = &_f_9584_;
 (*result)[585] = &_f_9585_;
 (*result)[586] = &_f_9586_;
 (*result)[587] = &_f_9587_;
 (*result)[588] = &_f_9588_;
 (*result)[589] = &_f_9589_;
 (*result)[590] = &_f_9590_;
 (*result)[591] = &_f_9591_;
 (*result)[592] = &_f_9592_;
 (*result)[593] = &_f_9593_;
 (*result)[594] = &_f_9594_;
 (*result)[595] = &_f_9595_;
 (*result)[596] = &_f_9596_;
 (*result)[597] = &_f_9597_;
 (*result)[598] = &_f_9598_;
 (*result)[599] = &_f_9599_;
 (*result)[600] = &_f_9600_;
 (*result)[601] = &_f_9601_;
 (*result)[602] = &_f_9602_;
 (*result)[603] = &_f_9603_;
 (*result)[604] = &_f_9604_;
 (*result)[605] = &_f_9605_;
 (*result)[606] = &_f_9606_;
 (*result)[607] = &_f_9607_;
 (*result)[608] = &_f_9608_;
 (*result)[609] = &_f_9609_;
 (*result)[610] = &_f_9610_;
 (*result)[611] = &_f_9611_;
 (*result)[612] = &_f_9612_;
 (*result)[613] = &_f_9613_;
 (*result)[614] = &_f_9614_;
 (*result)[615] = &_f_9615_;
 (*result)[616] = &_f_9616_;
 (*result)[617] = &_f_9617_;
 (*result)[618] = &_f_9618_;
 (*result)[619] = &_f_9619_;
 (*result)[620] = &_f_9620_;
 (*result)[621] = &_f_9621_;
 (*result)[622] = &_f_9622_;
 (*result)[623] = &_f_9623_;
 (*result)[624] = &_f_9624_;
 (*result)[625] = &_f_9625_;
 (*result)[626] = &_f_9626_;
 (*result)[627] = &_f_9627_;
 (*result)[628] = &_f_9628_;
 (*result)[629] = &_f_9629_;
 (*result)[630] = &_f_9630_;
 (*result)[631] = &_f_9631_;
 (*result)[632] = &_f_9632_;
 (*result)[633] = &_f_9633_;
 (*result)[634] = &_f_9634_;
 (*result)[635] = &_f_9635_;
 (*result)[636] = &_f_9636_;
 (*result)[637] = &_f_9637_;
 (*result)[638] = &_f_9638_;
 (*result)[639] = &_f_9639_;
 (*result)[640] = &_f_9640_;
 (*result)[641] = &_f_9641_;
 (*result)[642] = &_f_9642_;
 (*result)[643] = &_f_9643_;
 (*result)[644] = &_f_9644_;
 (*result)[645] = &_f_9645_;
 (*result)[646] = &_f_9646_;
 (*result)[647] = &_f_9647_;
 (*result)[648] = &_f_9648_;
 (*result)[649] = &_f_9649_;
 (*result)[650] = &_f_9650_;
 (*result)[651] = &_f_9651_;
 (*result)[652] = &_f_9652_;
 (*result)[653] = &_f_9653_;
 (*result)[654] = &_f_9654_;
 (*result)[655] = &_f_9655_;
 (*result)[656] = &_f_9656_;
 (*result)[657] = &_f_9657_;
 (*result)[658] = &_f_9658_;
 (*result)[659] = &_f_9659_;
 (*result)[660] = &_f_9660_;
 (*result)[661] = &_f_9661_;
 (*result)[662] = &_f_9662_;
 (*result)[663] = &_f_9663_;
 (*result)[664] = &_f_9664_;
 (*result)[665] = &_f_9665_;
 (*result)[666] = &_f_9666_;
 (*result)[667] = &_f_9667_;
 (*result)[668] = &_f_9668_;
 (*result)[669] = &_f_9669_;
 (*result)[670] = &_f_9670_;
 (*result)[671] = &_f_9671_;
 (*result)[672] = &_f_9672_;
 (*result)[673] = &_f_9673_;
 (*result)[674] = &_f_9674_;
 (*result)[675] = &_f_9675_;
 (*result)[676] = &_f_9676_;
 (*result)[677] = &_f_9677_;
 (*result)[678] = &_f_9678_;
 (*result)[679] = &_f_9679_;
 (*result)[680] = &_f_9680_;
 (*result)[681] = &_f_9681_;
 (*result)[682] = &_f_9682_;
 (*result)[683] = &_f_9683_;
 (*result)[684] = &_f_9684_;
 (*result)[685] = &_f_9685_;
 (*result)[686] = &_f_9686_;
 (*result)[687] = &_f_9687_;
 (*result)[688] = &_f_9688_;
 (*result)[689] = &_f_9689_;
 (*result)[690] = &_f_9690_;
 (*result)[691] = &_f_9691_;
 (*result)[692] = &_f_9692_;
 (*result)[693] = &_f_9693_;
 (*result)[694] = &_f_9694_;
 (*result)[695] = &_f_9695_;
 (*result)[696] = &_f_9696_;
 (*result)[697] = &_f_9697_;
 (*result)[698] = &_f_9698_;
 (*result)[699] = &_f_9699_;
 (*result)[700] = &_f_9700_;
 (*result)[701] = &_f_9701_;
 (*result)[702] = &_f_9702_;
 (*result)[703] = &_f_9703_;
 (*result)[704] = &_f_9704_;
 (*result)[705] = &_f_9705_;
 (*result)[706] = &_f_9706_;
 (*result)[707] = &_f_9707_;
 (*result)[708] = &_f_9708_;
 (*result)[709] = &_f_9709_;
 (*result)[710] = &_f_9710_;
 (*result)[711] = &_f_9711_;
 (*result)[712] = &_f_9712_;
 (*result)[713] = &_f_9713_;
 (*result)[714] = &_f_9714_;
 (*result)[715] = &_f_9715_;
 (*result)[716] = &_f_9716_;
 (*result)[717] = &_f_9717_;
 (*result)[718] = &_f_9718_;
 (*result)[719] = &_f_9719_;
 (*result)[720] = &_f_9720_;
 (*result)[721] = &_f_9721_;
 (*result)[722] = &_f_9722_;
 (*result)[723] = &_f_9723_;
 (*result)[724] = &_f_9724_;
 (*result)[725] = &_f_9725_;
 (*result)[726] = &_f_9726_;
 (*result)[727] = &_f_9727_;
 (*result)[728] = &_f_9728_;
 (*result)[729] = &_f_9729_;
 (*result)[730] = &_f_9730_;
 (*result)[731] = &_f_9731_;
 (*result)[732] = &_f_9732_;
 (*result)[733] = &_f_9733_;
 (*result)[734] = &_f_9734_;
 (*result)[735] = &_f_9735_;
 (*result)[736] = &_f_9736_;
 (*result)[737] = &_f_9737_;
 (*result)[738] = &_f_9738_;
 (*result)[739] = &_f_9739_;
 (*result)[740] = &_f_9740_;
 (*result)[741] = &_f_9741_;
 (*result)[742] = &_f_9742_;
 (*result)[743] = &_f_9743_;
 (*result)[744] = &_f_9744_;
 (*result)[745] = &_f_9745_;
 (*result)[746] = &_f_9746_;
 (*result)[747] = &_f_9747_;
 (*result)[748] = &_f_9748_;
 (*result)[749] = &_f_9749_;
 (*result)[750] = &_f_9750_;
 (*result)[751] = &_f_9751_;
 (*result)[752] = &_f_9752_;
 (*result)[753] = &_f_9753_;
 (*result)[754] = &_f_9754_;
 (*result)[755] = &_f_9755_;
 (*result)[756] = &_f_9756_;
 (*result)[757] = &_f_9757_;
 (*result)[758] = &_f_9758_;
 (*result)[759] = &_f_9759_;
 (*result)[760] = &_f_9760_;
 (*result)[761] = &_f_9761_;
 (*result)[762] = &_f_9762_;
 (*result)[763] = &_f_9763_;
 (*result)[764] = &_f_9764_;
 (*result)[765] = &_f_9765_;
 (*result)[766] = &_f_9766_;
 (*result)[767] = &_f_9767_;
 (*result)[768] = &_f_9768_;
 (*result)[769] = &_f_9769_;
 (*result)[770] = &_f_9770_;
 (*result)[771] = &_f_9771_;
 (*result)[772] = &_f_9772_;
 (*result)[773] = &_f_9773_;
 (*result)[774] = &_f_9774_;
 (*result)[775] = &_f_9775_;
 (*result)[776] = &_f_9776_;
 (*result)[777] = &_f_9777_;
 (*result)[778] = &_f_9778_;
 (*result)[779] = &_f_9779_;
 (*result)[780] = &_f_9780_;
 (*result)[781] = &_f_9781_;
 (*result)[782] = &_f_9782_;
 (*result)[783] = &_f_9783_;
 (*result)[784] = &_f_9784_;
 (*result)[785] = &_f_9785_;
 (*result)[786] = &_f_9786_;
 (*result)[787] = &_f_9787_;
 (*result)[788] = &_f_9788_;
 (*result)[789] = &_f_9789_;
 (*result)[790] = &_f_9790_;
 (*result)[791] = &_f_9791_;
 (*result)[792] = &_f_9792_;
 (*result)[793] = &_f_9793_;
 (*result)[794] = &_f_9794_;
 (*result)[795] = &_f_9795_;
 (*result)[796] = &_f_9796_;
 (*result)[797] = &_f_9797_;
 (*result)[798] = &_f_9798_;
 (*result)[799] = &_f_9799_;
 (*result)[800] = &_f_9800_;
 (*result)[801] = &_f_9801_;
 (*result)[802] = &_f_9802_;
 (*result)[803] = &_f_9803_;
 (*result)[804] = &_f_9804_;
 (*result)[805] = &_f_9805_;
 (*result)[806] = &_f_9806_;
 (*result)[807] = &_f_9807_;
 (*result)[808] = &_f_9808_;
 (*result)[809] = &_f_9809_;
 (*result)[810] = &_f_9810_;
 (*result)[811] = &_f_9811_;
 (*result)[812] = &_f_9812_;
 (*result)[813] = &_f_9813_;
 (*result)[814] = &_f_9814_;
 (*result)[815] = &_f_9815_;
 (*result)[816] = &_f_9816_;
 (*result)[817] = &_f_9817_;
 (*result)[818] = &_f_9818_;
 (*result)[819] = &_f_9819_;
 (*result)[820] = &_f_9820_;
 (*result)[821] = &_f_9821_;
 (*result)[822] = &_f_9822_;
 (*result)[823] = &_f_9823_;
 (*result)[824] = &_f_9824_;
 (*result)[825] = &_f_9825_;
 (*result)[826] = &_f_9826_;
 (*result)[827] = &_f_9827_;
 (*result)[828] = &_f_9828_;
 (*result)[829] = &_f_9829_;
 (*result)[830] = &_f_9830_;
 (*result)[831] = &_f_9831_;
 (*result)[832] = &_f_9832_;
 (*result)[833] = &_f_9833_;
 (*result)[834] = &_f_9834_;
 (*result)[835] = &_f_9835_;
 (*result)[836] = &_f_9836_;
 (*result)[837] = &_f_9837_;
 (*result)[838] = &_f_9838_;
 (*result)[839] = &_f_9839_;
 (*result)[840] = &_f_9840_;
 (*result)[841] = &_f_9841_;
 (*result)[842] = &_f_9842_;
 (*result)[843] = &_f_9843_;
 (*result)[844] = &_f_9844_;
 (*result)[845] = &_f_9845_;
 (*result)[846] = &_f_9846_;
 (*result)[847] = &_f_9847_;
 (*result)[848] = &_f_9848_;
 (*result)[849] = &_f_9849_;
 (*result)[850] = &_f_9850_;
 (*result)[851] = &_f_9851_;
 (*result)[852] = &_f_9852_;
 (*result)[853] = &_f_9853_;
 (*result)[854] = &_f_9854_;
 (*result)[855] = &_f_9855_;
 (*result)[856] = &_f_9856_;
 (*result)[857] = &_f_9857_;
 (*result)[858] = &_f_9858_;
 (*result)[859] = &_f_9859_;
 (*result)[860] = &_f_9860_;
 (*result)[861] = &_f_9861_;
 (*result)[862] = &_f_9862_;
 (*result)[863] = &_f_9863_;
 (*result)[864] = &_f_9864_;
 (*result)[865] = &_f_9865_;
 (*result)[866] = &_f_9866_;
 (*result)[867] = &_f_9867_;
 (*result)[868] = &_f_9868_;
 (*result)[869] = &_f_9869_;
 (*result)[870] = &_f_9870_;
 (*result)[871] = &_f_9871_;
 (*result)[872] = &_f_9872_;
 (*result)[873] = &_f_9873_;
 (*result)[874] = &_f_9874_;
 (*result)[875] = &_f_9875_;
 (*result)[876] = &_f_9876_;
 (*result)[877] = &_f_9877_;
 (*result)[878] = &_f_9878_;
 (*result)[879] = &_f_9879_;
 (*result)[880] = &_f_9880_;
 (*result)[881] = &_f_9881_;
 (*result)[882] = &_f_9882_;
 (*result)[883] = &_f_9883_;
 (*result)[884] = &_f_9884_;
 (*result)[885] = &_f_9885_;
 (*result)[886] = &_f_9886_;
 (*result)[887] = &_f_9887_;
 (*result)[888] = &_f_9888_;
 (*result)[889] = &_f_9889_;
 (*result)[890] = &_f_9890_;
 (*result)[891] = &_f_9891_;
 (*result)[892] = &_f_9892_;
 (*result)[893] = &_f_9893_;
 (*result)[894] = &_f_9894_;
 (*result)[895] = &_f_9895_;
 (*result)[896] = &_f_9896_;
 (*result)[897] = &_f_9897_;
 (*result)[898] = &_f_9898_;
 (*result)[899] = &_f_9899_;
 (*result)[900] = &_f_9900_;
 (*result)[901] = &_f_9901_;
 (*result)[902] = &_f_9902_;
 (*result)[903] = &_f_9903_;
 (*result)[904] = &_f_9904_;
 (*result)[905] = &_f_9905_;
 (*result)[906] = &_f_9906_;
 (*result)[907] = &_f_9907_;
 (*result)[908] = &_f_9908_;
 (*result)[909] = &_f_9909_;
 (*result)[910] = &_f_9910_;
 (*result)[911] = &_f_9911_;
 (*result)[912] = &_f_9912_;
 (*result)[913] = &_f_9913_;
 (*result)[914] = &_f_9914_;
 (*result)[915] = &_f_9915_;
 (*result)[916] = &_f_9916_;
 (*result)[917] = &_f_9917_;
 (*result)[918] = &_f_9918_;
 (*result)[919] = &_f_9919_;
 (*result)[920] = &_f_9920_;
 (*result)[921] = &_f_9921_;
 (*result)[922] = &_f_9922_;
 (*result)[923] = &_f_9923_;
 (*result)[924] = &_f_9924_;
 (*result)[925] = &_f_9925_;
 (*result)[926] = &_f_9926_;
 (*result)[927] = &_f_9927_;
 (*result)[928] = &_f_9928_;
 (*result)[929] = &_f_9929_;
 (*result)[930] = &_f_9930_;
 (*result)[931] = &_f_9931_;
 (*result)[932] = &_f_9932_;
 (*result)[933] = &_f_9933_;
 (*result)[934] = &_f_9934_;
 (*result)[935] = &_f_9935_;
 (*result)[936] = &_f_9936_;
 (*result)[937] = &_f_9937_;
 (*result)[938] = &_f_9938_;
 (*result)[939] = &_f_9939_;
 (*result)[940] = &_f_9940_;
 (*result)[941] = &_f_9941_;
 (*result)[942] = &_f_9942_;
 (*result)[943] = &_f_9943_;
 (*result)[944] = &_f_9944_;
 (*result)[945] = &_f_9945_;
 (*result)[946] = &_f_9946_;
 (*result)[947] = &_f_9947_;
 (*result)[948] = &_f_9948_;
 (*result)[949] = &_f_9949_;
 (*result)[950] = &_f_9950_;
 (*result)[951] = &_f_9951_;
 (*result)[952] = &_f_9952_;
 (*result)[953] = &_f_9953_;
 (*result)[954] = &_f_9954_;
 (*result)[955] = &_f_9955_;
 (*result)[956] = &_f_9956_;
 (*result)[957] = &_f_9957_;
 (*result)[958] = &_f_9958_;
 (*result)[959] = &_f_9959_;
 (*result)[960] = &_f_9960_;
 (*result)[961] = &_f_9961_;
 (*result)[962] = &_f_9962_;
 (*result)[963] = &_f_9963_;
 (*result)[964] = &_f_9964_;
 (*result)[965] = &_f_9965_;
 (*result)[966] = &_f_9966_;
 (*result)[967] = &_f_9967_;
 (*result)[968] = &_f_9968_;
 (*result)[969] = &_f_9969_;
 (*result)[970] = &_f_9970_;
 (*result)[971] = &_f_9971_;
 (*result)[972] = &_f_9972_;
 (*result)[973] = &_f_9973_;
 (*result)[974] = &_f_9974_;
 (*result)[975] = &_f_9975_;
 (*result)[976] = &_f_9976_;
 (*result)[977] = &_f_9977_;
 (*result)[978] = &_f_9978_;
 (*result)[979] = &_f_9979_;
 (*result)[980] = &_f_9980_;
 (*result)[981] = &_f_9981_;
 (*result)[982] = &_f_9982_;
 (*result)[983] = &_f_9983_;
 (*result)[984] = &_f_9984_;
 (*result)[985] = &_f_9985_;
 (*result)[986] = &_f_9986_;
 (*result)[987] = &_f_9987_;
 (*result)[988] = &_f_9988_;
 (*result)[989] = &_f_9989_;
 (*result)[990] = &_f_9990_;
 (*result)[991] = &_f_9991_;
 (*result)[992] = &_f_9992_;
 (*result)[993] = &_f_9993_;
 (*result)[994] = &_f_9994_;
 (*result)[995] = &_f_9995_;
 (*result)[996] = &_f_9996_;
 (*result)[997] = &_f_9997_;
 (*result)[998] = &_f_9998_;
 (*result)[999] = &_f_9999_;
}

void run_s0_3_re9(u4 code, minimal_fn_s0_re9_type fn, void*& retv, n8 a1, n8 a2, n8 a3)
{
 code %= 10000;
 static s0_3_re9_dispatch_array* dispatch_array = init_s0_3_re9_dispatch_array();
 run_s0_3_re9_type f = (*dispatch_array)[code];
 f(retv, a1, a2, a3, fn);
}

#endif //def FULL_INCLUDE
