


#ifndef SEEN_DEFS_S01_3_RE8
#define SEEN_DEFS_S01_3_RE8

typedef n8(*minimal_fn_s0_re8_type)();
typedef n8(_min_::*minimal_fn_s0_re8_type)();
typedef void(*run_s01_3_re8_type)(n8& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re8_type fn,
  minimal_fn_s1_re8_type sfn);
typedef run_s01_3_re8_type s01_3_re8_dispatch_array [1000];

#endif //  SEEN_DEFS_S01_3_RE8

#ifdef FULL_INCLUDE

#include "fn-array-s01_3_re8.cpp"

s01_3_re8_dispatch_array* init_s01_3_re8_dispatch_array()
{
 s01_3_re8_dispatch_array* result = (s01_3_re8_dispatch_array*) new run_s01_3_re8_type[1000];
 
 (*result)[0] = &_f_8000_;
 (*result)[1] = &_f_8001_;
 (*result)[2] = &_f_8002_;
 (*result)[3] = &_f_8003_;
 (*result)[4] = &_f_8004_;
 (*result)[5] = &_f_8005_;
 (*result)[6] = &_f_8006_;
 (*result)[7] = &_f_8007_;
 (*result)[8] = &_f_8008_;
 (*result)[9] = &_f_8009_;
 (*result)[10] = &_f_8010_;
 (*result)[11] = &_f_8011_;
 (*result)[12] = &_f_8012_;
 (*result)[13] = &_f_8013_;
 (*result)[14] = &_f_8014_;
 (*result)[15] = &_f_8015_;
 (*result)[16] = &_f_8016_;
 (*result)[17] = &_f_8017_;
 (*result)[18] = &_f_8018_;
 (*result)[19] = &_f_8019_;
 (*result)[20] = &_f_8020_;
 (*result)[21] = &_f_8021_;
 (*result)[22] = &_f_8022_;
 (*result)[23] = &_f_8023_;
 (*result)[24] = &_f_8024_;
 (*result)[25] = &_f_8025_;
 (*result)[26] = &_f_8026_;
 (*result)[27] = &_f_8027_;
 (*result)[28] = &_f_8028_;
 (*result)[29] = &_f_8029_;
 (*result)[30] = &_f_8030_;
 (*result)[31] = &_f_8031_;
 (*result)[32] = &_f_8032_;
 (*result)[33] = &_f_8033_;
 (*result)[34] = &_f_8034_;
 (*result)[35] = &_f_8035_;
 (*result)[36] = &_f_8036_;
 (*result)[37] = &_f_8037_;
 (*result)[38] = &_f_8038_;
 (*result)[39] = &_f_8039_;
 (*result)[40] = &_f_8040_;
 (*result)[41] = &_f_8041_;
 (*result)[42] = &_f_8042_;
 (*result)[43] = &_f_8043_;
 (*result)[44] = &_f_8044_;
 (*result)[45] = &_f_8045_;
 (*result)[46] = &_f_8046_;
 (*result)[47] = &_f_8047_;
 (*result)[48] = &_f_8048_;
 (*result)[49] = &_f_8049_;
 (*result)[50] = &_f_8050_;
 (*result)[51] = &_f_8051_;
 (*result)[52] = &_f_8052_;
 (*result)[53] = &_f_8053_;
 (*result)[54] = &_f_8054_;
 (*result)[55] = &_f_8055_;
 (*result)[56] = &_f_8056_;
 (*result)[57] = &_f_8057_;
 (*result)[58] = &_f_8058_;
 (*result)[59] = &_f_8059_;
 (*result)[60] = &_f_8060_;
 (*result)[61] = &_f_8061_;
 (*result)[62] = &_f_8062_;
 (*result)[63] = &_f_8063_;
 (*result)[64] = &_f_8064_;
 (*result)[65] = &_f_8065_;
 (*result)[66] = &_f_8066_;
 (*result)[67] = &_f_8067_;
 (*result)[68] = &_f_8068_;
 (*result)[69] = &_f_8069_;
 (*result)[70] = &_f_8070_;
 (*result)[71] = &_f_8071_;
 (*result)[72] = &_f_8072_;
 (*result)[73] = &_f_8073_;
 (*result)[74] = &_f_8074_;
 (*result)[75] = &_f_8075_;
 (*result)[76] = &_f_8076_;
 (*result)[77] = &_f_8077_;
 (*result)[78] = &_f_8078_;
 (*result)[79] = &_f_8079_;
 (*result)[80] = &_f_8080_;
 (*result)[81] = &_f_8081_;
 (*result)[82] = &_f_8082_;
 (*result)[83] = &_f_8083_;
 (*result)[84] = &_f_8084_;
 (*result)[85] = &_f_8085_;
 (*result)[86] = &_f_8086_;
 (*result)[87] = &_f_8087_;
 (*result)[88] = &_f_8088_;
 (*result)[89] = &_f_8089_;
 (*result)[90] = &_f_8090_;
 (*result)[91] = &_f_8091_;
 (*result)[92] = &_f_8092_;
 (*result)[93] = &_f_8093_;
 (*result)[94] = &_f_8094_;
 (*result)[95] = &_f_8095_;
 (*result)[96] = &_f_8096_;
 (*result)[97] = &_f_8097_;
 (*result)[98] = &_f_8098_;
 (*result)[99] = &_f_8099_;
 (*result)[100] = &_f_8100_;
 (*result)[101] = &_f_8101_;
 (*result)[102] = &_f_8102_;
 (*result)[103] = &_f_8103_;
 (*result)[104] = &_f_8104_;
 (*result)[105] = &_f_8105_;
 (*result)[106] = &_f_8106_;
 (*result)[107] = &_f_8107_;
 (*result)[108] = &_f_8108_;
 (*result)[109] = &_f_8109_;
 (*result)[110] = &_f_8110_;
 (*result)[111] = &_f_8111_;
 (*result)[112] = &_f_8112_;
 (*result)[113] = &_f_8113_;
 (*result)[114] = &_f_8114_;
 (*result)[115] = &_f_8115_;
 (*result)[116] = &_f_8116_;
 (*result)[117] = &_f_8117_;
 (*result)[118] = &_f_8118_;
 (*result)[119] = &_f_8119_;
 (*result)[120] = &_f_8120_;
 (*result)[121] = &_f_8121_;
 (*result)[122] = &_f_8122_;
 (*result)[123] = &_f_8123_;
 (*result)[124] = &_f_8124_;
 (*result)[125] = &_f_8125_;
 (*result)[126] = &_f_8126_;
 (*result)[127] = &_f_8127_;
 (*result)[128] = &_f_8128_;
 (*result)[129] = &_f_8129_;
 (*result)[130] = &_f_8130_;
 (*result)[131] = &_f_8131_;
 (*result)[132] = &_f_8132_;
 (*result)[133] = &_f_8133_;
 (*result)[134] = &_f_8134_;
 (*result)[135] = &_f_8135_;
 (*result)[136] = &_f_8136_;
 (*result)[137] = &_f_8137_;
 (*result)[138] = &_f_8138_;
 (*result)[139] = &_f_8139_;
 (*result)[140] = &_f_8140_;
 (*result)[141] = &_f_8141_;
 (*result)[142] = &_f_8142_;
 (*result)[143] = &_f_8143_;
 (*result)[144] = &_f_8144_;
 (*result)[145] = &_f_8145_;
 (*result)[146] = &_f_8146_;
 (*result)[147] = &_f_8147_;
 (*result)[148] = &_f_8148_;
 (*result)[149] = &_f_8149_;
 (*result)[150] = &_f_8150_;
 (*result)[151] = &_f_8151_;
 (*result)[152] = &_f_8152_;
 (*result)[153] = &_f_8153_;
 (*result)[154] = &_f_8154_;
 (*result)[155] = &_f_8155_;
 (*result)[156] = &_f_8156_;
 (*result)[157] = &_f_8157_;
 (*result)[158] = &_f_8158_;
 (*result)[159] = &_f_8159_;
 (*result)[160] = &_f_8160_;
 (*result)[161] = &_f_8161_;
 (*result)[162] = &_f_8162_;
 (*result)[163] = &_f_8163_;
 (*result)[164] = &_f_8164_;
 (*result)[165] = &_f_8165_;
 (*result)[166] = &_f_8166_;
 (*result)[167] = &_f_8167_;
 (*result)[168] = &_f_8168_;
 (*result)[169] = &_f_8169_;
 (*result)[170] = &_f_8170_;
 (*result)[171] = &_f_8171_;
 (*result)[172] = &_f_8172_;
 (*result)[173] = &_f_8173_;
 (*result)[174] = &_f_8174_;
 (*result)[175] = &_f_8175_;
 (*result)[176] = &_f_8176_;
 (*result)[177] = &_f_8177_;
 (*result)[178] = &_f_8178_;
 (*result)[179] = &_f_8179_;
 (*result)[180] = &_f_8180_;
 (*result)[181] = &_f_8181_;
 (*result)[182] = &_f_8182_;
 (*result)[183] = &_f_8183_;
 (*result)[184] = &_f_8184_;
 (*result)[185] = &_f_8185_;
 (*result)[186] = &_f_8186_;
 (*result)[187] = &_f_8187_;
 (*result)[188] = &_f_8188_;
 (*result)[189] = &_f_8189_;
 (*result)[190] = &_f_8190_;
 (*result)[191] = &_f_8191_;
 (*result)[192] = &_f_8192_;
 (*result)[193] = &_f_8193_;
 (*result)[194] = &_f_8194_;
 (*result)[195] = &_f_8195_;
 (*result)[196] = &_f_8196_;
 (*result)[197] = &_f_8197_;
 (*result)[198] = &_f_8198_;
 (*result)[199] = &_f_8199_;
 (*result)[200] = &_f_8200_;
 (*result)[201] = &_f_8201_;
 (*result)[202] = &_f_8202_;
 (*result)[203] = &_f_8203_;
 (*result)[204] = &_f_8204_;
 (*result)[205] = &_f_8205_;
 (*result)[206] = &_f_8206_;
 (*result)[207] = &_f_8207_;
 (*result)[208] = &_f_8208_;
 (*result)[209] = &_f_8209_;
 (*result)[210] = &_f_8210_;
 (*result)[211] = &_f_8211_;
 (*result)[212] = &_f_8212_;
 (*result)[213] = &_f_8213_;
 (*result)[214] = &_f_8214_;
 (*result)[215] = &_f_8215_;
 (*result)[216] = &_f_8216_;
 (*result)[217] = &_f_8217_;
 (*result)[218] = &_f_8218_;
 (*result)[219] = &_f_8219_;
 (*result)[220] = &_f_8220_;
 (*result)[221] = &_f_8221_;
 (*result)[222] = &_f_8222_;
 (*result)[223] = &_f_8223_;
 (*result)[224] = &_f_8224_;
 (*result)[225] = &_f_8225_;
 (*result)[226] = &_f_8226_;
 (*result)[227] = &_f_8227_;
 (*result)[228] = &_f_8228_;
 (*result)[229] = &_f_8229_;
 (*result)[230] = &_f_8230_;
 (*result)[231] = &_f_8231_;
 (*result)[232] = &_f_8232_;
 (*result)[233] = &_f_8233_;
 (*result)[234] = &_f_8234_;
 (*result)[235] = &_f_8235_;
 (*result)[236] = &_f_8236_;
 (*result)[237] = &_f_8237_;
 (*result)[238] = &_f_8238_;
 (*result)[239] = &_f_8239_;
 (*result)[240] = &_f_8240_;
 (*result)[241] = &_f_8241_;
 (*result)[242] = &_f_8242_;
 (*result)[243] = &_f_8243_;
 (*result)[244] = &_f_8244_;
 (*result)[245] = &_f_8245_;
 (*result)[246] = &_f_8246_;
 (*result)[247] = &_f_8247_;
 (*result)[248] = &_f_8248_;
 (*result)[249] = &_f_8249_;
 (*result)[250] = &_f_8250_;
 (*result)[251] = &_f_8251_;
 (*result)[252] = &_f_8252_;
 (*result)[253] = &_f_8253_;
 (*result)[254] = &_f_8254_;
 (*result)[255] = &_f_8255_;
 (*result)[256] = &_f_8256_;
 (*result)[257] = &_f_8257_;
 (*result)[258] = &_f_8258_;
 (*result)[259] = &_f_8259_;
 (*result)[260] = &_f_8260_;
 (*result)[261] = &_f_8261_;
 (*result)[262] = &_f_8262_;
 (*result)[263] = &_f_8263_;
 (*result)[264] = &_f_8264_;
 (*result)[265] = &_f_8265_;
 (*result)[266] = &_f_8266_;
 (*result)[267] = &_f_8267_;
 (*result)[268] = &_f_8268_;
 (*result)[269] = &_f_8269_;
 (*result)[270] = &_f_8270_;
 (*result)[271] = &_f_8271_;
 (*result)[272] = &_f_8272_;
 (*result)[273] = &_f_8273_;
 (*result)[274] = &_f_8274_;
 (*result)[275] = &_f_8275_;
 (*result)[276] = &_f_8276_;
 (*result)[277] = &_f_8277_;
 (*result)[278] = &_f_8278_;
 (*result)[279] = &_f_8279_;
 (*result)[280] = &_f_8280_;
 (*result)[281] = &_f_8281_;
 (*result)[282] = &_f_8282_;
 (*result)[283] = &_f_8283_;
 (*result)[284] = &_f_8284_;
 (*result)[285] = &_f_8285_;
 (*result)[286] = &_f_8286_;
 (*result)[287] = &_f_8287_;
 (*result)[288] = &_f_8288_;
 (*result)[289] = &_f_8289_;
 (*result)[290] = &_f_8290_;
 (*result)[291] = &_f_8291_;
 (*result)[292] = &_f_8292_;
 (*result)[293] = &_f_8293_;
 (*result)[294] = &_f_8294_;
 (*result)[295] = &_f_8295_;
 (*result)[296] = &_f_8296_;
 (*result)[297] = &_f_8297_;
 (*result)[298] = &_f_8298_;
 (*result)[299] = &_f_8299_;
 (*result)[300] = &_f_8300_;
 (*result)[301] = &_f_8301_;
 (*result)[302] = &_f_8302_;
 (*result)[303] = &_f_8303_;
 (*result)[304] = &_f_8304_;
 (*result)[305] = &_f_8305_;
 (*result)[306] = &_f_8306_;
 (*result)[307] = &_f_8307_;
 (*result)[308] = &_f_8308_;
 (*result)[309] = &_f_8309_;
 (*result)[310] = &_f_8310_;
 (*result)[311] = &_f_8311_;
 (*result)[312] = &_f_8312_;
 (*result)[313] = &_f_8313_;
 (*result)[314] = &_f_8314_;
 (*result)[315] = &_f_8315_;
 (*result)[316] = &_f_8316_;
 (*result)[317] = &_f_8317_;
 (*result)[318] = &_f_8318_;
 (*result)[319] = &_f_8319_;
 (*result)[320] = &_f_8320_;
 (*result)[321] = &_f_8321_;
 (*result)[322] = &_f_8322_;
 (*result)[323] = &_f_8323_;
 (*result)[324] = &_f_8324_;
 (*result)[325] = &_f_8325_;
 (*result)[326] = &_f_8326_;
 (*result)[327] = &_f_8327_;
 (*result)[328] = &_f_8328_;
 (*result)[329] = &_f_8329_;
 (*result)[330] = &_f_8330_;
 (*result)[331] = &_f_8331_;
 (*result)[332] = &_f_8332_;
 (*result)[333] = &_f_8333_;
 (*result)[334] = &_f_8334_;
 (*result)[335] = &_f_8335_;
 (*result)[336] = &_f_8336_;
 (*result)[337] = &_f_8337_;
 (*result)[338] = &_f_8338_;
 (*result)[339] = &_f_8339_;
 (*result)[340] = &_f_8340_;
 (*result)[341] = &_f_8341_;
 (*result)[342] = &_f_8342_;
 (*result)[343] = &_f_8343_;
 (*result)[344] = &_f_8344_;
 (*result)[345] = &_f_8345_;
 (*result)[346] = &_f_8346_;
 (*result)[347] = &_f_8347_;
 (*result)[348] = &_f_8348_;
 (*result)[349] = &_f_8349_;
 (*result)[350] = &_f_8350_;
 (*result)[351] = &_f_8351_;
 (*result)[352] = &_f_8352_;
 (*result)[353] = &_f_8353_;
 (*result)[354] = &_f_8354_;
 (*result)[355] = &_f_8355_;
 (*result)[356] = &_f_8356_;
 (*result)[357] = &_f_8357_;
 (*result)[358] = &_f_8358_;
 (*result)[359] = &_f_8359_;
 (*result)[360] = &_f_8360_;
 (*result)[361] = &_f_8361_;
 (*result)[362] = &_f_8362_;
 (*result)[363] = &_f_8363_;
 (*result)[364] = &_f_8364_;
 (*result)[365] = &_f_8365_;
 (*result)[366] = &_f_8366_;
 (*result)[367] = &_f_8367_;
 (*result)[368] = &_f_8368_;
 (*result)[369] = &_f_8369_;
 (*result)[370] = &_f_8370_;
 (*result)[371] = &_f_8371_;
 (*result)[372] = &_f_8372_;
 (*result)[373] = &_f_8373_;
 (*result)[374] = &_f_8374_;
 (*result)[375] = &_f_8375_;
 (*result)[376] = &_f_8376_;
 (*result)[377] = &_f_8377_;
 (*result)[378] = &_f_8378_;
 (*result)[379] = &_f_8379_;
 (*result)[380] = &_f_8380_;
 (*result)[381] = &_f_8381_;
 (*result)[382] = &_f_8382_;
 (*result)[383] = &_f_8383_;
 (*result)[384] = &_f_8384_;
 (*result)[385] = &_f_8385_;
 (*result)[386] = &_f_8386_;
 (*result)[387] = &_f_8387_;
 (*result)[388] = &_f_8388_;
 (*result)[389] = &_f_8389_;
 (*result)[390] = &_f_8390_;
 (*result)[391] = &_f_8391_;
 (*result)[392] = &_f_8392_;
 (*result)[393] = &_f_8393_;
 (*result)[394] = &_f_8394_;
 (*result)[395] = &_f_8395_;
 (*result)[396] = &_f_8396_;
 (*result)[397] = &_f_8397_;
 (*result)[398] = &_f_8398_;
 (*result)[399] = &_f_8399_;
 (*result)[400] = &_f_8400_;
 (*result)[401] = &_f_8401_;
 (*result)[402] = &_f_8402_;
 (*result)[403] = &_f_8403_;
 (*result)[404] = &_f_8404_;
 (*result)[405] = &_f_8405_;
 (*result)[406] = &_f_8406_;
 (*result)[407] = &_f_8407_;
 (*result)[408] = &_f_8408_;
 (*result)[409] = &_f_8409_;
 (*result)[410] = &_f_8410_;
 (*result)[411] = &_f_8411_;
 (*result)[412] = &_f_8412_;
 (*result)[413] = &_f_8413_;
 (*result)[414] = &_f_8414_;
 (*result)[415] = &_f_8415_;
 (*result)[416] = &_f_8416_;
 (*result)[417] = &_f_8417_;
 (*result)[418] = &_f_8418_;
 (*result)[419] = &_f_8419_;
 (*result)[420] = &_f_8420_;
 (*result)[421] = &_f_8421_;
 (*result)[422] = &_f_8422_;
 (*result)[423] = &_f_8423_;
 (*result)[424] = &_f_8424_;
 (*result)[425] = &_f_8425_;
 (*result)[426] = &_f_8426_;
 (*result)[427] = &_f_8427_;
 (*result)[428] = &_f_8428_;
 (*result)[429] = &_f_8429_;
 (*result)[430] = &_f_8430_;
 (*result)[431] = &_f_8431_;
 (*result)[432] = &_f_8432_;
 (*result)[433] = &_f_8433_;
 (*result)[434] = &_f_8434_;
 (*result)[435] = &_f_8435_;
 (*result)[436] = &_f_8436_;
 (*result)[437] = &_f_8437_;
 (*result)[438] = &_f_8438_;
 (*result)[439] = &_f_8439_;
 (*result)[440] = &_f_8440_;
 (*result)[441] = &_f_8441_;
 (*result)[442] = &_f_8442_;
 (*result)[443] = &_f_8443_;
 (*result)[444] = &_f_8444_;
 (*result)[445] = &_f_8445_;
 (*result)[446] = &_f_8446_;
 (*result)[447] = &_f_8447_;
 (*result)[448] = &_f_8448_;
 (*result)[449] = &_f_8449_;
 (*result)[450] = &_f_8450_;
 (*result)[451] = &_f_8451_;
 (*result)[452] = &_f_8452_;
 (*result)[453] = &_f_8453_;
 (*result)[454] = &_f_8454_;
 (*result)[455] = &_f_8455_;
 (*result)[456] = &_f_8456_;
 (*result)[457] = &_f_8457_;
 (*result)[458] = &_f_8458_;
 (*result)[459] = &_f_8459_;
 (*result)[460] = &_f_8460_;
 (*result)[461] = &_f_8461_;
 (*result)[462] = &_f_8462_;
 (*result)[463] = &_f_8463_;
 (*result)[464] = &_f_8464_;
 (*result)[465] = &_f_8465_;
 (*result)[466] = &_f_8466_;
 (*result)[467] = &_f_8467_;
 (*result)[468] = &_f_8468_;
 (*result)[469] = &_f_8469_;
 (*result)[470] = &_f_8470_;
 (*result)[471] = &_f_8471_;
 (*result)[472] = &_f_8472_;
 (*result)[473] = &_f_8473_;
 (*result)[474] = &_f_8474_;
 (*result)[475] = &_f_8475_;
 (*result)[476] = &_f_8476_;
 (*result)[477] = &_f_8477_;
 (*result)[478] = &_f_8478_;
 (*result)[479] = &_f_8479_;
 (*result)[480] = &_f_8480_;
 (*result)[481] = &_f_8481_;
 (*result)[482] = &_f_8482_;
 (*result)[483] = &_f_8483_;
 (*result)[484] = &_f_8484_;
 (*result)[485] = &_f_8485_;
 (*result)[486] = &_f_8486_;
 (*result)[487] = &_f_8487_;
 (*result)[488] = &_f_8488_;
 (*result)[489] = &_f_8489_;
 (*result)[490] = &_f_8490_;
 (*result)[491] = &_f_8491_;
 (*result)[492] = &_f_8492_;
 (*result)[493] = &_f_8493_;
 (*result)[494] = &_f_8494_;
 (*result)[495] = &_f_8495_;
 (*result)[496] = &_f_8496_;
 (*result)[497] = &_f_8497_;
 (*result)[498] = &_f_8498_;
 (*result)[499] = &_f_8499_;
 (*result)[500] = &_f_8500_;
 (*result)[501] = &_f_8501_;
 (*result)[502] = &_f_8502_;
 (*result)[503] = &_f_8503_;
 (*result)[504] = &_f_8504_;
 (*result)[505] = &_f_8505_;
 (*result)[506] = &_f_8506_;
 (*result)[507] = &_f_8507_;
 (*result)[508] = &_f_8508_;
 (*result)[509] = &_f_8509_;
 (*result)[510] = &_f_8510_;
 (*result)[511] = &_f_8511_;
 (*result)[512] = &_f_8512_;
 (*result)[513] = &_f_8513_;
 (*result)[514] = &_f_8514_;
 (*result)[515] = &_f_8515_;
 (*result)[516] = &_f_8516_;
 (*result)[517] = &_f_8517_;
 (*result)[518] = &_f_8518_;
 (*result)[519] = &_f_8519_;
 (*result)[520] = &_f_8520_;
 (*result)[521] = &_f_8521_;
 (*result)[522] = &_f_8522_;
 (*result)[523] = &_f_8523_;
 (*result)[524] = &_f_8524_;
 (*result)[525] = &_f_8525_;
 (*result)[526] = &_f_8526_;
 (*result)[527] = &_f_8527_;
 (*result)[528] = &_f_8528_;
 (*result)[529] = &_f_8529_;
 (*result)[530] = &_f_8530_;
 (*result)[531] = &_f_8531_;
 (*result)[532] = &_f_8532_;
 (*result)[533] = &_f_8533_;
 (*result)[534] = &_f_8534_;
 (*result)[535] = &_f_8535_;
 (*result)[536] = &_f_8536_;
 (*result)[537] = &_f_8537_;
 (*result)[538] = &_f_8538_;
 (*result)[539] = &_f_8539_;
 (*result)[540] = &_f_8540_;
 (*result)[541] = &_f_8541_;
 (*result)[542] = &_f_8542_;
 (*result)[543] = &_f_8543_;
 (*result)[544] = &_f_8544_;
 (*result)[545] = &_f_8545_;
 (*result)[546] = &_f_8546_;
 (*result)[547] = &_f_8547_;
 (*result)[548] = &_f_8548_;
 (*result)[549] = &_f_8549_;
 (*result)[550] = &_f_8550_;
 (*result)[551] = &_f_8551_;
 (*result)[552] = &_f_8552_;
 (*result)[553] = &_f_8553_;
 (*result)[554] = &_f_8554_;
 (*result)[555] = &_f_8555_;
 (*result)[556] = &_f_8556_;
 (*result)[557] = &_f_8557_;
 (*result)[558] = &_f_8558_;
 (*result)[559] = &_f_8559_;
 (*result)[560] = &_f_8560_;
 (*result)[561] = &_f_8561_;
 (*result)[562] = &_f_8562_;
 (*result)[563] = &_f_8563_;
 (*result)[564] = &_f_8564_;
 (*result)[565] = &_f_8565_;
 (*result)[566] = &_f_8566_;
 (*result)[567] = &_f_8567_;
 (*result)[568] = &_f_8568_;
 (*result)[569] = &_f_8569_;
 (*result)[570] = &_f_8570_;
 (*result)[571] = &_f_8571_;
 (*result)[572] = &_f_8572_;
 (*result)[573] = &_f_8573_;
 (*result)[574] = &_f_8574_;
 (*result)[575] = &_f_8575_;
 (*result)[576] = &_f_8576_;
 (*result)[577] = &_f_8577_;
 (*result)[578] = &_f_8578_;
 (*result)[579] = &_f_8579_;
 (*result)[580] = &_f_8580_;
 (*result)[581] = &_f_8581_;
 (*result)[582] = &_f_8582_;
 (*result)[583] = &_f_8583_;
 (*result)[584] = &_f_8584_;
 (*result)[585] = &_f_8585_;
 (*result)[586] = &_f_8586_;
 (*result)[587] = &_f_8587_;
 (*result)[588] = &_f_8588_;
 (*result)[589] = &_f_8589_;
 (*result)[590] = &_f_8590_;
 (*result)[591] = &_f_8591_;
 (*result)[592] = &_f_8592_;
 (*result)[593] = &_f_8593_;
 (*result)[594] = &_f_8594_;
 (*result)[595] = &_f_8595_;
 (*result)[596] = &_f_8596_;
 (*result)[597] = &_f_8597_;
 (*result)[598] = &_f_8598_;
 (*result)[599] = &_f_8599_;
 (*result)[600] = &_f_8600_;
 (*result)[601] = &_f_8601_;
 (*result)[602] = &_f_8602_;
 (*result)[603] = &_f_8603_;
 (*result)[604] = &_f_8604_;
 (*result)[605] = &_f_8605_;
 (*result)[606] = &_f_8606_;
 (*result)[607] = &_f_8607_;
 (*result)[608] = &_f_8608_;
 (*result)[609] = &_f_8609_;
 (*result)[610] = &_f_8610_;
 (*result)[611] = &_f_8611_;
 (*result)[612] = &_f_8612_;
 (*result)[613] = &_f_8613_;
 (*result)[614] = &_f_8614_;
 (*result)[615] = &_f_8615_;
 (*result)[616] = &_f_8616_;
 (*result)[617] = &_f_8617_;
 (*result)[618] = &_f_8618_;
 (*result)[619] = &_f_8619_;
 (*result)[620] = &_f_8620_;
 (*result)[621] = &_f_8621_;
 (*result)[622] = &_f_8622_;
 (*result)[623] = &_f_8623_;
 (*result)[624] = &_f_8624_;
 (*result)[625] = &_f_8625_;
 (*result)[626] = &_f_8626_;
 (*result)[627] = &_f_8627_;
 (*result)[628] = &_f_8628_;
 (*result)[629] = &_f_8629_;
 (*result)[630] = &_f_8630_;
 (*result)[631] = &_f_8631_;
 (*result)[632] = &_f_8632_;
 (*result)[633] = &_f_8633_;
 (*result)[634] = &_f_8634_;
 (*result)[635] = &_f_8635_;
 (*result)[636] = &_f_8636_;
 (*result)[637] = &_f_8637_;
 (*result)[638] = &_f_8638_;
 (*result)[639] = &_f_8639_;
 (*result)[640] = &_f_8640_;
 (*result)[641] = &_f_8641_;
 (*result)[642] = &_f_8642_;
 (*result)[643] = &_f_8643_;
 (*result)[644] = &_f_8644_;
 (*result)[645] = &_f_8645_;
 (*result)[646] = &_f_8646_;
 (*result)[647] = &_f_8647_;
 (*result)[648] = &_f_8648_;
 (*result)[649] = &_f_8649_;
 (*result)[650] = &_f_8650_;
 (*result)[651] = &_f_8651_;
 (*result)[652] = &_f_8652_;
 (*result)[653] = &_f_8653_;
 (*result)[654] = &_f_8654_;
 (*result)[655] = &_f_8655_;
 (*result)[656] = &_f_8656_;
 (*result)[657] = &_f_8657_;
 (*result)[658] = &_f_8658_;
 (*result)[659] = &_f_8659_;
 (*result)[660] = &_f_8660_;
 (*result)[661] = &_f_8661_;
 (*result)[662] = &_f_8662_;
 (*result)[663] = &_f_8663_;
 (*result)[664] = &_f_8664_;
 (*result)[665] = &_f_8665_;
 (*result)[666] = &_f_8666_;
 (*result)[667] = &_f_8667_;
 (*result)[668] = &_f_8668_;
 (*result)[669] = &_f_8669_;
 (*result)[670] = &_f_8670_;
 (*result)[671] = &_f_8671_;
 (*result)[672] = &_f_8672_;
 (*result)[673] = &_f_8673_;
 (*result)[674] = &_f_8674_;
 (*result)[675] = &_f_8675_;
 (*result)[676] = &_f_8676_;
 (*result)[677] = &_f_8677_;
 (*result)[678] = &_f_8678_;
 (*result)[679] = &_f_8679_;
 (*result)[680] = &_f_8680_;
 (*result)[681] = &_f_8681_;
 (*result)[682] = &_f_8682_;
 (*result)[683] = &_f_8683_;
 (*result)[684] = &_f_8684_;
 (*result)[685] = &_f_8685_;
 (*result)[686] = &_f_8686_;
 (*result)[687] = &_f_8687_;
 (*result)[688] = &_f_8688_;
 (*result)[689] = &_f_8689_;
 (*result)[690] = &_f_8690_;
 (*result)[691] = &_f_8691_;
 (*result)[692] = &_f_8692_;
 (*result)[693] = &_f_8693_;
 (*result)[694] = &_f_8694_;
 (*result)[695] = &_f_8695_;
 (*result)[696] = &_f_8696_;
 (*result)[697] = &_f_8697_;
 (*result)[698] = &_f_8698_;
 (*result)[699] = &_f_8699_;
 (*result)[700] = &_f_8700_;
 (*result)[701] = &_f_8701_;
 (*result)[702] = &_f_8702_;
 (*result)[703] = &_f_8703_;
 (*result)[704] = &_f_8704_;
 (*result)[705] = &_f_8705_;
 (*result)[706] = &_f_8706_;
 (*result)[707] = &_f_8707_;
 (*result)[708] = &_f_8708_;
 (*result)[709] = &_f_8709_;
 (*result)[710] = &_f_8710_;
 (*result)[711] = &_f_8711_;
 (*result)[712] = &_f_8712_;
 (*result)[713] = &_f_8713_;
 (*result)[714] = &_f_8714_;
 (*result)[715] = &_f_8715_;
 (*result)[716] = &_f_8716_;
 (*result)[717] = &_f_8717_;
 (*result)[718] = &_f_8718_;
 (*result)[719] = &_f_8719_;
 (*result)[720] = &_f_8720_;
 (*result)[721] = &_f_8721_;
 (*result)[722] = &_f_8722_;
 (*result)[723] = &_f_8723_;
 (*result)[724] = &_f_8724_;
 (*result)[725] = &_f_8725_;
 (*result)[726] = &_f_8726_;
 (*result)[727] = &_f_8727_;
 (*result)[728] = &_f_8728_;
 (*result)[729] = &_f_8729_;
 (*result)[730] = &_f_8730_;
 (*result)[731] = &_f_8731_;
 (*result)[732] = &_f_8732_;
 (*result)[733] = &_f_8733_;
 (*result)[734] = &_f_8734_;
 (*result)[735] = &_f_8735_;
 (*result)[736] = &_f_8736_;
 (*result)[737] = &_f_8737_;
 (*result)[738] = &_f_8738_;
 (*result)[739] = &_f_8739_;
 (*result)[740] = &_f_8740_;
 (*result)[741] = &_f_8741_;
 (*result)[742] = &_f_8742_;
 (*result)[743] = &_f_8743_;
 (*result)[744] = &_f_8744_;
 (*result)[745] = &_f_8745_;
 (*result)[746] = &_f_8746_;
 (*result)[747] = &_f_8747_;
 (*result)[748] = &_f_8748_;
 (*result)[749] = &_f_8749_;
 (*result)[750] = &_f_8750_;
 (*result)[751] = &_f_8751_;
 (*result)[752] = &_f_8752_;
 (*result)[753] = &_f_8753_;
 (*result)[754] = &_f_8754_;
 (*result)[755] = &_f_8755_;
 (*result)[756] = &_f_8756_;
 (*result)[757] = &_f_8757_;
 (*result)[758] = &_f_8758_;
 (*result)[759] = &_f_8759_;
 (*result)[760] = &_f_8760_;
 (*result)[761] = &_f_8761_;
 (*result)[762] = &_f_8762_;
 (*result)[763] = &_f_8763_;
 (*result)[764] = &_f_8764_;
 (*result)[765] = &_f_8765_;
 (*result)[766] = &_f_8766_;
 (*result)[767] = &_f_8767_;
 (*result)[768] = &_f_8768_;
 (*result)[769] = &_f_8769_;
 (*result)[770] = &_f_8770_;
 (*result)[771] = &_f_8771_;
 (*result)[772] = &_f_8772_;
 (*result)[773] = &_f_8773_;
 (*result)[774] = &_f_8774_;
 (*result)[775] = &_f_8775_;
 (*result)[776] = &_f_8776_;
 (*result)[777] = &_f_8777_;
 (*result)[778] = &_f_8778_;
 (*result)[779] = &_f_8779_;
 (*result)[780] = &_f_8780_;
 (*result)[781] = &_f_8781_;
 (*result)[782] = &_f_8782_;
 (*result)[783] = &_f_8783_;
 (*result)[784] = &_f_8784_;
 (*result)[785] = &_f_8785_;
 (*result)[786] = &_f_8786_;
 (*result)[787] = &_f_8787_;
 (*result)[788] = &_f_8788_;
 (*result)[789] = &_f_8789_;
 (*result)[790] = &_f_8790_;
 (*result)[791] = &_f_8791_;
 (*result)[792] = &_f_8792_;
 (*result)[793] = &_f_8793_;
 (*result)[794] = &_f_8794_;
 (*result)[795] = &_f_8795_;
 (*result)[796] = &_f_8796_;
 (*result)[797] = &_f_8797_;
 (*result)[798] = &_f_8798_;
 (*result)[799] = &_f_8799_;
 (*result)[800] = &_f_8800_;
 (*result)[801] = &_f_8801_;
 (*result)[802] = &_f_8802_;
 (*result)[803] = &_f_8803_;
 (*result)[804] = &_f_8804_;
 (*result)[805] = &_f_8805_;
 (*result)[806] = &_f_8806_;
 (*result)[807] = &_f_8807_;
 (*result)[808] = &_f_8808_;
 (*result)[809] = &_f_8809_;
 (*result)[810] = &_f_8810_;
 (*result)[811] = &_f_8811_;
 (*result)[812] = &_f_8812_;
 (*result)[813] = &_f_8813_;
 (*result)[814] = &_f_8814_;
 (*result)[815] = &_f_8815_;
 (*result)[816] = &_f_8816_;
 (*result)[817] = &_f_8817_;
 (*result)[818] = &_f_8818_;
 (*result)[819] = &_f_8819_;
 (*result)[820] = &_f_8820_;
 (*result)[821] = &_f_8821_;
 (*result)[822] = &_f_8822_;
 (*result)[823] = &_f_8823_;
 (*result)[824] = &_f_8824_;
 (*result)[825] = &_f_8825_;
 (*result)[826] = &_f_8826_;
 (*result)[827] = &_f_8827_;
 (*result)[828] = &_f_8828_;
 (*result)[829] = &_f_8829_;
 (*result)[830] = &_f_8830_;
 (*result)[831] = &_f_8831_;
 (*result)[832] = &_f_8832_;
 (*result)[833] = &_f_8833_;
 (*result)[834] = &_f_8834_;
 (*result)[835] = &_f_8835_;
 (*result)[836] = &_f_8836_;
 (*result)[837] = &_f_8837_;
 (*result)[838] = &_f_8838_;
 (*result)[839] = &_f_8839_;
 (*result)[840] = &_f_8840_;
 (*result)[841] = &_f_8841_;
 (*result)[842] = &_f_8842_;
 (*result)[843] = &_f_8843_;
 (*result)[844] = &_f_8844_;
 (*result)[845] = &_f_8845_;
 (*result)[846] = &_f_8846_;
 (*result)[847] = &_f_8847_;
 (*result)[848] = &_f_8848_;
 (*result)[849] = &_f_8849_;
 (*result)[850] = &_f_8850_;
 (*result)[851] = &_f_8851_;
 (*result)[852] = &_f_8852_;
 (*result)[853] = &_f_8853_;
 (*result)[854] = &_f_8854_;
 (*result)[855] = &_f_8855_;
 (*result)[856] = &_f_8856_;
 (*result)[857] = &_f_8857_;
 (*result)[858] = &_f_8858_;
 (*result)[859] = &_f_8859_;
 (*result)[860] = &_f_8860_;
 (*result)[861] = &_f_8861_;
 (*result)[862] = &_f_8862_;
 (*result)[863] = &_f_8863_;
 (*result)[864] = &_f_8864_;
 (*result)[865] = &_f_8865_;
 (*result)[866] = &_f_8866_;
 (*result)[867] = &_f_8867_;
 (*result)[868] = &_f_8868_;
 (*result)[869] = &_f_8869_;
 (*result)[870] = &_f_8870_;
 (*result)[871] = &_f_8871_;
 (*result)[872] = &_f_8872_;
 (*result)[873] = &_f_8873_;
 (*result)[874] = &_f_8874_;
 (*result)[875] = &_f_8875_;
 (*result)[876] = &_f_8876_;
 (*result)[877] = &_f_8877_;
 (*result)[878] = &_f_8878_;
 (*result)[879] = &_f_8879_;
 (*result)[880] = &_f_8880_;
 (*result)[881] = &_f_8881_;
 (*result)[882] = &_f_8882_;
 (*result)[883] = &_f_8883_;
 (*result)[884] = &_f_8884_;
 (*result)[885] = &_f_8885_;
 (*result)[886] = &_f_8886_;
 (*result)[887] = &_f_8887_;
 (*result)[888] = &_f_8888_;
 (*result)[889] = &_f_8889_;
 (*result)[890] = &_f_8890_;
 (*result)[891] = &_f_8891_;
 (*result)[892] = &_f_8892_;
 (*result)[893] = &_f_8893_;
 (*result)[894] = &_f_8894_;
 (*result)[895] = &_f_8895_;
 (*result)[896] = &_f_8896_;
 (*result)[897] = &_f_8897_;
 (*result)[898] = &_f_8898_;
 (*result)[899] = &_f_8899_;
 (*result)[900] = &_f_8900_;
 (*result)[901] = &_f_8901_;
 (*result)[902] = &_f_8902_;
 (*result)[903] = &_f_8903_;
 (*result)[904] = &_f_8904_;
 (*result)[905] = &_f_8905_;
 (*result)[906] = &_f_8906_;
 (*result)[907] = &_f_8907_;
 (*result)[908] = &_f_8908_;
 (*result)[909] = &_f_8909_;
 (*result)[910] = &_f_8910_;
 (*result)[911] = &_f_8911_;
 (*result)[912] = &_f_8912_;
 (*result)[913] = &_f_8913_;
 (*result)[914] = &_f_8914_;
 (*result)[915] = &_f_8915_;
 (*result)[916] = &_f_8916_;
 (*result)[917] = &_f_8917_;
 (*result)[918] = &_f_8918_;
 (*result)[919] = &_f_8919_;
 (*result)[920] = &_f_8920_;
 (*result)[921] = &_f_8921_;
 (*result)[922] = &_f_8922_;
 (*result)[923] = &_f_8923_;
 (*result)[924] = &_f_8924_;
 (*result)[925] = &_f_8925_;
 (*result)[926] = &_f_8926_;
 (*result)[927] = &_f_8927_;
 (*result)[928] = &_f_8928_;
 (*result)[929] = &_f_8929_;
 (*result)[930] = &_f_8930_;
 (*result)[931] = &_f_8931_;
 (*result)[932] = &_f_8932_;
 (*result)[933] = &_f_8933_;
 (*result)[934] = &_f_8934_;
 (*result)[935] = &_f_8935_;
 (*result)[936] = &_f_8936_;
 (*result)[937] = &_f_8937_;
 (*result)[938] = &_f_8938_;
 (*result)[939] = &_f_8939_;
 (*result)[940] = &_f_8940_;
 (*result)[941] = &_f_8941_;
 (*result)[942] = &_f_8942_;
 (*result)[943] = &_f_8943_;
 (*result)[944] = &_f_8944_;
 (*result)[945] = &_f_8945_;
 (*result)[946] = &_f_8946_;
 (*result)[947] = &_f_8947_;
 (*result)[948] = &_f_8948_;
 (*result)[949] = &_f_8949_;
 (*result)[950] = &_f_8950_;
 (*result)[951] = &_f_8951_;
 (*result)[952] = &_f_8952_;
 (*result)[953] = &_f_8953_;
 (*result)[954] = &_f_8954_;
 (*result)[955] = &_f_8955_;
 (*result)[956] = &_f_8956_;
 (*result)[957] = &_f_8957_;
 (*result)[958] = &_f_8958_;
 (*result)[959] = &_f_8959_;
 (*result)[960] = &_f_8960_;
 (*result)[961] = &_f_8961_;
 (*result)[962] = &_f_8962_;
 (*result)[963] = &_f_8963_;
 (*result)[964] = &_f_8964_;
 (*result)[965] = &_f_8965_;
 (*result)[966] = &_f_8966_;
 (*result)[967] = &_f_8967_;
 (*result)[968] = &_f_8968_;
 (*result)[969] = &_f_8969_;
 (*result)[970] = &_f_8970_;
 (*result)[971] = &_f_8971_;
 (*result)[972] = &_f_8972_;
 (*result)[973] = &_f_8973_;
 (*result)[974] = &_f_8974_;
 (*result)[975] = &_f_8975_;
 (*result)[976] = &_f_8976_;
 (*result)[977] = &_f_8977_;
 (*result)[978] = &_f_8978_;
 (*result)[979] = &_f_8979_;
 (*result)[980] = &_f_8980_;
 (*result)[981] = &_f_8981_;
 (*result)[982] = &_f_8982_;
 (*result)[983] = &_f_8983_;
 (*result)[984] = &_f_8984_;
 (*result)[985] = &_f_8985_;
 (*result)[986] = &_f_8986_;
 (*result)[987] = &_f_8987_;
 (*result)[988] = &_f_8988_;
 (*result)[989] = &_f_8989_;
 (*result)[990] = &_f_8990_;
 (*result)[991] = &_f_8991_;
 (*result)[992] = &_f_8992_;
 (*result)[993] = &_f_8993_;
 (*result)[994] = &_f_8994_;
 (*result)[995] = &_f_8995_;
 (*result)[996] = &_f_8996_;
 (*result)[997] = &_f_8997_;
 (*result)[998] = &_f_8998_;
 (*result)[999] = &_f_8999_;
}

void run_s01_3_re8(u4 code, minimal_fn_s01_re8_type fn, n8& retv, n8 a1, n8 a2, n8 a3)
{
 code %= 1000;
 static s01_3_re8_dispatch_array* dispatch_array = init_s01_3_re8_dispatch_array();
 run_s01_3_re8_type f = (*dispatch_array)[code];
 f(retv, a1,a2,a3,fn);
}

#endif //def FULL_INCLUDE
