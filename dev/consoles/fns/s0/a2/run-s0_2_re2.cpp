


#ifndef SEEN_DEFS_S0_2_RE2
#define SEEN_DEFS_S0_2_RE2

typedef u2(*minimal_fn_s0_re2_type)();
typedef void(*run_s0_2_re2_type)(u2& retv, n8 arg1, n8 arg2, n8 arg3, minimal_fn_s0_re2_type fn);
typedef run_s0_2_re2_type s0_2_re2_dispatch_array [100];

#endif //  SEEN_DEFS_S0_2_RE2

#ifdef FULL_INCLUDE

#include "fn-array-s0_2_re2.cpp"

s0_2_re2_dispatch_array* init_s0_2_re2_dispatch_array()
{
 s0_2_re2_dispatch_array* result = (s0_2_re2_dispatch_array*) new run_s0_2_re2_type[100];
 
 (*result)[0] = &_f_2000_;
 (*result)[1] = &_f_2001_;
 (*result)[2] = &_f_2002_;
 (*result)[3] = &_f_2003_;
 (*result)[4] = &_f_2004_;
 (*result)[5] = &_f_2005_;
 (*result)[6] = &_f_2006_;
 (*result)[7] = &_f_2007_;
 (*result)[8] = &_f_2008_;
 (*result)[9] = &_f_2009_;
 (*result)[10] = &_f_2010_;
 (*result)[11] = &_f_2011_;
 (*result)[12] = &_f_2012_;
 (*result)[13] = &_f_2013_;
 (*result)[14] = &_f_2014_;
 (*result)[15] = &_f_2015_;
 (*result)[16] = &_f_2016_;
 (*result)[17] = &_f_2017_;
 (*result)[18] = &_f_2018_;
 (*result)[19] = &_f_2019_;
 (*result)[20] = &_f_2020_;
 (*result)[21] = &_f_2021_;
 (*result)[22] = &_f_2022_;
 (*result)[23] = &_f_2023_;
 (*result)[24] = &_f_2024_;
 (*result)[25] = &_f_2025_;
 (*result)[26] = &_f_2026_;
 (*result)[27] = &_f_2027_;
 (*result)[28] = &_f_2028_;
 (*result)[29] = &_f_2029_;
 (*result)[30] = &_f_2030_;
 (*result)[31] = &_f_2031_;
 (*result)[32] = &_f_2032_;
 (*result)[33] = &_f_2033_;
 (*result)[34] = &_f_2034_;
 (*result)[35] = &_f_2035_;
 (*result)[36] = &_f_2036_;
 (*result)[37] = &_f_2037_;
 (*result)[38] = &_f_2038_;
 (*result)[39] = &_f_2039_;
 (*result)[40] = &_f_2040_;
 (*result)[41] = &_f_2041_;
 (*result)[42] = &_f_2042_;
 (*result)[43] = &_f_2043_;
 (*result)[44] = &_f_2044_;
 (*result)[45] = &_f_2045_;
 (*result)[46] = &_f_2046_;
 (*result)[47] = &_f_2047_;
 (*result)[48] = &_f_2048_;
 (*result)[49] = &_f_2049_;
 (*result)[50] = &_f_2050_;
 (*result)[51] = &_f_2051_;
 (*result)[52] = &_f_2052_;
 (*result)[53] = &_f_2053_;
 (*result)[54] = &_f_2054_;
 (*result)[55] = &_f_2055_;
 (*result)[56] = &_f_2056_;
 (*result)[57] = &_f_2057_;
 (*result)[58] = &_f_2058_;
 (*result)[59] = &_f_2059_;
 (*result)[60] = &_f_2060_;
 (*result)[61] = &_f_2061_;
 (*result)[62] = &_f_2062_;
 (*result)[63] = &_f_2063_;
 (*result)[64] = &_f_2064_;
 (*result)[65] = &_f_2065_;
 (*result)[66] = &_f_2066_;
 (*result)[67] = &_f_2067_;
 (*result)[68] = &_f_2068_;
 (*result)[69] = &_f_2069_;
 (*result)[70] = &_f_2070_;
 (*result)[71] = &_f_2071_;
 (*result)[72] = &_f_2072_;
 (*result)[73] = &_f_2073_;
 (*result)[74] = &_f_2074_;
 (*result)[75] = &_f_2075_;
 (*result)[76] = &_f_2076_;
 (*result)[77] = &_f_2077_;
 (*result)[78] = &_f_2078_;
 (*result)[79] = &_f_2079_;
 (*result)[80] = &_f_2080_;
 (*result)[81] = &_f_2081_;
 (*result)[82] = &_f_2082_;
 (*result)[83] = &_f_2083_;
 (*result)[84] = &_f_2084_;
 (*result)[85] = &_f_2085_;
 (*result)[86] = &_f_2086_;
 (*result)[87] = &_f_2087_;
 (*result)[88] = &_f_2088_;
 (*result)[89] = &_f_2089_;
 (*result)[90] = &_f_2090_;
 (*result)[91] = &_f_2091_;
 (*result)[92] = &_f_2092_;
 (*result)[93] = &_f_2093_;
 (*result)[94] = &_f_2094_;
 (*result)[95] = &_f_2095_;
 (*result)[96] = &_f_2096_;
 (*result)[97] = &_f_2097_;
 (*result)[98] = &_f_2098_;
 (*result)[99] = &_f_2099_;
 (*result)[100] = &_f_2100_;
 (*result)[101] = &_f_2101_;
 (*result)[102] = &_f_2102_;
 (*result)[103] = &_f_2103_;
 (*result)[104] = &_f_2104_;
 (*result)[105] = &_f_2105_;
 (*result)[106] = &_f_2106_;
 (*result)[107] = &_f_2107_;
 (*result)[108] = &_f_2108_;
 (*result)[109] = &_f_2109_;
 (*result)[110] = &_f_2110_;
 (*result)[111] = &_f_2111_;
 (*result)[112] = &_f_2112_;
 (*result)[113] = &_f_2113_;
 (*result)[114] = &_f_2114_;
 (*result)[115] = &_f_2115_;
 (*result)[116] = &_f_2116_;
 (*result)[117] = &_f_2117_;
 (*result)[118] = &_f_2118_;
 (*result)[119] = &_f_2119_;
 (*result)[120] = &_f_2120_;
 (*result)[121] = &_f_2121_;
 (*result)[122] = &_f_2122_;
 (*result)[123] = &_f_2123_;
 (*result)[124] = &_f_2124_;
 (*result)[125] = &_f_2125_;
 (*result)[126] = &_f_2126_;
 (*result)[127] = &_f_2127_;
 (*result)[128] = &_f_2128_;
 (*result)[129] = &_f_2129_;
 (*result)[130] = &_f_2130_;
 (*result)[131] = &_f_2131_;
 (*result)[132] = &_f_2132_;
 (*result)[133] = &_f_2133_;
 (*result)[134] = &_f_2134_;
 (*result)[135] = &_f_2135_;
 (*result)[136] = &_f_2136_;
 (*result)[137] = &_f_2137_;
 (*result)[138] = &_f_2138_;
 (*result)[139] = &_f_2139_;
 (*result)[140] = &_f_2140_;
 (*result)[141] = &_f_2141_;
 (*result)[142] = &_f_2142_;
 (*result)[143] = &_f_2143_;
 (*result)[144] = &_f_2144_;
 (*result)[145] = &_f_2145_;
 (*result)[146] = &_f_2146_;
 (*result)[147] = &_f_2147_;
 (*result)[148] = &_f_2148_;
 (*result)[149] = &_f_2149_;
 (*result)[150] = &_f_2150_;
 (*result)[151] = &_f_2151_;
 (*result)[152] = &_f_2152_;
 (*result)[153] = &_f_2153_;
 (*result)[154] = &_f_2154_;
 (*result)[155] = &_f_2155_;
 (*result)[156] = &_f_2156_;
 (*result)[157] = &_f_2157_;
 (*result)[158] = &_f_2158_;
 (*result)[159] = &_f_2159_;
 (*result)[160] = &_f_2160_;
 (*result)[161] = &_f_2161_;
 (*result)[162] = &_f_2162_;
 (*result)[163] = &_f_2163_;
 (*result)[164] = &_f_2164_;
 (*result)[165] = &_f_2165_;
 (*result)[166] = &_f_2166_;
 (*result)[167] = &_f_2167_;
 (*result)[168] = &_f_2168_;
 (*result)[169] = &_f_2169_;
 (*result)[170] = &_f_2170_;
 (*result)[171] = &_f_2171_;
 (*result)[172] = &_f_2172_;
 (*result)[173] = &_f_2173_;
 (*result)[174] = &_f_2174_;
 (*result)[175] = &_f_2175_;
 (*result)[176] = &_f_2176_;
 (*result)[177] = &_f_2177_;
 (*result)[178] = &_f_2178_;
 (*result)[179] = &_f_2179_;
 (*result)[180] = &_f_2180_;
 (*result)[181] = &_f_2181_;
 (*result)[182] = &_f_2182_;
 (*result)[183] = &_f_2183_;
 (*result)[184] = &_f_2184_;
 (*result)[185] = &_f_2185_;
 (*result)[186] = &_f_2186_;
 (*result)[187] = &_f_2187_;
 (*result)[188] = &_f_2188_;
 (*result)[189] = &_f_2189_;
 (*result)[190] = &_f_2190_;
 (*result)[191] = &_f_2191_;
 (*result)[192] = &_f_2192_;
 (*result)[193] = &_f_2193_;
 (*result)[194] = &_f_2194_;
 (*result)[195] = &_f_2195_;
 (*result)[196] = &_f_2196_;
 (*result)[197] = &_f_2197_;
 (*result)[198] = &_f_2198_;
 (*result)[199] = &_f_2199_;
 (*result)[200] = &_f_2200_;
 (*result)[201] = &_f_2201_;
 (*result)[202] = &_f_2202_;
 (*result)[203] = &_f_2203_;
 (*result)[204] = &_f_2204_;
 (*result)[205] = &_f_2205_;
 (*result)[206] = &_f_2206_;
 (*result)[207] = &_f_2207_;
 (*result)[208] = &_f_2208_;
 (*result)[209] = &_f_2209_;
 (*result)[210] = &_f_2210_;
 (*result)[211] = &_f_2211_;
 (*result)[212] = &_f_2212_;
 (*result)[213] = &_f_2213_;
 (*result)[214] = &_f_2214_;
 (*result)[215] = &_f_2215_;
 (*result)[216] = &_f_2216_;
 (*result)[217] = &_f_2217_;
 (*result)[218] = &_f_2218_;
 (*result)[219] = &_f_2219_;
 (*result)[220] = &_f_2220_;
 (*result)[221] = &_f_2221_;
 (*result)[222] = &_f_2222_;
 (*result)[223] = &_f_2223_;
 (*result)[224] = &_f_2224_;
 (*result)[225] = &_f_2225_;
 (*result)[226] = &_f_2226_;
 (*result)[227] = &_f_2227_;
 (*result)[228] = &_f_2228_;
 (*result)[229] = &_f_2229_;
 (*result)[230] = &_f_2230_;
 (*result)[231] = &_f_2231_;
 (*result)[232] = &_f_2232_;
 (*result)[233] = &_f_2233_;
 (*result)[234] = &_f_2234_;
 (*result)[235] = &_f_2235_;
 (*result)[236] = &_f_2236_;
 (*result)[237] = &_f_2237_;
 (*result)[238] = &_f_2238_;
 (*result)[239] = &_f_2239_;
 (*result)[240] = &_f_2240_;
 (*result)[241] = &_f_2241_;
 (*result)[242] = &_f_2242_;
 (*result)[243] = &_f_2243_;
 (*result)[244] = &_f_2244_;
 (*result)[245] = &_f_2245_;
 (*result)[246] = &_f_2246_;
 (*result)[247] = &_f_2247_;
 (*result)[248] = &_f_2248_;
 (*result)[249] = &_f_2249_;
 (*result)[250] = &_f_2250_;
 (*result)[251] = &_f_2251_;
 (*result)[252] = &_f_2252_;
 (*result)[253] = &_f_2253_;
 (*result)[254] = &_f_2254_;
 (*result)[255] = &_f_2255_;
 (*result)[256] = &_f_2256_;
 (*result)[257] = &_f_2257_;
 (*result)[258] = &_f_2258_;
 (*result)[259] = &_f_2259_;
 (*result)[260] = &_f_2260_;
 (*result)[261] = &_f_2261_;
 (*result)[262] = &_f_2262_;
 (*result)[263] = &_f_2263_;
 (*result)[264] = &_f_2264_;
 (*result)[265] = &_f_2265_;
 (*result)[266] = &_f_2266_;
 (*result)[267] = &_f_2267_;
 (*result)[268] = &_f_2268_;
 (*result)[269] = &_f_2269_;
 (*result)[270] = &_f_2270_;
 (*result)[271] = &_f_2271_;
 (*result)[272] = &_f_2272_;
 (*result)[273] = &_f_2273_;
 (*result)[274] = &_f_2274_;
 (*result)[275] = &_f_2275_;
 (*result)[276] = &_f_2276_;
 (*result)[277] = &_f_2277_;
 (*result)[278] = &_f_2278_;
 (*result)[279] = &_f_2279_;
 (*result)[280] = &_f_2280_;
 (*result)[281] = &_f_2281_;
 (*result)[282] = &_f_2282_;
 (*result)[283] = &_f_2283_;
 (*result)[284] = &_f_2284_;
 (*result)[285] = &_f_2285_;
 (*result)[286] = &_f_2286_;
 (*result)[287] = &_f_2287_;
 (*result)[288] = &_f_2288_;
 (*result)[289] = &_f_2289_;
 (*result)[290] = &_f_2290_;
 (*result)[291] = &_f_2291_;
 (*result)[292] = &_f_2292_;
 (*result)[293] = &_f_2293_;
 (*result)[294] = &_f_2294_;
 (*result)[295] = &_f_2295_;
 (*result)[296] = &_f_2296_;
 (*result)[297] = &_f_2297_;
 (*result)[298] = &_f_2298_;
 (*result)[299] = &_f_2299_;
 (*result)[300] = &_f_2300_;
 (*result)[301] = &_f_2301_;
 (*result)[302] = &_f_2302_;
 (*result)[303] = &_f_2303_;
 (*result)[304] = &_f_2304_;
 (*result)[305] = &_f_2305_;
 (*result)[306] = &_f_2306_;
 (*result)[307] = &_f_2307_;
 (*result)[308] = &_f_2308_;
 (*result)[309] = &_f_2309_;
 (*result)[310] = &_f_2310_;
 (*result)[311] = &_f_2311_;
 (*result)[312] = &_f_2312_;
 (*result)[313] = &_f_2313_;
 (*result)[314] = &_f_2314_;
 (*result)[315] = &_f_2315_;
 (*result)[316] = &_f_2316_;
 (*result)[317] = &_f_2317_;
 (*result)[318] = &_f_2318_;
 (*result)[319] = &_f_2319_;
 (*result)[320] = &_f_2320_;
 (*result)[321] = &_f_2321_;
 (*result)[322] = &_f_2322_;
 (*result)[323] = &_f_2323_;
 (*result)[324] = &_f_2324_;
 (*result)[325] = &_f_2325_;
 (*result)[326] = &_f_2326_;
 (*result)[327] = &_f_2327_;
 (*result)[328] = &_f_2328_;
 (*result)[329] = &_f_2329_;
 (*result)[330] = &_f_2330_;
 (*result)[331] = &_f_2331_;
 (*result)[332] = &_f_2332_;
 (*result)[333] = &_f_2333_;
 (*result)[334] = &_f_2334_;
 (*result)[335] = &_f_2335_;
 (*result)[336] = &_f_2336_;
 (*result)[337] = &_f_2337_;
 (*result)[338] = &_f_2338_;
 (*result)[339] = &_f_2339_;
 (*result)[340] = &_f_2340_;
 (*result)[341] = &_f_2341_;
 (*result)[342] = &_f_2342_;
 (*result)[343] = &_f_2343_;
 (*result)[344] = &_f_2344_;
 (*result)[345] = &_f_2345_;
 (*result)[346] = &_f_2346_;
 (*result)[347] = &_f_2347_;
 (*result)[348] = &_f_2348_;
 (*result)[349] = &_f_2349_;
 (*result)[350] = &_f_2350_;
 (*result)[351] = &_f_2351_;
 (*result)[352] = &_f_2352_;
 (*result)[353] = &_f_2353_;
 (*result)[354] = &_f_2354_;
 (*result)[355] = &_f_2355_;
 (*result)[356] = &_f_2356_;
 (*result)[357] = &_f_2357_;
 (*result)[358] = &_f_2358_;
 (*result)[359] = &_f_2359_;
 (*result)[360] = &_f_2360_;
 (*result)[361] = &_f_2361_;
 (*result)[362] = &_f_2362_;
 (*result)[363] = &_f_2363_;
 (*result)[364] = &_f_2364_;
 (*result)[365] = &_f_2365_;
 (*result)[366] = &_f_2366_;
 (*result)[367] = &_f_2367_;
 (*result)[368] = &_f_2368_;
 (*result)[369] = &_f_2369_;
 (*result)[370] = &_f_2370_;
 (*result)[371] = &_f_2371_;
 (*result)[372] = &_f_2372_;
 (*result)[373] = &_f_2373_;
 (*result)[374] = &_f_2374_;
 (*result)[375] = &_f_2375_;
 (*result)[376] = &_f_2376_;
 (*result)[377] = &_f_2377_;
 (*result)[378] = &_f_2378_;
 (*result)[379] = &_f_2379_;
 (*result)[380] = &_f_2380_;
 (*result)[381] = &_f_2381_;
 (*result)[382] = &_f_2382_;
 (*result)[383] = &_f_2383_;
 (*result)[384] = &_f_2384_;
 (*result)[385] = &_f_2385_;
 (*result)[386] = &_f_2386_;
 (*result)[387] = &_f_2387_;
 (*result)[388] = &_f_2388_;
 (*result)[389] = &_f_2389_;
 (*result)[390] = &_f_2390_;
 (*result)[391] = &_f_2391_;
 (*result)[392] = &_f_2392_;
 (*result)[393] = &_f_2393_;
 (*result)[394] = &_f_2394_;
 (*result)[395] = &_f_2395_;
 (*result)[396] = &_f_2396_;
 (*result)[397] = &_f_2397_;
 (*result)[398] = &_f_2398_;
 (*result)[399] = &_f_2399_;
 (*result)[400] = &_f_2400_;
 (*result)[401] = &_f_2401_;
 (*result)[402] = &_f_2402_;
 (*result)[403] = &_f_2403_;
 (*result)[404] = &_f_2404_;
 (*result)[405] = &_f_2405_;
 (*result)[406] = &_f_2406_;
 (*result)[407] = &_f_2407_;
 (*result)[408] = &_f_2408_;
 (*result)[409] = &_f_2409_;
 (*result)[410] = &_f_2410_;
 (*result)[411] = &_f_2411_;
 (*result)[412] = &_f_2412_;
 (*result)[413] = &_f_2413_;
 (*result)[414] = &_f_2414_;
 (*result)[415] = &_f_2415_;
 (*result)[416] = &_f_2416_;
 (*result)[417] = &_f_2417_;
 (*result)[418] = &_f_2418_;
 (*result)[419] = &_f_2419_;
 (*result)[420] = &_f_2420_;
 (*result)[421] = &_f_2421_;
 (*result)[422] = &_f_2422_;
 (*result)[423] = &_f_2423_;
 (*result)[424] = &_f_2424_;
 (*result)[425] = &_f_2425_;
 (*result)[426] = &_f_2426_;
 (*result)[427] = &_f_2427_;
 (*result)[428] = &_f_2428_;
 (*result)[429] = &_f_2429_;
 (*result)[430] = &_f_2430_;
 (*result)[431] = &_f_2431_;
 (*result)[432] = &_f_2432_;
 (*result)[433] = &_f_2433_;
 (*result)[434] = &_f_2434_;
 (*result)[435] = &_f_2435_;
 (*result)[436] = &_f_2436_;
 (*result)[437] = &_f_2437_;
 (*result)[438] = &_f_2438_;
 (*result)[439] = &_f_2439_;
 (*result)[440] = &_f_2440_;
 (*result)[441] = &_f_2441_;
 (*result)[442] = &_f_2442_;
 (*result)[443] = &_f_2443_;
 (*result)[444] = &_f_2444_;
 (*result)[445] = &_f_2445_;
 (*result)[446] = &_f_2446_;
 (*result)[447] = &_f_2447_;
 (*result)[448] = &_f_2448_;
 (*result)[449] = &_f_2449_;
 (*result)[450] = &_f_2450_;
 (*result)[451] = &_f_2451_;
 (*result)[452] = &_f_2452_;
 (*result)[453] = &_f_2453_;
 (*result)[454] = &_f_2454_;
 (*result)[455] = &_f_2455_;
 (*result)[456] = &_f_2456_;
 (*result)[457] = &_f_2457_;
 (*result)[458] = &_f_2458_;
 (*result)[459] = &_f_2459_;
 (*result)[460] = &_f_2460_;
 (*result)[461] = &_f_2461_;
 (*result)[462] = &_f_2462_;
 (*result)[463] = &_f_2463_;
 (*result)[464] = &_f_2464_;
 (*result)[465] = &_f_2465_;
 (*result)[466] = &_f_2466_;
 (*result)[467] = &_f_2467_;
 (*result)[468] = &_f_2468_;
 (*result)[469] = &_f_2469_;
 (*result)[470] = &_f_2470_;
 (*result)[471] = &_f_2471_;
 (*result)[472] = &_f_2472_;
 (*result)[473] = &_f_2473_;
 (*result)[474] = &_f_2474_;
 (*result)[475] = &_f_2475_;
 (*result)[476] = &_f_2476_;
 (*result)[477] = &_f_2477_;
 (*result)[478] = &_f_2478_;
 (*result)[479] = &_f_2479_;
 (*result)[480] = &_f_2480_;
 (*result)[481] = &_f_2481_;
 (*result)[482] = &_f_2482_;
 (*result)[483] = &_f_2483_;
 (*result)[484] = &_f_2484_;
 (*result)[485] = &_f_2485_;
 (*result)[486] = &_f_2486_;
 (*result)[487] = &_f_2487_;
 (*result)[488] = &_f_2488_;
 (*result)[489] = &_f_2489_;
 (*result)[490] = &_f_2490_;
 (*result)[491] = &_f_2491_;
 (*result)[492] = &_f_2492_;
 (*result)[493] = &_f_2493_;
 (*result)[494] = &_f_2494_;
 (*result)[495] = &_f_2495_;
 (*result)[496] = &_f_2496_;
 (*result)[497] = &_f_2497_;
 (*result)[498] = &_f_2498_;
 (*result)[499] = &_f_2499_;
 (*result)[500] = &_f_2500_;
 (*result)[501] = &_f_2501_;
 (*result)[502] = &_f_2502_;
 (*result)[503] = &_f_2503_;
 (*result)[504] = &_f_2504_;
 (*result)[505] = &_f_2505_;
 (*result)[506] = &_f_2506_;
 (*result)[507] = &_f_2507_;
 (*result)[508] = &_f_2508_;
 (*result)[509] = &_f_2509_;
 (*result)[510] = &_f_2510_;
 (*result)[511] = &_f_2511_;
 (*result)[512] = &_f_2512_;
 (*result)[513] = &_f_2513_;
 (*result)[514] = &_f_2514_;
 (*result)[515] = &_f_2515_;
 (*result)[516] = &_f_2516_;
 (*result)[517] = &_f_2517_;
 (*result)[518] = &_f_2518_;
 (*result)[519] = &_f_2519_;
 (*result)[520] = &_f_2520_;
 (*result)[521] = &_f_2521_;
 (*result)[522] = &_f_2522_;
 (*result)[523] = &_f_2523_;
 (*result)[524] = &_f_2524_;
 (*result)[525] = &_f_2525_;
 (*result)[526] = &_f_2526_;
 (*result)[527] = &_f_2527_;
 (*result)[528] = &_f_2528_;
 (*result)[529] = &_f_2529_;
 (*result)[530] = &_f_2530_;
 (*result)[531] = &_f_2531_;
 (*result)[532] = &_f_2532_;
 (*result)[533] = &_f_2533_;
 (*result)[534] = &_f_2534_;
 (*result)[535] = &_f_2535_;
 (*result)[536] = &_f_2536_;
 (*result)[537] = &_f_2537_;
 (*result)[538] = &_f_2538_;
 (*result)[539] = &_f_2539_;
 (*result)[540] = &_f_2540_;
 (*result)[541] = &_f_2541_;
 (*result)[542] = &_f_2542_;
 (*result)[543] = &_f_2543_;
 (*result)[544] = &_f_2544_;
 (*result)[545] = &_f_2545_;
 (*result)[546] = &_f_2546_;
 (*result)[547] = &_f_2547_;
 (*result)[548] = &_f_2548_;
 (*result)[549] = &_f_2549_;
 (*result)[550] = &_f_2550_;
 (*result)[551] = &_f_2551_;
 (*result)[552] = &_f_2552_;
 (*result)[553] = &_f_2553_;
 (*result)[554] = &_f_2554_;
 (*result)[555] = &_f_2555_;
 (*result)[556] = &_f_2556_;
 (*result)[557] = &_f_2557_;
 (*result)[558] = &_f_2558_;
 (*result)[559] = &_f_2559_;
 (*result)[560] = &_f_2560_;
 (*result)[561] = &_f_2561_;
 (*result)[562] = &_f_2562_;
 (*result)[563] = &_f_2563_;
 (*result)[564] = &_f_2564_;
 (*result)[565] = &_f_2565_;
 (*result)[566] = &_f_2566_;
 (*result)[567] = &_f_2567_;
 (*result)[568] = &_f_2568_;
 (*result)[569] = &_f_2569_;
 (*result)[570] = &_f_2570_;
 (*result)[571] = &_f_2571_;
 (*result)[572] = &_f_2572_;
 (*result)[573] = &_f_2573_;
 (*result)[574] = &_f_2574_;
 (*result)[575] = &_f_2575_;
 (*result)[576] = &_f_2576_;
 (*result)[577] = &_f_2577_;
 (*result)[578] = &_f_2578_;
 (*result)[579] = &_f_2579_;
 (*result)[580] = &_f_2580_;
 (*result)[581] = &_f_2581_;
 (*result)[582] = &_f_2582_;
 (*result)[583] = &_f_2583_;
 (*result)[584] = &_f_2584_;
 (*result)[585] = &_f_2585_;
 (*result)[586] = &_f_2586_;
 (*result)[587] = &_f_2587_;
 (*result)[588] = &_f_2588_;
 (*result)[589] = &_f_2589_;
 (*result)[590] = &_f_2590_;
 (*result)[591] = &_f_2591_;
 (*result)[592] = &_f_2592_;
 (*result)[593] = &_f_2593_;
 (*result)[594] = &_f_2594_;
 (*result)[595] = &_f_2595_;
 (*result)[596] = &_f_2596_;
 (*result)[597] = &_f_2597_;
 (*result)[598] = &_f_2598_;
 (*result)[599] = &_f_2599_;
 (*result)[600] = &_f_2600_;
 (*result)[601] = &_f_2601_;
 (*result)[602] = &_f_2602_;
 (*result)[603] = &_f_2603_;
 (*result)[604] = &_f_2604_;
 (*result)[605] = &_f_2605_;
 (*result)[606] = &_f_2606_;
 (*result)[607] = &_f_2607_;
 (*result)[608] = &_f_2608_;
 (*result)[609] = &_f_2609_;
 (*result)[610] = &_f_2610_;
 (*result)[611] = &_f_2611_;
 (*result)[612] = &_f_2612_;
 (*result)[613] = &_f_2613_;
 (*result)[614] = &_f_2614_;
 (*result)[615] = &_f_2615_;
 (*result)[616] = &_f_2616_;
 (*result)[617] = &_f_2617_;
 (*result)[618] = &_f_2618_;
 (*result)[619] = &_f_2619_;
 (*result)[620] = &_f_2620_;
 (*result)[621] = &_f_2621_;
 (*result)[622] = &_f_2622_;
 (*result)[623] = &_f_2623_;
 (*result)[624] = &_f_2624_;
 (*result)[625] = &_f_2625_;
 (*result)[626] = &_f_2626_;
 (*result)[627] = &_f_2627_;
 (*result)[628] = &_f_2628_;
 (*result)[629] = &_f_2629_;
 (*result)[630] = &_f_2630_;
 (*result)[631] = &_f_2631_;
 (*result)[632] = &_f_2632_;
 (*result)[633] = &_f_2633_;
 (*result)[634] = &_f_2634_;
 (*result)[635] = &_f_2635_;
 (*result)[636] = &_f_2636_;
 (*result)[637] = &_f_2637_;
 (*result)[638] = &_f_2638_;
 (*result)[639] = &_f_2639_;
 (*result)[640] = &_f_2640_;
 (*result)[641] = &_f_2641_;
 (*result)[642] = &_f_2642_;
 (*result)[643] = &_f_2643_;
 (*result)[644] = &_f_2644_;
 (*result)[645] = &_f_2645_;
 (*result)[646] = &_f_2646_;
 (*result)[647] = &_f_2647_;
 (*result)[648] = &_f_2648_;
 (*result)[649] = &_f_2649_;
 (*result)[650] = &_f_2650_;
 (*result)[651] = &_f_2651_;
 (*result)[652] = &_f_2652_;
 (*result)[653] = &_f_2653_;
 (*result)[654] = &_f_2654_;
 (*result)[655] = &_f_2655_;
 (*result)[656] = &_f_2656_;
 (*result)[657] = &_f_2657_;
 (*result)[658] = &_f_2658_;
 (*result)[659] = &_f_2659_;
 (*result)[660] = &_f_2660_;
 (*result)[661] = &_f_2661_;
 (*result)[662] = &_f_2662_;
 (*result)[663] = &_f_2663_;
 (*result)[664] = &_f_2664_;
 (*result)[665] = &_f_2665_;
 (*result)[666] = &_f_2666_;
 (*result)[667] = &_f_2667_;
 (*result)[668] = &_f_2668_;
 (*result)[669] = &_f_2669_;
 (*result)[670] = &_f_2670_;
 (*result)[671] = &_f_2671_;
 (*result)[672] = &_f_2672_;
 (*result)[673] = &_f_2673_;
 (*result)[674] = &_f_2674_;
 (*result)[675] = &_f_2675_;
 (*result)[676] = &_f_2676_;
 (*result)[677] = &_f_2677_;
 (*result)[678] = &_f_2678_;
 (*result)[679] = &_f_2679_;
 (*result)[680] = &_f_2680_;
 (*result)[681] = &_f_2681_;
 (*result)[682] = &_f_2682_;
 (*result)[683] = &_f_2683_;
 (*result)[684] = &_f_2684_;
 (*result)[685] = &_f_2685_;
 (*result)[686] = &_f_2686_;
 (*result)[687] = &_f_2687_;
 (*result)[688] = &_f_2688_;
 (*result)[689] = &_f_2689_;
 (*result)[690] = &_f_2690_;
 (*result)[691] = &_f_2691_;
 (*result)[692] = &_f_2692_;
 (*result)[693] = &_f_2693_;
 (*result)[694] = &_f_2694_;
 (*result)[695] = &_f_2695_;
 (*result)[696] = &_f_2696_;
 (*result)[697] = &_f_2697_;
 (*result)[698] = &_f_2698_;
 (*result)[699] = &_f_2699_;
 (*result)[700] = &_f_2700_;
 (*result)[701] = &_f_2701_;
 (*result)[702] = &_f_2702_;
 (*result)[703] = &_f_2703_;
 (*result)[704] = &_f_2704_;
 (*result)[705] = &_f_2705_;
 (*result)[706] = &_f_2706_;
 (*result)[707] = &_f_2707_;
 (*result)[708] = &_f_2708_;
 (*result)[709] = &_f_2709_;
 (*result)[710] = &_f_2710_;
 (*result)[711] = &_f_2711_;
 (*result)[712] = &_f_2712_;
 (*result)[713] = &_f_2713_;
 (*result)[714] = &_f_2714_;
 (*result)[715] = &_f_2715_;
 (*result)[716] = &_f_2716_;
 (*result)[717] = &_f_2717_;
 (*result)[718] = &_f_2718_;
 (*result)[719] = &_f_2719_;
 (*result)[720] = &_f_2720_;
 (*result)[721] = &_f_2721_;
 (*result)[722] = &_f_2722_;
 (*result)[723] = &_f_2723_;
 (*result)[724] = &_f_2724_;
 (*result)[725] = &_f_2725_;
 (*result)[726] = &_f_2726_;
 (*result)[727] = &_f_2727_;
 (*result)[728] = &_f_2728_;
 (*result)[729] = &_f_2729_;
 (*result)[730] = &_f_2730_;
 (*result)[731] = &_f_2731_;
 (*result)[732] = &_f_2732_;
 (*result)[733] = &_f_2733_;
 (*result)[734] = &_f_2734_;
 (*result)[735] = &_f_2735_;
 (*result)[736] = &_f_2736_;
 (*result)[737] = &_f_2737_;
 (*result)[738] = &_f_2738_;
 (*result)[739] = &_f_2739_;
 (*result)[740] = &_f_2740_;
 (*result)[741] = &_f_2741_;
 (*result)[742] = &_f_2742_;
 (*result)[743] = &_f_2743_;
 (*result)[744] = &_f_2744_;
 (*result)[745] = &_f_2745_;
 (*result)[746] = &_f_2746_;
 (*result)[747] = &_f_2747_;
 (*result)[748] = &_f_2748_;
 (*result)[749] = &_f_2749_;
 (*result)[750] = &_f_2750_;
 (*result)[751] = &_f_2751_;
 (*result)[752] = &_f_2752_;
 (*result)[753] = &_f_2753_;
 (*result)[754] = &_f_2754_;
 (*result)[755] = &_f_2755_;
 (*result)[756] = &_f_2756_;
 (*result)[757] = &_f_2757_;
 (*result)[758] = &_f_2758_;
 (*result)[759] = &_f_2759_;
 (*result)[760] = &_f_2760_;
 (*result)[761] = &_f_2761_;
 (*result)[762] = &_f_2762_;
 (*result)[763] = &_f_2763_;
 (*result)[764] = &_f_2764_;
 (*result)[765] = &_f_2765_;
 (*result)[766] = &_f_2766_;
 (*result)[767] = &_f_2767_;
 (*result)[768] = &_f_2768_;
 (*result)[769] = &_f_2769_;
 (*result)[770] = &_f_2770_;
 (*result)[771] = &_f_2771_;
 (*result)[772] = &_f_2772_;
 (*result)[773] = &_f_2773_;
 (*result)[774] = &_f_2774_;
 (*result)[775] = &_f_2775_;
 (*result)[776] = &_f_2776_;
 (*result)[777] = &_f_2777_;
 (*result)[778] = &_f_2778_;
 (*result)[779] = &_f_2779_;
 (*result)[780] = &_f_2780_;
 (*result)[781] = &_f_2781_;
 (*result)[782] = &_f_2782_;
 (*result)[783] = &_f_2783_;
 (*result)[784] = &_f_2784_;
 (*result)[785] = &_f_2785_;
 (*result)[786] = &_f_2786_;
 (*result)[787] = &_f_2787_;
 (*result)[788] = &_f_2788_;
 (*result)[789] = &_f_2789_;
 (*result)[790] = &_f_2790_;
 (*result)[791] = &_f_2791_;
 (*result)[792] = &_f_2792_;
 (*result)[793] = &_f_2793_;
 (*result)[794] = &_f_2794_;
 (*result)[795] = &_f_2795_;
 (*result)[796] = &_f_2796_;
 (*result)[797] = &_f_2797_;
 (*result)[798] = &_f_2798_;
 (*result)[799] = &_f_2799_;
 (*result)[800] = &_f_2800_;
 (*result)[801] = &_f_2801_;
 (*result)[802] = &_f_2802_;
 (*result)[803] = &_f_2803_;
 (*result)[804] = &_f_2804_;
 (*result)[805] = &_f_2805_;
 (*result)[806] = &_f_2806_;
 (*result)[807] = &_f_2807_;
 (*result)[808] = &_f_2808_;
 (*result)[809] = &_f_2809_;
 (*result)[810] = &_f_2810_;
 (*result)[811] = &_f_2811_;
 (*result)[812] = &_f_2812_;
 (*result)[813] = &_f_2813_;
 (*result)[814] = &_f_2814_;
 (*result)[815] = &_f_2815_;
 (*result)[816] = &_f_2816_;
 (*result)[817] = &_f_2817_;
 (*result)[818] = &_f_2818_;
 (*result)[819] = &_f_2819_;
 (*result)[820] = &_f_2820_;
 (*result)[821] = &_f_2821_;
 (*result)[822] = &_f_2822_;
 (*result)[823] = &_f_2823_;
 (*result)[824] = &_f_2824_;
 (*result)[825] = &_f_2825_;
 (*result)[826] = &_f_2826_;
 (*result)[827] = &_f_2827_;
 (*result)[828] = &_f_2828_;
 (*result)[829] = &_f_2829_;
 (*result)[830] = &_f_2830_;
 (*result)[831] = &_f_2831_;
 (*result)[832] = &_f_2832_;
 (*result)[833] = &_f_2833_;
 (*result)[834] = &_f_2834_;
 (*result)[835] = &_f_2835_;
 (*result)[836] = &_f_2836_;
 (*result)[837] = &_f_2837_;
 (*result)[838] = &_f_2838_;
 (*result)[839] = &_f_2839_;
 (*result)[840] = &_f_2840_;
 (*result)[841] = &_f_2841_;
 (*result)[842] = &_f_2842_;
 (*result)[843] = &_f_2843_;
 (*result)[844] = &_f_2844_;
 (*result)[845] = &_f_2845_;
 (*result)[846] = &_f_2846_;
 (*result)[847] = &_f_2847_;
 (*result)[848] = &_f_2848_;
 (*result)[849] = &_f_2849_;
 (*result)[850] = &_f_2850_;
 (*result)[851] = &_f_2851_;
 (*result)[852] = &_f_2852_;
 (*result)[853] = &_f_2853_;
 (*result)[854] = &_f_2854_;
 (*result)[855] = &_f_2855_;
 (*result)[856] = &_f_2856_;
 (*result)[857] = &_f_2857_;
 (*result)[858] = &_f_2858_;
 (*result)[859] = &_f_2859_;
 (*result)[860] = &_f_2860_;
 (*result)[861] = &_f_2861_;
 (*result)[862] = &_f_2862_;
 (*result)[863] = &_f_2863_;
 (*result)[864] = &_f_2864_;
 (*result)[865] = &_f_2865_;
 (*result)[866] = &_f_2866_;
 (*result)[867] = &_f_2867_;
 (*result)[868] = &_f_2868_;
 (*result)[869] = &_f_2869_;
 (*result)[870] = &_f_2870_;
 (*result)[871] = &_f_2871_;
 (*result)[872] = &_f_2872_;
 (*result)[873] = &_f_2873_;
 (*result)[874] = &_f_2874_;
 (*result)[875] = &_f_2875_;
 (*result)[876] = &_f_2876_;
 (*result)[877] = &_f_2877_;
 (*result)[878] = &_f_2878_;
 (*result)[879] = &_f_2879_;
 (*result)[880] = &_f_2880_;
 (*result)[881] = &_f_2881_;
 (*result)[882] = &_f_2882_;
 (*result)[883] = &_f_2883_;
 (*result)[884] = &_f_2884_;
 (*result)[885] = &_f_2885_;
 (*result)[886] = &_f_2886_;
 (*result)[887] = &_f_2887_;
 (*result)[888] = &_f_2888_;
 (*result)[889] = &_f_2889_;
 (*result)[890] = &_f_2890_;
 (*result)[891] = &_f_2891_;
 (*result)[892] = &_f_2892_;
 (*result)[893] = &_f_2893_;
 (*result)[894] = &_f_2894_;
 (*result)[895] = &_f_2895_;
 (*result)[896] = &_f_2896_;
 (*result)[897] = &_f_2897_;
 (*result)[898] = &_f_2898_;
 (*result)[899] = &_f_2899_;
 (*result)[900] = &_f_2900_;
 (*result)[901] = &_f_2901_;
 (*result)[902] = &_f_2902_;
 (*result)[903] = &_f_2903_;
 (*result)[904] = &_f_2904_;
 (*result)[905] = &_f_2905_;
 (*result)[906] = &_f_2906_;
 (*result)[907] = &_f_2907_;
 (*result)[908] = &_f_2908_;
 (*result)[909] = &_f_2909_;
 (*result)[910] = &_f_2910_;
 (*result)[911] = &_f_2911_;
 (*result)[912] = &_f_2912_;
 (*result)[913] = &_f_2913_;
 (*result)[914] = &_f_2914_;
 (*result)[915] = &_f_2915_;
 (*result)[916] = &_f_2916_;
 (*result)[917] = &_f_2917_;
 (*result)[918] = &_f_2918_;
 (*result)[919] = &_f_2919_;
 (*result)[920] = &_f_2920_;
 (*result)[921] = &_f_2921_;
 (*result)[922] = &_f_2922_;
 (*result)[923] = &_f_2923_;
 (*result)[924] = &_f_2924_;
 (*result)[925] = &_f_2925_;
 (*result)[926] = &_f_2926_;
 (*result)[927] = &_f_2927_;
 (*result)[928] = &_f_2928_;
 (*result)[929] = &_f_2929_;
 (*result)[930] = &_f_2930_;
 (*result)[931] = &_f_2931_;
 (*result)[932] = &_f_2932_;
 (*result)[933] = &_f_2933_;
 (*result)[934] = &_f_2934_;
 (*result)[935] = &_f_2935_;
 (*result)[936] = &_f_2936_;
 (*result)[937] = &_f_2937_;
 (*result)[938] = &_f_2938_;
 (*result)[939] = &_f_2939_;
 (*result)[940] = &_f_2940_;
 (*result)[941] = &_f_2941_;
 (*result)[942] = &_f_2942_;
 (*result)[943] = &_f_2943_;
 (*result)[944] = &_f_2944_;
 (*result)[945] = &_f_2945_;
 (*result)[946] = &_f_2946_;
 (*result)[947] = &_f_2947_;
 (*result)[948] = &_f_2948_;
 (*result)[949] = &_f_2949_;
 (*result)[950] = &_f_2950_;
 (*result)[951] = &_f_2951_;
 (*result)[952] = &_f_2952_;
 (*result)[953] = &_f_2953_;
 (*result)[954] = &_f_2954_;
 (*result)[955] = &_f_2955_;
 (*result)[956] = &_f_2956_;
 (*result)[957] = &_f_2957_;
 (*result)[958] = &_f_2958_;
 (*result)[959] = &_f_2959_;
 (*result)[960] = &_f_2960_;
 (*result)[961] = &_f_2961_;
 (*result)[962] = &_f_2962_;
 (*result)[963] = &_f_2963_;
 (*result)[964] = &_f_2964_;
 (*result)[965] = &_f_2965_;
 (*result)[966] = &_f_2966_;
 (*result)[967] = &_f_2967_;
 (*result)[968] = &_f_2968_;
 (*result)[969] = &_f_2969_;
 (*result)[970] = &_f_2970_;
 (*result)[971] = &_f_2971_;
 (*result)[972] = &_f_2972_;
 (*result)[973] = &_f_2973_;
 (*result)[974] = &_f_2974_;
 (*result)[975] = &_f_2975_;
 (*result)[976] = &_f_2976_;
 (*result)[977] = &_f_2977_;
 (*result)[978] = &_f_2978_;
 (*result)[979] = &_f_2979_;
 (*result)[980] = &_f_2980_;
 (*result)[981] = &_f_2981_;
 (*result)[982] = &_f_2982_;
 (*result)[983] = &_f_2983_;
 (*result)[984] = &_f_2984_;
 (*result)[985] = &_f_2985_;
 (*result)[986] = &_f_2986_;
 (*result)[987] = &_f_2987_;
 (*result)[988] = &_f_2988_;
 (*result)[989] = &_f_2989_;
 (*result)[990] = &_f_2990_;
 (*result)[991] = &_f_2991_;
 (*result)[992] = &_f_2992_;
 (*result)[993] = &_f_2993_;
 (*result)[994] = &_f_2994_;
 (*result)[995] = &_f_2995_;
 (*result)[996] = &_f_2996_;
 (*result)[997] = &_f_2997_;
 (*result)[998] = &_f_2998_;
 (*result)[999] = &_f_2999_;
}

void run_s0_2_re2(u4 code, minimal_fn_s0_re2_type fn, u2& retv, n8 a1, n8 a2, n8 a3)
{
 code %= 1000;
 static s0_2_re2_dispatch_array* dispatch_array = init_s0_2_re2_dispatch_array();
 run_s0_2_re2_type f = (*dispatch_array)[code];
 f(retv, a1, a2, a3, fn);
}

#endif //def FULL_INCLUDE
