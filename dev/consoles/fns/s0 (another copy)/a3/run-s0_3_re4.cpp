


#ifndef SEEN_DEFS_S0_3_RE4
#define SEEN_DEFS_S0_3_RE4

typedef u4(*minimal_fn_s0_re4_type)();
typedef void(*run_s0_3_re4_type)(u4& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re4_type fn);
typedef run_s0_3_re4_type s0_3_re4_dispatch_array [1000];

#endif //  SEEN_DEFS_S0_3_RE4

#ifdef FULL_INCLUDE

#include "fn-array-s0_3_re4.cpp"

s0_3_re4_dispatch_array* init_s0_3_re4_dispatch_array()
{
 s0_3_re4_dispatch_array* result = (s0_3_re4_dispatch_array*) new run_s0_3_re4_type[1000];
 
 (*result)[0] = &_f_4000_;
 (*result)[1] = &_f_4001_;
 (*result)[2] = &_f_4002_;
 (*result)[3] = &_f_4003_;
 (*result)[4] = &_f_4004_;
 (*result)[5] = &_f_4005_;
 (*result)[6] = &_f_4006_;
 (*result)[7] = &_f_4007_;
 (*result)[8] = &_f_4008_;
 (*result)[9] = &_f_4009_;
 (*result)[10] = &_f_4010_;
 (*result)[11] = &_f_4011_;
 (*result)[12] = &_f_4012_;
 (*result)[13] = &_f_4013_;
 (*result)[14] = &_f_4014_;
 (*result)[15] = &_f_4015_;
 (*result)[16] = &_f_4016_;
 (*result)[17] = &_f_4017_;
 (*result)[18] = &_f_4018_;
 (*result)[19] = &_f_4019_;
 (*result)[20] = &_f_4020_;
 (*result)[21] = &_f_4021_;
 (*result)[22] = &_f_4022_;
 (*result)[23] = &_f_4023_;
 (*result)[24] = &_f_4024_;
 (*result)[25] = &_f_4025_;
 (*result)[26] = &_f_4026_;
 (*result)[27] = &_f_4027_;
 (*result)[28] = &_f_4028_;
 (*result)[29] = &_f_4029_;
 (*result)[30] = &_f_4030_;
 (*result)[31] = &_f_4031_;
 (*result)[32] = &_f_4032_;
 (*result)[33] = &_f_4033_;
 (*result)[34] = &_f_4034_;
 (*result)[35] = &_f_4035_;
 (*result)[36] = &_f_4036_;
 (*result)[37] = &_f_4037_;
 (*result)[38] = &_f_4038_;
 (*result)[39] = &_f_4039_;
 (*result)[40] = &_f_4040_;
 (*result)[41] = &_f_4041_;
 (*result)[42] = &_f_4042_;
 (*result)[43] = &_f_4043_;
 (*result)[44] = &_f_4044_;
 (*result)[45] = &_f_4045_;
 (*result)[46] = &_f_4046_;
 (*result)[47] = &_f_4047_;
 (*result)[48] = &_f_4048_;
 (*result)[49] = &_f_4049_;
 (*result)[50] = &_f_4050_;
 (*result)[51] = &_f_4051_;
 (*result)[52] = &_f_4052_;
 (*result)[53] = &_f_4053_;
 (*result)[54] = &_f_4054_;
 (*result)[55] = &_f_4055_;
 (*result)[56] = &_f_4056_;
 (*result)[57] = &_f_4057_;
 (*result)[58] = &_f_4058_;
 (*result)[59] = &_f_4059_;
 (*result)[60] = &_f_4060_;
 (*result)[61] = &_f_4061_;
 (*result)[62] = &_f_4062_;
 (*result)[63] = &_f_4063_;
 (*result)[64] = &_f_4064_;
 (*result)[65] = &_f_4065_;
 (*result)[66] = &_f_4066_;
 (*result)[67] = &_f_4067_;
 (*result)[68] = &_f_4068_;
 (*result)[69] = &_f_4069_;
 (*result)[70] = &_f_4070_;
 (*result)[71] = &_f_4071_;
 (*result)[72] = &_f_4072_;
 (*result)[73] = &_f_4073_;
 (*result)[74] = &_f_4074_;
 (*result)[75] = &_f_4075_;
 (*result)[76] = &_f_4076_;
 (*result)[77] = &_f_4077_;
 (*result)[78] = &_f_4078_;
 (*result)[79] = &_f_4079_;
 (*result)[80] = &_f_4080_;
 (*result)[81] = &_f_4081_;
 (*result)[82] = &_f_4082_;
 (*result)[83] = &_f_4083_;
 (*result)[84] = &_f_4084_;
 (*result)[85] = &_f_4085_;
 (*result)[86] = &_f_4086_;
 (*result)[87] = &_f_4087_;
 (*result)[88] = &_f_4088_;
 (*result)[89] = &_f_4089_;
 (*result)[90] = &_f_4090_;
 (*result)[91] = &_f_4091_;
 (*result)[92] = &_f_4092_;
 (*result)[93] = &_f_4093_;
 (*result)[94] = &_f_4094_;
 (*result)[95] = &_f_4095_;
 (*result)[96] = &_f_4096_;
 (*result)[97] = &_f_4097_;
 (*result)[98] = &_f_4098_;
 (*result)[99] = &_f_4099_;
 (*result)[100] = &_f_4100_;
 (*result)[101] = &_f_4101_;
 (*result)[102] = &_f_4102_;
 (*result)[103] = &_f_4103_;
 (*result)[104] = &_f_4104_;
 (*result)[105] = &_f_4105_;
 (*result)[106] = &_f_4106_;
 (*result)[107] = &_f_4107_;
 (*result)[108] = &_f_4108_;
 (*result)[109] = &_f_4109_;
 (*result)[110] = &_f_4110_;
 (*result)[111] = &_f_4111_;
 (*result)[112] = &_f_4112_;
 (*result)[113] = &_f_4113_;
 (*result)[114] = &_f_4114_;
 (*result)[115] = &_f_4115_;
 (*result)[116] = &_f_4116_;
 (*result)[117] = &_f_4117_;
 (*result)[118] = &_f_4118_;
 (*result)[119] = &_f_4119_;
 (*result)[120] = &_f_4120_;
 (*result)[121] = &_f_4121_;
 (*result)[122] = &_f_4122_;
 (*result)[123] = &_f_4123_;
 (*result)[124] = &_f_4124_;
 (*result)[125] = &_f_4125_;
 (*result)[126] = &_f_4126_;
 (*result)[127] = &_f_4127_;
 (*result)[128] = &_f_4128_;
 (*result)[129] = &_f_4129_;
 (*result)[130] = &_f_4130_;
 (*result)[131] = &_f_4131_;
 (*result)[132] = &_f_4132_;
 (*result)[133] = &_f_4133_;
 (*result)[134] = &_f_4134_;
 (*result)[135] = &_f_4135_;
 (*result)[136] = &_f_4136_;
 (*result)[137] = &_f_4137_;
 (*result)[138] = &_f_4138_;
 (*result)[139] = &_f_4139_;
 (*result)[140] = &_f_4140_;
 (*result)[141] = &_f_4141_;
 (*result)[142] = &_f_4142_;
 (*result)[143] = &_f_4143_;
 (*result)[144] = &_f_4144_;
 (*result)[145] = &_f_4145_;
 (*result)[146] = &_f_4146_;
 (*result)[147] = &_f_4147_;
 (*result)[148] = &_f_4148_;
 (*result)[149] = &_f_4149_;
 (*result)[150] = &_f_4150_;
 (*result)[151] = &_f_4151_;
 (*result)[152] = &_f_4152_;
 (*result)[153] = &_f_4153_;
 (*result)[154] = &_f_4154_;
 (*result)[155] = &_f_4155_;
 (*result)[156] = &_f_4156_;
 (*result)[157] = &_f_4157_;
 (*result)[158] = &_f_4158_;
 (*result)[159] = &_f_4159_;
 (*result)[160] = &_f_4160_;
 (*result)[161] = &_f_4161_;
 (*result)[162] = &_f_4162_;
 (*result)[163] = &_f_4163_;
 (*result)[164] = &_f_4164_;
 (*result)[165] = &_f_4165_;
 (*result)[166] = &_f_4166_;
 (*result)[167] = &_f_4167_;
 (*result)[168] = &_f_4168_;
 (*result)[169] = &_f_4169_;
 (*result)[170] = &_f_4170_;
 (*result)[171] = &_f_4171_;
 (*result)[172] = &_f_4172_;
 (*result)[173] = &_f_4173_;
 (*result)[174] = &_f_4174_;
 (*result)[175] = &_f_4175_;
 (*result)[176] = &_f_4176_;
 (*result)[177] = &_f_4177_;
 (*result)[178] = &_f_4178_;
 (*result)[179] = &_f_4179_;
 (*result)[180] = &_f_4180_;
 (*result)[181] = &_f_4181_;
 (*result)[182] = &_f_4182_;
 (*result)[183] = &_f_4183_;
 (*result)[184] = &_f_4184_;
 (*result)[185] = &_f_4185_;
 (*result)[186] = &_f_4186_;
 (*result)[187] = &_f_4187_;
 (*result)[188] = &_f_4188_;
 (*result)[189] = &_f_4189_;
 (*result)[190] = &_f_4190_;
 (*result)[191] = &_f_4191_;
 (*result)[192] = &_f_4192_;
 (*result)[193] = &_f_4193_;
 (*result)[194] = &_f_4194_;
 (*result)[195] = &_f_4195_;
 (*result)[196] = &_f_4196_;
 (*result)[197] = &_f_4197_;
 (*result)[198] = &_f_4198_;
 (*result)[199] = &_f_4199_;
 (*result)[200] = &_f_4200_;
 (*result)[201] = &_f_4201_;
 (*result)[202] = &_f_4202_;
 (*result)[203] = &_f_4203_;
 (*result)[204] = &_f_4204_;
 (*result)[205] = &_f_4205_;
 (*result)[206] = &_f_4206_;
 (*result)[207] = &_f_4207_;
 (*result)[208] = &_f_4208_;
 (*result)[209] = &_f_4209_;
 (*result)[210] = &_f_4210_;
 (*result)[211] = &_f_4211_;
 (*result)[212] = &_f_4212_;
 (*result)[213] = &_f_4213_;
 (*result)[214] = &_f_4214_;
 (*result)[215] = &_f_4215_;
 (*result)[216] = &_f_4216_;
 (*result)[217] = &_f_4217_;
 (*result)[218] = &_f_4218_;
 (*result)[219] = &_f_4219_;
 (*result)[220] = &_f_4220_;
 (*result)[221] = &_f_4221_;
 (*result)[222] = &_f_4222_;
 (*result)[223] = &_f_4223_;
 (*result)[224] = &_f_4224_;
 (*result)[225] = &_f_4225_;
 (*result)[226] = &_f_4226_;
 (*result)[227] = &_f_4227_;
 (*result)[228] = &_f_4228_;
 (*result)[229] = &_f_4229_;
 (*result)[230] = &_f_4230_;
 (*result)[231] = &_f_4231_;
 (*result)[232] = &_f_4232_;
 (*result)[233] = &_f_4233_;
 (*result)[234] = &_f_4234_;
 (*result)[235] = &_f_4235_;
 (*result)[236] = &_f_4236_;
 (*result)[237] = &_f_4237_;
 (*result)[238] = &_f_4238_;
 (*result)[239] = &_f_4239_;
 (*result)[240] = &_f_4240_;
 (*result)[241] = &_f_4241_;
 (*result)[242] = &_f_4242_;
 (*result)[243] = &_f_4243_;
 (*result)[244] = &_f_4244_;
 (*result)[245] = &_f_4245_;
 (*result)[246] = &_f_4246_;
 (*result)[247] = &_f_4247_;
 (*result)[248] = &_f_4248_;
 (*result)[249] = &_f_4249_;
 (*result)[250] = &_f_4250_;
 (*result)[251] = &_f_4251_;
 (*result)[252] = &_f_4252_;
 (*result)[253] = &_f_4253_;
 (*result)[254] = &_f_4254_;
 (*result)[255] = &_f_4255_;
 (*result)[256] = &_f_4256_;
 (*result)[257] = &_f_4257_;
 (*result)[258] = &_f_4258_;
 (*result)[259] = &_f_4259_;
 (*result)[260] = &_f_4260_;
 (*result)[261] = &_f_4261_;
 (*result)[262] = &_f_4262_;
 (*result)[263] = &_f_4263_;
 (*result)[264] = &_f_4264_;
 (*result)[265] = &_f_4265_;
 (*result)[266] = &_f_4266_;
 (*result)[267] = &_f_4267_;
 (*result)[268] = &_f_4268_;
 (*result)[269] = &_f_4269_;
 (*result)[270] = &_f_4270_;
 (*result)[271] = &_f_4271_;
 (*result)[272] = &_f_4272_;
 (*result)[273] = &_f_4273_;
 (*result)[274] = &_f_4274_;
 (*result)[275] = &_f_4275_;
 (*result)[276] = &_f_4276_;
 (*result)[277] = &_f_4277_;
 (*result)[278] = &_f_4278_;
 (*result)[279] = &_f_4279_;
 (*result)[280] = &_f_4280_;
 (*result)[281] = &_f_4281_;
 (*result)[282] = &_f_4282_;
 (*result)[283] = &_f_4283_;
 (*result)[284] = &_f_4284_;
 (*result)[285] = &_f_4285_;
 (*result)[286] = &_f_4286_;
 (*result)[287] = &_f_4287_;
 (*result)[288] = &_f_4288_;
 (*result)[289] = &_f_4289_;
 (*result)[290] = &_f_4290_;
 (*result)[291] = &_f_4291_;
 (*result)[292] = &_f_4292_;
 (*result)[293] = &_f_4293_;
 (*result)[294] = &_f_4294_;
 (*result)[295] = &_f_4295_;
 (*result)[296] = &_f_4296_;
 (*result)[297] = &_f_4297_;
 (*result)[298] = &_f_4298_;
 (*result)[299] = &_f_4299_;
 (*result)[300] = &_f_4300_;
 (*result)[301] = &_f_4301_;
 (*result)[302] = &_f_4302_;
 (*result)[303] = &_f_4303_;
 (*result)[304] = &_f_4304_;
 (*result)[305] = &_f_4305_;
 (*result)[306] = &_f_4306_;
 (*result)[307] = &_f_4307_;
 (*result)[308] = &_f_4308_;
 (*result)[309] = &_f_4309_;
 (*result)[310] = &_f_4310_;
 (*result)[311] = &_f_4311_;
 (*result)[312] = &_f_4312_;
 (*result)[313] = &_f_4313_;
 (*result)[314] = &_f_4314_;
 (*result)[315] = &_f_4315_;
 (*result)[316] = &_f_4316_;
 (*result)[317] = &_f_4317_;
 (*result)[318] = &_f_4318_;
 (*result)[319] = &_f_4319_;
 (*result)[320] = &_f_4320_;
 (*result)[321] = &_f_4321_;
 (*result)[322] = &_f_4322_;
 (*result)[323] = &_f_4323_;
 (*result)[324] = &_f_4324_;
 (*result)[325] = &_f_4325_;
 (*result)[326] = &_f_4326_;
 (*result)[327] = &_f_4327_;
 (*result)[328] = &_f_4328_;
 (*result)[329] = &_f_4329_;
 (*result)[330] = &_f_4330_;
 (*result)[331] = &_f_4331_;
 (*result)[332] = &_f_4332_;
 (*result)[333] = &_f_4333_;
 (*result)[334] = &_f_4334_;
 (*result)[335] = &_f_4335_;
 (*result)[336] = &_f_4336_;
 (*result)[337] = &_f_4337_;
 (*result)[338] = &_f_4338_;
 (*result)[339] = &_f_4339_;
 (*result)[340] = &_f_4340_;
 (*result)[341] = &_f_4341_;
 (*result)[342] = &_f_4342_;
 (*result)[343] = &_f_4343_;
 (*result)[344] = &_f_4344_;
 (*result)[345] = &_f_4345_;
 (*result)[346] = &_f_4346_;
 (*result)[347] = &_f_4347_;
 (*result)[348] = &_f_4348_;
 (*result)[349] = &_f_4349_;
 (*result)[350] = &_f_4350_;
 (*result)[351] = &_f_4351_;
 (*result)[352] = &_f_4352_;
 (*result)[353] = &_f_4353_;
 (*result)[354] = &_f_4354_;
 (*result)[355] = &_f_4355_;
 (*result)[356] = &_f_4356_;
 (*result)[357] = &_f_4357_;
 (*result)[358] = &_f_4358_;
 (*result)[359] = &_f_4359_;
 (*result)[360] = &_f_4360_;
 (*result)[361] = &_f_4361_;
 (*result)[362] = &_f_4362_;
 (*result)[363] = &_f_4363_;
 (*result)[364] = &_f_4364_;
 (*result)[365] = &_f_4365_;
 (*result)[366] = &_f_4366_;
 (*result)[367] = &_f_4367_;
 (*result)[368] = &_f_4368_;
 (*result)[369] = &_f_4369_;
 (*result)[370] = &_f_4370_;
 (*result)[371] = &_f_4371_;
 (*result)[372] = &_f_4372_;
 (*result)[373] = &_f_4373_;
 (*result)[374] = &_f_4374_;
 (*result)[375] = &_f_4375_;
 (*result)[376] = &_f_4376_;
 (*result)[377] = &_f_4377_;
 (*result)[378] = &_f_4378_;
 (*result)[379] = &_f_4379_;
 (*result)[380] = &_f_4380_;
 (*result)[381] = &_f_4381_;
 (*result)[382] = &_f_4382_;
 (*result)[383] = &_f_4383_;
 (*result)[384] = &_f_4384_;
 (*result)[385] = &_f_4385_;
 (*result)[386] = &_f_4386_;
 (*result)[387] = &_f_4387_;
 (*result)[388] = &_f_4388_;
 (*result)[389] = &_f_4389_;
 (*result)[390] = &_f_4390_;
 (*result)[391] = &_f_4391_;
 (*result)[392] = &_f_4392_;
 (*result)[393] = &_f_4393_;
 (*result)[394] = &_f_4394_;
 (*result)[395] = &_f_4395_;
 (*result)[396] = &_f_4396_;
 (*result)[397] = &_f_4397_;
 (*result)[398] = &_f_4398_;
 (*result)[399] = &_f_4399_;
 (*result)[400] = &_f_4400_;
 (*result)[401] = &_f_4401_;
 (*result)[402] = &_f_4402_;
 (*result)[403] = &_f_4403_;
 (*result)[404] = &_f_4404_;
 (*result)[405] = &_f_4405_;
 (*result)[406] = &_f_4406_;
 (*result)[407] = &_f_4407_;
 (*result)[408] = &_f_4408_;
 (*result)[409] = &_f_4409_;
 (*result)[410] = &_f_4410_;
 (*result)[411] = &_f_4411_;
 (*result)[412] = &_f_4412_;
 (*result)[413] = &_f_4413_;
 (*result)[414] = &_f_4414_;
 (*result)[415] = &_f_4415_;
 (*result)[416] = &_f_4416_;
 (*result)[417] = &_f_4417_;
 (*result)[418] = &_f_4418_;
 (*result)[419] = &_f_4419_;
 (*result)[420] = &_f_4420_;
 (*result)[421] = &_f_4421_;
 (*result)[422] = &_f_4422_;
 (*result)[423] = &_f_4423_;
 (*result)[424] = &_f_4424_;
 (*result)[425] = &_f_4425_;
 (*result)[426] = &_f_4426_;
 (*result)[427] = &_f_4427_;
 (*result)[428] = &_f_4428_;
 (*result)[429] = &_f_4429_;
 (*result)[430] = &_f_4430_;
 (*result)[431] = &_f_4431_;
 (*result)[432] = &_f_4432_;
 (*result)[433] = &_f_4433_;
 (*result)[434] = &_f_4434_;
 (*result)[435] = &_f_4435_;
 (*result)[436] = &_f_4436_;
 (*result)[437] = &_f_4437_;
 (*result)[438] = &_f_4438_;
 (*result)[439] = &_f_4439_;
 (*result)[440] = &_f_4440_;
 (*result)[441] = &_f_4441_;
 (*result)[442] = &_f_4442_;
 (*result)[443] = &_f_4443_;
 (*result)[444] = &_f_4444_;
 (*result)[445] = &_f_4445_;
 (*result)[446] = &_f_4446_;
 (*result)[447] = &_f_4447_;
 (*result)[448] = &_f_4448_;
 (*result)[449] = &_f_4449_;
 (*result)[450] = &_f_4450_;
 (*result)[451] = &_f_4451_;
 (*result)[452] = &_f_4452_;
 (*result)[453] = &_f_4453_;
 (*result)[454] = &_f_4454_;
 (*result)[455] = &_f_4455_;
 (*result)[456] = &_f_4456_;
 (*result)[457] = &_f_4457_;
 (*result)[458] = &_f_4458_;
 (*result)[459] = &_f_4459_;
 (*result)[460] = &_f_4460_;
 (*result)[461] = &_f_4461_;
 (*result)[462] = &_f_4462_;
 (*result)[463] = &_f_4463_;
 (*result)[464] = &_f_4464_;
 (*result)[465] = &_f_4465_;
 (*result)[466] = &_f_4466_;
 (*result)[467] = &_f_4467_;
 (*result)[468] = &_f_4468_;
 (*result)[469] = &_f_4469_;
 (*result)[470] = &_f_4470_;
 (*result)[471] = &_f_4471_;
 (*result)[472] = &_f_4472_;
 (*result)[473] = &_f_4473_;
 (*result)[474] = &_f_4474_;
 (*result)[475] = &_f_4475_;
 (*result)[476] = &_f_4476_;
 (*result)[477] = &_f_4477_;
 (*result)[478] = &_f_4478_;
 (*result)[479] = &_f_4479_;
 (*result)[480] = &_f_4480_;
 (*result)[481] = &_f_4481_;
 (*result)[482] = &_f_4482_;
 (*result)[483] = &_f_4483_;
 (*result)[484] = &_f_4484_;
 (*result)[485] = &_f_4485_;
 (*result)[486] = &_f_4486_;
 (*result)[487] = &_f_4487_;
 (*result)[488] = &_f_4488_;
 (*result)[489] = &_f_4489_;
 (*result)[490] = &_f_4490_;
 (*result)[491] = &_f_4491_;
 (*result)[492] = &_f_4492_;
 (*result)[493] = &_f_4493_;
 (*result)[494] = &_f_4494_;
 (*result)[495] = &_f_4495_;
 (*result)[496] = &_f_4496_;
 (*result)[497] = &_f_4497_;
 (*result)[498] = &_f_4498_;
 (*result)[499] = &_f_4499_;
 (*result)[500] = &_f_4500_;
 (*result)[501] = &_f_4501_;
 (*result)[502] = &_f_4502_;
 (*result)[503] = &_f_4503_;
 (*result)[504] = &_f_4504_;
 (*result)[505] = &_f_4505_;
 (*result)[506] = &_f_4506_;
 (*result)[507] = &_f_4507_;
 (*result)[508] = &_f_4508_;
 (*result)[509] = &_f_4509_;
 (*result)[510] = &_f_4510_;
 (*result)[511] = &_f_4511_;
 (*result)[512] = &_f_4512_;
 (*result)[513] = &_f_4513_;
 (*result)[514] = &_f_4514_;
 (*result)[515] = &_f_4515_;
 (*result)[516] = &_f_4516_;
 (*result)[517] = &_f_4517_;
 (*result)[518] = &_f_4518_;
 (*result)[519] = &_f_4519_;
 (*result)[520] = &_f_4520_;
 (*result)[521] = &_f_4521_;
 (*result)[522] = &_f_4522_;
 (*result)[523] = &_f_4523_;
 (*result)[524] = &_f_4524_;
 (*result)[525] = &_f_4525_;
 (*result)[526] = &_f_4526_;
 (*result)[527] = &_f_4527_;
 (*result)[528] = &_f_4528_;
 (*result)[529] = &_f_4529_;
 (*result)[530] = &_f_4530_;
 (*result)[531] = &_f_4531_;
 (*result)[532] = &_f_4532_;
 (*result)[533] = &_f_4533_;
 (*result)[534] = &_f_4534_;
 (*result)[535] = &_f_4535_;
 (*result)[536] = &_f_4536_;
 (*result)[537] = &_f_4537_;
 (*result)[538] = &_f_4538_;
 (*result)[539] = &_f_4539_;
 (*result)[540] = &_f_4540_;
 (*result)[541] = &_f_4541_;
 (*result)[542] = &_f_4542_;
 (*result)[543] = &_f_4543_;
 (*result)[544] = &_f_4544_;
 (*result)[545] = &_f_4545_;
 (*result)[546] = &_f_4546_;
 (*result)[547] = &_f_4547_;
 (*result)[548] = &_f_4548_;
 (*result)[549] = &_f_4549_;
 (*result)[550] = &_f_4550_;
 (*result)[551] = &_f_4551_;
 (*result)[552] = &_f_4552_;
 (*result)[553] = &_f_4553_;
 (*result)[554] = &_f_4554_;
 (*result)[555] = &_f_4555_;
 (*result)[556] = &_f_4556_;
 (*result)[557] = &_f_4557_;
 (*result)[558] = &_f_4558_;
 (*result)[559] = &_f_4559_;
 (*result)[560] = &_f_4560_;
 (*result)[561] = &_f_4561_;
 (*result)[562] = &_f_4562_;
 (*result)[563] = &_f_4563_;
 (*result)[564] = &_f_4564_;
 (*result)[565] = &_f_4565_;
 (*result)[566] = &_f_4566_;
 (*result)[567] = &_f_4567_;
 (*result)[568] = &_f_4568_;
 (*result)[569] = &_f_4569_;
 (*result)[570] = &_f_4570_;
 (*result)[571] = &_f_4571_;
 (*result)[572] = &_f_4572_;
 (*result)[573] = &_f_4573_;
 (*result)[574] = &_f_4574_;
 (*result)[575] = &_f_4575_;
 (*result)[576] = &_f_4576_;
 (*result)[577] = &_f_4577_;
 (*result)[578] = &_f_4578_;
 (*result)[579] = &_f_4579_;
 (*result)[580] = &_f_4580_;
 (*result)[581] = &_f_4581_;
 (*result)[582] = &_f_4582_;
 (*result)[583] = &_f_4583_;
 (*result)[584] = &_f_4584_;
 (*result)[585] = &_f_4585_;
 (*result)[586] = &_f_4586_;
 (*result)[587] = &_f_4587_;
 (*result)[588] = &_f_4588_;
 (*result)[589] = &_f_4589_;
 (*result)[590] = &_f_4590_;
 (*result)[591] = &_f_4591_;
 (*result)[592] = &_f_4592_;
 (*result)[593] = &_f_4593_;
 (*result)[594] = &_f_4594_;
 (*result)[595] = &_f_4595_;
 (*result)[596] = &_f_4596_;
 (*result)[597] = &_f_4597_;
 (*result)[598] = &_f_4598_;
 (*result)[599] = &_f_4599_;
 (*result)[600] = &_f_4600_;
 (*result)[601] = &_f_4601_;
 (*result)[602] = &_f_4602_;
 (*result)[603] = &_f_4603_;
 (*result)[604] = &_f_4604_;
 (*result)[605] = &_f_4605_;
 (*result)[606] = &_f_4606_;
 (*result)[607] = &_f_4607_;
 (*result)[608] = &_f_4608_;
 (*result)[609] = &_f_4609_;
 (*result)[610] = &_f_4610_;
 (*result)[611] = &_f_4611_;
 (*result)[612] = &_f_4612_;
 (*result)[613] = &_f_4613_;
 (*result)[614] = &_f_4614_;
 (*result)[615] = &_f_4615_;
 (*result)[616] = &_f_4616_;
 (*result)[617] = &_f_4617_;
 (*result)[618] = &_f_4618_;
 (*result)[619] = &_f_4619_;
 (*result)[620] = &_f_4620_;
 (*result)[621] = &_f_4621_;
 (*result)[622] = &_f_4622_;
 (*result)[623] = &_f_4623_;
 (*result)[624] = &_f_4624_;
 (*result)[625] = &_f_4625_;
 (*result)[626] = &_f_4626_;
 (*result)[627] = &_f_4627_;
 (*result)[628] = &_f_4628_;
 (*result)[629] = &_f_4629_;
 (*result)[630] = &_f_4630_;
 (*result)[631] = &_f_4631_;
 (*result)[632] = &_f_4632_;
 (*result)[633] = &_f_4633_;
 (*result)[634] = &_f_4634_;
 (*result)[635] = &_f_4635_;
 (*result)[636] = &_f_4636_;
 (*result)[637] = &_f_4637_;
 (*result)[638] = &_f_4638_;
 (*result)[639] = &_f_4639_;
 (*result)[640] = &_f_4640_;
 (*result)[641] = &_f_4641_;
 (*result)[642] = &_f_4642_;
 (*result)[643] = &_f_4643_;
 (*result)[644] = &_f_4644_;
 (*result)[645] = &_f_4645_;
 (*result)[646] = &_f_4646_;
 (*result)[647] = &_f_4647_;
 (*result)[648] = &_f_4648_;
 (*result)[649] = &_f_4649_;
 (*result)[650] = &_f_4650_;
 (*result)[651] = &_f_4651_;
 (*result)[652] = &_f_4652_;
 (*result)[653] = &_f_4653_;
 (*result)[654] = &_f_4654_;
 (*result)[655] = &_f_4655_;
 (*result)[656] = &_f_4656_;
 (*result)[657] = &_f_4657_;
 (*result)[658] = &_f_4658_;
 (*result)[659] = &_f_4659_;
 (*result)[660] = &_f_4660_;
 (*result)[661] = &_f_4661_;
 (*result)[662] = &_f_4662_;
 (*result)[663] = &_f_4663_;
 (*result)[664] = &_f_4664_;
 (*result)[665] = &_f_4665_;
 (*result)[666] = &_f_4666_;
 (*result)[667] = &_f_4667_;
 (*result)[668] = &_f_4668_;
 (*result)[669] = &_f_4669_;
 (*result)[670] = &_f_4670_;
 (*result)[671] = &_f_4671_;
 (*result)[672] = &_f_4672_;
 (*result)[673] = &_f_4673_;
 (*result)[674] = &_f_4674_;
 (*result)[675] = &_f_4675_;
 (*result)[676] = &_f_4676_;
 (*result)[677] = &_f_4677_;
 (*result)[678] = &_f_4678_;
 (*result)[679] = &_f_4679_;
 (*result)[680] = &_f_4680_;
 (*result)[681] = &_f_4681_;
 (*result)[682] = &_f_4682_;
 (*result)[683] = &_f_4683_;
 (*result)[684] = &_f_4684_;
 (*result)[685] = &_f_4685_;
 (*result)[686] = &_f_4686_;
 (*result)[687] = &_f_4687_;
 (*result)[688] = &_f_4688_;
 (*result)[689] = &_f_4689_;
 (*result)[690] = &_f_4690_;
 (*result)[691] = &_f_4691_;
 (*result)[692] = &_f_4692_;
 (*result)[693] = &_f_4693_;
 (*result)[694] = &_f_4694_;
 (*result)[695] = &_f_4695_;
 (*result)[696] = &_f_4696_;
 (*result)[697] = &_f_4697_;
 (*result)[698] = &_f_4698_;
 (*result)[699] = &_f_4699_;
 (*result)[700] = &_f_4700_;
 (*result)[701] = &_f_4701_;
 (*result)[702] = &_f_4702_;
 (*result)[703] = &_f_4703_;
 (*result)[704] = &_f_4704_;
 (*result)[705] = &_f_4705_;
 (*result)[706] = &_f_4706_;
 (*result)[707] = &_f_4707_;
 (*result)[708] = &_f_4708_;
 (*result)[709] = &_f_4709_;
 (*result)[710] = &_f_4710_;
 (*result)[711] = &_f_4711_;
 (*result)[712] = &_f_4712_;
 (*result)[713] = &_f_4713_;
 (*result)[714] = &_f_4714_;
 (*result)[715] = &_f_4715_;
 (*result)[716] = &_f_4716_;
 (*result)[717] = &_f_4717_;
 (*result)[718] = &_f_4718_;
 (*result)[719] = &_f_4719_;
 (*result)[720] = &_f_4720_;
 (*result)[721] = &_f_4721_;
 (*result)[722] = &_f_4722_;
 (*result)[723] = &_f_4723_;
 (*result)[724] = &_f_4724_;
 (*result)[725] = &_f_4725_;
 (*result)[726] = &_f_4726_;
 (*result)[727] = &_f_4727_;
 (*result)[728] = &_f_4728_;
 (*result)[729] = &_f_4729_;
 (*result)[730] = &_f_4730_;
 (*result)[731] = &_f_4731_;
 (*result)[732] = &_f_4732_;
 (*result)[733] = &_f_4733_;
 (*result)[734] = &_f_4734_;
 (*result)[735] = &_f_4735_;
 (*result)[736] = &_f_4736_;
 (*result)[737] = &_f_4737_;
 (*result)[738] = &_f_4738_;
 (*result)[739] = &_f_4739_;
 (*result)[740] = &_f_4740_;
 (*result)[741] = &_f_4741_;
 (*result)[742] = &_f_4742_;
 (*result)[743] = &_f_4743_;
 (*result)[744] = &_f_4744_;
 (*result)[745] = &_f_4745_;
 (*result)[746] = &_f_4746_;
 (*result)[747] = &_f_4747_;
 (*result)[748] = &_f_4748_;
 (*result)[749] = &_f_4749_;
 (*result)[750] = &_f_4750_;
 (*result)[751] = &_f_4751_;
 (*result)[752] = &_f_4752_;
 (*result)[753] = &_f_4753_;
 (*result)[754] = &_f_4754_;
 (*result)[755] = &_f_4755_;
 (*result)[756] = &_f_4756_;
 (*result)[757] = &_f_4757_;
 (*result)[758] = &_f_4758_;
 (*result)[759] = &_f_4759_;
 (*result)[760] = &_f_4760_;
 (*result)[761] = &_f_4761_;
 (*result)[762] = &_f_4762_;
 (*result)[763] = &_f_4763_;
 (*result)[764] = &_f_4764_;
 (*result)[765] = &_f_4765_;
 (*result)[766] = &_f_4766_;
 (*result)[767] = &_f_4767_;
 (*result)[768] = &_f_4768_;
 (*result)[769] = &_f_4769_;
 (*result)[770] = &_f_4770_;
 (*result)[771] = &_f_4771_;
 (*result)[772] = &_f_4772_;
 (*result)[773] = &_f_4773_;
 (*result)[774] = &_f_4774_;
 (*result)[775] = &_f_4775_;
 (*result)[776] = &_f_4776_;
 (*result)[777] = &_f_4777_;
 (*result)[778] = &_f_4778_;
 (*result)[779] = &_f_4779_;
 (*result)[780] = &_f_4780_;
 (*result)[781] = &_f_4781_;
 (*result)[782] = &_f_4782_;
 (*result)[783] = &_f_4783_;
 (*result)[784] = &_f_4784_;
 (*result)[785] = &_f_4785_;
 (*result)[786] = &_f_4786_;
 (*result)[787] = &_f_4787_;
 (*result)[788] = &_f_4788_;
 (*result)[789] = &_f_4789_;
 (*result)[790] = &_f_4790_;
 (*result)[791] = &_f_4791_;
 (*result)[792] = &_f_4792_;
 (*result)[793] = &_f_4793_;
 (*result)[794] = &_f_4794_;
 (*result)[795] = &_f_4795_;
 (*result)[796] = &_f_4796_;
 (*result)[797] = &_f_4797_;
 (*result)[798] = &_f_4798_;
 (*result)[799] = &_f_4799_;
 (*result)[800] = &_f_4800_;
 (*result)[801] = &_f_4801_;
 (*result)[802] = &_f_4802_;
 (*result)[803] = &_f_4803_;
 (*result)[804] = &_f_4804_;
 (*result)[805] = &_f_4805_;
 (*result)[806] = &_f_4806_;
 (*result)[807] = &_f_4807_;
 (*result)[808] = &_f_4808_;
 (*result)[809] = &_f_4809_;
 (*result)[810] = &_f_4810_;
 (*result)[811] = &_f_4811_;
 (*result)[812] = &_f_4812_;
 (*result)[813] = &_f_4813_;
 (*result)[814] = &_f_4814_;
 (*result)[815] = &_f_4815_;
 (*result)[816] = &_f_4816_;
 (*result)[817] = &_f_4817_;
 (*result)[818] = &_f_4818_;
 (*result)[819] = &_f_4819_;
 (*result)[820] = &_f_4820_;
 (*result)[821] = &_f_4821_;
 (*result)[822] = &_f_4822_;
 (*result)[823] = &_f_4823_;
 (*result)[824] = &_f_4824_;
 (*result)[825] = &_f_4825_;
 (*result)[826] = &_f_4826_;
 (*result)[827] = &_f_4827_;
 (*result)[828] = &_f_4828_;
 (*result)[829] = &_f_4829_;
 (*result)[830] = &_f_4830_;
 (*result)[831] = &_f_4831_;
 (*result)[832] = &_f_4832_;
 (*result)[833] = &_f_4833_;
 (*result)[834] = &_f_4834_;
 (*result)[835] = &_f_4835_;
 (*result)[836] = &_f_4836_;
 (*result)[837] = &_f_4837_;
 (*result)[838] = &_f_4838_;
 (*result)[839] = &_f_4839_;
 (*result)[840] = &_f_4840_;
 (*result)[841] = &_f_4841_;
 (*result)[842] = &_f_4842_;
 (*result)[843] = &_f_4843_;
 (*result)[844] = &_f_4844_;
 (*result)[845] = &_f_4845_;
 (*result)[846] = &_f_4846_;
 (*result)[847] = &_f_4847_;
 (*result)[848] = &_f_4848_;
 (*result)[849] = &_f_4849_;
 (*result)[850] = &_f_4850_;
 (*result)[851] = &_f_4851_;
 (*result)[852] = &_f_4852_;
 (*result)[853] = &_f_4853_;
 (*result)[854] = &_f_4854_;
 (*result)[855] = &_f_4855_;
 (*result)[856] = &_f_4856_;
 (*result)[857] = &_f_4857_;
 (*result)[858] = &_f_4858_;
 (*result)[859] = &_f_4859_;
 (*result)[860] = &_f_4860_;
 (*result)[861] = &_f_4861_;
 (*result)[862] = &_f_4862_;
 (*result)[863] = &_f_4863_;
 (*result)[864] = &_f_4864_;
 (*result)[865] = &_f_4865_;
 (*result)[866] = &_f_4866_;
 (*result)[867] = &_f_4867_;
 (*result)[868] = &_f_4868_;
 (*result)[869] = &_f_4869_;
 (*result)[870] = &_f_4870_;
 (*result)[871] = &_f_4871_;
 (*result)[872] = &_f_4872_;
 (*result)[873] = &_f_4873_;
 (*result)[874] = &_f_4874_;
 (*result)[875] = &_f_4875_;
 (*result)[876] = &_f_4876_;
 (*result)[877] = &_f_4877_;
 (*result)[878] = &_f_4878_;
 (*result)[879] = &_f_4879_;
 (*result)[880] = &_f_4880_;
 (*result)[881] = &_f_4881_;
 (*result)[882] = &_f_4882_;
 (*result)[883] = &_f_4883_;
 (*result)[884] = &_f_4884_;
 (*result)[885] = &_f_4885_;
 (*result)[886] = &_f_4886_;
 (*result)[887] = &_f_4887_;
 (*result)[888] = &_f_4888_;
 (*result)[889] = &_f_4889_;
 (*result)[890] = &_f_4890_;
 (*result)[891] = &_f_4891_;
 (*result)[892] = &_f_4892_;
 (*result)[893] = &_f_4893_;
 (*result)[894] = &_f_4894_;
 (*result)[895] = &_f_4895_;
 (*result)[896] = &_f_4896_;
 (*result)[897] = &_f_4897_;
 (*result)[898] = &_f_4898_;
 (*result)[899] = &_f_4899_;
 (*result)[900] = &_f_4900_;
 (*result)[901] = &_f_4901_;
 (*result)[902] = &_f_4902_;
 (*result)[903] = &_f_4903_;
 (*result)[904] = &_f_4904_;
 (*result)[905] = &_f_4905_;
 (*result)[906] = &_f_4906_;
 (*result)[907] = &_f_4907_;
 (*result)[908] = &_f_4908_;
 (*result)[909] = &_f_4909_;
 (*result)[910] = &_f_4910_;
 (*result)[911] = &_f_4911_;
 (*result)[912] = &_f_4912_;
 (*result)[913] = &_f_4913_;
 (*result)[914] = &_f_4914_;
 (*result)[915] = &_f_4915_;
 (*result)[916] = &_f_4916_;
 (*result)[917] = &_f_4917_;
 (*result)[918] = &_f_4918_;
 (*result)[919] = &_f_4919_;
 (*result)[920] = &_f_4920_;
 (*result)[921] = &_f_4921_;
 (*result)[922] = &_f_4922_;
 (*result)[923] = &_f_4923_;
 (*result)[924] = &_f_4924_;
 (*result)[925] = &_f_4925_;
 (*result)[926] = &_f_4926_;
 (*result)[927] = &_f_4927_;
 (*result)[928] = &_f_4928_;
 (*result)[929] = &_f_4929_;
 (*result)[930] = &_f_4930_;
 (*result)[931] = &_f_4931_;
 (*result)[932] = &_f_4932_;
 (*result)[933] = &_f_4933_;
 (*result)[934] = &_f_4934_;
 (*result)[935] = &_f_4935_;
 (*result)[936] = &_f_4936_;
 (*result)[937] = &_f_4937_;
 (*result)[938] = &_f_4938_;
 (*result)[939] = &_f_4939_;
 (*result)[940] = &_f_4940_;
 (*result)[941] = &_f_4941_;
 (*result)[942] = &_f_4942_;
 (*result)[943] = &_f_4943_;
 (*result)[944] = &_f_4944_;
 (*result)[945] = &_f_4945_;
 (*result)[946] = &_f_4946_;
 (*result)[947] = &_f_4947_;
 (*result)[948] = &_f_4948_;
 (*result)[949] = &_f_4949_;
 (*result)[950] = &_f_4950_;
 (*result)[951] = &_f_4951_;
 (*result)[952] = &_f_4952_;
 (*result)[953] = &_f_4953_;
 (*result)[954] = &_f_4954_;
 (*result)[955] = &_f_4955_;
 (*result)[956] = &_f_4956_;
 (*result)[957] = &_f_4957_;
 (*result)[958] = &_f_4958_;
 (*result)[959] = &_f_4959_;
 (*result)[960] = &_f_4960_;
 (*result)[961] = &_f_4961_;
 (*result)[962] = &_f_4962_;
 (*result)[963] = &_f_4963_;
 (*result)[964] = &_f_4964_;
 (*result)[965] = &_f_4965_;
 (*result)[966] = &_f_4966_;
 (*result)[967] = &_f_4967_;
 (*result)[968] = &_f_4968_;
 (*result)[969] = &_f_4969_;
 (*result)[970] = &_f_4970_;
 (*result)[971] = &_f_4971_;
 (*result)[972] = &_f_4972_;
 (*result)[973] = &_f_4973_;
 (*result)[974] = &_f_4974_;
 (*result)[975] = &_f_4975_;
 (*result)[976] = &_f_4976_;
 (*result)[977] = &_f_4977_;
 (*result)[978] = &_f_4978_;
 (*result)[979] = &_f_4979_;
 (*result)[980] = &_f_4980_;
 (*result)[981] = &_f_4981_;
 (*result)[982] = &_f_4982_;
 (*result)[983] = &_f_4983_;
 (*result)[984] = &_f_4984_;
 (*result)[985] = &_f_4985_;
 (*result)[986] = &_f_4986_;
 (*result)[987] = &_f_4987_;
 (*result)[988] = &_f_4988_;
 (*result)[989] = &_f_4989_;
 (*result)[990] = &_f_4990_;
 (*result)[991] = &_f_4991_;
 (*result)[992] = &_f_4992_;
 (*result)[993] = &_f_4993_;
 (*result)[994] = &_f_4994_;
 (*result)[995] = &_f_4995_;
 (*result)[996] = &_f_4996_;
 (*result)[997] = &_f_4997_;
 (*result)[998] = &_f_4998_;
 (*result)[999] = &_f_4999_;
}

void run_s0_3_re4(u4 code, minimal_fn_s0_re4_type fn, u4& retv, n8 a1, n8 a2, n8 a3)
{
 code %= 1000;
 static s0_3_re4_dispatch_array* dispatch_array = init_s0_3_re4_dispatch_array();
 run_s0_3_re4_type f = (*dispatch_array)[code];
 f(retv, a1,a2,a3,fn);
}

#endif //def FULL_INCLUDE
