


#ifndef SEEN_DEFS_S0_3_RE6
#define SEEN_DEFS_S0_3_RE6

typedef r8(*minimal_fn_s0_re6_type)();
typedef void(*run_s0_3_re6_type)(r8& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re6_type fn);
typedef run_s0_3_re6_type s0_3_re6_dispatch_array [1000];

#endif //  SEEN_DEFS_S0_3_RE6

#ifdef FULL_INCLUDE

#include "fn-array-s0_3_re6.cpp"

s0_3_re6_dispatch_array* init_s0_3_re6_dispatch_array()
{
 s0_3_re6_dispatch_array* result = (s0_3_re6_dispatch_array*) new run_s0_3_re6_type[1000];
 
 (*result)[0] = &_f_6000_;
 (*result)[1] = &_f_6001_;
 (*result)[2] = &_f_6002_;
 (*result)[3] = &_f_6003_;
 (*result)[4] = &_f_6004_;
 (*result)[5] = &_f_6005_;
 (*result)[6] = &_f_6006_;
 (*result)[7] = &_f_6007_;
 (*result)[8] = &_f_6008_;
 (*result)[9] = &_f_6009_;
 (*result)[10] = &_f_6010_;
 (*result)[11] = &_f_6011_;
 (*result)[12] = &_f_6012_;
 (*result)[13] = &_f_6013_;
 (*result)[14] = &_f_6014_;
 (*result)[15] = &_f_6015_;
 (*result)[16] = &_f_6016_;
 (*result)[17] = &_f_6017_;
 (*result)[18] = &_f_6018_;
 (*result)[19] = &_f_6019_;
 (*result)[20] = &_f_6020_;
 (*result)[21] = &_f_6021_;
 (*result)[22] = &_f_6022_;
 (*result)[23] = &_f_6023_;
 (*result)[24] = &_f_6024_;
 (*result)[25] = &_f_6025_;
 (*result)[26] = &_f_6026_;
 (*result)[27] = &_f_6027_;
 (*result)[28] = &_f_6028_;
 (*result)[29] = &_f_6029_;
 (*result)[30] = &_f_6030_;
 (*result)[31] = &_f_6031_;
 (*result)[32] = &_f_6032_;
 (*result)[33] = &_f_6033_;
 (*result)[34] = &_f_6034_;
 (*result)[35] = &_f_6035_;
 (*result)[36] = &_f_6036_;
 (*result)[37] = &_f_6037_;
 (*result)[38] = &_f_6038_;
 (*result)[39] = &_f_6039_;
 (*result)[40] = &_f_6040_;
 (*result)[41] = &_f_6041_;
 (*result)[42] = &_f_6042_;
 (*result)[43] = &_f_6043_;
 (*result)[44] = &_f_6044_;
 (*result)[45] = &_f_6045_;
 (*result)[46] = &_f_6046_;
 (*result)[47] = &_f_6047_;
 (*result)[48] = &_f_6048_;
 (*result)[49] = &_f_6049_;
 (*result)[50] = &_f_6050_;
 (*result)[51] = &_f_6051_;
 (*result)[52] = &_f_6052_;
 (*result)[53] = &_f_6053_;
 (*result)[54] = &_f_6054_;
 (*result)[55] = &_f_6055_;
 (*result)[56] = &_f_6056_;
 (*result)[57] = &_f_6057_;
 (*result)[58] = &_f_6058_;
 (*result)[59] = &_f_6059_;
 (*result)[60] = &_f_6060_;
 (*result)[61] = &_f_6061_;
 (*result)[62] = &_f_6062_;
 (*result)[63] = &_f_6063_;
 (*result)[64] = &_f_6064_;
 (*result)[65] = &_f_6065_;
 (*result)[66] = &_f_6066_;
 (*result)[67] = &_f_6067_;
 (*result)[68] = &_f_6068_;
 (*result)[69] = &_f_6069_;
 (*result)[70] = &_f_6070_;
 (*result)[71] = &_f_6071_;
 (*result)[72] = &_f_6072_;
 (*result)[73] = &_f_6073_;
 (*result)[74] = &_f_6074_;
 (*result)[75] = &_f_6075_;
 (*result)[76] = &_f_6076_;
 (*result)[77] = &_f_6077_;
 (*result)[78] = &_f_6078_;
 (*result)[79] = &_f_6079_;
 (*result)[80] = &_f_6080_;
 (*result)[81] = &_f_6081_;
 (*result)[82] = &_f_6082_;
 (*result)[83] = &_f_6083_;
 (*result)[84] = &_f_6084_;
 (*result)[85] = &_f_6085_;
 (*result)[86] = &_f_6086_;
 (*result)[87] = &_f_6087_;
 (*result)[88] = &_f_6088_;
 (*result)[89] = &_f_6089_;
 (*result)[90] = &_f_6090_;
 (*result)[91] = &_f_6091_;
 (*result)[92] = &_f_6092_;
 (*result)[93] = &_f_6093_;
 (*result)[94] = &_f_6094_;
 (*result)[95] = &_f_6095_;
 (*result)[96] = &_f_6096_;
 (*result)[97] = &_f_6097_;
 (*result)[98] = &_f_6098_;
 (*result)[99] = &_f_6099_;
 (*result)[100] = &_f_6100_;
 (*result)[101] = &_f_6101_;
 (*result)[102] = &_f_6102_;
 (*result)[103] = &_f_6103_;
 (*result)[104] = &_f_6104_;
 (*result)[105] = &_f_6105_;
 (*result)[106] = &_f_6106_;
 (*result)[107] = &_f_6107_;
 (*result)[108] = &_f_6108_;
 (*result)[109] = &_f_6109_;
 (*result)[110] = &_f_6110_;
 (*result)[111] = &_f_6111_;
 (*result)[112] = &_f_6112_;
 (*result)[113] = &_f_6113_;
 (*result)[114] = &_f_6114_;
 (*result)[115] = &_f_6115_;
 (*result)[116] = &_f_6116_;
 (*result)[117] = &_f_6117_;
 (*result)[118] = &_f_6118_;
 (*result)[119] = &_f_6119_;
 (*result)[120] = &_f_6120_;
 (*result)[121] = &_f_6121_;
 (*result)[122] = &_f_6122_;
 (*result)[123] = &_f_6123_;
 (*result)[124] = &_f_6124_;
 (*result)[125] = &_f_6125_;
 (*result)[126] = &_f_6126_;
 (*result)[127] = &_f_6127_;
 (*result)[128] = &_f_6128_;
 (*result)[129] = &_f_6129_;
 (*result)[130] = &_f_6130_;
 (*result)[131] = &_f_6131_;
 (*result)[132] = &_f_6132_;
 (*result)[133] = &_f_6133_;
 (*result)[134] = &_f_6134_;
 (*result)[135] = &_f_6135_;
 (*result)[136] = &_f_6136_;
 (*result)[137] = &_f_6137_;
 (*result)[138] = &_f_6138_;
 (*result)[139] = &_f_6139_;
 (*result)[140] = &_f_6140_;
 (*result)[141] = &_f_6141_;
 (*result)[142] = &_f_6142_;
 (*result)[143] = &_f_6143_;
 (*result)[144] = &_f_6144_;
 (*result)[145] = &_f_6145_;
 (*result)[146] = &_f_6146_;
 (*result)[147] = &_f_6147_;
 (*result)[148] = &_f_6148_;
 (*result)[149] = &_f_6149_;
 (*result)[150] = &_f_6150_;
 (*result)[151] = &_f_6151_;
 (*result)[152] = &_f_6152_;
 (*result)[153] = &_f_6153_;
 (*result)[154] = &_f_6154_;
 (*result)[155] = &_f_6155_;
 (*result)[156] = &_f_6156_;
 (*result)[157] = &_f_6157_;
 (*result)[158] = &_f_6158_;
 (*result)[159] = &_f_6159_;
 (*result)[160] = &_f_6160_;
 (*result)[161] = &_f_6161_;
 (*result)[162] = &_f_6162_;
 (*result)[163] = &_f_6163_;
 (*result)[164] = &_f_6164_;
 (*result)[165] = &_f_6165_;
 (*result)[166] = &_f_6166_;
 (*result)[167] = &_f_6167_;
 (*result)[168] = &_f_6168_;
 (*result)[169] = &_f_6169_;
 (*result)[170] = &_f_6170_;
 (*result)[171] = &_f_6171_;
 (*result)[172] = &_f_6172_;
 (*result)[173] = &_f_6173_;
 (*result)[174] = &_f_6174_;
 (*result)[175] = &_f_6175_;
 (*result)[176] = &_f_6176_;
 (*result)[177] = &_f_6177_;
 (*result)[178] = &_f_6178_;
 (*result)[179] = &_f_6179_;
 (*result)[180] = &_f_6180_;
 (*result)[181] = &_f_6181_;
 (*result)[182] = &_f_6182_;
 (*result)[183] = &_f_6183_;
 (*result)[184] = &_f_6184_;
 (*result)[185] = &_f_6185_;
 (*result)[186] = &_f_6186_;
 (*result)[187] = &_f_6187_;
 (*result)[188] = &_f_6188_;
 (*result)[189] = &_f_6189_;
 (*result)[190] = &_f_6190_;
 (*result)[191] = &_f_6191_;
 (*result)[192] = &_f_6192_;
 (*result)[193] = &_f_6193_;
 (*result)[194] = &_f_6194_;
 (*result)[195] = &_f_6195_;
 (*result)[196] = &_f_6196_;
 (*result)[197] = &_f_6197_;
 (*result)[198] = &_f_6198_;
 (*result)[199] = &_f_6199_;
 (*result)[200] = &_f_6200_;
 (*result)[201] = &_f_6201_;
 (*result)[202] = &_f_6202_;
 (*result)[203] = &_f_6203_;
 (*result)[204] = &_f_6204_;
 (*result)[205] = &_f_6205_;
 (*result)[206] = &_f_6206_;
 (*result)[207] = &_f_6207_;
 (*result)[208] = &_f_6208_;
 (*result)[209] = &_f_6209_;
 (*result)[210] = &_f_6210_;
 (*result)[211] = &_f_6211_;
 (*result)[212] = &_f_6212_;
 (*result)[213] = &_f_6213_;
 (*result)[214] = &_f_6214_;
 (*result)[215] = &_f_6215_;
 (*result)[216] = &_f_6216_;
 (*result)[217] = &_f_6217_;
 (*result)[218] = &_f_6218_;
 (*result)[219] = &_f_6219_;
 (*result)[220] = &_f_6220_;
 (*result)[221] = &_f_6221_;
 (*result)[222] = &_f_6222_;
 (*result)[223] = &_f_6223_;
 (*result)[224] = &_f_6224_;
 (*result)[225] = &_f_6225_;
 (*result)[226] = &_f_6226_;
 (*result)[227] = &_f_6227_;
 (*result)[228] = &_f_6228_;
 (*result)[229] = &_f_6229_;
 (*result)[230] = &_f_6230_;
 (*result)[231] = &_f_6231_;
 (*result)[232] = &_f_6232_;
 (*result)[233] = &_f_6233_;
 (*result)[234] = &_f_6234_;
 (*result)[235] = &_f_6235_;
 (*result)[236] = &_f_6236_;
 (*result)[237] = &_f_6237_;
 (*result)[238] = &_f_6238_;
 (*result)[239] = &_f_6239_;
 (*result)[240] = &_f_6240_;
 (*result)[241] = &_f_6241_;
 (*result)[242] = &_f_6242_;
 (*result)[243] = &_f_6243_;
 (*result)[244] = &_f_6244_;
 (*result)[245] = &_f_6245_;
 (*result)[246] = &_f_6246_;
 (*result)[247] = &_f_6247_;
 (*result)[248] = &_f_6248_;
 (*result)[249] = &_f_6249_;
 (*result)[250] = &_f_6250_;
 (*result)[251] = &_f_6251_;
 (*result)[252] = &_f_6252_;
 (*result)[253] = &_f_6253_;
 (*result)[254] = &_f_6254_;
 (*result)[255] = &_f_6255_;
 (*result)[256] = &_f_6256_;
 (*result)[257] = &_f_6257_;
 (*result)[258] = &_f_6258_;
 (*result)[259] = &_f_6259_;
 (*result)[260] = &_f_6260_;
 (*result)[261] = &_f_6261_;
 (*result)[262] = &_f_6262_;
 (*result)[263] = &_f_6263_;
 (*result)[264] = &_f_6264_;
 (*result)[265] = &_f_6265_;
 (*result)[266] = &_f_6266_;
 (*result)[267] = &_f_6267_;
 (*result)[268] = &_f_6268_;
 (*result)[269] = &_f_6269_;
 (*result)[270] = &_f_6270_;
 (*result)[271] = &_f_6271_;
 (*result)[272] = &_f_6272_;
 (*result)[273] = &_f_6273_;
 (*result)[274] = &_f_6274_;
 (*result)[275] = &_f_6275_;
 (*result)[276] = &_f_6276_;
 (*result)[277] = &_f_6277_;
 (*result)[278] = &_f_6278_;
 (*result)[279] = &_f_6279_;
 (*result)[280] = &_f_6280_;
 (*result)[281] = &_f_6281_;
 (*result)[282] = &_f_6282_;
 (*result)[283] = &_f_6283_;
 (*result)[284] = &_f_6284_;
 (*result)[285] = &_f_6285_;
 (*result)[286] = &_f_6286_;
 (*result)[287] = &_f_6287_;
 (*result)[288] = &_f_6288_;
 (*result)[289] = &_f_6289_;
 (*result)[290] = &_f_6290_;
 (*result)[291] = &_f_6291_;
 (*result)[292] = &_f_6292_;
 (*result)[293] = &_f_6293_;
 (*result)[294] = &_f_6294_;
 (*result)[295] = &_f_6295_;
 (*result)[296] = &_f_6296_;
 (*result)[297] = &_f_6297_;
 (*result)[298] = &_f_6298_;
 (*result)[299] = &_f_6299_;
 (*result)[300] = &_f_6300_;
 (*result)[301] = &_f_6301_;
 (*result)[302] = &_f_6302_;
 (*result)[303] = &_f_6303_;
 (*result)[304] = &_f_6304_;
 (*result)[305] = &_f_6305_;
 (*result)[306] = &_f_6306_;
 (*result)[307] = &_f_6307_;
 (*result)[308] = &_f_6308_;
 (*result)[309] = &_f_6309_;
 (*result)[310] = &_f_6310_;
 (*result)[311] = &_f_6311_;
 (*result)[312] = &_f_6312_;
 (*result)[313] = &_f_6313_;
 (*result)[314] = &_f_6314_;
 (*result)[315] = &_f_6315_;
 (*result)[316] = &_f_6316_;
 (*result)[317] = &_f_6317_;
 (*result)[318] = &_f_6318_;
 (*result)[319] = &_f_6319_;
 (*result)[320] = &_f_6320_;
 (*result)[321] = &_f_6321_;
 (*result)[322] = &_f_6322_;
 (*result)[323] = &_f_6323_;
 (*result)[324] = &_f_6324_;
 (*result)[325] = &_f_6325_;
 (*result)[326] = &_f_6326_;
 (*result)[327] = &_f_6327_;
 (*result)[328] = &_f_6328_;
 (*result)[329] = &_f_6329_;
 (*result)[330] = &_f_6330_;
 (*result)[331] = &_f_6331_;
 (*result)[332] = &_f_6332_;
 (*result)[333] = &_f_6333_;
 (*result)[334] = &_f_6334_;
 (*result)[335] = &_f_6335_;
 (*result)[336] = &_f_6336_;
 (*result)[337] = &_f_6337_;
 (*result)[338] = &_f_6338_;
 (*result)[339] = &_f_6339_;
 (*result)[340] = &_f_6340_;
 (*result)[341] = &_f_6341_;
 (*result)[342] = &_f_6342_;
 (*result)[343] = &_f_6343_;
 (*result)[344] = &_f_6344_;
 (*result)[345] = &_f_6345_;
 (*result)[346] = &_f_6346_;
 (*result)[347] = &_f_6347_;
 (*result)[348] = &_f_6348_;
 (*result)[349] = &_f_6349_;
 (*result)[350] = &_f_6350_;
 (*result)[351] = &_f_6351_;
 (*result)[352] = &_f_6352_;
 (*result)[353] = &_f_6353_;
 (*result)[354] = &_f_6354_;
 (*result)[355] = &_f_6355_;
 (*result)[356] = &_f_6356_;
 (*result)[357] = &_f_6357_;
 (*result)[358] = &_f_6358_;
 (*result)[359] = &_f_6359_;
 (*result)[360] = &_f_6360_;
 (*result)[361] = &_f_6361_;
 (*result)[362] = &_f_6362_;
 (*result)[363] = &_f_6363_;
 (*result)[364] = &_f_6364_;
 (*result)[365] = &_f_6365_;
 (*result)[366] = &_f_6366_;
 (*result)[367] = &_f_6367_;
 (*result)[368] = &_f_6368_;
 (*result)[369] = &_f_6369_;
 (*result)[370] = &_f_6370_;
 (*result)[371] = &_f_6371_;
 (*result)[372] = &_f_6372_;
 (*result)[373] = &_f_6373_;
 (*result)[374] = &_f_6374_;
 (*result)[375] = &_f_6375_;
 (*result)[376] = &_f_6376_;
 (*result)[377] = &_f_6377_;
 (*result)[378] = &_f_6378_;
 (*result)[379] = &_f_6379_;
 (*result)[380] = &_f_6380_;
 (*result)[381] = &_f_6381_;
 (*result)[382] = &_f_6382_;
 (*result)[383] = &_f_6383_;
 (*result)[384] = &_f_6384_;
 (*result)[385] = &_f_6385_;
 (*result)[386] = &_f_6386_;
 (*result)[387] = &_f_6387_;
 (*result)[388] = &_f_6388_;
 (*result)[389] = &_f_6389_;
 (*result)[390] = &_f_6390_;
 (*result)[391] = &_f_6391_;
 (*result)[392] = &_f_6392_;
 (*result)[393] = &_f_6393_;
 (*result)[394] = &_f_6394_;
 (*result)[395] = &_f_6395_;
 (*result)[396] = &_f_6396_;
 (*result)[397] = &_f_6397_;
 (*result)[398] = &_f_6398_;
 (*result)[399] = &_f_6399_;
 (*result)[400] = &_f_6400_;
 (*result)[401] = &_f_6401_;
 (*result)[402] = &_f_6402_;
 (*result)[403] = &_f_6403_;
 (*result)[404] = &_f_6404_;
 (*result)[405] = &_f_6405_;
 (*result)[406] = &_f_6406_;
 (*result)[407] = &_f_6407_;
 (*result)[408] = &_f_6408_;
 (*result)[409] = &_f_6409_;
 (*result)[410] = &_f_6410_;
 (*result)[411] = &_f_6411_;
 (*result)[412] = &_f_6412_;
 (*result)[413] = &_f_6413_;
 (*result)[414] = &_f_6414_;
 (*result)[415] = &_f_6415_;
 (*result)[416] = &_f_6416_;
 (*result)[417] = &_f_6417_;
 (*result)[418] = &_f_6418_;
 (*result)[419] = &_f_6419_;
 (*result)[420] = &_f_6420_;
 (*result)[421] = &_f_6421_;
 (*result)[422] = &_f_6422_;
 (*result)[423] = &_f_6423_;
 (*result)[424] = &_f_6424_;
 (*result)[425] = &_f_6425_;
 (*result)[426] = &_f_6426_;
 (*result)[427] = &_f_6427_;
 (*result)[428] = &_f_6428_;
 (*result)[429] = &_f_6429_;
 (*result)[430] = &_f_6430_;
 (*result)[431] = &_f_6431_;
 (*result)[432] = &_f_6432_;
 (*result)[433] = &_f_6433_;
 (*result)[434] = &_f_6434_;
 (*result)[435] = &_f_6435_;
 (*result)[436] = &_f_6436_;
 (*result)[437] = &_f_6437_;
 (*result)[438] = &_f_6438_;
 (*result)[439] = &_f_6439_;
 (*result)[440] = &_f_6440_;
 (*result)[441] = &_f_6441_;
 (*result)[442] = &_f_6442_;
 (*result)[443] = &_f_6443_;
 (*result)[444] = &_f_6444_;
 (*result)[445] = &_f_6445_;
 (*result)[446] = &_f_6446_;
 (*result)[447] = &_f_6447_;
 (*result)[448] = &_f_6448_;
 (*result)[449] = &_f_6449_;
 (*result)[450] = &_f_6450_;
 (*result)[451] = &_f_6451_;
 (*result)[452] = &_f_6452_;
 (*result)[453] = &_f_6453_;
 (*result)[454] = &_f_6454_;
 (*result)[455] = &_f_6455_;
 (*result)[456] = &_f_6456_;
 (*result)[457] = &_f_6457_;
 (*result)[458] = &_f_6458_;
 (*result)[459] = &_f_6459_;
 (*result)[460] = &_f_6460_;
 (*result)[461] = &_f_6461_;
 (*result)[462] = &_f_6462_;
 (*result)[463] = &_f_6463_;
 (*result)[464] = &_f_6464_;
 (*result)[465] = &_f_6465_;
 (*result)[466] = &_f_6466_;
 (*result)[467] = &_f_6467_;
 (*result)[468] = &_f_6468_;
 (*result)[469] = &_f_6469_;
 (*result)[470] = &_f_6470_;
 (*result)[471] = &_f_6471_;
 (*result)[472] = &_f_6472_;
 (*result)[473] = &_f_6473_;
 (*result)[474] = &_f_6474_;
 (*result)[475] = &_f_6475_;
 (*result)[476] = &_f_6476_;
 (*result)[477] = &_f_6477_;
 (*result)[478] = &_f_6478_;
 (*result)[479] = &_f_6479_;
 (*result)[480] = &_f_6480_;
 (*result)[481] = &_f_6481_;
 (*result)[482] = &_f_6482_;
 (*result)[483] = &_f_6483_;
 (*result)[484] = &_f_6484_;
 (*result)[485] = &_f_6485_;
 (*result)[486] = &_f_6486_;
 (*result)[487] = &_f_6487_;
 (*result)[488] = &_f_6488_;
 (*result)[489] = &_f_6489_;
 (*result)[490] = &_f_6490_;
 (*result)[491] = &_f_6491_;
 (*result)[492] = &_f_6492_;
 (*result)[493] = &_f_6493_;
 (*result)[494] = &_f_6494_;
 (*result)[495] = &_f_6495_;
 (*result)[496] = &_f_6496_;
 (*result)[497] = &_f_6497_;
 (*result)[498] = &_f_6498_;
 (*result)[499] = &_f_6499_;
 (*result)[500] = &_f_6500_;
 (*result)[501] = &_f_6501_;
 (*result)[502] = &_f_6502_;
 (*result)[503] = &_f_6503_;
 (*result)[504] = &_f_6504_;
 (*result)[505] = &_f_6505_;
 (*result)[506] = &_f_6506_;
 (*result)[507] = &_f_6507_;
 (*result)[508] = &_f_6508_;
 (*result)[509] = &_f_6509_;
 (*result)[510] = &_f_6510_;
 (*result)[511] = &_f_6511_;
 (*result)[512] = &_f_6512_;
 (*result)[513] = &_f_6513_;
 (*result)[514] = &_f_6514_;
 (*result)[515] = &_f_6515_;
 (*result)[516] = &_f_6516_;
 (*result)[517] = &_f_6517_;
 (*result)[518] = &_f_6518_;
 (*result)[519] = &_f_6519_;
 (*result)[520] = &_f_6520_;
 (*result)[521] = &_f_6521_;
 (*result)[522] = &_f_6522_;
 (*result)[523] = &_f_6523_;
 (*result)[524] = &_f_6524_;
 (*result)[525] = &_f_6525_;
 (*result)[526] = &_f_6526_;
 (*result)[527] = &_f_6527_;
 (*result)[528] = &_f_6528_;
 (*result)[529] = &_f_6529_;
 (*result)[530] = &_f_6530_;
 (*result)[531] = &_f_6531_;
 (*result)[532] = &_f_6532_;
 (*result)[533] = &_f_6533_;
 (*result)[534] = &_f_6534_;
 (*result)[535] = &_f_6535_;
 (*result)[536] = &_f_6536_;
 (*result)[537] = &_f_6537_;
 (*result)[538] = &_f_6538_;
 (*result)[539] = &_f_6539_;
 (*result)[540] = &_f_6540_;
 (*result)[541] = &_f_6541_;
 (*result)[542] = &_f_6542_;
 (*result)[543] = &_f_6543_;
 (*result)[544] = &_f_6544_;
 (*result)[545] = &_f_6545_;
 (*result)[546] = &_f_6546_;
 (*result)[547] = &_f_6547_;
 (*result)[548] = &_f_6548_;
 (*result)[549] = &_f_6549_;
 (*result)[550] = &_f_6550_;
 (*result)[551] = &_f_6551_;
 (*result)[552] = &_f_6552_;
 (*result)[553] = &_f_6553_;
 (*result)[554] = &_f_6554_;
 (*result)[555] = &_f_6555_;
 (*result)[556] = &_f_6556_;
 (*result)[557] = &_f_6557_;
 (*result)[558] = &_f_6558_;
 (*result)[559] = &_f_6559_;
 (*result)[560] = &_f_6560_;
 (*result)[561] = &_f_6561_;
 (*result)[562] = &_f_6562_;
 (*result)[563] = &_f_6563_;
 (*result)[564] = &_f_6564_;
 (*result)[565] = &_f_6565_;
 (*result)[566] = &_f_6566_;
 (*result)[567] = &_f_6567_;
 (*result)[568] = &_f_6568_;
 (*result)[569] = &_f_6569_;
 (*result)[570] = &_f_6570_;
 (*result)[571] = &_f_6571_;
 (*result)[572] = &_f_6572_;
 (*result)[573] = &_f_6573_;
 (*result)[574] = &_f_6574_;
 (*result)[575] = &_f_6575_;
 (*result)[576] = &_f_6576_;
 (*result)[577] = &_f_6577_;
 (*result)[578] = &_f_6578_;
 (*result)[579] = &_f_6579_;
 (*result)[580] = &_f_6580_;
 (*result)[581] = &_f_6581_;
 (*result)[582] = &_f_6582_;
 (*result)[583] = &_f_6583_;
 (*result)[584] = &_f_6584_;
 (*result)[585] = &_f_6585_;
 (*result)[586] = &_f_6586_;
 (*result)[587] = &_f_6587_;
 (*result)[588] = &_f_6588_;
 (*result)[589] = &_f_6589_;
 (*result)[590] = &_f_6590_;
 (*result)[591] = &_f_6591_;
 (*result)[592] = &_f_6592_;
 (*result)[593] = &_f_6593_;
 (*result)[594] = &_f_6594_;
 (*result)[595] = &_f_6595_;
 (*result)[596] = &_f_6596_;
 (*result)[597] = &_f_6597_;
 (*result)[598] = &_f_6598_;
 (*result)[599] = &_f_6599_;
 (*result)[600] = &_f_6600_;
 (*result)[601] = &_f_6601_;
 (*result)[602] = &_f_6602_;
 (*result)[603] = &_f_6603_;
 (*result)[604] = &_f_6604_;
 (*result)[605] = &_f_6605_;
 (*result)[606] = &_f_6606_;
 (*result)[607] = &_f_6607_;
 (*result)[608] = &_f_6608_;
 (*result)[609] = &_f_6609_;
 (*result)[610] = &_f_6610_;
 (*result)[611] = &_f_6611_;
 (*result)[612] = &_f_6612_;
 (*result)[613] = &_f_6613_;
 (*result)[614] = &_f_6614_;
 (*result)[615] = &_f_6615_;
 (*result)[616] = &_f_6616_;
 (*result)[617] = &_f_6617_;
 (*result)[618] = &_f_6618_;
 (*result)[619] = &_f_6619_;
 (*result)[620] = &_f_6620_;
 (*result)[621] = &_f_6621_;
 (*result)[622] = &_f_6622_;
 (*result)[623] = &_f_6623_;
 (*result)[624] = &_f_6624_;
 (*result)[625] = &_f_6625_;
 (*result)[626] = &_f_6626_;
 (*result)[627] = &_f_6627_;
 (*result)[628] = &_f_6628_;
 (*result)[629] = &_f_6629_;
 (*result)[630] = &_f_6630_;
 (*result)[631] = &_f_6631_;
 (*result)[632] = &_f_6632_;
 (*result)[633] = &_f_6633_;
 (*result)[634] = &_f_6634_;
 (*result)[635] = &_f_6635_;
 (*result)[636] = &_f_6636_;
 (*result)[637] = &_f_6637_;
 (*result)[638] = &_f_6638_;
 (*result)[639] = &_f_6639_;
 (*result)[640] = &_f_6640_;
 (*result)[641] = &_f_6641_;
 (*result)[642] = &_f_6642_;
 (*result)[643] = &_f_6643_;
 (*result)[644] = &_f_6644_;
 (*result)[645] = &_f_6645_;
 (*result)[646] = &_f_6646_;
 (*result)[647] = &_f_6647_;
 (*result)[648] = &_f_6648_;
 (*result)[649] = &_f_6649_;
 (*result)[650] = &_f_6650_;
 (*result)[651] = &_f_6651_;
 (*result)[652] = &_f_6652_;
 (*result)[653] = &_f_6653_;
 (*result)[654] = &_f_6654_;
 (*result)[655] = &_f_6655_;
 (*result)[656] = &_f_6656_;
 (*result)[657] = &_f_6657_;
 (*result)[658] = &_f_6658_;
 (*result)[659] = &_f_6659_;
 (*result)[660] = &_f_6660_;
 (*result)[661] = &_f_6661_;
 (*result)[662] = &_f_6662_;
 (*result)[663] = &_f_6663_;
 (*result)[664] = &_f_6664_;
 (*result)[665] = &_f_6665_;
 (*result)[666] = &_f_6666_;
 (*result)[667] = &_f_6667_;
 (*result)[668] = &_f_6668_;
 (*result)[669] = &_f_6669_;
 (*result)[670] = &_f_6670_;
 (*result)[671] = &_f_6671_;
 (*result)[672] = &_f_6672_;
 (*result)[673] = &_f_6673_;
 (*result)[674] = &_f_6674_;
 (*result)[675] = &_f_6675_;
 (*result)[676] = &_f_6676_;
 (*result)[677] = &_f_6677_;
 (*result)[678] = &_f_6678_;
 (*result)[679] = &_f_6679_;
 (*result)[680] = &_f_6680_;
 (*result)[681] = &_f_6681_;
 (*result)[682] = &_f_6682_;
 (*result)[683] = &_f_6683_;
 (*result)[684] = &_f_6684_;
 (*result)[685] = &_f_6685_;
 (*result)[686] = &_f_6686_;
 (*result)[687] = &_f_6687_;
 (*result)[688] = &_f_6688_;
 (*result)[689] = &_f_6689_;
 (*result)[690] = &_f_6690_;
 (*result)[691] = &_f_6691_;
 (*result)[692] = &_f_6692_;
 (*result)[693] = &_f_6693_;
 (*result)[694] = &_f_6694_;
 (*result)[695] = &_f_6695_;
 (*result)[696] = &_f_6696_;
 (*result)[697] = &_f_6697_;
 (*result)[698] = &_f_6698_;
 (*result)[699] = &_f_6699_;
 (*result)[700] = &_f_6700_;
 (*result)[701] = &_f_6701_;
 (*result)[702] = &_f_6702_;
 (*result)[703] = &_f_6703_;
 (*result)[704] = &_f_6704_;
 (*result)[705] = &_f_6705_;
 (*result)[706] = &_f_6706_;
 (*result)[707] = &_f_6707_;
 (*result)[708] = &_f_6708_;
 (*result)[709] = &_f_6709_;
 (*result)[710] = &_f_6710_;
 (*result)[711] = &_f_6711_;
 (*result)[712] = &_f_6712_;
 (*result)[713] = &_f_6713_;
 (*result)[714] = &_f_6714_;
 (*result)[715] = &_f_6715_;
 (*result)[716] = &_f_6716_;
 (*result)[717] = &_f_6717_;
 (*result)[718] = &_f_6718_;
 (*result)[719] = &_f_6719_;
 (*result)[720] = &_f_6720_;
 (*result)[721] = &_f_6721_;
 (*result)[722] = &_f_6722_;
 (*result)[723] = &_f_6723_;
 (*result)[724] = &_f_6724_;
 (*result)[725] = &_f_6725_;
 (*result)[726] = &_f_6726_;
 (*result)[727] = &_f_6727_;
 (*result)[728] = &_f_6728_;
 (*result)[729] = &_f_6729_;
 (*result)[730] = &_f_6730_;
 (*result)[731] = &_f_6731_;
 (*result)[732] = &_f_6732_;
 (*result)[733] = &_f_6733_;
 (*result)[734] = &_f_6734_;
 (*result)[735] = &_f_6735_;
 (*result)[736] = &_f_6736_;
 (*result)[737] = &_f_6737_;
 (*result)[738] = &_f_6738_;
 (*result)[739] = &_f_6739_;
 (*result)[740] = &_f_6740_;
 (*result)[741] = &_f_6741_;
 (*result)[742] = &_f_6742_;
 (*result)[743] = &_f_6743_;
 (*result)[744] = &_f_6744_;
 (*result)[745] = &_f_6745_;
 (*result)[746] = &_f_6746_;
 (*result)[747] = &_f_6747_;
 (*result)[748] = &_f_6748_;
 (*result)[749] = &_f_6749_;
 (*result)[750] = &_f_6750_;
 (*result)[751] = &_f_6751_;
 (*result)[752] = &_f_6752_;
 (*result)[753] = &_f_6753_;
 (*result)[754] = &_f_6754_;
 (*result)[755] = &_f_6755_;
 (*result)[756] = &_f_6756_;
 (*result)[757] = &_f_6757_;
 (*result)[758] = &_f_6758_;
 (*result)[759] = &_f_6759_;
 (*result)[760] = &_f_6760_;
 (*result)[761] = &_f_6761_;
 (*result)[762] = &_f_6762_;
 (*result)[763] = &_f_6763_;
 (*result)[764] = &_f_6764_;
 (*result)[765] = &_f_6765_;
 (*result)[766] = &_f_6766_;
 (*result)[767] = &_f_6767_;
 (*result)[768] = &_f_6768_;
 (*result)[769] = &_f_6769_;
 (*result)[770] = &_f_6770_;
 (*result)[771] = &_f_6771_;
 (*result)[772] = &_f_6772_;
 (*result)[773] = &_f_6773_;
 (*result)[774] = &_f_6774_;
 (*result)[775] = &_f_6775_;
 (*result)[776] = &_f_6776_;
 (*result)[777] = &_f_6777_;
 (*result)[778] = &_f_6778_;
 (*result)[779] = &_f_6779_;
 (*result)[780] = &_f_6780_;
 (*result)[781] = &_f_6781_;
 (*result)[782] = &_f_6782_;
 (*result)[783] = &_f_6783_;
 (*result)[784] = &_f_6784_;
 (*result)[785] = &_f_6785_;
 (*result)[786] = &_f_6786_;
 (*result)[787] = &_f_6787_;
 (*result)[788] = &_f_6788_;
 (*result)[789] = &_f_6789_;
 (*result)[790] = &_f_6790_;
 (*result)[791] = &_f_6791_;
 (*result)[792] = &_f_6792_;
 (*result)[793] = &_f_6793_;
 (*result)[794] = &_f_6794_;
 (*result)[795] = &_f_6795_;
 (*result)[796] = &_f_6796_;
 (*result)[797] = &_f_6797_;
 (*result)[798] = &_f_6798_;
 (*result)[799] = &_f_6799_;
 (*result)[800] = &_f_6800_;
 (*result)[801] = &_f_6801_;
 (*result)[802] = &_f_6802_;
 (*result)[803] = &_f_6803_;
 (*result)[804] = &_f_6804_;
 (*result)[805] = &_f_6805_;
 (*result)[806] = &_f_6806_;
 (*result)[807] = &_f_6807_;
 (*result)[808] = &_f_6808_;
 (*result)[809] = &_f_6809_;
 (*result)[810] = &_f_6810_;
 (*result)[811] = &_f_6811_;
 (*result)[812] = &_f_6812_;
 (*result)[813] = &_f_6813_;
 (*result)[814] = &_f_6814_;
 (*result)[815] = &_f_6815_;
 (*result)[816] = &_f_6816_;
 (*result)[817] = &_f_6817_;
 (*result)[818] = &_f_6818_;
 (*result)[819] = &_f_6819_;
 (*result)[820] = &_f_6820_;
 (*result)[821] = &_f_6821_;
 (*result)[822] = &_f_6822_;
 (*result)[823] = &_f_6823_;
 (*result)[824] = &_f_6824_;
 (*result)[825] = &_f_6825_;
 (*result)[826] = &_f_6826_;
 (*result)[827] = &_f_6827_;
 (*result)[828] = &_f_6828_;
 (*result)[829] = &_f_6829_;
 (*result)[830] = &_f_6830_;
 (*result)[831] = &_f_6831_;
 (*result)[832] = &_f_6832_;
 (*result)[833] = &_f_6833_;
 (*result)[834] = &_f_6834_;
 (*result)[835] = &_f_6835_;
 (*result)[836] = &_f_6836_;
 (*result)[837] = &_f_6837_;
 (*result)[838] = &_f_6838_;
 (*result)[839] = &_f_6839_;
 (*result)[840] = &_f_6840_;
 (*result)[841] = &_f_6841_;
 (*result)[842] = &_f_6842_;
 (*result)[843] = &_f_6843_;
 (*result)[844] = &_f_6844_;
 (*result)[845] = &_f_6845_;
 (*result)[846] = &_f_6846_;
 (*result)[847] = &_f_6847_;
 (*result)[848] = &_f_6848_;
 (*result)[849] = &_f_6849_;
 (*result)[850] = &_f_6850_;
 (*result)[851] = &_f_6851_;
 (*result)[852] = &_f_6852_;
 (*result)[853] = &_f_6853_;
 (*result)[854] = &_f_6854_;
 (*result)[855] = &_f_6855_;
 (*result)[856] = &_f_6856_;
 (*result)[857] = &_f_6857_;
 (*result)[858] = &_f_6858_;
 (*result)[859] = &_f_6859_;
 (*result)[860] = &_f_6860_;
 (*result)[861] = &_f_6861_;
 (*result)[862] = &_f_6862_;
 (*result)[863] = &_f_6863_;
 (*result)[864] = &_f_6864_;
 (*result)[865] = &_f_6865_;
 (*result)[866] = &_f_6866_;
 (*result)[867] = &_f_6867_;
 (*result)[868] = &_f_6868_;
 (*result)[869] = &_f_6869_;
 (*result)[870] = &_f_6870_;
 (*result)[871] = &_f_6871_;
 (*result)[872] = &_f_6872_;
 (*result)[873] = &_f_6873_;
 (*result)[874] = &_f_6874_;
 (*result)[875] = &_f_6875_;
 (*result)[876] = &_f_6876_;
 (*result)[877] = &_f_6877_;
 (*result)[878] = &_f_6878_;
 (*result)[879] = &_f_6879_;
 (*result)[880] = &_f_6880_;
 (*result)[881] = &_f_6881_;
 (*result)[882] = &_f_6882_;
 (*result)[883] = &_f_6883_;
 (*result)[884] = &_f_6884_;
 (*result)[885] = &_f_6885_;
 (*result)[886] = &_f_6886_;
 (*result)[887] = &_f_6887_;
 (*result)[888] = &_f_6888_;
 (*result)[889] = &_f_6889_;
 (*result)[890] = &_f_6890_;
 (*result)[891] = &_f_6891_;
 (*result)[892] = &_f_6892_;
 (*result)[893] = &_f_6893_;
 (*result)[894] = &_f_6894_;
 (*result)[895] = &_f_6895_;
 (*result)[896] = &_f_6896_;
 (*result)[897] = &_f_6897_;
 (*result)[898] = &_f_6898_;
 (*result)[899] = &_f_6899_;
 (*result)[900] = &_f_6900_;
 (*result)[901] = &_f_6901_;
 (*result)[902] = &_f_6902_;
 (*result)[903] = &_f_6903_;
 (*result)[904] = &_f_6904_;
 (*result)[905] = &_f_6905_;
 (*result)[906] = &_f_6906_;
 (*result)[907] = &_f_6907_;
 (*result)[908] = &_f_6908_;
 (*result)[909] = &_f_6909_;
 (*result)[910] = &_f_6910_;
 (*result)[911] = &_f_6911_;
 (*result)[912] = &_f_6912_;
 (*result)[913] = &_f_6913_;
 (*result)[914] = &_f_6914_;
 (*result)[915] = &_f_6915_;
 (*result)[916] = &_f_6916_;
 (*result)[917] = &_f_6917_;
 (*result)[918] = &_f_6918_;
 (*result)[919] = &_f_6919_;
 (*result)[920] = &_f_6920_;
 (*result)[921] = &_f_6921_;
 (*result)[922] = &_f_6922_;
 (*result)[923] = &_f_6923_;
 (*result)[924] = &_f_6924_;
 (*result)[925] = &_f_6925_;
 (*result)[926] = &_f_6926_;
 (*result)[927] = &_f_6927_;
 (*result)[928] = &_f_6928_;
 (*result)[929] = &_f_6929_;
 (*result)[930] = &_f_6930_;
 (*result)[931] = &_f_6931_;
 (*result)[932] = &_f_6932_;
 (*result)[933] = &_f_6933_;
 (*result)[934] = &_f_6934_;
 (*result)[935] = &_f_6935_;
 (*result)[936] = &_f_6936_;
 (*result)[937] = &_f_6937_;
 (*result)[938] = &_f_6938_;
 (*result)[939] = &_f_6939_;
 (*result)[940] = &_f_6940_;
 (*result)[941] = &_f_6941_;
 (*result)[942] = &_f_6942_;
 (*result)[943] = &_f_6943_;
 (*result)[944] = &_f_6944_;
 (*result)[945] = &_f_6945_;
 (*result)[946] = &_f_6946_;
 (*result)[947] = &_f_6947_;
 (*result)[948] = &_f_6948_;
 (*result)[949] = &_f_6949_;
 (*result)[950] = &_f_6950_;
 (*result)[951] = &_f_6951_;
 (*result)[952] = &_f_6952_;
 (*result)[953] = &_f_6953_;
 (*result)[954] = &_f_6954_;
 (*result)[955] = &_f_6955_;
 (*result)[956] = &_f_6956_;
 (*result)[957] = &_f_6957_;
 (*result)[958] = &_f_6958_;
 (*result)[959] = &_f_6959_;
 (*result)[960] = &_f_6960_;
 (*result)[961] = &_f_6961_;
 (*result)[962] = &_f_6962_;
 (*result)[963] = &_f_6963_;
 (*result)[964] = &_f_6964_;
 (*result)[965] = &_f_6965_;
 (*result)[966] = &_f_6966_;
 (*result)[967] = &_f_6967_;
 (*result)[968] = &_f_6968_;
 (*result)[969] = &_f_6969_;
 (*result)[970] = &_f_6970_;
 (*result)[971] = &_f_6971_;
 (*result)[972] = &_f_6972_;
 (*result)[973] = &_f_6973_;
 (*result)[974] = &_f_6974_;
 (*result)[975] = &_f_6975_;
 (*result)[976] = &_f_6976_;
 (*result)[977] = &_f_6977_;
 (*result)[978] = &_f_6978_;
 (*result)[979] = &_f_6979_;
 (*result)[980] = &_f_6980_;
 (*result)[981] = &_f_6981_;
 (*result)[982] = &_f_6982_;
 (*result)[983] = &_f_6983_;
 (*result)[984] = &_f_6984_;
 (*result)[985] = &_f_6985_;
 (*result)[986] = &_f_6986_;
 (*result)[987] = &_f_6987_;
 (*result)[988] = &_f_6988_;
 (*result)[989] = &_f_6989_;
 (*result)[990] = &_f_6990_;
 (*result)[991] = &_f_6991_;
 (*result)[992] = &_f_6992_;
 (*result)[993] = &_f_6993_;
 (*result)[994] = &_f_6994_;
 (*result)[995] = &_f_6995_;
 (*result)[996] = &_f_6996_;
 (*result)[997] = &_f_6997_;
 (*result)[998] = &_f_6998_;
 (*result)[999] = &_f_6999_;
}

void run_s0_3_re6(u4 code, minimal_fn_s0_re6_type fn, r8& retv, n8 a1, n8 a2, n8 a3)
{
 code %= 10000;
 static s0_3_re6_dispatch_array* dispatch_array = init_s0_3_re6_dispatch_array();
 run_s0_3_re6_type f = (*dispatch_array)[code];
 f(retv, a1, a2, a3, fn);
}

#endif //def FULL_INCLUDE
