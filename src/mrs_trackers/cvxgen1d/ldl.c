/* Produced by CVXGEN, 2018-02-08 04:01:51 -0500.  */
/* CVXGEN is Copyright (C) 2006-2017 Jacob Mattingley, jem@cvxgen.com. */
/* The code in this file is Copyright (C) 2006-2017 Jacob Mattingley. */
/* CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial */
/* applications without prior written permission from Jacob Mattingley. */

/* Filename: ldl.c. */
/* Description: Basic test harness for solver.c. */
#include "solver.h"
/* Be sure to place ldl_solve first, so storage schemes are defined by it. */
void ldl_solve1d(double *target, double *var) {
  int i;
  /* Find var = (L*diag(work1d.d)*L') \ target, then unpermute. */
  /* Answer goes into var. */
  /* Forward substitution. */
  /* Include permutation as we retrieve from target. Use v so we can unpermute */
  /* later. */
  work1d.v[0] = target[120];
  work1d.v[1] = target[241];
  work1d.v[2] = target[242];
  work1d.v[3] = target[243];
  work1d.v[4] = target[244];
  work1d.v[5] = target[245];
  work1d.v[6] = target[246];
  work1d.v[7] = target[247];
  work1d.v[8] = target[248];
  work1d.v[9] = target[249];
  work1d.v[10] = target[250];
  work1d.v[11] = target[251];
  work1d.v[12] = target[252];
  work1d.v[13] = target[253];
  work1d.v[14] = target[254];
  work1d.v[15] = target[255];
  work1d.v[16] = target[256];
  work1d.v[17] = target[257];
  work1d.v[18] = target[258];
  work1d.v[19] = target[259];
  work1d.v[20] = target[260];
  work1d.v[21] = target[261];
  work1d.v[22] = target[262];
  work1d.v[23] = target[263];
  work1d.v[24] = target[264];
  work1d.v[25] = target[265];
  work1d.v[26] = target[266];
  work1d.v[27] = target[267];
  work1d.v[28] = target[268];
  work1d.v[29] = target[269];
  work1d.v[30] = target[270];
  work1d.v[31] = target[271];
  work1d.v[32] = target[272];
  work1d.v[33] = target[273];
  work1d.v[34] = target[274];
  work1d.v[35] = target[275];
  work1d.v[36] = target[276];
  work1d.v[37] = target[277];
  work1d.v[38] = target[278];
  work1d.v[39] = target[279];
  work1d.v[40] = target[280];
  work1d.v[41] = target[281];
  work1d.v[42] = target[282];
  work1d.v[43] = target[283];
  work1d.v[44] = target[284];
  work1d.v[45] = target[285];
  work1d.v[46] = target[286];
  work1d.v[47] = target[287];
  work1d.v[48] = target[288];
  work1d.v[49] = target[289];
  work1d.v[50] = target[290];
  work1d.v[51] = target[291];
  work1d.v[52] = target[292];
  work1d.v[53] = target[293];
  work1d.v[54] = target[294];
  work1d.v[55] = target[295];
  work1d.v[56] = target[296];
  work1d.v[57] = target[297];
  work1d.v[58] = target[298];
  work1d.v[59] = target[299];
  work1d.v[60] = target[300];
  work1d.v[61] = target[301];
  work1d.v[62] = target[302];
  work1d.v[63] = target[303];
  work1d.v[64] = target[304];
  work1d.v[65] = target[305];
  work1d.v[66] = target[306];
  work1d.v[67] = target[307];
  work1d.v[68] = target[308];
  work1d.v[69] = target[309];
  work1d.v[70] = target[310];
  work1d.v[71] = target[311];
  work1d.v[72] = target[312];
  work1d.v[73] = target[313];
  work1d.v[74] = target[314];
  work1d.v[75] = target[315];
  work1d.v[76] = target[316];
  work1d.v[77] = target[317];
  work1d.v[78] = target[318];
  work1d.v[79] = target[319];
  work1d.v[80] = target[320];
  work1d.v[81] = target[321];
  work1d.v[82] = target[322];
  work1d.v[83] = target[323];
  work1d.v[84] = target[324];
  work1d.v[85] = target[325];
  work1d.v[86] = target[326];
  work1d.v[87] = target[327];
  work1d.v[88] = target[328];
  work1d.v[89] = target[329];
  work1d.v[90] = target[330];
  work1d.v[91] = target[331];
  work1d.v[92] = target[332];
  work1d.v[93] = target[333];
  work1d.v[94] = target[334];
  work1d.v[95] = target[335];
  work1d.v[96] = target[336];
  work1d.v[97] = target[337];
  work1d.v[98] = target[338];
  work1d.v[99] = target[339];
  work1d.v[100] = target[340];
  work1d.v[101] = target[341];
  work1d.v[102] = target[342];
  work1d.v[103] = target[343];
  work1d.v[104] = target[344];
  work1d.v[105] = target[345];
  work1d.v[106] = target[346];
  work1d.v[107] = target[347];
  work1d.v[108] = target[348];
  work1d.v[109] = target[349];
  work1d.v[110] = target[350];
  work1d.v[111] = target[351];
  work1d.v[112] = target[352];
  work1d.v[113] = target[353];
  work1d.v[114] = target[354];
  work1d.v[115] = target[355];
  work1d.v[116] = target[356];
  work1d.v[117] = target[357];
  work1d.v[118] = target[358];
  work1d.v[119] = target[359];
  work1d.v[120] = target[360];
  work1d.v[121] = target[361];
  work1d.v[122] = target[362];
  work1d.v[123] = target[363];
  work1d.v[124] = target[364];
  work1d.v[125] = target[365];
  work1d.v[126] = target[366];
  work1d.v[127] = target[367];
  work1d.v[128] = target[368];
  work1d.v[129] = target[369];
  work1d.v[130] = target[370];
  work1d.v[131] = target[371];
  work1d.v[132] = target[372];
  work1d.v[133] = target[373];
  work1d.v[134] = target[374];
  work1d.v[135] = target[375];
  work1d.v[136] = target[376];
  work1d.v[137] = target[377];
  work1d.v[138] = target[378];
  work1d.v[139] = target[379];
  work1d.v[140] = target[380];
  work1d.v[141] = target[381];
  work1d.v[142] = target[382];
  work1d.v[143] = target[383];
  work1d.v[144] = target[384];
  work1d.v[145] = target[385];
  work1d.v[146] = target[386];
  work1d.v[147] = target[387];
  work1d.v[148] = target[388];
  work1d.v[149] = target[389];
  work1d.v[150] = target[390];
  work1d.v[151] = target[391];
  work1d.v[152] = target[392];
  work1d.v[153] = target[393];
  work1d.v[154] = target[394];
  work1d.v[155] = target[395];
  work1d.v[156] = target[396];
  work1d.v[157] = target[397];
  work1d.v[158] = target[398];
  work1d.v[159] = target[399];
  work1d.v[160] = target[400];
  work1d.v[161] = target[401];
  work1d.v[162] = target[402];
  work1d.v[163] = target[403];
  work1d.v[164] = target[404];
  work1d.v[165] = target[405];
  work1d.v[166] = target[406];
  work1d.v[167] = target[407];
  work1d.v[168] = target[408];
  work1d.v[169] = target[409];
  work1d.v[170] = target[410];
  work1d.v[171] = target[411];
  work1d.v[172] = target[412];
  work1d.v[173] = target[413];
  work1d.v[174] = target[414];
  work1d.v[175] = target[415];
  work1d.v[176] = target[416];
  work1d.v[177] = target[417];
  work1d.v[178] = target[418];
  work1d.v[179] = target[419];
  work1d.v[180] = target[420];
  work1d.v[181] = target[421];
  work1d.v[182] = target[422];
  work1d.v[183] = target[423];
  work1d.v[184] = target[424];
  work1d.v[185] = target[425];
  work1d.v[186] = target[426];
  work1d.v[187] = target[427];
  work1d.v[188] = target[428];
  work1d.v[189] = target[429];
  work1d.v[190] = target[430];
  work1d.v[191] = target[431];
  work1d.v[192] = target[432];
  work1d.v[193] = target[433];
  work1d.v[194] = target[434];
  work1d.v[195] = target[435];
  work1d.v[196] = target[436];
  work1d.v[197] = target[437];
  work1d.v[198] = target[438];
  work1d.v[199] = target[439];
  work1d.v[200] = target[440];
  work1d.v[201] = target[441];
  work1d.v[202] = target[442];
  work1d.v[203] = target[443];
  work1d.v[204] = target[444];
  work1d.v[205] = target[445];
  work1d.v[206] = target[446];
  work1d.v[207] = target[447];
  work1d.v[208] = target[448];
  work1d.v[209] = target[449];
  work1d.v[210] = target[450];
  work1d.v[211] = target[451];
  work1d.v[212] = target[452];
  work1d.v[213] = target[453];
  work1d.v[214] = target[454];
  work1d.v[215] = target[455];
  work1d.v[216] = target[456];
  work1d.v[217] = target[457];
  work1d.v[218] = target[458];
  work1d.v[219] = target[459];
  work1d.v[220] = target[460];
  work1d.v[221] = target[461];
  work1d.v[222] = target[462];
  work1d.v[223] = target[463];
  work1d.v[224] = target[464];
  work1d.v[225] = target[465];
  work1d.v[226] = target[466];
  work1d.v[227] = target[467];
  work1d.v[228] = target[468];
  work1d.v[229] = target[469];
  work1d.v[230] = target[470];
  work1d.v[231] = target[471];
  work1d.v[232] = target[472];
  work1d.v[233] = target[473];
  work1d.v[234] = target[474];
  work1d.v[235] = target[475];
  work1d.v[236] = target[476];
  work1d.v[237] = target[477];
  work1d.v[238] = target[478];
  work1d.v[239] = target[479];
  work1d.v[240] = target[480];
  work1d.v[241] = target[481];
  work1d.v[242] = target[482];
  work1d.v[243] = target[483];
  work1d.v[244] = target[484];
  work1d.v[245] = target[485];
  work1d.v[246] = target[486];
  work1d.v[247] = target[487];
  work1d.v[248] = target[488];
  work1d.v[249] = target[489];
  work1d.v[250] = target[490];
  work1d.v[251] = target[491];
  work1d.v[252] = target[492];
  work1d.v[253] = target[493];
  work1d.v[254] = target[494];
  work1d.v[255] = target[495];
  work1d.v[256] = target[496];
  work1d.v[257] = target[497];
  work1d.v[258] = target[498];
  work1d.v[259] = target[499];
  work1d.v[260] = target[500];
  work1d.v[261] = target[501];
  work1d.v[262] = target[502];
  work1d.v[263] = target[503];
  work1d.v[264] = target[504];
  work1d.v[265] = target[505];
  work1d.v[266] = target[506];
  work1d.v[267] = target[507];
  work1d.v[268] = target[508];
  work1d.v[269] = target[509];
  work1d.v[270] = target[510];
  work1d.v[271] = target[511];
  work1d.v[272] = target[512];
  work1d.v[273] = target[513];
  work1d.v[274] = target[514];
  work1d.v[275] = target[515];
  work1d.v[276] = target[516];
  work1d.v[277] = target[517];
  work1d.v[278] = target[518];
  work1d.v[279] = target[519];
  work1d.v[280] = target[520];
  work1d.v[281] = target[521];
  work1d.v[282] = target[522];
  work1d.v[283] = target[523];
  work1d.v[284] = target[524];
  work1d.v[285] = target[525];
  work1d.v[286] = target[526];
  work1d.v[287] = target[527];
  work1d.v[288] = target[528];
  work1d.v[289] = target[529];
  work1d.v[290] = target[530];
  work1d.v[291] = target[531];
  work1d.v[292] = target[532];
  work1d.v[293] = target[533];
  work1d.v[294] = target[534];
  work1d.v[295] = target[535];
  work1d.v[296] = target[536];
  work1d.v[297] = target[537];
  work1d.v[298] = target[538];
  work1d.v[299] = target[539];
  work1d.v[300] = target[540];
  work1d.v[301] = target[541];
  work1d.v[302] = target[542];
  work1d.v[303] = target[543];
  work1d.v[304] = target[544];
  work1d.v[305] = target[545];
  work1d.v[306] = target[546];
  work1d.v[307] = target[547];
  work1d.v[308] = target[548];
  work1d.v[309] = target[549];
  work1d.v[310] = target[550];
  work1d.v[311] = target[551];
  work1d.v[312] = target[552];
  work1d.v[313] = target[553];
  work1d.v[314] = target[554];
  work1d.v[315] = target[555];
  work1d.v[316] = target[556];
  work1d.v[317] = target[557];
  work1d.v[318] = target[558];
  work1d.v[319] = target[559];
  work1d.v[320] = target[560];
  work1d.v[321] = target[801]-work1d.L[0]*work1d.v[241];
  work1d.v[322] = target[802]-work1d.L[1]*work1d.v[242];
  work1d.v[323] = target[803]-work1d.L[2]*work1d.v[243];
  work1d.v[324] = target[804]-work1d.L[3]*work1d.v[244];
  work1d.v[325] = target[805]-work1d.L[4]*work1d.v[245];
  work1d.v[326] = target[806]-work1d.L[5]*work1d.v[246];
  work1d.v[327] = target[807]-work1d.L[6]*work1d.v[247];
  work1d.v[328] = target[808]-work1d.L[7]*work1d.v[248];
  work1d.v[329] = target[809]-work1d.L[8]*work1d.v[249];
  work1d.v[330] = target[810]-work1d.L[9]*work1d.v[250];
  work1d.v[331] = target[811]-work1d.L[10]*work1d.v[251];
  work1d.v[332] = target[812]-work1d.L[11]*work1d.v[252];
  work1d.v[333] = target[813]-work1d.L[12]*work1d.v[253];
  work1d.v[334] = target[814]-work1d.L[13]*work1d.v[254];
  work1d.v[335] = target[815]-work1d.L[14]*work1d.v[255];
  work1d.v[336] = target[816]-work1d.L[15]*work1d.v[256];
  work1d.v[337] = target[817]-work1d.L[16]*work1d.v[257];
  work1d.v[338] = target[818]-work1d.L[17]*work1d.v[258];
  work1d.v[339] = target[819]-work1d.L[18]*work1d.v[259];
  work1d.v[340] = target[820]-work1d.L[19]*work1d.v[260];
  work1d.v[341] = target[821]-work1d.L[20]*work1d.v[261];
  work1d.v[342] = target[822]-work1d.L[21]*work1d.v[262];
  work1d.v[343] = target[823]-work1d.L[22]*work1d.v[263];
  work1d.v[344] = target[824]-work1d.L[23]*work1d.v[264];
  work1d.v[345] = target[825]-work1d.L[24]*work1d.v[265];
  work1d.v[346] = target[826]-work1d.L[25]*work1d.v[266];
  work1d.v[347] = target[827]-work1d.L[26]*work1d.v[267];
  work1d.v[348] = target[828]-work1d.L[27]*work1d.v[268];
  work1d.v[349] = target[829]-work1d.L[28]*work1d.v[269];
  work1d.v[350] = target[830]-work1d.L[29]*work1d.v[270];
  work1d.v[351] = target[831]-work1d.L[30]*work1d.v[271];
  work1d.v[352] = target[832]-work1d.L[31]*work1d.v[272];
  work1d.v[353] = target[833]-work1d.L[32]*work1d.v[273];
  work1d.v[354] = target[834]-work1d.L[33]*work1d.v[274];
  work1d.v[355] = target[835]-work1d.L[34]*work1d.v[275];
  work1d.v[356] = target[836]-work1d.L[35]*work1d.v[276];
  work1d.v[357] = target[837]-work1d.L[36]*work1d.v[277];
  work1d.v[358] = target[838]-work1d.L[37]*work1d.v[278];
  work1d.v[359] = target[839]-work1d.L[38]*work1d.v[279];
  work1d.v[360] = target[840]-work1d.L[39]*work1d.v[280];
  work1d.v[361] = target[841]-work1d.L[40]*work1d.v[281];
  work1d.v[362] = target[842]-work1d.L[41]*work1d.v[282];
  work1d.v[363] = target[843]-work1d.L[42]*work1d.v[283];
  work1d.v[364] = target[844]-work1d.L[43]*work1d.v[284];
  work1d.v[365] = target[845]-work1d.L[44]*work1d.v[285];
  work1d.v[366] = target[846]-work1d.L[45]*work1d.v[286];
  work1d.v[367] = target[847]-work1d.L[46]*work1d.v[287];
  work1d.v[368] = target[848]-work1d.L[47]*work1d.v[288];
  work1d.v[369] = target[849]-work1d.L[48]*work1d.v[289];
  work1d.v[370] = target[850]-work1d.L[49]*work1d.v[290];
  work1d.v[371] = target[851]-work1d.L[50]*work1d.v[291];
  work1d.v[372] = target[852]-work1d.L[51]*work1d.v[292];
  work1d.v[373] = target[853]-work1d.L[52]*work1d.v[293];
  work1d.v[374] = target[854]-work1d.L[53]*work1d.v[294];
  work1d.v[375] = target[855]-work1d.L[54]*work1d.v[295];
  work1d.v[376] = target[856]-work1d.L[55]*work1d.v[296];
  work1d.v[377] = target[857]-work1d.L[56]*work1d.v[297];
  work1d.v[378] = target[858]-work1d.L[57]*work1d.v[298];
  work1d.v[379] = target[859]-work1d.L[58]*work1d.v[299];
  work1d.v[380] = target[860]-work1d.L[59]*work1d.v[300];
  work1d.v[381] = target[861]-work1d.L[60]*work1d.v[301];
  work1d.v[382] = target[862]-work1d.L[61]*work1d.v[302];
  work1d.v[383] = target[863]-work1d.L[62]*work1d.v[303];
  work1d.v[384] = target[864]-work1d.L[63]*work1d.v[304];
  work1d.v[385] = target[865]-work1d.L[64]*work1d.v[305];
  work1d.v[386] = target[866]-work1d.L[65]*work1d.v[306];
  work1d.v[387] = target[867]-work1d.L[66]*work1d.v[307];
  work1d.v[388] = target[868]-work1d.L[67]*work1d.v[308];
  work1d.v[389] = target[869]-work1d.L[68]*work1d.v[309];
  work1d.v[390] = target[870]-work1d.L[69]*work1d.v[310];
  work1d.v[391] = target[871]-work1d.L[70]*work1d.v[311];
  work1d.v[392] = target[872]-work1d.L[71]*work1d.v[312];
  work1d.v[393] = target[873]-work1d.L[72]*work1d.v[313];
  work1d.v[394] = target[874]-work1d.L[73]*work1d.v[314];
  work1d.v[395] = target[875]-work1d.L[74]*work1d.v[315];
  work1d.v[396] = target[876]-work1d.L[75]*work1d.v[316];
  work1d.v[397] = target[877]-work1d.L[76]*work1d.v[317];
  work1d.v[398] = target[878]-work1d.L[77]*work1d.v[318];
  work1d.v[399] = target[879]-work1d.L[78]*work1d.v[319];
  work1d.v[400] = target[880]-work1d.L[79]*work1d.v[320];
  work1d.v[401] = target[881];
  work1d.v[402] = target[882];
  work1d.v[403] = target[80];
  work1d.v[404] = target[883]-work1d.L[80]*work1d.v[403];
  work1d.v[405] = target[81];
  work1d.v[406] = target[82];
  work1d.v[407] = target[83];
  work1d.v[408] = target[84];
  work1d.v[409] = target[85];
  work1d.v[410] = target[86];
  work1d.v[411] = target[87];
  work1d.v[412] = target[88];
  work1d.v[413] = target[89];
  work1d.v[414] = target[90];
  work1d.v[415] = target[91];
  work1d.v[416] = target[92];
  work1d.v[417] = target[93];
  work1d.v[418] = target[94];
  work1d.v[419] = target[95];
  work1d.v[420] = target[96];
  work1d.v[421] = target[97];
  work1d.v[422] = target[98];
  work1d.v[423] = target[99];
  work1d.v[424] = target[100];
  work1d.v[425] = target[101];
  work1d.v[426] = target[102];
  work1d.v[427] = target[103];
  work1d.v[428] = target[104];
  work1d.v[429] = target[105];
  work1d.v[430] = target[106];
  work1d.v[431] = target[107];
  work1d.v[432] = target[108];
  work1d.v[433] = target[109];
  work1d.v[434] = target[110];
  work1d.v[435] = target[111];
  work1d.v[436] = target[112];
  work1d.v[437] = target[113];
  work1d.v[438] = target[114];
  work1d.v[439] = target[115];
  work1d.v[440] = target[116];
  work1d.v[441] = target[117];
  work1d.v[442] = target[118];
  work1d.v[443] = target[119];
  work1d.v[444] = target[121]-work1d.L[81]*work1d.v[401];
  work1d.v[445] = target[238];
  work1d.v[446] = target[561]-work1d.L[82]*work1d.v[1];
  work1d.v[447] = target[0]-work1d.L[83]*work1d.v[446];
  work1d.v[448] = target[562]-work1d.L[84]*work1d.v[2]-work1d.L[85]*work1d.v[447];
  work1d.v[449] = target[563]-work1d.L[86]*work1d.v[3]-work1d.L[87]*work1d.v[447]-work1d.L[88]*work1d.v[448];
  work1d.v[450] = target[564]-work1d.L[89]*work1d.v[4];
  work1d.v[451] = target[1]-work1d.L[90]*work1d.v[450];
  work1d.v[452] = target[565]-work1d.L[91]*work1d.v[5]-work1d.L[92]*work1d.v[451];
  work1d.v[453] = target[566]-work1d.L[93]*work1d.v[6]-work1d.L[94]*work1d.v[451]-work1d.L[95]*work1d.v[452];
  work1d.v[454] = target[567]-work1d.L[96]*work1d.v[7];
  work1d.v[455] = target[2]-work1d.L[97]*work1d.v[454];
  work1d.v[456] = target[568]-work1d.L[98]*work1d.v[8]-work1d.L[99]*work1d.v[455];
  work1d.v[457] = target[569]-work1d.L[100]*work1d.v[9]-work1d.L[101]*work1d.v[455]-work1d.L[102]*work1d.v[456];
  work1d.v[458] = target[570]-work1d.L[103]*work1d.v[10];
  work1d.v[459] = target[3]-work1d.L[104]*work1d.v[458];
  work1d.v[460] = target[571]-work1d.L[105]*work1d.v[11]-work1d.L[106]*work1d.v[459];
  work1d.v[461] = target[572]-work1d.L[107]*work1d.v[12]-work1d.L[108]*work1d.v[459]-work1d.L[109]*work1d.v[460];
  work1d.v[462] = target[573]-work1d.L[110]*work1d.v[13];
  work1d.v[463] = target[4]-work1d.L[111]*work1d.v[462];
  work1d.v[464] = target[574]-work1d.L[112]*work1d.v[14]-work1d.L[113]*work1d.v[463];
  work1d.v[465] = target[575]-work1d.L[114]*work1d.v[15]-work1d.L[115]*work1d.v[463]-work1d.L[116]*work1d.v[464];
  work1d.v[466] = target[576]-work1d.L[117]*work1d.v[16];
  work1d.v[467] = target[5]-work1d.L[118]*work1d.v[466];
  work1d.v[468] = target[577]-work1d.L[119]*work1d.v[17]-work1d.L[120]*work1d.v[467];
  work1d.v[469] = target[578]-work1d.L[121]*work1d.v[18]-work1d.L[122]*work1d.v[467]-work1d.L[123]*work1d.v[468];
  work1d.v[470] = target[579]-work1d.L[124]*work1d.v[19];
  work1d.v[471] = target[6]-work1d.L[125]*work1d.v[470];
  work1d.v[472] = target[580]-work1d.L[126]*work1d.v[20]-work1d.L[127]*work1d.v[471];
  work1d.v[473] = target[581]-work1d.L[128]*work1d.v[21]-work1d.L[129]*work1d.v[471]-work1d.L[130]*work1d.v[472];
  work1d.v[474] = target[582]-work1d.L[131]*work1d.v[22];
  work1d.v[475] = target[7]-work1d.L[132]*work1d.v[474];
  work1d.v[476] = target[583]-work1d.L[133]*work1d.v[23]-work1d.L[134]*work1d.v[475];
  work1d.v[477] = target[584]-work1d.L[135]*work1d.v[24]-work1d.L[136]*work1d.v[475]-work1d.L[137]*work1d.v[476];
  work1d.v[478] = target[585]-work1d.L[138]*work1d.v[25];
  work1d.v[479] = target[8]-work1d.L[139]*work1d.v[478];
  work1d.v[480] = target[586]-work1d.L[140]*work1d.v[26]-work1d.L[141]*work1d.v[479];
  work1d.v[481] = target[587]-work1d.L[142]*work1d.v[27]-work1d.L[143]*work1d.v[479]-work1d.L[144]*work1d.v[480];
  work1d.v[482] = target[588]-work1d.L[145]*work1d.v[28];
  work1d.v[483] = target[9]-work1d.L[146]*work1d.v[482];
  work1d.v[484] = target[589]-work1d.L[147]*work1d.v[29]-work1d.L[148]*work1d.v[483];
  work1d.v[485] = target[590]-work1d.L[149]*work1d.v[30]-work1d.L[150]*work1d.v[483]-work1d.L[151]*work1d.v[484];
  work1d.v[486] = target[591]-work1d.L[152]*work1d.v[31];
  work1d.v[487] = target[10]-work1d.L[153]*work1d.v[486];
  work1d.v[488] = target[592]-work1d.L[154]*work1d.v[32]-work1d.L[155]*work1d.v[487];
  work1d.v[489] = target[593]-work1d.L[156]*work1d.v[33]-work1d.L[157]*work1d.v[487]-work1d.L[158]*work1d.v[488];
  work1d.v[490] = target[594]-work1d.L[159]*work1d.v[34];
  work1d.v[491] = target[11]-work1d.L[160]*work1d.v[490];
  work1d.v[492] = target[595]-work1d.L[161]*work1d.v[35]-work1d.L[162]*work1d.v[491];
  work1d.v[493] = target[596]-work1d.L[163]*work1d.v[36]-work1d.L[164]*work1d.v[491]-work1d.L[165]*work1d.v[492];
  work1d.v[494] = target[597]-work1d.L[166]*work1d.v[37];
  work1d.v[495] = target[12]-work1d.L[167]*work1d.v[494];
  work1d.v[496] = target[598]-work1d.L[168]*work1d.v[38]-work1d.L[169]*work1d.v[495];
  work1d.v[497] = target[599]-work1d.L[170]*work1d.v[39]-work1d.L[171]*work1d.v[495]-work1d.L[172]*work1d.v[496];
  work1d.v[498] = target[600]-work1d.L[173]*work1d.v[40];
  work1d.v[499] = target[13]-work1d.L[174]*work1d.v[498];
  work1d.v[500] = target[601]-work1d.L[175]*work1d.v[41]-work1d.L[176]*work1d.v[499];
  work1d.v[501] = target[602]-work1d.L[177]*work1d.v[42]-work1d.L[178]*work1d.v[499]-work1d.L[179]*work1d.v[500];
  work1d.v[502] = target[603]-work1d.L[180]*work1d.v[43];
  work1d.v[503] = target[14]-work1d.L[181]*work1d.v[502];
  work1d.v[504] = target[604]-work1d.L[182]*work1d.v[44]-work1d.L[183]*work1d.v[503];
  work1d.v[505] = target[605]-work1d.L[184]*work1d.v[45]-work1d.L[185]*work1d.v[503]-work1d.L[186]*work1d.v[504];
  work1d.v[506] = target[606]-work1d.L[187]*work1d.v[46];
  work1d.v[507] = target[15]-work1d.L[188]*work1d.v[506];
  work1d.v[508] = target[607]-work1d.L[189]*work1d.v[47]-work1d.L[190]*work1d.v[507];
  work1d.v[509] = target[608]-work1d.L[191]*work1d.v[48]-work1d.L[192]*work1d.v[507]-work1d.L[193]*work1d.v[508];
  work1d.v[510] = target[609]-work1d.L[194]*work1d.v[49];
  work1d.v[511] = target[16]-work1d.L[195]*work1d.v[510];
  work1d.v[512] = target[610]-work1d.L[196]*work1d.v[50]-work1d.L[197]*work1d.v[511];
  work1d.v[513] = target[611]-work1d.L[198]*work1d.v[51]-work1d.L[199]*work1d.v[511]-work1d.L[200]*work1d.v[512];
  work1d.v[514] = target[612]-work1d.L[201]*work1d.v[52];
  work1d.v[515] = target[17]-work1d.L[202]*work1d.v[514];
  work1d.v[516] = target[613]-work1d.L[203]*work1d.v[53]-work1d.L[204]*work1d.v[515];
  work1d.v[517] = target[614]-work1d.L[205]*work1d.v[54]-work1d.L[206]*work1d.v[515]-work1d.L[207]*work1d.v[516];
  work1d.v[518] = target[615]-work1d.L[208]*work1d.v[55];
  work1d.v[519] = target[18]-work1d.L[209]*work1d.v[518];
  work1d.v[520] = target[616]-work1d.L[210]*work1d.v[56]-work1d.L[211]*work1d.v[519];
  work1d.v[521] = target[617]-work1d.L[212]*work1d.v[57]-work1d.L[213]*work1d.v[519]-work1d.L[214]*work1d.v[520];
  work1d.v[522] = target[618]-work1d.L[215]*work1d.v[58];
  work1d.v[523] = target[19]-work1d.L[216]*work1d.v[522];
  work1d.v[524] = target[619]-work1d.L[217]*work1d.v[59]-work1d.L[218]*work1d.v[523];
  work1d.v[525] = target[620]-work1d.L[219]*work1d.v[60]-work1d.L[220]*work1d.v[523]-work1d.L[221]*work1d.v[524];
  work1d.v[526] = target[621]-work1d.L[222]*work1d.v[61];
  work1d.v[527] = target[20]-work1d.L[223]*work1d.v[526];
  work1d.v[528] = target[622]-work1d.L[224]*work1d.v[62]-work1d.L[225]*work1d.v[527];
  work1d.v[529] = target[623]-work1d.L[226]*work1d.v[63]-work1d.L[227]*work1d.v[527]-work1d.L[228]*work1d.v[528];
  work1d.v[530] = target[624]-work1d.L[229]*work1d.v[64];
  work1d.v[531] = target[21]-work1d.L[230]*work1d.v[530];
  work1d.v[532] = target[625]-work1d.L[231]*work1d.v[65]-work1d.L[232]*work1d.v[531];
  work1d.v[533] = target[626]-work1d.L[233]*work1d.v[66]-work1d.L[234]*work1d.v[531]-work1d.L[235]*work1d.v[532];
  work1d.v[534] = target[627]-work1d.L[236]*work1d.v[67];
  work1d.v[535] = target[22]-work1d.L[237]*work1d.v[534];
  work1d.v[536] = target[628]-work1d.L[238]*work1d.v[68]-work1d.L[239]*work1d.v[535];
  work1d.v[537] = target[629]-work1d.L[240]*work1d.v[69]-work1d.L[241]*work1d.v[535]-work1d.L[242]*work1d.v[536];
  work1d.v[538] = target[630]-work1d.L[243]*work1d.v[70];
  work1d.v[539] = target[23]-work1d.L[244]*work1d.v[538];
  work1d.v[540] = target[631]-work1d.L[245]*work1d.v[71]-work1d.L[246]*work1d.v[539];
  work1d.v[541] = target[632]-work1d.L[247]*work1d.v[72]-work1d.L[248]*work1d.v[539]-work1d.L[249]*work1d.v[540];
  work1d.v[542] = target[633]-work1d.L[250]*work1d.v[73];
  work1d.v[543] = target[24]-work1d.L[251]*work1d.v[542];
  work1d.v[544] = target[634]-work1d.L[252]*work1d.v[74]-work1d.L[253]*work1d.v[543];
  work1d.v[545] = target[635]-work1d.L[254]*work1d.v[75]-work1d.L[255]*work1d.v[543]-work1d.L[256]*work1d.v[544];
  work1d.v[546] = target[636]-work1d.L[257]*work1d.v[76];
  work1d.v[547] = target[25]-work1d.L[258]*work1d.v[546];
  work1d.v[548] = target[637]-work1d.L[259]*work1d.v[77]-work1d.L[260]*work1d.v[547];
  work1d.v[549] = target[638]-work1d.L[261]*work1d.v[78]-work1d.L[262]*work1d.v[547]-work1d.L[263]*work1d.v[548];
  work1d.v[550] = target[639]-work1d.L[264]*work1d.v[79];
  work1d.v[551] = target[26]-work1d.L[265]*work1d.v[550];
  work1d.v[552] = target[640]-work1d.L[266]*work1d.v[80]-work1d.L[267]*work1d.v[551];
  work1d.v[553] = target[641]-work1d.L[268]*work1d.v[81]-work1d.L[269]*work1d.v[551]-work1d.L[270]*work1d.v[552];
  work1d.v[554] = target[642]-work1d.L[271]*work1d.v[82];
  work1d.v[555] = target[27]-work1d.L[272]*work1d.v[554];
  work1d.v[556] = target[643]-work1d.L[273]*work1d.v[83]-work1d.L[274]*work1d.v[555];
  work1d.v[557] = target[644]-work1d.L[275]*work1d.v[84]-work1d.L[276]*work1d.v[555]-work1d.L[277]*work1d.v[556];
  work1d.v[558] = target[645]-work1d.L[278]*work1d.v[85];
  work1d.v[559] = target[28]-work1d.L[279]*work1d.v[558];
  work1d.v[560] = target[646]-work1d.L[280]*work1d.v[86]-work1d.L[281]*work1d.v[559];
  work1d.v[561] = target[647]-work1d.L[282]*work1d.v[87]-work1d.L[283]*work1d.v[559]-work1d.L[284]*work1d.v[560];
  work1d.v[562] = target[648]-work1d.L[285]*work1d.v[88];
  work1d.v[563] = target[29]-work1d.L[286]*work1d.v[562];
  work1d.v[564] = target[649]-work1d.L[287]*work1d.v[89]-work1d.L[288]*work1d.v[563];
  work1d.v[565] = target[650]-work1d.L[289]*work1d.v[90]-work1d.L[290]*work1d.v[563]-work1d.L[291]*work1d.v[564];
  work1d.v[566] = target[651]-work1d.L[292]*work1d.v[91];
  work1d.v[567] = target[30]-work1d.L[293]*work1d.v[566];
  work1d.v[568] = target[652]-work1d.L[294]*work1d.v[92]-work1d.L[295]*work1d.v[567];
  work1d.v[569] = target[653]-work1d.L[296]*work1d.v[93]-work1d.L[297]*work1d.v[567]-work1d.L[298]*work1d.v[568];
  work1d.v[570] = target[654]-work1d.L[299]*work1d.v[94];
  work1d.v[571] = target[31]-work1d.L[300]*work1d.v[570];
  work1d.v[572] = target[655]-work1d.L[301]*work1d.v[95]-work1d.L[302]*work1d.v[571];
  work1d.v[573] = target[656]-work1d.L[303]*work1d.v[96]-work1d.L[304]*work1d.v[571]-work1d.L[305]*work1d.v[572];
  work1d.v[574] = target[657]-work1d.L[306]*work1d.v[97];
  work1d.v[575] = target[32]-work1d.L[307]*work1d.v[574];
  work1d.v[576] = target[658]-work1d.L[308]*work1d.v[98]-work1d.L[309]*work1d.v[575];
  work1d.v[577] = target[659]-work1d.L[310]*work1d.v[99]-work1d.L[311]*work1d.v[575]-work1d.L[312]*work1d.v[576];
  work1d.v[578] = target[660]-work1d.L[313]*work1d.v[100];
  work1d.v[579] = target[33]-work1d.L[314]*work1d.v[578];
  work1d.v[580] = target[661]-work1d.L[315]*work1d.v[101]-work1d.L[316]*work1d.v[579];
  work1d.v[581] = target[662]-work1d.L[317]*work1d.v[102]-work1d.L[318]*work1d.v[579]-work1d.L[319]*work1d.v[580];
  work1d.v[582] = target[663]-work1d.L[320]*work1d.v[103];
  work1d.v[583] = target[34]-work1d.L[321]*work1d.v[582];
  work1d.v[584] = target[664]-work1d.L[322]*work1d.v[104]-work1d.L[323]*work1d.v[583];
  work1d.v[585] = target[665]-work1d.L[324]*work1d.v[105]-work1d.L[325]*work1d.v[583]-work1d.L[326]*work1d.v[584];
  work1d.v[586] = target[666]-work1d.L[327]*work1d.v[106];
  work1d.v[587] = target[35]-work1d.L[328]*work1d.v[586];
  work1d.v[588] = target[667]-work1d.L[329]*work1d.v[107]-work1d.L[330]*work1d.v[587];
  work1d.v[589] = target[668]-work1d.L[331]*work1d.v[108]-work1d.L[332]*work1d.v[587]-work1d.L[333]*work1d.v[588];
  work1d.v[590] = target[669]-work1d.L[334]*work1d.v[109];
  work1d.v[591] = target[36]-work1d.L[335]*work1d.v[590];
  work1d.v[592] = target[670]-work1d.L[336]*work1d.v[110]-work1d.L[337]*work1d.v[591];
  work1d.v[593] = target[671]-work1d.L[338]*work1d.v[111]-work1d.L[339]*work1d.v[591]-work1d.L[340]*work1d.v[592];
  work1d.v[594] = target[672]-work1d.L[341]*work1d.v[112];
  work1d.v[595] = target[37]-work1d.L[342]*work1d.v[594];
  work1d.v[596] = target[673]-work1d.L[343]*work1d.v[113]-work1d.L[344]*work1d.v[595];
  work1d.v[597] = target[674]-work1d.L[345]*work1d.v[114]-work1d.L[346]*work1d.v[595]-work1d.L[347]*work1d.v[596];
  work1d.v[598] = target[675]-work1d.L[348]*work1d.v[115];
  work1d.v[599] = target[38]-work1d.L[349]*work1d.v[598];
  work1d.v[600] = target[676]-work1d.L[350]*work1d.v[116]-work1d.L[351]*work1d.v[599];
  work1d.v[601] = target[677]-work1d.L[352]*work1d.v[117]-work1d.L[353]*work1d.v[599]-work1d.L[354]*work1d.v[600];
  work1d.v[602] = target[678]-work1d.L[355]*work1d.v[118];
  work1d.v[603] = target[39]-work1d.L[356]*work1d.v[602];
  work1d.v[604] = target[679]-work1d.L[357]*work1d.v[119]-work1d.L[358]*work1d.v[603];
  work1d.v[605] = target[680]-work1d.L[359]*work1d.v[120]-work1d.L[360]*work1d.v[603]-work1d.L[361]*work1d.v[604];
  work1d.v[606] = target[239]-work1d.L[362]*work1d.v[360]-work1d.L[363]*work1d.v[604]-work1d.L[364]*work1d.v[605];
  work1d.v[607] = target[681]-work1d.L[365]*work1d.v[121];
  work1d.v[608] = target[40]-work1d.L[366]*work1d.v[607];
  work1d.v[609] = target[682]-work1d.L[367]*work1d.v[122]-work1d.L[368]*work1d.v[608];
  work1d.v[610] = target[683]-work1d.L[369]*work1d.v[123]-work1d.L[370]*work1d.v[608]-work1d.L[371]*work1d.v[609];
  work1d.v[611] = target[684]-work1d.L[372]*work1d.v[124];
  work1d.v[612] = target[41]-work1d.L[373]*work1d.v[611];
  work1d.v[613] = target[685]-work1d.L[374]*work1d.v[125]-work1d.L[375]*work1d.v[612];
  work1d.v[614] = target[686]-work1d.L[376]*work1d.v[126]-work1d.L[377]*work1d.v[612]-work1d.L[378]*work1d.v[613];
  work1d.v[615] = target[687]-work1d.L[379]*work1d.v[127];
  work1d.v[616] = target[42]-work1d.L[380]*work1d.v[615];
  work1d.v[617] = target[688]-work1d.L[381]*work1d.v[128]-work1d.L[382]*work1d.v[616];
  work1d.v[618] = target[689]-work1d.L[383]*work1d.v[129]-work1d.L[384]*work1d.v[616]-work1d.L[385]*work1d.v[617];
  work1d.v[619] = target[690]-work1d.L[386]*work1d.v[130];
  work1d.v[620] = target[43]-work1d.L[387]*work1d.v[619];
  work1d.v[621] = target[691]-work1d.L[388]*work1d.v[131]-work1d.L[389]*work1d.v[620];
  work1d.v[622] = target[692]-work1d.L[390]*work1d.v[132]-work1d.L[391]*work1d.v[620]-work1d.L[392]*work1d.v[621];
  work1d.v[623] = target[693]-work1d.L[393]*work1d.v[133];
  work1d.v[624] = target[44]-work1d.L[394]*work1d.v[623];
  work1d.v[625] = target[694]-work1d.L[395]*work1d.v[134]-work1d.L[396]*work1d.v[624];
  work1d.v[626] = target[695]-work1d.L[397]*work1d.v[135]-work1d.L[398]*work1d.v[624]-work1d.L[399]*work1d.v[625];
  work1d.v[627] = target[696]-work1d.L[400]*work1d.v[136];
  work1d.v[628] = target[45]-work1d.L[401]*work1d.v[627];
  work1d.v[629] = target[697]-work1d.L[402]*work1d.v[137]-work1d.L[403]*work1d.v[628];
  work1d.v[630] = target[698]-work1d.L[404]*work1d.v[138]-work1d.L[405]*work1d.v[628]-work1d.L[406]*work1d.v[629];
  work1d.v[631] = target[699]-work1d.L[407]*work1d.v[139];
  work1d.v[632] = target[46]-work1d.L[408]*work1d.v[631];
  work1d.v[633] = target[700]-work1d.L[409]*work1d.v[140]-work1d.L[410]*work1d.v[632];
  work1d.v[634] = target[701]-work1d.L[411]*work1d.v[141]-work1d.L[412]*work1d.v[632]-work1d.L[413]*work1d.v[633];
  work1d.v[635] = target[702]-work1d.L[414]*work1d.v[142];
  work1d.v[636] = target[47]-work1d.L[415]*work1d.v[635];
  work1d.v[637] = target[703]-work1d.L[416]*work1d.v[143]-work1d.L[417]*work1d.v[636];
  work1d.v[638] = target[704]-work1d.L[418]*work1d.v[144]-work1d.L[419]*work1d.v[636]-work1d.L[420]*work1d.v[637];
  work1d.v[639] = target[705]-work1d.L[421]*work1d.v[145];
  work1d.v[640] = target[48]-work1d.L[422]*work1d.v[639];
  work1d.v[641] = target[706]-work1d.L[423]*work1d.v[146]-work1d.L[424]*work1d.v[640];
  work1d.v[642] = target[707]-work1d.L[425]*work1d.v[147]-work1d.L[426]*work1d.v[640]-work1d.L[427]*work1d.v[641];
  work1d.v[643] = target[708]-work1d.L[428]*work1d.v[148];
  work1d.v[644] = target[49]-work1d.L[429]*work1d.v[643];
  work1d.v[645] = target[709]-work1d.L[430]*work1d.v[149]-work1d.L[431]*work1d.v[644];
  work1d.v[646] = target[710]-work1d.L[432]*work1d.v[150]-work1d.L[433]*work1d.v[644]-work1d.L[434]*work1d.v[645];
  work1d.v[647] = target[711]-work1d.L[435]*work1d.v[151];
  work1d.v[648] = target[50]-work1d.L[436]*work1d.v[647];
  work1d.v[649] = target[712]-work1d.L[437]*work1d.v[152]-work1d.L[438]*work1d.v[648];
  work1d.v[650] = target[713]-work1d.L[439]*work1d.v[153]-work1d.L[440]*work1d.v[648]-work1d.L[441]*work1d.v[649];
  work1d.v[651] = target[714]-work1d.L[442]*work1d.v[154];
  work1d.v[652] = target[51]-work1d.L[443]*work1d.v[651];
  work1d.v[653] = target[715]-work1d.L[444]*work1d.v[155]-work1d.L[445]*work1d.v[652];
  work1d.v[654] = target[716]-work1d.L[446]*work1d.v[156]-work1d.L[447]*work1d.v[652]-work1d.L[448]*work1d.v[653];
  work1d.v[655] = target[717]-work1d.L[449]*work1d.v[157];
  work1d.v[656] = target[52]-work1d.L[450]*work1d.v[655];
  work1d.v[657] = target[718]-work1d.L[451]*work1d.v[158]-work1d.L[452]*work1d.v[656];
  work1d.v[658] = target[719]-work1d.L[453]*work1d.v[159]-work1d.L[454]*work1d.v[656]-work1d.L[455]*work1d.v[657];
  work1d.v[659] = target[720]-work1d.L[456]*work1d.v[160];
  work1d.v[660] = target[53]-work1d.L[457]*work1d.v[659];
  work1d.v[661] = target[721]-work1d.L[458]*work1d.v[161]-work1d.L[459]*work1d.v[660];
  work1d.v[662] = target[722]-work1d.L[460]*work1d.v[162]-work1d.L[461]*work1d.v[660]-work1d.L[462]*work1d.v[661];
  work1d.v[663] = target[723]-work1d.L[463]*work1d.v[163];
  work1d.v[664] = target[54]-work1d.L[464]*work1d.v[663];
  work1d.v[665] = target[724]-work1d.L[465]*work1d.v[164]-work1d.L[466]*work1d.v[664];
  work1d.v[666] = target[725]-work1d.L[467]*work1d.v[165]-work1d.L[468]*work1d.v[664]-work1d.L[469]*work1d.v[665];
  work1d.v[667] = target[726]-work1d.L[470]*work1d.v[166];
  work1d.v[668] = target[55]-work1d.L[471]*work1d.v[667];
  work1d.v[669] = target[727]-work1d.L[472]*work1d.v[167]-work1d.L[473]*work1d.v[668];
  work1d.v[670] = target[728]-work1d.L[474]*work1d.v[168]-work1d.L[475]*work1d.v[668]-work1d.L[476]*work1d.v[669];
  work1d.v[671] = target[729]-work1d.L[477]*work1d.v[169];
  work1d.v[672] = target[56]-work1d.L[478]*work1d.v[671];
  work1d.v[673] = target[730]-work1d.L[479]*work1d.v[170]-work1d.L[480]*work1d.v[672];
  work1d.v[674] = target[731]-work1d.L[481]*work1d.v[171]-work1d.L[482]*work1d.v[672]-work1d.L[483]*work1d.v[673];
  work1d.v[675] = target[732]-work1d.L[484]*work1d.v[172];
  work1d.v[676] = target[57]-work1d.L[485]*work1d.v[675];
  work1d.v[677] = target[733]-work1d.L[486]*work1d.v[173]-work1d.L[487]*work1d.v[676];
  work1d.v[678] = target[734]-work1d.L[488]*work1d.v[174]-work1d.L[489]*work1d.v[676]-work1d.L[490]*work1d.v[677];
  work1d.v[679] = target[735]-work1d.L[491]*work1d.v[175];
  work1d.v[680] = target[58]-work1d.L[492]*work1d.v[679];
  work1d.v[681] = target[736]-work1d.L[493]*work1d.v[176]-work1d.L[494]*work1d.v[680];
  work1d.v[682] = target[737]-work1d.L[495]*work1d.v[177]-work1d.L[496]*work1d.v[680]-work1d.L[497]*work1d.v[681];
  work1d.v[683] = target[738]-work1d.L[498]*work1d.v[178];
  work1d.v[684] = target[59]-work1d.L[499]*work1d.v[683];
  work1d.v[685] = target[739]-work1d.L[500]*work1d.v[179]-work1d.L[501]*work1d.v[684];
  work1d.v[686] = target[740]-work1d.L[502]*work1d.v[180]-work1d.L[503]*work1d.v[684]-work1d.L[504]*work1d.v[685];
  work1d.v[687] = target[741]-work1d.L[505]*work1d.v[181];
  work1d.v[688] = target[60]-work1d.L[506]*work1d.v[687];
  work1d.v[689] = target[742]-work1d.L[507]*work1d.v[182]-work1d.L[508]*work1d.v[688];
  work1d.v[690] = target[743]-work1d.L[509]*work1d.v[183]-work1d.L[510]*work1d.v[688]-work1d.L[511]*work1d.v[689];
  work1d.v[691] = target[744]-work1d.L[512]*work1d.v[184];
  work1d.v[692] = target[61]-work1d.L[513]*work1d.v[691];
  work1d.v[693] = target[745]-work1d.L[514]*work1d.v[185]-work1d.L[515]*work1d.v[692];
  work1d.v[694] = target[746]-work1d.L[516]*work1d.v[186]-work1d.L[517]*work1d.v[692]-work1d.L[518]*work1d.v[693];
  work1d.v[695] = target[747]-work1d.L[519]*work1d.v[187];
  work1d.v[696] = target[62]-work1d.L[520]*work1d.v[695];
  work1d.v[697] = target[748]-work1d.L[521]*work1d.v[188]-work1d.L[522]*work1d.v[696];
  work1d.v[698] = target[749]-work1d.L[523]*work1d.v[189]-work1d.L[524]*work1d.v[696]-work1d.L[525]*work1d.v[697];
  work1d.v[699] = target[750]-work1d.L[526]*work1d.v[190];
  work1d.v[700] = target[63]-work1d.L[527]*work1d.v[699];
  work1d.v[701] = target[751]-work1d.L[528]*work1d.v[191]-work1d.L[529]*work1d.v[700];
  work1d.v[702] = target[752]-work1d.L[530]*work1d.v[192]-work1d.L[531]*work1d.v[700]-work1d.L[532]*work1d.v[701];
  work1d.v[703] = target[753]-work1d.L[533]*work1d.v[193];
  work1d.v[704] = target[64]-work1d.L[534]*work1d.v[703];
  work1d.v[705] = target[754]-work1d.L[535]*work1d.v[194]-work1d.L[536]*work1d.v[704];
  work1d.v[706] = target[755]-work1d.L[537]*work1d.v[195]-work1d.L[538]*work1d.v[704]-work1d.L[539]*work1d.v[705];
  work1d.v[707] = target[756]-work1d.L[540]*work1d.v[196];
  work1d.v[708] = target[65]-work1d.L[541]*work1d.v[707];
  work1d.v[709] = target[757]-work1d.L[542]*work1d.v[197]-work1d.L[543]*work1d.v[708];
  work1d.v[710] = target[758]-work1d.L[544]*work1d.v[198]-work1d.L[545]*work1d.v[708]-work1d.L[546]*work1d.v[709];
  work1d.v[711] = target[759]-work1d.L[547]*work1d.v[199];
  work1d.v[712] = target[66]-work1d.L[548]*work1d.v[711];
  work1d.v[713] = target[760]-work1d.L[549]*work1d.v[200]-work1d.L[550]*work1d.v[712];
  work1d.v[714] = target[761]-work1d.L[551]*work1d.v[201]-work1d.L[552]*work1d.v[712]-work1d.L[553]*work1d.v[713];
  work1d.v[715] = target[762]-work1d.L[554]*work1d.v[202];
  work1d.v[716] = target[67]-work1d.L[555]*work1d.v[715];
  work1d.v[717] = target[763]-work1d.L[556]*work1d.v[203]-work1d.L[557]*work1d.v[716];
  work1d.v[718] = target[764]-work1d.L[558]*work1d.v[204]-work1d.L[559]*work1d.v[716]-work1d.L[560]*work1d.v[717];
  work1d.v[719] = target[765]-work1d.L[561]*work1d.v[205];
  work1d.v[720] = target[68]-work1d.L[562]*work1d.v[719];
  work1d.v[721] = target[766]-work1d.L[563]*work1d.v[206]-work1d.L[564]*work1d.v[720];
  work1d.v[722] = target[767]-work1d.L[565]*work1d.v[207]-work1d.L[566]*work1d.v[720]-work1d.L[567]*work1d.v[721];
  work1d.v[723] = target[768]-work1d.L[568]*work1d.v[208];
  work1d.v[724] = target[69]-work1d.L[569]*work1d.v[723];
  work1d.v[725] = target[769]-work1d.L[570]*work1d.v[209]-work1d.L[571]*work1d.v[724];
  work1d.v[726] = target[770]-work1d.L[572]*work1d.v[210]-work1d.L[573]*work1d.v[724]-work1d.L[574]*work1d.v[725];
  work1d.v[727] = target[771]-work1d.L[575]*work1d.v[211];
  work1d.v[728] = target[70]-work1d.L[576]*work1d.v[727];
  work1d.v[729] = target[772]-work1d.L[577]*work1d.v[212]-work1d.L[578]*work1d.v[728];
  work1d.v[730] = target[773]-work1d.L[579]*work1d.v[213]-work1d.L[580]*work1d.v[728]-work1d.L[581]*work1d.v[729];
  work1d.v[731] = target[774]-work1d.L[582]*work1d.v[214];
  work1d.v[732] = target[71]-work1d.L[583]*work1d.v[731];
  work1d.v[733] = target[775]-work1d.L[584]*work1d.v[215]-work1d.L[585]*work1d.v[732];
  work1d.v[734] = target[776]-work1d.L[586]*work1d.v[216]-work1d.L[587]*work1d.v[732]-work1d.L[588]*work1d.v[733];
  work1d.v[735] = target[777]-work1d.L[589]*work1d.v[217];
  work1d.v[736] = target[72]-work1d.L[590]*work1d.v[735];
  work1d.v[737] = target[778]-work1d.L[591]*work1d.v[218]-work1d.L[592]*work1d.v[736];
  work1d.v[738] = target[779]-work1d.L[593]*work1d.v[219]-work1d.L[594]*work1d.v[736]-work1d.L[595]*work1d.v[737];
  work1d.v[739] = target[780]-work1d.L[596]*work1d.v[220];
  work1d.v[740] = target[73]-work1d.L[597]*work1d.v[739];
  work1d.v[741] = target[781]-work1d.L[598]*work1d.v[221]-work1d.L[599]*work1d.v[740];
  work1d.v[742] = target[782]-work1d.L[600]*work1d.v[222]-work1d.L[601]*work1d.v[740]-work1d.L[602]*work1d.v[741];
  work1d.v[743] = target[783]-work1d.L[603]*work1d.v[223];
  work1d.v[744] = target[74]-work1d.L[604]*work1d.v[743];
  work1d.v[745] = target[784]-work1d.L[605]*work1d.v[224]-work1d.L[606]*work1d.v[744];
  work1d.v[746] = target[785]-work1d.L[607]*work1d.v[225]-work1d.L[608]*work1d.v[744]-work1d.L[609]*work1d.v[745];
  work1d.v[747] = target[786]-work1d.L[610]*work1d.v[226];
  work1d.v[748] = target[75]-work1d.L[611]*work1d.v[747];
  work1d.v[749] = target[787]-work1d.L[612]*work1d.v[227]-work1d.L[613]*work1d.v[748];
  work1d.v[750] = target[788]-work1d.L[614]*work1d.v[228]-work1d.L[615]*work1d.v[748]-work1d.L[616]*work1d.v[749];
  work1d.v[751] = target[789]-work1d.L[617]*work1d.v[229];
  work1d.v[752] = target[76]-work1d.L[618]*work1d.v[751];
  work1d.v[753] = target[790]-work1d.L[619]*work1d.v[230]-work1d.L[620]*work1d.v[752];
  work1d.v[754] = target[791]-work1d.L[621]*work1d.v[231]-work1d.L[622]*work1d.v[752]-work1d.L[623]*work1d.v[753];
  work1d.v[755] = target[792]-work1d.L[624]*work1d.v[232];
  work1d.v[756] = target[77]-work1d.L[625]*work1d.v[755];
  work1d.v[757] = target[793]-work1d.L[626]*work1d.v[233]-work1d.L[627]*work1d.v[756];
  work1d.v[758] = target[794]-work1d.L[628]*work1d.v[234]-work1d.L[629]*work1d.v[756]-work1d.L[630]*work1d.v[757];
  work1d.v[759] = target[795]-work1d.L[631]*work1d.v[235];
  work1d.v[760] = target[78]-work1d.L[632]*work1d.v[759];
  work1d.v[761] = target[796]-work1d.L[633]*work1d.v[236]-work1d.L[634]*work1d.v[760];
  work1d.v[762] = target[797]-work1d.L[635]*work1d.v[237]-work1d.L[636]*work1d.v[760]-work1d.L[637]*work1d.v[761];
  work1d.v[763] = target[798]-work1d.L[638]*work1d.v[238];
  work1d.v[764] = target[79]-work1d.L[639]*work1d.v[763];
  work1d.v[765] = target[799]-work1d.L[640]*work1d.v[239]-work1d.L[641]*work1d.v[764];
  work1d.v[766] = target[800]-work1d.L[642]*work1d.v[240]-work1d.L[643]*work1d.v[764]-work1d.L[644]*work1d.v[765];
  work1d.v[767] = target[240]-work1d.L[645]*work1d.v[400]-work1d.L[646]*work1d.v[765]-work1d.L[647]*work1d.v[766];
  work1d.v[768] = target[1000]-work1d.L[648]*work1d.v[443]-work1d.L[649]*work1d.v[767];
  work1d.v[769] = target[237]-work1d.L[650]*work1d.v[399]-work1d.L[651]*work1d.v[761]-work1d.L[652]*work1d.v[762]-work1d.L[653]*work1d.v[768];
  work1d.v[770] = target[884]-work1d.L[654]*work1d.v[444];
  work1d.v[771] = target[886]-work1d.L[655]*work1d.v[405];
  work1d.v[772] = target[889]-work1d.L[656]*work1d.v[406];
  work1d.v[773] = target[892]-work1d.L[657]*work1d.v[407];
  work1d.v[774] = target[895]-work1d.L[658]*work1d.v[408];
  work1d.v[775] = target[898]-work1d.L[659]*work1d.v[409];
  work1d.v[776] = target[901]-work1d.L[660]*work1d.v[410];
  work1d.v[777] = target[904]-work1d.L[661]*work1d.v[411];
  work1d.v[778] = target[907]-work1d.L[662]*work1d.v[412];
  work1d.v[779] = target[910]-work1d.L[663]*work1d.v[413];
  work1d.v[780] = target[913]-work1d.L[664]*work1d.v[414];
  work1d.v[781] = target[916]-work1d.L[665]*work1d.v[415];
  work1d.v[782] = target[919]-work1d.L[666]*work1d.v[416];
  work1d.v[783] = target[922]-work1d.L[667]*work1d.v[417];
  work1d.v[784] = target[925]-work1d.L[668]*work1d.v[418];
  work1d.v[785] = target[928]-work1d.L[669]*work1d.v[419];
  work1d.v[786] = target[931]-work1d.L[670]*work1d.v[420];
  work1d.v[787] = target[934]-work1d.L[671]*work1d.v[421];
  work1d.v[788] = target[937]-work1d.L[672]*work1d.v[422];
  work1d.v[789] = target[940]-work1d.L[673]*work1d.v[423];
  work1d.v[790] = target[943]-work1d.L[674]*work1d.v[424];
  work1d.v[791] = target[946]-work1d.L[675]*work1d.v[425];
  work1d.v[792] = target[949]-work1d.L[676]*work1d.v[426];
  work1d.v[793] = target[952]-work1d.L[677]*work1d.v[427];
  work1d.v[794] = target[955]-work1d.L[678]*work1d.v[428];
  work1d.v[795] = target[958]-work1d.L[679]*work1d.v[429];
  work1d.v[796] = target[961]-work1d.L[680]*work1d.v[430];
  work1d.v[797] = target[964]-work1d.L[681]*work1d.v[431];
  work1d.v[798] = target[967]-work1d.L[682]*work1d.v[432];
  work1d.v[799] = target[970]-work1d.L[683]*work1d.v[433];
  work1d.v[800] = target[973]-work1d.L[684]*work1d.v[434];
  work1d.v[801] = target[976]-work1d.L[685]*work1d.v[435];
  work1d.v[802] = target[979]-work1d.L[686]*work1d.v[436];
  work1d.v[803] = target[982]-work1d.L[687]*work1d.v[437];
  work1d.v[804] = target[985]-work1d.L[688]*work1d.v[438];
  work1d.v[805] = target[988]-work1d.L[689]*work1d.v[439];
  work1d.v[806] = target[991]-work1d.L[690]*work1d.v[440];
  work1d.v[807] = target[994]-work1d.L[691]*work1d.v[441];
  work1d.v[808] = target[997]-work1d.L[692]*work1d.v[442]-work1d.L[693]*work1d.v[769];
  work1d.v[809] = target[998]-work1d.L[694]*work1d.v[445];
  work1d.v[810] = target[999]-work1d.L[695]*work1d.v[606]-work1d.L[696]*work1d.v[769]-work1d.L[697]*work1d.v[808];
  work1d.v[811] = target[122]-work1d.L[698]*work1d.v[321]-work1d.L[699]*work1d.v[402]-work1d.L[700]*work1d.v[448]-work1d.L[701]*work1d.v[449]-work1d.L[702]*work1d.v[770];
  work1d.v[812] = target[123]-work1d.L[703]*work1d.v[361]-work1d.L[704]*work1d.v[404]-work1d.L[705]*work1d.v[609]-work1d.L[706]*work1d.v[610]-work1d.L[707]*work1d.v[771];
  work1d.v[813] = target[124]-work1d.L[708]*work1d.v[770]-work1d.L[709]*work1d.v[811];
  work1d.v[814] = target[127];
  work1d.v[815] = target[130];
  work1d.v[816] = target[133];
  work1d.v[817] = target[136];
  work1d.v[818] = target[139];
  work1d.v[819] = target[142];
  work1d.v[820] = target[145];
  work1d.v[821] = target[148];
  work1d.v[822] = target[151];
  work1d.v[823] = target[154];
  work1d.v[824] = target[157];
  work1d.v[825] = target[160];
  work1d.v[826] = target[163];
  work1d.v[827] = target[166];
  work1d.v[828] = target[169];
  work1d.v[829] = target[172];
  work1d.v[830] = target[175];
  work1d.v[831] = target[178];
  work1d.v[832] = target[181];
  work1d.v[833] = target[184];
  work1d.v[834] = target[187];
  work1d.v[835] = target[190];
  work1d.v[836] = target[193];
  work1d.v[837] = target[196];
  work1d.v[838] = target[199];
  work1d.v[839] = target[202];
  work1d.v[840] = target[205];
  work1d.v[841] = target[208];
  work1d.v[842] = target[211];
  work1d.v[843] = target[214];
  work1d.v[844] = target[217];
  work1d.v[845] = target[220];
  work1d.v[846] = target[223];
  work1d.v[847] = target[226];
  work1d.v[848] = target[229];
  work1d.v[849] = target[232];
  work1d.v[850] = target[235]-work1d.L[710]*work1d.v[809];
  work1d.v[851] = target[885]-work1d.L[711]*work1d.v[811]-work1d.L[712]*work1d.v[812]-work1d.L[713]*work1d.v[813];
  work1d.v[852] = target[125]-work1d.L[714]*work1d.v[322]-work1d.L[715]*work1d.v[452]-work1d.L[716]*work1d.v[453]-work1d.L[717]*work1d.v[851];
  work1d.v[853] = target[126]-work1d.L[718]*work1d.v[362]-work1d.L[719]*work1d.v[613]-work1d.L[720]*work1d.v[614]-work1d.L[721]*work1d.v[771]-work1d.L[722]*work1d.v[772]-work1d.L[723]*work1d.v[812]-work1d.L[724]*work1d.v[851]-work1d.L[725]*work1d.v[852];
  work1d.v[854] = target[887]-work1d.L[726]*work1d.v[813]-work1d.L[727]*work1d.v[814]-work1d.L[728]*work1d.v[851]-work1d.L[729]*work1d.v[852]-work1d.L[730]*work1d.v[853];
  work1d.v[855] = target[888]-work1d.L[731]*work1d.v[852]-work1d.L[732]*work1d.v[853]-work1d.L[733]*work1d.v[854];
  work1d.v[856] = target[128]-work1d.L[734]*work1d.v[323]-work1d.L[735]*work1d.v[456]-work1d.L[736]*work1d.v[457]-work1d.L[737]*work1d.v[855];
  work1d.v[857] = target[129]-work1d.L[738]*work1d.v[363]-work1d.L[739]*work1d.v[617]-work1d.L[740]*work1d.v[618]-work1d.L[741]*work1d.v[772]-work1d.L[742]*work1d.v[773]-work1d.L[743]*work1d.v[853]-work1d.L[744]*work1d.v[854]-work1d.L[745]*work1d.v[855]-work1d.L[746]*work1d.v[856];
  work1d.v[858] = target[890]-work1d.L[747]*work1d.v[814]-work1d.L[748]*work1d.v[815]-work1d.L[749]*work1d.v[854]-work1d.L[750]*work1d.v[855]-work1d.L[751]*work1d.v[856]-work1d.L[752]*work1d.v[857];
  work1d.v[859] = target[891]-work1d.L[753]*work1d.v[856]-work1d.L[754]*work1d.v[857]-work1d.L[755]*work1d.v[858];
  work1d.v[860] = target[131]-work1d.L[756]*work1d.v[324]-work1d.L[757]*work1d.v[460]-work1d.L[758]*work1d.v[461]-work1d.L[759]*work1d.v[859];
  work1d.v[861] = target[132]-work1d.L[760]*work1d.v[364]-work1d.L[761]*work1d.v[621]-work1d.L[762]*work1d.v[622]-work1d.L[763]*work1d.v[773]-work1d.L[764]*work1d.v[774]-work1d.L[765]*work1d.v[857]-work1d.L[766]*work1d.v[858]-work1d.L[767]*work1d.v[859]-work1d.L[768]*work1d.v[860];
  work1d.v[862] = target[893]-work1d.L[769]*work1d.v[815]-work1d.L[770]*work1d.v[816]-work1d.L[771]*work1d.v[858]-work1d.L[772]*work1d.v[859]-work1d.L[773]*work1d.v[860]-work1d.L[774]*work1d.v[861];
  work1d.v[863] = target[894]-work1d.L[775]*work1d.v[860]-work1d.L[776]*work1d.v[861]-work1d.L[777]*work1d.v[862];
  work1d.v[864] = target[134]-work1d.L[778]*work1d.v[325]-work1d.L[779]*work1d.v[464]-work1d.L[780]*work1d.v[465]-work1d.L[781]*work1d.v[863];
  work1d.v[865] = target[135]-work1d.L[782]*work1d.v[365]-work1d.L[783]*work1d.v[625]-work1d.L[784]*work1d.v[626]-work1d.L[785]*work1d.v[774]-work1d.L[786]*work1d.v[775]-work1d.L[787]*work1d.v[861]-work1d.L[788]*work1d.v[862]-work1d.L[789]*work1d.v[863]-work1d.L[790]*work1d.v[864];
  work1d.v[866] = target[896]-work1d.L[791]*work1d.v[816]-work1d.L[792]*work1d.v[817]-work1d.L[793]*work1d.v[862]-work1d.L[794]*work1d.v[863]-work1d.L[795]*work1d.v[864]-work1d.L[796]*work1d.v[865];
  work1d.v[867] = target[897]-work1d.L[797]*work1d.v[864]-work1d.L[798]*work1d.v[865]-work1d.L[799]*work1d.v[866];
  work1d.v[868] = target[137]-work1d.L[800]*work1d.v[326]-work1d.L[801]*work1d.v[468]-work1d.L[802]*work1d.v[469]-work1d.L[803]*work1d.v[867];
  work1d.v[869] = target[138]-work1d.L[804]*work1d.v[366]-work1d.L[805]*work1d.v[629]-work1d.L[806]*work1d.v[630]-work1d.L[807]*work1d.v[775]-work1d.L[808]*work1d.v[776]-work1d.L[809]*work1d.v[865]-work1d.L[810]*work1d.v[866]-work1d.L[811]*work1d.v[867]-work1d.L[812]*work1d.v[868];
  work1d.v[870] = target[899]-work1d.L[813]*work1d.v[817]-work1d.L[814]*work1d.v[818]-work1d.L[815]*work1d.v[866]-work1d.L[816]*work1d.v[867]-work1d.L[817]*work1d.v[868]-work1d.L[818]*work1d.v[869];
  work1d.v[871] = target[900]-work1d.L[819]*work1d.v[868]-work1d.L[820]*work1d.v[869]-work1d.L[821]*work1d.v[870];
  work1d.v[872] = target[140]-work1d.L[822]*work1d.v[327]-work1d.L[823]*work1d.v[472]-work1d.L[824]*work1d.v[473]-work1d.L[825]*work1d.v[871];
  work1d.v[873] = target[141]-work1d.L[826]*work1d.v[367]-work1d.L[827]*work1d.v[633]-work1d.L[828]*work1d.v[634]-work1d.L[829]*work1d.v[776]-work1d.L[830]*work1d.v[777]-work1d.L[831]*work1d.v[869]-work1d.L[832]*work1d.v[870]-work1d.L[833]*work1d.v[871]-work1d.L[834]*work1d.v[872];
  work1d.v[874] = target[902]-work1d.L[835]*work1d.v[818]-work1d.L[836]*work1d.v[819]-work1d.L[837]*work1d.v[870]-work1d.L[838]*work1d.v[871]-work1d.L[839]*work1d.v[872]-work1d.L[840]*work1d.v[873];
  work1d.v[875] = target[903]-work1d.L[841]*work1d.v[872]-work1d.L[842]*work1d.v[873]-work1d.L[843]*work1d.v[874];
  work1d.v[876] = target[143]-work1d.L[844]*work1d.v[328]-work1d.L[845]*work1d.v[476]-work1d.L[846]*work1d.v[477]-work1d.L[847]*work1d.v[875];
  work1d.v[877] = target[144]-work1d.L[848]*work1d.v[368]-work1d.L[849]*work1d.v[637]-work1d.L[850]*work1d.v[638]-work1d.L[851]*work1d.v[777]-work1d.L[852]*work1d.v[778]-work1d.L[853]*work1d.v[873]-work1d.L[854]*work1d.v[874]-work1d.L[855]*work1d.v[875]-work1d.L[856]*work1d.v[876];
  work1d.v[878] = target[905]-work1d.L[857]*work1d.v[819]-work1d.L[858]*work1d.v[820]-work1d.L[859]*work1d.v[874]-work1d.L[860]*work1d.v[875]-work1d.L[861]*work1d.v[876]-work1d.L[862]*work1d.v[877];
  work1d.v[879] = target[906]-work1d.L[863]*work1d.v[876]-work1d.L[864]*work1d.v[877]-work1d.L[865]*work1d.v[878];
  work1d.v[880] = target[146]-work1d.L[866]*work1d.v[329]-work1d.L[867]*work1d.v[480]-work1d.L[868]*work1d.v[481]-work1d.L[869]*work1d.v[879];
  work1d.v[881] = target[147]-work1d.L[870]*work1d.v[369]-work1d.L[871]*work1d.v[641]-work1d.L[872]*work1d.v[642]-work1d.L[873]*work1d.v[778]-work1d.L[874]*work1d.v[779]-work1d.L[875]*work1d.v[877]-work1d.L[876]*work1d.v[878]-work1d.L[877]*work1d.v[879]-work1d.L[878]*work1d.v[880];
  work1d.v[882] = target[908]-work1d.L[879]*work1d.v[820]-work1d.L[880]*work1d.v[821]-work1d.L[881]*work1d.v[878]-work1d.L[882]*work1d.v[879]-work1d.L[883]*work1d.v[880]-work1d.L[884]*work1d.v[881];
  work1d.v[883] = target[909]-work1d.L[885]*work1d.v[880]-work1d.L[886]*work1d.v[881]-work1d.L[887]*work1d.v[882];
  work1d.v[884] = target[149]-work1d.L[888]*work1d.v[330]-work1d.L[889]*work1d.v[484]-work1d.L[890]*work1d.v[485]-work1d.L[891]*work1d.v[883];
  work1d.v[885] = target[150]-work1d.L[892]*work1d.v[370]-work1d.L[893]*work1d.v[645]-work1d.L[894]*work1d.v[646]-work1d.L[895]*work1d.v[779]-work1d.L[896]*work1d.v[780]-work1d.L[897]*work1d.v[881]-work1d.L[898]*work1d.v[882]-work1d.L[899]*work1d.v[883]-work1d.L[900]*work1d.v[884];
  work1d.v[886] = target[911]-work1d.L[901]*work1d.v[821]-work1d.L[902]*work1d.v[822]-work1d.L[903]*work1d.v[882]-work1d.L[904]*work1d.v[883]-work1d.L[905]*work1d.v[884]-work1d.L[906]*work1d.v[885];
  work1d.v[887] = target[912]-work1d.L[907]*work1d.v[884]-work1d.L[908]*work1d.v[885]-work1d.L[909]*work1d.v[886];
  work1d.v[888] = target[152]-work1d.L[910]*work1d.v[331]-work1d.L[911]*work1d.v[488]-work1d.L[912]*work1d.v[489]-work1d.L[913]*work1d.v[887];
  work1d.v[889] = target[153]-work1d.L[914]*work1d.v[371]-work1d.L[915]*work1d.v[649]-work1d.L[916]*work1d.v[650]-work1d.L[917]*work1d.v[780]-work1d.L[918]*work1d.v[781]-work1d.L[919]*work1d.v[885]-work1d.L[920]*work1d.v[886]-work1d.L[921]*work1d.v[887]-work1d.L[922]*work1d.v[888];
  work1d.v[890] = target[914]-work1d.L[923]*work1d.v[822]-work1d.L[924]*work1d.v[823]-work1d.L[925]*work1d.v[886]-work1d.L[926]*work1d.v[887]-work1d.L[927]*work1d.v[888]-work1d.L[928]*work1d.v[889];
  work1d.v[891] = target[915]-work1d.L[929]*work1d.v[888]-work1d.L[930]*work1d.v[889]-work1d.L[931]*work1d.v[890];
  work1d.v[892] = target[155]-work1d.L[932]*work1d.v[332]-work1d.L[933]*work1d.v[492]-work1d.L[934]*work1d.v[493]-work1d.L[935]*work1d.v[891];
  work1d.v[893] = target[156]-work1d.L[936]*work1d.v[372]-work1d.L[937]*work1d.v[653]-work1d.L[938]*work1d.v[654]-work1d.L[939]*work1d.v[781]-work1d.L[940]*work1d.v[782]-work1d.L[941]*work1d.v[889]-work1d.L[942]*work1d.v[890]-work1d.L[943]*work1d.v[891]-work1d.L[944]*work1d.v[892];
  work1d.v[894] = target[917]-work1d.L[945]*work1d.v[823]-work1d.L[946]*work1d.v[824]-work1d.L[947]*work1d.v[890]-work1d.L[948]*work1d.v[891]-work1d.L[949]*work1d.v[892]-work1d.L[950]*work1d.v[893];
  work1d.v[895] = target[918]-work1d.L[951]*work1d.v[892]-work1d.L[952]*work1d.v[893]-work1d.L[953]*work1d.v[894];
  work1d.v[896] = target[158]-work1d.L[954]*work1d.v[333]-work1d.L[955]*work1d.v[496]-work1d.L[956]*work1d.v[497]-work1d.L[957]*work1d.v[895];
  work1d.v[897] = target[159]-work1d.L[958]*work1d.v[373]-work1d.L[959]*work1d.v[657]-work1d.L[960]*work1d.v[658]-work1d.L[961]*work1d.v[782]-work1d.L[962]*work1d.v[783]-work1d.L[963]*work1d.v[893]-work1d.L[964]*work1d.v[894]-work1d.L[965]*work1d.v[895]-work1d.L[966]*work1d.v[896];
  work1d.v[898] = target[920]-work1d.L[967]*work1d.v[824]-work1d.L[968]*work1d.v[825]-work1d.L[969]*work1d.v[894]-work1d.L[970]*work1d.v[895]-work1d.L[971]*work1d.v[896]-work1d.L[972]*work1d.v[897];
  work1d.v[899] = target[921]-work1d.L[973]*work1d.v[896]-work1d.L[974]*work1d.v[897]-work1d.L[975]*work1d.v[898];
  work1d.v[900] = target[161]-work1d.L[976]*work1d.v[334]-work1d.L[977]*work1d.v[500]-work1d.L[978]*work1d.v[501]-work1d.L[979]*work1d.v[899];
  work1d.v[901] = target[162]-work1d.L[980]*work1d.v[374]-work1d.L[981]*work1d.v[661]-work1d.L[982]*work1d.v[662]-work1d.L[983]*work1d.v[783]-work1d.L[984]*work1d.v[784]-work1d.L[985]*work1d.v[897]-work1d.L[986]*work1d.v[898]-work1d.L[987]*work1d.v[899]-work1d.L[988]*work1d.v[900];
  work1d.v[902] = target[923]-work1d.L[989]*work1d.v[825]-work1d.L[990]*work1d.v[826]-work1d.L[991]*work1d.v[898]-work1d.L[992]*work1d.v[899]-work1d.L[993]*work1d.v[900]-work1d.L[994]*work1d.v[901];
  work1d.v[903] = target[924]-work1d.L[995]*work1d.v[900]-work1d.L[996]*work1d.v[901]-work1d.L[997]*work1d.v[902];
  work1d.v[904] = target[164]-work1d.L[998]*work1d.v[335]-work1d.L[999]*work1d.v[504]-work1d.L[1000]*work1d.v[505]-work1d.L[1001]*work1d.v[903];
  work1d.v[905] = target[165]-work1d.L[1002]*work1d.v[375]-work1d.L[1003]*work1d.v[665]-work1d.L[1004]*work1d.v[666]-work1d.L[1005]*work1d.v[784]-work1d.L[1006]*work1d.v[785]-work1d.L[1007]*work1d.v[901]-work1d.L[1008]*work1d.v[902]-work1d.L[1009]*work1d.v[903]-work1d.L[1010]*work1d.v[904];
  work1d.v[906] = target[926]-work1d.L[1011]*work1d.v[826]-work1d.L[1012]*work1d.v[827]-work1d.L[1013]*work1d.v[902]-work1d.L[1014]*work1d.v[903]-work1d.L[1015]*work1d.v[904]-work1d.L[1016]*work1d.v[905];
  work1d.v[907] = target[927]-work1d.L[1017]*work1d.v[904]-work1d.L[1018]*work1d.v[905]-work1d.L[1019]*work1d.v[906];
  work1d.v[908] = target[167]-work1d.L[1020]*work1d.v[336]-work1d.L[1021]*work1d.v[508]-work1d.L[1022]*work1d.v[509]-work1d.L[1023]*work1d.v[907];
  work1d.v[909] = target[168]-work1d.L[1024]*work1d.v[376]-work1d.L[1025]*work1d.v[669]-work1d.L[1026]*work1d.v[670]-work1d.L[1027]*work1d.v[785]-work1d.L[1028]*work1d.v[786]-work1d.L[1029]*work1d.v[905]-work1d.L[1030]*work1d.v[906]-work1d.L[1031]*work1d.v[907]-work1d.L[1032]*work1d.v[908];
  work1d.v[910] = target[929]-work1d.L[1033]*work1d.v[827]-work1d.L[1034]*work1d.v[828]-work1d.L[1035]*work1d.v[906]-work1d.L[1036]*work1d.v[907]-work1d.L[1037]*work1d.v[908]-work1d.L[1038]*work1d.v[909];
  work1d.v[911] = target[930]-work1d.L[1039]*work1d.v[908]-work1d.L[1040]*work1d.v[909]-work1d.L[1041]*work1d.v[910];
  work1d.v[912] = target[170]-work1d.L[1042]*work1d.v[337]-work1d.L[1043]*work1d.v[512]-work1d.L[1044]*work1d.v[513]-work1d.L[1045]*work1d.v[911];
  work1d.v[913] = target[171]-work1d.L[1046]*work1d.v[377]-work1d.L[1047]*work1d.v[673]-work1d.L[1048]*work1d.v[674]-work1d.L[1049]*work1d.v[786]-work1d.L[1050]*work1d.v[787]-work1d.L[1051]*work1d.v[909]-work1d.L[1052]*work1d.v[910]-work1d.L[1053]*work1d.v[911]-work1d.L[1054]*work1d.v[912];
  work1d.v[914] = target[932]-work1d.L[1055]*work1d.v[828]-work1d.L[1056]*work1d.v[829]-work1d.L[1057]*work1d.v[910]-work1d.L[1058]*work1d.v[911]-work1d.L[1059]*work1d.v[912]-work1d.L[1060]*work1d.v[913];
  work1d.v[915] = target[933]-work1d.L[1061]*work1d.v[912]-work1d.L[1062]*work1d.v[913]-work1d.L[1063]*work1d.v[914];
  work1d.v[916] = target[173]-work1d.L[1064]*work1d.v[338]-work1d.L[1065]*work1d.v[516]-work1d.L[1066]*work1d.v[517]-work1d.L[1067]*work1d.v[915];
  work1d.v[917] = target[174]-work1d.L[1068]*work1d.v[378]-work1d.L[1069]*work1d.v[677]-work1d.L[1070]*work1d.v[678]-work1d.L[1071]*work1d.v[787]-work1d.L[1072]*work1d.v[788]-work1d.L[1073]*work1d.v[913]-work1d.L[1074]*work1d.v[914]-work1d.L[1075]*work1d.v[915]-work1d.L[1076]*work1d.v[916];
  work1d.v[918] = target[935]-work1d.L[1077]*work1d.v[829]-work1d.L[1078]*work1d.v[830]-work1d.L[1079]*work1d.v[914]-work1d.L[1080]*work1d.v[915]-work1d.L[1081]*work1d.v[916]-work1d.L[1082]*work1d.v[917];
  work1d.v[919] = target[936]-work1d.L[1083]*work1d.v[916]-work1d.L[1084]*work1d.v[917]-work1d.L[1085]*work1d.v[918];
  work1d.v[920] = target[176]-work1d.L[1086]*work1d.v[339]-work1d.L[1087]*work1d.v[520]-work1d.L[1088]*work1d.v[521]-work1d.L[1089]*work1d.v[919];
  work1d.v[921] = target[177]-work1d.L[1090]*work1d.v[379]-work1d.L[1091]*work1d.v[681]-work1d.L[1092]*work1d.v[682]-work1d.L[1093]*work1d.v[788]-work1d.L[1094]*work1d.v[789]-work1d.L[1095]*work1d.v[917]-work1d.L[1096]*work1d.v[918]-work1d.L[1097]*work1d.v[919]-work1d.L[1098]*work1d.v[920];
  work1d.v[922] = target[938]-work1d.L[1099]*work1d.v[830]-work1d.L[1100]*work1d.v[831]-work1d.L[1101]*work1d.v[918]-work1d.L[1102]*work1d.v[919]-work1d.L[1103]*work1d.v[920]-work1d.L[1104]*work1d.v[921];
  work1d.v[923] = target[939]-work1d.L[1105]*work1d.v[920]-work1d.L[1106]*work1d.v[921]-work1d.L[1107]*work1d.v[922];
  work1d.v[924] = target[179]-work1d.L[1108]*work1d.v[340]-work1d.L[1109]*work1d.v[524]-work1d.L[1110]*work1d.v[525]-work1d.L[1111]*work1d.v[923];
  work1d.v[925] = target[180]-work1d.L[1112]*work1d.v[380]-work1d.L[1113]*work1d.v[685]-work1d.L[1114]*work1d.v[686]-work1d.L[1115]*work1d.v[789]-work1d.L[1116]*work1d.v[790]-work1d.L[1117]*work1d.v[921]-work1d.L[1118]*work1d.v[922]-work1d.L[1119]*work1d.v[923]-work1d.L[1120]*work1d.v[924];
  work1d.v[926] = target[941]-work1d.L[1121]*work1d.v[831]-work1d.L[1122]*work1d.v[832]-work1d.L[1123]*work1d.v[922]-work1d.L[1124]*work1d.v[923]-work1d.L[1125]*work1d.v[924]-work1d.L[1126]*work1d.v[925];
  work1d.v[927] = target[942]-work1d.L[1127]*work1d.v[924]-work1d.L[1128]*work1d.v[925]-work1d.L[1129]*work1d.v[926];
  work1d.v[928] = target[182]-work1d.L[1130]*work1d.v[341]-work1d.L[1131]*work1d.v[528]-work1d.L[1132]*work1d.v[529]-work1d.L[1133]*work1d.v[927];
  work1d.v[929] = target[183]-work1d.L[1134]*work1d.v[381]-work1d.L[1135]*work1d.v[689]-work1d.L[1136]*work1d.v[690]-work1d.L[1137]*work1d.v[790]-work1d.L[1138]*work1d.v[791]-work1d.L[1139]*work1d.v[925]-work1d.L[1140]*work1d.v[926]-work1d.L[1141]*work1d.v[927]-work1d.L[1142]*work1d.v[928];
  work1d.v[930] = target[944]-work1d.L[1143]*work1d.v[832]-work1d.L[1144]*work1d.v[833]-work1d.L[1145]*work1d.v[926]-work1d.L[1146]*work1d.v[927]-work1d.L[1147]*work1d.v[928]-work1d.L[1148]*work1d.v[929];
  work1d.v[931] = target[945]-work1d.L[1149]*work1d.v[928]-work1d.L[1150]*work1d.v[929]-work1d.L[1151]*work1d.v[930];
  work1d.v[932] = target[185]-work1d.L[1152]*work1d.v[342]-work1d.L[1153]*work1d.v[532]-work1d.L[1154]*work1d.v[533]-work1d.L[1155]*work1d.v[931];
  work1d.v[933] = target[186]-work1d.L[1156]*work1d.v[382]-work1d.L[1157]*work1d.v[693]-work1d.L[1158]*work1d.v[694]-work1d.L[1159]*work1d.v[791]-work1d.L[1160]*work1d.v[792]-work1d.L[1161]*work1d.v[929]-work1d.L[1162]*work1d.v[930]-work1d.L[1163]*work1d.v[931]-work1d.L[1164]*work1d.v[932];
  work1d.v[934] = target[947]-work1d.L[1165]*work1d.v[833]-work1d.L[1166]*work1d.v[834]-work1d.L[1167]*work1d.v[930]-work1d.L[1168]*work1d.v[931]-work1d.L[1169]*work1d.v[932]-work1d.L[1170]*work1d.v[933];
  work1d.v[935] = target[948]-work1d.L[1171]*work1d.v[932]-work1d.L[1172]*work1d.v[933]-work1d.L[1173]*work1d.v[934];
  work1d.v[936] = target[188]-work1d.L[1174]*work1d.v[343]-work1d.L[1175]*work1d.v[536]-work1d.L[1176]*work1d.v[537]-work1d.L[1177]*work1d.v[935];
  work1d.v[937] = target[189]-work1d.L[1178]*work1d.v[383]-work1d.L[1179]*work1d.v[697]-work1d.L[1180]*work1d.v[698]-work1d.L[1181]*work1d.v[792]-work1d.L[1182]*work1d.v[793]-work1d.L[1183]*work1d.v[933]-work1d.L[1184]*work1d.v[934]-work1d.L[1185]*work1d.v[935]-work1d.L[1186]*work1d.v[936];
  work1d.v[938] = target[950]-work1d.L[1187]*work1d.v[834]-work1d.L[1188]*work1d.v[835]-work1d.L[1189]*work1d.v[934]-work1d.L[1190]*work1d.v[935]-work1d.L[1191]*work1d.v[936]-work1d.L[1192]*work1d.v[937];
  work1d.v[939] = target[951]-work1d.L[1193]*work1d.v[936]-work1d.L[1194]*work1d.v[937]-work1d.L[1195]*work1d.v[938];
  work1d.v[940] = target[191]-work1d.L[1196]*work1d.v[344]-work1d.L[1197]*work1d.v[540]-work1d.L[1198]*work1d.v[541]-work1d.L[1199]*work1d.v[939];
  work1d.v[941] = target[192]-work1d.L[1200]*work1d.v[384]-work1d.L[1201]*work1d.v[701]-work1d.L[1202]*work1d.v[702]-work1d.L[1203]*work1d.v[793]-work1d.L[1204]*work1d.v[794]-work1d.L[1205]*work1d.v[937]-work1d.L[1206]*work1d.v[938]-work1d.L[1207]*work1d.v[939]-work1d.L[1208]*work1d.v[940];
  work1d.v[942] = target[953]-work1d.L[1209]*work1d.v[835]-work1d.L[1210]*work1d.v[836]-work1d.L[1211]*work1d.v[938]-work1d.L[1212]*work1d.v[939]-work1d.L[1213]*work1d.v[940]-work1d.L[1214]*work1d.v[941];
  work1d.v[943] = target[954]-work1d.L[1215]*work1d.v[940]-work1d.L[1216]*work1d.v[941]-work1d.L[1217]*work1d.v[942];
  work1d.v[944] = target[194]-work1d.L[1218]*work1d.v[345]-work1d.L[1219]*work1d.v[544]-work1d.L[1220]*work1d.v[545]-work1d.L[1221]*work1d.v[943];
  work1d.v[945] = target[195]-work1d.L[1222]*work1d.v[385]-work1d.L[1223]*work1d.v[705]-work1d.L[1224]*work1d.v[706]-work1d.L[1225]*work1d.v[794]-work1d.L[1226]*work1d.v[795]-work1d.L[1227]*work1d.v[941]-work1d.L[1228]*work1d.v[942]-work1d.L[1229]*work1d.v[943]-work1d.L[1230]*work1d.v[944];
  work1d.v[946] = target[956]-work1d.L[1231]*work1d.v[836]-work1d.L[1232]*work1d.v[837]-work1d.L[1233]*work1d.v[942]-work1d.L[1234]*work1d.v[943]-work1d.L[1235]*work1d.v[944]-work1d.L[1236]*work1d.v[945];
  work1d.v[947] = target[957]-work1d.L[1237]*work1d.v[944]-work1d.L[1238]*work1d.v[945]-work1d.L[1239]*work1d.v[946];
  work1d.v[948] = target[197]-work1d.L[1240]*work1d.v[346]-work1d.L[1241]*work1d.v[548]-work1d.L[1242]*work1d.v[549]-work1d.L[1243]*work1d.v[947];
  work1d.v[949] = target[198]-work1d.L[1244]*work1d.v[386]-work1d.L[1245]*work1d.v[709]-work1d.L[1246]*work1d.v[710]-work1d.L[1247]*work1d.v[795]-work1d.L[1248]*work1d.v[796]-work1d.L[1249]*work1d.v[945]-work1d.L[1250]*work1d.v[946]-work1d.L[1251]*work1d.v[947]-work1d.L[1252]*work1d.v[948];
  work1d.v[950] = target[959]-work1d.L[1253]*work1d.v[837]-work1d.L[1254]*work1d.v[838]-work1d.L[1255]*work1d.v[946]-work1d.L[1256]*work1d.v[947]-work1d.L[1257]*work1d.v[948]-work1d.L[1258]*work1d.v[949];
  work1d.v[951] = target[960]-work1d.L[1259]*work1d.v[948]-work1d.L[1260]*work1d.v[949]-work1d.L[1261]*work1d.v[950];
  work1d.v[952] = target[200]-work1d.L[1262]*work1d.v[347]-work1d.L[1263]*work1d.v[552]-work1d.L[1264]*work1d.v[553]-work1d.L[1265]*work1d.v[951];
  work1d.v[953] = target[201]-work1d.L[1266]*work1d.v[387]-work1d.L[1267]*work1d.v[713]-work1d.L[1268]*work1d.v[714]-work1d.L[1269]*work1d.v[796]-work1d.L[1270]*work1d.v[797]-work1d.L[1271]*work1d.v[949]-work1d.L[1272]*work1d.v[950]-work1d.L[1273]*work1d.v[951]-work1d.L[1274]*work1d.v[952];
  work1d.v[954] = target[962]-work1d.L[1275]*work1d.v[838]-work1d.L[1276]*work1d.v[839]-work1d.L[1277]*work1d.v[950]-work1d.L[1278]*work1d.v[951]-work1d.L[1279]*work1d.v[952]-work1d.L[1280]*work1d.v[953];
  work1d.v[955] = target[963]-work1d.L[1281]*work1d.v[952]-work1d.L[1282]*work1d.v[953]-work1d.L[1283]*work1d.v[954];
  work1d.v[956] = target[203]-work1d.L[1284]*work1d.v[348]-work1d.L[1285]*work1d.v[556]-work1d.L[1286]*work1d.v[557]-work1d.L[1287]*work1d.v[955];
  work1d.v[957] = target[204]-work1d.L[1288]*work1d.v[388]-work1d.L[1289]*work1d.v[717]-work1d.L[1290]*work1d.v[718]-work1d.L[1291]*work1d.v[797]-work1d.L[1292]*work1d.v[798]-work1d.L[1293]*work1d.v[953]-work1d.L[1294]*work1d.v[954]-work1d.L[1295]*work1d.v[955]-work1d.L[1296]*work1d.v[956];
  work1d.v[958] = target[965]-work1d.L[1297]*work1d.v[839]-work1d.L[1298]*work1d.v[840]-work1d.L[1299]*work1d.v[954]-work1d.L[1300]*work1d.v[955]-work1d.L[1301]*work1d.v[956]-work1d.L[1302]*work1d.v[957];
  work1d.v[959] = target[966]-work1d.L[1303]*work1d.v[956]-work1d.L[1304]*work1d.v[957]-work1d.L[1305]*work1d.v[958];
  work1d.v[960] = target[206]-work1d.L[1306]*work1d.v[349]-work1d.L[1307]*work1d.v[560]-work1d.L[1308]*work1d.v[561]-work1d.L[1309]*work1d.v[959];
  work1d.v[961] = target[207]-work1d.L[1310]*work1d.v[389]-work1d.L[1311]*work1d.v[721]-work1d.L[1312]*work1d.v[722]-work1d.L[1313]*work1d.v[798]-work1d.L[1314]*work1d.v[799]-work1d.L[1315]*work1d.v[957]-work1d.L[1316]*work1d.v[958]-work1d.L[1317]*work1d.v[959]-work1d.L[1318]*work1d.v[960];
  work1d.v[962] = target[968]-work1d.L[1319]*work1d.v[840]-work1d.L[1320]*work1d.v[841]-work1d.L[1321]*work1d.v[958]-work1d.L[1322]*work1d.v[959]-work1d.L[1323]*work1d.v[960]-work1d.L[1324]*work1d.v[961];
  work1d.v[963] = target[969]-work1d.L[1325]*work1d.v[960]-work1d.L[1326]*work1d.v[961]-work1d.L[1327]*work1d.v[962];
  work1d.v[964] = target[209]-work1d.L[1328]*work1d.v[350]-work1d.L[1329]*work1d.v[564]-work1d.L[1330]*work1d.v[565]-work1d.L[1331]*work1d.v[963];
  work1d.v[965] = target[210]-work1d.L[1332]*work1d.v[390]-work1d.L[1333]*work1d.v[725]-work1d.L[1334]*work1d.v[726]-work1d.L[1335]*work1d.v[799]-work1d.L[1336]*work1d.v[800]-work1d.L[1337]*work1d.v[961]-work1d.L[1338]*work1d.v[962]-work1d.L[1339]*work1d.v[963]-work1d.L[1340]*work1d.v[964];
  work1d.v[966] = target[971]-work1d.L[1341]*work1d.v[841]-work1d.L[1342]*work1d.v[842]-work1d.L[1343]*work1d.v[962]-work1d.L[1344]*work1d.v[963]-work1d.L[1345]*work1d.v[964]-work1d.L[1346]*work1d.v[965];
  work1d.v[967] = target[972]-work1d.L[1347]*work1d.v[964]-work1d.L[1348]*work1d.v[965]-work1d.L[1349]*work1d.v[966];
  work1d.v[968] = target[212]-work1d.L[1350]*work1d.v[351]-work1d.L[1351]*work1d.v[568]-work1d.L[1352]*work1d.v[569]-work1d.L[1353]*work1d.v[967];
  work1d.v[969] = target[213]-work1d.L[1354]*work1d.v[391]-work1d.L[1355]*work1d.v[729]-work1d.L[1356]*work1d.v[730]-work1d.L[1357]*work1d.v[800]-work1d.L[1358]*work1d.v[801]-work1d.L[1359]*work1d.v[965]-work1d.L[1360]*work1d.v[966]-work1d.L[1361]*work1d.v[967]-work1d.L[1362]*work1d.v[968];
  work1d.v[970] = target[974]-work1d.L[1363]*work1d.v[842]-work1d.L[1364]*work1d.v[843]-work1d.L[1365]*work1d.v[966]-work1d.L[1366]*work1d.v[967]-work1d.L[1367]*work1d.v[968]-work1d.L[1368]*work1d.v[969];
  work1d.v[971] = target[975]-work1d.L[1369]*work1d.v[968]-work1d.L[1370]*work1d.v[969]-work1d.L[1371]*work1d.v[970];
  work1d.v[972] = target[215]-work1d.L[1372]*work1d.v[352]-work1d.L[1373]*work1d.v[572]-work1d.L[1374]*work1d.v[573]-work1d.L[1375]*work1d.v[971];
  work1d.v[973] = target[216]-work1d.L[1376]*work1d.v[392]-work1d.L[1377]*work1d.v[733]-work1d.L[1378]*work1d.v[734]-work1d.L[1379]*work1d.v[801]-work1d.L[1380]*work1d.v[802]-work1d.L[1381]*work1d.v[969]-work1d.L[1382]*work1d.v[970]-work1d.L[1383]*work1d.v[971]-work1d.L[1384]*work1d.v[972];
  work1d.v[974] = target[977]-work1d.L[1385]*work1d.v[843]-work1d.L[1386]*work1d.v[844]-work1d.L[1387]*work1d.v[970]-work1d.L[1388]*work1d.v[971]-work1d.L[1389]*work1d.v[972]-work1d.L[1390]*work1d.v[973];
  work1d.v[975] = target[978]-work1d.L[1391]*work1d.v[972]-work1d.L[1392]*work1d.v[973]-work1d.L[1393]*work1d.v[974];
  work1d.v[976] = target[218]-work1d.L[1394]*work1d.v[353]-work1d.L[1395]*work1d.v[576]-work1d.L[1396]*work1d.v[577]-work1d.L[1397]*work1d.v[975];
  work1d.v[977] = target[219]-work1d.L[1398]*work1d.v[393]-work1d.L[1399]*work1d.v[737]-work1d.L[1400]*work1d.v[738]-work1d.L[1401]*work1d.v[802]-work1d.L[1402]*work1d.v[803]-work1d.L[1403]*work1d.v[973]-work1d.L[1404]*work1d.v[974]-work1d.L[1405]*work1d.v[975]-work1d.L[1406]*work1d.v[976];
  work1d.v[978] = target[980]-work1d.L[1407]*work1d.v[844]-work1d.L[1408]*work1d.v[845]-work1d.L[1409]*work1d.v[974]-work1d.L[1410]*work1d.v[975]-work1d.L[1411]*work1d.v[976]-work1d.L[1412]*work1d.v[977];
  work1d.v[979] = target[981]-work1d.L[1413]*work1d.v[976]-work1d.L[1414]*work1d.v[977]-work1d.L[1415]*work1d.v[978];
  work1d.v[980] = target[221]-work1d.L[1416]*work1d.v[354]-work1d.L[1417]*work1d.v[580]-work1d.L[1418]*work1d.v[581]-work1d.L[1419]*work1d.v[979];
  work1d.v[981] = target[222]-work1d.L[1420]*work1d.v[394]-work1d.L[1421]*work1d.v[741]-work1d.L[1422]*work1d.v[742]-work1d.L[1423]*work1d.v[803]-work1d.L[1424]*work1d.v[804]-work1d.L[1425]*work1d.v[977]-work1d.L[1426]*work1d.v[978]-work1d.L[1427]*work1d.v[979]-work1d.L[1428]*work1d.v[980];
  work1d.v[982] = target[983]-work1d.L[1429]*work1d.v[845]-work1d.L[1430]*work1d.v[846]-work1d.L[1431]*work1d.v[978]-work1d.L[1432]*work1d.v[979]-work1d.L[1433]*work1d.v[980]-work1d.L[1434]*work1d.v[981];
  work1d.v[983] = target[984]-work1d.L[1435]*work1d.v[980]-work1d.L[1436]*work1d.v[981]-work1d.L[1437]*work1d.v[982];
  work1d.v[984] = target[224]-work1d.L[1438]*work1d.v[355]-work1d.L[1439]*work1d.v[584]-work1d.L[1440]*work1d.v[585]-work1d.L[1441]*work1d.v[983];
  work1d.v[985] = target[225]-work1d.L[1442]*work1d.v[395]-work1d.L[1443]*work1d.v[745]-work1d.L[1444]*work1d.v[746]-work1d.L[1445]*work1d.v[804]-work1d.L[1446]*work1d.v[805]-work1d.L[1447]*work1d.v[981]-work1d.L[1448]*work1d.v[982]-work1d.L[1449]*work1d.v[983]-work1d.L[1450]*work1d.v[984];
  work1d.v[986] = target[986]-work1d.L[1451]*work1d.v[846]-work1d.L[1452]*work1d.v[847]-work1d.L[1453]*work1d.v[982]-work1d.L[1454]*work1d.v[983]-work1d.L[1455]*work1d.v[984]-work1d.L[1456]*work1d.v[985];
  work1d.v[987] = target[987]-work1d.L[1457]*work1d.v[984]-work1d.L[1458]*work1d.v[985]-work1d.L[1459]*work1d.v[986];
  work1d.v[988] = target[227]-work1d.L[1460]*work1d.v[356]-work1d.L[1461]*work1d.v[588]-work1d.L[1462]*work1d.v[589]-work1d.L[1463]*work1d.v[987];
  work1d.v[989] = target[228]-work1d.L[1464]*work1d.v[396]-work1d.L[1465]*work1d.v[749]-work1d.L[1466]*work1d.v[750]-work1d.L[1467]*work1d.v[805]-work1d.L[1468]*work1d.v[806]-work1d.L[1469]*work1d.v[985]-work1d.L[1470]*work1d.v[986]-work1d.L[1471]*work1d.v[987]-work1d.L[1472]*work1d.v[988];
  work1d.v[990] = target[989]-work1d.L[1473]*work1d.v[847]-work1d.L[1474]*work1d.v[848]-work1d.L[1475]*work1d.v[986]-work1d.L[1476]*work1d.v[987]-work1d.L[1477]*work1d.v[988]-work1d.L[1478]*work1d.v[989];
  work1d.v[991] = target[990]-work1d.L[1479]*work1d.v[988]-work1d.L[1480]*work1d.v[989]-work1d.L[1481]*work1d.v[990];
  work1d.v[992] = target[230]-work1d.L[1482]*work1d.v[357]-work1d.L[1483]*work1d.v[592]-work1d.L[1484]*work1d.v[593]-work1d.L[1485]*work1d.v[991];
  work1d.v[993] = target[231]-work1d.L[1486]*work1d.v[397]-work1d.L[1487]*work1d.v[753]-work1d.L[1488]*work1d.v[754]-work1d.L[1489]*work1d.v[806]-work1d.L[1490]*work1d.v[807]-work1d.L[1491]*work1d.v[989]-work1d.L[1492]*work1d.v[990]-work1d.L[1493]*work1d.v[991]-work1d.L[1494]*work1d.v[992];
  work1d.v[994] = target[992]-work1d.L[1495]*work1d.v[848]-work1d.L[1496]*work1d.v[849]-work1d.L[1497]*work1d.v[990]-work1d.L[1498]*work1d.v[991]-work1d.L[1499]*work1d.v[992]-work1d.L[1500]*work1d.v[993];
  work1d.v[995] = target[993]-work1d.L[1501]*work1d.v[992]-work1d.L[1502]*work1d.v[993]-work1d.L[1503]*work1d.v[994];
  work1d.v[996] = target[995]-work1d.L[1504]*work1d.v[849]-work1d.L[1505]*work1d.v[850]-work1d.L[1506]*work1d.v[994]-work1d.L[1507]*work1d.v[995];
  work1d.v[997] = target[996];
  work1d.v[998] = target[233]-work1d.L[1508]*work1d.v[358]-work1d.L[1509]*work1d.v[596]-work1d.L[1510]*work1d.v[597]-work1d.L[1511]*work1d.v[995]-work1d.L[1512]*work1d.v[996]-work1d.L[1513]*work1d.v[997];
  work1d.v[999] = target[234]-work1d.L[1514]*work1d.v[398]-work1d.L[1515]*work1d.v[757]-work1d.L[1516]*work1d.v[758]-work1d.L[1517]*work1d.v[807]-work1d.L[1518]*work1d.v[808]-work1d.L[1519]*work1d.v[810]-work1d.L[1520]*work1d.v[993]-work1d.L[1521]*work1d.v[994]-work1d.L[1522]*work1d.v[995]-work1d.L[1523]*work1d.v[996]-work1d.L[1524]*work1d.v[997]-work1d.L[1525]*work1d.v[998];
  work1d.v[1000] = target[236]-work1d.L[1526]*work1d.v[359]-work1d.L[1527]*work1d.v[600]-work1d.L[1528]*work1d.v[601]-work1d.L[1529]*work1d.v[809]-work1d.L[1530]*work1d.v[810]-work1d.L[1531]*work1d.v[850]-work1d.L[1532]*work1d.v[996]-work1d.L[1533]*work1d.v[997]-work1d.L[1534]*work1d.v[998]-work1d.L[1535]*work1d.v[999];
  /* Diagonal scaling. Assume correctness of work1d.d_inv. */
  for (i = 0; i < 1001; i++)
    work1d.v[i] *= work1d.d_inv[i];
  /* Back substitution */
  work1d.v[999] -= work1d.L[1535]*work1d.v[1000];
  work1d.v[998] -= work1d.L[1525]*work1d.v[999]+work1d.L[1534]*work1d.v[1000];
  work1d.v[997] -= work1d.L[1513]*work1d.v[998]+work1d.L[1524]*work1d.v[999]+work1d.L[1533]*work1d.v[1000];
  work1d.v[996] -= work1d.L[1512]*work1d.v[998]+work1d.L[1523]*work1d.v[999]+work1d.L[1532]*work1d.v[1000];
  work1d.v[995] -= work1d.L[1507]*work1d.v[996]+work1d.L[1511]*work1d.v[998]+work1d.L[1522]*work1d.v[999];
  work1d.v[994] -= work1d.L[1503]*work1d.v[995]+work1d.L[1506]*work1d.v[996]+work1d.L[1521]*work1d.v[999];
  work1d.v[993] -= work1d.L[1500]*work1d.v[994]+work1d.L[1502]*work1d.v[995]+work1d.L[1520]*work1d.v[999];
  work1d.v[992] -= work1d.L[1494]*work1d.v[993]+work1d.L[1499]*work1d.v[994]+work1d.L[1501]*work1d.v[995];
  work1d.v[991] -= work1d.L[1485]*work1d.v[992]+work1d.L[1493]*work1d.v[993]+work1d.L[1498]*work1d.v[994];
  work1d.v[990] -= work1d.L[1481]*work1d.v[991]+work1d.L[1492]*work1d.v[993]+work1d.L[1497]*work1d.v[994];
  work1d.v[989] -= work1d.L[1478]*work1d.v[990]+work1d.L[1480]*work1d.v[991]+work1d.L[1491]*work1d.v[993];
  work1d.v[988] -= work1d.L[1472]*work1d.v[989]+work1d.L[1477]*work1d.v[990]+work1d.L[1479]*work1d.v[991];
  work1d.v[987] -= work1d.L[1463]*work1d.v[988]+work1d.L[1471]*work1d.v[989]+work1d.L[1476]*work1d.v[990];
  work1d.v[986] -= work1d.L[1459]*work1d.v[987]+work1d.L[1470]*work1d.v[989]+work1d.L[1475]*work1d.v[990];
  work1d.v[985] -= work1d.L[1456]*work1d.v[986]+work1d.L[1458]*work1d.v[987]+work1d.L[1469]*work1d.v[989];
  work1d.v[984] -= work1d.L[1450]*work1d.v[985]+work1d.L[1455]*work1d.v[986]+work1d.L[1457]*work1d.v[987];
  work1d.v[983] -= work1d.L[1441]*work1d.v[984]+work1d.L[1449]*work1d.v[985]+work1d.L[1454]*work1d.v[986];
  work1d.v[982] -= work1d.L[1437]*work1d.v[983]+work1d.L[1448]*work1d.v[985]+work1d.L[1453]*work1d.v[986];
  work1d.v[981] -= work1d.L[1434]*work1d.v[982]+work1d.L[1436]*work1d.v[983]+work1d.L[1447]*work1d.v[985];
  work1d.v[980] -= work1d.L[1428]*work1d.v[981]+work1d.L[1433]*work1d.v[982]+work1d.L[1435]*work1d.v[983];
  work1d.v[979] -= work1d.L[1419]*work1d.v[980]+work1d.L[1427]*work1d.v[981]+work1d.L[1432]*work1d.v[982];
  work1d.v[978] -= work1d.L[1415]*work1d.v[979]+work1d.L[1426]*work1d.v[981]+work1d.L[1431]*work1d.v[982];
  work1d.v[977] -= work1d.L[1412]*work1d.v[978]+work1d.L[1414]*work1d.v[979]+work1d.L[1425]*work1d.v[981];
  work1d.v[976] -= work1d.L[1406]*work1d.v[977]+work1d.L[1411]*work1d.v[978]+work1d.L[1413]*work1d.v[979];
  work1d.v[975] -= work1d.L[1397]*work1d.v[976]+work1d.L[1405]*work1d.v[977]+work1d.L[1410]*work1d.v[978];
  work1d.v[974] -= work1d.L[1393]*work1d.v[975]+work1d.L[1404]*work1d.v[977]+work1d.L[1409]*work1d.v[978];
  work1d.v[973] -= work1d.L[1390]*work1d.v[974]+work1d.L[1392]*work1d.v[975]+work1d.L[1403]*work1d.v[977];
  work1d.v[972] -= work1d.L[1384]*work1d.v[973]+work1d.L[1389]*work1d.v[974]+work1d.L[1391]*work1d.v[975];
  work1d.v[971] -= work1d.L[1375]*work1d.v[972]+work1d.L[1383]*work1d.v[973]+work1d.L[1388]*work1d.v[974];
  work1d.v[970] -= work1d.L[1371]*work1d.v[971]+work1d.L[1382]*work1d.v[973]+work1d.L[1387]*work1d.v[974];
  work1d.v[969] -= work1d.L[1368]*work1d.v[970]+work1d.L[1370]*work1d.v[971]+work1d.L[1381]*work1d.v[973];
  work1d.v[968] -= work1d.L[1362]*work1d.v[969]+work1d.L[1367]*work1d.v[970]+work1d.L[1369]*work1d.v[971];
  work1d.v[967] -= work1d.L[1353]*work1d.v[968]+work1d.L[1361]*work1d.v[969]+work1d.L[1366]*work1d.v[970];
  work1d.v[966] -= work1d.L[1349]*work1d.v[967]+work1d.L[1360]*work1d.v[969]+work1d.L[1365]*work1d.v[970];
  work1d.v[965] -= work1d.L[1346]*work1d.v[966]+work1d.L[1348]*work1d.v[967]+work1d.L[1359]*work1d.v[969];
  work1d.v[964] -= work1d.L[1340]*work1d.v[965]+work1d.L[1345]*work1d.v[966]+work1d.L[1347]*work1d.v[967];
  work1d.v[963] -= work1d.L[1331]*work1d.v[964]+work1d.L[1339]*work1d.v[965]+work1d.L[1344]*work1d.v[966];
  work1d.v[962] -= work1d.L[1327]*work1d.v[963]+work1d.L[1338]*work1d.v[965]+work1d.L[1343]*work1d.v[966];
  work1d.v[961] -= work1d.L[1324]*work1d.v[962]+work1d.L[1326]*work1d.v[963]+work1d.L[1337]*work1d.v[965];
  work1d.v[960] -= work1d.L[1318]*work1d.v[961]+work1d.L[1323]*work1d.v[962]+work1d.L[1325]*work1d.v[963];
  work1d.v[959] -= work1d.L[1309]*work1d.v[960]+work1d.L[1317]*work1d.v[961]+work1d.L[1322]*work1d.v[962];
  work1d.v[958] -= work1d.L[1305]*work1d.v[959]+work1d.L[1316]*work1d.v[961]+work1d.L[1321]*work1d.v[962];
  work1d.v[957] -= work1d.L[1302]*work1d.v[958]+work1d.L[1304]*work1d.v[959]+work1d.L[1315]*work1d.v[961];
  work1d.v[956] -= work1d.L[1296]*work1d.v[957]+work1d.L[1301]*work1d.v[958]+work1d.L[1303]*work1d.v[959];
  work1d.v[955] -= work1d.L[1287]*work1d.v[956]+work1d.L[1295]*work1d.v[957]+work1d.L[1300]*work1d.v[958];
  work1d.v[954] -= work1d.L[1283]*work1d.v[955]+work1d.L[1294]*work1d.v[957]+work1d.L[1299]*work1d.v[958];
  work1d.v[953] -= work1d.L[1280]*work1d.v[954]+work1d.L[1282]*work1d.v[955]+work1d.L[1293]*work1d.v[957];
  work1d.v[952] -= work1d.L[1274]*work1d.v[953]+work1d.L[1279]*work1d.v[954]+work1d.L[1281]*work1d.v[955];
  work1d.v[951] -= work1d.L[1265]*work1d.v[952]+work1d.L[1273]*work1d.v[953]+work1d.L[1278]*work1d.v[954];
  work1d.v[950] -= work1d.L[1261]*work1d.v[951]+work1d.L[1272]*work1d.v[953]+work1d.L[1277]*work1d.v[954];
  work1d.v[949] -= work1d.L[1258]*work1d.v[950]+work1d.L[1260]*work1d.v[951]+work1d.L[1271]*work1d.v[953];
  work1d.v[948] -= work1d.L[1252]*work1d.v[949]+work1d.L[1257]*work1d.v[950]+work1d.L[1259]*work1d.v[951];
  work1d.v[947] -= work1d.L[1243]*work1d.v[948]+work1d.L[1251]*work1d.v[949]+work1d.L[1256]*work1d.v[950];
  work1d.v[946] -= work1d.L[1239]*work1d.v[947]+work1d.L[1250]*work1d.v[949]+work1d.L[1255]*work1d.v[950];
  work1d.v[945] -= work1d.L[1236]*work1d.v[946]+work1d.L[1238]*work1d.v[947]+work1d.L[1249]*work1d.v[949];
  work1d.v[944] -= work1d.L[1230]*work1d.v[945]+work1d.L[1235]*work1d.v[946]+work1d.L[1237]*work1d.v[947];
  work1d.v[943] -= work1d.L[1221]*work1d.v[944]+work1d.L[1229]*work1d.v[945]+work1d.L[1234]*work1d.v[946];
  work1d.v[942] -= work1d.L[1217]*work1d.v[943]+work1d.L[1228]*work1d.v[945]+work1d.L[1233]*work1d.v[946];
  work1d.v[941] -= work1d.L[1214]*work1d.v[942]+work1d.L[1216]*work1d.v[943]+work1d.L[1227]*work1d.v[945];
  work1d.v[940] -= work1d.L[1208]*work1d.v[941]+work1d.L[1213]*work1d.v[942]+work1d.L[1215]*work1d.v[943];
  work1d.v[939] -= work1d.L[1199]*work1d.v[940]+work1d.L[1207]*work1d.v[941]+work1d.L[1212]*work1d.v[942];
  work1d.v[938] -= work1d.L[1195]*work1d.v[939]+work1d.L[1206]*work1d.v[941]+work1d.L[1211]*work1d.v[942];
  work1d.v[937] -= work1d.L[1192]*work1d.v[938]+work1d.L[1194]*work1d.v[939]+work1d.L[1205]*work1d.v[941];
  work1d.v[936] -= work1d.L[1186]*work1d.v[937]+work1d.L[1191]*work1d.v[938]+work1d.L[1193]*work1d.v[939];
  work1d.v[935] -= work1d.L[1177]*work1d.v[936]+work1d.L[1185]*work1d.v[937]+work1d.L[1190]*work1d.v[938];
  work1d.v[934] -= work1d.L[1173]*work1d.v[935]+work1d.L[1184]*work1d.v[937]+work1d.L[1189]*work1d.v[938];
  work1d.v[933] -= work1d.L[1170]*work1d.v[934]+work1d.L[1172]*work1d.v[935]+work1d.L[1183]*work1d.v[937];
  work1d.v[932] -= work1d.L[1164]*work1d.v[933]+work1d.L[1169]*work1d.v[934]+work1d.L[1171]*work1d.v[935];
  work1d.v[931] -= work1d.L[1155]*work1d.v[932]+work1d.L[1163]*work1d.v[933]+work1d.L[1168]*work1d.v[934];
  work1d.v[930] -= work1d.L[1151]*work1d.v[931]+work1d.L[1162]*work1d.v[933]+work1d.L[1167]*work1d.v[934];
  work1d.v[929] -= work1d.L[1148]*work1d.v[930]+work1d.L[1150]*work1d.v[931]+work1d.L[1161]*work1d.v[933];
  work1d.v[928] -= work1d.L[1142]*work1d.v[929]+work1d.L[1147]*work1d.v[930]+work1d.L[1149]*work1d.v[931];
  work1d.v[927] -= work1d.L[1133]*work1d.v[928]+work1d.L[1141]*work1d.v[929]+work1d.L[1146]*work1d.v[930];
  work1d.v[926] -= work1d.L[1129]*work1d.v[927]+work1d.L[1140]*work1d.v[929]+work1d.L[1145]*work1d.v[930];
  work1d.v[925] -= work1d.L[1126]*work1d.v[926]+work1d.L[1128]*work1d.v[927]+work1d.L[1139]*work1d.v[929];
  work1d.v[924] -= work1d.L[1120]*work1d.v[925]+work1d.L[1125]*work1d.v[926]+work1d.L[1127]*work1d.v[927];
  work1d.v[923] -= work1d.L[1111]*work1d.v[924]+work1d.L[1119]*work1d.v[925]+work1d.L[1124]*work1d.v[926];
  work1d.v[922] -= work1d.L[1107]*work1d.v[923]+work1d.L[1118]*work1d.v[925]+work1d.L[1123]*work1d.v[926];
  work1d.v[921] -= work1d.L[1104]*work1d.v[922]+work1d.L[1106]*work1d.v[923]+work1d.L[1117]*work1d.v[925];
  work1d.v[920] -= work1d.L[1098]*work1d.v[921]+work1d.L[1103]*work1d.v[922]+work1d.L[1105]*work1d.v[923];
  work1d.v[919] -= work1d.L[1089]*work1d.v[920]+work1d.L[1097]*work1d.v[921]+work1d.L[1102]*work1d.v[922];
  work1d.v[918] -= work1d.L[1085]*work1d.v[919]+work1d.L[1096]*work1d.v[921]+work1d.L[1101]*work1d.v[922];
  work1d.v[917] -= work1d.L[1082]*work1d.v[918]+work1d.L[1084]*work1d.v[919]+work1d.L[1095]*work1d.v[921];
  work1d.v[916] -= work1d.L[1076]*work1d.v[917]+work1d.L[1081]*work1d.v[918]+work1d.L[1083]*work1d.v[919];
  work1d.v[915] -= work1d.L[1067]*work1d.v[916]+work1d.L[1075]*work1d.v[917]+work1d.L[1080]*work1d.v[918];
  work1d.v[914] -= work1d.L[1063]*work1d.v[915]+work1d.L[1074]*work1d.v[917]+work1d.L[1079]*work1d.v[918];
  work1d.v[913] -= work1d.L[1060]*work1d.v[914]+work1d.L[1062]*work1d.v[915]+work1d.L[1073]*work1d.v[917];
  work1d.v[912] -= work1d.L[1054]*work1d.v[913]+work1d.L[1059]*work1d.v[914]+work1d.L[1061]*work1d.v[915];
  work1d.v[911] -= work1d.L[1045]*work1d.v[912]+work1d.L[1053]*work1d.v[913]+work1d.L[1058]*work1d.v[914];
  work1d.v[910] -= work1d.L[1041]*work1d.v[911]+work1d.L[1052]*work1d.v[913]+work1d.L[1057]*work1d.v[914];
  work1d.v[909] -= work1d.L[1038]*work1d.v[910]+work1d.L[1040]*work1d.v[911]+work1d.L[1051]*work1d.v[913];
  work1d.v[908] -= work1d.L[1032]*work1d.v[909]+work1d.L[1037]*work1d.v[910]+work1d.L[1039]*work1d.v[911];
  work1d.v[907] -= work1d.L[1023]*work1d.v[908]+work1d.L[1031]*work1d.v[909]+work1d.L[1036]*work1d.v[910];
  work1d.v[906] -= work1d.L[1019]*work1d.v[907]+work1d.L[1030]*work1d.v[909]+work1d.L[1035]*work1d.v[910];
  work1d.v[905] -= work1d.L[1016]*work1d.v[906]+work1d.L[1018]*work1d.v[907]+work1d.L[1029]*work1d.v[909];
  work1d.v[904] -= work1d.L[1010]*work1d.v[905]+work1d.L[1015]*work1d.v[906]+work1d.L[1017]*work1d.v[907];
  work1d.v[903] -= work1d.L[1001]*work1d.v[904]+work1d.L[1009]*work1d.v[905]+work1d.L[1014]*work1d.v[906];
  work1d.v[902] -= work1d.L[997]*work1d.v[903]+work1d.L[1008]*work1d.v[905]+work1d.L[1013]*work1d.v[906];
  work1d.v[901] -= work1d.L[994]*work1d.v[902]+work1d.L[996]*work1d.v[903]+work1d.L[1007]*work1d.v[905];
  work1d.v[900] -= work1d.L[988]*work1d.v[901]+work1d.L[993]*work1d.v[902]+work1d.L[995]*work1d.v[903];
  work1d.v[899] -= work1d.L[979]*work1d.v[900]+work1d.L[987]*work1d.v[901]+work1d.L[992]*work1d.v[902];
  work1d.v[898] -= work1d.L[975]*work1d.v[899]+work1d.L[986]*work1d.v[901]+work1d.L[991]*work1d.v[902];
  work1d.v[897] -= work1d.L[972]*work1d.v[898]+work1d.L[974]*work1d.v[899]+work1d.L[985]*work1d.v[901];
  work1d.v[896] -= work1d.L[966]*work1d.v[897]+work1d.L[971]*work1d.v[898]+work1d.L[973]*work1d.v[899];
  work1d.v[895] -= work1d.L[957]*work1d.v[896]+work1d.L[965]*work1d.v[897]+work1d.L[970]*work1d.v[898];
  work1d.v[894] -= work1d.L[953]*work1d.v[895]+work1d.L[964]*work1d.v[897]+work1d.L[969]*work1d.v[898];
  work1d.v[893] -= work1d.L[950]*work1d.v[894]+work1d.L[952]*work1d.v[895]+work1d.L[963]*work1d.v[897];
  work1d.v[892] -= work1d.L[944]*work1d.v[893]+work1d.L[949]*work1d.v[894]+work1d.L[951]*work1d.v[895];
  work1d.v[891] -= work1d.L[935]*work1d.v[892]+work1d.L[943]*work1d.v[893]+work1d.L[948]*work1d.v[894];
  work1d.v[890] -= work1d.L[931]*work1d.v[891]+work1d.L[942]*work1d.v[893]+work1d.L[947]*work1d.v[894];
  work1d.v[889] -= work1d.L[928]*work1d.v[890]+work1d.L[930]*work1d.v[891]+work1d.L[941]*work1d.v[893];
  work1d.v[888] -= work1d.L[922]*work1d.v[889]+work1d.L[927]*work1d.v[890]+work1d.L[929]*work1d.v[891];
  work1d.v[887] -= work1d.L[913]*work1d.v[888]+work1d.L[921]*work1d.v[889]+work1d.L[926]*work1d.v[890];
  work1d.v[886] -= work1d.L[909]*work1d.v[887]+work1d.L[920]*work1d.v[889]+work1d.L[925]*work1d.v[890];
  work1d.v[885] -= work1d.L[906]*work1d.v[886]+work1d.L[908]*work1d.v[887]+work1d.L[919]*work1d.v[889];
  work1d.v[884] -= work1d.L[900]*work1d.v[885]+work1d.L[905]*work1d.v[886]+work1d.L[907]*work1d.v[887];
  work1d.v[883] -= work1d.L[891]*work1d.v[884]+work1d.L[899]*work1d.v[885]+work1d.L[904]*work1d.v[886];
  work1d.v[882] -= work1d.L[887]*work1d.v[883]+work1d.L[898]*work1d.v[885]+work1d.L[903]*work1d.v[886];
  work1d.v[881] -= work1d.L[884]*work1d.v[882]+work1d.L[886]*work1d.v[883]+work1d.L[897]*work1d.v[885];
  work1d.v[880] -= work1d.L[878]*work1d.v[881]+work1d.L[883]*work1d.v[882]+work1d.L[885]*work1d.v[883];
  work1d.v[879] -= work1d.L[869]*work1d.v[880]+work1d.L[877]*work1d.v[881]+work1d.L[882]*work1d.v[882];
  work1d.v[878] -= work1d.L[865]*work1d.v[879]+work1d.L[876]*work1d.v[881]+work1d.L[881]*work1d.v[882];
  work1d.v[877] -= work1d.L[862]*work1d.v[878]+work1d.L[864]*work1d.v[879]+work1d.L[875]*work1d.v[881];
  work1d.v[876] -= work1d.L[856]*work1d.v[877]+work1d.L[861]*work1d.v[878]+work1d.L[863]*work1d.v[879];
  work1d.v[875] -= work1d.L[847]*work1d.v[876]+work1d.L[855]*work1d.v[877]+work1d.L[860]*work1d.v[878];
  work1d.v[874] -= work1d.L[843]*work1d.v[875]+work1d.L[854]*work1d.v[877]+work1d.L[859]*work1d.v[878];
  work1d.v[873] -= work1d.L[840]*work1d.v[874]+work1d.L[842]*work1d.v[875]+work1d.L[853]*work1d.v[877];
  work1d.v[872] -= work1d.L[834]*work1d.v[873]+work1d.L[839]*work1d.v[874]+work1d.L[841]*work1d.v[875];
  work1d.v[871] -= work1d.L[825]*work1d.v[872]+work1d.L[833]*work1d.v[873]+work1d.L[838]*work1d.v[874];
  work1d.v[870] -= work1d.L[821]*work1d.v[871]+work1d.L[832]*work1d.v[873]+work1d.L[837]*work1d.v[874];
  work1d.v[869] -= work1d.L[818]*work1d.v[870]+work1d.L[820]*work1d.v[871]+work1d.L[831]*work1d.v[873];
  work1d.v[868] -= work1d.L[812]*work1d.v[869]+work1d.L[817]*work1d.v[870]+work1d.L[819]*work1d.v[871];
  work1d.v[867] -= work1d.L[803]*work1d.v[868]+work1d.L[811]*work1d.v[869]+work1d.L[816]*work1d.v[870];
  work1d.v[866] -= work1d.L[799]*work1d.v[867]+work1d.L[810]*work1d.v[869]+work1d.L[815]*work1d.v[870];
  work1d.v[865] -= work1d.L[796]*work1d.v[866]+work1d.L[798]*work1d.v[867]+work1d.L[809]*work1d.v[869];
  work1d.v[864] -= work1d.L[790]*work1d.v[865]+work1d.L[795]*work1d.v[866]+work1d.L[797]*work1d.v[867];
  work1d.v[863] -= work1d.L[781]*work1d.v[864]+work1d.L[789]*work1d.v[865]+work1d.L[794]*work1d.v[866];
  work1d.v[862] -= work1d.L[777]*work1d.v[863]+work1d.L[788]*work1d.v[865]+work1d.L[793]*work1d.v[866];
  work1d.v[861] -= work1d.L[774]*work1d.v[862]+work1d.L[776]*work1d.v[863]+work1d.L[787]*work1d.v[865];
  work1d.v[860] -= work1d.L[768]*work1d.v[861]+work1d.L[773]*work1d.v[862]+work1d.L[775]*work1d.v[863];
  work1d.v[859] -= work1d.L[759]*work1d.v[860]+work1d.L[767]*work1d.v[861]+work1d.L[772]*work1d.v[862];
  work1d.v[858] -= work1d.L[755]*work1d.v[859]+work1d.L[766]*work1d.v[861]+work1d.L[771]*work1d.v[862];
  work1d.v[857] -= work1d.L[752]*work1d.v[858]+work1d.L[754]*work1d.v[859]+work1d.L[765]*work1d.v[861];
  work1d.v[856] -= work1d.L[746]*work1d.v[857]+work1d.L[751]*work1d.v[858]+work1d.L[753]*work1d.v[859];
  work1d.v[855] -= work1d.L[737]*work1d.v[856]+work1d.L[745]*work1d.v[857]+work1d.L[750]*work1d.v[858];
  work1d.v[854] -= work1d.L[733]*work1d.v[855]+work1d.L[744]*work1d.v[857]+work1d.L[749]*work1d.v[858];
  work1d.v[853] -= work1d.L[730]*work1d.v[854]+work1d.L[732]*work1d.v[855]+work1d.L[743]*work1d.v[857];
  work1d.v[852] -= work1d.L[725]*work1d.v[853]+work1d.L[729]*work1d.v[854]+work1d.L[731]*work1d.v[855];
  work1d.v[851] -= work1d.L[717]*work1d.v[852]+work1d.L[724]*work1d.v[853]+work1d.L[728]*work1d.v[854];
  work1d.v[850] -= work1d.L[1505]*work1d.v[996]+work1d.L[1531]*work1d.v[1000];
  work1d.v[849] -= work1d.L[1496]*work1d.v[994]+work1d.L[1504]*work1d.v[996];
  work1d.v[848] -= work1d.L[1474]*work1d.v[990]+work1d.L[1495]*work1d.v[994];
  work1d.v[847] -= work1d.L[1452]*work1d.v[986]+work1d.L[1473]*work1d.v[990];
  work1d.v[846] -= work1d.L[1430]*work1d.v[982]+work1d.L[1451]*work1d.v[986];
  work1d.v[845] -= work1d.L[1408]*work1d.v[978]+work1d.L[1429]*work1d.v[982];
  work1d.v[844] -= work1d.L[1386]*work1d.v[974]+work1d.L[1407]*work1d.v[978];
  work1d.v[843] -= work1d.L[1364]*work1d.v[970]+work1d.L[1385]*work1d.v[974];
  work1d.v[842] -= work1d.L[1342]*work1d.v[966]+work1d.L[1363]*work1d.v[970];
  work1d.v[841] -= work1d.L[1320]*work1d.v[962]+work1d.L[1341]*work1d.v[966];
  work1d.v[840] -= work1d.L[1298]*work1d.v[958]+work1d.L[1319]*work1d.v[962];
  work1d.v[839] -= work1d.L[1276]*work1d.v[954]+work1d.L[1297]*work1d.v[958];
  work1d.v[838] -= work1d.L[1254]*work1d.v[950]+work1d.L[1275]*work1d.v[954];
  work1d.v[837] -= work1d.L[1232]*work1d.v[946]+work1d.L[1253]*work1d.v[950];
  work1d.v[836] -= work1d.L[1210]*work1d.v[942]+work1d.L[1231]*work1d.v[946];
  work1d.v[835] -= work1d.L[1188]*work1d.v[938]+work1d.L[1209]*work1d.v[942];
  work1d.v[834] -= work1d.L[1166]*work1d.v[934]+work1d.L[1187]*work1d.v[938];
  work1d.v[833] -= work1d.L[1144]*work1d.v[930]+work1d.L[1165]*work1d.v[934];
  work1d.v[832] -= work1d.L[1122]*work1d.v[926]+work1d.L[1143]*work1d.v[930];
  work1d.v[831] -= work1d.L[1100]*work1d.v[922]+work1d.L[1121]*work1d.v[926];
  work1d.v[830] -= work1d.L[1078]*work1d.v[918]+work1d.L[1099]*work1d.v[922];
  work1d.v[829] -= work1d.L[1056]*work1d.v[914]+work1d.L[1077]*work1d.v[918];
  work1d.v[828] -= work1d.L[1034]*work1d.v[910]+work1d.L[1055]*work1d.v[914];
  work1d.v[827] -= work1d.L[1012]*work1d.v[906]+work1d.L[1033]*work1d.v[910];
  work1d.v[826] -= work1d.L[990]*work1d.v[902]+work1d.L[1011]*work1d.v[906];
  work1d.v[825] -= work1d.L[968]*work1d.v[898]+work1d.L[989]*work1d.v[902];
  work1d.v[824] -= work1d.L[946]*work1d.v[894]+work1d.L[967]*work1d.v[898];
  work1d.v[823] -= work1d.L[924]*work1d.v[890]+work1d.L[945]*work1d.v[894];
  work1d.v[822] -= work1d.L[902]*work1d.v[886]+work1d.L[923]*work1d.v[890];
  work1d.v[821] -= work1d.L[880]*work1d.v[882]+work1d.L[901]*work1d.v[886];
  work1d.v[820] -= work1d.L[858]*work1d.v[878]+work1d.L[879]*work1d.v[882];
  work1d.v[819] -= work1d.L[836]*work1d.v[874]+work1d.L[857]*work1d.v[878];
  work1d.v[818] -= work1d.L[814]*work1d.v[870]+work1d.L[835]*work1d.v[874];
  work1d.v[817] -= work1d.L[792]*work1d.v[866]+work1d.L[813]*work1d.v[870];
  work1d.v[816] -= work1d.L[770]*work1d.v[862]+work1d.L[791]*work1d.v[866];
  work1d.v[815] -= work1d.L[748]*work1d.v[858]+work1d.L[769]*work1d.v[862];
  work1d.v[814] -= work1d.L[727]*work1d.v[854]+work1d.L[747]*work1d.v[858];
  work1d.v[813] -= work1d.L[713]*work1d.v[851]+work1d.L[726]*work1d.v[854];
  work1d.v[812] -= work1d.L[712]*work1d.v[851]+work1d.L[723]*work1d.v[853];
  work1d.v[811] -= work1d.L[709]*work1d.v[813]+work1d.L[711]*work1d.v[851];
  work1d.v[810] -= work1d.L[1519]*work1d.v[999]+work1d.L[1530]*work1d.v[1000];
  work1d.v[809] -= work1d.L[710]*work1d.v[850]+work1d.L[1529]*work1d.v[1000];
  work1d.v[808] -= work1d.L[697]*work1d.v[810]+work1d.L[1518]*work1d.v[999];
  work1d.v[807] -= work1d.L[1490]*work1d.v[993]+work1d.L[1517]*work1d.v[999];
  work1d.v[806] -= work1d.L[1468]*work1d.v[989]+work1d.L[1489]*work1d.v[993];
  work1d.v[805] -= work1d.L[1446]*work1d.v[985]+work1d.L[1467]*work1d.v[989];
  work1d.v[804] -= work1d.L[1424]*work1d.v[981]+work1d.L[1445]*work1d.v[985];
  work1d.v[803] -= work1d.L[1402]*work1d.v[977]+work1d.L[1423]*work1d.v[981];
  work1d.v[802] -= work1d.L[1380]*work1d.v[973]+work1d.L[1401]*work1d.v[977];
  work1d.v[801] -= work1d.L[1358]*work1d.v[969]+work1d.L[1379]*work1d.v[973];
  work1d.v[800] -= work1d.L[1336]*work1d.v[965]+work1d.L[1357]*work1d.v[969];
  work1d.v[799] -= work1d.L[1314]*work1d.v[961]+work1d.L[1335]*work1d.v[965];
  work1d.v[798] -= work1d.L[1292]*work1d.v[957]+work1d.L[1313]*work1d.v[961];
  work1d.v[797] -= work1d.L[1270]*work1d.v[953]+work1d.L[1291]*work1d.v[957];
  work1d.v[796] -= work1d.L[1248]*work1d.v[949]+work1d.L[1269]*work1d.v[953];
  work1d.v[795] -= work1d.L[1226]*work1d.v[945]+work1d.L[1247]*work1d.v[949];
  work1d.v[794] -= work1d.L[1204]*work1d.v[941]+work1d.L[1225]*work1d.v[945];
  work1d.v[793] -= work1d.L[1182]*work1d.v[937]+work1d.L[1203]*work1d.v[941];
  work1d.v[792] -= work1d.L[1160]*work1d.v[933]+work1d.L[1181]*work1d.v[937];
  work1d.v[791] -= work1d.L[1138]*work1d.v[929]+work1d.L[1159]*work1d.v[933];
  work1d.v[790] -= work1d.L[1116]*work1d.v[925]+work1d.L[1137]*work1d.v[929];
  work1d.v[789] -= work1d.L[1094]*work1d.v[921]+work1d.L[1115]*work1d.v[925];
  work1d.v[788] -= work1d.L[1072]*work1d.v[917]+work1d.L[1093]*work1d.v[921];
  work1d.v[787] -= work1d.L[1050]*work1d.v[913]+work1d.L[1071]*work1d.v[917];
  work1d.v[786] -= work1d.L[1028]*work1d.v[909]+work1d.L[1049]*work1d.v[913];
  work1d.v[785] -= work1d.L[1006]*work1d.v[905]+work1d.L[1027]*work1d.v[909];
  work1d.v[784] -= work1d.L[984]*work1d.v[901]+work1d.L[1005]*work1d.v[905];
  work1d.v[783] -= work1d.L[962]*work1d.v[897]+work1d.L[983]*work1d.v[901];
  work1d.v[782] -= work1d.L[940]*work1d.v[893]+work1d.L[961]*work1d.v[897];
  work1d.v[781] -= work1d.L[918]*work1d.v[889]+work1d.L[939]*work1d.v[893];
  work1d.v[780] -= work1d.L[896]*work1d.v[885]+work1d.L[917]*work1d.v[889];
  work1d.v[779] -= work1d.L[874]*work1d.v[881]+work1d.L[895]*work1d.v[885];
  work1d.v[778] -= work1d.L[852]*work1d.v[877]+work1d.L[873]*work1d.v[881];
  work1d.v[777] -= work1d.L[830]*work1d.v[873]+work1d.L[851]*work1d.v[877];
  work1d.v[776] -= work1d.L[808]*work1d.v[869]+work1d.L[829]*work1d.v[873];
  work1d.v[775] -= work1d.L[786]*work1d.v[865]+work1d.L[807]*work1d.v[869];
  work1d.v[774] -= work1d.L[764]*work1d.v[861]+work1d.L[785]*work1d.v[865];
  work1d.v[773] -= work1d.L[742]*work1d.v[857]+work1d.L[763]*work1d.v[861];
  work1d.v[772] -= work1d.L[722]*work1d.v[853]+work1d.L[741]*work1d.v[857];
  work1d.v[771] -= work1d.L[707]*work1d.v[812]+work1d.L[721]*work1d.v[853];
  work1d.v[770] -= work1d.L[702]*work1d.v[811]+work1d.L[708]*work1d.v[813];
  work1d.v[769] -= work1d.L[693]*work1d.v[808]+work1d.L[696]*work1d.v[810];
  work1d.v[768] -= work1d.L[653]*work1d.v[769];
  work1d.v[767] -= work1d.L[649]*work1d.v[768];
  work1d.v[766] -= work1d.L[647]*work1d.v[767];
  work1d.v[765] -= work1d.L[644]*work1d.v[766]+work1d.L[646]*work1d.v[767];
  work1d.v[764] -= work1d.L[641]*work1d.v[765]+work1d.L[643]*work1d.v[766];
  work1d.v[763] -= work1d.L[639]*work1d.v[764];
  work1d.v[762] -= work1d.L[652]*work1d.v[769];
  work1d.v[761] -= work1d.L[637]*work1d.v[762]+work1d.L[651]*work1d.v[769];
  work1d.v[760] -= work1d.L[634]*work1d.v[761]+work1d.L[636]*work1d.v[762];
  work1d.v[759] -= work1d.L[632]*work1d.v[760];
  work1d.v[758] -= work1d.L[1516]*work1d.v[999];
  work1d.v[757] -= work1d.L[630]*work1d.v[758]+work1d.L[1515]*work1d.v[999];
  work1d.v[756] -= work1d.L[627]*work1d.v[757]+work1d.L[629]*work1d.v[758];
  work1d.v[755] -= work1d.L[625]*work1d.v[756];
  work1d.v[754] -= work1d.L[1488]*work1d.v[993];
  work1d.v[753] -= work1d.L[623]*work1d.v[754]+work1d.L[1487]*work1d.v[993];
  work1d.v[752] -= work1d.L[620]*work1d.v[753]+work1d.L[622]*work1d.v[754];
  work1d.v[751] -= work1d.L[618]*work1d.v[752];
  work1d.v[750] -= work1d.L[1466]*work1d.v[989];
  work1d.v[749] -= work1d.L[616]*work1d.v[750]+work1d.L[1465]*work1d.v[989];
  work1d.v[748] -= work1d.L[613]*work1d.v[749]+work1d.L[615]*work1d.v[750];
  work1d.v[747] -= work1d.L[611]*work1d.v[748];
  work1d.v[746] -= work1d.L[1444]*work1d.v[985];
  work1d.v[745] -= work1d.L[609]*work1d.v[746]+work1d.L[1443]*work1d.v[985];
  work1d.v[744] -= work1d.L[606]*work1d.v[745]+work1d.L[608]*work1d.v[746];
  work1d.v[743] -= work1d.L[604]*work1d.v[744];
  work1d.v[742] -= work1d.L[1422]*work1d.v[981];
  work1d.v[741] -= work1d.L[602]*work1d.v[742]+work1d.L[1421]*work1d.v[981];
  work1d.v[740] -= work1d.L[599]*work1d.v[741]+work1d.L[601]*work1d.v[742];
  work1d.v[739] -= work1d.L[597]*work1d.v[740];
  work1d.v[738] -= work1d.L[1400]*work1d.v[977];
  work1d.v[737] -= work1d.L[595]*work1d.v[738]+work1d.L[1399]*work1d.v[977];
  work1d.v[736] -= work1d.L[592]*work1d.v[737]+work1d.L[594]*work1d.v[738];
  work1d.v[735] -= work1d.L[590]*work1d.v[736];
  work1d.v[734] -= work1d.L[1378]*work1d.v[973];
  work1d.v[733] -= work1d.L[588]*work1d.v[734]+work1d.L[1377]*work1d.v[973];
  work1d.v[732] -= work1d.L[585]*work1d.v[733]+work1d.L[587]*work1d.v[734];
  work1d.v[731] -= work1d.L[583]*work1d.v[732];
  work1d.v[730] -= work1d.L[1356]*work1d.v[969];
  work1d.v[729] -= work1d.L[581]*work1d.v[730]+work1d.L[1355]*work1d.v[969];
  work1d.v[728] -= work1d.L[578]*work1d.v[729]+work1d.L[580]*work1d.v[730];
  work1d.v[727] -= work1d.L[576]*work1d.v[728];
  work1d.v[726] -= work1d.L[1334]*work1d.v[965];
  work1d.v[725] -= work1d.L[574]*work1d.v[726]+work1d.L[1333]*work1d.v[965];
  work1d.v[724] -= work1d.L[571]*work1d.v[725]+work1d.L[573]*work1d.v[726];
  work1d.v[723] -= work1d.L[569]*work1d.v[724];
  work1d.v[722] -= work1d.L[1312]*work1d.v[961];
  work1d.v[721] -= work1d.L[567]*work1d.v[722]+work1d.L[1311]*work1d.v[961];
  work1d.v[720] -= work1d.L[564]*work1d.v[721]+work1d.L[566]*work1d.v[722];
  work1d.v[719] -= work1d.L[562]*work1d.v[720];
  work1d.v[718] -= work1d.L[1290]*work1d.v[957];
  work1d.v[717] -= work1d.L[560]*work1d.v[718]+work1d.L[1289]*work1d.v[957];
  work1d.v[716] -= work1d.L[557]*work1d.v[717]+work1d.L[559]*work1d.v[718];
  work1d.v[715] -= work1d.L[555]*work1d.v[716];
  work1d.v[714] -= work1d.L[1268]*work1d.v[953];
  work1d.v[713] -= work1d.L[553]*work1d.v[714]+work1d.L[1267]*work1d.v[953];
  work1d.v[712] -= work1d.L[550]*work1d.v[713]+work1d.L[552]*work1d.v[714];
  work1d.v[711] -= work1d.L[548]*work1d.v[712];
  work1d.v[710] -= work1d.L[1246]*work1d.v[949];
  work1d.v[709] -= work1d.L[546]*work1d.v[710]+work1d.L[1245]*work1d.v[949];
  work1d.v[708] -= work1d.L[543]*work1d.v[709]+work1d.L[545]*work1d.v[710];
  work1d.v[707] -= work1d.L[541]*work1d.v[708];
  work1d.v[706] -= work1d.L[1224]*work1d.v[945];
  work1d.v[705] -= work1d.L[539]*work1d.v[706]+work1d.L[1223]*work1d.v[945];
  work1d.v[704] -= work1d.L[536]*work1d.v[705]+work1d.L[538]*work1d.v[706];
  work1d.v[703] -= work1d.L[534]*work1d.v[704];
  work1d.v[702] -= work1d.L[1202]*work1d.v[941];
  work1d.v[701] -= work1d.L[532]*work1d.v[702]+work1d.L[1201]*work1d.v[941];
  work1d.v[700] -= work1d.L[529]*work1d.v[701]+work1d.L[531]*work1d.v[702];
  work1d.v[699] -= work1d.L[527]*work1d.v[700];
  work1d.v[698] -= work1d.L[1180]*work1d.v[937];
  work1d.v[697] -= work1d.L[525]*work1d.v[698]+work1d.L[1179]*work1d.v[937];
  work1d.v[696] -= work1d.L[522]*work1d.v[697]+work1d.L[524]*work1d.v[698];
  work1d.v[695] -= work1d.L[520]*work1d.v[696];
  work1d.v[694] -= work1d.L[1158]*work1d.v[933];
  work1d.v[693] -= work1d.L[518]*work1d.v[694]+work1d.L[1157]*work1d.v[933];
  work1d.v[692] -= work1d.L[515]*work1d.v[693]+work1d.L[517]*work1d.v[694];
  work1d.v[691] -= work1d.L[513]*work1d.v[692];
  work1d.v[690] -= work1d.L[1136]*work1d.v[929];
  work1d.v[689] -= work1d.L[511]*work1d.v[690]+work1d.L[1135]*work1d.v[929];
  work1d.v[688] -= work1d.L[508]*work1d.v[689]+work1d.L[510]*work1d.v[690];
  work1d.v[687] -= work1d.L[506]*work1d.v[688];
  work1d.v[686] -= work1d.L[1114]*work1d.v[925];
  work1d.v[685] -= work1d.L[504]*work1d.v[686]+work1d.L[1113]*work1d.v[925];
  work1d.v[684] -= work1d.L[501]*work1d.v[685]+work1d.L[503]*work1d.v[686];
  work1d.v[683] -= work1d.L[499]*work1d.v[684];
  work1d.v[682] -= work1d.L[1092]*work1d.v[921];
  work1d.v[681] -= work1d.L[497]*work1d.v[682]+work1d.L[1091]*work1d.v[921];
  work1d.v[680] -= work1d.L[494]*work1d.v[681]+work1d.L[496]*work1d.v[682];
  work1d.v[679] -= work1d.L[492]*work1d.v[680];
  work1d.v[678] -= work1d.L[1070]*work1d.v[917];
  work1d.v[677] -= work1d.L[490]*work1d.v[678]+work1d.L[1069]*work1d.v[917];
  work1d.v[676] -= work1d.L[487]*work1d.v[677]+work1d.L[489]*work1d.v[678];
  work1d.v[675] -= work1d.L[485]*work1d.v[676];
  work1d.v[674] -= work1d.L[1048]*work1d.v[913];
  work1d.v[673] -= work1d.L[483]*work1d.v[674]+work1d.L[1047]*work1d.v[913];
  work1d.v[672] -= work1d.L[480]*work1d.v[673]+work1d.L[482]*work1d.v[674];
  work1d.v[671] -= work1d.L[478]*work1d.v[672];
  work1d.v[670] -= work1d.L[1026]*work1d.v[909];
  work1d.v[669] -= work1d.L[476]*work1d.v[670]+work1d.L[1025]*work1d.v[909];
  work1d.v[668] -= work1d.L[473]*work1d.v[669]+work1d.L[475]*work1d.v[670];
  work1d.v[667] -= work1d.L[471]*work1d.v[668];
  work1d.v[666] -= work1d.L[1004]*work1d.v[905];
  work1d.v[665] -= work1d.L[469]*work1d.v[666]+work1d.L[1003]*work1d.v[905];
  work1d.v[664] -= work1d.L[466]*work1d.v[665]+work1d.L[468]*work1d.v[666];
  work1d.v[663] -= work1d.L[464]*work1d.v[664];
  work1d.v[662] -= work1d.L[982]*work1d.v[901];
  work1d.v[661] -= work1d.L[462]*work1d.v[662]+work1d.L[981]*work1d.v[901];
  work1d.v[660] -= work1d.L[459]*work1d.v[661]+work1d.L[461]*work1d.v[662];
  work1d.v[659] -= work1d.L[457]*work1d.v[660];
  work1d.v[658] -= work1d.L[960]*work1d.v[897];
  work1d.v[657] -= work1d.L[455]*work1d.v[658]+work1d.L[959]*work1d.v[897];
  work1d.v[656] -= work1d.L[452]*work1d.v[657]+work1d.L[454]*work1d.v[658];
  work1d.v[655] -= work1d.L[450]*work1d.v[656];
  work1d.v[654] -= work1d.L[938]*work1d.v[893];
  work1d.v[653] -= work1d.L[448]*work1d.v[654]+work1d.L[937]*work1d.v[893];
  work1d.v[652] -= work1d.L[445]*work1d.v[653]+work1d.L[447]*work1d.v[654];
  work1d.v[651] -= work1d.L[443]*work1d.v[652];
  work1d.v[650] -= work1d.L[916]*work1d.v[889];
  work1d.v[649] -= work1d.L[441]*work1d.v[650]+work1d.L[915]*work1d.v[889];
  work1d.v[648] -= work1d.L[438]*work1d.v[649]+work1d.L[440]*work1d.v[650];
  work1d.v[647] -= work1d.L[436]*work1d.v[648];
  work1d.v[646] -= work1d.L[894]*work1d.v[885];
  work1d.v[645] -= work1d.L[434]*work1d.v[646]+work1d.L[893]*work1d.v[885];
  work1d.v[644] -= work1d.L[431]*work1d.v[645]+work1d.L[433]*work1d.v[646];
  work1d.v[643] -= work1d.L[429]*work1d.v[644];
  work1d.v[642] -= work1d.L[872]*work1d.v[881];
  work1d.v[641] -= work1d.L[427]*work1d.v[642]+work1d.L[871]*work1d.v[881];
  work1d.v[640] -= work1d.L[424]*work1d.v[641]+work1d.L[426]*work1d.v[642];
  work1d.v[639] -= work1d.L[422]*work1d.v[640];
  work1d.v[638] -= work1d.L[850]*work1d.v[877];
  work1d.v[637] -= work1d.L[420]*work1d.v[638]+work1d.L[849]*work1d.v[877];
  work1d.v[636] -= work1d.L[417]*work1d.v[637]+work1d.L[419]*work1d.v[638];
  work1d.v[635] -= work1d.L[415]*work1d.v[636];
  work1d.v[634] -= work1d.L[828]*work1d.v[873];
  work1d.v[633] -= work1d.L[413]*work1d.v[634]+work1d.L[827]*work1d.v[873];
  work1d.v[632] -= work1d.L[410]*work1d.v[633]+work1d.L[412]*work1d.v[634];
  work1d.v[631] -= work1d.L[408]*work1d.v[632];
  work1d.v[630] -= work1d.L[806]*work1d.v[869];
  work1d.v[629] -= work1d.L[406]*work1d.v[630]+work1d.L[805]*work1d.v[869];
  work1d.v[628] -= work1d.L[403]*work1d.v[629]+work1d.L[405]*work1d.v[630];
  work1d.v[627] -= work1d.L[401]*work1d.v[628];
  work1d.v[626] -= work1d.L[784]*work1d.v[865];
  work1d.v[625] -= work1d.L[399]*work1d.v[626]+work1d.L[783]*work1d.v[865];
  work1d.v[624] -= work1d.L[396]*work1d.v[625]+work1d.L[398]*work1d.v[626];
  work1d.v[623] -= work1d.L[394]*work1d.v[624];
  work1d.v[622] -= work1d.L[762]*work1d.v[861];
  work1d.v[621] -= work1d.L[392]*work1d.v[622]+work1d.L[761]*work1d.v[861];
  work1d.v[620] -= work1d.L[389]*work1d.v[621]+work1d.L[391]*work1d.v[622];
  work1d.v[619] -= work1d.L[387]*work1d.v[620];
  work1d.v[618] -= work1d.L[740]*work1d.v[857];
  work1d.v[617] -= work1d.L[385]*work1d.v[618]+work1d.L[739]*work1d.v[857];
  work1d.v[616] -= work1d.L[382]*work1d.v[617]+work1d.L[384]*work1d.v[618];
  work1d.v[615] -= work1d.L[380]*work1d.v[616];
  work1d.v[614] -= work1d.L[720]*work1d.v[853];
  work1d.v[613] -= work1d.L[378]*work1d.v[614]+work1d.L[719]*work1d.v[853];
  work1d.v[612] -= work1d.L[375]*work1d.v[613]+work1d.L[377]*work1d.v[614];
  work1d.v[611] -= work1d.L[373]*work1d.v[612];
  work1d.v[610] -= work1d.L[706]*work1d.v[812];
  work1d.v[609] -= work1d.L[371]*work1d.v[610]+work1d.L[705]*work1d.v[812];
  work1d.v[608] -= work1d.L[368]*work1d.v[609]+work1d.L[370]*work1d.v[610];
  work1d.v[607] -= work1d.L[366]*work1d.v[608];
  work1d.v[606] -= work1d.L[695]*work1d.v[810];
  work1d.v[605] -= work1d.L[364]*work1d.v[606];
  work1d.v[604] -= work1d.L[361]*work1d.v[605]+work1d.L[363]*work1d.v[606];
  work1d.v[603] -= work1d.L[358]*work1d.v[604]+work1d.L[360]*work1d.v[605];
  work1d.v[602] -= work1d.L[356]*work1d.v[603];
  work1d.v[601] -= work1d.L[1528]*work1d.v[1000];
  work1d.v[600] -= work1d.L[354]*work1d.v[601]+work1d.L[1527]*work1d.v[1000];
  work1d.v[599] -= work1d.L[351]*work1d.v[600]+work1d.L[353]*work1d.v[601];
  work1d.v[598] -= work1d.L[349]*work1d.v[599];
  work1d.v[597] -= work1d.L[1510]*work1d.v[998];
  work1d.v[596] -= work1d.L[347]*work1d.v[597]+work1d.L[1509]*work1d.v[998];
  work1d.v[595] -= work1d.L[344]*work1d.v[596]+work1d.L[346]*work1d.v[597];
  work1d.v[594] -= work1d.L[342]*work1d.v[595];
  work1d.v[593] -= work1d.L[1484]*work1d.v[992];
  work1d.v[592] -= work1d.L[340]*work1d.v[593]+work1d.L[1483]*work1d.v[992];
  work1d.v[591] -= work1d.L[337]*work1d.v[592]+work1d.L[339]*work1d.v[593];
  work1d.v[590] -= work1d.L[335]*work1d.v[591];
  work1d.v[589] -= work1d.L[1462]*work1d.v[988];
  work1d.v[588] -= work1d.L[333]*work1d.v[589]+work1d.L[1461]*work1d.v[988];
  work1d.v[587] -= work1d.L[330]*work1d.v[588]+work1d.L[332]*work1d.v[589];
  work1d.v[586] -= work1d.L[328]*work1d.v[587];
  work1d.v[585] -= work1d.L[1440]*work1d.v[984];
  work1d.v[584] -= work1d.L[326]*work1d.v[585]+work1d.L[1439]*work1d.v[984];
  work1d.v[583] -= work1d.L[323]*work1d.v[584]+work1d.L[325]*work1d.v[585];
  work1d.v[582] -= work1d.L[321]*work1d.v[583];
  work1d.v[581] -= work1d.L[1418]*work1d.v[980];
  work1d.v[580] -= work1d.L[319]*work1d.v[581]+work1d.L[1417]*work1d.v[980];
  work1d.v[579] -= work1d.L[316]*work1d.v[580]+work1d.L[318]*work1d.v[581];
  work1d.v[578] -= work1d.L[314]*work1d.v[579];
  work1d.v[577] -= work1d.L[1396]*work1d.v[976];
  work1d.v[576] -= work1d.L[312]*work1d.v[577]+work1d.L[1395]*work1d.v[976];
  work1d.v[575] -= work1d.L[309]*work1d.v[576]+work1d.L[311]*work1d.v[577];
  work1d.v[574] -= work1d.L[307]*work1d.v[575];
  work1d.v[573] -= work1d.L[1374]*work1d.v[972];
  work1d.v[572] -= work1d.L[305]*work1d.v[573]+work1d.L[1373]*work1d.v[972];
  work1d.v[571] -= work1d.L[302]*work1d.v[572]+work1d.L[304]*work1d.v[573];
  work1d.v[570] -= work1d.L[300]*work1d.v[571];
  work1d.v[569] -= work1d.L[1352]*work1d.v[968];
  work1d.v[568] -= work1d.L[298]*work1d.v[569]+work1d.L[1351]*work1d.v[968];
  work1d.v[567] -= work1d.L[295]*work1d.v[568]+work1d.L[297]*work1d.v[569];
  work1d.v[566] -= work1d.L[293]*work1d.v[567];
  work1d.v[565] -= work1d.L[1330]*work1d.v[964];
  work1d.v[564] -= work1d.L[291]*work1d.v[565]+work1d.L[1329]*work1d.v[964];
  work1d.v[563] -= work1d.L[288]*work1d.v[564]+work1d.L[290]*work1d.v[565];
  work1d.v[562] -= work1d.L[286]*work1d.v[563];
  work1d.v[561] -= work1d.L[1308]*work1d.v[960];
  work1d.v[560] -= work1d.L[284]*work1d.v[561]+work1d.L[1307]*work1d.v[960];
  work1d.v[559] -= work1d.L[281]*work1d.v[560]+work1d.L[283]*work1d.v[561];
  work1d.v[558] -= work1d.L[279]*work1d.v[559];
  work1d.v[557] -= work1d.L[1286]*work1d.v[956];
  work1d.v[556] -= work1d.L[277]*work1d.v[557]+work1d.L[1285]*work1d.v[956];
  work1d.v[555] -= work1d.L[274]*work1d.v[556]+work1d.L[276]*work1d.v[557];
  work1d.v[554] -= work1d.L[272]*work1d.v[555];
  work1d.v[553] -= work1d.L[1264]*work1d.v[952];
  work1d.v[552] -= work1d.L[270]*work1d.v[553]+work1d.L[1263]*work1d.v[952];
  work1d.v[551] -= work1d.L[267]*work1d.v[552]+work1d.L[269]*work1d.v[553];
  work1d.v[550] -= work1d.L[265]*work1d.v[551];
  work1d.v[549] -= work1d.L[1242]*work1d.v[948];
  work1d.v[548] -= work1d.L[263]*work1d.v[549]+work1d.L[1241]*work1d.v[948];
  work1d.v[547] -= work1d.L[260]*work1d.v[548]+work1d.L[262]*work1d.v[549];
  work1d.v[546] -= work1d.L[258]*work1d.v[547];
  work1d.v[545] -= work1d.L[1220]*work1d.v[944];
  work1d.v[544] -= work1d.L[256]*work1d.v[545]+work1d.L[1219]*work1d.v[944];
  work1d.v[543] -= work1d.L[253]*work1d.v[544]+work1d.L[255]*work1d.v[545];
  work1d.v[542] -= work1d.L[251]*work1d.v[543];
  work1d.v[541] -= work1d.L[1198]*work1d.v[940];
  work1d.v[540] -= work1d.L[249]*work1d.v[541]+work1d.L[1197]*work1d.v[940];
  work1d.v[539] -= work1d.L[246]*work1d.v[540]+work1d.L[248]*work1d.v[541];
  work1d.v[538] -= work1d.L[244]*work1d.v[539];
  work1d.v[537] -= work1d.L[1176]*work1d.v[936];
  work1d.v[536] -= work1d.L[242]*work1d.v[537]+work1d.L[1175]*work1d.v[936];
  work1d.v[535] -= work1d.L[239]*work1d.v[536]+work1d.L[241]*work1d.v[537];
  work1d.v[534] -= work1d.L[237]*work1d.v[535];
  work1d.v[533] -= work1d.L[1154]*work1d.v[932];
  work1d.v[532] -= work1d.L[235]*work1d.v[533]+work1d.L[1153]*work1d.v[932];
  work1d.v[531] -= work1d.L[232]*work1d.v[532]+work1d.L[234]*work1d.v[533];
  work1d.v[530] -= work1d.L[230]*work1d.v[531];
  work1d.v[529] -= work1d.L[1132]*work1d.v[928];
  work1d.v[528] -= work1d.L[228]*work1d.v[529]+work1d.L[1131]*work1d.v[928];
  work1d.v[527] -= work1d.L[225]*work1d.v[528]+work1d.L[227]*work1d.v[529];
  work1d.v[526] -= work1d.L[223]*work1d.v[527];
  work1d.v[525] -= work1d.L[1110]*work1d.v[924];
  work1d.v[524] -= work1d.L[221]*work1d.v[525]+work1d.L[1109]*work1d.v[924];
  work1d.v[523] -= work1d.L[218]*work1d.v[524]+work1d.L[220]*work1d.v[525];
  work1d.v[522] -= work1d.L[216]*work1d.v[523];
  work1d.v[521] -= work1d.L[1088]*work1d.v[920];
  work1d.v[520] -= work1d.L[214]*work1d.v[521]+work1d.L[1087]*work1d.v[920];
  work1d.v[519] -= work1d.L[211]*work1d.v[520]+work1d.L[213]*work1d.v[521];
  work1d.v[518] -= work1d.L[209]*work1d.v[519];
  work1d.v[517] -= work1d.L[1066]*work1d.v[916];
  work1d.v[516] -= work1d.L[207]*work1d.v[517]+work1d.L[1065]*work1d.v[916];
  work1d.v[515] -= work1d.L[204]*work1d.v[516]+work1d.L[206]*work1d.v[517];
  work1d.v[514] -= work1d.L[202]*work1d.v[515];
  work1d.v[513] -= work1d.L[1044]*work1d.v[912];
  work1d.v[512] -= work1d.L[200]*work1d.v[513]+work1d.L[1043]*work1d.v[912];
  work1d.v[511] -= work1d.L[197]*work1d.v[512]+work1d.L[199]*work1d.v[513];
  work1d.v[510] -= work1d.L[195]*work1d.v[511];
  work1d.v[509] -= work1d.L[1022]*work1d.v[908];
  work1d.v[508] -= work1d.L[193]*work1d.v[509]+work1d.L[1021]*work1d.v[908];
  work1d.v[507] -= work1d.L[190]*work1d.v[508]+work1d.L[192]*work1d.v[509];
  work1d.v[506] -= work1d.L[188]*work1d.v[507];
  work1d.v[505] -= work1d.L[1000]*work1d.v[904];
  work1d.v[504] -= work1d.L[186]*work1d.v[505]+work1d.L[999]*work1d.v[904];
  work1d.v[503] -= work1d.L[183]*work1d.v[504]+work1d.L[185]*work1d.v[505];
  work1d.v[502] -= work1d.L[181]*work1d.v[503];
  work1d.v[501] -= work1d.L[978]*work1d.v[900];
  work1d.v[500] -= work1d.L[179]*work1d.v[501]+work1d.L[977]*work1d.v[900];
  work1d.v[499] -= work1d.L[176]*work1d.v[500]+work1d.L[178]*work1d.v[501];
  work1d.v[498] -= work1d.L[174]*work1d.v[499];
  work1d.v[497] -= work1d.L[956]*work1d.v[896];
  work1d.v[496] -= work1d.L[172]*work1d.v[497]+work1d.L[955]*work1d.v[896];
  work1d.v[495] -= work1d.L[169]*work1d.v[496]+work1d.L[171]*work1d.v[497];
  work1d.v[494] -= work1d.L[167]*work1d.v[495];
  work1d.v[493] -= work1d.L[934]*work1d.v[892];
  work1d.v[492] -= work1d.L[165]*work1d.v[493]+work1d.L[933]*work1d.v[892];
  work1d.v[491] -= work1d.L[162]*work1d.v[492]+work1d.L[164]*work1d.v[493];
  work1d.v[490] -= work1d.L[160]*work1d.v[491];
  work1d.v[489] -= work1d.L[912]*work1d.v[888];
  work1d.v[488] -= work1d.L[158]*work1d.v[489]+work1d.L[911]*work1d.v[888];
  work1d.v[487] -= work1d.L[155]*work1d.v[488]+work1d.L[157]*work1d.v[489];
  work1d.v[486] -= work1d.L[153]*work1d.v[487];
  work1d.v[485] -= work1d.L[890]*work1d.v[884];
  work1d.v[484] -= work1d.L[151]*work1d.v[485]+work1d.L[889]*work1d.v[884];
  work1d.v[483] -= work1d.L[148]*work1d.v[484]+work1d.L[150]*work1d.v[485];
  work1d.v[482] -= work1d.L[146]*work1d.v[483];
  work1d.v[481] -= work1d.L[868]*work1d.v[880];
  work1d.v[480] -= work1d.L[144]*work1d.v[481]+work1d.L[867]*work1d.v[880];
  work1d.v[479] -= work1d.L[141]*work1d.v[480]+work1d.L[143]*work1d.v[481];
  work1d.v[478] -= work1d.L[139]*work1d.v[479];
  work1d.v[477] -= work1d.L[846]*work1d.v[876];
  work1d.v[476] -= work1d.L[137]*work1d.v[477]+work1d.L[845]*work1d.v[876];
  work1d.v[475] -= work1d.L[134]*work1d.v[476]+work1d.L[136]*work1d.v[477];
  work1d.v[474] -= work1d.L[132]*work1d.v[475];
  work1d.v[473] -= work1d.L[824]*work1d.v[872];
  work1d.v[472] -= work1d.L[130]*work1d.v[473]+work1d.L[823]*work1d.v[872];
  work1d.v[471] -= work1d.L[127]*work1d.v[472]+work1d.L[129]*work1d.v[473];
  work1d.v[470] -= work1d.L[125]*work1d.v[471];
  work1d.v[469] -= work1d.L[802]*work1d.v[868];
  work1d.v[468] -= work1d.L[123]*work1d.v[469]+work1d.L[801]*work1d.v[868];
  work1d.v[467] -= work1d.L[120]*work1d.v[468]+work1d.L[122]*work1d.v[469];
  work1d.v[466] -= work1d.L[118]*work1d.v[467];
  work1d.v[465] -= work1d.L[780]*work1d.v[864];
  work1d.v[464] -= work1d.L[116]*work1d.v[465]+work1d.L[779]*work1d.v[864];
  work1d.v[463] -= work1d.L[113]*work1d.v[464]+work1d.L[115]*work1d.v[465];
  work1d.v[462] -= work1d.L[111]*work1d.v[463];
  work1d.v[461] -= work1d.L[758]*work1d.v[860];
  work1d.v[460] -= work1d.L[109]*work1d.v[461]+work1d.L[757]*work1d.v[860];
  work1d.v[459] -= work1d.L[106]*work1d.v[460]+work1d.L[108]*work1d.v[461];
  work1d.v[458] -= work1d.L[104]*work1d.v[459];
  work1d.v[457] -= work1d.L[736]*work1d.v[856];
  work1d.v[456] -= work1d.L[102]*work1d.v[457]+work1d.L[735]*work1d.v[856];
  work1d.v[455] -= work1d.L[99]*work1d.v[456]+work1d.L[101]*work1d.v[457];
  work1d.v[454] -= work1d.L[97]*work1d.v[455];
  work1d.v[453] -= work1d.L[716]*work1d.v[852];
  work1d.v[452] -= work1d.L[95]*work1d.v[453]+work1d.L[715]*work1d.v[852];
  work1d.v[451] -= work1d.L[92]*work1d.v[452]+work1d.L[94]*work1d.v[453];
  work1d.v[450] -= work1d.L[90]*work1d.v[451];
  work1d.v[449] -= work1d.L[701]*work1d.v[811];
  work1d.v[448] -= work1d.L[88]*work1d.v[449]+work1d.L[700]*work1d.v[811];
  work1d.v[447] -= work1d.L[85]*work1d.v[448]+work1d.L[87]*work1d.v[449];
  work1d.v[446] -= work1d.L[83]*work1d.v[447];
  work1d.v[445] -= work1d.L[694]*work1d.v[809];
  work1d.v[444] -= work1d.L[654]*work1d.v[770];
  work1d.v[443] -= work1d.L[648]*work1d.v[768];
  work1d.v[442] -= work1d.L[692]*work1d.v[808];
  work1d.v[441] -= work1d.L[691]*work1d.v[807];
  work1d.v[440] -= work1d.L[690]*work1d.v[806];
  work1d.v[439] -= work1d.L[689]*work1d.v[805];
  work1d.v[438] -= work1d.L[688]*work1d.v[804];
  work1d.v[437] -= work1d.L[687]*work1d.v[803];
  work1d.v[436] -= work1d.L[686]*work1d.v[802];
  work1d.v[435] -= work1d.L[685]*work1d.v[801];
  work1d.v[434] -= work1d.L[684]*work1d.v[800];
  work1d.v[433] -= work1d.L[683]*work1d.v[799];
  work1d.v[432] -= work1d.L[682]*work1d.v[798];
  work1d.v[431] -= work1d.L[681]*work1d.v[797];
  work1d.v[430] -= work1d.L[680]*work1d.v[796];
  work1d.v[429] -= work1d.L[679]*work1d.v[795];
  work1d.v[428] -= work1d.L[678]*work1d.v[794];
  work1d.v[427] -= work1d.L[677]*work1d.v[793];
  work1d.v[426] -= work1d.L[676]*work1d.v[792];
  work1d.v[425] -= work1d.L[675]*work1d.v[791];
  work1d.v[424] -= work1d.L[674]*work1d.v[790];
  work1d.v[423] -= work1d.L[673]*work1d.v[789];
  work1d.v[422] -= work1d.L[672]*work1d.v[788];
  work1d.v[421] -= work1d.L[671]*work1d.v[787];
  work1d.v[420] -= work1d.L[670]*work1d.v[786];
  work1d.v[419] -= work1d.L[669]*work1d.v[785];
  work1d.v[418] -= work1d.L[668]*work1d.v[784];
  work1d.v[417] -= work1d.L[667]*work1d.v[783];
  work1d.v[416] -= work1d.L[666]*work1d.v[782];
  work1d.v[415] -= work1d.L[665]*work1d.v[781];
  work1d.v[414] -= work1d.L[664]*work1d.v[780];
  work1d.v[413] -= work1d.L[663]*work1d.v[779];
  work1d.v[412] -= work1d.L[662]*work1d.v[778];
  work1d.v[411] -= work1d.L[661]*work1d.v[777];
  work1d.v[410] -= work1d.L[660]*work1d.v[776];
  work1d.v[409] -= work1d.L[659]*work1d.v[775];
  work1d.v[408] -= work1d.L[658]*work1d.v[774];
  work1d.v[407] -= work1d.L[657]*work1d.v[773];
  work1d.v[406] -= work1d.L[656]*work1d.v[772];
  work1d.v[405] -= work1d.L[655]*work1d.v[771];
  work1d.v[404] -= work1d.L[704]*work1d.v[812];
  work1d.v[403] -= work1d.L[80]*work1d.v[404];
  work1d.v[402] -= work1d.L[699]*work1d.v[811];
  work1d.v[401] -= work1d.L[81]*work1d.v[444];
  work1d.v[400] -= work1d.L[645]*work1d.v[767];
  work1d.v[399] -= work1d.L[650]*work1d.v[769];
  work1d.v[398] -= work1d.L[1514]*work1d.v[999];
  work1d.v[397] -= work1d.L[1486]*work1d.v[993];
  work1d.v[396] -= work1d.L[1464]*work1d.v[989];
  work1d.v[395] -= work1d.L[1442]*work1d.v[985];
  work1d.v[394] -= work1d.L[1420]*work1d.v[981];
  work1d.v[393] -= work1d.L[1398]*work1d.v[977];
  work1d.v[392] -= work1d.L[1376]*work1d.v[973];
  work1d.v[391] -= work1d.L[1354]*work1d.v[969];
  work1d.v[390] -= work1d.L[1332]*work1d.v[965];
  work1d.v[389] -= work1d.L[1310]*work1d.v[961];
  work1d.v[388] -= work1d.L[1288]*work1d.v[957];
  work1d.v[387] -= work1d.L[1266]*work1d.v[953];
  work1d.v[386] -= work1d.L[1244]*work1d.v[949];
  work1d.v[385] -= work1d.L[1222]*work1d.v[945];
  work1d.v[384] -= work1d.L[1200]*work1d.v[941];
  work1d.v[383] -= work1d.L[1178]*work1d.v[937];
  work1d.v[382] -= work1d.L[1156]*work1d.v[933];
  work1d.v[381] -= work1d.L[1134]*work1d.v[929];
  work1d.v[380] -= work1d.L[1112]*work1d.v[925];
  work1d.v[379] -= work1d.L[1090]*work1d.v[921];
  work1d.v[378] -= work1d.L[1068]*work1d.v[917];
  work1d.v[377] -= work1d.L[1046]*work1d.v[913];
  work1d.v[376] -= work1d.L[1024]*work1d.v[909];
  work1d.v[375] -= work1d.L[1002]*work1d.v[905];
  work1d.v[374] -= work1d.L[980]*work1d.v[901];
  work1d.v[373] -= work1d.L[958]*work1d.v[897];
  work1d.v[372] -= work1d.L[936]*work1d.v[893];
  work1d.v[371] -= work1d.L[914]*work1d.v[889];
  work1d.v[370] -= work1d.L[892]*work1d.v[885];
  work1d.v[369] -= work1d.L[870]*work1d.v[881];
  work1d.v[368] -= work1d.L[848]*work1d.v[877];
  work1d.v[367] -= work1d.L[826]*work1d.v[873];
  work1d.v[366] -= work1d.L[804]*work1d.v[869];
  work1d.v[365] -= work1d.L[782]*work1d.v[865];
  work1d.v[364] -= work1d.L[760]*work1d.v[861];
  work1d.v[363] -= work1d.L[738]*work1d.v[857];
  work1d.v[362] -= work1d.L[718]*work1d.v[853];
  work1d.v[361] -= work1d.L[703]*work1d.v[812];
  work1d.v[360] -= work1d.L[362]*work1d.v[606];
  work1d.v[359] -= work1d.L[1526]*work1d.v[1000];
  work1d.v[358] -= work1d.L[1508]*work1d.v[998];
  work1d.v[357] -= work1d.L[1482]*work1d.v[992];
  work1d.v[356] -= work1d.L[1460]*work1d.v[988];
  work1d.v[355] -= work1d.L[1438]*work1d.v[984];
  work1d.v[354] -= work1d.L[1416]*work1d.v[980];
  work1d.v[353] -= work1d.L[1394]*work1d.v[976];
  work1d.v[352] -= work1d.L[1372]*work1d.v[972];
  work1d.v[351] -= work1d.L[1350]*work1d.v[968];
  work1d.v[350] -= work1d.L[1328]*work1d.v[964];
  work1d.v[349] -= work1d.L[1306]*work1d.v[960];
  work1d.v[348] -= work1d.L[1284]*work1d.v[956];
  work1d.v[347] -= work1d.L[1262]*work1d.v[952];
  work1d.v[346] -= work1d.L[1240]*work1d.v[948];
  work1d.v[345] -= work1d.L[1218]*work1d.v[944];
  work1d.v[344] -= work1d.L[1196]*work1d.v[940];
  work1d.v[343] -= work1d.L[1174]*work1d.v[936];
  work1d.v[342] -= work1d.L[1152]*work1d.v[932];
  work1d.v[341] -= work1d.L[1130]*work1d.v[928];
  work1d.v[340] -= work1d.L[1108]*work1d.v[924];
  work1d.v[339] -= work1d.L[1086]*work1d.v[920];
  work1d.v[338] -= work1d.L[1064]*work1d.v[916];
  work1d.v[337] -= work1d.L[1042]*work1d.v[912];
  work1d.v[336] -= work1d.L[1020]*work1d.v[908];
  work1d.v[335] -= work1d.L[998]*work1d.v[904];
  work1d.v[334] -= work1d.L[976]*work1d.v[900];
  work1d.v[333] -= work1d.L[954]*work1d.v[896];
  work1d.v[332] -= work1d.L[932]*work1d.v[892];
  work1d.v[331] -= work1d.L[910]*work1d.v[888];
  work1d.v[330] -= work1d.L[888]*work1d.v[884];
  work1d.v[329] -= work1d.L[866]*work1d.v[880];
  work1d.v[328] -= work1d.L[844]*work1d.v[876];
  work1d.v[327] -= work1d.L[822]*work1d.v[872];
  work1d.v[326] -= work1d.L[800]*work1d.v[868];
  work1d.v[325] -= work1d.L[778]*work1d.v[864];
  work1d.v[324] -= work1d.L[756]*work1d.v[860];
  work1d.v[323] -= work1d.L[734]*work1d.v[856];
  work1d.v[322] -= work1d.L[714]*work1d.v[852];
  work1d.v[321] -= work1d.L[698]*work1d.v[811];
  work1d.v[320] -= work1d.L[79]*work1d.v[400];
  work1d.v[319] -= work1d.L[78]*work1d.v[399];
  work1d.v[318] -= work1d.L[77]*work1d.v[398];
  work1d.v[317] -= work1d.L[76]*work1d.v[397];
  work1d.v[316] -= work1d.L[75]*work1d.v[396];
  work1d.v[315] -= work1d.L[74]*work1d.v[395];
  work1d.v[314] -= work1d.L[73]*work1d.v[394];
  work1d.v[313] -= work1d.L[72]*work1d.v[393];
  work1d.v[312] -= work1d.L[71]*work1d.v[392];
  work1d.v[311] -= work1d.L[70]*work1d.v[391];
  work1d.v[310] -= work1d.L[69]*work1d.v[390];
  work1d.v[309] -= work1d.L[68]*work1d.v[389];
  work1d.v[308] -= work1d.L[67]*work1d.v[388];
  work1d.v[307] -= work1d.L[66]*work1d.v[387];
  work1d.v[306] -= work1d.L[65]*work1d.v[386];
  work1d.v[305] -= work1d.L[64]*work1d.v[385];
  work1d.v[304] -= work1d.L[63]*work1d.v[384];
  work1d.v[303] -= work1d.L[62]*work1d.v[383];
  work1d.v[302] -= work1d.L[61]*work1d.v[382];
  work1d.v[301] -= work1d.L[60]*work1d.v[381];
  work1d.v[300] -= work1d.L[59]*work1d.v[380];
  work1d.v[299] -= work1d.L[58]*work1d.v[379];
  work1d.v[298] -= work1d.L[57]*work1d.v[378];
  work1d.v[297] -= work1d.L[56]*work1d.v[377];
  work1d.v[296] -= work1d.L[55]*work1d.v[376];
  work1d.v[295] -= work1d.L[54]*work1d.v[375];
  work1d.v[294] -= work1d.L[53]*work1d.v[374];
  work1d.v[293] -= work1d.L[52]*work1d.v[373];
  work1d.v[292] -= work1d.L[51]*work1d.v[372];
  work1d.v[291] -= work1d.L[50]*work1d.v[371];
  work1d.v[290] -= work1d.L[49]*work1d.v[370];
  work1d.v[289] -= work1d.L[48]*work1d.v[369];
  work1d.v[288] -= work1d.L[47]*work1d.v[368];
  work1d.v[287] -= work1d.L[46]*work1d.v[367];
  work1d.v[286] -= work1d.L[45]*work1d.v[366];
  work1d.v[285] -= work1d.L[44]*work1d.v[365];
  work1d.v[284] -= work1d.L[43]*work1d.v[364];
  work1d.v[283] -= work1d.L[42]*work1d.v[363];
  work1d.v[282] -= work1d.L[41]*work1d.v[362];
  work1d.v[281] -= work1d.L[40]*work1d.v[361];
  work1d.v[280] -= work1d.L[39]*work1d.v[360];
  work1d.v[279] -= work1d.L[38]*work1d.v[359];
  work1d.v[278] -= work1d.L[37]*work1d.v[358];
  work1d.v[277] -= work1d.L[36]*work1d.v[357];
  work1d.v[276] -= work1d.L[35]*work1d.v[356];
  work1d.v[275] -= work1d.L[34]*work1d.v[355];
  work1d.v[274] -= work1d.L[33]*work1d.v[354];
  work1d.v[273] -= work1d.L[32]*work1d.v[353];
  work1d.v[272] -= work1d.L[31]*work1d.v[352];
  work1d.v[271] -= work1d.L[30]*work1d.v[351];
  work1d.v[270] -= work1d.L[29]*work1d.v[350];
  work1d.v[269] -= work1d.L[28]*work1d.v[349];
  work1d.v[268] -= work1d.L[27]*work1d.v[348];
  work1d.v[267] -= work1d.L[26]*work1d.v[347];
  work1d.v[266] -= work1d.L[25]*work1d.v[346];
  work1d.v[265] -= work1d.L[24]*work1d.v[345];
  work1d.v[264] -= work1d.L[23]*work1d.v[344];
  work1d.v[263] -= work1d.L[22]*work1d.v[343];
  work1d.v[262] -= work1d.L[21]*work1d.v[342];
  work1d.v[261] -= work1d.L[20]*work1d.v[341];
  work1d.v[260] -= work1d.L[19]*work1d.v[340];
  work1d.v[259] -= work1d.L[18]*work1d.v[339];
  work1d.v[258] -= work1d.L[17]*work1d.v[338];
  work1d.v[257] -= work1d.L[16]*work1d.v[337];
  work1d.v[256] -= work1d.L[15]*work1d.v[336];
  work1d.v[255] -= work1d.L[14]*work1d.v[335];
  work1d.v[254] -= work1d.L[13]*work1d.v[334];
  work1d.v[253] -= work1d.L[12]*work1d.v[333];
  work1d.v[252] -= work1d.L[11]*work1d.v[332];
  work1d.v[251] -= work1d.L[10]*work1d.v[331];
  work1d.v[250] -= work1d.L[9]*work1d.v[330];
  work1d.v[249] -= work1d.L[8]*work1d.v[329];
  work1d.v[248] -= work1d.L[7]*work1d.v[328];
  work1d.v[247] -= work1d.L[6]*work1d.v[327];
  work1d.v[246] -= work1d.L[5]*work1d.v[326];
  work1d.v[245] -= work1d.L[4]*work1d.v[325];
  work1d.v[244] -= work1d.L[3]*work1d.v[324];
  work1d.v[243] -= work1d.L[2]*work1d.v[323];
  work1d.v[242] -= work1d.L[1]*work1d.v[322];
  work1d.v[241] -= work1d.L[0]*work1d.v[321];
  work1d.v[240] -= work1d.L[642]*work1d.v[766];
  work1d.v[239] -= work1d.L[640]*work1d.v[765];
  work1d.v[238] -= work1d.L[638]*work1d.v[763];
  work1d.v[237] -= work1d.L[635]*work1d.v[762];
  work1d.v[236] -= work1d.L[633]*work1d.v[761];
  work1d.v[235] -= work1d.L[631]*work1d.v[759];
  work1d.v[234] -= work1d.L[628]*work1d.v[758];
  work1d.v[233] -= work1d.L[626]*work1d.v[757];
  work1d.v[232] -= work1d.L[624]*work1d.v[755];
  work1d.v[231] -= work1d.L[621]*work1d.v[754];
  work1d.v[230] -= work1d.L[619]*work1d.v[753];
  work1d.v[229] -= work1d.L[617]*work1d.v[751];
  work1d.v[228] -= work1d.L[614]*work1d.v[750];
  work1d.v[227] -= work1d.L[612]*work1d.v[749];
  work1d.v[226] -= work1d.L[610]*work1d.v[747];
  work1d.v[225] -= work1d.L[607]*work1d.v[746];
  work1d.v[224] -= work1d.L[605]*work1d.v[745];
  work1d.v[223] -= work1d.L[603]*work1d.v[743];
  work1d.v[222] -= work1d.L[600]*work1d.v[742];
  work1d.v[221] -= work1d.L[598]*work1d.v[741];
  work1d.v[220] -= work1d.L[596]*work1d.v[739];
  work1d.v[219] -= work1d.L[593]*work1d.v[738];
  work1d.v[218] -= work1d.L[591]*work1d.v[737];
  work1d.v[217] -= work1d.L[589]*work1d.v[735];
  work1d.v[216] -= work1d.L[586]*work1d.v[734];
  work1d.v[215] -= work1d.L[584]*work1d.v[733];
  work1d.v[214] -= work1d.L[582]*work1d.v[731];
  work1d.v[213] -= work1d.L[579]*work1d.v[730];
  work1d.v[212] -= work1d.L[577]*work1d.v[729];
  work1d.v[211] -= work1d.L[575]*work1d.v[727];
  work1d.v[210] -= work1d.L[572]*work1d.v[726];
  work1d.v[209] -= work1d.L[570]*work1d.v[725];
  work1d.v[208] -= work1d.L[568]*work1d.v[723];
  work1d.v[207] -= work1d.L[565]*work1d.v[722];
  work1d.v[206] -= work1d.L[563]*work1d.v[721];
  work1d.v[205] -= work1d.L[561]*work1d.v[719];
  work1d.v[204] -= work1d.L[558]*work1d.v[718];
  work1d.v[203] -= work1d.L[556]*work1d.v[717];
  work1d.v[202] -= work1d.L[554]*work1d.v[715];
  work1d.v[201] -= work1d.L[551]*work1d.v[714];
  work1d.v[200] -= work1d.L[549]*work1d.v[713];
  work1d.v[199] -= work1d.L[547]*work1d.v[711];
  work1d.v[198] -= work1d.L[544]*work1d.v[710];
  work1d.v[197] -= work1d.L[542]*work1d.v[709];
  work1d.v[196] -= work1d.L[540]*work1d.v[707];
  work1d.v[195] -= work1d.L[537]*work1d.v[706];
  work1d.v[194] -= work1d.L[535]*work1d.v[705];
  work1d.v[193] -= work1d.L[533]*work1d.v[703];
  work1d.v[192] -= work1d.L[530]*work1d.v[702];
  work1d.v[191] -= work1d.L[528]*work1d.v[701];
  work1d.v[190] -= work1d.L[526]*work1d.v[699];
  work1d.v[189] -= work1d.L[523]*work1d.v[698];
  work1d.v[188] -= work1d.L[521]*work1d.v[697];
  work1d.v[187] -= work1d.L[519]*work1d.v[695];
  work1d.v[186] -= work1d.L[516]*work1d.v[694];
  work1d.v[185] -= work1d.L[514]*work1d.v[693];
  work1d.v[184] -= work1d.L[512]*work1d.v[691];
  work1d.v[183] -= work1d.L[509]*work1d.v[690];
  work1d.v[182] -= work1d.L[507]*work1d.v[689];
  work1d.v[181] -= work1d.L[505]*work1d.v[687];
  work1d.v[180] -= work1d.L[502]*work1d.v[686];
  work1d.v[179] -= work1d.L[500]*work1d.v[685];
  work1d.v[178] -= work1d.L[498]*work1d.v[683];
  work1d.v[177] -= work1d.L[495]*work1d.v[682];
  work1d.v[176] -= work1d.L[493]*work1d.v[681];
  work1d.v[175] -= work1d.L[491]*work1d.v[679];
  work1d.v[174] -= work1d.L[488]*work1d.v[678];
  work1d.v[173] -= work1d.L[486]*work1d.v[677];
  work1d.v[172] -= work1d.L[484]*work1d.v[675];
  work1d.v[171] -= work1d.L[481]*work1d.v[674];
  work1d.v[170] -= work1d.L[479]*work1d.v[673];
  work1d.v[169] -= work1d.L[477]*work1d.v[671];
  work1d.v[168] -= work1d.L[474]*work1d.v[670];
  work1d.v[167] -= work1d.L[472]*work1d.v[669];
  work1d.v[166] -= work1d.L[470]*work1d.v[667];
  work1d.v[165] -= work1d.L[467]*work1d.v[666];
  work1d.v[164] -= work1d.L[465]*work1d.v[665];
  work1d.v[163] -= work1d.L[463]*work1d.v[663];
  work1d.v[162] -= work1d.L[460]*work1d.v[662];
  work1d.v[161] -= work1d.L[458]*work1d.v[661];
  work1d.v[160] -= work1d.L[456]*work1d.v[659];
  work1d.v[159] -= work1d.L[453]*work1d.v[658];
  work1d.v[158] -= work1d.L[451]*work1d.v[657];
  work1d.v[157] -= work1d.L[449]*work1d.v[655];
  work1d.v[156] -= work1d.L[446]*work1d.v[654];
  work1d.v[155] -= work1d.L[444]*work1d.v[653];
  work1d.v[154] -= work1d.L[442]*work1d.v[651];
  work1d.v[153] -= work1d.L[439]*work1d.v[650];
  work1d.v[152] -= work1d.L[437]*work1d.v[649];
  work1d.v[151] -= work1d.L[435]*work1d.v[647];
  work1d.v[150] -= work1d.L[432]*work1d.v[646];
  work1d.v[149] -= work1d.L[430]*work1d.v[645];
  work1d.v[148] -= work1d.L[428]*work1d.v[643];
  work1d.v[147] -= work1d.L[425]*work1d.v[642];
  work1d.v[146] -= work1d.L[423]*work1d.v[641];
  work1d.v[145] -= work1d.L[421]*work1d.v[639];
  work1d.v[144] -= work1d.L[418]*work1d.v[638];
  work1d.v[143] -= work1d.L[416]*work1d.v[637];
  work1d.v[142] -= work1d.L[414]*work1d.v[635];
  work1d.v[141] -= work1d.L[411]*work1d.v[634];
  work1d.v[140] -= work1d.L[409]*work1d.v[633];
  work1d.v[139] -= work1d.L[407]*work1d.v[631];
  work1d.v[138] -= work1d.L[404]*work1d.v[630];
  work1d.v[137] -= work1d.L[402]*work1d.v[629];
  work1d.v[136] -= work1d.L[400]*work1d.v[627];
  work1d.v[135] -= work1d.L[397]*work1d.v[626];
  work1d.v[134] -= work1d.L[395]*work1d.v[625];
  work1d.v[133] -= work1d.L[393]*work1d.v[623];
  work1d.v[132] -= work1d.L[390]*work1d.v[622];
  work1d.v[131] -= work1d.L[388]*work1d.v[621];
  work1d.v[130] -= work1d.L[386]*work1d.v[619];
  work1d.v[129] -= work1d.L[383]*work1d.v[618];
  work1d.v[128] -= work1d.L[381]*work1d.v[617];
  work1d.v[127] -= work1d.L[379]*work1d.v[615];
  work1d.v[126] -= work1d.L[376]*work1d.v[614];
  work1d.v[125] -= work1d.L[374]*work1d.v[613];
  work1d.v[124] -= work1d.L[372]*work1d.v[611];
  work1d.v[123] -= work1d.L[369]*work1d.v[610];
  work1d.v[122] -= work1d.L[367]*work1d.v[609];
  work1d.v[121] -= work1d.L[365]*work1d.v[607];
  work1d.v[120] -= work1d.L[359]*work1d.v[605];
  work1d.v[119] -= work1d.L[357]*work1d.v[604];
  work1d.v[118] -= work1d.L[355]*work1d.v[602];
  work1d.v[117] -= work1d.L[352]*work1d.v[601];
  work1d.v[116] -= work1d.L[350]*work1d.v[600];
  work1d.v[115] -= work1d.L[348]*work1d.v[598];
  work1d.v[114] -= work1d.L[345]*work1d.v[597];
  work1d.v[113] -= work1d.L[343]*work1d.v[596];
  work1d.v[112] -= work1d.L[341]*work1d.v[594];
  work1d.v[111] -= work1d.L[338]*work1d.v[593];
  work1d.v[110] -= work1d.L[336]*work1d.v[592];
  work1d.v[109] -= work1d.L[334]*work1d.v[590];
  work1d.v[108] -= work1d.L[331]*work1d.v[589];
  work1d.v[107] -= work1d.L[329]*work1d.v[588];
  work1d.v[106] -= work1d.L[327]*work1d.v[586];
  work1d.v[105] -= work1d.L[324]*work1d.v[585];
  work1d.v[104] -= work1d.L[322]*work1d.v[584];
  work1d.v[103] -= work1d.L[320]*work1d.v[582];
  work1d.v[102] -= work1d.L[317]*work1d.v[581];
  work1d.v[101] -= work1d.L[315]*work1d.v[580];
  work1d.v[100] -= work1d.L[313]*work1d.v[578];
  work1d.v[99] -= work1d.L[310]*work1d.v[577];
  work1d.v[98] -= work1d.L[308]*work1d.v[576];
  work1d.v[97] -= work1d.L[306]*work1d.v[574];
  work1d.v[96] -= work1d.L[303]*work1d.v[573];
  work1d.v[95] -= work1d.L[301]*work1d.v[572];
  work1d.v[94] -= work1d.L[299]*work1d.v[570];
  work1d.v[93] -= work1d.L[296]*work1d.v[569];
  work1d.v[92] -= work1d.L[294]*work1d.v[568];
  work1d.v[91] -= work1d.L[292]*work1d.v[566];
  work1d.v[90] -= work1d.L[289]*work1d.v[565];
  work1d.v[89] -= work1d.L[287]*work1d.v[564];
  work1d.v[88] -= work1d.L[285]*work1d.v[562];
  work1d.v[87] -= work1d.L[282]*work1d.v[561];
  work1d.v[86] -= work1d.L[280]*work1d.v[560];
  work1d.v[85] -= work1d.L[278]*work1d.v[558];
  work1d.v[84] -= work1d.L[275]*work1d.v[557];
  work1d.v[83] -= work1d.L[273]*work1d.v[556];
  work1d.v[82] -= work1d.L[271]*work1d.v[554];
  work1d.v[81] -= work1d.L[268]*work1d.v[553];
  work1d.v[80] -= work1d.L[266]*work1d.v[552];
  work1d.v[79] -= work1d.L[264]*work1d.v[550];
  work1d.v[78] -= work1d.L[261]*work1d.v[549];
  work1d.v[77] -= work1d.L[259]*work1d.v[548];
  work1d.v[76] -= work1d.L[257]*work1d.v[546];
  work1d.v[75] -= work1d.L[254]*work1d.v[545];
  work1d.v[74] -= work1d.L[252]*work1d.v[544];
  work1d.v[73] -= work1d.L[250]*work1d.v[542];
  work1d.v[72] -= work1d.L[247]*work1d.v[541];
  work1d.v[71] -= work1d.L[245]*work1d.v[540];
  work1d.v[70] -= work1d.L[243]*work1d.v[538];
  work1d.v[69] -= work1d.L[240]*work1d.v[537];
  work1d.v[68] -= work1d.L[238]*work1d.v[536];
  work1d.v[67] -= work1d.L[236]*work1d.v[534];
  work1d.v[66] -= work1d.L[233]*work1d.v[533];
  work1d.v[65] -= work1d.L[231]*work1d.v[532];
  work1d.v[64] -= work1d.L[229]*work1d.v[530];
  work1d.v[63] -= work1d.L[226]*work1d.v[529];
  work1d.v[62] -= work1d.L[224]*work1d.v[528];
  work1d.v[61] -= work1d.L[222]*work1d.v[526];
  work1d.v[60] -= work1d.L[219]*work1d.v[525];
  work1d.v[59] -= work1d.L[217]*work1d.v[524];
  work1d.v[58] -= work1d.L[215]*work1d.v[522];
  work1d.v[57] -= work1d.L[212]*work1d.v[521];
  work1d.v[56] -= work1d.L[210]*work1d.v[520];
  work1d.v[55] -= work1d.L[208]*work1d.v[518];
  work1d.v[54] -= work1d.L[205]*work1d.v[517];
  work1d.v[53] -= work1d.L[203]*work1d.v[516];
  work1d.v[52] -= work1d.L[201]*work1d.v[514];
  work1d.v[51] -= work1d.L[198]*work1d.v[513];
  work1d.v[50] -= work1d.L[196]*work1d.v[512];
  work1d.v[49] -= work1d.L[194]*work1d.v[510];
  work1d.v[48] -= work1d.L[191]*work1d.v[509];
  work1d.v[47] -= work1d.L[189]*work1d.v[508];
  work1d.v[46] -= work1d.L[187]*work1d.v[506];
  work1d.v[45] -= work1d.L[184]*work1d.v[505];
  work1d.v[44] -= work1d.L[182]*work1d.v[504];
  work1d.v[43] -= work1d.L[180]*work1d.v[502];
  work1d.v[42] -= work1d.L[177]*work1d.v[501];
  work1d.v[41] -= work1d.L[175]*work1d.v[500];
  work1d.v[40] -= work1d.L[173]*work1d.v[498];
  work1d.v[39] -= work1d.L[170]*work1d.v[497];
  work1d.v[38] -= work1d.L[168]*work1d.v[496];
  work1d.v[37] -= work1d.L[166]*work1d.v[494];
  work1d.v[36] -= work1d.L[163]*work1d.v[493];
  work1d.v[35] -= work1d.L[161]*work1d.v[492];
  work1d.v[34] -= work1d.L[159]*work1d.v[490];
  work1d.v[33] -= work1d.L[156]*work1d.v[489];
  work1d.v[32] -= work1d.L[154]*work1d.v[488];
  work1d.v[31] -= work1d.L[152]*work1d.v[486];
  work1d.v[30] -= work1d.L[149]*work1d.v[485];
  work1d.v[29] -= work1d.L[147]*work1d.v[484];
  work1d.v[28] -= work1d.L[145]*work1d.v[482];
  work1d.v[27] -= work1d.L[142]*work1d.v[481];
  work1d.v[26] -= work1d.L[140]*work1d.v[480];
  work1d.v[25] -= work1d.L[138]*work1d.v[478];
  work1d.v[24] -= work1d.L[135]*work1d.v[477];
  work1d.v[23] -= work1d.L[133]*work1d.v[476];
  work1d.v[22] -= work1d.L[131]*work1d.v[474];
  work1d.v[21] -= work1d.L[128]*work1d.v[473];
  work1d.v[20] -= work1d.L[126]*work1d.v[472];
  work1d.v[19] -= work1d.L[124]*work1d.v[470];
  work1d.v[18] -= work1d.L[121]*work1d.v[469];
  work1d.v[17] -= work1d.L[119]*work1d.v[468];
  work1d.v[16] -= work1d.L[117]*work1d.v[466];
  work1d.v[15] -= work1d.L[114]*work1d.v[465];
  work1d.v[14] -= work1d.L[112]*work1d.v[464];
  work1d.v[13] -= work1d.L[110]*work1d.v[462];
  work1d.v[12] -= work1d.L[107]*work1d.v[461];
  work1d.v[11] -= work1d.L[105]*work1d.v[460];
  work1d.v[10] -= work1d.L[103]*work1d.v[458];
  work1d.v[9] -= work1d.L[100]*work1d.v[457];
  work1d.v[8] -= work1d.L[98]*work1d.v[456];
  work1d.v[7] -= work1d.L[96]*work1d.v[454];
  work1d.v[6] -= work1d.L[93]*work1d.v[453];
  work1d.v[5] -= work1d.L[91]*work1d.v[452];
  work1d.v[4] -= work1d.L[89]*work1d.v[450];
  work1d.v[3] -= work1d.L[86]*work1d.v[449];
  work1d.v[2] -= work1d.L[84]*work1d.v[448];
  work1d.v[1] -= work1d.L[82]*work1d.v[446];
  /* Unpermute the result, from v to var. */
  var[0] = work1d.v[447];
  var[1] = work1d.v[451];
  var[2] = work1d.v[455];
  var[3] = work1d.v[459];
  var[4] = work1d.v[463];
  var[5] = work1d.v[467];
  var[6] = work1d.v[471];
  var[7] = work1d.v[475];
  var[8] = work1d.v[479];
  var[9] = work1d.v[483];
  var[10] = work1d.v[487];
  var[11] = work1d.v[491];
  var[12] = work1d.v[495];
  var[13] = work1d.v[499];
  var[14] = work1d.v[503];
  var[15] = work1d.v[507];
  var[16] = work1d.v[511];
  var[17] = work1d.v[515];
  var[18] = work1d.v[519];
  var[19] = work1d.v[523];
  var[20] = work1d.v[527];
  var[21] = work1d.v[531];
  var[22] = work1d.v[535];
  var[23] = work1d.v[539];
  var[24] = work1d.v[543];
  var[25] = work1d.v[547];
  var[26] = work1d.v[551];
  var[27] = work1d.v[555];
  var[28] = work1d.v[559];
  var[29] = work1d.v[563];
  var[30] = work1d.v[567];
  var[31] = work1d.v[571];
  var[32] = work1d.v[575];
  var[33] = work1d.v[579];
  var[34] = work1d.v[583];
  var[35] = work1d.v[587];
  var[36] = work1d.v[591];
  var[37] = work1d.v[595];
  var[38] = work1d.v[599];
  var[39] = work1d.v[603];
  var[40] = work1d.v[608];
  var[41] = work1d.v[612];
  var[42] = work1d.v[616];
  var[43] = work1d.v[620];
  var[44] = work1d.v[624];
  var[45] = work1d.v[628];
  var[46] = work1d.v[632];
  var[47] = work1d.v[636];
  var[48] = work1d.v[640];
  var[49] = work1d.v[644];
  var[50] = work1d.v[648];
  var[51] = work1d.v[652];
  var[52] = work1d.v[656];
  var[53] = work1d.v[660];
  var[54] = work1d.v[664];
  var[55] = work1d.v[668];
  var[56] = work1d.v[672];
  var[57] = work1d.v[676];
  var[58] = work1d.v[680];
  var[59] = work1d.v[684];
  var[60] = work1d.v[688];
  var[61] = work1d.v[692];
  var[62] = work1d.v[696];
  var[63] = work1d.v[700];
  var[64] = work1d.v[704];
  var[65] = work1d.v[708];
  var[66] = work1d.v[712];
  var[67] = work1d.v[716];
  var[68] = work1d.v[720];
  var[69] = work1d.v[724];
  var[70] = work1d.v[728];
  var[71] = work1d.v[732];
  var[72] = work1d.v[736];
  var[73] = work1d.v[740];
  var[74] = work1d.v[744];
  var[75] = work1d.v[748];
  var[76] = work1d.v[752];
  var[77] = work1d.v[756];
  var[78] = work1d.v[760];
  var[79] = work1d.v[764];
  var[80] = work1d.v[403];
  var[81] = work1d.v[405];
  var[82] = work1d.v[406];
  var[83] = work1d.v[407];
  var[84] = work1d.v[408];
  var[85] = work1d.v[409];
  var[86] = work1d.v[410];
  var[87] = work1d.v[411];
  var[88] = work1d.v[412];
  var[89] = work1d.v[413];
  var[90] = work1d.v[414];
  var[91] = work1d.v[415];
  var[92] = work1d.v[416];
  var[93] = work1d.v[417];
  var[94] = work1d.v[418];
  var[95] = work1d.v[419];
  var[96] = work1d.v[420];
  var[97] = work1d.v[421];
  var[98] = work1d.v[422];
  var[99] = work1d.v[423];
  var[100] = work1d.v[424];
  var[101] = work1d.v[425];
  var[102] = work1d.v[426];
  var[103] = work1d.v[427];
  var[104] = work1d.v[428];
  var[105] = work1d.v[429];
  var[106] = work1d.v[430];
  var[107] = work1d.v[431];
  var[108] = work1d.v[432];
  var[109] = work1d.v[433];
  var[110] = work1d.v[434];
  var[111] = work1d.v[435];
  var[112] = work1d.v[436];
  var[113] = work1d.v[437];
  var[114] = work1d.v[438];
  var[115] = work1d.v[439];
  var[116] = work1d.v[440];
  var[117] = work1d.v[441];
  var[118] = work1d.v[442];
  var[119] = work1d.v[443];
  var[120] = work1d.v[0];
  var[121] = work1d.v[444];
  var[122] = work1d.v[811];
  var[123] = work1d.v[812];
  var[124] = work1d.v[813];
  var[125] = work1d.v[852];
  var[126] = work1d.v[853];
  var[127] = work1d.v[814];
  var[128] = work1d.v[856];
  var[129] = work1d.v[857];
  var[130] = work1d.v[815];
  var[131] = work1d.v[860];
  var[132] = work1d.v[861];
  var[133] = work1d.v[816];
  var[134] = work1d.v[864];
  var[135] = work1d.v[865];
  var[136] = work1d.v[817];
  var[137] = work1d.v[868];
  var[138] = work1d.v[869];
  var[139] = work1d.v[818];
  var[140] = work1d.v[872];
  var[141] = work1d.v[873];
  var[142] = work1d.v[819];
  var[143] = work1d.v[876];
  var[144] = work1d.v[877];
  var[145] = work1d.v[820];
  var[146] = work1d.v[880];
  var[147] = work1d.v[881];
  var[148] = work1d.v[821];
  var[149] = work1d.v[884];
  var[150] = work1d.v[885];
  var[151] = work1d.v[822];
  var[152] = work1d.v[888];
  var[153] = work1d.v[889];
  var[154] = work1d.v[823];
  var[155] = work1d.v[892];
  var[156] = work1d.v[893];
  var[157] = work1d.v[824];
  var[158] = work1d.v[896];
  var[159] = work1d.v[897];
  var[160] = work1d.v[825];
  var[161] = work1d.v[900];
  var[162] = work1d.v[901];
  var[163] = work1d.v[826];
  var[164] = work1d.v[904];
  var[165] = work1d.v[905];
  var[166] = work1d.v[827];
  var[167] = work1d.v[908];
  var[168] = work1d.v[909];
  var[169] = work1d.v[828];
  var[170] = work1d.v[912];
  var[171] = work1d.v[913];
  var[172] = work1d.v[829];
  var[173] = work1d.v[916];
  var[174] = work1d.v[917];
  var[175] = work1d.v[830];
  var[176] = work1d.v[920];
  var[177] = work1d.v[921];
  var[178] = work1d.v[831];
  var[179] = work1d.v[924];
  var[180] = work1d.v[925];
  var[181] = work1d.v[832];
  var[182] = work1d.v[928];
  var[183] = work1d.v[929];
  var[184] = work1d.v[833];
  var[185] = work1d.v[932];
  var[186] = work1d.v[933];
  var[187] = work1d.v[834];
  var[188] = work1d.v[936];
  var[189] = work1d.v[937];
  var[190] = work1d.v[835];
  var[191] = work1d.v[940];
  var[192] = work1d.v[941];
  var[193] = work1d.v[836];
  var[194] = work1d.v[944];
  var[195] = work1d.v[945];
  var[196] = work1d.v[837];
  var[197] = work1d.v[948];
  var[198] = work1d.v[949];
  var[199] = work1d.v[838];
  var[200] = work1d.v[952];
  var[201] = work1d.v[953];
  var[202] = work1d.v[839];
  var[203] = work1d.v[956];
  var[204] = work1d.v[957];
  var[205] = work1d.v[840];
  var[206] = work1d.v[960];
  var[207] = work1d.v[961];
  var[208] = work1d.v[841];
  var[209] = work1d.v[964];
  var[210] = work1d.v[965];
  var[211] = work1d.v[842];
  var[212] = work1d.v[968];
  var[213] = work1d.v[969];
  var[214] = work1d.v[843];
  var[215] = work1d.v[972];
  var[216] = work1d.v[973];
  var[217] = work1d.v[844];
  var[218] = work1d.v[976];
  var[219] = work1d.v[977];
  var[220] = work1d.v[845];
  var[221] = work1d.v[980];
  var[222] = work1d.v[981];
  var[223] = work1d.v[846];
  var[224] = work1d.v[984];
  var[225] = work1d.v[985];
  var[226] = work1d.v[847];
  var[227] = work1d.v[988];
  var[228] = work1d.v[989];
  var[229] = work1d.v[848];
  var[230] = work1d.v[992];
  var[231] = work1d.v[993];
  var[232] = work1d.v[849];
  var[233] = work1d.v[998];
  var[234] = work1d.v[999];
  var[235] = work1d.v[850];
  var[236] = work1d.v[1000];
  var[237] = work1d.v[769];
  var[238] = work1d.v[445];
  var[239] = work1d.v[606];
  var[240] = work1d.v[767];
  var[241] = work1d.v[1];
  var[242] = work1d.v[2];
  var[243] = work1d.v[3];
  var[244] = work1d.v[4];
  var[245] = work1d.v[5];
  var[246] = work1d.v[6];
  var[247] = work1d.v[7];
  var[248] = work1d.v[8];
  var[249] = work1d.v[9];
  var[250] = work1d.v[10];
  var[251] = work1d.v[11];
  var[252] = work1d.v[12];
  var[253] = work1d.v[13];
  var[254] = work1d.v[14];
  var[255] = work1d.v[15];
  var[256] = work1d.v[16];
  var[257] = work1d.v[17];
  var[258] = work1d.v[18];
  var[259] = work1d.v[19];
  var[260] = work1d.v[20];
  var[261] = work1d.v[21];
  var[262] = work1d.v[22];
  var[263] = work1d.v[23];
  var[264] = work1d.v[24];
  var[265] = work1d.v[25];
  var[266] = work1d.v[26];
  var[267] = work1d.v[27];
  var[268] = work1d.v[28];
  var[269] = work1d.v[29];
  var[270] = work1d.v[30];
  var[271] = work1d.v[31];
  var[272] = work1d.v[32];
  var[273] = work1d.v[33];
  var[274] = work1d.v[34];
  var[275] = work1d.v[35];
  var[276] = work1d.v[36];
  var[277] = work1d.v[37];
  var[278] = work1d.v[38];
  var[279] = work1d.v[39];
  var[280] = work1d.v[40];
  var[281] = work1d.v[41];
  var[282] = work1d.v[42];
  var[283] = work1d.v[43];
  var[284] = work1d.v[44];
  var[285] = work1d.v[45];
  var[286] = work1d.v[46];
  var[287] = work1d.v[47];
  var[288] = work1d.v[48];
  var[289] = work1d.v[49];
  var[290] = work1d.v[50];
  var[291] = work1d.v[51];
  var[292] = work1d.v[52];
  var[293] = work1d.v[53];
  var[294] = work1d.v[54];
  var[295] = work1d.v[55];
  var[296] = work1d.v[56];
  var[297] = work1d.v[57];
  var[298] = work1d.v[58];
  var[299] = work1d.v[59];
  var[300] = work1d.v[60];
  var[301] = work1d.v[61];
  var[302] = work1d.v[62];
  var[303] = work1d.v[63];
  var[304] = work1d.v[64];
  var[305] = work1d.v[65];
  var[306] = work1d.v[66];
  var[307] = work1d.v[67];
  var[308] = work1d.v[68];
  var[309] = work1d.v[69];
  var[310] = work1d.v[70];
  var[311] = work1d.v[71];
  var[312] = work1d.v[72];
  var[313] = work1d.v[73];
  var[314] = work1d.v[74];
  var[315] = work1d.v[75];
  var[316] = work1d.v[76];
  var[317] = work1d.v[77];
  var[318] = work1d.v[78];
  var[319] = work1d.v[79];
  var[320] = work1d.v[80];
  var[321] = work1d.v[81];
  var[322] = work1d.v[82];
  var[323] = work1d.v[83];
  var[324] = work1d.v[84];
  var[325] = work1d.v[85];
  var[326] = work1d.v[86];
  var[327] = work1d.v[87];
  var[328] = work1d.v[88];
  var[329] = work1d.v[89];
  var[330] = work1d.v[90];
  var[331] = work1d.v[91];
  var[332] = work1d.v[92];
  var[333] = work1d.v[93];
  var[334] = work1d.v[94];
  var[335] = work1d.v[95];
  var[336] = work1d.v[96];
  var[337] = work1d.v[97];
  var[338] = work1d.v[98];
  var[339] = work1d.v[99];
  var[340] = work1d.v[100];
  var[341] = work1d.v[101];
  var[342] = work1d.v[102];
  var[343] = work1d.v[103];
  var[344] = work1d.v[104];
  var[345] = work1d.v[105];
  var[346] = work1d.v[106];
  var[347] = work1d.v[107];
  var[348] = work1d.v[108];
  var[349] = work1d.v[109];
  var[350] = work1d.v[110];
  var[351] = work1d.v[111];
  var[352] = work1d.v[112];
  var[353] = work1d.v[113];
  var[354] = work1d.v[114];
  var[355] = work1d.v[115];
  var[356] = work1d.v[116];
  var[357] = work1d.v[117];
  var[358] = work1d.v[118];
  var[359] = work1d.v[119];
  var[360] = work1d.v[120];
  var[361] = work1d.v[121];
  var[362] = work1d.v[122];
  var[363] = work1d.v[123];
  var[364] = work1d.v[124];
  var[365] = work1d.v[125];
  var[366] = work1d.v[126];
  var[367] = work1d.v[127];
  var[368] = work1d.v[128];
  var[369] = work1d.v[129];
  var[370] = work1d.v[130];
  var[371] = work1d.v[131];
  var[372] = work1d.v[132];
  var[373] = work1d.v[133];
  var[374] = work1d.v[134];
  var[375] = work1d.v[135];
  var[376] = work1d.v[136];
  var[377] = work1d.v[137];
  var[378] = work1d.v[138];
  var[379] = work1d.v[139];
  var[380] = work1d.v[140];
  var[381] = work1d.v[141];
  var[382] = work1d.v[142];
  var[383] = work1d.v[143];
  var[384] = work1d.v[144];
  var[385] = work1d.v[145];
  var[386] = work1d.v[146];
  var[387] = work1d.v[147];
  var[388] = work1d.v[148];
  var[389] = work1d.v[149];
  var[390] = work1d.v[150];
  var[391] = work1d.v[151];
  var[392] = work1d.v[152];
  var[393] = work1d.v[153];
  var[394] = work1d.v[154];
  var[395] = work1d.v[155];
  var[396] = work1d.v[156];
  var[397] = work1d.v[157];
  var[398] = work1d.v[158];
  var[399] = work1d.v[159];
  var[400] = work1d.v[160];
  var[401] = work1d.v[161];
  var[402] = work1d.v[162];
  var[403] = work1d.v[163];
  var[404] = work1d.v[164];
  var[405] = work1d.v[165];
  var[406] = work1d.v[166];
  var[407] = work1d.v[167];
  var[408] = work1d.v[168];
  var[409] = work1d.v[169];
  var[410] = work1d.v[170];
  var[411] = work1d.v[171];
  var[412] = work1d.v[172];
  var[413] = work1d.v[173];
  var[414] = work1d.v[174];
  var[415] = work1d.v[175];
  var[416] = work1d.v[176];
  var[417] = work1d.v[177];
  var[418] = work1d.v[178];
  var[419] = work1d.v[179];
  var[420] = work1d.v[180];
  var[421] = work1d.v[181];
  var[422] = work1d.v[182];
  var[423] = work1d.v[183];
  var[424] = work1d.v[184];
  var[425] = work1d.v[185];
  var[426] = work1d.v[186];
  var[427] = work1d.v[187];
  var[428] = work1d.v[188];
  var[429] = work1d.v[189];
  var[430] = work1d.v[190];
  var[431] = work1d.v[191];
  var[432] = work1d.v[192];
  var[433] = work1d.v[193];
  var[434] = work1d.v[194];
  var[435] = work1d.v[195];
  var[436] = work1d.v[196];
  var[437] = work1d.v[197];
  var[438] = work1d.v[198];
  var[439] = work1d.v[199];
  var[440] = work1d.v[200];
  var[441] = work1d.v[201];
  var[442] = work1d.v[202];
  var[443] = work1d.v[203];
  var[444] = work1d.v[204];
  var[445] = work1d.v[205];
  var[446] = work1d.v[206];
  var[447] = work1d.v[207];
  var[448] = work1d.v[208];
  var[449] = work1d.v[209];
  var[450] = work1d.v[210];
  var[451] = work1d.v[211];
  var[452] = work1d.v[212];
  var[453] = work1d.v[213];
  var[454] = work1d.v[214];
  var[455] = work1d.v[215];
  var[456] = work1d.v[216];
  var[457] = work1d.v[217];
  var[458] = work1d.v[218];
  var[459] = work1d.v[219];
  var[460] = work1d.v[220];
  var[461] = work1d.v[221];
  var[462] = work1d.v[222];
  var[463] = work1d.v[223];
  var[464] = work1d.v[224];
  var[465] = work1d.v[225];
  var[466] = work1d.v[226];
  var[467] = work1d.v[227];
  var[468] = work1d.v[228];
  var[469] = work1d.v[229];
  var[470] = work1d.v[230];
  var[471] = work1d.v[231];
  var[472] = work1d.v[232];
  var[473] = work1d.v[233];
  var[474] = work1d.v[234];
  var[475] = work1d.v[235];
  var[476] = work1d.v[236];
  var[477] = work1d.v[237];
  var[478] = work1d.v[238];
  var[479] = work1d.v[239];
  var[480] = work1d.v[240];
  var[481] = work1d.v[241];
  var[482] = work1d.v[242];
  var[483] = work1d.v[243];
  var[484] = work1d.v[244];
  var[485] = work1d.v[245];
  var[486] = work1d.v[246];
  var[487] = work1d.v[247];
  var[488] = work1d.v[248];
  var[489] = work1d.v[249];
  var[490] = work1d.v[250];
  var[491] = work1d.v[251];
  var[492] = work1d.v[252];
  var[493] = work1d.v[253];
  var[494] = work1d.v[254];
  var[495] = work1d.v[255];
  var[496] = work1d.v[256];
  var[497] = work1d.v[257];
  var[498] = work1d.v[258];
  var[499] = work1d.v[259];
  var[500] = work1d.v[260];
  var[501] = work1d.v[261];
  var[502] = work1d.v[262];
  var[503] = work1d.v[263];
  var[504] = work1d.v[264];
  var[505] = work1d.v[265];
  var[506] = work1d.v[266];
  var[507] = work1d.v[267];
  var[508] = work1d.v[268];
  var[509] = work1d.v[269];
  var[510] = work1d.v[270];
  var[511] = work1d.v[271];
  var[512] = work1d.v[272];
  var[513] = work1d.v[273];
  var[514] = work1d.v[274];
  var[515] = work1d.v[275];
  var[516] = work1d.v[276];
  var[517] = work1d.v[277];
  var[518] = work1d.v[278];
  var[519] = work1d.v[279];
  var[520] = work1d.v[280];
  var[521] = work1d.v[281];
  var[522] = work1d.v[282];
  var[523] = work1d.v[283];
  var[524] = work1d.v[284];
  var[525] = work1d.v[285];
  var[526] = work1d.v[286];
  var[527] = work1d.v[287];
  var[528] = work1d.v[288];
  var[529] = work1d.v[289];
  var[530] = work1d.v[290];
  var[531] = work1d.v[291];
  var[532] = work1d.v[292];
  var[533] = work1d.v[293];
  var[534] = work1d.v[294];
  var[535] = work1d.v[295];
  var[536] = work1d.v[296];
  var[537] = work1d.v[297];
  var[538] = work1d.v[298];
  var[539] = work1d.v[299];
  var[540] = work1d.v[300];
  var[541] = work1d.v[301];
  var[542] = work1d.v[302];
  var[543] = work1d.v[303];
  var[544] = work1d.v[304];
  var[545] = work1d.v[305];
  var[546] = work1d.v[306];
  var[547] = work1d.v[307];
  var[548] = work1d.v[308];
  var[549] = work1d.v[309];
  var[550] = work1d.v[310];
  var[551] = work1d.v[311];
  var[552] = work1d.v[312];
  var[553] = work1d.v[313];
  var[554] = work1d.v[314];
  var[555] = work1d.v[315];
  var[556] = work1d.v[316];
  var[557] = work1d.v[317];
  var[558] = work1d.v[318];
  var[559] = work1d.v[319];
  var[560] = work1d.v[320];
  var[561] = work1d.v[446];
  var[562] = work1d.v[448];
  var[563] = work1d.v[449];
  var[564] = work1d.v[450];
  var[565] = work1d.v[452];
  var[566] = work1d.v[453];
  var[567] = work1d.v[454];
  var[568] = work1d.v[456];
  var[569] = work1d.v[457];
  var[570] = work1d.v[458];
  var[571] = work1d.v[460];
  var[572] = work1d.v[461];
  var[573] = work1d.v[462];
  var[574] = work1d.v[464];
  var[575] = work1d.v[465];
  var[576] = work1d.v[466];
  var[577] = work1d.v[468];
  var[578] = work1d.v[469];
  var[579] = work1d.v[470];
  var[580] = work1d.v[472];
  var[581] = work1d.v[473];
  var[582] = work1d.v[474];
  var[583] = work1d.v[476];
  var[584] = work1d.v[477];
  var[585] = work1d.v[478];
  var[586] = work1d.v[480];
  var[587] = work1d.v[481];
  var[588] = work1d.v[482];
  var[589] = work1d.v[484];
  var[590] = work1d.v[485];
  var[591] = work1d.v[486];
  var[592] = work1d.v[488];
  var[593] = work1d.v[489];
  var[594] = work1d.v[490];
  var[595] = work1d.v[492];
  var[596] = work1d.v[493];
  var[597] = work1d.v[494];
  var[598] = work1d.v[496];
  var[599] = work1d.v[497];
  var[600] = work1d.v[498];
  var[601] = work1d.v[500];
  var[602] = work1d.v[501];
  var[603] = work1d.v[502];
  var[604] = work1d.v[504];
  var[605] = work1d.v[505];
  var[606] = work1d.v[506];
  var[607] = work1d.v[508];
  var[608] = work1d.v[509];
  var[609] = work1d.v[510];
  var[610] = work1d.v[512];
  var[611] = work1d.v[513];
  var[612] = work1d.v[514];
  var[613] = work1d.v[516];
  var[614] = work1d.v[517];
  var[615] = work1d.v[518];
  var[616] = work1d.v[520];
  var[617] = work1d.v[521];
  var[618] = work1d.v[522];
  var[619] = work1d.v[524];
  var[620] = work1d.v[525];
  var[621] = work1d.v[526];
  var[622] = work1d.v[528];
  var[623] = work1d.v[529];
  var[624] = work1d.v[530];
  var[625] = work1d.v[532];
  var[626] = work1d.v[533];
  var[627] = work1d.v[534];
  var[628] = work1d.v[536];
  var[629] = work1d.v[537];
  var[630] = work1d.v[538];
  var[631] = work1d.v[540];
  var[632] = work1d.v[541];
  var[633] = work1d.v[542];
  var[634] = work1d.v[544];
  var[635] = work1d.v[545];
  var[636] = work1d.v[546];
  var[637] = work1d.v[548];
  var[638] = work1d.v[549];
  var[639] = work1d.v[550];
  var[640] = work1d.v[552];
  var[641] = work1d.v[553];
  var[642] = work1d.v[554];
  var[643] = work1d.v[556];
  var[644] = work1d.v[557];
  var[645] = work1d.v[558];
  var[646] = work1d.v[560];
  var[647] = work1d.v[561];
  var[648] = work1d.v[562];
  var[649] = work1d.v[564];
  var[650] = work1d.v[565];
  var[651] = work1d.v[566];
  var[652] = work1d.v[568];
  var[653] = work1d.v[569];
  var[654] = work1d.v[570];
  var[655] = work1d.v[572];
  var[656] = work1d.v[573];
  var[657] = work1d.v[574];
  var[658] = work1d.v[576];
  var[659] = work1d.v[577];
  var[660] = work1d.v[578];
  var[661] = work1d.v[580];
  var[662] = work1d.v[581];
  var[663] = work1d.v[582];
  var[664] = work1d.v[584];
  var[665] = work1d.v[585];
  var[666] = work1d.v[586];
  var[667] = work1d.v[588];
  var[668] = work1d.v[589];
  var[669] = work1d.v[590];
  var[670] = work1d.v[592];
  var[671] = work1d.v[593];
  var[672] = work1d.v[594];
  var[673] = work1d.v[596];
  var[674] = work1d.v[597];
  var[675] = work1d.v[598];
  var[676] = work1d.v[600];
  var[677] = work1d.v[601];
  var[678] = work1d.v[602];
  var[679] = work1d.v[604];
  var[680] = work1d.v[605];
  var[681] = work1d.v[607];
  var[682] = work1d.v[609];
  var[683] = work1d.v[610];
  var[684] = work1d.v[611];
  var[685] = work1d.v[613];
  var[686] = work1d.v[614];
  var[687] = work1d.v[615];
  var[688] = work1d.v[617];
  var[689] = work1d.v[618];
  var[690] = work1d.v[619];
  var[691] = work1d.v[621];
  var[692] = work1d.v[622];
  var[693] = work1d.v[623];
  var[694] = work1d.v[625];
  var[695] = work1d.v[626];
  var[696] = work1d.v[627];
  var[697] = work1d.v[629];
  var[698] = work1d.v[630];
  var[699] = work1d.v[631];
  var[700] = work1d.v[633];
  var[701] = work1d.v[634];
  var[702] = work1d.v[635];
  var[703] = work1d.v[637];
  var[704] = work1d.v[638];
  var[705] = work1d.v[639];
  var[706] = work1d.v[641];
  var[707] = work1d.v[642];
  var[708] = work1d.v[643];
  var[709] = work1d.v[645];
  var[710] = work1d.v[646];
  var[711] = work1d.v[647];
  var[712] = work1d.v[649];
  var[713] = work1d.v[650];
  var[714] = work1d.v[651];
  var[715] = work1d.v[653];
  var[716] = work1d.v[654];
  var[717] = work1d.v[655];
  var[718] = work1d.v[657];
  var[719] = work1d.v[658];
  var[720] = work1d.v[659];
  var[721] = work1d.v[661];
  var[722] = work1d.v[662];
  var[723] = work1d.v[663];
  var[724] = work1d.v[665];
  var[725] = work1d.v[666];
  var[726] = work1d.v[667];
  var[727] = work1d.v[669];
  var[728] = work1d.v[670];
  var[729] = work1d.v[671];
  var[730] = work1d.v[673];
  var[731] = work1d.v[674];
  var[732] = work1d.v[675];
  var[733] = work1d.v[677];
  var[734] = work1d.v[678];
  var[735] = work1d.v[679];
  var[736] = work1d.v[681];
  var[737] = work1d.v[682];
  var[738] = work1d.v[683];
  var[739] = work1d.v[685];
  var[740] = work1d.v[686];
  var[741] = work1d.v[687];
  var[742] = work1d.v[689];
  var[743] = work1d.v[690];
  var[744] = work1d.v[691];
  var[745] = work1d.v[693];
  var[746] = work1d.v[694];
  var[747] = work1d.v[695];
  var[748] = work1d.v[697];
  var[749] = work1d.v[698];
  var[750] = work1d.v[699];
  var[751] = work1d.v[701];
  var[752] = work1d.v[702];
  var[753] = work1d.v[703];
  var[754] = work1d.v[705];
  var[755] = work1d.v[706];
  var[756] = work1d.v[707];
  var[757] = work1d.v[709];
  var[758] = work1d.v[710];
  var[759] = work1d.v[711];
  var[760] = work1d.v[713];
  var[761] = work1d.v[714];
  var[762] = work1d.v[715];
  var[763] = work1d.v[717];
  var[764] = work1d.v[718];
  var[765] = work1d.v[719];
  var[766] = work1d.v[721];
  var[767] = work1d.v[722];
  var[768] = work1d.v[723];
  var[769] = work1d.v[725];
  var[770] = work1d.v[726];
  var[771] = work1d.v[727];
  var[772] = work1d.v[729];
  var[773] = work1d.v[730];
  var[774] = work1d.v[731];
  var[775] = work1d.v[733];
  var[776] = work1d.v[734];
  var[777] = work1d.v[735];
  var[778] = work1d.v[737];
  var[779] = work1d.v[738];
  var[780] = work1d.v[739];
  var[781] = work1d.v[741];
  var[782] = work1d.v[742];
  var[783] = work1d.v[743];
  var[784] = work1d.v[745];
  var[785] = work1d.v[746];
  var[786] = work1d.v[747];
  var[787] = work1d.v[749];
  var[788] = work1d.v[750];
  var[789] = work1d.v[751];
  var[790] = work1d.v[753];
  var[791] = work1d.v[754];
  var[792] = work1d.v[755];
  var[793] = work1d.v[757];
  var[794] = work1d.v[758];
  var[795] = work1d.v[759];
  var[796] = work1d.v[761];
  var[797] = work1d.v[762];
  var[798] = work1d.v[763];
  var[799] = work1d.v[765];
  var[800] = work1d.v[766];
  var[801] = work1d.v[321];
  var[802] = work1d.v[322];
  var[803] = work1d.v[323];
  var[804] = work1d.v[324];
  var[805] = work1d.v[325];
  var[806] = work1d.v[326];
  var[807] = work1d.v[327];
  var[808] = work1d.v[328];
  var[809] = work1d.v[329];
  var[810] = work1d.v[330];
  var[811] = work1d.v[331];
  var[812] = work1d.v[332];
  var[813] = work1d.v[333];
  var[814] = work1d.v[334];
  var[815] = work1d.v[335];
  var[816] = work1d.v[336];
  var[817] = work1d.v[337];
  var[818] = work1d.v[338];
  var[819] = work1d.v[339];
  var[820] = work1d.v[340];
  var[821] = work1d.v[341];
  var[822] = work1d.v[342];
  var[823] = work1d.v[343];
  var[824] = work1d.v[344];
  var[825] = work1d.v[345];
  var[826] = work1d.v[346];
  var[827] = work1d.v[347];
  var[828] = work1d.v[348];
  var[829] = work1d.v[349];
  var[830] = work1d.v[350];
  var[831] = work1d.v[351];
  var[832] = work1d.v[352];
  var[833] = work1d.v[353];
  var[834] = work1d.v[354];
  var[835] = work1d.v[355];
  var[836] = work1d.v[356];
  var[837] = work1d.v[357];
  var[838] = work1d.v[358];
  var[839] = work1d.v[359];
  var[840] = work1d.v[360];
  var[841] = work1d.v[361];
  var[842] = work1d.v[362];
  var[843] = work1d.v[363];
  var[844] = work1d.v[364];
  var[845] = work1d.v[365];
  var[846] = work1d.v[366];
  var[847] = work1d.v[367];
  var[848] = work1d.v[368];
  var[849] = work1d.v[369];
  var[850] = work1d.v[370];
  var[851] = work1d.v[371];
  var[852] = work1d.v[372];
  var[853] = work1d.v[373];
  var[854] = work1d.v[374];
  var[855] = work1d.v[375];
  var[856] = work1d.v[376];
  var[857] = work1d.v[377];
  var[858] = work1d.v[378];
  var[859] = work1d.v[379];
  var[860] = work1d.v[380];
  var[861] = work1d.v[381];
  var[862] = work1d.v[382];
  var[863] = work1d.v[383];
  var[864] = work1d.v[384];
  var[865] = work1d.v[385];
  var[866] = work1d.v[386];
  var[867] = work1d.v[387];
  var[868] = work1d.v[388];
  var[869] = work1d.v[389];
  var[870] = work1d.v[390];
  var[871] = work1d.v[391];
  var[872] = work1d.v[392];
  var[873] = work1d.v[393];
  var[874] = work1d.v[394];
  var[875] = work1d.v[395];
  var[876] = work1d.v[396];
  var[877] = work1d.v[397];
  var[878] = work1d.v[398];
  var[879] = work1d.v[399];
  var[880] = work1d.v[400];
  var[881] = work1d.v[401];
  var[882] = work1d.v[402];
  var[883] = work1d.v[404];
  var[884] = work1d.v[770];
  var[885] = work1d.v[851];
  var[886] = work1d.v[771];
  var[887] = work1d.v[854];
  var[888] = work1d.v[855];
  var[889] = work1d.v[772];
  var[890] = work1d.v[858];
  var[891] = work1d.v[859];
  var[892] = work1d.v[773];
  var[893] = work1d.v[862];
  var[894] = work1d.v[863];
  var[895] = work1d.v[774];
  var[896] = work1d.v[866];
  var[897] = work1d.v[867];
  var[898] = work1d.v[775];
  var[899] = work1d.v[870];
  var[900] = work1d.v[871];
  var[901] = work1d.v[776];
  var[902] = work1d.v[874];
  var[903] = work1d.v[875];
  var[904] = work1d.v[777];
  var[905] = work1d.v[878];
  var[906] = work1d.v[879];
  var[907] = work1d.v[778];
  var[908] = work1d.v[882];
  var[909] = work1d.v[883];
  var[910] = work1d.v[779];
  var[911] = work1d.v[886];
  var[912] = work1d.v[887];
  var[913] = work1d.v[780];
  var[914] = work1d.v[890];
  var[915] = work1d.v[891];
  var[916] = work1d.v[781];
  var[917] = work1d.v[894];
  var[918] = work1d.v[895];
  var[919] = work1d.v[782];
  var[920] = work1d.v[898];
  var[921] = work1d.v[899];
  var[922] = work1d.v[783];
  var[923] = work1d.v[902];
  var[924] = work1d.v[903];
  var[925] = work1d.v[784];
  var[926] = work1d.v[906];
  var[927] = work1d.v[907];
  var[928] = work1d.v[785];
  var[929] = work1d.v[910];
  var[930] = work1d.v[911];
  var[931] = work1d.v[786];
  var[932] = work1d.v[914];
  var[933] = work1d.v[915];
  var[934] = work1d.v[787];
  var[935] = work1d.v[918];
  var[936] = work1d.v[919];
  var[937] = work1d.v[788];
  var[938] = work1d.v[922];
  var[939] = work1d.v[923];
  var[940] = work1d.v[789];
  var[941] = work1d.v[926];
  var[942] = work1d.v[927];
  var[943] = work1d.v[790];
  var[944] = work1d.v[930];
  var[945] = work1d.v[931];
  var[946] = work1d.v[791];
  var[947] = work1d.v[934];
  var[948] = work1d.v[935];
  var[949] = work1d.v[792];
  var[950] = work1d.v[938];
  var[951] = work1d.v[939];
  var[952] = work1d.v[793];
  var[953] = work1d.v[942];
  var[954] = work1d.v[943];
  var[955] = work1d.v[794];
  var[956] = work1d.v[946];
  var[957] = work1d.v[947];
  var[958] = work1d.v[795];
  var[959] = work1d.v[950];
  var[960] = work1d.v[951];
  var[961] = work1d.v[796];
  var[962] = work1d.v[954];
  var[963] = work1d.v[955];
  var[964] = work1d.v[797];
  var[965] = work1d.v[958];
  var[966] = work1d.v[959];
  var[967] = work1d.v[798];
  var[968] = work1d.v[962];
  var[969] = work1d.v[963];
  var[970] = work1d.v[799];
  var[971] = work1d.v[966];
  var[972] = work1d.v[967];
  var[973] = work1d.v[800];
  var[974] = work1d.v[970];
  var[975] = work1d.v[971];
  var[976] = work1d.v[801];
  var[977] = work1d.v[974];
  var[978] = work1d.v[975];
  var[979] = work1d.v[802];
  var[980] = work1d.v[978];
  var[981] = work1d.v[979];
  var[982] = work1d.v[803];
  var[983] = work1d.v[982];
  var[984] = work1d.v[983];
  var[985] = work1d.v[804];
  var[986] = work1d.v[986];
  var[987] = work1d.v[987];
  var[988] = work1d.v[805];
  var[989] = work1d.v[990];
  var[990] = work1d.v[991];
  var[991] = work1d.v[806];
  var[992] = work1d.v[994];
  var[993] = work1d.v[995];
  var[994] = work1d.v[807];
  var[995] = work1d.v[996];
  var[996] = work1d.v[997];
  var[997] = work1d.v[808];
  var[998] = work1d.v[809];
  var[999] = work1d.v[810];
  var[1000] = work1d.v[768];
#ifndef ZERO_LIBRARY_MODE
  if (settings1d.debug) {
    printf("Squared norm for solution is %.8g.\n", check_residual1d(target, var));
  }
#endif
}
void ldl_factor1d(void) {
  work1d.d[0] = work1d.KKT[0];
  if (work1d.d[0] < 0)
    work1d.d[0] = settings1d.kkt_reg;
  else
    work1d.d[0] += settings1d.kkt_reg;
  work1d.d_inv[0] = 1/work1d.d[0];
  work1d.v[1] = work1d.KKT[1];
  work1d.d[1] = work1d.v[1];
  if (work1d.d[1] < 0)
    work1d.d[1] = settings1d.kkt_reg;
  else
    work1d.d[1] += settings1d.kkt_reg;
  work1d.d_inv[1] = 1/work1d.d[1];
  work1d.L[82] = (work1d.KKT[2])*work1d.d_inv[1];
  work1d.v[2] = work1d.KKT[3];
  work1d.d[2] = work1d.v[2];
  if (work1d.d[2] < 0)
    work1d.d[2] = settings1d.kkt_reg;
  else
    work1d.d[2] += settings1d.kkt_reg;
  work1d.d_inv[2] = 1/work1d.d[2];
  work1d.L[84] = (work1d.KKT[4])*work1d.d_inv[2];
  work1d.v[3] = work1d.KKT[5];
  work1d.d[3] = work1d.v[3];
  if (work1d.d[3] < 0)
    work1d.d[3] = settings1d.kkt_reg;
  else
    work1d.d[3] += settings1d.kkt_reg;
  work1d.d_inv[3] = 1/work1d.d[3];
  work1d.L[86] = (work1d.KKT[6])*work1d.d_inv[3];
  work1d.v[4] = work1d.KKT[7];
  work1d.d[4] = work1d.v[4];
  if (work1d.d[4] < 0)
    work1d.d[4] = settings1d.kkt_reg;
  else
    work1d.d[4] += settings1d.kkt_reg;
  work1d.d_inv[4] = 1/work1d.d[4];
  work1d.L[89] = (work1d.KKT[8])*work1d.d_inv[4];
  work1d.v[5] = work1d.KKT[9];
  work1d.d[5] = work1d.v[5];
  if (work1d.d[5] < 0)
    work1d.d[5] = settings1d.kkt_reg;
  else
    work1d.d[5] += settings1d.kkt_reg;
  work1d.d_inv[5] = 1/work1d.d[5];
  work1d.L[91] = (work1d.KKT[10])*work1d.d_inv[5];
  work1d.v[6] = work1d.KKT[11];
  work1d.d[6] = work1d.v[6];
  if (work1d.d[6] < 0)
    work1d.d[6] = settings1d.kkt_reg;
  else
    work1d.d[6] += settings1d.kkt_reg;
  work1d.d_inv[6] = 1/work1d.d[6];
  work1d.L[93] = (work1d.KKT[12])*work1d.d_inv[6];
  work1d.v[7] = work1d.KKT[13];
  work1d.d[7] = work1d.v[7];
  if (work1d.d[7] < 0)
    work1d.d[7] = settings1d.kkt_reg;
  else
    work1d.d[7] += settings1d.kkt_reg;
  work1d.d_inv[7] = 1/work1d.d[7];
  work1d.L[96] = (work1d.KKT[14])*work1d.d_inv[7];
  work1d.v[8] = work1d.KKT[15];
  work1d.d[8] = work1d.v[8];
  if (work1d.d[8] < 0)
    work1d.d[8] = settings1d.kkt_reg;
  else
    work1d.d[8] += settings1d.kkt_reg;
  work1d.d_inv[8] = 1/work1d.d[8];
  work1d.L[98] = (work1d.KKT[16])*work1d.d_inv[8];
  work1d.v[9] = work1d.KKT[17];
  work1d.d[9] = work1d.v[9];
  if (work1d.d[9] < 0)
    work1d.d[9] = settings1d.kkt_reg;
  else
    work1d.d[9] += settings1d.kkt_reg;
  work1d.d_inv[9] = 1/work1d.d[9];
  work1d.L[100] = (work1d.KKT[18])*work1d.d_inv[9];
  work1d.v[10] = work1d.KKT[19];
  work1d.d[10] = work1d.v[10];
  if (work1d.d[10] < 0)
    work1d.d[10] = settings1d.kkt_reg;
  else
    work1d.d[10] += settings1d.kkt_reg;
  work1d.d_inv[10] = 1/work1d.d[10];
  work1d.L[103] = (work1d.KKT[20])*work1d.d_inv[10];
  work1d.v[11] = work1d.KKT[21];
  work1d.d[11] = work1d.v[11];
  if (work1d.d[11] < 0)
    work1d.d[11] = settings1d.kkt_reg;
  else
    work1d.d[11] += settings1d.kkt_reg;
  work1d.d_inv[11] = 1/work1d.d[11];
  work1d.L[105] = (work1d.KKT[22])*work1d.d_inv[11];
  work1d.v[12] = work1d.KKT[23];
  work1d.d[12] = work1d.v[12];
  if (work1d.d[12] < 0)
    work1d.d[12] = settings1d.kkt_reg;
  else
    work1d.d[12] += settings1d.kkt_reg;
  work1d.d_inv[12] = 1/work1d.d[12];
  work1d.L[107] = (work1d.KKT[24])*work1d.d_inv[12];
  work1d.v[13] = work1d.KKT[25];
  work1d.d[13] = work1d.v[13];
  if (work1d.d[13] < 0)
    work1d.d[13] = settings1d.kkt_reg;
  else
    work1d.d[13] += settings1d.kkt_reg;
  work1d.d_inv[13] = 1/work1d.d[13];
  work1d.L[110] = (work1d.KKT[26])*work1d.d_inv[13];
  work1d.v[14] = work1d.KKT[27];
  work1d.d[14] = work1d.v[14];
  if (work1d.d[14] < 0)
    work1d.d[14] = settings1d.kkt_reg;
  else
    work1d.d[14] += settings1d.kkt_reg;
  work1d.d_inv[14] = 1/work1d.d[14];
  work1d.L[112] = (work1d.KKT[28])*work1d.d_inv[14];
  work1d.v[15] = work1d.KKT[29];
  work1d.d[15] = work1d.v[15];
  if (work1d.d[15] < 0)
    work1d.d[15] = settings1d.kkt_reg;
  else
    work1d.d[15] += settings1d.kkt_reg;
  work1d.d_inv[15] = 1/work1d.d[15];
  work1d.L[114] = (work1d.KKT[30])*work1d.d_inv[15];
  work1d.v[16] = work1d.KKT[31];
  work1d.d[16] = work1d.v[16];
  if (work1d.d[16] < 0)
    work1d.d[16] = settings1d.kkt_reg;
  else
    work1d.d[16] += settings1d.kkt_reg;
  work1d.d_inv[16] = 1/work1d.d[16];
  work1d.L[117] = (work1d.KKT[32])*work1d.d_inv[16];
  work1d.v[17] = work1d.KKT[33];
  work1d.d[17] = work1d.v[17];
  if (work1d.d[17] < 0)
    work1d.d[17] = settings1d.kkt_reg;
  else
    work1d.d[17] += settings1d.kkt_reg;
  work1d.d_inv[17] = 1/work1d.d[17];
  work1d.L[119] = (work1d.KKT[34])*work1d.d_inv[17];
  work1d.v[18] = work1d.KKT[35];
  work1d.d[18] = work1d.v[18];
  if (work1d.d[18] < 0)
    work1d.d[18] = settings1d.kkt_reg;
  else
    work1d.d[18] += settings1d.kkt_reg;
  work1d.d_inv[18] = 1/work1d.d[18];
  work1d.L[121] = (work1d.KKT[36])*work1d.d_inv[18];
  work1d.v[19] = work1d.KKT[37];
  work1d.d[19] = work1d.v[19];
  if (work1d.d[19] < 0)
    work1d.d[19] = settings1d.kkt_reg;
  else
    work1d.d[19] += settings1d.kkt_reg;
  work1d.d_inv[19] = 1/work1d.d[19];
  work1d.L[124] = (work1d.KKT[38])*work1d.d_inv[19];
  work1d.v[20] = work1d.KKT[39];
  work1d.d[20] = work1d.v[20];
  if (work1d.d[20] < 0)
    work1d.d[20] = settings1d.kkt_reg;
  else
    work1d.d[20] += settings1d.kkt_reg;
  work1d.d_inv[20] = 1/work1d.d[20];
  work1d.L[126] = (work1d.KKT[40])*work1d.d_inv[20];
  work1d.v[21] = work1d.KKT[41];
  work1d.d[21] = work1d.v[21];
  if (work1d.d[21] < 0)
    work1d.d[21] = settings1d.kkt_reg;
  else
    work1d.d[21] += settings1d.kkt_reg;
  work1d.d_inv[21] = 1/work1d.d[21];
  work1d.L[128] = (work1d.KKT[42])*work1d.d_inv[21];
  work1d.v[22] = work1d.KKT[43];
  work1d.d[22] = work1d.v[22];
  if (work1d.d[22] < 0)
    work1d.d[22] = settings1d.kkt_reg;
  else
    work1d.d[22] += settings1d.kkt_reg;
  work1d.d_inv[22] = 1/work1d.d[22];
  work1d.L[131] = (work1d.KKT[44])*work1d.d_inv[22];
  work1d.v[23] = work1d.KKT[45];
  work1d.d[23] = work1d.v[23];
  if (work1d.d[23] < 0)
    work1d.d[23] = settings1d.kkt_reg;
  else
    work1d.d[23] += settings1d.kkt_reg;
  work1d.d_inv[23] = 1/work1d.d[23];
  work1d.L[133] = (work1d.KKT[46])*work1d.d_inv[23];
  work1d.v[24] = work1d.KKT[47];
  work1d.d[24] = work1d.v[24];
  if (work1d.d[24] < 0)
    work1d.d[24] = settings1d.kkt_reg;
  else
    work1d.d[24] += settings1d.kkt_reg;
  work1d.d_inv[24] = 1/work1d.d[24];
  work1d.L[135] = (work1d.KKT[48])*work1d.d_inv[24];
  work1d.v[25] = work1d.KKT[49];
  work1d.d[25] = work1d.v[25];
  if (work1d.d[25] < 0)
    work1d.d[25] = settings1d.kkt_reg;
  else
    work1d.d[25] += settings1d.kkt_reg;
  work1d.d_inv[25] = 1/work1d.d[25];
  work1d.L[138] = (work1d.KKT[50])*work1d.d_inv[25];
  work1d.v[26] = work1d.KKT[51];
  work1d.d[26] = work1d.v[26];
  if (work1d.d[26] < 0)
    work1d.d[26] = settings1d.kkt_reg;
  else
    work1d.d[26] += settings1d.kkt_reg;
  work1d.d_inv[26] = 1/work1d.d[26];
  work1d.L[140] = (work1d.KKT[52])*work1d.d_inv[26];
  work1d.v[27] = work1d.KKT[53];
  work1d.d[27] = work1d.v[27];
  if (work1d.d[27] < 0)
    work1d.d[27] = settings1d.kkt_reg;
  else
    work1d.d[27] += settings1d.kkt_reg;
  work1d.d_inv[27] = 1/work1d.d[27];
  work1d.L[142] = (work1d.KKT[54])*work1d.d_inv[27];
  work1d.v[28] = work1d.KKT[55];
  work1d.d[28] = work1d.v[28];
  if (work1d.d[28] < 0)
    work1d.d[28] = settings1d.kkt_reg;
  else
    work1d.d[28] += settings1d.kkt_reg;
  work1d.d_inv[28] = 1/work1d.d[28];
  work1d.L[145] = (work1d.KKT[56])*work1d.d_inv[28];
  work1d.v[29] = work1d.KKT[57];
  work1d.d[29] = work1d.v[29];
  if (work1d.d[29] < 0)
    work1d.d[29] = settings1d.kkt_reg;
  else
    work1d.d[29] += settings1d.kkt_reg;
  work1d.d_inv[29] = 1/work1d.d[29];
  work1d.L[147] = (work1d.KKT[58])*work1d.d_inv[29];
  work1d.v[30] = work1d.KKT[59];
  work1d.d[30] = work1d.v[30];
  if (work1d.d[30] < 0)
    work1d.d[30] = settings1d.kkt_reg;
  else
    work1d.d[30] += settings1d.kkt_reg;
  work1d.d_inv[30] = 1/work1d.d[30];
  work1d.L[149] = (work1d.KKT[60])*work1d.d_inv[30];
  work1d.v[31] = work1d.KKT[61];
  work1d.d[31] = work1d.v[31];
  if (work1d.d[31] < 0)
    work1d.d[31] = settings1d.kkt_reg;
  else
    work1d.d[31] += settings1d.kkt_reg;
  work1d.d_inv[31] = 1/work1d.d[31];
  work1d.L[152] = (work1d.KKT[62])*work1d.d_inv[31];
  work1d.v[32] = work1d.KKT[63];
  work1d.d[32] = work1d.v[32];
  if (work1d.d[32] < 0)
    work1d.d[32] = settings1d.kkt_reg;
  else
    work1d.d[32] += settings1d.kkt_reg;
  work1d.d_inv[32] = 1/work1d.d[32];
  work1d.L[154] = (work1d.KKT[64])*work1d.d_inv[32];
  work1d.v[33] = work1d.KKT[65];
  work1d.d[33] = work1d.v[33];
  if (work1d.d[33] < 0)
    work1d.d[33] = settings1d.kkt_reg;
  else
    work1d.d[33] += settings1d.kkt_reg;
  work1d.d_inv[33] = 1/work1d.d[33];
  work1d.L[156] = (work1d.KKT[66])*work1d.d_inv[33];
  work1d.v[34] = work1d.KKT[67];
  work1d.d[34] = work1d.v[34];
  if (work1d.d[34] < 0)
    work1d.d[34] = settings1d.kkt_reg;
  else
    work1d.d[34] += settings1d.kkt_reg;
  work1d.d_inv[34] = 1/work1d.d[34];
  work1d.L[159] = (work1d.KKT[68])*work1d.d_inv[34];
  work1d.v[35] = work1d.KKT[69];
  work1d.d[35] = work1d.v[35];
  if (work1d.d[35] < 0)
    work1d.d[35] = settings1d.kkt_reg;
  else
    work1d.d[35] += settings1d.kkt_reg;
  work1d.d_inv[35] = 1/work1d.d[35];
  work1d.L[161] = (work1d.KKT[70])*work1d.d_inv[35];
  work1d.v[36] = work1d.KKT[71];
  work1d.d[36] = work1d.v[36];
  if (work1d.d[36] < 0)
    work1d.d[36] = settings1d.kkt_reg;
  else
    work1d.d[36] += settings1d.kkt_reg;
  work1d.d_inv[36] = 1/work1d.d[36];
  work1d.L[163] = (work1d.KKT[72])*work1d.d_inv[36];
  work1d.v[37] = work1d.KKT[73];
  work1d.d[37] = work1d.v[37];
  if (work1d.d[37] < 0)
    work1d.d[37] = settings1d.kkt_reg;
  else
    work1d.d[37] += settings1d.kkt_reg;
  work1d.d_inv[37] = 1/work1d.d[37];
  work1d.L[166] = (work1d.KKT[74])*work1d.d_inv[37];
  work1d.v[38] = work1d.KKT[75];
  work1d.d[38] = work1d.v[38];
  if (work1d.d[38] < 0)
    work1d.d[38] = settings1d.kkt_reg;
  else
    work1d.d[38] += settings1d.kkt_reg;
  work1d.d_inv[38] = 1/work1d.d[38];
  work1d.L[168] = (work1d.KKT[76])*work1d.d_inv[38];
  work1d.v[39] = work1d.KKT[77];
  work1d.d[39] = work1d.v[39];
  if (work1d.d[39] < 0)
    work1d.d[39] = settings1d.kkt_reg;
  else
    work1d.d[39] += settings1d.kkt_reg;
  work1d.d_inv[39] = 1/work1d.d[39];
  work1d.L[170] = (work1d.KKT[78])*work1d.d_inv[39];
  work1d.v[40] = work1d.KKT[79];
  work1d.d[40] = work1d.v[40];
  if (work1d.d[40] < 0)
    work1d.d[40] = settings1d.kkt_reg;
  else
    work1d.d[40] += settings1d.kkt_reg;
  work1d.d_inv[40] = 1/work1d.d[40];
  work1d.L[173] = (work1d.KKT[80])*work1d.d_inv[40];
  work1d.v[41] = work1d.KKT[81];
  work1d.d[41] = work1d.v[41];
  if (work1d.d[41] < 0)
    work1d.d[41] = settings1d.kkt_reg;
  else
    work1d.d[41] += settings1d.kkt_reg;
  work1d.d_inv[41] = 1/work1d.d[41];
  work1d.L[175] = (work1d.KKT[82])*work1d.d_inv[41];
  work1d.v[42] = work1d.KKT[83];
  work1d.d[42] = work1d.v[42];
  if (work1d.d[42] < 0)
    work1d.d[42] = settings1d.kkt_reg;
  else
    work1d.d[42] += settings1d.kkt_reg;
  work1d.d_inv[42] = 1/work1d.d[42];
  work1d.L[177] = (work1d.KKT[84])*work1d.d_inv[42];
  work1d.v[43] = work1d.KKT[85];
  work1d.d[43] = work1d.v[43];
  if (work1d.d[43] < 0)
    work1d.d[43] = settings1d.kkt_reg;
  else
    work1d.d[43] += settings1d.kkt_reg;
  work1d.d_inv[43] = 1/work1d.d[43];
  work1d.L[180] = (work1d.KKT[86])*work1d.d_inv[43];
  work1d.v[44] = work1d.KKT[87];
  work1d.d[44] = work1d.v[44];
  if (work1d.d[44] < 0)
    work1d.d[44] = settings1d.kkt_reg;
  else
    work1d.d[44] += settings1d.kkt_reg;
  work1d.d_inv[44] = 1/work1d.d[44];
  work1d.L[182] = (work1d.KKT[88])*work1d.d_inv[44];
  work1d.v[45] = work1d.KKT[89];
  work1d.d[45] = work1d.v[45];
  if (work1d.d[45] < 0)
    work1d.d[45] = settings1d.kkt_reg;
  else
    work1d.d[45] += settings1d.kkt_reg;
  work1d.d_inv[45] = 1/work1d.d[45];
  work1d.L[184] = (work1d.KKT[90])*work1d.d_inv[45];
  work1d.v[46] = work1d.KKT[91];
  work1d.d[46] = work1d.v[46];
  if (work1d.d[46] < 0)
    work1d.d[46] = settings1d.kkt_reg;
  else
    work1d.d[46] += settings1d.kkt_reg;
  work1d.d_inv[46] = 1/work1d.d[46];
  work1d.L[187] = (work1d.KKT[92])*work1d.d_inv[46];
  work1d.v[47] = work1d.KKT[93];
  work1d.d[47] = work1d.v[47];
  if (work1d.d[47] < 0)
    work1d.d[47] = settings1d.kkt_reg;
  else
    work1d.d[47] += settings1d.kkt_reg;
  work1d.d_inv[47] = 1/work1d.d[47];
  work1d.L[189] = (work1d.KKT[94])*work1d.d_inv[47];
  work1d.v[48] = work1d.KKT[95];
  work1d.d[48] = work1d.v[48];
  if (work1d.d[48] < 0)
    work1d.d[48] = settings1d.kkt_reg;
  else
    work1d.d[48] += settings1d.kkt_reg;
  work1d.d_inv[48] = 1/work1d.d[48];
  work1d.L[191] = (work1d.KKT[96])*work1d.d_inv[48];
  work1d.v[49] = work1d.KKT[97];
  work1d.d[49] = work1d.v[49];
  if (work1d.d[49] < 0)
    work1d.d[49] = settings1d.kkt_reg;
  else
    work1d.d[49] += settings1d.kkt_reg;
  work1d.d_inv[49] = 1/work1d.d[49];
  work1d.L[194] = (work1d.KKT[98])*work1d.d_inv[49];
  work1d.v[50] = work1d.KKT[99];
  work1d.d[50] = work1d.v[50];
  if (work1d.d[50] < 0)
    work1d.d[50] = settings1d.kkt_reg;
  else
    work1d.d[50] += settings1d.kkt_reg;
  work1d.d_inv[50] = 1/work1d.d[50];
  work1d.L[196] = (work1d.KKT[100])*work1d.d_inv[50];
  work1d.v[51] = work1d.KKT[101];
  work1d.d[51] = work1d.v[51];
  if (work1d.d[51] < 0)
    work1d.d[51] = settings1d.kkt_reg;
  else
    work1d.d[51] += settings1d.kkt_reg;
  work1d.d_inv[51] = 1/work1d.d[51];
  work1d.L[198] = (work1d.KKT[102])*work1d.d_inv[51];
  work1d.v[52] = work1d.KKT[103];
  work1d.d[52] = work1d.v[52];
  if (work1d.d[52] < 0)
    work1d.d[52] = settings1d.kkt_reg;
  else
    work1d.d[52] += settings1d.kkt_reg;
  work1d.d_inv[52] = 1/work1d.d[52];
  work1d.L[201] = (work1d.KKT[104])*work1d.d_inv[52];
  work1d.v[53] = work1d.KKT[105];
  work1d.d[53] = work1d.v[53];
  if (work1d.d[53] < 0)
    work1d.d[53] = settings1d.kkt_reg;
  else
    work1d.d[53] += settings1d.kkt_reg;
  work1d.d_inv[53] = 1/work1d.d[53];
  work1d.L[203] = (work1d.KKT[106])*work1d.d_inv[53];
  work1d.v[54] = work1d.KKT[107];
  work1d.d[54] = work1d.v[54];
  if (work1d.d[54] < 0)
    work1d.d[54] = settings1d.kkt_reg;
  else
    work1d.d[54] += settings1d.kkt_reg;
  work1d.d_inv[54] = 1/work1d.d[54];
  work1d.L[205] = (work1d.KKT[108])*work1d.d_inv[54];
  work1d.v[55] = work1d.KKT[109];
  work1d.d[55] = work1d.v[55];
  if (work1d.d[55] < 0)
    work1d.d[55] = settings1d.kkt_reg;
  else
    work1d.d[55] += settings1d.kkt_reg;
  work1d.d_inv[55] = 1/work1d.d[55];
  work1d.L[208] = (work1d.KKT[110])*work1d.d_inv[55];
  work1d.v[56] = work1d.KKT[111];
  work1d.d[56] = work1d.v[56];
  if (work1d.d[56] < 0)
    work1d.d[56] = settings1d.kkt_reg;
  else
    work1d.d[56] += settings1d.kkt_reg;
  work1d.d_inv[56] = 1/work1d.d[56];
  work1d.L[210] = (work1d.KKT[112])*work1d.d_inv[56];
  work1d.v[57] = work1d.KKT[113];
  work1d.d[57] = work1d.v[57];
  if (work1d.d[57] < 0)
    work1d.d[57] = settings1d.kkt_reg;
  else
    work1d.d[57] += settings1d.kkt_reg;
  work1d.d_inv[57] = 1/work1d.d[57];
  work1d.L[212] = (work1d.KKT[114])*work1d.d_inv[57];
  work1d.v[58] = work1d.KKT[115];
  work1d.d[58] = work1d.v[58];
  if (work1d.d[58] < 0)
    work1d.d[58] = settings1d.kkt_reg;
  else
    work1d.d[58] += settings1d.kkt_reg;
  work1d.d_inv[58] = 1/work1d.d[58];
  work1d.L[215] = (work1d.KKT[116])*work1d.d_inv[58];
  work1d.v[59] = work1d.KKT[117];
  work1d.d[59] = work1d.v[59];
  if (work1d.d[59] < 0)
    work1d.d[59] = settings1d.kkt_reg;
  else
    work1d.d[59] += settings1d.kkt_reg;
  work1d.d_inv[59] = 1/work1d.d[59];
  work1d.L[217] = (work1d.KKT[118])*work1d.d_inv[59];
  work1d.v[60] = work1d.KKT[119];
  work1d.d[60] = work1d.v[60];
  if (work1d.d[60] < 0)
    work1d.d[60] = settings1d.kkt_reg;
  else
    work1d.d[60] += settings1d.kkt_reg;
  work1d.d_inv[60] = 1/work1d.d[60];
  work1d.L[219] = (work1d.KKT[120])*work1d.d_inv[60];
  work1d.v[61] = work1d.KKT[121];
  work1d.d[61] = work1d.v[61];
  if (work1d.d[61] < 0)
    work1d.d[61] = settings1d.kkt_reg;
  else
    work1d.d[61] += settings1d.kkt_reg;
  work1d.d_inv[61] = 1/work1d.d[61];
  work1d.L[222] = (work1d.KKT[122])*work1d.d_inv[61];
  work1d.v[62] = work1d.KKT[123];
  work1d.d[62] = work1d.v[62];
  if (work1d.d[62] < 0)
    work1d.d[62] = settings1d.kkt_reg;
  else
    work1d.d[62] += settings1d.kkt_reg;
  work1d.d_inv[62] = 1/work1d.d[62];
  work1d.L[224] = (work1d.KKT[124])*work1d.d_inv[62];
  work1d.v[63] = work1d.KKT[125];
  work1d.d[63] = work1d.v[63];
  if (work1d.d[63] < 0)
    work1d.d[63] = settings1d.kkt_reg;
  else
    work1d.d[63] += settings1d.kkt_reg;
  work1d.d_inv[63] = 1/work1d.d[63];
  work1d.L[226] = (work1d.KKT[126])*work1d.d_inv[63];
  work1d.v[64] = work1d.KKT[127];
  work1d.d[64] = work1d.v[64];
  if (work1d.d[64] < 0)
    work1d.d[64] = settings1d.kkt_reg;
  else
    work1d.d[64] += settings1d.kkt_reg;
  work1d.d_inv[64] = 1/work1d.d[64];
  work1d.L[229] = (work1d.KKT[128])*work1d.d_inv[64];
  work1d.v[65] = work1d.KKT[129];
  work1d.d[65] = work1d.v[65];
  if (work1d.d[65] < 0)
    work1d.d[65] = settings1d.kkt_reg;
  else
    work1d.d[65] += settings1d.kkt_reg;
  work1d.d_inv[65] = 1/work1d.d[65];
  work1d.L[231] = (work1d.KKT[130])*work1d.d_inv[65];
  work1d.v[66] = work1d.KKT[131];
  work1d.d[66] = work1d.v[66];
  if (work1d.d[66] < 0)
    work1d.d[66] = settings1d.kkt_reg;
  else
    work1d.d[66] += settings1d.kkt_reg;
  work1d.d_inv[66] = 1/work1d.d[66];
  work1d.L[233] = (work1d.KKT[132])*work1d.d_inv[66];
  work1d.v[67] = work1d.KKT[133];
  work1d.d[67] = work1d.v[67];
  if (work1d.d[67] < 0)
    work1d.d[67] = settings1d.kkt_reg;
  else
    work1d.d[67] += settings1d.kkt_reg;
  work1d.d_inv[67] = 1/work1d.d[67];
  work1d.L[236] = (work1d.KKT[134])*work1d.d_inv[67];
  work1d.v[68] = work1d.KKT[135];
  work1d.d[68] = work1d.v[68];
  if (work1d.d[68] < 0)
    work1d.d[68] = settings1d.kkt_reg;
  else
    work1d.d[68] += settings1d.kkt_reg;
  work1d.d_inv[68] = 1/work1d.d[68];
  work1d.L[238] = (work1d.KKT[136])*work1d.d_inv[68];
  work1d.v[69] = work1d.KKT[137];
  work1d.d[69] = work1d.v[69];
  if (work1d.d[69] < 0)
    work1d.d[69] = settings1d.kkt_reg;
  else
    work1d.d[69] += settings1d.kkt_reg;
  work1d.d_inv[69] = 1/work1d.d[69];
  work1d.L[240] = (work1d.KKT[138])*work1d.d_inv[69];
  work1d.v[70] = work1d.KKT[139];
  work1d.d[70] = work1d.v[70];
  if (work1d.d[70] < 0)
    work1d.d[70] = settings1d.kkt_reg;
  else
    work1d.d[70] += settings1d.kkt_reg;
  work1d.d_inv[70] = 1/work1d.d[70];
  work1d.L[243] = (work1d.KKT[140])*work1d.d_inv[70];
  work1d.v[71] = work1d.KKT[141];
  work1d.d[71] = work1d.v[71];
  if (work1d.d[71] < 0)
    work1d.d[71] = settings1d.kkt_reg;
  else
    work1d.d[71] += settings1d.kkt_reg;
  work1d.d_inv[71] = 1/work1d.d[71];
  work1d.L[245] = (work1d.KKT[142])*work1d.d_inv[71];
  work1d.v[72] = work1d.KKT[143];
  work1d.d[72] = work1d.v[72];
  if (work1d.d[72] < 0)
    work1d.d[72] = settings1d.kkt_reg;
  else
    work1d.d[72] += settings1d.kkt_reg;
  work1d.d_inv[72] = 1/work1d.d[72];
  work1d.L[247] = (work1d.KKT[144])*work1d.d_inv[72];
  work1d.v[73] = work1d.KKT[145];
  work1d.d[73] = work1d.v[73];
  if (work1d.d[73] < 0)
    work1d.d[73] = settings1d.kkt_reg;
  else
    work1d.d[73] += settings1d.kkt_reg;
  work1d.d_inv[73] = 1/work1d.d[73];
  work1d.L[250] = (work1d.KKT[146])*work1d.d_inv[73];
  work1d.v[74] = work1d.KKT[147];
  work1d.d[74] = work1d.v[74];
  if (work1d.d[74] < 0)
    work1d.d[74] = settings1d.kkt_reg;
  else
    work1d.d[74] += settings1d.kkt_reg;
  work1d.d_inv[74] = 1/work1d.d[74];
  work1d.L[252] = (work1d.KKT[148])*work1d.d_inv[74];
  work1d.v[75] = work1d.KKT[149];
  work1d.d[75] = work1d.v[75];
  if (work1d.d[75] < 0)
    work1d.d[75] = settings1d.kkt_reg;
  else
    work1d.d[75] += settings1d.kkt_reg;
  work1d.d_inv[75] = 1/work1d.d[75];
  work1d.L[254] = (work1d.KKT[150])*work1d.d_inv[75];
  work1d.v[76] = work1d.KKT[151];
  work1d.d[76] = work1d.v[76];
  if (work1d.d[76] < 0)
    work1d.d[76] = settings1d.kkt_reg;
  else
    work1d.d[76] += settings1d.kkt_reg;
  work1d.d_inv[76] = 1/work1d.d[76];
  work1d.L[257] = (work1d.KKT[152])*work1d.d_inv[76];
  work1d.v[77] = work1d.KKT[153];
  work1d.d[77] = work1d.v[77];
  if (work1d.d[77] < 0)
    work1d.d[77] = settings1d.kkt_reg;
  else
    work1d.d[77] += settings1d.kkt_reg;
  work1d.d_inv[77] = 1/work1d.d[77];
  work1d.L[259] = (work1d.KKT[154])*work1d.d_inv[77];
  work1d.v[78] = work1d.KKT[155];
  work1d.d[78] = work1d.v[78];
  if (work1d.d[78] < 0)
    work1d.d[78] = settings1d.kkt_reg;
  else
    work1d.d[78] += settings1d.kkt_reg;
  work1d.d_inv[78] = 1/work1d.d[78];
  work1d.L[261] = (work1d.KKT[156])*work1d.d_inv[78];
  work1d.v[79] = work1d.KKT[157];
  work1d.d[79] = work1d.v[79];
  if (work1d.d[79] < 0)
    work1d.d[79] = settings1d.kkt_reg;
  else
    work1d.d[79] += settings1d.kkt_reg;
  work1d.d_inv[79] = 1/work1d.d[79];
  work1d.L[264] = (work1d.KKT[158])*work1d.d_inv[79];
  work1d.v[80] = work1d.KKT[159];
  work1d.d[80] = work1d.v[80];
  if (work1d.d[80] < 0)
    work1d.d[80] = settings1d.kkt_reg;
  else
    work1d.d[80] += settings1d.kkt_reg;
  work1d.d_inv[80] = 1/work1d.d[80];
  work1d.L[266] = (work1d.KKT[160])*work1d.d_inv[80];
  work1d.v[81] = work1d.KKT[161];
  work1d.d[81] = work1d.v[81];
  if (work1d.d[81] < 0)
    work1d.d[81] = settings1d.kkt_reg;
  else
    work1d.d[81] += settings1d.kkt_reg;
  work1d.d_inv[81] = 1/work1d.d[81];
  work1d.L[268] = (work1d.KKT[162])*work1d.d_inv[81];
  work1d.v[82] = work1d.KKT[163];
  work1d.d[82] = work1d.v[82];
  if (work1d.d[82] < 0)
    work1d.d[82] = settings1d.kkt_reg;
  else
    work1d.d[82] += settings1d.kkt_reg;
  work1d.d_inv[82] = 1/work1d.d[82];
  work1d.L[271] = (work1d.KKT[164])*work1d.d_inv[82];
  work1d.v[83] = work1d.KKT[165];
  work1d.d[83] = work1d.v[83];
  if (work1d.d[83] < 0)
    work1d.d[83] = settings1d.kkt_reg;
  else
    work1d.d[83] += settings1d.kkt_reg;
  work1d.d_inv[83] = 1/work1d.d[83];
  work1d.L[273] = (work1d.KKT[166])*work1d.d_inv[83];
  work1d.v[84] = work1d.KKT[167];
  work1d.d[84] = work1d.v[84];
  if (work1d.d[84] < 0)
    work1d.d[84] = settings1d.kkt_reg;
  else
    work1d.d[84] += settings1d.kkt_reg;
  work1d.d_inv[84] = 1/work1d.d[84];
  work1d.L[275] = (work1d.KKT[168])*work1d.d_inv[84];
  work1d.v[85] = work1d.KKT[169];
  work1d.d[85] = work1d.v[85];
  if (work1d.d[85] < 0)
    work1d.d[85] = settings1d.kkt_reg;
  else
    work1d.d[85] += settings1d.kkt_reg;
  work1d.d_inv[85] = 1/work1d.d[85];
  work1d.L[278] = (work1d.KKT[170])*work1d.d_inv[85];
  work1d.v[86] = work1d.KKT[171];
  work1d.d[86] = work1d.v[86];
  if (work1d.d[86] < 0)
    work1d.d[86] = settings1d.kkt_reg;
  else
    work1d.d[86] += settings1d.kkt_reg;
  work1d.d_inv[86] = 1/work1d.d[86];
  work1d.L[280] = (work1d.KKT[172])*work1d.d_inv[86];
  work1d.v[87] = work1d.KKT[173];
  work1d.d[87] = work1d.v[87];
  if (work1d.d[87] < 0)
    work1d.d[87] = settings1d.kkt_reg;
  else
    work1d.d[87] += settings1d.kkt_reg;
  work1d.d_inv[87] = 1/work1d.d[87];
  work1d.L[282] = (work1d.KKT[174])*work1d.d_inv[87];
  work1d.v[88] = work1d.KKT[175];
  work1d.d[88] = work1d.v[88];
  if (work1d.d[88] < 0)
    work1d.d[88] = settings1d.kkt_reg;
  else
    work1d.d[88] += settings1d.kkt_reg;
  work1d.d_inv[88] = 1/work1d.d[88];
  work1d.L[285] = (work1d.KKT[176])*work1d.d_inv[88];
  work1d.v[89] = work1d.KKT[177];
  work1d.d[89] = work1d.v[89];
  if (work1d.d[89] < 0)
    work1d.d[89] = settings1d.kkt_reg;
  else
    work1d.d[89] += settings1d.kkt_reg;
  work1d.d_inv[89] = 1/work1d.d[89];
  work1d.L[287] = (work1d.KKT[178])*work1d.d_inv[89];
  work1d.v[90] = work1d.KKT[179];
  work1d.d[90] = work1d.v[90];
  if (work1d.d[90] < 0)
    work1d.d[90] = settings1d.kkt_reg;
  else
    work1d.d[90] += settings1d.kkt_reg;
  work1d.d_inv[90] = 1/work1d.d[90];
  work1d.L[289] = (work1d.KKT[180])*work1d.d_inv[90];
  work1d.v[91] = work1d.KKT[181];
  work1d.d[91] = work1d.v[91];
  if (work1d.d[91] < 0)
    work1d.d[91] = settings1d.kkt_reg;
  else
    work1d.d[91] += settings1d.kkt_reg;
  work1d.d_inv[91] = 1/work1d.d[91];
  work1d.L[292] = (work1d.KKT[182])*work1d.d_inv[91];
  work1d.v[92] = work1d.KKT[183];
  work1d.d[92] = work1d.v[92];
  if (work1d.d[92] < 0)
    work1d.d[92] = settings1d.kkt_reg;
  else
    work1d.d[92] += settings1d.kkt_reg;
  work1d.d_inv[92] = 1/work1d.d[92];
  work1d.L[294] = (work1d.KKT[184])*work1d.d_inv[92];
  work1d.v[93] = work1d.KKT[185];
  work1d.d[93] = work1d.v[93];
  if (work1d.d[93] < 0)
    work1d.d[93] = settings1d.kkt_reg;
  else
    work1d.d[93] += settings1d.kkt_reg;
  work1d.d_inv[93] = 1/work1d.d[93];
  work1d.L[296] = (work1d.KKT[186])*work1d.d_inv[93];
  work1d.v[94] = work1d.KKT[187];
  work1d.d[94] = work1d.v[94];
  if (work1d.d[94] < 0)
    work1d.d[94] = settings1d.kkt_reg;
  else
    work1d.d[94] += settings1d.kkt_reg;
  work1d.d_inv[94] = 1/work1d.d[94];
  work1d.L[299] = (work1d.KKT[188])*work1d.d_inv[94];
  work1d.v[95] = work1d.KKT[189];
  work1d.d[95] = work1d.v[95];
  if (work1d.d[95] < 0)
    work1d.d[95] = settings1d.kkt_reg;
  else
    work1d.d[95] += settings1d.kkt_reg;
  work1d.d_inv[95] = 1/work1d.d[95];
  work1d.L[301] = (work1d.KKT[190])*work1d.d_inv[95];
  work1d.v[96] = work1d.KKT[191];
  work1d.d[96] = work1d.v[96];
  if (work1d.d[96] < 0)
    work1d.d[96] = settings1d.kkt_reg;
  else
    work1d.d[96] += settings1d.kkt_reg;
  work1d.d_inv[96] = 1/work1d.d[96];
  work1d.L[303] = (work1d.KKT[192])*work1d.d_inv[96];
  work1d.v[97] = work1d.KKT[193];
  work1d.d[97] = work1d.v[97];
  if (work1d.d[97] < 0)
    work1d.d[97] = settings1d.kkt_reg;
  else
    work1d.d[97] += settings1d.kkt_reg;
  work1d.d_inv[97] = 1/work1d.d[97];
  work1d.L[306] = (work1d.KKT[194])*work1d.d_inv[97];
  work1d.v[98] = work1d.KKT[195];
  work1d.d[98] = work1d.v[98];
  if (work1d.d[98] < 0)
    work1d.d[98] = settings1d.kkt_reg;
  else
    work1d.d[98] += settings1d.kkt_reg;
  work1d.d_inv[98] = 1/work1d.d[98];
  work1d.L[308] = (work1d.KKT[196])*work1d.d_inv[98];
  work1d.v[99] = work1d.KKT[197];
  work1d.d[99] = work1d.v[99];
  if (work1d.d[99] < 0)
    work1d.d[99] = settings1d.kkt_reg;
  else
    work1d.d[99] += settings1d.kkt_reg;
  work1d.d_inv[99] = 1/work1d.d[99];
  work1d.L[310] = (work1d.KKT[198])*work1d.d_inv[99];
  work1d.v[100] = work1d.KKT[199];
  work1d.d[100] = work1d.v[100];
  if (work1d.d[100] < 0)
    work1d.d[100] = settings1d.kkt_reg;
  else
    work1d.d[100] += settings1d.kkt_reg;
  work1d.d_inv[100] = 1/work1d.d[100];
  work1d.L[313] = (work1d.KKT[200])*work1d.d_inv[100];
  work1d.v[101] = work1d.KKT[201];
  work1d.d[101] = work1d.v[101];
  if (work1d.d[101] < 0)
    work1d.d[101] = settings1d.kkt_reg;
  else
    work1d.d[101] += settings1d.kkt_reg;
  work1d.d_inv[101] = 1/work1d.d[101];
  work1d.L[315] = (work1d.KKT[202])*work1d.d_inv[101];
  work1d.v[102] = work1d.KKT[203];
  work1d.d[102] = work1d.v[102];
  if (work1d.d[102] < 0)
    work1d.d[102] = settings1d.kkt_reg;
  else
    work1d.d[102] += settings1d.kkt_reg;
  work1d.d_inv[102] = 1/work1d.d[102];
  work1d.L[317] = (work1d.KKT[204])*work1d.d_inv[102];
  work1d.v[103] = work1d.KKT[205];
  work1d.d[103] = work1d.v[103];
  if (work1d.d[103] < 0)
    work1d.d[103] = settings1d.kkt_reg;
  else
    work1d.d[103] += settings1d.kkt_reg;
  work1d.d_inv[103] = 1/work1d.d[103];
  work1d.L[320] = (work1d.KKT[206])*work1d.d_inv[103];
  work1d.v[104] = work1d.KKT[207];
  work1d.d[104] = work1d.v[104];
  if (work1d.d[104] < 0)
    work1d.d[104] = settings1d.kkt_reg;
  else
    work1d.d[104] += settings1d.kkt_reg;
  work1d.d_inv[104] = 1/work1d.d[104];
  work1d.L[322] = (work1d.KKT[208])*work1d.d_inv[104];
  work1d.v[105] = work1d.KKT[209];
  work1d.d[105] = work1d.v[105];
  if (work1d.d[105] < 0)
    work1d.d[105] = settings1d.kkt_reg;
  else
    work1d.d[105] += settings1d.kkt_reg;
  work1d.d_inv[105] = 1/work1d.d[105];
  work1d.L[324] = (work1d.KKT[210])*work1d.d_inv[105];
  work1d.v[106] = work1d.KKT[211];
  work1d.d[106] = work1d.v[106];
  if (work1d.d[106] < 0)
    work1d.d[106] = settings1d.kkt_reg;
  else
    work1d.d[106] += settings1d.kkt_reg;
  work1d.d_inv[106] = 1/work1d.d[106];
  work1d.L[327] = (work1d.KKT[212])*work1d.d_inv[106];
  work1d.v[107] = work1d.KKT[213];
  work1d.d[107] = work1d.v[107];
  if (work1d.d[107] < 0)
    work1d.d[107] = settings1d.kkt_reg;
  else
    work1d.d[107] += settings1d.kkt_reg;
  work1d.d_inv[107] = 1/work1d.d[107];
  work1d.L[329] = (work1d.KKT[214])*work1d.d_inv[107];
  work1d.v[108] = work1d.KKT[215];
  work1d.d[108] = work1d.v[108];
  if (work1d.d[108] < 0)
    work1d.d[108] = settings1d.kkt_reg;
  else
    work1d.d[108] += settings1d.kkt_reg;
  work1d.d_inv[108] = 1/work1d.d[108];
  work1d.L[331] = (work1d.KKT[216])*work1d.d_inv[108];
  work1d.v[109] = work1d.KKT[217];
  work1d.d[109] = work1d.v[109];
  if (work1d.d[109] < 0)
    work1d.d[109] = settings1d.kkt_reg;
  else
    work1d.d[109] += settings1d.kkt_reg;
  work1d.d_inv[109] = 1/work1d.d[109];
  work1d.L[334] = (work1d.KKT[218])*work1d.d_inv[109];
  work1d.v[110] = work1d.KKT[219];
  work1d.d[110] = work1d.v[110];
  if (work1d.d[110] < 0)
    work1d.d[110] = settings1d.kkt_reg;
  else
    work1d.d[110] += settings1d.kkt_reg;
  work1d.d_inv[110] = 1/work1d.d[110];
  work1d.L[336] = (work1d.KKT[220])*work1d.d_inv[110];
  work1d.v[111] = work1d.KKT[221];
  work1d.d[111] = work1d.v[111];
  if (work1d.d[111] < 0)
    work1d.d[111] = settings1d.kkt_reg;
  else
    work1d.d[111] += settings1d.kkt_reg;
  work1d.d_inv[111] = 1/work1d.d[111];
  work1d.L[338] = (work1d.KKT[222])*work1d.d_inv[111];
  work1d.v[112] = work1d.KKT[223];
  work1d.d[112] = work1d.v[112];
  if (work1d.d[112] < 0)
    work1d.d[112] = settings1d.kkt_reg;
  else
    work1d.d[112] += settings1d.kkt_reg;
  work1d.d_inv[112] = 1/work1d.d[112];
  work1d.L[341] = (work1d.KKT[224])*work1d.d_inv[112];
  work1d.v[113] = work1d.KKT[225];
  work1d.d[113] = work1d.v[113];
  if (work1d.d[113] < 0)
    work1d.d[113] = settings1d.kkt_reg;
  else
    work1d.d[113] += settings1d.kkt_reg;
  work1d.d_inv[113] = 1/work1d.d[113];
  work1d.L[343] = (work1d.KKT[226])*work1d.d_inv[113];
  work1d.v[114] = work1d.KKT[227];
  work1d.d[114] = work1d.v[114];
  if (work1d.d[114] < 0)
    work1d.d[114] = settings1d.kkt_reg;
  else
    work1d.d[114] += settings1d.kkt_reg;
  work1d.d_inv[114] = 1/work1d.d[114];
  work1d.L[345] = (work1d.KKT[228])*work1d.d_inv[114];
  work1d.v[115] = work1d.KKT[229];
  work1d.d[115] = work1d.v[115];
  if (work1d.d[115] < 0)
    work1d.d[115] = settings1d.kkt_reg;
  else
    work1d.d[115] += settings1d.kkt_reg;
  work1d.d_inv[115] = 1/work1d.d[115];
  work1d.L[348] = (work1d.KKT[230])*work1d.d_inv[115];
  work1d.v[116] = work1d.KKT[231];
  work1d.d[116] = work1d.v[116];
  if (work1d.d[116] < 0)
    work1d.d[116] = settings1d.kkt_reg;
  else
    work1d.d[116] += settings1d.kkt_reg;
  work1d.d_inv[116] = 1/work1d.d[116];
  work1d.L[350] = (work1d.KKT[232])*work1d.d_inv[116];
  work1d.v[117] = work1d.KKT[233];
  work1d.d[117] = work1d.v[117];
  if (work1d.d[117] < 0)
    work1d.d[117] = settings1d.kkt_reg;
  else
    work1d.d[117] += settings1d.kkt_reg;
  work1d.d_inv[117] = 1/work1d.d[117];
  work1d.L[352] = (work1d.KKT[234])*work1d.d_inv[117];
  work1d.v[118] = work1d.KKT[235];
  work1d.d[118] = work1d.v[118];
  if (work1d.d[118] < 0)
    work1d.d[118] = settings1d.kkt_reg;
  else
    work1d.d[118] += settings1d.kkt_reg;
  work1d.d_inv[118] = 1/work1d.d[118];
  work1d.L[355] = (work1d.KKT[236])*work1d.d_inv[118];
  work1d.v[119] = work1d.KKT[237];
  work1d.d[119] = work1d.v[119];
  if (work1d.d[119] < 0)
    work1d.d[119] = settings1d.kkt_reg;
  else
    work1d.d[119] += settings1d.kkt_reg;
  work1d.d_inv[119] = 1/work1d.d[119];
  work1d.L[357] = (work1d.KKT[238])*work1d.d_inv[119];
  work1d.v[120] = work1d.KKT[239];
  work1d.d[120] = work1d.v[120];
  if (work1d.d[120] < 0)
    work1d.d[120] = settings1d.kkt_reg;
  else
    work1d.d[120] += settings1d.kkt_reg;
  work1d.d_inv[120] = 1/work1d.d[120];
  work1d.L[359] = (work1d.KKT[240])*work1d.d_inv[120];
  work1d.v[121] = work1d.KKT[241];
  work1d.d[121] = work1d.v[121];
  if (work1d.d[121] < 0)
    work1d.d[121] = settings1d.kkt_reg;
  else
    work1d.d[121] += settings1d.kkt_reg;
  work1d.d_inv[121] = 1/work1d.d[121];
  work1d.L[365] = (work1d.KKT[242])*work1d.d_inv[121];
  work1d.v[122] = work1d.KKT[243];
  work1d.d[122] = work1d.v[122];
  if (work1d.d[122] < 0)
    work1d.d[122] = settings1d.kkt_reg;
  else
    work1d.d[122] += settings1d.kkt_reg;
  work1d.d_inv[122] = 1/work1d.d[122];
  work1d.L[367] = (work1d.KKT[244])*work1d.d_inv[122];
  work1d.v[123] = work1d.KKT[245];
  work1d.d[123] = work1d.v[123];
  if (work1d.d[123] < 0)
    work1d.d[123] = settings1d.kkt_reg;
  else
    work1d.d[123] += settings1d.kkt_reg;
  work1d.d_inv[123] = 1/work1d.d[123];
  work1d.L[369] = (work1d.KKT[246])*work1d.d_inv[123];
  work1d.v[124] = work1d.KKT[247];
  work1d.d[124] = work1d.v[124];
  if (work1d.d[124] < 0)
    work1d.d[124] = settings1d.kkt_reg;
  else
    work1d.d[124] += settings1d.kkt_reg;
  work1d.d_inv[124] = 1/work1d.d[124];
  work1d.L[372] = (work1d.KKT[248])*work1d.d_inv[124];
  work1d.v[125] = work1d.KKT[249];
  work1d.d[125] = work1d.v[125];
  if (work1d.d[125] < 0)
    work1d.d[125] = settings1d.kkt_reg;
  else
    work1d.d[125] += settings1d.kkt_reg;
  work1d.d_inv[125] = 1/work1d.d[125];
  work1d.L[374] = (work1d.KKT[250])*work1d.d_inv[125];
  work1d.v[126] = work1d.KKT[251];
  work1d.d[126] = work1d.v[126];
  if (work1d.d[126] < 0)
    work1d.d[126] = settings1d.kkt_reg;
  else
    work1d.d[126] += settings1d.kkt_reg;
  work1d.d_inv[126] = 1/work1d.d[126];
  work1d.L[376] = (work1d.KKT[252])*work1d.d_inv[126];
  work1d.v[127] = work1d.KKT[253];
  work1d.d[127] = work1d.v[127];
  if (work1d.d[127] < 0)
    work1d.d[127] = settings1d.kkt_reg;
  else
    work1d.d[127] += settings1d.kkt_reg;
  work1d.d_inv[127] = 1/work1d.d[127];
  work1d.L[379] = (work1d.KKT[254])*work1d.d_inv[127];
  work1d.v[128] = work1d.KKT[255];
  work1d.d[128] = work1d.v[128];
  if (work1d.d[128] < 0)
    work1d.d[128] = settings1d.kkt_reg;
  else
    work1d.d[128] += settings1d.kkt_reg;
  work1d.d_inv[128] = 1/work1d.d[128];
  work1d.L[381] = (work1d.KKT[256])*work1d.d_inv[128];
  work1d.v[129] = work1d.KKT[257];
  work1d.d[129] = work1d.v[129];
  if (work1d.d[129] < 0)
    work1d.d[129] = settings1d.kkt_reg;
  else
    work1d.d[129] += settings1d.kkt_reg;
  work1d.d_inv[129] = 1/work1d.d[129];
  work1d.L[383] = (work1d.KKT[258])*work1d.d_inv[129];
  work1d.v[130] = work1d.KKT[259];
  work1d.d[130] = work1d.v[130];
  if (work1d.d[130] < 0)
    work1d.d[130] = settings1d.kkt_reg;
  else
    work1d.d[130] += settings1d.kkt_reg;
  work1d.d_inv[130] = 1/work1d.d[130];
  work1d.L[386] = (work1d.KKT[260])*work1d.d_inv[130];
  work1d.v[131] = work1d.KKT[261];
  work1d.d[131] = work1d.v[131];
  if (work1d.d[131] < 0)
    work1d.d[131] = settings1d.kkt_reg;
  else
    work1d.d[131] += settings1d.kkt_reg;
  work1d.d_inv[131] = 1/work1d.d[131];
  work1d.L[388] = (work1d.KKT[262])*work1d.d_inv[131];
  work1d.v[132] = work1d.KKT[263];
  work1d.d[132] = work1d.v[132];
  if (work1d.d[132] < 0)
    work1d.d[132] = settings1d.kkt_reg;
  else
    work1d.d[132] += settings1d.kkt_reg;
  work1d.d_inv[132] = 1/work1d.d[132];
  work1d.L[390] = (work1d.KKT[264])*work1d.d_inv[132];
  work1d.v[133] = work1d.KKT[265];
  work1d.d[133] = work1d.v[133];
  if (work1d.d[133] < 0)
    work1d.d[133] = settings1d.kkt_reg;
  else
    work1d.d[133] += settings1d.kkt_reg;
  work1d.d_inv[133] = 1/work1d.d[133];
  work1d.L[393] = (work1d.KKT[266])*work1d.d_inv[133];
  work1d.v[134] = work1d.KKT[267];
  work1d.d[134] = work1d.v[134];
  if (work1d.d[134] < 0)
    work1d.d[134] = settings1d.kkt_reg;
  else
    work1d.d[134] += settings1d.kkt_reg;
  work1d.d_inv[134] = 1/work1d.d[134];
  work1d.L[395] = (work1d.KKT[268])*work1d.d_inv[134];
  work1d.v[135] = work1d.KKT[269];
  work1d.d[135] = work1d.v[135];
  if (work1d.d[135] < 0)
    work1d.d[135] = settings1d.kkt_reg;
  else
    work1d.d[135] += settings1d.kkt_reg;
  work1d.d_inv[135] = 1/work1d.d[135];
  work1d.L[397] = (work1d.KKT[270])*work1d.d_inv[135];
  work1d.v[136] = work1d.KKT[271];
  work1d.d[136] = work1d.v[136];
  if (work1d.d[136] < 0)
    work1d.d[136] = settings1d.kkt_reg;
  else
    work1d.d[136] += settings1d.kkt_reg;
  work1d.d_inv[136] = 1/work1d.d[136];
  work1d.L[400] = (work1d.KKT[272])*work1d.d_inv[136];
  work1d.v[137] = work1d.KKT[273];
  work1d.d[137] = work1d.v[137];
  if (work1d.d[137] < 0)
    work1d.d[137] = settings1d.kkt_reg;
  else
    work1d.d[137] += settings1d.kkt_reg;
  work1d.d_inv[137] = 1/work1d.d[137];
  work1d.L[402] = (work1d.KKT[274])*work1d.d_inv[137];
  work1d.v[138] = work1d.KKT[275];
  work1d.d[138] = work1d.v[138];
  if (work1d.d[138] < 0)
    work1d.d[138] = settings1d.kkt_reg;
  else
    work1d.d[138] += settings1d.kkt_reg;
  work1d.d_inv[138] = 1/work1d.d[138];
  work1d.L[404] = (work1d.KKT[276])*work1d.d_inv[138];
  work1d.v[139] = work1d.KKT[277];
  work1d.d[139] = work1d.v[139];
  if (work1d.d[139] < 0)
    work1d.d[139] = settings1d.kkt_reg;
  else
    work1d.d[139] += settings1d.kkt_reg;
  work1d.d_inv[139] = 1/work1d.d[139];
  work1d.L[407] = (work1d.KKT[278])*work1d.d_inv[139];
  work1d.v[140] = work1d.KKT[279];
  work1d.d[140] = work1d.v[140];
  if (work1d.d[140] < 0)
    work1d.d[140] = settings1d.kkt_reg;
  else
    work1d.d[140] += settings1d.kkt_reg;
  work1d.d_inv[140] = 1/work1d.d[140];
  work1d.L[409] = (work1d.KKT[280])*work1d.d_inv[140];
  work1d.v[141] = work1d.KKT[281];
  work1d.d[141] = work1d.v[141];
  if (work1d.d[141] < 0)
    work1d.d[141] = settings1d.kkt_reg;
  else
    work1d.d[141] += settings1d.kkt_reg;
  work1d.d_inv[141] = 1/work1d.d[141];
  work1d.L[411] = (work1d.KKT[282])*work1d.d_inv[141];
  work1d.v[142] = work1d.KKT[283];
  work1d.d[142] = work1d.v[142];
  if (work1d.d[142] < 0)
    work1d.d[142] = settings1d.kkt_reg;
  else
    work1d.d[142] += settings1d.kkt_reg;
  work1d.d_inv[142] = 1/work1d.d[142];
  work1d.L[414] = (work1d.KKT[284])*work1d.d_inv[142];
  work1d.v[143] = work1d.KKT[285];
  work1d.d[143] = work1d.v[143];
  if (work1d.d[143] < 0)
    work1d.d[143] = settings1d.kkt_reg;
  else
    work1d.d[143] += settings1d.kkt_reg;
  work1d.d_inv[143] = 1/work1d.d[143];
  work1d.L[416] = (work1d.KKT[286])*work1d.d_inv[143];
  work1d.v[144] = work1d.KKT[287];
  work1d.d[144] = work1d.v[144];
  if (work1d.d[144] < 0)
    work1d.d[144] = settings1d.kkt_reg;
  else
    work1d.d[144] += settings1d.kkt_reg;
  work1d.d_inv[144] = 1/work1d.d[144];
  work1d.L[418] = (work1d.KKT[288])*work1d.d_inv[144];
  work1d.v[145] = work1d.KKT[289];
  work1d.d[145] = work1d.v[145];
  if (work1d.d[145] < 0)
    work1d.d[145] = settings1d.kkt_reg;
  else
    work1d.d[145] += settings1d.kkt_reg;
  work1d.d_inv[145] = 1/work1d.d[145];
  work1d.L[421] = (work1d.KKT[290])*work1d.d_inv[145];
  work1d.v[146] = work1d.KKT[291];
  work1d.d[146] = work1d.v[146];
  if (work1d.d[146] < 0)
    work1d.d[146] = settings1d.kkt_reg;
  else
    work1d.d[146] += settings1d.kkt_reg;
  work1d.d_inv[146] = 1/work1d.d[146];
  work1d.L[423] = (work1d.KKT[292])*work1d.d_inv[146];
  work1d.v[147] = work1d.KKT[293];
  work1d.d[147] = work1d.v[147];
  if (work1d.d[147] < 0)
    work1d.d[147] = settings1d.kkt_reg;
  else
    work1d.d[147] += settings1d.kkt_reg;
  work1d.d_inv[147] = 1/work1d.d[147];
  work1d.L[425] = (work1d.KKT[294])*work1d.d_inv[147];
  work1d.v[148] = work1d.KKT[295];
  work1d.d[148] = work1d.v[148];
  if (work1d.d[148] < 0)
    work1d.d[148] = settings1d.kkt_reg;
  else
    work1d.d[148] += settings1d.kkt_reg;
  work1d.d_inv[148] = 1/work1d.d[148];
  work1d.L[428] = (work1d.KKT[296])*work1d.d_inv[148];
  work1d.v[149] = work1d.KKT[297];
  work1d.d[149] = work1d.v[149];
  if (work1d.d[149] < 0)
    work1d.d[149] = settings1d.kkt_reg;
  else
    work1d.d[149] += settings1d.kkt_reg;
  work1d.d_inv[149] = 1/work1d.d[149];
  work1d.L[430] = (work1d.KKT[298])*work1d.d_inv[149];
  work1d.v[150] = work1d.KKT[299];
  work1d.d[150] = work1d.v[150];
  if (work1d.d[150] < 0)
    work1d.d[150] = settings1d.kkt_reg;
  else
    work1d.d[150] += settings1d.kkt_reg;
  work1d.d_inv[150] = 1/work1d.d[150];
  work1d.L[432] = (work1d.KKT[300])*work1d.d_inv[150];
  work1d.v[151] = work1d.KKT[301];
  work1d.d[151] = work1d.v[151];
  if (work1d.d[151] < 0)
    work1d.d[151] = settings1d.kkt_reg;
  else
    work1d.d[151] += settings1d.kkt_reg;
  work1d.d_inv[151] = 1/work1d.d[151];
  work1d.L[435] = (work1d.KKT[302])*work1d.d_inv[151];
  work1d.v[152] = work1d.KKT[303];
  work1d.d[152] = work1d.v[152];
  if (work1d.d[152] < 0)
    work1d.d[152] = settings1d.kkt_reg;
  else
    work1d.d[152] += settings1d.kkt_reg;
  work1d.d_inv[152] = 1/work1d.d[152];
  work1d.L[437] = (work1d.KKT[304])*work1d.d_inv[152];
  work1d.v[153] = work1d.KKT[305];
  work1d.d[153] = work1d.v[153];
  if (work1d.d[153] < 0)
    work1d.d[153] = settings1d.kkt_reg;
  else
    work1d.d[153] += settings1d.kkt_reg;
  work1d.d_inv[153] = 1/work1d.d[153];
  work1d.L[439] = (work1d.KKT[306])*work1d.d_inv[153];
  work1d.v[154] = work1d.KKT[307];
  work1d.d[154] = work1d.v[154];
  if (work1d.d[154] < 0)
    work1d.d[154] = settings1d.kkt_reg;
  else
    work1d.d[154] += settings1d.kkt_reg;
  work1d.d_inv[154] = 1/work1d.d[154];
  work1d.L[442] = (work1d.KKT[308])*work1d.d_inv[154];
  work1d.v[155] = work1d.KKT[309];
  work1d.d[155] = work1d.v[155];
  if (work1d.d[155] < 0)
    work1d.d[155] = settings1d.kkt_reg;
  else
    work1d.d[155] += settings1d.kkt_reg;
  work1d.d_inv[155] = 1/work1d.d[155];
  work1d.L[444] = (work1d.KKT[310])*work1d.d_inv[155];
  work1d.v[156] = work1d.KKT[311];
  work1d.d[156] = work1d.v[156];
  if (work1d.d[156] < 0)
    work1d.d[156] = settings1d.kkt_reg;
  else
    work1d.d[156] += settings1d.kkt_reg;
  work1d.d_inv[156] = 1/work1d.d[156];
  work1d.L[446] = (work1d.KKT[312])*work1d.d_inv[156];
  work1d.v[157] = work1d.KKT[313];
  work1d.d[157] = work1d.v[157];
  if (work1d.d[157] < 0)
    work1d.d[157] = settings1d.kkt_reg;
  else
    work1d.d[157] += settings1d.kkt_reg;
  work1d.d_inv[157] = 1/work1d.d[157];
  work1d.L[449] = (work1d.KKT[314])*work1d.d_inv[157];
  work1d.v[158] = work1d.KKT[315];
  work1d.d[158] = work1d.v[158];
  if (work1d.d[158] < 0)
    work1d.d[158] = settings1d.kkt_reg;
  else
    work1d.d[158] += settings1d.kkt_reg;
  work1d.d_inv[158] = 1/work1d.d[158];
  work1d.L[451] = (work1d.KKT[316])*work1d.d_inv[158];
  work1d.v[159] = work1d.KKT[317];
  work1d.d[159] = work1d.v[159];
  if (work1d.d[159] < 0)
    work1d.d[159] = settings1d.kkt_reg;
  else
    work1d.d[159] += settings1d.kkt_reg;
  work1d.d_inv[159] = 1/work1d.d[159];
  work1d.L[453] = (work1d.KKT[318])*work1d.d_inv[159];
  work1d.v[160] = work1d.KKT[319];
  work1d.d[160] = work1d.v[160];
  if (work1d.d[160] < 0)
    work1d.d[160] = settings1d.kkt_reg;
  else
    work1d.d[160] += settings1d.kkt_reg;
  work1d.d_inv[160] = 1/work1d.d[160];
  work1d.L[456] = (work1d.KKT[320])*work1d.d_inv[160];
  work1d.v[161] = work1d.KKT[321];
  work1d.d[161] = work1d.v[161];
  if (work1d.d[161] < 0)
    work1d.d[161] = settings1d.kkt_reg;
  else
    work1d.d[161] += settings1d.kkt_reg;
  work1d.d_inv[161] = 1/work1d.d[161];
  work1d.L[458] = (work1d.KKT[322])*work1d.d_inv[161];
  work1d.v[162] = work1d.KKT[323];
  work1d.d[162] = work1d.v[162];
  if (work1d.d[162] < 0)
    work1d.d[162] = settings1d.kkt_reg;
  else
    work1d.d[162] += settings1d.kkt_reg;
  work1d.d_inv[162] = 1/work1d.d[162];
  work1d.L[460] = (work1d.KKT[324])*work1d.d_inv[162];
  work1d.v[163] = work1d.KKT[325];
  work1d.d[163] = work1d.v[163];
  if (work1d.d[163] < 0)
    work1d.d[163] = settings1d.kkt_reg;
  else
    work1d.d[163] += settings1d.kkt_reg;
  work1d.d_inv[163] = 1/work1d.d[163];
  work1d.L[463] = (work1d.KKT[326])*work1d.d_inv[163];
  work1d.v[164] = work1d.KKT[327];
  work1d.d[164] = work1d.v[164];
  if (work1d.d[164] < 0)
    work1d.d[164] = settings1d.kkt_reg;
  else
    work1d.d[164] += settings1d.kkt_reg;
  work1d.d_inv[164] = 1/work1d.d[164];
  work1d.L[465] = (work1d.KKT[328])*work1d.d_inv[164];
  work1d.v[165] = work1d.KKT[329];
  work1d.d[165] = work1d.v[165];
  if (work1d.d[165] < 0)
    work1d.d[165] = settings1d.kkt_reg;
  else
    work1d.d[165] += settings1d.kkt_reg;
  work1d.d_inv[165] = 1/work1d.d[165];
  work1d.L[467] = (work1d.KKT[330])*work1d.d_inv[165];
  work1d.v[166] = work1d.KKT[331];
  work1d.d[166] = work1d.v[166];
  if (work1d.d[166] < 0)
    work1d.d[166] = settings1d.kkt_reg;
  else
    work1d.d[166] += settings1d.kkt_reg;
  work1d.d_inv[166] = 1/work1d.d[166];
  work1d.L[470] = (work1d.KKT[332])*work1d.d_inv[166];
  work1d.v[167] = work1d.KKT[333];
  work1d.d[167] = work1d.v[167];
  if (work1d.d[167] < 0)
    work1d.d[167] = settings1d.kkt_reg;
  else
    work1d.d[167] += settings1d.kkt_reg;
  work1d.d_inv[167] = 1/work1d.d[167];
  work1d.L[472] = (work1d.KKT[334])*work1d.d_inv[167];
  work1d.v[168] = work1d.KKT[335];
  work1d.d[168] = work1d.v[168];
  if (work1d.d[168] < 0)
    work1d.d[168] = settings1d.kkt_reg;
  else
    work1d.d[168] += settings1d.kkt_reg;
  work1d.d_inv[168] = 1/work1d.d[168];
  work1d.L[474] = (work1d.KKT[336])*work1d.d_inv[168];
  work1d.v[169] = work1d.KKT[337];
  work1d.d[169] = work1d.v[169];
  if (work1d.d[169] < 0)
    work1d.d[169] = settings1d.kkt_reg;
  else
    work1d.d[169] += settings1d.kkt_reg;
  work1d.d_inv[169] = 1/work1d.d[169];
  work1d.L[477] = (work1d.KKT[338])*work1d.d_inv[169];
  work1d.v[170] = work1d.KKT[339];
  work1d.d[170] = work1d.v[170];
  if (work1d.d[170] < 0)
    work1d.d[170] = settings1d.kkt_reg;
  else
    work1d.d[170] += settings1d.kkt_reg;
  work1d.d_inv[170] = 1/work1d.d[170];
  work1d.L[479] = (work1d.KKT[340])*work1d.d_inv[170];
  work1d.v[171] = work1d.KKT[341];
  work1d.d[171] = work1d.v[171];
  if (work1d.d[171] < 0)
    work1d.d[171] = settings1d.kkt_reg;
  else
    work1d.d[171] += settings1d.kkt_reg;
  work1d.d_inv[171] = 1/work1d.d[171];
  work1d.L[481] = (work1d.KKT[342])*work1d.d_inv[171];
  work1d.v[172] = work1d.KKT[343];
  work1d.d[172] = work1d.v[172];
  if (work1d.d[172] < 0)
    work1d.d[172] = settings1d.kkt_reg;
  else
    work1d.d[172] += settings1d.kkt_reg;
  work1d.d_inv[172] = 1/work1d.d[172];
  work1d.L[484] = (work1d.KKT[344])*work1d.d_inv[172];
  work1d.v[173] = work1d.KKT[345];
  work1d.d[173] = work1d.v[173];
  if (work1d.d[173] < 0)
    work1d.d[173] = settings1d.kkt_reg;
  else
    work1d.d[173] += settings1d.kkt_reg;
  work1d.d_inv[173] = 1/work1d.d[173];
  work1d.L[486] = (work1d.KKT[346])*work1d.d_inv[173];
  work1d.v[174] = work1d.KKT[347];
  work1d.d[174] = work1d.v[174];
  if (work1d.d[174] < 0)
    work1d.d[174] = settings1d.kkt_reg;
  else
    work1d.d[174] += settings1d.kkt_reg;
  work1d.d_inv[174] = 1/work1d.d[174];
  work1d.L[488] = (work1d.KKT[348])*work1d.d_inv[174];
  work1d.v[175] = work1d.KKT[349];
  work1d.d[175] = work1d.v[175];
  if (work1d.d[175] < 0)
    work1d.d[175] = settings1d.kkt_reg;
  else
    work1d.d[175] += settings1d.kkt_reg;
  work1d.d_inv[175] = 1/work1d.d[175];
  work1d.L[491] = (work1d.KKT[350])*work1d.d_inv[175];
  work1d.v[176] = work1d.KKT[351];
  work1d.d[176] = work1d.v[176];
  if (work1d.d[176] < 0)
    work1d.d[176] = settings1d.kkt_reg;
  else
    work1d.d[176] += settings1d.kkt_reg;
  work1d.d_inv[176] = 1/work1d.d[176];
  work1d.L[493] = (work1d.KKT[352])*work1d.d_inv[176];
  work1d.v[177] = work1d.KKT[353];
  work1d.d[177] = work1d.v[177];
  if (work1d.d[177] < 0)
    work1d.d[177] = settings1d.kkt_reg;
  else
    work1d.d[177] += settings1d.kkt_reg;
  work1d.d_inv[177] = 1/work1d.d[177];
  work1d.L[495] = (work1d.KKT[354])*work1d.d_inv[177];
  work1d.v[178] = work1d.KKT[355];
  work1d.d[178] = work1d.v[178];
  if (work1d.d[178] < 0)
    work1d.d[178] = settings1d.kkt_reg;
  else
    work1d.d[178] += settings1d.kkt_reg;
  work1d.d_inv[178] = 1/work1d.d[178];
  work1d.L[498] = (work1d.KKT[356])*work1d.d_inv[178];
  work1d.v[179] = work1d.KKT[357];
  work1d.d[179] = work1d.v[179];
  if (work1d.d[179] < 0)
    work1d.d[179] = settings1d.kkt_reg;
  else
    work1d.d[179] += settings1d.kkt_reg;
  work1d.d_inv[179] = 1/work1d.d[179];
  work1d.L[500] = (work1d.KKT[358])*work1d.d_inv[179];
  work1d.v[180] = work1d.KKT[359];
  work1d.d[180] = work1d.v[180];
  if (work1d.d[180] < 0)
    work1d.d[180] = settings1d.kkt_reg;
  else
    work1d.d[180] += settings1d.kkt_reg;
  work1d.d_inv[180] = 1/work1d.d[180];
  work1d.L[502] = (work1d.KKT[360])*work1d.d_inv[180];
  work1d.v[181] = work1d.KKT[361];
  work1d.d[181] = work1d.v[181];
  if (work1d.d[181] < 0)
    work1d.d[181] = settings1d.kkt_reg;
  else
    work1d.d[181] += settings1d.kkt_reg;
  work1d.d_inv[181] = 1/work1d.d[181];
  work1d.L[505] = (work1d.KKT[362])*work1d.d_inv[181];
  work1d.v[182] = work1d.KKT[363];
  work1d.d[182] = work1d.v[182];
  if (work1d.d[182] < 0)
    work1d.d[182] = settings1d.kkt_reg;
  else
    work1d.d[182] += settings1d.kkt_reg;
  work1d.d_inv[182] = 1/work1d.d[182];
  work1d.L[507] = (work1d.KKT[364])*work1d.d_inv[182];
  work1d.v[183] = work1d.KKT[365];
  work1d.d[183] = work1d.v[183];
  if (work1d.d[183] < 0)
    work1d.d[183] = settings1d.kkt_reg;
  else
    work1d.d[183] += settings1d.kkt_reg;
  work1d.d_inv[183] = 1/work1d.d[183];
  work1d.L[509] = (work1d.KKT[366])*work1d.d_inv[183];
  work1d.v[184] = work1d.KKT[367];
  work1d.d[184] = work1d.v[184];
  if (work1d.d[184] < 0)
    work1d.d[184] = settings1d.kkt_reg;
  else
    work1d.d[184] += settings1d.kkt_reg;
  work1d.d_inv[184] = 1/work1d.d[184];
  work1d.L[512] = (work1d.KKT[368])*work1d.d_inv[184];
  work1d.v[185] = work1d.KKT[369];
  work1d.d[185] = work1d.v[185];
  if (work1d.d[185] < 0)
    work1d.d[185] = settings1d.kkt_reg;
  else
    work1d.d[185] += settings1d.kkt_reg;
  work1d.d_inv[185] = 1/work1d.d[185];
  work1d.L[514] = (work1d.KKT[370])*work1d.d_inv[185];
  work1d.v[186] = work1d.KKT[371];
  work1d.d[186] = work1d.v[186];
  if (work1d.d[186] < 0)
    work1d.d[186] = settings1d.kkt_reg;
  else
    work1d.d[186] += settings1d.kkt_reg;
  work1d.d_inv[186] = 1/work1d.d[186];
  work1d.L[516] = (work1d.KKT[372])*work1d.d_inv[186];
  work1d.v[187] = work1d.KKT[373];
  work1d.d[187] = work1d.v[187];
  if (work1d.d[187] < 0)
    work1d.d[187] = settings1d.kkt_reg;
  else
    work1d.d[187] += settings1d.kkt_reg;
  work1d.d_inv[187] = 1/work1d.d[187];
  work1d.L[519] = (work1d.KKT[374])*work1d.d_inv[187];
  work1d.v[188] = work1d.KKT[375];
  work1d.d[188] = work1d.v[188];
  if (work1d.d[188] < 0)
    work1d.d[188] = settings1d.kkt_reg;
  else
    work1d.d[188] += settings1d.kkt_reg;
  work1d.d_inv[188] = 1/work1d.d[188];
  work1d.L[521] = (work1d.KKT[376])*work1d.d_inv[188];
  work1d.v[189] = work1d.KKT[377];
  work1d.d[189] = work1d.v[189];
  if (work1d.d[189] < 0)
    work1d.d[189] = settings1d.kkt_reg;
  else
    work1d.d[189] += settings1d.kkt_reg;
  work1d.d_inv[189] = 1/work1d.d[189];
  work1d.L[523] = (work1d.KKT[378])*work1d.d_inv[189];
  work1d.v[190] = work1d.KKT[379];
  work1d.d[190] = work1d.v[190];
  if (work1d.d[190] < 0)
    work1d.d[190] = settings1d.kkt_reg;
  else
    work1d.d[190] += settings1d.kkt_reg;
  work1d.d_inv[190] = 1/work1d.d[190];
  work1d.L[526] = (work1d.KKT[380])*work1d.d_inv[190];
  work1d.v[191] = work1d.KKT[381];
  work1d.d[191] = work1d.v[191];
  if (work1d.d[191] < 0)
    work1d.d[191] = settings1d.kkt_reg;
  else
    work1d.d[191] += settings1d.kkt_reg;
  work1d.d_inv[191] = 1/work1d.d[191];
  work1d.L[528] = (work1d.KKT[382])*work1d.d_inv[191];
  work1d.v[192] = work1d.KKT[383];
  work1d.d[192] = work1d.v[192];
  if (work1d.d[192] < 0)
    work1d.d[192] = settings1d.kkt_reg;
  else
    work1d.d[192] += settings1d.kkt_reg;
  work1d.d_inv[192] = 1/work1d.d[192];
  work1d.L[530] = (work1d.KKT[384])*work1d.d_inv[192];
  work1d.v[193] = work1d.KKT[385];
  work1d.d[193] = work1d.v[193];
  if (work1d.d[193] < 0)
    work1d.d[193] = settings1d.kkt_reg;
  else
    work1d.d[193] += settings1d.kkt_reg;
  work1d.d_inv[193] = 1/work1d.d[193];
  work1d.L[533] = (work1d.KKT[386])*work1d.d_inv[193];
  work1d.v[194] = work1d.KKT[387];
  work1d.d[194] = work1d.v[194];
  if (work1d.d[194] < 0)
    work1d.d[194] = settings1d.kkt_reg;
  else
    work1d.d[194] += settings1d.kkt_reg;
  work1d.d_inv[194] = 1/work1d.d[194];
  work1d.L[535] = (work1d.KKT[388])*work1d.d_inv[194];
  work1d.v[195] = work1d.KKT[389];
  work1d.d[195] = work1d.v[195];
  if (work1d.d[195] < 0)
    work1d.d[195] = settings1d.kkt_reg;
  else
    work1d.d[195] += settings1d.kkt_reg;
  work1d.d_inv[195] = 1/work1d.d[195];
  work1d.L[537] = (work1d.KKT[390])*work1d.d_inv[195];
  work1d.v[196] = work1d.KKT[391];
  work1d.d[196] = work1d.v[196];
  if (work1d.d[196] < 0)
    work1d.d[196] = settings1d.kkt_reg;
  else
    work1d.d[196] += settings1d.kkt_reg;
  work1d.d_inv[196] = 1/work1d.d[196];
  work1d.L[540] = (work1d.KKT[392])*work1d.d_inv[196];
  work1d.v[197] = work1d.KKT[393];
  work1d.d[197] = work1d.v[197];
  if (work1d.d[197] < 0)
    work1d.d[197] = settings1d.kkt_reg;
  else
    work1d.d[197] += settings1d.kkt_reg;
  work1d.d_inv[197] = 1/work1d.d[197];
  work1d.L[542] = (work1d.KKT[394])*work1d.d_inv[197];
  work1d.v[198] = work1d.KKT[395];
  work1d.d[198] = work1d.v[198];
  if (work1d.d[198] < 0)
    work1d.d[198] = settings1d.kkt_reg;
  else
    work1d.d[198] += settings1d.kkt_reg;
  work1d.d_inv[198] = 1/work1d.d[198];
  work1d.L[544] = (work1d.KKT[396])*work1d.d_inv[198];
  work1d.v[199] = work1d.KKT[397];
  work1d.d[199] = work1d.v[199];
  if (work1d.d[199] < 0)
    work1d.d[199] = settings1d.kkt_reg;
  else
    work1d.d[199] += settings1d.kkt_reg;
  work1d.d_inv[199] = 1/work1d.d[199];
  work1d.L[547] = (work1d.KKT[398])*work1d.d_inv[199];
  work1d.v[200] = work1d.KKT[399];
  work1d.d[200] = work1d.v[200];
  if (work1d.d[200] < 0)
    work1d.d[200] = settings1d.kkt_reg;
  else
    work1d.d[200] += settings1d.kkt_reg;
  work1d.d_inv[200] = 1/work1d.d[200];
  work1d.L[549] = (work1d.KKT[400])*work1d.d_inv[200];
  work1d.v[201] = work1d.KKT[401];
  work1d.d[201] = work1d.v[201];
  if (work1d.d[201] < 0)
    work1d.d[201] = settings1d.kkt_reg;
  else
    work1d.d[201] += settings1d.kkt_reg;
  work1d.d_inv[201] = 1/work1d.d[201];
  work1d.L[551] = (work1d.KKT[402])*work1d.d_inv[201];
  work1d.v[202] = work1d.KKT[403];
  work1d.d[202] = work1d.v[202];
  if (work1d.d[202] < 0)
    work1d.d[202] = settings1d.kkt_reg;
  else
    work1d.d[202] += settings1d.kkt_reg;
  work1d.d_inv[202] = 1/work1d.d[202];
  work1d.L[554] = (work1d.KKT[404])*work1d.d_inv[202];
  work1d.v[203] = work1d.KKT[405];
  work1d.d[203] = work1d.v[203];
  if (work1d.d[203] < 0)
    work1d.d[203] = settings1d.kkt_reg;
  else
    work1d.d[203] += settings1d.kkt_reg;
  work1d.d_inv[203] = 1/work1d.d[203];
  work1d.L[556] = (work1d.KKT[406])*work1d.d_inv[203];
  work1d.v[204] = work1d.KKT[407];
  work1d.d[204] = work1d.v[204];
  if (work1d.d[204] < 0)
    work1d.d[204] = settings1d.kkt_reg;
  else
    work1d.d[204] += settings1d.kkt_reg;
  work1d.d_inv[204] = 1/work1d.d[204];
  work1d.L[558] = (work1d.KKT[408])*work1d.d_inv[204];
  work1d.v[205] = work1d.KKT[409];
  work1d.d[205] = work1d.v[205];
  if (work1d.d[205] < 0)
    work1d.d[205] = settings1d.kkt_reg;
  else
    work1d.d[205] += settings1d.kkt_reg;
  work1d.d_inv[205] = 1/work1d.d[205];
  work1d.L[561] = (work1d.KKT[410])*work1d.d_inv[205];
  work1d.v[206] = work1d.KKT[411];
  work1d.d[206] = work1d.v[206];
  if (work1d.d[206] < 0)
    work1d.d[206] = settings1d.kkt_reg;
  else
    work1d.d[206] += settings1d.kkt_reg;
  work1d.d_inv[206] = 1/work1d.d[206];
  work1d.L[563] = (work1d.KKT[412])*work1d.d_inv[206];
  work1d.v[207] = work1d.KKT[413];
  work1d.d[207] = work1d.v[207];
  if (work1d.d[207] < 0)
    work1d.d[207] = settings1d.kkt_reg;
  else
    work1d.d[207] += settings1d.kkt_reg;
  work1d.d_inv[207] = 1/work1d.d[207];
  work1d.L[565] = (work1d.KKT[414])*work1d.d_inv[207];
  work1d.v[208] = work1d.KKT[415];
  work1d.d[208] = work1d.v[208];
  if (work1d.d[208] < 0)
    work1d.d[208] = settings1d.kkt_reg;
  else
    work1d.d[208] += settings1d.kkt_reg;
  work1d.d_inv[208] = 1/work1d.d[208];
  work1d.L[568] = (work1d.KKT[416])*work1d.d_inv[208];
  work1d.v[209] = work1d.KKT[417];
  work1d.d[209] = work1d.v[209];
  if (work1d.d[209] < 0)
    work1d.d[209] = settings1d.kkt_reg;
  else
    work1d.d[209] += settings1d.kkt_reg;
  work1d.d_inv[209] = 1/work1d.d[209];
  work1d.L[570] = (work1d.KKT[418])*work1d.d_inv[209];
  work1d.v[210] = work1d.KKT[419];
  work1d.d[210] = work1d.v[210];
  if (work1d.d[210] < 0)
    work1d.d[210] = settings1d.kkt_reg;
  else
    work1d.d[210] += settings1d.kkt_reg;
  work1d.d_inv[210] = 1/work1d.d[210];
  work1d.L[572] = (work1d.KKT[420])*work1d.d_inv[210];
  work1d.v[211] = work1d.KKT[421];
  work1d.d[211] = work1d.v[211];
  if (work1d.d[211] < 0)
    work1d.d[211] = settings1d.kkt_reg;
  else
    work1d.d[211] += settings1d.kkt_reg;
  work1d.d_inv[211] = 1/work1d.d[211];
  work1d.L[575] = (work1d.KKT[422])*work1d.d_inv[211];
  work1d.v[212] = work1d.KKT[423];
  work1d.d[212] = work1d.v[212];
  if (work1d.d[212] < 0)
    work1d.d[212] = settings1d.kkt_reg;
  else
    work1d.d[212] += settings1d.kkt_reg;
  work1d.d_inv[212] = 1/work1d.d[212];
  work1d.L[577] = (work1d.KKT[424])*work1d.d_inv[212];
  work1d.v[213] = work1d.KKT[425];
  work1d.d[213] = work1d.v[213];
  if (work1d.d[213] < 0)
    work1d.d[213] = settings1d.kkt_reg;
  else
    work1d.d[213] += settings1d.kkt_reg;
  work1d.d_inv[213] = 1/work1d.d[213];
  work1d.L[579] = (work1d.KKT[426])*work1d.d_inv[213];
  work1d.v[214] = work1d.KKT[427];
  work1d.d[214] = work1d.v[214];
  if (work1d.d[214] < 0)
    work1d.d[214] = settings1d.kkt_reg;
  else
    work1d.d[214] += settings1d.kkt_reg;
  work1d.d_inv[214] = 1/work1d.d[214];
  work1d.L[582] = (work1d.KKT[428])*work1d.d_inv[214];
  work1d.v[215] = work1d.KKT[429];
  work1d.d[215] = work1d.v[215];
  if (work1d.d[215] < 0)
    work1d.d[215] = settings1d.kkt_reg;
  else
    work1d.d[215] += settings1d.kkt_reg;
  work1d.d_inv[215] = 1/work1d.d[215];
  work1d.L[584] = (work1d.KKT[430])*work1d.d_inv[215];
  work1d.v[216] = work1d.KKT[431];
  work1d.d[216] = work1d.v[216];
  if (work1d.d[216] < 0)
    work1d.d[216] = settings1d.kkt_reg;
  else
    work1d.d[216] += settings1d.kkt_reg;
  work1d.d_inv[216] = 1/work1d.d[216];
  work1d.L[586] = (work1d.KKT[432])*work1d.d_inv[216];
  work1d.v[217] = work1d.KKT[433];
  work1d.d[217] = work1d.v[217];
  if (work1d.d[217] < 0)
    work1d.d[217] = settings1d.kkt_reg;
  else
    work1d.d[217] += settings1d.kkt_reg;
  work1d.d_inv[217] = 1/work1d.d[217];
  work1d.L[589] = (work1d.KKT[434])*work1d.d_inv[217];
  work1d.v[218] = work1d.KKT[435];
  work1d.d[218] = work1d.v[218];
  if (work1d.d[218] < 0)
    work1d.d[218] = settings1d.kkt_reg;
  else
    work1d.d[218] += settings1d.kkt_reg;
  work1d.d_inv[218] = 1/work1d.d[218];
  work1d.L[591] = (work1d.KKT[436])*work1d.d_inv[218];
  work1d.v[219] = work1d.KKT[437];
  work1d.d[219] = work1d.v[219];
  if (work1d.d[219] < 0)
    work1d.d[219] = settings1d.kkt_reg;
  else
    work1d.d[219] += settings1d.kkt_reg;
  work1d.d_inv[219] = 1/work1d.d[219];
  work1d.L[593] = (work1d.KKT[438])*work1d.d_inv[219];
  work1d.v[220] = work1d.KKT[439];
  work1d.d[220] = work1d.v[220];
  if (work1d.d[220] < 0)
    work1d.d[220] = settings1d.kkt_reg;
  else
    work1d.d[220] += settings1d.kkt_reg;
  work1d.d_inv[220] = 1/work1d.d[220];
  work1d.L[596] = (work1d.KKT[440])*work1d.d_inv[220];
  work1d.v[221] = work1d.KKT[441];
  work1d.d[221] = work1d.v[221];
  if (work1d.d[221] < 0)
    work1d.d[221] = settings1d.kkt_reg;
  else
    work1d.d[221] += settings1d.kkt_reg;
  work1d.d_inv[221] = 1/work1d.d[221];
  work1d.L[598] = (work1d.KKT[442])*work1d.d_inv[221];
  work1d.v[222] = work1d.KKT[443];
  work1d.d[222] = work1d.v[222];
  if (work1d.d[222] < 0)
    work1d.d[222] = settings1d.kkt_reg;
  else
    work1d.d[222] += settings1d.kkt_reg;
  work1d.d_inv[222] = 1/work1d.d[222];
  work1d.L[600] = (work1d.KKT[444])*work1d.d_inv[222];
  work1d.v[223] = work1d.KKT[445];
  work1d.d[223] = work1d.v[223];
  if (work1d.d[223] < 0)
    work1d.d[223] = settings1d.kkt_reg;
  else
    work1d.d[223] += settings1d.kkt_reg;
  work1d.d_inv[223] = 1/work1d.d[223];
  work1d.L[603] = (work1d.KKT[446])*work1d.d_inv[223];
  work1d.v[224] = work1d.KKT[447];
  work1d.d[224] = work1d.v[224];
  if (work1d.d[224] < 0)
    work1d.d[224] = settings1d.kkt_reg;
  else
    work1d.d[224] += settings1d.kkt_reg;
  work1d.d_inv[224] = 1/work1d.d[224];
  work1d.L[605] = (work1d.KKT[448])*work1d.d_inv[224];
  work1d.v[225] = work1d.KKT[449];
  work1d.d[225] = work1d.v[225];
  if (work1d.d[225] < 0)
    work1d.d[225] = settings1d.kkt_reg;
  else
    work1d.d[225] += settings1d.kkt_reg;
  work1d.d_inv[225] = 1/work1d.d[225];
  work1d.L[607] = (work1d.KKT[450])*work1d.d_inv[225];
  work1d.v[226] = work1d.KKT[451];
  work1d.d[226] = work1d.v[226];
  if (work1d.d[226] < 0)
    work1d.d[226] = settings1d.kkt_reg;
  else
    work1d.d[226] += settings1d.kkt_reg;
  work1d.d_inv[226] = 1/work1d.d[226];
  work1d.L[610] = (work1d.KKT[452])*work1d.d_inv[226];
  work1d.v[227] = work1d.KKT[453];
  work1d.d[227] = work1d.v[227];
  if (work1d.d[227] < 0)
    work1d.d[227] = settings1d.kkt_reg;
  else
    work1d.d[227] += settings1d.kkt_reg;
  work1d.d_inv[227] = 1/work1d.d[227];
  work1d.L[612] = (work1d.KKT[454])*work1d.d_inv[227];
  work1d.v[228] = work1d.KKT[455];
  work1d.d[228] = work1d.v[228];
  if (work1d.d[228] < 0)
    work1d.d[228] = settings1d.kkt_reg;
  else
    work1d.d[228] += settings1d.kkt_reg;
  work1d.d_inv[228] = 1/work1d.d[228];
  work1d.L[614] = (work1d.KKT[456])*work1d.d_inv[228];
  work1d.v[229] = work1d.KKT[457];
  work1d.d[229] = work1d.v[229];
  if (work1d.d[229] < 0)
    work1d.d[229] = settings1d.kkt_reg;
  else
    work1d.d[229] += settings1d.kkt_reg;
  work1d.d_inv[229] = 1/work1d.d[229];
  work1d.L[617] = (work1d.KKT[458])*work1d.d_inv[229];
  work1d.v[230] = work1d.KKT[459];
  work1d.d[230] = work1d.v[230];
  if (work1d.d[230] < 0)
    work1d.d[230] = settings1d.kkt_reg;
  else
    work1d.d[230] += settings1d.kkt_reg;
  work1d.d_inv[230] = 1/work1d.d[230];
  work1d.L[619] = (work1d.KKT[460])*work1d.d_inv[230];
  work1d.v[231] = work1d.KKT[461];
  work1d.d[231] = work1d.v[231];
  if (work1d.d[231] < 0)
    work1d.d[231] = settings1d.kkt_reg;
  else
    work1d.d[231] += settings1d.kkt_reg;
  work1d.d_inv[231] = 1/work1d.d[231];
  work1d.L[621] = (work1d.KKT[462])*work1d.d_inv[231];
  work1d.v[232] = work1d.KKT[463];
  work1d.d[232] = work1d.v[232];
  if (work1d.d[232] < 0)
    work1d.d[232] = settings1d.kkt_reg;
  else
    work1d.d[232] += settings1d.kkt_reg;
  work1d.d_inv[232] = 1/work1d.d[232];
  work1d.L[624] = (work1d.KKT[464])*work1d.d_inv[232];
  work1d.v[233] = work1d.KKT[465];
  work1d.d[233] = work1d.v[233];
  if (work1d.d[233] < 0)
    work1d.d[233] = settings1d.kkt_reg;
  else
    work1d.d[233] += settings1d.kkt_reg;
  work1d.d_inv[233] = 1/work1d.d[233];
  work1d.L[626] = (work1d.KKT[466])*work1d.d_inv[233];
  work1d.v[234] = work1d.KKT[467];
  work1d.d[234] = work1d.v[234];
  if (work1d.d[234] < 0)
    work1d.d[234] = settings1d.kkt_reg;
  else
    work1d.d[234] += settings1d.kkt_reg;
  work1d.d_inv[234] = 1/work1d.d[234];
  work1d.L[628] = (work1d.KKT[468])*work1d.d_inv[234];
  work1d.v[235] = work1d.KKT[469];
  work1d.d[235] = work1d.v[235];
  if (work1d.d[235] < 0)
    work1d.d[235] = settings1d.kkt_reg;
  else
    work1d.d[235] += settings1d.kkt_reg;
  work1d.d_inv[235] = 1/work1d.d[235];
  work1d.L[631] = (work1d.KKT[470])*work1d.d_inv[235];
  work1d.v[236] = work1d.KKT[471];
  work1d.d[236] = work1d.v[236];
  if (work1d.d[236] < 0)
    work1d.d[236] = settings1d.kkt_reg;
  else
    work1d.d[236] += settings1d.kkt_reg;
  work1d.d_inv[236] = 1/work1d.d[236];
  work1d.L[633] = (work1d.KKT[472])*work1d.d_inv[236];
  work1d.v[237] = work1d.KKT[473];
  work1d.d[237] = work1d.v[237];
  if (work1d.d[237] < 0)
    work1d.d[237] = settings1d.kkt_reg;
  else
    work1d.d[237] += settings1d.kkt_reg;
  work1d.d_inv[237] = 1/work1d.d[237];
  work1d.L[635] = (work1d.KKT[474])*work1d.d_inv[237];
  work1d.v[238] = work1d.KKT[475];
  work1d.d[238] = work1d.v[238];
  if (work1d.d[238] < 0)
    work1d.d[238] = settings1d.kkt_reg;
  else
    work1d.d[238] += settings1d.kkt_reg;
  work1d.d_inv[238] = 1/work1d.d[238];
  work1d.L[638] = (work1d.KKT[476])*work1d.d_inv[238];
  work1d.v[239] = work1d.KKT[477];
  work1d.d[239] = work1d.v[239];
  if (work1d.d[239] < 0)
    work1d.d[239] = settings1d.kkt_reg;
  else
    work1d.d[239] += settings1d.kkt_reg;
  work1d.d_inv[239] = 1/work1d.d[239];
  work1d.L[640] = (work1d.KKT[478])*work1d.d_inv[239];
  work1d.v[240] = work1d.KKT[479];
  work1d.d[240] = work1d.v[240];
  if (work1d.d[240] < 0)
    work1d.d[240] = settings1d.kkt_reg;
  else
    work1d.d[240] += settings1d.kkt_reg;
  work1d.d_inv[240] = 1/work1d.d[240];
  work1d.L[642] = (work1d.KKT[480])*work1d.d_inv[240];
  work1d.v[241] = work1d.KKT[481];
  work1d.d[241] = work1d.v[241];
  if (work1d.d[241] < 0)
    work1d.d[241] = settings1d.kkt_reg;
  else
    work1d.d[241] += settings1d.kkt_reg;
  work1d.d_inv[241] = 1/work1d.d[241];
  work1d.L[0] = (work1d.KKT[482])*work1d.d_inv[241];
  work1d.v[242] = work1d.KKT[483];
  work1d.d[242] = work1d.v[242];
  if (work1d.d[242] < 0)
    work1d.d[242] = settings1d.kkt_reg;
  else
    work1d.d[242] += settings1d.kkt_reg;
  work1d.d_inv[242] = 1/work1d.d[242];
  work1d.L[1] = (work1d.KKT[484])*work1d.d_inv[242];
  work1d.v[243] = work1d.KKT[485];
  work1d.d[243] = work1d.v[243];
  if (work1d.d[243] < 0)
    work1d.d[243] = settings1d.kkt_reg;
  else
    work1d.d[243] += settings1d.kkt_reg;
  work1d.d_inv[243] = 1/work1d.d[243];
  work1d.L[2] = (work1d.KKT[486])*work1d.d_inv[243];
  work1d.v[244] = work1d.KKT[487];
  work1d.d[244] = work1d.v[244];
  if (work1d.d[244] < 0)
    work1d.d[244] = settings1d.kkt_reg;
  else
    work1d.d[244] += settings1d.kkt_reg;
  work1d.d_inv[244] = 1/work1d.d[244];
  work1d.L[3] = (work1d.KKT[488])*work1d.d_inv[244];
  work1d.v[245] = work1d.KKT[489];
  work1d.d[245] = work1d.v[245];
  if (work1d.d[245] < 0)
    work1d.d[245] = settings1d.kkt_reg;
  else
    work1d.d[245] += settings1d.kkt_reg;
  work1d.d_inv[245] = 1/work1d.d[245];
  work1d.L[4] = (work1d.KKT[490])*work1d.d_inv[245];
  work1d.v[246] = work1d.KKT[491];
  work1d.d[246] = work1d.v[246];
  if (work1d.d[246] < 0)
    work1d.d[246] = settings1d.kkt_reg;
  else
    work1d.d[246] += settings1d.kkt_reg;
  work1d.d_inv[246] = 1/work1d.d[246];
  work1d.L[5] = (work1d.KKT[492])*work1d.d_inv[246];
  work1d.v[247] = work1d.KKT[493];
  work1d.d[247] = work1d.v[247];
  if (work1d.d[247] < 0)
    work1d.d[247] = settings1d.kkt_reg;
  else
    work1d.d[247] += settings1d.kkt_reg;
  work1d.d_inv[247] = 1/work1d.d[247];
  work1d.L[6] = (work1d.KKT[494])*work1d.d_inv[247];
  work1d.v[248] = work1d.KKT[495];
  work1d.d[248] = work1d.v[248];
  if (work1d.d[248] < 0)
    work1d.d[248] = settings1d.kkt_reg;
  else
    work1d.d[248] += settings1d.kkt_reg;
  work1d.d_inv[248] = 1/work1d.d[248];
  work1d.L[7] = (work1d.KKT[496])*work1d.d_inv[248];
  work1d.v[249] = work1d.KKT[497];
  work1d.d[249] = work1d.v[249];
  if (work1d.d[249] < 0)
    work1d.d[249] = settings1d.kkt_reg;
  else
    work1d.d[249] += settings1d.kkt_reg;
  work1d.d_inv[249] = 1/work1d.d[249];
  work1d.L[8] = (work1d.KKT[498])*work1d.d_inv[249];
  work1d.v[250] = work1d.KKT[499];
  work1d.d[250] = work1d.v[250];
  if (work1d.d[250] < 0)
    work1d.d[250] = settings1d.kkt_reg;
  else
    work1d.d[250] += settings1d.kkt_reg;
  work1d.d_inv[250] = 1/work1d.d[250];
  work1d.L[9] = (work1d.KKT[500])*work1d.d_inv[250];
  work1d.v[251] = work1d.KKT[501];
  work1d.d[251] = work1d.v[251];
  if (work1d.d[251] < 0)
    work1d.d[251] = settings1d.kkt_reg;
  else
    work1d.d[251] += settings1d.kkt_reg;
  work1d.d_inv[251] = 1/work1d.d[251];
  work1d.L[10] = (work1d.KKT[502])*work1d.d_inv[251];
  work1d.v[252] = work1d.KKT[503];
  work1d.d[252] = work1d.v[252];
  if (work1d.d[252] < 0)
    work1d.d[252] = settings1d.kkt_reg;
  else
    work1d.d[252] += settings1d.kkt_reg;
  work1d.d_inv[252] = 1/work1d.d[252];
  work1d.L[11] = (work1d.KKT[504])*work1d.d_inv[252];
  work1d.v[253] = work1d.KKT[505];
  work1d.d[253] = work1d.v[253];
  if (work1d.d[253] < 0)
    work1d.d[253] = settings1d.kkt_reg;
  else
    work1d.d[253] += settings1d.kkt_reg;
  work1d.d_inv[253] = 1/work1d.d[253];
  work1d.L[12] = (work1d.KKT[506])*work1d.d_inv[253];
  work1d.v[254] = work1d.KKT[507];
  work1d.d[254] = work1d.v[254];
  if (work1d.d[254] < 0)
    work1d.d[254] = settings1d.kkt_reg;
  else
    work1d.d[254] += settings1d.kkt_reg;
  work1d.d_inv[254] = 1/work1d.d[254];
  work1d.L[13] = (work1d.KKT[508])*work1d.d_inv[254];
  work1d.v[255] = work1d.KKT[509];
  work1d.d[255] = work1d.v[255];
  if (work1d.d[255] < 0)
    work1d.d[255] = settings1d.kkt_reg;
  else
    work1d.d[255] += settings1d.kkt_reg;
  work1d.d_inv[255] = 1/work1d.d[255];
  work1d.L[14] = (work1d.KKT[510])*work1d.d_inv[255];
  work1d.v[256] = work1d.KKT[511];
  work1d.d[256] = work1d.v[256];
  if (work1d.d[256] < 0)
    work1d.d[256] = settings1d.kkt_reg;
  else
    work1d.d[256] += settings1d.kkt_reg;
  work1d.d_inv[256] = 1/work1d.d[256];
  work1d.L[15] = (work1d.KKT[512])*work1d.d_inv[256];
  work1d.v[257] = work1d.KKT[513];
  work1d.d[257] = work1d.v[257];
  if (work1d.d[257] < 0)
    work1d.d[257] = settings1d.kkt_reg;
  else
    work1d.d[257] += settings1d.kkt_reg;
  work1d.d_inv[257] = 1/work1d.d[257];
  work1d.L[16] = (work1d.KKT[514])*work1d.d_inv[257];
  work1d.v[258] = work1d.KKT[515];
  work1d.d[258] = work1d.v[258];
  if (work1d.d[258] < 0)
    work1d.d[258] = settings1d.kkt_reg;
  else
    work1d.d[258] += settings1d.kkt_reg;
  work1d.d_inv[258] = 1/work1d.d[258];
  work1d.L[17] = (work1d.KKT[516])*work1d.d_inv[258];
  work1d.v[259] = work1d.KKT[517];
  work1d.d[259] = work1d.v[259];
  if (work1d.d[259] < 0)
    work1d.d[259] = settings1d.kkt_reg;
  else
    work1d.d[259] += settings1d.kkt_reg;
  work1d.d_inv[259] = 1/work1d.d[259];
  work1d.L[18] = (work1d.KKT[518])*work1d.d_inv[259];
  work1d.v[260] = work1d.KKT[519];
  work1d.d[260] = work1d.v[260];
  if (work1d.d[260] < 0)
    work1d.d[260] = settings1d.kkt_reg;
  else
    work1d.d[260] += settings1d.kkt_reg;
  work1d.d_inv[260] = 1/work1d.d[260];
  work1d.L[19] = (work1d.KKT[520])*work1d.d_inv[260];
  work1d.v[261] = work1d.KKT[521];
  work1d.d[261] = work1d.v[261];
  if (work1d.d[261] < 0)
    work1d.d[261] = settings1d.kkt_reg;
  else
    work1d.d[261] += settings1d.kkt_reg;
  work1d.d_inv[261] = 1/work1d.d[261];
  work1d.L[20] = (work1d.KKT[522])*work1d.d_inv[261];
  work1d.v[262] = work1d.KKT[523];
  work1d.d[262] = work1d.v[262];
  if (work1d.d[262] < 0)
    work1d.d[262] = settings1d.kkt_reg;
  else
    work1d.d[262] += settings1d.kkt_reg;
  work1d.d_inv[262] = 1/work1d.d[262];
  work1d.L[21] = (work1d.KKT[524])*work1d.d_inv[262];
  work1d.v[263] = work1d.KKT[525];
  work1d.d[263] = work1d.v[263];
  if (work1d.d[263] < 0)
    work1d.d[263] = settings1d.kkt_reg;
  else
    work1d.d[263] += settings1d.kkt_reg;
  work1d.d_inv[263] = 1/work1d.d[263];
  work1d.L[22] = (work1d.KKT[526])*work1d.d_inv[263];
  work1d.v[264] = work1d.KKT[527];
  work1d.d[264] = work1d.v[264];
  if (work1d.d[264] < 0)
    work1d.d[264] = settings1d.kkt_reg;
  else
    work1d.d[264] += settings1d.kkt_reg;
  work1d.d_inv[264] = 1/work1d.d[264];
  work1d.L[23] = (work1d.KKT[528])*work1d.d_inv[264];
  work1d.v[265] = work1d.KKT[529];
  work1d.d[265] = work1d.v[265];
  if (work1d.d[265] < 0)
    work1d.d[265] = settings1d.kkt_reg;
  else
    work1d.d[265] += settings1d.kkt_reg;
  work1d.d_inv[265] = 1/work1d.d[265];
  work1d.L[24] = (work1d.KKT[530])*work1d.d_inv[265];
  work1d.v[266] = work1d.KKT[531];
  work1d.d[266] = work1d.v[266];
  if (work1d.d[266] < 0)
    work1d.d[266] = settings1d.kkt_reg;
  else
    work1d.d[266] += settings1d.kkt_reg;
  work1d.d_inv[266] = 1/work1d.d[266];
  work1d.L[25] = (work1d.KKT[532])*work1d.d_inv[266];
  work1d.v[267] = work1d.KKT[533];
  work1d.d[267] = work1d.v[267];
  if (work1d.d[267] < 0)
    work1d.d[267] = settings1d.kkt_reg;
  else
    work1d.d[267] += settings1d.kkt_reg;
  work1d.d_inv[267] = 1/work1d.d[267];
  work1d.L[26] = (work1d.KKT[534])*work1d.d_inv[267];
  work1d.v[268] = work1d.KKT[535];
  work1d.d[268] = work1d.v[268];
  if (work1d.d[268] < 0)
    work1d.d[268] = settings1d.kkt_reg;
  else
    work1d.d[268] += settings1d.kkt_reg;
  work1d.d_inv[268] = 1/work1d.d[268];
  work1d.L[27] = (work1d.KKT[536])*work1d.d_inv[268];
  work1d.v[269] = work1d.KKT[537];
  work1d.d[269] = work1d.v[269];
  if (work1d.d[269] < 0)
    work1d.d[269] = settings1d.kkt_reg;
  else
    work1d.d[269] += settings1d.kkt_reg;
  work1d.d_inv[269] = 1/work1d.d[269];
  work1d.L[28] = (work1d.KKT[538])*work1d.d_inv[269];
  work1d.v[270] = work1d.KKT[539];
  work1d.d[270] = work1d.v[270];
  if (work1d.d[270] < 0)
    work1d.d[270] = settings1d.kkt_reg;
  else
    work1d.d[270] += settings1d.kkt_reg;
  work1d.d_inv[270] = 1/work1d.d[270];
  work1d.L[29] = (work1d.KKT[540])*work1d.d_inv[270];
  work1d.v[271] = work1d.KKT[541];
  work1d.d[271] = work1d.v[271];
  if (work1d.d[271] < 0)
    work1d.d[271] = settings1d.kkt_reg;
  else
    work1d.d[271] += settings1d.kkt_reg;
  work1d.d_inv[271] = 1/work1d.d[271];
  work1d.L[30] = (work1d.KKT[542])*work1d.d_inv[271];
  work1d.v[272] = work1d.KKT[543];
  work1d.d[272] = work1d.v[272];
  if (work1d.d[272] < 0)
    work1d.d[272] = settings1d.kkt_reg;
  else
    work1d.d[272] += settings1d.kkt_reg;
  work1d.d_inv[272] = 1/work1d.d[272];
  work1d.L[31] = (work1d.KKT[544])*work1d.d_inv[272];
  work1d.v[273] = work1d.KKT[545];
  work1d.d[273] = work1d.v[273];
  if (work1d.d[273] < 0)
    work1d.d[273] = settings1d.kkt_reg;
  else
    work1d.d[273] += settings1d.kkt_reg;
  work1d.d_inv[273] = 1/work1d.d[273];
  work1d.L[32] = (work1d.KKT[546])*work1d.d_inv[273];
  work1d.v[274] = work1d.KKT[547];
  work1d.d[274] = work1d.v[274];
  if (work1d.d[274] < 0)
    work1d.d[274] = settings1d.kkt_reg;
  else
    work1d.d[274] += settings1d.kkt_reg;
  work1d.d_inv[274] = 1/work1d.d[274];
  work1d.L[33] = (work1d.KKT[548])*work1d.d_inv[274];
  work1d.v[275] = work1d.KKT[549];
  work1d.d[275] = work1d.v[275];
  if (work1d.d[275] < 0)
    work1d.d[275] = settings1d.kkt_reg;
  else
    work1d.d[275] += settings1d.kkt_reg;
  work1d.d_inv[275] = 1/work1d.d[275];
  work1d.L[34] = (work1d.KKT[550])*work1d.d_inv[275];
  work1d.v[276] = work1d.KKT[551];
  work1d.d[276] = work1d.v[276];
  if (work1d.d[276] < 0)
    work1d.d[276] = settings1d.kkt_reg;
  else
    work1d.d[276] += settings1d.kkt_reg;
  work1d.d_inv[276] = 1/work1d.d[276];
  work1d.L[35] = (work1d.KKT[552])*work1d.d_inv[276];
  work1d.v[277] = work1d.KKT[553];
  work1d.d[277] = work1d.v[277];
  if (work1d.d[277] < 0)
    work1d.d[277] = settings1d.kkt_reg;
  else
    work1d.d[277] += settings1d.kkt_reg;
  work1d.d_inv[277] = 1/work1d.d[277];
  work1d.L[36] = (work1d.KKT[554])*work1d.d_inv[277];
  work1d.v[278] = work1d.KKT[555];
  work1d.d[278] = work1d.v[278];
  if (work1d.d[278] < 0)
    work1d.d[278] = settings1d.kkt_reg;
  else
    work1d.d[278] += settings1d.kkt_reg;
  work1d.d_inv[278] = 1/work1d.d[278];
  work1d.L[37] = (work1d.KKT[556])*work1d.d_inv[278];
  work1d.v[279] = work1d.KKT[557];
  work1d.d[279] = work1d.v[279];
  if (work1d.d[279] < 0)
    work1d.d[279] = settings1d.kkt_reg;
  else
    work1d.d[279] += settings1d.kkt_reg;
  work1d.d_inv[279] = 1/work1d.d[279];
  work1d.L[38] = (work1d.KKT[558])*work1d.d_inv[279];
  work1d.v[280] = work1d.KKT[559];
  work1d.d[280] = work1d.v[280];
  if (work1d.d[280] < 0)
    work1d.d[280] = settings1d.kkt_reg;
  else
    work1d.d[280] += settings1d.kkt_reg;
  work1d.d_inv[280] = 1/work1d.d[280];
  work1d.L[39] = (work1d.KKT[560])*work1d.d_inv[280];
  work1d.v[281] = work1d.KKT[561];
  work1d.d[281] = work1d.v[281];
  if (work1d.d[281] < 0)
    work1d.d[281] = settings1d.kkt_reg;
  else
    work1d.d[281] += settings1d.kkt_reg;
  work1d.d_inv[281] = 1/work1d.d[281];
  work1d.L[40] = (work1d.KKT[562])*work1d.d_inv[281];
  work1d.v[282] = work1d.KKT[563];
  work1d.d[282] = work1d.v[282];
  if (work1d.d[282] < 0)
    work1d.d[282] = settings1d.kkt_reg;
  else
    work1d.d[282] += settings1d.kkt_reg;
  work1d.d_inv[282] = 1/work1d.d[282];
  work1d.L[41] = (work1d.KKT[564])*work1d.d_inv[282];
  work1d.v[283] = work1d.KKT[565];
  work1d.d[283] = work1d.v[283];
  if (work1d.d[283] < 0)
    work1d.d[283] = settings1d.kkt_reg;
  else
    work1d.d[283] += settings1d.kkt_reg;
  work1d.d_inv[283] = 1/work1d.d[283];
  work1d.L[42] = (work1d.KKT[566])*work1d.d_inv[283];
  work1d.v[284] = work1d.KKT[567];
  work1d.d[284] = work1d.v[284];
  if (work1d.d[284] < 0)
    work1d.d[284] = settings1d.kkt_reg;
  else
    work1d.d[284] += settings1d.kkt_reg;
  work1d.d_inv[284] = 1/work1d.d[284];
  work1d.L[43] = (work1d.KKT[568])*work1d.d_inv[284];
  work1d.v[285] = work1d.KKT[569];
  work1d.d[285] = work1d.v[285];
  if (work1d.d[285] < 0)
    work1d.d[285] = settings1d.kkt_reg;
  else
    work1d.d[285] += settings1d.kkt_reg;
  work1d.d_inv[285] = 1/work1d.d[285];
  work1d.L[44] = (work1d.KKT[570])*work1d.d_inv[285];
  work1d.v[286] = work1d.KKT[571];
  work1d.d[286] = work1d.v[286];
  if (work1d.d[286] < 0)
    work1d.d[286] = settings1d.kkt_reg;
  else
    work1d.d[286] += settings1d.kkt_reg;
  work1d.d_inv[286] = 1/work1d.d[286];
  work1d.L[45] = (work1d.KKT[572])*work1d.d_inv[286];
  work1d.v[287] = work1d.KKT[573];
  work1d.d[287] = work1d.v[287];
  if (work1d.d[287] < 0)
    work1d.d[287] = settings1d.kkt_reg;
  else
    work1d.d[287] += settings1d.kkt_reg;
  work1d.d_inv[287] = 1/work1d.d[287];
  work1d.L[46] = (work1d.KKT[574])*work1d.d_inv[287];
  work1d.v[288] = work1d.KKT[575];
  work1d.d[288] = work1d.v[288];
  if (work1d.d[288] < 0)
    work1d.d[288] = settings1d.kkt_reg;
  else
    work1d.d[288] += settings1d.kkt_reg;
  work1d.d_inv[288] = 1/work1d.d[288];
  work1d.L[47] = (work1d.KKT[576])*work1d.d_inv[288];
  work1d.v[289] = work1d.KKT[577];
  work1d.d[289] = work1d.v[289];
  if (work1d.d[289] < 0)
    work1d.d[289] = settings1d.kkt_reg;
  else
    work1d.d[289] += settings1d.kkt_reg;
  work1d.d_inv[289] = 1/work1d.d[289];
  work1d.L[48] = (work1d.KKT[578])*work1d.d_inv[289];
  work1d.v[290] = work1d.KKT[579];
  work1d.d[290] = work1d.v[290];
  if (work1d.d[290] < 0)
    work1d.d[290] = settings1d.kkt_reg;
  else
    work1d.d[290] += settings1d.kkt_reg;
  work1d.d_inv[290] = 1/work1d.d[290];
  work1d.L[49] = (work1d.KKT[580])*work1d.d_inv[290];
  work1d.v[291] = work1d.KKT[581];
  work1d.d[291] = work1d.v[291];
  if (work1d.d[291] < 0)
    work1d.d[291] = settings1d.kkt_reg;
  else
    work1d.d[291] += settings1d.kkt_reg;
  work1d.d_inv[291] = 1/work1d.d[291];
  work1d.L[50] = (work1d.KKT[582])*work1d.d_inv[291];
  work1d.v[292] = work1d.KKT[583];
  work1d.d[292] = work1d.v[292];
  if (work1d.d[292] < 0)
    work1d.d[292] = settings1d.kkt_reg;
  else
    work1d.d[292] += settings1d.kkt_reg;
  work1d.d_inv[292] = 1/work1d.d[292];
  work1d.L[51] = (work1d.KKT[584])*work1d.d_inv[292];
  work1d.v[293] = work1d.KKT[585];
  work1d.d[293] = work1d.v[293];
  if (work1d.d[293] < 0)
    work1d.d[293] = settings1d.kkt_reg;
  else
    work1d.d[293] += settings1d.kkt_reg;
  work1d.d_inv[293] = 1/work1d.d[293];
  work1d.L[52] = (work1d.KKT[586])*work1d.d_inv[293];
  work1d.v[294] = work1d.KKT[587];
  work1d.d[294] = work1d.v[294];
  if (work1d.d[294] < 0)
    work1d.d[294] = settings1d.kkt_reg;
  else
    work1d.d[294] += settings1d.kkt_reg;
  work1d.d_inv[294] = 1/work1d.d[294];
  work1d.L[53] = (work1d.KKT[588])*work1d.d_inv[294];
  work1d.v[295] = work1d.KKT[589];
  work1d.d[295] = work1d.v[295];
  if (work1d.d[295] < 0)
    work1d.d[295] = settings1d.kkt_reg;
  else
    work1d.d[295] += settings1d.kkt_reg;
  work1d.d_inv[295] = 1/work1d.d[295];
  work1d.L[54] = (work1d.KKT[590])*work1d.d_inv[295];
  work1d.v[296] = work1d.KKT[591];
  work1d.d[296] = work1d.v[296];
  if (work1d.d[296] < 0)
    work1d.d[296] = settings1d.kkt_reg;
  else
    work1d.d[296] += settings1d.kkt_reg;
  work1d.d_inv[296] = 1/work1d.d[296];
  work1d.L[55] = (work1d.KKT[592])*work1d.d_inv[296];
  work1d.v[297] = work1d.KKT[593];
  work1d.d[297] = work1d.v[297];
  if (work1d.d[297] < 0)
    work1d.d[297] = settings1d.kkt_reg;
  else
    work1d.d[297] += settings1d.kkt_reg;
  work1d.d_inv[297] = 1/work1d.d[297];
  work1d.L[56] = (work1d.KKT[594])*work1d.d_inv[297];
  work1d.v[298] = work1d.KKT[595];
  work1d.d[298] = work1d.v[298];
  if (work1d.d[298] < 0)
    work1d.d[298] = settings1d.kkt_reg;
  else
    work1d.d[298] += settings1d.kkt_reg;
  work1d.d_inv[298] = 1/work1d.d[298];
  work1d.L[57] = (work1d.KKT[596])*work1d.d_inv[298];
  work1d.v[299] = work1d.KKT[597];
  work1d.d[299] = work1d.v[299];
  if (work1d.d[299] < 0)
    work1d.d[299] = settings1d.kkt_reg;
  else
    work1d.d[299] += settings1d.kkt_reg;
  work1d.d_inv[299] = 1/work1d.d[299];
  work1d.L[58] = (work1d.KKT[598])*work1d.d_inv[299];
  work1d.v[300] = work1d.KKT[599];
  work1d.d[300] = work1d.v[300];
  if (work1d.d[300] < 0)
    work1d.d[300] = settings1d.kkt_reg;
  else
    work1d.d[300] += settings1d.kkt_reg;
  work1d.d_inv[300] = 1/work1d.d[300];
  work1d.L[59] = (work1d.KKT[600])*work1d.d_inv[300];
  work1d.v[301] = work1d.KKT[601];
  work1d.d[301] = work1d.v[301];
  if (work1d.d[301] < 0)
    work1d.d[301] = settings1d.kkt_reg;
  else
    work1d.d[301] += settings1d.kkt_reg;
  work1d.d_inv[301] = 1/work1d.d[301];
  work1d.L[60] = (work1d.KKT[602])*work1d.d_inv[301];
  work1d.v[302] = work1d.KKT[603];
  work1d.d[302] = work1d.v[302];
  if (work1d.d[302] < 0)
    work1d.d[302] = settings1d.kkt_reg;
  else
    work1d.d[302] += settings1d.kkt_reg;
  work1d.d_inv[302] = 1/work1d.d[302];
  work1d.L[61] = (work1d.KKT[604])*work1d.d_inv[302];
  work1d.v[303] = work1d.KKT[605];
  work1d.d[303] = work1d.v[303];
  if (work1d.d[303] < 0)
    work1d.d[303] = settings1d.kkt_reg;
  else
    work1d.d[303] += settings1d.kkt_reg;
  work1d.d_inv[303] = 1/work1d.d[303];
  work1d.L[62] = (work1d.KKT[606])*work1d.d_inv[303];
  work1d.v[304] = work1d.KKT[607];
  work1d.d[304] = work1d.v[304];
  if (work1d.d[304] < 0)
    work1d.d[304] = settings1d.kkt_reg;
  else
    work1d.d[304] += settings1d.kkt_reg;
  work1d.d_inv[304] = 1/work1d.d[304];
  work1d.L[63] = (work1d.KKT[608])*work1d.d_inv[304];
  work1d.v[305] = work1d.KKT[609];
  work1d.d[305] = work1d.v[305];
  if (work1d.d[305] < 0)
    work1d.d[305] = settings1d.kkt_reg;
  else
    work1d.d[305] += settings1d.kkt_reg;
  work1d.d_inv[305] = 1/work1d.d[305];
  work1d.L[64] = (work1d.KKT[610])*work1d.d_inv[305];
  work1d.v[306] = work1d.KKT[611];
  work1d.d[306] = work1d.v[306];
  if (work1d.d[306] < 0)
    work1d.d[306] = settings1d.kkt_reg;
  else
    work1d.d[306] += settings1d.kkt_reg;
  work1d.d_inv[306] = 1/work1d.d[306];
  work1d.L[65] = (work1d.KKT[612])*work1d.d_inv[306];
  work1d.v[307] = work1d.KKT[613];
  work1d.d[307] = work1d.v[307];
  if (work1d.d[307] < 0)
    work1d.d[307] = settings1d.kkt_reg;
  else
    work1d.d[307] += settings1d.kkt_reg;
  work1d.d_inv[307] = 1/work1d.d[307];
  work1d.L[66] = (work1d.KKT[614])*work1d.d_inv[307];
  work1d.v[308] = work1d.KKT[615];
  work1d.d[308] = work1d.v[308];
  if (work1d.d[308] < 0)
    work1d.d[308] = settings1d.kkt_reg;
  else
    work1d.d[308] += settings1d.kkt_reg;
  work1d.d_inv[308] = 1/work1d.d[308];
  work1d.L[67] = (work1d.KKT[616])*work1d.d_inv[308];
  work1d.v[309] = work1d.KKT[617];
  work1d.d[309] = work1d.v[309];
  if (work1d.d[309] < 0)
    work1d.d[309] = settings1d.kkt_reg;
  else
    work1d.d[309] += settings1d.kkt_reg;
  work1d.d_inv[309] = 1/work1d.d[309];
  work1d.L[68] = (work1d.KKT[618])*work1d.d_inv[309];
  work1d.v[310] = work1d.KKT[619];
  work1d.d[310] = work1d.v[310];
  if (work1d.d[310] < 0)
    work1d.d[310] = settings1d.kkt_reg;
  else
    work1d.d[310] += settings1d.kkt_reg;
  work1d.d_inv[310] = 1/work1d.d[310];
  work1d.L[69] = (work1d.KKT[620])*work1d.d_inv[310];
  work1d.v[311] = work1d.KKT[621];
  work1d.d[311] = work1d.v[311];
  if (work1d.d[311] < 0)
    work1d.d[311] = settings1d.kkt_reg;
  else
    work1d.d[311] += settings1d.kkt_reg;
  work1d.d_inv[311] = 1/work1d.d[311];
  work1d.L[70] = (work1d.KKT[622])*work1d.d_inv[311];
  work1d.v[312] = work1d.KKT[623];
  work1d.d[312] = work1d.v[312];
  if (work1d.d[312] < 0)
    work1d.d[312] = settings1d.kkt_reg;
  else
    work1d.d[312] += settings1d.kkt_reg;
  work1d.d_inv[312] = 1/work1d.d[312];
  work1d.L[71] = (work1d.KKT[624])*work1d.d_inv[312];
  work1d.v[313] = work1d.KKT[625];
  work1d.d[313] = work1d.v[313];
  if (work1d.d[313] < 0)
    work1d.d[313] = settings1d.kkt_reg;
  else
    work1d.d[313] += settings1d.kkt_reg;
  work1d.d_inv[313] = 1/work1d.d[313];
  work1d.L[72] = (work1d.KKT[626])*work1d.d_inv[313];
  work1d.v[314] = work1d.KKT[627];
  work1d.d[314] = work1d.v[314];
  if (work1d.d[314] < 0)
    work1d.d[314] = settings1d.kkt_reg;
  else
    work1d.d[314] += settings1d.kkt_reg;
  work1d.d_inv[314] = 1/work1d.d[314];
  work1d.L[73] = (work1d.KKT[628])*work1d.d_inv[314];
  work1d.v[315] = work1d.KKT[629];
  work1d.d[315] = work1d.v[315];
  if (work1d.d[315] < 0)
    work1d.d[315] = settings1d.kkt_reg;
  else
    work1d.d[315] += settings1d.kkt_reg;
  work1d.d_inv[315] = 1/work1d.d[315];
  work1d.L[74] = (work1d.KKT[630])*work1d.d_inv[315];
  work1d.v[316] = work1d.KKT[631];
  work1d.d[316] = work1d.v[316];
  if (work1d.d[316] < 0)
    work1d.d[316] = settings1d.kkt_reg;
  else
    work1d.d[316] += settings1d.kkt_reg;
  work1d.d_inv[316] = 1/work1d.d[316];
  work1d.L[75] = (work1d.KKT[632])*work1d.d_inv[316];
  work1d.v[317] = work1d.KKT[633];
  work1d.d[317] = work1d.v[317];
  if (work1d.d[317] < 0)
    work1d.d[317] = settings1d.kkt_reg;
  else
    work1d.d[317] += settings1d.kkt_reg;
  work1d.d_inv[317] = 1/work1d.d[317];
  work1d.L[76] = (work1d.KKT[634])*work1d.d_inv[317];
  work1d.v[318] = work1d.KKT[635];
  work1d.d[318] = work1d.v[318];
  if (work1d.d[318] < 0)
    work1d.d[318] = settings1d.kkt_reg;
  else
    work1d.d[318] += settings1d.kkt_reg;
  work1d.d_inv[318] = 1/work1d.d[318];
  work1d.L[77] = (work1d.KKT[636])*work1d.d_inv[318];
  work1d.v[319] = work1d.KKT[637];
  work1d.d[319] = work1d.v[319];
  if (work1d.d[319] < 0)
    work1d.d[319] = settings1d.kkt_reg;
  else
    work1d.d[319] += settings1d.kkt_reg;
  work1d.d_inv[319] = 1/work1d.d[319];
  work1d.L[78] = (work1d.KKT[638])*work1d.d_inv[319];
  work1d.v[320] = work1d.KKT[639];
  work1d.d[320] = work1d.v[320];
  if (work1d.d[320] < 0)
    work1d.d[320] = settings1d.kkt_reg;
  else
    work1d.d[320] += settings1d.kkt_reg;
  work1d.d_inv[320] = 1/work1d.d[320];
  work1d.L[79] = (work1d.KKT[640])*work1d.d_inv[320];
  work1d.v[241] = work1d.L[0]*work1d.d[241];
  work1d.v[321] = work1d.KKT[641]-work1d.L[0]*work1d.v[241];
  work1d.d[321] = work1d.v[321];
  if (work1d.d[321] > 0)
    work1d.d[321] = -settings1d.kkt_reg;
  else
    work1d.d[321] -= settings1d.kkt_reg;
  work1d.d_inv[321] = 1/work1d.d[321];
  work1d.L[698] = (work1d.KKT[642])*work1d.d_inv[321];
  work1d.v[242] = work1d.L[1]*work1d.d[242];
  work1d.v[322] = work1d.KKT[643]-work1d.L[1]*work1d.v[242];
  work1d.d[322] = work1d.v[322];
  if (work1d.d[322] > 0)
    work1d.d[322] = -settings1d.kkt_reg;
  else
    work1d.d[322] -= settings1d.kkt_reg;
  work1d.d_inv[322] = 1/work1d.d[322];
  work1d.L[714] = (work1d.KKT[644])*work1d.d_inv[322];
  work1d.v[243] = work1d.L[2]*work1d.d[243];
  work1d.v[323] = work1d.KKT[645]-work1d.L[2]*work1d.v[243];
  work1d.d[323] = work1d.v[323];
  if (work1d.d[323] > 0)
    work1d.d[323] = -settings1d.kkt_reg;
  else
    work1d.d[323] -= settings1d.kkt_reg;
  work1d.d_inv[323] = 1/work1d.d[323];
  work1d.L[734] = (work1d.KKT[646])*work1d.d_inv[323];
  work1d.v[244] = work1d.L[3]*work1d.d[244];
  work1d.v[324] = work1d.KKT[647]-work1d.L[3]*work1d.v[244];
  work1d.d[324] = work1d.v[324];
  if (work1d.d[324] > 0)
    work1d.d[324] = -settings1d.kkt_reg;
  else
    work1d.d[324] -= settings1d.kkt_reg;
  work1d.d_inv[324] = 1/work1d.d[324];
  work1d.L[756] = (work1d.KKT[648])*work1d.d_inv[324];
  work1d.v[245] = work1d.L[4]*work1d.d[245];
  work1d.v[325] = work1d.KKT[649]-work1d.L[4]*work1d.v[245];
  work1d.d[325] = work1d.v[325];
  if (work1d.d[325] > 0)
    work1d.d[325] = -settings1d.kkt_reg;
  else
    work1d.d[325] -= settings1d.kkt_reg;
  work1d.d_inv[325] = 1/work1d.d[325];
  work1d.L[778] = (work1d.KKT[650])*work1d.d_inv[325];
  work1d.v[246] = work1d.L[5]*work1d.d[246];
  work1d.v[326] = work1d.KKT[651]-work1d.L[5]*work1d.v[246];
  work1d.d[326] = work1d.v[326];
  if (work1d.d[326] > 0)
    work1d.d[326] = -settings1d.kkt_reg;
  else
    work1d.d[326] -= settings1d.kkt_reg;
  work1d.d_inv[326] = 1/work1d.d[326];
  work1d.L[800] = (work1d.KKT[652])*work1d.d_inv[326];
  work1d.v[247] = work1d.L[6]*work1d.d[247];
  work1d.v[327] = work1d.KKT[653]-work1d.L[6]*work1d.v[247];
  work1d.d[327] = work1d.v[327];
  if (work1d.d[327] > 0)
    work1d.d[327] = -settings1d.kkt_reg;
  else
    work1d.d[327] -= settings1d.kkt_reg;
  work1d.d_inv[327] = 1/work1d.d[327];
  work1d.L[822] = (work1d.KKT[654])*work1d.d_inv[327];
  work1d.v[248] = work1d.L[7]*work1d.d[248];
  work1d.v[328] = work1d.KKT[655]-work1d.L[7]*work1d.v[248];
  work1d.d[328] = work1d.v[328];
  if (work1d.d[328] > 0)
    work1d.d[328] = -settings1d.kkt_reg;
  else
    work1d.d[328] -= settings1d.kkt_reg;
  work1d.d_inv[328] = 1/work1d.d[328];
  work1d.L[844] = (work1d.KKT[656])*work1d.d_inv[328];
  work1d.v[249] = work1d.L[8]*work1d.d[249];
  work1d.v[329] = work1d.KKT[657]-work1d.L[8]*work1d.v[249];
  work1d.d[329] = work1d.v[329];
  if (work1d.d[329] > 0)
    work1d.d[329] = -settings1d.kkt_reg;
  else
    work1d.d[329] -= settings1d.kkt_reg;
  work1d.d_inv[329] = 1/work1d.d[329];
  work1d.L[866] = (work1d.KKT[658])*work1d.d_inv[329];
  work1d.v[250] = work1d.L[9]*work1d.d[250];
  work1d.v[330] = work1d.KKT[659]-work1d.L[9]*work1d.v[250];
  work1d.d[330] = work1d.v[330];
  if (work1d.d[330] > 0)
    work1d.d[330] = -settings1d.kkt_reg;
  else
    work1d.d[330] -= settings1d.kkt_reg;
  work1d.d_inv[330] = 1/work1d.d[330];
  work1d.L[888] = (work1d.KKT[660])*work1d.d_inv[330];
  work1d.v[251] = work1d.L[10]*work1d.d[251];
  work1d.v[331] = work1d.KKT[661]-work1d.L[10]*work1d.v[251];
  work1d.d[331] = work1d.v[331];
  if (work1d.d[331] > 0)
    work1d.d[331] = -settings1d.kkt_reg;
  else
    work1d.d[331] -= settings1d.kkt_reg;
  work1d.d_inv[331] = 1/work1d.d[331];
  work1d.L[910] = (work1d.KKT[662])*work1d.d_inv[331];
  work1d.v[252] = work1d.L[11]*work1d.d[252];
  work1d.v[332] = work1d.KKT[663]-work1d.L[11]*work1d.v[252];
  work1d.d[332] = work1d.v[332];
  if (work1d.d[332] > 0)
    work1d.d[332] = -settings1d.kkt_reg;
  else
    work1d.d[332] -= settings1d.kkt_reg;
  work1d.d_inv[332] = 1/work1d.d[332];
  work1d.L[932] = (work1d.KKT[664])*work1d.d_inv[332];
  work1d.v[253] = work1d.L[12]*work1d.d[253];
  work1d.v[333] = work1d.KKT[665]-work1d.L[12]*work1d.v[253];
  work1d.d[333] = work1d.v[333];
  if (work1d.d[333] > 0)
    work1d.d[333] = -settings1d.kkt_reg;
  else
    work1d.d[333] -= settings1d.kkt_reg;
  work1d.d_inv[333] = 1/work1d.d[333];
  work1d.L[954] = (work1d.KKT[666])*work1d.d_inv[333];
  work1d.v[254] = work1d.L[13]*work1d.d[254];
  work1d.v[334] = work1d.KKT[667]-work1d.L[13]*work1d.v[254];
  work1d.d[334] = work1d.v[334];
  if (work1d.d[334] > 0)
    work1d.d[334] = -settings1d.kkt_reg;
  else
    work1d.d[334] -= settings1d.kkt_reg;
  work1d.d_inv[334] = 1/work1d.d[334];
  work1d.L[976] = (work1d.KKT[668])*work1d.d_inv[334];
  work1d.v[255] = work1d.L[14]*work1d.d[255];
  work1d.v[335] = work1d.KKT[669]-work1d.L[14]*work1d.v[255];
  work1d.d[335] = work1d.v[335];
  if (work1d.d[335] > 0)
    work1d.d[335] = -settings1d.kkt_reg;
  else
    work1d.d[335] -= settings1d.kkt_reg;
  work1d.d_inv[335] = 1/work1d.d[335];
  work1d.L[998] = (work1d.KKT[670])*work1d.d_inv[335];
  work1d.v[256] = work1d.L[15]*work1d.d[256];
  work1d.v[336] = work1d.KKT[671]-work1d.L[15]*work1d.v[256];
  work1d.d[336] = work1d.v[336];
  if (work1d.d[336] > 0)
    work1d.d[336] = -settings1d.kkt_reg;
  else
    work1d.d[336] -= settings1d.kkt_reg;
  work1d.d_inv[336] = 1/work1d.d[336];
  work1d.L[1020] = (work1d.KKT[672])*work1d.d_inv[336];
  work1d.v[257] = work1d.L[16]*work1d.d[257];
  work1d.v[337] = work1d.KKT[673]-work1d.L[16]*work1d.v[257];
  work1d.d[337] = work1d.v[337];
  if (work1d.d[337] > 0)
    work1d.d[337] = -settings1d.kkt_reg;
  else
    work1d.d[337] -= settings1d.kkt_reg;
  work1d.d_inv[337] = 1/work1d.d[337];
  work1d.L[1042] = (work1d.KKT[674])*work1d.d_inv[337];
  work1d.v[258] = work1d.L[17]*work1d.d[258];
  work1d.v[338] = work1d.KKT[675]-work1d.L[17]*work1d.v[258];
  work1d.d[338] = work1d.v[338];
  if (work1d.d[338] > 0)
    work1d.d[338] = -settings1d.kkt_reg;
  else
    work1d.d[338] -= settings1d.kkt_reg;
  work1d.d_inv[338] = 1/work1d.d[338];
  work1d.L[1064] = (work1d.KKT[676])*work1d.d_inv[338];
  work1d.v[259] = work1d.L[18]*work1d.d[259];
  work1d.v[339] = work1d.KKT[677]-work1d.L[18]*work1d.v[259];
  work1d.d[339] = work1d.v[339];
  if (work1d.d[339] > 0)
    work1d.d[339] = -settings1d.kkt_reg;
  else
    work1d.d[339] -= settings1d.kkt_reg;
  work1d.d_inv[339] = 1/work1d.d[339];
  work1d.L[1086] = (work1d.KKT[678])*work1d.d_inv[339];
  work1d.v[260] = work1d.L[19]*work1d.d[260];
  work1d.v[340] = work1d.KKT[679]-work1d.L[19]*work1d.v[260];
  work1d.d[340] = work1d.v[340];
  if (work1d.d[340] > 0)
    work1d.d[340] = -settings1d.kkt_reg;
  else
    work1d.d[340] -= settings1d.kkt_reg;
  work1d.d_inv[340] = 1/work1d.d[340];
  work1d.L[1108] = (work1d.KKT[680])*work1d.d_inv[340];
  work1d.v[261] = work1d.L[20]*work1d.d[261];
  work1d.v[341] = work1d.KKT[681]-work1d.L[20]*work1d.v[261];
  work1d.d[341] = work1d.v[341];
  if (work1d.d[341] > 0)
    work1d.d[341] = -settings1d.kkt_reg;
  else
    work1d.d[341] -= settings1d.kkt_reg;
  work1d.d_inv[341] = 1/work1d.d[341];
  work1d.L[1130] = (work1d.KKT[682])*work1d.d_inv[341];
  work1d.v[262] = work1d.L[21]*work1d.d[262];
  work1d.v[342] = work1d.KKT[683]-work1d.L[21]*work1d.v[262];
  work1d.d[342] = work1d.v[342];
  if (work1d.d[342] > 0)
    work1d.d[342] = -settings1d.kkt_reg;
  else
    work1d.d[342] -= settings1d.kkt_reg;
  work1d.d_inv[342] = 1/work1d.d[342];
  work1d.L[1152] = (work1d.KKT[684])*work1d.d_inv[342];
  work1d.v[263] = work1d.L[22]*work1d.d[263];
  work1d.v[343] = work1d.KKT[685]-work1d.L[22]*work1d.v[263];
  work1d.d[343] = work1d.v[343];
  if (work1d.d[343] > 0)
    work1d.d[343] = -settings1d.kkt_reg;
  else
    work1d.d[343] -= settings1d.kkt_reg;
  work1d.d_inv[343] = 1/work1d.d[343];
  work1d.L[1174] = (work1d.KKT[686])*work1d.d_inv[343];
  work1d.v[264] = work1d.L[23]*work1d.d[264];
  work1d.v[344] = work1d.KKT[687]-work1d.L[23]*work1d.v[264];
  work1d.d[344] = work1d.v[344];
  if (work1d.d[344] > 0)
    work1d.d[344] = -settings1d.kkt_reg;
  else
    work1d.d[344] -= settings1d.kkt_reg;
  work1d.d_inv[344] = 1/work1d.d[344];
  work1d.L[1196] = (work1d.KKT[688])*work1d.d_inv[344];
  work1d.v[265] = work1d.L[24]*work1d.d[265];
  work1d.v[345] = work1d.KKT[689]-work1d.L[24]*work1d.v[265];
  work1d.d[345] = work1d.v[345];
  if (work1d.d[345] > 0)
    work1d.d[345] = -settings1d.kkt_reg;
  else
    work1d.d[345] -= settings1d.kkt_reg;
  work1d.d_inv[345] = 1/work1d.d[345];
  work1d.L[1218] = (work1d.KKT[690])*work1d.d_inv[345];
  work1d.v[266] = work1d.L[25]*work1d.d[266];
  work1d.v[346] = work1d.KKT[691]-work1d.L[25]*work1d.v[266];
  work1d.d[346] = work1d.v[346];
  if (work1d.d[346] > 0)
    work1d.d[346] = -settings1d.kkt_reg;
  else
    work1d.d[346] -= settings1d.kkt_reg;
  work1d.d_inv[346] = 1/work1d.d[346];
  work1d.L[1240] = (work1d.KKT[692])*work1d.d_inv[346];
  work1d.v[267] = work1d.L[26]*work1d.d[267];
  work1d.v[347] = work1d.KKT[693]-work1d.L[26]*work1d.v[267];
  work1d.d[347] = work1d.v[347];
  if (work1d.d[347] > 0)
    work1d.d[347] = -settings1d.kkt_reg;
  else
    work1d.d[347] -= settings1d.kkt_reg;
  work1d.d_inv[347] = 1/work1d.d[347];
  work1d.L[1262] = (work1d.KKT[694])*work1d.d_inv[347];
  work1d.v[268] = work1d.L[27]*work1d.d[268];
  work1d.v[348] = work1d.KKT[695]-work1d.L[27]*work1d.v[268];
  work1d.d[348] = work1d.v[348];
  if (work1d.d[348] > 0)
    work1d.d[348] = -settings1d.kkt_reg;
  else
    work1d.d[348] -= settings1d.kkt_reg;
  work1d.d_inv[348] = 1/work1d.d[348];
  work1d.L[1284] = (work1d.KKT[696])*work1d.d_inv[348];
  work1d.v[269] = work1d.L[28]*work1d.d[269];
  work1d.v[349] = work1d.KKT[697]-work1d.L[28]*work1d.v[269];
  work1d.d[349] = work1d.v[349];
  if (work1d.d[349] > 0)
    work1d.d[349] = -settings1d.kkt_reg;
  else
    work1d.d[349] -= settings1d.kkt_reg;
  work1d.d_inv[349] = 1/work1d.d[349];
  work1d.L[1306] = (work1d.KKT[698])*work1d.d_inv[349];
  work1d.v[270] = work1d.L[29]*work1d.d[270];
  work1d.v[350] = work1d.KKT[699]-work1d.L[29]*work1d.v[270];
  work1d.d[350] = work1d.v[350];
  if (work1d.d[350] > 0)
    work1d.d[350] = -settings1d.kkt_reg;
  else
    work1d.d[350] -= settings1d.kkt_reg;
  work1d.d_inv[350] = 1/work1d.d[350];
  work1d.L[1328] = (work1d.KKT[700])*work1d.d_inv[350];
  work1d.v[271] = work1d.L[30]*work1d.d[271];
  work1d.v[351] = work1d.KKT[701]-work1d.L[30]*work1d.v[271];
  work1d.d[351] = work1d.v[351];
  if (work1d.d[351] > 0)
    work1d.d[351] = -settings1d.kkt_reg;
  else
    work1d.d[351] -= settings1d.kkt_reg;
  work1d.d_inv[351] = 1/work1d.d[351];
  work1d.L[1350] = (work1d.KKT[702])*work1d.d_inv[351];
  work1d.v[272] = work1d.L[31]*work1d.d[272];
  work1d.v[352] = work1d.KKT[703]-work1d.L[31]*work1d.v[272];
  work1d.d[352] = work1d.v[352];
  if (work1d.d[352] > 0)
    work1d.d[352] = -settings1d.kkt_reg;
  else
    work1d.d[352] -= settings1d.kkt_reg;
  work1d.d_inv[352] = 1/work1d.d[352];
  work1d.L[1372] = (work1d.KKT[704])*work1d.d_inv[352];
  work1d.v[273] = work1d.L[32]*work1d.d[273];
  work1d.v[353] = work1d.KKT[705]-work1d.L[32]*work1d.v[273];
  work1d.d[353] = work1d.v[353];
  if (work1d.d[353] > 0)
    work1d.d[353] = -settings1d.kkt_reg;
  else
    work1d.d[353] -= settings1d.kkt_reg;
  work1d.d_inv[353] = 1/work1d.d[353];
  work1d.L[1394] = (work1d.KKT[706])*work1d.d_inv[353];
  work1d.v[274] = work1d.L[33]*work1d.d[274];
  work1d.v[354] = work1d.KKT[707]-work1d.L[33]*work1d.v[274];
  work1d.d[354] = work1d.v[354];
  if (work1d.d[354] > 0)
    work1d.d[354] = -settings1d.kkt_reg;
  else
    work1d.d[354] -= settings1d.kkt_reg;
  work1d.d_inv[354] = 1/work1d.d[354];
  work1d.L[1416] = (work1d.KKT[708])*work1d.d_inv[354];
  work1d.v[275] = work1d.L[34]*work1d.d[275];
  work1d.v[355] = work1d.KKT[709]-work1d.L[34]*work1d.v[275];
  work1d.d[355] = work1d.v[355];
  if (work1d.d[355] > 0)
    work1d.d[355] = -settings1d.kkt_reg;
  else
    work1d.d[355] -= settings1d.kkt_reg;
  work1d.d_inv[355] = 1/work1d.d[355];
  work1d.L[1438] = (work1d.KKT[710])*work1d.d_inv[355];
  work1d.v[276] = work1d.L[35]*work1d.d[276];
  work1d.v[356] = work1d.KKT[711]-work1d.L[35]*work1d.v[276];
  work1d.d[356] = work1d.v[356];
  if (work1d.d[356] > 0)
    work1d.d[356] = -settings1d.kkt_reg;
  else
    work1d.d[356] -= settings1d.kkt_reg;
  work1d.d_inv[356] = 1/work1d.d[356];
  work1d.L[1460] = (work1d.KKT[712])*work1d.d_inv[356];
  work1d.v[277] = work1d.L[36]*work1d.d[277];
  work1d.v[357] = work1d.KKT[713]-work1d.L[36]*work1d.v[277];
  work1d.d[357] = work1d.v[357];
  if (work1d.d[357] > 0)
    work1d.d[357] = -settings1d.kkt_reg;
  else
    work1d.d[357] -= settings1d.kkt_reg;
  work1d.d_inv[357] = 1/work1d.d[357];
  work1d.L[1482] = (work1d.KKT[714])*work1d.d_inv[357];
  work1d.v[278] = work1d.L[37]*work1d.d[278];
  work1d.v[358] = work1d.KKT[715]-work1d.L[37]*work1d.v[278];
  work1d.d[358] = work1d.v[358];
  if (work1d.d[358] > 0)
    work1d.d[358] = -settings1d.kkt_reg;
  else
    work1d.d[358] -= settings1d.kkt_reg;
  work1d.d_inv[358] = 1/work1d.d[358];
  work1d.L[1508] = (work1d.KKT[716])*work1d.d_inv[358];
  work1d.v[279] = work1d.L[38]*work1d.d[279];
  work1d.v[359] = work1d.KKT[717]-work1d.L[38]*work1d.v[279];
  work1d.d[359] = work1d.v[359];
  if (work1d.d[359] > 0)
    work1d.d[359] = -settings1d.kkt_reg;
  else
    work1d.d[359] -= settings1d.kkt_reg;
  work1d.d_inv[359] = 1/work1d.d[359];
  work1d.L[1526] = (work1d.KKT[718])*work1d.d_inv[359];
  work1d.v[280] = work1d.L[39]*work1d.d[280];
  work1d.v[360] = work1d.KKT[719]-work1d.L[39]*work1d.v[280];
  work1d.d[360] = work1d.v[360];
  if (work1d.d[360] > 0)
    work1d.d[360] = -settings1d.kkt_reg;
  else
    work1d.d[360] -= settings1d.kkt_reg;
  work1d.d_inv[360] = 1/work1d.d[360];
  work1d.L[362] = (work1d.KKT[720])*work1d.d_inv[360];
  work1d.v[281] = work1d.L[40]*work1d.d[281];
  work1d.v[361] = work1d.KKT[721]-work1d.L[40]*work1d.v[281];
  work1d.d[361] = work1d.v[361];
  if (work1d.d[361] > 0)
    work1d.d[361] = -settings1d.kkt_reg;
  else
    work1d.d[361] -= settings1d.kkt_reg;
  work1d.d_inv[361] = 1/work1d.d[361];
  work1d.L[703] = (work1d.KKT[722])*work1d.d_inv[361];
  work1d.v[282] = work1d.L[41]*work1d.d[282];
  work1d.v[362] = work1d.KKT[723]-work1d.L[41]*work1d.v[282];
  work1d.d[362] = work1d.v[362];
  if (work1d.d[362] > 0)
    work1d.d[362] = -settings1d.kkt_reg;
  else
    work1d.d[362] -= settings1d.kkt_reg;
  work1d.d_inv[362] = 1/work1d.d[362];
  work1d.L[718] = (work1d.KKT[724])*work1d.d_inv[362];
  work1d.v[283] = work1d.L[42]*work1d.d[283];
  work1d.v[363] = work1d.KKT[725]-work1d.L[42]*work1d.v[283];
  work1d.d[363] = work1d.v[363];
  if (work1d.d[363] > 0)
    work1d.d[363] = -settings1d.kkt_reg;
  else
    work1d.d[363] -= settings1d.kkt_reg;
  work1d.d_inv[363] = 1/work1d.d[363];
  work1d.L[738] = (work1d.KKT[726])*work1d.d_inv[363];
  work1d.v[284] = work1d.L[43]*work1d.d[284];
  work1d.v[364] = work1d.KKT[727]-work1d.L[43]*work1d.v[284];
  work1d.d[364] = work1d.v[364];
  if (work1d.d[364] > 0)
    work1d.d[364] = -settings1d.kkt_reg;
  else
    work1d.d[364] -= settings1d.kkt_reg;
  work1d.d_inv[364] = 1/work1d.d[364];
  work1d.L[760] = (work1d.KKT[728])*work1d.d_inv[364];
  work1d.v[285] = work1d.L[44]*work1d.d[285];
  work1d.v[365] = work1d.KKT[729]-work1d.L[44]*work1d.v[285];
  work1d.d[365] = work1d.v[365];
  if (work1d.d[365] > 0)
    work1d.d[365] = -settings1d.kkt_reg;
  else
    work1d.d[365] -= settings1d.kkt_reg;
  work1d.d_inv[365] = 1/work1d.d[365];
  work1d.L[782] = (work1d.KKT[730])*work1d.d_inv[365];
  work1d.v[286] = work1d.L[45]*work1d.d[286];
  work1d.v[366] = work1d.KKT[731]-work1d.L[45]*work1d.v[286];
  work1d.d[366] = work1d.v[366];
  if (work1d.d[366] > 0)
    work1d.d[366] = -settings1d.kkt_reg;
  else
    work1d.d[366] -= settings1d.kkt_reg;
  work1d.d_inv[366] = 1/work1d.d[366];
  work1d.L[804] = (work1d.KKT[732])*work1d.d_inv[366];
  work1d.v[287] = work1d.L[46]*work1d.d[287];
  work1d.v[367] = work1d.KKT[733]-work1d.L[46]*work1d.v[287];
  work1d.d[367] = work1d.v[367];
  if (work1d.d[367] > 0)
    work1d.d[367] = -settings1d.kkt_reg;
  else
    work1d.d[367] -= settings1d.kkt_reg;
  work1d.d_inv[367] = 1/work1d.d[367];
  work1d.L[826] = (work1d.KKT[734])*work1d.d_inv[367];
  work1d.v[288] = work1d.L[47]*work1d.d[288];
  work1d.v[368] = work1d.KKT[735]-work1d.L[47]*work1d.v[288];
  work1d.d[368] = work1d.v[368];
  if (work1d.d[368] > 0)
    work1d.d[368] = -settings1d.kkt_reg;
  else
    work1d.d[368] -= settings1d.kkt_reg;
  work1d.d_inv[368] = 1/work1d.d[368];
  work1d.L[848] = (work1d.KKT[736])*work1d.d_inv[368];
  work1d.v[289] = work1d.L[48]*work1d.d[289];
  work1d.v[369] = work1d.KKT[737]-work1d.L[48]*work1d.v[289];
  work1d.d[369] = work1d.v[369];
  if (work1d.d[369] > 0)
    work1d.d[369] = -settings1d.kkt_reg;
  else
    work1d.d[369] -= settings1d.kkt_reg;
  work1d.d_inv[369] = 1/work1d.d[369];
  work1d.L[870] = (work1d.KKT[738])*work1d.d_inv[369];
  work1d.v[290] = work1d.L[49]*work1d.d[290];
  work1d.v[370] = work1d.KKT[739]-work1d.L[49]*work1d.v[290];
  work1d.d[370] = work1d.v[370];
  if (work1d.d[370] > 0)
    work1d.d[370] = -settings1d.kkt_reg;
  else
    work1d.d[370] -= settings1d.kkt_reg;
  work1d.d_inv[370] = 1/work1d.d[370];
  work1d.L[892] = (work1d.KKT[740])*work1d.d_inv[370];
  work1d.v[291] = work1d.L[50]*work1d.d[291];
  work1d.v[371] = work1d.KKT[741]-work1d.L[50]*work1d.v[291];
  work1d.d[371] = work1d.v[371];
  if (work1d.d[371] > 0)
    work1d.d[371] = -settings1d.kkt_reg;
  else
    work1d.d[371] -= settings1d.kkt_reg;
  work1d.d_inv[371] = 1/work1d.d[371];
  work1d.L[914] = (work1d.KKT[742])*work1d.d_inv[371];
  work1d.v[292] = work1d.L[51]*work1d.d[292];
  work1d.v[372] = work1d.KKT[743]-work1d.L[51]*work1d.v[292];
  work1d.d[372] = work1d.v[372];
  if (work1d.d[372] > 0)
    work1d.d[372] = -settings1d.kkt_reg;
  else
    work1d.d[372] -= settings1d.kkt_reg;
  work1d.d_inv[372] = 1/work1d.d[372];
  work1d.L[936] = (work1d.KKT[744])*work1d.d_inv[372];
  work1d.v[293] = work1d.L[52]*work1d.d[293];
  work1d.v[373] = work1d.KKT[745]-work1d.L[52]*work1d.v[293];
  work1d.d[373] = work1d.v[373];
  if (work1d.d[373] > 0)
    work1d.d[373] = -settings1d.kkt_reg;
  else
    work1d.d[373] -= settings1d.kkt_reg;
  work1d.d_inv[373] = 1/work1d.d[373];
  work1d.L[958] = (work1d.KKT[746])*work1d.d_inv[373];
  work1d.v[294] = work1d.L[53]*work1d.d[294];
  work1d.v[374] = work1d.KKT[747]-work1d.L[53]*work1d.v[294];
  work1d.d[374] = work1d.v[374];
  if (work1d.d[374] > 0)
    work1d.d[374] = -settings1d.kkt_reg;
  else
    work1d.d[374] -= settings1d.kkt_reg;
  work1d.d_inv[374] = 1/work1d.d[374];
  work1d.L[980] = (work1d.KKT[748])*work1d.d_inv[374];
  work1d.v[295] = work1d.L[54]*work1d.d[295];
  work1d.v[375] = work1d.KKT[749]-work1d.L[54]*work1d.v[295];
  work1d.d[375] = work1d.v[375];
  if (work1d.d[375] > 0)
    work1d.d[375] = -settings1d.kkt_reg;
  else
    work1d.d[375] -= settings1d.kkt_reg;
  work1d.d_inv[375] = 1/work1d.d[375];
  work1d.L[1002] = (work1d.KKT[750])*work1d.d_inv[375];
  work1d.v[296] = work1d.L[55]*work1d.d[296];
  work1d.v[376] = work1d.KKT[751]-work1d.L[55]*work1d.v[296];
  work1d.d[376] = work1d.v[376];
  if (work1d.d[376] > 0)
    work1d.d[376] = -settings1d.kkt_reg;
  else
    work1d.d[376] -= settings1d.kkt_reg;
  work1d.d_inv[376] = 1/work1d.d[376];
  work1d.L[1024] = (work1d.KKT[752])*work1d.d_inv[376];
  work1d.v[297] = work1d.L[56]*work1d.d[297];
  work1d.v[377] = work1d.KKT[753]-work1d.L[56]*work1d.v[297];
  work1d.d[377] = work1d.v[377];
  if (work1d.d[377] > 0)
    work1d.d[377] = -settings1d.kkt_reg;
  else
    work1d.d[377] -= settings1d.kkt_reg;
  work1d.d_inv[377] = 1/work1d.d[377];
  work1d.L[1046] = (work1d.KKT[754])*work1d.d_inv[377];
  work1d.v[298] = work1d.L[57]*work1d.d[298];
  work1d.v[378] = work1d.KKT[755]-work1d.L[57]*work1d.v[298];
  work1d.d[378] = work1d.v[378];
  if (work1d.d[378] > 0)
    work1d.d[378] = -settings1d.kkt_reg;
  else
    work1d.d[378] -= settings1d.kkt_reg;
  work1d.d_inv[378] = 1/work1d.d[378];
  work1d.L[1068] = (work1d.KKT[756])*work1d.d_inv[378];
  work1d.v[299] = work1d.L[58]*work1d.d[299];
  work1d.v[379] = work1d.KKT[757]-work1d.L[58]*work1d.v[299];
  work1d.d[379] = work1d.v[379];
  if (work1d.d[379] > 0)
    work1d.d[379] = -settings1d.kkt_reg;
  else
    work1d.d[379] -= settings1d.kkt_reg;
  work1d.d_inv[379] = 1/work1d.d[379];
  work1d.L[1090] = (work1d.KKT[758])*work1d.d_inv[379];
  work1d.v[300] = work1d.L[59]*work1d.d[300];
  work1d.v[380] = work1d.KKT[759]-work1d.L[59]*work1d.v[300];
  work1d.d[380] = work1d.v[380];
  if (work1d.d[380] > 0)
    work1d.d[380] = -settings1d.kkt_reg;
  else
    work1d.d[380] -= settings1d.kkt_reg;
  work1d.d_inv[380] = 1/work1d.d[380];
  work1d.L[1112] = (work1d.KKT[760])*work1d.d_inv[380];
  work1d.v[301] = work1d.L[60]*work1d.d[301];
  work1d.v[381] = work1d.KKT[761]-work1d.L[60]*work1d.v[301];
  work1d.d[381] = work1d.v[381];
  if (work1d.d[381] > 0)
    work1d.d[381] = -settings1d.kkt_reg;
  else
    work1d.d[381] -= settings1d.kkt_reg;
  work1d.d_inv[381] = 1/work1d.d[381];
  work1d.L[1134] = (work1d.KKT[762])*work1d.d_inv[381];
  work1d.v[302] = work1d.L[61]*work1d.d[302];
  work1d.v[382] = work1d.KKT[763]-work1d.L[61]*work1d.v[302];
  work1d.d[382] = work1d.v[382];
  if (work1d.d[382] > 0)
    work1d.d[382] = -settings1d.kkt_reg;
  else
    work1d.d[382] -= settings1d.kkt_reg;
  work1d.d_inv[382] = 1/work1d.d[382];
  work1d.L[1156] = (work1d.KKT[764])*work1d.d_inv[382];
  work1d.v[303] = work1d.L[62]*work1d.d[303];
  work1d.v[383] = work1d.KKT[765]-work1d.L[62]*work1d.v[303];
  work1d.d[383] = work1d.v[383];
  if (work1d.d[383] > 0)
    work1d.d[383] = -settings1d.kkt_reg;
  else
    work1d.d[383] -= settings1d.kkt_reg;
  work1d.d_inv[383] = 1/work1d.d[383];
  work1d.L[1178] = (work1d.KKT[766])*work1d.d_inv[383];
  work1d.v[304] = work1d.L[63]*work1d.d[304];
  work1d.v[384] = work1d.KKT[767]-work1d.L[63]*work1d.v[304];
  work1d.d[384] = work1d.v[384];
  if (work1d.d[384] > 0)
    work1d.d[384] = -settings1d.kkt_reg;
  else
    work1d.d[384] -= settings1d.kkt_reg;
  work1d.d_inv[384] = 1/work1d.d[384];
  work1d.L[1200] = (work1d.KKT[768])*work1d.d_inv[384];
  work1d.v[305] = work1d.L[64]*work1d.d[305];
  work1d.v[385] = work1d.KKT[769]-work1d.L[64]*work1d.v[305];
  work1d.d[385] = work1d.v[385];
  if (work1d.d[385] > 0)
    work1d.d[385] = -settings1d.kkt_reg;
  else
    work1d.d[385] -= settings1d.kkt_reg;
  work1d.d_inv[385] = 1/work1d.d[385];
  work1d.L[1222] = (work1d.KKT[770])*work1d.d_inv[385];
  work1d.v[306] = work1d.L[65]*work1d.d[306];
  work1d.v[386] = work1d.KKT[771]-work1d.L[65]*work1d.v[306];
  work1d.d[386] = work1d.v[386];
  if (work1d.d[386] > 0)
    work1d.d[386] = -settings1d.kkt_reg;
  else
    work1d.d[386] -= settings1d.kkt_reg;
  work1d.d_inv[386] = 1/work1d.d[386];
  work1d.L[1244] = (work1d.KKT[772])*work1d.d_inv[386];
  work1d.v[307] = work1d.L[66]*work1d.d[307];
  work1d.v[387] = work1d.KKT[773]-work1d.L[66]*work1d.v[307];
  work1d.d[387] = work1d.v[387];
  if (work1d.d[387] > 0)
    work1d.d[387] = -settings1d.kkt_reg;
  else
    work1d.d[387] -= settings1d.kkt_reg;
  work1d.d_inv[387] = 1/work1d.d[387];
  work1d.L[1266] = (work1d.KKT[774])*work1d.d_inv[387];
  work1d.v[308] = work1d.L[67]*work1d.d[308];
  work1d.v[388] = work1d.KKT[775]-work1d.L[67]*work1d.v[308];
  work1d.d[388] = work1d.v[388];
  if (work1d.d[388] > 0)
    work1d.d[388] = -settings1d.kkt_reg;
  else
    work1d.d[388] -= settings1d.kkt_reg;
  work1d.d_inv[388] = 1/work1d.d[388];
  work1d.L[1288] = (work1d.KKT[776])*work1d.d_inv[388];
  work1d.v[309] = work1d.L[68]*work1d.d[309];
  work1d.v[389] = work1d.KKT[777]-work1d.L[68]*work1d.v[309];
  work1d.d[389] = work1d.v[389];
  if (work1d.d[389] > 0)
    work1d.d[389] = -settings1d.kkt_reg;
  else
    work1d.d[389] -= settings1d.kkt_reg;
  work1d.d_inv[389] = 1/work1d.d[389];
  work1d.L[1310] = (work1d.KKT[778])*work1d.d_inv[389];
  work1d.v[310] = work1d.L[69]*work1d.d[310];
  work1d.v[390] = work1d.KKT[779]-work1d.L[69]*work1d.v[310];
  work1d.d[390] = work1d.v[390];
  if (work1d.d[390] > 0)
    work1d.d[390] = -settings1d.kkt_reg;
  else
    work1d.d[390] -= settings1d.kkt_reg;
  work1d.d_inv[390] = 1/work1d.d[390];
  work1d.L[1332] = (work1d.KKT[780])*work1d.d_inv[390];
  work1d.v[311] = work1d.L[70]*work1d.d[311];
  work1d.v[391] = work1d.KKT[781]-work1d.L[70]*work1d.v[311];
  work1d.d[391] = work1d.v[391];
  if (work1d.d[391] > 0)
    work1d.d[391] = -settings1d.kkt_reg;
  else
    work1d.d[391] -= settings1d.kkt_reg;
  work1d.d_inv[391] = 1/work1d.d[391];
  work1d.L[1354] = (work1d.KKT[782])*work1d.d_inv[391];
  work1d.v[312] = work1d.L[71]*work1d.d[312];
  work1d.v[392] = work1d.KKT[783]-work1d.L[71]*work1d.v[312];
  work1d.d[392] = work1d.v[392];
  if (work1d.d[392] > 0)
    work1d.d[392] = -settings1d.kkt_reg;
  else
    work1d.d[392] -= settings1d.kkt_reg;
  work1d.d_inv[392] = 1/work1d.d[392];
  work1d.L[1376] = (work1d.KKT[784])*work1d.d_inv[392];
  work1d.v[313] = work1d.L[72]*work1d.d[313];
  work1d.v[393] = work1d.KKT[785]-work1d.L[72]*work1d.v[313];
  work1d.d[393] = work1d.v[393];
  if (work1d.d[393] > 0)
    work1d.d[393] = -settings1d.kkt_reg;
  else
    work1d.d[393] -= settings1d.kkt_reg;
  work1d.d_inv[393] = 1/work1d.d[393];
  work1d.L[1398] = (work1d.KKT[786])*work1d.d_inv[393];
  work1d.v[314] = work1d.L[73]*work1d.d[314];
  work1d.v[394] = work1d.KKT[787]-work1d.L[73]*work1d.v[314];
  work1d.d[394] = work1d.v[394];
  if (work1d.d[394] > 0)
    work1d.d[394] = -settings1d.kkt_reg;
  else
    work1d.d[394] -= settings1d.kkt_reg;
  work1d.d_inv[394] = 1/work1d.d[394];
  work1d.L[1420] = (work1d.KKT[788])*work1d.d_inv[394];
  work1d.v[315] = work1d.L[74]*work1d.d[315];
  work1d.v[395] = work1d.KKT[789]-work1d.L[74]*work1d.v[315];
  work1d.d[395] = work1d.v[395];
  if (work1d.d[395] > 0)
    work1d.d[395] = -settings1d.kkt_reg;
  else
    work1d.d[395] -= settings1d.kkt_reg;
  work1d.d_inv[395] = 1/work1d.d[395];
  work1d.L[1442] = (work1d.KKT[790])*work1d.d_inv[395];
  work1d.v[316] = work1d.L[75]*work1d.d[316];
  work1d.v[396] = work1d.KKT[791]-work1d.L[75]*work1d.v[316];
  work1d.d[396] = work1d.v[396];
  if (work1d.d[396] > 0)
    work1d.d[396] = -settings1d.kkt_reg;
  else
    work1d.d[396] -= settings1d.kkt_reg;
  work1d.d_inv[396] = 1/work1d.d[396];
  work1d.L[1464] = (work1d.KKT[792])*work1d.d_inv[396];
  work1d.v[317] = work1d.L[76]*work1d.d[317];
  work1d.v[397] = work1d.KKT[793]-work1d.L[76]*work1d.v[317];
  work1d.d[397] = work1d.v[397];
  if (work1d.d[397] > 0)
    work1d.d[397] = -settings1d.kkt_reg;
  else
    work1d.d[397] -= settings1d.kkt_reg;
  work1d.d_inv[397] = 1/work1d.d[397];
  work1d.L[1486] = (work1d.KKT[794])*work1d.d_inv[397];
  work1d.v[318] = work1d.L[77]*work1d.d[318];
  work1d.v[398] = work1d.KKT[795]-work1d.L[77]*work1d.v[318];
  work1d.d[398] = work1d.v[398];
  if (work1d.d[398] > 0)
    work1d.d[398] = -settings1d.kkt_reg;
  else
    work1d.d[398] -= settings1d.kkt_reg;
  work1d.d_inv[398] = 1/work1d.d[398];
  work1d.L[1514] = (work1d.KKT[796])*work1d.d_inv[398];
  work1d.v[319] = work1d.L[78]*work1d.d[319];
  work1d.v[399] = work1d.KKT[797]-work1d.L[78]*work1d.v[319];
  work1d.d[399] = work1d.v[399];
  if (work1d.d[399] > 0)
    work1d.d[399] = -settings1d.kkt_reg;
  else
    work1d.d[399] -= settings1d.kkt_reg;
  work1d.d_inv[399] = 1/work1d.d[399];
  work1d.L[650] = (work1d.KKT[798])*work1d.d_inv[399];
  work1d.v[320] = work1d.L[79]*work1d.d[320];
  work1d.v[400] = work1d.KKT[799]-work1d.L[79]*work1d.v[320];
  work1d.d[400] = work1d.v[400];
  if (work1d.d[400] > 0)
    work1d.d[400] = -settings1d.kkt_reg;
  else
    work1d.d[400] -= settings1d.kkt_reg;
  work1d.d_inv[400] = 1/work1d.d[400];
  work1d.L[645] = (work1d.KKT[800])*work1d.d_inv[400];
  work1d.v[401] = 0;
  work1d.d[401] = work1d.v[401];
  if (work1d.d[401] > 0)
    work1d.d[401] = -settings1d.kkt_reg;
  else
    work1d.d[401] -= settings1d.kkt_reg;
  work1d.d_inv[401] = 1/work1d.d[401];
  work1d.L[81] = (work1d.KKT[801])*work1d.d_inv[401];
  work1d.v[402] = 0;
  work1d.d[402] = work1d.v[402];
  if (work1d.d[402] > 0)
    work1d.d[402] = -settings1d.kkt_reg;
  else
    work1d.d[402] -= settings1d.kkt_reg;
  work1d.d_inv[402] = 1/work1d.d[402];
  work1d.L[699] = (work1d.KKT[802])*work1d.d_inv[402];
  work1d.v[403] = 0;
  work1d.d[403] = work1d.v[403];
  if (work1d.d[403] < 0)
    work1d.d[403] = settings1d.kkt_reg;
  else
    work1d.d[403] += settings1d.kkt_reg;
  work1d.d_inv[403] = 1/work1d.d[403];
  work1d.L[80] = (work1d.KKT[803])*work1d.d_inv[403];
  work1d.v[403] = work1d.L[80]*work1d.d[403];
  work1d.v[404] = 0-work1d.L[80]*work1d.v[403];
  work1d.d[404] = work1d.v[404];
  if (work1d.d[404] > 0)
    work1d.d[404] = -settings1d.kkt_reg;
  else
    work1d.d[404] -= settings1d.kkt_reg;
  work1d.d_inv[404] = 1/work1d.d[404];
  work1d.L[704] = (work1d.KKT[804])*work1d.d_inv[404];
  work1d.v[405] = work1d.KKT[805];
  work1d.d[405] = work1d.v[405];
  if (work1d.d[405] < 0)
    work1d.d[405] = settings1d.kkt_reg;
  else
    work1d.d[405] += settings1d.kkt_reg;
  work1d.d_inv[405] = 1/work1d.d[405];
  work1d.L[655] = (work1d.KKT[806])*work1d.d_inv[405];
  work1d.v[406] = work1d.KKT[807];
  work1d.d[406] = work1d.v[406];
  if (work1d.d[406] < 0)
    work1d.d[406] = settings1d.kkt_reg;
  else
    work1d.d[406] += settings1d.kkt_reg;
  work1d.d_inv[406] = 1/work1d.d[406];
  work1d.L[656] = (work1d.KKT[808])*work1d.d_inv[406];
  work1d.v[407] = work1d.KKT[809];
  work1d.d[407] = work1d.v[407];
  if (work1d.d[407] < 0)
    work1d.d[407] = settings1d.kkt_reg;
  else
    work1d.d[407] += settings1d.kkt_reg;
  work1d.d_inv[407] = 1/work1d.d[407];
  work1d.L[657] = (work1d.KKT[810])*work1d.d_inv[407];
  work1d.v[408] = work1d.KKT[811];
  work1d.d[408] = work1d.v[408];
  if (work1d.d[408] < 0)
    work1d.d[408] = settings1d.kkt_reg;
  else
    work1d.d[408] += settings1d.kkt_reg;
  work1d.d_inv[408] = 1/work1d.d[408];
  work1d.L[658] = (work1d.KKT[812])*work1d.d_inv[408];
  work1d.v[409] = work1d.KKT[813];
  work1d.d[409] = work1d.v[409];
  if (work1d.d[409] < 0)
    work1d.d[409] = settings1d.kkt_reg;
  else
    work1d.d[409] += settings1d.kkt_reg;
  work1d.d_inv[409] = 1/work1d.d[409];
  work1d.L[659] = (work1d.KKT[814])*work1d.d_inv[409];
  work1d.v[410] = work1d.KKT[815];
  work1d.d[410] = work1d.v[410];
  if (work1d.d[410] < 0)
    work1d.d[410] = settings1d.kkt_reg;
  else
    work1d.d[410] += settings1d.kkt_reg;
  work1d.d_inv[410] = 1/work1d.d[410];
  work1d.L[660] = (work1d.KKT[816])*work1d.d_inv[410];
  work1d.v[411] = work1d.KKT[817];
  work1d.d[411] = work1d.v[411];
  if (work1d.d[411] < 0)
    work1d.d[411] = settings1d.kkt_reg;
  else
    work1d.d[411] += settings1d.kkt_reg;
  work1d.d_inv[411] = 1/work1d.d[411];
  work1d.L[661] = (work1d.KKT[818])*work1d.d_inv[411];
  work1d.v[412] = work1d.KKT[819];
  work1d.d[412] = work1d.v[412];
  if (work1d.d[412] < 0)
    work1d.d[412] = settings1d.kkt_reg;
  else
    work1d.d[412] += settings1d.kkt_reg;
  work1d.d_inv[412] = 1/work1d.d[412];
  work1d.L[662] = (work1d.KKT[820])*work1d.d_inv[412];
  work1d.v[413] = work1d.KKT[821];
  work1d.d[413] = work1d.v[413];
  if (work1d.d[413] < 0)
    work1d.d[413] = settings1d.kkt_reg;
  else
    work1d.d[413] += settings1d.kkt_reg;
  work1d.d_inv[413] = 1/work1d.d[413];
  work1d.L[663] = (work1d.KKT[822])*work1d.d_inv[413];
  work1d.v[414] = work1d.KKT[823];
  work1d.d[414] = work1d.v[414];
  if (work1d.d[414] < 0)
    work1d.d[414] = settings1d.kkt_reg;
  else
    work1d.d[414] += settings1d.kkt_reg;
  work1d.d_inv[414] = 1/work1d.d[414];
  work1d.L[664] = (work1d.KKT[824])*work1d.d_inv[414];
  work1d.v[415] = work1d.KKT[825];
  work1d.d[415] = work1d.v[415];
  if (work1d.d[415] < 0)
    work1d.d[415] = settings1d.kkt_reg;
  else
    work1d.d[415] += settings1d.kkt_reg;
  work1d.d_inv[415] = 1/work1d.d[415];
  work1d.L[665] = (work1d.KKT[826])*work1d.d_inv[415];
  work1d.v[416] = work1d.KKT[827];
  work1d.d[416] = work1d.v[416];
  if (work1d.d[416] < 0)
    work1d.d[416] = settings1d.kkt_reg;
  else
    work1d.d[416] += settings1d.kkt_reg;
  work1d.d_inv[416] = 1/work1d.d[416];
  work1d.L[666] = (work1d.KKT[828])*work1d.d_inv[416];
  work1d.v[417] = work1d.KKT[829];
  work1d.d[417] = work1d.v[417];
  if (work1d.d[417] < 0)
    work1d.d[417] = settings1d.kkt_reg;
  else
    work1d.d[417] += settings1d.kkt_reg;
  work1d.d_inv[417] = 1/work1d.d[417];
  work1d.L[667] = (work1d.KKT[830])*work1d.d_inv[417];
  work1d.v[418] = work1d.KKT[831];
  work1d.d[418] = work1d.v[418];
  if (work1d.d[418] < 0)
    work1d.d[418] = settings1d.kkt_reg;
  else
    work1d.d[418] += settings1d.kkt_reg;
  work1d.d_inv[418] = 1/work1d.d[418];
  work1d.L[668] = (work1d.KKT[832])*work1d.d_inv[418];
  work1d.v[419] = work1d.KKT[833];
  work1d.d[419] = work1d.v[419];
  if (work1d.d[419] < 0)
    work1d.d[419] = settings1d.kkt_reg;
  else
    work1d.d[419] += settings1d.kkt_reg;
  work1d.d_inv[419] = 1/work1d.d[419];
  work1d.L[669] = (work1d.KKT[834])*work1d.d_inv[419];
  work1d.v[420] = work1d.KKT[835];
  work1d.d[420] = work1d.v[420];
  if (work1d.d[420] < 0)
    work1d.d[420] = settings1d.kkt_reg;
  else
    work1d.d[420] += settings1d.kkt_reg;
  work1d.d_inv[420] = 1/work1d.d[420];
  work1d.L[670] = (work1d.KKT[836])*work1d.d_inv[420];
  work1d.v[421] = work1d.KKT[837];
  work1d.d[421] = work1d.v[421];
  if (work1d.d[421] < 0)
    work1d.d[421] = settings1d.kkt_reg;
  else
    work1d.d[421] += settings1d.kkt_reg;
  work1d.d_inv[421] = 1/work1d.d[421];
  work1d.L[671] = (work1d.KKT[838])*work1d.d_inv[421];
  work1d.v[422] = work1d.KKT[839];
  work1d.d[422] = work1d.v[422];
  if (work1d.d[422] < 0)
    work1d.d[422] = settings1d.kkt_reg;
  else
    work1d.d[422] += settings1d.kkt_reg;
  work1d.d_inv[422] = 1/work1d.d[422];
  work1d.L[672] = (work1d.KKT[840])*work1d.d_inv[422];
  work1d.v[423] = work1d.KKT[841];
  work1d.d[423] = work1d.v[423];
  if (work1d.d[423] < 0)
    work1d.d[423] = settings1d.kkt_reg;
  else
    work1d.d[423] += settings1d.kkt_reg;
  work1d.d_inv[423] = 1/work1d.d[423];
  work1d.L[673] = (work1d.KKT[842])*work1d.d_inv[423];
  work1d.v[424] = work1d.KKT[843];
  work1d.d[424] = work1d.v[424];
  if (work1d.d[424] < 0)
    work1d.d[424] = settings1d.kkt_reg;
  else
    work1d.d[424] += settings1d.kkt_reg;
  work1d.d_inv[424] = 1/work1d.d[424];
  work1d.L[674] = (work1d.KKT[844])*work1d.d_inv[424];
  work1d.v[425] = work1d.KKT[845];
  work1d.d[425] = work1d.v[425];
  if (work1d.d[425] < 0)
    work1d.d[425] = settings1d.kkt_reg;
  else
    work1d.d[425] += settings1d.kkt_reg;
  work1d.d_inv[425] = 1/work1d.d[425];
  work1d.L[675] = (work1d.KKT[846])*work1d.d_inv[425];
  work1d.v[426] = work1d.KKT[847];
  work1d.d[426] = work1d.v[426];
  if (work1d.d[426] < 0)
    work1d.d[426] = settings1d.kkt_reg;
  else
    work1d.d[426] += settings1d.kkt_reg;
  work1d.d_inv[426] = 1/work1d.d[426];
  work1d.L[676] = (work1d.KKT[848])*work1d.d_inv[426];
  work1d.v[427] = work1d.KKT[849];
  work1d.d[427] = work1d.v[427];
  if (work1d.d[427] < 0)
    work1d.d[427] = settings1d.kkt_reg;
  else
    work1d.d[427] += settings1d.kkt_reg;
  work1d.d_inv[427] = 1/work1d.d[427];
  work1d.L[677] = (work1d.KKT[850])*work1d.d_inv[427];
  work1d.v[428] = work1d.KKT[851];
  work1d.d[428] = work1d.v[428];
  if (work1d.d[428] < 0)
    work1d.d[428] = settings1d.kkt_reg;
  else
    work1d.d[428] += settings1d.kkt_reg;
  work1d.d_inv[428] = 1/work1d.d[428];
  work1d.L[678] = (work1d.KKT[852])*work1d.d_inv[428];
  work1d.v[429] = work1d.KKT[853];
  work1d.d[429] = work1d.v[429];
  if (work1d.d[429] < 0)
    work1d.d[429] = settings1d.kkt_reg;
  else
    work1d.d[429] += settings1d.kkt_reg;
  work1d.d_inv[429] = 1/work1d.d[429];
  work1d.L[679] = (work1d.KKT[854])*work1d.d_inv[429];
  work1d.v[430] = work1d.KKT[855];
  work1d.d[430] = work1d.v[430];
  if (work1d.d[430] < 0)
    work1d.d[430] = settings1d.kkt_reg;
  else
    work1d.d[430] += settings1d.kkt_reg;
  work1d.d_inv[430] = 1/work1d.d[430];
  work1d.L[680] = (work1d.KKT[856])*work1d.d_inv[430];
  work1d.v[431] = work1d.KKT[857];
  work1d.d[431] = work1d.v[431];
  if (work1d.d[431] < 0)
    work1d.d[431] = settings1d.kkt_reg;
  else
    work1d.d[431] += settings1d.kkt_reg;
  work1d.d_inv[431] = 1/work1d.d[431];
  work1d.L[681] = (work1d.KKT[858])*work1d.d_inv[431];
  work1d.v[432] = work1d.KKT[859];
  work1d.d[432] = work1d.v[432];
  if (work1d.d[432] < 0)
    work1d.d[432] = settings1d.kkt_reg;
  else
    work1d.d[432] += settings1d.kkt_reg;
  work1d.d_inv[432] = 1/work1d.d[432];
  work1d.L[682] = (work1d.KKT[860])*work1d.d_inv[432];
  work1d.v[433] = work1d.KKT[861];
  work1d.d[433] = work1d.v[433];
  if (work1d.d[433] < 0)
    work1d.d[433] = settings1d.kkt_reg;
  else
    work1d.d[433] += settings1d.kkt_reg;
  work1d.d_inv[433] = 1/work1d.d[433];
  work1d.L[683] = (work1d.KKT[862])*work1d.d_inv[433];
  work1d.v[434] = work1d.KKT[863];
  work1d.d[434] = work1d.v[434];
  if (work1d.d[434] < 0)
    work1d.d[434] = settings1d.kkt_reg;
  else
    work1d.d[434] += settings1d.kkt_reg;
  work1d.d_inv[434] = 1/work1d.d[434];
  work1d.L[684] = (work1d.KKT[864])*work1d.d_inv[434];
  work1d.v[435] = work1d.KKT[865];
  work1d.d[435] = work1d.v[435];
  if (work1d.d[435] < 0)
    work1d.d[435] = settings1d.kkt_reg;
  else
    work1d.d[435] += settings1d.kkt_reg;
  work1d.d_inv[435] = 1/work1d.d[435];
  work1d.L[685] = (work1d.KKT[866])*work1d.d_inv[435];
  work1d.v[436] = work1d.KKT[867];
  work1d.d[436] = work1d.v[436];
  if (work1d.d[436] < 0)
    work1d.d[436] = settings1d.kkt_reg;
  else
    work1d.d[436] += settings1d.kkt_reg;
  work1d.d_inv[436] = 1/work1d.d[436];
  work1d.L[686] = (work1d.KKT[868])*work1d.d_inv[436];
  work1d.v[437] = work1d.KKT[869];
  work1d.d[437] = work1d.v[437];
  if (work1d.d[437] < 0)
    work1d.d[437] = settings1d.kkt_reg;
  else
    work1d.d[437] += settings1d.kkt_reg;
  work1d.d_inv[437] = 1/work1d.d[437];
  work1d.L[687] = (work1d.KKT[870])*work1d.d_inv[437];
  work1d.v[438] = work1d.KKT[871];
  work1d.d[438] = work1d.v[438];
  if (work1d.d[438] < 0)
    work1d.d[438] = settings1d.kkt_reg;
  else
    work1d.d[438] += settings1d.kkt_reg;
  work1d.d_inv[438] = 1/work1d.d[438];
  work1d.L[688] = (work1d.KKT[872])*work1d.d_inv[438];
  work1d.v[439] = work1d.KKT[873];
  work1d.d[439] = work1d.v[439];
  if (work1d.d[439] < 0)
    work1d.d[439] = settings1d.kkt_reg;
  else
    work1d.d[439] += settings1d.kkt_reg;
  work1d.d_inv[439] = 1/work1d.d[439];
  work1d.L[689] = (work1d.KKT[874])*work1d.d_inv[439];
  work1d.v[440] = work1d.KKT[875];
  work1d.d[440] = work1d.v[440];
  if (work1d.d[440] < 0)
    work1d.d[440] = settings1d.kkt_reg;
  else
    work1d.d[440] += settings1d.kkt_reg;
  work1d.d_inv[440] = 1/work1d.d[440];
  work1d.L[690] = (work1d.KKT[876])*work1d.d_inv[440];
  work1d.v[441] = work1d.KKT[877];
  work1d.d[441] = work1d.v[441];
  if (work1d.d[441] < 0)
    work1d.d[441] = settings1d.kkt_reg;
  else
    work1d.d[441] += settings1d.kkt_reg;
  work1d.d_inv[441] = 1/work1d.d[441];
  work1d.L[691] = (work1d.KKT[878])*work1d.d_inv[441];
  work1d.v[442] = work1d.KKT[879];
  work1d.d[442] = work1d.v[442];
  if (work1d.d[442] < 0)
    work1d.d[442] = settings1d.kkt_reg;
  else
    work1d.d[442] += settings1d.kkt_reg;
  work1d.d_inv[442] = 1/work1d.d[442];
  work1d.L[692] = (work1d.KKT[880])*work1d.d_inv[442];
  work1d.v[443] = work1d.KKT[881];
  work1d.d[443] = work1d.v[443];
  if (work1d.d[443] < 0)
    work1d.d[443] = settings1d.kkt_reg;
  else
    work1d.d[443] += settings1d.kkt_reg;
  work1d.d_inv[443] = 1/work1d.d[443];
  work1d.L[648] = (work1d.KKT[882])*work1d.d_inv[443];
  work1d.v[401] = work1d.L[81]*work1d.d[401];
  work1d.v[444] = work1d.KKT[883]-work1d.L[81]*work1d.v[401];
  work1d.d[444] = work1d.v[444];
  if (work1d.d[444] < 0)
    work1d.d[444] = settings1d.kkt_reg;
  else
    work1d.d[444] += settings1d.kkt_reg;
  work1d.d_inv[444] = 1/work1d.d[444];
  work1d.L[654] = (work1d.KKT[884])*work1d.d_inv[444];
  work1d.v[445] = work1d.KKT[885];
  work1d.d[445] = work1d.v[445];
  if (work1d.d[445] < 0)
    work1d.d[445] = settings1d.kkt_reg;
  else
    work1d.d[445] += settings1d.kkt_reg;
  work1d.d_inv[445] = 1/work1d.d[445];
  work1d.L[694] = (work1d.KKT[886])*work1d.d_inv[445];
  work1d.v[1] = work1d.L[82]*work1d.d[1];
  work1d.v[446] = work1d.KKT[887]-work1d.L[82]*work1d.v[1];
  work1d.d[446] = work1d.v[446];
  if (work1d.d[446] > 0)
    work1d.d[446] = -settings1d.kkt_reg;
  else
    work1d.d[446] -= settings1d.kkt_reg;
  work1d.d_inv[446] = 1/work1d.d[446];
  work1d.L[83] = (work1d.KKT[888])*work1d.d_inv[446];
  work1d.v[446] = work1d.L[83]*work1d.d[446];
  work1d.v[447] = 0-work1d.L[83]*work1d.v[446];
  work1d.d[447] = work1d.v[447];
  if (work1d.d[447] < 0)
    work1d.d[447] = settings1d.kkt_reg;
  else
    work1d.d[447] += settings1d.kkt_reg;
  work1d.d_inv[447] = 1/work1d.d[447];
  work1d.L[85] = (work1d.KKT[889])*work1d.d_inv[447];
  work1d.L[87] = (work1d.KKT[890])*work1d.d_inv[447];
  work1d.v[2] = work1d.L[84]*work1d.d[2];
  work1d.v[447] = work1d.L[85]*work1d.d[447];
  work1d.v[448] = work1d.KKT[891]-work1d.L[84]*work1d.v[2]-work1d.L[85]*work1d.v[447];
  work1d.d[448] = work1d.v[448];
  if (work1d.d[448] > 0)
    work1d.d[448] = -settings1d.kkt_reg;
  else
    work1d.d[448] -= settings1d.kkt_reg;
  work1d.d_inv[448] = 1/work1d.d[448];
  work1d.L[88] = (-work1d.L[87]*work1d.v[447])*work1d.d_inv[448];
  work1d.L[700] = (work1d.KKT[892])*work1d.d_inv[448];
  work1d.v[3] = work1d.L[86]*work1d.d[3];
  work1d.v[447] = work1d.L[87]*work1d.d[447];
  work1d.v[448] = work1d.L[88]*work1d.d[448];
  work1d.v[449] = work1d.KKT[893]-work1d.L[86]*work1d.v[3]-work1d.L[87]*work1d.v[447]-work1d.L[88]*work1d.v[448];
  work1d.d[449] = work1d.v[449];
  if (work1d.d[449] > 0)
    work1d.d[449] = -settings1d.kkt_reg;
  else
    work1d.d[449] -= settings1d.kkt_reg;
  work1d.d_inv[449] = 1/work1d.d[449];
  work1d.L[701] = (work1d.KKT[894]-work1d.L[700]*work1d.v[448])*work1d.d_inv[449];
  work1d.v[4] = work1d.L[89]*work1d.d[4];
  work1d.v[450] = work1d.KKT[895]-work1d.L[89]*work1d.v[4];
  work1d.d[450] = work1d.v[450];
  if (work1d.d[450] > 0)
    work1d.d[450] = -settings1d.kkt_reg;
  else
    work1d.d[450] -= settings1d.kkt_reg;
  work1d.d_inv[450] = 1/work1d.d[450];
  work1d.L[90] = (work1d.KKT[896])*work1d.d_inv[450];
  work1d.v[450] = work1d.L[90]*work1d.d[450];
  work1d.v[451] = 0-work1d.L[90]*work1d.v[450];
  work1d.d[451] = work1d.v[451];
  if (work1d.d[451] < 0)
    work1d.d[451] = settings1d.kkt_reg;
  else
    work1d.d[451] += settings1d.kkt_reg;
  work1d.d_inv[451] = 1/work1d.d[451];
  work1d.L[92] = (work1d.KKT[897])*work1d.d_inv[451];
  work1d.L[94] = (work1d.KKT[898])*work1d.d_inv[451];
  work1d.v[5] = work1d.L[91]*work1d.d[5];
  work1d.v[451] = work1d.L[92]*work1d.d[451];
  work1d.v[452] = work1d.KKT[899]-work1d.L[91]*work1d.v[5]-work1d.L[92]*work1d.v[451];
  work1d.d[452] = work1d.v[452];
  if (work1d.d[452] > 0)
    work1d.d[452] = -settings1d.kkt_reg;
  else
    work1d.d[452] -= settings1d.kkt_reg;
  work1d.d_inv[452] = 1/work1d.d[452];
  work1d.L[95] = (-work1d.L[94]*work1d.v[451])*work1d.d_inv[452];
  work1d.L[715] = (work1d.KKT[900])*work1d.d_inv[452];
  work1d.v[6] = work1d.L[93]*work1d.d[6];
  work1d.v[451] = work1d.L[94]*work1d.d[451];
  work1d.v[452] = work1d.L[95]*work1d.d[452];
  work1d.v[453] = work1d.KKT[901]-work1d.L[93]*work1d.v[6]-work1d.L[94]*work1d.v[451]-work1d.L[95]*work1d.v[452];
  work1d.d[453] = work1d.v[453];
  if (work1d.d[453] > 0)
    work1d.d[453] = -settings1d.kkt_reg;
  else
    work1d.d[453] -= settings1d.kkt_reg;
  work1d.d_inv[453] = 1/work1d.d[453];
  work1d.L[716] = (work1d.KKT[902]-work1d.L[715]*work1d.v[452])*work1d.d_inv[453];
  work1d.v[7] = work1d.L[96]*work1d.d[7];
  work1d.v[454] = work1d.KKT[903]-work1d.L[96]*work1d.v[7];
  work1d.d[454] = work1d.v[454];
  if (work1d.d[454] > 0)
    work1d.d[454] = -settings1d.kkt_reg;
  else
    work1d.d[454] -= settings1d.kkt_reg;
  work1d.d_inv[454] = 1/work1d.d[454];
  work1d.L[97] = (work1d.KKT[904])*work1d.d_inv[454];
  work1d.v[454] = work1d.L[97]*work1d.d[454];
  work1d.v[455] = 0-work1d.L[97]*work1d.v[454];
  work1d.d[455] = work1d.v[455];
  if (work1d.d[455] < 0)
    work1d.d[455] = settings1d.kkt_reg;
  else
    work1d.d[455] += settings1d.kkt_reg;
  work1d.d_inv[455] = 1/work1d.d[455];
  work1d.L[99] = (work1d.KKT[905])*work1d.d_inv[455];
  work1d.L[101] = (work1d.KKT[906])*work1d.d_inv[455];
  work1d.v[8] = work1d.L[98]*work1d.d[8];
  work1d.v[455] = work1d.L[99]*work1d.d[455];
  work1d.v[456] = work1d.KKT[907]-work1d.L[98]*work1d.v[8]-work1d.L[99]*work1d.v[455];
  work1d.d[456] = work1d.v[456];
  if (work1d.d[456] > 0)
    work1d.d[456] = -settings1d.kkt_reg;
  else
    work1d.d[456] -= settings1d.kkt_reg;
  work1d.d_inv[456] = 1/work1d.d[456];
  work1d.L[102] = (-work1d.L[101]*work1d.v[455])*work1d.d_inv[456];
  work1d.L[735] = (work1d.KKT[908])*work1d.d_inv[456];
  work1d.v[9] = work1d.L[100]*work1d.d[9];
  work1d.v[455] = work1d.L[101]*work1d.d[455];
  work1d.v[456] = work1d.L[102]*work1d.d[456];
  work1d.v[457] = work1d.KKT[909]-work1d.L[100]*work1d.v[9]-work1d.L[101]*work1d.v[455]-work1d.L[102]*work1d.v[456];
  work1d.d[457] = work1d.v[457];
  if (work1d.d[457] > 0)
    work1d.d[457] = -settings1d.kkt_reg;
  else
    work1d.d[457] -= settings1d.kkt_reg;
  work1d.d_inv[457] = 1/work1d.d[457];
  work1d.L[736] = (work1d.KKT[910]-work1d.L[735]*work1d.v[456])*work1d.d_inv[457];
  work1d.v[10] = work1d.L[103]*work1d.d[10];
  work1d.v[458] = work1d.KKT[911]-work1d.L[103]*work1d.v[10];
  work1d.d[458] = work1d.v[458];
  if (work1d.d[458] > 0)
    work1d.d[458] = -settings1d.kkt_reg;
  else
    work1d.d[458] -= settings1d.kkt_reg;
  work1d.d_inv[458] = 1/work1d.d[458];
  work1d.L[104] = (work1d.KKT[912])*work1d.d_inv[458];
  work1d.v[458] = work1d.L[104]*work1d.d[458];
  work1d.v[459] = 0-work1d.L[104]*work1d.v[458];
  work1d.d[459] = work1d.v[459];
  if (work1d.d[459] < 0)
    work1d.d[459] = settings1d.kkt_reg;
  else
    work1d.d[459] += settings1d.kkt_reg;
  work1d.d_inv[459] = 1/work1d.d[459];
  work1d.L[106] = (work1d.KKT[913])*work1d.d_inv[459];
  work1d.L[108] = (work1d.KKT[914])*work1d.d_inv[459];
  work1d.v[11] = work1d.L[105]*work1d.d[11];
  work1d.v[459] = work1d.L[106]*work1d.d[459];
  work1d.v[460] = work1d.KKT[915]-work1d.L[105]*work1d.v[11]-work1d.L[106]*work1d.v[459];
  work1d.d[460] = work1d.v[460];
  if (work1d.d[460] > 0)
    work1d.d[460] = -settings1d.kkt_reg;
  else
    work1d.d[460] -= settings1d.kkt_reg;
  work1d.d_inv[460] = 1/work1d.d[460];
  work1d.L[109] = (-work1d.L[108]*work1d.v[459])*work1d.d_inv[460];
  work1d.L[757] = (work1d.KKT[916])*work1d.d_inv[460];
  work1d.v[12] = work1d.L[107]*work1d.d[12];
  work1d.v[459] = work1d.L[108]*work1d.d[459];
  work1d.v[460] = work1d.L[109]*work1d.d[460];
  work1d.v[461] = work1d.KKT[917]-work1d.L[107]*work1d.v[12]-work1d.L[108]*work1d.v[459]-work1d.L[109]*work1d.v[460];
  work1d.d[461] = work1d.v[461];
  if (work1d.d[461] > 0)
    work1d.d[461] = -settings1d.kkt_reg;
  else
    work1d.d[461] -= settings1d.kkt_reg;
  work1d.d_inv[461] = 1/work1d.d[461];
  work1d.L[758] = (work1d.KKT[918]-work1d.L[757]*work1d.v[460])*work1d.d_inv[461];
  work1d.v[13] = work1d.L[110]*work1d.d[13];
  work1d.v[462] = work1d.KKT[919]-work1d.L[110]*work1d.v[13];
  work1d.d[462] = work1d.v[462];
  if (work1d.d[462] > 0)
    work1d.d[462] = -settings1d.kkt_reg;
  else
    work1d.d[462] -= settings1d.kkt_reg;
  work1d.d_inv[462] = 1/work1d.d[462];
  work1d.L[111] = (work1d.KKT[920])*work1d.d_inv[462];
  work1d.v[462] = work1d.L[111]*work1d.d[462];
  work1d.v[463] = 0-work1d.L[111]*work1d.v[462];
  work1d.d[463] = work1d.v[463];
  if (work1d.d[463] < 0)
    work1d.d[463] = settings1d.kkt_reg;
  else
    work1d.d[463] += settings1d.kkt_reg;
  work1d.d_inv[463] = 1/work1d.d[463];
  work1d.L[113] = (work1d.KKT[921])*work1d.d_inv[463];
  work1d.L[115] = (work1d.KKT[922])*work1d.d_inv[463];
  work1d.v[14] = work1d.L[112]*work1d.d[14];
  work1d.v[463] = work1d.L[113]*work1d.d[463];
  work1d.v[464] = work1d.KKT[923]-work1d.L[112]*work1d.v[14]-work1d.L[113]*work1d.v[463];
  work1d.d[464] = work1d.v[464];
  if (work1d.d[464] > 0)
    work1d.d[464] = -settings1d.kkt_reg;
  else
    work1d.d[464] -= settings1d.kkt_reg;
  work1d.d_inv[464] = 1/work1d.d[464];
  work1d.L[116] = (-work1d.L[115]*work1d.v[463])*work1d.d_inv[464];
  work1d.L[779] = (work1d.KKT[924])*work1d.d_inv[464];
  work1d.v[15] = work1d.L[114]*work1d.d[15];
  work1d.v[463] = work1d.L[115]*work1d.d[463];
  work1d.v[464] = work1d.L[116]*work1d.d[464];
  work1d.v[465] = work1d.KKT[925]-work1d.L[114]*work1d.v[15]-work1d.L[115]*work1d.v[463]-work1d.L[116]*work1d.v[464];
  work1d.d[465] = work1d.v[465];
  if (work1d.d[465] > 0)
    work1d.d[465] = -settings1d.kkt_reg;
  else
    work1d.d[465] -= settings1d.kkt_reg;
  work1d.d_inv[465] = 1/work1d.d[465];
  work1d.L[780] = (work1d.KKT[926]-work1d.L[779]*work1d.v[464])*work1d.d_inv[465];
  work1d.v[16] = work1d.L[117]*work1d.d[16];
  work1d.v[466] = work1d.KKT[927]-work1d.L[117]*work1d.v[16];
  work1d.d[466] = work1d.v[466];
  if (work1d.d[466] > 0)
    work1d.d[466] = -settings1d.kkt_reg;
  else
    work1d.d[466] -= settings1d.kkt_reg;
  work1d.d_inv[466] = 1/work1d.d[466];
  work1d.L[118] = (work1d.KKT[928])*work1d.d_inv[466];
  work1d.v[466] = work1d.L[118]*work1d.d[466];
  work1d.v[467] = 0-work1d.L[118]*work1d.v[466];
  work1d.d[467] = work1d.v[467];
  if (work1d.d[467] < 0)
    work1d.d[467] = settings1d.kkt_reg;
  else
    work1d.d[467] += settings1d.kkt_reg;
  work1d.d_inv[467] = 1/work1d.d[467];
  work1d.L[120] = (work1d.KKT[929])*work1d.d_inv[467];
  work1d.L[122] = (work1d.KKT[930])*work1d.d_inv[467];
  work1d.v[17] = work1d.L[119]*work1d.d[17];
  work1d.v[467] = work1d.L[120]*work1d.d[467];
  work1d.v[468] = work1d.KKT[931]-work1d.L[119]*work1d.v[17]-work1d.L[120]*work1d.v[467];
  work1d.d[468] = work1d.v[468];
  if (work1d.d[468] > 0)
    work1d.d[468] = -settings1d.kkt_reg;
  else
    work1d.d[468] -= settings1d.kkt_reg;
  work1d.d_inv[468] = 1/work1d.d[468];
  work1d.L[123] = (-work1d.L[122]*work1d.v[467])*work1d.d_inv[468];
  work1d.L[801] = (work1d.KKT[932])*work1d.d_inv[468];
  work1d.v[18] = work1d.L[121]*work1d.d[18];
  work1d.v[467] = work1d.L[122]*work1d.d[467];
  work1d.v[468] = work1d.L[123]*work1d.d[468];
  work1d.v[469] = work1d.KKT[933]-work1d.L[121]*work1d.v[18]-work1d.L[122]*work1d.v[467]-work1d.L[123]*work1d.v[468];
  work1d.d[469] = work1d.v[469];
  if (work1d.d[469] > 0)
    work1d.d[469] = -settings1d.kkt_reg;
  else
    work1d.d[469] -= settings1d.kkt_reg;
  work1d.d_inv[469] = 1/work1d.d[469];
  work1d.L[802] = (work1d.KKT[934]-work1d.L[801]*work1d.v[468])*work1d.d_inv[469];
  work1d.v[19] = work1d.L[124]*work1d.d[19];
  work1d.v[470] = work1d.KKT[935]-work1d.L[124]*work1d.v[19];
  work1d.d[470] = work1d.v[470];
  if (work1d.d[470] > 0)
    work1d.d[470] = -settings1d.kkt_reg;
  else
    work1d.d[470] -= settings1d.kkt_reg;
  work1d.d_inv[470] = 1/work1d.d[470];
  work1d.L[125] = (work1d.KKT[936])*work1d.d_inv[470];
  work1d.v[470] = work1d.L[125]*work1d.d[470];
  work1d.v[471] = 0-work1d.L[125]*work1d.v[470];
  work1d.d[471] = work1d.v[471];
  if (work1d.d[471] < 0)
    work1d.d[471] = settings1d.kkt_reg;
  else
    work1d.d[471] += settings1d.kkt_reg;
  work1d.d_inv[471] = 1/work1d.d[471];
  work1d.L[127] = (work1d.KKT[937])*work1d.d_inv[471];
  work1d.L[129] = (work1d.KKT[938])*work1d.d_inv[471];
  work1d.v[20] = work1d.L[126]*work1d.d[20];
  work1d.v[471] = work1d.L[127]*work1d.d[471];
  work1d.v[472] = work1d.KKT[939]-work1d.L[126]*work1d.v[20]-work1d.L[127]*work1d.v[471];
  work1d.d[472] = work1d.v[472];
  if (work1d.d[472] > 0)
    work1d.d[472] = -settings1d.kkt_reg;
  else
    work1d.d[472] -= settings1d.kkt_reg;
  work1d.d_inv[472] = 1/work1d.d[472];
  work1d.L[130] = (-work1d.L[129]*work1d.v[471])*work1d.d_inv[472];
  work1d.L[823] = (work1d.KKT[940])*work1d.d_inv[472];
  work1d.v[21] = work1d.L[128]*work1d.d[21];
  work1d.v[471] = work1d.L[129]*work1d.d[471];
  work1d.v[472] = work1d.L[130]*work1d.d[472];
  work1d.v[473] = work1d.KKT[941]-work1d.L[128]*work1d.v[21]-work1d.L[129]*work1d.v[471]-work1d.L[130]*work1d.v[472];
  work1d.d[473] = work1d.v[473];
  if (work1d.d[473] > 0)
    work1d.d[473] = -settings1d.kkt_reg;
  else
    work1d.d[473] -= settings1d.kkt_reg;
  work1d.d_inv[473] = 1/work1d.d[473];
  work1d.L[824] = (work1d.KKT[942]-work1d.L[823]*work1d.v[472])*work1d.d_inv[473];
  work1d.v[22] = work1d.L[131]*work1d.d[22];
  work1d.v[474] = work1d.KKT[943]-work1d.L[131]*work1d.v[22];
  work1d.d[474] = work1d.v[474];
  if (work1d.d[474] > 0)
    work1d.d[474] = -settings1d.kkt_reg;
  else
    work1d.d[474] -= settings1d.kkt_reg;
  work1d.d_inv[474] = 1/work1d.d[474];
  work1d.L[132] = (work1d.KKT[944])*work1d.d_inv[474];
  work1d.v[474] = work1d.L[132]*work1d.d[474];
  work1d.v[475] = 0-work1d.L[132]*work1d.v[474];
  work1d.d[475] = work1d.v[475];
  if (work1d.d[475] < 0)
    work1d.d[475] = settings1d.kkt_reg;
  else
    work1d.d[475] += settings1d.kkt_reg;
  work1d.d_inv[475] = 1/work1d.d[475];
  work1d.L[134] = (work1d.KKT[945])*work1d.d_inv[475];
  work1d.L[136] = (work1d.KKT[946])*work1d.d_inv[475];
  work1d.v[23] = work1d.L[133]*work1d.d[23];
  work1d.v[475] = work1d.L[134]*work1d.d[475];
  work1d.v[476] = work1d.KKT[947]-work1d.L[133]*work1d.v[23]-work1d.L[134]*work1d.v[475];
  work1d.d[476] = work1d.v[476];
  if (work1d.d[476] > 0)
    work1d.d[476] = -settings1d.kkt_reg;
  else
    work1d.d[476] -= settings1d.kkt_reg;
  work1d.d_inv[476] = 1/work1d.d[476];
  work1d.L[137] = (-work1d.L[136]*work1d.v[475])*work1d.d_inv[476];
  work1d.L[845] = (work1d.KKT[948])*work1d.d_inv[476];
  work1d.v[24] = work1d.L[135]*work1d.d[24];
  work1d.v[475] = work1d.L[136]*work1d.d[475];
  work1d.v[476] = work1d.L[137]*work1d.d[476];
  work1d.v[477] = work1d.KKT[949]-work1d.L[135]*work1d.v[24]-work1d.L[136]*work1d.v[475]-work1d.L[137]*work1d.v[476];
  work1d.d[477] = work1d.v[477];
  if (work1d.d[477] > 0)
    work1d.d[477] = -settings1d.kkt_reg;
  else
    work1d.d[477] -= settings1d.kkt_reg;
  work1d.d_inv[477] = 1/work1d.d[477];
  work1d.L[846] = (work1d.KKT[950]-work1d.L[845]*work1d.v[476])*work1d.d_inv[477];
  work1d.v[25] = work1d.L[138]*work1d.d[25];
  work1d.v[478] = work1d.KKT[951]-work1d.L[138]*work1d.v[25];
  work1d.d[478] = work1d.v[478];
  if (work1d.d[478] > 0)
    work1d.d[478] = -settings1d.kkt_reg;
  else
    work1d.d[478] -= settings1d.kkt_reg;
  work1d.d_inv[478] = 1/work1d.d[478];
  work1d.L[139] = (work1d.KKT[952])*work1d.d_inv[478];
  work1d.v[478] = work1d.L[139]*work1d.d[478];
  work1d.v[479] = 0-work1d.L[139]*work1d.v[478];
  work1d.d[479] = work1d.v[479];
  if (work1d.d[479] < 0)
    work1d.d[479] = settings1d.kkt_reg;
  else
    work1d.d[479] += settings1d.kkt_reg;
  work1d.d_inv[479] = 1/work1d.d[479];
  work1d.L[141] = (work1d.KKT[953])*work1d.d_inv[479];
  work1d.L[143] = (work1d.KKT[954])*work1d.d_inv[479];
  work1d.v[26] = work1d.L[140]*work1d.d[26];
  work1d.v[479] = work1d.L[141]*work1d.d[479];
  work1d.v[480] = work1d.KKT[955]-work1d.L[140]*work1d.v[26]-work1d.L[141]*work1d.v[479];
  work1d.d[480] = work1d.v[480];
  if (work1d.d[480] > 0)
    work1d.d[480] = -settings1d.kkt_reg;
  else
    work1d.d[480] -= settings1d.kkt_reg;
  work1d.d_inv[480] = 1/work1d.d[480];
  work1d.L[144] = (-work1d.L[143]*work1d.v[479])*work1d.d_inv[480];
  work1d.L[867] = (work1d.KKT[956])*work1d.d_inv[480];
  work1d.v[27] = work1d.L[142]*work1d.d[27];
  work1d.v[479] = work1d.L[143]*work1d.d[479];
  work1d.v[480] = work1d.L[144]*work1d.d[480];
  work1d.v[481] = work1d.KKT[957]-work1d.L[142]*work1d.v[27]-work1d.L[143]*work1d.v[479]-work1d.L[144]*work1d.v[480];
  work1d.d[481] = work1d.v[481];
  if (work1d.d[481] > 0)
    work1d.d[481] = -settings1d.kkt_reg;
  else
    work1d.d[481] -= settings1d.kkt_reg;
  work1d.d_inv[481] = 1/work1d.d[481];
  work1d.L[868] = (work1d.KKT[958]-work1d.L[867]*work1d.v[480])*work1d.d_inv[481];
  work1d.v[28] = work1d.L[145]*work1d.d[28];
  work1d.v[482] = work1d.KKT[959]-work1d.L[145]*work1d.v[28];
  work1d.d[482] = work1d.v[482];
  if (work1d.d[482] > 0)
    work1d.d[482] = -settings1d.kkt_reg;
  else
    work1d.d[482] -= settings1d.kkt_reg;
  work1d.d_inv[482] = 1/work1d.d[482];
  work1d.L[146] = (work1d.KKT[960])*work1d.d_inv[482];
  work1d.v[482] = work1d.L[146]*work1d.d[482];
  work1d.v[483] = 0-work1d.L[146]*work1d.v[482];
  work1d.d[483] = work1d.v[483];
  if (work1d.d[483] < 0)
    work1d.d[483] = settings1d.kkt_reg;
  else
    work1d.d[483] += settings1d.kkt_reg;
  work1d.d_inv[483] = 1/work1d.d[483];
  work1d.L[148] = (work1d.KKT[961])*work1d.d_inv[483];
  work1d.L[150] = (work1d.KKT[962])*work1d.d_inv[483];
  work1d.v[29] = work1d.L[147]*work1d.d[29];
  work1d.v[483] = work1d.L[148]*work1d.d[483];
  work1d.v[484] = work1d.KKT[963]-work1d.L[147]*work1d.v[29]-work1d.L[148]*work1d.v[483];
  work1d.d[484] = work1d.v[484];
  if (work1d.d[484] > 0)
    work1d.d[484] = -settings1d.kkt_reg;
  else
    work1d.d[484] -= settings1d.kkt_reg;
  work1d.d_inv[484] = 1/work1d.d[484];
  work1d.L[151] = (-work1d.L[150]*work1d.v[483])*work1d.d_inv[484];
  work1d.L[889] = (work1d.KKT[964])*work1d.d_inv[484];
  work1d.v[30] = work1d.L[149]*work1d.d[30];
  work1d.v[483] = work1d.L[150]*work1d.d[483];
  work1d.v[484] = work1d.L[151]*work1d.d[484];
  work1d.v[485] = work1d.KKT[965]-work1d.L[149]*work1d.v[30]-work1d.L[150]*work1d.v[483]-work1d.L[151]*work1d.v[484];
  work1d.d[485] = work1d.v[485];
  if (work1d.d[485] > 0)
    work1d.d[485] = -settings1d.kkt_reg;
  else
    work1d.d[485] -= settings1d.kkt_reg;
  work1d.d_inv[485] = 1/work1d.d[485];
  work1d.L[890] = (work1d.KKT[966]-work1d.L[889]*work1d.v[484])*work1d.d_inv[485];
  work1d.v[31] = work1d.L[152]*work1d.d[31];
  work1d.v[486] = work1d.KKT[967]-work1d.L[152]*work1d.v[31];
  work1d.d[486] = work1d.v[486];
  if (work1d.d[486] > 0)
    work1d.d[486] = -settings1d.kkt_reg;
  else
    work1d.d[486] -= settings1d.kkt_reg;
  work1d.d_inv[486] = 1/work1d.d[486];
  work1d.L[153] = (work1d.KKT[968])*work1d.d_inv[486];
  work1d.v[486] = work1d.L[153]*work1d.d[486];
  work1d.v[487] = 0-work1d.L[153]*work1d.v[486];
  work1d.d[487] = work1d.v[487];
  if (work1d.d[487] < 0)
    work1d.d[487] = settings1d.kkt_reg;
  else
    work1d.d[487] += settings1d.kkt_reg;
  work1d.d_inv[487] = 1/work1d.d[487];
  work1d.L[155] = (work1d.KKT[969])*work1d.d_inv[487];
  work1d.L[157] = (work1d.KKT[970])*work1d.d_inv[487];
  work1d.v[32] = work1d.L[154]*work1d.d[32];
  work1d.v[487] = work1d.L[155]*work1d.d[487];
  work1d.v[488] = work1d.KKT[971]-work1d.L[154]*work1d.v[32]-work1d.L[155]*work1d.v[487];
  work1d.d[488] = work1d.v[488];
  if (work1d.d[488] > 0)
    work1d.d[488] = -settings1d.kkt_reg;
  else
    work1d.d[488] -= settings1d.kkt_reg;
  work1d.d_inv[488] = 1/work1d.d[488];
  work1d.L[158] = (-work1d.L[157]*work1d.v[487])*work1d.d_inv[488];
  work1d.L[911] = (work1d.KKT[972])*work1d.d_inv[488];
  work1d.v[33] = work1d.L[156]*work1d.d[33];
  work1d.v[487] = work1d.L[157]*work1d.d[487];
  work1d.v[488] = work1d.L[158]*work1d.d[488];
  work1d.v[489] = work1d.KKT[973]-work1d.L[156]*work1d.v[33]-work1d.L[157]*work1d.v[487]-work1d.L[158]*work1d.v[488];
  work1d.d[489] = work1d.v[489];
  if (work1d.d[489] > 0)
    work1d.d[489] = -settings1d.kkt_reg;
  else
    work1d.d[489] -= settings1d.kkt_reg;
  work1d.d_inv[489] = 1/work1d.d[489];
  work1d.L[912] = (work1d.KKT[974]-work1d.L[911]*work1d.v[488])*work1d.d_inv[489];
  work1d.v[34] = work1d.L[159]*work1d.d[34];
  work1d.v[490] = work1d.KKT[975]-work1d.L[159]*work1d.v[34];
  work1d.d[490] = work1d.v[490];
  if (work1d.d[490] > 0)
    work1d.d[490] = -settings1d.kkt_reg;
  else
    work1d.d[490] -= settings1d.kkt_reg;
  work1d.d_inv[490] = 1/work1d.d[490];
  work1d.L[160] = (work1d.KKT[976])*work1d.d_inv[490];
  work1d.v[490] = work1d.L[160]*work1d.d[490];
  work1d.v[491] = 0-work1d.L[160]*work1d.v[490];
  work1d.d[491] = work1d.v[491];
  if (work1d.d[491] < 0)
    work1d.d[491] = settings1d.kkt_reg;
  else
    work1d.d[491] += settings1d.kkt_reg;
  work1d.d_inv[491] = 1/work1d.d[491];
  work1d.L[162] = (work1d.KKT[977])*work1d.d_inv[491];
  work1d.L[164] = (work1d.KKT[978])*work1d.d_inv[491];
  work1d.v[35] = work1d.L[161]*work1d.d[35];
  work1d.v[491] = work1d.L[162]*work1d.d[491];
  work1d.v[492] = work1d.KKT[979]-work1d.L[161]*work1d.v[35]-work1d.L[162]*work1d.v[491];
  work1d.d[492] = work1d.v[492];
  if (work1d.d[492] > 0)
    work1d.d[492] = -settings1d.kkt_reg;
  else
    work1d.d[492] -= settings1d.kkt_reg;
  work1d.d_inv[492] = 1/work1d.d[492];
  work1d.L[165] = (-work1d.L[164]*work1d.v[491])*work1d.d_inv[492];
  work1d.L[933] = (work1d.KKT[980])*work1d.d_inv[492];
  work1d.v[36] = work1d.L[163]*work1d.d[36];
  work1d.v[491] = work1d.L[164]*work1d.d[491];
  work1d.v[492] = work1d.L[165]*work1d.d[492];
  work1d.v[493] = work1d.KKT[981]-work1d.L[163]*work1d.v[36]-work1d.L[164]*work1d.v[491]-work1d.L[165]*work1d.v[492];
  work1d.d[493] = work1d.v[493];
  if (work1d.d[493] > 0)
    work1d.d[493] = -settings1d.kkt_reg;
  else
    work1d.d[493] -= settings1d.kkt_reg;
  work1d.d_inv[493] = 1/work1d.d[493];
  work1d.L[934] = (work1d.KKT[982]-work1d.L[933]*work1d.v[492])*work1d.d_inv[493];
  work1d.v[37] = work1d.L[166]*work1d.d[37];
  work1d.v[494] = work1d.KKT[983]-work1d.L[166]*work1d.v[37];
  work1d.d[494] = work1d.v[494];
  if (work1d.d[494] > 0)
    work1d.d[494] = -settings1d.kkt_reg;
  else
    work1d.d[494] -= settings1d.kkt_reg;
  work1d.d_inv[494] = 1/work1d.d[494];
  work1d.L[167] = (work1d.KKT[984])*work1d.d_inv[494];
  work1d.v[494] = work1d.L[167]*work1d.d[494];
  work1d.v[495] = 0-work1d.L[167]*work1d.v[494];
  work1d.d[495] = work1d.v[495];
  if (work1d.d[495] < 0)
    work1d.d[495] = settings1d.kkt_reg;
  else
    work1d.d[495] += settings1d.kkt_reg;
  work1d.d_inv[495] = 1/work1d.d[495];
  work1d.L[169] = (work1d.KKT[985])*work1d.d_inv[495];
  work1d.L[171] = (work1d.KKT[986])*work1d.d_inv[495];
  work1d.v[38] = work1d.L[168]*work1d.d[38];
  work1d.v[495] = work1d.L[169]*work1d.d[495];
  work1d.v[496] = work1d.KKT[987]-work1d.L[168]*work1d.v[38]-work1d.L[169]*work1d.v[495];
  work1d.d[496] = work1d.v[496];
  if (work1d.d[496] > 0)
    work1d.d[496] = -settings1d.kkt_reg;
  else
    work1d.d[496] -= settings1d.kkt_reg;
  work1d.d_inv[496] = 1/work1d.d[496];
  work1d.L[172] = (-work1d.L[171]*work1d.v[495])*work1d.d_inv[496];
  work1d.L[955] = (work1d.KKT[988])*work1d.d_inv[496];
  work1d.v[39] = work1d.L[170]*work1d.d[39];
  work1d.v[495] = work1d.L[171]*work1d.d[495];
  work1d.v[496] = work1d.L[172]*work1d.d[496];
  work1d.v[497] = work1d.KKT[989]-work1d.L[170]*work1d.v[39]-work1d.L[171]*work1d.v[495]-work1d.L[172]*work1d.v[496];
  work1d.d[497] = work1d.v[497];
  if (work1d.d[497] > 0)
    work1d.d[497] = -settings1d.kkt_reg;
  else
    work1d.d[497] -= settings1d.kkt_reg;
  work1d.d_inv[497] = 1/work1d.d[497];
  work1d.L[956] = (work1d.KKT[990]-work1d.L[955]*work1d.v[496])*work1d.d_inv[497];
  work1d.v[40] = work1d.L[173]*work1d.d[40];
  work1d.v[498] = work1d.KKT[991]-work1d.L[173]*work1d.v[40];
  work1d.d[498] = work1d.v[498];
  if (work1d.d[498] > 0)
    work1d.d[498] = -settings1d.kkt_reg;
  else
    work1d.d[498] -= settings1d.kkt_reg;
  work1d.d_inv[498] = 1/work1d.d[498];
  work1d.L[174] = (work1d.KKT[992])*work1d.d_inv[498];
  work1d.v[498] = work1d.L[174]*work1d.d[498];
  work1d.v[499] = 0-work1d.L[174]*work1d.v[498];
  work1d.d[499] = work1d.v[499];
  if (work1d.d[499] < 0)
    work1d.d[499] = settings1d.kkt_reg;
  else
    work1d.d[499] += settings1d.kkt_reg;
  work1d.d_inv[499] = 1/work1d.d[499];
  work1d.L[176] = (work1d.KKT[993])*work1d.d_inv[499];
  work1d.L[178] = (work1d.KKT[994])*work1d.d_inv[499];
  work1d.v[41] = work1d.L[175]*work1d.d[41];
  work1d.v[499] = work1d.L[176]*work1d.d[499];
  work1d.v[500] = work1d.KKT[995]-work1d.L[175]*work1d.v[41]-work1d.L[176]*work1d.v[499];
  work1d.d[500] = work1d.v[500];
  if (work1d.d[500] > 0)
    work1d.d[500] = -settings1d.kkt_reg;
  else
    work1d.d[500] -= settings1d.kkt_reg;
  work1d.d_inv[500] = 1/work1d.d[500];
  work1d.L[179] = (-work1d.L[178]*work1d.v[499])*work1d.d_inv[500];
  work1d.L[977] = (work1d.KKT[996])*work1d.d_inv[500];
  work1d.v[42] = work1d.L[177]*work1d.d[42];
  work1d.v[499] = work1d.L[178]*work1d.d[499];
  work1d.v[500] = work1d.L[179]*work1d.d[500];
  work1d.v[501] = work1d.KKT[997]-work1d.L[177]*work1d.v[42]-work1d.L[178]*work1d.v[499]-work1d.L[179]*work1d.v[500];
  work1d.d[501] = work1d.v[501];
  if (work1d.d[501] > 0)
    work1d.d[501] = -settings1d.kkt_reg;
  else
    work1d.d[501] -= settings1d.kkt_reg;
  work1d.d_inv[501] = 1/work1d.d[501];
  work1d.L[978] = (work1d.KKT[998]-work1d.L[977]*work1d.v[500])*work1d.d_inv[501];
  work1d.v[43] = work1d.L[180]*work1d.d[43];
  work1d.v[502] = work1d.KKT[999]-work1d.L[180]*work1d.v[43];
  work1d.d[502] = work1d.v[502];
  if (work1d.d[502] > 0)
    work1d.d[502] = -settings1d.kkt_reg;
  else
    work1d.d[502] -= settings1d.kkt_reg;
  work1d.d_inv[502] = 1/work1d.d[502];
  work1d.L[181] = (work1d.KKT[1000])*work1d.d_inv[502];
  work1d.v[502] = work1d.L[181]*work1d.d[502];
  work1d.v[503] = 0-work1d.L[181]*work1d.v[502];
  work1d.d[503] = work1d.v[503];
  if (work1d.d[503] < 0)
    work1d.d[503] = settings1d.kkt_reg;
  else
    work1d.d[503] += settings1d.kkt_reg;
  work1d.d_inv[503] = 1/work1d.d[503];
  work1d.L[183] = (work1d.KKT[1001])*work1d.d_inv[503];
  work1d.L[185] = (work1d.KKT[1002])*work1d.d_inv[503];
  work1d.v[44] = work1d.L[182]*work1d.d[44];
  work1d.v[503] = work1d.L[183]*work1d.d[503];
  work1d.v[504] = work1d.KKT[1003]-work1d.L[182]*work1d.v[44]-work1d.L[183]*work1d.v[503];
  work1d.d[504] = work1d.v[504];
  if (work1d.d[504] > 0)
    work1d.d[504] = -settings1d.kkt_reg;
  else
    work1d.d[504] -= settings1d.kkt_reg;
  work1d.d_inv[504] = 1/work1d.d[504];
  work1d.L[186] = (-work1d.L[185]*work1d.v[503])*work1d.d_inv[504];
  work1d.L[999] = (work1d.KKT[1004])*work1d.d_inv[504];
  work1d.v[45] = work1d.L[184]*work1d.d[45];
  work1d.v[503] = work1d.L[185]*work1d.d[503];
  work1d.v[504] = work1d.L[186]*work1d.d[504];
  work1d.v[505] = work1d.KKT[1005]-work1d.L[184]*work1d.v[45]-work1d.L[185]*work1d.v[503]-work1d.L[186]*work1d.v[504];
  work1d.d[505] = work1d.v[505];
  if (work1d.d[505] > 0)
    work1d.d[505] = -settings1d.kkt_reg;
  else
    work1d.d[505] -= settings1d.kkt_reg;
  work1d.d_inv[505] = 1/work1d.d[505];
  work1d.L[1000] = (work1d.KKT[1006]-work1d.L[999]*work1d.v[504])*work1d.d_inv[505];
  work1d.v[46] = work1d.L[187]*work1d.d[46];
  work1d.v[506] = work1d.KKT[1007]-work1d.L[187]*work1d.v[46];
  work1d.d[506] = work1d.v[506];
  if (work1d.d[506] > 0)
    work1d.d[506] = -settings1d.kkt_reg;
  else
    work1d.d[506] -= settings1d.kkt_reg;
  work1d.d_inv[506] = 1/work1d.d[506];
  work1d.L[188] = (work1d.KKT[1008])*work1d.d_inv[506];
  work1d.v[506] = work1d.L[188]*work1d.d[506];
  work1d.v[507] = 0-work1d.L[188]*work1d.v[506];
  work1d.d[507] = work1d.v[507];
  if (work1d.d[507] < 0)
    work1d.d[507] = settings1d.kkt_reg;
  else
    work1d.d[507] += settings1d.kkt_reg;
  work1d.d_inv[507] = 1/work1d.d[507];
  work1d.L[190] = (work1d.KKT[1009])*work1d.d_inv[507];
  work1d.L[192] = (work1d.KKT[1010])*work1d.d_inv[507];
  work1d.v[47] = work1d.L[189]*work1d.d[47];
  work1d.v[507] = work1d.L[190]*work1d.d[507];
  work1d.v[508] = work1d.KKT[1011]-work1d.L[189]*work1d.v[47]-work1d.L[190]*work1d.v[507];
  work1d.d[508] = work1d.v[508];
  if (work1d.d[508] > 0)
    work1d.d[508] = -settings1d.kkt_reg;
  else
    work1d.d[508] -= settings1d.kkt_reg;
  work1d.d_inv[508] = 1/work1d.d[508];
  work1d.L[193] = (-work1d.L[192]*work1d.v[507])*work1d.d_inv[508];
  work1d.L[1021] = (work1d.KKT[1012])*work1d.d_inv[508];
  work1d.v[48] = work1d.L[191]*work1d.d[48];
  work1d.v[507] = work1d.L[192]*work1d.d[507];
  work1d.v[508] = work1d.L[193]*work1d.d[508];
  work1d.v[509] = work1d.KKT[1013]-work1d.L[191]*work1d.v[48]-work1d.L[192]*work1d.v[507]-work1d.L[193]*work1d.v[508];
  work1d.d[509] = work1d.v[509];
  if (work1d.d[509] > 0)
    work1d.d[509] = -settings1d.kkt_reg;
  else
    work1d.d[509] -= settings1d.kkt_reg;
  work1d.d_inv[509] = 1/work1d.d[509];
  work1d.L[1022] = (work1d.KKT[1014]-work1d.L[1021]*work1d.v[508])*work1d.d_inv[509];
  work1d.v[49] = work1d.L[194]*work1d.d[49];
  work1d.v[510] = work1d.KKT[1015]-work1d.L[194]*work1d.v[49];
  work1d.d[510] = work1d.v[510];
  if (work1d.d[510] > 0)
    work1d.d[510] = -settings1d.kkt_reg;
  else
    work1d.d[510] -= settings1d.kkt_reg;
  work1d.d_inv[510] = 1/work1d.d[510];
  work1d.L[195] = (work1d.KKT[1016])*work1d.d_inv[510];
  work1d.v[510] = work1d.L[195]*work1d.d[510];
  work1d.v[511] = 0-work1d.L[195]*work1d.v[510];
  work1d.d[511] = work1d.v[511];
  if (work1d.d[511] < 0)
    work1d.d[511] = settings1d.kkt_reg;
  else
    work1d.d[511] += settings1d.kkt_reg;
  work1d.d_inv[511] = 1/work1d.d[511];
  work1d.L[197] = (work1d.KKT[1017])*work1d.d_inv[511];
  work1d.L[199] = (work1d.KKT[1018])*work1d.d_inv[511];
  work1d.v[50] = work1d.L[196]*work1d.d[50];
  work1d.v[511] = work1d.L[197]*work1d.d[511];
  work1d.v[512] = work1d.KKT[1019]-work1d.L[196]*work1d.v[50]-work1d.L[197]*work1d.v[511];
  work1d.d[512] = work1d.v[512];
  if (work1d.d[512] > 0)
    work1d.d[512] = -settings1d.kkt_reg;
  else
    work1d.d[512] -= settings1d.kkt_reg;
  work1d.d_inv[512] = 1/work1d.d[512];
  work1d.L[200] = (-work1d.L[199]*work1d.v[511])*work1d.d_inv[512];
  work1d.L[1043] = (work1d.KKT[1020])*work1d.d_inv[512];
  work1d.v[51] = work1d.L[198]*work1d.d[51];
  work1d.v[511] = work1d.L[199]*work1d.d[511];
  work1d.v[512] = work1d.L[200]*work1d.d[512];
  work1d.v[513] = work1d.KKT[1021]-work1d.L[198]*work1d.v[51]-work1d.L[199]*work1d.v[511]-work1d.L[200]*work1d.v[512];
  work1d.d[513] = work1d.v[513];
  if (work1d.d[513] > 0)
    work1d.d[513] = -settings1d.kkt_reg;
  else
    work1d.d[513] -= settings1d.kkt_reg;
  work1d.d_inv[513] = 1/work1d.d[513];
  work1d.L[1044] = (work1d.KKT[1022]-work1d.L[1043]*work1d.v[512])*work1d.d_inv[513];
  work1d.v[52] = work1d.L[201]*work1d.d[52];
  work1d.v[514] = work1d.KKT[1023]-work1d.L[201]*work1d.v[52];
  work1d.d[514] = work1d.v[514];
  if (work1d.d[514] > 0)
    work1d.d[514] = -settings1d.kkt_reg;
  else
    work1d.d[514] -= settings1d.kkt_reg;
  work1d.d_inv[514] = 1/work1d.d[514];
  work1d.L[202] = (work1d.KKT[1024])*work1d.d_inv[514];
  work1d.v[514] = work1d.L[202]*work1d.d[514];
  work1d.v[515] = 0-work1d.L[202]*work1d.v[514];
  work1d.d[515] = work1d.v[515];
  if (work1d.d[515] < 0)
    work1d.d[515] = settings1d.kkt_reg;
  else
    work1d.d[515] += settings1d.kkt_reg;
  work1d.d_inv[515] = 1/work1d.d[515];
  work1d.L[204] = (work1d.KKT[1025])*work1d.d_inv[515];
  work1d.L[206] = (work1d.KKT[1026])*work1d.d_inv[515];
  work1d.v[53] = work1d.L[203]*work1d.d[53];
  work1d.v[515] = work1d.L[204]*work1d.d[515];
  work1d.v[516] = work1d.KKT[1027]-work1d.L[203]*work1d.v[53]-work1d.L[204]*work1d.v[515];
  work1d.d[516] = work1d.v[516];
  if (work1d.d[516] > 0)
    work1d.d[516] = -settings1d.kkt_reg;
  else
    work1d.d[516] -= settings1d.kkt_reg;
  work1d.d_inv[516] = 1/work1d.d[516];
  work1d.L[207] = (-work1d.L[206]*work1d.v[515])*work1d.d_inv[516];
  work1d.L[1065] = (work1d.KKT[1028])*work1d.d_inv[516];
  work1d.v[54] = work1d.L[205]*work1d.d[54];
  work1d.v[515] = work1d.L[206]*work1d.d[515];
  work1d.v[516] = work1d.L[207]*work1d.d[516];
  work1d.v[517] = work1d.KKT[1029]-work1d.L[205]*work1d.v[54]-work1d.L[206]*work1d.v[515]-work1d.L[207]*work1d.v[516];
  work1d.d[517] = work1d.v[517];
  if (work1d.d[517] > 0)
    work1d.d[517] = -settings1d.kkt_reg;
  else
    work1d.d[517] -= settings1d.kkt_reg;
  work1d.d_inv[517] = 1/work1d.d[517];
  work1d.L[1066] = (work1d.KKT[1030]-work1d.L[1065]*work1d.v[516])*work1d.d_inv[517];
  work1d.v[55] = work1d.L[208]*work1d.d[55];
  work1d.v[518] = work1d.KKT[1031]-work1d.L[208]*work1d.v[55];
  work1d.d[518] = work1d.v[518];
  if (work1d.d[518] > 0)
    work1d.d[518] = -settings1d.kkt_reg;
  else
    work1d.d[518] -= settings1d.kkt_reg;
  work1d.d_inv[518] = 1/work1d.d[518];
  work1d.L[209] = (work1d.KKT[1032])*work1d.d_inv[518];
  work1d.v[518] = work1d.L[209]*work1d.d[518];
  work1d.v[519] = 0-work1d.L[209]*work1d.v[518];
  work1d.d[519] = work1d.v[519];
  if (work1d.d[519] < 0)
    work1d.d[519] = settings1d.kkt_reg;
  else
    work1d.d[519] += settings1d.kkt_reg;
  work1d.d_inv[519] = 1/work1d.d[519];
  work1d.L[211] = (work1d.KKT[1033])*work1d.d_inv[519];
  work1d.L[213] = (work1d.KKT[1034])*work1d.d_inv[519];
  work1d.v[56] = work1d.L[210]*work1d.d[56];
  work1d.v[519] = work1d.L[211]*work1d.d[519];
  work1d.v[520] = work1d.KKT[1035]-work1d.L[210]*work1d.v[56]-work1d.L[211]*work1d.v[519];
  work1d.d[520] = work1d.v[520];
  if (work1d.d[520] > 0)
    work1d.d[520] = -settings1d.kkt_reg;
  else
    work1d.d[520] -= settings1d.kkt_reg;
  work1d.d_inv[520] = 1/work1d.d[520];
  work1d.L[214] = (-work1d.L[213]*work1d.v[519])*work1d.d_inv[520];
  work1d.L[1087] = (work1d.KKT[1036])*work1d.d_inv[520];
  work1d.v[57] = work1d.L[212]*work1d.d[57];
  work1d.v[519] = work1d.L[213]*work1d.d[519];
  work1d.v[520] = work1d.L[214]*work1d.d[520];
  work1d.v[521] = work1d.KKT[1037]-work1d.L[212]*work1d.v[57]-work1d.L[213]*work1d.v[519]-work1d.L[214]*work1d.v[520];
  work1d.d[521] = work1d.v[521];
  if (work1d.d[521] > 0)
    work1d.d[521] = -settings1d.kkt_reg;
  else
    work1d.d[521] -= settings1d.kkt_reg;
  work1d.d_inv[521] = 1/work1d.d[521];
  work1d.L[1088] = (work1d.KKT[1038]-work1d.L[1087]*work1d.v[520])*work1d.d_inv[521];
  work1d.v[58] = work1d.L[215]*work1d.d[58];
  work1d.v[522] = work1d.KKT[1039]-work1d.L[215]*work1d.v[58];
  work1d.d[522] = work1d.v[522];
  if (work1d.d[522] > 0)
    work1d.d[522] = -settings1d.kkt_reg;
  else
    work1d.d[522] -= settings1d.kkt_reg;
  work1d.d_inv[522] = 1/work1d.d[522];
  work1d.L[216] = (work1d.KKT[1040])*work1d.d_inv[522];
  work1d.v[522] = work1d.L[216]*work1d.d[522];
  work1d.v[523] = 0-work1d.L[216]*work1d.v[522];
  work1d.d[523] = work1d.v[523];
  if (work1d.d[523] < 0)
    work1d.d[523] = settings1d.kkt_reg;
  else
    work1d.d[523] += settings1d.kkt_reg;
  work1d.d_inv[523] = 1/work1d.d[523];
  work1d.L[218] = (work1d.KKT[1041])*work1d.d_inv[523];
  work1d.L[220] = (work1d.KKT[1042])*work1d.d_inv[523];
  work1d.v[59] = work1d.L[217]*work1d.d[59];
  work1d.v[523] = work1d.L[218]*work1d.d[523];
  work1d.v[524] = work1d.KKT[1043]-work1d.L[217]*work1d.v[59]-work1d.L[218]*work1d.v[523];
  work1d.d[524] = work1d.v[524];
  if (work1d.d[524] > 0)
    work1d.d[524] = -settings1d.kkt_reg;
  else
    work1d.d[524] -= settings1d.kkt_reg;
  work1d.d_inv[524] = 1/work1d.d[524];
  work1d.L[221] = (-work1d.L[220]*work1d.v[523])*work1d.d_inv[524];
  work1d.L[1109] = (work1d.KKT[1044])*work1d.d_inv[524];
  work1d.v[60] = work1d.L[219]*work1d.d[60];
  work1d.v[523] = work1d.L[220]*work1d.d[523];
  work1d.v[524] = work1d.L[221]*work1d.d[524];
  work1d.v[525] = work1d.KKT[1045]-work1d.L[219]*work1d.v[60]-work1d.L[220]*work1d.v[523]-work1d.L[221]*work1d.v[524];
  work1d.d[525] = work1d.v[525];
  if (work1d.d[525] > 0)
    work1d.d[525] = -settings1d.kkt_reg;
  else
    work1d.d[525] -= settings1d.kkt_reg;
  work1d.d_inv[525] = 1/work1d.d[525];
  work1d.L[1110] = (work1d.KKT[1046]-work1d.L[1109]*work1d.v[524])*work1d.d_inv[525];
  work1d.v[61] = work1d.L[222]*work1d.d[61];
  work1d.v[526] = work1d.KKT[1047]-work1d.L[222]*work1d.v[61];
  work1d.d[526] = work1d.v[526];
  if (work1d.d[526] > 0)
    work1d.d[526] = -settings1d.kkt_reg;
  else
    work1d.d[526] -= settings1d.kkt_reg;
  work1d.d_inv[526] = 1/work1d.d[526];
  work1d.L[223] = (work1d.KKT[1048])*work1d.d_inv[526];
  work1d.v[526] = work1d.L[223]*work1d.d[526];
  work1d.v[527] = 0-work1d.L[223]*work1d.v[526];
  work1d.d[527] = work1d.v[527];
  if (work1d.d[527] < 0)
    work1d.d[527] = settings1d.kkt_reg;
  else
    work1d.d[527] += settings1d.kkt_reg;
  work1d.d_inv[527] = 1/work1d.d[527];
  work1d.L[225] = (work1d.KKT[1049])*work1d.d_inv[527];
  work1d.L[227] = (work1d.KKT[1050])*work1d.d_inv[527];
  work1d.v[62] = work1d.L[224]*work1d.d[62];
  work1d.v[527] = work1d.L[225]*work1d.d[527];
  work1d.v[528] = work1d.KKT[1051]-work1d.L[224]*work1d.v[62]-work1d.L[225]*work1d.v[527];
  work1d.d[528] = work1d.v[528];
  if (work1d.d[528] > 0)
    work1d.d[528] = -settings1d.kkt_reg;
  else
    work1d.d[528] -= settings1d.kkt_reg;
  work1d.d_inv[528] = 1/work1d.d[528];
  work1d.L[228] = (-work1d.L[227]*work1d.v[527])*work1d.d_inv[528];
  work1d.L[1131] = (work1d.KKT[1052])*work1d.d_inv[528];
  work1d.v[63] = work1d.L[226]*work1d.d[63];
  work1d.v[527] = work1d.L[227]*work1d.d[527];
  work1d.v[528] = work1d.L[228]*work1d.d[528];
  work1d.v[529] = work1d.KKT[1053]-work1d.L[226]*work1d.v[63]-work1d.L[227]*work1d.v[527]-work1d.L[228]*work1d.v[528];
  work1d.d[529] = work1d.v[529];
  if (work1d.d[529] > 0)
    work1d.d[529] = -settings1d.kkt_reg;
  else
    work1d.d[529] -= settings1d.kkt_reg;
  work1d.d_inv[529] = 1/work1d.d[529];
  work1d.L[1132] = (work1d.KKT[1054]-work1d.L[1131]*work1d.v[528])*work1d.d_inv[529];
  work1d.v[64] = work1d.L[229]*work1d.d[64];
  work1d.v[530] = work1d.KKT[1055]-work1d.L[229]*work1d.v[64];
  work1d.d[530] = work1d.v[530];
  if (work1d.d[530] > 0)
    work1d.d[530] = -settings1d.kkt_reg;
  else
    work1d.d[530] -= settings1d.kkt_reg;
  work1d.d_inv[530] = 1/work1d.d[530];
  work1d.L[230] = (work1d.KKT[1056])*work1d.d_inv[530];
  work1d.v[530] = work1d.L[230]*work1d.d[530];
  work1d.v[531] = 0-work1d.L[230]*work1d.v[530];
  work1d.d[531] = work1d.v[531];
  if (work1d.d[531] < 0)
    work1d.d[531] = settings1d.kkt_reg;
  else
    work1d.d[531] += settings1d.kkt_reg;
  work1d.d_inv[531] = 1/work1d.d[531];
  work1d.L[232] = (work1d.KKT[1057])*work1d.d_inv[531];
  work1d.L[234] = (work1d.KKT[1058])*work1d.d_inv[531];
  work1d.v[65] = work1d.L[231]*work1d.d[65];
  work1d.v[531] = work1d.L[232]*work1d.d[531];
  work1d.v[532] = work1d.KKT[1059]-work1d.L[231]*work1d.v[65]-work1d.L[232]*work1d.v[531];
  work1d.d[532] = work1d.v[532];
  if (work1d.d[532] > 0)
    work1d.d[532] = -settings1d.kkt_reg;
  else
    work1d.d[532] -= settings1d.kkt_reg;
  work1d.d_inv[532] = 1/work1d.d[532];
  work1d.L[235] = (-work1d.L[234]*work1d.v[531])*work1d.d_inv[532];
  work1d.L[1153] = (work1d.KKT[1060])*work1d.d_inv[532];
  work1d.v[66] = work1d.L[233]*work1d.d[66];
  work1d.v[531] = work1d.L[234]*work1d.d[531];
  work1d.v[532] = work1d.L[235]*work1d.d[532];
  work1d.v[533] = work1d.KKT[1061]-work1d.L[233]*work1d.v[66]-work1d.L[234]*work1d.v[531]-work1d.L[235]*work1d.v[532];
  work1d.d[533] = work1d.v[533];
  if (work1d.d[533] > 0)
    work1d.d[533] = -settings1d.kkt_reg;
  else
    work1d.d[533] -= settings1d.kkt_reg;
  work1d.d_inv[533] = 1/work1d.d[533];
  work1d.L[1154] = (work1d.KKT[1062]-work1d.L[1153]*work1d.v[532])*work1d.d_inv[533];
  work1d.v[67] = work1d.L[236]*work1d.d[67];
  work1d.v[534] = work1d.KKT[1063]-work1d.L[236]*work1d.v[67];
  work1d.d[534] = work1d.v[534];
  if (work1d.d[534] > 0)
    work1d.d[534] = -settings1d.kkt_reg;
  else
    work1d.d[534] -= settings1d.kkt_reg;
  work1d.d_inv[534] = 1/work1d.d[534];
  work1d.L[237] = (work1d.KKT[1064])*work1d.d_inv[534];
  work1d.v[534] = work1d.L[237]*work1d.d[534];
  work1d.v[535] = 0-work1d.L[237]*work1d.v[534];
  work1d.d[535] = work1d.v[535];
  if (work1d.d[535] < 0)
    work1d.d[535] = settings1d.kkt_reg;
  else
    work1d.d[535] += settings1d.kkt_reg;
  work1d.d_inv[535] = 1/work1d.d[535];
  work1d.L[239] = (work1d.KKT[1065])*work1d.d_inv[535];
  work1d.L[241] = (work1d.KKT[1066])*work1d.d_inv[535];
  work1d.v[68] = work1d.L[238]*work1d.d[68];
  work1d.v[535] = work1d.L[239]*work1d.d[535];
  work1d.v[536] = work1d.KKT[1067]-work1d.L[238]*work1d.v[68]-work1d.L[239]*work1d.v[535];
  work1d.d[536] = work1d.v[536];
  if (work1d.d[536] > 0)
    work1d.d[536] = -settings1d.kkt_reg;
  else
    work1d.d[536] -= settings1d.kkt_reg;
  work1d.d_inv[536] = 1/work1d.d[536];
  work1d.L[242] = (-work1d.L[241]*work1d.v[535])*work1d.d_inv[536];
  work1d.L[1175] = (work1d.KKT[1068])*work1d.d_inv[536];
  work1d.v[69] = work1d.L[240]*work1d.d[69];
  work1d.v[535] = work1d.L[241]*work1d.d[535];
  work1d.v[536] = work1d.L[242]*work1d.d[536];
  work1d.v[537] = work1d.KKT[1069]-work1d.L[240]*work1d.v[69]-work1d.L[241]*work1d.v[535]-work1d.L[242]*work1d.v[536];
  work1d.d[537] = work1d.v[537];
  if (work1d.d[537] > 0)
    work1d.d[537] = -settings1d.kkt_reg;
  else
    work1d.d[537] -= settings1d.kkt_reg;
  work1d.d_inv[537] = 1/work1d.d[537];
  work1d.L[1176] = (work1d.KKT[1070]-work1d.L[1175]*work1d.v[536])*work1d.d_inv[537];
  work1d.v[70] = work1d.L[243]*work1d.d[70];
  work1d.v[538] = work1d.KKT[1071]-work1d.L[243]*work1d.v[70];
  work1d.d[538] = work1d.v[538];
  if (work1d.d[538] > 0)
    work1d.d[538] = -settings1d.kkt_reg;
  else
    work1d.d[538] -= settings1d.kkt_reg;
  work1d.d_inv[538] = 1/work1d.d[538];
  work1d.L[244] = (work1d.KKT[1072])*work1d.d_inv[538];
  work1d.v[538] = work1d.L[244]*work1d.d[538];
  work1d.v[539] = 0-work1d.L[244]*work1d.v[538];
  work1d.d[539] = work1d.v[539];
  if (work1d.d[539] < 0)
    work1d.d[539] = settings1d.kkt_reg;
  else
    work1d.d[539] += settings1d.kkt_reg;
  work1d.d_inv[539] = 1/work1d.d[539];
  work1d.L[246] = (work1d.KKT[1073])*work1d.d_inv[539];
  work1d.L[248] = (work1d.KKT[1074])*work1d.d_inv[539];
  work1d.v[71] = work1d.L[245]*work1d.d[71];
  work1d.v[539] = work1d.L[246]*work1d.d[539];
  work1d.v[540] = work1d.KKT[1075]-work1d.L[245]*work1d.v[71]-work1d.L[246]*work1d.v[539];
  work1d.d[540] = work1d.v[540];
  if (work1d.d[540] > 0)
    work1d.d[540] = -settings1d.kkt_reg;
  else
    work1d.d[540] -= settings1d.kkt_reg;
  work1d.d_inv[540] = 1/work1d.d[540];
  work1d.L[249] = (-work1d.L[248]*work1d.v[539])*work1d.d_inv[540];
  work1d.L[1197] = (work1d.KKT[1076])*work1d.d_inv[540];
  work1d.v[72] = work1d.L[247]*work1d.d[72];
  work1d.v[539] = work1d.L[248]*work1d.d[539];
  work1d.v[540] = work1d.L[249]*work1d.d[540];
  work1d.v[541] = work1d.KKT[1077]-work1d.L[247]*work1d.v[72]-work1d.L[248]*work1d.v[539]-work1d.L[249]*work1d.v[540];
  work1d.d[541] = work1d.v[541];
  if (work1d.d[541] > 0)
    work1d.d[541] = -settings1d.kkt_reg;
  else
    work1d.d[541] -= settings1d.kkt_reg;
  work1d.d_inv[541] = 1/work1d.d[541];
  work1d.L[1198] = (work1d.KKT[1078]-work1d.L[1197]*work1d.v[540])*work1d.d_inv[541];
  work1d.v[73] = work1d.L[250]*work1d.d[73];
  work1d.v[542] = work1d.KKT[1079]-work1d.L[250]*work1d.v[73];
  work1d.d[542] = work1d.v[542];
  if (work1d.d[542] > 0)
    work1d.d[542] = -settings1d.kkt_reg;
  else
    work1d.d[542] -= settings1d.kkt_reg;
  work1d.d_inv[542] = 1/work1d.d[542];
  work1d.L[251] = (work1d.KKT[1080])*work1d.d_inv[542];
  work1d.v[542] = work1d.L[251]*work1d.d[542];
  work1d.v[543] = 0-work1d.L[251]*work1d.v[542];
  work1d.d[543] = work1d.v[543];
  if (work1d.d[543] < 0)
    work1d.d[543] = settings1d.kkt_reg;
  else
    work1d.d[543] += settings1d.kkt_reg;
  work1d.d_inv[543] = 1/work1d.d[543];
  work1d.L[253] = (work1d.KKT[1081])*work1d.d_inv[543];
  work1d.L[255] = (work1d.KKT[1082])*work1d.d_inv[543];
  work1d.v[74] = work1d.L[252]*work1d.d[74];
  work1d.v[543] = work1d.L[253]*work1d.d[543];
  work1d.v[544] = work1d.KKT[1083]-work1d.L[252]*work1d.v[74]-work1d.L[253]*work1d.v[543];
  work1d.d[544] = work1d.v[544];
  if (work1d.d[544] > 0)
    work1d.d[544] = -settings1d.kkt_reg;
  else
    work1d.d[544] -= settings1d.kkt_reg;
  work1d.d_inv[544] = 1/work1d.d[544];
  work1d.L[256] = (-work1d.L[255]*work1d.v[543])*work1d.d_inv[544];
  work1d.L[1219] = (work1d.KKT[1084])*work1d.d_inv[544];
  work1d.v[75] = work1d.L[254]*work1d.d[75];
  work1d.v[543] = work1d.L[255]*work1d.d[543];
  work1d.v[544] = work1d.L[256]*work1d.d[544];
  work1d.v[545] = work1d.KKT[1085]-work1d.L[254]*work1d.v[75]-work1d.L[255]*work1d.v[543]-work1d.L[256]*work1d.v[544];
  work1d.d[545] = work1d.v[545];
  if (work1d.d[545] > 0)
    work1d.d[545] = -settings1d.kkt_reg;
  else
    work1d.d[545] -= settings1d.kkt_reg;
  work1d.d_inv[545] = 1/work1d.d[545];
  work1d.L[1220] = (work1d.KKT[1086]-work1d.L[1219]*work1d.v[544])*work1d.d_inv[545];
  work1d.v[76] = work1d.L[257]*work1d.d[76];
  work1d.v[546] = work1d.KKT[1087]-work1d.L[257]*work1d.v[76];
  work1d.d[546] = work1d.v[546];
  if (work1d.d[546] > 0)
    work1d.d[546] = -settings1d.kkt_reg;
  else
    work1d.d[546] -= settings1d.kkt_reg;
  work1d.d_inv[546] = 1/work1d.d[546];
  work1d.L[258] = (work1d.KKT[1088])*work1d.d_inv[546];
  work1d.v[546] = work1d.L[258]*work1d.d[546];
  work1d.v[547] = 0-work1d.L[258]*work1d.v[546];
  work1d.d[547] = work1d.v[547];
  if (work1d.d[547] < 0)
    work1d.d[547] = settings1d.kkt_reg;
  else
    work1d.d[547] += settings1d.kkt_reg;
  work1d.d_inv[547] = 1/work1d.d[547];
  work1d.L[260] = (work1d.KKT[1089])*work1d.d_inv[547];
  work1d.L[262] = (work1d.KKT[1090])*work1d.d_inv[547];
  work1d.v[77] = work1d.L[259]*work1d.d[77];
  work1d.v[547] = work1d.L[260]*work1d.d[547];
  work1d.v[548] = work1d.KKT[1091]-work1d.L[259]*work1d.v[77]-work1d.L[260]*work1d.v[547];
  work1d.d[548] = work1d.v[548];
  if (work1d.d[548] > 0)
    work1d.d[548] = -settings1d.kkt_reg;
  else
    work1d.d[548] -= settings1d.kkt_reg;
  work1d.d_inv[548] = 1/work1d.d[548];
  work1d.L[263] = (-work1d.L[262]*work1d.v[547])*work1d.d_inv[548];
  work1d.L[1241] = (work1d.KKT[1092])*work1d.d_inv[548];
  work1d.v[78] = work1d.L[261]*work1d.d[78];
  work1d.v[547] = work1d.L[262]*work1d.d[547];
  work1d.v[548] = work1d.L[263]*work1d.d[548];
  work1d.v[549] = work1d.KKT[1093]-work1d.L[261]*work1d.v[78]-work1d.L[262]*work1d.v[547]-work1d.L[263]*work1d.v[548];
  work1d.d[549] = work1d.v[549];
  if (work1d.d[549] > 0)
    work1d.d[549] = -settings1d.kkt_reg;
  else
    work1d.d[549] -= settings1d.kkt_reg;
  work1d.d_inv[549] = 1/work1d.d[549];
  work1d.L[1242] = (work1d.KKT[1094]-work1d.L[1241]*work1d.v[548])*work1d.d_inv[549];
  work1d.v[79] = work1d.L[264]*work1d.d[79];
  work1d.v[550] = work1d.KKT[1095]-work1d.L[264]*work1d.v[79];
  work1d.d[550] = work1d.v[550];
  if (work1d.d[550] > 0)
    work1d.d[550] = -settings1d.kkt_reg;
  else
    work1d.d[550] -= settings1d.kkt_reg;
  work1d.d_inv[550] = 1/work1d.d[550];
  work1d.L[265] = (work1d.KKT[1096])*work1d.d_inv[550];
  work1d.v[550] = work1d.L[265]*work1d.d[550];
  work1d.v[551] = 0-work1d.L[265]*work1d.v[550];
  work1d.d[551] = work1d.v[551];
  if (work1d.d[551] < 0)
    work1d.d[551] = settings1d.kkt_reg;
  else
    work1d.d[551] += settings1d.kkt_reg;
  work1d.d_inv[551] = 1/work1d.d[551];
  work1d.L[267] = (work1d.KKT[1097])*work1d.d_inv[551];
  work1d.L[269] = (work1d.KKT[1098])*work1d.d_inv[551];
  work1d.v[80] = work1d.L[266]*work1d.d[80];
  work1d.v[551] = work1d.L[267]*work1d.d[551];
  work1d.v[552] = work1d.KKT[1099]-work1d.L[266]*work1d.v[80]-work1d.L[267]*work1d.v[551];
  work1d.d[552] = work1d.v[552];
  if (work1d.d[552] > 0)
    work1d.d[552] = -settings1d.kkt_reg;
  else
    work1d.d[552] -= settings1d.kkt_reg;
  work1d.d_inv[552] = 1/work1d.d[552];
  work1d.L[270] = (-work1d.L[269]*work1d.v[551])*work1d.d_inv[552];
  work1d.L[1263] = (work1d.KKT[1100])*work1d.d_inv[552];
  work1d.v[81] = work1d.L[268]*work1d.d[81];
  work1d.v[551] = work1d.L[269]*work1d.d[551];
  work1d.v[552] = work1d.L[270]*work1d.d[552];
  work1d.v[553] = work1d.KKT[1101]-work1d.L[268]*work1d.v[81]-work1d.L[269]*work1d.v[551]-work1d.L[270]*work1d.v[552];
  work1d.d[553] = work1d.v[553];
  if (work1d.d[553] > 0)
    work1d.d[553] = -settings1d.kkt_reg;
  else
    work1d.d[553] -= settings1d.kkt_reg;
  work1d.d_inv[553] = 1/work1d.d[553];
  work1d.L[1264] = (work1d.KKT[1102]-work1d.L[1263]*work1d.v[552])*work1d.d_inv[553];
  work1d.v[82] = work1d.L[271]*work1d.d[82];
  work1d.v[554] = work1d.KKT[1103]-work1d.L[271]*work1d.v[82];
  work1d.d[554] = work1d.v[554];
  if (work1d.d[554] > 0)
    work1d.d[554] = -settings1d.kkt_reg;
  else
    work1d.d[554] -= settings1d.kkt_reg;
  work1d.d_inv[554] = 1/work1d.d[554];
  work1d.L[272] = (work1d.KKT[1104])*work1d.d_inv[554];
  work1d.v[554] = work1d.L[272]*work1d.d[554];
  work1d.v[555] = 0-work1d.L[272]*work1d.v[554];
  work1d.d[555] = work1d.v[555];
  if (work1d.d[555] < 0)
    work1d.d[555] = settings1d.kkt_reg;
  else
    work1d.d[555] += settings1d.kkt_reg;
  work1d.d_inv[555] = 1/work1d.d[555];
  work1d.L[274] = (work1d.KKT[1105])*work1d.d_inv[555];
  work1d.L[276] = (work1d.KKT[1106])*work1d.d_inv[555];
  work1d.v[83] = work1d.L[273]*work1d.d[83];
  work1d.v[555] = work1d.L[274]*work1d.d[555];
  work1d.v[556] = work1d.KKT[1107]-work1d.L[273]*work1d.v[83]-work1d.L[274]*work1d.v[555];
  work1d.d[556] = work1d.v[556];
  if (work1d.d[556] > 0)
    work1d.d[556] = -settings1d.kkt_reg;
  else
    work1d.d[556] -= settings1d.kkt_reg;
  work1d.d_inv[556] = 1/work1d.d[556];
  work1d.L[277] = (-work1d.L[276]*work1d.v[555])*work1d.d_inv[556];
  work1d.L[1285] = (work1d.KKT[1108])*work1d.d_inv[556];
  work1d.v[84] = work1d.L[275]*work1d.d[84];
  work1d.v[555] = work1d.L[276]*work1d.d[555];
  work1d.v[556] = work1d.L[277]*work1d.d[556];
  work1d.v[557] = work1d.KKT[1109]-work1d.L[275]*work1d.v[84]-work1d.L[276]*work1d.v[555]-work1d.L[277]*work1d.v[556];
  work1d.d[557] = work1d.v[557];
  if (work1d.d[557] > 0)
    work1d.d[557] = -settings1d.kkt_reg;
  else
    work1d.d[557] -= settings1d.kkt_reg;
  work1d.d_inv[557] = 1/work1d.d[557];
  work1d.L[1286] = (work1d.KKT[1110]-work1d.L[1285]*work1d.v[556])*work1d.d_inv[557];
  work1d.v[85] = work1d.L[278]*work1d.d[85];
  work1d.v[558] = work1d.KKT[1111]-work1d.L[278]*work1d.v[85];
  work1d.d[558] = work1d.v[558];
  if (work1d.d[558] > 0)
    work1d.d[558] = -settings1d.kkt_reg;
  else
    work1d.d[558] -= settings1d.kkt_reg;
  work1d.d_inv[558] = 1/work1d.d[558];
  work1d.L[279] = (work1d.KKT[1112])*work1d.d_inv[558];
  work1d.v[558] = work1d.L[279]*work1d.d[558];
  work1d.v[559] = 0-work1d.L[279]*work1d.v[558];
  work1d.d[559] = work1d.v[559];
  if (work1d.d[559] < 0)
    work1d.d[559] = settings1d.kkt_reg;
  else
    work1d.d[559] += settings1d.kkt_reg;
  work1d.d_inv[559] = 1/work1d.d[559];
  work1d.L[281] = (work1d.KKT[1113])*work1d.d_inv[559];
  work1d.L[283] = (work1d.KKT[1114])*work1d.d_inv[559];
  work1d.v[86] = work1d.L[280]*work1d.d[86];
  work1d.v[559] = work1d.L[281]*work1d.d[559];
  work1d.v[560] = work1d.KKT[1115]-work1d.L[280]*work1d.v[86]-work1d.L[281]*work1d.v[559];
  work1d.d[560] = work1d.v[560];
  if (work1d.d[560] > 0)
    work1d.d[560] = -settings1d.kkt_reg;
  else
    work1d.d[560] -= settings1d.kkt_reg;
  work1d.d_inv[560] = 1/work1d.d[560];
  work1d.L[284] = (-work1d.L[283]*work1d.v[559])*work1d.d_inv[560];
  work1d.L[1307] = (work1d.KKT[1116])*work1d.d_inv[560];
  work1d.v[87] = work1d.L[282]*work1d.d[87];
  work1d.v[559] = work1d.L[283]*work1d.d[559];
  work1d.v[560] = work1d.L[284]*work1d.d[560];
  work1d.v[561] = work1d.KKT[1117]-work1d.L[282]*work1d.v[87]-work1d.L[283]*work1d.v[559]-work1d.L[284]*work1d.v[560];
  work1d.d[561] = work1d.v[561];
  if (work1d.d[561] > 0)
    work1d.d[561] = -settings1d.kkt_reg;
  else
    work1d.d[561] -= settings1d.kkt_reg;
  work1d.d_inv[561] = 1/work1d.d[561];
  work1d.L[1308] = (work1d.KKT[1118]-work1d.L[1307]*work1d.v[560])*work1d.d_inv[561];
  work1d.v[88] = work1d.L[285]*work1d.d[88];
  work1d.v[562] = work1d.KKT[1119]-work1d.L[285]*work1d.v[88];
  work1d.d[562] = work1d.v[562];
  if (work1d.d[562] > 0)
    work1d.d[562] = -settings1d.kkt_reg;
  else
    work1d.d[562] -= settings1d.kkt_reg;
  work1d.d_inv[562] = 1/work1d.d[562];
  work1d.L[286] = (work1d.KKT[1120])*work1d.d_inv[562];
  work1d.v[562] = work1d.L[286]*work1d.d[562];
  work1d.v[563] = 0-work1d.L[286]*work1d.v[562];
  work1d.d[563] = work1d.v[563];
  if (work1d.d[563] < 0)
    work1d.d[563] = settings1d.kkt_reg;
  else
    work1d.d[563] += settings1d.kkt_reg;
  work1d.d_inv[563] = 1/work1d.d[563];
  work1d.L[288] = (work1d.KKT[1121])*work1d.d_inv[563];
  work1d.L[290] = (work1d.KKT[1122])*work1d.d_inv[563];
  work1d.v[89] = work1d.L[287]*work1d.d[89];
  work1d.v[563] = work1d.L[288]*work1d.d[563];
  work1d.v[564] = work1d.KKT[1123]-work1d.L[287]*work1d.v[89]-work1d.L[288]*work1d.v[563];
  work1d.d[564] = work1d.v[564];
  if (work1d.d[564] > 0)
    work1d.d[564] = -settings1d.kkt_reg;
  else
    work1d.d[564] -= settings1d.kkt_reg;
  work1d.d_inv[564] = 1/work1d.d[564];
  work1d.L[291] = (-work1d.L[290]*work1d.v[563])*work1d.d_inv[564];
  work1d.L[1329] = (work1d.KKT[1124])*work1d.d_inv[564];
  work1d.v[90] = work1d.L[289]*work1d.d[90];
  work1d.v[563] = work1d.L[290]*work1d.d[563];
  work1d.v[564] = work1d.L[291]*work1d.d[564];
  work1d.v[565] = work1d.KKT[1125]-work1d.L[289]*work1d.v[90]-work1d.L[290]*work1d.v[563]-work1d.L[291]*work1d.v[564];
  work1d.d[565] = work1d.v[565];
  if (work1d.d[565] > 0)
    work1d.d[565] = -settings1d.kkt_reg;
  else
    work1d.d[565] -= settings1d.kkt_reg;
  work1d.d_inv[565] = 1/work1d.d[565];
  work1d.L[1330] = (work1d.KKT[1126]-work1d.L[1329]*work1d.v[564])*work1d.d_inv[565];
  work1d.v[91] = work1d.L[292]*work1d.d[91];
  work1d.v[566] = work1d.KKT[1127]-work1d.L[292]*work1d.v[91];
  work1d.d[566] = work1d.v[566];
  if (work1d.d[566] > 0)
    work1d.d[566] = -settings1d.kkt_reg;
  else
    work1d.d[566] -= settings1d.kkt_reg;
  work1d.d_inv[566] = 1/work1d.d[566];
  work1d.L[293] = (work1d.KKT[1128])*work1d.d_inv[566];
  work1d.v[566] = work1d.L[293]*work1d.d[566];
  work1d.v[567] = 0-work1d.L[293]*work1d.v[566];
  work1d.d[567] = work1d.v[567];
  if (work1d.d[567] < 0)
    work1d.d[567] = settings1d.kkt_reg;
  else
    work1d.d[567] += settings1d.kkt_reg;
  work1d.d_inv[567] = 1/work1d.d[567];
  work1d.L[295] = (work1d.KKT[1129])*work1d.d_inv[567];
  work1d.L[297] = (work1d.KKT[1130])*work1d.d_inv[567];
  work1d.v[92] = work1d.L[294]*work1d.d[92];
  work1d.v[567] = work1d.L[295]*work1d.d[567];
  work1d.v[568] = work1d.KKT[1131]-work1d.L[294]*work1d.v[92]-work1d.L[295]*work1d.v[567];
  work1d.d[568] = work1d.v[568];
  if (work1d.d[568] > 0)
    work1d.d[568] = -settings1d.kkt_reg;
  else
    work1d.d[568] -= settings1d.kkt_reg;
  work1d.d_inv[568] = 1/work1d.d[568];
  work1d.L[298] = (-work1d.L[297]*work1d.v[567])*work1d.d_inv[568];
  work1d.L[1351] = (work1d.KKT[1132])*work1d.d_inv[568];
  work1d.v[93] = work1d.L[296]*work1d.d[93];
  work1d.v[567] = work1d.L[297]*work1d.d[567];
  work1d.v[568] = work1d.L[298]*work1d.d[568];
  work1d.v[569] = work1d.KKT[1133]-work1d.L[296]*work1d.v[93]-work1d.L[297]*work1d.v[567]-work1d.L[298]*work1d.v[568];
  work1d.d[569] = work1d.v[569];
  if (work1d.d[569] > 0)
    work1d.d[569] = -settings1d.kkt_reg;
  else
    work1d.d[569] -= settings1d.kkt_reg;
  work1d.d_inv[569] = 1/work1d.d[569];
  work1d.L[1352] = (work1d.KKT[1134]-work1d.L[1351]*work1d.v[568])*work1d.d_inv[569];
  work1d.v[94] = work1d.L[299]*work1d.d[94];
  work1d.v[570] = work1d.KKT[1135]-work1d.L[299]*work1d.v[94];
  work1d.d[570] = work1d.v[570];
  if (work1d.d[570] > 0)
    work1d.d[570] = -settings1d.kkt_reg;
  else
    work1d.d[570] -= settings1d.kkt_reg;
  work1d.d_inv[570] = 1/work1d.d[570];
  work1d.L[300] = (work1d.KKT[1136])*work1d.d_inv[570];
  work1d.v[570] = work1d.L[300]*work1d.d[570];
  work1d.v[571] = 0-work1d.L[300]*work1d.v[570];
  work1d.d[571] = work1d.v[571];
  if (work1d.d[571] < 0)
    work1d.d[571] = settings1d.kkt_reg;
  else
    work1d.d[571] += settings1d.kkt_reg;
  work1d.d_inv[571] = 1/work1d.d[571];
  work1d.L[302] = (work1d.KKT[1137])*work1d.d_inv[571];
  work1d.L[304] = (work1d.KKT[1138])*work1d.d_inv[571];
  work1d.v[95] = work1d.L[301]*work1d.d[95];
  work1d.v[571] = work1d.L[302]*work1d.d[571];
  work1d.v[572] = work1d.KKT[1139]-work1d.L[301]*work1d.v[95]-work1d.L[302]*work1d.v[571];
  work1d.d[572] = work1d.v[572];
  if (work1d.d[572] > 0)
    work1d.d[572] = -settings1d.kkt_reg;
  else
    work1d.d[572] -= settings1d.kkt_reg;
  work1d.d_inv[572] = 1/work1d.d[572];
  work1d.L[305] = (-work1d.L[304]*work1d.v[571])*work1d.d_inv[572];
  work1d.L[1373] = (work1d.KKT[1140])*work1d.d_inv[572];
  work1d.v[96] = work1d.L[303]*work1d.d[96];
  work1d.v[571] = work1d.L[304]*work1d.d[571];
  work1d.v[572] = work1d.L[305]*work1d.d[572];
  work1d.v[573] = work1d.KKT[1141]-work1d.L[303]*work1d.v[96]-work1d.L[304]*work1d.v[571]-work1d.L[305]*work1d.v[572];
  work1d.d[573] = work1d.v[573];
  if (work1d.d[573] > 0)
    work1d.d[573] = -settings1d.kkt_reg;
  else
    work1d.d[573] -= settings1d.kkt_reg;
  work1d.d_inv[573] = 1/work1d.d[573];
  work1d.L[1374] = (work1d.KKT[1142]-work1d.L[1373]*work1d.v[572])*work1d.d_inv[573];
  work1d.v[97] = work1d.L[306]*work1d.d[97];
  work1d.v[574] = work1d.KKT[1143]-work1d.L[306]*work1d.v[97];
  work1d.d[574] = work1d.v[574];
  if (work1d.d[574] > 0)
    work1d.d[574] = -settings1d.kkt_reg;
  else
    work1d.d[574] -= settings1d.kkt_reg;
  work1d.d_inv[574] = 1/work1d.d[574];
  work1d.L[307] = (work1d.KKT[1144])*work1d.d_inv[574];
  work1d.v[574] = work1d.L[307]*work1d.d[574];
  work1d.v[575] = 0-work1d.L[307]*work1d.v[574];
  work1d.d[575] = work1d.v[575];
  if (work1d.d[575] < 0)
    work1d.d[575] = settings1d.kkt_reg;
  else
    work1d.d[575] += settings1d.kkt_reg;
  work1d.d_inv[575] = 1/work1d.d[575];
  work1d.L[309] = (work1d.KKT[1145])*work1d.d_inv[575];
  work1d.L[311] = (work1d.KKT[1146])*work1d.d_inv[575];
  work1d.v[98] = work1d.L[308]*work1d.d[98];
  work1d.v[575] = work1d.L[309]*work1d.d[575];
  work1d.v[576] = work1d.KKT[1147]-work1d.L[308]*work1d.v[98]-work1d.L[309]*work1d.v[575];
  work1d.d[576] = work1d.v[576];
  if (work1d.d[576] > 0)
    work1d.d[576] = -settings1d.kkt_reg;
  else
    work1d.d[576] -= settings1d.kkt_reg;
  work1d.d_inv[576] = 1/work1d.d[576];
  work1d.L[312] = (-work1d.L[311]*work1d.v[575])*work1d.d_inv[576];
  work1d.L[1395] = (work1d.KKT[1148])*work1d.d_inv[576];
  work1d.v[99] = work1d.L[310]*work1d.d[99];
  work1d.v[575] = work1d.L[311]*work1d.d[575];
  work1d.v[576] = work1d.L[312]*work1d.d[576];
  work1d.v[577] = work1d.KKT[1149]-work1d.L[310]*work1d.v[99]-work1d.L[311]*work1d.v[575]-work1d.L[312]*work1d.v[576];
  work1d.d[577] = work1d.v[577];
  if (work1d.d[577] > 0)
    work1d.d[577] = -settings1d.kkt_reg;
  else
    work1d.d[577] -= settings1d.kkt_reg;
  work1d.d_inv[577] = 1/work1d.d[577];
  work1d.L[1396] = (work1d.KKT[1150]-work1d.L[1395]*work1d.v[576])*work1d.d_inv[577];
  work1d.v[100] = work1d.L[313]*work1d.d[100];
  work1d.v[578] = work1d.KKT[1151]-work1d.L[313]*work1d.v[100];
  work1d.d[578] = work1d.v[578];
  if (work1d.d[578] > 0)
    work1d.d[578] = -settings1d.kkt_reg;
  else
    work1d.d[578] -= settings1d.kkt_reg;
  work1d.d_inv[578] = 1/work1d.d[578];
  work1d.L[314] = (work1d.KKT[1152])*work1d.d_inv[578];
  work1d.v[578] = work1d.L[314]*work1d.d[578];
  work1d.v[579] = 0-work1d.L[314]*work1d.v[578];
  work1d.d[579] = work1d.v[579];
  if (work1d.d[579] < 0)
    work1d.d[579] = settings1d.kkt_reg;
  else
    work1d.d[579] += settings1d.kkt_reg;
  work1d.d_inv[579] = 1/work1d.d[579];
  work1d.L[316] = (work1d.KKT[1153])*work1d.d_inv[579];
  work1d.L[318] = (work1d.KKT[1154])*work1d.d_inv[579];
  work1d.v[101] = work1d.L[315]*work1d.d[101];
  work1d.v[579] = work1d.L[316]*work1d.d[579];
  work1d.v[580] = work1d.KKT[1155]-work1d.L[315]*work1d.v[101]-work1d.L[316]*work1d.v[579];
  work1d.d[580] = work1d.v[580];
  if (work1d.d[580] > 0)
    work1d.d[580] = -settings1d.kkt_reg;
  else
    work1d.d[580] -= settings1d.kkt_reg;
  work1d.d_inv[580] = 1/work1d.d[580];
  work1d.L[319] = (-work1d.L[318]*work1d.v[579])*work1d.d_inv[580];
  work1d.L[1417] = (work1d.KKT[1156])*work1d.d_inv[580];
  work1d.v[102] = work1d.L[317]*work1d.d[102];
  work1d.v[579] = work1d.L[318]*work1d.d[579];
  work1d.v[580] = work1d.L[319]*work1d.d[580];
  work1d.v[581] = work1d.KKT[1157]-work1d.L[317]*work1d.v[102]-work1d.L[318]*work1d.v[579]-work1d.L[319]*work1d.v[580];
  work1d.d[581] = work1d.v[581];
  if (work1d.d[581] > 0)
    work1d.d[581] = -settings1d.kkt_reg;
  else
    work1d.d[581] -= settings1d.kkt_reg;
  work1d.d_inv[581] = 1/work1d.d[581];
  work1d.L[1418] = (work1d.KKT[1158]-work1d.L[1417]*work1d.v[580])*work1d.d_inv[581];
  work1d.v[103] = work1d.L[320]*work1d.d[103];
  work1d.v[582] = work1d.KKT[1159]-work1d.L[320]*work1d.v[103];
  work1d.d[582] = work1d.v[582];
  if (work1d.d[582] > 0)
    work1d.d[582] = -settings1d.kkt_reg;
  else
    work1d.d[582] -= settings1d.kkt_reg;
  work1d.d_inv[582] = 1/work1d.d[582];
  work1d.L[321] = (work1d.KKT[1160])*work1d.d_inv[582];
  work1d.v[582] = work1d.L[321]*work1d.d[582];
  work1d.v[583] = 0-work1d.L[321]*work1d.v[582];
  work1d.d[583] = work1d.v[583];
  if (work1d.d[583] < 0)
    work1d.d[583] = settings1d.kkt_reg;
  else
    work1d.d[583] += settings1d.kkt_reg;
  work1d.d_inv[583] = 1/work1d.d[583];
  work1d.L[323] = (work1d.KKT[1161])*work1d.d_inv[583];
  work1d.L[325] = (work1d.KKT[1162])*work1d.d_inv[583];
  work1d.v[104] = work1d.L[322]*work1d.d[104];
  work1d.v[583] = work1d.L[323]*work1d.d[583];
  work1d.v[584] = work1d.KKT[1163]-work1d.L[322]*work1d.v[104]-work1d.L[323]*work1d.v[583];
  work1d.d[584] = work1d.v[584];
  if (work1d.d[584] > 0)
    work1d.d[584] = -settings1d.kkt_reg;
  else
    work1d.d[584] -= settings1d.kkt_reg;
  work1d.d_inv[584] = 1/work1d.d[584];
  work1d.L[326] = (-work1d.L[325]*work1d.v[583])*work1d.d_inv[584];
  work1d.L[1439] = (work1d.KKT[1164])*work1d.d_inv[584];
  work1d.v[105] = work1d.L[324]*work1d.d[105];
  work1d.v[583] = work1d.L[325]*work1d.d[583];
  work1d.v[584] = work1d.L[326]*work1d.d[584];
  work1d.v[585] = work1d.KKT[1165]-work1d.L[324]*work1d.v[105]-work1d.L[325]*work1d.v[583]-work1d.L[326]*work1d.v[584];
  work1d.d[585] = work1d.v[585];
  if (work1d.d[585] > 0)
    work1d.d[585] = -settings1d.kkt_reg;
  else
    work1d.d[585] -= settings1d.kkt_reg;
  work1d.d_inv[585] = 1/work1d.d[585];
  work1d.L[1440] = (work1d.KKT[1166]-work1d.L[1439]*work1d.v[584])*work1d.d_inv[585];
  work1d.v[106] = work1d.L[327]*work1d.d[106];
  work1d.v[586] = work1d.KKT[1167]-work1d.L[327]*work1d.v[106];
  work1d.d[586] = work1d.v[586];
  if (work1d.d[586] > 0)
    work1d.d[586] = -settings1d.kkt_reg;
  else
    work1d.d[586] -= settings1d.kkt_reg;
  work1d.d_inv[586] = 1/work1d.d[586];
  work1d.L[328] = (work1d.KKT[1168])*work1d.d_inv[586];
  work1d.v[586] = work1d.L[328]*work1d.d[586];
  work1d.v[587] = 0-work1d.L[328]*work1d.v[586];
  work1d.d[587] = work1d.v[587];
  if (work1d.d[587] < 0)
    work1d.d[587] = settings1d.kkt_reg;
  else
    work1d.d[587] += settings1d.kkt_reg;
  work1d.d_inv[587] = 1/work1d.d[587];
  work1d.L[330] = (work1d.KKT[1169])*work1d.d_inv[587];
  work1d.L[332] = (work1d.KKT[1170])*work1d.d_inv[587];
  work1d.v[107] = work1d.L[329]*work1d.d[107];
  work1d.v[587] = work1d.L[330]*work1d.d[587];
  work1d.v[588] = work1d.KKT[1171]-work1d.L[329]*work1d.v[107]-work1d.L[330]*work1d.v[587];
  work1d.d[588] = work1d.v[588];
  if (work1d.d[588] > 0)
    work1d.d[588] = -settings1d.kkt_reg;
  else
    work1d.d[588] -= settings1d.kkt_reg;
  work1d.d_inv[588] = 1/work1d.d[588];
  work1d.L[333] = (-work1d.L[332]*work1d.v[587])*work1d.d_inv[588];
  work1d.L[1461] = (work1d.KKT[1172])*work1d.d_inv[588];
  work1d.v[108] = work1d.L[331]*work1d.d[108];
  work1d.v[587] = work1d.L[332]*work1d.d[587];
  work1d.v[588] = work1d.L[333]*work1d.d[588];
  work1d.v[589] = work1d.KKT[1173]-work1d.L[331]*work1d.v[108]-work1d.L[332]*work1d.v[587]-work1d.L[333]*work1d.v[588];
  work1d.d[589] = work1d.v[589];
  if (work1d.d[589] > 0)
    work1d.d[589] = -settings1d.kkt_reg;
  else
    work1d.d[589] -= settings1d.kkt_reg;
  work1d.d_inv[589] = 1/work1d.d[589];
  work1d.L[1462] = (work1d.KKT[1174]-work1d.L[1461]*work1d.v[588])*work1d.d_inv[589];
  work1d.v[109] = work1d.L[334]*work1d.d[109];
  work1d.v[590] = work1d.KKT[1175]-work1d.L[334]*work1d.v[109];
  work1d.d[590] = work1d.v[590];
  if (work1d.d[590] > 0)
    work1d.d[590] = -settings1d.kkt_reg;
  else
    work1d.d[590] -= settings1d.kkt_reg;
  work1d.d_inv[590] = 1/work1d.d[590];
  work1d.L[335] = (work1d.KKT[1176])*work1d.d_inv[590];
  work1d.v[590] = work1d.L[335]*work1d.d[590];
  work1d.v[591] = 0-work1d.L[335]*work1d.v[590];
  work1d.d[591] = work1d.v[591];
  if (work1d.d[591] < 0)
    work1d.d[591] = settings1d.kkt_reg;
  else
    work1d.d[591] += settings1d.kkt_reg;
  work1d.d_inv[591] = 1/work1d.d[591];
  work1d.L[337] = (work1d.KKT[1177])*work1d.d_inv[591];
  work1d.L[339] = (work1d.KKT[1178])*work1d.d_inv[591];
  work1d.v[110] = work1d.L[336]*work1d.d[110];
  work1d.v[591] = work1d.L[337]*work1d.d[591];
  work1d.v[592] = work1d.KKT[1179]-work1d.L[336]*work1d.v[110]-work1d.L[337]*work1d.v[591];
  work1d.d[592] = work1d.v[592];
  if (work1d.d[592] > 0)
    work1d.d[592] = -settings1d.kkt_reg;
  else
    work1d.d[592] -= settings1d.kkt_reg;
  work1d.d_inv[592] = 1/work1d.d[592];
  work1d.L[340] = (-work1d.L[339]*work1d.v[591])*work1d.d_inv[592];
  work1d.L[1483] = (work1d.KKT[1180])*work1d.d_inv[592];
  work1d.v[111] = work1d.L[338]*work1d.d[111];
  work1d.v[591] = work1d.L[339]*work1d.d[591];
  work1d.v[592] = work1d.L[340]*work1d.d[592];
  work1d.v[593] = work1d.KKT[1181]-work1d.L[338]*work1d.v[111]-work1d.L[339]*work1d.v[591]-work1d.L[340]*work1d.v[592];
  work1d.d[593] = work1d.v[593];
  if (work1d.d[593] > 0)
    work1d.d[593] = -settings1d.kkt_reg;
  else
    work1d.d[593] -= settings1d.kkt_reg;
  work1d.d_inv[593] = 1/work1d.d[593];
  work1d.L[1484] = (work1d.KKT[1182]-work1d.L[1483]*work1d.v[592])*work1d.d_inv[593];
  work1d.v[112] = work1d.L[341]*work1d.d[112];
  work1d.v[594] = work1d.KKT[1183]-work1d.L[341]*work1d.v[112];
  work1d.d[594] = work1d.v[594];
  if (work1d.d[594] > 0)
    work1d.d[594] = -settings1d.kkt_reg;
  else
    work1d.d[594] -= settings1d.kkt_reg;
  work1d.d_inv[594] = 1/work1d.d[594];
  work1d.L[342] = (work1d.KKT[1184])*work1d.d_inv[594];
  work1d.v[594] = work1d.L[342]*work1d.d[594];
  work1d.v[595] = 0-work1d.L[342]*work1d.v[594];
  work1d.d[595] = work1d.v[595];
  if (work1d.d[595] < 0)
    work1d.d[595] = settings1d.kkt_reg;
  else
    work1d.d[595] += settings1d.kkt_reg;
  work1d.d_inv[595] = 1/work1d.d[595];
  work1d.L[344] = (work1d.KKT[1185])*work1d.d_inv[595];
  work1d.L[346] = (work1d.KKT[1186])*work1d.d_inv[595];
  work1d.v[113] = work1d.L[343]*work1d.d[113];
  work1d.v[595] = work1d.L[344]*work1d.d[595];
  work1d.v[596] = work1d.KKT[1187]-work1d.L[343]*work1d.v[113]-work1d.L[344]*work1d.v[595];
  work1d.d[596] = work1d.v[596];
  if (work1d.d[596] > 0)
    work1d.d[596] = -settings1d.kkt_reg;
  else
    work1d.d[596] -= settings1d.kkt_reg;
  work1d.d_inv[596] = 1/work1d.d[596];
  work1d.L[347] = (-work1d.L[346]*work1d.v[595])*work1d.d_inv[596];
  work1d.L[1509] = (work1d.KKT[1188])*work1d.d_inv[596];
  work1d.v[114] = work1d.L[345]*work1d.d[114];
  work1d.v[595] = work1d.L[346]*work1d.d[595];
  work1d.v[596] = work1d.L[347]*work1d.d[596];
  work1d.v[597] = work1d.KKT[1189]-work1d.L[345]*work1d.v[114]-work1d.L[346]*work1d.v[595]-work1d.L[347]*work1d.v[596];
  work1d.d[597] = work1d.v[597];
  if (work1d.d[597] > 0)
    work1d.d[597] = -settings1d.kkt_reg;
  else
    work1d.d[597] -= settings1d.kkt_reg;
  work1d.d_inv[597] = 1/work1d.d[597];
  work1d.L[1510] = (work1d.KKT[1190]-work1d.L[1509]*work1d.v[596])*work1d.d_inv[597];
  work1d.v[115] = work1d.L[348]*work1d.d[115];
  work1d.v[598] = work1d.KKT[1191]-work1d.L[348]*work1d.v[115];
  work1d.d[598] = work1d.v[598];
  if (work1d.d[598] > 0)
    work1d.d[598] = -settings1d.kkt_reg;
  else
    work1d.d[598] -= settings1d.kkt_reg;
  work1d.d_inv[598] = 1/work1d.d[598];
  work1d.L[349] = (work1d.KKT[1192])*work1d.d_inv[598];
  work1d.v[598] = work1d.L[349]*work1d.d[598];
  work1d.v[599] = 0-work1d.L[349]*work1d.v[598];
  work1d.d[599] = work1d.v[599];
  if (work1d.d[599] < 0)
    work1d.d[599] = settings1d.kkt_reg;
  else
    work1d.d[599] += settings1d.kkt_reg;
  work1d.d_inv[599] = 1/work1d.d[599];
  work1d.L[351] = (work1d.KKT[1193])*work1d.d_inv[599];
  work1d.L[353] = (work1d.KKT[1194])*work1d.d_inv[599];
  work1d.v[116] = work1d.L[350]*work1d.d[116];
  work1d.v[599] = work1d.L[351]*work1d.d[599];
  work1d.v[600] = work1d.KKT[1195]-work1d.L[350]*work1d.v[116]-work1d.L[351]*work1d.v[599];
  work1d.d[600] = work1d.v[600];
  if (work1d.d[600] > 0)
    work1d.d[600] = -settings1d.kkt_reg;
  else
    work1d.d[600] -= settings1d.kkt_reg;
  work1d.d_inv[600] = 1/work1d.d[600];
  work1d.L[354] = (-work1d.L[353]*work1d.v[599])*work1d.d_inv[600];
  work1d.L[1527] = (work1d.KKT[1196])*work1d.d_inv[600];
  work1d.v[117] = work1d.L[352]*work1d.d[117];
  work1d.v[599] = work1d.L[353]*work1d.d[599];
  work1d.v[600] = work1d.L[354]*work1d.d[600];
  work1d.v[601] = work1d.KKT[1197]-work1d.L[352]*work1d.v[117]-work1d.L[353]*work1d.v[599]-work1d.L[354]*work1d.v[600];
  work1d.d[601] = work1d.v[601];
  if (work1d.d[601] > 0)
    work1d.d[601] = -settings1d.kkt_reg;
  else
    work1d.d[601] -= settings1d.kkt_reg;
  work1d.d_inv[601] = 1/work1d.d[601];
  work1d.L[1528] = (work1d.KKT[1198]-work1d.L[1527]*work1d.v[600])*work1d.d_inv[601];
  work1d.v[118] = work1d.L[355]*work1d.d[118];
  work1d.v[602] = work1d.KKT[1199]-work1d.L[355]*work1d.v[118];
  work1d.d[602] = work1d.v[602];
  if (work1d.d[602] > 0)
    work1d.d[602] = -settings1d.kkt_reg;
  else
    work1d.d[602] -= settings1d.kkt_reg;
  work1d.d_inv[602] = 1/work1d.d[602];
  work1d.L[356] = (work1d.KKT[1200])*work1d.d_inv[602];
  work1d.v[602] = work1d.L[356]*work1d.d[602];
  work1d.v[603] = 0-work1d.L[356]*work1d.v[602];
  work1d.d[603] = work1d.v[603];
  if (work1d.d[603] < 0)
    work1d.d[603] = settings1d.kkt_reg;
  else
    work1d.d[603] += settings1d.kkt_reg;
  work1d.d_inv[603] = 1/work1d.d[603];
  work1d.L[358] = (work1d.KKT[1201])*work1d.d_inv[603];
  work1d.L[360] = (work1d.KKT[1202])*work1d.d_inv[603];
  work1d.v[119] = work1d.L[357]*work1d.d[119];
  work1d.v[603] = work1d.L[358]*work1d.d[603];
  work1d.v[604] = work1d.KKT[1203]-work1d.L[357]*work1d.v[119]-work1d.L[358]*work1d.v[603];
  work1d.d[604] = work1d.v[604];
  if (work1d.d[604] > 0)
    work1d.d[604] = -settings1d.kkt_reg;
  else
    work1d.d[604] -= settings1d.kkt_reg;
  work1d.d_inv[604] = 1/work1d.d[604];
  work1d.L[361] = (-work1d.L[360]*work1d.v[603])*work1d.d_inv[604];
  work1d.L[363] = (work1d.KKT[1204])*work1d.d_inv[604];
  work1d.v[120] = work1d.L[359]*work1d.d[120];
  work1d.v[603] = work1d.L[360]*work1d.d[603];
  work1d.v[604] = work1d.L[361]*work1d.d[604];
  work1d.v[605] = work1d.KKT[1205]-work1d.L[359]*work1d.v[120]-work1d.L[360]*work1d.v[603]-work1d.L[361]*work1d.v[604];
  work1d.d[605] = work1d.v[605];
  if (work1d.d[605] > 0)
    work1d.d[605] = -settings1d.kkt_reg;
  else
    work1d.d[605] -= settings1d.kkt_reg;
  work1d.d_inv[605] = 1/work1d.d[605];
  work1d.L[364] = (work1d.KKT[1206]-work1d.L[363]*work1d.v[604])*work1d.d_inv[605];
  work1d.v[360] = work1d.L[362]*work1d.d[360];
  work1d.v[604] = work1d.L[363]*work1d.d[604];
  work1d.v[605] = work1d.L[364]*work1d.d[605];
  work1d.v[606] = work1d.KKT[1207]-work1d.L[362]*work1d.v[360]-work1d.L[363]*work1d.v[604]-work1d.L[364]*work1d.v[605];
  work1d.d[606] = work1d.v[606];
  if (work1d.d[606] < 0)
    work1d.d[606] = settings1d.kkt_reg;
  else
    work1d.d[606] += settings1d.kkt_reg;
  work1d.d_inv[606] = 1/work1d.d[606];
  work1d.L[695] = (work1d.KKT[1208])*work1d.d_inv[606];
  work1d.v[121] = work1d.L[365]*work1d.d[121];
  work1d.v[607] = work1d.KKT[1209]-work1d.L[365]*work1d.v[121];
  work1d.d[607] = work1d.v[607];
  if (work1d.d[607] > 0)
    work1d.d[607] = -settings1d.kkt_reg;
  else
    work1d.d[607] -= settings1d.kkt_reg;
  work1d.d_inv[607] = 1/work1d.d[607];
  work1d.L[366] = (work1d.KKT[1210])*work1d.d_inv[607];
  work1d.v[607] = work1d.L[366]*work1d.d[607];
  work1d.v[608] = 0-work1d.L[366]*work1d.v[607];
  work1d.d[608] = work1d.v[608];
  if (work1d.d[608] < 0)
    work1d.d[608] = settings1d.kkt_reg;
  else
    work1d.d[608] += settings1d.kkt_reg;
  work1d.d_inv[608] = 1/work1d.d[608];
  work1d.L[368] = (work1d.KKT[1211])*work1d.d_inv[608];
  work1d.L[370] = (work1d.KKT[1212])*work1d.d_inv[608];
  work1d.v[122] = work1d.L[367]*work1d.d[122];
  work1d.v[608] = work1d.L[368]*work1d.d[608];
  work1d.v[609] = work1d.KKT[1213]-work1d.L[367]*work1d.v[122]-work1d.L[368]*work1d.v[608];
  work1d.d[609] = work1d.v[609];
  if (work1d.d[609] > 0)
    work1d.d[609] = -settings1d.kkt_reg;
  else
    work1d.d[609] -= settings1d.kkt_reg;
  work1d.d_inv[609] = 1/work1d.d[609];
  work1d.L[371] = (-work1d.L[370]*work1d.v[608])*work1d.d_inv[609];
  work1d.L[705] = (work1d.KKT[1214])*work1d.d_inv[609];
  work1d.v[123] = work1d.L[369]*work1d.d[123];
  work1d.v[608] = work1d.L[370]*work1d.d[608];
  work1d.v[609] = work1d.L[371]*work1d.d[609];
  work1d.v[610] = work1d.KKT[1215]-work1d.L[369]*work1d.v[123]-work1d.L[370]*work1d.v[608]-work1d.L[371]*work1d.v[609];
  work1d.d[610] = work1d.v[610];
  if (work1d.d[610] > 0)
    work1d.d[610] = -settings1d.kkt_reg;
  else
    work1d.d[610] -= settings1d.kkt_reg;
  work1d.d_inv[610] = 1/work1d.d[610];
  work1d.L[706] = (work1d.KKT[1216]-work1d.L[705]*work1d.v[609])*work1d.d_inv[610];
  work1d.v[124] = work1d.L[372]*work1d.d[124];
  work1d.v[611] = work1d.KKT[1217]-work1d.L[372]*work1d.v[124];
  work1d.d[611] = work1d.v[611];
  if (work1d.d[611] > 0)
    work1d.d[611] = -settings1d.kkt_reg;
  else
    work1d.d[611] -= settings1d.kkt_reg;
  work1d.d_inv[611] = 1/work1d.d[611];
  work1d.L[373] = (work1d.KKT[1218])*work1d.d_inv[611];
  work1d.v[611] = work1d.L[373]*work1d.d[611];
  work1d.v[612] = 0-work1d.L[373]*work1d.v[611];
  work1d.d[612] = work1d.v[612];
  if (work1d.d[612] < 0)
    work1d.d[612] = settings1d.kkt_reg;
  else
    work1d.d[612] += settings1d.kkt_reg;
  work1d.d_inv[612] = 1/work1d.d[612];
  work1d.L[375] = (work1d.KKT[1219])*work1d.d_inv[612];
  work1d.L[377] = (work1d.KKT[1220])*work1d.d_inv[612];
  work1d.v[125] = work1d.L[374]*work1d.d[125];
  work1d.v[612] = work1d.L[375]*work1d.d[612];
  work1d.v[613] = work1d.KKT[1221]-work1d.L[374]*work1d.v[125]-work1d.L[375]*work1d.v[612];
  work1d.d[613] = work1d.v[613];
  if (work1d.d[613] > 0)
    work1d.d[613] = -settings1d.kkt_reg;
  else
    work1d.d[613] -= settings1d.kkt_reg;
  work1d.d_inv[613] = 1/work1d.d[613];
  work1d.L[378] = (-work1d.L[377]*work1d.v[612])*work1d.d_inv[613];
  work1d.L[719] = (work1d.KKT[1222])*work1d.d_inv[613];
  work1d.v[126] = work1d.L[376]*work1d.d[126];
  work1d.v[612] = work1d.L[377]*work1d.d[612];
  work1d.v[613] = work1d.L[378]*work1d.d[613];
  work1d.v[614] = work1d.KKT[1223]-work1d.L[376]*work1d.v[126]-work1d.L[377]*work1d.v[612]-work1d.L[378]*work1d.v[613];
  work1d.d[614] = work1d.v[614];
  if (work1d.d[614] > 0)
    work1d.d[614] = -settings1d.kkt_reg;
  else
    work1d.d[614] -= settings1d.kkt_reg;
  work1d.d_inv[614] = 1/work1d.d[614];
  work1d.L[720] = (work1d.KKT[1224]-work1d.L[719]*work1d.v[613])*work1d.d_inv[614];
  work1d.v[127] = work1d.L[379]*work1d.d[127];
  work1d.v[615] = work1d.KKT[1225]-work1d.L[379]*work1d.v[127];
  work1d.d[615] = work1d.v[615];
  if (work1d.d[615] > 0)
    work1d.d[615] = -settings1d.kkt_reg;
  else
    work1d.d[615] -= settings1d.kkt_reg;
  work1d.d_inv[615] = 1/work1d.d[615];
  work1d.L[380] = (work1d.KKT[1226])*work1d.d_inv[615];
  work1d.v[615] = work1d.L[380]*work1d.d[615];
  work1d.v[616] = 0-work1d.L[380]*work1d.v[615];
  work1d.d[616] = work1d.v[616];
  if (work1d.d[616] < 0)
    work1d.d[616] = settings1d.kkt_reg;
  else
    work1d.d[616] += settings1d.kkt_reg;
  work1d.d_inv[616] = 1/work1d.d[616];
  work1d.L[382] = (work1d.KKT[1227])*work1d.d_inv[616];
  work1d.L[384] = (work1d.KKT[1228])*work1d.d_inv[616];
  work1d.v[128] = work1d.L[381]*work1d.d[128];
  work1d.v[616] = work1d.L[382]*work1d.d[616];
  work1d.v[617] = work1d.KKT[1229]-work1d.L[381]*work1d.v[128]-work1d.L[382]*work1d.v[616];
  work1d.d[617] = work1d.v[617];
  if (work1d.d[617] > 0)
    work1d.d[617] = -settings1d.kkt_reg;
  else
    work1d.d[617] -= settings1d.kkt_reg;
  work1d.d_inv[617] = 1/work1d.d[617];
  work1d.L[385] = (-work1d.L[384]*work1d.v[616])*work1d.d_inv[617];
  work1d.L[739] = (work1d.KKT[1230])*work1d.d_inv[617];
  work1d.v[129] = work1d.L[383]*work1d.d[129];
  work1d.v[616] = work1d.L[384]*work1d.d[616];
  work1d.v[617] = work1d.L[385]*work1d.d[617];
  work1d.v[618] = work1d.KKT[1231]-work1d.L[383]*work1d.v[129]-work1d.L[384]*work1d.v[616]-work1d.L[385]*work1d.v[617];
  work1d.d[618] = work1d.v[618];
  if (work1d.d[618] > 0)
    work1d.d[618] = -settings1d.kkt_reg;
  else
    work1d.d[618] -= settings1d.kkt_reg;
  work1d.d_inv[618] = 1/work1d.d[618];
  work1d.L[740] = (work1d.KKT[1232]-work1d.L[739]*work1d.v[617])*work1d.d_inv[618];
  work1d.v[130] = work1d.L[386]*work1d.d[130];
  work1d.v[619] = work1d.KKT[1233]-work1d.L[386]*work1d.v[130];
  work1d.d[619] = work1d.v[619];
  if (work1d.d[619] > 0)
    work1d.d[619] = -settings1d.kkt_reg;
  else
    work1d.d[619] -= settings1d.kkt_reg;
  work1d.d_inv[619] = 1/work1d.d[619];
  work1d.L[387] = (work1d.KKT[1234])*work1d.d_inv[619];
  work1d.v[619] = work1d.L[387]*work1d.d[619];
  work1d.v[620] = 0-work1d.L[387]*work1d.v[619];
  work1d.d[620] = work1d.v[620];
  if (work1d.d[620] < 0)
    work1d.d[620] = settings1d.kkt_reg;
  else
    work1d.d[620] += settings1d.kkt_reg;
  work1d.d_inv[620] = 1/work1d.d[620];
  work1d.L[389] = (work1d.KKT[1235])*work1d.d_inv[620];
  work1d.L[391] = (work1d.KKT[1236])*work1d.d_inv[620];
  work1d.v[131] = work1d.L[388]*work1d.d[131];
  work1d.v[620] = work1d.L[389]*work1d.d[620];
  work1d.v[621] = work1d.KKT[1237]-work1d.L[388]*work1d.v[131]-work1d.L[389]*work1d.v[620];
  work1d.d[621] = work1d.v[621];
  if (work1d.d[621] > 0)
    work1d.d[621] = -settings1d.kkt_reg;
  else
    work1d.d[621] -= settings1d.kkt_reg;
  work1d.d_inv[621] = 1/work1d.d[621];
  work1d.L[392] = (-work1d.L[391]*work1d.v[620])*work1d.d_inv[621];
  work1d.L[761] = (work1d.KKT[1238])*work1d.d_inv[621];
  work1d.v[132] = work1d.L[390]*work1d.d[132];
  work1d.v[620] = work1d.L[391]*work1d.d[620];
  work1d.v[621] = work1d.L[392]*work1d.d[621];
  work1d.v[622] = work1d.KKT[1239]-work1d.L[390]*work1d.v[132]-work1d.L[391]*work1d.v[620]-work1d.L[392]*work1d.v[621];
  work1d.d[622] = work1d.v[622];
  if (work1d.d[622] > 0)
    work1d.d[622] = -settings1d.kkt_reg;
  else
    work1d.d[622] -= settings1d.kkt_reg;
  work1d.d_inv[622] = 1/work1d.d[622];
  work1d.L[762] = (work1d.KKT[1240]-work1d.L[761]*work1d.v[621])*work1d.d_inv[622];
  work1d.v[133] = work1d.L[393]*work1d.d[133];
  work1d.v[623] = work1d.KKT[1241]-work1d.L[393]*work1d.v[133];
  work1d.d[623] = work1d.v[623];
  if (work1d.d[623] > 0)
    work1d.d[623] = -settings1d.kkt_reg;
  else
    work1d.d[623] -= settings1d.kkt_reg;
  work1d.d_inv[623] = 1/work1d.d[623];
  work1d.L[394] = (work1d.KKT[1242])*work1d.d_inv[623];
  work1d.v[623] = work1d.L[394]*work1d.d[623];
  work1d.v[624] = 0-work1d.L[394]*work1d.v[623];
  work1d.d[624] = work1d.v[624];
  if (work1d.d[624] < 0)
    work1d.d[624] = settings1d.kkt_reg;
  else
    work1d.d[624] += settings1d.kkt_reg;
  work1d.d_inv[624] = 1/work1d.d[624];
  work1d.L[396] = (work1d.KKT[1243])*work1d.d_inv[624];
  work1d.L[398] = (work1d.KKT[1244])*work1d.d_inv[624];
  work1d.v[134] = work1d.L[395]*work1d.d[134];
  work1d.v[624] = work1d.L[396]*work1d.d[624];
  work1d.v[625] = work1d.KKT[1245]-work1d.L[395]*work1d.v[134]-work1d.L[396]*work1d.v[624];
  work1d.d[625] = work1d.v[625];
  if (work1d.d[625] > 0)
    work1d.d[625] = -settings1d.kkt_reg;
  else
    work1d.d[625] -= settings1d.kkt_reg;
  work1d.d_inv[625] = 1/work1d.d[625];
  work1d.L[399] = (-work1d.L[398]*work1d.v[624])*work1d.d_inv[625];
  work1d.L[783] = (work1d.KKT[1246])*work1d.d_inv[625];
  work1d.v[135] = work1d.L[397]*work1d.d[135];
  work1d.v[624] = work1d.L[398]*work1d.d[624];
  work1d.v[625] = work1d.L[399]*work1d.d[625];
  work1d.v[626] = work1d.KKT[1247]-work1d.L[397]*work1d.v[135]-work1d.L[398]*work1d.v[624]-work1d.L[399]*work1d.v[625];
  work1d.d[626] = work1d.v[626];
  if (work1d.d[626] > 0)
    work1d.d[626] = -settings1d.kkt_reg;
  else
    work1d.d[626] -= settings1d.kkt_reg;
  work1d.d_inv[626] = 1/work1d.d[626];
  work1d.L[784] = (work1d.KKT[1248]-work1d.L[783]*work1d.v[625])*work1d.d_inv[626];
  work1d.v[136] = work1d.L[400]*work1d.d[136];
  work1d.v[627] = work1d.KKT[1249]-work1d.L[400]*work1d.v[136];
  work1d.d[627] = work1d.v[627];
  if (work1d.d[627] > 0)
    work1d.d[627] = -settings1d.kkt_reg;
  else
    work1d.d[627] -= settings1d.kkt_reg;
  work1d.d_inv[627] = 1/work1d.d[627];
  work1d.L[401] = (work1d.KKT[1250])*work1d.d_inv[627];
  work1d.v[627] = work1d.L[401]*work1d.d[627];
  work1d.v[628] = 0-work1d.L[401]*work1d.v[627];
  work1d.d[628] = work1d.v[628];
  if (work1d.d[628] < 0)
    work1d.d[628] = settings1d.kkt_reg;
  else
    work1d.d[628] += settings1d.kkt_reg;
  work1d.d_inv[628] = 1/work1d.d[628];
  work1d.L[403] = (work1d.KKT[1251])*work1d.d_inv[628];
  work1d.L[405] = (work1d.KKT[1252])*work1d.d_inv[628];
  work1d.v[137] = work1d.L[402]*work1d.d[137];
  work1d.v[628] = work1d.L[403]*work1d.d[628];
  work1d.v[629] = work1d.KKT[1253]-work1d.L[402]*work1d.v[137]-work1d.L[403]*work1d.v[628];
  work1d.d[629] = work1d.v[629];
  if (work1d.d[629] > 0)
    work1d.d[629] = -settings1d.kkt_reg;
  else
    work1d.d[629] -= settings1d.kkt_reg;
  work1d.d_inv[629] = 1/work1d.d[629];
  work1d.L[406] = (-work1d.L[405]*work1d.v[628])*work1d.d_inv[629];
  work1d.L[805] = (work1d.KKT[1254])*work1d.d_inv[629];
  work1d.v[138] = work1d.L[404]*work1d.d[138];
  work1d.v[628] = work1d.L[405]*work1d.d[628];
  work1d.v[629] = work1d.L[406]*work1d.d[629];
  work1d.v[630] = work1d.KKT[1255]-work1d.L[404]*work1d.v[138]-work1d.L[405]*work1d.v[628]-work1d.L[406]*work1d.v[629];
  work1d.d[630] = work1d.v[630];
  if (work1d.d[630] > 0)
    work1d.d[630] = -settings1d.kkt_reg;
  else
    work1d.d[630] -= settings1d.kkt_reg;
  work1d.d_inv[630] = 1/work1d.d[630];
  work1d.L[806] = (work1d.KKT[1256]-work1d.L[805]*work1d.v[629])*work1d.d_inv[630];
  work1d.v[139] = work1d.L[407]*work1d.d[139];
  work1d.v[631] = work1d.KKT[1257]-work1d.L[407]*work1d.v[139];
  work1d.d[631] = work1d.v[631];
  if (work1d.d[631] > 0)
    work1d.d[631] = -settings1d.kkt_reg;
  else
    work1d.d[631] -= settings1d.kkt_reg;
  work1d.d_inv[631] = 1/work1d.d[631];
  work1d.L[408] = (work1d.KKT[1258])*work1d.d_inv[631];
  work1d.v[631] = work1d.L[408]*work1d.d[631];
  work1d.v[632] = 0-work1d.L[408]*work1d.v[631];
  work1d.d[632] = work1d.v[632];
  if (work1d.d[632] < 0)
    work1d.d[632] = settings1d.kkt_reg;
  else
    work1d.d[632] += settings1d.kkt_reg;
  work1d.d_inv[632] = 1/work1d.d[632];
  work1d.L[410] = (work1d.KKT[1259])*work1d.d_inv[632];
  work1d.L[412] = (work1d.KKT[1260])*work1d.d_inv[632];
  work1d.v[140] = work1d.L[409]*work1d.d[140];
  work1d.v[632] = work1d.L[410]*work1d.d[632];
  work1d.v[633] = work1d.KKT[1261]-work1d.L[409]*work1d.v[140]-work1d.L[410]*work1d.v[632];
  work1d.d[633] = work1d.v[633];
  if (work1d.d[633] > 0)
    work1d.d[633] = -settings1d.kkt_reg;
  else
    work1d.d[633] -= settings1d.kkt_reg;
  work1d.d_inv[633] = 1/work1d.d[633];
  work1d.L[413] = (-work1d.L[412]*work1d.v[632])*work1d.d_inv[633];
  work1d.L[827] = (work1d.KKT[1262])*work1d.d_inv[633];
  work1d.v[141] = work1d.L[411]*work1d.d[141];
  work1d.v[632] = work1d.L[412]*work1d.d[632];
  work1d.v[633] = work1d.L[413]*work1d.d[633];
  work1d.v[634] = work1d.KKT[1263]-work1d.L[411]*work1d.v[141]-work1d.L[412]*work1d.v[632]-work1d.L[413]*work1d.v[633];
  work1d.d[634] = work1d.v[634];
  if (work1d.d[634] > 0)
    work1d.d[634] = -settings1d.kkt_reg;
  else
    work1d.d[634] -= settings1d.kkt_reg;
  work1d.d_inv[634] = 1/work1d.d[634];
  work1d.L[828] = (work1d.KKT[1264]-work1d.L[827]*work1d.v[633])*work1d.d_inv[634];
  work1d.v[142] = work1d.L[414]*work1d.d[142];
  work1d.v[635] = work1d.KKT[1265]-work1d.L[414]*work1d.v[142];
  work1d.d[635] = work1d.v[635];
  if (work1d.d[635] > 0)
    work1d.d[635] = -settings1d.kkt_reg;
  else
    work1d.d[635] -= settings1d.kkt_reg;
  work1d.d_inv[635] = 1/work1d.d[635];
  work1d.L[415] = (work1d.KKT[1266])*work1d.d_inv[635];
  work1d.v[635] = work1d.L[415]*work1d.d[635];
  work1d.v[636] = 0-work1d.L[415]*work1d.v[635];
  work1d.d[636] = work1d.v[636];
  if (work1d.d[636] < 0)
    work1d.d[636] = settings1d.kkt_reg;
  else
    work1d.d[636] += settings1d.kkt_reg;
  work1d.d_inv[636] = 1/work1d.d[636];
  work1d.L[417] = (work1d.KKT[1267])*work1d.d_inv[636];
  work1d.L[419] = (work1d.KKT[1268])*work1d.d_inv[636];
  work1d.v[143] = work1d.L[416]*work1d.d[143];
  work1d.v[636] = work1d.L[417]*work1d.d[636];
  work1d.v[637] = work1d.KKT[1269]-work1d.L[416]*work1d.v[143]-work1d.L[417]*work1d.v[636];
  work1d.d[637] = work1d.v[637];
  if (work1d.d[637] > 0)
    work1d.d[637] = -settings1d.kkt_reg;
  else
    work1d.d[637] -= settings1d.kkt_reg;
  work1d.d_inv[637] = 1/work1d.d[637];
  work1d.L[420] = (-work1d.L[419]*work1d.v[636])*work1d.d_inv[637];
  work1d.L[849] = (work1d.KKT[1270])*work1d.d_inv[637];
  work1d.v[144] = work1d.L[418]*work1d.d[144];
  work1d.v[636] = work1d.L[419]*work1d.d[636];
  work1d.v[637] = work1d.L[420]*work1d.d[637];
  work1d.v[638] = work1d.KKT[1271]-work1d.L[418]*work1d.v[144]-work1d.L[419]*work1d.v[636]-work1d.L[420]*work1d.v[637];
  work1d.d[638] = work1d.v[638];
  if (work1d.d[638] > 0)
    work1d.d[638] = -settings1d.kkt_reg;
  else
    work1d.d[638] -= settings1d.kkt_reg;
  work1d.d_inv[638] = 1/work1d.d[638];
  work1d.L[850] = (work1d.KKT[1272]-work1d.L[849]*work1d.v[637])*work1d.d_inv[638];
  work1d.v[145] = work1d.L[421]*work1d.d[145];
  work1d.v[639] = work1d.KKT[1273]-work1d.L[421]*work1d.v[145];
  work1d.d[639] = work1d.v[639];
  if (work1d.d[639] > 0)
    work1d.d[639] = -settings1d.kkt_reg;
  else
    work1d.d[639] -= settings1d.kkt_reg;
  work1d.d_inv[639] = 1/work1d.d[639];
  work1d.L[422] = (work1d.KKT[1274])*work1d.d_inv[639];
  work1d.v[639] = work1d.L[422]*work1d.d[639];
  work1d.v[640] = 0-work1d.L[422]*work1d.v[639];
  work1d.d[640] = work1d.v[640];
  if (work1d.d[640] < 0)
    work1d.d[640] = settings1d.kkt_reg;
  else
    work1d.d[640] += settings1d.kkt_reg;
  work1d.d_inv[640] = 1/work1d.d[640];
  work1d.L[424] = (work1d.KKT[1275])*work1d.d_inv[640];
  work1d.L[426] = (work1d.KKT[1276])*work1d.d_inv[640];
  work1d.v[146] = work1d.L[423]*work1d.d[146];
  work1d.v[640] = work1d.L[424]*work1d.d[640];
  work1d.v[641] = work1d.KKT[1277]-work1d.L[423]*work1d.v[146]-work1d.L[424]*work1d.v[640];
  work1d.d[641] = work1d.v[641];
  if (work1d.d[641] > 0)
    work1d.d[641] = -settings1d.kkt_reg;
  else
    work1d.d[641] -= settings1d.kkt_reg;
  work1d.d_inv[641] = 1/work1d.d[641];
  work1d.L[427] = (-work1d.L[426]*work1d.v[640])*work1d.d_inv[641];
  work1d.L[871] = (work1d.KKT[1278])*work1d.d_inv[641];
  work1d.v[147] = work1d.L[425]*work1d.d[147];
  work1d.v[640] = work1d.L[426]*work1d.d[640];
  work1d.v[641] = work1d.L[427]*work1d.d[641];
  work1d.v[642] = work1d.KKT[1279]-work1d.L[425]*work1d.v[147]-work1d.L[426]*work1d.v[640]-work1d.L[427]*work1d.v[641];
  work1d.d[642] = work1d.v[642];
  if (work1d.d[642] > 0)
    work1d.d[642] = -settings1d.kkt_reg;
  else
    work1d.d[642] -= settings1d.kkt_reg;
  work1d.d_inv[642] = 1/work1d.d[642];
  work1d.L[872] = (work1d.KKT[1280]-work1d.L[871]*work1d.v[641])*work1d.d_inv[642];
  work1d.v[148] = work1d.L[428]*work1d.d[148];
  work1d.v[643] = work1d.KKT[1281]-work1d.L[428]*work1d.v[148];
  work1d.d[643] = work1d.v[643];
  if (work1d.d[643] > 0)
    work1d.d[643] = -settings1d.kkt_reg;
  else
    work1d.d[643] -= settings1d.kkt_reg;
  work1d.d_inv[643] = 1/work1d.d[643];
  work1d.L[429] = (work1d.KKT[1282])*work1d.d_inv[643];
  work1d.v[643] = work1d.L[429]*work1d.d[643];
  work1d.v[644] = 0-work1d.L[429]*work1d.v[643];
  work1d.d[644] = work1d.v[644];
  if (work1d.d[644] < 0)
    work1d.d[644] = settings1d.kkt_reg;
  else
    work1d.d[644] += settings1d.kkt_reg;
  work1d.d_inv[644] = 1/work1d.d[644];
  work1d.L[431] = (work1d.KKT[1283])*work1d.d_inv[644];
  work1d.L[433] = (work1d.KKT[1284])*work1d.d_inv[644];
  work1d.v[149] = work1d.L[430]*work1d.d[149];
  work1d.v[644] = work1d.L[431]*work1d.d[644];
  work1d.v[645] = work1d.KKT[1285]-work1d.L[430]*work1d.v[149]-work1d.L[431]*work1d.v[644];
  work1d.d[645] = work1d.v[645];
  if (work1d.d[645] > 0)
    work1d.d[645] = -settings1d.kkt_reg;
  else
    work1d.d[645] -= settings1d.kkt_reg;
  work1d.d_inv[645] = 1/work1d.d[645];
  work1d.L[434] = (-work1d.L[433]*work1d.v[644])*work1d.d_inv[645];
  work1d.L[893] = (work1d.KKT[1286])*work1d.d_inv[645];
  work1d.v[150] = work1d.L[432]*work1d.d[150];
  work1d.v[644] = work1d.L[433]*work1d.d[644];
  work1d.v[645] = work1d.L[434]*work1d.d[645];
  work1d.v[646] = work1d.KKT[1287]-work1d.L[432]*work1d.v[150]-work1d.L[433]*work1d.v[644]-work1d.L[434]*work1d.v[645];
  work1d.d[646] = work1d.v[646];
  if (work1d.d[646] > 0)
    work1d.d[646] = -settings1d.kkt_reg;
  else
    work1d.d[646] -= settings1d.kkt_reg;
  work1d.d_inv[646] = 1/work1d.d[646];
  work1d.L[894] = (work1d.KKT[1288]-work1d.L[893]*work1d.v[645])*work1d.d_inv[646];
  work1d.v[151] = work1d.L[435]*work1d.d[151];
  work1d.v[647] = work1d.KKT[1289]-work1d.L[435]*work1d.v[151];
  work1d.d[647] = work1d.v[647];
  if (work1d.d[647] > 0)
    work1d.d[647] = -settings1d.kkt_reg;
  else
    work1d.d[647] -= settings1d.kkt_reg;
  work1d.d_inv[647] = 1/work1d.d[647];
  work1d.L[436] = (work1d.KKT[1290])*work1d.d_inv[647];
  work1d.v[647] = work1d.L[436]*work1d.d[647];
  work1d.v[648] = 0-work1d.L[436]*work1d.v[647];
  work1d.d[648] = work1d.v[648];
  if (work1d.d[648] < 0)
    work1d.d[648] = settings1d.kkt_reg;
  else
    work1d.d[648] += settings1d.kkt_reg;
  work1d.d_inv[648] = 1/work1d.d[648];
  work1d.L[438] = (work1d.KKT[1291])*work1d.d_inv[648];
  work1d.L[440] = (work1d.KKT[1292])*work1d.d_inv[648];
  work1d.v[152] = work1d.L[437]*work1d.d[152];
  work1d.v[648] = work1d.L[438]*work1d.d[648];
  work1d.v[649] = work1d.KKT[1293]-work1d.L[437]*work1d.v[152]-work1d.L[438]*work1d.v[648];
  work1d.d[649] = work1d.v[649];
  if (work1d.d[649] > 0)
    work1d.d[649] = -settings1d.kkt_reg;
  else
    work1d.d[649] -= settings1d.kkt_reg;
  work1d.d_inv[649] = 1/work1d.d[649];
  work1d.L[441] = (-work1d.L[440]*work1d.v[648])*work1d.d_inv[649];
  work1d.L[915] = (work1d.KKT[1294])*work1d.d_inv[649];
  work1d.v[153] = work1d.L[439]*work1d.d[153];
  work1d.v[648] = work1d.L[440]*work1d.d[648];
  work1d.v[649] = work1d.L[441]*work1d.d[649];
  work1d.v[650] = work1d.KKT[1295]-work1d.L[439]*work1d.v[153]-work1d.L[440]*work1d.v[648]-work1d.L[441]*work1d.v[649];
  work1d.d[650] = work1d.v[650];
  if (work1d.d[650] > 0)
    work1d.d[650] = -settings1d.kkt_reg;
  else
    work1d.d[650] -= settings1d.kkt_reg;
  work1d.d_inv[650] = 1/work1d.d[650];
  work1d.L[916] = (work1d.KKT[1296]-work1d.L[915]*work1d.v[649])*work1d.d_inv[650];
  work1d.v[154] = work1d.L[442]*work1d.d[154];
  work1d.v[651] = work1d.KKT[1297]-work1d.L[442]*work1d.v[154];
  work1d.d[651] = work1d.v[651];
  if (work1d.d[651] > 0)
    work1d.d[651] = -settings1d.kkt_reg;
  else
    work1d.d[651] -= settings1d.kkt_reg;
  work1d.d_inv[651] = 1/work1d.d[651];
  work1d.L[443] = (work1d.KKT[1298])*work1d.d_inv[651];
  work1d.v[651] = work1d.L[443]*work1d.d[651];
  work1d.v[652] = 0-work1d.L[443]*work1d.v[651];
  work1d.d[652] = work1d.v[652];
  if (work1d.d[652] < 0)
    work1d.d[652] = settings1d.kkt_reg;
  else
    work1d.d[652] += settings1d.kkt_reg;
  work1d.d_inv[652] = 1/work1d.d[652];
  work1d.L[445] = (work1d.KKT[1299])*work1d.d_inv[652];
  work1d.L[447] = (work1d.KKT[1300])*work1d.d_inv[652];
  work1d.v[155] = work1d.L[444]*work1d.d[155];
  work1d.v[652] = work1d.L[445]*work1d.d[652];
  work1d.v[653] = work1d.KKT[1301]-work1d.L[444]*work1d.v[155]-work1d.L[445]*work1d.v[652];
  work1d.d[653] = work1d.v[653];
  if (work1d.d[653] > 0)
    work1d.d[653] = -settings1d.kkt_reg;
  else
    work1d.d[653] -= settings1d.kkt_reg;
  work1d.d_inv[653] = 1/work1d.d[653];
  work1d.L[448] = (-work1d.L[447]*work1d.v[652])*work1d.d_inv[653];
  work1d.L[937] = (work1d.KKT[1302])*work1d.d_inv[653];
  work1d.v[156] = work1d.L[446]*work1d.d[156];
  work1d.v[652] = work1d.L[447]*work1d.d[652];
  work1d.v[653] = work1d.L[448]*work1d.d[653];
  work1d.v[654] = work1d.KKT[1303]-work1d.L[446]*work1d.v[156]-work1d.L[447]*work1d.v[652]-work1d.L[448]*work1d.v[653];
  work1d.d[654] = work1d.v[654];
  if (work1d.d[654] > 0)
    work1d.d[654] = -settings1d.kkt_reg;
  else
    work1d.d[654] -= settings1d.kkt_reg;
  work1d.d_inv[654] = 1/work1d.d[654];
  work1d.L[938] = (work1d.KKT[1304]-work1d.L[937]*work1d.v[653])*work1d.d_inv[654];
  work1d.v[157] = work1d.L[449]*work1d.d[157];
  work1d.v[655] = work1d.KKT[1305]-work1d.L[449]*work1d.v[157];
  work1d.d[655] = work1d.v[655];
  if (work1d.d[655] > 0)
    work1d.d[655] = -settings1d.kkt_reg;
  else
    work1d.d[655] -= settings1d.kkt_reg;
  work1d.d_inv[655] = 1/work1d.d[655];
  work1d.L[450] = (work1d.KKT[1306])*work1d.d_inv[655];
  work1d.v[655] = work1d.L[450]*work1d.d[655];
  work1d.v[656] = 0-work1d.L[450]*work1d.v[655];
  work1d.d[656] = work1d.v[656];
  if (work1d.d[656] < 0)
    work1d.d[656] = settings1d.kkt_reg;
  else
    work1d.d[656] += settings1d.kkt_reg;
  work1d.d_inv[656] = 1/work1d.d[656];
  work1d.L[452] = (work1d.KKT[1307])*work1d.d_inv[656];
  work1d.L[454] = (work1d.KKT[1308])*work1d.d_inv[656];
  work1d.v[158] = work1d.L[451]*work1d.d[158];
  work1d.v[656] = work1d.L[452]*work1d.d[656];
  work1d.v[657] = work1d.KKT[1309]-work1d.L[451]*work1d.v[158]-work1d.L[452]*work1d.v[656];
  work1d.d[657] = work1d.v[657];
  if (work1d.d[657] > 0)
    work1d.d[657] = -settings1d.kkt_reg;
  else
    work1d.d[657] -= settings1d.kkt_reg;
  work1d.d_inv[657] = 1/work1d.d[657];
  work1d.L[455] = (-work1d.L[454]*work1d.v[656])*work1d.d_inv[657];
  work1d.L[959] = (work1d.KKT[1310])*work1d.d_inv[657];
  work1d.v[159] = work1d.L[453]*work1d.d[159];
  work1d.v[656] = work1d.L[454]*work1d.d[656];
  work1d.v[657] = work1d.L[455]*work1d.d[657];
  work1d.v[658] = work1d.KKT[1311]-work1d.L[453]*work1d.v[159]-work1d.L[454]*work1d.v[656]-work1d.L[455]*work1d.v[657];
  work1d.d[658] = work1d.v[658];
  if (work1d.d[658] > 0)
    work1d.d[658] = -settings1d.kkt_reg;
  else
    work1d.d[658] -= settings1d.kkt_reg;
  work1d.d_inv[658] = 1/work1d.d[658];
  work1d.L[960] = (work1d.KKT[1312]-work1d.L[959]*work1d.v[657])*work1d.d_inv[658];
  work1d.v[160] = work1d.L[456]*work1d.d[160];
  work1d.v[659] = work1d.KKT[1313]-work1d.L[456]*work1d.v[160];
  work1d.d[659] = work1d.v[659];
  if (work1d.d[659] > 0)
    work1d.d[659] = -settings1d.kkt_reg;
  else
    work1d.d[659] -= settings1d.kkt_reg;
  work1d.d_inv[659] = 1/work1d.d[659];
  work1d.L[457] = (work1d.KKT[1314])*work1d.d_inv[659];
  work1d.v[659] = work1d.L[457]*work1d.d[659];
  work1d.v[660] = 0-work1d.L[457]*work1d.v[659];
  work1d.d[660] = work1d.v[660];
  if (work1d.d[660] < 0)
    work1d.d[660] = settings1d.kkt_reg;
  else
    work1d.d[660] += settings1d.kkt_reg;
  work1d.d_inv[660] = 1/work1d.d[660];
  work1d.L[459] = (work1d.KKT[1315])*work1d.d_inv[660];
  work1d.L[461] = (work1d.KKT[1316])*work1d.d_inv[660];
  work1d.v[161] = work1d.L[458]*work1d.d[161];
  work1d.v[660] = work1d.L[459]*work1d.d[660];
  work1d.v[661] = work1d.KKT[1317]-work1d.L[458]*work1d.v[161]-work1d.L[459]*work1d.v[660];
  work1d.d[661] = work1d.v[661];
  if (work1d.d[661] > 0)
    work1d.d[661] = -settings1d.kkt_reg;
  else
    work1d.d[661] -= settings1d.kkt_reg;
  work1d.d_inv[661] = 1/work1d.d[661];
  work1d.L[462] = (-work1d.L[461]*work1d.v[660])*work1d.d_inv[661];
  work1d.L[981] = (work1d.KKT[1318])*work1d.d_inv[661];
  work1d.v[162] = work1d.L[460]*work1d.d[162];
  work1d.v[660] = work1d.L[461]*work1d.d[660];
  work1d.v[661] = work1d.L[462]*work1d.d[661];
  work1d.v[662] = work1d.KKT[1319]-work1d.L[460]*work1d.v[162]-work1d.L[461]*work1d.v[660]-work1d.L[462]*work1d.v[661];
  work1d.d[662] = work1d.v[662];
  if (work1d.d[662] > 0)
    work1d.d[662] = -settings1d.kkt_reg;
  else
    work1d.d[662] -= settings1d.kkt_reg;
  work1d.d_inv[662] = 1/work1d.d[662];
  work1d.L[982] = (work1d.KKT[1320]-work1d.L[981]*work1d.v[661])*work1d.d_inv[662];
  work1d.v[163] = work1d.L[463]*work1d.d[163];
  work1d.v[663] = work1d.KKT[1321]-work1d.L[463]*work1d.v[163];
  work1d.d[663] = work1d.v[663];
  if (work1d.d[663] > 0)
    work1d.d[663] = -settings1d.kkt_reg;
  else
    work1d.d[663] -= settings1d.kkt_reg;
  work1d.d_inv[663] = 1/work1d.d[663];
  work1d.L[464] = (work1d.KKT[1322])*work1d.d_inv[663];
  work1d.v[663] = work1d.L[464]*work1d.d[663];
  work1d.v[664] = 0-work1d.L[464]*work1d.v[663];
  work1d.d[664] = work1d.v[664];
  if (work1d.d[664] < 0)
    work1d.d[664] = settings1d.kkt_reg;
  else
    work1d.d[664] += settings1d.kkt_reg;
  work1d.d_inv[664] = 1/work1d.d[664];
  work1d.L[466] = (work1d.KKT[1323])*work1d.d_inv[664];
  work1d.L[468] = (work1d.KKT[1324])*work1d.d_inv[664];
  work1d.v[164] = work1d.L[465]*work1d.d[164];
  work1d.v[664] = work1d.L[466]*work1d.d[664];
  work1d.v[665] = work1d.KKT[1325]-work1d.L[465]*work1d.v[164]-work1d.L[466]*work1d.v[664];
  work1d.d[665] = work1d.v[665];
  if (work1d.d[665] > 0)
    work1d.d[665] = -settings1d.kkt_reg;
  else
    work1d.d[665] -= settings1d.kkt_reg;
  work1d.d_inv[665] = 1/work1d.d[665];
  work1d.L[469] = (-work1d.L[468]*work1d.v[664])*work1d.d_inv[665];
  work1d.L[1003] = (work1d.KKT[1326])*work1d.d_inv[665];
  work1d.v[165] = work1d.L[467]*work1d.d[165];
  work1d.v[664] = work1d.L[468]*work1d.d[664];
  work1d.v[665] = work1d.L[469]*work1d.d[665];
  work1d.v[666] = work1d.KKT[1327]-work1d.L[467]*work1d.v[165]-work1d.L[468]*work1d.v[664]-work1d.L[469]*work1d.v[665];
  work1d.d[666] = work1d.v[666];
  if (work1d.d[666] > 0)
    work1d.d[666] = -settings1d.kkt_reg;
  else
    work1d.d[666] -= settings1d.kkt_reg;
  work1d.d_inv[666] = 1/work1d.d[666];
  work1d.L[1004] = (work1d.KKT[1328]-work1d.L[1003]*work1d.v[665])*work1d.d_inv[666];
  work1d.v[166] = work1d.L[470]*work1d.d[166];
  work1d.v[667] = work1d.KKT[1329]-work1d.L[470]*work1d.v[166];
  work1d.d[667] = work1d.v[667];
  if (work1d.d[667] > 0)
    work1d.d[667] = -settings1d.kkt_reg;
  else
    work1d.d[667] -= settings1d.kkt_reg;
  work1d.d_inv[667] = 1/work1d.d[667];
  work1d.L[471] = (work1d.KKT[1330])*work1d.d_inv[667];
  work1d.v[667] = work1d.L[471]*work1d.d[667];
  work1d.v[668] = 0-work1d.L[471]*work1d.v[667];
  work1d.d[668] = work1d.v[668];
  if (work1d.d[668] < 0)
    work1d.d[668] = settings1d.kkt_reg;
  else
    work1d.d[668] += settings1d.kkt_reg;
  work1d.d_inv[668] = 1/work1d.d[668];
  work1d.L[473] = (work1d.KKT[1331])*work1d.d_inv[668];
  work1d.L[475] = (work1d.KKT[1332])*work1d.d_inv[668];
  work1d.v[167] = work1d.L[472]*work1d.d[167];
  work1d.v[668] = work1d.L[473]*work1d.d[668];
  work1d.v[669] = work1d.KKT[1333]-work1d.L[472]*work1d.v[167]-work1d.L[473]*work1d.v[668];
  work1d.d[669] = work1d.v[669];
  if (work1d.d[669] > 0)
    work1d.d[669] = -settings1d.kkt_reg;
  else
    work1d.d[669] -= settings1d.kkt_reg;
  work1d.d_inv[669] = 1/work1d.d[669];
  work1d.L[476] = (-work1d.L[475]*work1d.v[668])*work1d.d_inv[669];
  work1d.L[1025] = (work1d.KKT[1334])*work1d.d_inv[669];
  work1d.v[168] = work1d.L[474]*work1d.d[168];
  work1d.v[668] = work1d.L[475]*work1d.d[668];
  work1d.v[669] = work1d.L[476]*work1d.d[669];
  work1d.v[670] = work1d.KKT[1335]-work1d.L[474]*work1d.v[168]-work1d.L[475]*work1d.v[668]-work1d.L[476]*work1d.v[669];
  work1d.d[670] = work1d.v[670];
  if (work1d.d[670] > 0)
    work1d.d[670] = -settings1d.kkt_reg;
  else
    work1d.d[670] -= settings1d.kkt_reg;
  work1d.d_inv[670] = 1/work1d.d[670];
  work1d.L[1026] = (work1d.KKT[1336]-work1d.L[1025]*work1d.v[669])*work1d.d_inv[670];
  work1d.v[169] = work1d.L[477]*work1d.d[169];
  work1d.v[671] = work1d.KKT[1337]-work1d.L[477]*work1d.v[169];
  work1d.d[671] = work1d.v[671];
  if (work1d.d[671] > 0)
    work1d.d[671] = -settings1d.kkt_reg;
  else
    work1d.d[671] -= settings1d.kkt_reg;
  work1d.d_inv[671] = 1/work1d.d[671];
  work1d.L[478] = (work1d.KKT[1338])*work1d.d_inv[671];
  work1d.v[671] = work1d.L[478]*work1d.d[671];
  work1d.v[672] = 0-work1d.L[478]*work1d.v[671];
  work1d.d[672] = work1d.v[672];
  if (work1d.d[672] < 0)
    work1d.d[672] = settings1d.kkt_reg;
  else
    work1d.d[672] += settings1d.kkt_reg;
  work1d.d_inv[672] = 1/work1d.d[672];
  work1d.L[480] = (work1d.KKT[1339])*work1d.d_inv[672];
  work1d.L[482] = (work1d.KKT[1340])*work1d.d_inv[672];
  work1d.v[170] = work1d.L[479]*work1d.d[170];
  work1d.v[672] = work1d.L[480]*work1d.d[672];
  work1d.v[673] = work1d.KKT[1341]-work1d.L[479]*work1d.v[170]-work1d.L[480]*work1d.v[672];
  work1d.d[673] = work1d.v[673];
  if (work1d.d[673] > 0)
    work1d.d[673] = -settings1d.kkt_reg;
  else
    work1d.d[673] -= settings1d.kkt_reg;
  work1d.d_inv[673] = 1/work1d.d[673];
  work1d.L[483] = (-work1d.L[482]*work1d.v[672])*work1d.d_inv[673];
  work1d.L[1047] = (work1d.KKT[1342])*work1d.d_inv[673];
  work1d.v[171] = work1d.L[481]*work1d.d[171];
  work1d.v[672] = work1d.L[482]*work1d.d[672];
  work1d.v[673] = work1d.L[483]*work1d.d[673];
  work1d.v[674] = work1d.KKT[1343]-work1d.L[481]*work1d.v[171]-work1d.L[482]*work1d.v[672]-work1d.L[483]*work1d.v[673];
  work1d.d[674] = work1d.v[674];
  if (work1d.d[674] > 0)
    work1d.d[674] = -settings1d.kkt_reg;
  else
    work1d.d[674] -= settings1d.kkt_reg;
  work1d.d_inv[674] = 1/work1d.d[674];
  work1d.L[1048] = (work1d.KKT[1344]-work1d.L[1047]*work1d.v[673])*work1d.d_inv[674];
  work1d.v[172] = work1d.L[484]*work1d.d[172];
  work1d.v[675] = work1d.KKT[1345]-work1d.L[484]*work1d.v[172];
  work1d.d[675] = work1d.v[675];
  if (work1d.d[675] > 0)
    work1d.d[675] = -settings1d.kkt_reg;
  else
    work1d.d[675] -= settings1d.kkt_reg;
  work1d.d_inv[675] = 1/work1d.d[675];
  work1d.L[485] = (work1d.KKT[1346])*work1d.d_inv[675];
  work1d.v[675] = work1d.L[485]*work1d.d[675];
  work1d.v[676] = 0-work1d.L[485]*work1d.v[675];
  work1d.d[676] = work1d.v[676];
  if (work1d.d[676] < 0)
    work1d.d[676] = settings1d.kkt_reg;
  else
    work1d.d[676] += settings1d.kkt_reg;
  work1d.d_inv[676] = 1/work1d.d[676];
  work1d.L[487] = (work1d.KKT[1347])*work1d.d_inv[676];
  work1d.L[489] = (work1d.KKT[1348])*work1d.d_inv[676];
  work1d.v[173] = work1d.L[486]*work1d.d[173];
  work1d.v[676] = work1d.L[487]*work1d.d[676];
  work1d.v[677] = work1d.KKT[1349]-work1d.L[486]*work1d.v[173]-work1d.L[487]*work1d.v[676];
  work1d.d[677] = work1d.v[677];
  if (work1d.d[677] > 0)
    work1d.d[677] = -settings1d.kkt_reg;
  else
    work1d.d[677] -= settings1d.kkt_reg;
  work1d.d_inv[677] = 1/work1d.d[677];
  work1d.L[490] = (-work1d.L[489]*work1d.v[676])*work1d.d_inv[677];
  work1d.L[1069] = (work1d.KKT[1350])*work1d.d_inv[677];
  work1d.v[174] = work1d.L[488]*work1d.d[174];
  work1d.v[676] = work1d.L[489]*work1d.d[676];
  work1d.v[677] = work1d.L[490]*work1d.d[677];
  work1d.v[678] = work1d.KKT[1351]-work1d.L[488]*work1d.v[174]-work1d.L[489]*work1d.v[676]-work1d.L[490]*work1d.v[677];
  work1d.d[678] = work1d.v[678];
  if (work1d.d[678] > 0)
    work1d.d[678] = -settings1d.kkt_reg;
  else
    work1d.d[678] -= settings1d.kkt_reg;
  work1d.d_inv[678] = 1/work1d.d[678];
  work1d.L[1070] = (work1d.KKT[1352]-work1d.L[1069]*work1d.v[677])*work1d.d_inv[678];
  work1d.v[175] = work1d.L[491]*work1d.d[175];
  work1d.v[679] = work1d.KKT[1353]-work1d.L[491]*work1d.v[175];
  work1d.d[679] = work1d.v[679];
  if (work1d.d[679] > 0)
    work1d.d[679] = -settings1d.kkt_reg;
  else
    work1d.d[679] -= settings1d.kkt_reg;
  work1d.d_inv[679] = 1/work1d.d[679];
  work1d.L[492] = (work1d.KKT[1354])*work1d.d_inv[679];
  work1d.v[679] = work1d.L[492]*work1d.d[679];
  work1d.v[680] = 0-work1d.L[492]*work1d.v[679];
  work1d.d[680] = work1d.v[680];
  if (work1d.d[680] < 0)
    work1d.d[680] = settings1d.kkt_reg;
  else
    work1d.d[680] += settings1d.kkt_reg;
  work1d.d_inv[680] = 1/work1d.d[680];
  work1d.L[494] = (work1d.KKT[1355])*work1d.d_inv[680];
  work1d.L[496] = (work1d.KKT[1356])*work1d.d_inv[680];
  work1d.v[176] = work1d.L[493]*work1d.d[176];
  work1d.v[680] = work1d.L[494]*work1d.d[680];
  work1d.v[681] = work1d.KKT[1357]-work1d.L[493]*work1d.v[176]-work1d.L[494]*work1d.v[680];
  work1d.d[681] = work1d.v[681];
  if (work1d.d[681] > 0)
    work1d.d[681] = -settings1d.kkt_reg;
  else
    work1d.d[681] -= settings1d.kkt_reg;
  work1d.d_inv[681] = 1/work1d.d[681];
  work1d.L[497] = (-work1d.L[496]*work1d.v[680])*work1d.d_inv[681];
  work1d.L[1091] = (work1d.KKT[1358])*work1d.d_inv[681];
  work1d.v[177] = work1d.L[495]*work1d.d[177];
  work1d.v[680] = work1d.L[496]*work1d.d[680];
  work1d.v[681] = work1d.L[497]*work1d.d[681];
  work1d.v[682] = work1d.KKT[1359]-work1d.L[495]*work1d.v[177]-work1d.L[496]*work1d.v[680]-work1d.L[497]*work1d.v[681];
  work1d.d[682] = work1d.v[682];
  if (work1d.d[682] > 0)
    work1d.d[682] = -settings1d.kkt_reg;
  else
    work1d.d[682] -= settings1d.kkt_reg;
  work1d.d_inv[682] = 1/work1d.d[682];
  work1d.L[1092] = (work1d.KKT[1360]-work1d.L[1091]*work1d.v[681])*work1d.d_inv[682];
  work1d.v[178] = work1d.L[498]*work1d.d[178];
  work1d.v[683] = work1d.KKT[1361]-work1d.L[498]*work1d.v[178];
  work1d.d[683] = work1d.v[683];
  if (work1d.d[683] > 0)
    work1d.d[683] = -settings1d.kkt_reg;
  else
    work1d.d[683] -= settings1d.kkt_reg;
  work1d.d_inv[683] = 1/work1d.d[683];
  work1d.L[499] = (work1d.KKT[1362])*work1d.d_inv[683];
  work1d.v[683] = work1d.L[499]*work1d.d[683];
  work1d.v[684] = 0-work1d.L[499]*work1d.v[683];
  work1d.d[684] = work1d.v[684];
  if (work1d.d[684] < 0)
    work1d.d[684] = settings1d.kkt_reg;
  else
    work1d.d[684] += settings1d.kkt_reg;
  work1d.d_inv[684] = 1/work1d.d[684];
  work1d.L[501] = (work1d.KKT[1363])*work1d.d_inv[684];
  work1d.L[503] = (work1d.KKT[1364])*work1d.d_inv[684];
  work1d.v[179] = work1d.L[500]*work1d.d[179];
  work1d.v[684] = work1d.L[501]*work1d.d[684];
  work1d.v[685] = work1d.KKT[1365]-work1d.L[500]*work1d.v[179]-work1d.L[501]*work1d.v[684];
  work1d.d[685] = work1d.v[685];
  if (work1d.d[685] > 0)
    work1d.d[685] = -settings1d.kkt_reg;
  else
    work1d.d[685] -= settings1d.kkt_reg;
  work1d.d_inv[685] = 1/work1d.d[685];
  work1d.L[504] = (-work1d.L[503]*work1d.v[684])*work1d.d_inv[685];
  work1d.L[1113] = (work1d.KKT[1366])*work1d.d_inv[685];
  work1d.v[180] = work1d.L[502]*work1d.d[180];
  work1d.v[684] = work1d.L[503]*work1d.d[684];
  work1d.v[685] = work1d.L[504]*work1d.d[685];
  work1d.v[686] = work1d.KKT[1367]-work1d.L[502]*work1d.v[180]-work1d.L[503]*work1d.v[684]-work1d.L[504]*work1d.v[685];
  work1d.d[686] = work1d.v[686];
  if (work1d.d[686] > 0)
    work1d.d[686] = -settings1d.kkt_reg;
  else
    work1d.d[686] -= settings1d.kkt_reg;
  work1d.d_inv[686] = 1/work1d.d[686];
  work1d.L[1114] = (work1d.KKT[1368]-work1d.L[1113]*work1d.v[685])*work1d.d_inv[686];
  work1d.v[181] = work1d.L[505]*work1d.d[181];
  work1d.v[687] = work1d.KKT[1369]-work1d.L[505]*work1d.v[181];
  work1d.d[687] = work1d.v[687];
  if (work1d.d[687] > 0)
    work1d.d[687] = -settings1d.kkt_reg;
  else
    work1d.d[687] -= settings1d.kkt_reg;
  work1d.d_inv[687] = 1/work1d.d[687];
  work1d.L[506] = (work1d.KKT[1370])*work1d.d_inv[687];
  work1d.v[687] = work1d.L[506]*work1d.d[687];
  work1d.v[688] = 0-work1d.L[506]*work1d.v[687];
  work1d.d[688] = work1d.v[688];
  if (work1d.d[688] < 0)
    work1d.d[688] = settings1d.kkt_reg;
  else
    work1d.d[688] += settings1d.kkt_reg;
  work1d.d_inv[688] = 1/work1d.d[688];
  work1d.L[508] = (work1d.KKT[1371])*work1d.d_inv[688];
  work1d.L[510] = (work1d.KKT[1372])*work1d.d_inv[688];
  work1d.v[182] = work1d.L[507]*work1d.d[182];
  work1d.v[688] = work1d.L[508]*work1d.d[688];
  work1d.v[689] = work1d.KKT[1373]-work1d.L[507]*work1d.v[182]-work1d.L[508]*work1d.v[688];
  work1d.d[689] = work1d.v[689];
  if (work1d.d[689] > 0)
    work1d.d[689] = -settings1d.kkt_reg;
  else
    work1d.d[689] -= settings1d.kkt_reg;
  work1d.d_inv[689] = 1/work1d.d[689];
  work1d.L[511] = (-work1d.L[510]*work1d.v[688])*work1d.d_inv[689];
  work1d.L[1135] = (work1d.KKT[1374])*work1d.d_inv[689];
  work1d.v[183] = work1d.L[509]*work1d.d[183];
  work1d.v[688] = work1d.L[510]*work1d.d[688];
  work1d.v[689] = work1d.L[511]*work1d.d[689];
  work1d.v[690] = work1d.KKT[1375]-work1d.L[509]*work1d.v[183]-work1d.L[510]*work1d.v[688]-work1d.L[511]*work1d.v[689];
  work1d.d[690] = work1d.v[690];
  if (work1d.d[690] > 0)
    work1d.d[690] = -settings1d.kkt_reg;
  else
    work1d.d[690] -= settings1d.kkt_reg;
  work1d.d_inv[690] = 1/work1d.d[690];
  work1d.L[1136] = (work1d.KKT[1376]-work1d.L[1135]*work1d.v[689])*work1d.d_inv[690];
  work1d.v[184] = work1d.L[512]*work1d.d[184];
  work1d.v[691] = work1d.KKT[1377]-work1d.L[512]*work1d.v[184];
  work1d.d[691] = work1d.v[691];
  if (work1d.d[691] > 0)
    work1d.d[691] = -settings1d.kkt_reg;
  else
    work1d.d[691] -= settings1d.kkt_reg;
  work1d.d_inv[691] = 1/work1d.d[691];
  work1d.L[513] = (work1d.KKT[1378])*work1d.d_inv[691];
  work1d.v[691] = work1d.L[513]*work1d.d[691];
  work1d.v[692] = 0-work1d.L[513]*work1d.v[691];
  work1d.d[692] = work1d.v[692];
  if (work1d.d[692] < 0)
    work1d.d[692] = settings1d.kkt_reg;
  else
    work1d.d[692] += settings1d.kkt_reg;
  work1d.d_inv[692] = 1/work1d.d[692];
  work1d.L[515] = (work1d.KKT[1379])*work1d.d_inv[692];
  work1d.L[517] = (work1d.KKT[1380])*work1d.d_inv[692];
  work1d.v[185] = work1d.L[514]*work1d.d[185];
  work1d.v[692] = work1d.L[515]*work1d.d[692];
  work1d.v[693] = work1d.KKT[1381]-work1d.L[514]*work1d.v[185]-work1d.L[515]*work1d.v[692];
  work1d.d[693] = work1d.v[693];
  if (work1d.d[693] > 0)
    work1d.d[693] = -settings1d.kkt_reg;
  else
    work1d.d[693] -= settings1d.kkt_reg;
  work1d.d_inv[693] = 1/work1d.d[693];
  work1d.L[518] = (-work1d.L[517]*work1d.v[692])*work1d.d_inv[693];
  work1d.L[1157] = (work1d.KKT[1382])*work1d.d_inv[693];
  work1d.v[186] = work1d.L[516]*work1d.d[186];
  work1d.v[692] = work1d.L[517]*work1d.d[692];
  work1d.v[693] = work1d.L[518]*work1d.d[693];
  work1d.v[694] = work1d.KKT[1383]-work1d.L[516]*work1d.v[186]-work1d.L[517]*work1d.v[692]-work1d.L[518]*work1d.v[693];
  work1d.d[694] = work1d.v[694];
  if (work1d.d[694] > 0)
    work1d.d[694] = -settings1d.kkt_reg;
  else
    work1d.d[694] -= settings1d.kkt_reg;
  work1d.d_inv[694] = 1/work1d.d[694];
  work1d.L[1158] = (work1d.KKT[1384]-work1d.L[1157]*work1d.v[693])*work1d.d_inv[694];
  work1d.v[187] = work1d.L[519]*work1d.d[187];
  work1d.v[695] = work1d.KKT[1385]-work1d.L[519]*work1d.v[187];
  work1d.d[695] = work1d.v[695];
  if (work1d.d[695] > 0)
    work1d.d[695] = -settings1d.kkt_reg;
  else
    work1d.d[695] -= settings1d.kkt_reg;
  work1d.d_inv[695] = 1/work1d.d[695];
  work1d.L[520] = (work1d.KKT[1386])*work1d.d_inv[695];
  work1d.v[695] = work1d.L[520]*work1d.d[695];
  work1d.v[696] = 0-work1d.L[520]*work1d.v[695];
  work1d.d[696] = work1d.v[696];
  if (work1d.d[696] < 0)
    work1d.d[696] = settings1d.kkt_reg;
  else
    work1d.d[696] += settings1d.kkt_reg;
  work1d.d_inv[696] = 1/work1d.d[696];
  work1d.L[522] = (work1d.KKT[1387])*work1d.d_inv[696];
  work1d.L[524] = (work1d.KKT[1388])*work1d.d_inv[696];
  work1d.v[188] = work1d.L[521]*work1d.d[188];
  work1d.v[696] = work1d.L[522]*work1d.d[696];
  work1d.v[697] = work1d.KKT[1389]-work1d.L[521]*work1d.v[188]-work1d.L[522]*work1d.v[696];
  work1d.d[697] = work1d.v[697];
  if (work1d.d[697] > 0)
    work1d.d[697] = -settings1d.kkt_reg;
  else
    work1d.d[697] -= settings1d.kkt_reg;
  work1d.d_inv[697] = 1/work1d.d[697];
  work1d.L[525] = (-work1d.L[524]*work1d.v[696])*work1d.d_inv[697];
  work1d.L[1179] = (work1d.KKT[1390])*work1d.d_inv[697];
  work1d.v[189] = work1d.L[523]*work1d.d[189];
  work1d.v[696] = work1d.L[524]*work1d.d[696];
  work1d.v[697] = work1d.L[525]*work1d.d[697];
  work1d.v[698] = work1d.KKT[1391]-work1d.L[523]*work1d.v[189]-work1d.L[524]*work1d.v[696]-work1d.L[525]*work1d.v[697];
  work1d.d[698] = work1d.v[698];
  if (work1d.d[698] > 0)
    work1d.d[698] = -settings1d.kkt_reg;
  else
    work1d.d[698] -= settings1d.kkt_reg;
  work1d.d_inv[698] = 1/work1d.d[698];
  work1d.L[1180] = (work1d.KKT[1392]-work1d.L[1179]*work1d.v[697])*work1d.d_inv[698];
  work1d.v[190] = work1d.L[526]*work1d.d[190];
  work1d.v[699] = work1d.KKT[1393]-work1d.L[526]*work1d.v[190];
  work1d.d[699] = work1d.v[699];
  if (work1d.d[699] > 0)
    work1d.d[699] = -settings1d.kkt_reg;
  else
    work1d.d[699] -= settings1d.kkt_reg;
  work1d.d_inv[699] = 1/work1d.d[699];
  work1d.L[527] = (work1d.KKT[1394])*work1d.d_inv[699];
  work1d.v[699] = work1d.L[527]*work1d.d[699];
  work1d.v[700] = 0-work1d.L[527]*work1d.v[699];
  work1d.d[700] = work1d.v[700];
  if (work1d.d[700] < 0)
    work1d.d[700] = settings1d.kkt_reg;
  else
    work1d.d[700] += settings1d.kkt_reg;
  work1d.d_inv[700] = 1/work1d.d[700];
  work1d.L[529] = (work1d.KKT[1395])*work1d.d_inv[700];
  work1d.L[531] = (work1d.KKT[1396])*work1d.d_inv[700];
  work1d.v[191] = work1d.L[528]*work1d.d[191];
  work1d.v[700] = work1d.L[529]*work1d.d[700];
  work1d.v[701] = work1d.KKT[1397]-work1d.L[528]*work1d.v[191]-work1d.L[529]*work1d.v[700];
  work1d.d[701] = work1d.v[701];
  if (work1d.d[701] > 0)
    work1d.d[701] = -settings1d.kkt_reg;
  else
    work1d.d[701] -= settings1d.kkt_reg;
  work1d.d_inv[701] = 1/work1d.d[701];
  work1d.L[532] = (-work1d.L[531]*work1d.v[700])*work1d.d_inv[701];
  work1d.L[1201] = (work1d.KKT[1398])*work1d.d_inv[701];
  work1d.v[192] = work1d.L[530]*work1d.d[192];
  work1d.v[700] = work1d.L[531]*work1d.d[700];
  work1d.v[701] = work1d.L[532]*work1d.d[701];
  work1d.v[702] = work1d.KKT[1399]-work1d.L[530]*work1d.v[192]-work1d.L[531]*work1d.v[700]-work1d.L[532]*work1d.v[701];
  work1d.d[702] = work1d.v[702];
  if (work1d.d[702] > 0)
    work1d.d[702] = -settings1d.kkt_reg;
  else
    work1d.d[702] -= settings1d.kkt_reg;
  work1d.d_inv[702] = 1/work1d.d[702];
  work1d.L[1202] = (work1d.KKT[1400]-work1d.L[1201]*work1d.v[701])*work1d.d_inv[702];
  work1d.v[193] = work1d.L[533]*work1d.d[193];
  work1d.v[703] = work1d.KKT[1401]-work1d.L[533]*work1d.v[193];
  work1d.d[703] = work1d.v[703];
  if (work1d.d[703] > 0)
    work1d.d[703] = -settings1d.kkt_reg;
  else
    work1d.d[703] -= settings1d.kkt_reg;
  work1d.d_inv[703] = 1/work1d.d[703];
  work1d.L[534] = (work1d.KKT[1402])*work1d.d_inv[703];
  work1d.v[703] = work1d.L[534]*work1d.d[703];
  work1d.v[704] = 0-work1d.L[534]*work1d.v[703];
  work1d.d[704] = work1d.v[704];
  if (work1d.d[704] < 0)
    work1d.d[704] = settings1d.kkt_reg;
  else
    work1d.d[704] += settings1d.kkt_reg;
  work1d.d_inv[704] = 1/work1d.d[704];
  work1d.L[536] = (work1d.KKT[1403])*work1d.d_inv[704];
  work1d.L[538] = (work1d.KKT[1404])*work1d.d_inv[704];
  work1d.v[194] = work1d.L[535]*work1d.d[194];
  work1d.v[704] = work1d.L[536]*work1d.d[704];
  work1d.v[705] = work1d.KKT[1405]-work1d.L[535]*work1d.v[194]-work1d.L[536]*work1d.v[704];
  work1d.d[705] = work1d.v[705];
  if (work1d.d[705] > 0)
    work1d.d[705] = -settings1d.kkt_reg;
  else
    work1d.d[705] -= settings1d.kkt_reg;
  work1d.d_inv[705] = 1/work1d.d[705];
  work1d.L[539] = (-work1d.L[538]*work1d.v[704])*work1d.d_inv[705];
  work1d.L[1223] = (work1d.KKT[1406])*work1d.d_inv[705];
  work1d.v[195] = work1d.L[537]*work1d.d[195];
  work1d.v[704] = work1d.L[538]*work1d.d[704];
  work1d.v[705] = work1d.L[539]*work1d.d[705];
  work1d.v[706] = work1d.KKT[1407]-work1d.L[537]*work1d.v[195]-work1d.L[538]*work1d.v[704]-work1d.L[539]*work1d.v[705];
  work1d.d[706] = work1d.v[706];
  if (work1d.d[706] > 0)
    work1d.d[706] = -settings1d.kkt_reg;
  else
    work1d.d[706] -= settings1d.kkt_reg;
  work1d.d_inv[706] = 1/work1d.d[706];
  work1d.L[1224] = (work1d.KKT[1408]-work1d.L[1223]*work1d.v[705])*work1d.d_inv[706];
  work1d.v[196] = work1d.L[540]*work1d.d[196];
  work1d.v[707] = work1d.KKT[1409]-work1d.L[540]*work1d.v[196];
  work1d.d[707] = work1d.v[707];
  if (work1d.d[707] > 0)
    work1d.d[707] = -settings1d.kkt_reg;
  else
    work1d.d[707] -= settings1d.kkt_reg;
  work1d.d_inv[707] = 1/work1d.d[707];
  work1d.L[541] = (work1d.KKT[1410])*work1d.d_inv[707];
  work1d.v[707] = work1d.L[541]*work1d.d[707];
  work1d.v[708] = 0-work1d.L[541]*work1d.v[707];
  work1d.d[708] = work1d.v[708];
  if (work1d.d[708] < 0)
    work1d.d[708] = settings1d.kkt_reg;
  else
    work1d.d[708] += settings1d.kkt_reg;
  work1d.d_inv[708] = 1/work1d.d[708];
  work1d.L[543] = (work1d.KKT[1411])*work1d.d_inv[708];
  work1d.L[545] = (work1d.KKT[1412])*work1d.d_inv[708];
  work1d.v[197] = work1d.L[542]*work1d.d[197];
  work1d.v[708] = work1d.L[543]*work1d.d[708];
  work1d.v[709] = work1d.KKT[1413]-work1d.L[542]*work1d.v[197]-work1d.L[543]*work1d.v[708];
  work1d.d[709] = work1d.v[709];
  if (work1d.d[709] > 0)
    work1d.d[709] = -settings1d.kkt_reg;
  else
    work1d.d[709] -= settings1d.kkt_reg;
  work1d.d_inv[709] = 1/work1d.d[709];
  work1d.L[546] = (-work1d.L[545]*work1d.v[708])*work1d.d_inv[709];
  work1d.L[1245] = (work1d.KKT[1414])*work1d.d_inv[709];
  work1d.v[198] = work1d.L[544]*work1d.d[198];
  work1d.v[708] = work1d.L[545]*work1d.d[708];
  work1d.v[709] = work1d.L[546]*work1d.d[709];
  work1d.v[710] = work1d.KKT[1415]-work1d.L[544]*work1d.v[198]-work1d.L[545]*work1d.v[708]-work1d.L[546]*work1d.v[709];
  work1d.d[710] = work1d.v[710];
  if (work1d.d[710] > 0)
    work1d.d[710] = -settings1d.kkt_reg;
  else
    work1d.d[710] -= settings1d.kkt_reg;
  work1d.d_inv[710] = 1/work1d.d[710];
  work1d.L[1246] = (work1d.KKT[1416]-work1d.L[1245]*work1d.v[709])*work1d.d_inv[710];
  work1d.v[199] = work1d.L[547]*work1d.d[199];
  work1d.v[711] = work1d.KKT[1417]-work1d.L[547]*work1d.v[199];
  work1d.d[711] = work1d.v[711];
  if (work1d.d[711] > 0)
    work1d.d[711] = -settings1d.kkt_reg;
  else
    work1d.d[711] -= settings1d.kkt_reg;
  work1d.d_inv[711] = 1/work1d.d[711];
  work1d.L[548] = (work1d.KKT[1418])*work1d.d_inv[711];
  work1d.v[711] = work1d.L[548]*work1d.d[711];
  work1d.v[712] = 0-work1d.L[548]*work1d.v[711];
  work1d.d[712] = work1d.v[712];
  if (work1d.d[712] < 0)
    work1d.d[712] = settings1d.kkt_reg;
  else
    work1d.d[712] += settings1d.kkt_reg;
  work1d.d_inv[712] = 1/work1d.d[712];
  work1d.L[550] = (work1d.KKT[1419])*work1d.d_inv[712];
  work1d.L[552] = (work1d.KKT[1420])*work1d.d_inv[712];
  work1d.v[200] = work1d.L[549]*work1d.d[200];
  work1d.v[712] = work1d.L[550]*work1d.d[712];
  work1d.v[713] = work1d.KKT[1421]-work1d.L[549]*work1d.v[200]-work1d.L[550]*work1d.v[712];
  work1d.d[713] = work1d.v[713];
  if (work1d.d[713] > 0)
    work1d.d[713] = -settings1d.kkt_reg;
  else
    work1d.d[713] -= settings1d.kkt_reg;
  work1d.d_inv[713] = 1/work1d.d[713];
  work1d.L[553] = (-work1d.L[552]*work1d.v[712])*work1d.d_inv[713];
  work1d.L[1267] = (work1d.KKT[1422])*work1d.d_inv[713];
  work1d.v[201] = work1d.L[551]*work1d.d[201];
  work1d.v[712] = work1d.L[552]*work1d.d[712];
  work1d.v[713] = work1d.L[553]*work1d.d[713];
  work1d.v[714] = work1d.KKT[1423]-work1d.L[551]*work1d.v[201]-work1d.L[552]*work1d.v[712]-work1d.L[553]*work1d.v[713];
  work1d.d[714] = work1d.v[714];
  if (work1d.d[714] > 0)
    work1d.d[714] = -settings1d.kkt_reg;
  else
    work1d.d[714] -= settings1d.kkt_reg;
  work1d.d_inv[714] = 1/work1d.d[714];
  work1d.L[1268] = (work1d.KKT[1424]-work1d.L[1267]*work1d.v[713])*work1d.d_inv[714];
  work1d.v[202] = work1d.L[554]*work1d.d[202];
  work1d.v[715] = work1d.KKT[1425]-work1d.L[554]*work1d.v[202];
  work1d.d[715] = work1d.v[715];
  if (work1d.d[715] > 0)
    work1d.d[715] = -settings1d.kkt_reg;
  else
    work1d.d[715] -= settings1d.kkt_reg;
  work1d.d_inv[715] = 1/work1d.d[715];
  work1d.L[555] = (work1d.KKT[1426])*work1d.d_inv[715];
  work1d.v[715] = work1d.L[555]*work1d.d[715];
  work1d.v[716] = 0-work1d.L[555]*work1d.v[715];
  work1d.d[716] = work1d.v[716];
  if (work1d.d[716] < 0)
    work1d.d[716] = settings1d.kkt_reg;
  else
    work1d.d[716] += settings1d.kkt_reg;
  work1d.d_inv[716] = 1/work1d.d[716];
  work1d.L[557] = (work1d.KKT[1427])*work1d.d_inv[716];
  work1d.L[559] = (work1d.KKT[1428])*work1d.d_inv[716];
  work1d.v[203] = work1d.L[556]*work1d.d[203];
  work1d.v[716] = work1d.L[557]*work1d.d[716];
  work1d.v[717] = work1d.KKT[1429]-work1d.L[556]*work1d.v[203]-work1d.L[557]*work1d.v[716];
  work1d.d[717] = work1d.v[717];
  if (work1d.d[717] > 0)
    work1d.d[717] = -settings1d.kkt_reg;
  else
    work1d.d[717] -= settings1d.kkt_reg;
  work1d.d_inv[717] = 1/work1d.d[717];
  work1d.L[560] = (-work1d.L[559]*work1d.v[716])*work1d.d_inv[717];
  work1d.L[1289] = (work1d.KKT[1430])*work1d.d_inv[717];
  work1d.v[204] = work1d.L[558]*work1d.d[204];
  work1d.v[716] = work1d.L[559]*work1d.d[716];
  work1d.v[717] = work1d.L[560]*work1d.d[717];
  work1d.v[718] = work1d.KKT[1431]-work1d.L[558]*work1d.v[204]-work1d.L[559]*work1d.v[716]-work1d.L[560]*work1d.v[717];
  work1d.d[718] = work1d.v[718];
  if (work1d.d[718] > 0)
    work1d.d[718] = -settings1d.kkt_reg;
  else
    work1d.d[718] -= settings1d.kkt_reg;
  work1d.d_inv[718] = 1/work1d.d[718];
  work1d.L[1290] = (work1d.KKT[1432]-work1d.L[1289]*work1d.v[717])*work1d.d_inv[718];
  work1d.v[205] = work1d.L[561]*work1d.d[205];
  work1d.v[719] = work1d.KKT[1433]-work1d.L[561]*work1d.v[205];
  work1d.d[719] = work1d.v[719];
  if (work1d.d[719] > 0)
    work1d.d[719] = -settings1d.kkt_reg;
  else
    work1d.d[719] -= settings1d.kkt_reg;
  work1d.d_inv[719] = 1/work1d.d[719];
  work1d.L[562] = (work1d.KKT[1434])*work1d.d_inv[719];
  work1d.v[719] = work1d.L[562]*work1d.d[719];
  work1d.v[720] = 0-work1d.L[562]*work1d.v[719];
  work1d.d[720] = work1d.v[720];
  if (work1d.d[720] < 0)
    work1d.d[720] = settings1d.kkt_reg;
  else
    work1d.d[720] += settings1d.kkt_reg;
  work1d.d_inv[720] = 1/work1d.d[720];
  work1d.L[564] = (work1d.KKT[1435])*work1d.d_inv[720];
  work1d.L[566] = (work1d.KKT[1436])*work1d.d_inv[720];
  work1d.v[206] = work1d.L[563]*work1d.d[206];
  work1d.v[720] = work1d.L[564]*work1d.d[720];
  work1d.v[721] = work1d.KKT[1437]-work1d.L[563]*work1d.v[206]-work1d.L[564]*work1d.v[720];
  work1d.d[721] = work1d.v[721];
  if (work1d.d[721] > 0)
    work1d.d[721] = -settings1d.kkt_reg;
  else
    work1d.d[721] -= settings1d.kkt_reg;
  work1d.d_inv[721] = 1/work1d.d[721];
  work1d.L[567] = (-work1d.L[566]*work1d.v[720])*work1d.d_inv[721];
  work1d.L[1311] = (work1d.KKT[1438])*work1d.d_inv[721];
  work1d.v[207] = work1d.L[565]*work1d.d[207];
  work1d.v[720] = work1d.L[566]*work1d.d[720];
  work1d.v[721] = work1d.L[567]*work1d.d[721];
  work1d.v[722] = work1d.KKT[1439]-work1d.L[565]*work1d.v[207]-work1d.L[566]*work1d.v[720]-work1d.L[567]*work1d.v[721];
  work1d.d[722] = work1d.v[722];
  if (work1d.d[722] > 0)
    work1d.d[722] = -settings1d.kkt_reg;
  else
    work1d.d[722] -= settings1d.kkt_reg;
  work1d.d_inv[722] = 1/work1d.d[722];
  work1d.L[1312] = (work1d.KKT[1440]-work1d.L[1311]*work1d.v[721])*work1d.d_inv[722];
  work1d.v[208] = work1d.L[568]*work1d.d[208];
  work1d.v[723] = work1d.KKT[1441]-work1d.L[568]*work1d.v[208];
  work1d.d[723] = work1d.v[723];
  if (work1d.d[723] > 0)
    work1d.d[723] = -settings1d.kkt_reg;
  else
    work1d.d[723] -= settings1d.kkt_reg;
  work1d.d_inv[723] = 1/work1d.d[723];
  work1d.L[569] = (work1d.KKT[1442])*work1d.d_inv[723];
  work1d.v[723] = work1d.L[569]*work1d.d[723];
  work1d.v[724] = 0-work1d.L[569]*work1d.v[723];
  work1d.d[724] = work1d.v[724];
  if (work1d.d[724] < 0)
    work1d.d[724] = settings1d.kkt_reg;
  else
    work1d.d[724] += settings1d.kkt_reg;
  work1d.d_inv[724] = 1/work1d.d[724];
  work1d.L[571] = (work1d.KKT[1443])*work1d.d_inv[724];
  work1d.L[573] = (work1d.KKT[1444])*work1d.d_inv[724];
  work1d.v[209] = work1d.L[570]*work1d.d[209];
  work1d.v[724] = work1d.L[571]*work1d.d[724];
  work1d.v[725] = work1d.KKT[1445]-work1d.L[570]*work1d.v[209]-work1d.L[571]*work1d.v[724];
  work1d.d[725] = work1d.v[725];
  if (work1d.d[725] > 0)
    work1d.d[725] = -settings1d.kkt_reg;
  else
    work1d.d[725] -= settings1d.kkt_reg;
  work1d.d_inv[725] = 1/work1d.d[725];
  work1d.L[574] = (-work1d.L[573]*work1d.v[724])*work1d.d_inv[725];
  work1d.L[1333] = (work1d.KKT[1446])*work1d.d_inv[725];
  work1d.v[210] = work1d.L[572]*work1d.d[210];
  work1d.v[724] = work1d.L[573]*work1d.d[724];
  work1d.v[725] = work1d.L[574]*work1d.d[725];
  work1d.v[726] = work1d.KKT[1447]-work1d.L[572]*work1d.v[210]-work1d.L[573]*work1d.v[724]-work1d.L[574]*work1d.v[725];
  work1d.d[726] = work1d.v[726];
  if (work1d.d[726] > 0)
    work1d.d[726] = -settings1d.kkt_reg;
  else
    work1d.d[726] -= settings1d.kkt_reg;
  work1d.d_inv[726] = 1/work1d.d[726];
  work1d.L[1334] = (work1d.KKT[1448]-work1d.L[1333]*work1d.v[725])*work1d.d_inv[726];
  work1d.v[211] = work1d.L[575]*work1d.d[211];
  work1d.v[727] = work1d.KKT[1449]-work1d.L[575]*work1d.v[211];
  work1d.d[727] = work1d.v[727];
  if (work1d.d[727] > 0)
    work1d.d[727] = -settings1d.kkt_reg;
  else
    work1d.d[727] -= settings1d.kkt_reg;
  work1d.d_inv[727] = 1/work1d.d[727];
  work1d.L[576] = (work1d.KKT[1450])*work1d.d_inv[727];
  work1d.v[727] = work1d.L[576]*work1d.d[727];
  work1d.v[728] = 0-work1d.L[576]*work1d.v[727];
  work1d.d[728] = work1d.v[728];
  if (work1d.d[728] < 0)
    work1d.d[728] = settings1d.kkt_reg;
  else
    work1d.d[728] += settings1d.kkt_reg;
  work1d.d_inv[728] = 1/work1d.d[728];
  work1d.L[578] = (work1d.KKT[1451])*work1d.d_inv[728];
  work1d.L[580] = (work1d.KKT[1452])*work1d.d_inv[728];
  work1d.v[212] = work1d.L[577]*work1d.d[212];
  work1d.v[728] = work1d.L[578]*work1d.d[728];
  work1d.v[729] = work1d.KKT[1453]-work1d.L[577]*work1d.v[212]-work1d.L[578]*work1d.v[728];
  work1d.d[729] = work1d.v[729];
  if (work1d.d[729] > 0)
    work1d.d[729] = -settings1d.kkt_reg;
  else
    work1d.d[729] -= settings1d.kkt_reg;
  work1d.d_inv[729] = 1/work1d.d[729];
  work1d.L[581] = (-work1d.L[580]*work1d.v[728])*work1d.d_inv[729];
  work1d.L[1355] = (work1d.KKT[1454])*work1d.d_inv[729];
  work1d.v[213] = work1d.L[579]*work1d.d[213];
  work1d.v[728] = work1d.L[580]*work1d.d[728];
  work1d.v[729] = work1d.L[581]*work1d.d[729];
  work1d.v[730] = work1d.KKT[1455]-work1d.L[579]*work1d.v[213]-work1d.L[580]*work1d.v[728]-work1d.L[581]*work1d.v[729];
  work1d.d[730] = work1d.v[730];
  if (work1d.d[730] > 0)
    work1d.d[730] = -settings1d.kkt_reg;
  else
    work1d.d[730] -= settings1d.kkt_reg;
  work1d.d_inv[730] = 1/work1d.d[730];
  work1d.L[1356] = (work1d.KKT[1456]-work1d.L[1355]*work1d.v[729])*work1d.d_inv[730];
  work1d.v[214] = work1d.L[582]*work1d.d[214];
  work1d.v[731] = work1d.KKT[1457]-work1d.L[582]*work1d.v[214];
  work1d.d[731] = work1d.v[731];
  if (work1d.d[731] > 0)
    work1d.d[731] = -settings1d.kkt_reg;
  else
    work1d.d[731] -= settings1d.kkt_reg;
  work1d.d_inv[731] = 1/work1d.d[731];
  work1d.L[583] = (work1d.KKT[1458])*work1d.d_inv[731];
  work1d.v[731] = work1d.L[583]*work1d.d[731];
  work1d.v[732] = 0-work1d.L[583]*work1d.v[731];
  work1d.d[732] = work1d.v[732];
  if (work1d.d[732] < 0)
    work1d.d[732] = settings1d.kkt_reg;
  else
    work1d.d[732] += settings1d.kkt_reg;
  work1d.d_inv[732] = 1/work1d.d[732];
  work1d.L[585] = (work1d.KKT[1459])*work1d.d_inv[732];
  work1d.L[587] = (work1d.KKT[1460])*work1d.d_inv[732];
  work1d.v[215] = work1d.L[584]*work1d.d[215];
  work1d.v[732] = work1d.L[585]*work1d.d[732];
  work1d.v[733] = work1d.KKT[1461]-work1d.L[584]*work1d.v[215]-work1d.L[585]*work1d.v[732];
  work1d.d[733] = work1d.v[733];
  if (work1d.d[733] > 0)
    work1d.d[733] = -settings1d.kkt_reg;
  else
    work1d.d[733] -= settings1d.kkt_reg;
  work1d.d_inv[733] = 1/work1d.d[733];
  work1d.L[588] = (-work1d.L[587]*work1d.v[732])*work1d.d_inv[733];
  work1d.L[1377] = (work1d.KKT[1462])*work1d.d_inv[733];
  work1d.v[216] = work1d.L[586]*work1d.d[216];
  work1d.v[732] = work1d.L[587]*work1d.d[732];
  work1d.v[733] = work1d.L[588]*work1d.d[733];
  work1d.v[734] = work1d.KKT[1463]-work1d.L[586]*work1d.v[216]-work1d.L[587]*work1d.v[732]-work1d.L[588]*work1d.v[733];
  work1d.d[734] = work1d.v[734];
  if (work1d.d[734] > 0)
    work1d.d[734] = -settings1d.kkt_reg;
  else
    work1d.d[734] -= settings1d.kkt_reg;
  work1d.d_inv[734] = 1/work1d.d[734];
  work1d.L[1378] = (work1d.KKT[1464]-work1d.L[1377]*work1d.v[733])*work1d.d_inv[734];
  work1d.v[217] = work1d.L[589]*work1d.d[217];
  work1d.v[735] = work1d.KKT[1465]-work1d.L[589]*work1d.v[217];
  work1d.d[735] = work1d.v[735];
  if (work1d.d[735] > 0)
    work1d.d[735] = -settings1d.kkt_reg;
  else
    work1d.d[735] -= settings1d.kkt_reg;
  work1d.d_inv[735] = 1/work1d.d[735];
  work1d.L[590] = (work1d.KKT[1466])*work1d.d_inv[735];
  work1d.v[735] = work1d.L[590]*work1d.d[735];
  work1d.v[736] = 0-work1d.L[590]*work1d.v[735];
  work1d.d[736] = work1d.v[736];
  if (work1d.d[736] < 0)
    work1d.d[736] = settings1d.kkt_reg;
  else
    work1d.d[736] += settings1d.kkt_reg;
  work1d.d_inv[736] = 1/work1d.d[736];
  work1d.L[592] = (work1d.KKT[1467])*work1d.d_inv[736];
  work1d.L[594] = (work1d.KKT[1468])*work1d.d_inv[736];
  work1d.v[218] = work1d.L[591]*work1d.d[218];
  work1d.v[736] = work1d.L[592]*work1d.d[736];
  work1d.v[737] = work1d.KKT[1469]-work1d.L[591]*work1d.v[218]-work1d.L[592]*work1d.v[736];
  work1d.d[737] = work1d.v[737];
  if (work1d.d[737] > 0)
    work1d.d[737] = -settings1d.kkt_reg;
  else
    work1d.d[737] -= settings1d.kkt_reg;
  work1d.d_inv[737] = 1/work1d.d[737];
  work1d.L[595] = (-work1d.L[594]*work1d.v[736])*work1d.d_inv[737];
  work1d.L[1399] = (work1d.KKT[1470])*work1d.d_inv[737];
  work1d.v[219] = work1d.L[593]*work1d.d[219];
  work1d.v[736] = work1d.L[594]*work1d.d[736];
  work1d.v[737] = work1d.L[595]*work1d.d[737];
  work1d.v[738] = work1d.KKT[1471]-work1d.L[593]*work1d.v[219]-work1d.L[594]*work1d.v[736]-work1d.L[595]*work1d.v[737];
  work1d.d[738] = work1d.v[738];
  if (work1d.d[738] > 0)
    work1d.d[738] = -settings1d.kkt_reg;
  else
    work1d.d[738] -= settings1d.kkt_reg;
  work1d.d_inv[738] = 1/work1d.d[738];
  work1d.L[1400] = (work1d.KKT[1472]-work1d.L[1399]*work1d.v[737])*work1d.d_inv[738];
  work1d.v[220] = work1d.L[596]*work1d.d[220];
  work1d.v[739] = work1d.KKT[1473]-work1d.L[596]*work1d.v[220];
  work1d.d[739] = work1d.v[739];
  if (work1d.d[739] > 0)
    work1d.d[739] = -settings1d.kkt_reg;
  else
    work1d.d[739] -= settings1d.kkt_reg;
  work1d.d_inv[739] = 1/work1d.d[739];
  work1d.L[597] = (work1d.KKT[1474])*work1d.d_inv[739];
  work1d.v[739] = work1d.L[597]*work1d.d[739];
  work1d.v[740] = 0-work1d.L[597]*work1d.v[739];
  work1d.d[740] = work1d.v[740];
  if (work1d.d[740] < 0)
    work1d.d[740] = settings1d.kkt_reg;
  else
    work1d.d[740] += settings1d.kkt_reg;
  work1d.d_inv[740] = 1/work1d.d[740];
  work1d.L[599] = (work1d.KKT[1475])*work1d.d_inv[740];
  work1d.L[601] = (work1d.KKT[1476])*work1d.d_inv[740];
  work1d.v[221] = work1d.L[598]*work1d.d[221];
  work1d.v[740] = work1d.L[599]*work1d.d[740];
  work1d.v[741] = work1d.KKT[1477]-work1d.L[598]*work1d.v[221]-work1d.L[599]*work1d.v[740];
  work1d.d[741] = work1d.v[741];
  if (work1d.d[741] > 0)
    work1d.d[741] = -settings1d.kkt_reg;
  else
    work1d.d[741] -= settings1d.kkt_reg;
  work1d.d_inv[741] = 1/work1d.d[741];
  work1d.L[602] = (-work1d.L[601]*work1d.v[740])*work1d.d_inv[741];
  work1d.L[1421] = (work1d.KKT[1478])*work1d.d_inv[741];
  work1d.v[222] = work1d.L[600]*work1d.d[222];
  work1d.v[740] = work1d.L[601]*work1d.d[740];
  work1d.v[741] = work1d.L[602]*work1d.d[741];
  work1d.v[742] = work1d.KKT[1479]-work1d.L[600]*work1d.v[222]-work1d.L[601]*work1d.v[740]-work1d.L[602]*work1d.v[741];
  work1d.d[742] = work1d.v[742];
  if (work1d.d[742] > 0)
    work1d.d[742] = -settings1d.kkt_reg;
  else
    work1d.d[742] -= settings1d.kkt_reg;
  work1d.d_inv[742] = 1/work1d.d[742];
  work1d.L[1422] = (work1d.KKT[1480]-work1d.L[1421]*work1d.v[741])*work1d.d_inv[742];
  work1d.v[223] = work1d.L[603]*work1d.d[223];
  work1d.v[743] = work1d.KKT[1481]-work1d.L[603]*work1d.v[223];
  work1d.d[743] = work1d.v[743];
  if (work1d.d[743] > 0)
    work1d.d[743] = -settings1d.kkt_reg;
  else
    work1d.d[743] -= settings1d.kkt_reg;
  work1d.d_inv[743] = 1/work1d.d[743];
  work1d.L[604] = (work1d.KKT[1482])*work1d.d_inv[743];
  work1d.v[743] = work1d.L[604]*work1d.d[743];
  work1d.v[744] = 0-work1d.L[604]*work1d.v[743];
  work1d.d[744] = work1d.v[744];
  if (work1d.d[744] < 0)
    work1d.d[744] = settings1d.kkt_reg;
  else
    work1d.d[744] += settings1d.kkt_reg;
  work1d.d_inv[744] = 1/work1d.d[744];
  work1d.L[606] = (work1d.KKT[1483])*work1d.d_inv[744];
  work1d.L[608] = (work1d.KKT[1484])*work1d.d_inv[744];
  work1d.v[224] = work1d.L[605]*work1d.d[224];
  work1d.v[744] = work1d.L[606]*work1d.d[744];
  work1d.v[745] = work1d.KKT[1485]-work1d.L[605]*work1d.v[224]-work1d.L[606]*work1d.v[744];
  work1d.d[745] = work1d.v[745];
  if (work1d.d[745] > 0)
    work1d.d[745] = -settings1d.kkt_reg;
  else
    work1d.d[745] -= settings1d.kkt_reg;
  work1d.d_inv[745] = 1/work1d.d[745];
  work1d.L[609] = (-work1d.L[608]*work1d.v[744])*work1d.d_inv[745];
  work1d.L[1443] = (work1d.KKT[1486])*work1d.d_inv[745];
  work1d.v[225] = work1d.L[607]*work1d.d[225];
  work1d.v[744] = work1d.L[608]*work1d.d[744];
  work1d.v[745] = work1d.L[609]*work1d.d[745];
  work1d.v[746] = work1d.KKT[1487]-work1d.L[607]*work1d.v[225]-work1d.L[608]*work1d.v[744]-work1d.L[609]*work1d.v[745];
  work1d.d[746] = work1d.v[746];
  if (work1d.d[746] > 0)
    work1d.d[746] = -settings1d.kkt_reg;
  else
    work1d.d[746] -= settings1d.kkt_reg;
  work1d.d_inv[746] = 1/work1d.d[746];
  work1d.L[1444] = (work1d.KKT[1488]-work1d.L[1443]*work1d.v[745])*work1d.d_inv[746];
  work1d.v[226] = work1d.L[610]*work1d.d[226];
  work1d.v[747] = work1d.KKT[1489]-work1d.L[610]*work1d.v[226];
  work1d.d[747] = work1d.v[747];
  if (work1d.d[747] > 0)
    work1d.d[747] = -settings1d.kkt_reg;
  else
    work1d.d[747] -= settings1d.kkt_reg;
  work1d.d_inv[747] = 1/work1d.d[747];
  work1d.L[611] = (work1d.KKT[1490])*work1d.d_inv[747];
  work1d.v[747] = work1d.L[611]*work1d.d[747];
  work1d.v[748] = 0-work1d.L[611]*work1d.v[747];
  work1d.d[748] = work1d.v[748];
  if (work1d.d[748] < 0)
    work1d.d[748] = settings1d.kkt_reg;
  else
    work1d.d[748] += settings1d.kkt_reg;
  work1d.d_inv[748] = 1/work1d.d[748];
  work1d.L[613] = (work1d.KKT[1491])*work1d.d_inv[748];
  work1d.L[615] = (work1d.KKT[1492])*work1d.d_inv[748];
  work1d.v[227] = work1d.L[612]*work1d.d[227];
  work1d.v[748] = work1d.L[613]*work1d.d[748];
  work1d.v[749] = work1d.KKT[1493]-work1d.L[612]*work1d.v[227]-work1d.L[613]*work1d.v[748];
  work1d.d[749] = work1d.v[749];
  if (work1d.d[749] > 0)
    work1d.d[749] = -settings1d.kkt_reg;
  else
    work1d.d[749] -= settings1d.kkt_reg;
  work1d.d_inv[749] = 1/work1d.d[749];
  work1d.L[616] = (-work1d.L[615]*work1d.v[748])*work1d.d_inv[749];
  work1d.L[1465] = (work1d.KKT[1494])*work1d.d_inv[749];
  work1d.v[228] = work1d.L[614]*work1d.d[228];
  work1d.v[748] = work1d.L[615]*work1d.d[748];
  work1d.v[749] = work1d.L[616]*work1d.d[749];
  work1d.v[750] = work1d.KKT[1495]-work1d.L[614]*work1d.v[228]-work1d.L[615]*work1d.v[748]-work1d.L[616]*work1d.v[749];
  work1d.d[750] = work1d.v[750];
  if (work1d.d[750] > 0)
    work1d.d[750] = -settings1d.kkt_reg;
  else
    work1d.d[750] -= settings1d.kkt_reg;
  work1d.d_inv[750] = 1/work1d.d[750];
  work1d.L[1466] = (work1d.KKT[1496]-work1d.L[1465]*work1d.v[749])*work1d.d_inv[750];
  work1d.v[229] = work1d.L[617]*work1d.d[229];
  work1d.v[751] = work1d.KKT[1497]-work1d.L[617]*work1d.v[229];
  work1d.d[751] = work1d.v[751];
  if (work1d.d[751] > 0)
    work1d.d[751] = -settings1d.kkt_reg;
  else
    work1d.d[751] -= settings1d.kkt_reg;
  work1d.d_inv[751] = 1/work1d.d[751];
  work1d.L[618] = (work1d.KKT[1498])*work1d.d_inv[751];
  work1d.v[751] = work1d.L[618]*work1d.d[751];
  work1d.v[752] = 0-work1d.L[618]*work1d.v[751];
  work1d.d[752] = work1d.v[752];
  if (work1d.d[752] < 0)
    work1d.d[752] = settings1d.kkt_reg;
  else
    work1d.d[752] += settings1d.kkt_reg;
  work1d.d_inv[752] = 1/work1d.d[752];
  work1d.L[620] = (work1d.KKT[1499])*work1d.d_inv[752];
  work1d.L[622] = (work1d.KKT[1500])*work1d.d_inv[752];
  work1d.v[230] = work1d.L[619]*work1d.d[230];
  work1d.v[752] = work1d.L[620]*work1d.d[752];
  work1d.v[753] = work1d.KKT[1501]-work1d.L[619]*work1d.v[230]-work1d.L[620]*work1d.v[752];
  work1d.d[753] = work1d.v[753];
  if (work1d.d[753] > 0)
    work1d.d[753] = -settings1d.kkt_reg;
  else
    work1d.d[753] -= settings1d.kkt_reg;
  work1d.d_inv[753] = 1/work1d.d[753];
  work1d.L[623] = (-work1d.L[622]*work1d.v[752])*work1d.d_inv[753];
  work1d.L[1487] = (work1d.KKT[1502])*work1d.d_inv[753];
  work1d.v[231] = work1d.L[621]*work1d.d[231];
  work1d.v[752] = work1d.L[622]*work1d.d[752];
  work1d.v[753] = work1d.L[623]*work1d.d[753];
  work1d.v[754] = work1d.KKT[1503]-work1d.L[621]*work1d.v[231]-work1d.L[622]*work1d.v[752]-work1d.L[623]*work1d.v[753];
  work1d.d[754] = work1d.v[754];
  if (work1d.d[754] > 0)
    work1d.d[754] = -settings1d.kkt_reg;
  else
    work1d.d[754] -= settings1d.kkt_reg;
  work1d.d_inv[754] = 1/work1d.d[754];
  work1d.L[1488] = (work1d.KKT[1504]-work1d.L[1487]*work1d.v[753])*work1d.d_inv[754];
  work1d.v[232] = work1d.L[624]*work1d.d[232];
  work1d.v[755] = work1d.KKT[1505]-work1d.L[624]*work1d.v[232];
  work1d.d[755] = work1d.v[755];
  if (work1d.d[755] > 0)
    work1d.d[755] = -settings1d.kkt_reg;
  else
    work1d.d[755] -= settings1d.kkt_reg;
  work1d.d_inv[755] = 1/work1d.d[755];
  work1d.L[625] = (work1d.KKT[1506])*work1d.d_inv[755];
  work1d.v[755] = work1d.L[625]*work1d.d[755];
  work1d.v[756] = 0-work1d.L[625]*work1d.v[755];
  work1d.d[756] = work1d.v[756];
  if (work1d.d[756] < 0)
    work1d.d[756] = settings1d.kkt_reg;
  else
    work1d.d[756] += settings1d.kkt_reg;
  work1d.d_inv[756] = 1/work1d.d[756];
  work1d.L[627] = (work1d.KKT[1507])*work1d.d_inv[756];
  work1d.L[629] = (work1d.KKT[1508])*work1d.d_inv[756];
  work1d.v[233] = work1d.L[626]*work1d.d[233];
  work1d.v[756] = work1d.L[627]*work1d.d[756];
  work1d.v[757] = work1d.KKT[1509]-work1d.L[626]*work1d.v[233]-work1d.L[627]*work1d.v[756];
  work1d.d[757] = work1d.v[757];
  if (work1d.d[757] > 0)
    work1d.d[757] = -settings1d.kkt_reg;
  else
    work1d.d[757] -= settings1d.kkt_reg;
  work1d.d_inv[757] = 1/work1d.d[757];
  work1d.L[630] = (-work1d.L[629]*work1d.v[756])*work1d.d_inv[757];
  work1d.L[1515] = (work1d.KKT[1510])*work1d.d_inv[757];
  work1d.v[234] = work1d.L[628]*work1d.d[234];
  work1d.v[756] = work1d.L[629]*work1d.d[756];
  work1d.v[757] = work1d.L[630]*work1d.d[757];
  work1d.v[758] = work1d.KKT[1511]-work1d.L[628]*work1d.v[234]-work1d.L[629]*work1d.v[756]-work1d.L[630]*work1d.v[757];
  work1d.d[758] = work1d.v[758];
  if (work1d.d[758] > 0)
    work1d.d[758] = -settings1d.kkt_reg;
  else
    work1d.d[758] -= settings1d.kkt_reg;
  work1d.d_inv[758] = 1/work1d.d[758];
  work1d.L[1516] = (work1d.KKT[1512]-work1d.L[1515]*work1d.v[757])*work1d.d_inv[758];
  work1d.v[235] = work1d.L[631]*work1d.d[235];
  work1d.v[759] = work1d.KKT[1513]-work1d.L[631]*work1d.v[235];
  work1d.d[759] = work1d.v[759];
  if (work1d.d[759] > 0)
    work1d.d[759] = -settings1d.kkt_reg;
  else
    work1d.d[759] -= settings1d.kkt_reg;
  work1d.d_inv[759] = 1/work1d.d[759];
  work1d.L[632] = (work1d.KKT[1514])*work1d.d_inv[759];
  work1d.v[759] = work1d.L[632]*work1d.d[759];
  work1d.v[760] = 0-work1d.L[632]*work1d.v[759];
  work1d.d[760] = work1d.v[760];
  if (work1d.d[760] < 0)
    work1d.d[760] = settings1d.kkt_reg;
  else
    work1d.d[760] += settings1d.kkt_reg;
  work1d.d_inv[760] = 1/work1d.d[760];
  work1d.L[634] = (work1d.KKT[1515])*work1d.d_inv[760];
  work1d.L[636] = (work1d.KKT[1516])*work1d.d_inv[760];
  work1d.v[236] = work1d.L[633]*work1d.d[236];
  work1d.v[760] = work1d.L[634]*work1d.d[760];
  work1d.v[761] = work1d.KKT[1517]-work1d.L[633]*work1d.v[236]-work1d.L[634]*work1d.v[760];
  work1d.d[761] = work1d.v[761];
  if (work1d.d[761] > 0)
    work1d.d[761] = -settings1d.kkt_reg;
  else
    work1d.d[761] -= settings1d.kkt_reg;
  work1d.d_inv[761] = 1/work1d.d[761];
  work1d.L[637] = (-work1d.L[636]*work1d.v[760])*work1d.d_inv[761];
  work1d.L[651] = (work1d.KKT[1518])*work1d.d_inv[761];
  work1d.v[237] = work1d.L[635]*work1d.d[237];
  work1d.v[760] = work1d.L[636]*work1d.d[760];
  work1d.v[761] = work1d.L[637]*work1d.d[761];
  work1d.v[762] = work1d.KKT[1519]-work1d.L[635]*work1d.v[237]-work1d.L[636]*work1d.v[760]-work1d.L[637]*work1d.v[761];
  work1d.d[762] = work1d.v[762];
  if (work1d.d[762] > 0)
    work1d.d[762] = -settings1d.kkt_reg;
  else
    work1d.d[762] -= settings1d.kkt_reg;
  work1d.d_inv[762] = 1/work1d.d[762];
  work1d.L[652] = (work1d.KKT[1520]-work1d.L[651]*work1d.v[761])*work1d.d_inv[762];
  work1d.v[238] = work1d.L[638]*work1d.d[238];
  work1d.v[763] = work1d.KKT[1521]-work1d.L[638]*work1d.v[238];
  work1d.d[763] = work1d.v[763];
  if (work1d.d[763] > 0)
    work1d.d[763] = -settings1d.kkt_reg;
  else
    work1d.d[763] -= settings1d.kkt_reg;
  work1d.d_inv[763] = 1/work1d.d[763];
  work1d.L[639] = (work1d.KKT[1522])*work1d.d_inv[763];
  work1d.v[763] = work1d.L[639]*work1d.d[763];
  work1d.v[764] = 0-work1d.L[639]*work1d.v[763];
  work1d.d[764] = work1d.v[764];
  if (work1d.d[764] < 0)
    work1d.d[764] = settings1d.kkt_reg;
  else
    work1d.d[764] += settings1d.kkt_reg;
  work1d.d_inv[764] = 1/work1d.d[764];
  work1d.L[641] = (work1d.KKT[1523])*work1d.d_inv[764];
  work1d.L[643] = (work1d.KKT[1524])*work1d.d_inv[764];
  work1d.v[239] = work1d.L[640]*work1d.d[239];
  work1d.v[764] = work1d.L[641]*work1d.d[764];
  work1d.v[765] = work1d.KKT[1525]-work1d.L[640]*work1d.v[239]-work1d.L[641]*work1d.v[764];
  work1d.d[765] = work1d.v[765];
  if (work1d.d[765] > 0)
    work1d.d[765] = -settings1d.kkt_reg;
  else
    work1d.d[765] -= settings1d.kkt_reg;
  work1d.d_inv[765] = 1/work1d.d[765];
  work1d.L[644] = (-work1d.L[643]*work1d.v[764])*work1d.d_inv[765];
  work1d.L[646] = (work1d.KKT[1526])*work1d.d_inv[765];
  work1d.v[240] = work1d.L[642]*work1d.d[240];
  work1d.v[764] = work1d.L[643]*work1d.d[764];
  work1d.v[765] = work1d.L[644]*work1d.d[765];
  work1d.v[766] = work1d.KKT[1527]-work1d.L[642]*work1d.v[240]-work1d.L[643]*work1d.v[764]-work1d.L[644]*work1d.v[765];
  work1d.d[766] = work1d.v[766];
  if (work1d.d[766] > 0)
    work1d.d[766] = -settings1d.kkt_reg;
  else
    work1d.d[766] -= settings1d.kkt_reg;
  work1d.d_inv[766] = 1/work1d.d[766];
  work1d.L[647] = (work1d.KKT[1528]-work1d.L[646]*work1d.v[765])*work1d.d_inv[766];
  work1d.v[400] = work1d.L[645]*work1d.d[400];
  work1d.v[765] = work1d.L[646]*work1d.d[765];
  work1d.v[766] = work1d.L[647]*work1d.d[766];
  work1d.v[767] = work1d.KKT[1529]-work1d.L[645]*work1d.v[400]-work1d.L[646]*work1d.v[765]-work1d.L[647]*work1d.v[766];
  work1d.d[767] = work1d.v[767];
  if (work1d.d[767] < 0)
    work1d.d[767] = settings1d.kkt_reg;
  else
    work1d.d[767] += settings1d.kkt_reg;
  work1d.d_inv[767] = 1/work1d.d[767];
  work1d.L[649] = (work1d.KKT[1530])*work1d.d_inv[767];
  work1d.v[443] = work1d.L[648]*work1d.d[443];
  work1d.v[767] = work1d.L[649]*work1d.d[767];
  work1d.v[768] = 0-work1d.L[648]*work1d.v[443]-work1d.L[649]*work1d.v[767];
  work1d.d[768] = work1d.v[768];
  if (work1d.d[768] > 0)
    work1d.d[768] = -settings1d.kkt_reg;
  else
    work1d.d[768] -= settings1d.kkt_reg;
  work1d.d_inv[768] = 1/work1d.d[768];
  work1d.L[653] = (work1d.KKT[1531])*work1d.d_inv[768];
  work1d.v[399] = work1d.L[650]*work1d.d[399];
  work1d.v[761] = work1d.L[651]*work1d.d[761];
  work1d.v[762] = work1d.L[652]*work1d.d[762];
  work1d.v[768] = work1d.L[653]*work1d.d[768];
  work1d.v[769] = work1d.KKT[1532]-work1d.L[650]*work1d.v[399]-work1d.L[651]*work1d.v[761]-work1d.L[652]*work1d.v[762]-work1d.L[653]*work1d.v[768];
  work1d.d[769] = work1d.v[769];
  if (work1d.d[769] < 0)
    work1d.d[769] = settings1d.kkt_reg;
  else
    work1d.d[769] += settings1d.kkt_reg;
  work1d.d_inv[769] = 1/work1d.d[769];
  work1d.L[693] = (work1d.KKT[1533])*work1d.d_inv[769];
  work1d.L[696] = (work1d.KKT[1534])*work1d.d_inv[769];
  work1d.v[444] = work1d.L[654]*work1d.d[444];
  work1d.v[770] = 0-work1d.L[654]*work1d.v[444];
  work1d.d[770] = work1d.v[770];
  if (work1d.d[770] > 0)
    work1d.d[770] = -settings1d.kkt_reg;
  else
    work1d.d[770] -= settings1d.kkt_reg;
  work1d.d_inv[770] = 1/work1d.d[770];
  work1d.L[702] = (work1d.KKT[1535])*work1d.d_inv[770];
  work1d.L[708] = (work1d.KKT[1536])*work1d.d_inv[770];
  work1d.v[405] = work1d.L[655]*work1d.d[405];
  work1d.v[771] = 0-work1d.L[655]*work1d.v[405];
  work1d.d[771] = work1d.v[771];
  if (work1d.d[771] > 0)
    work1d.d[771] = -settings1d.kkt_reg;
  else
    work1d.d[771] -= settings1d.kkt_reg;
  work1d.d_inv[771] = 1/work1d.d[771];
  work1d.L[707] = (work1d.KKT[1537])*work1d.d_inv[771];
  work1d.L[721] = (work1d.KKT[1538])*work1d.d_inv[771];
  work1d.v[406] = work1d.L[656]*work1d.d[406];
  work1d.v[772] = 0-work1d.L[656]*work1d.v[406];
  work1d.d[772] = work1d.v[772];
  if (work1d.d[772] > 0)
    work1d.d[772] = -settings1d.kkt_reg;
  else
    work1d.d[772] -= settings1d.kkt_reg;
  work1d.d_inv[772] = 1/work1d.d[772];
  work1d.L[722] = (work1d.KKT[1539])*work1d.d_inv[772];
  work1d.L[741] = (work1d.KKT[1540])*work1d.d_inv[772];
  work1d.v[407] = work1d.L[657]*work1d.d[407];
  work1d.v[773] = 0-work1d.L[657]*work1d.v[407];
  work1d.d[773] = work1d.v[773];
  if (work1d.d[773] > 0)
    work1d.d[773] = -settings1d.kkt_reg;
  else
    work1d.d[773] -= settings1d.kkt_reg;
  work1d.d_inv[773] = 1/work1d.d[773];
  work1d.L[742] = (work1d.KKT[1541])*work1d.d_inv[773];
  work1d.L[763] = (work1d.KKT[1542])*work1d.d_inv[773];
  work1d.v[408] = work1d.L[658]*work1d.d[408];
  work1d.v[774] = 0-work1d.L[658]*work1d.v[408];
  work1d.d[774] = work1d.v[774];
  if (work1d.d[774] > 0)
    work1d.d[774] = -settings1d.kkt_reg;
  else
    work1d.d[774] -= settings1d.kkt_reg;
  work1d.d_inv[774] = 1/work1d.d[774];
  work1d.L[764] = (work1d.KKT[1543])*work1d.d_inv[774];
  work1d.L[785] = (work1d.KKT[1544])*work1d.d_inv[774];
  work1d.v[409] = work1d.L[659]*work1d.d[409];
  work1d.v[775] = 0-work1d.L[659]*work1d.v[409];
  work1d.d[775] = work1d.v[775];
  if (work1d.d[775] > 0)
    work1d.d[775] = -settings1d.kkt_reg;
  else
    work1d.d[775] -= settings1d.kkt_reg;
  work1d.d_inv[775] = 1/work1d.d[775];
  work1d.L[786] = (work1d.KKT[1545])*work1d.d_inv[775];
  work1d.L[807] = (work1d.KKT[1546])*work1d.d_inv[775];
  work1d.v[410] = work1d.L[660]*work1d.d[410];
  work1d.v[776] = 0-work1d.L[660]*work1d.v[410];
  work1d.d[776] = work1d.v[776];
  if (work1d.d[776] > 0)
    work1d.d[776] = -settings1d.kkt_reg;
  else
    work1d.d[776] -= settings1d.kkt_reg;
  work1d.d_inv[776] = 1/work1d.d[776];
  work1d.L[808] = (work1d.KKT[1547])*work1d.d_inv[776];
  work1d.L[829] = (work1d.KKT[1548])*work1d.d_inv[776];
  work1d.v[411] = work1d.L[661]*work1d.d[411];
  work1d.v[777] = 0-work1d.L[661]*work1d.v[411];
  work1d.d[777] = work1d.v[777];
  if (work1d.d[777] > 0)
    work1d.d[777] = -settings1d.kkt_reg;
  else
    work1d.d[777] -= settings1d.kkt_reg;
  work1d.d_inv[777] = 1/work1d.d[777];
  work1d.L[830] = (work1d.KKT[1549])*work1d.d_inv[777];
  work1d.L[851] = (work1d.KKT[1550])*work1d.d_inv[777];
  work1d.v[412] = work1d.L[662]*work1d.d[412];
  work1d.v[778] = 0-work1d.L[662]*work1d.v[412];
  work1d.d[778] = work1d.v[778];
  if (work1d.d[778] > 0)
    work1d.d[778] = -settings1d.kkt_reg;
  else
    work1d.d[778] -= settings1d.kkt_reg;
  work1d.d_inv[778] = 1/work1d.d[778];
  work1d.L[852] = (work1d.KKT[1551])*work1d.d_inv[778];
  work1d.L[873] = (work1d.KKT[1552])*work1d.d_inv[778];
  work1d.v[413] = work1d.L[663]*work1d.d[413];
  work1d.v[779] = 0-work1d.L[663]*work1d.v[413];
  work1d.d[779] = work1d.v[779];
  if (work1d.d[779] > 0)
    work1d.d[779] = -settings1d.kkt_reg;
  else
    work1d.d[779] -= settings1d.kkt_reg;
  work1d.d_inv[779] = 1/work1d.d[779];
  work1d.L[874] = (work1d.KKT[1553])*work1d.d_inv[779];
  work1d.L[895] = (work1d.KKT[1554])*work1d.d_inv[779];
  work1d.v[414] = work1d.L[664]*work1d.d[414];
  work1d.v[780] = 0-work1d.L[664]*work1d.v[414];
  work1d.d[780] = work1d.v[780];
  if (work1d.d[780] > 0)
    work1d.d[780] = -settings1d.kkt_reg;
  else
    work1d.d[780] -= settings1d.kkt_reg;
  work1d.d_inv[780] = 1/work1d.d[780];
  work1d.L[896] = (work1d.KKT[1555])*work1d.d_inv[780];
  work1d.L[917] = (work1d.KKT[1556])*work1d.d_inv[780];
  work1d.v[415] = work1d.L[665]*work1d.d[415];
  work1d.v[781] = 0-work1d.L[665]*work1d.v[415];
  work1d.d[781] = work1d.v[781];
  if (work1d.d[781] > 0)
    work1d.d[781] = -settings1d.kkt_reg;
  else
    work1d.d[781] -= settings1d.kkt_reg;
  work1d.d_inv[781] = 1/work1d.d[781];
  work1d.L[918] = (work1d.KKT[1557])*work1d.d_inv[781];
  work1d.L[939] = (work1d.KKT[1558])*work1d.d_inv[781];
  work1d.v[416] = work1d.L[666]*work1d.d[416];
  work1d.v[782] = 0-work1d.L[666]*work1d.v[416];
  work1d.d[782] = work1d.v[782];
  if (work1d.d[782] > 0)
    work1d.d[782] = -settings1d.kkt_reg;
  else
    work1d.d[782] -= settings1d.kkt_reg;
  work1d.d_inv[782] = 1/work1d.d[782];
  work1d.L[940] = (work1d.KKT[1559])*work1d.d_inv[782];
  work1d.L[961] = (work1d.KKT[1560])*work1d.d_inv[782];
  work1d.v[417] = work1d.L[667]*work1d.d[417];
  work1d.v[783] = 0-work1d.L[667]*work1d.v[417];
  work1d.d[783] = work1d.v[783];
  if (work1d.d[783] > 0)
    work1d.d[783] = -settings1d.kkt_reg;
  else
    work1d.d[783] -= settings1d.kkt_reg;
  work1d.d_inv[783] = 1/work1d.d[783];
  work1d.L[962] = (work1d.KKT[1561])*work1d.d_inv[783];
  work1d.L[983] = (work1d.KKT[1562])*work1d.d_inv[783];
  work1d.v[418] = work1d.L[668]*work1d.d[418];
  work1d.v[784] = 0-work1d.L[668]*work1d.v[418];
  work1d.d[784] = work1d.v[784];
  if (work1d.d[784] > 0)
    work1d.d[784] = -settings1d.kkt_reg;
  else
    work1d.d[784] -= settings1d.kkt_reg;
  work1d.d_inv[784] = 1/work1d.d[784];
  work1d.L[984] = (work1d.KKT[1563])*work1d.d_inv[784];
  work1d.L[1005] = (work1d.KKT[1564])*work1d.d_inv[784];
  work1d.v[419] = work1d.L[669]*work1d.d[419];
  work1d.v[785] = 0-work1d.L[669]*work1d.v[419];
  work1d.d[785] = work1d.v[785];
  if (work1d.d[785] > 0)
    work1d.d[785] = -settings1d.kkt_reg;
  else
    work1d.d[785] -= settings1d.kkt_reg;
  work1d.d_inv[785] = 1/work1d.d[785];
  work1d.L[1006] = (work1d.KKT[1565])*work1d.d_inv[785];
  work1d.L[1027] = (work1d.KKT[1566])*work1d.d_inv[785];
  work1d.v[420] = work1d.L[670]*work1d.d[420];
  work1d.v[786] = 0-work1d.L[670]*work1d.v[420];
  work1d.d[786] = work1d.v[786];
  if (work1d.d[786] > 0)
    work1d.d[786] = -settings1d.kkt_reg;
  else
    work1d.d[786] -= settings1d.kkt_reg;
  work1d.d_inv[786] = 1/work1d.d[786];
  work1d.L[1028] = (work1d.KKT[1567])*work1d.d_inv[786];
  work1d.L[1049] = (work1d.KKT[1568])*work1d.d_inv[786];
  work1d.v[421] = work1d.L[671]*work1d.d[421];
  work1d.v[787] = 0-work1d.L[671]*work1d.v[421];
  work1d.d[787] = work1d.v[787];
  if (work1d.d[787] > 0)
    work1d.d[787] = -settings1d.kkt_reg;
  else
    work1d.d[787] -= settings1d.kkt_reg;
  work1d.d_inv[787] = 1/work1d.d[787];
  work1d.L[1050] = (work1d.KKT[1569])*work1d.d_inv[787];
  work1d.L[1071] = (work1d.KKT[1570])*work1d.d_inv[787];
  work1d.v[422] = work1d.L[672]*work1d.d[422];
  work1d.v[788] = 0-work1d.L[672]*work1d.v[422];
  work1d.d[788] = work1d.v[788];
  if (work1d.d[788] > 0)
    work1d.d[788] = -settings1d.kkt_reg;
  else
    work1d.d[788] -= settings1d.kkt_reg;
  work1d.d_inv[788] = 1/work1d.d[788];
  work1d.L[1072] = (work1d.KKT[1571])*work1d.d_inv[788];
  work1d.L[1093] = (work1d.KKT[1572])*work1d.d_inv[788];
  work1d.v[423] = work1d.L[673]*work1d.d[423];
  work1d.v[789] = 0-work1d.L[673]*work1d.v[423];
  work1d.d[789] = work1d.v[789];
  if (work1d.d[789] > 0)
    work1d.d[789] = -settings1d.kkt_reg;
  else
    work1d.d[789] -= settings1d.kkt_reg;
  work1d.d_inv[789] = 1/work1d.d[789];
  work1d.L[1094] = (work1d.KKT[1573])*work1d.d_inv[789];
  work1d.L[1115] = (work1d.KKT[1574])*work1d.d_inv[789];
  work1d.v[424] = work1d.L[674]*work1d.d[424];
  work1d.v[790] = 0-work1d.L[674]*work1d.v[424];
  work1d.d[790] = work1d.v[790];
  if (work1d.d[790] > 0)
    work1d.d[790] = -settings1d.kkt_reg;
  else
    work1d.d[790] -= settings1d.kkt_reg;
  work1d.d_inv[790] = 1/work1d.d[790];
  work1d.L[1116] = (work1d.KKT[1575])*work1d.d_inv[790];
  work1d.L[1137] = (work1d.KKT[1576])*work1d.d_inv[790];
  work1d.v[425] = work1d.L[675]*work1d.d[425];
  work1d.v[791] = 0-work1d.L[675]*work1d.v[425];
  work1d.d[791] = work1d.v[791];
  if (work1d.d[791] > 0)
    work1d.d[791] = -settings1d.kkt_reg;
  else
    work1d.d[791] -= settings1d.kkt_reg;
  work1d.d_inv[791] = 1/work1d.d[791];
  work1d.L[1138] = (work1d.KKT[1577])*work1d.d_inv[791];
  work1d.L[1159] = (work1d.KKT[1578])*work1d.d_inv[791];
  work1d.v[426] = work1d.L[676]*work1d.d[426];
  work1d.v[792] = 0-work1d.L[676]*work1d.v[426];
  work1d.d[792] = work1d.v[792];
  if (work1d.d[792] > 0)
    work1d.d[792] = -settings1d.kkt_reg;
  else
    work1d.d[792] -= settings1d.kkt_reg;
  work1d.d_inv[792] = 1/work1d.d[792];
  work1d.L[1160] = (work1d.KKT[1579])*work1d.d_inv[792];
  work1d.L[1181] = (work1d.KKT[1580])*work1d.d_inv[792];
  work1d.v[427] = work1d.L[677]*work1d.d[427];
  work1d.v[793] = 0-work1d.L[677]*work1d.v[427];
  work1d.d[793] = work1d.v[793];
  if (work1d.d[793] > 0)
    work1d.d[793] = -settings1d.kkt_reg;
  else
    work1d.d[793] -= settings1d.kkt_reg;
  work1d.d_inv[793] = 1/work1d.d[793];
  work1d.L[1182] = (work1d.KKT[1581])*work1d.d_inv[793];
  work1d.L[1203] = (work1d.KKT[1582])*work1d.d_inv[793];
  work1d.v[428] = work1d.L[678]*work1d.d[428];
  work1d.v[794] = 0-work1d.L[678]*work1d.v[428];
  work1d.d[794] = work1d.v[794];
  if (work1d.d[794] > 0)
    work1d.d[794] = -settings1d.kkt_reg;
  else
    work1d.d[794] -= settings1d.kkt_reg;
  work1d.d_inv[794] = 1/work1d.d[794];
  work1d.L[1204] = (work1d.KKT[1583])*work1d.d_inv[794];
  work1d.L[1225] = (work1d.KKT[1584])*work1d.d_inv[794];
  work1d.v[429] = work1d.L[679]*work1d.d[429];
  work1d.v[795] = 0-work1d.L[679]*work1d.v[429];
  work1d.d[795] = work1d.v[795];
  if (work1d.d[795] > 0)
    work1d.d[795] = -settings1d.kkt_reg;
  else
    work1d.d[795] -= settings1d.kkt_reg;
  work1d.d_inv[795] = 1/work1d.d[795];
  work1d.L[1226] = (work1d.KKT[1585])*work1d.d_inv[795];
  work1d.L[1247] = (work1d.KKT[1586])*work1d.d_inv[795];
  work1d.v[430] = work1d.L[680]*work1d.d[430];
  work1d.v[796] = 0-work1d.L[680]*work1d.v[430];
  work1d.d[796] = work1d.v[796];
  if (work1d.d[796] > 0)
    work1d.d[796] = -settings1d.kkt_reg;
  else
    work1d.d[796] -= settings1d.kkt_reg;
  work1d.d_inv[796] = 1/work1d.d[796];
  work1d.L[1248] = (work1d.KKT[1587])*work1d.d_inv[796];
  work1d.L[1269] = (work1d.KKT[1588])*work1d.d_inv[796];
  work1d.v[431] = work1d.L[681]*work1d.d[431];
  work1d.v[797] = 0-work1d.L[681]*work1d.v[431];
  work1d.d[797] = work1d.v[797];
  if (work1d.d[797] > 0)
    work1d.d[797] = -settings1d.kkt_reg;
  else
    work1d.d[797] -= settings1d.kkt_reg;
  work1d.d_inv[797] = 1/work1d.d[797];
  work1d.L[1270] = (work1d.KKT[1589])*work1d.d_inv[797];
  work1d.L[1291] = (work1d.KKT[1590])*work1d.d_inv[797];
  work1d.v[432] = work1d.L[682]*work1d.d[432];
  work1d.v[798] = 0-work1d.L[682]*work1d.v[432];
  work1d.d[798] = work1d.v[798];
  if (work1d.d[798] > 0)
    work1d.d[798] = -settings1d.kkt_reg;
  else
    work1d.d[798] -= settings1d.kkt_reg;
  work1d.d_inv[798] = 1/work1d.d[798];
  work1d.L[1292] = (work1d.KKT[1591])*work1d.d_inv[798];
  work1d.L[1313] = (work1d.KKT[1592])*work1d.d_inv[798];
  work1d.v[433] = work1d.L[683]*work1d.d[433];
  work1d.v[799] = 0-work1d.L[683]*work1d.v[433];
  work1d.d[799] = work1d.v[799];
  if (work1d.d[799] > 0)
    work1d.d[799] = -settings1d.kkt_reg;
  else
    work1d.d[799] -= settings1d.kkt_reg;
  work1d.d_inv[799] = 1/work1d.d[799];
  work1d.L[1314] = (work1d.KKT[1593])*work1d.d_inv[799];
  work1d.L[1335] = (work1d.KKT[1594])*work1d.d_inv[799];
  work1d.v[434] = work1d.L[684]*work1d.d[434];
  work1d.v[800] = 0-work1d.L[684]*work1d.v[434];
  work1d.d[800] = work1d.v[800];
  if (work1d.d[800] > 0)
    work1d.d[800] = -settings1d.kkt_reg;
  else
    work1d.d[800] -= settings1d.kkt_reg;
  work1d.d_inv[800] = 1/work1d.d[800];
  work1d.L[1336] = (work1d.KKT[1595])*work1d.d_inv[800];
  work1d.L[1357] = (work1d.KKT[1596])*work1d.d_inv[800];
  work1d.v[435] = work1d.L[685]*work1d.d[435];
  work1d.v[801] = 0-work1d.L[685]*work1d.v[435];
  work1d.d[801] = work1d.v[801];
  if (work1d.d[801] > 0)
    work1d.d[801] = -settings1d.kkt_reg;
  else
    work1d.d[801] -= settings1d.kkt_reg;
  work1d.d_inv[801] = 1/work1d.d[801];
  work1d.L[1358] = (work1d.KKT[1597])*work1d.d_inv[801];
  work1d.L[1379] = (work1d.KKT[1598])*work1d.d_inv[801];
  work1d.v[436] = work1d.L[686]*work1d.d[436];
  work1d.v[802] = 0-work1d.L[686]*work1d.v[436];
  work1d.d[802] = work1d.v[802];
  if (work1d.d[802] > 0)
    work1d.d[802] = -settings1d.kkt_reg;
  else
    work1d.d[802] -= settings1d.kkt_reg;
  work1d.d_inv[802] = 1/work1d.d[802];
  work1d.L[1380] = (work1d.KKT[1599])*work1d.d_inv[802];
  work1d.L[1401] = (work1d.KKT[1600])*work1d.d_inv[802];
  work1d.v[437] = work1d.L[687]*work1d.d[437];
  work1d.v[803] = 0-work1d.L[687]*work1d.v[437];
  work1d.d[803] = work1d.v[803];
  if (work1d.d[803] > 0)
    work1d.d[803] = -settings1d.kkt_reg;
  else
    work1d.d[803] -= settings1d.kkt_reg;
  work1d.d_inv[803] = 1/work1d.d[803];
  work1d.L[1402] = (work1d.KKT[1601])*work1d.d_inv[803];
  work1d.L[1423] = (work1d.KKT[1602])*work1d.d_inv[803];
  work1d.v[438] = work1d.L[688]*work1d.d[438];
  work1d.v[804] = 0-work1d.L[688]*work1d.v[438];
  work1d.d[804] = work1d.v[804];
  if (work1d.d[804] > 0)
    work1d.d[804] = -settings1d.kkt_reg;
  else
    work1d.d[804] -= settings1d.kkt_reg;
  work1d.d_inv[804] = 1/work1d.d[804];
  work1d.L[1424] = (work1d.KKT[1603])*work1d.d_inv[804];
  work1d.L[1445] = (work1d.KKT[1604])*work1d.d_inv[804];
  work1d.v[439] = work1d.L[689]*work1d.d[439];
  work1d.v[805] = 0-work1d.L[689]*work1d.v[439];
  work1d.d[805] = work1d.v[805];
  if (work1d.d[805] > 0)
    work1d.d[805] = -settings1d.kkt_reg;
  else
    work1d.d[805] -= settings1d.kkt_reg;
  work1d.d_inv[805] = 1/work1d.d[805];
  work1d.L[1446] = (work1d.KKT[1605])*work1d.d_inv[805];
  work1d.L[1467] = (work1d.KKT[1606])*work1d.d_inv[805];
  work1d.v[440] = work1d.L[690]*work1d.d[440];
  work1d.v[806] = 0-work1d.L[690]*work1d.v[440];
  work1d.d[806] = work1d.v[806];
  if (work1d.d[806] > 0)
    work1d.d[806] = -settings1d.kkt_reg;
  else
    work1d.d[806] -= settings1d.kkt_reg;
  work1d.d_inv[806] = 1/work1d.d[806];
  work1d.L[1468] = (work1d.KKT[1607])*work1d.d_inv[806];
  work1d.L[1489] = (work1d.KKT[1608])*work1d.d_inv[806];
  work1d.v[441] = work1d.L[691]*work1d.d[441];
  work1d.v[807] = 0-work1d.L[691]*work1d.v[441];
  work1d.d[807] = work1d.v[807];
  if (work1d.d[807] > 0)
    work1d.d[807] = -settings1d.kkt_reg;
  else
    work1d.d[807] -= settings1d.kkt_reg;
  work1d.d_inv[807] = 1/work1d.d[807];
  work1d.L[1490] = (work1d.KKT[1609])*work1d.d_inv[807];
  work1d.L[1517] = (work1d.KKT[1610])*work1d.d_inv[807];
  work1d.v[442] = work1d.L[692]*work1d.d[442];
  work1d.v[769] = work1d.L[693]*work1d.d[769];
  work1d.v[808] = 0-work1d.L[692]*work1d.v[442]-work1d.L[693]*work1d.v[769];
  work1d.d[808] = work1d.v[808];
  if (work1d.d[808] > 0)
    work1d.d[808] = -settings1d.kkt_reg;
  else
    work1d.d[808] -= settings1d.kkt_reg;
  work1d.d_inv[808] = 1/work1d.d[808];
  work1d.L[697] = (-work1d.L[696]*work1d.v[769])*work1d.d_inv[808];
  work1d.L[1518] = (work1d.KKT[1611])*work1d.d_inv[808];
  work1d.v[445] = work1d.L[694]*work1d.d[445];
  work1d.v[809] = 0-work1d.L[694]*work1d.v[445];
  work1d.d[809] = work1d.v[809];
  if (work1d.d[809] > 0)
    work1d.d[809] = -settings1d.kkt_reg;
  else
    work1d.d[809] -= settings1d.kkt_reg;
  work1d.d_inv[809] = 1/work1d.d[809];
  work1d.L[710] = (work1d.KKT[1612])*work1d.d_inv[809];
  work1d.L[1529] = (work1d.KKT[1613])*work1d.d_inv[809];
  work1d.v[606] = work1d.L[695]*work1d.d[606];
  work1d.v[769] = work1d.L[696]*work1d.d[769];
  work1d.v[808] = work1d.L[697]*work1d.d[808];
  work1d.v[810] = 0-work1d.L[695]*work1d.v[606]-work1d.L[696]*work1d.v[769]-work1d.L[697]*work1d.v[808];
  work1d.d[810] = work1d.v[810];
  if (work1d.d[810] > 0)
    work1d.d[810] = -settings1d.kkt_reg;
  else
    work1d.d[810] -= settings1d.kkt_reg;
  work1d.d_inv[810] = 1/work1d.d[810];
  work1d.L[1519] = (-work1d.L[1518]*work1d.v[808])*work1d.d_inv[810];
  work1d.L[1530] = (work1d.KKT[1614])*work1d.d_inv[810];
  work1d.v[321] = work1d.L[698]*work1d.d[321];
  work1d.v[402] = work1d.L[699]*work1d.d[402];
  work1d.v[448] = work1d.L[700]*work1d.d[448];
  work1d.v[449] = work1d.L[701]*work1d.d[449];
  work1d.v[770] = work1d.L[702]*work1d.d[770];
  work1d.v[811] = work1d.KKT[1615]-work1d.L[698]*work1d.v[321]-work1d.L[699]*work1d.v[402]-work1d.L[700]*work1d.v[448]-work1d.L[701]*work1d.v[449]-work1d.L[702]*work1d.v[770];
  work1d.d[811] = work1d.v[811];
  if (work1d.d[811] < 0)
    work1d.d[811] = settings1d.kkt_reg;
  else
    work1d.d[811] += settings1d.kkt_reg;
  work1d.d_inv[811] = 1/work1d.d[811];
  work1d.L[709] = (-work1d.L[708]*work1d.v[770])*work1d.d_inv[811];
  work1d.L[711] = (work1d.KKT[1616])*work1d.d_inv[811];
  work1d.v[361] = work1d.L[703]*work1d.d[361];
  work1d.v[404] = work1d.L[704]*work1d.d[404];
  work1d.v[609] = work1d.L[705]*work1d.d[609];
  work1d.v[610] = work1d.L[706]*work1d.d[610];
  work1d.v[771] = work1d.L[707]*work1d.d[771];
  work1d.v[812] = work1d.KKT[1617]-work1d.L[703]*work1d.v[361]-work1d.L[704]*work1d.v[404]-work1d.L[705]*work1d.v[609]-work1d.L[706]*work1d.v[610]-work1d.L[707]*work1d.v[771];
  work1d.d[812] = work1d.v[812];
  if (work1d.d[812] < 0)
    work1d.d[812] = settings1d.kkt_reg;
  else
    work1d.d[812] += settings1d.kkt_reg;
  work1d.d_inv[812] = 1/work1d.d[812];
  work1d.L[712] = (work1d.KKT[1618])*work1d.d_inv[812];
  work1d.L[723] = (-work1d.L[721]*work1d.v[771])*work1d.d_inv[812];
  work1d.v[770] = work1d.L[708]*work1d.d[770];
  work1d.v[811] = work1d.L[709]*work1d.d[811];
  work1d.v[813] = work1d.KKT[1619]-work1d.L[708]*work1d.v[770]-work1d.L[709]*work1d.v[811];
  work1d.d[813] = work1d.v[813];
  if (work1d.d[813] < 0)
    work1d.d[813] = settings1d.kkt_reg;
  else
    work1d.d[813] += settings1d.kkt_reg;
  work1d.d_inv[813] = 1/work1d.d[813];
  work1d.L[713] = (-work1d.L[711]*work1d.v[811])*work1d.d_inv[813];
  work1d.L[726] = (work1d.KKT[1620])*work1d.d_inv[813];
  work1d.v[814] = work1d.KKT[1621];
  work1d.d[814] = work1d.v[814];
  if (work1d.d[814] < 0)
    work1d.d[814] = settings1d.kkt_reg;
  else
    work1d.d[814] += settings1d.kkt_reg;
  work1d.d_inv[814] = 1/work1d.d[814];
  work1d.L[727] = (work1d.KKT[1622])*work1d.d_inv[814];
  work1d.L[747] = (work1d.KKT[1623])*work1d.d_inv[814];
  work1d.v[815] = work1d.KKT[1624];
  work1d.d[815] = work1d.v[815];
  if (work1d.d[815] < 0)
    work1d.d[815] = settings1d.kkt_reg;
  else
    work1d.d[815] += settings1d.kkt_reg;
  work1d.d_inv[815] = 1/work1d.d[815];
  work1d.L[748] = (work1d.KKT[1625])*work1d.d_inv[815];
  work1d.L[769] = (work1d.KKT[1626])*work1d.d_inv[815];
  work1d.v[816] = work1d.KKT[1627];
  work1d.d[816] = work1d.v[816];
  if (work1d.d[816] < 0)
    work1d.d[816] = settings1d.kkt_reg;
  else
    work1d.d[816] += settings1d.kkt_reg;
  work1d.d_inv[816] = 1/work1d.d[816];
  work1d.L[770] = (work1d.KKT[1628])*work1d.d_inv[816];
  work1d.L[791] = (work1d.KKT[1629])*work1d.d_inv[816];
  work1d.v[817] = work1d.KKT[1630];
  work1d.d[817] = work1d.v[817];
  if (work1d.d[817] < 0)
    work1d.d[817] = settings1d.kkt_reg;
  else
    work1d.d[817] += settings1d.kkt_reg;
  work1d.d_inv[817] = 1/work1d.d[817];
  work1d.L[792] = (work1d.KKT[1631])*work1d.d_inv[817];
  work1d.L[813] = (work1d.KKT[1632])*work1d.d_inv[817];
  work1d.v[818] = work1d.KKT[1633];
  work1d.d[818] = work1d.v[818];
  if (work1d.d[818] < 0)
    work1d.d[818] = settings1d.kkt_reg;
  else
    work1d.d[818] += settings1d.kkt_reg;
  work1d.d_inv[818] = 1/work1d.d[818];
  work1d.L[814] = (work1d.KKT[1634])*work1d.d_inv[818];
  work1d.L[835] = (work1d.KKT[1635])*work1d.d_inv[818];
  work1d.v[819] = work1d.KKT[1636];
  work1d.d[819] = work1d.v[819];
  if (work1d.d[819] < 0)
    work1d.d[819] = settings1d.kkt_reg;
  else
    work1d.d[819] += settings1d.kkt_reg;
  work1d.d_inv[819] = 1/work1d.d[819];
  work1d.L[836] = (work1d.KKT[1637])*work1d.d_inv[819];
  work1d.L[857] = (work1d.KKT[1638])*work1d.d_inv[819];
  work1d.v[820] = work1d.KKT[1639];
  work1d.d[820] = work1d.v[820];
  if (work1d.d[820] < 0)
    work1d.d[820] = settings1d.kkt_reg;
  else
    work1d.d[820] += settings1d.kkt_reg;
  work1d.d_inv[820] = 1/work1d.d[820];
  work1d.L[858] = (work1d.KKT[1640])*work1d.d_inv[820];
  work1d.L[879] = (work1d.KKT[1641])*work1d.d_inv[820];
  work1d.v[821] = work1d.KKT[1642];
  work1d.d[821] = work1d.v[821];
  if (work1d.d[821] < 0)
    work1d.d[821] = settings1d.kkt_reg;
  else
    work1d.d[821] += settings1d.kkt_reg;
  work1d.d_inv[821] = 1/work1d.d[821];
  work1d.L[880] = (work1d.KKT[1643])*work1d.d_inv[821];
  work1d.L[901] = (work1d.KKT[1644])*work1d.d_inv[821];
  work1d.v[822] = work1d.KKT[1645];
  work1d.d[822] = work1d.v[822];
  if (work1d.d[822] < 0)
    work1d.d[822] = settings1d.kkt_reg;
  else
    work1d.d[822] += settings1d.kkt_reg;
  work1d.d_inv[822] = 1/work1d.d[822];
  work1d.L[902] = (work1d.KKT[1646])*work1d.d_inv[822];
  work1d.L[923] = (work1d.KKT[1647])*work1d.d_inv[822];
  work1d.v[823] = work1d.KKT[1648];
  work1d.d[823] = work1d.v[823];
  if (work1d.d[823] < 0)
    work1d.d[823] = settings1d.kkt_reg;
  else
    work1d.d[823] += settings1d.kkt_reg;
  work1d.d_inv[823] = 1/work1d.d[823];
  work1d.L[924] = (work1d.KKT[1649])*work1d.d_inv[823];
  work1d.L[945] = (work1d.KKT[1650])*work1d.d_inv[823];
  work1d.v[824] = work1d.KKT[1651];
  work1d.d[824] = work1d.v[824];
  if (work1d.d[824] < 0)
    work1d.d[824] = settings1d.kkt_reg;
  else
    work1d.d[824] += settings1d.kkt_reg;
  work1d.d_inv[824] = 1/work1d.d[824];
  work1d.L[946] = (work1d.KKT[1652])*work1d.d_inv[824];
  work1d.L[967] = (work1d.KKT[1653])*work1d.d_inv[824];
  work1d.v[825] = work1d.KKT[1654];
  work1d.d[825] = work1d.v[825];
  if (work1d.d[825] < 0)
    work1d.d[825] = settings1d.kkt_reg;
  else
    work1d.d[825] += settings1d.kkt_reg;
  work1d.d_inv[825] = 1/work1d.d[825];
  work1d.L[968] = (work1d.KKT[1655])*work1d.d_inv[825];
  work1d.L[989] = (work1d.KKT[1656])*work1d.d_inv[825];
  work1d.v[826] = work1d.KKT[1657];
  work1d.d[826] = work1d.v[826];
  if (work1d.d[826] < 0)
    work1d.d[826] = settings1d.kkt_reg;
  else
    work1d.d[826] += settings1d.kkt_reg;
  work1d.d_inv[826] = 1/work1d.d[826];
  work1d.L[990] = (work1d.KKT[1658])*work1d.d_inv[826];
  work1d.L[1011] = (work1d.KKT[1659])*work1d.d_inv[826];
  work1d.v[827] = work1d.KKT[1660];
  work1d.d[827] = work1d.v[827];
  if (work1d.d[827] < 0)
    work1d.d[827] = settings1d.kkt_reg;
  else
    work1d.d[827] += settings1d.kkt_reg;
  work1d.d_inv[827] = 1/work1d.d[827];
  work1d.L[1012] = (work1d.KKT[1661])*work1d.d_inv[827];
  work1d.L[1033] = (work1d.KKT[1662])*work1d.d_inv[827];
  work1d.v[828] = work1d.KKT[1663];
  work1d.d[828] = work1d.v[828];
  if (work1d.d[828] < 0)
    work1d.d[828] = settings1d.kkt_reg;
  else
    work1d.d[828] += settings1d.kkt_reg;
  work1d.d_inv[828] = 1/work1d.d[828];
  work1d.L[1034] = (work1d.KKT[1664])*work1d.d_inv[828];
  work1d.L[1055] = (work1d.KKT[1665])*work1d.d_inv[828];
  work1d.v[829] = work1d.KKT[1666];
  work1d.d[829] = work1d.v[829];
  if (work1d.d[829] < 0)
    work1d.d[829] = settings1d.kkt_reg;
  else
    work1d.d[829] += settings1d.kkt_reg;
  work1d.d_inv[829] = 1/work1d.d[829];
  work1d.L[1056] = (work1d.KKT[1667])*work1d.d_inv[829];
  work1d.L[1077] = (work1d.KKT[1668])*work1d.d_inv[829];
  work1d.v[830] = work1d.KKT[1669];
  work1d.d[830] = work1d.v[830];
  if (work1d.d[830] < 0)
    work1d.d[830] = settings1d.kkt_reg;
  else
    work1d.d[830] += settings1d.kkt_reg;
  work1d.d_inv[830] = 1/work1d.d[830];
  work1d.L[1078] = (work1d.KKT[1670])*work1d.d_inv[830];
  work1d.L[1099] = (work1d.KKT[1671])*work1d.d_inv[830];
  work1d.v[831] = work1d.KKT[1672];
  work1d.d[831] = work1d.v[831];
  if (work1d.d[831] < 0)
    work1d.d[831] = settings1d.kkt_reg;
  else
    work1d.d[831] += settings1d.kkt_reg;
  work1d.d_inv[831] = 1/work1d.d[831];
  work1d.L[1100] = (work1d.KKT[1673])*work1d.d_inv[831];
  work1d.L[1121] = (work1d.KKT[1674])*work1d.d_inv[831];
  work1d.v[832] = work1d.KKT[1675];
  work1d.d[832] = work1d.v[832];
  if (work1d.d[832] < 0)
    work1d.d[832] = settings1d.kkt_reg;
  else
    work1d.d[832] += settings1d.kkt_reg;
  work1d.d_inv[832] = 1/work1d.d[832];
  work1d.L[1122] = (work1d.KKT[1676])*work1d.d_inv[832];
  work1d.L[1143] = (work1d.KKT[1677])*work1d.d_inv[832];
  work1d.v[833] = work1d.KKT[1678];
  work1d.d[833] = work1d.v[833];
  if (work1d.d[833] < 0)
    work1d.d[833] = settings1d.kkt_reg;
  else
    work1d.d[833] += settings1d.kkt_reg;
  work1d.d_inv[833] = 1/work1d.d[833];
  work1d.L[1144] = (work1d.KKT[1679])*work1d.d_inv[833];
  work1d.L[1165] = (work1d.KKT[1680])*work1d.d_inv[833];
  work1d.v[834] = work1d.KKT[1681];
  work1d.d[834] = work1d.v[834];
  if (work1d.d[834] < 0)
    work1d.d[834] = settings1d.kkt_reg;
  else
    work1d.d[834] += settings1d.kkt_reg;
  work1d.d_inv[834] = 1/work1d.d[834];
  work1d.L[1166] = (work1d.KKT[1682])*work1d.d_inv[834];
  work1d.L[1187] = (work1d.KKT[1683])*work1d.d_inv[834];
  work1d.v[835] = work1d.KKT[1684];
  work1d.d[835] = work1d.v[835];
  if (work1d.d[835] < 0)
    work1d.d[835] = settings1d.kkt_reg;
  else
    work1d.d[835] += settings1d.kkt_reg;
  work1d.d_inv[835] = 1/work1d.d[835];
  work1d.L[1188] = (work1d.KKT[1685])*work1d.d_inv[835];
  work1d.L[1209] = (work1d.KKT[1686])*work1d.d_inv[835];
  work1d.v[836] = work1d.KKT[1687];
  work1d.d[836] = work1d.v[836];
  if (work1d.d[836] < 0)
    work1d.d[836] = settings1d.kkt_reg;
  else
    work1d.d[836] += settings1d.kkt_reg;
  work1d.d_inv[836] = 1/work1d.d[836];
  work1d.L[1210] = (work1d.KKT[1688])*work1d.d_inv[836];
  work1d.L[1231] = (work1d.KKT[1689])*work1d.d_inv[836];
  work1d.v[837] = work1d.KKT[1690];
  work1d.d[837] = work1d.v[837];
  if (work1d.d[837] < 0)
    work1d.d[837] = settings1d.kkt_reg;
  else
    work1d.d[837] += settings1d.kkt_reg;
  work1d.d_inv[837] = 1/work1d.d[837];
  work1d.L[1232] = (work1d.KKT[1691])*work1d.d_inv[837];
  work1d.L[1253] = (work1d.KKT[1692])*work1d.d_inv[837];
  work1d.v[838] = work1d.KKT[1693];
  work1d.d[838] = work1d.v[838];
  if (work1d.d[838] < 0)
    work1d.d[838] = settings1d.kkt_reg;
  else
    work1d.d[838] += settings1d.kkt_reg;
  work1d.d_inv[838] = 1/work1d.d[838];
  work1d.L[1254] = (work1d.KKT[1694])*work1d.d_inv[838];
  work1d.L[1275] = (work1d.KKT[1695])*work1d.d_inv[838];
  work1d.v[839] = work1d.KKT[1696];
  work1d.d[839] = work1d.v[839];
  if (work1d.d[839] < 0)
    work1d.d[839] = settings1d.kkt_reg;
  else
    work1d.d[839] += settings1d.kkt_reg;
  work1d.d_inv[839] = 1/work1d.d[839];
  work1d.L[1276] = (work1d.KKT[1697])*work1d.d_inv[839];
  work1d.L[1297] = (work1d.KKT[1698])*work1d.d_inv[839];
  work1d.v[840] = work1d.KKT[1699];
  work1d.d[840] = work1d.v[840];
  if (work1d.d[840] < 0)
    work1d.d[840] = settings1d.kkt_reg;
  else
    work1d.d[840] += settings1d.kkt_reg;
  work1d.d_inv[840] = 1/work1d.d[840];
  work1d.L[1298] = (work1d.KKT[1700])*work1d.d_inv[840];
  work1d.L[1319] = (work1d.KKT[1701])*work1d.d_inv[840];
  work1d.v[841] = work1d.KKT[1702];
  work1d.d[841] = work1d.v[841];
  if (work1d.d[841] < 0)
    work1d.d[841] = settings1d.kkt_reg;
  else
    work1d.d[841] += settings1d.kkt_reg;
  work1d.d_inv[841] = 1/work1d.d[841];
  work1d.L[1320] = (work1d.KKT[1703])*work1d.d_inv[841];
  work1d.L[1341] = (work1d.KKT[1704])*work1d.d_inv[841];
  work1d.v[842] = work1d.KKT[1705];
  work1d.d[842] = work1d.v[842];
  if (work1d.d[842] < 0)
    work1d.d[842] = settings1d.kkt_reg;
  else
    work1d.d[842] += settings1d.kkt_reg;
  work1d.d_inv[842] = 1/work1d.d[842];
  work1d.L[1342] = (work1d.KKT[1706])*work1d.d_inv[842];
  work1d.L[1363] = (work1d.KKT[1707])*work1d.d_inv[842];
  work1d.v[843] = work1d.KKT[1708];
  work1d.d[843] = work1d.v[843];
  if (work1d.d[843] < 0)
    work1d.d[843] = settings1d.kkt_reg;
  else
    work1d.d[843] += settings1d.kkt_reg;
  work1d.d_inv[843] = 1/work1d.d[843];
  work1d.L[1364] = (work1d.KKT[1709])*work1d.d_inv[843];
  work1d.L[1385] = (work1d.KKT[1710])*work1d.d_inv[843];
  work1d.v[844] = work1d.KKT[1711];
  work1d.d[844] = work1d.v[844];
  if (work1d.d[844] < 0)
    work1d.d[844] = settings1d.kkt_reg;
  else
    work1d.d[844] += settings1d.kkt_reg;
  work1d.d_inv[844] = 1/work1d.d[844];
  work1d.L[1386] = (work1d.KKT[1712])*work1d.d_inv[844];
  work1d.L[1407] = (work1d.KKT[1713])*work1d.d_inv[844];
  work1d.v[845] = work1d.KKT[1714];
  work1d.d[845] = work1d.v[845];
  if (work1d.d[845] < 0)
    work1d.d[845] = settings1d.kkt_reg;
  else
    work1d.d[845] += settings1d.kkt_reg;
  work1d.d_inv[845] = 1/work1d.d[845];
  work1d.L[1408] = (work1d.KKT[1715])*work1d.d_inv[845];
  work1d.L[1429] = (work1d.KKT[1716])*work1d.d_inv[845];
  work1d.v[846] = work1d.KKT[1717];
  work1d.d[846] = work1d.v[846];
  if (work1d.d[846] < 0)
    work1d.d[846] = settings1d.kkt_reg;
  else
    work1d.d[846] += settings1d.kkt_reg;
  work1d.d_inv[846] = 1/work1d.d[846];
  work1d.L[1430] = (work1d.KKT[1718])*work1d.d_inv[846];
  work1d.L[1451] = (work1d.KKT[1719])*work1d.d_inv[846];
  work1d.v[847] = work1d.KKT[1720];
  work1d.d[847] = work1d.v[847];
  if (work1d.d[847] < 0)
    work1d.d[847] = settings1d.kkt_reg;
  else
    work1d.d[847] += settings1d.kkt_reg;
  work1d.d_inv[847] = 1/work1d.d[847];
  work1d.L[1452] = (work1d.KKT[1721])*work1d.d_inv[847];
  work1d.L[1473] = (work1d.KKT[1722])*work1d.d_inv[847];
  work1d.v[848] = work1d.KKT[1723];
  work1d.d[848] = work1d.v[848];
  if (work1d.d[848] < 0)
    work1d.d[848] = settings1d.kkt_reg;
  else
    work1d.d[848] += settings1d.kkt_reg;
  work1d.d_inv[848] = 1/work1d.d[848];
  work1d.L[1474] = (work1d.KKT[1724])*work1d.d_inv[848];
  work1d.L[1495] = (work1d.KKT[1725])*work1d.d_inv[848];
  work1d.v[849] = work1d.KKT[1726];
  work1d.d[849] = work1d.v[849];
  if (work1d.d[849] < 0)
    work1d.d[849] = settings1d.kkt_reg;
  else
    work1d.d[849] += settings1d.kkt_reg;
  work1d.d_inv[849] = 1/work1d.d[849];
  work1d.L[1496] = (work1d.KKT[1727])*work1d.d_inv[849];
  work1d.L[1504] = (work1d.KKT[1728])*work1d.d_inv[849];
  work1d.v[809] = work1d.L[710]*work1d.d[809];
  work1d.v[850] = work1d.KKT[1729]-work1d.L[710]*work1d.v[809];
  work1d.d[850] = work1d.v[850];
  if (work1d.d[850] < 0)
    work1d.d[850] = settings1d.kkt_reg;
  else
    work1d.d[850] += settings1d.kkt_reg;
  work1d.d_inv[850] = 1/work1d.d[850];
  work1d.L[1505] = (work1d.KKT[1730])*work1d.d_inv[850];
  work1d.L[1531] = (-work1d.L[1529]*work1d.v[809])*work1d.d_inv[850];
  work1d.v[811] = work1d.L[711]*work1d.d[811];
  work1d.v[812] = work1d.L[712]*work1d.d[812];
  work1d.v[813] = work1d.L[713]*work1d.d[813];
  work1d.v[851] = 0-work1d.L[711]*work1d.v[811]-work1d.L[712]*work1d.v[812]-work1d.L[713]*work1d.v[813];
  work1d.d[851] = work1d.v[851];
  if (work1d.d[851] > 0)
    work1d.d[851] = -settings1d.kkt_reg;
  else
    work1d.d[851] -= settings1d.kkt_reg;
  work1d.d_inv[851] = 1/work1d.d[851];
  work1d.L[717] = (work1d.KKT[1731])*work1d.d_inv[851];
  work1d.L[724] = (-work1d.L[723]*work1d.v[812])*work1d.d_inv[851];
  work1d.L[728] = (-work1d.L[726]*work1d.v[813])*work1d.d_inv[851];
  work1d.v[322] = work1d.L[714]*work1d.d[322];
  work1d.v[452] = work1d.L[715]*work1d.d[452];
  work1d.v[453] = work1d.L[716]*work1d.d[453];
  work1d.v[851] = work1d.L[717]*work1d.d[851];
  work1d.v[852] = work1d.KKT[1732]-work1d.L[714]*work1d.v[322]-work1d.L[715]*work1d.v[452]-work1d.L[716]*work1d.v[453]-work1d.L[717]*work1d.v[851];
  work1d.d[852] = work1d.v[852];
  if (work1d.d[852] < 0)
    work1d.d[852] = settings1d.kkt_reg;
  else
    work1d.d[852] += settings1d.kkt_reg;
  work1d.d_inv[852] = 1/work1d.d[852];
  work1d.L[725] = (-work1d.L[724]*work1d.v[851])*work1d.d_inv[852];
  work1d.L[729] = (work1d.KKT[1733]-work1d.L[728]*work1d.v[851])*work1d.d_inv[852];
  work1d.L[731] = (work1d.KKT[1734])*work1d.d_inv[852];
  work1d.v[362] = work1d.L[718]*work1d.d[362];
  work1d.v[613] = work1d.L[719]*work1d.d[613];
  work1d.v[614] = work1d.L[720]*work1d.d[614];
  work1d.v[771] = work1d.L[721]*work1d.d[771];
  work1d.v[772] = work1d.L[722]*work1d.d[772];
  work1d.v[812] = work1d.L[723]*work1d.d[812];
  work1d.v[851] = work1d.L[724]*work1d.d[851];
  work1d.v[852] = work1d.L[725]*work1d.d[852];
  work1d.v[853] = work1d.KKT[1735]-work1d.L[718]*work1d.v[362]-work1d.L[719]*work1d.v[613]-work1d.L[720]*work1d.v[614]-work1d.L[721]*work1d.v[771]-work1d.L[722]*work1d.v[772]-work1d.L[723]*work1d.v[812]-work1d.L[724]*work1d.v[851]-work1d.L[725]*work1d.v[852];
  work1d.d[853] = work1d.v[853];
  if (work1d.d[853] < 0)
    work1d.d[853] = settings1d.kkt_reg;
  else
    work1d.d[853] += settings1d.kkt_reg;
  work1d.d_inv[853] = 1/work1d.d[853];
  work1d.L[730] = (-work1d.L[728]*work1d.v[851]-work1d.L[729]*work1d.v[852])*work1d.d_inv[853];
  work1d.L[732] = (work1d.KKT[1736]-work1d.L[731]*work1d.v[852])*work1d.d_inv[853];
  work1d.L[743] = (-work1d.L[741]*work1d.v[772])*work1d.d_inv[853];
  work1d.v[813] = work1d.L[726]*work1d.d[813];
  work1d.v[814] = work1d.L[727]*work1d.d[814];
  work1d.v[851] = work1d.L[728]*work1d.d[851];
  work1d.v[852] = work1d.L[729]*work1d.d[852];
  work1d.v[853] = work1d.L[730]*work1d.d[853];
  work1d.v[854] = 0-work1d.L[726]*work1d.v[813]-work1d.L[727]*work1d.v[814]-work1d.L[728]*work1d.v[851]-work1d.L[729]*work1d.v[852]-work1d.L[730]*work1d.v[853];
  work1d.d[854] = work1d.v[854];
  if (work1d.d[854] > 0)
    work1d.d[854] = -settings1d.kkt_reg;
  else
    work1d.d[854] -= settings1d.kkt_reg;
  work1d.d_inv[854] = 1/work1d.d[854];
  work1d.L[733] = (-work1d.L[731]*work1d.v[852]-work1d.L[732]*work1d.v[853])*work1d.d_inv[854];
  work1d.L[744] = (-work1d.L[743]*work1d.v[853])*work1d.d_inv[854];
  work1d.L[749] = (-work1d.L[747]*work1d.v[814])*work1d.d_inv[854];
  work1d.v[852] = work1d.L[731]*work1d.d[852];
  work1d.v[853] = work1d.L[732]*work1d.d[853];
  work1d.v[854] = work1d.L[733]*work1d.d[854];
  work1d.v[855] = 0-work1d.L[731]*work1d.v[852]-work1d.L[732]*work1d.v[853]-work1d.L[733]*work1d.v[854];
  work1d.d[855] = work1d.v[855];
  if (work1d.d[855] > 0)
    work1d.d[855] = -settings1d.kkt_reg;
  else
    work1d.d[855] -= settings1d.kkt_reg;
  work1d.d_inv[855] = 1/work1d.d[855];
  work1d.L[737] = (work1d.KKT[1737])*work1d.d_inv[855];
  work1d.L[745] = (-work1d.L[743]*work1d.v[853]-work1d.L[744]*work1d.v[854])*work1d.d_inv[855];
  work1d.L[750] = (-work1d.L[749]*work1d.v[854])*work1d.d_inv[855];
  work1d.v[323] = work1d.L[734]*work1d.d[323];
  work1d.v[456] = work1d.L[735]*work1d.d[456];
  work1d.v[457] = work1d.L[736]*work1d.d[457];
  work1d.v[855] = work1d.L[737]*work1d.d[855];
  work1d.v[856] = work1d.KKT[1738]-work1d.L[734]*work1d.v[323]-work1d.L[735]*work1d.v[456]-work1d.L[736]*work1d.v[457]-work1d.L[737]*work1d.v[855];
  work1d.d[856] = work1d.v[856];
  if (work1d.d[856] < 0)
    work1d.d[856] = settings1d.kkt_reg;
  else
    work1d.d[856] += settings1d.kkt_reg;
  work1d.d_inv[856] = 1/work1d.d[856];
  work1d.L[746] = (-work1d.L[745]*work1d.v[855])*work1d.d_inv[856];
  work1d.L[751] = (work1d.KKT[1739]-work1d.L[750]*work1d.v[855])*work1d.d_inv[856];
  work1d.L[753] = (work1d.KKT[1740])*work1d.d_inv[856];
  work1d.v[363] = work1d.L[738]*work1d.d[363];
  work1d.v[617] = work1d.L[739]*work1d.d[617];
  work1d.v[618] = work1d.L[740]*work1d.d[618];
  work1d.v[772] = work1d.L[741]*work1d.d[772];
  work1d.v[773] = work1d.L[742]*work1d.d[773];
  work1d.v[853] = work1d.L[743]*work1d.d[853];
  work1d.v[854] = work1d.L[744]*work1d.d[854];
  work1d.v[855] = work1d.L[745]*work1d.d[855];
  work1d.v[856] = work1d.L[746]*work1d.d[856];
  work1d.v[857] = work1d.KKT[1741]-work1d.L[738]*work1d.v[363]-work1d.L[739]*work1d.v[617]-work1d.L[740]*work1d.v[618]-work1d.L[741]*work1d.v[772]-work1d.L[742]*work1d.v[773]-work1d.L[743]*work1d.v[853]-work1d.L[744]*work1d.v[854]-work1d.L[745]*work1d.v[855]-work1d.L[746]*work1d.v[856];
  work1d.d[857] = work1d.v[857];
  if (work1d.d[857] < 0)
    work1d.d[857] = settings1d.kkt_reg;
  else
    work1d.d[857] += settings1d.kkt_reg;
  work1d.d_inv[857] = 1/work1d.d[857];
  work1d.L[752] = (-work1d.L[749]*work1d.v[854]-work1d.L[750]*work1d.v[855]-work1d.L[751]*work1d.v[856])*work1d.d_inv[857];
  work1d.L[754] = (work1d.KKT[1742]-work1d.L[753]*work1d.v[856])*work1d.d_inv[857];
  work1d.L[765] = (-work1d.L[763]*work1d.v[773])*work1d.d_inv[857];
  work1d.v[814] = work1d.L[747]*work1d.d[814];
  work1d.v[815] = work1d.L[748]*work1d.d[815];
  work1d.v[854] = work1d.L[749]*work1d.d[854];
  work1d.v[855] = work1d.L[750]*work1d.d[855];
  work1d.v[856] = work1d.L[751]*work1d.d[856];
  work1d.v[857] = work1d.L[752]*work1d.d[857];
  work1d.v[858] = 0-work1d.L[747]*work1d.v[814]-work1d.L[748]*work1d.v[815]-work1d.L[749]*work1d.v[854]-work1d.L[750]*work1d.v[855]-work1d.L[751]*work1d.v[856]-work1d.L[752]*work1d.v[857];
  work1d.d[858] = work1d.v[858];
  if (work1d.d[858] > 0)
    work1d.d[858] = -settings1d.kkt_reg;
  else
    work1d.d[858] -= settings1d.kkt_reg;
  work1d.d_inv[858] = 1/work1d.d[858];
  work1d.L[755] = (-work1d.L[753]*work1d.v[856]-work1d.L[754]*work1d.v[857])*work1d.d_inv[858];
  work1d.L[766] = (-work1d.L[765]*work1d.v[857])*work1d.d_inv[858];
  work1d.L[771] = (-work1d.L[769]*work1d.v[815])*work1d.d_inv[858];
  work1d.v[856] = work1d.L[753]*work1d.d[856];
  work1d.v[857] = work1d.L[754]*work1d.d[857];
  work1d.v[858] = work1d.L[755]*work1d.d[858];
  work1d.v[859] = 0-work1d.L[753]*work1d.v[856]-work1d.L[754]*work1d.v[857]-work1d.L[755]*work1d.v[858];
  work1d.d[859] = work1d.v[859];
  if (work1d.d[859] > 0)
    work1d.d[859] = -settings1d.kkt_reg;
  else
    work1d.d[859] -= settings1d.kkt_reg;
  work1d.d_inv[859] = 1/work1d.d[859];
  work1d.L[759] = (work1d.KKT[1743])*work1d.d_inv[859];
  work1d.L[767] = (-work1d.L[765]*work1d.v[857]-work1d.L[766]*work1d.v[858])*work1d.d_inv[859];
  work1d.L[772] = (-work1d.L[771]*work1d.v[858])*work1d.d_inv[859];
  work1d.v[324] = work1d.L[756]*work1d.d[324];
  work1d.v[460] = work1d.L[757]*work1d.d[460];
  work1d.v[461] = work1d.L[758]*work1d.d[461];
  work1d.v[859] = work1d.L[759]*work1d.d[859];
  work1d.v[860] = work1d.KKT[1744]-work1d.L[756]*work1d.v[324]-work1d.L[757]*work1d.v[460]-work1d.L[758]*work1d.v[461]-work1d.L[759]*work1d.v[859];
  work1d.d[860] = work1d.v[860];
  if (work1d.d[860] < 0)
    work1d.d[860] = settings1d.kkt_reg;
  else
    work1d.d[860] += settings1d.kkt_reg;
  work1d.d_inv[860] = 1/work1d.d[860];
  work1d.L[768] = (-work1d.L[767]*work1d.v[859])*work1d.d_inv[860];
  work1d.L[773] = (work1d.KKT[1745]-work1d.L[772]*work1d.v[859])*work1d.d_inv[860];
  work1d.L[775] = (work1d.KKT[1746])*work1d.d_inv[860];
  work1d.v[364] = work1d.L[760]*work1d.d[364];
  work1d.v[621] = work1d.L[761]*work1d.d[621];
  work1d.v[622] = work1d.L[762]*work1d.d[622];
  work1d.v[773] = work1d.L[763]*work1d.d[773];
  work1d.v[774] = work1d.L[764]*work1d.d[774];
  work1d.v[857] = work1d.L[765]*work1d.d[857];
  work1d.v[858] = work1d.L[766]*work1d.d[858];
  work1d.v[859] = work1d.L[767]*work1d.d[859];
  work1d.v[860] = work1d.L[768]*work1d.d[860];
  work1d.v[861] = work1d.KKT[1747]-work1d.L[760]*work1d.v[364]-work1d.L[761]*work1d.v[621]-work1d.L[762]*work1d.v[622]-work1d.L[763]*work1d.v[773]-work1d.L[764]*work1d.v[774]-work1d.L[765]*work1d.v[857]-work1d.L[766]*work1d.v[858]-work1d.L[767]*work1d.v[859]-work1d.L[768]*work1d.v[860];
  work1d.d[861] = work1d.v[861];
  if (work1d.d[861] < 0)
    work1d.d[861] = settings1d.kkt_reg;
  else
    work1d.d[861] += settings1d.kkt_reg;
  work1d.d_inv[861] = 1/work1d.d[861];
  work1d.L[774] = (-work1d.L[771]*work1d.v[858]-work1d.L[772]*work1d.v[859]-work1d.L[773]*work1d.v[860])*work1d.d_inv[861];
  work1d.L[776] = (work1d.KKT[1748]-work1d.L[775]*work1d.v[860])*work1d.d_inv[861];
  work1d.L[787] = (-work1d.L[785]*work1d.v[774])*work1d.d_inv[861];
  work1d.v[815] = work1d.L[769]*work1d.d[815];
  work1d.v[816] = work1d.L[770]*work1d.d[816];
  work1d.v[858] = work1d.L[771]*work1d.d[858];
  work1d.v[859] = work1d.L[772]*work1d.d[859];
  work1d.v[860] = work1d.L[773]*work1d.d[860];
  work1d.v[861] = work1d.L[774]*work1d.d[861];
  work1d.v[862] = 0-work1d.L[769]*work1d.v[815]-work1d.L[770]*work1d.v[816]-work1d.L[771]*work1d.v[858]-work1d.L[772]*work1d.v[859]-work1d.L[773]*work1d.v[860]-work1d.L[774]*work1d.v[861];
  work1d.d[862] = work1d.v[862];
  if (work1d.d[862] > 0)
    work1d.d[862] = -settings1d.kkt_reg;
  else
    work1d.d[862] -= settings1d.kkt_reg;
  work1d.d_inv[862] = 1/work1d.d[862];
  work1d.L[777] = (-work1d.L[775]*work1d.v[860]-work1d.L[776]*work1d.v[861])*work1d.d_inv[862];
  work1d.L[788] = (-work1d.L[787]*work1d.v[861])*work1d.d_inv[862];
  work1d.L[793] = (-work1d.L[791]*work1d.v[816])*work1d.d_inv[862];
  work1d.v[860] = work1d.L[775]*work1d.d[860];
  work1d.v[861] = work1d.L[776]*work1d.d[861];
  work1d.v[862] = work1d.L[777]*work1d.d[862];
  work1d.v[863] = 0-work1d.L[775]*work1d.v[860]-work1d.L[776]*work1d.v[861]-work1d.L[777]*work1d.v[862];
  work1d.d[863] = work1d.v[863];
  if (work1d.d[863] > 0)
    work1d.d[863] = -settings1d.kkt_reg;
  else
    work1d.d[863] -= settings1d.kkt_reg;
  work1d.d_inv[863] = 1/work1d.d[863];
  work1d.L[781] = (work1d.KKT[1749])*work1d.d_inv[863];
  work1d.L[789] = (-work1d.L[787]*work1d.v[861]-work1d.L[788]*work1d.v[862])*work1d.d_inv[863];
  work1d.L[794] = (-work1d.L[793]*work1d.v[862])*work1d.d_inv[863];
  work1d.v[325] = work1d.L[778]*work1d.d[325];
  work1d.v[464] = work1d.L[779]*work1d.d[464];
  work1d.v[465] = work1d.L[780]*work1d.d[465];
  work1d.v[863] = work1d.L[781]*work1d.d[863];
  work1d.v[864] = work1d.KKT[1750]-work1d.L[778]*work1d.v[325]-work1d.L[779]*work1d.v[464]-work1d.L[780]*work1d.v[465]-work1d.L[781]*work1d.v[863];
  work1d.d[864] = work1d.v[864];
  if (work1d.d[864] < 0)
    work1d.d[864] = settings1d.kkt_reg;
  else
    work1d.d[864] += settings1d.kkt_reg;
  work1d.d_inv[864] = 1/work1d.d[864];
  work1d.L[790] = (-work1d.L[789]*work1d.v[863])*work1d.d_inv[864];
  work1d.L[795] = (work1d.KKT[1751]-work1d.L[794]*work1d.v[863])*work1d.d_inv[864];
  work1d.L[797] = (work1d.KKT[1752])*work1d.d_inv[864];
  work1d.v[365] = work1d.L[782]*work1d.d[365];
  work1d.v[625] = work1d.L[783]*work1d.d[625];
  work1d.v[626] = work1d.L[784]*work1d.d[626];
  work1d.v[774] = work1d.L[785]*work1d.d[774];
  work1d.v[775] = work1d.L[786]*work1d.d[775];
  work1d.v[861] = work1d.L[787]*work1d.d[861];
  work1d.v[862] = work1d.L[788]*work1d.d[862];
  work1d.v[863] = work1d.L[789]*work1d.d[863];
  work1d.v[864] = work1d.L[790]*work1d.d[864];
  work1d.v[865] = work1d.KKT[1753]-work1d.L[782]*work1d.v[365]-work1d.L[783]*work1d.v[625]-work1d.L[784]*work1d.v[626]-work1d.L[785]*work1d.v[774]-work1d.L[786]*work1d.v[775]-work1d.L[787]*work1d.v[861]-work1d.L[788]*work1d.v[862]-work1d.L[789]*work1d.v[863]-work1d.L[790]*work1d.v[864];
  work1d.d[865] = work1d.v[865];
  if (work1d.d[865] < 0)
    work1d.d[865] = settings1d.kkt_reg;
  else
    work1d.d[865] += settings1d.kkt_reg;
  work1d.d_inv[865] = 1/work1d.d[865];
  work1d.L[796] = (-work1d.L[793]*work1d.v[862]-work1d.L[794]*work1d.v[863]-work1d.L[795]*work1d.v[864])*work1d.d_inv[865];
  work1d.L[798] = (work1d.KKT[1754]-work1d.L[797]*work1d.v[864])*work1d.d_inv[865];
  work1d.L[809] = (-work1d.L[807]*work1d.v[775])*work1d.d_inv[865];
  work1d.v[816] = work1d.L[791]*work1d.d[816];
  work1d.v[817] = work1d.L[792]*work1d.d[817];
  work1d.v[862] = work1d.L[793]*work1d.d[862];
  work1d.v[863] = work1d.L[794]*work1d.d[863];
  work1d.v[864] = work1d.L[795]*work1d.d[864];
  work1d.v[865] = work1d.L[796]*work1d.d[865];
  work1d.v[866] = 0-work1d.L[791]*work1d.v[816]-work1d.L[792]*work1d.v[817]-work1d.L[793]*work1d.v[862]-work1d.L[794]*work1d.v[863]-work1d.L[795]*work1d.v[864]-work1d.L[796]*work1d.v[865];
  work1d.d[866] = work1d.v[866];
  if (work1d.d[866] > 0)
    work1d.d[866] = -settings1d.kkt_reg;
  else
    work1d.d[866] -= settings1d.kkt_reg;
  work1d.d_inv[866] = 1/work1d.d[866];
  work1d.L[799] = (-work1d.L[797]*work1d.v[864]-work1d.L[798]*work1d.v[865])*work1d.d_inv[866];
  work1d.L[810] = (-work1d.L[809]*work1d.v[865])*work1d.d_inv[866];
  work1d.L[815] = (-work1d.L[813]*work1d.v[817])*work1d.d_inv[866];
  work1d.v[864] = work1d.L[797]*work1d.d[864];
  work1d.v[865] = work1d.L[798]*work1d.d[865];
  work1d.v[866] = work1d.L[799]*work1d.d[866];
  work1d.v[867] = 0-work1d.L[797]*work1d.v[864]-work1d.L[798]*work1d.v[865]-work1d.L[799]*work1d.v[866];
  work1d.d[867] = work1d.v[867];
  if (work1d.d[867] > 0)
    work1d.d[867] = -settings1d.kkt_reg;
  else
    work1d.d[867] -= settings1d.kkt_reg;
  work1d.d_inv[867] = 1/work1d.d[867];
  work1d.L[803] = (work1d.KKT[1755])*work1d.d_inv[867];
  work1d.L[811] = (-work1d.L[809]*work1d.v[865]-work1d.L[810]*work1d.v[866])*work1d.d_inv[867];
  work1d.L[816] = (-work1d.L[815]*work1d.v[866])*work1d.d_inv[867];
  work1d.v[326] = work1d.L[800]*work1d.d[326];
  work1d.v[468] = work1d.L[801]*work1d.d[468];
  work1d.v[469] = work1d.L[802]*work1d.d[469];
  work1d.v[867] = work1d.L[803]*work1d.d[867];
  work1d.v[868] = work1d.KKT[1756]-work1d.L[800]*work1d.v[326]-work1d.L[801]*work1d.v[468]-work1d.L[802]*work1d.v[469]-work1d.L[803]*work1d.v[867];
  work1d.d[868] = work1d.v[868];
  if (work1d.d[868] < 0)
    work1d.d[868] = settings1d.kkt_reg;
  else
    work1d.d[868] += settings1d.kkt_reg;
  work1d.d_inv[868] = 1/work1d.d[868];
  work1d.L[812] = (-work1d.L[811]*work1d.v[867])*work1d.d_inv[868];
  work1d.L[817] = (work1d.KKT[1757]-work1d.L[816]*work1d.v[867])*work1d.d_inv[868];
  work1d.L[819] = (work1d.KKT[1758])*work1d.d_inv[868];
  work1d.v[366] = work1d.L[804]*work1d.d[366];
  work1d.v[629] = work1d.L[805]*work1d.d[629];
  work1d.v[630] = work1d.L[806]*work1d.d[630];
  work1d.v[775] = work1d.L[807]*work1d.d[775];
  work1d.v[776] = work1d.L[808]*work1d.d[776];
  work1d.v[865] = work1d.L[809]*work1d.d[865];
  work1d.v[866] = work1d.L[810]*work1d.d[866];
  work1d.v[867] = work1d.L[811]*work1d.d[867];
  work1d.v[868] = work1d.L[812]*work1d.d[868];
  work1d.v[869] = work1d.KKT[1759]-work1d.L[804]*work1d.v[366]-work1d.L[805]*work1d.v[629]-work1d.L[806]*work1d.v[630]-work1d.L[807]*work1d.v[775]-work1d.L[808]*work1d.v[776]-work1d.L[809]*work1d.v[865]-work1d.L[810]*work1d.v[866]-work1d.L[811]*work1d.v[867]-work1d.L[812]*work1d.v[868];
  work1d.d[869] = work1d.v[869];
  if (work1d.d[869] < 0)
    work1d.d[869] = settings1d.kkt_reg;
  else
    work1d.d[869] += settings1d.kkt_reg;
  work1d.d_inv[869] = 1/work1d.d[869];
  work1d.L[818] = (-work1d.L[815]*work1d.v[866]-work1d.L[816]*work1d.v[867]-work1d.L[817]*work1d.v[868])*work1d.d_inv[869];
  work1d.L[820] = (work1d.KKT[1760]-work1d.L[819]*work1d.v[868])*work1d.d_inv[869];
  work1d.L[831] = (-work1d.L[829]*work1d.v[776])*work1d.d_inv[869];
  work1d.v[817] = work1d.L[813]*work1d.d[817];
  work1d.v[818] = work1d.L[814]*work1d.d[818];
  work1d.v[866] = work1d.L[815]*work1d.d[866];
  work1d.v[867] = work1d.L[816]*work1d.d[867];
  work1d.v[868] = work1d.L[817]*work1d.d[868];
  work1d.v[869] = work1d.L[818]*work1d.d[869];
  work1d.v[870] = 0-work1d.L[813]*work1d.v[817]-work1d.L[814]*work1d.v[818]-work1d.L[815]*work1d.v[866]-work1d.L[816]*work1d.v[867]-work1d.L[817]*work1d.v[868]-work1d.L[818]*work1d.v[869];
  work1d.d[870] = work1d.v[870];
  if (work1d.d[870] > 0)
    work1d.d[870] = -settings1d.kkt_reg;
  else
    work1d.d[870] -= settings1d.kkt_reg;
  work1d.d_inv[870] = 1/work1d.d[870];
  work1d.L[821] = (-work1d.L[819]*work1d.v[868]-work1d.L[820]*work1d.v[869])*work1d.d_inv[870];
  work1d.L[832] = (-work1d.L[831]*work1d.v[869])*work1d.d_inv[870];
  work1d.L[837] = (-work1d.L[835]*work1d.v[818])*work1d.d_inv[870];
  work1d.v[868] = work1d.L[819]*work1d.d[868];
  work1d.v[869] = work1d.L[820]*work1d.d[869];
  work1d.v[870] = work1d.L[821]*work1d.d[870];
  work1d.v[871] = 0-work1d.L[819]*work1d.v[868]-work1d.L[820]*work1d.v[869]-work1d.L[821]*work1d.v[870];
  work1d.d[871] = work1d.v[871];
  if (work1d.d[871] > 0)
    work1d.d[871] = -settings1d.kkt_reg;
  else
    work1d.d[871] -= settings1d.kkt_reg;
  work1d.d_inv[871] = 1/work1d.d[871];
  work1d.L[825] = (work1d.KKT[1761])*work1d.d_inv[871];
  work1d.L[833] = (-work1d.L[831]*work1d.v[869]-work1d.L[832]*work1d.v[870])*work1d.d_inv[871];
  work1d.L[838] = (-work1d.L[837]*work1d.v[870])*work1d.d_inv[871];
  work1d.v[327] = work1d.L[822]*work1d.d[327];
  work1d.v[472] = work1d.L[823]*work1d.d[472];
  work1d.v[473] = work1d.L[824]*work1d.d[473];
  work1d.v[871] = work1d.L[825]*work1d.d[871];
  work1d.v[872] = work1d.KKT[1762]-work1d.L[822]*work1d.v[327]-work1d.L[823]*work1d.v[472]-work1d.L[824]*work1d.v[473]-work1d.L[825]*work1d.v[871];
  work1d.d[872] = work1d.v[872];
  if (work1d.d[872] < 0)
    work1d.d[872] = settings1d.kkt_reg;
  else
    work1d.d[872] += settings1d.kkt_reg;
  work1d.d_inv[872] = 1/work1d.d[872];
  work1d.L[834] = (-work1d.L[833]*work1d.v[871])*work1d.d_inv[872];
  work1d.L[839] = (work1d.KKT[1763]-work1d.L[838]*work1d.v[871])*work1d.d_inv[872];
  work1d.L[841] = (work1d.KKT[1764])*work1d.d_inv[872];
  work1d.v[367] = work1d.L[826]*work1d.d[367];
  work1d.v[633] = work1d.L[827]*work1d.d[633];
  work1d.v[634] = work1d.L[828]*work1d.d[634];
  work1d.v[776] = work1d.L[829]*work1d.d[776];
  work1d.v[777] = work1d.L[830]*work1d.d[777];
  work1d.v[869] = work1d.L[831]*work1d.d[869];
  work1d.v[870] = work1d.L[832]*work1d.d[870];
  work1d.v[871] = work1d.L[833]*work1d.d[871];
  work1d.v[872] = work1d.L[834]*work1d.d[872];
  work1d.v[873] = work1d.KKT[1765]-work1d.L[826]*work1d.v[367]-work1d.L[827]*work1d.v[633]-work1d.L[828]*work1d.v[634]-work1d.L[829]*work1d.v[776]-work1d.L[830]*work1d.v[777]-work1d.L[831]*work1d.v[869]-work1d.L[832]*work1d.v[870]-work1d.L[833]*work1d.v[871]-work1d.L[834]*work1d.v[872];
  work1d.d[873] = work1d.v[873];
  if (work1d.d[873] < 0)
    work1d.d[873] = settings1d.kkt_reg;
  else
    work1d.d[873] += settings1d.kkt_reg;
  work1d.d_inv[873] = 1/work1d.d[873];
  work1d.L[840] = (-work1d.L[837]*work1d.v[870]-work1d.L[838]*work1d.v[871]-work1d.L[839]*work1d.v[872])*work1d.d_inv[873];
  work1d.L[842] = (work1d.KKT[1766]-work1d.L[841]*work1d.v[872])*work1d.d_inv[873];
  work1d.L[853] = (-work1d.L[851]*work1d.v[777])*work1d.d_inv[873];
  work1d.v[818] = work1d.L[835]*work1d.d[818];
  work1d.v[819] = work1d.L[836]*work1d.d[819];
  work1d.v[870] = work1d.L[837]*work1d.d[870];
  work1d.v[871] = work1d.L[838]*work1d.d[871];
  work1d.v[872] = work1d.L[839]*work1d.d[872];
  work1d.v[873] = work1d.L[840]*work1d.d[873];
  work1d.v[874] = 0-work1d.L[835]*work1d.v[818]-work1d.L[836]*work1d.v[819]-work1d.L[837]*work1d.v[870]-work1d.L[838]*work1d.v[871]-work1d.L[839]*work1d.v[872]-work1d.L[840]*work1d.v[873];
  work1d.d[874] = work1d.v[874];
  if (work1d.d[874] > 0)
    work1d.d[874] = -settings1d.kkt_reg;
  else
    work1d.d[874] -= settings1d.kkt_reg;
  work1d.d_inv[874] = 1/work1d.d[874];
  work1d.L[843] = (-work1d.L[841]*work1d.v[872]-work1d.L[842]*work1d.v[873])*work1d.d_inv[874];
  work1d.L[854] = (-work1d.L[853]*work1d.v[873])*work1d.d_inv[874];
  work1d.L[859] = (-work1d.L[857]*work1d.v[819])*work1d.d_inv[874];
  work1d.v[872] = work1d.L[841]*work1d.d[872];
  work1d.v[873] = work1d.L[842]*work1d.d[873];
  work1d.v[874] = work1d.L[843]*work1d.d[874];
  work1d.v[875] = 0-work1d.L[841]*work1d.v[872]-work1d.L[842]*work1d.v[873]-work1d.L[843]*work1d.v[874];
  work1d.d[875] = work1d.v[875];
  if (work1d.d[875] > 0)
    work1d.d[875] = -settings1d.kkt_reg;
  else
    work1d.d[875] -= settings1d.kkt_reg;
  work1d.d_inv[875] = 1/work1d.d[875];
  work1d.L[847] = (work1d.KKT[1767])*work1d.d_inv[875];
  work1d.L[855] = (-work1d.L[853]*work1d.v[873]-work1d.L[854]*work1d.v[874])*work1d.d_inv[875];
  work1d.L[860] = (-work1d.L[859]*work1d.v[874])*work1d.d_inv[875];
  work1d.v[328] = work1d.L[844]*work1d.d[328];
  work1d.v[476] = work1d.L[845]*work1d.d[476];
  work1d.v[477] = work1d.L[846]*work1d.d[477];
  work1d.v[875] = work1d.L[847]*work1d.d[875];
  work1d.v[876] = work1d.KKT[1768]-work1d.L[844]*work1d.v[328]-work1d.L[845]*work1d.v[476]-work1d.L[846]*work1d.v[477]-work1d.L[847]*work1d.v[875];
  work1d.d[876] = work1d.v[876];
  if (work1d.d[876] < 0)
    work1d.d[876] = settings1d.kkt_reg;
  else
    work1d.d[876] += settings1d.kkt_reg;
  work1d.d_inv[876] = 1/work1d.d[876];
  work1d.L[856] = (-work1d.L[855]*work1d.v[875])*work1d.d_inv[876];
  work1d.L[861] = (work1d.KKT[1769]-work1d.L[860]*work1d.v[875])*work1d.d_inv[876];
  work1d.L[863] = (work1d.KKT[1770])*work1d.d_inv[876];
  work1d.v[368] = work1d.L[848]*work1d.d[368];
  work1d.v[637] = work1d.L[849]*work1d.d[637];
  work1d.v[638] = work1d.L[850]*work1d.d[638];
  work1d.v[777] = work1d.L[851]*work1d.d[777];
  work1d.v[778] = work1d.L[852]*work1d.d[778];
  work1d.v[873] = work1d.L[853]*work1d.d[873];
  work1d.v[874] = work1d.L[854]*work1d.d[874];
  work1d.v[875] = work1d.L[855]*work1d.d[875];
  work1d.v[876] = work1d.L[856]*work1d.d[876];
  work1d.v[877] = work1d.KKT[1771]-work1d.L[848]*work1d.v[368]-work1d.L[849]*work1d.v[637]-work1d.L[850]*work1d.v[638]-work1d.L[851]*work1d.v[777]-work1d.L[852]*work1d.v[778]-work1d.L[853]*work1d.v[873]-work1d.L[854]*work1d.v[874]-work1d.L[855]*work1d.v[875]-work1d.L[856]*work1d.v[876];
  work1d.d[877] = work1d.v[877];
  if (work1d.d[877] < 0)
    work1d.d[877] = settings1d.kkt_reg;
  else
    work1d.d[877] += settings1d.kkt_reg;
  work1d.d_inv[877] = 1/work1d.d[877];
  work1d.L[862] = (-work1d.L[859]*work1d.v[874]-work1d.L[860]*work1d.v[875]-work1d.L[861]*work1d.v[876])*work1d.d_inv[877];
  work1d.L[864] = (work1d.KKT[1772]-work1d.L[863]*work1d.v[876])*work1d.d_inv[877];
  work1d.L[875] = (-work1d.L[873]*work1d.v[778])*work1d.d_inv[877];
  work1d.v[819] = work1d.L[857]*work1d.d[819];
  work1d.v[820] = work1d.L[858]*work1d.d[820];
  work1d.v[874] = work1d.L[859]*work1d.d[874];
  work1d.v[875] = work1d.L[860]*work1d.d[875];
  work1d.v[876] = work1d.L[861]*work1d.d[876];
  work1d.v[877] = work1d.L[862]*work1d.d[877];
  work1d.v[878] = 0-work1d.L[857]*work1d.v[819]-work1d.L[858]*work1d.v[820]-work1d.L[859]*work1d.v[874]-work1d.L[860]*work1d.v[875]-work1d.L[861]*work1d.v[876]-work1d.L[862]*work1d.v[877];
  work1d.d[878] = work1d.v[878];
  if (work1d.d[878] > 0)
    work1d.d[878] = -settings1d.kkt_reg;
  else
    work1d.d[878] -= settings1d.kkt_reg;
  work1d.d_inv[878] = 1/work1d.d[878];
  work1d.L[865] = (-work1d.L[863]*work1d.v[876]-work1d.L[864]*work1d.v[877])*work1d.d_inv[878];
  work1d.L[876] = (-work1d.L[875]*work1d.v[877])*work1d.d_inv[878];
  work1d.L[881] = (-work1d.L[879]*work1d.v[820])*work1d.d_inv[878];
  work1d.v[876] = work1d.L[863]*work1d.d[876];
  work1d.v[877] = work1d.L[864]*work1d.d[877];
  work1d.v[878] = work1d.L[865]*work1d.d[878];
  work1d.v[879] = 0-work1d.L[863]*work1d.v[876]-work1d.L[864]*work1d.v[877]-work1d.L[865]*work1d.v[878];
  work1d.d[879] = work1d.v[879];
  if (work1d.d[879] > 0)
    work1d.d[879] = -settings1d.kkt_reg;
  else
    work1d.d[879] -= settings1d.kkt_reg;
  work1d.d_inv[879] = 1/work1d.d[879];
  work1d.L[869] = (work1d.KKT[1773])*work1d.d_inv[879];
  work1d.L[877] = (-work1d.L[875]*work1d.v[877]-work1d.L[876]*work1d.v[878])*work1d.d_inv[879];
  work1d.L[882] = (-work1d.L[881]*work1d.v[878])*work1d.d_inv[879];
  work1d.v[329] = work1d.L[866]*work1d.d[329];
  work1d.v[480] = work1d.L[867]*work1d.d[480];
  work1d.v[481] = work1d.L[868]*work1d.d[481];
  work1d.v[879] = work1d.L[869]*work1d.d[879];
  work1d.v[880] = work1d.KKT[1774]-work1d.L[866]*work1d.v[329]-work1d.L[867]*work1d.v[480]-work1d.L[868]*work1d.v[481]-work1d.L[869]*work1d.v[879];
  work1d.d[880] = work1d.v[880];
  if (work1d.d[880] < 0)
    work1d.d[880] = settings1d.kkt_reg;
  else
    work1d.d[880] += settings1d.kkt_reg;
  work1d.d_inv[880] = 1/work1d.d[880];
  work1d.L[878] = (-work1d.L[877]*work1d.v[879])*work1d.d_inv[880];
  work1d.L[883] = (work1d.KKT[1775]-work1d.L[882]*work1d.v[879])*work1d.d_inv[880];
  work1d.L[885] = (work1d.KKT[1776])*work1d.d_inv[880];
  work1d.v[369] = work1d.L[870]*work1d.d[369];
  work1d.v[641] = work1d.L[871]*work1d.d[641];
  work1d.v[642] = work1d.L[872]*work1d.d[642];
  work1d.v[778] = work1d.L[873]*work1d.d[778];
  work1d.v[779] = work1d.L[874]*work1d.d[779];
  work1d.v[877] = work1d.L[875]*work1d.d[877];
  work1d.v[878] = work1d.L[876]*work1d.d[878];
  work1d.v[879] = work1d.L[877]*work1d.d[879];
  work1d.v[880] = work1d.L[878]*work1d.d[880];
  work1d.v[881] = work1d.KKT[1777]-work1d.L[870]*work1d.v[369]-work1d.L[871]*work1d.v[641]-work1d.L[872]*work1d.v[642]-work1d.L[873]*work1d.v[778]-work1d.L[874]*work1d.v[779]-work1d.L[875]*work1d.v[877]-work1d.L[876]*work1d.v[878]-work1d.L[877]*work1d.v[879]-work1d.L[878]*work1d.v[880];
  work1d.d[881] = work1d.v[881];
  if (work1d.d[881] < 0)
    work1d.d[881] = settings1d.kkt_reg;
  else
    work1d.d[881] += settings1d.kkt_reg;
  work1d.d_inv[881] = 1/work1d.d[881];
  work1d.L[884] = (-work1d.L[881]*work1d.v[878]-work1d.L[882]*work1d.v[879]-work1d.L[883]*work1d.v[880])*work1d.d_inv[881];
  work1d.L[886] = (work1d.KKT[1778]-work1d.L[885]*work1d.v[880])*work1d.d_inv[881];
  work1d.L[897] = (-work1d.L[895]*work1d.v[779])*work1d.d_inv[881];
  work1d.v[820] = work1d.L[879]*work1d.d[820];
  work1d.v[821] = work1d.L[880]*work1d.d[821];
  work1d.v[878] = work1d.L[881]*work1d.d[878];
  work1d.v[879] = work1d.L[882]*work1d.d[879];
  work1d.v[880] = work1d.L[883]*work1d.d[880];
  work1d.v[881] = work1d.L[884]*work1d.d[881];
  work1d.v[882] = 0-work1d.L[879]*work1d.v[820]-work1d.L[880]*work1d.v[821]-work1d.L[881]*work1d.v[878]-work1d.L[882]*work1d.v[879]-work1d.L[883]*work1d.v[880]-work1d.L[884]*work1d.v[881];
  work1d.d[882] = work1d.v[882];
  if (work1d.d[882] > 0)
    work1d.d[882] = -settings1d.kkt_reg;
  else
    work1d.d[882] -= settings1d.kkt_reg;
  work1d.d_inv[882] = 1/work1d.d[882];
  work1d.L[887] = (-work1d.L[885]*work1d.v[880]-work1d.L[886]*work1d.v[881])*work1d.d_inv[882];
  work1d.L[898] = (-work1d.L[897]*work1d.v[881])*work1d.d_inv[882];
  work1d.L[903] = (-work1d.L[901]*work1d.v[821])*work1d.d_inv[882];
  work1d.v[880] = work1d.L[885]*work1d.d[880];
  work1d.v[881] = work1d.L[886]*work1d.d[881];
  work1d.v[882] = work1d.L[887]*work1d.d[882];
  work1d.v[883] = 0-work1d.L[885]*work1d.v[880]-work1d.L[886]*work1d.v[881]-work1d.L[887]*work1d.v[882];
  work1d.d[883] = work1d.v[883];
  if (work1d.d[883] > 0)
    work1d.d[883] = -settings1d.kkt_reg;
  else
    work1d.d[883] -= settings1d.kkt_reg;
  work1d.d_inv[883] = 1/work1d.d[883];
  work1d.L[891] = (work1d.KKT[1779])*work1d.d_inv[883];
  work1d.L[899] = (-work1d.L[897]*work1d.v[881]-work1d.L[898]*work1d.v[882])*work1d.d_inv[883];
  work1d.L[904] = (-work1d.L[903]*work1d.v[882])*work1d.d_inv[883];
  work1d.v[330] = work1d.L[888]*work1d.d[330];
  work1d.v[484] = work1d.L[889]*work1d.d[484];
  work1d.v[485] = work1d.L[890]*work1d.d[485];
  work1d.v[883] = work1d.L[891]*work1d.d[883];
  work1d.v[884] = work1d.KKT[1780]-work1d.L[888]*work1d.v[330]-work1d.L[889]*work1d.v[484]-work1d.L[890]*work1d.v[485]-work1d.L[891]*work1d.v[883];
  work1d.d[884] = work1d.v[884];
  if (work1d.d[884] < 0)
    work1d.d[884] = settings1d.kkt_reg;
  else
    work1d.d[884] += settings1d.kkt_reg;
  work1d.d_inv[884] = 1/work1d.d[884];
  work1d.L[900] = (-work1d.L[899]*work1d.v[883])*work1d.d_inv[884];
  work1d.L[905] = (work1d.KKT[1781]-work1d.L[904]*work1d.v[883])*work1d.d_inv[884];
  work1d.L[907] = (work1d.KKT[1782])*work1d.d_inv[884];
  work1d.v[370] = work1d.L[892]*work1d.d[370];
  work1d.v[645] = work1d.L[893]*work1d.d[645];
  work1d.v[646] = work1d.L[894]*work1d.d[646];
  work1d.v[779] = work1d.L[895]*work1d.d[779];
  work1d.v[780] = work1d.L[896]*work1d.d[780];
  work1d.v[881] = work1d.L[897]*work1d.d[881];
  work1d.v[882] = work1d.L[898]*work1d.d[882];
  work1d.v[883] = work1d.L[899]*work1d.d[883];
  work1d.v[884] = work1d.L[900]*work1d.d[884];
  work1d.v[885] = work1d.KKT[1783]-work1d.L[892]*work1d.v[370]-work1d.L[893]*work1d.v[645]-work1d.L[894]*work1d.v[646]-work1d.L[895]*work1d.v[779]-work1d.L[896]*work1d.v[780]-work1d.L[897]*work1d.v[881]-work1d.L[898]*work1d.v[882]-work1d.L[899]*work1d.v[883]-work1d.L[900]*work1d.v[884];
  work1d.d[885] = work1d.v[885];
  if (work1d.d[885] < 0)
    work1d.d[885] = settings1d.kkt_reg;
  else
    work1d.d[885] += settings1d.kkt_reg;
  work1d.d_inv[885] = 1/work1d.d[885];
  work1d.L[906] = (-work1d.L[903]*work1d.v[882]-work1d.L[904]*work1d.v[883]-work1d.L[905]*work1d.v[884])*work1d.d_inv[885];
  work1d.L[908] = (work1d.KKT[1784]-work1d.L[907]*work1d.v[884])*work1d.d_inv[885];
  work1d.L[919] = (-work1d.L[917]*work1d.v[780])*work1d.d_inv[885];
  work1d.v[821] = work1d.L[901]*work1d.d[821];
  work1d.v[822] = work1d.L[902]*work1d.d[822];
  work1d.v[882] = work1d.L[903]*work1d.d[882];
  work1d.v[883] = work1d.L[904]*work1d.d[883];
  work1d.v[884] = work1d.L[905]*work1d.d[884];
  work1d.v[885] = work1d.L[906]*work1d.d[885];
  work1d.v[886] = 0-work1d.L[901]*work1d.v[821]-work1d.L[902]*work1d.v[822]-work1d.L[903]*work1d.v[882]-work1d.L[904]*work1d.v[883]-work1d.L[905]*work1d.v[884]-work1d.L[906]*work1d.v[885];
  work1d.d[886] = work1d.v[886];
  if (work1d.d[886] > 0)
    work1d.d[886] = -settings1d.kkt_reg;
  else
    work1d.d[886] -= settings1d.kkt_reg;
  work1d.d_inv[886] = 1/work1d.d[886];
  work1d.L[909] = (-work1d.L[907]*work1d.v[884]-work1d.L[908]*work1d.v[885])*work1d.d_inv[886];
  work1d.L[920] = (-work1d.L[919]*work1d.v[885])*work1d.d_inv[886];
  work1d.L[925] = (-work1d.L[923]*work1d.v[822])*work1d.d_inv[886];
  work1d.v[884] = work1d.L[907]*work1d.d[884];
  work1d.v[885] = work1d.L[908]*work1d.d[885];
  work1d.v[886] = work1d.L[909]*work1d.d[886];
  work1d.v[887] = 0-work1d.L[907]*work1d.v[884]-work1d.L[908]*work1d.v[885]-work1d.L[909]*work1d.v[886];
  work1d.d[887] = work1d.v[887];
  if (work1d.d[887] > 0)
    work1d.d[887] = -settings1d.kkt_reg;
  else
    work1d.d[887] -= settings1d.kkt_reg;
  work1d.d_inv[887] = 1/work1d.d[887];
  work1d.L[913] = (work1d.KKT[1785])*work1d.d_inv[887];
  work1d.L[921] = (-work1d.L[919]*work1d.v[885]-work1d.L[920]*work1d.v[886])*work1d.d_inv[887];
  work1d.L[926] = (-work1d.L[925]*work1d.v[886])*work1d.d_inv[887];
  work1d.v[331] = work1d.L[910]*work1d.d[331];
  work1d.v[488] = work1d.L[911]*work1d.d[488];
  work1d.v[489] = work1d.L[912]*work1d.d[489];
  work1d.v[887] = work1d.L[913]*work1d.d[887];
  work1d.v[888] = work1d.KKT[1786]-work1d.L[910]*work1d.v[331]-work1d.L[911]*work1d.v[488]-work1d.L[912]*work1d.v[489]-work1d.L[913]*work1d.v[887];
  work1d.d[888] = work1d.v[888];
  if (work1d.d[888] < 0)
    work1d.d[888] = settings1d.kkt_reg;
  else
    work1d.d[888] += settings1d.kkt_reg;
  work1d.d_inv[888] = 1/work1d.d[888];
  work1d.L[922] = (-work1d.L[921]*work1d.v[887])*work1d.d_inv[888];
  work1d.L[927] = (work1d.KKT[1787]-work1d.L[926]*work1d.v[887])*work1d.d_inv[888];
  work1d.L[929] = (work1d.KKT[1788])*work1d.d_inv[888];
  work1d.v[371] = work1d.L[914]*work1d.d[371];
  work1d.v[649] = work1d.L[915]*work1d.d[649];
  work1d.v[650] = work1d.L[916]*work1d.d[650];
  work1d.v[780] = work1d.L[917]*work1d.d[780];
  work1d.v[781] = work1d.L[918]*work1d.d[781];
  work1d.v[885] = work1d.L[919]*work1d.d[885];
  work1d.v[886] = work1d.L[920]*work1d.d[886];
  work1d.v[887] = work1d.L[921]*work1d.d[887];
  work1d.v[888] = work1d.L[922]*work1d.d[888];
  work1d.v[889] = work1d.KKT[1789]-work1d.L[914]*work1d.v[371]-work1d.L[915]*work1d.v[649]-work1d.L[916]*work1d.v[650]-work1d.L[917]*work1d.v[780]-work1d.L[918]*work1d.v[781]-work1d.L[919]*work1d.v[885]-work1d.L[920]*work1d.v[886]-work1d.L[921]*work1d.v[887]-work1d.L[922]*work1d.v[888];
  work1d.d[889] = work1d.v[889];
  if (work1d.d[889] < 0)
    work1d.d[889] = settings1d.kkt_reg;
  else
    work1d.d[889] += settings1d.kkt_reg;
  work1d.d_inv[889] = 1/work1d.d[889];
  work1d.L[928] = (-work1d.L[925]*work1d.v[886]-work1d.L[926]*work1d.v[887]-work1d.L[927]*work1d.v[888])*work1d.d_inv[889];
  work1d.L[930] = (work1d.KKT[1790]-work1d.L[929]*work1d.v[888])*work1d.d_inv[889];
  work1d.L[941] = (-work1d.L[939]*work1d.v[781])*work1d.d_inv[889];
  work1d.v[822] = work1d.L[923]*work1d.d[822];
  work1d.v[823] = work1d.L[924]*work1d.d[823];
  work1d.v[886] = work1d.L[925]*work1d.d[886];
  work1d.v[887] = work1d.L[926]*work1d.d[887];
  work1d.v[888] = work1d.L[927]*work1d.d[888];
  work1d.v[889] = work1d.L[928]*work1d.d[889];
  work1d.v[890] = 0-work1d.L[923]*work1d.v[822]-work1d.L[924]*work1d.v[823]-work1d.L[925]*work1d.v[886]-work1d.L[926]*work1d.v[887]-work1d.L[927]*work1d.v[888]-work1d.L[928]*work1d.v[889];
  work1d.d[890] = work1d.v[890];
  if (work1d.d[890] > 0)
    work1d.d[890] = -settings1d.kkt_reg;
  else
    work1d.d[890] -= settings1d.kkt_reg;
  work1d.d_inv[890] = 1/work1d.d[890];
  work1d.L[931] = (-work1d.L[929]*work1d.v[888]-work1d.L[930]*work1d.v[889])*work1d.d_inv[890];
  work1d.L[942] = (-work1d.L[941]*work1d.v[889])*work1d.d_inv[890];
  work1d.L[947] = (-work1d.L[945]*work1d.v[823])*work1d.d_inv[890];
  work1d.v[888] = work1d.L[929]*work1d.d[888];
  work1d.v[889] = work1d.L[930]*work1d.d[889];
  work1d.v[890] = work1d.L[931]*work1d.d[890];
  work1d.v[891] = 0-work1d.L[929]*work1d.v[888]-work1d.L[930]*work1d.v[889]-work1d.L[931]*work1d.v[890];
  work1d.d[891] = work1d.v[891];
  if (work1d.d[891] > 0)
    work1d.d[891] = -settings1d.kkt_reg;
  else
    work1d.d[891] -= settings1d.kkt_reg;
  work1d.d_inv[891] = 1/work1d.d[891];
  work1d.L[935] = (work1d.KKT[1791])*work1d.d_inv[891];
  work1d.L[943] = (-work1d.L[941]*work1d.v[889]-work1d.L[942]*work1d.v[890])*work1d.d_inv[891];
  work1d.L[948] = (-work1d.L[947]*work1d.v[890])*work1d.d_inv[891];
  work1d.v[332] = work1d.L[932]*work1d.d[332];
  work1d.v[492] = work1d.L[933]*work1d.d[492];
  work1d.v[493] = work1d.L[934]*work1d.d[493];
  work1d.v[891] = work1d.L[935]*work1d.d[891];
  work1d.v[892] = work1d.KKT[1792]-work1d.L[932]*work1d.v[332]-work1d.L[933]*work1d.v[492]-work1d.L[934]*work1d.v[493]-work1d.L[935]*work1d.v[891];
  work1d.d[892] = work1d.v[892];
  if (work1d.d[892] < 0)
    work1d.d[892] = settings1d.kkt_reg;
  else
    work1d.d[892] += settings1d.kkt_reg;
  work1d.d_inv[892] = 1/work1d.d[892];
  work1d.L[944] = (-work1d.L[943]*work1d.v[891])*work1d.d_inv[892];
  work1d.L[949] = (work1d.KKT[1793]-work1d.L[948]*work1d.v[891])*work1d.d_inv[892];
  work1d.L[951] = (work1d.KKT[1794])*work1d.d_inv[892];
  work1d.v[372] = work1d.L[936]*work1d.d[372];
  work1d.v[653] = work1d.L[937]*work1d.d[653];
  work1d.v[654] = work1d.L[938]*work1d.d[654];
  work1d.v[781] = work1d.L[939]*work1d.d[781];
  work1d.v[782] = work1d.L[940]*work1d.d[782];
  work1d.v[889] = work1d.L[941]*work1d.d[889];
  work1d.v[890] = work1d.L[942]*work1d.d[890];
  work1d.v[891] = work1d.L[943]*work1d.d[891];
  work1d.v[892] = work1d.L[944]*work1d.d[892];
  work1d.v[893] = work1d.KKT[1795]-work1d.L[936]*work1d.v[372]-work1d.L[937]*work1d.v[653]-work1d.L[938]*work1d.v[654]-work1d.L[939]*work1d.v[781]-work1d.L[940]*work1d.v[782]-work1d.L[941]*work1d.v[889]-work1d.L[942]*work1d.v[890]-work1d.L[943]*work1d.v[891]-work1d.L[944]*work1d.v[892];
  work1d.d[893] = work1d.v[893];
  if (work1d.d[893] < 0)
    work1d.d[893] = settings1d.kkt_reg;
  else
    work1d.d[893] += settings1d.kkt_reg;
  work1d.d_inv[893] = 1/work1d.d[893];
  work1d.L[950] = (-work1d.L[947]*work1d.v[890]-work1d.L[948]*work1d.v[891]-work1d.L[949]*work1d.v[892])*work1d.d_inv[893];
  work1d.L[952] = (work1d.KKT[1796]-work1d.L[951]*work1d.v[892])*work1d.d_inv[893];
  work1d.L[963] = (-work1d.L[961]*work1d.v[782])*work1d.d_inv[893];
  work1d.v[823] = work1d.L[945]*work1d.d[823];
  work1d.v[824] = work1d.L[946]*work1d.d[824];
  work1d.v[890] = work1d.L[947]*work1d.d[890];
  work1d.v[891] = work1d.L[948]*work1d.d[891];
  work1d.v[892] = work1d.L[949]*work1d.d[892];
  work1d.v[893] = work1d.L[950]*work1d.d[893];
  work1d.v[894] = 0-work1d.L[945]*work1d.v[823]-work1d.L[946]*work1d.v[824]-work1d.L[947]*work1d.v[890]-work1d.L[948]*work1d.v[891]-work1d.L[949]*work1d.v[892]-work1d.L[950]*work1d.v[893];
  work1d.d[894] = work1d.v[894];
  if (work1d.d[894] > 0)
    work1d.d[894] = -settings1d.kkt_reg;
  else
    work1d.d[894] -= settings1d.kkt_reg;
  work1d.d_inv[894] = 1/work1d.d[894];
  work1d.L[953] = (-work1d.L[951]*work1d.v[892]-work1d.L[952]*work1d.v[893])*work1d.d_inv[894];
  work1d.L[964] = (-work1d.L[963]*work1d.v[893])*work1d.d_inv[894];
  work1d.L[969] = (-work1d.L[967]*work1d.v[824])*work1d.d_inv[894];
  work1d.v[892] = work1d.L[951]*work1d.d[892];
  work1d.v[893] = work1d.L[952]*work1d.d[893];
  work1d.v[894] = work1d.L[953]*work1d.d[894];
  work1d.v[895] = 0-work1d.L[951]*work1d.v[892]-work1d.L[952]*work1d.v[893]-work1d.L[953]*work1d.v[894];
  work1d.d[895] = work1d.v[895];
  if (work1d.d[895] > 0)
    work1d.d[895] = -settings1d.kkt_reg;
  else
    work1d.d[895] -= settings1d.kkt_reg;
  work1d.d_inv[895] = 1/work1d.d[895];
  work1d.L[957] = (work1d.KKT[1797])*work1d.d_inv[895];
  work1d.L[965] = (-work1d.L[963]*work1d.v[893]-work1d.L[964]*work1d.v[894])*work1d.d_inv[895];
  work1d.L[970] = (-work1d.L[969]*work1d.v[894])*work1d.d_inv[895];
  work1d.v[333] = work1d.L[954]*work1d.d[333];
  work1d.v[496] = work1d.L[955]*work1d.d[496];
  work1d.v[497] = work1d.L[956]*work1d.d[497];
  work1d.v[895] = work1d.L[957]*work1d.d[895];
  work1d.v[896] = work1d.KKT[1798]-work1d.L[954]*work1d.v[333]-work1d.L[955]*work1d.v[496]-work1d.L[956]*work1d.v[497]-work1d.L[957]*work1d.v[895];
  work1d.d[896] = work1d.v[896];
  if (work1d.d[896] < 0)
    work1d.d[896] = settings1d.kkt_reg;
  else
    work1d.d[896] += settings1d.kkt_reg;
  work1d.d_inv[896] = 1/work1d.d[896];
  work1d.L[966] = (-work1d.L[965]*work1d.v[895])*work1d.d_inv[896];
  work1d.L[971] = (work1d.KKT[1799]-work1d.L[970]*work1d.v[895])*work1d.d_inv[896];
  work1d.L[973] = (work1d.KKT[1800])*work1d.d_inv[896];
  work1d.v[373] = work1d.L[958]*work1d.d[373];
  work1d.v[657] = work1d.L[959]*work1d.d[657];
  work1d.v[658] = work1d.L[960]*work1d.d[658];
  work1d.v[782] = work1d.L[961]*work1d.d[782];
  work1d.v[783] = work1d.L[962]*work1d.d[783];
  work1d.v[893] = work1d.L[963]*work1d.d[893];
  work1d.v[894] = work1d.L[964]*work1d.d[894];
  work1d.v[895] = work1d.L[965]*work1d.d[895];
  work1d.v[896] = work1d.L[966]*work1d.d[896];
  work1d.v[897] = work1d.KKT[1801]-work1d.L[958]*work1d.v[373]-work1d.L[959]*work1d.v[657]-work1d.L[960]*work1d.v[658]-work1d.L[961]*work1d.v[782]-work1d.L[962]*work1d.v[783]-work1d.L[963]*work1d.v[893]-work1d.L[964]*work1d.v[894]-work1d.L[965]*work1d.v[895]-work1d.L[966]*work1d.v[896];
  work1d.d[897] = work1d.v[897];
  if (work1d.d[897] < 0)
    work1d.d[897] = settings1d.kkt_reg;
  else
    work1d.d[897] += settings1d.kkt_reg;
  work1d.d_inv[897] = 1/work1d.d[897];
  work1d.L[972] = (-work1d.L[969]*work1d.v[894]-work1d.L[970]*work1d.v[895]-work1d.L[971]*work1d.v[896])*work1d.d_inv[897];
  work1d.L[974] = (work1d.KKT[1802]-work1d.L[973]*work1d.v[896])*work1d.d_inv[897];
  work1d.L[985] = (-work1d.L[983]*work1d.v[783])*work1d.d_inv[897];
  work1d.v[824] = work1d.L[967]*work1d.d[824];
  work1d.v[825] = work1d.L[968]*work1d.d[825];
  work1d.v[894] = work1d.L[969]*work1d.d[894];
  work1d.v[895] = work1d.L[970]*work1d.d[895];
  work1d.v[896] = work1d.L[971]*work1d.d[896];
  work1d.v[897] = work1d.L[972]*work1d.d[897];
  work1d.v[898] = 0-work1d.L[967]*work1d.v[824]-work1d.L[968]*work1d.v[825]-work1d.L[969]*work1d.v[894]-work1d.L[970]*work1d.v[895]-work1d.L[971]*work1d.v[896]-work1d.L[972]*work1d.v[897];
  work1d.d[898] = work1d.v[898];
  if (work1d.d[898] > 0)
    work1d.d[898] = -settings1d.kkt_reg;
  else
    work1d.d[898] -= settings1d.kkt_reg;
  work1d.d_inv[898] = 1/work1d.d[898];
  work1d.L[975] = (-work1d.L[973]*work1d.v[896]-work1d.L[974]*work1d.v[897])*work1d.d_inv[898];
  work1d.L[986] = (-work1d.L[985]*work1d.v[897])*work1d.d_inv[898];
  work1d.L[991] = (-work1d.L[989]*work1d.v[825])*work1d.d_inv[898];
  work1d.v[896] = work1d.L[973]*work1d.d[896];
  work1d.v[897] = work1d.L[974]*work1d.d[897];
  work1d.v[898] = work1d.L[975]*work1d.d[898];
  work1d.v[899] = 0-work1d.L[973]*work1d.v[896]-work1d.L[974]*work1d.v[897]-work1d.L[975]*work1d.v[898];
  work1d.d[899] = work1d.v[899];
  if (work1d.d[899] > 0)
    work1d.d[899] = -settings1d.kkt_reg;
  else
    work1d.d[899] -= settings1d.kkt_reg;
  work1d.d_inv[899] = 1/work1d.d[899];
  work1d.L[979] = (work1d.KKT[1803])*work1d.d_inv[899];
  work1d.L[987] = (-work1d.L[985]*work1d.v[897]-work1d.L[986]*work1d.v[898])*work1d.d_inv[899];
  work1d.L[992] = (-work1d.L[991]*work1d.v[898])*work1d.d_inv[899];
  work1d.v[334] = work1d.L[976]*work1d.d[334];
  work1d.v[500] = work1d.L[977]*work1d.d[500];
  work1d.v[501] = work1d.L[978]*work1d.d[501];
  work1d.v[899] = work1d.L[979]*work1d.d[899];
  work1d.v[900] = work1d.KKT[1804]-work1d.L[976]*work1d.v[334]-work1d.L[977]*work1d.v[500]-work1d.L[978]*work1d.v[501]-work1d.L[979]*work1d.v[899];
  work1d.d[900] = work1d.v[900];
  if (work1d.d[900] < 0)
    work1d.d[900] = settings1d.kkt_reg;
  else
    work1d.d[900] += settings1d.kkt_reg;
  work1d.d_inv[900] = 1/work1d.d[900];
  work1d.L[988] = (-work1d.L[987]*work1d.v[899])*work1d.d_inv[900];
  work1d.L[993] = (work1d.KKT[1805]-work1d.L[992]*work1d.v[899])*work1d.d_inv[900];
  work1d.L[995] = (work1d.KKT[1806])*work1d.d_inv[900];
  work1d.v[374] = work1d.L[980]*work1d.d[374];
  work1d.v[661] = work1d.L[981]*work1d.d[661];
  work1d.v[662] = work1d.L[982]*work1d.d[662];
  work1d.v[783] = work1d.L[983]*work1d.d[783];
  work1d.v[784] = work1d.L[984]*work1d.d[784];
  work1d.v[897] = work1d.L[985]*work1d.d[897];
  work1d.v[898] = work1d.L[986]*work1d.d[898];
  work1d.v[899] = work1d.L[987]*work1d.d[899];
  work1d.v[900] = work1d.L[988]*work1d.d[900];
  work1d.v[901] = work1d.KKT[1807]-work1d.L[980]*work1d.v[374]-work1d.L[981]*work1d.v[661]-work1d.L[982]*work1d.v[662]-work1d.L[983]*work1d.v[783]-work1d.L[984]*work1d.v[784]-work1d.L[985]*work1d.v[897]-work1d.L[986]*work1d.v[898]-work1d.L[987]*work1d.v[899]-work1d.L[988]*work1d.v[900];
  work1d.d[901] = work1d.v[901];
  if (work1d.d[901] < 0)
    work1d.d[901] = settings1d.kkt_reg;
  else
    work1d.d[901] += settings1d.kkt_reg;
  work1d.d_inv[901] = 1/work1d.d[901];
  work1d.L[994] = (-work1d.L[991]*work1d.v[898]-work1d.L[992]*work1d.v[899]-work1d.L[993]*work1d.v[900])*work1d.d_inv[901];
  work1d.L[996] = (work1d.KKT[1808]-work1d.L[995]*work1d.v[900])*work1d.d_inv[901];
  work1d.L[1007] = (-work1d.L[1005]*work1d.v[784])*work1d.d_inv[901];
  work1d.v[825] = work1d.L[989]*work1d.d[825];
  work1d.v[826] = work1d.L[990]*work1d.d[826];
  work1d.v[898] = work1d.L[991]*work1d.d[898];
  work1d.v[899] = work1d.L[992]*work1d.d[899];
  work1d.v[900] = work1d.L[993]*work1d.d[900];
  work1d.v[901] = work1d.L[994]*work1d.d[901];
  work1d.v[902] = 0-work1d.L[989]*work1d.v[825]-work1d.L[990]*work1d.v[826]-work1d.L[991]*work1d.v[898]-work1d.L[992]*work1d.v[899]-work1d.L[993]*work1d.v[900]-work1d.L[994]*work1d.v[901];
  work1d.d[902] = work1d.v[902];
  if (work1d.d[902] > 0)
    work1d.d[902] = -settings1d.kkt_reg;
  else
    work1d.d[902] -= settings1d.kkt_reg;
  work1d.d_inv[902] = 1/work1d.d[902];
  work1d.L[997] = (-work1d.L[995]*work1d.v[900]-work1d.L[996]*work1d.v[901])*work1d.d_inv[902];
  work1d.L[1008] = (-work1d.L[1007]*work1d.v[901])*work1d.d_inv[902];
  work1d.L[1013] = (-work1d.L[1011]*work1d.v[826])*work1d.d_inv[902];
  work1d.v[900] = work1d.L[995]*work1d.d[900];
  work1d.v[901] = work1d.L[996]*work1d.d[901];
  work1d.v[902] = work1d.L[997]*work1d.d[902];
  work1d.v[903] = 0-work1d.L[995]*work1d.v[900]-work1d.L[996]*work1d.v[901]-work1d.L[997]*work1d.v[902];
  work1d.d[903] = work1d.v[903];
  if (work1d.d[903] > 0)
    work1d.d[903] = -settings1d.kkt_reg;
  else
    work1d.d[903] -= settings1d.kkt_reg;
  work1d.d_inv[903] = 1/work1d.d[903];
  work1d.L[1001] = (work1d.KKT[1809])*work1d.d_inv[903];
  work1d.L[1009] = (-work1d.L[1007]*work1d.v[901]-work1d.L[1008]*work1d.v[902])*work1d.d_inv[903];
  work1d.L[1014] = (-work1d.L[1013]*work1d.v[902])*work1d.d_inv[903];
  work1d.v[335] = work1d.L[998]*work1d.d[335];
  work1d.v[504] = work1d.L[999]*work1d.d[504];
  work1d.v[505] = work1d.L[1000]*work1d.d[505];
  work1d.v[903] = work1d.L[1001]*work1d.d[903];
  work1d.v[904] = work1d.KKT[1810]-work1d.L[998]*work1d.v[335]-work1d.L[999]*work1d.v[504]-work1d.L[1000]*work1d.v[505]-work1d.L[1001]*work1d.v[903];
  work1d.d[904] = work1d.v[904];
  if (work1d.d[904] < 0)
    work1d.d[904] = settings1d.kkt_reg;
  else
    work1d.d[904] += settings1d.kkt_reg;
  work1d.d_inv[904] = 1/work1d.d[904];
  work1d.L[1010] = (-work1d.L[1009]*work1d.v[903])*work1d.d_inv[904];
  work1d.L[1015] = (work1d.KKT[1811]-work1d.L[1014]*work1d.v[903])*work1d.d_inv[904];
  work1d.L[1017] = (work1d.KKT[1812])*work1d.d_inv[904];
  work1d.v[375] = work1d.L[1002]*work1d.d[375];
  work1d.v[665] = work1d.L[1003]*work1d.d[665];
  work1d.v[666] = work1d.L[1004]*work1d.d[666];
  work1d.v[784] = work1d.L[1005]*work1d.d[784];
  work1d.v[785] = work1d.L[1006]*work1d.d[785];
  work1d.v[901] = work1d.L[1007]*work1d.d[901];
  work1d.v[902] = work1d.L[1008]*work1d.d[902];
  work1d.v[903] = work1d.L[1009]*work1d.d[903];
  work1d.v[904] = work1d.L[1010]*work1d.d[904];
  work1d.v[905] = work1d.KKT[1813]-work1d.L[1002]*work1d.v[375]-work1d.L[1003]*work1d.v[665]-work1d.L[1004]*work1d.v[666]-work1d.L[1005]*work1d.v[784]-work1d.L[1006]*work1d.v[785]-work1d.L[1007]*work1d.v[901]-work1d.L[1008]*work1d.v[902]-work1d.L[1009]*work1d.v[903]-work1d.L[1010]*work1d.v[904];
  work1d.d[905] = work1d.v[905];
  if (work1d.d[905] < 0)
    work1d.d[905] = settings1d.kkt_reg;
  else
    work1d.d[905] += settings1d.kkt_reg;
  work1d.d_inv[905] = 1/work1d.d[905];
  work1d.L[1016] = (-work1d.L[1013]*work1d.v[902]-work1d.L[1014]*work1d.v[903]-work1d.L[1015]*work1d.v[904])*work1d.d_inv[905];
  work1d.L[1018] = (work1d.KKT[1814]-work1d.L[1017]*work1d.v[904])*work1d.d_inv[905];
  work1d.L[1029] = (-work1d.L[1027]*work1d.v[785])*work1d.d_inv[905];
  work1d.v[826] = work1d.L[1011]*work1d.d[826];
  work1d.v[827] = work1d.L[1012]*work1d.d[827];
  work1d.v[902] = work1d.L[1013]*work1d.d[902];
  work1d.v[903] = work1d.L[1014]*work1d.d[903];
  work1d.v[904] = work1d.L[1015]*work1d.d[904];
  work1d.v[905] = work1d.L[1016]*work1d.d[905];
  work1d.v[906] = 0-work1d.L[1011]*work1d.v[826]-work1d.L[1012]*work1d.v[827]-work1d.L[1013]*work1d.v[902]-work1d.L[1014]*work1d.v[903]-work1d.L[1015]*work1d.v[904]-work1d.L[1016]*work1d.v[905];
  work1d.d[906] = work1d.v[906];
  if (work1d.d[906] > 0)
    work1d.d[906] = -settings1d.kkt_reg;
  else
    work1d.d[906] -= settings1d.kkt_reg;
  work1d.d_inv[906] = 1/work1d.d[906];
  work1d.L[1019] = (-work1d.L[1017]*work1d.v[904]-work1d.L[1018]*work1d.v[905])*work1d.d_inv[906];
  work1d.L[1030] = (-work1d.L[1029]*work1d.v[905])*work1d.d_inv[906];
  work1d.L[1035] = (-work1d.L[1033]*work1d.v[827])*work1d.d_inv[906];
  work1d.v[904] = work1d.L[1017]*work1d.d[904];
  work1d.v[905] = work1d.L[1018]*work1d.d[905];
  work1d.v[906] = work1d.L[1019]*work1d.d[906];
  work1d.v[907] = 0-work1d.L[1017]*work1d.v[904]-work1d.L[1018]*work1d.v[905]-work1d.L[1019]*work1d.v[906];
  work1d.d[907] = work1d.v[907];
  if (work1d.d[907] > 0)
    work1d.d[907] = -settings1d.kkt_reg;
  else
    work1d.d[907] -= settings1d.kkt_reg;
  work1d.d_inv[907] = 1/work1d.d[907];
  work1d.L[1023] = (work1d.KKT[1815])*work1d.d_inv[907];
  work1d.L[1031] = (-work1d.L[1029]*work1d.v[905]-work1d.L[1030]*work1d.v[906])*work1d.d_inv[907];
  work1d.L[1036] = (-work1d.L[1035]*work1d.v[906])*work1d.d_inv[907];
  work1d.v[336] = work1d.L[1020]*work1d.d[336];
  work1d.v[508] = work1d.L[1021]*work1d.d[508];
  work1d.v[509] = work1d.L[1022]*work1d.d[509];
  work1d.v[907] = work1d.L[1023]*work1d.d[907];
  work1d.v[908] = work1d.KKT[1816]-work1d.L[1020]*work1d.v[336]-work1d.L[1021]*work1d.v[508]-work1d.L[1022]*work1d.v[509]-work1d.L[1023]*work1d.v[907];
  work1d.d[908] = work1d.v[908];
  if (work1d.d[908] < 0)
    work1d.d[908] = settings1d.kkt_reg;
  else
    work1d.d[908] += settings1d.kkt_reg;
  work1d.d_inv[908] = 1/work1d.d[908];
  work1d.L[1032] = (-work1d.L[1031]*work1d.v[907])*work1d.d_inv[908];
  work1d.L[1037] = (work1d.KKT[1817]-work1d.L[1036]*work1d.v[907])*work1d.d_inv[908];
  work1d.L[1039] = (work1d.KKT[1818])*work1d.d_inv[908];
  work1d.v[376] = work1d.L[1024]*work1d.d[376];
  work1d.v[669] = work1d.L[1025]*work1d.d[669];
  work1d.v[670] = work1d.L[1026]*work1d.d[670];
  work1d.v[785] = work1d.L[1027]*work1d.d[785];
  work1d.v[786] = work1d.L[1028]*work1d.d[786];
  work1d.v[905] = work1d.L[1029]*work1d.d[905];
  work1d.v[906] = work1d.L[1030]*work1d.d[906];
  work1d.v[907] = work1d.L[1031]*work1d.d[907];
  work1d.v[908] = work1d.L[1032]*work1d.d[908];
  work1d.v[909] = work1d.KKT[1819]-work1d.L[1024]*work1d.v[376]-work1d.L[1025]*work1d.v[669]-work1d.L[1026]*work1d.v[670]-work1d.L[1027]*work1d.v[785]-work1d.L[1028]*work1d.v[786]-work1d.L[1029]*work1d.v[905]-work1d.L[1030]*work1d.v[906]-work1d.L[1031]*work1d.v[907]-work1d.L[1032]*work1d.v[908];
  work1d.d[909] = work1d.v[909];
  if (work1d.d[909] < 0)
    work1d.d[909] = settings1d.kkt_reg;
  else
    work1d.d[909] += settings1d.kkt_reg;
  work1d.d_inv[909] = 1/work1d.d[909];
  work1d.L[1038] = (-work1d.L[1035]*work1d.v[906]-work1d.L[1036]*work1d.v[907]-work1d.L[1037]*work1d.v[908])*work1d.d_inv[909];
  work1d.L[1040] = (work1d.KKT[1820]-work1d.L[1039]*work1d.v[908])*work1d.d_inv[909];
  work1d.L[1051] = (-work1d.L[1049]*work1d.v[786])*work1d.d_inv[909];
  work1d.v[827] = work1d.L[1033]*work1d.d[827];
  work1d.v[828] = work1d.L[1034]*work1d.d[828];
  work1d.v[906] = work1d.L[1035]*work1d.d[906];
  work1d.v[907] = work1d.L[1036]*work1d.d[907];
  work1d.v[908] = work1d.L[1037]*work1d.d[908];
  work1d.v[909] = work1d.L[1038]*work1d.d[909];
  work1d.v[910] = 0-work1d.L[1033]*work1d.v[827]-work1d.L[1034]*work1d.v[828]-work1d.L[1035]*work1d.v[906]-work1d.L[1036]*work1d.v[907]-work1d.L[1037]*work1d.v[908]-work1d.L[1038]*work1d.v[909];
  work1d.d[910] = work1d.v[910];
  if (work1d.d[910] > 0)
    work1d.d[910] = -settings1d.kkt_reg;
  else
    work1d.d[910] -= settings1d.kkt_reg;
  work1d.d_inv[910] = 1/work1d.d[910];
  work1d.L[1041] = (-work1d.L[1039]*work1d.v[908]-work1d.L[1040]*work1d.v[909])*work1d.d_inv[910];
  work1d.L[1052] = (-work1d.L[1051]*work1d.v[909])*work1d.d_inv[910];
  work1d.L[1057] = (-work1d.L[1055]*work1d.v[828])*work1d.d_inv[910];
  work1d.v[908] = work1d.L[1039]*work1d.d[908];
  work1d.v[909] = work1d.L[1040]*work1d.d[909];
  work1d.v[910] = work1d.L[1041]*work1d.d[910];
  work1d.v[911] = 0-work1d.L[1039]*work1d.v[908]-work1d.L[1040]*work1d.v[909]-work1d.L[1041]*work1d.v[910];
  work1d.d[911] = work1d.v[911];
  if (work1d.d[911] > 0)
    work1d.d[911] = -settings1d.kkt_reg;
  else
    work1d.d[911] -= settings1d.kkt_reg;
  work1d.d_inv[911] = 1/work1d.d[911];
  work1d.L[1045] = (work1d.KKT[1821])*work1d.d_inv[911];
  work1d.L[1053] = (-work1d.L[1051]*work1d.v[909]-work1d.L[1052]*work1d.v[910])*work1d.d_inv[911];
  work1d.L[1058] = (-work1d.L[1057]*work1d.v[910])*work1d.d_inv[911];
  work1d.v[337] = work1d.L[1042]*work1d.d[337];
  work1d.v[512] = work1d.L[1043]*work1d.d[512];
  work1d.v[513] = work1d.L[1044]*work1d.d[513];
  work1d.v[911] = work1d.L[1045]*work1d.d[911];
  work1d.v[912] = work1d.KKT[1822]-work1d.L[1042]*work1d.v[337]-work1d.L[1043]*work1d.v[512]-work1d.L[1044]*work1d.v[513]-work1d.L[1045]*work1d.v[911];
  work1d.d[912] = work1d.v[912];
  if (work1d.d[912] < 0)
    work1d.d[912] = settings1d.kkt_reg;
  else
    work1d.d[912] += settings1d.kkt_reg;
  work1d.d_inv[912] = 1/work1d.d[912];
  work1d.L[1054] = (-work1d.L[1053]*work1d.v[911])*work1d.d_inv[912];
  work1d.L[1059] = (work1d.KKT[1823]-work1d.L[1058]*work1d.v[911])*work1d.d_inv[912];
  work1d.L[1061] = (work1d.KKT[1824])*work1d.d_inv[912];
  work1d.v[377] = work1d.L[1046]*work1d.d[377];
  work1d.v[673] = work1d.L[1047]*work1d.d[673];
  work1d.v[674] = work1d.L[1048]*work1d.d[674];
  work1d.v[786] = work1d.L[1049]*work1d.d[786];
  work1d.v[787] = work1d.L[1050]*work1d.d[787];
  work1d.v[909] = work1d.L[1051]*work1d.d[909];
  work1d.v[910] = work1d.L[1052]*work1d.d[910];
  work1d.v[911] = work1d.L[1053]*work1d.d[911];
  work1d.v[912] = work1d.L[1054]*work1d.d[912];
  work1d.v[913] = work1d.KKT[1825]-work1d.L[1046]*work1d.v[377]-work1d.L[1047]*work1d.v[673]-work1d.L[1048]*work1d.v[674]-work1d.L[1049]*work1d.v[786]-work1d.L[1050]*work1d.v[787]-work1d.L[1051]*work1d.v[909]-work1d.L[1052]*work1d.v[910]-work1d.L[1053]*work1d.v[911]-work1d.L[1054]*work1d.v[912];
  work1d.d[913] = work1d.v[913];
  if (work1d.d[913] < 0)
    work1d.d[913] = settings1d.kkt_reg;
  else
    work1d.d[913] += settings1d.kkt_reg;
  work1d.d_inv[913] = 1/work1d.d[913];
  work1d.L[1060] = (-work1d.L[1057]*work1d.v[910]-work1d.L[1058]*work1d.v[911]-work1d.L[1059]*work1d.v[912])*work1d.d_inv[913];
  work1d.L[1062] = (work1d.KKT[1826]-work1d.L[1061]*work1d.v[912])*work1d.d_inv[913];
  work1d.L[1073] = (-work1d.L[1071]*work1d.v[787])*work1d.d_inv[913];
  work1d.v[828] = work1d.L[1055]*work1d.d[828];
  work1d.v[829] = work1d.L[1056]*work1d.d[829];
  work1d.v[910] = work1d.L[1057]*work1d.d[910];
  work1d.v[911] = work1d.L[1058]*work1d.d[911];
  work1d.v[912] = work1d.L[1059]*work1d.d[912];
  work1d.v[913] = work1d.L[1060]*work1d.d[913];
  work1d.v[914] = 0-work1d.L[1055]*work1d.v[828]-work1d.L[1056]*work1d.v[829]-work1d.L[1057]*work1d.v[910]-work1d.L[1058]*work1d.v[911]-work1d.L[1059]*work1d.v[912]-work1d.L[1060]*work1d.v[913];
  work1d.d[914] = work1d.v[914];
  if (work1d.d[914] > 0)
    work1d.d[914] = -settings1d.kkt_reg;
  else
    work1d.d[914] -= settings1d.kkt_reg;
  work1d.d_inv[914] = 1/work1d.d[914];
  work1d.L[1063] = (-work1d.L[1061]*work1d.v[912]-work1d.L[1062]*work1d.v[913])*work1d.d_inv[914];
  work1d.L[1074] = (-work1d.L[1073]*work1d.v[913])*work1d.d_inv[914];
  work1d.L[1079] = (-work1d.L[1077]*work1d.v[829])*work1d.d_inv[914];
  work1d.v[912] = work1d.L[1061]*work1d.d[912];
  work1d.v[913] = work1d.L[1062]*work1d.d[913];
  work1d.v[914] = work1d.L[1063]*work1d.d[914];
  work1d.v[915] = 0-work1d.L[1061]*work1d.v[912]-work1d.L[1062]*work1d.v[913]-work1d.L[1063]*work1d.v[914];
  work1d.d[915] = work1d.v[915];
  if (work1d.d[915] > 0)
    work1d.d[915] = -settings1d.kkt_reg;
  else
    work1d.d[915] -= settings1d.kkt_reg;
  work1d.d_inv[915] = 1/work1d.d[915];
  work1d.L[1067] = (work1d.KKT[1827])*work1d.d_inv[915];
  work1d.L[1075] = (-work1d.L[1073]*work1d.v[913]-work1d.L[1074]*work1d.v[914])*work1d.d_inv[915];
  work1d.L[1080] = (-work1d.L[1079]*work1d.v[914])*work1d.d_inv[915];
  work1d.v[338] = work1d.L[1064]*work1d.d[338];
  work1d.v[516] = work1d.L[1065]*work1d.d[516];
  work1d.v[517] = work1d.L[1066]*work1d.d[517];
  work1d.v[915] = work1d.L[1067]*work1d.d[915];
  work1d.v[916] = work1d.KKT[1828]-work1d.L[1064]*work1d.v[338]-work1d.L[1065]*work1d.v[516]-work1d.L[1066]*work1d.v[517]-work1d.L[1067]*work1d.v[915];
  work1d.d[916] = work1d.v[916];
  if (work1d.d[916] < 0)
    work1d.d[916] = settings1d.kkt_reg;
  else
    work1d.d[916] += settings1d.kkt_reg;
  work1d.d_inv[916] = 1/work1d.d[916];
  work1d.L[1076] = (-work1d.L[1075]*work1d.v[915])*work1d.d_inv[916];
  work1d.L[1081] = (work1d.KKT[1829]-work1d.L[1080]*work1d.v[915])*work1d.d_inv[916];
  work1d.L[1083] = (work1d.KKT[1830])*work1d.d_inv[916];
  work1d.v[378] = work1d.L[1068]*work1d.d[378];
  work1d.v[677] = work1d.L[1069]*work1d.d[677];
  work1d.v[678] = work1d.L[1070]*work1d.d[678];
  work1d.v[787] = work1d.L[1071]*work1d.d[787];
  work1d.v[788] = work1d.L[1072]*work1d.d[788];
  work1d.v[913] = work1d.L[1073]*work1d.d[913];
  work1d.v[914] = work1d.L[1074]*work1d.d[914];
  work1d.v[915] = work1d.L[1075]*work1d.d[915];
  work1d.v[916] = work1d.L[1076]*work1d.d[916];
  work1d.v[917] = work1d.KKT[1831]-work1d.L[1068]*work1d.v[378]-work1d.L[1069]*work1d.v[677]-work1d.L[1070]*work1d.v[678]-work1d.L[1071]*work1d.v[787]-work1d.L[1072]*work1d.v[788]-work1d.L[1073]*work1d.v[913]-work1d.L[1074]*work1d.v[914]-work1d.L[1075]*work1d.v[915]-work1d.L[1076]*work1d.v[916];
  work1d.d[917] = work1d.v[917];
  if (work1d.d[917] < 0)
    work1d.d[917] = settings1d.kkt_reg;
  else
    work1d.d[917] += settings1d.kkt_reg;
  work1d.d_inv[917] = 1/work1d.d[917];
  work1d.L[1082] = (-work1d.L[1079]*work1d.v[914]-work1d.L[1080]*work1d.v[915]-work1d.L[1081]*work1d.v[916])*work1d.d_inv[917];
  work1d.L[1084] = (work1d.KKT[1832]-work1d.L[1083]*work1d.v[916])*work1d.d_inv[917];
  work1d.L[1095] = (-work1d.L[1093]*work1d.v[788])*work1d.d_inv[917];
  work1d.v[829] = work1d.L[1077]*work1d.d[829];
  work1d.v[830] = work1d.L[1078]*work1d.d[830];
  work1d.v[914] = work1d.L[1079]*work1d.d[914];
  work1d.v[915] = work1d.L[1080]*work1d.d[915];
  work1d.v[916] = work1d.L[1081]*work1d.d[916];
  work1d.v[917] = work1d.L[1082]*work1d.d[917];
  work1d.v[918] = 0-work1d.L[1077]*work1d.v[829]-work1d.L[1078]*work1d.v[830]-work1d.L[1079]*work1d.v[914]-work1d.L[1080]*work1d.v[915]-work1d.L[1081]*work1d.v[916]-work1d.L[1082]*work1d.v[917];
  work1d.d[918] = work1d.v[918];
  if (work1d.d[918] > 0)
    work1d.d[918] = -settings1d.kkt_reg;
  else
    work1d.d[918] -= settings1d.kkt_reg;
  work1d.d_inv[918] = 1/work1d.d[918];
  work1d.L[1085] = (-work1d.L[1083]*work1d.v[916]-work1d.L[1084]*work1d.v[917])*work1d.d_inv[918];
  work1d.L[1096] = (-work1d.L[1095]*work1d.v[917])*work1d.d_inv[918];
  work1d.L[1101] = (-work1d.L[1099]*work1d.v[830])*work1d.d_inv[918];
  work1d.v[916] = work1d.L[1083]*work1d.d[916];
  work1d.v[917] = work1d.L[1084]*work1d.d[917];
  work1d.v[918] = work1d.L[1085]*work1d.d[918];
  work1d.v[919] = 0-work1d.L[1083]*work1d.v[916]-work1d.L[1084]*work1d.v[917]-work1d.L[1085]*work1d.v[918];
  work1d.d[919] = work1d.v[919];
  if (work1d.d[919] > 0)
    work1d.d[919] = -settings1d.kkt_reg;
  else
    work1d.d[919] -= settings1d.kkt_reg;
  work1d.d_inv[919] = 1/work1d.d[919];
  work1d.L[1089] = (work1d.KKT[1833])*work1d.d_inv[919];
  work1d.L[1097] = (-work1d.L[1095]*work1d.v[917]-work1d.L[1096]*work1d.v[918])*work1d.d_inv[919];
  work1d.L[1102] = (-work1d.L[1101]*work1d.v[918])*work1d.d_inv[919];
  work1d.v[339] = work1d.L[1086]*work1d.d[339];
  work1d.v[520] = work1d.L[1087]*work1d.d[520];
  work1d.v[521] = work1d.L[1088]*work1d.d[521];
  work1d.v[919] = work1d.L[1089]*work1d.d[919];
  work1d.v[920] = work1d.KKT[1834]-work1d.L[1086]*work1d.v[339]-work1d.L[1087]*work1d.v[520]-work1d.L[1088]*work1d.v[521]-work1d.L[1089]*work1d.v[919];
  work1d.d[920] = work1d.v[920];
  if (work1d.d[920] < 0)
    work1d.d[920] = settings1d.kkt_reg;
  else
    work1d.d[920] += settings1d.kkt_reg;
  work1d.d_inv[920] = 1/work1d.d[920];
  work1d.L[1098] = (-work1d.L[1097]*work1d.v[919])*work1d.d_inv[920];
  work1d.L[1103] = (work1d.KKT[1835]-work1d.L[1102]*work1d.v[919])*work1d.d_inv[920];
  work1d.L[1105] = (work1d.KKT[1836])*work1d.d_inv[920];
  work1d.v[379] = work1d.L[1090]*work1d.d[379];
  work1d.v[681] = work1d.L[1091]*work1d.d[681];
  work1d.v[682] = work1d.L[1092]*work1d.d[682];
  work1d.v[788] = work1d.L[1093]*work1d.d[788];
  work1d.v[789] = work1d.L[1094]*work1d.d[789];
  work1d.v[917] = work1d.L[1095]*work1d.d[917];
  work1d.v[918] = work1d.L[1096]*work1d.d[918];
  work1d.v[919] = work1d.L[1097]*work1d.d[919];
  work1d.v[920] = work1d.L[1098]*work1d.d[920];
  work1d.v[921] = work1d.KKT[1837]-work1d.L[1090]*work1d.v[379]-work1d.L[1091]*work1d.v[681]-work1d.L[1092]*work1d.v[682]-work1d.L[1093]*work1d.v[788]-work1d.L[1094]*work1d.v[789]-work1d.L[1095]*work1d.v[917]-work1d.L[1096]*work1d.v[918]-work1d.L[1097]*work1d.v[919]-work1d.L[1098]*work1d.v[920];
  work1d.d[921] = work1d.v[921];
  if (work1d.d[921] < 0)
    work1d.d[921] = settings1d.kkt_reg;
  else
    work1d.d[921] += settings1d.kkt_reg;
  work1d.d_inv[921] = 1/work1d.d[921];
  work1d.L[1104] = (-work1d.L[1101]*work1d.v[918]-work1d.L[1102]*work1d.v[919]-work1d.L[1103]*work1d.v[920])*work1d.d_inv[921];
  work1d.L[1106] = (work1d.KKT[1838]-work1d.L[1105]*work1d.v[920])*work1d.d_inv[921];
  work1d.L[1117] = (-work1d.L[1115]*work1d.v[789])*work1d.d_inv[921];
  work1d.v[830] = work1d.L[1099]*work1d.d[830];
  work1d.v[831] = work1d.L[1100]*work1d.d[831];
  work1d.v[918] = work1d.L[1101]*work1d.d[918];
  work1d.v[919] = work1d.L[1102]*work1d.d[919];
  work1d.v[920] = work1d.L[1103]*work1d.d[920];
  work1d.v[921] = work1d.L[1104]*work1d.d[921];
  work1d.v[922] = 0-work1d.L[1099]*work1d.v[830]-work1d.L[1100]*work1d.v[831]-work1d.L[1101]*work1d.v[918]-work1d.L[1102]*work1d.v[919]-work1d.L[1103]*work1d.v[920]-work1d.L[1104]*work1d.v[921];
  work1d.d[922] = work1d.v[922];
  if (work1d.d[922] > 0)
    work1d.d[922] = -settings1d.kkt_reg;
  else
    work1d.d[922] -= settings1d.kkt_reg;
  work1d.d_inv[922] = 1/work1d.d[922];
  work1d.L[1107] = (-work1d.L[1105]*work1d.v[920]-work1d.L[1106]*work1d.v[921])*work1d.d_inv[922];
  work1d.L[1118] = (-work1d.L[1117]*work1d.v[921])*work1d.d_inv[922];
  work1d.L[1123] = (-work1d.L[1121]*work1d.v[831])*work1d.d_inv[922];
  work1d.v[920] = work1d.L[1105]*work1d.d[920];
  work1d.v[921] = work1d.L[1106]*work1d.d[921];
  work1d.v[922] = work1d.L[1107]*work1d.d[922];
  work1d.v[923] = 0-work1d.L[1105]*work1d.v[920]-work1d.L[1106]*work1d.v[921]-work1d.L[1107]*work1d.v[922];
  work1d.d[923] = work1d.v[923];
  if (work1d.d[923] > 0)
    work1d.d[923] = -settings1d.kkt_reg;
  else
    work1d.d[923] -= settings1d.kkt_reg;
  work1d.d_inv[923] = 1/work1d.d[923];
  work1d.L[1111] = (work1d.KKT[1839])*work1d.d_inv[923];
  work1d.L[1119] = (-work1d.L[1117]*work1d.v[921]-work1d.L[1118]*work1d.v[922])*work1d.d_inv[923];
  work1d.L[1124] = (-work1d.L[1123]*work1d.v[922])*work1d.d_inv[923];
  work1d.v[340] = work1d.L[1108]*work1d.d[340];
  work1d.v[524] = work1d.L[1109]*work1d.d[524];
  work1d.v[525] = work1d.L[1110]*work1d.d[525];
  work1d.v[923] = work1d.L[1111]*work1d.d[923];
  work1d.v[924] = work1d.KKT[1840]-work1d.L[1108]*work1d.v[340]-work1d.L[1109]*work1d.v[524]-work1d.L[1110]*work1d.v[525]-work1d.L[1111]*work1d.v[923];
  work1d.d[924] = work1d.v[924];
  if (work1d.d[924] < 0)
    work1d.d[924] = settings1d.kkt_reg;
  else
    work1d.d[924] += settings1d.kkt_reg;
  work1d.d_inv[924] = 1/work1d.d[924];
  work1d.L[1120] = (-work1d.L[1119]*work1d.v[923])*work1d.d_inv[924];
  work1d.L[1125] = (work1d.KKT[1841]-work1d.L[1124]*work1d.v[923])*work1d.d_inv[924];
  work1d.L[1127] = (work1d.KKT[1842])*work1d.d_inv[924];
  work1d.v[380] = work1d.L[1112]*work1d.d[380];
  work1d.v[685] = work1d.L[1113]*work1d.d[685];
  work1d.v[686] = work1d.L[1114]*work1d.d[686];
  work1d.v[789] = work1d.L[1115]*work1d.d[789];
  work1d.v[790] = work1d.L[1116]*work1d.d[790];
  work1d.v[921] = work1d.L[1117]*work1d.d[921];
  work1d.v[922] = work1d.L[1118]*work1d.d[922];
  work1d.v[923] = work1d.L[1119]*work1d.d[923];
  work1d.v[924] = work1d.L[1120]*work1d.d[924];
  work1d.v[925] = work1d.KKT[1843]-work1d.L[1112]*work1d.v[380]-work1d.L[1113]*work1d.v[685]-work1d.L[1114]*work1d.v[686]-work1d.L[1115]*work1d.v[789]-work1d.L[1116]*work1d.v[790]-work1d.L[1117]*work1d.v[921]-work1d.L[1118]*work1d.v[922]-work1d.L[1119]*work1d.v[923]-work1d.L[1120]*work1d.v[924];
  work1d.d[925] = work1d.v[925];
  if (work1d.d[925] < 0)
    work1d.d[925] = settings1d.kkt_reg;
  else
    work1d.d[925] += settings1d.kkt_reg;
  work1d.d_inv[925] = 1/work1d.d[925];
  work1d.L[1126] = (-work1d.L[1123]*work1d.v[922]-work1d.L[1124]*work1d.v[923]-work1d.L[1125]*work1d.v[924])*work1d.d_inv[925];
  work1d.L[1128] = (work1d.KKT[1844]-work1d.L[1127]*work1d.v[924])*work1d.d_inv[925];
  work1d.L[1139] = (-work1d.L[1137]*work1d.v[790])*work1d.d_inv[925];
  work1d.v[831] = work1d.L[1121]*work1d.d[831];
  work1d.v[832] = work1d.L[1122]*work1d.d[832];
  work1d.v[922] = work1d.L[1123]*work1d.d[922];
  work1d.v[923] = work1d.L[1124]*work1d.d[923];
  work1d.v[924] = work1d.L[1125]*work1d.d[924];
  work1d.v[925] = work1d.L[1126]*work1d.d[925];
  work1d.v[926] = 0-work1d.L[1121]*work1d.v[831]-work1d.L[1122]*work1d.v[832]-work1d.L[1123]*work1d.v[922]-work1d.L[1124]*work1d.v[923]-work1d.L[1125]*work1d.v[924]-work1d.L[1126]*work1d.v[925];
  work1d.d[926] = work1d.v[926];
  if (work1d.d[926] > 0)
    work1d.d[926] = -settings1d.kkt_reg;
  else
    work1d.d[926] -= settings1d.kkt_reg;
  work1d.d_inv[926] = 1/work1d.d[926];
  work1d.L[1129] = (-work1d.L[1127]*work1d.v[924]-work1d.L[1128]*work1d.v[925])*work1d.d_inv[926];
  work1d.L[1140] = (-work1d.L[1139]*work1d.v[925])*work1d.d_inv[926];
  work1d.L[1145] = (-work1d.L[1143]*work1d.v[832])*work1d.d_inv[926];
  work1d.v[924] = work1d.L[1127]*work1d.d[924];
  work1d.v[925] = work1d.L[1128]*work1d.d[925];
  work1d.v[926] = work1d.L[1129]*work1d.d[926];
  work1d.v[927] = 0-work1d.L[1127]*work1d.v[924]-work1d.L[1128]*work1d.v[925]-work1d.L[1129]*work1d.v[926];
  work1d.d[927] = work1d.v[927];
  if (work1d.d[927] > 0)
    work1d.d[927] = -settings1d.kkt_reg;
  else
    work1d.d[927] -= settings1d.kkt_reg;
  work1d.d_inv[927] = 1/work1d.d[927];
  work1d.L[1133] = (work1d.KKT[1845])*work1d.d_inv[927];
  work1d.L[1141] = (-work1d.L[1139]*work1d.v[925]-work1d.L[1140]*work1d.v[926])*work1d.d_inv[927];
  work1d.L[1146] = (-work1d.L[1145]*work1d.v[926])*work1d.d_inv[927];
  work1d.v[341] = work1d.L[1130]*work1d.d[341];
  work1d.v[528] = work1d.L[1131]*work1d.d[528];
  work1d.v[529] = work1d.L[1132]*work1d.d[529];
  work1d.v[927] = work1d.L[1133]*work1d.d[927];
  work1d.v[928] = work1d.KKT[1846]-work1d.L[1130]*work1d.v[341]-work1d.L[1131]*work1d.v[528]-work1d.L[1132]*work1d.v[529]-work1d.L[1133]*work1d.v[927];
  work1d.d[928] = work1d.v[928];
  if (work1d.d[928] < 0)
    work1d.d[928] = settings1d.kkt_reg;
  else
    work1d.d[928] += settings1d.kkt_reg;
  work1d.d_inv[928] = 1/work1d.d[928];
  work1d.L[1142] = (-work1d.L[1141]*work1d.v[927])*work1d.d_inv[928];
  work1d.L[1147] = (work1d.KKT[1847]-work1d.L[1146]*work1d.v[927])*work1d.d_inv[928];
  work1d.L[1149] = (work1d.KKT[1848])*work1d.d_inv[928];
  work1d.v[381] = work1d.L[1134]*work1d.d[381];
  work1d.v[689] = work1d.L[1135]*work1d.d[689];
  work1d.v[690] = work1d.L[1136]*work1d.d[690];
  work1d.v[790] = work1d.L[1137]*work1d.d[790];
  work1d.v[791] = work1d.L[1138]*work1d.d[791];
  work1d.v[925] = work1d.L[1139]*work1d.d[925];
  work1d.v[926] = work1d.L[1140]*work1d.d[926];
  work1d.v[927] = work1d.L[1141]*work1d.d[927];
  work1d.v[928] = work1d.L[1142]*work1d.d[928];
  work1d.v[929] = work1d.KKT[1849]-work1d.L[1134]*work1d.v[381]-work1d.L[1135]*work1d.v[689]-work1d.L[1136]*work1d.v[690]-work1d.L[1137]*work1d.v[790]-work1d.L[1138]*work1d.v[791]-work1d.L[1139]*work1d.v[925]-work1d.L[1140]*work1d.v[926]-work1d.L[1141]*work1d.v[927]-work1d.L[1142]*work1d.v[928];
  work1d.d[929] = work1d.v[929];
  if (work1d.d[929] < 0)
    work1d.d[929] = settings1d.kkt_reg;
  else
    work1d.d[929] += settings1d.kkt_reg;
  work1d.d_inv[929] = 1/work1d.d[929];
  work1d.L[1148] = (-work1d.L[1145]*work1d.v[926]-work1d.L[1146]*work1d.v[927]-work1d.L[1147]*work1d.v[928])*work1d.d_inv[929];
  work1d.L[1150] = (work1d.KKT[1850]-work1d.L[1149]*work1d.v[928])*work1d.d_inv[929];
  work1d.L[1161] = (-work1d.L[1159]*work1d.v[791])*work1d.d_inv[929];
  work1d.v[832] = work1d.L[1143]*work1d.d[832];
  work1d.v[833] = work1d.L[1144]*work1d.d[833];
  work1d.v[926] = work1d.L[1145]*work1d.d[926];
  work1d.v[927] = work1d.L[1146]*work1d.d[927];
  work1d.v[928] = work1d.L[1147]*work1d.d[928];
  work1d.v[929] = work1d.L[1148]*work1d.d[929];
  work1d.v[930] = 0-work1d.L[1143]*work1d.v[832]-work1d.L[1144]*work1d.v[833]-work1d.L[1145]*work1d.v[926]-work1d.L[1146]*work1d.v[927]-work1d.L[1147]*work1d.v[928]-work1d.L[1148]*work1d.v[929];
  work1d.d[930] = work1d.v[930];
  if (work1d.d[930] > 0)
    work1d.d[930] = -settings1d.kkt_reg;
  else
    work1d.d[930] -= settings1d.kkt_reg;
  work1d.d_inv[930] = 1/work1d.d[930];
  work1d.L[1151] = (-work1d.L[1149]*work1d.v[928]-work1d.L[1150]*work1d.v[929])*work1d.d_inv[930];
  work1d.L[1162] = (-work1d.L[1161]*work1d.v[929])*work1d.d_inv[930];
  work1d.L[1167] = (-work1d.L[1165]*work1d.v[833])*work1d.d_inv[930];
  work1d.v[928] = work1d.L[1149]*work1d.d[928];
  work1d.v[929] = work1d.L[1150]*work1d.d[929];
  work1d.v[930] = work1d.L[1151]*work1d.d[930];
  work1d.v[931] = 0-work1d.L[1149]*work1d.v[928]-work1d.L[1150]*work1d.v[929]-work1d.L[1151]*work1d.v[930];
  work1d.d[931] = work1d.v[931];
  if (work1d.d[931] > 0)
    work1d.d[931] = -settings1d.kkt_reg;
  else
    work1d.d[931] -= settings1d.kkt_reg;
  work1d.d_inv[931] = 1/work1d.d[931];
  work1d.L[1155] = (work1d.KKT[1851])*work1d.d_inv[931];
  work1d.L[1163] = (-work1d.L[1161]*work1d.v[929]-work1d.L[1162]*work1d.v[930])*work1d.d_inv[931];
  work1d.L[1168] = (-work1d.L[1167]*work1d.v[930])*work1d.d_inv[931];
  work1d.v[342] = work1d.L[1152]*work1d.d[342];
  work1d.v[532] = work1d.L[1153]*work1d.d[532];
  work1d.v[533] = work1d.L[1154]*work1d.d[533];
  work1d.v[931] = work1d.L[1155]*work1d.d[931];
  work1d.v[932] = work1d.KKT[1852]-work1d.L[1152]*work1d.v[342]-work1d.L[1153]*work1d.v[532]-work1d.L[1154]*work1d.v[533]-work1d.L[1155]*work1d.v[931];
  work1d.d[932] = work1d.v[932];
  if (work1d.d[932] < 0)
    work1d.d[932] = settings1d.kkt_reg;
  else
    work1d.d[932] += settings1d.kkt_reg;
  work1d.d_inv[932] = 1/work1d.d[932];
  work1d.L[1164] = (-work1d.L[1163]*work1d.v[931])*work1d.d_inv[932];
  work1d.L[1169] = (work1d.KKT[1853]-work1d.L[1168]*work1d.v[931])*work1d.d_inv[932];
  work1d.L[1171] = (work1d.KKT[1854])*work1d.d_inv[932];
  work1d.v[382] = work1d.L[1156]*work1d.d[382];
  work1d.v[693] = work1d.L[1157]*work1d.d[693];
  work1d.v[694] = work1d.L[1158]*work1d.d[694];
  work1d.v[791] = work1d.L[1159]*work1d.d[791];
  work1d.v[792] = work1d.L[1160]*work1d.d[792];
  work1d.v[929] = work1d.L[1161]*work1d.d[929];
  work1d.v[930] = work1d.L[1162]*work1d.d[930];
  work1d.v[931] = work1d.L[1163]*work1d.d[931];
  work1d.v[932] = work1d.L[1164]*work1d.d[932];
  work1d.v[933] = work1d.KKT[1855]-work1d.L[1156]*work1d.v[382]-work1d.L[1157]*work1d.v[693]-work1d.L[1158]*work1d.v[694]-work1d.L[1159]*work1d.v[791]-work1d.L[1160]*work1d.v[792]-work1d.L[1161]*work1d.v[929]-work1d.L[1162]*work1d.v[930]-work1d.L[1163]*work1d.v[931]-work1d.L[1164]*work1d.v[932];
  work1d.d[933] = work1d.v[933];
  if (work1d.d[933] < 0)
    work1d.d[933] = settings1d.kkt_reg;
  else
    work1d.d[933] += settings1d.kkt_reg;
  work1d.d_inv[933] = 1/work1d.d[933];
  work1d.L[1170] = (-work1d.L[1167]*work1d.v[930]-work1d.L[1168]*work1d.v[931]-work1d.L[1169]*work1d.v[932])*work1d.d_inv[933];
  work1d.L[1172] = (work1d.KKT[1856]-work1d.L[1171]*work1d.v[932])*work1d.d_inv[933];
  work1d.L[1183] = (-work1d.L[1181]*work1d.v[792])*work1d.d_inv[933];
  work1d.v[833] = work1d.L[1165]*work1d.d[833];
  work1d.v[834] = work1d.L[1166]*work1d.d[834];
  work1d.v[930] = work1d.L[1167]*work1d.d[930];
  work1d.v[931] = work1d.L[1168]*work1d.d[931];
  work1d.v[932] = work1d.L[1169]*work1d.d[932];
  work1d.v[933] = work1d.L[1170]*work1d.d[933];
  work1d.v[934] = 0-work1d.L[1165]*work1d.v[833]-work1d.L[1166]*work1d.v[834]-work1d.L[1167]*work1d.v[930]-work1d.L[1168]*work1d.v[931]-work1d.L[1169]*work1d.v[932]-work1d.L[1170]*work1d.v[933];
  work1d.d[934] = work1d.v[934];
  if (work1d.d[934] > 0)
    work1d.d[934] = -settings1d.kkt_reg;
  else
    work1d.d[934] -= settings1d.kkt_reg;
  work1d.d_inv[934] = 1/work1d.d[934];
  work1d.L[1173] = (-work1d.L[1171]*work1d.v[932]-work1d.L[1172]*work1d.v[933])*work1d.d_inv[934];
  work1d.L[1184] = (-work1d.L[1183]*work1d.v[933])*work1d.d_inv[934];
  work1d.L[1189] = (-work1d.L[1187]*work1d.v[834])*work1d.d_inv[934];
  work1d.v[932] = work1d.L[1171]*work1d.d[932];
  work1d.v[933] = work1d.L[1172]*work1d.d[933];
  work1d.v[934] = work1d.L[1173]*work1d.d[934];
  work1d.v[935] = 0-work1d.L[1171]*work1d.v[932]-work1d.L[1172]*work1d.v[933]-work1d.L[1173]*work1d.v[934];
  work1d.d[935] = work1d.v[935];
  if (work1d.d[935] > 0)
    work1d.d[935] = -settings1d.kkt_reg;
  else
    work1d.d[935] -= settings1d.kkt_reg;
  work1d.d_inv[935] = 1/work1d.d[935];
  work1d.L[1177] = (work1d.KKT[1857])*work1d.d_inv[935];
  work1d.L[1185] = (-work1d.L[1183]*work1d.v[933]-work1d.L[1184]*work1d.v[934])*work1d.d_inv[935];
  work1d.L[1190] = (-work1d.L[1189]*work1d.v[934])*work1d.d_inv[935];
  work1d.v[343] = work1d.L[1174]*work1d.d[343];
  work1d.v[536] = work1d.L[1175]*work1d.d[536];
  work1d.v[537] = work1d.L[1176]*work1d.d[537];
  work1d.v[935] = work1d.L[1177]*work1d.d[935];
  work1d.v[936] = work1d.KKT[1858]-work1d.L[1174]*work1d.v[343]-work1d.L[1175]*work1d.v[536]-work1d.L[1176]*work1d.v[537]-work1d.L[1177]*work1d.v[935];
  work1d.d[936] = work1d.v[936];
  if (work1d.d[936] < 0)
    work1d.d[936] = settings1d.kkt_reg;
  else
    work1d.d[936] += settings1d.kkt_reg;
  work1d.d_inv[936] = 1/work1d.d[936];
  work1d.L[1186] = (-work1d.L[1185]*work1d.v[935])*work1d.d_inv[936];
  work1d.L[1191] = (work1d.KKT[1859]-work1d.L[1190]*work1d.v[935])*work1d.d_inv[936];
  work1d.L[1193] = (work1d.KKT[1860])*work1d.d_inv[936];
  work1d.v[383] = work1d.L[1178]*work1d.d[383];
  work1d.v[697] = work1d.L[1179]*work1d.d[697];
  work1d.v[698] = work1d.L[1180]*work1d.d[698];
  work1d.v[792] = work1d.L[1181]*work1d.d[792];
  work1d.v[793] = work1d.L[1182]*work1d.d[793];
  work1d.v[933] = work1d.L[1183]*work1d.d[933];
  work1d.v[934] = work1d.L[1184]*work1d.d[934];
  work1d.v[935] = work1d.L[1185]*work1d.d[935];
  work1d.v[936] = work1d.L[1186]*work1d.d[936];
  work1d.v[937] = work1d.KKT[1861]-work1d.L[1178]*work1d.v[383]-work1d.L[1179]*work1d.v[697]-work1d.L[1180]*work1d.v[698]-work1d.L[1181]*work1d.v[792]-work1d.L[1182]*work1d.v[793]-work1d.L[1183]*work1d.v[933]-work1d.L[1184]*work1d.v[934]-work1d.L[1185]*work1d.v[935]-work1d.L[1186]*work1d.v[936];
  work1d.d[937] = work1d.v[937];
  if (work1d.d[937] < 0)
    work1d.d[937] = settings1d.kkt_reg;
  else
    work1d.d[937] += settings1d.kkt_reg;
  work1d.d_inv[937] = 1/work1d.d[937];
  work1d.L[1192] = (-work1d.L[1189]*work1d.v[934]-work1d.L[1190]*work1d.v[935]-work1d.L[1191]*work1d.v[936])*work1d.d_inv[937];
  work1d.L[1194] = (work1d.KKT[1862]-work1d.L[1193]*work1d.v[936])*work1d.d_inv[937];
  work1d.L[1205] = (-work1d.L[1203]*work1d.v[793])*work1d.d_inv[937];
  work1d.v[834] = work1d.L[1187]*work1d.d[834];
  work1d.v[835] = work1d.L[1188]*work1d.d[835];
  work1d.v[934] = work1d.L[1189]*work1d.d[934];
  work1d.v[935] = work1d.L[1190]*work1d.d[935];
  work1d.v[936] = work1d.L[1191]*work1d.d[936];
  work1d.v[937] = work1d.L[1192]*work1d.d[937];
  work1d.v[938] = 0-work1d.L[1187]*work1d.v[834]-work1d.L[1188]*work1d.v[835]-work1d.L[1189]*work1d.v[934]-work1d.L[1190]*work1d.v[935]-work1d.L[1191]*work1d.v[936]-work1d.L[1192]*work1d.v[937];
  work1d.d[938] = work1d.v[938];
  if (work1d.d[938] > 0)
    work1d.d[938] = -settings1d.kkt_reg;
  else
    work1d.d[938] -= settings1d.kkt_reg;
  work1d.d_inv[938] = 1/work1d.d[938];
  work1d.L[1195] = (-work1d.L[1193]*work1d.v[936]-work1d.L[1194]*work1d.v[937])*work1d.d_inv[938];
  work1d.L[1206] = (-work1d.L[1205]*work1d.v[937])*work1d.d_inv[938];
  work1d.L[1211] = (-work1d.L[1209]*work1d.v[835])*work1d.d_inv[938];
  work1d.v[936] = work1d.L[1193]*work1d.d[936];
  work1d.v[937] = work1d.L[1194]*work1d.d[937];
  work1d.v[938] = work1d.L[1195]*work1d.d[938];
  work1d.v[939] = 0-work1d.L[1193]*work1d.v[936]-work1d.L[1194]*work1d.v[937]-work1d.L[1195]*work1d.v[938];
  work1d.d[939] = work1d.v[939];
  if (work1d.d[939] > 0)
    work1d.d[939] = -settings1d.kkt_reg;
  else
    work1d.d[939] -= settings1d.kkt_reg;
  work1d.d_inv[939] = 1/work1d.d[939];
  work1d.L[1199] = (work1d.KKT[1863])*work1d.d_inv[939];
  work1d.L[1207] = (-work1d.L[1205]*work1d.v[937]-work1d.L[1206]*work1d.v[938])*work1d.d_inv[939];
  work1d.L[1212] = (-work1d.L[1211]*work1d.v[938])*work1d.d_inv[939];
  work1d.v[344] = work1d.L[1196]*work1d.d[344];
  work1d.v[540] = work1d.L[1197]*work1d.d[540];
  work1d.v[541] = work1d.L[1198]*work1d.d[541];
  work1d.v[939] = work1d.L[1199]*work1d.d[939];
  work1d.v[940] = work1d.KKT[1864]-work1d.L[1196]*work1d.v[344]-work1d.L[1197]*work1d.v[540]-work1d.L[1198]*work1d.v[541]-work1d.L[1199]*work1d.v[939];
  work1d.d[940] = work1d.v[940];
  if (work1d.d[940] < 0)
    work1d.d[940] = settings1d.kkt_reg;
  else
    work1d.d[940] += settings1d.kkt_reg;
  work1d.d_inv[940] = 1/work1d.d[940];
  work1d.L[1208] = (-work1d.L[1207]*work1d.v[939])*work1d.d_inv[940];
  work1d.L[1213] = (work1d.KKT[1865]-work1d.L[1212]*work1d.v[939])*work1d.d_inv[940];
  work1d.L[1215] = (work1d.KKT[1866])*work1d.d_inv[940];
  work1d.v[384] = work1d.L[1200]*work1d.d[384];
  work1d.v[701] = work1d.L[1201]*work1d.d[701];
  work1d.v[702] = work1d.L[1202]*work1d.d[702];
  work1d.v[793] = work1d.L[1203]*work1d.d[793];
  work1d.v[794] = work1d.L[1204]*work1d.d[794];
  work1d.v[937] = work1d.L[1205]*work1d.d[937];
  work1d.v[938] = work1d.L[1206]*work1d.d[938];
  work1d.v[939] = work1d.L[1207]*work1d.d[939];
  work1d.v[940] = work1d.L[1208]*work1d.d[940];
  work1d.v[941] = work1d.KKT[1867]-work1d.L[1200]*work1d.v[384]-work1d.L[1201]*work1d.v[701]-work1d.L[1202]*work1d.v[702]-work1d.L[1203]*work1d.v[793]-work1d.L[1204]*work1d.v[794]-work1d.L[1205]*work1d.v[937]-work1d.L[1206]*work1d.v[938]-work1d.L[1207]*work1d.v[939]-work1d.L[1208]*work1d.v[940];
  work1d.d[941] = work1d.v[941];
  if (work1d.d[941] < 0)
    work1d.d[941] = settings1d.kkt_reg;
  else
    work1d.d[941] += settings1d.kkt_reg;
  work1d.d_inv[941] = 1/work1d.d[941];
  work1d.L[1214] = (-work1d.L[1211]*work1d.v[938]-work1d.L[1212]*work1d.v[939]-work1d.L[1213]*work1d.v[940])*work1d.d_inv[941];
  work1d.L[1216] = (work1d.KKT[1868]-work1d.L[1215]*work1d.v[940])*work1d.d_inv[941];
  work1d.L[1227] = (-work1d.L[1225]*work1d.v[794])*work1d.d_inv[941];
  work1d.v[835] = work1d.L[1209]*work1d.d[835];
  work1d.v[836] = work1d.L[1210]*work1d.d[836];
  work1d.v[938] = work1d.L[1211]*work1d.d[938];
  work1d.v[939] = work1d.L[1212]*work1d.d[939];
  work1d.v[940] = work1d.L[1213]*work1d.d[940];
  work1d.v[941] = work1d.L[1214]*work1d.d[941];
  work1d.v[942] = 0-work1d.L[1209]*work1d.v[835]-work1d.L[1210]*work1d.v[836]-work1d.L[1211]*work1d.v[938]-work1d.L[1212]*work1d.v[939]-work1d.L[1213]*work1d.v[940]-work1d.L[1214]*work1d.v[941];
  work1d.d[942] = work1d.v[942];
  if (work1d.d[942] > 0)
    work1d.d[942] = -settings1d.kkt_reg;
  else
    work1d.d[942] -= settings1d.kkt_reg;
  work1d.d_inv[942] = 1/work1d.d[942];
  work1d.L[1217] = (-work1d.L[1215]*work1d.v[940]-work1d.L[1216]*work1d.v[941])*work1d.d_inv[942];
  work1d.L[1228] = (-work1d.L[1227]*work1d.v[941])*work1d.d_inv[942];
  work1d.L[1233] = (-work1d.L[1231]*work1d.v[836])*work1d.d_inv[942];
  work1d.v[940] = work1d.L[1215]*work1d.d[940];
  work1d.v[941] = work1d.L[1216]*work1d.d[941];
  work1d.v[942] = work1d.L[1217]*work1d.d[942];
  work1d.v[943] = 0-work1d.L[1215]*work1d.v[940]-work1d.L[1216]*work1d.v[941]-work1d.L[1217]*work1d.v[942];
  work1d.d[943] = work1d.v[943];
  if (work1d.d[943] > 0)
    work1d.d[943] = -settings1d.kkt_reg;
  else
    work1d.d[943] -= settings1d.kkt_reg;
  work1d.d_inv[943] = 1/work1d.d[943];
  work1d.L[1221] = (work1d.KKT[1869])*work1d.d_inv[943];
  work1d.L[1229] = (-work1d.L[1227]*work1d.v[941]-work1d.L[1228]*work1d.v[942])*work1d.d_inv[943];
  work1d.L[1234] = (-work1d.L[1233]*work1d.v[942])*work1d.d_inv[943];
  work1d.v[345] = work1d.L[1218]*work1d.d[345];
  work1d.v[544] = work1d.L[1219]*work1d.d[544];
  work1d.v[545] = work1d.L[1220]*work1d.d[545];
  work1d.v[943] = work1d.L[1221]*work1d.d[943];
  work1d.v[944] = work1d.KKT[1870]-work1d.L[1218]*work1d.v[345]-work1d.L[1219]*work1d.v[544]-work1d.L[1220]*work1d.v[545]-work1d.L[1221]*work1d.v[943];
  work1d.d[944] = work1d.v[944];
  if (work1d.d[944] < 0)
    work1d.d[944] = settings1d.kkt_reg;
  else
    work1d.d[944] += settings1d.kkt_reg;
  work1d.d_inv[944] = 1/work1d.d[944];
  work1d.L[1230] = (-work1d.L[1229]*work1d.v[943])*work1d.d_inv[944];
  work1d.L[1235] = (work1d.KKT[1871]-work1d.L[1234]*work1d.v[943])*work1d.d_inv[944];
  work1d.L[1237] = (work1d.KKT[1872])*work1d.d_inv[944];
  work1d.v[385] = work1d.L[1222]*work1d.d[385];
  work1d.v[705] = work1d.L[1223]*work1d.d[705];
  work1d.v[706] = work1d.L[1224]*work1d.d[706];
  work1d.v[794] = work1d.L[1225]*work1d.d[794];
  work1d.v[795] = work1d.L[1226]*work1d.d[795];
  work1d.v[941] = work1d.L[1227]*work1d.d[941];
  work1d.v[942] = work1d.L[1228]*work1d.d[942];
  work1d.v[943] = work1d.L[1229]*work1d.d[943];
  work1d.v[944] = work1d.L[1230]*work1d.d[944];
  work1d.v[945] = work1d.KKT[1873]-work1d.L[1222]*work1d.v[385]-work1d.L[1223]*work1d.v[705]-work1d.L[1224]*work1d.v[706]-work1d.L[1225]*work1d.v[794]-work1d.L[1226]*work1d.v[795]-work1d.L[1227]*work1d.v[941]-work1d.L[1228]*work1d.v[942]-work1d.L[1229]*work1d.v[943]-work1d.L[1230]*work1d.v[944];
  work1d.d[945] = work1d.v[945];
  if (work1d.d[945] < 0)
    work1d.d[945] = settings1d.kkt_reg;
  else
    work1d.d[945] += settings1d.kkt_reg;
  work1d.d_inv[945] = 1/work1d.d[945];
  work1d.L[1236] = (-work1d.L[1233]*work1d.v[942]-work1d.L[1234]*work1d.v[943]-work1d.L[1235]*work1d.v[944])*work1d.d_inv[945];
  work1d.L[1238] = (work1d.KKT[1874]-work1d.L[1237]*work1d.v[944])*work1d.d_inv[945];
  work1d.L[1249] = (-work1d.L[1247]*work1d.v[795])*work1d.d_inv[945];
  work1d.v[836] = work1d.L[1231]*work1d.d[836];
  work1d.v[837] = work1d.L[1232]*work1d.d[837];
  work1d.v[942] = work1d.L[1233]*work1d.d[942];
  work1d.v[943] = work1d.L[1234]*work1d.d[943];
  work1d.v[944] = work1d.L[1235]*work1d.d[944];
  work1d.v[945] = work1d.L[1236]*work1d.d[945];
  work1d.v[946] = 0-work1d.L[1231]*work1d.v[836]-work1d.L[1232]*work1d.v[837]-work1d.L[1233]*work1d.v[942]-work1d.L[1234]*work1d.v[943]-work1d.L[1235]*work1d.v[944]-work1d.L[1236]*work1d.v[945];
  work1d.d[946] = work1d.v[946];
  if (work1d.d[946] > 0)
    work1d.d[946] = -settings1d.kkt_reg;
  else
    work1d.d[946] -= settings1d.kkt_reg;
  work1d.d_inv[946] = 1/work1d.d[946];
  work1d.L[1239] = (-work1d.L[1237]*work1d.v[944]-work1d.L[1238]*work1d.v[945])*work1d.d_inv[946];
  work1d.L[1250] = (-work1d.L[1249]*work1d.v[945])*work1d.d_inv[946];
  work1d.L[1255] = (-work1d.L[1253]*work1d.v[837])*work1d.d_inv[946];
  work1d.v[944] = work1d.L[1237]*work1d.d[944];
  work1d.v[945] = work1d.L[1238]*work1d.d[945];
  work1d.v[946] = work1d.L[1239]*work1d.d[946];
  work1d.v[947] = 0-work1d.L[1237]*work1d.v[944]-work1d.L[1238]*work1d.v[945]-work1d.L[1239]*work1d.v[946];
  work1d.d[947] = work1d.v[947];
  if (work1d.d[947] > 0)
    work1d.d[947] = -settings1d.kkt_reg;
  else
    work1d.d[947] -= settings1d.kkt_reg;
  work1d.d_inv[947] = 1/work1d.d[947];
  work1d.L[1243] = (work1d.KKT[1875])*work1d.d_inv[947];
  work1d.L[1251] = (-work1d.L[1249]*work1d.v[945]-work1d.L[1250]*work1d.v[946])*work1d.d_inv[947];
  work1d.L[1256] = (-work1d.L[1255]*work1d.v[946])*work1d.d_inv[947];
  work1d.v[346] = work1d.L[1240]*work1d.d[346];
  work1d.v[548] = work1d.L[1241]*work1d.d[548];
  work1d.v[549] = work1d.L[1242]*work1d.d[549];
  work1d.v[947] = work1d.L[1243]*work1d.d[947];
  work1d.v[948] = work1d.KKT[1876]-work1d.L[1240]*work1d.v[346]-work1d.L[1241]*work1d.v[548]-work1d.L[1242]*work1d.v[549]-work1d.L[1243]*work1d.v[947];
  work1d.d[948] = work1d.v[948];
  if (work1d.d[948] < 0)
    work1d.d[948] = settings1d.kkt_reg;
  else
    work1d.d[948] += settings1d.kkt_reg;
  work1d.d_inv[948] = 1/work1d.d[948];
  work1d.L[1252] = (-work1d.L[1251]*work1d.v[947])*work1d.d_inv[948];
  work1d.L[1257] = (work1d.KKT[1877]-work1d.L[1256]*work1d.v[947])*work1d.d_inv[948];
  work1d.L[1259] = (work1d.KKT[1878])*work1d.d_inv[948];
  work1d.v[386] = work1d.L[1244]*work1d.d[386];
  work1d.v[709] = work1d.L[1245]*work1d.d[709];
  work1d.v[710] = work1d.L[1246]*work1d.d[710];
  work1d.v[795] = work1d.L[1247]*work1d.d[795];
  work1d.v[796] = work1d.L[1248]*work1d.d[796];
  work1d.v[945] = work1d.L[1249]*work1d.d[945];
  work1d.v[946] = work1d.L[1250]*work1d.d[946];
  work1d.v[947] = work1d.L[1251]*work1d.d[947];
  work1d.v[948] = work1d.L[1252]*work1d.d[948];
  work1d.v[949] = work1d.KKT[1879]-work1d.L[1244]*work1d.v[386]-work1d.L[1245]*work1d.v[709]-work1d.L[1246]*work1d.v[710]-work1d.L[1247]*work1d.v[795]-work1d.L[1248]*work1d.v[796]-work1d.L[1249]*work1d.v[945]-work1d.L[1250]*work1d.v[946]-work1d.L[1251]*work1d.v[947]-work1d.L[1252]*work1d.v[948];
  work1d.d[949] = work1d.v[949];
  if (work1d.d[949] < 0)
    work1d.d[949] = settings1d.kkt_reg;
  else
    work1d.d[949] += settings1d.kkt_reg;
  work1d.d_inv[949] = 1/work1d.d[949];
  work1d.L[1258] = (-work1d.L[1255]*work1d.v[946]-work1d.L[1256]*work1d.v[947]-work1d.L[1257]*work1d.v[948])*work1d.d_inv[949];
  work1d.L[1260] = (work1d.KKT[1880]-work1d.L[1259]*work1d.v[948])*work1d.d_inv[949];
  work1d.L[1271] = (-work1d.L[1269]*work1d.v[796])*work1d.d_inv[949];
  work1d.v[837] = work1d.L[1253]*work1d.d[837];
  work1d.v[838] = work1d.L[1254]*work1d.d[838];
  work1d.v[946] = work1d.L[1255]*work1d.d[946];
  work1d.v[947] = work1d.L[1256]*work1d.d[947];
  work1d.v[948] = work1d.L[1257]*work1d.d[948];
  work1d.v[949] = work1d.L[1258]*work1d.d[949];
  work1d.v[950] = 0-work1d.L[1253]*work1d.v[837]-work1d.L[1254]*work1d.v[838]-work1d.L[1255]*work1d.v[946]-work1d.L[1256]*work1d.v[947]-work1d.L[1257]*work1d.v[948]-work1d.L[1258]*work1d.v[949];
  work1d.d[950] = work1d.v[950];
  if (work1d.d[950] > 0)
    work1d.d[950] = -settings1d.kkt_reg;
  else
    work1d.d[950] -= settings1d.kkt_reg;
  work1d.d_inv[950] = 1/work1d.d[950];
  work1d.L[1261] = (-work1d.L[1259]*work1d.v[948]-work1d.L[1260]*work1d.v[949])*work1d.d_inv[950];
  work1d.L[1272] = (-work1d.L[1271]*work1d.v[949])*work1d.d_inv[950];
  work1d.L[1277] = (-work1d.L[1275]*work1d.v[838])*work1d.d_inv[950];
  work1d.v[948] = work1d.L[1259]*work1d.d[948];
  work1d.v[949] = work1d.L[1260]*work1d.d[949];
  work1d.v[950] = work1d.L[1261]*work1d.d[950];
  work1d.v[951] = 0-work1d.L[1259]*work1d.v[948]-work1d.L[1260]*work1d.v[949]-work1d.L[1261]*work1d.v[950];
  work1d.d[951] = work1d.v[951];
  if (work1d.d[951] > 0)
    work1d.d[951] = -settings1d.kkt_reg;
  else
    work1d.d[951] -= settings1d.kkt_reg;
  work1d.d_inv[951] = 1/work1d.d[951];
  work1d.L[1265] = (work1d.KKT[1881])*work1d.d_inv[951];
  work1d.L[1273] = (-work1d.L[1271]*work1d.v[949]-work1d.L[1272]*work1d.v[950])*work1d.d_inv[951];
  work1d.L[1278] = (-work1d.L[1277]*work1d.v[950])*work1d.d_inv[951];
  work1d.v[347] = work1d.L[1262]*work1d.d[347];
  work1d.v[552] = work1d.L[1263]*work1d.d[552];
  work1d.v[553] = work1d.L[1264]*work1d.d[553];
  work1d.v[951] = work1d.L[1265]*work1d.d[951];
  work1d.v[952] = work1d.KKT[1882]-work1d.L[1262]*work1d.v[347]-work1d.L[1263]*work1d.v[552]-work1d.L[1264]*work1d.v[553]-work1d.L[1265]*work1d.v[951];
  work1d.d[952] = work1d.v[952];
  if (work1d.d[952] < 0)
    work1d.d[952] = settings1d.kkt_reg;
  else
    work1d.d[952] += settings1d.kkt_reg;
  work1d.d_inv[952] = 1/work1d.d[952];
  work1d.L[1274] = (-work1d.L[1273]*work1d.v[951])*work1d.d_inv[952];
  work1d.L[1279] = (work1d.KKT[1883]-work1d.L[1278]*work1d.v[951])*work1d.d_inv[952];
  work1d.L[1281] = (work1d.KKT[1884])*work1d.d_inv[952];
  work1d.v[387] = work1d.L[1266]*work1d.d[387];
  work1d.v[713] = work1d.L[1267]*work1d.d[713];
  work1d.v[714] = work1d.L[1268]*work1d.d[714];
  work1d.v[796] = work1d.L[1269]*work1d.d[796];
  work1d.v[797] = work1d.L[1270]*work1d.d[797];
  work1d.v[949] = work1d.L[1271]*work1d.d[949];
  work1d.v[950] = work1d.L[1272]*work1d.d[950];
  work1d.v[951] = work1d.L[1273]*work1d.d[951];
  work1d.v[952] = work1d.L[1274]*work1d.d[952];
  work1d.v[953] = work1d.KKT[1885]-work1d.L[1266]*work1d.v[387]-work1d.L[1267]*work1d.v[713]-work1d.L[1268]*work1d.v[714]-work1d.L[1269]*work1d.v[796]-work1d.L[1270]*work1d.v[797]-work1d.L[1271]*work1d.v[949]-work1d.L[1272]*work1d.v[950]-work1d.L[1273]*work1d.v[951]-work1d.L[1274]*work1d.v[952];
  work1d.d[953] = work1d.v[953];
  if (work1d.d[953] < 0)
    work1d.d[953] = settings1d.kkt_reg;
  else
    work1d.d[953] += settings1d.kkt_reg;
  work1d.d_inv[953] = 1/work1d.d[953];
  work1d.L[1280] = (-work1d.L[1277]*work1d.v[950]-work1d.L[1278]*work1d.v[951]-work1d.L[1279]*work1d.v[952])*work1d.d_inv[953];
  work1d.L[1282] = (work1d.KKT[1886]-work1d.L[1281]*work1d.v[952])*work1d.d_inv[953];
  work1d.L[1293] = (-work1d.L[1291]*work1d.v[797])*work1d.d_inv[953];
  work1d.v[838] = work1d.L[1275]*work1d.d[838];
  work1d.v[839] = work1d.L[1276]*work1d.d[839];
  work1d.v[950] = work1d.L[1277]*work1d.d[950];
  work1d.v[951] = work1d.L[1278]*work1d.d[951];
  work1d.v[952] = work1d.L[1279]*work1d.d[952];
  work1d.v[953] = work1d.L[1280]*work1d.d[953];
  work1d.v[954] = 0-work1d.L[1275]*work1d.v[838]-work1d.L[1276]*work1d.v[839]-work1d.L[1277]*work1d.v[950]-work1d.L[1278]*work1d.v[951]-work1d.L[1279]*work1d.v[952]-work1d.L[1280]*work1d.v[953];
  work1d.d[954] = work1d.v[954];
  if (work1d.d[954] > 0)
    work1d.d[954] = -settings1d.kkt_reg;
  else
    work1d.d[954] -= settings1d.kkt_reg;
  work1d.d_inv[954] = 1/work1d.d[954];
  work1d.L[1283] = (-work1d.L[1281]*work1d.v[952]-work1d.L[1282]*work1d.v[953])*work1d.d_inv[954];
  work1d.L[1294] = (-work1d.L[1293]*work1d.v[953])*work1d.d_inv[954];
  work1d.L[1299] = (-work1d.L[1297]*work1d.v[839])*work1d.d_inv[954];
  work1d.v[952] = work1d.L[1281]*work1d.d[952];
  work1d.v[953] = work1d.L[1282]*work1d.d[953];
  work1d.v[954] = work1d.L[1283]*work1d.d[954];
  work1d.v[955] = 0-work1d.L[1281]*work1d.v[952]-work1d.L[1282]*work1d.v[953]-work1d.L[1283]*work1d.v[954];
  work1d.d[955] = work1d.v[955];
  if (work1d.d[955] > 0)
    work1d.d[955] = -settings1d.kkt_reg;
  else
    work1d.d[955] -= settings1d.kkt_reg;
  work1d.d_inv[955] = 1/work1d.d[955];
  work1d.L[1287] = (work1d.KKT[1887])*work1d.d_inv[955];
  work1d.L[1295] = (-work1d.L[1293]*work1d.v[953]-work1d.L[1294]*work1d.v[954])*work1d.d_inv[955];
  work1d.L[1300] = (-work1d.L[1299]*work1d.v[954])*work1d.d_inv[955];
  work1d.v[348] = work1d.L[1284]*work1d.d[348];
  work1d.v[556] = work1d.L[1285]*work1d.d[556];
  work1d.v[557] = work1d.L[1286]*work1d.d[557];
  work1d.v[955] = work1d.L[1287]*work1d.d[955];
  work1d.v[956] = work1d.KKT[1888]-work1d.L[1284]*work1d.v[348]-work1d.L[1285]*work1d.v[556]-work1d.L[1286]*work1d.v[557]-work1d.L[1287]*work1d.v[955];
  work1d.d[956] = work1d.v[956];
  if (work1d.d[956] < 0)
    work1d.d[956] = settings1d.kkt_reg;
  else
    work1d.d[956] += settings1d.kkt_reg;
  work1d.d_inv[956] = 1/work1d.d[956];
  work1d.L[1296] = (-work1d.L[1295]*work1d.v[955])*work1d.d_inv[956];
  work1d.L[1301] = (work1d.KKT[1889]-work1d.L[1300]*work1d.v[955])*work1d.d_inv[956];
  work1d.L[1303] = (work1d.KKT[1890])*work1d.d_inv[956];
  work1d.v[388] = work1d.L[1288]*work1d.d[388];
  work1d.v[717] = work1d.L[1289]*work1d.d[717];
  work1d.v[718] = work1d.L[1290]*work1d.d[718];
  work1d.v[797] = work1d.L[1291]*work1d.d[797];
  work1d.v[798] = work1d.L[1292]*work1d.d[798];
  work1d.v[953] = work1d.L[1293]*work1d.d[953];
  work1d.v[954] = work1d.L[1294]*work1d.d[954];
  work1d.v[955] = work1d.L[1295]*work1d.d[955];
  work1d.v[956] = work1d.L[1296]*work1d.d[956];
  work1d.v[957] = work1d.KKT[1891]-work1d.L[1288]*work1d.v[388]-work1d.L[1289]*work1d.v[717]-work1d.L[1290]*work1d.v[718]-work1d.L[1291]*work1d.v[797]-work1d.L[1292]*work1d.v[798]-work1d.L[1293]*work1d.v[953]-work1d.L[1294]*work1d.v[954]-work1d.L[1295]*work1d.v[955]-work1d.L[1296]*work1d.v[956];
  work1d.d[957] = work1d.v[957];
  if (work1d.d[957] < 0)
    work1d.d[957] = settings1d.kkt_reg;
  else
    work1d.d[957] += settings1d.kkt_reg;
  work1d.d_inv[957] = 1/work1d.d[957];
  work1d.L[1302] = (-work1d.L[1299]*work1d.v[954]-work1d.L[1300]*work1d.v[955]-work1d.L[1301]*work1d.v[956])*work1d.d_inv[957];
  work1d.L[1304] = (work1d.KKT[1892]-work1d.L[1303]*work1d.v[956])*work1d.d_inv[957];
  work1d.L[1315] = (-work1d.L[1313]*work1d.v[798])*work1d.d_inv[957];
  work1d.v[839] = work1d.L[1297]*work1d.d[839];
  work1d.v[840] = work1d.L[1298]*work1d.d[840];
  work1d.v[954] = work1d.L[1299]*work1d.d[954];
  work1d.v[955] = work1d.L[1300]*work1d.d[955];
  work1d.v[956] = work1d.L[1301]*work1d.d[956];
  work1d.v[957] = work1d.L[1302]*work1d.d[957];
  work1d.v[958] = 0-work1d.L[1297]*work1d.v[839]-work1d.L[1298]*work1d.v[840]-work1d.L[1299]*work1d.v[954]-work1d.L[1300]*work1d.v[955]-work1d.L[1301]*work1d.v[956]-work1d.L[1302]*work1d.v[957];
  work1d.d[958] = work1d.v[958];
  if (work1d.d[958] > 0)
    work1d.d[958] = -settings1d.kkt_reg;
  else
    work1d.d[958] -= settings1d.kkt_reg;
  work1d.d_inv[958] = 1/work1d.d[958];
  work1d.L[1305] = (-work1d.L[1303]*work1d.v[956]-work1d.L[1304]*work1d.v[957])*work1d.d_inv[958];
  work1d.L[1316] = (-work1d.L[1315]*work1d.v[957])*work1d.d_inv[958];
  work1d.L[1321] = (-work1d.L[1319]*work1d.v[840])*work1d.d_inv[958];
  work1d.v[956] = work1d.L[1303]*work1d.d[956];
  work1d.v[957] = work1d.L[1304]*work1d.d[957];
  work1d.v[958] = work1d.L[1305]*work1d.d[958];
  work1d.v[959] = 0-work1d.L[1303]*work1d.v[956]-work1d.L[1304]*work1d.v[957]-work1d.L[1305]*work1d.v[958];
  work1d.d[959] = work1d.v[959];
  if (work1d.d[959] > 0)
    work1d.d[959] = -settings1d.kkt_reg;
  else
    work1d.d[959] -= settings1d.kkt_reg;
  work1d.d_inv[959] = 1/work1d.d[959];
  work1d.L[1309] = (work1d.KKT[1893])*work1d.d_inv[959];
  work1d.L[1317] = (-work1d.L[1315]*work1d.v[957]-work1d.L[1316]*work1d.v[958])*work1d.d_inv[959];
  work1d.L[1322] = (-work1d.L[1321]*work1d.v[958])*work1d.d_inv[959];
  work1d.v[349] = work1d.L[1306]*work1d.d[349];
  work1d.v[560] = work1d.L[1307]*work1d.d[560];
  work1d.v[561] = work1d.L[1308]*work1d.d[561];
  work1d.v[959] = work1d.L[1309]*work1d.d[959];
  work1d.v[960] = work1d.KKT[1894]-work1d.L[1306]*work1d.v[349]-work1d.L[1307]*work1d.v[560]-work1d.L[1308]*work1d.v[561]-work1d.L[1309]*work1d.v[959];
  work1d.d[960] = work1d.v[960];
  if (work1d.d[960] < 0)
    work1d.d[960] = settings1d.kkt_reg;
  else
    work1d.d[960] += settings1d.kkt_reg;
  work1d.d_inv[960] = 1/work1d.d[960];
  work1d.L[1318] = (-work1d.L[1317]*work1d.v[959])*work1d.d_inv[960];
  work1d.L[1323] = (work1d.KKT[1895]-work1d.L[1322]*work1d.v[959])*work1d.d_inv[960];
  work1d.L[1325] = (work1d.KKT[1896])*work1d.d_inv[960];
  work1d.v[389] = work1d.L[1310]*work1d.d[389];
  work1d.v[721] = work1d.L[1311]*work1d.d[721];
  work1d.v[722] = work1d.L[1312]*work1d.d[722];
  work1d.v[798] = work1d.L[1313]*work1d.d[798];
  work1d.v[799] = work1d.L[1314]*work1d.d[799];
  work1d.v[957] = work1d.L[1315]*work1d.d[957];
  work1d.v[958] = work1d.L[1316]*work1d.d[958];
  work1d.v[959] = work1d.L[1317]*work1d.d[959];
  work1d.v[960] = work1d.L[1318]*work1d.d[960];
  work1d.v[961] = work1d.KKT[1897]-work1d.L[1310]*work1d.v[389]-work1d.L[1311]*work1d.v[721]-work1d.L[1312]*work1d.v[722]-work1d.L[1313]*work1d.v[798]-work1d.L[1314]*work1d.v[799]-work1d.L[1315]*work1d.v[957]-work1d.L[1316]*work1d.v[958]-work1d.L[1317]*work1d.v[959]-work1d.L[1318]*work1d.v[960];
  work1d.d[961] = work1d.v[961];
  if (work1d.d[961] < 0)
    work1d.d[961] = settings1d.kkt_reg;
  else
    work1d.d[961] += settings1d.kkt_reg;
  work1d.d_inv[961] = 1/work1d.d[961];
  work1d.L[1324] = (-work1d.L[1321]*work1d.v[958]-work1d.L[1322]*work1d.v[959]-work1d.L[1323]*work1d.v[960])*work1d.d_inv[961];
  work1d.L[1326] = (work1d.KKT[1898]-work1d.L[1325]*work1d.v[960])*work1d.d_inv[961];
  work1d.L[1337] = (-work1d.L[1335]*work1d.v[799])*work1d.d_inv[961];
  work1d.v[840] = work1d.L[1319]*work1d.d[840];
  work1d.v[841] = work1d.L[1320]*work1d.d[841];
  work1d.v[958] = work1d.L[1321]*work1d.d[958];
  work1d.v[959] = work1d.L[1322]*work1d.d[959];
  work1d.v[960] = work1d.L[1323]*work1d.d[960];
  work1d.v[961] = work1d.L[1324]*work1d.d[961];
  work1d.v[962] = 0-work1d.L[1319]*work1d.v[840]-work1d.L[1320]*work1d.v[841]-work1d.L[1321]*work1d.v[958]-work1d.L[1322]*work1d.v[959]-work1d.L[1323]*work1d.v[960]-work1d.L[1324]*work1d.v[961];
  work1d.d[962] = work1d.v[962];
  if (work1d.d[962] > 0)
    work1d.d[962] = -settings1d.kkt_reg;
  else
    work1d.d[962] -= settings1d.kkt_reg;
  work1d.d_inv[962] = 1/work1d.d[962];
  work1d.L[1327] = (-work1d.L[1325]*work1d.v[960]-work1d.L[1326]*work1d.v[961])*work1d.d_inv[962];
  work1d.L[1338] = (-work1d.L[1337]*work1d.v[961])*work1d.d_inv[962];
  work1d.L[1343] = (-work1d.L[1341]*work1d.v[841])*work1d.d_inv[962];
  work1d.v[960] = work1d.L[1325]*work1d.d[960];
  work1d.v[961] = work1d.L[1326]*work1d.d[961];
  work1d.v[962] = work1d.L[1327]*work1d.d[962];
  work1d.v[963] = 0-work1d.L[1325]*work1d.v[960]-work1d.L[1326]*work1d.v[961]-work1d.L[1327]*work1d.v[962];
  work1d.d[963] = work1d.v[963];
  if (work1d.d[963] > 0)
    work1d.d[963] = -settings1d.kkt_reg;
  else
    work1d.d[963] -= settings1d.kkt_reg;
  work1d.d_inv[963] = 1/work1d.d[963];
  work1d.L[1331] = (work1d.KKT[1899])*work1d.d_inv[963];
  work1d.L[1339] = (-work1d.L[1337]*work1d.v[961]-work1d.L[1338]*work1d.v[962])*work1d.d_inv[963];
  work1d.L[1344] = (-work1d.L[1343]*work1d.v[962])*work1d.d_inv[963];
  work1d.v[350] = work1d.L[1328]*work1d.d[350];
  work1d.v[564] = work1d.L[1329]*work1d.d[564];
  work1d.v[565] = work1d.L[1330]*work1d.d[565];
  work1d.v[963] = work1d.L[1331]*work1d.d[963];
  work1d.v[964] = work1d.KKT[1900]-work1d.L[1328]*work1d.v[350]-work1d.L[1329]*work1d.v[564]-work1d.L[1330]*work1d.v[565]-work1d.L[1331]*work1d.v[963];
  work1d.d[964] = work1d.v[964];
  if (work1d.d[964] < 0)
    work1d.d[964] = settings1d.kkt_reg;
  else
    work1d.d[964] += settings1d.kkt_reg;
  work1d.d_inv[964] = 1/work1d.d[964];
  work1d.L[1340] = (-work1d.L[1339]*work1d.v[963])*work1d.d_inv[964];
  work1d.L[1345] = (work1d.KKT[1901]-work1d.L[1344]*work1d.v[963])*work1d.d_inv[964];
  work1d.L[1347] = (work1d.KKT[1902])*work1d.d_inv[964];
  work1d.v[390] = work1d.L[1332]*work1d.d[390];
  work1d.v[725] = work1d.L[1333]*work1d.d[725];
  work1d.v[726] = work1d.L[1334]*work1d.d[726];
  work1d.v[799] = work1d.L[1335]*work1d.d[799];
  work1d.v[800] = work1d.L[1336]*work1d.d[800];
  work1d.v[961] = work1d.L[1337]*work1d.d[961];
  work1d.v[962] = work1d.L[1338]*work1d.d[962];
  work1d.v[963] = work1d.L[1339]*work1d.d[963];
  work1d.v[964] = work1d.L[1340]*work1d.d[964];
  work1d.v[965] = work1d.KKT[1903]-work1d.L[1332]*work1d.v[390]-work1d.L[1333]*work1d.v[725]-work1d.L[1334]*work1d.v[726]-work1d.L[1335]*work1d.v[799]-work1d.L[1336]*work1d.v[800]-work1d.L[1337]*work1d.v[961]-work1d.L[1338]*work1d.v[962]-work1d.L[1339]*work1d.v[963]-work1d.L[1340]*work1d.v[964];
  work1d.d[965] = work1d.v[965];
  if (work1d.d[965] < 0)
    work1d.d[965] = settings1d.kkt_reg;
  else
    work1d.d[965] += settings1d.kkt_reg;
  work1d.d_inv[965] = 1/work1d.d[965];
  work1d.L[1346] = (-work1d.L[1343]*work1d.v[962]-work1d.L[1344]*work1d.v[963]-work1d.L[1345]*work1d.v[964])*work1d.d_inv[965];
  work1d.L[1348] = (work1d.KKT[1904]-work1d.L[1347]*work1d.v[964])*work1d.d_inv[965];
  work1d.L[1359] = (-work1d.L[1357]*work1d.v[800])*work1d.d_inv[965];
  work1d.v[841] = work1d.L[1341]*work1d.d[841];
  work1d.v[842] = work1d.L[1342]*work1d.d[842];
  work1d.v[962] = work1d.L[1343]*work1d.d[962];
  work1d.v[963] = work1d.L[1344]*work1d.d[963];
  work1d.v[964] = work1d.L[1345]*work1d.d[964];
  work1d.v[965] = work1d.L[1346]*work1d.d[965];
  work1d.v[966] = 0-work1d.L[1341]*work1d.v[841]-work1d.L[1342]*work1d.v[842]-work1d.L[1343]*work1d.v[962]-work1d.L[1344]*work1d.v[963]-work1d.L[1345]*work1d.v[964]-work1d.L[1346]*work1d.v[965];
  work1d.d[966] = work1d.v[966];
  if (work1d.d[966] > 0)
    work1d.d[966] = -settings1d.kkt_reg;
  else
    work1d.d[966] -= settings1d.kkt_reg;
  work1d.d_inv[966] = 1/work1d.d[966];
  work1d.L[1349] = (-work1d.L[1347]*work1d.v[964]-work1d.L[1348]*work1d.v[965])*work1d.d_inv[966];
  work1d.L[1360] = (-work1d.L[1359]*work1d.v[965])*work1d.d_inv[966];
  work1d.L[1365] = (-work1d.L[1363]*work1d.v[842])*work1d.d_inv[966];
  work1d.v[964] = work1d.L[1347]*work1d.d[964];
  work1d.v[965] = work1d.L[1348]*work1d.d[965];
  work1d.v[966] = work1d.L[1349]*work1d.d[966];
  work1d.v[967] = 0-work1d.L[1347]*work1d.v[964]-work1d.L[1348]*work1d.v[965]-work1d.L[1349]*work1d.v[966];
  work1d.d[967] = work1d.v[967];
  if (work1d.d[967] > 0)
    work1d.d[967] = -settings1d.kkt_reg;
  else
    work1d.d[967] -= settings1d.kkt_reg;
  work1d.d_inv[967] = 1/work1d.d[967];
  work1d.L[1353] = (work1d.KKT[1905])*work1d.d_inv[967];
  work1d.L[1361] = (-work1d.L[1359]*work1d.v[965]-work1d.L[1360]*work1d.v[966])*work1d.d_inv[967];
  work1d.L[1366] = (-work1d.L[1365]*work1d.v[966])*work1d.d_inv[967];
  work1d.v[351] = work1d.L[1350]*work1d.d[351];
  work1d.v[568] = work1d.L[1351]*work1d.d[568];
  work1d.v[569] = work1d.L[1352]*work1d.d[569];
  work1d.v[967] = work1d.L[1353]*work1d.d[967];
  work1d.v[968] = work1d.KKT[1906]-work1d.L[1350]*work1d.v[351]-work1d.L[1351]*work1d.v[568]-work1d.L[1352]*work1d.v[569]-work1d.L[1353]*work1d.v[967];
  work1d.d[968] = work1d.v[968];
  if (work1d.d[968] < 0)
    work1d.d[968] = settings1d.kkt_reg;
  else
    work1d.d[968] += settings1d.kkt_reg;
  work1d.d_inv[968] = 1/work1d.d[968];
  work1d.L[1362] = (-work1d.L[1361]*work1d.v[967])*work1d.d_inv[968];
  work1d.L[1367] = (work1d.KKT[1907]-work1d.L[1366]*work1d.v[967])*work1d.d_inv[968];
  work1d.L[1369] = (work1d.KKT[1908])*work1d.d_inv[968];
  work1d.v[391] = work1d.L[1354]*work1d.d[391];
  work1d.v[729] = work1d.L[1355]*work1d.d[729];
  work1d.v[730] = work1d.L[1356]*work1d.d[730];
  work1d.v[800] = work1d.L[1357]*work1d.d[800];
  work1d.v[801] = work1d.L[1358]*work1d.d[801];
  work1d.v[965] = work1d.L[1359]*work1d.d[965];
  work1d.v[966] = work1d.L[1360]*work1d.d[966];
  work1d.v[967] = work1d.L[1361]*work1d.d[967];
  work1d.v[968] = work1d.L[1362]*work1d.d[968];
  work1d.v[969] = work1d.KKT[1909]-work1d.L[1354]*work1d.v[391]-work1d.L[1355]*work1d.v[729]-work1d.L[1356]*work1d.v[730]-work1d.L[1357]*work1d.v[800]-work1d.L[1358]*work1d.v[801]-work1d.L[1359]*work1d.v[965]-work1d.L[1360]*work1d.v[966]-work1d.L[1361]*work1d.v[967]-work1d.L[1362]*work1d.v[968];
  work1d.d[969] = work1d.v[969];
  if (work1d.d[969] < 0)
    work1d.d[969] = settings1d.kkt_reg;
  else
    work1d.d[969] += settings1d.kkt_reg;
  work1d.d_inv[969] = 1/work1d.d[969];
  work1d.L[1368] = (-work1d.L[1365]*work1d.v[966]-work1d.L[1366]*work1d.v[967]-work1d.L[1367]*work1d.v[968])*work1d.d_inv[969];
  work1d.L[1370] = (work1d.KKT[1910]-work1d.L[1369]*work1d.v[968])*work1d.d_inv[969];
  work1d.L[1381] = (-work1d.L[1379]*work1d.v[801])*work1d.d_inv[969];
  work1d.v[842] = work1d.L[1363]*work1d.d[842];
  work1d.v[843] = work1d.L[1364]*work1d.d[843];
  work1d.v[966] = work1d.L[1365]*work1d.d[966];
  work1d.v[967] = work1d.L[1366]*work1d.d[967];
  work1d.v[968] = work1d.L[1367]*work1d.d[968];
  work1d.v[969] = work1d.L[1368]*work1d.d[969];
  work1d.v[970] = 0-work1d.L[1363]*work1d.v[842]-work1d.L[1364]*work1d.v[843]-work1d.L[1365]*work1d.v[966]-work1d.L[1366]*work1d.v[967]-work1d.L[1367]*work1d.v[968]-work1d.L[1368]*work1d.v[969];
  work1d.d[970] = work1d.v[970];
  if (work1d.d[970] > 0)
    work1d.d[970] = -settings1d.kkt_reg;
  else
    work1d.d[970] -= settings1d.kkt_reg;
  work1d.d_inv[970] = 1/work1d.d[970];
  work1d.L[1371] = (-work1d.L[1369]*work1d.v[968]-work1d.L[1370]*work1d.v[969])*work1d.d_inv[970];
  work1d.L[1382] = (-work1d.L[1381]*work1d.v[969])*work1d.d_inv[970];
  work1d.L[1387] = (-work1d.L[1385]*work1d.v[843])*work1d.d_inv[970];
  work1d.v[968] = work1d.L[1369]*work1d.d[968];
  work1d.v[969] = work1d.L[1370]*work1d.d[969];
  work1d.v[970] = work1d.L[1371]*work1d.d[970];
  work1d.v[971] = 0-work1d.L[1369]*work1d.v[968]-work1d.L[1370]*work1d.v[969]-work1d.L[1371]*work1d.v[970];
  work1d.d[971] = work1d.v[971];
  if (work1d.d[971] > 0)
    work1d.d[971] = -settings1d.kkt_reg;
  else
    work1d.d[971] -= settings1d.kkt_reg;
  work1d.d_inv[971] = 1/work1d.d[971];
  work1d.L[1375] = (work1d.KKT[1911])*work1d.d_inv[971];
  work1d.L[1383] = (-work1d.L[1381]*work1d.v[969]-work1d.L[1382]*work1d.v[970])*work1d.d_inv[971];
  work1d.L[1388] = (-work1d.L[1387]*work1d.v[970])*work1d.d_inv[971];
  work1d.v[352] = work1d.L[1372]*work1d.d[352];
  work1d.v[572] = work1d.L[1373]*work1d.d[572];
  work1d.v[573] = work1d.L[1374]*work1d.d[573];
  work1d.v[971] = work1d.L[1375]*work1d.d[971];
  work1d.v[972] = work1d.KKT[1912]-work1d.L[1372]*work1d.v[352]-work1d.L[1373]*work1d.v[572]-work1d.L[1374]*work1d.v[573]-work1d.L[1375]*work1d.v[971];
  work1d.d[972] = work1d.v[972];
  if (work1d.d[972] < 0)
    work1d.d[972] = settings1d.kkt_reg;
  else
    work1d.d[972] += settings1d.kkt_reg;
  work1d.d_inv[972] = 1/work1d.d[972];
  work1d.L[1384] = (-work1d.L[1383]*work1d.v[971])*work1d.d_inv[972];
  work1d.L[1389] = (work1d.KKT[1913]-work1d.L[1388]*work1d.v[971])*work1d.d_inv[972];
  work1d.L[1391] = (work1d.KKT[1914])*work1d.d_inv[972];
  work1d.v[392] = work1d.L[1376]*work1d.d[392];
  work1d.v[733] = work1d.L[1377]*work1d.d[733];
  work1d.v[734] = work1d.L[1378]*work1d.d[734];
  work1d.v[801] = work1d.L[1379]*work1d.d[801];
  work1d.v[802] = work1d.L[1380]*work1d.d[802];
  work1d.v[969] = work1d.L[1381]*work1d.d[969];
  work1d.v[970] = work1d.L[1382]*work1d.d[970];
  work1d.v[971] = work1d.L[1383]*work1d.d[971];
  work1d.v[972] = work1d.L[1384]*work1d.d[972];
  work1d.v[973] = work1d.KKT[1915]-work1d.L[1376]*work1d.v[392]-work1d.L[1377]*work1d.v[733]-work1d.L[1378]*work1d.v[734]-work1d.L[1379]*work1d.v[801]-work1d.L[1380]*work1d.v[802]-work1d.L[1381]*work1d.v[969]-work1d.L[1382]*work1d.v[970]-work1d.L[1383]*work1d.v[971]-work1d.L[1384]*work1d.v[972];
  work1d.d[973] = work1d.v[973];
  if (work1d.d[973] < 0)
    work1d.d[973] = settings1d.kkt_reg;
  else
    work1d.d[973] += settings1d.kkt_reg;
  work1d.d_inv[973] = 1/work1d.d[973];
  work1d.L[1390] = (-work1d.L[1387]*work1d.v[970]-work1d.L[1388]*work1d.v[971]-work1d.L[1389]*work1d.v[972])*work1d.d_inv[973];
  work1d.L[1392] = (work1d.KKT[1916]-work1d.L[1391]*work1d.v[972])*work1d.d_inv[973];
  work1d.L[1403] = (-work1d.L[1401]*work1d.v[802])*work1d.d_inv[973];
  work1d.v[843] = work1d.L[1385]*work1d.d[843];
  work1d.v[844] = work1d.L[1386]*work1d.d[844];
  work1d.v[970] = work1d.L[1387]*work1d.d[970];
  work1d.v[971] = work1d.L[1388]*work1d.d[971];
  work1d.v[972] = work1d.L[1389]*work1d.d[972];
  work1d.v[973] = work1d.L[1390]*work1d.d[973];
  work1d.v[974] = 0-work1d.L[1385]*work1d.v[843]-work1d.L[1386]*work1d.v[844]-work1d.L[1387]*work1d.v[970]-work1d.L[1388]*work1d.v[971]-work1d.L[1389]*work1d.v[972]-work1d.L[1390]*work1d.v[973];
  work1d.d[974] = work1d.v[974];
  if (work1d.d[974] > 0)
    work1d.d[974] = -settings1d.kkt_reg;
  else
    work1d.d[974] -= settings1d.kkt_reg;
  work1d.d_inv[974] = 1/work1d.d[974];
  work1d.L[1393] = (-work1d.L[1391]*work1d.v[972]-work1d.L[1392]*work1d.v[973])*work1d.d_inv[974];
  work1d.L[1404] = (-work1d.L[1403]*work1d.v[973])*work1d.d_inv[974];
  work1d.L[1409] = (-work1d.L[1407]*work1d.v[844])*work1d.d_inv[974];
  work1d.v[972] = work1d.L[1391]*work1d.d[972];
  work1d.v[973] = work1d.L[1392]*work1d.d[973];
  work1d.v[974] = work1d.L[1393]*work1d.d[974];
  work1d.v[975] = 0-work1d.L[1391]*work1d.v[972]-work1d.L[1392]*work1d.v[973]-work1d.L[1393]*work1d.v[974];
  work1d.d[975] = work1d.v[975];
  if (work1d.d[975] > 0)
    work1d.d[975] = -settings1d.kkt_reg;
  else
    work1d.d[975] -= settings1d.kkt_reg;
  work1d.d_inv[975] = 1/work1d.d[975];
  work1d.L[1397] = (work1d.KKT[1917])*work1d.d_inv[975];
  work1d.L[1405] = (-work1d.L[1403]*work1d.v[973]-work1d.L[1404]*work1d.v[974])*work1d.d_inv[975];
  work1d.L[1410] = (-work1d.L[1409]*work1d.v[974])*work1d.d_inv[975];
  work1d.v[353] = work1d.L[1394]*work1d.d[353];
  work1d.v[576] = work1d.L[1395]*work1d.d[576];
  work1d.v[577] = work1d.L[1396]*work1d.d[577];
  work1d.v[975] = work1d.L[1397]*work1d.d[975];
  work1d.v[976] = work1d.KKT[1918]-work1d.L[1394]*work1d.v[353]-work1d.L[1395]*work1d.v[576]-work1d.L[1396]*work1d.v[577]-work1d.L[1397]*work1d.v[975];
  work1d.d[976] = work1d.v[976];
  if (work1d.d[976] < 0)
    work1d.d[976] = settings1d.kkt_reg;
  else
    work1d.d[976] += settings1d.kkt_reg;
  work1d.d_inv[976] = 1/work1d.d[976];
  work1d.L[1406] = (-work1d.L[1405]*work1d.v[975])*work1d.d_inv[976];
  work1d.L[1411] = (work1d.KKT[1919]-work1d.L[1410]*work1d.v[975])*work1d.d_inv[976];
  work1d.L[1413] = (work1d.KKT[1920])*work1d.d_inv[976];
  work1d.v[393] = work1d.L[1398]*work1d.d[393];
  work1d.v[737] = work1d.L[1399]*work1d.d[737];
  work1d.v[738] = work1d.L[1400]*work1d.d[738];
  work1d.v[802] = work1d.L[1401]*work1d.d[802];
  work1d.v[803] = work1d.L[1402]*work1d.d[803];
  work1d.v[973] = work1d.L[1403]*work1d.d[973];
  work1d.v[974] = work1d.L[1404]*work1d.d[974];
  work1d.v[975] = work1d.L[1405]*work1d.d[975];
  work1d.v[976] = work1d.L[1406]*work1d.d[976];
  work1d.v[977] = work1d.KKT[1921]-work1d.L[1398]*work1d.v[393]-work1d.L[1399]*work1d.v[737]-work1d.L[1400]*work1d.v[738]-work1d.L[1401]*work1d.v[802]-work1d.L[1402]*work1d.v[803]-work1d.L[1403]*work1d.v[973]-work1d.L[1404]*work1d.v[974]-work1d.L[1405]*work1d.v[975]-work1d.L[1406]*work1d.v[976];
  work1d.d[977] = work1d.v[977];
  if (work1d.d[977] < 0)
    work1d.d[977] = settings1d.kkt_reg;
  else
    work1d.d[977] += settings1d.kkt_reg;
  work1d.d_inv[977] = 1/work1d.d[977];
  work1d.L[1412] = (-work1d.L[1409]*work1d.v[974]-work1d.L[1410]*work1d.v[975]-work1d.L[1411]*work1d.v[976])*work1d.d_inv[977];
  work1d.L[1414] = (work1d.KKT[1922]-work1d.L[1413]*work1d.v[976])*work1d.d_inv[977];
  work1d.L[1425] = (-work1d.L[1423]*work1d.v[803])*work1d.d_inv[977];
  work1d.v[844] = work1d.L[1407]*work1d.d[844];
  work1d.v[845] = work1d.L[1408]*work1d.d[845];
  work1d.v[974] = work1d.L[1409]*work1d.d[974];
  work1d.v[975] = work1d.L[1410]*work1d.d[975];
  work1d.v[976] = work1d.L[1411]*work1d.d[976];
  work1d.v[977] = work1d.L[1412]*work1d.d[977];
  work1d.v[978] = 0-work1d.L[1407]*work1d.v[844]-work1d.L[1408]*work1d.v[845]-work1d.L[1409]*work1d.v[974]-work1d.L[1410]*work1d.v[975]-work1d.L[1411]*work1d.v[976]-work1d.L[1412]*work1d.v[977];
  work1d.d[978] = work1d.v[978];
  if (work1d.d[978] > 0)
    work1d.d[978] = -settings1d.kkt_reg;
  else
    work1d.d[978] -= settings1d.kkt_reg;
  work1d.d_inv[978] = 1/work1d.d[978];
  work1d.L[1415] = (-work1d.L[1413]*work1d.v[976]-work1d.L[1414]*work1d.v[977])*work1d.d_inv[978];
  work1d.L[1426] = (-work1d.L[1425]*work1d.v[977])*work1d.d_inv[978];
  work1d.L[1431] = (-work1d.L[1429]*work1d.v[845])*work1d.d_inv[978];
  work1d.v[976] = work1d.L[1413]*work1d.d[976];
  work1d.v[977] = work1d.L[1414]*work1d.d[977];
  work1d.v[978] = work1d.L[1415]*work1d.d[978];
  work1d.v[979] = 0-work1d.L[1413]*work1d.v[976]-work1d.L[1414]*work1d.v[977]-work1d.L[1415]*work1d.v[978];
  work1d.d[979] = work1d.v[979];
  if (work1d.d[979] > 0)
    work1d.d[979] = -settings1d.kkt_reg;
  else
    work1d.d[979] -= settings1d.kkt_reg;
  work1d.d_inv[979] = 1/work1d.d[979];
  work1d.L[1419] = (work1d.KKT[1923])*work1d.d_inv[979];
  work1d.L[1427] = (-work1d.L[1425]*work1d.v[977]-work1d.L[1426]*work1d.v[978])*work1d.d_inv[979];
  work1d.L[1432] = (-work1d.L[1431]*work1d.v[978])*work1d.d_inv[979];
  work1d.v[354] = work1d.L[1416]*work1d.d[354];
  work1d.v[580] = work1d.L[1417]*work1d.d[580];
  work1d.v[581] = work1d.L[1418]*work1d.d[581];
  work1d.v[979] = work1d.L[1419]*work1d.d[979];
  work1d.v[980] = work1d.KKT[1924]-work1d.L[1416]*work1d.v[354]-work1d.L[1417]*work1d.v[580]-work1d.L[1418]*work1d.v[581]-work1d.L[1419]*work1d.v[979];
  work1d.d[980] = work1d.v[980];
  if (work1d.d[980] < 0)
    work1d.d[980] = settings1d.kkt_reg;
  else
    work1d.d[980] += settings1d.kkt_reg;
  work1d.d_inv[980] = 1/work1d.d[980];
  work1d.L[1428] = (-work1d.L[1427]*work1d.v[979])*work1d.d_inv[980];
  work1d.L[1433] = (work1d.KKT[1925]-work1d.L[1432]*work1d.v[979])*work1d.d_inv[980];
  work1d.L[1435] = (work1d.KKT[1926])*work1d.d_inv[980];
  work1d.v[394] = work1d.L[1420]*work1d.d[394];
  work1d.v[741] = work1d.L[1421]*work1d.d[741];
  work1d.v[742] = work1d.L[1422]*work1d.d[742];
  work1d.v[803] = work1d.L[1423]*work1d.d[803];
  work1d.v[804] = work1d.L[1424]*work1d.d[804];
  work1d.v[977] = work1d.L[1425]*work1d.d[977];
  work1d.v[978] = work1d.L[1426]*work1d.d[978];
  work1d.v[979] = work1d.L[1427]*work1d.d[979];
  work1d.v[980] = work1d.L[1428]*work1d.d[980];
  work1d.v[981] = work1d.KKT[1927]-work1d.L[1420]*work1d.v[394]-work1d.L[1421]*work1d.v[741]-work1d.L[1422]*work1d.v[742]-work1d.L[1423]*work1d.v[803]-work1d.L[1424]*work1d.v[804]-work1d.L[1425]*work1d.v[977]-work1d.L[1426]*work1d.v[978]-work1d.L[1427]*work1d.v[979]-work1d.L[1428]*work1d.v[980];
  work1d.d[981] = work1d.v[981];
  if (work1d.d[981] < 0)
    work1d.d[981] = settings1d.kkt_reg;
  else
    work1d.d[981] += settings1d.kkt_reg;
  work1d.d_inv[981] = 1/work1d.d[981];
  work1d.L[1434] = (-work1d.L[1431]*work1d.v[978]-work1d.L[1432]*work1d.v[979]-work1d.L[1433]*work1d.v[980])*work1d.d_inv[981];
  work1d.L[1436] = (work1d.KKT[1928]-work1d.L[1435]*work1d.v[980])*work1d.d_inv[981];
  work1d.L[1447] = (-work1d.L[1445]*work1d.v[804])*work1d.d_inv[981];
  work1d.v[845] = work1d.L[1429]*work1d.d[845];
  work1d.v[846] = work1d.L[1430]*work1d.d[846];
  work1d.v[978] = work1d.L[1431]*work1d.d[978];
  work1d.v[979] = work1d.L[1432]*work1d.d[979];
  work1d.v[980] = work1d.L[1433]*work1d.d[980];
  work1d.v[981] = work1d.L[1434]*work1d.d[981];
  work1d.v[982] = 0-work1d.L[1429]*work1d.v[845]-work1d.L[1430]*work1d.v[846]-work1d.L[1431]*work1d.v[978]-work1d.L[1432]*work1d.v[979]-work1d.L[1433]*work1d.v[980]-work1d.L[1434]*work1d.v[981];
  work1d.d[982] = work1d.v[982];
  if (work1d.d[982] > 0)
    work1d.d[982] = -settings1d.kkt_reg;
  else
    work1d.d[982] -= settings1d.kkt_reg;
  work1d.d_inv[982] = 1/work1d.d[982];
  work1d.L[1437] = (-work1d.L[1435]*work1d.v[980]-work1d.L[1436]*work1d.v[981])*work1d.d_inv[982];
  work1d.L[1448] = (-work1d.L[1447]*work1d.v[981])*work1d.d_inv[982];
  work1d.L[1453] = (-work1d.L[1451]*work1d.v[846])*work1d.d_inv[982];
  work1d.v[980] = work1d.L[1435]*work1d.d[980];
  work1d.v[981] = work1d.L[1436]*work1d.d[981];
  work1d.v[982] = work1d.L[1437]*work1d.d[982];
  work1d.v[983] = 0-work1d.L[1435]*work1d.v[980]-work1d.L[1436]*work1d.v[981]-work1d.L[1437]*work1d.v[982];
  work1d.d[983] = work1d.v[983];
  if (work1d.d[983] > 0)
    work1d.d[983] = -settings1d.kkt_reg;
  else
    work1d.d[983] -= settings1d.kkt_reg;
  work1d.d_inv[983] = 1/work1d.d[983];
  work1d.L[1441] = (work1d.KKT[1929])*work1d.d_inv[983];
  work1d.L[1449] = (-work1d.L[1447]*work1d.v[981]-work1d.L[1448]*work1d.v[982])*work1d.d_inv[983];
  work1d.L[1454] = (-work1d.L[1453]*work1d.v[982])*work1d.d_inv[983];
  work1d.v[355] = work1d.L[1438]*work1d.d[355];
  work1d.v[584] = work1d.L[1439]*work1d.d[584];
  work1d.v[585] = work1d.L[1440]*work1d.d[585];
  work1d.v[983] = work1d.L[1441]*work1d.d[983];
  work1d.v[984] = work1d.KKT[1930]-work1d.L[1438]*work1d.v[355]-work1d.L[1439]*work1d.v[584]-work1d.L[1440]*work1d.v[585]-work1d.L[1441]*work1d.v[983];
  work1d.d[984] = work1d.v[984];
  if (work1d.d[984] < 0)
    work1d.d[984] = settings1d.kkt_reg;
  else
    work1d.d[984] += settings1d.kkt_reg;
  work1d.d_inv[984] = 1/work1d.d[984];
  work1d.L[1450] = (-work1d.L[1449]*work1d.v[983])*work1d.d_inv[984];
  work1d.L[1455] = (work1d.KKT[1931]-work1d.L[1454]*work1d.v[983])*work1d.d_inv[984];
  work1d.L[1457] = (work1d.KKT[1932])*work1d.d_inv[984];
  work1d.v[395] = work1d.L[1442]*work1d.d[395];
  work1d.v[745] = work1d.L[1443]*work1d.d[745];
  work1d.v[746] = work1d.L[1444]*work1d.d[746];
  work1d.v[804] = work1d.L[1445]*work1d.d[804];
  work1d.v[805] = work1d.L[1446]*work1d.d[805];
  work1d.v[981] = work1d.L[1447]*work1d.d[981];
  work1d.v[982] = work1d.L[1448]*work1d.d[982];
  work1d.v[983] = work1d.L[1449]*work1d.d[983];
  work1d.v[984] = work1d.L[1450]*work1d.d[984];
  work1d.v[985] = work1d.KKT[1933]-work1d.L[1442]*work1d.v[395]-work1d.L[1443]*work1d.v[745]-work1d.L[1444]*work1d.v[746]-work1d.L[1445]*work1d.v[804]-work1d.L[1446]*work1d.v[805]-work1d.L[1447]*work1d.v[981]-work1d.L[1448]*work1d.v[982]-work1d.L[1449]*work1d.v[983]-work1d.L[1450]*work1d.v[984];
  work1d.d[985] = work1d.v[985];
  if (work1d.d[985] < 0)
    work1d.d[985] = settings1d.kkt_reg;
  else
    work1d.d[985] += settings1d.kkt_reg;
  work1d.d_inv[985] = 1/work1d.d[985];
  work1d.L[1456] = (-work1d.L[1453]*work1d.v[982]-work1d.L[1454]*work1d.v[983]-work1d.L[1455]*work1d.v[984])*work1d.d_inv[985];
  work1d.L[1458] = (work1d.KKT[1934]-work1d.L[1457]*work1d.v[984])*work1d.d_inv[985];
  work1d.L[1469] = (-work1d.L[1467]*work1d.v[805])*work1d.d_inv[985];
  work1d.v[846] = work1d.L[1451]*work1d.d[846];
  work1d.v[847] = work1d.L[1452]*work1d.d[847];
  work1d.v[982] = work1d.L[1453]*work1d.d[982];
  work1d.v[983] = work1d.L[1454]*work1d.d[983];
  work1d.v[984] = work1d.L[1455]*work1d.d[984];
  work1d.v[985] = work1d.L[1456]*work1d.d[985];
  work1d.v[986] = 0-work1d.L[1451]*work1d.v[846]-work1d.L[1452]*work1d.v[847]-work1d.L[1453]*work1d.v[982]-work1d.L[1454]*work1d.v[983]-work1d.L[1455]*work1d.v[984]-work1d.L[1456]*work1d.v[985];
  work1d.d[986] = work1d.v[986];
  if (work1d.d[986] > 0)
    work1d.d[986] = -settings1d.kkt_reg;
  else
    work1d.d[986] -= settings1d.kkt_reg;
  work1d.d_inv[986] = 1/work1d.d[986];
  work1d.L[1459] = (-work1d.L[1457]*work1d.v[984]-work1d.L[1458]*work1d.v[985])*work1d.d_inv[986];
  work1d.L[1470] = (-work1d.L[1469]*work1d.v[985])*work1d.d_inv[986];
  work1d.L[1475] = (-work1d.L[1473]*work1d.v[847])*work1d.d_inv[986];
  work1d.v[984] = work1d.L[1457]*work1d.d[984];
  work1d.v[985] = work1d.L[1458]*work1d.d[985];
  work1d.v[986] = work1d.L[1459]*work1d.d[986];
  work1d.v[987] = 0-work1d.L[1457]*work1d.v[984]-work1d.L[1458]*work1d.v[985]-work1d.L[1459]*work1d.v[986];
  work1d.d[987] = work1d.v[987];
  if (work1d.d[987] > 0)
    work1d.d[987] = -settings1d.kkt_reg;
  else
    work1d.d[987] -= settings1d.kkt_reg;
  work1d.d_inv[987] = 1/work1d.d[987];
  work1d.L[1463] = (work1d.KKT[1935])*work1d.d_inv[987];
  work1d.L[1471] = (-work1d.L[1469]*work1d.v[985]-work1d.L[1470]*work1d.v[986])*work1d.d_inv[987];
  work1d.L[1476] = (-work1d.L[1475]*work1d.v[986])*work1d.d_inv[987];
  work1d.v[356] = work1d.L[1460]*work1d.d[356];
  work1d.v[588] = work1d.L[1461]*work1d.d[588];
  work1d.v[589] = work1d.L[1462]*work1d.d[589];
  work1d.v[987] = work1d.L[1463]*work1d.d[987];
  work1d.v[988] = work1d.KKT[1936]-work1d.L[1460]*work1d.v[356]-work1d.L[1461]*work1d.v[588]-work1d.L[1462]*work1d.v[589]-work1d.L[1463]*work1d.v[987];
  work1d.d[988] = work1d.v[988];
  if (work1d.d[988] < 0)
    work1d.d[988] = settings1d.kkt_reg;
  else
    work1d.d[988] += settings1d.kkt_reg;
  work1d.d_inv[988] = 1/work1d.d[988];
  work1d.L[1472] = (-work1d.L[1471]*work1d.v[987])*work1d.d_inv[988];
  work1d.L[1477] = (work1d.KKT[1937]-work1d.L[1476]*work1d.v[987])*work1d.d_inv[988];
  work1d.L[1479] = (work1d.KKT[1938])*work1d.d_inv[988];
  work1d.v[396] = work1d.L[1464]*work1d.d[396];
  work1d.v[749] = work1d.L[1465]*work1d.d[749];
  work1d.v[750] = work1d.L[1466]*work1d.d[750];
  work1d.v[805] = work1d.L[1467]*work1d.d[805];
  work1d.v[806] = work1d.L[1468]*work1d.d[806];
  work1d.v[985] = work1d.L[1469]*work1d.d[985];
  work1d.v[986] = work1d.L[1470]*work1d.d[986];
  work1d.v[987] = work1d.L[1471]*work1d.d[987];
  work1d.v[988] = work1d.L[1472]*work1d.d[988];
  work1d.v[989] = work1d.KKT[1939]-work1d.L[1464]*work1d.v[396]-work1d.L[1465]*work1d.v[749]-work1d.L[1466]*work1d.v[750]-work1d.L[1467]*work1d.v[805]-work1d.L[1468]*work1d.v[806]-work1d.L[1469]*work1d.v[985]-work1d.L[1470]*work1d.v[986]-work1d.L[1471]*work1d.v[987]-work1d.L[1472]*work1d.v[988];
  work1d.d[989] = work1d.v[989];
  if (work1d.d[989] < 0)
    work1d.d[989] = settings1d.kkt_reg;
  else
    work1d.d[989] += settings1d.kkt_reg;
  work1d.d_inv[989] = 1/work1d.d[989];
  work1d.L[1478] = (-work1d.L[1475]*work1d.v[986]-work1d.L[1476]*work1d.v[987]-work1d.L[1477]*work1d.v[988])*work1d.d_inv[989];
  work1d.L[1480] = (work1d.KKT[1940]-work1d.L[1479]*work1d.v[988])*work1d.d_inv[989];
  work1d.L[1491] = (-work1d.L[1489]*work1d.v[806])*work1d.d_inv[989];
  work1d.v[847] = work1d.L[1473]*work1d.d[847];
  work1d.v[848] = work1d.L[1474]*work1d.d[848];
  work1d.v[986] = work1d.L[1475]*work1d.d[986];
  work1d.v[987] = work1d.L[1476]*work1d.d[987];
  work1d.v[988] = work1d.L[1477]*work1d.d[988];
  work1d.v[989] = work1d.L[1478]*work1d.d[989];
  work1d.v[990] = 0-work1d.L[1473]*work1d.v[847]-work1d.L[1474]*work1d.v[848]-work1d.L[1475]*work1d.v[986]-work1d.L[1476]*work1d.v[987]-work1d.L[1477]*work1d.v[988]-work1d.L[1478]*work1d.v[989];
  work1d.d[990] = work1d.v[990];
  if (work1d.d[990] > 0)
    work1d.d[990] = -settings1d.kkt_reg;
  else
    work1d.d[990] -= settings1d.kkt_reg;
  work1d.d_inv[990] = 1/work1d.d[990];
  work1d.L[1481] = (-work1d.L[1479]*work1d.v[988]-work1d.L[1480]*work1d.v[989])*work1d.d_inv[990];
  work1d.L[1492] = (-work1d.L[1491]*work1d.v[989])*work1d.d_inv[990];
  work1d.L[1497] = (-work1d.L[1495]*work1d.v[848])*work1d.d_inv[990];
  work1d.v[988] = work1d.L[1479]*work1d.d[988];
  work1d.v[989] = work1d.L[1480]*work1d.d[989];
  work1d.v[990] = work1d.L[1481]*work1d.d[990];
  work1d.v[991] = 0-work1d.L[1479]*work1d.v[988]-work1d.L[1480]*work1d.v[989]-work1d.L[1481]*work1d.v[990];
  work1d.d[991] = work1d.v[991];
  if (work1d.d[991] > 0)
    work1d.d[991] = -settings1d.kkt_reg;
  else
    work1d.d[991] -= settings1d.kkt_reg;
  work1d.d_inv[991] = 1/work1d.d[991];
  work1d.L[1485] = (work1d.KKT[1941])*work1d.d_inv[991];
  work1d.L[1493] = (-work1d.L[1491]*work1d.v[989]-work1d.L[1492]*work1d.v[990])*work1d.d_inv[991];
  work1d.L[1498] = (-work1d.L[1497]*work1d.v[990])*work1d.d_inv[991];
  work1d.v[357] = work1d.L[1482]*work1d.d[357];
  work1d.v[592] = work1d.L[1483]*work1d.d[592];
  work1d.v[593] = work1d.L[1484]*work1d.d[593];
  work1d.v[991] = work1d.L[1485]*work1d.d[991];
  work1d.v[992] = work1d.KKT[1942]-work1d.L[1482]*work1d.v[357]-work1d.L[1483]*work1d.v[592]-work1d.L[1484]*work1d.v[593]-work1d.L[1485]*work1d.v[991];
  work1d.d[992] = work1d.v[992];
  if (work1d.d[992] < 0)
    work1d.d[992] = settings1d.kkt_reg;
  else
    work1d.d[992] += settings1d.kkt_reg;
  work1d.d_inv[992] = 1/work1d.d[992];
  work1d.L[1494] = (-work1d.L[1493]*work1d.v[991])*work1d.d_inv[992];
  work1d.L[1499] = (work1d.KKT[1943]-work1d.L[1498]*work1d.v[991])*work1d.d_inv[992];
  work1d.L[1501] = (work1d.KKT[1944])*work1d.d_inv[992];
  work1d.v[397] = work1d.L[1486]*work1d.d[397];
  work1d.v[753] = work1d.L[1487]*work1d.d[753];
  work1d.v[754] = work1d.L[1488]*work1d.d[754];
  work1d.v[806] = work1d.L[1489]*work1d.d[806];
  work1d.v[807] = work1d.L[1490]*work1d.d[807];
  work1d.v[989] = work1d.L[1491]*work1d.d[989];
  work1d.v[990] = work1d.L[1492]*work1d.d[990];
  work1d.v[991] = work1d.L[1493]*work1d.d[991];
  work1d.v[992] = work1d.L[1494]*work1d.d[992];
  work1d.v[993] = work1d.KKT[1945]-work1d.L[1486]*work1d.v[397]-work1d.L[1487]*work1d.v[753]-work1d.L[1488]*work1d.v[754]-work1d.L[1489]*work1d.v[806]-work1d.L[1490]*work1d.v[807]-work1d.L[1491]*work1d.v[989]-work1d.L[1492]*work1d.v[990]-work1d.L[1493]*work1d.v[991]-work1d.L[1494]*work1d.v[992];
  work1d.d[993] = work1d.v[993];
  if (work1d.d[993] < 0)
    work1d.d[993] = settings1d.kkt_reg;
  else
    work1d.d[993] += settings1d.kkt_reg;
  work1d.d_inv[993] = 1/work1d.d[993];
  work1d.L[1500] = (-work1d.L[1497]*work1d.v[990]-work1d.L[1498]*work1d.v[991]-work1d.L[1499]*work1d.v[992])*work1d.d_inv[993];
  work1d.L[1502] = (work1d.KKT[1946]-work1d.L[1501]*work1d.v[992])*work1d.d_inv[993];
  work1d.L[1520] = (-work1d.L[1517]*work1d.v[807])*work1d.d_inv[993];
  work1d.v[848] = work1d.L[1495]*work1d.d[848];
  work1d.v[849] = work1d.L[1496]*work1d.d[849];
  work1d.v[990] = work1d.L[1497]*work1d.d[990];
  work1d.v[991] = work1d.L[1498]*work1d.d[991];
  work1d.v[992] = work1d.L[1499]*work1d.d[992];
  work1d.v[993] = work1d.L[1500]*work1d.d[993];
  work1d.v[994] = 0-work1d.L[1495]*work1d.v[848]-work1d.L[1496]*work1d.v[849]-work1d.L[1497]*work1d.v[990]-work1d.L[1498]*work1d.v[991]-work1d.L[1499]*work1d.v[992]-work1d.L[1500]*work1d.v[993];
  work1d.d[994] = work1d.v[994];
  if (work1d.d[994] > 0)
    work1d.d[994] = -settings1d.kkt_reg;
  else
    work1d.d[994] -= settings1d.kkt_reg;
  work1d.d_inv[994] = 1/work1d.d[994];
  work1d.L[1503] = (-work1d.L[1501]*work1d.v[992]-work1d.L[1502]*work1d.v[993])*work1d.d_inv[994];
  work1d.L[1506] = (-work1d.L[1504]*work1d.v[849])*work1d.d_inv[994];
  work1d.L[1521] = (-work1d.L[1520]*work1d.v[993])*work1d.d_inv[994];
  work1d.v[992] = work1d.L[1501]*work1d.d[992];
  work1d.v[993] = work1d.L[1502]*work1d.d[993];
  work1d.v[994] = work1d.L[1503]*work1d.d[994];
  work1d.v[995] = 0-work1d.L[1501]*work1d.v[992]-work1d.L[1502]*work1d.v[993]-work1d.L[1503]*work1d.v[994];
  work1d.d[995] = work1d.v[995];
  if (work1d.d[995] > 0)
    work1d.d[995] = -settings1d.kkt_reg;
  else
    work1d.d[995] -= settings1d.kkt_reg;
  work1d.d_inv[995] = 1/work1d.d[995];
  work1d.L[1507] = (-work1d.L[1506]*work1d.v[994])*work1d.d_inv[995];
  work1d.L[1511] = (work1d.KKT[1947])*work1d.d_inv[995];
  work1d.L[1522] = (-work1d.L[1520]*work1d.v[993]-work1d.L[1521]*work1d.v[994])*work1d.d_inv[995];
  work1d.v[849] = work1d.L[1504]*work1d.d[849];
  work1d.v[850] = work1d.L[1505]*work1d.d[850];
  work1d.v[994] = work1d.L[1506]*work1d.d[994];
  work1d.v[995] = work1d.L[1507]*work1d.d[995];
  work1d.v[996] = 0-work1d.L[1504]*work1d.v[849]-work1d.L[1505]*work1d.v[850]-work1d.L[1506]*work1d.v[994]-work1d.L[1507]*work1d.v[995];
  work1d.d[996] = work1d.v[996];
  if (work1d.d[996] > 0)
    work1d.d[996] = -settings1d.kkt_reg;
  else
    work1d.d[996] -= settings1d.kkt_reg;
  work1d.d_inv[996] = 1/work1d.d[996];
  work1d.L[1512] = (work1d.KKT[1948]-work1d.L[1511]*work1d.v[995])*work1d.d_inv[996];
  work1d.L[1523] = (-work1d.L[1521]*work1d.v[994]-work1d.L[1522]*work1d.v[995])*work1d.d_inv[996];
  work1d.L[1532] = (-work1d.L[1531]*work1d.v[850])*work1d.d_inv[996];
  work1d.v[997] = 0;
  work1d.d[997] = work1d.v[997];
  if (work1d.d[997] > 0)
    work1d.d[997] = -settings1d.kkt_reg;
  else
    work1d.d[997] -= settings1d.kkt_reg;
  work1d.d_inv[997] = 1/work1d.d[997];
  work1d.L[1513] = (work1d.KKT[1949])*work1d.d_inv[997];
  work1d.L[1524] = (work1d.KKT[1950])*work1d.d_inv[997];
  work1d.L[1533] = (work1d.KKT[1951])*work1d.d_inv[997];
  work1d.v[358] = work1d.L[1508]*work1d.d[358];
  work1d.v[596] = work1d.L[1509]*work1d.d[596];
  work1d.v[597] = work1d.L[1510]*work1d.d[597];
  work1d.v[995] = work1d.L[1511]*work1d.d[995];
  work1d.v[996] = work1d.L[1512]*work1d.d[996];
  work1d.v[997] = work1d.L[1513]*work1d.d[997];
  work1d.v[998] = work1d.KKT[1952]-work1d.L[1508]*work1d.v[358]-work1d.L[1509]*work1d.v[596]-work1d.L[1510]*work1d.v[597]-work1d.L[1511]*work1d.v[995]-work1d.L[1512]*work1d.v[996]-work1d.L[1513]*work1d.v[997];
  work1d.d[998] = work1d.v[998];
  if (work1d.d[998] < 0)
    work1d.d[998] = settings1d.kkt_reg;
  else
    work1d.d[998] += settings1d.kkt_reg;
  work1d.d_inv[998] = 1/work1d.d[998];
  work1d.L[1525] = (-work1d.L[1522]*work1d.v[995]-work1d.L[1523]*work1d.v[996]-work1d.L[1524]*work1d.v[997])*work1d.d_inv[998];
  work1d.L[1534] = (-work1d.L[1532]*work1d.v[996]-work1d.L[1533]*work1d.v[997])*work1d.d_inv[998];
  work1d.v[398] = work1d.L[1514]*work1d.d[398];
  work1d.v[757] = work1d.L[1515]*work1d.d[757];
  work1d.v[758] = work1d.L[1516]*work1d.d[758];
  work1d.v[807] = work1d.L[1517]*work1d.d[807];
  work1d.v[808] = work1d.L[1518]*work1d.d[808];
  work1d.v[810] = work1d.L[1519]*work1d.d[810];
  work1d.v[993] = work1d.L[1520]*work1d.d[993];
  work1d.v[994] = work1d.L[1521]*work1d.d[994];
  work1d.v[995] = work1d.L[1522]*work1d.d[995];
  work1d.v[996] = work1d.L[1523]*work1d.d[996];
  work1d.v[997] = work1d.L[1524]*work1d.d[997];
  work1d.v[998] = work1d.L[1525]*work1d.d[998];
  work1d.v[999] = work1d.KKT[1953]-work1d.L[1514]*work1d.v[398]-work1d.L[1515]*work1d.v[757]-work1d.L[1516]*work1d.v[758]-work1d.L[1517]*work1d.v[807]-work1d.L[1518]*work1d.v[808]-work1d.L[1519]*work1d.v[810]-work1d.L[1520]*work1d.v[993]-work1d.L[1521]*work1d.v[994]-work1d.L[1522]*work1d.v[995]-work1d.L[1523]*work1d.v[996]-work1d.L[1524]*work1d.v[997]-work1d.L[1525]*work1d.v[998];
  work1d.d[999] = work1d.v[999];
  if (work1d.d[999] < 0)
    work1d.d[999] = settings1d.kkt_reg;
  else
    work1d.d[999] += settings1d.kkt_reg;
  work1d.d_inv[999] = 1/work1d.d[999];
  work1d.L[1535] = (-work1d.L[1530]*work1d.v[810]-work1d.L[1532]*work1d.v[996]-work1d.L[1533]*work1d.v[997]-work1d.L[1534]*work1d.v[998])*work1d.d_inv[999];
  work1d.v[359] = work1d.L[1526]*work1d.d[359];
  work1d.v[600] = work1d.L[1527]*work1d.d[600];
  work1d.v[601] = work1d.L[1528]*work1d.d[601];
  work1d.v[809] = work1d.L[1529]*work1d.d[809];
  work1d.v[810] = work1d.L[1530]*work1d.d[810];
  work1d.v[850] = work1d.L[1531]*work1d.d[850];
  work1d.v[996] = work1d.L[1532]*work1d.d[996];
  work1d.v[997] = work1d.L[1533]*work1d.d[997];
  work1d.v[998] = work1d.L[1534]*work1d.d[998];
  work1d.v[999] = work1d.L[1535]*work1d.d[999];
  work1d.v[1000] = work1d.KKT[1954]-work1d.L[1526]*work1d.v[359]-work1d.L[1527]*work1d.v[600]-work1d.L[1528]*work1d.v[601]-work1d.L[1529]*work1d.v[809]-work1d.L[1530]*work1d.v[810]-work1d.L[1531]*work1d.v[850]-work1d.L[1532]*work1d.v[996]-work1d.L[1533]*work1d.v[997]-work1d.L[1534]*work1d.v[998]-work1d.L[1535]*work1d.v[999];
  work1d.d[1000] = work1d.v[1000];
  if (work1d.d[1000] < 0)
    work1d.d[1000] = settings1d.kkt_reg;
  else
    work1d.d[1000] += settings1d.kkt_reg;
  work1d.d_inv[1000] = 1/work1d.d[1000];
#ifndef ZERO_LIBRARY_MODE
  if (settings1d.debug) {
    printf("Squared Frobenius for factorization is %.8g.\n", check_factorization1d());
  }
#endif
}
double check_factorization1d(void) {
  /* Returns the squared Frobenius norm of A - L*D*L'. */
  double temp, residual;
  /* Only check the lower triangle. */
  residual = 0;
  temp = work1d.KKT[805]-1*work1d.d[405]*1;
  residual += temp*temp;
  temp = work1d.KKT[807]-1*work1d.d[406]*1;
  residual += temp*temp;
  temp = work1d.KKT[809]-1*work1d.d[407]*1;
  residual += temp*temp;
  temp = work1d.KKT[811]-1*work1d.d[408]*1;
  residual += temp*temp;
  temp = work1d.KKT[813]-1*work1d.d[409]*1;
  residual += temp*temp;
  temp = work1d.KKT[815]-1*work1d.d[410]*1;
  residual += temp*temp;
  temp = work1d.KKT[817]-1*work1d.d[411]*1;
  residual += temp*temp;
  temp = work1d.KKT[819]-1*work1d.d[412]*1;
  residual += temp*temp;
  temp = work1d.KKT[821]-1*work1d.d[413]*1;
  residual += temp*temp;
  temp = work1d.KKT[823]-1*work1d.d[414]*1;
  residual += temp*temp;
  temp = work1d.KKT[825]-1*work1d.d[415]*1;
  residual += temp*temp;
  temp = work1d.KKT[827]-1*work1d.d[416]*1;
  residual += temp*temp;
  temp = work1d.KKT[829]-1*work1d.d[417]*1;
  residual += temp*temp;
  temp = work1d.KKT[831]-1*work1d.d[418]*1;
  residual += temp*temp;
  temp = work1d.KKT[833]-1*work1d.d[419]*1;
  residual += temp*temp;
  temp = work1d.KKT[835]-1*work1d.d[420]*1;
  residual += temp*temp;
  temp = work1d.KKT[837]-1*work1d.d[421]*1;
  residual += temp*temp;
  temp = work1d.KKT[839]-1*work1d.d[422]*1;
  residual += temp*temp;
  temp = work1d.KKT[841]-1*work1d.d[423]*1;
  residual += temp*temp;
  temp = work1d.KKT[843]-1*work1d.d[424]*1;
  residual += temp*temp;
  temp = work1d.KKT[845]-1*work1d.d[425]*1;
  residual += temp*temp;
  temp = work1d.KKT[847]-1*work1d.d[426]*1;
  residual += temp*temp;
  temp = work1d.KKT[849]-1*work1d.d[427]*1;
  residual += temp*temp;
  temp = work1d.KKT[851]-1*work1d.d[428]*1;
  residual += temp*temp;
  temp = work1d.KKT[853]-1*work1d.d[429]*1;
  residual += temp*temp;
  temp = work1d.KKT[855]-1*work1d.d[430]*1;
  residual += temp*temp;
  temp = work1d.KKT[857]-1*work1d.d[431]*1;
  residual += temp*temp;
  temp = work1d.KKT[859]-1*work1d.d[432]*1;
  residual += temp*temp;
  temp = work1d.KKT[861]-1*work1d.d[433]*1;
  residual += temp*temp;
  temp = work1d.KKT[863]-1*work1d.d[434]*1;
  residual += temp*temp;
  temp = work1d.KKT[865]-1*work1d.d[435]*1;
  residual += temp*temp;
  temp = work1d.KKT[867]-1*work1d.d[436]*1;
  residual += temp*temp;
  temp = work1d.KKT[869]-1*work1d.d[437]*1;
  residual += temp*temp;
  temp = work1d.KKT[871]-1*work1d.d[438]*1;
  residual += temp*temp;
  temp = work1d.KKT[873]-1*work1d.d[439]*1;
  residual += temp*temp;
  temp = work1d.KKT[875]-1*work1d.d[440]*1;
  residual += temp*temp;
  temp = work1d.KKT[877]-1*work1d.d[441]*1;
  residual += temp*temp;
  temp = work1d.KKT[879]-1*work1d.d[442]*1;
  residual += temp*temp;
  temp = work1d.KKT[881]-1*work1d.d[443]*1;
  residual += temp*temp;
  temp = work1d.KKT[0]-1*work1d.d[0]*1;
  residual += temp*temp;
  temp = work1d.KKT[883]-1*work1d.d[444]*1-work1d.L[81]*work1d.d[401]*work1d.L[81];
  residual += temp*temp;
  temp = work1d.KKT[1615]-1*work1d.d[811]*1-work1d.L[700]*work1d.d[448]*work1d.L[700]-work1d.L[701]*work1d.d[449]*work1d.L[701]-work1d.L[698]*work1d.d[321]*work1d.L[698]-work1d.L[699]*work1d.d[402]*work1d.L[699]-work1d.L[702]*work1d.d[770]*work1d.L[702];
  residual += temp*temp;
  temp = work1d.KKT[1617]-1*work1d.d[812]*1-work1d.L[705]*work1d.d[609]*work1d.L[705]-work1d.L[706]*work1d.d[610]*work1d.L[706]-work1d.L[703]*work1d.d[361]*work1d.L[703]-work1d.L[704]*work1d.d[404]*work1d.L[704]-work1d.L[707]*work1d.d[771]*work1d.L[707];
  residual += temp*temp;
  temp = work1d.KKT[1619]-1*work1d.d[813]*1-work1d.L[708]*work1d.d[770]*work1d.L[708]-work1d.L[709]*work1d.d[811]*work1d.L[709];
  residual += temp*temp;
  temp = work1d.KKT[1732]-1*work1d.d[852]*1-work1d.L[715]*work1d.d[452]*work1d.L[715]-work1d.L[716]*work1d.d[453]*work1d.L[716]-work1d.L[714]*work1d.d[322]*work1d.L[714]-work1d.L[717]*work1d.d[851]*work1d.L[717];
  residual += temp*temp;
  temp = work1d.KKT[1735]-1*work1d.d[853]*1-work1d.L[719]*work1d.d[613]*work1d.L[719]-work1d.L[720]*work1d.d[614]*work1d.L[720]-work1d.L[718]*work1d.d[362]*work1d.L[718]-work1d.L[721]*work1d.d[771]*work1d.L[721]-work1d.L[722]*work1d.d[772]*work1d.L[722]-work1d.L[723]*work1d.d[812]*work1d.L[723]-work1d.L[724]*work1d.d[851]*work1d.L[724]-work1d.L[725]*work1d.d[852]*work1d.L[725];
  residual += temp*temp;
  temp = work1d.KKT[1621]-1*work1d.d[814]*1;
  residual += temp*temp;
  temp = work1d.KKT[1738]-1*work1d.d[856]*1-work1d.L[735]*work1d.d[456]*work1d.L[735]-work1d.L[736]*work1d.d[457]*work1d.L[736]-work1d.L[734]*work1d.d[323]*work1d.L[734]-work1d.L[737]*work1d.d[855]*work1d.L[737];
  residual += temp*temp;
  temp = work1d.KKT[1741]-1*work1d.d[857]*1-work1d.L[739]*work1d.d[617]*work1d.L[739]-work1d.L[740]*work1d.d[618]*work1d.L[740]-work1d.L[738]*work1d.d[363]*work1d.L[738]-work1d.L[741]*work1d.d[772]*work1d.L[741]-work1d.L[742]*work1d.d[773]*work1d.L[742]-work1d.L[743]*work1d.d[853]*work1d.L[743]-work1d.L[745]*work1d.d[855]*work1d.L[745]-work1d.L[744]*work1d.d[854]*work1d.L[744]-work1d.L[746]*work1d.d[856]*work1d.L[746];
  residual += temp*temp;
  temp = work1d.KKT[1624]-1*work1d.d[815]*1;
  residual += temp*temp;
  temp = work1d.KKT[1744]-1*work1d.d[860]*1-work1d.L[757]*work1d.d[460]*work1d.L[757]-work1d.L[758]*work1d.d[461]*work1d.L[758]-work1d.L[756]*work1d.d[324]*work1d.L[756]-work1d.L[759]*work1d.d[859]*work1d.L[759];
  residual += temp*temp;
  temp = work1d.KKT[1747]-1*work1d.d[861]*1-work1d.L[761]*work1d.d[621]*work1d.L[761]-work1d.L[762]*work1d.d[622]*work1d.L[762]-work1d.L[760]*work1d.d[364]*work1d.L[760]-work1d.L[763]*work1d.d[773]*work1d.L[763]-work1d.L[764]*work1d.d[774]*work1d.L[764]-work1d.L[765]*work1d.d[857]*work1d.L[765]-work1d.L[767]*work1d.d[859]*work1d.L[767]-work1d.L[766]*work1d.d[858]*work1d.L[766]-work1d.L[768]*work1d.d[860]*work1d.L[768];
  residual += temp*temp;
  temp = work1d.KKT[1627]-1*work1d.d[816]*1;
  residual += temp*temp;
  temp = work1d.KKT[1750]-1*work1d.d[864]*1-work1d.L[779]*work1d.d[464]*work1d.L[779]-work1d.L[780]*work1d.d[465]*work1d.L[780]-work1d.L[778]*work1d.d[325]*work1d.L[778]-work1d.L[781]*work1d.d[863]*work1d.L[781];
  residual += temp*temp;
  temp = work1d.KKT[1753]-1*work1d.d[865]*1-work1d.L[783]*work1d.d[625]*work1d.L[783]-work1d.L[784]*work1d.d[626]*work1d.L[784]-work1d.L[782]*work1d.d[365]*work1d.L[782]-work1d.L[785]*work1d.d[774]*work1d.L[785]-work1d.L[786]*work1d.d[775]*work1d.L[786]-work1d.L[787]*work1d.d[861]*work1d.L[787]-work1d.L[789]*work1d.d[863]*work1d.L[789]-work1d.L[788]*work1d.d[862]*work1d.L[788]-work1d.L[790]*work1d.d[864]*work1d.L[790];
  residual += temp*temp;
  temp = work1d.KKT[1630]-1*work1d.d[817]*1;
  residual += temp*temp;
  temp = work1d.KKT[1756]-1*work1d.d[868]*1-work1d.L[801]*work1d.d[468]*work1d.L[801]-work1d.L[802]*work1d.d[469]*work1d.L[802]-work1d.L[800]*work1d.d[326]*work1d.L[800]-work1d.L[803]*work1d.d[867]*work1d.L[803];
  residual += temp*temp;
  temp = work1d.KKT[1759]-1*work1d.d[869]*1-work1d.L[805]*work1d.d[629]*work1d.L[805]-work1d.L[806]*work1d.d[630]*work1d.L[806]-work1d.L[804]*work1d.d[366]*work1d.L[804]-work1d.L[807]*work1d.d[775]*work1d.L[807]-work1d.L[808]*work1d.d[776]*work1d.L[808]-work1d.L[809]*work1d.d[865]*work1d.L[809]-work1d.L[811]*work1d.d[867]*work1d.L[811]-work1d.L[810]*work1d.d[866]*work1d.L[810]-work1d.L[812]*work1d.d[868]*work1d.L[812];
  residual += temp*temp;
  temp = work1d.KKT[1633]-1*work1d.d[818]*1;
  residual += temp*temp;
  temp = work1d.KKT[1762]-1*work1d.d[872]*1-work1d.L[823]*work1d.d[472]*work1d.L[823]-work1d.L[824]*work1d.d[473]*work1d.L[824]-work1d.L[822]*work1d.d[327]*work1d.L[822]-work1d.L[825]*work1d.d[871]*work1d.L[825];
  residual += temp*temp;
  temp = work1d.KKT[1765]-1*work1d.d[873]*1-work1d.L[827]*work1d.d[633]*work1d.L[827]-work1d.L[828]*work1d.d[634]*work1d.L[828]-work1d.L[826]*work1d.d[367]*work1d.L[826]-work1d.L[829]*work1d.d[776]*work1d.L[829]-work1d.L[830]*work1d.d[777]*work1d.L[830]-work1d.L[831]*work1d.d[869]*work1d.L[831]-work1d.L[833]*work1d.d[871]*work1d.L[833]-work1d.L[832]*work1d.d[870]*work1d.L[832]-work1d.L[834]*work1d.d[872]*work1d.L[834];
  residual += temp*temp;
  temp = work1d.KKT[1636]-1*work1d.d[819]*1;
  residual += temp*temp;
  temp = work1d.KKT[1768]-1*work1d.d[876]*1-work1d.L[845]*work1d.d[476]*work1d.L[845]-work1d.L[846]*work1d.d[477]*work1d.L[846]-work1d.L[844]*work1d.d[328]*work1d.L[844]-work1d.L[847]*work1d.d[875]*work1d.L[847];
  residual += temp*temp;
  temp = work1d.KKT[1771]-1*work1d.d[877]*1-work1d.L[849]*work1d.d[637]*work1d.L[849]-work1d.L[850]*work1d.d[638]*work1d.L[850]-work1d.L[848]*work1d.d[368]*work1d.L[848]-work1d.L[851]*work1d.d[777]*work1d.L[851]-work1d.L[852]*work1d.d[778]*work1d.L[852]-work1d.L[853]*work1d.d[873]*work1d.L[853]-work1d.L[855]*work1d.d[875]*work1d.L[855]-work1d.L[854]*work1d.d[874]*work1d.L[854]-work1d.L[856]*work1d.d[876]*work1d.L[856];
  residual += temp*temp;
  temp = work1d.KKT[1639]-1*work1d.d[820]*1;
  residual += temp*temp;
  temp = work1d.KKT[1774]-1*work1d.d[880]*1-work1d.L[867]*work1d.d[480]*work1d.L[867]-work1d.L[868]*work1d.d[481]*work1d.L[868]-work1d.L[866]*work1d.d[329]*work1d.L[866]-work1d.L[869]*work1d.d[879]*work1d.L[869];
  residual += temp*temp;
  temp = work1d.KKT[1777]-1*work1d.d[881]*1-work1d.L[871]*work1d.d[641]*work1d.L[871]-work1d.L[872]*work1d.d[642]*work1d.L[872]-work1d.L[870]*work1d.d[369]*work1d.L[870]-work1d.L[873]*work1d.d[778]*work1d.L[873]-work1d.L[874]*work1d.d[779]*work1d.L[874]-work1d.L[875]*work1d.d[877]*work1d.L[875]-work1d.L[877]*work1d.d[879]*work1d.L[877]-work1d.L[876]*work1d.d[878]*work1d.L[876]-work1d.L[878]*work1d.d[880]*work1d.L[878];
  residual += temp*temp;
  temp = work1d.KKT[1642]-1*work1d.d[821]*1;
  residual += temp*temp;
  temp = work1d.KKT[1780]-1*work1d.d[884]*1-work1d.L[889]*work1d.d[484]*work1d.L[889]-work1d.L[890]*work1d.d[485]*work1d.L[890]-work1d.L[888]*work1d.d[330]*work1d.L[888]-work1d.L[891]*work1d.d[883]*work1d.L[891];
  residual += temp*temp;
  temp = work1d.KKT[1783]-1*work1d.d[885]*1-work1d.L[893]*work1d.d[645]*work1d.L[893]-work1d.L[894]*work1d.d[646]*work1d.L[894]-work1d.L[892]*work1d.d[370]*work1d.L[892]-work1d.L[895]*work1d.d[779]*work1d.L[895]-work1d.L[896]*work1d.d[780]*work1d.L[896]-work1d.L[897]*work1d.d[881]*work1d.L[897]-work1d.L[899]*work1d.d[883]*work1d.L[899]-work1d.L[898]*work1d.d[882]*work1d.L[898]-work1d.L[900]*work1d.d[884]*work1d.L[900];
  residual += temp*temp;
  temp = work1d.KKT[1645]-1*work1d.d[822]*1;
  residual += temp*temp;
  temp = work1d.KKT[1786]-1*work1d.d[888]*1-work1d.L[911]*work1d.d[488]*work1d.L[911]-work1d.L[912]*work1d.d[489]*work1d.L[912]-work1d.L[910]*work1d.d[331]*work1d.L[910]-work1d.L[913]*work1d.d[887]*work1d.L[913];
  residual += temp*temp;
  temp = work1d.KKT[1789]-1*work1d.d[889]*1-work1d.L[915]*work1d.d[649]*work1d.L[915]-work1d.L[916]*work1d.d[650]*work1d.L[916]-work1d.L[914]*work1d.d[371]*work1d.L[914]-work1d.L[917]*work1d.d[780]*work1d.L[917]-work1d.L[918]*work1d.d[781]*work1d.L[918]-work1d.L[919]*work1d.d[885]*work1d.L[919]-work1d.L[921]*work1d.d[887]*work1d.L[921]-work1d.L[920]*work1d.d[886]*work1d.L[920]-work1d.L[922]*work1d.d[888]*work1d.L[922];
  residual += temp*temp;
  temp = work1d.KKT[1648]-1*work1d.d[823]*1;
  residual += temp*temp;
  temp = work1d.KKT[1792]-1*work1d.d[892]*1-work1d.L[933]*work1d.d[492]*work1d.L[933]-work1d.L[934]*work1d.d[493]*work1d.L[934]-work1d.L[932]*work1d.d[332]*work1d.L[932]-work1d.L[935]*work1d.d[891]*work1d.L[935];
  residual += temp*temp;
  temp = work1d.KKT[1795]-1*work1d.d[893]*1-work1d.L[937]*work1d.d[653]*work1d.L[937]-work1d.L[938]*work1d.d[654]*work1d.L[938]-work1d.L[936]*work1d.d[372]*work1d.L[936]-work1d.L[939]*work1d.d[781]*work1d.L[939]-work1d.L[940]*work1d.d[782]*work1d.L[940]-work1d.L[941]*work1d.d[889]*work1d.L[941]-work1d.L[943]*work1d.d[891]*work1d.L[943]-work1d.L[942]*work1d.d[890]*work1d.L[942]-work1d.L[944]*work1d.d[892]*work1d.L[944];
  residual += temp*temp;
  temp = work1d.KKT[1651]-1*work1d.d[824]*1;
  residual += temp*temp;
  temp = work1d.KKT[1798]-1*work1d.d[896]*1-work1d.L[955]*work1d.d[496]*work1d.L[955]-work1d.L[956]*work1d.d[497]*work1d.L[956]-work1d.L[954]*work1d.d[333]*work1d.L[954]-work1d.L[957]*work1d.d[895]*work1d.L[957];
  residual += temp*temp;
  temp = work1d.KKT[1801]-1*work1d.d[897]*1-work1d.L[959]*work1d.d[657]*work1d.L[959]-work1d.L[960]*work1d.d[658]*work1d.L[960]-work1d.L[958]*work1d.d[373]*work1d.L[958]-work1d.L[961]*work1d.d[782]*work1d.L[961]-work1d.L[962]*work1d.d[783]*work1d.L[962]-work1d.L[963]*work1d.d[893]*work1d.L[963]-work1d.L[965]*work1d.d[895]*work1d.L[965]-work1d.L[964]*work1d.d[894]*work1d.L[964]-work1d.L[966]*work1d.d[896]*work1d.L[966];
  residual += temp*temp;
  temp = work1d.KKT[1654]-1*work1d.d[825]*1;
  residual += temp*temp;
  temp = work1d.KKT[1804]-1*work1d.d[900]*1-work1d.L[977]*work1d.d[500]*work1d.L[977]-work1d.L[978]*work1d.d[501]*work1d.L[978]-work1d.L[976]*work1d.d[334]*work1d.L[976]-work1d.L[979]*work1d.d[899]*work1d.L[979];
  residual += temp*temp;
  temp = work1d.KKT[1807]-1*work1d.d[901]*1-work1d.L[981]*work1d.d[661]*work1d.L[981]-work1d.L[982]*work1d.d[662]*work1d.L[982]-work1d.L[980]*work1d.d[374]*work1d.L[980]-work1d.L[983]*work1d.d[783]*work1d.L[983]-work1d.L[984]*work1d.d[784]*work1d.L[984]-work1d.L[985]*work1d.d[897]*work1d.L[985]-work1d.L[987]*work1d.d[899]*work1d.L[987]-work1d.L[986]*work1d.d[898]*work1d.L[986]-work1d.L[988]*work1d.d[900]*work1d.L[988];
  residual += temp*temp;
  temp = work1d.KKT[1657]-1*work1d.d[826]*1;
  residual += temp*temp;
  temp = work1d.KKT[1810]-1*work1d.d[904]*1-work1d.L[999]*work1d.d[504]*work1d.L[999]-work1d.L[1000]*work1d.d[505]*work1d.L[1000]-work1d.L[998]*work1d.d[335]*work1d.L[998]-work1d.L[1001]*work1d.d[903]*work1d.L[1001];
  residual += temp*temp;
  temp = work1d.KKT[1813]-1*work1d.d[905]*1-work1d.L[1003]*work1d.d[665]*work1d.L[1003]-work1d.L[1004]*work1d.d[666]*work1d.L[1004]-work1d.L[1002]*work1d.d[375]*work1d.L[1002]-work1d.L[1005]*work1d.d[784]*work1d.L[1005]-work1d.L[1006]*work1d.d[785]*work1d.L[1006]-work1d.L[1007]*work1d.d[901]*work1d.L[1007]-work1d.L[1009]*work1d.d[903]*work1d.L[1009]-work1d.L[1008]*work1d.d[902]*work1d.L[1008]-work1d.L[1010]*work1d.d[904]*work1d.L[1010];
  residual += temp*temp;
  temp = work1d.KKT[1660]-1*work1d.d[827]*1;
  residual += temp*temp;
  temp = work1d.KKT[1816]-1*work1d.d[908]*1-work1d.L[1021]*work1d.d[508]*work1d.L[1021]-work1d.L[1022]*work1d.d[509]*work1d.L[1022]-work1d.L[1020]*work1d.d[336]*work1d.L[1020]-work1d.L[1023]*work1d.d[907]*work1d.L[1023];
  residual += temp*temp;
  temp = work1d.KKT[1819]-1*work1d.d[909]*1-work1d.L[1025]*work1d.d[669]*work1d.L[1025]-work1d.L[1026]*work1d.d[670]*work1d.L[1026]-work1d.L[1024]*work1d.d[376]*work1d.L[1024]-work1d.L[1027]*work1d.d[785]*work1d.L[1027]-work1d.L[1028]*work1d.d[786]*work1d.L[1028]-work1d.L[1029]*work1d.d[905]*work1d.L[1029]-work1d.L[1031]*work1d.d[907]*work1d.L[1031]-work1d.L[1030]*work1d.d[906]*work1d.L[1030]-work1d.L[1032]*work1d.d[908]*work1d.L[1032];
  residual += temp*temp;
  temp = work1d.KKT[1663]-1*work1d.d[828]*1;
  residual += temp*temp;
  temp = work1d.KKT[1822]-1*work1d.d[912]*1-work1d.L[1043]*work1d.d[512]*work1d.L[1043]-work1d.L[1044]*work1d.d[513]*work1d.L[1044]-work1d.L[1042]*work1d.d[337]*work1d.L[1042]-work1d.L[1045]*work1d.d[911]*work1d.L[1045];
  residual += temp*temp;
  temp = work1d.KKT[1825]-1*work1d.d[913]*1-work1d.L[1047]*work1d.d[673]*work1d.L[1047]-work1d.L[1048]*work1d.d[674]*work1d.L[1048]-work1d.L[1046]*work1d.d[377]*work1d.L[1046]-work1d.L[1049]*work1d.d[786]*work1d.L[1049]-work1d.L[1050]*work1d.d[787]*work1d.L[1050]-work1d.L[1051]*work1d.d[909]*work1d.L[1051]-work1d.L[1053]*work1d.d[911]*work1d.L[1053]-work1d.L[1052]*work1d.d[910]*work1d.L[1052]-work1d.L[1054]*work1d.d[912]*work1d.L[1054];
  residual += temp*temp;
  temp = work1d.KKT[1666]-1*work1d.d[829]*1;
  residual += temp*temp;
  temp = work1d.KKT[1828]-1*work1d.d[916]*1-work1d.L[1065]*work1d.d[516]*work1d.L[1065]-work1d.L[1066]*work1d.d[517]*work1d.L[1066]-work1d.L[1064]*work1d.d[338]*work1d.L[1064]-work1d.L[1067]*work1d.d[915]*work1d.L[1067];
  residual += temp*temp;
  temp = work1d.KKT[1831]-1*work1d.d[917]*1-work1d.L[1069]*work1d.d[677]*work1d.L[1069]-work1d.L[1070]*work1d.d[678]*work1d.L[1070]-work1d.L[1068]*work1d.d[378]*work1d.L[1068]-work1d.L[1071]*work1d.d[787]*work1d.L[1071]-work1d.L[1072]*work1d.d[788]*work1d.L[1072]-work1d.L[1073]*work1d.d[913]*work1d.L[1073]-work1d.L[1075]*work1d.d[915]*work1d.L[1075]-work1d.L[1074]*work1d.d[914]*work1d.L[1074]-work1d.L[1076]*work1d.d[916]*work1d.L[1076];
  residual += temp*temp;
  temp = work1d.KKT[1669]-1*work1d.d[830]*1;
  residual += temp*temp;
  temp = work1d.KKT[1834]-1*work1d.d[920]*1-work1d.L[1087]*work1d.d[520]*work1d.L[1087]-work1d.L[1088]*work1d.d[521]*work1d.L[1088]-work1d.L[1086]*work1d.d[339]*work1d.L[1086]-work1d.L[1089]*work1d.d[919]*work1d.L[1089];
  residual += temp*temp;
  temp = work1d.KKT[1837]-1*work1d.d[921]*1-work1d.L[1091]*work1d.d[681]*work1d.L[1091]-work1d.L[1092]*work1d.d[682]*work1d.L[1092]-work1d.L[1090]*work1d.d[379]*work1d.L[1090]-work1d.L[1093]*work1d.d[788]*work1d.L[1093]-work1d.L[1094]*work1d.d[789]*work1d.L[1094]-work1d.L[1095]*work1d.d[917]*work1d.L[1095]-work1d.L[1097]*work1d.d[919]*work1d.L[1097]-work1d.L[1096]*work1d.d[918]*work1d.L[1096]-work1d.L[1098]*work1d.d[920]*work1d.L[1098];
  residual += temp*temp;
  temp = work1d.KKT[1672]-1*work1d.d[831]*1;
  residual += temp*temp;
  temp = work1d.KKT[1840]-1*work1d.d[924]*1-work1d.L[1109]*work1d.d[524]*work1d.L[1109]-work1d.L[1110]*work1d.d[525]*work1d.L[1110]-work1d.L[1108]*work1d.d[340]*work1d.L[1108]-work1d.L[1111]*work1d.d[923]*work1d.L[1111];
  residual += temp*temp;
  temp = work1d.KKT[1843]-1*work1d.d[925]*1-work1d.L[1113]*work1d.d[685]*work1d.L[1113]-work1d.L[1114]*work1d.d[686]*work1d.L[1114]-work1d.L[1112]*work1d.d[380]*work1d.L[1112]-work1d.L[1115]*work1d.d[789]*work1d.L[1115]-work1d.L[1116]*work1d.d[790]*work1d.L[1116]-work1d.L[1117]*work1d.d[921]*work1d.L[1117]-work1d.L[1119]*work1d.d[923]*work1d.L[1119]-work1d.L[1118]*work1d.d[922]*work1d.L[1118]-work1d.L[1120]*work1d.d[924]*work1d.L[1120];
  residual += temp*temp;
  temp = work1d.KKT[1675]-1*work1d.d[832]*1;
  residual += temp*temp;
  temp = work1d.KKT[1846]-1*work1d.d[928]*1-work1d.L[1131]*work1d.d[528]*work1d.L[1131]-work1d.L[1132]*work1d.d[529]*work1d.L[1132]-work1d.L[1130]*work1d.d[341]*work1d.L[1130]-work1d.L[1133]*work1d.d[927]*work1d.L[1133];
  residual += temp*temp;
  temp = work1d.KKT[1849]-1*work1d.d[929]*1-work1d.L[1135]*work1d.d[689]*work1d.L[1135]-work1d.L[1136]*work1d.d[690]*work1d.L[1136]-work1d.L[1134]*work1d.d[381]*work1d.L[1134]-work1d.L[1137]*work1d.d[790]*work1d.L[1137]-work1d.L[1138]*work1d.d[791]*work1d.L[1138]-work1d.L[1139]*work1d.d[925]*work1d.L[1139]-work1d.L[1141]*work1d.d[927]*work1d.L[1141]-work1d.L[1140]*work1d.d[926]*work1d.L[1140]-work1d.L[1142]*work1d.d[928]*work1d.L[1142];
  residual += temp*temp;
  temp = work1d.KKT[1678]-1*work1d.d[833]*1;
  residual += temp*temp;
  temp = work1d.KKT[1852]-1*work1d.d[932]*1-work1d.L[1153]*work1d.d[532]*work1d.L[1153]-work1d.L[1154]*work1d.d[533]*work1d.L[1154]-work1d.L[1152]*work1d.d[342]*work1d.L[1152]-work1d.L[1155]*work1d.d[931]*work1d.L[1155];
  residual += temp*temp;
  temp = work1d.KKT[1855]-1*work1d.d[933]*1-work1d.L[1157]*work1d.d[693]*work1d.L[1157]-work1d.L[1158]*work1d.d[694]*work1d.L[1158]-work1d.L[1156]*work1d.d[382]*work1d.L[1156]-work1d.L[1159]*work1d.d[791]*work1d.L[1159]-work1d.L[1160]*work1d.d[792]*work1d.L[1160]-work1d.L[1161]*work1d.d[929]*work1d.L[1161]-work1d.L[1163]*work1d.d[931]*work1d.L[1163]-work1d.L[1162]*work1d.d[930]*work1d.L[1162]-work1d.L[1164]*work1d.d[932]*work1d.L[1164];
  residual += temp*temp;
  temp = work1d.KKT[1681]-1*work1d.d[834]*1;
  residual += temp*temp;
  temp = work1d.KKT[1858]-1*work1d.d[936]*1-work1d.L[1175]*work1d.d[536]*work1d.L[1175]-work1d.L[1176]*work1d.d[537]*work1d.L[1176]-work1d.L[1174]*work1d.d[343]*work1d.L[1174]-work1d.L[1177]*work1d.d[935]*work1d.L[1177];
  residual += temp*temp;
  temp = work1d.KKT[1861]-1*work1d.d[937]*1-work1d.L[1179]*work1d.d[697]*work1d.L[1179]-work1d.L[1180]*work1d.d[698]*work1d.L[1180]-work1d.L[1178]*work1d.d[383]*work1d.L[1178]-work1d.L[1181]*work1d.d[792]*work1d.L[1181]-work1d.L[1182]*work1d.d[793]*work1d.L[1182]-work1d.L[1183]*work1d.d[933]*work1d.L[1183]-work1d.L[1185]*work1d.d[935]*work1d.L[1185]-work1d.L[1184]*work1d.d[934]*work1d.L[1184]-work1d.L[1186]*work1d.d[936]*work1d.L[1186];
  residual += temp*temp;
  temp = work1d.KKT[1684]-1*work1d.d[835]*1;
  residual += temp*temp;
  temp = work1d.KKT[1864]-1*work1d.d[940]*1-work1d.L[1197]*work1d.d[540]*work1d.L[1197]-work1d.L[1198]*work1d.d[541]*work1d.L[1198]-work1d.L[1196]*work1d.d[344]*work1d.L[1196]-work1d.L[1199]*work1d.d[939]*work1d.L[1199];
  residual += temp*temp;
  temp = work1d.KKT[1867]-1*work1d.d[941]*1-work1d.L[1201]*work1d.d[701]*work1d.L[1201]-work1d.L[1202]*work1d.d[702]*work1d.L[1202]-work1d.L[1200]*work1d.d[384]*work1d.L[1200]-work1d.L[1203]*work1d.d[793]*work1d.L[1203]-work1d.L[1204]*work1d.d[794]*work1d.L[1204]-work1d.L[1205]*work1d.d[937]*work1d.L[1205]-work1d.L[1207]*work1d.d[939]*work1d.L[1207]-work1d.L[1206]*work1d.d[938]*work1d.L[1206]-work1d.L[1208]*work1d.d[940]*work1d.L[1208];
  residual += temp*temp;
  temp = work1d.KKT[1687]-1*work1d.d[836]*1;
  residual += temp*temp;
  temp = work1d.KKT[1870]-1*work1d.d[944]*1-work1d.L[1219]*work1d.d[544]*work1d.L[1219]-work1d.L[1220]*work1d.d[545]*work1d.L[1220]-work1d.L[1218]*work1d.d[345]*work1d.L[1218]-work1d.L[1221]*work1d.d[943]*work1d.L[1221];
  residual += temp*temp;
  temp = work1d.KKT[1873]-1*work1d.d[945]*1-work1d.L[1223]*work1d.d[705]*work1d.L[1223]-work1d.L[1224]*work1d.d[706]*work1d.L[1224]-work1d.L[1222]*work1d.d[385]*work1d.L[1222]-work1d.L[1225]*work1d.d[794]*work1d.L[1225]-work1d.L[1226]*work1d.d[795]*work1d.L[1226]-work1d.L[1227]*work1d.d[941]*work1d.L[1227]-work1d.L[1229]*work1d.d[943]*work1d.L[1229]-work1d.L[1228]*work1d.d[942]*work1d.L[1228]-work1d.L[1230]*work1d.d[944]*work1d.L[1230];
  residual += temp*temp;
  temp = work1d.KKT[1690]-1*work1d.d[837]*1;
  residual += temp*temp;
  temp = work1d.KKT[1876]-1*work1d.d[948]*1-work1d.L[1241]*work1d.d[548]*work1d.L[1241]-work1d.L[1242]*work1d.d[549]*work1d.L[1242]-work1d.L[1240]*work1d.d[346]*work1d.L[1240]-work1d.L[1243]*work1d.d[947]*work1d.L[1243];
  residual += temp*temp;
  temp = work1d.KKT[1879]-1*work1d.d[949]*1-work1d.L[1245]*work1d.d[709]*work1d.L[1245]-work1d.L[1246]*work1d.d[710]*work1d.L[1246]-work1d.L[1244]*work1d.d[386]*work1d.L[1244]-work1d.L[1247]*work1d.d[795]*work1d.L[1247]-work1d.L[1248]*work1d.d[796]*work1d.L[1248]-work1d.L[1249]*work1d.d[945]*work1d.L[1249]-work1d.L[1251]*work1d.d[947]*work1d.L[1251]-work1d.L[1250]*work1d.d[946]*work1d.L[1250]-work1d.L[1252]*work1d.d[948]*work1d.L[1252];
  residual += temp*temp;
  temp = work1d.KKT[1693]-1*work1d.d[838]*1;
  residual += temp*temp;
  temp = work1d.KKT[1882]-1*work1d.d[952]*1-work1d.L[1263]*work1d.d[552]*work1d.L[1263]-work1d.L[1264]*work1d.d[553]*work1d.L[1264]-work1d.L[1262]*work1d.d[347]*work1d.L[1262]-work1d.L[1265]*work1d.d[951]*work1d.L[1265];
  residual += temp*temp;
  temp = work1d.KKT[1885]-1*work1d.d[953]*1-work1d.L[1267]*work1d.d[713]*work1d.L[1267]-work1d.L[1268]*work1d.d[714]*work1d.L[1268]-work1d.L[1266]*work1d.d[387]*work1d.L[1266]-work1d.L[1269]*work1d.d[796]*work1d.L[1269]-work1d.L[1270]*work1d.d[797]*work1d.L[1270]-work1d.L[1271]*work1d.d[949]*work1d.L[1271]-work1d.L[1273]*work1d.d[951]*work1d.L[1273]-work1d.L[1272]*work1d.d[950]*work1d.L[1272]-work1d.L[1274]*work1d.d[952]*work1d.L[1274];
  residual += temp*temp;
  temp = work1d.KKT[1696]-1*work1d.d[839]*1;
  residual += temp*temp;
  temp = work1d.KKT[1888]-1*work1d.d[956]*1-work1d.L[1285]*work1d.d[556]*work1d.L[1285]-work1d.L[1286]*work1d.d[557]*work1d.L[1286]-work1d.L[1284]*work1d.d[348]*work1d.L[1284]-work1d.L[1287]*work1d.d[955]*work1d.L[1287];
  residual += temp*temp;
  temp = work1d.KKT[1891]-1*work1d.d[957]*1-work1d.L[1289]*work1d.d[717]*work1d.L[1289]-work1d.L[1290]*work1d.d[718]*work1d.L[1290]-work1d.L[1288]*work1d.d[388]*work1d.L[1288]-work1d.L[1291]*work1d.d[797]*work1d.L[1291]-work1d.L[1292]*work1d.d[798]*work1d.L[1292]-work1d.L[1293]*work1d.d[953]*work1d.L[1293]-work1d.L[1295]*work1d.d[955]*work1d.L[1295]-work1d.L[1294]*work1d.d[954]*work1d.L[1294]-work1d.L[1296]*work1d.d[956]*work1d.L[1296];
  residual += temp*temp;
  temp = work1d.KKT[1699]-1*work1d.d[840]*1;
  residual += temp*temp;
  temp = work1d.KKT[1894]-1*work1d.d[960]*1-work1d.L[1307]*work1d.d[560]*work1d.L[1307]-work1d.L[1308]*work1d.d[561]*work1d.L[1308]-work1d.L[1306]*work1d.d[349]*work1d.L[1306]-work1d.L[1309]*work1d.d[959]*work1d.L[1309];
  residual += temp*temp;
  temp = work1d.KKT[1897]-1*work1d.d[961]*1-work1d.L[1311]*work1d.d[721]*work1d.L[1311]-work1d.L[1312]*work1d.d[722]*work1d.L[1312]-work1d.L[1310]*work1d.d[389]*work1d.L[1310]-work1d.L[1313]*work1d.d[798]*work1d.L[1313]-work1d.L[1314]*work1d.d[799]*work1d.L[1314]-work1d.L[1315]*work1d.d[957]*work1d.L[1315]-work1d.L[1317]*work1d.d[959]*work1d.L[1317]-work1d.L[1316]*work1d.d[958]*work1d.L[1316]-work1d.L[1318]*work1d.d[960]*work1d.L[1318];
  residual += temp*temp;
  temp = work1d.KKT[1702]-1*work1d.d[841]*1;
  residual += temp*temp;
  temp = work1d.KKT[1900]-1*work1d.d[964]*1-work1d.L[1329]*work1d.d[564]*work1d.L[1329]-work1d.L[1330]*work1d.d[565]*work1d.L[1330]-work1d.L[1328]*work1d.d[350]*work1d.L[1328]-work1d.L[1331]*work1d.d[963]*work1d.L[1331];
  residual += temp*temp;
  temp = work1d.KKT[1903]-1*work1d.d[965]*1-work1d.L[1333]*work1d.d[725]*work1d.L[1333]-work1d.L[1334]*work1d.d[726]*work1d.L[1334]-work1d.L[1332]*work1d.d[390]*work1d.L[1332]-work1d.L[1335]*work1d.d[799]*work1d.L[1335]-work1d.L[1336]*work1d.d[800]*work1d.L[1336]-work1d.L[1337]*work1d.d[961]*work1d.L[1337]-work1d.L[1339]*work1d.d[963]*work1d.L[1339]-work1d.L[1338]*work1d.d[962]*work1d.L[1338]-work1d.L[1340]*work1d.d[964]*work1d.L[1340];
  residual += temp*temp;
  temp = work1d.KKT[1705]-1*work1d.d[842]*1;
  residual += temp*temp;
  temp = work1d.KKT[1906]-1*work1d.d[968]*1-work1d.L[1351]*work1d.d[568]*work1d.L[1351]-work1d.L[1352]*work1d.d[569]*work1d.L[1352]-work1d.L[1350]*work1d.d[351]*work1d.L[1350]-work1d.L[1353]*work1d.d[967]*work1d.L[1353];
  residual += temp*temp;
  temp = work1d.KKT[1909]-1*work1d.d[969]*1-work1d.L[1355]*work1d.d[729]*work1d.L[1355]-work1d.L[1356]*work1d.d[730]*work1d.L[1356]-work1d.L[1354]*work1d.d[391]*work1d.L[1354]-work1d.L[1357]*work1d.d[800]*work1d.L[1357]-work1d.L[1358]*work1d.d[801]*work1d.L[1358]-work1d.L[1359]*work1d.d[965]*work1d.L[1359]-work1d.L[1361]*work1d.d[967]*work1d.L[1361]-work1d.L[1360]*work1d.d[966]*work1d.L[1360]-work1d.L[1362]*work1d.d[968]*work1d.L[1362];
  residual += temp*temp;
  temp = work1d.KKT[1708]-1*work1d.d[843]*1;
  residual += temp*temp;
  temp = work1d.KKT[1912]-1*work1d.d[972]*1-work1d.L[1373]*work1d.d[572]*work1d.L[1373]-work1d.L[1374]*work1d.d[573]*work1d.L[1374]-work1d.L[1372]*work1d.d[352]*work1d.L[1372]-work1d.L[1375]*work1d.d[971]*work1d.L[1375];
  residual += temp*temp;
  temp = work1d.KKT[1915]-1*work1d.d[973]*1-work1d.L[1377]*work1d.d[733]*work1d.L[1377]-work1d.L[1378]*work1d.d[734]*work1d.L[1378]-work1d.L[1376]*work1d.d[392]*work1d.L[1376]-work1d.L[1379]*work1d.d[801]*work1d.L[1379]-work1d.L[1380]*work1d.d[802]*work1d.L[1380]-work1d.L[1381]*work1d.d[969]*work1d.L[1381]-work1d.L[1383]*work1d.d[971]*work1d.L[1383]-work1d.L[1382]*work1d.d[970]*work1d.L[1382]-work1d.L[1384]*work1d.d[972]*work1d.L[1384];
  residual += temp*temp;
  temp = work1d.KKT[1711]-1*work1d.d[844]*1;
  residual += temp*temp;
  temp = work1d.KKT[1918]-1*work1d.d[976]*1-work1d.L[1395]*work1d.d[576]*work1d.L[1395]-work1d.L[1396]*work1d.d[577]*work1d.L[1396]-work1d.L[1394]*work1d.d[353]*work1d.L[1394]-work1d.L[1397]*work1d.d[975]*work1d.L[1397];
  residual += temp*temp;
  temp = work1d.KKT[1921]-1*work1d.d[977]*1-work1d.L[1399]*work1d.d[737]*work1d.L[1399]-work1d.L[1400]*work1d.d[738]*work1d.L[1400]-work1d.L[1398]*work1d.d[393]*work1d.L[1398]-work1d.L[1401]*work1d.d[802]*work1d.L[1401]-work1d.L[1402]*work1d.d[803]*work1d.L[1402]-work1d.L[1403]*work1d.d[973]*work1d.L[1403]-work1d.L[1405]*work1d.d[975]*work1d.L[1405]-work1d.L[1404]*work1d.d[974]*work1d.L[1404]-work1d.L[1406]*work1d.d[976]*work1d.L[1406];
  residual += temp*temp;
  temp = work1d.KKT[1714]-1*work1d.d[845]*1;
  residual += temp*temp;
  temp = work1d.KKT[1924]-1*work1d.d[980]*1-work1d.L[1417]*work1d.d[580]*work1d.L[1417]-work1d.L[1418]*work1d.d[581]*work1d.L[1418]-work1d.L[1416]*work1d.d[354]*work1d.L[1416]-work1d.L[1419]*work1d.d[979]*work1d.L[1419];
  residual += temp*temp;
  temp = work1d.KKT[1927]-1*work1d.d[981]*1-work1d.L[1421]*work1d.d[741]*work1d.L[1421]-work1d.L[1422]*work1d.d[742]*work1d.L[1422]-work1d.L[1420]*work1d.d[394]*work1d.L[1420]-work1d.L[1423]*work1d.d[803]*work1d.L[1423]-work1d.L[1424]*work1d.d[804]*work1d.L[1424]-work1d.L[1425]*work1d.d[977]*work1d.L[1425]-work1d.L[1427]*work1d.d[979]*work1d.L[1427]-work1d.L[1426]*work1d.d[978]*work1d.L[1426]-work1d.L[1428]*work1d.d[980]*work1d.L[1428];
  residual += temp*temp;
  temp = work1d.KKT[1717]-1*work1d.d[846]*1;
  residual += temp*temp;
  temp = work1d.KKT[1930]-1*work1d.d[984]*1-work1d.L[1439]*work1d.d[584]*work1d.L[1439]-work1d.L[1440]*work1d.d[585]*work1d.L[1440]-work1d.L[1438]*work1d.d[355]*work1d.L[1438]-work1d.L[1441]*work1d.d[983]*work1d.L[1441];
  residual += temp*temp;
  temp = work1d.KKT[1933]-1*work1d.d[985]*1-work1d.L[1443]*work1d.d[745]*work1d.L[1443]-work1d.L[1444]*work1d.d[746]*work1d.L[1444]-work1d.L[1442]*work1d.d[395]*work1d.L[1442]-work1d.L[1445]*work1d.d[804]*work1d.L[1445]-work1d.L[1446]*work1d.d[805]*work1d.L[1446]-work1d.L[1447]*work1d.d[981]*work1d.L[1447]-work1d.L[1449]*work1d.d[983]*work1d.L[1449]-work1d.L[1448]*work1d.d[982]*work1d.L[1448]-work1d.L[1450]*work1d.d[984]*work1d.L[1450];
  residual += temp*temp;
  temp = work1d.KKT[1720]-1*work1d.d[847]*1;
  residual += temp*temp;
  temp = work1d.KKT[1936]-1*work1d.d[988]*1-work1d.L[1461]*work1d.d[588]*work1d.L[1461]-work1d.L[1462]*work1d.d[589]*work1d.L[1462]-work1d.L[1460]*work1d.d[356]*work1d.L[1460]-work1d.L[1463]*work1d.d[987]*work1d.L[1463];
  residual += temp*temp;
  temp = work1d.KKT[1939]-1*work1d.d[989]*1-work1d.L[1465]*work1d.d[749]*work1d.L[1465]-work1d.L[1466]*work1d.d[750]*work1d.L[1466]-work1d.L[1464]*work1d.d[396]*work1d.L[1464]-work1d.L[1467]*work1d.d[805]*work1d.L[1467]-work1d.L[1468]*work1d.d[806]*work1d.L[1468]-work1d.L[1469]*work1d.d[985]*work1d.L[1469]-work1d.L[1471]*work1d.d[987]*work1d.L[1471]-work1d.L[1470]*work1d.d[986]*work1d.L[1470]-work1d.L[1472]*work1d.d[988]*work1d.L[1472];
  residual += temp*temp;
  temp = work1d.KKT[1723]-1*work1d.d[848]*1;
  residual += temp*temp;
  temp = work1d.KKT[1942]-1*work1d.d[992]*1-work1d.L[1483]*work1d.d[592]*work1d.L[1483]-work1d.L[1484]*work1d.d[593]*work1d.L[1484]-work1d.L[1482]*work1d.d[357]*work1d.L[1482]-work1d.L[1485]*work1d.d[991]*work1d.L[1485];
  residual += temp*temp;
  temp = work1d.KKT[1945]-1*work1d.d[993]*1-work1d.L[1487]*work1d.d[753]*work1d.L[1487]-work1d.L[1488]*work1d.d[754]*work1d.L[1488]-work1d.L[1486]*work1d.d[397]*work1d.L[1486]-work1d.L[1489]*work1d.d[806]*work1d.L[1489]-work1d.L[1490]*work1d.d[807]*work1d.L[1490]-work1d.L[1491]*work1d.d[989]*work1d.L[1491]-work1d.L[1493]*work1d.d[991]*work1d.L[1493]-work1d.L[1492]*work1d.d[990]*work1d.L[1492]-work1d.L[1494]*work1d.d[992]*work1d.L[1494];
  residual += temp*temp;
  temp = work1d.KKT[1726]-1*work1d.d[849]*1;
  residual += temp*temp;
  temp = work1d.KKT[1952]-1*work1d.d[998]*1-work1d.L[1509]*work1d.d[596]*work1d.L[1509]-work1d.L[1510]*work1d.d[597]*work1d.L[1510]-work1d.L[1508]*work1d.d[358]*work1d.L[1508]-work1d.L[1511]*work1d.d[995]*work1d.L[1511]-work1d.L[1513]*work1d.d[997]*work1d.L[1513]-work1d.L[1512]*work1d.d[996]*work1d.L[1512];
  residual += temp*temp;
  temp = work1d.KKT[1953]-1*work1d.d[999]*1-work1d.L[1515]*work1d.d[757]*work1d.L[1515]-work1d.L[1516]*work1d.d[758]*work1d.L[1516]-work1d.L[1514]*work1d.d[398]*work1d.L[1514]-work1d.L[1517]*work1d.d[807]*work1d.L[1517]-work1d.L[1518]*work1d.d[808]*work1d.L[1518]-work1d.L[1524]*work1d.d[997]*work1d.L[1524]-work1d.L[1520]*work1d.d[993]*work1d.L[1520]-work1d.L[1519]*work1d.d[810]*work1d.L[1519]-work1d.L[1522]*work1d.d[995]*work1d.L[1522]-work1d.L[1521]*work1d.d[994]*work1d.L[1521]-work1d.L[1523]*work1d.d[996]*work1d.L[1523]-work1d.L[1525]*work1d.d[998]*work1d.L[1525];
  residual += temp*temp;
  temp = work1d.KKT[1729]-1*work1d.d[850]*1-work1d.L[710]*work1d.d[809]*work1d.L[710];
  residual += temp*temp;
  temp = work1d.KKT[1954]-1*work1d.d[1000]*1-work1d.L[1527]*work1d.d[600]*work1d.L[1527]-work1d.L[1528]*work1d.d[601]*work1d.L[1528]-work1d.L[1526]*work1d.d[359]*work1d.L[1526]-work1d.L[1533]*work1d.d[997]*work1d.L[1533]-work1d.L[1530]*work1d.d[810]*work1d.L[1530]-work1d.L[1529]*work1d.d[809]*work1d.L[1529]-work1d.L[1531]*work1d.d[850]*work1d.L[1531]-work1d.L[1535]*work1d.d[999]*work1d.L[1535]-work1d.L[1532]*work1d.d[996]*work1d.L[1532]-work1d.L[1534]*work1d.d[998]*work1d.L[1534];
  residual += temp*temp;
  temp = work1d.KKT[1532]-1*work1d.d[769]*1-work1d.L[651]*work1d.d[761]*work1d.L[651]-work1d.L[652]*work1d.d[762]*work1d.L[652]-work1d.L[650]*work1d.d[399]*work1d.L[650]-work1d.L[653]*work1d.d[768]*work1d.L[653];
  residual += temp*temp;
  temp = work1d.KKT[885]-1*work1d.d[445]*1;
  residual += temp*temp;
  temp = work1d.KKT[1207]-1*work1d.d[606]*1-work1d.L[363]*work1d.d[604]*work1d.L[363]-work1d.L[364]*work1d.d[605]*work1d.L[364]-work1d.L[362]*work1d.d[360]*work1d.L[362];
  residual += temp*temp;
  temp = work1d.KKT[1529]-1*work1d.d[767]*1-work1d.L[646]*work1d.d[765]*work1d.L[646]-work1d.L[647]*work1d.d[766]*work1d.L[647]-work1d.L[645]*work1d.d[400]*work1d.L[645];
  residual += temp*temp;
  temp = work1d.KKT[1]-1*work1d.d[1]*1;
  residual += temp*temp;
  temp = work1d.KKT[3]-1*work1d.d[2]*1;
  residual += temp*temp;
  temp = work1d.KKT[5]-1*work1d.d[3]*1;
  residual += temp*temp;
  temp = work1d.KKT[7]-1*work1d.d[4]*1;
  residual += temp*temp;
  temp = work1d.KKT[9]-1*work1d.d[5]*1;
  residual += temp*temp;
  temp = work1d.KKT[11]-1*work1d.d[6]*1;
  residual += temp*temp;
  temp = work1d.KKT[13]-1*work1d.d[7]*1;
  residual += temp*temp;
  temp = work1d.KKT[15]-1*work1d.d[8]*1;
  residual += temp*temp;
  temp = work1d.KKT[17]-1*work1d.d[9]*1;
  residual += temp*temp;
  temp = work1d.KKT[19]-1*work1d.d[10]*1;
  residual += temp*temp;
  temp = work1d.KKT[21]-1*work1d.d[11]*1;
  residual += temp*temp;
  temp = work1d.KKT[23]-1*work1d.d[12]*1;
  residual += temp*temp;
  temp = work1d.KKT[25]-1*work1d.d[13]*1;
  residual += temp*temp;
  temp = work1d.KKT[27]-1*work1d.d[14]*1;
  residual += temp*temp;
  temp = work1d.KKT[29]-1*work1d.d[15]*1;
  residual += temp*temp;
  temp = work1d.KKT[31]-1*work1d.d[16]*1;
  residual += temp*temp;
  temp = work1d.KKT[33]-1*work1d.d[17]*1;
  residual += temp*temp;
  temp = work1d.KKT[35]-1*work1d.d[18]*1;
  residual += temp*temp;
  temp = work1d.KKT[37]-1*work1d.d[19]*1;
  residual += temp*temp;
  temp = work1d.KKT[39]-1*work1d.d[20]*1;
  residual += temp*temp;
  temp = work1d.KKT[41]-1*work1d.d[21]*1;
  residual += temp*temp;
  temp = work1d.KKT[43]-1*work1d.d[22]*1;
  residual += temp*temp;
  temp = work1d.KKT[45]-1*work1d.d[23]*1;
  residual += temp*temp;
  temp = work1d.KKT[47]-1*work1d.d[24]*1;
  residual += temp*temp;
  temp = work1d.KKT[49]-1*work1d.d[25]*1;
  residual += temp*temp;
  temp = work1d.KKT[51]-1*work1d.d[26]*1;
  residual += temp*temp;
  temp = work1d.KKT[53]-1*work1d.d[27]*1;
  residual += temp*temp;
  temp = work1d.KKT[55]-1*work1d.d[28]*1;
  residual += temp*temp;
  temp = work1d.KKT[57]-1*work1d.d[29]*1;
  residual += temp*temp;
  temp = work1d.KKT[59]-1*work1d.d[30]*1;
  residual += temp*temp;
  temp = work1d.KKT[61]-1*work1d.d[31]*1;
  residual += temp*temp;
  temp = work1d.KKT[63]-1*work1d.d[32]*1;
  residual += temp*temp;
  temp = work1d.KKT[65]-1*work1d.d[33]*1;
  residual += temp*temp;
  temp = work1d.KKT[67]-1*work1d.d[34]*1;
  residual += temp*temp;
  temp = work1d.KKT[69]-1*work1d.d[35]*1;
  residual += temp*temp;
  temp = work1d.KKT[71]-1*work1d.d[36]*1;
  residual += temp*temp;
  temp = work1d.KKT[73]-1*work1d.d[37]*1;
  residual += temp*temp;
  temp = work1d.KKT[75]-1*work1d.d[38]*1;
  residual += temp*temp;
  temp = work1d.KKT[77]-1*work1d.d[39]*1;
  residual += temp*temp;
  temp = work1d.KKT[79]-1*work1d.d[40]*1;
  residual += temp*temp;
  temp = work1d.KKT[81]-1*work1d.d[41]*1;
  residual += temp*temp;
  temp = work1d.KKT[83]-1*work1d.d[42]*1;
  residual += temp*temp;
  temp = work1d.KKT[85]-1*work1d.d[43]*1;
  residual += temp*temp;
  temp = work1d.KKT[87]-1*work1d.d[44]*1;
  residual += temp*temp;
  temp = work1d.KKT[89]-1*work1d.d[45]*1;
  residual += temp*temp;
  temp = work1d.KKT[91]-1*work1d.d[46]*1;
  residual += temp*temp;
  temp = work1d.KKT[93]-1*work1d.d[47]*1;
  residual += temp*temp;
  temp = work1d.KKT[95]-1*work1d.d[48]*1;
  residual += temp*temp;
  temp = work1d.KKT[97]-1*work1d.d[49]*1;
  residual += temp*temp;
  temp = work1d.KKT[99]-1*work1d.d[50]*1;
  residual += temp*temp;
  temp = work1d.KKT[101]-1*work1d.d[51]*1;
  residual += temp*temp;
  temp = work1d.KKT[103]-1*work1d.d[52]*1;
  residual += temp*temp;
  temp = work1d.KKT[105]-1*work1d.d[53]*1;
  residual += temp*temp;
  temp = work1d.KKT[107]-1*work1d.d[54]*1;
  residual += temp*temp;
  temp = work1d.KKT[109]-1*work1d.d[55]*1;
  residual += temp*temp;
  temp = work1d.KKT[111]-1*work1d.d[56]*1;
  residual += temp*temp;
  temp = work1d.KKT[113]-1*work1d.d[57]*1;
  residual += temp*temp;
  temp = work1d.KKT[115]-1*work1d.d[58]*1;
  residual += temp*temp;
  temp = work1d.KKT[117]-1*work1d.d[59]*1;
  residual += temp*temp;
  temp = work1d.KKT[119]-1*work1d.d[60]*1;
  residual += temp*temp;
  temp = work1d.KKT[121]-1*work1d.d[61]*1;
  residual += temp*temp;
  temp = work1d.KKT[123]-1*work1d.d[62]*1;
  residual += temp*temp;
  temp = work1d.KKT[125]-1*work1d.d[63]*1;
  residual += temp*temp;
  temp = work1d.KKT[127]-1*work1d.d[64]*1;
  residual += temp*temp;
  temp = work1d.KKT[129]-1*work1d.d[65]*1;
  residual += temp*temp;
  temp = work1d.KKT[131]-1*work1d.d[66]*1;
  residual += temp*temp;
  temp = work1d.KKT[133]-1*work1d.d[67]*1;
  residual += temp*temp;
  temp = work1d.KKT[135]-1*work1d.d[68]*1;
  residual += temp*temp;
  temp = work1d.KKT[137]-1*work1d.d[69]*1;
  residual += temp*temp;
  temp = work1d.KKT[139]-1*work1d.d[70]*1;
  residual += temp*temp;
  temp = work1d.KKT[141]-1*work1d.d[71]*1;
  residual += temp*temp;
  temp = work1d.KKT[143]-1*work1d.d[72]*1;
  residual += temp*temp;
  temp = work1d.KKT[145]-1*work1d.d[73]*1;
  residual += temp*temp;
  temp = work1d.KKT[147]-1*work1d.d[74]*1;
  residual += temp*temp;
  temp = work1d.KKT[149]-1*work1d.d[75]*1;
  residual += temp*temp;
  temp = work1d.KKT[151]-1*work1d.d[76]*1;
  residual += temp*temp;
  temp = work1d.KKT[153]-1*work1d.d[77]*1;
  residual += temp*temp;
  temp = work1d.KKT[155]-1*work1d.d[78]*1;
  residual += temp*temp;
  temp = work1d.KKT[157]-1*work1d.d[79]*1;
  residual += temp*temp;
  temp = work1d.KKT[159]-1*work1d.d[80]*1;
  residual += temp*temp;
  temp = work1d.KKT[161]-1*work1d.d[81]*1;
  residual += temp*temp;
  temp = work1d.KKT[163]-1*work1d.d[82]*1;
  residual += temp*temp;
  temp = work1d.KKT[165]-1*work1d.d[83]*1;
  residual += temp*temp;
  temp = work1d.KKT[167]-1*work1d.d[84]*1;
  residual += temp*temp;
  temp = work1d.KKT[169]-1*work1d.d[85]*1;
  residual += temp*temp;
  temp = work1d.KKT[171]-1*work1d.d[86]*1;
  residual += temp*temp;
  temp = work1d.KKT[173]-1*work1d.d[87]*1;
  residual += temp*temp;
  temp = work1d.KKT[175]-1*work1d.d[88]*1;
  residual += temp*temp;
  temp = work1d.KKT[177]-1*work1d.d[89]*1;
  residual += temp*temp;
  temp = work1d.KKT[179]-1*work1d.d[90]*1;
  residual += temp*temp;
  temp = work1d.KKT[181]-1*work1d.d[91]*1;
  residual += temp*temp;
  temp = work1d.KKT[183]-1*work1d.d[92]*1;
  residual += temp*temp;
  temp = work1d.KKT[185]-1*work1d.d[93]*1;
  residual += temp*temp;
  temp = work1d.KKT[187]-1*work1d.d[94]*1;
  residual += temp*temp;
  temp = work1d.KKT[189]-1*work1d.d[95]*1;
  residual += temp*temp;
  temp = work1d.KKT[191]-1*work1d.d[96]*1;
  residual += temp*temp;
  temp = work1d.KKT[193]-1*work1d.d[97]*1;
  residual += temp*temp;
  temp = work1d.KKT[195]-1*work1d.d[98]*1;
  residual += temp*temp;
  temp = work1d.KKT[197]-1*work1d.d[99]*1;
  residual += temp*temp;
  temp = work1d.KKT[199]-1*work1d.d[100]*1;
  residual += temp*temp;
  temp = work1d.KKT[201]-1*work1d.d[101]*1;
  residual += temp*temp;
  temp = work1d.KKT[203]-1*work1d.d[102]*1;
  residual += temp*temp;
  temp = work1d.KKT[205]-1*work1d.d[103]*1;
  residual += temp*temp;
  temp = work1d.KKT[207]-1*work1d.d[104]*1;
  residual += temp*temp;
  temp = work1d.KKT[209]-1*work1d.d[105]*1;
  residual += temp*temp;
  temp = work1d.KKT[211]-1*work1d.d[106]*1;
  residual += temp*temp;
  temp = work1d.KKT[213]-1*work1d.d[107]*1;
  residual += temp*temp;
  temp = work1d.KKT[215]-1*work1d.d[108]*1;
  residual += temp*temp;
  temp = work1d.KKT[217]-1*work1d.d[109]*1;
  residual += temp*temp;
  temp = work1d.KKT[219]-1*work1d.d[110]*1;
  residual += temp*temp;
  temp = work1d.KKT[221]-1*work1d.d[111]*1;
  residual += temp*temp;
  temp = work1d.KKT[223]-1*work1d.d[112]*1;
  residual += temp*temp;
  temp = work1d.KKT[225]-1*work1d.d[113]*1;
  residual += temp*temp;
  temp = work1d.KKT[227]-1*work1d.d[114]*1;
  residual += temp*temp;
  temp = work1d.KKT[229]-1*work1d.d[115]*1;
  residual += temp*temp;
  temp = work1d.KKT[231]-1*work1d.d[116]*1;
  residual += temp*temp;
  temp = work1d.KKT[233]-1*work1d.d[117]*1;
  residual += temp*temp;
  temp = work1d.KKT[235]-1*work1d.d[118]*1;
  residual += temp*temp;
  temp = work1d.KKT[237]-1*work1d.d[119]*1;
  residual += temp*temp;
  temp = work1d.KKT[239]-1*work1d.d[120]*1;
  residual += temp*temp;
  temp = work1d.KKT[241]-1*work1d.d[121]*1;
  residual += temp*temp;
  temp = work1d.KKT[243]-1*work1d.d[122]*1;
  residual += temp*temp;
  temp = work1d.KKT[245]-1*work1d.d[123]*1;
  residual += temp*temp;
  temp = work1d.KKT[247]-1*work1d.d[124]*1;
  residual += temp*temp;
  temp = work1d.KKT[249]-1*work1d.d[125]*1;
  residual += temp*temp;
  temp = work1d.KKT[251]-1*work1d.d[126]*1;
  residual += temp*temp;
  temp = work1d.KKT[253]-1*work1d.d[127]*1;
  residual += temp*temp;
  temp = work1d.KKT[255]-1*work1d.d[128]*1;
  residual += temp*temp;
  temp = work1d.KKT[257]-1*work1d.d[129]*1;
  residual += temp*temp;
  temp = work1d.KKT[259]-1*work1d.d[130]*1;
  residual += temp*temp;
  temp = work1d.KKT[261]-1*work1d.d[131]*1;
  residual += temp*temp;
  temp = work1d.KKT[263]-1*work1d.d[132]*1;
  residual += temp*temp;
  temp = work1d.KKT[265]-1*work1d.d[133]*1;
  residual += temp*temp;
  temp = work1d.KKT[267]-1*work1d.d[134]*1;
  residual += temp*temp;
  temp = work1d.KKT[269]-1*work1d.d[135]*1;
  residual += temp*temp;
  temp = work1d.KKT[271]-1*work1d.d[136]*1;
  residual += temp*temp;
  temp = work1d.KKT[273]-1*work1d.d[137]*1;
  residual += temp*temp;
  temp = work1d.KKT[275]-1*work1d.d[138]*1;
  residual += temp*temp;
  temp = work1d.KKT[277]-1*work1d.d[139]*1;
  residual += temp*temp;
  temp = work1d.KKT[279]-1*work1d.d[140]*1;
  residual += temp*temp;
  temp = work1d.KKT[281]-1*work1d.d[141]*1;
  residual += temp*temp;
  temp = work1d.KKT[283]-1*work1d.d[142]*1;
  residual += temp*temp;
  temp = work1d.KKT[285]-1*work1d.d[143]*1;
  residual += temp*temp;
  temp = work1d.KKT[287]-1*work1d.d[144]*1;
  residual += temp*temp;
  temp = work1d.KKT[289]-1*work1d.d[145]*1;
  residual += temp*temp;
  temp = work1d.KKT[291]-1*work1d.d[146]*1;
  residual += temp*temp;
  temp = work1d.KKT[293]-1*work1d.d[147]*1;
  residual += temp*temp;
  temp = work1d.KKT[295]-1*work1d.d[148]*1;
  residual += temp*temp;
  temp = work1d.KKT[297]-1*work1d.d[149]*1;
  residual += temp*temp;
  temp = work1d.KKT[299]-1*work1d.d[150]*1;
  residual += temp*temp;
  temp = work1d.KKT[301]-1*work1d.d[151]*1;
  residual += temp*temp;
  temp = work1d.KKT[303]-1*work1d.d[152]*1;
  residual += temp*temp;
  temp = work1d.KKT[305]-1*work1d.d[153]*1;
  residual += temp*temp;
  temp = work1d.KKT[307]-1*work1d.d[154]*1;
  residual += temp*temp;
  temp = work1d.KKT[309]-1*work1d.d[155]*1;
  residual += temp*temp;
  temp = work1d.KKT[311]-1*work1d.d[156]*1;
  residual += temp*temp;
  temp = work1d.KKT[313]-1*work1d.d[157]*1;
  residual += temp*temp;
  temp = work1d.KKT[315]-1*work1d.d[158]*1;
  residual += temp*temp;
  temp = work1d.KKT[317]-1*work1d.d[159]*1;
  residual += temp*temp;
  temp = work1d.KKT[319]-1*work1d.d[160]*1;
  residual += temp*temp;
  temp = work1d.KKT[321]-1*work1d.d[161]*1;
  residual += temp*temp;
  temp = work1d.KKT[323]-1*work1d.d[162]*1;
  residual += temp*temp;
  temp = work1d.KKT[325]-1*work1d.d[163]*1;
  residual += temp*temp;
  temp = work1d.KKT[327]-1*work1d.d[164]*1;
  residual += temp*temp;
  temp = work1d.KKT[329]-1*work1d.d[165]*1;
  residual += temp*temp;
  temp = work1d.KKT[331]-1*work1d.d[166]*1;
  residual += temp*temp;
  temp = work1d.KKT[333]-1*work1d.d[167]*1;
  residual += temp*temp;
  temp = work1d.KKT[335]-1*work1d.d[168]*1;
  residual += temp*temp;
  temp = work1d.KKT[337]-1*work1d.d[169]*1;
  residual += temp*temp;
  temp = work1d.KKT[339]-1*work1d.d[170]*1;
  residual += temp*temp;
  temp = work1d.KKT[341]-1*work1d.d[171]*1;
  residual += temp*temp;
  temp = work1d.KKT[343]-1*work1d.d[172]*1;
  residual += temp*temp;
  temp = work1d.KKT[345]-1*work1d.d[173]*1;
  residual += temp*temp;
  temp = work1d.KKT[347]-1*work1d.d[174]*1;
  residual += temp*temp;
  temp = work1d.KKT[349]-1*work1d.d[175]*1;
  residual += temp*temp;
  temp = work1d.KKT[351]-1*work1d.d[176]*1;
  residual += temp*temp;
  temp = work1d.KKT[353]-1*work1d.d[177]*1;
  residual += temp*temp;
  temp = work1d.KKT[355]-1*work1d.d[178]*1;
  residual += temp*temp;
  temp = work1d.KKT[357]-1*work1d.d[179]*1;
  residual += temp*temp;
  temp = work1d.KKT[359]-1*work1d.d[180]*1;
  residual += temp*temp;
  temp = work1d.KKT[361]-1*work1d.d[181]*1;
  residual += temp*temp;
  temp = work1d.KKT[363]-1*work1d.d[182]*1;
  residual += temp*temp;
  temp = work1d.KKT[365]-1*work1d.d[183]*1;
  residual += temp*temp;
  temp = work1d.KKT[367]-1*work1d.d[184]*1;
  residual += temp*temp;
  temp = work1d.KKT[369]-1*work1d.d[185]*1;
  residual += temp*temp;
  temp = work1d.KKT[371]-1*work1d.d[186]*1;
  residual += temp*temp;
  temp = work1d.KKT[373]-1*work1d.d[187]*1;
  residual += temp*temp;
  temp = work1d.KKT[375]-1*work1d.d[188]*1;
  residual += temp*temp;
  temp = work1d.KKT[377]-1*work1d.d[189]*1;
  residual += temp*temp;
  temp = work1d.KKT[379]-1*work1d.d[190]*1;
  residual += temp*temp;
  temp = work1d.KKT[381]-1*work1d.d[191]*1;
  residual += temp*temp;
  temp = work1d.KKT[383]-1*work1d.d[192]*1;
  residual += temp*temp;
  temp = work1d.KKT[385]-1*work1d.d[193]*1;
  residual += temp*temp;
  temp = work1d.KKT[387]-1*work1d.d[194]*1;
  residual += temp*temp;
  temp = work1d.KKT[389]-1*work1d.d[195]*1;
  residual += temp*temp;
  temp = work1d.KKT[391]-1*work1d.d[196]*1;
  residual += temp*temp;
  temp = work1d.KKT[393]-1*work1d.d[197]*1;
  residual += temp*temp;
  temp = work1d.KKT[395]-1*work1d.d[198]*1;
  residual += temp*temp;
  temp = work1d.KKT[397]-1*work1d.d[199]*1;
  residual += temp*temp;
  temp = work1d.KKT[399]-1*work1d.d[200]*1;
  residual += temp*temp;
  temp = work1d.KKT[401]-1*work1d.d[201]*1;
  residual += temp*temp;
  temp = work1d.KKT[403]-1*work1d.d[202]*1;
  residual += temp*temp;
  temp = work1d.KKT[405]-1*work1d.d[203]*1;
  residual += temp*temp;
  temp = work1d.KKT[407]-1*work1d.d[204]*1;
  residual += temp*temp;
  temp = work1d.KKT[409]-1*work1d.d[205]*1;
  residual += temp*temp;
  temp = work1d.KKT[411]-1*work1d.d[206]*1;
  residual += temp*temp;
  temp = work1d.KKT[413]-1*work1d.d[207]*1;
  residual += temp*temp;
  temp = work1d.KKT[415]-1*work1d.d[208]*1;
  residual += temp*temp;
  temp = work1d.KKT[417]-1*work1d.d[209]*1;
  residual += temp*temp;
  temp = work1d.KKT[419]-1*work1d.d[210]*1;
  residual += temp*temp;
  temp = work1d.KKT[421]-1*work1d.d[211]*1;
  residual += temp*temp;
  temp = work1d.KKT[423]-1*work1d.d[212]*1;
  residual += temp*temp;
  temp = work1d.KKT[425]-1*work1d.d[213]*1;
  residual += temp*temp;
  temp = work1d.KKT[427]-1*work1d.d[214]*1;
  residual += temp*temp;
  temp = work1d.KKT[429]-1*work1d.d[215]*1;
  residual += temp*temp;
  temp = work1d.KKT[431]-1*work1d.d[216]*1;
  residual += temp*temp;
  temp = work1d.KKT[433]-1*work1d.d[217]*1;
  residual += temp*temp;
  temp = work1d.KKT[435]-1*work1d.d[218]*1;
  residual += temp*temp;
  temp = work1d.KKT[437]-1*work1d.d[219]*1;
  residual += temp*temp;
  temp = work1d.KKT[439]-1*work1d.d[220]*1;
  residual += temp*temp;
  temp = work1d.KKT[441]-1*work1d.d[221]*1;
  residual += temp*temp;
  temp = work1d.KKT[443]-1*work1d.d[222]*1;
  residual += temp*temp;
  temp = work1d.KKT[445]-1*work1d.d[223]*1;
  residual += temp*temp;
  temp = work1d.KKT[447]-1*work1d.d[224]*1;
  residual += temp*temp;
  temp = work1d.KKT[449]-1*work1d.d[225]*1;
  residual += temp*temp;
  temp = work1d.KKT[451]-1*work1d.d[226]*1;
  residual += temp*temp;
  temp = work1d.KKT[453]-1*work1d.d[227]*1;
  residual += temp*temp;
  temp = work1d.KKT[455]-1*work1d.d[228]*1;
  residual += temp*temp;
  temp = work1d.KKT[457]-1*work1d.d[229]*1;
  residual += temp*temp;
  temp = work1d.KKT[459]-1*work1d.d[230]*1;
  residual += temp*temp;
  temp = work1d.KKT[461]-1*work1d.d[231]*1;
  residual += temp*temp;
  temp = work1d.KKT[463]-1*work1d.d[232]*1;
  residual += temp*temp;
  temp = work1d.KKT[465]-1*work1d.d[233]*1;
  residual += temp*temp;
  temp = work1d.KKT[467]-1*work1d.d[234]*1;
  residual += temp*temp;
  temp = work1d.KKT[469]-1*work1d.d[235]*1;
  residual += temp*temp;
  temp = work1d.KKT[471]-1*work1d.d[236]*1;
  residual += temp*temp;
  temp = work1d.KKT[473]-1*work1d.d[237]*1;
  residual += temp*temp;
  temp = work1d.KKT[475]-1*work1d.d[238]*1;
  residual += temp*temp;
  temp = work1d.KKT[477]-1*work1d.d[239]*1;
  residual += temp*temp;
  temp = work1d.KKT[479]-1*work1d.d[240]*1;
  residual += temp*temp;
  temp = work1d.KKT[481]-1*work1d.d[241]*1;
  residual += temp*temp;
  temp = work1d.KKT[483]-1*work1d.d[242]*1;
  residual += temp*temp;
  temp = work1d.KKT[485]-1*work1d.d[243]*1;
  residual += temp*temp;
  temp = work1d.KKT[487]-1*work1d.d[244]*1;
  residual += temp*temp;
  temp = work1d.KKT[489]-1*work1d.d[245]*1;
  residual += temp*temp;
  temp = work1d.KKT[491]-1*work1d.d[246]*1;
  residual += temp*temp;
  temp = work1d.KKT[493]-1*work1d.d[247]*1;
  residual += temp*temp;
  temp = work1d.KKT[495]-1*work1d.d[248]*1;
  residual += temp*temp;
  temp = work1d.KKT[497]-1*work1d.d[249]*1;
  residual += temp*temp;
  temp = work1d.KKT[499]-1*work1d.d[250]*1;
  residual += temp*temp;
  temp = work1d.KKT[501]-1*work1d.d[251]*1;
  residual += temp*temp;
  temp = work1d.KKT[503]-1*work1d.d[252]*1;
  residual += temp*temp;
  temp = work1d.KKT[505]-1*work1d.d[253]*1;
  residual += temp*temp;
  temp = work1d.KKT[507]-1*work1d.d[254]*1;
  residual += temp*temp;
  temp = work1d.KKT[509]-1*work1d.d[255]*1;
  residual += temp*temp;
  temp = work1d.KKT[511]-1*work1d.d[256]*1;
  residual += temp*temp;
  temp = work1d.KKT[513]-1*work1d.d[257]*1;
  residual += temp*temp;
  temp = work1d.KKT[515]-1*work1d.d[258]*1;
  residual += temp*temp;
  temp = work1d.KKT[517]-1*work1d.d[259]*1;
  residual += temp*temp;
  temp = work1d.KKT[519]-1*work1d.d[260]*1;
  residual += temp*temp;
  temp = work1d.KKT[521]-1*work1d.d[261]*1;
  residual += temp*temp;
  temp = work1d.KKT[523]-1*work1d.d[262]*1;
  residual += temp*temp;
  temp = work1d.KKT[525]-1*work1d.d[263]*1;
  residual += temp*temp;
  temp = work1d.KKT[527]-1*work1d.d[264]*1;
  residual += temp*temp;
  temp = work1d.KKT[529]-1*work1d.d[265]*1;
  residual += temp*temp;
  temp = work1d.KKT[531]-1*work1d.d[266]*1;
  residual += temp*temp;
  temp = work1d.KKT[533]-1*work1d.d[267]*1;
  residual += temp*temp;
  temp = work1d.KKT[535]-1*work1d.d[268]*1;
  residual += temp*temp;
  temp = work1d.KKT[537]-1*work1d.d[269]*1;
  residual += temp*temp;
  temp = work1d.KKT[539]-1*work1d.d[270]*1;
  residual += temp*temp;
  temp = work1d.KKT[541]-1*work1d.d[271]*1;
  residual += temp*temp;
  temp = work1d.KKT[543]-1*work1d.d[272]*1;
  residual += temp*temp;
  temp = work1d.KKT[545]-1*work1d.d[273]*1;
  residual += temp*temp;
  temp = work1d.KKT[547]-1*work1d.d[274]*1;
  residual += temp*temp;
  temp = work1d.KKT[549]-1*work1d.d[275]*1;
  residual += temp*temp;
  temp = work1d.KKT[551]-1*work1d.d[276]*1;
  residual += temp*temp;
  temp = work1d.KKT[553]-1*work1d.d[277]*1;
  residual += temp*temp;
  temp = work1d.KKT[555]-1*work1d.d[278]*1;
  residual += temp*temp;
  temp = work1d.KKT[557]-1*work1d.d[279]*1;
  residual += temp*temp;
  temp = work1d.KKT[559]-1*work1d.d[280]*1;
  residual += temp*temp;
  temp = work1d.KKT[561]-1*work1d.d[281]*1;
  residual += temp*temp;
  temp = work1d.KKT[563]-1*work1d.d[282]*1;
  residual += temp*temp;
  temp = work1d.KKT[565]-1*work1d.d[283]*1;
  residual += temp*temp;
  temp = work1d.KKT[567]-1*work1d.d[284]*1;
  residual += temp*temp;
  temp = work1d.KKT[569]-1*work1d.d[285]*1;
  residual += temp*temp;
  temp = work1d.KKT[571]-1*work1d.d[286]*1;
  residual += temp*temp;
  temp = work1d.KKT[573]-1*work1d.d[287]*1;
  residual += temp*temp;
  temp = work1d.KKT[575]-1*work1d.d[288]*1;
  residual += temp*temp;
  temp = work1d.KKT[577]-1*work1d.d[289]*1;
  residual += temp*temp;
  temp = work1d.KKT[579]-1*work1d.d[290]*1;
  residual += temp*temp;
  temp = work1d.KKT[581]-1*work1d.d[291]*1;
  residual += temp*temp;
  temp = work1d.KKT[583]-1*work1d.d[292]*1;
  residual += temp*temp;
  temp = work1d.KKT[585]-1*work1d.d[293]*1;
  residual += temp*temp;
  temp = work1d.KKT[587]-1*work1d.d[294]*1;
  residual += temp*temp;
  temp = work1d.KKT[589]-1*work1d.d[295]*1;
  residual += temp*temp;
  temp = work1d.KKT[591]-1*work1d.d[296]*1;
  residual += temp*temp;
  temp = work1d.KKT[593]-1*work1d.d[297]*1;
  residual += temp*temp;
  temp = work1d.KKT[595]-1*work1d.d[298]*1;
  residual += temp*temp;
  temp = work1d.KKT[597]-1*work1d.d[299]*1;
  residual += temp*temp;
  temp = work1d.KKT[599]-1*work1d.d[300]*1;
  residual += temp*temp;
  temp = work1d.KKT[601]-1*work1d.d[301]*1;
  residual += temp*temp;
  temp = work1d.KKT[603]-1*work1d.d[302]*1;
  residual += temp*temp;
  temp = work1d.KKT[605]-1*work1d.d[303]*1;
  residual += temp*temp;
  temp = work1d.KKT[607]-1*work1d.d[304]*1;
  residual += temp*temp;
  temp = work1d.KKT[609]-1*work1d.d[305]*1;
  residual += temp*temp;
  temp = work1d.KKT[611]-1*work1d.d[306]*1;
  residual += temp*temp;
  temp = work1d.KKT[613]-1*work1d.d[307]*1;
  residual += temp*temp;
  temp = work1d.KKT[615]-1*work1d.d[308]*1;
  residual += temp*temp;
  temp = work1d.KKT[617]-1*work1d.d[309]*1;
  residual += temp*temp;
  temp = work1d.KKT[619]-1*work1d.d[310]*1;
  residual += temp*temp;
  temp = work1d.KKT[621]-1*work1d.d[311]*1;
  residual += temp*temp;
  temp = work1d.KKT[623]-1*work1d.d[312]*1;
  residual += temp*temp;
  temp = work1d.KKT[625]-1*work1d.d[313]*1;
  residual += temp*temp;
  temp = work1d.KKT[627]-1*work1d.d[314]*1;
  residual += temp*temp;
  temp = work1d.KKT[629]-1*work1d.d[315]*1;
  residual += temp*temp;
  temp = work1d.KKT[631]-1*work1d.d[316]*1;
  residual += temp*temp;
  temp = work1d.KKT[633]-1*work1d.d[317]*1;
  residual += temp*temp;
  temp = work1d.KKT[635]-1*work1d.d[318]*1;
  residual += temp*temp;
  temp = work1d.KKT[637]-1*work1d.d[319]*1;
  residual += temp*temp;
  temp = work1d.KKT[639]-1*work1d.d[320]*1;
  residual += temp*temp;
  temp = work1d.KKT[2]-work1d.L[82]*work1d.d[1]*1;
  residual += temp*temp;
  temp = work1d.KKT[4]-work1d.L[84]*work1d.d[2]*1;
  residual += temp*temp;
  temp = work1d.KKT[6]-work1d.L[86]*work1d.d[3]*1;
  residual += temp*temp;
  temp = work1d.KKT[8]-work1d.L[89]*work1d.d[4]*1;
  residual += temp*temp;
  temp = work1d.KKT[10]-work1d.L[91]*work1d.d[5]*1;
  residual += temp*temp;
  temp = work1d.KKT[12]-work1d.L[93]*work1d.d[6]*1;
  residual += temp*temp;
  temp = work1d.KKT[14]-work1d.L[96]*work1d.d[7]*1;
  residual += temp*temp;
  temp = work1d.KKT[16]-work1d.L[98]*work1d.d[8]*1;
  residual += temp*temp;
  temp = work1d.KKT[18]-work1d.L[100]*work1d.d[9]*1;
  residual += temp*temp;
  temp = work1d.KKT[20]-work1d.L[103]*work1d.d[10]*1;
  residual += temp*temp;
  temp = work1d.KKT[22]-work1d.L[105]*work1d.d[11]*1;
  residual += temp*temp;
  temp = work1d.KKT[24]-work1d.L[107]*work1d.d[12]*1;
  residual += temp*temp;
  temp = work1d.KKT[26]-work1d.L[110]*work1d.d[13]*1;
  residual += temp*temp;
  temp = work1d.KKT[28]-work1d.L[112]*work1d.d[14]*1;
  residual += temp*temp;
  temp = work1d.KKT[30]-work1d.L[114]*work1d.d[15]*1;
  residual += temp*temp;
  temp = work1d.KKT[32]-work1d.L[117]*work1d.d[16]*1;
  residual += temp*temp;
  temp = work1d.KKT[34]-work1d.L[119]*work1d.d[17]*1;
  residual += temp*temp;
  temp = work1d.KKT[36]-work1d.L[121]*work1d.d[18]*1;
  residual += temp*temp;
  temp = work1d.KKT[38]-work1d.L[124]*work1d.d[19]*1;
  residual += temp*temp;
  temp = work1d.KKT[40]-work1d.L[126]*work1d.d[20]*1;
  residual += temp*temp;
  temp = work1d.KKT[42]-work1d.L[128]*work1d.d[21]*1;
  residual += temp*temp;
  temp = work1d.KKT[44]-work1d.L[131]*work1d.d[22]*1;
  residual += temp*temp;
  temp = work1d.KKT[46]-work1d.L[133]*work1d.d[23]*1;
  residual += temp*temp;
  temp = work1d.KKT[48]-work1d.L[135]*work1d.d[24]*1;
  residual += temp*temp;
  temp = work1d.KKT[50]-work1d.L[138]*work1d.d[25]*1;
  residual += temp*temp;
  temp = work1d.KKT[52]-work1d.L[140]*work1d.d[26]*1;
  residual += temp*temp;
  temp = work1d.KKT[54]-work1d.L[142]*work1d.d[27]*1;
  residual += temp*temp;
  temp = work1d.KKT[56]-work1d.L[145]*work1d.d[28]*1;
  residual += temp*temp;
  temp = work1d.KKT[58]-work1d.L[147]*work1d.d[29]*1;
  residual += temp*temp;
  temp = work1d.KKT[60]-work1d.L[149]*work1d.d[30]*1;
  residual += temp*temp;
  temp = work1d.KKT[62]-work1d.L[152]*work1d.d[31]*1;
  residual += temp*temp;
  temp = work1d.KKT[64]-work1d.L[154]*work1d.d[32]*1;
  residual += temp*temp;
  temp = work1d.KKT[66]-work1d.L[156]*work1d.d[33]*1;
  residual += temp*temp;
  temp = work1d.KKT[68]-work1d.L[159]*work1d.d[34]*1;
  residual += temp*temp;
  temp = work1d.KKT[70]-work1d.L[161]*work1d.d[35]*1;
  residual += temp*temp;
  temp = work1d.KKT[72]-work1d.L[163]*work1d.d[36]*1;
  residual += temp*temp;
  temp = work1d.KKT[74]-work1d.L[166]*work1d.d[37]*1;
  residual += temp*temp;
  temp = work1d.KKT[76]-work1d.L[168]*work1d.d[38]*1;
  residual += temp*temp;
  temp = work1d.KKT[78]-work1d.L[170]*work1d.d[39]*1;
  residual += temp*temp;
  temp = work1d.KKT[80]-work1d.L[173]*work1d.d[40]*1;
  residual += temp*temp;
  temp = work1d.KKT[82]-work1d.L[175]*work1d.d[41]*1;
  residual += temp*temp;
  temp = work1d.KKT[84]-work1d.L[177]*work1d.d[42]*1;
  residual += temp*temp;
  temp = work1d.KKT[86]-work1d.L[180]*work1d.d[43]*1;
  residual += temp*temp;
  temp = work1d.KKT[88]-work1d.L[182]*work1d.d[44]*1;
  residual += temp*temp;
  temp = work1d.KKT[90]-work1d.L[184]*work1d.d[45]*1;
  residual += temp*temp;
  temp = work1d.KKT[92]-work1d.L[187]*work1d.d[46]*1;
  residual += temp*temp;
  temp = work1d.KKT[94]-work1d.L[189]*work1d.d[47]*1;
  residual += temp*temp;
  temp = work1d.KKT[96]-work1d.L[191]*work1d.d[48]*1;
  residual += temp*temp;
  temp = work1d.KKT[98]-work1d.L[194]*work1d.d[49]*1;
  residual += temp*temp;
  temp = work1d.KKT[100]-work1d.L[196]*work1d.d[50]*1;
  residual += temp*temp;
  temp = work1d.KKT[102]-work1d.L[198]*work1d.d[51]*1;
  residual += temp*temp;
  temp = work1d.KKT[104]-work1d.L[201]*work1d.d[52]*1;
  residual += temp*temp;
  temp = work1d.KKT[106]-work1d.L[203]*work1d.d[53]*1;
  residual += temp*temp;
  temp = work1d.KKT[108]-work1d.L[205]*work1d.d[54]*1;
  residual += temp*temp;
  temp = work1d.KKT[110]-work1d.L[208]*work1d.d[55]*1;
  residual += temp*temp;
  temp = work1d.KKT[112]-work1d.L[210]*work1d.d[56]*1;
  residual += temp*temp;
  temp = work1d.KKT[114]-work1d.L[212]*work1d.d[57]*1;
  residual += temp*temp;
  temp = work1d.KKT[116]-work1d.L[215]*work1d.d[58]*1;
  residual += temp*temp;
  temp = work1d.KKT[118]-work1d.L[217]*work1d.d[59]*1;
  residual += temp*temp;
  temp = work1d.KKT[120]-work1d.L[219]*work1d.d[60]*1;
  residual += temp*temp;
  temp = work1d.KKT[122]-work1d.L[222]*work1d.d[61]*1;
  residual += temp*temp;
  temp = work1d.KKT[124]-work1d.L[224]*work1d.d[62]*1;
  residual += temp*temp;
  temp = work1d.KKT[126]-work1d.L[226]*work1d.d[63]*1;
  residual += temp*temp;
  temp = work1d.KKT[128]-work1d.L[229]*work1d.d[64]*1;
  residual += temp*temp;
  temp = work1d.KKT[130]-work1d.L[231]*work1d.d[65]*1;
  residual += temp*temp;
  temp = work1d.KKT[132]-work1d.L[233]*work1d.d[66]*1;
  residual += temp*temp;
  temp = work1d.KKT[134]-work1d.L[236]*work1d.d[67]*1;
  residual += temp*temp;
  temp = work1d.KKT[136]-work1d.L[238]*work1d.d[68]*1;
  residual += temp*temp;
  temp = work1d.KKT[138]-work1d.L[240]*work1d.d[69]*1;
  residual += temp*temp;
  temp = work1d.KKT[140]-work1d.L[243]*work1d.d[70]*1;
  residual += temp*temp;
  temp = work1d.KKT[142]-work1d.L[245]*work1d.d[71]*1;
  residual += temp*temp;
  temp = work1d.KKT[144]-work1d.L[247]*work1d.d[72]*1;
  residual += temp*temp;
  temp = work1d.KKT[146]-work1d.L[250]*work1d.d[73]*1;
  residual += temp*temp;
  temp = work1d.KKT[148]-work1d.L[252]*work1d.d[74]*1;
  residual += temp*temp;
  temp = work1d.KKT[150]-work1d.L[254]*work1d.d[75]*1;
  residual += temp*temp;
  temp = work1d.KKT[152]-work1d.L[257]*work1d.d[76]*1;
  residual += temp*temp;
  temp = work1d.KKT[154]-work1d.L[259]*work1d.d[77]*1;
  residual += temp*temp;
  temp = work1d.KKT[156]-work1d.L[261]*work1d.d[78]*1;
  residual += temp*temp;
  temp = work1d.KKT[158]-work1d.L[264]*work1d.d[79]*1;
  residual += temp*temp;
  temp = work1d.KKT[160]-work1d.L[266]*work1d.d[80]*1;
  residual += temp*temp;
  temp = work1d.KKT[162]-work1d.L[268]*work1d.d[81]*1;
  residual += temp*temp;
  temp = work1d.KKT[164]-work1d.L[271]*work1d.d[82]*1;
  residual += temp*temp;
  temp = work1d.KKT[166]-work1d.L[273]*work1d.d[83]*1;
  residual += temp*temp;
  temp = work1d.KKT[168]-work1d.L[275]*work1d.d[84]*1;
  residual += temp*temp;
  temp = work1d.KKT[170]-work1d.L[278]*work1d.d[85]*1;
  residual += temp*temp;
  temp = work1d.KKT[172]-work1d.L[280]*work1d.d[86]*1;
  residual += temp*temp;
  temp = work1d.KKT[174]-work1d.L[282]*work1d.d[87]*1;
  residual += temp*temp;
  temp = work1d.KKT[176]-work1d.L[285]*work1d.d[88]*1;
  residual += temp*temp;
  temp = work1d.KKT[178]-work1d.L[287]*work1d.d[89]*1;
  residual += temp*temp;
  temp = work1d.KKT[180]-work1d.L[289]*work1d.d[90]*1;
  residual += temp*temp;
  temp = work1d.KKT[182]-work1d.L[292]*work1d.d[91]*1;
  residual += temp*temp;
  temp = work1d.KKT[184]-work1d.L[294]*work1d.d[92]*1;
  residual += temp*temp;
  temp = work1d.KKT[186]-work1d.L[296]*work1d.d[93]*1;
  residual += temp*temp;
  temp = work1d.KKT[188]-work1d.L[299]*work1d.d[94]*1;
  residual += temp*temp;
  temp = work1d.KKT[190]-work1d.L[301]*work1d.d[95]*1;
  residual += temp*temp;
  temp = work1d.KKT[192]-work1d.L[303]*work1d.d[96]*1;
  residual += temp*temp;
  temp = work1d.KKT[194]-work1d.L[306]*work1d.d[97]*1;
  residual += temp*temp;
  temp = work1d.KKT[196]-work1d.L[308]*work1d.d[98]*1;
  residual += temp*temp;
  temp = work1d.KKT[198]-work1d.L[310]*work1d.d[99]*1;
  residual += temp*temp;
  temp = work1d.KKT[200]-work1d.L[313]*work1d.d[100]*1;
  residual += temp*temp;
  temp = work1d.KKT[202]-work1d.L[315]*work1d.d[101]*1;
  residual += temp*temp;
  temp = work1d.KKT[204]-work1d.L[317]*work1d.d[102]*1;
  residual += temp*temp;
  temp = work1d.KKT[206]-work1d.L[320]*work1d.d[103]*1;
  residual += temp*temp;
  temp = work1d.KKT[208]-work1d.L[322]*work1d.d[104]*1;
  residual += temp*temp;
  temp = work1d.KKT[210]-work1d.L[324]*work1d.d[105]*1;
  residual += temp*temp;
  temp = work1d.KKT[212]-work1d.L[327]*work1d.d[106]*1;
  residual += temp*temp;
  temp = work1d.KKT[214]-work1d.L[329]*work1d.d[107]*1;
  residual += temp*temp;
  temp = work1d.KKT[216]-work1d.L[331]*work1d.d[108]*1;
  residual += temp*temp;
  temp = work1d.KKT[218]-work1d.L[334]*work1d.d[109]*1;
  residual += temp*temp;
  temp = work1d.KKT[220]-work1d.L[336]*work1d.d[110]*1;
  residual += temp*temp;
  temp = work1d.KKT[222]-work1d.L[338]*work1d.d[111]*1;
  residual += temp*temp;
  temp = work1d.KKT[224]-work1d.L[341]*work1d.d[112]*1;
  residual += temp*temp;
  temp = work1d.KKT[226]-work1d.L[343]*work1d.d[113]*1;
  residual += temp*temp;
  temp = work1d.KKT[228]-work1d.L[345]*work1d.d[114]*1;
  residual += temp*temp;
  temp = work1d.KKT[230]-work1d.L[348]*work1d.d[115]*1;
  residual += temp*temp;
  temp = work1d.KKT[232]-work1d.L[350]*work1d.d[116]*1;
  residual += temp*temp;
  temp = work1d.KKT[234]-work1d.L[352]*work1d.d[117]*1;
  residual += temp*temp;
  temp = work1d.KKT[236]-work1d.L[355]*work1d.d[118]*1;
  residual += temp*temp;
  temp = work1d.KKT[238]-work1d.L[357]*work1d.d[119]*1;
  residual += temp*temp;
  temp = work1d.KKT[240]-work1d.L[359]*work1d.d[120]*1;
  residual += temp*temp;
  temp = work1d.KKT[242]-work1d.L[365]*work1d.d[121]*1;
  residual += temp*temp;
  temp = work1d.KKT[244]-work1d.L[367]*work1d.d[122]*1;
  residual += temp*temp;
  temp = work1d.KKT[246]-work1d.L[369]*work1d.d[123]*1;
  residual += temp*temp;
  temp = work1d.KKT[248]-work1d.L[372]*work1d.d[124]*1;
  residual += temp*temp;
  temp = work1d.KKT[250]-work1d.L[374]*work1d.d[125]*1;
  residual += temp*temp;
  temp = work1d.KKT[252]-work1d.L[376]*work1d.d[126]*1;
  residual += temp*temp;
  temp = work1d.KKT[254]-work1d.L[379]*work1d.d[127]*1;
  residual += temp*temp;
  temp = work1d.KKT[256]-work1d.L[381]*work1d.d[128]*1;
  residual += temp*temp;
  temp = work1d.KKT[258]-work1d.L[383]*work1d.d[129]*1;
  residual += temp*temp;
  temp = work1d.KKT[260]-work1d.L[386]*work1d.d[130]*1;
  residual += temp*temp;
  temp = work1d.KKT[262]-work1d.L[388]*work1d.d[131]*1;
  residual += temp*temp;
  temp = work1d.KKT[264]-work1d.L[390]*work1d.d[132]*1;
  residual += temp*temp;
  temp = work1d.KKT[266]-work1d.L[393]*work1d.d[133]*1;
  residual += temp*temp;
  temp = work1d.KKT[268]-work1d.L[395]*work1d.d[134]*1;
  residual += temp*temp;
  temp = work1d.KKT[270]-work1d.L[397]*work1d.d[135]*1;
  residual += temp*temp;
  temp = work1d.KKT[272]-work1d.L[400]*work1d.d[136]*1;
  residual += temp*temp;
  temp = work1d.KKT[274]-work1d.L[402]*work1d.d[137]*1;
  residual += temp*temp;
  temp = work1d.KKT[276]-work1d.L[404]*work1d.d[138]*1;
  residual += temp*temp;
  temp = work1d.KKT[278]-work1d.L[407]*work1d.d[139]*1;
  residual += temp*temp;
  temp = work1d.KKT[280]-work1d.L[409]*work1d.d[140]*1;
  residual += temp*temp;
  temp = work1d.KKT[282]-work1d.L[411]*work1d.d[141]*1;
  residual += temp*temp;
  temp = work1d.KKT[284]-work1d.L[414]*work1d.d[142]*1;
  residual += temp*temp;
  temp = work1d.KKT[286]-work1d.L[416]*work1d.d[143]*1;
  residual += temp*temp;
  temp = work1d.KKT[288]-work1d.L[418]*work1d.d[144]*1;
  residual += temp*temp;
  temp = work1d.KKT[290]-work1d.L[421]*work1d.d[145]*1;
  residual += temp*temp;
  temp = work1d.KKT[292]-work1d.L[423]*work1d.d[146]*1;
  residual += temp*temp;
  temp = work1d.KKT[294]-work1d.L[425]*work1d.d[147]*1;
  residual += temp*temp;
  temp = work1d.KKT[296]-work1d.L[428]*work1d.d[148]*1;
  residual += temp*temp;
  temp = work1d.KKT[298]-work1d.L[430]*work1d.d[149]*1;
  residual += temp*temp;
  temp = work1d.KKT[300]-work1d.L[432]*work1d.d[150]*1;
  residual += temp*temp;
  temp = work1d.KKT[302]-work1d.L[435]*work1d.d[151]*1;
  residual += temp*temp;
  temp = work1d.KKT[304]-work1d.L[437]*work1d.d[152]*1;
  residual += temp*temp;
  temp = work1d.KKT[306]-work1d.L[439]*work1d.d[153]*1;
  residual += temp*temp;
  temp = work1d.KKT[308]-work1d.L[442]*work1d.d[154]*1;
  residual += temp*temp;
  temp = work1d.KKT[310]-work1d.L[444]*work1d.d[155]*1;
  residual += temp*temp;
  temp = work1d.KKT[312]-work1d.L[446]*work1d.d[156]*1;
  residual += temp*temp;
  temp = work1d.KKT[314]-work1d.L[449]*work1d.d[157]*1;
  residual += temp*temp;
  temp = work1d.KKT[316]-work1d.L[451]*work1d.d[158]*1;
  residual += temp*temp;
  temp = work1d.KKT[318]-work1d.L[453]*work1d.d[159]*1;
  residual += temp*temp;
  temp = work1d.KKT[320]-work1d.L[456]*work1d.d[160]*1;
  residual += temp*temp;
  temp = work1d.KKT[322]-work1d.L[458]*work1d.d[161]*1;
  residual += temp*temp;
  temp = work1d.KKT[324]-work1d.L[460]*work1d.d[162]*1;
  residual += temp*temp;
  temp = work1d.KKT[326]-work1d.L[463]*work1d.d[163]*1;
  residual += temp*temp;
  temp = work1d.KKT[328]-work1d.L[465]*work1d.d[164]*1;
  residual += temp*temp;
  temp = work1d.KKT[330]-work1d.L[467]*work1d.d[165]*1;
  residual += temp*temp;
  temp = work1d.KKT[332]-work1d.L[470]*work1d.d[166]*1;
  residual += temp*temp;
  temp = work1d.KKT[334]-work1d.L[472]*work1d.d[167]*1;
  residual += temp*temp;
  temp = work1d.KKT[336]-work1d.L[474]*work1d.d[168]*1;
  residual += temp*temp;
  temp = work1d.KKT[338]-work1d.L[477]*work1d.d[169]*1;
  residual += temp*temp;
  temp = work1d.KKT[340]-work1d.L[479]*work1d.d[170]*1;
  residual += temp*temp;
  temp = work1d.KKT[342]-work1d.L[481]*work1d.d[171]*1;
  residual += temp*temp;
  temp = work1d.KKT[344]-work1d.L[484]*work1d.d[172]*1;
  residual += temp*temp;
  temp = work1d.KKT[346]-work1d.L[486]*work1d.d[173]*1;
  residual += temp*temp;
  temp = work1d.KKT[348]-work1d.L[488]*work1d.d[174]*1;
  residual += temp*temp;
  temp = work1d.KKT[350]-work1d.L[491]*work1d.d[175]*1;
  residual += temp*temp;
  temp = work1d.KKT[352]-work1d.L[493]*work1d.d[176]*1;
  residual += temp*temp;
  temp = work1d.KKT[354]-work1d.L[495]*work1d.d[177]*1;
  residual += temp*temp;
  temp = work1d.KKT[356]-work1d.L[498]*work1d.d[178]*1;
  residual += temp*temp;
  temp = work1d.KKT[358]-work1d.L[500]*work1d.d[179]*1;
  residual += temp*temp;
  temp = work1d.KKT[360]-work1d.L[502]*work1d.d[180]*1;
  residual += temp*temp;
  temp = work1d.KKT[362]-work1d.L[505]*work1d.d[181]*1;
  residual += temp*temp;
  temp = work1d.KKT[364]-work1d.L[507]*work1d.d[182]*1;
  residual += temp*temp;
  temp = work1d.KKT[366]-work1d.L[509]*work1d.d[183]*1;
  residual += temp*temp;
  temp = work1d.KKT[368]-work1d.L[512]*work1d.d[184]*1;
  residual += temp*temp;
  temp = work1d.KKT[370]-work1d.L[514]*work1d.d[185]*1;
  residual += temp*temp;
  temp = work1d.KKT[372]-work1d.L[516]*work1d.d[186]*1;
  residual += temp*temp;
  temp = work1d.KKT[374]-work1d.L[519]*work1d.d[187]*1;
  residual += temp*temp;
  temp = work1d.KKT[376]-work1d.L[521]*work1d.d[188]*1;
  residual += temp*temp;
  temp = work1d.KKT[378]-work1d.L[523]*work1d.d[189]*1;
  residual += temp*temp;
  temp = work1d.KKT[380]-work1d.L[526]*work1d.d[190]*1;
  residual += temp*temp;
  temp = work1d.KKT[382]-work1d.L[528]*work1d.d[191]*1;
  residual += temp*temp;
  temp = work1d.KKT[384]-work1d.L[530]*work1d.d[192]*1;
  residual += temp*temp;
  temp = work1d.KKT[386]-work1d.L[533]*work1d.d[193]*1;
  residual += temp*temp;
  temp = work1d.KKT[388]-work1d.L[535]*work1d.d[194]*1;
  residual += temp*temp;
  temp = work1d.KKT[390]-work1d.L[537]*work1d.d[195]*1;
  residual += temp*temp;
  temp = work1d.KKT[392]-work1d.L[540]*work1d.d[196]*1;
  residual += temp*temp;
  temp = work1d.KKT[394]-work1d.L[542]*work1d.d[197]*1;
  residual += temp*temp;
  temp = work1d.KKT[396]-work1d.L[544]*work1d.d[198]*1;
  residual += temp*temp;
  temp = work1d.KKT[398]-work1d.L[547]*work1d.d[199]*1;
  residual += temp*temp;
  temp = work1d.KKT[400]-work1d.L[549]*work1d.d[200]*1;
  residual += temp*temp;
  temp = work1d.KKT[402]-work1d.L[551]*work1d.d[201]*1;
  residual += temp*temp;
  temp = work1d.KKT[404]-work1d.L[554]*work1d.d[202]*1;
  residual += temp*temp;
  temp = work1d.KKT[406]-work1d.L[556]*work1d.d[203]*1;
  residual += temp*temp;
  temp = work1d.KKT[408]-work1d.L[558]*work1d.d[204]*1;
  residual += temp*temp;
  temp = work1d.KKT[410]-work1d.L[561]*work1d.d[205]*1;
  residual += temp*temp;
  temp = work1d.KKT[412]-work1d.L[563]*work1d.d[206]*1;
  residual += temp*temp;
  temp = work1d.KKT[414]-work1d.L[565]*work1d.d[207]*1;
  residual += temp*temp;
  temp = work1d.KKT[416]-work1d.L[568]*work1d.d[208]*1;
  residual += temp*temp;
  temp = work1d.KKT[418]-work1d.L[570]*work1d.d[209]*1;
  residual += temp*temp;
  temp = work1d.KKT[420]-work1d.L[572]*work1d.d[210]*1;
  residual += temp*temp;
  temp = work1d.KKT[422]-work1d.L[575]*work1d.d[211]*1;
  residual += temp*temp;
  temp = work1d.KKT[424]-work1d.L[577]*work1d.d[212]*1;
  residual += temp*temp;
  temp = work1d.KKT[426]-work1d.L[579]*work1d.d[213]*1;
  residual += temp*temp;
  temp = work1d.KKT[428]-work1d.L[582]*work1d.d[214]*1;
  residual += temp*temp;
  temp = work1d.KKT[430]-work1d.L[584]*work1d.d[215]*1;
  residual += temp*temp;
  temp = work1d.KKT[432]-work1d.L[586]*work1d.d[216]*1;
  residual += temp*temp;
  temp = work1d.KKT[434]-work1d.L[589]*work1d.d[217]*1;
  residual += temp*temp;
  temp = work1d.KKT[436]-work1d.L[591]*work1d.d[218]*1;
  residual += temp*temp;
  temp = work1d.KKT[438]-work1d.L[593]*work1d.d[219]*1;
  residual += temp*temp;
  temp = work1d.KKT[440]-work1d.L[596]*work1d.d[220]*1;
  residual += temp*temp;
  temp = work1d.KKT[442]-work1d.L[598]*work1d.d[221]*1;
  residual += temp*temp;
  temp = work1d.KKT[444]-work1d.L[600]*work1d.d[222]*1;
  residual += temp*temp;
  temp = work1d.KKT[446]-work1d.L[603]*work1d.d[223]*1;
  residual += temp*temp;
  temp = work1d.KKT[448]-work1d.L[605]*work1d.d[224]*1;
  residual += temp*temp;
  temp = work1d.KKT[450]-work1d.L[607]*work1d.d[225]*1;
  residual += temp*temp;
  temp = work1d.KKT[452]-work1d.L[610]*work1d.d[226]*1;
  residual += temp*temp;
  temp = work1d.KKT[454]-work1d.L[612]*work1d.d[227]*1;
  residual += temp*temp;
  temp = work1d.KKT[456]-work1d.L[614]*work1d.d[228]*1;
  residual += temp*temp;
  temp = work1d.KKT[458]-work1d.L[617]*work1d.d[229]*1;
  residual += temp*temp;
  temp = work1d.KKT[460]-work1d.L[619]*work1d.d[230]*1;
  residual += temp*temp;
  temp = work1d.KKT[462]-work1d.L[621]*work1d.d[231]*1;
  residual += temp*temp;
  temp = work1d.KKT[464]-work1d.L[624]*work1d.d[232]*1;
  residual += temp*temp;
  temp = work1d.KKT[466]-work1d.L[626]*work1d.d[233]*1;
  residual += temp*temp;
  temp = work1d.KKT[468]-work1d.L[628]*work1d.d[234]*1;
  residual += temp*temp;
  temp = work1d.KKT[470]-work1d.L[631]*work1d.d[235]*1;
  residual += temp*temp;
  temp = work1d.KKT[472]-work1d.L[633]*work1d.d[236]*1;
  residual += temp*temp;
  temp = work1d.KKT[474]-work1d.L[635]*work1d.d[237]*1;
  residual += temp*temp;
  temp = work1d.KKT[476]-work1d.L[638]*work1d.d[238]*1;
  residual += temp*temp;
  temp = work1d.KKT[478]-work1d.L[640]*work1d.d[239]*1;
  residual += temp*temp;
  temp = work1d.KKT[480]-work1d.L[642]*work1d.d[240]*1;
  residual += temp*temp;
  temp = work1d.KKT[482]-work1d.L[0]*work1d.d[241]*1;
  residual += temp*temp;
  temp = work1d.KKT[484]-work1d.L[1]*work1d.d[242]*1;
  residual += temp*temp;
  temp = work1d.KKT[486]-work1d.L[2]*work1d.d[243]*1;
  residual += temp*temp;
  temp = work1d.KKT[488]-work1d.L[3]*work1d.d[244]*1;
  residual += temp*temp;
  temp = work1d.KKT[490]-work1d.L[4]*work1d.d[245]*1;
  residual += temp*temp;
  temp = work1d.KKT[492]-work1d.L[5]*work1d.d[246]*1;
  residual += temp*temp;
  temp = work1d.KKT[494]-work1d.L[6]*work1d.d[247]*1;
  residual += temp*temp;
  temp = work1d.KKT[496]-work1d.L[7]*work1d.d[248]*1;
  residual += temp*temp;
  temp = work1d.KKT[498]-work1d.L[8]*work1d.d[249]*1;
  residual += temp*temp;
  temp = work1d.KKT[500]-work1d.L[9]*work1d.d[250]*1;
  residual += temp*temp;
  temp = work1d.KKT[502]-work1d.L[10]*work1d.d[251]*1;
  residual += temp*temp;
  temp = work1d.KKT[504]-work1d.L[11]*work1d.d[252]*1;
  residual += temp*temp;
  temp = work1d.KKT[506]-work1d.L[12]*work1d.d[253]*1;
  residual += temp*temp;
  temp = work1d.KKT[508]-work1d.L[13]*work1d.d[254]*1;
  residual += temp*temp;
  temp = work1d.KKT[510]-work1d.L[14]*work1d.d[255]*1;
  residual += temp*temp;
  temp = work1d.KKT[512]-work1d.L[15]*work1d.d[256]*1;
  residual += temp*temp;
  temp = work1d.KKT[514]-work1d.L[16]*work1d.d[257]*1;
  residual += temp*temp;
  temp = work1d.KKT[516]-work1d.L[17]*work1d.d[258]*1;
  residual += temp*temp;
  temp = work1d.KKT[518]-work1d.L[18]*work1d.d[259]*1;
  residual += temp*temp;
  temp = work1d.KKT[520]-work1d.L[19]*work1d.d[260]*1;
  residual += temp*temp;
  temp = work1d.KKT[522]-work1d.L[20]*work1d.d[261]*1;
  residual += temp*temp;
  temp = work1d.KKT[524]-work1d.L[21]*work1d.d[262]*1;
  residual += temp*temp;
  temp = work1d.KKT[526]-work1d.L[22]*work1d.d[263]*1;
  residual += temp*temp;
  temp = work1d.KKT[528]-work1d.L[23]*work1d.d[264]*1;
  residual += temp*temp;
  temp = work1d.KKT[530]-work1d.L[24]*work1d.d[265]*1;
  residual += temp*temp;
  temp = work1d.KKT[532]-work1d.L[25]*work1d.d[266]*1;
  residual += temp*temp;
  temp = work1d.KKT[534]-work1d.L[26]*work1d.d[267]*1;
  residual += temp*temp;
  temp = work1d.KKT[536]-work1d.L[27]*work1d.d[268]*1;
  residual += temp*temp;
  temp = work1d.KKT[538]-work1d.L[28]*work1d.d[269]*1;
  residual += temp*temp;
  temp = work1d.KKT[540]-work1d.L[29]*work1d.d[270]*1;
  residual += temp*temp;
  temp = work1d.KKT[542]-work1d.L[30]*work1d.d[271]*1;
  residual += temp*temp;
  temp = work1d.KKT[544]-work1d.L[31]*work1d.d[272]*1;
  residual += temp*temp;
  temp = work1d.KKT[546]-work1d.L[32]*work1d.d[273]*1;
  residual += temp*temp;
  temp = work1d.KKT[548]-work1d.L[33]*work1d.d[274]*1;
  residual += temp*temp;
  temp = work1d.KKT[550]-work1d.L[34]*work1d.d[275]*1;
  residual += temp*temp;
  temp = work1d.KKT[552]-work1d.L[35]*work1d.d[276]*1;
  residual += temp*temp;
  temp = work1d.KKT[554]-work1d.L[36]*work1d.d[277]*1;
  residual += temp*temp;
  temp = work1d.KKT[556]-work1d.L[37]*work1d.d[278]*1;
  residual += temp*temp;
  temp = work1d.KKT[558]-work1d.L[38]*work1d.d[279]*1;
  residual += temp*temp;
  temp = work1d.KKT[560]-work1d.L[39]*work1d.d[280]*1;
  residual += temp*temp;
  temp = work1d.KKT[562]-work1d.L[40]*work1d.d[281]*1;
  residual += temp*temp;
  temp = work1d.KKT[564]-work1d.L[41]*work1d.d[282]*1;
  residual += temp*temp;
  temp = work1d.KKT[566]-work1d.L[42]*work1d.d[283]*1;
  residual += temp*temp;
  temp = work1d.KKT[568]-work1d.L[43]*work1d.d[284]*1;
  residual += temp*temp;
  temp = work1d.KKT[570]-work1d.L[44]*work1d.d[285]*1;
  residual += temp*temp;
  temp = work1d.KKT[572]-work1d.L[45]*work1d.d[286]*1;
  residual += temp*temp;
  temp = work1d.KKT[574]-work1d.L[46]*work1d.d[287]*1;
  residual += temp*temp;
  temp = work1d.KKT[576]-work1d.L[47]*work1d.d[288]*1;
  residual += temp*temp;
  temp = work1d.KKT[578]-work1d.L[48]*work1d.d[289]*1;
  residual += temp*temp;
  temp = work1d.KKT[580]-work1d.L[49]*work1d.d[290]*1;
  residual += temp*temp;
  temp = work1d.KKT[582]-work1d.L[50]*work1d.d[291]*1;
  residual += temp*temp;
  temp = work1d.KKT[584]-work1d.L[51]*work1d.d[292]*1;
  residual += temp*temp;
  temp = work1d.KKT[586]-work1d.L[52]*work1d.d[293]*1;
  residual += temp*temp;
  temp = work1d.KKT[588]-work1d.L[53]*work1d.d[294]*1;
  residual += temp*temp;
  temp = work1d.KKT[590]-work1d.L[54]*work1d.d[295]*1;
  residual += temp*temp;
  temp = work1d.KKT[592]-work1d.L[55]*work1d.d[296]*1;
  residual += temp*temp;
  temp = work1d.KKT[594]-work1d.L[56]*work1d.d[297]*1;
  residual += temp*temp;
  temp = work1d.KKT[596]-work1d.L[57]*work1d.d[298]*1;
  residual += temp*temp;
  temp = work1d.KKT[598]-work1d.L[58]*work1d.d[299]*1;
  residual += temp*temp;
  temp = work1d.KKT[600]-work1d.L[59]*work1d.d[300]*1;
  residual += temp*temp;
  temp = work1d.KKT[602]-work1d.L[60]*work1d.d[301]*1;
  residual += temp*temp;
  temp = work1d.KKT[604]-work1d.L[61]*work1d.d[302]*1;
  residual += temp*temp;
  temp = work1d.KKT[606]-work1d.L[62]*work1d.d[303]*1;
  residual += temp*temp;
  temp = work1d.KKT[608]-work1d.L[63]*work1d.d[304]*1;
  residual += temp*temp;
  temp = work1d.KKT[610]-work1d.L[64]*work1d.d[305]*1;
  residual += temp*temp;
  temp = work1d.KKT[612]-work1d.L[65]*work1d.d[306]*1;
  residual += temp*temp;
  temp = work1d.KKT[614]-work1d.L[66]*work1d.d[307]*1;
  residual += temp*temp;
  temp = work1d.KKT[616]-work1d.L[67]*work1d.d[308]*1;
  residual += temp*temp;
  temp = work1d.KKT[618]-work1d.L[68]*work1d.d[309]*1;
  residual += temp*temp;
  temp = work1d.KKT[620]-work1d.L[69]*work1d.d[310]*1;
  residual += temp*temp;
  temp = work1d.KKT[622]-work1d.L[70]*work1d.d[311]*1;
  residual += temp*temp;
  temp = work1d.KKT[624]-work1d.L[71]*work1d.d[312]*1;
  residual += temp*temp;
  temp = work1d.KKT[626]-work1d.L[72]*work1d.d[313]*1;
  residual += temp*temp;
  temp = work1d.KKT[628]-work1d.L[73]*work1d.d[314]*1;
  residual += temp*temp;
  temp = work1d.KKT[630]-work1d.L[74]*work1d.d[315]*1;
  residual += temp*temp;
  temp = work1d.KKT[632]-work1d.L[75]*work1d.d[316]*1;
  residual += temp*temp;
  temp = work1d.KKT[634]-work1d.L[76]*work1d.d[317]*1;
  residual += temp*temp;
  temp = work1d.KKT[636]-work1d.L[77]*work1d.d[318]*1;
  residual += temp*temp;
  temp = work1d.KKT[638]-work1d.L[78]*work1d.d[319]*1;
  residual += temp*temp;
  temp = work1d.KKT[640]-work1d.L[79]*work1d.d[320]*1;
  residual += temp*temp;
  temp = work1d.KKT[887]-work1d.L[82]*work1d.d[1]*work1d.L[82]-1*work1d.d[446]*1;
  residual += temp*temp;
  temp = work1d.KKT[891]-work1d.L[84]*work1d.d[2]*work1d.L[84]-1*work1d.d[448]*1-work1d.L[85]*work1d.d[447]*work1d.L[85];
  residual += temp*temp;
  temp = work1d.KKT[893]-work1d.L[86]*work1d.d[3]*work1d.L[86]-1*work1d.d[449]*1-work1d.L[87]*work1d.d[447]*work1d.L[87]-work1d.L[88]*work1d.d[448]*work1d.L[88];
  residual += temp*temp;
  temp = work1d.KKT[895]-work1d.L[89]*work1d.d[4]*work1d.L[89]-1*work1d.d[450]*1;
  residual += temp*temp;
  temp = work1d.KKT[899]-work1d.L[91]*work1d.d[5]*work1d.L[91]-1*work1d.d[452]*1-work1d.L[92]*work1d.d[451]*work1d.L[92];
  residual += temp*temp;
  temp = work1d.KKT[901]-work1d.L[93]*work1d.d[6]*work1d.L[93]-1*work1d.d[453]*1-work1d.L[94]*work1d.d[451]*work1d.L[94]-work1d.L[95]*work1d.d[452]*work1d.L[95];
  residual += temp*temp;
  temp = work1d.KKT[903]-work1d.L[96]*work1d.d[7]*work1d.L[96]-1*work1d.d[454]*1;
  residual += temp*temp;
  temp = work1d.KKT[907]-work1d.L[98]*work1d.d[8]*work1d.L[98]-1*work1d.d[456]*1-work1d.L[99]*work1d.d[455]*work1d.L[99];
  residual += temp*temp;
  temp = work1d.KKT[909]-work1d.L[100]*work1d.d[9]*work1d.L[100]-1*work1d.d[457]*1-work1d.L[101]*work1d.d[455]*work1d.L[101]-work1d.L[102]*work1d.d[456]*work1d.L[102];
  residual += temp*temp;
  temp = work1d.KKT[911]-work1d.L[103]*work1d.d[10]*work1d.L[103]-1*work1d.d[458]*1;
  residual += temp*temp;
  temp = work1d.KKT[915]-work1d.L[105]*work1d.d[11]*work1d.L[105]-1*work1d.d[460]*1-work1d.L[106]*work1d.d[459]*work1d.L[106];
  residual += temp*temp;
  temp = work1d.KKT[917]-work1d.L[107]*work1d.d[12]*work1d.L[107]-1*work1d.d[461]*1-work1d.L[108]*work1d.d[459]*work1d.L[108]-work1d.L[109]*work1d.d[460]*work1d.L[109];
  residual += temp*temp;
  temp = work1d.KKT[919]-work1d.L[110]*work1d.d[13]*work1d.L[110]-1*work1d.d[462]*1;
  residual += temp*temp;
  temp = work1d.KKT[923]-work1d.L[112]*work1d.d[14]*work1d.L[112]-1*work1d.d[464]*1-work1d.L[113]*work1d.d[463]*work1d.L[113];
  residual += temp*temp;
  temp = work1d.KKT[925]-work1d.L[114]*work1d.d[15]*work1d.L[114]-1*work1d.d[465]*1-work1d.L[115]*work1d.d[463]*work1d.L[115]-work1d.L[116]*work1d.d[464]*work1d.L[116];
  residual += temp*temp;
  temp = work1d.KKT[927]-work1d.L[117]*work1d.d[16]*work1d.L[117]-1*work1d.d[466]*1;
  residual += temp*temp;
  temp = work1d.KKT[931]-work1d.L[119]*work1d.d[17]*work1d.L[119]-1*work1d.d[468]*1-work1d.L[120]*work1d.d[467]*work1d.L[120];
  residual += temp*temp;
  temp = work1d.KKT[933]-work1d.L[121]*work1d.d[18]*work1d.L[121]-1*work1d.d[469]*1-work1d.L[122]*work1d.d[467]*work1d.L[122]-work1d.L[123]*work1d.d[468]*work1d.L[123];
  residual += temp*temp;
  temp = work1d.KKT[935]-work1d.L[124]*work1d.d[19]*work1d.L[124]-1*work1d.d[470]*1;
  residual += temp*temp;
  temp = work1d.KKT[939]-work1d.L[126]*work1d.d[20]*work1d.L[126]-1*work1d.d[472]*1-work1d.L[127]*work1d.d[471]*work1d.L[127];
  residual += temp*temp;
  temp = work1d.KKT[941]-work1d.L[128]*work1d.d[21]*work1d.L[128]-1*work1d.d[473]*1-work1d.L[129]*work1d.d[471]*work1d.L[129]-work1d.L[130]*work1d.d[472]*work1d.L[130];
  residual += temp*temp;
  temp = work1d.KKT[943]-work1d.L[131]*work1d.d[22]*work1d.L[131]-1*work1d.d[474]*1;
  residual += temp*temp;
  temp = work1d.KKT[947]-work1d.L[133]*work1d.d[23]*work1d.L[133]-1*work1d.d[476]*1-work1d.L[134]*work1d.d[475]*work1d.L[134];
  residual += temp*temp;
  temp = work1d.KKT[949]-work1d.L[135]*work1d.d[24]*work1d.L[135]-1*work1d.d[477]*1-work1d.L[136]*work1d.d[475]*work1d.L[136]-work1d.L[137]*work1d.d[476]*work1d.L[137];
  residual += temp*temp;
  temp = work1d.KKT[951]-work1d.L[138]*work1d.d[25]*work1d.L[138]-1*work1d.d[478]*1;
  residual += temp*temp;
  temp = work1d.KKT[955]-work1d.L[140]*work1d.d[26]*work1d.L[140]-1*work1d.d[480]*1-work1d.L[141]*work1d.d[479]*work1d.L[141];
  residual += temp*temp;
  temp = work1d.KKT[957]-work1d.L[142]*work1d.d[27]*work1d.L[142]-1*work1d.d[481]*1-work1d.L[143]*work1d.d[479]*work1d.L[143]-work1d.L[144]*work1d.d[480]*work1d.L[144];
  residual += temp*temp;
  temp = work1d.KKT[959]-work1d.L[145]*work1d.d[28]*work1d.L[145]-1*work1d.d[482]*1;
  residual += temp*temp;
  temp = work1d.KKT[963]-work1d.L[147]*work1d.d[29]*work1d.L[147]-1*work1d.d[484]*1-work1d.L[148]*work1d.d[483]*work1d.L[148];
  residual += temp*temp;
  temp = work1d.KKT[965]-work1d.L[149]*work1d.d[30]*work1d.L[149]-1*work1d.d[485]*1-work1d.L[150]*work1d.d[483]*work1d.L[150]-work1d.L[151]*work1d.d[484]*work1d.L[151];
  residual += temp*temp;
  temp = work1d.KKT[967]-work1d.L[152]*work1d.d[31]*work1d.L[152]-1*work1d.d[486]*1;
  residual += temp*temp;
  temp = work1d.KKT[971]-work1d.L[154]*work1d.d[32]*work1d.L[154]-1*work1d.d[488]*1-work1d.L[155]*work1d.d[487]*work1d.L[155];
  residual += temp*temp;
  temp = work1d.KKT[973]-work1d.L[156]*work1d.d[33]*work1d.L[156]-1*work1d.d[489]*1-work1d.L[157]*work1d.d[487]*work1d.L[157]-work1d.L[158]*work1d.d[488]*work1d.L[158];
  residual += temp*temp;
  temp = work1d.KKT[975]-work1d.L[159]*work1d.d[34]*work1d.L[159]-1*work1d.d[490]*1;
  residual += temp*temp;
  temp = work1d.KKT[979]-work1d.L[161]*work1d.d[35]*work1d.L[161]-1*work1d.d[492]*1-work1d.L[162]*work1d.d[491]*work1d.L[162];
  residual += temp*temp;
  temp = work1d.KKT[981]-work1d.L[163]*work1d.d[36]*work1d.L[163]-1*work1d.d[493]*1-work1d.L[164]*work1d.d[491]*work1d.L[164]-work1d.L[165]*work1d.d[492]*work1d.L[165];
  residual += temp*temp;
  temp = work1d.KKT[983]-work1d.L[166]*work1d.d[37]*work1d.L[166]-1*work1d.d[494]*1;
  residual += temp*temp;
  temp = work1d.KKT[987]-work1d.L[168]*work1d.d[38]*work1d.L[168]-1*work1d.d[496]*1-work1d.L[169]*work1d.d[495]*work1d.L[169];
  residual += temp*temp;
  temp = work1d.KKT[989]-work1d.L[170]*work1d.d[39]*work1d.L[170]-1*work1d.d[497]*1-work1d.L[171]*work1d.d[495]*work1d.L[171]-work1d.L[172]*work1d.d[496]*work1d.L[172];
  residual += temp*temp;
  temp = work1d.KKT[991]-work1d.L[173]*work1d.d[40]*work1d.L[173]-1*work1d.d[498]*1;
  residual += temp*temp;
  temp = work1d.KKT[995]-work1d.L[175]*work1d.d[41]*work1d.L[175]-1*work1d.d[500]*1-work1d.L[176]*work1d.d[499]*work1d.L[176];
  residual += temp*temp;
  temp = work1d.KKT[997]-work1d.L[177]*work1d.d[42]*work1d.L[177]-1*work1d.d[501]*1-work1d.L[178]*work1d.d[499]*work1d.L[178]-work1d.L[179]*work1d.d[500]*work1d.L[179];
  residual += temp*temp;
  temp = work1d.KKT[999]-work1d.L[180]*work1d.d[43]*work1d.L[180]-1*work1d.d[502]*1;
  residual += temp*temp;
  temp = work1d.KKT[1003]-work1d.L[182]*work1d.d[44]*work1d.L[182]-1*work1d.d[504]*1-work1d.L[183]*work1d.d[503]*work1d.L[183];
  residual += temp*temp;
  temp = work1d.KKT[1005]-work1d.L[184]*work1d.d[45]*work1d.L[184]-1*work1d.d[505]*1-work1d.L[185]*work1d.d[503]*work1d.L[185]-work1d.L[186]*work1d.d[504]*work1d.L[186];
  residual += temp*temp;
  temp = work1d.KKT[1007]-work1d.L[187]*work1d.d[46]*work1d.L[187]-1*work1d.d[506]*1;
  residual += temp*temp;
  temp = work1d.KKT[1011]-work1d.L[189]*work1d.d[47]*work1d.L[189]-1*work1d.d[508]*1-work1d.L[190]*work1d.d[507]*work1d.L[190];
  residual += temp*temp;
  temp = work1d.KKT[1013]-work1d.L[191]*work1d.d[48]*work1d.L[191]-1*work1d.d[509]*1-work1d.L[192]*work1d.d[507]*work1d.L[192]-work1d.L[193]*work1d.d[508]*work1d.L[193];
  residual += temp*temp;
  temp = work1d.KKT[1015]-work1d.L[194]*work1d.d[49]*work1d.L[194]-1*work1d.d[510]*1;
  residual += temp*temp;
  temp = work1d.KKT[1019]-work1d.L[196]*work1d.d[50]*work1d.L[196]-1*work1d.d[512]*1-work1d.L[197]*work1d.d[511]*work1d.L[197];
  residual += temp*temp;
  temp = work1d.KKT[1021]-work1d.L[198]*work1d.d[51]*work1d.L[198]-1*work1d.d[513]*1-work1d.L[199]*work1d.d[511]*work1d.L[199]-work1d.L[200]*work1d.d[512]*work1d.L[200];
  residual += temp*temp;
  temp = work1d.KKT[1023]-work1d.L[201]*work1d.d[52]*work1d.L[201]-1*work1d.d[514]*1;
  residual += temp*temp;
  temp = work1d.KKT[1027]-work1d.L[203]*work1d.d[53]*work1d.L[203]-1*work1d.d[516]*1-work1d.L[204]*work1d.d[515]*work1d.L[204];
  residual += temp*temp;
  temp = work1d.KKT[1029]-work1d.L[205]*work1d.d[54]*work1d.L[205]-1*work1d.d[517]*1-work1d.L[206]*work1d.d[515]*work1d.L[206]-work1d.L[207]*work1d.d[516]*work1d.L[207];
  residual += temp*temp;
  temp = work1d.KKT[1031]-work1d.L[208]*work1d.d[55]*work1d.L[208]-1*work1d.d[518]*1;
  residual += temp*temp;
  temp = work1d.KKT[1035]-work1d.L[210]*work1d.d[56]*work1d.L[210]-1*work1d.d[520]*1-work1d.L[211]*work1d.d[519]*work1d.L[211];
  residual += temp*temp;
  temp = work1d.KKT[1037]-work1d.L[212]*work1d.d[57]*work1d.L[212]-1*work1d.d[521]*1-work1d.L[213]*work1d.d[519]*work1d.L[213]-work1d.L[214]*work1d.d[520]*work1d.L[214];
  residual += temp*temp;
  temp = work1d.KKT[1039]-work1d.L[215]*work1d.d[58]*work1d.L[215]-1*work1d.d[522]*1;
  residual += temp*temp;
  temp = work1d.KKT[1043]-work1d.L[217]*work1d.d[59]*work1d.L[217]-1*work1d.d[524]*1-work1d.L[218]*work1d.d[523]*work1d.L[218];
  residual += temp*temp;
  temp = work1d.KKT[1045]-work1d.L[219]*work1d.d[60]*work1d.L[219]-1*work1d.d[525]*1-work1d.L[220]*work1d.d[523]*work1d.L[220]-work1d.L[221]*work1d.d[524]*work1d.L[221];
  residual += temp*temp;
  temp = work1d.KKT[1047]-work1d.L[222]*work1d.d[61]*work1d.L[222]-1*work1d.d[526]*1;
  residual += temp*temp;
  temp = work1d.KKT[1051]-work1d.L[224]*work1d.d[62]*work1d.L[224]-1*work1d.d[528]*1-work1d.L[225]*work1d.d[527]*work1d.L[225];
  residual += temp*temp;
  temp = work1d.KKT[1053]-work1d.L[226]*work1d.d[63]*work1d.L[226]-1*work1d.d[529]*1-work1d.L[227]*work1d.d[527]*work1d.L[227]-work1d.L[228]*work1d.d[528]*work1d.L[228];
  residual += temp*temp;
  temp = work1d.KKT[1055]-work1d.L[229]*work1d.d[64]*work1d.L[229]-1*work1d.d[530]*1;
  residual += temp*temp;
  temp = work1d.KKT[1059]-work1d.L[231]*work1d.d[65]*work1d.L[231]-1*work1d.d[532]*1-work1d.L[232]*work1d.d[531]*work1d.L[232];
  residual += temp*temp;
  temp = work1d.KKT[1061]-work1d.L[233]*work1d.d[66]*work1d.L[233]-1*work1d.d[533]*1-work1d.L[234]*work1d.d[531]*work1d.L[234]-work1d.L[235]*work1d.d[532]*work1d.L[235];
  residual += temp*temp;
  temp = work1d.KKT[1063]-work1d.L[236]*work1d.d[67]*work1d.L[236]-1*work1d.d[534]*1;
  residual += temp*temp;
  temp = work1d.KKT[1067]-work1d.L[238]*work1d.d[68]*work1d.L[238]-1*work1d.d[536]*1-work1d.L[239]*work1d.d[535]*work1d.L[239];
  residual += temp*temp;
  temp = work1d.KKT[1069]-work1d.L[240]*work1d.d[69]*work1d.L[240]-1*work1d.d[537]*1-work1d.L[241]*work1d.d[535]*work1d.L[241]-work1d.L[242]*work1d.d[536]*work1d.L[242];
  residual += temp*temp;
  temp = work1d.KKT[1071]-work1d.L[243]*work1d.d[70]*work1d.L[243]-1*work1d.d[538]*1;
  residual += temp*temp;
  temp = work1d.KKT[1075]-work1d.L[245]*work1d.d[71]*work1d.L[245]-1*work1d.d[540]*1-work1d.L[246]*work1d.d[539]*work1d.L[246];
  residual += temp*temp;
  temp = work1d.KKT[1077]-work1d.L[247]*work1d.d[72]*work1d.L[247]-1*work1d.d[541]*1-work1d.L[248]*work1d.d[539]*work1d.L[248]-work1d.L[249]*work1d.d[540]*work1d.L[249];
  residual += temp*temp;
  temp = work1d.KKT[1079]-work1d.L[250]*work1d.d[73]*work1d.L[250]-1*work1d.d[542]*1;
  residual += temp*temp;
  temp = work1d.KKT[1083]-work1d.L[252]*work1d.d[74]*work1d.L[252]-1*work1d.d[544]*1-work1d.L[253]*work1d.d[543]*work1d.L[253];
  residual += temp*temp;
  temp = work1d.KKT[1085]-work1d.L[254]*work1d.d[75]*work1d.L[254]-1*work1d.d[545]*1-work1d.L[255]*work1d.d[543]*work1d.L[255]-work1d.L[256]*work1d.d[544]*work1d.L[256];
  residual += temp*temp;
  temp = work1d.KKT[1087]-work1d.L[257]*work1d.d[76]*work1d.L[257]-1*work1d.d[546]*1;
  residual += temp*temp;
  temp = work1d.KKT[1091]-work1d.L[259]*work1d.d[77]*work1d.L[259]-1*work1d.d[548]*1-work1d.L[260]*work1d.d[547]*work1d.L[260];
  residual += temp*temp;
  temp = work1d.KKT[1093]-work1d.L[261]*work1d.d[78]*work1d.L[261]-1*work1d.d[549]*1-work1d.L[262]*work1d.d[547]*work1d.L[262]-work1d.L[263]*work1d.d[548]*work1d.L[263];
  residual += temp*temp;
  temp = work1d.KKT[1095]-work1d.L[264]*work1d.d[79]*work1d.L[264]-1*work1d.d[550]*1;
  residual += temp*temp;
  temp = work1d.KKT[1099]-work1d.L[266]*work1d.d[80]*work1d.L[266]-1*work1d.d[552]*1-work1d.L[267]*work1d.d[551]*work1d.L[267];
  residual += temp*temp;
  temp = work1d.KKT[1101]-work1d.L[268]*work1d.d[81]*work1d.L[268]-1*work1d.d[553]*1-work1d.L[269]*work1d.d[551]*work1d.L[269]-work1d.L[270]*work1d.d[552]*work1d.L[270];
  residual += temp*temp;
  temp = work1d.KKT[1103]-work1d.L[271]*work1d.d[82]*work1d.L[271]-1*work1d.d[554]*1;
  residual += temp*temp;
  temp = work1d.KKT[1107]-work1d.L[273]*work1d.d[83]*work1d.L[273]-1*work1d.d[556]*1-work1d.L[274]*work1d.d[555]*work1d.L[274];
  residual += temp*temp;
  temp = work1d.KKT[1109]-work1d.L[275]*work1d.d[84]*work1d.L[275]-1*work1d.d[557]*1-work1d.L[276]*work1d.d[555]*work1d.L[276]-work1d.L[277]*work1d.d[556]*work1d.L[277];
  residual += temp*temp;
  temp = work1d.KKT[1111]-work1d.L[278]*work1d.d[85]*work1d.L[278]-1*work1d.d[558]*1;
  residual += temp*temp;
  temp = work1d.KKT[1115]-work1d.L[280]*work1d.d[86]*work1d.L[280]-1*work1d.d[560]*1-work1d.L[281]*work1d.d[559]*work1d.L[281];
  residual += temp*temp;
  temp = work1d.KKT[1117]-work1d.L[282]*work1d.d[87]*work1d.L[282]-1*work1d.d[561]*1-work1d.L[283]*work1d.d[559]*work1d.L[283]-work1d.L[284]*work1d.d[560]*work1d.L[284];
  residual += temp*temp;
  temp = work1d.KKT[1119]-work1d.L[285]*work1d.d[88]*work1d.L[285]-1*work1d.d[562]*1;
  residual += temp*temp;
  temp = work1d.KKT[1123]-work1d.L[287]*work1d.d[89]*work1d.L[287]-1*work1d.d[564]*1-work1d.L[288]*work1d.d[563]*work1d.L[288];
  residual += temp*temp;
  temp = work1d.KKT[1125]-work1d.L[289]*work1d.d[90]*work1d.L[289]-1*work1d.d[565]*1-work1d.L[290]*work1d.d[563]*work1d.L[290]-work1d.L[291]*work1d.d[564]*work1d.L[291];
  residual += temp*temp;
  temp = work1d.KKT[1127]-work1d.L[292]*work1d.d[91]*work1d.L[292]-1*work1d.d[566]*1;
  residual += temp*temp;
  temp = work1d.KKT[1131]-work1d.L[294]*work1d.d[92]*work1d.L[294]-1*work1d.d[568]*1-work1d.L[295]*work1d.d[567]*work1d.L[295];
  residual += temp*temp;
  temp = work1d.KKT[1133]-work1d.L[296]*work1d.d[93]*work1d.L[296]-1*work1d.d[569]*1-work1d.L[297]*work1d.d[567]*work1d.L[297]-work1d.L[298]*work1d.d[568]*work1d.L[298];
  residual += temp*temp;
  temp = work1d.KKT[1135]-work1d.L[299]*work1d.d[94]*work1d.L[299]-1*work1d.d[570]*1;
  residual += temp*temp;
  temp = work1d.KKT[1139]-work1d.L[301]*work1d.d[95]*work1d.L[301]-1*work1d.d[572]*1-work1d.L[302]*work1d.d[571]*work1d.L[302];
  residual += temp*temp;
  temp = work1d.KKT[1141]-work1d.L[303]*work1d.d[96]*work1d.L[303]-1*work1d.d[573]*1-work1d.L[304]*work1d.d[571]*work1d.L[304]-work1d.L[305]*work1d.d[572]*work1d.L[305];
  residual += temp*temp;
  temp = work1d.KKT[1143]-work1d.L[306]*work1d.d[97]*work1d.L[306]-1*work1d.d[574]*1;
  residual += temp*temp;
  temp = work1d.KKT[1147]-work1d.L[308]*work1d.d[98]*work1d.L[308]-1*work1d.d[576]*1-work1d.L[309]*work1d.d[575]*work1d.L[309];
  residual += temp*temp;
  temp = work1d.KKT[1149]-work1d.L[310]*work1d.d[99]*work1d.L[310]-1*work1d.d[577]*1-work1d.L[311]*work1d.d[575]*work1d.L[311]-work1d.L[312]*work1d.d[576]*work1d.L[312];
  residual += temp*temp;
  temp = work1d.KKT[1151]-work1d.L[313]*work1d.d[100]*work1d.L[313]-1*work1d.d[578]*1;
  residual += temp*temp;
  temp = work1d.KKT[1155]-work1d.L[315]*work1d.d[101]*work1d.L[315]-1*work1d.d[580]*1-work1d.L[316]*work1d.d[579]*work1d.L[316];
  residual += temp*temp;
  temp = work1d.KKT[1157]-work1d.L[317]*work1d.d[102]*work1d.L[317]-1*work1d.d[581]*1-work1d.L[318]*work1d.d[579]*work1d.L[318]-work1d.L[319]*work1d.d[580]*work1d.L[319];
  residual += temp*temp;
  temp = work1d.KKT[1159]-work1d.L[320]*work1d.d[103]*work1d.L[320]-1*work1d.d[582]*1;
  residual += temp*temp;
  temp = work1d.KKT[1163]-work1d.L[322]*work1d.d[104]*work1d.L[322]-1*work1d.d[584]*1-work1d.L[323]*work1d.d[583]*work1d.L[323];
  residual += temp*temp;
  temp = work1d.KKT[1165]-work1d.L[324]*work1d.d[105]*work1d.L[324]-1*work1d.d[585]*1-work1d.L[325]*work1d.d[583]*work1d.L[325]-work1d.L[326]*work1d.d[584]*work1d.L[326];
  residual += temp*temp;
  temp = work1d.KKT[1167]-work1d.L[327]*work1d.d[106]*work1d.L[327]-1*work1d.d[586]*1;
  residual += temp*temp;
  temp = work1d.KKT[1171]-work1d.L[329]*work1d.d[107]*work1d.L[329]-1*work1d.d[588]*1-work1d.L[330]*work1d.d[587]*work1d.L[330];
  residual += temp*temp;
  temp = work1d.KKT[1173]-work1d.L[331]*work1d.d[108]*work1d.L[331]-1*work1d.d[589]*1-work1d.L[332]*work1d.d[587]*work1d.L[332]-work1d.L[333]*work1d.d[588]*work1d.L[333];
  residual += temp*temp;
  temp = work1d.KKT[1175]-work1d.L[334]*work1d.d[109]*work1d.L[334]-1*work1d.d[590]*1;
  residual += temp*temp;
  temp = work1d.KKT[1179]-work1d.L[336]*work1d.d[110]*work1d.L[336]-1*work1d.d[592]*1-work1d.L[337]*work1d.d[591]*work1d.L[337];
  residual += temp*temp;
  temp = work1d.KKT[1181]-work1d.L[338]*work1d.d[111]*work1d.L[338]-1*work1d.d[593]*1-work1d.L[339]*work1d.d[591]*work1d.L[339]-work1d.L[340]*work1d.d[592]*work1d.L[340];
  residual += temp*temp;
  temp = work1d.KKT[1183]-work1d.L[341]*work1d.d[112]*work1d.L[341]-1*work1d.d[594]*1;
  residual += temp*temp;
  temp = work1d.KKT[1187]-work1d.L[343]*work1d.d[113]*work1d.L[343]-1*work1d.d[596]*1-work1d.L[344]*work1d.d[595]*work1d.L[344];
  residual += temp*temp;
  temp = work1d.KKT[1189]-work1d.L[345]*work1d.d[114]*work1d.L[345]-1*work1d.d[597]*1-work1d.L[346]*work1d.d[595]*work1d.L[346]-work1d.L[347]*work1d.d[596]*work1d.L[347];
  residual += temp*temp;
  temp = work1d.KKT[1191]-work1d.L[348]*work1d.d[115]*work1d.L[348]-1*work1d.d[598]*1;
  residual += temp*temp;
  temp = work1d.KKT[1195]-work1d.L[350]*work1d.d[116]*work1d.L[350]-1*work1d.d[600]*1-work1d.L[351]*work1d.d[599]*work1d.L[351];
  residual += temp*temp;
  temp = work1d.KKT[1197]-work1d.L[352]*work1d.d[117]*work1d.L[352]-1*work1d.d[601]*1-work1d.L[353]*work1d.d[599]*work1d.L[353]-work1d.L[354]*work1d.d[600]*work1d.L[354];
  residual += temp*temp;
  temp = work1d.KKT[1199]-work1d.L[355]*work1d.d[118]*work1d.L[355]-1*work1d.d[602]*1;
  residual += temp*temp;
  temp = work1d.KKT[1203]-work1d.L[357]*work1d.d[119]*work1d.L[357]-1*work1d.d[604]*1-work1d.L[358]*work1d.d[603]*work1d.L[358];
  residual += temp*temp;
  temp = work1d.KKT[1205]-work1d.L[359]*work1d.d[120]*work1d.L[359]-1*work1d.d[605]*1-work1d.L[360]*work1d.d[603]*work1d.L[360]-work1d.L[361]*work1d.d[604]*work1d.L[361];
  residual += temp*temp;
  temp = work1d.KKT[1209]-work1d.L[365]*work1d.d[121]*work1d.L[365]-1*work1d.d[607]*1;
  residual += temp*temp;
  temp = work1d.KKT[1213]-work1d.L[367]*work1d.d[122]*work1d.L[367]-1*work1d.d[609]*1-work1d.L[368]*work1d.d[608]*work1d.L[368];
  residual += temp*temp;
  temp = work1d.KKT[1215]-work1d.L[369]*work1d.d[123]*work1d.L[369]-1*work1d.d[610]*1-work1d.L[370]*work1d.d[608]*work1d.L[370]-work1d.L[371]*work1d.d[609]*work1d.L[371];
  residual += temp*temp;
  temp = work1d.KKT[1217]-work1d.L[372]*work1d.d[124]*work1d.L[372]-1*work1d.d[611]*1;
  residual += temp*temp;
  temp = work1d.KKT[1221]-work1d.L[374]*work1d.d[125]*work1d.L[374]-1*work1d.d[613]*1-work1d.L[375]*work1d.d[612]*work1d.L[375];
  residual += temp*temp;
  temp = work1d.KKT[1223]-work1d.L[376]*work1d.d[126]*work1d.L[376]-1*work1d.d[614]*1-work1d.L[377]*work1d.d[612]*work1d.L[377]-work1d.L[378]*work1d.d[613]*work1d.L[378];
  residual += temp*temp;
  temp = work1d.KKT[1225]-work1d.L[379]*work1d.d[127]*work1d.L[379]-1*work1d.d[615]*1;
  residual += temp*temp;
  temp = work1d.KKT[1229]-work1d.L[381]*work1d.d[128]*work1d.L[381]-1*work1d.d[617]*1-work1d.L[382]*work1d.d[616]*work1d.L[382];
  residual += temp*temp;
  temp = work1d.KKT[1231]-work1d.L[383]*work1d.d[129]*work1d.L[383]-1*work1d.d[618]*1-work1d.L[384]*work1d.d[616]*work1d.L[384]-work1d.L[385]*work1d.d[617]*work1d.L[385];
  residual += temp*temp;
  temp = work1d.KKT[1233]-work1d.L[386]*work1d.d[130]*work1d.L[386]-1*work1d.d[619]*1;
  residual += temp*temp;
  temp = work1d.KKT[1237]-work1d.L[388]*work1d.d[131]*work1d.L[388]-1*work1d.d[621]*1-work1d.L[389]*work1d.d[620]*work1d.L[389];
  residual += temp*temp;
  temp = work1d.KKT[1239]-work1d.L[390]*work1d.d[132]*work1d.L[390]-1*work1d.d[622]*1-work1d.L[391]*work1d.d[620]*work1d.L[391]-work1d.L[392]*work1d.d[621]*work1d.L[392];
  residual += temp*temp;
  temp = work1d.KKT[1241]-work1d.L[393]*work1d.d[133]*work1d.L[393]-1*work1d.d[623]*1;
  residual += temp*temp;
  temp = work1d.KKT[1245]-work1d.L[395]*work1d.d[134]*work1d.L[395]-1*work1d.d[625]*1-work1d.L[396]*work1d.d[624]*work1d.L[396];
  residual += temp*temp;
  temp = work1d.KKT[1247]-work1d.L[397]*work1d.d[135]*work1d.L[397]-1*work1d.d[626]*1-work1d.L[398]*work1d.d[624]*work1d.L[398]-work1d.L[399]*work1d.d[625]*work1d.L[399];
  residual += temp*temp;
  temp = work1d.KKT[1249]-work1d.L[400]*work1d.d[136]*work1d.L[400]-1*work1d.d[627]*1;
  residual += temp*temp;
  temp = work1d.KKT[1253]-work1d.L[402]*work1d.d[137]*work1d.L[402]-1*work1d.d[629]*1-work1d.L[403]*work1d.d[628]*work1d.L[403];
  residual += temp*temp;
  temp = work1d.KKT[1255]-work1d.L[404]*work1d.d[138]*work1d.L[404]-1*work1d.d[630]*1-work1d.L[405]*work1d.d[628]*work1d.L[405]-work1d.L[406]*work1d.d[629]*work1d.L[406];
  residual += temp*temp;
  temp = work1d.KKT[1257]-work1d.L[407]*work1d.d[139]*work1d.L[407]-1*work1d.d[631]*1;
  residual += temp*temp;
  temp = work1d.KKT[1261]-work1d.L[409]*work1d.d[140]*work1d.L[409]-1*work1d.d[633]*1-work1d.L[410]*work1d.d[632]*work1d.L[410];
  residual += temp*temp;
  temp = work1d.KKT[1263]-work1d.L[411]*work1d.d[141]*work1d.L[411]-1*work1d.d[634]*1-work1d.L[412]*work1d.d[632]*work1d.L[412]-work1d.L[413]*work1d.d[633]*work1d.L[413];
  residual += temp*temp;
  temp = work1d.KKT[1265]-work1d.L[414]*work1d.d[142]*work1d.L[414]-1*work1d.d[635]*1;
  residual += temp*temp;
  temp = work1d.KKT[1269]-work1d.L[416]*work1d.d[143]*work1d.L[416]-1*work1d.d[637]*1-work1d.L[417]*work1d.d[636]*work1d.L[417];
  residual += temp*temp;
  temp = work1d.KKT[1271]-work1d.L[418]*work1d.d[144]*work1d.L[418]-1*work1d.d[638]*1-work1d.L[419]*work1d.d[636]*work1d.L[419]-work1d.L[420]*work1d.d[637]*work1d.L[420];
  residual += temp*temp;
  temp = work1d.KKT[1273]-work1d.L[421]*work1d.d[145]*work1d.L[421]-1*work1d.d[639]*1;
  residual += temp*temp;
  temp = work1d.KKT[1277]-work1d.L[423]*work1d.d[146]*work1d.L[423]-1*work1d.d[641]*1-work1d.L[424]*work1d.d[640]*work1d.L[424];
  residual += temp*temp;
  temp = work1d.KKT[1279]-work1d.L[425]*work1d.d[147]*work1d.L[425]-1*work1d.d[642]*1-work1d.L[426]*work1d.d[640]*work1d.L[426]-work1d.L[427]*work1d.d[641]*work1d.L[427];
  residual += temp*temp;
  temp = work1d.KKT[1281]-work1d.L[428]*work1d.d[148]*work1d.L[428]-1*work1d.d[643]*1;
  residual += temp*temp;
  temp = work1d.KKT[1285]-work1d.L[430]*work1d.d[149]*work1d.L[430]-1*work1d.d[645]*1-work1d.L[431]*work1d.d[644]*work1d.L[431];
  residual += temp*temp;
  temp = work1d.KKT[1287]-work1d.L[432]*work1d.d[150]*work1d.L[432]-1*work1d.d[646]*1-work1d.L[433]*work1d.d[644]*work1d.L[433]-work1d.L[434]*work1d.d[645]*work1d.L[434];
  residual += temp*temp;
  temp = work1d.KKT[1289]-work1d.L[435]*work1d.d[151]*work1d.L[435]-1*work1d.d[647]*1;
  residual += temp*temp;
  temp = work1d.KKT[1293]-work1d.L[437]*work1d.d[152]*work1d.L[437]-1*work1d.d[649]*1-work1d.L[438]*work1d.d[648]*work1d.L[438];
  residual += temp*temp;
  temp = work1d.KKT[1295]-work1d.L[439]*work1d.d[153]*work1d.L[439]-1*work1d.d[650]*1-work1d.L[440]*work1d.d[648]*work1d.L[440]-work1d.L[441]*work1d.d[649]*work1d.L[441];
  residual += temp*temp;
  temp = work1d.KKT[1297]-work1d.L[442]*work1d.d[154]*work1d.L[442]-1*work1d.d[651]*1;
  residual += temp*temp;
  temp = work1d.KKT[1301]-work1d.L[444]*work1d.d[155]*work1d.L[444]-1*work1d.d[653]*1-work1d.L[445]*work1d.d[652]*work1d.L[445];
  residual += temp*temp;
  temp = work1d.KKT[1303]-work1d.L[446]*work1d.d[156]*work1d.L[446]-1*work1d.d[654]*1-work1d.L[447]*work1d.d[652]*work1d.L[447]-work1d.L[448]*work1d.d[653]*work1d.L[448];
  residual += temp*temp;
  temp = work1d.KKT[1305]-work1d.L[449]*work1d.d[157]*work1d.L[449]-1*work1d.d[655]*1;
  residual += temp*temp;
  temp = work1d.KKT[1309]-work1d.L[451]*work1d.d[158]*work1d.L[451]-1*work1d.d[657]*1-work1d.L[452]*work1d.d[656]*work1d.L[452];
  residual += temp*temp;
  temp = work1d.KKT[1311]-work1d.L[453]*work1d.d[159]*work1d.L[453]-1*work1d.d[658]*1-work1d.L[454]*work1d.d[656]*work1d.L[454]-work1d.L[455]*work1d.d[657]*work1d.L[455];
  residual += temp*temp;
  temp = work1d.KKT[1313]-work1d.L[456]*work1d.d[160]*work1d.L[456]-1*work1d.d[659]*1;
  residual += temp*temp;
  temp = work1d.KKT[1317]-work1d.L[458]*work1d.d[161]*work1d.L[458]-1*work1d.d[661]*1-work1d.L[459]*work1d.d[660]*work1d.L[459];
  residual += temp*temp;
  temp = work1d.KKT[1319]-work1d.L[460]*work1d.d[162]*work1d.L[460]-1*work1d.d[662]*1-work1d.L[461]*work1d.d[660]*work1d.L[461]-work1d.L[462]*work1d.d[661]*work1d.L[462];
  residual += temp*temp;
  temp = work1d.KKT[1321]-work1d.L[463]*work1d.d[163]*work1d.L[463]-1*work1d.d[663]*1;
  residual += temp*temp;
  temp = work1d.KKT[1325]-work1d.L[465]*work1d.d[164]*work1d.L[465]-1*work1d.d[665]*1-work1d.L[466]*work1d.d[664]*work1d.L[466];
  residual += temp*temp;
  temp = work1d.KKT[1327]-work1d.L[467]*work1d.d[165]*work1d.L[467]-1*work1d.d[666]*1-work1d.L[468]*work1d.d[664]*work1d.L[468]-work1d.L[469]*work1d.d[665]*work1d.L[469];
  residual += temp*temp;
  temp = work1d.KKT[1329]-work1d.L[470]*work1d.d[166]*work1d.L[470]-1*work1d.d[667]*1;
  residual += temp*temp;
  temp = work1d.KKT[1333]-work1d.L[472]*work1d.d[167]*work1d.L[472]-1*work1d.d[669]*1-work1d.L[473]*work1d.d[668]*work1d.L[473];
  residual += temp*temp;
  temp = work1d.KKT[1335]-work1d.L[474]*work1d.d[168]*work1d.L[474]-1*work1d.d[670]*1-work1d.L[475]*work1d.d[668]*work1d.L[475]-work1d.L[476]*work1d.d[669]*work1d.L[476];
  residual += temp*temp;
  temp = work1d.KKT[1337]-work1d.L[477]*work1d.d[169]*work1d.L[477]-1*work1d.d[671]*1;
  residual += temp*temp;
  temp = work1d.KKT[1341]-work1d.L[479]*work1d.d[170]*work1d.L[479]-1*work1d.d[673]*1-work1d.L[480]*work1d.d[672]*work1d.L[480];
  residual += temp*temp;
  temp = work1d.KKT[1343]-work1d.L[481]*work1d.d[171]*work1d.L[481]-1*work1d.d[674]*1-work1d.L[482]*work1d.d[672]*work1d.L[482]-work1d.L[483]*work1d.d[673]*work1d.L[483];
  residual += temp*temp;
  temp = work1d.KKT[1345]-work1d.L[484]*work1d.d[172]*work1d.L[484]-1*work1d.d[675]*1;
  residual += temp*temp;
  temp = work1d.KKT[1349]-work1d.L[486]*work1d.d[173]*work1d.L[486]-1*work1d.d[677]*1-work1d.L[487]*work1d.d[676]*work1d.L[487];
  residual += temp*temp;
  temp = work1d.KKT[1351]-work1d.L[488]*work1d.d[174]*work1d.L[488]-1*work1d.d[678]*1-work1d.L[489]*work1d.d[676]*work1d.L[489]-work1d.L[490]*work1d.d[677]*work1d.L[490];
  residual += temp*temp;
  temp = work1d.KKT[1353]-work1d.L[491]*work1d.d[175]*work1d.L[491]-1*work1d.d[679]*1;
  residual += temp*temp;
  temp = work1d.KKT[1357]-work1d.L[493]*work1d.d[176]*work1d.L[493]-1*work1d.d[681]*1-work1d.L[494]*work1d.d[680]*work1d.L[494];
  residual += temp*temp;
  temp = work1d.KKT[1359]-work1d.L[495]*work1d.d[177]*work1d.L[495]-1*work1d.d[682]*1-work1d.L[496]*work1d.d[680]*work1d.L[496]-work1d.L[497]*work1d.d[681]*work1d.L[497];
  residual += temp*temp;
  temp = work1d.KKT[1361]-work1d.L[498]*work1d.d[178]*work1d.L[498]-1*work1d.d[683]*1;
  residual += temp*temp;
  temp = work1d.KKT[1365]-work1d.L[500]*work1d.d[179]*work1d.L[500]-1*work1d.d[685]*1-work1d.L[501]*work1d.d[684]*work1d.L[501];
  residual += temp*temp;
  temp = work1d.KKT[1367]-work1d.L[502]*work1d.d[180]*work1d.L[502]-1*work1d.d[686]*1-work1d.L[503]*work1d.d[684]*work1d.L[503]-work1d.L[504]*work1d.d[685]*work1d.L[504];
  residual += temp*temp;
  temp = work1d.KKT[1369]-work1d.L[505]*work1d.d[181]*work1d.L[505]-1*work1d.d[687]*1;
  residual += temp*temp;
  temp = work1d.KKT[1373]-work1d.L[507]*work1d.d[182]*work1d.L[507]-1*work1d.d[689]*1-work1d.L[508]*work1d.d[688]*work1d.L[508];
  residual += temp*temp;
  temp = work1d.KKT[1375]-work1d.L[509]*work1d.d[183]*work1d.L[509]-1*work1d.d[690]*1-work1d.L[510]*work1d.d[688]*work1d.L[510]-work1d.L[511]*work1d.d[689]*work1d.L[511];
  residual += temp*temp;
  temp = work1d.KKT[1377]-work1d.L[512]*work1d.d[184]*work1d.L[512]-1*work1d.d[691]*1;
  residual += temp*temp;
  temp = work1d.KKT[1381]-work1d.L[514]*work1d.d[185]*work1d.L[514]-1*work1d.d[693]*1-work1d.L[515]*work1d.d[692]*work1d.L[515];
  residual += temp*temp;
  temp = work1d.KKT[1383]-work1d.L[516]*work1d.d[186]*work1d.L[516]-1*work1d.d[694]*1-work1d.L[517]*work1d.d[692]*work1d.L[517]-work1d.L[518]*work1d.d[693]*work1d.L[518];
  residual += temp*temp;
  temp = work1d.KKT[1385]-work1d.L[519]*work1d.d[187]*work1d.L[519]-1*work1d.d[695]*1;
  residual += temp*temp;
  temp = work1d.KKT[1389]-work1d.L[521]*work1d.d[188]*work1d.L[521]-1*work1d.d[697]*1-work1d.L[522]*work1d.d[696]*work1d.L[522];
  residual += temp*temp;
  temp = work1d.KKT[1391]-work1d.L[523]*work1d.d[189]*work1d.L[523]-1*work1d.d[698]*1-work1d.L[524]*work1d.d[696]*work1d.L[524]-work1d.L[525]*work1d.d[697]*work1d.L[525];
  residual += temp*temp;
  temp = work1d.KKT[1393]-work1d.L[526]*work1d.d[190]*work1d.L[526]-1*work1d.d[699]*1;
  residual += temp*temp;
  temp = work1d.KKT[1397]-work1d.L[528]*work1d.d[191]*work1d.L[528]-1*work1d.d[701]*1-work1d.L[529]*work1d.d[700]*work1d.L[529];
  residual += temp*temp;
  temp = work1d.KKT[1399]-work1d.L[530]*work1d.d[192]*work1d.L[530]-1*work1d.d[702]*1-work1d.L[531]*work1d.d[700]*work1d.L[531]-work1d.L[532]*work1d.d[701]*work1d.L[532];
  residual += temp*temp;
  temp = work1d.KKT[1401]-work1d.L[533]*work1d.d[193]*work1d.L[533]-1*work1d.d[703]*1;
  residual += temp*temp;
  temp = work1d.KKT[1405]-work1d.L[535]*work1d.d[194]*work1d.L[535]-1*work1d.d[705]*1-work1d.L[536]*work1d.d[704]*work1d.L[536];
  residual += temp*temp;
  temp = work1d.KKT[1407]-work1d.L[537]*work1d.d[195]*work1d.L[537]-1*work1d.d[706]*1-work1d.L[538]*work1d.d[704]*work1d.L[538]-work1d.L[539]*work1d.d[705]*work1d.L[539];
  residual += temp*temp;
  temp = work1d.KKT[1409]-work1d.L[540]*work1d.d[196]*work1d.L[540]-1*work1d.d[707]*1;
  residual += temp*temp;
  temp = work1d.KKT[1413]-work1d.L[542]*work1d.d[197]*work1d.L[542]-1*work1d.d[709]*1-work1d.L[543]*work1d.d[708]*work1d.L[543];
  residual += temp*temp;
  temp = work1d.KKT[1415]-work1d.L[544]*work1d.d[198]*work1d.L[544]-1*work1d.d[710]*1-work1d.L[545]*work1d.d[708]*work1d.L[545]-work1d.L[546]*work1d.d[709]*work1d.L[546];
  residual += temp*temp;
  temp = work1d.KKT[1417]-work1d.L[547]*work1d.d[199]*work1d.L[547]-1*work1d.d[711]*1;
  residual += temp*temp;
  temp = work1d.KKT[1421]-work1d.L[549]*work1d.d[200]*work1d.L[549]-1*work1d.d[713]*1-work1d.L[550]*work1d.d[712]*work1d.L[550];
  residual += temp*temp;
  temp = work1d.KKT[1423]-work1d.L[551]*work1d.d[201]*work1d.L[551]-1*work1d.d[714]*1-work1d.L[552]*work1d.d[712]*work1d.L[552]-work1d.L[553]*work1d.d[713]*work1d.L[553];
  residual += temp*temp;
  temp = work1d.KKT[1425]-work1d.L[554]*work1d.d[202]*work1d.L[554]-1*work1d.d[715]*1;
  residual += temp*temp;
  temp = work1d.KKT[1429]-work1d.L[556]*work1d.d[203]*work1d.L[556]-1*work1d.d[717]*1-work1d.L[557]*work1d.d[716]*work1d.L[557];
  residual += temp*temp;
  temp = work1d.KKT[1431]-work1d.L[558]*work1d.d[204]*work1d.L[558]-1*work1d.d[718]*1-work1d.L[559]*work1d.d[716]*work1d.L[559]-work1d.L[560]*work1d.d[717]*work1d.L[560];
  residual += temp*temp;
  temp = work1d.KKT[1433]-work1d.L[561]*work1d.d[205]*work1d.L[561]-1*work1d.d[719]*1;
  residual += temp*temp;
  temp = work1d.KKT[1437]-work1d.L[563]*work1d.d[206]*work1d.L[563]-1*work1d.d[721]*1-work1d.L[564]*work1d.d[720]*work1d.L[564];
  residual += temp*temp;
  temp = work1d.KKT[1439]-work1d.L[565]*work1d.d[207]*work1d.L[565]-1*work1d.d[722]*1-work1d.L[566]*work1d.d[720]*work1d.L[566]-work1d.L[567]*work1d.d[721]*work1d.L[567];
  residual += temp*temp;
  temp = work1d.KKT[1441]-work1d.L[568]*work1d.d[208]*work1d.L[568]-1*work1d.d[723]*1;
  residual += temp*temp;
  temp = work1d.KKT[1445]-work1d.L[570]*work1d.d[209]*work1d.L[570]-1*work1d.d[725]*1-work1d.L[571]*work1d.d[724]*work1d.L[571];
  residual += temp*temp;
  temp = work1d.KKT[1447]-work1d.L[572]*work1d.d[210]*work1d.L[572]-1*work1d.d[726]*1-work1d.L[573]*work1d.d[724]*work1d.L[573]-work1d.L[574]*work1d.d[725]*work1d.L[574];
  residual += temp*temp;
  temp = work1d.KKT[1449]-work1d.L[575]*work1d.d[211]*work1d.L[575]-1*work1d.d[727]*1;
  residual += temp*temp;
  temp = work1d.KKT[1453]-work1d.L[577]*work1d.d[212]*work1d.L[577]-1*work1d.d[729]*1-work1d.L[578]*work1d.d[728]*work1d.L[578];
  residual += temp*temp;
  temp = work1d.KKT[1455]-work1d.L[579]*work1d.d[213]*work1d.L[579]-1*work1d.d[730]*1-work1d.L[580]*work1d.d[728]*work1d.L[580]-work1d.L[581]*work1d.d[729]*work1d.L[581];
  residual += temp*temp;
  temp = work1d.KKT[1457]-work1d.L[582]*work1d.d[214]*work1d.L[582]-1*work1d.d[731]*1;
  residual += temp*temp;
  temp = work1d.KKT[1461]-work1d.L[584]*work1d.d[215]*work1d.L[584]-1*work1d.d[733]*1-work1d.L[585]*work1d.d[732]*work1d.L[585];
  residual += temp*temp;
  temp = work1d.KKT[1463]-work1d.L[586]*work1d.d[216]*work1d.L[586]-1*work1d.d[734]*1-work1d.L[587]*work1d.d[732]*work1d.L[587]-work1d.L[588]*work1d.d[733]*work1d.L[588];
  residual += temp*temp;
  temp = work1d.KKT[1465]-work1d.L[589]*work1d.d[217]*work1d.L[589]-1*work1d.d[735]*1;
  residual += temp*temp;
  temp = work1d.KKT[1469]-work1d.L[591]*work1d.d[218]*work1d.L[591]-1*work1d.d[737]*1-work1d.L[592]*work1d.d[736]*work1d.L[592];
  residual += temp*temp;
  temp = work1d.KKT[1471]-work1d.L[593]*work1d.d[219]*work1d.L[593]-1*work1d.d[738]*1-work1d.L[594]*work1d.d[736]*work1d.L[594]-work1d.L[595]*work1d.d[737]*work1d.L[595];
  residual += temp*temp;
  temp = work1d.KKT[1473]-work1d.L[596]*work1d.d[220]*work1d.L[596]-1*work1d.d[739]*1;
  residual += temp*temp;
  temp = work1d.KKT[1477]-work1d.L[598]*work1d.d[221]*work1d.L[598]-1*work1d.d[741]*1-work1d.L[599]*work1d.d[740]*work1d.L[599];
  residual += temp*temp;
  temp = work1d.KKT[1479]-work1d.L[600]*work1d.d[222]*work1d.L[600]-1*work1d.d[742]*1-work1d.L[601]*work1d.d[740]*work1d.L[601]-work1d.L[602]*work1d.d[741]*work1d.L[602];
  residual += temp*temp;
  temp = work1d.KKT[1481]-work1d.L[603]*work1d.d[223]*work1d.L[603]-1*work1d.d[743]*1;
  residual += temp*temp;
  temp = work1d.KKT[1485]-work1d.L[605]*work1d.d[224]*work1d.L[605]-1*work1d.d[745]*1-work1d.L[606]*work1d.d[744]*work1d.L[606];
  residual += temp*temp;
  temp = work1d.KKT[1487]-work1d.L[607]*work1d.d[225]*work1d.L[607]-1*work1d.d[746]*1-work1d.L[608]*work1d.d[744]*work1d.L[608]-work1d.L[609]*work1d.d[745]*work1d.L[609];
  residual += temp*temp;
  temp = work1d.KKT[1489]-work1d.L[610]*work1d.d[226]*work1d.L[610]-1*work1d.d[747]*1;
  residual += temp*temp;
  temp = work1d.KKT[1493]-work1d.L[612]*work1d.d[227]*work1d.L[612]-1*work1d.d[749]*1-work1d.L[613]*work1d.d[748]*work1d.L[613];
  residual += temp*temp;
  temp = work1d.KKT[1495]-work1d.L[614]*work1d.d[228]*work1d.L[614]-1*work1d.d[750]*1-work1d.L[615]*work1d.d[748]*work1d.L[615]-work1d.L[616]*work1d.d[749]*work1d.L[616];
  residual += temp*temp;
  temp = work1d.KKT[1497]-work1d.L[617]*work1d.d[229]*work1d.L[617]-1*work1d.d[751]*1;
  residual += temp*temp;
  temp = work1d.KKT[1501]-work1d.L[619]*work1d.d[230]*work1d.L[619]-1*work1d.d[753]*1-work1d.L[620]*work1d.d[752]*work1d.L[620];
  residual += temp*temp;
  temp = work1d.KKT[1503]-work1d.L[621]*work1d.d[231]*work1d.L[621]-1*work1d.d[754]*1-work1d.L[622]*work1d.d[752]*work1d.L[622]-work1d.L[623]*work1d.d[753]*work1d.L[623];
  residual += temp*temp;
  temp = work1d.KKT[1505]-work1d.L[624]*work1d.d[232]*work1d.L[624]-1*work1d.d[755]*1;
  residual += temp*temp;
  temp = work1d.KKT[1509]-work1d.L[626]*work1d.d[233]*work1d.L[626]-1*work1d.d[757]*1-work1d.L[627]*work1d.d[756]*work1d.L[627];
  residual += temp*temp;
  temp = work1d.KKT[1511]-work1d.L[628]*work1d.d[234]*work1d.L[628]-1*work1d.d[758]*1-work1d.L[629]*work1d.d[756]*work1d.L[629]-work1d.L[630]*work1d.d[757]*work1d.L[630];
  residual += temp*temp;
  temp = work1d.KKT[1513]-work1d.L[631]*work1d.d[235]*work1d.L[631]-1*work1d.d[759]*1;
  residual += temp*temp;
  temp = work1d.KKT[1517]-work1d.L[633]*work1d.d[236]*work1d.L[633]-1*work1d.d[761]*1-work1d.L[634]*work1d.d[760]*work1d.L[634];
  residual += temp*temp;
  temp = work1d.KKT[1519]-work1d.L[635]*work1d.d[237]*work1d.L[635]-1*work1d.d[762]*1-work1d.L[636]*work1d.d[760]*work1d.L[636]-work1d.L[637]*work1d.d[761]*work1d.L[637];
  residual += temp*temp;
  temp = work1d.KKT[1521]-work1d.L[638]*work1d.d[238]*work1d.L[638]-1*work1d.d[763]*1;
  residual += temp*temp;
  temp = work1d.KKT[1525]-work1d.L[640]*work1d.d[239]*work1d.L[640]-1*work1d.d[765]*1-work1d.L[641]*work1d.d[764]*work1d.L[641];
  residual += temp*temp;
  temp = work1d.KKT[1527]-work1d.L[642]*work1d.d[240]*work1d.L[642]-1*work1d.d[766]*1-work1d.L[643]*work1d.d[764]*work1d.L[643]-work1d.L[644]*work1d.d[765]*work1d.L[644];
  residual += temp*temp;
  temp = work1d.KKT[641]-work1d.L[0]*work1d.d[241]*work1d.L[0]-1*work1d.d[321]*1;
  residual += temp*temp;
  temp = work1d.KKT[643]-work1d.L[1]*work1d.d[242]*work1d.L[1]-1*work1d.d[322]*1;
  residual += temp*temp;
  temp = work1d.KKT[645]-work1d.L[2]*work1d.d[243]*work1d.L[2]-1*work1d.d[323]*1;
  residual += temp*temp;
  temp = work1d.KKT[647]-work1d.L[3]*work1d.d[244]*work1d.L[3]-1*work1d.d[324]*1;
  residual += temp*temp;
  temp = work1d.KKT[649]-work1d.L[4]*work1d.d[245]*work1d.L[4]-1*work1d.d[325]*1;
  residual += temp*temp;
  temp = work1d.KKT[651]-work1d.L[5]*work1d.d[246]*work1d.L[5]-1*work1d.d[326]*1;
  residual += temp*temp;
  temp = work1d.KKT[653]-work1d.L[6]*work1d.d[247]*work1d.L[6]-1*work1d.d[327]*1;
  residual += temp*temp;
  temp = work1d.KKT[655]-work1d.L[7]*work1d.d[248]*work1d.L[7]-1*work1d.d[328]*1;
  residual += temp*temp;
  temp = work1d.KKT[657]-work1d.L[8]*work1d.d[249]*work1d.L[8]-1*work1d.d[329]*1;
  residual += temp*temp;
  temp = work1d.KKT[659]-work1d.L[9]*work1d.d[250]*work1d.L[9]-1*work1d.d[330]*1;
  residual += temp*temp;
  temp = work1d.KKT[661]-work1d.L[10]*work1d.d[251]*work1d.L[10]-1*work1d.d[331]*1;
  residual += temp*temp;
  temp = work1d.KKT[663]-work1d.L[11]*work1d.d[252]*work1d.L[11]-1*work1d.d[332]*1;
  residual += temp*temp;
  temp = work1d.KKT[665]-work1d.L[12]*work1d.d[253]*work1d.L[12]-1*work1d.d[333]*1;
  residual += temp*temp;
  temp = work1d.KKT[667]-work1d.L[13]*work1d.d[254]*work1d.L[13]-1*work1d.d[334]*1;
  residual += temp*temp;
  temp = work1d.KKT[669]-work1d.L[14]*work1d.d[255]*work1d.L[14]-1*work1d.d[335]*1;
  residual += temp*temp;
  temp = work1d.KKT[671]-work1d.L[15]*work1d.d[256]*work1d.L[15]-1*work1d.d[336]*1;
  residual += temp*temp;
  temp = work1d.KKT[673]-work1d.L[16]*work1d.d[257]*work1d.L[16]-1*work1d.d[337]*1;
  residual += temp*temp;
  temp = work1d.KKT[675]-work1d.L[17]*work1d.d[258]*work1d.L[17]-1*work1d.d[338]*1;
  residual += temp*temp;
  temp = work1d.KKT[677]-work1d.L[18]*work1d.d[259]*work1d.L[18]-1*work1d.d[339]*1;
  residual += temp*temp;
  temp = work1d.KKT[679]-work1d.L[19]*work1d.d[260]*work1d.L[19]-1*work1d.d[340]*1;
  residual += temp*temp;
  temp = work1d.KKT[681]-work1d.L[20]*work1d.d[261]*work1d.L[20]-1*work1d.d[341]*1;
  residual += temp*temp;
  temp = work1d.KKT[683]-work1d.L[21]*work1d.d[262]*work1d.L[21]-1*work1d.d[342]*1;
  residual += temp*temp;
  temp = work1d.KKT[685]-work1d.L[22]*work1d.d[263]*work1d.L[22]-1*work1d.d[343]*1;
  residual += temp*temp;
  temp = work1d.KKT[687]-work1d.L[23]*work1d.d[264]*work1d.L[23]-1*work1d.d[344]*1;
  residual += temp*temp;
  temp = work1d.KKT[689]-work1d.L[24]*work1d.d[265]*work1d.L[24]-1*work1d.d[345]*1;
  residual += temp*temp;
  temp = work1d.KKT[691]-work1d.L[25]*work1d.d[266]*work1d.L[25]-1*work1d.d[346]*1;
  residual += temp*temp;
  temp = work1d.KKT[693]-work1d.L[26]*work1d.d[267]*work1d.L[26]-1*work1d.d[347]*1;
  residual += temp*temp;
  temp = work1d.KKT[695]-work1d.L[27]*work1d.d[268]*work1d.L[27]-1*work1d.d[348]*1;
  residual += temp*temp;
  temp = work1d.KKT[697]-work1d.L[28]*work1d.d[269]*work1d.L[28]-1*work1d.d[349]*1;
  residual += temp*temp;
  temp = work1d.KKT[699]-work1d.L[29]*work1d.d[270]*work1d.L[29]-1*work1d.d[350]*1;
  residual += temp*temp;
  temp = work1d.KKT[701]-work1d.L[30]*work1d.d[271]*work1d.L[30]-1*work1d.d[351]*1;
  residual += temp*temp;
  temp = work1d.KKT[703]-work1d.L[31]*work1d.d[272]*work1d.L[31]-1*work1d.d[352]*1;
  residual += temp*temp;
  temp = work1d.KKT[705]-work1d.L[32]*work1d.d[273]*work1d.L[32]-1*work1d.d[353]*1;
  residual += temp*temp;
  temp = work1d.KKT[707]-work1d.L[33]*work1d.d[274]*work1d.L[33]-1*work1d.d[354]*1;
  residual += temp*temp;
  temp = work1d.KKT[709]-work1d.L[34]*work1d.d[275]*work1d.L[34]-1*work1d.d[355]*1;
  residual += temp*temp;
  temp = work1d.KKT[711]-work1d.L[35]*work1d.d[276]*work1d.L[35]-1*work1d.d[356]*1;
  residual += temp*temp;
  temp = work1d.KKT[713]-work1d.L[36]*work1d.d[277]*work1d.L[36]-1*work1d.d[357]*1;
  residual += temp*temp;
  temp = work1d.KKT[715]-work1d.L[37]*work1d.d[278]*work1d.L[37]-1*work1d.d[358]*1;
  residual += temp*temp;
  temp = work1d.KKT[717]-work1d.L[38]*work1d.d[279]*work1d.L[38]-1*work1d.d[359]*1;
  residual += temp*temp;
  temp = work1d.KKT[719]-work1d.L[39]*work1d.d[280]*work1d.L[39]-1*work1d.d[360]*1;
  residual += temp*temp;
  temp = work1d.KKT[721]-work1d.L[40]*work1d.d[281]*work1d.L[40]-1*work1d.d[361]*1;
  residual += temp*temp;
  temp = work1d.KKT[723]-work1d.L[41]*work1d.d[282]*work1d.L[41]-1*work1d.d[362]*1;
  residual += temp*temp;
  temp = work1d.KKT[725]-work1d.L[42]*work1d.d[283]*work1d.L[42]-1*work1d.d[363]*1;
  residual += temp*temp;
  temp = work1d.KKT[727]-work1d.L[43]*work1d.d[284]*work1d.L[43]-1*work1d.d[364]*1;
  residual += temp*temp;
  temp = work1d.KKT[729]-work1d.L[44]*work1d.d[285]*work1d.L[44]-1*work1d.d[365]*1;
  residual += temp*temp;
  temp = work1d.KKT[731]-work1d.L[45]*work1d.d[286]*work1d.L[45]-1*work1d.d[366]*1;
  residual += temp*temp;
  temp = work1d.KKT[733]-work1d.L[46]*work1d.d[287]*work1d.L[46]-1*work1d.d[367]*1;
  residual += temp*temp;
  temp = work1d.KKT[735]-work1d.L[47]*work1d.d[288]*work1d.L[47]-1*work1d.d[368]*1;
  residual += temp*temp;
  temp = work1d.KKT[737]-work1d.L[48]*work1d.d[289]*work1d.L[48]-1*work1d.d[369]*1;
  residual += temp*temp;
  temp = work1d.KKT[739]-work1d.L[49]*work1d.d[290]*work1d.L[49]-1*work1d.d[370]*1;
  residual += temp*temp;
  temp = work1d.KKT[741]-work1d.L[50]*work1d.d[291]*work1d.L[50]-1*work1d.d[371]*1;
  residual += temp*temp;
  temp = work1d.KKT[743]-work1d.L[51]*work1d.d[292]*work1d.L[51]-1*work1d.d[372]*1;
  residual += temp*temp;
  temp = work1d.KKT[745]-work1d.L[52]*work1d.d[293]*work1d.L[52]-1*work1d.d[373]*1;
  residual += temp*temp;
  temp = work1d.KKT[747]-work1d.L[53]*work1d.d[294]*work1d.L[53]-1*work1d.d[374]*1;
  residual += temp*temp;
  temp = work1d.KKT[749]-work1d.L[54]*work1d.d[295]*work1d.L[54]-1*work1d.d[375]*1;
  residual += temp*temp;
  temp = work1d.KKT[751]-work1d.L[55]*work1d.d[296]*work1d.L[55]-1*work1d.d[376]*1;
  residual += temp*temp;
  temp = work1d.KKT[753]-work1d.L[56]*work1d.d[297]*work1d.L[56]-1*work1d.d[377]*1;
  residual += temp*temp;
  temp = work1d.KKT[755]-work1d.L[57]*work1d.d[298]*work1d.L[57]-1*work1d.d[378]*1;
  residual += temp*temp;
  temp = work1d.KKT[757]-work1d.L[58]*work1d.d[299]*work1d.L[58]-1*work1d.d[379]*1;
  residual += temp*temp;
  temp = work1d.KKT[759]-work1d.L[59]*work1d.d[300]*work1d.L[59]-1*work1d.d[380]*1;
  residual += temp*temp;
  temp = work1d.KKT[761]-work1d.L[60]*work1d.d[301]*work1d.L[60]-1*work1d.d[381]*1;
  residual += temp*temp;
  temp = work1d.KKT[763]-work1d.L[61]*work1d.d[302]*work1d.L[61]-1*work1d.d[382]*1;
  residual += temp*temp;
  temp = work1d.KKT[765]-work1d.L[62]*work1d.d[303]*work1d.L[62]-1*work1d.d[383]*1;
  residual += temp*temp;
  temp = work1d.KKT[767]-work1d.L[63]*work1d.d[304]*work1d.L[63]-1*work1d.d[384]*1;
  residual += temp*temp;
  temp = work1d.KKT[769]-work1d.L[64]*work1d.d[305]*work1d.L[64]-1*work1d.d[385]*1;
  residual += temp*temp;
  temp = work1d.KKT[771]-work1d.L[65]*work1d.d[306]*work1d.L[65]-1*work1d.d[386]*1;
  residual += temp*temp;
  temp = work1d.KKT[773]-work1d.L[66]*work1d.d[307]*work1d.L[66]-1*work1d.d[387]*1;
  residual += temp*temp;
  temp = work1d.KKT[775]-work1d.L[67]*work1d.d[308]*work1d.L[67]-1*work1d.d[388]*1;
  residual += temp*temp;
  temp = work1d.KKT[777]-work1d.L[68]*work1d.d[309]*work1d.L[68]-1*work1d.d[389]*1;
  residual += temp*temp;
  temp = work1d.KKT[779]-work1d.L[69]*work1d.d[310]*work1d.L[69]-1*work1d.d[390]*1;
  residual += temp*temp;
  temp = work1d.KKT[781]-work1d.L[70]*work1d.d[311]*work1d.L[70]-1*work1d.d[391]*1;
  residual += temp*temp;
  temp = work1d.KKT[783]-work1d.L[71]*work1d.d[312]*work1d.L[71]-1*work1d.d[392]*1;
  residual += temp*temp;
  temp = work1d.KKT[785]-work1d.L[72]*work1d.d[313]*work1d.L[72]-1*work1d.d[393]*1;
  residual += temp*temp;
  temp = work1d.KKT[787]-work1d.L[73]*work1d.d[314]*work1d.L[73]-1*work1d.d[394]*1;
  residual += temp*temp;
  temp = work1d.KKT[789]-work1d.L[74]*work1d.d[315]*work1d.L[74]-1*work1d.d[395]*1;
  residual += temp*temp;
  temp = work1d.KKT[791]-work1d.L[75]*work1d.d[316]*work1d.L[75]-1*work1d.d[396]*1;
  residual += temp*temp;
  temp = work1d.KKT[793]-work1d.L[76]*work1d.d[317]*work1d.L[76]-1*work1d.d[397]*1;
  residual += temp*temp;
  temp = work1d.KKT[795]-work1d.L[77]*work1d.d[318]*work1d.L[77]-1*work1d.d[398]*1;
  residual += temp*temp;
  temp = work1d.KKT[797]-work1d.L[78]*work1d.d[319]*work1d.L[78]-1*work1d.d[399]*1;
  residual += temp*temp;
  temp = work1d.KKT[799]-work1d.L[79]*work1d.d[320]*work1d.L[79]-1*work1d.d[400]*1;
  residual += temp*temp;
  temp = work1d.KKT[888]-1*work1d.d[446]*work1d.L[83];
  residual += temp*temp;
  temp = work1d.KKT[889]-work1d.L[85]*work1d.d[447]*1;
  residual += temp*temp;
  temp = work1d.KKT[892]-1*work1d.d[448]*work1d.L[700];
  residual += temp*temp;
  temp = work1d.KKT[890]-work1d.L[87]*work1d.d[447]*1;
  residual += temp*temp;
  temp = work1d.KKT[894]-1*work1d.d[449]*work1d.L[701]-work1d.L[88]*work1d.d[448]*work1d.L[700];
  residual += temp*temp;
  temp = work1d.KKT[896]-1*work1d.d[450]*work1d.L[90];
  residual += temp*temp;
  temp = work1d.KKT[897]-work1d.L[92]*work1d.d[451]*1;
  residual += temp*temp;
  temp = work1d.KKT[900]-1*work1d.d[452]*work1d.L[715];
  residual += temp*temp;
  temp = work1d.KKT[898]-work1d.L[94]*work1d.d[451]*1;
  residual += temp*temp;
  temp = work1d.KKT[902]-1*work1d.d[453]*work1d.L[716]-work1d.L[95]*work1d.d[452]*work1d.L[715];
  residual += temp*temp;
  temp = work1d.KKT[904]-1*work1d.d[454]*work1d.L[97];
  residual += temp*temp;
  temp = work1d.KKT[905]-work1d.L[99]*work1d.d[455]*1;
  residual += temp*temp;
  temp = work1d.KKT[908]-1*work1d.d[456]*work1d.L[735];
  residual += temp*temp;
  temp = work1d.KKT[906]-work1d.L[101]*work1d.d[455]*1;
  residual += temp*temp;
  temp = work1d.KKT[910]-1*work1d.d[457]*work1d.L[736]-work1d.L[102]*work1d.d[456]*work1d.L[735];
  residual += temp*temp;
  temp = work1d.KKT[912]-1*work1d.d[458]*work1d.L[104];
  residual += temp*temp;
  temp = work1d.KKT[913]-work1d.L[106]*work1d.d[459]*1;
  residual += temp*temp;
  temp = work1d.KKT[916]-1*work1d.d[460]*work1d.L[757];
  residual += temp*temp;
  temp = work1d.KKT[914]-work1d.L[108]*work1d.d[459]*1;
  residual += temp*temp;
  temp = work1d.KKT[918]-1*work1d.d[461]*work1d.L[758]-work1d.L[109]*work1d.d[460]*work1d.L[757];
  residual += temp*temp;
  temp = work1d.KKT[920]-1*work1d.d[462]*work1d.L[111];
  residual += temp*temp;
  temp = work1d.KKT[921]-work1d.L[113]*work1d.d[463]*1;
  residual += temp*temp;
  temp = work1d.KKT[924]-1*work1d.d[464]*work1d.L[779];
  residual += temp*temp;
  temp = work1d.KKT[922]-work1d.L[115]*work1d.d[463]*1;
  residual += temp*temp;
  temp = work1d.KKT[926]-1*work1d.d[465]*work1d.L[780]-work1d.L[116]*work1d.d[464]*work1d.L[779];
  residual += temp*temp;
  temp = work1d.KKT[928]-1*work1d.d[466]*work1d.L[118];
  residual += temp*temp;
  temp = work1d.KKT[929]-work1d.L[120]*work1d.d[467]*1;
  residual += temp*temp;
  temp = work1d.KKT[932]-1*work1d.d[468]*work1d.L[801];
  residual += temp*temp;
  temp = work1d.KKT[930]-work1d.L[122]*work1d.d[467]*1;
  residual += temp*temp;
  temp = work1d.KKT[934]-1*work1d.d[469]*work1d.L[802]-work1d.L[123]*work1d.d[468]*work1d.L[801];
  residual += temp*temp;
  temp = work1d.KKT[936]-1*work1d.d[470]*work1d.L[125];
  residual += temp*temp;
  temp = work1d.KKT[937]-work1d.L[127]*work1d.d[471]*1;
  residual += temp*temp;
  temp = work1d.KKT[940]-1*work1d.d[472]*work1d.L[823];
  residual += temp*temp;
  temp = work1d.KKT[938]-work1d.L[129]*work1d.d[471]*1;
  residual += temp*temp;
  temp = work1d.KKT[942]-1*work1d.d[473]*work1d.L[824]-work1d.L[130]*work1d.d[472]*work1d.L[823];
  residual += temp*temp;
  temp = work1d.KKT[944]-1*work1d.d[474]*work1d.L[132];
  residual += temp*temp;
  temp = work1d.KKT[945]-work1d.L[134]*work1d.d[475]*1;
  residual += temp*temp;
  temp = work1d.KKT[948]-1*work1d.d[476]*work1d.L[845];
  residual += temp*temp;
  temp = work1d.KKT[946]-work1d.L[136]*work1d.d[475]*1;
  residual += temp*temp;
  temp = work1d.KKT[950]-1*work1d.d[477]*work1d.L[846]-work1d.L[137]*work1d.d[476]*work1d.L[845];
  residual += temp*temp;
  temp = work1d.KKT[952]-1*work1d.d[478]*work1d.L[139];
  residual += temp*temp;
  temp = work1d.KKT[953]-work1d.L[141]*work1d.d[479]*1;
  residual += temp*temp;
  temp = work1d.KKT[956]-1*work1d.d[480]*work1d.L[867];
  residual += temp*temp;
  temp = work1d.KKT[954]-work1d.L[143]*work1d.d[479]*1;
  residual += temp*temp;
  temp = work1d.KKT[958]-1*work1d.d[481]*work1d.L[868]-work1d.L[144]*work1d.d[480]*work1d.L[867];
  residual += temp*temp;
  temp = work1d.KKT[960]-1*work1d.d[482]*work1d.L[146];
  residual += temp*temp;
  temp = work1d.KKT[961]-work1d.L[148]*work1d.d[483]*1;
  residual += temp*temp;
  temp = work1d.KKT[964]-1*work1d.d[484]*work1d.L[889];
  residual += temp*temp;
  temp = work1d.KKT[962]-work1d.L[150]*work1d.d[483]*1;
  residual += temp*temp;
  temp = work1d.KKT[966]-1*work1d.d[485]*work1d.L[890]-work1d.L[151]*work1d.d[484]*work1d.L[889];
  residual += temp*temp;
  temp = work1d.KKT[968]-1*work1d.d[486]*work1d.L[153];
  residual += temp*temp;
  temp = work1d.KKT[969]-work1d.L[155]*work1d.d[487]*1;
  residual += temp*temp;
  temp = work1d.KKT[972]-1*work1d.d[488]*work1d.L[911];
  residual += temp*temp;
  temp = work1d.KKT[970]-work1d.L[157]*work1d.d[487]*1;
  residual += temp*temp;
  temp = work1d.KKT[974]-1*work1d.d[489]*work1d.L[912]-work1d.L[158]*work1d.d[488]*work1d.L[911];
  residual += temp*temp;
  temp = work1d.KKT[976]-1*work1d.d[490]*work1d.L[160];
  residual += temp*temp;
  temp = work1d.KKT[977]-work1d.L[162]*work1d.d[491]*1;
  residual += temp*temp;
  temp = work1d.KKT[980]-1*work1d.d[492]*work1d.L[933];
  residual += temp*temp;
  temp = work1d.KKT[978]-work1d.L[164]*work1d.d[491]*1;
  residual += temp*temp;
  temp = work1d.KKT[982]-1*work1d.d[493]*work1d.L[934]-work1d.L[165]*work1d.d[492]*work1d.L[933];
  residual += temp*temp;
  temp = work1d.KKT[984]-1*work1d.d[494]*work1d.L[167];
  residual += temp*temp;
  temp = work1d.KKT[985]-work1d.L[169]*work1d.d[495]*1;
  residual += temp*temp;
  temp = work1d.KKT[988]-1*work1d.d[496]*work1d.L[955];
  residual += temp*temp;
  temp = work1d.KKT[986]-work1d.L[171]*work1d.d[495]*1;
  residual += temp*temp;
  temp = work1d.KKT[990]-1*work1d.d[497]*work1d.L[956]-work1d.L[172]*work1d.d[496]*work1d.L[955];
  residual += temp*temp;
  temp = work1d.KKT[992]-1*work1d.d[498]*work1d.L[174];
  residual += temp*temp;
  temp = work1d.KKT[993]-work1d.L[176]*work1d.d[499]*1;
  residual += temp*temp;
  temp = work1d.KKT[996]-1*work1d.d[500]*work1d.L[977];
  residual += temp*temp;
  temp = work1d.KKT[994]-work1d.L[178]*work1d.d[499]*1;
  residual += temp*temp;
  temp = work1d.KKT[998]-1*work1d.d[501]*work1d.L[978]-work1d.L[179]*work1d.d[500]*work1d.L[977];
  residual += temp*temp;
  temp = work1d.KKT[1000]-1*work1d.d[502]*work1d.L[181];
  residual += temp*temp;
  temp = work1d.KKT[1001]-work1d.L[183]*work1d.d[503]*1;
  residual += temp*temp;
  temp = work1d.KKT[1004]-1*work1d.d[504]*work1d.L[999];
  residual += temp*temp;
  temp = work1d.KKT[1002]-work1d.L[185]*work1d.d[503]*1;
  residual += temp*temp;
  temp = work1d.KKT[1006]-1*work1d.d[505]*work1d.L[1000]-work1d.L[186]*work1d.d[504]*work1d.L[999];
  residual += temp*temp;
  temp = work1d.KKT[1008]-1*work1d.d[506]*work1d.L[188];
  residual += temp*temp;
  temp = work1d.KKT[1009]-work1d.L[190]*work1d.d[507]*1;
  residual += temp*temp;
  temp = work1d.KKT[1012]-1*work1d.d[508]*work1d.L[1021];
  residual += temp*temp;
  temp = work1d.KKT[1010]-work1d.L[192]*work1d.d[507]*1;
  residual += temp*temp;
  temp = work1d.KKT[1014]-1*work1d.d[509]*work1d.L[1022]-work1d.L[193]*work1d.d[508]*work1d.L[1021];
  residual += temp*temp;
  temp = work1d.KKT[1016]-1*work1d.d[510]*work1d.L[195];
  residual += temp*temp;
  temp = work1d.KKT[1017]-work1d.L[197]*work1d.d[511]*1;
  residual += temp*temp;
  temp = work1d.KKT[1020]-1*work1d.d[512]*work1d.L[1043];
  residual += temp*temp;
  temp = work1d.KKT[1018]-work1d.L[199]*work1d.d[511]*1;
  residual += temp*temp;
  temp = work1d.KKT[1022]-1*work1d.d[513]*work1d.L[1044]-work1d.L[200]*work1d.d[512]*work1d.L[1043];
  residual += temp*temp;
  temp = work1d.KKT[1024]-1*work1d.d[514]*work1d.L[202];
  residual += temp*temp;
  temp = work1d.KKT[1025]-work1d.L[204]*work1d.d[515]*1;
  residual += temp*temp;
  temp = work1d.KKT[1028]-1*work1d.d[516]*work1d.L[1065];
  residual += temp*temp;
  temp = work1d.KKT[1026]-work1d.L[206]*work1d.d[515]*1;
  residual += temp*temp;
  temp = work1d.KKT[1030]-1*work1d.d[517]*work1d.L[1066]-work1d.L[207]*work1d.d[516]*work1d.L[1065];
  residual += temp*temp;
  temp = work1d.KKT[1032]-1*work1d.d[518]*work1d.L[209];
  residual += temp*temp;
  temp = work1d.KKT[1033]-work1d.L[211]*work1d.d[519]*1;
  residual += temp*temp;
  temp = work1d.KKT[1036]-1*work1d.d[520]*work1d.L[1087];
  residual += temp*temp;
  temp = work1d.KKT[1034]-work1d.L[213]*work1d.d[519]*1;
  residual += temp*temp;
  temp = work1d.KKT[1038]-1*work1d.d[521]*work1d.L[1088]-work1d.L[214]*work1d.d[520]*work1d.L[1087];
  residual += temp*temp;
  temp = work1d.KKT[1040]-1*work1d.d[522]*work1d.L[216];
  residual += temp*temp;
  temp = work1d.KKT[1041]-work1d.L[218]*work1d.d[523]*1;
  residual += temp*temp;
  temp = work1d.KKT[1044]-1*work1d.d[524]*work1d.L[1109];
  residual += temp*temp;
  temp = work1d.KKT[1042]-work1d.L[220]*work1d.d[523]*1;
  residual += temp*temp;
  temp = work1d.KKT[1046]-1*work1d.d[525]*work1d.L[1110]-work1d.L[221]*work1d.d[524]*work1d.L[1109];
  residual += temp*temp;
  temp = work1d.KKT[1048]-1*work1d.d[526]*work1d.L[223];
  residual += temp*temp;
  temp = work1d.KKT[1049]-work1d.L[225]*work1d.d[527]*1;
  residual += temp*temp;
  temp = work1d.KKT[1052]-1*work1d.d[528]*work1d.L[1131];
  residual += temp*temp;
  temp = work1d.KKT[1050]-work1d.L[227]*work1d.d[527]*1;
  residual += temp*temp;
  temp = work1d.KKT[1054]-1*work1d.d[529]*work1d.L[1132]-work1d.L[228]*work1d.d[528]*work1d.L[1131];
  residual += temp*temp;
  temp = work1d.KKT[1056]-1*work1d.d[530]*work1d.L[230];
  residual += temp*temp;
  temp = work1d.KKT[1057]-work1d.L[232]*work1d.d[531]*1;
  residual += temp*temp;
  temp = work1d.KKT[1060]-1*work1d.d[532]*work1d.L[1153];
  residual += temp*temp;
  temp = work1d.KKT[1058]-work1d.L[234]*work1d.d[531]*1;
  residual += temp*temp;
  temp = work1d.KKT[1062]-1*work1d.d[533]*work1d.L[1154]-work1d.L[235]*work1d.d[532]*work1d.L[1153];
  residual += temp*temp;
  temp = work1d.KKT[1064]-1*work1d.d[534]*work1d.L[237];
  residual += temp*temp;
  temp = work1d.KKT[1065]-work1d.L[239]*work1d.d[535]*1;
  residual += temp*temp;
  temp = work1d.KKT[1068]-1*work1d.d[536]*work1d.L[1175];
  residual += temp*temp;
  temp = work1d.KKT[1066]-work1d.L[241]*work1d.d[535]*1;
  residual += temp*temp;
  temp = work1d.KKT[1070]-1*work1d.d[537]*work1d.L[1176]-work1d.L[242]*work1d.d[536]*work1d.L[1175];
  residual += temp*temp;
  temp = work1d.KKT[1072]-1*work1d.d[538]*work1d.L[244];
  residual += temp*temp;
  temp = work1d.KKT[1073]-work1d.L[246]*work1d.d[539]*1;
  residual += temp*temp;
  temp = work1d.KKT[1076]-1*work1d.d[540]*work1d.L[1197];
  residual += temp*temp;
  temp = work1d.KKT[1074]-work1d.L[248]*work1d.d[539]*1;
  residual += temp*temp;
  temp = work1d.KKT[1078]-1*work1d.d[541]*work1d.L[1198]-work1d.L[249]*work1d.d[540]*work1d.L[1197];
  residual += temp*temp;
  temp = work1d.KKT[1080]-1*work1d.d[542]*work1d.L[251];
  residual += temp*temp;
  temp = work1d.KKT[1081]-work1d.L[253]*work1d.d[543]*1;
  residual += temp*temp;
  temp = work1d.KKT[1084]-1*work1d.d[544]*work1d.L[1219];
  residual += temp*temp;
  temp = work1d.KKT[1082]-work1d.L[255]*work1d.d[543]*1;
  residual += temp*temp;
  temp = work1d.KKT[1086]-1*work1d.d[545]*work1d.L[1220]-work1d.L[256]*work1d.d[544]*work1d.L[1219];
  residual += temp*temp;
  temp = work1d.KKT[1088]-1*work1d.d[546]*work1d.L[258];
  residual += temp*temp;
  temp = work1d.KKT[1089]-work1d.L[260]*work1d.d[547]*1;
  residual += temp*temp;
  temp = work1d.KKT[1092]-1*work1d.d[548]*work1d.L[1241];
  residual += temp*temp;
  temp = work1d.KKT[1090]-work1d.L[262]*work1d.d[547]*1;
  residual += temp*temp;
  temp = work1d.KKT[1094]-1*work1d.d[549]*work1d.L[1242]-work1d.L[263]*work1d.d[548]*work1d.L[1241];
  residual += temp*temp;
  temp = work1d.KKT[1096]-1*work1d.d[550]*work1d.L[265];
  residual += temp*temp;
  temp = work1d.KKT[1097]-work1d.L[267]*work1d.d[551]*1;
  residual += temp*temp;
  temp = work1d.KKT[1100]-1*work1d.d[552]*work1d.L[1263];
  residual += temp*temp;
  temp = work1d.KKT[1098]-work1d.L[269]*work1d.d[551]*1;
  residual += temp*temp;
  temp = work1d.KKT[1102]-1*work1d.d[553]*work1d.L[1264]-work1d.L[270]*work1d.d[552]*work1d.L[1263];
  residual += temp*temp;
  temp = work1d.KKT[1104]-1*work1d.d[554]*work1d.L[272];
  residual += temp*temp;
  temp = work1d.KKT[1105]-work1d.L[274]*work1d.d[555]*1;
  residual += temp*temp;
  temp = work1d.KKT[1108]-1*work1d.d[556]*work1d.L[1285];
  residual += temp*temp;
  temp = work1d.KKT[1106]-work1d.L[276]*work1d.d[555]*1;
  residual += temp*temp;
  temp = work1d.KKT[1110]-1*work1d.d[557]*work1d.L[1286]-work1d.L[277]*work1d.d[556]*work1d.L[1285];
  residual += temp*temp;
  temp = work1d.KKT[1112]-1*work1d.d[558]*work1d.L[279];
  residual += temp*temp;
  temp = work1d.KKT[1113]-work1d.L[281]*work1d.d[559]*1;
  residual += temp*temp;
  temp = work1d.KKT[1116]-1*work1d.d[560]*work1d.L[1307];
  residual += temp*temp;
  temp = work1d.KKT[1114]-work1d.L[283]*work1d.d[559]*1;
  residual += temp*temp;
  temp = work1d.KKT[1118]-1*work1d.d[561]*work1d.L[1308]-work1d.L[284]*work1d.d[560]*work1d.L[1307];
  residual += temp*temp;
  temp = work1d.KKT[1120]-1*work1d.d[562]*work1d.L[286];
  residual += temp*temp;
  temp = work1d.KKT[1121]-work1d.L[288]*work1d.d[563]*1;
  residual += temp*temp;
  temp = work1d.KKT[1124]-1*work1d.d[564]*work1d.L[1329];
  residual += temp*temp;
  temp = work1d.KKT[1122]-work1d.L[290]*work1d.d[563]*1;
  residual += temp*temp;
  temp = work1d.KKT[1126]-1*work1d.d[565]*work1d.L[1330]-work1d.L[291]*work1d.d[564]*work1d.L[1329];
  residual += temp*temp;
  temp = work1d.KKT[1128]-1*work1d.d[566]*work1d.L[293];
  residual += temp*temp;
  temp = work1d.KKT[1129]-work1d.L[295]*work1d.d[567]*1;
  residual += temp*temp;
  temp = work1d.KKT[1132]-1*work1d.d[568]*work1d.L[1351];
  residual += temp*temp;
  temp = work1d.KKT[1130]-work1d.L[297]*work1d.d[567]*1;
  residual += temp*temp;
  temp = work1d.KKT[1134]-1*work1d.d[569]*work1d.L[1352]-work1d.L[298]*work1d.d[568]*work1d.L[1351];
  residual += temp*temp;
  temp = work1d.KKT[1136]-1*work1d.d[570]*work1d.L[300];
  residual += temp*temp;
  temp = work1d.KKT[1137]-work1d.L[302]*work1d.d[571]*1;
  residual += temp*temp;
  temp = work1d.KKT[1140]-1*work1d.d[572]*work1d.L[1373];
  residual += temp*temp;
  temp = work1d.KKT[1138]-work1d.L[304]*work1d.d[571]*1;
  residual += temp*temp;
  temp = work1d.KKT[1142]-1*work1d.d[573]*work1d.L[1374]-work1d.L[305]*work1d.d[572]*work1d.L[1373];
  residual += temp*temp;
  temp = work1d.KKT[1144]-1*work1d.d[574]*work1d.L[307];
  residual += temp*temp;
  temp = work1d.KKT[1145]-work1d.L[309]*work1d.d[575]*1;
  residual += temp*temp;
  temp = work1d.KKT[1148]-1*work1d.d[576]*work1d.L[1395];
  residual += temp*temp;
  temp = work1d.KKT[1146]-work1d.L[311]*work1d.d[575]*1;
  residual += temp*temp;
  temp = work1d.KKT[1150]-1*work1d.d[577]*work1d.L[1396]-work1d.L[312]*work1d.d[576]*work1d.L[1395];
  residual += temp*temp;
  temp = work1d.KKT[1152]-1*work1d.d[578]*work1d.L[314];
  residual += temp*temp;
  temp = work1d.KKT[1153]-work1d.L[316]*work1d.d[579]*1;
  residual += temp*temp;
  temp = work1d.KKT[1156]-1*work1d.d[580]*work1d.L[1417];
  residual += temp*temp;
  temp = work1d.KKT[1154]-work1d.L[318]*work1d.d[579]*1;
  residual += temp*temp;
  temp = work1d.KKT[1158]-1*work1d.d[581]*work1d.L[1418]-work1d.L[319]*work1d.d[580]*work1d.L[1417];
  residual += temp*temp;
  temp = work1d.KKT[1160]-1*work1d.d[582]*work1d.L[321];
  residual += temp*temp;
  temp = work1d.KKT[1161]-work1d.L[323]*work1d.d[583]*1;
  residual += temp*temp;
  temp = work1d.KKT[1164]-1*work1d.d[584]*work1d.L[1439];
  residual += temp*temp;
  temp = work1d.KKT[1162]-work1d.L[325]*work1d.d[583]*1;
  residual += temp*temp;
  temp = work1d.KKT[1166]-1*work1d.d[585]*work1d.L[1440]-work1d.L[326]*work1d.d[584]*work1d.L[1439];
  residual += temp*temp;
  temp = work1d.KKT[1168]-1*work1d.d[586]*work1d.L[328];
  residual += temp*temp;
  temp = work1d.KKT[1169]-work1d.L[330]*work1d.d[587]*1;
  residual += temp*temp;
  temp = work1d.KKT[1172]-1*work1d.d[588]*work1d.L[1461];
  residual += temp*temp;
  temp = work1d.KKT[1170]-work1d.L[332]*work1d.d[587]*1;
  residual += temp*temp;
  temp = work1d.KKT[1174]-1*work1d.d[589]*work1d.L[1462]-work1d.L[333]*work1d.d[588]*work1d.L[1461];
  residual += temp*temp;
  temp = work1d.KKT[1176]-1*work1d.d[590]*work1d.L[335];
  residual += temp*temp;
  temp = work1d.KKT[1177]-work1d.L[337]*work1d.d[591]*1;
  residual += temp*temp;
  temp = work1d.KKT[1180]-1*work1d.d[592]*work1d.L[1483];
  residual += temp*temp;
  temp = work1d.KKT[1178]-work1d.L[339]*work1d.d[591]*1;
  residual += temp*temp;
  temp = work1d.KKT[1182]-1*work1d.d[593]*work1d.L[1484]-work1d.L[340]*work1d.d[592]*work1d.L[1483];
  residual += temp*temp;
  temp = work1d.KKT[1184]-1*work1d.d[594]*work1d.L[342];
  residual += temp*temp;
  temp = work1d.KKT[1185]-work1d.L[344]*work1d.d[595]*1;
  residual += temp*temp;
  temp = work1d.KKT[1188]-1*work1d.d[596]*work1d.L[1509];
  residual += temp*temp;
  temp = work1d.KKT[1186]-work1d.L[346]*work1d.d[595]*1;
  residual += temp*temp;
  temp = work1d.KKT[1190]-1*work1d.d[597]*work1d.L[1510]-work1d.L[347]*work1d.d[596]*work1d.L[1509];
  residual += temp*temp;
  temp = work1d.KKT[1192]-1*work1d.d[598]*work1d.L[349];
  residual += temp*temp;
  temp = work1d.KKT[1193]-work1d.L[351]*work1d.d[599]*1;
  residual += temp*temp;
  temp = work1d.KKT[1196]-1*work1d.d[600]*work1d.L[1527];
  residual += temp*temp;
  temp = work1d.KKT[1194]-work1d.L[353]*work1d.d[599]*1;
  residual += temp*temp;
  temp = work1d.KKT[1198]-1*work1d.d[601]*work1d.L[1528]-work1d.L[354]*work1d.d[600]*work1d.L[1527];
  residual += temp*temp;
  temp = work1d.KKT[1200]-1*work1d.d[602]*work1d.L[356];
  residual += temp*temp;
  temp = work1d.KKT[1201]-work1d.L[358]*work1d.d[603]*1;
  residual += temp*temp;
  temp = work1d.KKT[1204]-1*work1d.d[604]*work1d.L[363];
  residual += temp*temp;
  temp = work1d.KKT[1202]-work1d.L[360]*work1d.d[603]*1;
  residual += temp*temp;
  temp = work1d.KKT[1206]-1*work1d.d[605]*work1d.L[364]-work1d.L[361]*work1d.d[604]*work1d.L[363];
  residual += temp*temp;
  temp = work1d.KKT[1210]-1*work1d.d[607]*work1d.L[366];
  residual += temp*temp;
  temp = work1d.KKT[1211]-work1d.L[368]*work1d.d[608]*1;
  residual += temp*temp;
  temp = work1d.KKT[1214]-1*work1d.d[609]*work1d.L[705];
  residual += temp*temp;
  temp = work1d.KKT[1212]-work1d.L[370]*work1d.d[608]*1;
  residual += temp*temp;
  temp = work1d.KKT[1216]-1*work1d.d[610]*work1d.L[706]-work1d.L[371]*work1d.d[609]*work1d.L[705];
  residual += temp*temp;
  temp = work1d.KKT[1218]-1*work1d.d[611]*work1d.L[373];
  residual += temp*temp;
  temp = work1d.KKT[1219]-work1d.L[375]*work1d.d[612]*1;
  residual += temp*temp;
  temp = work1d.KKT[1222]-1*work1d.d[613]*work1d.L[719];
  residual += temp*temp;
  temp = work1d.KKT[1220]-work1d.L[377]*work1d.d[612]*1;
  residual += temp*temp;
  temp = work1d.KKT[1224]-1*work1d.d[614]*work1d.L[720]-work1d.L[378]*work1d.d[613]*work1d.L[719];
  residual += temp*temp;
  temp = work1d.KKT[1226]-1*work1d.d[615]*work1d.L[380];
  residual += temp*temp;
  temp = work1d.KKT[1227]-work1d.L[382]*work1d.d[616]*1;
  residual += temp*temp;
  temp = work1d.KKT[1230]-1*work1d.d[617]*work1d.L[739];
  residual += temp*temp;
  temp = work1d.KKT[1228]-work1d.L[384]*work1d.d[616]*1;
  residual += temp*temp;
  temp = work1d.KKT[1232]-1*work1d.d[618]*work1d.L[740]-work1d.L[385]*work1d.d[617]*work1d.L[739];
  residual += temp*temp;
  temp = work1d.KKT[1234]-1*work1d.d[619]*work1d.L[387];
  residual += temp*temp;
  temp = work1d.KKT[1235]-work1d.L[389]*work1d.d[620]*1;
  residual += temp*temp;
  temp = work1d.KKT[1238]-1*work1d.d[621]*work1d.L[761];
  residual += temp*temp;
  temp = work1d.KKT[1236]-work1d.L[391]*work1d.d[620]*1;
  residual += temp*temp;
  temp = work1d.KKT[1240]-1*work1d.d[622]*work1d.L[762]-work1d.L[392]*work1d.d[621]*work1d.L[761];
  residual += temp*temp;
  temp = work1d.KKT[1242]-1*work1d.d[623]*work1d.L[394];
  residual += temp*temp;
  temp = work1d.KKT[1243]-work1d.L[396]*work1d.d[624]*1;
  residual += temp*temp;
  temp = work1d.KKT[1246]-1*work1d.d[625]*work1d.L[783];
  residual += temp*temp;
  temp = work1d.KKT[1244]-work1d.L[398]*work1d.d[624]*1;
  residual += temp*temp;
  temp = work1d.KKT[1248]-1*work1d.d[626]*work1d.L[784]-work1d.L[399]*work1d.d[625]*work1d.L[783];
  residual += temp*temp;
  temp = work1d.KKT[1250]-1*work1d.d[627]*work1d.L[401];
  residual += temp*temp;
  temp = work1d.KKT[1251]-work1d.L[403]*work1d.d[628]*1;
  residual += temp*temp;
  temp = work1d.KKT[1254]-1*work1d.d[629]*work1d.L[805];
  residual += temp*temp;
  temp = work1d.KKT[1252]-work1d.L[405]*work1d.d[628]*1;
  residual += temp*temp;
  temp = work1d.KKT[1256]-1*work1d.d[630]*work1d.L[806]-work1d.L[406]*work1d.d[629]*work1d.L[805];
  residual += temp*temp;
  temp = work1d.KKT[1258]-1*work1d.d[631]*work1d.L[408];
  residual += temp*temp;
  temp = work1d.KKT[1259]-work1d.L[410]*work1d.d[632]*1;
  residual += temp*temp;
  temp = work1d.KKT[1262]-1*work1d.d[633]*work1d.L[827];
  residual += temp*temp;
  temp = work1d.KKT[1260]-work1d.L[412]*work1d.d[632]*1;
  residual += temp*temp;
  temp = work1d.KKT[1264]-1*work1d.d[634]*work1d.L[828]-work1d.L[413]*work1d.d[633]*work1d.L[827];
  residual += temp*temp;
  temp = work1d.KKT[1266]-1*work1d.d[635]*work1d.L[415];
  residual += temp*temp;
  temp = work1d.KKT[1267]-work1d.L[417]*work1d.d[636]*1;
  residual += temp*temp;
  temp = work1d.KKT[1270]-1*work1d.d[637]*work1d.L[849];
  residual += temp*temp;
  temp = work1d.KKT[1268]-work1d.L[419]*work1d.d[636]*1;
  residual += temp*temp;
  temp = work1d.KKT[1272]-1*work1d.d[638]*work1d.L[850]-work1d.L[420]*work1d.d[637]*work1d.L[849];
  residual += temp*temp;
  temp = work1d.KKT[1274]-1*work1d.d[639]*work1d.L[422];
  residual += temp*temp;
  temp = work1d.KKT[1275]-work1d.L[424]*work1d.d[640]*1;
  residual += temp*temp;
  temp = work1d.KKT[1278]-1*work1d.d[641]*work1d.L[871];
  residual += temp*temp;
  temp = work1d.KKT[1276]-work1d.L[426]*work1d.d[640]*1;
  residual += temp*temp;
  temp = work1d.KKT[1280]-1*work1d.d[642]*work1d.L[872]-work1d.L[427]*work1d.d[641]*work1d.L[871];
  residual += temp*temp;
  temp = work1d.KKT[1282]-1*work1d.d[643]*work1d.L[429];
  residual += temp*temp;
  temp = work1d.KKT[1283]-work1d.L[431]*work1d.d[644]*1;
  residual += temp*temp;
  temp = work1d.KKT[1286]-1*work1d.d[645]*work1d.L[893];
  residual += temp*temp;
  temp = work1d.KKT[1284]-work1d.L[433]*work1d.d[644]*1;
  residual += temp*temp;
  temp = work1d.KKT[1288]-1*work1d.d[646]*work1d.L[894]-work1d.L[434]*work1d.d[645]*work1d.L[893];
  residual += temp*temp;
  temp = work1d.KKT[1290]-1*work1d.d[647]*work1d.L[436];
  residual += temp*temp;
  temp = work1d.KKT[1291]-work1d.L[438]*work1d.d[648]*1;
  residual += temp*temp;
  temp = work1d.KKT[1294]-1*work1d.d[649]*work1d.L[915];
  residual += temp*temp;
  temp = work1d.KKT[1292]-work1d.L[440]*work1d.d[648]*1;
  residual += temp*temp;
  temp = work1d.KKT[1296]-1*work1d.d[650]*work1d.L[916]-work1d.L[441]*work1d.d[649]*work1d.L[915];
  residual += temp*temp;
  temp = work1d.KKT[1298]-1*work1d.d[651]*work1d.L[443];
  residual += temp*temp;
  temp = work1d.KKT[1299]-work1d.L[445]*work1d.d[652]*1;
  residual += temp*temp;
  temp = work1d.KKT[1302]-1*work1d.d[653]*work1d.L[937];
  residual += temp*temp;
  temp = work1d.KKT[1300]-work1d.L[447]*work1d.d[652]*1;
  residual += temp*temp;
  temp = work1d.KKT[1304]-1*work1d.d[654]*work1d.L[938]-work1d.L[448]*work1d.d[653]*work1d.L[937];
  residual += temp*temp;
  temp = work1d.KKT[1306]-1*work1d.d[655]*work1d.L[450];
  residual += temp*temp;
  temp = work1d.KKT[1307]-work1d.L[452]*work1d.d[656]*1;
  residual += temp*temp;
  temp = work1d.KKT[1310]-1*work1d.d[657]*work1d.L[959];
  residual += temp*temp;
  temp = work1d.KKT[1308]-work1d.L[454]*work1d.d[656]*1;
  residual += temp*temp;
  temp = work1d.KKT[1312]-1*work1d.d[658]*work1d.L[960]-work1d.L[455]*work1d.d[657]*work1d.L[959];
  residual += temp*temp;
  temp = work1d.KKT[1314]-1*work1d.d[659]*work1d.L[457];
  residual += temp*temp;
  temp = work1d.KKT[1315]-work1d.L[459]*work1d.d[660]*1;
  residual += temp*temp;
  temp = work1d.KKT[1318]-1*work1d.d[661]*work1d.L[981];
  residual += temp*temp;
  temp = work1d.KKT[1316]-work1d.L[461]*work1d.d[660]*1;
  residual += temp*temp;
  temp = work1d.KKT[1320]-1*work1d.d[662]*work1d.L[982]-work1d.L[462]*work1d.d[661]*work1d.L[981];
  residual += temp*temp;
  temp = work1d.KKT[1322]-1*work1d.d[663]*work1d.L[464];
  residual += temp*temp;
  temp = work1d.KKT[1323]-work1d.L[466]*work1d.d[664]*1;
  residual += temp*temp;
  temp = work1d.KKT[1326]-1*work1d.d[665]*work1d.L[1003];
  residual += temp*temp;
  temp = work1d.KKT[1324]-work1d.L[468]*work1d.d[664]*1;
  residual += temp*temp;
  temp = work1d.KKT[1328]-1*work1d.d[666]*work1d.L[1004]-work1d.L[469]*work1d.d[665]*work1d.L[1003];
  residual += temp*temp;
  temp = work1d.KKT[1330]-1*work1d.d[667]*work1d.L[471];
  residual += temp*temp;
  temp = work1d.KKT[1331]-work1d.L[473]*work1d.d[668]*1;
  residual += temp*temp;
  temp = work1d.KKT[1334]-1*work1d.d[669]*work1d.L[1025];
  residual += temp*temp;
  temp = work1d.KKT[1332]-work1d.L[475]*work1d.d[668]*1;
  residual += temp*temp;
  temp = work1d.KKT[1336]-1*work1d.d[670]*work1d.L[1026]-work1d.L[476]*work1d.d[669]*work1d.L[1025];
  residual += temp*temp;
  temp = work1d.KKT[1338]-1*work1d.d[671]*work1d.L[478];
  residual += temp*temp;
  temp = work1d.KKT[1339]-work1d.L[480]*work1d.d[672]*1;
  residual += temp*temp;
  temp = work1d.KKT[1342]-1*work1d.d[673]*work1d.L[1047];
  residual += temp*temp;
  temp = work1d.KKT[1340]-work1d.L[482]*work1d.d[672]*1;
  residual += temp*temp;
  temp = work1d.KKT[1344]-1*work1d.d[674]*work1d.L[1048]-work1d.L[483]*work1d.d[673]*work1d.L[1047];
  residual += temp*temp;
  temp = work1d.KKT[1346]-1*work1d.d[675]*work1d.L[485];
  residual += temp*temp;
  temp = work1d.KKT[1347]-work1d.L[487]*work1d.d[676]*1;
  residual += temp*temp;
  temp = work1d.KKT[1350]-1*work1d.d[677]*work1d.L[1069];
  residual += temp*temp;
  temp = work1d.KKT[1348]-work1d.L[489]*work1d.d[676]*1;
  residual += temp*temp;
  temp = work1d.KKT[1352]-1*work1d.d[678]*work1d.L[1070]-work1d.L[490]*work1d.d[677]*work1d.L[1069];
  residual += temp*temp;
  temp = work1d.KKT[1354]-1*work1d.d[679]*work1d.L[492];
  residual += temp*temp;
  temp = work1d.KKT[1355]-work1d.L[494]*work1d.d[680]*1;
  residual += temp*temp;
  temp = work1d.KKT[1358]-1*work1d.d[681]*work1d.L[1091];
  residual += temp*temp;
  temp = work1d.KKT[1356]-work1d.L[496]*work1d.d[680]*1;
  residual += temp*temp;
  temp = work1d.KKT[1360]-1*work1d.d[682]*work1d.L[1092]-work1d.L[497]*work1d.d[681]*work1d.L[1091];
  residual += temp*temp;
  temp = work1d.KKT[1362]-1*work1d.d[683]*work1d.L[499];
  residual += temp*temp;
  temp = work1d.KKT[1363]-work1d.L[501]*work1d.d[684]*1;
  residual += temp*temp;
  temp = work1d.KKT[1366]-1*work1d.d[685]*work1d.L[1113];
  residual += temp*temp;
  temp = work1d.KKT[1364]-work1d.L[503]*work1d.d[684]*1;
  residual += temp*temp;
  temp = work1d.KKT[1368]-1*work1d.d[686]*work1d.L[1114]-work1d.L[504]*work1d.d[685]*work1d.L[1113];
  residual += temp*temp;
  temp = work1d.KKT[1370]-1*work1d.d[687]*work1d.L[506];
  residual += temp*temp;
  temp = work1d.KKT[1371]-work1d.L[508]*work1d.d[688]*1;
  residual += temp*temp;
  temp = work1d.KKT[1374]-1*work1d.d[689]*work1d.L[1135];
  residual += temp*temp;
  temp = work1d.KKT[1372]-work1d.L[510]*work1d.d[688]*1;
  residual += temp*temp;
  temp = work1d.KKT[1376]-1*work1d.d[690]*work1d.L[1136]-work1d.L[511]*work1d.d[689]*work1d.L[1135];
  residual += temp*temp;
  temp = work1d.KKT[1378]-1*work1d.d[691]*work1d.L[513];
  residual += temp*temp;
  temp = work1d.KKT[1379]-work1d.L[515]*work1d.d[692]*1;
  residual += temp*temp;
  temp = work1d.KKT[1382]-1*work1d.d[693]*work1d.L[1157];
  residual += temp*temp;
  temp = work1d.KKT[1380]-work1d.L[517]*work1d.d[692]*1;
  residual += temp*temp;
  temp = work1d.KKT[1384]-1*work1d.d[694]*work1d.L[1158]-work1d.L[518]*work1d.d[693]*work1d.L[1157];
  residual += temp*temp;
  temp = work1d.KKT[1386]-1*work1d.d[695]*work1d.L[520];
  residual += temp*temp;
  temp = work1d.KKT[1387]-work1d.L[522]*work1d.d[696]*1;
  residual += temp*temp;
  temp = work1d.KKT[1390]-1*work1d.d[697]*work1d.L[1179];
  residual += temp*temp;
  temp = work1d.KKT[1388]-work1d.L[524]*work1d.d[696]*1;
  residual += temp*temp;
  temp = work1d.KKT[1392]-1*work1d.d[698]*work1d.L[1180]-work1d.L[525]*work1d.d[697]*work1d.L[1179];
  residual += temp*temp;
  temp = work1d.KKT[1394]-1*work1d.d[699]*work1d.L[527];
  residual += temp*temp;
  temp = work1d.KKT[1395]-work1d.L[529]*work1d.d[700]*1;
  residual += temp*temp;
  temp = work1d.KKT[1398]-1*work1d.d[701]*work1d.L[1201];
  residual += temp*temp;
  temp = work1d.KKT[1396]-work1d.L[531]*work1d.d[700]*1;
  residual += temp*temp;
  temp = work1d.KKT[1400]-1*work1d.d[702]*work1d.L[1202]-work1d.L[532]*work1d.d[701]*work1d.L[1201];
  residual += temp*temp;
  temp = work1d.KKT[1402]-1*work1d.d[703]*work1d.L[534];
  residual += temp*temp;
  temp = work1d.KKT[1403]-work1d.L[536]*work1d.d[704]*1;
  residual += temp*temp;
  temp = work1d.KKT[1406]-1*work1d.d[705]*work1d.L[1223];
  residual += temp*temp;
  temp = work1d.KKT[1404]-work1d.L[538]*work1d.d[704]*1;
  residual += temp*temp;
  temp = work1d.KKT[1408]-1*work1d.d[706]*work1d.L[1224]-work1d.L[539]*work1d.d[705]*work1d.L[1223];
  residual += temp*temp;
  temp = work1d.KKT[1410]-1*work1d.d[707]*work1d.L[541];
  residual += temp*temp;
  temp = work1d.KKT[1411]-work1d.L[543]*work1d.d[708]*1;
  residual += temp*temp;
  temp = work1d.KKT[1414]-1*work1d.d[709]*work1d.L[1245];
  residual += temp*temp;
  temp = work1d.KKT[1412]-work1d.L[545]*work1d.d[708]*1;
  residual += temp*temp;
  temp = work1d.KKT[1416]-1*work1d.d[710]*work1d.L[1246]-work1d.L[546]*work1d.d[709]*work1d.L[1245];
  residual += temp*temp;
  temp = work1d.KKT[1418]-1*work1d.d[711]*work1d.L[548];
  residual += temp*temp;
  temp = work1d.KKT[1419]-work1d.L[550]*work1d.d[712]*1;
  residual += temp*temp;
  temp = work1d.KKT[1422]-1*work1d.d[713]*work1d.L[1267];
  residual += temp*temp;
  temp = work1d.KKT[1420]-work1d.L[552]*work1d.d[712]*1;
  residual += temp*temp;
  temp = work1d.KKT[1424]-1*work1d.d[714]*work1d.L[1268]-work1d.L[553]*work1d.d[713]*work1d.L[1267];
  residual += temp*temp;
  temp = work1d.KKT[1426]-1*work1d.d[715]*work1d.L[555];
  residual += temp*temp;
  temp = work1d.KKT[1427]-work1d.L[557]*work1d.d[716]*1;
  residual += temp*temp;
  temp = work1d.KKT[1430]-1*work1d.d[717]*work1d.L[1289];
  residual += temp*temp;
  temp = work1d.KKT[1428]-work1d.L[559]*work1d.d[716]*1;
  residual += temp*temp;
  temp = work1d.KKT[1432]-1*work1d.d[718]*work1d.L[1290]-work1d.L[560]*work1d.d[717]*work1d.L[1289];
  residual += temp*temp;
  temp = work1d.KKT[1434]-1*work1d.d[719]*work1d.L[562];
  residual += temp*temp;
  temp = work1d.KKT[1435]-work1d.L[564]*work1d.d[720]*1;
  residual += temp*temp;
  temp = work1d.KKT[1438]-1*work1d.d[721]*work1d.L[1311];
  residual += temp*temp;
  temp = work1d.KKT[1436]-work1d.L[566]*work1d.d[720]*1;
  residual += temp*temp;
  temp = work1d.KKT[1440]-1*work1d.d[722]*work1d.L[1312]-work1d.L[567]*work1d.d[721]*work1d.L[1311];
  residual += temp*temp;
  temp = work1d.KKT[1442]-1*work1d.d[723]*work1d.L[569];
  residual += temp*temp;
  temp = work1d.KKT[1443]-work1d.L[571]*work1d.d[724]*1;
  residual += temp*temp;
  temp = work1d.KKT[1446]-1*work1d.d[725]*work1d.L[1333];
  residual += temp*temp;
  temp = work1d.KKT[1444]-work1d.L[573]*work1d.d[724]*1;
  residual += temp*temp;
  temp = work1d.KKT[1448]-1*work1d.d[726]*work1d.L[1334]-work1d.L[574]*work1d.d[725]*work1d.L[1333];
  residual += temp*temp;
  temp = work1d.KKT[1450]-1*work1d.d[727]*work1d.L[576];
  residual += temp*temp;
  temp = work1d.KKT[1451]-work1d.L[578]*work1d.d[728]*1;
  residual += temp*temp;
  temp = work1d.KKT[1454]-1*work1d.d[729]*work1d.L[1355];
  residual += temp*temp;
  temp = work1d.KKT[1452]-work1d.L[580]*work1d.d[728]*1;
  residual += temp*temp;
  temp = work1d.KKT[1456]-1*work1d.d[730]*work1d.L[1356]-work1d.L[581]*work1d.d[729]*work1d.L[1355];
  residual += temp*temp;
  temp = work1d.KKT[1458]-1*work1d.d[731]*work1d.L[583];
  residual += temp*temp;
  temp = work1d.KKT[1459]-work1d.L[585]*work1d.d[732]*1;
  residual += temp*temp;
  temp = work1d.KKT[1462]-1*work1d.d[733]*work1d.L[1377];
  residual += temp*temp;
  temp = work1d.KKT[1460]-work1d.L[587]*work1d.d[732]*1;
  residual += temp*temp;
  temp = work1d.KKT[1464]-1*work1d.d[734]*work1d.L[1378]-work1d.L[588]*work1d.d[733]*work1d.L[1377];
  residual += temp*temp;
  temp = work1d.KKT[1466]-1*work1d.d[735]*work1d.L[590];
  residual += temp*temp;
  temp = work1d.KKT[1467]-work1d.L[592]*work1d.d[736]*1;
  residual += temp*temp;
  temp = work1d.KKT[1470]-1*work1d.d[737]*work1d.L[1399];
  residual += temp*temp;
  temp = work1d.KKT[1468]-work1d.L[594]*work1d.d[736]*1;
  residual += temp*temp;
  temp = work1d.KKT[1472]-1*work1d.d[738]*work1d.L[1400]-work1d.L[595]*work1d.d[737]*work1d.L[1399];
  residual += temp*temp;
  temp = work1d.KKT[1474]-1*work1d.d[739]*work1d.L[597];
  residual += temp*temp;
  temp = work1d.KKT[1475]-work1d.L[599]*work1d.d[740]*1;
  residual += temp*temp;
  temp = work1d.KKT[1478]-1*work1d.d[741]*work1d.L[1421];
  residual += temp*temp;
  temp = work1d.KKT[1476]-work1d.L[601]*work1d.d[740]*1;
  residual += temp*temp;
  temp = work1d.KKT[1480]-1*work1d.d[742]*work1d.L[1422]-work1d.L[602]*work1d.d[741]*work1d.L[1421];
  residual += temp*temp;
  temp = work1d.KKT[1482]-1*work1d.d[743]*work1d.L[604];
  residual += temp*temp;
  temp = work1d.KKT[1483]-work1d.L[606]*work1d.d[744]*1;
  residual += temp*temp;
  temp = work1d.KKT[1486]-1*work1d.d[745]*work1d.L[1443];
  residual += temp*temp;
  temp = work1d.KKT[1484]-work1d.L[608]*work1d.d[744]*1;
  residual += temp*temp;
  temp = work1d.KKT[1488]-1*work1d.d[746]*work1d.L[1444]-work1d.L[609]*work1d.d[745]*work1d.L[1443];
  residual += temp*temp;
  temp = work1d.KKT[1490]-1*work1d.d[747]*work1d.L[611];
  residual += temp*temp;
  temp = work1d.KKT[1491]-work1d.L[613]*work1d.d[748]*1;
  residual += temp*temp;
  temp = work1d.KKT[1494]-1*work1d.d[749]*work1d.L[1465];
  residual += temp*temp;
  temp = work1d.KKT[1492]-work1d.L[615]*work1d.d[748]*1;
  residual += temp*temp;
  temp = work1d.KKT[1496]-1*work1d.d[750]*work1d.L[1466]-work1d.L[616]*work1d.d[749]*work1d.L[1465];
  residual += temp*temp;
  temp = work1d.KKT[1498]-1*work1d.d[751]*work1d.L[618];
  residual += temp*temp;
  temp = work1d.KKT[1499]-work1d.L[620]*work1d.d[752]*1;
  residual += temp*temp;
  temp = work1d.KKT[1502]-1*work1d.d[753]*work1d.L[1487];
  residual += temp*temp;
  temp = work1d.KKT[1500]-work1d.L[622]*work1d.d[752]*1;
  residual += temp*temp;
  temp = work1d.KKT[1504]-1*work1d.d[754]*work1d.L[1488]-work1d.L[623]*work1d.d[753]*work1d.L[1487];
  residual += temp*temp;
  temp = work1d.KKT[1506]-1*work1d.d[755]*work1d.L[625];
  residual += temp*temp;
  temp = work1d.KKT[1507]-work1d.L[627]*work1d.d[756]*1;
  residual += temp*temp;
  temp = work1d.KKT[1510]-1*work1d.d[757]*work1d.L[1515];
  residual += temp*temp;
  temp = work1d.KKT[1508]-work1d.L[629]*work1d.d[756]*1;
  residual += temp*temp;
  temp = work1d.KKT[1512]-1*work1d.d[758]*work1d.L[1516]-work1d.L[630]*work1d.d[757]*work1d.L[1515];
  residual += temp*temp;
  temp = work1d.KKT[1514]-1*work1d.d[759]*work1d.L[632];
  residual += temp*temp;
  temp = work1d.KKT[1515]-work1d.L[634]*work1d.d[760]*1;
  residual += temp*temp;
  temp = work1d.KKT[1518]-1*work1d.d[761]*work1d.L[651];
  residual += temp*temp;
  temp = work1d.KKT[1516]-work1d.L[636]*work1d.d[760]*1;
  residual += temp*temp;
  temp = work1d.KKT[1520]-1*work1d.d[762]*work1d.L[652]-work1d.L[637]*work1d.d[761]*work1d.L[651];
  residual += temp*temp;
  temp = work1d.KKT[1522]-1*work1d.d[763]*work1d.L[639];
  residual += temp*temp;
  temp = work1d.KKT[1523]-work1d.L[641]*work1d.d[764]*1;
  residual += temp*temp;
  temp = work1d.KKT[1526]-1*work1d.d[765]*work1d.L[646];
  residual += temp*temp;
  temp = work1d.KKT[1524]-work1d.L[643]*work1d.d[764]*1;
  residual += temp*temp;
  temp = work1d.KKT[1528]-1*work1d.d[766]*work1d.L[647]-work1d.L[644]*work1d.d[765]*work1d.L[646];
  residual += temp*temp;
  temp = work1d.KKT[642]-1*work1d.d[321]*work1d.L[698];
  residual += temp*temp;
  temp = work1d.KKT[644]-1*work1d.d[322]*work1d.L[714];
  residual += temp*temp;
  temp = work1d.KKT[646]-1*work1d.d[323]*work1d.L[734];
  residual += temp*temp;
  temp = work1d.KKT[648]-1*work1d.d[324]*work1d.L[756];
  residual += temp*temp;
  temp = work1d.KKT[650]-1*work1d.d[325]*work1d.L[778];
  residual += temp*temp;
  temp = work1d.KKT[652]-1*work1d.d[326]*work1d.L[800];
  residual += temp*temp;
  temp = work1d.KKT[654]-1*work1d.d[327]*work1d.L[822];
  residual += temp*temp;
  temp = work1d.KKT[656]-1*work1d.d[328]*work1d.L[844];
  residual += temp*temp;
  temp = work1d.KKT[658]-1*work1d.d[329]*work1d.L[866];
  residual += temp*temp;
  temp = work1d.KKT[660]-1*work1d.d[330]*work1d.L[888];
  residual += temp*temp;
  temp = work1d.KKT[662]-1*work1d.d[331]*work1d.L[910];
  residual += temp*temp;
  temp = work1d.KKT[664]-1*work1d.d[332]*work1d.L[932];
  residual += temp*temp;
  temp = work1d.KKT[666]-1*work1d.d[333]*work1d.L[954];
  residual += temp*temp;
  temp = work1d.KKT[668]-1*work1d.d[334]*work1d.L[976];
  residual += temp*temp;
  temp = work1d.KKT[670]-1*work1d.d[335]*work1d.L[998];
  residual += temp*temp;
  temp = work1d.KKT[672]-1*work1d.d[336]*work1d.L[1020];
  residual += temp*temp;
  temp = work1d.KKT[674]-1*work1d.d[337]*work1d.L[1042];
  residual += temp*temp;
  temp = work1d.KKT[676]-1*work1d.d[338]*work1d.L[1064];
  residual += temp*temp;
  temp = work1d.KKT[678]-1*work1d.d[339]*work1d.L[1086];
  residual += temp*temp;
  temp = work1d.KKT[680]-1*work1d.d[340]*work1d.L[1108];
  residual += temp*temp;
  temp = work1d.KKT[682]-1*work1d.d[341]*work1d.L[1130];
  residual += temp*temp;
  temp = work1d.KKT[684]-1*work1d.d[342]*work1d.L[1152];
  residual += temp*temp;
  temp = work1d.KKT[686]-1*work1d.d[343]*work1d.L[1174];
  residual += temp*temp;
  temp = work1d.KKT[688]-1*work1d.d[344]*work1d.L[1196];
  residual += temp*temp;
  temp = work1d.KKT[690]-1*work1d.d[345]*work1d.L[1218];
  residual += temp*temp;
  temp = work1d.KKT[692]-1*work1d.d[346]*work1d.L[1240];
  residual += temp*temp;
  temp = work1d.KKT[694]-1*work1d.d[347]*work1d.L[1262];
  residual += temp*temp;
  temp = work1d.KKT[696]-1*work1d.d[348]*work1d.L[1284];
  residual += temp*temp;
  temp = work1d.KKT[698]-1*work1d.d[349]*work1d.L[1306];
  residual += temp*temp;
  temp = work1d.KKT[700]-1*work1d.d[350]*work1d.L[1328];
  residual += temp*temp;
  temp = work1d.KKT[702]-1*work1d.d[351]*work1d.L[1350];
  residual += temp*temp;
  temp = work1d.KKT[704]-1*work1d.d[352]*work1d.L[1372];
  residual += temp*temp;
  temp = work1d.KKT[706]-1*work1d.d[353]*work1d.L[1394];
  residual += temp*temp;
  temp = work1d.KKT[708]-1*work1d.d[354]*work1d.L[1416];
  residual += temp*temp;
  temp = work1d.KKT[710]-1*work1d.d[355]*work1d.L[1438];
  residual += temp*temp;
  temp = work1d.KKT[712]-1*work1d.d[356]*work1d.L[1460];
  residual += temp*temp;
  temp = work1d.KKT[714]-1*work1d.d[357]*work1d.L[1482];
  residual += temp*temp;
  temp = work1d.KKT[716]-1*work1d.d[358]*work1d.L[1508];
  residual += temp*temp;
  temp = work1d.KKT[718]-1*work1d.d[359]*work1d.L[1526];
  residual += temp*temp;
  temp = work1d.KKT[720]-1*work1d.d[360]*work1d.L[362];
  residual += temp*temp;
  temp = work1d.KKT[722]-1*work1d.d[361]*work1d.L[703];
  residual += temp*temp;
  temp = work1d.KKT[724]-1*work1d.d[362]*work1d.L[718];
  residual += temp*temp;
  temp = work1d.KKT[726]-1*work1d.d[363]*work1d.L[738];
  residual += temp*temp;
  temp = work1d.KKT[728]-1*work1d.d[364]*work1d.L[760];
  residual += temp*temp;
  temp = work1d.KKT[730]-1*work1d.d[365]*work1d.L[782];
  residual += temp*temp;
  temp = work1d.KKT[732]-1*work1d.d[366]*work1d.L[804];
  residual += temp*temp;
  temp = work1d.KKT[734]-1*work1d.d[367]*work1d.L[826];
  residual += temp*temp;
  temp = work1d.KKT[736]-1*work1d.d[368]*work1d.L[848];
  residual += temp*temp;
  temp = work1d.KKT[738]-1*work1d.d[369]*work1d.L[870];
  residual += temp*temp;
  temp = work1d.KKT[740]-1*work1d.d[370]*work1d.L[892];
  residual += temp*temp;
  temp = work1d.KKT[742]-1*work1d.d[371]*work1d.L[914];
  residual += temp*temp;
  temp = work1d.KKT[744]-1*work1d.d[372]*work1d.L[936];
  residual += temp*temp;
  temp = work1d.KKT[746]-1*work1d.d[373]*work1d.L[958];
  residual += temp*temp;
  temp = work1d.KKT[748]-1*work1d.d[374]*work1d.L[980];
  residual += temp*temp;
  temp = work1d.KKT[750]-1*work1d.d[375]*work1d.L[1002];
  residual += temp*temp;
  temp = work1d.KKT[752]-1*work1d.d[376]*work1d.L[1024];
  residual += temp*temp;
  temp = work1d.KKT[754]-1*work1d.d[377]*work1d.L[1046];
  residual += temp*temp;
  temp = work1d.KKT[756]-1*work1d.d[378]*work1d.L[1068];
  residual += temp*temp;
  temp = work1d.KKT[758]-1*work1d.d[379]*work1d.L[1090];
  residual += temp*temp;
  temp = work1d.KKT[760]-1*work1d.d[380]*work1d.L[1112];
  residual += temp*temp;
  temp = work1d.KKT[762]-1*work1d.d[381]*work1d.L[1134];
  residual += temp*temp;
  temp = work1d.KKT[764]-1*work1d.d[382]*work1d.L[1156];
  residual += temp*temp;
  temp = work1d.KKT[766]-1*work1d.d[383]*work1d.L[1178];
  residual += temp*temp;
  temp = work1d.KKT[768]-1*work1d.d[384]*work1d.L[1200];
  residual += temp*temp;
  temp = work1d.KKT[770]-1*work1d.d[385]*work1d.L[1222];
  residual += temp*temp;
  temp = work1d.KKT[772]-1*work1d.d[386]*work1d.L[1244];
  residual += temp*temp;
  temp = work1d.KKT[774]-1*work1d.d[387]*work1d.L[1266];
  residual += temp*temp;
  temp = work1d.KKT[776]-1*work1d.d[388]*work1d.L[1288];
  residual += temp*temp;
  temp = work1d.KKT[778]-1*work1d.d[389]*work1d.L[1310];
  residual += temp*temp;
  temp = work1d.KKT[780]-1*work1d.d[390]*work1d.L[1332];
  residual += temp*temp;
  temp = work1d.KKT[782]-1*work1d.d[391]*work1d.L[1354];
  residual += temp*temp;
  temp = work1d.KKT[784]-1*work1d.d[392]*work1d.L[1376];
  residual += temp*temp;
  temp = work1d.KKT[786]-1*work1d.d[393]*work1d.L[1398];
  residual += temp*temp;
  temp = work1d.KKT[788]-1*work1d.d[394]*work1d.L[1420];
  residual += temp*temp;
  temp = work1d.KKT[790]-1*work1d.d[395]*work1d.L[1442];
  residual += temp*temp;
  temp = work1d.KKT[792]-1*work1d.d[396]*work1d.L[1464];
  residual += temp*temp;
  temp = work1d.KKT[794]-1*work1d.d[397]*work1d.L[1486];
  residual += temp*temp;
  temp = work1d.KKT[796]-1*work1d.d[398]*work1d.L[1514];
  residual += temp*temp;
  temp = work1d.KKT[798]-1*work1d.d[399]*work1d.L[650];
  residual += temp*temp;
  temp = work1d.KKT[800]-1*work1d.d[400]*work1d.L[645];
  residual += temp*temp;
  temp = work1d.KKT[803]-work1d.L[80]*work1d.d[403]*1;
  residual += temp*temp;
  temp = work1d.KKT[801]-1*work1d.d[401]*work1d.L[81];
  residual += temp*temp;
  temp = work1d.KKT[802]-1*work1d.d[402]*work1d.L[699];
  residual += temp*temp;
  temp = work1d.KKT[804]-1*work1d.d[404]*work1d.L[704];
  residual += temp*temp;
  temp = work1d.KKT[806]-work1d.L[655]*work1d.d[405]*1;
  residual += temp*temp;
  temp = work1d.KKT[884]-work1d.L[654]*work1d.d[444]*1;
  residual += temp*temp;
  temp = work1d.KKT[1616]-work1d.L[711]*work1d.d[811]*1;
  residual += temp*temp;
  temp = work1d.KKT[1537]-1*work1d.d[771]*work1d.L[707];
  residual += temp*temp;
  temp = work1d.KKT[1535]-1*work1d.d[770]*work1d.L[702];
  residual += temp*temp;
  temp = work1d.KKT[1618]-work1d.L[712]*work1d.d[812]*1;
  residual += temp*temp;
  temp = work1d.KKT[1536]-1*work1d.d[770]*work1d.L[708];
  residual += temp*temp;
  temp = work1d.KKT[1731]-1*work1d.d[851]*work1d.L[717];
  residual += temp*temp;
  temp = work1d.KKT[1538]-1*work1d.d[771]*work1d.L[721];
  residual += temp*temp;
  temp = work1d.KKT[808]-work1d.L[656]*work1d.d[406]*1;
  residual += temp*temp;
  temp = work1d.KKT[1620]-work1d.L[726]*work1d.d[813]*1;
  residual += temp*temp;
  temp = work1d.KKT[1734]-work1d.L[731]*work1d.d[852]*1;
  residual += temp*temp;
  temp = work1d.KKT[1539]-1*work1d.d[772]*work1d.L[722];
  residual += temp*temp;
  temp = work1d.KKT[1733]-work1d.L[729]*work1d.d[852]*1-work1d.L[728]*work1d.d[851]*work1d.L[717];
  residual += temp*temp;
  temp = work1d.KKT[1736]-work1d.L[731]*work1d.d[852]*work1d.L[725]-work1d.L[732]*work1d.d[853]*1;
  residual += temp*temp;
  temp = work1d.KKT[1622]-work1d.L[727]*work1d.d[814]*1;
  residual += temp*temp;
  temp = work1d.KKT[1737]-1*work1d.d[855]*work1d.L[737];
  residual += temp*temp;
  temp = work1d.KKT[1540]-1*work1d.d[772]*work1d.L[741];
  residual += temp*temp;
  temp = work1d.KKT[810]-work1d.L[657]*work1d.d[407]*1;
  residual += temp*temp;
  temp = work1d.KKT[1623]-work1d.L[747]*work1d.d[814]*1;
  residual += temp*temp;
  temp = work1d.KKT[1740]-work1d.L[753]*work1d.d[856]*1;
  residual += temp*temp;
  temp = work1d.KKT[1541]-1*work1d.d[773]*work1d.L[742];
  residual += temp*temp;
  temp = work1d.KKT[1739]-work1d.L[751]*work1d.d[856]*1-work1d.L[750]*work1d.d[855]*work1d.L[737];
  residual += temp*temp;
  temp = work1d.KKT[1742]-work1d.L[753]*work1d.d[856]*work1d.L[746]-work1d.L[754]*work1d.d[857]*1;
  residual += temp*temp;
  temp = work1d.KKT[1625]-work1d.L[748]*work1d.d[815]*1;
  residual += temp*temp;
  temp = work1d.KKT[1743]-1*work1d.d[859]*work1d.L[759];
  residual += temp*temp;
  temp = work1d.KKT[1542]-1*work1d.d[773]*work1d.L[763];
  residual += temp*temp;
  temp = work1d.KKT[812]-work1d.L[658]*work1d.d[408]*1;
  residual += temp*temp;
  temp = work1d.KKT[1626]-work1d.L[769]*work1d.d[815]*1;
  residual += temp*temp;
  temp = work1d.KKT[1746]-work1d.L[775]*work1d.d[860]*1;
  residual += temp*temp;
  temp = work1d.KKT[1543]-1*work1d.d[774]*work1d.L[764];
  residual += temp*temp;
  temp = work1d.KKT[1745]-work1d.L[773]*work1d.d[860]*1-work1d.L[772]*work1d.d[859]*work1d.L[759];
  residual += temp*temp;
  temp = work1d.KKT[1748]-work1d.L[775]*work1d.d[860]*work1d.L[768]-work1d.L[776]*work1d.d[861]*1;
  residual += temp*temp;
  temp = work1d.KKT[1628]-work1d.L[770]*work1d.d[816]*1;
  residual += temp*temp;
  temp = work1d.KKT[1749]-1*work1d.d[863]*work1d.L[781];
  residual += temp*temp;
  temp = work1d.KKT[1544]-1*work1d.d[774]*work1d.L[785];
  residual += temp*temp;
  temp = work1d.KKT[814]-work1d.L[659]*work1d.d[409]*1;
  residual += temp*temp;
  temp = work1d.KKT[1629]-work1d.L[791]*work1d.d[816]*1;
  residual += temp*temp;
  temp = work1d.KKT[1752]-work1d.L[797]*work1d.d[864]*1;
  residual += temp*temp;
  temp = work1d.KKT[1545]-1*work1d.d[775]*work1d.L[786];
  residual += temp*temp;
  temp = work1d.KKT[1751]-work1d.L[795]*work1d.d[864]*1-work1d.L[794]*work1d.d[863]*work1d.L[781];
  residual += temp*temp;
  temp = work1d.KKT[1754]-work1d.L[797]*work1d.d[864]*work1d.L[790]-work1d.L[798]*work1d.d[865]*1;
  residual += temp*temp;
  temp = work1d.KKT[1631]-work1d.L[792]*work1d.d[817]*1;
  residual += temp*temp;
  temp = work1d.KKT[1755]-1*work1d.d[867]*work1d.L[803];
  residual += temp*temp;
  temp = work1d.KKT[1546]-1*work1d.d[775]*work1d.L[807];
  residual += temp*temp;
  temp = work1d.KKT[816]-work1d.L[660]*work1d.d[410]*1;
  residual += temp*temp;
  temp = work1d.KKT[1632]-work1d.L[813]*work1d.d[817]*1;
  residual += temp*temp;
  temp = work1d.KKT[1758]-work1d.L[819]*work1d.d[868]*1;
  residual += temp*temp;
  temp = work1d.KKT[1547]-1*work1d.d[776]*work1d.L[808];
  residual += temp*temp;
  temp = work1d.KKT[1757]-work1d.L[817]*work1d.d[868]*1-work1d.L[816]*work1d.d[867]*work1d.L[803];
  residual += temp*temp;
  temp = work1d.KKT[1760]-work1d.L[819]*work1d.d[868]*work1d.L[812]-work1d.L[820]*work1d.d[869]*1;
  residual += temp*temp;
  temp = work1d.KKT[1634]-work1d.L[814]*work1d.d[818]*1;
  residual += temp*temp;
  temp = work1d.KKT[1761]-1*work1d.d[871]*work1d.L[825];
  residual += temp*temp;
  temp = work1d.KKT[1548]-1*work1d.d[776]*work1d.L[829];
  residual += temp*temp;
  temp = work1d.KKT[818]-work1d.L[661]*work1d.d[411]*1;
  residual += temp*temp;
  temp = work1d.KKT[1635]-work1d.L[835]*work1d.d[818]*1;
  residual += temp*temp;
  temp = work1d.KKT[1764]-work1d.L[841]*work1d.d[872]*1;
  residual += temp*temp;
  temp = work1d.KKT[1549]-1*work1d.d[777]*work1d.L[830];
  residual += temp*temp;
  temp = work1d.KKT[1763]-work1d.L[839]*work1d.d[872]*1-work1d.L[838]*work1d.d[871]*work1d.L[825];
  residual += temp*temp;
  temp = work1d.KKT[1766]-work1d.L[841]*work1d.d[872]*work1d.L[834]-work1d.L[842]*work1d.d[873]*1;
  residual += temp*temp;
  temp = work1d.KKT[1637]-work1d.L[836]*work1d.d[819]*1;
  residual += temp*temp;
  temp = work1d.KKT[1767]-1*work1d.d[875]*work1d.L[847];
  residual += temp*temp;
  temp = work1d.KKT[1550]-1*work1d.d[777]*work1d.L[851];
  residual += temp*temp;
  temp = work1d.KKT[820]-work1d.L[662]*work1d.d[412]*1;
  residual += temp*temp;
  temp = work1d.KKT[1638]-work1d.L[857]*work1d.d[819]*1;
  residual += temp*temp;
  temp = work1d.KKT[1770]-work1d.L[863]*work1d.d[876]*1;
  residual += temp*temp;
  temp = work1d.KKT[1551]-1*work1d.d[778]*work1d.L[852];
  residual += temp*temp;
  temp = work1d.KKT[1769]-work1d.L[861]*work1d.d[876]*1-work1d.L[860]*work1d.d[875]*work1d.L[847];
  residual += temp*temp;
  temp = work1d.KKT[1772]-work1d.L[863]*work1d.d[876]*work1d.L[856]-work1d.L[864]*work1d.d[877]*1;
  residual += temp*temp;
  temp = work1d.KKT[1640]-work1d.L[858]*work1d.d[820]*1;
  residual += temp*temp;
  temp = work1d.KKT[1773]-1*work1d.d[879]*work1d.L[869];
  residual += temp*temp;
  temp = work1d.KKT[1552]-1*work1d.d[778]*work1d.L[873];
  residual += temp*temp;
  temp = work1d.KKT[822]-work1d.L[663]*work1d.d[413]*1;
  residual += temp*temp;
  temp = work1d.KKT[1641]-work1d.L[879]*work1d.d[820]*1;
  residual += temp*temp;
  temp = work1d.KKT[1776]-work1d.L[885]*work1d.d[880]*1;
  residual += temp*temp;
  temp = work1d.KKT[1553]-1*work1d.d[779]*work1d.L[874];
  residual += temp*temp;
  temp = work1d.KKT[1775]-work1d.L[883]*work1d.d[880]*1-work1d.L[882]*work1d.d[879]*work1d.L[869];
  residual += temp*temp;
  temp = work1d.KKT[1778]-work1d.L[885]*work1d.d[880]*work1d.L[878]-work1d.L[886]*work1d.d[881]*1;
  residual += temp*temp;
  temp = work1d.KKT[1643]-work1d.L[880]*work1d.d[821]*1;
  residual += temp*temp;
  temp = work1d.KKT[1779]-1*work1d.d[883]*work1d.L[891];
  residual += temp*temp;
  temp = work1d.KKT[1554]-1*work1d.d[779]*work1d.L[895];
  residual += temp*temp;
  temp = work1d.KKT[824]-work1d.L[664]*work1d.d[414]*1;
  residual += temp*temp;
  temp = work1d.KKT[1644]-work1d.L[901]*work1d.d[821]*1;
  residual += temp*temp;
  temp = work1d.KKT[1782]-work1d.L[907]*work1d.d[884]*1;
  residual += temp*temp;
  temp = work1d.KKT[1555]-1*work1d.d[780]*work1d.L[896];
  residual += temp*temp;
  temp = work1d.KKT[1781]-work1d.L[905]*work1d.d[884]*1-work1d.L[904]*work1d.d[883]*work1d.L[891];
  residual += temp*temp;
  temp = work1d.KKT[1784]-work1d.L[907]*work1d.d[884]*work1d.L[900]-work1d.L[908]*work1d.d[885]*1;
  residual += temp*temp;
  temp = work1d.KKT[1646]-work1d.L[902]*work1d.d[822]*1;
  residual += temp*temp;
  temp = work1d.KKT[1785]-1*work1d.d[887]*work1d.L[913];
  residual += temp*temp;
  temp = work1d.KKT[1556]-1*work1d.d[780]*work1d.L[917];
  residual += temp*temp;
  temp = work1d.KKT[826]-work1d.L[665]*work1d.d[415]*1;
  residual += temp*temp;
  temp = work1d.KKT[1647]-work1d.L[923]*work1d.d[822]*1;
  residual += temp*temp;
  temp = work1d.KKT[1788]-work1d.L[929]*work1d.d[888]*1;
  residual += temp*temp;
  temp = work1d.KKT[1557]-1*work1d.d[781]*work1d.L[918];
  residual += temp*temp;
  temp = work1d.KKT[1787]-work1d.L[927]*work1d.d[888]*1-work1d.L[926]*work1d.d[887]*work1d.L[913];
  residual += temp*temp;
  temp = work1d.KKT[1790]-work1d.L[929]*work1d.d[888]*work1d.L[922]-work1d.L[930]*work1d.d[889]*1;
  residual += temp*temp;
  temp = work1d.KKT[1649]-work1d.L[924]*work1d.d[823]*1;
  residual += temp*temp;
  temp = work1d.KKT[1791]-1*work1d.d[891]*work1d.L[935];
  residual += temp*temp;
  temp = work1d.KKT[1558]-1*work1d.d[781]*work1d.L[939];
  residual += temp*temp;
  temp = work1d.KKT[828]-work1d.L[666]*work1d.d[416]*1;
  residual += temp*temp;
  temp = work1d.KKT[1650]-work1d.L[945]*work1d.d[823]*1;
  residual += temp*temp;
  temp = work1d.KKT[1794]-work1d.L[951]*work1d.d[892]*1;
  residual += temp*temp;
  temp = work1d.KKT[1559]-1*work1d.d[782]*work1d.L[940];
  residual += temp*temp;
  temp = work1d.KKT[1793]-work1d.L[949]*work1d.d[892]*1-work1d.L[948]*work1d.d[891]*work1d.L[935];
  residual += temp*temp;
  temp = work1d.KKT[1796]-work1d.L[951]*work1d.d[892]*work1d.L[944]-work1d.L[952]*work1d.d[893]*1;
  residual += temp*temp;
  temp = work1d.KKT[1652]-work1d.L[946]*work1d.d[824]*1;
  residual += temp*temp;
  temp = work1d.KKT[1797]-1*work1d.d[895]*work1d.L[957];
  residual += temp*temp;
  temp = work1d.KKT[1560]-1*work1d.d[782]*work1d.L[961];
  residual += temp*temp;
  temp = work1d.KKT[830]-work1d.L[667]*work1d.d[417]*1;
  residual += temp*temp;
  temp = work1d.KKT[1653]-work1d.L[967]*work1d.d[824]*1;
  residual += temp*temp;
  temp = work1d.KKT[1800]-work1d.L[973]*work1d.d[896]*1;
  residual += temp*temp;
  temp = work1d.KKT[1561]-1*work1d.d[783]*work1d.L[962];
  residual += temp*temp;
  temp = work1d.KKT[1799]-work1d.L[971]*work1d.d[896]*1-work1d.L[970]*work1d.d[895]*work1d.L[957];
  residual += temp*temp;
  temp = work1d.KKT[1802]-work1d.L[973]*work1d.d[896]*work1d.L[966]-work1d.L[974]*work1d.d[897]*1;
  residual += temp*temp;
  temp = work1d.KKT[1655]-work1d.L[968]*work1d.d[825]*1;
  residual += temp*temp;
  temp = work1d.KKT[1803]-1*work1d.d[899]*work1d.L[979];
  residual += temp*temp;
  temp = work1d.KKT[1562]-1*work1d.d[783]*work1d.L[983];
  residual += temp*temp;
  temp = work1d.KKT[832]-work1d.L[668]*work1d.d[418]*1;
  residual += temp*temp;
  temp = work1d.KKT[1656]-work1d.L[989]*work1d.d[825]*1;
  residual += temp*temp;
  temp = work1d.KKT[1806]-work1d.L[995]*work1d.d[900]*1;
  residual += temp*temp;
  temp = work1d.KKT[1563]-1*work1d.d[784]*work1d.L[984];
  residual += temp*temp;
  temp = work1d.KKT[1805]-work1d.L[993]*work1d.d[900]*1-work1d.L[992]*work1d.d[899]*work1d.L[979];
  residual += temp*temp;
  temp = work1d.KKT[1808]-work1d.L[995]*work1d.d[900]*work1d.L[988]-work1d.L[996]*work1d.d[901]*1;
  residual += temp*temp;
  temp = work1d.KKT[1658]-work1d.L[990]*work1d.d[826]*1;
  residual += temp*temp;
  temp = work1d.KKT[1809]-1*work1d.d[903]*work1d.L[1001];
  residual += temp*temp;
  temp = work1d.KKT[1564]-1*work1d.d[784]*work1d.L[1005];
  residual += temp*temp;
  temp = work1d.KKT[834]-work1d.L[669]*work1d.d[419]*1;
  residual += temp*temp;
  temp = work1d.KKT[1659]-work1d.L[1011]*work1d.d[826]*1;
  residual += temp*temp;
  temp = work1d.KKT[1812]-work1d.L[1017]*work1d.d[904]*1;
  residual += temp*temp;
  temp = work1d.KKT[1565]-1*work1d.d[785]*work1d.L[1006];
  residual += temp*temp;
  temp = work1d.KKT[1811]-work1d.L[1015]*work1d.d[904]*1-work1d.L[1014]*work1d.d[903]*work1d.L[1001];
  residual += temp*temp;
  temp = work1d.KKT[1814]-work1d.L[1017]*work1d.d[904]*work1d.L[1010]-work1d.L[1018]*work1d.d[905]*1;
  residual += temp*temp;
  temp = work1d.KKT[1661]-work1d.L[1012]*work1d.d[827]*1;
  residual += temp*temp;
  temp = work1d.KKT[1815]-1*work1d.d[907]*work1d.L[1023];
  residual += temp*temp;
  temp = work1d.KKT[1566]-1*work1d.d[785]*work1d.L[1027];
  residual += temp*temp;
  temp = work1d.KKT[836]-work1d.L[670]*work1d.d[420]*1;
  residual += temp*temp;
  temp = work1d.KKT[1662]-work1d.L[1033]*work1d.d[827]*1;
  residual += temp*temp;
  temp = work1d.KKT[1818]-work1d.L[1039]*work1d.d[908]*1;
  residual += temp*temp;
  temp = work1d.KKT[1567]-1*work1d.d[786]*work1d.L[1028];
  residual += temp*temp;
  temp = work1d.KKT[1817]-work1d.L[1037]*work1d.d[908]*1-work1d.L[1036]*work1d.d[907]*work1d.L[1023];
  residual += temp*temp;
  temp = work1d.KKT[1820]-work1d.L[1039]*work1d.d[908]*work1d.L[1032]-work1d.L[1040]*work1d.d[909]*1;
  residual += temp*temp;
  temp = work1d.KKT[1664]-work1d.L[1034]*work1d.d[828]*1;
  residual += temp*temp;
  temp = work1d.KKT[1821]-1*work1d.d[911]*work1d.L[1045];
  residual += temp*temp;
  temp = work1d.KKT[1568]-1*work1d.d[786]*work1d.L[1049];
  residual += temp*temp;
  temp = work1d.KKT[838]-work1d.L[671]*work1d.d[421]*1;
  residual += temp*temp;
  temp = work1d.KKT[1665]-work1d.L[1055]*work1d.d[828]*1;
  residual += temp*temp;
  temp = work1d.KKT[1824]-work1d.L[1061]*work1d.d[912]*1;
  residual += temp*temp;
  temp = work1d.KKT[1569]-1*work1d.d[787]*work1d.L[1050];
  residual += temp*temp;
  temp = work1d.KKT[1823]-work1d.L[1059]*work1d.d[912]*1-work1d.L[1058]*work1d.d[911]*work1d.L[1045];
  residual += temp*temp;
  temp = work1d.KKT[1826]-work1d.L[1061]*work1d.d[912]*work1d.L[1054]-work1d.L[1062]*work1d.d[913]*1;
  residual += temp*temp;
  temp = work1d.KKT[1667]-work1d.L[1056]*work1d.d[829]*1;
  residual += temp*temp;
  temp = work1d.KKT[1827]-1*work1d.d[915]*work1d.L[1067];
  residual += temp*temp;
  temp = work1d.KKT[1570]-1*work1d.d[787]*work1d.L[1071];
  residual += temp*temp;
  temp = work1d.KKT[840]-work1d.L[672]*work1d.d[422]*1;
  residual += temp*temp;
  temp = work1d.KKT[1668]-work1d.L[1077]*work1d.d[829]*1;
  residual += temp*temp;
  temp = work1d.KKT[1830]-work1d.L[1083]*work1d.d[916]*1;
  residual += temp*temp;
  temp = work1d.KKT[1571]-1*work1d.d[788]*work1d.L[1072];
  residual += temp*temp;
  temp = work1d.KKT[1829]-work1d.L[1081]*work1d.d[916]*1-work1d.L[1080]*work1d.d[915]*work1d.L[1067];
  residual += temp*temp;
  temp = work1d.KKT[1832]-work1d.L[1083]*work1d.d[916]*work1d.L[1076]-work1d.L[1084]*work1d.d[917]*1;
  residual += temp*temp;
  temp = work1d.KKT[1670]-work1d.L[1078]*work1d.d[830]*1;
  residual += temp*temp;
  temp = work1d.KKT[1833]-1*work1d.d[919]*work1d.L[1089];
  residual += temp*temp;
  temp = work1d.KKT[1572]-1*work1d.d[788]*work1d.L[1093];
  residual += temp*temp;
  temp = work1d.KKT[842]-work1d.L[673]*work1d.d[423]*1;
  residual += temp*temp;
  temp = work1d.KKT[1671]-work1d.L[1099]*work1d.d[830]*1;
  residual += temp*temp;
  temp = work1d.KKT[1836]-work1d.L[1105]*work1d.d[920]*1;
  residual += temp*temp;
  temp = work1d.KKT[1573]-1*work1d.d[789]*work1d.L[1094];
  residual += temp*temp;
  temp = work1d.KKT[1835]-work1d.L[1103]*work1d.d[920]*1-work1d.L[1102]*work1d.d[919]*work1d.L[1089];
  residual += temp*temp;
  temp = work1d.KKT[1838]-work1d.L[1105]*work1d.d[920]*work1d.L[1098]-work1d.L[1106]*work1d.d[921]*1;
  residual += temp*temp;
  temp = work1d.KKT[1673]-work1d.L[1100]*work1d.d[831]*1;
  residual += temp*temp;
  temp = work1d.KKT[1839]-1*work1d.d[923]*work1d.L[1111];
  residual += temp*temp;
  temp = work1d.KKT[1574]-1*work1d.d[789]*work1d.L[1115];
  residual += temp*temp;
  temp = work1d.KKT[844]-work1d.L[674]*work1d.d[424]*1;
  residual += temp*temp;
  temp = work1d.KKT[1674]-work1d.L[1121]*work1d.d[831]*1;
  residual += temp*temp;
  temp = work1d.KKT[1842]-work1d.L[1127]*work1d.d[924]*1;
  residual += temp*temp;
  temp = work1d.KKT[1575]-1*work1d.d[790]*work1d.L[1116];
  residual += temp*temp;
  temp = work1d.KKT[1841]-work1d.L[1125]*work1d.d[924]*1-work1d.L[1124]*work1d.d[923]*work1d.L[1111];
  residual += temp*temp;
  temp = work1d.KKT[1844]-work1d.L[1127]*work1d.d[924]*work1d.L[1120]-work1d.L[1128]*work1d.d[925]*1;
  residual += temp*temp;
  temp = work1d.KKT[1676]-work1d.L[1122]*work1d.d[832]*1;
  residual += temp*temp;
  temp = work1d.KKT[1845]-1*work1d.d[927]*work1d.L[1133];
  residual += temp*temp;
  temp = work1d.KKT[1576]-1*work1d.d[790]*work1d.L[1137];
  residual += temp*temp;
  temp = work1d.KKT[846]-work1d.L[675]*work1d.d[425]*1;
  residual += temp*temp;
  temp = work1d.KKT[1677]-work1d.L[1143]*work1d.d[832]*1;
  residual += temp*temp;
  temp = work1d.KKT[1848]-work1d.L[1149]*work1d.d[928]*1;
  residual += temp*temp;
  temp = work1d.KKT[1577]-1*work1d.d[791]*work1d.L[1138];
  residual += temp*temp;
  temp = work1d.KKT[1847]-work1d.L[1147]*work1d.d[928]*1-work1d.L[1146]*work1d.d[927]*work1d.L[1133];
  residual += temp*temp;
  temp = work1d.KKT[1850]-work1d.L[1149]*work1d.d[928]*work1d.L[1142]-work1d.L[1150]*work1d.d[929]*1;
  residual += temp*temp;
  temp = work1d.KKT[1679]-work1d.L[1144]*work1d.d[833]*1;
  residual += temp*temp;
  temp = work1d.KKT[1851]-1*work1d.d[931]*work1d.L[1155];
  residual += temp*temp;
  temp = work1d.KKT[1578]-1*work1d.d[791]*work1d.L[1159];
  residual += temp*temp;
  temp = work1d.KKT[848]-work1d.L[676]*work1d.d[426]*1;
  residual += temp*temp;
  temp = work1d.KKT[1680]-work1d.L[1165]*work1d.d[833]*1;
  residual += temp*temp;
  temp = work1d.KKT[1854]-work1d.L[1171]*work1d.d[932]*1;
  residual += temp*temp;
  temp = work1d.KKT[1579]-1*work1d.d[792]*work1d.L[1160];
  residual += temp*temp;
  temp = work1d.KKT[1853]-work1d.L[1169]*work1d.d[932]*1-work1d.L[1168]*work1d.d[931]*work1d.L[1155];
  residual += temp*temp;
  temp = work1d.KKT[1856]-work1d.L[1171]*work1d.d[932]*work1d.L[1164]-work1d.L[1172]*work1d.d[933]*1;
  residual += temp*temp;
  temp = work1d.KKT[1682]-work1d.L[1166]*work1d.d[834]*1;
  residual += temp*temp;
  temp = work1d.KKT[1857]-1*work1d.d[935]*work1d.L[1177];
  residual += temp*temp;
  temp = work1d.KKT[1580]-1*work1d.d[792]*work1d.L[1181];
  residual += temp*temp;
  temp = work1d.KKT[850]-work1d.L[677]*work1d.d[427]*1;
  residual += temp*temp;
  temp = work1d.KKT[1683]-work1d.L[1187]*work1d.d[834]*1;
  residual += temp*temp;
  temp = work1d.KKT[1860]-work1d.L[1193]*work1d.d[936]*1;
  residual += temp*temp;
  temp = work1d.KKT[1581]-1*work1d.d[793]*work1d.L[1182];
  residual += temp*temp;
  temp = work1d.KKT[1859]-work1d.L[1191]*work1d.d[936]*1-work1d.L[1190]*work1d.d[935]*work1d.L[1177];
  residual += temp*temp;
  temp = work1d.KKT[1862]-work1d.L[1193]*work1d.d[936]*work1d.L[1186]-work1d.L[1194]*work1d.d[937]*1;
  residual += temp*temp;
  temp = work1d.KKT[1685]-work1d.L[1188]*work1d.d[835]*1;
  residual += temp*temp;
  temp = work1d.KKT[1863]-1*work1d.d[939]*work1d.L[1199];
  residual += temp*temp;
  temp = work1d.KKT[1582]-1*work1d.d[793]*work1d.L[1203];
  residual += temp*temp;
  temp = work1d.KKT[852]-work1d.L[678]*work1d.d[428]*1;
  residual += temp*temp;
  temp = work1d.KKT[1686]-work1d.L[1209]*work1d.d[835]*1;
  residual += temp*temp;
  temp = work1d.KKT[1866]-work1d.L[1215]*work1d.d[940]*1;
  residual += temp*temp;
  temp = work1d.KKT[1583]-1*work1d.d[794]*work1d.L[1204];
  residual += temp*temp;
  temp = work1d.KKT[1865]-work1d.L[1213]*work1d.d[940]*1-work1d.L[1212]*work1d.d[939]*work1d.L[1199];
  residual += temp*temp;
  temp = work1d.KKT[1868]-work1d.L[1215]*work1d.d[940]*work1d.L[1208]-work1d.L[1216]*work1d.d[941]*1;
  residual += temp*temp;
  temp = work1d.KKT[1688]-work1d.L[1210]*work1d.d[836]*1;
  residual += temp*temp;
  temp = work1d.KKT[1869]-1*work1d.d[943]*work1d.L[1221];
  residual += temp*temp;
  temp = work1d.KKT[1584]-1*work1d.d[794]*work1d.L[1225];
  residual += temp*temp;
  temp = work1d.KKT[854]-work1d.L[679]*work1d.d[429]*1;
  residual += temp*temp;
  temp = work1d.KKT[1689]-work1d.L[1231]*work1d.d[836]*1;
  residual += temp*temp;
  temp = work1d.KKT[1872]-work1d.L[1237]*work1d.d[944]*1;
  residual += temp*temp;
  temp = work1d.KKT[1585]-1*work1d.d[795]*work1d.L[1226];
  residual += temp*temp;
  temp = work1d.KKT[1871]-work1d.L[1235]*work1d.d[944]*1-work1d.L[1234]*work1d.d[943]*work1d.L[1221];
  residual += temp*temp;
  temp = work1d.KKT[1874]-work1d.L[1237]*work1d.d[944]*work1d.L[1230]-work1d.L[1238]*work1d.d[945]*1;
  residual += temp*temp;
  temp = work1d.KKT[1691]-work1d.L[1232]*work1d.d[837]*1;
  residual += temp*temp;
  temp = work1d.KKT[1875]-1*work1d.d[947]*work1d.L[1243];
  residual += temp*temp;
  temp = work1d.KKT[1586]-1*work1d.d[795]*work1d.L[1247];
  residual += temp*temp;
  temp = work1d.KKT[856]-work1d.L[680]*work1d.d[430]*1;
  residual += temp*temp;
  temp = work1d.KKT[1692]-work1d.L[1253]*work1d.d[837]*1;
  residual += temp*temp;
  temp = work1d.KKT[1878]-work1d.L[1259]*work1d.d[948]*1;
  residual += temp*temp;
  temp = work1d.KKT[1587]-1*work1d.d[796]*work1d.L[1248];
  residual += temp*temp;
  temp = work1d.KKT[1877]-work1d.L[1257]*work1d.d[948]*1-work1d.L[1256]*work1d.d[947]*work1d.L[1243];
  residual += temp*temp;
  temp = work1d.KKT[1880]-work1d.L[1259]*work1d.d[948]*work1d.L[1252]-work1d.L[1260]*work1d.d[949]*1;
  residual += temp*temp;
  temp = work1d.KKT[1694]-work1d.L[1254]*work1d.d[838]*1;
  residual += temp*temp;
  temp = work1d.KKT[1881]-1*work1d.d[951]*work1d.L[1265];
  residual += temp*temp;
  temp = work1d.KKT[1588]-1*work1d.d[796]*work1d.L[1269];
  residual += temp*temp;
  temp = work1d.KKT[858]-work1d.L[681]*work1d.d[431]*1;
  residual += temp*temp;
  temp = work1d.KKT[1695]-work1d.L[1275]*work1d.d[838]*1;
  residual += temp*temp;
  temp = work1d.KKT[1884]-work1d.L[1281]*work1d.d[952]*1;
  residual += temp*temp;
  temp = work1d.KKT[1589]-1*work1d.d[797]*work1d.L[1270];
  residual += temp*temp;
  temp = work1d.KKT[1883]-work1d.L[1279]*work1d.d[952]*1-work1d.L[1278]*work1d.d[951]*work1d.L[1265];
  residual += temp*temp;
  temp = work1d.KKT[1886]-work1d.L[1281]*work1d.d[952]*work1d.L[1274]-work1d.L[1282]*work1d.d[953]*1;
  residual += temp*temp;
  temp = work1d.KKT[1697]-work1d.L[1276]*work1d.d[839]*1;
  residual += temp*temp;
  temp = work1d.KKT[1887]-1*work1d.d[955]*work1d.L[1287];
  residual += temp*temp;
  temp = work1d.KKT[1590]-1*work1d.d[797]*work1d.L[1291];
  residual += temp*temp;
  temp = work1d.KKT[860]-work1d.L[682]*work1d.d[432]*1;
  residual += temp*temp;
  temp = work1d.KKT[1698]-work1d.L[1297]*work1d.d[839]*1;
  residual += temp*temp;
  temp = work1d.KKT[1890]-work1d.L[1303]*work1d.d[956]*1;
  residual += temp*temp;
  temp = work1d.KKT[1591]-1*work1d.d[798]*work1d.L[1292];
  residual += temp*temp;
  temp = work1d.KKT[1889]-work1d.L[1301]*work1d.d[956]*1-work1d.L[1300]*work1d.d[955]*work1d.L[1287];
  residual += temp*temp;
  temp = work1d.KKT[1892]-work1d.L[1303]*work1d.d[956]*work1d.L[1296]-work1d.L[1304]*work1d.d[957]*1;
  residual += temp*temp;
  temp = work1d.KKT[1700]-work1d.L[1298]*work1d.d[840]*1;
  residual += temp*temp;
  temp = work1d.KKT[1893]-1*work1d.d[959]*work1d.L[1309];
  residual += temp*temp;
  temp = work1d.KKT[1592]-1*work1d.d[798]*work1d.L[1313];
  residual += temp*temp;
  temp = work1d.KKT[862]-work1d.L[683]*work1d.d[433]*1;
  residual += temp*temp;
  temp = work1d.KKT[1701]-work1d.L[1319]*work1d.d[840]*1;
  residual += temp*temp;
  temp = work1d.KKT[1896]-work1d.L[1325]*work1d.d[960]*1;
  residual += temp*temp;
  temp = work1d.KKT[1593]-1*work1d.d[799]*work1d.L[1314];
  residual += temp*temp;
  temp = work1d.KKT[1895]-work1d.L[1323]*work1d.d[960]*1-work1d.L[1322]*work1d.d[959]*work1d.L[1309];
  residual += temp*temp;
  temp = work1d.KKT[1898]-work1d.L[1325]*work1d.d[960]*work1d.L[1318]-work1d.L[1326]*work1d.d[961]*1;
  residual += temp*temp;
  temp = work1d.KKT[1703]-work1d.L[1320]*work1d.d[841]*1;
  residual += temp*temp;
  temp = work1d.KKT[1899]-1*work1d.d[963]*work1d.L[1331];
  residual += temp*temp;
  temp = work1d.KKT[1594]-1*work1d.d[799]*work1d.L[1335];
  residual += temp*temp;
  temp = work1d.KKT[864]-work1d.L[684]*work1d.d[434]*1;
  residual += temp*temp;
  temp = work1d.KKT[1704]-work1d.L[1341]*work1d.d[841]*1;
  residual += temp*temp;
  temp = work1d.KKT[1902]-work1d.L[1347]*work1d.d[964]*1;
  residual += temp*temp;
  temp = work1d.KKT[1595]-1*work1d.d[800]*work1d.L[1336];
  residual += temp*temp;
  temp = work1d.KKT[1901]-work1d.L[1345]*work1d.d[964]*1-work1d.L[1344]*work1d.d[963]*work1d.L[1331];
  residual += temp*temp;
  temp = work1d.KKT[1904]-work1d.L[1347]*work1d.d[964]*work1d.L[1340]-work1d.L[1348]*work1d.d[965]*1;
  residual += temp*temp;
  temp = work1d.KKT[1706]-work1d.L[1342]*work1d.d[842]*1;
  residual += temp*temp;
  temp = work1d.KKT[1905]-1*work1d.d[967]*work1d.L[1353];
  residual += temp*temp;
  temp = work1d.KKT[1596]-1*work1d.d[800]*work1d.L[1357];
  residual += temp*temp;
  temp = work1d.KKT[866]-work1d.L[685]*work1d.d[435]*1;
  residual += temp*temp;
  temp = work1d.KKT[1707]-work1d.L[1363]*work1d.d[842]*1;
  residual += temp*temp;
  temp = work1d.KKT[1908]-work1d.L[1369]*work1d.d[968]*1;
  residual += temp*temp;
  temp = work1d.KKT[1597]-1*work1d.d[801]*work1d.L[1358];
  residual += temp*temp;
  temp = work1d.KKT[1907]-work1d.L[1367]*work1d.d[968]*1-work1d.L[1366]*work1d.d[967]*work1d.L[1353];
  residual += temp*temp;
  temp = work1d.KKT[1910]-work1d.L[1369]*work1d.d[968]*work1d.L[1362]-work1d.L[1370]*work1d.d[969]*1;
  residual += temp*temp;
  temp = work1d.KKT[1709]-work1d.L[1364]*work1d.d[843]*1;
  residual += temp*temp;
  temp = work1d.KKT[1911]-1*work1d.d[971]*work1d.L[1375];
  residual += temp*temp;
  temp = work1d.KKT[1598]-1*work1d.d[801]*work1d.L[1379];
  residual += temp*temp;
  temp = work1d.KKT[868]-work1d.L[686]*work1d.d[436]*1;
  residual += temp*temp;
  temp = work1d.KKT[1710]-work1d.L[1385]*work1d.d[843]*1;
  residual += temp*temp;
  temp = work1d.KKT[1914]-work1d.L[1391]*work1d.d[972]*1;
  residual += temp*temp;
  temp = work1d.KKT[1599]-1*work1d.d[802]*work1d.L[1380];
  residual += temp*temp;
  temp = work1d.KKT[1913]-work1d.L[1389]*work1d.d[972]*1-work1d.L[1388]*work1d.d[971]*work1d.L[1375];
  residual += temp*temp;
  temp = work1d.KKT[1916]-work1d.L[1391]*work1d.d[972]*work1d.L[1384]-work1d.L[1392]*work1d.d[973]*1;
  residual += temp*temp;
  temp = work1d.KKT[1712]-work1d.L[1386]*work1d.d[844]*1;
  residual += temp*temp;
  temp = work1d.KKT[1917]-1*work1d.d[975]*work1d.L[1397];
  residual += temp*temp;
  temp = work1d.KKT[1600]-1*work1d.d[802]*work1d.L[1401];
  residual += temp*temp;
  temp = work1d.KKT[870]-work1d.L[687]*work1d.d[437]*1;
  residual += temp*temp;
  temp = work1d.KKT[1713]-work1d.L[1407]*work1d.d[844]*1;
  residual += temp*temp;
  temp = work1d.KKT[1920]-work1d.L[1413]*work1d.d[976]*1;
  residual += temp*temp;
  temp = work1d.KKT[1601]-1*work1d.d[803]*work1d.L[1402];
  residual += temp*temp;
  temp = work1d.KKT[1919]-work1d.L[1411]*work1d.d[976]*1-work1d.L[1410]*work1d.d[975]*work1d.L[1397];
  residual += temp*temp;
  temp = work1d.KKT[1922]-work1d.L[1413]*work1d.d[976]*work1d.L[1406]-work1d.L[1414]*work1d.d[977]*1;
  residual += temp*temp;
  temp = work1d.KKT[1715]-work1d.L[1408]*work1d.d[845]*1;
  residual += temp*temp;
  temp = work1d.KKT[1923]-1*work1d.d[979]*work1d.L[1419];
  residual += temp*temp;
  temp = work1d.KKT[1602]-1*work1d.d[803]*work1d.L[1423];
  residual += temp*temp;
  temp = work1d.KKT[872]-work1d.L[688]*work1d.d[438]*1;
  residual += temp*temp;
  temp = work1d.KKT[1716]-work1d.L[1429]*work1d.d[845]*1;
  residual += temp*temp;
  temp = work1d.KKT[1926]-work1d.L[1435]*work1d.d[980]*1;
  residual += temp*temp;
  temp = work1d.KKT[1603]-1*work1d.d[804]*work1d.L[1424];
  residual += temp*temp;
  temp = work1d.KKT[1925]-work1d.L[1433]*work1d.d[980]*1-work1d.L[1432]*work1d.d[979]*work1d.L[1419];
  residual += temp*temp;
  temp = work1d.KKT[1928]-work1d.L[1435]*work1d.d[980]*work1d.L[1428]-work1d.L[1436]*work1d.d[981]*1;
  residual += temp*temp;
  temp = work1d.KKT[1718]-work1d.L[1430]*work1d.d[846]*1;
  residual += temp*temp;
  temp = work1d.KKT[1929]-1*work1d.d[983]*work1d.L[1441];
  residual += temp*temp;
  temp = work1d.KKT[1604]-1*work1d.d[804]*work1d.L[1445];
  residual += temp*temp;
  temp = work1d.KKT[874]-work1d.L[689]*work1d.d[439]*1;
  residual += temp*temp;
  temp = work1d.KKT[1719]-work1d.L[1451]*work1d.d[846]*1;
  residual += temp*temp;
  temp = work1d.KKT[1932]-work1d.L[1457]*work1d.d[984]*1;
  residual += temp*temp;
  temp = work1d.KKT[1605]-1*work1d.d[805]*work1d.L[1446];
  residual += temp*temp;
  temp = work1d.KKT[1931]-work1d.L[1455]*work1d.d[984]*1-work1d.L[1454]*work1d.d[983]*work1d.L[1441];
  residual += temp*temp;
  temp = work1d.KKT[1934]-work1d.L[1457]*work1d.d[984]*work1d.L[1450]-work1d.L[1458]*work1d.d[985]*1;
  residual += temp*temp;
  temp = work1d.KKT[1721]-work1d.L[1452]*work1d.d[847]*1;
  residual += temp*temp;
  temp = work1d.KKT[1935]-1*work1d.d[987]*work1d.L[1463];
  residual += temp*temp;
  temp = work1d.KKT[1606]-1*work1d.d[805]*work1d.L[1467];
  residual += temp*temp;
  temp = work1d.KKT[876]-work1d.L[690]*work1d.d[440]*1;
  residual += temp*temp;
  temp = work1d.KKT[1722]-work1d.L[1473]*work1d.d[847]*1;
  residual += temp*temp;
  temp = work1d.KKT[1938]-work1d.L[1479]*work1d.d[988]*1;
  residual += temp*temp;
  temp = work1d.KKT[1607]-1*work1d.d[806]*work1d.L[1468];
  residual += temp*temp;
  temp = work1d.KKT[1937]-work1d.L[1477]*work1d.d[988]*1-work1d.L[1476]*work1d.d[987]*work1d.L[1463];
  residual += temp*temp;
  temp = work1d.KKT[1940]-work1d.L[1479]*work1d.d[988]*work1d.L[1472]-work1d.L[1480]*work1d.d[989]*1;
  residual += temp*temp;
  temp = work1d.KKT[1724]-work1d.L[1474]*work1d.d[848]*1;
  residual += temp*temp;
  temp = work1d.KKT[1941]-1*work1d.d[991]*work1d.L[1485];
  residual += temp*temp;
  temp = work1d.KKT[1608]-1*work1d.d[806]*work1d.L[1489];
  residual += temp*temp;
  temp = work1d.KKT[878]-work1d.L[691]*work1d.d[441]*1;
  residual += temp*temp;
  temp = work1d.KKT[1725]-work1d.L[1495]*work1d.d[848]*1;
  residual += temp*temp;
  temp = work1d.KKT[1944]-work1d.L[1501]*work1d.d[992]*1;
  residual += temp*temp;
  temp = work1d.KKT[1609]-1*work1d.d[807]*work1d.L[1490];
  residual += temp*temp;
  temp = work1d.KKT[1943]-work1d.L[1499]*work1d.d[992]*1-work1d.L[1498]*work1d.d[991]*work1d.L[1485];
  residual += temp*temp;
  temp = work1d.KKT[1946]-work1d.L[1501]*work1d.d[992]*work1d.L[1494]-work1d.L[1502]*work1d.d[993]*1;
  residual += temp*temp;
  temp = work1d.KKT[1727]-work1d.L[1496]*work1d.d[849]*1;
  residual += temp*temp;
  temp = work1d.KKT[1947]-1*work1d.d[995]*work1d.L[1511];
  residual += temp*temp;
  temp = work1d.KKT[1610]-1*work1d.d[807]*work1d.L[1517];
  residual += temp*temp;
  temp = work1d.KKT[880]-work1d.L[692]*work1d.d[442]*1;
  residual += temp*temp;
  temp = work1d.KKT[1728]-work1d.L[1504]*work1d.d[849]*1;
  residual += temp*temp;
  temp = work1d.KKT[1949]-1*work1d.d[997]*work1d.L[1513];
  residual += temp*temp;
  temp = work1d.KKT[1611]-1*work1d.d[808]*work1d.L[1518];
  residual += temp*temp;
  temp = work1d.KKT[1948]-1*work1d.d[996]*work1d.L[1512]-work1d.L[1507]*work1d.d[995]*work1d.L[1511];
  residual += temp*temp;
  temp = work1d.KKT[1950]-1*work1d.d[997]*work1d.L[1524];
  residual += temp*temp;
  temp = work1d.KKT[1730]-work1d.L[1505]*work1d.d[850]*1;
  residual += temp*temp;
  temp = work1d.KKT[1951]-1*work1d.d[997]*work1d.L[1533];
  residual += temp*temp;
  temp = work1d.KKT[1533]-work1d.L[693]*work1d.d[769]*1;
  residual += temp*temp;
  temp = work1d.KKT[882]-work1d.L[648]*work1d.d[443]*1;
  residual += temp*temp;
  temp = work1d.KKT[1612]-1*work1d.d[809]*work1d.L[710];
  residual += temp*temp;
  temp = work1d.KKT[1614]-1*work1d.d[810]*work1d.L[1530];
  residual += temp*temp;
  temp = work1d.KKT[1531]-1*work1d.d[768]*work1d.L[653];
  residual += temp*temp;
  temp = work1d.KKT[1613]-1*work1d.d[809]*work1d.L[1529];
  residual += temp*temp;
  temp = work1d.KKT[1534]-work1d.L[696]*work1d.d[769]*1;
  residual += temp*temp;
  temp = work1d.KKT[886]-work1d.L[694]*work1d.d[445]*1;
  residual += temp*temp;
  temp = work1d.KKT[1208]-work1d.L[695]*work1d.d[606]*1;
  residual += temp*temp;
  temp = work1d.KKT[1530]-work1d.L[649]*work1d.d[767]*1;
  residual += temp*temp;
  return residual;
}
void matrix_multiply1d(double *result, double *source) {
  /* Finds result = A*source. */
  result[0] = work1d.KKT[888]*source[561]+work1d.KKT[889]*source[562]+work1d.KKT[890]*source[563];
  result[1] = work1d.KKT[896]*source[564]+work1d.KKT[897]*source[565]+work1d.KKT[898]*source[566];
  result[2] = work1d.KKT[904]*source[567]+work1d.KKT[905]*source[568]+work1d.KKT[906]*source[569];
  result[3] = work1d.KKT[912]*source[570]+work1d.KKT[913]*source[571]+work1d.KKT[914]*source[572];
  result[4] = work1d.KKT[920]*source[573]+work1d.KKT[921]*source[574]+work1d.KKT[922]*source[575];
  result[5] = work1d.KKT[928]*source[576]+work1d.KKT[929]*source[577]+work1d.KKT[930]*source[578];
  result[6] = work1d.KKT[936]*source[579]+work1d.KKT[937]*source[580]+work1d.KKT[938]*source[581];
  result[7] = work1d.KKT[944]*source[582]+work1d.KKT[945]*source[583]+work1d.KKT[946]*source[584];
  result[8] = work1d.KKT[952]*source[585]+work1d.KKT[953]*source[586]+work1d.KKT[954]*source[587];
  result[9] = work1d.KKT[960]*source[588]+work1d.KKT[961]*source[589]+work1d.KKT[962]*source[590];
  result[10] = work1d.KKT[968]*source[591]+work1d.KKT[969]*source[592]+work1d.KKT[970]*source[593];
  result[11] = work1d.KKT[976]*source[594]+work1d.KKT[977]*source[595]+work1d.KKT[978]*source[596];
  result[12] = work1d.KKT[984]*source[597]+work1d.KKT[985]*source[598]+work1d.KKT[986]*source[599];
  result[13] = work1d.KKT[992]*source[600]+work1d.KKT[993]*source[601]+work1d.KKT[994]*source[602];
  result[14] = work1d.KKT[1000]*source[603]+work1d.KKT[1001]*source[604]+work1d.KKT[1002]*source[605];
  result[15] = work1d.KKT[1008]*source[606]+work1d.KKT[1009]*source[607]+work1d.KKT[1010]*source[608];
  result[16] = work1d.KKT[1016]*source[609]+work1d.KKT[1017]*source[610]+work1d.KKT[1018]*source[611];
  result[17] = work1d.KKT[1024]*source[612]+work1d.KKT[1025]*source[613]+work1d.KKT[1026]*source[614];
  result[18] = work1d.KKT[1032]*source[615]+work1d.KKT[1033]*source[616]+work1d.KKT[1034]*source[617];
  result[19] = work1d.KKT[1040]*source[618]+work1d.KKT[1041]*source[619]+work1d.KKT[1042]*source[620];
  result[20] = work1d.KKT[1048]*source[621]+work1d.KKT[1049]*source[622]+work1d.KKT[1050]*source[623];
  result[21] = work1d.KKT[1056]*source[624]+work1d.KKT[1057]*source[625]+work1d.KKT[1058]*source[626];
  result[22] = work1d.KKT[1064]*source[627]+work1d.KKT[1065]*source[628]+work1d.KKT[1066]*source[629];
  result[23] = work1d.KKT[1072]*source[630]+work1d.KKT[1073]*source[631]+work1d.KKT[1074]*source[632];
  result[24] = work1d.KKT[1080]*source[633]+work1d.KKT[1081]*source[634]+work1d.KKT[1082]*source[635];
  result[25] = work1d.KKT[1088]*source[636]+work1d.KKT[1089]*source[637]+work1d.KKT[1090]*source[638];
  result[26] = work1d.KKT[1096]*source[639]+work1d.KKT[1097]*source[640]+work1d.KKT[1098]*source[641];
  result[27] = work1d.KKT[1104]*source[642]+work1d.KKT[1105]*source[643]+work1d.KKT[1106]*source[644];
  result[28] = work1d.KKT[1112]*source[645]+work1d.KKT[1113]*source[646]+work1d.KKT[1114]*source[647];
  result[29] = work1d.KKT[1120]*source[648]+work1d.KKT[1121]*source[649]+work1d.KKT[1122]*source[650];
  result[30] = work1d.KKT[1128]*source[651]+work1d.KKT[1129]*source[652]+work1d.KKT[1130]*source[653];
  result[31] = work1d.KKT[1136]*source[654]+work1d.KKT[1137]*source[655]+work1d.KKT[1138]*source[656];
  result[32] = work1d.KKT[1144]*source[657]+work1d.KKT[1145]*source[658]+work1d.KKT[1146]*source[659];
  result[33] = work1d.KKT[1152]*source[660]+work1d.KKT[1153]*source[661]+work1d.KKT[1154]*source[662];
  result[34] = work1d.KKT[1160]*source[663]+work1d.KKT[1161]*source[664]+work1d.KKT[1162]*source[665];
  result[35] = work1d.KKT[1168]*source[666]+work1d.KKT[1169]*source[667]+work1d.KKT[1170]*source[668];
  result[36] = work1d.KKT[1176]*source[669]+work1d.KKT[1177]*source[670]+work1d.KKT[1178]*source[671];
  result[37] = work1d.KKT[1184]*source[672]+work1d.KKT[1185]*source[673]+work1d.KKT[1186]*source[674];
  result[38] = work1d.KKT[1192]*source[675]+work1d.KKT[1193]*source[676]+work1d.KKT[1194]*source[677];
  result[39] = work1d.KKT[1200]*source[678]+work1d.KKT[1201]*source[679]+work1d.KKT[1202]*source[680];
  result[40] = work1d.KKT[1210]*source[681]+work1d.KKT[1211]*source[682]+work1d.KKT[1212]*source[683];
  result[41] = work1d.KKT[1218]*source[684]+work1d.KKT[1219]*source[685]+work1d.KKT[1220]*source[686];
  result[42] = work1d.KKT[1226]*source[687]+work1d.KKT[1227]*source[688]+work1d.KKT[1228]*source[689];
  result[43] = work1d.KKT[1234]*source[690]+work1d.KKT[1235]*source[691]+work1d.KKT[1236]*source[692];
  result[44] = work1d.KKT[1242]*source[693]+work1d.KKT[1243]*source[694]+work1d.KKT[1244]*source[695];
  result[45] = work1d.KKT[1250]*source[696]+work1d.KKT[1251]*source[697]+work1d.KKT[1252]*source[698];
  result[46] = work1d.KKT[1258]*source[699]+work1d.KKT[1259]*source[700]+work1d.KKT[1260]*source[701];
  result[47] = work1d.KKT[1266]*source[702]+work1d.KKT[1267]*source[703]+work1d.KKT[1268]*source[704];
  result[48] = work1d.KKT[1274]*source[705]+work1d.KKT[1275]*source[706]+work1d.KKT[1276]*source[707];
  result[49] = work1d.KKT[1282]*source[708]+work1d.KKT[1283]*source[709]+work1d.KKT[1284]*source[710];
  result[50] = work1d.KKT[1290]*source[711]+work1d.KKT[1291]*source[712]+work1d.KKT[1292]*source[713];
  result[51] = work1d.KKT[1298]*source[714]+work1d.KKT[1299]*source[715]+work1d.KKT[1300]*source[716];
  result[52] = work1d.KKT[1306]*source[717]+work1d.KKT[1307]*source[718]+work1d.KKT[1308]*source[719];
  result[53] = work1d.KKT[1314]*source[720]+work1d.KKT[1315]*source[721]+work1d.KKT[1316]*source[722];
  result[54] = work1d.KKT[1322]*source[723]+work1d.KKT[1323]*source[724]+work1d.KKT[1324]*source[725];
  result[55] = work1d.KKT[1330]*source[726]+work1d.KKT[1331]*source[727]+work1d.KKT[1332]*source[728];
  result[56] = work1d.KKT[1338]*source[729]+work1d.KKT[1339]*source[730]+work1d.KKT[1340]*source[731];
  result[57] = work1d.KKT[1346]*source[732]+work1d.KKT[1347]*source[733]+work1d.KKT[1348]*source[734];
  result[58] = work1d.KKT[1354]*source[735]+work1d.KKT[1355]*source[736]+work1d.KKT[1356]*source[737];
  result[59] = work1d.KKT[1362]*source[738]+work1d.KKT[1363]*source[739]+work1d.KKT[1364]*source[740];
  result[60] = work1d.KKT[1370]*source[741]+work1d.KKT[1371]*source[742]+work1d.KKT[1372]*source[743];
  result[61] = work1d.KKT[1378]*source[744]+work1d.KKT[1379]*source[745]+work1d.KKT[1380]*source[746];
  result[62] = work1d.KKT[1386]*source[747]+work1d.KKT[1387]*source[748]+work1d.KKT[1388]*source[749];
  result[63] = work1d.KKT[1394]*source[750]+work1d.KKT[1395]*source[751]+work1d.KKT[1396]*source[752];
  result[64] = work1d.KKT[1402]*source[753]+work1d.KKT[1403]*source[754]+work1d.KKT[1404]*source[755];
  result[65] = work1d.KKT[1410]*source[756]+work1d.KKT[1411]*source[757]+work1d.KKT[1412]*source[758];
  result[66] = work1d.KKT[1418]*source[759]+work1d.KKT[1419]*source[760]+work1d.KKT[1420]*source[761];
  result[67] = work1d.KKT[1426]*source[762]+work1d.KKT[1427]*source[763]+work1d.KKT[1428]*source[764];
  result[68] = work1d.KKT[1434]*source[765]+work1d.KKT[1435]*source[766]+work1d.KKT[1436]*source[767];
  result[69] = work1d.KKT[1442]*source[768]+work1d.KKT[1443]*source[769]+work1d.KKT[1444]*source[770];
  result[70] = work1d.KKT[1450]*source[771]+work1d.KKT[1451]*source[772]+work1d.KKT[1452]*source[773];
  result[71] = work1d.KKT[1458]*source[774]+work1d.KKT[1459]*source[775]+work1d.KKT[1460]*source[776];
  result[72] = work1d.KKT[1466]*source[777]+work1d.KKT[1467]*source[778]+work1d.KKT[1468]*source[779];
  result[73] = work1d.KKT[1474]*source[780]+work1d.KKT[1475]*source[781]+work1d.KKT[1476]*source[782];
  result[74] = work1d.KKT[1482]*source[783]+work1d.KKT[1483]*source[784]+work1d.KKT[1484]*source[785];
  result[75] = work1d.KKT[1490]*source[786]+work1d.KKT[1491]*source[787]+work1d.KKT[1492]*source[788];
  result[76] = work1d.KKT[1498]*source[789]+work1d.KKT[1499]*source[790]+work1d.KKT[1500]*source[791];
  result[77] = work1d.KKT[1506]*source[792]+work1d.KKT[1507]*source[793]+work1d.KKT[1508]*source[794];
  result[78] = work1d.KKT[1514]*source[795]+work1d.KKT[1515]*source[796]+work1d.KKT[1516]*source[797];
  result[79] = work1d.KKT[1522]*source[798]+work1d.KKT[1523]*source[799]+work1d.KKT[1524]*source[800];
  result[80] = work1d.KKT[803]*source[883];
  result[81] = work1d.KKT[805]*source[81]+work1d.KKT[806]*source[886];
  result[82] = work1d.KKT[807]*source[82]+work1d.KKT[808]*source[889];
  result[83] = work1d.KKT[809]*source[83]+work1d.KKT[810]*source[892];
  result[84] = work1d.KKT[811]*source[84]+work1d.KKT[812]*source[895];
  result[85] = work1d.KKT[813]*source[85]+work1d.KKT[814]*source[898];
  result[86] = work1d.KKT[815]*source[86]+work1d.KKT[816]*source[901];
  result[87] = work1d.KKT[817]*source[87]+work1d.KKT[818]*source[904];
  result[88] = work1d.KKT[819]*source[88]+work1d.KKT[820]*source[907];
  result[89] = work1d.KKT[821]*source[89]+work1d.KKT[822]*source[910];
  result[90] = work1d.KKT[823]*source[90]+work1d.KKT[824]*source[913];
  result[91] = work1d.KKT[825]*source[91]+work1d.KKT[826]*source[916];
  result[92] = work1d.KKT[827]*source[92]+work1d.KKT[828]*source[919];
  result[93] = work1d.KKT[829]*source[93]+work1d.KKT[830]*source[922];
  result[94] = work1d.KKT[831]*source[94]+work1d.KKT[832]*source[925];
  result[95] = work1d.KKT[833]*source[95]+work1d.KKT[834]*source[928];
  result[96] = work1d.KKT[835]*source[96]+work1d.KKT[836]*source[931];
  result[97] = work1d.KKT[837]*source[97]+work1d.KKT[838]*source[934];
  result[98] = work1d.KKT[839]*source[98]+work1d.KKT[840]*source[937];
  result[99] = work1d.KKT[841]*source[99]+work1d.KKT[842]*source[940];
  result[100] = work1d.KKT[843]*source[100]+work1d.KKT[844]*source[943];
  result[101] = work1d.KKT[845]*source[101]+work1d.KKT[846]*source[946];
  result[102] = work1d.KKT[847]*source[102]+work1d.KKT[848]*source[949];
  result[103] = work1d.KKT[849]*source[103]+work1d.KKT[850]*source[952];
  result[104] = work1d.KKT[851]*source[104]+work1d.KKT[852]*source[955];
  result[105] = work1d.KKT[853]*source[105]+work1d.KKT[854]*source[958];
  result[106] = work1d.KKT[855]*source[106]+work1d.KKT[856]*source[961];
  result[107] = work1d.KKT[857]*source[107]+work1d.KKT[858]*source[964];
  result[108] = work1d.KKT[859]*source[108]+work1d.KKT[860]*source[967];
  result[109] = work1d.KKT[861]*source[109]+work1d.KKT[862]*source[970];
  result[110] = work1d.KKT[863]*source[110]+work1d.KKT[864]*source[973];
  result[111] = work1d.KKT[865]*source[111]+work1d.KKT[866]*source[976];
  result[112] = work1d.KKT[867]*source[112]+work1d.KKT[868]*source[979];
  result[113] = work1d.KKT[869]*source[113]+work1d.KKT[870]*source[982];
  result[114] = work1d.KKT[871]*source[114]+work1d.KKT[872]*source[985];
  result[115] = work1d.KKT[873]*source[115]+work1d.KKT[874]*source[988];
  result[116] = work1d.KKT[875]*source[116]+work1d.KKT[876]*source[991];
  result[117] = work1d.KKT[877]*source[117]+work1d.KKT[878]*source[994];
  result[118] = work1d.KKT[879]*source[118]+work1d.KKT[880]*source[997];
  result[119] = work1d.KKT[881]*source[119]+work1d.KKT[882]*source[1000];
  result[120] = work1d.KKT[0]*source[120];
  result[121] = work1d.KKT[883]*source[121]+work1d.KKT[801]*source[881]+work1d.KKT[884]*source[884];
  result[122] = work1d.KKT[1615]*source[122]+work1d.KKT[892]*source[562]+work1d.KKT[894]*source[563]+work1d.KKT[642]*source[801]+work1d.KKT[802]*source[882]+work1d.KKT[1616]*source[885]+work1d.KKT[1535]*source[884];
  result[123] = work1d.KKT[1617]*source[123]+work1d.KKT[1214]*source[682]+work1d.KKT[1216]*source[683]+work1d.KKT[722]*source[841]+work1d.KKT[804]*source[883]+work1d.KKT[1537]*source[886]+work1d.KKT[1618]*source[885];
  result[124] = work1d.KKT[1619]*source[124]+work1d.KKT[1536]*source[884]+work1d.KKT[1620]*source[887];
  result[125] = work1d.KKT[1732]*source[125]+work1d.KKT[900]*source[565]+work1d.KKT[902]*source[566]+work1d.KKT[644]*source[802]+work1d.KKT[1731]*source[885]+work1d.KKT[1734]*source[888]+work1d.KKT[1733]*source[887];
  result[126] = work1d.KKT[1735]*source[126]+work1d.KKT[1222]*source[685]+work1d.KKT[1224]*source[686]+work1d.KKT[724]*source[842]+work1d.KKT[1538]*source[886]+work1d.KKT[1539]*source[889]+work1d.KKT[1736]*source[888];
  result[127] = work1d.KKT[1621]*source[127]+work1d.KKT[1622]*source[887]+work1d.KKT[1623]*source[890];
  result[128] = work1d.KKT[1738]*source[128]+work1d.KKT[908]*source[568]+work1d.KKT[910]*source[569]+work1d.KKT[646]*source[803]+work1d.KKT[1737]*source[888]+work1d.KKT[1740]*source[891]+work1d.KKT[1739]*source[890];
  result[129] = work1d.KKT[1741]*source[129]+work1d.KKT[1230]*source[688]+work1d.KKT[1232]*source[689]+work1d.KKT[726]*source[843]+work1d.KKT[1540]*source[889]+work1d.KKT[1541]*source[892]+work1d.KKT[1742]*source[891];
  result[130] = work1d.KKT[1624]*source[130]+work1d.KKT[1625]*source[890]+work1d.KKT[1626]*source[893];
  result[131] = work1d.KKT[1744]*source[131]+work1d.KKT[916]*source[571]+work1d.KKT[918]*source[572]+work1d.KKT[648]*source[804]+work1d.KKT[1743]*source[891]+work1d.KKT[1746]*source[894]+work1d.KKT[1745]*source[893];
  result[132] = work1d.KKT[1747]*source[132]+work1d.KKT[1238]*source[691]+work1d.KKT[1240]*source[692]+work1d.KKT[728]*source[844]+work1d.KKT[1542]*source[892]+work1d.KKT[1543]*source[895]+work1d.KKT[1748]*source[894];
  result[133] = work1d.KKT[1627]*source[133]+work1d.KKT[1628]*source[893]+work1d.KKT[1629]*source[896];
  result[134] = work1d.KKT[1750]*source[134]+work1d.KKT[924]*source[574]+work1d.KKT[926]*source[575]+work1d.KKT[650]*source[805]+work1d.KKT[1749]*source[894]+work1d.KKT[1752]*source[897]+work1d.KKT[1751]*source[896];
  result[135] = work1d.KKT[1753]*source[135]+work1d.KKT[1246]*source[694]+work1d.KKT[1248]*source[695]+work1d.KKT[730]*source[845]+work1d.KKT[1544]*source[895]+work1d.KKT[1545]*source[898]+work1d.KKT[1754]*source[897];
  result[136] = work1d.KKT[1630]*source[136]+work1d.KKT[1631]*source[896]+work1d.KKT[1632]*source[899];
  result[137] = work1d.KKT[1756]*source[137]+work1d.KKT[932]*source[577]+work1d.KKT[934]*source[578]+work1d.KKT[652]*source[806]+work1d.KKT[1755]*source[897]+work1d.KKT[1758]*source[900]+work1d.KKT[1757]*source[899];
  result[138] = work1d.KKT[1759]*source[138]+work1d.KKT[1254]*source[697]+work1d.KKT[1256]*source[698]+work1d.KKT[732]*source[846]+work1d.KKT[1546]*source[898]+work1d.KKT[1547]*source[901]+work1d.KKT[1760]*source[900];
  result[139] = work1d.KKT[1633]*source[139]+work1d.KKT[1634]*source[899]+work1d.KKT[1635]*source[902];
  result[140] = work1d.KKT[1762]*source[140]+work1d.KKT[940]*source[580]+work1d.KKT[942]*source[581]+work1d.KKT[654]*source[807]+work1d.KKT[1761]*source[900]+work1d.KKT[1764]*source[903]+work1d.KKT[1763]*source[902];
  result[141] = work1d.KKT[1765]*source[141]+work1d.KKT[1262]*source[700]+work1d.KKT[1264]*source[701]+work1d.KKT[734]*source[847]+work1d.KKT[1548]*source[901]+work1d.KKT[1549]*source[904]+work1d.KKT[1766]*source[903];
  result[142] = work1d.KKT[1636]*source[142]+work1d.KKT[1637]*source[902]+work1d.KKT[1638]*source[905];
  result[143] = work1d.KKT[1768]*source[143]+work1d.KKT[948]*source[583]+work1d.KKT[950]*source[584]+work1d.KKT[656]*source[808]+work1d.KKT[1767]*source[903]+work1d.KKT[1770]*source[906]+work1d.KKT[1769]*source[905];
  result[144] = work1d.KKT[1771]*source[144]+work1d.KKT[1270]*source[703]+work1d.KKT[1272]*source[704]+work1d.KKT[736]*source[848]+work1d.KKT[1550]*source[904]+work1d.KKT[1551]*source[907]+work1d.KKT[1772]*source[906];
  result[145] = work1d.KKT[1639]*source[145]+work1d.KKT[1640]*source[905]+work1d.KKT[1641]*source[908];
  result[146] = work1d.KKT[1774]*source[146]+work1d.KKT[956]*source[586]+work1d.KKT[958]*source[587]+work1d.KKT[658]*source[809]+work1d.KKT[1773]*source[906]+work1d.KKT[1776]*source[909]+work1d.KKT[1775]*source[908];
  result[147] = work1d.KKT[1777]*source[147]+work1d.KKT[1278]*source[706]+work1d.KKT[1280]*source[707]+work1d.KKT[738]*source[849]+work1d.KKT[1552]*source[907]+work1d.KKT[1553]*source[910]+work1d.KKT[1778]*source[909];
  result[148] = work1d.KKT[1642]*source[148]+work1d.KKT[1643]*source[908]+work1d.KKT[1644]*source[911];
  result[149] = work1d.KKT[1780]*source[149]+work1d.KKT[964]*source[589]+work1d.KKT[966]*source[590]+work1d.KKT[660]*source[810]+work1d.KKT[1779]*source[909]+work1d.KKT[1782]*source[912]+work1d.KKT[1781]*source[911];
  result[150] = work1d.KKT[1783]*source[150]+work1d.KKT[1286]*source[709]+work1d.KKT[1288]*source[710]+work1d.KKT[740]*source[850]+work1d.KKT[1554]*source[910]+work1d.KKT[1555]*source[913]+work1d.KKT[1784]*source[912];
  result[151] = work1d.KKT[1645]*source[151]+work1d.KKT[1646]*source[911]+work1d.KKT[1647]*source[914];
  result[152] = work1d.KKT[1786]*source[152]+work1d.KKT[972]*source[592]+work1d.KKT[974]*source[593]+work1d.KKT[662]*source[811]+work1d.KKT[1785]*source[912]+work1d.KKT[1788]*source[915]+work1d.KKT[1787]*source[914];
  result[153] = work1d.KKT[1789]*source[153]+work1d.KKT[1294]*source[712]+work1d.KKT[1296]*source[713]+work1d.KKT[742]*source[851]+work1d.KKT[1556]*source[913]+work1d.KKT[1557]*source[916]+work1d.KKT[1790]*source[915];
  result[154] = work1d.KKT[1648]*source[154]+work1d.KKT[1649]*source[914]+work1d.KKT[1650]*source[917];
  result[155] = work1d.KKT[1792]*source[155]+work1d.KKT[980]*source[595]+work1d.KKT[982]*source[596]+work1d.KKT[664]*source[812]+work1d.KKT[1791]*source[915]+work1d.KKT[1794]*source[918]+work1d.KKT[1793]*source[917];
  result[156] = work1d.KKT[1795]*source[156]+work1d.KKT[1302]*source[715]+work1d.KKT[1304]*source[716]+work1d.KKT[744]*source[852]+work1d.KKT[1558]*source[916]+work1d.KKT[1559]*source[919]+work1d.KKT[1796]*source[918];
  result[157] = work1d.KKT[1651]*source[157]+work1d.KKT[1652]*source[917]+work1d.KKT[1653]*source[920];
  result[158] = work1d.KKT[1798]*source[158]+work1d.KKT[988]*source[598]+work1d.KKT[990]*source[599]+work1d.KKT[666]*source[813]+work1d.KKT[1797]*source[918]+work1d.KKT[1800]*source[921]+work1d.KKT[1799]*source[920];
  result[159] = work1d.KKT[1801]*source[159]+work1d.KKT[1310]*source[718]+work1d.KKT[1312]*source[719]+work1d.KKT[746]*source[853]+work1d.KKT[1560]*source[919]+work1d.KKT[1561]*source[922]+work1d.KKT[1802]*source[921];
  result[160] = work1d.KKT[1654]*source[160]+work1d.KKT[1655]*source[920]+work1d.KKT[1656]*source[923];
  result[161] = work1d.KKT[1804]*source[161]+work1d.KKT[996]*source[601]+work1d.KKT[998]*source[602]+work1d.KKT[668]*source[814]+work1d.KKT[1803]*source[921]+work1d.KKT[1806]*source[924]+work1d.KKT[1805]*source[923];
  result[162] = work1d.KKT[1807]*source[162]+work1d.KKT[1318]*source[721]+work1d.KKT[1320]*source[722]+work1d.KKT[748]*source[854]+work1d.KKT[1562]*source[922]+work1d.KKT[1563]*source[925]+work1d.KKT[1808]*source[924];
  result[163] = work1d.KKT[1657]*source[163]+work1d.KKT[1658]*source[923]+work1d.KKT[1659]*source[926];
  result[164] = work1d.KKT[1810]*source[164]+work1d.KKT[1004]*source[604]+work1d.KKT[1006]*source[605]+work1d.KKT[670]*source[815]+work1d.KKT[1809]*source[924]+work1d.KKT[1812]*source[927]+work1d.KKT[1811]*source[926];
  result[165] = work1d.KKT[1813]*source[165]+work1d.KKT[1326]*source[724]+work1d.KKT[1328]*source[725]+work1d.KKT[750]*source[855]+work1d.KKT[1564]*source[925]+work1d.KKT[1565]*source[928]+work1d.KKT[1814]*source[927];
  result[166] = work1d.KKT[1660]*source[166]+work1d.KKT[1661]*source[926]+work1d.KKT[1662]*source[929];
  result[167] = work1d.KKT[1816]*source[167]+work1d.KKT[1012]*source[607]+work1d.KKT[1014]*source[608]+work1d.KKT[672]*source[816]+work1d.KKT[1815]*source[927]+work1d.KKT[1818]*source[930]+work1d.KKT[1817]*source[929];
  result[168] = work1d.KKT[1819]*source[168]+work1d.KKT[1334]*source[727]+work1d.KKT[1336]*source[728]+work1d.KKT[752]*source[856]+work1d.KKT[1566]*source[928]+work1d.KKT[1567]*source[931]+work1d.KKT[1820]*source[930];
  result[169] = work1d.KKT[1663]*source[169]+work1d.KKT[1664]*source[929]+work1d.KKT[1665]*source[932];
  result[170] = work1d.KKT[1822]*source[170]+work1d.KKT[1020]*source[610]+work1d.KKT[1022]*source[611]+work1d.KKT[674]*source[817]+work1d.KKT[1821]*source[930]+work1d.KKT[1824]*source[933]+work1d.KKT[1823]*source[932];
  result[171] = work1d.KKT[1825]*source[171]+work1d.KKT[1342]*source[730]+work1d.KKT[1344]*source[731]+work1d.KKT[754]*source[857]+work1d.KKT[1568]*source[931]+work1d.KKT[1569]*source[934]+work1d.KKT[1826]*source[933];
  result[172] = work1d.KKT[1666]*source[172]+work1d.KKT[1667]*source[932]+work1d.KKT[1668]*source[935];
  result[173] = work1d.KKT[1828]*source[173]+work1d.KKT[1028]*source[613]+work1d.KKT[1030]*source[614]+work1d.KKT[676]*source[818]+work1d.KKT[1827]*source[933]+work1d.KKT[1830]*source[936]+work1d.KKT[1829]*source[935];
  result[174] = work1d.KKT[1831]*source[174]+work1d.KKT[1350]*source[733]+work1d.KKT[1352]*source[734]+work1d.KKT[756]*source[858]+work1d.KKT[1570]*source[934]+work1d.KKT[1571]*source[937]+work1d.KKT[1832]*source[936];
  result[175] = work1d.KKT[1669]*source[175]+work1d.KKT[1670]*source[935]+work1d.KKT[1671]*source[938];
  result[176] = work1d.KKT[1834]*source[176]+work1d.KKT[1036]*source[616]+work1d.KKT[1038]*source[617]+work1d.KKT[678]*source[819]+work1d.KKT[1833]*source[936]+work1d.KKT[1836]*source[939]+work1d.KKT[1835]*source[938];
  result[177] = work1d.KKT[1837]*source[177]+work1d.KKT[1358]*source[736]+work1d.KKT[1360]*source[737]+work1d.KKT[758]*source[859]+work1d.KKT[1572]*source[937]+work1d.KKT[1573]*source[940]+work1d.KKT[1838]*source[939];
  result[178] = work1d.KKT[1672]*source[178]+work1d.KKT[1673]*source[938]+work1d.KKT[1674]*source[941];
  result[179] = work1d.KKT[1840]*source[179]+work1d.KKT[1044]*source[619]+work1d.KKT[1046]*source[620]+work1d.KKT[680]*source[820]+work1d.KKT[1839]*source[939]+work1d.KKT[1842]*source[942]+work1d.KKT[1841]*source[941];
  result[180] = work1d.KKT[1843]*source[180]+work1d.KKT[1366]*source[739]+work1d.KKT[1368]*source[740]+work1d.KKT[760]*source[860]+work1d.KKT[1574]*source[940]+work1d.KKT[1575]*source[943]+work1d.KKT[1844]*source[942];
  result[181] = work1d.KKT[1675]*source[181]+work1d.KKT[1676]*source[941]+work1d.KKT[1677]*source[944];
  result[182] = work1d.KKT[1846]*source[182]+work1d.KKT[1052]*source[622]+work1d.KKT[1054]*source[623]+work1d.KKT[682]*source[821]+work1d.KKT[1845]*source[942]+work1d.KKT[1848]*source[945]+work1d.KKT[1847]*source[944];
  result[183] = work1d.KKT[1849]*source[183]+work1d.KKT[1374]*source[742]+work1d.KKT[1376]*source[743]+work1d.KKT[762]*source[861]+work1d.KKT[1576]*source[943]+work1d.KKT[1577]*source[946]+work1d.KKT[1850]*source[945];
  result[184] = work1d.KKT[1678]*source[184]+work1d.KKT[1679]*source[944]+work1d.KKT[1680]*source[947];
  result[185] = work1d.KKT[1852]*source[185]+work1d.KKT[1060]*source[625]+work1d.KKT[1062]*source[626]+work1d.KKT[684]*source[822]+work1d.KKT[1851]*source[945]+work1d.KKT[1854]*source[948]+work1d.KKT[1853]*source[947];
  result[186] = work1d.KKT[1855]*source[186]+work1d.KKT[1382]*source[745]+work1d.KKT[1384]*source[746]+work1d.KKT[764]*source[862]+work1d.KKT[1578]*source[946]+work1d.KKT[1579]*source[949]+work1d.KKT[1856]*source[948];
  result[187] = work1d.KKT[1681]*source[187]+work1d.KKT[1682]*source[947]+work1d.KKT[1683]*source[950];
  result[188] = work1d.KKT[1858]*source[188]+work1d.KKT[1068]*source[628]+work1d.KKT[1070]*source[629]+work1d.KKT[686]*source[823]+work1d.KKT[1857]*source[948]+work1d.KKT[1860]*source[951]+work1d.KKT[1859]*source[950];
  result[189] = work1d.KKT[1861]*source[189]+work1d.KKT[1390]*source[748]+work1d.KKT[1392]*source[749]+work1d.KKT[766]*source[863]+work1d.KKT[1580]*source[949]+work1d.KKT[1581]*source[952]+work1d.KKT[1862]*source[951];
  result[190] = work1d.KKT[1684]*source[190]+work1d.KKT[1685]*source[950]+work1d.KKT[1686]*source[953];
  result[191] = work1d.KKT[1864]*source[191]+work1d.KKT[1076]*source[631]+work1d.KKT[1078]*source[632]+work1d.KKT[688]*source[824]+work1d.KKT[1863]*source[951]+work1d.KKT[1866]*source[954]+work1d.KKT[1865]*source[953];
  result[192] = work1d.KKT[1867]*source[192]+work1d.KKT[1398]*source[751]+work1d.KKT[1400]*source[752]+work1d.KKT[768]*source[864]+work1d.KKT[1582]*source[952]+work1d.KKT[1583]*source[955]+work1d.KKT[1868]*source[954];
  result[193] = work1d.KKT[1687]*source[193]+work1d.KKT[1688]*source[953]+work1d.KKT[1689]*source[956];
  result[194] = work1d.KKT[1870]*source[194]+work1d.KKT[1084]*source[634]+work1d.KKT[1086]*source[635]+work1d.KKT[690]*source[825]+work1d.KKT[1869]*source[954]+work1d.KKT[1872]*source[957]+work1d.KKT[1871]*source[956];
  result[195] = work1d.KKT[1873]*source[195]+work1d.KKT[1406]*source[754]+work1d.KKT[1408]*source[755]+work1d.KKT[770]*source[865]+work1d.KKT[1584]*source[955]+work1d.KKT[1585]*source[958]+work1d.KKT[1874]*source[957];
  result[196] = work1d.KKT[1690]*source[196]+work1d.KKT[1691]*source[956]+work1d.KKT[1692]*source[959];
  result[197] = work1d.KKT[1876]*source[197]+work1d.KKT[1092]*source[637]+work1d.KKT[1094]*source[638]+work1d.KKT[692]*source[826]+work1d.KKT[1875]*source[957]+work1d.KKT[1878]*source[960]+work1d.KKT[1877]*source[959];
  result[198] = work1d.KKT[1879]*source[198]+work1d.KKT[1414]*source[757]+work1d.KKT[1416]*source[758]+work1d.KKT[772]*source[866]+work1d.KKT[1586]*source[958]+work1d.KKT[1587]*source[961]+work1d.KKT[1880]*source[960];
  result[199] = work1d.KKT[1693]*source[199]+work1d.KKT[1694]*source[959]+work1d.KKT[1695]*source[962];
  result[200] = work1d.KKT[1882]*source[200]+work1d.KKT[1100]*source[640]+work1d.KKT[1102]*source[641]+work1d.KKT[694]*source[827]+work1d.KKT[1881]*source[960]+work1d.KKT[1884]*source[963]+work1d.KKT[1883]*source[962];
  result[201] = work1d.KKT[1885]*source[201]+work1d.KKT[1422]*source[760]+work1d.KKT[1424]*source[761]+work1d.KKT[774]*source[867]+work1d.KKT[1588]*source[961]+work1d.KKT[1589]*source[964]+work1d.KKT[1886]*source[963];
  result[202] = work1d.KKT[1696]*source[202]+work1d.KKT[1697]*source[962]+work1d.KKT[1698]*source[965];
  result[203] = work1d.KKT[1888]*source[203]+work1d.KKT[1108]*source[643]+work1d.KKT[1110]*source[644]+work1d.KKT[696]*source[828]+work1d.KKT[1887]*source[963]+work1d.KKT[1890]*source[966]+work1d.KKT[1889]*source[965];
  result[204] = work1d.KKT[1891]*source[204]+work1d.KKT[1430]*source[763]+work1d.KKT[1432]*source[764]+work1d.KKT[776]*source[868]+work1d.KKT[1590]*source[964]+work1d.KKT[1591]*source[967]+work1d.KKT[1892]*source[966];
  result[205] = work1d.KKT[1699]*source[205]+work1d.KKT[1700]*source[965]+work1d.KKT[1701]*source[968];
  result[206] = work1d.KKT[1894]*source[206]+work1d.KKT[1116]*source[646]+work1d.KKT[1118]*source[647]+work1d.KKT[698]*source[829]+work1d.KKT[1893]*source[966]+work1d.KKT[1896]*source[969]+work1d.KKT[1895]*source[968];
  result[207] = work1d.KKT[1897]*source[207]+work1d.KKT[1438]*source[766]+work1d.KKT[1440]*source[767]+work1d.KKT[778]*source[869]+work1d.KKT[1592]*source[967]+work1d.KKT[1593]*source[970]+work1d.KKT[1898]*source[969];
  result[208] = work1d.KKT[1702]*source[208]+work1d.KKT[1703]*source[968]+work1d.KKT[1704]*source[971];
  result[209] = work1d.KKT[1900]*source[209]+work1d.KKT[1124]*source[649]+work1d.KKT[1126]*source[650]+work1d.KKT[700]*source[830]+work1d.KKT[1899]*source[969]+work1d.KKT[1902]*source[972]+work1d.KKT[1901]*source[971];
  result[210] = work1d.KKT[1903]*source[210]+work1d.KKT[1446]*source[769]+work1d.KKT[1448]*source[770]+work1d.KKT[780]*source[870]+work1d.KKT[1594]*source[970]+work1d.KKT[1595]*source[973]+work1d.KKT[1904]*source[972];
  result[211] = work1d.KKT[1705]*source[211]+work1d.KKT[1706]*source[971]+work1d.KKT[1707]*source[974];
  result[212] = work1d.KKT[1906]*source[212]+work1d.KKT[1132]*source[652]+work1d.KKT[1134]*source[653]+work1d.KKT[702]*source[831]+work1d.KKT[1905]*source[972]+work1d.KKT[1908]*source[975]+work1d.KKT[1907]*source[974];
  result[213] = work1d.KKT[1909]*source[213]+work1d.KKT[1454]*source[772]+work1d.KKT[1456]*source[773]+work1d.KKT[782]*source[871]+work1d.KKT[1596]*source[973]+work1d.KKT[1597]*source[976]+work1d.KKT[1910]*source[975];
  result[214] = work1d.KKT[1708]*source[214]+work1d.KKT[1709]*source[974]+work1d.KKT[1710]*source[977];
  result[215] = work1d.KKT[1912]*source[215]+work1d.KKT[1140]*source[655]+work1d.KKT[1142]*source[656]+work1d.KKT[704]*source[832]+work1d.KKT[1911]*source[975]+work1d.KKT[1914]*source[978]+work1d.KKT[1913]*source[977];
  result[216] = work1d.KKT[1915]*source[216]+work1d.KKT[1462]*source[775]+work1d.KKT[1464]*source[776]+work1d.KKT[784]*source[872]+work1d.KKT[1598]*source[976]+work1d.KKT[1599]*source[979]+work1d.KKT[1916]*source[978];
  result[217] = work1d.KKT[1711]*source[217]+work1d.KKT[1712]*source[977]+work1d.KKT[1713]*source[980];
  result[218] = work1d.KKT[1918]*source[218]+work1d.KKT[1148]*source[658]+work1d.KKT[1150]*source[659]+work1d.KKT[706]*source[833]+work1d.KKT[1917]*source[978]+work1d.KKT[1920]*source[981]+work1d.KKT[1919]*source[980];
  result[219] = work1d.KKT[1921]*source[219]+work1d.KKT[1470]*source[778]+work1d.KKT[1472]*source[779]+work1d.KKT[786]*source[873]+work1d.KKT[1600]*source[979]+work1d.KKT[1601]*source[982]+work1d.KKT[1922]*source[981];
  result[220] = work1d.KKT[1714]*source[220]+work1d.KKT[1715]*source[980]+work1d.KKT[1716]*source[983];
  result[221] = work1d.KKT[1924]*source[221]+work1d.KKT[1156]*source[661]+work1d.KKT[1158]*source[662]+work1d.KKT[708]*source[834]+work1d.KKT[1923]*source[981]+work1d.KKT[1926]*source[984]+work1d.KKT[1925]*source[983];
  result[222] = work1d.KKT[1927]*source[222]+work1d.KKT[1478]*source[781]+work1d.KKT[1480]*source[782]+work1d.KKT[788]*source[874]+work1d.KKT[1602]*source[982]+work1d.KKT[1603]*source[985]+work1d.KKT[1928]*source[984];
  result[223] = work1d.KKT[1717]*source[223]+work1d.KKT[1718]*source[983]+work1d.KKT[1719]*source[986];
  result[224] = work1d.KKT[1930]*source[224]+work1d.KKT[1164]*source[664]+work1d.KKT[1166]*source[665]+work1d.KKT[710]*source[835]+work1d.KKT[1929]*source[984]+work1d.KKT[1932]*source[987]+work1d.KKT[1931]*source[986];
  result[225] = work1d.KKT[1933]*source[225]+work1d.KKT[1486]*source[784]+work1d.KKT[1488]*source[785]+work1d.KKT[790]*source[875]+work1d.KKT[1604]*source[985]+work1d.KKT[1605]*source[988]+work1d.KKT[1934]*source[987];
  result[226] = work1d.KKT[1720]*source[226]+work1d.KKT[1721]*source[986]+work1d.KKT[1722]*source[989];
  result[227] = work1d.KKT[1936]*source[227]+work1d.KKT[1172]*source[667]+work1d.KKT[1174]*source[668]+work1d.KKT[712]*source[836]+work1d.KKT[1935]*source[987]+work1d.KKT[1938]*source[990]+work1d.KKT[1937]*source[989];
  result[228] = work1d.KKT[1939]*source[228]+work1d.KKT[1494]*source[787]+work1d.KKT[1496]*source[788]+work1d.KKT[792]*source[876]+work1d.KKT[1606]*source[988]+work1d.KKT[1607]*source[991]+work1d.KKT[1940]*source[990];
  result[229] = work1d.KKT[1723]*source[229]+work1d.KKT[1724]*source[989]+work1d.KKT[1725]*source[992];
  result[230] = work1d.KKT[1942]*source[230]+work1d.KKT[1180]*source[670]+work1d.KKT[1182]*source[671]+work1d.KKT[714]*source[837]+work1d.KKT[1941]*source[990]+work1d.KKT[1944]*source[993]+work1d.KKT[1943]*source[992];
  result[231] = work1d.KKT[1945]*source[231]+work1d.KKT[1502]*source[790]+work1d.KKT[1504]*source[791]+work1d.KKT[794]*source[877]+work1d.KKT[1608]*source[991]+work1d.KKT[1609]*source[994]+work1d.KKT[1946]*source[993];
  result[232] = work1d.KKT[1726]*source[232]+work1d.KKT[1727]*source[992]+work1d.KKT[1728]*source[995];
  result[233] = work1d.KKT[1952]*source[233]+work1d.KKT[1188]*source[673]+work1d.KKT[1190]*source[674]+work1d.KKT[716]*source[838]+work1d.KKT[1947]*source[993]+work1d.KKT[1949]*source[996]+work1d.KKT[1948]*source[995];
  result[234] = work1d.KKT[1953]*source[234]+work1d.KKT[1510]*source[793]+work1d.KKT[1512]*source[794]+work1d.KKT[796]*source[878]+work1d.KKT[1610]*source[994]+work1d.KKT[1611]*source[997]+work1d.KKT[1950]*source[996];
  result[235] = work1d.KKT[1729]*source[235]+work1d.KKT[1730]*source[995]+work1d.KKT[1612]*source[998];
  result[236] = work1d.KKT[1954]*source[236]+work1d.KKT[1196]*source[676]+work1d.KKT[1198]*source[677]+work1d.KKT[718]*source[839]+work1d.KKT[1951]*source[996]+work1d.KKT[1614]*source[999]+work1d.KKT[1613]*source[998];
  result[237] = work1d.KKT[1532]*source[237]+work1d.KKT[1518]*source[796]+work1d.KKT[1520]*source[797]+work1d.KKT[798]*source[879]+work1d.KKT[1533]*source[997]+work1d.KKT[1531]*source[1000]+work1d.KKT[1534]*source[999];
  result[238] = work1d.KKT[885]*source[238]+work1d.KKT[886]*source[998];
  result[239] = work1d.KKT[1207]*source[239]+work1d.KKT[1204]*source[679]+work1d.KKT[1206]*source[680]+work1d.KKT[720]*source[840]+work1d.KKT[1208]*source[999];
  result[240] = work1d.KKT[1529]*source[240]+work1d.KKT[1526]*source[799]+work1d.KKT[1528]*source[800]+work1d.KKT[800]*source[880]+work1d.KKT[1530]*source[1000];
  result[241] = work1d.KKT[1]*source[241]+work1d.KKT[2]*source[561];
  result[242] = work1d.KKT[3]*source[242]+work1d.KKT[4]*source[562];
  result[243] = work1d.KKT[5]*source[243]+work1d.KKT[6]*source[563];
  result[244] = work1d.KKT[7]*source[244]+work1d.KKT[8]*source[564];
  result[245] = work1d.KKT[9]*source[245]+work1d.KKT[10]*source[565];
  result[246] = work1d.KKT[11]*source[246]+work1d.KKT[12]*source[566];
  result[247] = work1d.KKT[13]*source[247]+work1d.KKT[14]*source[567];
  result[248] = work1d.KKT[15]*source[248]+work1d.KKT[16]*source[568];
  result[249] = work1d.KKT[17]*source[249]+work1d.KKT[18]*source[569];
  result[250] = work1d.KKT[19]*source[250]+work1d.KKT[20]*source[570];
  result[251] = work1d.KKT[21]*source[251]+work1d.KKT[22]*source[571];
  result[252] = work1d.KKT[23]*source[252]+work1d.KKT[24]*source[572];
  result[253] = work1d.KKT[25]*source[253]+work1d.KKT[26]*source[573];
  result[254] = work1d.KKT[27]*source[254]+work1d.KKT[28]*source[574];
  result[255] = work1d.KKT[29]*source[255]+work1d.KKT[30]*source[575];
  result[256] = work1d.KKT[31]*source[256]+work1d.KKT[32]*source[576];
  result[257] = work1d.KKT[33]*source[257]+work1d.KKT[34]*source[577];
  result[258] = work1d.KKT[35]*source[258]+work1d.KKT[36]*source[578];
  result[259] = work1d.KKT[37]*source[259]+work1d.KKT[38]*source[579];
  result[260] = work1d.KKT[39]*source[260]+work1d.KKT[40]*source[580];
  result[261] = work1d.KKT[41]*source[261]+work1d.KKT[42]*source[581];
  result[262] = work1d.KKT[43]*source[262]+work1d.KKT[44]*source[582];
  result[263] = work1d.KKT[45]*source[263]+work1d.KKT[46]*source[583];
  result[264] = work1d.KKT[47]*source[264]+work1d.KKT[48]*source[584];
  result[265] = work1d.KKT[49]*source[265]+work1d.KKT[50]*source[585];
  result[266] = work1d.KKT[51]*source[266]+work1d.KKT[52]*source[586];
  result[267] = work1d.KKT[53]*source[267]+work1d.KKT[54]*source[587];
  result[268] = work1d.KKT[55]*source[268]+work1d.KKT[56]*source[588];
  result[269] = work1d.KKT[57]*source[269]+work1d.KKT[58]*source[589];
  result[270] = work1d.KKT[59]*source[270]+work1d.KKT[60]*source[590];
  result[271] = work1d.KKT[61]*source[271]+work1d.KKT[62]*source[591];
  result[272] = work1d.KKT[63]*source[272]+work1d.KKT[64]*source[592];
  result[273] = work1d.KKT[65]*source[273]+work1d.KKT[66]*source[593];
  result[274] = work1d.KKT[67]*source[274]+work1d.KKT[68]*source[594];
  result[275] = work1d.KKT[69]*source[275]+work1d.KKT[70]*source[595];
  result[276] = work1d.KKT[71]*source[276]+work1d.KKT[72]*source[596];
  result[277] = work1d.KKT[73]*source[277]+work1d.KKT[74]*source[597];
  result[278] = work1d.KKT[75]*source[278]+work1d.KKT[76]*source[598];
  result[279] = work1d.KKT[77]*source[279]+work1d.KKT[78]*source[599];
  result[280] = work1d.KKT[79]*source[280]+work1d.KKT[80]*source[600];
  result[281] = work1d.KKT[81]*source[281]+work1d.KKT[82]*source[601];
  result[282] = work1d.KKT[83]*source[282]+work1d.KKT[84]*source[602];
  result[283] = work1d.KKT[85]*source[283]+work1d.KKT[86]*source[603];
  result[284] = work1d.KKT[87]*source[284]+work1d.KKT[88]*source[604];
  result[285] = work1d.KKT[89]*source[285]+work1d.KKT[90]*source[605];
  result[286] = work1d.KKT[91]*source[286]+work1d.KKT[92]*source[606];
  result[287] = work1d.KKT[93]*source[287]+work1d.KKT[94]*source[607];
  result[288] = work1d.KKT[95]*source[288]+work1d.KKT[96]*source[608];
  result[289] = work1d.KKT[97]*source[289]+work1d.KKT[98]*source[609];
  result[290] = work1d.KKT[99]*source[290]+work1d.KKT[100]*source[610];
  result[291] = work1d.KKT[101]*source[291]+work1d.KKT[102]*source[611];
  result[292] = work1d.KKT[103]*source[292]+work1d.KKT[104]*source[612];
  result[293] = work1d.KKT[105]*source[293]+work1d.KKT[106]*source[613];
  result[294] = work1d.KKT[107]*source[294]+work1d.KKT[108]*source[614];
  result[295] = work1d.KKT[109]*source[295]+work1d.KKT[110]*source[615];
  result[296] = work1d.KKT[111]*source[296]+work1d.KKT[112]*source[616];
  result[297] = work1d.KKT[113]*source[297]+work1d.KKT[114]*source[617];
  result[298] = work1d.KKT[115]*source[298]+work1d.KKT[116]*source[618];
  result[299] = work1d.KKT[117]*source[299]+work1d.KKT[118]*source[619];
  result[300] = work1d.KKT[119]*source[300]+work1d.KKT[120]*source[620];
  result[301] = work1d.KKT[121]*source[301]+work1d.KKT[122]*source[621];
  result[302] = work1d.KKT[123]*source[302]+work1d.KKT[124]*source[622];
  result[303] = work1d.KKT[125]*source[303]+work1d.KKT[126]*source[623];
  result[304] = work1d.KKT[127]*source[304]+work1d.KKT[128]*source[624];
  result[305] = work1d.KKT[129]*source[305]+work1d.KKT[130]*source[625];
  result[306] = work1d.KKT[131]*source[306]+work1d.KKT[132]*source[626];
  result[307] = work1d.KKT[133]*source[307]+work1d.KKT[134]*source[627];
  result[308] = work1d.KKT[135]*source[308]+work1d.KKT[136]*source[628];
  result[309] = work1d.KKT[137]*source[309]+work1d.KKT[138]*source[629];
  result[310] = work1d.KKT[139]*source[310]+work1d.KKT[140]*source[630];
  result[311] = work1d.KKT[141]*source[311]+work1d.KKT[142]*source[631];
  result[312] = work1d.KKT[143]*source[312]+work1d.KKT[144]*source[632];
  result[313] = work1d.KKT[145]*source[313]+work1d.KKT[146]*source[633];
  result[314] = work1d.KKT[147]*source[314]+work1d.KKT[148]*source[634];
  result[315] = work1d.KKT[149]*source[315]+work1d.KKT[150]*source[635];
  result[316] = work1d.KKT[151]*source[316]+work1d.KKT[152]*source[636];
  result[317] = work1d.KKT[153]*source[317]+work1d.KKT[154]*source[637];
  result[318] = work1d.KKT[155]*source[318]+work1d.KKT[156]*source[638];
  result[319] = work1d.KKT[157]*source[319]+work1d.KKT[158]*source[639];
  result[320] = work1d.KKT[159]*source[320]+work1d.KKT[160]*source[640];
  result[321] = work1d.KKT[161]*source[321]+work1d.KKT[162]*source[641];
  result[322] = work1d.KKT[163]*source[322]+work1d.KKT[164]*source[642];
  result[323] = work1d.KKT[165]*source[323]+work1d.KKT[166]*source[643];
  result[324] = work1d.KKT[167]*source[324]+work1d.KKT[168]*source[644];
  result[325] = work1d.KKT[169]*source[325]+work1d.KKT[170]*source[645];
  result[326] = work1d.KKT[171]*source[326]+work1d.KKT[172]*source[646];
  result[327] = work1d.KKT[173]*source[327]+work1d.KKT[174]*source[647];
  result[328] = work1d.KKT[175]*source[328]+work1d.KKT[176]*source[648];
  result[329] = work1d.KKT[177]*source[329]+work1d.KKT[178]*source[649];
  result[330] = work1d.KKT[179]*source[330]+work1d.KKT[180]*source[650];
  result[331] = work1d.KKT[181]*source[331]+work1d.KKT[182]*source[651];
  result[332] = work1d.KKT[183]*source[332]+work1d.KKT[184]*source[652];
  result[333] = work1d.KKT[185]*source[333]+work1d.KKT[186]*source[653];
  result[334] = work1d.KKT[187]*source[334]+work1d.KKT[188]*source[654];
  result[335] = work1d.KKT[189]*source[335]+work1d.KKT[190]*source[655];
  result[336] = work1d.KKT[191]*source[336]+work1d.KKT[192]*source[656];
  result[337] = work1d.KKT[193]*source[337]+work1d.KKT[194]*source[657];
  result[338] = work1d.KKT[195]*source[338]+work1d.KKT[196]*source[658];
  result[339] = work1d.KKT[197]*source[339]+work1d.KKT[198]*source[659];
  result[340] = work1d.KKT[199]*source[340]+work1d.KKT[200]*source[660];
  result[341] = work1d.KKT[201]*source[341]+work1d.KKT[202]*source[661];
  result[342] = work1d.KKT[203]*source[342]+work1d.KKT[204]*source[662];
  result[343] = work1d.KKT[205]*source[343]+work1d.KKT[206]*source[663];
  result[344] = work1d.KKT[207]*source[344]+work1d.KKT[208]*source[664];
  result[345] = work1d.KKT[209]*source[345]+work1d.KKT[210]*source[665];
  result[346] = work1d.KKT[211]*source[346]+work1d.KKT[212]*source[666];
  result[347] = work1d.KKT[213]*source[347]+work1d.KKT[214]*source[667];
  result[348] = work1d.KKT[215]*source[348]+work1d.KKT[216]*source[668];
  result[349] = work1d.KKT[217]*source[349]+work1d.KKT[218]*source[669];
  result[350] = work1d.KKT[219]*source[350]+work1d.KKT[220]*source[670];
  result[351] = work1d.KKT[221]*source[351]+work1d.KKT[222]*source[671];
  result[352] = work1d.KKT[223]*source[352]+work1d.KKT[224]*source[672];
  result[353] = work1d.KKT[225]*source[353]+work1d.KKT[226]*source[673];
  result[354] = work1d.KKT[227]*source[354]+work1d.KKT[228]*source[674];
  result[355] = work1d.KKT[229]*source[355]+work1d.KKT[230]*source[675];
  result[356] = work1d.KKT[231]*source[356]+work1d.KKT[232]*source[676];
  result[357] = work1d.KKT[233]*source[357]+work1d.KKT[234]*source[677];
  result[358] = work1d.KKT[235]*source[358]+work1d.KKT[236]*source[678];
  result[359] = work1d.KKT[237]*source[359]+work1d.KKT[238]*source[679];
  result[360] = work1d.KKT[239]*source[360]+work1d.KKT[240]*source[680];
  result[361] = work1d.KKT[241]*source[361]+work1d.KKT[242]*source[681];
  result[362] = work1d.KKT[243]*source[362]+work1d.KKT[244]*source[682];
  result[363] = work1d.KKT[245]*source[363]+work1d.KKT[246]*source[683];
  result[364] = work1d.KKT[247]*source[364]+work1d.KKT[248]*source[684];
  result[365] = work1d.KKT[249]*source[365]+work1d.KKT[250]*source[685];
  result[366] = work1d.KKT[251]*source[366]+work1d.KKT[252]*source[686];
  result[367] = work1d.KKT[253]*source[367]+work1d.KKT[254]*source[687];
  result[368] = work1d.KKT[255]*source[368]+work1d.KKT[256]*source[688];
  result[369] = work1d.KKT[257]*source[369]+work1d.KKT[258]*source[689];
  result[370] = work1d.KKT[259]*source[370]+work1d.KKT[260]*source[690];
  result[371] = work1d.KKT[261]*source[371]+work1d.KKT[262]*source[691];
  result[372] = work1d.KKT[263]*source[372]+work1d.KKT[264]*source[692];
  result[373] = work1d.KKT[265]*source[373]+work1d.KKT[266]*source[693];
  result[374] = work1d.KKT[267]*source[374]+work1d.KKT[268]*source[694];
  result[375] = work1d.KKT[269]*source[375]+work1d.KKT[270]*source[695];
  result[376] = work1d.KKT[271]*source[376]+work1d.KKT[272]*source[696];
  result[377] = work1d.KKT[273]*source[377]+work1d.KKT[274]*source[697];
  result[378] = work1d.KKT[275]*source[378]+work1d.KKT[276]*source[698];
  result[379] = work1d.KKT[277]*source[379]+work1d.KKT[278]*source[699];
  result[380] = work1d.KKT[279]*source[380]+work1d.KKT[280]*source[700];
  result[381] = work1d.KKT[281]*source[381]+work1d.KKT[282]*source[701];
  result[382] = work1d.KKT[283]*source[382]+work1d.KKT[284]*source[702];
  result[383] = work1d.KKT[285]*source[383]+work1d.KKT[286]*source[703];
  result[384] = work1d.KKT[287]*source[384]+work1d.KKT[288]*source[704];
  result[385] = work1d.KKT[289]*source[385]+work1d.KKT[290]*source[705];
  result[386] = work1d.KKT[291]*source[386]+work1d.KKT[292]*source[706];
  result[387] = work1d.KKT[293]*source[387]+work1d.KKT[294]*source[707];
  result[388] = work1d.KKT[295]*source[388]+work1d.KKT[296]*source[708];
  result[389] = work1d.KKT[297]*source[389]+work1d.KKT[298]*source[709];
  result[390] = work1d.KKT[299]*source[390]+work1d.KKT[300]*source[710];
  result[391] = work1d.KKT[301]*source[391]+work1d.KKT[302]*source[711];
  result[392] = work1d.KKT[303]*source[392]+work1d.KKT[304]*source[712];
  result[393] = work1d.KKT[305]*source[393]+work1d.KKT[306]*source[713];
  result[394] = work1d.KKT[307]*source[394]+work1d.KKT[308]*source[714];
  result[395] = work1d.KKT[309]*source[395]+work1d.KKT[310]*source[715];
  result[396] = work1d.KKT[311]*source[396]+work1d.KKT[312]*source[716];
  result[397] = work1d.KKT[313]*source[397]+work1d.KKT[314]*source[717];
  result[398] = work1d.KKT[315]*source[398]+work1d.KKT[316]*source[718];
  result[399] = work1d.KKT[317]*source[399]+work1d.KKT[318]*source[719];
  result[400] = work1d.KKT[319]*source[400]+work1d.KKT[320]*source[720];
  result[401] = work1d.KKT[321]*source[401]+work1d.KKT[322]*source[721];
  result[402] = work1d.KKT[323]*source[402]+work1d.KKT[324]*source[722];
  result[403] = work1d.KKT[325]*source[403]+work1d.KKT[326]*source[723];
  result[404] = work1d.KKT[327]*source[404]+work1d.KKT[328]*source[724];
  result[405] = work1d.KKT[329]*source[405]+work1d.KKT[330]*source[725];
  result[406] = work1d.KKT[331]*source[406]+work1d.KKT[332]*source[726];
  result[407] = work1d.KKT[333]*source[407]+work1d.KKT[334]*source[727];
  result[408] = work1d.KKT[335]*source[408]+work1d.KKT[336]*source[728];
  result[409] = work1d.KKT[337]*source[409]+work1d.KKT[338]*source[729];
  result[410] = work1d.KKT[339]*source[410]+work1d.KKT[340]*source[730];
  result[411] = work1d.KKT[341]*source[411]+work1d.KKT[342]*source[731];
  result[412] = work1d.KKT[343]*source[412]+work1d.KKT[344]*source[732];
  result[413] = work1d.KKT[345]*source[413]+work1d.KKT[346]*source[733];
  result[414] = work1d.KKT[347]*source[414]+work1d.KKT[348]*source[734];
  result[415] = work1d.KKT[349]*source[415]+work1d.KKT[350]*source[735];
  result[416] = work1d.KKT[351]*source[416]+work1d.KKT[352]*source[736];
  result[417] = work1d.KKT[353]*source[417]+work1d.KKT[354]*source[737];
  result[418] = work1d.KKT[355]*source[418]+work1d.KKT[356]*source[738];
  result[419] = work1d.KKT[357]*source[419]+work1d.KKT[358]*source[739];
  result[420] = work1d.KKT[359]*source[420]+work1d.KKT[360]*source[740];
  result[421] = work1d.KKT[361]*source[421]+work1d.KKT[362]*source[741];
  result[422] = work1d.KKT[363]*source[422]+work1d.KKT[364]*source[742];
  result[423] = work1d.KKT[365]*source[423]+work1d.KKT[366]*source[743];
  result[424] = work1d.KKT[367]*source[424]+work1d.KKT[368]*source[744];
  result[425] = work1d.KKT[369]*source[425]+work1d.KKT[370]*source[745];
  result[426] = work1d.KKT[371]*source[426]+work1d.KKT[372]*source[746];
  result[427] = work1d.KKT[373]*source[427]+work1d.KKT[374]*source[747];
  result[428] = work1d.KKT[375]*source[428]+work1d.KKT[376]*source[748];
  result[429] = work1d.KKT[377]*source[429]+work1d.KKT[378]*source[749];
  result[430] = work1d.KKT[379]*source[430]+work1d.KKT[380]*source[750];
  result[431] = work1d.KKT[381]*source[431]+work1d.KKT[382]*source[751];
  result[432] = work1d.KKT[383]*source[432]+work1d.KKT[384]*source[752];
  result[433] = work1d.KKT[385]*source[433]+work1d.KKT[386]*source[753];
  result[434] = work1d.KKT[387]*source[434]+work1d.KKT[388]*source[754];
  result[435] = work1d.KKT[389]*source[435]+work1d.KKT[390]*source[755];
  result[436] = work1d.KKT[391]*source[436]+work1d.KKT[392]*source[756];
  result[437] = work1d.KKT[393]*source[437]+work1d.KKT[394]*source[757];
  result[438] = work1d.KKT[395]*source[438]+work1d.KKT[396]*source[758];
  result[439] = work1d.KKT[397]*source[439]+work1d.KKT[398]*source[759];
  result[440] = work1d.KKT[399]*source[440]+work1d.KKT[400]*source[760];
  result[441] = work1d.KKT[401]*source[441]+work1d.KKT[402]*source[761];
  result[442] = work1d.KKT[403]*source[442]+work1d.KKT[404]*source[762];
  result[443] = work1d.KKT[405]*source[443]+work1d.KKT[406]*source[763];
  result[444] = work1d.KKT[407]*source[444]+work1d.KKT[408]*source[764];
  result[445] = work1d.KKT[409]*source[445]+work1d.KKT[410]*source[765];
  result[446] = work1d.KKT[411]*source[446]+work1d.KKT[412]*source[766];
  result[447] = work1d.KKT[413]*source[447]+work1d.KKT[414]*source[767];
  result[448] = work1d.KKT[415]*source[448]+work1d.KKT[416]*source[768];
  result[449] = work1d.KKT[417]*source[449]+work1d.KKT[418]*source[769];
  result[450] = work1d.KKT[419]*source[450]+work1d.KKT[420]*source[770];
  result[451] = work1d.KKT[421]*source[451]+work1d.KKT[422]*source[771];
  result[452] = work1d.KKT[423]*source[452]+work1d.KKT[424]*source[772];
  result[453] = work1d.KKT[425]*source[453]+work1d.KKT[426]*source[773];
  result[454] = work1d.KKT[427]*source[454]+work1d.KKT[428]*source[774];
  result[455] = work1d.KKT[429]*source[455]+work1d.KKT[430]*source[775];
  result[456] = work1d.KKT[431]*source[456]+work1d.KKT[432]*source[776];
  result[457] = work1d.KKT[433]*source[457]+work1d.KKT[434]*source[777];
  result[458] = work1d.KKT[435]*source[458]+work1d.KKT[436]*source[778];
  result[459] = work1d.KKT[437]*source[459]+work1d.KKT[438]*source[779];
  result[460] = work1d.KKT[439]*source[460]+work1d.KKT[440]*source[780];
  result[461] = work1d.KKT[441]*source[461]+work1d.KKT[442]*source[781];
  result[462] = work1d.KKT[443]*source[462]+work1d.KKT[444]*source[782];
  result[463] = work1d.KKT[445]*source[463]+work1d.KKT[446]*source[783];
  result[464] = work1d.KKT[447]*source[464]+work1d.KKT[448]*source[784];
  result[465] = work1d.KKT[449]*source[465]+work1d.KKT[450]*source[785];
  result[466] = work1d.KKT[451]*source[466]+work1d.KKT[452]*source[786];
  result[467] = work1d.KKT[453]*source[467]+work1d.KKT[454]*source[787];
  result[468] = work1d.KKT[455]*source[468]+work1d.KKT[456]*source[788];
  result[469] = work1d.KKT[457]*source[469]+work1d.KKT[458]*source[789];
  result[470] = work1d.KKT[459]*source[470]+work1d.KKT[460]*source[790];
  result[471] = work1d.KKT[461]*source[471]+work1d.KKT[462]*source[791];
  result[472] = work1d.KKT[463]*source[472]+work1d.KKT[464]*source[792];
  result[473] = work1d.KKT[465]*source[473]+work1d.KKT[466]*source[793];
  result[474] = work1d.KKT[467]*source[474]+work1d.KKT[468]*source[794];
  result[475] = work1d.KKT[469]*source[475]+work1d.KKT[470]*source[795];
  result[476] = work1d.KKT[471]*source[476]+work1d.KKT[472]*source[796];
  result[477] = work1d.KKT[473]*source[477]+work1d.KKT[474]*source[797];
  result[478] = work1d.KKT[475]*source[478]+work1d.KKT[476]*source[798];
  result[479] = work1d.KKT[477]*source[479]+work1d.KKT[478]*source[799];
  result[480] = work1d.KKT[479]*source[480]+work1d.KKT[480]*source[800];
  result[481] = work1d.KKT[481]*source[481]+work1d.KKT[482]*source[801];
  result[482] = work1d.KKT[483]*source[482]+work1d.KKT[484]*source[802];
  result[483] = work1d.KKT[485]*source[483]+work1d.KKT[486]*source[803];
  result[484] = work1d.KKT[487]*source[484]+work1d.KKT[488]*source[804];
  result[485] = work1d.KKT[489]*source[485]+work1d.KKT[490]*source[805];
  result[486] = work1d.KKT[491]*source[486]+work1d.KKT[492]*source[806];
  result[487] = work1d.KKT[493]*source[487]+work1d.KKT[494]*source[807];
  result[488] = work1d.KKT[495]*source[488]+work1d.KKT[496]*source[808];
  result[489] = work1d.KKT[497]*source[489]+work1d.KKT[498]*source[809];
  result[490] = work1d.KKT[499]*source[490]+work1d.KKT[500]*source[810];
  result[491] = work1d.KKT[501]*source[491]+work1d.KKT[502]*source[811];
  result[492] = work1d.KKT[503]*source[492]+work1d.KKT[504]*source[812];
  result[493] = work1d.KKT[505]*source[493]+work1d.KKT[506]*source[813];
  result[494] = work1d.KKT[507]*source[494]+work1d.KKT[508]*source[814];
  result[495] = work1d.KKT[509]*source[495]+work1d.KKT[510]*source[815];
  result[496] = work1d.KKT[511]*source[496]+work1d.KKT[512]*source[816];
  result[497] = work1d.KKT[513]*source[497]+work1d.KKT[514]*source[817];
  result[498] = work1d.KKT[515]*source[498]+work1d.KKT[516]*source[818];
  result[499] = work1d.KKT[517]*source[499]+work1d.KKT[518]*source[819];
  result[500] = work1d.KKT[519]*source[500]+work1d.KKT[520]*source[820];
  result[501] = work1d.KKT[521]*source[501]+work1d.KKT[522]*source[821];
  result[502] = work1d.KKT[523]*source[502]+work1d.KKT[524]*source[822];
  result[503] = work1d.KKT[525]*source[503]+work1d.KKT[526]*source[823];
  result[504] = work1d.KKT[527]*source[504]+work1d.KKT[528]*source[824];
  result[505] = work1d.KKT[529]*source[505]+work1d.KKT[530]*source[825];
  result[506] = work1d.KKT[531]*source[506]+work1d.KKT[532]*source[826];
  result[507] = work1d.KKT[533]*source[507]+work1d.KKT[534]*source[827];
  result[508] = work1d.KKT[535]*source[508]+work1d.KKT[536]*source[828];
  result[509] = work1d.KKT[537]*source[509]+work1d.KKT[538]*source[829];
  result[510] = work1d.KKT[539]*source[510]+work1d.KKT[540]*source[830];
  result[511] = work1d.KKT[541]*source[511]+work1d.KKT[542]*source[831];
  result[512] = work1d.KKT[543]*source[512]+work1d.KKT[544]*source[832];
  result[513] = work1d.KKT[545]*source[513]+work1d.KKT[546]*source[833];
  result[514] = work1d.KKT[547]*source[514]+work1d.KKT[548]*source[834];
  result[515] = work1d.KKT[549]*source[515]+work1d.KKT[550]*source[835];
  result[516] = work1d.KKT[551]*source[516]+work1d.KKT[552]*source[836];
  result[517] = work1d.KKT[553]*source[517]+work1d.KKT[554]*source[837];
  result[518] = work1d.KKT[555]*source[518]+work1d.KKT[556]*source[838];
  result[519] = work1d.KKT[557]*source[519]+work1d.KKT[558]*source[839];
  result[520] = work1d.KKT[559]*source[520]+work1d.KKT[560]*source[840];
  result[521] = work1d.KKT[561]*source[521]+work1d.KKT[562]*source[841];
  result[522] = work1d.KKT[563]*source[522]+work1d.KKT[564]*source[842];
  result[523] = work1d.KKT[565]*source[523]+work1d.KKT[566]*source[843];
  result[524] = work1d.KKT[567]*source[524]+work1d.KKT[568]*source[844];
  result[525] = work1d.KKT[569]*source[525]+work1d.KKT[570]*source[845];
  result[526] = work1d.KKT[571]*source[526]+work1d.KKT[572]*source[846];
  result[527] = work1d.KKT[573]*source[527]+work1d.KKT[574]*source[847];
  result[528] = work1d.KKT[575]*source[528]+work1d.KKT[576]*source[848];
  result[529] = work1d.KKT[577]*source[529]+work1d.KKT[578]*source[849];
  result[530] = work1d.KKT[579]*source[530]+work1d.KKT[580]*source[850];
  result[531] = work1d.KKT[581]*source[531]+work1d.KKT[582]*source[851];
  result[532] = work1d.KKT[583]*source[532]+work1d.KKT[584]*source[852];
  result[533] = work1d.KKT[585]*source[533]+work1d.KKT[586]*source[853];
  result[534] = work1d.KKT[587]*source[534]+work1d.KKT[588]*source[854];
  result[535] = work1d.KKT[589]*source[535]+work1d.KKT[590]*source[855];
  result[536] = work1d.KKT[591]*source[536]+work1d.KKT[592]*source[856];
  result[537] = work1d.KKT[593]*source[537]+work1d.KKT[594]*source[857];
  result[538] = work1d.KKT[595]*source[538]+work1d.KKT[596]*source[858];
  result[539] = work1d.KKT[597]*source[539]+work1d.KKT[598]*source[859];
  result[540] = work1d.KKT[599]*source[540]+work1d.KKT[600]*source[860];
  result[541] = work1d.KKT[601]*source[541]+work1d.KKT[602]*source[861];
  result[542] = work1d.KKT[603]*source[542]+work1d.KKT[604]*source[862];
  result[543] = work1d.KKT[605]*source[543]+work1d.KKT[606]*source[863];
  result[544] = work1d.KKT[607]*source[544]+work1d.KKT[608]*source[864];
  result[545] = work1d.KKT[609]*source[545]+work1d.KKT[610]*source[865];
  result[546] = work1d.KKT[611]*source[546]+work1d.KKT[612]*source[866];
  result[547] = work1d.KKT[613]*source[547]+work1d.KKT[614]*source[867];
  result[548] = work1d.KKT[615]*source[548]+work1d.KKT[616]*source[868];
  result[549] = work1d.KKT[617]*source[549]+work1d.KKT[618]*source[869];
  result[550] = work1d.KKT[619]*source[550]+work1d.KKT[620]*source[870];
  result[551] = work1d.KKT[621]*source[551]+work1d.KKT[622]*source[871];
  result[552] = work1d.KKT[623]*source[552]+work1d.KKT[624]*source[872];
  result[553] = work1d.KKT[625]*source[553]+work1d.KKT[626]*source[873];
  result[554] = work1d.KKT[627]*source[554]+work1d.KKT[628]*source[874];
  result[555] = work1d.KKT[629]*source[555]+work1d.KKT[630]*source[875];
  result[556] = work1d.KKT[631]*source[556]+work1d.KKT[632]*source[876];
  result[557] = work1d.KKT[633]*source[557]+work1d.KKT[634]*source[877];
  result[558] = work1d.KKT[635]*source[558]+work1d.KKT[636]*source[878];
  result[559] = work1d.KKT[637]*source[559]+work1d.KKT[638]*source[879];
  result[560] = work1d.KKT[639]*source[560]+work1d.KKT[640]*source[880];
  result[561] = work1d.KKT[2]*source[241]+work1d.KKT[887]*source[561]+work1d.KKT[888]*source[0];
  result[562] = work1d.KKT[4]*source[242]+work1d.KKT[891]*source[562]+work1d.KKT[889]*source[0]+work1d.KKT[892]*source[122];
  result[563] = work1d.KKT[6]*source[243]+work1d.KKT[893]*source[563]+work1d.KKT[890]*source[0]+work1d.KKT[894]*source[122];
  result[564] = work1d.KKT[8]*source[244]+work1d.KKT[895]*source[564]+work1d.KKT[896]*source[1];
  result[565] = work1d.KKT[10]*source[245]+work1d.KKT[899]*source[565]+work1d.KKT[897]*source[1]+work1d.KKT[900]*source[125];
  result[566] = work1d.KKT[12]*source[246]+work1d.KKT[901]*source[566]+work1d.KKT[898]*source[1]+work1d.KKT[902]*source[125];
  result[567] = work1d.KKT[14]*source[247]+work1d.KKT[903]*source[567]+work1d.KKT[904]*source[2];
  result[568] = work1d.KKT[16]*source[248]+work1d.KKT[907]*source[568]+work1d.KKT[905]*source[2]+work1d.KKT[908]*source[128];
  result[569] = work1d.KKT[18]*source[249]+work1d.KKT[909]*source[569]+work1d.KKT[906]*source[2]+work1d.KKT[910]*source[128];
  result[570] = work1d.KKT[20]*source[250]+work1d.KKT[911]*source[570]+work1d.KKT[912]*source[3];
  result[571] = work1d.KKT[22]*source[251]+work1d.KKT[915]*source[571]+work1d.KKT[913]*source[3]+work1d.KKT[916]*source[131];
  result[572] = work1d.KKT[24]*source[252]+work1d.KKT[917]*source[572]+work1d.KKT[914]*source[3]+work1d.KKT[918]*source[131];
  result[573] = work1d.KKT[26]*source[253]+work1d.KKT[919]*source[573]+work1d.KKT[920]*source[4];
  result[574] = work1d.KKT[28]*source[254]+work1d.KKT[923]*source[574]+work1d.KKT[921]*source[4]+work1d.KKT[924]*source[134];
  result[575] = work1d.KKT[30]*source[255]+work1d.KKT[925]*source[575]+work1d.KKT[922]*source[4]+work1d.KKT[926]*source[134];
  result[576] = work1d.KKT[32]*source[256]+work1d.KKT[927]*source[576]+work1d.KKT[928]*source[5];
  result[577] = work1d.KKT[34]*source[257]+work1d.KKT[931]*source[577]+work1d.KKT[929]*source[5]+work1d.KKT[932]*source[137];
  result[578] = work1d.KKT[36]*source[258]+work1d.KKT[933]*source[578]+work1d.KKT[930]*source[5]+work1d.KKT[934]*source[137];
  result[579] = work1d.KKT[38]*source[259]+work1d.KKT[935]*source[579]+work1d.KKT[936]*source[6];
  result[580] = work1d.KKT[40]*source[260]+work1d.KKT[939]*source[580]+work1d.KKT[937]*source[6]+work1d.KKT[940]*source[140];
  result[581] = work1d.KKT[42]*source[261]+work1d.KKT[941]*source[581]+work1d.KKT[938]*source[6]+work1d.KKT[942]*source[140];
  result[582] = work1d.KKT[44]*source[262]+work1d.KKT[943]*source[582]+work1d.KKT[944]*source[7];
  result[583] = work1d.KKT[46]*source[263]+work1d.KKT[947]*source[583]+work1d.KKT[945]*source[7]+work1d.KKT[948]*source[143];
  result[584] = work1d.KKT[48]*source[264]+work1d.KKT[949]*source[584]+work1d.KKT[946]*source[7]+work1d.KKT[950]*source[143];
  result[585] = work1d.KKT[50]*source[265]+work1d.KKT[951]*source[585]+work1d.KKT[952]*source[8];
  result[586] = work1d.KKT[52]*source[266]+work1d.KKT[955]*source[586]+work1d.KKT[953]*source[8]+work1d.KKT[956]*source[146];
  result[587] = work1d.KKT[54]*source[267]+work1d.KKT[957]*source[587]+work1d.KKT[954]*source[8]+work1d.KKT[958]*source[146];
  result[588] = work1d.KKT[56]*source[268]+work1d.KKT[959]*source[588]+work1d.KKT[960]*source[9];
  result[589] = work1d.KKT[58]*source[269]+work1d.KKT[963]*source[589]+work1d.KKT[961]*source[9]+work1d.KKT[964]*source[149];
  result[590] = work1d.KKT[60]*source[270]+work1d.KKT[965]*source[590]+work1d.KKT[962]*source[9]+work1d.KKT[966]*source[149];
  result[591] = work1d.KKT[62]*source[271]+work1d.KKT[967]*source[591]+work1d.KKT[968]*source[10];
  result[592] = work1d.KKT[64]*source[272]+work1d.KKT[971]*source[592]+work1d.KKT[969]*source[10]+work1d.KKT[972]*source[152];
  result[593] = work1d.KKT[66]*source[273]+work1d.KKT[973]*source[593]+work1d.KKT[970]*source[10]+work1d.KKT[974]*source[152];
  result[594] = work1d.KKT[68]*source[274]+work1d.KKT[975]*source[594]+work1d.KKT[976]*source[11];
  result[595] = work1d.KKT[70]*source[275]+work1d.KKT[979]*source[595]+work1d.KKT[977]*source[11]+work1d.KKT[980]*source[155];
  result[596] = work1d.KKT[72]*source[276]+work1d.KKT[981]*source[596]+work1d.KKT[978]*source[11]+work1d.KKT[982]*source[155];
  result[597] = work1d.KKT[74]*source[277]+work1d.KKT[983]*source[597]+work1d.KKT[984]*source[12];
  result[598] = work1d.KKT[76]*source[278]+work1d.KKT[987]*source[598]+work1d.KKT[985]*source[12]+work1d.KKT[988]*source[158];
  result[599] = work1d.KKT[78]*source[279]+work1d.KKT[989]*source[599]+work1d.KKT[986]*source[12]+work1d.KKT[990]*source[158];
  result[600] = work1d.KKT[80]*source[280]+work1d.KKT[991]*source[600]+work1d.KKT[992]*source[13];
  result[601] = work1d.KKT[82]*source[281]+work1d.KKT[995]*source[601]+work1d.KKT[993]*source[13]+work1d.KKT[996]*source[161];
  result[602] = work1d.KKT[84]*source[282]+work1d.KKT[997]*source[602]+work1d.KKT[994]*source[13]+work1d.KKT[998]*source[161];
  result[603] = work1d.KKT[86]*source[283]+work1d.KKT[999]*source[603]+work1d.KKT[1000]*source[14];
  result[604] = work1d.KKT[88]*source[284]+work1d.KKT[1003]*source[604]+work1d.KKT[1001]*source[14]+work1d.KKT[1004]*source[164];
  result[605] = work1d.KKT[90]*source[285]+work1d.KKT[1005]*source[605]+work1d.KKT[1002]*source[14]+work1d.KKT[1006]*source[164];
  result[606] = work1d.KKT[92]*source[286]+work1d.KKT[1007]*source[606]+work1d.KKT[1008]*source[15];
  result[607] = work1d.KKT[94]*source[287]+work1d.KKT[1011]*source[607]+work1d.KKT[1009]*source[15]+work1d.KKT[1012]*source[167];
  result[608] = work1d.KKT[96]*source[288]+work1d.KKT[1013]*source[608]+work1d.KKT[1010]*source[15]+work1d.KKT[1014]*source[167];
  result[609] = work1d.KKT[98]*source[289]+work1d.KKT[1015]*source[609]+work1d.KKT[1016]*source[16];
  result[610] = work1d.KKT[100]*source[290]+work1d.KKT[1019]*source[610]+work1d.KKT[1017]*source[16]+work1d.KKT[1020]*source[170];
  result[611] = work1d.KKT[102]*source[291]+work1d.KKT[1021]*source[611]+work1d.KKT[1018]*source[16]+work1d.KKT[1022]*source[170];
  result[612] = work1d.KKT[104]*source[292]+work1d.KKT[1023]*source[612]+work1d.KKT[1024]*source[17];
  result[613] = work1d.KKT[106]*source[293]+work1d.KKT[1027]*source[613]+work1d.KKT[1025]*source[17]+work1d.KKT[1028]*source[173];
  result[614] = work1d.KKT[108]*source[294]+work1d.KKT[1029]*source[614]+work1d.KKT[1026]*source[17]+work1d.KKT[1030]*source[173];
  result[615] = work1d.KKT[110]*source[295]+work1d.KKT[1031]*source[615]+work1d.KKT[1032]*source[18];
  result[616] = work1d.KKT[112]*source[296]+work1d.KKT[1035]*source[616]+work1d.KKT[1033]*source[18]+work1d.KKT[1036]*source[176];
  result[617] = work1d.KKT[114]*source[297]+work1d.KKT[1037]*source[617]+work1d.KKT[1034]*source[18]+work1d.KKT[1038]*source[176];
  result[618] = work1d.KKT[116]*source[298]+work1d.KKT[1039]*source[618]+work1d.KKT[1040]*source[19];
  result[619] = work1d.KKT[118]*source[299]+work1d.KKT[1043]*source[619]+work1d.KKT[1041]*source[19]+work1d.KKT[1044]*source[179];
  result[620] = work1d.KKT[120]*source[300]+work1d.KKT[1045]*source[620]+work1d.KKT[1042]*source[19]+work1d.KKT[1046]*source[179];
  result[621] = work1d.KKT[122]*source[301]+work1d.KKT[1047]*source[621]+work1d.KKT[1048]*source[20];
  result[622] = work1d.KKT[124]*source[302]+work1d.KKT[1051]*source[622]+work1d.KKT[1049]*source[20]+work1d.KKT[1052]*source[182];
  result[623] = work1d.KKT[126]*source[303]+work1d.KKT[1053]*source[623]+work1d.KKT[1050]*source[20]+work1d.KKT[1054]*source[182];
  result[624] = work1d.KKT[128]*source[304]+work1d.KKT[1055]*source[624]+work1d.KKT[1056]*source[21];
  result[625] = work1d.KKT[130]*source[305]+work1d.KKT[1059]*source[625]+work1d.KKT[1057]*source[21]+work1d.KKT[1060]*source[185];
  result[626] = work1d.KKT[132]*source[306]+work1d.KKT[1061]*source[626]+work1d.KKT[1058]*source[21]+work1d.KKT[1062]*source[185];
  result[627] = work1d.KKT[134]*source[307]+work1d.KKT[1063]*source[627]+work1d.KKT[1064]*source[22];
  result[628] = work1d.KKT[136]*source[308]+work1d.KKT[1067]*source[628]+work1d.KKT[1065]*source[22]+work1d.KKT[1068]*source[188];
  result[629] = work1d.KKT[138]*source[309]+work1d.KKT[1069]*source[629]+work1d.KKT[1066]*source[22]+work1d.KKT[1070]*source[188];
  result[630] = work1d.KKT[140]*source[310]+work1d.KKT[1071]*source[630]+work1d.KKT[1072]*source[23];
  result[631] = work1d.KKT[142]*source[311]+work1d.KKT[1075]*source[631]+work1d.KKT[1073]*source[23]+work1d.KKT[1076]*source[191];
  result[632] = work1d.KKT[144]*source[312]+work1d.KKT[1077]*source[632]+work1d.KKT[1074]*source[23]+work1d.KKT[1078]*source[191];
  result[633] = work1d.KKT[146]*source[313]+work1d.KKT[1079]*source[633]+work1d.KKT[1080]*source[24];
  result[634] = work1d.KKT[148]*source[314]+work1d.KKT[1083]*source[634]+work1d.KKT[1081]*source[24]+work1d.KKT[1084]*source[194];
  result[635] = work1d.KKT[150]*source[315]+work1d.KKT[1085]*source[635]+work1d.KKT[1082]*source[24]+work1d.KKT[1086]*source[194];
  result[636] = work1d.KKT[152]*source[316]+work1d.KKT[1087]*source[636]+work1d.KKT[1088]*source[25];
  result[637] = work1d.KKT[154]*source[317]+work1d.KKT[1091]*source[637]+work1d.KKT[1089]*source[25]+work1d.KKT[1092]*source[197];
  result[638] = work1d.KKT[156]*source[318]+work1d.KKT[1093]*source[638]+work1d.KKT[1090]*source[25]+work1d.KKT[1094]*source[197];
  result[639] = work1d.KKT[158]*source[319]+work1d.KKT[1095]*source[639]+work1d.KKT[1096]*source[26];
  result[640] = work1d.KKT[160]*source[320]+work1d.KKT[1099]*source[640]+work1d.KKT[1097]*source[26]+work1d.KKT[1100]*source[200];
  result[641] = work1d.KKT[162]*source[321]+work1d.KKT[1101]*source[641]+work1d.KKT[1098]*source[26]+work1d.KKT[1102]*source[200];
  result[642] = work1d.KKT[164]*source[322]+work1d.KKT[1103]*source[642]+work1d.KKT[1104]*source[27];
  result[643] = work1d.KKT[166]*source[323]+work1d.KKT[1107]*source[643]+work1d.KKT[1105]*source[27]+work1d.KKT[1108]*source[203];
  result[644] = work1d.KKT[168]*source[324]+work1d.KKT[1109]*source[644]+work1d.KKT[1106]*source[27]+work1d.KKT[1110]*source[203];
  result[645] = work1d.KKT[170]*source[325]+work1d.KKT[1111]*source[645]+work1d.KKT[1112]*source[28];
  result[646] = work1d.KKT[172]*source[326]+work1d.KKT[1115]*source[646]+work1d.KKT[1113]*source[28]+work1d.KKT[1116]*source[206];
  result[647] = work1d.KKT[174]*source[327]+work1d.KKT[1117]*source[647]+work1d.KKT[1114]*source[28]+work1d.KKT[1118]*source[206];
  result[648] = work1d.KKT[176]*source[328]+work1d.KKT[1119]*source[648]+work1d.KKT[1120]*source[29];
  result[649] = work1d.KKT[178]*source[329]+work1d.KKT[1123]*source[649]+work1d.KKT[1121]*source[29]+work1d.KKT[1124]*source[209];
  result[650] = work1d.KKT[180]*source[330]+work1d.KKT[1125]*source[650]+work1d.KKT[1122]*source[29]+work1d.KKT[1126]*source[209];
  result[651] = work1d.KKT[182]*source[331]+work1d.KKT[1127]*source[651]+work1d.KKT[1128]*source[30];
  result[652] = work1d.KKT[184]*source[332]+work1d.KKT[1131]*source[652]+work1d.KKT[1129]*source[30]+work1d.KKT[1132]*source[212];
  result[653] = work1d.KKT[186]*source[333]+work1d.KKT[1133]*source[653]+work1d.KKT[1130]*source[30]+work1d.KKT[1134]*source[212];
  result[654] = work1d.KKT[188]*source[334]+work1d.KKT[1135]*source[654]+work1d.KKT[1136]*source[31];
  result[655] = work1d.KKT[190]*source[335]+work1d.KKT[1139]*source[655]+work1d.KKT[1137]*source[31]+work1d.KKT[1140]*source[215];
  result[656] = work1d.KKT[192]*source[336]+work1d.KKT[1141]*source[656]+work1d.KKT[1138]*source[31]+work1d.KKT[1142]*source[215];
  result[657] = work1d.KKT[194]*source[337]+work1d.KKT[1143]*source[657]+work1d.KKT[1144]*source[32];
  result[658] = work1d.KKT[196]*source[338]+work1d.KKT[1147]*source[658]+work1d.KKT[1145]*source[32]+work1d.KKT[1148]*source[218];
  result[659] = work1d.KKT[198]*source[339]+work1d.KKT[1149]*source[659]+work1d.KKT[1146]*source[32]+work1d.KKT[1150]*source[218];
  result[660] = work1d.KKT[200]*source[340]+work1d.KKT[1151]*source[660]+work1d.KKT[1152]*source[33];
  result[661] = work1d.KKT[202]*source[341]+work1d.KKT[1155]*source[661]+work1d.KKT[1153]*source[33]+work1d.KKT[1156]*source[221];
  result[662] = work1d.KKT[204]*source[342]+work1d.KKT[1157]*source[662]+work1d.KKT[1154]*source[33]+work1d.KKT[1158]*source[221];
  result[663] = work1d.KKT[206]*source[343]+work1d.KKT[1159]*source[663]+work1d.KKT[1160]*source[34];
  result[664] = work1d.KKT[208]*source[344]+work1d.KKT[1163]*source[664]+work1d.KKT[1161]*source[34]+work1d.KKT[1164]*source[224];
  result[665] = work1d.KKT[210]*source[345]+work1d.KKT[1165]*source[665]+work1d.KKT[1162]*source[34]+work1d.KKT[1166]*source[224];
  result[666] = work1d.KKT[212]*source[346]+work1d.KKT[1167]*source[666]+work1d.KKT[1168]*source[35];
  result[667] = work1d.KKT[214]*source[347]+work1d.KKT[1171]*source[667]+work1d.KKT[1169]*source[35]+work1d.KKT[1172]*source[227];
  result[668] = work1d.KKT[216]*source[348]+work1d.KKT[1173]*source[668]+work1d.KKT[1170]*source[35]+work1d.KKT[1174]*source[227];
  result[669] = work1d.KKT[218]*source[349]+work1d.KKT[1175]*source[669]+work1d.KKT[1176]*source[36];
  result[670] = work1d.KKT[220]*source[350]+work1d.KKT[1179]*source[670]+work1d.KKT[1177]*source[36]+work1d.KKT[1180]*source[230];
  result[671] = work1d.KKT[222]*source[351]+work1d.KKT[1181]*source[671]+work1d.KKT[1178]*source[36]+work1d.KKT[1182]*source[230];
  result[672] = work1d.KKT[224]*source[352]+work1d.KKT[1183]*source[672]+work1d.KKT[1184]*source[37];
  result[673] = work1d.KKT[226]*source[353]+work1d.KKT[1187]*source[673]+work1d.KKT[1185]*source[37]+work1d.KKT[1188]*source[233];
  result[674] = work1d.KKT[228]*source[354]+work1d.KKT[1189]*source[674]+work1d.KKT[1186]*source[37]+work1d.KKT[1190]*source[233];
  result[675] = work1d.KKT[230]*source[355]+work1d.KKT[1191]*source[675]+work1d.KKT[1192]*source[38];
  result[676] = work1d.KKT[232]*source[356]+work1d.KKT[1195]*source[676]+work1d.KKT[1193]*source[38]+work1d.KKT[1196]*source[236];
  result[677] = work1d.KKT[234]*source[357]+work1d.KKT[1197]*source[677]+work1d.KKT[1194]*source[38]+work1d.KKT[1198]*source[236];
  result[678] = work1d.KKT[236]*source[358]+work1d.KKT[1199]*source[678]+work1d.KKT[1200]*source[39];
  result[679] = work1d.KKT[238]*source[359]+work1d.KKT[1203]*source[679]+work1d.KKT[1201]*source[39]+work1d.KKT[1204]*source[239];
  result[680] = work1d.KKT[240]*source[360]+work1d.KKT[1205]*source[680]+work1d.KKT[1202]*source[39]+work1d.KKT[1206]*source[239];
  result[681] = work1d.KKT[242]*source[361]+work1d.KKT[1209]*source[681]+work1d.KKT[1210]*source[40];
  result[682] = work1d.KKT[244]*source[362]+work1d.KKT[1213]*source[682]+work1d.KKT[1211]*source[40]+work1d.KKT[1214]*source[123];
  result[683] = work1d.KKT[246]*source[363]+work1d.KKT[1215]*source[683]+work1d.KKT[1212]*source[40]+work1d.KKT[1216]*source[123];
  result[684] = work1d.KKT[248]*source[364]+work1d.KKT[1217]*source[684]+work1d.KKT[1218]*source[41];
  result[685] = work1d.KKT[250]*source[365]+work1d.KKT[1221]*source[685]+work1d.KKT[1219]*source[41]+work1d.KKT[1222]*source[126];
  result[686] = work1d.KKT[252]*source[366]+work1d.KKT[1223]*source[686]+work1d.KKT[1220]*source[41]+work1d.KKT[1224]*source[126];
  result[687] = work1d.KKT[254]*source[367]+work1d.KKT[1225]*source[687]+work1d.KKT[1226]*source[42];
  result[688] = work1d.KKT[256]*source[368]+work1d.KKT[1229]*source[688]+work1d.KKT[1227]*source[42]+work1d.KKT[1230]*source[129];
  result[689] = work1d.KKT[258]*source[369]+work1d.KKT[1231]*source[689]+work1d.KKT[1228]*source[42]+work1d.KKT[1232]*source[129];
  result[690] = work1d.KKT[260]*source[370]+work1d.KKT[1233]*source[690]+work1d.KKT[1234]*source[43];
  result[691] = work1d.KKT[262]*source[371]+work1d.KKT[1237]*source[691]+work1d.KKT[1235]*source[43]+work1d.KKT[1238]*source[132];
  result[692] = work1d.KKT[264]*source[372]+work1d.KKT[1239]*source[692]+work1d.KKT[1236]*source[43]+work1d.KKT[1240]*source[132];
  result[693] = work1d.KKT[266]*source[373]+work1d.KKT[1241]*source[693]+work1d.KKT[1242]*source[44];
  result[694] = work1d.KKT[268]*source[374]+work1d.KKT[1245]*source[694]+work1d.KKT[1243]*source[44]+work1d.KKT[1246]*source[135];
  result[695] = work1d.KKT[270]*source[375]+work1d.KKT[1247]*source[695]+work1d.KKT[1244]*source[44]+work1d.KKT[1248]*source[135];
  result[696] = work1d.KKT[272]*source[376]+work1d.KKT[1249]*source[696]+work1d.KKT[1250]*source[45];
  result[697] = work1d.KKT[274]*source[377]+work1d.KKT[1253]*source[697]+work1d.KKT[1251]*source[45]+work1d.KKT[1254]*source[138];
  result[698] = work1d.KKT[276]*source[378]+work1d.KKT[1255]*source[698]+work1d.KKT[1252]*source[45]+work1d.KKT[1256]*source[138];
  result[699] = work1d.KKT[278]*source[379]+work1d.KKT[1257]*source[699]+work1d.KKT[1258]*source[46];
  result[700] = work1d.KKT[280]*source[380]+work1d.KKT[1261]*source[700]+work1d.KKT[1259]*source[46]+work1d.KKT[1262]*source[141];
  result[701] = work1d.KKT[282]*source[381]+work1d.KKT[1263]*source[701]+work1d.KKT[1260]*source[46]+work1d.KKT[1264]*source[141];
  result[702] = work1d.KKT[284]*source[382]+work1d.KKT[1265]*source[702]+work1d.KKT[1266]*source[47];
  result[703] = work1d.KKT[286]*source[383]+work1d.KKT[1269]*source[703]+work1d.KKT[1267]*source[47]+work1d.KKT[1270]*source[144];
  result[704] = work1d.KKT[288]*source[384]+work1d.KKT[1271]*source[704]+work1d.KKT[1268]*source[47]+work1d.KKT[1272]*source[144];
  result[705] = work1d.KKT[290]*source[385]+work1d.KKT[1273]*source[705]+work1d.KKT[1274]*source[48];
  result[706] = work1d.KKT[292]*source[386]+work1d.KKT[1277]*source[706]+work1d.KKT[1275]*source[48]+work1d.KKT[1278]*source[147];
  result[707] = work1d.KKT[294]*source[387]+work1d.KKT[1279]*source[707]+work1d.KKT[1276]*source[48]+work1d.KKT[1280]*source[147];
  result[708] = work1d.KKT[296]*source[388]+work1d.KKT[1281]*source[708]+work1d.KKT[1282]*source[49];
  result[709] = work1d.KKT[298]*source[389]+work1d.KKT[1285]*source[709]+work1d.KKT[1283]*source[49]+work1d.KKT[1286]*source[150];
  result[710] = work1d.KKT[300]*source[390]+work1d.KKT[1287]*source[710]+work1d.KKT[1284]*source[49]+work1d.KKT[1288]*source[150];
  result[711] = work1d.KKT[302]*source[391]+work1d.KKT[1289]*source[711]+work1d.KKT[1290]*source[50];
  result[712] = work1d.KKT[304]*source[392]+work1d.KKT[1293]*source[712]+work1d.KKT[1291]*source[50]+work1d.KKT[1294]*source[153];
  result[713] = work1d.KKT[306]*source[393]+work1d.KKT[1295]*source[713]+work1d.KKT[1292]*source[50]+work1d.KKT[1296]*source[153];
  result[714] = work1d.KKT[308]*source[394]+work1d.KKT[1297]*source[714]+work1d.KKT[1298]*source[51];
  result[715] = work1d.KKT[310]*source[395]+work1d.KKT[1301]*source[715]+work1d.KKT[1299]*source[51]+work1d.KKT[1302]*source[156];
  result[716] = work1d.KKT[312]*source[396]+work1d.KKT[1303]*source[716]+work1d.KKT[1300]*source[51]+work1d.KKT[1304]*source[156];
  result[717] = work1d.KKT[314]*source[397]+work1d.KKT[1305]*source[717]+work1d.KKT[1306]*source[52];
  result[718] = work1d.KKT[316]*source[398]+work1d.KKT[1309]*source[718]+work1d.KKT[1307]*source[52]+work1d.KKT[1310]*source[159];
  result[719] = work1d.KKT[318]*source[399]+work1d.KKT[1311]*source[719]+work1d.KKT[1308]*source[52]+work1d.KKT[1312]*source[159];
  result[720] = work1d.KKT[320]*source[400]+work1d.KKT[1313]*source[720]+work1d.KKT[1314]*source[53];
  result[721] = work1d.KKT[322]*source[401]+work1d.KKT[1317]*source[721]+work1d.KKT[1315]*source[53]+work1d.KKT[1318]*source[162];
  result[722] = work1d.KKT[324]*source[402]+work1d.KKT[1319]*source[722]+work1d.KKT[1316]*source[53]+work1d.KKT[1320]*source[162];
  result[723] = work1d.KKT[326]*source[403]+work1d.KKT[1321]*source[723]+work1d.KKT[1322]*source[54];
  result[724] = work1d.KKT[328]*source[404]+work1d.KKT[1325]*source[724]+work1d.KKT[1323]*source[54]+work1d.KKT[1326]*source[165];
  result[725] = work1d.KKT[330]*source[405]+work1d.KKT[1327]*source[725]+work1d.KKT[1324]*source[54]+work1d.KKT[1328]*source[165];
  result[726] = work1d.KKT[332]*source[406]+work1d.KKT[1329]*source[726]+work1d.KKT[1330]*source[55];
  result[727] = work1d.KKT[334]*source[407]+work1d.KKT[1333]*source[727]+work1d.KKT[1331]*source[55]+work1d.KKT[1334]*source[168];
  result[728] = work1d.KKT[336]*source[408]+work1d.KKT[1335]*source[728]+work1d.KKT[1332]*source[55]+work1d.KKT[1336]*source[168];
  result[729] = work1d.KKT[338]*source[409]+work1d.KKT[1337]*source[729]+work1d.KKT[1338]*source[56];
  result[730] = work1d.KKT[340]*source[410]+work1d.KKT[1341]*source[730]+work1d.KKT[1339]*source[56]+work1d.KKT[1342]*source[171];
  result[731] = work1d.KKT[342]*source[411]+work1d.KKT[1343]*source[731]+work1d.KKT[1340]*source[56]+work1d.KKT[1344]*source[171];
  result[732] = work1d.KKT[344]*source[412]+work1d.KKT[1345]*source[732]+work1d.KKT[1346]*source[57];
  result[733] = work1d.KKT[346]*source[413]+work1d.KKT[1349]*source[733]+work1d.KKT[1347]*source[57]+work1d.KKT[1350]*source[174];
  result[734] = work1d.KKT[348]*source[414]+work1d.KKT[1351]*source[734]+work1d.KKT[1348]*source[57]+work1d.KKT[1352]*source[174];
  result[735] = work1d.KKT[350]*source[415]+work1d.KKT[1353]*source[735]+work1d.KKT[1354]*source[58];
  result[736] = work1d.KKT[352]*source[416]+work1d.KKT[1357]*source[736]+work1d.KKT[1355]*source[58]+work1d.KKT[1358]*source[177];
  result[737] = work1d.KKT[354]*source[417]+work1d.KKT[1359]*source[737]+work1d.KKT[1356]*source[58]+work1d.KKT[1360]*source[177];
  result[738] = work1d.KKT[356]*source[418]+work1d.KKT[1361]*source[738]+work1d.KKT[1362]*source[59];
  result[739] = work1d.KKT[358]*source[419]+work1d.KKT[1365]*source[739]+work1d.KKT[1363]*source[59]+work1d.KKT[1366]*source[180];
  result[740] = work1d.KKT[360]*source[420]+work1d.KKT[1367]*source[740]+work1d.KKT[1364]*source[59]+work1d.KKT[1368]*source[180];
  result[741] = work1d.KKT[362]*source[421]+work1d.KKT[1369]*source[741]+work1d.KKT[1370]*source[60];
  result[742] = work1d.KKT[364]*source[422]+work1d.KKT[1373]*source[742]+work1d.KKT[1371]*source[60]+work1d.KKT[1374]*source[183];
  result[743] = work1d.KKT[366]*source[423]+work1d.KKT[1375]*source[743]+work1d.KKT[1372]*source[60]+work1d.KKT[1376]*source[183];
  result[744] = work1d.KKT[368]*source[424]+work1d.KKT[1377]*source[744]+work1d.KKT[1378]*source[61];
  result[745] = work1d.KKT[370]*source[425]+work1d.KKT[1381]*source[745]+work1d.KKT[1379]*source[61]+work1d.KKT[1382]*source[186];
  result[746] = work1d.KKT[372]*source[426]+work1d.KKT[1383]*source[746]+work1d.KKT[1380]*source[61]+work1d.KKT[1384]*source[186];
  result[747] = work1d.KKT[374]*source[427]+work1d.KKT[1385]*source[747]+work1d.KKT[1386]*source[62];
  result[748] = work1d.KKT[376]*source[428]+work1d.KKT[1389]*source[748]+work1d.KKT[1387]*source[62]+work1d.KKT[1390]*source[189];
  result[749] = work1d.KKT[378]*source[429]+work1d.KKT[1391]*source[749]+work1d.KKT[1388]*source[62]+work1d.KKT[1392]*source[189];
  result[750] = work1d.KKT[380]*source[430]+work1d.KKT[1393]*source[750]+work1d.KKT[1394]*source[63];
  result[751] = work1d.KKT[382]*source[431]+work1d.KKT[1397]*source[751]+work1d.KKT[1395]*source[63]+work1d.KKT[1398]*source[192];
  result[752] = work1d.KKT[384]*source[432]+work1d.KKT[1399]*source[752]+work1d.KKT[1396]*source[63]+work1d.KKT[1400]*source[192];
  result[753] = work1d.KKT[386]*source[433]+work1d.KKT[1401]*source[753]+work1d.KKT[1402]*source[64];
  result[754] = work1d.KKT[388]*source[434]+work1d.KKT[1405]*source[754]+work1d.KKT[1403]*source[64]+work1d.KKT[1406]*source[195];
  result[755] = work1d.KKT[390]*source[435]+work1d.KKT[1407]*source[755]+work1d.KKT[1404]*source[64]+work1d.KKT[1408]*source[195];
  result[756] = work1d.KKT[392]*source[436]+work1d.KKT[1409]*source[756]+work1d.KKT[1410]*source[65];
  result[757] = work1d.KKT[394]*source[437]+work1d.KKT[1413]*source[757]+work1d.KKT[1411]*source[65]+work1d.KKT[1414]*source[198];
  result[758] = work1d.KKT[396]*source[438]+work1d.KKT[1415]*source[758]+work1d.KKT[1412]*source[65]+work1d.KKT[1416]*source[198];
  result[759] = work1d.KKT[398]*source[439]+work1d.KKT[1417]*source[759]+work1d.KKT[1418]*source[66];
  result[760] = work1d.KKT[400]*source[440]+work1d.KKT[1421]*source[760]+work1d.KKT[1419]*source[66]+work1d.KKT[1422]*source[201];
  result[761] = work1d.KKT[402]*source[441]+work1d.KKT[1423]*source[761]+work1d.KKT[1420]*source[66]+work1d.KKT[1424]*source[201];
  result[762] = work1d.KKT[404]*source[442]+work1d.KKT[1425]*source[762]+work1d.KKT[1426]*source[67];
  result[763] = work1d.KKT[406]*source[443]+work1d.KKT[1429]*source[763]+work1d.KKT[1427]*source[67]+work1d.KKT[1430]*source[204];
  result[764] = work1d.KKT[408]*source[444]+work1d.KKT[1431]*source[764]+work1d.KKT[1428]*source[67]+work1d.KKT[1432]*source[204];
  result[765] = work1d.KKT[410]*source[445]+work1d.KKT[1433]*source[765]+work1d.KKT[1434]*source[68];
  result[766] = work1d.KKT[412]*source[446]+work1d.KKT[1437]*source[766]+work1d.KKT[1435]*source[68]+work1d.KKT[1438]*source[207];
  result[767] = work1d.KKT[414]*source[447]+work1d.KKT[1439]*source[767]+work1d.KKT[1436]*source[68]+work1d.KKT[1440]*source[207];
  result[768] = work1d.KKT[416]*source[448]+work1d.KKT[1441]*source[768]+work1d.KKT[1442]*source[69];
  result[769] = work1d.KKT[418]*source[449]+work1d.KKT[1445]*source[769]+work1d.KKT[1443]*source[69]+work1d.KKT[1446]*source[210];
  result[770] = work1d.KKT[420]*source[450]+work1d.KKT[1447]*source[770]+work1d.KKT[1444]*source[69]+work1d.KKT[1448]*source[210];
  result[771] = work1d.KKT[422]*source[451]+work1d.KKT[1449]*source[771]+work1d.KKT[1450]*source[70];
  result[772] = work1d.KKT[424]*source[452]+work1d.KKT[1453]*source[772]+work1d.KKT[1451]*source[70]+work1d.KKT[1454]*source[213];
  result[773] = work1d.KKT[426]*source[453]+work1d.KKT[1455]*source[773]+work1d.KKT[1452]*source[70]+work1d.KKT[1456]*source[213];
  result[774] = work1d.KKT[428]*source[454]+work1d.KKT[1457]*source[774]+work1d.KKT[1458]*source[71];
  result[775] = work1d.KKT[430]*source[455]+work1d.KKT[1461]*source[775]+work1d.KKT[1459]*source[71]+work1d.KKT[1462]*source[216];
  result[776] = work1d.KKT[432]*source[456]+work1d.KKT[1463]*source[776]+work1d.KKT[1460]*source[71]+work1d.KKT[1464]*source[216];
  result[777] = work1d.KKT[434]*source[457]+work1d.KKT[1465]*source[777]+work1d.KKT[1466]*source[72];
  result[778] = work1d.KKT[436]*source[458]+work1d.KKT[1469]*source[778]+work1d.KKT[1467]*source[72]+work1d.KKT[1470]*source[219];
  result[779] = work1d.KKT[438]*source[459]+work1d.KKT[1471]*source[779]+work1d.KKT[1468]*source[72]+work1d.KKT[1472]*source[219];
  result[780] = work1d.KKT[440]*source[460]+work1d.KKT[1473]*source[780]+work1d.KKT[1474]*source[73];
  result[781] = work1d.KKT[442]*source[461]+work1d.KKT[1477]*source[781]+work1d.KKT[1475]*source[73]+work1d.KKT[1478]*source[222];
  result[782] = work1d.KKT[444]*source[462]+work1d.KKT[1479]*source[782]+work1d.KKT[1476]*source[73]+work1d.KKT[1480]*source[222];
  result[783] = work1d.KKT[446]*source[463]+work1d.KKT[1481]*source[783]+work1d.KKT[1482]*source[74];
  result[784] = work1d.KKT[448]*source[464]+work1d.KKT[1485]*source[784]+work1d.KKT[1483]*source[74]+work1d.KKT[1486]*source[225];
  result[785] = work1d.KKT[450]*source[465]+work1d.KKT[1487]*source[785]+work1d.KKT[1484]*source[74]+work1d.KKT[1488]*source[225];
  result[786] = work1d.KKT[452]*source[466]+work1d.KKT[1489]*source[786]+work1d.KKT[1490]*source[75];
  result[787] = work1d.KKT[454]*source[467]+work1d.KKT[1493]*source[787]+work1d.KKT[1491]*source[75]+work1d.KKT[1494]*source[228];
  result[788] = work1d.KKT[456]*source[468]+work1d.KKT[1495]*source[788]+work1d.KKT[1492]*source[75]+work1d.KKT[1496]*source[228];
  result[789] = work1d.KKT[458]*source[469]+work1d.KKT[1497]*source[789]+work1d.KKT[1498]*source[76];
  result[790] = work1d.KKT[460]*source[470]+work1d.KKT[1501]*source[790]+work1d.KKT[1499]*source[76]+work1d.KKT[1502]*source[231];
  result[791] = work1d.KKT[462]*source[471]+work1d.KKT[1503]*source[791]+work1d.KKT[1500]*source[76]+work1d.KKT[1504]*source[231];
  result[792] = work1d.KKT[464]*source[472]+work1d.KKT[1505]*source[792]+work1d.KKT[1506]*source[77];
  result[793] = work1d.KKT[466]*source[473]+work1d.KKT[1509]*source[793]+work1d.KKT[1507]*source[77]+work1d.KKT[1510]*source[234];
  result[794] = work1d.KKT[468]*source[474]+work1d.KKT[1511]*source[794]+work1d.KKT[1508]*source[77]+work1d.KKT[1512]*source[234];
  result[795] = work1d.KKT[470]*source[475]+work1d.KKT[1513]*source[795]+work1d.KKT[1514]*source[78];
  result[796] = work1d.KKT[472]*source[476]+work1d.KKT[1517]*source[796]+work1d.KKT[1515]*source[78]+work1d.KKT[1518]*source[237];
  result[797] = work1d.KKT[474]*source[477]+work1d.KKT[1519]*source[797]+work1d.KKT[1516]*source[78]+work1d.KKT[1520]*source[237];
  result[798] = work1d.KKT[476]*source[478]+work1d.KKT[1521]*source[798]+work1d.KKT[1522]*source[79];
  result[799] = work1d.KKT[478]*source[479]+work1d.KKT[1525]*source[799]+work1d.KKT[1523]*source[79]+work1d.KKT[1526]*source[240];
  result[800] = work1d.KKT[480]*source[480]+work1d.KKT[1527]*source[800]+work1d.KKT[1524]*source[79]+work1d.KKT[1528]*source[240];
  result[801] = work1d.KKT[482]*source[481]+work1d.KKT[641]*source[801]+work1d.KKT[642]*source[122];
  result[802] = work1d.KKT[484]*source[482]+work1d.KKT[643]*source[802]+work1d.KKT[644]*source[125];
  result[803] = work1d.KKT[486]*source[483]+work1d.KKT[645]*source[803]+work1d.KKT[646]*source[128];
  result[804] = work1d.KKT[488]*source[484]+work1d.KKT[647]*source[804]+work1d.KKT[648]*source[131];
  result[805] = work1d.KKT[490]*source[485]+work1d.KKT[649]*source[805]+work1d.KKT[650]*source[134];
  result[806] = work1d.KKT[492]*source[486]+work1d.KKT[651]*source[806]+work1d.KKT[652]*source[137];
  result[807] = work1d.KKT[494]*source[487]+work1d.KKT[653]*source[807]+work1d.KKT[654]*source[140];
  result[808] = work1d.KKT[496]*source[488]+work1d.KKT[655]*source[808]+work1d.KKT[656]*source[143];
  result[809] = work1d.KKT[498]*source[489]+work1d.KKT[657]*source[809]+work1d.KKT[658]*source[146];
  result[810] = work1d.KKT[500]*source[490]+work1d.KKT[659]*source[810]+work1d.KKT[660]*source[149];
  result[811] = work1d.KKT[502]*source[491]+work1d.KKT[661]*source[811]+work1d.KKT[662]*source[152];
  result[812] = work1d.KKT[504]*source[492]+work1d.KKT[663]*source[812]+work1d.KKT[664]*source[155];
  result[813] = work1d.KKT[506]*source[493]+work1d.KKT[665]*source[813]+work1d.KKT[666]*source[158];
  result[814] = work1d.KKT[508]*source[494]+work1d.KKT[667]*source[814]+work1d.KKT[668]*source[161];
  result[815] = work1d.KKT[510]*source[495]+work1d.KKT[669]*source[815]+work1d.KKT[670]*source[164];
  result[816] = work1d.KKT[512]*source[496]+work1d.KKT[671]*source[816]+work1d.KKT[672]*source[167];
  result[817] = work1d.KKT[514]*source[497]+work1d.KKT[673]*source[817]+work1d.KKT[674]*source[170];
  result[818] = work1d.KKT[516]*source[498]+work1d.KKT[675]*source[818]+work1d.KKT[676]*source[173];
  result[819] = work1d.KKT[518]*source[499]+work1d.KKT[677]*source[819]+work1d.KKT[678]*source[176];
  result[820] = work1d.KKT[520]*source[500]+work1d.KKT[679]*source[820]+work1d.KKT[680]*source[179];
  result[821] = work1d.KKT[522]*source[501]+work1d.KKT[681]*source[821]+work1d.KKT[682]*source[182];
  result[822] = work1d.KKT[524]*source[502]+work1d.KKT[683]*source[822]+work1d.KKT[684]*source[185];
  result[823] = work1d.KKT[526]*source[503]+work1d.KKT[685]*source[823]+work1d.KKT[686]*source[188];
  result[824] = work1d.KKT[528]*source[504]+work1d.KKT[687]*source[824]+work1d.KKT[688]*source[191];
  result[825] = work1d.KKT[530]*source[505]+work1d.KKT[689]*source[825]+work1d.KKT[690]*source[194];
  result[826] = work1d.KKT[532]*source[506]+work1d.KKT[691]*source[826]+work1d.KKT[692]*source[197];
  result[827] = work1d.KKT[534]*source[507]+work1d.KKT[693]*source[827]+work1d.KKT[694]*source[200];
  result[828] = work1d.KKT[536]*source[508]+work1d.KKT[695]*source[828]+work1d.KKT[696]*source[203];
  result[829] = work1d.KKT[538]*source[509]+work1d.KKT[697]*source[829]+work1d.KKT[698]*source[206];
  result[830] = work1d.KKT[540]*source[510]+work1d.KKT[699]*source[830]+work1d.KKT[700]*source[209];
  result[831] = work1d.KKT[542]*source[511]+work1d.KKT[701]*source[831]+work1d.KKT[702]*source[212];
  result[832] = work1d.KKT[544]*source[512]+work1d.KKT[703]*source[832]+work1d.KKT[704]*source[215];
  result[833] = work1d.KKT[546]*source[513]+work1d.KKT[705]*source[833]+work1d.KKT[706]*source[218];
  result[834] = work1d.KKT[548]*source[514]+work1d.KKT[707]*source[834]+work1d.KKT[708]*source[221];
  result[835] = work1d.KKT[550]*source[515]+work1d.KKT[709]*source[835]+work1d.KKT[710]*source[224];
  result[836] = work1d.KKT[552]*source[516]+work1d.KKT[711]*source[836]+work1d.KKT[712]*source[227];
  result[837] = work1d.KKT[554]*source[517]+work1d.KKT[713]*source[837]+work1d.KKT[714]*source[230];
  result[838] = work1d.KKT[556]*source[518]+work1d.KKT[715]*source[838]+work1d.KKT[716]*source[233];
  result[839] = work1d.KKT[558]*source[519]+work1d.KKT[717]*source[839]+work1d.KKT[718]*source[236];
  result[840] = work1d.KKT[560]*source[520]+work1d.KKT[719]*source[840]+work1d.KKT[720]*source[239];
  result[841] = work1d.KKT[562]*source[521]+work1d.KKT[721]*source[841]+work1d.KKT[722]*source[123];
  result[842] = work1d.KKT[564]*source[522]+work1d.KKT[723]*source[842]+work1d.KKT[724]*source[126];
  result[843] = work1d.KKT[566]*source[523]+work1d.KKT[725]*source[843]+work1d.KKT[726]*source[129];
  result[844] = work1d.KKT[568]*source[524]+work1d.KKT[727]*source[844]+work1d.KKT[728]*source[132];
  result[845] = work1d.KKT[570]*source[525]+work1d.KKT[729]*source[845]+work1d.KKT[730]*source[135];
  result[846] = work1d.KKT[572]*source[526]+work1d.KKT[731]*source[846]+work1d.KKT[732]*source[138];
  result[847] = work1d.KKT[574]*source[527]+work1d.KKT[733]*source[847]+work1d.KKT[734]*source[141];
  result[848] = work1d.KKT[576]*source[528]+work1d.KKT[735]*source[848]+work1d.KKT[736]*source[144];
  result[849] = work1d.KKT[578]*source[529]+work1d.KKT[737]*source[849]+work1d.KKT[738]*source[147];
  result[850] = work1d.KKT[580]*source[530]+work1d.KKT[739]*source[850]+work1d.KKT[740]*source[150];
  result[851] = work1d.KKT[582]*source[531]+work1d.KKT[741]*source[851]+work1d.KKT[742]*source[153];
  result[852] = work1d.KKT[584]*source[532]+work1d.KKT[743]*source[852]+work1d.KKT[744]*source[156];
  result[853] = work1d.KKT[586]*source[533]+work1d.KKT[745]*source[853]+work1d.KKT[746]*source[159];
  result[854] = work1d.KKT[588]*source[534]+work1d.KKT[747]*source[854]+work1d.KKT[748]*source[162];
  result[855] = work1d.KKT[590]*source[535]+work1d.KKT[749]*source[855]+work1d.KKT[750]*source[165];
  result[856] = work1d.KKT[592]*source[536]+work1d.KKT[751]*source[856]+work1d.KKT[752]*source[168];
  result[857] = work1d.KKT[594]*source[537]+work1d.KKT[753]*source[857]+work1d.KKT[754]*source[171];
  result[858] = work1d.KKT[596]*source[538]+work1d.KKT[755]*source[858]+work1d.KKT[756]*source[174];
  result[859] = work1d.KKT[598]*source[539]+work1d.KKT[757]*source[859]+work1d.KKT[758]*source[177];
  result[860] = work1d.KKT[600]*source[540]+work1d.KKT[759]*source[860]+work1d.KKT[760]*source[180];
  result[861] = work1d.KKT[602]*source[541]+work1d.KKT[761]*source[861]+work1d.KKT[762]*source[183];
  result[862] = work1d.KKT[604]*source[542]+work1d.KKT[763]*source[862]+work1d.KKT[764]*source[186];
  result[863] = work1d.KKT[606]*source[543]+work1d.KKT[765]*source[863]+work1d.KKT[766]*source[189];
  result[864] = work1d.KKT[608]*source[544]+work1d.KKT[767]*source[864]+work1d.KKT[768]*source[192];
  result[865] = work1d.KKT[610]*source[545]+work1d.KKT[769]*source[865]+work1d.KKT[770]*source[195];
  result[866] = work1d.KKT[612]*source[546]+work1d.KKT[771]*source[866]+work1d.KKT[772]*source[198];
  result[867] = work1d.KKT[614]*source[547]+work1d.KKT[773]*source[867]+work1d.KKT[774]*source[201];
  result[868] = work1d.KKT[616]*source[548]+work1d.KKT[775]*source[868]+work1d.KKT[776]*source[204];
  result[869] = work1d.KKT[618]*source[549]+work1d.KKT[777]*source[869]+work1d.KKT[778]*source[207];
  result[870] = work1d.KKT[620]*source[550]+work1d.KKT[779]*source[870]+work1d.KKT[780]*source[210];
  result[871] = work1d.KKT[622]*source[551]+work1d.KKT[781]*source[871]+work1d.KKT[782]*source[213];
  result[872] = work1d.KKT[624]*source[552]+work1d.KKT[783]*source[872]+work1d.KKT[784]*source[216];
  result[873] = work1d.KKT[626]*source[553]+work1d.KKT[785]*source[873]+work1d.KKT[786]*source[219];
  result[874] = work1d.KKT[628]*source[554]+work1d.KKT[787]*source[874]+work1d.KKT[788]*source[222];
  result[875] = work1d.KKT[630]*source[555]+work1d.KKT[789]*source[875]+work1d.KKT[790]*source[225];
  result[876] = work1d.KKT[632]*source[556]+work1d.KKT[791]*source[876]+work1d.KKT[792]*source[228];
  result[877] = work1d.KKT[634]*source[557]+work1d.KKT[793]*source[877]+work1d.KKT[794]*source[231];
  result[878] = work1d.KKT[636]*source[558]+work1d.KKT[795]*source[878]+work1d.KKT[796]*source[234];
  result[879] = work1d.KKT[638]*source[559]+work1d.KKT[797]*source[879]+work1d.KKT[798]*source[237];
  result[880] = work1d.KKT[640]*source[560]+work1d.KKT[799]*source[880]+work1d.KKT[800]*source[240];
  result[881] = work1d.KKT[801]*source[121];
  result[882] = work1d.KKT[802]*source[122];
  result[883] = work1d.KKT[803]*source[80]+work1d.KKT[804]*source[123];
  result[884] = work1d.KKT[884]*source[121]+work1d.KKT[1535]*source[122]+work1d.KKT[1536]*source[124];
  result[885] = work1d.KKT[1616]*source[122]+work1d.KKT[1618]*source[123]+work1d.KKT[1731]*source[125];
  result[886] = work1d.KKT[806]*source[81]+work1d.KKT[1537]*source[123]+work1d.KKT[1538]*source[126];
  result[887] = work1d.KKT[1620]*source[124]+work1d.KKT[1733]*source[125]+work1d.KKT[1622]*source[127];
  result[888] = work1d.KKT[1734]*source[125]+work1d.KKT[1736]*source[126]+work1d.KKT[1737]*source[128];
  result[889] = work1d.KKT[808]*source[82]+work1d.KKT[1539]*source[126]+work1d.KKT[1540]*source[129];
  result[890] = work1d.KKT[1623]*source[127]+work1d.KKT[1739]*source[128]+work1d.KKT[1625]*source[130];
  result[891] = work1d.KKT[1740]*source[128]+work1d.KKT[1742]*source[129]+work1d.KKT[1743]*source[131];
  result[892] = work1d.KKT[810]*source[83]+work1d.KKT[1541]*source[129]+work1d.KKT[1542]*source[132];
  result[893] = work1d.KKT[1626]*source[130]+work1d.KKT[1745]*source[131]+work1d.KKT[1628]*source[133];
  result[894] = work1d.KKT[1746]*source[131]+work1d.KKT[1748]*source[132]+work1d.KKT[1749]*source[134];
  result[895] = work1d.KKT[812]*source[84]+work1d.KKT[1543]*source[132]+work1d.KKT[1544]*source[135];
  result[896] = work1d.KKT[1629]*source[133]+work1d.KKT[1751]*source[134]+work1d.KKT[1631]*source[136];
  result[897] = work1d.KKT[1752]*source[134]+work1d.KKT[1754]*source[135]+work1d.KKT[1755]*source[137];
  result[898] = work1d.KKT[814]*source[85]+work1d.KKT[1545]*source[135]+work1d.KKT[1546]*source[138];
  result[899] = work1d.KKT[1632]*source[136]+work1d.KKT[1757]*source[137]+work1d.KKT[1634]*source[139];
  result[900] = work1d.KKT[1758]*source[137]+work1d.KKT[1760]*source[138]+work1d.KKT[1761]*source[140];
  result[901] = work1d.KKT[816]*source[86]+work1d.KKT[1547]*source[138]+work1d.KKT[1548]*source[141];
  result[902] = work1d.KKT[1635]*source[139]+work1d.KKT[1763]*source[140]+work1d.KKT[1637]*source[142];
  result[903] = work1d.KKT[1764]*source[140]+work1d.KKT[1766]*source[141]+work1d.KKT[1767]*source[143];
  result[904] = work1d.KKT[818]*source[87]+work1d.KKT[1549]*source[141]+work1d.KKT[1550]*source[144];
  result[905] = work1d.KKT[1638]*source[142]+work1d.KKT[1769]*source[143]+work1d.KKT[1640]*source[145];
  result[906] = work1d.KKT[1770]*source[143]+work1d.KKT[1772]*source[144]+work1d.KKT[1773]*source[146];
  result[907] = work1d.KKT[820]*source[88]+work1d.KKT[1551]*source[144]+work1d.KKT[1552]*source[147];
  result[908] = work1d.KKT[1641]*source[145]+work1d.KKT[1775]*source[146]+work1d.KKT[1643]*source[148];
  result[909] = work1d.KKT[1776]*source[146]+work1d.KKT[1778]*source[147]+work1d.KKT[1779]*source[149];
  result[910] = work1d.KKT[822]*source[89]+work1d.KKT[1553]*source[147]+work1d.KKT[1554]*source[150];
  result[911] = work1d.KKT[1644]*source[148]+work1d.KKT[1781]*source[149]+work1d.KKT[1646]*source[151];
  result[912] = work1d.KKT[1782]*source[149]+work1d.KKT[1784]*source[150]+work1d.KKT[1785]*source[152];
  result[913] = work1d.KKT[824]*source[90]+work1d.KKT[1555]*source[150]+work1d.KKT[1556]*source[153];
  result[914] = work1d.KKT[1647]*source[151]+work1d.KKT[1787]*source[152]+work1d.KKT[1649]*source[154];
  result[915] = work1d.KKT[1788]*source[152]+work1d.KKT[1790]*source[153]+work1d.KKT[1791]*source[155];
  result[916] = work1d.KKT[826]*source[91]+work1d.KKT[1557]*source[153]+work1d.KKT[1558]*source[156];
  result[917] = work1d.KKT[1650]*source[154]+work1d.KKT[1793]*source[155]+work1d.KKT[1652]*source[157];
  result[918] = work1d.KKT[1794]*source[155]+work1d.KKT[1796]*source[156]+work1d.KKT[1797]*source[158];
  result[919] = work1d.KKT[828]*source[92]+work1d.KKT[1559]*source[156]+work1d.KKT[1560]*source[159];
  result[920] = work1d.KKT[1653]*source[157]+work1d.KKT[1799]*source[158]+work1d.KKT[1655]*source[160];
  result[921] = work1d.KKT[1800]*source[158]+work1d.KKT[1802]*source[159]+work1d.KKT[1803]*source[161];
  result[922] = work1d.KKT[830]*source[93]+work1d.KKT[1561]*source[159]+work1d.KKT[1562]*source[162];
  result[923] = work1d.KKT[1656]*source[160]+work1d.KKT[1805]*source[161]+work1d.KKT[1658]*source[163];
  result[924] = work1d.KKT[1806]*source[161]+work1d.KKT[1808]*source[162]+work1d.KKT[1809]*source[164];
  result[925] = work1d.KKT[832]*source[94]+work1d.KKT[1563]*source[162]+work1d.KKT[1564]*source[165];
  result[926] = work1d.KKT[1659]*source[163]+work1d.KKT[1811]*source[164]+work1d.KKT[1661]*source[166];
  result[927] = work1d.KKT[1812]*source[164]+work1d.KKT[1814]*source[165]+work1d.KKT[1815]*source[167];
  result[928] = work1d.KKT[834]*source[95]+work1d.KKT[1565]*source[165]+work1d.KKT[1566]*source[168];
  result[929] = work1d.KKT[1662]*source[166]+work1d.KKT[1817]*source[167]+work1d.KKT[1664]*source[169];
  result[930] = work1d.KKT[1818]*source[167]+work1d.KKT[1820]*source[168]+work1d.KKT[1821]*source[170];
  result[931] = work1d.KKT[836]*source[96]+work1d.KKT[1567]*source[168]+work1d.KKT[1568]*source[171];
  result[932] = work1d.KKT[1665]*source[169]+work1d.KKT[1823]*source[170]+work1d.KKT[1667]*source[172];
  result[933] = work1d.KKT[1824]*source[170]+work1d.KKT[1826]*source[171]+work1d.KKT[1827]*source[173];
  result[934] = work1d.KKT[838]*source[97]+work1d.KKT[1569]*source[171]+work1d.KKT[1570]*source[174];
  result[935] = work1d.KKT[1668]*source[172]+work1d.KKT[1829]*source[173]+work1d.KKT[1670]*source[175];
  result[936] = work1d.KKT[1830]*source[173]+work1d.KKT[1832]*source[174]+work1d.KKT[1833]*source[176];
  result[937] = work1d.KKT[840]*source[98]+work1d.KKT[1571]*source[174]+work1d.KKT[1572]*source[177];
  result[938] = work1d.KKT[1671]*source[175]+work1d.KKT[1835]*source[176]+work1d.KKT[1673]*source[178];
  result[939] = work1d.KKT[1836]*source[176]+work1d.KKT[1838]*source[177]+work1d.KKT[1839]*source[179];
  result[940] = work1d.KKT[842]*source[99]+work1d.KKT[1573]*source[177]+work1d.KKT[1574]*source[180];
  result[941] = work1d.KKT[1674]*source[178]+work1d.KKT[1841]*source[179]+work1d.KKT[1676]*source[181];
  result[942] = work1d.KKT[1842]*source[179]+work1d.KKT[1844]*source[180]+work1d.KKT[1845]*source[182];
  result[943] = work1d.KKT[844]*source[100]+work1d.KKT[1575]*source[180]+work1d.KKT[1576]*source[183];
  result[944] = work1d.KKT[1677]*source[181]+work1d.KKT[1847]*source[182]+work1d.KKT[1679]*source[184];
  result[945] = work1d.KKT[1848]*source[182]+work1d.KKT[1850]*source[183]+work1d.KKT[1851]*source[185];
  result[946] = work1d.KKT[846]*source[101]+work1d.KKT[1577]*source[183]+work1d.KKT[1578]*source[186];
  result[947] = work1d.KKT[1680]*source[184]+work1d.KKT[1853]*source[185]+work1d.KKT[1682]*source[187];
  result[948] = work1d.KKT[1854]*source[185]+work1d.KKT[1856]*source[186]+work1d.KKT[1857]*source[188];
  result[949] = work1d.KKT[848]*source[102]+work1d.KKT[1579]*source[186]+work1d.KKT[1580]*source[189];
  result[950] = work1d.KKT[1683]*source[187]+work1d.KKT[1859]*source[188]+work1d.KKT[1685]*source[190];
  result[951] = work1d.KKT[1860]*source[188]+work1d.KKT[1862]*source[189]+work1d.KKT[1863]*source[191];
  result[952] = work1d.KKT[850]*source[103]+work1d.KKT[1581]*source[189]+work1d.KKT[1582]*source[192];
  result[953] = work1d.KKT[1686]*source[190]+work1d.KKT[1865]*source[191]+work1d.KKT[1688]*source[193];
  result[954] = work1d.KKT[1866]*source[191]+work1d.KKT[1868]*source[192]+work1d.KKT[1869]*source[194];
  result[955] = work1d.KKT[852]*source[104]+work1d.KKT[1583]*source[192]+work1d.KKT[1584]*source[195];
  result[956] = work1d.KKT[1689]*source[193]+work1d.KKT[1871]*source[194]+work1d.KKT[1691]*source[196];
  result[957] = work1d.KKT[1872]*source[194]+work1d.KKT[1874]*source[195]+work1d.KKT[1875]*source[197];
  result[958] = work1d.KKT[854]*source[105]+work1d.KKT[1585]*source[195]+work1d.KKT[1586]*source[198];
  result[959] = work1d.KKT[1692]*source[196]+work1d.KKT[1877]*source[197]+work1d.KKT[1694]*source[199];
  result[960] = work1d.KKT[1878]*source[197]+work1d.KKT[1880]*source[198]+work1d.KKT[1881]*source[200];
  result[961] = work1d.KKT[856]*source[106]+work1d.KKT[1587]*source[198]+work1d.KKT[1588]*source[201];
  result[962] = work1d.KKT[1695]*source[199]+work1d.KKT[1883]*source[200]+work1d.KKT[1697]*source[202];
  result[963] = work1d.KKT[1884]*source[200]+work1d.KKT[1886]*source[201]+work1d.KKT[1887]*source[203];
  result[964] = work1d.KKT[858]*source[107]+work1d.KKT[1589]*source[201]+work1d.KKT[1590]*source[204];
  result[965] = work1d.KKT[1698]*source[202]+work1d.KKT[1889]*source[203]+work1d.KKT[1700]*source[205];
  result[966] = work1d.KKT[1890]*source[203]+work1d.KKT[1892]*source[204]+work1d.KKT[1893]*source[206];
  result[967] = work1d.KKT[860]*source[108]+work1d.KKT[1591]*source[204]+work1d.KKT[1592]*source[207];
  result[968] = work1d.KKT[1701]*source[205]+work1d.KKT[1895]*source[206]+work1d.KKT[1703]*source[208];
  result[969] = work1d.KKT[1896]*source[206]+work1d.KKT[1898]*source[207]+work1d.KKT[1899]*source[209];
  result[970] = work1d.KKT[862]*source[109]+work1d.KKT[1593]*source[207]+work1d.KKT[1594]*source[210];
  result[971] = work1d.KKT[1704]*source[208]+work1d.KKT[1901]*source[209]+work1d.KKT[1706]*source[211];
  result[972] = work1d.KKT[1902]*source[209]+work1d.KKT[1904]*source[210]+work1d.KKT[1905]*source[212];
  result[973] = work1d.KKT[864]*source[110]+work1d.KKT[1595]*source[210]+work1d.KKT[1596]*source[213];
  result[974] = work1d.KKT[1707]*source[211]+work1d.KKT[1907]*source[212]+work1d.KKT[1709]*source[214];
  result[975] = work1d.KKT[1908]*source[212]+work1d.KKT[1910]*source[213]+work1d.KKT[1911]*source[215];
  result[976] = work1d.KKT[866]*source[111]+work1d.KKT[1597]*source[213]+work1d.KKT[1598]*source[216];
  result[977] = work1d.KKT[1710]*source[214]+work1d.KKT[1913]*source[215]+work1d.KKT[1712]*source[217];
  result[978] = work1d.KKT[1914]*source[215]+work1d.KKT[1916]*source[216]+work1d.KKT[1917]*source[218];
  result[979] = work1d.KKT[868]*source[112]+work1d.KKT[1599]*source[216]+work1d.KKT[1600]*source[219];
  result[980] = work1d.KKT[1713]*source[217]+work1d.KKT[1919]*source[218]+work1d.KKT[1715]*source[220];
  result[981] = work1d.KKT[1920]*source[218]+work1d.KKT[1922]*source[219]+work1d.KKT[1923]*source[221];
  result[982] = work1d.KKT[870]*source[113]+work1d.KKT[1601]*source[219]+work1d.KKT[1602]*source[222];
  result[983] = work1d.KKT[1716]*source[220]+work1d.KKT[1925]*source[221]+work1d.KKT[1718]*source[223];
  result[984] = work1d.KKT[1926]*source[221]+work1d.KKT[1928]*source[222]+work1d.KKT[1929]*source[224];
  result[985] = work1d.KKT[872]*source[114]+work1d.KKT[1603]*source[222]+work1d.KKT[1604]*source[225];
  result[986] = work1d.KKT[1719]*source[223]+work1d.KKT[1931]*source[224]+work1d.KKT[1721]*source[226];
  result[987] = work1d.KKT[1932]*source[224]+work1d.KKT[1934]*source[225]+work1d.KKT[1935]*source[227];
  result[988] = work1d.KKT[874]*source[115]+work1d.KKT[1605]*source[225]+work1d.KKT[1606]*source[228];
  result[989] = work1d.KKT[1722]*source[226]+work1d.KKT[1937]*source[227]+work1d.KKT[1724]*source[229];
  result[990] = work1d.KKT[1938]*source[227]+work1d.KKT[1940]*source[228]+work1d.KKT[1941]*source[230];
  result[991] = work1d.KKT[876]*source[116]+work1d.KKT[1607]*source[228]+work1d.KKT[1608]*source[231];
  result[992] = work1d.KKT[1725]*source[229]+work1d.KKT[1943]*source[230]+work1d.KKT[1727]*source[232];
  result[993] = work1d.KKT[1944]*source[230]+work1d.KKT[1946]*source[231]+work1d.KKT[1947]*source[233];
  result[994] = work1d.KKT[878]*source[117]+work1d.KKT[1609]*source[231]+work1d.KKT[1610]*source[234];
  result[995] = work1d.KKT[1728]*source[232]+work1d.KKT[1948]*source[233]+work1d.KKT[1730]*source[235];
  result[996] = work1d.KKT[1949]*source[233]+work1d.KKT[1950]*source[234]+work1d.KKT[1951]*source[236];
  result[997] = work1d.KKT[880]*source[118]+work1d.KKT[1611]*source[234]+work1d.KKT[1533]*source[237];
  result[998] = work1d.KKT[1612]*source[235]+work1d.KKT[1613]*source[236]+work1d.KKT[886]*source[238];
  result[999] = work1d.KKT[1614]*source[236]+work1d.KKT[1534]*source[237]+work1d.KKT[1208]*source[239];
  result[1000] = work1d.KKT[882]*source[119]+work1d.KKT[1531]*source[237]+work1d.KKT[1530]*source[240];
}
double check_residual1d(double *target, double *multiplicand) {
  /* Returns the squared 2-norm of lhs - A*rhs. */
  /* Reuses v to find the residual. */
  int i;
  double residual;
  residual = 0;
  matrix_multiply1d(work1d.v, multiplicand);
  for (i = 0; i < 241; i++) {
    residual += (target[i] - work1d.v[i])*(target[i] - work1d.v[i]);
  }
  return residual;
}
void fill_KKT1d(void) {
  work1d.KKT[805] = 2*params1d.R[0];
  work1d.KKT[807] = 2*params1d.R[0];
  work1d.KKT[809] = 2*params1d.R[0];
  work1d.KKT[811] = 2*params1d.R[0];
  work1d.KKT[813] = 2*params1d.R[0];
  work1d.KKT[815] = 2*params1d.R[0];
  work1d.KKT[817] = 2*params1d.R[0];
  work1d.KKT[819] = 2*params1d.R[0];
  work1d.KKT[821] = 2*params1d.R[0];
  work1d.KKT[823] = 2*params1d.R[0];
  work1d.KKT[825] = 2*params1d.R[0];
  work1d.KKT[827] = 2*params1d.R[0];
  work1d.KKT[829] = 2*params1d.R[0];
  work1d.KKT[831] = 2*params1d.R[0];
  work1d.KKT[833] = 2*params1d.R[0];
  work1d.KKT[835] = 2*params1d.R[0];
  work1d.KKT[837] = 2*params1d.R[0];
  work1d.KKT[839] = 2*params1d.R[0];
  work1d.KKT[841] = 2*params1d.R[0];
  work1d.KKT[843] = 2*params1d.R[0];
  work1d.KKT[845] = 2*params1d.R[0];
  work1d.KKT[847] = 2*params1d.R[0];
  work1d.KKT[849] = 2*params1d.R[0];
  work1d.KKT[851] = 2*params1d.R[0];
  work1d.KKT[853] = 2*params1d.R[0];
  work1d.KKT[855] = 2*params1d.R[0];
  work1d.KKT[857] = 2*params1d.R[0];
  work1d.KKT[859] = 2*params1d.R[0];
  work1d.KKT[861] = 2*params1d.R[0];
  work1d.KKT[863] = 2*params1d.R[0];
  work1d.KKT[865] = 2*params1d.R[0];
  work1d.KKT[867] = 2*params1d.R[0];
  work1d.KKT[869] = 2*params1d.R[0];
  work1d.KKT[871] = 2*params1d.R[0];
  work1d.KKT[873] = 2*params1d.R[0];
  work1d.KKT[875] = 2*params1d.R[0];
  work1d.KKT[877] = 2*params1d.R[0];
  work1d.KKT[879] = 2*params1d.R[0];
  work1d.KKT[881] = 2*params1d.R[0];
  work1d.KKT[0] = 2*params1d.R[0];
  work1d.KKT[883] = 2*params1d.Q[0];
  work1d.KKT[1615] = 2*params1d.Q[1];
  work1d.KKT[1617] = 2*params1d.Q[2];
  work1d.KKT[1619] = 2*params1d.Q[0];
  work1d.KKT[1732] = 2*params1d.Q[1];
  work1d.KKT[1735] = 2*params1d.Q[2];
  work1d.KKT[1621] = 2*params1d.Q[0];
  work1d.KKT[1738] = 2*params1d.Q[1];
  work1d.KKT[1741] = 2*params1d.Q[2];
  work1d.KKT[1624] = 2*params1d.Q[0];
  work1d.KKT[1744] = 2*params1d.Q[1];
  work1d.KKT[1747] = 2*params1d.Q[2];
  work1d.KKT[1627] = 2*params1d.Q[0];
  work1d.KKT[1750] = 2*params1d.Q[1];
  work1d.KKT[1753] = 2*params1d.Q[2];
  work1d.KKT[1630] = 2*params1d.Q[0];
  work1d.KKT[1756] = 2*params1d.Q[1];
  work1d.KKT[1759] = 2*params1d.Q[2];
  work1d.KKT[1633] = 2*params1d.Q[0];
  work1d.KKT[1762] = 2*params1d.Q[1];
  work1d.KKT[1765] = 2*params1d.Q[2];
  work1d.KKT[1636] = 2*params1d.Q[0];
  work1d.KKT[1768] = 2*params1d.Q[1];
  work1d.KKT[1771] = 2*params1d.Q[2];
  work1d.KKT[1639] = 2*params1d.Q[0];
  work1d.KKT[1774] = 2*params1d.Q[1];
  work1d.KKT[1777] = 2*params1d.Q[2];
  work1d.KKT[1642] = 2*params1d.Q[0];
  work1d.KKT[1780] = 2*params1d.Q[1];
  work1d.KKT[1783] = 2*params1d.Q[2];
  work1d.KKT[1645] = 2*params1d.Q[0];
  work1d.KKT[1786] = 2*params1d.Q[1];
  work1d.KKT[1789] = 2*params1d.Q[2];
  work1d.KKT[1648] = 2*params1d.Q[0];
  work1d.KKT[1792] = 2*params1d.Q[1];
  work1d.KKT[1795] = 2*params1d.Q[2];
  work1d.KKT[1651] = 2*params1d.Q[0];
  work1d.KKT[1798] = 2*params1d.Q[1];
  work1d.KKT[1801] = 2*params1d.Q[2];
  work1d.KKT[1654] = 2*params1d.Q[0];
  work1d.KKT[1804] = 2*params1d.Q[1];
  work1d.KKT[1807] = 2*params1d.Q[2];
  work1d.KKT[1657] = 2*params1d.Q[0];
  work1d.KKT[1810] = 2*params1d.Q[1];
  work1d.KKT[1813] = 2*params1d.Q[2];
  work1d.KKT[1660] = 2*params1d.Q[0];
  work1d.KKT[1816] = 2*params1d.Q[1];
  work1d.KKT[1819] = 2*params1d.Q[2];
  work1d.KKT[1663] = 2*params1d.Q[0];
  work1d.KKT[1822] = 2*params1d.Q[1];
  work1d.KKT[1825] = 2*params1d.Q[2];
  work1d.KKT[1666] = 2*params1d.Q[0];
  work1d.KKT[1828] = 2*params1d.Q[1];
  work1d.KKT[1831] = 2*params1d.Q[2];
  work1d.KKT[1669] = 2*params1d.Q[0];
  work1d.KKT[1834] = 2*params1d.Q[1];
  work1d.KKT[1837] = 2*params1d.Q[2];
  work1d.KKT[1672] = 2*params1d.Q[0];
  work1d.KKT[1840] = 2*params1d.Q[1];
  work1d.KKT[1843] = 2*params1d.Q[2];
  work1d.KKT[1675] = 2*params1d.Q[0];
  work1d.KKT[1846] = 2*params1d.Q[1];
  work1d.KKT[1849] = 2*params1d.Q[2];
  work1d.KKT[1678] = 2*params1d.Q[0];
  work1d.KKT[1852] = 2*params1d.Q[1];
  work1d.KKT[1855] = 2*params1d.Q[2];
  work1d.KKT[1681] = 2*params1d.Q[0];
  work1d.KKT[1858] = 2*params1d.Q[1];
  work1d.KKT[1861] = 2*params1d.Q[2];
  work1d.KKT[1684] = 2*params1d.Q[0];
  work1d.KKT[1864] = 2*params1d.Q[1];
  work1d.KKT[1867] = 2*params1d.Q[2];
  work1d.KKT[1687] = 2*params1d.Q[0];
  work1d.KKT[1870] = 2*params1d.Q[1];
  work1d.KKT[1873] = 2*params1d.Q[2];
  work1d.KKT[1690] = 2*params1d.Q[0];
  work1d.KKT[1876] = 2*params1d.Q[1];
  work1d.KKT[1879] = 2*params1d.Q[2];
  work1d.KKT[1693] = 2*params1d.Q[0];
  work1d.KKT[1882] = 2*params1d.Q[1];
  work1d.KKT[1885] = 2*params1d.Q[2];
  work1d.KKT[1696] = 2*params1d.Q[0];
  work1d.KKT[1888] = 2*params1d.Q[1];
  work1d.KKT[1891] = 2*params1d.Q[2];
  work1d.KKT[1699] = 2*params1d.Q[0];
  work1d.KKT[1894] = 2*params1d.Q[1];
  work1d.KKT[1897] = 2*params1d.Q[2];
  work1d.KKT[1702] = 2*params1d.Q[0];
  work1d.KKT[1900] = 2*params1d.Q[1];
  work1d.KKT[1903] = 2*params1d.Q[2];
  work1d.KKT[1705] = 2*params1d.Q[0];
  work1d.KKT[1906] = 2*params1d.Q[1];
  work1d.KKT[1909] = 2*params1d.Q[2];
  work1d.KKT[1708] = 2*params1d.Q[0];
  work1d.KKT[1912] = 2*params1d.Q[1];
  work1d.KKT[1915] = 2*params1d.Q[2];
  work1d.KKT[1711] = 2*params1d.Q[0];
  work1d.KKT[1918] = 2*params1d.Q[1];
  work1d.KKT[1921] = 2*params1d.Q[2];
  work1d.KKT[1714] = 2*params1d.Q[0];
  work1d.KKT[1924] = 2*params1d.Q[1];
  work1d.KKT[1927] = 2*params1d.Q[2];
  work1d.KKT[1717] = 2*params1d.Q[0];
  work1d.KKT[1930] = 2*params1d.Q[1];
  work1d.KKT[1933] = 2*params1d.Q[2];
  work1d.KKT[1720] = 2*params1d.Q[0];
  work1d.KKT[1936] = 2*params1d.Q[1];
  work1d.KKT[1939] = 2*params1d.Q[2];
  work1d.KKT[1723] = 2*params1d.Q[0];
  work1d.KKT[1942] = 2*params1d.Q[1];
  work1d.KKT[1945] = 2*params1d.Q[2];
  work1d.KKT[1726] = 2*params1d.Q[0];
  work1d.KKT[1952] = 2*params1d.Q[1];
  work1d.KKT[1953] = 2*params1d.Q[2];
  work1d.KKT[1729] = 2*params1d.Q[0];
  work1d.KKT[1954] = 2*params1d.Q[1];
  work1d.KKT[1532] = 2*params1d.Q[2];
  work1d.KKT[885] = 2*params1d.Q[0];
  work1d.KKT[1207] = 2*params1d.Q[1];
  work1d.KKT[1529] = 2*params1d.Q[2];
  work1d.KKT[1] = work1d.s_inv_z[0];
  work1d.KKT[3] = work1d.s_inv_z[1];
  work1d.KKT[5] = work1d.s_inv_z[2];
  work1d.KKT[7] = work1d.s_inv_z[3];
  work1d.KKT[9] = work1d.s_inv_z[4];
  work1d.KKT[11] = work1d.s_inv_z[5];
  work1d.KKT[13] = work1d.s_inv_z[6];
  work1d.KKT[15] = work1d.s_inv_z[7];
  work1d.KKT[17] = work1d.s_inv_z[8];
  work1d.KKT[19] = work1d.s_inv_z[9];
  work1d.KKT[21] = work1d.s_inv_z[10];
  work1d.KKT[23] = work1d.s_inv_z[11];
  work1d.KKT[25] = work1d.s_inv_z[12];
  work1d.KKT[27] = work1d.s_inv_z[13];
  work1d.KKT[29] = work1d.s_inv_z[14];
  work1d.KKT[31] = work1d.s_inv_z[15];
  work1d.KKT[33] = work1d.s_inv_z[16];
  work1d.KKT[35] = work1d.s_inv_z[17];
  work1d.KKT[37] = work1d.s_inv_z[18];
  work1d.KKT[39] = work1d.s_inv_z[19];
  work1d.KKT[41] = work1d.s_inv_z[20];
  work1d.KKT[43] = work1d.s_inv_z[21];
  work1d.KKT[45] = work1d.s_inv_z[22];
  work1d.KKT[47] = work1d.s_inv_z[23];
  work1d.KKT[49] = work1d.s_inv_z[24];
  work1d.KKT[51] = work1d.s_inv_z[25];
  work1d.KKT[53] = work1d.s_inv_z[26];
  work1d.KKT[55] = work1d.s_inv_z[27];
  work1d.KKT[57] = work1d.s_inv_z[28];
  work1d.KKT[59] = work1d.s_inv_z[29];
  work1d.KKT[61] = work1d.s_inv_z[30];
  work1d.KKT[63] = work1d.s_inv_z[31];
  work1d.KKT[65] = work1d.s_inv_z[32];
  work1d.KKT[67] = work1d.s_inv_z[33];
  work1d.KKT[69] = work1d.s_inv_z[34];
  work1d.KKT[71] = work1d.s_inv_z[35];
  work1d.KKT[73] = work1d.s_inv_z[36];
  work1d.KKT[75] = work1d.s_inv_z[37];
  work1d.KKT[77] = work1d.s_inv_z[38];
  work1d.KKT[79] = work1d.s_inv_z[39];
  work1d.KKT[81] = work1d.s_inv_z[40];
  work1d.KKT[83] = work1d.s_inv_z[41];
  work1d.KKT[85] = work1d.s_inv_z[42];
  work1d.KKT[87] = work1d.s_inv_z[43];
  work1d.KKT[89] = work1d.s_inv_z[44];
  work1d.KKT[91] = work1d.s_inv_z[45];
  work1d.KKT[93] = work1d.s_inv_z[46];
  work1d.KKT[95] = work1d.s_inv_z[47];
  work1d.KKT[97] = work1d.s_inv_z[48];
  work1d.KKT[99] = work1d.s_inv_z[49];
  work1d.KKT[101] = work1d.s_inv_z[50];
  work1d.KKT[103] = work1d.s_inv_z[51];
  work1d.KKT[105] = work1d.s_inv_z[52];
  work1d.KKT[107] = work1d.s_inv_z[53];
  work1d.KKT[109] = work1d.s_inv_z[54];
  work1d.KKT[111] = work1d.s_inv_z[55];
  work1d.KKT[113] = work1d.s_inv_z[56];
  work1d.KKT[115] = work1d.s_inv_z[57];
  work1d.KKT[117] = work1d.s_inv_z[58];
  work1d.KKT[119] = work1d.s_inv_z[59];
  work1d.KKT[121] = work1d.s_inv_z[60];
  work1d.KKT[123] = work1d.s_inv_z[61];
  work1d.KKT[125] = work1d.s_inv_z[62];
  work1d.KKT[127] = work1d.s_inv_z[63];
  work1d.KKT[129] = work1d.s_inv_z[64];
  work1d.KKT[131] = work1d.s_inv_z[65];
  work1d.KKT[133] = work1d.s_inv_z[66];
  work1d.KKT[135] = work1d.s_inv_z[67];
  work1d.KKT[137] = work1d.s_inv_z[68];
  work1d.KKT[139] = work1d.s_inv_z[69];
  work1d.KKT[141] = work1d.s_inv_z[70];
  work1d.KKT[143] = work1d.s_inv_z[71];
  work1d.KKT[145] = work1d.s_inv_z[72];
  work1d.KKT[147] = work1d.s_inv_z[73];
  work1d.KKT[149] = work1d.s_inv_z[74];
  work1d.KKT[151] = work1d.s_inv_z[75];
  work1d.KKT[153] = work1d.s_inv_z[76];
  work1d.KKT[155] = work1d.s_inv_z[77];
  work1d.KKT[157] = work1d.s_inv_z[78];
  work1d.KKT[159] = work1d.s_inv_z[79];
  work1d.KKT[161] = work1d.s_inv_z[80];
  work1d.KKT[163] = work1d.s_inv_z[81];
  work1d.KKT[165] = work1d.s_inv_z[82];
  work1d.KKT[167] = work1d.s_inv_z[83];
  work1d.KKT[169] = work1d.s_inv_z[84];
  work1d.KKT[171] = work1d.s_inv_z[85];
  work1d.KKT[173] = work1d.s_inv_z[86];
  work1d.KKT[175] = work1d.s_inv_z[87];
  work1d.KKT[177] = work1d.s_inv_z[88];
  work1d.KKT[179] = work1d.s_inv_z[89];
  work1d.KKT[181] = work1d.s_inv_z[90];
  work1d.KKT[183] = work1d.s_inv_z[91];
  work1d.KKT[185] = work1d.s_inv_z[92];
  work1d.KKT[187] = work1d.s_inv_z[93];
  work1d.KKT[189] = work1d.s_inv_z[94];
  work1d.KKT[191] = work1d.s_inv_z[95];
  work1d.KKT[193] = work1d.s_inv_z[96];
  work1d.KKT[195] = work1d.s_inv_z[97];
  work1d.KKT[197] = work1d.s_inv_z[98];
  work1d.KKT[199] = work1d.s_inv_z[99];
  work1d.KKT[201] = work1d.s_inv_z[100];
  work1d.KKT[203] = work1d.s_inv_z[101];
  work1d.KKT[205] = work1d.s_inv_z[102];
  work1d.KKT[207] = work1d.s_inv_z[103];
  work1d.KKT[209] = work1d.s_inv_z[104];
  work1d.KKT[211] = work1d.s_inv_z[105];
  work1d.KKT[213] = work1d.s_inv_z[106];
  work1d.KKT[215] = work1d.s_inv_z[107];
  work1d.KKT[217] = work1d.s_inv_z[108];
  work1d.KKT[219] = work1d.s_inv_z[109];
  work1d.KKT[221] = work1d.s_inv_z[110];
  work1d.KKT[223] = work1d.s_inv_z[111];
  work1d.KKT[225] = work1d.s_inv_z[112];
  work1d.KKT[227] = work1d.s_inv_z[113];
  work1d.KKT[229] = work1d.s_inv_z[114];
  work1d.KKT[231] = work1d.s_inv_z[115];
  work1d.KKT[233] = work1d.s_inv_z[116];
  work1d.KKT[235] = work1d.s_inv_z[117];
  work1d.KKT[237] = work1d.s_inv_z[118];
  work1d.KKT[239] = work1d.s_inv_z[119];
  work1d.KKT[241] = work1d.s_inv_z[120];
  work1d.KKT[243] = work1d.s_inv_z[121];
  work1d.KKT[245] = work1d.s_inv_z[122];
  work1d.KKT[247] = work1d.s_inv_z[123];
  work1d.KKT[249] = work1d.s_inv_z[124];
  work1d.KKT[251] = work1d.s_inv_z[125];
  work1d.KKT[253] = work1d.s_inv_z[126];
  work1d.KKT[255] = work1d.s_inv_z[127];
  work1d.KKT[257] = work1d.s_inv_z[128];
  work1d.KKT[259] = work1d.s_inv_z[129];
  work1d.KKT[261] = work1d.s_inv_z[130];
  work1d.KKT[263] = work1d.s_inv_z[131];
  work1d.KKT[265] = work1d.s_inv_z[132];
  work1d.KKT[267] = work1d.s_inv_z[133];
  work1d.KKT[269] = work1d.s_inv_z[134];
  work1d.KKT[271] = work1d.s_inv_z[135];
  work1d.KKT[273] = work1d.s_inv_z[136];
  work1d.KKT[275] = work1d.s_inv_z[137];
  work1d.KKT[277] = work1d.s_inv_z[138];
  work1d.KKT[279] = work1d.s_inv_z[139];
  work1d.KKT[281] = work1d.s_inv_z[140];
  work1d.KKT[283] = work1d.s_inv_z[141];
  work1d.KKT[285] = work1d.s_inv_z[142];
  work1d.KKT[287] = work1d.s_inv_z[143];
  work1d.KKT[289] = work1d.s_inv_z[144];
  work1d.KKT[291] = work1d.s_inv_z[145];
  work1d.KKT[293] = work1d.s_inv_z[146];
  work1d.KKT[295] = work1d.s_inv_z[147];
  work1d.KKT[297] = work1d.s_inv_z[148];
  work1d.KKT[299] = work1d.s_inv_z[149];
  work1d.KKT[301] = work1d.s_inv_z[150];
  work1d.KKT[303] = work1d.s_inv_z[151];
  work1d.KKT[305] = work1d.s_inv_z[152];
  work1d.KKT[307] = work1d.s_inv_z[153];
  work1d.KKT[309] = work1d.s_inv_z[154];
  work1d.KKT[311] = work1d.s_inv_z[155];
  work1d.KKT[313] = work1d.s_inv_z[156];
  work1d.KKT[315] = work1d.s_inv_z[157];
  work1d.KKT[317] = work1d.s_inv_z[158];
  work1d.KKT[319] = work1d.s_inv_z[159];
  work1d.KKT[321] = work1d.s_inv_z[160];
  work1d.KKT[323] = work1d.s_inv_z[161];
  work1d.KKT[325] = work1d.s_inv_z[162];
  work1d.KKT[327] = work1d.s_inv_z[163];
  work1d.KKT[329] = work1d.s_inv_z[164];
  work1d.KKT[331] = work1d.s_inv_z[165];
  work1d.KKT[333] = work1d.s_inv_z[166];
  work1d.KKT[335] = work1d.s_inv_z[167];
  work1d.KKT[337] = work1d.s_inv_z[168];
  work1d.KKT[339] = work1d.s_inv_z[169];
  work1d.KKT[341] = work1d.s_inv_z[170];
  work1d.KKT[343] = work1d.s_inv_z[171];
  work1d.KKT[345] = work1d.s_inv_z[172];
  work1d.KKT[347] = work1d.s_inv_z[173];
  work1d.KKT[349] = work1d.s_inv_z[174];
  work1d.KKT[351] = work1d.s_inv_z[175];
  work1d.KKT[353] = work1d.s_inv_z[176];
  work1d.KKT[355] = work1d.s_inv_z[177];
  work1d.KKT[357] = work1d.s_inv_z[178];
  work1d.KKT[359] = work1d.s_inv_z[179];
  work1d.KKT[361] = work1d.s_inv_z[180];
  work1d.KKT[363] = work1d.s_inv_z[181];
  work1d.KKT[365] = work1d.s_inv_z[182];
  work1d.KKT[367] = work1d.s_inv_z[183];
  work1d.KKT[369] = work1d.s_inv_z[184];
  work1d.KKT[371] = work1d.s_inv_z[185];
  work1d.KKT[373] = work1d.s_inv_z[186];
  work1d.KKT[375] = work1d.s_inv_z[187];
  work1d.KKT[377] = work1d.s_inv_z[188];
  work1d.KKT[379] = work1d.s_inv_z[189];
  work1d.KKT[381] = work1d.s_inv_z[190];
  work1d.KKT[383] = work1d.s_inv_z[191];
  work1d.KKT[385] = work1d.s_inv_z[192];
  work1d.KKT[387] = work1d.s_inv_z[193];
  work1d.KKT[389] = work1d.s_inv_z[194];
  work1d.KKT[391] = work1d.s_inv_z[195];
  work1d.KKT[393] = work1d.s_inv_z[196];
  work1d.KKT[395] = work1d.s_inv_z[197];
  work1d.KKT[397] = work1d.s_inv_z[198];
  work1d.KKT[399] = work1d.s_inv_z[199];
  work1d.KKT[401] = work1d.s_inv_z[200];
  work1d.KKT[403] = work1d.s_inv_z[201];
  work1d.KKT[405] = work1d.s_inv_z[202];
  work1d.KKT[407] = work1d.s_inv_z[203];
  work1d.KKT[409] = work1d.s_inv_z[204];
  work1d.KKT[411] = work1d.s_inv_z[205];
  work1d.KKT[413] = work1d.s_inv_z[206];
  work1d.KKT[415] = work1d.s_inv_z[207];
  work1d.KKT[417] = work1d.s_inv_z[208];
  work1d.KKT[419] = work1d.s_inv_z[209];
  work1d.KKT[421] = work1d.s_inv_z[210];
  work1d.KKT[423] = work1d.s_inv_z[211];
  work1d.KKT[425] = work1d.s_inv_z[212];
  work1d.KKT[427] = work1d.s_inv_z[213];
  work1d.KKT[429] = work1d.s_inv_z[214];
  work1d.KKT[431] = work1d.s_inv_z[215];
  work1d.KKT[433] = work1d.s_inv_z[216];
  work1d.KKT[435] = work1d.s_inv_z[217];
  work1d.KKT[437] = work1d.s_inv_z[218];
  work1d.KKT[439] = work1d.s_inv_z[219];
  work1d.KKT[441] = work1d.s_inv_z[220];
  work1d.KKT[443] = work1d.s_inv_z[221];
  work1d.KKT[445] = work1d.s_inv_z[222];
  work1d.KKT[447] = work1d.s_inv_z[223];
  work1d.KKT[449] = work1d.s_inv_z[224];
  work1d.KKT[451] = work1d.s_inv_z[225];
  work1d.KKT[453] = work1d.s_inv_z[226];
  work1d.KKT[455] = work1d.s_inv_z[227];
  work1d.KKT[457] = work1d.s_inv_z[228];
  work1d.KKT[459] = work1d.s_inv_z[229];
  work1d.KKT[461] = work1d.s_inv_z[230];
  work1d.KKT[463] = work1d.s_inv_z[231];
  work1d.KKT[465] = work1d.s_inv_z[232];
  work1d.KKT[467] = work1d.s_inv_z[233];
  work1d.KKT[469] = work1d.s_inv_z[234];
  work1d.KKT[471] = work1d.s_inv_z[235];
  work1d.KKT[473] = work1d.s_inv_z[236];
  work1d.KKT[475] = work1d.s_inv_z[237];
  work1d.KKT[477] = work1d.s_inv_z[238];
  work1d.KKT[479] = work1d.s_inv_z[239];
  work1d.KKT[481] = work1d.s_inv_z[240];
  work1d.KKT[483] = work1d.s_inv_z[241];
  work1d.KKT[485] = work1d.s_inv_z[242];
  work1d.KKT[487] = work1d.s_inv_z[243];
  work1d.KKT[489] = work1d.s_inv_z[244];
  work1d.KKT[491] = work1d.s_inv_z[245];
  work1d.KKT[493] = work1d.s_inv_z[246];
  work1d.KKT[495] = work1d.s_inv_z[247];
  work1d.KKT[497] = work1d.s_inv_z[248];
  work1d.KKT[499] = work1d.s_inv_z[249];
  work1d.KKT[501] = work1d.s_inv_z[250];
  work1d.KKT[503] = work1d.s_inv_z[251];
  work1d.KKT[505] = work1d.s_inv_z[252];
  work1d.KKT[507] = work1d.s_inv_z[253];
  work1d.KKT[509] = work1d.s_inv_z[254];
  work1d.KKT[511] = work1d.s_inv_z[255];
  work1d.KKT[513] = work1d.s_inv_z[256];
  work1d.KKT[515] = work1d.s_inv_z[257];
  work1d.KKT[517] = work1d.s_inv_z[258];
  work1d.KKT[519] = work1d.s_inv_z[259];
  work1d.KKT[521] = work1d.s_inv_z[260];
  work1d.KKT[523] = work1d.s_inv_z[261];
  work1d.KKT[525] = work1d.s_inv_z[262];
  work1d.KKT[527] = work1d.s_inv_z[263];
  work1d.KKT[529] = work1d.s_inv_z[264];
  work1d.KKT[531] = work1d.s_inv_z[265];
  work1d.KKT[533] = work1d.s_inv_z[266];
  work1d.KKT[535] = work1d.s_inv_z[267];
  work1d.KKT[537] = work1d.s_inv_z[268];
  work1d.KKT[539] = work1d.s_inv_z[269];
  work1d.KKT[541] = work1d.s_inv_z[270];
  work1d.KKT[543] = work1d.s_inv_z[271];
  work1d.KKT[545] = work1d.s_inv_z[272];
  work1d.KKT[547] = work1d.s_inv_z[273];
  work1d.KKT[549] = work1d.s_inv_z[274];
  work1d.KKT[551] = work1d.s_inv_z[275];
  work1d.KKT[553] = work1d.s_inv_z[276];
  work1d.KKT[555] = work1d.s_inv_z[277];
  work1d.KKT[557] = work1d.s_inv_z[278];
  work1d.KKT[559] = work1d.s_inv_z[279];
  work1d.KKT[561] = work1d.s_inv_z[280];
  work1d.KKT[563] = work1d.s_inv_z[281];
  work1d.KKT[565] = work1d.s_inv_z[282];
  work1d.KKT[567] = work1d.s_inv_z[283];
  work1d.KKT[569] = work1d.s_inv_z[284];
  work1d.KKT[571] = work1d.s_inv_z[285];
  work1d.KKT[573] = work1d.s_inv_z[286];
  work1d.KKT[575] = work1d.s_inv_z[287];
  work1d.KKT[577] = work1d.s_inv_z[288];
  work1d.KKT[579] = work1d.s_inv_z[289];
  work1d.KKT[581] = work1d.s_inv_z[290];
  work1d.KKT[583] = work1d.s_inv_z[291];
  work1d.KKT[585] = work1d.s_inv_z[292];
  work1d.KKT[587] = work1d.s_inv_z[293];
  work1d.KKT[589] = work1d.s_inv_z[294];
  work1d.KKT[591] = work1d.s_inv_z[295];
  work1d.KKT[593] = work1d.s_inv_z[296];
  work1d.KKT[595] = work1d.s_inv_z[297];
  work1d.KKT[597] = work1d.s_inv_z[298];
  work1d.KKT[599] = work1d.s_inv_z[299];
  work1d.KKT[601] = work1d.s_inv_z[300];
  work1d.KKT[603] = work1d.s_inv_z[301];
  work1d.KKT[605] = work1d.s_inv_z[302];
  work1d.KKT[607] = work1d.s_inv_z[303];
  work1d.KKT[609] = work1d.s_inv_z[304];
  work1d.KKT[611] = work1d.s_inv_z[305];
  work1d.KKT[613] = work1d.s_inv_z[306];
  work1d.KKT[615] = work1d.s_inv_z[307];
  work1d.KKT[617] = work1d.s_inv_z[308];
  work1d.KKT[619] = work1d.s_inv_z[309];
  work1d.KKT[621] = work1d.s_inv_z[310];
  work1d.KKT[623] = work1d.s_inv_z[311];
  work1d.KKT[625] = work1d.s_inv_z[312];
  work1d.KKT[627] = work1d.s_inv_z[313];
  work1d.KKT[629] = work1d.s_inv_z[314];
  work1d.KKT[631] = work1d.s_inv_z[315];
  work1d.KKT[633] = work1d.s_inv_z[316];
  work1d.KKT[635] = work1d.s_inv_z[317];
  work1d.KKT[637] = work1d.s_inv_z[318];
  work1d.KKT[639] = work1d.s_inv_z[319];
  work1d.KKT[2] = 1;
  work1d.KKT[4] = 1;
  work1d.KKT[6] = 1;
  work1d.KKT[8] = 1;
  work1d.KKT[10] = 1;
  work1d.KKT[12] = 1;
  work1d.KKT[14] = 1;
  work1d.KKT[16] = 1;
  work1d.KKT[18] = 1;
  work1d.KKT[20] = 1;
  work1d.KKT[22] = 1;
  work1d.KKT[24] = 1;
  work1d.KKT[26] = 1;
  work1d.KKT[28] = 1;
  work1d.KKT[30] = 1;
  work1d.KKT[32] = 1;
  work1d.KKT[34] = 1;
  work1d.KKT[36] = 1;
  work1d.KKT[38] = 1;
  work1d.KKT[40] = 1;
  work1d.KKT[42] = 1;
  work1d.KKT[44] = 1;
  work1d.KKT[46] = 1;
  work1d.KKT[48] = 1;
  work1d.KKT[50] = 1;
  work1d.KKT[52] = 1;
  work1d.KKT[54] = 1;
  work1d.KKT[56] = 1;
  work1d.KKT[58] = 1;
  work1d.KKT[60] = 1;
  work1d.KKT[62] = 1;
  work1d.KKT[64] = 1;
  work1d.KKT[66] = 1;
  work1d.KKT[68] = 1;
  work1d.KKT[70] = 1;
  work1d.KKT[72] = 1;
  work1d.KKT[74] = 1;
  work1d.KKT[76] = 1;
  work1d.KKT[78] = 1;
  work1d.KKT[80] = 1;
  work1d.KKT[82] = 1;
  work1d.KKT[84] = 1;
  work1d.KKT[86] = 1;
  work1d.KKT[88] = 1;
  work1d.KKT[90] = 1;
  work1d.KKT[92] = 1;
  work1d.KKT[94] = 1;
  work1d.KKT[96] = 1;
  work1d.KKT[98] = 1;
  work1d.KKT[100] = 1;
  work1d.KKT[102] = 1;
  work1d.KKT[104] = 1;
  work1d.KKT[106] = 1;
  work1d.KKT[108] = 1;
  work1d.KKT[110] = 1;
  work1d.KKT[112] = 1;
  work1d.KKT[114] = 1;
  work1d.KKT[116] = 1;
  work1d.KKT[118] = 1;
  work1d.KKT[120] = 1;
  work1d.KKT[122] = 1;
  work1d.KKT[124] = 1;
  work1d.KKT[126] = 1;
  work1d.KKT[128] = 1;
  work1d.KKT[130] = 1;
  work1d.KKT[132] = 1;
  work1d.KKT[134] = 1;
  work1d.KKT[136] = 1;
  work1d.KKT[138] = 1;
  work1d.KKT[140] = 1;
  work1d.KKT[142] = 1;
  work1d.KKT[144] = 1;
  work1d.KKT[146] = 1;
  work1d.KKT[148] = 1;
  work1d.KKT[150] = 1;
  work1d.KKT[152] = 1;
  work1d.KKT[154] = 1;
  work1d.KKT[156] = 1;
  work1d.KKT[158] = 1;
  work1d.KKT[160] = 1;
  work1d.KKT[162] = 1;
  work1d.KKT[164] = 1;
  work1d.KKT[166] = 1;
  work1d.KKT[168] = 1;
  work1d.KKT[170] = 1;
  work1d.KKT[172] = 1;
  work1d.KKT[174] = 1;
  work1d.KKT[176] = 1;
  work1d.KKT[178] = 1;
  work1d.KKT[180] = 1;
  work1d.KKT[182] = 1;
  work1d.KKT[184] = 1;
  work1d.KKT[186] = 1;
  work1d.KKT[188] = 1;
  work1d.KKT[190] = 1;
  work1d.KKT[192] = 1;
  work1d.KKT[194] = 1;
  work1d.KKT[196] = 1;
  work1d.KKT[198] = 1;
  work1d.KKT[200] = 1;
  work1d.KKT[202] = 1;
  work1d.KKT[204] = 1;
  work1d.KKT[206] = 1;
  work1d.KKT[208] = 1;
  work1d.KKT[210] = 1;
  work1d.KKT[212] = 1;
  work1d.KKT[214] = 1;
  work1d.KKT[216] = 1;
  work1d.KKT[218] = 1;
  work1d.KKT[220] = 1;
  work1d.KKT[222] = 1;
  work1d.KKT[224] = 1;
  work1d.KKT[226] = 1;
  work1d.KKT[228] = 1;
  work1d.KKT[230] = 1;
  work1d.KKT[232] = 1;
  work1d.KKT[234] = 1;
  work1d.KKT[236] = 1;
  work1d.KKT[238] = 1;
  work1d.KKT[240] = 1;
  work1d.KKT[242] = 1;
  work1d.KKT[244] = 1;
  work1d.KKT[246] = 1;
  work1d.KKT[248] = 1;
  work1d.KKT[250] = 1;
  work1d.KKT[252] = 1;
  work1d.KKT[254] = 1;
  work1d.KKT[256] = 1;
  work1d.KKT[258] = 1;
  work1d.KKT[260] = 1;
  work1d.KKT[262] = 1;
  work1d.KKT[264] = 1;
  work1d.KKT[266] = 1;
  work1d.KKT[268] = 1;
  work1d.KKT[270] = 1;
  work1d.KKT[272] = 1;
  work1d.KKT[274] = 1;
  work1d.KKT[276] = 1;
  work1d.KKT[278] = 1;
  work1d.KKT[280] = 1;
  work1d.KKT[282] = 1;
  work1d.KKT[284] = 1;
  work1d.KKT[286] = 1;
  work1d.KKT[288] = 1;
  work1d.KKT[290] = 1;
  work1d.KKT[292] = 1;
  work1d.KKT[294] = 1;
  work1d.KKT[296] = 1;
  work1d.KKT[298] = 1;
  work1d.KKT[300] = 1;
  work1d.KKT[302] = 1;
  work1d.KKT[304] = 1;
  work1d.KKT[306] = 1;
  work1d.KKT[308] = 1;
  work1d.KKT[310] = 1;
  work1d.KKT[312] = 1;
  work1d.KKT[314] = 1;
  work1d.KKT[316] = 1;
  work1d.KKT[318] = 1;
  work1d.KKT[320] = 1;
  work1d.KKT[322] = 1;
  work1d.KKT[324] = 1;
  work1d.KKT[326] = 1;
  work1d.KKT[328] = 1;
  work1d.KKT[330] = 1;
  work1d.KKT[332] = 1;
  work1d.KKT[334] = 1;
  work1d.KKT[336] = 1;
  work1d.KKT[338] = 1;
  work1d.KKT[340] = 1;
  work1d.KKT[342] = 1;
  work1d.KKT[344] = 1;
  work1d.KKT[346] = 1;
  work1d.KKT[348] = 1;
  work1d.KKT[350] = 1;
  work1d.KKT[352] = 1;
  work1d.KKT[354] = 1;
  work1d.KKT[356] = 1;
  work1d.KKT[358] = 1;
  work1d.KKT[360] = 1;
  work1d.KKT[362] = 1;
  work1d.KKT[364] = 1;
  work1d.KKT[366] = 1;
  work1d.KKT[368] = 1;
  work1d.KKT[370] = 1;
  work1d.KKT[372] = 1;
  work1d.KKT[374] = 1;
  work1d.KKT[376] = 1;
  work1d.KKT[378] = 1;
  work1d.KKT[380] = 1;
  work1d.KKT[382] = 1;
  work1d.KKT[384] = 1;
  work1d.KKT[386] = 1;
  work1d.KKT[388] = 1;
  work1d.KKT[390] = 1;
  work1d.KKT[392] = 1;
  work1d.KKT[394] = 1;
  work1d.KKT[396] = 1;
  work1d.KKT[398] = 1;
  work1d.KKT[400] = 1;
  work1d.KKT[402] = 1;
  work1d.KKT[404] = 1;
  work1d.KKT[406] = 1;
  work1d.KKT[408] = 1;
  work1d.KKT[410] = 1;
  work1d.KKT[412] = 1;
  work1d.KKT[414] = 1;
  work1d.KKT[416] = 1;
  work1d.KKT[418] = 1;
  work1d.KKT[420] = 1;
  work1d.KKT[422] = 1;
  work1d.KKT[424] = 1;
  work1d.KKT[426] = 1;
  work1d.KKT[428] = 1;
  work1d.KKT[430] = 1;
  work1d.KKT[432] = 1;
  work1d.KKT[434] = 1;
  work1d.KKT[436] = 1;
  work1d.KKT[438] = 1;
  work1d.KKT[440] = 1;
  work1d.KKT[442] = 1;
  work1d.KKT[444] = 1;
  work1d.KKT[446] = 1;
  work1d.KKT[448] = 1;
  work1d.KKT[450] = 1;
  work1d.KKT[452] = 1;
  work1d.KKT[454] = 1;
  work1d.KKT[456] = 1;
  work1d.KKT[458] = 1;
  work1d.KKT[460] = 1;
  work1d.KKT[462] = 1;
  work1d.KKT[464] = 1;
  work1d.KKT[466] = 1;
  work1d.KKT[468] = 1;
  work1d.KKT[470] = 1;
  work1d.KKT[472] = 1;
  work1d.KKT[474] = 1;
  work1d.KKT[476] = 1;
  work1d.KKT[478] = 1;
  work1d.KKT[480] = 1;
  work1d.KKT[482] = 1;
  work1d.KKT[484] = 1;
  work1d.KKT[486] = 1;
  work1d.KKT[488] = 1;
  work1d.KKT[490] = 1;
  work1d.KKT[492] = 1;
  work1d.KKT[494] = 1;
  work1d.KKT[496] = 1;
  work1d.KKT[498] = 1;
  work1d.KKT[500] = 1;
  work1d.KKT[502] = 1;
  work1d.KKT[504] = 1;
  work1d.KKT[506] = 1;
  work1d.KKT[508] = 1;
  work1d.KKT[510] = 1;
  work1d.KKT[512] = 1;
  work1d.KKT[514] = 1;
  work1d.KKT[516] = 1;
  work1d.KKT[518] = 1;
  work1d.KKT[520] = 1;
  work1d.KKT[522] = 1;
  work1d.KKT[524] = 1;
  work1d.KKT[526] = 1;
  work1d.KKT[528] = 1;
  work1d.KKT[530] = 1;
  work1d.KKT[532] = 1;
  work1d.KKT[534] = 1;
  work1d.KKT[536] = 1;
  work1d.KKT[538] = 1;
  work1d.KKT[540] = 1;
  work1d.KKT[542] = 1;
  work1d.KKT[544] = 1;
  work1d.KKT[546] = 1;
  work1d.KKT[548] = 1;
  work1d.KKT[550] = 1;
  work1d.KKT[552] = 1;
  work1d.KKT[554] = 1;
  work1d.KKT[556] = 1;
  work1d.KKT[558] = 1;
  work1d.KKT[560] = 1;
  work1d.KKT[562] = 1;
  work1d.KKT[564] = 1;
  work1d.KKT[566] = 1;
  work1d.KKT[568] = 1;
  work1d.KKT[570] = 1;
  work1d.KKT[572] = 1;
  work1d.KKT[574] = 1;
  work1d.KKT[576] = 1;
  work1d.KKT[578] = 1;
  work1d.KKT[580] = 1;
  work1d.KKT[582] = 1;
  work1d.KKT[584] = 1;
  work1d.KKT[586] = 1;
  work1d.KKT[588] = 1;
  work1d.KKT[590] = 1;
  work1d.KKT[592] = 1;
  work1d.KKT[594] = 1;
  work1d.KKT[596] = 1;
  work1d.KKT[598] = 1;
  work1d.KKT[600] = 1;
  work1d.KKT[602] = 1;
  work1d.KKT[604] = 1;
  work1d.KKT[606] = 1;
  work1d.KKT[608] = 1;
  work1d.KKT[610] = 1;
  work1d.KKT[612] = 1;
  work1d.KKT[614] = 1;
  work1d.KKT[616] = 1;
  work1d.KKT[618] = 1;
  work1d.KKT[620] = 1;
  work1d.KKT[622] = 1;
  work1d.KKT[624] = 1;
  work1d.KKT[626] = 1;
  work1d.KKT[628] = 1;
  work1d.KKT[630] = 1;
  work1d.KKT[632] = 1;
  work1d.KKT[634] = 1;
  work1d.KKT[636] = 1;
  work1d.KKT[638] = 1;
  work1d.KKT[640] = 1;
  work1d.KKT[887] = work1d.block_33[0];
  work1d.KKT[891] = work1d.block_33[0];
  work1d.KKT[893] = work1d.block_33[0];
  work1d.KKT[895] = work1d.block_33[0];
  work1d.KKT[899] = work1d.block_33[0];
  work1d.KKT[901] = work1d.block_33[0];
  work1d.KKT[903] = work1d.block_33[0];
  work1d.KKT[907] = work1d.block_33[0];
  work1d.KKT[909] = work1d.block_33[0];
  work1d.KKT[911] = work1d.block_33[0];
  work1d.KKT[915] = work1d.block_33[0];
  work1d.KKT[917] = work1d.block_33[0];
  work1d.KKT[919] = work1d.block_33[0];
  work1d.KKT[923] = work1d.block_33[0];
  work1d.KKT[925] = work1d.block_33[0];
  work1d.KKT[927] = work1d.block_33[0];
  work1d.KKT[931] = work1d.block_33[0];
  work1d.KKT[933] = work1d.block_33[0];
  work1d.KKT[935] = work1d.block_33[0];
  work1d.KKT[939] = work1d.block_33[0];
  work1d.KKT[941] = work1d.block_33[0];
  work1d.KKT[943] = work1d.block_33[0];
  work1d.KKT[947] = work1d.block_33[0];
  work1d.KKT[949] = work1d.block_33[0];
  work1d.KKT[951] = work1d.block_33[0];
  work1d.KKT[955] = work1d.block_33[0];
  work1d.KKT[957] = work1d.block_33[0];
  work1d.KKT[959] = work1d.block_33[0];
  work1d.KKT[963] = work1d.block_33[0];
  work1d.KKT[965] = work1d.block_33[0];
  work1d.KKT[967] = work1d.block_33[0];
  work1d.KKT[971] = work1d.block_33[0];
  work1d.KKT[973] = work1d.block_33[0];
  work1d.KKT[975] = work1d.block_33[0];
  work1d.KKT[979] = work1d.block_33[0];
  work1d.KKT[981] = work1d.block_33[0];
  work1d.KKT[983] = work1d.block_33[0];
  work1d.KKT[987] = work1d.block_33[0];
  work1d.KKT[989] = work1d.block_33[0];
  work1d.KKT[991] = work1d.block_33[0];
  work1d.KKT[995] = work1d.block_33[0];
  work1d.KKT[997] = work1d.block_33[0];
  work1d.KKT[999] = work1d.block_33[0];
  work1d.KKT[1003] = work1d.block_33[0];
  work1d.KKT[1005] = work1d.block_33[0];
  work1d.KKT[1007] = work1d.block_33[0];
  work1d.KKT[1011] = work1d.block_33[0];
  work1d.KKT[1013] = work1d.block_33[0];
  work1d.KKT[1015] = work1d.block_33[0];
  work1d.KKT[1019] = work1d.block_33[0];
  work1d.KKT[1021] = work1d.block_33[0];
  work1d.KKT[1023] = work1d.block_33[0];
  work1d.KKT[1027] = work1d.block_33[0];
  work1d.KKT[1029] = work1d.block_33[0];
  work1d.KKT[1031] = work1d.block_33[0];
  work1d.KKT[1035] = work1d.block_33[0];
  work1d.KKT[1037] = work1d.block_33[0];
  work1d.KKT[1039] = work1d.block_33[0];
  work1d.KKT[1043] = work1d.block_33[0];
  work1d.KKT[1045] = work1d.block_33[0];
  work1d.KKT[1047] = work1d.block_33[0];
  work1d.KKT[1051] = work1d.block_33[0];
  work1d.KKT[1053] = work1d.block_33[0];
  work1d.KKT[1055] = work1d.block_33[0];
  work1d.KKT[1059] = work1d.block_33[0];
  work1d.KKT[1061] = work1d.block_33[0];
  work1d.KKT[1063] = work1d.block_33[0];
  work1d.KKT[1067] = work1d.block_33[0];
  work1d.KKT[1069] = work1d.block_33[0];
  work1d.KKT[1071] = work1d.block_33[0];
  work1d.KKT[1075] = work1d.block_33[0];
  work1d.KKT[1077] = work1d.block_33[0];
  work1d.KKT[1079] = work1d.block_33[0];
  work1d.KKT[1083] = work1d.block_33[0];
  work1d.KKT[1085] = work1d.block_33[0];
  work1d.KKT[1087] = work1d.block_33[0];
  work1d.KKT[1091] = work1d.block_33[0];
  work1d.KKT[1093] = work1d.block_33[0];
  work1d.KKT[1095] = work1d.block_33[0];
  work1d.KKT[1099] = work1d.block_33[0];
  work1d.KKT[1101] = work1d.block_33[0];
  work1d.KKT[1103] = work1d.block_33[0];
  work1d.KKT[1107] = work1d.block_33[0];
  work1d.KKT[1109] = work1d.block_33[0];
  work1d.KKT[1111] = work1d.block_33[0];
  work1d.KKT[1115] = work1d.block_33[0];
  work1d.KKT[1117] = work1d.block_33[0];
  work1d.KKT[1119] = work1d.block_33[0];
  work1d.KKT[1123] = work1d.block_33[0];
  work1d.KKT[1125] = work1d.block_33[0];
  work1d.KKT[1127] = work1d.block_33[0];
  work1d.KKT[1131] = work1d.block_33[0];
  work1d.KKT[1133] = work1d.block_33[0];
  work1d.KKT[1135] = work1d.block_33[0];
  work1d.KKT[1139] = work1d.block_33[0];
  work1d.KKT[1141] = work1d.block_33[0];
  work1d.KKT[1143] = work1d.block_33[0];
  work1d.KKT[1147] = work1d.block_33[0];
  work1d.KKT[1149] = work1d.block_33[0];
  work1d.KKT[1151] = work1d.block_33[0];
  work1d.KKT[1155] = work1d.block_33[0];
  work1d.KKT[1157] = work1d.block_33[0];
  work1d.KKT[1159] = work1d.block_33[0];
  work1d.KKT[1163] = work1d.block_33[0];
  work1d.KKT[1165] = work1d.block_33[0];
  work1d.KKT[1167] = work1d.block_33[0];
  work1d.KKT[1171] = work1d.block_33[0];
  work1d.KKT[1173] = work1d.block_33[0];
  work1d.KKT[1175] = work1d.block_33[0];
  work1d.KKT[1179] = work1d.block_33[0];
  work1d.KKT[1181] = work1d.block_33[0];
  work1d.KKT[1183] = work1d.block_33[0];
  work1d.KKT[1187] = work1d.block_33[0];
  work1d.KKT[1189] = work1d.block_33[0];
  work1d.KKT[1191] = work1d.block_33[0];
  work1d.KKT[1195] = work1d.block_33[0];
  work1d.KKT[1197] = work1d.block_33[0];
  work1d.KKT[1199] = work1d.block_33[0];
  work1d.KKT[1203] = work1d.block_33[0];
  work1d.KKT[1205] = work1d.block_33[0];
  work1d.KKT[1209] = work1d.block_33[0];
  work1d.KKT[1213] = work1d.block_33[0];
  work1d.KKT[1215] = work1d.block_33[0];
  work1d.KKT[1217] = work1d.block_33[0];
  work1d.KKT[1221] = work1d.block_33[0];
  work1d.KKT[1223] = work1d.block_33[0];
  work1d.KKT[1225] = work1d.block_33[0];
  work1d.KKT[1229] = work1d.block_33[0];
  work1d.KKT[1231] = work1d.block_33[0];
  work1d.KKT[1233] = work1d.block_33[0];
  work1d.KKT[1237] = work1d.block_33[0];
  work1d.KKT[1239] = work1d.block_33[0];
  work1d.KKT[1241] = work1d.block_33[0];
  work1d.KKT[1245] = work1d.block_33[0];
  work1d.KKT[1247] = work1d.block_33[0];
  work1d.KKT[1249] = work1d.block_33[0];
  work1d.KKT[1253] = work1d.block_33[0];
  work1d.KKT[1255] = work1d.block_33[0];
  work1d.KKT[1257] = work1d.block_33[0];
  work1d.KKT[1261] = work1d.block_33[0];
  work1d.KKT[1263] = work1d.block_33[0];
  work1d.KKT[1265] = work1d.block_33[0];
  work1d.KKT[1269] = work1d.block_33[0];
  work1d.KKT[1271] = work1d.block_33[0];
  work1d.KKT[1273] = work1d.block_33[0];
  work1d.KKT[1277] = work1d.block_33[0];
  work1d.KKT[1279] = work1d.block_33[0];
  work1d.KKT[1281] = work1d.block_33[0];
  work1d.KKT[1285] = work1d.block_33[0];
  work1d.KKT[1287] = work1d.block_33[0];
  work1d.KKT[1289] = work1d.block_33[0];
  work1d.KKT[1293] = work1d.block_33[0];
  work1d.KKT[1295] = work1d.block_33[0];
  work1d.KKT[1297] = work1d.block_33[0];
  work1d.KKT[1301] = work1d.block_33[0];
  work1d.KKT[1303] = work1d.block_33[0];
  work1d.KKT[1305] = work1d.block_33[0];
  work1d.KKT[1309] = work1d.block_33[0];
  work1d.KKT[1311] = work1d.block_33[0];
  work1d.KKT[1313] = work1d.block_33[0];
  work1d.KKT[1317] = work1d.block_33[0];
  work1d.KKT[1319] = work1d.block_33[0];
  work1d.KKT[1321] = work1d.block_33[0];
  work1d.KKT[1325] = work1d.block_33[0];
  work1d.KKT[1327] = work1d.block_33[0];
  work1d.KKT[1329] = work1d.block_33[0];
  work1d.KKT[1333] = work1d.block_33[0];
  work1d.KKT[1335] = work1d.block_33[0];
  work1d.KKT[1337] = work1d.block_33[0];
  work1d.KKT[1341] = work1d.block_33[0];
  work1d.KKT[1343] = work1d.block_33[0];
  work1d.KKT[1345] = work1d.block_33[0];
  work1d.KKT[1349] = work1d.block_33[0];
  work1d.KKT[1351] = work1d.block_33[0];
  work1d.KKT[1353] = work1d.block_33[0];
  work1d.KKT[1357] = work1d.block_33[0];
  work1d.KKT[1359] = work1d.block_33[0];
  work1d.KKT[1361] = work1d.block_33[0];
  work1d.KKT[1365] = work1d.block_33[0];
  work1d.KKT[1367] = work1d.block_33[0];
  work1d.KKT[1369] = work1d.block_33[0];
  work1d.KKT[1373] = work1d.block_33[0];
  work1d.KKT[1375] = work1d.block_33[0];
  work1d.KKT[1377] = work1d.block_33[0];
  work1d.KKT[1381] = work1d.block_33[0];
  work1d.KKT[1383] = work1d.block_33[0];
  work1d.KKT[1385] = work1d.block_33[0];
  work1d.KKT[1389] = work1d.block_33[0];
  work1d.KKT[1391] = work1d.block_33[0];
  work1d.KKT[1393] = work1d.block_33[0];
  work1d.KKT[1397] = work1d.block_33[0];
  work1d.KKT[1399] = work1d.block_33[0];
  work1d.KKT[1401] = work1d.block_33[0];
  work1d.KKT[1405] = work1d.block_33[0];
  work1d.KKT[1407] = work1d.block_33[0];
  work1d.KKT[1409] = work1d.block_33[0];
  work1d.KKT[1413] = work1d.block_33[0];
  work1d.KKT[1415] = work1d.block_33[0];
  work1d.KKT[1417] = work1d.block_33[0];
  work1d.KKT[1421] = work1d.block_33[0];
  work1d.KKT[1423] = work1d.block_33[0];
  work1d.KKT[1425] = work1d.block_33[0];
  work1d.KKT[1429] = work1d.block_33[0];
  work1d.KKT[1431] = work1d.block_33[0];
  work1d.KKT[1433] = work1d.block_33[0];
  work1d.KKT[1437] = work1d.block_33[0];
  work1d.KKT[1439] = work1d.block_33[0];
  work1d.KKT[1441] = work1d.block_33[0];
  work1d.KKT[1445] = work1d.block_33[0];
  work1d.KKT[1447] = work1d.block_33[0];
  work1d.KKT[1449] = work1d.block_33[0];
  work1d.KKT[1453] = work1d.block_33[0];
  work1d.KKT[1455] = work1d.block_33[0];
  work1d.KKT[1457] = work1d.block_33[0];
  work1d.KKT[1461] = work1d.block_33[0];
  work1d.KKT[1463] = work1d.block_33[0];
  work1d.KKT[1465] = work1d.block_33[0];
  work1d.KKT[1469] = work1d.block_33[0];
  work1d.KKT[1471] = work1d.block_33[0];
  work1d.KKT[1473] = work1d.block_33[0];
  work1d.KKT[1477] = work1d.block_33[0];
  work1d.KKT[1479] = work1d.block_33[0];
  work1d.KKT[1481] = work1d.block_33[0];
  work1d.KKT[1485] = work1d.block_33[0];
  work1d.KKT[1487] = work1d.block_33[0];
  work1d.KKT[1489] = work1d.block_33[0];
  work1d.KKT[1493] = work1d.block_33[0];
  work1d.KKT[1495] = work1d.block_33[0];
  work1d.KKT[1497] = work1d.block_33[0];
  work1d.KKT[1501] = work1d.block_33[0];
  work1d.KKT[1503] = work1d.block_33[0];
  work1d.KKT[1505] = work1d.block_33[0];
  work1d.KKT[1509] = work1d.block_33[0];
  work1d.KKT[1511] = work1d.block_33[0];
  work1d.KKT[1513] = work1d.block_33[0];
  work1d.KKT[1517] = work1d.block_33[0];
  work1d.KKT[1519] = work1d.block_33[0];
  work1d.KKT[1521] = work1d.block_33[0];
  work1d.KKT[1525] = work1d.block_33[0];
  work1d.KKT[1527] = work1d.block_33[0];
  work1d.KKT[641] = work1d.block_33[0];
  work1d.KKT[643] = work1d.block_33[0];
  work1d.KKT[645] = work1d.block_33[0];
  work1d.KKT[647] = work1d.block_33[0];
  work1d.KKT[649] = work1d.block_33[0];
  work1d.KKT[651] = work1d.block_33[0];
  work1d.KKT[653] = work1d.block_33[0];
  work1d.KKT[655] = work1d.block_33[0];
  work1d.KKT[657] = work1d.block_33[0];
  work1d.KKT[659] = work1d.block_33[0];
  work1d.KKT[661] = work1d.block_33[0];
  work1d.KKT[663] = work1d.block_33[0];
  work1d.KKT[665] = work1d.block_33[0];
  work1d.KKT[667] = work1d.block_33[0];
  work1d.KKT[669] = work1d.block_33[0];
  work1d.KKT[671] = work1d.block_33[0];
  work1d.KKT[673] = work1d.block_33[0];
  work1d.KKT[675] = work1d.block_33[0];
  work1d.KKT[677] = work1d.block_33[0];
  work1d.KKT[679] = work1d.block_33[0];
  work1d.KKT[681] = work1d.block_33[0];
  work1d.KKT[683] = work1d.block_33[0];
  work1d.KKT[685] = work1d.block_33[0];
  work1d.KKT[687] = work1d.block_33[0];
  work1d.KKT[689] = work1d.block_33[0];
  work1d.KKT[691] = work1d.block_33[0];
  work1d.KKT[693] = work1d.block_33[0];
  work1d.KKT[695] = work1d.block_33[0];
  work1d.KKT[697] = work1d.block_33[0];
  work1d.KKT[699] = work1d.block_33[0];
  work1d.KKT[701] = work1d.block_33[0];
  work1d.KKT[703] = work1d.block_33[0];
  work1d.KKT[705] = work1d.block_33[0];
  work1d.KKT[707] = work1d.block_33[0];
  work1d.KKT[709] = work1d.block_33[0];
  work1d.KKT[711] = work1d.block_33[0];
  work1d.KKT[713] = work1d.block_33[0];
  work1d.KKT[715] = work1d.block_33[0];
  work1d.KKT[717] = work1d.block_33[0];
  work1d.KKT[719] = work1d.block_33[0];
  work1d.KKT[721] = work1d.block_33[0];
  work1d.KKT[723] = work1d.block_33[0];
  work1d.KKT[725] = work1d.block_33[0];
  work1d.KKT[727] = work1d.block_33[0];
  work1d.KKT[729] = work1d.block_33[0];
  work1d.KKT[731] = work1d.block_33[0];
  work1d.KKT[733] = work1d.block_33[0];
  work1d.KKT[735] = work1d.block_33[0];
  work1d.KKT[737] = work1d.block_33[0];
  work1d.KKT[739] = work1d.block_33[0];
  work1d.KKT[741] = work1d.block_33[0];
  work1d.KKT[743] = work1d.block_33[0];
  work1d.KKT[745] = work1d.block_33[0];
  work1d.KKT[747] = work1d.block_33[0];
  work1d.KKT[749] = work1d.block_33[0];
  work1d.KKT[751] = work1d.block_33[0];
  work1d.KKT[753] = work1d.block_33[0];
  work1d.KKT[755] = work1d.block_33[0];
  work1d.KKT[757] = work1d.block_33[0];
  work1d.KKT[759] = work1d.block_33[0];
  work1d.KKT[761] = work1d.block_33[0];
  work1d.KKT[763] = work1d.block_33[0];
  work1d.KKT[765] = work1d.block_33[0];
  work1d.KKT[767] = work1d.block_33[0];
  work1d.KKT[769] = work1d.block_33[0];
  work1d.KKT[771] = work1d.block_33[0];
  work1d.KKT[773] = work1d.block_33[0];
  work1d.KKT[775] = work1d.block_33[0];
  work1d.KKT[777] = work1d.block_33[0];
  work1d.KKT[779] = work1d.block_33[0];
  work1d.KKT[781] = work1d.block_33[0];
  work1d.KKT[783] = work1d.block_33[0];
  work1d.KKT[785] = work1d.block_33[0];
  work1d.KKT[787] = work1d.block_33[0];
  work1d.KKT[789] = work1d.block_33[0];
  work1d.KKT[791] = work1d.block_33[0];
  work1d.KKT[793] = work1d.block_33[0];
  work1d.KKT[795] = work1d.block_33[0];
  work1d.KKT[797] = work1d.block_33[0];
  work1d.KKT[799] = work1d.block_33[0];
  work1d.KKT[888] = 1;
  work1d.KKT[889] = -1;
  work1d.KKT[892] = 1;
  work1d.KKT[890] = -1;
  work1d.KKT[894] = -1;
  work1d.KKT[896] = 1;
  work1d.KKT[897] = -1;
  work1d.KKT[900] = 1;
  work1d.KKT[898] = -1;
  work1d.KKT[902] = -1;
  work1d.KKT[904] = 1;
  work1d.KKT[905] = -1;
  work1d.KKT[908] = 1;
  work1d.KKT[906] = -1;
  work1d.KKT[910] = -1;
  work1d.KKT[912] = 1;
  work1d.KKT[913] = -1;
  work1d.KKT[916] = 1;
  work1d.KKT[914] = -1;
  work1d.KKT[918] = -1;
  work1d.KKT[920] = 1;
  work1d.KKT[921] = -1;
  work1d.KKT[924] = 1;
  work1d.KKT[922] = -1;
  work1d.KKT[926] = -1;
  work1d.KKT[928] = 1;
  work1d.KKT[929] = -1;
  work1d.KKT[932] = 1;
  work1d.KKT[930] = -1;
  work1d.KKT[934] = -1;
  work1d.KKT[936] = 1;
  work1d.KKT[937] = -1;
  work1d.KKT[940] = 1;
  work1d.KKT[938] = -1;
  work1d.KKT[942] = -1;
  work1d.KKT[944] = 1;
  work1d.KKT[945] = -1;
  work1d.KKT[948] = 1;
  work1d.KKT[946] = -1;
  work1d.KKT[950] = -1;
  work1d.KKT[952] = 1;
  work1d.KKT[953] = -1;
  work1d.KKT[956] = 1;
  work1d.KKT[954] = -1;
  work1d.KKT[958] = -1;
  work1d.KKT[960] = 1;
  work1d.KKT[961] = -1;
  work1d.KKT[964] = 1;
  work1d.KKT[962] = -1;
  work1d.KKT[966] = -1;
  work1d.KKT[968] = 1;
  work1d.KKT[969] = -1;
  work1d.KKT[972] = 1;
  work1d.KKT[970] = -1;
  work1d.KKT[974] = -1;
  work1d.KKT[976] = 1;
  work1d.KKT[977] = -1;
  work1d.KKT[980] = 1;
  work1d.KKT[978] = -1;
  work1d.KKT[982] = -1;
  work1d.KKT[984] = 1;
  work1d.KKT[985] = -1;
  work1d.KKT[988] = 1;
  work1d.KKT[986] = -1;
  work1d.KKT[990] = -1;
  work1d.KKT[992] = 1;
  work1d.KKT[993] = -1;
  work1d.KKT[996] = 1;
  work1d.KKT[994] = -1;
  work1d.KKT[998] = -1;
  work1d.KKT[1000] = 1;
  work1d.KKT[1001] = -1;
  work1d.KKT[1004] = 1;
  work1d.KKT[1002] = -1;
  work1d.KKT[1006] = -1;
  work1d.KKT[1008] = 1;
  work1d.KKT[1009] = -1;
  work1d.KKT[1012] = 1;
  work1d.KKT[1010] = -1;
  work1d.KKT[1014] = -1;
  work1d.KKT[1016] = 1;
  work1d.KKT[1017] = -1;
  work1d.KKT[1020] = 1;
  work1d.KKT[1018] = -1;
  work1d.KKT[1022] = -1;
  work1d.KKT[1024] = 1;
  work1d.KKT[1025] = -1;
  work1d.KKT[1028] = 1;
  work1d.KKT[1026] = -1;
  work1d.KKT[1030] = -1;
  work1d.KKT[1032] = 1;
  work1d.KKT[1033] = -1;
  work1d.KKT[1036] = 1;
  work1d.KKT[1034] = -1;
  work1d.KKT[1038] = -1;
  work1d.KKT[1040] = 1;
  work1d.KKT[1041] = -1;
  work1d.KKT[1044] = 1;
  work1d.KKT[1042] = -1;
  work1d.KKT[1046] = -1;
  work1d.KKT[1048] = 1;
  work1d.KKT[1049] = -1;
  work1d.KKT[1052] = 1;
  work1d.KKT[1050] = -1;
  work1d.KKT[1054] = -1;
  work1d.KKT[1056] = 1;
  work1d.KKT[1057] = -1;
  work1d.KKT[1060] = 1;
  work1d.KKT[1058] = -1;
  work1d.KKT[1062] = -1;
  work1d.KKT[1064] = 1;
  work1d.KKT[1065] = -1;
  work1d.KKT[1068] = 1;
  work1d.KKT[1066] = -1;
  work1d.KKT[1070] = -1;
  work1d.KKT[1072] = 1;
  work1d.KKT[1073] = -1;
  work1d.KKT[1076] = 1;
  work1d.KKT[1074] = -1;
  work1d.KKT[1078] = -1;
  work1d.KKT[1080] = 1;
  work1d.KKT[1081] = -1;
  work1d.KKT[1084] = 1;
  work1d.KKT[1082] = -1;
  work1d.KKT[1086] = -1;
  work1d.KKT[1088] = 1;
  work1d.KKT[1089] = -1;
  work1d.KKT[1092] = 1;
  work1d.KKT[1090] = -1;
  work1d.KKT[1094] = -1;
  work1d.KKT[1096] = 1;
  work1d.KKT[1097] = -1;
  work1d.KKT[1100] = 1;
  work1d.KKT[1098] = -1;
  work1d.KKT[1102] = -1;
  work1d.KKT[1104] = 1;
  work1d.KKT[1105] = -1;
  work1d.KKT[1108] = 1;
  work1d.KKT[1106] = -1;
  work1d.KKT[1110] = -1;
  work1d.KKT[1112] = 1;
  work1d.KKT[1113] = -1;
  work1d.KKT[1116] = 1;
  work1d.KKT[1114] = -1;
  work1d.KKT[1118] = -1;
  work1d.KKT[1120] = 1;
  work1d.KKT[1121] = -1;
  work1d.KKT[1124] = 1;
  work1d.KKT[1122] = -1;
  work1d.KKT[1126] = -1;
  work1d.KKT[1128] = 1;
  work1d.KKT[1129] = -1;
  work1d.KKT[1132] = 1;
  work1d.KKT[1130] = -1;
  work1d.KKT[1134] = -1;
  work1d.KKT[1136] = 1;
  work1d.KKT[1137] = -1;
  work1d.KKT[1140] = 1;
  work1d.KKT[1138] = -1;
  work1d.KKT[1142] = -1;
  work1d.KKT[1144] = 1;
  work1d.KKT[1145] = -1;
  work1d.KKT[1148] = 1;
  work1d.KKT[1146] = -1;
  work1d.KKT[1150] = -1;
  work1d.KKT[1152] = 1;
  work1d.KKT[1153] = -1;
  work1d.KKT[1156] = 1;
  work1d.KKT[1154] = -1;
  work1d.KKT[1158] = -1;
  work1d.KKT[1160] = 1;
  work1d.KKT[1161] = -1;
  work1d.KKT[1164] = 1;
  work1d.KKT[1162] = -1;
  work1d.KKT[1166] = -1;
  work1d.KKT[1168] = 1;
  work1d.KKT[1169] = -1;
  work1d.KKT[1172] = 1;
  work1d.KKT[1170] = -1;
  work1d.KKT[1174] = -1;
  work1d.KKT[1176] = 1;
  work1d.KKT[1177] = -1;
  work1d.KKT[1180] = 1;
  work1d.KKT[1178] = -1;
  work1d.KKT[1182] = -1;
  work1d.KKT[1184] = 1;
  work1d.KKT[1185] = -1;
  work1d.KKT[1188] = 1;
  work1d.KKT[1186] = -1;
  work1d.KKT[1190] = -1;
  work1d.KKT[1192] = 1;
  work1d.KKT[1193] = -1;
  work1d.KKT[1196] = 1;
  work1d.KKT[1194] = -1;
  work1d.KKT[1198] = -1;
  work1d.KKT[1200] = 1;
  work1d.KKT[1201] = -1;
  work1d.KKT[1204] = 1;
  work1d.KKT[1202] = -1;
  work1d.KKT[1206] = -1;
  work1d.KKT[1210] = 1;
  work1d.KKT[1211] = -1;
  work1d.KKT[1214] = 1;
  work1d.KKT[1212] = -1;
  work1d.KKT[1216] = -1;
  work1d.KKT[1218] = 1;
  work1d.KKT[1219] = -1;
  work1d.KKT[1222] = 1;
  work1d.KKT[1220] = -1;
  work1d.KKT[1224] = -1;
  work1d.KKT[1226] = 1;
  work1d.KKT[1227] = -1;
  work1d.KKT[1230] = 1;
  work1d.KKT[1228] = -1;
  work1d.KKT[1232] = -1;
  work1d.KKT[1234] = 1;
  work1d.KKT[1235] = -1;
  work1d.KKT[1238] = 1;
  work1d.KKT[1236] = -1;
  work1d.KKT[1240] = -1;
  work1d.KKT[1242] = 1;
  work1d.KKT[1243] = -1;
  work1d.KKT[1246] = 1;
  work1d.KKT[1244] = -1;
  work1d.KKT[1248] = -1;
  work1d.KKT[1250] = 1;
  work1d.KKT[1251] = -1;
  work1d.KKT[1254] = 1;
  work1d.KKT[1252] = -1;
  work1d.KKT[1256] = -1;
  work1d.KKT[1258] = 1;
  work1d.KKT[1259] = -1;
  work1d.KKT[1262] = 1;
  work1d.KKT[1260] = -1;
  work1d.KKT[1264] = -1;
  work1d.KKT[1266] = 1;
  work1d.KKT[1267] = -1;
  work1d.KKT[1270] = 1;
  work1d.KKT[1268] = -1;
  work1d.KKT[1272] = -1;
  work1d.KKT[1274] = 1;
  work1d.KKT[1275] = -1;
  work1d.KKT[1278] = 1;
  work1d.KKT[1276] = -1;
  work1d.KKT[1280] = -1;
  work1d.KKT[1282] = 1;
  work1d.KKT[1283] = -1;
  work1d.KKT[1286] = 1;
  work1d.KKT[1284] = -1;
  work1d.KKT[1288] = -1;
  work1d.KKT[1290] = 1;
  work1d.KKT[1291] = -1;
  work1d.KKT[1294] = 1;
  work1d.KKT[1292] = -1;
  work1d.KKT[1296] = -1;
  work1d.KKT[1298] = 1;
  work1d.KKT[1299] = -1;
  work1d.KKT[1302] = 1;
  work1d.KKT[1300] = -1;
  work1d.KKT[1304] = -1;
  work1d.KKT[1306] = 1;
  work1d.KKT[1307] = -1;
  work1d.KKT[1310] = 1;
  work1d.KKT[1308] = -1;
  work1d.KKT[1312] = -1;
  work1d.KKT[1314] = 1;
  work1d.KKT[1315] = -1;
  work1d.KKT[1318] = 1;
  work1d.KKT[1316] = -1;
  work1d.KKT[1320] = -1;
  work1d.KKT[1322] = 1;
  work1d.KKT[1323] = -1;
  work1d.KKT[1326] = 1;
  work1d.KKT[1324] = -1;
  work1d.KKT[1328] = -1;
  work1d.KKT[1330] = 1;
  work1d.KKT[1331] = -1;
  work1d.KKT[1334] = 1;
  work1d.KKT[1332] = -1;
  work1d.KKT[1336] = -1;
  work1d.KKT[1338] = 1;
  work1d.KKT[1339] = -1;
  work1d.KKT[1342] = 1;
  work1d.KKT[1340] = -1;
  work1d.KKT[1344] = -1;
  work1d.KKT[1346] = 1;
  work1d.KKT[1347] = -1;
  work1d.KKT[1350] = 1;
  work1d.KKT[1348] = -1;
  work1d.KKT[1352] = -1;
  work1d.KKT[1354] = 1;
  work1d.KKT[1355] = -1;
  work1d.KKT[1358] = 1;
  work1d.KKT[1356] = -1;
  work1d.KKT[1360] = -1;
  work1d.KKT[1362] = 1;
  work1d.KKT[1363] = -1;
  work1d.KKT[1366] = 1;
  work1d.KKT[1364] = -1;
  work1d.KKT[1368] = -1;
  work1d.KKT[1370] = 1;
  work1d.KKT[1371] = -1;
  work1d.KKT[1374] = 1;
  work1d.KKT[1372] = -1;
  work1d.KKT[1376] = -1;
  work1d.KKT[1378] = 1;
  work1d.KKT[1379] = -1;
  work1d.KKT[1382] = 1;
  work1d.KKT[1380] = -1;
  work1d.KKT[1384] = -1;
  work1d.KKT[1386] = 1;
  work1d.KKT[1387] = -1;
  work1d.KKT[1390] = 1;
  work1d.KKT[1388] = -1;
  work1d.KKT[1392] = -1;
  work1d.KKT[1394] = 1;
  work1d.KKT[1395] = -1;
  work1d.KKT[1398] = 1;
  work1d.KKT[1396] = -1;
  work1d.KKT[1400] = -1;
  work1d.KKT[1402] = 1;
  work1d.KKT[1403] = -1;
  work1d.KKT[1406] = 1;
  work1d.KKT[1404] = -1;
  work1d.KKT[1408] = -1;
  work1d.KKT[1410] = 1;
  work1d.KKT[1411] = -1;
  work1d.KKT[1414] = 1;
  work1d.KKT[1412] = -1;
  work1d.KKT[1416] = -1;
  work1d.KKT[1418] = 1;
  work1d.KKT[1419] = -1;
  work1d.KKT[1422] = 1;
  work1d.KKT[1420] = -1;
  work1d.KKT[1424] = -1;
  work1d.KKT[1426] = 1;
  work1d.KKT[1427] = -1;
  work1d.KKT[1430] = 1;
  work1d.KKT[1428] = -1;
  work1d.KKT[1432] = -1;
  work1d.KKT[1434] = 1;
  work1d.KKT[1435] = -1;
  work1d.KKT[1438] = 1;
  work1d.KKT[1436] = -1;
  work1d.KKT[1440] = -1;
  work1d.KKT[1442] = 1;
  work1d.KKT[1443] = -1;
  work1d.KKT[1446] = 1;
  work1d.KKT[1444] = -1;
  work1d.KKT[1448] = -1;
  work1d.KKT[1450] = 1;
  work1d.KKT[1451] = -1;
  work1d.KKT[1454] = 1;
  work1d.KKT[1452] = -1;
  work1d.KKT[1456] = -1;
  work1d.KKT[1458] = 1;
  work1d.KKT[1459] = -1;
  work1d.KKT[1462] = 1;
  work1d.KKT[1460] = -1;
  work1d.KKT[1464] = -1;
  work1d.KKT[1466] = 1;
  work1d.KKT[1467] = -1;
  work1d.KKT[1470] = 1;
  work1d.KKT[1468] = -1;
  work1d.KKT[1472] = -1;
  work1d.KKT[1474] = 1;
  work1d.KKT[1475] = -1;
  work1d.KKT[1478] = 1;
  work1d.KKT[1476] = -1;
  work1d.KKT[1480] = -1;
  work1d.KKT[1482] = 1;
  work1d.KKT[1483] = -1;
  work1d.KKT[1486] = 1;
  work1d.KKT[1484] = -1;
  work1d.KKT[1488] = -1;
  work1d.KKT[1490] = 1;
  work1d.KKT[1491] = -1;
  work1d.KKT[1494] = 1;
  work1d.KKT[1492] = -1;
  work1d.KKT[1496] = -1;
  work1d.KKT[1498] = 1;
  work1d.KKT[1499] = -1;
  work1d.KKT[1502] = 1;
  work1d.KKT[1500] = -1;
  work1d.KKT[1504] = -1;
  work1d.KKT[1506] = 1;
  work1d.KKT[1507] = -1;
  work1d.KKT[1510] = 1;
  work1d.KKT[1508] = -1;
  work1d.KKT[1512] = -1;
  work1d.KKT[1514] = 1;
  work1d.KKT[1515] = -1;
  work1d.KKT[1518] = 1;
  work1d.KKT[1516] = -1;
  work1d.KKT[1520] = -1;
  work1d.KKT[1522] = 1;
  work1d.KKT[1523] = -1;
  work1d.KKT[1526] = 1;
  work1d.KKT[1524] = -1;
  work1d.KKT[1528] = -1;
  work1d.KKT[642] = -1;
  work1d.KKT[644] = -1;
  work1d.KKT[646] = -1;
  work1d.KKT[648] = -1;
  work1d.KKT[650] = -1;
  work1d.KKT[652] = -1;
  work1d.KKT[654] = -1;
  work1d.KKT[656] = -1;
  work1d.KKT[658] = -1;
  work1d.KKT[660] = -1;
  work1d.KKT[662] = -1;
  work1d.KKT[664] = -1;
  work1d.KKT[666] = -1;
  work1d.KKT[668] = -1;
  work1d.KKT[670] = -1;
  work1d.KKT[672] = -1;
  work1d.KKT[674] = -1;
  work1d.KKT[676] = -1;
  work1d.KKT[678] = -1;
  work1d.KKT[680] = -1;
  work1d.KKT[682] = -1;
  work1d.KKT[684] = -1;
  work1d.KKT[686] = -1;
  work1d.KKT[688] = -1;
  work1d.KKT[690] = -1;
  work1d.KKT[692] = -1;
  work1d.KKT[694] = -1;
  work1d.KKT[696] = -1;
  work1d.KKT[698] = -1;
  work1d.KKT[700] = -1;
  work1d.KKT[702] = -1;
  work1d.KKT[704] = -1;
  work1d.KKT[706] = -1;
  work1d.KKT[708] = -1;
  work1d.KKT[710] = -1;
  work1d.KKT[712] = -1;
  work1d.KKT[714] = -1;
  work1d.KKT[716] = -1;
  work1d.KKT[718] = -1;
  work1d.KKT[720] = -1;
  work1d.KKT[722] = -1;
  work1d.KKT[724] = -1;
  work1d.KKT[726] = -1;
  work1d.KKT[728] = -1;
  work1d.KKT[730] = -1;
  work1d.KKT[732] = -1;
  work1d.KKT[734] = -1;
  work1d.KKT[736] = -1;
  work1d.KKT[738] = -1;
  work1d.KKT[740] = -1;
  work1d.KKT[742] = -1;
  work1d.KKT[744] = -1;
  work1d.KKT[746] = -1;
  work1d.KKT[748] = -1;
  work1d.KKT[750] = -1;
  work1d.KKT[752] = -1;
  work1d.KKT[754] = -1;
  work1d.KKT[756] = -1;
  work1d.KKT[758] = -1;
  work1d.KKT[760] = -1;
  work1d.KKT[762] = -1;
  work1d.KKT[764] = -1;
  work1d.KKT[766] = -1;
  work1d.KKT[768] = -1;
  work1d.KKT[770] = -1;
  work1d.KKT[772] = -1;
  work1d.KKT[774] = -1;
  work1d.KKT[776] = -1;
  work1d.KKT[778] = -1;
  work1d.KKT[780] = -1;
  work1d.KKT[782] = -1;
  work1d.KKT[784] = -1;
  work1d.KKT[786] = -1;
  work1d.KKT[788] = -1;
  work1d.KKT[790] = -1;
  work1d.KKT[792] = -1;
  work1d.KKT[794] = -1;
  work1d.KKT[796] = -1;
  work1d.KKT[798] = -1;
  work1d.KKT[800] = -1;
  work1d.KKT[803] = -params1d.Bf[0];
  work1d.KKT[801] = 1;
  work1d.KKT[802] = 1;
  work1d.KKT[804] = 1;
  work1d.KKT[806] = -params1d.B[0];
  work1d.KKT[884] = -params1d.A[0];
  work1d.KKT[1616] = -params1d.A[1];
  work1d.KKT[1537] = -params1d.A[2];
  work1d.KKT[1535] = -params1d.A[3];
  work1d.KKT[1618] = -params1d.A[4];
  work1d.KKT[1536] = 1;
  work1d.KKT[1731] = 1;
  work1d.KKT[1538] = 1;
  work1d.KKT[808] = -params1d.B[0];
  work1d.KKT[1620] = -params1d.A[0];
  work1d.KKT[1734] = -params1d.A[1];
  work1d.KKT[1539] = -params1d.A[2];
  work1d.KKT[1733] = -params1d.A[3];
  work1d.KKT[1736] = -params1d.A[4];
  work1d.KKT[1622] = 1;
  work1d.KKT[1737] = 1;
  work1d.KKT[1540] = 1;
  work1d.KKT[810] = -params1d.B[0];
  work1d.KKT[1623] = -params1d.A[0];
  work1d.KKT[1740] = -params1d.A[1];
  work1d.KKT[1541] = -params1d.A[2];
  work1d.KKT[1739] = -params1d.A[3];
  work1d.KKT[1742] = -params1d.A[4];
  work1d.KKT[1625] = 1;
  work1d.KKT[1743] = 1;
  work1d.KKT[1542] = 1;
  work1d.KKT[812] = -params1d.B[0];
  work1d.KKT[1626] = -params1d.A[0];
  work1d.KKT[1746] = -params1d.A[1];
  work1d.KKT[1543] = -params1d.A[2];
  work1d.KKT[1745] = -params1d.A[3];
  work1d.KKT[1748] = -params1d.A[4];
  work1d.KKT[1628] = 1;
  work1d.KKT[1749] = 1;
  work1d.KKT[1544] = 1;
  work1d.KKT[814] = -params1d.B[0];
  work1d.KKT[1629] = -params1d.A[0];
  work1d.KKT[1752] = -params1d.A[1];
  work1d.KKT[1545] = -params1d.A[2];
  work1d.KKT[1751] = -params1d.A[3];
  work1d.KKT[1754] = -params1d.A[4];
  work1d.KKT[1631] = 1;
  work1d.KKT[1755] = 1;
  work1d.KKT[1546] = 1;
  work1d.KKT[816] = -params1d.B[0];
  work1d.KKT[1632] = -params1d.A[0];
  work1d.KKT[1758] = -params1d.A[1];
  work1d.KKT[1547] = -params1d.A[2];
  work1d.KKT[1757] = -params1d.A[3];
  work1d.KKT[1760] = -params1d.A[4];
  work1d.KKT[1634] = 1;
  work1d.KKT[1761] = 1;
  work1d.KKT[1548] = 1;
  work1d.KKT[818] = -params1d.B[0];
  work1d.KKT[1635] = -params1d.A[0];
  work1d.KKT[1764] = -params1d.A[1];
  work1d.KKT[1549] = -params1d.A[2];
  work1d.KKT[1763] = -params1d.A[3];
  work1d.KKT[1766] = -params1d.A[4];
  work1d.KKT[1637] = 1;
  work1d.KKT[1767] = 1;
  work1d.KKT[1550] = 1;
  work1d.KKT[820] = -params1d.B[0];
  work1d.KKT[1638] = -params1d.A[0];
  work1d.KKT[1770] = -params1d.A[1];
  work1d.KKT[1551] = -params1d.A[2];
  work1d.KKT[1769] = -params1d.A[3];
  work1d.KKT[1772] = -params1d.A[4];
  work1d.KKT[1640] = 1;
  work1d.KKT[1773] = 1;
  work1d.KKT[1552] = 1;
  work1d.KKT[822] = -params1d.B[0];
  work1d.KKT[1641] = -params1d.A[0];
  work1d.KKT[1776] = -params1d.A[1];
  work1d.KKT[1553] = -params1d.A[2];
  work1d.KKT[1775] = -params1d.A[3];
  work1d.KKT[1778] = -params1d.A[4];
  work1d.KKT[1643] = 1;
  work1d.KKT[1779] = 1;
  work1d.KKT[1554] = 1;
  work1d.KKT[824] = -params1d.B[0];
  work1d.KKT[1644] = -params1d.A[0];
  work1d.KKT[1782] = -params1d.A[1];
  work1d.KKT[1555] = -params1d.A[2];
  work1d.KKT[1781] = -params1d.A[3];
  work1d.KKT[1784] = -params1d.A[4];
  work1d.KKT[1646] = 1;
  work1d.KKT[1785] = 1;
  work1d.KKT[1556] = 1;
  work1d.KKT[826] = -params1d.B[0];
  work1d.KKT[1647] = -params1d.A[0];
  work1d.KKT[1788] = -params1d.A[1];
  work1d.KKT[1557] = -params1d.A[2];
  work1d.KKT[1787] = -params1d.A[3];
  work1d.KKT[1790] = -params1d.A[4];
  work1d.KKT[1649] = 1;
  work1d.KKT[1791] = 1;
  work1d.KKT[1558] = 1;
  work1d.KKT[828] = -params1d.B[0];
  work1d.KKT[1650] = -params1d.A[0];
  work1d.KKT[1794] = -params1d.A[1];
  work1d.KKT[1559] = -params1d.A[2];
  work1d.KKT[1793] = -params1d.A[3];
  work1d.KKT[1796] = -params1d.A[4];
  work1d.KKT[1652] = 1;
  work1d.KKT[1797] = 1;
  work1d.KKT[1560] = 1;
  work1d.KKT[830] = -params1d.B[0];
  work1d.KKT[1653] = -params1d.A[0];
  work1d.KKT[1800] = -params1d.A[1];
  work1d.KKT[1561] = -params1d.A[2];
  work1d.KKT[1799] = -params1d.A[3];
  work1d.KKT[1802] = -params1d.A[4];
  work1d.KKT[1655] = 1;
  work1d.KKT[1803] = 1;
  work1d.KKT[1562] = 1;
  work1d.KKT[832] = -params1d.B[0];
  work1d.KKT[1656] = -params1d.A[0];
  work1d.KKT[1806] = -params1d.A[1];
  work1d.KKT[1563] = -params1d.A[2];
  work1d.KKT[1805] = -params1d.A[3];
  work1d.KKT[1808] = -params1d.A[4];
  work1d.KKT[1658] = 1;
  work1d.KKT[1809] = 1;
  work1d.KKT[1564] = 1;
  work1d.KKT[834] = -params1d.B[0];
  work1d.KKT[1659] = -params1d.A[0];
  work1d.KKT[1812] = -params1d.A[1];
  work1d.KKT[1565] = -params1d.A[2];
  work1d.KKT[1811] = -params1d.A[3];
  work1d.KKT[1814] = -params1d.A[4];
  work1d.KKT[1661] = 1;
  work1d.KKT[1815] = 1;
  work1d.KKT[1566] = 1;
  work1d.KKT[836] = -params1d.B[0];
  work1d.KKT[1662] = -params1d.A[0];
  work1d.KKT[1818] = -params1d.A[1];
  work1d.KKT[1567] = -params1d.A[2];
  work1d.KKT[1817] = -params1d.A[3];
  work1d.KKT[1820] = -params1d.A[4];
  work1d.KKT[1664] = 1;
  work1d.KKT[1821] = 1;
  work1d.KKT[1568] = 1;
  work1d.KKT[838] = -params1d.B[0];
  work1d.KKT[1665] = -params1d.A[0];
  work1d.KKT[1824] = -params1d.A[1];
  work1d.KKT[1569] = -params1d.A[2];
  work1d.KKT[1823] = -params1d.A[3];
  work1d.KKT[1826] = -params1d.A[4];
  work1d.KKT[1667] = 1;
  work1d.KKT[1827] = 1;
  work1d.KKT[1570] = 1;
  work1d.KKT[840] = -params1d.B[0];
  work1d.KKT[1668] = -params1d.A[0];
  work1d.KKT[1830] = -params1d.A[1];
  work1d.KKT[1571] = -params1d.A[2];
  work1d.KKT[1829] = -params1d.A[3];
  work1d.KKT[1832] = -params1d.A[4];
  work1d.KKT[1670] = 1;
  work1d.KKT[1833] = 1;
  work1d.KKT[1572] = 1;
  work1d.KKT[842] = -params1d.B[0];
  work1d.KKT[1671] = -params1d.A[0];
  work1d.KKT[1836] = -params1d.A[1];
  work1d.KKT[1573] = -params1d.A[2];
  work1d.KKT[1835] = -params1d.A[3];
  work1d.KKT[1838] = -params1d.A[4];
  work1d.KKT[1673] = 1;
  work1d.KKT[1839] = 1;
  work1d.KKT[1574] = 1;
  work1d.KKT[844] = -params1d.B[0];
  work1d.KKT[1674] = -params1d.A[0];
  work1d.KKT[1842] = -params1d.A[1];
  work1d.KKT[1575] = -params1d.A[2];
  work1d.KKT[1841] = -params1d.A[3];
  work1d.KKT[1844] = -params1d.A[4];
  work1d.KKT[1676] = 1;
  work1d.KKT[1845] = 1;
  work1d.KKT[1576] = 1;
  work1d.KKT[846] = -params1d.B[0];
  work1d.KKT[1677] = -params1d.A[0];
  work1d.KKT[1848] = -params1d.A[1];
  work1d.KKT[1577] = -params1d.A[2];
  work1d.KKT[1847] = -params1d.A[3];
  work1d.KKT[1850] = -params1d.A[4];
  work1d.KKT[1679] = 1;
  work1d.KKT[1851] = 1;
  work1d.KKT[1578] = 1;
  work1d.KKT[848] = -params1d.B[0];
  work1d.KKT[1680] = -params1d.A[0];
  work1d.KKT[1854] = -params1d.A[1];
  work1d.KKT[1579] = -params1d.A[2];
  work1d.KKT[1853] = -params1d.A[3];
  work1d.KKT[1856] = -params1d.A[4];
  work1d.KKT[1682] = 1;
  work1d.KKT[1857] = 1;
  work1d.KKT[1580] = 1;
  work1d.KKT[850] = -params1d.B[0];
  work1d.KKT[1683] = -params1d.A[0];
  work1d.KKT[1860] = -params1d.A[1];
  work1d.KKT[1581] = -params1d.A[2];
  work1d.KKT[1859] = -params1d.A[3];
  work1d.KKT[1862] = -params1d.A[4];
  work1d.KKT[1685] = 1;
  work1d.KKT[1863] = 1;
  work1d.KKT[1582] = 1;
  work1d.KKT[852] = -params1d.B[0];
  work1d.KKT[1686] = -params1d.A[0];
  work1d.KKT[1866] = -params1d.A[1];
  work1d.KKT[1583] = -params1d.A[2];
  work1d.KKT[1865] = -params1d.A[3];
  work1d.KKT[1868] = -params1d.A[4];
  work1d.KKT[1688] = 1;
  work1d.KKT[1869] = 1;
  work1d.KKT[1584] = 1;
  work1d.KKT[854] = -params1d.B[0];
  work1d.KKT[1689] = -params1d.A[0];
  work1d.KKT[1872] = -params1d.A[1];
  work1d.KKT[1585] = -params1d.A[2];
  work1d.KKT[1871] = -params1d.A[3];
  work1d.KKT[1874] = -params1d.A[4];
  work1d.KKT[1691] = 1;
  work1d.KKT[1875] = 1;
  work1d.KKT[1586] = 1;
  work1d.KKT[856] = -params1d.B[0];
  work1d.KKT[1692] = -params1d.A[0];
  work1d.KKT[1878] = -params1d.A[1];
  work1d.KKT[1587] = -params1d.A[2];
  work1d.KKT[1877] = -params1d.A[3];
  work1d.KKT[1880] = -params1d.A[4];
  work1d.KKT[1694] = 1;
  work1d.KKT[1881] = 1;
  work1d.KKT[1588] = 1;
  work1d.KKT[858] = -params1d.B[0];
  work1d.KKT[1695] = -params1d.A[0];
  work1d.KKT[1884] = -params1d.A[1];
  work1d.KKT[1589] = -params1d.A[2];
  work1d.KKT[1883] = -params1d.A[3];
  work1d.KKT[1886] = -params1d.A[4];
  work1d.KKT[1697] = 1;
  work1d.KKT[1887] = 1;
  work1d.KKT[1590] = 1;
  work1d.KKT[860] = -params1d.B[0];
  work1d.KKT[1698] = -params1d.A[0];
  work1d.KKT[1890] = -params1d.A[1];
  work1d.KKT[1591] = -params1d.A[2];
  work1d.KKT[1889] = -params1d.A[3];
  work1d.KKT[1892] = -params1d.A[4];
  work1d.KKT[1700] = 1;
  work1d.KKT[1893] = 1;
  work1d.KKT[1592] = 1;
  work1d.KKT[862] = -params1d.B[0];
  work1d.KKT[1701] = -params1d.A[0];
  work1d.KKT[1896] = -params1d.A[1];
  work1d.KKT[1593] = -params1d.A[2];
  work1d.KKT[1895] = -params1d.A[3];
  work1d.KKT[1898] = -params1d.A[4];
  work1d.KKT[1703] = 1;
  work1d.KKT[1899] = 1;
  work1d.KKT[1594] = 1;
  work1d.KKT[864] = -params1d.B[0];
  work1d.KKT[1704] = -params1d.A[0];
  work1d.KKT[1902] = -params1d.A[1];
  work1d.KKT[1595] = -params1d.A[2];
  work1d.KKT[1901] = -params1d.A[3];
  work1d.KKT[1904] = -params1d.A[4];
  work1d.KKT[1706] = 1;
  work1d.KKT[1905] = 1;
  work1d.KKT[1596] = 1;
  work1d.KKT[866] = -params1d.B[0];
  work1d.KKT[1707] = -params1d.A[0];
  work1d.KKT[1908] = -params1d.A[1];
  work1d.KKT[1597] = -params1d.A[2];
  work1d.KKT[1907] = -params1d.A[3];
  work1d.KKT[1910] = -params1d.A[4];
  work1d.KKT[1709] = 1;
  work1d.KKT[1911] = 1;
  work1d.KKT[1598] = 1;
  work1d.KKT[868] = -params1d.B[0];
  work1d.KKT[1710] = -params1d.A[0];
  work1d.KKT[1914] = -params1d.A[1];
  work1d.KKT[1599] = -params1d.A[2];
  work1d.KKT[1913] = -params1d.A[3];
  work1d.KKT[1916] = -params1d.A[4];
  work1d.KKT[1712] = 1;
  work1d.KKT[1917] = 1;
  work1d.KKT[1600] = 1;
  work1d.KKT[870] = -params1d.B[0];
  work1d.KKT[1713] = -params1d.A[0];
  work1d.KKT[1920] = -params1d.A[1];
  work1d.KKT[1601] = -params1d.A[2];
  work1d.KKT[1919] = -params1d.A[3];
  work1d.KKT[1922] = -params1d.A[4];
  work1d.KKT[1715] = 1;
  work1d.KKT[1923] = 1;
  work1d.KKT[1602] = 1;
  work1d.KKT[872] = -params1d.B[0];
  work1d.KKT[1716] = -params1d.A[0];
  work1d.KKT[1926] = -params1d.A[1];
  work1d.KKT[1603] = -params1d.A[2];
  work1d.KKT[1925] = -params1d.A[3];
  work1d.KKT[1928] = -params1d.A[4];
  work1d.KKT[1718] = 1;
  work1d.KKT[1929] = 1;
  work1d.KKT[1604] = 1;
  work1d.KKT[874] = -params1d.B[0];
  work1d.KKT[1719] = -params1d.A[0];
  work1d.KKT[1932] = -params1d.A[1];
  work1d.KKT[1605] = -params1d.A[2];
  work1d.KKT[1931] = -params1d.A[3];
  work1d.KKT[1934] = -params1d.A[4];
  work1d.KKT[1721] = 1;
  work1d.KKT[1935] = 1;
  work1d.KKT[1606] = 1;
  work1d.KKT[876] = -params1d.B[0];
  work1d.KKT[1722] = -params1d.A[0];
  work1d.KKT[1938] = -params1d.A[1];
  work1d.KKT[1607] = -params1d.A[2];
  work1d.KKT[1937] = -params1d.A[3];
  work1d.KKT[1940] = -params1d.A[4];
  work1d.KKT[1724] = 1;
  work1d.KKT[1941] = 1;
  work1d.KKT[1608] = 1;
  work1d.KKT[878] = -params1d.B[0];
  work1d.KKT[1725] = -params1d.A[0];
  work1d.KKT[1944] = -params1d.A[1];
  work1d.KKT[1609] = -params1d.A[2];
  work1d.KKT[1943] = -params1d.A[3];
  work1d.KKT[1946] = -params1d.A[4];
  work1d.KKT[1727] = 1;
  work1d.KKT[1947] = 1;
  work1d.KKT[1610] = 1;
  work1d.KKT[880] = -params1d.B[0];
  work1d.KKT[1728] = -params1d.A[0];
  work1d.KKT[1949] = -params1d.A[1];
  work1d.KKT[1611] = -params1d.A[2];
  work1d.KKT[1948] = -params1d.A[3];
  work1d.KKT[1950] = -params1d.A[4];
  work1d.KKT[1730] = 1;
  work1d.KKT[1951] = 1;
  work1d.KKT[1533] = 1;
  work1d.KKT[882] = -params1d.B[0];
  work1d.KKT[1612] = -params1d.A[0];
  work1d.KKT[1614] = -params1d.A[1];
  work1d.KKT[1531] = -params1d.A[2];
  work1d.KKT[1613] = -params1d.A[3];
  work1d.KKT[1534] = -params1d.A[4];
  work1d.KKT[886] = 1;
  work1d.KKT[1208] = 1;
  work1d.KKT[1530] = 1;
}
