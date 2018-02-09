/* Produced by CVXGEN, 2018-02-09 07:26:17 -0500.  */
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
  work1d.v[0] = target[40];
  work1d.v[1] = target[161];
  work1d.v[2] = target[162];
  work1d.v[3] = target[163];
  work1d.v[4] = target[164];
  work1d.v[5] = target[165];
  work1d.v[6] = target[166];
  work1d.v[7] = target[167];
  work1d.v[8] = target[168];
  work1d.v[9] = target[169];
  work1d.v[10] = target[170];
  work1d.v[11] = target[171];
  work1d.v[12] = target[172];
  work1d.v[13] = target[173];
  work1d.v[14] = target[174];
  work1d.v[15] = target[175];
  work1d.v[16] = target[176];
  work1d.v[17] = target[177];
  work1d.v[18] = target[178];
  work1d.v[19] = target[179];
  work1d.v[20] = target[180];
  work1d.v[21] = target[181];
  work1d.v[22] = target[182];
  work1d.v[23] = target[183];
  work1d.v[24] = target[184];
  work1d.v[25] = target[185];
  work1d.v[26] = target[186];
  work1d.v[27] = target[187];
  work1d.v[28] = target[188];
  work1d.v[29] = target[189];
  work1d.v[30] = target[190];
  work1d.v[31] = target[191];
  work1d.v[32] = target[192];
  work1d.v[33] = target[193];
  work1d.v[34] = target[194];
  work1d.v[35] = target[195];
  work1d.v[36] = target[196];
  work1d.v[37] = target[197];
  work1d.v[38] = target[198];
  work1d.v[39] = target[199];
  work1d.v[40] = target[200];
  work1d.v[41] = target[201];
  work1d.v[42] = target[202];
  work1d.v[43] = target[203];
  work1d.v[44] = target[204];
  work1d.v[45] = target[205];
  work1d.v[46] = target[206];
  work1d.v[47] = target[207];
  work1d.v[48] = target[208];
  work1d.v[49] = target[209];
  work1d.v[50] = target[210];
  work1d.v[51] = target[211];
  work1d.v[52] = target[212];
  work1d.v[53] = target[213];
  work1d.v[54] = target[214];
  work1d.v[55] = target[215];
  work1d.v[56] = target[216];
  work1d.v[57] = target[217];
  work1d.v[58] = target[218];
  work1d.v[59] = target[219];
  work1d.v[60] = target[220];
  work1d.v[61] = target[221];
  work1d.v[62] = target[222];
  work1d.v[63] = target[223];
  work1d.v[64] = target[224];
  work1d.v[65] = target[225];
  work1d.v[66] = target[226];
  work1d.v[67] = target[227];
  work1d.v[68] = target[228];
  work1d.v[69] = target[229];
  work1d.v[70] = target[230];
  work1d.v[71] = target[231];
  work1d.v[72] = target[232];
  work1d.v[73] = target[233];
  work1d.v[74] = target[234];
  work1d.v[75] = target[235];
  work1d.v[76] = target[236];
  work1d.v[77] = target[237];
  work1d.v[78] = target[238];
  work1d.v[79] = target[239];
  work1d.v[80] = target[240];
  work1d.v[81] = target[241];
  work1d.v[82] = target[242];
  work1d.v[83] = target[243];
  work1d.v[84] = target[244];
  work1d.v[85] = target[245];
  work1d.v[86] = target[246];
  work1d.v[87] = target[247];
  work1d.v[88] = target[248];
  work1d.v[89] = target[249];
  work1d.v[90] = target[250];
  work1d.v[91] = target[251];
  work1d.v[92] = target[252];
  work1d.v[93] = target[253];
  work1d.v[94] = target[254];
  work1d.v[95] = target[255];
  work1d.v[96] = target[256];
  work1d.v[97] = target[257];
  work1d.v[98] = target[258];
  work1d.v[99] = target[259];
  work1d.v[100] = target[260];
  work1d.v[101] = target[261];
  work1d.v[102] = target[262];
  work1d.v[103] = target[263];
  work1d.v[104] = target[264];
  work1d.v[105] = target[265];
  work1d.v[106] = target[266];
  work1d.v[107] = target[267];
  work1d.v[108] = target[268];
  work1d.v[109] = target[269];
  work1d.v[110] = target[270];
  work1d.v[111] = target[271];
  work1d.v[112] = target[272];
  work1d.v[113] = target[273];
  work1d.v[114] = target[274];
  work1d.v[115] = target[275];
  work1d.v[116] = target[276];
  work1d.v[117] = target[277];
  work1d.v[118] = target[278];
  work1d.v[119] = target[279];
  work1d.v[120] = target[280];
  work1d.v[121] = target[281];
  work1d.v[122] = target[282];
  work1d.v[123] = target[283];
  work1d.v[124] = target[284];
  work1d.v[125] = target[285];
  work1d.v[126] = target[286];
  work1d.v[127] = target[287];
  work1d.v[128] = target[288];
  work1d.v[129] = target[289];
  work1d.v[130] = target[290];
  work1d.v[131] = target[291];
  work1d.v[132] = target[292];
  work1d.v[133] = target[293];
  work1d.v[134] = target[294];
  work1d.v[135] = target[295];
  work1d.v[136] = target[296];
  work1d.v[137] = target[297];
  work1d.v[138] = target[298];
  work1d.v[139] = target[299];
  work1d.v[140] = target[300];
  work1d.v[141] = target[301];
  work1d.v[142] = target[302];
  work1d.v[143] = target[303];
  work1d.v[144] = target[304];
  work1d.v[145] = target[305];
  work1d.v[146] = target[306];
  work1d.v[147] = target[307];
  work1d.v[148] = target[308];
  work1d.v[149] = target[309];
  work1d.v[150] = target[310];
  work1d.v[151] = target[311];
  work1d.v[152] = target[312];
  work1d.v[153] = target[313];
  work1d.v[154] = target[314];
  work1d.v[155] = target[315];
  work1d.v[156] = target[316];
  work1d.v[157] = target[317];
  work1d.v[158] = target[318];
  work1d.v[159] = target[319];
  work1d.v[160] = target[320];
  work1d.v[161] = target[321]-work1d.L[0]*work1d.v[1];
  work1d.v[162] = target[322]-work1d.L[1]*work1d.v[2];
  work1d.v[163] = target[323]-work1d.L[2]*work1d.v[3];
  work1d.v[164] = target[324]-work1d.L[3]*work1d.v[4];
  work1d.v[165] = target[325]-work1d.L[4]*work1d.v[5];
  work1d.v[166] = target[326]-work1d.L[5]*work1d.v[6];
  work1d.v[167] = target[327]-work1d.L[6]*work1d.v[7];
  work1d.v[168] = target[328]-work1d.L[7]*work1d.v[8];
  work1d.v[169] = target[329]-work1d.L[8]*work1d.v[9];
  work1d.v[170] = target[330]-work1d.L[9]*work1d.v[10];
  work1d.v[171] = target[331]-work1d.L[10]*work1d.v[11];
  work1d.v[172] = target[332]-work1d.L[11]*work1d.v[12];
  work1d.v[173] = target[333]-work1d.L[12]*work1d.v[13];
  work1d.v[174] = target[334]-work1d.L[13]*work1d.v[14];
  work1d.v[175] = target[335]-work1d.L[14]*work1d.v[15];
  work1d.v[176] = target[336]-work1d.L[15]*work1d.v[16];
  work1d.v[177] = target[337]-work1d.L[16]*work1d.v[17];
  work1d.v[178] = target[338]-work1d.L[17]*work1d.v[18];
  work1d.v[179] = target[339]-work1d.L[18]*work1d.v[19];
  work1d.v[180] = target[340]-work1d.L[19]*work1d.v[20];
  work1d.v[181] = target[341]-work1d.L[20]*work1d.v[21];
  work1d.v[182] = target[342]-work1d.L[21]*work1d.v[22];
  work1d.v[183] = target[343]-work1d.L[22]*work1d.v[23];
  work1d.v[184] = target[344]-work1d.L[23]*work1d.v[24];
  work1d.v[185] = target[345]-work1d.L[24]*work1d.v[25];
  work1d.v[186] = target[346]-work1d.L[25]*work1d.v[26];
  work1d.v[187] = target[347]-work1d.L[26]*work1d.v[27];
  work1d.v[188] = target[348]-work1d.L[27]*work1d.v[28];
  work1d.v[189] = target[349]-work1d.L[28]*work1d.v[29];
  work1d.v[190] = target[350]-work1d.L[29]*work1d.v[30];
  work1d.v[191] = target[351]-work1d.L[30]*work1d.v[31];
  work1d.v[192] = target[352]-work1d.L[31]*work1d.v[32];
  work1d.v[193] = target[353]-work1d.L[32]*work1d.v[33];
  work1d.v[194] = target[354]-work1d.L[33]*work1d.v[34];
  work1d.v[195] = target[355]-work1d.L[34]*work1d.v[35];
  work1d.v[196] = target[356]-work1d.L[35]*work1d.v[36];
  work1d.v[197] = target[357]-work1d.L[36]*work1d.v[37];
  work1d.v[198] = target[358]-work1d.L[37]*work1d.v[38];
  work1d.v[199] = target[359]-work1d.L[38]*work1d.v[39];
  work1d.v[200] = target[360]-work1d.L[39]*work1d.v[40];
  work1d.v[201] = target[361]-work1d.L[40]*work1d.v[41];
  work1d.v[202] = target[362]-work1d.L[41]*work1d.v[42];
  work1d.v[203] = target[363]-work1d.L[42]*work1d.v[43];
  work1d.v[204] = target[364]-work1d.L[43]*work1d.v[44];
  work1d.v[205] = target[365]-work1d.L[44]*work1d.v[45];
  work1d.v[206] = target[366]-work1d.L[45]*work1d.v[46];
  work1d.v[207] = target[367]-work1d.L[46]*work1d.v[47];
  work1d.v[208] = target[368]-work1d.L[47]*work1d.v[48];
  work1d.v[209] = target[369]-work1d.L[48]*work1d.v[49];
  work1d.v[210] = target[370]-work1d.L[49]*work1d.v[50];
  work1d.v[211] = target[371]-work1d.L[50]*work1d.v[51];
  work1d.v[212] = target[372]-work1d.L[51]*work1d.v[52];
  work1d.v[213] = target[373]-work1d.L[52]*work1d.v[53];
  work1d.v[214] = target[374]-work1d.L[53]*work1d.v[54];
  work1d.v[215] = target[375]-work1d.L[54]*work1d.v[55];
  work1d.v[216] = target[376]-work1d.L[55]*work1d.v[56];
  work1d.v[217] = target[377]-work1d.L[56]*work1d.v[57];
  work1d.v[218] = target[378]-work1d.L[57]*work1d.v[58];
  work1d.v[219] = target[379]-work1d.L[58]*work1d.v[59];
  work1d.v[220] = target[380]-work1d.L[59]*work1d.v[60];
  work1d.v[221] = target[381]-work1d.L[60]*work1d.v[61];
  work1d.v[222] = target[382]-work1d.L[61]*work1d.v[62];
  work1d.v[223] = target[383]-work1d.L[62]*work1d.v[63];
  work1d.v[224] = target[384]-work1d.L[63]*work1d.v[64];
  work1d.v[225] = target[385]-work1d.L[64]*work1d.v[65];
  work1d.v[226] = target[386]-work1d.L[65]*work1d.v[66];
  work1d.v[227] = target[387]-work1d.L[66]*work1d.v[67];
  work1d.v[228] = target[388]-work1d.L[67]*work1d.v[68];
  work1d.v[229] = target[389]-work1d.L[68]*work1d.v[69];
  work1d.v[230] = target[390]-work1d.L[69]*work1d.v[70];
  work1d.v[231] = target[391]-work1d.L[70]*work1d.v[71];
  work1d.v[232] = target[392]-work1d.L[71]*work1d.v[72];
  work1d.v[233] = target[393]-work1d.L[72]*work1d.v[73];
  work1d.v[234] = target[394]-work1d.L[73]*work1d.v[74];
  work1d.v[235] = target[395]-work1d.L[74]*work1d.v[75];
  work1d.v[236] = target[396]-work1d.L[75]*work1d.v[76];
  work1d.v[237] = target[397]-work1d.L[76]*work1d.v[77];
  work1d.v[238] = target[398]-work1d.L[77]*work1d.v[78];
  work1d.v[239] = target[399]-work1d.L[78]*work1d.v[79];
  work1d.v[240] = target[400]-work1d.L[79]*work1d.v[80];
  work1d.v[241] = target[401]-work1d.L[80]*work1d.v[81];
  work1d.v[242] = target[402]-work1d.L[81]*work1d.v[82];
  work1d.v[243] = target[403]-work1d.L[82]*work1d.v[83];
  work1d.v[244] = target[404]-work1d.L[83]*work1d.v[84];
  work1d.v[245] = target[405]-work1d.L[84]*work1d.v[85];
  work1d.v[246] = target[406]-work1d.L[85]*work1d.v[86];
  work1d.v[247] = target[407]-work1d.L[86]*work1d.v[87];
  work1d.v[248] = target[408]-work1d.L[87]*work1d.v[88];
  work1d.v[249] = target[409]-work1d.L[88]*work1d.v[89];
  work1d.v[250] = target[410]-work1d.L[89]*work1d.v[90];
  work1d.v[251] = target[411]-work1d.L[90]*work1d.v[91];
  work1d.v[252] = target[412]-work1d.L[91]*work1d.v[92];
  work1d.v[253] = target[413]-work1d.L[92]*work1d.v[93];
  work1d.v[254] = target[414]-work1d.L[93]*work1d.v[94];
  work1d.v[255] = target[415]-work1d.L[94]*work1d.v[95];
  work1d.v[256] = target[416]-work1d.L[95]*work1d.v[96];
  work1d.v[257] = target[417]-work1d.L[96]*work1d.v[97];
  work1d.v[258] = target[418]-work1d.L[97]*work1d.v[98];
  work1d.v[259] = target[419]-work1d.L[98]*work1d.v[99];
  work1d.v[260] = target[420]-work1d.L[99]*work1d.v[100];
  work1d.v[261] = target[421]-work1d.L[100]*work1d.v[101];
  work1d.v[262] = target[422]-work1d.L[101]*work1d.v[102];
  work1d.v[263] = target[423]-work1d.L[102]*work1d.v[103];
  work1d.v[264] = target[424]-work1d.L[103]*work1d.v[104];
  work1d.v[265] = target[425]-work1d.L[104]*work1d.v[105];
  work1d.v[266] = target[426]-work1d.L[105]*work1d.v[106];
  work1d.v[267] = target[427]-work1d.L[106]*work1d.v[107];
  work1d.v[268] = target[428]-work1d.L[107]*work1d.v[108];
  work1d.v[269] = target[429]-work1d.L[108]*work1d.v[109];
  work1d.v[270] = target[430]-work1d.L[109]*work1d.v[110];
  work1d.v[271] = target[431]-work1d.L[110]*work1d.v[111];
  work1d.v[272] = target[432]-work1d.L[111]*work1d.v[112];
  work1d.v[273] = target[433]-work1d.L[112]*work1d.v[113];
  work1d.v[274] = target[434]-work1d.L[113]*work1d.v[114];
  work1d.v[275] = target[435]-work1d.L[114]*work1d.v[115];
  work1d.v[276] = target[436]-work1d.L[115]*work1d.v[116];
  work1d.v[277] = target[437]-work1d.L[116]*work1d.v[117];
  work1d.v[278] = target[438]-work1d.L[117]*work1d.v[118];
  work1d.v[279] = target[439]-work1d.L[118]*work1d.v[119];
  work1d.v[280] = target[440]-work1d.L[119]*work1d.v[120];
  work1d.v[281] = target[441]-work1d.L[120]*work1d.v[121];
  work1d.v[282] = target[442]-work1d.L[121]*work1d.v[122];
  work1d.v[283] = target[443]-work1d.L[122]*work1d.v[123];
  work1d.v[284] = target[444]-work1d.L[123]*work1d.v[124];
  work1d.v[285] = target[445]-work1d.L[124]*work1d.v[125];
  work1d.v[286] = target[446]-work1d.L[125]*work1d.v[126];
  work1d.v[287] = target[447]-work1d.L[126]*work1d.v[127];
  work1d.v[288] = target[448]-work1d.L[127]*work1d.v[128];
  work1d.v[289] = target[449]-work1d.L[128]*work1d.v[129];
  work1d.v[290] = target[450]-work1d.L[129]*work1d.v[130];
  work1d.v[291] = target[451]-work1d.L[130]*work1d.v[131];
  work1d.v[292] = target[452]-work1d.L[131]*work1d.v[132];
  work1d.v[293] = target[453]-work1d.L[132]*work1d.v[133];
  work1d.v[294] = target[454]-work1d.L[133]*work1d.v[134];
  work1d.v[295] = target[455]-work1d.L[134]*work1d.v[135];
  work1d.v[296] = target[456]-work1d.L[135]*work1d.v[136];
  work1d.v[297] = target[457]-work1d.L[136]*work1d.v[137];
  work1d.v[298] = target[458]-work1d.L[137]*work1d.v[138];
  work1d.v[299] = target[459]-work1d.L[138]*work1d.v[139];
  work1d.v[300] = target[460]-work1d.L[139]*work1d.v[140];
  work1d.v[301] = target[461]-work1d.L[140]*work1d.v[141];
  work1d.v[302] = target[462]-work1d.L[141]*work1d.v[142];
  work1d.v[303] = target[463]-work1d.L[142]*work1d.v[143];
  work1d.v[304] = target[464]-work1d.L[143]*work1d.v[144];
  work1d.v[305] = target[465]-work1d.L[144]*work1d.v[145];
  work1d.v[306] = target[466]-work1d.L[145]*work1d.v[146];
  work1d.v[307] = target[467]-work1d.L[146]*work1d.v[147];
  work1d.v[308] = target[468]-work1d.L[147]*work1d.v[148];
  work1d.v[309] = target[469]-work1d.L[148]*work1d.v[149];
  work1d.v[310] = target[470]-work1d.L[149]*work1d.v[150];
  work1d.v[311] = target[471]-work1d.L[150]*work1d.v[151];
  work1d.v[312] = target[472]-work1d.L[151]*work1d.v[152];
  work1d.v[313] = target[473]-work1d.L[152]*work1d.v[153];
  work1d.v[314] = target[474]-work1d.L[153]*work1d.v[154];
  work1d.v[315] = target[475]-work1d.L[154]*work1d.v[155];
  work1d.v[316] = target[476]-work1d.L[155]*work1d.v[156];
  work1d.v[317] = target[477]-work1d.L[156]*work1d.v[157];
  work1d.v[318] = target[478]-work1d.L[157]*work1d.v[158];
  work1d.v[319] = target[479]-work1d.L[158]*work1d.v[159];
  work1d.v[320] = target[480]-work1d.L[159]*work1d.v[160];
  work1d.v[321] = target[481];
  work1d.v[322] = target[482];
  work1d.v[323] = target[0];
  work1d.v[324] = target[483]-work1d.L[160]*work1d.v[323];
  work1d.v[325] = target[1];
  work1d.v[326] = target[2];
  work1d.v[327] = target[3];
  work1d.v[328] = target[4];
  work1d.v[329] = target[5];
  work1d.v[330] = target[6];
  work1d.v[331] = target[7];
  work1d.v[332] = target[8];
  work1d.v[333] = target[9];
  work1d.v[334] = target[10];
  work1d.v[335] = target[11];
  work1d.v[336] = target[12];
  work1d.v[337] = target[13];
  work1d.v[338] = target[14];
  work1d.v[339] = target[15];
  work1d.v[340] = target[16];
  work1d.v[341] = target[17];
  work1d.v[342] = target[18];
  work1d.v[343] = target[19];
  work1d.v[344] = target[20];
  work1d.v[345] = target[21];
  work1d.v[346] = target[22];
  work1d.v[347] = target[23];
  work1d.v[348] = target[24];
  work1d.v[349] = target[25];
  work1d.v[350] = target[26];
  work1d.v[351] = target[27];
  work1d.v[352] = target[28];
  work1d.v[353] = target[29];
  work1d.v[354] = target[30];
  work1d.v[355] = target[31];
  work1d.v[356] = target[32];
  work1d.v[357] = target[33];
  work1d.v[358] = target[34];
  work1d.v[359] = target[35];
  work1d.v[360] = target[36];
  work1d.v[361] = target[37];
  work1d.v[362] = target[38];
  work1d.v[363] = target[39];
  work1d.v[364] = target[160]-work1d.L[161]*work1d.v[240]-work1d.L[162]*work1d.v[320];
  work1d.v[365] = target[600]-work1d.L[163]*work1d.v[363]-work1d.L[164]*work1d.v[364];
  work1d.v[366] = target[41]-work1d.L[165]*work1d.v[321];
  work1d.v[367] = target[158];
  work1d.v[368] = target[159]-work1d.L[166]*work1d.v[200]-work1d.L[167]*work1d.v[280];
  work1d.v[369] = target[157]-work1d.L[168]*work1d.v[239]-work1d.L[169]*work1d.v[319]-work1d.L[170]*work1d.v[365];
  work1d.v[370] = target[484]-work1d.L[171]*work1d.v[366];
  work1d.v[371] = target[486]-work1d.L[172]*work1d.v[325];
  work1d.v[372] = target[489]-work1d.L[173]*work1d.v[326];
  work1d.v[373] = target[492]-work1d.L[174]*work1d.v[327];
  work1d.v[374] = target[495]-work1d.L[175]*work1d.v[328];
  work1d.v[375] = target[498]-work1d.L[176]*work1d.v[329];
  work1d.v[376] = target[501]-work1d.L[177]*work1d.v[330];
  work1d.v[377] = target[504]-work1d.L[178]*work1d.v[331];
  work1d.v[378] = target[507]-work1d.L[179]*work1d.v[332];
  work1d.v[379] = target[510]-work1d.L[180]*work1d.v[333];
  work1d.v[380] = target[513]-work1d.L[181]*work1d.v[334];
  work1d.v[381] = target[516]-work1d.L[182]*work1d.v[335];
  work1d.v[382] = target[519]-work1d.L[183]*work1d.v[336];
  work1d.v[383] = target[522]-work1d.L[184]*work1d.v[337];
  work1d.v[384] = target[525]-work1d.L[185]*work1d.v[338];
  work1d.v[385] = target[528]-work1d.L[186]*work1d.v[339];
  work1d.v[386] = target[531]-work1d.L[187]*work1d.v[340];
  work1d.v[387] = target[534]-work1d.L[188]*work1d.v[341];
  work1d.v[388] = target[537]-work1d.L[189]*work1d.v[342];
  work1d.v[389] = target[540]-work1d.L[190]*work1d.v[343];
  work1d.v[390] = target[543]-work1d.L[191]*work1d.v[344];
  work1d.v[391] = target[546]-work1d.L[192]*work1d.v[345];
  work1d.v[392] = target[549]-work1d.L[193]*work1d.v[346];
  work1d.v[393] = target[552]-work1d.L[194]*work1d.v[347];
  work1d.v[394] = target[555]-work1d.L[195]*work1d.v[348];
  work1d.v[395] = target[558]-work1d.L[196]*work1d.v[349];
  work1d.v[396] = target[561]-work1d.L[197]*work1d.v[350];
  work1d.v[397] = target[564]-work1d.L[198]*work1d.v[351];
  work1d.v[398] = target[567]-work1d.L[199]*work1d.v[352];
  work1d.v[399] = target[570]-work1d.L[200]*work1d.v[353];
  work1d.v[400] = target[573]-work1d.L[201]*work1d.v[354];
  work1d.v[401] = target[576]-work1d.L[202]*work1d.v[355];
  work1d.v[402] = target[579]-work1d.L[203]*work1d.v[356];
  work1d.v[403] = target[582]-work1d.L[204]*work1d.v[357];
  work1d.v[404] = target[585]-work1d.L[205]*work1d.v[358];
  work1d.v[405] = target[588]-work1d.L[206]*work1d.v[359];
  work1d.v[406] = target[591]-work1d.L[207]*work1d.v[360];
  work1d.v[407] = target[594]-work1d.L[208]*work1d.v[361];
  work1d.v[408] = target[597]-work1d.L[209]*work1d.v[362]-work1d.L[210]*work1d.v[369];
  work1d.v[409] = target[598]-work1d.L[211]*work1d.v[367];
  work1d.v[410] = target[599]-work1d.L[212]*work1d.v[368]-work1d.L[213]*work1d.v[369]-work1d.L[214]*work1d.v[408];
  work1d.v[411] = target[42]-work1d.L[215]*work1d.v[161]-work1d.L[216]*work1d.v[241]-work1d.L[217]*work1d.v[322]-work1d.L[218]*work1d.v[370];
  work1d.v[412] = target[43]-work1d.L[219]*work1d.v[201]-work1d.L[220]*work1d.v[281]-work1d.L[221]*work1d.v[324]-work1d.L[222]*work1d.v[371];
  work1d.v[413] = target[44]-work1d.L[223]*work1d.v[370]-work1d.L[224]*work1d.v[411];
  work1d.v[414] = target[47];
  work1d.v[415] = target[50];
  work1d.v[416] = target[53];
  work1d.v[417] = target[56];
  work1d.v[418] = target[59];
  work1d.v[419] = target[62];
  work1d.v[420] = target[65];
  work1d.v[421] = target[68];
  work1d.v[422] = target[71];
  work1d.v[423] = target[74];
  work1d.v[424] = target[77];
  work1d.v[425] = target[80];
  work1d.v[426] = target[83];
  work1d.v[427] = target[86];
  work1d.v[428] = target[89];
  work1d.v[429] = target[92];
  work1d.v[430] = target[95];
  work1d.v[431] = target[98];
  work1d.v[432] = target[101];
  work1d.v[433] = target[104];
  work1d.v[434] = target[107];
  work1d.v[435] = target[110];
  work1d.v[436] = target[113];
  work1d.v[437] = target[116];
  work1d.v[438] = target[119];
  work1d.v[439] = target[122];
  work1d.v[440] = target[125];
  work1d.v[441] = target[128];
  work1d.v[442] = target[131];
  work1d.v[443] = target[134];
  work1d.v[444] = target[137];
  work1d.v[445] = target[140];
  work1d.v[446] = target[143];
  work1d.v[447] = target[146];
  work1d.v[448] = target[149];
  work1d.v[449] = target[152];
  work1d.v[450] = target[155]-work1d.L[225]*work1d.v[409];
  work1d.v[451] = target[485]-work1d.L[226]*work1d.v[411]-work1d.L[227]*work1d.v[412]-work1d.L[228]*work1d.v[413];
  work1d.v[452] = target[45]-work1d.L[229]*work1d.v[162]-work1d.L[230]*work1d.v[242]-work1d.L[231]*work1d.v[451];
  work1d.v[453] = target[46]-work1d.L[232]*work1d.v[202]-work1d.L[233]*work1d.v[282]-work1d.L[234]*work1d.v[371]-work1d.L[235]*work1d.v[372]-work1d.L[236]*work1d.v[412]-work1d.L[237]*work1d.v[451]-work1d.L[238]*work1d.v[452];
  work1d.v[454] = target[487]-work1d.L[239]*work1d.v[413]-work1d.L[240]*work1d.v[414]-work1d.L[241]*work1d.v[451]-work1d.L[242]*work1d.v[452]-work1d.L[243]*work1d.v[453];
  work1d.v[455] = target[488]-work1d.L[244]*work1d.v[452]-work1d.L[245]*work1d.v[453]-work1d.L[246]*work1d.v[454];
  work1d.v[456] = target[48]-work1d.L[247]*work1d.v[163]-work1d.L[248]*work1d.v[243]-work1d.L[249]*work1d.v[455];
  work1d.v[457] = target[49]-work1d.L[250]*work1d.v[203]-work1d.L[251]*work1d.v[283]-work1d.L[252]*work1d.v[372]-work1d.L[253]*work1d.v[373]-work1d.L[254]*work1d.v[453]-work1d.L[255]*work1d.v[454]-work1d.L[256]*work1d.v[455]-work1d.L[257]*work1d.v[456];
  work1d.v[458] = target[490]-work1d.L[258]*work1d.v[414]-work1d.L[259]*work1d.v[415]-work1d.L[260]*work1d.v[454]-work1d.L[261]*work1d.v[455]-work1d.L[262]*work1d.v[456]-work1d.L[263]*work1d.v[457];
  work1d.v[459] = target[491]-work1d.L[264]*work1d.v[456]-work1d.L[265]*work1d.v[457]-work1d.L[266]*work1d.v[458];
  work1d.v[460] = target[51]-work1d.L[267]*work1d.v[164]-work1d.L[268]*work1d.v[244]-work1d.L[269]*work1d.v[459];
  work1d.v[461] = target[52]-work1d.L[270]*work1d.v[204]-work1d.L[271]*work1d.v[284]-work1d.L[272]*work1d.v[373]-work1d.L[273]*work1d.v[374]-work1d.L[274]*work1d.v[457]-work1d.L[275]*work1d.v[458]-work1d.L[276]*work1d.v[459]-work1d.L[277]*work1d.v[460];
  work1d.v[462] = target[493]-work1d.L[278]*work1d.v[415]-work1d.L[279]*work1d.v[416]-work1d.L[280]*work1d.v[458]-work1d.L[281]*work1d.v[459]-work1d.L[282]*work1d.v[460]-work1d.L[283]*work1d.v[461];
  work1d.v[463] = target[494]-work1d.L[284]*work1d.v[460]-work1d.L[285]*work1d.v[461]-work1d.L[286]*work1d.v[462];
  work1d.v[464] = target[54]-work1d.L[287]*work1d.v[165]-work1d.L[288]*work1d.v[245]-work1d.L[289]*work1d.v[463];
  work1d.v[465] = target[55]-work1d.L[290]*work1d.v[205]-work1d.L[291]*work1d.v[285]-work1d.L[292]*work1d.v[374]-work1d.L[293]*work1d.v[375]-work1d.L[294]*work1d.v[461]-work1d.L[295]*work1d.v[462]-work1d.L[296]*work1d.v[463]-work1d.L[297]*work1d.v[464];
  work1d.v[466] = target[496]-work1d.L[298]*work1d.v[416]-work1d.L[299]*work1d.v[417]-work1d.L[300]*work1d.v[462]-work1d.L[301]*work1d.v[463]-work1d.L[302]*work1d.v[464]-work1d.L[303]*work1d.v[465];
  work1d.v[467] = target[497]-work1d.L[304]*work1d.v[464]-work1d.L[305]*work1d.v[465]-work1d.L[306]*work1d.v[466];
  work1d.v[468] = target[57]-work1d.L[307]*work1d.v[166]-work1d.L[308]*work1d.v[246]-work1d.L[309]*work1d.v[467];
  work1d.v[469] = target[58]-work1d.L[310]*work1d.v[206]-work1d.L[311]*work1d.v[286]-work1d.L[312]*work1d.v[375]-work1d.L[313]*work1d.v[376]-work1d.L[314]*work1d.v[465]-work1d.L[315]*work1d.v[466]-work1d.L[316]*work1d.v[467]-work1d.L[317]*work1d.v[468];
  work1d.v[470] = target[499]-work1d.L[318]*work1d.v[417]-work1d.L[319]*work1d.v[418]-work1d.L[320]*work1d.v[466]-work1d.L[321]*work1d.v[467]-work1d.L[322]*work1d.v[468]-work1d.L[323]*work1d.v[469];
  work1d.v[471] = target[500]-work1d.L[324]*work1d.v[468]-work1d.L[325]*work1d.v[469]-work1d.L[326]*work1d.v[470];
  work1d.v[472] = target[60]-work1d.L[327]*work1d.v[167]-work1d.L[328]*work1d.v[247]-work1d.L[329]*work1d.v[471];
  work1d.v[473] = target[61]-work1d.L[330]*work1d.v[207]-work1d.L[331]*work1d.v[287]-work1d.L[332]*work1d.v[376]-work1d.L[333]*work1d.v[377]-work1d.L[334]*work1d.v[469]-work1d.L[335]*work1d.v[470]-work1d.L[336]*work1d.v[471]-work1d.L[337]*work1d.v[472];
  work1d.v[474] = target[502]-work1d.L[338]*work1d.v[418]-work1d.L[339]*work1d.v[419]-work1d.L[340]*work1d.v[470]-work1d.L[341]*work1d.v[471]-work1d.L[342]*work1d.v[472]-work1d.L[343]*work1d.v[473];
  work1d.v[475] = target[503]-work1d.L[344]*work1d.v[472]-work1d.L[345]*work1d.v[473]-work1d.L[346]*work1d.v[474];
  work1d.v[476] = target[63]-work1d.L[347]*work1d.v[168]-work1d.L[348]*work1d.v[248]-work1d.L[349]*work1d.v[475];
  work1d.v[477] = target[64]-work1d.L[350]*work1d.v[208]-work1d.L[351]*work1d.v[288]-work1d.L[352]*work1d.v[377]-work1d.L[353]*work1d.v[378]-work1d.L[354]*work1d.v[473]-work1d.L[355]*work1d.v[474]-work1d.L[356]*work1d.v[475]-work1d.L[357]*work1d.v[476];
  work1d.v[478] = target[505]-work1d.L[358]*work1d.v[419]-work1d.L[359]*work1d.v[420]-work1d.L[360]*work1d.v[474]-work1d.L[361]*work1d.v[475]-work1d.L[362]*work1d.v[476]-work1d.L[363]*work1d.v[477];
  work1d.v[479] = target[506]-work1d.L[364]*work1d.v[476]-work1d.L[365]*work1d.v[477]-work1d.L[366]*work1d.v[478];
  work1d.v[480] = target[66]-work1d.L[367]*work1d.v[169]-work1d.L[368]*work1d.v[249]-work1d.L[369]*work1d.v[479];
  work1d.v[481] = target[67]-work1d.L[370]*work1d.v[209]-work1d.L[371]*work1d.v[289]-work1d.L[372]*work1d.v[378]-work1d.L[373]*work1d.v[379]-work1d.L[374]*work1d.v[477]-work1d.L[375]*work1d.v[478]-work1d.L[376]*work1d.v[479]-work1d.L[377]*work1d.v[480];
  work1d.v[482] = target[508]-work1d.L[378]*work1d.v[420]-work1d.L[379]*work1d.v[421]-work1d.L[380]*work1d.v[478]-work1d.L[381]*work1d.v[479]-work1d.L[382]*work1d.v[480]-work1d.L[383]*work1d.v[481];
  work1d.v[483] = target[509]-work1d.L[384]*work1d.v[480]-work1d.L[385]*work1d.v[481]-work1d.L[386]*work1d.v[482];
  work1d.v[484] = target[69]-work1d.L[387]*work1d.v[170]-work1d.L[388]*work1d.v[250]-work1d.L[389]*work1d.v[483];
  work1d.v[485] = target[70]-work1d.L[390]*work1d.v[210]-work1d.L[391]*work1d.v[290]-work1d.L[392]*work1d.v[379]-work1d.L[393]*work1d.v[380]-work1d.L[394]*work1d.v[481]-work1d.L[395]*work1d.v[482]-work1d.L[396]*work1d.v[483]-work1d.L[397]*work1d.v[484];
  work1d.v[486] = target[511]-work1d.L[398]*work1d.v[421]-work1d.L[399]*work1d.v[422]-work1d.L[400]*work1d.v[482]-work1d.L[401]*work1d.v[483]-work1d.L[402]*work1d.v[484]-work1d.L[403]*work1d.v[485];
  work1d.v[487] = target[512]-work1d.L[404]*work1d.v[484]-work1d.L[405]*work1d.v[485]-work1d.L[406]*work1d.v[486];
  work1d.v[488] = target[72]-work1d.L[407]*work1d.v[171]-work1d.L[408]*work1d.v[251]-work1d.L[409]*work1d.v[487];
  work1d.v[489] = target[73]-work1d.L[410]*work1d.v[211]-work1d.L[411]*work1d.v[291]-work1d.L[412]*work1d.v[380]-work1d.L[413]*work1d.v[381]-work1d.L[414]*work1d.v[485]-work1d.L[415]*work1d.v[486]-work1d.L[416]*work1d.v[487]-work1d.L[417]*work1d.v[488];
  work1d.v[490] = target[514]-work1d.L[418]*work1d.v[422]-work1d.L[419]*work1d.v[423]-work1d.L[420]*work1d.v[486]-work1d.L[421]*work1d.v[487]-work1d.L[422]*work1d.v[488]-work1d.L[423]*work1d.v[489];
  work1d.v[491] = target[515]-work1d.L[424]*work1d.v[488]-work1d.L[425]*work1d.v[489]-work1d.L[426]*work1d.v[490];
  work1d.v[492] = target[75]-work1d.L[427]*work1d.v[172]-work1d.L[428]*work1d.v[252]-work1d.L[429]*work1d.v[491];
  work1d.v[493] = target[76]-work1d.L[430]*work1d.v[212]-work1d.L[431]*work1d.v[292]-work1d.L[432]*work1d.v[381]-work1d.L[433]*work1d.v[382]-work1d.L[434]*work1d.v[489]-work1d.L[435]*work1d.v[490]-work1d.L[436]*work1d.v[491]-work1d.L[437]*work1d.v[492];
  work1d.v[494] = target[517]-work1d.L[438]*work1d.v[423]-work1d.L[439]*work1d.v[424]-work1d.L[440]*work1d.v[490]-work1d.L[441]*work1d.v[491]-work1d.L[442]*work1d.v[492]-work1d.L[443]*work1d.v[493];
  work1d.v[495] = target[518]-work1d.L[444]*work1d.v[492]-work1d.L[445]*work1d.v[493]-work1d.L[446]*work1d.v[494];
  work1d.v[496] = target[78]-work1d.L[447]*work1d.v[173]-work1d.L[448]*work1d.v[253]-work1d.L[449]*work1d.v[495];
  work1d.v[497] = target[79]-work1d.L[450]*work1d.v[213]-work1d.L[451]*work1d.v[293]-work1d.L[452]*work1d.v[382]-work1d.L[453]*work1d.v[383]-work1d.L[454]*work1d.v[493]-work1d.L[455]*work1d.v[494]-work1d.L[456]*work1d.v[495]-work1d.L[457]*work1d.v[496];
  work1d.v[498] = target[520]-work1d.L[458]*work1d.v[424]-work1d.L[459]*work1d.v[425]-work1d.L[460]*work1d.v[494]-work1d.L[461]*work1d.v[495]-work1d.L[462]*work1d.v[496]-work1d.L[463]*work1d.v[497];
  work1d.v[499] = target[521]-work1d.L[464]*work1d.v[496]-work1d.L[465]*work1d.v[497]-work1d.L[466]*work1d.v[498];
  work1d.v[500] = target[81]-work1d.L[467]*work1d.v[174]-work1d.L[468]*work1d.v[254]-work1d.L[469]*work1d.v[499];
  work1d.v[501] = target[82]-work1d.L[470]*work1d.v[214]-work1d.L[471]*work1d.v[294]-work1d.L[472]*work1d.v[383]-work1d.L[473]*work1d.v[384]-work1d.L[474]*work1d.v[497]-work1d.L[475]*work1d.v[498]-work1d.L[476]*work1d.v[499]-work1d.L[477]*work1d.v[500];
  work1d.v[502] = target[523]-work1d.L[478]*work1d.v[425]-work1d.L[479]*work1d.v[426]-work1d.L[480]*work1d.v[498]-work1d.L[481]*work1d.v[499]-work1d.L[482]*work1d.v[500]-work1d.L[483]*work1d.v[501];
  work1d.v[503] = target[524]-work1d.L[484]*work1d.v[500]-work1d.L[485]*work1d.v[501]-work1d.L[486]*work1d.v[502];
  work1d.v[504] = target[84]-work1d.L[487]*work1d.v[175]-work1d.L[488]*work1d.v[255]-work1d.L[489]*work1d.v[503];
  work1d.v[505] = target[85]-work1d.L[490]*work1d.v[215]-work1d.L[491]*work1d.v[295]-work1d.L[492]*work1d.v[384]-work1d.L[493]*work1d.v[385]-work1d.L[494]*work1d.v[501]-work1d.L[495]*work1d.v[502]-work1d.L[496]*work1d.v[503]-work1d.L[497]*work1d.v[504];
  work1d.v[506] = target[526]-work1d.L[498]*work1d.v[426]-work1d.L[499]*work1d.v[427]-work1d.L[500]*work1d.v[502]-work1d.L[501]*work1d.v[503]-work1d.L[502]*work1d.v[504]-work1d.L[503]*work1d.v[505];
  work1d.v[507] = target[527]-work1d.L[504]*work1d.v[504]-work1d.L[505]*work1d.v[505]-work1d.L[506]*work1d.v[506];
  work1d.v[508] = target[87]-work1d.L[507]*work1d.v[176]-work1d.L[508]*work1d.v[256]-work1d.L[509]*work1d.v[507];
  work1d.v[509] = target[88]-work1d.L[510]*work1d.v[216]-work1d.L[511]*work1d.v[296]-work1d.L[512]*work1d.v[385]-work1d.L[513]*work1d.v[386]-work1d.L[514]*work1d.v[505]-work1d.L[515]*work1d.v[506]-work1d.L[516]*work1d.v[507]-work1d.L[517]*work1d.v[508];
  work1d.v[510] = target[529]-work1d.L[518]*work1d.v[427]-work1d.L[519]*work1d.v[428]-work1d.L[520]*work1d.v[506]-work1d.L[521]*work1d.v[507]-work1d.L[522]*work1d.v[508]-work1d.L[523]*work1d.v[509];
  work1d.v[511] = target[530]-work1d.L[524]*work1d.v[508]-work1d.L[525]*work1d.v[509]-work1d.L[526]*work1d.v[510];
  work1d.v[512] = target[90]-work1d.L[527]*work1d.v[177]-work1d.L[528]*work1d.v[257]-work1d.L[529]*work1d.v[511];
  work1d.v[513] = target[91]-work1d.L[530]*work1d.v[217]-work1d.L[531]*work1d.v[297]-work1d.L[532]*work1d.v[386]-work1d.L[533]*work1d.v[387]-work1d.L[534]*work1d.v[509]-work1d.L[535]*work1d.v[510]-work1d.L[536]*work1d.v[511]-work1d.L[537]*work1d.v[512];
  work1d.v[514] = target[532]-work1d.L[538]*work1d.v[428]-work1d.L[539]*work1d.v[429]-work1d.L[540]*work1d.v[510]-work1d.L[541]*work1d.v[511]-work1d.L[542]*work1d.v[512]-work1d.L[543]*work1d.v[513];
  work1d.v[515] = target[533]-work1d.L[544]*work1d.v[512]-work1d.L[545]*work1d.v[513]-work1d.L[546]*work1d.v[514];
  work1d.v[516] = target[93]-work1d.L[547]*work1d.v[178]-work1d.L[548]*work1d.v[258]-work1d.L[549]*work1d.v[515];
  work1d.v[517] = target[94]-work1d.L[550]*work1d.v[218]-work1d.L[551]*work1d.v[298]-work1d.L[552]*work1d.v[387]-work1d.L[553]*work1d.v[388]-work1d.L[554]*work1d.v[513]-work1d.L[555]*work1d.v[514]-work1d.L[556]*work1d.v[515]-work1d.L[557]*work1d.v[516];
  work1d.v[518] = target[535]-work1d.L[558]*work1d.v[429]-work1d.L[559]*work1d.v[430]-work1d.L[560]*work1d.v[514]-work1d.L[561]*work1d.v[515]-work1d.L[562]*work1d.v[516]-work1d.L[563]*work1d.v[517];
  work1d.v[519] = target[536]-work1d.L[564]*work1d.v[516]-work1d.L[565]*work1d.v[517]-work1d.L[566]*work1d.v[518];
  work1d.v[520] = target[96]-work1d.L[567]*work1d.v[179]-work1d.L[568]*work1d.v[259]-work1d.L[569]*work1d.v[519];
  work1d.v[521] = target[97]-work1d.L[570]*work1d.v[219]-work1d.L[571]*work1d.v[299]-work1d.L[572]*work1d.v[388]-work1d.L[573]*work1d.v[389]-work1d.L[574]*work1d.v[517]-work1d.L[575]*work1d.v[518]-work1d.L[576]*work1d.v[519]-work1d.L[577]*work1d.v[520];
  work1d.v[522] = target[538]-work1d.L[578]*work1d.v[430]-work1d.L[579]*work1d.v[431]-work1d.L[580]*work1d.v[518]-work1d.L[581]*work1d.v[519]-work1d.L[582]*work1d.v[520]-work1d.L[583]*work1d.v[521];
  work1d.v[523] = target[539]-work1d.L[584]*work1d.v[520]-work1d.L[585]*work1d.v[521]-work1d.L[586]*work1d.v[522];
  work1d.v[524] = target[99]-work1d.L[587]*work1d.v[180]-work1d.L[588]*work1d.v[260]-work1d.L[589]*work1d.v[523];
  work1d.v[525] = target[100]-work1d.L[590]*work1d.v[220]-work1d.L[591]*work1d.v[300]-work1d.L[592]*work1d.v[389]-work1d.L[593]*work1d.v[390]-work1d.L[594]*work1d.v[521]-work1d.L[595]*work1d.v[522]-work1d.L[596]*work1d.v[523]-work1d.L[597]*work1d.v[524];
  work1d.v[526] = target[541]-work1d.L[598]*work1d.v[431]-work1d.L[599]*work1d.v[432]-work1d.L[600]*work1d.v[522]-work1d.L[601]*work1d.v[523]-work1d.L[602]*work1d.v[524]-work1d.L[603]*work1d.v[525];
  work1d.v[527] = target[542]-work1d.L[604]*work1d.v[524]-work1d.L[605]*work1d.v[525]-work1d.L[606]*work1d.v[526];
  work1d.v[528] = target[102]-work1d.L[607]*work1d.v[181]-work1d.L[608]*work1d.v[261]-work1d.L[609]*work1d.v[527];
  work1d.v[529] = target[103]-work1d.L[610]*work1d.v[221]-work1d.L[611]*work1d.v[301]-work1d.L[612]*work1d.v[390]-work1d.L[613]*work1d.v[391]-work1d.L[614]*work1d.v[525]-work1d.L[615]*work1d.v[526]-work1d.L[616]*work1d.v[527]-work1d.L[617]*work1d.v[528];
  work1d.v[530] = target[544]-work1d.L[618]*work1d.v[432]-work1d.L[619]*work1d.v[433]-work1d.L[620]*work1d.v[526]-work1d.L[621]*work1d.v[527]-work1d.L[622]*work1d.v[528]-work1d.L[623]*work1d.v[529];
  work1d.v[531] = target[545]-work1d.L[624]*work1d.v[528]-work1d.L[625]*work1d.v[529]-work1d.L[626]*work1d.v[530];
  work1d.v[532] = target[105]-work1d.L[627]*work1d.v[182]-work1d.L[628]*work1d.v[262]-work1d.L[629]*work1d.v[531];
  work1d.v[533] = target[106]-work1d.L[630]*work1d.v[222]-work1d.L[631]*work1d.v[302]-work1d.L[632]*work1d.v[391]-work1d.L[633]*work1d.v[392]-work1d.L[634]*work1d.v[529]-work1d.L[635]*work1d.v[530]-work1d.L[636]*work1d.v[531]-work1d.L[637]*work1d.v[532];
  work1d.v[534] = target[547]-work1d.L[638]*work1d.v[433]-work1d.L[639]*work1d.v[434]-work1d.L[640]*work1d.v[530]-work1d.L[641]*work1d.v[531]-work1d.L[642]*work1d.v[532]-work1d.L[643]*work1d.v[533];
  work1d.v[535] = target[548]-work1d.L[644]*work1d.v[532]-work1d.L[645]*work1d.v[533]-work1d.L[646]*work1d.v[534];
  work1d.v[536] = target[108]-work1d.L[647]*work1d.v[183]-work1d.L[648]*work1d.v[263]-work1d.L[649]*work1d.v[535];
  work1d.v[537] = target[109]-work1d.L[650]*work1d.v[223]-work1d.L[651]*work1d.v[303]-work1d.L[652]*work1d.v[392]-work1d.L[653]*work1d.v[393]-work1d.L[654]*work1d.v[533]-work1d.L[655]*work1d.v[534]-work1d.L[656]*work1d.v[535]-work1d.L[657]*work1d.v[536];
  work1d.v[538] = target[550]-work1d.L[658]*work1d.v[434]-work1d.L[659]*work1d.v[435]-work1d.L[660]*work1d.v[534]-work1d.L[661]*work1d.v[535]-work1d.L[662]*work1d.v[536]-work1d.L[663]*work1d.v[537];
  work1d.v[539] = target[551]-work1d.L[664]*work1d.v[536]-work1d.L[665]*work1d.v[537]-work1d.L[666]*work1d.v[538];
  work1d.v[540] = target[111]-work1d.L[667]*work1d.v[184]-work1d.L[668]*work1d.v[264]-work1d.L[669]*work1d.v[539];
  work1d.v[541] = target[112]-work1d.L[670]*work1d.v[224]-work1d.L[671]*work1d.v[304]-work1d.L[672]*work1d.v[393]-work1d.L[673]*work1d.v[394]-work1d.L[674]*work1d.v[537]-work1d.L[675]*work1d.v[538]-work1d.L[676]*work1d.v[539]-work1d.L[677]*work1d.v[540];
  work1d.v[542] = target[553]-work1d.L[678]*work1d.v[435]-work1d.L[679]*work1d.v[436]-work1d.L[680]*work1d.v[538]-work1d.L[681]*work1d.v[539]-work1d.L[682]*work1d.v[540]-work1d.L[683]*work1d.v[541];
  work1d.v[543] = target[554]-work1d.L[684]*work1d.v[540]-work1d.L[685]*work1d.v[541]-work1d.L[686]*work1d.v[542];
  work1d.v[544] = target[114]-work1d.L[687]*work1d.v[185]-work1d.L[688]*work1d.v[265]-work1d.L[689]*work1d.v[543];
  work1d.v[545] = target[115]-work1d.L[690]*work1d.v[225]-work1d.L[691]*work1d.v[305]-work1d.L[692]*work1d.v[394]-work1d.L[693]*work1d.v[395]-work1d.L[694]*work1d.v[541]-work1d.L[695]*work1d.v[542]-work1d.L[696]*work1d.v[543]-work1d.L[697]*work1d.v[544];
  work1d.v[546] = target[556]-work1d.L[698]*work1d.v[436]-work1d.L[699]*work1d.v[437]-work1d.L[700]*work1d.v[542]-work1d.L[701]*work1d.v[543]-work1d.L[702]*work1d.v[544]-work1d.L[703]*work1d.v[545];
  work1d.v[547] = target[557]-work1d.L[704]*work1d.v[544]-work1d.L[705]*work1d.v[545]-work1d.L[706]*work1d.v[546];
  work1d.v[548] = target[117]-work1d.L[707]*work1d.v[186]-work1d.L[708]*work1d.v[266]-work1d.L[709]*work1d.v[547];
  work1d.v[549] = target[118]-work1d.L[710]*work1d.v[226]-work1d.L[711]*work1d.v[306]-work1d.L[712]*work1d.v[395]-work1d.L[713]*work1d.v[396]-work1d.L[714]*work1d.v[545]-work1d.L[715]*work1d.v[546]-work1d.L[716]*work1d.v[547]-work1d.L[717]*work1d.v[548];
  work1d.v[550] = target[559]-work1d.L[718]*work1d.v[437]-work1d.L[719]*work1d.v[438]-work1d.L[720]*work1d.v[546]-work1d.L[721]*work1d.v[547]-work1d.L[722]*work1d.v[548]-work1d.L[723]*work1d.v[549];
  work1d.v[551] = target[560]-work1d.L[724]*work1d.v[548]-work1d.L[725]*work1d.v[549]-work1d.L[726]*work1d.v[550];
  work1d.v[552] = target[120]-work1d.L[727]*work1d.v[187]-work1d.L[728]*work1d.v[267]-work1d.L[729]*work1d.v[551];
  work1d.v[553] = target[121]-work1d.L[730]*work1d.v[227]-work1d.L[731]*work1d.v[307]-work1d.L[732]*work1d.v[396]-work1d.L[733]*work1d.v[397]-work1d.L[734]*work1d.v[549]-work1d.L[735]*work1d.v[550]-work1d.L[736]*work1d.v[551]-work1d.L[737]*work1d.v[552];
  work1d.v[554] = target[562]-work1d.L[738]*work1d.v[438]-work1d.L[739]*work1d.v[439]-work1d.L[740]*work1d.v[550]-work1d.L[741]*work1d.v[551]-work1d.L[742]*work1d.v[552]-work1d.L[743]*work1d.v[553];
  work1d.v[555] = target[563]-work1d.L[744]*work1d.v[552]-work1d.L[745]*work1d.v[553]-work1d.L[746]*work1d.v[554];
  work1d.v[556] = target[123]-work1d.L[747]*work1d.v[188]-work1d.L[748]*work1d.v[268]-work1d.L[749]*work1d.v[555];
  work1d.v[557] = target[124]-work1d.L[750]*work1d.v[228]-work1d.L[751]*work1d.v[308]-work1d.L[752]*work1d.v[397]-work1d.L[753]*work1d.v[398]-work1d.L[754]*work1d.v[553]-work1d.L[755]*work1d.v[554]-work1d.L[756]*work1d.v[555]-work1d.L[757]*work1d.v[556];
  work1d.v[558] = target[565]-work1d.L[758]*work1d.v[439]-work1d.L[759]*work1d.v[440]-work1d.L[760]*work1d.v[554]-work1d.L[761]*work1d.v[555]-work1d.L[762]*work1d.v[556]-work1d.L[763]*work1d.v[557];
  work1d.v[559] = target[566]-work1d.L[764]*work1d.v[556]-work1d.L[765]*work1d.v[557]-work1d.L[766]*work1d.v[558];
  work1d.v[560] = target[126]-work1d.L[767]*work1d.v[189]-work1d.L[768]*work1d.v[269]-work1d.L[769]*work1d.v[559];
  work1d.v[561] = target[127]-work1d.L[770]*work1d.v[229]-work1d.L[771]*work1d.v[309]-work1d.L[772]*work1d.v[398]-work1d.L[773]*work1d.v[399]-work1d.L[774]*work1d.v[557]-work1d.L[775]*work1d.v[558]-work1d.L[776]*work1d.v[559]-work1d.L[777]*work1d.v[560];
  work1d.v[562] = target[568]-work1d.L[778]*work1d.v[440]-work1d.L[779]*work1d.v[441]-work1d.L[780]*work1d.v[558]-work1d.L[781]*work1d.v[559]-work1d.L[782]*work1d.v[560]-work1d.L[783]*work1d.v[561];
  work1d.v[563] = target[569]-work1d.L[784]*work1d.v[560]-work1d.L[785]*work1d.v[561]-work1d.L[786]*work1d.v[562];
  work1d.v[564] = target[129]-work1d.L[787]*work1d.v[190]-work1d.L[788]*work1d.v[270]-work1d.L[789]*work1d.v[563];
  work1d.v[565] = target[130]-work1d.L[790]*work1d.v[230]-work1d.L[791]*work1d.v[310]-work1d.L[792]*work1d.v[399]-work1d.L[793]*work1d.v[400]-work1d.L[794]*work1d.v[561]-work1d.L[795]*work1d.v[562]-work1d.L[796]*work1d.v[563]-work1d.L[797]*work1d.v[564];
  work1d.v[566] = target[571]-work1d.L[798]*work1d.v[441]-work1d.L[799]*work1d.v[442]-work1d.L[800]*work1d.v[562]-work1d.L[801]*work1d.v[563]-work1d.L[802]*work1d.v[564]-work1d.L[803]*work1d.v[565];
  work1d.v[567] = target[572]-work1d.L[804]*work1d.v[564]-work1d.L[805]*work1d.v[565]-work1d.L[806]*work1d.v[566];
  work1d.v[568] = target[132]-work1d.L[807]*work1d.v[191]-work1d.L[808]*work1d.v[271]-work1d.L[809]*work1d.v[567];
  work1d.v[569] = target[133]-work1d.L[810]*work1d.v[231]-work1d.L[811]*work1d.v[311]-work1d.L[812]*work1d.v[400]-work1d.L[813]*work1d.v[401]-work1d.L[814]*work1d.v[565]-work1d.L[815]*work1d.v[566]-work1d.L[816]*work1d.v[567]-work1d.L[817]*work1d.v[568];
  work1d.v[570] = target[574]-work1d.L[818]*work1d.v[442]-work1d.L[819]*work1d.v[443]-work1d.L[820]*work1d.v[566]-work1d.L[821]*work1d.v[567]-work1d.L[822]*work1d.v[568]-work1d.L[823]*work1d.v[569];
  work1d.v[571] = target[575]-work1d.L[824]*work1d.v[568]-work1d.L[825]*work1d.v[569]-work1d.L[826]*work1d.v[570];
  work1d.v[572] = target[135]-work1d.L[827]*work1d.v[192]-work1d.L[828]*work1d.v[272]-work1d.L[829]*work1d.v[571];
  work1d.v[573] = target[136]-work1d.L[830]*work1d.v[232]-work1d.L[831]*work1d.v[312]-work1d.L[832]*work1d.v[401]-work1d.L[833]*work1d.v[402]-work1d.L[834]*work1d.v[569]-work1d.L[835]*work1d.v[570]-work1d.L[836]*work1d.v[571]-work1d.L[837]*work1d.v[572];
  work1d.v[574] = target[577]-work1d.L[838]*work1d.v[443]-work1d.L[839]*work1d.v[444]-work1d.L[840]*work1d.v[570]-work1d.L[841]*work1d.v[571]-work1d.L[842]*work1d.v[572]-work1d.L[843]*work1d.v[573];
  work1d.v[575] = target[578]-work1d.L[844]*work1d.v[572]-work1d.L[845]*work1d.v[573]-work1d.L[846]*work1d.v[574];
  work1d.v[576] = target[138]-work1d.L[847]*work1d.v[193]-work1d.L[848]*work1d.v[273]-work1d.L[849]*work1d.v[575];
  work1d.v[577] = target[139]-work1d.L[850]*work1d.v[233]-work1d.L[851]*work1d.v[313]-work1d.L[852]*work1d.v[402]-work1d.L[853]*work1d.v[403]-work1d.L[854]*work1d.v[573]-work1d.L[855]*work1d.v[574]-work1d.L[856]*work1d.v[575]-work1d.L[857]*work1d.v[576];
  work1d.v[578] = target[580]-work1d.L[858]*work1d.v[444]-work1d.L[859]*work1d.v[445]-work1d.L[860]*work1d.v[574]-work1d.L[861]*work1d.v[575]-work1d.L[862]*work1d.v[576]-work1d.L[863]*work1d.v[577];
  work1d.v[579] = target[581]-work1d.L[864]*work1d.v[576]-work1d.L[865]*work1d.v[577]-work1d.L[866]*work1d.v[578];
  work1d.v[580] = target[141]-work1d.L[867]*work1d.v[194]-work1d.L[868]*work1d.v[274]-work1d.L[869]*work1d.v[579];
  work1d.v[581] = target[142]-work1d.L[870]*work1d.v[234]-work1d.L[871]*work1d.v[314]-work1d.L[872]*work1d.v[403]-work1d.L[873]*work1d.v[404]-work1d.L[874]*work1d.v[577]-work1d.L[875]*work1d.v[578]-work1d.L[876]*work1d.v[579]-work1d.L[877]*work1d.v[580];
  work1d.v[582] = target[583]-work1d.L[878]*work1d.v[445]-work1d.L[879]*work1d.v[446]-work1d.L[880]*work1d.v[578]-work1d.L[881]*work1d.v[579]-work1d.L[882]*work1d.v[580]-work1d.L[883]*work1d.v[581];
  work1d.v[583] = target[584]-work1d.L[884]*work1d.v[580]-work1d.L[885]*work1d.v[581]-work1d.L[886]*work1d.v[582];
  work1d.v[584] = target[144]-work1d.L[887]*work1d.v[195]-work1d.L[888]*work1d.v[275]-work1d.L[889]*work1d.v[583];
  work1d.v[585] = target[145]-work1d.L[890]*work1d.v[235]-work1d.L[891]*work1d.v[315]-work1d.L[892]*work1d.v[404]-work1d.L[893]*work1d.v[405]-work1d.L[894]*work1d.v[581]-work1d.L[895]*work1d.v[582]-work1d.L[896]*work1d.v[583]-work1d.L[897]*work1d.v[584];
  work1d.v[586] = target[586]-work1d.L[898]*work1d.v[446]-work1d.L[899]*work1d.v[447]-work1d.L[900]*work1d.v[582]-work1d.L[901]*work1d.v[583]-work1d.L[902]*work1d.v[584]-work1d.L[903]*work1d.v[585];
  work1d.v[587] = target[587]-work1d.L[904]*work1d.v[584]-work1d.L[905]*work1d.v[585]-work1d.L[906]*work1d.v[586];
  work1d.v[588] = target[147]-work1d.L[907]*work1d.v[196]-work1d.L[908]*work1d.v[276]-work1d.L[909]*work1d.v[587];
  work1d.v[589] = target[148]-work1d.L[910]*work1d.v[236]-work1d.L[911]*work1d.v[316]-work1d.L[912]*work1d.v[405]-work1d.L[913]*work1d.v[406]-work1d.L[914]*work1d.v[585]-work1d.L[915]*work1d.v[586]-work1d.L[916]*work1d.v[587]-work1d.L[917]*work1d.v[588];
  work1d.v[590] = target[589]-work1d.L[918]*work1d.v[447]-work1d.L[919]*work1d.v[448]-work1d.L[920]*work1d.v[586]-work1d.L[921]*work1d.v[587]-work1d.L[922]*work1d.v[588]-work1d.L[923]*work1d.v[589];
  work1d.v[591] = target[590]-work1d.L[924]*work1d.v[588]-work1d.L[925]*work1d.v[589]-work1d.L[926]*work1d.v[590];
  work1d.v[592] = target[150]-work1d.L[927]*work1d.v[197]-work1d.L[928]*work1d.v[277]-work1d.L[929]*work1d.v[591];
  work1d.v[593] = target[151]-work1d.L[930]*work1d.v[237]-work1d.L[931]*work1d.v[317]-work1d.L[932]*work1d.v[406]-work1d.L[933]*work1d.v[407]-work1d.L[934]*work1d.v[589]-work1d.L[935]*work1d.v[590]-work1d.L[936]*work1d.v[591]-work1d.L[937]*work1d.v[592];
  work1d.v[594] = target[592]-work1d.L[938]*work1d.v[448]-work1d.L[939]*work1d.v[449]-work1d.L[940]*work1d.v[590]-work1d.L[941]*work1d.v[591]-work1d.L[942]*work1d.v[592]-work1d.L[943]*work1d.v[593];
  work1d.v[595] = target[593]-work1d.L[944]*work1d.v[592]-work1d.L[945]*work1d.v[593]-work1d.L[946]*work1d.v[594];
  work1d.v[596] = target[595]-work1d.L[947]*work1d.v[449]-work1d.L[948]*work1d.v[450]-work1d.L[949]*work1d.v[594]-work1d.L[950]*work1d.v[595];
  work1d.v[597] = target[596];
  work1d.v[598] = target[153]-work1d.L[951]*work1d.v[198]-work1d.L[952]*work1d.v[278]-work1d.L[953]*work1d.v[595]-work1d.L[954]*work1d.v[596]-work1d.L[955]*work1d.v[597];
  work1d.v[599] = target[154]-work1d.L[956]*work1d.v[238]-work1d.L[957]*work1d.v[318]-work1d.L[958]*work1d.v[407]-work1d.L[959]*work1d.v[408]-work1d.L[960]*work1d.v[410]-work1d.L[961]*work1d.v[593]-work1d.L[962]*work1d.v[594]-work1d.L[963]*work1d.v[595]-work1d.L[964]*work1d.v[596]-work1d.L[965]*work1d.v[597]-work1d.L[966]*work1d.v[598];
  work1d.v[600] = target[156]-work1d.L[967]*work1d.v[199]-work1d.L[968]*work1d.v[279]-work1d.L[969]*work1d.v[409]-work1d.L[970]*work1d.v[410]-work1d.L[971]*work1d.v[450]-work1d.L[972]*work1d.v[596]-work1d.L[973]*work1d.v[597]-work1d.L[974]*work1d.v[598]-work1d.L[975]*work1d.v[599];
  /* Diagonal scaling. Assume correctness of work1d.d_inv. */
  for (i = 0; i < 601; i++)
    work1d.v[i] *= work1d.d_inv[i];
  /* Back substitution */
  work1d.v[599] -= work1d.L[975]*work1d.v[600];
  work1d.v[598] -= work1d.L[966]*work1d.v[599]+work1d.L[974]*work1d.v[600];
  work1d.v[597] -= work1d.L[955]*work1d.v[598]+work1d.L[965]*work1d.v[599]+work1d.L[973]*work1d.v[600];
  work1d.v[596] -= work1d.L[954]*work1d.v[598]+work1d.L[964]*work1d.v[599]+work1d.L[972]*work1d.v[600];
  work1d.v[595] -= work1d.L[950]*work1d.v[596]+work1d.L[953]*work1d.v[598]+work1d.L[963]*work1d.v[599];
  work1d.v[594] -= work1d.L[946]*work1d.v[595]+work1d.L[949]*work1d.v[596]+work1d.L[962]*work1d.v[599];
  work1d.v[593] -= work1d.L[943]*work1d.v[594]+work1d.L[945]*work1d.v[595]+work1d.L[961]*work1d.v[599];
  work1d.v[592] -= work1d.L[937]*work1d.v[593]+work1d.L[942]*work1d.v[594]+work1d.L[944]*work1d.v[595];
  work1d.v[591] -= work1d.L[929]*work1d.v[592]+work1d.L[936]*work1d.v[593]+work1d.L[941]*work1d.v[594];
  work1d.v[590] -= work1d.L[926]*work1d.v[591]+work1d.L[935]*work1d.v[593]+work1d.L[940]*work1d.v[594];
  work1d.v[589] -= work1d.L[923]*work1d.v[590]+work1d.L[925]*work1d.v[591]+work1d.L[934]*work1d.v[593];
  work1d.v[588] -= work1d.L[917]*work1d.v[589]+work1d.L[922]*work1d.v[590]+work1d.L[924]*work1d.v[591];
  work1d.v[587] -= work1d.L[909]*work1d.v[588]+work1d.L[916]*work1d.v[589]+work1d.L[921]*work1d.v[590];
  work1d.v[586] -= work1d.L[906]*work1d.v[587]+work1d.L[915]*work1d.v[589]+work1d.L[920]*work1d.v[590];
  work1d.v[585] -= work1d.L[903]*work1d.v[586]+work1d.L[905]*work1d.v[587]+work1d.L[914]*work1d.v[589];
  work1d.v[584] -= work1d.L[897]*work1d.v[585]+work1d.L[902]*work1d.v[586]+work1d.L[904]*work1d.v[587];
  work1d.v[583] -= work1d.L[889]*work1d.v[584]+work1d.L[896]*work1d.v[585]+work1d.L[901]*work1d.v[586];
  work1d.v[582] -= work1d.L[886]*work1d.v[583]+work1d.L[895]*work1d.v[585]+work1d.L[900]*work1d.v[586];
  work1d.v[581] -= work1d.L[883]*work1d.v[582]+work1d.L[885]*work1d.v[583]+work1d.L[894]*work1d.v[585];
  work1d.v[580] -= work1d.L[877]*work1d.v[581]+work1d.L[882]*work1d.v[582]+work1d.L[884]*work1d.v[583];
  work1d.v[579] -= work1d.L[869]*work1d.v[580]+work1d.L[876]*work1d.v[581]+work1d.L[881]*work1d.v[582];
  work1d.v[578] -= work1d.L[866]*work1d.v[579]+work1d.L[875]*work1d.v[581]+work1d.L[880]*work1d.v[582];
  work1d.v[577] -= work1d.L[863]*work1d.v[578]+work1d.L[865]*work1d.v[579]+work1d.L[874]*work1d.v[581];
  work1d.v[576] -= work1d.L[857]*work1d.v[577]+work1d.L[862]*work1d.v[578]+work1d.L[864]*work1d.v[579];
  work1d.v[575] -= work1d.L[849]*work1d.v[576]+work1d.L[856]*work1d.v[577]+work1d.L[861]*work1d.v[578];
  work1d.v[574] -= work1d.L[846]*work1d.v[575]+work1d.L[855]*work1d.v[577]+work1d.L[860]*work1d.v[578];
  work1d.v[573] -= work1d.L[843]*work1d.v[574]+work1d.L[845]*work1d.v[575]+work1d.L[854]*work1d.v[577];
  work1d.v[572] -= work1d.L[837]*work1d.v[573]+work1d.L[842]*work1d.v[574]+work1d.L[844]*work1d.v[575];
  work1d.v[571] -= work1d.L[829]*work1d.v[572]+work1d.L[836]*work1d.v[573]+work1d.L[841]*work1d.v[574];
  work1d.v[570] -= work1d.L[826]*work1d.v[571]+work1d.L[835]*work1d.v[573]+work1d.L[840]*work1d.v[574];
  work1d.v[569] -= work1d.L[823]*work1d.v[570]+work1d.L[825]*work1d.v[571]+work1d.L[834]*work1d.v[573];
  work1d.v[568] -= work1d.L[817]*work1d.v[569]+work1d.L[822]*work1d.v[570]+work1d.L[824]*work1d.v[571];
  work1d.v[567] -= work1d.L[809]*work1d.v[568]+work1d.L[816]*work1d.v[569]+work1d.L[821]*work1d.v[570];
  work1d.v[566] -= work1d.L[806]*work1d.v[567]+work1d.L[815]*work1d.v[569]+work1d.L[820]*work1d.v[570];
  work1d.v[565] -= work1d.L[803]*work1d.v[566]+work1d.L[805]*work1d.v[567]+work1d.L[814]*work1d.v[569];
  work1d.v[564] -= work1d.L[797]*work1d.v[565]+work1d.L[802]*work1d.v[566]+work1d.L[804]*work1d.v[567];
  work1d.v[563] -= work1d.L[789]*work1d.v[564]+work1d.L[796]*work1d.v[565]+work1d.L[801]*work1d.v[566];
  work1d.v[562] -= work1d.L[786]*work1d.v[563]+work1d.L[795]*work1d.v[565]+work1d.L[800]*work1d.v[566];
  work1d.v[561] -= work1d.L[783]*work1d.v[562]+work1d.L[785]*work1d.v[563]+work1d.L[794]*work1d.v[565];
  work1d.v[560] -= work1d.L[777]*work1d.v[561]+work1d.L[782]*work1d.v[562]+work1d.L[784]*work1d.v[563];
  work1d.v[559] -= work1d.L[769]*work1d.v[560]+work1d.L[776]*work1d.v[561]+work1d.L[781]*work1d.v[562];
  work1d.v[558] -= work1d.L[766]*work1d.v[559]+work1d.L[775]*work1d.v[561]+work1d.L[780]*work1d.v[562];
  work1d.v[557] -= work1d.L[763]*work1d.v[558]+work1d.L[765]*work1d.v[559]+work1d.L[774]*work1d.v[561];
  work1d.v[556] -= work1d.L[757]*work1d.v[557]+work1d.L[762]*work1d.v[558]+work1d.L[764]*work1d.v[559];
  work1d.v[555] -= work1d.L[749]*work1d.v[556]+work1d.L[756]*work1d.v[557]+work1d.L[761]*work1d.v[558];
  work1d.v[554] -= work1d.L[746]*work1d.v[555]+work1d.L[755]*work1d.v[557]+work1d.L[760]*work1d.v[558];
  work1d.v[553] -= work1d.L[743]*work1d.v[554]+work1d.L[745]*work1d.v[555]+work1d.L[754]*work1d.v[557];
  work1d.v[552] -= work1d.L[737]*work1d.v[553]+work1d.L[742]*work1d.v[554]+work1d.L[744]*work1d.v[555];
  work1d.v[551] -= work1d.L[729]*work1d.v[552]+work1d.L[736]*work1d.v[553]+work1d.L[741]*work1d.v[554];
  work1d.v[550] -= work1d.L[726]*work1d.v[551]+work1d.L[735]*work1d.v[553]+work1d.L[740]*work1d.v[554];
  work1d.v[549] -= work1d.L[723]*work1d.v[550]+work1d.L[725]*work1d.v[551]+work1d.L[734]*work1d.v[553];
  work1d.v[548] -= work1d.L[717]*work1d.v[549]+work1d.L[722]*work1d.v[550]+work1d.L[724]*work1d.v[551];
  work1d.v[547] -= work1d.L[709]*work1d.v[548]+work1d.L[716]*work1d.v[549]+work1d.L[721]*work1d.v[550];
  work1d.v[546] -= work1d.L[706]*work1d.v[547]+work1d.L[715]*work1d.v[549]+work1d.L[720]*work1d.v[550];
  work1d.v[545] -= work1d.L[703]*work1d.v[546]+work1d.L[705]*work1d.v[547]+work1d.L[714]*work1d.v[549];
  work1d.v[544] -= work1d.L[697]*work1d.v[545]+work1d.L[702]*work1d.v[546]+work1d.L[704]*work1d.v[547];
  work1d.v[543] -= work1d.L[689]*work1d.v[544]+work1d.L[696]*work1d.v[545]+work1d.L[701]*work1d.v[546];
  work1d.v[542] -= work1d.L[686]*work1d.v[543]+work1d.L[695]*work1d.v[545]+work1d.L[700]*work1d.v[546];
  work1d.v[541] -= work1d.L[683]*work1d.v[542]+work1d.L[685]*work1d.v[543]+work1d.L[694]*work1d.v[545];
  work1d.v[540] -= work1d.L[677]*work1d.v[541]+work1d.L[682]*work1d.v[542]+work1d.L[684]*work1d.v[543];
  work1d.v[539] -= work1d.L[669]*work1d.v[540]+work1d.L[676]*work1d.v[541]+work1d.L[681]*work1d.v[542];
  work1d.v[538] -= work1d.L[666]*work1d.v[539]+work1d.L[675]*work1d.v[541]+work1d.L[680]*work1d.v[542];
  work1d.v[537] -= work1d.L[663]*work1d.v[538]+work1d.L[665]*work1d.v[539]+work1d.L[674]*work1d.v[541];
  work1d.v[536] -= work1d.L[657]*work1d.v[537]+work1d.L[662]*work1d.v[538]+work1d.L[664]*work1d.v[539];
  work1d.v[535] -= work1d.L[649]*work1d.v[536]+work1d.L[656]*work1d.v[537]+work1d.L[661]*work1d.v[538];
  work1d.v[534] -= work1d.L[646]*work1d.v[535]+work1d.L[655]*work1d.v[537]+work1d.L[660]*work1d.v[538];
  work1d.v[533] -= work1d.L[643]*work1d.v[534]+work1d.L[645]*work1d.v[535]+work1d.L[654]*work1d.v[537];
  work1d.v[532] -= work1d.L[637]*work1d.v[533]+work1d.L[642]*work1d.v[534]+work1d.L[644]*work1d.v[535];
  work1d.v[531] -= work1d.L[629]*work1d.v[532]+work1d.L[636]*work1d.v[533]+work1d.L[641]*work1d.v[534];
  work1d.v[530] -= work1d.L[626]*work1d.v[531]+work1d.L[635]*work1d.v[533]+work1d.L[640]*work1d.v[534];
  work1d.v[529] -= work1d.L[623]*work1d.v[530]+work1d.L[625]*work1d.v[531]+work1d.L[634]*work1d.v[533];
  work1d.v[528] -= work1d.L[617]*work1d.v[529]+work1d.L[622]*work1d.v[530]+work1d.L[624]*work1d.v[531];
  work1d.v[527] -= work1d.L[609]*work1d.v[528]+work1d.L[616]*work1d.v[529]+work1d.L[621]*work1d.v[530];
  work1d.v[526] -= work1d.L[606]*work1d.v[527]+work1d.L[615]*work1d.v[529]+work1d.L[620]*work1d.v[530];
  work1d.v[525] -= work1d.L[603]*work1d.v[526]+work1d.L[605]*work1d.v[527]+work1d.L[614]*work1d.v[529];
  work1d.v[524] -= work1d.L[597]*work1d.v[525]+work1d.L[602]*work1d.v[526]+work1d.L[604]*work1d.v[527];
  work1d.v[523] -= work1d.L[589]*work1d.v[524]+work1d.L[596]*work1d.v[525]+work1d.L[601]*work1d.v[526];
  work1d.v[522] -= work1d.L[586]*work1d.v[523]+work1d.L[595]*work1d.v[525]+work1d.L[600]*work1d.v[526];
  work1d.v[521] -= work1d.L[583]*work1d.v[522]+work1d.L[585]*work1d.v[523]+work1d.L[594]*work1d.v[525];
  work1d.v[520] -= work1d.L[577]*work1d.v[521]+work1d.L[582]*work1d.v[522]+work1d.L[584]*work1d.v[523];
  work1d.v[519] -= work1d.L[569]*work1d.v[520]+work1d.L[576]*work1d.v[521]+work1d.L[581]*work1d.v[522];
  work1d.v[518] -= work1d.L[566]*work1d.v[519]+work1d.L[575]*work1d.v[521]+work1d.L[580]*work1d.v[522];
  work1d.v[517] -= work1d.L[563]*work1d.v[518]+work1d.L[565]*work1d.v[519]+work1d.L[574]*work1d.v[521];
  work1d.v[516] -= work1d.L[557]*work1d.v[517]+work1d.L[562]*work1d.v[518]+work1d.L[564]*work1d.v[519];
  work1d.v[515] -= work1d.L[549]*work1d.v[516]+work1d.L[556]*work1d.v[517]+work1d.L[561]*work1d.v[518];
  work1d.v[514] -= work1d.L[546]*work1d.v[515]+work1d.L[555]*work1d.v[517]+work1d.L[560]*work1d.v[518];
  work1d.v[513] -= work1d.L[543]*work1d.v[514]+work1d.L[545]*work1d.v[515]+work1d.L[554]*work1d.v[517];
  work1d.v[512] -= work1d.L[537]*work1d.v[513]+work1d.L[542]*work1d.v[514]+work1d.L[544]*work1d.v[515];
  work1d.v[511] -= work1d.L[529]*work1d.v[512]+work1d.L[536]*work1d.v[513]+work1d.L[541]*work1d.v[514];
  work1d.v[510] -= work1d.L[526]*work1d.v[511]+work1d.L[535]*work1d.v[513]+work1d.L[540]*work1d.v[514];
  work1d.v[509] -= work1d.L[523]*work1d.v[510]+work1d.L[525]*work1d.v[511]+work1d.L[534]*work1d.v[513];
  work1d.v[508] -= work1d.L[517]*work1d.v[509]+work1d.L[522]*work1d.v[510]+work1d.L[524]*work1d.v[511];
  work1d.v[507] -= work1d.L[509]*work1d.v[508]+work1d.L[516]*work1d.v[509]+work1d.L[521]*work1d.v[510];
  work1d.v[506] -= work1d.L[506]*work1d.v[507]+work1d.L[515]*work1d.v[509]+work1d.L[520]*work1d.v[510];
  work1d.v[505] -= work1d.L[503]*work1d.v[506]+work1d.L[505]*work1d.v[507]+work1d.L[514]*work1d.v[509];
  work1d.v[504] -= work1d.L[497]*work1d.v[505]+work1d.L[502]*work1d.v[506]+work1d.L[504]*work1d.v[507];
  work1d.v[503] -= work1d.L[489]*work1d.v[504]+work1d.L[496]*work1d.v[505]+work1d.L[501]*work1d.v[506];
  work1d.v[502] -= work1d.L[486]*work1d.v[503]+work1d.L[495]*work1d.v[505]+work1d.L[500]*work1d.v[506];
  work1d.v[501] -= work1d.L[483]*work1d.v[502]+work1d.L[485]*work1d.v[503]+work1d.L[494]*work1d.v[505];
  work1d.v[500] -= work1d.L[477]*work1d.v[501]+work1d.L[482]*work1d.v[502]+work1d.L[484]*work1d.v[503];
  work1d.v[499] -= work1d.L[469]*work1d.v[500]+work1d.L[476]*work1d.v[501]+work1d.L[481]*work1d.v[502];
  work1d.v[498] -= work1d.L[466]*work1d.v[499]+work1d.L[475]*work1d.v[501]+work1d.L[480]*work1d.v[502];
  work1d.v[497] -= work1d.L[463]*work1d.v[498]+work1d.L[465]*work1d.v[499]+work1d.L[474]*work1d.v[501];
  work1d.v[496] -= work1d.L[457]*work1d.v[497]+work1d.L[462]*work1d.v[498]+work1d.L[464]*work1d.v[499];
  work1d.v[495] -= work1d.L[449]*work1d.v[496]+work1d.L[456]*work1d.v[497]+work1d.L[461]*work1d.v[498];
  work1d.v[494] -= work1d.L[446]*work1d.v[495]+work1d.L[455]*work1d.v[497]+work1d.L[460]*work1d.v[498];
  work1d.v[493] -= work1d.L[443]*work1d.v[494]+work1d.L[445]*work1d.v[495]+work1d.L[454]*work1d.v[497];
  work1d.v[492] -= work1d.L[437]*work1d.v[493]+work1d.L[442]*work1d.v[494]+work1d.L[444]*work1d.v[495];
  work1d.v[491] -= work1d.L[429]*work1d.v[492]+work1d.L[436]*work1d.v[493]+work1d.L[441]*work1d.v[494];
  work1d.v[490] -= work1d.L[426]*work1d.v[491]+work1d.L[435]*work1d.v[493]+work1d.L[440]*work1d.v[494];
  work1d.v[489] -= work1d.L[423]*work1d.v[490]+work1d.L[425]*work1d.v[491]+work1d.L[434]*work1d.v[493];
  work1d.v[488] -= work1d.L[417]*work1d.v[489]+work1d.L[422]*work1d.v[490]+work1d.L[424]*work1d.v[491];
  work1d.v[487] -= work1d.L[409]*work1d.v[488]+work1d.L[416]*work1d.v[489]+work1d.L[421]*work1d.v[490];
  work1d.v[486] -= work1d.L[406]*work1d.v[487]+work1d.L[415]*work1d.v[489]+work1d.L[420]*work1d.v[490];
  work1d.v[485] -= work1d.L[403]*work1d.v[486]+work1d.L[405]*work1d.v[487]+work1d.L[414]*work1d.v[489];
  work1d.v[484] -= work1d.L[397]*work1d.v[485]+work1d.L[402]*work1d.v[486]+work1d.L[404]*work1d.v[487];
  work1d.v[483] -= work1d.L[389]*work1d.v[484]+work1d.L[396]*work1d.v[485]+work1d.L[401]*work1d.v[486];
  work1d.v[482] -= work1d.L[386]*work1d.v[483]+work1d.L[395]*work1d.v[485]+work1d.L[400]*work1d.v[486];
  work1d.v[481] -= work1d.L[383]*work1d.v[482]+work1d.L[385]*work1d.v[483]+work1d.L[394]*work1d.v[485];
  work1d.v[480] -= work1d.L[377]*work1d.v[481]+work1d.L[382]*work1d.v[482]+work1d.L[384]*work1d.v[483];
  work1d.v[479] -= work1d.L[369]*work1d.v[480]+work1d.L[376]*work1d.v[481]+work1d.L[381]*work1d.v[482];
  work1d.v[478] -= work1d.L[366]*work1d.v[479]+work1d.L[375]*work1d.v[481]+work1d.L[380]*work1d.v[482];
  work1d.v[477] -= work1d.L[363]*work1d.v[478]+work1d.L[365]*work1d.v[479]+work1d.L[374]*work1d.v[481];
  work1d.v[476] -= work1d.L[357]*work1d.v[477]+work1d.L[362]*work1d.v[478]+work1d.L[364]*work1d.v[479];
  work1d.v[475] -= work1d.L[349]*work1d.v[476]+work1d.L[356]*work1d.v[477]+work1d.L[361]*work1d.v[478];
  work1d.v[474] -= work1d.L[346]*work1d.v[475]+work1d.L[355]*work1d.v[477]+work1d.L[360]*work1d.v[478];
  work1d.v[473] -= work1d.L[343]*work1d.v[474]+work1d.L[345]*work1d.v[475]+work1d.L[354]*work1d.v[477];
  work1d.v[472] -= work1d.L[337]*work1d.v[473]+work1d.L[342]*work1d.v[474]+work1d.L[344]*work1d.v[475];
  work1d.v[471] -= work1d.L[329]*work1d.v[472]+work1d.L[336]*work1d.v[473]+work1d.L[341]*work1d.v[474];
  work1d.v[470] -= work1d.L[326]*work1d.v[471]+work1d.L[335]*work1d.v[473]+work1d.L[340]*work1d.v[474];
  work1d.v[469] -= work1d.L[323]*work1d.v[470]+work1d.L[325]*work1d.v[471]+work1d.L[334]*work1d.v[473];
  work1d.v[468] -= work1d.L[317]*work1d.v[469]+work1d.L[322]*work1d.v[470]+work1d.L[324]*work1d.v[471];
  work1d.v[467] -= work1d.L[309]*work1d.v[468]+work1d.L[316]*work1d.v[469]+work1d.L[321]*work1d.v[470];
  work1d.v[466] -= work1d.L[306]*work1d.v[467]+work1d.L[315]*work1d.v[469]+work1d.L[320]*work1d.v[470];
  work1d.v[465] -= work1d.L[303]*work1d.v[466]+work1d.L[305]*work1d.v[467]+work1d.L[314]*work1d.v[469];
  work1d.v[464] -= work1d.L[297]*work1d.v[465]+work1d.L[302]*work1d.v[466]+work1d.L[304]*work1d.v[467];
  work1d.v[463] -= work1d.L[289]*work1d.v[464]+work1d.L[296]*work1d.v[465]+work1d.L[301]*work1d.v[466];
  work1d.v[462] -= work1d.L[286]*work1d.v[463]+work1d.L[295]*work1d.v[465]+work1d.L[300]*work1d.v[466];
  work1d.v[461] -= work1d.L[283]*work1d.v[462]+work1d.L[285]*work1d.v[463]+work1d.L[294]*work1d.v[465];
  work1d.v[460] -= work1d.L[277]*work1d.v[461]+work1d.L[282]*work1d.v[462]+work1d.L[284]*work1d.v[463];
  work1d.v[459] -= work1d.L[269]*work1d.v[460]+work1d.L[276]*work1d.v[461]+work1d.L[281]*work1d.v[462];
  work1d.v[458] -= work1d.L[266]*work1d.v[459]+work1d.L[275]*work1d.v[461]+work1d.L[280]*work1d.v[462];
  work1d.v[457] -= work1d.L[263]*work1d.v[458]+work1d.L[265]*work1d.v[459]+work1d.L[274]*work1d.v[461];
  work1d.v[456] -= work1d.L[257]*work1d.v[457]+work1d.L[262]*work1d.v[458]+work1d.L[264]*work1d.v[459];
  work1d.v[455] -= work1d.L[249]*work1d.v[456]+work1d.L[256]*work1d.v[457]+work1d.L[261]*work1d.v[458];
  work1d.v[454] -= work1d.L[246]*work1d.v[455]+work1d.L[255]*work1d.v[457]+work1d.L[260]*work1d.v[458];
  work1d.v[453] -= work1d.L[243]*work1d.v[454]+work1d.L[245]*work1d.v[455]+work1d.L[254]*work1d.v[457];
  work1d.v[452] -= work1d.L[238]*work1d.v[453]+work1d.L[242]*work1d.v[454]+work1d.L[244]*work1d.v[455];
  work1d.v[451] -= work1d.L[231]*work1d.v[452]+work1d.L[237]*work1d.v[453]+work1d.L[241]*work1d.v[454];
  work1d.v[450] -= work1d.L[948]*work1d.v[596]+work1d.L[971]*work1d.v[600];
  work1d.v[449] -= work1d.L[939]*work1d.v[594]+work1d.L[947]*work1d.v[596];
  work1d.v[448] -= work1d.L[919]*work1d.v[590]+work1d.L[938]*work1d.v[594];
  work1d.v[447] -= work1d.L[899]*work1d.v[586]+work1d.L[918]*work1d.v[590];
  work1d.v[446] -= work1d.L[879]*work1d.v[582]+work1d.L[898]*work1d.v[586];
  work1d.v[445] -= work1d.L[859]*work1d.v[578]+work1d.L[878]*work1d.v[582];
  work1d.v[444] -= work1d.L[839]*work1d.v[574]+work1d.L[858]*work1d.v[578];
  work1d.v[443] -= work1d.L[819]*work1d.v[570]+work1d.L[838]*work1d.v[574];
  work1d.v[442] -= work1d.L[799]*work1d.v[566]+work1d.L[818]*work1d.v[570];
  work1d.v[441] -= work1d.L[779]*work1d.v[562]+work1d.L[798]*work1d.v[566];
  work1d.v[440] -= work1d.L[759]*work1d.v[558]+work1d.L[778]*work1d.v[562];
  work1d.v[439] -= work1d.L[739]*work1d.v[554]+work1d.L[758]*work1d.v[558];
  work1d.v[438] -= work1d.L[719]*work1d.v[550]+work1d.L[738]*work1d.v[554];
  work1d.v[437] -= work1d.L[699]*work1d.v[546]+work1d.L[718]*work1d.v[550];
  work1d.v[436] -= work1d.L[679]*work1d.v[542]+work1d.L[698]*work1d.v[546];
  work1d.v[435] -= work1d.L[659]*work1d.v[538]+work1d.L[678]*work1d.v[542];
  work1d.v[434] -= work1d.L[639]*work1d.v[534]+work1d.L[658]*work1d.v[538];
  work1d.v[433] -= work1d.L[619]*work1d.v[530]+work1d.L[638]*work1d.v[534];
  work1d.v[432] -= work1d.L[599]*work1d.v[526]+work1d.L[618]*work1d.v[530];
  work1d.v[431] -= work1d.L[579]*work1d.v[522]+work1d.L[598]*work1d.v[526];
  work1d.v[430] -= work1d.L[559]*work1d.v[518]+work1d.L[578]*work1d.v[522];
  work1d.v[429] -= work1d.L[539]*work1d.v[514]+work1d.L[558]*work1d.v[518];
  work1d.v[428] -= work1d.L[519]*work1d.v[510]+work1d.L[538]*work1d.v[514];
  work1d.v[427] -= work1d.L[499]*work1d.v[506]+work1d.L[518]*work1d.v[510];
  work1d.v[426] -= work1d.L[479]*work1d.v[502]+work1d.L[498]*work1d.v[506];
  work1d.v[425] -= work1d.L[459]*work1d.v[498]+work1d.L[478]*work1d.v[502];
  work1d.v[424] -= work1d.L[439]*work1d.v[494]+work1d.L[458]*work1d.v[498];
  work1d.v[423] -= work1d.L[419]*work1d.v[490]+work1d.L[438]*work1d.v[494];
  work1d.v[422] -= work1d.L[399]*work1d.v[486]+work1d.L[418]*work1d.v[490];
  work1d.v[421] -= work1d.L[379]*work1d.v[482]+work1d.L[398]*work1d.v[486];
  work1d.v[420] -= work1d.L[359]*work1d.v[478]+work1d.L[378]*work1d.v[482];
  work1d.v[419] -= work1d.L[339]*work1d.v[474]+work1d.L[358]*work1d.v[478];
  work1d.v[418] -= work1d.L[319]*work1d.v[470]+work1d.L[338]*work1d.v[474];
  work1d.v[417] -= work1d.L[299]*work1d.v[466]+work1d.L[318]*work1d.v[470];
  work1d.v[416] -= work1d.L[279]*work1d.v[462]+work1d.L[298]*work1d.v[466];
  work1d.v[415] -= work1d.L[259]*work1d.v[458]+work1d.L[278]*work1d.v[462];
  work1d.v[414] -= work1d.L[240]*work1d.v[454]+work1d.L[258]*work1d.v[458];
  work1d.v[413] -= work1d.L[228]*work1d.v[451]+work1d.L[239]*work1d.v[454];
  work1d.v[412] -= work1d.L[227]*work1d.v[451]+work1d.L[236]*work1d.v[453];
  work1d.v[411] -= work1d.L[224]*work1d.v[413]+work1d.L[226]*work1d.v[451];
  work1d.v[410] -= work1d.L[960]*work1d.v[599]+work1d.L[970]*work1d.v[600];
  work1d.v[409] -= work1d.L[225]*work1d.v[450]+work1d.L[969]*work1d.v[600];
  work1d.v[408] -= work1d.L[214]*work1d.v[410]+work1d.L[959]*work1d.v[599];
  work1d.v[407] -= work1d.L[933]*work1d.v[593]+work1d.L[958]*work1d.v[599];
  work1d.v[406] -= work1d.L[913]*work1d.v[589]+work1d.L[932]*work1d.v[593];
  work1d.v[405] -= work1d.L[893]*work1d.v[585]+work1d.L[912]*work1d.v[589];
  work1d.v[404] -= work1d.L[873]*work1d.v[581]+work1d.L[892]*work1d.v[585];
  work1d.v[403] -= work1d.L[853]*work1d.v[577]+work1d.L[872]*work1d.v[581];
  work1d.v[402] -= work1d.L[833]*work1d.v[573]+work1d.L[852]*work1d.v[577];
  work1d.v[401] -= work1d.L[813]*work1d.v[569]+work1d.L[832]*work1d.v[573];
  work1d.v[400] -= work1d.L[793]*work1d.v[565]+work1d.L[812]*work1d.v[569];
  work1d.v[399] -= work1d.L[773]*work1d.v[561]+work1d.L[792]*work1d.v[565];
  work1d.v[398] -= work1d.L[753]*work1d.v[557]+work1d.L[772]*work1d.v[561];
  work1d.v[397] -= work1d.L[733]*work1d.v[553]+work1d.L[752]*work1d.v[557];
  work1d.v[396] -= work1d.L[713]*work1d.v[549]+work1d.L[732]*work1d.v[553];
  work1d.v[395] -= work1d.L[693]*work1d.v[545]+work1d.L[712]*work1d.v[549];
  work1d.v[394] -= work1d.L[673]*work1d.v[541]+work1d.L[692]*work1d.v[545];
  work1d.v[393] -= work1d.L[653]*work1d.v[537]+work1d.L[672]*work1d.v[541];
  work1d.v[392] -= work1d.L[633]*work1d.v[533]+work1d.L[652]*work1d.v[537];
  work1d.v[391] -= work1d.L[613]*work1d.v[529]+work1d.L[632]*work1d.v[533];
  work1d.v[390] -= work1d.L[593]*work1d.v[525]+work1d.L[612]*work1d.v[529];
  work1d.v[389] -= work1d.L[573]*work1d.v[521]+work1d.L[592]*work1d.v[525];
  work1d.v[388] -= work1d.L[553]*work1d.v[517]+work1d.L[572]*work1d.v[521];
  work1d.v[387] -= work1d.L[533]*work1d.v[513]+work1d.L[552]*work1d.v[517];
  work1d.v[386] -= work1d.L[513]*work1d.v[509]+work1d.L[532]*work1d.v[513];
  work1d.v[385] -= work1d.L[493]*work1d.v[505]+work1d.L[512]*work1d.v[509];
  work1d.v[384] -= work1d.L[473]*work1d.v[501]+work1d.L[492]*work1d.v[505];
  work1d.v[383] -= work1d.L[453]*work1d.v[497]+work1d.L[472]*work1d.v[501];
  work1d.v[382] -= work1d.L[433]*work1d.v[493]+work1d.L[452]*work1d.v[497];
  work1d.v[381] -= work1d.L[413]*work1d.v[489]+work1d.L[432]*work1d.v[493];
  work1d.v[380] -= work1d.L[393]*work1d.v[485]+work1d.L[412]*work1d.v[489];
  work1d.v[379] -= work1d.L[373]*work1d.v[481]+work1d.L[392]*work1d.v[485];
  work1d.v[378] -= work1d.L[353]*work1d.v[477]+work1d.L[372]*work1d.v[481];
  work1d.v[377] -= work1d.L[333]*work1d.v[473]+work1d.L[352]*work1d.v[477];
  work1d.v[376] -= work1d.L[313]*work1d.v[469]+work1d.L[332]*work1d.v[473];
  work1d.v[375] -= work1d.L[293]*work1d.v[465]+work1d.L[312]*work1d.v[469];
  work1d.v[374] -= work1d.L[273]*work1d.v[461]+work1d.L[292]*work1d.v[465];
  work1d.v[373] -= work1d.L[253]*work1d.v[457]+work1d.L[272]*work1d.v[461];
  work1d.v[372] -= work1d.L[235]*work1d.v[453]+work1d.L[252]*work1d.v[457];
  work1d.v[371] -= work1d.L[222]*work1d.v[412]+work1d.L[234]*work1d.v[453];
  work1d.v[370] -= work1d.L[218]*work1d.v[411]+work1d.L[223]*work1d.v[413];
  work1d.v[369] -= work1d.L[210]*work1d.v[408]+work1d.L[213]*work1d.v[410];
  work1d.v[368] -= work1d.L[212]*work1d.v[410];
  work1d.v[367] -= work1d.L[211]*work1d.v[409];
  work1d.v[366] -= work1d.L[171]*work1d.v[370];
  work1d.v[365] -= work1d.L[170]*work1d.v[369];
  work1d.v[364] -= work1d.L[164]*work1d.v[365];
  work1d.v[363] -= work1d.L[163]*work1d.v[365];
  work1d.v[362] -= work1d.L[209]*work1d.v[408];
  work1d.v[361] -= work1d.L[208]*work1d.v[407];
  work1d.v[360] -= work1d.L[207]*work1d.v[406];
  work1d.v[359] -= work1d.L[206]*work1d.v[405];
  work1d.v[358] -= work1d.L[205]*work1d.v[404];
  work1d.v[357] -= work1d.L[204]*work1d.v[403];
  work1d.v[356] -= work1d.L[203]*work1d.v[402];
  work1d.v[355] -= work1d.L[202]*work1d.v[401];
  work1d.v[354] -= work1d.L[201]*work1d.v[400];
  work1d.v[353] -= work1d.L[200]*work1d.v[399];
  work1d.v[352] -= work1d.L[199]*work1d.v[398];
  work1d.v[351] -= work1d.L[198]*work1d.v[397];
  work1d.v[350] -= work1d.L[197]*work1d.v[396];
  work1d.v[349] -= work1d.L[196]*work1d.v[395];
  work1d.v[348] -= work1d.L[195]*work1d.v[394];
  work1d.v[347] -= work1d.L[194]*work1d.v[393];
  work1d.v[346] -= work1d.L[193]*work1d.v[392];
  work1d.v[345] -= work1d.L[192]*work1d.v[391];
  work1d.v[344] -= work1d.L[191]*work1d.v[390];
  work1d.v[343] -= work1d.L[190]*work1d.v[389];
  work1d.v[342] -= work1d.L[189]*work1d.v[388];
  work1d.v[341] -= work1d.L[188]*work1d.v[387];
  work1d.v[340] -= work1d.L[187]*work1d.v[386];
  work1d.v[339] -= work1d.L[186]*work1d.v[385];
  work1d.v[338] -= work1d.L[185]*work1d.v[384];
  work1d.v[337] -= work1d.L[184]*work1d.v[383];
  work1d.v[336] -= work1d.L[183]*work1d.v[382];
  work1d.v[335] -= work1d.L[182]*work1d.v[381];
  work1d.v[334] -= work1d.L[181]*work1d.v[380];
  work1d.v[333] -= work1d.L[180]*work1d.v[379];
  work1d.v[332] -= work1d.L[179]*work1d.v[378];
  work1d.v[331] -= work1d.L[178]*work1d.v[377];
  work1d.v[330] -= work1d.L[177]*work1d.v[376];
  work1d.v[329] -= work1d.L[176]*work1d.v[375];
  work1d.v[328] -= work1d.L[175]*work1d.v[374];
  work1d.v[327] -= work1d.L[174]*work1d.v[373];
  work1d.v[326] -= work1d.L[173]*work1d.v[372];
  work1d.v[325] -= work1d.L[172]*work1d.v[371];
  work1d.v[324] -= work1d.L[221]*work1d.v[412];
  work1d.v[323] -= work1d.L[160]*work1d.v[324];
  work1d.v[322] -= work1d.L[217]*work1d.v[411];
  work1d.v[321] -= work1d.L[165]*work1d.v[366];
  work1d.v[320] -= work1d.L[162]*work1d.v[364];
  work1d.v[319] -= work1d.L[169]*work1d.v[369];
  work1d.v[318] -= work1d.L[957]*work1d.v[599];
  work1d.v[317] -= work1d.L[931]*work1d.v[593];
  work1d.v[316] -= work1d.L[911]*work1d.v[589];
  work1d.v[315] -= work1d.L[891]*work1d.v[585];
  work1d.v[314] -= work1d.L[871]*work1d.v[581];
  work1d.v[313] -= work1d.L[851]*work1d.v[577];
  work1d.v[312] -= work1d.L[831]*work1d.v[573];
  work1d.v[311] -= work1d.L[811]*work1d.v[569];
  work1d.v[310] -= work1d.L[791]*work1d.v[565];
  work1d.v[309] -= work1d.L[771]*work1d.v[561];
  work1d.v[308] -= work1d.L[751]*work1d.v[557];
  work1d.v[307] -= work1d.L[731]*work1d.v[553];
  work1d.v[306] -= work1d.L[711]*work1d.v[549];
  work1d.v[305] -= work1d.L[691]*work1d.v[545];
  work1d.v[304] -= work1d.L[671]*work1d.v[541];
  work1d.v[303] -= work1d.L[651]*work1d.v[537];
  work1d.v[302] -= work1d.L[631]*work1d.v[533];
  work1d.v[301] -= work1d.L[611]*work1d.v[529];
  work1d.v[300] -= work1d.L[591]*work1d.v[525];
  work1d.v[299] -= work1d.L[571]*work1d.v[521];
  work1d.v[298] -= work1d.L[551]*work1d.v[517];
  work1d.v[297] -= work1d.L[531]*work1d.v[513];
  work1d.v[296] -= work1d.L[511]*work1d.v[509];
  work1d.v[295] -= work1d.L[491]*work1d.v[505];
  work1d.v[294] -= work1d.L[471]*work1d.v[501];
  work1d.v[293] -= work1d.L[451]*work1d.v[497];
  work1d.v[292] -= work1d.L[431]*work1d.v[493];
  work1d.v[291] -= work1d.L[411]*work1d.v[489];
  work1d.v[290] -= work1d.L[391]*work1d.v[485];
  work1d.v[289] -= work1d.L[371]*work1d.v[481];
  work1d.v[288] -= work1d.L[351]*work1d.v[477];
  work1d.v[287] -= work1d.L[331]*work1d.v[473];
  work1d.v[286] -= work1d.L[311]*work1d.v[469];
  work1d.v[285] -= work1d.L[291]*work1d.v[465];
  work1d.v[284] -= work1d.L[271]*work1d.v[461];
  work1d.v[283] -= work1d.L[251]*work1d.v[457];
  work1d.v[282] -= work1d.L[233]*work1d.v[453];
  work1d.v[281] -= work1d.L[220]*work1d.v[412];
  work1d.v[280] -= work1d.L[167]*work1d.v[368];
  work1d.v[279] -= work1d.L[968]*work1d.v[600];
  work1d.v[278] -= work1d.L[952]*work1d.v[598];
  work1d.v[277] -= work1d.L[928]*work1d.v[592];
  work1d.v[276] -= work1d.L[908]*work1d.v[588];
  work1d.v[275] -= work1d.L[888]*work1d.v[584];
  work1d.v[274] -= work1d.L[868]*work1d.v[580];
  work1d.v[273] -= work1d.L[848]*work1d.v[576];
  work1d.v[272] -= work1d.L[828]*work1d.v[572];
  work1d.v[271] -= work1d.L[808]*work1d.v[568];
  work1d.v[270] -= work1d.L[788]*work1d.v[564];
  work1d.v[269] -= work1d.L[768]*work1d.v[560];
  work1d.v[268] -= work1d.L[748]*work1d.v[556];
  work1d.v[267] -= work1d.L[728]*work1d.v[552];
  work1d.v[266] -= work1d.L[708]*work1d.v[548];
  work1d.v[265] -= work1d.L[688]*work1d.v[544];
  work1d.v[264] -= work1d.L[668]*work1d.v[540];
  work1d.v[263] -= work1d.L[648]*work1d.v[536];
  work1d.v[262] -= work1d.L[628]*work1d.v[532];
  work1d.v[261] -= work1d.L[608]*work1d.v[528];
  work1d.v[260] -= work1d.L[588]*work1d.v[524];
  work1d.v[259] -= work1d.L[568]*work1d.v[520];
  work1d.v[258] -= work1d.L[548]*work1d.v[516];
  work1d.v[257] -= work1d.L[528]*work1d.v[512];
  work1d.v[256] -= work1d.L[508]*work1d.v[508];
  work1d.v[255] -= work1d.L[488]*work1d.v[504];
  work1d.v[254] -= work1d.L[468]*work1d.v[500];
  work1d.v[253] -= work1d.L[448]*work1d.v[496];
  work1d.v[252] -= work1d.L[428]*work1d.v[492];
  work1d.v[251] -= work1d.L[408]*work1d.v[488];
  work1d.v[250] -= work1d.L[388]*work1d.v[484];
  work1d.v[249] -= work1d.L[368]*work1d.v[480];
  work1d.v[248] -= work1d.L[348]*work1d.v[476];
  work1d.v[247] -= work1d.L[328]*work1d.v[472];
  work1d.v[246] -= work1d.L[308]*work1d.v[468];
  work1d.v[245] -= work1d.L[288]*work1d.v[464];
  work1d.v[244] -= work1d.L[268]*work1d.v[460];
  work1d.v[243] -= work1d.L[248]*work1d.v[456];
  work1d.v[242] -= work1d.L[230]*work1d.v[452];
  work1d.v[241] -= work1d.L[216]*work1d.v[411];
  work1d.v[240] -= work1d.L[161]*work1d.v[364];
  work1d.v[239] -= work1d.L[168]*work1d.v[369];
  work1d.v[238] -= work1d.L[956]*work1d.v[599];
  work1d.v[237] -= work1d.L[930]*work1d.v[593];
  work1d.v[236] -= work1d.L[910]*work1d.v[589];
  work1d.v[235] -= work1d.L[890]*work1d.v[585];
  work1d.v[234] -= work1d.L[870]*work1d.v[581];
  work1d.v[233] -= work1d.L[850]*work1d.v[577];
  work1d.v[232] -= work1d.L[830]*work1d.v[573];
  work1d.v[231] -= work1d.L[810]*work1d.v[569];
  work1d.v[230] -= work1d.L[790]*work1d.v[565];
  work1d.v[229] -= work1d.L[770]*work1d.v[561];
  work1d.v[228] -= work1d.L[750]*work1d.v[557];
  work1d.v[227] -= work1d.L[730]*work1d.v[553];
  work1d.v[226] -= work1d.L[710]*work1d.v[549];
  work1d.v[225] -= work1d.L[690]*work1d.v[545];
  work1d.v[224] -= work1d.L[670]*work1d.v[541];
  work1d.v[223] -= work1d.L[650]*work1d.v[537];
  work1d.v[222] -= work1d.L[630]*work1d.v[533];
  work1d.v[221] -= work1d.L[610]*work1d.v[529];
  work1d.v[220] -= work1d.L[590]*work1d.v[525];
  work1d.v[219] -= work1d.L[570]*work1d.v[521];
  work1d.v[218] -= work1d.L[550]*work1d.v[517];
  work1d.v[217] -= work1d.L[530]*work1d.v[513];
  work1d.v[216] -= work1d.L[510]*work1d.v[509];
  work1d.v[215] -= work1d.L[490]*work1d.v[505];
  work1d.v[214] -= work1d.L[470]*work1d.v[501];
  work1d.v[213] -= work1d.L[450]*work1d.v[497];
  work1d.v[212] -= work1d.L[430]*work1d.v[493];
  work1d.v[211] -= work1d.L[410]*work1d.v[489];
  work1d.v[210] -= work1d.L[390]*work1d.v[485];
  work1d.v[209] -= work1d.L[370]*work1d.v[481];
  work1d.v[208] -= work1d.L[350]*work1d.v[477];
  work1d.v[207] -= work1d.L[330]*work1d.v[473];
  work1d.v[206] -= work1d.L[310]*work1d.v[469];
  work1d.v[205] -= work1d.L[290]*work1d.v[465];
  work1d.v[204] -= work1d.L[270]*work1d.v[461];
  work1d.v[203] -= work1d.L[250]*work1d.v[457];
  work1d.v[202] -= work1d.L[232]*work1d.v[453];
  work1d.v[201] -= work1d.L[219]*work1d.v[412];
  work1d.v[200] -= work1d.L[166]*work1d.v[368];
  work1d.v[199] -= work1d.L[967]*work1d.v[600];
  work1d.v[198] -= work1d.L[951]*work1d.v[598];
  work1d.v[197] -= work1d.L[927]*work1d.v[592];
  work1d.v[196] -= work1d.L[907]*work1d.v[588];
  work1d.v[195] -= work1d.L[887]*work1d.v[584];
  work1d.v[194] -= work1d.L[867]*work1d.v[580];
  work1d.v[193] -= work1d.L[847]*work1d.v[576];
  work1d.v[192] -= work1d.L[827]*work1d.v[572];
  work1d.v[191] -= work1d.L[807]*work1d.v[568];
  work1d.v[190] -= work1d.L[787]*work1d.v[564];
  work1d.v[189] -= work1d.L[767]*work1d.v[560];
  work1d.v[188] -= work1d.L[747]*work1d.v[556];
  work1d.v[187] -= work1d.L[727]*work1d.v[552];
  work1d.v[186] -= work1d.L[707]*work1d.v[548];
  work1d.v[185] -= work1d.L[687]*work1d.v[544];
  work1d.v[184] -= work1d.L[667]*work1d.v[540];
  work1d.v[183] -= work1d.L[647]*work1d.v[536];
  work1d.v[182] -= work1d.L[627]*work1d.v[532];
  work1d.v[181] -= work1d.L[607]*work1d.v[528];
  work1d.v[180] -= work1d.L[587]*work1d.v[524];
  work1d.v[179] -= work1d.L[567]*work1d.v[520];
  work1d.v[178] -= work1d.L[547]*work1d.v[516];
  work1d.v[177] -= work1d.L[527]*work1d.v[512];
  work1d.v[176] -= work1d.L[507]*work1d.v[508];
  work1d.v[175] -= work1d.L[487]*work1d.v[504];
  work1d.v[174] -= work1d.L[467]*work1d.v[500];
  work1d.v[173] -= work1d.L[447]*work1d.v[496];
  work1d.v[172] -= work1d.L[427]*work1d.v[492];
  work1d.v[171] -= work1d.L[407]*work1d.v[488];
  work1d.v[170] -= work1d.L[387]*work1d.v[484];
  work1d.v[169] -= work1d.L[367]*work1d.v[480];
  work1d.v[168] -= work1d.L[347]*work1d.v[476];
  work1d.v[167] -= work1d.L[327]*work1d.v[472];
  work1d.v[166] -= work1d.L[307]*work1d.v[468];
  work1d.v[165] -= work1d.L[287]*work1d.v[464];
  work1d.v[164] -= work1d.L[267]*work1d.v[460];
  work1d.v[163] -= work1d.L[247]*work1d.v[456];
  work1d.v[162] -= work1d.L[229]*work1d.v[452];
  work1d.v[161] -= work1d.L[215]*work1d.v[411];
  work1d.v[160] -= work1d.L[159]*work1d.v[320];
  work1d.v[159] -= work1d.L[158]*work1d.v[319];
  work1d.v[158] -= work1d.L[157]*work1d.v[318];
  work1d.v[157] -= work1d.L[156]*work1d.v[317];
  work1d.v[156] -= work1d.L[155]*work1d.v[316];
  work1d.v[155] -= work1d.L[154]*work1d.v[315];
  work1d.v[154] -= work1d.L[153]*work1d.v[314];
  work1d.v[153] -= work1d.L[152]*work1d.v[313];
  work1d.v[152] -= work1d.L[151]*work1d.v[312];
  work1d.v[151] -= work1d.L[150]*work1d.v[311];
  work1d.v[150] -= work1d.L[149]*work1d.v[310];
  work1d.v[149] -= work1d.L[148]*work1d.v[309];
  work1d.v[148] -= work1d.L[147]*work1d.v[308];
  work1d.v[147] -= work1d.L[146]*work1d.v[307];
  work1d.v[146] -= work1d.L[145]*work1d.v[306];
  work1d.v[145] -= work1d.L[144]*work1d.v[305];
  work1d.v[144] -= work1d.L[143]*work1d.v[304];
  work1d.v[143] -= work1d.L[142]*work1d.v[303];
  work1d.v[142] -= work1d.L[141]*work1d.v[302];
  work1d.v[141] -= work1d.L[140]*work1d.v[301];
  work1d.v[140] -= work1d.L[139]*work1d.v[300];
  work1d.v[139] -= work1d.L[138]*work1d.v[299];
  work1d.v[138] -= work1d.L[137]*work1d.v[298];
  work1d.v[137] -= work1d.L[136]*work1d.v[297];
  work1d.v[136] -= work1d.L[135]*work1d.v[296];
  work1d.v[135] -= work1d.L[134]*work1d.v[295];
  work1d.v[134] -= work1d.L[133]*work1d.v[294];
  work1d.v[133] -= work1d.L[132]*work1d.v[293];
  work1d.v[132] -= work1d.L[131]*work1d.v[292];
  work1d.v[131] -= work1d.L[130]*work1d.v[291];
  work1d.v[130] -= work1d.L[129]*work1d.v[290];
  work1d.v[129] -= work1d.L[128]*work1d.v[289];
  work1d.v[128] -= work1d.L[127]*work1d.v[288];
  work1d.v[127] -= work1d.L[126]*work1d.v[287];
  work1d.v[126] -= work1d.L[125]*work1d.v[286];
  work1d.v[125] -= work1d.L[124]*work1d.v[285];
  work1d.v[124] -= work1d.L[123]*work1d.v[284];
  work1d.v[123] -= work1d.L[122]*work1d.v[283];
  work1d.v[122] -= work1d.L[121]*work1d.v[282];
  work1d.v[121] -= work1d.L[120]*work1d.v[281];
  work1d.v[120] -= work1d.L[119]*work1d.v[280];
  work1d.v[119] -= work1d.L[118]*work1d.v[279];
  work1d.v[118] -= work1d.L[117]*work1d.v[278];
  work1d.v[117] -= work1d.L[116]*work1d.v[277];
  work1d.v[116] -= work1d.L[115]*work1d.v[276];
  work1d.v[115] -= work1d.L[114]*work1d.v[275];
  work1d.v[114] -= work1d.L[113]*work1d.v[274];
  work1d.v[113] -= work1d.L[112]*work1d.v[273];
  work1d.v[112] -= work1d.L[111]*work1d.v[272];
  work1d.v[111] -= work1d.L[110]*work1d.v[271];
  work1d.v[110] -= work1d.L[109]*work1d.v[270];
  work1d.v[109] -= work1d.L[108]*work1d.v[269];
  work1d.v[108] -= work1d.L[107]*work1d.v[268];
  work1d.v[107] -= work1d.L[106]*work1d.v[267];
  work1d.v[106] -= work1d.L[105]*work1d.v[266];
  work1d.v[105] -= work1d.L[104]*work1d.v[265];
  work1d.v[104] -= work1d.L[103]*work1d.v[264];
  work1d.v[103] -= work1d.L[102]*work1d.v[263];
  work1d.v[102] -= work1d.L[101]*work1d.v[262];
  work1d.v[101] -= work1d.L[100]*work1d.v[261];
  work1d.v[100] -= work1d.L[99]*work1d.v[260];
  work1d.v[99] -= work1d.L[98]*work1d.v[259];
  work1d.v[98] -= work1d.L[97]*work1d.v[258];
  work1d.v[97] -= work1d.L[96]*work1d.v[257];
  work1d.v[96] -= work1d.L[95]*work1d.v[256];
  work1d.v[95] -= work1d.L[94]*work1d.v[255];
  work1d.v[94] -= work1d.L[93]*work1d.v[254];
  work1d.v[93] -= work1d.L[92]*work1d.v[253];
  work1d.v[92] -= work1d.L[91]*work1d.v[252];
  work1d.v[91] -= work1d.L[90]*work1d.v[251];
  work1d.v[90] -= work1d.L[89]*work1d.v[250];
  work1d.v[89] -= work1d.L[88]*work1d.v[249];
  work1d.v[88] -= work1d.L[87]*work1d.v[248];
  work1d.v[87] -= work1d.L[86]*work1d.v[247];
  work1d.v[86] -= work1d.L[85]*work1d.v[246];
  work1d.v[85] -= work1d.L[84]*work1d.v[245];
  work1d.v[84] -= work1d.L[83]*work1d.v[244];
  work1d.v[83] -= work1d.L[82]*work1d.v[243];
  work1d.v[82] -= work1d.L[81]*work1d.v[242];
  work1d.v[81] -= work1d.L[80]*work1d.v[241];
  work1d.v[80] -= work1d.L[79]*work1d.v[240];
  work1d.v[79] -= work1d.L[78]*work1d.v[239];
  work1d.v[78] -= work1d.L[77]*work1d.v[238];
  work1d.v[77] -= work1d.L[76]*work1d.v[237];
  work1d.v[76] -= work1d.L[75]*work1d.v[236];
  work1d.v[75] -= work1d.L[74]*work1d.v[235];
  work1d.v[74] -= work1d.L[73]*work1d.v[234];
  work1d.v[73] -= work1d.L[72]*work1d.v[233];
  work1d.v[72] -= work1d.L[71]*work1d.v[232];
  work1d.v[71] -= work1d.L[70]*work1d.v[231];
  work1d.v[70] -= work1d.L[69]*work1d.v[230];
  work1d.v[69] -= work1d.L[68]*work1d.v[229];
  work1d.v[68] -= work1d.L[67]*work1d.v[228];
  work1d.v[67] -= work1d.L[66]*work1d.v[227];
  work1d.v[66] -= work1d.L[65]*work1d.v[226];
  work1d.v[65] -= work1d.L[64]*work1d.v[225];
  work1d.v[64] -= work1d.L[63]*work1d.v[224];
  work1d.v[63] -= work1d.L[62]*work1d.v[223];
  work1d.v[62] -= work1d.L[61]*work1d.v[222];
  work1d.v[61] -= work1d.L[60]*work1d.v[221];
  work1d.v[60] -= work1d.L[59]*work1d.v[220];
  work1d.v[59] -= work1d.L[58]*work1d.v[219];
  work1d.v[58] -= work1d.L[57]*work1d.v[218];
  work1d.v[57] -= work1d.L[56]*work1d.v[217];
  work1d.v[56] -= work1d.L[55]*work1d.v[216];
  work1d.v[55] -= work1d.L[54]*work1d.v[215];
  work1d.v[54] -= work1d.L[53]*work1d.v[214];
  work1d.v[53] -= work1d.L[52]*work1d.v[213];
  work1d.v[52] -= work1d.L[51]*work1d.v[212];
  work1d.v[51] -= work1d.L[50]*work1d.v[211];
  work1d.v[50] -= work1d.L[49]*work1d.v[210];
  work1d.v[49] -= work1d.L[48]*work1d.v[209];
  work1d.v[48] -= work1d.L[47]*work1d.v[208];
  work1d.v[47] -= work1d.L[46]*work1d.v[207];
  work1d.v[46] -= work1d.L[45]*work1d.v[206];
  work1d.v[45] -= work1d.L[44]*work1d.v[205];
  work1d.v[44] -= work1d.L[43]*work1d.v[204];
  work1d.v[43] -= work1d.L[42]*work1d.v[203];
  work1d.v[42] -= work1d.L[41]*work1d.v[202];
  work1d.v[41] -= work1d.L[40]*work1d.v[201];
  work1d.v[40] -= work1d.L[39]*work1d.v[200];
  work1d.v[39] -= work1d.L[38]*work1d.v[199];
  work1d.v[38] -= work1d.L[37]*work1d.v[198];
  work1d.v[37] -= work1d.L[36]*work1d.v[197];
  work1d.v[36] -= work1d.L[35]*work1d.v[196];
  work1d.v[35] -= work1d.L[34]*work1d.v[195];
  work1d.v[34] -= work1d.L[33]*work1d.v[194];
  work1d.v[33] -= work1d.L[32]*work1d.v[193];
  work1d.v[32] -= work1d.L[31]*work1d.v[192];
  work1d.v[31] -= work1d.L[30]*work1d.v[191];
  work1d.v[30] -= work1d.L[29]*work1d.v[190];
  work1d.v[29] -= work1d.L[28]*work1d.v[189];
  work1d.v[28] -= work1d.L[27]*work1d.v[188];
  work1d.v[27] -= work1d.L[26]*work1d.v[187];
  work1d.v[26] -= work1d.L[25]*work1d.v[186];
  work1d.v[25] -= work1d.L[24]*work1d.v[185];
  work1d.v[24] -= work1d.L[23]*work1d.v[184];
  work1d.v[23] -= work1d.L[22]*work1d.v[183];
  work1d.v[22] -= work1d.L[21]*work1d.v[182];
  work1d.v[21] -= work1d.L[20]*work1d.v[181];
  work1d.v[20] -= work1d.L[19]*work1d.v[180];
  work1d.v[19] -= work1d.L[18]*work1d.v[179];
  work1d.v[18] -= work1d.L[17]*work1d.v[178];
  work1d.v[17] -= work1d.L[16]*work1d.v[177];
  work1d.v[16] -= work1d.L[15]*work1d.v[176];
  work1d.v[15] -= work1d.L[14]*work1d.v[175];
  work1d.v[14] -= work1d.L[13]*work1d.v[174];
  work1d.v[13] -= work1d.L[12]*work1d.v[173];
  work1d.v[12] -= work1d.L[11]*work1d.v[172];
  work1d.v[11] -= work1d.L[10]*work1d.v[171];
  work1d.v[10] -= work1d.L[9]*work1d.v[170];
  work1d.v[9] -= work1d.L[8]*work1d.v[169];
  work1d.v[8] -= work1d.L[7]*work1d.v[168];
  work1d.v[7] -= work1d.L[6]*work1d.v[167];
  work1d.v[6] -= work1d.L[5]*work1d.v[166];
  work1d.v[5] -= work1d.L[4]*work1d.v[165];
  work1d.v[4] -= work1d.L[3]*work1d.v[164];
  work1d.v[3] -= work1d.L[2]*work1d.v[163];
  work1d.v[2] -= work1d.L[1]*work1d.v[162];
  work1d.v[1] -= work1d.L[0]*work1d.v[161];
  /* Unpermute the result, from v to var. */
  var[0] = work1d.v[323];
  var[1] = work1d.v[325];
  var[2] = work1d.v[326];
  var[3] = work1d.v[327];
  var[4] = work1d.v[328];
  var[5] = work1d.v[329];
  var[6] = work1d.v[330];
  var[7] = work1d.v[331];
  var[8] = work1d.v[332];
  var[9] = work1d.v[333];
  var[10] = work1d.v[334];
  var[11] = work1d.v[335];
  var[12] = work1d.v[336];
  var[13] = work1d.v[337];
  var[14] = work1d.v[338];
  var[15] = work1d.v[339];
  var[16] = work1d.v[340];
  var[17] = work1d.v[341];
  var[18] = work1d.v[342];
  var[19] = work1d.v[343];
  var[20] = work1d.v[344];
  var[21] = work1d.v[345];
  var[22] = work1d.v[346];
  var[23] = work1d.v[347];
  var[24] = work1d.v[348];
  var[25] = work1d.v[349];
  var[26] = work1d.v[350];
  var[27] = work1d.v[351];
  var[28] = work1d.v[352];
  var[29] = work1d.v[353];
  var[30] = work1d.v[354];
  var[31] = work1d.v[355];
  var[32] = work1d.v[356];
  var[33] = work1d.v[357];
  var[34] = work1d.v[358];
  var[35] = work1d.v[359];
  var[36] = work1d.v[360];
  var[37] = work1d.v[361];
  var[38] = work1d.v[362];
  var[39] = work1d.v[363];
  var[40] = work1d.v[0];
  var[41] = work1d.v[366];
  var[42] = work1d.v[411];
  var[43] = work1d.v[412];
  var[44] = work1d.v[413];
  var[45] = work1d.v[452];
  var[46] = work1d.v[453];
  var[47] = work1d.v[414];
  var[48] = work1d.v[456];
  var[49] = work1d.v[457];
  var[50] = work1d.v[415];
  var[51] = work1d.v[460];
  var[52] = work1d.v[461];
  var[53] = work1d.v[416];
  var[54] = work1d.v[464];
  var[55] = work1d.v[465];
  var[56] = work1d.v[417];
  var[57] = work1d.v[468];
  var[58] = work1d.v[469];
  var[59] = work1d.v[418];
  var[60] = work1d.v[472];
  var[61] = work1d.v[473];
  var[62] = work1d.v[419];
  var[63] = work1d.v[476];
  var[64] = work1d.v[477];
  var[65] = work1d.v[420];
  var[66] = work1d.v[480];
  var[67] = work1d.v[481];
  var[68] = work1d.v[421];
  var[69] = work1d.v[484];
  var[70] = work1d.v[485];
  var[71] = work1d.v[422];
  var[72] = work1d.v[488];
  var[73] = work1d.v[489];
  var[74] = work1d.v[423];
  var[75] = work1d.v[492];
  var[76] = work1d.v[493];
  var[77] = work1d.v[424];
  var[78] = work1d.v[496];
  var[79] = work1d.v[497];
  var[80] = work1d.v[425];
  var[81] = work1d.v[500];
  var[82] = work1d.v[501];
  var[83] = work1d.v[426];
  var[84] = work1d.v[504];
  var[85] = work1d.v[505];
  var[86] = work1d.v[427];
  var[87] = work1d.v[508];
  var[88] = work1d.v[509];
  var[89] = work1d.v[428];
  var[90] = work1d.v[512];
  var[91] = work1d.v[513];
  var[92] = work1d.v[429];
  var[93] = work1d.v[516];
  var[94] = work1d.v[517];
  var[95] = work1d.v[430];
  var[96] = work1d.v[520];
  var[97] = work1d.v[521];
  var[98] = work1d.v[431];
  var[99] = work1d.v[524];
  var[100] = work1d.v[525];
  var[101] = work1d.v[432];
  var[102] = work1d.v[528];
  var[103] = work1d.v[529];
  var[104] = work1d.v[433];
  var[105] = work1d.v[532];
  var[106] = work1d.v[533];
  var[107] = work1d.v[434];
  var[108] = work1d.v[536];
  var[109] = work1d.v[537];
  var[110] = work1d.v[435];
  var[111] = work1d.v[540];
  var[112] = work1d.v[541];
  var[113] = work1d.v[436];
  var[114] = work1d.v[544];
  var[115] = work1d.v[545];
  var[116] = work1d.v[437];
  var[117] = work1d.v[548];
  var[118] = work1d.v[549];
  var[119] = work1d.v[438];
  var[120] = work1d.v[552];
  var[121] = work1d.v[553];
  var[122] = work1d.v[439];
  var[123] = work1d.v[556];
  var[124] = work1d.v[557];
  var[125] = work1d.v[440];
  var[126] = work1d.v[560];
  var[127] = work1d.v[561];
  var[128] = work1d.v[441];
  var[129] = work1d.v[564];
  var[130] = work1d.v[565];
  var[131] = work1d.v[442];
  var[132] = work1d.v[568];
  var[133] = work1d.v[569];
  var[134] = work1d.v[443];
  var[135] = work1d.v[572];
  var[136] = work1d.v[573];
  var[137] = work1d.v[444];
  var[138] = work1d.v[576];
  var[139] = work1d.v[577];
  var[140] = work1d.v[445];
  var[141] = work1d.v[580];
  var[142] = work1d.v[581];
  var[143] = work1d.v[446];
  var[144] = work1d.v[584];
  var[145] = work1d.v[585];
  var[146] = work1d.v[447];
  var[147] = work1d.v[588];
  var[148] = work1d.v[589];
  var[149] = work1d.v[448];
  var[150] = work1d.v[592];
  var[151] = work1d.v[593];
  var[152] = work1d.v[449];
  var[153] = work1d.v[598];
  var[154] = work1d.v[599];
  var[155] = work1d.v[450];
  var[156] = work1d.v[600];
  var[157] = work1d.v[369];
  var[158] = work1d.v[367];
  var[159] = work1d.v[368];
  var[160] = work1d.v[364];
  var[161] = work1d.v[1];
  var[162] = work1d.v[2];
  var[163] = work1d.v[3];
  var[164] = work1d.v[4];
  var[165] = work1d.v[5];
  var[166] = work1d.v[6];
  var[167] = work1d.v[7];
  var[168] = work1d.v[8];
  var[169] = work1d.v[9];
  var[170] = work1d.v[10];
  var[171] = work1d.v[11];
  var[172] = work1d.v[12];
  var[173] = work1d.v[13];
  var[174] = work1d.v[14];
  var[175] = work1d.v[15];
  var[176] = work1d.v[16];
  var[177] = work1d.v[17];
  var[178] = work1d.v[18];
  var[179] = work1d.v[19];
  var[180] = work1d.v[20];
  var[181] = work1d.v[21];
  var[182] = work1d.v[22];
  var[183] = work1d.v[23];
  var[184] = work1d.v[24];
  var[185] = work1d.v[25];
  var[186] = work1d.v[26];
  var[187] = work1d.v[27];
  var[188] = work1d.v[28];
  var[189] = work1d.v[29];
  var[190] = work1d.v[30];
  var[191] = work1d.v[31];
  var[192] = work1d.v[32];
  var[193] = work1d.v[33];
  var[194] = work1d.v[34];
  var[195] = work1d.v[35];
  var[196] = work1d.v[36];
  var[197] = work1d.v[37];
  var[198] = work1d.v[38];
  var[199] = work1d.v[39];
  var[200] = work1d.v[40];
  var[201] = work1d.v[41];
  var[202] = work1d.v[42];
  var[203] = work1d.v[43];
  var[204] = work1d.v[44];
  var[205] = work1d.v[45];
  var[206] = work1d.v[46];
  var[207] = work1d.v[47];
  var[208] = work1d.v[48];
  var[209] = work1d.v[49];
  var[210] = work1d.v[50];
  var[211] = work1d.v[51];
  var[212] = work1d.v[52];
  var[213] = work1d.v[53];
  var[214] = work1d.v[54];
  var[215] = work1d.v[55];
  var[216] = work1d.v[56];
  var[217] = work1d.v[57];
  var[218] = work1d.v[58];
  var[219] = work1d.v[59];
  var[220] = work1d.v[60];
  var[221] = work1d.v[61];
  var[222] = work1d.v[62];
  var[223] = work1d.v[63];
  var[224] = work1d.v[64];
  var[225] = work1d.v[65];
  var[226] = work1d.v[66];
  var[227] = work1d.v[67];
  var[228] = work1d.v[68];
  var[229] = work1d.v[69];
  var[230] = work1d.v[70];
  var[231] = work1d.v[71];
  var[232] = work1d.v[72];
  var[233] = work1d.v[73];
  var[234] = work1d.v[74];
  var[235] = work1d.v[75];
  var[236] = work1d.v[76];
  var[237] = work1d.v[77];
  var[238] = work1d.v[78];
  var[239] = work1d.v[79];
  var[240] = work1d.v[80];
  var[241] = work1d.v[81];
  var[242] = work1d.v[82];
  var[243] = work1d.v[83];
  var[244] = work1d.v[84];
  var[245] = work1d.v[85];
  var[246] = work1d.v[86];
  var[247] = work1d.v[87];
  var[248] = work1d.v[88];
  var[249] = work1d.v[89];
  var[250] = work1d.v[90];
  var[251] = work1d.v[91];
  var[252] = work1d.v[92];
  var[253] = work1d.v[93];
  var[254] = work1d.v[94];
  var[255] = work1d.v[95];
  var[256] = work1d.v[96];
  var[257] = work1d.v[97];
  var[258] = work1d.v[98];
  var[259] = work1d.v[99];
  var[260] = work1d.v[100];
  var[261] = work1d.v[101];
  var[262] = work1d.v[102];
  var[263] = work1d.v[103];
  var[264] = work1d.v[104];
  var[265] = work1d.v[105];
  var[266] = work1d.v[106];
  var[267] = work1d.v[107];
  var[268] = work1d.v[108];
  var[269] = work1d.v[109];
  var[270] = work1d.v[110];
  var[271] = work1d.v[111];
  var[272] = work1d.v[112];
  var[273] = work1d.v[113];
  var[274] = work1d.v[114];
  var[275] = work1d.v[115];
  var[276] = work1d.v[116];
  var[277] = work1d.v[117];
  var[278] = work1d.v[118];
  var[279] = work1d.v[119];
  var[280] = work1d.v[120];
  var[281] = work1d.v[121];
  var[282] = work1d.v[122];
  var[283] = work1d.v[123];
  var[284] = work1d.v[124];
  var[285] = work1d.v[125];
  var[286] = work1d.v[126];
  var[287] = work1d.v[127];
  var[288] = work1d.v[128];
  var[289] = work1d.v[129];
  var[290] = work1d.v[130];
  var[291] = work1d.v[131];
  var[292] = work1d.v[132];
  var[293] = work1d.v[133];
  var[294] = work1d.v[134];
  var[295] = work1d.v[135];
  var[296] = work1d.v[136];
  var[297] = work1d.v[137];
  var[298] = work1d.v[138];
  var[299] = work1d.v[139];
  var[300] = work1d.v[140];
  var[301] = work1d.v[141];
  var[302] = work1d.v[142];
  var[303] = work1d.v[143];
  var[304] = work1d.v[144];
  var[305] = work1d.v[145];
  var[306] = work1d.v[146];
  var[307] = work1d.v[147];
  var[308] = work1d.v[148];
  var[309] = work1d.v[149];
  var[310] = work1d.v[150];
  var[311] = work1d.v[151];
  var[312] = work1d.v[152];
  var[313] = work1d.v[153];
  var[314] = work1d.v[154];
  var[315] = work1d.v[155];
  var[316] = work1d.v[156];
  var[317] = work1d.v[157];
  var[318] = work1d.v[158];
  var[319] = work1d.v[159];
  var[320] = work1d.v[160];
  var[321] = work1d.v[161];
  var[322] = work1d.v[162];
  var[323] = work1d.v[163];
  var[324] = work1d.v[164];
  var[325] = work1d.v[165];
  var[326] = work1d.v[166];
  var[327] = work1d.v[167];
  var[328] = work1d.v[168];
  var[329] = work1d.v[169];
  var[330] = work1d.v[170];
  var[331] = work1d.v[171];
  var[332] = work1d.v[172];
  var[333] = work1d.v[173];
  var[334] = work1d.v[174];
  var[335] = work1d.v[175];
  var[336] = work1d.v[176];
  var[337] = work1d.v[177];
  var[338] = work1d.v[178];
  var[339] = work1d.v[179];
  var[340] = work1d.v[180];
  var[341] = work1d.v[181];
  var[342] = work1d.v[182];
  var[343] = work1d.v[183];
  var[344] = work1d.v[184];
  var[345] = work1d.v[185];
  var[346] = work1d.v[186];
  var[347] = work1d.v[187];
  var[348] = work1d.v[188];
  var[349] = work1d.v[189];
  var[350] = work1d.v[190];
  var[351] = work1d.v[191];
  var[352] = work1d.v[192];
  var[353] = work1d.v[193];
  var[354] = work1d.v[194];
  var[355] = work1d.v[195];
  var[356] = work1d.v[196];
  var[357] = work1d.v[197];
  var[358] = work1d.v[198];
  var[359] = work1d.v[199];
  var[360] = work1d.v[200];
  var[361] = work1d.v[201];
  var[362] = work1d.v[202];
  var[363] = work1d.v[203];
  var[364] = work1d.v[204];
  var[365] = work1d.v[205];
  var[366] = work1d.v[206];
  var[367] = work1d.v[207];
  var[368] = work1d.v[208];
  var[369] = work1d.v[209];
  var[370] = work1d.v[210];
  var[371] = work1d.v[211];
  var[372] = work1d.v[212];
  var[373] = work1d.v[213];
  var[374] = work1d.v[214];
  var[375] = work1d.v[215];
  var[376] = work1d.v[216];
  var[377] = work1d.v[217];
  var[378] = work1d.v[218];
  var[379] = work1d.v[219];
  var[380] = work1d.v[220];
  var[381] = work1d.v[221];
  var[382] = work1d.v[222];
  var[383] = work1d.v[223];
  var[384] = work1d.v[224];
  var[385] = work1d.v[225];
  var[386] = work1d.v[226];
  var[387] = work1d.v[227];
  var[388] = work1d.v[228];
  var[389] = work1d.v[229];
  var[390] = work1d.v[230];
  var[391] = work1d.v[231];
  var[392] = work1d.v[232];
  var[393] = work1d.v[233];
  var[394] = work1d.v[234];
  var[395] = work1d.v[235];
  var[396] = work1d.v[236];
  var[397] = work1d.v[237];
  var[398] = work1d.v[238];
  var[399] = work1d.v[239];
  var[400] = work1d.v[240];
  var[401] = work1d.v[241];
  var[402] = work1d.v[242];
  var[403] = work1d.v[243];
  var[404] = work1d.v[244];
  var[405] = work1d.v[245];
  var[406] = work1d.v[246];
  var[407] = work1d.v[247];
  var[408] = work1d.v[248];
  var[409] = work1d.v[249];
  var[410] = work1d.v[250];
  var[411] = work1d.v[251];
  var[412] = work1d.v[252];
  var[413] = work1d.v[253];
  var[414] = work1d.v[254];
  var[415] = work1d.v[255];
  var[416] = work1d.v[256];
  var[417] = work1d.v[257];
  var[418] = work1d.v[258];
  var[419] = work1d.v[259];
  var[420] = work1d.v[260];
  var[421] = work1d.v[261];
  var[422] = work1d.v[262];
  var[423] = work1d.v[263];
  var[424] = work1d.v[264];
  var[425] = work1d.v[265];
  var[426] = work1d.v[266];
  var[427] = work1d.v[267];
  var[428] = work1d.v[268];
  var[429] = work1d.v[269];
  var[430] = work1d.v[270];
  var[431] = work1d.v[271];
  var[432] = work1d.v[272];
  var[433] = work1d.v[273];
  var[434] = work1d.v[274];
  var[435] = work1d.v[275];
  var[436] = work1d.v[276];
  var[437] = work1d.v[277];
  var[438] = work1d.v[278];
  var[439] = work1d.v[279];
  var[440] = work1d.v[280];
  var[441] = work1d.v[281];
  var[442] = work1d.v[282];
  var[443] = work1d.v[283];
  var[444] = work1d.v[284];
  var[445] = work1d.v[285];
  var[446] = work1d.v[286];
  var[447] = work1d.v[287];
  var[448] = work1d.v[288];
  var[449] = work1d.v[289];
  var[450] = work1d.v[290];
  var[451] = work1d.v[291];
  var[452] = work1d.v[292];
  var[453] = work1d.v[293];
  var[454] = work1d.v[294];
  var[455] = work1d.v[295];
  var[456] = work1d.v[296];
  var[457] = work1d.v[297];
  var[458] = work1d.v[298];
  var[459] = work1d.v[299];
  var[460] = work1d.v[300];
  var[461] = work1d.v[301];
  var[462] = work1d.v[302];
  var[463] = work1d.v[303];
  var[464] = work1d.v[304];
  var[465] = work1d.v[305];
  var[466] = work1d.v[306];
  var[467] = work1d.v[307];
  var[468] = work1d.v[308];
  var[469] = work1d.v[309];
  var[470] = work1d.v[310];
  var[471] = work1d.v[311];
  var[472] = work1d.v[312];
  var[473] = work1d.v[313];
  var[474] = work1d.v[314];
  var[475] = work1d.v[315];
  var[476] = work1d.v[316];
  var[477] = work1d.v[317];
  var[478] = work1d.v[318];
  var[479] = work1d.v[319];
  var[480] = work1d.v[320];
  var[481] = work1d.v[321];
  var[482] = work1d.v[322];
  var[483] = work1d.v[324];
  var[484] = work1d.v[370];
  var[485] = work1d.v[451];
  var[486] = work1d.v[371];
  var[487] = work1d.v[454];
  var[488] = work1d.v[455];
  var[489] = work1d.v[372];
  var[490] = work1d.v[458];
  var[491] = work1d.v[459];
  var[492] = work1d.v[373];
  var[493] = work1d.v[462];
  var[494] = work1d.v[463];
  var[495] = work1d.v[374];
  var[496] = work1d.v[466];
  var[497] = work1d.v[467];
  var[498] = work1d.v[375];
  var[499] = work1d.v[470];
  var[500] = work1d.v[471];
  var[501] = work1d.v[376];
  var[502] = work1d.v[474];
  var[503] = work1d.v[475];
  var[504] = work1d.v[377];
  var[505] = work1d.v[478];
  var[506] = work1d.v[479];
  var[507] = work1d.v[378];
  var[508] = work1d.v[482];
  var[509] = work1d.v[483];
  var[510] = work1d.v[379];
  var[511] = work1d.v[486];
  var[512] = work1d.v[487];
  var[513] = work1d.v[380];
  var[514] = work1d.v[490];
  var[515] = work1d.v[491];
  var[516] = work1d.v[381];
  var[517] = work1d.v[494];
  var[518] = work1d.v[495];
  var[519] = work1d.v[382];
  var[520] = work1d.v[498];
  var[521] = work1d.v[499];
  var[522] = work1d.v[383];
  var[523] = work1d.v[502];
  var[524] = work1d.v[503];
  var[525] = work1d.v[384];
  var[526] = work1d.v[506];
  var[527] = work1d.v[507];
  var[528] = work1d.v[385];
  var[529] = work1d.v[510];
  var[530] = work1d.v[511];
  var[531] = work1d.v[386];
  var[532] = work1d.v[514];
  var[533] = work1d.v[515];
  var[534] = work1d.v[387];
  var[535] = work1d.v[518];
  var[536] = work1d.v[519];
  var[537] = work1d.v[388];
  var[538] = work1d.v[522];
  var[539] = work1d.v[523];
  var[540] = work1d.v[389];
  var[541] = work1d.v[526];
  var[542] = work1d.v[527];
  var[543] = work1d.v[390];
  var[544] = work1d.v[530];
  var[545] = work1d.v[531];
  var[546] = work1d.v[391];
  var[547] = work1d.v[534];
  var[548] = work1d.v[535];
  var[549] = work1d.v[392];
  var[550] = work1d.v[538];
  var[551] = work1d.v[539];
  var[552] = work1d.v[393];
  var[553] = work1d.v[542];
  var[554] = work1d.v[543];
  var[555] = work1d.v[394];
  var[556] = work1d.v[546];
  var[557] = work1d.v[547];
  var[558] = work1d.v[395];
  var[559] = work1d.v[550];
  var[560] = work1d.v[551];
  var[561] = work1d.v[396];
  var[562] = work1d.v[554];
  var[563] = work1d.v[555];
  var[564] = work1d.v[397];
  var[565] = work1d.v[558];
  var[566] = work1d.v[559];
  var[567] = work1d.v[398];
  var[568] = work1d.v[562];
  var[569] = work1d.v[563];
  var[570] = work1d.v[399];
  var[571] = work1d.v[566];
  var[572] = work1d.v[567];
  var[573] = work1d.v[400];
  var[574] = work1d.v[570];
  var[575] = work1d.v[571];
  var[576] = work1d.v[401];
  var[577] = work1d.v[574];
  var[578] = work1d.v[575];
  var[579] = work1d.v[402];
  var[580] = work1d.v[578];
  var[581] = work1d.v[579];
  var[582] = work1d.v[403];
  var[583] = work1d.v[582];
  var[584] = work1d.v[583];
  var[585] = work1d.v[404];
  var[586] = work1d.v[586];
  var[587] = work1d.v[587];
  var[588] = work1d.v[405];
  var[589] = work1d.v[590];
  var[590] = work1d.v[591];
  var[591] = work1d.v[406];
  var[592] = work1d.v[594];
  var[593] = work1d.v[595];
  var[594] = work1d.v[407];
  var[595] = work1d.v[596];
  var[596] = work1d.v[597];
  var[597] = work1d.v[408];
  var[598] = work1d.v[409];
  var[599] = work1d.v[410];
  var[600] = work1d.v[365];
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
  work1d.L[0] = (work1d.KKT[2])*work1d.d_inv[1];
  work1d.v[2] = work1d.KKT[3];
  work1d.d[2] = work1d.v[2];
  if (work1d.d[2] < 0)
    work1d.d[2] = settings1d.kkt_reg;
  else
    work1d.d[2] += settings1d.kkt_reg;
  work1d.d_inv[2] = 1/work1d.d[2];
  work1d.L[1] = (work1d.KKT[4])*work1d.d_inv[2];
  work1d.v[3] = work1d.KKT[5];
  work1d.d[3] = work1d.v[3];
  if (work1d.d[3] < 0)
    work1d.d[3] = settings1d.kkt_reg;
  else
    work1d.d[3] += settings1d.kkt_reg;
  work1d.d_inv[3] = 1/work1d.d[3];
  work1d.L[2] = (work1d.KKT[6])*work1d.d_inv[3];
  work1d.v[4] = work1d.KKT[7];
  work1d.d[4] = work1d.v[4];
  if (work1d.d[4] < 0)
    work1d.d[4] = settings1d.kkt_reg;
  else
    work1d.d[4] += settings1d.kkt_reg;
  work1d.d_inv[4] = 1/work1d.d[4];
  work1d.L[3] = (work1d.KKT[8])*work1d.d_inv[4];
  work1d.v[5] = work1d.KKT[9];
  work1d.d[5] = work1d.v[5];
  if (work1d.d[5] < 0)
    work1d.d[5] = settings1d.kkt_reg;
  else
    work1d.d[5] += settings1d.kkt_reg;
  work1d.d_inv[5] = 1/work1d.d[5];
  work1d.L[4] = (work1d.KKT[10])*work1d.d_inv[5];
  work1d.v[6] = work1d.KKT[11];
  work1d.d[6] = work1d.v[6];
  if (work1d.d[6] < 0)
    work1d.d[6] = settings1d.kkt_reg;
  else
    work1d.d[6] += settings1d.kkt_reg;
  work1d.d_inv[6] = 1/work1d.d[6];
  work1d.L[5] = (work1d.KKT[12])*work1d.d_inv[6];
  work1d.v[7] = work1d.KKT[13];
  work1d.d[7] = work1d.v[7];
  if (work1d.d[7] < 0)
    work1d.d[7] = settings1d.kkt_reg;
  else
    work1d.d[7] += settings1d.kkt_reg;
  work1d.d_inv[7] = 1/work1d.d[7];
  work1d.L[6] = (work1d.KKT[14])*work1d.d_inv[7];
  work1d.v[8] = work1d.KKT[15];
  work1d.d[8] = work1d.v[8];
  if (work1d.d[8] < 0)
    work1d.d[8] = settings1d.kkt_reg;
  else
    work1d.d[8] += settings1d.kkt_reg;
  work1d.d_inv[8] = 1/work1d.d[8];
  work1d.L[7] = (work1d.KKT[16])*work1d.d_inv[8];
  work1d.v[9] = work1d.KKT[17];
  work1d.d[9] = work1d.v[9];
  if (work1d.d[9] < 0)
    work1d.d[9] = settings1d.kkt_reg;
  else
    work1d.d[9] += settings1d.kkt_reg;
  work1d.d_inv[9] = 1/work1d.d[9];
  work1d.L[8] = (work1d.KKT[18])*work1d.d_inv[9];
  work1d.v[10] = work1d.KKT[19];
  work1d.d[10] = work1d.v[10];
  if (work1d.d[10] < 0)
    work1d.d[10] = settings1d.kkt_reg;
  else
    work1d.d[10] += settings1d.kkt_reg;
  work1d.d_inv[10] = 1/work1d.d[10];
  work1d.L[9] = (work1d.KKT[20])*work1d.d_inv[10];
  work1d.v[11] = work1d.KKT[21];
  work1d.d[11] = work1d.v[11];
  if (work1d.d[11] < 0)
    work1d.d[11] = settings1d.kkt_reg;
  else
    work1d.d[11] += settings1d.kkt_reg;
  work1d.d_inv[11] = 1/work1d.d[11];
  work1d.L[10] = (work1d.KKT[22])*work1d.d_inv[11];
  work1d.v[12] = work1d.KKT[23];
  work1d.d[12] = work1d.v[12];
  if (work1d.d[12] < 0)
    work1d.d[12] = settings1d.kkt_reg;
  else
    work1d.d[12] += settings1d.kkt_reg;
  work1d.d_inv[12] = 1/work1d.d[12];
  work1d.L[11] = (work1d.KKT[24])*work1d.d_inv[12];
  work1d.v[13] = work1d.KKT[25];
  work1d.d[13] = work1d.v[13];
  if (work1d.d[13] < 0)
    work1d.d[13] = settings1d.kkt_reg;
  else
    work1d.d[13] += settings1d.kkt_reg;
  work1d.d_inv[13] = 1/work1d.d[13];
  work1d.L[12] = (work1d.KKT[26])*work1d.d_inv[13];
  work1d.v[14] = work1d.KKT[27];
  work1d.d[14] = work1d.v[14];
  if (work1d.d[14] < 0)
    work1d.d[14] = settings1d.kkt_reg;
  else
    work1d.d[14] += settings1d.kkt_reg;
  work1d.d_inv[14] = 1/work1d.d[14];
  work1d.L[13] = (work1d.KKT[28])*work1d.d_inv[14];
  work1d.v[15] = work1d.KKT[29];
  work1d.d[15] = work1d.v[15];
  if (work1d.d[15] < 0)
    work1d.d[15] = settings1d.kkt_reg;
  else
    work1d.d[15] += settings1d.kkt_reg;
  work1d.d_inv[15] = 1/work1d.d[15];
  work1d.L[14] = (work1d.KKT[30])*work1d.d_inv[15];
  work1d.v[16] = work1d.KKT[31];
  work1d.d[16] = work1d.v[16];
  if (work1d.d[16] < 0)
    work1d.d[16] = settings1d.kkt_reg;
  else
    work1d.d[16] += settings1d.kkt_reg;
  work1d.d_inv[16] = 1/work1d.d[16];
  work1d.L[15] = (work1d.KKT[32])*work1d.d_inv[16];
  work1d.v[17] = work1d.KKT[33];
  work1d.d[17] = work1d.v[17];
  if (work1d.d[17] < 0)
    work1d.d[17] = settings1d.kkt_reg;
  else
    work1d.d[17] += settings1d.kkt_reg;
  work1d.d_inv[17] = 1/work1d.d[17];
  work1d.L[16] = (work1d.KKT[34])*work1d.d_inv[17];
  work1d.v[18] = work1d.KKT[35];
  work1d.d[18] = work1d.v[18];
  if (work1d.d[18] < 0)
    work1d.d[18] = settings1d.kkt_reg;
  else
    work1d.d[18] += settings1d.kkt_reg;
  work1d.d_inv[18] = 1/work1d.d[18];
  work1d.L[17] = (work1d.KKT[36])*work1d.d_inv[18];
  work1d.v[19] = work1d.KKT[37];
  work1d.d[19] = work1d.v[19];
  if (work1d.d[19] < 0)
    work1d.d[19] = settings1d.kkt_reg;
  else
    work1d.d[19] += settings1d.kkt_reg;
  work1d.d_inv[19] = 1/work1d.d[19];
  work1d.L[18] = (work1d.KKT[38])*work1d.d_inv[19];
  work1d.v[20] = work1d.KKT[39];
  work1d.d[20] = work1d.v[20];
  if (work1d.d[20] < 0)
    work1d.d[20] = settings1d.kkt_reg;
  else
    work1d.d[20] += settings1d.kkt_reg;
  work1d.d_inv[20] = 1/work1d.d[20];
  work1d.L[19] = (work1d.KKT[40])*work1d.d_inv[20];
  work1d.v[21] = work1d.KKT[41];
  work1d.d[21] = work1d.v[21];
  if (work1d.d[21] < 0)
    work1d.d[21] = settings1d.kkt_reg;
  else
    work1d.d[21] += settings1d.kkt_reg;
  work1d.d_inv[21] = 1/work1d.d[21];
  work1d.L[20] = (work1d.KKT[42])*work1d.d_inv[21];
  work1d.v[22] = work1d.KKT[43];
  work1d.d[22] = work1d.v[22];
  if (work1d.d[22] < 0)
    work1d.d[22] = settings1d.kkt_reg;
  else
    work1d.d[22] += settings1d.kkt_reg;
  work1d.d_inv[22] = 1/work1d.d[22];
  work1d.L[21] = (work1d.KKT[44])*work1d.d_inv[22];
  work1d.v[23] = work1d.KKT[45];
  work1d.d[23] = work1d.v[23];
  if (work1d.d[23] < 0)
    work1d.d[23] = settings1d.kkt_reg;
  else
    work1d.d[23] += settings1d.kkt_reg;
  work1d.d_inv[23] = 1/work1d.d[23];
  work1d.L[22] = (work1d.KKT[46])*work1d.d_inv[23];
  work1d.v[24] = work1d.KKT[47];
  work1d.d[24] = work1d.v[24];
  if (work1d.d[24] < 0)
    work1d.d[24] = settings1d.kkt_reg;
  else
    work1d.d[24] += settings1d.kkt_reg;
  work1d.d_inv[24] = 1/work1d.d[24];
  work1d.L[23] = (work1d.KKT[48])*work1d.d_inv[24];
  work1d.v[25] = work1d.KKT[49];
  work1d.d[25] = work1d.v[25];
  if (work1d.d[25] < 0)
    work1d.d[25] = settings1d.kkt_reg;
  else
    work1d.d[25] += settings1d.kkt_reg;
  work1d.d_inv[25] = 1/work1d.d[25];
  work1d.L[24] = (work1d.KKT[50])*work1d.d_inv[25];
  work1d.v[26] = work1d.KKT[51];
  work1d.d[26] = work1d.v[26];
  if (work1d.d[26] < 0)
    work1d.d[26] = settings1d.kkt_reg;
  else
    work1d.d[26] += settings1d.kkt_reg;
  work1d.d_inv[26] = 1/work1d.d[26];
  work1d.L[25] = (work1d.KKT[52])*work1d.d_inv[26];
  work1d.v[27] = work1d.KKT[53];
  work1d.d[27] = work1d.v[27];
  if (work1d.d[27] < 0)
    work1d.d[27] = settings1d.kkt_reg;
  else
    work1d.d[27] += settings1d.kkt_reg;
  work1d.d_inv[27] = 1/work1d.d[27];
  work1d.L[26] = (work1d.KKT[54])*work1d.d_inv[27];
  work1d.v[28] = work1d.KKT[55];
  work1d.d[28] = work1d.v[28];
  if (work1d.d[28] < 0)
    work1d.d[28] = settings1d.kkt_reg;
  else
    work1d.d[28] += settings1d.kkt_reg;
  work1d.d_inv[28] = 1/work1d.d[28];
  work1d.L[27] = (work1d.KKT[56])*work1d.d_inv[28];
  work1d.v[29] = work1d.KKT[57];
  work1d.d[29] = work1d.v[29];
  if (work1d.d[29] < 0)
    work1d.d[29] = settings1d.kkt_reg;
  else
    work1d.d[29] += settings1d.kkt_reg;
  work1d.d_inv[29] = 1/work1d.d[29];
  work1d.L[28] = (work1d.KKT[58])*work1d.d_inv[29];
  work1d.v[30] = work1d.KKT[59];
  work1d.d[30] = work1d.v[30];
  if (work1d.d[30] < 0)
    work1d.d[30] = settings1d.kkt_reg;
  else
    work1d.d[30] += settings1d.kkt_reg;
  work1d.d_inv[30] = 1/work1d.d[30];
  work1d.L[29] = (work1d.KKT[60])*work1d.d_inv[30];
  work1d.v[31] = work1d.KKT[61];
  work1d.d[31] = work1d.v[31];
  if (work1d.d[31] < 0)
    work1d.d[31] = settings1d.kkt_reg;
  else
    work1d.d[31] += settings1d.kkt_reg;
  work1d.d_inv[31] = 1/work1d.d[31];
  work1d.L[30] = (work1d.KKT[62])*work1d.d_inv[31];
  work1d.v[32] = work1d.KKT[63];
  work1d.d[32] = work1d.v[32];
  if (work1d.d[32] < 0)
    work1d.d[32] = settings1d.kkt_reg;
  else
    work1d.d[32] += settings1d.kkt_reg;
  work1d.d_inv[32] = 1/work1d.d[32];
  work1d.L[31] = (work1d.KKT[64])*work1d.d_inv[32];
  work1d.v[33] = work1d.KKT[65];
  work1d.d[33] = work1d.v[33];
  if (work1d.d[33] < 0)
    work1d.d[33] = settings1d.kkt_reg;
  else
    work1d.d[33] += settings1d.kkt_reg;
  work1d.d_inv[33] = 1/work1d.d[33];
  work1d.L[32] = (work1d.KKT[66])*work1d.d_inv[33];
  work1d.v[34] = work1d.KKT[67];
  work1d.d[34] = work1d.v[34];
  if (work1d.d[34] < 0)
    work1d.d[34] = settings1d.kkt_reg;
  else
    work1d.d[34] += settings1d.kkt_reg;
  work1d.d_inv[34] = 1/work1d.d[34];
  work1d.L[33] = (work1d.KKT[68])*work1d.d_inv[34];
  work1d.v[35] = work1d.KKT[69];
  work1d.d[35] = work1d.v[35];
  if (work1d.d[35] < 0)
    work1d.d[35] = settings1d.kkt_reg;
  else
    work1d.d[35] += settings1d.kkt_reg;
  work1d.d_inv[35] = 1/work1d.d[35];
  work1d.L[34] = (work1d.KKT[70])*work1d.d_inv[35];
  work1d.v[36] = work1d.KKT[71];
  work1d.d[36] = work1d.v[36];
  if (work1d.d[36] < 0)
    work1d.d[36] = settings1d.kkt_reg;
  else
    work1d.d[36] += settings1d.kkt_reg;
  work1d.d_inv[36] = 1/work1d.d[36];
  work1d.L[35] = (work1d.KKT[72])*work1d.d_inv[36];
  work1d.v[37] = work1d.KKT[73];
  work1d.d[37] = work1d.v[37];
  if (work1d.d[37] < 0)
    work1d.d[37] = settings1d.kkt_reg;
  else
    work1d.d[37] += settings1d.kkt_reg;
  work1d.d_inv[37] = 1/work1d.d[37];
  work1d.L[36] = (work1d.KKT[74])*work1d.d_inv[37];
  work1d.v[38] = work1d.KKT[75];
  work1d.d[38] = work1d.v[38];
  if (work1d.d[38] < 0)
    work1d.d[38] = settings1d.kkt_reg;
  else
    work1d.d[38] += settings1d.kkt_reg;
  work1d.d_inv[38] = 1/work1d.d[38];
  work1d.L[37] = (work1d.KKT[76])*work1d.d_inv[38];
  work1d.v[39] = work1d.KKT[77];
  work1d.d[39] = work1d.v[39];
  if (work1d.d[39] < 0)
    work1d.d[39] = settings1d.kkt_reg;
  else
    work1d.d[39] += settings1d.kkt_reg;
  work1d.d_inv[39] = 1/work1d.d[39];
  work1d.L[38] = (work1d.KKT[78])*work1d.d_inv[39];
  work1d.v[40] = work1d.KKT[79];
  work1d.d[40] = work1d.v[40];
  if (work1d.d[40] < 0)
    work1d.d[40] = settings1d.kkt_reg;
  else
    work1d.d[40] += settings1d.kkt_reg;
  work1d.d_inv[40] = 1/work1d.d[40];
  work1d.L[39] = (work1d.KKT[80])*work1d.d_inv[40];
  work1d.v[41] = work1d.KKT[81];
  work1d.d[41] = work1d.v[41];
  if (work1d.d[41] < 0)
    work1d.d[41] = settings1d.kkt_reg;
  else
    work1d.d[41] += settings1d.kkt_reg;
  work1d.d_inv[41] = 1/work1d.d[41];
  work1d.L[40] = (work1d.KKT[82])*work1d.d_inv[41];
  work1d.v[42] = work1d.KKT[83];
  work1d.d[42] = work1d.v[42];
  if (work1d.d[42] < 0)
    work1d.d[42] = settings1d.kkt_reg;
  else
    work1d.d[42] += settings1d.kkt_reg;
  work1d.d_inv[42] = 1/work1d.d[42];
  work1d.L[41] = (work1d.KKT[84])*work1d.d_inv[42];
  work1d.v[43] = work1d.KKT[85];
  work1d.d[43] = work1d.v[43];
  if (work1d.d[43] < 0)
    work1d.d[43] = settings1d.kkt_reg;
  else
    work1d.d[43] += settings1d.kkt_reg;
  work1d.d_inv[43] = 1/work1d.d[43];
  work1d.L[42] = (work1d.KKT[86])*work1d.d_inv[43];
  work1d.v[44] = work1d.KKT[87];
  work1d.d[44] = work1d.v[44];
  if (work1d.d[44] < 0)
    work1d.d[44] = settings1d.kkt_reg;
  else
    work1d.d[44] += settings1d.kkt_reg;
  work1d.d_inv[44] = 1/work1d.d[44];
  work1d.L[43] = (work1d.KKT[88])*work1d.d_inv[44];
  work1d.v[45] = work1d.KKT[89];
  work1d.d[45] = work1d.v[45];
  if (work1d.d[45] < 0)
    work1d.d[45] = settings1d.kkt_reg;
  else
    work1d.d[45] += settings1d.kkt_reg;
  work1d.d_inv[45] = 1/work1d.d[45];
  work1d.L[44] = (work1d.KKT[90])*work1d.d_inv[45];
  work1d.v[46] = work1d.KKT[91];
  work1d.d[46] = work1d.v[46];
  if (work1d.d[46] < 0)
    work1d.d[46] = settings1d.kkt_reg;
  else
    work1d.d[46] += settings1d.kkt_reg;
  work1d.d_inv[46] = 1/work1d.d[46];
  work1d.L[45] = (work1d.KKT[92])*work1d.d_inv[46];
  work1d.v[47] = work1d.KKT[93];
  work1d.d[47] = work1d.v[47];
  if (work1d.d[47] < 0)
    work1d.d[47] = settings1d.kkt_reg;
  else
    work1d.d[47] += settings1d.kkt_reg;
  work1d.d_inv[47] = 1/work1d.d[47];
  work1d.L[46] = (work1d.KKT[94])*work1d.d_inv[47];
  work1d.v[48] = work1d.KKT[95];
  work1d.d[48] = work1d.v[48];
  if (work1d.d[48] < 0)
    work1d.d[48] = settings1d.kkt_reg;
  else
    work1d.d[48] += settings1d.kkt_reg;
  work1d.d_inv[48] = 1/work1d.d[48];
  work1d.L[47] = (work1d.KKT[96])*work1d.d_inv[48];
  work1d.v[49] = work1d.KKT[97];
  work1d.d[49] = work1d.v[49];
  if (work1d.d[49] < 0)
    work1d.d[49] = settings1d.kkt_reg;
  else
    work1d.d[49] += settings1d.kkt_reg;
  work1d.d_inv[49] = 1/work1d.d[49];
  work1d.L[48] = (work1d.KKT[98])*work1d.d_inv[49];
  work1d.v[50] = work1d.KKT[99];
  work1d.d[50] = work1d.v[50];
  if (work1d.d[50] < 0)
    work1d.d[50] = settings1d.kkt_reg;
  else
    work1d.d[50] += settings1d.kkt_reg;
  work1d.d_inv[50] = 1/work1d.d[50];
  work1d.L[49] = (work1d.KKT[100])*work1d.d_inv[50];
  work1d.v[51] = work1d.KKT[101];
  work1d.d[51] = work1d.v[51];
  if (work1d.d[51] < 0)
    work1d.d[51] = settings1d.kkt_reg;
  else
    work1d.d[51] += settings1d.kkt_reg;
  work1d.d_inv[51] = 1/work1d.d[51];
  work1d.L[50] = (work1d.KKT[102])*work1d.d_inv[51];
  work1d.v[52] = work1d.KKT[103];
  work1d.d[52] = work1d.v[52];
  if (work1d.d[52] < 0)
    work1d.d[52] = settings1d.kkt_reg;
  else
    work1d.d[52] += settings1d.kkt_reg;
  work1d.d_inv[52] = 1/work1d.d[52];
  work1d.L[51] = (work1d.KKT[104])*work1d.d_inv[52];
  work1d.v[53] = work1d.KKT[105];
  work1d.d[53] = work1d.v[53];
  if (work1d.d[53] < 0)
    work1d.d[53] = settings1d.kkt_reg;
  else
    work1d.d[53] += settings1d.kkt_reg;
  work1d.d_inv[53] = 1/work1d.d[53];
  work1d.L[52] = (work1d.KKT[106])*work1d.d_inv[53];
  work1d.v[54] = work1d.KKT[107];
  work1d.d[54] = work1d.v[54];
  if (work1d.d[54] < 0)
    work1d.d[54] = settings1d.kkt_reg;
  else
    work1d.d[54] += settings1d.kkt_reg;
  work1d.d_inv[54] = 1/work1d.d[54];
  work1d.L[53] = (work1d.KKT[108])*work1d.d_inv[54];
  work1d.v[55] = work1d.KKT[109];
  work1d.d[55] = work1d.v[55];
  if (work1d.d[55] < 0)
    work1d.d[55] = settings1d.kkt_reg;
  else
    work1d.d[55] += settings1d.kkt_reg;
  work1d.d_inv[55] = 1/work1d.d[55];
  work1d.L[54] = (work1d.KKT[110])*work1d.d_inv[55];
  work1d.v[56] = work1d.KKT[111];
  work1d.d[56] = work1d.v[56];
  if (work1d.d[56] < 0)
    work1d.d[56] = settings1d.kkt_reg;
  else
    work1d.d[56] += settings1d.kkt_reg;
  work1d.d_inv[56] = 1/work1d.d[56];
  work1d.L[55] = (work1d.KKT[112])*work1d.d_inv[56];
  work1d.v[57] = work1d.KKT[113];
  work1d.d[57] = work1d.v[57];
  if (work1d.d[57] < 0)
    work1d.d[57] = settings1d.kkt_reg;
  else
    work1d.d[57] += settings1d.kkt_reg;
  work1d.d_inv[57] = 1/work1d.d[57];
  work1d.L[56] = (work1d.KKT[114])*work1d.d_inv[57];
  work1d.v[58] = work1d.KKT[115];
  work1d.d[58] = work1d.v[58];
  if (work1d.d[58] < 0)
    work1d.d[58] = settings1d.kkt_reg;
  else
    work1d.d[58] += settings1d.kkt_reg;
  work1d.d_inv[58] = 1/work1d.d[58];
  work1d.L[57] = (work1d.KKT[116])*work1d.d_inv[58];
  work1d.v[59] = work1d.KKT[117];
  work1d.d[59] = work1d.v[59];
  if (work1d.d[59] < 0)
    work1d.d[59] = settings1d.kkt_reg;
  else
    work1d.d[59] += settings1d.kkt_reg;
  work1d.d_inv[59] = 1/work1d.d[59];
  work1d.L[58] = (work1d.KKT[118])*work1d.d_inv[59];
  work1d.v[60] = work1d.KKT[119];
  work1d.d[60] = work1d.v[60];
  if (work1d.d[60] < 0)
    work1d.d[60] = settings1d.kkt_reg;
  else
    work1d.d[60] += settings1d.kkt_reg;
  work1d.d_inv[60] = 1/work1d.d[60];
  work1d.L[59] = (work1d.KKT[120])*work1d.d_inv[60];
  work1d.v[61] = work1d.KKT[121];
  work1d.d[61] = work1d.v[61];
  if (work1d.d[61] < 0)
    work1d.d[61] = settings1d.kkt_reg;
  else
    work1d.d[61] += settings1d.kkt_reg;
  work1d.d_inv[61] = 1/work1d.d[61];
  work1d.L[60] = (work1d.KKT[122])*work1d.d_inv[61];
  work1d.v[62] = work1d.KKT[123];
  work1d.d[62] = work1d.v[62];
  if (work1d.d[62] < 0)
    work1d.d[62] = settings1d.kkt_reg;
  else
    work1d.d[62] += settings1d.kkt_reg;
  work1d.d_inv[62] = 1/work1d.d[62];
  work1d.L[61] = (work1d.KKT[124])*work1d.d_inv[62];
  work1d.v[63] = work1d.KKT[125];
  work1d.d[63] = work1d.v[63];
  if (work1d.d[63] < 0)
    work1d.d[63] = settings1d.kkt_reg;
  else
    work1d.d[63] += settings1d.kkt_reg;
  work1d.d_inv[63] = 1/work1d.d[63];
  work1d.L[62] = (work1d.KKT[126])*work1d.d_inv[63];
  work1d.v[64] = work1d.KKT[127];
  work1d.d[64] = work1d.v[64];
  if (work1d.d[64] < 0)
    work1d.d[64] = settings1d.kkt_reg;
  else
    work1d.d[64] += settings1d.kkt_reg;
  work1d.d_inv[64] = 1/work1d.d[64];
  work1d.L[63] = (work1d.KKT[128])*work1d.d_inv[64];
  work1d.v[65] = work1d.KKT[129];
  work1d.d[65] = work1d.v[65];
  if (work1d.d[65] < 0)
    work1d.d[65] = settings1d.kkt_reg;
  else
    work1d.d[65] += settings1d.kkt_reg;
  work1d.d_inv[65] = 1/work1d.d[65];
  work1d.L[64] = (work1d.KKT[130])*work1d.d_inv[65];
  work1d.v[66] = work1d.KKT[131];
  work1d.d[66] = work1d.v[66];
  if (work1d.d[66] < 0)
    work1d.d[66] = settings1d.kkt_reg;
  else
    work1d.d[66] += settings1d.kkt_reg;
  work1d.d_inv[66] = 1/work1d.d[66];
  work1d.L[65] = (work1d.KKT[132])*work1d.d_inv[66];
  work1d.v[67] = work1d.KKT[133];
  work1d.d[67] = work1d.v[67];
  if (work1d.d[67] < 0)
    work1d.d[67] = settings1d.kkt_reg;
  else
    work1d.d[67] += settings1d.kkt_reg;
  work1d.d_inv[67] = 1/work1d.d[67];
  work1d.L[66] = (work1d.KKT[134])*work1d.d_inv[67];
  work1d.v[68] = work1d.KKT[135];
  work1d.d[68] = work1d.v[68];
  if (work1d.d[68] < 0)
    work1d.d[68] = settings1d.kkt_reg;
  else
    work1d.d[68] += settings1d.kkt_reg;
  work1d.d_inv[68] = 1/work1d.d[68];
  work1d.L[67] = (work1d.KKT[136])*work1d.d_inv[68];
  work1d.v[69] = work1d.KKT[137];
  work1d.d[69] = work1d.v[69];
  if (work1d.d[69] < 0)
    work1d.d[69] = settings1d.kkt_reg;
  else
    work1d.d[69] += settings1d.kkt_reg;
  work1d.d_inv[69] = 1/work1d.d[69];
  work1d.L[68] = (work1d.KKT[138])*work1d.d_inv[69];
  work1d.v[70] = work1d.KKT[139];
  work1d.d[70] = work1d.v[70];
  if (work1d.d[70] < 0)
    work1d.d[70] = settings1d.kkt_reg;
  else
    work1d.d[70] += settings1d.kkt_reg;
  work1d.d_inv[70] = 1/work1d.d[70];
  work1d.L[69] = (work1d.KKT[140])*work1d.d_inv[70];
  work1d.v[71] = work1d.KKT[141];
  work1d.d[71] = work1d.v[71];
  if (work1d.d[71] < 0)
    work1d.d[71] = settings1d.kkt_reg;
  else
    work1d.d[71] += settings1d.kkt_reg;
  work1d.d_inv[71] = 1/work1d.d[71];
  work1d.L[70] = (work1d.KKT[142])*work1d.d_inv[71];
  work1d.v[72] = work1d.KKT[143];
  work1d.d[72] = work1d.v[72];
  if (work1d.d[72] < 0)
    work1d.d[72] = settings1d.kkt_reg;
  else
    work1d.d[72] += settings1d.kkt_reg;
  work1d.d_inv[72] = 1/work1d.d[72];
  work1d.L[71] = (work1d.KKT[144])*work1d.d_inv[72];
  work1d.v[73] = work1d.KKT[145];
  work1d.d[73] = work1d.v[73];
  if (work1d.d[73] < 0)
    work1d.d[73] = settings1d.kkt_reg;
  else
    work1d.d[73] += settings1d.kkt_reg;
  work1d.d_inv[73] = 1/work1d.d[73];
  work1d.L[72] = (work1d.KKT[146])*work1d.d_inv[73];
  work1d.v[74] = work1d.KKT[147];
  work1d.d[74] = work1d.v[74];
  if (work1d.d[74] < 0)
    work1d.d[74] = settings1d.kkt_reg;
  else
    work1d.d[74] += settings1d.kkt_reg;
  work1d.d_inv[74] = 1/work1d.d[74];
  work1d.L[73] = (work1d.KKT[148])*work1d.d_inv[74];
  work1d.v[75] = work1d.KKT[149];
  work1d.d[75] = work1d.v[75];
  if (work1d.d[75] < 0)
    work1d.d[75] = settings1d.kkt_reg;
  else
    work1d.d[75] += settings1d.kkt_reg;
  work1d.d_inv[75] = 1/work1d.d[75];
  work1d.L[74] = (work1d.KKT[150])*work1d.d_inv[75];
  work1d.v[76] = work1d.KKT[151];
  work1d.d[76] = work1d.v[76];
  if (work1d.d[76] < 0)
    work1d.d[76] = settings1d.kkt_reg;
  else
    work1d.d[76] += settings1d.kkt_reg;
  work1d.d_inv[76] = 1/work1d.d[76];
  work1d.L[75] = (work1d.KKT[152])*work1d.d_inv[76];
  work1d.v[77] = work1d.KKT[153];
  work1d.d[77] = work1d.v[77];
  if (work1d.d[77] < 0)
    work1d.d[77] = settings1d.kkt_reg;
  else
    work1d.d[77] += settings1d.kkt_reg;
  work1d.d_inv[77] = 1/work1d.d[77];
  work1d.L[76] = (work1d.KKT[154])*work1d.d_inv[77];
  work1d.v[78] = work1d.KKT[155];
  work1d.d[78] = work1d.v[78];
  if (work1d.d[78] < 0)
    work1d.d[78] = settings1d.kkt_reg;
  else
    work1d.d[78] += settings1d.kkt_reg;
  work1d.d_inv[78] = 1/work1d.d[78];
  work1d.L[77] = (work1d.KKT[156])*work1d.d_inv[78];
  work1d.v[79] = work1d.KKT[157];
  work1d.d[79] = work1d.v[79];
  if (work1d.d[79] < 0)
    work1d.d[79] = settings1d.kkt_reg;
  else
    work1d.d[79] += settings1d.kkt_reg;
  work1d.d_inv[79] = 1/work1d.d[79];
  work1d.L[78] = (work1d.KKT[158])*work1d.d_inv[79];
  work1d.v[80] = work1d.KKT[159];
  work1d.d[80] = work1d.v[80];
  if (work1d.d[80] < 0)
    work1d.d[80] = settings1d.kkt_reg;
  else
    work1d.d[80] += settings1d.kkt_reg;
  work1d.d_inv[80] = 1/work1d.d[80];
  work1d.L[79] = (work1d.KKT[160])*work1d.d_inv[80];
  work1d.v[81] = work1d.KKT[161];
  work1d.d[81] = work1d.v[81];
  if (work1d.d[81] < 0)
    work1d.d[81] = settings1d.kkt_reg;
  else
    work1d.d[81] += settings1d.kkt_reg;
  work1d.d_inv[81] = 1/work1d.d[81];
  work1d.L[80] = (work1d.KKT[162])*work1d.d_inv[81];
  work1d.v[82] = work1d.KKT[163];
  work1d.d[82] = work1d.v[82];
  if (work1d.d[82] < 0)
    work1d.d[82] = settings1d.kkt_reg;
  else
    work1d.d[82] += settings1d.kkt_reg;
  work1d.d_inv[82] = 1/work1d.d[82];
  work1d.L[81] = (work1d.KKT[164])*work1d.d_inv[82];
  work1d.v[83] = work1d.KKT[165];
  work1d.d[83] = work1d.v[83];
  if (work1d.d[83] < 0)
    work1d.d[83] = settings1d.kkt_reg;
  else
    work1d.d[83] += settings1d.kkt_reg;
  work1d.d_inv[83] = 1/work1d.d[83];
  work1d.L[82] = (work1d.KKT[166])*work1d.d_inv[83];
  work1d.v[84] = work1d.KKT[167];
  work1d.d[84] = work1d.v[84];
  if (work1d.d[84] < 0)
    work1d.d[84] = settings1d.kkt_reg;
  else
    work1d.d[84] += settings1d.kkt_reg;
  work1d.d_inv[84] = 1/work1d.d[84];
  work1d.L[83] = (work1d.KKT[168])*work1d.d_inv[84];
  work1d.v[85] = work1d.KKT[169];
  work1d.d[85] = work1d.v[85];
  if (work1d.d[85] < 0)
    work1d.d[85] = settings1d.kkt_reg;
  else
    work1d.d[85] += settings1d.kkt_reg;
  work1d.d_inv[85] = 1/work1d.d[85];
  work1d.L[84] = (work1d.KKT[170])*work1d.d_inv[85];
  work1d.v[86] = work1d.KKT[171];
  work1d.d[86] = work1d.v[86];
  if (work1d.d[86] < 0)
    work1d.d[86] = settings1d.kkt_reg;
  else
    work1d.d[86] += settings1d.kkt_reg;
  work1d.d_inv[86] = 1/work1d.d[86];
  work1d.L[85] = (work1d.KKT[172])*work1d.d_inv[86];
  work1d.v[87] = work1d.KKT[173];
  work1d.d[87] = work1d.v[87];
  if (work1d.d[87] < 0)
    work1d.d[87] = settings1d.kkt_reg;
  else
    work1d.d[87] += settings1d.kkt_reg;
  work1d.d_inv[87] = 1/work1d.d[87];
  work1d.L[86] = (work1d.KKT[174])*work1d.d_inv[87];
  work1d.v[88] = work1d.KKT[175];
  work1d.d[88] = work1d.v[88];
  if (work1d.d[88] < 0)
    work1d.d[88] = settings1d.kkt_reg;
  else
    work1d.d[88] += settings1d.kkt_reg;
  work1d.d_inv[88] = 1/work1d.d[88];
  work1d.L[87] = (work1d.KKT[176])*work1d.d_inv[88];
  work1d.v[89] = work1d.KKT[177];
  work1d.d[89] = work1d.v[89];
  if (work1d.d[89] < 0)
    work1d.d[89] = settings1d.kkt_reg;
  else
    work1d.d[89] += settings1d.kkt_reg;
  work1d.d_inv[89] = 1/work1d.d[89];
  work1d.L[88] = (work1d.KKT[178])*work1d.d_inv[89];
  work1d.v[90] = work1d.KKT[179];
  work1d.d[90] = work1d.v[90];
  if (work1d.d[90] < 0)
    work1d.d[90] = settings1d.kkt_reg;
  else
    work1d.d[90] += settings1d.kkt_reg;
  work1d.d_inv[90] = 1/work1d.d[90];
  work1d.L[89] = (work1d.KKT[180])*work1d.d_inv[90];
  work1d.v[91] = work1d.KKT[181];
  work1d.d[91] = work1d.v[91];
  if (work1d.d[91] < 0)
    work1d.d[91] = settings1d.kkt_reg;
  else
    work1d.d[91] += settings1d.kkt_reg;
  work1d.d_inv[91] = 1/work1d.d[91];
  work1d.L[90] = (work1d.KKT[182])*work1d.d_inv[91];
  work1d.v[92] = work1d.KKT[183];
  work1d.d[92] = work1d.v[92];
  if (work1d.d[92] < 0)
    work1d.d[92] = settings1d.kkt_reg;
  else
    work1d.d[92] += settings1d.kkt_reg;
  work1d.d_inv[92] = 1/work1d.d[92];
  work1d.L[91] = (work1d.KKT[184])*work1d.d_inv[92];
  work1d.v[93] = work1d.KKT[185];
  work1d.d[93] = work1d.v[93];
  if (work1d.d[93] < 0)
    work1d.d[93] = settings1d.kkt_reg;
  else
    work1d.d[93] += settings1d.kkt_reg;
  work1d.d_inv[93] = 1/work1d.d[93];
  work1d.L[92] = (work1d.KKT[186])*work1d.d_inv[93];
  work1d.v[94] = work1d.KKT[187];
  work1d.d[94] = work1d.v[94];
  if (work1d.d[94] < 0)
    work1d.d[94] = settings1d.kkt_reg;
  else
    work1d.d[94] += settings1d.kkt_reg;
  work1d.d_inv[94] = 1/work1d.d[94];
  work1d.L[93] = (work1d.KKT[188])*work1d.d_inv[94];
  work1d.v[95] = work1d.KKT[189];
  work1d.d[95] = work1d.v[95];
  if (work1d.d[95] < 0)
    work1d.d[95] = settings1d.kkt_reg;
  else
    work1d.d[95] += settings1d.kkt_reg;
  work1d.d_inv[95] = 1/work1d.d[95];
  work1d.L[94] = (work1d.KKT[190])*work1d.d_inv[95];
  work1d.v[96] = work1d.KKT[191];
  work1d.d[96] = work1d.v[96];
  if (work1d.d[96] < 0)
    work1d.d[96] = settings1d.kkt_reg;
  else
    work1d.d[96] += settings1d.kkt_reg;
  work1d.d_inv[96] = 1/work1d.d[96];
  work1d.L[95] = (work1d.KKT[192])*work1d.d_inv[96];
  work1d.v[97] = work1d.KKT[193];
  work1d.d[97] = work1d.v[97];
  if (work1d.d[97] < 0)
    work1d.d[97] = settings1d.kkt_reg;
  else
    work1d.d[97] += settings1d.kkt_reg;
  work1d.d_inv[97] = 1/work1d.d[97];
  work1d.L[96] = (work1d.KKT[194])*work1d.d_inv[97];
  work1d.v[98] = work1d.KKT[195];
  work1d.d[98] = work1d.v[98];
  if (work1d.d[98] < 0)
    work1d.d[98] = settings1d.kkt_reg;
  else
    work1d.d[98] += settings1d.kkt_reg;
  work1d.d_inv[98] = 1/work1d.d[98];
  work1d.L[97] = (work1d.KKT[196])*work1d.d_inv[98];
  work1d.v[99] = work1d.KKT[197];
  work1d.d[99] = work1d.v[99];
  if (work1d.d[99] < 0)
    work1d.d[99] = settings1d.kkt_reg;
  else
    work1d.d[99] += settings1d.kkt_reg;
  work1d.d_inv[99] = 1/work1d.d[99];
  work1d.L[98] = (work1d.KKT[198])*work1d.d_inv[99];
  work1d.v[100] = work1d.KKT[199];
  work1d.d[100] = work1d.v[100];
  if (work1d.d[100] < 0)
    work1d.d[100] = settings1d.kkt_reg;
  else
    work1d.d[100] += settings1d.kkt_reg;
  work1d.d_inv[100] = 1/work1d.d[100];
  work1d.L[99] = (work1d.KKT[200])*work1d.d_inv[100];
  work1d.v[101] = work1d.KKT[201];
  work1d.d[101] = work1d.v[101];
  if (work1d.d[101] < 0)
    work1d.d[101] = settings1d.kkt_reg;
  else
    work1d.d[101] += settings1d.kkt_reg;
  work1d.d_inv[101] = 1/work1d.d[101];
  work1d.L[100] = (work1d.KKT[202])*work1d.d_inv[101];
  work1d.v[102] = work1d.KKT[203];
  work1d.d[102] = work1d.v[102];
  if (work1d.d[102] < 0)
    work1d.d[102] = settings1d.kkt_reg;
  else
    work1d.d[102] += settings1d.kkt_reg;
  work1d.d_inv[102] = 1/work1d.d[102];
  work1d.L[101] = (work1d.KKT[204])*work1d.d_inv[102];
  work1d.v[103] = work1d.KKT[205];
  work1d.d[103] = work1d.v[103];
  if (work1d.d[103] < 0)
    work1d.d[103] = settings1d.kkt_reg;
  else
    work1d.d[103] += settings1d.kkt_reg;
  work1d.d_inv[103] = 1/work1d.d[103];
  work1d.L[102] = (work1d.KKT[206])*work1d.d_inv[103];
  work1d.v[104] = work1d.KKT[207];
  work1d.d[104] = work1d.v[104];
  if (work1d.d[104] < 0)
    work1d.d[104] = settings1d.kkt_reg;
  else
    work1d.d[104] += settings1d.kkt_reg;
  work1d.d_inv[104] = 1/work1d.d[104];
  work1d.L[103] = (work1d.KKT[208])*work1d.d_inv[104];
  work1d.v[105] = work1d.KKT[209];
  work1d.d[105] = work1d.v[105];
  if (work1d.d[105] < 0)
    work1d.d[105] = settings1d.kkt_reg;
  else
    work1d.d[105] += settings1d.kkt_reg;
  work1d.d_inv[105] = 1/work1d.d[105];
  work1d.L[104] = (work1d.KKT[210])*work1d.d_inv[105];
  work1d.v[106] = work1d.KKT[211];
  work1d.d[106] = work1d.v[106];
  if (work1d.d[106] < 0)
    work1d.d[106] = settings1d.kkt_reg;
  else
    work1d.d[106] += settings1d.kkt_reg;
  work1d.d_inv[106] = 1/work1d.d[106];
  work1d.L[105] = (work1d.KKT[212])*work1d.d_inv[106];
  work1d.v[107] = work1d.KKT[213];
  work1d.d[107] = work1d.v[107];
  if (work1d.d[107] < 0)
    work1d.d[107] = settings1d.kkt_reg;
  else
    work1d.d[107] += settings1d.kkt_reg;
  work1d.d_inv[107] = 1/work1d.d[107];
  work1d.L[106] = (work1d.KKT[214])*work1d.d_inv[107];
  work1d.v[108] = work1d.KKT[215];
  work1d.d[108] = work1d.v[108];
  if (work1d.d[108] < 0)
    work1d.d[108] = settings1d.kkt_reg;
  else
    work1d.d[108] += settings1d.kkt_reg;
  work1d.d_inv[108] = 1/work1d.d[108];
  work1d.L[107] = (work1d.KKT[216])*work1d.d_inv[108];
  work1d.v[109] = work1d.KKT[217];
  work1d.d[109] = work1d.v[109];
  if (work1d.d[109] < 0)
    work1d.d[109] = settings1d.kkt_reg;
  else
    work1d.d[109] += settings1d.kkt_reg;
  work1d.d_inv[109] = 1/work1d.d[109];
  work1d.L[108] = (work1d.KKT[218])*work1d.d_inv[109];
  work1d.v[110] = work1d.KKT[219];
  work1d.d[110] = work1d.v[110];
  if (work1d.d[110] < 0)
    work1d.d[110] = settings1d.kkt_reg;
  else
    work1d.d[110] += settings1d.kkt_reg;
  work1d.d_inv[110] = 1/work1d.d[110];
  work1d.L[109] = (work1d.KKT[220])*work1d.d_inv[110];
  work1d.v[111] = work1d.KKT[221];
  work1d.d[111] = work1d.v[111];
  if (work1d.d[111] < 0)
    work1d.d[111] = settings1d.kkt_reg;
  else
    work1d.d[111] += settings1d.kkt_reg;
  work1d.d_inv[111] = 1/work1d.d[111];
  work1d.L[110] = (work1d.KKT[222])*work1d.d_inv[111];
  work1d.v[112] = work1d.KKT[223];
  work1d.d[112] = work1d.v[112];
  if (work1d.d[112] < 0)
    work1d.d[112] = settings1d.kkt_reg;
  else
    work1d.d[112] += settings1d.kkt_reg;
  work1d.d_inv[112] = 1/work1d.d[112];
  work1d.L[111] = (work1d.KKT[224])*work1d.d_inv[112];
  work1d.v[113] = work1d.KKT[225];
  work1d.d[113] = work1d.v[113];
  if (work1d.d[113] < 0)
    work1d.d[113] = settings1d.kkt_reg;
  else
    work1d.d[113] += settings1d.kkt_reg;
  work1d.d_inv[113] = 1/work1d.d[113];
  work1d.L[112] = (work1d.KKT[226])*work1d.d_inv[113];
  work1d.v[114] = work1d.KKT[227];
  work1d.d[114] = work1d.v[114];
  if (work1d.d[114] < 0)
    work1d.d[114] = settings1d.kkt_reg;
  else
    work1d.d[114] += settings1d.kkt_reg;
  work1d.d_inv[114] = 1/work1d.d[114];
  work1d.L[113] = (work1d.KKT[228])*work1d.d_inv[114];
  work1d.v[115] = work1d.KKT[229];
  work1d.d[115] = work1d.v[115];
  if (work1d.d[115] < 0)
    work1d.d[115] = settings1d.kkt_reg;
  else
    work1d.d[115] += settings1d.kkt_reg;
  work1d.d_inv[115] = 1/work1d.d[115];
  work1d.L[114] = (work1d.KKT[230])*work1d.d_inv[115];
  work1d.v[116] = work1d.KKT[231];
  work1d.d[116] = work1d.v[116];
  if (work1d.d[116] < 0)
    work1d.d[116] = settings1d.kkt_reg;
  else
    work1d.d[116] += settings1d.kkt_reg;
  work1d.d_inv[116] = 1/work1d.d[116];
  work1d.L[115] = (work1d.KKT[232])*work1d.d_inv[116];
  work1d.v[117] = work1d.KKT[233];
  work1d.d[117] = work1d.v[117];
  if (work1d.d[117] < 0)
    work1d.d[117] = settings1d.kkt_reg;
  else
    work1d.d[117] += settings1d.kkt_reg;
  work1d.d_inv[117] = 1/work1d.d[117];
  work1d.L[116] = (work1d.KKT[234])*work1d.d_inv[117];
  work1d.v[118] = work1d.KKT[235];
  work1d.d[118] = work1d.v[118];
  if (work1d.d[118] < 0)
    work1d.d[118] = settings1d.kkt_reg;
  else
    work1d.d[118] += settings1d.kkt_reg;
  work1d.d_inv[118] = 1/work1d.d[118];
  work1d.L[117] = (work1d.KKT[236])*work1d.d_inv[118];
  work1d.v[119] = work1d.KKT[237];
  work1d.d[119] = work1d.v[119];
  if (work1d.d[119] < 0)
    work1d.d[119] = settings1d.kkt_reg;
  else
    work1d.d[119] += settings1d.kkt_reg;
  work1d.d_inv[119] = 1/work1d.d[119];
  work1d.L[118] = (work1d.KKT[238])*work1d.d_inv[119];
  work1d.v[120] = work1d.KKT[239];
  work1d.d[120] = work1d.v[120];
  if (work1d.d[120] < 0)
    work1d.d[120] = settings1d.kkt_reg;
  else
    work1d.d[120] += settings1d.kkt_reg;
  work1d.d_inv[120] = 1/work1d.d[120];
  work1d.L[119] = (work1d.KKT[240])*work1d.d_inv[120];
  work1d.v[121] = work1d.KKT[241];
  work1d.d[121] = work1d.v[121];
  if (work1d.d[121] < 0)
    work1d.d[121] = settings1d.kkt_reg;
  else
    work1d.d[121] += settings1d.kkt_reg;
  work1d.d_inv[121] = 1/work1d.d[121];
  work1d.L[120] = (work1d.KKT[242])*work1d.d_inv[121];
  work1d.v[122] = work1d.KKT[243];
  work1d.d[122] = work1d.v[122];
  if (work1d.d[122] < 0)
    work1d.d[122] = settings1d.kkt_reg;
  else
    work1d.d[122] += settings1d.kkt_reg;
  work1d.d_inv[122] = 1/work1d.d[122];
  work1d.L[121] = (work1d.KKT[244])*work1d.d_inv[122];
  work1d.v[123] = work1d.KKT[245];
  work1d.d[123] = work1d.v[123];
  if (work1d.d[123] < 0)
    work1d.d[123] = settings1d.kkt_reg;
  else
    work1d.d[123] += settings1d.kkt_reg;
  work1d.d_inv[123] = 1/work1d.d[123];
  work1d.L[122] = (work1d.KKT[246])*work1d.d_inv[123];
  work1d.v[124] = work1d.KKT[247];
  work1d.d[124] = work1d.v[124];
  if (work1d.d[124] < 0)
    work1d.d[124] = settings1d.kkt_reg;
  else
    work1d.d[124] += settings1d.kkt_reg;
  work1d.d_inv[124] = 1/work1d.d[124];
  work1d.L[123] = (work1d.KKT[248])*work1d.d_inv[124];
  work1d.v[125] = work1d.KKT[249];
  work1d.d[125] = work1d.v[125];
  if (work1d.d[125] < 0)
    work1d.d[125] = settings1d.kkt_reg;
  else
    work1d.d[125] += settings1d.kkt_reg;
  work1d.d_inv[125] = 1/work1d.d[125];
  work1d.L[124] = (work1d.KKT[250])*work1d.d_inv[125];
  work1d.v[126] = work1d.KKT[251];
  work1d.d[126] = work1d.v[126];
  if (work1d.d[126] < 0)
    work1d.d[126] = settings1d.kkt_reg;
  else
    work1d.d[126] += settings1d.kkt_reg;
  work1d.d_inv[126] = 1/work1d.d[126];
  work1d.L[125] = (work1d.KKT[252])*work1d.d_inv[126];
  work1d.v[127] = work1d.KKT[253];
  work1d.d[127] = work1d.v[127];
  if (work1d.d[127] < 0)
    work1d.d[127] = settings1d.kkt_reg;
  else
    work1d.d[127] += settings1d.kkt_reg;
  work1d.d_inv[127] = 1/work1d.d[127];
  work1d.L[126] = (work1d.KKT[254])*work1d.d_inv[127];
  work1d.v[128] = work1d.KKT[255];
  work1d.d[128] = work1d.v[128];
  if (work1d.d[128] < 0)
    work1d.d[128] = settings1d.kkt_reg;
  else
    work1d.d[128] += settings1d.kkt_reg;
  work1d.d_inv[128] = 1/work1d.d[128];
  work1d.L[127] = (work1d.KKT[256])*work1d.d_inv[128];
  work1d.v[129] = work1d.KKT[257];
  work1d.d[129] = work1d.v[129];
  if (work1d.d[129] < 0)
    work1d.d[129] = settings1d.kkt_reg;
  else
    work1d.d[129] += settings1d.kkt_reg;
  work1d.d_inv[129] = 1/work1d.d[129];
  work1d.L[128] = (work1d.KKT[258])*work1d.d_inv[129];
  work1d.v[130] = work1d.KKT[259];
  work1d.d[130] = work1d.v[130];
  if (work1d.d[130] < 0)
    work1d.d[130] = settings1d.kkt_reg;
  else
    work1d.d[130] += settings1d.kkt_reg;
  work1d.d_inv[130] = 1/work1d.d[130];
  work1d.L[129] = (work1d.KKT[260])*work1d.d_inv[130];
  work1d.v[131] = work1d.KKT[261];
  work1d.d[131] = work1d.v[131];
  if (work1d.d[131] < 0)
    work1d.d[131] = settings1d.kkt_reg;
  else
    work1d.d[131] += settings1d.kkt_reg;
  work1d.d_inv[131] = 1/work1d.d[131];
  work1d.L[130] = (work1d.KKT[262])*work1d.d_inv[131];
  work1d.v[132] = work1d.KKT[263];
  work1d.d[132] = work1d.v[132];
  if (work1d.d[132] < 0)
    work1d.d[132] = settings1d.kkt_reg;
  else
    work1d.d[132] += settings1d.kkt_reg;
  work1d.d_inv[132] = 1/work1d.d[132];
  work1d.L[131] = (work1d.KKT[264])*work1d.d_inv[132];
  work1d.v[133] = work1d.KKT[265];
  work1d.d[133] = work1d.v[133];
  if (work1d.d[133] < 0)
    work1d.d[133] = settings1d.kkt_reg;
  else
    work1d.d[133] += settings1d.kkt_reg;
  work1d.d_inv[133] = 1/work1d.d[133];
  work1d.L[132] = (work1d.KKT[266])*work1d.d_inv[133];
  work1d.v[134] = work1d.KKT[267];
  work1d.d[134] = work1d.v[134];
  if (work1d.d[134] < 0)
    work1d.d[134] = settings1d.kkt_reg;
  else
    work1d.d[134] += settings1d.kkt_reg;
  work1d.d_inv[134] = 1/work1d.d[134];
  work1d.L[133] = (work1d.KKT[268])*work1d.d_inv[134];
  work1d.v[135] = work1d.KKT[269];
  work1d.d[135] = work1d.v[135];
  if (work1d.d[135] < 0)
    work1d.d[135] = settings1d.kkt_reg;
  else
    work1d.d[135] += settings1d.kkt_reg;
  work1d.d_inv[135] = 1/work1d.d[135];
  work1d.L[134] = (work1d.KKT[270])*work1d.d_inv[135];
  work1d.v[136] = work1d.KKT[271];
  work1d.d[136] = work1d.v[136];
  if (work1d.d[136] < 0)
    work1d.d[136] = settings1d.kkt_reg;
  else
    work1d.d[136] += settings1d.kkt_reg;
  work1d.d_inv[136] = 1/work1d.d[136];
  work1d.L[135] = (work1d.KKT[272])*work1d.d_inv[136];
  work1d.v[137] = work1d.KKT[273];
  work1d.d[137] = work1d.v[137];
  if (work1d.d[137] < 0)
    work1d.d[137] = settings1d.kkt_reg;
  else
    work1d.d[137] += settings1d.kkt_reg;
  work1d.d_inv[137] = 1/work1d.d[137];
  work1d.L[136] = (work1d.KKT[274])*work1d.d_inv[137];
  work1d.v[138] = work1d.KKT[275];
  work1d.d[138] = work1d.v[138];
  if (work1d.d[138] < 0)
    work1d.d[138] = settings1d.kkt_reg;
  else
    work1d.d[138] += settings1d.kkt_reg;
  work1d.d_inv[138] = 1/work1d.d[138];
  work1d.L[137] = (work1d.KKT[276])*work1d.d_inv[138];
  work1d.v[139] = work1d.KKT[277];
  work1d.d[139] = work1d.v[139];
  if (work1d.d[139] < 0)
    work1d.d[139] = settings1d.kkt_reg;
  else
    work1d.d[139] += settings1d.kkt_reg;
  work1d.d_inv[139] = 1/work1d.d[139];
  work1d.L[138] = (work1d.KKT[278])*work1d.d_inv[139];
  work1d.v[140] = work1d.KKT[279];
  work1d.d[140] = work1d.v[140];
  if (work1d.d[140] < 0)
    work1d.d[140] = settings1d.kkt_reg;
  else
    work1d.d[140] += settings1d.kkt_reg;
  work1d.d_inv[140] = 1/work1d.d[140];
  work1d.L[139] = (work1d.KKT[280])*work1d.d_inv[140];
  work1d.v[141] = work1d.KKT[281];
  work1d.d[141] = work1d.v[141];
  if (work1d.d[141] < 0)
    work1d.d[141] = settings1d.kkt_reg;
  else
    work1d.d[141] += settings1d.kkt_reg;
  work1d.d_inv[141] = 1/work1d.d[141];
  work1d.L[140] = (work1d.KKT[282])*work1d.d_inv[141];
  work1d.v[142] = work1d.KKT[283];
  work1d.d[142] = work1d.v[142];
  if (work1d.d[142] < 0)
    work1d.d[142] = settings1d.kkt_reg;
  else
    work1d.d[142] += settings1d.kkt_reg;
  work1d.d_inv[142] = 1/work1d.d[142];
  work1d.L[141] = (work1d.KKT[284])*work1d.d_inv[142];
  work1d.v[143] = work1d.KKT[285];
  work1d.d[143] = work1d.v[143];
  if (work1d.d[143] < 0)
    work1d.d[143] = settings1d.kkt_reg;
  else
    work1d.d[143] += settings1d.kkt_reg;
  work1d.d_inv[143] = 1/work1d.d[143];
  work1d.L[142] = (work1d.KKT[286])*work1d.d_inv[143];
  work1d.v[144] = work1d.KKT[287];
  work1d.d[144] = work1d.v[144];
  if (work1d.d[144] < 0)
    work1d.d[144] = settings1d.kkt_reg;
  else
    work1d.d[144] += settings1d.kkt_reg;
  work1d.d_inv[144] = 1/work1d.d[144];
  work1d.L[143] = (work1d.KKT[288])*work1d.d_inv[144];
  work1d.v[145] = work1d.KKT[289];
  work1d.d[145] = work1d.v[145];
  if (work1d.d[145] < 0)
    work1d.d[145] = settings1d.kkt_reg;
  else
    work1d.d[145] += settings1d.kkt_reg;
  work1d.d_inv[145] = 1/work1d.d[145];
  work1d.L[144] = (work1d.KKT[290])*work1d.d_inv[145];
  work1d.v[146] = work1d.KKT[291];
  work1d.d[146] = work1d.v[146];
  if (work1d.d[146] < 0)
    work1d.d[146] = settings1d.kkt_reg;
  else
    work1d.d[146] += settings1d.kkt_reg;
  work1d.d_inv[146] = 1/work1d.d[146];
  work1d.L[145] = (work1d.KKT[292])*work1d.d_inv[146];
  work1d.v[147] = work1d.KKT[293];
  work1d.d[147] = work1d.v[147];
  if (work1d.d[147] < 0)
    work1d.d[147] = settings1d.kkt_reg;
  else
    work1d.d[147] += settings1d.kkt_reg;
  work1d.d_inv[147] = 1/work1d.d[147];
  work1d.L[146] = (work1d.KKT[294])*work1d.d_inv[147];
  work1d.v[148] = work1d.KKT[295];
  work1d.d[148] = work1d.v[148];
  if (work1d.d[148] < 0)
    work1d.d[148] = settings1d.kkt_reg;
  else
    work1d.d[148] += settings1d.kkt_reg;
  work1d.d_inv[148] = 1/work1d.d[148];
  work1d.L[147] = (work1d.KKT[296])*work1d.d_inv[148];
  work1d.v[149] = work1d.KKT[297];
  work1d.d[149] = work1d.v[149];
  if (work1d.d[149] < 0)
    work1d.d[149] = settings1d.kkt_reg;
  else
    work1d.d[149] += settings1d.kkt_reg;
  work1d.d_inv[149] = 1/work1d.d[149];
  work1d.L[148] = (work1d.KKT[298])*work1d.d_inv[149];
  work1d.v[150] = work1d.KKT[299];
  work1d.d[150] = work1d.v[150];
  if (work1d.d[150] < 0)
    work1d.d[150] = settings1d.kkt_reg;
  else
    work1d.d[150] += settings1d.kkt_reg;
  work1d.d_inv[150] = 1/work1d.d[150];
  work1d.L[149] = (work1d.KKT[300])*work1d.d_inv[150];
  work1d.v[151] = work1d.KKT[301];
  work1d.d[151] = work1d.v[151];
  if (work1d.d[151] < 0)
    work1d.d[151] = settings1d.kkt_reg;
  else
    work1d.d[151] += settings1d.kkt_reg;
  work1d.d_inv[151] = 1/work1d.d[151];
  work1d.L[150] = (work1d.KKT[302])*work1d.d_inv[151];
  work1d.v[152] = work1d.KKT[303];
  work1d.d[152] = work1d.v[152];
  if (work1d.d[152] < 0)
    work1d.d[152] = settings1d.kkt_reg;
  else
    work1d.d[152] += settings1d.kkt_reg;
  work1d.d_inv[152] = 1/work1d.d[152];
  work1d.L[151] = (work1d.KKT[304])*work1d.d_inv[152];
  work1d.v[153] = work1d.KKT[305];
  work1d.d[153] = work1d.v[153];
  if (work1d.d[153] < 0)
    work1d.d[153] = settings1d.kkt_reg;
  else
    work1d.d[153] += settings1d.kkt_reg;
  work1d.d_inv[153] = 1/work1d.d[153];
  work1d.L[152] = (work1d.KKT[306])*work1d.d_inv[153];
  work1d.v[154] = work1d.KKT[307];
  work1d.d[154] = work1d.v[154];
  if (work1d.d[154] < 0)
    work1d.d[154] = settings1d.kkt_reg;
  else
    work1d.d[154] += settings1d.kkt_reg;
  work1d.d_inv[154] = 1/work1d.d[154];
  work1d.L[153] = (work1d.KKT[308])*work1d.d_inv[154];
  work1d.v[155] = work1d.KKT[309];
  work1d.d[155] = work1d.v[155];
  if (work1d.d[155] < 0)
    work1d.d[155] = settings1d.kkt_reg;
  else
    work1d.d[155] += settings1d.kkt_reg;
  work1d.d_inv[155] = 1/work1d.d[155];
  work1d.L[154] = (work1d.KKT[310])*work1d.d_inv[155];
  work1d.v[156] = work1d.KKT[311];
  work1d.d[156] = work1d.v[156];
  if (work1d.d[156] < 0)
    work1d.d[156] = settings1d.kkt_reg;
  else
    work1d.d[156] += settings1d.kkt_reg;
  work1d.d_inv[156] = 1/work1d.d[156];
  work1d.L[155] = (work1d.KKT[312])*work1d.d_inv[156];
  work1d.v[157] = work1d.KKT[313];
  work1d.d[157] = work1d.v[157];
  if (work1d.d[157] < 0)
    work1d.d[157] = settings1d.kkt_reg;
  else
    work1d.d[157] += settings1d.kkt_reg;
  work1d.d_inv[157] = 1/work1d.d[157];
  work1d.L[156] = (work1d.KKT[314])*work1d.d_inv[157];
  work1d.v[158] = work1d.KKT[315];
  work1d.d[158] = work1d.v[158];
  if (work1d.d[158] < 0)
    work1d.d[158] = settings1d.kkt_reg;
  else
    work1d.d[158] += settings1d.kkt_reg;
  work1d.d_inv[158] = 1/work1d.d[158];
  work1d.L[157] = (work1d.KKT[316])*work1d.d_inv[158];
  work1d.v[159] = work1d.KKT[317];
  work1d.d[159] = work1d.v[159];
  if (work1d.d[159] < 0)
    work1d.d[159] = settings1d.kkt_reg;
  else
    work1d.d[159] += settings1d.kkt_reg;
  work1d.d_inv[159] = 1/work1d.d[159];
  work1d.L[158] = (work1d.KKT[318])*work1d.d_inv[159];
  work1d.v[160] = work1d.KKT[319];
  work1d.d[160] = work1d.v[160];
  if (work1d.d[160] < 0)
    work1d.d[160] = settings1d.kkt_reg;
  else
    work1d.d[160] += settings1d.kkt_reg;
  work1d.d_inv[160] = 1/work1d.d[160];
  work1d.L[159] = (work1d.KKT[320])*work1d.d_inv[160];
  work1d.v[1] = work1d.L[0]*work1d.d[1];
  work1d.v[161] = work1d.KKT[321]-work1d.L[0]*work1d.v[1];
  work1d.d[161] = work1d.v[161];
  if (work1d.d[161] > 0)
    work1d.d[161] = -settings1d.kkt_reg;
  else
    work1d.d[161] -= settings1d.kkt_reg;
  work1d.d_inv[161] = 1/work1d.d[161];
  work1d.L[215] = (work1d.KKT[322])*work1d.d_inv[161];
  work1d.v[2] = work1d.L[1]*work1d.d[2];
  work1d.v[162] = work1d.KKT[323]-work1d.L[1]*work1d.v[2];
  work1d.d[162] = work1d.v[162];
  if (work1d.d[162] > 0)
    work1d.d[162] = -settings1d.kkt_reg;
  else
    work1d.d[162] -= settings1d.kkt_reg;
  work1d.d_inv[162] = 1/work1d.d[162];
  work1d.L[229] = (work1d.KKT[324])*work1d.d_inv[162];
  work1d.v[3] = work1d.L[2]*work1d.d[3];
  work1d.v[163] = work1d.KKT[325]-work1d.L[2]*work1d.v[3];
  work1d.d[163] = work1d.v[163];
  if (work1d.d[163] > 0)
    work1d.d[163] = -settings1d.kkt_reg;
  else
    work1d.d[163] -= settings1d.kkt_reg;
  work1d.d_inv[163] = 1/work1d.d[163];
  work1d.L[247] = (work1d.KKT[326])*work1d.d_inv[163];
  work1d.v[4] = work1d.L[3]*work1d.d[4];
  work1d.v[164] = work1d.KKT[327]-work1d.L[3]*work1d.v[4];
  work1d.d[164] = work1d.v[164];
  if (work1d.d[164] > 0)
    work1d.d[164] = -settings1d.kkt_reg;
  else
    work1d.d[164] -= settings1d.kkt_reg;
  work1d.d_inv[164] = 1/work1d.d[164];
  work1d.L[267] = (work1d.KKT[328])*work1d.d_inv[164];
  work1d.v[5] = work1d.L[4]*work1d.d[5];
  work1d.v[165] = work1d.KKT[329]-work1d.L[4]*work1d.v[5];
  work1d.d[165] = work1d.v[165];
  if (work1d.d[165] > 0)
    work1d.d[165] = -settings1d.kkt_reg;
  else
    work1d.d[165] -= settings1d.kkt_reg;
  work1d.d_inv[165] = 1/work1d.d[165];
  work1d.L[287] = (work1d.KKT[330])*work1d.d_inv[165];
  work1d.v[6] = work1d.L[5]*work1d.d[6];
  work1d.v[166] = work1d.KKT[331]-work1d.L[5]*work1d.v[6];
  work1d.d[166] = work1d.v[166];
  if (work1d.d[166] > 0)
    work1d.d[166] = -settings1d.kkt_reg;
  else
    work1d.d[166] -= settings1d.kkt_reg;
  work1d.d_inv[166] = 1/work1d.d[166];
  work1d.L[307] = (work1d.KKT[332])*work1d.d_inv[166];
  work1d.v[7] = work1d.L[6]*work1d.d[7];
  work1d.v[167] = work1d.KKT[333]-work1d.L[6]*work1d.v[7];
  work1d.d[167] = work1d.v[167];
  if (work1d.d[167] > 0)
    work1d.d[167] = -settings1d.kkt_reg;
  else
    work1d.d[167] -= settings1d.kkt_reg;
  work1d.d_inv[167] = 1/work1d.d[167];
  work1d.L[327] = (work1d.KKT[334])*work1d.d_inv[167];
  work1d.v[8] = work1d.L[7]*work1d.d[8];
  work1d.v[168] = work1d.KKT[335]-work1d.L[7]*work1d.v[8];
  work1d.d[168] = work1d.v[168];
  if (work1d.d[168] > 0)
    work1d.d[168] = -settings1d.kkt_reg;
  else
    work1d.d[168] -= settings1d.kkt_reg;
  work1d.d_inv[168] = 1/work1d.d[168];
  work1d.L[347] = (work1d.KKT[336])*work1d.d_inv[168];
  work1d.v[9] = work1d.L[8]*work1d.d[9];
  work1d.v[169] = work1d.KKT[337]-work1d.L[8]*work1d.v[9];
  work1d.d[169] = work1d.v[169];
  if (work1d.d[169] > 0)
    work1d.d[169] = -settings1d.kkt_reg;
  else
    work1d.d[169] -= settings1d.kkt_reg;
  work1d.d_inv[169] = 1/work1d.d[169];
  work1d.L[367] = (work1d.KKT[338])*work1d.d_inv[169];
  work1d.v[10] = work1d.L[9]*work1d.d[10];
  work1d.v[170] = work1d.KKT[339]-work1d.L[9]*work1d.v[10];
  work1d.d[170] = work1d.v[170];
  if (work1d.d[170] > 0)
    work1d.d[170] = -settings1d.kkt_reg;
  else
    work1d.d[170] -= settings1d.kkt_reg;
  work1d.d_inv[170] = 1/work1d.d[170];
  work1d.L[387] = (work1d.KKT[340])*work1d.d_inv[170];
  work1d.v[11] = work1d.L[10]*work1d.d[11];
  work1d.v[171] = work1d.KKT[341]-work1d.L[10]*work1d.v[11];
  work1d.d[171] = work1d.v[171];
  if (work1d.d[171] > 0)
    work1d.d[171] = -settings1d.kkt_reg;
  else
    work1d.d[171] -= settings1d.kkt_reg;
  work1d.d_inv[171] = 1/work1d.d[171];
  work1d.L[407] = (work1d.KKT[342])*work1d.d_inv[171];
  work1d.v[12] = work1d.L[11]*work1d.d[12];
  work1d.v[172] = work1d.KKT[343]-work1d.L[11]*work1d.v[12];
  work1d.d[172] = work1d.v[172];
  if (work1d.d[172] > 0)
    work1d.d[172] = -settings1d.kkt_reg;
  else
    work1d.d[172] -= settings1d.kkt_reg;
  work1d.d_inv[172] = 1/work1d.d[172];
  work1d.L[427] = (work1d.KKT[344])*work1d.d_inv[172];
  work1d.v[13] = work1d.L[12]*work1d.d[13];
  work1d.v[173] = work1d.KKT[345]-work1d.L[12]*work1d.v[13];
  work1d.d[173] = work1d.v[173];
  if (work1d.d[173] > 0)
    work1d.d[173] = -settings1d.kkt_reg;
  else
    work1d.d[173] -= settings1d.kkt_reg;
  work1d.d_inv[173] = 1/work1d.d[173];
  work1d.L[447] = (work1d.KKT[346])*work1d.d_inv[173];
  work1d.v[14] = work1d.L[13]*work1d.d[14];
  work1d.v[174] = work1d.KKT[347]-work1d.L[13]*work1d.v[14];
  work1d.d[174] = work1d.v[174];
  if (work1d.d[174] > 0)
    work1d.d[174] = -settings1d.kkt_reg;
  else
    work1d.d[174] -= settings1d.kkt_reg;
  work1d.d_inv[174] = 1/work1d.d[174];
  work1d.L[467] = (work1d.KKT[348])*work1d.d_inv[174];
  work1d.v[15] = work1d.L[14]*work1d.d[15];
  work1d.v[175] = work1d.KKT[349]-work1d.L[14]*work1d.v[15];
  work1d.d[175] = work1d.v[175];
  if (work1d.d[175] > 0)
    work1d.d[175] = -settings1d.kkt_reg;
  else
    work1d.d[175] -= settings1d.kkt_reg;
  work1d.d_inv[175] = 1/work1d.d[175];
  work1d.L[487] = (work1d.KKT[350])*work1d.d_inv[175];
  work1d.v[16] = work1d.L[15]*work1d.d[16];
  work1d.v[176] = work1d.KKT[351]-work1d.L[15]*work1d.v[16];
  work1d.d[176] = work1d.v[176];
  if (work1d.d[176] > 0)
    work1d.d[176] = -settings1d.kkt_reg;
  else
    work1d.d[176] -= settings1d.kkt_reg;
  work1d.d_inv[176] = 1/work1d.d[176];
  work1d.L[507] = (work1d.KKT[352])*work1d.d_inv[176];
  work1d.v[17] = work1d.L[16]*work1d.d[17];
  work1d.v[177] = work1d.KKT[353]-work1d.L[16]*work1d.v[17];
  work1d.d[177] = work1d.v[177];
  if (work1d.d[177] > 0)
    work1d.d[177] = -settings1d.kkt_reg;
  else
    work1d.d[177] -= settings1d.kkt_reg;
  work1d.d_inv[177] = 1/work1d.d[177];
  work1d.L[527] = (work1d.KKT[354])*work1d.d_inv[177];
  work1d.v[18] = work1d.L[17]*work1d.d[18];
  work1d.v[178] = work1d.KKT[355]-work1d.L[17]*work1d.v[18];
  work1d.d[178] = work1d.v[178];
  if (work1d.d[178] > 0)
    work1d.d[178] = -settings1d.kkt_reg;
  else
    work1d.d[178] -= settings1d.kkt_reg;
  work1d.d_inv[178] = 1/work1d.d[178];
  work1d.L[547] = (work1d.KKT[356])*work1d.d_inv[178];
  work1d.v[19] = work1d.L[18]*work1d.d[19];
  work1d.v[179] = work1d.KKT[357]-work1d.L[18]*work1d.v[19];
  work1d.d[179] = work1d.v[179];
  if (work1d.d[179] > 0)
    work1d.d[179] = -settings1d.kkt_reg;
  else
    work1d.d[179] -= settings1d.kkt_reg;
  work1d.d_inv[179] = 1/work1d.d[179];
  work1d.L[567] = (work1d.KKT[358])*work1d.d_inv[179];
  work1d.v[20] = work1d.L[19]*work1d.d[20];
  work1d.v[180] = work1d.KKT[359]-work1d.L[19]*work1d.v[20];
  work1d.d[180] = work1d.v[180];
  if (work1d.d[180] > 0)
    work1d.d[180] = -settings1d.kkt_reg;
  else
    work1d.d[180] -= settings1d.kkt_reg;
  work1d.d_inv[180] = 1/work1d.d[180];
  work1d.L[587] = (work1d.KKT[360])*work1d.d_inv[180];
  work1d.v[21] = work1d.L[20]*work1d.d[21];
  work1d.v[181] = work1d.KKT[361]-work1d.L[20]*work1d.v[21];
  work1d.d[181] = work1d.v[181];
  if (work1d.d[181] > 0)
    work1d.d[181] = -settings1d.kkt_reg;
  else
    work1d.d[181] -= settings1d.kkt_reg;
  work1d.d_inv[181] = 1/work1d.d[181];
  work1d.L[607] = (work1d.KKT[362])*work1d.d_inv[181];
  work1d.v[22] = work1d.L[21]*work1d.d[22];
  work1d.v[182] = work1d.KKT[363]-work1d.L[21]*work1d.v[22];
  work1d.d[182] = work1d.v[182];
  if (work1d.d[182] > 0)
    work1d.d[182] = -settings1d.kkt_reg;
  else
    work1d.d[182] -= settings1d.kkt_reg;
  work1d.d_inv[182] = 1/work1d.d[182];
  work1d.L[627] = (work1d.KKT[364])*work1d.d_inv[182];
  work1d.v[23] = work1d.L[22]*work1d.d[23];
  work1d.v[183] = work1d.KKT[365]-work1d.L[22]*work1d.v[23];
  work1d.d[183] = work1d.v[183];
  if (work1d.d[183] > 0)
    work1d.d[183] = -settings1d.kkt_reg;
  else
    work1d.d[183] -= settings1d.kkt_reg;
  work1d.d_inv[183] = 1/work1d.d[183];
  work1d.L[647] = (work1d.KKT[366])*work1d.d_inv[183];
  work1d.v[24] = work1d.L[23]*work1d.d[24];
  work1d.v[184] = work1d.KKT[367]-work1d.L[23]*work1d.v[24];
  work1d.d[184] = work1d.v[184];
  if (work1d.d[184] > 0)
    work1d.d[184] = -settings1d.kkt_reg;
  else
    work1d.d[184] -= settings1d.kkt_reg;
  work1d.d_inv[184] = 1/work1d.d[184];
  work1d.L[667] = (work1d.KKT[368])*work1d.d_inv[184];
  work1d.v[25] = work1d.L[24]*work1d.d[25];
  work1d.v[185] = work1d.KKT[369]-work1d.L[24]*work1d.v[25];
  work1d.d[185] = work1d.v[185];
  if (work1d.d[185] > 0)
    work1d.d[185] = -settings1d.kkt_reg;
  else
    work1d.d[185] -= settings1d.kkt_reg;
  work1d.d_inv[185] = 1/work1d.d[185];
  work1d.L[687] = (work1d.KKT[370])*work1d.d_inv[185];
  work1d.v[26] = work1d.L[25]*work1d.d[26];
  work1d.v[186] = work1d.KKT[371]-work1d.L[25]*work1d.v[26];
  work1d.d[186] = work1d.v[186];
  if (work1d.d[186] > 0)
    work1d.d[186] = -settings1d.kkt_reg;
  else
    work1d.d[186] -= settings1d.kkt_reg;
  work1d.d_inv[186] = 1/work1d.d[186];
  work1d.L[707] = (work1d.KKT[372])*work1d.d_inv[186];
  work1d.v[27] = work1d.L[26]*work1d.d[27];
  work1d.v[187] = work1d.KKT[373]-work1d.L[26]*work1d.v[27];
  work1d.d[187] = work1d.v[187];
  if (work1d.d[187] > 0)
    work1d.d[187] = -settings1d.kkt_reg;
  else
    work1d.d[187] -= settings1d.kkt_reg;
  work1d.d_inv[187] = 1/work1d.d[187];
  work1d.L[727] = (work1d.KKT[374])*work1d.d_inv[187];
  work1d.v[28] = work1d.L[27]*work1d.d[28];
  work1d.v[188] = work1d.KKT[375]-work1d.L[27]*work1d.v[28];
  work1d.d[188] = work1d.v[188];
  if (work1d.d[188] > 0)
    work1d.d[188] = -settings1d.kkt_reg;
  else
    work1d.d[188] -= settings1d.kkt_reg;
  work1d.d_inv[188] = 1/work1d.d[188];
  work1d.L[747] = (work1d.KKT[376])*work1d.d_inv[188];
  work1d.v[29] = work1d.L[28]*work1d.d[29];
  work1d.v[189] = work1d.KKT[377]-work1d.L[28]*work1d.v[29];
  work1d.d[189] = work1d.v[189];
  if (work1d.d[189] > 0)
    work1d.d[189] = -settings1d.kkt_reg;
  else
    work1d.d[189] -= settings1d.kkt_reg;
  work1d.d_inv[189] = 1/work1d.d[189];
  work1d.L[767] = (work1d.KKT[378])*work1d.d_inv[189];
  work1d.v[30] = work1d.L[29]*work1d.d[30];
  work1d.v[190] = work1d.KKT[379]-work1d.L[29]*work1d.v[30];
  work1d.d[190] = work1d.v[190];
  if (work1d.d[190] > 0)
    work1d.d[190] = -settings1d.kkt_reg;
  else
    work1d.d[190] -= settings1d.kkt_reg;
  work1d.d_inv[190] = 1/work1d.d[190];
  work1d.L[787] = (work1d.KKT[380])*work1d.d_inv[190];
  work1d.v[31] = work1d.L[30]*work1d.d[31];
  work1d.v[191] = work1d.KKT[381]-work1d.L[30]*work1d.v[31];
  work1d.d[191] = work1d.v[191];
  if (work1d.d[191] > 0)
    work1d.d[191] = -settings1d.kkt_reg;
  else
    work1d.d[191] -= settings1d.kkt_reg;
  work1d.d_inv[191] = 1/work1d.d[191];
  work1d.L[807] = (work1d.KKT[382])*work1d.d_inv[191];
  work1d.v[32] = work1d.L[31]*work1d.d[32];
  work1d.v[192] = work1d.KKT[383]-work1d.L[31]*work1d.v[32];
  work1d.d[192] = work1d.v[192];
  if (work1d.d[192] > 0)
    work1d.d[192] = -settings1d.kkt_reg;
  else
    work1d.d[192] -= settings1d.kkt_reg;
  work1d.d_inv[192] = 1/work1d.d[192];
  work1d.L[827] = (work1d.KKT[384])*work1d.d_inv[192];
  work1d.v[33] = work1d.L[32]*work1d.d[33];
  work1d.v[193] = work1d.KKT[385]-work1d.L[32]*work1d.v[33];
  work1d.d[193] = work1d.v[193];
  if (work1d.d[193] > 0)
    work1d.d[193] = -settings1d.kkt_reg;
  else
    work1d.d[193] -= settings1d.kkt_reg;
  work1d.d_inv[193] = 1/work1d.d[193];
  work1d.L[847] = (work1d.KKT[386])*work1d.d_inv[193];
  work1d.v[34] = work1d.L[33]*work1d.d[34];
  work1d.v[194] = work1d.KKT[387]-work1d.L[33]*work1d.v[34];
  work1d.d[194] = work1d.v[194];
  if (work1d.d[194] > 0)
    work1d.d[194] = -settings1d.kkt_reg;
  else
    work1d.d[194] -= settings1d.kkt_reg;
  work1d.d_inv[194] = 1/work1d.d[194];
  work1d.L[867] = (work1d.KKT[388])*work1d.d_inv[194];
  work1d.v[35] = work1d.L[34]*work1d.d[35];
  work1d.v[195] = work1d.KKT[389]-work1d.L[34]*work1d.v[35];
  work1d.d[195] = work1d.v[195];
  if (work1d.d[195] > 0)
    work1d.d[195] = -settings1d.kkt_reg;
  else
    work1d.d[195] -= settings1d.kkt_reg;
  work1d.d_inv[195] = 1/work1d.d[195];
  work1d.L[887] = (work1d.KKT[390])*work1d.d_inv[195];
  work1d.v[36] = work1d.L[35]*work1d.d[36];
  work1d.v[196] = work1d.KKT[391]-work1d.L[35]*work1d.v[36];
  work1d.d[196] = work1d.v[196];
  if (work1d.d[196] > 0)
    work1d.d[196] = -settings1d.kkt_reg;
  else
    work1d.d[196] -= settings1d.kkt_reg;
  work1d.d_inv[196] = 1/work1d.d[196];
  work1d.L[907] = (work1d.KKT[392])*work1d.d_inv[196];
  work1d.v[37] = work1d.L[36]*work1d.d[37];
  work1d.v[197] = work1d.KKT[393]-work1d.L[36]*work1d.v[37];
  work1d.d[197] = work1d.v[197];
  if (work1d.d[197] > 0)
    work1d.d[197] = -settings1d.kkt_reg;
  else
    work1d.d[197] -= settings1d.kkt_reg;
  work1d.d_inv[197] = 1/work1d.d[197];
  work1d.L[927] = (work1d.KKT[394])*work1d.d_inv[197];
  work1d.v[38] = work1d.L[37]*work1d.d[38];
  work1d.v[198] = work1d.KKT[395]-work1d.L[37]*work1d.v[38];
  work1d.d[198] = work1d.v[198];
  if (work1d.d[198] > 0)
    work1d.d[198] = -settings1d.kkt_reg;
  else
    work1d.d[198] -= settings1d.kkt_reg;
  work1d.d_inv[198] = 1/work1d.d[198];
  work1d.L[951] = (work1d.KKT[396])*work1d.d_inv[198];
  work1d.v[39] = work1d.L[38]*work1d.d[39];
  work1d.v[199] = work1d.KKT[397]-work1d.L[38]*work1d.v[39];
  work1d.d[199] = work1d.v[199];
  if (work1d.d[199] > 0)
    work1d.d[199] = -settings1d.kkt_reg;
  else
    work1d.d[199] -= settings1d.kkt_reg;
  work1d.d_inv[199] = 1/work1d.d[199];
  work1d.L[967] = (work1d.KKT[398])*work1d.d_inv[199];
  work1d.v[40] = work1d.L[39]*work1d.d[40];
  work1d.v[200] = work1d.KKT[399]-work1d.L[39]*work1d.v[40];
  work1d.d[200] = work1d.v[200];
  if (work1d.d[200] > 0)
    work1d.d[200] = -settings1d.kkt_reg;
  else
    work1d.d[200] -= settings1d.kkt_reg;
  work1d.d_inv[200] = 1/work1d.d[200];
  work1d.L[166] = (work1d.KKT[400])*work1d.d_inv[200];
  work1d.v[41] = work1d.L[40]*work1d.d[41];
  work1d.v[201] = work1d.KKT[401]-work1d.L[40]*work1d.v[41];
  work1d.d[201] = work1d.v[201];
  if (work1d.d[201] > 0)
    work1d.d[201] = -settings1d.kkt_reg;
  else
    work1d.d[201] -= settings1d.kkt_reg;
  work1d.d_inv[201] = 1/work1d.d[201];
  work1d.L[219] = (work1d.KKT[402])*work1d.d_inv[201];
  work1d.v[42] = work1d.L[41]*work1d.d[42];
  work1d.v[202] = work1d.KKT[403]-work1d.L[41]*work1d.v[42];
  work1d.d[202] = work1d.v[202];
  if (work1d.d[202] > 0)
    work1d.d[202] = -settings1d.kkt_reg;
  else
    work1d.d[202] -= settings1d.kkt_reg;
  work1d.d_inv[202] = 1/work1d.d[202];
  work1d.L[232] = (work1d.KKT[404])*work1d.d_inv[202];
  work1d.v[43] = work1d.L[42]*work1d.d[43];
  work1d.v[203] = work1d.KKT[405]-work1d.L[42]*work1d.v[43];
  work1d.d[203] = work1d.v[203];
  if (work1d.d[203] > 0)
    work1d.d[203] = -settings1d.kkt_reg;
  else
    work1d.d[203] -= settings1d.kkt_reg;
  work1d.d_inv[203] = 1/work1d.d[203];
  work1d.L[250] = (work1d.KKT[406])*work1d.d_inv[203];
  work1d.v[44] = work1d.L[43]*work1d.d[44];
  work1d.v[204] = work1d.KKT[407]-work1d.L[43]*work1d.v[44];
  work1d.d[204] = work1d.v[204];
  if (work1d.d[204] > 0)
    work1d.d[204] = -settings1d.kkt_reg;
  else
    work1d.d[204] -= settings1d.kkt_reg;
  work1d.d_inv[204] = 1/work1d.d[204];
  work1d.L[270] = (work1d.KKT[408])*work1d.d_inv[204];
  work1d.v[45] = work1d.L[44]*work1d.d[45];
  work1d.v[205] = work1d.KKT[409]-work1d.L[44]*work1d.v[45];
  work1d.d[205] = work1d.v[205];
  if (work1d.d[205] > 0)
    work1d.d[205] = -settings1d.kkt_reg;
  else
    work1d.d[205] -= settings1d.kkt_reg;
  work1d.d_inv[205] = 1/work1d.d[205];
  work1d.L[290] = (work1d.KKT[410])*work1d.d_inv[205];
  work1d.v[46] = work1d.L[45]*work1d.d[46];
  work1d.v[206] = work1d.KKT[411]-work1d.L[45]*work1d.v[46];
  work1d.d[206] = work1d.v[206];
  if (work1d.d[206] > 0)
    work1d.d[206] = -settings1d.kkt_reg;
  else
    work1d.d[206] -= settings1d.kkt_reg;
  work1d.d_inv[206] = 1/work1d.d[206];
  work1d.L[310] = (work1d.KKT[412])*work1d.d_inv[206];
  work1d.v[47] = work1d.L[46]*work1d.d[47];
  work1d.v[207] = work1d.KKT[413]-work1d.L[46]*work1d.v[47];
  work1d.d[207] = work1d.v[207];
  if (work1d.d[207] > 0)
    work1d.d[207] = -settings1d.kkt_reg;
  else
    work1d.d[207] -= settings1d.kkt_reg;
  work1d.d_inv[207] = 1/work1d.d[207];
  work1d.L[330] = (work1d.KKT[414])*work1d.d_inv[207];
  work1d.v[48] = work1d.L[47]*work1d.d[48];
  work1d.v[208] = work1d.KKT[415]-work1d.L[47]*work1d.v[48];
  work1d.d[208] = work1d.v[208];
  if (work1d.d[208] > 0)
    work1d.d[208] = -settings1d.kkt_reg;
  else
    work1d.d[208] -= settings1d.kkt_reg;
  work1d.d_inv[208] = 1/work1d.d[208];
  work1d.L[350] = (work1d.KKT[416])*work1d.d_inv[208];
  work1d.v[49] = work1d.L[48]*work1d.d[49];
  work1d.v[209] = work1d.KKT[417]-work1d.L[48]*work1d.v[49];
  work1d.d[209] = work1d.v[209];
  if (work1d.d[209] > 0)
    work1d.d[209] = -settings1d.kkt_reg;
  else
    work1d.d[209] -= settings1d.kkt_reg;
  work1d.d_inv[209] = 1/work1d.d[209];
  work1d.L[370] = (work1d.KKT[418])*work1d.d_inv[209];
  work1d.v[50] = work1d.L[49]*work1d.d[50];
  work1d.v[210] = work1d.KKT[419]-work1d.L[49]*work1d.v[50];
  work1d.d[210] = work1d.v[210];
  if (work1d.d[210] > 0)
    work1d.d[210] = -settings1d.kkt_reg;
  else
    work1d.d[210] -= settings1d.kkt_reg;
  work1d.d_inv[210] = 1/work1d.d[210];
  work1d.L[390] = (work1d.KKT[420])*work1d.d_inv[210];
  work1d.v[51] = work1d.L[50]*work1d.d[51];
  work1d.v[211] = work1d.KKT[421]-work1d.L[50]*work1d.v[51];
  work1d.d[211] = work1d.v[211];
  if (work1d.d[211] > 0)
    work1d.d[211] = -settings1d.kkt_reg;
  else
    work1d.d[211] -= settings1d.kkt_reg;
  work1d.d_inv[211] = 1/work1d.d[211];
  work1d.L[410] = (work1d.KKT[422])*work1d.d_inv[211];
  work1d.v[52] = work1d.L[51]*work1d.d[52];
  work1d.v[212] = work1d.KKT[423]-work1d.L[51]*work1d.v[52];
  work1d.d[212] = work1d.v[212];
  if (work1d.d[212] > 0)
    work1d.d[212] = -settings1d.kkt_reg;
  else
    work1d.d[212] -= settings1d.kkt_reg;
  work1d.d_inv[212] = 1/work1d.d[212];
  work1d.L[430] = (work1d.KKT[424])*work1d.d_inv[212];
  work1d.v[53] = work1d.L[52]*work1d.d[53];
  work1d.v[213] = work1d.KKT[425]-work1d.L[52]*work1d.v[53];
  work1d.d[213] = work1d.v[213];
  if (work1d.d[213] > 0)
    work1d.d[213] = -settings1d.kkt_reg;
  else
    work1d.d[213] -= settings1d.kkt_reg;
  work1d.d_inv[213] = 1/work1d.d[213];
  work1d.L[450] = (work1d.KKT[426])*work1d.d_inv[213];
  work1d.v[54] = work1d.L[53]*work1d.d[54];
  work1d.v[214] = work1d.KKT[427]-work1d.L[53]*work1d.v[54];
  work1d.d[214] = work1d.v[214];
  if (work1d.d[214] > 0)
    work1d.d[214] = -settings1d.kkt_reg;
  else
    work1d.d[214] -= settings1d.kkt_reg;
  work1d.d_inv[214] = 1/work1d.d[214];
  work1d.L[470] = (work1d.KKT[428])*work1d.d_inv[214];
  work1d.v[55] = work1d.L[54]*work1d.d[55];
  work1d.v[215] = work1d.KKT[429]-work1d.L[54]*work1d.v[55];
  work1d.d[215] = work1d.v[215];
  if (work1d.d[215] > 0)
    work1d.d[215] = -settings1d.kkt_reg;
  else
    work1d.d[215] -= settings1d.kkt_reg;
  work1d.d_inv[215] = 1/work1d.d[215];
  work1d.L[490] = (work1d.KKT[430])*work1d.d_inv[215];
  work1d.v[56] = work1d.L[55]*work1d.d[56];
  work1d.v[216] = work1d.KKT[431]-work1d.L[55]*work1d.v[56];
  work1d.d[216] = work1d.v[216];
  if (work1d.d[216] > 0)
    work1d.d[216] = -settings1d.kkt_reg;
  else
    work1d.d[216] -= settings1d.kkt_reg;
  work1d.d_inv[216] = 1/work1d.d[216];
  work1d.L[510] = (work1d.KKT[432])*work1d.d_inv[216];
  work1d.v[57] = work1d.L[56]*work1d.d[57];
  work1d.v[217] = work1d.KKT[433]-work1d.L[56]*work1d.v[57];
  work1d.d[217] = work1d.v[217];
  if (work1d.d[217] > 0)
    work1d.d[217] = -settings1d.kkt_reg;
  else
    work1d.d[217] -= settings1d.kkt_reg;
  work1d.d_inv[217] = 1/work1d.d[217];
  work1d.L[530] = (work1d.KKT[434])*work1d.d_inv[217];
  work1d.v[58] = work1d.L[57]*work1d.d[58];
  work1d.v[218] = work1d.KKT[435]-work1d.L[57]*work1d.v[58];
  work1d.d[218] = work1d.v[218];
  if (work1d.d[218] > 0)
    work1d.d[218] = -settings1d.kkt_reg;
  else
    work1d.d[218] -= settings1d.kkt_reg;
  work1d.d_inv[218] = 1/work1d.d[218];
  work1d.L[550] = (work1d.KKT[436])*work1d.d_inv[218];
  work1d.v[59] = work1d.L[58]*work1d.d[59];
  work1d.v[219] = work1d.KKT[437]-work1d.L[58]*work1d.v[59];
  work1d.d[219] = work1d.v[219];
  if (work1d.d[219] > 0)
    work1d.d[219] = -settings1d.kkt_reg;
  else
    work1d.d[219] -= settings1d.kkt_reg;
  work1d.d_inv[219] = 1/work1d.d[219];
  work1d.L[570] = (work1d.KKT[438])*work1d.d_inv[219];
  work1d.v[60] = work1d.L[59]*work1d.d[60];
  work1d.v[220] = work1d.KKT[439]-work1d.L[59]*work1d.v[60];
  work1d.d[220] = work1d.v[220];
  if (work1d.d[220] > 0)
    work1d.d[220] = -settings1d.kkt_reg;
  else
    work1d.d[220] -= settings1d.kkt_reg;
  work1d.d_inv[220] = 1/work1d.d[220];
  work1d.L[590] = (work1d.KKT[440])*work1d.d_inv[220];
  work1d.v[61] = work1d.L[60]*work1d.d[61];
  work1d.v[221] = work1d.KKT[441]-work1d.L[60]*work1d.v[61];
  work1d.d[221] = work1d.v[221];
  if (work1d.d[221] > 0)
    work1d.d[221] = -settings1d.kkt_reg;
  else
    work1d.d[221] -= settings1d.kkt_reg;
  work1d.d_inv[221] = 1/work1d.d[221];
  work1d.L[610] = (work1d.KKT[442])*work1d.d_inv[221];
  work1d.v[62] = work1d.L[61]*work1d.d[62];
  work1d.v[222] = work1d.KKT[443]-work1d.L[61]*work1d.v[62];
  work1d.d[222] = work1d.v[222];
  if (work1d.d[222] > 0)
    work1d.d[222] = -settings1d.kkt_reg;
  else
    work1d.d[222] -= settings1d.kkt_reg;
  work1d.d_inv[222] = 1/work1d.d[222];
  work1d.L[630] = (work1d.KKT[444])*work1d.d_inv[222];
  work1d.v[63] = work1d.L[62]*work1d.d[63];
  work1d.v[223] = work1d.KKT[445]-work1d.L[62]*work1d.v[63];
  work1d.d[223] = work1d.v[223];
  if (work1d.d[223] > 0)
    work1d.d[223] = -settings1d.kkt_reg;
  else
    work1d.d[223] -= settings1d.kkt_reg;
  work1d.d_inv[223] = 1/work1d.d[223];
  work1d.L[650] = (work1d.KKT[446])*work1d.d_inv[223];
  work1d.v[64] = work1d.L[63]*work1d.d[64];
  work1d.v[224] = work1d.KKT[447]-work1d.L[63]*work1d.v[64];
  work1d.d[224] = work1d.v[224];
  if (work1d.d[224] > 0)
    work1d.d[224] = -settings1d.kkt_reg;
  else
    work1d.d[224] -= settings1d.kkt_reg;
  work1d.d_inv[224] = 1/work1d.d[224];
  work1d.L[670] = (work1d.KKT[448])*work1d.d_inv[224];
  work1d.v[65] = work1d.L[64]*work1d.d[65];
  work1d.v[225] = work1d.KKT[449]-work1d.L[64]*work1d.v[65];
  work1d.d[225] = work1d.v[225];
  if (work1d.d[225] > 0)
    work1d.d[225] = -settings1d.kkt_reg;
  else
    work1d.d[225] -= settings1d.kkt_reg;
  work1d.d_inv[225] = 1/work1d.d[225];
  work1d.L[690] = (work1d.KKT[450])*work1d.d_inv[225];
  work1d.v[66] = work1d.L[65]*work1d.d[66];
  work1d.v[226] = work1d.KKT[451]-work1d.L[65]*work1d.v[66];
  work1d.d[226] = work1d.v[226];
  if (work1d.d[226] > 0)
    work1d.d[226] = -settings1d.kkt_reg;
  else
    work1d.d[226] -= settings1d.kkt_reg;
  work1d.d_inv[226] = 1/work1d.d[226];
  work1d.L[710] = (work1d.KKT[452])*work1d.d_inv[226];
  work1d.v[67] = work1d.L[66]*work1d.d[67];
  work1d.v[227] = work1d.KKT[453]-work1d.L[66]*work1d.v[67];
  work1d.d[227] = work1d.v[227];
  if (work1d.d[227] > 0)
    work1d.d[227] = -settings1d.kkt_reg;
  else
    work1d.d[227] -= settings1d.kkt_reg;
  work1d.d_inv[227] = 1/work1d.d[227];
  work1d.L[730] = (work1d.KKT[454])*work1d.d_inv[227];
  work1d.v[68] = work1d.L[67]*work1d.d[68];
  work1d.v[228] = work1d.KKT[455]-work1d.L[67]*work1d.v[68];
  work1d.d[228] = work1d.v[228];
  if (work1d.d[228] > 0)
    work1d.d[228] = -settings1d.kkt_reg;
  else
    work1d.d[228] -= settings1d.kkt_reg;
  work1d.d_inv[228] = 1/work1d.d[228];
  work1d.L[750] = (work1d.KKT[456])*work1d.d_inv[228];
  work1d.v[69] = work1d.L[68]*work1d.d[69];
  work1d.v[229] = work1d.KKT[457]-work1d.L[68]*work1d.v[69];
  work1d.d[229] = work1d.v[229];
  if (work1d.d[229] > 0)
    work1d.d[229] = -settings1d.kkt_reg;
  else
    work1d.d[229] -= settings1d.kkt_reg;
  work1d.d_inv[229] = 1/work1d.d[229];
  work1d.L[770] = (work1d.KKT[458])*work1d.d_inv[229];
  work1d.v[70] = work1d.L[69]*work1d.d[70];
  work1d.v[230] = work1d.KKT[459]-work1d.L[69]*work1d.v[70];
  work1d.d[230] = work1d.v[230];
  if (work1d.d[230] > 0)
    work1d.d[230] = -settings1d.kkt_reg;
  else
    work1d.d[230] -= settings1d.kkt_reg;
  work1d.d_inv[230] = 1/work1d.d[230];
  work1d.L[790] = (work1d.KKT[460])*work1d.d_inv[230];
  work1d.v[71] = work1d.L[70]*work1d.d[71];
  work1d.v[231] = work1d.KKT[461]-work1d.L[70]*work1d.v[71];
  work1d.d[231] = work1d.v[231];
  if (work1d.d[231] > 0)
    work1d.d[231] = -settings1d.kkt_reg;
  else
    work1d.d[231] -= settings1d.kkt_reg;
  work1d.d_inv[231] = 1/work1d.d[231];
  work1d.L[810] = (work1d.KKT[462])*work1d.d_inv[231];
  work1d.v[72] = work1d.L[71]*work1d.d[72];
  work1d.v[232] = work1d.KKT[463]-work1d.L[71]*work1d.v[72];
  work1d.d[232] = work1d.v[232];
  if (work1d.d[232] > 0)
    work1d.d[232] = -settings1d.kkt_reg;
  else
    work1d.d[232] -= settings1d.kkt_reg;
  work1d.d_inv[232] = 1/work1d.d[232];
  work1d.L[830] = (work1d.KKT[464])*work1d.d_inv[232];
  work1d.v[73] = work1d.L[72]*work1d.d[73];
  work1d.v[233] = work1d.KKT[465]-work1d.L[72]*work1d.v[73];
  work1d.d[233] = work1d.v[233];
  if (work1d.d[233] > 0)
    work1d.d[233] = -settings1d.kkt_reg;
  else
    work1d.d[233] -= settings1d.kkt_reg;
  work1d.d_inv[233] = 1/work1d.d[233];
  work1d.L[850] = (work1d.KKT[466])*work1d.d_inv[233];
  work1d.v[74] = work1d.L[73]*work1d.d[74];
  work1d.v[234] = work1d.KKT[467]-work1d.L[73]*work1d.v[74];
  work1d.d[234] = work1d.v[234];
  if (work1d.d[234] > 0)
    work1d.d[234] = -settings1d.kkt_reg;
  else
    work1d.d[234] -= settings1d.kkt_reg;
  work1d.d_inv[234] = 1/work1d.d[234];
  work1d.L[870] = (work1d.KKT[468])*work1d.d_inv[234];
  work1d.v[75] = work1d.L[74]*work1d.d[75];
  work1d.v[235] = work1d.KKT[469]-work1d.L[74]*work1d.v[75];
  work1d.d[235] = work1d.v[235];
  if (work1d.d[235] > 0)
    work1d.d[235] = -settings1d.kkt_reg;
  else
    work1d.d[235] -= settings1d.kkt_reg;
  work1d.d_inv[235] = 1/work1d.d[235];
  work1d.L[890] = (work1d.KKT[470])*work1d.d_inv[235];
  work1d.v[76] = work1d.L[75]*work1d.d[76];
  work1d.v[236] = work1d.KKT[471]-work1d.L[75]*work1d.v[76];
  work1d.d[236] = work1d.v[236];
  if (work1d.d[236] > 0)
    work1d.d[236] = -settings1d.kkt_reg;
  else
    work1d.d[236] -= settings1d.kkt_reg;
  work1d.d_inv[236] = 1/work1d.d[236];
  work1d.L[910] = (work1d.KKT[472])*work1d.d_inv[236];
  work1d.v[77] = work1d.L[76]*work1d.d[77];
  work1d.v[237] = work1d.KKT[473]-work1d.L[76]*work1d.v[77];
  work1d.d[237] = work1d.v[237];
  if (work1d.d[237] > 0)
    work1d.d[237] = -settings1d.kkt_reg;
  else
    work1d.d[237] -= settings1d.kkt_reg;
  work1d.d_inv[237] = 1/work1d.d[237];
  work1d.L[930] = (work1d.KKT[474])*work1d.d_inv[237];
  work1d.v[78] = work1d.L[77]*work1d.d[78];
  work1d.v[238] = work1d.KKT[475]-work1d.L[77]*work1d.v[78];
  work1d.d[238] = work1d.v[238];
  if (work1d.d[238] > 0)
    work1d.d[238] = -settings1d.kkt_reg;
  else
    work1d.d[238] -= settings1d.kkt_reg;
  work1d.d_inv[238] = 1/work1d.d[238];
  work1d.L[956] = (work1d.KKT[476])*work1d.d_inv[238];
  work1d.v[79] = work1d.L[78]*work1d.d[79];
  work1d.v[239] = work1d.KKT[477]-work1d.L[78]*work1d.v[79];
  work1d.d[239] = work1d.v[239];
  if (work1d.d[239] > 0)
    work1d.d[239] = -settings1d.kkt_reg;
  else
    work1d.d[239] -= settings1d.kkt_reg;
  work1d.d_inv[239] = 1/work1d.d[239];
  work1d.L[168] = (work1d.KKT[478])*work1d.d_inv[239];
  work1d.v[80] = work1d.L[79]*work1d.d[80];
  work1d.v[240] = work1d.KKT[479]-work1d.L[79]*work1d.v[80];
  work1d.d[240] = work1d.v[240];
  if (work1d.d[240] > 0)
    work1d.d[240] = -settings1d.kkt_reg;
  else
    work1d.d[240] -= settings1d.kkt_reg;
  work1d.d_inv[240] = 1/work1d.d[240];
  work1d.L[161] = (work1d.KKT[480])*work1d.d_inv[240];
  work1d.v[81] = work1d.L[80]*work1d.d[81];
  work1d.v[241] = work1d.KKT[481]-work1d.L[80]*work1d.v[81];
  work1d.d[241] = work1d.v[241];
  if (work1d.d[241] > 0)
    work1d.d[241] = -settings1d.kkt_reg;
  else
    work1d.d[241] -= settings1d.kkt_reg;
  work1d.d_inv[241] = 1/work1d.d[241];
  work1d.L[216] = (work1d.KKT[482])*work1d.d_inv[241];
  work1d.v[82] = work1d.L[81]*work1d.d[82];
  work1d.v[242] = work1d.KKT[483]-work1d.L[81]*work1d.v[82];
  work1d.d[242] = work1d.v[242];
  if (work1d.d[242] > 0)
    work1d.d[242] = -settings1d.kkt_reg;
  else
    work1d.d[242] -= settings1d.kkt_reg;
  work1d.d_inv[242] = 1/work1d.d[242];
  work1d.L[230] = (work1d.KKT[484])*work1d.d_inv[242];
  work1d.v[83] = work1d.L[82]*work1d.d[83];
  work1d.v[243] = work1d.KKT[485]-work1d.L[82]*work1d.v[83];
  work1d.d[243] = work1d.v[243];
  if (work1d.d[243] > 0)
    work1d.d[243] = -settings1d.kkt_reg;
  else
    work1d.d[243] -= settings1d.kkt_reg;
  work1d.d_inv[243] = 1/work1d.d[243];
  work1d.L[248] = (work1d.KKT[486])*work1d.d_inv[243];
  work1d.v[84] = work1d.L[83]*work1d.d[84];
  work1d.v[244] = work1d.KKT[487]-work1d.L[83]*work1d.v[84];
  work1d.d[244] = work1d.v[244];
  if (work1d.d[244] > 0)
    work1d.d[244] = -settings1d.kkt_reg;
  else
    work1d.d[244] -= settings1d.kkt_reg;
  work1d.d_inv[244] = 1/work1d.d[244];
  work1d.L[268] = (work1d.KKT[488])*work1d.d_inv[244];
  work1d.v[85] = work1d.L[84]*work1d.d[85];
  work1d.v[245] = work1d.KKT[489]-work1d.L[84]*work1d.v[85];
  work1d.d[245] = work1d.v[245];
  if (work1d.d[245] > 0)
    work1d.d[245] = -settings1d.kkt_reg;
  else
    work1d.d[245] -= settings1d.kkt_reg;
  work1d.d_inv[245] = 1/work1d.d[245];
  work1d.L[288] = (work1d.KKT[490])*work1d.d_inv[245];
  work1d.v[86] = work1d.L[85]*work1d.d[86];
  work1d.v[246] = work1d.KKT[491]-work1d.L[85]*work1d.v[86];
  work1d.d[246] = work1d.v[246];
  if (work1d.d[246] > 0)
    work1d.d[246] = -settings1d.kkt_reg;
  else
    work1d.d[246] -= settings1d.kkt_reg;
  work1d.d_inv[246] = 1/work1d.d[246];
  work1d.L[308] = (work1d.KKT[492])*work1d.d_inv[246];
  work1d.v[87] = work1d.L[86]*work1d.d[87];
  work1d.v[247] = work1d.KKT[493]-work1d.L[86]*work1d.v[87];
  work1d.d[247] = work1d.v[247];
  if (work1d.d[247] > 0)
    work1d.d[247] = -settings1d.kkt_reg;
  else
    work1d.d[247] -= settings1d.kkt_reg;
  work1d.d_inv[247] = 1/work1d.d[247];
  work1d.L[328] = (work1d.KKT[494])*work1d.d_inv[247];
  work1d.v[88] = work1d.L[87]*work1d.d[88];
  work1d.v[248] = work1d.KKT[495]-work1d.L[87]*work1d.v[88];
  work1d.d[248] = work1d.v[248];
  if (work1d.d[248] > 0)
    work1d.d[248] = -settings1d.kkt_reg;
  else
    work1d.d[248] -= settings1d.kkt_reg;
  work1d.d_inv[248] = 1/work1d.d[248];
  work1d.L[348] = (work1d.KKT[496])*work1d.d_inv[248];
  work1d.v[89] = work1d.L[88]*work1d.d[89];
  work1d.v[249] = work1d.KKT[497]-work1d.L[88]*work1d.v[89];
  work1d.d[249] = work1d.v[249];
  if (work1d.d[249] > 0)
    work1d.d[249] = -settings1d.kkt_reg;
  else
    work1d.d[249] -= settings1d.kkt_reg;
  work1d.d_inv[249] = 1/work1d.d[249];
  work1d.L[368] = (work1d.KKT[498])*work1d.d_inv[249];
  work1d.v[90] = work1d.L[89]*work1d.d[90];
  work1d.v[250] = work1d.KKT[499]-work1d.L[89]*work1d.v[90];
  work1d.d[250] = work1d.v[250];
  if (work1d.d[250] > 0)
    work1d.d[250] = -settings1d.kkt_reg;
  else
    work1d.d[250] -= settings1d.kkt_reg;
  work1d.d_inv[250] = 1/work1d.d[250];
  work1d.L[388] = (work1d.KKT[500])*work1d.d_inv[250];
  work1d.v[91] = work1d.L[90]*work1d.d[91];
  work1d.v[251] = work1d.KKT[501]-work1d.L[90]*work1d.v[91];
  work1d.d[251] = work1d.v[251];
  if (work1d.d[251] > 0)
    work1d.d[251] = -settings1d.kkt_reg;
  else
    work1d.d[251] -= settings1d.kkt_reg;
  work1d.d_inv[251] = 1/work1d.d[251];
  work1d.L[408] = (work1d.KKT[502])*work1d.d_inv[251];
  work1d.v[92] = work1d.L[91]*work1d.d[92];
  work1d.v[252] = work1d.KKT[503]-work1d.L[91]*work1d.v[92];
  work1d.d[252] = work1d.v[252];
  if (work1d.d[252] > 0)
    work1d.d[252] = -settings1d.kkt_reg;
  else
    work1d.d[252] -= settings1d.kkt_reg;
  work1d.d_inv[252] = 1/work1d.d[252];
  work1d.L[428] = (work1d.KKT[504])*work1d.d_inv[252];
  work1d.v[93] = work1d.L[92]*work1d.d[93];
  work1d.v[253] = work1d.KKT[505]-work1d.L[92]*work1d.v[93];
  work1d.d[253] = work1d.v[253];
  if (work1d.d[253] > 0)
    work1d.d[253] = -settings1d.kkt_reg;
  else
    work1d.d[253] -= settings1d.kkt_reg;
  work1d.d_inv[253] = 1/work1d.d[253];
  work1d.L[448] = (work1d.KKT[506])*work1d.d_inv[253];
  work1d.v[94] = work1d.L[93]*work1d.d[94];
  work1d.v[254] = work1d.KKT[507]-work1d.L[93]*work1d.v[94];
  work1d.d[254] = work1d.v[254];
  if (work1d.d[254] > 0)
    work1d.d[254] = -settings1d.kkt_reg;
  else
    work1d.d[254] -= settings1d.kkt_reg;
  work1d.d_inv[254] = 1/work1d.d[254];
  work1d.L[468] = (work1d.KKT[508])*work1d.d_inv[254];
  work1d.v[95] = work1d.L[94]*work1d.d[95];
  work1d.v[255] = work1d.KKT[509]-work1d.L[94]*work1d.v[95];
  work1d.d[255] = work1d.v[255];
  if (work1d.d[255] > 0)
    work1d.d[255] = -settings1d.kkt_reg;
  else
    work1d.d[255] -= settings1d.kkt_reg;
  work1d.d_inv[255] = 1/work1d.d[255];
  work1d.L[488] = (work1d.KKT[510])*work1d.d_inv[255];
  work1d.v[96] = work1d.L[95]*work1d.d[96];
  work1d.v[256] = work1d.KKT[511]-work1d.L[95]*work1d.v[96];
  work1d.d[256] = work1d.v[256];
  if (work1d.d[256] > 0)
    work1d.d[256] = -settings1d.kkt_reg;
  else
    work1d.d[256] -= settings1d.kkt_reg;
  work1d.d_inv[256] = 1/work1d.d[256];
  work1d.L[508] = (work1d.KKT[512])*work1d.d_inv[256];
  work1d.v[97] = work1d.L[96]*work1d.d[97];
  work1d.v[257] = work1d.KKT[513]-work1d.L[96]*work1d.v[97];
  work1d.d[257] = work1d.v[257];
  if (work1d.d[257] > 0)
    work1d.d[257] = -settings1d.kkt_reg;
  else
    work1d.d[257] -= settings1d.kkt_reg;
  work1d.d_inv[257] = 1/work1d.d[257];
  work1d.L[528] = (work1d.KKT[514])*work1d.d_inv[257];
  work1d.v[98] = work1d.L[97]*work1d.d[98];
  work1d.v[258] = work1d.KKT[515]-work1d.L[97]*work1d.v[98];
  work1d.d[258] = work1d.v[258];
  if (work1d.d[258] > 0)
    work1d.d[258] = -settings1d.kkt_reg;
  else
    work1d.d[258] -= settings1d.kkt_reg;
  work1d.d_inv[258] = 1/work1d.d[258];
  work1d.L[548] = (work1d.KKT[516])*work1d.d_inv[258];
  work1d.v[99] = work1d.L[98]*work1d.d[99];
  work1d.v[259] = work1d.KKT[517]-work1d.L[98]*work1d.v[99];
  work1d.d[259] = work1d.v[259];
  if (work1d.d[259] > 0)
    work1d.d[259] = -settings1d.kkt_reg;
  else
    work1d.d[259] -= settings1d.kkt_reg;
  work1d.d_inv[259] = 1/work1d.d[259];
  work1d.L[568] = (work1d.KKT[518])*work1d.d_inv[259];
  work1d.v[100] = work1d.L[99]*work1d.d[100];
  work1d.v[260] = work1d.KKT[519]-work1d.L[99]*work1d.v[100];
  work1d.d[260] = work1d.v[260];
  if (work1d.d[260] > 0)
    work1d.d[260] = -settings1d.kkt_reg;
  else
    work1d.d[260] -= settings1d.kkt_reg;
  work1d.d_inv[260] = 1/work1d.d[260];
  work1d.L[588] = (work1d.KKT[520])*work1d.d_inv[260];
  work1d.v[101] = work1d.L[100]*work1d.d[101];
  work1d.v[261] = work1d.KKT[521]-work1d.L[100]*work1d.v[101];
  work1d.d[261] = work1d.v[261];
  if (work1d.d[261] > 0)
    work1d.d[261] = -settings1d.kkt_reg;
  else
    work1d.d[261] -= settings1d.kkt_reg;
  work1d.d_inv[261] = 1/work1d.d[261];
  work1d.L[608] = (work1d.KKT[522])*work1d.d_inv[261];
  work1d.v[102] = work1d.L[101]*work1d.d[102];
  work1d.v[262] = work1d.KKT[523]-work1d.L[101]*work1d.v[102];
  work1d.d[262] = work1d.v[262];
  if (work1d.d[262] > 0)
    work1d.d[262] = -settings1d.kkt_reg;
  else
    work1d.d[262] -= settings1d.kkt_reg;
  work1d.d_inv[262] = 1/work1d.d[262];
  work1d.L[628] = (work1d.KKT[524])*work1d.d_inv[262];
  work1d.v[103] = work1d.L[102]*work1d.d[103];
  work1d.v[263] = work1d.KKT[525]-work1d.L[102]*work1d.v[103];
  work1d.d[263] = work1d.v[263];
  if (work1d.d[263] > 0)
    work1d.d[263] = -settings1d.kkt_reg;
  else
    work1d.d[263] -= settings1d.kkt_reg;
  work1d.d_inv[263] = 1/work1d.d[263];
  work1d.L[648] = (work1d.KKT[526])*work1d.d_inv[263];
  work1d.v[104] = work1d.L[103]*work1d.d[104];
  work1d.v[264] = work1d.KKT[527]-work1d.L[103]*work1d.v[104];
  work1d.d[264] = work1d.v[264];
  if (work1d.d[264] > 0)
    work1d.d[264] = -settings1d.kkt_reg;
  else
    work1d.d[264] -= settings1d.kkt_reg;
  work1d.d_inv[264] = 1/work1d.d[264];
  work1d.L[668] = (work1d.KKT[528])*work1d.d_inv[264];
  work1d.v[105] = work1d.L[104]*work1d.d[105];
  work1d.v[265] = work1d.KKT[529]-work1d.L[104]*work1d.v[105];
  work1d.d[265] = work1d.v[265];
  if (work1d.d[265] > 0)
    work1d.d[265] = -settings1d.kkt_reg;
  else
    work1d.d[265] -= settings1d.kkt_reg;
  work1d.d_inv[265] = 1/work1d.d[265];
  work1d.L[688] = (work1d.KKT[530])*work1d.d_inv[265];
  work1d.v[106] = work1d.L[105]*work1d.d[106];
  work1d.v[266] = work1d.KKT[531]-work1d.L[105]*work1d.v[106];
  work1d.d[266] = work1d.v[266];
  if (work1d.d[266] > 0)
    work1d.d[266] = -settings1d.kkt_reg;
  else
    work1d.d[266] -= settings1d.kkt_reg;
  work1d.d_inv[266] = 1/work1d.d[266];
  work1d.L[708] = (work1d.KKT[532])*work1d.d_inv[266];
  work1d.v[107] = work1d.L[106]*work1d.d[107];
  work1d.v[267] = work1d.KKT[533]-work1d.L[106]*work1d.v[107];
  work1d.d[267] = work1d.v[267];
  if (work1d.d[267] > 0)
    work1d.d[267] = -settings1d.kkt_reg;
  else
    work1d.d[267] -= settings1d.kkt_reg;
  work1d.d_inv[267] = 1/work1d.d[267];
  work1d.L[728] = (work1d.KKT[534])*work1d.d_inv[267];
  work1d.v[108] = work1d.L[107]*work1d.d[108];
  work1d.v[268] = work1d.KKT[535]-work1d.L[107]*work1d.v[108];
  work1d.d[268] = work1d.v[268];
  if (work1d.d[268] > 0)
    work1d.d[268] = -settings1d.kkt_reg;
  else
    work1d.d[268] -= settings1d.kkt_reg;
  work1d.d_inv[268] = 1/work1d.d[268];
  work1d.L[748] = (work1d.KKT[536])*work1d.d_inv[268];
  work1d.v[109] = work1d.L[108]*work1d.d[109];
  work1d.v[269] = work1d.KKT[537]-work1d.L[108]*work1d.v[109];
  work1d.d[269] = work1d.v[269];
  if (work1d.d[269] > 0)
    work1d.d[269] = -settings1d.kkt_reg;
  else
    work1d.d[269] -= settings1d.kkt_reg;
  work1d.d_inv[269] = 1/work1d.d[269];
  work1d.L[768] = (work1d.KKT[538])*work1d.d_inv[269];
  work1d.v[110] = work1d.L[109]*work1d.d[110];
  work1d.v[270] = work1d.KKT[539]-work1d.L[109]*work1d.v[110];
  work1d.d[270] = work1d.v[270];
  if (work1d.d[270] > 0)
    work1d.d[270] = -settings1d.kkt_reg;
  else
    work1d.d[270] -= settings1d.kkt_reg;
  work1d.d_inv[270] = 1/work1d.d[270];
  work1d.L[788] = (work1d.KKT[540])*work1d.d_inv[270];
  work1d.v[111] = work1d.L[110]*work1d.d[111];
  work1d.v[271] = work1d.KKT[541]-work1d.L[110]*work1d.v[111];
  work1d.d[271] = work1d.v[271];
  if (work1d.d[271] > 0)
    work1d.d[271] = -settings1d.kkt_reg;
  else
    work1d.d[271] -= settings1d.kkt_reg;
  work1d.d_inv[271] = 1/work1d.d[271];
  work1d.L[808] = (work1d.KKT[542])*work1d.d_inv[271];
  work1d.v[112] = work1d.L[111]*work1d.d[112];
  work1d.v[272] = work1d.KKT[543]-work1d.L[111]*work1d.v[112];
  work1d.d[272] = work1d.v[272];
  if (work1d.d[272] > 0)
    work1d.d[272] = -settings1d.kkt_reg;
  else
    work1d.d[272] -= settings1d.kkt_reg;
  work1d.d_inv[272] = 1/work1d.d[272];
  work1d.L[828] = (work1d.KKT[544])*work1d.d_inv[272];
  work1d.v[113] = work1d.L[112]*work1d.d[113];
  work1d.v[273] = work1d.KKT[545]-work1d.L[112]*work1d.v[113];
  work1d.d[273] = work1d.v[273];
  if (work1d.d[273] > 0)
    work1d.d[273] = -settings1d.kkt_reg;
  else
    work1d.d[273] -= settings1d.kkt_reg;
  work1d.d_inv[273] = 1/work1d.d[273];
  work1d.L[848] = (work1d.KKT[546])*work1d.d_inv[273];
  work1d.v[114] = work1d.L[113]*work1d.d[114];
  work1d.v[274] = work1d.KKT[547]-work1d.L[113]*work1d.v[114];
  work1d.d[274] = work1d.v[274];
  if (work1d.d[274] > 0)
    work1d.d[274] = -settings1d.kkt_reg;
  else
    work1d.d[274] -= settings1d.kkt_reg;
  work1d.d_inv[274] = 1/work1d.d[274];
  work1d.L[868] = (work1d.KKT[548])*work1d.d_inv[274];
  work1d.v[115] = work1d.L[114]*work1d.d[115];
  work1d.v[275] = work1d.KKT[549]-work1d.L[114]*work1d.v[115];
  work1d.d[275] = work1d.v[275];
  if (work1d.d[275] > 0)
    work1d.d[275] = -settings1d.kkt_reg;
  else
    work1d.d[275] -= settings1d.kkt_reg;
  work1d.d_inv[275] = 1/work1d.d[275];
  work1d.L[888] = (work1d.KKT[550])*work1d.d_inv[275];
  work1d.v[116] = work1d.L[115]*work1d.d[116];
  work1d.v[276] = work1d.KKT[551]-work1d.L[115]*work1d.v[116];
  work1d.d[276] = work1d.v[276];
  if (work1d.d[276] > 0)
    work1d.d[276] = -settings1d.kkt_reg;
  else
    work1d.d[276] -= settings1d.kkt_reg;
  work1d.d_inv[276] = 1/work1d.d[276];
  work1d.L[908] = (work1d.KKT[552])*work1d.d_inv[276];
  work1d.v[117] = work1d.L[116]*work1d.d[117];
  work1d.v[277] = work1d.KKT[553]-work1d.L[116]*work1d.v[117];
  work1d.d[277] = work1d.v[277];
  if (work1d.d[277] > 0)
    work1d.d[277] = -settings1d.kkt_reg;
  else
    work1d.d[277] -= settings1d.kkt_reg;
  work1d.d_inv[277] = 1/work1d.d[277];
  work1d.L[928] = (work1d.KKT[554])*work1d.d_inv[277];
  work1d.v[118] = work1d.L[117]*work1d.d[118];
  work1d.v[278] = work1d.KKT[555]-work1d.L[117]*work1d.v[118];
  work1d.d[278] = work1d.v[278];
  if (work1d.d[278] > 0)
    work1d.d[278] = -settings1d.kkt_reg;
  else
    work1d.d[278] -= settings1d.kkt_reg;
  work1d.d_inv[278] = 1/work1d.d[278];
  work1d.L[952] = (work1d.KKT[556])*work1d.d_inv[278];
  work1d.v[119] = work1d.L[118]*work1d.d[119];
  work1d.v[279] = work1d.KKT[557]-work1d.L[118]*work1d.v[119];
  work1d.d[279] = work1d.v[279];
  if (work1d.d[279] > 0)
    work1d.d[279] = -settings1d.kkt_reg;
  else
    work1d.d[279] -= settings1d.kkt_reg;
  work1d.d_inv[279] = 1/work1d.d[279];
  work1d.L[968] = (work1d.KKT[558])*work1d.d_inv[279];
  work1d.v[120] = work1d.L[119]*work1d.d[120];
  work1d.v[280] = work1d.KKT[559]-work1d.L[119]*work1d.v[120];
  work1d.d[280] = work1d.v[280];
  if (work1d.d[280] > 0)
    work1d.d[280] = -settings1d.kkt_reg;
  else
    work1d.d[280] -= settings1d.kkt_reg;
  work1d.d_inv[280] = 1/work1d.d[280];
  work1d.L[167] = (work1d.KKT[560])*work1d.d_inv[280];
  work1d.v[121] = work1d.L[120]*work1d.d[121];
  work1d.v[281] = work1d.KKT[561]-work1d.L[120]*work1d.v[121];
  work1d.d[281] = work1d.v[281];
  if (work1d.d[281] > 0)
    work1d.d[281] = -settings1d.kkt_reg;
  else
    work1d.d[281] -= settings1d.kkt_reg;
  work1d.d_inv[281] = 1/work1d.d[281];
  work1d.L[220] = (work1d.KKT[562])*work1d.d_inv[281];
  work1d.v[122] = work1d.L[121]*work1d.d[122];
  work1d.v[282] = work1d.KKT[563]-work1d.L[121]*work1d.v[122];
  work1d.d[282] = work1d.v[282];
  if (work1d.d[282] > 0)
    work1d.d[282] = -settings1d.kkt_reg;
  else
    work1d.d[282] -= settings1d.kkt_reg;
  work1d.d_inv[282] = 1/work1d.d[282];
  work1d.L[233] = (work1d.KKT[564])*work1d.d_inv[282];
  work1d.v[123] = work1d.L[122]*work1d.d[123];
  work1d.v[283] = work1d.KKT[565]-work1d.L[122]*work1d.v[123];
  work1d.d[283] = work1d.v[283];
  if (work1d.d[283] > 0)
    work1d.d[283] = -settings1d.kkt_reg;
  else
    work1d.d[283] -= settings1d.kkt_reg;
  work1d.d_inv[283] = 1/work1d.d[283];
  work1d.L[251] = (work1d.KKT[566])*work1d.d_inv[283];
  work1d.v[124] = work1d.L[123]*work1d.d[124];
  work1d.v[284] = work1d.KKT[567]-work1d.L[123]*work1d.v[124];
  work1d.d[284] = work1d.v[284];
  if (work1d.d[284] > 0)
    work1d.d[284] = -settings1d.kkt_reg;
  else
    work1d.d[284] -= settings1d.kkt_reg;
  work1d.d_inv[284] = 1/work1d.d[284];
  work1d.L[271] = (work1d.KKT[568])*work1d.d_inv[284];
  work1d.v[125] = work1d.L[124]*work1d.d[125];
  work1d.v[285] = work1d.KKT[569]-work1d.L[124]*work1d.v[125];
  work1d.d[285] = work1d.v[285];
  if (work1d.d[285] > 0)
    work1d.d[285] = -settings1d.kkt_reg;
  else
    work1d.d[285] -= settings1d.kkt_reg;
  work1d.d_inv[285] = 1/work1d.d[285];
  work1d.L[291] = (work1d.KKT[570])*work1d.d_inv[285];
  work1d.v[126] = work1d.L[125]*work1d.d[126];
  work1d.v[286] = work1d.KKT[571]-work1d.L[125]*work1d.v[126];
  work1d.d[286] = work1d.v[286];
  if (work1d.d[286] > 0)
    work1d.d[286] = -settings1d.kkt_reg;
  else
    work1d.d[286] -= settings1d.kkt_reg;
  work1d.d_inv[286] = 1/work1d.d[286];
  work1d.L[311] = (work1d.KKT[572])*work1d.d_inv[286];
  work1d.v[127] = work1d.L[126]*work1d.d[127];
  work1d.v[287] = work1d.KKT[573]-work1d.L[126]*work1d.v[127];
  work1d.d[287] = work1d.v[287];
  if (work1d.d[287] > 0)
    work1d.d[287] = -settings1d.kkt_reg;
  else
    work1d.d[287] -= settings1d.kkt_reg;
  work1d.d_inv[287] = 1/work1d.d[287];
  work1d.L[331] = (work1d.KKT[574])*work1d.d_inv[287];
  work1d.v[128] = work1d.L[127]*work1d.d[128];
  work1d.v[288] = work1d.KKT[575]-work1d.L[127]*work1d.v[128];
  work1d.d[288] = work1d.v[288];
  if (work1d.d[288] > 0)
    work1d.d[288] = -settings1d.kkt_reg;
  else
    work1d.d[288] -= settings1d.kkt_reg;
  work1d.d_inv[288] = 1/work1d.d[288];
  work1d.L[351] = (work1d.KKT[576])*work1d.d_inv[288];
  work1d.v[129] = work1d.L[128]*work1d.d[129];
  work1d.v[289] = work1d.KKT[577]-work1d.L[128]*work1d.v[129];
  work1d.d[289] = work1d.v[289];
  if (work1d.d[289] > 0)
    work1d.d[289] = -settings1d.kkt_reg;
  else
    work1d.d[289] -= settings1d.kkt_reg;
  work1d.d_inv[289] = 1/work1d.d[289];
  work1d.L[371] = (work1d.KKT[578])*work1d.d_inv[289];
  work1d.v[130] = work1d.L[129]*work1d.d[130];
  work1d.v[290] = work1d.KKT[579]-work1d.L[129]*work1d.v[130];
  work1d.d[290] = work1d.v[290];
  if (work1d.d[290] > 0)
    work1d.d[290] = -settings1d.kkt_reg;
  else
    work1d.d[290] -= settings1d.kkt_reg;
  work1d.d_inv[290] = 1/work1d.d[290];
  work1d.L[391] = (work1d.KKT[580])*work1d.d_inv[290];
  work1d.v[131] = work1d.L[130]*work1d.d[131];
  work1d.v[291] = work1d.KKT[581]-work1d.L[130]*work1d.v[131];
  work1d.d[291] = work1d.v[291];
  if (work1d.d[291] > 0)
    work1d.d[291] = -settings1d.kkt_reg;
  else
    work1d.d[291] -= settings1d.kkt_reg;
  work1d.d_inv[291] = 1/work1d.d[291];
  work1d.L[411] = (work1d.KKT[582])*work1d.d_inv[291];
  work1d.v[132] = work1d.L[131]*work1d.d[132];
  work1d.v[292] = work1d.KKT[583]-work1d.L[131]*work1d.v[132];
  work1d.d[292] = work1d.v[292];
  if (work1d.d[292] > 0)
    work1d.d[292] = -settings1d.kkt_reg;
  else
    work1d.d[292] -= settings1d.kkt_reg;
  work1d.d_inv[292] = 1/work1d.d[292];
  work1d.L[431] = (work1d.KKT[584])*work1d.d_inv[292];
  work1d.v[133] = work1d.L[132]*work1d.d[133];
  work1d.v[293] = work1d.KKT[585]-work1d.L[132]*work1d.v[133];
  work1d.d[293] = work1d.v[293];
  if (work1d.d[293] > 0)
    work1d.d[293] = -settings1d.kkt_reg;
  else
    work1d.d[293] -= settings1d.kkt_reg;
  work1d.d_inv[293] = 1/work1d.d[293];
  work1d.L[451] = (work1d.KKT[586])*work1d.d_inv[293];
  work1d.v[134] = work1d.L[133]*work1d.d[134];
  work1d.v[294] = work1d.KKT[587]-work1d.L[133]*work1d.v[134];
  work1d.d[294] = work1d.v[294];
  if (work1d.d[294] > 0)
    work1d.d[294] = -settings1d.kkt_reg;
  else
    work1d.d[294] -= settings1d.kkt_reg;
  work1d.d_inv[294] = 1/work1d.d[294];
  work1d.L[471] = (work1d.KKT[588])*work1d.d_inv[294];
  work1d.v[135] = work1d.L[134]*work1d.d[135];
  work1d.v[295] = work1d.KKT[589]-work1d.L[134]*work1d.v[135];
  work1d.d[295] = work1d.v[295];
  if (work1d.d[295] > 0)
    work1d.d[295] = -settings1d.kkt_reg;
  else
    work1d.d[295] -= settings1d.kkt_reg;
  work1d.d_inv[295] = 1/work1d.d[295];
  work1d.L[491] = (work1d.KKT[590])*work1d.d_inv[295];
  work1d.v[136] = work1d.L[135]*work1d.d[136];
  work1d.v[296] = work1d.KKT[591]-work1d.L[135]*work1d.v[136];
  work1d.d[296] = work1d.v[296];
  if (work1d.d[296] > 0)
    work1d.d[296] = -settings1d.kkt_reg;
  else
    work1d.d[296] -= settings1d.kkt_reg;
  work1d.d_inv[296] = 1/work1d.d[296];
  work1d.L[511] = (work1d.KKT[592])*work1d.d_inv[296];
  work1d.v[137] = work1d.L[136]*work1d.d[137];
  work1d.v[297] = work1d.KKT[593]-work1d.L[136]*work1d.v[137];
  work1d.d[297] = work1d.v[297];
  if (work1d.d[297] > 0)
    work1d.d[297] = -settings1d.kkt_reg;
  else
    work1d.d[297] -= settings1d.kkt_reg;
  work1d.d_inv[297] = 1/work1d.d[297];
  work1d.L[531] = (work1d.KKT[594])*work1d.d_inv[297];
  work1d.v[138] = work1d.L[137]*work1d.d[138];
  work1d.v[298] = work1d.KKT[595]-work1d.L[137]*work1d.v[138];
  work1d.d[298] = work1d.v[298];
  if (work1d.d[298] > 0)
    work1d.d[298] = -settings1d.kkt_reg;
  else
    work1d.d[298] -= settings1d.kkt_reg;
  work1d.d_inv[298] = 1/work1d.d[298];
  work1d.L[551] = (work1d.KKT[596])*work1d.d_inv[298];
  work1d.v[139] = work1d.L[138]*work1d.d[139];
  work1d.v[299] = work1d.KKT[597]-work1d.L[138]*work1d.v[139];
  work1d.d[299] = work1d.v[299];
  if (work1d.d[299] > 0)
    work1d.d[299] = -settings1d.kkt_reg;
  else
    work1d.d[299] -= settings1d.kkt_reg;
  work1d.d_inv[299] = 1/work1d.d[299];
  work1d.L[571] = (work1d.KKT[598])*work1d.d_inv[299];
  work1d.v[140] = work1d.L[139]*work1d.d[140];
  work1d.v[300] = work1d.KKT[599]-work1d.L[139]*work1d.v[140];
  work1d.d[300] = work1d.v[300];
  if (work1d.d[300] > 0)
    work1d.d[300] = -settings1d.kkt_reg;
  else
    work1d.d[300] -= settings1d.kkt_reg;
  work1d.d_inv[300] = 1/work1d.d[300];
  work1d.L[591] = (work1d.KKT[600])*work1d.d_inv[300];
  work1d.v[141] = work1d.L[140]*work1d.d[141];
  work1d.v[301] = work1d.KKT[601]-work1d.L[140]*work1d.v[141];
  work1d.d[301] = work1d.v[301];
  if (work1d.d[301] > 0)
    work1d.d[301] = -settings1d.kkt_reg;
  else
    work1d.d[301] -= settings1d.kkt_reg;
  work1d.d_inv[301] = 1/work1d.d[301];
  work1d.L[611] = (work1d.KKT[602])*work1d.d_inv[301];
  work1d.v[142] = work1d.L[141]*work1d.d[142];
  work1d.v[302] = work1d.KKT[603]-work1d.L[141]*work1d.v[142];
  work1d.d[302] = work1d.v[302];
  if (work1d.d[302] > 0)
    work1d.d[302] = -settings1d.kkt_reg;
  else
    work1d.d[302] -= settings1d.kkt_reg;
  work1d.d_inv[302] = 1/work1d.d[302];
  work1d.L[631] = (work1d.KKT[604])*work1d.d_inv[302];
  work1d.v[143] = work1d.L[142]*work1d.d[143];
  work1d.v[303] = work1d.KKT[605]-work1d.L[142]*work1d.v[143];
  work1d.d[303] = work1d.v[303];
  if (work1d.d[303] > 0)
    work1d.d[303] = -settings1d.kkt_reg;
  else
    work1d.d[303] -= settings1d.kkt_reg;
  work1d.d_inv[303] = 1/work1d.d[303];
  work1d.L[651] = (work1d.KKT[606])*work1d.d_inv[303];
  work1d.v[144] = work1d.L[143]*work1d.d[144];
  work1d.v[304] = work1d.KKT[607]-work1d.L[143]*work1d.v[144];
  work1d.d[304] = work1d.v[304];
  if (work1d.d[304] > 0)
    work1d.d[304] = -settings1d.kkt_reg;
  else
    work1d.d[304] -= settings1d.kkt_reg;
  work1d.d_inv[304] = 1/work1d.d[304];
  work1d.L[671] = (work1d.KKT[608])*work1d.d_inv[304];
  work1d.v[145] = work1d.L[144]*work1d.d[145];
  work1d.v[305] = work1d.KKT[609]-work1d.L[144]*work1d.v[145];
  work1d.d[305] = work1d.v[305];
  if (work1d.d[305] > 0)
    work1d.d[305] = -settings1d.kkt_reg;
  else
    work1d.d[305] -= settings1d.kkt_reg;
  work1d.d_inv[305] = 1/work1d.d[305];
  work1d.L[691] = (work1d.KKT[610])*work1d.d_inv[305];
  work1d.v[146] = work1d.L[145]*work1d.d[146];
  work1d.v[306] = work1d.KKT[611]-work1d.L[145]*work1d.v[146];
  work1d.d[306] = work1d.v[306];
  if (work1d.d[306] > 0)
    work1d.d[306] = -settings1d.kkt_reg;
  else
    work1d.d[306] -= settings1d.kkt_reg;
  work1d.d_inv[306] = 1/work1d.d[306];
  work1d.L[711] = (work1d.KKT[612])*work1d.d_inv[306];
  work1d.v[147] = work1d.L[146]*work1d.d[147];
  work1d.v[307] = work1d.KKT[613]-work1d.L[146]*work1d.v[147];
  work1d.d[307] = work1d.v[307];
  if (work1d.d[307] > 0)
    work1d.d[307] = -settings1d.kkt_reg;
  else
    work1d.d[307] -= settings1d.kkt_reg;
  work1d.d_inv[307] = 1/work1d.d[307];
  work1d.L[731] = (work1d.KKT[614])*work1d.d_inv[307];
  work1d.v[148] = work1d.L[147]*work1d.d[148];
  work1d.v[308] = work1d.KKT[615]-work1d.L[147]*work1d.v[148];
  work1d.d[308] = work1d.v[308];
  if (work1d.d[308] > 0)
    work1d.d[308] = -settings1d.kkt_reg;
  else
    work1d.d[308] -= settings1d.kkt_reg;
  work1d.d_inv[308] = 1/work1d.d[308];
  work1d.L[751] = (work1d.KKT[616])*work1d.d_inv[308];
  work1d.v[149] = work1d.L[148]*work1d.d[149];
  work1d.v[309] = work1d.KKT[617]-work1d.L[148]*work1d.v[149];
  work1d.d[309] = work1d.v[309];
  if (work1d.d[309] > 0)
    work1d.d[309] = -settings1d.kkt_reg;
  else
    work1d.d[309] -= settings1d.kkt_reg;
  work1d.d_inv[309] = 1/work1d.d[309];
  work1d.L[771] = (work1d.KKT[618])*work1d.d_inv[309];
  work1d.v[150] = work1d.L[149]*work1d.d[150];
  work1d.v[310] = work1d.KKT[619]-work1d.L[149]*work1d.v[150];
  work1d.d[310] = work1d.v[310];
  if (work1d.d[310] > 0)
    work1d.d[310] = -settings1d.kkt_reg;
  else
    work1d.d[310] -= settings1d.kkt_reg;
  work1d.d_inv[310] = 1/work1d.d[310];
  work1d.L[791] = (work1d.KKT[620])*work1d.d_inv[310];
  work1d.v[151] = work1d.L[150]*work1d.d[151];
  work1d.v[311] = work1d.KKT[621]-work1d.L[150]*work1d.v[151];
  work1d.d[311] = work1d.v[311];
  if (work1d.d[311] > 0)
    work1d.d[311] = -settings1d.kkt_reg;
  else
    work1d.d[311] -= settings1d.kkt_reg;
  work1d.d_inv[311] = 1/work1d.d[311];
  work1d.L[811] = (work1d.KKT[622])*work1d.d_inv[311];
  work1d.v[152] = work1d.L[151]*work1d.d[152];
  work1d.v[312] = work1d.KKT[623]-work1d.L[151]*work1d.v[152];
  work1d.d[312] = work1d.v[312];
  if (work1d.d[312] > 0)
    work1d.d[312] = -settings1d.kkt_reg;
  else
    work1d.d[312] -= settings1d.kkt_reg;
  work1d.d_inv[312] = 1/work1d.d[312];
  work1d.L[831] = (work1d.KKT[624])*work1d.d_inv[312];
  work1d.v[153] = work1d.L[152]*work1d.d[153];
  work1d.v[313] = work1d.KKT[625]-work1d.L[152]*work1d.v[153];
  work1d.d[313] = work1d.v[313];
  if (work1d.d[313] > 0)
    work1d.d[313] = -settings1d.kkt_reg;
  else
    work1d.d[313] -= settings1d.kkt_reg;
  work1d.d_inv[313] = 1/work1d.d[313];
  work1d.L[851] = (work1d.KKT[626])*work1d.d_inv[313];
  work1d.v[154] = work1d.L[153]*work1d.d[154];
  work1d.v[314] = work1d.KKT[627]-work1d.L[153]*work1d.v[154];
  work1d.d[314] = work1d.v[314];
  if (work1d.d[314] > 0)
    work1d.d[314] = -settings1d.kkt_reg;
  else
    work1d.d[314] -= settings1d.kkt_reg;
  work1d.d_inv[314] = 1/work1d.d[314];
  work1d.L[871] = (work1d.KKT[628])*work1d.d_inv[314];
  work1d.v[155] = work1d.L[154]*work1d.d[155];
  work1d.v[315] = work1d.KKT[629]-work1d.L[154]*work1d.v[155];
  work1d.d[315] = work1d.v[315];
  if (work1d.d[315] > 0)
    work1d.d[315] = -settings1d.kkt_reg;
  else
    work1d.d[315] -= settings1d.kkt_reg;
  work1d.d_inv[315] = 1/work1d.d[315];
  work1d.L[891] = (work1d.KKT[630])*work1d.d_inv[315];
  work1d.v[156] = work1d.L[155]*work1d.d[156];
  work1d.v[316] = work1d.KKT[631]-work1d.L[155]*work1d.v[156];
  work1d.d[316] = work1d.v[316];
  if (work1d.d[316] > 0)
    work1d.d[316] = -settings1d.kkt_reg;
  else
    work1d.d[316] -= settings1d.kkt_reg;
  work1d.d_inv[316] = 1/work1d.d[316];
  work1d.L[911] = (work1d.KKT[632])*work1d.d_inv[316];
  work1d.v[157] = work1d.L[156]*work1d.d[157];
  work1d.v[317] = work1d.KKT[633]-work1d.L[156]*work1d.v[157];
  work1d.d[317] = work1d.v[317];
  if (work1d.d[317] > 0)
    work1d.d[317] = -settings1d.kkt_reg;
  else
    work1d.d[317] -= settings1d.kkt_reg;
  work1d.d_inv[317] = 1/work1d.d[317];
  work1d.L[931] = (work1d.KKT[634])*work1d.d_inv[317];
  work1d.v[158] = work1d.L[157]*work1d.d[158];
  work1d.v[318] = work1d.KKT[635]-work1d.L[157]*work1d.v[158];
  work1d.d[318] = work1d.v[318];
  if (work1d.d[318] > 0)
    work1d.d[318] = -settings1d.kkt_reg;
  else
    work1d.d[318] -= settings1d.kkt_reg;
  work1d.d_inv[318] = 1/work1d.d[318];
  work1d.L[957] = (work1d.KKT[636])*work1d.d_inv[318];
  work1d.v[159] = work1d.L[158]*work1d.d[159];
  work1d.v[319] = work1d.KKT[637]-work1d.L[158]*work1d.v[159];
  work1d.d[319] = work1d.v[319];
  if (work1d.d[319] > 0)
    work1d.d[319] = -settings1d.kkt_reg;
  else
    work1d.d[319] -= settings1d.kkt_reg;
  work1d.d_inv[319] = 1/work1d.d[319];
  work1d.L[169] = (work1d.KKT[638])*work1d.d_inv[319];
  work1d.v[160] = work1d.L[159]*work1d.d[160];
  work1d.v[320] = work1d.KKT[639]-work1d.L[159]*work1d.v[160];
  work1d.d[320] = work1d.v[320];
  if (work1d.d[320] > 0)
    work1d.d[320] = -settings1d.kkt_reg;
  else
    work1d.d[320] -= settings1d.kkt_reg;
  work1d.d_inv[320] = 1/work1d.d[320];
  work1d.L[162] = (work1d.KKT[640])*work1d.d_inv[320];
  work1d.v[321] = 0;
  work1d.d[321] = work1d.v[321];
  if (work1d.d[321] > 0)
    work1d.d[321] = -settings1d.kkt_reg;
  else
    work1d.d[321] -= settings1d.kkt_reg;
  work1d.d_inv[321] = 1/work1d.d[321];
  work1d.L[165] = (work1d.KKT[641])*work1d.d_inv[321];
  work1d.v[322] = 0;
  work1d.d[322] = work1d.v[322];
  if (work1d.d[322] > 0)
    work1d.d[322] = -settings1d.kkt_reg;
  else
    work1d.d[322] -= settings1d.kkt_reg;
  work1d.d_inv[322] = 1/work1d.d[322];
  work1d.L[217] = (work1d.KKT[642])*work1d.d_inv[322];
  work1d.v[323] = 0;
  work1d.d[323] = work1d.v[323];
  if (work1d.d[323] < 0)
    work1d.d[323] = settings1d.kkt_reg;
  else
    work1d.d[323] += settings1d.kkt_reg;
  work1d.d_inv[323] = 1/work1d.d[323];
  work1d.L[160] = (work1d.KKT[643])*work1d.d_inv[323];
  work1d.v[323] = work1d.L[160]*work1d.d[323];
  work1d.v[324] = 0-work1d.L[160]*work1d.v[323];
  work1d.d[324] = work1d.v[324];
  if (work1d.d[324] > 0)
    work1d.d[324] = -settings1d.kkt_reg;
  else
    work1d.d[324] -= settings1d.kkt_reg;
  work1d.d_inv[324] = 1/work1d.d[324];
  work1d.L[221] = (work1d.KKT[644])*work1d.d_inv[324];
  work1d.v[325] = work1d.KKT[645];
  work1d.d[325] = work1d.v[325];
  if (work1d.d[325] < 0)
    work1d.d[325] = settings1d.kkt_reg;
  else
    work1d.d[325] += settings1d.kkt_reg;
  work1d.d_inv[325] = 1/work1d.d[325];
  work1d.L[172] = (work1d.KKT[646])*work1d.d_inv[325];
  work1d.v[326] = work1d.KKT[647];
  work1d.d[326] = work1d.v[326];
  if (work1d.d[326] < 0)
    work1d.d[326] = settings1d.kkt_reg;
  else
    work1d.d[326] += settings1d.kkt_reg;
  work1d.d_inv[326] = 1/work1d.d[326];
  work1d.L[173] = (work1d.KKT[648])*work1d.d_inv[326];
  work1d.v[327] = work1d.KKT[649];
  work1d.d[327] = work1d.v[327];
  if (work1d.d[327] < 0)
    work1d.d[327] = settings1d.kkt_reg;
  else
    work1d.d[327] += settings1d.kkt_reg;
  work1d.d_inv[327] = 1/work1d.d[327];
  work1d.L[174] = (work1d.KKT[650])*work1d.d_inv[327];
  work1d.v[328] = work1d.KKT[651];
  work1d.d[328] = work1d.v[328];
  if (work1d.d[328] < 0)
    work1d.d[328] = settings1d.kkt_reg;
  else
    work1d.d[328] += settings1d.kkt_reg;
  work1d.d_inv[328] = 1/work1d.d[328];
  work1d.L[175] = (work1d.KKT[652])*work1d.d_inv[328];
  work1d.v[329] = work1d.KKT[653];
  work1d.d[329] = work1d.v[329];
  if (work1d.d[329] < 0)
    work1d.d[329] = settings1d.kkt_reg;
  else
    work1d.d[329] += settings1d.kkt_reg;
  work1d.d_inv[329] = 1/work1d.d[329];
  work1d.L[176] = (work1d.KKT[654])*work1d.d_inv[329];
  work1d.v[330] = work1d.KKT[655];
  work1d.d[330] = work1d.v[330];
  if (work1d.d[330] < 0)
    work1d.d[330] = settings1d.kkt_reg;
  else
    work1d.d[330] += settings1d.kkt_reg;
  work1d.d_inv[330] = 1/work1d.d[330];
  work1d.L[177] = (work1d.KKT[656])*work1d.d_inv[330];
  work1d.v[331] = work1d.KKT[657];
  work1d.d[331] = work1d.v[331];
  if (work1d.d[331] < 0)
    work1d.d[331] = settings1d.kkt_reg;
  else
    work1d.d[331] += settings1d.kkt_reg;
  work1d.d_inv[331] = 1/work1d.d[331];
  work1d.L[178] = (work1d.KKT[658])*work1d.d_inv[331];
  work1d.v[332] = work1d.KKT[659];
  work1d.d[332] = work1d.v[332];
  if (work1d.d[332] < 0)
    work1d.d[332] = settings1d.kkt_reg;
  else
    work1d.d[332] += settings1d.kkt_reg;
  work1d.d_inv[332] = 1/work1d.d[332];
  work1d.L[179] = (work1d.KKT[660])*work1d.d_inv[332];
  work1d.v[333] = work1d.KKT[661];
  work1d.d[333] = work1d.v[333];
  if (work1d.d[333] < 0)
    work1d.d[333] = settings1d.kkt_reg;
  else
    work1d.d[333] += settings1d.kkt_reg;
  work1d.d_inv[333] = 1/work1d.d[333];
  work1d.L[180] = (work1d.KKT[662])*work1d.d_inv[333];
  work1d.v[334] = work1d.KKT[663];
  work1d.d[334] = work1d.v[334];
  if (work1d.d[334] < 0)
    work1d.d[334] = settings1d.kkt_reg;
  else
    work1d.d[334] += settings1d.kkt_reg;
  work1d.d_inv[334] = 1/work1d.d[334];
  work1d.L[181] = (work1d.KKT[664])*work1d.d_inv[334];
  work1d.v[335] = work1d.KKT[665];
  work1d.d[335] = work1d.v[335];
  if (work1d.d[335] < 0)
    work1d.d[335] = settings1d.kkt_reg;
  else
    work1d.d[335] += settings1d.kkt_reg;
  work1d.d_inv[335] = 1/work1d.d[335];
  work1d.L[182] = (work1d.KKT[666])*work1d.d_inv[335];
  work1d.v[336] = work1d.KKT[667];
  work1d.d[336] = work1d.v[336];
  if (work1d.d[336] < 0)
    work1d.d[336] = settings1d.kkt_reg;
  else
    work1d.d[336] += settings1d.kkt_reg;
  work1d.d_inv[336] = 1/work1d.d[336];
  work1d.L[183] = (work1d.KKT[668])*work1d.d_inv[336];
  work1d.v[337] = work1d.KKT[669];
  work1d.d[337] = work1d.v[337];
  if (work1d.d[337] < 0)
    work1d.d[337] = settings1d.kkt_reg;
  else
    work1d.d[337] += settings1d.kkt_reg;
  work1d.d_inv[337] = 1/work1d.d[337];
  work1d.L[184] = (work1d.KKT[670])*work1d.d_inv[337];
  work1d.v[338] = work1d.KKT[671];
  work1d.d[338] = work1d.v[338];
  if (work1d.d[338] < 0)
    work1d.d[338] = settings1d.kkt_reg;
  else
    work1d.d[338] += settings1d.kkt_reg;
  work1d.d_inv[338] = 1/work1d.d[338];
  work1d.L[185] = (work1d.KKT[672])*work1d.d_inv[338];
  work1d.v[339] = work1d.KKT[673];
  work1d.d[339] = work1d.v[339];
  if (work1d.d[339] < 0)
    work1d.d[339] = settings1d.kkt_reg;
  else
    work1d.d[339] += settings1d.kkt_reg;
  work1d.d_inv[339] = 1/work1d.d[339];
  work1d.L[186] = (work1d.KKT[674])*work1d.d_inv[339];
  work1d.v[340] = work1d.KKT[675];
  work1d.d[340] = work1d.v[340];
  if (work1d.d[340] < 0)
    work1d.d[340] = settings1d.kkt_reg;
  else
    work1d.d[340] += settings1d.kkt_reg;
  work1d.d_inv[340] = 1/work1d.d[340];
  work1d.L[187] = (work1d.KKT[676])*work1d.d_inv[340];
  work1d.v[341] = work1d.KKT[677];
  work1d.d[341] = work1d.v[341];
  if (work1d.d[341] < 0)
    work1d.d[341] = settings1d.kkt_reg;
  else
    work1d.d[341] += settings1d.kkt_reg;
  work1d.d_inv[341] = 1/work1d.d[341];
  work1d.L[188] = (work1d.KKT[678])*work1d.d_inv[341];
  work1d.v[342] = work1d.KKT[679];
  work1d.d[342] = work1d.v[342];
  if (work1d.d[342] < 0)
    work1d.d[342] = settings1d.kkt_reg;
  else
    work1d.d[342] += settings1d.kkt_reg;
  work1d.d_inv[342] = 1/work1d.d[342];
  work1d.L[189] = (work1d.KKT[680])*work1d.d_inv[342];
  work1d.v[343] = work1d.KKT[681];
  work1d.d[343] = work1d.v[343];
  if (work1d.d[343] < 0)
    work1d.d[343] = settings1d.kkt_reg;
  else
    work1d.d[343] += settings1d.kkt_reg;
  work1d.d_inv[343] = 1/work1d.d[343];
  work1d.L[190] = (work1d.KKT[682])*work1d.d_inv[343];
  work1d.v[344] = work1d.KKT[683];
  work1d.d[344] = work1d.v[344];
  if (work1d.d[344] < 0)
    work1d.d[344] = settings1d.kkt_reg;
  else
    work1d.d[344] += settings1d.kkt_reg;
  work1d.d_inv[344] = 1/work1d.d[344];
  work1d.L[191] = (work1d.KKT[684])*work1d.d_inv[344];
  work1d.v[345] = work1d.KKT[685];
  work1d.d[345] = work1d.v[345];
  if (work1d.d[345] < 0)
    work1d.d[345] = settings1d.kkt_reg;
  else
    work1d.d[345] += settings1d.kkt_reg;
  work1d.d_inv[345] = 1/work1d.d[345];
  work1d.L[192] = (work1d.KKT[686])*work1d.d_inv[345];
  work1d.v[346] = work1d.KKT[687];
  work1d.d[346] = work1d.v[346];
  if (work1d.d[346] < 0)
    work1d.d[346] = settings1d.kkt_reg;
  else
    work1d.d[346] += settings1d.kkt_reg;
  work1d.d_inv[346] = 1/work1d.d[346];
  work1d.L[193] = (work1d.KKT[688])*work1d.d_inv[346];
  work1d.v[347] = work1d.KKT[689];
  work1d.d[347] = work1d.v[347];
  if (work1d.d[347] < 0)
    work1d.d[347] = settings1d.kkt_reg;
  else
    work1d.d[347] += settings1d.kkt_reg;
  work1d.d_inv[347] = 1/work1d.d[347];
  work1d.L[194] = (work1d.KKT[690])*work1d.d_inv[347];
  work1d.v[348] = work1d.KKT[691];
  work1d.d[348] = work1d.v[348];
  if (work1d.d[348] < 0)
    work1d.d[348] = settings1d.kkt_reg;
  else
    work1d.d[348] += settings1d.kkt_reg;
  work1d.d_inv[348] = 1/work1d.d[348];
  work1d.L[195] = (work1d.KKT[692])*work1d.d_inv[348];
  work1d.v[349] = work1d.KKT[693];
  work1d.d[349] = work1d.v[349];
  if (work1d.d[349] < 0)
    work1d.d[349] = settings1d.kkt_reg;
  else
    work1d.d[349] += settings1d.kkt_reg;
  work1d.d_inv[349] = 1/work1d.d[349];
  work1d.L[196] = (work1d.KKT[694])*work1d.d_inv[349];
  work1d.v[350] = work1d.KKT[695];
  work1d.d[350] = work1d.v[350];
  if (work1d.d[350] < 0)
    work1d.d[350] = settings1d.kkt_reg;
  else
    work1d.d[350] += settings1d.kkt_reg;
  work1d.d_inv[350] = 1/work1d.d[350];
  work1d.L[197] = (work1d.KKT[696])*work1d.d_inv[350];
  work1d.v[351] = work1d.KKT[697];
  work1d.d[351] = work1d.v[351];
  if (work1d.d[351] < 0)
    work1d.d[351] = settings1d.kkt_reg;
  else
    work1d.d[351] += settings1d.kkt_reg;
  work1d.d_inv[351] = 1/work1d.d[351];
  work1d.L[198] = (work1d.KKT[698])*work1d.d_inv[351];
  work1d.v[352] = work1d.KKT[699];
  work1d.d[352] = work1d.v[352];
  if (work1d.d[352] < 0)
    work1d.d[352] = settings1d.kkt_reg;
  else
    work1d.d[352] += settings1d.kkt_reg;
  work1d.d_inv[352] = 1/work1d.d[352];
  work1d.L[199] = (work1d.KKT[700])*work1d.d_inv[352];
  work1d.v[353] = work1d.KKT[701];
  work1d.d[353] = work1d.v[353];
  if (work1d.d[353] < 0)
    work1d.d[353] = settings1d.kkt_reg;
  else
    work1d.d[353] += settings1d.kkt_reg;
  work1d.d_inv[353] = 1/work1d.d[353];
  work1d.L[200] = (work1d.KKT[702])*work1d.d_inv[353];
  work1d.v[354] = work1d.KKT[703];
  work1d.d[354] = work1d.v[354];
  if (work1d.d[354] < 0)
    work1d.d[354] = settings1d.kkt_reg;
  else
    work1d.d[354] += settings1d.kkt_reg;
  work1d.d_inv[354] = 1/work1d.d[354];
  work1d.L[201] = (work1d.KKT[704])*work1d.d_inv[354];
  work1d.v[355] = work1d.KKT[705];
  work1d.d[355] = work1d.v[355];
  if (work1d.d[355] < 0)
    work1d.d[355] = settings1d.kkt_reg;
  else
    work1d.d[355] += settings1d.kkt_reg;
  work1d.d_inv[355] = 1/work1d.d[355];
  work1d.L[202] = (work1d.KKT[706])*work1d.d_inv[355];
  work1d.v[356] = work1d.KKT[707];
  work1d.d[356] = work1d.v[356];
  if (work1d.d[356] < 0)
    work1d.d[356] = settings1d.kkt_reg;
  else
    work1d.d[356] += settings1d.kkt_reg;
  work1d.d_inv[356] = 1/work1d.d[356];
  work1d.L[203] = (work1d.KKT[708])*work1d.d_inv[356];
  work1d.v[357] = work1d.KKT[709];
  work1d.d[357] = work1d.v[357];
  if (work1d.d[357] < 0)
    work1d.d[357] = settings1d.kkt_reg;
  else
    work1d.d[357] += settings1d.kkt_reg;
  work1d.d_inv[357] = 1/work1d.d[357];
  work1d.L[204] = (work1d.KKT[710])*work1d.d_inv[357];
  work1d.v[358] = work1d.KKT[711];
  work1d.d[358] = work1d.v[358];
  if (work1d.d[358] < 0)
    work1d.d[358] = settings1d.kkt_reg;
  else
    work1d.d[358] += settings1d.kkt_reg;
  work1d.d_inv[358] = 1/work1d.d[358];
  work1d.L[205] = (work1d.KKT[712])*work1d.d_inv[358];
  work1d.v[359] = work1d.KKT[713];
  work1d.d[359] = work1d.v[359];
  if (work1d.d[359] < 0)
    work1d.d[359] = settings1d.kkt_reg;
  else
    work1d.d[359] += settings1d.kkt_reg;
  work1d.d_inv[359] = 1/work1d.d[359];
  work1d.L[206] = (work1d.KKT[714])*work1d.d_inv[359];
  work1d.v[360] = work1d.KKT[715];
  work1d.d[360] = work1d.v[360];
  if (work1d.d[360] < 0)
    work1d.d[360] = settings1d.kkt_reg;
  else
    work1d.d[360] += settings1d.kkt_reg;
  work1d.d_inv[360] = 1/work1d.d[360];
  work1d.L[207] = (work1d.KKT[716])*work1d.d_inv[360];
  work1d.v[361] = work1d.KKT[717];
  work1d.d[361] = work1d.v[361];
  if (work1d.d[361] < 0)
    work1d.d[361] = settings1d.kkt_reg;
  else
    work1d.d[361] += settings1d.kkt_reg;
  work1d.d_inv[361] = 1/work1d.d[361];
  work1d.L[208] = (work1d.KKT[718])*work1d.d_inv[361];
  work1d.v[362] = work1d.KKT[719];
  work1d.d[362] = work1d.v[362];
  if (work1d.d[362] < 0)
    work1d.d[362] = settings1d.kkt_reg;
  else
    work1d.d[362] += settings1d.kkt_reg;
  work1d.d_inv[362] = 1/work1d.d[362];
  work1d.L[209] = (work1d.KKT[720])*work1d.d_inv[362];
  work1d.v[363] = work1d.KKT[721];
  work1d.d[363] = work1d.v[363];
  if (work1d.d[363] < 0)
    work1d.d[363] = settings1d.kkt_reg;
  else
    work1d.d[363] += settings1d.kkt_reg;
  work1d.d_inv[363] = 1/work1d.d[363];
  work1d.L[163] = (work1d.KKT[722])*work1d.d_inv[363];
  work1d.v[240] = work1d.L[161]*work1d.d[240];
  work1d.v[320] = work1d.L[162]*work1d.d[320];
  work1d.v[364] = work1d.KKT[723]-work1d.L[161]*work1d.v[240]-work1d.L[162]*work1d.v[320];
  work1d.d[364] = work1d.v[364];
  if (work1d.d[364] < 0)
    work1d.d[364] = settings1d.kkt_reg;
  else
    work1d.d[364] += settings1d.kkt_reg;
  work1d.d_inv[364] = 1/work1d.d[364];
  work1d.L[164] = (work1d.KKT[724])*work1d.d_inv[364];
  work1d.v[363] = work1d.L[163]*work1d.d[363];
  work1d.v[364] = work1d.L[164]*work1d.d[364];
  work1d.v[365] = 0-work1d.L[163]*work1d.v[363]-work1d.L[164]*work1d.v[364];
  work1d.d[365] = work1d.v[365];
  if (work1d.d[365] > 0)
    work1d.d[365] = -settings1d.kkt_reg;
  else
    work1d.d[365] -= settings1d.kkt_reg;
  work1d.d_inv[365] = 1/work1d.d[365];
  work1d.L[170] = (work1d.KKT[725])*work1d.d_inv[365];
  work1d.v[321] = work1d.L[165]*work1d.d[321];
  work1d.v[366] = work1d.KKT[726]-work1d.L[165]*work1d.v[321];
  work1d.d[366] = work1d.v[366];
  if (work1d.d[366] < 0)
    work1d.d[366] = settings1d.kkt_reg;
  else
    work1d.d[366] += settings1d.kkt_reg;
  work1d.d_inv[366] = 1/work1d.d[366];
  work1d.L[171] = (work1d.KKT[727])*work1d.d_inv[366];
  work1d.v[367] = work1d.KKT[728];
  work1d.d[367] = work1d.v[367];
  if (work1d.d[367] < 0)
    work1d.d[367] = settings1d.kkt_reg;
  else
    work1d.d[367] += settings1d.kkt_reg;
  work1d.d_inv[367] = 1/work1d.d[367];
  work1d.L[211] = (work1d.KKT[729])*work1d.d_inv[367];
  work1d.v[200] = work1d.L[166]*work1d.d[200];
  work1d.v[280] = work1d.L[167]*work1d.d[280];
  work1d.v[368] = work1d.KKT[730]-work1d.L[166]*work1d.v[200]-work1d.L[167]*work1d.v[280];
  work1d.d[368] = work1d.v[368];
  if (work1d.d[368] < 0)
    work1d.d[368] = settings1d.kkt_reg;
  else
    work1d.d[368] += settings1d.kkt_reg;
  work1d.d_inv[368] = 1/work1d.d[368];
  work1d.L[212] = (work1d.KKT[731])*work1d.d_inv[368];
  work1d.v[239] = work1d.L[168]*work1d.d[239];
  work1d.v[319] = work1d.L[169]*work1d.d[319];
  work1d.v[365] = work1d.L[170]*work1d.d[365];
  work1d.v[369] = work1d.KKT[732]-work1d.L[168]*work1d.v[239]-work1d.L[169]*work1d.v[319]-work1d.L[170]*work1d.v[365];
  work1d.d[369] = work1d.v[369];
  if (work1d.d[369] < 0)
    work1d.d[369] = settings1d.kkt_reg;
  else
    work1d.d[369] += settings1d.kkt_reg;
  work1d.d_inv[369] = 1/work1d.d[369];
  work1d.L[210] = (work1d.KKT[733])*work1d.d_inv[369];
  work1d.L[213] = (work1d.KKT[734])*work1d.d_inv[369];
  work1d.v[366] = work1d.L[171]*work1d.d[366];
  work1d.v[370] = 0-work1d.L[171]*work1d.v[366];
  work1d.d[370] = work1d.v[370];
  if (work1d.d[370] > 0)
    work1d.d[370] = -settings1d.kkt_reg;
  else
    work1d.d[370] -= settings1d.kkt_reg;
  work1d.d_inv[370] = 1/work1d.d[370];
  work1d.L[218] = (work1d.KKT[735])*work1d.d_inv[370];
  work1d.L[223] = (work1d.KKT[736])*work1d.d_inv[370];
  work1d.v[325] = work1d.L[172]*work1d.d[325];
  work1d.v[371] = 0-work1d.L[172]*work1d.v[325];
  work1d.d[371] = work1d.v[371];
  if (work1d.d[371] > 0)
    work1d.d[371] = -settings1d.kkt_reg;
  else
    work1d.d[371] -= settings1d.kkt_reg;
  work1d.d_inv[371] = 1/work1d.d[371];
  work1d.L[222] = (work1d.KKT[737])*work1d.d_inv[371];
  work1d.L[234] = (work1d.KKT[738])*work1d.d_inv[371];
  work1d.v[326] = work1d.L[173]*work1d.d[326];
  work1d.v[372] = 0-work1d.L[173]*work1d.v[326];
  work1d.d[372] = work1d.v[372];
  if (work1d.d[372] > 0)
    work1d.d[372] = -settings1d.kkt_reg;
  else
    work1d.d[372] -= settings1d.kkt_reg;
  work1d.d_inv[372] = 1/work1d.d[372];
  work1d.L[235] = (work1d.KKT[739])*work1d.d_inv[372];
  work1d.L[252] = (work1d.KKT[740])*work1d.d_inv[372];
  work1d.v[327] = work1d.L[174]*work1d.d[327];
  work1d.v[373] = 0-work1d.L[174]*work1d.v[327];
  work1d.d[373] = work1d.v[373];
  if (work1d.d[373] > 0)
    work1d.d[373] = -settings1d.kkt_reg;
  else
    work1d.d[373] -= settings1d.kkt_reg;
  work1d.d_inv[373] = 1/work1d.d[373];
  work1d.L[253] = (work1d.KKT[741])*work1d.d_inv[373];
  work1d.L[272] = (work1d.KKT[742])*work1d.d_inv[373];
  work1d.v[328] = work1d.L[175]*work1d.d[328];
  work1d.v[374] = 0-work1d.L[175]*work1d.v[328];
  work1d.d[374] = work1d.v[374];
  if (work1d.d[374] > 0)
    work1d.d[374] = -settings1d.kkt_reg;
  else
    work1d.d[374] -= settings1d.kkt_reg;
  work1d.d_inv[374] = 1/work1d.d[374];
  work1d.L[273] = (work1d.KKT[743])*work1d.d_inv[374];
  work1d.L[292] = (work1d.KKT[744])*work1d.d_inv[374];
  work1d.v[329] = work1d.L[176]*work1d.d[329];
  work1d.v[375] = 0-work1d.L[176]*work1d.v[329];
  work1d.d[375] = work1d.v[375];
  if (work1d.d[375] > 0)
    work1d.d[375] = -settings1d.kkt_reg;
  else
    work1d.d[375] -= settings1d.kkt_reg;
  work1d.d_inv[375] = 1/work1d.d[375];
  work1d.L[293] = (work1d.KKT[745])*work1d.d_inv[375];
  work1d.L[312] = (work1d.KKT[746])*work1d.d_inv[375];
  work1d.v[330] = work1d.L[177]*work1d.d[330];
  work1d.v[376] = 0-work1d.L[177]*work1d.v[330];
  work1d.d[376] = work1d.v[376];
  if (work1d.d[376] > 0)
    work1d.d[376] = -settings1d.kkt_reg;
  else
    work1d.d[376] -= settings1d.kkt_reg;
  work1d.d_inv[376] = 1/work1d.d[376];
  work1d.L[313] = (work1d.KKT[747])*work1d.d_inv[376];
  work1d.L[332] = (work1d.KKT[748])*work1d.d_inv[376];
  work1d.v[331] = work1d.L[178]*work1d.d[331];
  work1d.v[377] = 0-work1d.L[178]*work1d.v[331];
  work1d.d[377] = work1d.v[377];
  if (work1d.d[377] > 0)
    work1d.d[377] = -settings1d.kkt_reg;
  else
    work1d.d[377] -= settings1d.kkt_reg;
  work1d.d_inv[377] = 1/work1d.d[377];
  work1d.L[333] = (work1d.KKT[749])*work1d.d_inv[377];
  work1d.L[352] = (work1d.KKT[750])*work1d.d_inv[377];
  work1d.v[332] = work1d.L[179]*work1d.d[332];
  work1d.v[378] = 0-work1d.L[179]*work1d.v[332];
  work1d.d[378] = work1d.v[378];
  if (work1d.d[378] > 0)
    work1d.d[378] = -settings1d.kkt_reg;
  else
    work1d.d[378] -= settings1d.kkt_reg;
  work1d.d_inv[378] = 1/work1d.d[378];
  work1d.L[353] = (work1d.KKT[751])*work1d.d_inv[378];
  work1d.L[372] = (work1d.KKT[752])*work1d.d_inv[378];
  work1d.v[333] = work1d.L[180]*work1d.d[333];
  work1d.v[379] = 0-work1d.L[180]*work1d.v[333];
  work1d.d[379] = work1d.v[379];
  if (work1d.d[379] > 0)
    work1d.d[379] = -settings1d.kkt_reg;
  else
    work1d.d[379] -= settings1d.kkt_reg;
  work1d.d_inv[379] = 1/work1d.d[379];
  work1d.L[373] = (work1d.KKT[753])*work1d.d_inv[379];
  work1d.L[392] = (work1d.KKT[754])*work1d.d_inv[379];
  work1d.v[334] = work1d.L[181]*work1d.d[334];
  work1d.v[380] = 0-work1d.L[181]*work1d.v[334];
  work1d.d[380] = work1d.v[380];
  if (work1d.d[380] > 0)
    work1d.d[380] = -settings1d.kkt_reg;
  else
    work1d.d[380] -= settings1d.kkt_reg;
  work1d.d_inv[380] = 1/work1d.d[380];
  work1d.L[393] = (work1d.KKT[755])*work1d.d_inv[380];
  work1d.L[412] = (work1d.KKT[756])*work1d.d_inv[380];
  work1d.v[335] = work1d.L[182]*work1d.d[335];
  work1d.v[381] = 0-work1d.L[182]*work1d.v[335];
  work1d.d[381] = work1d.v[381];
  if (work1d.d[381] > 0)
    work1d.d[381] = -settings1d.kkt_reg;
  else
    work1d.d[381] -= settings1d.kkt_reg;
  work1d.d_inv[381] = 1/work1d.d[381];
  work1d.L[413] = (work1d.KKT[757])*work1d.d_inv[381];
  work1d.L[432] = (work1d.KKT[758])*work1d.d_inv[381];
  work1d.v[336] = work1d.L[183]*work1d.d[336];
  work1d.v[382] = 0-work1d.L[183]*work1d.v[336];
  work1d.d[382] = work1d.v[382];
  if (work1d.d[382] > 0)
    work1d.d[382] = -settings1d.kkt_reg;
  else
    work1d.d[382] -= settings1d.kkt_reg;
  work1d.d_inv[382] = 1/work1d.d[382];
  work1d.L[433] = (work1d.KKT[759])*work1d.d_inv[382];
  work1d.L[452] = (work1d.KKT[760])*work1d.d_inv[382];
  work1d.v[337] = work1d.L[184]*work1d.d[337];
  work1d.v[383] = 0-work1d.L[184]*work1d.v[337];
  work1d.d[383] = work1d.v[383];
  if (work1d.d[383] > 0)
    work1d.d[383] = -settings1d.kkt_reg;
  else
    work1d.d[383] -= settings1d.kkt_reg;
  work1d.d_inv[383] = 1/work1d.d[383];
  work1d.L[453] = (work1d.KKT[761])*work1d.d_inv[383];
  work1d.L[472] = (work1d.KKT[762])*work1d.d_inv[383];
  work1d.v[338] = work1d.L[185]*work1d.d[338];
  work1d.v[384] = 0-work1d.L[185]*work1d.v[338];
  work1d.d[384] = work1d.v[384];
  if (work1d.d[384] > 0)
    work1d.d[384] = -settings1d.kkt_reg;
  else
    work1d.d[384] -= settings1d.kkt_reg;
  work1d.d_inv[384] = 1/work1d.d[384];
  work1d.L[473] = (work1d.KKT[763])*work1d.d_inv[384];
  work1d.L[492] = (work1d.KKT[764])*work1d.d_inv[384];
  work1d.v[339] = work1d.L[186]*work1d.d[339];
  work1d.v[385] = 0-work1d.L[186]*work1d.v[339];
  work1d.d[385] = work1d.v[385];
  if (work1d.d[385] > 0)
    work1d.d[385] = -settings1d.kkt_reg;
  else
    work1d.d[385] -= settings1d.kkt_reg;
  work1d.d_inv[385] = 1/work1d.d[385];
  work1d.L[493] = (work1d.KKT[765])*work1d.d_inv[385];
  work1d.L[512] = (work1d.KKT[766])*work1d.d_inv[385];
  work1d.v[340] = work1d.L[187]*work1d.d[340];
  work1d.v[386] = 0-work1d.L[187]*work1d.v[340];
  work1d.d[386] = work1d.v[386];
  if (work1d.d[386] > 0)
    work1d.d[386] = -settings1d.kkt_reg;
  else
    work1d.d[386] -= settings1d.kkt_reg;
  work1d.d_inv[386] = 1/work1d.d[386];
  work1d.L[513] = (work1d.KKT[767])*work1d.d_inv[386];
  work1d.L[532] = (work1d.KKT[768])*work1d.d_inv[386];
  work1d.v[341] = work1d.L[188]*work1d.d[341];
  work1d.v[387] = 0-work1d.L[188]*work1d.v[341];
  work1d.d[387] = work1d.v[387];
  if (work1d.d[387] > 0)
    work1d.d[387] = -settings1d.kkt_reg;
  else
    work1d.d[387] -= settings1d.kkt_reg;
  work1d.d_inv[387] = 1/work1d.d[387];
  work1d.L[533] = (work1d.KKT[769])*work1d.d_inv[387];
  work1d.L[552] = (work1d.KKT[770])*work1d.d_inv[387];
  work1d.v[342] = work1d.L[189]*work1d.d[342];
  work1d.v[388] = 0-work1d.L[189]*work1d.v[342];
  work1d.d[388] = work1d.v[388];
  if (work1d.d[388] > 0)
    work1d.d[388] = -settings1d.kkt_reg;
  else
    work1d.d[388] -= settings1d.kkt_reg;
  work1d.d_inv[388] = 1/work1d.d[388];
  work1d.L[553] = (work1d.KKT[771])*work1d.d_inv[388];
  work1d.L[572] = (work1d.KKT[772])*work1d.d_inv[388];
  work1d.v[343] = work1d.L[190]*work1d.d[343];
  work1d.v[389] = 0-work1d.L[190]*work1d.v[343];
  work1d.d[389] = work1d.v[389];
  if (work1d.d[389] > 0)
    work1d.d[389] = -settings1d.kkt_reg;
  else
    work1d.d[389] -= settings1d.kkt_reg;
  work1d.d_inv[389] = 1/work1d.d[389];
  work1d.L[573] = (work1d.KKT[773])*work1d.d_inv[389];
  work1d.L[592] = (work1d.KKT[774])*work1d.d_inv[389];
  work1d.v[344] = work1d.L[191]*work1d.d[344];
  work1d.v[390] = 0-work1d.L[191]*work1d.v[344];
  work1d.d[390] = work1d.v[390];
  if (work1d.d[390] > 0)
    work1d.d[390] = -settings1d.kkt_reg;
  else
    work1d.d[390] -= settings1d.kkt_reg;
  work1d.d_inv[390] = 1/work1d.d[390];
  work1d.L[593] = (work1d.KKT[775])*work1d.d_inv[390];
  work1d.L[612] = (work1d.KKT[776])*work1d.d_inv[390];
  work1d.v[345] = work1d.L[192]*work1d.d[345];
  work1d.v[391] = 0-work1d.L[192]*work1d.v[345];
  work1d.d[391] = work1d.v[391];
  if (work1d.d[391] > 0)
    work1d.d[391] = -settings1d.kkt_reg;
  else
    work1d.d[391] -= settings1d.kkt_reg;
  work1d.d_inv[391] = 1/work1d.d[391];
  work1d.L[613] = (work1d.KKT[777])*work1d.d_inv[391];
  work1d.L[632] = (work1d.KKT[778])*work1d.d_inv[391];
  work1d.v[346] = work1d.L[193]*work1d.d[346];
  work1d.v[392] = 0-work1d.L[193]*work1d.v[346];
  work1d.d[392] = work1d.v[392];
  if (work1d.d[392] > 0)
    work1d.d[392] = -settings1d.kkt_reg;
  else
    work1d.d[392] -= settings1d.kkt_reg;
  work1d.d_inv[392] = 1/work1d.d[392];
  work1d.L[633] = (work1d.KKT[779])*work1d.d_inv[392];
  work1d.L[652] = (work1d.KKT[780])*work1d.d_inv[392];
  work1d.v[347] = work1d.L[194]*work1d.d[347];
  work1d.v[393] = 0-work1d.L[194]*work1d.v[347];
  work1d.d[393] = work1d.v[393];
  if (work1d.d[393] > 0)
    work1d.d[393] = -settings1d.kkt_reg;
  else
    work1d.d[393] -= settings1d.kkt_reg;
  work1d.d_inv[393] = 1/work1d.d[393];
  work1d.L[653] = (work1d.KKT[781])*work1d.d_inv[393];
  work1d.L[672] = (work1d.KKT[782])*work1d.d_inv[393];
  work1d.v[348] = work1d.L[195]*work1d.d[348];
  work1d.v[394] = 0-work1d.L[195]*work1d.v[348];
  work1d.d[394] = work1d.v[394];
  if (work1d.d[394] > 0)
    work1d.d[394] = -settings1d.kkt_reg;
  else
    work1d.d[394] -= settings1d.kkt_reg;
  work1d.d_inv[394] = 1/work1d.d[394];
  work1d.L[673] = (work1d.KKT[783])*work1d.d_inv[394];
  work1d.L[692] = (work1d.KKT[784])*work1d.d_inv[394];
  work1d.v[349] = work1d.L[196]*work1d.d[349];
  work1d.v[395] = 0-work1d.L[196]*work1d.v[349];
  work1d.d[395] = work1d.v[395];
  if (work1d.d[395] > 0)
    work1d.d[395] = -settings1d.kkt_reg;
  else
    work1d.d[395] -= settings1d.kkt_reg;
  work1d.d_inv[395] = 1/work1d.d[395];
  work1d.L[693] = (work1d.KKT[785])*work1d.d_inv[395];
  work1d.L[712] = (work1d.KKT[786])*work1d.d_inv[395];
  work1d.v[350] = work1d.L[197]*work1d.d[350];
  work1d.v[396] = 0-work1d.L[197]*work1d.v[350];
  work1d.d[396] = work1d.v[396];
  if (work1d.d[396] > 0)
    work1d.d[396] = -settings1d.kkt_reg;
  else
    work1d.d[396] -= settings1d.kkt_reg;
  work1d.d_inv[396] = 1/work1d.d[396];
  work1d.L[713] = (work1d.KKT[787])*work1d.d_inv[396];
  work1d.L[732] = (work1d.KKT[788])*work1d.d_inv[396];
  work1d.v[351] = work1d.L[198]*work1d.d[351];
  work1d.v[397] = 0-work1d.L[198]*work1d.v[351];
  work1d.d[397] = work1d.v[397];
  if (work1d.d[397] > 0)
    work1d.d[397] = -settings1d.kkt_reg;
  else
    work1d.d[397] -= settings1d.kkt_reg;
  work1d.d_inv[397] = 1/work1d.d[397];
  work1d.L[733] = (work1d.KKT[789])*work1d.d_inv[397];
  work1d.L[752] = (work1d.KKT[790])*work1d.d_inv[397];
  work1d.v[352] = work1d.L[199]*work1d.d[352];
  work1d.v[398] = 0-work1d.L[199]*work1d.v[352];
  work1d.d[398] = work1d.v[398];
  if (work1d.d[398] > 0)
    work1d.d[398] = -settings1d.kkt_reg;
  else
    work1d.d[398] -= settings1d.kkt_reg;
  work1d.d_inv[398] = 1/work1d.d[398];
  work1d.L[753] = (work1d.KKT[791])*work1d.d_inv[398];
  work1d.L[772] = (work1d.KKT[792])*work1d.d_inv[398];
  work1d.v[353] = work1d.L[200]*work1d.d[353];
  work1d.v[399] = 0-work1d.L[200]*work1d.v[353];
  work1d.d[399] = work1d.v[399];
  if (work1d.d[399] > 0)
    work1d.d[399] = -settings1d.kkt_reg;
  else
    work1d.d[399] -= settings1d.kkt_reg;
  work1d.d_inv[399] = 1/work1d.d[399];
  work1d.L[773] = (work1d.KKT[793])*work1d.d_inv[399];
  work1d.L[792] = (work1d.KKT[794])*work1d.d_inv[399];
  work1d.v[354] = work1d.L[201]*work1d.d[354];
  work1d.v[400] = 0-work1d.L[201]*work1d.v[354];
  work1d.d[400] = work1d.v[400];
  if (work1d.d[400] > 0)
    work1d.d[400] = -settings1d.kkt_reg;
  else
    work1d.d[400] -= settings1d.kkt_reg;
  work1d.d_inv[400] = 1/work1d.d[400];
  work1d.L[793] = (work1d.KKT[795])*work1d.d_inv[400];
  work1d.L[812] = (work1d.KKT[796])*work1d.d_inv[400];
  work1d.v[355] = work1d.L[202]*work1d.d[355];
  work1d.v[401] = 0-work1d.L[202]*work1d.v[355];
  work1d.d[401] = work1d.v[401];
  if (work1d.d[401] > 0)
    work1d.d[401] = -settings1d.kkt_reg;
  else
    work1d.d[401] -= settings1d.kkt_reg;
  work1d.d_inv[401] = 1/work1d.d[401];
  work1d.L[813] = (work1d.KKT[797])*work1d.d_inv[401];
  work1d.L[832] = (work1d.KKT[798])*work1d.d_inv[401];
  work1d.v[356] = work1d.L[203]*work1d.d[356];
  work1d.v[402] = 0-work1d.L[203]*work1d.v[356];
  work1d.d[402] = work1d.v[402];
  if (work1d.d[402] > 0)
    work1d.d[402] = -settings1d.kkt_reg;
  else
    work1d.d[402] -= settings1d.kkt_reg;
  work1d.d_inv[402] = 1/work1d.d[402];
  work1d.L[833] = (work1d.KKT[799])*work1d.d_inv[402];
  work1d.L[852] = (work1d.KKT[800])*work1d.d_inv[402];
  work1d.v[357] = work1d.L[204]*work1d.d[357];
  work1d.v[403] = 0-work1d.L[204]*work1d.v[357];
  work1d.d[403] = work1d.v[403];
  if (work1d.d[403] > 0)
    work1d.d[403] = -settings1d.kkt_reg;
  else
    work1d.d[403] -= settings1d.kkt_reg;
  work1d.d_inv[403] = 1/work1d.d[403];
  work1d.L[853] = (work1d.KKT[801])*work1d.d_inv[403];
  work1d.L[872] = (work1d.KKT[802])*work1d.d_inv[403];
  work1d.v[358] = work1d.L[205]*work1d.d[358];
  work1d.v[404] = 0-work1d.L[205]*work1d.v[358];
  work1d.d[404] = work1d.v[404];
  if (work1d.d[404] > 0)
    work1d.d[404] = -settings1d.kkt_reg;
  else
    work1d.d[404] -= settings1d.kkt_reg;
  work1d.d_inv[404] = 1/work1d.d[404];
  work1d.L[873] = (work1d.KKT[803])*work1d.d_inv[404];
  work1d.L[892] = (work1d.KKT[804])*work1d.d_inv[404];
  work1d.v[359] = work1d.L[206]*work1d.d[359];
  work1d.v[405] = 0-work1d.L[206]*work1d.v[359];
  work1d.d[405] = work1d.v[405];
  if (work1d.d[405] > 0)
    work1d.d[405] = -settings1d.kkt_reg;
  else
    work1d.d[405] -= settings1d.kkt_reg;
  work1d.d_inv[405] = 1/work1d.d[405];
  work1d.L[893] = (work1d.KKT[805])*work1d.d_inv[405];
  work1d.L[912] = (work1d.KKT[806])*work1d.d_inv[405];
  work1d.v[360] = work1d.L[207]*work1d.d[360];
  work1d.v[406] = 0-work1d.L[207]*work1d.v[360];
  work1d.d[406] = work1d.v[406];
  if (work1d.d[406] > 0)
    work1d.d[406] = -settings1d.kkt_reg;
  else
    work1d.d[406] -= settings1d.kkt_reg;
  work1d.d_inv[406] = 1/work1d.d[406];
  work1d.L[913] = (work1d.KKT[807])*work1d.d_inv[406];
  work1d.L[932] = (work1d.KKT[808])*work1d.d_inv[406];
  work1d.v[361] = work1d.L[208]*work1d.d[361];
  work1d.v[407] = 0-work1d.L[208]*work1d.v[361];
  work1d.d[407] = work1d.v[407];
  if (work1d.d[407] > 0)
    work1d.d[407] = -settings1d.kkt_reg;
  else
    work1d.d[407] -= settings1d.kkt_reg;
  work1d.d_inv[407] = 1/work1d.d[407];
  work1d.L[933] = (work1d.KKT[809])*work1d.d_inv[407];
  work1d.L[958] = (work1d.KKT[810])*work1d.d_inv[407];
  work1d.v[362] = work1d.L[209]*work1d.d[362];
  work1d.v[369] = work1d.L[210]*work1d.d[369];
  work1d.v[408] = 0-work1d.L[209]*work1d.v[362]-work1d.L[210]*work1d.v[369];
  work1d.d[408] = work1d.v[408];
  if (work1d.d[408] > 0)
    work1d.d[408] = -settings1d.kkt_reg;
  else
    work1d.d[408] -= settings1d.kkt_reg;
  work1d.d_inv[408] = 1/work1d.d[408];
  work1d.L[214] = (-work1d.L[213]*work1d.v[369])*work1d.d_inv[408];
  work1d.L[959] = (work1d.KKT[811])*work1d.d_inv[408];
  work1d.v[367] = work1d.L[211]*work1d.d[367];
  work1d.v[409] = 0-work1d.L[211]*work1d.v[367];
  work1d.d[409] = work1d.v[409];
  if (work1d.d[409] > 0)
    work1d.d[409] = -settings1d.kkt_reg;
  else
    work1d.d[409] -= settings1d.kkt_reg;
  work1d.d_inv[409] = 1/work1d.d[409];
  work1d.L[225] = (work1d.KKT[812])*work1d.d_inv[409];
  work1d.L[969] = (work1d.KKT[813])*work1d.d_inv[409];
  work1d.v[368] = work1d.L[212]*work1d.d[368];
  work1d.v[369] = work1d.L[213]*work1d.d[369];
  work1d.v[408] = work1d.L[214]*work1d.d[408];
  work1d.v[410] = 0-work1d.L[212]*work1d.v[368]-work1d.L[213]*work1d.v[369]-work1d.L[214]*work1d.v[408];
  work1d.d[410] = work1d.v[410];
  if (work1d.d[410] > 0)
    work1d.d[410] = -settings1d.kkt_reg;
  else
    work1d.d[410] -= settings1d.kkt_reg;
  work1d.d_inv[410] = 1/work1d.d[410];
  work1d.L[960] = (-work1d.L[959]*work1d.v[408])*work1d.d_inv[410];
  work1d.L[970] = (work1d.KKT[814])*work1d.d_inv[410];
  work1d.v[161] = work1d.L[215]*work1d.d[161];
  work1d.v[241] = work1d.L[216]*work1d.d[241];
  work1d.v[322] = work1d.L[217]*work1d.d[322];
  work1d.v[370] = work1d.L[218]*work1d.d[370];
  work1d.v[411] = work1d.KKT[815]-work1d.L[215]*work1d.v[161]-work1d.L[216]*work1d.v[241]-work1d.L[217]*work1d.v[322]-work1d.L[218]*work1d.v[370];
  work1d.d[411] = work1d.v[411];
  if (work1d.d[411] < 0)
    work1d.d[411] = settings1d.kkt_reg;
  else
    work1d.d[411] += settings1d.kkt_reg;
  work1d.d_inv[411] = 1/work1d.d[411];
  work1d.L[224] = (-work1d.L[223]*work1d.v[370])*work1d.d_inv[411];
  work1d.L[226] = (work1d.KKT[816])*work1d.d_inv[411];
  work1d.v[201] = work1d.L[219]*work1d.d[201];
  work1d.v[281] = work1d.L[220]*work1d.d[281];
  work1d.v[324] = work1d.L[221]*work1d.d[324];
  work1d.v[371] = work1d.L[222]*work1d.d[371];
  work1d.v[412] = work1d.KKT[817]-work1d.L[219]*work1d.v[201]-work1d.L[220]*work1d.v[281]-work1d.L[221]*work1d.v[324]-work1d.L[222]*work1d.v[371];
  work1d.d[412] = work1d.v[412];
  if (work1d.d[412] < 0)
    work1d.d[412] = settings1d.kkt_reg;
  else
    work1d.d[412] += settings1d.kkt_reg;
  work1d.d_inv[412] = 1/work1d.d[412];
  work1d.L[227] = (work1d.KKT[818])*work1d.d_inv[412];
  work1d.L[236] = (-work1d.L[234]*work1d.v[371])*work1d.d_inv[412];
  work1d.v[370] = work1d.L[223]*work1d.d[370];
  work1d.v[411] = work1d.L[224]*work1d.d[411];
  work1d.v[413] = work1d.KKT[819]-work1d.L[223]*work1d.v[370]-work1d.L[224]*work1d.v[411];
  work1d.d[413] = work1d.v[413];
  if (work1d.d[413] < 0)
    work1d.d[413] = settings1d.kkt_reg;
  else
    work1d.d[413] += settings1d.kkt_reg;
  work1d.d_inv[413] = 1/work1d.d[413];
  work1d.L[228] = (-work1d.L[226]*work1d.v[411])*work1d.d_inv[413];
  work1d.L[239] = (work1d.KKT[820])*work1d.d_inv[413];
  work1d.v[414] = work1d.KKT[821];
  work1d.d[414] = work1d.v[414];
  if (work1d.d[414] < 0)
    work1d.d[414] = settings1d.kkt_reg;
  else
    work1d.d[414] += settings1d.kkt_reg;
  work1d.d_inv[414] = 1/work1d.d[414];
  work1d.L[240] = (work1d.KKT[822])*work1d.d_inv[414];
  work1d.L[258] = (work1d.KKT[823])*work1d.d_inv[414];
  work1d.v[415] = work1d.KKT[824];
  work1d.d[415] = work1d.v[415];
  if (work1d.d[415] < 0)
    work1d.d[415] = settings1d.kkt_reg;
  else
    work1d.d[415] += settings1d.kkt_reg;
  work1d.d_inv[415] = 1/work1d.d[415];
  work1d.L[259] = (work1d.KKT[825])*work1d.d_inv[415];
  work1d.L[278] = (work1d.KKT[826])*work1d.d_inv[415];
  work1d.v[416] = work1d.KKT[827];
  work1d.d[416] = work1d.v[416];
  if (work1d.d[416] < 0)
    work1d.d[416] = settings1d.kkt_reg;
  else
    work1d.d[416] += settings1d.kkt_reg;
  work1d.d_inv[416] = 1/work1d.d[416];
  work1d.L[279] = (work1d.KKT[828])*work1d.d_inv[416];
  work1d.L[298] = (work1d.KKT[829])*work1d.d_inv[416];
  work1d.v[417] = work1d.KKT[830];
  work1d.d[417] = work1d.v[417];
  if (work1d.d[417] < 0)
    work1d.d[417] = settings1d.kkt_reg;
  else
    work1d.d[417] += settings1d.kkt_reg;
  work1d.d_inv[417] = 1/work1d.d[417];
  work1d.L[299] = (work1d.KKT[831])*work1d.d_inv[417];
  work1d.L[318] = (work1d.KKT[832])*work1d.d_inv[417];
  work1d.v[418] = work1d.KKT[833];
  work1d.d[418] = work1d.v[418];
  if (work1d.d[418] < 0)
    work1d.d[418] = settings1d.kkt_reg;
  else
    work1d.d[418] += settings1d.kkt_reg;
  work1d.d_inv[418] = 1/work1d.d[418];
  work1d.L[319] = (work1d.KKT[834])*work1d.d_inv[418];
  work1d.L[338] = (work1d.KKT[835])*work1d.d_inv[418];
  work1d.v[419] = work1d.KKT[836];
  work1d.d[419] = work1d.v[419];
  if (work1d.d[419] < 0)
    work1d.d[419] = settings1d.kkt_reg;
  else
    work1d.d[419] += settings1d.kkt_reg;
  work1d.d_inv[419] = 1/work1d.d[419];
  work1d.L[339] = (work1d.KKT[837])*work1d.d_inv[419];
  work1d.L[358] = (work1d.KKT[838])*work1d.d_inv[419];
  work1d.v[420] = work1d.KKT[839];
  work1d.d[420] = work1d.v[420];
  if (work1d.d[420] < 0)
    work1d.d[420] = settings1d.kkt_reg;
  else
    work1d.d[420] += settings1d.kkt_reg;
  work1d.d_inv[420] = 1/work1d.d[420];
  work1d.L[359] = (work1d.KKT[840])*work1d.d_inv[420];
  work1d.L[378] = (work1d.KKT[841])*work1d.d_inv[420];
  work1d.v[421] = work1d.KKT[842];
  work1d.d[421] = work1d.v[421];
  if (work1d.d[421] < 0)
    work1d.d[421] = settings1d.kkt_reg;
  else
    work1d.d[421] += settings1d.kkt_reg;
  work1d.d_inv[421] = 1/work1d.d[421];
  work1d.L[379] = (work1d.KKT[843])*work1d.d_inv[421];
  work1d.L[398] = (work1d.KKT[844])*work1d.d_inv[421];
  work1d.v[422] = work1d.KKT[845];
  work1d.d[422] = work1d.v[422];
  if (work1d.d[422] < 0)
    work1d.d[422] = settings1d.kkt_reg;
  else
    work1d.d[422] += settings1d.kkt_reg;
  work1d.d_inv[422] = 1/work1d.d[422];
  work1d.L[399] = (work1d.KKT[846])*work1d.d_inv[422];
  work1d.L[418] = (work1d.KKT[847])*work1d.d_inv[422];
  work1d.v[423] = work1d.KKT[848];
  work1d.d[423] = work1d.v[423];
  if (work1d.d[423] < 0)
    work1d.d[423] = settings1d.kkt_reg;
  else
    work1d.d[423] += settings1d.kkt_reg;
  work1d.d_inv[423] = 1/work1d.d[423];
  work1d.L[419] = (work1d.KKT[849])*work1d.d_inv[423];
  work1d.L[438] = (work1d.KKT[850])*work1d.d_inv[423];
  work1d.v[424] = work1d.KKT[851];
  work1d.d[424] = work1d.v[424];
  if (work1d.d[424] < 0)
    work1d.d[424] = settings1d.kkt_reg;
  else
    work1d.d[424] += settings1d.kkt_reg;
  work1d.d_inv[424] = 1/work1d.d[424];
  work1d.L[439] = (work1d.KKT[852])*work1d.d_inv[424];
  work1d.L[458] = (work1d.KKT[853])*work1d.d_inv[424];
  work1d.v[425] = work1d.KKT[854];
  work1d.d[425] = work1d.v[425];
  if (work1d.d[425] < 0)
    work1d.d[425] = settings1d.kkt_reg;
  else
    work1d.d[425] += settings1d.kkt_reg;
  work1d.d_inv[425] = 1/work1d.d[425];
  work1d.L[459] = (work1d.KKT[855])*work1d.d_inv[425];
  work1d.L[478] = (work1d.KKT[856])*work1d.d_inv[425];
  work1d.v[426] = work1d.KKT[857];
  work1d.d[426] = work1d.v[426];
  if (work1d.d[426] < 0)
    work1d.d[426] = settings1d.kkt_reg;
  else
    work1d.d[426] += settings1d.kkt_reg;
  work1d.d_inv[426] = 1/work1d.d[426];
  work1d.L[479] = (work1d.KKT[858])*work1d.d_inv[426];
  work1d.L[498] = (work1d.KKT[859])*work1d.d_inv[426];
  work1d.v[427] = work1d.KKT[860];
  work1d.d[427] = work1d.v[427];
  if (work1d.d[427] < 0)
    work1d.d[427] = settings1d.kkt_reg;
  else
    work1d.d[427] += settings1d.kkt_reg;
  work1d.d_inv[427] = 1/work1d.d[427];
  work1d.L[499] = (work1d.KKT[861])*work1d.d_inv[427];
  work1d.L[518] = (work1d.KKT[862])*work1d.d_inv[427];
  work1d.v[428] = work1d.KKT[863];
  work1d.d[428] = work1d.v[428];
  if (work1d.d[428] < 0)
    work1d.d[428] = settings1d.kkt_reg;
  else
    work1d.d[428] += settings1d.kkt_reg;
  work1d.d_inv[428] = 1/work1d.d[428];
  work1d.L[519] = (work1d.KKT[864])*work1d.d_inv[428];
  work1d.L[538] = (work1d.KKT[865])*work1d.d_inv[428];
  work1d.v[429] = work1d.KKT[866];
  work1d.d[429] = work1d.v[429];
  if (work1d.d[429] < 0)
    work1d.d[429] = settings1d.kkt_reg;
  else
    work1d.d[429] += settings1d.kkt_reg;
  work1d.d_inv[429] = 1/work1d.d[429];
  work1d.L[539] = (work1d.KKT[867])*work1d.d_inv[429];
  work1d.L[558] = (work1d.KKT[868])*work1d.d_inv[429];
  work1d.v[430] = work1d.KKT[869];
  work1d.d[430] = work1d.v[430];
  if (work1d.d[430] < 0)
    work1d.d[430] = settings1d.kkt_reg;
  else
    work1d.d[430] += settings1d.kkt_reg;
  work1d.d_inv[430] = 1/work1d.d[430];
  work1d.L[559] = (work1d.KKT[870])*work1d.d_inv[430];
  work1d.L[578] = (work1d.KKT[871])*work1d.d_inv[430];
  work1d.v[431] = work1d.KKT[872];
  work1d.d[431] = work1d.v[431];
  if (work1d.d[431] < 0)
    work1d.d[431] = settings1d.kkt_reg;
  else
    work1d.d[431] += settings1d.kkt_reg;
  work1d.d_inv[431] = 1/work1d.d[431];
  work1d.L[579] = (work1d.KKT[873])*work1d.d_inv[431];
  work1d.L[598] = (work1d.KKT[874])*work1d.d_inv[431];
  work1d.v[432] = work1d.KKT[875];
  work1d.d[432] = work1d.v[432];
  if (work1d.d[432] < 0)
    work1d.d[432] = settings1d.kkt_reg;
  else
    work1d.d[432] += settings1d.kkt_reg;
  work1d.d_inv[432] = 1/work1d.d[432];
  work1d.L[599] = (work1d.KKT[876])*work1d.d_inv[432];
  work1d.L[618] = (work1d.KKT[877])*work1d.d_inv[432];
  work1d.v[433] = work1d.KKT[878];
  work1d.d[433] = work1d.v[433];
  if (work1d.d[433] < 0)
    work1d.d[433] = settings1d.kkt_reg;
  else
    work1d.d[433] += settings1d.kkt_reg;
  work1d.d_inv[433] = 1/work1d.d[433];
  work1d.L[619] = (work1d.KKT[879])*work1d.d_inv[433];
  work1d.L[638] = (work1d.KKT[880])*work1d.d_inv[433];
  work1d.v[434] = work1d.KKT[881];
  work1d.d[434] = work1d.v[434];
  if (work1d.d[434] < 0)
    work1d.d[434] = settings1d.kkt_reg;
  else
    work1d.d[434] += settings1d.kkt_reg;
  work1d.d_inv[434] = 1/work1d.d[434];
  work1d.L[639] = (work1d.KKT[882])*work1d.d_inv[434];
  work1d.L[658] = (work1d.KKT[883])*work1d.d_inv[434];
  work1d.v[435] = work1d.KKT[884];
  work1d.d[435] = work1d.v[435];
  if (work1d.d[435] < 0)
    work1d.d[435] = settings1d.kkt_reg;
  else
    work1d.d[435] += settings1d.kkt_reg;
  work1d.d_inv[435] = 1/work1d.d[435];
  work1d.L[659] = (work1d.KKT[885])*work1d.d_inv[435];
  work1d.L[678] = (work1d.KKT[886])*work1d.d_inv[435];
  work1d.v[436] = work1d.KKT[887];
  work1d.d[436] = work1d.v[436];
  if (work1d.d[436] < 0)
    work1d.d[436] = settings1d.kkt_reg;
  else
    work1d.d[436] += settings1d.kkt_reg;
  work1d.d_inv[436] = 1/work1d.d[436];
  work1d.L[679] = (work1d.KKT[888])*work1d.d_inv[436];
  work1d.L[698] = (work1d.KKT[889])*work1d.d_inv[436];
  work1d.v[437] = work1d.KKT[890];
  work1d.d[437] = work1d.v[437];
  if (work1d.d[437] < 0)
    work1d.d[437] = settings1d.kkt_reg;
  else
    work1d.d[437] += settings1d.kkt_reg;
  work1d.d_inv[437] = 1/work1d.d[437];
  work1d.L[699] = (work1d.KKT[891])*work1d.d_inv[437];
  work1d.L[718] = (work1d.KKT[892])*work1d.d_inv[437];
  work1d.v[438] = work1d.KKT[893];
  work1d.d[438] = work1d.v[438];
  if (work1d.d[438] < 0)
    work1d.d[438] = settings1d.kkt_reg;
  else
    work1d.d[438] += settings1d.kkt_reg;
  work1d.d_inv[438] = 1/work1d.d[438];
  work1d.L[719] = (work1d.KKT[894])*work1d.d_inv[438];
  work1d.L[738] = (work1d.KKT[895])*work1d.d_inv[438];
  work1d.v[439] = work1d.KKT[896];
  work1d.d[439] = work1d.v[439];
  if (work1d.d[439] < 0)
    work1d.d[439] = settings1d.kkt_reg;
  else
    work1d.d[439] += settings1d.kkt_reg;
  work1d.d_inv[439] = 1/work1d.d[439];
  work1d.L[739] = (work1d.KKT[897])*work1d.d_inv[439];
  work1d.L[758] = (work1d.KKT[898])*work1d.d_inv[439];
  work1d.v[440] = work1d.KKT[899];
  work1d.d[440] = work1d.v[440];
  if (work1d.d[440] < 0)
    work1d.d[440] = settings1d.kkt_reg;
  else
    work1d.d[440] += settings1d.kkt_reg;
  work1d.d_inv[440] = 1/work1d.d[440];
  work1d.L[759] = (work1d.KKT[900])*work1d.d_inv[440];
  work1d.L[778] = (work1d.KKT[901])*work1d.d_inv[440];
  work1d.v[441] = work1d.KKT[902];
  work1d.d[441] = work1d.v[441];
  if (work1d.d[441] < 0)
    work1d.d[441] = settings1d.kkt_reg;
  else
    work1d.d[441] += settings1d.kkt_reg;
  work1d.d_inv[441] = 1/work1d.d[441];
  work1d.L[779] = (work1d.KKT[903])*work1d.d_inv[441];
  work1d.L[798] = (work1d.KKT[904])*work1d.d_inv[441];
  work1d.v[442] = work1d.KKT[905];
  work1d.d[442] = work1d.v[442];
  if (work1d.d[442] < 0)
    work1d.d[442] = settings1d.kkt_reg;
  else
    work1d.d[442] += settings1d.kkt_reg;
  work1d.d_inv[442] = 1/work1d.d[442];
  work1d.L[799] = (work1d.KKT[906])*work1d.d_inv[442];
  work1d.L[818] = (work1d.KKT[907])*work1d.d_inv[442];
  work1d.v[443] = work1d.KKT[908];
  work1d.d[443] = work1d.v[443];
  if (work1d.d[443] < 0)
    work1d.d[443] = settings1d.kkt_reg;
  else
    work1d.d[443] += settings1d.kkt_reg;
  work1d.d_inv[443] = 1/work1d.d[443];
  work1d.L[819] = (work1d.KKT[909])*work1d.d_inv[443];
  work1d.L[838] = (work1d.KKT[910])*work1d.d_inv[443];
  work1d.v[444] = work1d.KKT[911];
  work1d.d[444] = work1d.v[444];
  if (work1d.d[444] < 0)
    work1d.d[444] = settings1d.kkt_reg;
  else
    work1d.d[444] += settings1d.kkt_reg;
  work1d.d_inv[444] = 1/work1d.d[444];
  work1d.L[839] = (work1d.KKT[912])*work1d.d_inv[444];
  work1d.L[858] = (work1d.KKT[913])*work1d.d_inv[444];
  work1d.v[445] = work1d.KKT[914];
  work1d.d[445] = work1d.v[445];
  if (work1d.d[445] < 0)
    work1d.d[445] = settings1d.kkt_reg;
  else
    work1d.d[445] += settings1d.kkt_reg;
  work1d.d_inv[445] = 1/work1d.d[445];
  work1d.L[859] = (work1d.KKT[915])*work1d.d_inv[445];
  work1d.L[878] = (work1d.KKT[916])*work1d.d_inv[445];
  work1d.v[446] = work1d.KKT[917];
  work1d.d[446] = work1d.v[446];
  if (work1d.d[446] < 0)
    work1d.d[446] = settings1d.kkt_reg;
  else
    work1d.d[446] += settings1d.kkt_reg;
  work1d.d_inv[446] = 1/work1d.d[446];
  work1d.L[879] = (work1d.KKT[918])*work1d.d_inv[446];
  work1d.L[898] = (work1d.KKT[919])*work1d.d_inv[446];
  work1d.v[447] = work1d.KKT[920];
  work1d.d[447] = work1d.v[447];
  if (work1d.d[447] < 0)
    work1d.d[447] = settings1d.kkt_reg;
  else
    work1d.d[447] += settings1d.kkt_reg;
  work1d.d_inv[447] = 1/work1d.d[447];
  work1d.L[899] = (work1d.KKT[921])*work1d.d_inv[447];
  work1d.L[918] = (work1d.KKT[922])*work1d.d_inv[447];
  work1d.v[448] = work1d.KKT[923];
  work1d.d[448] = work1d.v[448];
  if (work1d.d[448] < 0)
    work1d.d[448] = settings1d.kkt_reg;
  else
    work1d.d[448] += settings1d.kkt_reg;
  work1d.d_inv[448] = 1/work1d.d[448];
  work1d.L[919] = (work1d.KKT[924])*work1d.d_inv[448];
  work1d.L[938] = (work1d.KKT[925])*work1d.d_inv[448];
  work1d.v[449] = work1d.KKT[926];
  work1d.d[449] = work1d.v[449];
  if (work1d.d[449] < 0)
    work1d.d[449] = settings1d.kkt_reg;
  else
    work1d.d[449] += settings1d.kkt_reg;
  work1d.d_inv[449] = 1/work1d.d[449];
  work1d.L[939] = (work1d.KKT[927])*work1d.d_inv[449];
  work1d.L[947] = (work1d.KKT[928])*work1d.d_inv[449];
  work1d.v[409] = work1d.L[225]*work1d.d[409];
  work1d.v[450] = work1d.KKT[929]-work1d.L[225]*work1d.v[409];
  work1d.d[450] = work1d.v[450];
  if (work1d.d[450] < 0)
    work1d.d[450] = settings1d.kkt_reg;
  else
    work1d.d[450] += settings1d.kkt_reg;
  work1d.d_inv[450] = 1/work1d.d[450];
  work1d.L[948] = (work1d.KKT[930])*work1d.d_inv[450];
  work1d.L[971] = (-work1d.L[969]*work1d.v[409])*work1d.d_inv[450];
  work1d.v[411] = work1d.L[226]*work1d.d[411];
  work1d.v[412] = work1d.L[227]*work1d.d[412];
  work1d.v[413] = work1d.L[228]*work1d.d[413];
  work1d.v[451] = 0-work1d.L[226]*work1d.v[411]-work1d.L[227]*work1d.v[412]-work1d.L[228]*work1d.v[413];
  work1d.d[451] = work1d.v[451];
  if (work1d.d[451] > 0)
    work1d.d[451] = -settings1d.kkt_reg;
  else
    work1d.d[451] -= settings1d.kkt_reg;
  work1d.d_inv[451] = 1/work1d.d[451];
  work1d.L[231] = (work1d.KKT[931])*work1d.d_inv[451];
  work1d.L[237] = (-work1d.L[236]*work1d.v[412])*work1d.d_inv[451];
  work1d.L[241] = (-work1d.L[239]*work1d.v[413])*work1d.d_inv[451];
  work1d.v[162] = work1d.L[229]*work1d.d[162];
  work1d.v[242] = work1d.L[230]*work1d.d[242];
  work1d.v[451] = work1d.L[231]*work1d.d[451];
  work1d.v[452] = work1d.KKT[932]-work1d.L[229]*work1d.v[162]-work1d.L[230]*work1d.v[242]-work1d.L[231]*work1d.v[451];
  work1d.d[452] = work1d.v[452];
  if (work1d.d[452] < 0)
    work1d.d[452] = settings1d.kkt_reg;
  else
    work1d.d[452] += settings1d.kkt_reg;
  work1d.d_inv[452] = 1/work1d.d[452];
  work1d.L[238] = (-work1d.L[237]*work1d.v[451])*work1d.d_inv[452];
  work1d.L[242] = (work1d.KKT[933]-work1d.L[241]*work1d.v[451])*work1d.d_inv[452];
  work1d.L[244] = (work1d.KKT[934])*work1d.d_inv[452];
  work1d.v[202] = work1d.L[232]*work1d.d[202];
  work1d.v[282] = work1d.L[233]*work1d.d[282];
  work1d.v[371] = work1d.L[234]*work1d.d[371];
  work1d.v[372] = work1d.L[235]*work1d.d[372];
  work1d.v[412] = work1d.L[236]*work1d.d[412];
  work1d.v[451] = work1d.L[237]*work1d.d[451];
  work1d.v[452] = work1d.L[238]*work1d.d[452];
  work1d.v[453] = work1d.KKT[935]-work1d.L[232]*work1d.v[202]-work1d.L[233]*work1d.v[282]-work1d.L[234]*work1d.v[371]-work1d.L[235]*work1d.v[372]-work1d.L[236]*work1d.v[412]-work1d.L[237]*work1d.v[451]-work1d.L[238]*work1d.v[452];
  work1d.d[453] = work1d.v[453];
  if (work1d.d[453] < 0)
    work1d.d[453] = settings1d.kkt_reg;
  else
    work1d.d[453] += settings1d.kkt_reg;
  work1d.d_inv[453] = 1/work1d.d[453];
  work1d.L[243] = (-work1d.L[241]*work1d.v[451]-work1d.L[242]*work1d.v[452])*work1d.d_inv[453];
  work1d.L[245] = (work1d.KKT[936]-work1d.L[244]*work1d.v[452])*work1d.d_inv[453];
  work1d.L[254] = (-work1d.L[252]*work1d.v[372])*work1d.d_inv[453];
  work1d.v[413] = work1d.L[239]*work1d.d[413];
  work1d.v[414] = work1d.L[240]*work1d.d[414];
  work1d.v[451] = work1d.L[241]*work1d.d[451];
  work1d.v[452] = work1d.L[242]*work1d.d[452];
  work1d.v[453] = work1d.L[243]*work1d.d[453];
  work1d.v[454] = 0-work1d.L[239]*work1d.v[413]-work1d.L[240]*work1d.v[414]-work1d.L[241]*work1d.v[451]-work1d.L[242]*work1d.v[452]-work1d.L[243]*work1d.v[453];
  work1d.d[454] = work1d.v[454];
  if (work1d.d[454] > 0)
    work1d.d[454] = -settings1d.kkt_reg;
  else
    work1d.d[454] -= settings1d.kkt_reg;
  work1d.d_inv[454] = 1/work1d.d[454];
  work1d.L[246] = (-work1d.L[244]*work1d.v[452]-work1d.L[245]*work1d.v[453])*work1d.d_inv[454];
  work1d.L[255] = (-work1d.L[254]*work1d.v[453])*work1d.d_inv[454];
  work1d.L[260] = (-work1d.L[258]*work1d.v[414])*work1d.d_inv[454];
  work1d.v[452] = work1d.L[244]*work1d.d[452];
  work1d.v[453] = work1d.L[245]*work1d.d[453];
  work1d.v[454] = work1d.L[246]*work1d.d[454];
  work1d.v[455] = 0-work1d.L[244]*work1d.v[452]-work1d.L[245]*work1d.v[453]-work1d.L[246]*work1d.v[454];
  work1d.d[455] = work1d.v[455];
  if (work1d.d[455] > 0)
    work1d.d[455] = -settings1d.kkt_reg;
  else
    work1d.d[455] -= settings1d.kkt_reg;
  work1d.d_inv[455] = 1/work1d.d[455];
  work1d.L[249] = (work1d.KKT[937])*work1d.d_inv[455];
  work1d.L[256] = (-work1d.L[254]*work1d.v[453]-work1d.L[255]*work1d.v[454])*work1d.d_inv[455];
  work1d.L[261] = (-work1d.L[260]*work1d.v[454])*work1d.d_inv[455];
  work1d.v[163] = work1d.L[247]*work1d.d[163];
  work1d.v[243] = work1d.L[248]*work1d.d[243];
  work1d.v[455] = work1d.L[249]*work1d.d[455];
  work1d.v[456] = work1d.KKT[938]-work1d.L[247]*work1d.v[163]-work1d.L[248]*work1d.v[243]-work1d.L[249]*work1d.v[455];
  work1d.d[456] = work1d.v[456];
  if (work1d.d[456] < 0)
    work1d.d[456] = settings1d.kkt_reg;
  else
    work1d.d[456] += settings1d.kkt_reg;
  work1d.d_inv[456] = 1/work1d.d[456];
  work1d.L[257] = (-work1d.L[256]*work1d.v[455])*work1d.d_inv[456];
  work1d.L[262] = (work1d.KKT[939]-work1d.L[261]*work1d.v[455])*work1d.d_inv[456];
  work1d.L[264] = (work1d.KKT[940])*work1d.d_inv[456];
  work1d.v[203] = work1d.L[250]*work1d.d[203];
  work1d.v[283] = work1d.L[251]*work1d.d[283];
  work1d.v[372] = work1d.L[252]*work1d.d[372];
  work1d.v[373] = work1d.L[253]*work1d.d[373];
  work1d.v[453] = work1d.L[254]*work1d.d[453];
  work1d.v[454] = work1d.L[255]*work1d.d[454];
  work1d.v[455] = work1d.L[256]*work1d.d[455];
  work1d.v[456] = work1d.L[257]*work1d.d[456];
  work1d.v[457] = work1d.KKT[941]-work1d.L[250]*work1d.v[203]-work1d.L[251]*work1d.v[283]-work1d.L[252]*work1d.v[372]-work1d.L[253]*work1d.v[373]-work1d.L[254]*work1d.v[453]-work1d.L[255]*work1d.v[454]-work1d.L[256]*work1d.v[455]-work1d.L[257]*work1d.v[456];
  work1d.d[457] = work1d.v[457];
  if (work1d.d[457] < 0)
    work1d.d[457] = settings1d.kkt_reg;
  else
    work1d.d[457] += settings1d.kkt_reg;
  work1d.d_inv[457] = 1/work1d.d[457];
  work1d.L[263] = (-work1d.L[260]*work1d.v[454]-work1d.L[261]*work1d.v[455]-work1d.L[262]*work1d.v[456])*work1d.d_inv[457];
  work1d.L[265] = (work1d.KKT[942]-work1d.L[264]*work1d.v[456])*work1d.d_inv[457];
  work1d.L[274] = (-work1d.L[272]*work1d.v[373])*work1d.d_inv[457];
  work1d.v[414] = work1d.L[258]*work1d.d[414];
  work1d.v[415] = work1d.L[259]*work1d.d[415];
  work1d.v[454] = work1d.L[260]*work1d.d[454];
  work1d.v[455] = work1d.L[261]*work1d.d[455];
  work1d.v[456] = work1d.L[262]*work1d.d[456];
  work1d.v[457] = work1d.L[263]*work1d.d[457];
  work1d.v[458] = 0-work1d.L[258]*work1d.v[414]-work1d.L[259]*work1d.v[415]-work1d.L[260]*work1d.v[454]-work1d.L[261]*work1d.v[455]-work1d.L[262]*work1d.v[456]-work1d.L[263]*work1d.v[457];
  work1d.d[458] = work1d.v[458];
  if (work1d.d[458] > 0)
    work1d.d[458] = -settings1d.kkt_reg;
  else
    work1d.d[458] -= settings1d.kkt_reg;
  work1d.d_inv[458] = 1/work1d.d[458];
  work1d.L[266] = (-work1d.L[264]*work1d.v[456]-work1d.L[265]*work1d.v[457])*work1d.d_inv[458];
  work1d.L[275] = (-work1d.L[274]*work1d.v[457])*work1d.d_inv[458];
  work1d.L[280] = (-work1d.L[278]*work1d.v[415])*work1d.d_inv[458];
  work1d.v[456] = work1d.L[264]*work1d.d[456];
  work1d.v[457] = work1d.L[265]*work1d.d[457];
  work1d.v[458] = work1d.L[266]*work1d.d[458];
  work1d.v[459] = 0-work1d.L[264]*work1d.v[456]-work1d.L[265]*work1d.v[457]-work1d.L[266]*work1d.v[458];
  work1d.d[459] = work1d.v[459];
  if (work1d.d[459] > 0)
    work1d.d[459] = -settings1d.kkt_reg;
  else
    work1d.d[459] -= settings1d.kkt_reg;
  work1d.d_inv[459] = 1/work1d.d[459];
  work1d.L[269] = (work1d.KKT[943])*work1d.d_inv[459];
  work1d.L[276] = (-work1d.L[274]*work1d.v[457]-work1d.L[275]*work1d.v[458])*work1d.d_inv[459];
  work1d.L[281] = (-work1d.L[280]*work1d.v[458])*work1d.d_inv[459];
  work1d.v[164] = work1d.L[267]*work1d.d[164];
  work1d.v[244] = work1d.L[268]*work1d.d[244];
  work1d.v[459] = work1d.L[269]*work1d.d[459];
  work1d.v[460] = work1d.KKT[944]-work1d.L[267]*work1d.v[164]-work1d.L[268]*work1d.v[244]-work1d.L[269]*work1d.v[459];
  work1d.d[460] = work1d.v[460];
  if (work1d.d[460] < 0)
    work1d.d[460] = settings1d.kkt_reg;
  else
    work1d.d[460] += settings1d.kkt_reg;
  work1d.d_inv[460] = 1/work1d.d[460];
  work1d.L[277] = (-work1d.L[276]*work1d.v[459])*work1d.d_inv[460];
  work1d.L[282] = (work1d.KKT[945]-work1d.L[281]*work1d.v[459])*work1d.d_inv[460];
  work1d.L[284] = (work1d.KKT[946])*work1d.d_inv[460];
  work1d.v[204] = work1d.L[270]*work1d.d[204];
  work1d.v[284] = work1d.L[271]*work1d.d[284];
  work1d.v[373] = work1d.L[272]*work1d.d[373];
  work1d.v[374] = work1d.L[273]*work1d.d[374];
  work1d.v[457] = work1d.L[274]*work1d.d[457];
  work1d.v[458] = work1d.L[275]*work1d.d[458];
  work1d.v[459] = work1d.L[276]*work1d.d[459];
  work1d.v[460] = work1d.L[277]*work1d.d[460];
  work1d.v[461] = work1d.KKT[947]-work1d.L[270]*work1d.v[204]-work1d.L[271]*work1d.v[284]-work1d.L[272]*work1d.v[373]-work1d.L[273]*work1d.v[374]-work1d.L[274]*work1d.v[457]-work1d.L[275]*work1d.v[458]-work1d.L[276]*work1d.v[459]-work1d.L[277]*work1d.v[460];
  work1d.d[461] = work1d.v[461];
  if (work1d.d[461] < 0)
    work1d.d[461] = settings1d.kkt_reg;
  else
    work1d.d[461] += settings1d.kkt_reg;
  work1d.d_inv[461] = 1/work1d.d[461];
  work1d.L[283] = (-work1d.L[280]*work1d.v[458]-work1d.L[281]*work1d.v[459]-work1d.L[282]*work1d.v[460])*work1d.d_inv[461];
  work1d.L[285] = (work1d.KKT[948]-work1d.L[284]*work1d.v[460])*work1d.d_inv[461];
  work1d.L[294] = (-work1d.L[292]*work1d.v[374])*work1d.d_inv[461];
  work1d.v[415] = work1d.L[278]*work1d.d[415];
  work1d.v[416] = work1d.L[279]*work1d.d[416];
  work1d.v[458] = work1d.L[280]*work1d.d[458];
  work1d.v[459] = work1d.L[281]*work1d.d[459];
  work1d.v[460] = work1d.L[282]*work1d.d[460];
  work1d.v[461] = work1d.L[283]*work1d.d[461];
  work1d.v[462] = 0-work1d.L[278]*work1d.v[415]-work1d.L[279]*work1d.v[416]-work1d.L[280]*work1d.v[458]-work1d.L[281]*work1d.v[459]-work1d.L[282]*work1d.v[460]-work1d.L[283]*work1d.v[461];
  work1d.d[462] = work1d.v[462];
  if (work1d.d[462] > 0)
    work1d.d[462] = -settings1d.kkt_reg;
  else
    work1d.d[462] -= settings1d.kkt_reg;
  work1d.d_inv[462] = 1/work1d.d[462];
  work1d.L[286] = (-work1d.L[284]*work1d.v[460]-work1d.L[285]*work1d.v[461])*work1d.d_inv[462];
  work1d.L[295] = (-work1d.L[294]*work1d.v[461])*work1d.d_inv[462];
  work1d.L[300] = (-work1d.L[298]*work1d.v[416])*work1d.d_inv[462];
  work1d.v[460] = work1d.L[284]*work1d.d[460];
  work1d.v[461] = work1d.L[285]*work1d.d[461];
  work1d.v[462] = work1d.L[286]*work1d.d[462];
  work1d.v[463] = 0-work1d.L[284]*work1d.v[460]-work1d.L[285]*work1d.v[461]-work1d.L[286]*work1d.v[462];
  work1d.d[463] = work1d.v[463];
  if (work1d.d[463] > 0)
    work1d.d[463] = -settings1d.kkt_reg;
  else
    work1d.d[463] -= settings1d.kkt_reg;
  work1d.d_inv[463] = 1/work1d.d[463];
  work1d.L[289] = (work1d.KKT[949])*work1d.d_inv[463];
  work1d.L[296] = (-work1d.L[294]*work1d.v[461]-work1d.L[295]*work1d.v[462])*work1d.d_inv[463];
  work1d.L[301] = (-work1d.L[300]*work1d.v[462])*work1d.d_inv[463];
  work1d.v[165] = work1d.L[287]*work1d.d[165];
  work1d.v[245] = work1d.L[288]*work1d.d[245];
  work1d.v[463] = work1d.L[289]*work1d.d[463];
  work1d.v[464] = work1d.KKT[950]-work1d.L[287]*work1d.v[165]-work1d.L[288]*work1d.v[245]-work1d.L[289]*work1d.v[463];
  work1d.d[464] = work1d.v[464];
  if (work1d.d[464] < 0)
    work1d.d[464] = settings1d.kkt_reg;
  else
    work1d.d[464] += settings1d.kkt_reg;
  work1d.d_inv[464] = 1/work1d.d[464];
  work1d.L[297] = (-work1d.L[296]*work1d.v[463])*work1d.d_inv[464];
  work1d.L[302] = (work1d.KKT[951]-work1d.L[301]*work1d.v[463])*work1d.d_inv[464];
  work1d.L[304] = (work1d.KKT[952])*work1d.d_inv[464];
  work1d.v[205] = work1d.L[290]*work1d.d[205];
  work1d.v[285] = work1d.L[291]*work1d.d[285];
  work1d.v[374] = work1d.L[292]*work1d.d[374];
  work1d.v[375] = work1d.L[293]*work1d.d[375];
  work1d.v[461] = work1d.L[294]*work1d.d[461];
  work1d.v[462] = work1d.L[295]*work1d.d[462];
  work1d.v[463] = work1d.L[296]*work1d.d[463];
  work1d.v[464] = work1d.L[297]*work1d.d[464];
  work1d.v[465] = work1d.KKT[953]-work1d.L[290]*work1d.v[205]-work1d.L[291]*work1d.v[285]-work1d.L[292]*work1d.v[374]-work1d.L[293]*work1d.v[375]-work1d.L[294]*work1d.v[461]-work1d.L[295]*work1d.v[462]-work1d.L[296]*work1d.v[463]-work1d.L[297]*work1d.v[464];
  work1d.d[465] = work1d.v[465];
  if (work1d.d[465] < 0)
    work1d.d[465] = settings1d.kkt_reg;
  else
    work1d.d[465] += settings1d.kkt_reg;
  work1d.d_inv[465] = 1/work1d.d[465];
  work1d.L[303] = (-work1d.L[300]*work1d.v[462]-work1d.L[301]*work1d.v[463]-work1d.L[302]*work1d.v[464])*work1d.d_inv[465];
  work1d.L[305] = (work1d.KKT[954]-work1d.L[304]*work1d.v[464])*work1d.d_inv[465];
  work1d.L[314] = (-work1d.L[312]*work1d.v[375])*work1d.d_inv[465];
  work1d.v[416] = work1d.L[298]*work1d.d[416];
  work1d.v[417] = work1d.L[299]*work1d.d[417];
  work1d.v[462] = work1d.L[300]*work1d.d[462];
  work1d.v[463] = work1d.L[301]*work1d.d[463];
  work1d.v[464] = work1d.L[302]*work1d.d[464];
  work1d.v[465] = work1d.L[303]*work1d.d[465];
  work1d.v[466] = 0-work1d.L[298]*work1d.v[416]-work1d.L[299]*work1d.v[417]-work1d.L[300]*work1d.v[462]-work1d.L[301]*work1d.v[463]-work1d.L[302]*work1d.v[464]-work1d.L[303]*work1d.v[465];
  work1d.d[466] = work1d.v[466];
  if (work1d.d[466] > 0)
    work1d.d[466] = -settings1d.kkt_reg;
  else
    work1d.d[466] -= settings1d.kkt_reg;
  work1d.d_inv[466] = 1/work1d.d[466];
  work1d.L[306] = (-work1d.L[304]*work1d.v[464]-work1d.L[305]*work1d.v[465])*work1d.d_inv[466];
  work1d.L[315] = (-work1d.L[314]*work1d.v[465])*work1d.d_inv[466];
  work1d.L[320] = (-work1d.L[318]*work1d.v[417])*work1d.d_inv[466];
  work1d.v[464] = work1d.L[304]*work1d.d[464];
  work1d.v[465] = work1d.L[305]*work1d.d[465];
  work1d.v[466] = work1d.L[306]*work1d.d[466];
  work1d.v[467] = 0-work1d.L[304]*work1d.v[464]-work1d.L[305]*work1d.v[465]-work1d.L[306]*work1d.v[466];
  work1d.d[467] = work1d.v[467];
  if (work1d.d[467] > 0)
    work1d.d[467] = -settings1d.kkt_reg;
  else
    work1d.d[467] -= settings1d.kkt_reg;
  work1d.d_inv[467] = 1/work1d.d[467];
  work1d.L[309] = (work1d.KKT[955])*work1d.d_inv[467];
  work1d.L[316] = (-work1d.L[314]*work1d.v[465]-work1d.L[315]*work1d.v[466])*work1d.d_inv[467];
  work1d.L[321] = (-work1d.L[320]*work1d.v[466])*work1d.d_inv[467];
  work1d.v[166] = work1d.L[307]*work1d.d[166];
  work1d.v[246] = work1d.L[308]*work1d.d[246];
  work1d.v[467] = work1d.L[309]*work1d.d[467];
  work1d.v[468] = work1d.KKT[956]-work1d.L[307]*work1d.v[166]-work1d.L[308]*work1d.v[246]-work1d.L[309]*work1d.v[467];
  work1d.d[468] = work1d.v[468];
  if (work1d.d[468] < 0)
    work1d.d[468] = settings1d.kkt_reg;
  else
    work1d.d[468] += settings1d.kkt_reg;
  work1d.d_inv[468] = 1/work1d.d[468];
  work1d.L[317] = (-work1d.L[316]*work1d.v[467])*work1d.d_inv[468];
  work1d.L[322] = (work1d.KKT[957]-work1d.L[321]*work1d.v[467])*work1d.d_inv[468];
  work1d.L[324] = (work1d.KKT[958])*work1d.d_inv[468];
  work1d.v[206] = work1d.L[310]*work1d.d[206];
  work1d.v[286] = work1d.L[311]*work1d.d[286];
  work1d.v[375] = work1d.L[312]*work1d.d[375];
  work1d.v[376] = work1d.L[313]*work1d.d[376];
  work1d.v[465] = work1d.L[314]*work1d.d[465];
  work1d.v[466] = work1d.L[315]*work1d.d[466];
  work1d.v[467] = work1d.L[316]*work1d.d[467];
  work1d.v[468] = work1d.L[317]*work1d.d[468];
  work1d.v[469] = work1d.KKT[959]-work1d.L[310]*work1d.v[206]-work1d.L[311]*work1d.v[286]-work1d.L[312]*work1d.v[375]-work1d.L[313]*work1d.v[376]-work1d.L[314]*work1d.v[465]-work1d.L[315]*work1d.v[466]-work1d.L[316]*work1d.v[467]-work1d.L[317]*work1d.v[468];
  work1d.d[469] = work1d.v[469];
  if (work1d.d[469] < 0)
    work1d.d[469] = settings1d.kkt_reg;
  else
    work1d.d[469] += settings1d.kkt_reg;
  work1d.d_inv[469] = 1/work1d.d[469];
  work1d.L[323] = (-work1d.L[320]*work1d.v[466]-work1d.L[321]*work1d.v[467]-work1d.L[322]*work1d.v[468])*work1d.d_inv[469];
  work1d.L[325] = (work1d.KKT[960]-work1d.L[324]*work1d.v[468])*work1d.d_inv[469];
  work1d.L[334] = (-work1d.L[332]*work1d.v[376])*work1d.d_inv[469];
  work1d.v[417] = work1d.L[318]*work1d.d[417];
  work1d.v[418] = work1d.L[319]*work1d.d[418];
  work1d.v[466] = work1d.L[320]*work1d.d[466];
  work1d.v[467] = work1d.L[321]*work1d.d[467];
  work1d.v[468] = work1d.L[322]*work1d.d[468];
  work1d.v[469] = work1d.L[323]*work1d.d[469];
  work1d.v[470] = 0-work1d.L[318]*work1d.v[417]-work1d.L[319]*work1d.v[418]-work1d.L[320]*work1d.v[466]-work1d.L[321]*work1d.v[467]-work1d.L[322]*work1d.v[468]-work1d.L[323]*work1d.v[469];
  work1d.d[470] = work1d.v[470];
  if (work1d.d[470] > 0)
    work1d.d[470] = -settings1d.kkt_reg;
  else
    work1d.d[470] -= settings1d.kkt_reg;
  work1d.d_inv[470] = 1/work1d.d[470];
  work1d.L[326] = (-work1d.L[324]*work1d.v[468]-work1d.L[325]*work1d.v[469])*work1d.d_inv[470];
  work1d.L[335] = (-work1d.L[334]*work1d.v[469])*work1d.d_inv[470];
  work1d.L[340] = (-work1d.L[338]*work1d.v[418])*work1d.d_inv[470];
  work1d.v[468] = work1d.L[324]*work1d.d[468];
  work1d.v[469] = work1d.L[325]*work1d.d[469];
  work1d.v[470] = work1d.L[326]*work1d.d[470];
  work1d.v[471] = 0-work1d.L[324]*work1d.v[468]-work1d.L[325]*work1d.v[469]-work1d.L[326]*work1d.v[470];
  work1d.d[471] = work1d.v[471];
  if (work1d.d[471] > 0)
    work1d.d[471] = -settings1d.kkt_reg;
  else
    work1d.d[471] -= settings1d.kkt_reg;
  work1d.d_inv[471] = 1/work1d.d[471];
  work1d.L[329] = (work1d.KKT[961])*work1d.d_inv[471];
  work1d.L[336] = (-work1d.L[334]*work1d.v[469]-work1d.L[335]*work1d.v[470])*work1d.d_inv[471];
  work1d.L[341] = (-work1d.L[340]*work1d.v[470])*work1d.d_inv[471];
  work1d.v[167] = work1d.L[327]*work1d.d[167];
  work1d.v[247] = work1d.L[328]*work1d.d[247];
  work1d.v[471] = work1d.L[329]*work1d.d[471];
  work1d.v[472] = work1d.KKT[962]-work1d.L[327]*work1d.v[167]-work1d.L[328]*work1d.v[247]-work1d.L[329]*work1d.v[471];
  work1d.d[472] = work1d.v[472];
  if (work1d.d[472] < 0)
    work1d.d[472] = settings1d.kkt_reg;
  else
    work1d.d[472] += settings1d.kkt_reg;
  work1d.d_inv[472] = 1/work1d.d[472];
  work1d.L[337] = (-work1d.L[336]*work1d.v[471])*work1d.d_inv[472];
  work1d.L[342] = (work1d.KKT[963]-work1d.L[341]*work1d.v[471])*work1d.d_inv[472];
  work1d.L[344] = (work1d.KKT[964])*work1d.d_inv[472];
  work1d.v[207] = work1d.L[330]*work1d.d[207];
  work1d.v[287] = work1d.L[331]*work1d.d[287];
  work1d.v[376] = work1d.L[332]*work1d.d[376];
  work1d.v[377] = work1d.L[333]*work1d.d[377];
  work1d.v[469] = work1d.L[334]*work1d.d[469];
  work1d.v[470] = work1d.L[335]*work1d.d[470];
  work1d.v[471] = work1d.L[336]*work1d.d[471];
  work1d.v[472] = work1d.L[337]*work1d.d[472];
  work1d.v[473] = work1d.KKT[965]-work1d.L[330]*work1d.v[207]-work1d.L[331]*work1d.v[287]-work1d.L[332]*work1d.v[376]-work1d.L[333]*work1d.v[377]-work1d.L[334]*work1d.v[469]-work1d.L[335]*work1d.v[470]-work1d.L[336]*work1d.v[471]-work1d.L[337]*work1d.v[472];
  work1d.d[473] = work1d.v[473];
  if (work1d.d[473] < 0)
    work1d.d[473] = settings1d.kkt_reg;
  else
    work1d.d[473] += settings1d.kkt_reg;
  work1d.d_inv[473] = 1/work1d.d[473];
  work1d.L[343] = (-work1d.L[340]*work1d.v[470]-work1d.L[341]*work1d.v[471]-work1d.L[342]*work1d.v[472])*work1d.d_inv[473];
  work1d.L[345] = (work1d.KKT[966]-work1d.L[344]*work1d.v[472])*work1d.d_inv[473];
  work1d.L[354] = (-work1d.L[352]*work1d.v[377])*work1d.d_inv[473];
  work1d.v[418] = work1d.L[338]*work1d.d[418];
  work1d.v[419] = work1d.L[339]*work1d.d[419];
  work1d.v[470] = work1d.L[340]*work1d.d[470];
  work1d.v[471] = work1d.L[341]*work1d.d[471];
  work1d.v[472] = work1d.L[342]*work1d.d[472];
  work1d.v[473] = work1d.L[343]*work1d.d[473];
  work1d.v[474] = 0-work1d.L[338]*work1d.v[418]-work1d.L[339]*work1d.v[419]-work1d.L[340]*work1d.v[470]-work1d.L[341]*work1d.v[471]-work1d.L[342]*work1d.v[472]-work1d.L[343]*work1d.v[473];
  work1d.d[474] = work1d.v[474];
  if (work1d.d[474] > 0)
    work1d.d[474] = -settings1d.kkt_reg;
  else
    work1d.d[474] -= settings1d.kkt_reg;
  work1d.d_inv[474] = 1/work1d.d[474];
  work1d.L[346] = (-work1d.L[344]*work1d.v[472]-work1d.L[345]*work1d.v[473])*work1d.d_inv[474];
  work1d.L[355] = (-work1d.L[354]*work1d.v[473])*work1d.d_inv[474];
  work1d.L[360] = (-work1d.L[358]*work1d.v[419])*work1d.d_inv[474];
  work1d.v[472] = work1d.L[344]*work1d.d[472];
  work1d.v[473] = work1d.L[345]*work1d.d[473];
  work1d.v[474] = work1d.L[346]*work1d.d[474];
  work1d.v[475] = 0-work1d.L[344]*work1d.v[472]-work1d.L[345]*work1d.v[473]-work1d.L[346]*work1d.v[474];
  work1d.d[475] = work1d.v[475];
  if (work1d.d[475] > 0)
    work1d.d[475] = -settings1d.kkt_reg;
  else
    work1d.d[475] -= settings1d.kkt_reg;
  work1d.d_inv[475] = 1/work1d.d[475];
  work1d.L[349] = (work1d.KKT[967])*work1d.d_inv[475];
  work1d.L[356] = (-work1d.L[354]*work1d.v[473]-work1d.L[355]*work1d.v[474])*work1d.d_inv[475];
  work1d.L[361] = (-work1d.L[360]*work1d.v[474])*work1d.d_inv[475];
  work1d.v[168] = work1d.L[347]*work1d.d[168];
  work1d.v[248] = work1d.L[348]*work1d.d[248];
  work1d.v[475] = work1d.L[349]*work1d.d[475];
  work1d.v[476] = work1d.KKT[968]-work1d.L[347]*work1d.v[168]-work1d.L[348]*work1d.v[248]-work1d.L[349]*work1d.v[475];
  work1d.d[476] = work1d.v[476];
  if (work1d.d[476] < 0)
    work1d.d[476] = settings1d.kkt_reg;
  else
    work1d.d[476] += settings1d.kkt_reg;
  work1d.d_inv[476] = 1/work1d.d[476];
  work1d.L[357] = (-work1d.L[356]*work1d.v[475])*work1d.d_inv[476];
  work1d.L[362] = (work1d.KKT[969]-work1d.L[361]*work1d.v[475])*work1d.d_inv[476];
  work1d.L[364] = (work1d.KKT[970])*work1d.d_inv[476];
  work1d.v[208] = work1d.L[350]*work1d.d[208];
  work1d.v[288] = work1d.L[351]*work1d.d[288];
  work1d.v[377] = work1d.L[352]*work1d.d[377];
  work1d.v[378] = work1d.L[353]*work1d.d[378];
  work1d.v[473] = work1d.L[354]*work1d.d[473];
  work1d.v[474] = work1d.L[355]*work1d.d[474];
  work1d.v[475] = work1d.L[356]*work1d.d[475];
  work1d.v[476] = work1d.L[357]*work1d.d[476];
  work1d.v[477] = work1d.KKT[971]-work1d.L[350]*work1d.v[208]-work1d.L[351]*work1d.v[288]-work1d.L[352]*work1d.v[377]-work1d.L[353]*work1d.v[378]-work1d.L[354]*work1d.v[473]-work1d.L[355]*work1d.v[474]-work1d.L[356]*work1d.v[475]-work1d.L[357]*work1d.v[476];
  work1d.d[477] = work1d.v[477];
  if (work1d.d[477] < 0)
    work1d.d[477] = settings1d.kkt_reg;
  else
    work1d.d[477] += settings1d.kkt_reg;
  work1d.d_inv[477] = 1/work1d.d[477];
  work1d.L[363] = (-work1d.L[360]*work1d.v[474]-work1d.L[361]*work1d.v[475]-work1d.L[362]*work1d.v[476])*work1d.d_inv[477];
  work1d.L[365] = (work1d.KKT[972]-work1d.L[364]*work1d.v[476])*work1d.d_inv[477];
  work1d.L[374] = (-work1d.L[372]*work1d.v[378])*work1d.d_inv[477];
  work1d.v[419] = work1d.L[358]*work1d.d[419];
  work1d.v[420] = work1d.L[359]*work1d.d[420];
  work1d.v[474] = work1d.L[360]*work1d.d[474];
  work1d.v[475] = work1d.L[361]*work1d.d[475];
  work1d.v[476] = work1d.L[362]*work1d.d[476];
  work1d.v[477] = work1d.L[363]*work1d.d[477];
  work1d.v[478] = 0-work1d.L[358]*work1d.v[419]-work1d.L[359]*work1d.v[420]-work1d.L[360]*work1d.v[474]-work1d.L[361]*work1d.v[475]-work1d.L[362]*work1d.v[476]-work1d.L[363]*work1d.v[477];
  work1d.d[478] = work1d.v[478];
  if (work1d.d[478] > 0)
    work1d.d[478] = -settings1d.kkt_reg;
  else
    work1d.d[478] -= settings1d.kkt_reg;
  work1d.d_inv[478] = 1/work1d.d[478];
  work1d.L[366] = (-work1d.L[364]*work1d.v[476]-work1d.L[365]*work1d.v[477])*work1d.d_inv[478];
  work1d.L[375] = (-work1d.L[374]*work1d.v[477])*work1d.d_inv[478];
  work1d.L[380] = (-work1d.L[378]*work1d.v[420])*work1d.d_inv[478];
  work1d.v[476] = work1d.L[364]*work1d.d[476];
  work1d.v[477] = work1d.L[365]*work1d.d[477];
  work1d.v[478] = work1d.L[366]*work1d.d[478];
  work1d.v[479] = 0-work1d.L[364]*work1d.v[476]-work1d.L[365]*work1d.v[477]-work1d.L[366]*work1d.v[478];
  work1d.d[479] = work1d.v[479];
  if (work1d.d[479] > 0)
    work1d.d[479] = -settings1d.kkt_reg;
  else
    work1d.d[479] -= settings1d.kkt_reg;
  work1d.d_inv[479] = 1/work1d.d[479];
  work1d.L[369] = (work1d.KKT[973])*work1d.d_inv[479];
  work1d.L[376] = (-work1d.L[374]*work1d.v[477]-work1d.L[375]*work1d.v[478])*work1d.d_inv[479];
  work1d.L[381] = (-work1d.L[380]*work1d.v[478])*work1d.d_inv[479];
  work1d.v[169] = work1d.L[367]*work1d.d[169];
  work1d.v[249] = work1d.L[368]*work1d.d[249];
  work1d.v[479] = work1d.L[369]*work1d.d[479];
  work1d.v[480] = work1d.KKT[974]-work1d.L[367]*work1d.v[169]-work1d.L[368]*work1d.v[249]-work1d.L[369]*work1d.v[479];
  work1d.d[480] = work1d.v[480];
  if (work1d.d[480] < 0)
    work1d.d[480] = settings1d.kkt_reg;
  else
    work1d.d[480] += settings1d.kkt_reg;
  work1d.d_inv[480] = 1/work1d.d[480];
  work1d.L[377] = (-work1d.L[376]*work1d.v[479])*work1d.d_inv[480];
  work1d.L[382] = (work1d.KKT[975]-work1d.L[381]*work1d.v[479])*work1d.d_inv[480];
  work1d.L[384] = (work1d.KKT[976])*work1d.d_inv[480];
  work1d.v[209] = work1d.L[370]*work1d.d[209];
  work1d.v[289] = work1d.L[371]*work1d.d[289];
  work1d.v[378] = work1d.L[372]*work1d.d[378];
  work1d.v[379] = work1d.L[373]*work1d.d[379];
  work1d.v[477] = work1d.L[374]*work1d.d[477];
  work1d.v[478] = work1d.L[375]*work1d.d[478];
  work1d.v[479] = work1d.L[376]*work1d.d[479];
  work1d.v[480] = work1d.L[377]*work1d.d[480];
  work1d.v[481] = work1d.KKT[977]-work1d.L[370]*work1d.v[209]-work1d.L[371]*work1d.v[289]-work1d.L[372]*work1d.v[378]-work1d.L[373]*work1d.v[379]-work1d.L[374]*work1d.v[477]-work1d.L[375]*work1d.v[478]-work1d.L[376]*work1d.v[479]-work1d.L[377]*work1d.v[480];
  work1d.d[481] = work1d.v[481];
  if (work1d.d[481] < 0)
    work1d.d[481] = settings1d.kkt_reg;
  else
    work1d.d[481] += settings1d.kkt_reg;
  work1d.d_inv[481] = 1/work1d.d[481];
  work1d.L[383] = (-work1d.L[380]*work1d.v[478]-work1d.L[381]*work1d.v[479]-work1d.L[382]*work1d.v[480])*work1d.d_inv[481];
  work1d.L[385] = (work1d.KKT[978]-work1d.L[384]*work1d.v[480])*work1d.d_inv[481];
  work1d.L[394] = (-work1d.L[392]*work1d.v[379])*work1d.d_inv[481];
  work1d.v[420] = work1d.L[378]*work1d.d[420];
  work1d.v[421] = work1d.L[379]*work1d.d[421];
  work1d.v[478] = work1d.L[380]*work1d.d[478];
  work1d.v[479] = work1d.L[381]*work1d.d[479];
  work1d.v[480] = work1d.L[382]*work1d.d[480];
  work1d.v[481] = work1d.L[383]*work1d.d[481];
  work1d.v[482] = 0-work1d.L[378]*work1d.v[420]-work1d.L[379]*work1d.v[421]-work1d.L[380]*work1d.v[478]-work1d.L[381]*work1d.v[479]-work1d.L[382]*work1d.v[480]-work1d.L[383]*work1d.v[481];
  work1d.d[482] = work1d.v[482];
  if (work1d.d[482] > 0)
    work1d.d[482] = -settings1d.kkt_reg;
  else
    work1d.d[482] -= settings1d.kkt_reg;
  work1d.d_inv[482] = 1/work1d.d[482];
  work1d.L[386] = (-work1d.L[384]*work1d.v[480]-work1d.L[385]*work1d.v[481])*work1d.d_inv[482];
  work1d.L[395] = (-work1d.L[394]*work1d.v[481])*work1d.d_inv[482];
  work1d.L[400] = (-work1d.L[398]*work1d.v[421])*work1d.d_inv[482];
  work1d.v[480] = work1d.L[384]*work1d.d[480];
  work1d.v[481] = work1d.L[385]*work1d.d[481];
  work1d.v[482] = work1d.L[386]*work1d.d[482];
  work1d.v[483] = 0-work1d.L[384]*work1d.v[480]-work1d.L[385]*work1d.v[481]-work1d.L[386]*work1d.v[482];
  work1d.d[483] = work1d.v[483];
  if (work1d.d[483] > 0)
    work1d.d[483] = -settings1d.kkt_reg;
  else
    work1d.d[483] -= settings1d.kkt_reg;
  work1d.d_inv[483] = 1/work1d.d[483];
  work1d.L[389] = (work1d.KKT[979])*work1d.d_inv[483];
  work1d.L[396] = (-work1d.L[394]*work1d.v[481]-work1d.L[395]*work1d.v[482])*work1d.d_inv[483];
  work1d.L[401] = (-work1d.L[400]*work1d.v[482])*work1d.d_inv[483];
  work1d.v[170] = work1d.L[387]*work1d.d[170];
  work1d.v[250] = work1d.L[388]*work1d.d[250];
  work1d.v[483] = work1d.L[389]*work1d.d[483];
  work1d.v[484] = work1d.KKT[980]-work1d.L[387]*work1d.v[170]-work1d.L[388]*work1d.v[250]-work1d.L[389]*work1d.v[483];
  work1d.d[484] = work1d.v[484];
  if (work1d.d[484] < 0)
    work1d.d[484] = settings1d.kkt_reg;
  else
    work1d.d[484] += settings1d.kkt_reg;
  work1d.d_inv[484] = 1/work1d.d[484];
  work1d.L[397] = (-work1d.L[396]*work1d.v[483])*work1d.d_inv[484];
  work1d.L[402] = (work1d.KKT[981]-work1d.L[401]*work1d.v[483])*work1d.d_inv[484];
  work1d.L[404] = (work1d.KKT[982])*work1d.d_inv[484];
  work1d.v[210] = work1d.L[390]*work1d.d[210];
  work1d.v[290] = work1d.L[391]*work1d.d[290];
  work1d.v[379] = work1d.L[392]*work1d.d[379];
  work1d.v[380] = work1d.L[393]*work1d.d[380];
  work1d.v[481] = work1d.L[394]*work1d.d[481];
  work1d.v[482] = work1d.L[395]*work1d.d[482];
  work1d.v[483] = work1d.L[396]*work1d.d[483];
  work1d.v[484] = work1d.L[397]*work1d.d[484];
  work1d.v[485] = work1d.KKT[983]-work1d.L[390]*work1d.v[210]-work1d.L[391]*work1d.v[290]-work1d.L[392]*work1d.v[379]-work1d.L[393]*work1d.v[380]-work1d.L[394]*work1d.v[481]-work1d.L[395]*work1d.v[482]-work1d.L[396]*work1d.v[483]-work1d.L[397]*work1d.v[484];
  work1d.d[485] = work1d.v[485];
  if (work1d.d[485] < 0)
    work1d.d[485] = settings1d.kkt_reg;
  else
    work1d.d[485] += settings1d.kkt_reg;
  work1d.d_inv[485] = 1/work1d.d[485];
  work1d.L[403] = (-work1d.L[400]*work1d.v[482]-work1d.L[401]*work1d.v[483]-work1d.L[402]*work1d.v[484])*work1d.d_inv[485];
  work1d.L[405] = (work1d.KKT[984]-work1d.L[404]*work1d.v[484])*work1d.d_inv[485];
  work1d.L[414] = (-work1d.L[412]*work1d.v[380])*work1d.d_inv[485];
  work1d.v[421] = work1d.L[398]*work1d.d[421];
  work1d.v[422] = work1d.L[399]*work1d.d[422];
  work1d.v[482] = work1d.L[400]*work1d.d[482];
  work1d.v[483] = work1d.L[401]*work1d.d[483];
  work1d.v[484] = work1d.L[402]*work1d.d[484];
  work1d.v[485] = work1d.L[403]*work1d.d[485];
  work1d.v[486] = 0-work1d.L[398]*work1d.v[421]-work1d.L[399]*work1d.v[422]-work1d.L[400]*work1d.v[482]-work1d.L[401]*work1d.v[483]-work1d.L[402]*work1d.v[484]-work1d.L[403]*work1d.v[485];
  work1d.d[486] = work1d.v[486];
  if (work1d.d[486] > 0)
    work1d.d[486] = -settings1d.kkt_reg;
  else
    work1d.d[486] -= settings1d.kkt_reg;
  work1d.d_inv[486] = 1/work1d.d[486];
  work1d.L[406] = (-work1d.L[404]*work1d.v[484]-work1d.L[405]*work1d.v[485])*work1d.d_inv[486];
  work1d.L[415] = (-work1d.L[414]*work1d.v[485])*work1d.d_inv[486];
  work1d.L[420] = (-work1d.L[418]*work1d.v[422])*work1d.d_inv[486];
  work1d.v[484] = work1d.L[404]*work1d.d[484];
  work1d.v[485] = work1d.L[405]*work1d.d[485];
  work1d.v[486] = work1d.L[406]*work1d.d[486];
  work1d.v[487] = 0-work1d.L[404]*work1d.v[484]-work1d.L[405]*work1d.v[485]-work1d.L[406]*work1d.v[486];
  work1d.d[487] = work1d.v[487];
  if (work1d.d[487] > 0)
    work1d.d[487] = -settings1d.kkt_reg;
  else
    work1d.d[487] -= settings1d.kkt_reg;
  work1d.d_inv[487] = 1/work1d.d[487];
  work1d.L[409] = (work1d.KKT[985])*work1d.d_inv[487];
  work1d.L[416] = (-work1d.L[414]*work1d.v[485]-work1d.L[415]*work1d.v[486])*work1d.d_inv[487];
  work1d.L[421] = (-work1d.L[420]*work1d.v[486])*work1d.d_inv[487];
  work1d.v[171] = work1d.L[407]*work1d.d[171];
  work1d.v[251] = work1d.L[408]*work1d.d[251];
  work1d.v[487] = work1d.L[409]*work1d.d[487];
  work1d.v[488] = work1d.KKT[986]-work1d.L[407]*work1d.v[171]-work1d.L[408]*work1d.v[251]-work1d.L[409]*work1d.v[487];
  work1d.d[488] = work1d.v[488];
  if (work1d.d[488] < 0)
    work1d.d[488] = settings1d.kkt_reg;
  else
    work1d.d[488] += settings1d.kkt_reg;
  work1d.d_inv[488] = 1/work1d.d[488];
  work1d.L[417] = (-work1d.L[416]*work1d.v[487])*work1d.d_inv[488];
  work1d.L[422] = (work1d.KKT[987]-work1d.L[421]*work1d.v[487])*work1d.d_inv[488];
  work1d.L[424] = (work1d.KKT[988])*work1d.d_inv[488];
  work1d.v[211] = work1d.L[410]*work1d.d[211];
  work1d.v[291] = work1d.L[411]*work1d.d[291];
  work1d.v[380] = work1d.L[412]*work1d.d[380];
  work1d.v[381] = work1d.L[413]*work1d.d[381];
  work1d.v[485] = work1d.L[414]*work1d.d[485];
  work1d.v[486] = work1d.L[415]*work1d.d[486];
  work1d.v[487] = work1d.L[416]*work1d.d[487];
  work1d.v[488] = work1d.L[417]*work1d.d[488];
  work1d.v[489] = work1d.KKT[989]-work1d.L[410]*work1d.v[211]-work1d.L[411]*work1d.v[291]-work1d.L[412]*work1d.v[380]-work1d.L[413]*work1d.v[381]-work1d.L[414]*work1d.v[485]-work1d.L[415]*work1d.v[486]-work1d.L[416]*work1d.v[487]-work1d.L[417]*work1d.v[488];
  work1d.d[489] = work1d.v[489];
  if (work1d.d[489] < 0)
    work1d.d[489] = settings1d.kkt_reg;
  else
    work1d.d[489] += settings1d.kkt_reg;
  work1d.d_inv[489] = 1/work1d.d[489];
  work1d.L[423] = (-work1d.L[420]*work1d.v[486]-work1d.L[421]*work1d.v[487]-work1d.L[422]*work1d.v[488])*work1d.d_inv[489];
  work1d.L[425] = (work1d.KKT[990]-work1d.L[424]*work1d.v[488])*work1d.d_inv[489];
  work1d.L[434] = (-work1d.L[432]*work1d.v[381])*work1d.d_inv[489];
  work1d.v[422] = work1d.L[418]*work1d.d[422];
  work1d.v[423] = work1d.L[419]*work1d.d[423];
  work1d.v[486] = work1d.L[420]*work1d.d[486];
  work1d.v[487] = work1d.L[421]*work1d.d[487];
  work1d.v[488] = work1d.L[422]*work1d.d[488];
  work1d.v[489] = work1d.L[423]*work1d.d[489];
  work1d.v[490] = 0-work1d.L[418]*work1d.v[422]-work1d.L[419]*work1d.v[423]-work1d.L[420]*work1d.v[486]-work1d.L[421]*work1d.v[487]-work1d.L[422]*work1d.v[488]-work1d.L[423]*work1d.v[489];
  work1d.d[490] = work1d.v[490];
  if (work1d.d[490] > 0)
    work1d.d[490] = -settings1d.kkt_reg;
  else
    work1d.d[490] -= settings1d.kkt_reg;
  work1d.d_inv[490] = 1/work1d.d[490];
  work1d.L[426] = (-work1d.L[424]*work1d.v[488]-work1d.L[425]*work1d.v[489])*work1d.d_inv[490];
  work1d.L[435] = (-work1d.L[434]*work1d.v[489])*work1d.d_inv[490];
  work1d.L[440] = (-work1d.L[438]*work1d.v[423])*work1d.d_inv[490];
  work1d.v[488] = work1d.L[424]*work1d.d[488];
  work1d.v[489] = work1d.L[425]*work1d.d[489];
  work1d.v[490] = work1d.L[426]*work1d.d[490];
  work1d.v[491] = 0-work1d.L[424]*work1d.v[488]-work1d.L[425]*work1d.v[489]-work1d.L[426]*work1d.v[490];
  work1d.d[491] = work1d.v[491];
  if (work1d.d[491] > 0)
    work1d.d[491] = -settings1d.kkt_reg;
  else
    work1d.d[491] -= settings1d.kkt_reg;
  work1d.d_inv[491] = 1/work1d.d[491];
  work1d.L[429] = (work1d.KKT[991])*work1d.d_inv[491];
  work1d.L[436] = (-work1d.L[434]*work1d.v[489]-work1d.L[435]*work1d.v[490])*work1d.d_inv[491];
  work1d.L[441] = (-work1d.L[440]*work1d.v[490])*work1d.d_inv[491];
  work1d.v[172] = work1d.L[427]*work1d.d[172];
  work1d.v[252] = work1d.L[428]*work1d.d[252];
  work1d.v[491] = work1d.L[429]*work1d.d[491];
  work1d.v[492] = work1d.KKT[992]-work1d.L[427]*work1d.v[172]-work1d.L[428]*work1d.v[252]-work1d.L[429]*work1d.v[491];
  work1d.d[492] = work1d.v[492];
  if (work1d.d[492] < 0)
    work1d.d[492] = settings1d.kkt_reg;
  else
    work1d.d[492] += settings1d.kkt_reg;
  work1d.d_inv[492] = 1/work1d.d[492];
  work1d.L[437] = (-work1d.L[436]*work1d.v[491])*work1d.d_inv[492];
  work1d.L[442] = (work1d.KKT[993]-work1d.L[441]*work1d.v[491])*work1d.d_inv[492];
  work1d.L[444] = (work1d.KKT[994])*work1d.d_inv[492];
  work1d.v[212] = work1d.L[430]*work1d.d[212];
  work1d.v[292] = work1d.L[431]*work1d.d[292];
  work1d.v[381] = work1d.L[432]*work1d.d[381];
  work1d.v[382] = work1d.L[433]*work1d.d[382];
  work1d.v[489] = work1d.L[434]*work1d.d[489];
  work1d.v[490] = work1d.L[435]*work1d.d[490];
  work1d.v[491] = work1d.L[436]*work1d.d[491];
  work1d.v[492] = work1d.L[437]*work1d.d[492];
  work1d.v[493] = work1d.KKT[995]-work1d.L[430]*work1d.v[212]-work1d.L[431]*work1d.v[292]-work1d.L[432]*work1d.v[381]-work1d.L[433]*work1d.v[382]-work1d.L[434]*work1d.v[489]-work1d.L[435]*work1d.v[490]-work1d.L[436]*work1d.v[491]-work1d.L[437]*work1d.v[492];
  work1d.d[493] = work1d.v[493];
  if (work1d.d[493] < 0)
    work1d.d[493] = settings1d.kkt_reg;
  else
    work1d.d[493] += settings1d.kkt_reg;
  work1d.d_inv[493] = 1/work1d.d[493];
  work1d.L[443] = (-work1d.L[440]*work1d.v[490]-work1d.L[441]*work1d.v[491]-work1d.L[442]*work1d.v[492])*work1d.d_inv[493];
  work1d.L[445] = (work1d.KKT[996]-work1d.L[444]*work1d.v[492])*work1d.d_inv[493];
  work1d.L[454] = (-work1d.L[452]*work1d.v[382])*work1d.d_inv[493];
  work1d.v[423] = work1d.L[438]*work1d.d[423];
  work1d.v[424] = work1d.L[439]*work1d.d[424];
  work1d.v[490] = work1d.L[440]*work1d.d[490];
  work1d.v[491] = work1d.L[441]*work1d.d[491];
  work1d.v[492] = work1d.L[442]*work1d.d[492];
  work1d.v[493] = work1d.L[443]*work1d.d[493];
  work1d.v[494] = 0-work1d.L[438]*work1d.v[423]-work1d.L[439]*work1d.v[424]-work1d.L[440]*work1d.v[490]-work1d.L[441]*work1d.v[491]-work1d.L[442]*work1d.v[492]-work1d.L[443]*work1d.v[493];
  work1d.d[494] = work1d.v[494];
  if (work1d.d[494] > 0)
    work1d.d[494] = -settings1d.kkt_reg;
  else
    work1d.d[494] -= settings1d.kkt_reg;
  work1d.d_inv[494] = 1/work1d.d[494];
  work1d.L[446] = (-work1d.L[444]*work1d.v[492]-work1d.L[445]*work1d.v[493])*work1d.d_inv[494];
  work1d.L[455] = (-work1d.L[454]*work1d.v[493])*work1d.d_inv[494];
  work1d.L[460] = (-work1d.L[458]*work1d.v[424])*work1d.d_inv[494];
  work1d.v[492] = work1d.L[444]*work1d.d[492];
  work1d.v[493] = work1d.L[445]*work1d.d[493];
  work1d.v[494] = work1d.L[446]*work1d.d[494];
  work1d.v[495] = 0-work1d.L[444]*work1d.v[492]-work1d.L[445]*work1d.v[493]-work1d.L[446]*work1d.v[494];
  work1d.d[495] = work1d.v[495];
  if (work1d.d[495] > 0)
    work1d.d[495] = -settings1d.kkt_reg;
  else
    work1d.d[495] -= settings1d.kkt_reg;
  work1d.d_inv[495] = 1/work1d.d[495];
  work1d.L[449] = (work1d.KKT[997])*work1d.d_inv[495];
  work1d.L[456] = (-work1d.L[454]*work1d.v[493]-work1d.L[455]*work1d.v[494])*work1d.d_inv[495];
  work1d.L[461] = (-work1d.L[460]*work1d.v[494])*work1d.d_inv[495];
  work1d.v[173] = work1d.L[447]*work1d.d[173];
  work1d.v[253] = work1d.L[448]*work1d.d[253];
  work1d.v[495] = work1d.L[449]*work1d.d[495];
  work1d.v[496] = work1d.KKT[998]-work1d.L[447]*work1d.v[173]-work1d.L[448]*work1d.v[253]-work1d.L[449]*work1d.v[495];
  work1d.d[496] = work1d.v[496];
  if (work1d.d[496] < 0)
    work1d.d[496] = settings1d.kkt_reg;
  else
    work1d.d[496] += settings1d.kkt_reg;
  work1d.d_inv[496] = 1/work1d.d[496];
  work1d.L[457] = (-work1d.L[456]*work1d.v[495])*work1d.d_inv[496];
  work1d.L[462] = (work1d.KKT[999]-work1d.L[461]*work1d.v[495])*work1d.d_inv[496];
  work1d.L[464] = (work1d.KKT[1000])*work1d.d_inv[496];
  work1d.v[213] = work1d.L[450]*work1d.d[213];
  work1d.v[293] = work1d.L[451]*work1d.d[293];
  work1d.v[382] = work1d.L[452]*work1d.d[382];
  work1d.v[383] = work1d.L[453]*work1d.d[383];
  work1d.v[493] = work1d.L[454]*work1d.d[493];
  work1d.v[494] = work1d.L[455]*work1d.d[494];
  work1d.v[495] = work1d.L[456]*work1d.d[495];
  work1d.v[496] = work1d.L[457]*work1d.d[496];
  work1d.v[497] = work1d.KKT[1001]-work1d.L[450]*work1d.v[213]-work1d.L[451]*work1d.v[293]-work1d.L[452]*work1d.v[382]-work1d.L[453]*work1d.v[383]-work1d.L[454]*work1d.v[493]-work1d.L[455]*work1d.v[494]-work1d.L[456]*work1d.v[495]-work1d.L[457]*work1d.v[496];
  work1d.d[497] = work1d.v[497];
  if (work1d.d[497] < 0)
    work1d.d[497] = settings1d.kkt_reg;
  else
    work1d.d[497] += settings1d.kkt_reg;
  work1d.d_inv[497] = 1/work1d.d[497];
  work1d.L[463] = (-work1d.L[460]*work1d.v[494]-work1d.L[461]*work1d.v[495]-work1d.L[462]*work1d.v[496])*work1d.d_inv[497];
  work1d.L[465] = (work1d.KKT[1002]-work1d.L[464]*work1d.v[496])*work1d.d_inv[497];
  work1d.L[474] = (-work1d.L[472]*work1d.v[383])*work1d.d_inv[497];
  work1d.v[424] = work1d.L[458]*work1d.d[424];
  work1d.v[425] = work1d.L[459]*work1d.d[425];
  work1d.v[494] = work1d.L[460]*work1d.d[494];
  work1d.v[495] = work1d.L[461]*work1d.d[495];
  work1d.v[496] = work1d.L[462]*work1d.d[496];
  work1d.v[497] = work1d.L[463]*work1d.d[497];
  work1d.v[498] = 0-work1d.L[458]*work1d.v[424]-work1d.L[459]*work1d.v[425]-work1d.L[460]*work1d.v[494]-work1d.L[461]*work1d.v[495]-work1d.L[462]*work1d.v[496]-work1d.L[463]*work1d.v[497];
  work1d.d[498] = work1d.v[498];
  if (work1d.d[498] > 0)
    work1d.d[498] = -settings1d.kkt_reg;
  else
    work1d.d[498] -= settings1d.kkt_reg;
  work1d.d_inv[498] = 1/work1d.d[498];
  work1d.L[466] = (-work1d.L[464]*work1d.v[496]-work1d.L[465]*work1d.v[497])*work1d.d_inv[498];
  work1d.L[475] = (-work1d.L[474]*work1d.v[497])*work1d.d_inv[498];
  work1d.L[480] = (-work1d.L[478]*work1d.v[425])*work1d.d_inv[498];
  work1d.v[496] = work1d.L[464]*work1d.d[496];
  work1d.v[497] = work1d.L[465]*work1d.d[497];
  work1d.v[498] = work1d.L[466]*work1d.d[498];
  work1d.v[499] = 0-work1d.L[464]*work1d.v[496]-work1d.L[465]*work1d.v[497]-work1d.L[466]*work1d.v[498];
  work1d.d[499] = work1d.v[499];
  if (work1d.d[499] > 0)
    work1d.d[499] = -settings1d.kkt_reg;
  else
    work1d.d[499] -= settings1d.kkt_reg;
  work1d.d_inv[499] = 1/work1d.d[499];
  work1d.L[469] = (work1d.KKT[1003])*work1d.d_inv[499];
  work1d.L[476] = (-work1d.L[474]*work1d.v[497]-work1d.L[475]*work1d.v[498])*work1d.d_inv[499];
  work1d.L[481] = (-work1d.L[480]*work1d.v[498])*work1d.d_inv[499];
  work1d.v[174] = work1d.L[467]*work1d.d[174];
  work1d.v[254] = work1d.L[468]*work1d.d[254];
  work1d.v[499] = work1d.L[469]*work1d.d[499];
  work1d.v[500] = work1d.KKT[1004]-work1d.L[467]*work1d.v[174]-work1d.L[468]*work1d.v[254]-work1d.L[469]*work1d.v[499];
  work1d.d[500] = work1d.v[500];
  if (work1d.d[500] < 0)
    work1d.d[500] = settings1d.kkt_reg;
  else
    work1d.d[500] += settings1d.kkt_reg;
  work1d.d_inv[500] = 1/work1d.d[500];
  work1d.L[477] = (-work1d.L[476]*work1d.v[499])*work1d.d_inv[500];
  work1d.L[482] = (work1d.KKT[1005]-work1d.L[481]*work1d.v[499])*work1d.d_inv[500];
  work1d.L[484] = (work1d.KKT[1006])*work1d.d_inv[500];
  work1d.v[214] = work1d.L[470]*work1d.d[214];
  work1d.v[294] = work1d.L[471]*work1d.d[294];
  work1d.v[383] = work1d.L[472]*work1d.d[383];
  work1d.v[384] = work1d.L[473]*work1d.d[384];
  work1d.v[497] = work1d.L[474]*work1d.d[497];
  work1d.v[498] = work1d.L[475]*work1d.d[498];
  work1d.v[499] = work1d.L[476]*work1d.d[499];
  work1d.v[500] = work1d.L[477]*work1d.d[500];
  work1d.v[501] = work1d.KKT[1007]-work1d.L[470]*work1d.v[214]-work1d.L[471]*work1d.v[294]-work1d.L[472]*work1d.v[383]-work1d.L[473]*work1d.v[384]-work1d.L[474]*work1d.v[497]-work1d.L[475]*work1d.v[498]-work1d.L[476]*work1d.v[499]-work1d.L[477]*work1d.v[500];
  work1d.d[501] = work1d.v[501];
  if (work1d.d[501] < 0)
    work1d.d[501] = settings1d.kkt_reg;
  else
    work1d.d[501] += settings1d.kkt_reg;
  work1d.d_inv[501] = 1/work1d.d[501];
  work1d.L[483] = (-work1d.L[480]*work1d.v[498]-work1d.L[481]*work1d.v[499]-work1d.L[482]*work1d.v[500])*work1d.d_inv[501];
  work1d.L[485] = (work1d.KKT[1008]-work1d.L[484]*work1d.v[500])*work1d.d_inv[501];
  work1d.L[494] = (-work1d.L[492]*work1d.v[384])*work1d.d_inv[501];
  work1d.v[425] = work1d.L[478]*work1d.d[425];
  work1d.v[426] = work1d.L[479]*work1d.d[426];
  work1d.v[498] = work1d.L[480]*work1d.d[498];
  work1d.v[499] = work1d.L[481]*work1d.d[499];
  work1d.v[500] = work1d.L[482]*work1d.d[500];
  work1d.v[501] = work1d.L[483]*work1d.d[501];
  work1d.v[502] = 0-work1d.L[478]*work1d.v[425]-work1d.L[479]*work1d.v[426]-work1d.L[480]*work1d.v[498]-work1d.L[481]*work1d.v[499]-work1d.L[482]*work1d.v[500]-work1d.L[483]*work1d.v[501];
  work1d.d[502] = work1d.v[502];
  if (work1d.d[502] > 0)
    work1d.d[502] = -settings1d.kkt_reg;
  else
    work1d.d[502] -= settings1d.kkt_reg;
  work1d.d_inv[502] = 1/work1d.d[502];
  work1d.L[486] = (-work1d.L[484]*work1d.v[500]-work1d.L[485]*work1d.v[501])*work1d.d_inv[502];
  work1d.L[495] = (-work1d.L[494]*work1d.v[501])*work1d.d_inv[502];
  work1d.L[500] = (-work1d.L[498]*work1d.v[426])*work1d.d_inv[502];
  work1d.v[500] = work1d.L[484]*work1d.d[500];
  work1d.v[501] = work1d.L[485]*work1d.d[501];
  work1d.v[502] = work1d.L[486]*work1d.d[502];
  work1d.v[503] = 0-work1d.L[484]*work1d.v[500]-work1d.L[485]*work1d.v[501]-work1d.L[486]*work1d.v[502];
  work1d.d[503] = work1d.v[503];
  if (work1d.d[503] > 0)
    work1d.d[503] = -settings1d.kkt_reg;
  else
    work1d.d[503] -= settings1d.kkt_reg;
  work1d.d_inv[503] = 1/work1d.d[503];
  work1d.L[489] = (work1d.KKT[1009])*work1d.d_inv[503];
  work1d.L[496] = (-work1d.L[494]*work1d.v[501]-work1d.L[495]*work1d.v[502])*work1d.d_inv[503];
  work1d.L[501] = (-work1d.L[500]*work1d.v[502])*work1d.d_inv[503];
  work1d.v[175] = work1d.L[487]*work1d.d[175];
  work1d.v[255] = work1d.L[488]*work1d.d[255];
  work1d.v[503] = work1d.L[489]*work1d.d[503];
  work1d.v[504] = work1d.KKT[1010]-work1d.L[487]*work1d.v[175]-work1d.L[488]*work1d.v[255]-work1d.L[489]*work1d.v[503];
  work1d.d[504] = work1d.v[504];
  if (work1d.d[504] < 0)
    work1d.d[504] = settings1d.kkt_reg;
  else
    work1d.d[504] += settings1d.kkt_reg;
  work1d.d_inv[504] = 1/work1d.d[504];
  work1d.L[497] = (-work1d.L[496]*work1d.v[503])*work1d.d_inv[504];
  work1d.L[502] = (work1d.KKT[1011]-work1d.L[501]*work1d.v[503])*work1d.d_inv[504];
  work1d.L[504] = (work1d.KKT[1012])*work1d.d_inv[504];
  work1d.v[215] = work1d.L[490]*work1d.d[215];
  work1d.v[295] = work1d.L[491]*work1d.d[295];
  work1d.v[384] = work1d.L[492]*work1d.d[384];
  work1d.v[385] = work1d.L[493]*work1d.d[385];
  work1d.v[501] = work1d.L[494]*work1d.d[501];
  work1d.v[502] = work1d.L[495]*work1d.d[502];
  work1d.v[503] = work1d.L[496]*work1d.d[503];
  work1d.v[504] = work1d.L[497]*work1d.d[504];
  work1d.v[505] = work1d.KKT[1013]-work1d.L[490]*work1d.v[215]-work1d.L[491]*work1d.v[295]-work1d.L[492]*work1d.v[384]-work1d.L[493]*work1d.v[385]-work1d.L[494]*work1d.v[501]-work1d.L[495]*work1d.v[502]-work1d.L[496]*work1d.v[503]-work1d.L[497]*work1d.v[504];
  work1d.d[505] = work1d.v[505];
  if (work1d.d[505] < 0)
    work1d.d[505] = settings1d.kkt_reg;
  else
    work1d.d[505] += settings1d.kkt_reg;
  work1d.d_inv[505] = 1/work1d.d[505];
  work1d.L[503] = (-work1d.L[500]*work1d.v[502]-work1d.L[501]*work1d.v[503]-work1d.L[502]*work1d.v[504])*work1d.d_inv[505];
  work1d.L[505] = (work1d.KKT[1014]-work1d.L[504]*work1d.v[504])*work1d.d_inv[505];
  work1d.L[514] = (-work1d.L[512]*work1d.v[385])*work1d.d_inv[505];
  work1d.v[426] = work1d.L[498]*work1d.d[426];
  work1d.v[427] = work1d.L[499]*work1d.d[427];
  work1d.v[502] = work1d.L[500]*work1d.d[502];
  work1d.v[503] = work1d.L[501]*work1d.d[503];
  work1d.v[504] = work1d.L[502]*work1d.d[504];
  work1d.v[505] = work1d.L[503]*work1d.d[505];
  work1d.v[506] = 0-work1d.L[498]*work1d.v[426]-work1d.L[499]*work1d.v[427]-work1d.L[500]*work1d.v[502]-work1d.L[501]*work1d.v[503]-work1d.L[502]*work1d.v[504]-work1d.L[503]*work1d.v[505];
  work1d.d[506] = work1d.v[506];
  if (work1d.d[506] > 0)
    work1d.d[506] = -settings1d.kkt_reg;
  else
    work1d.d[506] -= settings1d.kkt_reg;
  work1d.d_inv[506] = 1/work1d.d[506];
  work1d.L[506] = (-work1d.L[504]*work1d.v[504]-work1d.L[505]*work1d.v[505])*work1d.d_inv[506];
  work1d.L[515] = (-work1d.L[514]*work1d.v[505])*work1d.d_inv[506];
  work1d.L[520] = (-work1d.L[518]*work1d.v[427])*work1d.d_inv[506];
  work1d.v[504] = work1d.L[504]*work1d.d[504];
  work1d.v[505] = work1d.L[505]*work1d.d[505];
  work1d.v[506] = work1d.L[506]*work1d.d[506];
  work1d.v[507] = 0-work1d.L[504]*work1d.v[504]-work1d.L[505]*work1d.v[505]-work1d.L[506]*work1d.v[506];
  work1d.d[507] = work1d.v[507];
  if (work1d.d[507] > 0)
    work1d.d[507] = -settings1d.kkt_reg;
  else
    work1d.d[507] -= settings1d.kkt_reg;
  work1d.d_inv[507] = 1/work1d.d[507];
  work1d.L[509] = (work1d.KKT[1015])*work1d.d_inv[507];
  work1d.L[516] = (-work1d.L[514]*work1d.v[505]-work1d.L[515]*work1d.v[506])*work1d.d_inv[507];
  work1d.L[521] = (-work1d.L[520]*work1d.v[506])*work1d.d_inv[507];
  work1d.v[176] = work1d.L[507]*work1d.d[176];
  work1d.v[256] = work1d.L[508]*work1d.d[256];
  work1d.v[507] = work1d.L[509]*work1d.d[507];
  work1d.v[508] = work1d.KKT[1016]-work1d.L[507]*work1d.v[176]-work1d.L[508]*work1d.v[256]-work1d.L[509]*work1d.v[507];
  work1d.d[508] = work1d.v[508];
  if (work1d.d[508] < 0)
    work1d.d[508] = settings1d.kkt_reg;
  else
    work1d.d[508] += settings1d.kkt_reg;
  work1d.d_inv[508] = 1/work1d.d[508];
  work1d.L[517] = (-work1d.L[516]*work1d.v[507])*work1d.d_inv[508];
  work1d.L[522] = (work1d.KKT[1017]-work1d.L[521]*work1d.v[507])*work1d.d_inv[508];
  work1d.L[524] = (work1d.KKT[1018])*work1d.d_inv[508];
  work1d.v[216] = work1d.L[510]*work1d.d[216];
  work1d.v[296] = work1d.L[511]*work1d.d[296];
  work1d.v[385] = work1d.L[512]*work1d.d[385];
  work1d.v[386] = work1d.L[513]*work1d.d[386];
  work1d.v[505] = work1d.L[514]*work1d.d[505];
  work1d.v[506] = work1d.L[515]*work1d.d[506];
  work1d.v[507] = work1d.L[516]*work1d.d[507];
  work1d.v[508] = work1d.L[517]*work1d.d[508];
  work1d.v[509] = work1d.KKT[1019]-work1d.L[510]*work1d.v[216]-work1d.L[511]*work1d.v[296]-work1d.L[512]*work1d.v[385]-work1d.L[513]*work1d.v[386]-work1d.L[514]*work1d.v[505]-work1d.L[515]*work1d.v[506]-work1d.L[516]*work1d.v[507]-work1d.L[517]*work1d.v[508];
  work1d.d[509] = work1d.v[509];
  if (work1d.d[509] < 0)
    work1d.d[509] = settings1d.kkt_reg;
  else
    work1d.d[509] += settings1d.kkt_reg;
  work1d.d_inv[509] = 1/work1d.d[509];
  work1d.L[523] = (-work1d.L[520]*work1d.v[506]-work1d.L[521]*work1d.v[507]-work1d.L[522]*work1d.v[508])*work1d.d_inv[509];
  work1d.L[525] = (work1d.KKT[1020]-work1d.L[524]*work1d.v[508])*work1d.d_inv[509];
  work1d.L[534] = (-work1d.L[532]*work1d.v[386])*work1d.d_inv[509];
  work1d.v[427] = work1d.L[518]*work1d.d[427];
  work1d.v[428] = work1d.L[519]*work1d.d[428];
  work1d.v[506] = work1d.L[520]*work1d.d[506];
  work1d.v[507] = work1d.L[521]*work1d.d[507];
  work1d.v[508] = work1d.L[522]*work1d.d[508];
  work1d.v[509] = work1d.L[523]*work1d.d[509];
  work1d.v[510] = 0-work1d.L[518]*work1d.v[427]-work1d.L[519]*work1d.v[428]-work1d.L[520]*work1d.v[506]-work1d.L[521]*work1d.v[507]-work1d.L[522]*work1d.v[508]-work1d.L[523]*work1d.v[509];
  work1d.d[510] = work1d.v[510];
  if (work1d.d[510] > 0)
    work1d.d[510] = -settings1d.kkt_reg;
  else
    work1d.d[510] -= settings1d.kkt_reg;
  work1d.d_inv[510] = 1/work1d.d[510];
  work1d.L[526] = (-work1d.L[524]*work1d.v[508]-work1d.L[525]*work1d.v[509])*work1d.d_inv[510];
  work1d.L[535] = (-work1d.L[534]*work1d.v[509])*work1d.d_inv[510];
  work1d.L[540] = (-work1d.L[538]*work1d.v[428])*work1d.d_inv[510];
  work1d.v[508] = work1d.L[524]*work1d.d[508];
  work1d.v[509] = work1d.L[525]*work1d.d[509];
  work1d.v[510] = work1d.L[526]*work1d.d[510];
  work1d.v[511] = 0-work1d.L[524]*work1d.v[508]-work1d.L[525]*work1d.v[509]-work1d.L[526]*work1d.v[510];
  work1d.d[511] = work1d.v[511];
  if (work1d.d[511] > 0)
    work1d.d[511] = -settings1d.kkt_reg;
  else
    work1d.d[511] -= settings1d.kkt_reg;
  work1d.d_inv[511] = 1/work1d.d[511];
  work1d.L[529] = (work1d.KKT[1021])*work1d.d_inv[511];
  work1d.L[536] = (-work1d.L[534]*work1d.v[509]-work1d.L[535]*work1d.v[510])*work1d.d_inv[511];
  work1d.L[541] = (-work1d.L[540]*work1d.v[510])*work1d.d_inv[511];
  work1d.v[177] = work1d.L[527]*work1d.d[177];
  work1d.v[257] = work1d.L[528]*work1d.d[257];
  work1d.v[511] = work1d.L[529]*work1d.d[511];
  work1d.v[512] = work1d.KKT[1022]-work1d.L[527]*work1d.v[177]-work1d.L[528]*work1d.v[257]-work1d.L[529]*work1d.v[511];
  work1d.d[512] = work1d.v[512];
  if (work1d.d[512] < 0)
    work1d.d[512] = settings1d.kkt_reg;
  else
    work1d.d[512] += settings1d.kkt_reg;
  work1d.d_inv[512] = 1/work1d.d[512];
  work1d.L[537] = (-work1d.L[536]*work1d.v[511])*work1d.d_inv[512];
  work1d.L[542] = (work1d.KKT[1023]-work1d.L[541]*work1d.v[511])*work1d.d_inv[512];
  work1d.L[544] = (work1d.KKT[1024])*work1d.d_inv[512];
  work1d.v[217] = work1d.L[530]*work1d.d[217];
  work1d.v[297] = work1d.L[531]*work1d.d[297];
  work1d.v[386] = work1d.L[532]*work1d.d[386];
  work1d.v[387] = work1d.L[533]*work1d.d[387];
  work1d.v[509] = work1d.L[534]*work1d.d[509];
  work1d.v[510] = work1d.L[535]*work1d.d[510];
  work1d.v[511] = work1d.L[536]*work1d.d[511];
  work1d.v[512] = work1d.L[537]*work1d.d[512];
  work1d.v[513] = work1d.KKT[1025]-work1d.L[530]*work1d.v[217]-work1d.L[531]*work1d.v[297]-work1d.L[532]*work1d.v[386]-work1d.L[533]*work1d.v[387]-work1d.L[534]*work1d.v[509]-work1d.L[535]*work1d.v[510]-work1d.L[536]*work1d.v[511]-work1d.L[537]*work1d.v[512];
  work1d.d[513] = work1d.v[513];
  if (work1d.d[513] < 0)
    work1d.d[513] = settings1d.kkt_reg;
  else
    work1d.d[513] += settings1d.kkt_reg;
  work1d.d_inv[513] = 1/work1d.d[513];
  work1d.L[543] = (-work1d.L[540]*work1d.v[510]-work1d.L[541]*work1d.v[511]-work1d.L[542]*work1d.v[512])*work1d.d_inv[513];
  work1d.L[545] = (work1d.KKT[1026]-work1d.L[544]*work1d.v[512])*work1d.d_inv[513];
  work1d.L[554] = (-work1d.L[552]*work1d.v[387])*work1d.d_inv[513];
  work1d.v[428] = work1d.L[538]*work1d.d[428];
  work1d.v[429] = work1d.L[539]*work1d.d[429];
  work1d.v[510] = work1d.L[540]*work1d.d[510];
  work1d.v[511] = work1d.L[541]*work1d.d[511];
  work1d.v[512] = work1d.L[542]*work1d.d[512];
  work1d.v[513] = work1d.L[543]*work1d.d[513];
  work1d.v[514] = 0-work1d.L[538]*work1d.v[428]-work1d.L[539]*work1d.v[429]-work1d.L[540]*work1d.v[510]-work1d.L[541]*work1d.v[511]-work1d.L[542]*work1d.v[512]-work1d.L[543]*work1d.v[513];
  work1d.d[514] = work1d.v[514];
  if (work1d.d[514] > 0)
    work1d.d[514] = -settings1d.kkt_reg;
  else
    work1d.d[514] -= settings1d.kkt_reg;
  work1d.d_inv[514] = 1/work1d.d[514];
  work1d.L[546] = (-work1d.L[544]*work1d.v[512]-work1d.L[545]*work1d.v[513])*work1d.d_inv[514];
  work1d.L[555] = (-work1d.L[554]*work1d.v[513])*work1d.d_inv[514];
  work1d.L[560] = (-work1d.L[558]*work1d.v[429])*work1d.d_inv[514];
  work1d.v[512] = work1d.L[544]*work1d.d[512];
  work1d.v[513] = work1d.L[545]*work1d.d[513];
  work1d.v[514] = work1d.L[546]*work1d.d[514];
  work1d.v[515] = 0-work1d.L[544]*work1d.v[512]-work1d.L[545]*work1d.v[513]-work1d.L[546]*work1d.v[514];
  work1d.d[515] = work1d.v[515];
  if (work1d.d[515] > 0)
    work1d.d[515] = -settings1d.kkt_reg;
  else
    work1d.d[515] -= settings1d.kkt_reg;
  work1d.d_inv[515] = 1/work1d.d[515];
  work1d.L[549] = (work1d.KKT[1027])*work1d.d_inv[515];
  work1d.L[556] = (-work1d.L[554]*work1d.v[513]-work1d.L[555]*work1d.v[514])*work1d.d_inv[515];
  work1d.L[561] = (-work1d.L[560]*work1d.v[514])*work1d.d_inv[515];
  work1d.v[178] = work1d.L[547]*work1d.d[178];
  work1d.v[258] = work1d.L[548]*work1d.d[258];
  work1d.v[515] = work1d.L[549]*work1d.d[515];
  work1d.v[516] = work1d.KKT[1028]-work1d.L[547]*work1d.v[178]-work1d.L[548]*work1d.v[258]-work1d.L[549]*work1d.v[515];
  work1d.d[516] = work1d.v[516];
  if (work1d.d[516] < 0)
    work1d.d[516] = settings1d.kkt_reg;
  else
    work1d.d[516] += settings1d.kkt_reg;
  work1d.d_inv[516] = 1/work1d.d[516];
  work1d.L[557] = (-work1d.L[556]*work1d.v[515])*work1d.d_inv[516];
  work1d.L[562] = (work1d.KKT[1029]-work1d.L[561]*work1d.v[515])*work1d.d_inv[516];
  work1d.L[564] = (work1d.KKT[1030])*work1d.d_inv[516];
  work1d.v[218] = work1d.L[550]*work1d.d[218];
  work1d.v[298] = work1d.L[551]*work1d.d[298];
  work1d.v[387] = work1d.L[552]*work1d.d[387];
  work1d.v[388] = work1d.L[553]*work1d.d[388];
  work1d.v[513] = work1d.L[554]*work1d.d[513];
  work1d.v[514] = work1d.L[555]*work1d.d[514];
  work1d.v[515] = work1d.L[556]*work1d.d[515];
  work1d.v[516] = work1d.L[557]*work1d.d[516];
  work1d.v[517] = work1d.KKT[1031]-work1d.L[550]*work1d.v[218]-work1d.L[551]*work1d.v[298]-work1d.L[552]*work1d.v[387]-work1d.L[553]*work1d.v[388]-work1d.L[554]*work1d.v[513]-work1d.L[555]*work1d.v[514]-work1d.L[556]*work1d.v[515]-work1d.L[557]*work1d.v[516];
  work1d.d[517] = work1d.v[517];
  if (work1d.d[517] < 0)
    work1d.d[517] = settings1d.kkt_reg;
  else
    work1d.d[517] += settings1d.kkt_reg;
  work1d.d_inv[517] = 1/work1d.d[517];
  work1d.L[563] = (-work1d.L[560]*work1d.v[514]-work1d.L[561]*work1d.v[515]-work1d.L[562]*work1d.v[516])*work1d.d_inv[517];
  work1d.L[565] = (work1d.KKT[1032]-work1d.L[564]*work1d.v[516])*work1d.d_inv[517];
  work1d.L[574] = (-work1d.L[572]*work1d.v[388])*work1d.d_inv[517];
  work1d.v[429] = work1d.L[558]*work1d.d[429];
  work1d.v[430] = work1d.L[559]*work1d.d[430];
  work1d.v[514] = work1d.L[560]*work1d.d[514];
  work1d.v[515] = work1d.L[561]*work1d.d[515];
  work1d.v[516] = work1d.L[562]*work1d.d[516];
  work1d.v[517] = work1d.L[563]*work1d.d[517];
  work1d.v[518] = 0-work1d.L[558]*work1d.v[429]-work1d.L[559]*work1d.v[430]-work1d.L[560]*work1d.v[514]-work1d.L[561]*work1d.v[515]-work1d.L[562]*work1d.v[516]-work1d.L[563]*work1d.v[517];
  work1d.d[518] = work1d.v[518];
  if (work1d.d[518] > 0)
    work1d.d[518] = -settings1d.kkt_reg;
  else
    work1d.d[518] -= settings1d.kkt_reg;
  work1d.d_inv[518] = 1/work1d.d[518];
  work1d.L[566] = (-work1d.L[564]*work1d.v[516]-work1d.L[565]*work1d.v[517])*work1d.d_inv[518];
  work1d.L[575] = (-work1d.L[574]*work1d.v[517])*work1d.d_inv[518];
  work1d.L[580] = (-work1d.L[578]*work1d.v[430])*work1d.d_inv[518];
  work1d.v[516] = work1d.L[564]*work1d.d[516];
  work1d.v[517] = work1d.L[565]*work1d.d[517];
  work1d.v[518] = work1d.L[566]*work1d.d[518];
  work1d.v[519] = 0-work1d.L[564]*work1d.v[516]-work1d.L[565]*work1d.v[517]-work1d.L[566]*work1d.v[518];
  work1d.d[519] = work1d.v[519];
  if (work1d.d[519] > 0)
    work1d.d[519] = -settings1d.kkt_reg;
  else
    work1d.d[519] -= settings1d.kkt_reg;
  work1d.d_inv[519] = 1/work1d.d[519];
  work1d.L[569] = (work1d.KKT[1033])*work1d.d_inv[519];
  work1d.L[576] = (-work1d.L[574]*work1d.v[517]-work1d.L[575]*work1d.v[518])*work1d.d_inv[519];
  work1d.L[581] = (-work1d.L[580]*work1d.v[518])*work1d.d_inv[519];
  work1d.v[179] = work1d.L[567]*work1d.d[179];
  work1d.v[259] = work1d.L[568]*work1d.d[259];
  work1d.v[519] = work1d.L[569]*work1d.d[519];
  work1d.v[520] = work1d.KKT[1034]-work1d.L[567]*work1d.v[179]-work1d.L[568]*work1d.v[259]-work1d.L[569]*work1d.v[519];
  work1d.d[520] = work1d.v[520];
  if (work1d.d[520] < 0)
    work1d.d[520] = settings1d.kkt_reg;
  else
    work1d.d[520] += settings1d.kkt_reg;
  work1d.d_inv[520] = 1/work1d.d[520];
  work1d.L[577] = (-work1d.L[576]*work1d.v[519])*work1d.d_inv[520];
  work1d.L[582] = (work1d.KKT[1035]-work1d.L[581]*work1d.v[519])*work1d.d_inv[520];
  work1d.L[584] = (work1d.KKT[1036])*work1d.d_inv[520];
  work1d.v[219] = work1d.L[570]*work1d.d[219];
  work1d.v[299] = work1d.L[571]*work1d.d[299];
  work1d.v[388] = work1d.L[572]*work1d.d[388];
  work1d.v[389] = work1d.L[573]*work1d.d[389];
  work1d.v[517] = work1d.L[574]*work1d.d[517];
  work1d.v[518] = work1d.L[575]*work1d.d[518];
  work1d.v[519] = work1d.L[576]*work1d.d[519];
  work1d.v[520] = work1d.L[577]*work1d.d[520];
  work1d.v[521] = work1d.KKT[1037]-work1d.L[570]*work1d.v[219]-work1d.L[571]*work1d.v[299]-work1d.L[572]*work1d.v[388]-work1d.L[573]*work1d.v[389]-work1d.L[574]*work1d.v[517]-work1d.L[575]*work1d.v[518]-work1d.L[576]*work1d.v[519]-work1d.L[577]*work1d.v[520];
  work1d.d[521] = work1d.v[521];
  if (work1d.d[521] < 0)
    work1d.d[521] = settings1d.kkt_reg;
  else
    work1d.d[521] += settings1d.kkt_reg;
  work1d.d_inv[521] = 1/work1d.d[521];
  work1d.L[583] = (-work1d.L[580]*work1d.v[518]-work1d.L[581]*work1d.v[519]-work1d.L[582]*work1d.v[520])*work1d.d_inv[521];
  work1d.L[585] = (work1d.KKT[1038]-work1d.L[584]*work1d.v[520])*work1d.d_inv[521];
  work1d.L[594] = (-work1d.L[592]*work1d.v[389])*work1d.d_inv[521];
  work1d.v[430] = work1d.L[578]*work1d.d[430];
  work1d.v[431] = work1d.L[579]*work1d.d[431];
  work1d.v[518] = work1d.L[580]*work1d.d[518];
  work1d.v[519] = work1d.L[581]*work1d.d[519];
  work1d.v[520] = work1d.L[582]*work1d.d[520];
  work1d.v[521] = work1d.L[583]*work1d.d[521];
  work1d.v[522] = 0-work1d.L[578]*work1d.v[430]-work1d.L[579]*work1d.v[431]-work1d.L[580]*work1d.v[518]-work1d.L[581]*work1d.v[519]-work1d.L[582]*work1d.v[520]-work1d.L[583]*work1d.v[521];
  work1d.d[522] = work1d.v[522];
  if (work1d.d[522] > 0)
    work1d.d[522] = -settings1d.kkt_reg;
  else
    work1d.d[522] -= settings1d.kkt_reg;
  work1d.d_inv[522] = 1/work1d.d[522];
  work1d.L[586] = (-work1d.L[584]*work1d.v[520]-work1d.L[585]*work1d.v[521])*work1d.d_inv[522];
  work1d.L[595] = (-work1d.L[594]*work1d.v[521])*work1d.d_inv[522];
  work1d.L[600] = (-work1d.L[598]*work1d.v[431])*work1d.d_inv[522];
  work1d.v[520] = work1d.L[584]*work1d.d[520];
  work1d.v[521] = work1d.L[585]*work1d.d[521];
  work1d.v[522] = work1d.L[586]*work1d.d[522];
  work1d.v[523] = 0-work1d.L[584]*work1d.v[520]-work1d.L[585]*work1d.v[521]-work1d.L[586]*work1d.v[522];
  work1d.d[523] = work1d.v[523];
  if (work1d.d[523] > 0)
    work1d.d[523] = -settings1d.kkt_reg;
  else
    work1d.d[523] -= settings1d.kkt_reg;
  work1d.d_inv[523] = 1/work1d.d[523];
  work1d.L[589] = (work1d.KKT[1039])*work1d.d_inv[523];
  work1d.L[596] = (-work1d.L[594]*work1d.v[521]-work1d.L[595]*work1d.v[522])*work1d.d_inv[523];
  work1d.L[601] = (-work1d.L[600]*work1d.v[522])*work1d.d_inv[523];
  work1d.v[180] = work1d.L[587]*work1d.d[180];
  work1d.v[260] = work1d.L[588]*work1d.d[260];
  work1d.v[523] = work1d.L[589]*work1d.d[523];
  work1d.v[524] = work1d.KKT[1040]-work1d.L[587]*work1d.v[180]-work1d.L[588]*work1d.v[260]-work1d.L[589]*work1d.v[523];
  work1d.d[524] = work1d.v[524];
  if (work1d.d[524] < 0)
    work1d.d[524] = settings1d.kkt_reg;
  else
    work1d.d[524] += settings1d.kkt_reg;
  work1d.d_inv[524] = 1/work1d.d[524];
  work1d.L[597] = (-work1d.L[596]*work1d.v[523])*work1d.d_inv[524];
  work1d.L[602] = (work1d.KKT[1041]-work1d.L[601]*work1d.v[523])*work1d.d_inv[524];
  work1d.L[604] = (work1d.KKT[1042])*work1d.d_inv[524];
  work1d.v[220] = work1d.L[590]*work1d.d[220];
  work1d.v[300] = work1d.L[591]*work1d.d[300];
  work1d.v[389] = work1d.L[592]*work1d.d[389];
  work1d.v[390] = work1d.L[593]*work1d.d[390];
  work1d.v[521] = work1d.L[594]*work1d.d[521];
  work1d.v[522] = work1d.L[595]*work1d.d[522];
  work1d.v[523] = work1d.L[596]*work1d.d[523];
  work1d.v[524] = work1d.L[597]*work1d.d[524];
  work1d.v[525] = work1d.KKT[1043]-work1d.L[590]*work1d.v[220]-work1d.L[591]*work1d.v[300]-work1d.L[592]*work1d.v[389]-work1d.L[593]*work1d.v[390]-work1d.L[594]*work1d.v[521]-work1d.L[595]*work1d.v[522]-work1d.L[596]*work1d.v[523]-work1d.L[597]*work1d.v[524];
  work1d.d[525] = work1d.v[525];
  if (work1d.d[525] < 0)
    work1d.d[525] = settings1d.kkt_reg;
  else
    work1d.d[525] += settings1d.kkt_reg;
  work1d.d_inv[525] = 1/work1d.d[525];
  work1d.L[603] = (-work1d.L[600]*work1d.v[522]-work1d.L[601]*work1d.v[523]-work1d.L[602]*work1d.v[524])*work1d.d_inv[525];
  work1d.L[605] = (work1d.KKT[1044]-work1d.L[604]*work1d.v[524])*work1d.d_inv[525];
  work1d.L[614] = (-work1d.L[612]*work1d.v[390])*work1d.d_inv[525];
  work1d.v[431] = work1d.L[598]*work1d.d[431];
  work1d.v[432] = work1d.L[599]*work1d.d[432];
  work1d.v[522] = work1d.L[600]*work1d.d[522];
  work1d.v[523] = work1d.L[601]*work1d.d[523];
  work1d.v[524] = work1d.L[602]*work1d.d[524];
  work1d.v[525] = work1d.L[603]*work1d.d[525];
  work1d.v[526] = 0-work1d.L[598]*work1d.v[431]-work1d.L[599]*work1d.v[432]-work1d.L[600]*work1d.v[522]-work1d.L[601]*work1d.v[523]-work1d.L[602]*work1d.v[524]-work1d.L[603]*work1d.v[525];
  work1d.d[526] = work1d.v[526];
  if (work1d.d[526] > 0)
    work1d.d[526] = -settings1d.kkt_reg;
  else
    work1d.d[526] -= settings1d.kkt_reg;
  work1d.d_inv[526] = 1/work1d.d[526];
  work1d.L[606] = (-work1d.L[604]*work1d.v[524]-work1d.L[605]*work1d.v[525])*work1d.d_inv[526];
  work1d.L[615] = (-work1d.L[614]*work1d.v[525])*work1d.d_inv[526];
  work1d.L[620] = (-work1d.L[618]*work1d.v[432])*work1d.d_inv[526];
  work1d.v[524] = work1d.L[604]*work1d.d[524];
  work1d.v[525] = work1d.L[605]*work1d.d[525];
  work1d.v[526] = work1d.L[606]*work1d.d[526];
  work1d.v[527] = 0-work1d.L[604]*work1d.v[524]-work1d.L[605]*work1d.v[525]-work1d.L[606]*work1d.v[526];
  work1d.d[527] = work1d.v[527];
  if (work1d.d[527] > 0)
    work1d.d[527] = -settings1d.kkt_reg;
  else
    work1d.d[527] -= settings1d.kkt_reg;
  work1d.d_inv[527] = 1/work1d.d[527];
  work1d.L[609] = (work1d.KKT[1045])*work1d.d_inv[527];
  work1d.L[616] = (-work1d.L[614]*work1d.v[525]-work1d.L[615]*work1d.v[526])*work1d.d_inv[527];
  work1d.L[621] = (-work1d.L[620]*work1d.v[526])*work1d.d_inv[527];
  work1d.v[181] = work1d.L[607]*work1d.d[181];
  work1d.v[261] = work1d.L[608]*work1d.d[261];
  work1d.v[527] = work1d.L[609]*work1d.d[527];
  work1d.v[528] = work1d.KKT[1046]-work1d.L[607]*work1d.v[181]-work1d.L[608]*work1d.v[261]-work1d.L[609]*work1d.v[527];
  work1d.d[528] = work1d.v[528];
  if (work1d.d[528] < 0)
    work1d.d[528] = settings1d.kkt_reg;
  else
    work1d.d[528] += settings1d.kkt_reg;
  work1d.d_inv[528] = 1/work1d.d[528];
  work1d.L[617] = (-work1d.L[616]*work1d.v[527])*work1d.d_inv[528];
  work1d.L[622] = (work1d.KKT[1047]-work1d.L[621]*work1d.v[527])*work1d.d_inv[528];
  work1d.L[624] = (work1d.KKT[1048])*work1d.d_inv[528];
  work1d.v[221] = work1d.L[610]*work1d.d[221];
  work1d.v[301] = work1d.L[611]*work1d.d[301];
  work1d.v[390] = work1d.L[612]*work1d.d[390];
  work1d.v[391] = work1d.L[613]*work1d.d[391];
  work1d.v[525] = work1d.L[614]*work1d.d[525];
  work1d.v[526] = work1d.L[615]*work1d.d[526];
  work1d.v[527] = work1d.L[616]*work1d.d[527];
  work1d.v[528] = work1d.L[617]*work1d.d[528];
  work1d.v[529] = work1d.KKT[1049]-work1d.L[610]*work1d.v[221]-work1d.L[611]*work1d.v[301]-work1d.L[612]*work1d.v[390]-work1d.L[613]*work1d.v[391]-work1d.L[614]*work1d.v[525]-work1d.L[615]*work1d.v[526]-work1d.L[616]*work1d.v[527]-work1d.L[617]*work1d.v[528];
  work1d.d[529] = work1d.v[529];
  if (work1d.d[529] < 0)
    work1d.d[529] = settings1d.kkt_reg;
  else
    work1d.d[529] += settings1d.kkt_reg;
  work1d.d_inv[529] = 1/work1d.d[529];
  work1d.L[623] = (-work1d.L[620]*work1d.v[526]-work1d.L[621]*work1d.v[527]-work1d.L[622]*work1d.v[528])*work1d.d_inv[529];
  work1d.L[625] = (work1d.KKT[1050]-work1d.L[624]*work1d.v[528])*work1d.d_inv[529];
  work1d.L[634] = (-work1d.L[632]*work1d.v[391])*work1d.d_inv[529];
  work1d.v[432] = work1d.L[618]*work1d.d[432];
  work1d.v[433] = work1d.L[619]*work1d.d[433];
  work1d.v[526] = work1d.L[620]*work1d.d[526];
  work1d.v[527] = work1d.L[621]*work1d.d[527];
  work1d.v[528] = work1d.L[622]*work1d.d[528];
  work1d.v[529] = work1d.L[623]*work1d.d[529];
  work1d.v[530] = 0-work1d.L[618]*work1d.v[432]-work1d.L[619]*work1d.v[433]-work1d.L[620]*work1d.v[526]-work1d.L[621]*work1d.v[527]-work1d.L[622]*work1d.v[528]-work1d.L[623]*work1d.v[529];
  work1d.d[530] = work1d.v[530];
  if (work1d.d[530] > 0)
    work1d.d[530] = -settings1d.kkt_reg;
  else
    work1d.d[530] -= settings1d.kkt_reg;
  work1d.d_inv[530] = 1/work1d.d[530];
  work1d.L[626] = (-work1d.L[624]*work1d.v[528]-work1d.L[625]*work1d.v[529])*work1d.d_inv[530];
  work1d.L[635] = (-work1d.L[634]*work1d.v[529])*work1d.d_inv[530];
  work1d.L[640] = (-work1d.L[638]*work1d.v[433])*work1d.d_inv[530];
  work1d.v[528] = work1d.L[624]*work1d.d[528];
  work1d.v[529] = work1d.L[625]*work1d.d[529];
  work1d.v[530] = work1d.L[626]*work1d.d[530];
  work1d.v[531] = 0-work1d.L[624]*work1d.v[528]-work1d.L[625]*work1d.v[529]-work1d.L[626]*work1d.v[530];
  work1d.d[531] = work1d.v[531];
  if (work1d.d[531] > 0)
    work1d.d[531] = -settings1d.kkt_reg;
  else
    work1d.d[531] -= settings1d.kkt_reg;
  work1d.d_inv[531] = 1/work1d.d[531];
  work1d.L[629] = (work1d.KKT[1051])*work1d.d_inv[531];
  work1d.L[636] = (-work1d.L[634]*work1d.v[529]-work1d.L[635]*work1d.v[530])*work1d.d_inv[531];
  work1d.L[641] = (-work1d.L[640]*work1d.v[530])*work1d.d_inv[531];
  work1d.v[182] = work1d.L[627]*work1d.d[182];
  work1d.v[262] = work1d.L[628]*work1d.d[262];
  work1d.v[531] = work1d.L[629]*work1d.d[531];
  work1d.v[532] = work1d.KKT[1052]-work1d.L[627]*work1d.v[182]-work1d.L[628]*work1d.v[262]-work1d.L[629]*work1d.v[531];
  work1d.d[532] = work1d.v[532];
  if (work1d.d[532] < 0)
    work1d.d[532] = settings1d.kkt_reg;
  else
    work1d.d[532] += settings1d.kkt_reg;
  work1d.d_inv[532] = 1/work1d.d[532];
  work1d.L[637] = (-work1d.L[636]*work1d.v[531])*work1d.d_inv[532];
  work1d.L[642] = (work1d.KKT[1053]-work1d.L[641]*work1d.v[531])*work1d.d_inv[532];
  work1d.L[644] = (work1d.KKT[1054])*work1d.d_inv[532];
  work1d.v[222] = work1d.L[630]*work1d.d[222];
  work1d.v[302] = work1d.L[631]*work1d.d[302];
  work1d.v[391] = work1d.L[632]*work1d.d[391];
  work1d.v[392] = work1d.L[633]*work1d.d[392];
  work1d.v[529] = work1d.L[634]*work1d.d[529];
  work1d.v[530] = work1d.L[635]*work1d.d[530];
  work1d.v[531] = work1d.L[636]*work1d.d[531];
  work1d.v[532] = work1d.L[637]*work1d.d[532];
  work1d.v[533] = work1d.KKT[1055]-work1d.L[630]*work1d.v[222]-work1d.L[631]*work1d.v[302]-work1d.L[632]*work1d.v[391]-work1d.L[633]*work1d.v[392]-work1d.L[634]*work1d.v[529]-work1d.L[635]*work1d.v[530]-work1d.L[636]*work1d.v[531]-work1d.L[637]*work1d.v[532];
  work1d.d[533] = work1d.v[533];
  if (work1d.d[533] < 0)
    work1d.d[533] = settings1d.kkt_reg;
  else
    work1d.d[533] += settings1d.kkt_reg;
  work1d.d_inv[533] = 1/work1d.d[533];
  work1d.L[643] = (-work1d.L[640]*work1d.v[530]-work1d.L[641]*work1d.v[531]-work1d.L[642]*work1d.v[532])*work1d.d_inv[533];
  work1d.L[645] = (work1d.KKT[1056]-work1d.L[644]*work1d.v[532])*work1d.d_inv[533];
  work1d.L[654] = (-work1d.L[652]*work1d.v[392])*work1d.d_inv[533];
  work1d.v[433] = work1d.L[638]*work1d.d[433];
  work1d.v[434] = work1d.L[639]*work1d.d[434];
  work1d.v[530] = work1d.L[640]*work1d.d[530];
  work1d.v[531] = work1d.L[641]*work1d.d[531];
  work1d.v[532] = work1d.L[642]*work1d.d[532];
  work1d.v[533] = work1d.L[643]*work1d.d[533];
  work1d.v[534] = 0-work1d.L[638]*work1d.v[433]-work1d.L[639]*work1d.v[434]-work1d.L[640]*work1d.v[530]-work1d.L[641]*work1d.v[531]-work1d.L[642]*work1d.v[532]-work1d.L[643]*work1d.v[533];
  work1d.d[534] = work1d.v[534];
  if (work1d.d[534] > 0)
    work1d.d[534] = -settings1d.kkt_reg;
  else
    work1d.d[534] -= settings1d.kkt_reg;
  work1d.d_inv[534] = 1/work1d.d[534];
  work1d.L[646] = (-work1d.L[644]*work1d.v[532]-work1d.L[645]*work1d.v[533])*work1d.d_inv[534];
  work1d.L[655] = (-work1d.L[654]*work1d.v[533])*work1d.d_inv[534];
  work1d.L[660] = (-work1d.L[658]*work1d.v[434])*work1d.d_inv[534];
  work1d.v[532] = work1d.L[644]*work1d.d[532];
  work1d.v[533] = work1d.L[645]*work1d.d[533];
  work1d.v[534] = work1d.L[646]*work1d.d[534];
  work1d.v[535] = 0-work1d.L[644]*work1d.v[532]-work1d.L[645]*work1d.v[533]-work1d.L[646]*work1d.v[534];
  work1d.d[535] = work1d.v[535];
  if (work1d.d[535] > 0)
    work1d.d[535] = -settings1d.kkt_reg;
  else
    work1d.d[535] -= settings1d.kkt_reg;
  work1d.d_inv[535] = 1/work1d.d[535];
  work1d.L[649] = (work1d.KKT[1057])*work1d.d_inv[535];
  work1d.L[656] = (-work1d.L[654]*work1d.v[533]-work1d.L[655]*work1d.v[534])*work1d.d_inv[535];
  work1d.L[661] = (-work1d.L[660]*work1d.v[534])*work1d.d_inv[535];
  work1d.v[183] = work1d.L[647]*work1d.d[183];
  work1d.v[263] = work1d.L[648]*work1d.d[263];
  work1d.v[535] = work1d.L[649]*work1d.d[535];
  work1d.v[536] = work1d.KKT[1058]-work1d.L[647]*work1d.v[183]-work1d.L[648]*work1d.v[263]-work1d.L[649]*work1d.v[535];
  work1d.d[536] = work1d.v[536];
  if (work1d.d[536] < 0)
    work1d.d[536] = settings1d.kkt_reg;
  else
    work1d.d[536] += settings1d.kkt_reg;
  work1d.d_inv[536] = 1/work1d.d[536];
  work1d.L[657] = (-work1d.L[656]*work1d.v[535])*work1d.d_inv[536];
  work1d.L[662] = (work1d.KKT[1059]-work1d.L[661]*work1d.v[535])*work1d.d_inv[536];
  work1d.L[664] = (work1d.KKT[1060])*work1d.d_inv[536];
  work1d.v[223] = work1d.L[650]*work1d.d[223];
  work1d.v[303] = work1d.L[651]*work1d.d[303];
  work1d.v[392] = work1d.L[652]*work1d.d[392];
  work1d.v[393] = work1d.L[653]*work1d.d[393];
  work1d.v[533] = work1d.L[654]*work1d.d[533];
  work1d.v[534] = work1d.L[655]*work1d.d[534];
  work1d.v[535] = work1d.L[656]*work1d.d[535];
  work1d.v[536] = work1d.L[657]*work1d.d[536];
  work1d.v[537] = work1d.KKT[1061]-work1d.L[650]*work1d.v[223]-work1d.L[651]*work1d.v[303]-work1d.L[652]*work1d.v[392]-work1d.L[653]*work1d.v[393]-work1d.L[654]*work1d.v[533]-work1d.L[655]*work1d.v[534]-work1d.L[656]*work1d.v[535]-work1d.L[657]*work1d.v[536];
  work1d.d[537] = work1d.v[537];
  if (work1d.d[537] < 0)
    work1d.d[537] = settings1d.kkt_reg;
  else
    work1d.d[537] += settings1d.kkt_reg;
  work1d.d_inv[537] = 1/work1d.d[537];
  work1d.L[663] = (-work1d.L[660]*work1d.v[534]-work1d.L[661]*work1d.v[535]-work1d.L[662]*work1d.v[536])*work1d.d_inv[537];
  work1d.L[665] = (work1d.KKT[1062]-work1d.L[664]*work1d.v[536])*work1d.d_inv[537];
  work1d.L[674] = (-work1d.L[672]*work1d.v[393])*work1d.d_inv[537];
  work1d.v[434] = work1d.L[658]*work1d.d[434];
  work1d.v[435] = work1d.L[659]*work1d.d[435];
  work1d.v[534] = work1d.L[660]*work1d.d[534];
  work1d.v[535] = work1d.L[661]*work1d.d[535];
  work1d.v[536] = work1d.L[662]*work1d.d[536];
  work1d.v[537] = work1d.L[663]*work1d.d[537];
  work1d.v[538] = 0-work1d.L[658]*work1d.v[434]-work1d.L[659]*work1d.v[435]-work1d.L[660]*work1d.v[534]-work1d.L[661]*work1d.v[535]-work1d.L[662]*work1d.v[536]-work1d.L[663]*work1d.v[537];
  work1d.d[538] = work1d.v[538];
  if (work1d.d[538] > 0)
    work1d.d[538] = -settings1d.kkt_reg;
  else
    work1d.d[538] -= settings1d.kkt_reg;
  work1d.d_inv[538] = 1/work1d.d[538];
  work1d.L[666] = (-work1d.L[664]*work1d.v[536]-work1d.L[665]*work1d.v[537])*work1d.d_inv[538];
  work1d.L[675] = (-work1d.L[674]*work1d.v[537])*work1d.d_inv[538];
  work1d.L[680] = (-work1d.L[678]*work1d.v[435])*work1d.d_inv[538];
  work1d.v[536] = work1d.L[664]*work1d.d[536];
  work1d.v[537] = work1d.L[665]*work1d.d[537];
  work1d.v[538] = work1d.L[666]*work1d.d[538];
  work1d.v[539] = 0-work1d.L[664]*work1d.v[536]-work1d.L[665]*work1d.v[537]-work1d.L[666]*work1d.v[538];
  work1d.d[539] = work1d.v[539];
  if (work1d.d[539] > 0)
    work1d.d[539] = -settings1d.kkt_reg;
  else
    work1d.d[539] -= settings1d.kkt_reg;
  work1d.d_inv[539] = 1/work1d.d[539];
  work1d.L[669] = (work1d.KKT[1063])*work1d.d_inv[539];
  work1d.L[676] = (-work1d.L[674]*work1d.v[537]-work1d.L[675]*work1d.v[538])*work1d.d_inv[539];
  work1d.L[681] = (-work1d.L[680]*work1d.v[538])*work1d.d_inv[539];
  work1d.v[184] = work1d.L[667]*work1d.d[184];
  work1d.v[264] = work1d.L[668]*work1d.d[264];
  work1d.v[539] = work1d.L[669]*work1d.d[539];
  work1d.v[540] = work1d.KKT[1064]-work1d.L[667]*work1d.v[184]-work1d.L[668]*work1d.v[264]-work1d.L[669]*work1d.v[539];
  work1d.d[540] = work1d.v[540];
  if (work1d.d[540] < 0)
    work1d.d[540] = settings1d.kkt_reg;
  else
    work1d.d[540] += settings1d.kkt_reg;
  work1d.d_inv[540] = 1/work1d.d[540];
  work1d.L[677] = (-work1d.L[676]*work1d.v[539])*work1d.d_inv[540];
  work1d.L[682] = (work1d.KKT[1065]-work1d.L[681]*work1d.v[539])*work1d.d_inv[540];
  work1d.L[684] = (work1d.KKT[1066])*work1d.d_inv[540];
  work1d.v[224] = work1d.L[670]*work1d.d[224];
  work1d.v[304] = work1d.L[671]*work1d.d[304];
  work1d.v[393] = work1d.L[672]*work1d.d[393];
  work1d.v[394] = work1d.L[673]*work1d.d[394];
  work1d.v[537] = work1d.L[674]*work1d.d[537];
  work1d.v[538] = work1d.L[675]*work1d.d[538];
  work1d.v[539] = work1d.L[676]*work1d.d[539];
  work1d.v[540] = work1d.L[677]*work1d.d[540];
  work1d.v[541] = work1d.KKT[1067]-work1d.L[670]*work1d.v[224]-work1d.L[671]*work1d.v[304]-work1d.L[672]*work1d.v[393]-work1d.L[673]*work1d.v[394]-work1d.L[674]*work1d.v[537]-work1d.L[675]*work1d.v[538]-work1d.L[676]*work1d.v[539]-work1d.L[677]*work1d.v[540];
  work1d.d[541] = work1d.v[541];
  if (work1d.d[541] < 0)
    work1d.d[541] = settings1d.kkt_reg;
  else
    work1d.d[541] += settings1d.kkt_reg;
  work1d.d_inv[541] = 1/work1d.d[541];
  work1d.L[683] = (-work1d.L[680]*work1d.v[538]-work1d.L[681]*work1d.v[539]-work1d.L[682]*work1d.v[540])*work1d.d_inv[541];
  work1d.L[685] = (work1d.KKT[1068]-work1d.L[684]*work1d.v[540])*work1d.d_inv[541];
  work1d.L[694] = (-work1d.L[692]*work1d.v[394])*work1d.d_inv[541];
  work1d.v[435] = work1d.L[678]*work1d.d[435];
  work1d.v[436] = work1d.L[679]*work1d.d[436];
  work1d.v[538] = work1d.L[680]*work1d.d[538];
  work1d.v[539] = work1d.L[681]*work1d.d[539];
  work1d.v[540] = work1d.L[682]*work1d.d[540];
  work1d.v[541] = work1d.L[683]*work1d.d[541];
  work1d.v[542] = 0-work1d.L[678]*work1d.v[435]-work1d.L[679]*work1d.v[436]-work1d.L[680]*work1d.v[538]-work1d.L[681]*work1d.v[539]-work1d.L[682]*work1d.v[540]-work1d.L[683]*work1d.v[541];
  work1d.d[542] = work1d.v[542];
  if (work1d.d[542] > 0)
    work1d.d[542] = -settings1d.kkt_reg;
  else
    work1d.d[542] -= settings1d.kkt_reg;
  work1d.d_inv[542] = 1/work1d.d[542];
  work1d.L[686] = (-work1d.L[684]*work1d.v[540]-work1d.L[685]*work1d.v[541])*work1d.d_inv[542];
  work1d.L[695] = (-work1d.L[694]*work1d.v[541])*work1d.d_inv[542];
  work1d.L[700] = (-work1d.L[698]*work1d.v[436])*work1d.d_inv[542];
  work1d.v[540] = work1d.L[684]*work1d.d[540];
  work1d.v[541] = work1d.L[685]*work1d.d[541];
  work1d.v[542] = work1d.L[686]*work1d.d[542];
  work1d.v[543] = 0-work1d.L[684]*work1d.v[540]-work1d.L[685]*work1d.v[541]-work1d.L[686]*work1d.v[542];
  work1d.d[543] = work1d.v[543];
  if (work1d.d[543] > 0)
    work1d.d[543] = -settings1d.kkt_reg;
  else
    work1d.d[543] -= settings1d.kkt_reg;
  work1d.d_inv[543] = 1/work1d.d[543];
  work1d.L[689] = (work1d.KKT[1069])*work1d.d_inv[543];
  work1d.L[696] = (-work1d.L[694]*work1d.v[541]-work1d.L[695]*work1d.v[542])*work1d.d_inv[543];
  work1d.L[701] = (-work1d.L[700]*work1d.v[542])*work1d.d_inv[543];
  work1d.v[185] = work1d.L[687]*work1d.d[185];
  work1d.v[265] = work1d.L[688]*work1d.d[265];
  work1d.v[543] = work1d.L[689]*work1d.d[543];
  work1d.v[544] = work1d.KKT[1070]-work1d.L[687]*work1d.v[185]-work1d.L[688]*work1d.v[265]-work1d.L[689]*work1d.v[543];
  work1d.d[544] = work1d.v[544];
  if (work1d.d[544] < 0)
    work1d.d[544] = settings1d.kkt_reg;
  else
    work1d.d[544] += settings1d.kkt_reg;
  work1d.d_inv[544] = 1/work1d.d[544];
  work1d.L[697] = (-work1d.L[696]*work1d.v[543])*work1d.d_inv[544];
  work1d.L[702] = (work1d.KKT[1071]-work1d.L[701]*work1d.v[543])*work1d.d_inv[544];
  work1d.L[704] = (work1d.KKT[1072])*work1d.d_inv[544];
  work1d.v[225] = work1d.L[690]*work1d.d[225];
  work1d.v[305] = work1d.L[691]*work1d.d[305];
  work1d.v[394] = work1d.L[692]*work1d.d[394];
  work1d.v[395] = work1d.L[693]*work1d.d[395];
  work1d.v[541] = work1d.L[694]*work1d.d[541];
  work1d.v[542] = work1d.L[695]*work1d.d[542];
  work1d.v[543] = work1d.L[696]*work1d.d[543];
  work1d.v[544] = work1d.L[697]*work1d.d[544];
  work1d.v[545] = work1d.KKT[1073]-work1d.L[690]*work1d.v[225]-work1d.L[691]*work1d.v[305]-work1d.L[692]*work1d.v[394]-work1d.L[693]*work1d.v[395]-work1d.L[694]*work1d.v[541]-work1d.L[695]*work1d.v[542]-work1d.L[696]*work1d.v[543]-work1d.L[697]*work1d.v[544];
  work1d.d[545] = work1d.v[545];
  if (work1d.d[545] < 0)
    work1d.d[545] = settings1d.kkt_reg;
  else
    work1d.d[545] += settings1d.kkt_reg;
  work1d.d_inv[545] = 1/work1d.d[545];
  work1d.L[703] = (-work1d.L[700]*work1d.v[542]-work1d.L[701]*work1d.v[543]-work1d.L[702]*work1d.v[544])*work1d.d_inv[545];
  work1d.L[705] = (work1d.KKT[1074]-work1d.L[704]*work1d.v[544])*work1d.d_inv[545];
  work1d.L[714] = (-work1d.L[712]*work1d.v[395])*work1d.d_inv[545];
  work1d.v[436] = work1d.L[698]*work1d.d[436];
  work1d.v[437] = work1d.L[699]*work1d.d[437];
  work1d.v[542] = work1d.L[700]*work1d.d[542];
  work1d.v[543] = work1d.L[701]*work1d.d[543];
  work1d.v[544] = work1d.L[702]*work1d.d[544];
  work1d.v[545] = work1d.L[703]*work1d.d[545];
  work1d.v[546] = 0-work1d.L[698]*work1d.v[436]-work1d.L[699]*work1d.v[437]-work1d.L[700]*work1d.v[542]-work1d.L[701]*work1d.v[543]-work1d.L[702]*work1d.v[544]-work1d.L[703]*work1d.v[545];
  work1d.d[546] = work1d.v[546];
  if (work1d.d[546] > 0)
    work1d.d[546] = -settings1d.kkt_reg;
  else
    work1d.d[546] -= settings1d.kkt_reg;
  work1d.d_inv[546] = 1/work1d.d[546];
  work1d.L[706] = (-work1d.L[704]*work1d.v[544]-work1d.L[705]*work1d.v[545])*work1d.d_inv[546];
  work1d.L[715] = (-work1d.L[714]*work1d.v[545])*work1d.d_inv[546];
  work1d.L[720] = (-work1d.L[718]*work1d.v[437])*work1d.d_inv[546];
  work1d.v[544] = work1d.L[704]*work1d.d[544];
  work1d.v[545] = work1d.L[705]*work1d.d[545];
  work1d.v[546] = work1d.L[706]*work1d.d[546];
  work1d.v[547] = 0-work1d.L[704]*work1d.v[544]-work1d.L[705]*work1d.v[545]-work1d.L[706]*work1d.v[546];
  work1d.d[547] = work1d.v[547];
  if (work1d.d[547] > 0)
    work1d.d[547] = -settings1d.kkt_reg;
  else
    work1d.d[547] -= settings1d.kkt_reg;
  work1d.d_inv[547] = 1/work1d.d[547];
  work1d.L[709] = (work1d.KKT[1075])*work1d.d_inv[547];
  work1d.L[716] = (-work1d.L[714]*work1d.v[545]-work1d.L[715]*work1d.v[546])*work1d.d_inv[547];
  work1d.L[721] = (-work1d.L[720]*work1d.v[546])*work1d.d_inv[547];
  work1d.v[186] = work1d.L[707]*work1d.d[186];
  work1d.v[266] = work1d.L[708]*work1d.d[266];
  work1d.v[547] = work1d.L[709]*work1d.d[547];
  work1d.v[548] = work1d.KKT[1076]-work1d.L[707]*work1d.v[186]-work1d.L[708]*work1d.v[266]-work1d.L[709]*work1d.v[547];
  work1d.d[548] = work1d.v[548];
  if (work1d.d[548] < 0)
    work1d.d[548] = settings1d.kkt_reg;
  else
    work1d.d[548] += settings1d.kkt_reg;
  work1d.d_inv[548] = 1/work1d.d[548];
  work1d.L[717] = (-work1d.L[716]*work1d.v[547])*work1d.d_inv[548];
  work1d.L[722] = (work1d.KKT[1077]-work1d.L[721]*work1d.v[547])*work1d.d_inv[548];
  work1d.L[724] = (work1d.KKT[1078])*work1d.d_inv[548];
  work1d.v[226] = work1d.L[710]*work1d.d[226];
  work1d.v[306] = work1d.L[711]*work1d.d[306];
  work1d.v[395] = work1d.L[712]*work1d.d[395];
  work1d.v[396] = work1d.L[713]*work1d.d[396];
  work1d.v[545] = work1d.L[714]*work1d.d[545];
  work1d.v[546] = work1d.L[715]*work1d.d[546];
  work1d.v[547] = work1d.L[716]*work1d.d[547];
  work1d.v[548] = work1d.L[717]*work1d.d[548];
  work1d.v[549] = work1d.KKT[1079]-work1d.L[710]*work1d.v[226]-work1d.L[711]*work1d.v[306]-work1d.L[712]*work1d.v[395]-work1d.L[713]*work1d.v[396]-work1d.L[714]*work1d.v[545]-work1d.L[715]*work1d.v[546]-work1d.L[716]*work1d.v[547]-work1d.L[717]*work1d.v[548];
  work1d.d[549] = work1d.v[549];
  if (work1d.d[549] < 0)
    work1d.d[549] = settings1d.kkt_reg;
  else
    work1d.d[549] += settings1d.kkt_reg;
  work1d.d_inv[549] = 1/work1d.d[549];
  work1d.L[723] = (-work1d.L[720]*work1d.v[546]-work1d.L[721]*work1d.v[547]-work1d.L[722]*work1d.v[548])*work1d.d_inv[549];
  work1d.L[725] = (work1d.KKT[1080]-work1d.L[724]*work1d.v[548])*work1d.d_inv[549];
  work1d.L[734] = (-work1d.L[732]*work1d.v[396])*work1d.d_inv[549];
  work1d.v[437] = work1d.L[718]*work1d.d[437];
  work1d.v[438] = work1d.L[719]*work1d.d[438];
  work1d.v[546] = work1d.L[720]*work1d.d[546];
  work1d.v[547] = work1d.L[721]*work1d.d[547];
  work1d.v[548] = work1d.L[722]*work1d.d[548];
  work1d.v[549] = work1d.L[723]*work1d.d[549];
  work1d.v[550] = 0-work1d.L[718]*work1d.v[437]-work1d.L[719]*work1d.v[438]-work1d.L[720]*work1d.v[546]-work1d.L[721]*work1d.v[547]-work1d.L[722]*work1d.v[548]-work1d.L[723]*work1d.v[549];
  work1d.d[550] = work1d.v[550];
  if (work1d.d[550] > 0)
    work1d.d[550] = -settings1d.kkt_reg;
  else
    work1d.d[550] -= settings1d.kkt_reg;
  work1d.d_inv[550] = 1/work1d.d[550];
  work1d.L[726] = (-work1d.L[724]*work1d.v[548]-work1d.L[725]*work1d.v[549])*work1d.d_inv[550];
  work1d.L[735] = (-work1d.L[734]*work1d.v[549])*work1d.d_inv[550];
  work1d.L[740] = (-work1d.L[738]*work1d.v[438])*work1d.d_inv[550];
  work1d.v[548] = work1d.L[724]*work1d.d[548];
  work1d.v[549] = work1d.L[725]*work1d.d[549];
  work1d.v[550] = work1d.L[726]*work1d.d[550];
  work1d.v[551] = 0-work1d.L[724]*work1d.v[548]-work1d.L[725]*work1d.v[549]-work1d.L[726]*work1d.v[550];
  work1d.d[551] = work1d.v[551];
  if (work1d.d[551] > 0)
    work1d.d[551] = -settings1d.kkt_reg;
  else
    work1d.d[551] -= settings1d.kkt_reg;
  work1d.d_inv[551] = 1/work1d.d[551];
  work1d.L[729] = (work1d.KKT[1081])*work1d.d_inv[551];
  work1d.L[736] = (-work1d.L[734]*work1d.v[549]-work1d.L[735]*work1d.v[550])*work1d.d_inv[551];
  work1d.L[741] = (-work1d.L[740]*work1d.v[550])*work1d.d_inv[551];
  work1d.v[187] = work1d.L[727]*work1d.d[187];
  work1d.v[267] = work1d.L[728]*work1d.d[267];
  work1d.v[551] = work1d.L[729]*work1d.d[551];
  work1d.v[552] = work1d.KKT[1082]-work1d.L[727]*work1d.v[187]-work1d.L[728]*work1d.v[267]-work1d.L[729]*work1d.v[551];
  work1d.d[552] = work1d.v[552];
  if (work1d.d[552] < 0)
    work1d.d[552] = settings1d.kkt_reg;
  else
    work1d.d[552] += settings1d.kkt_reg;
  work1d.d_inv[552] = 1/work1d.d[552];
  work1d.L[737] = (-work1d.L[736]*work1d.v[551])*work1d.d_inv[552];
  work1d.L[742] = (work1d.KKT[1083]-work1d.L[741]*work1d.v[551])*work1d.d_inv[552];
  work1d.L[744] = (work1d.KKT[1084])*work1d.d_inv[552];
  work1d.v[227] = work1d.L[730]*work1d.d[227];
  work1d.v[307] = work1d.L[731]*work1d.d[307];
  work1d.v[396] = work1d.L[732]*work1d.d[396];
  work1d.v[397] = work1d.L[733]*work1d.d[397];
  work1d.v[549] = work1d.L[734]*work1d.d[549];
  work1d.v[550] = work1d.L[735]*work1d.d[550];
  work1d.v[551] = work1d.L[736]*work1d.d[551];
  work1d.v[552] = work1d.L[737]*work1d.d[552];
  work1d.v[553] = work1d.KKT[1085]-work1d.L[730]*work1d.v[227]-work1d.L[731]*work1d.v[307]-work1d.L[732]*work1d.v[396]-work1d.L[733]*work1d.v[397]-work1d.L[734]*work1d.v[549]-work1d.L[735]*work1d.v[550]-work1d.L[736]*work1d.v[551]-work1d.L[737]*work1d.v[552];
  work1d.d[553] = work1d.v[553];
  if (work1d.d[553] < 0)
    work1d.d[553] = settings1d.kkt_reg;
  else
    work1d.d[553] += settings1d.kkt_reg;
  work1d.d_inv[553] = 1/work1d.d[553];
  work1d.L[743] = (-work1d.L[740]*work1d.v[550]-work1d.L[741]*work1d.v[551]-work1d.L[742]*work1d.v[552])*work1d.d_inv[553];
  work1d.L[745] = (work1d.KKT[1086]-work1d.L[744]*work1d.v[552])*work1d.d_inv[553];
  work1d.L[754] = (-work1d.L[752]*work1d.v[397])*work1d.d_inv[553];
  work1d.v[438] = work1d.L[738]*work1d.d[438];
  work1d.v[439] = work1d.L[739]*work1d.d[439];
  work1d.v[550] = work1d.L[740]*work1d.d[550];
  work1d.v[551] = work1d.L[741]*work1d.d[551];
  work1d.v[552] = work1d.L[742]*work1d.d[552];
  work1d.v[553] = work1d.L[743]*work1d.d[553];
  work1d.v[554] = 0-work1d.L[738]*work1d.v[438]-work1d.L[739]*work1d.v[439]-work1d.L[740]*work1d.v[550]-work1d.L[741]*work1d.v[551]-work1d.L[742]*work1d.v[552]-work1d.L[743]*work1d.v[553];
  work1d.d[554] = work1d.v[554];
  if (work1d.d[554] > 0)
    work1d.d[554] = -settings1d.kkt_reg;
  else
    work1d.d[554] -= settings1d.kkt_reg;
  work1d.d_inv[554] = 1/work1d.d[554];
  work1d.L[746] = (-work1d.L[744]*work1d.v[552]-work1d.L[745]*work1d.v[553])*work1d.d_inv[554];
  work1d.L[755] = (-work1d.L[754]*work1d.v[553])*work1d.d_inv[554];
  work1d.L[760] = (-work1d.L[758]*work1d.v[439])*work1d.d_inv[554];
  work1d.v[552] = work1d.L[744]*work1d.d[552];
  work1d.v[553] = work1d.L[745]*work1d.d[553];
  work1d.v[554] = work1d.L[746]*work1d.d[554];
  work1d.v[555] = 0-work1d.L[744]*work1d.v[552]-work1d.L[745]*work1d.v[553]-work1d.L[746]*work1d.v[554];
  work1d.d[555] = work1d.v[555];
  if (work1d.d[555] > 0)
    work1d.d[555] = -settings1d.kkt_reg;
  else
    work1d.d[555] -= settings1d.kkt_reg;
  work1d.d_inv[555] = 1/work1d.d[555];
  work1d.L[749] = (work1d.KKT[1087])*work1d.d_inv[555];
  work1d.L[756] = (-work1d.L[754]*work1d.v[553]-work1d.L[755]*work1d.v[554])*work1d.d_inv[555];
  work1d.L[761] = (-work1d.L[760]*work1d.v[554])*work1d.d_inv[555];
  work1d.v[188] = work1d.L[747]*work1d.d[188];
  work1d.v[268] = work1d.L[748]*work1d.d[268];
  work1d.v[555] = work1d.L[749]*work1d.d[555];
  work1d.v[556] = work1d.KKT[1088]-work1d.L[747]*work1d.v[188]-work1d.L[748]*work1d.v[268]-work1d.L[749]*work1d.v[555];
  work1d.d[556] = work1d.v[556];
  if (work1d.d[556] < 0)
    work1d.d[556] = settings1d.kkt_reg;
  else
    work1d.d[556] += settings1d.kkt_reg;
  work1d.d_inv[556] = 1/work1d.d[556];
  work1d.L[757] = (-work1d.L[756]*work1d.v[555])*work1d.d_inv[556];
  work1d.L[762] = (work1d.KKT[1089]-work1d.L[761]*work1d.v[555])*work1d.d_inv[556];
  work1d.L[764] = (work1d.KKT[1090])*work1d.d_inv[556];
  work1d.v[228] = work1d.L[750]*work1d.d[228];
  work1d.v[308] = work1d.L[751]*work1d.d[308];
  work1d.v[397] = work1d.L[752]*work1d.d[397];
  work1d.v[398] = work1d.L[753]*work1d.d[398];
  work1d.v[553] = work1d.L[754]*work1d.d[553];
  work1d.v[554] = work1d.L[755]*work1d.d[554];
  work1d.v[555] = work1d.L[756]*work1d.d[555];
  work1d.v[556] = work1d.L[757]*work1d.d[556];
  work1d.v[557] = work1d.KKT[1091]-work1d.L[750]*work1d.v[228]-work1d.L[751]*work1d.v[308]-work1d.L[752]*work1d.v[397]-work1d.L[753]*work1d.v[398]-work1d.L[754]*work1d.v[553]-work1d.L[755]*work1d.v[554]-work1d.L[756]*work1d.v[555]-work1d.L[757]*work1d.v[556];
  work1d.d[557] = work1d.v[557];
  if (work1d.d[557] < 0)
    work1d.d[557] = settings1d.kkt_reg;
  else
    work1d.d[557] += settings1d.kkt_reg;
  work1d.d_inv[557] = 1/work1d.d[557];
  work1d.L[763] = (-work1d.L[760]*work1d.v[554]-work1d.L[761]*work1d.v[555]-work1d.L[762]*work1d.v[556])*work1d.d_inv[557];
  work1d.L[765] = (work1d.KKT[1092]-work1d.L[764]*work1d.v[556])*work1d.d_inv[557];
  work1d.L[774] = (-work1d.L[772]*work1d.v[398])*work1d.d_inv[557];
  work1d.v[439] = work1d.L[758]*work1d.d[439];
  work1d.v[440] = work1d.L[759]*work1d.d[440];
  work1d.v[554] = work1d.L[760]*work1d.d[554];
  work1d.v[555] = work1d.L[761]*work1d.d[555];
  work1d.v[556] = work1d.L[762]*work1d.d[556];
  work1d.v[557] = work1d.L[763]*work1d.d[557];
  work1d.v[558] = 0-work1d.L[758]*work1d.v[439]-work1d.L[759]*work1d.v[440]-work1d.L[760]*work1d.v[554]-work1d.L[761]*work1d.v[555]-work1d.L[762]*work1d.v[556]-work1d.L[763]*work1d.v[557];
  work1d.d[558] = work1d.v[558];
  if (work1d.d[558] > 0)
    work1d.d[558] = -settings1d.kkt_reg;
  else
    work1d.d[558] -= settings1d.kkt_reg;
  work1d.d_inv[558] = 1/work1d.d[558];
  work1d.L[766] = (-work1d.L[764]*work1d.v[556]-work1d.L[765]*work1d.v[557])*work1d.d_inv[558];
  work1d.L[775] = (-work1d.L[774]*work1d.v[557])*work1d.d_inv[558];
  work1d.L[780] = (-work1d.L[778]*work1d.v[440])*work1d.d_inv[558];
  work1d.v[556] = work1d.L[764]*work1d.d[556];
  work1d.v[557] = work1d.L[765]*work1d.d[557];
  work1d.v[558] = work1d.L[766]*work1d.d[558];
  work1d.v[559] = 0-work1d.L[764]*work1d.v[556]-work1d.L[765]*work1d.v[557]-work1d.L[766]*work1d.v[558];
  work1d.d[559] = work1d.v[559];
  if (work1d.d[559] > 0)
    work1d.d[559] = -settings1d.kkt_reg;
  else
    work1d.d[559] -= settings1d.kkt_reg;
  work1d.d_inv[559] = 1/work1d.d[559];
  work1d.L[769] = (work1d.KKT[1093])*work1d.d_inv[559];
  work1d.L[776] = (-work1d.L[774]*work1d.v[557]-work1d.L[775]*work1d.v[558])*work1d.d_inv[559];
  work1d.L[781] = (-work1d.L[780]*work1d.v[558])*work1d.d_inv[559];
  work1d.v[189] = work1d.L[767]*work1d.d[189];
  work1d.v[269] = work1d.L[768]*work1d.d[269];
  work1d.v[559] = work1d.L[769]*work1d.d[559];
  work1d.v[560] = work1d.KKT[1094]-work1d.L[767]*work1d.v[189]-work1d.L[768]*work1d.v[269]-work1d.L[769]*work1d.v[559];
  work1d.d[560] = work1d.v[560];
  if (work1d.d[560] < 0)
    work1d.d[560] = settings1d.kkt_reg;
  else
    work1d.d[560] += settings1d.kkt_reg;
  work1d.d_inv[560] = 1/work1d.d[560];
  work1d.L[777] = (-work1d.L[776]*work1d.v[559])*work1d.d_inv[560];
  work1d.L[782] = (work1d.KKT[1095]-work1d.L[781]*work1d.v[559])*work1d.d_inv[560];
  work1d.L[784] = (work1d.KKT[1096])*work1d.d_inv[560];
  work1d.v[229] = work1d.L[770]*work1d.d[229];
  work1d.v[309] = work1d.L[771]*work1d.d[309];
  work1d.v[398] = work1d.L[772]*work1d.d[398];
  work1d.v[399] = work1d.L[773]*work1d.d[399];
  work1d.v[557] = work1d.L[774]*work1d.d[557];
  work1d.v[558] = work1d.L[775]*work1d.d[558];
  work1d.v[559] = work1d.L[776]*work1d.d[559];
  work1d.v[560] = work1d.L[777]*work1d.d[560];
  work1d.v[561] = work1d.KKT[1097]-work1d.L[770]*work1d.v[229]-work1d.L[771]*work1d.v[309]-work1d.L[772]*work1d.v[398]-work1d.L[773]*work1d.v[399]-work1d.L[774]*work1d.v[557]-work1d.L[775]*work1d.v[558]-work1d.L[776]*work1d.v[559]-work1d.L[777]*work1d.v[560];
  work1d.d[561] = work1d.v[561];
  if (work1d.d[561] < 0)
    work1d.d[561] = settings1d.kkt_reg;
  else
    work1d.d[561] += settings1d.kkt_reg;
  work1d.d_inv[561] = 1/work1d.d[561];
  work1d.L[783] = (-work1d.L[780]*work1d.v[558]-work1d.L[781]*work1d.v[559]-work1d.L[782]*work1d.v[560])*work1d.d_inv[561];
  work1d.L[785] = (work1d.KKT[1098]-work1d.L[784]*work1d.v[560])*work1d.d_inv[561];
  work1d.L[794] = (-work1d.L[792]*work1d.v[399])*work1d.d_inv[561];
  work1d.v[440] = work1d.L[778]*work1d.d[440];
  work1d.v[441] = work1d.L[779]*work1d.d[441];
  work1d.v[558] = work1d.L[780]*work1d.d[558];
  work1d.v[559] = work1d.L[781]*work1d.d[559];
  work1d.v[560] = work1d.L[782]*work1d.d[560];
  work1d.v[561] = work1d.L[783]*work1d.d[561];
  work1d.v[562] = 0-work1d.L[778]*work1d.v[440]-work1d.L[779]*work1d.v[441]-work1d.L[780]*work1d.v[558]-work1d.L[781]*work1d.v[559]-work1d.L[782]*work1d.v[560]-work1d.L[783]*work1d.v[561];
  work1d.d[562] = work1d.v[562];
  if (work1d.d[562] > 0)
    work1d.d[562] = -settings1d.kkt_reg;
  else
    work1d.d[562] -= settings1d.kkt_reg;
  work1d.d_inv[562] = 1/work1d.d[562];
  work1d.L[786] = (-work1d.L[784]*work1d.v[560]-work1d.L[785]*work1d.v[561])*work1d.d_inv[562];
  work1d.L[795] = (-work1d.L[794]*work1d.v[561])*work1d.d_inv[562];
  work1d.L[800] = (-work1d.L[798]*work1d.v[441])*work1d.d_inv[562];
  work1d.v[560] = work1d.L[784]*work1d.d[560];
  work1d.v[561] = work1d.L[785]*work1d.d[561];
  work1d.v[562] = work1d.L[786]*work1d.d[562];
  work1d.v[563] = 0-work1d.L[784]*work1d.v[560]-work1d.L[785]*work1d.v[561]-work1d.L[786]*work1d.v[562];
  work1d.d[563] = work1d.v[563];
  if (work1d.d[563] > 0)
    work1d.d[563] = -settings1d.kkt_reg;
  else
    work1d.d[563] -= settings1d.kkt_reg;
  work1d.d_inv[563] = 1/work1d.d[563];
  work1d.L[789] = (work1d.KKT[1099])*work1d.d_inv[563];
  work1d.L[796] = (-work1d.L[794]*work1d.v[561]-work1d.L[795]*work1d.v[562])*work1d.d_inv[563];
  work1d.L[801] = (-work1d.L[800]*work1d.v[562])*work1d.d_inv[563];
  work1d.v[190] = work1d.L[787]*work1d.d[190];
  work1d.v[270] = work1d.L[788]*work1d.d[270];
  work1d.v[563] = work1d.L[789]*work1d.d[563];
  work1d.v[564] = work1d.KKT[1100]-work1d.L[787]*work1d.v[190]-work1d.L[788]*work1d.v[270]-work1d.L[789]*work1d.v[563];
  work1d.d[564] = work1d.v[564];
  if (work1d.d[564] < 0)
    work1d.d[564] = settings1d.kkt_reg;
  else
    work1d.d[564] += settings1d.kkt_reg;
  work1d.d_inv[564] = 1/work1d.d[564];
  work1d.L[797] = (-work1d.L[796]*work1d.v[563])*work1d.d_inv[564];
  work1d.L[802] = (work1d.KKT[1101]-work1d.L[801]*work1d.v[563])*work1d.d_inv[564];
  work1d.L[804] = (work1d.KKT[1102])*work1d.d_inv[564];
  work1d.v[230] = work1d.L[790]*work1d.d[230];
  work1d.v[310] = work1d.L[791]*work1d.d[310];
  work1d.v[399] = work1d.L[792]*work1d.d[399];
  work1d.v[400] = work1d.L[793]*work1d.d[400];
  work1d.v[561] = work1d.L[794]*work1d.d[561];
  work1d.v[562] = work1d.L[795]*work1d.d[562];
  work1d.v[563] = work1d.L[796]*work1d.d[563];
  work1d.v[564] = work1d.L[797]*work1d.d[564];
  work1d.v[565] = work1d.KKT[1103]-work1d.L[790]*work1d.v[230]-work1d.L[791]*work1d.v[310]-work1d.L[792]*work1d.v[399]-work1d.L[793]*work1d.v[400]-work1d.L[794]*work1d.v[561]-work1d.L[795]*work1d.v[562]-work1d.L[796]*work1d.v[563]-work1d.L[797]*work1d.v[564];
  work1d.d[565] = work1d.v[565];
  if (work1d.d[565] < 0)
    work1d.d[565] = settings1d.kkt_reg;
  else
    work1d.d[565] += settings1d.kkt_reg;
  work1d.d_inv[565] = 1/work1d.d[565];
  work1d.L[803] = (-work1d.L[800]*work1d.v[562]-work1d.L[801]*work1d.v[563]-work1d.L[802]*work1d.v[564])*work1d.d_inv[565];
  work1d.L[805] = (work1d.KKT[1104]-work1d.L[804]*work1d.v[564])*work1d.d_inv[565];
  work1d.L[814] = (-work1d.L[812]*work1d.v[400])*work1d.d_inv[565];
  work1d.v[441] = work1d.L[798]*work1d.d[441];
  work1d.v[442] = work1d.L[799]*work1d.d[442];
  work1d.v[562] = work1d.L[800]*work1d.d[562];
  work1d.v[563] = work1d.L[801]*work1d.d[563];
  work1d.v[564] = work1d.L[802]*work1d.d[564];
  work1d.v[565] = work1d.L[803]*work1d.d[565];
  work1d.v[566] = 0-work1d.L[798]*work1d.v[441]-work1d.L[799]*work1d.v[442]-work1d.L[800]*work1d.v[562]-work1d.L[801]*work1d.v[563]-work1d.L[802]*work1d.v[564]-work1d.L[803]*work1d.v[565];
  work1d.d[566] = work1d.v[566];
  if (work1d.d[566] > 0)
    work1d.d[566] = -settings1d.kkt_reg;
  else
    work1d.d[566] -= settings1d.kkt_reg;
  work1d.d_inv[566] = 1/work1d.d[566];
  work1d.L[806] = (-work1d.L[804]*work1d.v[564]-work1d.L[805]*work1d.v[565])*work1d.d_inv[566];
  work1d.L[815] = (-work1d.L[814]*work1d.v[565])*work1d.d_inv[566];
  work1d.L[820] = (-work1d.L[818]*work1d.v[442])*work1d.d_inv[566];
  work1d.v[564] = work1d.L[804]*work1d.d[564];
  work1d.v[565] = work1d.L[805]*work1d.d[565];
  work1d.v[566] = work1d.L[806]*work1d.d[566];
  work1d.v[567] = 0-work1d.L[804]*work1d.v[564]-work1d.L[805]*work1d.v[565]-work1d.L[806]*work1d.v[566];
  work1d.d[567] = work1d.v[567];
  if (work1d.d[567] > 0)
    work1d.d[567] = -settings1d.kkt_reg;
  else
    work1d.d[567] -= settings1d.kkt_reg;
  work1d.d_inv[567] = 1/work1d.d[567];
  work1d.L[809] = (work1d.KKT[1105])*work1d.d_inv[567];
  work1d.L[816] = (-work1d.L[814]*work1d.v[565]-work1d.L[815]*work1d.v[566])*work1d.d_inv[567];
  work1d.L[821] = (-work1d.L[820]*work1d.v[566])*work1d.d_inv[567];
  work1d.v[191] = work1d.L[807]*work1d.d[191];
  work1d.v[271] = work1d.L[808]*work1d.d[271];
  work1d.v[567] = work1d.L[809]*work1d.d[567];
  work1d.v[568] = work1d.KKT[1106]-work1d.L[807]*work1d.v[191]-work1d.L[808]*work1d.v[271]-work1d.L[809]*work1d.v[567];
  work1d.d[568] = work1d.v[568];
  if (work1d.d[568] < 0)
    work1d.d[568] = settings1d.kkt_reg;
  else
    work1d.d[568] += settings1d.kkt_reg;
  work1d.d_inv[568] = 1/work1d.d[568];
  work1d.L[817] = (-work1d.L[816]*work1d.v[567])*work1d.d_inv[568];
  work1d.L[822] = (work1d.KKT[1107]-work1d.L[821]*work1d.v[567])*work1d.d_inv[568];
  work1d.L[824] = (work1d.KKT[1108])*work1d.d_inv[568];
  work1d.v[231] = work1d.L[810]*work1d.d[231];
  work1d.v[311] = work1d.L[811]*work1d.d[311];
  work1d.v[400] = work1d.L[812]*work1d.d[400];
  work1d.v[401] = work1d.L[813]*work1d.d[401];
  work1d.v[565] = work1d.L[814]*work1d.d[565];
  work1d.v[566] = work1d.L[815]*work1d.d[566];
  work1d.v[567] = work1d.L[816]*work1d.d[567];
  work1d.v[568] = work1d.L[817]*work1d.d[568];
  work1d.v[569] = work1d.KKT[1109]-work1d.L[810]*work1d.v[231]-work1d.L[811]*work1d.v[311]-work1d.L[812]*work1d.v[400]-work1d.L[813]*work1d.v[401]-work1d.L[814]*work1d.v[565]-work1d.L[815]*work1d.v[566]-work1d.L[816]*work1d.v[567]-work1d.L[817]*work1d.v[568];
  work1d.d[569] = work1d.v[569];
  if (work1d.d[569] < 0)
    work1d.d[569] = settings1d.kkt_reg;
  else
    work1d.d[569] += settings1d.kkt_reg;
  work1d.d_inv[569] = 1/work1d.d[569];
  work1d.L[823] = (-work1d.L[820]*work1d.v[566]-work1d.L[821]*work1d.v[567]-work1d.L[822]*work1d.v[568])*work1d.d_inv[569];
  work1d.L[825] = (work1d.KKT[1110]-work1d.L[824]*work1d.v[568])*work1d.d_inv[569];
  work1d.L[834] = (-work1d.L[832]*work1d.v[401])*work1d.d_inv[569];
  work1d.v[442] = work1d.L[818]*work1d.d[442];
  work1d.v[443] = work1d.L[819]*work1d.d[443];
  work1d.v[566] = work1d.L[820]*work1d.d[566];
  work1d.v[567] = work1d.L[821]*work1d.d[567];
  work1d.v[568] = work1d.L[822]*work1d.d[568];
  work1d.v[569] = work1d.L[823]*work1d.d[569];
  work1d.v[570] = 0-work1d.L[818]*work1d.v[442]-work1d.L[819]*work1d.v[443]-work1d.L[820]*work1d.v[566]-work1d.L[821]*work1d.v[567]-work1d.L[822]*work1d.v[568]-work1d.L[823]*work1d.v[569];
  work1d.d[570] = work1d.v[570];
  if (work1d.d[570] > 0)
    work1d.d[570] = -settings1d.kkt_reg;
  else
    work1d.d[570] -= settings1d.kkt_reg;
  work1d.d_inv[570] = 1/work1d.d[570];
  work1d.L[826] = (-work1d.L[824]*work1d.v[568]-work1d.L[825]*work1d.v[569])*work1d.d_inv[570];
  work1d.L[835] = (-work1d.L[834]*work1d.v[569])*work1d.d_inv[570];
  work1d.L[840] = (-work1d.L[838]*work1d.v[443])*work1d.d_inv[570];
  work1d.v[568] = work1d.L[824]*work1d.d[568];
  work1d.v[569] = work1d.L[825]*work1d.d[569];
  work1d.v[570] = work1d.L[826]*work1d.d[570];
  work1d.v[571] = 0-work1d.L[824]*work1d.v[568]-work1d.L[825]*work1d.v[569]-work1d.L[826]*work1d.v[570];
  work1d.d[571] = work1d.v[571];
  if (work1d.d[571] > 0)
    work1d.d[571] = -settings1d.kkt_reg;
  else
    work1d.d[571] -= settings1d.kkt_reg;
  work1d.d_inv[571] = 1/work1d.d[571];
  work1d.L[829] = (work1d.KKT[1111])*work1d.d_inv[571];
  work1d.L[836] = (-work1d.L[834]*work1d.v[569]-work1d.L[835]*work1d.v[570])*work1d.d_inv[571];
  work1d.L[841] = (-work1d.L[840]*work1d.v[570])*work1d.d_inv[571];
  work1d.v[192] = work1d.L[827]*work1d.d[192];
  work1d.v[272] = work1d.L[828]*work1d.d[272];
  work1d.v[571] = work1d.L[829]*work1d.d[571];
  work1d.v[572] = work1d.KKT[1112]-work1d.L[827]*work1d.v[192]-work1d.L[828]*work1d.v[272]-work1d.L[829]*work1d.v[571];
  work1d.d[572] = work1d.v[572];
  if (work1d.d[572] < 0)
    work1d.d[572] = settings1d.kkt_reg;
  else
    work1d.d[572] += settings1d.kkt_reg;
  work1d.d_inv[572] = 1/work1d.d[572];
  work1d.L[837] = (-work1d.L[836]*work1d.v[571])*work1d.d_inv[572];
  work1d.L[842] = (work1d.KKT[1113]-work1d.L[841]*work1d.v[571])*work1d.d_inv[572];
  work1d.L[844] = (work1d.KKT[1114])*work1d.d_inv[572];
  work1d.v[232] = work1d.L[830]*work1d.d[232];
  work1d.v[312] = work1d.L[831]*work1d.d[312];
  work1d.v[401] = work1d.L[832]*work1d.d[401];
  work1d.v[402] = work1d.L[833]*work1d.d[402];
  work1d.v[569] = work1d.L[834]*work1d.d[569];
  work1d.v[570] = work1d.L[835]*work1d.d[570];
  work1d.v[571] = work1d.L[836]*work1d.d[571];
  work1d.v[572] = work1d.L[837]*work1d.d[572];
  work1d.v[573] = work1d.KKT[1115]-work1d.L[830]*work1d.v[232]-work1d.L[831]*work1d.v[312]-work1d.L[832]*work1d.v[401]-work1d.L[833]*work1d.v[402]-work1d.L[834]*work1d.v[569]-work1d.L[835]*work1d.v[570]-work1d.L[836]*work1d.v[571]-work1d.L[837]*work1d.v[572];
  work1d.d[573] = work1d.v[573];
  if (work1d.d[573] < 0)
    work1d.d[573] = settings1d.kkt_reg;
  else
    work1d.d[573] += settings1d.kkt_reg;
  work1d.d_inv[573] = 1/work1d.d[573];
  work1d.L[843] = (-work1d.L[840]*work1d.v[570]-work1d.L[841]*work1d.v[571]-work1d.L[842]*work1d.v[572])*work1d.d_inv[573];
  work1d.L[845] = (work1d.KKT[1116]-work1d.L[844]*work1d.v[572])*work1d.d_inv[573];
  work1d.L[854] = (-work1d.L[852]*work1d.v[402])*work1d.d_inv[573];
  work1d.v[443] = work1d.L[838]*work1d.d[443];
  work1d.v[444] = work1d.L[839]*work1d.d[444];
  work1d.v[570] = work1d.L[840]*work1d.d[570];
  work1d.v[571] = work1d.L[841]*work1d.d[571];
  work1d.v[572] = work1d.L[842]*work1d.d[572];
  work1d.v[573] = work1d.L[843]*work1d.d[573];
  work1d.v[574] = 0-work1d.L[838]*work1d.v[443]-work1d.L[839]*work1d.v[444]-work1d.L[840]*work1d.v[570]-work1d.L[841]*work1d.v[571]-work1d.L[842]*work1d.v[572]-work1d.L[843]*work1d.v[573];
  work1d.d[574] = work1d.v[574];
  if (work1d.d[574] > 0)
    work1d.d[574] = -settings1d.kkt_reg;
  else
    work1d.d[574] -= settings1d.kkt_reg;
  work1d.d_inv[574] = 1/work1d.d[574];
  work1d.L[846] = (-work1d.L[844]*work1d.v[572]-work1d.L[845]*work1d.v[573])*work1d.d_inv[574];
  work1d.L[855] = (-work1d.L[854]*work1d.v[573])*work1d.d_inv[574];
  work1d.L[860] = (-work1d.L[858]*work1d.v[444])*work1d.d_inv[574];
  work1d.v[572] = work1d.L[844]*work1d.d[572];
  work1d.v[573] = work1d.L[845]*work1d.d[573];
  work1d.v[574] = work1d.L[846]*work1d.d[574];
  work1d.v[575] = 0-work1d.L[844]*work1d.v[572]-work1d.L[845]*work1d.v[573]-work1d.L[846]*work1d.v[574];
  work1d.d[575] = work1d.v[575];
  if (work1d.d[575] > 0)
    work1d.d[575] = -settings1d.kkt_reg;
  else
    work1d.d[575] -= settings1d.kkt_reg;
  work1d.d_inv[575] = 1/work1d.d[575];
  work1d.L[849] = (work1d.KKT[1117])*work1d.d_inv[575];
  work1d.L[856] = (-work1d.L[854]*work1d.v[573]-work1d.L[855]*work1d.v[574])*work1d.d_inv[575];
  work1d.L[861] = (-work1d.L[860]*work1d.v[574])*work1d.d_inv[575];
  work1d.v[193] = work1d.L[847]*work1d.d[193];
  work1d.v[273] = work1d.L[848]*work1d.d[273];
  work1d.v[575] = work1d.L[849]*work1d.d[575];
  work1d.v[576] = work1d.KKT[1118]-work1d.L[847]*work1d.v[193]-work1d.L[848]*work1d.v[273]-work1d.L[849]*work1d.v[575];
  work1d.d[576] = work1d.v[576];
  if (work1d.d[576] < 0)
    work1d.d[576] = settings1d.kkt_reg;
  else
    work1d.d[576] += settings1d.kkt_reg;
  work1d.d_inv[576] = 1/work1d.d[576];
  work1d.L[857] = (-work1d.L[856]*work1d.v[575])*work1d.d_inv[576];
  work1d.L[862] = (work1d.KKT[1119]-work1d.L[861]*work1d.v[575])*work1d.d_inv[576];
  work1d.L[864] = (work1d.KKT[1120])*work1d.d_inv[576];
  work1d.v[233] = work1d.L[850]*work1d.d[233];
  work1d.v[313] = work1d.L[851]*work1d.d[313];
  work1d.v[402] = work1d.L[852]*work1d.d[402];
  work1d.v[403] = work1d.L[853]*work1d.d[403];
  work1d.v[573] = work1d.L[854]*work1d.d[573];
  work1d.v[574] = work1d.L[855]*work1d.d[574];
  work1d.v[575] = work1d.L[856]*work1d.d[575];
  work1d.v[576] = work1d.L[857]*work1d.d[576];
  work1d.v[577] = work1d.KKT[1121]-work1d.L[850]*work1d.v[233]-work1d.L[851]*work1d.v[313]-work1d.L[852]*work1d.v[402]-work1d.L[853]*work1d.v[403]-work1d.L[854]*work1d.v[573]-work1d.L[855]*work1d.v[574]-work1d.L[856]*work1d.v[575]-work1d.L[857]*work1d.v[576];
  work1d.d[577] = work1d.v[577];
  if (work1d.d[577] < 0)
    work1d.d[577] = settings1d.kkt_reg;
  else
    work1d.d[577] += settings1d.kkt_reg;
  work1d.d_inv[577] = 1/work1d.d[577];
  work1d.L[863] = (-work1d.L[860]*work1d.v[574]-work1d.L[861]*work1d.v[575]-work1d.L[862]*work1d.v[576])*work1d.d_inv[577];
  work1d.L[865] = (work1d.KKT[1122]-work1d.L[864]*work1d.v[576])*work1d.d_inv[577];
  work1d.L[874] = (-work1d.L[872]*work1d.v[403])*work1d.d_inv[577];
  work1d.v[444] = work1d.L[858]*work1d.d[444];
  work1d.v[445] = work1d.L[859]*work1d.d[445];
  work1d.v[574] = work1d.L[860]*work1d.d[574];
  work1d.v[575] = work1d.L[861]*work1d.d[575];
  work1d.v[576] = work1d.L[862]*work1d.d[576];
  work1d.v[577] = work1d.L[863]*work1d.d[577];
  work1d.v[578] = 0-work1d.L[858]*work1d.v[444]-work1d.L[859]*work1d.v[445]-work1d.L[860]*work1d.v[574]-work1d.L[861]*work1d.v[575]-work1d.L[862]*work1d.v[576]-work1d.L[863]*work1d.v[577];
  work1d.d[578] = work1d.v[578];
  if (work1d.d[578] > 0)
    work1d.d[578] = -settings1d.kkt_reg;
  else
    work1d.d[578] -= settings1d.kkt_reg;
  work1d.d_inv[578] = 1/work1d.d[578];
  work1d.L[866] = (-work1d.L[864]*work1d.v[576]-work1d.L[865]*work1d.v[577])*work1d.d_inv[578];
  work1d.L[875] = (-work1d.L[874]*work1d.v[577])*work1d.d_inv[578];
  work1d.L[880] = (-work1d.L[878]*work1d.v[445])*work1d.d_inv[578];
  work1d.v[576] = work1d.L[864]*work1d.d[576];
  work1d.v[577] = work1d.L[865]*work1d.d[577];
  work1d.v[578] = work1d.L[866]*work1d.d[578];
  work1d.v[579] = 0-work1d.L[864]*work1d.v[576]-work1d.L[865]*work1d.v[577]-work1d.L[866]*work1d.v[578];
  work1d.d[579] = work1d.v[579];
  if (work1d.d[579] > 0)
    work1d.d[579] = -settings1d.kkt_reg;
  else
    work1d.d[579] -= settings1d.kkt_reg;
  work1d.d_inv[579] = 1/work1d.d[579];
  work1d.L[869] = (work1d.KKT[1123])*work1d.d_inv[579];
  work1d.L[876] = (-work1d.L[874]*work1d.v[577]-work1d.L[875]*work1d.v[578])*work1d.d_inv[579];
  work1d.L[881] = (-work1d.L[880]*work1d.v[578])*work1d.d_inv[579];
  work1d.v[194] = work1d.L[867]*work1d.d[194];
  work1d.v[274] = work1d.L[868]*work1d.d[274];
  work1d.v[579] = work1d.L[869]*work1d.d[579];
  work1d.v[580] = work1d.KKT[1124]-work1d.L[867]*work1d.v[194]-work1d.L[868]*work1d.v[274]-work1d.L[869]*work1d.v[579];
  work1d.d[580] = work1d.v[580];
  if (work1d.d[580] < 0)
    work1d.d[580] = settings1d.kkt_reg;
  else
    work1d.d[580] += settings1d.kkt_reg;
  work1d.d_inv[580] = 1/work1d.d[580];
  work1d.L[877] = (-work1d.L[876]*work1d.v[579])*work1d.d_inv[580];
  work1d.L[882] = (work1d.KKT[1125]-work1d.L[881]*work1d.v[579])*work1d.d_inv[580];
  work1d.L[884] = (work1d.KKT[1126])*work1d.d_inv[580];
  work1d.v[234] = work1d.L[870]*work1d.d[234];
  work1d.v[314] = work1d.L[871]*work1d.d[314];
  work1d.v[403] = work1d.L[872]*work1d.d[403];
  work1d.v[404] = work1d.L[873]*work1d.d[404];
  work1d.v[577] = work1d.L[874]*work1d.d[577];
  work1d.v[578] = work1d.L[875]*work1d.d[578];
  work1d.v[579] = work1d.L[876]*work1d.d[579];
  work1d.v[580] = work1d.L[877]*work1d.d[580];
  work1d.v[581] = work1d.KKT[1127]-work1d.L[870]*work1d.v[234]-work1d.L[871]*work1d.v[314]-work1d.L[872]*work1d.v[403]-work1d.L[873]*work1d.v[404]-work1d.L[874]*work1d.v[577]-work1d.L[875]*work1d.v[578]-work1d.L[876]*work1d.v[579]-work1d.L[877]*work1d.v[580];
  work1d.d[581] = work1d.v[581];
  if (work1d.d[581] < 0)
    work1d.d[581] = settings1d.kkt_reg;
  else
    work1d.d[581] += settings1d.kkt_reg;
  work1d.d_inv[581] = 1/work1d.d[581];
  work1d.L[883] = (-work1d.L[880]*work1d.v[578]-work1d.L[881]*work1d.v[579]-work1d.L[882]*work1d.v[580])*work1d.d_inv[581];
  work1d.L[885] = (work1d.KKT[1128]-work1d.L[884]*work1d.v[580])*work1d.d_inv[581];
  work1d.L[894] = (-work1d.L[892]*work1d.v[404])*work1d.d_inv[581];
  work1d.v[445] = work1d.L[878]*work1d.d[445];
  work1d.v[446] = work1d.L[879]*work1d.d[446];
  work1d.v[578] = work1d.L[880]*work1d.d[578];
  work1d.v[579] = work1d.L[881]*work1d.d[579];
  work1d.v[580] = work1d.L[882]*work1d.d[580];
  work1d.v[581] = work1d.L[883]*work1d.d[581];
  work1d.v[582] = 0-work1d.L[878]*work1d.v[445]-work1d.L[879]*work1d.v[446]-work1d.L[880]*work1d.v[578]-work1d.L[881]*work1d.v[579]-work1d.L[882]*work1d.v[580]-work1d.L[883]*work1d.v[581];
  work1d.d[582] = work1d.v[582];
  if (work1d.d[582] > 0)
    work1d.d[582] = -settings1d.kkt_reg;
  else
    work1d.d[582] -= settings1d.kkt_reg;
  work1d.d_inv[582] = 1/work1d.d[582];
  work1d.L[886] = (-work1d.L[884]*work1d.v[580]-work1d.L[885]*work1d.v[581])*work1d.d_inv[582];
  work1d.L[895] = (-work1d.L[894]*work1d.v[581])*work1d.d_inv[582];
  work1d.L[900] = (-work1d.L[898]*work1d.v[446])*work1d.d_inv[582];
  work1d.v[580] = work1d.L[884]*work1d.d[580];
  work1d.v[581] = work1d.L[885]*work1d.d[581];
  work1d.v[582] = work1d.L[886]*work1d.d[582];
  work1d.v[583] = 0-work1d.L[884]*work1d.v[580]-work1d.L[885]*work1d.v[581]-work1d.L[886]*work1d.v[582];
  work1d.d[583] = work1d.v[583];
  if (work1d.d[583] > 0)
    work1d.d[583] = -settings1d.kkt_reg;
  else
    work1d.d[583] -= settings1d.kkt_reg;
  work1d.d_inv[583] = 1/work1d.d[583];
  work1d.L[889] = (work1d.KKT[1129])*work1d.d_inv[583];
  work1d.L[896] = (-work1d.L[894]*work1d.v[581]-work1d.L[895]*work1d.v[582])*work1d.d_inv[583];
  work1d.L[901] = (-work1d.L[900]*work1d.v[582])*work1d.d_inv[583];
  work1d.v[195] = work1d.L[887]*work1d.d[195];
  work1d.v[275] = work1d.L[888]*work1d.d[275];
  work1d.v[583] = work1d.L[889]*work1d.d[583];
  work1d.v[584] = work1d.KKT[1130]-work1d.L[887]*work1d.v[195]-work1d.L[888]*work1d.v[275]-work1d.L[889]*work1d.v[583];
  work1d.d[584] = work1d.v[584];
  if (work1d.d[584] < 0)
    work1d.d[584] = settings1d.kkt_reg;
  else
    work1d.d[584] += settings1d.kkt_reg;
  work1d.d_inv[584] = 1/work1d.d[584];
  work1d.L[897] = (-work1d.L[896]*work1d.v[583])*work1d.d_inv[584];
  work1d.L[902] = (work1d.KKT[1131]-work1d.L[901]*work1d.v[583])*work1d.d_inv[584];
  work1d.L[904] = (work1d.KKT[1132])*work1d.d_inv[584];
  work1d.v[235] = work1d.L[890]*work1d.d[235];
  work1d.v[315] = work1d.L[891]*work1d.d[315];
  work1d.v[404] = work1d.L[892]*work1d.d[404];
  work1d.v[405] = work1d.L[893]*work1d.d[405];
  work1d.v[581] = work1d.L[894]*work1d.d[581];
  work1d.v[582] = work1d.L[895]*work1d.d[582];
  work1d.v[583] = work1d.L[896]*work1d.d[583];
  work1d.v[584] = work1d.L[897]*work1d.d[584];
  work1d.v[585] = work1d.KKT[1133]-work1d.L[890]*work1d.v[235]-work1d.L[891]*work1d.v[315]-work1d.L[892]*work1d.v[404]-work1d.L[893]*work1d.v[405]-work1d.L[894]*work1d.v[581]-work1d.L[895]*work1d.v[582]-work1d.L[896]*work1d.v[583]-work1d.L[897]*work1d.v[584];
  work1d.d[585] = work1d.v[585];
  if (work1d.d[585] < 0)
    work1d.d[585] = settings1d.kkt_reg;
  else
    work1d.d[585] += settings1d.kkt_reg;
  work1d.d_inv[585] = 1/work1d.d[585];
  work1d.L[903] = (-work1d.L[900]*work1d.v[582]-work1d.L[901]*work1d.v[583]-work1d.L[902]*work1d.v[584])*work1d.d_inv[585];
  work1d.L[905] = (work1d.KKT[1134]-work1d.L[904]*work1d.v[584])*work1d.d_inv[585];
  work1d.L[914] = (-work1d.L[912]*work1d.v[405])*work1d.d_inv[585];
  work1d.v[446] = work1d.L[898]*work1d.d[446];
  work1d.v[447] = work1d.L[899]*work1d.d[447];
  work1d.v[582] = work1d.L[900]*work1d.d[582];
  work1d.v[583] = work1d.L[901]*work1d.d[583];
  work1d.v[584] = work1d.L[902]*work1d.d[584];
  work1d.v[585] = work1d.L[903]*work1d.d[585];
  work1d.v[586] = 0-work1d.L[898]*work1d.v[446]-work1d.L[899]*work1d.v[447]-work1d.L[900]*work1d.v[582]-work1d.L[901]*work1d.v[583]-work1d.L[902]*work1d.v[584]-work1d.L[903]*work1d.v[585];
  work1d.d[586] = work1d.v[586];
  if (work1d.d[586] > 0)
    work1d.d[586] = -settings1d.kkt_reg;
  else
    work1d.d[586] -= settings1d.kkt_reg;
  work1d.d_inv[586] = 1/work1d.d[586];
  work1d.L[906] = (-work1d.L[904]*work1d.v[584]-work1d.L[905]*work1d.v[585])*work1d.d_inv[586];
  work1d.L[915] = (-work1d.L[914]*work1d.v[585])*work1d.d_inv[586];
  work1d.L[920] = (-work1d.L[918]*work1d.v[447])*work1d.d_inv[586];
  work1d.v[584] = work1d.L[904]*work1d.d[584];
  work1d.v[585] = work1d.L[905]*work1d.d[585];
  work1d.v[586] = work1d.L[906]*work1d.d[586];
  work1d.v[587] = 0-work1d.L[904]*work1d.v[584]-work1d.L[905]*work1d.v[585]-work1d.L[906]*work1d.v[586];
  work1d.d[587] = work1d.v[587];
  if (work1d.d[587] > 0)
    work1d.d[587] = -settings1d.kkt_reg;
  else
    work1d.d[587] -= settings1d.kkt_reg;
  work1d.d_inv[587] = 1/work1d.d[587];
  work1d.L[909] = (work1d.KKT[1135])*work1d.d_inv[587];
  work1d.L[916] = (-work1d.L[914]*work1d.v[585]-work1d.L[915]*work1d.v[586])*work1d.d_inv[587];
  work1d.L[921] = (-work1d.L[920]*work1d.v[586])*work1d.d_inv[587];
  work1d.v[196] = work1d.L[907]*work1d.d[196];
  work1d.v[276] = work1d.L[908]*work1d.d[276];
  work1d.v[587] = work1d.L[909]*work1d.d[587];
  work1d.v[588] = work1d.KKT[1136]-work1d.L[907]*work1d.v[196]-work1d.L[908]*work1d.v[276]-work1d.L[909]*work1d.v[587];
  work1d.d[588] = work1d.v[588];
  if (work1d.d[588] < 0)
    work1d.d[588] = settings1d.kkt_reg;
  else
    work1d.d[588] += settings1d.kkt_reg;
  work1d.d_inv[588] = 1/work1d.d[588];
  work1d.L[917] = (-work1d.L[916]*work1d.v[587])*work1d.d_inv[588];
  work1d.L[922] = (work1d.KKT[1137]-work1d.L[921]*work1d.v[587])*work1d.d_inv[588];
  work1d.L[924] = (work1d.KKT[1138])*work1d.d_inv[588];
  work1d.v[236] = work1d.L[910]*work1d.d[236];
  work1d.v[316] = work1d.L[911]*work1d.d[316];
  work1d.v[405] = work1d.L[912]*work1d.d[405];
  work1d.v[406] = work1d.L[913]*work1d.d[406];
  work1d.v[585] = work1d.L[914]*work1d.d[585];
  work1d.v[586] = work1d.L[915]*work1d.d[586];
  work1d.v[587] = work1d.L[916]*work1d.d[587];
  work1d.v[588] = work1d.L[917]*work1d.d[588];
  work1d.v[589] = work1d.KKT[1139]-work1d.L[910]*work1d.v[236]-work1d.L[911]*work1d.v[316]-work1d.L[912]*work1d.v[405]-work1d.L[913]*work1d.v[406]-work1d.L[914]*work1d.v[585]-work1d.L[915]*work1d.v[586]-work1d.L[916]*work1d.v[587]-work1d.L[917]*work1d.v[588];
  work1d.d[589] = work1d.v[589];
  if (work1d.d[589] < 0)
    work1d.d[589] = settings1d.kkt_reg;
  else
    work1d.d[589] += settings1d.kkt_reg;
  work1d.d_inv[589] = 1/work1d.d[589];
  work1d.L[923] = (-work1d.L[920]*work1d.v[586]-work1d.L[921]*work1d.v[587]-work1d.L[922]*work1d.v[588])*work1d.d_inv[589];
  work1d.L[925] = (work1d.KKT[1140]-work1d.L[924]*work1d.v[588])*work1d.d_inv[589];
  work1d.L[934] = (-work1d.L[932]*work1d.v[406])*work1d.d_inv[589];
  work1d.v[447] = work1d.L[918]*work1d.d[447];
  work1d.v[448] = work1d.L[919]*work1d.d[448];
  work1d.v[586] = work1d.L[920]*work1d.d[586];
  work1d.v[587] = work1d.L[921]*work1d.d[587];
  work1d.v[588] = work1d.L[922]*work1d.d[588];
  work1d.v[589] = work1d.L[923]*work1d.d[589];
  work1d.v[590] = 0-work1d.L[918]*work1d.v[447]-work1d.L[919]*work1d.v[448]-work1d.L[920]*work1d.v[586]-work1d.L[921]*work1d.v[587]-work1d.L[922]*work1d.v[588]-work1d.L[923]*work1d.v[589];
  work1d.d[590] = work1d.v[590];
  if (work1d.d[590] > 0)
    work1d.d[590] = -settings1d.kkt_reg;
  else
    work1d.d[590] -= settings1d.kkt_reg;
  work1d.d_inv[590] = 1/work1d.d[590];
  work1d.L[926] = (-work1d.L[924]*work1d.v[588]-work1d.L[925]*work1d.v[589])*work1d.d_inv[590];
  work1d.L[935] = (-work1d.L[934]*work1d.v[589])*work1d.d_inv[590];
  work1d.L[940] = (-work1d.L[938]*work1d.v[448])*work1d.d_inv[590];
  work1d.v[588] = work1d.L[924]*work1d.d[588];
  work1d.v[589] = work1d.L[925]*work1d.d[589];
  work1d.v[590] = work1d.L[926]*work1d.d[590];
  work1d.v[591] = 0-work1d.L[924]*work1d.v[588]-work1d.L[925]*work1d.v[589]-work1d.L[926]*work1d.v[590];
  work1d.d[591] = work1d.v[591];
  if (work1d.d[591] > 0)
    work1d.d[591] = -settings1d.kkt_reg;
  else
    work1d.d[591] -= settings1d.kkt_reg;
  work1d.d_inv[591] = 1/work1d.d[591];
  work1d.L[929] = (work1d.KKT[1141])*work1d.d_inv[591];
  work1d.L[936] = (-work1d.L[934]*work1d.v[589]-work1d.L[935]*work1d.v[590])*work1d.d_inv[591];
  work1d.L[941] = (-work1d.L[940]*work1d.v[590])*work1d.d_inv[591];
  work1d.v[197] = work1d.L[927]*work1d.d[197];
  work1d.v[277] = work1d.L[928]*work1d.d[277];
  work1d.v[591] = work1d.L[929]*work1d.d[591];
  work1d.v[592] = work1d.KKT[1142]-work1d.L[927]*work1d.v[197]-work1d.L[928]*work1d.v[277]-work1d.L[929]*work1d.v[591];
  work1d.d[592] = work1d.v[592];
  if (work1d.d[592] < 0)
    work1d.d[592] = settings1d.kkt_reg;
  else
    work1d.d[592] += settings1d.kkt_reg;
  work1d.d_inv[592] = 1/work1d.d[592];
  work1d.L[937] = (-work1d.L[936]*work1d.v[591])*work1d.d_inv[592];
  work1d.L[942] = (work1d.KKT[1143]-work1d.L[941]*work1d.v[591])*work1d.d_inv[592];
  work1d.L[944] = (work1d.KKT[1144])*work1d.d_inv[592];
  work1d.v[237] = work1d.L[930]*work1d.d[237];
  work1d.v[317] = work1d.L[931]*work1d.d[317];
  work1d.v[406] = work1d.L[932]*work1d.d[406];
  work1d.v[407] = work1d.L[933]*work1d.d[407];
  work1d.v[589] = work1d.L[934]*work1d.d[589];
  work1d.v[590] = work1d.L[935]*work1d.d[590];
  work1d.v[591] = work1d.L[936]*work1d.d[591];
  work1d.v[592] = work1d.L[937]*work1d.d[592];
  work1d.v[593] = work1d.KKT[1145]-work1d.L[930]*work1d.v[237]-work1d.L[931]*work1d.v[317]-work1d.L[932]*work1d.v[406]-work1d.L[933]*work1d.v[407]-work1d.L[934]*work1d.v[589]-work1d.L[935]*work1d.v[590]-work1d.L[936]*work1d.v[591]-work1d.L[937]*work1d.v[592];
  work1d.d[593] = work1d.v[593];
  if (work1d.d[593] < 0)
    work1d.d[593] = settings1d.kkt_reg;
  else
    work1d.d[593] += settings1d.kkt_reg;
  work1d.d_inv[593] = 1/work1d.d[593];
  work1d.L[943] = (-work1d.L[940]*work1d.v[590]-work1d.L[941]*work1d.v[591]-work1d.L[942]*work1d.v[592])*work1d.d_inv[593];
  work1d.L[945] = (work1d.KKT[1146]-work1d.L[944]*work1d.v[592])*work1d.d_inv[593];
  work1d.L[961] = (-work1d.L[958]*work1d.v[407])*work1d.d_inv[593];
  work1d.v[448] = work1d.L[938]*work1d.d[448];
  work1d.v[449] = work1d.L[939]*work1d.d[449];
  work1d.v[590] = work1d.L[940]*work1d.d[590];
  work1d.v[591] = work1d.L[941]*work1d.d[591];
  work1d.v[592] = work1d.L[942]*work1d.d[592];
  work1d.v[593] = work1d.L[943]*work1d.d[593];
  work1d.v[594] = 0-work1d.L[938]*work1d.v[448]-work1d.L[939]*work1d.v[449]-work1d.L[940]*work1d.v[590]-work1d.L[941]*work1d.v[591]-work1d.L[942]*work1d.v[592]-work1d.L[943]*work1d.v[593];
  work1d.d[594] = work1d.v[594];
  if (work1d.d[594] > 0)
    work1d.d[594] = -settings1d.kkt_reg;
  else
    work1d.d[594] -= settings1d.kkt_reg;
  work1d.d_inv[594] = 1/work1d.d[594];
  work1d.L[946] = (-work1d.L[944]*work1d.v[592]-work1d.L[945]*work1d.v[593])*work1d.d_inv[594];
  work1d.L[949] = (-work1d.L[947]*work1d.v[449])*work1d.d_inv[594];
  work1d.L[962] = (-work1d.L[961]*work1d.v[593])*work1d.d_inv[594];
  work1d.v[592] = work1d.L[944]*work1d.d[592];
  work1d.v[593] = work1d.L[945]*work1d.d[593];
  work1d.v[594] = work1d.L[946]*work1d.d[594];
  work1d.v[595] = 0-work1d.L[944]*work1d.v[592]-work1d.L[945]*work1d.v[593]-work1d.L[946]*work1d.v[594];
  work1d.d[595] = work1d.v[595];
  if (work1d.d[595] > 0)
    work1d.d[595] = -settings1d.kkt_reg;
  else
    work1d.d[595] -= settings1d.kkt_reg;
  work1d.d_inv[595] = 1/work1d.d[595];
  work1d.L[950] = (-work1d.L[949]*work1d.v[594])*work1d.d_inv[595];
  work1d.L[953] = (work1d.KKT[1147])*work1d.d_inv[595];
  work1d.L[963] = (-work1d.L[961]*work1d.v[593]-work1d.L[962]*work1d.v[594])*work1d.d_inv[595];
  work1d.v[449] = work1d.L[947]*work1d.d[449];
  work1d.v[450] = work1d.L[948]*work1d.d[450];
  work1d.v[594] = work1d.L[949]*work1d.d[594];
  work1d.v[595] = work1d.L[950]*work1d.d[595];
  work1d.v[596] = 0-work1d.L[947]*work1d.v[449]-work1d.L[948]*work1d.v[450]-work1d.L[949]*work1d.v[594]-work1d.L[950]*work1d.v[595];
  work1d.d[596] = work1d.v[596];
  if (work1d.d[596] > 0)
    work1d.d[596] = -settings1d.kkt_reg;
  else
    work1d.d[596] -= settings1d.kkt_reg;
  work1d.d_inv[596] = 1/work1d.d[596];
  work1d.L[954] = (work1d.KKT[1148]-work1d.L[953]*work1d.v[595])*work1d.d_inv[596];
  work1d.L[964] = (-work1d.L[962]*work1d.v[594]-work1d.L[963]*work1d.v[595])*work1d.d_inv[596];
  work1d.L[972] = (-work1d.L[971]*work1d.v[450])*work1d.d_inv[596];
  work1d.v[597] = 0;
  work1d.d[597] = work1d.v[597];
  if (work1d.d[597] > 0)
    work1d.d[597] = -settings1d.kkt_reg;
  else
    work1d.d[597] -= settings1d.kkt_reg;
  work1d.d_inv[597] = 1/work1d.d[597];
  work1d.L[955] = (work1d.KKT[1149])*work1d.d_inv[597];
  work1d.L[965] = (work1d.KKT[1150])*work1d.d_inv[597];
  work1d.L[973] = (work1d.KKT[1151])*work1d.d_inv[597];
  work1d.v[198] = work1d.L[951]*work1d.d[198];
  work1d.v[278] = work1d.L[952]*work1d.d[278];
  work1d.v[595] = work1d.L[953]*work1d.d[595];
  work1d.v[596] = work1d.L[954]*work1d.d[596];
  work1d.v[597] = work1d.L[955]*work1d.d[597];
  work1d.v[598] = work1d.KKT[1152]-work1d.L[951]*work1d.v[198]-work1d.L[952]*work1d.v[278]-work1d.L[953]*work1d.v[595]-work1d.L[954]*work1d.v[596]-work1d.L[955]*work1d.v[597];
  work1d.d[598] = work1d.v[598];
  if (work1d.d[598] < 0)
    work1d.d[598] = settings1d.kkt_reg;
  else
    work1d.d[598] += settings1d.kkt_reg;
  work1d.d_inv[598] = 1/work1d.d[598];
  work1d.L[966] = (-work1d.L[963]*work1d.v[595]-work1d.L[964]*work1d.v[596]-work1d.L[965]*work1d.v[597])*work1d.d_inv[598];
  work1d.L[974] = (-work1d.L[972]*work1d.v[596]-work1d.L[973]*work1d.v[597])*work1d.d_inv[598];
  work1d.v[238] = work1d.L[956]*work1d.d[238];
  work1d.v[318] = work1d.L[957]*work1d.d[318];
  work1d.v[407] = work1d.L[958]*work1d.d[407];
  work1d.v[408] = work1d.L[959]*work1d.d[408];
  work1d.v[410] = work1d.L[960]*work1d.d[410];
  work1d.v[593] = work1d.L[961]*work1d.d[593];
  work1d.v[594] = work1d.L[962]*work1d.d[594];
  work1d.v[595] = work1d.L[963]*work1d.d[595];
  work1d.v[596] = work1d.L[964]*work1d.d[596];
  work1d.v[597] = work1d.L[965]*work1d.d[597];
  work1d.v[598] = work1d.L[966]*work1d.d[598];
  work1d.v[599] = work1d.KKT[1153]-work1d.L[956]*work1d.v[238]-work1d.L[957]*work1d.v[318]-work1d.L[958]*work1d.v[407]-work1d.L[959]*work1d.v[408]-work1d.L[960]*work1d.v[410]-work1d.L[961]*work1d.v[593]-work1d.L[962]*work1d.v[594]-work1d.L[963]*work1d.v[595]-work1d.L[964]*work1d.v[596]-work1d.L[965]*work1d.v[597]-work1d.L[966]*work1d.v[598];
  work1d.d[599] = work1d.v[599];
  if (work1d.d[599] < 0)
    work1d.d[599] = settings1d.kkt_reg;
  else
    work1d.d[599] += settings1d.kkt_reg;
  work1d.d_inv[599] = 1/work1d.d[599];
  work1d.L[975] = (-work1d.L[970]*work1d.v[410]-work1d.L[972]*work1d.v[596]-work1d.L[973]*work1d.v[597]-work1d.L[974]*work1d.v[598])*work1d.d_inv[599];
  work1d.v[199] = work1d.L[967]*work1d.d[199];
  work1d.v[279] = work1d.L[968]*work1d.d[279];
  work1d.v[409] = work1d.L[969]*work1d.d[409];
  work1d.v[410] = work1d.L[970]*work1d.d[410];
  work1d.v[450] = work1d.L[971]*work1d.d[450];
  work1d.v[596] = work1d.L[972]*work1d.d[596];
  work1d.v[597] = work1d.L[973]*work1d.d[597];
  work1d.v[598] = work1d.L[974]*work1d.d[598];
  work1d.v[599] = work1d.L[975]*work1d.d[599];
  work1d.v[600] = work1d.KKT[1154]-work1d.L[967]*work1d.v[199]-work1d.L[968]*work1d.v[279]-work1d.L[969]*work1d.v[409]-work1d.L[970]*work1d.v[410]-work1d.L[971]*work1d.v[450]-work1d.L[972]*work1d.v[596]-work1d.L[973]*work1d.v[597]-work1d.L[974]*work1d.v[598]-work1d.L[975]*work1d.v[599];
  work1d.d[600] = work1d.v[600];
  if (work1d.d[600] < 0)
    work1d.d[600] = settings1d.kkt_reg;
  else
    work1d.d[600] += settings1d.kkt_reg;
  work1d.d_inv[600] = 1/work1d.d[600];
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
  temp = work1d.KKT[645]-1*work1d.d[325]*1;
  residual += temp*temp;
  temp = work1d.KKT[647]-1*work1d.d[326]*1;
  residual += temp*temp;
  temp = work1d.KKT[649]-1*work1d.d[327]*1;
  residual += temp*temp;
  temp = work1d.KKT[651]-1*work1d.d[328]*1;
  residual += temp*temp;
  temp = work1d.KKT[653]-1*work1d.d[329]*1;
  residual += temp*temp;
  temp = work1d.KKT[655]-1*work1d.d[330]*1;
  residual += temp*temp;
  temp = work1d.KKT[657]-1*work1d.d[331]*1;
  residual += temp*temp;
  temp = work1d.KKT[659]-1*work1d.d[332]*1;
  residual += temp*temp;
  temp = work1d.KKT[661]-1*work1d.d[333]*1;
  residual += temp*temp;
  temp = work1d.KKT[663]-1*work1d.d[334]*1;
  residual += temp*temp;
  temp = work1d.KKT[665]-1*work1d.d[335]*1;
  residual += temp*temp;
  temp = work1d.KKT[667]-1*work1d.d[336]*1;
  residual += temp*temp;
  temp = work1d.KKT[669]-1*work1d.d[337]*1;
  residual += temp*temp;
  temp = work1d.KKT[671]-1*work1d.d[338]*1;
  residual += temp*temp;
  temp = work1d.KKT[673]-1*work1d.d[339]*1;
  residual += temp*temp;
  temp = work1d.KKT[675]-1*work1d.d[340]*1;
  residual += temp*temp;
  temp = work1d.KKT[677]-1*work1d.d[341]*1;
  residual += temp*temp;
  temp = work1d.KKT[679]-1*work1d.d[342]*1;
  residual += temp*temp;
  temp = work1d.KKT[681]-1*work1d.d[343]*1;
  residual += temp*temp;
  temp = work1d.KKT[683]-1*work1d.d[344]*1;
  residual += temp*temp;
  temp = work1d.KKT[685]-1*work1d.d[345]*1;
  residual += temp*temp;
  temp = work1d.KKT[687]-1*work1d.d[346]*1;
  residual += temp*temp;
  temp = work1d.KKT[689]-1*work1d.d[347]*1;
  residual += temp*temp;
  temp = work1d.KKT[691]-1*work1d.d[348]*1;
  residual += temp*temp;
  temp = work1d.KKT[693]-1*work1d.d[349]*1;
  residual += temp*temp;
  temp = work1d.KKT[695]-1*work1d.d[350]*1;
  residual += temp*temp;
  temp = work1d.KKT[697]-1*work1d.d[351]*1;
  residual += temp*temp;
  temp = work1d.KKT[699]-1*work1d.d[352]*1;
  residual += temp*temp;
  temp = work1d.KKT[701]-1*work1d.d[353]*1;
  residual += temp*temp;
  temp = work1d.KKT[703]-1*work1d.d[354]*1;
  residual += temp*temp;
  temp = work1d.KKT[705]-1*work1d.d[355]*1;
  residual += temp*temp;
  temp = work1d.KKT[707]-1*work1d.d[356]*1;
  residual += temp*temp;
  temp = work1d.KKT[709]-1*work1d.d[357]*1;
  residual += temp*temp;
  temp = work1d.KKT[711]-1*work1d.d[358]*1;
  residual += temp*temp;
  temp = work1d.KKT[713]-1*work1d.d[359]*1;
  residual += temp*temp;
  temp = work1d.KKT[715]-1*work1d.d[360]*1;
  residual += temp*temp;
  temp = work1d.KKT[717]-1*work1d.d[361]*1;
  residual += temp*temp;
  temp = work1d.KKT[719]-1*work1d.d[362]*1;
  residual += temp*temp;
  temp = work1d.KKT[721]-1*work1d.d[363]*1;
  residual += temp*temp;
  temp = work1d.KKT[0]-1*work1d.d[0]*1;
  residual += temp*temp;
  temp = work1d.KKT[726]-1*work1d.d[366]*1-work1d.L[165]*work1d.d[321]*work1d.L[165];
  residual += temp*temp;
  temp = work1d.KKT[815]-1*work1d.d[411]*1-work1d.L[215]*work1d.d[161]*work1d.L[215]-work1d.L[216]*work1d.d[241]*work1d.L[216]-work1d.L[217]*work1d.d[322]*work1d.L[217]-work1d.L[218]*work1d.d[370]*work1d.L[218];
  residual += temp*temp;
  temp = work1d.KKT[817]-1*work1d.d[412]*1-work1d.L[219]*work1d.d[201]*work1d.L[219]-work1d.L[220]*work1d.d[281]*work1d.L[220]-work1d.L[221]*work1d.d[324]*work1d.L[221]-work1d.L[222]*work1d.d[371]*work1d.L[222];
  residual += temp*temp;
  temp = work1d.KKT[819]-1*work1d.d[413]*1-work1d.L[223]*work1d.d[370]*work1d.L[223]-work1d.L[224]*work1d.d[411]*work1d.L[224];
  residual += temp*temp;
  temp = work1d.KKT[932]-1*work1d.d[452]*1-work1d.L[229]*work1d.d[162]*work1d.L[229]-work1d.L[230]*work1d.d[242]*work1d.L[230]-work1d.L[231]*work1d.d[451]*work1d.L[231];
  residual += temp*temp;
  temp = work1d.KKT[935]-1*work1d.d[453]*1-work1d.L[232]*work1d.d[202]*work1d.L[232]-work1d.L[233]*work1d.d[282]*work1d.L[233]-work1d.L[234]*work1d.d[371]*work1d.L[234]-work1d.L[235]*work1d.d[372]*work1d.L[235]-work1d.L[236]*work1d.d[412]*work1d.L[236]-work1d.L[237]*work1d.d[451]*work1d.L[237]-work1d.L[238]*work1d.d[452]*work1d.L[238];
  residual += temp*temp;
  temp = work1d.KKT[821]-1*work1d.d[414]*1;
  residual += temp*temp;
  temp = work1d.KKT[938]-1*work1d.d[456]*1-work1d.L[247]*work1d.d[163]*work1d.L[247]-work1d.L[248]*work1d.d[243]*work1d.L[248]-work1d.L[249]*work1d.d[455]*work1d.L[249];
  residual += temp*temp;
  temp = work1d.KKT[941]-1*work1d.d[457]*1-work1d.L[250]*work1d.d[203]*work1d.L[250]-work1d.L[251]*work1d.d[283]*work1d.L[251]-work1d.L[252]*work1d.d[372]*work1d.L[252]-work1d.L[253]*work1d.d[373]*work1d.L[253]-work1d.L[254]*work1d.d[453]*work1d.L[254]-work1d.L[256]*work1d.d[455]*work1d.L[256]-work1d.L[255]*work1d.d[454]*work1d.L[255]-work1d.L[257]*work1d.d[456]*work1d.L[257];
  residual += temp*temp;
  temp = work1d.KKT[824]-1*work1d.d[415]*1;
  residual += temp*temp;
  temp = work1d.KKT[944]-1*work1d.d[460]*1-work1d.L[267]*work1d.d[164]*work1d.L[267]-work1d.L[268]*work1d.d[244]*work1d.L[268]-work1d.L[269]*work1d.d[459]*work1d.L[269];
  residual += temp*temp;
  temp = work1d.KKT[947]-1*work1d.d[461]*1-work1d.L[270]*work1d.d[204]*work1d.L[270]-work1d.L[271]*work1d.d[284]*work1d.L[271]-work1d.L[272]*work1d.d[373]*work1d.L[272]-work1d.L[273]*work1d.d[374]*work1d.L[273]-work1d.L[274]*work1d.d[457]*work1d.L[274]-work1d.L[276]*work1d.d[459]*work1d.L[276]-work1d.L[275]*work1d.d[458]*work1d.L[275]-work1d.L[277]*work1d.d[460]*work1d.L[277];
  residual += temp*temp;
  temp = work1d.KKT[827]-1*work1d.d[416]*1;
  residual += temp*temp;
  temp = work1d.KKT[950]-1*work1d.d[464]*1-work1d.L[287]*work1d.d[165]*work1d.L[287]-work1d.L[288]*work1d.d[245]*work1d.L[288]-work1d.L[289]*work1d.d[463]*work1d.L[289];
  residual += temp*temp;
  temp = work1d.KKT[953]-1*work1d.d[465]*1-work1d.L[290]*work1d.d[205]*work1d.L[290]-work1d.L[291]*work1d.d[285]*work1d.L[291]-work1d.L[292]*work1d.d[374]*work1d.L[292]-work1d.L[293]*work1d.d[375]*work1d.L[293]-work1d.L[294]*work1d.d[461]*work1d.L[294]-work1d.L[296]*work1d.d[463]*work1d.L[296]-work1d.L[295]*work1d.d[462]*work1d.L[295]-work1d.L[297]*work1d.d[464]*work1d.L[297];
  residual += temp*temp;
  temp = work1d.KKT[830]-1*work1d.d[417]*1;
  residual += temp*temp;
  temp = work1d.KKT[956]-1*work1d.d[468]*1-work1d.L[307]*work1d.d[166]*work1d.L[307]-work1d.L[308]*work1d.d[246]*work1d.L[308]-work1d.L[309]*work1d.d[467]*work1d.L[309];
  residual += temp*temp;
  temp = work1d.KKT[959]-1*work1d.d[469]*1-work1d.L[310]*work1d.d[206]*work1d.L[310]-work1d.L[311]*work1d.d[286]*work1d.L[311]-work1d.L[312]*work1d.d[375]*work1d.L[312]-work1d.L[313]*work1d.d[376]*work1d.L[313]-work1d.L[314]*work1d.d[465]*work1d.L[314]-work1d.L[316]*work1d.d[467]*work1d.L[316]-work1d.L[315]*work1d.d[466]*work1d.L[315]-work1d.L[317]*work1d.d[468]*work1d.L[317];
  residual += temp*temp;
  temp = work1d.KKT[833]-1*work1d.d[418]*1;
  residual += temp*temp;
  temp = work1d.KKT[962]-1*work1d.d[472]*1-work1d.L[327]*work1d.d[167]*work1d.L[327]-work1d.L[328]*work1d.d[247]*work1d.L[328]-work1d.L[329]*work1d.d[471]*work1d.L[329];
  residual += temp*temp;
  temp = work1d.KKT[965]-1*work1d.d[473]*1-work1d.L[330]*work1d.d[207]*work1d.L[330]-work1d.L[331]*work1d.d[287]*work1d.L[331]-work1d.L[332]*work1d.d[376]*work1d.L[332]-work1d.L[333]*work1d.d[377]*work1d.L[333]-work1d.L[334]*work1d.d[469]*work1d.L[334]-work1d.L[336]*work1d.d[471]*work1d.L[336]-work1d.L[335]*work1d.d[470]*work1d.L[335]-work1d.L[337]*work1d.d[472]*work1d.L[337];
  residual += temp*temp;
  temp = work1d.KKT[836]-1*work1d.d[419]*1;
  residual += temp*temp;
  temp = work1d.KKT[968]-1*work1d.d[476]*1-work1d.L[347]*work1d.d[168]*work1d.L[347]-work1d.L[348]*work1d.d[248]*work1d.L[348]-work1d.L[349]*work1d.d[475]*work1d.L[349];
  residual += temp*temp;
  temp = work1d.KKT[971]-1*work1d.d[477]*1-work1d.L[350]*work1d.d[208]*work1d.L[350]-work1d.L[351]*work1d.d[288]*work1d.L[351]-work1d.L[352]*work1d.d[377]*work1d.L[352]-work1d.L[353]*work1d.d[378]*work1d.L[353]-work1d.L[354]*work1d.d[473]*work1d.L[354]-work1d.L[356]*work1d.d[475]*work1d.L[356]-work1d.L[355]*work1d.d[474]*work1d.L[355]-work1d.L[357]*work1d.d[476]*work1d.L[357];
  residual += temp*temp;
  temp = work1d.KKT[839]-1*work1d.d[420]*1;
  residual += temp*temp;
  temp = work1d.KKT[974]-1*work1d.d[480]*1-work1d.L[367]*work1d.d[169]*work1d.L[367]-work1d.L[368]*work1d.d[249]*work1d.L[368]-work1d.L[369]*work1d.d[479]*work1d.L[369];
  residual += temp*temp;
  temp = work1d.KKT[977]-1*work1d.d[481]*1-work1d.L[370]*work1d.d[209]*work1d.L[370]-work1d.L[371]*work1d.d[289]*work1d.L[371]-work1d.L[372]*work1d.d[378]*work1d.L[372]-work1d.L[373]*work1d.d[379]*work1d.L[373]-work1d.L[374]*work1d.d[477]*work1d.L[374]-work1d.L[376]*work1d.d[479]*work1d.L[376]-work1d.L[375]*work1d.d[478]*work1d.L[375]-work1d.L[377]*work1d.d[480]*work1d.L[377];
  residual += temp*temp;
  temp = work1d.KKT[842]-1*work1d.d[421]*1;
  residual += temp*temp;
  temp = work1d.KKT[980]-1*work1d.d[484]*1-work1d.L[387]*work1d.d[170]*work1d.L[387]-work1d.L[388]*work1d.d[250]*work1d.L[388]-work1d.L[389]*work1d.d[483]*work1d.L[389];
  residual += temp*temp;
  temp = work1d.KKT[983]-1*work1d.d[485]*1-work1d.L[390]*work1d.d[210]*work1d.L[390]-work1d.L[391]*work1d.d[290]*work1d.L[391]-work1d.L[392]*work1d.d[379]*work1d.L[392]-work1d.L[393]*work1d.d[380]*work1d.L[393]-work1d.L[394]*work1d.d[481]*work1d.L[394]-work1d.L[396]*work1d.d[483]*work1d.L[396]-work1d.L[395]*work1d.d[482]*work1d.L[395]-work1d.L[397]*work1d.d[484]*work1d.L[397];
  residual += temp*temp;
  temp = work1d.KKT[845]-1*work1d.d[422]*1;
  residual += temp*temp;
  temp = work1d.KKT[986]-1*work1d.d[488]*1-work1d.L[407]*work1d.d[171]*work1d.L[407]-work1d.L[408]*work1d.d[251]*work1d.L[408]-work1d.L[409]*work1d.d[487]*work1d.L[409];
  residual += temp*temp;
  temp = work1d.KKT[989]-1*work1d.d[489]*1-work1d.L[410]*work1d.d[211]*work1d.L[410]-work1d.L[411]*work1d.d[291]*work1d.L[411]-work1d.L[412]*work1d.d[380]*work1d.L[412]-work1d.L[413]*work1d.d[381]*work1d.L[413]-work1d.L[414]*work1d.d[485]*work1d.L[414]-work1d.L[416]*work1d.d[487]*work1d.L[416]-work1d.L[415]*work1d.d[486]*work1d.L[415]-work1d.L[417]*work1d.d[488]*work1d.L[417];
  residual += temp*temp;
  temp = work1d.KKT[848]-1*work1d.d[423]*1;
  residual += temp*temp;
  temp = work1d.KKT[992]-1*work1d.d[492]*1-work1d.L[427]*work1d.d[172]*work1d.L[427]-work1d.L[428]*work1d.d[252]*work1d.L[428]-work1d.L[429]*work1d.d[491]*work1d.L[429];
  residual += temp*temp;
  temp = work1d.KKT[995]-1*work1d.d[493]*1-work1d.L[430]*work1d.d[212]*work1d.L[430]-work1d.L[431]*work1d.d[292]*work1d.L[431]-work1d.L[432]*work1d.d[381]*work1d.L[432]-work1d.L[433]*work1d.d[382]*work1d.L[433]-work1d.L[434]*work1d.d[489]*work1d.L[434]-work1d.L[436]*work1d.d[491]*work1d.L[436]-work1d.L[435]*work1d.d[490]*work1d.L[435]-work1d.L[437]*work1d.d[492]*work1d.L[437];
  residual += temp*temp;
  temp = work1d.KKT[851]-1*work1d.d[424]*1;
  residual += temp*temp;
  temp = work1d.KKT[998]-1*work1d.d[496]*1-work1d.L[447]*work1d.d[173]*work1d.L[447]-work1d.L[448]*work1d.d[253]*work1d.L[448]-work1d.L[449]*work1d.d[495]*work1d.L[449];
  residual += temp*temp;
  temp = work1d.KKT[1001]-1*work1d.d[497]*1-work1d.L[450]*work1d.d[213]*work1d.L[450]-work1d.L[451]*work1d.d[293]*work1d.L[451]-work1d.L[452]*work1d.d[382]*work1d.L[452]-work1d.L[453]*work1d.d[383]*work1d.L[453]-work1d.L[454]*work1d.d[493]*work1d.L[454]-work1d.L[456]*work1d.d[495]*work1d.L[456]-work1d.L[455]*work1d.d[494]*work1d.L[455]-work1d.L[457]*work1d.d[496]*work1d.L[457];
  residual += temp*temp;
  temp = work1d.KKT[854]-1*work1d.d[425]*1;
  residual += temp*temp;
  temp = work1d.KKT[1004]-1*work1d.d[500]*1-work1d.L[467]*work1d.d[174]*work1d.L[467]-work1d.L[468]*work1d.d[254]*work1d.L[468]-work1d.L[469]*work1d.d[499]*work1d.L[469];
  residual += temp*temp;
  temp = work1d.KKT[1007]-1*work1d.d[501]*1-work1d.L[470]*work1d.d[214]*work1d.L[470]-work1d.L[471]*work1d.d[294]*work1d.L[471]-work1d.L[472]*work1d.d[383]*work1d.L[472]-work1d.L[473]*work1d.d[384]*work1d.L[473]-work1d.L[474]*work1d.d[497]*work1d.L[474]-work1d.L[476]*work1d.d[499]*work1d.L[476]-work1d.L[475]*work1d.d[498]*work1d.L[475]-work1d.L[477]*work1d.d[500]*work1d.L[477];
  residual += temp*temp;
  temp = work1d.KKT[857]-1*work1d.d[426]*1;
  residual += temp*temp;
  temp = work1d.KKT[1010]-1*work1d.d[504]*1-work1d.L[487]*work1d.d[175]*work1d.L[487]-work1d.L[488]*work1d.d[255]*work1d.L[488]-work1d.L[489]*work1d.d[503]*work1d.L[489];
  residual += temp*temp;
  temp = work1d.KKT[1013]-1*work1d.d[505]*1-work1d.L[490]*work1d.d[215]*work1d.L[490]-work1d.L[491]*work1d.d[295]*work1d.L[491]-work1d.L[492]*work1d.d[384]*work1d.L[492]-work1d.L[493]*work1d.d[385]*work1d.L[493]-work1d.L[494]*work1d.d[501]*work1d.L[494]-work1d.L[496]*work1d.d[503]*work1d.L[496]-work1d.L[495]*work1d.d[502]*work1d.L[495]-work1d.L[497]*work1d.d[504]*work1d.L[497];
  residual += temp*temp;
  temp = work1d.KKT[860]-1*work1d.d[427]*1;
  residual += temp*temp;
  temp = work1d.KKT[1016]-1*work1d.d[508]*1-work1d.L[507]*work1d.d[176]*work1d.L[507]-work1d.L[508]*work1d.d[256]*work1d.L[508]-work1d.L[509]*work1d.d[507]*work1d.L[509];
  residual += temp*temp;
  temp = work1d.KKT[1019]-1*work1d.d[509]*1-work1d.L[510]*work1d.d[216]*work1d.L[510]-work1d.L[511]*work1d.d[296]*work1d.L[511]-work1d.L[512]*work1d.d[385]*work1d.L[512]-work1d.L[513]*work1d.d[386]*work1d.L[513]-work1d.L[514]*work1d.d[505]*work1d.L[514]-work1d.L[516]*work1d.d[507]*work1d.L[516]-work1d.L[515]*work1d.d[506]*work1d.L[515]-work1d.L[517]*work1d.d[508]*work1d.L[517];
  residual += temp*temp;
  temp = work1d.KKT[863]-1*work1d.d[428]*1;
  residual += temp*temp;
  temp = work1d.KKT[1022]-1*work1d.d[512]*1-work1d.L[527]*work1d.d[177]*work1d.L[527]-work1d.L[528]*work1d.d[257]*work1d.L[528]-work1d.L[529]*work1d.d[511]*work1d.L[529];
  residual += temp*temp;
  temp = work1d.KKT[1025]-1*work1d.d[513]*1-work1d.L[530]*work1d.d[217]*work1d.L[530]-work1d.L[531]*work1d.d[297]*work1d.L[531]-work1d.L[532]*work1d.d[386]*work1d.L[532]-work1d.L[533]*work1d.d[387]*work1d.L[533]-work1d.L[534]*work1d.d[509]*work1d.L[534]-work1d.L[536]*work1d.d[511]*work1d.L[536]-work1d.L[535]*work1d.d[510]*work1d.L[535]-work1d.L[537]*work1d.d[512]*work1d.L[537];
  residual += temp*temp;
  temp = work1d.KKT[866]-1*work1d.d[429]*1;
  residual += temp*temp;
  temp = work1d.KKT[1028]-1*work1d.d[516]*1-work1d.L[547]*work1d.d[178]*work1d.L[547]-work1d.L[548]*work1d.d[258]*work1d.L[548]-work1d.L[549]*work1d.d[515]*work1d.L[549];
  residual += temp*temp;
  temp = work1d.KKT[1031]-1*work1d.d[517]*1-work1d.L[550]*work1d.d[218]*work1d.L[550]-work1d.L[551]*work1d.d[298]*work1d.L[551]-work1d.L[552]*work1d.d[387]*work1d.L[552]-work1d.L[553]*work1d.d[388]*work1d.L[553]-work1d.L[554]*work1d.d[513]*work1d.L[554]-work1d.L[556]*work1d.d[515]*work1d.L[556]-work1d.L[555]*work1d.d[514]*work1d.L[555]-work1d.L[557]*work1d.d[516]*work1d.L[557];
  residual += temp*temp;
  temp = work1d.KKT[869]-1*work1d.d[430]*1;
  residual += temp*temp;
  temp = work1d.KKT[1034]-1*work1d.d[520]*1-work1d.L[567]*work1d.d[179]*work1d.L[567]-work1d.L[568]*work1d.d[259]*work1d.L[568]-work1d.L[569]*work1d.d[519]*work1d.L[569];
  residual += temp*temp;
  temp = work1d.KKT[1037]-1*work1d.d[521]*1-work1d.L[570]*work1d.d[219]*work1d.L[570]-work1d.L[571]*work1d.d[299]*work1d.L[571]-work1d.L[572]*work1d.d[388]*work1d.L[572]-work1d.L[573]*work1d.d[389]*work1d.L[573]-work1d.L[574]*work1d.d[517]*work1d.L[574]-work1d.L[576]*work1d.d[519]*work1d.L[576]-work1d.L[575]*work1d.d[518]*work1d.L[575]-work1d.L[577]*work1d.d[520]*work1d.L[577];
  residual += temp*temp;
  temp = work1d.KKT[872]-1*work1d.d[431]*1;
  residual += temp*temp;
  temp = work1d.KKT[1040]-1*work1d.d[524]*1-work1d.L[587]*work1d.d[180]*work1d.L[587]-work1d.L[588]*work1d.d[260]*work1d.L[588]-work1d.L[589]*work1d.d[523]*work1d.L[589];
  residual += temp*temp;
  temp = work1d.KKT[1043]-1*work1d.d[525]*1-work1d.L[590]*work1d.d[220]*work1d.L[590]-work1d.L[591]*work1d.d[300]*work1d.L[591]-work1d.L[592]*work1d.d[389]*work1d.L[592]-work1d.L[593]*work1d.d[390]*work1d.L[593]-work1d.L[594]*work1d.d[521]*work1d.L[594]-work1d.L[596]*work1d.d[523]*work1d.L[596]-work1d.L[595]*work1d.d[522]*work1d.L[595]-work1d.L[597]*work1d.d[524]*work1d.L[597];
  residual += temp*temp;
  temp = work1d.KKT[875]-1*work1d.d[432]*1;
  residual += temp*temp;
  temp = work1d.KKT[1046]-1*work1d.d[528]*1-work1d.L[607]*work1d.d[181]*work1d.L[607]-work1d.L[608]*work1d.d[261]*work1d.L[608]-work1d.L[609]*work1d.d[527]*work1d.L[609];
  residual += temp*temp;
  temp = work1d.KKT[1049]-1*work1d.d[529]*1-work1d.L[610]*work1d.d[221]*work1d.L[610]-work1d.L[611]*work1d.d[301]*work1d.L[611]-work1d.L[612]*work1d.d[390]*work1d.L[612]-work1d.L[613]*work1d.d[391]*work1d.L[613]-work1d.L[614]*work1d.d[525]*work1d.L[614]-work1d.L[616]*work1d.d[527]*work1d.L[616]-work1d.L[615]*work1d.d[526]*work1d.L[615]-work1d.L[617]*work1d.d[528]*work1d.L[617];
  residual += temp*temp;
  temp = work1d.KKT[878]-1*work1d.d[433]*1;
  residual += temp*temp;
  temp = work1d.KKT[1052]-1*work1d.d[532]*1-work1d.L[627]*work1d.d[182]*work1d.L[627]-work1d.L[628]*work1d.d[262]*work1d.L[628]-work1d.L[629]*work1d.d[531]*work1d.L[629];
  residual += temp*temp;
  temp = work1d.KKT[1055]-1*work1d.d[533]*1-work1d.L[630]*work1d.d[222]*work1d.L[630]-work1d.L[631]*work1d.d[302]*work1d.L[631]-work1d.L[632]*work1d.d[391]*work1d.L[632]-work1d.L[633]*work1d.d[392]*work1d.L[633]-work1d.L[634]*work1d.d[529]*work1d.L[634]-work1d.L[636]*work1d.d[531]*work1d.L[636]-work1d.L[635]*work1d.d[530]*work1d.L[635]-work1d.L[637]*work1d.d[532]*work1d.L[637];
  residual += temp*temp;
  temp = work1d.KKT[881]-1*work1d.d[434]*1;
  residual += temp*temp;
  temp = work1d.KKT[1058]-1*work1d.d[536]*1-work1d.L[647]*work1d.d[183]*work1d.L[647]-work1d.L[648]*work1d.d[263]*work1d.L[648]-work1d.L[649]*work1d.d[535]*work1d.L[649];
  residual += temp*temp;
  temp = work1d.KKT[1061]-1*work1d.d[537]*1-work1d.L[650]*work1d.d[223]*work1d.L[650]-work1d.L[651]*work1d.d[303]*work1d.L[651]-work1d.L[652]*work1d.d[392]*work1d.L[652]-work1d.L[653]*work1d.d[393]*work1d.L[653]-work1d.L[654]*work1d.d[533]*work1d.L[654]-work1d.L[656]*work1d.d[535]*work1d.L[656]-work1d.L[655]*work1d.d[534]*work1d.L[655]-work1d.L[657]*work1d.d[536]*work1d.L[657];
  residual += temp*temp;
  temp = work1d.KKT[884]-1*work1d.d[435]*1;
  residual += temp*temp;
  temp = work1d.KKT[1064]-1*work1d.d[540]*1-work1d.L[667]*work1d.d[184]*work1d.L[667]-work1d.L[668]*work1d.d[264]*work1d.L[668]-work1d.L[669]*work1d.d[539]*work1d.L[669];
  residual += temp*temp;
  temp = work1d.KKT[1067]-1*work1d.d[541]*1-work1d.L[670]*work1d.d[224]*work1d.L[670]-work1d.L[671]*work1d.d[304]*work1d.L[671]-work1d.L[672]*work1d.d[393]*work1d.L[672]-work1d.L[673]*work1d.d[394]*work1d.L[673]-work1d.L[674]*work1d.d[537]*work1d.L[674]-work1d.L[676]*work1d.d[539]*work1d.L[676]-work1d.L[675]*work1d.d[538]*work1d.L[675]-work1d.L[677]*work1d.d[540]*work1d.L[677];
  residual += temp*temp;
  temp = work1d.KKT[887]-1*work1d.d[436]*1;
  residual += temp*temp;
  temp = work1d.KKT[1070]-1*work1d.d[544]*1-work1d.L[687]*work1d.d[185]*work1d.L[687]-work1d.L[688]*work1d.d[265]*work1d.L[688]-work1d.L[689]*work1d.d[543]*work1d.L[689];
  residual += temp*temp;
  temp = work1d.KKT[1073]-1*work1d.d[545]*1-work1d.L[690]*work1d.d[225]*work1d.L[690]-work1d.L[691]*work1d.d[305]*work1d.L[691]-work1d.L[692]*work1d.d[394]*work1d.L[692]-work1d.L[693]*work1d.d[395]*work1d.L[693]-work1d.L[694]*work1d.d[541]*work1d.L[694]-work1d.L[696]*work1d.d[543]*work1d.L[696]-work1d.L[695]*work1d.d[542]*work1d.L[695]-work1d.L[697]*work1d.d[544]*work1d.L[697];
  residual += temp*temp;
  temp = work1d.KKT[890]-1*work1d.d[437]*1;
  residual += temp*temp;
  temp = work1d.KKT[1076]-1*work1d.d[548]*1-work1d.L[707]*work1d.d[186]*work1d.L[707]-work1d.L[708]*work1d.d[266]*work1d.L[708]-work1d.L[709]*work1d.d[547]*work1d.L[709];
  residual += temp*temp;
  temp = work1d.KKT[1079]-1*work1d.d[549]*1-work1d.L[710]*work1d.d[226]*work1d.L[710]-work1d.L[711]*work1d.d[306]*work1d.L[711]-work1d.L[712]*work1d.d[395]*work1d.L[712]-work1d.L[713]*work1d.d[396]*work1d.L[713]-work1d.L[714]*work1d.d[545]*work1d.L[714]-work1d.L[716]*work1d.d[547]*work1d.L[716]-work1d.L[715]*work1d.d[546]*work1d.L[715]-work1d.L[717]*work1d.d[548]*work1d.L[717];
  residual += temp*temp;
  temp = work1d.KKT[893]-1*work1d.d[438]*1;
  residual += temp*temp;
  temp = work1d.KKT[1082]-1*work1d.d[552]*1-work1d.L[727]*work1d.d[187]*work1d.L[727]-work1d.L[728]*work1d.d[267]*work1d.L[728]-work1d.L[729]*work1d.d[551]*work1d.L[729];
  residual += temp*temp;
  temp = work1d.KKT[1085]-1*work1d.d[553]*1-work1d.L[730]*work1d.d[227]*work1d.L[730]-work1d.L[731]*work1d.d[307]*work1d.L[731]-work1d.L[732]*work1d.d[396]*work1d.L[732]-work1d.L[733]*work1d.d[397]*work1d.L[733]-work1d.L[734]*work1d.d[549]*work1d.L[734]-work1d.L[736]*work1d.d[551]*work1d.L[736]-work1d.L[735]*work1d.d[550]*work1d.L[735]-work1d.L[737]*work1d.d[552]*work1d.L[737];
  residual += temp*temp;
  temp = work1d.KKT[896]-1*work1d.d[439]*1;
  residual += temp*temp;
  temp = work1d.KKT[1088]-1*work1d.d[556]*1-work1d.L[747]*work1d.d[188]*work1d.L[747]-work1d.L[748]*work1d.d[268]*work1d.L[748]-work1d.L[749]*work1d.d[555]*work1d.L[749];
  residual += temp*temp;
  temp = work1d.KKT[1091]-1*work1d.d[557]*1-work1d.L[750]*work1d.d[228]*work1d.L[750]-work1d.L[751]*work1d.d[308]*work1d.L[751]-work1d.L[752]*work1d.d[397]*work1d.L[752]-work1d.L[753]*work1d.d[398]*work1d.L[753]-work1d.L[754]*work1d.d[553]*work1d.L[754]-work1d.L[756]*work1d.d[555]*work1d.L[756]-work1d.L[755]*work1d.d[554]*work1d.L[755]-work1d.L[757]*work1d.d[556]*work1d.L[757];
  residual += temp*temp;
  temp = work1d.KKT[899]-1*work1d.d[440]*1;
  residual += temp*temp;
  temp = work1d.KKT[1094]-1*work1d.d[560]*1-work1d.L[767]*work1d.d[189]*work1d.L[767]-work1d.L[768]*work1d.d[269]*work1d.L[768]-work1d.L[769]*work1d.d[559]*work1d.L[769];
  residual += temp*temp;
  temp = work1d.KKT[1097]-1*work1d.d[561]*1-work1d.L[770]*work1d.d[229]*work1d.L[770]-work1d.L[771]*work1d.d[309]*work1d.L[771]-work1d.L[772]*work1d.d[398]*work1d.L[772]-work1d.L[773]*work1d.d[399]*work1d.L[773]-work1d.L[774]*work1d.d[557]*work1d.L[774]-work1d.L[776]*work1d.d[559]*work1d.L[776]-work1d.L[775]*work1d.d[558]*work1d.L[775]-work1d.L[777]*work1d.d[560]*work1d.L[777];
  residual += temp*temp;
  temp = work1d.KKT[902]-1*work1d.d[441]*1;
  residual += temp*temp;
  temp = work1d.KKT[1100]-1*work1d.d[564]*1-work1d.L[787]*work1d.d[190]*work1d.L[787]-work1d.L[788]*work1d.d[270]*work1d.L[788]-work1d.L[789]*work1d.d[563]*work1d.L[789];
  residual += temp*temp;
  temp = work1d.KKT[1103]-1*work1d.d[565]*1-work1d.L[790]*work1d.d[230]*work1d.L[790]-work1d.L[791]*work1d.d[310]*work1d.L[791]-work1d.L[792]*work1d.d[399]*work1d.L[792]-work1d.L[793]*work1d.d[400]*work1d.L[793]-work1d.L[794]*work1d.d[561]*work1d.L[794]-work1d.L[796]*work1d.d[563]*work1d.L[796]-work1d.L[795]*work1d.d[562]*work1d.L[795]-work1d.L[797]*work1d.d[564]*work1d.L[797];
  residual += temp*temp;
  temp = work1d.KKT[905]-1*work1d.d[442]*1;
  residual += temp*temp;
  temp = work1d.KKT[1106]-1*work1d.d[568]*1-work1d.L[807]*work1d.d[191]*work1d.L[807]-work1d.L[808]*work1d.d[271]*work1d.L[808]-work1d.L[809]*work1d.d[567]*work1d.L[809];
  residual += temp*temp;
  temp = work1d.KKT[1109]-1*work1d.d[569]*1-work1d.L[810]*work1d.d[231]*work1d.L[810]-work1d.L[811]*work1d.d[311]*work1d.L[811]-work1d.L[812]*work1d.d[400]*work1d.L[812]-work1d.L[813]*work1d.d[401]*work1d.L[813]-work1d.L[814]*work1d.d[565]*work1d.L[814]-work1d.L[816]*work1d.d[567]*work1d.L[816]-work1d.L[815]*work1d.d[566]*work1d.L[815]-work1d.L[817]*work1d.d[568]*work1d.L[817];
  residual += temp*temp;
  temp = work1d.KKT[908]-1*work1d.d[443]*1;
  residual += temp*temp;
  temp = work1d.KKT[1112]-1*work1d.d[572]*1-work1d.L[827]*work1d.d[192]*work1d.L[827]-work1d.L[828]*work1d.d[272]*work1d.L[828]-work1d.L[829]*work1d.d[571]*work1d.L[829];
  residual += temp*temp;
  temp = work1d.KKT[1115]-1*work1d.d[573]*1-work1d.L[830]*work1d.d[232]*work1d.L[830]-work1d.L[831]*work1d.d[312]*work1d.L[831]-work1d.L[832]*work1d.d[401]*work1d.L[832]-work1d.L[833]*work1d.d[402]*work1d.L[833]-work1d.L[834]*work1d.d[569]*work1d.L[834]-work1d.L[836]*work1d.d[571]*work1d.L[836]-work1d.L[835]*work1d.d[570]*work1d.L[835]-work1d.L[837]*work1d.d[572]*work1d.L[837];
  residual += temp*temp;
  temp = work1d.KKT[911]-1*work1d.d[444]*1;
  residual += temp*temp;
  temp = work1d.KKT[1118]-1*work1d.d[576]*1-work1d.L[847]*work1d.d[193]*work1d.L[847]-work1d.L[848]*work1d.d[273]*work1d.L[848]-work1d.L[849]*work1d.d[575]*work1d.L[849];
  residual += temp*temp;
  temp = work1d.KKT[1121]-1*work1d.d[577]*1-work1d.L[850]*work1d.d[233]*work1d.L[850]-work1d.L[851]*work1d.d[313]*work1d.L[851]-work1d.L[852]*work1d.d[402]*work1d.L[852]-work1d.L[853]*work1d.d[403]*work1d.L[853]-work1d.L[854]*work1d.d[573]*work1d.L[854]-work1d.L[856]*work1d.d[575]*work1d.L[856]-work1d.L[855]*work1d.d[574]*work1d.L[855]-work1d.L[857]*work1d.d[576]*work1d.L[857];
  residual += temp*temp;
  temp = work1d.KKT[914]-1*work1d.d[445]*1;
  residual += temp*temp;
  temp = work1d.KKT[1124]-1*work1d.d[580]*1-work1d.L[867]*work1d.d[194]*work1d.L[867]-work1d.L[868]*work1d.d[274]*work1d.L[868]-work1d.L[869]*work1d.d[579]*work1d.L[869];
  residual += temp*temp;
  temp = work1d.KKT[1127]-1*work1d.d[581]*1-work1d.L[870]*work1d.d[234]*work1d.L[870]-work1d.L[871]*work1d.d[314]*work1d.L[871]-work1d.L[872]*work1d.d[403]*work1d.L[872]-work1d.L[873]*work1d.d[404]*work1d.L[873]-work1d.L[874]*work1d.d[577]*work1d.L[874]-work1d.L[876]*work1d.d[579]*work1d.L[876]-work1d.L[875]*work1d.d[578]*work1d.L[875]-work1d.L[877]*work1d.d[580]*work1d.L[877];
  residual += temp*temp;
  temp = work1d.KKT[917]-1*work1d.d[446]*1;
  residual += temp*temp;
  temp = work1d.KKT[1130]-1*work1d.d[584]*1-work1d.L[887]*work1d.d[195]*work1d.L[887]-work1d.L[888]*work1d.d[275]*work1d.L[888]-work1d.L[889]*work1d.d[583]*work1d.L[889];
  residual += temp*temp;
  temp = work1d.KKT[1133]-1*work1d.d[585]*1-work1d.L[890]*work1d.d[235]*work1d.L[890]-work1d.L[891]*work1d.d[315]*work1d.L[891]-work1d.L[892]*work1d.d[404]*work1d.L[892]-work1d.L[893]*work1d.d[405]*work1d.L[893]-work1d.L[894]*work1d.d[581]*work1d.L[894]-work1d.L[896]*work1d.d[583]*work1d.L[896]-work1d.L[895]*work1d.d[582]*work1d.L[895]-work1d.L[897]*work1d.d[584]*work1d.L[897];
  residual += temp*temp;
  temp = work1d.KKT[920]-1*work1d.d[447]*1;
  residual += temp*temp;
  temp = work1d.KKT[1136]-1*work1d.d[588]*1-work1d.L[907]*work1d.d[196]*work1d.L[907]-work1d.L[908]*work1d.d[276]*work1d.L[908]-work1d.L[909]*work1d.d[587]*work1d.L[909];
  residual += temp*temp;
  temp = work1d.KKT[1139]-1*work1d.d[589]*1-work1d.L[910]*work1d.d[236]*work1d.L[910]-work1d.L[911]*work1d.d[316]*work1d.L[911]-work1d.L[912]*work1d.d[405]*work1d.L[912]-work1d.L[913]*work1d.d[406]*work1d.L[913]-work1d.L[914]*work1d.d[585]*work1d.L[914]-work1d.L[916]*work1d.d[587]*work1d.L[916]-work1d.L[915]*work1d.d[586]*work1d.L[915]-work1d.L[917]*work1d.d[588]*work1d.L[917];
  residual += temp*temp;
  temp = work1d.KKT[923]-1*work1d.d[448]*1;
  residual += temp*temp;
  temp = work1d.KKT[1142]-1*work1d.d[592]*1-work1d.L[927]*work1d.d[197]*work1d.L[927]-work1d.L[928]*work1d.d[277]*work1d.L[928]-work1d.L[929]*work1d.d[591]*work1d.L[929];
  residual += temp*temp;
  temp = work1d.KKT[1145]-1*work1d.d[593]*1-work1d.L[930]*work1d.d[237]*work1d.L[930]-work1d.L[931]*work1d.d[317]*work1d.L[931]-work1d.L[932]*work1d.d[406]*work1d.L[932]-work1d.L[933]*work1d.d[407]*work1d.L[933]-work1d.L[934]*work1d.d[589]*work1d.L[934]-work1d.L[936]*work1d.d[591]*work1d.L[936]-work1d.L[935]*work1d.d[590]*work1d.L[935]-work1d.L[937]*work1d.d[592]*work1d.L[937];
  residual += temp*temp;
  temp = work1d.KKT[926]-1*work1d.d[449]*1;
  residual += temp*temp;
  temp = work1d.KKT[1152]-1*work1d.d[598]*1-work1d.L[951]*work1d.d[198]*work1d.L[951]-work1d.L[952]*work1d.d[278]*work1d.L[952]-work1d.L[953]*work1d.d[595]*work1d.L[953]-work1d.L[955]*work1d.d[597]*work1d.L[955]-work1d.L[954]*work1d.d[596]*work1d.L[954];
  residual += temp*temp;
  temp = work1d.KKT[1153]-1*work1d.d[599]*1-work1d.L[956]*work1d.d[238]*work1d.L[956]-work1d.L[957]*work1d.d[318]*work1d.L[957]-work1d.L[958]*work1d.d[407]*work1d.L[958]-work1d.L[959]*work1d.d[408]*work1d.L[959]-work1d.L[965]*work1d.d[597]*work1d.L[965]-work1d.L[961]*work1d.d[593]*work1d.L[961]-work1d.L[960]*work1d.d[410]*work1d.L[960]-work1d.L[963]*work1d.d[595]*work1d.L[963]-work1d.L[962]*work1d.d[594]*work1d.L[962]-work1d.L[964]*work1d.d[596]*work1d.L[964]-work1d.L[966]*work1d.d[598]*work1d.L[966];
  residual += temp*temp;
  temp = work1d.KKT[929]-1*work1d.d[450]*1-work1d.L[225]*work1d.d[409]*work1d.L[225];
  residual += temp*temp;
  temp = work1d.KKT[1154]-1*work1d.d[600]*1-work1d.L[967]*work1d.d[199]*work1d.L[967]-work1d.L[968]*work1d.d[279]*work1d.L[968]-work1d.L[973]*work1d.d[597]*work1d.L[973]-work1d.L[970]*work1d.d[410]*work1d.L[970]-work1d.L[969]*work1d.d[409]*work1d.L[969]-work1d.L[971]*work1d.d[450]*work1d.L[971]-work1d.L[975]*work1d.d[599]*work1d.L[975]-work1d.L[972]*work1d.d[596]*work1d.L[972]-work1d.L[974]*work1d.d[598]*work1d.L[974];
  residual += temp*temp;
  temp = work1d.KKT[732]-1*work1d.d[369]*1-work1d.L[168]*work1d.d[239]*work1d.L[168]-work1d.L[169]*work1d.d[319]*work1d.L[169]-work1d.L[170]*work1d.d[365]*work1d.L[170];
  residual += temp*temp;
  temp = work1d.KKT[728]-1*work1d.d[367]*1;
  residual += temp*temp;
  temp = work1d.KKT[730]-1*work1d.d[368]*1-work1d.L[166]*work1d.d[200]*work1d.L[166]-work1d.L[167]*work1d.d[280]*work1d.L[167];
  residual += temp*temp;
  temp = work1d.KKT[723]-1*work1d.d[364]*1-work1d.L[161]*work1d.d[240]*work1d.L[161]-work1d.L[162]*work1d.d[320]*work1d.L[162];
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
  temp = work1d.KKT[2]-work1d.L[0]*work1d.d[1]*1;
  residual += temp*temp;
  temp = work1d.KKT[4]-work1d.L[1]*work1d.d[2]*1;
  residual += temp*temp;
  temp = work1d.KKT[6]-work1d.L[2]*work1d.d[3]*1;
  residual += temp*temp;
  temp = work1d.KKT[8]-work1d.L[3]*work1d.d[4]*1;
  residual += temp*temp;
  temp = work1d.KKT[10]-work1d.L[4]*work1d.d[5]*1;
  residual += temp*temp;
  temp = work1d.KKT[12]-work1d.L[5]*work1d.d[6]*1;
  residual += temp*temp;
  temp = work1d.KKT[14]-work1d.L[6]*work1d.d[7]*1;
  residual += temp*temp;
  temp = work1d.KKT[16]-work1d.L[7]*work1d.d[8]*1;
  residual += temp*temp;
  temp = work1d.KKT[18]-work1d.L[8]*work1d.d[9]*1;
  residual += temp*temp;
  temp = work1d.KKT[20]-work1d.L[9]*work1d.d[10]*1;
  residual += temp*temp;
  temp = work1d.KKT[22]-work1d.L[10]*work1d.d[11]*1;
  residual += temp*temp;
  temp = work1d.KKT[24]-work1d.L[11]*work1d.d[12]*1;
  residual += temp*temp;
  temp = work1d.KKT[26]-work1d.L[12]*work1d.d[13]*1;
  residual += temp*temp;
  temp = work1d.KKT[28]-work1d.L[13]*work1d.d[14]*1;
  residual += temp*temp;
  temp = work1d.KKT[30]-work1d.L[14]*work1d.d[15]*1;
  residual += temp*temp;
  temp = work1d.KKT[32]-work1d.L[15]*work1d.d[16]*1;
  residual += temp*temp;
  temp = work1d.KKT[34]-work1d.L[16]*work1d.d[17]*1;
  residual += temp*temp;
  temp = work1d.KKT[36]-work1d.L[17]*work1d.d[18]*1;
  residual += temp*temp;
  temp = work1d.KKT[38]-work1d.L[18]*work1d.d[19]*1;
  residual += temp*temp;
  temp = work1d.KKT[40]-work1d.L[19]*work1d.d[20]*1;
  residual += temp*temp;
  temp = work1d.KKT[42]-work1d.L[20]*work1d.d[21]*1;
  residual += temp*temp;
  temp = work1d.KKT[44]-work1d.L[21]*work1d.d[22]*1;
  residual += temp*temp;
  temp = work1d.KKT[46]-work1d.L[22]*work1d.d[23]*1;
  residual += temp*temp;
  temp = work1d.KKT[48]-work1d.L[23]*work1d.d[24]*1;
  residual += temp*temp;
  temp = work1d.KKT[50]-work1d.L[24]*work1d.d[25]*1;
  residual += temp*temp;
  temp = work1d.KKT[52]-work1d.L[25]*work1d.d[26]*1;
  residual += temp*temp;
  temp = work1d.KKT[54]-work1d.L[26]*work1d.d[27]*1;
  residual += temp*temp;
  temp = work1d.KKT[56]-work1d.L[27]*work1d.d[28]*1;
  residual += temp*temp;
  temp = work1d.KKT[58]-work1d.L[28]*work1d.d[29]*1;
  residual += temp*temp;
  temp = work1d.KKT[60]-work1d.L[29]*work1d.d[30]*1;
  residual += temp*temp;
  temp = work1d.KKT[62]-work1d.L[30]*work1d.d[31]*1;
  residual += temp*temp;
  temp = work1d.KKT[64]-work1d.L[31]*work1d.d[32]*1;
  residual += temp*temp;
  temp = work1d.KKT[66]-work1d.L[32]*work1d.d[33]*1;
  residual += temp*temp;
  temp = work1d.KKT[68]-work1d.L[33]*work1d.d[34]*1;
  residual += temp*temp;
  temp = work1d.KKT[70]-work1d.L[34]*work1d.d[35]*1;
  residual += temp*temp;
  temp = work1d.KKT[72]-work1d.L[35]*work1d.d[36]*1;
  residual += temp*temp;
  temp = work1d.KKT[74]-work1d.L[36]*work1d.d[37]*1;
  residual += temp*temp;
  temp = work1d.KKT[76]-work1d.L[37]*work1d.d[38]*1;
  residual += temp*temp;
  temp = work1d.KKT[78]-work1d.L[38]*work1d.d[39]*1;
  residual += temp*temp;
  temp = work1d.KKT[80]-work1d.L[39]*work1d.d[40]*1;
  residual += temp*temp;
  temp = work1d.KKT[82]-work1d.L[40]*work1d.d[41]*1;
  residual += temp*temp;
  temp = work1d.KKT[84]-work1d.L[41]*work1d.d[42]*1;
  residual += temp*temp;
  temp = work1d.KKT[86]-work1d.L[42]*work1d.d[43]*1;
  residual += temp*temp;
  temp = work1d.KKT[88]-work1d.L[43]*work1d.d[44]*1;
  residual += temp*temp;
  temp = work1d.KKT[90]-work1d.L[44]*work1d.d[45]*1;
  residual += temp*temp;
  temp = work1d.KKT[92]-work1d.L[45]*work1d.d[46]*1;
  residual += temp*temp;
  temp = work1d.KKT[94]-work1d.L[46]*work1d.d[47]*1;
  residual += temp*temp;
  temp = work1d.KKT[96]-work1d.L[47]*work1d.d[48]*1;
  residual += temp*temp;
  temp = work1d.KKT[98]-work1d.L[48]*work1d.d[49]*1;
  residual += temp*temp;
  temp = work1d.KKT[100]-work1d.L[49]*work1d.d[50]*1;
  residual += temp*temp;
  temp = work1d.KKT[102]-work1d.L[50]*work1d.d[51]*1;
  residual += temp*temp;
  temp = work1d.KKT[104]-work1d.L[51]*work1d.d[52]*1;
  residual += temp*temp;
  temp = work1d.KKT[106]-work1d.L[52]*work1d.d[53]*1;
  residual += temp*temp;
  temp = work1d.KKT[108]-work1d.L[53]*work1d.d[54]*1;
  residual += temp*temp;
  temp = work1d.KKT[110]-work1d.L[54]*work1d.d[55]*1;
  residual += temp*temp;
  temp = work1d.KKT[112]-work1d.L[55]*work1d.d[56]*1;
  residual += temp*temp;
  temp = work1d.KKT[114]-work1d.L[56]*work1d.d[57]*1;
  residual += temp*temp;
  temp = work1d.KKT[116]-work1d.L[57]*work1d.d[58]*1;
  residual += temp*temp;
  temp = work1d.KKT[118]-work1d.L[58]*work1d.d[59]*1;
  residual += temp*temp;
  temp = work1d.KKT[120]-work1d.L[59]*work1d.d[60]*1;
  residual += temp*temp;
  temp = work1d.KKT[122]-work1d.L[60]*work1d.d[61]*1;
  residual += temp*temp;
  temp = work1d.KKT[124]-work1d.L[61]*work1d.d[62]*1;
  residual += temp*temp;
  temp = work1d.KKT[126]-work1d.L[62]*work1d.d[63]*1;
  residual += temp*temp;
  temp = work1d.KKT[128]-work1d.L[63]*work1d.d[64]*1;
  residual += temp*temp;
  temp = work1d.KKT[130]-work1d.L[64]*work1d.d[65]*1;
  residual += temp*temp;
  temp = work1d.KKT[132]-work1d.L[65]*work1d.d[66]*1;
  residual += temp*temp;
  temp = work1d.KKT[134]-work1d.L[66]*work1d.d[67]*1;
  residual += temp*temp;
  temp = work1d.KKT[136]-work1d.L[67]*work1d.d[68]*1;
  residual += temp*temp;
  temp = work1d.KKT[138]-work1d.L[68]*work1d.d[69]*1;
  residual += temp*temp;
  temp = work1d.KKT[140]-work1d.L[69]*work1d.d[70]*1;
  residual += temp*temp;
  temp = work1d.KKT[142]-work1d.L[70]*work1d.d[71]*1;
  residual += temp*temp;
  temp = work1d.KKT[144]-work1d.L[71]*work1d.d[72]*1;
  residual += temp*temp;
  temp = work1d.KKT[146]-work1d.L[72]*work1d.d[73]*1;
  residual += temp*temp;
  temp = work1d.KKT[148]-work1d.L[73]*work1d.d[74]*1;
  residual += temp*temp;
  temp = work1d.KKT[150]-work1d.L[74]*work1d.d[75]*1;
  residual += temp*temp;
  temp = work1d.KKT[152]-work1d.L[75]*work1d.d[76]*1;
  residual += temp*temp;
  temp = work1d.KKT[154]-work1d.L[76]*work1d.d[77]*1;
  residual += temp*temp;
  temp = work1d.KKT[156]-work1d.L[77]*work1d.d[78]*1;
  residual += temp*temp;
  temp = work1d.KKT[158]-work1d.L[78]*work1d.d[79]*1;
  residual += temp*temp;
  temp = work1d.KKT[160]-work1d.L[79]*work1d.d[80]*1;
  residual += temp*temp;
  temp = work1d.KKT[162]-work1d.L[80]*work1d.d[81]*1;
  residual += temp*temp;
  temp = work1d.KKT[164]-work1d.L[81]*work1d.d[82]*1;
  residual += temp*temp;
  temp = work1d.KKT[166]-work1d.L[82]*work1d.d[83]*1;
  residual += temp*temp;
  temp = work1d.KKT[168]-work1d.L[83]*work1d.d[84]*1;
  residual += temp*temp;
  temp = work1d.KKT[170]-work1d.L[84]*work1d.d[85]*1;
  residual += temp*temp;
  temp = work1d.KKT[172]-work1d.L[85]*work1d.d[86]*1;
  residual += temp*temp;
  temp = work1d.KKT[174]-work1d.L[86]*work1d.d[87]*1;
  residual += temp*temp;
  temp = work1d.KKT[176]-work1d.L[87]*work1d.d[88]*1;
  residual += temp*temp;
  temp = work1d.KKT[178]-work1d.L[88]*work1d.d[89]*1;
  residual += temp*temp;
  temp = work1d.KKT[180]-work1d.L[89]*work1d.d[90]*1;
  residual += temp*temp;
  temp = work1d.KKT[182]-work1d.L[90]*work1d.d[91]*1;
  residual += temp*temp;
  temp = work1d.KKT[184]-work1d.L[91]*work1d.d[92]*1;
  residual += temp*temp;
  temp = work1d.KKT[186]-work1d.L[92]*work1d.d[93]*1;
  residual += temp*temp;
  temp = work1d.KKT[188]-work1d.L[93]*work1d.d[94]*1;
  residual += temp*temp;
  temp = work1d.KKT[190]-work1d.L[94]*work1d.d[95]*1;
  residual += temp*temp;
  temp = work1d.KKT[192]-work1d.L[95]*work1d.d[96]*1;
  residual += temp*temp;
  temp = work1d.KKT[194]-work1d.L[96]*work1d.d[97]*1;
  residual += temp*temp;
  temp = work1d.KKT[196]-work1d.L[97]*work1d.d[98]*1;
  residual += temp*temp;
  temp = work1d.KKT[198]-work1d.L[98]*work1d.d[99]*1;
  residual += temp*temp;
  temp = work1d.KKT[200]-work1d.L[99]*work1d.d[100]*1;
  residual += temp*temp;
  temp = work1d.KKT[202]-work1d.L[100]*work1d.d[101]*1;
  residual += temp*temp;
  temp = work1d.KKT[204]-work1d.L[101]*work1d.d[102]*1;
  residual += temp*temp;
  temp = work1d.KKT[206]-work1d.L[102]*work1d.d[103]*1;
  residual += temp*temp;
  temp = work1d.KKT[208]-work1d.L[103]*work1d.d[104]*1;
  residual += temp*temp;
  temp = work1d.KKT[210]-work1d.L[104]*work1d.d[105]*1;
  residual += temp*temp;
  temp = work1d.KKT[212]-work1d.L[105]*work1d.d[106]*1;
  residual += temp*temp;
  temp = work1d.KKT[214]-work1d.L[106]*work1d.d[107]*1;
  residual += temp*temp;
  temp = work1d.KKT[216]-work1d.L[107]*work1d.d[108]*1;
  residual += temp*temp;
  temp = work1d.KKT[218]-work1d.L[108]*work1d.d[109]*1;
  residual += temp*temp;
  temp = work1d.KKT[220]-work1d.L[109]*work1d.d[110]*1;
  residual += temp*temp;
  temp = work1d.KKT[222]-work1d.L[110]*work1d.d[111]*1;
  residual += temp*temp;
  temp = work1d.KKT[224]-work1d.L[111]*work1d.d[112]*1;
  residual += temp*temp;
  temp = work1d.KKT[226]-work1d.L[112]*work1d.d[113]*1;
  residual += temp*temp;
  temp = work1d.KKT[228]-work1d.L[113]*work1d.d[114]*1;
  residual += temp*temp;
  temp = work1d.KKT[230]-work1d.L[114]*work1d.d[115]*1;
  residual += temp*temp;
  temp = work1d.KKT[232]-work1d.L[115]*work1d.d[116]*1;
  residual += temp*temp;
  temp = work1d.KKT[234]-work1d.L[116]*work1d.d[117]*1;
  residual += temp*temp;
  temp = work1d.KKT[236]-work1d.L[117]*work1d.d[118]*1;
  residual += temp*temp;
  temp = work1d.KKT[238]-work1d.L[118]*work1d.d[119]*1;
  residual += temp*temp;
  temp = work1d.KKT[240]-work1d.L[119]*work1d.d[120]*1;
  residual += temp*temp;
  temp = work1d.KKT[242]-work1d.L[120]*work1d.d[121]*1;
  residual += temp*temp;
  temp = work1d.KKT[244]-work1d.L[121]*work1d.d[122]*1;
  residual += temp*temp;
  temp = work1d.KKT[246]-work1d.L[122]*work1d.d[123]*1;
  residual += temp*temp;
  temp = work1d.KKT[248]-work1d.L[123]*work1d.d[124]*1;
  residual += temp*temp;
  temp = work1d.KKT[250]-work1d.L[124]*work1d.d[125]*1;
  residual += temp*temp;
  temp = work1d.KKT[252]-work1d.L[125]*work1d.d[126]*1;
  residual += temp*temp;
  temp = work1d.KKT[254]-work1d.L[126]*work1d.d[127]*1;
  residual += temp*temp;
  temp = work1d.KKT[256]-work1d.L[127]*work1d.d[128]*1;
  residual += temp*temp;
  temp = work1d.KKT[258]-work1d.L[128]*work1d.d[129]*1;
  residual += temp*temp;
  temp = work1d.KKT[260]-work1d.L[129]*work1d.d[130]*1;
  residual += temp*temp;
  temp = work1d.KKT[262]-work1d.L[130]*work1d.d[131]*1;
  residual += temp*temp;
  temp = work1d.KKT[264]-work1d.L[131]*work1d.d[132]*1;
  residual += temp*temp;
  temp = work1d.KKT[266]-work1d.L[132]*work1d.d[133]*1;
  residual += temp*temp;
  temp = work1d.KKT[268]-work1d.L[133]*work1d.d[134]*1;
  residual += temp*temp;
  temp = work1d.KKT[270]-work1d.L[134]*work1d.d[135]*1;
  residual += temp*temp;
  temp = work1d.KKT[272]-work1d.L[135]*work1d.d[136]*1;
  residual += temp*temp;
  temp = work1d.KKT[274]-work1d.L[136]*work1d.d[137]*1;
  residual += temp*temp;
  temp = work1d.KKT[276]-work1d.L[137]*work1d.d[138]*1;
  residual += temp*temp;
  temp = work1d.KKT[278]-work1d.L[138]*work1d.d[139]*1;
  residual += temp*temp;
  temp = work1d.KKT[280]-work1d.L[139]*work1d.d[140]*1;
  residual += temp*temp;
  temp = work1d.KKT[282]-work1d.L[140]*work1d.d[141]*1;
  residual += temp*temp;
  temp = work1d.KKT[284]-work1d.L[141]*work1d.d[142]*1;
  residual += temp*temp;
  temp = work1d.KKT[286]-work1d.L[142]*work1d.d[143]*1;
  residual += temp*temp;
  temp = work1d.KKT[288]-work1d.L[143]*work1d.d[144]*1;
  residual += temp*temp;
  temp = work1d.KKT[290]-work1d.L[144]*work1d.d[145]*1;
  residual += temp*temp;
  temp = work1d.KKT[292]-work1d.L[145]*work1d.d[146]*1;
  residual += temp*temp;
  temp = work1d.KKT[294]-work1d.L[146]*work1d.d[147]*1;
  residual += temp*temp;
  temp = work1d.KKT[296]-work1d.L[147]*work1d.d[148]*1;
  residual += temp*temp;
  temp = work1d.KKT[298]-work1d.L[148]*work1d.d[149]*1;
  residual += temp*temp;
  temp = work1d.KKT[300]-work1d.L[149]*work1d.d[150]*1;
  residual += temp*temp;
  temp = work1d.KKT[302]-work1d.L[150]*work1d.d[151]*1;
  residual += temp*temp;
  temp = work1d.KKT[304]-work1d.L[151]*work1d.d[152]*1;
  residual += temp*temp;
  temp = work1d.KKT[306]-work1d.L[152]*work1d.d[153]*1;
  residual += temp*temp;
  temp = work1d.KKT[308]-work1d.L[153]*work1d.d[154]*1;
  residual += temp*temp;
  temp = work1d.KKT[310]-work1d.L[154]*work1d.d[155]*1;
  residual += temp*temp;
  temp = work1d.KKT[312]-work1d.L[155]*work1d.d[156]*1;
  residual += temp*temp;
  temp = work1d.KKT[314]-work1d.L[156]*work1d.d[157]*1;
  residual += temp*temp;
  temp = work1d.KKT[316]-work1d.L[157]*work1d.d[158]*1;
  residual += temp*temp;
  temp = work1d.KKT[318]-work1d.L[158]*work1d.d[159]*1;
  residual += temp*temp;
  temp = work1d.KKT[320]-work1d.L[159]*work1d.d[160]*1;
  residual += temp*temp;
  temp = work1d.KKT[321]-work1d.L[0]*work1d.d[1]*work1d.L[0]-1*work1d.d[161]*1;
  residual += temp*temp;
  temp = work1d.KKT[323]-work1d.L[1]*work1d.d[2]*work1d.L[1]-1*work1d.d[162]*1;
  residual += temp*temp;
  temp = work1d.KKT[325]-work1d.L[2]*work1d.d[3]*work1d.L[2]-1*work1d.d[163]*1;
  residual += temp*temp;
  temp = work1d.KKT[327]-work1d.L[3]*work1d.d[4]*work1d.L[3]-1*work1d.d[164]*1;
  residual += temp*temp;
  temp = work1d.KKT[329]-work1d.L[4]*work1d.d[5]*work1d.L[4]-1*work1d.d[165]*1;
  residual += temp*temp;
  temp = work1d.KKT[331]-work1d.L[5]*work1d.d[6]*work1d.L[5]-1*work1d.d[166]*1;
  residual += temp*temp;
  temp = work1d.KKT[333]-work1d.L[6]*work1d.d[7]*work1d.L[6]-1*work1d.d[167]*1;
  residual += temp*temp;
  temp = work1d.KKT[335]-work1d.L[7]*work1d.d[8]*work1d.L[7]-1*work1d.d[168]*1;
  residual += temp*temp;
  temp = work1d.KKT[337]-work1d.L[8]*work1d.d[9]*work1d.L[8]-1*work1d.d[169]*1;
  residual += temp*temp;
  temp = work1d.KKT[339]-work1d.L[9]*work1d.d[10]*work1d.L[9]-1*work1d.d[170]*1;
  residual += temp*temp;
  temp = work1d.KKT[341]-work1d.L[10]*work1d.d[11]*work1d.L[10]-1*work1d.d[171]*1;
  residual += temp*temp;
  temp = work1d.KKT[343]-work1d.L[11]*work1d.d[12]*work1d.L[11]-1*work1d.d[172]*1;
  residual += temp*temp;
  temp = work1d.KKT[345]-work1d.L[12]*work1d.d[13]*work1d.L[12]-1*work1d.d[173]*1;
  residual += temp*temp;
  temp = work1d.KKT[347]-work1d.L[13]*work1d.d[14]*work1d.L[13]-1*work1d.d[174]*1;
  residual += temp*temp;
  temp = work1d.KKT[349]-work1d.L[14]*work1d.d[15]*work1d.L[14]-1*work1d.d[175]*1;
  residual += temp*temp;
  temp = work1d.KKT[351]-work1d.L[15]*work1d.d[16]*work1d.L[15]-1*work1d.d[176]*1;
  residual += temp*temp;
  temp = work1d.KKT[353]-work1d.L[16]*work1d.d[17]*work1d.L[16]-1*work1d.d[177]*1;
  residual += temp*temp;
  temp = work1d.KKT[355]-work1d.L[17]*work1d.d[18]*work1d.L[17]-1*work1d.d[178]*1;
  residual += temp*temp;
  temp = work1d.KKT[357]-work1d.L[18]*work1d.d[19]*work1d.L[18]-1*work1d.d[179]*1;
  residual += temp*temp;
  temp = work1d.KKT[359]-work1d.L[19]*work1d.d[20]*work1d.L[19]-1*work1d.d[180]*1;
  residual += temp*temp;
  temp = work1d.KKT[361]-work1d.L[20]*work1d.d[21]*work1d.L[20]-1*work1d.d[181]*1;
  residual += temp*temp;
  temp = work1d.KKT[363]-work1d.L[21]*work1d.d[22]*work1d.L[21]-1*work1d.d[182]*1;
  residual += temp*temp;
  temp = work1d.KKT[365]-work1d.L[22]*work1d.d[23]*work1d.L[22]-1*work1d.d[183]*1;
  residual += temp*temp;
  temp = work1d.KKT[367]-work1d.L[23]*work1d.d[24]*work1d.L[23]-1*work1d.d[184]*1;
  residual += temp*temp;
  temp = work1d.KKT[369]-work1d.L[24]*work1d.d[25]*work1d.L[24]-1*work1d.d[185]*1;
  residual += temp*temp;
  temp = work1d.KKT[371]-work1d.L[25]*work1d.d[26]*work1d.L[25]-1*work1d.d[186]*1;
  residual += temp*temp;
  temp = work1d.KKT[373]-work1d.L[26]*work1d.d[27]*work1d.L[26]-1*work1d.d[187]*1;
  residual += temp*temp;
  temp = work1d.KKT[375]-work1d.L[27]*work1d.d[28]*work1d.L[27]-1*work1d.d[188]*1;
  residual += temp*temp;
  temp = work1d.KKT[377]-work1d.L[28]*work1d.d[29]*work1d.L[28]-1*work1d.d[189]*1;
  residual += temp*temp;
  temp = work1d.KKT[379]-work1d.L[29]*work1d.d[30]*work1d.L[29]-1*work1d.d[190]*1;
  residual += temp*temp;
  temp = work1d.KKT[381]-work1d.L[30]*work1d.d[31]*work1d.L[30]-1*work1d.d[191]*1;
  residual += temp*temp;
  temp = work1d.KKT[383]-work1d.L[31]*work1d.d[32]*work1d.L[31]-1*work1d.d[192]*1;
  residual += temp*temp;
  temp = work1d.KKT[385]-work1d.L[32]*work1d.d[33]*work1d.L[32]-1*work1d.d[193]*1;
  residual += temp*temp;
  temp = work1d.KKT[387]-work1d.L[33]*work1d.d[34]*work1d.L[33]-1*work1d.d[194]*1;
  residual += temp*temp;
  temp = work1d.KKT[389]-work1d.L[34]*work1d.d[35]*work1d.L[34]-1*work1d.d[195]*1;
  residual += temp*temp;
  temp = work1d.KKT[391]-work1d.L[35]*work1d.d[36]*work1d.L[35]-1*work1d.d[196]*1;
  residual += temp*temp;
  temp = work1d.KKT[393]-work1d.L[36]*work1d.d[37]*work1d.L[36]-1*work1d.d[197]*1;
  residual += temp*temp;
  temp = work1d.KKT[395]-work1d.L[37]*work1d.d[38]*work1d.L[37]-1*work1d.d[198]*1;
  residual += temp*temp;
  temp = work1d.KKT[397]-work1d.L[38]*work1d.d[39]*work1d.L[38]-1*work1d.d[199]*1;
  residual += temp*temp;
  temp = work1d.KKT[399]-work1d.L[39]*work1d.d[40]*work1d.L[39]-1*work1d.d[200]*1;
  residual += temp*temp;
  temp = work1d.KKT[401]-work1d.L[40]*work1d.d[41]*work1d.L[40]-1*work1d.d[201]*1;
  residual += temp*temp;
  temp = work1d.KKT[403]-work1d.L[41]*work1d.d[42]*work1d.L[41]-1*work1d.d[202]*1;
  residual += temp*temp;
  temp = work1d.KKT[405]-work1d.L[42]*work1d.d[43]*work1d.L[42]-1*work1d.d[203]*1;
  residual += temp*temp;
  temp = work1d.KKT[407]-work1d.L[43]*work1d.d[44]*work1d.L[43]-1*work1d.d[204]*1;
  residual += temp*temp;
  temp = work1d.KKT[409]-work1d.L[44]*work1d.d[45]*work1d.L[44]-1*work1d.d[205]*1;
  residual += temp*temp;
  temp = work1d.KKT[411]-work1d.L[45]*work1d.d[46]*work1d.L[45]-1*work1d.d[206]*1;
  residual += temp*temp;
  temp = work1d.KKT[413]-work1d.L[46]*work1d.d[47]*work1d.L[46]-1*work1d.d[207]*1;
  residual += temp*temp;
  temp = work1d.KKT[415]-work1d.L[47]*work1d.d[48]*work1d.L[47]-1*work1d.d[208]*1;
  residual += temp*temp;
  temp = work1d.KKT[417]-work1d.L[48]*work1d.d[49]*work1d.L[48]-1*work1d.d[209]*1;
  residual += temp*temp;
  temp = work1d.KKT[419]-work1d.L[49]*work1d.d[50]*work1d.L[49]-1*work1d.d[210]*1;
  residual += temp*temp;
  temp = work1d.KKT[421]-work1d.L[50]*work1d.d[51]*work1d.L[50]-1*work1d.d[211]*1;
  residual += temp*temp;
  temp = work1d.KKT[423]-work1d.L[51]*work1d.d[52]*work1d.L[51]-1*work1d.d[212]*1;
  residual += temp*temp;
  temp = work1d.KKT[425]-work1d.L[52]*work1d.d[53]*work1d.L[52]-1*work1d.d[213]*1;
  residual += temp*temp;
  temp = work1d.KKT[427]-work1d.L[53]*work1d.d[54]*work1d.L[53]-1*work1d.d[214]*1;
  residual += temp*temp;
  temp = work1d.KKT[429]-work1d.L[54]*work1d.d[55]*work1d.L[54]-1*work1d.d[215]*1;
  residual += temp*temp;
  temp = work1d.KKT[431]-work1d.L[55]*work1d.d[56]*work1d.L[55]-1*work1d.d[216]*1;
  residual += temp*temp;
  temp = work1d.KKT[433]-work1d.L[56]*work1d.d[57]*work1d.L[56]-1*work1d.d[217]*1;
  residual += temp*temp;
  temp = work1d.KKT[435]-work1d.L[57]*work1d.d[58]*work1d.L[57]-1*work1d.d[218]*1;
  residual += temp*temp;
  temp = work1d.KKT[437]-work1d.L[58]*work1d.d[59]*work1d.L[58]-1*work1d.d[219]*1;
  residual += temp*temp;
  temp = work1d.KKT[439]-work1d.L[59]*work1d.d[60]*work1d.L[59]-1*work1d.d[220]*1;
  residual += temp*temp;
  temp = work1d.KKT[441]-work1d.L[60]*work1d.d[61]*work1d.L[60]-1*work1d.d[221]*1;
  residual += temp*temp;
  temp = work1d.KKT[443]-work1d.L[61]*work1d.d[62]*work1d.L[61]-1*work1d.d[222]*1;
  residual += temp*temp;
  temp = work1d.KKT[445]-work1d.L[62]*work1d.d[63]*work1d.L[62]-1*work1d.d[223]*1;
  residual += temp*temp;
  temp = work1d.KKT[447]-work1d.L[63]*work1d.d[64]*work1d.L[63]-1*work1d.d[224]*1;
  residual += temp*temp;
  temp = work1d.KKT[449]-work1d.L[64]*work1d.d[65]*work1d.L[64]-1*work1d.d[225]*1;
  residual += temp*temp;
  temp = work1d.KKT[451]-work1d.L[65]*work1d.d[66]*work1d.L[65]-1*work1d.d[226]*1;
  residual += temp*temp;
  temp = work1d.KKT[453]-work1d.L[66]*work1d.d[67]*work1d.L[66]-1*work1d.d[227]*1;
  residual += temp*temp;
  temp = work1d.KKT[455]-work1d.L[67]*work1d.d[68]*work1d.L[67]-1*work1d.d[228]*1;
  residual += temp*temp;
  temp = work1d.KKT[457]-work1d.L[68]*work1d.d[69]*work1d.L[68]-1*work1d.d[229]*1;
  residual += temp*temp;
  temp = work1d.KKT[459]-work1d.L[69]*work1d.d[70]*work1d.L[69]-1*work1d.d[230]*1;
  residual += temp*temp;
  temp = work1d.KKT[461]-work1d.L[70]*work1d.d[71]*work1d.L[70]-1*work1d.d[231]*1;
  residual += temp*temp;
  temp = work1d.KKT[463]-work1d.L[71]*work1d.d[72]*work1d.L[71]-1*work1d.d[232]*1;
  residual += temp*temp;
  temp = work1d.KKT[465]-work1d.L[72]*work1d.d[73]*work1d.L[72]-1*work1d.d[233]*1;
  residual += temp*temp;
  temp = work1d.KKT[467]-work1d.L[73]*work1d.d[74]*work1d.L[73]-1*work1d.d[234]*1;
  residual += temp*temp;
  temp = work1d.KKT[469]-work1d.L[74]*work1d.d[75]*work1d.L[74]-1*work1d.d[235]*1;
  residual += temp*temp;
  temp = work1d.KKT[471]-work1d.L[75]*work1d.d[76]*work1d.L[75]-1*work1d.d[236]*1;
  residual += temp*temp;
  temp = work1d.KKT[473]-work1d.L[76]*work1d.d[77]*work1d.L[76]-1*work1d.d[237]*1;
  residual += temp*temp;
  temp = work1d.KKT[475]-work1d.L[77]*work1d.d[78]*work1d.L[77]-1*work1d.d[238]*1;
  residual += temp*temp;
  temp = work1d.KKT[477]-work1d.L[78]*work1d.d[79]*work1d.L[78]-1*work1d.d[239]*1;
  residual += temp*temp;
  temp = work1d.KKT[479]-work1d.L[79]*work1d.d[80]*work1d.L[79]-1*work1d.d[240]*1;
  residual += temp*temp;
  temp = work1d.KKT[481]-work1d.L[80]*work1d.d[81]*work1d.L[80]-1*work1d.d[241]*1;
  residual += temp*temp;
  temp = work1d.KKT[483]-work1d.L[81]*work1d.d[82]*work1d.L[81]-1*work1d.d[242]*1;
  residual += temp*temp;
  temp = work1d.KKT[485]-work1d.L[82]*work1d.d[83]*work1d.L[82]-1*work1d.d[243]*1;
  residual += temp*temp;
  temp = work1d.KKT[487]-work1d.L[83]*work1d.d[84]*work1d.L[83]-1*work1d.d[244]*1;
  residual += temp*temp;
  temp = work1d.KKT[489]-work1d.L[84]*work1d.d[85]*work1d.L[84]-1*work1d.d[245]*1;
  residual += temp*temp;
  temp = work1d.KKT[491]-work1d.L[85]*work1d.d[86]*work1d.L[85]-1*work1d.d[246]*1;
  residual += temp*temp;
  temp = work1d.KKT[493]-work1d.L[86]*work1d.d[87]*work1d.L[86]-1*work1d.d[247]*1;
  residual += temp*temp;
  temp = work1d.KKT[495]-work1d.L[87]*work1d.d[88]*work1d.L[87]-1*work1d.d[248]*1;
  residual += temp*temp;
  temp = work1d.KKT[497]-work1d.L[88]*work1d.d[89]*work1d.L[88]-1*work1d.d[249]*1;
  residual += temp*temp;
  temp = work1d.KKT[499]-work1d.L[89]*work1d.d[90]*work1d.L[89]-1*work1d.d[250]*1;
  residual += temp*temp;
  temp = work1d.KKT[501]-work1d.L[90]*work1d.d[91]*work1d.L[90]-1*work1d.d[251]*1;
  residual += temp*temp;
  temp = work1d.KKT[503]-work1d.L[91]*work1d.d[92]*work1d.L[91]-1*work1d.d[252]*1;
  residual += temp*temp;
  temp = work1d.KKT[505]-work1d.L[92]*work1d.d[93]*work1d.L[92]-1*work1d.d[253]*1;
  residual += temp*temp;
  temp = work1d.KKT[507]-work1d.L[93]*work1d.d[94]*work1d.L[93]-1*work1d.d[254]*1;
  residual += temp*temp;
  temp = work1d.KKT[509]-work1d.L[94]*work1d.d[95]*work1d.L[94]-1*work1d.d[255]*1;
  residual += temp*temp;
  temp = work1d.KKT[511]-work1d.L[95]*work1d.d[96]*work1d.L[95]-1*work1d.d[256]*1;
  residual += temp*temp;
  temp = work1d.KKT[513]-work1d.L[96]*work1d.d[97]*work1d.L[96]-1*work1d.d[257]*1;
  residual += temp*temp;
  temp = work1d.KKT[515]-work1d.L[97]*work1d.d[98]*work1d.L[97]-1*work1d.d[258]*1;
  residual += temp*temp;
  temp = work1d.KKT[517]-work1d.L[98]*work1d.d[99]*work1d.L[98]-1*work1d.d[259]*1;
  residual += temp*temp;
  temp = work1d.KKT[519]-work1d.L[99]*work1d.d[100]*work1d.L[99]-1*work1d.d[260]*1;
  residual += temp*temp;
  temp = work1d.KKT[521]-work1d.L[100]*work1d.d[101]*work1d.L[100]-1*work1d.d[261]*1;
  residual += temp*temp;
  temp = work1d.KKT[523]-work1d.L[101]*work1d.d[102]*work1d.L[101]-1*work1d.d[262]*1;
  residual += temp*temp;
  temp = work1d.KKT[525]-work1d.L[102]*work1d.d[103]*work1d.L[102]-1*work1d.d[263]*1;
  residual += temp*temp;
  temp = work1d.KKT[527]-work1d.L[103]*work1d.d[104]*work1d.L[103]-1*work1d.d[264]*1;
  residual += temp*temp;
  temp = work1d.KKT[529]-work1d.L[104]*work1d.d[105]*work1d.L[104]-1*work1d.d[265]*1;
  residual += temp*temp;
  temp = work1d.KKT[531]-work1d.L[105]*work1d.d[106]*work1d.L[105]-1*work1d.d[266]*1;
  residual += temp*temp;
  temp = work1d.KKT[533]-work1d.L[106]*work1d.d[107]*work1d.L[106]-1*work1d.d[267]*1;
  residual += temp*temp;
  temp = work1d.KKT[535]-work1d.L[107]*work1d.d[108]*work1d.L[107]-1*work1d.d[268]*1;
  residual += temp*temp;
  temp = work1d.KKT[537]-work1d.L[108]*work1d.d[109]*work1d.L[108]-1*work1d.d[269]*1;
  residual += temp*temp;
  temp = work1d.KKT[539]-work1d.L[109]*work1d.d[110]*work1d.L[109]-1*work1d.d[270]*1;
  residual += temp*temp;
  temp = work1d.KKT[541]-work1d.L[110]*work1d.d[111]*work1d.L[110]-1*work1d.d[271]*1;
  residual += temp*temp;
  temp = work1d.KKT[543]-work1d.L[111]*work1d.d[112]*work1d.L[111]-1*work1d.d[272]*1;
  residual += temp*temp;
  temp = work1d.KKT[545]-work1d.L[112]*work1d.d[113]*work1d.L[112]-1*work1d.d[273]*1;
  residual += temp*temp;
  temp = work1d.KKT[547]-work1d.L[113]*work1d.d[114]*work1d.L[113]-1*work1d.d[274]*1;
  residual += temp*temp;
  temp = work1d.KKT[549]-work1d.L[114]*work1d.d[115]*work1d.L[114]-1*work1d.d[275]*1;
  residual += temp*temp;
  temp = work1d.KKT[551]-work1d.L[115]*work1d.d[116]*work1d.L[115]-1*work1d.d[276]*1;
  residual += temp*temp;
  temp = work1d.KKT[553]-work1d.L[116]*work1d.d[117]*work1d.L[116]-1*work1d.d[277]*1;
  residual += temp*temp;
  temp = work1d.KKT[555]-work1d.L[117]*work1d.d[118]*work1d.L[117]-1*work1d.d[278]*1;
  residual += temp*temp;
  temp = work1d.KKT[557]-work1d.L[118]*work1d.d[119]*work1d.L[118]-1*work1d.d[279]*1;
  residual += temp*temp;
  temp = work1d.KKT[559]-work1d.L[119]*work1d.d[120]*work1d.L[119]-1*work1d.d[280]*1;
  residual += temp*temp;
  temp = work1d.KKT[561]-work1d.L[120]*work1d.d[121]*work1d.L[120]-1*work1d.d[281]*1;
  residual += temp*temp;
  temp = work1d.KKT[563]-work1d.L[121]*work1d.d[122]*work1d.L[121]-1*work1d.d[282]*1;
  residual += temp*temp;
  temp = work1d.KKT[565]-work1d.L[122]*work1d.d[123]*work1d.L[122]-1*work1d.d[283]*1;
  residual += temp*temp;
  temp = work1d.KKT[567]-work1d.L[123]*work1d.d[124]*work1d.L[123]-1*work1d.d[284]*1;
  residual += temp*temp;
  temp = work1d.KKT[569]-work1d.L[124]*work1d.d[125]*work1d.L[124]-1*work1d.d[285]*1;
  residual += temp*temp;
  temp = work1d.KKT[571]-work1d.L[125]*work1d.d[126]*work1d.L[125]-1*work1d.d[286]*1;
  residual += temp*temp;
  temp = work1d.KKT[573]-work1d.L[126]*work1d.d[127]*work1d.L[126]-1*work1d.d[287]*1;
  residual += temp*temp;
  temp = work1d.KKT[575]-work1d.L[127]*work1d.d[128]*work1d.L[127]-1*work1d.d[288]*1;
  residual += temp*temp;
  temp = work1d.KKT[577]-work1d.L[128]*work1d.d[129]*work1d.L[128]-1*work1d.d[289]*1;
  residual += temp*temp;
  temp = work1d.KKT[579]-work1d.L[129]*work1d.d[130]*work1d.L[129]-1*work1d.d[290]*1;
  residual += temp*temp;
  temp = work1d.KKT[581]-work1d.L[130]*work1d.d[131]*work1d.L[130]-1*work1d.d[291]*1;
  residual += temp*temp;
  temp = work1d.KKT[583]-work1d.L[131]*work1d.d[132]*work1d.L[131]-1*work1d.d[292]*1;
  residual += temp*temp;
  temp = work1d.KKT[585]-work1d.L[132]*work1d.d[133]*work1d.L[132]-1*work1d.d[293]*1;
  residual += temp*temp;
  temp = work1d.KKT[587]-work1d.L[133]*work1d.d[134]*work1d.L[133]-1*work1d.d[294]*1;
  residual += temp*temp;
  temp = work1d.KKT[589]-work1d.L[134]*work1d.d[135]*work1d.L[134]-1*work1d.d[295]*1;
  residual += temp*temp;
  temp = work1d.KKT[591]-work1d.L[135]*work1d.d[136]*work1d.L[135]-1*work1d.d[296]*1;
  residual += temp*temp;
  temp = work1d.KKT[593]-work1d.L[136]*work1d.d[137]*work1d.L[136]-1*work1d.d[297]*1;
  residual += temp*temp;
  temp = work1d.KKT[595]-work1d.L[137]*work1d.d[138]*work1d.L[137]-1*work1d.d[298]*1;
  residual += temp*temp;
  temp = work1d.KKT[597]-work1d.L[138]*work1d.d[139]*work1d.L[138]-1*work1d.d[299]*1;
  residual += temp*temp;
  temp = work1d.KKT[599]-work1d.L[139]*work1d.d[140]*work1d.L[139]-1*work1d.d[300]*1;
  residual += temp*temp;
  temp = work1d.KKT[601]-work1d.L[140]*work1d.d[141]*work1d.L[140]-1*work1d.d[301]*1;
  residual += temp*temp;
  temp = work1d.KKT[603]-work1d.L[141]*work1d.d[142]*work1d.L[141]-1*work1d.d[302]*1;
  residual += temp*temp;
  temp = work1d.KKT[605]-work1d.L[142]*work1d.d[143]*work1d.L[142]-1*work1d.d[303]*1;
  residual += temp*temp;
  temp = work1d.KKT[607]-work1d.L[143]*work1d.d[144]*work1d.L[143]-1*work1d.d[304]*1;
  residual += temp*temp;
  temp = work1d.KKT[609]-work1d.L[144]*work1d.d[145]*work1d.L[144]-1*work1d.d[305]*1;
  residual += temp*temp;
  temp = work1d.KKT[611]-work1d.L[145]*work1d.d[146]*work1d.L[145]-1*work1d.d[306]*1;
  residual += temp*temp;
  temp = work1d.KKT[613]-work1d.L[146]*work1d.d[147]*work1d.L[146]-1*work1d.d[307]*1;
  residual += temp*temp;
  temp = work1d.KKT[615]-work1d.L[147]*work1d.d[148]*work1d.L[147]-1*work1d.d[308]*1;
  residual += temp*temp;
  temp = work1d.KKT[617]-work1d.L[148]*work1d.d[149]*work1d.L[148]-1*work1d.d[309]*1;
  residual += temp*temp;
  temp = work1d.KKT[619]-work1d.L[149]*work1d.d[150]*work1d.L[149]-1*work1d.d[310]*1;
  residual += temp*temp;
  temp = work1d.KKT[621]-work1d.L[150]*work1d.d[151]*work1d.L[150]-1*work1d.d[311]*1;
  residual += temp*temp;
  temp = work1d.KKT[623]-work1d.L[151]*work1d.d[152]*work1d.L[151]-1*work1d.d[312]*1;
  residual += temp*temp;
  temp = work1d.KKT[625]-work1d.L[152]*work1d.d[153]*work1d.L[152]-1*work1d.d[313]*1;
  residual += temp*temp;
  temp = work1d.KKT[627]-work1d.L[153]*work1d.d[154]*work1d.L[153]-1*work1d.d[314]*1;
  residual += temp*temp;
  temp = work1d.KKT[629]-work1d.L[154]*work1d.d[155]*work1d.L[154]-1*work1d.d[315]*1;
  residual += temp*temp;
  temp = work1d.KKT[631]-work1d.L[155]*work1d.d[156]*work1d.L[155]-1*work1d.d[316]*1;
  residual += temp*temp;
  temp = work1d.KKT[633]-work1d.L[156]*work1d.d[157]*work1d.L[156]-1*work1d.d[317]*1;
  residual += temp*temp;
  temp = work1d.KKT[635]-work1d.L[157]*work1d.d[158]*work1d.L[157]-1*work1d.d[318]*1;
  residual += temp*temp;
  temp = work1d.KKT[637]-work1d.L[158]*work1d.d[159]*work1d.L[158]-1*work1d.d[319]*1;
  residual += temp*temp;
  temp = work1d.KKT[639]-work1d.L[159]*work1d.d[160]*work1d.L[159]-1*work1d.d[320]*1;
  residual += temp*temp;
  temp = work1d.KKT[322]-1*work1d.d[161]*work1d.L[215];
  residual += temp*temp;
  temp = work1d.KKT[324]-1*work1d.d[162]*work1d.L[229];
  residual += temp*temp;
  temp = work1d.KKT[326]-1*work1d.d[163]*work1d.L[247];
  residual += temp*temp;
  temp = work1d.KKT[328]-1*work1d.d[164]*work1d.L[267];
  residual += temp*temp;
  temp = work1d.KKT[330]-1*work1d.d[165]*work1d.L[287];
  residual += temp*temp;
  temp = work1d.KKT[332]-1*work1d.d[166]*work1d.L[307];
  residual += temp*temp;
  temp = work1d.KKT[334]-1*work1d.d[167]*work1d.L[327];
  residual += temp*temp;
  temp = work1d.KKT[336]-1*work1d.d[168]*work1d.L[347];
  residual += temp*temp;
  temp = work1d.KKT[338]-1*work1d.d[169]*work1d.L[367];
  residual += temp*temp;
  temp = work1d.KKT[340]-1*work1d.d[170]*work1d.L[387];
  residual += temp*temp;
  temp = work1d.KKT[342]-1*work1d.d[171]*work1d.L[407];
  residual += temp*temp;
  temp = work1d.KKT[344]-1*work1d.d[172]*work1d.L[427];
  residual += temp*temp;
  temp = work1d.KKT[346]-1*work1d.d[173]*work1d.L[447];
  residual += temp*temp;
  temp = work1d.KKT[348]-1*work1d.d[174]*work1d.L[467];
  residual += temp*temp;
  temp = work1d.KKT[350]-1*work1d.d[175]*work1d.L[487];
  residual += temp*temp;
  temp = work1d.KKT[352]-1*work1d.d[176]*work1d.L[507];
  residual += temp*temp;
  temp = work1d.KKT[354]-1*work1d.d[177]*work1d.L[527];
  residual += temp*temp;
  temp = work1d.KKT[356]-1*work1d.d[178]*work1d.L[547];
  residual += temp*temp;
  temp = work1d.KKT[358]-1*work1d.d[179]*work1d.L[567];
  residual += temp*temp;
  temp = work1d.KKT[360]-1*work1d.d[180]*work1d.L[587];
  residual += temp*temp;
  temp = work1d.KKT[362]-1*work1d.d[181]*work1d.L[607];
  residual += temp*temp;
  temp = work1d.KKT[364]-1*work1d.d[182]*work1d.L[627];
  residual += temp*temp;
  temp = work1d.KKT[366]-1*work1d.d[183]*work1d.L[647];
  residual += temp*temp;
  temp = work1d.KKT[368]-1*work1d.d[184]*work1d.L[667];
  residual += temp*temp;
  temp = work1d.KKT[370]-1*work1d.d[185]*work1d.L[687];
  residual += temp*temp;
  temp = work1d.KKT[372]-1*work1d.d[186]*work1d.L[707];
  residual += temp*temp;
  temp = work1d.KKT[374]-1*work1d.d[187]*work1d.L[727];
  residual += temp*temp;
  temp = work1d.KKT[376]-1*work1d.d[188]*work1d.L[747];
  residual += temp*temp;
  temp = work1d.KKT[378]-1*work1d.d[189]*work1d.L[767];
  residual += temp*temp;
  temp = work1d.KKT[380]-1*work1d.d[190]*work1d.L[787];
  residual += temp*temp;
  temp = work1d.KKT[382]-1*work1d.d[191]*work1d.L[807];
  residual += temp*temp;
  temp = work1d.KKT[384]-1*work1d.d[192]*work1d.L[827];
  residual += temp*temp;
  temp = work1d.KKT[386]-1*work1d.d[193]*work1d.L[847];
  residual += temp*temp;
  temp = work1d.KKT[388]-1*work1d.d[194]*work1d.L[867];
  residual += temp*temp;
  temp = work1d.KKT[390]-1*work1d.d[195]*work1d.L[887];
  residual += temp*temp;
  temp = work1d.KKT[392]-1*work1d.d[196]*work1d.L[907];
  residual += temp*temp;
  temp = work1d.KKT[394]-1*work1d.d[197]*work1d.L[927];
  residual += temp*temp;
  temp = work1d.KKT[396]-1*work1d.d[198]*work1d.L[951];
  residual += temp*temp;
  temp = work1d.KKT[398]-1*work1d.d[199]*work1d.L[967];
  residual += temp*temp;
  temp = work1d.KKT[400]-1*work1d.d[200]*work1d.L[166];
  residual += temp*temp;
  temp = work1d.KKT[402]-1*work1d.d[201]*work1d.L[219];
  residual += temp*temp;
  temp = work1d.KKT[404]-1*work1d.d[202]*work1d.L[232];
  residual += temp*temp;
  temp = work1d.KKT[406]-1*work1d.d[203]*work1d.L[250];
  residual += temp*temp;
  temp = work1d.KKT[408]-1*work1d.d[204]*work1d.L[270];
  residual += temp*temp;
  temp = work1d.KKT[410]-1*work1d.d[205]*work1d.L[290];
  residual += temp*temp;
  temp = work1d.KKT[412]-1*work1d.d[206]*work1d.L[310];
  residual += temp*temp;
  temp = work1d.KKT[414]-1*work1d.d[207]*work1d.L[330];
  residual += temp*temp;
  temp = work1d.KKT[416]-1*work1d.d[208]*work1d.L[350];
  residual += temp*temp;
  temp = work1d.KKT[418]-1*work1d.d[209]*work1d.L[370];
  residual += temp*temp;
  temp = work1d.KKT[420]-1*work1d.d[210]*work1d.L[390];
  residual += temp*temp;
  temp = work1d.KKT[422]-1*work1d.d[211]*work1d.L[410];
  residual += temp*temp;
  temp = work1d.KKT[424]-1*work1d.d[212]*work1d.L[430];
  residual += temp*temp;
  temp = work1d.KKT[426]-1*work1d.d[213]*work1d.L[450];
  residual += temp*temp;
  temp = work1d.KKT[428]-1*work1d.d[214]*work1d.L[470];
  residual += temp*temp;
  temp = work1d.KKT[430]-1*work1d.d[215]*work1d.L[490];
  residual += temp*temp;
  temp = work1d.KKT[432]-1*work1d.d[216]*work1d.L[510];
  residual += temp*temp;
  temp = work1d.KKT[434]-1*work1d.d[217]*work1d.L[530];
  residual += temp*temp;
  temp = work1d.KKT[436]-1*work1d.d[218]*work1d.L[550];
  residual += temp*temp;
  temp = work1d.KKT[438]-1*work1d.d[219]*work1d.L[570];
  residual += temp*temp;
  temp = work1d.KKT[440]-1*work1d.d[220]*work1d.L[590];
  residual += temp*temp;
  temp = work1d.KKT[442]-1*work1d.d[221]*work1d.L[610];
  residual += temp*temp;
  temp = work1d.KKT[444]-1*work1d.d[222]*work1d.L[630];
  residual += temp*temp;
  temp = work1d.KKT[446]-1*work1d.d[223]*work1d.L[650];
  residual += temp*temp;
  temp = work1d.KKT[448]-1*work1d.d[224]*work1d.L[670];
  residual += temp*temp;
  temp = work1d.KKT[450]-1*work1d.d[225]*work1d.L[690];
  residual += temp*temp;
  temp = work1d.KKT[452]-1*work1d.d[226]*work1d.L[710];
  residual += temp*temp;
  temp = work1d.KKT[454]-1*work1d.d[227]*work1d.L[730];
  residual += temp*temp;
  temp = work1d.KKT[456]-1*work1d.d[228]*work1d.L[750];
  residual += temp*temp;
  temp = work1d.KKT[458]-1*work1d.d[229]*work1d.L[770];
  residual += temp*temp;
  temp = work1d.KKT[460]-1*work1d.d[230]*work1d.L[790];
  residual += temp*temp;
  temp = work1d.KKT[462]-1*work1d.d[231]*work1d.L[810];
  residual += temp*temp;
  temp = work1d.KKT[464]-1*work1d.d[232]*work1d.L[830];
  residual += temp*temp;
  temp = work1d.KKT[466]-1*work1d.d[233]*work1d.L[850];
  residual += temp*temp;
  temp = work1d.KKT[468]-1*work1d.d[234]*work1d.L[870];
  residual += temp*temp;
  temp = work1d.KKT[470]-1*work1d.d[235]*work1d.L[890];
  residual += temp*temp;
  temp = work1d.KKT[472]-1*work1d.d[236]*work1d.L[910];
  residual += temp*temp;
  temp = work1d.KKT[474]-1*work1d.d[237]*work1d.L[930];
  residual += temp*temp;
  temp = work1d.KKT[476]-1*work1d.d[238]*work1d.L[956];
  residual += temp*temp;
  temp = work1d.KKT[478]-1*work1d.d[239]*work1d.L[168];
  residual += temp*temp;
  temp = work1d.KKT[480]-1*work1d.d[240]*work1d.L[161];
  residual += temp*temp;
  temp = work1d.KKT[482]-1*work1d.d[241]*work1d.L[216];
  residual += temp*temp;
  temp = work1d.KKT[484]-1*work1d.d[242]*work1d.L[230];
  residual += temp*temp;
  temp = work1d.KKT[486]-1*work1d.d[243]*work1d.L[248];
  residual += temp*temp;
  temp = work1d.KKT[488]-1*work1d.d[244]*work1d.L[268];
  residual += temp*temp;
  temp = work1d.KKT[490]-1*work1d.d[245]*work1d.L[288];
  residual += temp*temp;
  temp = work1d.KKT[492]-1*work1d.d[246]*work1d.L[308];
  residual += temp*temp;
  temp = work1d.KKT[494]-1*work1d.d[247]*work1d.L[328];
  residual += temp*temp;
  temp = work1d.KKT[496]-1*work1d.d[248]*work1d.L[348];
  residual += temp*temp;
  temp = work1d.KKT[498]-1*work1d.d[249]*work1d.L[368];
  residual += temp*temp;
  temp = work1d.KKT[500]-1*work1d.d[250]*work1d.L[388];
  residual += temp*temp;
  temp = work1d.KKT[502]-1*work1d.d[251]*work1d.L[408];
  residual += temp*temp;
  temp = work1d.KKT[504]-1*work1d.d[252]*work1d.L[428];
  residual += temp*temp;
  temp = work1d.KKT[506]-1*work1d.d[253]*work1d.L[448];
  residual += temp*temp;
  temp = work1d.KKT[508]-1*work1d.d[254]*work1d.L[468];
  residual += temp*temp;
  temp = work1d.KKT[510]-1*work1d.d[255]*work1d.L[488];
  residual += temp*temp;
  temp = work1d.KKT[512]-1*work1d.d[256]*work1d.L[508];
  residual += temp*temp;
  temp = work1d.KKT[514]-1*work1d.d[257]*work1d.L[528];
  residual += temp*temp;
  temp = work1d.KKT[516]-1*work1d.d[258]*work1d.L[548];
  residual += temp*temp;
  temp = work1d.KKT[518]-1*work1d.d[259]*work1d.L[568];
  residual += temp*temp;
  temp = work1d.KKT[520]-1*work1d.d[260]*work1d.L[588];
  residual += temp*temp;
  temp = work1d.KKT[522]-1*work1d.d[261]*work1d.L[608];
  residual += temp*temp;
  temp = work1d.KKT[524]-1*work1d.d[262]*work1d.L[628];
  residual += temp*temp;
  temp = work1d.KKT[526]-1*work1d.d[263]*work1d.L[648];
  residual += temp*temp;
  temp = work1d.KKT[528]-1*work1d.d[264]*work1d.L[668];
  residual += temp*temp;
  temp = work1d.KKT[530]-1*work1d.d[265]*work1d.L[688];
  residual += temp*temp;
  temp = work1d.KKT[532]-1*work1d.d[266]*work1d.L[708];
  residual += temp*temp;
  temp = work1d.KKT[534]-1*work1d.d[267]*work1d.L[728];
  residual += temp*temp;
  temp = work1d.KKT[536]-1*work1d.d[268]*work1d.L[748];
  residual += temp*temp;
  temp = work1d.KKT[538]-1*work1d.d[269]*work1d.L[768];
  residual += temp*temp;
  temp = work1d.KKT[540]-1*work1d.d[270]*work1d.L[788];
  residual += temp*temp;
  temp = work1d.KKT[542]-1*work1d.d[271]*work1d.L[808];
  residual += temp*temp;
  temp = work1d.KKT[544]-1*work1d.d[272]*work1d.L[828];
  residual += temp*temp;
  temp = work1d.KKT[546]-1*work1d.d[273]*work1d.L[848];
  residual += temp*temp;
  temp = work1d.KKT[548]-1*work1d.d[274]*work1d.L[868];
  residual += temp*temp;
  temp = work1d.KKT[550]-1*work1d.d[275]*work1d.L[888];
  residual += temp*temp;
  temp = work1d.KKT[552]-1*work1d.d[276]*work1d.L[908];
  residual += temp*temp;
  temp = work1d.KKT[554]-1*work1d.d[277]*work1d.L[928];
  residual += temp*temp;
  temp = work1d.KKT[556]-1*work1d.d[278]*work1d.L[952];
  residual += temp*temp;
  temp = work1d.KKT[558]-1*work1d.d[279]*work1d.L[968];
  residual += temp*temp;
  temp = work1d.KKT[560]-1*work1d.d[280]*work1d.L[167];
  residual += temp*temp;
  temp = work1d.KKT[562]-1*work1d.d[281]*work1d.L[220];
  residual += temp*temp;
  temp = work1d.KKT[564]-1*work1d.d[282]*work1d.L[233];
  residual += temp*temp;
  temp = work1d.KKT[566]-1*work1d.d[283]*work1d.L[251];
  residual += temp*temp;
  temp = work1d.KKT[568]-1*work1d.d[284]*work1d.L[271];
  residual += temp*temp;
  temp = work1d.KKT[570]-1*work1d.d[285]*work1d.L[291];
  residual += temp*temp;
  temp = work1d.KKT[572]-1*work1d.d[286]*work1d.L[311];
  residual += temp*temp;
  temp = work1d.KKT[574]-1*work1d.d[287]*work1d.L[331];
  residual += temp*temp;
  temp = work1d.KKT[576]-1*work1d.d[288]*work1d.L[351];
  residual += temp*temp;
  temp = work1d.KKT[578]-1*work1d.d[289]*work1d.L[371];
  residual += temp*temp;
  temp = work1d.KKT[580]-1*work1d.d[290]*work1d.L[391];
  residual += temp*temp;
  temp = work1d.KKT[582]-1*work1d.d[291]*work1d.L[411];
  residual += temp*temp;
  temp = work1d.KKT[584]-1*work1d.d[292]*work1d.L[431];
  residual += temp*temp;
  temp = work1d.KKT[586]-1*work1d.d[293]*work1d.L[451];
  residual += temp*temp;
  temp = work1d.KKT[588]-1*work1d.d[294]*work1d.L[471];
  residual += temp*temp;
  temp = work1d.KKT[590]-1*work1d.d[295]*work1d.L[491];
  residual += temp*temp;
  temp = work1d.KKT[592]-1*work1d.d[296]*work1d.L[511];
  residual += temp*temp;
  temp = work1d.KKT[594]-1*work1d.d[297]*work1d.L[531];
  residual += temp*temp;
  temp = work1d.KKT[596]-1*work1d.d[298]*work1d.L[551];
  residual += temp*temp;
  temp = work1d.KKT[598]-1*work1d.d[299]*work1d.L[571];
  residual += temp*temp;
  temp = work1d.KKT[600]-1*work1d.d[300]*work1d.L[591];
  residual += temp*temp;
  temp = work1d.KKT[602]-1*work1d.d[301]*work1d.L[611];
  residual += temp*temp;
  temp = work1d.KKT[604]-1*work1d.d[302]*work1d.L[631];
  residual += temp*temp;
  temp = work1d.KKT[606]-1*work1d.d[303]*work1d.L[651];
  residual += temp*temp;
  temp = work1d.KKT[608]-1*work1d.d[304]*work1d.L[671];
  residual += temp*temp;
  temp = work1d.KKT[610]-1*work1d.d[305]*work1d.L[691];
  residual += temp*temp;
  temp = work1d.KKT[612]-1*work1d.d[306]*work1d.L[711];
  residual += temp*temp;
  temp = work1d.KKT[614]-1*work1d.d[307]*work1d.L[731];
  residual += temp*temp;
  temp = work1d.KKT[616]-1*work1d.d[308]*work1d.L[751];
  residual += temp*temp;
  temp = work1d.KKT[618]-1*work1d.d[309]*work1d.L[771];
  residual += temp*temp;
  temp = work1d.KKT[620]-1*work1d.d[310]*work1d.L[791];
  residual += temp*temp;
  temp = work1d.KKT[622]-1*work1d.d[311]*work1d.L[811];
  residual += temp*temp;
  temp = work1d.KKT[624]-1*work1d.d[312]*work1d.L[831];
  residual += temp*temp;
  temp = work1d.KKT[626]-1*work1d.d[313]*work1d.L[851];
  residual += temp*temp;
  temp = work1d.KKT[628]-1*work1d.d[314]*work1d.L[871];
  residual += temp*temp;
  temp = work1d.KKT[630]-1*work1d.d[315]*work1d.L[891];
  residual += temp*temp;
  temp = work1d.KKT[632]-1*work1d.d[316]*work1d.L[911];
  residual += temp*temp;
  temp = work1d.KKT[634]-1*work1d.d[317]*work1d.L[931];
  residual += temp*temp;
  temp = work1d.KKT[636]-1*work1d.d[318]*work1d.L[957];
  residual += temp*temp;
  temp = work1d.KKT[638]-1*work1d.d[319]*work1d.L[169];
  residual += temp*temp;
  temp = work1d.KKT[640]-1*work1d.d[320]*work1d.L[162];
  residual += temp*temp;
  temp = work1d.KKT[643]-work1d.L[160]*work1d.d[323]*1;
  residual += temp*temp;
  temp = work1d.KKT[641]-1*work1d.d[321]*work1d.L[165];
  residual += temp*temp;
  temp = work1d.KKT[642]-1*work1d.d[322]*work1d.L[217];
  residual += temp*temp;
  temp = work1d.KKT[644]-1*work1d.d[324]*work1d.L[221];
  residual += temp*temp;
  temp = work1d.KKT[646]-work1d.L[172]*work1d.d[325]*1;
  residual += temp*temp;
  temp = work1d.KKT[727]-work1d.L[171]*work1d.d[366]*1;
  residual += temp*temp;
  temp = work1d.KKT[816]-work1d.L[226]*work1d.d[411]*1;
  residual += temp*temp;
  temp = work1d.KKT[737]-1*work1d.d[371]*work1d.L[222];
  residual += temp*temp;
  temp = work1d.KKT[735]-1*work1d.d[370]*work1d.L[218];
  residual += temp*temp;
  temp = work1d.KKT[818]-work1d.L[227]*work1d.d[412]*1;
  residual += temp*temp;
  temp = work1d.KKT[736]-1*work1d.d[370]*work1d.L[223];
  residual += temp*temp;
  temp = work1d.KKT[931]-1*work1d.d[451]*work1d.L[231];
  residual += temp*temp;
  temp = work1d.KKT[738]-1*work1d.d[371]*work1d.L[234];
  residual += temp*temp;
  temp = work1d.KKT[648]-work1d.L[173]*work1d.d[326]*1;
  residual += temp*temp;
  temp = work1d.KKT[820]-work1d.L[239]*work1d.d[413]*1;
  residual += temp*temp;
  temp = work1d.KKT[934]-work1d.L[244]*work1d.d[452]*1;
  residual += temp*temp;
  temp = work1d.KKT[739]-1*work1d.d[372]*work1d.L[235];
  residual += temp*temp;
  temp = work1d.KKT[933]-work1d.L[242]*work1d.d[452]*1-work1d.L[241]*work1d.d[451]*work1d.L[231];
  residual += temp*temp;
  temp = work1d.KKT[936]-work1d.L[244]*work1d.d[452]*work1d.L[238]-work1d.L[245]*work1d.d[453]*1;
  residual += temp*temp;
  temp = work1d.KKT[822]-work1d.L[240]*work1d.d[414]*1;
  residual += temp*temp;
  temp = work1d.KKT[937]-1*work1d.d[455]*work1d.L[249];
  residual += temp*temp;
  temp = work1d.KKT[740]-1*work1d.d[372]*work1d.L[252];
  residual += temp*temp;
  temp = work1d.KKT[650]-work1d.L[174]*work1d.d[327]*1;
  residual += temp*temp;
  temp = work1d.KKT[823]-work1d.L[258]*work1d.d[414]*1;
  residual += temp*temp;
  temp = work1d.KKT[940]-work1d.L[264]*work1d.d[456]*1;
  residual += temp*temp;
  temp = work1d.KKT[741]-1*work1d.d[373]*work1d.L[253];
  residual += temp*temp;
  temp = work1d.KKT[939]-work1d.L[262]*work1d.d[456]*1-work1d.L[261]*work1d.d[455]*work1d.L[249];
  residual += temp*temp;
  temp = work1d.KKT[942]-work1d.L[264]*work1d.d[456]*work1d.L[257]-work1d.L[265]*work1d.d[457]*1;
  residual += temp*temp;
  temp = work1d.KKT[825]-work1d.L[259]*work1d.d[415]*1;
  residual += temp*temp;
  temp = work1d.KKT[943]-1*work1d.d[459]*work1d.L[269];
  residual += temp*temp;
  temp = work1d.KKT[742]-1*work1d.d[373]*work1d.L[272];
  residual += temp*temp;
  temp = work1d.KKT[652]-work1d.L[175]*work1d.d[328]*1;
  residual += temp*temp;
  temp = work1d.KKT[826]-work1d.L[278]*work1d.d[415]*1;
  residual += temp*temp;
  temp = work1d.KKT[946]-work1d.L[284]*work1d.d[460]*1;
  residual += temp*temp;
  temp = work1d.KKT[743]-1*work1d.d[374]*work1d.L[273];
  residual += temp*temp;
  temp = work1d.KKT[945]-work1d.L[282]*work1d.d[460]*1-work1d.L[281]*work1d.d[459]*work1d.L[269];
  residual += temp*temp;
  temp = work1d.KKT[948]-work1d.L[284]*work1d.d[460]*work1d.L[277]-work1d.L[285]*work1d.d[461]*1;
  residual += temp*temp;
  temp = work1d.KKT[828]-work1d.L[279]*work1d.d[416]*1;
  residual += temp*temp;
  temp = work1d.KKT[949]-1*work1d.d[463]*work1d.L[289];
  residual += temp*temp;
  temp = work1d.KKT[744]-1*work1d.d[374]*work1d.L[292];
  residual += temp*temp;
  temp = work1d.KKT[654]-work1d.L[176]*work1d.d[329]*1;
  residual += temp*temp;
  temp = work1d.KKT[829]-work1d.L[298]*work1d.d[416]*1;
  residual += temp*temp;
  temp = work1d.KKT[952]-work1d.L[304]*work1d.d[464]*1;
  residual += temp*temp;
  temp = work1d.KKT[745]-1*work1d.d[375]*work1d.L[293];
  residual += temp*temp;
  temp = work1d.KKT[951]-work1d.L[302]*work1d.d[464]*1-work1d.L[301]*work1d.d[463]*work1d.L[289];
  residual += temp*temp;
  temp = work1d.KKT[954]-work1d.L[304]*work1d.d[464]*work1d.L[297]-work1d.L[305]*work1d.d[465]*1;
  residual += temp*temp;
  temp = work1d.KKT[831]-work1d.L[299]*work1d.d[417]*1;
  residual += temp*temp;
  temp = work1d.KKT[955]-1*work1d.d[467]*work1d.L[309];
  residual += temp*temp;
  temp = work1d.KKT[746]-1*work1d.d[375]*work1d.L[312];
  residual += temp*temp;
  temp = work1d.KKT[656]-work1d.L[177]*work1d.d[330]*1;
  residual += temp*temp;
  temp = work1d.KKT[832]-work1d.L[318]*work1d.d[417]*1;
  residual += temp*temp;
  temp = work1d.KKT[958]-work1d.L[324]*work1d.d[468]*1;
  residual += temp*temp;
  temp = work1d.KKT[747]-1*work1d.d[376]*work1d.L[313];
  residual += temp*temp;
  temp = work1d.KKT[957]-work1d.L[322]*work1d.d[468]*1-work1d.L[321]*work1d.d[467]*work1d.L[309];
  residual += temp*temp;
  temp = work1d.KKT[960]-work1d.L[324]*work1d.d[468]*work1d.L[317]-work1d.L[325]*work1d.d[469]*1;
  residual += temp*temp;
  temp = work1d.KKT[834]-work1d.L[319]*work1d.d[418]*1;
  residual += temp*temp;
  temp = work1d.KKT[961]-1*work1d.d[471]*work1d.L[329];
  residual += temp*temp;
  temp = work1d.KKT[748]-1*work1d.d[376]*work1d.L[332];
  residual += temp*temp;
  temp = work1d.KKT[658]-work1d.L[178]*work1d.d[331]*1;
  residual += temp*temp;
  temp = work1d.KKT[835]-work1d.L[338]*work1d.d[418]*1;
  residual += temp*temp;
  temp = work1d.KKT[964]-work1d.L[344]*work1d.d[472]*1;
  residual += temp*temp;
  temp = work1d.KKT[749]-1*work1d.d[377]*work1d.L[333];
  residual += temp*temp;
  temp = work1d.KKT[963]-work1d.L[342]*work1d.d[472]*1-work1d.L[341]*work1d.d[471]*work1d.L[329];
  residual += temp*temp;
  temp = work1d.KKT[966]-work1d.L[344]*work1d.d[472]*work1d.L[337]-work1d.L[345]*work1d.d[473]*1;
  residual += temp*temp;
  temp = work1d.KKT[837]-work1d.L[339]*work1d.d[419]*1;
  residual += temp*temp;
  temp = work1d.KKT[967]-1*work1d.d[475]*work1d.L[349];
  residual += temp*temp;
  temp = work1d.KKT[750]-1*work1d.d[377]*work1d.L[352];
  residual += temp*temp;
  temp = work1d.KKT[660]-work1d.L[179]*work1d.d[332]*1;
  residual += temp*temp;
  temp = work1d.KKT[838]-work1d.L[358]*work1d.d[419]*1;
  residual += temp*temp;
  temp = work1d.KKT[970]-work1d.L[364]*work1d.d[476]*1;
  residual += temp*temp;
  temp = work1d.KKT[751]-1*work1d.d[378]*work1d.L[353];
  residual += temp*temp;
  temp = work1d.KKT[969]-work1d.L[362]*work1d.d[476]*1-work1d.L[361]*work1d.d[475]*work1d.L[349];
  residual += temp*temp;
  temp = work1d.KKT[972]-work1d.L[364]*work1d.d[476]*work1d.L[357]-work1d.L[365]*work1d.d[477]*1;
  residual += temp*temp;
  temp = work1d.KKT[840]-work1d.L[359]*work1d.d[420]*1;
  residual += temp*temp;
  temp = work1d.KKT[973]-1*work1d.d[479]*work1d.L[369];
  residual += temp*temp;
  temp = work1d.KKT[752]-1*work1d.d[378]*work1d.L[372];
  residual += temp*temp;
  temp = work1d.KKT[662]-work1d.L[180]*work1d.d[333]*1;
  residual += temp*temp;
  temp = work1d.KKT[841]-work1d.L[378]*work1d.d[420]*1;
  residual += temp*temp;
  temp = work1d.KKT[976]-work1d.L[384]*work1d.d[480]*1;
  residual += temp*temp;
  temp = work1d.KKT[753]-1*work1d.d[379]*work1d.L[373];
  residual += temp*temp;
  temp = work1d.KKT[975]-work1d.L[382]*work1d.d[480]*1-work1d.L[381]*work1d.d[479]*work1d.L[369];
  residual += temp*temp;
  temp = work1d.KKT[978]-work1d.L[384]*work1d.d[480]*work1d.L[377]-work1d.L[385]*work1d.d[481]*1;
  residual += temp*temp;
  temp = work1d.KKT[843]-work1d.L[379]*work1d.d[421]*1;
  residual += temp*temp;
  temp = work1d.KKT[979]-1*work1d.d[483]*work1d.L[389];
  residual += temp*temp;
  temp = work1d.KKT[754]-1*work1d.d[379]*work1d.L[392];
  residual += temp*temp;
  temp = work1d.KKT[664]-work1d.L[181]*work1d.d[334]*1;
  residual += temp*temp;
  temp = work1d.KKT[844]-work1d.L[398]*work1d.d[421]*1;
  residual += temp*temp;
  temp = work1d.KKT[982]-work1d.L[404]*work1d.d[484]*1;
  residual += temp*temp;
  temp = work1d.KKT[755]-1*work1d.d[380]*work1d.L[393];
  residual += temp*temp;
  temp = work1d.KKT[981]-work1d.L[402]*work1d.d[484]*1-work1d.L[401]*work1d.d[483]*work1d.L[389];
  residual += temp*temp;
  temp = work1d.KKT[984]-work1d.L[404]*work1d.d[484]*work1d.L[397]-work1d.L[405]*work1d.d[485]*1;
  residual += temp*temp;
  temp = work1d.KKT[846]-work1d.L[399]*work1d.d[422]*1;
  residual += temp*temp;
  temp = work1d.KKT[985]-1*work1d.d[487]*work1d.L[409];
  residual += temp*temp;
  temp = work1d.KKT[756]-1*work1d.d[380]*work1d.L[412];
  residual += temp*temp;
  temp = work1d.KKT[666]-work1d.L[182]*work1d.d[335]*1;
  residual += temp*temp;
  temp = work1d.KKT[847]-work1d.L[418]*work1d.d[422]*1;
  residual += temp*temp;
  temp = work1d.KKT[988]-work1d.L[424]*work1d.d[488]*1;
  residual += temp*temp;
  temp = work1d.KKT[757]-1*work1d.d[381]*work1d.L[413];
  residual += temp*temp;
  temp = work1d.KKT[987]-work1d.L[422]*work1d.d[488]*1-work1d.L[421]*work1d.d[487]*work1d.L[409];
  residual += temp*temp;
  temp = work1d.KKT[990]-work1d.L[424]*work1d.d[488]*work1d.L[417]-work1d.L[425]*work1d.d[489]*1;
  residual += temp*temp;
  temp = work1d.KKT[849]-work1d.L[419]*work1d.d[423]*1;
  residual += temp*temp;
  temp = work1d.KKT[991]-1*work1d.d[491]*work1d.L[429];
  residual += temp*temp;
  temp = work1d.KKT[758]-1*work1d.d[381]*work1d.L[432];
  residual += temp*temp;
  temp = work1d.KKT[668]-work1d.L[183]*work1d.d[336]*1;
  residual += temp*temp;
  temp = work1d.KKT[850]-work1d.L[438]*work1d.d[423]*1;
  residual += temp*temp;
  temp = work1d.KKT[994]-work1d.L[444]*work1d.d[492]*1;
  residual += temp*temp;
  temp = work1d.KKT[759]-1*work1d.d[382]*work1d.L[433];
  residual += temp*temp;
  temp = work1d.KKT[993]-work1d.L[442]*work1d.d[492]*1-work1d.L[441]*work1d.d[491]*work1d.L[429];
  residual += temp*temp;
  temp = work1d.KKT[996]-work1d.L[444]*work1d.d[492]*work1d.L[437]-work1d.L[445]*work1d.d[493]*1;
  residual += temp*temp;
  temp = work1d.KKT[852]-work1d.L[439]*work1d.d[424]*1;
  residual += temp*temp;
  temp = work1d.KKT[997]-1*work1d.d[495]*work1d.L[449];
  residual += temp*temp;
  temp = work1d.KKT[760]-1*work1d.d[382]*work1d.L[452];
  residual += temp*temp;
  temp = work1d.KKT[670]-work1d.L[184]*work1d.d[337]*1;
  residual += temp*temp;
  temp = work1d.KKT[853]-work1d.L[458]*work1d.d[424]*1;
  residual += temp*temp;
  temp = work1d.KKT[1000]-work1d.L[464]*work1d.d[496]*1;
  residual += temp*temp;
  temp = work1d.KKT[761]-1*work1d.d[383]*work1d.L[453];
  residual += temp*temp;
  temp = work1d.KKT[999]-work1d.L[462]*work1d.d[496]*1-work1d.L[461]*work1d.d[495]*work1d.L[449];
  residual += temp*temp;
  temp = work1d.KKT[1002]-work1d.L[464]*work1d.d[496]*work1d.L[457]-work1d.L[465]*work1d.d[497]*1;
  residual += temp*temp;
  temp = work1d.KKT[855]-work1d.L[459]*work1d.d[425]*1;
  residual += temp*temp;
  temp = work1d.KKT[1003]-1*work1d.d[499]*work1d.L[469];
  residual += temp*temp;
  temp = work1d.KKT[762]-1*work1d.d[383]*work1d.L[472];
  residual += temp*temp;
  temp = work1d.KKT[672]-work1d.L[185]*work1d.d[338]*1;
  residual += temp*temp;
  temp = work1d.KKT[856]-work1d.L[478]*work1d.d[425]*1;
  residual += temp*temp;
  temp = work1d.KKT[1006]-work1d.L[484]*work1d.d[500]*1;
  residual += temp*temp;
  temp = work1d.KKT[763]-1*work1d.d[384]*work1d.L[473];
  residual += temp*temp;
  temp = work1d.KKT[1005]-work1d.L[482]*work1d.d[500]*1-work1d.L[481]*work1d.d[499]*work1d.L[469];
  residual += temp*temp;
  temp = work1d.KKT[1008]-work1d.L[484]*work1d.d[500]*work1d.L[477]-work1d.L[485]*work1d.d[501]*1;
  residual += temp*temp;
  temp = work1d.KKT[858]-work1d.L[479]*work1d.d[426]*1;
  residual += temp*temp;
  temp = work1d.KKT[1009]-1*work1d.d[503]*work1d.L[489];
  residual += temp*temp;
  temp = work1d.KKT[764]-1*work1d.d[384]*work1d.L[492];
  residual += temp*temp;
  temp = work1d.KKT[674]-work1d.L[186]*work1d.d[339]*1;
  residual += temp*temp;
  temp = work1d.KKT[859]-work1d.L[498]*work1d.d[426]*1;
  residual += temp*temp;
  temp = work1d.KKT[1012]-work1d.L[504]*work1d.d[504]*1;
  residual += temp*temp;
  temp = work1d.KKT[765]-1*work1d.d[385]*work1d.L[493];
  residual += temp*temp;
  temp = work1d.KKT[1011]-work1d.L[502]*work1d.d[504]*1-work1d.L[501]*work1d.d[503]*work1d.L[489];
  residual += temp*temp;
  temp = work1d.KKT[1014]-work1d.L[504]*work1d.d[504]*work1d.L[497]-work1d.L[505]*work1d.d[505]*1;
  residual += temp*temp;
  temp = work1d.KKT[861]-work1d.L[499]*work1d.d[427]*1;
  residual += temp*temp;
  temp = work1d.KKT[1015]-1*work1d.d[507]*work1d.L[509];
  residual += temp*temp;
  temp = work1d.KKT[766]-1*work1d.d[385]*work1d.L[512];
  residual += temp*temp;
  temp = work1d.KKT[676]-work1d.L[187]*work1d.d[340]*1;
  residual += temp*temp;
  temp = work1d.KKT[862]-work1d.L[518]*work1d.d[427]*1;
  residual += temp*temp;
  temp = work1d.KKT[1018]-work1d.L[524]*work1d.d[508]*1;
  residual += temp*temp;
  temp = work1d.KKT[767]-1*work1d.d[386]*work1d.L[513];
  residual += temp*temp;
  temp = work1d.KKT[1017]-work1d.L[522]*work1d.d[508]*1-work1d.L[521]*work1d.d[507]*work1d.L[509];
  residual += temp*temp;
  temp = work1d.KKT[1020]-work1d.L[524]*work1d.d[508]*work1d.L[517]-work1d.L[525]*work1d.d[509]*1;
  residual += temp*temp;
  temp = work1d.KKT[864]-work1d.L[519]*work1d.d[428]*1;
  residual += temp*temp;
  temp = work1d.KKT[1021]-1*work1d.d[511]*work1d.L[529];
  residual += temp*temp;
  temp = work1d.KKT[768]-1*work1d.d[386]*work1d.L[532];
  residual += temp*temp;
  temp = work1d.KKT[678]-work1d.L[188]*work1d.d[341]*1;
  residual += temp*temp;
  temp = work1d.KKT[865]-work1d.L[538]*work1d.d[428]*1;
  residual += temp*temp;
  temp = work1d.KKT[1024]-work1d.L[544]*work1d.d[512]*1;
  residual += temp*temp;
  temp = work1d.KKT[769]-1*work1d.d[387]*work1d.L[533];
  residual += temp*temp;
  temp = work1d.KKT[1023]-work1d.L[542]*work1d.d[512]*1-work1d.L[541]*work1d.d[511]*work1d.L[529];
  residual += temp*temp;
  temp = work1d.KKT[1026]-work1d.L[544]*work1d.d[512]*work1d.L[537]-work1d.L[545]*work1d.d[513]*1;
  residual += temp*temp;
  temp = work1d.KKT[867]-work1d.L[539]*work1d.d[429]*1;
  residual += temp*temp;
  temp = work1d.KKT[1027]-1*work1d.d[515]*work1d.L[549];
  residual += temp*temp;
  temp = work1d.KKT[770]-1*work1d.d[387]*work1d.L[552];
  residual += temp*temp;
  temp = work1d.KKT[680]-work1d.L[189]*work1d.d[342]*1;
  residual += temp*temp;
  temp = work1d.KKT[868]-work1d.L[558]*work1d.d[429]*1;
  residual += temp*temp;
  temp = work1d.KKT[1030]-work1d.L[564]*work1d.d[516]*1;
  residual += temp*temp;
  temp = work1d.KKT[771]-1*work1d.d[388]*work1d.L[553];
  residual += temp*temp;
  temp = work1d.KKT[1029]-work1d.L[562]*work1d.d[516]*1-work1d.L[561]*work1d.d[515]*work1d.L[549];
  residual += temp*temp;
  temp = work1d.KKT[1032]-work1d.L[564]*work1d.d[516]*work1d.L[557]-work1d.L[565]*work1d.d[517]*1;
  residual += temp*temp;
  temp = work1d.KKT[870]-work1d.L[559]*work1d.d[430]*1;
  residual += temp*temp;
  temp = work1d.KKT[1033]-1*work1d.d[519]*work1d.L[569];
  residual += temp*temp;
  temp = work1d.KKT[772]-1*work1d.d[388]*work1d.L[572];
  residual += temp*temp;
  temp = work1d.KKT[682]-work1d.L[190]*work1d.d[343]*1;
  residual += temp*temp;
  temp = work1d.KKT[871]-work1d.L[578]*work1d.d[430]*1;
  residual += temp*temp;
  temp = work1d.KKT[1036]-work1d.L[584]*work1d.d[520]*1;
  residual += temp*temp;
  temp = work1d.KKT[773]-1*work1d.d[389]*work1d.L[573];
  residual += temp*temp;
  temp = work1d.KKT[1035]-work1d.L[582]*work1d.d[520]*1-work1d.L[581]*work1d.d[519]*work1d.L[569];
  residual += temp*temp;
  temp = work1d.KKT[1038]-work1d.L[584]*work1d.d[520]*work1d.L[577]-work1d.L[585]*work1d.d[521]*1;
  residual += temp*temp;
  temp = work1d.KKT[873]-work1d.L[579]*work1d.d[431]*1;
  residual += temp*temp;
  temp = work1d.KKT[1039]-1*work1d.d[523]*work1d.L[589];
  residual += temp*temp;
  temp = work1d.KKT[774]-1*work1d.d[389]*work1d.L[592];
  residual += temp*temp;
  temp = work1d.KKT[684]-work1d.L[191]*work1d.d[344]*1;
  residual += temp*temp;
  temp = work1d.KKT[874]-work1d.L[598]*work1d.d[431]*1;
  residual += temp*temp;
  temp = work1d.KKT[1042]-work1d.L[604]*work1d.d[524]*1;
  residual += temp*temp;
  temp = work1d.KKT[775]-1*work1d.d[390]*work1d.L[593];
  residual += temp*temp;
  temp = work1d.KKT[1041]-work1d.L[602]*work1d.d[524]*1-work1d.L[601]*work1d.d[523]*work1d.L[589];
  residual += temp*temp;
  temp = work1d.KKT[1044]-work1d.L[604]*work1d.d[524]*work1d.L[597]-work1d.L[605]*work1d.d[525]*1;
  residual += temp*temp;
  temp = work1d.KKT[876]-work1d.L[599]*work1d.d[432]*1;
  residual += temp*temp;
  temp = work1d.KKT[1045]-1*work1d.d[527]*work1d.L[609];
  residual += temp*temp;
  temp = work1d.KKT[776]-1*work1d.d[390]*work1d.L[612];
  residual += temp*temp;
  temp = work1d.KKT[686]-work1d.L[192]*work1d.d[345]*1;
  residual += temp*temp;
  temp = work1d.KKT[877]-work1d.L[618]*work1d.d[432]*1;
  residual += temp*temp;
  temp = work1d.KKT[1048]-work1d.L[624]*work1d.d[528]*1;
  residual += temp*temp;
  temp = work1d.KKT[777]-1*work1d.d[391]*work1d.L[613];
  residual += temp*temp;
  temp = work1d.KKT[1047]-work1d.L[622]*work1d.d[528]*1-work1d.L[621]*work1d.d[527]*work1d.L[609];
  residual += temp*temp;
  temp = work1d.KKT[1050]-work1d.L[624]*work1d.d[528]*work1d.L[617]-work1d.L[625]*work1d.d[529]*1;
  residual += temp*temp;
  temp = work1d.KKT[879]-work1d.L[619]*work1d.d[433]*1;
  residual += temp*temp;
  temp = work1d.KKT[1051]-1*work1d.d[531]*work1d.L[629];
  residual += temp*temp;
  temp = work1d.KKT[778]-1*work1d.d[391]*work1d.L[632];
  residual += temp*temp;
  temp = work1d.KKT[688]-work1d.L[193]*work1d.d[346]*1;
  residual += temp*temp;
  temp = work1d.KKT[880]-work1d.L[638]*work1d.d[433]*1;
  residual += temp*temp;
  temp = work1d.KKT[1054]-work1d.L[644]*work1d.d[532]*1;
  residual += temp*temp;
  temp = work1d.KKT[779]-1*work1d.d[392]*work1d.L[633];
  residual += temp*temp;
  temp = work1d.KKT[1053]-work1d.L[642]*work1d.d[532]*1-work1d.L[641]*work1d.d[531]*work1d.L[629];
  residual += temp*temp;
  temp = work1d.KKT[1056]-work1d.L[644]*work1d.d[532]*work1d.L[637]-work1d.L[645]*work1d.d[533]*1;
  residual += temp*temp;
  temp = work1d.KKT[882]-work1d.L[639]*work1d.d[434]*1;
  residual += temp*temp;
  temp = work1d.KKT[1057]-1*work1d.d[535]*work1d.L[649];
  residual += temp*temp;
  temp = work1d.KKT[780]-1*work1d.d[392]*work1d.L[652];
  residual += temp*temp;
  temp = work1d.KKT[690]-work1d.L[194]*work1d.d[347]*1;
  residual += temp*temp;
  temp = work1d.KKT[883]-work1d.L[658]*work1d.d[434]*1;
  residual += temp*temp;
  temp = work1d.KKT[1060]-work1d.L[664]*work1d.d[536]*1;
  residual += temp*temp;
  temp = work1d.KKT[781]-1*work1d.d[393]*work1d.L[653];
  residual += temp*temp;
  temp = work1d.KKT[1059]-work1d.L[662]*work1d.d[536]*1-work1d.L[661]*work1d.d[535]*work1d.L[649];
  residual += temp*temp;
  temp = work1d.KKT[1062]-work1d.L[664]*work1d.d[536]*work1d.L[657]-work1d.L[665]*work1d.d[537]*1;
  residual += temp*temp;
  temp = work1d.KKT[885]-work1d.L[659]*work1d.d[435]*1;
  residual += temp*temp;
  temp = work1d.KKT[1063]-1*work1d.d[539]*work1d.L[669];
  residual += temp*temp;
  temp = work1d.KKT[782]-1*work1d.d[393]*work1d.L[672];
  residual += temp*temp;
  temp = work1d.KKT[692]-work1d.L[195]*work1d.d[348]*1;
  residual += temp*temp;
  temp = work1d.KKT[886]-work1d.L[678]*work1d.d[435]*1;
  residual += temp*temp;
  temp = work1d.KKT[1066]-work1d.L[684]*work1d.d[540]*1;
  residual += temp*temp;
  temp = work1d.KKT[783]-1*work1d.d[394]*work1d.L[673];
  residual += temp*temp;
  temp = work1d.KKT[1065]-work1d.L[682]*work1d.d[540]*1-work1d.L[681]*work1d.d[539]*work1d.L[669];
  residual += temp*temp;
  temp = work1d.KKT[1068]-work1d.L[684]*work1d.d[540]*work1d.L[677]-work1d.L[685]*work1d.d[541]*1;
  residual += temp*temp;
  temp = work1d.KKT[888]-work1d.L[679]*work1d.d[436]*1;
  residual += temp*temp;
  temp = work1d.KKT[1069]-1*work1d.d[543]*work1d.L[689];
  residual += temp*temp;
  temp = work1d.KKT[784]-1*work1d.d[394]*work1d.L[692];
  residual += temp*temp;
  temp = work1d.KKT[694]-work1d.L[196]*work1d.d[349]*1;
  residual += temp*temp;
  temp = work1d.KKT[889]-work1d.L[698]*work1d.d[436]*1;
  residual += temp*temp;
  temp = work1d.KKT[1072]-work1d.L[704]*work1d.d[544]*1;
  residual += temp*temp;
  temp = work1d.KKT[785]-1*work1d.d[395]*work1d.L[693];
  residual += temp*temp;
  temp = work1d.KKT[1071]-work1d.L[702]*work1d.d[544]*1-work1d.L[701]*work1d.d[543]*work1d.L[689];
  residual += temp*temp;
  temp = work1d.KKT[1074]-work1d.L[704]*work1d.d[544]*work1d.L[697]-work1d.L[705]*work1d.d[545]*1;
  residual += temp*temp;
  temp = work1d.KKT[891]-work1d.L[699]*work1d.d[437]*1;
  residual += temp*temp;
  temp = work1d.KKT[1075]-1*work1d.d[547]*work1d.L[709];
  residual += temp*temp;
  temp = work1d.KKT[786]-1*work1d.d[395]*work1d.L[712];
  residual += temp*temp;
  temp = work1d.KKT[696]-work1d.L[197]*work1d.d[350]*1;
  residual += temp*temp;
  temp = work1d.KKT[892]-work1d.L[718]*work1d.d[437]*1;
  residual += temp*temp;
  temp = work1d.KKT[1078]-work1d.L[724]*work1d.d[548]*1;
  residual += temp*temp;
  temp = work1d.KKT[787]-1*work1d.d[396]*work1d.L[713];
  residual += temp*temp;
  temp = work1d.KKT[1077]-work1d.L[722]*work1d.d[548]*1-work1d.L[721]*work1d.d[547]*work1d.L[709];
  residual += temp*temp;
  temp = work1d.KKT[1080]-work1d.L[724]*work1d.d[548]*work1d.L[717]-work1d.L[725]*work1d.d[549]*1;
  residual += temp*temp;
  temp = work1d.KKT[894]-work1d.L[719]*work1d.d[438]*1;
  residual += temp*temp;
  temp = work1d.KKT[1081]-1*work1d.d[551]*work1d.L[729];
  residual += temp*temp;
  temp = work1d.KKT[788]-1*work1d.d[396]*work1d.L[732];
  residual += temp*temp;
  temp = work1d.KKT[698]-work1d.L[198]*work1d.d[351]*1;
  residual += temp*temp;
  temp = work1d.KKT[895]-work1d.L[738]*work1d.d[438]*1;
  residual += temp*temp;
  temp = work1d.KKT[1084]-work1d.L[744]*work1d.d[552]*1;
  residual += temp*temp;
  temp = work1d.KKT[789]-1*work1d.d[397]*work1d.L[733];
  residual += temp*temp;
  temp = work1d.KKT[1083]-work1d.L[742]*work1d.d[552]*1-work1d.L[741]*work1d.d[551]*work1d.L[729];
  residual += temp*temp;
  temp = work1d.KKT[1086]-work1d.L[744]*work1d.d[552]*work1d.L[737]-work1d.L[745]*work1d.d[553]*1;
  residual += temp*temp;
  temp = work1d.KKT[897]-work1d.L[739]*work1d.d[439]*1;
  residual += temp*temp;
  temp = work1d.KKT[1087]-1*work1d.d[555]*work1d.L[749];
  residual += temp*temp;
  temp = work1d.KKT[790]-1*work1d.d[397]*work1d.L[752];
  residual += temp*temp;
  temp = work1d.KKT[700]-work1d.L[199]*work1d.d[352]*1;
  residual += temp*temp;
  temp = work1d.KKT[898]-work1d.L[758]*work1d.d[439]*1;
  residual += temp*temp;
  temp = work1d.KKT[1090]-work1d.L[764]*work1d.d[556]*1;
  residual += temp*temp;
  temp = work1d.KKT[791]-1*work1d.d[398]*work1d.L[753];
  residual += temp*temp;
  temp = work1d.KKT[1089]-work1d.L[762]*work1d.d[556]*1-work1d.L[761]*work1d.d[555]*work1d.L[749];
  residual += temp*temp;
  temp = work1d.KKT[1092]-work1d.L[764]*work1d.d[556]*work1d.L[757]-work1d.L[765]*work1d.d[557]*1;
  residual += temp*temp;
  temp = work1d.KKT[900]-work1d.L[759]*work1d.d[440]*1;
  residual += temp*temp;
  temp = work1d.KKT[1093]-1*work1d.d[559]*work1d.L[769];
  residual += temp*temp;
  temp = work1d.KKT[792]-1*work1d.d[398]*work1d.L[772];
  residual += temp*temp;
  temp = work1d.KKT[702]-work1d.L[200]*work1d.d[353]*1;
  residual += temp*temp;
  temp = work1d.KKT[901]-work1d.L[778]*work1d.d[440]*1;
  residual += temp*temp;
  temp = work1d.KKT[1096]-work1d.L[784]*work1d.d[560]*1;
  residual += temp*temp;
  temp = work1d.KKT[793]-1*work1d.d[399]*work1d.L[773];
  residual += temp*temp;
  temp = work1d.KKT[1095]-work1d.L[782]*work1d.d[560]*1-work1d.L[781]*work1d.d[559]*work1d.L[769];
  residual += temp*temp;
  temp = work1d.KKT[1098]-work1d.L[784]*work1d.d[560]*work1d.L[777]-work1d.L[785]*work1d.d[561]*1;
  residual += temp*temp;
  temp = work1d.KKT[903]-work1d.L[779]*work1d.d[441]*1;
  residual += temp*temp;
  temp = work1d.KKT[1099]-1*work1d.d[563]*work1d.L[789];
  residual += temp*temp;
  temp = work1d.KKT[794]-1*work1d.d[399]*work1d.L[792];
  residual += temp*temp;
  temp = work1d.KKT[704]-work1d.L[201]*work1d.d[354]*1;
  residual += temp*temp;
  temp = work1d.KKT[904]-work1d.L[798]*work1d.d[441]*1;
  residual += temp*temp;
  temp = work1d.KKT[1102]-work1d.L[804]*work1d.d[564]*1;
  residual += temp*temp;
  temp = work1d.KKT[795]-1*work1d.d[400]*work1d.L[793];
  residual += temp*temp;
  temp = work1d.KKT[1101]-work1d.L[802]*work1d.d[564]*1-work1d.L[801]*work1d.d[563]*work1d.L[789];
  residual += temp*temp;
  temp = work1d.KKT[1104]-work1d.L[804]*work1d.d[564]*work1d.L[797]-work1d.L[805]*work1d.d[565]*1;
  residual += temp*temp;
  temp = work1d.KKT[906]-work1d.L[799]*work1d.d[442]*1;
  residual += temp*temp;
  temp = work1d.KKT[1105]-1*work1d.d[567]*work1d.L[809];
  residual += temp*temp;
  temp = work1d.KKT[796]-1*work1d.d[400]*work1d.L[812];
  residual += temp*temp;
  temp = work1d.KKT[706]-work1d.L[202]*work1d.d[355]*1;
  residual += temp*temp;
  temp = work1d.KKT[907]-work1d.L[818]*work1d.d[442]*1;
  residual += temp*temp;
  temp = work1d.KKT[1108]-work1d.L[824]*work1d.d[568]*1;
  residual += temp*temp;
  temp = work1d.KKT[797]-1*work1d.d[401]*work1d.L[813];
  residual += temp*temp;
  temp = work1d.KKT[1107]-work1d.L[822]*work1d.d[568]*1-work1d.L[821]*work1d.d[567]*work1d.L[809];
  residual += temp*temp;
  temp = work1d.KKT[1110]-work1d.L[824]*work1d.d[568]*work1d.L[817]-work1d.L[825]*work1d.d[569]*1;
  residual += temp*temp;
  temp = work1d.KKT[909]-work1d.L[819]*work1d.d[443]*1;
  residual += temp*temp;
  temp = work1d.KKT[1111]-1*work1d.d[571]*work1d.L[829];
  residual += temp*temp;
  temp = work1d.KKT[798]-1*work1d.d[401]*work1d.L[832];
  residual += temp*temp;
  temp = work1d.KKT[708]-work1d.L[203]*work1d.d[356]*1;
  residual += temp*temp;
  temp = work1d.KKT[910]-work1d.L[838]*work1d.d[443]*1;
  residual += temp*temp;
  temp = work1d.KKT[1114]-work1d.L[844]*work1d.d[572]*1;
  residual += temp*temp;
  temp = work1d.KKT[799]-1*work1d.d[402]*work1d.L[833];
  residual += temp*temp;
  temp = work1d.KKT[1113]-work1d.L[842]*work1d.d[572]*1-work1d.L[841]*work1d.d[571]*work1d.L[829];
  residual += temp*temp;
  temp = work1d.KKT[1116]-work1d.L[844]*work1d.d[572]*work1d.L[837]-work1d.L[845]*work1d.d[573]*1;
  residual += temp*temp;
  temp = work1d.KKT[912]-work1d.L[839]*work1d.d[444]*1;
  residual += temp*temp;
  temp = work1d.KKT[1117]-1*work1d.d[575]*work1d.L[849];
  residual += temp*temp;
  temp = work1d.KKT[800]-1*work1d.d[402]*work1d.L[852];
  residual += temp*temp;
  temp = work1d.KKT[710]-work1d.L[204]*work1d.d[357]*1;
  residual += temp*temp;
  temp = work1d.KKT[913]-work1d.L[858]*work1d.d[444]*1;
  residual += temp*temp;
  temp = work1d.KKT[1120]-work1d.L[864]*work1d.d[576]*1;
  residual += temp*temp;
  temp = work1d.KKT[801]-1*work1d.d[403]*work1d.L[853];
  residual += temp*temp;
  temp = work1d.KKT[1119]-work1d.L[862]*work1d.d[576]*1-work1d.L[861]*work1d.d[575]*work1d.L[849];
  residual += temp*temp;
  temp = work1d.KKT[1122]-work1d.L[864]*work1d.d[576]*work1d.L[857]-work1d.L[865]*work1d.d[577]*1;
  residual += temp*temp;
  temp = work1d.KKT[915]-work1d.L[859]*work1d.d[445]*1;
  residual += temp*temp;
  temp = work1d.KKT[1123]-1*work1d.d[579]*work1d.L[869];
  residual += temp*temp;
  temp = work1d.KKT[802]-1*work1d.d[403]*work1d.L[872];
  residual += temp*temp;
  temp = work1d.KKT[712]-work1d.L[205]*work1d.d[358]*1;
  residual += temp*temp;
  temp = work1d.KKT[916]-work1d.L[878]*work1d.d[445]*1;
  residual += temp*temp;
  temp = work1d.KKT[1126]-work1d.L[884]*work1d.d[580]*1;
  residual += temp*temp;
  temp = work1d.KKT[803]-1*work1d.d[404]*work1d.L[873];
  residual += temp*temp;
  temp = work1d.KKT[1125]-work1d.L[882]*work1d.d[580]*1-work1d.L[881]*work1d.d[579]*work1d.L[869];
  residual += temp*temp;
  temp = work1d.KKT[1128]-work1d.L[884]*work1d.d[580]*work1d.L[877]-work1d.L[885]*work1d.d[581]*1;
  residual += temp*temp;
  temp = work1d.KKT[918]-work1d.L[879]*work1d.d[446]*1;
  residual += temp*temp;
  temp = work1d.KKT[1129]-1*work1d.d[583]*work1d.L[889];
  residual += temp*temp;
  temp = work1d.KKT[804]-1*work1d.d[404]*work1d.L[892];
  residual += temp*temp;
  temp = work1d.KKT[714]-work1d.L[206]*work1d.d[359]*1;
  residual += temp*temp;
  temp = work1d.KKT[919]-work1d.L[898]*work1d.d[446]*1;
  residual += temp*temp;
  temp = work1d.KKT[1132]-work1d.L[904]*work1d.d[584]*1;
  residual += temp*temp;
  temp = work1d.KKT[805]-1*work1d.d[405]*work1d.L[893];
  residual += temp*temp;
  temp = work1d.KKT[1131]-work1d.L[902]*work1d.d[584]*1-work1d.L[901]*work1d.d[583]*work1d.L[889];
  residual += temp*temp;
  temp = work1d.KKT[1134]-work1d.L[904]*work1d.d[584]*work1d.L[897]-work1d.L[905]*work1d.d[585]*1;
  residual += temp*temp;
  temp = work1d.KKT[921]-work1d.L[899]*work1d.d[447]*1;
  residual += temp*temp;
  temp = work1d.KKT[1135]-1*work1d.d[587]*work1d.L[909];
  residual += temp*temp;
  temp = work1d.KKT[806]-1*work1d.d[405]*work1d.L[912];
  residual += temp*temp;
  temp = work1d.KKT[716]-work1d.L[207]*work1d.d[360]*1;
  residual += temp*temp;
  temp = work1d.KKT[922]-work1d.L[918]*work1d.d[447]*1;
  residual += temp*temp;
  temp = work1d.KKT[1138]-work1d.L[924]*work1d.d[588]*1;
  residual += temp*temp;
  temp = work1d.KKT[807]-1*work1d.d[406]*work1d.L[913];
  residual += temp*temp;
  temp = work1d.KKT[1137]-work1d.L[922]*work1d.d[588]*1-work1d.L[921]*work1d.d[587]*work1d.L[909];
  residual += temp*temp;
  temp = work1d.KKT[1140]-work1d.L[924]*work1d.d[588]*work1d.L[917]-work1d.L[925]*work1d.d[589]*1;
  residual += temp*temp;
  temp = work1d.KKT[924]-work1d.L[919]*work1d.d[448]*1;
  residual += temp*temp;
  temp = work1d.KKT[1141]-1*work1d.d[591]*work1d.L[929];
  residual += temp*temp;
  temp = work1d.KKT[808]-1*work1d.d[406]*work1d.L[932];
  residual += temp*temp;
  temp = work1d.KKT[718]-work1d.L[208]*work1d.d[361]*1;
  residual += temp*temp;
  temp = work1d.KKT[925]-work1d.L[938]*work1d.d[448]*1;
  residual += temp*temp;
  temp = work1d.KKT[1144]-work1d.L[944]*work1d.d[592]*1;
  residual += temp*temp;
  temp = work1d.KKT[809]-1*work1d.d[407]*work1d.L[933];
  residual += temp*temp;
  temp = work1d.KKT[1143]-work1d.L[942]*work1d.d[592]*1-work1d.L[941]*work1d.d[591]*work1d.L[929];
  residual += temp*temp;
  temp = work1d.KKT[1146]-work1d.L[944]*work1d.d[592]*work1d.L[937]-work1d.L[945]*work1d.d[593]*1;
  residual += temp*temp;
  temp = work1d.KKT[927]-work1d.L[939]*work1d.d[449]*1;
  residual += temp*temp;
  temp = work1d.KKT[1147]-1*work1d.d[595]*work1d.L[953];
  residual += temp*temp;
  temp = work1d.KKT[810]-1*work1d.d[407]*work1d.L[958];
  residual += temp*temp;
  temp = work1d.KKT[720]-work1d.L[209]*work1d.d[362]*1;
  residual += temp*temp;
  temp = work1d.KKT[928]-work1d.L[947]*work1d.d[449]*1;
  residual += temp*temp;
  temp = work1d.KKT[1149]-1*work1d.d[597]*work1d.L[955];
  residual += temp*temp;
  temp = work1d.KKT[811]-1*work1d.d[408]*work1d.L[959];
  residual += temp*temp;
  temp = work1d.KKT[1148]-1*work1d.d[596]*work1d.L[954]-work1d.L[950]*work1d.d[595]*work1d.L[953];
  residual += temp*temp;
  temp = work1d.KKT[1150]-1*work1d.d[597]*work1d.L[965];
  residual += temp*temp;
  temp = work1d.KKT[930]-work1d.L[948]*work1d.d[450]*1;
  residual += temp*temp;
  temp = work1d.KKT[1151]-1*work1d.d[597]*work1d.L[973];
  residual += temp*temp;
  temp = work1d.KKT[733]-work1d.L[210]*work1d.d[369]*1;
  residual += temp*temp;
  temp = work1d.KKT[722]-work1d.L[163]*work1d.d[363]*1;
  residual += temp*temp;
  temp = work1d.KKT[812]-1*work1d.d[409]*work1d.L[225];
  residual += temp*temp;
  temp = work1d.KKT[814]-1*work1d.d[410]*work1d.L[970];
  residual += temp*temp;
  temp = work1d.KKT[725]-1*work1d.d[365]*work1d.L[170];
  residual += temp*temp;
  temp = work1d.KKT[813]-1*work1d.d[409]*work1d.L[969];
  residual += temp*temp;
  temp = work1d.KKT[734]-work1d.L[213]*work1d.d[369]*1;
  residual += temp*temp;
  temp = work1d.KKT[729]-work1d.L[211]*work1d.d[367]*1;
  residual += temp*temp;
  temp = work1d.KKT[731]-work1d.L[212]*work1d.d[368]*1;
  residual += temp*temp;
  temp = work1d.KKT[724]-work1d.L[164]*work1d.d[364]*1;
  residual += temp*temp;
  return residual;
}
void matrix_multiply1d(double *result, double *source) {
  /* Finds result = A*source. */
  result[0] = work1d.KKT[643]*source[483];
  result[1] = work1d.KKT[645]*source[1]+work1d.KKT[646]*source[486];
  result[2] = work1d.KKT[647]*source[2]+work1d.KKT[648]*source[489];
  result[3] = work1d.KKT[649]*source[3]+work1d.KKT[650]*source[492];
  result[4] = work1d.KKT[651]*source[4]+work1d.KKT[652]*source[495];
  result[5] = work1d.KKT[653]*source[5]+work1d.KKT[654]*source[498];
  result[6] = work1d.KKT[655]*source[6]+work1d.KKT[656]*source[501];
  result[7] = work1d.KKT[657]*source[7]+work1d.KKT[658]*source[504];
  result[8] = work1d.KKT[659]*source[8]+work1d.KKT[660]*source[507];
  result[9] = work1d.KKT[661]*source[9]+work1d.KKT[662]*source[510];
  result[10] = work1d.KKT[663]*source[10]+work1d.KKT[664]*source[513];
  result[11] = work1d.KKT[665]*source[11]+work1d.KKT[666]*source[516];
  result[12] = work1d.KKT[667]*source[12]+work1d.KKT[668]*source[519];
  result[13] = work1d.KKT[669]*source[13]+work1d.KKT[670]*source[522];
  result[14] = work1d.KKT[671]*source[14]+work1d.KKT[672]*source[525];
  result[15] = work1d.KKT[673]*source[15]+work1d.KKT[674]*source[528];
  result[16] = work1d.KKT[675]*source[16]+work1d.KKT[676]*source[531];
  result[17] = work1d.KKT[677]*source[17]+work1d.KKT[678]*source[534];
  result[18] = work1d.KKT[679]*source[18]+work1d.KKT[680]*source[537];
  result[19] = work1d.KKT[681]*source[19]+work1d.KKT[682]*source[540];
  result[20] = work1d.KKT[683]*source[20]+work1d.KKT[684]*source[543];
  result[21] = work1d.KKT[685]*source[21]+work1d.KKT[686]*source[546];
  result[22] = work1d.KKT[687]*source[22]+work1d.KKT[688]*source[549];
  result[23] = work1d.KKT[689]*source[23]+work1d.KKT[690]*source[552];
  result[24] = work1d.KKT[691]*source[24]+work1d.KKT[692]*source[555];
  result[25] = work1d.KKT[693]*source[25]+work1d.KKT[694]*source[558];
  result[26] = work1d.KKT[695]*source[26]+work1d.KKT[696]*source[561];
  result[27] = work1d.KKT[697]*source[27]+work1d.KKT[698]*source[564];
  result[28] = work1d.KKT[699]*source[28]+work1d.KKT[700]*source[567];
  result[29] = work1d.KKT[701]*source[29]+work1d.KKT[702]*source[570];
  result[30] = work1d.KKT[703]*source[30]+work1d.KKT[704]*source[573];
  result[31] = work1d.KKT[705]*source[31]+work1d.KKT[706]*source[576];
  result[32] = work1d.KKT[707]*source[32]+work1d.KKT[708]*source[579];
  result[33] = work1d.KKT[709]*source[33]+work1d.KKT[710]*source[582];
  result[34] = work1d.KKT[711]*source[34]+work1d.KKT[712]*source[585];
  result[35] = work1d.KKT[713]*source[35]+work1d.KKT[714]*source[588];
  result[36] = work1d.KKT[715]*source[36]+work1d.KKT[716]*source[591];
  result[37] = work1d.KKT[717]*source[37]+work1d.KKT[718]*source[594];
  result[38] = work1d.KKT[719]*source[38]+work1d.KKT[720]*source[597];
  result[39] = work1d.KKT[721]*source[39]+work1d.KKT[722]*source[600];
  result[40] = work1d.KKT[0]*source[40];
  result[41] = work1d.KKT[726]*source[41]+work1d.KKT[641]*source[481]+work1d.KKT[727]*source[484];
  result[42] = work1d.KKT[815]*source[42]+work1d.KKT[322]*source[321]+work1d.KKT[482]*source[401]+work1d.KKT[642]*source[482]+work1d.KKT[816]*source[485]+work1d.KKT[735]*source[484];
  result[43] = work1d.KKT[817]*source[43]+work1d.KKT[402]*source[361]+work1d.KKT[562]*source[441]+work1d.KKT[644]*source[483]+work1d.KKT[737]*source[486]+work1d.KKT[818]*source[485];
  result[44] = work1d.KKT[819]*source[44]+work1d.KKT[736]*source[484]+work1d.KKT[820]*source[487];
  result[45] = work1d.KKT[932]*source[45]+work1d.KKT[324]*source[322]+work1d.KKT[484]*source[402]+work1d.KKT[931]*source[485]+work1d.KKT[934]*source[488]+work1d.KKT[933]*source[487];
  result[46] = work1d.KKT[935]*source[46]+work1d.KKT[404]*source[362]+work1d.KKT[564]*source[442]+work1d.KKT[738]*source[486]+work1d.KKT[739]*source[489]+work1d.KKT[936]*source[488];
  result[47] = work1d.KKT[821]*source[47]+work1d.KKT[822]*source[487]+work1d.KKT[823]*source[490];
  result[48] = work1d.KKT[938]*source[48]+work1d.KKT[326]*source[323]+work1d.KKT[486]*source[403]+work1d.KKT[937]*source[488]+work1d.KKT[940]*source[491]+work1d.KKT[939]*source[490];
  result[49] = work1d.KKT[941]*source[49]+work1d.KKT[406]*source[363]+work1d.KKT[566]*source[443]+work1d.KKT[740]*source[489]+work1d.KKT[741]*source[492]+work1d.KKT[942]*source[491];
  result[50] = work1d.KKT[824]*source[50]+work1d.KKT[825]*source[490]+work1d.KKT[826]*source[493];
  result[51] = work1d.KKT[944]*source[51]+work1d.KKT[328]*source[324]+work1d.KKT[488]*source[404]+work1d.KKT[943]*source[491]+work1d.KKT[946]*source[494]+work1d.KKT[945]*source[493];
  result[52] = work1d.KKT[947]*source[52]+work1d.KKT[408]*source[364]+work1d.KKT[568]*source[444]+work1d.KKT[742]*source[492]+work1d.KKT[743]*source[495]+work1d.KKT[948]*source[494];
  result[53] = work1d.KKT[827]*source[53]+work1d.KKT[828]*source[493]+work1d.KKT[829]*source[496];
  result[54] = work1d.KKT[950]*source[54]+work1d.KKT[330]*source[325]+work1d.KKT[490]*source[405]+work1d.KKT[949]*source[494]+work1d.KKT[952]*source[497]+work1d.KKT[951]*source[496];
  result[55] = work1d.KKT[953]*source[55]+work1d.KKT[410]*source[365]+work1d.KKT[570]*source[445]+work1d.KKT[744]*source[495]+work1d.KKT[745]*source[498]+work1d.KKT[954]*source[497];
  result[56] = work1d.KKT[830]*source[56]+work1d.KKT[831]*source[496]+work1d.KKT[832]*source[499];
  result[57] = work1d.KKT[956]*source[57]+work1d.KKT[332]*source[326]+work1d.KKT[492]*source[406]+work1d.KKT[955]*source[497]+work1d.KKT[958]*source[500]+work1d.KKT[957]*source[499];
  result[58] = work1d.KKT[959]*source[58]+work1d.KKT[412]*source[366]+work1d.KKT[572]*source[446]+work1d.KKT[746]*source[498]+work1d.KKT[747]*source[501]+work1d.KKT[960]*source[500];
  result[59] = work1d.KKT[833]*source[59]+work1d.KKT[834]*source[499]+work1d.KKT[835]*source[502];
  result[60] = work1d.KKT[962]*source[60]+work1d.KKT[334]*source[327]+work1d.KKT[494]*source[407]+work1d.KKT[961]*source[500]+work1d.KKT[964]*source[503]+work1d.KKT[963]*source[502];
  result[61] = work1d.KKT[965]*source[61]+work1d.KKT[414]*source[367]+work1d.KKT[574]*source[447]+work1d.KKT[748]*source[501]+work1d.KKT[749]*source[504]+work1d.KKT[966]*source[503];
  result[62] = work1d.KKT[836]*source[62]+work1d.KKT[837]*source[502]+work1d.KKT[838]*source[505];
  result[63] = work1d.KKT[968]*source[63]+work1d.KKT[336]*source[328]+work1d.KKT[496]*source[408]+work1d.KKT[967]*source[503]+work1d.KKT[970]*source[506]+work1d.KKT[969]*source[505];
  result[64] = work1d.KKT[971]*source[64]+work1d.KKT[416]*source[368]+work1d.KKT[576]*source[448]+work1d.KKT[750]*source[504]+work1d.KKT[751]*source[507]+work1d.KKT[972]*source[506];
  result[65] = work1d.KKT[839]*source[65]+work1d.KKT[840]*source[505]+work1d.KKT[841]*source[508];
  result[66] = work1d.KKT[974]*source[66]+work1d.KKT[338]*source[329]+work1d.KKT[498]*source[409]+work1d.KKT[973]*source[506]+work1d.KKT[976]*source[509]+work1d.KKT[975]*source[508];
  result[67] = work1d.KKT[977]*source[67]+work1d.KKT[418]*source[369]+work1d.KKT[578]*source[449]+work1d.KKT[752]*source[507]+work1d.KKT[753]*source[510]+work1d.KKT[978]*source[509];
  result[68] = work1d.KKT[842]*source[68]+work1d.KKT[843]*source[508]+work1d.KKT[844]*source[511];
  result[69] = work1d.KKT[980]*source[69]+work1d.KKT[340]*source[330]+work1d.KKT[500]*source[410]+work1d.KKT[979]*source[509]+work1d.KKT[982]*source[512]+work1d.KKT[981]*source[511];
  result[70] = work1d.KKT[983]*source[70]+work1d.KKT[420]*source[370]+work1d.KKT[580]*source[450]+work1d.KKT[754]*source[510]+work1d.KKT[755]*source[513]+work1d.KKT[984]*source[512];
  result[71] = work1d.KKT[845]*source[71]+work1d.KKT[846]*source[511]+work1d.KKT[847]*source[514];
  result[72] = work1d.KKT[986]*source[72]+work1d.KKT[342]*source[331]+work1d.KKT[502]*source[411]+work1d.KKT[985]*source[512]+work1d.KKT[988]*source[515]+work1d.KKT[987]*source[514];
  result[73] = work1d.KKT[989]*source[73]+work1d.KKT[422]*source[371]+work1d.KKT[582]*source[451]+work1d.KKT[756]*source[513]+work1d.KKT[757]*source[516]+work1d.KKT[990]*source[515];
  result[74] = work1d.KKT[848]*source[74]+work1d.KKT[849]*source[514]+work1d.KKT[850]*source[517];
  result[75] = work1d.KKT[992]*source[75]+work1d.KKT[344]*source[332]+work1d.KKT[504]*source[412]+work1d.KKT[991]*source[515]+work1d.KKT[994]*source[518]+work1d.KKT[993]*source[517];
  result[76] = work1d.KKT[995]*source[76]+work1d.KKT[424]*source[372]+work1d.KKT[584]*source[452]+work1d.KKT[758]*source[516]+work1d.KKT[759]*source[519]+work1d.KKT[996]*source[518];
  result[77] = work1d.KKT[851]*source[77]+work1d.KKT[852]*source[517]+work1d.KKT[853]*source[520];
  result[78] = work1d.KKT[998]*source[78]+work1d.KKT[346]*source[333]+work1d.KKT[506]*source[413]+work1d.KKT[997]*source[518]+work1d.KKT[1000]*source[521]+work1d.KKT[999]*source[520];
  result[79] = work1d.KKT[1001]*source[79]+work1d.KKT[426]*source[373]+work1d.KKT[586]*source[453]+work1d.KKT[760]*source[519]+work1d.KKT[761]*source[522]+work1d.KKT[1002]*source[521];
  result[80] = work1d.KKT[854]*source[80]+work1d.KKT[855]*source[520]+work1d.KKT[856]*source[523];
  result[81] = work1d.KKT[1004]*source[81]+work1d.KKT[348]*source[334]+work1d.KKT[508]*source[414]+work1d.KKT[1003]*source[521]+work1d.KKT[1006]*source[524]+work1d.KKT[1005]*source[523];
  result[82] = work1d.KKT[1007]*source[82]+work1d.KKT[428]*source[374]+work1d.KKT[588]*source[454]+work1d.KKT[762]*source[522]+work1d.KKT[763]*source[525]+work1d.KKT[1008]*source[524];
  result[83] = work1d.KKT[857]*source[83]+work1d.KKT[858]*source[523]+work1d.KKT[859]*source[526];
  result[84] = work1d.KKT[1010]*source[84]+work1d.KKT[350]*source[335]+work1d.KKT[510]*source[415]+work1d.KKT[1009]*source[524]+work1d.KKT[1012]*source[527]+work1d.KKT[1011]*source[526];
  result[85] = work1d.KKT[1013]*source[85]+work1d.KKT[430]*source[375]+work1d.KKT[590]*source[455]+work1d.KKT[764]*source[525]+work1d.KKT[765]*source[528]+work1d.KKT[1014]*source[527];
  result[86] = work1d.KKT[860]*source[86]+work1d.KKT[861]*source[526]+work1d.KKT[862]*source[529];
  result[87] = work1d.KKT[1016]*source[87]+work1d.KKT[352]*source[336]+work1d.KKT[512]*source[416]+work1d.KKT[1015]*source[527]+work1d.KKT[1018]*source[530]+work1d.KKT[1017]*source[529];
  result[88] = work1d.KKT[1019]*source[88]+work1d.KKT[432]*source[376]+work1d.KKT[592]*source[456]+work1d.KKT[766]*source[528]+work1d.KKT[767]*source[531]+work1d.KKT[1020]*source[530];
  result[89] = work1d.KKT[863]*source[89]+work1d.KKT[864]*source[529]+work1d.KKT[865]*source[532];
  result[90] = work1d.KKT[1022]*source[90]+work1d.KKT[354]*source[337]+work1d.KKT[514]*source[417]+work1d.KKT[1021]*source[530]+work1d.KKT[1024]*source[533]+work1d.KKT[1023]*source[532];
  result[91] = work1d.KKT[1025]*source[91]+work1d.KKT[434]*source[377]+work1d.KKT[594]*source[457]+work1d.KKT[768]*source[531]+work1d.KKT[769]*source[534]+work1d.KKT[1026]*source[533];
  result[92] = work1d.KKT[866]*source[92]+work1d.KKT[867]*source[532]+work1d.KKT[868]*source[535];
  result[93] = work1d.KKT[1028]*source[93]+work1d.KKT[356]*source[338]+work1d.KKT[516]*source[418]+work1d.KKT[1027]*source[533]+work1d.KKT[1030]*source[536]+work1d.KKT[1029]*source[535];
  result[94] = work1d.KKT[1031]*source[94]+work1d.KKT[436]*source[378]+work1d.KKT[596]*source[458]+work1d.KKT[770]*source[534]+work1d.KKT[771]*source[537]+work1d.KKT[1032]*source[536];
  result[95] = work1d.KKT[869]*source[95]+work1d.KKT[870]*source[535]+work1d.KKT[871]*source[538];
  result[96] = work1d.KKT[1034]*source[96]+work1d.KKT[358]*source[339]+work1d.KKT[518]*source[419]+work1d.KKT[1033]*source[536]+work1d.KKT[1036]*source[539]+work1d.KKT[1035]*source[538];
  result[97] = work1d.KKT[1037]*source[97]+work1d.KKT[438]*source[379]+work1d.KKT[598]*source[459]+work1d.KKT[772]*source[537]+work1d.KKT[773]*source[540]+work1d.KKT[1038]*source[539];
  result[98] = work1d.KKT[872]*source[98]+work1d.KKT[873]*source[538]+work1d.KKT[874]*source[541];
  result[99] = work1d.KKT[1040]*source[99]+work1d.KKT[360]*source[340]+work1d.KKT[520]*source[420]+work1d.KKT[1039]*source[539]+work1d.KKT[1042]*source[542]+work1d.KKT[1041]*source[541];
  result[100] = work1d.KKT[1043]*source[100]+work1d.KKT[440]*source[380]+work1d.KKT[600]*source[460]+work1d.KKT[774]*source[540]+work1d.KKT[775]*source[543]+work1d.KKT[1044]*source[542];
  result[101] = work1d.KKT[875]*source[101]+work1d.KKT[876]*source[541]+work1d.KKT[877]*source[544];
  result[102] = work1d.KKT[1046]*source[102]+work1d.KKT[362]*source[341]+work1d.KKT[522]*source[421]+work1d.KKT[1045]*source[542]+work1d.KKT[1048]*source[545]+work1d.KKT[1047]*source[544];
  result[103] = work1d.KKT[1049]*source[103]+work1d.KKT[442]*source[381]+work1d.KKT[602]*source[461]+work1d.KKT[776]*source[543]+work1d.KKT[777]*source[546]+work1d.KKT[1050]*source[545];
  result[104] = work1d.KKT[878]*source[104]+work1d.KKT[879]*source[544]+work1d.KKT[880]*source[547];
  result[105] = work1d.KKT[1052]*source[105]+work1d.KKT[364]*source[342]+work1d.KKT[524]*source[422]+work1d.KKT[1051]*source[545]+work1d.KKT[1054]*source[548]+work1d.KKT[1053]*source[547];
  result[106] = work1d.KKT[1055]*source[106]+work1d.KKT[444]*source[382]+work1d.KKT[604]*source[462]+work1d.KKT[778]*source[546]+work1d.KKT[779]*source[549]+work1d.KKT[1056]*source[548];
  result[107] = work1d.KKT[881]*source[107]+work1d.KKT[882]*source[547]+work1d.KKT[883]*source[550];
  result[108] = work1d.KKT[1058]*source[108]+work1d.KKT[366]*source[343]+work1d.KKT[526]*source[423]+work1d.KKT[1057]*source[548]+work1d.KKT[1060]*source[551]+work1d.KKT[1059]*source[550];
  result[109] = work1d.KKT[1061]*source[109]+work1d.KKT[446]*source[383]+work1d.KKT[606]*source[463]+work1d.KKT[780]*source[549]+work1d.KKT[781]*source[552]+work1d.KKT[1062]*source[551];
  result[110] = work1d.KKT[884]*source[110]+work1d.KKT[885]*source[550]+work1d.KKT[886]*source[553];
  result[111] = work1d.KKT[1064]*source[111]+work1d.KKT[368]*source[344]+work1d.KKT[528]*source[424]+work1d.KKT[1063]*source[551]+work1d.KKT[1066]*source[554]+work1d.KKT[1065]*source[553];
  result[112] = work1d.KKT[1067]*source[112]+work1d.KKT[448]*source[384]+work1d.KKT[608]*source[464]+work1d.KKT[782]*source[552]+work1d.KKT[783]*source[555]+work1d.KKT[1068]*source[554];
  result[113] = work1d.KKT[887]*source[113]+work1d.KKT[888]*source[553]+work1d.KKT[889]*source[556];
  result[114] = work1d.KKT[1070]*source[114]+work1d.KKT[370]*source[345]+work1d.KKT[530]*source[425]+work1d.KKT[1069]*source[554]+work1d.KKT[1072]*source[557]+work1d.KKT[1071]*source[556];
  result[115] = work1d.KKT[1073]*source[115]+work1d.KKT[450]*source[385]+work1d.KKT[610]*source[465]+work1d.KKT[784]*source[555]+work1d.KKT[785]*source[558]+work1d.KKT[1074]*source[557];
  result[116] = work1d.KKT[890]*source[116]+work1d.KKT[891]*source[556]+work1d.KKT[892]*source[559];
  result[117] = work1d.KKT[1076]*source[117]+work1d.KKT[372]*source[346]+work1d.KKT[532]*source[426]+work1d.KKT[1075]*source[557]+work1d.KKT[1078]*source[560]+work1d.KKT[1077]*source[559];
  result[118] = work1d.KKT[1079]*source[118]+work1d.KKT[452]*source[386]+work1d.KKT[612]*source[466]+work1d.KKT[786]*source[558]+work1d.KKT[787]*source[561]+work1d.KKT[1080]*source[560];
  result[119] = work1d.KKT[893]*source[119]+work1d.KKT[894]*source[559]+work1d.KKT[895]*source[562];
  result[120] = work1d.KKT[1082]*source[120]+work1d.KKT[374]*source[347]+work1d.KKT[534]*source[427]+work1d.KKT[1081]*source[560]+work1d.KKT[1084]*source[563]+work1d.KKT[1083]*source[562];
  result[121] = work1d.KKT[1085]*source[121]+work1d.KKT[454]*source[387]+work1d.KKT[614]*source[467]+work1d.KKT[788]*source[561]+work1d.KKT[789]*source[564]+work1d.KKT[1086]*source[563];
  result[122] = work1d.KKT[896]*source[122]+work1d.KKT[897]*source[562]+work1d.KKT[898]*source[565];
  result[123] = work1d.KKT[1088]*source[123]+work1d.KKT[376]*source[348]+work1d.KKT[536]*source[428]+work1d.KKT[1087]*source[563]+work1d.KKT[1090]*source[566]+work1d.KKT[1089]*source[565];
  result[124] = work1d.KKT[1091]*source[124]+work1d.KKT[456]*source[388]+work1d.KKT[616]*source[468]+work1d.KKT[790]*source[564]+work1d.KKT[791]*source[567]+work1d.KKT[1092]*source[566];
  result[125] = work1d.KKT[899]*source[125]+work1d.KKT[900]*source[565]+work1d.KKT[901]*source[568];
  result[126] = work1d.KKT[1094]*source[126]+work1d.KKT[378]*source[349]+work1d.KKT[538]*source[429]+work1d.KKT[1093]*source[566]+work1d.KKT[1096]*source[569]+work1d.KKT[1095]*source[568];
  result[127] = work1d.KKT[1097]*source[127]+work1d.KKT[458]*source[389]+work1d.KKT[618]*source[469]+work1d.KKT[792]*source[567]+work1d.KKT[793]*source[570]+work1d.KKT[1098]*source[569];
  result[128] = work1d.KKT[902]*source[128]+work1d.KKT[903]*source[568]+work1d.KKT[904]*source[571];
  result[129] = work1d.KKT[1100]*source[129]+work1d.KKT[380]*source[350]+work1d.KKT[540]*source[430]+work1d.KKT[1099]*source[569]+work1d.KKT[1102]*source[572]+work1d.KKT[1101]*source[571];
  result[130] = work1d.KKT[1103]*source[130]+work1d.KKT[460]*source[390]+work1d.KKT[620]*source[470]+work1d.KKT[794]*source[570]+work1d.KKT[795]*source[573]+work1d.KKT[1104]*source[572];
  result[131] = work1d.KKT[905]*source[131]+work1d.KKT[906]*source[571]+work1d.KKT[907]*source[574];
  result[132] = work1d.KKT[1106]*source[132]+work1d.KKT[382]*source[351]+work1d.KKT[542]*source[431]+work1d.KKT[1105]*source[572]+work1d.KKT[1108]*source[575]+work1d.KKT[1107]*source[574];
  result[133] = work1d.KKT[1109]*source[133]+work1d.KKT[462]*source[391]+work1d.KKT[622]*source[471]+work1d.KKT[796]*source[573]+work1d.KKT[797]*source[576]+work1d.KKT[1110]*source[575];
  result[134] = work1d.KKT[908]*source[134]+work1d.KKT[909]*source[574]+work1d.KKT[910]*source[577];
  result[135] = work1d.KKT[1112]*source[135]+work1d.KKT[384]*source[352]+work1d.KKT[544]*source[432]+work1d.KKT[1111]*source[575]+work1d.KKT[1114]*source[578]+work1d.KKT[1113]*source[577];
  result[136] = work1d.KKT[1115]*source[136]+work1d.KKT[464]*source[392]+work1d.KKT[624]*source[472]+work1d.KKT[798]*source[576]+work1d.KKT[799]*source[579]+work1d.KKT[1116]*source[578];
  result[137] = work1d.KKT[911]*source[137]+work1d.KKT[912]*source[577]+work1d.KKT[913]*source[580];
  result[138] = work1d.KKT[1118]*source[138]+work1d.KKT[386]*source[353]+work1d.KKT[546]*source[433]+work1d.KKT[1117]*source[578]+work1d.KKT[1120]*source[581]+work1d.KKT[1119]*source[580];
  result[139] = work1d.KKT[1121]*source[139]+work1d.KKT[466]*source[393]+work1d.KKT[626]*source[473]+work1d.KKT[800]*source[579]+work1d.KKT[801]*source[582]+work1d.KKT[1122]*source[581];
  result[140] = work1d.KKT[914]*source[140]+work1d.KKT[915]*source[580]+work1d.KKT[916]*source[583];
  result[141] = work1d.KKT[1124]*source[141]+work1d.KKT[388]*source[354]+work1d.KKT[548]*source[434]+work1d.KKT[1123]*source[581]+work1d.KKT[1126]*source[584]+work1d.KKT[1125]*source[583];
  result[142] = work1d.KKT[1127]*source[142]+work1d.KKT[468]*source[394]+work1d.KKT[628]*source[474]+work1d.KKT[802]*source[582]+work1d.KKT[803]*source[585]+work1d.KKT[1128]*source[584];
  result[143] = work1d.KKT[917]*source[143]+work1d.KKT[918]*source[583]+work1d.KKT[919]*source[586];
  result[144] = work1d.KKT[1130]*source[144]+work1d.KKT[390]*source[355]+work1d.KKT[550]*source[435]+work1d.KKT[1129]*source[584]+work1d.KKT[1132]*source[587]+work1d.KKT[1131]*source[586];
  result[145] = work1d.KKT[1133]*source[145]+work1d.KKT[470]*source[395]+work1d.KKT[630]*source[475]+work1d.KKT[804]*source[585]+work1d.KKT[805]*source[588]+work1d.KKT[1134]*source[587];
  result[146] = work1d.KKT[920]*source[146]+work1d.KKT[921]*source[586]+work1d.KKT[922]*source[589];
  result[147] = work1d.KKT[1136]*source[147]+work1d.KKT[392]*source[356]+work1d.KKT[552]*source[436]+work1d.KKT[1135]*source[587]+work1d.KKT[1138]*source[590]+work1d.KKT[1137]*source[589];
  result[148] = work1d.KKT[1139]*source[148]+work1d.KKT[472]*source[396]+work1d.KKT[632]*source[476]+work1d.KKT[806]*source[588]+work1d.KKT[807]*source[591]+work1d.KKT[1140]*source[590];
  result[149] = work1d.KKT[923]*source[149]+work1d.KKT[924]*source[589]+work1d.KKT[925]*source[592];
  result[150] = work1d.KKT[1142]*source[150]+work1d.KKT[394]*source[357]+work1d.KKT[554]*source[437]+work1d.KKT[1141]*source[590]+work1d.KKT[1144]*source[593]+work1d.KKT[1143]*source[592];
  result[151] = work1d.KKT[1145]*source[151]+work1d.KKT[474]*source[397]+work1d.KKT[634]*source[477]+work1d.KKT[808]*source[591]+work1d.KKT[809]*source[594]+work1d.KKT[1146]*source[593];
  result[152] = work1d.KKT[926]*source[152]+work1d.KKT[927]*source[592]+work1d.KKT[928]*source[595];
  result[153] = work1d.KKT[1152]*source[153]+work1d.KKT[396]*source[358]+work1d.KKT[556]*source[438]+work1d.KKT[1147]*source[593]+work1d.KKT[1149]*source[596]+work1d.KKT[1148]*source[595];
  result[154] = work1d.KKT[1153]*source[154]+work1d.KKT[476]*source[398]+work1d.KKT[636]*source[478]+work1d.KKT[810]*source[594]+work1d.KKT[811]*source[597]+work1d.KKT[1150]*source[596];
  result[155] = work1d.KKT[929]*source[155]+work1d.KKT[930]*source[595]+work1d.KKT[812]*source[598];
  result[156] = work1d.KKT[1154]*source[156]+work1d.KKT[398]*source[359]+work1d.KKT[558]*source[439]+work1d.KKT[1151]*source[596]+work1d.KKT[814]*source[599]+work1d.KKT[813]*source[598];
  result[157] = work1d.KKT[732]*source[157]+work1d.KKT[478]*source[399]+work1d.KKT[638]*source[479]+work1d.KKT[733]*source[597]+work1d.KKT[725]*source[600]+work1d.KKT[734]*source[599];
  result[158] = work1d.KKT[728]*source[158]+work1d.KKT[729]*source[598];
  result[159] = work1d.KKT[730]*source[159]+work1d.KKT[400]*source[360]+work1d.KKT[560]*source[440]+work1d.KKT[731]*source[599];
  result[160] = work1d.KKT[723]*source[160]+work1d.KKT[480]*source[400]+work1d.KKT[640]*source[480]+work1d.KKT[724]*source[600];
  result[161] = work1d.KKT[1]*source[161]+work1d.KKT[2]*source[321];
  result[162] = work1d.KKT[3]*source[162]+work1d.KKT[4]*source[322];
  result[163] = work1d.KKT[5]*source[163]+work1d.KKT[6]*source[323];
  result[164] = work1d.KKT[7]*source[164]+work1d.KKT[8]*source[324];
  result[165] = work1d.KKT[9]*source[165]+work1d.KKT[10]*source[325];
  result[166] = work1d.KKT[11]*source[166]+work1d.KKT[12]*source[326];
  result[167] = work1d.KKT[13]*source[167]+work1d.KKT[14]*source[327];
  result[168] = work1d.KKT[15]*source[168]+work1d.KKT[16]*source[328];
  result[169] = work1d.KKT[17]*source[169]+work1d.KKT[18]*source[329];
  result[170] = work1d.KKT[19]*source[170]+work1d.KKT[20]*source[330];
  result[171] = work1d.KKT[21]*source[171]+work1d.KKT[22]*source[331];
  result[172] = work1d.KKT[23]*source[172]+work1d.KKT[24]*source[332];
  result[173] = work1d.KKT[25]*source[173]+work1d.KKT[26]*source[333];
  result[174] = work1d.KKT[27]*source[174]+work1d.KKT[28]*source[334];
  result[175] = work1d.KKT[29]*source[175]+work1d.KKT[30]*source[335];
  result[176] = work1d.KKT[31]*source[176]+work1d.KKT[32]*source[336];
  result[177] = work1d.KKT[33]*source[177]+work1d.KKT[34]*source[337];
  result[178] = work1d.KKT[35]*source[178]+work1d.KKT[36]*source[338];
  result[179] = work1d.KKT[37]*source[179]+work1d.KKT[38]*source[339];
  result[180] = work1d.KKT[39]*source[180]+work1d.KKT[40]*source[340];
  result[181] = work1d.KKT[41]*source[181]+work1d.KKT[42]*source[341];
  result[182] = work1d.KKT[43]*source[182]+work1d.KKT[44]*source[342];
  result[183] = work1d.KKT[45]*source[183]+work1d.KKT[46]*source[343];
  result[184] = work1d.KKT[47]*source[184]+work1d.KKT[48]*source[344];
  result[185] = work1d.KKT[49]*source[185]+work1d.KKT[50]*source[345];
  result[186] = work1d.KKT[51]*source[186]+work1d.KKT[52]*source[346];
  result[187] = work1d.KKT[53]*source[187]+work1d.KKT[54]*source[347];
  result[188] = work1d.KKT[55]*source[188]+work1d.KKT[56]*source[348];
  result[189] = work1d.KKT[57]*source[189]+work1d.KKT[58]*source[349];
  result[190] = work1d.KKT[59]*source[190]+work1d.KKT[60]*source[350];
  result[191] = work1d.KKT[61]*source[191]+work1d.KKT[62]*source[351];
  result[192] = work1d.KKT[63]*source[192]+work1d.KKT[64]*source[352];
  result[193] = work1d.KKT[65]*source[193]+work1d.KKT[66]*source[353];
  result[194] = work1d.KKT[67]*source[194]+work1d.KKT[68]*source[354];
  result[195] = work1d.KKT[69]*source[195]+work1d.KKT[70]*source[355];
  result[196] = work1d.KKT[71]*source[196]+work1d.KKT[72]*source[356];
  result[197] = work1d.KKT[73]*source[197]+work1d.KKT[74]*source[357];
  result[198] = work1d.KKT[75]*source[198]+work1d.KKT[76]*source[358];
  result[199] = work1d.KKT[77]*source[199]+work1d.KKT[78]*source[359];
  result[200] = work1d.KKT[79]*source[200]+work1d.KKT[80]*source[360];
  result[201] = work1d.KKT[81]*source[201]+work1d.KKT[82]*source[361];
  result[202] = work1d.KKT[83]*source[202]+work1d.KKT[84]*source[362];
  result[203] = work1d.KKT[85]*source[203]+work1d.KKT[86]*source[363];
  result[204] = work1d.KKT[87]*source[204]+work1d.KKT[88]*source[364];
  result[205] = work1d.KKT[89]*source[205]+work1d.KKT[90]*source[365];
  result[206] = work1d.KKT[91]*source[206]+work1d.KKT[92]*source[366];
  result[207] = work1d.KKT[93]*source[207]+work1d.KKT[94]*source[367];
  result[208] = work1d.KKT[95]*source[208]+work1d.KKT[96]*source[368];
  result[209] = work1d.KKT[97]*source[209]+work1d.KKT[98]*source[369];
  result[210] = work1d.KKT[99]*source[210]+work1d.KKT[100]*source[370];
  result[211] = work1d.KKT[101]*source[211]+work1d.KKT[102]*source[371];
  result[212] = work1d.KKT[103]*source[212]+work1d.KKT[104]*source[372];
  result[213] = work1d.KKT[105]*source[213]+work1d.KKT[106]*source[373];
  result[214] = work1d.KKT[107]*source[214]+work1d.KKT[108]*source[374];
  result[215] = work1d.KKT[109]*source[215]+work1d.KKT[110]*source[375];
  result[216] = work1d.KKT[111]*source[216]+work1d.KKT[112]*source[376];
  result[217] = work1d.KKT[113]*source[217]+work1d.KKT[114]*source[377];
  result[218] = work1d.KKT[115]*source[218]+work1d.KKT[116]*source[378];
  result[219] = work1d.KKT[117]*source[219]+work1d.KKT[118]*source[379];
  result[220] = work1d.KKT[119]*source[220]+work1d.KKT[120]*source[380];
  result[221] = work1d.KKT[121]*source[221]+work1d.KKT[122]*source[381];
  result[222] = work1d.KKT[123]*source[222]+work1d.KKT[124]*source[382];
  result[223] = work1d.KKT[125]*source[223]+work1d.KKT[126]*source[383];
  result[224] = work1d.KKT[127]*source[224]+work1d.KKT[128]*source[384];
  result[225] = work1d.KKT[129]*source[225]+work1d.KKT[130]*source[385];
  result[226] = work1d.KKT[131]*source[226]+work1d.KKT[132]*source[386];
  result[227] = work1d.KKT[133]*source[227]+work1d.KKT[134]*source[387];
  result[228] = work1d.KKT[135]*source[228]+work1d.KKT[136]*source[388];
  result[229] = work1d.KKT[137]*source[229]+work1d.KKT[138]*source[389];
  result[230] = work1d.KKT[139]*source[230]+work1d.KKT[140]*source[390];
  result[231] = work1d.KKT[141]*source[231]+work1d.KKT[142]*source[391];
  result[232] = work1d.KKT[143]*source[232]+work1d.KKT[144]*source[392];
  result[233] = work1d.KKT[145]*source[233]+work1d.KKT[146]*source[393];
  result[234] = work1d.KKT[147]*source[234]+work1d.KKT[148]*source[394];
  result[235] = work1d.KKT[149]*source[235]+work1d.KKT[150]*source[395];
  result[236] = work1d.KKT[151]*source[236]+work1d.KKT[152]*source[396];
  result[237] = work1d.KKT[153]*source[237]+work1d.KKT[154]*source[397];
  result[238] = work1d.KKT[155]*source[238]+work1d.KKT[156]*source[398];
  result[239] = work1d.KKT[157]*source[239]+work1d.KKT[158]*source[399];
  result[240] = work1d.KKT[159]*source[240]+work1d.KKT[160]*source[400];
  result[241] = work1d.KKT[161]*source[241]+work1d.KKT[162]*source[401];
  result[242] = work1d.KKT[163]*source[242]+work1d.KKT[164]*source[402];
  result[243] = work1d.KKT[165]*source[243]+work1d.KKT[166]*source[403];
  result[244] = work1d.KKT[167]*source[244]+work1d.KKT[168]*source[404];
  result[245] = work1d.KKT[169]*source[245]+work1d.KKT[170]*source[405];
  result[246] = work1d.KKT[171]*source[246]+work1d.KKT[172]*source[406];
  result[247] = work1d.KKT[173]*source[247]+work1d.KKT[174]*source[407];
  result[248] = work1d.KKT[175]*source[248]+work1d.KKT[176]*source[408];
  result[249] = work1d.KKT[177]*source[249]+work1d.KKT[178]*source[409];
  result[250] = work1d.KKT[179]*source[250]+work1d.KKT[180]*source[410];
  result[251] = work1d.KKT[181]*source[251]+work1d.KKT[182]*source[411];
  result[252] = work1d.KKT[183]*source[252]+work1d.KKT[184]*source[412];
  result[253] = work1d.KKT[185]*source[253]+work1d.KKT[186]*source[413];
  result[254] = work1d.KKT[187]*source[254]+work1d.KKT[188]*source[414];
  result[255] = work1d.KKT[189]*source[255]+work1d.KKT[190]*source[415];
  result[256] = work1d.KKT[191]*source[256]+work1d.KKT[192]*source[416];
  result[257] = work1d.KKT[193]*source[257]+work1d.KKT[194]*source[417];
  result[258] = work1d.KKT[195]*source[258]+work1d.KKT[196]*source[418];
  result[259] = work1d.KKT[197]*source[259]+work1d.KKT[198]*source[419];
  result[260] = work1d.KKT[199]*source[260]+work1d.KKT[200]*source[420];
  result[261] = work1d.KKT[201]*source[261]+work1d.KKT[202]*source[421];
  result[262] = work1d.KKT[203]*source[262]+work1d.KKT[204]*source[422];
  result[263] = work1d.KKT[205]*source[263]+work1d.KKT[206]*source[423];
  result[264] = work1d.KKT[207]*source[264]+work1d.KKT[208]*source[424];
  result[265] = work1d.KKT[209]*source[265]+work1d.KKT[210]*source[425];
  result[266] = work1d.KKT[211]*source[266]+work1d.KKT[212]*source[426];
  result[267] = work1d.KKT[213]*source[267]+work1d.KKT[214]*source[427];
  result[268] = work1d.KKT[215]*source[268]+work1d.KKT[216]*source[428];
  result[269] = work1d.KKT[217]*source[269]+work1d.KKT[218]*source[429];
  result[270] = work1d.KKT[219]*source[270]+work1d.KKT[220]*source[430];
  result[271] = work1d.KKT[221]*source[271]+work1d.KKT[222]*source[431];
  result[272] = work1d.KKT[223]*source[272]+work1d.KKT[224]*source[432];
  result[273] = work1d.KKT[225]*source[273]+work1d.KKT[226]*source[433];
  result[274] = work1d.KKT[227]*source[274]+work1d.KKT[228]*source[434];
  result[275] = work1d.KKT[229]*source[275]+work1d.KKT[230]*source[435];
  result[276] = work1d.KKT[231]*source[276]+work1d.KKT[232]*source[436];
  result[277] = work1d.KKT[233]*source[277]+work1d.KKT[234]*source[437];
  result[278] = work1d.KKT[235]*source[278]+work1d.KKT[236]*source[438];
  result[279] = work1d.KKT[237]*source[279]+work1d.KKT[238]*source[439];
  result[280] = work1d.KKT[239]*source[280]+work1d.KKT[240]*source[440];
  result[281] = work1d.KKT[241]*source[281]+work1d.KKT[242]*source[441];
  result[282] = work1d.KKT[243]*source[282]+work1d.KKT[244]*source[442];
  result[283] = work1d.KKT[245]*source[283]+work1d.KKT[246]*source[443];
  result[284] = work1d.KKT[247]*source[284]+work1d.KKT[248]*source[444];
  result[285] = work1d.KKT[249]*source[285]+work1d.KKT[250]*source[445];
  result[286] = work1d.KKT[251]*source[286]+work1d.KKT[252]*source[446];
  result[287] = work1d.KKT[253]*source[287]+work1d.KKT[254]*source[447];
  result[288] = work1d.KKT[255]*source[288]+work1d.KKT[256]*source[448];
  result[289] = work1d.KKT[257]*source[289]+work1d.KKT[258]*source[449];
  result[290] = work1d.KKT[259]*source[290]+work1d.KKT[260]*source[450];
  result[291] = work1d.KKT[261]*source[291]+work1d.KKT[262]*source[451];
  result[292] = work1d.KKT[263]*source[292]+work1d.KKT[264]*source[452];
  result[293] = work1d.KKT[265]*source[293]+work1d.KKT[266]*source[453];
  result[294] = work1d.KKT[267]*source[294]+work1d.KKT[268]*source[454];
  result[295] = work1d.KKT[269]*source[295]+work1d.KKT[270]*source[455];
  result[296] = work1d.KKT[271]*source[296]+work1d.KKT[272]*source[456];
  result[297] = work1d.KKT[273]*source[297]+work1d.KKT[274]*source[457];
  result[298] = work1d.KKT[275]*source[298]+work1d.KKT[276]*source[458];
  result[299] = work1d.KKT[277]*source[299]+work1d.KKT[278]*source[459];
  result[300] = work1d.KKT[279]*source[300]+work1d.KKT[280]*source[460];
  result[301] = work1d.KKT[281]*source[301]+work1d.KKT[282]*source[461];
  result[302] = work1d.KKT[283]*source[302]+work1d.KKT[284]*source[462];
  result[303] = work1d.KKT[285]*source[303]+work1d.KKT[286]*source[463];
  result[304] = work1d.KKT[287]*source[304]+work1d.KKT[288]*source[464];
  result[305] = work1d.KKT[289]*source[305]+work1d.KKT[290]*source[465];
  result[306] = work1d.KKT[291]*source[306]+work1d.KKT[292]*source[466];
  result[307] = work1d.KKT[293]*source[307]+work1d.KKT[294]*source[467];
  result[308] = work1d.KKT[295]*source[308]+work1d.KKT[296]*source[468];
  result[309] = work1d.KKT[297]*source[309]+work1d.KKT[298]*source[469];
  result[310] = work1d.KKT[299]*source[310]+work1d.KKT[300]*source[470];
  result[311] = work1d.KKT[301]*source[311]+work1d.KKT[302]*source[471];
  result[312] = work1d.KKT[303]*source[312]+work1d.KKT[304]*source[472];
  result[313] = work1d.KKT[305]*source[313]+work1d.KKT[306]*source[473];
  result[314] = work1d.KKT[307]*source[314]+work1d.KKT[308]*source[474];
  result[315] = work1d.KKT[309]*source[315]+work1d.KKT[310]*source[475];
  result[316] = work1d.KKT[311]*source[316]+work1d.KKT[312]*source[476];
  result[317] = work1d.KKT[313]*source[317]+work1d.KKT[314]*source[477];
  result[318] = work1d.KKT[315]*source[318]+work1d.KKT[316]*source[478];
  result[319] = work1d.KKT[317]*source[319]+work1d.KKT[318]*source[479];
  result[320] = work1d.KKT[319]*source[320]+work1d.KKT[320]*source[480];
  result[321] = work1d.KKT[2]*source[161]+work1d.KKT[321]*source[321]+work1d.KKT[322]*source[42];
  result[322] = work1d.KKT[4]*source[162]+work1d.KKT[323]*source[322]+work1d.KKT[324]*source[45];
  result[323] = work1d.KKT[6]*source[163]+work1d.KKT[325]*source[323]+work1d.KKT[326]*source[48];
  result[324] = work1d.KKT[8]*source[164]+work1d.KKT[327]*source[324]+work1d.KKT[328]*source[51];
  result[325] = work1d.KKT[10]*source[165]+work1d.KKT[329]*source[325]+work1d.KKT[330]*source[54];
  result[326] = work1d.KKT[12]*source[166]+work1d.KKT[331]*source[326]+work1d.KKT[332]*source[57];
  result[327] = work1d.KKT[14]*source[167]+work1d.KKT[333]*source[327]+work1d.KKT[334]*source[60];
  result[328] = work1d.KKT[16]*source[168]+work1d.KKT[335]*source[328]+work1d.KKT[336]*source[63];
  result[329] = work1d.KKT[18]*source[169]+work1d.KKT[337]*source[329]+work1d.KKT[338]*source[66];
  result[330] = work1d.KKT[20]*source[170]+work1d.KKT[339]*source[330]+work1d.KKT[340]*source[69];
  result[331] = work1d.KKT[22]*source[171]+work1d.KKT[341]*source[331]+work1d.KKT[342]*source[72];
  result[332] = work1d.KKT[24]*source[172]+work1d.KKT[343]*source[332]+work1d.KKT[344]*source[75];
  result[333] = work1d.KKT[26]*source[173]+work1d.KKT[345]*source[333]+work1d.KKT[346]*source[78];
  result[334] = work1d.KKT[28]*source[174]+work1d.KKT[347]*source[334]+work1d.KKT[348]*source[81];
  result[335] = work1d.KKT[30]*source[175]+work1d.KKT[349]*source[335]+work1d.KKT[350]*source[84];
  result[336] = work1d.KKT[32]*source[176]+work1d.KKT[351]*source[336]+work1d.KKT[352]*source[87];
  result[337] = work1d.KKT[34]*source[177]+work1d.KKT[353]*source[337]+work1d.KKT[354]*source[90];
  result[338] = work1d.KKT[36]*source[178]+work1d.KKT[355]*source[338]+work1d.KKT[356]*source[93];
  result[339] = work1d.KKT[38]*source[179]+work1d.KKT[357]*source[339]+work1d.KKT[358]*source[96];
  result[340] = work1d.KKT[40]*source[180]+work1d.KKT[359]*source[340]+work1d.KKT[360]*source[99];
  result[341] = work1d.KKT[42]*source[181]+work1d.KKT[361]*source[341]+work1d.KKT[362]*source[102];
  result[342] = work1d.KKT[44]*source[182]+work1d.KKT[363]*source[342]+work1d.KKT[364]*source[105];
  result[343] = work1d.KKT[46]*source[183]+work1d.KKT[365]*source[343]+work1d.KKT[366]*source[108];
  result[344] = work1d.KKT[48]*source[184]+work1d.KKT[367]*source[344]+work1d.KKT[368]*source[111];
  result[345] = work1d.KKT[50]*source[185]+work1d.KKT[369]*source[345]+work1d.KKT[370]*source[114];
  result[346] = work1d.KKT[52]*source[186]+work1d.KKT[371]*source[346]+work1d.KKT[372]*source[117];
  result[347] = work1d.KKT[54]*source[187]+work1d.KKT[373]*source[347]+work1d.KKT[374]*source[120];
  result[348] = work1d.KKT[56]*source[188]+work1d.KKT[375]*source[348]+work1d.KKT[376]*source[123];
  result[349] = work1d.KKT[58]*source[189]+work1d.KKT[377]*source[349]+work1d.KKT[378]*source[126];
  result[350] = work1d.KKT[60]*source[190]+work1d.KKT[379]*source[350]+work1d.KKT[380]*source[129];
  result[351] = work1d.KKT[62]*source[191]+work1d.KKT[381]*source[351]+work1d.KKT[382]*source[132];
  result[352] = work1d.KKT[64]*source[192]+work1d.KKT[383]*source[352]+work1d.KKT[384]*source[135];
  result[353] = work1d.KKT[66]*source[193]+work1d.KKT[385]*source[353]+work1d.KKT[386]*source[138];
  result[354] = work1d.KKT[68]*source[194]+work1d.KKT[387]*source[354]+work1d.KKT[388]*source[141];
  result[355] = work1d.KKT[70]*source[195]+work1d.KKT[389]*source[355]+work1d.KKT[390]*source[144];
  result[356] = work1d.KKT[72]*source[196]+work1d.KKT[391]*source[356]+work1d.KKT[392]*source[147];
  result[357] = work1d.KKT[74]*source[197]+work1d.KKT[393]*source[357]+work1d.KKT[394]*source[150];
  result[358] = work1d.KKT[76]*source[198]+work1d.KKT[395]*source[358]+work1d.KKT[396]*source[153];
  result[359] = work1d.KKT[78]*source[199]+work1d.KKT[397]*source[359]+work1d.KKT[398]*source[156];
  result[360] = work1d.KKT[80]*source[200]+work1d.KKT[399]*source[360]+work1d.KKT[400]*source[159];
  result[361] = work1d.KKT[82]*source[201]+work1d.KKT[401]*source[361]+work1d.KKT[402]*source[43];
  result[362] = work1d.KKT[84]*source[202]+work1d.KKT[403]*source[362]+work1d.KKT[404]*source[46];
  result[363] = work1d.KKT[86]*source[203]+work1d.KKT[405]*source[363]+work1d.KKT[406]*source[49];
  result[364] = work1d.KKT[88]*source[204]+work1d.KKT[407]*source[364]+work1d.KKT[408]*source[52];
  result[365] = work1d.KKT[90]*source[205]+work1d.KKT[409]*source[365]+work1d.KKT[410]*source[55];
  result[366] = work1d.KKT[92]*source[206]+work1d.KKT[411]*source[366]+work1d.KKT[412]*source[58];
  result[367] = work1d.KKT[94]*source[207]+work1d.KKT[413]*source[367]+work1d.KKT[414]*source[61];
  result[368] = work1d.KKT[96]*source[208]+work1d.KKT[415]*source[368]+work1d.KKT[416]*source[64];
  result[369] = work1d.KKT[98]*source[209]+work1d.KKT[417]*source[369]+work1d.KKT[418]*source[67];
  result[370] = work1d.KKT[100]*source[210]+work1d.KKT[419]*source[370]+work1d.KKT[420]*source[70];
  result[371] = work1d.KKT[102]*source[211]+work1d.KKT[421]*source[371]+work1d.KKT[422]*source[73];
  result[372] = work1d.KKT[104]*source[212]+work1d.KKT[423]*source[372]+work1d.KKT[424]*source[76];
  result[373] = work1d.KKT[106]*source[213]+work1d.KKT[425]*source[373]+work1d.KKT[426]*source[79];
  result[374] = work1d.KKT[108]*source[214]+work1d.KKT[427]*source[374]+work1d.KKT[428]*source[82];
  result[375] = work1d.KKT[110]*source[215]+work1d.KKT[429]*source[375]+work1d.KKT[430]*source[85];
  result[376] = work1d.KKT[112]*source[216]+work1d.KKT[431]*source[376]+work1d.KKT[432]*source[88];
  result[377] = work1d.KKT[114]*source[217]+work1d.KKT[433]*source[377]+work1d.KKT[434]*source[91];
  result[378] = work1d.KKT[116]*source[218]+work1d.KKT[435]*source[378]+work1d.KKT[436]*source[94];
  result[379] = work1d.KKT[118]*source[219]+work1d.KKT[437]*source[379]+work1d.KKT[438]*source[97];
  result[380] = work1d.KKT[120]*source[220]+work1d.KKT[439]*source[380]+work1d.KKT[440]*source[100];
  result[381] = work1d.KKT[122]*source[221]+work1d.KKT[441]*source[381]+work1d.KKT[442]*source[103];
  result[382] = work1d.KKT[124]*source[222]+work1d.KKT[443]*source[382]+work1d.KKT[444]*source[106];
  result[383] = work1d.KKT[126]*source[223]+work1d.KKT[445]*source[383]+work1d.KKT[446]*source[109];
  result[384] = work1d.KKT[128]*source[224]+work1d.KKT[447]*source[384]+work1d.KKT[448]*source[112];
  result[385] = work1d.KKT[130]*source[225]+work1d.KKT[449]*source[385]+work1d.KKT[450]*source[115];
  result[386] = work1d.KKT[132]*source[226]+work1d.KKT[451]*source[386]+work1d.KKT[452]*source[118];
  result[387] = work1d.KKT[134]*source[227]+work1d.KKT[453]*source[387]+work1d.KKT[454]*source[121];
  result[388] = work1d.KKT[136]*source[228]+work1d.KKT[455]*source[388]+work1d.KKT[456]*source[124];
  result[389] = work1d.KKT[138]*source[229]+work1d.KKT[457]*source[389]+work1d.KKT[458]*source[127];
  result[390] = work1d.KKT[140]*source[230]+work1d.KKT[459]*source[390]+work1d.KKT[460]*source[130];
  result[391] = work1d.KKT[142]*source[231]+work1d.KKT[461]*source[391]+work1d.KKT[462]*source[133];
  result[392] = work1d.KKT[144]*source[232]+work1d.KKT[463]*source[392]+work1d.KKT[464]*source[136];
  result[393] = work1d.KKT[146]*source[233]+work1d.KKT[465]*source[393]+work1d.KKT[466]*source[139];
  result[394] = work1d.KKT[148]*source[234]+work1d.KKT[467]*source[394]+work1d.KKT[468]*source[142];
  result[395] = work1d.KKT[150]*source[235]+work1d.KKT[469]*source[395]+work1d.KKT[470]*source[145];
  result[396] = work1d.KKT[152]*source[236]+work1d.KKT[471]*source[396]+work1d.KKT[472]*source[148];
  result[397] = work1d.KKT[154]*source[237]+work1d.KKT[473]*source[397]+work1d.KKT[474]*source[151];
  result[398] = work1d.KKT[156]*source[238]+work1d.KKT[475]*source[398]+work1d.KKT[476]*source[154];
  result[399] = work1d.KKT[158]*source[239]+work1d.KKT[477]*source[399]+work1d.KKT[478]*source[157];
  result[400] = work1d.KKT[160]*source[240]+work1d.KKT[479]*source[400]+work1d.KKT[480]*source[160];
  result[401] = work1d.KKT[162]*source[241]+work1d.KKT[481]*source[401]+work1d.KKT[482]*source[42];
  result[402] = work1d.KKT[164]*source[242]+work1d.KKT[483]*source[402]+work1d.KKT[484]*source[45];
  result[403] = work1d.KKT[166]*source[243]+work1d.KKT[485]*source[403]+work1d.KKT[486]*source[48];
  result[404] = work1d.KKT[168]*source[244]+work1d.KKT[487]*source[404]+work1d.KKT[488]*source[51];
  result[405] = work1d.KKT[170]*source[245]+work1d.KKT[489]*source[405]+work1d.KKT[490]*source[54];
  result[406] = work1d.KKT[172]*source[246]+work1d.KKT[491]*source[406]+work1d.KKT[492]*source[57];
  result[407] = work1d.KKT[174]*source[247]+work1d.KKT[493]*source[407]+work1d.KKT[494]*source[60];
  result[408] = work1d.KKT[176]*source[248]+work1d.KKT[495]*source[408]+work1d.KKT[496]*source[63];
  result[409] = work1d.KKT[178]*source[249]+work1d.KKT[497]*source[409]+work1d.KKT[498]*source[66];
  result[410] = work1d.KKT[180]*source[250]+work1d.KKT[499]*source[410]+work1d.KKT[500]*source[69];
  result[411] = work1d.KKT[182]*source[251]+work1d.KKT[501]*source[411]+work1d.KKT[502]*source[72];
  result[412] = work1d.KKT[184]*source[252]+work1d.KKT[503]*source[412]+work1d.KKT[504]*source[75];
  result[413] = work1d.KKT[186]*source[253]+work1d.KKT[505]*source[413]+work1d.KKT[506]*source[78];
  result[414] = work1d.KKT[188]*source[254]+work1d.KKT[507]*source[414]+work1d.KKT[508]*source[81];
  result[415] = work1d.KKT[190]*source[255]+work1d.KKT[509]*source[415]+work1d.KKT[510]*source[84];
  result[416] = work1d.KKT[192]*source[256]+work1d.KKT[511]*source[416]+work1d.KKT[512]*source[87];
  result[417] = work1d.KKT[194]*source[257]+work1d.KKT[513]*source[417]+work1d.KKT[514]*source[90];
  result[418] = work1d.KKT[196]*source[258]+work1d.KKT[515]*source[418]+work1d.KKT[516]*source[93];
  result[419] = work1d.KKT[198]*source[259]+work1d.KKT[517]*source[419]+work1d.KKT[518]*source[96];
  result[420] = work1d.KKT[200]*source[260]+work1d.KKT[519]*source[420]+work1d.KKT[520]*source[99];
  result[421] = work1d.KKT[202]*source[261]+work1d.KKT[521]*source[421]+work1d.KKT[522]*source[102];
  result[422] = work1d.KKT[204]*source[262]+work1d.KKT[523]*source[422]+work1d.KKT[524]*source[105];
  result[423] = work1d.KKT[206]*source[263]+work1d.KKT[525]*source[423]+work1d.KKT[526]*source[108];
  result[424] = work1d.KKT[208]*source[264]+work1d.KKT[527]*source[424]+work1d.KKT[528]*source[111];
  result[425] = work1d.KKT[210]*source[265]+work1d.KKT[529]*source[425]+work1d.KKT[530]*source[114];
  result[426] = work1d.KKT[212]*source[266]+work1d.KKT[531]*source[426]+work1d.KKT[532]*source[117];
  result[427] = work1d.KKT[214]*source[267]+work1d.KKT[533]*source[427]+work1d.KKT[534]*source[120];
  result[428] = work1d.KKT[216]*source[268]+work1d.KKT[535]*source[428]+work1d.KKT[536]*source[123];
  result[429] = work1d.KKT[218]*source[269]+work1d.KKT[537]*source[429]+work1d.KKT[538]*source[126];
  result[430] = work1d.KKT[220]*source[270]+work1d.KKT[539]*source[430]+work1d.KKT[540]*source[129];
  result[431] = work1d.KKT[222]*source[271]+work1d.KKT[541]*source[431]+work1d.KKT[542]*source[132];
  result[432] = work1d.KKT[224]*source[272]+work1d.KKT[543]*source[432]+work1d.KKT[544]*source[135];
  result[433] = work1d.KKT[226]*source[273]+work1d.KKT[545]*source[433]+work1d.KKT[546]*source[138];
  result[434] = work1d.KKT[228]*source[274]+work1d.KKT[547]*source[434]+work1d.KKT[548]*source[141];
  result[435] = work1d.KKT[230]*source[275]+work1d.KKT[549]*source[435]+work1d.KKT[550]*source[144];
  result[436] = work1d.KKT[232]*source[276]+work1d.KKT[551]*source[436]+work1d.KKT[552]*source[147];
  result[437] = work1d.KKT[234]*source[277]+work1d.KKT[553]*source[437]+work1d.KKT[554]*source[150];
  result[438] = work1d.KKT[236]*source[278]+work1d.KKT[555]*source[438]+work1d.KKT[556]*source[153];
  result[439] = work1d.KKT[238]*source[279]+work1d.KKT[557]*source[439]+work1d.KKT[558]*source[156];
  result[440] = work1d.KKT[240]*source[280]+work1d.KKT[559]*source[440]+work1d.KKT[560]*source[159];
  result[441] = work1d.KKT[242]*source[281]+work1d.KKT[561]*source[441]+work1d.KKT[562]*source[43];
  result[442] = work1d.KKT[244]*source[282]+work1d.KKT[563]*source[442]+work1d.KKT[564]*source[46];
  result[443] = work1d.KKT[246]*source[283]+work1d.KKT[565]*source[443]+work1d.KKT[566]*source[49];
  result[444] = work1d.KKT[248]*source[284]+work1d.KKT[567]*source[444]+work1d.KKT[568]*source[52];
  result[445] = work1d.KKT[250]*source[285]+work1d.KKT[569]*source[445]+work1d.KKT[570]*source[55];
  result[446] = work1d.KKT[252]*source[286]+work1d.KKT[571]*source[446]+work1d.KKT[572]*source[58];
  result[447] = work1d.KKT[254]*source[287]+work1d.KKT[573]*source[447]+work1d.KKT[574]*source[61];
  result[448] = work1d.KKT[256]*source[288]+work1d.KKT[575]*source[448]+work1d.KKT[576]*source[64];
  result[449] = work1d.KKT[258]*source[289]+work1d.KKT[577]*source[449]+work1d.KKT[578]*source[67];
  result[450] = work1d.KKT[260]*source[290]+work1d.KKT[579]*source[450]+work1d.KKT[580]*source[70];
  result[451] = work1d.KKT[262]*source[291]+work1d.KKT[581]*source[451]+work1d.KKT[582]*source[73];
  result[452] = work1d.KKT[264]*source[292]+work1d.KKT[583]*source[452]+work1d.KKT[584]*source[76];
  result[453] = work1d.KKT[266]*source[293]+work1d.KKT[585]*source[453]+work1d.KKT[586]*source[79];
  result[454] = work1d.KKT[268]*source[294]+work1d.KKT[587]*source[454]+work1d.KKT[588]*source[82];
  result[455] = work1d.KKT[270]*source[295]+work1d.KKT[589]*source[455]+work1d.KKT[590]*source[85];
  result[456] = work1d.KKT[272]*source[296]+work1d.KKT[591]*source[456]+work1d.KKT[592]*source[88];
  result[457] = work1d.KKT[274]*source[297]+work1d.KKT[593]*source[457]+work1d.KKT[594]*source[91];
  result[458] = work1d.KKT[276]*source[298]+work1d.KKT[595]*source[458]+work1d.KKT[596]*source[94];
  result[459] = work1d.KKT[278]*source[299]+work1d.KKT[597]*source[459]+work1d.KKT[598]*source[97];
  result[460] = work1d.KKT[280]*source[300]+work1d.KKT[599]*source[460]+work1d.KKT[600]*source[100];
  result[461] = work1d.KKT[282]*source[301]+work1d.KKT[601]*source[461]+work1d.KKT[602]*source[103];
  result[462] = work1d.KKT[284]*source[302]+work1d.KKT[603]*source[462]+work1d.KKT[604]*source[106];
  result[463] = work1d.KKT[286]*source[303]+work1d.KKT[605]*source[463]+work1d.KKT[606]*source[109];
  result[464] = work1d.KKT[288]*source[304]+work1d.KKT[607]*source[464]+work1d.KKT[608]*source[112];
  result[465] = work1d.KKT[290]*source[305]+work1d.KKT[609]*source[465]+work1d.KKT[610]*source[115];
  result[466] = work1d.KKT[292]*source[306]+work1d.KKT[611]*source[466]+work1d.KKT[612]*source[118];
  result[467] = work1d.KKT[294]*source[307]+work1d.KKT[613]*source[467]+work1d.KKT[614]*source[121];
  result[468] = work1d.KKT[296]*source[308]+work1d.KKT[615]*source[468]+work1d.KKT[616]*source[124];
  result[469] = work1d.KKT[298]*source[309]+work1d.KKT[617]*source[469]+work1d.KKT[618]*source[127];
  result[470] = work1d.KKT[300]*source[310]+work1d.KKT[619]*source[470]+work1d.KKT[620]*source[130];
  result[471] = work1d.KKT[302]*source[311]+work1d.KKT[621]*source[471]+work1d.KKT[622]*source[133];
  result[472] = work1d.KKT[304]*source[312]+work1d.KKT[623]*source[472]+work1d.KKT[624]*source[136];
  result[473] = work1d.KKT[306]*source[313]+work1d.KKT[625]*source[473]+work1d.KKT[626]*source[139];
  result[474] = work1d.KKT[308]*source[314]+work1d.KKT[627]*source[474]+work1d.KKT[628]*source[142];
  result[475] = work1d.KKT[310]*source[315]+work1d.KKT[629]*source[475]+work1d.KKT[630]*source[145];
  result[476] = work1d.KKT[312]*source[316]+work1d.KKT[631]*source[476]+work1d.KKT[632]*source[148];
  result[477] = work1d.KKT[314]*source[317]+work1d.KKT[633]*source[477]+work1d.KKT[634]*source[151];
  result[478] = work1d.KKT[316]*source[318]+work1d.KKT[635]*source[478]+work1d.KKT[636]*source[154];
  result[479] = work1d.KKT[318]*source[319]+work1d.KKT[637]*source[479]+work1d.KKT[638]*source[157];
  result[480] = work1d.KKT[320]*source[320]+work1d.KKT[639]*source[480]+work1d.KKT[640]*source[160];
  result[481] = work1d.KKT[641]*source[41];
  result[482] = work1d.KKT[642]*source[42];
  result[483] = work1d.KKT[643]*source[0]+work1d.KKT[644]*source[43];
  result[484] = work1d.KKT[727]*source[41]+work1d.KKT[735]*source[42]+work1d.KKT[736]*source[44];
  result[485] = work1d.KKT[816]*source[42]+work1d.KKT[818]*source[43]+work1d.KKT[931]*source[45];
  result[486] = work1d.KKT[646]*source[1]+work1d.KKT[737]*source[43]+work1d.KKT[738]*source[46];
  result[487] = work1d.KKT[820]*source[44]+work1d.KKT[933]*source[45]+work1d.KKT[822]*source[47];
  result[488] = work1d.KKT[934]*source[45]+work1d.KKT[936]*source[46]+work1d.KKT[937]*source[48];
  result[489] = work1d.KKT[648]*source[2]+work1d.KKT[739]*source[46]+work1d.KKT[740]*source[49];
  result[490] = work1d.KKT[823]*source[47]+work1d.KKT[939]*source[48]+work1d.KKT[825]*source[50];
  result[491] = work1d.KKT[940]*source[48]+work1d.KKT[942]*source[49]+work1d.KKT[943]*source[51];
  result[492] = work1d.KKT[650]*source[3]+work1d.KKT[741]*source[49]+work1d.KKT[742]*source[52];
  result[493] = work1d.KKT[826]*source[50]+work1d.KKT[945]*source[51]+work1d.KKT[828]*source[53];
  result[494] = work1d.KKT[946]*source[51]+work1d.KKT[948]*source[52]+work1d.KKT[949]*source[54];
  result[495] = work1d.KKT[652]*source[4]+work1d.KKT[743]*source[52]+work1d.KKT[744]*source[55];
  result[496] = work1d.KKT[829]*source[53]+work1d.KKT[951]*source[54]+work1d.KKT[831]*source[56];
  result[497] = work1d.KKT[952]*source[54]+work1d.KKT[954]*source[55]+work1d.KKT[955]*source[57];
  result[498] = work1d.KKT[654]*source[5]+work1d.KKT[745]*source[55]+work1d.KKT[746]*source[58];
  result[499] = work1d.KKT[832]*source[56]+work1d.KKT[957]*source[57]+work1d.KKT[834]*source[59];
  result[500] = work1d.KKT[958]*source[57]+work1d.KKT[960]*source[58]+work1d.KKT[961]*source[60];
  result[501] = work1d.KKT[656]*source[6]+work1d.KKT[747]*source[58]+work1d.KKT[748]*source[61];
  result[502] = work1d.KKT[835]*source[59]+work1d.KKT[963]*source[60]+work1d.KKT[837]*source[62];
  result[503] = work1d.KKT[964]*source[60]+work1d.KKT[966]*source[61]+work1d.KKT[967]*source[63];
  result[504] = work1d.KKT[658]*source[7]+work1d.KKT[749]*source[61]+work1d.KKT[750]*source[64];
  result[505] = work1d.KKT[838]*source[62]+work1d.KKT[969]*source[63]+work1d.KKT[840]*source[65];
  result[506] = work1d.KKT[970]*source[63]+work1d.KKT[972]*source[64]+work1d.KKT[973]*source[66];
  result[507] = work1d.KKT[660]*source[8]+work1d.KKT[751]*source[64]+work1d.KKT[752]*source[67];
  result[508] = work1d.KKT[841]*source[65]+work1d.KKT[975]*source[66]+work1d.KKT[843]*source[68];
  result[509] = work1d.KKT[976]*source[66]+work1d.KKT[978]*source[67]+work1d.KKT[979]*source[69];
  result[510] = work1d.KKT[662]*source[9]+work1d.KKT[753]*source[67]+work1d.KKT[754]*source[70];
  result[511] = work1d.KKT[844]*source[68]+work1d.KKT[981]*source[69]+work1d.KKT[846]*source[71];
  result[512] = work1d.KKT[982]*source[69]+work1d.KKT[984]*source[70]+work1d.KKT[985]*source[72];
  result[513] = work1d.KKT[664]*source[10]+work1d.KKT[755]*source[70]+work1d.KKT[756]*source[73];
  result[514] = work1d.KKT[847]*source[71]+work1d.KKT[987]*source[72]+work1d.KKT[849]*source[74];
  result[515] = work1d.KKT[988]*source[72]+work1d.KKT[990]*source[73]+work1d.KKT[991]*source[75];
  result[516] = work1d.KKT[666]*source[11]+work1d.KKT[757]*source[73]+work1d.KKT[758]*source[76];
  result[517] = work1d.KKT[850]*source[74]+work1d.KKT[993]*source[75]+work1d.KKT[852]*source[77];
  result[518] = work1d.KKT[994]*source[75]+work1d.KKT[996]*source[76]+work1d.KKT[997]*source[78];
  result[519] = work1d.KKT[668]*source[12]+work1d.KKT[759]*source[76]+work1d.KKT[760]*source[79];
  result[520] = work1d.KKT[853]*source[77]+work1d.KKT[999]*source[78]+work1d.KKT[855]*source[80];
  result[521] = work1d.KKT[1000]*source[78]+work1d.KKT[1002]*source[79]+work1d.KKT[1003]*source[81];
  result[522] = work1d.KKT[670]*source[13]+work1d.KKT[761]*source[79]+work1d.KKT[762]*source[82];
  result[523] = work1d.KKT[856]*source[80]+work1d.KKT[1005]*source[81]+work1d.KKT[858]*source[83];
  result[524] = work1d.KKT[1006]*source[81]+work1d.KKT[1008]*source[82]+work1d.KKT[1009]*source[84];
  result[525] = work1d.KKT[672]*source[14]+work1d.KKT[763]*source[82]+work1d.KKT[764]*source[85];
  result[526] = work1d.KKT[859]*source[83]+work1d.KKT[1011]*source[84]+work1d.KKT[861]*source[86];
  result[527] = work1d.KKT[1012]*source[84]+work1d.KKT[1014]*source[85]+work1d.KKT[1015]*source[87];
  result[528] = work1d.KKT[674]*source[15]+work1d.KKT[765]*source[85]+work1d.KKT[766]*source[88];
  result[529] = work1d.KKT[862]*source[86]+work1d.KKT[1017]*source[87]+work1d.KKT[864]*source[89];
  result[530] = work1d.KKT[1018]*source[87]+work1d.KKT[1020]*source[88]+work1d.KKT[1021]*source[90];
  result[531] = work1d.KKT[676]*source[16]+work1d.KKT[767]*source[88]+work1d.KKT[768]*source[91];
  result[532] = work1d.KKT[865]*source[89]+work1d.KKT[1023]*source[90]+work1d.KKT[867]*source[92];
  result[533] = work1d.KKT[1024]*source[90]+work1d.KKT[1026]*source[91]+work1d.KKT[1027]*source[93];
  result[534] = work1d.KKT[678]*source[17]+work1d.KKT[769]*source[91]+work1d.KKT[770]*source[94];
  result[535] = work1d.KKT[868]*source[92]+work1d.KKT[1029]*source[93]+work1d.KKT[870]*source[95];
  result[536] = work1d.KKT[1030]*source[93]+work1d.KKT[1032]*source[94]+work1d.KKT[1033]*source[96];
  result[537] = work1d.KKT[680]*source[18]+work1d.KKT[771]*source[94]+work1d.KKT[772]*source[97];
  result[538] = work1d.KKT[871]*source[95]+work1d.KKT[1035]*source[96]+work1d.KKT[873]*source[98];
  result[539] = work1d.KKT[1036]*source[96]+work1d.KKT[1038]*source[97]+work1d.KKT[1039]*source[99];
  result[540] = work1d.KKT[682]*source[19]+work1d.KKT[773]*source[97]+work1d.KKT[774]*source[100];
  result[541] = work1d.KKT[874]*source[98]+work1d.KKT[1041]*source[99]+work1d.KKT[876]*source[101];
  result[542] = work1d.KKT[1042]*source[99]+work1d.KKT[1044]*source[100]+work1d.KKT[1045]*source[102];
  result[543] = work1d.KKT[684]*source[20]+work1d.KKT[775]*source[100]+work1d.KKT[776]*source[103];
  result[544] = work1d.KKT[877]*source[101]+work1d.KKT[1047]*source[102]+work1d.KKT[879]*source[104];
  result[545] = work1d.KKT[1048]*source[102]+work1d.KKT[1050]*source[103]+work1d.KKT[1051]*source[105];
  result[546] = work1d.KKT[686]*source[21]+work1d.KKT[777]*source[103]+work1d.KKT[778]*source[106];
  result[547] = work1d.KKT[880]*source[104]+work1d.KKT[1053]*source[105]+work1d.KKT[882]*source[107];
  result[548] = work1d.KKT[1054]*source[105]+work1d.KKT[1056]*source[106]+work1d.KKT[1057]*source[108];
  result[549] = work1d.KKT[688]*source[22]+work1d.KKT[779]*source[106]+work1d.KKT[780]*source[109];
  result[550] = work1d.KKT[883]*source[107]+work1d.KKT[1059]*source[108]+work1d.KKT[885]*source[110];
  result[551] = work1d.KKT[1060]*source[108]+work1d.KKT[1062]*source[109]+work1d.KKT[1063]*source[111];
  result[552] = work1d.KKT[690]*source[23]+work1d.KKT[781]*source[109]+work1d.KKT[782]*source[112];
  result[553] = work1d.KKT[886]*source[110]+work1d.KKT[1065]*source[111]+work1d.KKT[888]*source[113];
  result[554] = work1d.KKT[1066]*source[111]+work1d.KKT[1068]*source[112]+work1d.KKT[1069]*source[114];
  result[555] = work1d.KKT[692]*source[24]+work1d.KKT[783]*source[112]+work1d.KKT[784]*source[115];
  result[556] = work1d.KKT[889]*source[113]+work1d.KKT[1071]*source[114]+work1d.KKT[891]*source[116];
  result[557] = work1d.KKT[1072]*source[114]+work1d.KKT[1074]*source[115]+work1d.KKT[1075]*source[117];
  result[558] = work1d.KKT[694]*source[25]+work1d.KKT[785]*source[115]+work1d.KKT[786]*source[118];
  result[559] = work1d.KKT[892]*source[116]+work1d.KKT[1077]*source[117]+work1d.KKT[894]*source[119];
  result[560] = work1d.KKT[1078]*source[117]+work1d.KKT[1080]*source[118]+work1d.KKT[1081]*source[120];
  result[561] = work1d.KKT[696]*source[26]+work1d.KKT[787]*source[118]+work1d.KKT[788]*source[121];
  result[562] = work1d.KKT[895]*source[119]+work1d.KKT[1083]*source[120]+work1d.KKT[897]*source[122];
  result[563] = work1d.KKT[1084]*source[120]+work1d.KKT[1086]*source[121]+work1d.KKT[1087]*source[123];
  result[564] = work1d.KKT[698]*source[27]+work1d.KKT[789]*source[121]+work1d.KKT[790]*source[124];
  result[565] = work1d.KKT[898]*source[122]+work1d.KKT[1089]*source[123]+work1d.KKT[900]*source[125];
  result[566] = work1d.KKT[1090]*source[123]+work1d.KKT[1092]*source[124]+work1d.KKT[1093]*source[126];
  result[567] = work1d.KKT[700]*source[28]+work1d.KKT[791]*source[124]+work1d.KKT[792]*source[127];
  result[568] = work1d.KKT[901]*source[125]+work1d.KKT[1095]*source[126]+work1d.KKT[903]*source[128];
  result[569] = work1d.KKT[1096]*source[126]+work1d.KKT[1098]*source[127]+work1d.KKT[1099]*source[129];
  result[570] = work1d.KKT[702]*source[29]+work1d.KKT[793]*source[127]+work1d.KKT[794]*source[130];
  result[571] = work1d.KKT[904]*source[128]+work1d.KKT[1101]*source[129]+work1d.KKT[906]*source[131];
  result[572] = work1d.KKT[1102]*source[129]+work1d.KKT[1104]*source[130]+work1d.KKT[1105]*source[132];
  result[573] = work1d.KKT[704]*source[30]+work1d.KKT[795]*source[130]+work1d.KKT[796]*source[133];
  result[574] = work1d.KKT[907]*source[131]+work1d.KKT[1107]*source[132]+work1d.KKT[909]*source[134];
  result[575] = work1d.KKT[1108]*source[132]+work1d.KKT[1110]*source[133]+work1d.KKT[1111]*source[135];
  result[576] = work1d.KKT[706]*source[31]+work1d.KKT[797]*source[133]+work1d.KKT[798]*source[136];
  result[577] = work1d.KKT[910]*source[134]+work1d.KKT[1113]*source[135]+work1d.KKT[912]*source[137];
  result[578] = work1d.KKT[1114]*source[135]+work1d.KKT[1116]*source[136]+work1d.KKT[1117]*source[138];
  result[579] = work1d.KKT[708]*source[32]+work1d.KKT[799]*source[136]+work1d.KKT[800]*source[139];
  result[580] = work1d.KKT[913]*source[137]+work1d.KKT[1119]*source[138]+work1d.KKT[915]*source[140];
  result[581] = work1d.KKT[1120]*source[138]+work1d.KKT[1122]*source[139]+work1d.KKT[1123]*source[141];
  result[582] = work1d.KKT[710]*source[33]+work1d.KKT[801]*source[139]+work1d.KKT[802]*source[142];
  result[583] = work1d.KKT[916]*source[140]+work1d.KKT[1125]*source[141]+work1d.KKT[918]*source[143];
  result[584] = work1d.KKT[1126]*source[141]+work1d.KKT[1128]*source[142]+work1d.KKT[1129]*source[144];
  result[585] = work1d.KKT[712]*source[34]+work1d.KKT[803]*source[142]+work1d.KKT[804]*source[145];
  result[586] = work1d.KKT[919]*source[143]+work1d.KKT[1131]*source[144]+work1d.KKT[921]*source[146];
  result[587] = work1d.KKT[1132]*source[144]+work1d.KKT[1134]*source[145]+work1d.KKT[1135]*source[147];
  result[588] = work1d.KKT[714]*source[35]+work1d.KKT[805]*source[145]+work1d.KKT[806]*source[148];
  result[589] = work1d.KKT[922]*source[146]+work1d.KKT[1137]*source[147]+work1d.KKT[924]*source[149];
  result[590] = work1d.KKT[1138]*source[147]+work1d.KKT[1140]*source[148]+work1d.KKT[1141]*source[150];
  result[591] = work1d.KKT[716]*source[36]+work1d.KKT[807]*source[148]+work1d.KKT[808]*source[151];
  result[592] = work1d.KKT[925]*source[149]+work1d.KKT[1143]*source[150]+work1d.KKT[927]*source[152];
  result[593] = work1d.KKT[1144]*source[150]+work1d.KKT[1146]*source[151]+work1d.KKT[1147]*source[153];
  result[594] = work1d.KKT[718]*source[37]+work1d.KKT[809]*source[151]+work1d.KKT[810]*source[154];
  result[595] = work1d.KKT[928]*source[152]+work1d.KKT[1148]*source[153]+work1d.KKT[930]*source[155];
  result[596] = work1d.KKT[1149]*source[153]+work1d.KKT[1150]*source[154]+work1d.KKT[1151]*source[156];
  result[597] = work1d.KKT[720]*source[38]+work1d.KKT[811]*source[154]+work1d.KKT[733]*source[157];
  result[598] = work1d.KKT[812]*source[155]+work1d.KKT[813]*source[156]+work1d.KKT[729]*source[158];
  result[599] = work1d.KKT[814]*source[156]+work1d.KKT[734]*source[157]+work1d.KKT[731]*source[159];
  result[600] = work1d.KKT[722]*source[39]+work1d.KKT[725]*source[157]+work1d.KKT[724]*source[160];
}
double check_residual1d(double *target, double *multiplicand) {
  /* Returns the squared 2-norm of lhs - A*rhs. */
  /* Reuses v to find the residual. */
  int i;
  double residual;
  residual = 0;
  matrix_multiply1d(work1d.v, multiplicand);
  for (i = 0; i < 161; i++) {
    residual += (target[i] - work1d.v[i])*(target[i] - work1d.v[i]);
  }
  return residual;
}
void fill_KKT1d(void) {
  work1d.KKT[645] = 2*params1d.R[0];
  work1d.KKT[647] = 2*params1d.R[0];
  work1d.KKT[649] = 2*params1d.R[0];
  work1d.KKT[651] = 2*params1d.R[0];
  work1d.KKT[653] = 2*params1d.R[0];
  work1d.KKT[655] = 2*params1d.R[0];
  work1d.KKT[657] = 2*params1d.R[0];
  work1d.KKT[659] = 2*params1d.R[0];
  work1d.KKT[661] = 2*params1d.R[0];
  work1d.KKT[663] = 2*params1d.R[0];
  work1d.KKT[665] = 2*params1d.R[0];
  work1d.KKT[667] = 2*params1d.R[0];
  work1d.KKT[669] = 2*params1d.R[0];
  work1d.KKT[671] = 2*params1d.R[0];
  work1d.KKT[673] = 2*params1d.R[0];
  work1d.KKT[675] = 2*params1d.R[0];
  work1d.KKT[677] = 2*params1d.R[0];
  work1d.KKT[679] = 2*params1d.R[0];
  work1d.KKT[681] = 2*params1d.R[0];
  work1d.KKT[683] = 2*params1d.R[0];
  work1d.KKT[685] = 2*params1d.R[0];
  work1d.KKT[687] = 2*params1d.R[0];
  work1d.KKT[689] = 2*params1d.R[0];
  work1d.KKT[691] = 2*params1d.R[0];
  work1d.KKT[693] = 2*params1d.R[0];
  work1d.KKT[695] = 2*params1d.R[0];
  work1d.KKT[697] = 2*params1d.R[0];
  work1d.KKT[699] = 2*params1d.R[0];
  work1d.KKT[701] = 2*params1d.R[0];
  work1d.KKT[703] = 2*params1d.R[0];
  work1d.KKT[705] = 2*params1d.R[0];
  work1d.KKT[707] = 2*params1d.R[0];
  work1d.KKT[709] = 2*params1d.R[0];
  work1d.KKT[711] = 2*params1d.R[0];
  work1d.KKT[713] = 2*params1d.R[0];
  work1d.KKT[715] = 2*params1d.R[0];
  work1d.KKT[717] = 2*params1d.R[0];
  work1d.KKT[719] = 2*params1d.R[0];
  work1d.KKT[721] = 2*params1d.R[0];
  work1d.KKT[0] = 2*params1d.R[0];
  work1d.KKT[726] = 2*params1d.Q[0];
  work1d.KKT[815] = 2*params1d.Q[1];
  work1d.KKT[817] = 2*params1d.Q[2];
  work1d.KKT[819] = 2*params1d.Q[0];
  work1d.KKT[932] = 2*params1d.Q[1];
  work1d.KKT[935] = 2*params1d.Q[2];
  work1d.KKT[821] = 2*params1d.Q[0];
  work1d.KKT[938] = 2*params1d.Q[1];
  work1d.KKT[941] = 2*params1d.Q[2];
  work1d.KKT[824] = 2*params1d.Q[0];
  work1d.KKT[944] = 2*params1d.Q[1];
  work1d.KKT[947] = 2*params1d.Q[2];
  work1d.KKT[827] = 2*params1d.Q[0];
  work1d.KKT[950] = 2*params1d.Q[1];
  work1d.KKT[953] = 2*params1d.Q[2];
  work1d.KKT[830] = 2*params1d.Q[0];
  work1d.KKT[956] = 2*params1d.Q[1];
  work1d.KKT[959] = 2*params1d.Q[2];
  work1d.KKT[833] = 2*params1d.Q[0];
  work1d.KKT[962] = 2*params1d.Q[1];
  work1d.KKT[965] = 2*params1d.Q[2];
  work1d.KKT[836] = 2*params1d.Q[0];
  work1d.KKT[968] = 2*params1d.Q[1];
  work1d.KKT[971] = 2*params1d.Q[2];
  work1d.KKT[839] = 2*params1d.Q[0];
  work1d.KKT[974] = 2*params1d.Q[1];
  work1d.KKT[977] = 2*params1d.Q[2];
  work1d.KKT[842] = 2*params1d.Q[0];
  work1d.KKT[980] = 2*params1d.Q[1];
  work1d.KKT[983] = 2*params1d.Q[2];
  work1d.KKT[845] = 2*params1d.Q[0];
  work1d.KKT[986] = 2*params1d.Q[1];
  work1d.KKT[989] = 2*params1d.Q[2];
  work1d.KKT[848] = 2*params1d.Q[0];
  work1d.KKT[992] = 2*params1d.Q[1];
  work1d.KKT[995] = 2*params1d.Q[2];
  work1d.KKT[851] = 2*params1d.Q[0];
  work1d.KKT[998] = 2*params1d.Q[1];
  work1d.KKT[1001] = 2*params1d.Q[2];
  work1d.KKT[854] = 2*params1d.Q[0];
  work1d.KKT[1004] = 2*params1d.Q[1];
  work1d.KKT[1007] = 2*params1d.Q[2];
  work1d.KKT[857] = 2*params1d.Q[0];
  work1d.KKT[1010] = 2*params1d.Q[1];
  work1d.KKT[1013] = 2*params1d.Q[2];
  work1d.KKT[860] = 2*params1d.Q[0];
  work1d.KKT[1016] = 2*params1d.Q[1];
  work1d.KKT[1019] = 2*params1d.Q[2];
  work1d.KKT[863] = 2*params1d.Q[0];
  work1d.KKT[1022] = 2*params1d.Q[1];
  work1d.KKT[1025] = 2*params1d.Q[2];
  work1d.KKT[866] = 2*params1d.Q[0];
  work1d.KKT[1028] = 2*params1d.Q[1];
  work1d.KKT[1031] = 2*params1d.Q[2];
  work1d.KKT[869] = 2*params1d.Q[0];
  work1d.KKT[1034] = 2*params1d.Q[1];
  work1d.KKT[1037] = 2*params1d.Q[2];
  work1d.KKT[872] = 2*params1d.Q[0];
  work1d.KKT[1040] = 2*params1d.Q[1];
  work1d.KKT[1043] = 2*params1d.Q[2];
  work1d.KKT[875] = 2*params1d.Q[0];
  work1d.KKT[1046] = 2*params1d.Q[1];
  work1d.KKT[1049] = 2*params1d.Q[2];
  work1d.KKT[878] = 2*params1d.Q[0];
  work1d.KKT[1052] = 2*params1d.Q[1];
  work1d.KKT[1055] = 2*params1d.Q[2];
  work1d.KKT[881] = 2*params1d.Q[0];
  work1d.KKT[1058] = 2*params1d.Q[1];
  work1d.KKT[1061] = 2*params1d.Q[2];
  work1d.KKT[884] = 2*params1d.Q[0];
  work1d.KKT[1064] = 2*params1d.Q[1];
  work1d.KKT[1067] = 2*params1d.Q[2];
  work1d.KKT[887] = 2*params1d.Q[0];
  work1d.KKT[1070] = 2*params1d.Q[1];
  work1d.KKT[1073] = 2*params1d.Q[2];
  work1d.KKT[890] = 2*params1d.Q[0];
  work1d.KKT[1076] = 2*params1d.Q[1];
  work1d.KKT[1079] = 2*params1d.Q[2];
  work1d.KKT[893] = 2*params1d.Q[0];
  work1d.KKT[1082] = 2*params1d.Q[1];
  work1d.KKT[1085] = 2*params1d.Q[2];
  work1d.KKT[896] = 2*params1d.Q[0];
  work1d.KKT[1088] = 2*params1d.Q[1];
  work1d.KKT[1091] = 2*params1d.Q[2];
  work1d.KKT[899] = 2*params1d.Q[0];
  work1d.KKT[1094] = 2*params1d.Q[1];
  work1d.KKT[1097] = 2*params1d.Q[2];
  work1d.KKT[902] = 2*params1d.Q[0];
  work1d.KKT[1100] = 2*params1d.Q[1];
  work1d.KKT[1103] = 2*params1d.Q[2];
  work1d.KKT[905] = 2*params1d.Q[0];
  work1d.KKT[1106] = 2*params1d.Q[1];
  work1d.KKT[1109] = 2*params1d.Q[2];
  work1d.KKT[908] = 2*params1d.Q[0];
  work1d.KKT[1112] = 2*params1d.Q[1];
  work1d.KKT[1115] = 2*params1d.Q[2];
  work1d.KKT[911] = 2*params1d.Q[0];
  work1d.KKT[1118] = 2*params1d.Q[1];
  work1d.KKT[1121] = 2*params1d.Q[2];
  work1d.KKT[914] = 2*params1d.Q[0];
  work1d.KKT[1124] = 2*params1d.Q[1];
  work1d.KKT[1127] = 2*params1d.Q[2];
  work1d.KKT[917] = 2*params1d.Q[0];
  work1d.KKT[1130] = 2*params1d.Q[1];
  work1d.KKT[1133] = 2*params1d.Q[2];
  work1d.KKT[920] = 2*params1d.Q[0];
  work1d.KKT[1136] = 2*params1d.Q[1];
  work1d.KKT[1139] = 2*params1d.Q[2];
  work1d.KKT[923] = 2*params1d.Q[0];
  work1d.KKT[1142] = 2*params1d.Q[1];
  work1d.KKT[1145] = 2*params1d.Q[2];
  work1d.KKT[926] = 2*params1d.Q[0];
  work1d.KKT[1152] = 2*params1d.Q[1];
  work1d.KKT[1153] = 2*params1d.Q[2];
  work1d.KKT[929] = 2*params1d.Q[0];
  work1d.KKT[1154] = 2*params1d.Q[1];
  work1d.KKT[732] = 2*params1d.Q[2];
  work1d.KKT[728] = 2*params1d.Q[0];
  work1d.KKT[730] = 2*params1d.Q[1];
  work1d.KKT[723] = 2*params1d.Q[2];
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
  work1d.KKT[321] = work1d.block_33[0];
  work1d.KKT[323] = work1d.block_33[0];
  work1d.KKT[325] = work1d.block_33[0];
  work1d.KKT[327] = work1d.block_33[0];
  work1d.KKT[329] = work1d.block_33[0];
  work1d.KKT[331] = work1d.block_33[0];
  work1d.KKT[333] = work1d.block_33[0];
  work1d.KKT[335] = work1d.block_33[0];
  work1d.KKT[337] = work1d.block_33[0];
  work1d.KKT[339] = work1d.block_33[0];
  work1d.KKT[341] = work1d.block_33[0];
  work1d.KKT[343] = work1d.block_33[0];
  work1d.KKT[345] = work1d.block_33[0];
  work1d.KKT[347] = work1d.block_33[0];
  work1d.KKT[349] = work1d.block_33[0];
  work1d.KKT[351] = work1d.block_33[0];
  work1d.KKT[353] = work1d.block_33[0];
  work1d.KKT[355] = work1d.block_33[0];
  work1d.KKT[357] = work1d.block_33[0];
  work1d.KKT[359] = work1d.block_33[0];
  work1d.KKT[361] = work1d.block_33[0];
  work1d.KKT[363] = work1d.block_33[0];
  work1d.KKT[365] = work1d.block_33[0];
  work1d.KKT[367] = work1d.block_33[0];
  work1d.KKT[369] = work1d.block_33[0];
  work1d.KKT[371] = work1d.block_33[0];
  work1d.KKT[373] = work1d.block_33[0];
  work1d.KKT[375] = work1d.block_33[0];
  work1d.KKT[377] = work1d.block_33[0];
  work1d.KKT[379] = work1d.block_33[0];
  work1d.KKT[381] = work1d.block_33[0];
  work1d.KKT[383] = work1d.block_33[0];
  work1d.KKT[385] = work1d.block_33[0];
  work1d.KKT[387] = work1d.block_33[0];
  work1d.KKT[389] = work1d.block_33[0];
  work1d.KKT[391] = work1d.block_33[0];
  work1d.KKT[393] = work1d.block_33[0];
  work1d.KKT[395] = work1d.block_33[0];
  work1d.KKT[397] = work1d.block_33[0];
  work1d.KKT[399] = work1d.block_33[0];
  work1d.KKT[401] = work1d.block_33[0];
  work1d.KKT[403] = work1d.block_33[0];
  work1d.KKT[405] = work1d.block_33[0];
  work1d.KKT[407] = work1d.block_33[0];
  work1d.KKT[409] = work1d.block_33[0];
  work1d.KKT[411] = work1d.block_33[0];
  work1d.KKT[413] = work1d.block_33[0];
  work1d.KKT[415] = work1d.block_33[0];
  work1d.KKT[417] = work1d.block_33[0];
  work1d.KKT[419] = work1d.block_33[0];
  work1d.KKT[421] = work1d.block_33[0];
  work1d.KKT[423] = work1d.block_33[0];
  work1d.KKT[425] = work1d.block_33[0];
  work1d.KKT[427] = work1d.block_33[0];
  work1d.KKT[429] = work1d.block_33[0];
  work1d.KKT[431] = work1d.block_33[0];
  work1d.KKT[433] = work1d.block_33[0];
  work1d.KKT[435] = work1d.block_33[0];
  work1d.KKT[437] = work1d.block_33[0];
  work1d.KKT[439] = work1d.block_33[0];
  work1d.KKT[441] = work1d.block_33[0];
  work1d.KKT[443] = work1d.block_33[0];
  work1d.KKT[445] = work1d.block_33[0];
  work1d.KKT[447] = work1d.block_33[0];
  work1d.KKT[449] = work1d.block_33[0];
  work1d.KKT[451] = work1d.block_33[0];
  work1d.KKT[453] = work1d.block_33[0];
  work1d.KKT[455] = work1d.block_33[0];
  work1d.KKT[457] = work1d.block_33[0];
  work1d.KKT[459] = work1d.block_33[0];
  work1d.KKT[461] = work1d.block_33[0];
  work1d.KKT[463] = work1d.block_33[0];
  work1d.KKT[465] = work1d.block_33[0];
  work1d.KKT[467] = work1d.block_33[0];
  work1d.KKT[469] = work1d.block_33[0];
  work1d.KKT[471] = work1d.block_33[0];
  work1d.KKT[473] = work1d.block_33[0];
  work1d.KKT[475] = work1d.block_33[0];
  work1d.KKT[477] = work1d.block_33[0];
  work1d.KKT[479] = work1d.block_33[0];
  work1d.KKT[481] = work1d.block_33[0];
  work1d.KKT[483] = work1d.block_33[0];
  work1d.KKT[485] = work1d.block_33[0];
  work1d.KKT[487] = work1d.block_33[0];
  work1d.KKT[489] = work1d.block_33[0];
  work1d.KKT[491] = work1d.block_33[0];
  work1d.KKT[493] = work1d.block_33[0];
  work1d.KKT[495] = work1d.block_33[0];
  work1d.KKT[497] = work1d.block_33[0];
  work1d.KKT[499] = work1d.block_33[0];
  work1d.KKT[501] = work1d.block_33[0];
  work1d.KKT[503] = work1d.block_33[0];
  work1d.KKT[505] = work1d.block_33[0];
  work1d.KKT[507] = work1d.block_33[0];
  work1d.KKT[509] = work1d.block_33[0];
  work1d.KKT[511] = work1d.block_33[0];
  work1d.KKT[513] = work1d.block_33[0];
  work1d.KKT[515] = work1d.block_33[0];
  work1d.KKT[517] = work1d.block_33[0];
  work1d.KKT[519] = work1d.block_33[0];
  work1d.KKT[521] = work1d.block_33[0];
  work1d.KKT[523] = work1d.block_33[0];
  work1d.KKT[525] = work1d.block_33[0];
  work1d.KKT[527] = work1d.block_33[0];
  work1d.KKT[529] = work1d.block_33[0];
  work1d.KKT[531] = work1d.block_33[0];
  work1d.KKT[533] = work1d.block_33[0];
  work1d.KKT[535] = work1d.block_33[0];
  work1d.KKT[537] = work1d.block_33[0];
  work1d.KKT[539] = work1d.block_33[0];
  work1d.KKT[541] = work1d.block_33[0];
  work1d.KKT[543] = work1d.block_33[0];
  work1d.KKT[545] = work1d.block_33[0];
  work1d.KKT[547] = work1d.block_33[0];
  work1d.KKT[549] = work1d.block_33[0];
  work1d.KKT[551] = work1d.block_33[0];
  work1d.KKT[553] = work1d.block_33[0];
  work1d.KKT[555] = work1d.block_33[0];
  work1d.KKT[557] = work1d.block_33[0];
  work1d.KKT[559] = work1d.block_33[0];
  work1d.KKT[561] = work1d.block_33[0];
  work1d.KKT[563] = work1d.block_33[0];
  work1d.KKT[565] = work1d.block_33[0];
  work1d.KKT[567] = work1d.block_33[0];
  work1d.KKT[569] = work1d.block_33[0];
  work1d.KKT[571] = work1d.block_33[0];
  work1d.KKT[573] = work1d.block_33[0];
  work1d.KKT[575] = work1d.block_33[0];
  work1d.KKT[577] = work1d.block_33[0];
  work1d.KKT[579] = work1d.block_33[0];
  work1d.KKT[581] = work1d.block_33[0];
  work1d.KKT[583] = work1d.block_33[0];
  work1d.KKT[585] = work1d.block_33[0];
  work1d.KKT[587] = work1d.block_33[0];
  work1d.KKT[589] = work1d.block_33[0];
  work1d.KKT[591] = work1d.block_33[0];
  work1d.KKT[593] = work1d.block_33[0];
  work1d.KKT[595] = work1d.block_33[0];
  work1d.KKT[597] = work1d.block_33[0];
  work1d.KKT[599] = work1d.block_33[0];
  work1d.KKT[601] = work1d.block_33[0];
  work1d.KKT[603] = work1d.block_33[0];
  work1d.KKT[605] = work1d.block_33[0];
  work1d.KKT[607] = work1d.block_33[0];
  work1d.KKT[609] = work1d.block_33[0];
  work1d.KKT[611] = work1d.block_33[0];
  work1d.KKT[613] = work1d.block_33[0];
  work1d.KKT[615] = work1d.block_33[0];
  work1d.KKT[617] = work1d.block_33[0];
  work1d.KKT[619] = work1d.block_33[0];
  work1d.KKT[621] = work1d.block_33[0];
  work1d.KKT[623] = work1d.block_33[0];
  work1d.KKT[625] = work1d.block_33[0];
  work1d.KKT[627] = work1d.block_33[0];
  work1d.KKT[629] = work1d.block_33[0];
  work1d.KKT[631] = work1d.block_33[0];
  work1d.KKT[633] = work1d.block_33[0];
  work1d.KKT[635] = work1d.block_33[0];
  work1d.KKT[637] = work1d.block_33[0];
  work1d.KKT[639] = work1d.block_33[0];
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
  work1d.KKT[482] = -1;
  work1d.KKT[484] = -1;
  work1d.KKT[486] = -1;
  work1d.KKT[488] = -1;
  work1d.KKT[490] = -1;
  work1d.KKT[492] = -1;
  work1d.KKT[494] = -1;
  work1d.KKT[496] = -1;
  work1d.KKT[498] = -1;
  work1d.KKT[500] = -1;
  work1d.KKT[502] = -1;
  work1d.KKT[504] = -1;
  work1d.KKT[506] = -1;
  work1d.KKT[508] = -1;
  work1d.KKT[510] = -1;
  work1d.KKT[512] = -1;
  work1d.KKT[514] = -1;
  work1d.KKT[516] = -1;
  work1d.KKT[518] = -1;
  work1d.KKT[520] = -1;
  work1d.KKT[522] = -1;
  work1d.KKT[524] = -1;
  work1d.KKT[526] = -1;
  work1d.KKT[528] = -1;
  work1d.KKT[530] = -1;
  work1d.KKT[532] = -1;
  work1d.KKT[534] = -1;
  work1d.KKT[536] = -1;
  work1d.KKT[538] = -1;
  work1d.KKT[540] = -1;
  work1d.KKT[542] = -1;
  work1d.KKT[544] = -1;
  work1d.KKT[546] = -1;
  work1d.KKT[548] = -1;
  work1d.KKT[550] = -1;
  work1d.KKT[552] = -1;
  work1d.KKT[554] = -1;
  work1d.KKT[556] = -1;
  work1d.KKT[558] = -1;
  work1d.KKT[560] = -1;
  work1d.KKT[562] = -1;
  work1d.KKT[564] = -1;
  work1d.KKT[566] = -1;
  work1d.KKT[568] = -1;
  work1d.KKT[570] = -1;
  work1d.KKT[572] = -1;
  work1d.KKT[574] = -1;
  work1d.KKT[576] = -1;
  work1d.KKT[578] = -1;
  work1d.KKT[580] = -1;
  work1d.KKT[582] = -1;
  work1d.KKT[584] = -1;
  work1d.KKT[586] = -1;
  work1d.KKT[588] = -1;
  work1d.KKT[590] = -1;
  work1d.KKT[592] = -1;
  work1d.KKT[594] = -1;
  work1d.KKT[596] = -1;
  work1d.KKT[598] = -1;
  work1d.KKT[600] = -1;
  work1d.KKT[602] = -1;
  work1d.KKT[604] = -1;
  work1d.KKT[606] = -1;
  work1d.KKT[608] = -1;
  work1d.KKT[610] = -1;
  work1d.KKT[612] = -1;
  work1d.KKT[614] = -1;
  work1d.KKT[616] = -1;
  work1d.KKT[618] = -1;
  work1d.KKT[620] = -1;
  work1d.KKT[622] = -1;
  work1d.KKT[624] = -1;
  work1d.KKT[626] = -1;
  work1d.KKT[628] = -1;
  work1d.KKT[630] = -1;
  work1d.KKT[632] = -1;
  work1d.KKT[634] = -1;
  work1d.KKT[636] = -1;
  work1d.KKT[638] = -1;
  work1d.KKT[640] = -1;
  work1d.KKT[643] = -params1d.Bf[0];
  work1d.KKT[641] = 1;
  work1d.KKT[642] = 1;
  work1d.KKT[644] = 1;
  work1d.KKT[646] = -params1d.B[0];
  work1d.KKT[727] = -params1d.A[0];
  work1d.KKT[816] = -params1d.A[1];
  work1d.KKT[737] = -params1d.A[2];
  work1d.KKT[735] = -params1d.A[3];
  work1d.KKT[818] = -params1d.A[4];
  work1d.KKT[736] = 1;
  work1d.KKT[931] = 1;
  work1d.KKT[738] = 1;
  work1d.KKT[648] = -params1d.B[0];
  work1d.KKT[820] = -params1d.A[0];
  work1d.KKT[934] = -params1d.A[1];
  work1d.KKT[739] = -params1d.A[2];
  work1d.KKT[933] = -params1d.A[3];
  work1d.KKT[936] = -params1d.A[4];
  work1d.KKT[822] = 1;
  work1d.KKT[937] = 1;
  work1d.KKT[740] = 1;
  work1d.KKT[650] = -params1d.B[0];
  work1d.KKT[823] = -params1d.A[0];
  work1d.KKT[940] = -params1d.A[1];
  work1d.KKT[741] = -params1d.A[2];
  work1d.KKT[939] = -params1d.A[3];
  work1d.KKT[942] = -params1d.A[4];
  work1d.KKT[825] = 1;
  work1d.KKT[943] = 1;
  work1d.KKT[742] = 1;
  work1d.KKT[652] = -params1d.B[0];
  work1d.KKT[826] = -params1d.A[0];
  work1d.KKT[946] = -params1d.A[1];
  work1d.KKT[743] = -params1d.A[2];
  work1d.KKT[945] = -params1d.A[3];
  work1d.KKT[948] = -params1d.A[4];
  work1d.KKT[828] = 1;
  work1d.KKT[949] = 1;
  work1d.KKT[744] = 1;
  work1d.KKT[654] = -params1d.B[0];
  work1d.KKT[829] = -params1d.A[0];
  work1d.KKT[952] = -params1d.A[1];
  work1d.KKT[745] = -params1d.A[2];
  work1d.KKT[951] = -params1d.A[3];
  work1d.KKT[954] = -params1d.A[4];
  work1d.KKT[831] = 1;
  work1d.KKT[955] = 1;
  work1d.KKT[746] = 1;
  work1d.KKT[656] = -params1d.B[0];
  work1d.KKT[832] = -params1d.A[0];
  work1d.KKT[958] = -params1d.A[1];
  work1d.KKT[747] = -params1d.A[2];
  work1d.KKT[957] = -params1d.A[3];
  work1d.KKT[960] = -params1d.A[4];
  work1d.KKT[834] = 1;
  work1d.KKT[961] = 1;
  work1d.KKT[748] = 1;
  work1d.KKT[658] = -params1d.B[0];
  work1d.KKT[835] = -params1d.A[0];
  work1d.KKT[964] = -params1d.A[1];
  work1d.KKT[749] = -params1d.A[2];
  work1d.KKT[963] = -params1d.A[3];
  work1d.KKT[966] = -params1d.A[4];
  work1d.KKT[837] = 1;
  work1d.KKT[967] = 1;
  work1d.KKT[750] = 1;
  work1d.KKT[660] = -params1d.B[0];
  work1d.KKT[838] = -params1d.A[0];
  work1d.KKT[970] = -params1d.A[1];
  work1d.KKT[751] = -params1d.A[2];
  work1d.KKT[969] = -params1d.A[3];
  work1d.KKT[972] = -params1d.A[4];
  work1d.KKT[840] = 1;
  work1d.KKT[973] = 1;
  work1d.KKT[752] = 1;
  work1d.KKT[662] = -params1d.B[0];
  work1d.KKT[841] = -params1d.A[0];
  work1d.KKT[976] = -params1d.A[1];
  work1d.KKT[753] = -params1d.A[2];
  work1d.KKT[975] = -params1d.A[3];
  work1d.KKT[978] = -params1d.A[4];
  work1d.KKT[843] = 1;
  work1d.KKT[979] = 1;
  work1d.KKT[754] = 1;
  work1d.KKT[664] = -params1d.B[0];
  work1d.KKT[844] = -params1d.A[0];
  work1d.KKT[982] = -params1d.A[1];
  work1d.KKT[755] = -params1d.A[2];
  work1d.KKT[981] = -params1d.A[3];
  work1d.KKT[984] = -params1d.A[4];
  work1d.KKT[846] = 1;
  work1d.KKT[985] = 1;
  work1d.KKT[756] = 1;
  work1d.KKT[666] = -params1d.B[0];
  work1d.KKT[847] = -params1d.A[0];
  work1d.KKT[988] = -params1d.A[1];
  work1d.KKT[757] = -params1d.A[2];
  work1d.KKT[987] = -params1d.A[3];
  work1d.KKT[990] = -params1d.A[4];
  work1d.KKT[849] = 1;
  work1d.KKT[991] = 1;
  work1d.KKT[758] = 1;
  work1d.KKT[668] = -params1d.B[0];
  work1d.KKT[850] = -params1d.A[0];
  work1d.KKT[994] = -params1d.A[1];
  work1d.KKT[759] = -params1d.A[2];
  work1d.KKT[993] = -params1d.A[3];
  work1d.KKT[996] = -params1d.A[4];
  work1d.KKT[852] = 1;
  work1d.KKT[997] = 1;
  work1d.KKT[760] = 1;
  work1d.KKT[670] = -params1d.B[0];
  work1d.KKT[853] = -params1d.A[0];
  work1d.KKT[1000] = -params1d.A[1];
  work1d.KKT[761] = -params1d.A[2];
  work1d.KKT[999] = -params1d.A[3];
  work1d.KKT[1002] = -params1d.A[4];
  work1d.KKT[855] = 1;
  work1d.KKT[1003] = 1;
  work1d.KKT[762] = 1;
  work1d.KKT[672] = -params1d.B[0];
  work1d.KKT[856] = -params1d.A[0];
  work1d.KKT[1006] = -params1d.A[1];
  work1d.KKT[763] = -params1d.A[2];
  work1d.KKT[1005] = -params1d.A[3];
  work1d.KKT[1008] = -params1d.A[4];
  work1d.KKT[858] = 1;
  work1d.KKT[1009] = 1;
  work1d.KKT[764] = 1;
  work1d.KKT[674] = -params1d.B[0];
  work1d.KKT[859] = -params1d.A[0];
  work1d.KKT[1012] = -params1d.A[1];
  work1d.KKT[765] = -params1d.A[2];
  work1d.KKT[1011] = -params1d.A[3];
  work1d.KKT[1014] = -params1d.A[4];
  work1d.KKT[861] = 1;
  work1d.KKT[1015] = 1;
  work1d.KKT[766] = 1;
  work1d.KKT[676] = -params1d.B[0];
  work1d.KKT[862] = -params1d.A[0];
  work1d.KKT[1018] = -params1d.A[1];
  work1d.KKT[767] = -params1d.A[2];
  work1d.KKT[1017] = -params1d.A[3];
  work1d.KKT[1020] = -params1d.A[4];
  work1d.KKT[864] = 1;
  work1d.KKT[1021] = 1;
  work1d.KKT[768] = 1;
  work1d.KKT[678] = -params1d.B[0];
  work1d.KKT[865] = -params1d.A[0];
  work1d.KKT[1024] = -params1d.A[1];
  work1d.KKT[769] = -params1d.A[2];
  work1d.KKT[1023] = -params1d.A[3];
  work1d.KKT[1026] = -params1d.A[4];
  work1d.KKT[867] = 1;
  work1d.KKT[1027] = 1;
  work1d.KKT[770] = 1;
  work1d.KKT[680] = -params1d.B[0];
  work1d.KKT[868] = -params1d.A[0];
  work1d.KKT[1030] = -params1d.A[1];
  work1d.KKT[771] = -params1d.A[2];
  work1d.KKT[1029] = -params1d.A[3];
  work1d.KKT[1032] = -params1d.A[4];
  work1d.KKT[870] = 1;
  work1d.KKT[1033] = 1;
  work1d.KKT[772] = 1;
  work1d.KKT[682] = -params1d.B[0];
  work1d.KKT[871] = -params1d.A[0];
  work1d.KKT[1036] = -params1d.A[1];
  work1d.KKT[773] = -params1d.A[2];
  work1d.KKT[1035] = -params1d.A[3];
  work1d.KKT[1038] = -params1d.A[4];
  work1d.KKT[873] = 1;
  work1d.KKT[1039] = 1;
  work1d.KKT[774] = 1;
  work1d.KKT[684] = -params1d.B[0];
  work1d.KKT[874] = -params1d.A[0];
  work1d.KKT[1042] = -params1d.A[1];
  work1d.KKT[775] = -params1d.A[2];
  work1d.KKT[1041] = -params1d.A[3];
  work1d.KKT[1044] = -params1d.A[4];
  work1d.KKT[876] = 1;
  work1d.KKT[1045] = 1;
  work1d.KKT[776] = 1;
  work1d.KKT[686] = -params1d.B[0];
  work1d.KKT[877] = -params1d.A[0];
  work1d.KKT[1048] = -params1d.A[1];
  work1d.KKT[777] = -params1d.A[2];
  work1d.KKT[1047] = -params1d.A[3];
  work1d.KKT[1050] = -params1d.A[4];
  work1d.KKT[879] = 1;
  work1d.KKT[1051] = 1;
  work1d.KKT[778] = 1;
  work1d.KKT[688] = -params1d.B[0];
  work1d.KKT[880] = -params1d.A[0];
  work1d.KKT[1054] = -params1d.A[1];
  work1d.KKT[779] = -params1d.A[2];
  work1d.KKT[1053] = -params1d.A[3];
  work1d.KKT[1056] = -params1d.A[4];
  work1d.KKT[882] = 1;
  work1d.KKT[1057] = 1;
  work1d.KKT[780] = 1;
  work1d.KKT[690] = -params1d.B[0];
  work1d.KKT[883] = -params1d.A[0];
  work1d.KKT[1060] = -params1d.A[1];
  work1d.KKT[781] = -params1d.A[2];
  work1d.KKT[1059] = -params1d.A[3];
  work1d.KKT[1062] = -params1d.A[4];
  work1d.KKT[885] = 1;
  work1d.KKT[1063] = 1;
  work1d.KKT[782] = 1;
  work1d.KKT[692] = -params1d.B[0];
  work1d.KKT[886] = -params1d.A[0];
  work1d.KKT[1066] = -params1d.A[1];
  work1d.KKT[783] = -params1d.A[2];
  work1d.KKT[1065] = -params1d.A[3];
  work1d.KKT[1068] = -params1d.A[4];
  work1d.KKT[888] = 1;
  work1d.KKT[1069] = 1;
  work1d.KKT[784] = 1;
  work1d.KKT[694] = -params1d.B[0];
  work1d.KKT[889] = -params1d.A[0];
  work1d.KKT[1072] = -params1d.A[1];
  work1d.KKT[785] = -params1d.A[2];
  work1d.KKT[1071] = -params1d.A[3];
  work1d.KKT[1074] = -params1d.A[4];
  work1d.KKT[891] = 1;
  work1d.KKT[1075] = 1;
  work1d.KKT[786] = 1;
  work1d.KKT[696] = -params1d.B[0];
  work1d.KKT[892] = -params1d.A[0];
  work1d.KKT[1078] = -params1d.A[1];
  work1d.KKT[787] = -params1d.A[2];
  work1d.KKT[1077] = -params1d.A[3];
  work1d.KKT[1080] = -params1d.A[4];
  work1d.KKT[894] = 1;
  work1d.KKT[1081] = 1;
  work1d.KKT[788] = 1;
  work1d.KKT[698] = -params1d.B[0];
  work1d.KKT[895] = -params1d.A[0];
  work1d.KKT[1084] = -params1d.A[1];
  work1d.KKT[789] = -params1d.A[2];
  work1d.KKT[1083] = -params1d.A[3];
  work1d.KKT[1086] = -params1d.A[4];
  work1d.KKT[897] = 1;
  work1d.KKT[1087] = 1;
  work1d.KKT[790] = 1;
  work1d.KKT[700] = -params1d.B[0];
  work1d.KKT[898] = -params1d.A[0];
  work1d.KKT[1090] = -params1d.A[1];
  work1d.KKT[791] = -params1d.A[2];
  work1d.KKT[1089] = -params1d.A[3];
  work1d.KKT[1092] = -params1d.A[4];
  work1d.KKT[900] = 1;
  work1d.KKT[1093] = 1;
  work1d.KKT[792] = 1;
  work1d.KKT[702] = -params1d.B[0];
  work1d.KKT[901] = -params1d.A[0];
  work1d.KKT[1096] = -params1d.A[1];
  work1d.KKT[793] = -params1d.A[2];
  work1d.KKT[1095] = -params1d.A[3];
  work1d.KKT[1098] = -params1d.A[4];
  work1d.KKT[903] = 1;
  work1d.KKT[1099] = 1;
  work1d.KKT[794] = 1;
  work1d.KKT[704] = -params1d.B[0];
  work1d.KKT[904] = -params1d.A[0];
  work1d.KKT[1102] = -params1d.A[1];
  work1d.KKT[795] = -params1d.A[2];
  work1d.KKT[1101] = -params1d.A[3];
  work1d.KKT[1104] = -params1d.A[4];
  work1d.KKT[906] = 1;
  work1d.KKT[1105] = 1;
  work1d.KKT[796] = 1;
  work1d.KKT[706] = -params1d.B[0];
  work1d.KKT[907] = -params1d.A[0];
  work1d.KKT[1108] = -params1d.A[1];
  work1d.KKT[797] = -params1d.A[2];
  work1d.KKT[1107] = -params1d.A[3];
  work1d.KKT[1110] = -params1d.A[4];
  work1d.KKT[909] = 1;
  work1d.KKT[1111] = 1;
  work1d.KKT[798] = 1;
  work1d.KKT[708] = -params1d.B[0];
  work1d.KKT[910] = -params1d.A[0];
  work1d.KKT[1114] = -params1d.A[1];
  work1d.KKT[799] = -params1d.A[2];
  work1d.KKT[1113] = -params1d.A[3];
  work1d.KKT[1116] = -params1d.A[4];
  work1d.KKT[912] = 1;
  work1d.KKT[1117] = 1;
  work1d.KKT[800] = 1;
  work1d.KKT[710] = -params1d.B[0];
  work1d.KKT[913] = -params1d.A[0];
  work1d.KKT[1120] = -params1d.A[1];
  work1d.KKT[801] = -params1d.A[2];
  work1d.KKT[1119] = -params1d.A[3];
  work1d.KKT[1122] = -params1d.A[4];
  work1d.KKT[915] = 1;
  work1d.KKT[1123] = 1;
  work1d.KKT[802] = 1;
  work1d.KKT[712] = -params1d.B[0];
  work1d.KKT[916] = -params1d.A[0];
  work1d.KKT[1126] = -params1d.A[1];
  work1d.KKT[803] = -params1d.A[2];
  work1d.KKT[1125] = -params1d.A[3];
  work1d.KKT[1128] = -params1d.A[4];
  work1d.KKT[918] = 1;
  work1d.KKT[1129] = 1;
  work1d.KKT[804] = 1;
  work1d.KKT[714] = -params1d.B[0];
  work1d.KKT[919] = -params1d.A[0];
  work1d.KKT[1132] = -params1d.A[1];
  work1d.KKT[805] = -params1d.A[2];
  work1d.KKT[1131] = -params1d.A[3];
  work1d.KKT[1134] = -params1d.A[4];
  work1d.KKT[921] = 1;
  work1d.KKT[1135] = 1;
  work1d.KKT[806] = 1;
  work1d.KKT[716] = -params1d.B[0];
  work1d.KKT[922] = -params1d.A[0];
  work1d.KKT[1138] = -params1d.A[1];
  work1d.KKT[807] = -params1d.A[2];
  work1d.KKT[1137] = -params1d.A[3];
  work1d.KKT[1140] = -params1d.A[4];
  work1d.KKT[924] = 1;
  work1d.KKT[1141] = 1;
  work1d.KKT[808] = 1;
  work1d.KKT[718] = -params1d.B[0];
  work1d.KKT[925] = -params1d.A[0];
  work1d.KKT[1144] = -params1d.A[1];
  work1d.KKT[809] = -params1d.A[2];
  work1d.KKT[1143] = -params1d.A[3];
  work1d.KKT[1146] = -params1d.A[4];
  work1d.KKT[927] = 1;
  work1d.KKT[1147] = 1;
  work1d.KKT[810] = 1;
  work1d.KKT[720] = -params1d.B[0];
  work1d.KKT[928] = -params1d.A[0];
  work1d.KKT[1149] = -params1d.A[1];
  work1d.KKT[811] = -params1d.A[2];
  work1d.KKT[1148] = -params1d.A[3];
  work1d.KKT[1150] = -params1d.A[4];
  work1d.KKT[930] = 1;
  work1d.KKT[1151] = 1;
  work1d.KKT[733] = 1;
  work1d.KKT[722] = -params1d.B[0];
  work1d.KKT[812] = -params1d.A[0];
  work1d.KKT[814] = -params1d.A[1];
  work1d.KKT[725] = -params1d.A[2];
  work1d.KKT[813] = -params1d.A[3];
  work1d.KKT[734] = -params1d.A[4];
  work1d.KKT[729] = 1;
  work1d.KKT[731] = 1;
  work1d.KKT[724] = 1;
}
