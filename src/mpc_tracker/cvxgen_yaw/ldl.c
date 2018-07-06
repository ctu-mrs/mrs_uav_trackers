/* Produced by CVXGEN, 2018-02-17 15:26:31 -0500.  */
/* CVXGEN is Copyright (C) 2006-2017 Jacob Mattingley, jem@cvxgen.com. */
/* The code in this file is Copyright (C) 2006-2017 Jacob Mattingley. */
/* CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial */
/* applications without prior written permission from Jacob Mattingley. */

/* Filename: ldl.c. */
/* Description: Basic test harness for solver.c. */
#include "solver.h"
/* Be sure to place ldl_solve first, so storage schemes are defined by it. */
void ldl_solve_yaw(double *target, double *var) {
  int i;
  /* Find var = (L*diag(workYaw.d)*L') \ target, then unpermute. */
  /* Answer goes into var. */
  /* Forward substitution. */
  /* Include permutation as we retrieve from target. Use v so we can unpermute */
  /* later. */
  workYaw.v[0] = target[40];
  workYaw.v[1] = target[161];
  workYaw.v[2] = target[162];
  workYaw.v[3] = target[163];
  workYaw.v[4] = target[164];
  workYaw.v[5] = target[165];
  workYaw.v[6] = target[166];
  workYaw.v[7] = target[167];
  workYaw.v[8] = target[168];
  workYaw.v[9] = target[169];
  workYaw.v[10] = target[170];
  workYaw.v[11] = target[171];
  workYaw.v[12] = target[172];
  workYaw.v[13] = target[173];
  workYaw.v[14] = target[174];
  workYaw.v[15] = target[175];
  workYaw.v[16] = target[176];
  workYaw.v[17] = target[177];
  workYaw.v[18] = target[178];
  workYaw.v[19] = target[179];
  workYaw.v[20] = target[180];
  workYaw.v[21] = target[181];
  workYaw.v[22] = target[182];
  workYaw.v[23] = target[183];
  workYaw.v[24] = target[184];
  workYaw.v[25] = target[185];
  workYaw.v[26] = target[186];
  workYaw.v[27] = target[187];
  workYaw.v[28] = target[188];
  workYaw.v[29] = target[189];
  workYaw.v[30] = target[190];
  workYaw.v[31] = target[191];
  workYaw.v[32] = target[192];
  workYaw.v[33] = target[193];
  workYaw.v[34] = target[194];
  workYaw.v[35] = target[195];
  workYaw.v[36] = target[196];
  workYaw.v[37] = target[197];
  workYaw.v[38] = target[198];
  workYaw.v[39] = target[199];
  workYaw.v[40] = target[200];
  workYaw.v[41] = target[201];
  workYaw.v[42] = target[202];
  workYaw.v[43] = target[203];
  workYaw.v[44] = target[204];
  workYaw.v[45] = target[205];
  workYaw.v[46] = target[206];
  workYaw.v[47] = target[207];
  workYaw.v[48] = target[208];
  workYaw.v[49] = target[209];
  workYaw.v[50] = target[210];
  workYaw.v[51] = target[211];
  workYaw.v[52] = target[212];
  workYaw.v[53] = target[213];
  workYaw.v[54] = target[214];
  workYaw.v[55] = target[215];
  workYaw.v[56] = target[216];
  workYaw.v[57] = target[217];
  workYaw.v[58] = target[218];
  workYaw.v[59] = target[219];
  workYaw.v[60] = target[220];
  workYaw.v[61] = target[221];
  workYaw.v[62] = target[222];
  workYaw.v[63] = target[223];
  workYaw.v[64] = target[224];
  workYaw.v[65] = target[225];
  workYaw.v[66] = target[226];
  workYaw.v[67] = target[227];
  workYaw.v[68] = target[228];
  workYaw.v[69] = target[229];
  workYaw.v[70] = target[230];
  workYaw.v[71] = target[231];
  workYaw.v[72] = target[232];
  workYaw.v[73] = target[233];
  workYaw.v[74] = target[234];
  workYaw.v[75] = target[235];
  workYaw.v[76] = target[236];
  workYaw.v[77] = target[237];
  workYaw.v[78] = target[238];
  workYaw.v[79] = target[239];
  workYaw.v[80] = target[240];
  workYaw.v[81] = target[241];
  workYaw.v[82] = target[242];
  workYaw.v[83] = target[243];
  workYaw.v[84] = target[244];
  workYaw.v[85] = target[245];
  workYaw.v[86] = target[246];
  workYaw.v[87] = target[247];
  workYaw.v[88] = target[248];
  workYaw.v[89] = target[249];
  workYaw.v[90] = target[250];
  workYaw.v[91] = target[251];
  workYaw.v[92] = target[252];
  workYaw.v[93] = target[253];
  workYaw.v[94] = target[254];
  workYaw.v[95] = target[255];
  workYaw.v[96] = target[256];
  workYaw.v[97] = target[257];
  workYaw.v[98] = target[258];
  workYaw.v[99] = target[259];
  workYaw.v[100] = target[260];
  workYaw.v[101] = target[261];
  workYaw.v[102] = target[262];
  workYaw.v[103] = target[263];
  workYaw.v[104] = target[264];
  workYaw.v[105] = target[265];
  workYaw.v[106] = target[266];
  workYaw.v[107] = target[267];
  workYaw.v[108] = target[268];
  workYaw.v[109] = target[269];
  workYaw.v[110] = target[270];
  workYaw.v[111] = target[271];
  workYaw.v[112] = target[272];
  workYaw.v[113] = target[273];
  workYaw.v[114] = target[274];
  workYaw.v[115] = target[275];
  workYaw.v[116] = target[276];
  workYaw.v[117] = target[277];
  workYaw.v[118] = target[278];
  workYaw.v[119] = target[279];
  workYaw.v[120] = target[280];
  workYaw.v[121] = target[281];
  workYaw.v[122] = target[282];
  workYaw.v[123] = target[283];
  workYaw.v[124] = target[284];
  workYaw.v[125] = target[285];
  workYaw.v[126] = target[286];
  workYaw.v[127] = target[287];
  workYaw.v[128] = target[288];
  workYaw.v[129] = target[289];
  workYaw.v[130] = target[290];
  workYaw.v[131] = target[291];
  workYaw.v[132] = target[292];
  workYaw.v[133] = target[293];
  workYaw.v[134] = target[294];
  workYaw.v[135] = target[295];
  workYaw.v[136] = target[296];
  workYaw.v[137] = target[297];
  workYaw.v[138] = target[298];
  workYaw.v[139] = target[299];
  workYaw.v[140] = target[300];
  workYaw.v[141] = target[301];
  workYaw.v[142] = target[302];
  workYaw.v[143] = target[303];
  workYaw.v[144] = target[304];
  workYaw.v[145] = target[305];
  workYaw.v[146] = target[306];
  workYaw.v[147] = target[307];
  workYaw.v[148] = target[308];
  workYaw.v[149] = target[309];
  workYaw.v[150] = target[310];
  workYaw.v[151] = target[311];
  workYaw.v[152] = target[312];
  workYaw.v[153] = target[313];
  workYaw.v[154] = target[314];
  workYaw.v[155] = target[315];
  workYaw.v[156] = target[316];
  workYaw.v[157] = target[317];
  workYaw.v[158] = target[318];
  workYaw.v[159] = target[319];
  workYaw.v[160] = target[320];
  workYaw.v[161] = target[321]-workYaw.L[0]*workYaw.v[1];
  workYaw.v[162] = target[322]-workYaw.L[1]*workYaw.v[2];
  workYaw.v[163] = target[323]-workYaw.L[2]*workYaw.v[3];
  workYaw.v[164] = target[324]-workYaw.L[3]*workYaw.v[4];
  workYaw.v[165] = target[325]-workYaw.L[4]*workYaw.v[5];
  workYaw.v[166] = target[326]-workYaw.L[5]*workYaw.v[6];
  workYaw.v[167] = target[327]-workYaw.L[6]*workYaw.v[7];
  workYaw.v[168] = target[328]-workYaw.L[7]*workYaw.v[8];
  workYaw.v[169] = target[329]-workYaw.L[8]*workYaw.v[9];
  workYaw.v[170] = target[330]-workYaw.L[9]*workYaw.v[10];
  workYaw.v[171] = target[331]-workYaw.L[10]*workYaw.v[11];
  workYaw.v[172] = target[332]-workYaw.L[11]*workYaw.v[12];
  workYaw.v[173] = target[333]-workYaw.L[12]*workYaw.v[13];
  workYaw.v[174] = target[334]-workYaw.L[13]*workYaw.v[14];
  workYaw.v[175] = target[335]-workYaw.L[14]*workYaw.v[15];
  workYaw.v[176] = target[336]-workYaw.L[15]*workYaw.v[16];
  workYaw.v[177] = target[337]-workYaw.L[16]*workYaw.v[17];
  workYaw.v[178] = target[338]-workYaw.L[17]*workYaw.v[18];
  workYaw.v[179] = target[339]-workYaw.L[18]*workYaw.v[19];
  workYaw.v[180] = target[340]-workYaw.L[19]*workYaw.v[20];
  workYaw.v[181] = target[341]-workYaw.L[20]*workYaw.v[21];
  workYaw.v[182] = target[342]-workYaw.L[21]*workYaw.v[22];
  workYaw.v[183] = target[343]-workYaw.L[22]*workYaw.v[23];
  workYaw.v[184] = target[344]-workYaw.L[23]*workYaw.v[24];
  workYaw.v[185] = target[345]-workYaw.L[24]*workYaw.v[25];
  workYaw.v[186] = target[346]-workYaw.L[25]*workYaw.v[26];
  workYaw.v[187] = target[347]-workYaw.L[26]*workYaw.v[27];
  workYaw.v[188] = target[348]-workYaw.L[27]*workYaw.v[28];
  workYaw.v[189] = target[349]-workYaw.L[28]*workYaw.v[29];
  workYaw.v[190] = target[350]-workYaw.L[29]*workYaw.v[30];
  workYaw.v[191] = target[351]-workYaw.L[30]*workYaw.v[31];
  workYaw.v[192] = target[352]-workYaw.L[31]*workYaw.v[32];
  workYaw.v[193] = target[353]-workYaw.L[32]*workYaw.v[33];
  workYaw.v[194] = target[354]-workYaw.L[33]*workYaw.v[34];
  workYaw.v[195] = target[355]-workYaw.L[34]*workYaw.v[35];
  workYaw.v[196] = target[356]-workYaw.L[35]*workYaw.v[36];
  workYaw.v[197] = target[357]-workYaw.L[36]*workYaw.v[37];
  workYaw.v[198] = target[358]-workYaw.L[37]*workYaw.v[38];
  workYaw.v[199] = target[359]-workYaw.L[38]*workYaw.v[39];
  workYaw.v[200] = target[360]-workYaw.L[39]*workYaw.v[40];
  workYaw.v[201] = target[361]-workYaw.L[40]*workYaw.v[41];
  workYaw.v[202] = target[362]-workYaw.L[41]*workYaw.v[42];
  workYaw.v[203] = target[363]-workYaw.L[42]*workYaw.v[43];
  workYaw.v[204] = target[364]-workYaw.L[43]*workYaw.v[44];
  workYaw.v[205] = target[365]-workYaw.L[44]*workYaw.v[45];
  workYaw.v[206] = target[366]-workYaw.L[45]*workYaw.v[46];
  workYaw.v[207] = target[367]-workYaw.L[46]*workYaw.v[47];
  workYaw.v[208] = target[368]-workYaw.L[47]*workYaw.v[48];
  workYaw.v[209] = target[369]-workYaw.L[48]*workYaw.v[49];
  workYaw.v[210] = target[370]-workYaw.L[49]*workYaw.v[50];
  workYaw.v[211] = target[371]-workYaw.L[50]*workYaw.v[51];
  workYaw.v[212] = target[372]-workYaw.L[51]*workYaw.v[52];
  workYaw.v[213] = target[373]-workYaw.L[52]*workYaw.v[53];
  workYaw.v[214] = target[374]-workYaw.L[53]*workYaw.v[54];
  workYaw.v[215] = target[375]-workYaw.L[54]*workYaw.v[55];
  workYaw.v[216] = target[376]-workYaw.L[55]*workYaw.v[56];
  workYaw.v[217] = target[377]-workYaw.L[56]*workYaw.v[57];
  workYaw.v[218] = target[378]-workYaw.L[57]*workYaw.v[58];
  workYaw.v[219] = target[379]-workYaw.L[58]*workYaw.v[59];
  workYaw.v[220] = target[380]-workYaw.L[59]*workYaw.v[60];
  workYaw.v[221] = target[381]-workYaw.L[60]*workYaw.v[61];
  workYaw.v[222] = target[382]-workYaw.L[61]*workYaw.v[62];
  workYaw.v[223] = target[383]-workYaw.L[62]*workYaw.v[63];
  workYaw.v[224] = target[384]-workYaw.L[63]*workYaw.v[64];
  workYaw.v[225] = target[385]-workYaw.L[64]*workYaw.v[65];
  workYaw.v[226] = target[386]-workYaw.L[65]*workYaw.v[66];
  workYaw.v[227] = target[387]-workYaw.L[66]*workYaw.v[67];
  workYaw.v[228] = target[388]-workYaw.L[67]*workYaw.v[68];
  workYaw.v[229] = target[389]-workYaw.L[68]*workYaw.v[69];
  workYaw.v[230] = target[390]-workYaw.L[69]*workYaw.v[70];
  workYaw.v[231] = target[391]-workYaw.L[70]*workYaw.v[71];
  workYaw.v[232] = target[392]-workYaw.L[71]*workYaw.v[72];
  workYaw.v[233] = target[393]-workYaw.L[72]*workYaw.v[73];
  workYaw.v[234] = target[394]-workYaw.L[73]*workYaw.v[74];
  workYaw.v[235] = target[395]-workYaw.L[74]*workYaw.v[75];
  workYaw.v[236] = target[396]-workYaw.L[75]*workYaw.v[76];
  workYaw.v[237] = target[397]-workYaw.L[76]*workYaw.v[77];
  workYaw.v[238] = target[398]-workYaw.L[77]*workYaw.v[78];
  workYaw.v[239] = target[399]-workYaw.L[78]*workYaw.v[79];
  workYaw.v[240] = target[400]-workYaw.L[79]*workYaw.v[80];
  workYaw.v[241] = target[401]-workYaw.L[80]*workYaw.v[81];
  workYaw.v[242] = target[402]-workYaw.L[81]*workYaw.v[82];
  workYaw.v[243] = target[403]-workYaw.L[82]*workYaw.v[83];
  workYaw.v[244] = target[404]-workYaw.L[83]*workYaw.v[84];
  workYaw.v[245] = target[405]-workYaw.L[84]*workYaw.v[85];
  workYaw.v[246] = target[406]-workYaw.L[85]*workYaw.v[86];
  workYaw.v[247] = target[407]-workYaw.L[86]*workYaw.v[87];
  workYaw.v[248] = target[408]-workYaw.L[87]*workYaw.v[88];
  workYaw.v[249] = target[409]-workYaw.L[88]*workYaw.v[89];
  workYaw.v[250] = target[410]-workYaw.L[89]*workYaw.v[90];
  workYaw.v[251] = target[411]-workYaw.L[90]*workYaw.v[91];
  workYaw.v[252] = target[412]-workYaw.L[91]*workYaw.v[92];
  workYaw.v[253] = target[413]-workYaw.L[92]*workYaw.v[93];
  workYaw.v[254] = target[414]-workYaw.L[93]*workYaw.v[94];
  workYaw.v[255] = target[415]-workYaw.L[94]*workYaw.v[95];
  workYaw.v[256] = target[416]-workYaw.L[95]*workYaw.v[96];
  workYaw.v[257] = target[417]-workYaw.L[96]*workYaw.v[97];
  workYaw.v[258] = target[418]-workYaw.L[97]*workYaw.v[98];
  workYaw.v[259] = target[419]-workYaw.L[98]*workYaw.v[99];
  workYaw.v[260] = target[420]-workYaw.L[99]*workYaw.v[100];
  workYaw.v[261] = target[421]-workYaw.L[100]*workYaw.v[101];
  workYaw.v[262] = target[422]-workYaw.L[101]*workYaw.v[102];
  workYaw.v[263] = target[423]-workYaw.L[102]*workYaw.v[103];
  workYaw.v[264] = target[424]-workYaw.L[103]*workYaw.v[104];
  workYaw.v[265] = target[425]-workYaw.L[104]*workYaw.v[105];
  workYaw.v[266] = target[426]-workYaw.L[105]*workYaw.v[106];
  workYaw.v[267] = target[427]-workYaw.L[106]*workYaw.v[107];
  workYaw.v[268] = target[428]-workYaw.L[107]*workYaw.v[108];
  workYaw.v[269] = target[429]-workYaw.L[108]*workYaw.v[109];
  workYaw.v[270] = target[430]-workYaw.L[109]*workYaw.v[110];
  workYaw.v[271] = target[431]-workYaw.L[110]*workYaw.v[111];
  workYaw.v[272] = target[432]-workYaw.L[111]*workYaw.v[112];
  workYaw.v[273] = target[433]-workYaw.L[112]*workYaw.v[113];
  workYaw.v[274] = target[434]-workYaw.L[113]*workYaw.v[114];
  workYaw.v[275] = target[435]-workYaw.L[114]*workYaw.v[115];
  workYaw.v[276] = target[436]-workYaw.L[115]*workYaw.v[116];
  workYaw.v[277] = target[437]-workYaw.L[116]*workYaw.v[117];
  workYaw.v[278] = target[438]-workYaw.L[117]*workYaw.v[118];
  workYaw.v[279] = target[439]-workYaw.L[118]*workYaw.v[119];
  workYaw.v[280] = target[440]-workYaw.L[119]*workYaw.v[120];
  workYaw.v[281] = target[441]-workYaw.L[120]*workYaw.v[121];
  workYaw.v[282] = target[442]-workYaw.L[121]*workYaw.v[122];
  workYaw.v[283] = target[443]-workYaw.L[122]*workYaw.v[123];
  workYaw.v[284] = target[444]-workYaw.L[123]*workYaw.v[124];
  workYaw.v[285] = target[445]-workYaw.L[124]*workYaw.v[125];
  workYaw.v[286] = target[446]-workYaw.L[125]*workYaw.v[126];
  workYaw.v[287] = target[447]-workYaw.L[126]*workYaw.v[127];
  workYaw.v[288] = target[448]-workYaw.L[127]*workYaw.v[128];
  workYaw.v[289] = target[449]-workYaw.L[128]*workYaw.v[129];
  workYaw.v[290] = target[450]-workYaw.L[129]*workYaw.v[130];
  workYaw.v[291] = target[451]-workYaw.L[130]*workYaw.v[131];
  workYaw.v[292] = target[452]-workYaw.L[131]*workYaw.v[132];
  workYaw.v[293] = target[453]-workYaw.L[132]*workYaw.v[133];
  workYaw.v[294] = target[454]-workYaw.L[133]*workYaw.v[134];
  workYaw.v[295] = target[455]-workYaw.L[134]*workYaw.v[135];
  workYaw.v[296] = target[456]-workYaw.L[135]*workYaw.v[136];
  workYaw.v[297] = target[457]-workYaw.L[136]*workYaw.v[137];
  workYaw.v[298] = target[458]-workYaw.L[137]*workYaw.v[138];
  workYaw.v[299] = target[459]-workYaw.L[138]*workYaw.v[139];
  workYaw.v[300] = target[460]-workYaw.L[139]*workYaw.v[140];
  workYaw.v[301] = target[461]-workYaw.L[140]*workYaw.v[141];
  workYaw.v[302] = target[462]-workYaw.L[141]*workYaw.v[142];
  workYaw.v[303] = target[463]-workYaw.L[142]*workYaw.v[143];
  workYaw.v[304] = target[464]-workYaw.L[143]*workYaw.v[144];
  workYaw.v[305] = target[465]-workYaw.L[144]*workYaw.v[145];
  workYaw.v[306] = target[466]-workYaw.L[145]*workYaw.v[146];
  workYaw.v[307] = target[467]-workYaw.L[146]*workYaw.v[147];
  workYaw.v[308] = target[468]-workYaw.L[147]*workYaw.v[148];
  workYaw.v[309] = target[469]-workYaw.L[148]*workYaw.v[149];
  workYaw.v[310] = target[470]-workYaw.L[149]*workYaw.v[150];
  workYaw.v[311] = target[471]-workYaw.L[150]*workYaw.v[151];
  workYaw.v[312] = target[472]-workYaw.L[151]*workYaw.v[152];
  workYaw.v[313] = target[473]-workYaw.L[152]*workYaw.v[153];
  workYaw.v[314] = target[474]-workYaw.L[153]*workYaw.v[154];
  workYaw.v[315] = target[475]-workYaw.L[154]*workYaw.v[155];
  workYaw.v[316] = target[476]-workYaw.L[155]*workYaw.v[156];
  workYaw.v[317] = target[477]-workYaw.L[156]*workYaw.v[157];
  workYaw.v[318] = target[478]-workYaw.L[157]*workYaw.v[158];
  workYaw.v[319] = target[479]-workYaw.L[158]*workYaw.v[159];
  workYaw.v[320] = target[480]-workYaw.L[159]*workYaw.v[160];
  workYaw.v[321] = target[481];
  workYaw.v[322] = target[482];
  workYaw.v[323] = target[0];
  workYaw.v[324] = target[483]-workYaw.L[160]*workYaw.v[323];
  workYaw.v[325] = target[1];
  workYaw.v[326] = target[2];
  workYaw.v[327] = target[3];
  workYaw.v[328] = target[4];
  workYaw.v[329] = target[5];
  workYaw.v[330] = target[6];
  workYaw.v[331] = target[7];
  workYaw.v[332] = target[8];
  workYaw.v[333] = target[9];
  workYaw.v[334] = target[10];
  workYaw.v[335] = target[11];
  workYaw.v[336] = target[12];
  workYaw.v[337] = target[13];
  workYaw.v[338] = target[14];
  workYaw.v[339] = target[15];
  workYaw.v[340] = target[16];
  workYaw.v[341] = target[17];
  workYaw.v[342] = target[18];
  workYaw.v[343] = target[19];
  workYaw.v[344] = target[20];
  workYaw.v[345] = target[21];
  workYaw.v[346] = target[22];
  workYaw.v[347] = target[23];
  workYaw.v[348] = target[24];
  workYaw.v[349] = target[25];
  workYaw.v[350] = target[26];
  workYaw.v[351] = target[27];
  workYaw.v[352] = target[28];
  workYaw.v[353] = target[29];
  workYaw.v[354] = target[30];
  workYaw.v[355] = target[31];
  workYaw.v[356] = target[32];
  workYaw.v[357] = target[33];
  workYaw.v[358] = target[34];
  workYaw.v[359] = target[35];
  workYaw.v[360] = target[36];
  workYaw.v[361] = target[37];
  workYaw.v[362] = target[38];
  workYaw.v[363] = target[39];
  workYaw.v[364] = target[160]-workYaw.L[161]*workYaw.v[280]-workYaw.L[162]*workYaw.v[320];
  workYaw.v[365] = target[600]-workYaw.L[163]*workYaw.v[363]-workYaw.L[164]*workYaw.v[364];
  workYaw.v[366] = target[41]-workYaw.L[165]*workYaw.v[321];
  workYaw.v[367] = target[158];
  workYaw.v[368] = target[159]-workYaw.L[166]*workYaw.v[200]-workYaw.L[167]*workYaw.v[240];
  workYaw.v[369] = target[157]-workYaw.L[168]*workYaw.v[279]-workYaw.L[169]*workYaw.v[319]-workYaw.L[170]*workYaw.v[365];
  workYaw.v[370] = target[484]-workYaw.L[171]*workYaw.v[366];
  workYaw.v[371] = target[486]-workYaw.L[172]*workYaw.v[325];
  workYaw.v[372] = target[489]-workYaw.L[173]*workYaw.v[326];
  workYaw.v[373] = target[492]-workYaw.L[174]*workYaw.v[327];
  workYaw.v[374] = target[495]-workYaw.L[175]*workYaw.v[328];
  workYaw.v[375] = target[498]-workYaw.L[176]*workYaw.v[329];
  workYaw.v[376] = target[501]-workYaw.L[177]*workYaw.v[330];
  workYaw.v[377] = target[504]-workYaw.L[178]*workYaw.v[331];
  workYaw.v[378] = target[507]-workYaw.L[179]*workYaw.v[332];
  workYaw.v[379] = target[510]-workYaw.L[180]*workYaw.v[333];
  workYaw.v[380] = target[513]-workYaw.L[181]*workYaw.v[334];
  workYaw.v[381] = target[516]-workYaw.L[182]*workYaw.v[335];
  workYaw.v[382] = target[519]-workYaw.L[183]*workYaw.v[336];
  workYaw.v[383] = target[522]-workYaw.L[184]*workYaw.v[337];
  workYaw.v[384] = target[525]-workYaw.L[185]*workYaw.v[338];
  workYaw.v[385] = target[528]-workYaw.L[186]*workYaw.v[339];
  workYaw.v[386] = target[531]-workYaw.L[187]*workYaw.v[340];
  workYaw.v[387] = target[534]-workYaw.L[188]*workYaw.v[341];
  workYaw.v[388] = target[537]-workYaw.L[189]*workYaw.v[342];
  workYaw.v[389] = target[540]-workYaw.L[190]*workYaw.v[343];
  workYaw.v[390] = target[543]-workYaw.L[191]*workYaw.v[344];
  workYaw.v[391] = target[546]-workYaw.L[192]*workYaw.v[345];
  workYaw.v[392] = target[549]-workYaw.L[193]*workYaw.v[346];
  workYaw.v[393] = target[552]-workYaw.L[194]*workYaw.v[347];
  workYaw.v[394] = target[555]-workYaw.L[195]*workYaw.v[348];
  workYaw.v[395] = target[558]-workYaw.L[196]*workYaw.v[349];
  workYaw.v[396] = target[561]-workYaw.L[197]*workYaw.v[350];
  workYaw.v[397] = target[564]-workYaw.L[198]*workYaw.v[351];
  workYaw.v[398] = target[567]-workYaw.L[199]*workYaw.v[352];
  workYaw.v[399] = target[570]-workYaw.L[200]*workYaw.v[353];
  workYaw.v[400] = target[573]-workYaw.L[201]*workYaw.v[354];
  workYaw.v[401] = target[576]-workYaw.L[202]*workYaw.v[355];
  workYaw.v[402] = target[579]-workYaw.L[203]*workYaw.v[356];
  workYaw.v[403] = target[582]-workYaw.L[204]*workYaw.v[357];
  workYaw.v[404] = target[585]-workYaw.L[205]*workYaw.v[358];
  workYaw.v[405] = target[588]-workYaw.L[206]*workYaw.v[359];
  workYaw.v[406] = target[591]-workYaw.L[207]*workYaw.v[360];
  workYaw.v[407] = target[594]-workYaw.L[208]*workYaw.v[361];
  workYaw.v[408] = target[597]-workYaw.L[209]*workYaw.v[362]-workYaw.L[210]*workYaw.v[369];
  workYaw.v[409] = target[598]-workYaw.L[211]*workYaw.v[367];
  workYaw.v[410] = target[599]-workYaw.L[212]*workYaw.v[368]-workYaw.L[213]*workYaw.v[369]-workYaw.L[214]*workYaw.v[408];
  workYaw.v[411] = target[42]-workYaw.L[215]*workYaw.v[161]-workYaw.L[216]*workYaw.v[201]-workYaw.L[217]*workYaw.v[322]-workYaw.L[218]*workYaw.v[370];
  workYaw.v[412] = target[43]-workYaw.L[219]*workYaw.v[241]-workYaw.L[220]*workYaw.v[281]-workYaw.L[221]*workYaw.v[324]-workYaw.L[222]*workYaw.v[371];
  workYaw.v[413] = target[44]-workYaw.L[223]*workYaw.v[370]-workYaw.L[224]*workYaw.v[411];
  workYaw.v[414] = target[47];
  workYaw.v[415] = target[50];
  workYaw.v[416] = target[53];
  workYaw.v[417] = target[56];
  workYaw.v[418] = target[59];
  workYaw.v[419] = target[62];
  workYaw.v[420] = target[65];
  workYaw.v[421] = target[68];
  workYaw.v[422] = target[71];
  workYaw.v[423] = target[74];
  workYaw.v[424] = target[77];
  workYaw.v[425] = target[80];
  workYaw.v[426] = target[83];
  workYaw.v[427] = target[86];
  workYaw.v[428] = target[89];
  workYaw.v[429] = target[92];
  workYaw.v[430] = target[95];
  workYaw.v[431] = target[98];
  workYaw.v[432] = target[101];
  workYaw.v[433] = target[104];
  workYaw.v[434] = target[107];
  workYaw.v[435] = target[110];
  workYaw.v[436] = target[113];
  workYaw.v[437] = target[116];
  workYaw.v[438] = target[119];
  workYaw.v[439] = target[122];
  workYaw.v[440] = target[125];
  workYaw.v[441] = target[128];
  workYaw.v[442] = target[131];
  workYaw.v[443] = target[134];
  workYaw.v[444] = target[137];
  workYaw.v[445] = target[140];
  workYaw.v[446] = target[143];
  workYaw.v[447] = target[146];
  workYaw.v[448] = target[149];
  workYaw.v[449] = target[152];
  workYaw.v[450] = target[155]-workYaw.L[225]*workYaw.v[409];
  workYaw.v[451] = target[485]-workYaw.L[226]*workYaw.v[411]-workYaw.L[227]*workYaw.v[412]-workYaw.L[228]*workYaw.v[413];
  workYaw.v[452] = target[45]-workYaw.L[229]*workYaw.v[162]-workYaw.L[230]*workYaw.v[202]-workYaw.L[231]*workYaw.v[451];
  workYaw.v[453] = target[46]-workYaw.L[232]*workYaw.v[242]-workYaw.L[233]*workYaw.v[282]-workYaw.L[234]*workYaw.v[371]-workYaw.L[235]*workYaw.v[372]-workYaw.L[236]*workYaw.v[412]-workYaw.L[237]*workYaw.v[451]-workYaw.L[238]*workYaw.v[452];
  workYaw.v[454] = target[487]-workYaw.L[239]*workYaw.v[413]-workYaw.L[240]*workYaw.v[414]-workYaw.L[241]*workYaw.v[451]-workYaw.L[242]*workYaw.v[452]-workYaw.L[243]*workYaw.v[453];
  workYaw.v[455] = target[488]-workYaw.L[244]*workYaw.v[452]-workYaw.L[245]*workYaw.v[453]-workYaw.L[246]*workYaw.v[454];
  workYaw.v[456] = target[48]-workYaw.L[247]*workYaw.v[163]-workYaw.L[248]*workYaw.v[203]-workYaw.L[249]*workYaw.v[455];
  workYaw.v[457] = target[49]-workYaw.L[250]*workYaw.v[243]-workYaw.L[251]*workYaw.v[283]-workYaw.L[252]*workYaw.v[372]-workYaw.L[253]*workYaw.v[373]-workYaw.L[254]*workYaw.v[453]-workYaw.L[255]*workYaw.v[454]-workYaw.L[256]*workYaw.v[455]-workYaw.L[257]*workYaw.v[456];
  workYaw.v[458] = target[490]-workYaw.L[258]*workYaw.v[414]-workYaw.L[259]*workYaw.v[415]-workYaw.L[260]*workYaw.v[454]-workYaw.L[261]*workYaw.v[455]-workYaw.L[262]*workYaw.v[456]-workYaw.L[263]*workYaw.v[457];
  workYaw.v[459] = target[491]-workYaw.L[264]*workYaw.v[456]-workYaw.L[265]*workYaw.v[457]-workYaw.L[266]*workYaw.v[458];
  workYaw.v[460] = target[51]-workYaw.L[267]*workYaw.v[164]-workYaw.L[268]*workYaw.v[204]-workYaw.L[269]*workYaw.v[459];
  workYaw.v[461] = target[52]-workYaw.L[270]*workYaw.v[244]-workYaw.L[271]*workYaw.v[284]-workYaw.L[272]*workYaw.v[373]-workYaw.L[273]*workYaw.v[374]-workYaw.L[274]*workYaw.v[457]-workYaw.L[275]*workYaw.v[458]-workYaw.L[276]*workYaw.v[459]-workYaw.L[277]*workYaw.v[460];
  workYaw.v[462] = target[493]-workYaw.L[278]*workYaw.v[415]-workYaw.L[279]*workYaw.v[416]-workYaw.L[280]*workYaw.v[458]-workYaw.L[281]*workYaw.v[459]-workYaw.L[282]*workYaw.v[460]-workYaw.L[283]*workYaw.v[461];
  workYaw.v[463] = target[494]-workYaw.L[284]*workYaw.v[460]-workYaw.L[285]*workYaw.v[461]-workYaw.L[286]*workYaw.v[462];
  workYaw.v[464] = target[54]-workYaw.L[287]*workYaw.v[165]-workYaw.L[288]*workYaw.v[205]-workYaw.L[289]*workYaw.v[463];
  workYaw.v[465] = target[55]-workYaw.L[290]*workYaw.v[245]-workYaw.L[291]*workYaw.v[285]-workYaw.L[292]*workYaw.v[374]-workYaw.L[293]*workYaw.v[375]-workYaw.L[294]*workYaw.v[461]-workYaw.L[295]*workYaw.v[462]-workYaw.L[296]*workYaw.v[463]-workYaw.L[297]*workYaw.v[464];
  workYaw.v[466] = target[496]-workYaw.L[298]*workYaw.v[416]-workYaw.L[299]*workYaw.v[417]-workYaw.L[300]*workYaw.v[462]-workYaw.L[301]*workYaw.v[463]-workYaw.L[302]*workYaw.v[464]-workYaw.L[303]*workYaw.v[465];
  workYaw.v[467] = target[497]-workYaw.L[304]*workYaw.v[464]-workYaw.L[305]*workYaw.v[465]-workYaw.L[306]*workYaw.v[466];
  workYaw.v[468] = target[57]-workYaw.L[307]*workYaw.v[166]-workYaw.L[308]*workYaw.v[206]-workYaw.L[309]*workYaw.v[467];
  workYaw.v[469] = target[58]-workYaw.L[310]*workYaw.v[246]-workYaw.L[311]*workYaw.v[286]-workYaw.L[312]*workYaw.v[375]-workYaw.L[313]*workYaw.v[376]-workYaw.L[314]*workYaw.v[465]-workYaw.L[315]*workYaw.v[466]-workYaw.L[316]*workYaw.v[467]-workYaw.L[317]*workYaw.v[468];
  workYaw.v[470] = target[499]-workYaw.L[318]*workYaw.v[417]-workYaw.L[319]*workYaw.v[418]-workYaw.L[320]*workYaw.v[466]-workYaw.L[321]*workYaw.v[467]-workYaw.L[322]*workYaw.v[468]-workYaw.L[323]*workYaw.v[469];
  workYaw.v[471] = target[500]-workYaw.L[324]*workYaw.v[468]-workYaw.L[325]*workYaw.v[469]-workYaw.L[326]*workYaw.v[470];
  workYaw.v[472] = target[60]-workYaw.L[327]*workYaw.v[167]-workYaw.L[328]*workYaw.v[207]-workYaw.L[329]*workYaw.v[471];
  workYaw.v[473] = target[61]-workYaw.L[330]*workYaw.v[247]-workYaw.L[331]*workYaw.v[287]-workYaw.L[332]*workYaw.v[376]-workYaw.L[333]*workYaw.v[377]-workYaw.L[334]*workYaw.v[469]-workYaw.L[335]*workYaw.v[470]-workYaw.L[336]*workYaw.v[471]-workYaw.L[337]*workYaw.v[472];
  workYaw.v[474] = target[502]-workYaw.L[338]*workYaw.v[418]-workYaw.L[339]*workYaw.v[419]-workYaw.L[340]*workYaw.v[470]-workYaw.L[341]*workYaw.v[471]-workYaw.L[342]*workYaw.v[472]-workYaw.L[343]*workYaw.v[473];
  workYaw.v[475] = target[503]-workYaw.L[344]*workYaw.v[472]-workYaw.L[345]*workYaw.v[473]-workYaw.L[346]*workYaw.v[474];
  workYaw.v[476] = target[63]-workYaw.L[347]*workYaw.v[168]-workYaw.L[348]*workYaw.v[208]-workYaw.L[349]*workYaw.v[475];
  workYaw.v[477] = target[64]-workYaw.L[350]*workYaw.v[248]-workYaw.L[351]*workYaw.v[288]-workYaw.L[352]*workYaw.v[377]-workYaw.L[353]*workYaw.v[378]-workYaw.L[354]*workYaw.v[473]-workYaw.L[355]*workYaw.v[474]-workYaw.L[356]*workYaw.v[475]-workYaw.L[357]*workYaw.v[476];
  workYaw.v[478] = target[505]-workYaw.L[358]*workYaw.v[419]-workYaw.L[359]*workYaw.v[420]-workYaw.L[360]*workYaw.v[474]-workYaw.L[361]*workYaw.v[475]-workYaw.L[362]*workYaw.v[476]-workYaw.L[363]*workYaw.v[477];
  workYaw.v[479] = target[506]-workYaw.L[364]*workYaw.v[476]-workYaw.L[365]*workYaw.v[477]-workYaw.L[366]*workYaw.v[478];
  workYaw.v[480] = target[66]-workYaw.L[367]*workYaw.v[169]-workYaw.L[368]*workYaw.v[209]-workYaw.L[369]*workYaw.v[479];
  workYaw.v[481] = target[67]-workYaw.L[370]*workYaw.v[249]-workYaw.L[371]*workYaw.v[289]-workYaw.L[372]*workYaw.v[378]-workYaw.L[373]*workYaw.v[379]-workYaw.L[374]*workYaw.v[477]-workYaw.L[375]*workYaw.v[478]-workYaw.L[376]*workYaw.v[479]-workYaw.L[377]*workYaw.v[480];
  workYaw.v[482] = target[508]-workYaw.L[378]*workYaw.v[420]-workYaw.L[379]*workYaw.v[421]-workYaw.L[380]*workYaw.v[478]-workYaw.L[381]*workYaw.v[479]-workYaw.L[382]*workYaw.v[480]-workYaw.L[383]*workYaw.v[481];
  workYaw.v[483] = target[509]-workYaw.L[384]*workYaw.v[480]-workYaw.L[385]*workYaw.v[481]-workYaw.L[386]*workYaw.v[482];
  workYaw.v[484] = target[69]-workYaw.L[387]*workYaw.v[170]-workYaw.L[388]*workYaw.v[210]-workYaw.L[389]*workYaw.v[483];
  workYaw.v[485] = target[70]-workYaw.L[390]*workYaw.v[250]-workYaw.L[391]*workYaw.v[290]-workYaw.L[392]*workYaw.v[379]-workYaw.L[393]*workYaw.v[380]-workYaw.L[394]*workYaw.v[481]-workYaw.L[395]*workYaw.v[482]-workYaw.L[396]*workYaw.v[483]-workYaw.L[397]*workYaw.v[484];
  workYaw.v[486] = target[511]-workYaw.L[398]*workYaw.v[421]-workYaw.L[399]*workYaw.v[422]-workYaw.L[400]*workYaw.v[482]-workYaw.L[401]*workYaw.v[483]-workYaw.L[402]*workYaw.v[484]-workYaw.L[403]*workYaw.v[485];
  workYaw.v[487] = target[512]-workYaw.L[404]*workYaw.v[484]-workYaw.L[405]*workYaw.v[485]-workYaw.L[406]*workYaw.v[486];
  workYaw.v[488] = target[72]-workYaw.L[407]*workYaw.v[171]-workYaw.L[408]*workYaw.v[211]-workYaw.L[409]*workYaw.v[487];
  workYaw.v[489] = target[73]-workYaw.L[410]*workYaw.v[251]-workYaw.L[411]*workYaw.v[291]-workYaw.L[412]*workYaw.v[380]-workYaw.L[413]*workYaw.v[381]-workYaw.L[414]*workYaw.v[485]-workYaw.L[415]*workYaw.v[486]-workYaw.L[416]*workYaw.v[487]-workYaw.L[417]*workYaw.v[488];
  workYaw.v[490] = target[514]-workYaw.L[418]*workYaw.v[422]-workYaw.L[419]*workYaw.v[423]-workYaw.L[420]*workYaw.v[486]-workYaw.L[421]*workYaw.v[487]-workYaw.L[422]*workYaw.v[488]-workYaw.L[423]*workYaw.v[489];
  workYaw.v[491] = target[515]-workYaw.L[424]*workYaw.v[488]-workYaw.L[425]*workYaw.v[489]-workYaw.L[426]*workYaw.v[490];
  workYaw.v[492] = target[75]-workYaw.L[427]*workYaw.v[172]-workYaw.L[428]*workYaw.v[212]-workYaw.L[429]*workYaw.v[491];
  workYaw.v[493] = target[76]-workYaw.L[430]*workYaw.v[252]-workYaw.L[431]*workYaw.v[292]-workYaw.L[432]*workYaw.v[381]-workYaw.L[433]*workYaw.v[382]-workYaw.L[434]*workYaw.v[489]-workYaw.L[435]*workYaw.v[490]-workYaw.L[436]*workYaw.v[491]-workYaw.L[437]*workYaw.v[492];
  workYaw.v[494] = target[517]-workYaw.L[438]*workYaw.v[423]-workYaw.L[439]*workYaw.v[424]-workYaw.L[440]*workYaw.v[490]-workYaw.L[441]*workYaw.v[491]-workYaw.L[442]*workYaw.v[492]-workYaw.L[443]*workYaw.v[493];
  workYaw.v[495] = target[518]-workYaw.L[444]*workYaw.v[492]-workYaw.L[445]*workYaw.v[493]-workYaw.L[446]*workYaw.v[494];
  workYaw.v[496] = target[78]-workYaw.L[447]*workYaw.v[173]-workYaw.L[448]*workYaw.v[213]-workYaw.L[449]*workYaw.v[495];
  workYaw.v[497] = target[79]-workYaw.L[450]*workYaw.v[253]-workYaw.L[451]*workYaw.v[293]-workYaw.L[452]*workYaw.v[382]-workYaw.L[453]*workYaw.v[383]-workYaw.L[454]*workYaw.v[493]-workYaw.L[455]*workYaw.v[494]-workYaw.L[456]*workYaw.v[495]-workYaw.L[457]*workYaw.v[496];
  workYaw.v[498] = target[520]-workYaw.L[458]*workYaw.v[424]-workYaw.L[459]*workYaw.v[425]-workYaw.L[460]*workYaw.v[494]-workYaw.L[461]*workYaw.v[495]-workYaw.L[462]*workYaw.v[496]-workYaw.L[463]*workYaw.v[497];
  workYaw.v[499] = target[521]-workYaw.L[464]*workYaw.v[496]-workYaw.L[465]*workYaw.v[497]-workYaw.L[466]*workYaw.v[498];
  workYaw.v[500] = target[81]-workYaw.L[467]*workYaw.v[174]-workYaw.L[468]*workYaw.v[214]-workYaw.L[469]*workYaw.v[499];
  workYaw.v[501] = target[82]-workYaw.L[470]*workYaw.v[254]-workYaw.L[471]*workYaw.v[294]-workYaw.L[472]*workYaw.v[383]-workYaw.L[473]*workYaw.v[384]-workYaw.L[474]*workYaw.v[497]-workYaw.L[475]*workYaw.v[498]-workYaw.L[476]*workYaw.v[499]-workYaw.L[477]*workYaw.v[500];
  workYaw.v[502] = target[523]-workYaw.L[478]*workYaw.v[425]-workYaw.L[479]*workYaw.v[426]-workYaw.L[480]*workYaw.v[498]-workYaw.L[481]*workYaw.v[499]-workYaw.L[482]*workYaw.v[500]-workYaw.L[483]*workYaw.v[501];
  workYaw.v[503] = target[524]-workYaw.L[484]*workYaw.v[500]-workYaw.L[485]*workYaw.v[501]-workYaw.L[486]*workYaw.v[502];
  workYaw.v[504] = target[84]-workYaw.L[487]*workYaw.v[175]-workYaw.L[488]*workYaw.v[215]-workYaw.L[489]*workYaw.v[503];
  workYaw.v[505] = target[85]-workYaw.L[490]*workYaw.v[255]-workYaw.L[491]*workYaw.v[295]-workYaw.L[492]*workYaw.v[384]-workYaw.L[493]*workYaw.v[385]-workYaw.L[494]*workYaw.v[501]-workYaw.L[495]*workYaw.v[502]-workYaw.L[496]*workYaw.v[503]-workYaw.L[497]*workYaw.v[504];
  workYaw.v[506] = target[526]-workYaw.L[498]*workYaw.v[426]-workYaw.L[499]*workYaw.v[427]-workYaw.L[500]*workYaw.v[502]-workYaw.L[501]*workYaw.v[503]-workYaw.L[502]*workYaw.v[504]-workYaw.L[503]*workYaw.v[505];
  workYaw.v[507] = target[527]-workYaw.L[504]*workYaw.v[504]-workYaw.L[505]*workYaw.v[505]-workYaw.L[506]*workYaw.v[506];
  workYaw.v[508] = target[87]-workYaw.L[507]*workYaw.v[176]-workYaw.L[508]*workYaw.v[216]-workYaw.L[509]*workYaw.v[507];
  workYaw.v[509] = target[88]-workYaw.L[510]*workYaw.v[256]-workYaw.L[511]*workYaw.v[296]-workYaw.L[512]*workYaw.v[385]-workYaw.L[513]*workYaw.v[386]-workYaw.L[514]*workYaw.v[505]-workYaw.L[515]*workYaw.v[506]-workYaw.L[516]*workYaw.v[507]-workYaw.L[517]*workYaw.v[508];
  workYaw.v[510] = target[529]-workYaw.L[518]*workYaw.v[427]-workYaw.L[519]*workYaw.v[428]-workYaw.L[520]*workYaw.v[506]-workYaw.L[521]*workYaw.v[507]-workYaw.L[522]*workYaw.v[508]-workYaw.L[523]*workYaw.v[509];
  workYaw.v[511] = target[530]-workYaw.L[524]*workYaw.v[508]-workYaw.L[525]*workYaw.v[509]-workYaw.L[526]*workYaw.v[510];
  workYaw.v[512] = target[90]-workYaw.L[527]*workYaw.v[177]-workYaw.L[528]*workYaw.v[217]-workYaw.L[529]*workYaw.v[511];
  workYaw.v[513] = target[91]-workYaw.L[530]*workYaw.v[257]-workYaw.L[531]*workYaw.v[297]-workYaw.L[532]*workYaw.v[386]-workYaw.L[533]*workYaw.v[387]-workYaw.L[534]*workYaw.v[509]-workYaw.L[535]*workYaw.v[510]-workYaw.L[536]*workYaw.v[511]-workYaw.L[537]*workYaw.v[512];
  workYaw.v[514] = target[532]-workYaw.L[538]*workYaw.v[428]-workYaw.L[539]*workYaw.v[429]-workYaw.L[540]*workYaw.v[510]-workYaw.L[541]*workYaw.v[511]-workYaw.L[542]*workYaw.v[512]-workYaw.L[543]*workYaw.v[513];
  workYaw.v[515] = target[533]-workYaw.L[544]*workYaw.v[512]-workYaw.L[545]*workYaw.v[513]-workYaw.L[546]*workYaw.v[514];
  workYaw.v[516] = target[93]-workYaw.L[547]*workYaw.v[178]-workYaw.L[548]*workYaw.v[218]-workYaw.L[549]*workYaw.v[515];
  workYaw.v[517] = target[94]-workYaw.L[550]*workYaw.v[258]-workYaw.L[551]*workYaw.v[298]-workYaw.L[552]*workYaw.v[387]-workYaw.L[553]*workYaw.v[388]-workYaw.L[554]*workYaw.v[513]-workYaw.L[555]*workYaw.v[514]-workYaw.L[556]*workYaw.v[515]-workYaw.L[557]*workYaw.v[516];
  workYaw.v[518] = target[535]-workYaw.L[558]*workYaw.v[429]-workYaw.L[559]*workYaw.v[430]-workYaw.L[560]*workYaw.v[514]-workYaw.L[561]*workYaw.v[515]-workYaw.L[562]*workYaw.v[516]-workYaw.L[563]*workYaw.v[517];
  workYaw.v[519] = target[536]-workYaw.L[564]*workYaw.v[516]-workYaw.L[565]*workYaw.v[517]-workYaw.L[566]*workYaw.v[518];
  workYaw.v[520] = target[96]-workYaw.L[567]*workYaw.v[179]-workYaw.L[568]*workYaw.v[219]-workYaw.L[569]*workYaw.v[519];
  workYaw.v[521] = target[97]-workYaw.L[570]*workYaw.v[259]-workYaw.L[571]*workYaw.v[299]-workYaw.L[572]*workYaw.v[388]-workYaw.L[573]*workYaw.v[389]-workYaw.L[574]*workYaw.v[517]-workYaw.L[575]*workYaw.v[518]-workYaw.L[576]*workYaw.v[519]-workYaw.L[577]*workYaw.v[520];
  workYaw.v[522] = target[538]-workYaw.L[578]*workYaw.v[430]-workYaw.L[579]*workYaw.v[431]-workYaw.L[580]*workYaw.v[518]-workYaw.L[581]*workYaw.v[519]-workYaw.L[582]*workYaw.v[520]-workYaw.L[583]*workYaw.v[521];
  workYaw.v[523] = target[539]-workYaw.L[584]*workYaw.v[520]-workYaw.L[585]*workYaw.v[521]-workYaw.L[586]*workYaw.v[522];
  workYaw.v[524] = target[99]-workYaw.L[587]*workYaw.v[180]-workYaw.L[588]*workYaw.v[220]-workYaw.L[589]*workYaw.v[523];
  workYaw.v[525] = target[100]-workYaw.L[590]*workYaw.v[260]-workYaw.L[591]*workYaw.v[300]-workYaw.L[592]*workYaw.v[389]-workYaw.L[593]*workYaw.v[390]-workYaw.L[594]*workYaw.v[521]-workYaw.L[595]*workYaw.v[522]-workYaw.L[596]*workYaw.v[523]-workYaw.L[597]*workYaw.v[524];
  workYaw.v[526] = target[541]-workYaw.L[598]*workYaw.v[431]-workYaw.L[599]*workYaw.v[432]-workYaw.L[600]*workYaw.v[522]-workYaw.L[601]*workYaw.v[523]-workYaw.L[602]*workYaw.v[524]-workYaw.L[603]*workYaw.v[525];
  workYaw.v[527] = target[542]-workYaw.L[604]*workYaw.v[524]-workYaw.L[605]*workYaw.v[525]-workYaw.L[606]*workYaw.v[526];
  workYaw.v[528] = target[102]-workYaw.L[607]*workYaw.v[181]-workYaw.L[608]*workYaw.v[221]-workYaw.L[609]*workYaw.v[527];
  workYaw.v[529] = target[103]-workYaw.L[610]*workYaw.v[261]-workYaw.L[611]*workYaw.v[301]-workYaw.L[612]*workYaw.v[390]-workYaw.L[613]*workYaw.v[391]-workYaw.L[614]*workYaw.v[525]-workYaw.L[615]*workYaw.v[526]-workYaw.L[616]*workYaw.v[527]-workYaw.L[617]*workYaw.v[528];
  workYaw.v[530] = target[544]-workYaw.L[618]*workYaw.v[432]-workYaw.L[619]*workYaw.v[433]-workYaw.L[620]*workYaw.v[526]-workYaw.L[621]*workYaw.v[527]-workYaw.L[622]*workYaw.v[528]-workYaw.L[623]*workYaw.v[529];
  workYaw.v[531] = target[545]-workYaw.L[624]*workYaw.v[528]-workYaw.L[625]*workYaw.v[529]-workYaw.L[626]*workYaw.v[530];
  workYaw.v[532] = target[105]-workYaw.L[627]*workYaw.v[182]-workYaw.L[628]*workYaw.v[222]-workYaw.L[629]*workYaw.v[531];
  workYaw.v[533] = target[106]-workYaw.L[630]*workYaw.v[262]-workYaw.L[631]*workYaw.v[302]-workYaw.L[632]*workYaw.v[391]-workYaw.L[633]*workYaw.v[392]-workYaw.L[634]*workYaw.v[529]-workYaw.L[635]*workYaw.v[530]-workYaw.L[636]*workYaw.v[531]-workYaw.L[637]*workYaw.v[532];
  workYaw.v[534] = target[547]-workYaw.L[638]*workYaw.v[433]-workYaw.L[639]*workYaw.v[434]-workYaw.L[640]*workYaw.v[530]-workYaw.L[641]*workYaw.v[531]-workYaw.L[642]*workYaw.v[532]-workYaw.L[643]*workYaw.v[533];
  workYaw.v[535] = target[548]-workYaw.L[644]*workYaw.v[532]-workYaw.L[645]*workYaw.v[533]-workYaw.L[646]*workYaw.v[534];
  workYaw.v[536] = target[108]-workYaw.L[647]*workYaw.v[183]-workYaw.L[648]*workYaw.v[223]-workYaw.L[649]*workYaw.v[535];
  workYaw.v[537] = target[109]-workYaw.L[650]*workYaw.v[263]-workYaw.L[651]*workYaw.v[303]-workYaw.L[652]*workYaw.v[392]-workYaw.L[653]*workYaw.v[393]-workYaw.L[654]*workYaw.v[533]-workYaw.L[655]*workYaw.v[534]-workYaw.L[656]*workYaw.v[535]-workYaw.L[657]*workYaw.v[536];
  workYaw.v[538] = target[550]-workYaw.L[658]*workYaw.v[434]-workYaw.L[659]*workYaw.v[435]-workYaw.L[660]*workYaw.v[534]-workYaw.L[661]*workYaw.v[535]-workYaw.L[662]*workYaw.v[536]-workYaw.L[663]*workYaw.v[537];
  workYaw.v[539] = target[551]-workYaw.L[664]*workYaw.v[536]-workYaw.L[665]*workYaw.v[537]-workYaw.L[666]*workYaw.v[538];
  workYaw.v[540] = target[111]-workYaw.L[667]*workYaw.v[184]-workYaw.L[668]*workYaw.v[224]-workYaw.L[669]*workYaw.v[539];
  workYaw.v[541] = target[112]-workYaw.L[670]*workYaw.v[264]-workYaw.L[671]*workYaw.v[304]-workYaw.L[672]*workYaw.v[393]-workYaw.L[673]*workYaw.v[394]-workYaw.L[674]*workYaw.v[537]-workYaw.L[675]*workYaw.v[538]-workYaw.L[676]*workYaw.v[539]-workYaw.L[677]*workYaw.v[540];
  workYaw.v[542] = target[553]-workYaw.L[678]*workYaw.v[435]-workYaw.L[679]*workYaw.v[436]-workYaw.L[680]*workYaw.v[538]-workYaw.L[681]*workYaw.v[539]-workYaw.L[682]*workYaw.v[540]-workYaw.L[683]*workYaw.v[541];
  workYaw.v[543] = target[554]-workYaw.L[684]*workYaw.v[540]-workYaw.L[685]*workYaw.v[541]-workYaw.L[686]*workYaw.v[542];
  workYaw.v[544] = target[114]-workYaw.L[687]*workYaw.v[185]-workYaw.L[688]*workYaw.v[225]-workYaw.L[689]*workYaw.v[543];
  workYaw.v[545] = target[115]-workYaw.L[690]*workYaw.v[265]-workYaw.L[691]*workYaw.v[305]-workYaw.L[692]*workYaw.v[394]-workYaw.L[693]*workYaw.v[395]-workYaw.L[694]*workYaw.v[541]-workYaw.L[695]*workYaw.v[542]-workYaw.L[696]*workYaw.v[543]-workYaw.L[697]*workYaw.v[544];
  workYaw.v[546] = target[556]-workYaw.L[698]*workYaw.v[436]-workYaw.L[699]*workYaw.v[437]-workYaw.L[700]*workYaw.v[542]-workYaw.L[701]*workYaw.v[543]-workYaw.L[702]*workYaw.v[544]-workYaw.L[703]*workYaw.v[545];
  workYaw.v[547] = target[557]-workYaw.L[704]*workYaw.v[544]-workYaw.L[705]*workYaw.v[545]-workYaw.L[706]*workYaw.v[546];
  workYaw.v[548] = target[117]-workYaw.L[707]*workYaw.v[186]-workYaw.L[708]*workYaw.v[226]-workYaw.L[709]*workYaw.v[547];
  workYaw.v[549] = target[118]-workYaw.L[710]*workYaw.v[266]-workYaw.L[711]*workYaw.v[306]-workYaw.L[712]*workYaw.v[395]-workYaw.L[713]*workYaw.v[396]-workYaw.L[714]*workYaw.v[545]-workYaw.L[715]*workYaw.v[546]-workYaw.L[716]*workYaw.v[547]-workYaw.L[717]*workYaw.v[548];
  workYaw.v[550] = target[559]-workYaw.L[718]*workYaw.v[437]-workYaw.L[719]*workYaw.v[438]-workYaw.L[720]*workYaw.v[546]-workYaw.L[721]*workYaw.v[547]-workYaw.L[722]*workYaw.v[548]-workYaw.L[723]*workYaw.v[549];
  workYaw.v[551] = target[560]-workYaw.L[724]*workYaw.v[548]-workYaw.L[725]*workYaw.v[549]-workYaw.L[726]*workYaw.v[550];
  workYaw.v[552] = target[120]-workYaw.L[727]*workYaw.v[187]-workYaw.L[728]*workYaw.v[227]-workYaw.L[729]*workYaw.v[551];
  workYaw.v[553] = target[121]-workYaw.L[730]*workYaw.v[267]-workYaw.L[731]*workYaw.v[307]-workYaw.L[732]*workYaw.v[396]-workYaw.L[733]*workYaw.v[397]-workYaw.L[734]*workYaw.v[549]-workYaw.L[735]*workYaw.v[550]-workYaw.L[736]*workYaw.v[551]-workYaw.L[737]*workYaw.v[552];
  workYaw.v[554] = target[562]-workYaw.L[738]*workYaw.v[438]-workYaw.L[739]*workYaw.v[439]-workYaw.L[740]*workYaw.v[550]-workYaw.L[741]*workYaw.v[551]-workYaw.L[742]*workYaw.v[552]-workYaw.L[743]*workYaw.v[553];
  workYaw.v[555] = target[563]-workYaw.L[744]*workYaw.v[552]-workYaw.L[745]*workYaw.v[553]-workYaw.L[746]*workYaw.v[554];
  workYaw.v[556] = target[123]-workYaw.L[747]*workYaw.v[188]-workYaw.L[748]*workYaw.v[228]-workYaw.L[749]*workYaw.v[555];
  workYaw.v[557] = target[124]-workYaw.L[750]*workYaw.v[268]-workYaw.L[751]*workYaw.v[308]-workYaw.L[752]*workYaw.v[397]-workYaw.L[753]*workYaw.v[398]-workYaw.L[754]*workYaw.v[553]-workYaw.L[755]*workYaw.v[554]-workYaw.L[756]*workYaw.v[555]-workYaw.L[757]*workYaw.v[556];
  workYaw.v[558] = target[565]-workYaw.L[758]*workYaw.v[439]-workYaw.L[759]*workYaw.v[440]-workYaw.L[760]*workYaw.v[554]-workYaw.L[761]*workYaw.v[555]-workYaw.L[762]*workYaw.v[556]-workYaw.L[763]*workYaw.v[557];
  workYaw.v[559] = target[566]-workYaw.L[764]*workYaw.v[556]-workYaw.L[765]*workYaw.v[557]-workYaw.L[766]*workYaw.v[558];
  workYaw.v[560] = target[126]-workYaw.L[767]*workYaw.v[189]-workYaw.L[768]*workYaw.v[229]-workYaw.L[769]*workYaw.v[559];
  workYaw.v[561] = target[127]-workYaw.L[770]*workYaw.v[269]-workYaw.L[771]*workYaw.v[309]-workYaw.L[772]*workYaw.v[398]-workYaw.L[773]*workYaw.v[399]-workYaw.L[774]*workYaw.v[557]-workYaw.L[775]*workYaw.v[558]-workYaw.L[776]*workYaw.v[559]-workYaw.L[777]*workYaw.v[560];
  workYaw.v[562] = target[568]-workYaw.L[778]*workYaw.v[440]-workYaw.L[779]*workYaw.v[441]-workYaw.L[780]*workYaw.v[558]-workYaw.L[781]*workYaw.v[559]-workYaw.L[782]*workYaw.v[560]-workYaw.L[783]*workYaw.v[561];
  workYaw.v[563] = target[569]-workYaw.L[784]*workYaw.v[560]-workYaw.L[785]*workYaw.v[561]-workYaw.L[786]*workYaw.v[562];
  workYaw.v[564] = target[129]-workYaw.L[787]*workYaw.v[190]-workYaw.L[788]*workYaw.v[230]-workYaw.L[789]*workYaw.v[563];
  workYaw.v[565] = target[130]-workYaw.L[790]*workYaw.v[270]-workYaw.L[791]*workYaw.v[310]-workYaw.L[792]*workYaw.v[399]-workYaw.L[793]*workYaw.v[400]-workYaw.L[794]*workYaw.v[561]-workYaw.L[795]*workYaw.v[562]-workYaw.L[796]*workYaw.v[563]-workYaw.L[797]*workYaw.v[564];
  workYaw.v[566] = target[571]-workYaw.L[798]*workYaw.v[441]-workYaw.L[799]*workYaw.v[442]-workYaw.L[800]*workYaw.v[562]-workYaw.L[801]*workYaw.v[563]-workYaw.L[802]*workYaw.v[564]-workYaw.L[803]*workYaw.v[565];
  workYaw.v[567] = target[572]-workYaw.L[804]*workYaw.v[564]-workYaw.L[805]*workYaw.v[565]-workYaw.L[806]*workYaw.v[566];
  workYaw.v[568] = target[132]-workYaw.L[807]*workYaw.v[191]-workYaw.L[808]*workYaw.v[231]-workYaw.L[809]*workYaw.v[567];
  workYaw.v[569] = target[133]-workYaw.L[810]*workYaw.v[271]-workYaw.L[811]*workYaw.v[311]-workYaw.L[812]*workYaw.v[400]-workYaw.L[813]*workYaw.v[401]-workYaw.L[814]*workYaw.v[565]-workYaw.L[815]*workYaw.v[566]-workYaw.L[816]*workYaw.v[567]-workYaw.L[817]*workYaw.v[568];
  workYaw.v[570] = target[574]-workYaw.L[818]*workYaw.v[442]-workYaw.L[819]*workYaw.v[443]-workYaw.L[820]*workYaw.v[566]-workYaw.L[821]*workYaw.v[567]-workYaw.L[822]*workYaw.v[568]-workYaw.L[823]*workYaw.v[569];
  workYaw.v[571] = target[575]-workYaw.L[824]*workYaw.v[568]-workYaw.L[825]*workYaw.v[569]-workYaw.L[826]*workYaw.v[570];
  workYaw.v[572] = target[135]-workYaw.L[827]*workYaw.v[192]-workYaw.L[828]*workYaw.v[232]-workYaw.L[829]*workYaw.v[571];
  workYaw.v[573] = target[136]-workYaw.L[830]*workYaw.v[272]-workYaw.L[831]*workYaw.v[312]-workYaw.L[832]*workYaw.v[401]-workYaw.L[833]*workYaw.v[402]-workYaw.L[834]*workYaw.v[569]-workYaw.L[835]*workYaw.v[570]-workYaw.L[836]*workYaw.v[571]-workYaw.L[837]*workYaw.v[572];
  workYaw.v[574] = target[577]-workYaw.L[838]*workYaw.v[443]-workYaw.L[839]*workYaw.v[444]-workYaw.L[840]*workYaw.v[570]-workYaw.L[841]*workYaw.v[571]-workYaw.L[842]*workYaw.v[572]-workYaw.L[843]*workYaw.v[573];
  workYaw.v[575] = target[578]-workYaw.L[844]*workYaw.v[572]-workYaw.L[845]*workYaw.v[573]-workYaw.L[846]*workYaw.v[574];
  workYaw.v[576] = target[138]-workYaw.L[847]*workYaw.v[193]-workYaw.L[848]*workYaw.v[233]-workYaw.L[849]*workYaw.v[575];
  workYaw.v[577] = target[139]-workYaw.L[850]*workYaw.v[273]-workYaw.L[851]*workYaw.v[313]-workYaw.L[852]*workYaw.v[402]-workYaw.L[853]*workYaw.v[403]-workYaw.L[854]*workYaw.v[573]-workYaw.L[855]*workYaw.v[574]-workYaw.L[856]*workYaw.v[575]-workYaw.L[857]*workYaw.v[576];
  workYaw.v[578] = target[580]-workYaw.L[858]*workYaw.v[444]-workYaw.L[859]*workYaw.v[445]-workYaw.L[860]*workYaw.v[574]-workYaw.L[861]*workYaw.v[575]-workYaw.L[862]*workYaw.v[576]-workYaw.L[863]*workYaw.v[577];
  workYaw.v[579] = target[581]-workYaw.L[864]*workYaw.v[576]-workYaw.L[865]*workYaw.v[577]-workYaw.L[866]*workYaw.v[578];
  workYaw.v[580] = target[141]-workYaw.L[867]*workYaw.v[194]-workYaw.L[868]*workYaw.v[234]-workYaw.L[869]*workYaw.v[579];
  workYaw.v[581] = target[142]-workYaw.L[870]*workYaw.v[274]-workYaw.L[871]*workYaw.v[314]-workYaw.L[872]*workYaw.v[403]-workYaw.L[873]*workYaw.v[404]-workYaw.L[874]*workYaw.v[577]-workYaw.L[875]*workYaw.v[578]-workYaw.L[876]*workYaw.v[579]-workYaw.L[877]*workYaw.v[580];
  workYaw.v[582] = target[583]-workYaw.L[878]*workYaw.v[445]-workYaw.L[879]*workYaw.v[446]-workYaw.L[880]*workYaw.v[578]-workYaw.L[881]*workYaw.v[579]-workYaw.L[882]*workYaw.v[580]-workYaw.L[883]*workYaw.v[581];
  workYaw.v[583] = target[584]-workYaw.L[884]*workYaw.v[580]-workYaw.L[885]*workYaw.v[581]-workYaw.L[886]*workYaw.v[582];
  workYaw.v[584] = target[144]-workYaw.L[887]*workYaw.v[195]-workYaw.L[888]*workYaw.v[235]-workYaw.L[889]*workYaw.v[583];
  workYaw.v[585] = target[145]-workYaw.L[890]*workYaw.v[275]-workYaw.L[891]*workYaw.v[315]-workYaw.L[892]*workYaw.v[404]-workYaw.L[893]*workYaw.v[405]-workYaw.L[894]*workYaw.v[581]-workYaw.L[895]*workYaw.v[582]-workYaw.L[896]*workYaw.v[583]-workYaw.L[897]*workYaw.v[584];
  workYaw.v[586] = target[586]-workYaw.L[898]*workYaw.v[446]-workYaw.L[899]*workYaw.v[447]-workYaw.L[900]*workYaw.v[582]-workYaw.L[901]*workYaw.v[583]-workYaw.L[902]*workYaw.v[584]-workYaw.L[903]*workYaw.v[585];
  workYaw.v[587] = target[587]-workYaw.L[904]*workYaw.v[584]-workYaw.L[905]*workYaw.v[585]-workYaw.L[906]*workYaw.v[586];
  workYaw.v[588] = target[147]-workYaw.L[907]*workYaw.v[196]-workYaw.L[908]*workYaw.v[236]-workYaw.L[909]*workYaw.v[587];
  workYaw.v[589] = target[148]-workYaw.L[910]*workYaw.v[276]-workYaw.L[911]*workYaw.v[316]-workYaw.L[912]*workYaw.v[405]-workYaw.L[913]*workYaw.v[406]-workYaw.L[914]*workYaw.v[585]-workYaw.L[915]*workYaw.v[586]-workYaw.L[916]*workYaw.v[587]-workYaw.L[917]*workYaw.v[588];
  workYaw.v[590] = target[589]-workYaw.L[918]*workYaw.v[447]-workYaw.L[919]*workYaw.v[448]-workYaw.L[920]*workYaw.v[586]-workYaw.L[921]*workYaw.v[587]-workYaw.L[922]*workYaw.v[588]-workYaw.L[923]*workYaw.v[589];
  workYaw.v[591] = target[590]-workYaw.L[924]*workYaw.v[588]-workYaw.L[925]*workYaw.v[589]-workYaw.L[926]*workYaw.v[590];
  workYaw.v[592] = target[150]-workYaw.L[927]*workYaw.v[197]-workYaw.L[928]*workYaw.v[237]-workYaw.L[929]*workYaw.v[591];
  workYaw.v[593] = target[151]-workYaw.L[930]*workYaw.v[277]-workYaw.L[931]*workYaw.v[317]-workYaw.L[932]*workYaw.v[406]-workYaw.L[933]*workYaw.v[407]-workYaw.L[934]*workYaw.v[589]-workYaw.L[935]*workYaw.v[590]-workYaw.L[936]*workYaw.v[591]-workYaw.L[937]*workYaw.v[592];
  workYaw.v[594] = target[592]-workYaw.L[938]*workYaw.v[448]-workYaw.L[939]*workYaw.v[449]-workYaw.L[940]*workYaw.v[590]-workYaw.L[941]*workYaw.v[591]-workYaw.L[942]*workYaw.v[592]-workYaw.L[943]*workYaw.v[593];
  workYaw.v[595] = target[593]-workYaw.L[944]*workYaw.v[592]-workYaw.L[945]*workYaw.v[593]-workYaw.L[946]*workYaw.v[594];
  workYaw.v[596] = target[595]-workYaw.L[947]*workYaw.v[449]-workYaw.L[948]*workYaw.v[450]-workYaw.L[949]*workYaw.v[594]-workYaw.L[950]*workYaw.v[595];
  workYaw.v[597] = target[596];
  workYaw.v[598] = target[153]-workYaw.L[951]*workYaw.v[198]-workYaw.L[952]*workYaw.v[238]-workYaw.L[953]*workYaw.v[595]-workYaw.L[954]*workYaw.v[596]-workYaw.L[955]*workYaw.v[597];
  workYaw.v[599] = target[154]-workYaw.L[956]*workYaw.v[278]-workYaw.L[957]*workYaw.v[318]-workYaw.L[958]*workYaw.v[407]-workYaw.L[959]*workYaw.v[408]-workYaw.L[960]*workYaw.v[410]-workYaw.L[961]*workYaw.v[593]-workYaw.L[962]*workYaw.v[594]-workYaw.L[963]*workYaw.v[595]-workYaw.L[964]*workYaw.v[596]-workYaw.L[965]*workYaw.v[597]-workYaw.L[966]*workYaw.v[598];
  workYaw.v[600] = target[156]-workYaw.L[967]*workYaw.v[199]-workYaw.L[968]*workYaw.v[239]-workYaw.L[969]*workYaw.v[409]-workYaw.L[970]*workYaw.v[410]-workYaw.L[971]*workYaw.v[450]-workYaw.L[972]*workYaw.v[596]-workYaw.L[973]*workYaw.v[597]-workYaw.L[974]*workYaw.v[598]-workYaw.L[975]*workYaw.v[599];
  /* Diagonal scaling. Assume correctness of workYaw.d_inv. */
  for (i = 0; i < 601; i++)
    workYaw.v[i] *= workYaw.d_inv[i];
  /* Back substitution */
  workYaw.v[599] -= workYaw.L[975]*workYaw.v[600];
  workYaw.v[598] -= workYaw.L[966]*workYaw.v[599]+workYaw.L[974]*workYaw.v[600];
  workYaw.v[597] -= workYaw.L[955]*workYaw.v[598]+workYaw.L[965]*workYaw.v[599]+workYaw.L[973]*workYaw.v[600];
  workYaw.v[596] -= workYaw.L[954]*workYaw.v[598]+workYaw.L[964]*workYaw.v[599]+workYaw.L[972]*workYaw.v[600];
  workYaw.v[595] -= workYaw.L[950]*workYaw.v[596]+workYaw.L[953]*workYaw.v[598]+workYaw.L[963]*workYaw.v[599];
  workYaw.v[594] -= workYaw.L[946]*workYaw.v[595]+workYaw.L[949]*workYaw.v[596]+workYaw.L[962]*workYaw.v[599];
  workYaw.v[593] -= workYaw.L[943]*workYaw.v[594]+workYaw.L[945]*workYaw.v[595]+workYaw.L[961]*workYaw.v[599];
  workYaw.v[592] -= workYaw.L[937]*workYaw.v[593]+workYaw.L[942]*workYaw.v[594]+workYaw.L[944]*workYaw.v[595];
  workYaw.v[591] -= workYaw.L[929]*workYaw.v[592]+workYaw.L[936]*workYaw.v[593]+workYaw.L[941]*workYaw.v[594];
  workYaw.v[590] -= workYaw.L[926]*workYaw.v[591]+workYaw.L[935]*workYaw.v[593]+workYaw.L[940]*workYaw.v[594];
  workYaw.v[589] -= workYaw.L[923]*workYaw.v[590]+workYaw.L[925]*workYaw.v[591]+workYaw.L[934]*workYaw.v[593];
  workYaw.v[588] -= workYaw.L[917]*workYaw.v[589]+workYaw.L[922]*workYaw.v[590]+workYaw.L[924]*workYaw.v[591];
  workYaw.v[587] -= workYaw.L[909]*workYaw.v[588]+workYaw.L[916]*workYaw.v[589]+workYaw.L[921]*workYaw.v[590];
  workYaw.v[586] -= workYaw.L[906]*workYaw.v[587]+workYaw.L[915]*workYaw.v[589]+workYaw.L[920]*workYaw.v[590];
  workYaw.v[585] -= workYaw.L[903]*workYaw.v[586]+workYaw.L[905]*workYaw.v[587]+workYaw.L[914]*workYaw.v[589];
  workYaw.v[584] -= workYaw.L[897]*workYaw.v[585]+workYaw.L[902]*workYaw.v[586]+workYaw.L[904]*workYaw.v[587];
  workYaw.v[583] -= workYaw.L[889]*workYaw.v[584]+workYaw.L[896]*workYaw.v[585]+workYaw.L[901]*workYaw.v[586];
  workYaw.v[582] -= workYaw.L[886]*workYaw.v[583]+workYaw.L[895]*workYaw.v[585]+workYaw.L[900]*workYaw.v[586];
  workYaw.v[581] -= workYaw.L[883]*workYaw.v[582]+workYaw.L[885]*workYaw.v[583]+workYaw.L[894]*workYaw.v[585];
  workYaw.v[580] -= workYaw.L[877]*workYaw.v[581]+workYaw.L[882]*workYaw.v[582]+workYaw.L[884]*workYaw.v[583];
  workYaw.v[579] -= workYaw.L[869]*workYaw.v[580]+workYaw.L[876]*workYaw.v[581]+workYaw.L[881]*workYaw.v[582];
  workYaw.v[578] -= workYaw.L[866]*workYaw.v[579]+workYaw.L[875]*workYaw.v[581]+workYaw.L[880]*workYaw.v[582];
  workYaw.v[577] -= workYaw.L[863]*workYaw.v[578]+workYaw.L[865]*workYaw.v[579]+workYaw.L[874]*workYaw.v[581];
  workYaw.v[576] -= workYaw.L[857]*workYaw.v[577]+workYaw.L[862]*workYaw.v[578]+workYaw.L[864]*workYaw.v[579];
  workYaw.v[575] -= workYaw.L[849]*workYaw.v[576]+workYaw.L[856]*workYaw.v[577]+workYaw.L[861]*workYaw.v[578];
  workYaw.v[574] -= workYaw.L[846]*workYaw.v[575]+workYaw.L[855]*workYaw.v[577]+workYaw.L[860]*workYaw.v[578];
  workYaw.v[573] -= workYaw.L[843]*workYaw.v[574]+workYaw.L[845]*workYaw.v[575]+workYaw.L[854]*workYaw.v[577];
  workYaw.v[572] -= workYaw.L[837]*workYaw.v[573]+workYaw.L[842]*workYaw.v[574]+workYaw.L[844]*workYaw.v[575];
  workYaw.v[571] -= workYaw.L[829]*workYaw.v[572]+workYaw.L[836]*workYaw.v[573]+workYaw.L[841]*workYaw.v[574];
  workYaw.v[570] -= workYaw.L[826]*workYaw.v[571]+workYaw.L[835]*workYaw.v[573]+workYaw.L[840]*workYaw.v[574];
  workYaw.v[569] -= workYaw.L[823]*workYaw.v[570]+workYaw.L[825]*workYaw.v[571]+workYaw.L[834]*workYaw.v[573];
  workYaw.v[568] -= workYaw.L[817]*workYaw.v[569]+workYaw.L[822]*workYaw.v[570]+workYaw.L[824]*workYaw.v[571];
  workYaw.v[567] -= workYaw.L[809]*workYaw.v[568]+workYaw.L[816]*workYaw.v[569]+workYaw.L[821]*workYaw.v[570];
  workYaw.v[566] -= workYaw.L[806]*workYaw.v[567]+workYaw.L[815]*workYaw.v[569]+workYaw.L[820]*workYaw.v[570];
  workYaw.v[565] -= workYaw.L[803]*workYaw.v[566]+workYaw.L[805]*workYaw.v[567]+workYaw.L[814]*workYaw.v[569];
  workYaw.v[564] -= workYaw.L[797]*workYaw.v[565]+workYaw.L[802]*workYaw.v[566]+workYaw.L[804]*workYaw.v[567];
  workYaw.v[563] -= workYaw.L[789]*workYaw.v[564]+workYaw.L[796]*workYaw.v[565]+workYaw.L[801]*workYaw.v[566];
  workYaw.v[562] -= workYaw.L[786]*workYaw.v[563]+workYaw.L[795]*workYaw.v[565]+workYaw.L[800]*workYaw.v[566];
  workYaw.v[561] -= workYaw.L[783]*workYaw.v[562]+workYaw.L[785]*workYaw.v[563]+workYaw.L[794]*workYaw.v[565];
  workYaw.v[560] -= workYaw.L[777]*workYaw.v[561]+workYaw.L[782]*workYaw.v[562]+workYaw.L[784]*workYaw.v[563];
  workYaw.v[559] -= workYaw.L[769]*workYaw.v[560]+workYaw.L[776]*workYaw.v[561]+workYaw.L[781]*workYaw.v[562];
  workYaw.v[558] -= workYaw.L[766]*workYaw.v[559]+workYaw.L[775]*workYaw.v[561]+workYaw.L[780]*workYaw.v[562];
  workYaw.v[557] -= workYaw.L[763]*workYaw.v[558]+workYaw.L[765]*workYaw.v[559]+workYaw.L[774]*workYaw.v[561];
  workYaw.v[556] -= workYaw.L[757]*workYaw.v[557]+workYaw.L[762]*workYaw.v[558]+workYaw.L[764]*workYaw.v[559];
  workYaw.v[555] -= workYaw.L[749]*workYaw.v[556]+workYaw.L[756]*workYaw.v[557]+workYaw.L[761]*workYaw.v[558];
  workYaw.v[554] -= workYaw.L[746]*workYaw.v[555]+workYaw.L[755]*workYaw.v[557]+workYaw.L[760]*workYaw.v[558];
  workYaw.v[553] -= workYaw.L[743]*workYaw.v[554]+workYaw.L[745]*workYaw.v[555]+workYaw.L[754]*workYaw.v[557];
  workYaw.v[552] -= workYaw.L[737]*workYaw.v[553]+workYaw.L[742]*workYaw.v[554]+workYaw.L[744]*workYaw.v[555];
  workYaw.v[551] -= workYaw.L[729]*workYaw.v[552]+workYaw.L[736]*workYaw.v[553]+workYaw.L[741]*workYaw.v[554];
  workYaw.v[550] -= workYaw.L[726]*workYaw.v[551]+workYaw.L[735]*workYaw.v[553]+workYaw.L[740]*workYaw.v[554];
  workYaw.v[549] -= workYaw.L[723]*workYaw.v[550]+workYaw.L[725]*workYaw.v[551]+workYaw.L[734]*workYaw.v[553];
  workYaw.v[548] -= workYaw.L[717]*workYaw.v[549]+workYaw.L[722]*workYaw.v[550]+workYaw.L[724]*workYaw.v[551];
  workYaw.v[547] -= workYaw.L[709]*workYaw.v[548]+workYaw.L[716]*workYaw.v[549]+workYaw.L[721]*workYaw.v[550];
  workYaw.v[546] -= workYaw.L[706]*workYaw.v[547]+workYaw.L[715]*workYaw.v[549]+workYaw.L[720]*workYaw.v[550];
  workYaw.v[545] -= workYaw.L[703]*workYaw.v[546]+workYaw.L[705]*workYaw.v[547]+workYaw.L[714]*workYaw.v[549];
  workYaw.v[544] -= workYaw.L[697]*workYaw.v[545]+workYaw.L[702]*workYaw.v[546]+workYaw.L[704]*workYaw.v[547];
  workYaw.v[543] -= workYaw.L[689]*workYaw.v[544]+workYaw.L[696]*workYaw.v[545]+workYaw.L[701]*workYaw.v[546];
  workYaw.v[542] -= workYaw.L[686]*workYaw.v[543]+workYaw.L[695]*workYaw.v[545]+workYaw.L[700]*workYaw.v[546];
  workYaw.v[541] -= workYaw.L[683]*workYaw.v[542]+workYaw.L[685]*workYaw.v[543]+workYaw.L[694]*workYaw.v[545];
  workYaw.v[540] -= workYaw.L[677]*workYaw.v[541]+workYaw.L[682]*workYaw.v[542]+workYaw.L[684]*workYaw.v[543];
  workYaw.v[539] -= workYaw.L[669]*workYaw.v[540]+workYaw.L[676]*workYaw.v[541]+workYaw.L[681]*workYaw.v[542];
  workYaw.v[538] -= workYaw.L[666]*workYaw.v[539]+workYaw.L[675]*workYaw.v[541]+workYaw.L[680]*workYaw.v[542];
  workYaw.v[537] -= workYaw.L[663]*workYaw.v[538]+workYaw.L[665]*workYaw.v[539]+workYaw.L[674]*workYaw.v[541];
  workYaw.v[536] -= workYaw.L[657]*workYaw.v[537]+workYaw.L[662]*workYaw.v[538]+workYaw.L[664]*workYaw.v[539];
  workYaw.v[535] -= workYaw.L[649]*workYaw.v[536]+workYaw.L[656]*workYaw.v[537]+workYaw.L[661]*workYaw.v[538];
  workYaw.v[534] -= workYaw.L[646]*workYaw.v[535]+workYaw.L[655]*workYaw.v[537]+workYaw.L[660]*workYaw.v[538];
  workYaw.v[533] -= workYaw.L[643]*workYaw.v[534]+workYaw.L[645]*workYaw.v[535]+workYaw.L[654]*workYaw.v[537];
  workYaw.v[532] -= workYaw.L[637]*workYaw.v[533]+workYaw.L[642]*workYaw.v[534]+workYaw.L[644]*workYaw.v[535];
  workYaw.v[531] -= workYaw.L[629]*workYaw.v[532]+workYaw.L[636]*workYaw.v[533]+workYaw.L[641]*workYaw.v[534];
  workYaw.v[530] -= workYaw.L[626]*workYaw.v[531]+workYaw.L[635]*workYaw.v[533]+workYaw.L[640]*workYaw.v[534];
  workYaw.v[529] -= workYaw.L[623]*workYaw.v[530]+workYaw.L[625]*workYaw.v[531]+workYaw.L[634]*workYaw.v[533];
  workYaw.v[528] -= workYaw.L[617]*workYaw.v[529]+workYaw.L[622]*workYaw.v[530]+workYaw.L[624]*workYaw.v[531];
  workYaw.v[527] -= workYaw.L[609]*workYaw.v[528]+workYaw.L[616]*workYaw.v[529]+workYaw.L[621]*workYaw.v[530];
  workYaw.v[526] -= workYaw.L[606]*workYaw.v[527]+workYaw.L[615]*workYaw.v[529]+workYaw.L[620]*workYaw.v[530];
  workYaw.v[525] -= workYaw.L[603]*workYaw.v[526]+workYaw.L[605]*workYaw.v[527]+workYaw.L[614]*workYaw.v[529];
  workYaw.v[524] -= workYaw.L[597]*workYaw.v[525]+workYaw.L[602]*workYaw.v[526]+workYaw.L[604]*workYaw.v[527];
  workYaw.v[523] -= workYaw.L[589]*workYaw.v[524]+workYaw.L[596]*workYaw.v[525]+workYaw.L[601]*workYaw.v[526];
  workYaw.v[522] -= workYaw.L[586]*workYaw.v[523]+workYaw.L[595]*workYaw.v[525]+workYaw.L[600]*workYaw.v[526];
  workYaw.v[521] -= workYaw.L[583]*workYaw.v[522]+workYaw.L[585]*workYaw.v[523]+workYaw.L[594]*workYaw.v[525];
  workYaw.v[520] -= workYaw.L[577]*workYaw.v[521]+workYaw.L[582]*workYaw.v[522]+workYaw.L[584]*workYaw.v[523];
  workYaw.v[519] -= workYaw.L[569]*workYaw.v[520]+workYaw.L[576]*workYaw.v[521]+workYaw.L[581]*workYaw.v[522];
  workYaw.v[518] -= workYaw.L[566]*workYaw.v[519]+workYaw.L[575]*workYaw.v[521]+workYaw.L[580]*workYaw.v[522];
  workYaw.v[517] -= workYaw.L[563]*workYaw.v[518]+workYaw.L[565]*workYaw.v[519]+workYaw.L[574]*workYaw.v[521];
  workYaw.v[516] -= workYaw.L[557]*workYaw.v[517]+workYaw.L[562]*workYaw.v[518]+workYaw.L[564]*workYaw.v[519];
  workYaw.v[515] -= workYaw.L[549]*workYaw.v[516]+workYaw.L[556]*workYaw.v[517]+workYaw.L[561]*workYaw.v[518];
  workYaw.v[514] -= workYaw.L[546]*workYaw.v[515]+workYaw.L[555]*workYaw.v[517]+workYaw.L[560]*workYaw.v[518];
  workYaw.v[513] -= workYaw.L[543]*workYaw.v[514]+workYaw.L[545]*workYaw.v[515]+workYaw.L[554]*workYaw.v[517];
  workYaw.v[512] -= workYaw.L[537]*workYaw.v[513]+workYaw.L[542]*workYaw.v[514]+workYaw.L[544]*workYaw.v[515];
  workYaw.v[511] -= workYaw.L[529]*workYaw.v[512]+workYaw.L[536]*workYaw.v[513]+workYaw.L[541]*workYaw.v[514];
  workYaw.v[510] -= workYaw.L[526]*workYaw.v[511]+workYaw.L[535]*workYaw.v[513]+workYaw.L[540]*workYaw.v[514];
  workYaw.v[509] -= workYaw.L[523]*workYaw.v[510]+workYaw.L[525]*workYaw.v[511]+workYaw.L[534]*workYaw.v[513];
  workYaw.v[508] -= workYaw.L[517]*workYaw.v[509]+workYaw.L[522]*workYaw.v[510]+workYaw.L[524]*workYaw.v[511];
  workYaw.v[507] -= workYaw.L[509]*workYaw.v[508]+workYaw.L[516]*workYaw.v[509]+workYaw.L[521]*workYaw.v[510];
  workYaw.v[506] -= workYaw.L[506]*workYaw.v[507]+workYaw.L[515]*workYaw.v[509]+workYaw.L[520]*workYaw.v[510];
  workYaw.v[505] -= workYaw.L[503]*workYaw.v[506]+workYaw.L[505]*workYaw.v[507]+workYaw.L[514]*workYaw.v[509];
  workYaw.v[504] -= workYaw.L[497]*workYaw.v[505]+workYaw.L[502]*workYaw.v[506]+workYaw.L[504]*workYaw.v[507];
  workYaw.v[503] -= workYaw.L[489]*workYaw.v[504]+workYaw.L[496]*workYaw.v[505]+workYaw.L[501]*workYaw.v[506];
  workYaw.v[502] -= workYaw.L[486]*workYaw.v[503]+workYaw.L[495]*workYaw.v[505]+workYaw.L[500]*workYaw.v[506];
  workYaw.v[501] -= workYaw.L[483]*workYaw.v[502]+workYaw.L[485]*workYaw.v[503]+workYaw.L[494]*workYaw.v[505];
  workYaw.v[500] -= workYaw.L[477]*workYaw.v[501]+workYaw.L[482]*workYaw.v[502]+workYaw.L[484]*workYaw.v[503];
  workYaw.v[499] -= workYaw.L[469]*workYaw.v[500]+workYaw.L[476]*workYaw.v[501]+workYaw.L[481]*workYaw.v[502];
  workYaw.v[498] -= workYaw.L[466]*workYaw.v[499]+workYaw.L[475]*workYaw.v[501]+workYaw.L[480]*workYaw.v[502];
  workYaw.v[497] -= workYaw.L[463]*workYaw.v[498]+workYaw.L[465]*workYaw.v[499]+workYaw.L[474]*workYaw.v[501];
  workYaw.v[496] -= workYaw.L[457]*workYaw.v[497]+workYaw.L[462]*workYaw.v[498]+workYaw.L[464]*workYaw.v[499];
  workYaw.v[495] -= workYaw.L[449]*workYaw.v[496]+workYaw.L[456]*workYaw.v[497]+workYaw.L[461]*workYaw.v[498];
  workYaw.v[494] -= workYaw.L[446]*workYaw.v[495]+workYaw.L[455]*workYaw.v[497]+workYaw.L[460]*workYaw.v[498];
  workYaw.v[493] -= workYaw.L[443]*workYaw.v[494]+workYaw.L[445]*workYaw.v[495]+workYaw.L[454]*workYaw.v[497];
  workYaw.v[492] -= workYaw.L[437]*workYaw.v[493]+workYaw.L[442]*workYaw.v[494]+workYaw.L[444]*workYaw.v[495];
  workYaw.v[491] -= workYaw.L[429]*workYaw.v[492]+workYaw.L[436]*workYaw.v[493]+workYaw.L[441]*workYaw.v[494];
  workYaw.v[490] -= workYaw.L[426]*workYaw.v[491]+workYaw.L[435]*workYaw.v[493]+workYaw.L[440]*workYaw.v[494];
  workYaw.v[489] -= workYaw.L[423]*workYaw.v[490]+workYaw.L[425]*workYaw.v[491]+workYaw.L[434]*workYaw.v[493];
  workYaw.v[488] -= workYaw.L[417]*workYaw.v[489]+workYaw.L[422]*workYaw.v[490]+workYaw.L[424]*workYaw.v[491];
  workYaw.v[487] -= workYaw.L[409]*workYaw.v[488]+workYaw.L[416]*workYaw.v[489]+workYaw.L[421]*workYaw.v[490];
  workYaw.v[486] -= workYaw.L[406]*workYaw.v[487]+workYaw.L[415]*workYaw.v[489]+workYaw.L[420]*workYaw.v[490];
  workYaw.v[485] -= workYaw.L[403]*workYaw.v[486]+workYaw.L[405]*workYaw.v[487]+workYaw.L[414]*workYaw.v[489];
  workYaw.v[484] -= workYaw.L[397]*workYaw.v[485]+workYaw.L[402]*workYaw.v[486]+workYaw.L[404]*workYaw.v[487];
  workYaw.v[483] -= workYaw.L[389]*workYaw.v[484]+workYaw.L[396]*workYaw.v[485]+workYaw.L[401]*workYaw.v[486];
  workYaw.v[482] -= workYaw.L[386]*workYaw.v[483]+workYaw.L[395]*workYaw.v[485]+workYaw.L[400]*workYaw.v[486];
  workYaw.v[481] -= workYaw.L[383]*workYaw.v[482]+workYaw.L[385]*workYaw.v[483]+workYaw.L[394]*workYaw.v[485];
  workYaw.v[480] -= workYaw.L[377]*workYaw.v[481]+workYaw.L[382]*workYaw.v[482]+workYaw.L[384]*workYaw.v[483];
  workYaw.v[479] -= workYaw.L[369]*workYaw.v[480]+workYaw.L[376]*workYaw.v[481]+workYaw.L[381]*workYaw.v[482];
  workYaw.v[478] -= workYaw.L[366]*workYaw.v[479]+workYaw.L[375]*workYaw.v[481]+workYaw.L[380]*workYaw.v[482];
  workYaw.v[477] -= workYaw.L[363]*workYaw.v[478]+workYaw.L[365]*workYaw.v[479]+workYaw.L[374]*workYaw.v[481];
  workYaw.v[476] -= workYaw.L[357]*workYaw.v[477]+workYaw.L[362]*workYaw.v[478]+workYaw.L[364]*workYaw.v[479];
  workYaw.v[475] -= workYaw.L[349]*workYaw.v[476]+workYaw.L[356]*workYaw.v[477]+workYaw.L[361]*workYaw.v[478];
  workYaw.v[474] -= workYaw.L[346]*workYaw.v[475]+workYaw.L[355]*workYaw.v[477]+workYaw.L[360]*workYaw.v[478];
  workYaw.v[473] -= workYaw.L[343]*workYaw.v[474]+workYaw.L[345]*workYaw.v[475]+workYaw.L[354]*workYaw.v[477];
  workYaw.v[472] -= workYaw.L[337]*workYaw.v[473]+workYaw.L[342]*workYaw.v[474]+workYaw.L[344]*workYaw.v[475];
  workYaw.v[471] -= workYaw.L[329]*workYaw.v[472]+workYaw.L[336]*workYaw.v[473]+workYaw.L[341]*workYaw.v[474];
  workYaw.v[470] -= workYaw.L[326]*workYaw.v[471]+workYaw.L[335]*workYaw.v[473]+workYaw.L[340]*workYaw.v[474];
  workYaw.v[469] -= workYaw.L[323]*workYaw.v[470]+workYaw.L[325]*workYaw.v[471]+workYaw.L[334]*workYaw.v[473];
  workYaw.v[468] -= workYaw.L[317]*workYaw.v[469]+workYaw.L[322]*workYaw.v[470]+workYaw.L[324]*workYaw.v[471];
  workYaw.v[467] -= workYaw.L[309]*workYaw.v[468]+workYaw.L[316]*workYaw.v[469]+workYaw.L[321]*workYaw.v[470];
  workYaw.v[466] -= workYaw.L[306]*workYaw.v[467]+workYaw.L[315]*workYaw.v[469]+workYaw.L[320]*workYaw.v[470];
  workYaw.v[465] -= workYaw.L[303]*workYaw.v[466]+workYaw.L[305]*workYaw.v[467]+workYaw.L[314]*workYaw.v[469];
  workYaw.v[464] -= workYaw.L[297]*workYaw.v[465]+workYaw.L[302]*workYaw.v[466]+workYaw.L[304]*workYaw.v[467];
  workYaw.v[463] -= workYaw.L[289]*workYaw.v[464]+workYaw.L[296]*workYaw.v[465]+workYaw.L[301]*workYaw.v[466];
  workYaw.v[462] -= workYaw.L[286]*workYaw.v[463]+workYaw.L[295]*workYaw.v[465]+workYaw.L[300]*workYaw.v[466];
  workYaw.v[461] -= workYaw.L[283]*workYaw.v[462]+workYaw.L[285]*workYaw.v[463]+workYaw.L[294]*workYaw.v[465];
  workYaw.v[460] -= workYaw.L[277]*workYaw.v[461]+workYaw.L[282]*workYaw.v[462]+workYaw.L[284]*workYaw.v[463];
  workYaw.v[459] -= workYaw.L[269]*workYaw.v[460]+workYaw.L[276]*workYaw.v[461]+workYaw.L[281]*workYaw.v[462];
  workYaw.v[458] -= workYaw.L[266]*workYaw.v[459]+workYaw.L[275]*workYaw.v[461]+workYaw.L[280]*workYaw.v[462];
  workYaw.v[457] -= workYaw.L[263]*workYaw.v[458]+workYaw.L[265]*workYaw.v[459]+workYaw.L[274]*workYaw.v[461];
  workYaw.v[456] -= workYaw.L[257]*workYaw.v[457]+workYaw.L[262]*workYaw.v[458]+workYaw.L[264]*workYaw.v[459];
  workYaw.v[455] -= workYaw.L[249]*workYaw.v[456]+workYaw.L[256]*workYaw.v[457]+workYaw.L[261]*workYaw.v[458];
  workYaw.v[454] -= workYaw.L[246]*workYaw.v[455]+workYaw.L[255]*workYaw.v[457]+workYaw.L[260]*workYaw.v[458];
  workYaw.v[453] -= workYaw.L[243]*workYaw.v[454]+workYaw.L[245]*workYaw.v[455]+workYaw.L[254]*workYaw.v[457];
  workYaw.v[452] -= workYaw.L[238]*workYaw.v[453]+workYaw.L[242]*workYaw.v[454]+workYaw.L[244]*workYaw.v[455];
  workYaw.v[451] -= workYaw.L[231]*workYaw.v[452]+workYaw.L[237]*workYaw.v[453]+workYaw.L[241]*workYaw.v[454];
  workYaw.v[450] -= workYaw.L[948]*workYaw.v[596]+workYaw.L[971]*workYaw.v[600];
  workYaw.v[449] -= workYaw.L[939]*workYaw.v[594]+workYaw.L[947]*workYaw.v[596];
  workYaw.v[448] -= workYaw.L[919]*workYaw.v[590]+workYaw.L[938]*workYaw.v[594];
  workYaw.v[447] -= workYaw.L[899]*workYaw.v[586]+workYaw.L[918]*workYaw.v[590];
  workYaw.v[446] -= workYaw.L[879]*workYaw.v[582]+workYaw.L[898]*workYaw.v[586];
  workYaw.v[445] -= workYaw.L[859]*workYaw.v[578]+workYaw.L[878]*workYaw.v[582];
  workYaw.v[444] -= workYaw.L[839]*workYaw.v[574]+workYaw.L[858]*workYaw.v[578];
  workYaw.v[443] -= workYaw.L[819]*workYaw.v[570]+workYaw.L[838]*workYaw.v[574];
  workYaw.v[442] -= workYaw.L[799]*workYaw.v[566]+workYaw.L[818]*workYaw.v[570];
  workYaw.v[441] -= workYaw.L[779]*workYaw.v[562]+workYaw.L[798]*workYaw.v[566];
  workYaw.v[440] -= workYaw.L[759]*workYaw.v[558]+workYaw.L[778]*workYaw.v[562];
  workYaw.v[439] -= workYaw.L[739]*workYaw.v[554]+workYaw.L[758]*workYaw.v[558];
  workYaw.v[438] -= workYaw.L[719]*workYaw.v[550]+workYaw.L[738]*workYaw.v[554];
  workYaw.v[437] -= workYaw.L[699]*workYaw.v[546]+workYaw.L[718]*workYaw.v[550];
  workYaw.v[436] -= workYaw.L[679]*workYaw.v[542]+workYaw.L[698]*workYaw.v[546];
  workYaw.v[435] -= workYaw.L[659]*workYaw.v[538]+workYaw.L[678]*workYaw.v[542];
  workYaw.v[434] -= workYaw.L[639]*workYaw.v[534]+workYaw.L[658]*workYaw.v[538];
  workYaw.v[433] -= workYaw.L[619]*workYaw.v[530]+workYaw.L[638]*workYaw.v[534];
  workYaw.v[432] -= workYaw.L[599]*workYaw.v[526]+workYaw.L[618]*workYaw.v[530];
  workYaw.v[431] -= workYaw.L[579]*workYaw.v[522]+workYaw.L[598]*workYaw.v[526];
  workYaw.v[430] -= workYaw.L[559]*workYaw.v[518]+workYaw.L[578]*workYaw.v[522];
  workYaw.v[429] -= workYaw.L[539]*workYaw.v[514]+workYaw.L[558]*workYaw.v[518];
  workYaw.v[428] -= workYaw.L[519]*workYaw.v[510]+workYaw.L[538]*workYaw.v[514];
  workYaw.v[427] -= workYaw.L[499]*workYaw.v[506]+workYaw.L[518]*workYaw.v[510];
  workYaw.v[426] -= workYaw.L[479]*workYaw.v[502]+workYaw.L[498]*workYaw.v[506];
  workYaw.v[425] -= workYaw.L[459]*workYaw.v[498]+workYaw.L[478]*workYaw.v[502];
  workYaw.v[424] -= workYaw.L[439]*workYaw.v[494]+workYaw.L[458]*workYaw.v[498];
  workYaw.v[423] -= workYaw.L[419]*workYaw.v[490]+workYaw.L[438]*workYaw.v[494];
  workYaw.v[422] -= workYaw.L[399]*workYaw.v[486]+workYaw.L[418]*workYaw.v[490];
  workYaw.v[421] -= workYaw.L[379]*workYaw.v[482]+workYaw.L[398]*workYaw.v[486];
  workYaw.v[420] -= workYaw.L[359]*workYaw.v[478]+workYaw.L[378]*workYaw.v[482];
  workYaw.v[419] -= workYaw.L[339]*workYaw.v[474]+workYaw.L[358]*workYaw.v[478];
  workYaw.v[418] -= workYaw.L[319]*workYaw.v[470]+workYaw.L[338]*workYaw.v[474];
  workYaw.v[417] -= workYaw.L[299]*workYaw.v[466]+workYaw.L[318]*workYaw.v[470];
  workYaw.v[416] -= workYaw.L[279]*workYaw.v[462]+workYaw.L[298]*workYaw.v[466];
  workYaw.v[415] -= workYaw.L[259]*workYaw.v[458]+workYaw.L[278]*workYaw.v[462];
  workYaw.v[414] -= workYaw.L[240]*workYaw.v[454]+workYaw.L[258]*workYaw.v[458];
  workYaw.v[413] -= workYaw.L[228]*workYaw.v[451]+workYaw.L[239]*workYaw.v[454];
  workYaw.v[412] -= workYaw.L[227]*workYaw.v[451]+workYaw.L[236]*workYaw.v[453];
  workYaw.v[411] -= workYaw.L[224]*workYaw.v[413]+workYaw.L[226]*workYaw.v[451];
  workYaw.v[410] -= workYaw.L[960]*workYaw.v[599]+workYaw.L[970]*workYaw.v[600];
  workYaw.v[409] -= workYaw.L[225]*workYaw.v[450]+workYaw.L[969]*workYaw.v[600];
  workYaw.v[408] -= workYaw.L[214]*workYaw.v[410]+workYaw.L[959]*workYaw.v[599];
  workYaw.v[407] -= workYaw.L[933]*workYaw.v[593]+workYaw.L[958]*workYaw.v[599];
  workYaw.v[406] -= workYaw.L[913]*workYaw.v[589]+workYaw.L[932]*workYaw.v[593];
  workYaw.v[405] -= workYaw.L[893]*workYaw.v[585]+workYaw.L[912]*workYaw.v[589];
  workYaw.v[404] -= workYaw.L[873]*workYaw.v[581]+workYaw.L[892]*workYaw.v[585];
  workYaw.v[403] -= workYaw.L[853]*workYaw.v[577]+workYaw.L[872]*workYaw.v[581];
  workYaw.v[402] -= workYaw.L[833]*workYaw.v[573]+workYaw.L[852]*workYaw.v[577];
  workYaw.v[401] -= workYaw.L[813]*workYaw.v[569]+workYaw.L[832]*workYaw.v[573];
  workYaw.v[400] -= workYaw.L[793]*workYaw.v[565]+workYaw.L[812]*workYaw.v[569];
  workYaw.v[399] -= workYaw.L[773]*workYaw.v[561]+workYaw.L[792]*workYaw.v[565];
  workYaw.v[398] -= workYaw.L[753]*workYaw.v[557]+workYaw.L[772]*workYaw.v[561];
  workYaw.v[397] -= workYaw.L[733]*workYaw.v[553]+workYaw.L[752]*workYaw.v[557];
  workYaw.v[396] -= workYaw.L[713]*workYaw.v[549]+workYaw.L[732]*workYaw.v[553];
  workYaw.v[395] -= workYaw.L[693]*workYaw.v[545]+workYaw.L[712]*workYaw.v[549];
  workYaw.v[394] -= workYaw.L[673]*workYaw.v[541]+workYaw.L[692]*workYaw.v[545];
  workYaw.v[393] -= workYaw.L[653]*workYaw.v[537]+workYaw.L[672]*workYaw.v[541];
  workYaw.v[392] -= workYaw.L[633]*workYaw.v[533]+workYaw.L[652]*workYaw.v[537];
  workYaw.v[391] -= workYaw.L[613]*workYaw.v[529]+workYaw.L[632]*workYaw.v[533];
  workYaw.v[390] -= workYaw.L[593]*workYaw.v[525]+workYaw.L[612]*workYaw.v[529];
  workYaw.v[389] -= workYaw.L[573]*workYaw.v[521]+workYaw.L[592]*workYaw.v[525];
  workYaw.v[388] -= workYaw.L[553]*workYaw.v[517]+workYaw.L[572]*workYaw.v[521];
  workYaw.v[387] -= workYaw.L[533]*workYaw.v[513]+workYaw.L[552]*workYaw.v[517];
  workYaw.v[386] -= workYaw.L[513]*workYaw.v[509]+workYaw.L[532]*workYaw.v[513];
  workYaw.v[385] -= workYaw.L[493]*workYaw.v[505]+workYaw.L[512]*workYaw.v[509];
  workYaw.v[384] -= workYaw.L[473]*workYaw.v[501]+workYaw.L[492]*workYaw.v[505];
  workYaw.v[383] -= workYaw.L[453]*workYaw.v[497]+workYaw.L[472]*workYaw.v[501];
  workYaw.v[382] -= workYaw.L[433]*workYaw.v[493]+workYaw.L[452]*workYaw.v[497];
  workYaw.v[381] -= workYaw.L[413]*workYaw.v[489]+workYaw.L[432]*workYaw.v[493];
  workYaw.v[380] -= workYaw.L[393]*workYaw.v[485]+workYaw.L[412]*workYaw.v[489];
  workYaw.v[379] -= workYaw.L[373]*workYaw.v[481]+workYaw.L[392]*workYaw.v[485];
  workYaw.v[378] -= workYaw.L[353]*workYaw.v[477]+workYaw.L[372]*workYaw.v[481];
  workYaw.v[377] -= workYaw.L[333]*workYaw.v[473]+workYaw.L[352]*workYaw.v[477];
  workYaw.v[376] -= workYaw.L[313]*workYaw.v[469]+workYaw.L[332]*workYaw.v[473];
  workYaw.v[375] -= workYaw.L[293]*workYaw.v[465]+workYaw.L[312]*workYaw.v[469];
  workYaw.v[374] -= workYaw.L[273]*workYaw.v[461]+workYaw.L[292]*workYaw.v[465];
  workYaw.v[373] -= workYaw.L[253]*workYaw.v[457]+workYaw.L[272]*workYaw.v[461];
  workYaw.v[372] -= workYaw.L[235]*workYaw.v[453]+workYaw.L[252]*workYaw.v[457];
  workYaw.v[371] -= workYaw.L[222]*workYaw.v[412]+workYaw.L[234]*workYaw.v[453];
  workYaw.v[370] -= workYaw.L[218]*workYaw.v[411]+workYaw.L[223]*workYaw.v[413];
  workYaw.v[369] -= workYaw.L[210]*workYaw.v[408]+workYaw.L[213]*workYaw.v[410];
  workYaw.v[368] -= workYaw.L[212]*workYaw.v[410];
  workYaw.v[367] -= workYaw.L[211]*workYaw.v[409];
  workYaw.v[366] -= workYaw.L[171]*workYaw.v[370];
  workYaw.v[365] -= workYaw.L[170]*workYaw.v[369];
  workYaw.v[364] -= workYaw.L[164]*workYaw.v[365];
  workYaw.v[363] -= workYaw.L[163]*workYaw.v[365];
  workYaw.v[362] -= workYaw.L[209]*workYaw.v[408];
  workYaw.v[361] -= workYaw.L[208]*workYaw.v[407];
  workYaw.v[360] -= workYaw.L[207]*workYaw.v[406];
  workYaw.v[359] -= workYaw.L[206]*workYaw.v[405];
  workYaw.v[358] -= workYaw.L[205]*workYaw.v[404];
  workYaw.v[357] -= workYaw.L[204]*workYaw.v[403];
  workYaw.v[356] -= workYaw.L[203]*workYaw.v[402];
  workYaw.v[355] -= workYaw.L[202]*workYaw.v[401];
  workYaw.v[354] -= workYaw.L[201]*workYaw.v[400];
  workYaw.v[353] -= workYaw.L[200]*workYaw.v[399];
  workYaw.v[352] -= workYaw.L[199]*workYaw.v[398];
  workYaw.v[351] -= workYaw.L[198]*workYaw.v[397];
  workYaw.v[350] -= workYaw.L[197]*workYaw.v[396];
  workYaw.v[349] -= workYaw.L[196]*workYaw.v[395];
  workYaw.v[348] -= workYaw.L[195]*workYaw.v[394];
  workYaw.v[347] -= workYaw.L[194]*workYaw.v[393];
  workYaw.v[346] -= workYaw.L[193]*workYaw.v[392];
  workYaw.v[345] -= workYaw.L[192]*workYaw.v[391];
  workYaw.v[344] -= workYaw.L[191]*workYaw.v[390];
  workYaw.v[343] -= workYaw.L[190]*workYaw.v[389];
  workYaw.v[342] -= workYaw.L[189]*workYaw.v[388];
  workYaw.v[341] -= workYaw.L[188]*workYaw.v[387];
  workYaw.v[340] -= workYaw.L[187]*workYaw.v[386];
  workYaw.v[339] -= workYaw.L[186]*workYaw.v[385];
  workYaw.v[338] -= workYaw.L[185]*workYaw.v[384];
  workYaw.v[337] -= workYaw.L[184]*workYaw.v[383];
  workYaw.v[336] -= workYaw.L[183]*workYaw.v[382];
  workYaw.v[335] -= workYaw.L[182]*workYaw.v[381];
  workYaw.v[334] -= workYaw.L[181]*workYaw.v[380];
  workYaw.v[333] -= workYaw.L[180]*workYaw.v[379];
  workYaw.v[332] -= workYaw.L[179]*workYaw.v[378];
  workYaw.v[331] -= workYaw.L[178]*workYaw.v[377];
  workYaw.v[330] -= workYaw.L[177]*workYaw.v[376];
  workYaw.v[329] -= workYaw.L[176]*workYaw.v[375];
  workYaw.v[328] -= workYaw.L[175]*workYaw.v[374];
  workYaw.v[327] -= workYaw.L[174]*workYaw.v[373];
  workYaw.v[326] -= workYaw.L[173]*workYaw.v[372];
  workYaw.v[325] -= workYaw.L[172]*workYaw.v[371];
  workYaw.v[324] -= workYaw.L[221]*workYaw.v[412];
  workYaw.v[323] -= workYaw.L[160]*workYaw.v[324];
  workYaw.v[322] -= workYaw.L[217]*workYaw.v[411];
  workYaw.v[321] -= workYaw.L[165]*workYaw.v[366];
  workYaw.v[320] -= workYaw.L[162]*workYaw.v[364];
  workYaw.v[319] -= workYaw.L[169]*workYaw.v[369];
  workYaw.v[318] -= workYaw.L[957]*workYaw.v[599];
  workYaw.v[317] -= workYaw.L[931]*workYaw.v[593];
  workYaw.v[316] -= workYaw.L[911]*workYaw.v[589];
  workYaw.v[315] -= workYaw.L[891]*workYaw.v[585];
  workYaw.v[314] -= workYaw.L[871]*workYaw.v[581];
  workYaw.v[313] -= workYaw.L[851]*workYaw.v[577];
  workYaw.v[312] -= workYaw.L[831]*workYaw.v[573];
  workYaw.v[311] -= workYaw.L[811]*workYaw.v[569];
  workYaw.v[310] -= workYaw.L[791]*workYaw.v[565];
  workYaw.v[309] -= workYaw.L[771]*workYaw.v[561];
  workYaw.v[308] -= workYaw.L[751]*workYaw.v[557];
  workYaw.v[307] -= workYaw.L[731]*workYaw.v[553];
  workYaw.v[306] -= workYaw.L[711]*workYaw.v[549];
  workYaw.v[305] -= workYaw.L[691]*workYaw.v[545];
  workYaw.v[304] -= workYaw.L[671]*workYaw.v[541];
  workYaw.v[303] -= workYaw.L[651]*workYaw.v[537];
  workYaw.v[302] -= workYaw.L[631]*workYaw.v[533];
  workYaw.v[301] -= workYaw.L[611]*workYaw.v[529];
  workYaw.v[300] -= workYaw.L[591]*workYaw.v[525];
  workYaw.v[299] -= workYaw.L[571]*workYaw.v[521];
  workYaw.v[298] -= workYaw.L[551]*workYaw.v[517];
  workYaw.v[297] -= workYaw.L[531]*workYaw.v[513];
  workYaw.v[296] -= workYaw.L[511]*workYaw.v[509];
  workYaw.v[295] -= workYaw.L[491]*workYaw.v[505];
  workYaw.v[294] -= workYaw.L[471]*workYaw.v[501];
  workYaw.v[293] -= workYaw.L[451]*workYaw.v[497];
  workYaw.v[292] -= workYaw.L[431]*workYaw.v[493];
  workYaw.v[291] -= workYaw.L[411]*workYaw.v[489];
  workYaw.v[290] -= workYaw.L[391]*workYaw.v[485];
  workYaw.v[289] -= workYaw.L[371]*workYaw.v[481];
  workYaw.v[288] -= workYaw.L[351]*workYaw.v[477];
  workYaw.v[287] -= workYaw.L[331]*workYaw.v[473];
  workYaw.v[286] -= workYaw.L[311]*workYaw.v[469];
  workYaw.v[285] -= workYaw.L[291]*workYaw.v[465];
  workYaw.v[284] -= workYaw.L[271]*workYaw.v[461];
  workYaw.v[283] -= workYaw.L[251]*workYaw.v[457];
  workYaw.v[282] -= workYaw.L[233]*workYaw.v[453];
  workYaw.v[281] -= workYaw.L[220]*workYaw.v[412];
  workYaw.v[280] -= workYaw.L[161]*workYaw.v[364];
  workYaw.v[279] -= workYaw.L[168]*workYaw.v[369];
  workYaw.v[278] -= workYaw.L[956]*workYaw.v[599];
  workYaw.v[277] -= workYaw.L[930]*workYaw.v[593];
  workYaw.v[276] -= workYaw.L[910]*workYaw.v[589];
  workYaw.v[275] -= workYaw.L[890]*workYaw.v[585];
  workYaw.v[274] -= workYaw.L[870]*workYaw.v[581];
  workYaw.v[273] -= workYaw.L[850]*workYaw.v[577];
  workYaw.v[272] -= workYaw.L[830]*workYaw.v[573];
  workYaw.v[271] -= workYaw.L[810]*workYaw.v[569];
  workYaw.v[270] -= workYaw.L[790]*workYaw.v[565];
  workYaw.v[269] -= workYaw.L[770]*workYaw.v[561];
  workYaw.v[268] -= workYaw.L[750]*workYaw.v[557];
  workYaw.v[267] -= workYaw.L[730]*workYaw.v[553];
  workYaw.v[266] -= workYaw.L[710]*workYaw.v[549];
  workYaw.v[265] -= workYaw.L[690]*workYaw.v[545];
  workYaw.v[264] -= workYaw.L[670]*workYaw.v[541];
  workYaw.v[263] -= workYaw.L[650]*workYaw.v[537];
  workYaw.v[262] -= workYaw.L[630]*workYaw.v[533];
  workYaw.v[261] -= workYaw.L[610]*workYaw.v[529];
  workYaw.v[260] -= workYaw.L[590]*workYaw.v[525];
  workYaw.v[259] -= workYaw.L[570]*workYaw.v[521];
  workYaw.v[258] -= workYaw.L[550]*workYaw.v[517];
  workYaw.v[257] -= workYaw.L[530]*workYaw.v[513];
  workYaw.v[256] -= workYaw.L[510]*workYaw.v[509];
  workYaw.v[255] -= workYaw.L[490]*workYaw.v[505];
  workYaw.v[254] -= workYaw.L[470]*workYaw.v[501];
  workYaw.v[253] -= workYaw.L[450]*workYaw.v[497];
  workYaw.v[252] -= workYaw.L[430]*workYaw.v[493];
  workYaw.v[251] -= workYaw.L[410]*workYaw.v[489];
  workYaw.v[250] -= workYaw.L[390]*workYaw.v[485];
  workYaw.v[249] -= workYaw.L[370]*workYaw.v[481];
  workYaw.v[248] -= workYaw.L[350]*workYaw.v[477];
  workYaw.v[247] -= workYaw.L[330]*workYaw.v[473];
  workYaw.v[246] -= workYaw.L[310]*workYaw.v[469];
  workYaw.v[245] -= workYaw.L[290]*workYaw.v[465];
  workYaw.v[244] -= workYaw.L[270]*workYaw.v[461];
  workYaw.v[243] -= workYaw.L[250]*workYaw.v[457];
  workYaw.v[242] -= workYaw.L[232]*workYaw.v[453];
  workYaw.v[241] -= workYaw.L[219]*workYaw.v[412];
  workYaw.v[240] -= workYaw.L[167]*workYaw.v[368];
  workYaw.v[239] -= workYaw.L[968]*workYaw.v[600];
  workYaw.v[238] -= workYaw.L[952]*workYaw.v[598];
  workYaw.v[237] -= workYaw.L[928]*workYaw.v[592];
  workYaw.v[236] -= workYaw.L[908]*workYaw.v[588];
  workYaw.v[235] -= workYaw.L[888]*workYaw.v[584];
  workYaw.v[234] -= workYaw.L[868]*workYaw.v[580];
  workYaw.v[233] -= workYaw.L[848]*workYaw.v[576];
  workYaw.v[232] -= workYaw.L[828]*workYaw.v[572];
  workYaw.v[231] -= workYaw.L[808]*workYaw.v[568];
  workYaw.v[230] -= workYaw.L[788]*workYaw.v[564];
  workYaw.v[229] -= workYaw.L[768]*workYaw.v[560];
  workYaw.v[228] -= workYaw.L[748]*workYaw.v[556];
  workYaw.v[227] -= workYaw.L[728]*workYaw.v[552];
  workYaw.v[226] -= workYaw.L[708]*workYaw.v[548];
  workYaw.v[225] -= workYaw.L[688]*workYaw.v[544];
  workYaw.v[224] -= workYaw.L[668]*workYaw.v[540];
  workYaw.v[223] -= workYaw.L[648]*workYaw.v[536];
  workYaw.v[222] -= workYaw.L[628]*workYaw.v[532];
  workYaw.v[221] -= workYaw.L[608]*workYaw.v[528];
  workYaw.v[220] -= workYaw.L[588]*workYaw.v[524];
  workYaw.v[219] -= workYaw.L[568]*workYaw.v[520];
  workYaw.v[218] -= workYaw.L[548]*workYaw.v[516];
  workYaw.v[217] -= workYaw.L[528]*workYaw.v[512];
  workYaw.v[216] -= workYaw.L[508]*workYaw.v[508];
  workYaw.v[215] -= workYaw.L[488]*workYaw.v[504];
  workYaw.v[214] -= workYaw.L[468]*workYaw.v[500];
  workYaw.v[213] -= workYaw.L[448]*workYaw.v[496];
  workYaw.v[212] -= workYaw.L[428]*workYaw.v[492];
  workYaw.v[211] -= workYaw.L[408]*workYaw.v[488];
  workYaw.v[210] -= workYaw.L[388]*workYaw.v[484];
  workYaw.v[209] -= workYaw.L[368]*workYaw.v[480];
  workYaw.v[208] -= workYaw.L[348]*workYaw.v[476];
  workYaw.v[207] -= workYaw.L[328]*workYaw.v[472];
  workYaw.v[206] -= workYaw.L[308]*workYaw.v[468];
  workYaw.v[205] -= workYaw.L[288]*workYaw.v[464];
  workYaw.v[204] -= workYaw.L[268]*workYaw.v[460];
  workYaw.v[203] -= workYaw.L[248]*workYaw.v[456];
  workYaw.v[202] -= workYaw.L[230]*workYaw.v[452];
  workYaw.v[201] -= workYaw.L[216]*workYaw.v[411];
  workYaw.v[200] -= workYaw.L[166]*workYaw.v[368];
  workYaw.v[199] -= workYaw.L[967]*workYaw.v[600];
  workYaw.v[198] -= workYaw.L[951]*workYaw.v[598];
  workYaw.v[197] -= workYaw.L[927]*workYaw.v[592];
  workYaw.v[196] -= workYaw.L[907]*workYaw.v[588];
  workYaw.v[195] -= workYaw.L[887]*workYaw.v[584];
  workYaw.v[194] -= workYaw.L[867]*workYaw.v[580];
  workYaw.v[193] -= workYaw.L[847]*workYaw.v[576];
  workYaw.v[192] -= workYaw.L[827]*workYaw.v[572];
  workYaw.v[191] -= workYaw.L[807]*workYaw.v[568];
  workYaw.v[190] -= workYaw.L[787]*workYaw.v[564];
  workYaw.v[189] -= workYaw.L[767]*workYaw.v[560];
  workYaw.v[188] -= workYaw.L[747]*workYaw.v[556];
  workYaw.v[187] -= workYaw.L[727]*workYaw.v[552];
  workYaw.v[186] -= workYaw.L[707]*workYaw.v[548];
  workYaw.v[185] -= workYaw.L[687]*workYaw.v[544];
  workYaw.v[184] -= workYaw.L[667]*workYaw.v[540];
  workYaw.v[183] -= workYaw.L[647]*workYaw.v[536];
  workYaw.v[182] -= workYaw.L[627]*workYaw.v[532];
  workYaw.v[181] -= workYaw.L[607]*workYaw.v[528];
  workYaw.v[180] -= workYaw.L[587]*workYaw.v[524];
  workYaw.v[179] -= workYaw.L[567]*workYaw.v[520];
  workYaw.v[178] -= workYaw.L[547]*workYaw.v[516];
  workYaw.v[177] -= workYaw.L[527]*workYaw.v[512];
  workYaw.v[176] -= workYaw.L[507]*workYaw.v[508];
  workYaw.v[175] -= workYaw.L[487]*workYaw.v[504];
  workYaw.v[174] -= workYaw.L[467]*workYaw.v[500];
  workYaw.v[173] -= workYaw.L[447]*workYaw.v[496];
  workYaw.v[172] -= workYaw.L[427]*workYaw.v[492];
  workYaw.v[171] -= workYaw.L[407]*workYaw.v[488];
  workYaw.v[170] -= workYaw.L[387]*workYaw.v[484];
  workYaw.v[169] -= workYaw.L[367]*workYaw.v[480];
  workYaw.v[168] -= workYaw.L[347]*workYaw.v[476];
  workYaw.v[167] -= workYaw.L[327]*workYaw.v[472];
  workYaw.v[166] -= workYaw.L[307]*workYaw.v[468];
  workYaw.v[165] -= workYaw.L[287]*workYaw.v[464];
  workYaw.v[164] -= workYaw.L[267]*workYaw.v[460];
  workYaw.v[163] -= workYaw.L[247]*workYaw.v[456];
  workYaw.v[162] -= workYaw.L[229]*workYaw.v[452];
  workYaw.v[161] -= workYaw.L[215]*workYaw.v[411];
  workYaw.v[160] -= workYaw.L[159]*workYaw.v[320];
  workYaw.v[159] -= workYaw.L[158]*workYaw.v[319];
  workYaw.v[158] -= workYaw.L[157]*workYaw.v[318];
  workYaw.v[157] -= workYaw.L[156]*workYaw.v[317];
  workYaw.v[156] -= workYaw.L[155]*workYaw.v[316];
  workYaw.v[155] -= workYaw.L[154]*workYaw.v[315];
  workYaw.v[154] -= workYaw.L[153]*workYaw.v[314];
  workYaw.v[153] -= workYaw.L[152]*workYaw.v[313];
  workYaw.v[152] -= workYaw.L[151]*workYaw.v[312];
  workYaw.v[151] -= workYaw.L[150]*workYaw.v[311];
  workYaw.v[150] -= workYaw.L[149]*workYaw.v[310];
  workYaw.v[149] -= workYaw.L[148]*workYaw.v[309];
  workYaw.v[148] -= workYaw.L[147]*workYaw.v[308];
  workYaw.v[147] -= workYaw.L[146]*workYaw.v[307];
  workYaw.v[146] -= workYaw.L[145]*workYaw.v[306];
  workYaw.v[145] -= workYaw.L[144]*workYaw.v[305];
  workYaw.v[144] -= workYaw.L[143]*workYaw.v[304];
  workYaw.v[143] -= workYaw.L[142]*workYaw.v[303];
  workYaw.v[142] -= workYaw.L[141]*workYaw.v[302];
  workYaw.v[141] -= workYaw.L[140]*workYaw.v[301];
  workYaw.v[140] -= workYaw.L[139]*workYaw.v[300];
  workYaw.v[139] -= workYaw.L[138]*workYaw.v[299];
  workYaw.v[138] -= workYaw.L[137]*workYaw.v[298];
  workYaw.v[137] -= workYaw.L[136]*workYaw.v[297];
  workYaw.v[136] -= workYaw.L[135]*workYaw.v[296];
  workYaw.v[135] -= workYaw.L[134]*workYaw.v[295];
  workYaw.v[134] -= workYaw.L[133]*workYaw.v[294];
  workYaw.v[133] -= workYaw.L[132]*workYaw.v[293];
  workYaw.v[132] -= workYaw.L[131]*workYaw.v[292];
  workYaw.v[131] -= workYaw.L[130]*workYaw.v[291];
  workYaw.v[130] -= workYaw.L[129]*workYaw.v[290];
  workYaw.v[129] -= workYaw.L[128]*workYaw.v[289];
  workYaw.v[128] -= workYaw.L[127]*workYaw.v[288];
  workYaw.v[127] -= workYaw.L[126]*workYaw.v[287];
  workYaw.v[126] -= workYaw.L[125]*workYaw.v[286];
  workYaw.v[125] -= workYaw.L[124]*workYaw.v[285];
  workYaw.v[124] -= workYaw.L[123]*workYaw.v[284];
  workYaw.v[123] -= workYaw.L[122]*workYaw.v[283];
  workYaw.v[122] -= workYaw.L[121]*workYaw.v[282];
  workYaw.v[121] -= workYaw.L[120]*workYaw.v[281];
  workYaw.v[120] -= workYaw.L[119]*workYaw.v[280];
  workYaw.v[119] -= workYaw.L[118]*workYaw.v[279];
  workYaw.v[118] -= workYaw.L[117]*workYaw.v[278];
  workYaw.v[117] -= workYaw.L[116]*workYaw.v[277];
  workYaw.v[116] -= workYaw.L[115]*workYaw.v[276];
  workYaw.v[115] -= workYaw.L[114]*workYaw.v[275];
  workYaw.v[114] -= workYaw.L[113]*workYaw.v[274];
  workYaw.v[113] -= workYaw.L[112]*workYaw.v[273];
  workYaw.v[112] -= workYaw.L[111]*workYaw.v[272];
  workYaw.v[111] -= workYaw.L[110]*workYaw.v[271];
  workYaw.v[110] -= workYaw.L[109]*workYaw.v[270];
  workYaw.v[109] -= workYaw.L[108]*workYaw.v[269];
  workYaw.v[108] -= workYaw.L[107]*workYaw.v[268];
  workYaw.v[107] -= workYaw.L[106]*workYaw.v[267];
  workYaw.v[106] -= workYaw.L[105]*workYaw.v[266];
  workYaw.v[105] -= workYaw.L[104]*workYaw.v[265];
  workYaw.v[104] -= workYaw.L[103]*workYaw.v[264];
  workYaw.v[103] -= workYaw.L[102]*workYaw.v[263];
  workYaw.v[102] -= workYaw.L[101]*workYaw.v[262];
  workYaw.v[101] -= workYaw.L[100]*workYaw.v[261];
  workYaw.v[100] -= workYaw.L[99]*workYaw.v[260];
  workYaw.v[99] -= workYaw.L[98]*workYaw.v[259];
  workYaw.v[98] -= workYaw.L[97]*workYaw.v[258];
  workYaw.v[97] -= workYaw.L[96]*workYaw.v[257];
  workYaw.v[96] -= workYaw.L[95]*workYaw.v[256];
  workYaw.v[95] -= workYaw.L[94]*workYaw.v[255];
  workYaw.v[94] -= workYaw.L[93]*workYaw.v[254];
  workYaw.v[93] -= workYaw.L[92]*workYaw.v[253];
  workYaw.v[92] -= workYaw.L[91]*workYaw.v[252];
  workYaw.v[91] -= workYaw.L[90]*workYaw.v[251];
  workYaw.v[90] -= workYaw.L[89]*workYaw.v[250];
  workYaw.v[89] -= workYaw.L[88]*workYaw.v[249];
  workYaw.v[88] -= workYaw.L[87]*workYaw.v[248];
  workYaw.v[87] -= workYaw.L[86]*workYaw.v[247];
  workYaw.v[86] -= workYaw.L[85]*workYaw.v[246];
  workYaw.v[85] -= workYaw.L[84]*workYaw.v[245];
  workYaw.v[84] -= workYaw.L[83]*workYaw.v[244];
  workYaw.v[83] -= workYaw.L[82]*workYaw.v[243];
  workYaw.v[82] -= workYaw.L[81]*workYaw.v[242];
  workYaw.v[81] -= workYaw.L[80]*workYaw.v[241];
  workYaw.v[80] -= workYaw.L[79]*workYaw.v[240];
  workYaw.v[79] -= workYaw.L[78]*workYaw.v[239];
  workYaw.v[78] -= workYaw.L[77]*workYaw.v[238];
  workYaw.v[77] -= workYaw.L[76]*workYaw.v[237];
  workYaw.v[76] -= workYaw.L[75]*workYaw.v[236];
  workYaw.v[75] -= workYaw.L[74]*workYaw.v[235];
  workYaw.v[74] -= workYaw.L[73]*workYaw.v[234];
  workYaw.v[73] -= workYaw.L[72]*workYaw.v[233];
  workYaw.v[72] -= workYaw.L[71]*workYaw.v[232];
  workYaw.v[71] -= workYaw.L[70]*workYaw.v[231];
  workYaw.v[70] -= workYaw.L[69]*workYaw.v[230];
  workYaw.v[69] -= workYaw.L[68]*workYaw.v[229];
  workYaw.v[68] -= workYaw.L[67]*workYaw.v[228];
  workYaw.v[67] -= workYaw.L[66]*workYaw.v[227];
  workYaw.v[66] -= workYaw.L[65]*workYaw.v[226];
  workYaw.v[65] -= workYaw.L[64]*workYaw.v[225];
  workYaw.v[64] -= workYaw.L[63]*workYaw.v[224];
  workYaw.v[63] -= workYaw.L[62]*workYaw.v[223];
  workYaw.v[62] -= workYaw.L[61]*workYaw.v[222];
  workYaw.v[61] -= workYaw.L[60]*workYaw.v[221];
  workYaw.v[60] -= workYaw.L[59]*workYaw.v[220];
  workYaw.v[59] -= workYaw.L[58]*workYaw.v[219];
  workYaw.v[58] -= workYaw.L[57]*workYaw.v[218];
  workYaw.v[57] -= workYaw.L[56]*workYaw.v[217];
  workYaw.v[56] -= workYaw.L[55]*workYaw.v[216];
  workYaw.v[55] -= workYaw.L[54]*workYaw.v[215];
  workYaw.v[54] -= workYaw.L[53]*workYaw.v[214];
  workYaw.v[53] -= workYaw.L[52]*workYaw.v[213];
  workYaw.v[52] -= workYaw.L[51]*workYaw.v[212];
  workYaw.v[51] -= workYaw.L[50]*workYaw.v[211];
  workYaw.v[50] -= workYaw.L[49]*workYaw.v[210];
  workYaw.v[49] -= workYaw.L[48]*workYaw.v[209];
  workYaw.v[48] -= workYaw.L[47]*workYaw.v[208];
  workYaw.v[47] -= workYaw.L[46]*workYaw.v[207];
  workYaw.v[46] -= workYaw.L[45]*workYaw.v[206];
  workYaw.v[45] -= workYaw.L[44]*workYaw.v[205];
  workYaw.v[44] -= workYaw.L[43]*workYaw.v[204];
  workYaw.v[43] -= workYaw.L[42]*workYaw.v[203];
  workYaw.v[42] -= workYaw.L[41]*workYaw.v[202];
  workYaw.v[41] -= workYaw.L[40]*workYaw.v[201];
  workYaw.v[40] -= workYaw.L[39]*workYaw.v[200];
  workYaw.v[39] -= workYaw.L[38]*workYaw.v[199];
  workYaw.v[38] -= workYaw.L[37]*workYaw.v[198];
  workYaw.v[37] -= workYaw.L[36]*workYaw.v[197];
  workYaw.v[36] -= workYaw.L[35]*workYaw.v[196];
  workYaw.v[35] -= workYaw.L[34]*workYaw.v[195];
  workYaw.v[34] -= workYaw.L[33]*workYaw.v[194];
  workYaw.v[33] -= workYaw.L[32]*workYaw.v[193];
  workYaw.v[32] -= workYaw.L[31]*workYaw.v[192];
  workYaw.v[31] -= workYaw.L[30]*workYaw.v[191];
  workYaw.v[30] -= workYaw.L[29]*workYaw.v[190];
  workYaw.v[29] -= workYaw.L[28]*workYaw.v[189];
  workYaw.v[28] -= workYaw.L[27]*workYaw.v[188];
  workYaw.v[27] -= workYaw.L[26]*workYaw.v[187];
  workYaw.v[26] -= workYaw.L[25]*workYaw.v[186];
  workYaw.v[25] -= workYaw.L[24]*workYaw.v[185];
  workYaw.v[24] -= workYaw.L[23]*workYaw.v[184];
  workYaw.v[23] -= workYaw.L[22]*workYaw.v[183];
  workYaw.v[22] -= workYaw.L[21]*workYaw.v[182];
  workYaw.v[21] -= workYaw.L[20]*workYaw.v[181];
  workYaw.v[20] -= workYaw.L[19]*workYaw.v[180];
  workYaw.v[19] -= workYaw.L[18]*workYaw.v[179];
  workYaw.v[18] -= workYaw.L[17]*workYaw.v[178];
  workYaw.v[17] -= workYaw.L[16]*workYaw.v[177];
  workYaw.v[16] -= workYaw.L[15]*workYaw.v[176];
  workYaw.v[15] -= workYaw.L[14]*workYaw.v[175];
  workYaw.v[14] -= workYaw.L[13]*workYaw.v[174];
  workYaw.v[13] -= workYaw.L[12]*workYaw.v[173];
  workYaw.v[12] -= workYaw.L[11]*workYaw.v[172];
  workYaw.v[11] -= workYaw.L[10]*workYaw.v[171];
  workYaw.v[10] -= workYaw.L[9]*workYaw.v[170];
  workYaw.v[9] -= workYaw.L[8]*workYaw.v[169];
  workYaw.v[8] -= workYaw.L[7]*workYaw.v[168];
  workYaw.v[7] -= workYaw.L[6]*workYaw.v[167];
  workYaw.v[6] -= workYaw.L[5]*workYaw.v[166];
  workYaw.v[5] -= workYaw.L[4]*workYaw.v[165];
  workYaw.v[4] -= workYaw.L[3]*workYaw.v[164];
  workYaw.v[3] -= workYaw.L[2]*workYaw.v[163];
  workYaw.v[2] -= workYaw.L[1]*workYaw.v[162];
  workYaw.v[1] -= workYaw.L[0]*workYaw.v[161];
  /* Unpermute the result, from v to var. */
  var[0] = workYaw.v[323];
  var[1] = workYaw.v[325];
  var[2] = workYaw.v[326];
  var[3] = workYaw.v[327];
  var[4] = workYaw.v[328];
  var[5] = workYaw.v[329];
  var[6] = workYaw.v[330];
  var[7] = workYaw.v[331];
  var[8] = workYaw.v[332];
  var[9] = workYaw.v[333];
  var[10] = workYaw.v[334];
  var[11] = workYaw.v[335];
  var[12] = workYaw.v[336];
  var[13] = workYaw.v[337];
  var[14] = workYaw.v[338];
  var[15] = workYaw.v[339];
  var[16] = workYaw.v[340];
  var[17] = workYaw.v[341];
  var[18] = workYaw.v[342];
  var[19] = workYaw.v[343];
  var[20] = workYaw.v[344];
  var[21] = workYaw.v[345];
  var[22] = workYaw.v[346];
  var[23] = workYaw.v[347];
  var[24] = workYaw.v[348];
  var[25] = workYaw.v[349];
  var[26] = workYaw.v[350];
  var[27] = workYaw.v[351];
  var[28] = workYaw.v[352];
  var[29] = workYaw.v[353];
  var[30] = workYaw.v[354];
  var[31] = workYaw.v[355];
  var[32] = workYaw.v[356];
  var[33] = workYaw.v[357];
  var[34] = workYaw.v[358];
  var[35] = workYaw.v[359];
  var[36] = workYaw.v[360];
  var[37] = workYaw.v[361];
  var[38] = workYaw.v[362];
  var[39] = workYaw.v[363];
  var[40] = workYaw.v[0];
  var[41] = workYaw.v[366];
  var[42] = workYaw.v[411];
  var[43] = workYaw.v[412];
  var[44] = workYaw.v[413];
  var[45] = workYaw.v[452];
  var[46] = workYaw.v[453];
  var[47] = workYaw.v[414];
  var[48] = workYaw.v[456];
  var[49] = workYaw.v[457];
  var[50] = workYaw.v[415];
  var[51] = workYaw.v[460];
  var[52] = workYaw.v[461];
  var[53] = workYaw.v[416];
  var[54] = workYaw.v[464];
  var[55] = workYaw.v[465];
  var[56] = workYaw.v[417];
  var[57] = workYaw.v[468];
  var[58] = workYaw.v[469];
  var[59] = workYaw.v[418];
  var[60] = workYaw.v[472];
  var[61] = workYaw.v[473];
  var[62] = workYaw.v[419];
  var[63] = workYaw.v[476];
  var[64] = workYaw.v[477];
  var[65] = workYaw.v[420];
  var[66] = workYaw.v[480];
  var[67] = workYaw.v[481];
  var[68] = workYaw.v[421];
  var[69] = workYaw.v[484];
  var[70] = workYaw.v[485];
  var[71] = workYaw.v[422];
  var[72] = workYaw.v[488];
  var[73] = workYaw.v[489];
  var[74] = workYaw.v[423];
  var[75] = workYaw.v[492];
  var[76] = workYaw.v[493];
  var[77] = workYaw.v[424];
  var[78] = workYaw.v[496];
  var[79] = workYaw.v[497];
  var[80] = workYaw.v[425];
  var[81] = workYaw.v[500];
  var[82] = workYaw.v[501];
  var[83] = workYaw.v[426];
  var[84] = workYaw.v[504];
  var[85] = workYaw.v[505];
  var[86] = workYaw.v[427];
  var[87] = workYaw.v[508];
  var[88] = workYaw.v[509];
  var[89] = workYaw.v[428];
  var[90] = workYaw.v[512];
  var[91] = workYaw.v[513];
  var[92] = workYaw.v[429];
  var[93] = workYaw.v[516];
  var[94] = workYaw.v[517];
  var[95] = workYaw.v[430];
  var[96] = workYaw.v[520];
  var[97] = workYaw.v[521];
  var[98] = workYaw.v[431];
  var[99] = workYaw.v[524];
  var[100] = workYaw.v[525];
  var[101] = workYaw.v[432];
  var[102] = workYaw.v[528];
  var[103] = workYaw.v[529];
  var[104] = workYaw.v[433];
  var[105] = workYaw.v[532];
  var[106] = workYaw.v[533];
  var[107] = workYaw.v[434];
  var[108] = workYaw.v[536];
  var[109] = workYaw.v[537];
  var[110] = workYaw.v[435];
  var[111] = workYaw.v[540];
  var[112] = workYaw.v[541];
  var[113] = workYaw.v[436];
  var[114] = workYaw.v[544];
  var[115] = workYaw.v[545];
  var[116] = workYaw.v[437];
  var[117] = workYaw.v[548];
  var[118] = workYaw.v[549];
  var[119] = workYaw.v[438];
  var[120] = workYaw.v[552];
  var[121] = workYaw.v[553];
  var[122] = workYaw.v[439];
  var[123] = workYaw.v[556];
  var[124] = workYaw.v[557];
  var[125] = workYaw.v[440];
  var[126] = workYaw.v[560];
  var[127] = workYaw.v[561];
  var[128] = workYaw.v[441];
  var[129] = workYaw.v[564];
  var[130] = workYaw.v[565];
  var[131] = workYaw.v[442];
  var[132] = workYaw.v[568];
  var[133] = workYaw.v[569];
  var[134] = workYaw.v[443];
  var[135] = workYaw.v[572];
  var[136] = workYaw.v[573];
  var[137] = workYaw.v[444];
  var[138] = workYaw.v[576];
  var[139] = workYaw.v[577];
  var[140] = workYaw.v[445];
  var[141] = workYaw.v[580];
  var[142] = workYaw.v[581];
  var[143] = workYaw.v[446];
  var[144] = workYaw.v[584];
  var[145] = workYaw.v[585];
  var[146] = workYaw.v[447];
  var[147] = workYaw.v[588];
  var[148] = workYaw.v[589];
  var[149] = workYaw.v[448];
  var[150] = workYaw.v[592];
  var[151] = workYaw.v[593];
  var[152] = workYaw.v[449];
  var[153] = workYaw.v[598];
  var[154] = workYaw.v[599];
  var[155] = workYaw.v[450];
  var[156] = workYaw.v[600];
  var[157] = workYaw.v[369];
  var[158] = workYaw.v[367];
  var[159] = workYaw.v[368];
  var[160] = workYaw.v[364];
  var[161] = workYaw.v[1];
  var[162] = workYaw.v[2];
  var[163] = workYaw.v[3];
  var[164] = workYaw.v[4];
  var[165] = workYaw.v[5];
  var[166] = workYaw.v[6];
  var[167] = workYaw.v[7];
  var[168] = workYaw.v[8];
  var[169] = workYaw.v[9];
  var[170] = workYaw.v[10];
  var[171] = workYaw.v[11];
  var[172] = workYaw.v[12];
  var[173] = workYaw.v[13];
  var[174] = workYaw.v[14];
  var[175] = workYaw.v[15];
  var[176] = workYaw.v[16];
  var[177] = workYaw.v[17];
  var[178] = workYaw.v[18];
  var[179] = workYaw.v[19];
  var[180] = workYaw.v[20];
  var[181] = workYaw.v[21];
  var[182] = workYaw.v[22];
  var[183] = workYaw.v[23];
  var[184] = workYaw.v[24];
  var[185] = workYaw.v[25];
  var[186] = workYaw.v[26];
  var[187] = workYaw.v[27];
  var[188] = workYaw.v[28];
  var[189] = workYaw.v[29];
  var[190] = workYaw.v[30];
  var[191] = workYaw.v[31];
  var[192] = workYaw.v[32];
  var[193] = workYaw.v[33];
  var[194] = workYaw.v[34];
  var[195] = workYaw.v[35];
  var[196] = workYaw.v[36];
  var[197] = workYaw.v[37];
  var[198] = workYaw.v[38];
  var[199] = workYaw.v[39];
  var[200] = workYaw.v[40];
  var[201] = workYaw.v[41];
  var[202] = workYaw.v[42];
  var[203] = workYaw.v[43];
  var[204] = workYaw.v[44];
  var[205] = workYaw.v[45];
  var[206] = workYaw.v[46];
  var[207] = workYaw.v[47];
  var[208] = workYaw.v[48];
  var[209] = workYaw.v[49];
  var[210] = workYaw.v[50];
  var[211] = workYaw.v[51];
  var[212] = workYaw.v[52];
  var[213] = workYaw.v[53];
  var[214] = workYaw.v[54];
  var[215] = workYaw.v[55];
  var[216] = workYaw.v[56];
  var[217] = workYaw.v[57];
  var[218] = workYaw.v[58];
  var[219] = workYaw.v[59];
  var[220] = workYaw.v[60];
  var[221] = workYaw.v[61];
  var[222] = workYaw.v[62];
  var[223] = workYaw.v[63];
  var[224] = workYaw.v[64];
  var[225] = workYaw.v[65];
  var[226] = workYaw.v[66];
  var[227] = workYaw.v[67];
  var[228] = workYaw.v[68];
  var[229] = workYaw.v[69];
  var[230] = workYaw.v[70];
  var[231] = workYaw.v[71];
  var[232] = workYaw.v[72];
  var[233] = workYaw.v[73];
  var[234] = workYaw.v[74];
  var[235] = workYaw.v[75];
  var[236] = workYaw.v[76];
  var[237] = workYaw.v[77];
  var[238] = workYaw.v[78];
  var[239] = workYaw.v[79];
  var[240] = workYaw.v[80];
  var[241] = workYaw.v[81];
  var[242] = workYaw.v[82];
  var[243] = workYaw.v[83];
  var[244] = workYaw.v[84];
  var[245] = workYaw.v[85];
  var[246] = workYaw.v[86];
  var[247] = workYaw.v[87];
  var[248] = workYaw.v[88];
  var[249] = workYaw.v[89];
  var[250] = workYaw.v[90];
  var[251] = workYaw.v[91];
  var[252] = workYaw.v[92];
  var[253] = workYaw.v[93];
  var[254] = workYaw.v[94];
  var[255] = workYaw.v[95];
  var[256] = workYaw.v[96];
  var[257] = workYaw.v[97];
  var[258] = workYaw.v[98];
  var[259] = workYaw.v[99];
  var[260] = workYaw.v[100];
  var[261] = workYaw.v[101];
  var[262] = workYaw.v[102];
  var[263] = workYaw.v[103];
  var[264] = workYaw.v[104];
  var[265] = workYaw.v[105];
  var[266] = workYaw.v[106];
  var[267] = workYaw.v[107];
  var[268] = workYaw.v[108];
  var[269] = workYaw.v[109];
  var[270] = workYaw.v[110];
  var[271] = workYaw.v[111];
  var[272] = workYaw.v[112];
  var[273] = workYaw.v[113];
  var[274] = workYaw.v[114];
  var[275] = workYaw.v[115];
  var[276] = workYaw.v[116];
  var[277] = workYaw.v[117];
  var[278] = workYaw.v[118];
  var[279] = workYaw.v[119];
  var[280] = workYaw.v[120];
  var[281] = workYaw.v[121];
  var[282] = workYaw.v[122];
  var[283] = workYaw.v[123];
  var[284] = workYaw.v[124];
  var[285] = workYaw.v[125];
  var[286] = workYaw.v[126];
  var[287] = workYaw.v[127];
  var[288] = workYaw.v[128];
  var[289] = workYaw.v[129];
  var[290] = workYaw.v[130];
  var[291] = workYaw.v[131];
  var[292] = workYaw.v[132];
  var[293] = workYaw.v[133];
  var[294] = workYaw.v[134];
  var[295] = workYaw.v[135];
  var[296] = workYaw.v[136];
  var[297] = workYaw.v[137];
  var[298] = workYaw.v[138];
  var[299] = workYaw.v[139];
  var[300] = workYaw.v[140];
  var[301] = workYaw.v[141];
  var[302] = workYaw.v[142];
  var[303] = workYaw.v[143];
  var[304] = workYaw.v[144];
  var[305] = workYaw.v[145];
  var[306] = workYaw.v[146];
  var[307] = workYaw.v[147];
  var[308] = workYaw.v[148];
  var[309] = workYaw.v[149];
  var[310] = workYaw.v[150];
  var[311] = workYaw.v[151];
  var[312] = workYaw.v[152];
  var[313] = workYaw.v[153];
  var[314] = workYaw.v[154];
  var[315] = workYaw.v[155];
  var[316] = workYaw.v[156];
  var[317] = workYaw.v[157];
  var[318] = workYaw.v[158];
  var[319] = workYaw.v[159];
  var[320] = workYaw.v[160];
  var[321] = workYaw.v[161];
  var[322] = workYaw.v[162];
  var[323] = workYaw.v[163];
  var[324] = workYaw.v[164];
  var[325] = workYaw.v[165];
  var[326] = workYaw.v[166];
  var[327] = workYaw.v[167];
  var[328] = workYaw.v[168];
  var[329] = workYaw.v[169];
  var[330] = workYaw.v[170];
  var[331] = workYaw.v[171];
  var[332] = workYaw.v[172];
  var[333] = workYaw.v[173];
  var[334] = workYaw.v[174];
  var[335] = workYaw.v[175];
  var[336] = workYaw.v[176];
  var[337] = workYaw.v[177];
  var[338] = workYaw.v[178];
  var[339] = workYaw.v[179];
  var[340] = workYaw.v[180];
  var[341] = workYaw.v[181];
  var[342] = workYaw.v[182];
  var[343] = workYaw.v[183];
  var[344] = workYaw.v[184];
  var[345] = workYaw.v[185];
  var[346] = workYaw.v[186];
  var[347] = workYaw.v[187];
  var[348] = workYaw.v[188];
  var[349] = workYaw.v[189];
  var[350] = workYaw.v[190];
  var[351] = workYaw.v[191];
  var[352] = workYaw.v[192];
  var[353] = workYaw.v[193];
  var[354] = workYaw.v[194];
  var[355] = workYaw.v[195];
  var[356] = workYaw.v[196];
  var[357] = workYaw.v[197];
  var[358] = workYaw.v[198];
  var[359] = workYaw.v[199];
  var[360] = workYaw.v[200];
  var[361] = workYaw.v[201];
  var[362] = workYaw.v[202];
  var[363] = workYaw.v[203];
  var[364] = workYaw.v[204];
  var[365] = workYaw.v[205];
  var[366] = workYaw.v[206];
  var[367] = workYaw.v[207];
  var[368] = workYaw.v[208];
  var[369] = workYaw.v[209];
  var[370] = workYaw.v[210];
  var[371] = workYaw.v[211];
  var[372] = workYaw.v[212];
  var[373] = workYaw.v[213];
  var[374] = workYaw.v[214];
  var[375] = workYaw.v[215];
  var[376] = workYaw.v[216];
  var[377] = workYaw.v[217];
  var[378] = workYaw.v[218];
  var[379] = workYaw.v[219];
  var[380] = workYaw.v[220];
  var[381] = workYaw.v[221];
  var[382] = workYaw.v[222];
  var[383] = workYaw.v[223];
  var[384] = workYaw.v[224];
  var[385] = workYaw.v[225];
  var[386] = workYaw.v[226];
  var[387] = workYaw.v[227];
  var[388] = workYaw.v[228];
  var[389] = workYaw.v[229];
  var[390] = workYaw.v[230];
  var[391] = workYaw.v[231];
  var[392] = workYaw.v[232];
  var[393] = workYaw.v[233];
  var[394] = workYaw.v[234];
  var[395] = workYaw.v[235];
  var[396] = workYaw.v[236];
  var[397] = workYaw.v[237];
  var[398] = workYaw.v[238];
  var[399] = workYaw.v[239];
  var[400] = workYaw.v[240];
  var[401] = workYaw.v[241];
  var[402] = workYaw.v[242];
  var[403] = workYaw.v[243];
  var[404] = workYaw.v[244];
  var[405] = workYaw.v[245];
  var[406] = workYaw.v[246];
  var[407] = workYaw.v[247];
  var[408] = workYaw.v[248];
  var[409] = workYaw.v[249];
  var[410] = workYaw.v[250];
  var[411] = workYaw.v[251];
  var[412] = workYaw.v[252];
  var[413] = workYaw.v[253];
  var[414] = workYaw.v[254];
  var[415] = workYaw.v[255];
  var[416] = workYaw.v[256];
  var[417] = workYaw.v[257];
  var[418] = workYaw.v[258];
  var[419] = workYaw.v[259];
  var[420] = workYaw.v[260];
  var[421] = workYaw.v[261];
  var[422] = workYaw.v[262];
  var[423] = workYaw.v[263];
  var[424] = workYaw.v[264];
  var[425] = workYaw.v[265];
  var[426] = workYaw.v[266];
  var[427] = workYaw.v[267];
  var[428] = workYaw.v[268];
  var[429] = workYaw.v[269];
  var[430] = workYaw.v[270];
  var[431] = workYaw.v[271];
  var[432] = workYaw.v[272];
  var[433] = workYaw.v[273];
  var[434] = workYaw.v[274];
  var[435] = workYaw.v[275];
  var[436] = workYaw.v[276];
  var[437] = workYaw.v[277];
  var[438] = workYaw.v[278];
  var[439] = workYaw.v[279];
  var[440] = workYaw.v[280];
  var[441] = workYaw.v[281];
  var[442] = workYaw.v[282];
  var[443] = workYaw.v[283];
  var[444] = workYaw.v[284];
  var[445] = workYaw.v[285];
  var[446] = workYaw.v[286];
  var[447] = workYaw.v[287];
  var[448] = workYaw.v[288];
  var[449] = workYaw.v[289];
  var[450] = workYaw.v[290];
  var[451] = workYaw.v[291];
  var[452] = workYaw.v[292];
  var[453] = workYaw.v[293];
  var[454] = workYaw.v[294];
  var[455] = workYaw.v[295];
  var[456] = workYaw.v[296];
  var[457] = workYaw.v[297];
  var[458] = workYaw.v[298];
  var[459] = workYaw.v[299];
  var[460] = workYaw.v[300];
  var[461] = workYaw.v[301];
  var[462] = workYaw.v[302];
  var[463] = workYaw.v[303];
  var[464] = workYaw.v[304];
  var[465] = workYaw.v[305];
  var[466] = workYaw.v[306];
  var[467] = workYaw.v[307];
  var[468] = workYaw.v[308];
  var[469] = workYaw.v[309];
  var[470] = workYaw.v[310];
  var[471] = workYaw.v[311];
  var[472] = workYaw.v[312];
  var[473] = workYaw.v[313];
  var[474] = workYaw.v[314];
  var[475] = workYaw.v[315];
  var[476] = workYaw.v[316];
  var[477] = workYaw.v[317];
  var[478] = workYaw.v[318];
  var[479] = workYaw.v[319];
  var[480] = workYaw.v[320];
  var[481] = workYaw.v[321];
  var[482] = workYaw.v[322];
  var[483] = workYaw.v[324];
  var[484] = workYaw.v[370];
  var[485] = workYaw.v[451];
  var[486] = workYaw.v[371];
  var[487] = workYaw.v[454];
  var[488] = workYaw.v[455];
  var[489] = workYaw.v[372];
  var[490] = workYaw.v[458];
  var[491] = workYaw.v[459];
  var[492] = workYaw.v[373];
  var[493] = workYaw.v[462];
  var[494] = workYaw.v[463];
  var[495] = workYaw.v[374];
  var[496] = workYaw.v[466];
  var[497] = workYaw.v[467];
  var[498] = workYaw.v[375];
  var[499] = workYaw.v[470];
  var[500] = workYaw.v[471];
  var[501] = workYaw.v[376];
  var[502] = workYaw.v[474];
  var[503] = workYaw.v[475];
  var[504] = workYaw.v[377];
  var[505] = workYaw.v[478];
  var[506] = workYaw.v[479];
  var[507] = workYaw.v[378];
  var[508] = workYaw.v[482];
  var[509] = workYaw.v[483];
  var[510] = workYaw.v[379];
  var[511] = workYaw.v[486];
  var[512] = workYaw.v[487];
  var[513] = workYaw.v[380];
  var[514] = workYaw.v[490];
  var[515] = workYaw.v[491];
  var[516] = workYaw.v[381];
  var[517] = workYaw.v[494];
  var[518] = workYaw.v[495];
  var[519] = workYaw.v[382];
  var[520] = workYaw.v[498];
  var[521] = workYaw.v[499];
  var[522] = workYaw.v[383];
  var[523] = workYaw.v[502];
  var[524] = workYaw.v[503];
  var[525] = workYaw.v[384];
  var[526] = workYaw.v[506];
  var[527] = workYaw.v[507];
  var[528] = workYaw.v[385];
  var[529] = workYaw.v[510];
  var[530] = workYaw.v[511];
  var[531] = workYaw.v[386];
  var[532] = workYaw.v[514];
  var[533] = workYaw.v[515];
  var[534] = workYaw.v[387];
  var[535] = workYaw.v[518];
  var[536] = workYaw.v[519];
  var[537] = workYaw.v[388];
  var[538] = workYaw.v[522];
  var[539] = workYaw.v[523];
  var[540] = workYaw.v[389];
  var[541] = workYaw.v[526];
  var[542] = workYaw.v[527];
  var[543] = workYaw.v[390];
  var[544] = workYaw.v[530];
  var[545] = workYaw.v[531];
  var[546] = workYaw.v[391];
  var[547] = workYaw.v[534];
  var[548] = workYaw.v[535];
  var[549] = workYaw.v[392];
  var[550] = workYaw.v[538];
  var[551] = workYaw.v[539];
  var[552] = workYaw.v[393];
  var[553] = workYaw.v[542];
  var[554] = workYaw.v[543];
  var[555] = workYaw.v[394];
  var[556] = workYaw.v[546];
  var[557] = workYaw.v[547];
  var[558] = workYaw.v[395];
  var[559] = workYaw.v[550];
  var[560] = workYaw.v[551];
  var[561] = workYaw.v[396];
  var[562] = workYaw.v[554];
  var[563] = workYaw.v[555];
  var[564] = workYaw.v[397];
  var[565] = workYaw.v[558];
  var[566] = workYaw.v[559];
  var[567] = workYaw.v[398];
  var[568] = workYaw.v[562];
  var[569] = workYaw.v[563];
  var[570] = workYaw.v[399];
  var[571] = workYaw.v[566];
  var[572] = workYaw.v[567];
  var[573] = workYaw.v[400];
  var[574] = workYaw.v[570];
  var[575] = workYaw.v[571];
  var[576] = workYaw.v[401];
  var[577] = workYaw.v[574];
  var[578] = workYaw.v[575];
  var[579] = workYaw.v[402];
  var[580] = workYaw.v[578];
  var[581] = workYaw.v[579];
  var[582] = workYaw.v[403];
  var[583] = workYaw.v[582];
  var[584] = workYaw.v[583];
  var[585] = workYaw.v[404];
  var[586] = workYaw.v[586];
  var[587] = workYaw.v[587];
  var[588] = workYaw.v[405];
  var[589] = workYaw.v[590];
  var[590] = workYaw.v[591];
  var[591] = workYaw.v[406];
  var[592] = workYaw.v[594];
  var[593] = workYaw.v[595];
  var[594] = workYaw.v[407];
  var[595] = workYaw.v[596];
  var[596] = workYaw.v[597];
  var[597] = workYaw.v[408];
  var[598] = workYaw.v[409];
  var[599] = workYaw.v[410];
  var[600] = workYaw.v[365];
#ifndef ZERO_LIBRARY_MODE
  if (settingsYaw.debug) {
    printf("Squared norm for solution is %.8g.\n", check_residual_yaw(target, var));
  }
#endif
}
void ldl_factor_yaw(void) {
  workYaw.d[0] = workYaw.KKT[0];
  if (workYaw.d[0] < 0)
    workYaw.d[0] = settingsYaw.kkt_reg;
  else
    workYaw.d[0] += settingsYaw.kkt_reg;
  workYaw.d_inv[0] = 1/workYaw.d[0];
  workYaw.v[1] = workYaw.KKT[1];
  workYaw.d[1] = workYaw.v[1];
  if (workYaw.d[1] < 0)
    workYaw.d[1] = settingsYaw.kkt_reg;
  else
    workYaw.d[1] += settingsYaw.kkt_reg;
  workYaw.d_inv[1] = 1/workYaw.d[1];
  workYaw.L[0] = (workYaw.KKT[2])*workYaw.d_inv[1];
  workYaw.v[2] = workYaw.KKT[3];
  workYaw.d[2] = workYaw.v[2];
  if (workYaw.d[2] < 0)
    workYaw.d[2] = settingsYaw.kkt_reg;
  else
    workYaw.d[2] += settingsYaw.kkt_reg;
  workYaw.d_inv[2] = 1/workYaw.d[2];
  workYaw.L[1] = (workYaw.KKT[4])*workYaw.d_inv[2];
  workYaw.v[3] = workYaw.KKT[5];
  workYaw.d[3] = workYaw.v[3];
  if (workYaw.d[3] < 0)
    workYaw.d[3] = settingsYaw.kkt_reg;
  else
    workYaw.d[3] += settingsYaw.kkt_reg;
  workYaw.d_inv[3] = 1/workYaw.d[3];
  workYaw.L[2] = (workYaw.KKT[6])*workYaw.d_inv[3];
  workYaw.v[4] = workYaw.KKT[7];
  workYaw.d[4] = workYaw.v[4];
  if (workYaw.d[4] < 0)
    workYaw.d[4] = settingsYaw.kkt_reg;
  else
    workYaw.d[4] += settingsYaw.kkt_reg;
  workYaw.d_inv[4] = 1/workYaw.d[4];
  workYaw.L[3] = (workYaw.KKT[8])*workYaw.d_inv[4];
  workYaw.v[5] = workYaw.KKT[9];
  workYaw.d[5] = workYaw.v[5];
  if (workYaw.d[5] < 0)
    workYaw.d[5] = settingsYaw.kkt_reg;
  else
    workYaw.d[5] += settingsYaw.kkt_reg;
  workYaw.d_inv[5] = 1/workYaw.d[5];
  workYaw.L[4] = (workYaw.KKT[10])*workYaw.d_inv[5];
  workYaw.v[6] = workYaw.KKT[11];
  workYaw.d[6] = workYaw.v[6];
  if (workYaw.d[6] < 0)
    workYaw.d[6] = settingsYaw.kkt_reg;
  else
    workYaw.d[6] += settingsYaw.kkt_reg;
  workYaw.d_inv[6] = 1/workYaw.d[6];
  workYaw.L[5] = (workYaw.KKT[12])*workYaw.d_inv[6];
  workYaw.v[7] = workYaw.KKT[13];
  workYaw.d[7] = workYaw.v[7];
  if (workYaw.d[7] < 0)
    workYaw.d[7] = settingsYaw.kkt_reg;
  else
    workYaw.d[7] += settingsYaw.kkt_reg;
  workYaw.d_inv[7] = 1/workYaw.d[7];
  workYaw.L[6] = (workYaw.KKT[14])*workYaw.d_inv[7];
  workYaw.v[8] = workYaw.KKT[15];
  workYaw.d[8] = workYaw.v[8];
  if (workYaw.d[8] < 0)
    workYaw.d[8] = settingsYaw.kkt_reg;
  else
    workYaw.d[8] += settingsYaw.kkt_reg;
  workYaw.d_inv[8] = 1/workYaw.d[8];
  workYaw.L[7] = (workYaw.KKT[16])*workYaw.d_inv[8];
  workYaw.v[9] = workYaw.KKT[17];
  workYaw.d[9] = workYaw.v[9];
  if (workYaw.d[9] < 0)
    workYaw.d[9] = settingsYaw.kkt_reg;
  else
    workYaw.d[9] += settingsYaw.kkt_reg;
  workYaw.d_inv[9] = 1/workYaw.d[9];
  workYaw.L[8] = (workYaw.KKT[18])*workYaw.d_inv[9];
  workYaw.v[10] = workYaw.KKT[19];
  workYaw.d[10] = workYaw.v[10];
  if (workYaw.d[10] < 0)
    workYaw.d[10] = settingsYaw.kkt_reg;
  else
    workYaw.d[10] += settingsYaw.kkt_reg;
  workYaw.d_inv[10] = 1/workYaw.d[10];
  workYaw.L[9] = (workYaw.KKT[20])*workYaw.d_inv[10];
  workYaw.v[11] = workYaw.KKT[21];
  workYaw.d[11] = workYaw.v[11];
  if (workYaw.d[11] < 0)
    workYaw.d[11] = settingsYaw.kkt_reg;
  else
    workYaw.d[11] += settingsYaw.kkt_reg;
  workYaw.d_inv[11] = 1/workYaw.d[11];
  workYaw.L[10] = (workYaw.KKT[22])*workYaw.d_inv[11];
  workYaw.v[12] = workYaw.KKT[23];
  workYaw.d[12] = workYaw.v[12];
  if (workYaw.d[12] < 0)
    workYaw.d[12] = settingsYaw.kkt_reg;
  else
    workYaw.d[12] += settingsYaw.kkt_reg;
  workYaw.d_inv[12] = 1/workYaw.d[12];
  workYaw.L[11] = (workYaw.KKT[24])*workYaw.d_inv[12];
  workYaw.v[13] = workYaw.KKT[25];
  workYaw.d[13] = workYaw.v[13];
  if (workYaw.d[13] < 0)
    workYaw.d[13] = settingsYaw.kkt_reg;
  else
    workYaw.d[13] += settingsYaw.kkt_reg;
  workYaw.d_inv[13] = 1/workYaw.d[13];
  workYaw.L[12] = (workYaw.KKT[26])*workYaw.d_inv[13];
  workYaw.v[14] = workYaw.KKT[27];
  workYaw.d[14] = workYaw.v[14];
  if (workYaw.d[14] < 0)
    workYaw.d[14] = settingsYaw.kkt_reg;
  else
    workYaw.d[14] += settingsYaw.kkt_reg;
  workYaw.d_inv[14] = 1/workYaw.d[14];
  workYaw.L[13] = (workYaw.KKT[28])*workYaw.d_inv[14];
  workYaw.v[15] = workYaw.KKT[29];
  workYaw.d[15] = workYaw.v[15];
  if (workYaw.d[15] < 0)
    workYaw.d[15] = settingsYaw.kkt_reg;
  else
    workYaw.d[15] += settingsYaw.kkt_reg;
  workYaw.d_inv[15] = 1/workYaw.d[15];
  workYaw.L[14] = (workYaw.KKT[30])*workYaw.d_inv[15];
  workYaw.v[16] = workYaw.KKT[31];
  workYaw.d[16] = workYaw.v[16];
  if (workYaw.d[16] < 0)
    workYaw.d[16] = settingsYaw.kkt_reg;
  else
    workYaw.d[16] += settingsYaw.kkt_reg;
  workYaw.d_inv[16] = 1/workYaw.d[16];
  workYaw.L[15] = (workYaw.KKT[32])*workYaw.d_inv[16];
  workYaw.v[17] = workYaw.KKT[33];
  workYaw.d[17] = workYaw.v[17];
  if (workYaw.d[17] < 0)
    workYaw.d[17] = settingsYaw.kkt_reg;
  else
    workYaw.d[17] += settingsYaw.kkt_reg;
  workYaw.d_inv[17] = 1/workYaw.d[17];
  workYaw.L[16] = (workYaw.KKT[34])*workYaw.d_inv[17];
  workYaw.v[18] = workYaw.KKT[35];
  workYaw.d[18] = workYaw.v[18];
  if (workYaw.d[18] < 0)
    workYaw.d[18] = settingsYaw.kkt_reg;
  else
    workYaw.d[18] += settingsYaw.kkt_reg;
  workYaw.d_inv[18] = 1/workYaw.d[18];
  workYaw.L[17] = (workYaw.KKT[36])*workYaw.d_inv[18];
  workYaw.v[19] = workYaw.KKT[37];
  workYaw.d[19] = workYaw.v[19];
  if (workYaw.d[19] < 0)
    workYaw.d[19] = settingsYaw.kkt_reg;
  else
    workYaw.d[19] += settingsYaw.kkt_reg;
  workYaw.d_inv[19] = 1/workYaw.d[19];
  workYaw.L[18] = (workYaw.KKT[38])*workYaw.d_inv[19];
  workYaw.v[20] = workYaw.KKT[39];
  workYaw.d[20] = workYaw.v[20];
  if (workYaw.d[20] < 0)
    workYaw.d[20] = settingsYaw.kkt_reg;
  else
    workYaw.d[20] += settingsYaw.kkt_reg;
  workYaw.d_inv[20] = 1/workYaw.d[20];
  workYaw.L[19] = (workYaw.KKT[40])*workYaw.d_inv[20];
  workYaw.v[21] = workYaw.KKT[41];
  workYaw.d[21] = workYaw.v[21];
  if (workYaw.d[21] < 0)
    workYaw.d[21] = settingsYaw.kkt_reg;
  else
    workYaw.d[21] += settingsYaw.kkt_reg;
  workYaw.d_inv[21] = 1/workYaw.d[21];
  workYaw.L[20] = (workYaw.KKT[42])*workYaw.d_inv[21];
  workYaw.v[22] = workYaw.KKT[43];
  workYaw.d[22] = workYaw.v[22];
  if (workYaw.d[22] < 0)
    workYaw.d[22] = settingsYaw.kkt_reg;
  else
    workYaw.d[22] += settingsYaw.kkt_reg;
  workYaw.d_inv[22] = 1/workYaw.d[22];
  workYaw.L[21] = (workYaw.KKT[44])*workYaw.d_inv[22];
  workYaw.v[23] = workYaw.KKT[45];
  workYaw.d[23] = workYaw.v[23];
  if (workYaw.d[23] < 0)
    workYaw.d[23] = settingsYaw.kkt_reg;
  else
    workYaw.d[23] += settingsYaw.kkt_reg;
  workYaw.d_inv[23] = 1/workYaw.d[23];
  workYaw.L[22] = (workYaw.KKT[46])*workYaw.d_inv[23];
  workYaw.v[24] = workYaw.KKT[47];
  workYaw.d[24] = workYaw.v[24];
  if (workYaw.d[24] < 0)
    workYaw.d[24] = settingsYaw.kkt_reg;
  else
    workYaw.d[24] += settingsYaw.kkt_reg;
  workYaw.d_inv[24] = 1/workYaw.d[24];
  workYaw.L[23] = (workYaw.KKT[48])*workYaw.d_inv[24];
  workYaw.v[25] = workYaw.KKT[49];
  workYaw.d[25] = workYaw.v[25];
  if (workYaw.d[25] < 0)
    workYaw.d[25] = settingsYaw.kkt_reg;
  else
    workYaw.d[25] += settingsYaw.kkt_reg;
  workYaw.d_inv[25] = 1/workYaw.d[25];
  workYaw.L[24] = (workYaw.KKT[50])*workYaw.d_inv[25];
  workYaw.v[26] = workYaw.KKT[51];
  workYaw.d[26] = workYaw.v[26];
  if (workYaw.d[26] < 0)
    workYaw.d[26] = settingsYaw.kkt_reg;
  else
    workYaw.d[26] += settingsYaw.kkt_reg;
  workYaw.d_inv[26] = 1/workYaw.d[26];
  workYaw.L[25] = (workYaw.KKT[52])*workYaw.d_inv[26];
  workYaw.v[27] = workYaw.KKT[53];
  workYaw.d[27] = workYaw.v[27];
  if (workYaw.d[27] < 0)
    workYaw.d[27] = settingsYaw.kkt_reg;
  else
    workYaw.d[27] += settingsYaw.kkt_reg;
  workYaw.d_inv[27] = 1/workYaw.d[27];
  workYaw.L[26] = (workYaw.KKT[54])*workYaw.d_inv[27];
  workYaw.v[28] = workYaw.KKT[55];
  workYaw.d[28] = workYaw.v[28];
  if (workYaw.d[28] < 0)
    workYaw.d[28] = settingsYaw.kkt_reg;
  else
    workYaw.d[28] += settingsYaw.kkt_reg;
  workYaw.d_inv[28] = 1/workYaw.d[28];
  workYaw.L[27] = (workYaw.KKT[56])*workYaw.d_inv[28];
  workYaw.v[29] = workYaw.KKT[57];
  workYaw.d[29] = workYaw.v[29];
  if (workYaw.d[29] < 0)
    workYaw.d[29] = settingsYaw.kkt_reg;
  else
    workYaw.d[29] += settingsYaw.kkt_reg;
  workYaw.d_inv[29] = 1/workYaw.d[29];
  workYaw.L[28] = (workYaw.KKT[58])*workYaw.d_inv[29];
  workYaw.v[30] = workYaw.KKT[59];
  workYaw.d[30] = workYaw.v[30];
  if (workYaw.d[30] < 0)
    workYaw.d[30] = settingsYaw.kkt_reg;
  else
    workYaw.d[30] += settingsYaw.kkt_reg;
  workYaw.d_inv[30] = 1/workYaw.d[30];
  workYaw.L[29] = (workYaw.KKT[60])*workYaw.d_inv[30];
  workYaw.v[31] = workYaw.KKT[61];
  workYaw.d[31] = workYaw.v[31];
  if (workYaw.d[31] < 0)
    workYaw.d[31] = settingsYaw.kkt_reg;
  else
    workYaw.d[31] += settingsYaw.kkt_reg;
  workYaw.d_inv[31] = 1/workYaw.d[31];
  workYaw.L[30] = (workYaw.KKT[62])*workYaw.d_inv[31];
  workYaw.v[32] = workYaw.KKT[63];
  workYaw.d[32] = workYaw.v[32];
  if (workYaw.d[32] < 0)
    workYaw.d[32] = settingsYaw.kkt_reg;
  else
    workYaw.d[32] += settingsYaw.kkt_reg;
  workYaw.d_inv[32] = 1/workYaw.d[32];
  workYaw.L[31] = (workYaw.KKT[64])*workYaw.d_inv[32];
  workYaw.v[33] = workYaw.KKT[65];
  workYaw.d[33] = workYaw.v[33];
  if (workYaw.d[33] < 0)
    workYaw.d[33] = settingsYaw.kkt_reg;
  else
    workYaw.d[33] += settingsYaw.kkt_reg;
  workYaw.d_inv[33] = 1/workYaw.d[33];
  workYaw.L[32] = (workYaw.KKT[66])*workYaw.d_inv[33];
  workYaw.v[34] = workYaw.KKT[67];
  workYaw.d[34] = workYaw.v[34];
  if (workYaw.d[34] < 0)
    workYaw.d[34] = settingsYaw.kkt_reg;
  else
    workYaw.d[34] += settingsYaw.kkt_reg;
  workYaw.d_inv[34] = 1/workYaw.d[34];
  workYaw.L[33] = (workYaw.KKT[68])*workYaw.d_inv[34];
  workYaw.v[35] = workYaw.KKT[69];
  workYaw.d[35] = workYaw.v[35];
  if (workYaw.d[35] < 0)
    workYaw.d[35] = settingsYaw.kkt_reg;
  else
    workYaw.d[35] += settingsYaw.kkt_reg;
  workYaw.d_inv[35] = 1/workYaw.d[35];
  workYaw.L[34] = (workYaw.KKT[70])*workYaw.d_inv[35];
  workYaw.v[36] = workYaw.KKT[71];
  workYaw.d[36] = workYaw.v[36];
  if (workYaw.d[36] < 0)
    workYaw.d[36] = settingsYaw.kkt_reg;
  else
    workYaw.d[36] += settingsYaw.kkt_reg;
  workYaw.d_inv[36] = 1/workYaw.d[36];
  workYaw.L[35] = (workYaw.KKT[72])*workYaw.d_inv[36];
  workYaw.v[37] = workYaw.KKT[73];
  workYaw.d[37] = workYaw.v[37];
  if (workYaw.d[37] < 0)
    workYaw.d[37] = settingsYaw.kkt_reg;
  else
    workYaw.d[37] += settingsYaw.kkt_reg;
  workYaw.d_inv[37] = 1/workYaw.d[37];
  workYaw.L[36] = (workYaw.KKT[74])*workYaw.d_inv[37];
  workYaw.v[38] = workYaw.KKT[75];
  workYaw.d[38] = workYaw.v[38];
  if (workYaw.d[38] < 0)
    workYaw.d[38] = settingsYaw.kkt_reg;
  else
    workYaw.d[38] += settingsYaw.kkt_reg;
  workYaw.d_inv[38] = 1/workYaw.d[38];
  workYaw.L[37] = (workYaw.KKT[76])*workYaw.d_inv[38];
  workYaw.v[39] = workYaw.KKT[77];
  workYaw.d[39] = workYaw.v[39];
  if (workYaw.d[39] < 0)
    workYaw.d[39] = settingsYaw.kkt_reg;
  else
    workYaw.d[39] += settingsYaw.kkt_reg;
  workYaw.d_inv[39] = 1/workYaw.d[39];
  workYaw.L[38] = (workYaw.KKT[78])*workYaw.d_inv[39];
  workYaw.v[40] = workYaw.KKT[79];
  workYaw.d[40] = workYaw.v[40];
  if (workYaw.d[40] < 0)
    workYaw.d[40] = settingsYaw.kkt_reg;
  else
    workYaw.d[40] += settingsYaw.kkt_reg;
  workYaw.d_inv[40] = 1/workYaw.d[40];
  workYaw.L[39] = (workYaw.KKT[80])*workYaw.d_inv[40];
  workYaw.v[41] = workYaw.KKT[81];
  workYaw.d[41] = workYaw.v[41];
  if (workYaw.d[41] < 0)
    workYaw.d[41] = settingsYaw.kkt_reg;
  else
    workYaw.d[41] += settingsYaw.kkt_reg;
  workYaw.d_inv[41] = 1/workYaw.d[41];
  workYaw.L[40] = (workYaw.KKT[82])*workYaw.d_inv[41];
  workYaw.v[42] = workYaw.KKT[83];
  workYaw.d[42] = workYaw.v[42];
  if (workYaw.d[42] < 0)
    workYaw.d[42] = settingsYaw.kkt_reg;
  else
    workYaw.d[42] += settingsYaw.kkt_reg;
  workYaw.d_inv[42] = 1/workYaw.d[42];
  workYaw.L[41] = (workYaw.KKT[84])*workYaw.d_inv[42];
  workYaw.v[43] = workYaw.KKT[85];
  workYaw.d[43] = workYaw.v[43];
  if (workYaw.d[43] < 0)
    workYaw.d[43] = settingsYaw.kkt_reg;
  else
    workYaw.d[43] += settingsYaw.kkt_reg;
  workYaw.d_inv[43] = 1/workYaw.d[43];
  workYaw.L[42] = (workYaw.KKT[86])*workYaw.d_inv[43];
  workYaw.v[44] = workYaw.KKT[87];
  workYaw.d[44] = workYaw.v[44];
  if (workYaw.d[44] < 0)
    workYaw.d[44] = settingsYaw.kkt_reg;
  else
    workYaw.d[44] += settingsYaw.kkt_reg;
  workYaw.d_inv[44] = 1/workYaw.d[44];
  workYaw.L[43] = (workYaw.KKT[88])*workYaw.d_inv[44];
  workYaw.v[45] = workYaw.KKT[89];
  workYaw.d[45] = workYaw.v[45];
  if (workYaw.d[45] < 0)
    workYaw.d[45] = settingsYaw.kkt_reg;
  else
    workYaw.d[45] += settingsYaw.kkt_reg;
  workYaw.d_inv[45] = 1/workYaw.d[45];
  workYaw.L[44] = (workYaw.KKT[90])*workYaw.d_inv[45];
  workYaw.v[46] = workYaw.KKT[91];
  workYaw.d[46] = workYaw.v[46];
  if (workYaw.d[46] < 0)
    workYaw.d[46] = settingsYaw.kkt_reg;
  else
    workYaw.d[46] += settingsYaw.kkt_reg;
  workYaw.d_inv[46] = 1/workYaw.d[46];
  workYaw.L[45] = (workYaw.KKT[92])*workYaw.d_inv[46];
  workYaw.v[47] = workYaw.KKT[93];
  workYaw.d[47] = workYaw.v[47];
  if (workYaw.d[47] < 0)
    workYaw.d[47] = settingsYaw.kkt_reg;
  else
    workYaw.d[47] += settingsYaw.kkt_reg;
  workYaw.d_inv[47] = 1/workYaw.d[47];
  workYaw.L[46] = (workYaw.KKT[94])*workYaw.d_inv[47];
  workYaw.v[48] = workYaw.KKT[95];
  workYaw.d[48] = workYaw.v[48];
  if (workYaw.d[48] < 0)
    workYaw.d[48] = settingsYaw.kkt_reg;
  else
    workYaw.d[48] += settingsYaw.kkt_reg;
  workYaw.d_inv[48] = 1/workYaw.d[48];
  workYaw.L[47] = (workYaw.KKT[96])*workYaw.d_inv[48];
  workYaw.v[49] = workYaw.KKT[97];
  workYaw.d[49] = workYaw.v[49];
  if (workYaw.d[49] < 0)
    workYaw.d[49] = settingsYaw.kkt_reg;
  else
    workYaw.d[49] += settingsYaw.kkt_reg;
  workYaw.d_inv[49] = 1/workYaw.d[49];
  workYaw.L[48] = (workYaw.KKT[98])*workYaw.d_inv[49];
  workYaw.v[50] = workYaw.KKT[99];
  workYaw.d[50] = workYaw.v[50];
  if (workYaw.d[50] < 0)
    workYaw.d[50] = settingsYaw.kkt_reg;
  else
    workYaw.d[50] += settingsYaw.kkt_reg;
  workYaw.d_inv[50] = 1/workYaw.d[50];
  workYaw.L[49] = (workYaw.KKT[100])*workYaw.d_inv[50];
  workYaw.v[51] = workYaw.KKT[101];
  workYaw.d[51] = workYaw.v[51];
  if (workYaw.d[51] < 0)
    workYaw.d[51] = settingsYaw.kkt_reg;
  else
    workYaw.d[51] += settingsYaw.kkt_reg;
  workYaw.d_inv[51] = 1/workYaw.d[51];
  workYaw.L[50] = (workYaw.KKT[102])*workYaw.d_inv[51];
  workYaw.v[52] = workYaw.KKT[103];
  workYaw.d[52] = workYaw.v[52];
  if (workYaw.d[52] < 0)
    workYaw.d[52] = settingsYaw.kkt_reg;
  else
    workYaw.d[52] += settingsYaw.kkt_reg;
  workYaw.d_inv[52] = 1/workYaw.d[52];
  workYaw.L[51] = (workYaw.KKT[104])*workYaw.d_inv[52];
  workYaw.v[53] = workYaw.KKT[105];
  workYaw.d[53] = workYaw.v[53];
  if (workYaw.d[53] < 0)
    workYaw.d[53] = settingsYaw.kkt_reg;
  else
    workYaw.d[53] += settingsYaw.kkt_reg;
  workYaw.d_inv[53] = 1/workYaw.d[53];
  workYaw.L[52] = (workYaw.KKT[106])*workYaw.d_inv[53];
  workYaw.v[54] = workYaw.KKT[107];
  workYaw.d[54] = workYaw.v[54];
  if (workYaw.d[54] < 0)
    workYaw.d[54] = settingsYaw.kkt_reg;
  else
    workYaw.d[54] += settingsYaw.kkt_reg;
  workYaw.d_inv[54] = 1/workYaw.d[54];
  workYaw.L[53] = (workYaw.KKT[108])*workYaw.d_inv[54];
  workYaw.v[55] = workYaw.KKT[109];
  workYaw.d[55] = workYaw.v[55];
  if (workYaw.d[55] < 0)
    workYaw.d[55] = settingsYaw.kkt_reg;
  else
    workYaw.d[55] += settingsYaw.kkt_reg;
  workYaw.d_inv[55] = 1/workYaw.d[55];
  workYaw.L[54] = (workYaw.KKT[110])*workYaw.d_inv[55];
  workYaw.v[56] = workYaw.KKT[111];
  workYaw.d[56] = workYaw.v[56];
  if (workYaw.d[56] < 0)
    workYaw.d[56] = settingsYaw.kkt_reg;
  else
    workYaw.d[56] += settingsYaw.kkt_reg;
  workYaw.d_inv[56] = 1/workYaw.d[56];
  workYaw.L[55] = (workYaw.KKT[112])*workYaw.d_inv[56];
  workYaw.v[57] = workYaw.KKT[113];
  workYaw.d[57] = workYaw.v[57];
  if (workYaw.d[57] < 0)
    workYaw.d[57] = settingsYaw.kkt_reg;
  else
    workYaw.d[57] += settingsYaw.kkt_reg;
  workYaw.d_inv[57] = 1/workYaw.d[57];
  workYaw.L[56] = (workYaw.KKT[114])*workYaw.d_inv[57];
  workYaw.v[58] = workYaw.KKT[115];
  workYaw.d[58] = workYaw.v[58];
  if (workYaw.d[58] < 0)
    workYaw.d[58] = settingsYaw.kkt_reg;
  else
    workYaw.d[58] += settingsYaw.kkt_reg;
  workYaw.d_inv[58] = 1/workYaw.d[58];
  workYaw.L[57] = (workYaw.KKT[116])*workYaw.d_inv[58];
  workYaw.v[59] = workYaw.KKT[117];
  workYaw.d[59] = workYaw.v[59];
  if (workYaw.d[59] < 0)
    workYaw.d[59] = settingsYaw.kkt_reg;
  else
    workYaw.d[59] += settingsYaw.kkt_reg;
  workYaw.d_inv[59] = 1/workYaw.d[59];
  workYaw.L[58] = (workYaw.KKT[118])*workYaw.d_inv[59];
  workYaw.v[60] = workYaw.KKT[119];
  workYaw.d[60] = workYaw.v[60];
  if (workYaw.d[60] < 0)
    workYaw.d[60] = settingsYaw.kkt_reg;
  else
    workYaw.d[60] += settingsYaw.kkt_reg;
  workYaw.d_inv[60] = 1/workYaw.d[60];
  workYaw.L[59] = (workYaw.KKT[120])*workYaw.d_inv[60];
  workYaw.v[61] = workYaw.KKT[121];
  workYaw.d[61] = workYaw.v[61];
  if (workYaw.d[61] < 0)
    workYaw.d[61] = settingsYaw.kkt_reg;
  else
    workYaw.d[61] += settingsYaw.kkt_reg;
  workYaw.d_inv[61] = 1/workYaw.d[61];
  workYaw.L[60] = (workYaw.KKT[122])*workYaw.d_inv[61];
  workYaw.v[62] = workYaw.KKT[123];
  workYaw.d[62] = workYaw.v[62];
  if (workYaw.d[62] < 0)
    workYaw.d[62] = settingsYaw.kkt_reg;
  else
    workYaw.d[62] += settingsYaw.kkt_reg;
  workYaw.d_inv[62] = 1/workYaw.d[62];
  workYaw.L[61] = (workYaw.KKT[124])*workYaw.d_inv[62];
  workYaw.v[63] = workYaw.KKT[125];
  workYaw.d[63] = workYaw.v[63];
  if (workYaw.d[63] < 0)
    workYaw.d[63] = settingsYaw.kkt_reg;
  else
    workYaw.d[63] += settingsYaw.kkt_reg;
  workYaw.d_inv[63] = 1/workYaw.d[63];
  workYaw.L[62] = (workYaw.KKT[126])*workYaw.d_inv[63];
  workYaw.v[64] = workYaw.KKT[127];
  workYaw.d[64] = workYaw.v[64];
  if (workYaw.d[64] < 0)
    workYaw.d[64] = settingsYaw.kkt_reg;
  else
    workYaw.d[64] += settingsYaw.kkt_reg;
  workYaw.d_inv[64] = 1/workYaw.d[64];
  workYaw.L[63] = (workYaw.KKT[128])*workYaw.d_inv[64];
  workYaw.v[65] = workYaw.KKT[129];
  workYaw.d[65] = workYaw.v[65];
  if (workYaw.d[65] < 0)
    workYaw.d[65] = settingsYaw.kkt_reg;
  else
    workYaw.d[65] += settingsYaw.kkt_reg;
  workYaw.d_inv[65] = 1/workYaw.d[65];
  workYaw.L[64] = (workYaw.KKT[130])*workYaw.d_inv[65];
  workYaw.v[66] = workYaw.KKT[131];
  workYaw.d[66] = workYaw.v[66];
  if (workYaw.d[66] < 0)
    workYaw.d[66] = settingsYaw.kkt_reg;
  else
    workYaw.d[66] += settingsYaw.kkt_reg;
  workYaw.d_inv[66] = 1/workYaw.d[66];
  workYaw.L[65] = (workYaw.KKT[132])*workYaw.d_inv[66];
  workYaw.v[67] = workYaw.KKT[133];
  workYaw.d[67] = workYaw.v[67];
  if (workYaw.d[67] < 0)
    workYaw.d[67] = settingsYaw.kkt_reg;
  else
    workYaw.d[67] += settingsYaw.kkt_reg;
  workYaw.d_inv[67] = 1/workYaw.d[67];
  workYaw.L[66] = (workYaw.KKT[134])*workYaw.d_inv[67];
  workYaw.v[68] = workYaw.KKT[135];
  workYaw.d[68] = workYaw.v[68];
  if (workYaw.d[68] < 0)
    workYaw.d[68] = settingsYaw.kkt_reg;
  else
    workYaw.d[68] += settingsYaw.kkt_reg;
  workYaw.d_inv[68] = 1/workYaw.d[68];
  workYaw.L[67] = (workYaw.KKT[136])*workYaw.d_inv[68];
  workYaw.v[69] = workYaw.KKT[137];
  workYaw.d[69] = workYaw.v[69];
  if (workYaw.d[69] < 0)
    workYaw.d[69] = settingsYaw.kkt_reg;
  else
    workYaw.d[69] += settingsYaw.kkt_reg;
  workYaw.d_inv[69] = 1/workYaw.d[69];
  workYaw.L[68] = (workYaw.KKT[138])*workYaw.d_inv[69];
  workYaw.v[70] = workYaw.KKT[139];
  workYaw.d[70] = workYaw.v[70];
  if (workYaw.d[70] < 0)
    workYaw.d[70] = settingsYaw.kkt_reg;
  else
    workYaw.d[70] += settingsYaw.kkt_reg;
  workYaw.d_inv[70] = 1/workYaw.d[70];
  workYaw.L[69] = (workYaw.KKT[140])*workYaw.d_inv[70];
  workYaw.v[71] = workYaw.KKT[141];
  workYaw.d[71] = workYaw.v[71];
  if (workYaw.d[71] < 0)
    workYaw.d[71] = settingsYaw.kkt_reg;
  else
    workYaw.d[71] += settingsYaw.kkt_reg;
  workYaw.d_inv[71] = 1/workYaw.d[71];
  workYaw.L[70] = (workYaw.KKT[142])*workYaw.d_inv[71];
  workYaw.v[72] = workYaw.KKT[143];
  workYaw.d[72] = workYaw.v[72];
  if (workYaw.d[72] < 0)
    workYaw.d[72] = settingsYaw.kkt_reg;
  else
    workYaw.d[72] += settingsYaw.kkt_reg;
  workYaw.d_inv[72] = 1/workYaw.d[72];
  workYaw.L[71] = (workYaw.KKT[144])*workYaw.d_inv[72];
  workYaw.v[73] = workYaw.KKT[145];
  workYaw.d[73] = workYaw.v[73];
  if (workYaw.d[73] < 0)
    workYaw.d[73] = settingsYaw.kkt_reg;
  else
    workYaw.d[73] += settingsYaw.kkt_reg;
  workYaw.d_inv[73] = 1/workYaw.d[73];
  workYaw.L[72] = (workYaw.KKT[146])*workYaw.d_inv[73];
  workYaw.v[74] = workYaw.KKT[147];
  workYaw.d[74] = workYaw.v[74];
  if (workYaw.d[74] < 0)
    workYaw.d[74] = settingsYaw.kkt_reg;
  else
    workYaw.d[74] += settingsYaw.kkt_reg;
  workYaw.d_inv[74] = 1/workYaw.d[74];
  workYaw.L[73] = (workYaw.KKT[148])*workYaw.d_inv[74];
  workYaw.v[75] = workYaw.KKT[149];
  workYaw.d[75] = workYaw.v[75];
  if (workYaw.d[75] < 0)
    workYaw.d[75] = settingsYaw.kkt_reg;
  else
    workYaw.d[75] += settingsYaw.kkt_reg;
  workYaw.d_inv[75] = 1/workYaw.d[75];
  workYaw.L[74] = (workYaw.KKT[150])*workYaw.d_inv[75];
  workYaw.v[76] = workYaw.KKT[151];
  workYaw.d[76] = workYaw.v[76];
  if (workYaw.d[76] < 0)
    workYaw.d[76] = settingsYaw.kkt_reg;
  else
    workYaw.d[76] += settingsYaw.kkt_reg;
  workYaw.d_inv[76] = 1/workYaw.d[76];
  workYaw.L[75] = (workYaw.KKT[152])*workYaw.d_inv[76];
  workYaw.v[77] = workYaw.KKT[153];
  workYaw.d[77] = workYaw.v[77];
  if (workYaw.d[77] < 0)
    workYaw.d[77] = settingsYaw.kkt_reg;
  else
    workYaw.d[77] += settingsYaw.kkt_reg;
  workYaw.d_inv[77] = 1/workYaw.d[77];
  workYaw.L[76] = (workYaw.KKT[154])*workYaw.d_inv[77];
  workYaw.v[78] = workYaw.KKT[155];
  workYaw.d[78] = workYaw.v[78];
  if (workYaw.d[78] < 0)
    workYaw.d[78] = settingsYaw.kkt_reg;
  else
    workYaw.d[78] += settingsYaw.kkt_reg;
  workYaw.d_inv[78] = 1/workYaw.d[78];
  workYaw.L[77] = (workYaw.KKT[156])*workYaw.d_inv[78];
  workYaw.v[79] = workYaw.KKT[157];
  workYaw.d[79] = workYaw.v[79];
  if (workYaw.d[79] < 0)
    workYaw.d[79] = settingsYaw.kkt_reg;
  else
    workYaw.d[79] += settingsYaw.kkt_reg;
  workYaw.d_inv[79] = 1/workYaw.d[79];
  workYaw.L[78] = (workYaw.KKT[158])*workYaw.d_inv[79];
  workYaw.v[80] = workYaw.KKT[159];
  workYaw.d[80] = workYaw.v[80];
  if (workYaw.d[80] < 0)
    workYaw.d[80] = settingsYaw.kkt_reg;
  else
    workYaw.d[80] += settingsYaw.kkt_reg;
  workYaw.d_inv[80] = 1/workYaw.d[80];
  workYaw.L[79] = (workYaw.KKT[160])*workYaw.d_inv[80];
  workYaw.v[81] = workYaw.KKT[161];
  workYaw.d[81] = workYaw.v[81];
  if (workYaw.d[81] < 0)
    workYaw.d[81] = settingsYaw.kkt_reg;
  else
    workYaw.d[81] += settingsYaw.kkt_reg;
  workYaw.d_inv[81] = 1/workYaw.d[81];
  workYaw.L[80] = (workYaw.KKT[162])*workYaw.d_inv[81];
  workYaw.v[82] = workYaw.KKT[163];
  workYaw.d[82] = workYaw.v[82];
  if (workYaw.d[82] < 0)
    workYaw.d[82] = settingsYaw.kkt_reg;
  else
    workYaw.d[82] += settingsYaw.kkt_reg;
  workYaw.d_inv[82] = 1/workYaw.d[82];
  workYaw.L[81] = (workYaw.KKT[164])*workYaw.d_inv[82];
  workYaw.v[83] = workYaw.KKT[165];
  workYaw.d[83] = workYaw.v[83];
  if (workYaw.d[83] < 0)
    workYaw.d[83] = settingsYaw.kkt_reg;
  else
    workYaw.d[83] += settingsYaw.kkt_reg;
  workYaw.d_inv[83] = 1/workYaw.d[83];
  workYaw.L[82] = (workYaw.KKT[166])*workYaw.d_inv[83];
  workYaw.v[84] = workYaw.KKT[167];
  workYaw.d[84] = workYaw.v[84];
  if (workYaw.d[84] < 0)
    workYaw.d[84] = settingsYaw.kkt_reg;
  else
    workYaw.d[84] += settingsYaw.kkt_reg;
  workYaw.d_inv[84] = 1/workYaw.d[84];
  workYaw.L[83] = (workYaw.KKT[168])*workYaw.d_inv[84];
  workYaw.v[85] = workYaw.KKT[169];
  workYaw.d[85] = workYaw.v[85];
  if (workYaw.d[85] < 0)
    workYaw.d[85] = settingsYaw.kkt_reg;
  else
    workYaw.d[85] += settingsYaw.kkt_reg;
  workYaw.d_inv[85] = 1/workYaw.d[85];
  workYaw.L[84] = (workYaw.KKT[170])*workYaw.d_inv[85];
  workYaw.v[86] = workYaw.KKT[171];
  workYaw.d[86] = workYaw.v[86];
  if (workYaw.d[86] < 0)
    workYaw.d[86] = settingsYaw.kkt_reg;
  else
    workYaw.d[86] += settingsYaw.kkt_reg;
  workYaw.d_inv[86] = 1/workYaw.d[86];
  workYaw.L[85] = (workYaw.KKT[172])*workYaw.d_inv[86];
  workYaw.v[87] = workYaw.KKT[173];
  workYaw.d[87] = workYaw.v[87];
  if (workYaw.d[87] < 0)
    workYaw.d[87] = settingsYaw.kkt_reg;
  else
    workYaw.d[87] += settingsYaw.kkt_reg;
  workYaw.d_inv[87] = 1/workYaw.d[87];
  workYaw.L[86] = (workYaw.KKT[174])*workYaw.d_inv[87];
  workYaw.v[88] = workYaw.KKT[175];
  workYaw.d[88] = workYaw.v[88];
  if (workYaw.d[88] < 0)
    workYaw.d[88] = settingsYaw.kkt_reg;
  else
    workYaw.d[88] += settingsYaw.kkt_reg;
  workYaw.d_inv[88] = 1/workYaw.d[88];
  workYaw.L[87] = (workYaw.KKT[176])*workYaw.d_inv[88];
  workYaw.v[89] = workYaw.KKT[177];
  workYaw.d[89] = workYaw.v[89];
  if (workYaw.d[89] < 0)
    workYaw.d[89] = settingsYaw.kkt_reg;
  else
    workYaw.d[89] += settingsYaw.kkt_reg;
  workYaw.d_inv[89] = 1/workYaw.d[89];
  workYaw.L[88] = (workYaw.KKT[178])*workYaw.d_inv[89];
  workYaw.v[90] = workYaw.KKT[179];
  workYaw.d[90] = workYaw.v[90];
  if (workYaw.d[90] < 0)
    workYaw.d[90] = settingsYaw.kkt_reg;
  else
    workYaw.d[90] += settingsYaw.kkt_reg;
  workYaw.d_inv[90] = 1/workYaw.d[90];
  workYaw.L[89] = (workYaw.KKT[180])*workYaw.d_inv[90];
  workYaw.v[91] = workYaw.KKT[181];
  workYaw.d[91] = workYaw.v[91];
  if (workYaw.d[91] < 0)
    workYaw.d[91] = settingsYaw.kkt_reg;
  else
    workYaw.d[91] += settingsYaw.kkt_reg;
  workYaw.d_inv[91] = 1/workYaw.d[91];
  workYaw.L[90] = (workYaw.KKT[182])*workYaw.d_inv[91];
  workYaw.v[92] = workYaw.KKT[183];
  workYaw.d[92] = workYaw.v[92];
  if (workYaw.d[92] < 0)
    workYaw.d[92] = settingsYaw.kkt_reg;
  else
    workYaw.d[92] += settingsYaw.kkt_reg;
  workYaw.d_inv[92] = 1/workYaw.d[92];
  workYaw.L[91] = (workYaw.KKT[184])*workYaw.d_inv[92];
  workYaw.v[93] = workYaw.KKT[185];
  workYaw.d[93] = workYaw.v[93];
  if (workYaw.d[93] < 0)
    workYaw.d[93] = settingsYaw.kkt_reg;
  else
    workYaw.d[93] += settingsYaw.kkt_reg;
  workYaw.d_inv[93] = 1/workYaw.d[93];
  workYaw.L[92] = (workYaw.KKT[186])*workYaw.d_inv[93];
  workYaw.v[94] = workYaw.KKT[187];
  workYaw.d[94] = workYaw.v[94];
  if (workYaw.d[94] < 0)
    workYaw.d[94] = settingsYaw.kkt_reg;
  else
    workYaw.d[94] += settingsYaw.kkt_reg;
  workYaw.d_inv[94] = 1/workYaw.d[94];
  workYaw.L[93] = (workYaw.KKT[188])*workYaw.d_inv[94];
  workYaw.v[95] = workYaw.KKT[189];
  workYaw.d[95] = workYaw.v[95];
  if (workYaw.d[95] < 0)
    workYaw.d[95] = settingsYaw.kkt_reg;
  else
    workYaw.d[95] += settingsYaw.kkt_reg;
  workYaw.d_inv[95] = 1/workYaw.d[95];
  workYaw.L[94] = (workYaw.KKT[190])*workYaw.d_inv[95];
  workYaw.v[96] = workYaw.KKT[191];
  workYaw.d[96] = workYaw.v[96];
  if (workYaw.d[96] < 0)
    workYaw.d[96] = settingsYaw.kkt_reg;
  else
    workYaw.d[96] += settingsYaw.kkt_reg;
  workYaw.d_inv[96] = 1/workYaw.d[96];
  workYaw.L[95] = (workYaw.KKT[192])*workYaw.d_inv[96];
  workYaw.v[97] = workYaw.KKT[193];
  workYaw.d[97] = workYaw.v[97];
  if (workYaw.d[97] < 0)
    workYaw.d[97] = settingsYaw.kkt_reg;
  else
    workYaw.d[97] += settingsYaw.kkt_reg;
  workYaw.d_inv[97] = 1/workYaw.d[97];
  workYaw.L[96] = (workYaw.KKT[194])*workYaw.d_inv[97];
  workYaw.v[98] = workYaw.KKT[195];
  workYaw.d[98] = workYaw.v[98];
  if (workYaw.d[98] < 0)
    workYaw.d[98] = settingsYaw.kkt_reg;
  else
    workYaw.d[98] += settingsYaw.kkt_reg;
  workYaw.d_inv[98] = 1/workYaw.d[98];
  workYaw.L[97] = (workYaw.KKT[196])*workYaw.d_inv[98];
  workYaw.v[99] = workYaw.KKT[197];
  workYaw.d[99] = workYaw.v[99];
  if (workYaw.d[99] < 0)
    workYaw.d[99] = settingsYaw.kkt_reg;
  else
    workYaw.d[99] += settingsYaw.kkt_reg;
  workYaw.d_inv[99] = 1/workYaw.d[99];
  workYaw.L[98] = (workYaw.KKT[198])*workYaw.d_inv[99];
  workYaw.v[100] = workYaw.KKT[199];
  workYaw.d[100] = workYaw.v[100];
  if (workYaw.d[100] < 0)
    workYaw.d[100] = settingsYaw.kkt_reg;
  else
    workYaw.d[100] += settingsYaw.kkt_reg;
  workYaw.d_inv[100] = 1/workYaw.d[100];
  workYaw.L[99] = (workYaw.KKT[200])*workYaw.d_inv[100];
  workYaw.v[101] = workYaw.KKT[201];
  workYaw.d[101] = workYaw.v[101];
  if (workYaw.d[101] < 0)
    workYaw.d[101] = settingsYaw.kkt_reg;
  else
    workYaw.d[101] += settingsYaw.kkt_reg;
  workYaw.d_inv[101] = 1/workYaw.d[101];
  workYaw.L[100] = (workYaw.KKT[202])*workYaw.d_inv[101];
  workYaw.v[102] = workYaw.KKT[203];
  workYaw.d[102] = workYaw.v[102];
  if (workYaw.d[102] < 0)
    workYaw.d[102] = settingsYaw.kkt_reg;
  else
    workYaw.d[102] += settingsYaw.kkt_reg;
  workYaw.d_inv[102] = 1/workYaw.d[102];
  workYaw.L[101] = (workYaw.KKT[204])*workYaw.d_inv[102];
  workYaw.v[103] = workYaw.KKT[205];
  workYaw.d[103] = workYaw.v[103];
  if (workYaw.d[103] < 0)
    workYaw.d[103] = settingsYaw.kkt_reg;
  else
    workYaw.d[103] += settingsYaw.kkt_reg;
  workYaw.d_inv[103] = 1/workYaw.d[103];
  workYaw.L[102] = (workYaw.KKT[206])*workYaw.d_inv[103];
  workYaw.v[104] = workYaw.KKT[207];
  workYaw.d[104] = workYaw.v[104];
  if (workYaw.d[104] < 0)
    workYaw.d[104] = settingsYaw.kkt_reg;
  else
    workYaw.d[104] += settingsYaw.kkt_reg;
  workYaw.d_inv[104] = 1/workYaw.d[104];
  workYaw.L[103] = (workYaw.KKT[208])*workYaw.d_inv[104];
  workYaw.v[105] = workYaw.KKT[209];
  workYaw.d[105] = workYaw.v[105];
  if (workYaw.d[105] < 0)
    workYaw.d[105] = settingsYaw.kkt_reg;
  else
    workYaw.d[105] += settingsYaw.kkt_reg;
  workYaw.d_inv[105] = 1/workYaw.d[105];
  workYaw.L[104] = (workYaw.KKT[210])*workYaw.d_inv[105];
  workYaw.v[106] = workYaw.KKT[211];
  workYaw.d[106] = workYaw.v[106];
  if (workYaw.d[106] < 0)
    workYaw.d[106] = settingsYaw.kkt_reg;
  else
    workYaw.d[106] += settingsYaw.kkt_reg;
  workYaw.d_inv[106] = 1/workYaw.d[106];
  workYaw.L[105] = (workYaw.KKT[212])*workYaw.d_inv[106];
  workYaw.v[107] = workYaw.KKT[213];
  workYaw.d[107] = workYaw.v[107];
  if (workYaw.d[107] < 0)
    workYaw.d[107] = settingsYaw.kkt_reg;
  else
    workYaw.d[107] += settingsYaw.kkt_reg;
  workYaw.d_inv[107] = 1/workYaw.d[107];
  workYaw.L[106] = (workYaw.KKT[214])*workYaw.d_inv[107];
  workYaw.v[108] = workYaw.KKT[215];
  workYaw.d[108] = workYaw.v[108];
  if (workYaw.d[108] < 0)
    workYaw.d[108] = settingsYaw.kkt_reg;
  else
    workYaw.d[108] += settingsYaw.kkt_reg;
  workYaw.d_inv[108] = 1/workYaw.d[108];
  workYaw.L[107] = (workYaw.KKT[216])*workYaw.d_inv[108];
  workYaw.v[109] = workYaw.KKT[217];
  workYaw.d[109] = workYaw.v[109];
  if (workYaw.d[109] < 0)
    workYaw.d[109] = settingsYaw.kkt_reg;
  else
    workYaw.d[109] += settingsYaw.kkt_reg;
  workYaw.d_inv[109] = 1/workYaw.d[109];
  workYaw.L[108] = (workYaw.KKT[218])*workYaw.d_inv[109];
  workYaw.v[110] = workYaw.KKT[219];
  workYaw.d[110] = workYaw.v[110];
  if (workYaw.d[110] < 0)
    workYaw.d[110] = settingsYaw.kkt_reg;
  else
    workYaw.d[110] += settingsYaw.kkt_reg;
  workYaw.d_inv[110] = 1/workYaw.d[110];
  workYaw.L[109] = (workYaw.KKT[220])*workYaw.d_inv[110];
  workYaw.v[111] = workYaw.KKT[221];
  workYaw.d[111] = workYaw.v[111];
  if (workYaw.d[111] < 0)
    workYaw.d[111] = settingsYaw.kkt_reg;
  else
    workYaw.d[111] += settingsYaw.kkt_reg;
  workYaw.d_inv[111] = 1/workYaw.d[111];
  workYaw.L[110] = (workYaw.KKT[222])*workYaw.d_inv[111];
  workYaw.v[112] = workYaw.KKT[223];
  workYaw.d[112] = workYaw.v[112];
  if (workYaw.d[112] < 0)
    workYaw.d[112] = settingsYaw.kkt_reg;
  else
    workYaw.d[112] += settingsYaw.kkt_reg;
  workYaw.d_inv[112] = 1/workYaw.d[112];
  workYaw.L[111] = (workYaw.KKT[224])*workYaw.d_inv[112];
  workYaw.v[113] = workYaw.KKT[225];
  workYaw.d[113] = workYaw.v[113];
  if (workYaw.d[113] < 0)
    workYaw.d[113] = settingsYaw.kkt_reg;
  else
    workYaw.d[113] += settingsYaw.kkt_reg;
  workYaw.d_inv[113] = 1/workYaw.d[113];
  workYaw.L[112] = (workYaw.KKT[226])*workYaw.d_inv[113];
  workYaw.v[114] = workYaw.KKT[227];
  workYaw.d[114] = workYaw.v[114];
  if (workYaw.d[114] < 0)
    workYaw.d[114] = settingsYaw.kkt_reg;
  else
    workYaw.d[114] += settingsYaw.kkt_reg;
  workYaw.d_inv[114] = 1/workYaw.d[114];
  workYaw.L[113] = (workYaw.KKT[228])*workYaw.d_inv[114];
  workYaw.v[115] = workYaw.KKT[229];
  workYaw.d[115] = workYaw.v[115];
  if (workYaw.d[115] < 0)
    workYaw.d[115] = settingsYaw.kkt_reg;
  else
    workYaw.d[115] += settingsYaw.kkt_reg;
  workYaw.d_inv[115] = 1/workYaw.d[115];
  workYaw.L[114] = (workYaw.KKT[230])*workYaw.d_inv[115];
  workYaw.v[116] = workYaw.KKT[231];
  workYaw.d[116] = workYaw.v[116];
  if (workYaw.d[116] < 0)
    workYaw.d[116] = settingsYaw.kkt_reg;
  else
    workYaw.d[116] += settingsYaw.kkt_reg;
  workYaw.d_inv[116] = 1/workYaw.d[116];
  workYaw.L[115] = (workYaw.KKT[232])*workYaw.d_inv[116];
  workYaw.v[117] = workYaw.KKT[233];
  workYaw.d[117] = workYaw.v[117];
  if (workYaw.d[117] < 0)
    workYaw.d[117] = settingsYaw.kkt_reg;
  else
    workYaw.d[117] += settingsYaw.kkt_reg;
  workYaw.d_inv[117] = 1/workYaw.d[117];
  workYaw.L[116] = (workYaw.KKT[234])*workYaw.d_inv[117];
  workYaw.v[118] = workYaw.KKT[235];
  workYaw.d[118] = workYaw.v[118];
  if (workYaw.d[118] < 0)
    workYaw.d[118] = settingsYaw.kkt_reg;
  else
    workYaw.d[118] += settingsYaw.kkt_reg;
  workYaw.d_inv[118] = 1/workYaw.d[118];
  workYaw.L[117] = (workYaw.KKT[236])*workYaw.d_inv[118];
  workYaw.v[119] = workYaw.KKT[237];
  workYaw.d[119] = workYaw.v[119];
  if (workYaw.d[119] < 0)
    workYaw.d[119] = settingsYaw.kkt_reg;
  else
    workYaw.d[119] += settingsYaw.kkt_reg;
  workYaw.d_inv[119] = 1/workYaw.d[119];
  workYaw.L[118] = (workYaw.KKT[238])*workYaw.d_inv[119];
  workYaw.v[120] = workYaw.KKT[239];
  workYaw.d[120] = workYaw.v[120];
  if (workYaw.d[120] < 0)
    workYaw.d[120] = settingsYaw.kkt_reg;
  else
    workYaw.d[120] += settingsYaw.kkt_reg;
  workYaw.d_inv[120] = 1/workYaw.d[120];
  workYaw.L[119] = (workYaw.KKT[240])*workYaw.d_inv[120];
  workYaw.v[121] = workYaw.KKT[241];
  workYaw.d[121] = workYaw.v[121];
  if (workYaw.d[121] < 0)
    workYaw.d[121] = settingsYaw.kkt_reg;
  else
    workYaw.d[121] += settingsYaw.kkt_reg;
  workYaw.d_inv[121] = 1/workYaw.d[121];
  workYaw.L[120] = (workYaw.KKT[242])*workYaw.d_inv[121];
  workYaw.v[122] = workYaw.KKT[243];
  workYaw.d[122] = workYaw.v[122];
  if (workYaw.d[122] < 0)
    workYaw.d[122] = settingsYaw.kkt_reg;
  else
    workYaw.d[122] += settingsYaw.kkt_reg;
  workYaw.d_inv[122] = 1/workYaw.d[122];
  workYaw.L[121] = (workYaw.KKT[244])*workYaw.d_inv[122];
  workYaw.v[123] = workYaw.KKT[245];
  workYaw.d[123] = workYaw.v[123];
  if (workYaw.d[123] < 0)
    workYaw.d[123] = settingsYaw.kkt_reg;
  else
    workYaw.d[123] += settingsYaw.kkt_reg;
  workYaw.d_inv[123] = 1/workYaw.d[123];
  workYaw.L[122] = (workYaw.KKT[246])*workYaw.d_inv[123];
  workYaw.v[124] = workYaw.KKT[247];
  workYaw.d[124] = workYaw.v[124];
  if (workYaw.d[124] < 0)
    workYaw.d[124] = settingsYaw.kkt_reg;
  else
    workYaw.d[124] += settingsYaw.kkt_reg;
  workYaw.d_inv[124] = 1/workYaw.d[124];
  workYaw.L[123] = (workYaw.KKT[248])*workYaw.d_inv[124];
  workYaw.v[125] = workYaw.KKT[249];
  workYaw.d[125] = workYaw.v[125];
  if (workYaw.d[125] < 0)
    workYaw.d[125] = settingsYaw.kkt_reg;
  else
    workYaw.d[125] += settingsYaw.kkt_reg;
  workYaw.d_inv[125] = 1/workYaw.d[125];
  workYaw.L[124] = (workYaw.KKT[250])*workYaw.d_inv[125];
  workYaw.v[126] = workYaw.KKT[251];
  workYaw.d[126] = workYaw.v[126];
  if (workYaw.d[126] < 0)
    workYaw.d[126] = settingsYaw.kkt_reg;
  else
    workYaw.d[126] += settingsYaw.kkt_reg;
  workYaw.d_inv[126] = 1/workYaw.d[126];
  workYaw.L[125] = (workYaw.KKT[252])*workYaw.d_inv[126];
  workYaw.v[127] = workYaw.KKT[253];
  workYaw.d[127] = workYaw.v[127];
  if (workYaw.d[127] < 0)
    workYaw.d[127] = settingsYaw.kkt_reg;
  else
    workYaw.d[127] += settingsYaw.kkt_reg;
  workYaw.d_inv[127] = 1/workYaw.d[127];
  workYaw.L[126] = (workYaw.KKT[254])*workYaw.d_inv[127];
  workYaw.v[128] = workYaw.KKT[255];
  workYaw.d[128] = workYaw.v[128];
  if (workYaw.d[128] < 0)
    workYaw.d[128] = settingsYaw.kkt_reg;
  else
    workYaw.d[128] += settingsYaw.kkt_reg;
  workYaw.d_inv[128] = 1/workYaw.d[128];
  workYaw.L[127] = (workYaw.KKT[256])*workYaw.d_inv[128];
  workYaw.v[129] = workYaw.KKT[257];
  workYaw.d[129] = workYaw.v[129];
  if (workYaw.d[129] < 0)
    workYaw.d[129] = settingsYaw.kkt_reg;
  else
    workYaw.d[129] += settingsYaw.kkt_reg;
  workYaw.d_inv[129] = 1/workYaw.d[129];
  workYaw.L[128] = (workYaw.KKT[258])*workYaw.d_inv[129];
  workYaw.v[130] = workYaw.KKT[259];
  workYaw.d[130] = workYaw.v[130];
  if (workYaw.d[130] < 0)
    workYaw.d[130] = settingsYaw.kkt_reg;
  else
    workYaw.d[130] += settingsYaw.kkt_reg;
  workYaw.d_inv[130] = 1/workYaw.d[130];
  workYaw.L[129] = (workYaw.KKT[260])*workYaw.d_inv[130];
  workYaw.v[131] = workYaw.KKT[261];
  workYaw.d[131] = workYaw.v[131];
  if (workYaw.d[131] < 0)
    workYaw.d[131] = settingsYaw.kkt_reg;
  else
    workYaw.d[131] += settingsYaw.kkt_reg;
  workYaw.d_inv[131] = 1/workYaw.d[131];
  workYaw.L[130] = (workYaw.KKT[262])*workYaw.d_inv[131];
  workYaw.v[132] = workYaw.KKT[263];
  workYaw.d[132] = workYaw.v[132];
  if (workYaw.d[132] < 0)
    workYaw.d[132] = settingsYaw.kkt_reg;
  else
    workYaw.d[132] += settingsYaw.kkt_reg;
  workYaw.d_inv[132] = 1/workYaw.d[132];
  workYaw.L[131] = (workYaw.KKT[264])*workYaw.d_inv[132];
  workYaw.v[133] = workYaw.KKT[265];
  workYaw.d[133] = workYaw.v[133];
  if (workYaw.d[133] < 0)
    workYaw.d[133] = settingsYaw.kkt_reg;
  else
    workYaw.d[133] += settingsYaw.kkt_reg;
  workYaw.d_inv[133] = 1/workYaw.d[133];
  workYaw.L[132] = (workYaw.KKT[266])*workYaw.d_inv[133];
  workYaw.v[134] = workYaw.KKT[267];
  workYaw.d[134] = workYaw.v[134];
  if (workYaw.d[134] < 0)
    workYaw.d[134] = settingsYaw.kkt_reg;
  else
    workYaw.d[134] += settingsYaw.kkt_reg;
  workYaw.d_inv[134] = 1/workYaw.d[134];
  workYaw.L[133] = (workYaw.KKT[268])*workYaw.d_inv[134];
  workYaw.v[135] = workYaw.KKT[269];
  workYaw.d[135] = workYaw.v[135];
  if (workYaw.d[135] < 0)
    workYaw.d[135] = settingsYaw.kkt_reg;
  else
    workYaw.d[135] += settingsYaw.kkt_reg;
  workYaw.d_inv[135] = 1/workYaw.d[135];
  workYaw.L[134] = (workYaw.KKT[270])*workYaw.d_inv[135];
  workYaw.v[136] = workYaw.KKT[271];
  workYaw.d[136] = workYaw.v[136];
  if (workYaw.d[136] < 0)
    workYaw.d[136] = settingsYaw.kkt_reg;
  else
    workYaw.d[136] += settingsYaw.kkt_reg;
  workYaw.d_inv[136] = 1/workYaw.d[136];
  workYaw.L[135] = (workYaw.KKT[272])*workYaw.d_inv[136];
  workYaw.v[137] = workYaw.KKT[273];
  workYaw.d[137] = workYaw.v[137];
  if (workYaw.d[137] < 0)
    workYaw.d[137] = settingsYaw.kkt_reg;
  else
    workYaw.d[137] += settingsYaw.kkt_reg;
  workYaw.d_inv[137] = 1/workYaw.d[137];
  workYaw.L[136] = (workYaw.KKT[274])*workYaw.d_inv[137];
  workYaw.v[138] = workYaw.KKT[275];
  workYaw.d[138] = workYaw.v[138];
  if (workYaw.d[138] < 0)
    workYaw.d[138] = settingsYaw.kkt_reg;
  else
    workYaw.d[138] += settingsYaw.kkt_reg;
  workYaw.d_inv[138] = 1/workYaw.d[138];
  workYaw.L[137] = (workYaw.KKT[276])*workYaw.d_inv[138];
  workYaw.v[139] = workYaw.KKT[277];
  workYaw.d[139] = workYaw.v[139];
  if (workYaw.d[139] < 0)
    workYaw.d[139] = settingsYaw.kkt_reg;
  else
    workYaw.d[139] += settingsYaw.kkt_reg;
  workYaw.d_inv[139] = 1/workYaw.d[139];
  workYaw.L[138] = (workYaw.KKT[278])*workYaw.d_inv[139];
  workYaw.v[140] = workYaw.KKT[279];
  workYaw.d[140] = workYaw.v[140];
  if (workYaw.d[140] < 0)
    workYaw.d[140] = settingsYaw.kkt_reg;
  else
    workYaw.d[140] += settingsYaw.kkt_reg;
  workYaw.d_inv[140] = 1/workYaw.d[140];
  workYaw.L[139] = (workYaw.KKT[280])*workYaw.d_inv[140];
  workYaw.v[141] = workYaw.KKT[281];
  workYaw.d[141] = workYaw.v[141];
  if (workYaw.d[141] < 0)
    workYaw.d[141] = settingsYaw.kkt_reg;
  else
    workYaw.d[141] += settingsYaw.kkt_reg;
  workYaw.d_inv[141] = 1/workYaw.d[141];
  workYaw.L[140] = (workYaw.KKT[282])*workYaw.d_inv[141];
  workYaw.v[142] = workYaw.KKT[283];
  workYaw.d[142] = workYaw.v[142];
  if (workYaw.d[142] < 0)
    workYaw.d[142] = settingsYaw.kkt_reg;
  else
    workYaw.d[142] += settingsYaw.kkt_reg;
  workYaw.d_inv[142] = 1/workYaw.d[142];
  workYaw.L[141] = (workYaw.KKT[284])*workYaw.d_inv[142];
  workYaw.v[143] = workYaw.KKT[285];
  workYaw.d[143] = workYaw.v[143];
  if (workYaw.d[143] < 0)
    workYaw.d[143] = settingsYaw.kkt_reg;
  else
    workYaw.d[143] += settingsYaw.kkt_reg;
  workYaw.d_inv[143] = 1/workYaw.d[143];
  workYaw.L[142] = (workYaw.KKT[286])*workYaw.d_inv[143];
  workYaw.v[144] = workYaw.KKT[287];
  workYaw.d[144] = workYaw.v[144];
  if (workYaw.d[144] < 0)
    workYaw.d[144] = settingsYaw.kkt_reg;
  else
    workYaw.d[144] += settingsYaw.kkt_reg;
  workYaw.d_inv[144] = 1/workYaw.d[144];
  workYaw.L[143] = (workYaw.KKT[288])*workYaw.d_inv[144];
  workYaw.v[145] = workYaw.KKT[289];
  workYaw.d[145] = workYaw.v[145];
  if (workYaw.d[145] < 0)
    workYaw.d[145] = settingsYaw.kkt_reg;
  else
    workYaw.d[145] += settingsYaw.kkt_reg;
  workYaw.d_inv[145] = 1/workYaw.d[145];
  workYaw.L[144] = (workYaw.KKT[290])*workYaw.d_inv[145];
  workYaw.v[146] = workYaw.KKT[291];
  workYaw.d[146] = workYaw.v[146];
  if (workYaw.d[146] < 0)
    workYaw.d[146] = settingsYaw.kkt_reg;
  else
    workYaw.d[146] += settingsYaw.kkt_reg;
  workYaw.d_inv[146] = 1/workYaw.d[146];
  workYaw.L[145] = (workYaw.KKT[292])*workYaw.d_inv[146];
  workYaw.v[147] = workYaw.KKT[293];
  workYaw.d[147] = workYaw.v[147];
  if (workYaw.d[147] < 0)
    workYaw.d[147] = settingsYaw.kkt_reg;
  else
    workYaw.d[147] += settingsYaw.kkt_reg;
  workYaw.d_inv[147] = 1/workYaw.d[147];
  workYaw.L[146] = (workYaw.KKT[294])*workYaw.d_inv[147];
  workYaw.v[148] = workYaw.KKT[295];
  workYaw.d[148] = workYaw.v[148];
  if (workYaw.d[148] < 0)
    workYaw.d[148] = settingsYaw.kkt_reg;
  else
    workYaw.d[148] += settingsYaw.kkt_reg;
  workYaw.d_inv[148] = 1/workYaw.d[148];
  workYaw.L[147] = (workYaw.KKT[296])*workYaw.d_inv[148];
  workYaw.v[149] = workYaw.KKT[297];
  workYaw.d[149] = workYaw.v[149];
  if (workYaw.d[149] < 0)
    workYaw.d[149] = settingsYaw.kkt_reg;
  else
    workYaw.d[149] += settingsYaw.kkt_reg;
  workYaw.d_inv[149] = 1/workYaw.d[149];
  workYaw.L[148] = (workYaw.KKT[298])*workYaw.d_inv[149];
  workYaw.v[150] = workYaw.KKT[299];
  workYaw.d[150] = workYaw.v[150];
  if (workYaw.d[150] < 0)
    workYaw.d[150] = settingsYaw.kkt_reg;
  else
    workYaw.d[150] += settingsYaw.kkt_reg;
  workYaw.d_inv[150] = 1/workYaw.d[150];
  workYaw.L[149] = (workYaw.KKT[300])*workYaw.d_inv[150];
  workYaw.v[151] = workYaw.KKT[301];
  workYaw.d[151] = workYaw.v[151];
  if (workYaw.d[151] < 0)
    workYaw.d[151] = settingsYaw.kkt_reg;
  else
    workYaw.d[151] += settingsYaw.kkt_reg;
  workYaw.d_inv[151] = 1/workYaw.d[151];
  workYaw.L[150] = (workYaw.KKT[302])*workYaw.d_inv[151];
  workYaw.v[152] = workYaw.KKT[303];
  workYaw.d[152] = workYaw.v[152];
  if (workYaw.d[152] < 0)
    workYaw.d[152] = settingsYaw.kkt_reg;
  else
    workYaw.d[152] += settingsYaw.kkt_reg;
  workYaw.d_inv[152] = 1/workYaw.d[152];
  workYaw.L[151] = (workYaw.KKT[304])*workYaw.d_inv[152];
  workYaw.v[153] = workYaw.KKT[305];
  workYaw.d[153] = workYaw.v[153];
  if (workYaw.d[153] < 0)
    workYaw.d[153] = settingsYaw.kkt_reg;
  else
    workYaw.d[153] += settingsYaw.kkt_reg;
  workYaw.d_inv[153] = 1/workYaw.d[153];
  workYaw.L[152] = (workYaw.KKT[306])*workYaw.d_inv[153];
  workYaw.v[154] = workYaw.KKT[307];
  workYaw.d[154] = workYaw.v[154];
  if (workYaw.d[154] < 0)
    workYaw.d[154] = settingsYaw.kkt_reg;
  else
    workYaw.d[154] += settingsYaw.kkt_reg;
  workYaw.d_inv[154] = 1/workYaw.d[154];
  workYaw.L[153] = (workYaw.KKT[308])*workYaw.d_inv[154];
  workYaw.v[155] = workYaw.KKT[309];
  workYaw.d[155] = workYaw.v[155];
  if (workYaw.d[155] < 0)
    workYaw.d[155] = settingsYaw.kkt_reg;
  else
    workYaw.d[155] += settingsYaw.kkt_reg;
  workYaw.d_inv[155] = 1/workYaw.d[155];
  workYaw.L[154] = (workYaw.KKT[310])*workYaw.d_inv[155];
  workYaw.v[156] = workYaw.KKT[311];
  workYaw.d[156] = workYaw.v[156];
  if (workYaw.d[156] < 0)
    workYaw.d[156] = settingsYaw.kkt_reg;
  else
    workYaw.d[156] += settingsYaw.kkt_reg;
  workYaw.d_inv[156] = 1/workYaw.d[156];
  workYaw.L[155] = (workYaw.KKT[312])*workYaw.d_inv[156];
  workYaw.v[157] = workYaw.KKT[313];
  workYaw.d[157] = workYaw.v[157];
  if (workYaw.d[157] < 0)
    workYaw.d[157] = settingsYaw.kkt_reg;
  else
    workYaw.d[157] += settingsYaw.kkt_reg;
  workYaw.d_inv[157] = 1/workYaw.d[157];
  workYaw.L[156] = (workYaw.KKT[314])*workYaw.d_inv[157];
  workYaw.v[158] = workYaw.KKT[315];
  workYaw.d[158] = workYaw.v[158];
  if (workYaw.d[158] < 0)
    workYaw.d[158] = settingsYaw.kkt_reg;
  else
    workYaw.d[158] += settingsYaw.kkt_reg;
  workYaw.d_inv[158] = 1/workYaw.d[158];
  workYaw.L[157] = (workYaw.KKT[316])*workYaw.d_inv[158];
  workYaw.v[159] = workYaw.KKT[317];
  workYaw.d[159] = workYaw.v[159];
  if (workYaw.d[159] < 0)
    workYaw.d[159] = settingsYaw.kkt_reg;
  else
    workYaw.d[159] += settingsYaw.kkt_reg;
  workYaw.d_inv[159] = 1/workYaw.d[159];
  workYaw.L[158] = (workYaw.KKT[318])*workYaw.d_inv[159];
  workYaw.v[160] = workYaw.KKT[319];
  workYaw.d[160] = workYaw.v[160];
  if (workYaw.d[160] < 0)
    workYaw.d[160] = settingsYaw.kkt_reg;
  else
    workYaw.d[160] += settingsYaw.kkt_reg;
  workYaw.d_inv[160] = 1/workYaw.d[160];
  workYaw.L[159] = (workYaw.KKT[320])*workYaw.d_inv[160];
  workYaw.v[1] = workYaw.L[0]*workYaw.d[1];
  workYaw.v[161] = workYaw.KKT[321]-workYaw.L[0]*workYaw.v[1];
  workYaw.d[161] = workYaw.v[161];
  if (workYaw.d[161] > 0)
    workYaw.d[161] = -settingsYaw.kkt_reg;
  else
    workYaw.d[161] -= settingsYaw.kkt_reg;
  workYaw.d_inv[161] = 1/workYaw.d[161];
  workYaw.L[215] = (workYaw.KKT[322])*workYaw.d_inv[161];
  workYaw.v[2] = workYaw.L[1]*workYaw.d[2];
  workYaw.v[162] = workYaw.KKT[323]-workYaw.L[1]*workYaw.v[2];
  workYaw.d[162] = workYaw.v[162];
  if (workYaw.d[162] > 0)
    workYaw.d[162] = -settingsYaw.kkt_reg;
  else
    workYaw.d[162] -= settingsYaw.kkt_reg;
  workYaw.d_inv[162] = 1/workYaw.d[162];
  workYaw.L[229] = (workYaw.KKT[324])*workYaw.d_inv[162];
  workYaw.v[3] = workYaw.L[2]*workYaw.d[3];
  workYaw.v[163] = workYaw.KKT[325]-workYaw.L[2]*workYaw.v[3];
  workYaw.d[163] = workYaw.v[163];
  if (workYaw.d[163] > 0)
    workYaw.d[163] = -settingsYaw.kkt_reg;
  else
    workYaw.d[163] -= settingsYaw.kkt_reg;
  workYaw.d_inv[163] = 1/workYaw.d[163];
  workYaw.L[247] = (workYaw.KKT[326])*workYaw.d_inv[163];
  workYaw.v[4] = workYaw.L[3]*workYaw.d[4];
  workYaw.v[164] = workYaw.KKT[327]-workYaw.L[3]*workYaw.v[4];
  workYaw.d[164] = workYaw.v[164];
  if (workYaw.d[164] > 0)
    workYaw.d[164] = -settingsYaw.kkt_reg;
  else
    workYaw.d[164] -= settingsYaw.kkt_reg;
  workYaw.d_inv[164] = 1/workYaw.d[164];
  workYaw.L[267] = (workYaw.KKT[328])*workYaw.d_inv[164];
  workYaw.v[5] = workYaw.L[4]*workYaw.d[5];
  workYaw.v[165] = workYaw.KKT[329]-workYaw.L[4]*workYaw.v[5];
  workYaw.d[165] = workYaw.v[165];
  if (workYaw.d[165] > 0)
    workYaw.d[165] = -settingsYaw.kkt_reg;
  else
    workYaw.d[165] -= settingsYaw.kkt_reg;
  workYaw.d_inv[165] = 1/workYaw.d[165];
  workYaw.L[287] = (workYaw.KKT[330])*workYaw.d_inv[165];
  workYaw.v[6] = workYaw.L[5]*workYaw.d[6];
  workYaw.v[166] = workYaw.KKT[331]-workYaw.L[5]*workYaw.v[6];
  workYaw.d[166] = workYaw.v[166];
  if (workYaw.d[166] > 0)
    workYaw.d[166] = -settingsYaw.kkt_reg;
  else
    workYaw.d[166] -= settingsYaw.kkt_reg;
  workYaw.d_inv[166] = 1/workYaw.d[166];
  workYaw.L[307] = (workYaw.KKT[332])*workYaw.d_inv[166];
  workYaw.v[7] = workYaw.L[6]*workYaw.d[7];
  workYaw.v[167] = workYaw.KKT[333]-workYaw.L[6]*workYaw.v[7];
  workYaw.d[167] = workYaw.v[167];
  if (workYaw.d[167] > 0)
    workYaw.d[167] = -settingsYaw.kkt_reg;
  else
    workYaw.d[167] -= settingsYaw.kkt_reg;
  workYaw.d_inv[167] = 1/workYaw.d[167];
  workYaw.L[327] = (workYaw.KKT[334])*workYaw.d_inv[167];
  workYaw.v[8] = workYaw.L[7]*workYaw.d[8];
  workYaw.v[168] = workYaw.KKT[335]-workYaw.L[7]*workYaw.v[8];
  workYaw.d[168] = workYaw.v[168];
  if (workYaw.d[168] > 0)
    workYaw.d[168] = -settingsYaw.kkt_reg;
  else
    workYaw.d[168] -= settingsYaw.kkt_reg;
  workYaw.d_inv[168] = 1/workYaw.d[168];
  workYaw.L[347] = (workYaw.KKT[336])*workYaw.d_inv[168];
  workYaw.v[9] = workYaw.L[8]*workYaw.d[9];
  workYaw.v[169] = workYaw.KKT[337]-workYaw.L[8]*workYaw.v[9];
  workYaw.d[169] = workYaw.v[169];
  if (workYaw.d[169] > 0)
    workYaw.d[169] = -settingsYaw.kkt_reg;
  else
    workYaw.d[169] -= settingsYaw.kkt_reg;
  workYaw.d_inv[169] = 1/workYaw.d[169];
  workYaw.L[367] = (workYaw.KKT[338])*workYaw.d_inv[169];
  workYaw.v[10] = workYaw.L[9]*workYaw.d[10];
  workYaw.v[170] = workYaw.KKT[339]-workYaw.L[9]*workYaw.v[10];
  workYaw.d[170] = workYaw.v[170];
  if (workYaw.d[170] > 0)
    workYaw.d[170] = -settingsYaw.kkt_reg;
  else
    workYaw.d[170] -= settingsYaw.kkt_reg;
  workYaw.d_inv[170] = 1/workYaw.d[170];
  workYaw.L[387] = (workYaw.KKT[340])*workYaw.d_inv[170];
  workYaw.v[11] = workYaw.L[10]*workYaw.d[11];
  workYaw.v[171] = workYaw.KKT[341]-workYaw.L[10]*workYaw.v[11];
  workYaw.d[171] = workYaw.v[171];
  if (workYaw.d[171] > 0)
    workYaw.d[171] = -settingsYaw.kkt_reg;
  else
    workYaw.d[171] -= settingsYaw.kkt_reg;
  workYaw.d_inv[171] = 1/workYaw.d[171];
  workYaw.L[407] = (workYaw.KKT[342])*workYaw.d_inv[171];
  workYaw.v[12] = workYaw.L[11]*workYaw.d[12];
  workYaw.v[172] = workYaw.KKT[343]-workYaw.L[11]*workYaw.v[12];
  workYaw.d[172] = workYaw.v[172];
  if (workYaw.d[172] > 0)
    workYaw.d[172] = -settingsYaw.kkt_reg;
  else
    workYaw.d[172] -= settingsYaw.kkt_reg;
  workYaw.d_inv[172] = 1/workYaw.d[172];
  workYaw.L[427] = (workYaw.KKT[344])*workYaw.d_inv[172];
  workYaw.v[13] = workYaw.L[12]*workYaw.d[13];
  workYaw.v[173] = workYaw.KKT[345]-workYaw.L[12]*workYaw.v[13];
  workYaw.d[173] = workYaw.v[173];
  if (workYaw.d[173] > 0)
    workYaw.d[173] = -settingsYaw.kkt_reg;
  else
    workYaw.d[173] -= settingsYaw.kkt_reg;
  workYaw.d_inv[173] = 1/workYaw.d[173];
  workYaw.L[447] = (workYaw.KKT[346])*workYaw.d_inv[173];
  workYaw.v[14] = workYaw.L[13]*workYaw.d[14];
  workYaw.v[174] = workYaw.KKT[347]-workYaw.L[13]*workYaw.v[14];
  workYaw.d[174] = workYaw.v[174];
  if (workYaw.d[174] > 0)
    workYaw.d[174] = -settingsYaw.kkt_reg;
  else
    workYaw.d[174] -= settingsYaw.kkt_reg;
  workYaw.d_inv[174] = 1/workYaw.d[174];
  workYaw.L[467] = (workYaw.KKT[348])*workYaw.d_inv[174];
  workYaw.v[15] = workYaw.L[14]*workYaw.d[15];
  workYaw.v[175] = workYaw.KKT[349]-workYaw.L[14]*workYaw.v[15];
  workYaw.d[175] = workYaw.v[175];
  if (workYaw.d[175] > 0)
    workYaw.d[175] = -settingsYaw.kkt_reg;
  else
    workYaw.d[175] -= settingsYaw.kkt_reg;
  workYaw.d_inv[175] = 1/workYaw.d[175];
  workYaw.L[487] = (workYaw.KKT[350])*workYaw.d_inv[175];
  workYaw.v[16] = workYaw.L[15]*workYaw.d[16];
  workYaw.v[176] = workYaw.KKT[351]-workYaw.L[15]*workYaw.v[16];
  workYaw.d[176] = workYaw.v[176];
  if (workYaw.d[176] > 0)
    workYaw.d[176] = -settingsYaw.kkt_reg;
  else
    workYaw.d[176] -= settingsYaw.kkt_reg;
  workYaw.d_inv[176] = 1/workYaw.d[176];
  workYaw.L[507] = (workYaw.KKT[352])*workYaw.d_inv[176];
  workYaw.v[17] = workYaw.L[16]*workYaw.d[17];
  workYaw.v[177] = workYaw.KKT[353]-workYaw.L[16]*workYaw.v[17];
  workYaw.d[177] = workYaw.v[177];
  if (workYaw.d[177] > 0)
    workYaw.d[177] = -settingsYaw.kkt_reg;
  else
    workYaw.d[177] -= settingsYaw.kkt_reg;
  workYaw.d_inv[177] = 1/workYaw.d[177];
  workYaw.L[527] = (workYaw.KKT[354])*workYaw.d_inv[177];
  workYaw.v[18] = workYaw.L[17]*workYaw.d[18];
  workYaw.v[178] = workYaw.KKT[355]-workYaw.L[17]*workYaw.v[18];
  workYaw.d[178] = workYaw.v[178];
  if (workYaw.d[178] > 0)
    workYaw.d[178] = -settingsYaw.kkt_reg;
  else
    workYaw.d[178] -= settingsYaw.kkt_reg;
  workYaw.d_inv[178] = 1/workYaw.d[178];
  workYaw.L[547] = (workYaw.KKT[356])*workYaw.d_inv[178];
  workYaw.v[19] = workYaw.L[18]*workYaw.d[19];
  workYaw.v[179] = workYaw.KKT[357]-workYaw.L[18]*workYaw.v[19];
  workYaw.d[179] = workYaw.v[179];
  if (workYaw.d[179] > 0)
    workYaw.d[179] = -settingsYaw.kkt_reg;
  else
    workYaw.d[179] -= settingsYaw.kkt_reg;
  workYaw.d_inv[179] = 1/workYaw.d[179];
  workYaw.L[567] = (workYaw.KKT[358])*workYaw.d_inv[179];
  workYaw.v[20] = workYaw.L[19]*workYaw.d[20];
  workYaw.v[180] = workYaw.KKT[359]-workYaw.L[19]*workYaw.v[20];
  workYaw.d[180] = workYaw.v[180];
  if (workYaw.d[180] > 0)
    workYaw.d[180] = -settingsYaw.kkt_reg;
  else
    workYaw.d[180] -= settingsYaw.kkt_reg;
  workYaw.d_inv[180] = 1/workYaw.d[180];
  workYaw.L[587] = (workYaw.KKT[360])*workYaw.d_inv[180];
  workYaw.v[21] = workYaw.L[20]*workYaw.d[21];
  workYaw.v[181] = workYaw.KKT[361]-workYaw.L[20]*workYaw.v[21];
  workYaw.d[181] = workYaw.v[181];
  if (workYaw.d[181] > 0)
    workYaw.d[181] = -settingsYaw.kkt_reg;
  else
    workYaw.d[181] -= settingsYaw.kkt_reg;
  workYaw.d_inv[181] = 1/workYaw.d[181];
  workYaw.L[607] = (workYaw.KKT[362])*workYaw.d_inv[181];
  workYaw.v[22] = workYaw.L[21]*workYaw.d[22];
  workYaw.v[182] = workYaw.KKT[363]-workYaw.L[21]*workYaw.v[22];
  workYaw.d[182] = workYaw.v[182];
  if (workYaw.d[182] > 0)
    workYaw.d[182] = -settingsYaw.kkt_reg;
  else
    workYaw.d[182] -= settingsYaw.kkt_reg;
  workYaw.d_inv[182] = 1/workYaw.d[182];
  workYaw.L[627] = (workYaw.KKT[364])*workYaw.d_inv[182];
  workYaw.v[23] = workYaw.L[22]*workYaw.d[23];
  workYaw.v[183] = workYaw.KKT[365]-workYaw.L[22]*workYaw.v[23];
  workYaw.d[183] = workYaw.v[183];
  if (workYaw.d[183] > 0)
    workYaw.d[183] = -settingsYaw.kkt_reg;
  else
    workYaw.d[183] -= settingsYaw.kkt_reg;
  workYaw.d_inv[183] = 1/workYaw.d[183];
  workYaw.L[647] = (workYaw.KKT[366])*workYaw.d_inv[183];
  workYaw.v[24] = workYaw.L[23]*workYaw.d[24];
  workYaw.v[184] = workYaw.KKT[367]-workYaw.L[23]*workYaw.v[24];
  workYaw.d[184] = workYaw.v[184];
  if (workYaw.d[184] > 0)
    workYaw.d[184] = -settingsYaw.kkt_reg;
  else
    workYaw.d[184] -= settingsYaw.kkt_reg;
  workYaw.d_inv[184] = 1/workYaw.d[184];
  workYaw.L[667] = (workYaw.KKT[368])*workYaw.d_inv[184];
  workYaw.v[25] = workYaw.L[24]*workYaw.d[25];
  workYaw.v[185] = workYaw.KKT[369]-workYaw.L[24]*workYaw.v[25];
  workYaw.d[185] = workYaw.v[185];
  if (workYaw.d[185] > 0)
    workYaw.d[185] = -settingsYaw.kkt_reg;
  else
    workYaw.d[185] -= settingsYaw.kkt_reg;
  workYaw.d_inv[185] = 1/workYaw.d[185];
  workYaw.L[687] = (workYaw.KKT[370])*workYaw.d_inv[185];
  workYaw.v[26] = workYaw.L[25]*workYaw.d[26];
  workYaw.v[186] = workYaw.KKT[371]-workYaw.L[25]*workYaw.v[26];
  workYaw.d[186] = workYaw.v[186];
  if (workYaw.d[186] > 0)
    workYaw.d[186] = -settingsYaw.kkt_reg;
  else
    workYaw.d[186] -= settingsYaw.kkt_reg;
  workYaw.d_inv[186] = 1/workYaw.d[186];
  workYaw.L[707] = (workYaw.KKT[372])*workYaw.d_inv[186];
  workYaw.v[27] = workYaw.L[26]*workYaw.d[27];
  workYaw.v[187] = workYaw.KKT[373]-workYaw.L[26]*workYaw.v[27];
  workYaw.d[187] = workYaw.v[187];
  if (workYaw.d[187] > 0)
    workYaw.d[187] = -settingsYaw.kkt_reg;
  else
    workYaw.d[187] -= settingsYaw.kkt_reg;
  workYaw.d_inv[187] = 1/workYaw.d[187];
  workYaw.L[727] = (workYaw.KKT[374])*workYaw.d_inv[187];
  workYaw.v[28] = workYaw.L[27]*workYaw.d[28];
  workYaw.v[188] = workYaw.KKT[375]-workYaw.L[27]*workYaw.v[28];
  workYaw.d[188] = workYaw.v[188];
  if (workYaw.d[188] > 0)
    workYaw.d[188] = -settingsYaw.kkt_reg;
  else
    workYaw.d[188] -= settingsYaw.kkt_reg;
  workYaw.d_inv[188] = 1/workYaw.d[188];
  workYaw.L[747] = (workYaw.KKT[376])*workYaw.d_inv[188];
  workYaw.v[29] = workYaw.L[28]*workYaw.d[29];
  workYaw.v[189] = workYaw.KKT[377]-workYaw.L[28]*workYaw.v[29];
  workYaw.d[189] = workYaw.v[189];
  if (workYaw.d[189] > 0)
    workYaw.d[189] = -settingsYaw.kkt_reg;
  else
    workYaw.d[189] -= settingsYaw.kkt_reg;
  workYaw.d_inv[189] = 1/workYaw.d[189];
  workYaw.L[767] = (workYaw.KKT[378])*workYaw.d_inv[189];
  workYaw.v[30] = workYaw.L[29]*workYaw.d[30];
  workYaw.v[190] = workYaw.KKT[379]-workYaw.L[29]*workYaw.v[30];
  workYaw.d[190] = workYaw.v[190];
  if (workYaw.d[190] > 0)
    workYaw.d[190] = -settingsYaw.kkt_reg;
  else
    workYaw.d[190] -= settingsYaw.kkt_reg;
  workYaw.d_inv[190] = 1/workYaw.d[190];
  workYaw.L[787] = (workYaw.KKT[380])*workYaw.d_inv[190];
  workYaw.v[31] = workYaw.L[30]*workYaw.d[31];
  workYaw.v[191] = workYaw.KKT[381]-workYaw.L[30]*workYaw.v[31];
  workYaw.d[191] = workYaw.v[191];
  if (workYaw.d[191] > 0)
    workYaw.d[191] = -settingsYaw.kkt_reg;
  else
    workYaw.d[191] -= settingsYaw.kkt_reg;
  workYaw.d_inv[191] = 1/workYaw.d[191];
  workYaw.L[807] = (workYaw.KKT[382])*workYaw.d_inv[191];
  workYaw.v[32] = workYaw.L[31]*workYaw.d[32];
  workYaw.v[192] = workYaw.KKT[383]-workYaw.L[31]*workYaw.v[32];
  workYaw.d[192] = workYaw.v[192];
  if (workYaw.d[192] > 0)
    workYaw.d[192] = -settingsYaw.kkt_reg;
  else
    workYaw.d[192] -= settingsYaw.kkt_reg;
  workYaw.d_inv[192] = 1/workYaw.d[192];
  workYaw.L[827] = (workYaw.KKT[384])*workYaw.d_inv[192];
  workYaw.v[33] = workYaw.L[32]*workYaw.d[33];
  workYaw.v[193] = workYaw.KKT[385]-workYaw.L[32]*workYaw.v[33];
  workYaw.d[193] = workYaw.v[193];
  if (workYaw.d[193] > 0)
    workYaw.d[193] = -settingsYaw.kkt_reg;
  else
    workYaw.d[193] -= settingsYaw.kkt_reg;
  workYaw.d_inv[193] = 1/workYaw.d[193];
  workYaw.L[847] = (workYaw.KKT[386])*workYaw.d_inv[193];
  workYaw.v[34] = workYaw.L[33]*workYaw.d[34];
  workYaw.v[194] = workYaw.KKT[387]-workYaw.L[33]*workYaw.v[34];
  workYaw.d[194] = workYaw.v[194];
  if (workYaw.d[194] > 0)
    workYaw.d[194] = -settingsYaw.kkt_reg;
  else
    workYaw.d[194] -= settingsYaw.kkt_reg;
  workYaw.d_inv[194] = 1/workYaw.d[194];
  workYaw.L[867] = (workYaw.KKT[388])*workYaw.d_inv[194];
  workYaw.v[35] = workYaw.L[34]*workYaw.d[35];
  workYaw.v[195] = workYaw.KKT[389]-workYaw.L[34]*workYaw.v[35];
  workYaw.d[195] = workYaw.v[195];
  if (workYaw.d[195] > 0)
    workYaw.d[195] = -settingsYaw.kkt_reg;
  else
    workYaw.d[195] -= settingsYaw.kkt_reg;
  workYaw.d_inv[195] = 1/workYaw.d[195];
  workYaw.L[887] = (workYaw.KKT[390])*workYaw.d_inv[195];
  workYaw.v[36] = workYaw.L[35]*workYaw.d[36];
  workYaw.v[196] = workYaw.KKT[391]-workYaw.L[35]*workYaw.v[36];
  workYaw.d[196] = workYaw.v[196];
  if (workYaw.d[196] > 0)
    workYaw.d[196] = -settingsYaw.kkt_reg;
  else
    workYaw.d[196] -= settingsYaw.kkt_reg;
  workYaw.d_inv[196] = 1/workYaw.d[196];
  workYaw.L[907] = (workYaw.KKT[392])*workYaw.d_inv[196];
  workYaw.v[37] = workYaw.L[36]*workYaw.d[37];
  workYaw.v[197] = workYaw.KKT[393]-workYaw.L[36]*workYaw.v[37];
  workYaw.d[197] = workYaw.v[197];
  if (workYaw.d[197] > 0)
    workYaw.d[197] = -settingsYaw.kkt_reg;
  else
    workYaw.d[197] -= settingsYaw.kkt_reg;
  workYaw.d_inv[197] = 1/workYaw.d[197];
  workYaw.L[927] = (workYaw.KKT[394])*workYaw.d_inv[197];
  workYaw.v[38] = workYaw.L[37]*workYaw.d[38];
  workYaw.v[198] = workYaw.KKT[395]-workYaw.L[37]*workYaw.v[38];
  workYaw.d[198] = workYaw.v[198];
  if (workYaw.d[198] > 0)
    workYaw.d[198] = -settingsYaw.kkt_reg;
  else
    workYaw.d[198] -= settingsYaw.kkt_reg;
  workYaw.d_inv[198] = 1/workYaw.d[198];
  workYaw.L[951] = (workYaw.KKT[396])*workYaw.d_inv[198];
  workYaw.v[39] = workYaw.L[38]*workYaw.d[39];
  workYaw.v[199] = workYaw.KKT[397]-workYaw.L[38]*workYaw.v[39];
  workYaw.d[199] = workYaw.v[199];
  if (workYaw.d[199] > 0)
    workYaw.d[199] = -settingsYaw.kkt_reg;
  else
    workYaw.d[199] -= settingsYaw.kkt_reg;
  workYaw.d_inv[199] = 1/workYaw.d[199];
  workYaw.L[967] = (workYaw.KKT[398])*workYaw.d_inv[199];
  workYaw.v[40] = workYaw.L[39]*workYaw.d[40];
  workYaw.v[200] = workYaw.KKT[399]-workYaw.L[39]*workYaw.v[40];
  workYaw.d[200] = workYaw.v[200];
  if (workYaw.d[200] > 0)
    workYaw.d[200] = -settingsYaw.kkt_reg;
  else
    workYaw.d[200] -= settingsYaw.kkt_reg;
  workYaw.d_inv[200] = 1/workYaw.d[200];
  workYaw.L[166] = (workYaw.KKT[400])*workYaw.d_inv[200];
  workYaw.v[41] = workYaw.L[40]*workYaw.d[41];
  workYaw.v[201] = workYaw.KKT[401]-workYaw.L[40]*workYaw.v[41];
  workYaw.d[201] = workYaw.v[201];
  if (workYaw.d[201] > 0)
    workYaw.d[201] = -settingsYaw.kkt_reg;
  else
    workYaw.d[201] -= settingsYaw.kkt_reg;
  workYaw.d_inv[201] = 1/workYaw.d[201];
  workYaw.L[216] = (workYaw.KKT[402])*workYaw.d_inv[201];
  workYaw.v[42] = workYaw.L[41]*workYaw.d[42];
  workYaw.v[202] = workYaw.KKT[403]-workYaw.L[41]*workYaw.v[42];
  workYaw.d[202] = workYaw.v[202];
  if (workYaw.d[202] > 0)
    workYaw.d[202] = -settingsYaw.kkt_reg;
  else
    workYaw.d[202] -= settingsYaw.kkt_reg;
  workYaw.d_inv[202] = 1/workYaw.d[202];
  workYaw.L[230] = (workYaw.KKT[404])*workYaw.d_inv[202];
  workYaw.v[43] = workYaw.L[42]*workYaw.d[43];
  workYaw.v[203] = workYaw.KKT[405]-workYaw.L[42]*workYaw.v[43];
  workYaw.d[203] = workYaw.v[203];
  if (workYaw.d[203] > 0)
    workYaw.d[203] = -settingsYaw.kkt_reg;
  else
    workYaw.d[203] -= settingsYaw.kkt_reg;
  workYaw.d_inv[203] = 1/workYaw.d[203];
  workYaw.L[248] = (workYaw.KKT[406])*workYaw.d_inv[203];
  workYaw.v[44] = workYaw.L[43]*workYaw.d[44];
  workYaw.v[204] = workYaw.KKT[407]-workYaw.L[43]*workYaw.v[44];
  workYaw.d[204] = workYaw.v[204];
  if (workYaw.d[204] > 0)
    workYaw.d[204] = -settingsYaw.kkt_reg;
  else
    workYaw.d[204] -= settingsYaw.kkt_reg;
  workYaw.d_inv[204] = 1/workYaw.d[204];
  workYaw.L[268] = (workYaw.KKT[408])*workYaw.d_inv[204];
  workYaw.v[45] = workYaw.L[44]*workYaw.d[45];
  workYaw.v[205] = workYaw.KKT[409]-workYaw.L[44]*workYaw.v[45];
  workYaw.d[205] = workYaw.v[205];
  if (workYaw.d[205] > 0)
    workYaw.d[205] = -settingsYaw.kkt_reg;
  else
    workYaw.d[205] -= settingsYaw.kkt_reg;
  workYaw.d_inv[205] = 1/workYaw.d[205];
  workYaw.L[288] = (workYaw.KKT[410])*workYaw.d_inv[205];
  workYaw.v[46] = workYaw.L[45]*workYaw.d[46];
  workYaw.v[206] = workYaw.KKT[411]-workYaw.L[45]*workYaw.v[46];
  workYaw.d[206] = workYaw.v[206];
  if (workYaw.d[206] > 0)
    workYaw.d[206] = -settingsYaw.kkt_reg;
  else
    workYaw.d[206] -= settingsYaw.kkt_reg;
  workYaw.d_inv[206] = 1/workYaw.d[206];
  workYaw.L[308] = (workYaw.KKT[412])*workYaw.d_inv[206];
  workYaw.v[47] = workYaw.L[46]*workYaw.d[47];
  workYaw.v[207] = workYaw.KKT[413]-workYaw.L[46]*workYaw.v[47];
  workYaw.d[207] = workYaw.v[207];
  if (workYaw.d[207] > 0)
    workYaw.d[207] = -settingsYaw.kkt_reg;
  else
    workYaw.d[207] -= settingsYaw.kkt_reg;
  workYaw.d_inv[207] = 1/workYaw.d[207];
  workYaw.L[328] = (workYaw.KKT[414])*workYaw.d_inv[207];
  workYaw.v[48] = workYaw.L[47]*workYaw.d[48];
  workYaw.v[208] = workYaw.KKT[415]-workYaw.L[47]*workYaw.v[48];
  workYaw.d[208] = workYaw.v[208];
  if (workYaw.d[208] > 0)
    workYaw.d[208] = -settingsYaw.kkt_reg;
  else
    workYaw.d[208] -= settingsYaw.kkt_reg;
  workYaw.d_inv[208] = 1/workYaw.d[208];
  workYaw.L[348] = (workYaw.KKT[416])*workYaw.d_inv[208];
  workYaw.v[49] = workYaw.L[48]*workYaw.d[49];
  workYaw.v[209] = workYaw.KKT[417]-workYaw.L[48]*workYaw.v[49];
  workYaw.d[209] = workYaw.v[209];
  if (workYaw.d[209] > 0)
    workYaw.d[209] = -settingsYaw.kkt_reg;
  else
    workYaw.d[209] -= settingsYaw.kkt_reg;
  workYaw.d_inv[209] = 1/workYaw.d[209];
  workYaw.L[368] = (workYaw.KKT[418])*workYaw.d_inv[209];
  workYaw.v[50] = workYaw.L[49]*workYaw.d[50];
  workYaw.v[210] = workYaw.KKT[419]-workYaw.L[49]*workYaw.v[50];
  workYaw.d[210] = workYaw.v[210];
  if (workYaw.d[210] > 0)
    workYaw.d[210] = -settingsYaw.kkt_reg;
  else
    workYaw.d[210] -= settingsYaw.kkt_reg;
  workYaw.d_inv[210] = 1/workYaw.d[210];
  workYaw.L[388] = (workYaw.KKT[420])*workYaw.d_inv[210];
  workYaw.v[51] = workYaw.L[50]*workYaw.d[51];
  workYaw.v[211] = workYaw.KKT[421]-workYaw.L[50]*workYaw.v[51];
  workYaw.d[211] = workYaw.v[211];
  if (workYaw.d[211] > 0)
    workYaw.d[211] = -settingsYaw.kkt_reg;
  else
    workYaw.d[211] -= settingsYaw.kkt_reg;
  workYaw.d_inv[211] = 1/workYaw.d[211];
  workYaw.L[408] = (workYaw.KKT[422])*workYaw.d_inv[211];
  workYaw.v[52] = workYaw.L[51]*workYaw.d[52];
  workYaw.v[212] = workYaw.KKT[423]-workYaw.L[51]*workYaw.v[52];
  workYaw.d[212] = workYaw.v[212];
  if (workYaw.d[212] > 0)
    workYaw.d[212] = -settingsYaw.kkt_reg;
  else
    workYaw.d[212] -= settingsYaw.kkt_reg;
  workYaw.d_inv[212] = 1/workYaw.d[212];
  workYaw.L[428] = (workYaw.KKT[424])*workYaw.d_inv[212];
  workYaw.v[53] = workYaw.L[52]*workYaw.d[53];
  workYaw.v[213] = workYaw.KKT[425]-workYaw.L[52]*workYaw.v[53];
  workYaw.d[213] = workYaw.v[213];
  if (workYaw.d[213] > 0)
    workYaw.d[213] = -settingsYaw.kkt_reg;
  else
    workYaw.d[213] -= settingsYaw.kkt_reg;
  workYaw.d_inv[213] = 1/workYaw.d[213];
  workYaw.L[448] = (workYaw.KKT[426])*workYaw.d_inv[213];
  workYaw.v[54] = workYaw.L[53]*workYaw.d[54];
  workYaw.v[214] = workYaw.KKT[427]-workYaw.L[53]*workYaw.v[54];
  workYaw.d[214] = workYaw.v[214];
  if (workYaw.d[214] > 0)
    workYaw.d[214] = -settingsYaw.kkt_reg;
  else
    workYaw.d[214] -= settingsYaw.kkt_reg;
  workYaw.d_inv[214] = 1/workYaw.d[214];
  workYaw.L[468] = (workYaw.KKT[428])*workYaw.d_inv[214];
  workYaw.v[55] = workYaw.L[54]*workYaw.d[55];
  workYaw.v[215] = workYaw.KKT[429]-workYaw.L[54]*workYaw.v[55];
  workYaw.d[215] = workYaw.v[215];
  if (workYaw.d[215] > 0)
    workYaw.d[215] = -settingsYaw.kkt_reg;
  else
    workYaw.d[215] -= settingsYaw.kkt_reg;
  workYaw.d_inv[215] = 1/workYaw.d[215];
  workYaw.L[488] = (workYaw.KKT[430])*workYaw.d_inv[215];
  workYaw.v[56] = workYaw.L[55]*workYaw.d[56];
  workYaw.v[216] = workYaw.KKT[431]-workYaw.L[55]*workYaw.v[56];
  workYaw.d[216] = workYaw.v[216];
  if (workYaw.d[216] > 0)
    workYaw.d[216] = -settingsYaw.kkt_reg;
  else
    workYaw.d[216] -= settingsYaw.kkt_reg;
  workYaw.d_inv[216] = 1/workYaw.d[216];
  workYaw.L[508] = (workYaw.KKT[432])*workYaw.d_inv[216];
  workYaw.v[57] = workYaw.L[56]*workYaw.d[57];
  workYaw.v[217] = workYaw.KKT[433]-workYaw.L[56]*workYaw.v[57];
  workYaw.d[217] = workYaw.v[217];
  if (workYaw.d[217] > 0)
    workYaw.d[217] = -settingsYaw.kkt_reg;
  else
    workYaw.d[217] -= settingsYaw.kkt_reg;
  workYaw.d_inv[217] = 1/workYaw.d[217];
  workYaw.L[528] = (workYaw.KKT[434])*workYaw.d_inv[217];
  workYaw.v[58] = workYaw.L[57]*workYaw.d[58];
  workYaw.v[218] = workYaw.KKT[435]-workYaw.L[57]*workYaw.v[58];
  workYaw.d[218] = workYaw.v[218];
  if (workYaw.d[218] > 0)
    workYaw.d[218] = -settingsYaw.kkt_reg;
  else
    workYaw.d[218] -= settingsYaw.kkt_reg;
  workYaw.d_inv[218] = 1/workYaw.d[218];
  workYaw.L[548] = (workYaw.KKT[436])*workYaw.d_inv[218];
  workYaw.v[59] = workYaw.L[58]*workYaw.d[59];
  workYaw.v[219] = workYaw.KKT[437]-workYaw.L[58]*workYaw.v[59];
  workYaw.d[219] = workYaw.v[219];
  if (workYaw.d[219] > 0)
    workYaw.d[219] = -settingsYaw.kkt_reg;
  else
    workYaw.d[219] -= settingsYaw.kkt_reg;
  workYaw.d_inv[219] = 1/workYaw.d[219];
  workYaw.L[568] = (workYaw.KKT[438])*workYaw.d_inv[219];
  workYaw.v[60] = workYaw.L[59]*workYaw.d[60];
  workYaw.v[220] = workYaw.KKT[439]-workYaw.L[59]*workYaw.v[60];
  workYaw.d[220] = workYaw.v[220];
  if (workYaw.d[220] > 0)
    workYaw.d[220] = -settingsYaw.kkt_reg;
  else
    workYaw.d[220] -= settingsYaw.kkt_reg;
  workYaw.d_inv[220] = 1/workYaw.d[220];
  workYaw.L[588] = (workYaw.KKT[440])*workYaw.d_inv[220];
  workYaw.v[61] = workYaw.L[60]*workYaw.d[61];
  workYaw.v[221] = workYaw.KKT[441]-workYaw.L[60]*workYaw.v[61];
  workYaw.d[221] = workYaw.v[221];
  if (workYaw.d[221] > 0)
    workYaw.d[221] = -settingsYaw.kkt_reg;
  else
    workYaw.d[221] -= settingsYaw.kkt_reg;
  workYaw.d_inv[221] = 1/workYaw.d[221];
  workYaw.L[608] = (workYaw.KKT[442])*workYaw.d_inv[221];
  workYaw.v[62] = workYaw.L[61]*workYaw.d[62];
  workYaw.v[222] = workYaw.KKT[443]-workYaw.L[61]*workYaw.v[62];
  workYaw.d[222] = workYaw.v[222];
  if (workYaw.d[222] > 0)
    workYaw.d[222] = -settingsYaw.kkt_reg;
  else
    workYaw.d[222] -= settingsYaw.kkt_reg;
  workYaw.d_inv[222] = 1/workYaw.d[222];
  workYaw.L[628] = (workYaw.KKT[444])*workYaw.d_inv[222];
  workYaw.v[63] = workYaw.L[62]*workYaw.d[63];
  workYaw.v[223] = workYaw.KKT[445]-workYaw.L[62]*workYaw.v[63];
  workYaw.d[223] = workYaw.v[223];
  if (workYaw.d[223] > 0)
    workYaw.d[223] = -settingsYaw.kkt_reg;
  else
    workYaw.d[223] -= settingsYaw.kkt_reg;
  workYaw.d_inv[223] = 1/workYaw.d[223];
  workYaw.L[648] = (workYaw.KKT[446])*workYaw.d_inv[223];
  workYaw.v[64] = workYaw.L[63]*workYaw.d[64];
  workYaw.v[224] = workYaw.KKT[447]-workYaw.L[63]*workYaw.v[64];
  workYaw.d[224] = workYaw.v[224];
  if (workYaw.d[224] > 0)
    workYaw.d[224] = -settingsYaw.kkt_reg;
  else
    workYaw.d[224] -= settingsYaw.kkt_reg;
  workYaw.d_inv[224] = 1/workYaw.d[224];
  workYaw.L[668] = (workYaw.KKT[448])*workYaw.d_inv[224];
  workYaw.v[65] = workYaw.L[64]*workYaw.d[65];
  workYaw.v[225] = workYaw.KKT[449]-workYaw.L[64]*workYaw.v[65];
  workYaw.d[225] = workYaw.v[225];
  if (workYaw.d[225] > 0)
    workYaw.d[225] = -settingsYaw.kkt_reg;
  else
    workYaw.d[225] -= settingsYaw.kkt_reg;
  workYaw.d_inv[225] = 1/workYaw.d[225];
  workYaw.L[688] = (workYaw.KKT[450])*workYaw.d_inv[225];
  workYaw.v[66] = workYaw.L[65]*workYaw.d[66];
  workYaw.v[226] = workYaw.KKT[451]-workYaw.L[65]*workYaw.v[66];
  workYaw.d[226] = workYaw.v[226];
  if (workYaw.d[226] > 0)
    workYaw.d[226] = -settingsYaw.kkt_reg;
  else
    workYaw.d[226] -= settingsYaw.kkt_reg;
  workYaw.d_inv[226] = 1/workYaw.d[226];
  workYaw.L[708] = (workYaw.KKT[452])*workYaw.d_inv[226];
  workYaw.v[67] = workYaw.L[66]*workYaw.d[67];
  workYaw.v[227] = workYaw.KKT[453]-workYaw.L[66]*workYaw.v[67];
  workYaw.d[227] = workYaw.v[227];
  if (workYaw.d[227] > 0)
    workYaw.d[227] = -settingsYaw.kkt_reg;
  else
    workYaw.d[227] -= settingsYaw.kkt_reg;
  workYaw.d_inv[227] = 1/workYaw.d[227];
  workYaw.L[728] = (workYaw.KKT[454])*workYaw.d_inv[227];
  workYaw.v[68] = workYaw.L[67]*workYaw.d[68];
  workYaw.v[228] = workYaw.KKT[455]-workYaw.L[67]*workYaw.v[68];
  workYaw.d[228] = workYaw.v[228];
  if (workYaw.d[228] > 0)
    workYaw.d[228] = -settingsYaw.kkt_reg;
  else
    workYaw.d[228] -= settingsYaw.kkt_reg;
  workYaw.d_inv[228] = 1/workYaw.d[228];
  workYaw.L[748] = (workYaw.KKT[456])*workYaw.d_inv[228];
  workYaw.v[69] = workYaw.L[68]*workYaw.d[69];
  workYaw.v[229] = workYaw.KKT[457]-workYaw.L[68]*workYaw.v[69];
  workYaw.d[229] = workYaw.v[229];
  if (workYaw.d[229] > 0)
    workYaw.d[229] = -settingsYaw.kkt_reg;
  else
    workYaw.d[229] -= settingsYaw.kkt_reg;
  workYaw.d_inv[229] = 1/workYaw.d[229];
  workYaw.L[768] = (workYaw.KKT[458])*workYaw.d_inv[229];
  workYaw.v[70] = workYaw.L[69]*workYaw.d[70];
  workYaw.v[230] = workYaw.KKT[459]-workYaw.L[69]*workYaw.v[70];
  workYaw.d[230] = workYaw.v[230];
  if (workYaw.d[230] > 0)
    workYaw.d[230] = -settingsYaw.kkt_reg;
  else
    workYaw.d[230] -= settingsYaw.kkt_reg;
  workYaw.d_inv[230] = 1/workYaw.d[230];
  workYaw.L[788] = (workYaw.KKT[460])*workYaw.d_inv[230];
  workYaw.v[71] = workYaw.L[70]*workYaw.d[71];
  workYaw.v[231] = workYaw.KKT[461]-workYaw.L[70]*workYaw.v[71];
  workYaw.d[231] = workYaw.v[231];
  if (workYaw.d[231] > 0)
    workYaw.d[231] = -settingsYaw.kkt_reg;
  else
    workYaw.d[231] -= settingsYaw.kkt_reg;
  workYaw.d_inv[231] = 1/workYaw.d[231];
  workYaw.L[808] = (workYaw.KKT[462])*workYaw.d_inv[231];
  workYaw.v[72] = workYaw.L[71]*workYaw.d[72];
  workYaw.v[232] = workYaw.KKT[463]-workYaw.L[71]*workYaw.v[72];
  workYaw.d[232] = workYaw.v[232];
  if (workYaw.d[232] > 0)
    workYaw.d[232] = -settingsYaw.kkt_reg;
  else
    workYaw.d[232] -= settingsYaw.kkt_reg;
  workYaw.d_inv[232] = 1/workYaw.d[232];
  workYaw.L[828] = (workYaw.KKT[464])*workYaw.d_inv[232];
  workYaw.v[73] = workYaw.L[72]*workYaw.d[73];
  workYaw.v[233] = workYaw.KKT[465]-workYaw.L[72]*workYaw.v[73];
  workYaw.d[233] = workYaw.v[233];
  if (workYaw.d[233] > 0)
    workYaw.d[233] = -settingsYaw.kkt_reg;
  else
    workYaw.d[233] -= settingsYaw.kkt_reg;
  workYaw.d_inv[233] = 1/workYaw.d[233];
  workYaw.L[848] = (workYaw.KKT[466])*workYaw.d_inv[233];
  workYaw.v[74] = workYaw.L[73]*workYaw.d[74];
  workYaw.v[234] = workYaw.KKT[467]-workYaw.L[73]*workYaw.v[74];
  workYaw.d[234] = workYaw.v[234];
  if (workYaw.d[234] > 0)
    workYaw.d[234] = -settingsYaw.kkt_reg;
  else
    workYaw.d[234] -= settingsYaw.kkt_reg;
  workYaw.d_inv[234] = 1/workYaw.d[234];
  workYaw.L[868] = (workYaw.KKT[468])*workYaw.d_inv[234];
  workYaw.v[75] = workYaw.L[74]*workYaw.d[75];
  workYaw.v[235] = workYaw.KKT[469]-workYaw.L[74]*workYaw.v[75];
  workYaw.d[235] = workYaw.v[235];
  if (workYaw.d[235] > 0)
    workYaw.d[235] = -settingsYaw.kkt_reg;
  else
    workYaw.d[235] -= settingsYaw.kkt_reg;
  workYaw.d_inv[235] = 1/workYaw.d[235];
  workYaw.L[888] = (workYaw.KKT[470])*workYaw.d_inv[235];
  workYaw.v[76] = workYaw.L[75]*workYaw.d[76];
  workYaw.v[236] = workYaw.KKT[471]-workYaw.L[75]*workYaw.v[76];
  workYaw.d[236] = workYaw.v[236];
  if (workYaw.d[236] > 0)
    workYaw.d[236] = -settingsYaw.kkt_reg;
  else
    workYaw.d[236] -= settingsYaw.kkt_reg;
  workYaw.d_inv[236] = 1/workYaw.d[236];
  workYaw.L[908] = (workYaw.KKT[472])*workYaw.d_inv[236];
  workYaw.v[77] = workYaw.L[76]*workYaw.d[77];
  workYaw.v[237] = workYaw.KKT[473]-workYaw.L[76]*workYaw.v[77];
  workYaw.d[237] = workYaw.v[237];
  if (workYaw.d[237] > 0)
    workYaw.d[237] = -settingsYaw.kkt_reg;
  else
    workYaw.d[237] -= settingsYaw.kkt_reg;
  workYaw.d_inv[237] = 1/workYaw.d[237];
  workYaw.L[928] = (workYaw.KKT[474])*workYaw.d_inv[237];
  workYaw.v[78] = workYaw.L[77]*workYaw.d[78];
  workYaw.v[238] = workYaw.KKT[475]-workYaw.L[77]*workYaw.v[78];
  workYaw.d[238] = workYaw.v[238];
  if (workYaw.d[238] > 0)
    workYaw.d[238] = -settingsYaw.kkt_reg;
  else
    workYaw.d[238] -= settingsYaw.kkt_reg;
  workYaw.d_inv[238] = 1/workYaw.d[238];
  workYaw.L[952] = (workYaw.KKT[476])*workYaw.d_inv[238];
  workYaw.v[79] = workYaw.L[78]*workYaw.d[79];
  workYaw.v[239] = workYaw.KKT[477]-workYaw.L[78]*workYaw.v[79];
  workYaw.d[239] = workYaw.v[239];
  if (workYaw.d[239] > 0)
    workYaw.d[239] = -settingsYaw.kkt_reg;
  else
    workYaw.d[239] -= settingsYaw.kkt_reg;
  workYaw.d_inv[239] = 1/workYaw.d[239];
  workYaw.L[968] = (workYaw.KKT[478])*workYaw.d_inv[239];
  workYaw.v[80] = workYaw.L[79]*workYaw.d[80];
  workYaw.v[240] = workYaw.KKT[479]-workYaw.L[79]*workYaw.v[80];
  workYaw.d[240] = workYaw.v[240];
  if (workYaw.d[240] > 0)
    workYaw.d[240] = -settingsYaw.kkt_reg;
  else
    workYaw.d[240] -= settingsYaw.kkt_reg;
  workYaw.d_inv[240] = 1/workYaw.d[240];
  workYaw.L[167] = (workYaw.KKT[480])*workYaw.d_inv[240];
  workYaw.v[81] = workYaw.L[80]*workYaw.d[81];
  workYaw.v[241] = workYaw.KKT[481]-workYaw.L[80]*workYaw.v[81];
  workYaw.d[241] = workYaw.v[241];
  if (workYaw.d[241] > 0)
    workYaw.d[241] = -settingsYaw.kkt_reg;
  else
    workYaw.d[241] -= settingsYaw.kkt_reg;
  workYaw.d_inv[241] = 1/workYaw.d[241];
  workYaw.L[219] = (workYaw.KKT[482])*workYaw.d_inv[241];
  workYaw.v[82] = workYaw.L[81]*workYaw.d[82];
  workYaw.v[242] = workYaw.KKT[483]-workYaw.L[81]*workYaw.v[82];
  workYaw.d[242] = workYaw.v[242];
  if (workYaw.d[242] > 0)
    workYaw.d[242] = -settingsYaw.kkt_reg;
  else
    workYaw.d[242] -= settingsYaw.kkt_reg;
  workYaw.d_inv[242] = 1/workYaw.d[242];
  workYaw.L[232] = (workYaw.KKT[484])*workYaw.d_inv[242];
  workYaw.v[83] = workYaw.L[82]*workYaw.d[83];
  workYaw.v[243] = workYaw.KKT[485]-workYaw.L[82]*workYaw.v[83];
  workYaw.d[243] = workYaw.v[243];
  if (workYaw.d[243] > 0)
    workYaw.d[243] = -settingsYaw.kkt_reg;
  else
    workYaw.d[243] -= settingsYaw.kkt_reg;
  workYaw.d_inv[243] = 1/workYaw.d[243];
  workYaw.L[250] = (workYaw.KKT[486])*workYaw.d_inv[243];
  workYaw.v[84] = workYaw.L[83]*workYaw.d[84];
  workYaw.v[244] = workYaw.KKT[487]-workYaw.L[83]*workYaw.v[84];
  workYaw.d[244] = workYaw.v[244];
  if (workYaw.d[244] > 0)
    workYaw.d[244] = -settingsYaw.kkt_reg;
  else
    workYaw.d[244] -= settingsYaw.kkt_reg;
  workYaw.d_inv[244] = 1/workYaw.d[244];
  workYaw.L[270] = (workYaw.KKT[488])*workYaw.d_inv[244];
  workYaw.v[85] = workYaw.L[84]*workYaw.d[85];
  workYaw.v[245] = workYaw.KKT[489]-workYaw.L[84]*workYaw.v[85];
  workYaw.d[245] = workYaw.v[245];
  if (workYaw.d[245] > 0)
    workYaw.d[245] = -settingsYaw.kkt_reg;
  else
    workYaw.d[245] -= settingsYaw.kkt_reg;
  workYaw.d_inv[245] = 1/workYaw.d[245];
  workYaw.L[290] = (workYaw.KKT[490])*workYaw.d_inv[245];
  workYaw.v[86] = workYaw.L[85]*workYaw.d[86];
  workYaw.v[246] = workYaw.KKT[491]-workYaw.L[85]*workYaw.v[86];
  workYaw.d[246] = workYaw.v[246];
  if (workYaw.d[246] > 0)
    workYaw.d[246] = -settingsYaw.kkt_reg;
  else
    workYaw.d[246] -= settingsYaw.kkt_reg;
  workYaw.d_inv[246] = 1/workYaw.d[246];
  workYaw.L[310] = (workYaw.KKT[492])*workYaw.d_inv[246];
  workYaw.v[87] = workYaw.L[86]*workYaw.d[87];
  workYaw.v[247] = workYaw.KKT[493]-workYaw.L[86]*workYaw.v[87];
  workYaw.d[247] = workYaw.v[247];
  if (workYaw.d[247] > 0)
    workYaw.d[247] = -settingsYaw.kkt_reg;
  else
    workYaw.d[247] -= settingsYaw.kkt_reg;
  workYaw.d_inv[247] = 1/workYaw.d[247];
  workYaw.L[330] = (workYaw.KKT[494])*workYaw.d_inv[247];
  workYaw.v[88] = workYaw.L[87]*workYaw.d[88];
  workYaw.v[248] = workYaw.KKT[495]-workYaw.L[87]*workYaw.v[88];
  workYaw.d[248] = workYaw.v[248];
  if (workYaw.d[248] > 0)
    workYaw.d[248] = -settingsYaw.kkt_reg;
  else
    workYaw.d[248] -= settingsYaw.kkt_reg;
  workYaw.d_inv[248] = 1/workYaw.d[248];
  workYaw.L[350] = (workYaw.KKT[496])*workYaw.d_inv[248];
  workYaw.v[89] = workYaw.L[88]*workYaw.d[89];
  workYaw.v[249] = workYaw.KKT[497]-workYaw.L[88]*workYaw.v[89];
  workYaw.d[249] = workYaw.v[249];
  if (workYaw.d[249] > 0)
    workYaw.d[249] = -settingsYaw.kkt_reg;
  else
    workYaw.d[249] -= settingsYaw.kkt_reg;
  workYaw.d_inv[249] = 1/workYaw.d[249];
  workYaw.L[370] = (workYaw.KKT[498])*workYaw.d_inv[249];
  workYaw.v[90] = workYaw.L[89]*workYaw.d[90];
  workYaw.v[250] = workYaw.KKT[499]-workYaw.L[89]*workYaw.v[90];
  workYaw.d[250] = workYaw.v[250];
  if (workYaw.d[250] > 0)
    workYaw.d[250] = -settingsYaw.kkt_reg;
  else
    workYaw.d[250] -= settingsYaw.kkt_reg;
  workYaw.d_inv[250] = 1/workYaw.d[250];
  workYaw.L[390] = (workYaw.KKT[500])*workYaw.d_inv[250];
  workYaw.v[91] = workYaw.L[90]*workYaw.d[91];
  workYaw.v[251] = workYaw.KKT[501]-workYaw.L[90]*workYaw.v[91];
  workYaw.d[251] = workYaw.v[251];
  if (workYaw.d[251] > 0)
    workYaw.d[251] = -settingsYaw.kkt_reg;
  else
    workYaw.d[251] -= settingsYaw.kkt_reg;
  workYaw.d_inv[251] = 1/workYaw.d[251];
  workYaw.L[410] = (workYaw.KKT[502])*workYaw.d_inv[251];
  workYaw.v[92] = workYaw.L[91]*workYaw.d[92];
  workYaw.v[252] = workYaw.KKT[503]-workYaw.L[91]*workYaw.v[92];
  workYaw.d[252] = workYaw.v[252];
  if (workYaw.d[252] > 0)
    workYaw.d[252] = -settingsYaw.kkt_reg;
  else
    workYaw.d[252] -= settingsYaw.kkt_reg;
  workYaw.d_inv[252] = 1/workYaw.d[252];
  workYaw.L[430] = (workYaw.KKT[504])*workYaw.d_inv[252];
  workYaw.v[93] = workYaw.L[92]*workYaw.d[93];
  workYaw.v[253] = workYaw.KKT[505]-workYaw.L[92]*workYaw.v[93];
  workYaw.d[253] = workYaw.v[253];
  if (workYaw.d[253] > 0)
    workYaw.d[253] = -settingsYaw.kkt_reg;
  else
    workYaw.d[253] -= settingsYaw.kkt_reg;
  workYaw.d_inv[253] = 1/workYaw.d[253];
  workYaw.L[450] = (workYaw.KKT[506])*workYaw.d_inv[253];
  workYaw.v[94] = workYaw.L[93]*workYaw.d[94];
  workYaw.v[254] = workYaw.KKT[507]-workYaw.L[93]*workYaw.v[94];
  workYaw.d[254] = workYaw.v[254];
  if (workYaw.d[254] > 0)
    workYaw.d[254] = -settingsYaw.kkt_reg;
  else
    workYaw.d[254] -= settingsYaw.kkt_reg;
  workYaw.d_inv[254] = 1/workYaw.d[254];
  workYaw.L[470] = (workYaw.KKT[508])*workYaw.d_inv[254];
  workYaw.v[95] = workYaw.L[94]*workYaw.d[95];
  workYaw.v[255] = workYaw.KKT[509]-workYaw.L[94]*workYaw.v[95];
  workYaw.d[255] = workYaw.v[255];
  if (workYaw.d[255] > 0)
    workYaw.d[255] = -settingsYaw.kkt_reg;
  else
    workYaw.d[255] -= settingsYaw.kkt_reg;
  workYaw.d_inv[255] = 1/workYaw.d[255];
  workYaw.L[490] = (workYaw.KKT[510])*workYaw.d_inv[255];
  workYaw.v[96] = workYaw.L[95]*workYaw.d[96];
  workYaw.v[256] = workYaw.KKT[511]-workYaw.L[95]*workYaw.v[96];
  workYaw.d[256] = workYaw.v[256];
  if (workYaw.d[256] > 0)
    workYaw.d[256] = -settingsYaw.kkt_reg;
  else
    workYaw.d[256] -= settingsYaw.kkt_reg;
  workYaw.d_inv[256] = 1/workYaw.d[256];
  workYaw.L[510] = (workYaw.KKT[512])*workYaw.d_inv[256];
  workYaw.v[97] = workYaw.L[96]*workYaw.d[97];
  workYaw.v[257] = workYaw.KKT[513]-workYaw.L[96]*workYaw.v[97];
  workYaw.d[257] = workYaw.v[257];
  if (workYaw.d[257] > 0)
    workYaw.d[257] = -settingsYaw.kkt_reg;
  else
    workYaw.d[257] -= settingsYaw.kkt_reg;
  workYaw.d_inv[257] = 1/workYaw.d[257];
  workYaw.L[530] = (workYaw.KKT[514])*workYaw.d_inv[257];
  workYaw.v[98] = workYaw.L[97]*workYaw.d[98];
  workYaw.v[258] = workYaw.KKT[515]-workYaw.L[97]*workYaw.v[98];
  workYaw.d[258] = workYaw.v[258];
  if (workYaw.d[258] > 0)
    workYaw.d[258] = -settingsYaw.kkt_reg;
  else
    workYaw.d[258] -= settingsYaw.kkt_reg;
  workYaw.d_inv[258] = 1/workYaw.d[258];
  workYaw.L[550] = (workYaw.KKT[516])*workYaw.d_inv[258];
  workYaw.v[99] = workYaw.L[98]*workYaw.d[99];
  workYaw.v[259] = workYaw.KKT[517]-workYaw.L[98]*workYaw.v[99];
  workYaw.d[259] = workYaw.v[259];
  if (workYaw.d[259] > 0)
    workYaw.d[259] = -settingsYaw.kkt_reg;
  else
    workYaw.d[259] -= settingsYaw.kkt_reg;
  workYaw.d_inv[259] = 1/workYaw.d[259];
  workYaw.L[570] = (workYaw.KKT[518])*workYaw.d_inv[259];
  workYaw.v[100] = workYaw.L[99]*workYaw.d[100];
  workYaw.v[260] = workYaw.KKT[519]-workYaw.L[99]*workYaw.v[100];
  workYaw.d[260] = workYaw.v[260];
  if (workYaw.d[260] > 0)
    workYaw.d[260] = -settingsYaw.kkt_reg;
  else
    workYaw.d[260] -= settingsYaw.kkt_reg;
  workYaw.d_inv[260] = 1/workYaw.d[260];
  workYaw.L[590] = (workYaw.KKT[520])*workYaw.d_inv[260];
  workYaw.v[101] = workYaw.L[100]*workYaw.d[101];
  workYaw.v[261] = workYaw.KKT[521]-workYaw.L[100]*workYaw.v[101];
  workYaw.d[261] = workYaw.v[261];
  if (workYaw.d[261] > 0)
    workYaw.d[261] = -settingsYaw.kkt_reg;
  else
    workYaw.d[261] -= settingsYaw.kkt_reg;
  workYaw.d_inv[261] = 1/workYaw.d[261];
  workYaw.L[610] = (workYaw.KKT[522])*workYaw.d_inv[261];
  workYaw.v[102] = workYaw.L[101]*workYaw.d[102];
  workYaw.v[262] = workYaw.KKT[523]-workYaw.L[101]*workYaw.v[102];
  workYaw.d[262] = workYaw.v[262];
  if (workYaw.d[262] > 0)
    workYaw.d[262] = -settingsYaw.kkt_reg;
  else
    workYaw.d[262] -= settingsYaw.kkt_reg;
  workYaw.d_inv[262] = 1/workYaw.d[262];
  workYaw.L[630] = (workYaw.KKT[524])*workYaw.d_inv[262];
  workYaw.v[103] = workYaw.L[102]*workYaw.d[103];
  workYaw.v[263] = workYaw.KKT[525]-workYaw.L[102]*workYaw.v[103];
  workYaw.d[263] = workYaw.v[263];
  if (workYaw.d[263] > 0)
    workYaw.d[263] = -settingsYaw.kkt_reg;
  else
    workYaw.d[263] -= settingsYaw.kkt_reg;
  workYaw.d_inv[263] = 1/workYaw.d[263];
  workYaw.L[650] = (workYaw.KKT[526])*workYaw.d_inv[263];
  workYaw.v[104] = workYaw.L[103]*workYaw.d[104];
  workYaw.v[264] = workYaw.KKT[527]-workYaw.L[103]*workYaw.v[104];
  workYaw.d[264] = workYaw.v[264];
  if (workYaw.d[264] > 0)
    workYaw.d[264] = -settingsYaw.kkt_reg;
  else
    workYaw.d[264] -= settingsYaw.kkt_reg;
  workYaw.d_inv[264] = 1/workYaw.d[264];
  workYaw.L[670] = (workYaw.KKT[528])*workYaw.d_inv[264];
  workYaw.v[105] = workYaw.L[104]*workYaw.d[105];
  workYaw.v[265] = workYaw.KKT[529]-workYaw.L[104]*workYaw.v[105];
  workYaw.d[265] = workYaw.v[265];
  if (workYaw.d[265] > 0)
    workYaw.d[265] = -settingsYaw.kkt_reg;
  else
    workYaw.d[265] -= settingsYaw.kkt_reg;
  workYaw.d_inv[265] = 1/workYaw.d[265];
  workYaw.L[690] = (workYaw.KKT[530])*workYaw.d_inv[265];
  workYaw.v[106] = workYaw.L[105]*workYaw.d[106];
  workYaw.v[266] = workYaw.KKT[531]-workYaw.L[105]*workYaw.v[106];
  workYaw.d[266] = workYaw.v[266];
  if (workYaw.d[266] > 0)
    workYaw.d[266] = -settingsYaw.kkt_reg;
  else
    workYaw.d[266] -= settingsYaw.kkt_reg;
  workYaw.d_inv[266] = 1/workYaw.d[266];
  workYaw.L[710] = (workYaw.KKT[532])*workYaw.d_inv[266];
  workYaw.v[107] = workYaw.L[106]*workYaw.d[107];
  workYaw.v[267] = workYaw.KKT[533]-workYaw.L[106]*workYaw.v[107];
  workYaw.d[267] = workYaw.v[267];
  if (workYaw.d[267] > 0)
    workYaw.d[267] = -settingsYaw.kkt_reg;
  else
    workYaw.d[267] -= settingsYaw.kkt_reg;
  workYaw.d_inv[267] = 1/workYaw.d[267];
  workYaw.L[730] = (workYaw.KKT[534])*workYaw.d_inv[267];
  workYaw.v[108] = workYaw.L[107]*workYaw.d[108];
  workYaw.v[268] = workYaw.KKT[535]-workYaw.L[107]*workYaw.v[108];
  workYaw.d[268] = workYaw.v[268];
  if (workYaw.d[268] > 0)
    workYaw.d[268] = -settingsYaw.kkt_reg;
  else
    workYaw.d[268] -= settingsYaw.kkt_reg;
  workYaw.d_inv[268] = 1/workYaw.d[268];
  workYaw.L[750] = (workYaw.KKT[536])*workYaw.d_inv[268];
  workYaw.v[109] = workYaw.L[108]*workYaw.d[109];
  workYaw.v[269] = workYaw.KKT[537]-workYaw.L[108]*workYaw.v[109];
  workYaw.d[269] = workYaw.v[269];
  if (workYaw.d[269] > 0)
    workYaw.d[269] = -settingsYaw.kkt_reg;
  else
    workYaw.d[269] -= settingsYaw.kkt_reg;
  workYaw.d_inv[269] = 1/workYaw.d[269];
  workYaw.L[770] = (workYaw.KKT[538])*workYaw.d_inv[269];
  workYaw.v[110] = workYaw.L[109]*workYaw.d[110];
  workYaw.v[270] = workYaw.KKT[539]-workYaw.L[109]*workYaw.v[110];
  workYaw.d[270] = workYaw.v[270];
  if (workYaw.d[270] > 0)
    workYaw.d[270] = -settingsYaw.kkt_reg;
  else
    workYaw.d[270] -= settingsYaw.kkt_reg;
  workYaw.d_inv[270] = 1/workYaw.d[270];
  workYaw.L[790] = (workYaw.KKT[540])*workYaw.d_inv[270];
  workYaw.v[111] = workYaw.L[110]*workYaw.d[111];
  workYaw.v[271] = workYaw.KKT[541]-workYaw.L[110]*workYaw.v[111];
  workYaw.d[271] = workYaw.v[271];
  if (workYaw.d[271] > 0)
    workYaw.d[271] = -settingsYaw.kkt_reg;
  else
    workYaw.d[271] -= settingsYaw.kkt_reg;
  workYaw.d_inv[271] = 1/workYaw.d[271];
  workYaw.L[810] = (workYaw.KKT[542])*workYaw.d_inv[271];
  workYaw.v[112] = workYaw.L[111]*workYaw.d[112];
  workYaw.v[272] = workYaw.KKT[543]-workYaw.L[111]*workYaw.v[112];
  workYaw.d[272] = workYaw.v[272];
  if (workYaw.d[272] > 0)
    workYaw.d[272] = -settingsYaw.kkt_reg;
  else
    workYaw.d[272] -= settingsYaw.kkt_reg;
  workYaw.d_inv[272] = 1/workYaw.d[272];
  workYaw.L[830] = (workYaw.KKT[544])*workYaw.d_inv[272];
  workYaw.v[113] = workYaw.L[112]*workYaw.d[113];
  workYaw.v[273] = workYaw.KKT[545]-workYaw.L[112]*workYaw.v[113];
  workYaw.d[273] = workYaw.v[273];
  if (workYaw.d[273] > 0)
    workYaw.d[273] = -settingsYaw.kkt_reg;
  else
    workYaw.d[273] -= settingsYaw.kkt_reg;
  workYaw.d_inv[273] = 1/workYaw.d[273];
  workYaw.L[850] = (workYaw.KKT[546])*workYaw.d_inv[273];
  workYaw.v[114] = workYaw.L[113]*workYaw.d[114];
  workYaw.v[274] = workYaw.KKT[547]-workYaw.L[113]*workYaw.v[114];
  workYaw.d[274] = workYaw.v[274];
  if (workYaw.d[274] > 0)
    workYaw.d[274] = -settingsYaw.kkt_reg;
  else
    workYaw.d[274] -= settingsYaw.kkt_reg;
  workYaw.d_inv[274] = 1/workYaw.d[274];
  workYaw.L[870] = (workYaw.KKT[548])*workYaw.d_inv[274];
  workYaw.v[115] = workYaw.L[114]*workYaw.d[115];
  workYaw.v[275] = workYaw.KKT[549]-workYaw.L[114]*workYaw.v[115];
  workYaw.d[275] = workYaw.v[275];
  if (workYaw.d[275] > 0)
    workYaw.d[275] = -settingsYaw.kkt_reg;
  else
    workYaw.d[275] -= settingsYaw.kkt_reg;
  workYaw.d_inv[275] = 1/workYaw.d[275];
  workYaw.L[890] = (workYaw.KKT[550])*workYaw.d_inv[275];
  workYaw.v[116] = workYaw.L[115]*workYaw.d[116];
  workYaw.v[276] = workYaw.KKT[551]-workYaw.L[115]*workYaw.v[116];
  workYaw.d[276] = workYaw.v[276];
  if (workYaw.d[276] > 0)
    workYaw.d[276] = -settingsYaw.kkt_reg;
  else
    workYaw.d[276] -= settingsYaw.kkt_reg;
  workYaw.d_inv[276] = 1/workYaw.d[276];
  workYaw.L[910] = (workYaw.KKT[552])*workYaw.d_inv[276];
  workYaw.v[117] = workYaw.L[116]*workYaw.d[117];
  workYaw.v[277] = workYaw.KKT[553]-workYaw.L[116]*workYaw.v[117];
  workYaw.d[277] = workYaw.v[277];
  if (workYaw.d[277] > 0)
    workYaw.d[277] = -settingsYaw.kkt_reg;
  else
    workYaw.d[277] -= settingsYaw.kkt_reg;
  workYaw.d_inv[277] = 1/workYaw.d[277];
  workYaw.L[930] = (workYaw.KKT[554])*workYaw.d_inv[277];
  workYaw.v[118] = workYaw.L[117]*workYaw.d[118];
  workYaw.v[278] = workYaw.KKT[555]-workYaw.L[117]*workYaw.v[118];
  workYaw.d[278] = workYaw.v[278];
  if (workYaw.d[278] > 0)
    workYaw.d[278] = -settingsYaw.kkt_reg;
  else
    workYaw.d[278] -= settingsYaw.kkt_reg;
  workYaw.d_inv[278] = 1/workYaw.d[278];
  workYaw.L[956] = (workYaw.KKT[556])*workYaw.d_inv[278];
  workYaw.v[119] = workYaw.L[118]*workYaw.d[119];
  workYaw.v[279] = workYaw.KKT[557]-workYaw.L[118]*workYaw.v[119];
  workYaw.d[279] = workYaw.v[279];
  if (workYaw.d[279] > 0)
    workYaw.d[279] = -settingsYaw.kkt_reg;
  else
    workYaw.d[279] -= settingsYaw.kkt_reg;
  workYaw.d_inv[279] = 1/workYaw.d[279];
  workYaw.L[168] = (workYaw.KKT[558])*workYaw.d_inv[279];
  workYaw.v[120] = workYaw.L[119]*workYaw.d[120];
  workYaw.v[280] = workYaw.KKT[559]-workYaw.L[119]*workYaw.v[120];
  workYaw.d[280] = workYaw.v[280];
  if (workYaw.d[280] > 0)
    workYaw.d[280] = -settingsYaw.kkt_reg;
  else
    workYaw.d[280] -= settingsYaw.kkt_reg;
  workYaw.d_inv[280] = 1/workYaw.d[280];
  workYaw.L[161] = (workYaw.KKT[560])*workYaw.d_inv[280];
  workYaw.v[121] = workYaw.L[120]*workYaw.d[121];
  workYaw.v[281] = workYaw.KKT[561]-workYaw.L[120]*workYaw.v[121];
  workYaw.d[281] = workYaw.v[281];
  if (workYaw.d[281] > 0)
    workYaw.d[281] = -settingsYaw.kkt_reg;
  else
    workYaw.d[281] -= settingsYaw.kkt_reg;
  workYaw.d_inv[281] = 1/workYaw.d[281];
  workYaw.L[220] = (workYaw.KKT[562])*workYaw.d_inv[281];
  workYaw.v[122] = workYaw.L[121]*workYaw.d[122];
  workYaw.v[282] = workYaw.KKT[563]-workYaw.L[121]*workYaw.v[122];
  workYaw.d[282] = workYaw.v[282];
  if (workYaw.d[282] > 0)
    workYaw.d[282] = -settingsYaw.kkt_reg;
  else
    workYaw.d[282] -= settingsYaw.kkt_reg;
  workYaw.d_inv[282] = 1/workYaw.d[282];
  workYaw.L[233] = (workYaw.KKT[564])*workYaw.d_inv[282];
  workYaw.v[123] = workYaw.L[122]*workYaw.d[123];
  workYaw.v[283] = workYaw.KKT[565]-workYaw.L[122]*workYaw.v[123];
  workYaw.d[283] = workYaw.v[283];
  if (workYaw.d[283] > 0)
    workYaw.d[283] = -settingsYaw.kkt_reg;
  else
    workYaw.d[283] -= settingsYaw.kkt_reg;
  workYaw.d_inv[283] = 1/workYaw.d[283];
  workYaw.L[251] = (workYaw.KKT[566])*workYaw.d_inv[283];
  workYaw.v[124] = workYaw.L[123]*workYaw.d[124];
  workYaw.v[284] = workYaw.KKT[567]-workYaw.L[123]*workYaw.v[124];
  workYaw.d[284] = workYaw.v[284];
  if (workYaw.d[284] > 0)
    workYaw.d[284] = -settingsYaw.kkt_reg;
  else
    workYaw.d[284] -= settingsYaw.kkt_reg;
  workYaw.d_inv[284] = 1/workYaw.d[284];
  workYaw.L[271] = (workYaw.KKT[568])*workYaw.d_inv[284];
  workYaw.v[125] = workYaw.L[124]*workYaw.d[125];
  workYaw.v[285] = workYaw.KKT[569]-workYaw.L[124]*workYaw.v[125];
  workYaw.d[285] = workYaw.v[285];
  if (workYaw.d[285] > 0)
    workYaw.d[285] = -settingsYaw.kkt_reg;
  else
    workYaw.d[285] -= settingsYaw.kkt_reg;
  workYaw.d_inv[285] = 1/workYaw.d[285];
  workYaw.L[291] = (workYaw.KKT[570])*workYaw.d_inv[285];
  workYaw.v[126] = workYaw.L[125]*workYaw.d[126];
  workYaw.v[286] = workYaw.KKT[571]-workYaw.L[125]*workYaw.v[126];
  workYaw.d[286] = workYaw.v[286];
  if (workYaw.d[286] > 0)
    workYaw.d[286] = -settingsYaw.kkt_reg;
  else
    workYaw.d[286] -= settingsYaw.kkt_reg;
  workYaw.d_inv[286] = 1/workYaw.d[286];
  workYaw.L[311] = (workYaw.KKT[572])*workYaw.d_inv[286];
  workYaw.v[127] = workYaw.L[126]*workYaw.d[127];
  workYaw.v[287] = workYaw.KKT[573]-workYaw.L[126]*workYaw.v[127];
  workYaw.d[287] = workYaw.v[287];
  if (workYaw.d[287] > 0)
    workYaw.d[287] = -settingsYaw.kkt_reg;
  else
    workYaw.d[287] -= settingsYaw.kkt_reg;
  workYaw.d_inv[287] = 1/workYaw.d[287];
  workYaw.L[331] = (workYaw.KKT[574])*workYaw.d_inv[287];
  workYaw.v[128] = workYaw.L[127]*workYaw.d[128];
  workYaw.v[288] = workYaw.KKT[575]-workYaw.L[127]*workYaw.v[128];
  workYaw.d[288] = workYaw.v[288];
  if (workYaw.d[288] > 0)
    workYaw.d[288] = -settingsYaw.kkt_reg;
  else
    workYaw.d[288] -= settingsYaw.kkt_reg;
  workYaw.d_inv[288] = 1/workYaw.d[288];
  workYaw.L[351] = (workYaw.KKT[576])*workYaw.d_inv[288];
  workYaw.v[129] = workYaw.L[128]*workYaw.d[129];
  workYaw.v[289] = workYaw.KKT[577]-workYaw.L[128]*workYaw.v[129];
  workYaw.d[289] = workYaw.v[289];
  if (workYaw.d[289] > 0)
    workYaw.d[289] = -settingsYaw.kkt_reg;
  else
    workYaw.d[289] -= settingsYaw.kkt_reg;
  workYaw.d_inv[289] = 1/workYaw.d[289];
  workYaw.L[371] = (workYaw.KKT[578])*workYaw.d_inv[289];
  workYaw.v[130] = workYaw.L[129]*workYaw.d[130];
  workYaw.v[290] = workYaw.KKT[579]-workYaw.L[129]*workYaw.v[130];
  workYaw.d[290] = workYaw.v[290];
  if (workYaw.d[290] > 0)
    workYaw.d[290] = -settingsYaw.kkt_reg;
  else
    workYaw.d[290] -= settingsYaw.kkt_reg;
  workYaw.d_inv[290] = 1/workYaw.d[290];
  workYaw.L[391] = (workYaw.KKT[580])*workYaw.d_inv[290];
  workYaw.v[131] = workYaw.L[130]*workYaw.d[131];
  workYaw.v[291] = workYaw.KKT[581]-workYaw.L[130]*workYaw.v[131];
  workYaw.d[291] = workYaw.v[291];
  if (workYaw.d[291] > 0)
    workYaw.d[291] = -settingsYaw.kkt_reg;
  else
    workYaw.d[291] -= settingsYaw.kkt_reg;
  workYaw.d_inv[291] = 1/workYaw.d[291];
  workYaw.L[411] = (workYaw.KKT[582])*workYaw.d_inv[291];
  workYaw.v[132] = workYaw.L[131]*workYaw.d[132];
  workYaw.v[292] = workYaw.KKT[583]-workYaw.L[131]*workYaw.v[132];
  workYaw.d[292] = workYaw.v[292];
  if (workYaw.d[292] > 0)
    workYaw.d[292] = -settingsYaw.kkt_reg;
  else
    workYaw.d[292] -= settingsYaw.kkt_reg;
  workYaw.d_inv[292] = 1/workYaw.d[292];
  workYaw.L[431] = (workYaw.KKT[584])*workYaw.d_inv[292];
  workYaw.v[133] = workYaw.L[132]*workYaw.d[133];
  workYaw.v[293] = workYaw.KKT[585]-workYaw.L[132]*workYaw.v[133];
  workYaw.d[293] = workYaw.v[293];
  if (workYaw.d[293] > 0)
    workYaw.d[293] = -settingsYaw.kkt_reg;
  else
    workYaw.d[293] -= settingsYaw.kkt_reg;
  workYaw.d_inv[293] = 1/workYaw.d[293];
  workYaw.L[451] = (workYaw.KKT[586])*workYaw.d_inv[293];
  workYaw.v[134] = workYaw.L[133]*workYaw.d[134];
  workYaw.v[294] = workYaw.KKT[587]-workYaw.L[133]*workYaw.v[134];
  workYaw.d[294] = workYaw.v[294];
  if (workYaw.d[294] > 0)
    workYaw.d[294] = -settingsYaw.kkt_reg;
  else
    workYaw.d[294] -= settingsYaw.kkt_reg;
  workYaw.d_inv[294] = 1/workYaw.d[294];
  workYaw.L[471] = (workYaw.KKT[588])*workYaw.d_inv[294];
  workYaw.v[135] = workYaw.L[134]*workYaw.d[135];
  workYaw.v[295] = workYaw.KKT[589]-workYaw.L[134]*workYaw.v[135];
  workYaw.d[295] = workYaw.v[295];
  if (workYaw.d[295] > 0)
    workYaw.d[295] = -settingsYaw.kkt_reg;
  else
    workYaw.d[295] -= settingsYaw.kkt_reg;
  workYaw.d_inv[295] = 1/workYaw.d[295];
  workYaw.L[491] = (workYaw.KKT[590])*workYaw.d_inv[295];
  workYaw.v[136] = workYaw.L[135]*workYaw.d[136];
  workYaw.v[296] = workYaw.KKT[591]-workYaw.L[135]*workYaw.v[136];
  workYaw.d[296] = workYaw.v[296];
  if (workYaw.d[296] > 0)
    workYaw.d[296] = -settingsYaw.kkt_reg;
  else
    workYaw.d[296] -= settingsYaw.kkt_reg;
  workYaw.d_inv[296] = 1/workYaw.d[296];
  workYaw.L[511] = (workYaw.KKT[592])*workYaw.d_inv[296];
  workYaw.v[137] = workYaw.L[136]*workYaw.d[137];
  workYaw.v[297] = workYaw.KKT[593]-workYaw.L[136]*workYaw.v[137];
  workYaw.d[297] = workYaw.v[297];
  if (workYaw.d[297] > 0)
    workYaw.d[297] = -settingsYaw.kkt_reg;
  else
    workYaw.d[297] -= settingsYaw.kkt_reg;
  workYaw.d_inv[297] = 1/workYaw.d[297];
  workYaw.L[531] = (workYaw.KKT[594])*workYaw.d_inv[297];
  workYaw.v[138] = workYaw.L[137]*workYaw.d[138];
  workYaw.v[298] = workYaw.KKT[595]-workYaw.L[137]*workYaw.v[138];
  workYaw.d[298] = workYaw.v[298];
  if (workYaw.d[298] > 0)
    workYaw.d[298] = -settingsYaw.kkt_reg;
  else
    workYaw.d[298] -= settingsYaw.kkt_reg;
  workYaw.d_inv[298] = 1/workYaw.d[298];
  workYaw.L[551] = (workYaw.KKT[596])*workYaw.d_inv[298];
  workYaw.v[139] = workYaw.L[138]*workYaw.d[139];
  workYaw.v[299] = workYaw.KKT[597]-workYaw.L[138]*workYaw.v[139];
  workYaw.d[299] = workYaw.v[299];
  if (workYaw.d[299] > 0)
    workYaw.d[299] = -settingsYaw.kkt_reg;
  else
    workYaw.d[299] -= settingsYaw.kkt_reg;
  workYaw.d_inv[299] = 1/workYaw.d[299];
  workYaw.L[571] = (workYaw.KKT[598])*workYaw.d_inv[299];
  workYaw.v[140] = workYaw.L[139]*workYaw.d[140];
  workYaw.v[300] = workYaw.KKT[599]-workYaw.L[139]*workYaw.v[140];
  workYaw.d[300] = workYaw.v[300];
  if (workYaw.d[300] > 0)
    workYaw.d[300] = -settingsYaw.kkt_reg;
  else
    workYaw.d[300] -= settingsYaw.kkt_reg;
  workYaw.d_inv[300] = 1/workYaw.d[300];
  workYaw.L[591] = (workYaw.KKT[600])*workYaw.d_inv[300];
  workYaw.v[141] = workYaw.L[140]*workYaw.d[141];
  workYaw.v[301] = workYaw.KKT[601]-workYaw.L[140]*workYaw.v[141];
  workYaw.d[301] = workYaw.v[301];
  if (workYaw.d[301] > 0)
    workYaw.d[301] = -settingsYaw.kkt_reg;
  else
    workYaw.d[301] -= settingsYaw.kkt_reg;
  workYaw.d_inv[301] = 1/workYaw.d[301];
  workYaw.L[611] = (workYaw.KKT[602])*workYaw.d_inv[301];
  workYaw.v[142] = workYaw.L[141]*workYaw.d[142];
  workYaw.v[302] = workYaw.KKT[603]-workYaw.L[141]*workYaw.v[142];
  workYaw.d[302] = workYaw.v[302];
  if (workYaw.d[302] > 0)
    workYaw.d[302] = -settingsYaw.kkt_reg;
  else
    workYaw.d[302] -= settingsYaw.kkt_reg;
  workYaw.d_inv[302] = 1/workYaw.d[302];
  workYaw.L[631] = (workYaw.KKT[604])*workYaw.d_inv[302];
  workYaw.v[143] = workYaw.L[142]*workYaw.d[143];
  workYaw.v[303] = workYaw.KKT[605]-workYaw.L[142]*workYaw.v[143];
  workYaw.d[303] = workYaw.v[303];
  if (workYaw.d[303] > 0)
    workYaw.d[303] = -settingsYaw.kkt_reg;
  else
    workYaw.d[303] -= settingsYaw.kkt_reg;
  workYaw.d_inv[303] = 1/workYaw.d[303];
  workYaw.L[651] = (workYaw.KKT[606])*workYaw.d_inv[303];
  workYaw.v[144] = workYaw.L[143]*workYaw.d[144];
  workYaw.v[304] = workYaw.KKT[607]-workYaw.L[143]*workYaw.v[144];
  workYaw.d[304] = workYaw.v[304];
  if (workYaw.d[304] > 0)
    workYaw.d[304] = -settingsYaw.kkt_reg;
  else
    workYaw.d[304] -= settingsYaw.kkt_reg;
  workYaw.d_inv[304] = 1/workYaw.d[304];
  workYaw.L[671] = (workYaw.KKT[608])*workYaw.d_inv[304];
  workYaw.v[145] = workYaw.L[144]*workYaw.d[145];
  workYaw.v[305] = workYaw.KKT[609]-workYaw.L[144]*workYaw.v[145];
  workYaw.d[305] = workYaw.v[305];
  if (workYaw.d[305] > 0)
    workYaw.d[305] = -settingsYaw.kkt_reg;
  else
    workYaw.d[305] -= settingsYaw.kkt_reg;
  workYaw.d_inv[305] = 1/workYaw.d[305];
  workYaw.L[691] = (workYaw.KKT[610])*workYaw.d_inv[305];
  workYaw.v[146] = workYaw.L[145]*workYaw.d[146];
  workYaw.v[306] = workYaw.KKT[611]-workYaw.L[145]*workYaw.v[146];
  workYaw.d[306] = workYaw.v[306];
  if (workYaw.d[306] > 0)
    workYaw.d[306] = -settingsYaw.kkt_reg;
  else
    workYaw.d[306] -= settingsYaw.kkt_reg;
  workYaw.d_inv[306] = 1/workYaw.d[306];
  workYaw.L[711] = (workYaw.KKT[612])*workYaw.d_inv[306];
  workYaw.v[147] = workYaw.L[146]*workYaw.d[147];
  workYaw.v[307] = workYaw.KKT[613]-workYaw.L[146]*workYaw.v[147];
  workYaw.d[307] = workYaw.v[307];
  if (workYaw.d[307] > 0)
    workYaw.d[307] = -settingsYaw.kkt_reg;
  else
    workYaw.d[307] -= settingsYaw.kkt_reg;
  workYaw.d_inv[307] = 1/workYaw.d[307];
  workYaw.L[731] = (workYaw.KKT[614])*workYaw.d_inv[307];
  workYaw.v[148] = workYaw.L[147]*workYaw.d[148];
  workYaw.v[308] = workYaw.KKT[615]-workYaw.L[147]*workYaw.v[148];
  workYaw.d[308] = workYaw.v[308];
  if (workYaw.d[308] > 0)
    workYaw.d[308] = -settingsYaw.kkt_reg;
  else
    workYaw.d[308] -= settingsYaw.kkt_reg;
  workYaw.d_inv[308] = 1/workYaw.d[308];
  workYaw.L[751] = (workYaw.KKT[616])*workYaw.d_inv[308];
  workYaw.v[149] = workYaw.L[148]*workYaw.d[149];
  workYaw.v[309] = workYaw.KKT[617]-workYaw.L[148]*workYaw.v[149];
  workYaw.d[309] = workYaw.v[309];
  if (workYaw.d[309] > 0)
    workYaw.d[309] = -settingsYaw.kkt_reg;
  else
    workYaw.d[309] -= settingsYaw.kkt_reg;
  workYaw.d_inv[309] = 1/workYaw.d[309];
  workYaw.L[771] = (workYaw.KKT[618])*workYaw.d_inv[309];
  workYaw.v[150] = workYaw.L[149]*workYaw.d[150];
  workYaw.v[310] = workYaw.KKT[619]-workYaw.L[149]*workYaw.v[150];
  workYaw.d[310] = workYaw.v[310];
  if (workYaw.d[310] > 0)
    workYaw.d[310] = -settingsYaw.kkt_reg;
  else
    workYaw.d[310] -= settingsYaw.kkt_reg;
  workYaw.d_inv[310] = 1/workYaw.d[310];
  workYaw.L[791] = (workYaw.KKT[620])*workYaw.d_inv[310];
  workYaw.v[151] = workYaw.L[150]*workYaw.d[151];
  workYaw.v[311] = workYaw.KKT[621]-workYaw.L[150]*workYaw.v[151];
  workYaw.d[311] = workYaw.v[311];
  if (workYaw.d[311] > 0)
    workYaw.d[311] = -settingsYaw.kkt_reg;
  else
    workYaw.d[311] -= settingsYaw.kkt_reg;
  workYaw.d_inv[311] = 1/workYaw.d[311];
  workYaw.L[811] = (workYaw.KKT[622])*workYaw.d_inv[311];
  workYaw.v[152] = workYaw.L[151]*workYaw.d[152];
  workYaw.v[312] = workYaw.KKT[623]-workYaw.L[151]*workYaw.v[152];
  workYaw.d[312] = workYaw.v[312];
  if (workYaw.d[312] > 0)
    workYaw.d[312] = -settingsYaw.kkt_reg;
  else
    workYaw.d[312] -= settingsYaw.kkt_reg;
  workYaw.d_inv[312] = 1/workYaw.d[312];
  workYaw.L[831] = (workYaw.KKT[624])*workYaw.d_inv[312];
  workYaw.v[153] = workYaw.L[152]*workYaw.d[153];
  workYaw.v[313] = workYaw.KKT[625]-workYaw.L[152]*workYaw.v[153];
  workYaw.d[313] = workYaw.v[313];
  if (workYaw.d[313] > 0)
    workYaw.d[313] = -settingsYaw.kkt_reg;
  else
    workYaw.d[313] -= settingsYaw.kkt_reg;
  workYaw.d_inv[313] = 1/workYaw.d[313];
  workYaw.L[851] = (workYaw.KKT[626])*workYaw.d_inv[313];
  workYaw.v[154] = workYaw.L[153]*workYaw.d[154];
  workYaw.v[314] = workYaw.KKT[627]-workYaw.L[153]*workYaw.v[154];
  workYaw.d[314] = workYaw.v[314];
  if (workYaw.d[314] > 0)
    workYaw.d[314] = -settingsYaw.kkt_reg;
  else
    workYaw.d[314] -= settingsYaw.kkt_reg;
  workYaw.d_inv[314] = 1/workYaw.d[314];
  workYaw.L[871] = (workYaw.KKT[628])*workYaw.d_inv[314];
  workYaw.v[155] = workYaw.L[154]*workYaw.d[155];
  workYaw.v[315] = workYaw.KKT[629]-workYaw.L[154]*workYaw.v[155];
  workYaw.d[315] = workYaw.v[315];
  if (workYaw.d[315] > 0)
    workYaw.d[315] = -settingsYaw.kkt_reg;
  else
    workYaw.d[315] -= settingsYaw.kkt_reg;
  workYaw.d_inv[315] = 1/workYaw.d[315];
  workYaw.L[891] = (workYaw.KKT[630])*workYaw.d_inv[315];
  workYaw.v[156] = workYaw.L[155]*workYaw.d[156];
  workYaw.v[316] = workYaw.KKT[631]-workYaw.L[155]*workYaw.v[156];
  workYaw.d[316] = workYaw.v[316];
  if (workYaw.d[316] > 0)
    workYaw.d[316] = -settingsYaw.kkt_reg;
  else
    workYaw.d[316] -= settingsYaw.kkt_reg;
  workYaw.d_inv[316] = 1/workYaw.d[316];
  workYaw.L[911] = (workYaw.KKT[632])*workYaw.d_inv[316];
  workYaw.v[157] = workYaw.L[156]*workYaw.d[157];
  workYaw.v[317] = workYaw.KKT[633]-workYaw.L[156]*workYaw.v[157];
  workYaw.d[317] = workYaw.v[317];
  if (workYaw.d[317] > 0)
    workYaw.d[317] = -settingsYaw.kkt_reg;
  else
    workYaw.d[317] -= settingsYaw.kkt_reg;
  workYaw.d_inv[317] = 1/workYaw.d[317];
  workYaw.L[931] = (workYaw.KKT[634])*workYaw.d_inv[317];
  workYaw.v[158] = workYaw.L[157]*workYaw.d[158];
  workYaw.v[318] = workYaw.KKT[635]-workYaw.L[157]*workYaw.v[158];
  workYaw.d[318] = workYaw.v[318];
  if (workYaw.d[318] > 0)
    workYaw.d[318] = -settingsYaw.kkt_reg;
  else
    workYaw.d[318] -= settingsYaw.kkt_reg;
  workYaw.d_inv[318] = 1/workYaw.d[318];
  workYaw.L[957] = (workYaw.KKT[636])*workYaw.d_inv[318];
  workYaw.v[159] = workYaw.L[158]*workYaw.d[159];
  workYaw.v[319] = workYaw.KKT[637]-workYaw.L[158]*workYaw.v[159];
  workYaw.d[319] = workYaw.v[319];
  if (workYaw.d[319] > 0)
    workYaw.d[319] = -settingsYaw.kkt_reg;
  else
    workYaw.d[319] -= settingsYaw.kkt_reg;
  workYaw.d_inv[319] = 1/workYaw.d[319];
  workYaw.L[169] = (workYaw.KKT[638])*workYaw.d_inv[319];
  workYaw.v[160] = workYaw.L[159]*workYaw.d[160];
  workYaw.v[320] = workYaw.KKT[639]-workYaw.L[159]*workYaw.v[160];
  workYaw.d[320] = workYaw.v[320];
  if (workYaw.d[320] > 0)
    workYaw.d[320] = -settingsYaw.kkt_reg;
  else
    workYaw.d[320] -= settingsYaw.kkt_reg;
  workYaw.d_inv[320] = 1/workYaw.d[320];
  workYaw.L[162] = (workYaw.KKT[640])*workYaw.d_inv[320];
  workYaw.v[321] = 0;
  workYaw.d[321] = workYaw.v[321];
  if (workYaw.d[321] > 0)
    workYaw.d[321] = -settingsYaw.kkt_reg;
  else
    workYaw.d[321] -= settingsYaw.kkt_reg;
  workYaw.d_inv[321] = 1/workYaw.d[321];
  workYaw.L[165] = (workYaw.KKT[641])*workYaw.d_inv[321];
  workYaw.v[322] = 0;
  workYaw.d[322] = workYaw.v[322];
  if (workYaw.d[322] > 0)
    workYaw.d[322] = -settingsYaw.kkt_reg;
  else
    workYaw.d[322] -= settingsYaw.kkt_reg;
  workYaw.d_inv[322] = 1/workYaw.d[322];
  workYaw.L[217] = (workYaw.KKT[642])*workYaw.d_inv[322];
  workYaw.v[323] = 0;
  workYaw.d[323] = workYaw.v[323];
  if (workYaw.d[323] < 0)
    workYaw.d[323] = settingsYaw.kkt_reg;
  else
    workYaw.d[323] += settingsYaw.kkt_reg;
  workYaw.d_inv[323] = 1/workYaw.d[323];
  workYaw.L[160] = (workYaw.KKT[643])*workYaw.d_inv[323];
  workYaw.v[323] = workYaw.L[160]*workYaw.d[323];
  workYaw.v[324] = 0-workYaw.L[160]*workYaw.v[323];
  workYaw.d[324] = workYaw.v[324];
  if (workYaw.d[324] > 0)
    workYaw.d[324] = -settingsYaw.kkt_reg;
  else
    workYaw.d[324] -= settingsYaw.kkt_reg;
  workYaw.d_inv[324] = 1/workYaw.d[324];
  workYaw.L[221] = (workYaw.KKT[644])*workYaw.d_inv[324];
  workYaw.v[325] = workYaw.KKT[645];
  workYaw.d[325] = workYaw.v[325];
  if (workYaw.d[325] < 0)
    workYaw.d[325] = settingsYaw.kkt_reg;
  else
    workYaw.d[325] += settingsYaw.kkt_reg;
  workYaw.d_inv[325] = 1/workYaw.d[325];
  workYaw.L[172] = (workYaw.KKT[646])*workYaw.d_inv[325];
  workYaw.v[326] = workYaw.KKT[647];
  workYaw.d[326] = workYaw.v[326];
  if (workYaw.d[326] < 0)
    workYaw.d[326] = settingsYaw.kkt_reg;
  else
    workYaw.d[326] += settingsYaw.kkt_reg;
  workYaw.d_inv[326] = 1/workYaw.d[326];
  workYaw.L[173] = (workYaw.KKT[648])*workYaw.d_inv[326];
  workYaw.v[327] = workYaw.KKT[649];
  workYaw.d[327] = workYaw.v[327];
  if (workYaw.d[327] < 0)
    workYaw.d[327] = settingsYaw.kkt_reg;
  else
    workYaw.d[327] += settingsYaw.kkt_reg;
  workYaw.d_inv[327] = 1/workYaw.d[327];
  workYaw.L[174] = (workYaw.KKT[650])*workYaw.d_inv[327];
  workYaw.v[328] = workYaw.KKT[651];
  workYaw.d[328] = workYaw.v[328];
  if (workYaw.d[328] < 0)
    workYaw.d[328] = settingsYaw.kkt_reg;
  else
    workYaw.d[328] += settingsYaw.kkt_reg;
  workYaw.d_inv[328] = 1/workYaw.d[328];
  workYaw.L[175] = (workYaw.KKT[652])*workYaw.d_inv[328];
  workYaw.v[329] = workYaw.KKT[653];
  workYaw.d[329] = workYaw.v[329];
  if (workYaw.d[329] < 0)
    workYaw.d[329] = settingsYaw.kkt_reg;
  else
    workYaw.d[329] += settingsYaw.kkt_reg;
  workYaw.d_inv[329] = 1/workYaw.d[329];
  workYaw.L[176] = (workYaw.KKT[654])*workYaw.d_inv[329];
  workYaw.v[330] = workYaw.KKT[655];
  workYaw.d[330] = workYaw.v[330];
  if (workYaw.d[330] < 0)
    workYaw.d[330] = settingsYaw.kkt_reg;
  else
    workYaw.d[330] += settingsYaw.kkt_reg;
  workYaw.d_inv[330] = 1/workYaw.d[330];
  workYaw.L[177] = (workYaw.KKT[656])*workYaw.d_inv[330];
  workYaw.v[331] = workYaw.KKT[657];
  workYaw.d[331] = workYaw.v[331];
  if (workYaw.d[331] < 0)
    workYaw.d[331] = settingsYaw.kkt_reg;
  else
    workYaw.d[331] += settingsYaw.kkt_reg;
  workYaw.d_inv[331] = 1/workYaw.d[331];
  workYaw.L[178] = (workYaw.KKT[658])*workYaw.d_inv[331];
  workYaw.v[332] = workYaw.KKT[659];
  workYaw.d[332] = workYaw.v[332];
  if (workYaw.d[332] < 0)
    workYaw.d[332] = settingsYaw.kkt_reg;
  else
    workYaw.d[332] += settingsYaw.kkt_reg;
  workYaw.d_inv[332] = 1/workYaw.d[332];
  workYaw.L[179] = (workYaw.KKT[660])*workYaw.d_inv[332];
  workYaw.v[333] = workYaw.KKT[661];
  workYaw.d[333] = workYaw.v[333];
  if (workYaw.d[333] < 0)
    workYaw.d[333] = settingsYaw.kkt_reg;
  else
    workYaw.d[333] += settingsYaw.kkt_reg;
  workYaw.d_inv[333] = 1/workYaw.d[333];
  workYaw.L[180] = (workYaw.KKT[662])*workYaw.d_inv[333];
  workYaw.v[334] = workYaw.KKT[663];
  workYaw.d[334] = workYaw.v[334];
  if (workYaw.d[334] < 0)
    workYaw.d[334] = settingsYaw.kkt_reg;
  else
    workYaw.d[334] += settingsYaw.kkt_reg;
  workYaw.d_inv[334] = 1/workYaw.d[334];
  workYaw.L[181] = (workYaw.KKT[664])*workYaw.d_inv[334];
  workYaw.v[335] = workYaw.KKT[665];
  workYaw.d[335] = workYaw.v[335];
  if (workYaw.d[335] < 0)
    workYaw.d[335] = settingsYaw.kkt_reg;
  else
    workYaw.d[335] += settingsYaw.kkt_reg;
  workYaw.d_inv[335] = 1/workYaw.d[335];
  workYaw.L[182] = (workYaw.KKT[666])*workYaw.d_inv[335];
  workYaw.v[336] = workYaw.KKT[667];
  workYaw.d[336] = workYaw.v[336];
  if (workYaw.d[336] < 0)
    workYaw.d[336] = settingsYaw.kkt_reg;
  else
    workYaw.d[336] += settingsYaw.kkt_reg;
  workYaw.d_inv[336] = 1/workYaw.d[336];
  workYaw.L[183] = (workYaw.KKT[668])*workYaw.d_inv[336];
  workYaw.v[337] = workYaw.KKT[669];
  workYaw.d[337] = workYaw.v[337];
  if (workYaw.d[337] < 0)
    workYaw.d[337] = settingsYaw.kkt_reg;
  else
    workYaw.d[337] += settingsYaw.kkt_reg;
  workYaw.d_inv[337] = 1/workYaw.d[337];
  workYaw.L[184] = (workYaw.KKT[670])*workYaw.d_inv[337];
  workYaw.v[338] = workYaw.KKT[671];
  workYaw.d[338] = workYaw.v[338];
  if (workYaw.d[338] < 0)
    workYaw.d[338] = settingsYaw.kkt_reg;
  else
    workYaw.d[338] += settingsYaw.kkt_reg;
  workYaw.d_inv[338] = 1/workYaw.d[338];
  workYaw.L[185] = (workYaw.KKT[672])*workYaw.d_inv[338];
  workYaw.v[339] = workYaw.KKT[673];
  workYaw.d[339] = workYaw.v[339];
  if (workYaw.d[339] < 0)
    workYaw.d[339] = settingsYaw.kkt_reg;
  else
    workYaw.d[339] += settingsYaw.kkt_reg;
  workYaw.d_inv[339] = 1/workYaw.d[339];
  workYaw.L[186] = (workYaw.KKT[674])*workYaw.d_inv[339];
  workYaw.v[340] = workYaw.KKT[675];
  workYaw.d[340] = workYaw.v[340];
  if (workYaw.d[340] < 0)
    workYaw.d[340] = settingsYaw.kkt_reg;
  else
    workYaw.d[340] += settingsYaw.kkt_reg;
  workYaw.d_inv[340] = 1/workYaw.d[340];
  workYaw.L[187] = (workYaw.KKT[676])*workYaw.d_inv[340];
  workYaw.v[341] = workYaw.KKT[677];
  workYaw.d[341] = workYaw.v[341];
  if (workYaw.d[341] < 0)
    workYaw.d[341] = settingsYaw.kkt_reg;
  else
    workYaw.d[341] += settingsYaw.kkt_reg;
  workYaw.d_inv[341] = 1/workYaw.d[341];
  workYaw.L[188] = (workYaw.KKT[678])*workYaw.d_inv[341];
  workYaw.v[342] = workYaw.KKT[679];
  workYaw.d[342] = workYaw.v[342];
  if (workYaw.d[342] < 0)
    workYaw.d[342] = settingsYaw.kkt_reg;
  else
    workYaw.d[342] += settingsYaw.kkt_reg;
  workYaw.d_inv[342] = 1/workYaw.d[342];
  workYaw.L[189] = (workYaw.KKT[680])*workYaw.d_inv[342];
  workYaw.v[343] = workYaw.KKT[681];
  workYaw.d[343] = workYaw.v[343];
  if (workYaw.d[343] < 0)
    workYaw.d[343] = settingsYaw.kkt_reg;
  else
    workYaw.d[343] += settingsYaw.kkt_reg;
  workYaw.d_inv[343] = 1/workYaw.d[343];
  workYaw.L[190] = (workYaw.KKT[682])*workYaw.d_inv[343];
  workYaw.v[344] = workYaw.KKT[683];
  workYaw.d[344] = workYaw.v[344];
  if (workYaw.d[344] < 0)
    workYaw.d[344] = settingsYaw.kkt_reg;
  else
    workYaw.d[344] += settingsYaw.kkt_reg;
  workYaw.d_inv[344] = 1/workYaw.d[344];
  workYaw.L[191] = (workYaw.KKT[684])*workYaw.d_inv[344];
  workYaw.v[345] = workYaw.KKT[685];
  workYaw.d[345] = workYaw.v[345];
  if (workYaw.d[345] < 0)
    workYaw.d[345] = settingsYaw.kkt_reg;
  else
    workYaw.d[345] += settingsYaw.kkt_reg;
  workYaw.d_inv[345] = 1/workYaw.d[345];
  workYaw.L[192] = (workYaw.KKT[686])*workYaw.d_inv[345];
  workYaw.v[346] = workYaw.KKT[687];
  workYaw.d[346] = workYaw.v[346];
  if (workYaw.d[346] < 0)
    workYaw.d[346] = settingsYaw.kkt_reg;
  else
    workYaw.d[346] += settingsYaw.kkt_reg;
  workYaw.d_inv[346] = 1/workYaw.d[346];
  workYaw.L[193] = (workYaw.KKT[688])*workYaw.d_inv[346];
  workYaw.v[347] = workYaw.KKT[689];
  workYaw.d[347] = workYaw.v[347];
  if (workYaw.d[347] < 0)
    workYaw.d[347] = settingsYaw.kkt_reg;
  else
    workYaw.d[347] += settingsYaw.kkt_reg;
  workYaw.d_inv[347] = 1/workYaw.d[347];
  workYaw.L[194] = (workYaw.KKT[690])*workYaw.d_inv[347];
  workYaw.v[348] = workYaw.KKT[691];
  workYaw.d[348] = workYaw.v[348];
  if (workYaw.d[348] < 0)
    workYaw.d[348] = settingsYaw.kkt_reg;
  else
    workYaw.d[348] += settingsYaw.kkt_reg;
  workYaw.d_inv[348] = 1/workYaw.d[348];
  workYaw.L[195] = (workYaw.KKT[692])*workYaw.d_inv[348];
  workYaw.v[349] = workYaw.KKT[693];
  workYaw.d[349] = workYaw.v[349];
  if (workYaw.d[349] < 0)
    workYaw.d[349] = settingsYaw.kkt_reg;
  else
    workYaw.d[349] += settingsYaw.kkt_reg;
  workYaw.d_inv[349] = 1/workYaw.d[349];
  workYaw.L[196] = (workYaw.KKT[694])*workYaw.d_inv[349];
  workYaw.v[350] = workYaw.KKT[695];
  workYaw.d[350] = workYaw.v[350];
  if (workYaw.d[350] < 0)
    workYaw.d[350] = settingsYaw.kkt_reg;
  else
    workYaw.d[350] += settingsYaw.kkt_reg;
  workYaw.d_inv[350] = 1/workYaw.d[350];
  workYaw.L[197] = (workYaw.KKT[696])*workYaw.d_inv[350];
  workYaw.v[351] = workYaw.KKT[697];
  workYaw.d[351] = workYaw.v[351];
  if (workYaw.d[351] < 0)
    workYaw.d[351] = settingsYaw.kkt_reg;
  else
    workYaw.d[351] += settingsYaw.kkt_reg;
  workYaw.d_inv[351] = 1/workYaw.d[351];
  workYaw.L[198] = (workYaw.KKT[698])*workYaw.d_inv[351];
  workYaw.v[352] = workYaw.KKT[699];
  workYaw.d[352] = workYaw.v[352];
  if (workYaw.d[352] < 0)
    workYaw.d[352] = settingsYaw.kkt_reg;
  else
    workYaw.d[352] += settingsYaw.kkt_reg;
  workYaw.d_inv[352] = 1/workYaw.d[352];
  workYaw.L[199] = (workYaw.KKT[700])*workYaw.d_inv[352];
  workYaw.v[353] = workYaw.KKT[701];
  workYaw.d[353] = workYaw.v[353];
  if (workYaw.d[353] < 0)
    workYaw.d[353] = settingsYaw.kkt_reg;
  else
    workYaw.d[353] += settingsYaw.kkt_reg;
  workYaw.d_inv[353] = 1/workYaw.d[353];
  workYaw.L[200] = (workYaw.KKT[702])*workYaw.d_inv[353];
  workYaw.v[354] = workYaw.KKT[703];
  workYaw.d[354] = workYaw.v[354];
  if (workYaw.d[354] < 0)
    workYaw.d[354] = settingsYaw.kkt_reg;
  else
    workYaw.d[354] += settingsYaw.kkt_reg;
  workYaw.d_inv[354] = 1/workYaw.d[354];
  workYaw.L[201] = (workYaw.KKT[704])*workYaw.d_inv[354];
  workYaw.v[355] = workYaw.KKT[705];
  workYaw.d[355] = workYaw.v[355];
  if (workYaw.d[355] < 0)
    workYaw.d[355] = settingsYaw.kkt_reg;
  else
    workYaw.d[355] += settingsYaw.kkt_reg;
  workYaw.d_inv[355] = 1/workYaw.d[355];
  workYaw.L[202] = (workYaw.KKT[706])*workYaw.d_inv[355];
  workYaw.v[356] = workYaw.KKT[707];
  workYaw.d[356] = workYaw.v[356];
  if (workYaw.d[356] < 0)
    workYaw.d[356] = settingsYaw.kkt_reg;
  else
    workYaw.d[356] += settingsYaw.kkt_reg;
  workYaw.d_inv[356] = 1/workYaw.d[356];
  workYaw.L[203] = (workYaw.KKT[708])*workYaw.d_inv[356];
  workYaw.v[357] = workYaw.KKT[709];
  workYaw.d[357] = workYaw.v[357];
  if (workYaw.d[357] < 0)
    workYaw.d[357] = settingsYaw.kkt_reg;
  else
    workYaw.d[357] += settingsYaw.kkt_reg;
  workYaw.d_inv[357] = 1/workYaw.d[357];
  workYaw.L[204] = (workYaw.KKT[710])*workYaw.d_inv[357];
  workYaw.v[358] = workYaw.KKT[711];
  workYaw.d[358] = workYaw.v[358];
  if (workYaw.d[358] < 0)
    workYaw.d[358] = settingsYaw.kkt_reg;
  else
    workYaw.d[358] += settingsYaw.kkt_reg;
  workYaw.d_inv[358] = 1/workYaw.d[358];
  workYaw.L[205] = (workYaw.KKT[712])*workYaw.d_inv[358];
  workYaw.v[359] = workYaw.KKT[713];
  workYaw.d[359] = workYaw.v[359];
  if (workYaw.d[359] < 0)
    workYaw.d[359] = settingsYaw.kkt_reg;
  else
    workYaw.d[359] += settingsYaw.kkt_reg;
  workYaw.d_inv[359] = 1/workYaw.d[359];
  workYaw.L[206] = (workYaw.KKT[714])*workYaw.d_inv[359];
  workYaw.v[360] = workYaw.KKT[715];
  workYaw.d[360] = workYaw.v[360];
  if (workYaw.d[360] < 0)
    workYaw.d[360] = settingsYaw.kkt_reg;
  else
    workYaw.d[360] += settingsYaw.kkt_reg;
  workYaw.d_inv[360] = 1/workYaw.d[360];
  workYaw.L[207] = (workYaw.KKT[716])*workYaw.d_inv[360];
  workYaw.v[361] = workYaw.KKT[717];
  workYaw.d[361] = workYaw.v[361];
  if (workYaw.d[361] < 0)
    workYaw.d[361] = settingsYaw.kkt_reg;
  else
    workYaw.d[361] += settingsYaw.kkt_reg;
  workYaw.d_inv[361] = 1/workYaw.d[361];
  workYaw.L[208] = (workYaw.KKT[718])*workYaw.d_inv[361];
  workYaw.v[362] = workYaw.KKT[719];
  workYaw.d[362] = workYaw.v[362];
  if (workYaw.d[362] < 0)
    workYaw.d[362] = settingsYaw.kkt_reg;
  else
    workYaw.d[362] += settingsYaw.kkt_reg;
  workYaw.d_inv[362] = 1/workYaw.d[362];
  workYaw.L[209] = (workYaw.KKT[720])*workYaw.d_inv[362];
  workYaw.v[363] = workYaw.KKT[721];
  workYaw.d[363] = workYaw.v[363];
  if (workYaw.d[363] < 0)
    workYaw.d[363] = settingsYaw.kkt_reg;
  else
    workYaw.d[363] += settingsYaw.kkt_reg;
  workYaw.d_inv[363] = 1/workYaw.d[363];
  workYaw.L[163] = (workYaw.KKT[722])*workYaw.d_inv[363];
  workYaw.v[280] = workYaw.L[161]*workYaw.d[280];
  workYaw.v[320] = workYaw.L[162]*workYaw.d[320];
  workYaw.v[364] = workYaw.KKT[723]-workYaw.L[161]*workYaw.v[280]-workYaw.L[162]*workYaw.v[320];
  workYaw.d[364] = workYaw.v[364];
  if (workYaw.d[364] < 0)
    workYaw.d[364] = settingsYaw.kkt_reg;
  else
    workYaw.d[364] += settingsYaw.kkt_reg;
  workYaw.d_inv[364] = 1/workYaw.d[364];
  workYaw.L[164] = (workYaw.KKT[724])*workYaw.d_inv[364];
  workYaw.v[363] = workYaw.L[163]*workYaw.d[363];
  workYaw.v[364] = workYaw.L[164]*workYaw.d[364];
  workYaw.v[365] = 0-workYaw.L[163]*workYaw.v[363]-workYaw.L[164]*workYaw.v[364];
  workYaw.d[365] = workYaw.v[365];
  if (workYaw.d[365] > 0)
    workYaw.d[365] = -settingsYaw.kkt_reg;
  else
    workYaw.d[365] -= settingsYaw.kkt_reg;
  workYaw.d_inv[365] = 1/workYaw.d[365];
  workYaw.L[170] = (workYaw.KKT[725])*workYaw.d_inv[365];
  workYaw.v[321] = workYaw.L[165]*workYaw.d[321];
  workYaw.v[366] = workYaw.KKT[726]-workYaw.L[165]*workYaw.v[321];
  workYaw.d[366] = workYaw.v[366];
  if (workYaw.d[366] < 0)
    workYaw.d[366] = settingsYaw.kkt_reg;
  else
    workYaw.d[366] += settingsYaw.kkt_reg;
  workYaw.d_inv[366] = 1/workYaw.d[366];
  workYaw.L[171] = (workYaw.KKT[727])*workYaw.d_inv[366];
  workYaw.v[367] = workYaw.KKT[728];
  workYaw.d[367] = workYaw.v[367];
  if (workYaw.d[367] < 0)
    workYaw.d[367] = settingsYaw.kkt_reg;
  else
    workYaw.d[367] += settingsYaw.kkt_reg;
  workYaw.d_inv[367] = 1/workYaw.d[367];
  workYaw.L[211] = (workYaw.KKT[729])*workYaw.d_inv[367];
  workYaw.v[200] = workYaw.L[166]*workYaw.d[200];
  workYaw.v[240] = workYaw.L[167]*workYaw.d[240];
  workYaw.v[368] = workYaw.KKT[730]-workYaw.L[166]*workYaw.v[200]-workYaw.L[167]*workYaw.v[240];
  workYaw.d[368] = workYaw.v[368];
  if (workYaw.d[368] < 0)
    workYaw.d[368] = settingsYaw.kkt_reg;
  else
    workYaw.d[368] += settingsYaw.kkt_reg;
  workYaw.d_inv[368] = 1/workYaw.d[368];
  workYaw.L[212] = (workYaw.KKT[731])*workYaw.d_inv[368];
  workYaw.v[279] = workYaw.L[168]*workYaw.d[279];
  workYaw.v[319] = workYaw.L[169]*workYaw.d[319];
  workYaw.v[365] = workYaw.L[170]*workYaw.d[365];
  workYaw.v[369] = workYaw.KKT[732]-workYaw.L[168]*workYaw.v[279]-workYaw.L[169]*workYaw.v[319]-workYaw.L[170]*workYaw.v[365];
  workYaw.d[369] = workYaw.v[369];
  if (workYaw.d[369] < 0)
    workYaw.d[369] = settingsYaw.kkt_reg;
  else
    workYaw.d[369] += settingsYaw.kkt_reg;
  workYaw.d_inv[369] = 1/workYaw.d[369];
  workYaw.L[210] = (workYaw.KKT[733])*workYaw.d_inv[369];
  workYaw.L[213] = (workYaw.KKT[734])*workYaw.d_inv[369];
  workYaw.v[366] = workYaw.L[171]*workYaw.d[366];
  workYaw.v[370] = 0-workYaw.L[171]*workYaw.v[366];
  workYaw.d[370] = workYaw.v[370];
  if (workYaw.d[370] > 0)
    workYaw.d[370] = -settingsYaw.kkt_reg;
  else
    workYaw.d[370] -= settingsYaw.kkt_reg;
  workYaw.d_inv[370] = 1/workYaw.d[370];
  workYaw.L[218] = (workYaw.KKT[735])*workYaw.d_inv[370];
  workYaw.L[223] = (workYaw.KKT[736])*workYaw.d_inv[370];
  workYaw.v[325] = workYaw.L[172]*workYaw.d[325];
  workYaw.v[371] = 0-workYaw.L[172]*workYaw.v[325];
  workYaw.d[371] = workYaw.v[371];
  if (workYaw.d[371] > 0)
    workYaw.d[371] = -settingsYaw.kkt_reg;
  else
    workYaw.d[371] -= settingsYaw.kkt_reg;
  workYaw.d_inv[371] = 1/workYaw.d[371];
  workYaw.L[222] = (workYaw.KKT[737])*workYaw.d_inv[371];
  workYaw.L[234] = (workYaw.KKT[738])*workYaw.d_inv[371];
  workYaw.v[326] = workYaw.L[173]*workYaw.d[326];
  workYaw.v[372] = 0-workYaw.L[173]*workYaw.v[326];
  workYaw.d[372] = workYaw.v[372];
  if (workYaw.d[372] > 0)
    workYaw.d[372] = -settingsYaw.kkt_reg;
  else
    workYaw.d[372] -= settingsYaw.kkt_reg;
  workYaw.d_inv[372] = 1/workYaw.d[372];
  workYaw.L[235] = (workYaw.KKT[739])*workYaw.d_inv[372];
  workYaw.L[252] = (workYaw.KKT[740])*workYaw.d_inv[372];
  workYaw.v[327] = workYaw.L[174]*workYaw.d[327];
  workYaw.v[373] = 0-workYaw.L[174]*workYaw.v[327];
  workYaw.d[373] = workYaw.v[373];
  if (workYaw.d[373] > 0)
    workYaw.d[373] = -settingsYaw.kkt_reg;
  else
    workYaw.d[373] -= settingsYaw.kkt_reg;
  workYaw.d_inv[373] = 1/workYaw.d[373];
  workYaw.L[253] = (workYaw.KKT[741])*workYaw.d_inv[373];
  workYaw.L[272] = (workYaw.KKT[742])*workYaw.d_inv[373];
  workYaw.v[328] = workYaw.L[175]*workYaw.d[328];
  workYaw.v[374] = 0-workYaw.L[175]*workYaw.v[328];
  workYaw.d[374] = workYaw.v[374];
  if (workYaw.d[374] > 0)
    workYaw.d[374] = -settingsYaw.kkt_reg;
  else
    workYaw.d[374] -= settingsYaw.kkt_reg;
  workYaw.d_inv[374] = 1/workYaw.d[374];
  workYaw.L[273] = (workYaw.KKT[743])*workYaw.d_inv[374];
  workYaw.L[292] = (workYaw.KKT[744])*workYaw.d_inv[374];
  workYaw.v[329] = workYaw.L[176]*workYaw.d[329];
  workYaw.v[375] = 0-workYaw.L[176]*workYaw.v[329];
  workYaw.d[375] = workYaw.v[375];
  if (workYaw.d[375] > 0)
    workYaw.d[375] = -settingsYaw.kkt_reg;
  else
    workYaw.d[375] -= settingsYaw.kkt_reg;
  workYaw.d_inv[375] = 1/workYaw.d[375];
  workYaw.L[293] = (workYaw.KKT[745])*workYaw.d_inv[375];
  workYaw.L[312] = (workYaw.KKT[746])*workYaw.d_inv[375];
  workYaw.v[330] = workYaw.L[177]*workYaw.d[330];
  workYaw.v[376] = 0-workYaw.L[177]*workYaw.v[330];
  workYaw.d[376] = workYaw.v[376];
  if (workYaw.d[376] > 0)
    workYaw.d[376] = -settingsYaw.kkt_reg;
  else
    workYaw.d[376] -= settingsYaw.kkt_reg;
  workYaw.d_inv[376] = 1/workYaw.d[376];
  workYaw.L[313] = (workYaw.KKT[747])*workYaw.d_inv[376];
  workYaw.L[332] = (workYaw.KKT[748])*workYaw.d_inv[376];
  workYaw.v[331] = workYaw.L[178]*workYaw.d[331];
  workYaw.v[377] = 0-workYaw.L[178]*workYaw.v[331];
  workYaw.d[377] = workYaw.v[377];
  if (workYaw.d[377] > 0)
    workYaw.d[377] = -settingsYaw.kkt_reg;
  else
    workYaw.d[377] -= settingsYaw.kkt_reg;
  workYaw.d_inv[377] = 1/workYaw.d[377];
  workYaw.L[333] = (workYaw.KKT[749])*workYaw.d_inv[377];
  workYaw.L[352] = (workYaw.KKT[750])*workYaw.d_inv[377];
  workYaw.v[332] = workYaw.L[179]*workYaw.d[332];
  workYaw.v[378] = 0-workYaw.L[179]*workYaw.v[332];
  workYaw.d[378] = workYaw.v[378];
  if (workYaw.d[378] > 0)
    workYaw.d[378] = -settingsYaw.kkt_reg;
  else
    workYaw.d[378] -= settingsYaw.kkt_reg;
  workYaw.d_inv[378] = 1/workYaw.d[378];
  workYaw.L[353] = (workYaw.KKT[751])*workYaw.d_inv[378];
  workYaw.L[372] = (workYaw.KKT[752])*workYaw.d_inv[378];
  workYaw.v[333] = workYaw.L[180]*workYaw.d[333];
  workYaw.v[379] = 0-workYaw.L[180]*workYaw.v[333];
  workYaw.d[379] = workYaw.v[379];
  if (workYaw.d[379] > 0)
    workYaw.d[379] = -settingsYaw.kkt_reg;
  else
    workYaw.d[379] -= settingsYaw.kkt_reg;
  workYaw.d_inv[379] = 1/workYaw.d[379];
  workYaw.L[373] = (workYaw.KKT[753])*workYaw.d_inv[379];
  workYaw.L[392] = (workYaw.KKT[754])*workYaw.d_inv[379];
  workYaw.v[334] = workYaw.L[181]*workYaw.d[334];
  workYaw.v[380] = 0-workYaw.L[181]*workYaw.v[334];
  workYaw.d[380] = workYaw.v[380];
  if (workYaw.d[380] > 0)
    workYaw.d[380] = -settingsYaw.kkt_reg;
  else
    workYaw.d[380] -= settingsYaw.kkt_reg;
  workYaw.d_inv[380] = 1/workYaw.d[380];
  workYaw.L[393] = (workYaw.KKT[755])*workYaw.d_inv[380];
  workYaw.L[412] = (workYaw.KKT[756])*workYaw.d_inv[380];
  workYaw.v[335] = workYaw.L[182]*workYaw.d[335];
  workYaw.v[381] = 0-workYaw.L[182]*workYaw.v[335];
  workYaw.d[381] = workYaw.v[381];
  if (workYaw.d[381] > 0)
    workYaw.d[381] = -settingsYaw.kkt_reg;
  else
    workYaw.d[381] -= settingsYaw.kkt_reg;
  workYaw.d_inv[381] = 1/workYaw.d[381];
  workYaw.L[413] = (workYaw.KKT[757])*workYaw.d_inv[381];
  workYaw.L[432] = (workYaw.KKT[758])*workYaw.d_inv[381];
  workYaw.v[336] = workYaw.L[183]*workYaw.d[336];
  workYaw.v[382] = 0-workYaw.L[183]*workYaw.v[336];
  workYaw.d[382] = workYaw.v[382];
  if (workYaw.d[382] > 0)
    workYaw.d[382] = -settingsYaw.kkt_reg;
  else
    workYaw.d[382] -= settingsYaw.kkt_reg;
  workYaw.d_inv[382] = 1/workYaw.d[382];
  workYaw.L[433] = (workYaw.KKT[759])*workYaw.d_inv[382];
  workYaw.L[452] = (workYaw.KKT[760])*workYaw.d_inv[382];
  workYaw.v[337] = workYaw.L[184]*workYaw.d[337];
  workYaw.v[383] = 0-workYaw.L[184]*workYaw.v[337];
  workYaw.d[383] = workYaw.v[383];
  if (workYaw.d[383] > 0)
    workYaw.d[383] = -settingsYaw.kkt_reg;
  else
    workYaw.d[383] -= settingsYaw.kkt_reg;
  workYaw.d_inv[383] = 1/workYaw.d[383];
  workYaw.L[453] = (workYaw.KKT[761])*workYaw.d_inv[383];
  workYaw.L[472] = (workYaw.KKT[762])*workYaw.d_inv[383];
  workYaw.v[338] = workYaw.L[185]*workYaw.d[338];
  workYaw.v[384] = 0-workYaw.L[185]*workYaw.v[338];
  workYaw.d[384] = workYaw.v[384];
  if (workYaw.d[384] > 0)
    workYaw.d[384] = -settingsYaw.kkt_reg;
  else
    workYaw.d[384] -= settingsYaw.kkt_reg;
  workYaw.d_inv[384] = 1/workYaw.d[384];
  workYaw.L[473] = (workYaw.KKT[763])*workYaw.d_inv[384];
  workYaw.L[492] = (workYaw.KKT[764])*workYaw.d_inv[384];
  workYaw.v[339] = workYaw.L[186]*workYaw.d[339];
  workYaw.v[385] = 0-workYaw.L[186]*workYaw.v[339];
  workYaw.d[385] = workYaw.v[385];
  if (workYaw.d[385] > 0)
    workYaw.d[385] = -settingsYaw.kkt_reg;
  else
    workYaw.d[385] -= settingsYaw.kkt_reg;
  workYaw.d_inv[385] = 1/workYaw.d[385];
  workYaw.L[493] = (workYaw.KKT[765])*workYaw.d_inv[385];
  workYaw.L[512] = (workYaw.KKT[766])*workYaw.d_inv[385];
  workYaw.v[340] = workYaw.L[187]*workYaw.d[340];
  workYaw.v[386] = 0-workYaw.L[187]*workYaw.v[340];
  workYaw.d[386] = workYaw.v[386];
  if (workYaw.d[386] > 0)
    workYaw.d[386] = -settingsYaw.kkt_reg;
  else
    workYaw.d[386] -= settingsYaw.kkt_reg;
  workYaw.d_inv[386] = 1/workYaw.d[386];
  workYaw.L[513] = (workYaw.KKT[767])*workYaw.d_inv[386];
  workYaw.L[532] = (workYaw.KKT[768])*workYaw.d_inv[386];
  workYaw.v[341] = workYaw.L[188]*workYaw.d[341];
  workYaw.v[387] = 0-workYaw.L[188]*workYaw.v[341];
  workYaw.d[387] = workYaw.v[387];
  if (workYaw.d[387] > 0)
    workYaw.d[387] = -settingsYaw.kkt_reg;
  else
    workYaw.d[387] -= settingsYaw.kkt_reg;
  workYaw.d_inv[387] = 1/workYaw.d[387];
  workYaw.L[533] = (workYaw.KKT[769])*workYaw.d_inv[387];
  workYaw.L[552] = (workYaw.KKT[770])*workYaw.d_inv[387];
  workYaw.v[342] = workYaw.L[189]*workYaw.d[342];
  workYaw.v[388] = 0-workYaw.L[189]*workYaw.v[342];
  workYaw.d[388] = workYaw.v[388];
  if (workYaw.d[388] > 0)
    workYaw.d[388] = -settingsYaw.kkt_reg;
  else
    workYaw.d[388] -= settingsYaw.kkt_reg;
  workYaw.d_inv[388] = 1/workYaw.d[388];
  workYaw.L[553] = (workYaw.KKT[771])*workYaw.d_inv[388];
  workYaw.L[572] = (workYaw.KKT[772])*workYaw.d_inv[388];
  workYaw.v[343] = workYaw.L[190]*workYaw.d[343];
  workYaw.v[389] = 0-workYaw.L[190]*workYaw.v[343];
  workYaw.d[389] = workYaw.v[389];
  if (workYaw.d[389] > 0)
    workYaw.d[389] = -settingsYaw.kkt_reg;
  else
    workYaw.d[389] -= settingsYaw.kkt_reg;
  workYaw.d_inv[389] = 1/workYaw.d[389];
  workYaw.L[573] = (workYaw.KKT[773])*workYaw.d_inv[389];
  workYaw.L[592] = (workYaw.KKT[774])*workYaw.d_inv[389];
  workYaw.v[344] = workYaw.L[191]*workYaw.d[344];
  workYaw.v[390] = 0-workYaw.L[191]*workYaw.v[344];
  workYaw.d[390] = workYaw.v[390];
  if (workYaw.d[390] > 0)
    workYaw.d[390] = -settingsYaw.kkt_reg;
  else
    workYaw.d[390] -= settingsYaw.kkt_reg;
  workYaw.d_inv[390] = 1/workYaw.d[390];
  workYaw.L[593] = (workYaw.KKT[775])*workYaw.d_inv[390];
  workYaw.L[612] = (workYaw.KKT[776])*workYaw.d_inv[390];
  workYaw.v[345] = workYaw.L[192]*workYaw.d[345];
  workYaw.v[391] = 0-workYaw.L[192]*workYaw.v[345];
  workYaw.d[391] = workYaw.v[391];
  if (workYaw.d[391] > 0)
    workYaw.d[391] = -settingsYaw.kkt_reg;
  else
    workYaw.d[391] -= settingsYaw.kkt_reg;
  workYaw.d_inv[391] = 1/workYaw.d[391];
  workYaw.L[613] = (workYaw.KKT[777])*workYaw.d_inv[391];
  workYaw.L[632] = (workYaw.KKT[778])*workYaw.d_inv[391];
  workYaw.v[346] = workYaw.L[193]*workYaw.d[346];
  workYaw.v[392] = 0-workYaw.L[193]*workYaw.v[346];
  workYaw.d[392] = workYaw.v[392];
  if (workYaw.d[392] > 0)
    workYaw.d[392] = -settingsYaw.kkt_reg;
  else
    workYaw.d[392] -= settingsYaw.kkt_reg;
  workYaw.d_inv[392] = 1/workYaw.d[392];
  workYaw.L[633] = (workYaw.KKT[779])*workYaw.d_inv[392];
  workYaw.L[652] = (workYaw.KKT[780])*workYaw.d_inv[392];
  workYaw.v[347] = workYaw.L[194]*workYaw.d[347];
  workYaw.v[393] = 0-workYaw.L[194]*workYaw.v[347];
  workYaw.d[393] = workYaw.v[393];
  if (workYaw.d[393] > 0)
    workYaw.d[393] = -settingsYaw.kkt_reg;
  else
    workYaw.d[393] -= settingsYaw.kkt_reg;
  workYaw.d_inv[393] = 1/workYaw.d[393];
  workYaw.L[653] = (workYaw.KKT[781])*workYaw.d_inv[393];
  workYaw.L[672] = (workYaw.KKT[782])*workYaw.d_inv[393];
  workYaw.v[348] = workYaw.L[195]*workYaw.d[348];
  workYaw.v[394] = 0-workYaw.L[195]*workYaw.v[348];
  workYaw.d[394] = workYaw.v[394];
  if (workYaw.d[394] > 0)
    workYaw.d[394] = -settingsYaw.kkt_reg;
  else
    workYaw.d[394] -= settingsYaw.kkt_reg;
  workYaw.d_inv[394] = 1/workYaw.d[394];
  workYaw.L[673] = (workYaw.KKT[783])*workYaw.d_inv[394];
  workYaw.L[692] = (workYaw.KKT[784])*workYaw.d_inv[394];
  workYaw.v[349] = workYaw.L[196]*workYaw.d[349];
  workYaw.v[395] = 0-workYaw.L[196]*workYaw.v[349];
  workYaw.d[395] = workYaw.v[395];
  if (workYaw.d[395] > 0)
    workYaw.d[395] = -settingsYaw.kkt_reg;
  else
    workYaw.d[395] -= settingsYaw.kkt_reg;
  workYaw.d_inv[395] = 1/workYaw.d[395];
  workYaw.L[693] = (workYaw.KKT[785])*workYaw.d_inv[395];
  workYaw.L[712] = (workYaw.KKT[786])*workYaw.d_inv[395];
  workYaw.v[350] = workYaw.L[197]*workYaw.d[350];
  workYaw.v[396] = 0-workYaw.L[197]*workYaw.v[350];
  workYaw.d[396] = workYaw.v[396];
  if (workYaw.d[396] > 0)
    workYaw.d[396] = -settingsYaw.kkt_reg;
  else
    workYaw.d[396] -= settingsYaw.kkt_reg;
  workYaw.d_inv[396] = 1/workYaw.d[396];
  workYaw.L[713] = (workYaw.KKT[787])*workYaw.d_inv[396];
  workYaw.L[732] = (workYaw.KKT[788])*workYaw.d_inv[396];
  workYaw.v[351] = workYaw.L[198]*workYaw.d[351];
  workYaw.v[397] = 0-workYaw.L[198]*workYaw.v[351];
  workYaw.d[397] = workYaw.v[397];
  if (workYaw.d[397] > 0)
    workYaw.d[397] = -settingsYaw.kkt_reg;
  else
    workYaw.d[397] -= settingsYaw.kkt_reg;
  workYaw.d_inv[397] = 1/workYaw.d[397];
  workYaw.L[733] = (workYaw.KKT[789])*workYaw.d_inv[397];
  workYaw.L[752] = (workYaw.KKT[790])*workYaw.d_inv[397];
  workYaw.v[352] = workYaw.L[199]*workYaw.d[352];
  workYaw.v[398] = 0-workYaw.L[199]*workYaw.v[352];
  workYaw.d[398] = workYaw.v[398];
  if (workYaw.d[398] > 0)
    workYaw.d[398] = -settingsYaw.kkt_reg;
  else
    workYaw.d[398] -= settingsYaw.kkt_reg;
  workYaw.d_inv[398] = 1/workYaw.d[398];
  workYaw.L[753] = (workYaw.KKT[791])*workYaw.d_inv[398];
  workYaw.L[772] = (workYaw.KKT[792])*workYaw.d_inv[398];
  workYaw.v[353] = workYaw.L[200]*workYaw.d[353];
  workYaw.v[399] = 0-workYaw.L[200]*workYaw.v[353];
  workYaw.d[399] = workYaw.v[399];
  if (workYaw.d[399] > 0)
    workYaw.d[399] = -settingsYaw.kkt_reg;
  else
    workYaw.d[399] -= settingsYaw.kkt_reg;
  workYaw.d_inv[399] = 1/workYaw.d[399];
  workYaw.L[773] = (workYaw.KKT[793])*workYaw.d_inv[399];
  workYaw.L[792] = (workYaw.KKT[794])*workYaw.d_inv[399];
  workYaw.v[354] = workYaw.L[201]*workYaw.d[354];
  workYaw.v[400] = 0-workYaw.L[201]*workYaw.v[354];
  workYaw.d[400] = workYaw.v[400];
  if (workYaw.d[400] > 0)
    workYaw.d[400] = -settingsYaw.kkt_reg;
  else
    workYaw.d[400] -= settingsYaw.kkt_reg;
  workYaw.d_inv[400] = 1/workYaw.d[400];
  workYaw.L[793] = (workYaw.KKT[795])*workYaw.d_inv[400];
  workYaw.L[812] = (workYaw.KKT[796])*workYaw.d_inv[400];
  workYaw.v[355] = workYaw.L[202]*workYaw.d[355];
  workYaw.v[401] = 0-workYaw.L[202]*workYaw.v[355];
  workYaw.d[401] = workYaw.v[401];
  if (workYaw.d[401] > 0)
    workYaw.d[401] = -settingsYaw.kkt_reg;
  else
    workYaw.d[401] -= settingsYaw.kkt_reg;
  workYaw.d_inv[401] = 1/workYaw.d[401];
  workYaw.L[813] = (workYaw.KKT[797])*workYaw.d_inv[401];
  workYaw.L[832] = (workYaw.KKT[798])*workYaw.d_inv[401];
  workYaw.v[356] = workYaw.L[203]*workYaw.d[356];
  workYaw.v[402] = 0-workYaw.L[203]*workYaw.v[356];
  workYaw.d[402] = workYaw.v[402];
  if (workYaw.d[402] > 0)
    workYaw.d[402] = -settingsYaw.kkt_reg;
  else
    workYaw.d[402] -= settingsYaw.kkt_reg;
  workYaw.d_inv[402] = 1/workYaw.d[402];
  workYaw.L[833] = (workYaw.KKT[799])*workYaw.d_inv[402];
  workYaw.L[852] = (workYaw.KKT[800])*workYaw.d_inv[402];
  workYaw.v[357] = workYaw.L[204]*workYaw.d[357];
  workYaw.v[403] = 0-workYaw.L[204]*workYaw.v[357];
  workYaw.d[403] = workYaw.v[403];
  if (workYaw.d[403] > 0)
    workYaw.d[403] = -settingsYaw.kkt_reg;
  else
    workYaw.d[403] -= settingsYaw.kkt_reg;
  workYaw.d_inv[403] = 1/workYaw.d[403];
  workYaw.L[853] = (workYaw.KKT[801])*workYaw.d_inv[403];
  workYaw.L[872] = (workYaw.KKT[802])*workYaw.d_inv[403];
  workYaw.v[358] = workYaw.L[205]*workYaw.d[358];
  workYaw.v[404] = 0-workYaw.L[205]*workYaw.v[358];
  workYaw.d[404] = workYaw.v[404];
  if (workYaw.d[404] > 0)
    workYaw.d[404] = -settingsYaw.kkt_reg;
  else
    workYaw.d[404] -= settingsYaw.kkt_reg;
  workYaw.d_inv[404] = 1/workYaw.d[404];
  workYaw.L[873] = (workYaw.KKT[803])*workYaw.d_inv[404];
  workYaw.L[892] = (workYaw.KKT[804])*workYaw.d_inv[404];
  workYaw.v[359] = workYaw.L[206]*workYaw.d[359];
  workYaw.v[405] = 0-workYaw.L[206]*workYaw.v[359];
  workYaw.d[405] = workYaw.v[405];
  if (workYaw.d[405] > 0)
    workYaw.d[405] = -settingsYaw.kkt_reg;
  else
    workYaw.d[405] -= settingsYaw.kkt_reg;
  workYaw.d_inv[405] = 1/workYaw.d[405];
  workYaw.L[893] = (workYaw.KKT[805])*workYaw.d_inv[405];
  workYaw.L[912] = (workYaw.KKT[806])*workYaw.d_inv[405];
  workYaw.v[360] = workYaw.L[207]*workYaw.d[360];
  workYaw.v[406] = 0-workYaw.L[207]*workYaw.v[360];
  workYaw.d[406] = workYaw.v[406];
  if (workYaw.d[406] > 0)
    workYaw.d[406] = -settingsYaw.kkt_reg;
  else
    workYaw.d[406] -= settingsYaw.kkt_reg;
  workYaw.d_inv[406] = 1/workYaw.d[406];
  workYaw.L[913] = (workYaw.KKT[807])*workYaw.d_inv[406];
  workYaw.L[932] = (workYaw.KKT[808])*workYaw.d_inv[406];
  workYaw.v[361] = workYaw.L[208]*workYaw.d[361];
  workYaw.v[407] = 0-workYaw.L[208]*workYaw.v[361];
  workYaw.d[407] = workYaw.v[407];
  if (workYaw.d[407] > 0)
    workYaw.d[407] = -settingsYaw.kkt_reg;
  else
    workYaw.d[407] -= settingsYaw.kkt_reg;
  workYaw.d_inv[407] = 1/workYaw.d[407];
  workYaw.L[933] = (workYaw.KKT[809])*workYaw.d_inv[407];
  workYaw.L[958] = (workYaw.KKT[810])*workYaw.d_inv[407];
  workYaw.v[362] = workYaw.L[209]*workYaw.d[362];
  workYaw.v[369] = workYaw.L[210]*workYaw.d[369];
  workYaw.v[408] = 0-workYaw.L[209]*workYaw.v[362]-workYaw.L[210]*workYaw.v[369];
  workYaw.d[408] = workYaw.v[408];
  if (workYaw.d[408] > 0)
    workYaw.d[408] = -settingsYaw.kkt_reg;
  else
    workYaw.d[408] -= settingsYaw.kkt_reg;
  workYaw.d_inv[408] = 1/workYaw.d[408];
  workYaw.L[214] = (-workYaw.L[213]*workYaw.v[369])*workYaw.d_inv[408];
  workYaw.L[959] = (workYaw.KKT[811])*workYaw.d_inv[408];
  workYaw.v[367] = workYaw.L[211]*workYaw.d[367];
  workYaw.v[409] = 0-workYaw.L[211]*workYaw.v[367];
  workYaw.d[409] = workYaw.v[409];
  if (workYaw.d[409] > 0)
    workYaw.d[409] = -settingsYaw.kkt_reg;
  else
    workYaw.d[409] -= settingsYaw.kkt_reg;
  workYaw.d_inv[409] = 1/workYaw.d[409];
  workYaw.L[225] = (workYaw.KKT[812])*workYaw.d_inv[409];
  workYaw.L[969] = (workYaw.KKT[813])*workYaw.d_inv[409];
  workYaw.v[368] = workYaw.L[212]*workYaw.d[368];
  workYaw.v[369] = workYaw.L[213]*workYaw.d[369];
  workYaw.v[408] = workYaw.L[214]*workYaw.d[408];
  workYaw.v[410] = 0-workYaw.L[212]*workYaw.v[368]-workYaw.L[213]*workYaw.v[369]-workYaw.L[214]*workYaw.v[408];
  workYaw.d[410] = workYaw.v[410];
  if (workYaw.d[410] > 0)
    workYaw.d[410] = -settingsYaw.kkt_reg;
  else
    workYaw.d[410] -= settingsYaw.kkt_reg;
  workYaw.d_inv[410] = 1/workYaw.d[410];
  workYaw.L[960] = (-workYaw.L[959]*workYaw.v[408])*workYaw.d_inv[410];
  workYaw.L[970] = (workYaw.KKT[814])*workYaw.d_inv[410];
  workYaw.v[161] = workYaw.L[215]*workYaw.d[161];
  workYaw.v[201] = workYaw.L[216]*workYaw.d[201];
  workYaw.v[322] = workYaw.L[217]*workYaw.d[322];
  workYaw.v[370] = workYaw.L[218]*workYaw.d[370];
  workYaw.v[411] = workYaw.KKT[815]-workYaw.L[215]*workYaw.v[161]-workYaw.L[216]*workYaw.v[201]-workYaw.L[217]*workYaw.v[322]-workYaw.L[218]*workYaw.v[370];
  workYaw.d[411] = workYaw.v[411];
  if (workYaw.d[411] < 0)
    workYaw.d[411] = settingsYaw.kkt_reg;
  else
    workYaw.d[411] += settingsYaw.kkt_reg;
  workYaw.d_inv[411] = 1/workYaw.d[411];
  workYaw.L[224] = (-workYaw.L[223]*workYaw.v[370])*workYaw.d_inv[411];
  workYaw.L[226] = (workYaw.KKT[816])*workYaw.d_inv[411];
  workYaw.v[241] = workYaw.L[219]*workYaw.d[241];
  workYaw.v[281] = workYaw.L[220]*workYaw.d[281];
  workYaw.v[324] = workYaw.L[221]*workYaw.d[324];
  workYaw.v[371] = workYaw.L[222]*workYaw.d[371];
  workYaw.v[412] = workYaw.KKT[817]-workYaw.L[219]*workYaw.v[241]-workYaw.L[220]*workYaw.v[281]-workYaw.L[221]*workYaw.v[324]-workYaw.L[222]*workYaw.v[371];
  workYaw.d[412] = workYaw.v[412];
  if (workYaw.d[412] < 0)
    workYaw.d[412] = settingsYaw.kkt_reg;
  else
    workYaw.d[412] += settingsYaw.kkt_reg;
  workYaw.d_inv[412] = 1/workYaw.d[412];
  workYaw.L[227] = (workYaw.KKT[818])*workYaw.d_inv[412];
  workYaw.L[236] = (-workYaw.L[234]*workYaw.v[371])*workYaw.d_inv[412];
  workYaw.v[370] = workYaw.L[223]*workYaw.d[370];
  workYaw.v[411] = workYaw.L[224]*workYaw.d[411];
  workYaw.v[413] = workYaw.KKT[819]-workYaw.L[223]*workYaw.v[370]-workYaw.L[224]*workYaw.v[411];
  workYaw.d[413] = workYaw.v[413];
  if (workYaw.d[413] < 0)
    workYaw.d[413] = settingsYaw.kkt_reg;
  else
    workYaw.d[413] += settingsYaw.kkt_reg;
  workYaw.d_inv[413] = 1/workYaw.d[413];
  workYaw.L[228] = (-workYaw.L[226]*workYaw.v[411])*workYaw.d_inv[413];
  workYaw.L[239] = (workYaw.KKT[820])*workYaw.d_inv[413];
  workYaw.v[414] = workYaw.KKT[821];
  workYaw.d[414] = workYaw.v[414];
  if (workYaw.d[414] < 0)
    workYaw.d[414] = settingsYaw.kkt_reg;
  else
    workYaw.d[414] += settingsYaw.kkt_reg;
  workYaw.d_inv[414] = 1/workYaw.d[414];
  workYaw.L[240] = (workYaw.KKT[822])*workYaw.d_inv[414];
  workYaw.L[258] = (workYaw.KKT[823])*workYaw.d_inv[414];
  workYaw.v[415] = workYaw.KKT[824];
  workYaw.d[415] = workYaw.v[415];
  if (workYaw.d[415] < 0)
    workYaw.d[415] = settingsYaw.kkt_reg;
  else
    workYaw.d[415] += settingsYaw.kkt_reg;
  workYaw.d_inv[415] = 1/workYaw.d[415];
  workYaw.L[259] = (workYaw.KKT[825])*workYaw.d_inv[415];
  workYaw.L[278] = (workYaw.KKT[826])*workYaw.d_inv[415];
  workYaw.v[416] = workYaw.KKT[827];
  workYaw.d[416] = workYaw.v[416];
  if (workYaw.d[416] < 0)
    workYaw.d[416] = settingsYaw.kkt_reg;
  else
    workYaw.d[416] += settingsYaw.kkt_reg;
  workYaw.d_inv[416] = 1/workYaw.d[416];
  workYaw.L[279] = (workYaw.KKT[828])*workYaw.d_inv[416];
  workYaw.L[298] = (workYaw.KKT[829])*workYaw.d_inv[416];
  workYaw.v[417] = workYaw.KKT[830];
  workYaw.d[417] = workYaw.v[417];
  if (workYaw.d[417] < 0)
    workYaw.d[417] = settingsYaw.kkt_reg;
  else
    workYaw.d[417] += settingsYaw.kkt_reg;
  workYaw.d_inv[417] = 1/workYaw.d[417];
  workYaw.L[299] = (workYaw.KKT[831])*workYaw.d_inv[417];
  workYaw.L[318] = (workYaw.KKT[832])*workYaw.d_inv[417];
  workYaw.v[418] = workYaw.KKT[833];
  workYaw.d[418] = workYaw.v[418];
  if (workYaw.d[418] < 0)
    workYaw.d[418] = settingsYaw.kkt_reg;
  else
    workYaw.d[418] += settingsYaw.kkt_reg;
  workYaw.d_inv[418] = 1/workYaw.d[418];
  workYaw.L[319] = (workYaw.KKT[834])*workYaw.d_inv[418];
  workYaw.L[338] = (workYaw.KKT[835])*workYaw.d_inv[418];
  workYaw.v[419] = workYaw.KKT[836];
  workYaw.d[419] = workYaw.v[419];
  if (workYaw.d[419] < 0)
    workYaw.d[419] = settingsYaw.kkt_reg;
  else
    workYaw.d[419] += settingsYaw.kkt_reg;
  workYaw.d_inv[419] = 1/workYaw.d[419];
  workYaw.L[339] = (workYaw.KKT[837])*workYaw.d_inv[419];
  workYaw.L[358] = (workYaw.KKT[838])*workYaw.d_inv[419];
  workYaw.v[420] = workYaw.KKT[839];
  workYaw.d[420] = workYaw.v[420];
  if (workYaw.d[420] < 0)
    workYaw.d[420] = settingsYaw.kkt_reg;
  else
    workYaw.d[420] += settingsYaw.kkt_reg;
  workYaw.d_inv[420] = 1/workYaw.d[420];
  workYaw.L[359] = (workYaw.KKT[840])*workYaw.d_inv[420];
  workYaw.L[378] = (workYaw.KKT[841])*workYaw.d_inv[420];
  workYaw.v[421] = workYaw.KKT[842];
  workYaw.d[421] = workYaw.v[421];
  if (workYaw.d[421] < 0)
    workYaw.d[421] = settingsYaw.kkt_reg;
  else
    workYaw.d[421] += settingsYaw.kkt_reg;
  workYaw.d_inv[421] = 1/workYaw.d[421];
  workYaw.L[379] = (workYaw.KKT[843])*workYaw.d_inv[421];
  workYaw.L[398] = (workYaw.KKT[844])*workYaw.d_inv[421];
  workYaw.v[422] = workYaw.KKT[845];
  workYaw.d[422] = workYaw.v[422];
  if (workYaw.d[422] < 0)
    workYaw.d[422] = settingsYaw.kkt_reg;
  else
    workYaw.d[422] += settingsYaw.kkt_reg;
  workYaw.d_inv[422] = 1/workYaw.d[422];
  workYaw.L[399] = (workYaw.KKT[846])*workYaw.d_inv[422];
  workYaw.L[418] = (workYaw.KKT[847])*workYaw.d_inv[422];
  workYaw.v[423] = workYaw.KKT[848];
  workYaw.d[423] = workYaw.v[423];
  if (workYaw.d[423] < 0)
    workYaw.d[423] = settingsYaw.kkt_reg;
  else
    workYaw.d[423] += settingsYaw.kkt_reg;
  workYaw.d_inv[423] = 1/workYaw.d[423];
  workYaw.L[419] = (workYaw.KKT[849])*workYaw.d_inv[423];
  workYaw.L[438] = (workYaw.KKT[850])*workYaw.d_inv[423];
  workYaw.v[424] = workYaw.KKT[851];
  workYaw.d[424] = workYaw.v[424];
  if (workYaw.d[424] < 0)
    workYaw.d[424] = settingsYaw.kkt_reg;
  else
    workYaw.d[424] += settingsYaw.kkt_reg;
  workYaw.d_inv[424] = 1/workYaw.d[424];
  workYaw.L[439] = (workYaw.KKT[852])*workYaw.d_inv[424];
  workYaw.L[458] = (workYaw.KKT[853])*workYaw.d_inv[424];
  workYaw.v[425] = workYaw.KKT[854];
  workYaw.d[425] = workYaw.v[425];
  if (workYaw.d[425] < 0)
    workYaw.d[425] = settingsYaw.kkt_reg;
  else
    workYaw.d[425] += settingsYaw.kkt_reg;
  workYaw.d_inv[425] = 1/workYaw.d[425];
  workYaw.L[459] = (workYaw.KKT[855])*workYaw.d_inv[425];
  workYaw.L[478] = (workYaw.KKT[856])*workYaw.d_inv[425];
  workYaw.v[426] = workYaw.KKT[857];
  workYaw.d[426] = workYaw.v[426];
  if (workYaw.d[426] < 0)
    workYaw.d[426] = settingsYaw.kkt_reg;
  else
    workYaw.d[426] += settingsYaw.kkt_reg;
  workYaw.d_inv[426] = 1/workYaw.d[426];
  workYaw.L[479] = (workYaw.KKT[858])*workYaw.d_inv[426];
  workYaw.L[498] = (workYaw.KKT[859])*workYaw.d_inv[426];
  workYaw.v[427] = workYaw.KKT[860];
  workYaw.d[427] = workYaw.v[427];
  if (workYaw.d[427] < 0)
    workYaw.d[427] = settingsYaw.kkt_reg;
  else
    workYaw.d[427] += settingsYaw.kkt_reg;
  workYaw.d_inv[427] = 1/workYaw.d[427];
  workYaw.L[499] = (workYaw.KKT[861])*workYaw.d_inv[427];
  workYaw.L[518] = (workYaw.KKT[862])*workYaw.d_inv[427];
  workYaw.v[428] = workYaw.KKT[863];
  workYaw.d[428] = workYaw.v[428];
  if (workYaw.d[428] < 0)
    workYaw.d[428] = settingsYaw.kkt_reg;
  else
    workYaw.d[428] += settingsYaw.kkt_reg;
  workYaw.d_inv[428] = 1/workYaw.d[428];
  workYaw.L[519] = (workYaw.KKT[864])*workYaw.d_inv[428];
  workYaw.L[538] = (workYaw.KKT[865])*workYaw.d_inv[428];
  workYaw.v[429] = workYaw.KKT[866];
  workYaw.d[429] = workYaw.v[429];
  if (workYaw.d[429] < 0)
    workYaw.d[429] = settingsYaw.kkt_reg;
  else
    workYaw.d[429] += settingsYaw.kkt_reg;
  workYaw.d_inv[429] = 1/workYaw.d[429];
  workYaw.L[539] = (workYaw.KKT[867])*workYaw.d_inv[429];
  workYaw.L[558] = (workYaw.KKT[868])*workYaw.d_inv[429];
  workYaw.v[430] = workYaw.KKT[869];
  workYaw.d[430] = workYaw.v[430];
  if (workYaw.d[430] < 0)
    workYaw.d[430] = settingsYaw.kkt_reg;
  else
    workYaw.d[430] += settingsYaw.kkt_reg;
  workYaw.d_inv[430] = 1/workYaw.d[430];
  workYaw.L[559] = (workYaw.KKT[870])*workYaw.d_inv[430];
  workYaw.L[578] = (workYaw.KKT[871])*workYaw.d_inv[430];
  workYaw.v[431] = workYaw.KKT[872];
  workYaw.d[431] = workYaw.v[431];
  if (workYaw.d[431] < 0)
    workYaw.d[431] = settingsYaw.kkt_reg;
  else
    workYaw.d[431] += settingsYaw.kkt_reg;
  workYaw.d_inv[431] = 1/workYaw.d[431];
  workYaw.L[579] = (workYaw.KKT[873])*workYaw.d_inv[431];
  workYaw.L[598] = (workYaw.KKT[874])*workYaw.d_inv[431];
  workYaw.v[432] = workYaw.KKT[875];
  workYaw.d[432] = workYaw.v[432];
  if (workYaw.d[432] < 0)
    workYaw.d[432] = settingsYaw.kkt_reg;
  else
    workYaw.d[432] += settingsYaw.kkt_reg;
  workYaw.d_inv[432] = 1/workYaw.d[432];
  workYaw.L[599] = (workYaw.KKT[876])*workYaw.d_inv[432];
  workYaw.L[618] = (workYaw.KKT[877])*workYaw.d_inv[432];
  workYaw.v[433] = workYaw.KKT[878];
  workYaw.d[433] = workYaw.v[433];
  if (workYaw.d[433] < 0)
    workYaw.d[433] = settingsYaw.kkt_reg;
  else
    workYaw.d[433] += settingsYaw.kkt_reg;
  workYaw.d_inv[433] = 1/workYaw.d[433];
  workYaw.L[619] = (workYaw.KKT[879])*workYaw.d_inv[433];
  workYaw.L[638] = (workYaw.KKT[880])*workYaw.d_inv[433];
  workYaw.v[434] = workYaw.KKT[881];
  workYaw.d[434] = workYaw.v[434];
  if (workYaw.d[434] < 0)
    workYaw.d[434] = settingsYaw.kkt_reg;
  else
    workYaw.d[434] += settingsYaw.kkt_reg;
  workYaw.d_inv[434] = 1/workYaw.d[434];
  workYaw.L[639] = (workYaw.KKT[882])*workYaw.d_inv[434];
  workYaw.L[658] = (workYaw.KKT[883])*workYaw.d_inv[434];
  workYaw.v[435] = workYaw.KKT[884];
  workYaw.d[435] = workYaw.v[435];
  if (workYaw.d[435] < 0)
    workYaw.d[435] = settingsYaw.kkt_reg;
  else
    workYaw.d[435] += settingsYaw.kkt_reg;
  workYaw.d_inv[435] = 1/workYaw.d[435];
  workYaw.L[659] = (workYaw.KKT[885])*workYaw.d_inv[435];
  workYaw.L[678] = (workYaw.KKT[886])*workYaw.d_inv[435];
  workYaw.v[436] = workYaw.KKT[887];
  workYaw.d[436] = workYaw.v[436];
  if (workYaw.d[436] < 0)
    workYaw.d[436] = settingsYaw.kkt_reg;
  else
    workYaw.d[436] += settingsYaw.kkt_reg;
  workYaw.d_inv[436] = 1/workYaw.d[436];
  workYaw.L[679] = (workYaw.KKT[888])*workYaw.d_inv[436];
  workYaw.L[698] = (workYaw.KKT[889])*workYaw.d_inv[436];
  workYaw.v[437] = workYaw.KKT[890];
  workYaw.d[437] = workYaw.v[437];
  if (workYaw.d[437] < 0)
    workYaw.d[437] = settingsYaw.kkt_reg;
  else
    workYaw.d[437] += settingsYaw.kkt_reg;
  workYaw.d_inv[437] = 1/workYaw.d[437];
  workYaw.L[699] = (workYaw.KKT[891])*workYaw.d_inv[437];
  workYaw.L[718] = (workYaw.KKT[892])*workYaw.d_inv[437];
  workYaw.v[438] = workYaw.KKT[893];
  workYaw.d[438] = workYaw.v[438];
  if (workYaw.d[438] < 0)
    workYaw.d[438] = settingsYaw.kkt_reg;
  else
    workYaw.d[438] += settingsYaw.kkt_reg;
  workYaw.d_inv[438] = 1/workYaw.d[438];
  workYaw.L[719] = (workYaw.KKT[894])*workYaw.d_inv[438];
  workYaw.L[738] = (workYaw.KKT[895])*workYaw.d_inv[438];
  workYaw.v[439] = workYaw.KKT[896];
  workYaw.d[439] = workYaw.v[439];
  if (workYaw.d[439] < 0)
    workYaw.d[439] = settingsYaw.kkt_reg;
  else
    workYaw.d[439] += settingsYaw.kkt_reg;
  workYaw.d_inv[439] = 1/workYaw.d[439];
  workYaw.L[739] = (workYaw.KKT[897])*workYaw.d_inv[439];
  workYaw.L[758] = (workYaw.KKT[898])*workYaw.d_inv[439];
  workYaw.v[440] = workYaw.KKT[899];
  workYaw.d[440] = workYaw.v[440];
  if (workYaw.d[440] < 0)
    workYaw.d[440] = settingsYaw.kkt_reg;
  else
    workYaw.d[440] += settingsYaw.kkt_reg;
  workYaw.d_inv[440] = 1/workYaw.d[440];
  workYaw.L[759] = (workYaw.KKT[900])*workYaw.d_inv[440];
  workYaw.L[778] = (workYaw.KKT[901])*workYaw.d_inv[440];
  workYaw.v[441] = workYaw.KKT[902];
  workYaw.d[441] = workYaw.v[441];
  if (workYaw.d[441] < 0)
    workYaw.d[441] = settingsYaw.kkt_reg;
  else
    workYaw.d[441] += settingsYaw.kkt_reg;
  workYaw.d_inv[441] = 1/workYaw.d[441];
  workYaw.L[779] = (workYaw.KKT[903])*workYaw.d_inv[441];
  workYaw.L[798] = (workYaw.KKT[904])*workYaw.d_inv[441];
  workYaw.v[442] = workYaw.KKT[905];
  workYaw.d[442] = workYaw.v[442];
  if (workYaw.d[442] < 0)
    workYaw.d[442] = settingsYaw.kkt_reg;
  else
    workYaw.d[442] += settingsYaw.kkt_reg;
  workYaw.d_inv[442] = 1/workYaw.d[442];
  workYaw.L[799] = (workYaw.KKT[906])*workYaw.d_inv[442];
  workYaw.L[818] = (workYaw.KKT[907])*workYaw.d_inv[442];
  workYaw.v[443] = workYaw.KKT[908];
  workYaw.d[443] = workYaw.v[443];
  if (workYaw.d[443] < 0)
    workYaw.d[443] = settingsYaw.kkt_reg;
  else
    workYaw.d[443] += settingsYaw.kkt_reg;
  workYaw.d_inv[443] = 1/workYaw.d[443];
  workYaw.L[819] = (workYaw.KKT[909])*workYaw.d_inv[443];
  workYaw.L[838] = (workYaw.KKT[910])*workYaw.d_inv[443];
  workYaw.v[444] = workYaw.KKT[911];
  workYaw.d[444] = workYaw.v[444];
  if (workYaw.d[444] < 0)
    workYaw.d[444] = settingsYaw.kkt_reg;
  else
    workYaw.d[444] += settingsYaw.kkt_reg;
  workYaw.d_inv[444] = 1/workYaw.d[444];
  workYaw.L[839] = (workYaw.KKT[912])*workYaw.d_inv[444];
  workYaw.L[858] = (workYaw.KKT[913])*workYaw.d_inv[444];
  workYaw.v[445] = workYaw.KKT[914];
  workYaw.d[445] = workYaw.v[445];
  if (workYaw.d[445] < 0)
    workYaw.d[445] = settingsYaw.kkt_reg;
  else
    workYaw.d[445] += settingsYaw.kkt_reg;
  workYaw.d_inv[445] = 1/workYaw.d[445];
  workYaw.L[859] = (workYaw.KKT[915])*workYaw.d_inv[445];
  workYaw.L[878] = (workYaw.KKT[916])*workYaw.d_inv[445];
  workYaw.v[446] = workYaw.KKT[917];
  workYaw.d[446] = workYaw.v[446];
  if (workYaw.d[446] < 0)
    workYaw.d[446] = settingsYaw.kkt_reg;
  else
    workYaw.d[446] += settingsYaw.kkt_reg;
  workYaw.d_inv[446] = 1/workYaw.d[446];
  workYaw.L[879] = (workYaw.KKT[918])*workYaw.d_inv[446];
  workYaw.L[898] = (workYaw.KKT[919])*workYaw.d_inv[446];
  workYaw.v[447] = workYaw.KKT[920];
  workYaw.d[447] = workYaw.v[447];
  if (workYaw.d[447] < 0)
    workYaw.d[447] = settingsYaw.kkt_reg;
  else
    workYaw.d[447] += settingsYaw.kkt_reg;
  workYaw.d_inv[447] = 1/workYaw.d[447];
  workYaw.L[899] = (workYaw.KKT[921])*workYaw.d_inv[447];
  workYaw.L[918] = (workYaw.KKT[922])*workYaw.d_inv[447];
  workYaw.v[448] = workYaw.KKT[923];
  workYaw.d[448] = workYaw.v[448];
  if (workYaw.d[448] < 0)
    workYaw.d[448] = settingsYaw.kkt_reg;
  else
    workYaw.d[448] += settingsYaw.kkt_reg;
  workYaw.d_inv[448] = 1/workYaw.d[448];
  workYaw.L[919] = (workYaw.KKT[924])*workYaw.d_inv[448];
  workYaw.L[938] = (workYaw.KKT[925])*workYaw.d_inv[448];
  workYaw.v[449] = workYaw.KKT[926];
  workYaw.d[449] = workYaw.v[449];
  if (workYaw.d[449] < 0)
    workYaw.d[449] = settingsYaw.kkt_reg;
  else
    workYaw.d[449] += settingsYaw.kkt_reg;
  workYaw.d_inv[449] = 1/workYaw.d[449];
  workYaw.L[939] = (workYaw.KKT[927])*workYaw.d_inv[449];
  workYaw.L[947] = (workYaw.KKT[928])*workYaw.d_inv[449];
  workYaw.v[409] = workYaw.L[225]*workYaw.d[409];
  workYaw.v[450] = workYaw.KKT[929]-workYaw.L[225]*workYaw.v[409];
  workYaw.d[450] = workYaw.v[450];
  if (workYaw.d[450] < 0)
    workYaw.d[450] = settingsYaw.kkt_reg;
  else
    workYaw.d[450] += settingsYaw.kkt_reg;
  workYaw.d_inv[450] = 1/workYaw.d[450];
  workYaw.L[948] = (workYaw.KKT[930])*workYaw.d_inv[450];
  workYaw.L[971] = (-workYaw.L[969]*workYaw.v[409])*workYaw.d_inv[450];
  workYaw.v[411] = workYaw.L[226]*workYaw.d[411];
  workYaw.v[412] = workYaw.L[227]*workYaw.d[412];
  workYaw.v[413] = workYaw.L[228]*workYaw.d[413];
  workYaw.v[451] = 0-workYaw.L[226]*workYaw.v[411]-workYaw.L[227]*workYaw.v[412]-workYaw.L[228]*workYaw.v[413];
  workYaw.d[451] = workYaw.v[451];
  if (workYaw.d[451] > 0)
    workYaw.d[451] = -settingsYaw.kkt_reg;
  else
    workYaw.d[451] -= settingsYaw.kkt_reg;
  workYaw.d_inv[451] = 1/workYaw.d[451];
  workYaw.L[231] = (workYaw.KKT[931])*workYaw.d_inv[451];
  workYaw.L[237] = (-workYaw.L[236]*workYaw.v[412])*workYaw.d_inv[451];
  workYaw.L[241] = (-workYaw.L[239]*workYaw.v[413])*workYaw.d_inv[451];
  workYaw.v[162] = workYaw.L[229]*workYaw.d[162];
  workYaw.v[202] = workYaw.L[230]*workYaw.d[202];
  workYaw.v[451] = workYaw.L[231]*workYaw.d[451];
  workYaw.v[452] = workYaw.KKT[932]-workYaw.L[229]*workYaw.v[162]-workYaw.L[230]*workYaw.v[202]-workYaw.L[231]*workYaw.v[451];
  workYaw.d[452] = workYaw.v[452];
  if (workYaw.d[452] < 0)
    workYaw.d[452] = settingsYaw.kkt_reg;
  else
    workYaw.d[452] += settingsYaw.kkt_reg;
  workYaw.d_inv[452] = 1/workYaw.d[452];
  workYaw.L[238] = (-workYaw.L[237]*workYaw.v[451])*workYaw.d_inv[452];
  workYaw.L[242] = (workYaw.KKT[933]-workYaw.L[241]*workYaw.v[451])*workYaw.d_inv[452];
  workYaw.L[244] = (workYaw.KKT[934])*workYaw.d_inv[452];
  workYaw.v[242] = workYaw.L[232]*workYaw.d[242];
  workYaw.v[282] = workYaw.L[233]*workYaw.d[282];
  workYaw.v[371] = workYaw.L[234]*workYaw.d[371];
  workYaw.v[372] = workYaw.L[235]*workYaw.d[372];
  workYaw.v[412] = workYaw.L[236]*workYaw.d[412];
  workYaw.v[451] = workYaw.L[237]*workYaw.d[451];
  workYaw.v[452] = workYaw.L[238]*workYaw.d[452];
  workYaw.v[453] = workYaw.KKT[935]-workYaw.L[232]*workYaw.v[242]-workYaw.L[233]*workYaw.v[282]-workYaw.L[234]*workYaw.v[371]-workYaw.L[235]*workYaw.v[372]-workYaw.L[236]*workYaw.v[412]-workYaw.L[237]*workYaw.v[451]-workYaw.L[238]*workYaw.v[452];
  workYaw.d[453] = workYaw.v[453];
  if (workYaw.d[453] < 0)
    workYaw.d[453] = settingsYaw.kkt_reg;
  else
    workYaw.d[453] += settingsYaw.kkt_reg;
  workYaw.d_inv[453] = 1/workYaw.d[453];
  workYaw.L[243] = (-workYaw.L[241]*workYaw.v[451]-workYaw.L[242]*workYaw.v[452])*workYaw.d_inv[453];
  workYaw.L[245] = (workYaw.KKT[936]-workYaw.L[244]*workYaw.v[452])*workYaw.d_inv[453];
  workYaw.L[254] = (-workYaw.L[252]*workYaw.v[372])*workYaw.d_inv[453];
  workYaw.v[413] = workYaw.L[239]*workYaw.d[413];
  workYaw.v[414] = workYaw.L[240]*workYaw.d[414];
  workYaw.v[451] = workYaw.L[241]*workYaw.d[451];
  workYaw.v[452] = workYaw.L[242]*workYaw.d[452];
  workYaw.v[453] = workYaw.L[243]*workYaw.d[453];
  workYaw.v[454] = 0-workYaw.L[239]*workYaw.v[413]-workYaw.L[240]*workYaw.v[414]-workYaw.L[241]*workYaw.v[451]-workYaw.L[242]*workYaw.v[452]-workYaw.L[243]*workYaw.v[453];
  workYaw.d[454] = workYaw.v[454];
  if (workYaw.d[454] > 0)
    workYaw.d[454] = -settingsYaw.kkt_reg;
  else
    workYaw.d[454] -= settingsYaw.kkt_reg;
  workYaw.d_inv[454] = 1/workYaw.d[454];
  workYaw.L[246] = (-workYaw.L[244]*workYaw.v[452]-workYaw.L[245]*workYaw.v[453])*workYaw.d_inv[454];
  workYaw.L[255] = (-workYaw.L[254]*workYaw.v[453])*workYaw.d_inv[454];
  workYaw.L[260] = (-workYaw.L[258]*workYaw.v[414])*workYaw.d_inv[454];
  workYaw.v[452] = workYaw.L[244]*workYaw.d[452];
  workYaw.v[453] = workYaw.L[245]*workYaw.d[453];
  workYaw.v[454] = workYaw.L[246]*workYaw.d[454];
  workYaw.v[455] = 0-workYaw.L[244]*workYaw.v[452]-workYaw.L[245]*workYaw.v[453]-workYaw.L[246]*workYaw.v[454];
  workYaw.d[455] = workYaw.v[455];
  if (workYaw.d[455] > 0)
    workYaw.d[455] = -settingsYaw.kkt_reg;
  else
    workYaw.d[455] -= settingsYaw.kkt_reg;
  workYaw.d_inv[455] = 1/workYaw.d[455];
  workYaw.L[249] = (workYaw.KKT[937])*workYaw.d_inv[455];
  workYaw.L[256] = (-workYaw.L[254]*workYaw.v[453]-workYaw.L[255]*workYaw.v[454])*workYaw.d_inv[455];
  workYaw.L[261] = (-workYaw.L[260]*workYaw.v[454])*workYaw.d_inv[455];
  workYaw.v[163] = workYaw.L[247]*workYaw.d[163];
  workYaw.v[203] = workYaw.L[248]*workYaw.d[203];
  workYaw.v[455] = workYaw.L[249]*workYaw.d[455];
  workYaw.v[456] = workYaw.KKT[938]-workYaw.L[247]*workYaw.v[163]-workYaw.L[248]*workYaw.v[203]-workYaw.L[249]*workYaw.v[455];
  workYaw.d[456] = workYaw.v[456];
  if (workYaw.d[456] < 0)
    workYaw.d[456] = settingsYaw.kkt_reg;
  else
    workYaw.d[456] += settingsYaw.kkt_reg;
  workYaw.d_inv[456] = 1/workYaw.d[456];
  workYaw.L[257] = (-workYaw.L[256]*workYaw.v[455])*workYaw.d_inv[456];
  workYaw.L[262] = (workYaw.KKT[939]-workYaw.L[261]*workYaw.v[455])*workYaw.d_inv[456];
  workYaw.L[264] = (workYaw.KKT[940])*workYaw.d_inv[456];
  workYaw.v[243] = workYaw.L[250]*workYaw.d[243];
  workYaw.v[283] = workYaw.L[251]*workYaw.d[283];
  workYaw.v[372] = workYaw.L[252]*workYaw.d[372];
  workYaw.v[373] = workYaw.L[253]*workYaw.d[373];
  workYaw.v[453] = workYaw.L[254]*workYaw.d[453];
  workYaw.v[454] = workYaw.L[255]*workYaw.d[454];
  workYaw.v[455] = workYaw.L[256]*workYaw.d[455];
  workYaw.v[456] = workYaw.L[257]*workYaw.d[456];
  workYaw.v[457] = workYaw.KKT[941]-workYaw.L[250]*workYaw.v[243]-workYaw.L[251]*workYaw.v[283]-workYaw.L[252]*workYaw.v[372]-workYaw.L[253]*workYaw.v[373]-workYaw.L[254]*workYaw.v[453]-workYaw.L[255]*workYaw.v[454]-workYaw.L[256]*workYaw.v[455]-workYaw.L[257]*workYaw.v[456];
  workYaw.d[457] = workYaw.v[457];
  if (workYaw.d[457] < 0)
    workYaw.d[457] = settingsYaw.kkt_reg;
  else
    workYaw.d[457] += settingsYaw.kkt_reg;
  workYaw.d_inv[457] = 1/workYaw.d[457];
  workYaw.L[263] = (-workYaw.L[260]*workYaw.v[454]-workYaw.L[261]*workYaw.v[455]-workYaw.L[262]*workYaw.v[456])*workYaw.d_inv[457];
  workYaw.L[265] = (workYaw.KKT[942]-workYaw.L[264]*workYaw.v[456])*workYaw.d_inv[457];
  workYaw.L[274] = (-workYaw.L[272]*workYaw.v[373])*workYaw.d_inv[457];
  workYaw.v[414] = workYaw.L[258]*workYaw.d[414];
  workYaw.v[415] = workYaw.L[259]*workYaw.d[415];
  workYaw.v[454] = workYaw.L[260]*workYaw.d[454];
  workYaw.v[455] = workYaw.L[261]*workYaw.d[455];
  workYaw.v[456] = workYaw.L[262]*workYaw.d[456];
  workYaw.v[457] = workYaw.L[263]*workYaw.d[457];
  workYaw.v[458] = 0-workYaw.L[258]*workYaw.v[414]-workYaw.L[259]*workYaw.v[415]-workYaw.L[260]*workYaw.v[454]-workYaw.L[261]*workYaw.v[455]-workYaw.L[262]*workYaw.v[456]-workYaw.L[263]*workYaw.v[457];
  workYaw.d[458] = workYaw.v[458];
  if (workYaw.d[458] > 0)
    workYaw.d[458] = -settingsYaw.kkt_reg;
  else
    workYaw.d[458] -= settingsYaw.kkt_reg;
  workYaw.d_inv[458] = 1/workYaw.d[458];
  workYaw.L[266] = (-workYaw.L[264]*workYaw.v[456]-workYaw.L[265]*workYaw.v[457])*workYaw.d_inv[458];
  workYaw.L[275] = (-workYaw.L[274]*workYaw.v[457])*workYaw.d_inv[458];
  workYaw.L[280] = (-workYaw.L[278]*workYaw.v[415])*workYaw.d_inv[458];
  workYaw.v[456] = workYaw.L[264]*workYaw.d[456];
  workYaw.v[457] = workYaw.L[265]*workYaw.d[457];
  workYaw.v[458] = workYaw.L[266]*workYaw.d[458];
  workYaw.v[459] = 0-workYaw.L[264]*workYaw.v[456]-workYaw.L[265]*workYaw.v[457]-workYaw.L[266]*workYaw.v[458];
  workYaw.d[459] = workYaw.v[459];
  if (workYaw.d[459] > 0)
    workYaw.d[459] = -settingsYaw.kkt_reg;
  else
    workYaw.d[459] -= settingsYaw.kkt_reg;
  workYaw.d_inv[459] = 1/workYaw.d[459];
  workYaw.L[269] = (workYaw.KKT[943])*workYaw.d_inv[459];
  workYaw.L[276] = (-workYaw.L[274]*workYaw.v[457]-workYaw.L[275]*workYaw.v[458])*workYaw.d_inv[459];
  workYaw.L[281] = (-workYaw.L[280]*workYaw.v[458])*workYaw.d_inv[459];
  workYaw.v[164] = workYaw.L[267]*workYaw.d[164];
  workYaw.v[204] = workYaw.L[268]*workYaw.d[204];
  workYaw.v[459] = workYaw.L[269]*workYaw.d[459];
  workYaw.v[460] = workYaw.KKT[944]-workYaw.L[267]*workYaw.v[164]-workYaw.L[268]*workYaw.v[204]-workYaw.L[269]*workYaw.v[459];
  workYaw.d[460] = workYaw.v[460];
  if (workYaw.d[460] < 0)
    workYaw.d[460] = settingsYaw.kkt_reg;
  else
    workYaw.d[460] += settingsYaw.kkt_reg;
  workYaw.d_inv[460] = 1/workYaw.d[460];
  workYaw.L[277] = (-workYaw.L[276]*workYaw.v[459])*workYaw.d_inv[460];
  workYaw.L[282] = (workYaw.KKT[945]-workYaw.L[281]*workYaw.v[459])*workYaw.d_inv[460];
  workYaw.L[284] = (workYaw.KKT[946])*workYaw.d_inv[460];
  workYaw.v[244] = workYaw.L[270]*workYaw.d[244];
  workYaw.v[284] = workYaw.L[271]*workYaw.d[284];
  workYaw.v[373] = workYaw.L[272]*workYaw.d[373];
  workYaw.v[374] = workYaw.L[273]*workYaw.d[374];
  workYaw.v[457] = workYaw.L[274]*workYaw.d[457];
  workYaw.v[458] = workYaw.L[275]*workYaw.d[458];
  workYaw.v[459] = workYaw.L[276]*workYaw.d[459];
  workYaw.v[460] = workYaw.L[277]*workYaw.d[460];
  workYaw.v[461] = workYaw.KKT[947]-workYaw.L[270]*workYaw.v[244]-workYaw.L[271]*workYaw.v[284]-workYaw.L[272]*workYaw.v[373]-workYaw.L[273]*workYaw.v[374]-workYaw.L[274]*workYaw.v[457]-workYaw.L[275]*workYaw.v[458]-workYaw.L[276]*workYaw.v[459]-workYaw.L[277]*workYaw.v[460];
  workYaw.d[461] = workYaw.v[461];
  if (workYaw.d[461] < 0)
    workYaw.d[461] = settingsYaw.kkt_reg;
  else
    workYaw.d[461] += settingsYaw.kkt_reg;
  workYaw.d_inv[461] = 1/workYaw.d[461];
  workYaw.L[283] = (-workYaw.L[280]*workYaw.v[458]-workYaw.L[281]*workYaw.v[459]-workYaw.L[282]*workYaw.v[460])*workYaw.d_inv[461];
  workYaw.L[285] = (workYaw.KKT[948]-workYaw.L[284]*workYaw.v[460])*workYaw.d_inv[461];
  workYaw.L[294] = (-workYaw.L[292]*workYaw.v[374])*workYaw.d_inv[461];
  workYaw.v[415] = workYaw.L[278]*workYaw.d[415];
  workYaw.v[416] = workYaw.L[279]*workYaw.d[416];
  workYaw.v[458] = workYaw.L[280]*workYaw.d[458];
  workYaw.v[459] = workYaw.L[281]*workYaw.d[459];
  workYaw.v[460] = workYaw.L[282]*workYaw.d[460];
  workYaw.v[461] = workYaw.L[283]*workYaw.d[461];
  workYaw.v[462] = 0-workYaw.L[278]*workYaw.v[415]-workYaw.L[279]*workYaw.v[416]-workYaw.L[280]*workYaw.v[458]-workYaw.L[281]*workYaw.v[459]-workYaw.L[282]*workYaw.v[460]-workYaw.L[283]*workYaw.v[461];
  workYaw.d[462] = workYaw.v[462];
  if (workYaw.d[462] > 0)
    workYaw.d[462] = -settingsYaw.kkt_reg;
  else
    workYaw.d[462] -= settingsYaw.kkt_reg;
  workYaw.d_inv[462] = 1/workYaw.d[462];
  workYaw.L[286] = (-workYaw.L[284]*workYaw.v[460]-workYaw.L[285]*workYaw.v[461])*workYaw.d_inv[462];
  workYaw.L[295] = (-workYaw.L[294]*workYaw.v[461])*workYaw.d_inv[462];
  workYaw.L[300] = (-workYaw.L[298]*workYaw.v[416])*workYaw.d_inv[462];
  workYaw.v[460] = workYaw.L[284]*workYaw.d[460];
  workYaw.v[461] = workYaw.L[285]*workYaw.d[461];
  workYaw.v[462] = workYaw.L[286]*workYaw.d[462];
  workYaw.v[463] = 0-workYaw.L[284]*workYaw.v[460]-workYaw.L[285]*workYaw.v[461]-workYaw.L[286]*workYaw.v[462];
  workYaw.d[463] = workYaw.v[463];
  if (workYaw.d[463] > 0)
    workYaw.d[463] = -settingsYaw.kkt_reg;
  else
    workYaw.d[463] -= settingsYaw.kkt_reg;
  workYaw.d_inv[463] = 1/workYaw.d[463];
  workYaw.L[289] = (workYaw.KKT[949])*workYaw.d_inv[463];
  workYaw.L[296] = (-workYaw.L[294]*workYaw.v[461]-workYaw.L[295]*workYaw.v[462])*workYaw.d_inv[463];
  workYaw.L[301] = (-workYaw.L[300]*workYaw.v[462])*workYaw.d_inv[463];
  workYaw.v[165] = workYaw.L[287]*workYaw.d[165];
  workYaw.v[205] = workYaw.L[288]*workYaw.d[205];
  workYaw.v[463] = workYaw.L[289]*workYaw.d[463];
  workYaw.v[464] = workYaw.KKT[950]-workYaw.L[287]*workYaw.v[165]-workYaw.L[288]*workYaw.v[205]-workYaw.L[289]*workYaw.v[463];
  workYaw.d[464] = workYaw.v[464];
  if (workYaw.d[464] < 0)
    workYaw.d[464] = settingsYaw.kkt_reg;
  else
    workYaw.d[464] += settingsYaw.kkt_reg;
  workYaw.d_inv[464] = 1/workYaw.d[464];
  workYaw.L[297] = (-workYaw.L[296]*workYaw.v[463])*workYaw.d_inv[464];
  workYaw.L[302] = (workYaw.KKT[951]-workYaw.L[301]*workYaw.v[463])*workYaw.d_inv[464];
  workYaw.L[304] = (workYaw.KKT[952])*workYaw.d_inv[464];
  workYaw.v[245] = workYaw.L[290]*workYaw.d[245];
  workYaw.v[285] = workYaw.L[291]*workYaw.d[285];
  workYaw.v[374] = workYaw.L[292]*workYaw.d[374];
  workYaw.v[375] = workYaw.L[293]*workYaw.d[375];
  workYaw.v[461] = workYaw.L[294]*workYaw.d[461];
  workYaw.v[462] = workYaw.L[295]*workYaw.d[462];
  workYaw.v[463] = workYaw.L[296]*workYaw.d[463];
  workYaw.v[464] = workYaw.L[297]*workYaw.d[464];
  workYaw.v[465] = workYaw.KKT[953]-workYaw.L[290]*workYaw.v[245]-workYaw.L[291]*workYaw.v[285]-workYaw.L[292]*workYaw.v[374]-workYaw.L[293]*workYaw.v[375]-workYaw.L[294]*workYaw.v[461]-workYaw.L[295]*workYaw.v[462]-workYaw.L[296]*workYaw.v[463]-workYaw.L[297]*workYaw.v[464];
  workYaw.d[465] = workYaw.v[465];
  if (workYaw.d[465] < 0)
    workYaw.d[465] = settingsYaw.kkt_reg;
  else
    workYaw.d[465] += settingsYaw.kkt_reg;
  workYaw.d_inv[465] = 1/workYaw.d[465];
  workYaw.L[303] = (-workYaw.L[300]*workYaw.v[462]-workYaw.L[301]*workYaw.v[463]-workYaw.L[302]*workYaw.v[464])*workYaw.d_inv[465];
  workYaw.L[305] = (workYaw.KKT[954]-workYaw.L[304]*workYaw.v[464])*workYaw.d_inv[465];
  workYaw.L[314] = (-workYaw.L[312]*workYaw.v[375])*workYaw.d_inv[465];
  workYaw.v[416] = workYaw.L[298]*workYaw.d[416];
  workYaw.v[417] = workYaw.L[299]*workYaw.d[417];
  workYaw.v[462] = workYaw.L[300]*workYaw.d[462];
  workYaw.v[463] = workYaw.L[301]*workYaw.d[463];
  workYaw.v[464] = workYaw.L[302]*workYaw.d[464];
  workYaw.v[465] = workYaw.L[303]*workYaw.d[465];
  workYaw.v[466] = 0-workYaw.L[298]*workYaw.v[416]-workYaw.L[299]*workYaw.v[417]-workYaw.L[300]*workYaw.v[462]-workYaw.L[301]*workYaw.v[463]-workYaw.L[302]*workYaw.v[464]-workYaw.L[303]*workYaw.v[465];
  workYaw.d[466] = workYaw.v[466];
  if (workYaw.d[466] > 0)
    workYaw.d[466] = -settingsYaw.kkt_reg;
  else
    workYaw.d[466] -= settingsYaw.kkt_reg;
  workYaw.d_inv[466] = 1/workYaw.d[466];
  workYaw.L[306] = (-workYaw.L[304]*workYaw.v[464]-workYaw.L[305]*workYaw.v[465])*workYaw.d_inv[466];
  workYaw.L[315] = (-workYaw.L[314]*workYaw.v[465])*workYaw.d_inv[466];
  workYaw.L[320] = (-workYaw.L[318]*workYaw.v[417])*workYaw.d_inv[466];
  workYaw.v[464] = workYaw.L[304]*workYaw.d[464];
  workYaw.v[465] = workYaw.L[305]*workYaw.d[465];
  workYaw.v[466] = workYaw.L[306]*workYaw.d[466];
  workYaw.v[467] = 0-workYaw.L[304]*workYaw.v[464]-workYaw.L[305]*workYaw.v[465]-workYaw.L[306]*workYaw.v[466];
  workYaw.d[467] = workYaw.v[467];
  if (workYaw.d[467] > 0)
    workYaw.d[467] = -settingsYaw.kkt_reg;
  else
    workYaw.d[467] -= settingsYaw.kkt_reg;
  workYaw.d_inv[467] = 1/workYaw.d[467];
  workYaw.L[309] = (workYaw.KKT[955])*workYaw.d_inv[467];
  workYaw.L[316] = (-workYaw.L[314]*workYaw.v[465]-workYaw.L[315]*workYaw.v[466])*workYaw.d_inv[467];
  workYaw.L[321] = (-workYaw.L[320]*workYaw.v[466])*workYaw.d_inv[467];
  workYaw.v[166] = workYaw.L[307]*workYaw.d[166];
  workYaw.v[206] = workYaw.L[308]*workYaw.d[206];
  workYaw.v[467] = workYaw.L[309]*workYaw.d[467];
  workYaw.v[468] = workYaw.KKT[956]-workYaw.L[307]*workYaw.v[166]-workYaw.L[308]*workYaw.v[206]-workYaw.L[309]*workYaw.v[467];
  workYaw.d[468] = workYaw.v[468];
  if (workYaw.d[468] < 0)
    workYaw.d[468] = settingsYaw.kkt_reg;
  else
    workYaw.d[468] += settingsYaw.kkt_reg;
  workYaw.d_inv[468] = 1/workYaw.d[468];
  workYaw.L[317] = (-workYaw.L[316]*workYaw.v[467])*workYaw.d_inv[468];
  workYaw.L[322] = (workYaw.KKT[957]-workYaw.L[321]*workYaw.v[467])*workYaw.d_inv[468];
  workYaw.L[324] = (workYaw.KKT[958])*workYaw.d_inv[468];
  workYaw.v[246] = workYaw.L[310]*workYaw.d[246];
  workYaw.v[286] = workYaw.L[311]*workYaw.d[286];
  workYaw.v[375] = workYaw.L[312]*workYaw.d[375];
  workYaw.v[376] = workYaw.L[313]*workYaw.d[376];
  workYaw.v[465] = workYaw.L[314]*workYaw.d[465];
  workYaw.v[466] = workYaw.L[315]*workYaw.d[466];
  workYaw.v[467] = workYaw.L[316]*workYaw.d[467];
  workYaw.v[468] = workYaw.L[317]*workYaw.d[468];
  workYaw.v[469] = workYaw.KKT[959]-workYaw.L[310]*workYaw.v[246]-workYaw.L[311]*workYaw.v[286]-workYaw.L[312]*workYaw.v[375]-workYaw.L[313]*workYaw.v[376]-workYaw.L[314]*workYaw.v[465]-workYaw.L[315]*workYaw.v[466]-workYaw.L[316]*workYaw.v[467]-workYaw.L[317]*workYaw.v[468];
  workYaw.d[469] = workYaw.v[469];
  if (workYaw.d[469] < 0)
    workYaw.d[469] = settingsYaw.kkt_reg;
  else
    workYaw.d[469] += settingsYaw.kkt_reg;
  workYaw.d_inv[469] = 1/workYaw.d[469];
  workYaw.L[323] = (-workYaw.L[320]*workYaw.v[466]-workYaw.L[321]*workYaw.v[467]-workYaw.L[322]*workYaw.v[468])*workYaw.d_inv[469];
  workYaw.L[325] = (workYaw.KKT[960]-workYaw.L[324]*workYaw.v[468])*workYaw.d_inv[469];
  workYaw.L[334] = (-workYaw.L[332]*workYaw.v[376])*workYaw.d_inv[469];
  workYaw.v[417] = workYaw.L[318]*workYaw.d[417];
  workYaw.v[418] = workYaw.L[319]*workYaw.d[418];
  workYaw.v[466] = workYaw.L[320]*workYaw.d[466];
  workYaw.v[467] = workYaw.L[321]*workYaw.d[467];
  workYaw.v[468] = workYaw.L[322]*workYaw.d[468];
  workYaw.v[469] = workYaw.L[323]*workYaw.d[469];
  workYaw.v[470] = 0-workYaw.L[318]*workYaw.v[417]-workYaw.L[319]*workYaw.v[418]-workYaw.L[320]*workYaw.v[466]-workYaw.L[321]*workYaw.v[467]-workYaw.L[322]*workYaw.v[468]-workYaw.L[323]*workYaw.v[469];
  workYaw.d[470] = workYaw.v[470];
  if (workYaw.d[470] > 0)
    workYaw.d[470] = -settingsYaw.kkt_reg;
  else
    workYaw.d[470] -= settingsYaw.kkt_reg;
  workYaw.d_inv[470] = 1/workYaw.d[470];
  workYaw.L[326] = (-workYaw.L[324]*workYaw.v[468]-workYaw.L[325]*workYaw.v[469])*workYaw.d_inv[470];
  workYaw.L[335] = (-workYaw.L[334]*workYaw.v[469])*workYaw.d_inv[470];
  workYaw.L[340] = (-workYaw.L[338]*workYaw.v[418])*workYaw.d_inv[470];
  workYaw.v[468] = workYaw.L[324]*workYaw.d[468];
  workYaw.v[469] = workYaw.L[325]*workYaw.d[469];
  workYaw.v[470] = workYaw.L[326]*workYaw.d[470];
  workYaw.v[471] = 0-workYaw.L[324]*workYaw.v[468]-workYaw.L[325]*workYaw.v[469]-workYaw.L[326]*workYaw.v[470];
  workYaw.d[471] = workYaw.v[471];
  if (workYaw.d[471] > 0)
    workYaw.d[471] = -settingsYaw.kkt_reg;
  else
    workYaw.d[471] -= settingsYaw.kkt_reg;
  workYaw.d_inv[471] = 1/workYaw.d[471];
  workYaw.L[329] = (workYaw.KKT[961])*workYaw.d_inv[471];
  workYaw.L[336] = (-workYaw.L[334]*workYaw.v[469]-workYaw.L[335]*workYaw.v[470])*workYaw.d_inv[471];
  workYaw.L[341] = (-workYaw.L[340]*workYaw.v[470])*workYaw.d_inv[471];
  workYaw.v[167] = workYaw.L[327]*workYaw.d[167];
  workYaw.v[207] = workYaw.L[328]*workYaw.d[207];
  workYaw.v[471] = workYaw.L[329]*workYaw.d[471];
  workYaw.v[472] = workYaw.KKT[962]-workYaw.L[327]*workYaw.v[167]-workYaw.L[328]*workYaw.v[207]-workYaw.L[329]*workYaw.v[471];
  workYaw.d[472] = workYaw.v[472];
  if (workYaw.d[472] < 0)
    workYaw.d[472] = settingsYaw.kkt_reg;
  else
    workYaw.d[472] += settingsYaw.kkt_reg;
  workYaw.d_inv[472] = 1/workYaw.d[472];
  workYaw.L[337] = (-workYaw.L[336]*workYaw.v[471])*workYaw.d_inv[472];
  workYaw.L[342] = (workYaw.KKT[963]-workYaw.L[341]*workYaw.v[471])*workYaw.d_inv[472];
  workYaw.L[344] = (workYaw.KKT[964])*workYaw.d_inv[472];
  workYaw.v[247] = workYaw.L[330]*workYaw.d[247];
  workYaw.v[287] = workYaw.L[331]*workYaw.d[287];
  workYaw.v[376] = workYaw.L[332]*workYaw.d[376];
  workYaw.v[377] = workYaw.L[333]*workYaw.d[377];
  workYaw.v[469] = workYaw.L[334]*workYaw.d[469];
  workYaw.v[470] = workYaw.L[335]*workYaw.d[470];
  workYaw.v[471] = workYaw.L[336]*workYaw.d[471];
  workYaw.v[472] = workYaw.L[337]*workYaw.d[472];
  workYaw.v[473] = workYaw.KKT[965]-workYaw.L[330]*workYaw.v[247]-workYaw.L[331]*workYaw.v[287]-workYaw.L[332]*workYaw.v[376]-workYaw.L[333]*workYaw.v[377]-workYaw.L[334]*workYaw.v[469]-workYaw.L[335]*workYaw.v[470]-workYaw.L[336]*workYaw.v[471]-workYaw.L[337]*workYaw.v[472];
  workYaw.d[473] = workYaw.v[473];
  if (workYaw.d[473] < 0)
    workYaw.d[473] = settingsYaw.kkt_reg;
  else
    workYaw.d[473] += settingsYaw.kkt_reg;
  workYaw.d_inv[473] = 1/workYaw.d[473];
  workYaw.L[343] = (-workYaw.L[340]*workYaw.v[470]-workYaw.L[341]*workYaw.v[471]-workYaw.L[342]*workYaw.v[472])*workYaw.d_inv[473];
  workYaw.L[345] = (workYaw.KKT[966]-workYaw.L[344]*workYaw.v[472])*workYaw.d_inv[473];
  workYaw.L[354] = (-workYaw.L[352]*workYaw.v[377])*workYaw.d_inv[473];
  workYaw.v[418] = workYaw.L[338]*workYaw.d[418];
  workYaw.v[419] = workYaw.L[339]*workYaw.d[419];
  workYaw.v[470] = workYaw.L[340]*workYaw.d[470];
  workYaw.v[471] = workYaw.L[341]*workYaw.d[471];
  workYaw.v[472] = workYaw.L[342]*workYaw.d[472];
  workYaw.v[473] = workYaw.L[343]*workYaw.d[473];
  workYaw.v[474] = 0-workYaw.L[338]*workYaw.v[418]-workYaw.L[339]*workYaw.v[419]-workYaw.L[340]*workYaw.v[470]-workYaw.L[341]*workYaw.v[471]-workYaw.L[342]*workYaw.v[472]-workYaw.L[343]*workYaw.v[473];
  workYaw.d[474] = workYaw.v[474];
  if (workYaw.d[474] > 0)
    workYaw.d[474] = -settingsYaw.kkt_reg;
  else
    workYaw.d[474] -= settingsYaw.kkt_reg;
  workYaw.d_inv[474] = 1/workYaw.d[474];
  workYaw.L[346] = (-workYaw.L[344]*workYaw.v[472]-workYaw.L[345]*workYaw.v[473])*workYaw.d_inv[474];
  workYaw.L[355] = (-workYaw.L[354]*workYaw.v[473])*workYaw.d_inv[474];
  workYaw.L[360] = (-workYaw.L[358]*workYaw.v[419])*workYaw.d_inv[474];
  workYaw.v[472] = workYaw.L[344]*workYaw.d[472];
  workYaw.v[473] = workYaw.L[345]*workYaw.d[473];
  workYaw.v[474] = workYaw.L[346]*workYaw.d[474];
  workYaw.v[475] = 0-workYaw.L[344]*workYaw.v[472]-workYaw.L[345]*workYaw.v[473]-workYaw.L[346]*workYaw.v[474];
  workYaw.d[475] = workYaw.v[475];
  if (workYaw.d[475] > 0)
    workYaw.d[475] = -settingsYaw.kkt_reg;
  else
    workYaw.d[475] -= settingsYaw.kkt_reg;
  workYaw.d_inv[475] = 1/workYaw.d[475];
  workYaw.L[349] = (workYaw.KKT[967])*workYaw.d_inv[475];
  workYaw.L[356] = (-workYaw.L[354]*workYaw.v[473]-workYaw.L[355]*workYaw.v[474])*workYaw.d_inv[475];
  workYaw.L[361] = (-workYaw.L[360]*workYaw.v[474])*workYaw.d_inv[475];
  workYaw.v[168] = workYaw.L[347]*workYaw.d[168];
  workYaw.v[208] = workYaw.L[348]*workYaw.d[208];
  workYaw.v[475] = workYaw.L[349]*workYaw.d[475];
  workYaw.v[476] = workYaw.KKT[968]-workYaw.L[347]*workYaw.v[168]-workYaw.L[348]*workYaw.v[208]-workYaw.L[349]*workYaw.v[475];
  workYaw.d[476] = workYaw.v[476];
  if (workYaw.d[476] < 0)
    workYaw.d[476] = settingsYaw.kkt_reg;
  else
    workYaw.d[476] += settingsYaw.kkt_reg;
  workYaw.d_inv[476] = 1/workYaw.d[476];
  workYaw.L[357] = (-workYaw.L[356]*workYaw.v[475])*workYaw.d_inv[476];
  workYaw.L[362] = (workYaw.KKT[969]-workYaw.L[361]*workYaw.v[475])*workYaw.d_inv[476];
  workYaw.L[364] = (workYaw.KKT[970])*workYaw.d_inv[476];
  workYaw.v[248] = workYaw.L[350]*workYaw.d[248];
  workYaw.v[288] = workYaw.L[351]*workYaw.d[288];
  workYaw.v[377] = workYaw.L[352]*workYaw.d[377];
  workYaw.v[378] = workYaw.L[353]*workYaw.d[378];
  workYaw.v[473] = workYaw.L[354]*workYaw.d[473];
  workYaw.v[474] = workYaw.L[355]*workYaw.d[474];
  workYaw.v[475] = workYaw.L[356]*workYaw.d[475];
  workYaw.v[476] = workYaw.L[357]*workYaw.d[476];
  workYaw.v[477] = workYaw.KKT[971]-workYaw.L[350]*workYaw.v[248]-workYaw.L[351]*workYaw.v[288]-workYaw.L[352]*workYaw.v[377]-workYaw.L[353]*workYaw.v[378]-workYaw.L[354]*workYaw.v[473]-workYaw.L[355]*workYaw.v[474]-workYaw.L[356]*workYaw.v[475]-workYaw.L[357]*workYaw.v[476];
  workYaw.d[477] = workYaw.v[477];
  if (workYaw.d[477] < 0)
    workYaw.d[477] = settingsYaw.kkt_reg;
  else
    workYaw.d[477] += settingsYaw.kkt_reg;
  workYaw.d_inv[477] = 1/workYaw.d[477];
  workYaw.L[363] = (-workYaw.L[360]*workYaw.v[474]-workYaw.L[361]*workYaw.v[475]-workYaw.L[362]*workYaw.v[476])*workYaw.d_inv[477];
  workYaw.L[365] = (workYaw.KKT[972]-workYaw.L[364]*workYaw.v[476])*workYaw.d_inv[477];
  workYaw.L[374] = (-workYaw.L[372]*workYaw.v[378])*workYaw.d_inv[477];
  workYaw.v[419] = workYaw.L[358]*workYaw.d[419];
  workYaw.v[420] = workYaw.L[359]*workYaw.d[420];
  workYaw.v[474] = workYaw.L[360]*workYaw.d[474];
  workYaw.v[475] = workYaw.L[361]*workYaw.d[475];
  workYaw.v[476] = workYaw.L[362]*workYaw.d[476];
  workYaw.v[477] = workYaw.L[363]*workYaw.d[477];
  workYaw.v[478] = 0-workYaw.L[358]*workYaw.v[419]-workYaw.L[359]*workYaw.v[420]-workYaw.L[360]*workYaw.v[474]-workYaw.L[361]*workYaw.v[475]-workYaw.L[362]*workYaw.v[476]-workYaw.L[363]*workYaw.v[477];
  workYaw.d[478] = workYaw.v[478];
  if (workYaw.d[478] > 0)
    workYaw.d[478] = -settingsYaw.kkt_reg;
  else
    workYaw.d[478] -= settingsYaw.kkt_reg;
  workYaw.d_inv[478] = 1/workYaw.d[478];
  workYaw.L[366] = (-workYaw.L[364]*workYaw.v[476]-workYaw.L[365]*workYaw.v[477])*workYaw.d_inv[478];
  workYaw.L[375] = (-workYaw.L[374]*workYaw.v[477])*workYaw.d_inv[478];
  workYaw.L[380] = (-workYaw.L[378]*workYaw.v[420])*workYaw.d_inv[478];
  workYaw.v[476] = workYaw.L[364]*workYaw.d[476];
  workYaw.v[477] = workYaw.L[365]*workYaw.d[477];
  workYaw.v[478] = workYaw.L[366]*workYaw.d[478];
  workYaw.v[479] = 0-workYaw.L[364]*workYaw.v[476]-workYaw.L[365]*workYaw.v[477]-workYaw.L[366]*workYaw.v[478];
  workYaw.d[479] = workYaw.v[479];
  if (workYaw.d[479] > 0)
    workYaw.d[479] = -settingsYaw.kkt_reg;
  else
    workYaw.d[479] -= settingsYaw.kkt_reg;
  workYaw.d_inv[479] = 1/workYaw.d[479];
  workYaw.L[369] = (workYaw.KKT[973])*workYaw.d_inv[479];
  workYaw.L[376] = (-workYaw.L[374]*workYaw.v[477]-workYaw.L[375]*workYaw.v[478])*workYaw.d_inv[479];
  workYaw.L[381] = (-workYaw.L[380]*workYaw.v[478])*workYaw.d_inv[479];
  workYaw.v[169] = workYaw.L[367]*workYaw.d[169];
  workYaw.v[209] = workYaw.L[368]*workYaw.d[209];
  workYaw.v[479] = workYaw.L[369]*workYaw.d[479];
  workYaw.v[480] = workYaw.KKT[974]-workYaw.L[367]*workYaw.v[169]-workYaw.L[368]*workYaw.v[209]-workYaw.L[369]*workYaw.v[479];
  workYaw.d[480] = workYaw.v[480];
  if (workYaw.d[480] < 0)
    workYaw.d[480] = settingsYaw.kkt_reg;
  else
    workYaw.d[480] += settingsYaw.kkt_reg;
  workYaw.d_inv[480] = 1/workYaw.d[480];
  workYaw.L[377] = (-workYaw.L[376]*workYaw.v[479])*workYaw.d_inv[480];
  workYaw.L[382] = (workYaw.KKT[975]-workYaw.L[381]*workYaw.v[479])*workYaw.d_inv[480];
  workYaw.L[384] = (workYaw.KKT[976])*workYaw.d_inv[480];
  workYaw.v[249] = workYaw.L[370]*workYaw.d[249];
  workYaw.v[289] = workYaw.L[371]*workYaw.d[289];
  workYaw.v[378] = workYaw.L[372]*workYaw.d[378];
  workYaw.v[379] = workYaw.L[373]*workYaw.d[379];
  workYaw.v[477] = workYaw.L[374]*workYaw.d[477];
  workYaw.v[478] = workYaw.L[375]*workYaw.d[478];
  workYaw.v[479] = workYaw.L[376]*workYaw.d[479];
  workYaw.v[480] = workYaw.L[377]*workYaw.d[480];
  workYaw.v[481] = workYaw.KKT[977]-workYaw.L[370]*workYaw.v[249]-workYaw.L[371]*workYaw.v[289]-workYaw.L[372]*workYaw.v[378]-workYaw.L[373]*workYaw.v[379]-workYaw.L[374]*workYaw.v[477]-workYaw.L[375]*workYaw.v[478]-workYaw.L[376]*workYaw.v[479]-workYaw.L[377]*workYaw.v[480];
  workYaw.d[481] = workYaw.v[481];
  if (workYaw.d[481] < 0)
    workYaw.d[481] = settingsYaw.kkt_reg;
  else
    workYaw.d[481] += settingsYaw.kkt_reg;
  workYaw.d_inv[481] = 1/workYaw.d[481];
  workYaw.L[383] = (-workYaw.L[380]*workYaw.v[478]-workYaw.L[381]*workYaw.v[479]-workYaw.L[382]*workYaw.v[480])*workYaw.d_inv[481];
  workYaw.L[385] = (workYaw.KKT[978]-workYaw.L[384]*workYaw.v[480])*workYaw.d_inv[481];
  workYaw.L[394] = (-workYaw.L[392]*workYaw.v[379])*workYaw.d_inv[481];
  workYaw.v[420] = workYaw.L[378]*workYaw.d[420];
  workYaw.v[421] = workYaw.L[379]*workYaw.d[421];
  workYaw.v[478] = workYaw.L[380]*workYaw.d[478];
  workYaw.v[479] = workYaw.L[381]*workYaw.d[479];
  workYaw.v[480] = workYaw.L[382]*workYaw.d[480];
  workYaw.v[481] = workYaw.L[383]*workYaw.d[481];
  workYaw.v[482] = 0-workYaw.L[378]*workYaw.v[420]-workYaw.L[379]*workYaw.v[421]-workYaw.L[380]*workYaw.v[478]-workYaw.L[381]*workYaw.v[479]-workYaw.L[382]*workYaw.v[480]-workYaw.L[383]*workYaw.v[481];
  workYaw.d[482] = workYaw.v[482];
  if (workYaw.d[482] > 0)
    workYaw.d[482] = -settingsYaw.kkt_reg;
  else
    workYaw.d[482] -= settingsYaw.kkt_reg;
  workYaw.d_inv[482] = 1/workYaw.d[482];
  workYaw.L[386] = (-workYaw.L[384]*workYaw.v[480]-workYaw.L[385]*workYaw.v[481])*workYaw.d_inv[482];
  workYaw.L[395] = (-workYaw.L[394]*workYaw.v[481])*workYaw.d_inv[482];
  workYaw.L[400] = (-workYaw.L[398]*workYaw.v[421])*workYaw.d_inv[482];
  workYaw.v[480] = workYaw.L[384]*workYaw.d[480];
  workYaw.v[481] = workYaw.L[385]*workYaw.d[481];
  workYaw.v[482] = workYaw.L[386]*workYaw.d[482];
  workYaw.v[483] = 0-workYaw.L[384]*workYaw.v[480]-workYaw.L[385]*workYaw.v[481]-workYaw.L[386]*workYaw.v[482];
  workYaw.d[483] = workYaw.v[483];
  if (workYaw.d[483] > 0)
    workYaw.d[483] = -settingsYaw.kkt_reg;
  else
    workYaw.d[483] -= settingsYaw.kkt_reg;
  workYaw.d_inv[483] = 1/workYaw.d[483];
  workYaw.L[389] = (workYaw.KKT[979])*workYaw.d_inv[483];
  workYaw.L[396] = (-workYaw.L[394]*workYaw.v[481]-workYaw.L[395]*workYaw.v[482])*workYaw.d_inv[483];
  workYaw.L[401] = (-workYaw.L[400]*workYaw.v[482])*workYaw.d_inv[483];
  workYaw.v[170] = workYaw.L[387]*workYaw.d[170];
  workYaw.v[210] = workYaw.L[388]*workYaw.d[210];
  workYaw.v[483] = workYaw.L[389]*workYaw.d[483];
  workYaw.v[484] = workYaw.KKT[980]-workYaw.L[387]*workYaw.v[170]-workYaw.L[388]*workYaw.v[210]-workYaw.L[389]*workYaw.v[483];
  workYaw.d[484] = workYaw.v[484];
  if (workYaw.d[484] < 0)
    workYaw.d[484] = settingsYaw.kkt_reg;
  else
    workYaw.d[484] += settingsYaw.kkt_reg;
  workYaw.d_inv[484] = 1/workYaw.d[484];
  workYaw.L[397] = (-workYaw.L[396]*workYaw.v[483])*workYaw.d_inv[484];
  workYaw.L[402] = (workYaw.KKT[981]-workYaw.L[401]*workYaw.v[483])*workYaw.d_inv[484];
  workYaw.L[404] = (workYaw.KKT[982])*workYaw.d_inv[484];
  workYaw.v[250] = workYaw.L[390]*workYaw.d[250];
  workYaw.v[290] = workYaw.L[391]*workYaw.d[290];
  workYaw.v[379] = workYaw.L[392]*workYaw.d[379];
  workYaw.v[380] = workYaw.L[393]*workYaw.d[380];
  workYaw.v[481] = workYaw.L[394]*workYaw.d[481];
  workYaw.v[482] = workYaw.L[395]*workYaw.d[482];
  workYaw.v[483] = workYaw.L[396]*workYaw.d[483];
  workYaw.v[484] = workYaw.L[397]*workYaw.d[484];
  workYaw.v[485] = workYaw.KKT[983]-workYaw.L[390]*workYaw.v[250]-workYaw.L[391]*workYaw.v[290]-workYaw.L[392]*workYaw.v[379]-workYaw.L[393]*workYaw.v[380]-workYaw.L[394]*workYaw.v[481]-workYaw.L[395]*workYaw.v[482]-workYaw.L[396]*workYaw.v[483]-workYaw.L[397]*workYaw.v[484];
  workYaw.d[485] = workYaw.v[485];
  if (workYaw.d[485] < 0)
    workYaw.d[485] = settingsYaw.kkt_reg;
  else
    workYaw.d[485] += settingsYaw.kkt_reg;
  workYaw.d_inv[485] = 1/workYaw.d[485];
  workYaw.L[403] = (-workYaw.L[400]*workYaw.v[482]-workYaw.L[401]*workYaw.v[483]-workYaw.L[402]*workYaw.v[484])*workYaw.d_inv[485];
  workYaw.L[405] = (workYaw.KKT[984]-workYaw.L[404]*workYaw.v[484])*workYaw.d_inv[485];
  workYaw.L[414] = (-workYaw.L[412]*workYaw.v[380])*workYaw.d_inv[485];
  workYaw.v[421] = workYaw.L[398]*workYaw.d[421];
  workYaw.v[422] = workYaw.L[399]*workYaw.d[422];
  workYaw.v[482] = workYaw.L[400]*workYaw.d[482];
  workYaw.v[483] = workYaw.L[401]*workYaw.d[483];
  workYaw.v[484] = workYaw.L[402]*workYaw.d[484];
  workYaw.v[485] = workYaw.L[403]*workYaw.d[485];
  workYaw.v[486] = 0-workYaw.L[398]*workYaw.v[421]-workYaw.L[399]*workYaw.v[422]-workYaw.L[400]*workYaw.v[482]-workYaw.L[401]*workYaw.v[483]-workYaw.L[402]*workYaw.v[484]-workYaw.L[403]*workYaw.v[485];
  workYaw.d[486] = workYaw.v[486];
  if (workYaw.d[486] > 0)
    workYaw.d[486] = -settingsYaw.kkt_reg;
  else
    workYaw.d[486] -= settingsYaw.kkt_reg;
  workYaw.d_inv[486] = 1/workYaw.d[486];
  workYaw.L[406] = (-workYaw.L[404]*workYaw.v[484]-workYaw.L[405]*workYaw.v[485])*workYaw.d_inv[486];
  workYaw.L[415] = (-workYaw.L[414]*workYaw.v[485])*workYaw.d_inv[486];
  workYaw.L[420] = (-workYaw.L[418]*workYaw.v[422])*workYaw.d_inv[486];
  workYaw.v[484] = workYaw.L[404]*workYaw.d[484];
  workYaw.v[485] = workYaw.L[405]*workYaw.d[485];
  workYaw.v[486] = workYaw.L[406]*workYaw.d[486];
  workYaw.v[487] = 0-workYaw.L[404]*workYaw.v[484]-workYaw.L[405]*workYaw.v[485]-workYaw.L[406]*workYaw.v[486];
  workYaw.d[487] = workYaw.v[487];
  if (workYaw.d[487] > 0)
    workYaw.d[487] = -settingsYaw.kkt_reg;
  else
    workYaw.d[487] -= settingsYaw.kkt_reg;
  workYaw.d_inv[487] = 1/workYaw.d[487];
  workYaw.L[409] = (workYaw.KKT[985])*workYaw.d_inv[487];
  workYaw.L[416] = (-workYaw.L[414]*workYaw.v[485]-workYaw.L[415]*workYaw.v[486])*workYaw.d_inv[487];
  workYaw.L[421] = (-workYaw.L[420]*workYaw.v[486])*workYaw.d_inv[487];
  workYaw.v[171] = workYaw.L[407]*workYaw.d[171];
  workYaw.v[211] = workYaw.L[408]*workYaw.d[211];
  workYaw.v[487] = workYaw.L[409]*workYaw.d[487];
  workYaw.v[488] = workYaw.KKT[986]-workYaw.L[407]*workYaw.v[171]-workYaw.L[408]*workYaw.v[211]-workYaw.L[409]*workYaw.v[487];
  workYaw.d[488] = workYaw.v[488];
  if (workYaw.d[488] < 0)
    workYaw.d[488] = settingsYaw.kkt_reg;
  else
    workYaw.d[488] += settingsYaw.kkt_reg;
  workYaw.d_inv[488] = 1/workYaw.d[488];
  workYaw.L[417] = (-workYaw.L[416]*workYaw.v[487])*workYaw.d_inv[488];
  workYaw.L[422] = (workYaw.KKT[987]-workYaw.L[421]*workYaw.v[487])*workYaw.d_inv[488];
  workYaw.L[424] = (workYaw.KKT[988])*workYaw.d_inv[488];
  workYaw.v[251] = workYaw.L[410]*workYaw.d[251];
  workYaw.v[291] = workYaw.L[411]*workYaw.d[291];
  workYaw.v[380] = workYaw.L[412]*workYaw.d[380];
  workYaw.v[381] = workYaw.L[413]*workYaw.d[381];
  workYaw.v[485] = workYaw.L[414]*workYaw.d[485];
  workYaw.v[486] = workYaw.L[415]*workYaw.d[486];
  workYaw.v[487] = workYaw.L[416]*workYaw.d[487];
  workYaw.v[488] = workYaw.L[417]*workYaw.d[488];
  workYaw.v[489] = workYaw.KKT[989]-workYaw.L[410]*workYaw.v[251]-workYaw.L[411]*workYaw.v[291]-workYaw.L[412]*workYaw.v[380]-workYaw.L[413]*workYaw.v[381]-workYaw.L[414]*workYaw.v[485]-workYaw.L[415]*workYaw.v[486]-workYaw.L[416]*workYaw.v[487]-workYaw.L[417]*workYaw.v[488];
  workYaw.d[489] = workYaw.v[489];
  if (workYaw.d[489] < 0)
    workYaw.d[489] = settingsYaw.kkt_reg;
  else
    workYaw.d[489] += settingsYaw.kkt_reg;
  workYaw.d_inv[489] = 1/workYaw.d[489];
  workYaw.L[423] = (-workYaw.L[420]*workYaw.v[486]-workYaw.L[421]*workYaw.v[487]-workYaw.L[422]*workYaw.v[488])*workYaw.d_inv[489];
  workYaw.L[425] = (workYaw.KKT[990]-workYaw.L[424]*workYaw.v[488])*workYaw.d_inv[489];
  workYaw.L[434] = (-workYaw.L[432]*workYaw.v[381])*workYaw.d_inv[489];
  workYaw.v[422] = workYaw.L[418]*workYaw.d[422];
  workYaw.v[423] = workYaw.L[419]*workYaw.d[423];
  workYaw.v[486] = workYaw.L[420]*workYaw.d[486];
  workYaw.v[487] = workYaw.L[421]*workYaw.d[487];
  workYaw.v[488] = workYaw.L[422]*workYaw.d[488];
  workYaw.v[489] = workYaw.L[423]*workYaw.d[489];
  workYaw.v[490] = 0-workYaw.L[418]*workYaw.v[422]-workYaw.L[419]*workYaw.v[423]-workYaw.L[420]*workYaw.v[486]-workYaw.L[421]*workYaw.v[487]-workYaw.L[422]*workYaw.v[488]-workYaw.L[423]*workYaw.v[489];
  workYaw.d[490] = workYaw.v[490];
  if (workYaw.d[490] > 0)
    workYaw.d[490] = -settingsYaw.kkt_reg;
  else
    workYaw.d[490] -= settingsYaw.kkt_reg;
  workYaw.d_inv[490] = 1/workYaw.d[490];
  workYaw.L[426] = (-workYaw.L[424]*workYaw.v[488]-workYaw.L[425]*workYaw.v[489])*workYaw.d_inv[490];
  workYaw.L[435] = (-workYaw.L[434]*workYaw.v[489])*workYaw.d_inv[490];
  workYaw.L[440] = (-workYaw.L[438]*workYaw.v[423])*workYaw.d_inv[490];
  workYaw.v[488] = workYaw.L[424]*workYaw.d[488];
  workYaw.v[489] = workYaw.L[425]*workYaw.d[489];
  workYaw.v[490] = workYaw.L[426]*workYaw.d[490];
  workYaw.v[491] = 0-workYaw.L[424]*workYaw.v[488]-workYaw.L[425]*workYaw.v[489]-workYaw.L[426]*workYaw.v[490];
  workYaw.d[491] = workYaw.v[491];
  if (workYaw.d[491] > 0)
    workYaw.d[491] = -settingsYaw.kkt_reg;
  else
    workYaw.d[491] -= settingsYaw.kkt_reg;
  workYaw.d_inv[491] = 1/workYaw.d[491];
  workYaw.L[429] = (workYaw.KKT[991])*workYaw.d_inv[491];
  workYaw.L[436] = (-workYaw.L[434]*workYaw.v[489]-workYaw.L[435]*workYaw.v[490])*workYaw.d_inv[491];
  workYaw.L[441] = (-workYaw.L[440]*workYaw.v[490])*workYaw.d_inv[491];
  workYaw.v[172] = workYaw.L[427]*workYaw.d[172];
  workYaw.v[212] = workYaw.L[428]*workYaw.d[212];
  workYaw.v[491] = workYaw.L[429]*workYaw.d[491];
  workYaw.v[492] = workYaw.KKT[992]-workYaw.L[427]*workYaw.v[172]-workYaw.L[428]*workYaw.v[212]-workYaw.L[429]*workYaw.v[491];
  workYaw.d[492] = workYaw.v[492];
  if (workYaw.d[492] < 0)
    workYaw.d[492] = settingsYaw.kkt_reg;
  else
    workYaw.d[492] += settingsYaw.kkt_reg;
  workYaw.d_inv[492] = 1/workYaw.d[492];
  workYaw.L[437] = (-workYaw.L[436]*workYaw.v[491])*workYaw.d_inv[492];
  workYaw.L[442] = (workYaw.KKT[993]-workYaw.L[441]*workYaw.v[491])*workYaw.d_inv[492];
  workYaw.L[444] = (workYaw.KKT[994])*workYaw.d_inv[492];
  workYaw.v[252] = workYaw.L[430]*workYaw.d[252];
  workYaw.v[292] = workYaw.L[431]*workYaw.d[292];
  workYaw.v[381] = workYaw.L[432]*workYaw.d[381];
  workYaw.v[382] = workYaw.L[433]*workYaw.d[382];
  workYaw.v[489] = workYaw.L[434]*workYaw.d[489];
  workYaw.v[490] = workYaw.L[435]*workYaw.d[490];
  workYaw.v[491] = workYaw.L[436]*workYaw.d[491];
  workYaw.v[492] = workYaw.L[437]*workYaw.d[492];
  workYaw.v[493] = workYaw.KKT[995]-workYaw.L[430]*workYaw.v[252]-workYaw.L[431]*workYaw.v[292]-workYaw.L[432]*workYaw.v[381]-workYaw.L[433]*workYaw.v[382]-workYaw.L[434]*workYaw.v[489]-workYaw.L[435]*workYaw.v[490]-workYaw.L[436]*workYaw.v[491]-workYaw.L[437]*workYaw.v[492];
  workYaw.d[493] = workYaw.v[493];
  if (workYaw.d[493] < 0)
    workYaw.d[493] = settingsYaw.kkt_reg;
  else
    workYaw.d[493] += settingsYaw.kkt_reg;
  workYaw.d_inv[493] = 1/workYaw.d[493];
  workYaw.L[443] = (-workYaw.L[440]*workYaw.v[490]-workYaw.L[441]*workYaw.v[491]-workYaw.L[442]*workYaw.v[492])*workYaw.d_inv[493];
  workYaw.L[445] = (workYaw.KKT[996]-workYaw.L[444]*workYaw.v[492])*workYaw.d_inv[493];
  workYaw.L[454] = (-workYaw.L[452]*workYaw.v[382])*workYaw.d_inv[493];
  workYaw.v[423] = workYaw.L[438]*workYaw.d[423];
  workYaw.v[424] = workYaw.L[439]*workYaw.d[424];
  workYaw.v[490] = workYaw.L[440]*workYaw.d[490];
  workYaw.v[491] = workYaw.L[441]*workYaw.d[491];
  workYaw.v[492] = workYaw.L[442]*workYaw.d[492];
  workYaw.v[493] = workYaw.L[443]*workYaw.d[493];
  workYaw.v[494] = 0-workYaw.L[438]*workYaw.v[423]-workYaw.L[439]*workYaw.v[424]-workYaw.L[440]*workYaw.v[490]-workYaw.L[441]*workYaw.v[491]-workYaw.L[442]*workYaw.v[492]-workYaw.L[443]*workYaw.v[493];
  workYaw.d[494] = workYaw.v[494];
  if (workYaw.d[494] > 0)
    workYaw.d[494] = -settingsYaw.kkt_reg;
  else
    workYaw.d[494] -= settingsYaw.kkt_reg;
  workYaw.d_inv[494] = 1/workYaw.d[494];
  workYaw.L[446] = (-workYaw.L[444]*workYaw.v[492]-workYaw.L[445]*workYaw.v[493])*workYaw.d_inv[494];
  workYaw.L[455] = (-workYaw.L[454]*workYaw.v[493])*workYaw.d_inv[494];
  workYaw.L[460] = (-workYaw.L[458]*workYaw.v[424])*workYaw.d_inv[494];
  workYaw.v[492] = workYaw.L[444]*workYaw.d[492];
  workYaw.v[493] = workYaw.L[445]*workYaw.d[493];
  workYaw.v[494] = workYaw.L[446]*workYaw.d[494];
  workYaw.v[495] = 0-workYaw.L[444]*workYaw.v[492]-workYaw.L[445]*workYaw.v[493]-workYaw.L[446]*workYaw.v[494];
  workYaw.d[495] = workYaw.v[495];
  if (workYaw.d[495] > 0)
    workYaw.d[495] = -settingsYaw.kkt_reg;
  else
    workYaw.d[495] -= settingsYaw.kkt_reg;
  workYaw.d_inv[495] = 1/workYaw.d[495];
  workYaw.L[449] = (workYaw.KKT[997])*workYaw.d_inv[495];
  workYaw.L[456] = (-workYaw.L[454]*workYaw.v[493]-workYaw.L[455]*workYaw.v[494])*workYaw.d_inv[495];
  workYaw.L[461] = (-workYaw.L[460]*workYaw.v[494])*workYaw.d_inv[495];
  workYaw.v[173] = workYaw.L[447]*workYaw.d[173];
  workYaw.v[213] = workYaw.L[448]*workYaw.d[213];
  workYaw.v[495] = workYaw.L[449]*workYaw.d[495];
  workYaw.v[496] = workYaw.KKT[998]-workYaw.L[447]*workYaw.v[173]-workYaw.L[448]*workYaw.v[213]-workYaw.L[449]*workYaw.v[495];
  workYaw.d[496] = workYaw.v[496];
  if (workYaw.d[496] < 0)
    workYaw.d[496] = settingsYaw.kkt_reg;
  else
    workYaw.d[496] += settingsYaw.kkt_reg;
  workYaw.d_inv[496] = 1/workYaw.d[496];
  workYaw.L[457] = (-workYaw.L[456]*workYaw.v[495])*workYaw.d_inv[496];
  workYaw.L[462] = (workYaw.KKT[999]-workYaw.L[461]*workYaw.v[495])*workYaw.d_inv[496];
  workYaw.L[464] = (workYaw.KKT[1000])*workYaw.d_inv[496];
  workYaw.v[253] = workYaw.L[450]*workYaw.d[253];
  workYaw.v[293] = workYaw.L[451]*workYaw.d[293];
  workYaw.v[382] = workYaw.L[452]*workYaw.d[382];
  workYaw.v[383] = workYaw.L[453]*workYaw.d[383];
  workYaw.v[493] = workYaw.L[454]*workYaw.d[493];
  workYaw.v[494] = workYaw.L[455]*workYaw.d[494];
  workYaw.v[495] = workYaw.L[456]*workYaw.d[495];
  workYaw.v[496] = workYaw.L[457]*workYaw.d[496];
  workYaw.v[497] = workYaw.KKT[1001]-workYaw.L[450]*workYaw.v[253]-workYaw.L[451]*workYaw.v[293]-workYaw.L[452]*workYaw.v[382]-workYaw.L[453]*workYaw.v[383]-workYaw.L[454]*workYaw.v[493]-workYaw.L[455]*workYaw.v[494]-workYaw.L[456]*workYaw.v[495]-workYaw.L[457]*workYaw.v[496];
  workYaw.d[497] = workYaw.v[497];
  if (workYaw.d[497] < 0)
    workYaw.d[497] = settingsYaw.kkt_reg;
  else
    workYaw.d[497] += settingsYaw.kkt_reg;
  workYaw.d_inv[497] = 1/workYaw.d[497];
  workYaw.L[463] = (-workYaw.L[460]*workYaw.v[494]-workYaw.L[461]*workYaw.v[495]-workYaw.L[462]*workYaw.v[496])*workYaw.d_inv[497];
  workYaw.L[465] = (workYaw.KKT[1002]-workYaw.L[464]*workYaw.v[496])*workYaw.d_inv[497];
  workYaw.L[474] = (-workYaw.L[472]*workYaw.v[383])*workYaw.d_inv[497];
  workYaw.v[424] = workYaw.L[458]*workYaw.d[424];
  workYaw.v[425] = workYaw.L[459]*workYaw.d[425];
  workYaw.v[494] = workYaw.L[460]*workYaw.d[494];
  workYaw.v[495] = workYaw.L[461]*workYaw.d[495];
  workYaw.v[496] = workYaw.L[462]*workYaw.d[496];
  workYaw.v[497] = workYaw.L[463]*workYaw.d[497];
  workYaw.v[498] = 0-workYaw.L[458]*workYaw.v[424]-workYaw.L[459]*workYaw.v[425]-workYaw.L[460]*workYaw.v[494]-workYaw.L[461]*workYaw.v[495]-workYaw.L[462]*workYaw.v[496]-workYaw.L[463]*workYaw.v[497];
  workYaw.d[498] = workYaw.v[498];
  if (workYaw.d[498] > 0)
    workYaw.d[498] = -settingsYaw.kkt_reg;
  else
    workYaw.d[498] -= settingsYaw.kkt_reg;
  workYaw.d_inv[498] = 1/workYaw.d[498];
  workYaw.L[466] = (-workYaw.L[464]*workYaw.v[496]-workYaw.L[465]*workYaw.v[497])*workYaw.d_inv[498];
  workYaw.L[475] = (-workYaw.L[474]*workYaw.v[497])*workYaw.d_inv[498];
  workYaw.L[480] = (-workYaw.L[478]*workYaw.v[425])*workYaw.d_inv[498];
  workYaw.v[496] = workYaw.L[464]*workYaw.d[496];
  workYaw.v[497] = workYaw.L[465]*workYaw.d[497];
  workYaw.v[498] = workYaw.L[466]*workYaw.d[498];
  workYaw.v[499] = 0-workYaw.L[464]*workYaw.v[496]-workYaw.L[465]*workYaw.v[497]-workYaw.L[466]*workYaw.v[498];
  workYaw.d[499] = workYaw.v[499];
  if (workYaw.d[499] > 0)
    workYaw.d[499] = -settingsYaw.kkt_reg;
  else
    workYaw.d[499] -= settingsYaw.kkt_reg;
  workYaw.d_inv[499] = 1/workYaw.d[499];
  workYaw.L[469] = (workYaw.KKT[1003])*workYaw.d_inv[499];
  workYaw.L[476] = (-workYaw.L[474]*workYaw.v[497]-workYaw.L[475]*workYaw.v[498])*workYaw.d_inv[499];
  workYaw.L[481] = (-workYaw.L[480]*workYaw.v[498])*workYaw.d_inv[499];
  workYaw.v[174] = workYaw.L[467]*workYaw.d[174];
  workYaw.v[214] = workYaw.L[468]*workYaw.d[214];
  workYaw.v[499] = workYaw.L[469]*workYaw.d[499];
  workYaw.v[500] = workYaw.KKT[1004]-workYaw.L[467]*workYaw.v[174]-workYaw.L[468]*workYaw.v[214]-workYaw.L[469]*workYaw.v[499];
  workYaw.d[500] = workYaw.v[500];
  if (workYaw.d[500] < 0)
    workYaw.d[500] = settingsYaw.kkt_reg;
  else
    workYaw.d[500] += settingsYaw.kkt_reg;
  workYaw.d_inv[500] = 1/workYaw.d[500];
  workYaw.L[477] = (-workYaw.L[476]*workYaw.v[499])*workYaw.d_inv[500];
  workYaw.L[482] = (workYaw.KKT[1005]-workYaw.L[481]*workYaw.v[499])*workYaw.d_inv[500];
  workYaw.L[484] = (workYaw.KKT[1006])*workYaw.d_inv[500];
  workYaw.v[254] = workYaw.L[470]*workYaw.d[254];
  workYaw.v[294] = workYaw.L[471]*workYaw.d[294];
  workYaw.v[383] = workYaw.L[472]*workYaw.d[383];
  workYaw.v[384] = workYaw.L[473]*workYaw.d[384];
  workYaw.v[497] = workYaw.L[474]*workYaw.d[497];
  workYaw.v[498] = workYaw.L[475]*workYaw.d[498];
  workYaw.v[499] = workYaw.L[476]*workYaw.d[499];
  workYaw.v[500] = workYaw.L[477]*workYaw.d[500];
  workYaw.v[501] = workYaw.KKT[1007]-workYaw.L[470]*workYaw.v[254]-workYaw.L[471]*workYaw.v[294]-workYaw.L[472]*workYaw.v[383]-workYaw.L[473]*workYaw.v[384]-workYaw.L[474]*workYaw.v[497]-workYaw.L[475]*workYaw.v[498]-workYaw.L[476]*workYaw.v[499]-workYaw.L[477]*workYaw.v[500];
  workYaw.d[501] = workYaw.v[501];
  if (workYaw.d[501] < 0)
    workYaw.d[501] = settingsYaw.kkt_reg;
  else
    workYaw.d[501] += settingsYaw.kkt_reg;
  workYaw.d_inv[501] = 1/workYaw.d[501];
  workYaw.L[483] = (-workYaw.L[480]*workYaw.v[498]-workYaw.L[481]*workYaw.v[499]-workYaw.L[482]*workYaw.v[500])*workYaw.d_inv[501];
  workYaw.L[485] = (workYaw.KKT[1008]-workYaw.L[484]*workYaw.v[500])*workYaw.d_inv[501];
  workYaw.L[494] = (-workYaw.L[492]*workYaw.v[384])*workYaw.d_inv[501];
  workYaw.v[425] = workYaw.L[478]*workYaw.d[425];
  workYaw.v[426] = workYaw.L[479]*workYaw.d[426];
  workYaw.v[498] = workYaw.L[480]*workYaw.d[498];
  workYaw.v[499] = workYaw.L[481]*workYaw.d[499];
  workYaw.v[500] = workYaw.L[482]*workYaw.d[500];
  workYaw.v[501] = workYaw.L[483]*workYaw.d[501];
  workYaw.v[502] = 0-workYaw.L[478]*workYaw.v[425]-workYaw.L[479]*workYaw.v[426]-workYaw.L[480]*workYaw.v[498]-workYaw.L[481]*workYaw.v[499]-workYaw.L[482]*workYaw.v[500]-workYaw.L[483]*workYaw.v[501];
  workYaw.d[502] = workYaw.v[502];
  if (workYaw.d[502] > 0)
    workYaw.d[502] = -settingsYaw.kkt_reg;
  else
    workYaw.d[502] -= settingsYaw.kkt_reg;
  workYaw.d_inv[502] = 1/workYaw.d[502];
  workYaw.L[486] = (-workYaw.L[484]*workYaw.v[500]-workYaw.L[485]*workYaw.v[501])*workYaw.d_inv[502];
  workYaw.L[495] = (-workYaw.L[494]*workYaw.v[501])*workYaw.d_inv[502];
  workYaw.L[500] = (-workYaw.L[498]*workYaw.v[426])*workYaw.d_inv[502];
  workYaw.v[500] = workYaw.L[484]*workYaw.d[500];
  workYaw.v[501] = workYaw.L[485]*workYaw.d[501];
  workYaw.v[502] = workYaw.L[486]*workYaw.d[502];
  workYaw.v[503] = 0-workYaw.L[484]*workYaw.v[500]-workYaw.L[485]*workYaw.v[501]-workYaw.L[486]*workYaw.v[502];
  workYaw.d[503] = workYaw.v[503];
  if (workYaw.d[503] > 0)
    workYaw.d[503] = -settingsYaw.kkt_reg;
  else
    workYaw.d[503] -= settingsYaw.kkt_reg;
  workYaw.d_inv[503] = 1/workYaw.d[503];
  workYaw.L[489] = (workYaw.KKT[1009])*workYaw.d_inv[503];
  workYaw.L[496] = (-workYaw.L[494]*workYaw.v[501]-workYaw.L[495]*workYaw.v[502])*workYaw.d_inv[503];
  workYaw.L[501] = (-workYaw.L[500]*workYaw.v[502])*workYaw.d_inv[503];
  workYaw.v[175] = workYaw.L[487]*workYaw.d[175];
  workYaw.v[215] = workYaw.L[488]*workYaw.d[215];
  workYaw.v[503] = workYaw.L[489]*workYaw.d[503];
  workYaw.v[504] = workYaw.KKT[1010]-workYaw.L[487]*workYaw.v[175]-workYaw.L[488]*workYaw.v[215]-workYaw.L[489]*workYaw.v[503];
  workYaw.d[504] = workYaw.v[504];
  if (workYaw.d[504] < 0)
    workYaw.d[504] = settingsYaw.kkt_reg;
  else
    workYaw.d[504] += settingsYaw.kkt_reg;
  workYaw.d_inv[504] = 1/workYaw.d[504];
  workYaw.L[497] = (-workYaw.L[496]*workYaw.v[503])*workYaw.d_inv[504];
  workYaw.L[502] = (workYaw.KKT[1011]-workYaw.L[501]*workYaw.v[503])*workYaw.d_inv[504];
  workYaw.L[504] = (workYaw.KKT[1012])*workYaw.d_inv[504];
  workYaw.v[255] = workYaw.L[490]*workYaw.d[255];
  workYaw.v[295] = workYaw.L[491]*workYaw.d[295];
  workYaw.v[384] = workYaw.L[492]*workYaw.d[384];
  workYaw.v[385] = workYaw.L[493]*workYaw.d[385];
  workYaw.v[501] = workYaw.L[494]*workYaw.d[501];
  workYaw.v[502] = workYaw.L[495]*workYaw.d[502];
  workYaw.v[503] = workYaw.L[496]*workYaw.d[503];
  workYaw.v[504] = workYaw.L[497]*workYaw.d[504];
  workYaw.v[505] = workYaw.KKT[1013]-workYaw.L[490]*workYaw.v[255]-workYaw.L[491]*workYaw.v[295]-workYaw.L[492]*workYaw.v[384]-workYaw.L[493]*workYaw.v[385]-workYaw.L[494]*workYaw.v[501]-workYaw.L[495]*workYaw.v[502]-workYaw.L[496]*workYaw.v[503]-workYaw.L[497]*workYaw.v[504];
  workYaw.d[505] = workYaw.v[505];
  if (workYaw.d[505] < 0)
    workYaw.d[505] = settingsYaw.kkt_reg;
  else
    workYaw.d[505] += settingsYaw.kkt_reg;
  workYaw.d_inv[505] = 1/workYaw.d[505];
  workYaw.L[503] = (-workYaw.L[500]*workYaw.v[502]-workYaw.L[501]*workYaw.v[503]-workYaw.L[502]*workYaw.v[504])*workYaw.d_inv[505];
  workYaw.L[505] = (workYaw.KKT[1014]-workYaw.L[504]*workYaw.v[504])*workYaw.d_inv[505];
  workYaw.L[514] = (-workYaw.L[512]*workYaw.v[385])*workYaw.d_inv[505];
  workYaw.v[426] = workYaw.L[498]*workYaw.d[426];
  workYaw.v[427] = workYaw.L[499]*workYaw.d[427];
  workYaw.v[502] = workYaw.L[500]*workYaw.d[502];
  workYaw.v[503] = workYaw.L[501]*workYaw.d[503];
  workYaw.v[504] = workYaw.L[502]*workYaw.d[504];
  workYaw.v[505] = workYaw.L[503]*workYaw.d[505];
  workYaw.v[506] = 0-workYaw.L[498]*workYaw.v[426]-workYaw.L[499]*workYaw.v[427]-workYaw.L[500]*workYaw.v[502]-workYaw.L[501]*workYaw.v[503]-workYaw.L[502]*workYaw.v[504]-workYaw.L[503]*workYaw.v[505];
  workYaw.d[506] = workYaw.v[506];
  if (workYaw.d[506] > 0)
    workYaw.d[506] = -settingsYaw.kkt_reg;
  else
    workYaw.d[506] -= settingsYaw.kkt_reg;
  workYaw.d_inv[506] = 1/workYaw.d[506];
  workYaw.L[506] = (-workYaw.L[504]*workYaw.v[504]-workYaw.L[505]*workYaw.v[505])*workYaw.d_inv[506];
  workYaw.L[515] = (-workYaw.L[514]*workYaw.v[505])*workYaw.d_inv[506];
  workYaw.L[520] = (-workYaw.L[518]*workYaw.v[427])*workYaw.d_inv[506];
  workYaw.v[504] = workYaw.L[504]*workYaw.d[504];
  workYaw.v[505] = workYaw.L[505]*workYaw.d[505];
  workYaw.v[506] = workYaw.L[506]*workYaw.d[506];
  workYaw.v[507] = 0-workYaw.L[504]*workYaw.v[504]-workYaw.L[505]*workYaw.v[505]-workYaw.L[506]*workYaw.v[506];
  workYaw.d[507] = workYaw.v[507];
  if (workYaw.d[507] > 0)
    workYaw.d[507] = -settingsYaw.kkt_reg;
  else
    workYaw.d[507] -= settingsYaw.kkt_reg;
  workYaw.d_inv[507] = 1/workYaw.d[507];
  workYaw.L[509] = (workYaw.KKT[1015])*workYaw.d_inv[507];
  workYaw.L[516] = (-workYaw.L[514]*workYaw.v[505]-workYaw.L[515]*workYaw.v[506])*workYaw.d_inv[507];
  workYaw.L[521] = (-workYaw.L[520]*workYaw.v[506])*workYaw.d_inv[507];
  workYaw.v[176] = workYaw.L[507]*workYaw.d[176];
  workYaw.v[216] = workYaw.L[508]*workYaw.d[216];
  workYaw.v[507] = workYaw.L[509]*workYaw.d[507];
  workYaw.v[508] = workYaw.KKT[1016]-workYaw.L[507]*workYaw.v[176]-workYaw.L[508]*workYaw.v[216]-workYaw.L[509]*workYaw.v[507];
  workYaw.d[508] = workYaw.v[508];
  if (workYaw.d[508] < 0)
    workYaw.d[508] = settingsYaw.kkt_reg;
  else
    workYaw.d[508] += settingsYaw.kkt_reg;
  workYaw.d_inv[508] = 1/workYaw.d[508];
  workYaw.L[517] = (-workYaw.L[516]*workYaw.v[507])*workYaw.d_inv[508];
  workYaw.L[522] = (workYaw.KKT[1017]-workYaw.L[521]*workYaw.v[507])*workYaw.d_inv[508];
  workYaw.L[524] = (workYaw.KKT[1018])*workYaw.d_inv[508];
  workYaw.v[256] = workYaw.L[510]*workYaw.d[256];
  workYaw.v[296] = workYaw.L[511]*workYaw.d[296];
  workYaw.v[385] = workYaw.L[512]*workYaw.d[385];
  workYaw.v[386] = workYaw.L[513]*workYaw.d[386];
  workYaw.v[505] = workYaw.L[514]*workYaw.d[505];
  workYaw.v[506] = workYaw.L[515]*workYaw.d[506];
  workYaw.v[507] = workYaw.L[516]*workYaw.d[507];
  workYaw.v[508] = workYaw.L[517]*workYaw.d[508];
  workYaw.v[509] = workYaw.KKT[1019]-workYaw.L[510]*workYaw.v[256]-workYaw.L[511]*workYaw.v[296]-workYaw.L[512]*workYaw.v[385]-workYaw.L[513]*workYaw.v[386]-workYaw.L[514]*workYaw.v[505]-workYaw.L[515]*workYaw.v[506]-workYaw.L[516]*workYaw.v[507]-workYaw.L[517]*workYaw.v[508];
  workYaw.d[509] = workYaw.v[509];
  if (workYaw.d[509] < 0)
    workYaw.d[509] = settingsYaw.kkt_reg;
  else
    workYaw.d[509] += settingsYaw.kkt_reg;
  workYaw.d_inv[509] = 1/workYaw.d[509];
  workYaw.L[523] = (-workYaw.L[520]*workYaw.v[506]-workYaw.L[521]*workYaw.v[507]-workYaw.L[522]*workYaw.v[508])*workYaw.d_inv[509];
  workYaw.L[525] = (workYaw.KKT[1020]-workYaw.L[524]*workYaw.v[508])*workYaw.d_inv[509];
  workYaw.L[534] = (-workYaw.L[532]*workYaw.v[386])*workYaw.d_inv[509];
  workYaw.v[427] = workYaw.L[518]*workYaw.d[427];
  workYaw.v[428] = workYaw.L[519]*workYaw.d[428];
  workYaw.v[506] = workYaw.L[520]*workYaw.d[506];
  workYaw.v[507] = workYaw.L[521]*workYaw.d[507];
  workYaw.v[508] = workYaw.L[522]*workYaw.d[508];
  workYaw.v[509] = workYaw.L[523]*workYaw.d[509];
  workYaw.v[510] = 0-workYaw.L[518]*workYaw.v[427]-workYaw.L[519]*workYaw.v[428]-workYaw.L[520]*workYaw.v[506]-workYaw.L[521]*workYaw.v[507]-workYaw.L[522]*workYaw.v[508]-workYaw.L[523]*workYaw.v[509];
  workYaw.d[510] = workYaw.v[510];
  if (workYaw.d[510] > 0)
    workYaw.d[510] = -settingsYaw.kkt_reg;
  else
    workYaw.d[510] -= settingsYaw.kkt_reg;
  workYaw.d_inv[510] = 1/workYaw.d[510];
  workYaw.L[526] = (-workYaw.L[524]*workYaw.v[508]-workYaw.L[525]*workYaw.v[509])*workYaw.d_inv[510];
  workYaw.L[535] = (-workYaw.L[534]*workYaw.v[509])*workYaw.d_inv[510];
  workYaw.L[540] = (-workYaw.L[538]*workYaw.v[428])*workYaw.d_inv[510];
  workYaw.v[508] = workYaw.L[524]*workYaw.d[508];
  workYaw.v[509] = workYaw.L[525]*workYaw.d[509];
  workYaw.v[510] = workYaw.L[526]*workYaw.d[510];
  workYaw.v[511] = 0-workYaw.L[524]*workYaw.v[508]-workYaw.L[525]*workYaw.v[509]-workYaw.L[526]*workYaw.v[510];
  workYaw.d[511] = workYaw.v[511];
  if (workYaw.d[511] > 0)
    workYaw.d[511] = -settingsYaw.kkt_reg;
  else
    workYaw.d[511] -= settingsYaw.kkt_reg;
  workYaw.d_inv[511] = 1/workYaw.d[511];
  workYaw.L[529] = (workYaw.KKT[1021])*workYaw.d_inv[511];
  workYaw.L[536] = (-workYaw.L[534]*workYaw.v[509]-workYaw.L[535]*workYaw.v[510])*workYaw.d_inv[511];
  workYaw.L[541] = (-workYaw.L[540]*workYaw.v[510])*workYaw.d_inv[511];
  workYaw.v[177] = workYaw.L[527]*workYaw.d[177];
  workYaw.v[217] = workYaw.L[528]*workYaw.d[217];
  workYaw.v[511] = workYaw.L[529]*workYaw.d[511];
  workYaw.v[512] = workYaw.KKT[1022]-workYaw.L[527]*workYaw.v[177]-workYaw.L[528]*workYaw.v[217]-workYaw.L[529]*workYaw.v[511];
  workYaw.d[512] = workYaw.v[512];
  if (workYaw.d[512] < 0)
    workYaw.d[512] = settingsYaw.kkt_reg;
  else
    workYaw.d[512] += settingsYaw.kkt_reg;
  workYaw.d_inv[512] = 1/workYaw.d[512];
  workYaw.L[537] = (-workYaw.L[536]*workYaw.v[511])*workYaw.d_inv[512];
  workYaw.L[542] = (workYaw.KKT[1023]-workYaw.L[541]*workYaw.v[511])*workYaw.d_inv[512];
  workYaw.L[544] = (workYaw.KKT[1024])*workYaw.d_inv[512];
  workYaw.v[257] = workYaw.L[530]*workYaw.d[257];
  workYaw.v[297] = workYaw.L[531]*workYaw.d[297];
  workYaw.v[386] = workYaw.L[532]*workYaw.d[386];
  workYaw.v[387] = workYaw.L[533]*workYaw.d[387];
  workYaw.v[509] = workYaw.L[534]*workYaw.d[509];
  workYaw.v[510] = workYaw.L[535]*workYaw.d[510];
  workYaw.v[511] = workYaw.L[536]*workYaw.d[511];
  workYaw.v[512] = workYaw.L[537]*workYaw.d[512];
  workYaw.v[513] = workYaw.KKT[1025]-workYaw.L[530]*workYaw.v[257]-workYaw.L[531]*workYaw.v[297]-workYaw.L[532]*workYaw.v[386]-workYaw.L[533]*workYaw.v[387]-workYaw.L[534]*workYaw.v[509]-workYaw.L[535]*workYaw.v[510]-workYaw.L[536]*workYaw.v[511]-workYaw.L[537]*workYaw.v[512];
  workYaw.d[513] = workYaw.v[513];
  if (workYaw.d[513] < 0)
    workYaw.d[513] = settingsYaw.kkt_reg;
  else
    workYaw.d[513] += settingsYaw.kkt_reg;
  workYaw.d_inv[513] = 1/workYaw.d[513];
  workYaw.L[543] = (-workYaw.L[540]*workYaw.v[510]-workYaw.L[541]*workYaw.v[511]-workYaw.L[542]*workYaw.v[512])*workYaw.d_inv[513];
  workYaw.L[545] = (workYaw.KKT[1026]-workYaw.L[544]*workYaw.v[512])*workYaw.d_inv[513];
  workYaw.L[554] = (-workYaw.L[552]*workYaw.v[387])*workYaw.d_inv[513];
  workYaw.v[428] = workYaw.L[538]*workYaw.d[428];
  workYaw.v[429] = workYaw.L[539]*workYaw.d[429];
  workYaw.v[510] = workYaw.L[540]*workYaw.d[510];
  workYaw.v[511] = workYaw.L[541]*workYaw.d[511];
  workYaw.v[512] = workYaw.L[542]*workYaw.d[512];
  workYaw.v[513] = workYaw.L[543]*workYaw.d[513];
  workYaw.v[514] = 0-workYaw.L[538]*workYaw.v[428]-workYaw.L[539]*workYaw.v[429]-workYaw.L[540]*workYaw.v[510]-workYaw.L[541]*workYaw.v[511]-workYaw.L[542]*workYaw.v[512]-workYaw.L[543]*workYaw.v[513];
  workYaw.d[514] = workYaw.v[514];
  if (workYaw.d[514] > 0)
    workYaw.d[514] = -settingsYaw.kkt_reg;
  else
    workYaw.d[514] -= settingsYaw.kkt_reg;
  workYaw.d_inv[514] = 1/workYaw.d[514];
  workYaw.L[546] = (-workYaw.L[544]*workYaw.v[512]-workYaw.L[545]*workYaw.v[513])*workYaw.d_inv[514];
  workYaw.L[555] = (-workYaw.L[554]*workYaw.v[513])*workYaw.d_inv[514];
  workYaw.L[560] = (-workYaw.L[558]*workYaw.v[429])*workYaw.d_inv[514];
  workYaw.v[512] = workYaw.L[544]*workYaw.d[512];
  workYaw.v[513] = workYaw.L[545]*workYaw.d[513];
  workYaw.v[514] = workYaw.L[546]*workYaw.d[514];
  workYaw.v[515] = 0-workYaw.L[544]*workYaw.v[512]-workYaw.L[545]*workYaw.v[513]-workYaw.L[546]*workYaw.v[514];
  workYaw.d[515] = workYaw.v[515];
  if (workYaw.d[515] > 0)
    workYaw.d[515] = -settingsYaw.kkt_reg;
  else
    workYaw.d[515] -= settingsYaw.kkt_reg;
  workYaw.d_inv[515] = 1/workYaw.d[515];
  workYaw.L[549] = (workYaw.KKT[1027])*workYaw.d_inv[515];
  workYaw.L[556] = (-workYaw.L[554]*workYaw.v[513]-workYaw.L[555]*workYaw.v[514])*workYaw.d_inv[515];
  workYaw.L[561] = (-workYaw.L[560]*workYaw.v[514])*workYaw.d_inv[515];
  workYaw.v[178] = workYaw.L[547]*workYaw.d[178];
  workYaw.v[218] = workYaw.L[548]*workYaw.d[218];
  workYaw.v[515] = workYaw.L[549]*workYaw.d[515];
  workYaw.v[516] = workYaw.KKT[1028]-workYaw.L[547]*workYaw.v[178]-workYaw.L[548]*workYaw.v[218]-workYaw.L[549]*workYaw.v[515];
  workYaw.d[516] = workYaw.v[516];
  if (workYaw.d[516] < 0)
    workYaw.d[516] = settingsYaw.kkt_reg;
  else
    workYaw.d[516] += settingsYaw.kkt_reg;
  workYaw.d_inv[516] = 1/workYaw.d[516];
  workYaw.L[557] = (-workYaw.L[556]*workYaw.v[515])*workYaw.d_inv[516];
  workYaw.L[562] = (workYaw.KKT[1029]-workYaw.L[561]*workYaw.v[515])*workYaw.d_inv[516];
  workYaw.L[564] = (workYaw.KKT[1030])*workYaw.d_inv[516];
  workYaw.v[258] = workYaw.L[550]*workYaw.d[258];
  workYaw.v[298] = workYaw.L[551]*workYaw.d[298];
  workYaw.v[387] = workYaw.L[552]*workYaw.d[387];
  workYaw.v[388] = workYaw.L[553]*workYaw.d[388];
  workYaw.v[513] = workYaw.L[554]*workYaw.d[513];
  workYaw.v[514] = workYaw.L[555]*workYaw.d[514];
  workYaw.v[515] = workYaw.L[556]*workYaw.d[515];
  workYaw.v[516] = workYaw.L[557]*workYaw.d[516];
  workYaw.v[517] = workYaw.KKT[1031]-workYaw.L[550]*workYaw.v[258]-workYaw.L[551]*workYaw.v[298]-workYaw.L[552]*workYaw.v[387]-workYaw.L[553]*workYaw.v[388]-workYaw.L[554]*workYaw.v[513]-workYaw.L[555]*workYaw.v[514]-workYaw.L[556]*workYaw.v[515]-workYaw.L[557]*workYaw.v[516];
  workYaw.d[517] = workYaw.v[517];
  if (workYaw.d[517] < 0)
    workYaw.d[517] = settingsYaw.kkt_reg;
  else
    workYaw.d[517] += settingsYaw.kkt_reg;
  workYaw.d_inv[517] = 1/workYaw.d[517];
  workYaw.L[563] = (-workYaw.L[560]*workYaw.v[514]-workYaw.L[561]*workYaw.v[515]-workYaw.L[562]*workYaw.v[516])*workYaw.d_inv[517];
  workYaw.L[565] = (workYaw.KKT[1032]-workYaw.L[564]*workYaw.v[516])*workYaw.d_inv[517];
  workYaw.L[574] = (-workYaw.L[572]*workYaw.v[388])*workYaw.d_inv[517];
  workYaw.v[429] = workYaw.L[558]*workYaw.d[429];
  workYaw.v[430] = workYaw.L[559]*workYaw.d[430];
  workYaw.v[514] = workYaw.L[560]*workYaw.d[514];
  workYaw.v[515] = workYaw.L[561]*workYaw.d[515];
  workYaw.v[516] = workYaw.L[562]*workYaw.d[516];
  workYaw.v[517] = workYaw.L[563]*workYaw.d[517];
  workYaw.v[518] = 0-workYaw.L[558]*workYaw.v[429]-workYaw.L[559]*workYaw.v[430]-workYaw.L[560]*workYaw.v[514]-workYaw.L[561]*workYaw.v[515]-workYaw.L[562]*workYaw.v[516]-workYaw.L[563]*workYaw.v[517];
  workYaw.d[518] = workYaw.v[518];
  if (workYaw.d[518] > 0)
    workYaw.d[518] = -settingsYaw.kkt_reg;
  else
    workYaw.d[518] -= settingsYaw.kkt_reg;
  workYaw.d_inv[518] = 1/workYaw.d[518];
  workYaw.L[566] = (-workYaw.L[564]*workYaw.v[516]-workYaw.L[565]*workYaw.v[517])*workYaw.d_inv[518];
  workYaw.L[575] = (-workYaw.L[574]*workYaw.v[517])*workYaw.d_inv[518];
  workYaw.L[580] = (-workYaw.L[578]*workYaw.v[430])*workYaw.d_inv[518];
  workYaw.v[516] = workYaw.L[564]*workYaw.d[516];
  workYaw.v[517] = workYaw.L[565]*workYaw.d[517];
  workYaw.v[518] = workYaw.L[566]*workYaw.d[518];
  workYaw.v[519] = 0-workYaw.L[564]*workYaw.v[516]-workYaw.L[565]*workYaw.v[517]-workYaw.L[566]*workYaw.v[518];
  workYaw.d[519] = workYaw.v[519];
  if (workYaw.d[519] > 0)
    workYaw.d[519] = -settingsYaw.kkt_reg;
  else
    workYaw.d[519] -= settingsYaw.kkt_reg;
  workYaw.d_inv[519] = 1/workYaw.d[519];
  workYaw.L[569] = (workYaw.KKT[1033])*workYaw.d_inv[519];
  workYaw.L[576] = (-workYaw.L[574]*workYaw.v[517]-workYaw.L[575]*workYaw.v[518])*workYaw.d_inv[519];
  workYaw.L[581] = (-workYaw.L[580]*workYaw.v[518])*workYaw.d_inv[519];
  workYaw.v[179] = workYaw.L[567]*workYaw.d[179];
  workYaw.v[219] = workYaw.L[568]*workYaw.d[219];
  workYaw.v[519] = workYaw.L[569]*workYaw.d[519];
  workYaw.v[520] = workYaw.KKT[1034]-workYaw.L[567]*workYaw.v[179]-workYaw.L[568]*workYaw.v[219]-workYaw.L[569]*workYaw.v[519];
  workYaw.d[520] = workYaw.v[520];
  if (workYaw.d[520] < 0)
    workYaw.d[520] = settingsYaw.kkt_reg;
  else
    workYaw.d[520] += settingsYaw.kkt_reg;
  workYaw.d_inv[520] = 1/workYaw.d[520];
  workYaw.L[577] = (-workYaw.L[576]*workYaw.v[519])*workYaw.d_inv[520];
  workYaw.L[582] = (workYaw.KKT[1035]-workYaw.L[581]*workYaw.v[519])*workYaw.d_inv[520];
  workYaw.L[584] = (workYaw.KKT[1036])*workYaw.d_inv[520];
  workYaw.v[259] = workYaw.L[570]*workYaw.d[259];
  workYaw.v[299] = workYaw.L[571]*workYaw.d[299];
  workYaw.v[388] = workYaw.L[572]*workYaw.d[388];
  workYaw.v[389] = workYaw.L[573]*workYaw.d[389];
  workYaw.v[517] = workYaw.L[574]*workYaw.d[517];
  workYaw.v[518] = workYaw.L[575]*workYaw.d[518];
  workYaw.v[519] = workYaw.L[576]*workYaw.d[519];
  workYaw.v[520] = workYaw.L[577]*workYaw.d[520];
  workYaw.v[521] = workYaw.KKT[1037]-workYaw.L[570]*workYaw.v[259]-workYaw.L[571]*workYaw.v[299]-workYaw.L[572]*workYaw.v[388]-workYaw.L[573]*workYaw.v[389]-workYaw.L[574]*workYaw.v[517]-workYaw.L[575]*workYaw.v[518]-workYaw.L[576]*workYaw.v[519]-workYaw.L[577]*workYaw.v[520];
  workYaw.d[521] = workYaw.v[521];
  if (workYaw.d[521] < 0)
    workYaw.d[521] = settingsYaw.kkt_reg;
  else
    workYaw.d[521] += settingsYaw.kkt_reg;
  workYaw.d_inv[521] = 1/workYaw.d[521];
  workYaw.L[583] = (-workYaw.L[580]*workYaw.v[518]-workYaw.L[581]*workYaw.v[519]-workYaw.L[582]*workYaw.v[520])*workYaw.d_inv[521];
  workYaw.L[585] = (workYaw.KKT[1038]-workYaw.L[584]*workYaw.v[520])*workYaw.d_inv[521];
  workYaw.L[594] = (-workYaw.L[592]*workYaw.v[389])*workYaw.d_inv[521];
  workYaw.v[430] = workYaw.L[578]*workYaw.d[430];
  workYaw.v[431] = workYaw.L[579]*workYaw.d[431];
  workYaw.v[518] = workYaw.L[580]*workYaw.d[518];
  workYaw.v[519] = workYaw.L[581]*workYaw.d[519];
  workYaw.v[520] = workYaw.L[582]*workYaw.d[520];
  workYaw.v[521] = workYaw.L[583]*workYaw.d[521];
  workYaw.v[522] = 0-workYaw.L[578]*workYaw.v[430]-workYaw.L[579]*workYaw.v[431]-workYaw.L[580]*workYaw.v[518]-workYaw.L[581]*workYaw.v[519]-workYaw.L[582]*workYaw.v[520]-workYaw.L[583]*workYaw.v[521];
  workYaw.d[522] = workYaw.v[522];
  if (workYaw.d[522] > 0)
    workYaw.d[522] = -settingsYaw.kkt_reg;
  else
    workYaw.d[522] -= settingsYaw.kkt_reg;
  workYaw.d_inv[522] = 1/workYaw.d[522];
  workYaw.L[586] = (-workYaw.L[584]*workYaw.v[520]-workYaw.L[585]*workYaw.v[521])*workYaw.d_inv[522];
  workYaw.L[595] = (-workYaw.L[594]*workYaw.v[521])*workYaw.d_inv[522];
  workYaw.L[600] = (-workYaw.L[598]*workYaw.v[431])*workYaw.d_inv[522];
  workYaw.v[520] = workYaw.L[584]*workYaw.d[520];
  workYaw.v[521] = workYaw.L[585]*workYaw.d[521];
  workYaw.v[522] = workYaw.L[586]*workYaw.d[522];
  workYaw.v[523] = 0-workYaw.L[584]*workYaw.v[520]-workYaw.L[585]*workYaw.v[521]-workYaw.L[586]*workYaw.v[522];
  workYaw.d[523] = workYaw.v[523];
  if (workYaw.d[523] > 0)
    workYaw.d[523] = -settingsYaw.kkt_reg;
  else
    workYaw.d[523] -= settingsYaw.kkt_reg;
  workYaw.d_inv[523] = 1/workYaw.d[523];
  workYaw.L[589] = (workYaw.KKT[1039])*workYaw.d_inv[523];
  workYaw.L[596] = (-workYaw.L[594]*workYaw.v[521]-workYaw.L[595]*workYaw.v[522])*workYaw.d_inv[523];
  workYaw.L[601] = (-workYaw.L[600]*workYaw.v[522])*workYaw.d_inv[523];
  workYaw.v[180] = workYaw.L[587]*workYaw.d[180];
  workYaw.v[220] = workYaw.L[588]*workYaw.d[220];
  workYaw.v[523] = workYaw.L[589]*workYaw.d[523];
  workYaw.v[524] = workYaw.KKT[1040]-workYaw.L[587]*workYaw.v[180]-workYaw.L[588]*workYaw.v[220]-workYaw.L[589]*workYaw.v[523];
  workYaw.d[524] = workYaw.v[524];
  if (workYaw.d[524] < 0)
    workYaw.d[524] = settingsYaw.kkt_reg;
  else
    workYaw.d[524] += settingsYaw.kkt_reg;
  workYaw.d_inv[524] = 1/workYaw.d[524];
  workYaw.L[597] = (-workYaw.L[596]*workYaw.v[523])*workYaw.d_inv[524];
  workYaw.L[602] = (workYaw.KKT[1041]-workYaw.L[601]*workYaw.v[523])*workYaw.d_inv[524];
  workYaw.L[604] = (workYaw.KKT[1042])*workYaw.d_inv[524];
  workYaw.v[260] = workYaw.L[590]*workYaw.d[260];
  workYaw.v[300] = workYaw.L[591]*workYaw.d[300];
  workYaw.v[389] = workYaw.L[592]*workYaw.d[389];
  workYaw.v[390] = workYaw.L[593]*workYaw.d[390];
  workYaw.v[521] = workYaw.L[594]*workYaw.d[521];
  workYaw.v[522] = workYaw.L[595]*workYaw.d[522];
  workYaw.v[523] = workYaw.L[596]*workYaw.d[523];
  workYaw.v[524] = workYaw.L[597]*workYaw.d[524];
  workYaw.v[525] = workYaw.KKT[1043]-workYaw.L[590]*workYaw.v[260]-workYaw.L[591]*workYaw.v[300]-workYaw.L[592]*workYaw.v[389]-workYaw.L[593]*workYaw.v[390]-workYaw.L[594]*workYaw.v[521]-workYaw.L[595]*workYaw.v[522]-workYaw.L[596]*workYaw.v[523]-workYaw.L[597]*workYaw.v[524];
  workYaw.d[525] = workYaw.v[525];
  if (workYaw.d[525] < 0)
    workYaw.d[525] = settingsYaw.kkt_reg;
  else
    workYaw.d[525] += settingsYaw.kkt_reg;
  workYaw.d_inv[525] = 1/workYaw.d[525];
  workYaw.L[603] = (-workYaw.L[600]*workYaw.v[522]-workYaw.L[601]*workYaw.v[523]-workYaw.L[602]*workYaw.v[524])*workYaw.d_inv[525];
  workYaw.L[605] = (workYaw.KKT[1044]-workYaw.L[604]*workYaw.v[524])*workYaw.d_inv[525];
  workYaw.L[614] = (-workYaw.L[612]*workYaw.v[390])*workYaw.d_inv[525];
  workYaw.v[431] = workYaw.L[598]*workYaw.d[431];
  workYaw.v[432] = workYaw.L[599]*workYaw.d[432];
  workYaw.v[522] = workYaw.L[600]*workYaw.d[522];
  workYaw.v[523] = workYaw.L[601]*workYaw.d[523];
  workYaw.v[524] = workYaw.L[602]*workYaw.d[524];
  workYaw.v[525] = workYaw.L[603]*workYaw.d[525];
  workYaw.v[526] = 0-workYaw.L[598]*workYaw.v[431]-workYaw.L[599]*workYaw.v[432]-workYaw.L[600]*workYaw.v[522]-workYaw.L[601]*workYaw.v[523]-workYaw.L[602]*workYaw.v[524]-workYaw.L[603]*workYaw.v[525];
  workYaw.d[526] = workYaw.v[526];
  if (workYaw.d[526] > 0)
    workYaw.d[526] = -settingsYaw.kkt_reg;
  else
    workYaw.d[526] -= settingsYaw.kkt_reg;
  workYaw.d_inv[526] = 1/workYaw.d[526];
  workYaw.L[606] = (-workYaw.L[604]*workYaw.v[524]-workYaw.L[605]*workYaw.v[525])*workYaw.d_inv[526];
  workYaw.L[615] = (-workYaw.L[614]*workYaw.v[525])*workYaw.d_inv[526];
  workYaw.L[620] = (-workYaw.L[618]*workYaw.v[432])*workYaw.d_inv[526];
  workYaw.v[524] = workYaw.L[604]*workYaw.d[524];
  workYaw.v[525] = workYaw.L[605]*workYaw.d[525];
  workYaw.v[526] = workYaw.L[606]*workYaw.d[526];
  workYaw.v[527] = 0-workYaw.L[604]*workYaw.v[524]-workYaw.L[605]*workYaw.v[525]-workYaw.L[606]*workYaw.v[526];
  workYaw.d[527] = workYaw.v[527];
  if (workYaw.d[527] > 0)
    workYaw.d[527] = -settingsYaw.kkt_reg;
  else
    workYaw.d[527] -= settingsYaw.kkt_reg;
  workYaw.d_inv[527] = 1/workYaw.d[527];
  workYaw.L[609] = (workYaw.KKT[1045])*workYaw.d_inv[527];
  workYaw.L[616] = (-workYaw.L[614]*workYaw.v[525]-workYaw.L[615]*workYaw.v[526])*workYaw.d_inv[527];
  workYaw.L[621] = (-workYaw.L[620]*workYaw.v[526])*workYaw.d_inv[527];
  workYaw.v[181] = workYaw.L[607]*workYaw.d[181];
  workYaw.v[221] = workYaw.L[608]*workYaw.d[221];
  workYaw.v[527] = workYaw.L[609]*workYaw.d[527];
  workYaw.v[528] = workYaw.KKT[1046]-workYaw.L[607]*workYaw.v[181]-workYaw.L[608]*workYaw.v[221]-workYaw.L[609]*workYaw.v[527];
  workYaw.d[528] = workYaw.v[528];
  if (workYaw.d[528] < 0)
    workYaw.d[528] = settingsYaw.kkt_reg;
  else
    workYaw.d[528] += settingsYaw.kkt_reg;
  workYaw.d_inv[528] = 1/workYaw.d[528];
  workYaw.L[617] = (-workYaw.L[616]*workYaw.v[527])*workYaw.d_inv[528];
  workYaw.L[622] = (workYaw.KKT[1047]-workYaw.L[621]*workYaw.v[527])*workYaw.d_inv[528];
  workYaw.L[624] = (workYaw.KKT[1048])*workYaw.d_inv[528];
  workYaw.v[261] = workYaw.L[610]*workYaw.d[261];
  workYaw.v[301] = workYaw.L[611]*workYaw.d[301];
  workYaw.v[390] = workYaw.L[612]*workYaw.d[390];
  workYaw.v[391] = workYaw.L[613]*workYaw.d[391];
  workYaw.v[525] = workYaw.L[614]*workYaw.d[525];
  workYaw.v[526] = workYaw.L[615]*workYaw.d[526];
  workYaw.v[527] = workYaw.L[616]*workYaw.d[527];
  workYaw.v[528] = workYaw.L[617]*workYaw.d[528];
  workYaw.v[529] = workYaw.KKT[1049]-workYaw.L[610]*workYaw.v[261]-workYaw.L[611]*workYaw.v[301]-workYaw.L[612]*workYaw.v[390]-workYaw.L[613]*workYaw.v[391]-workYaw.L[614]*workYaw.v[525]-workYaw.L[615]*workYaw.v[526]-workYaw.L[616]*workYaw.v[527]-workYaw.L[617]*workYaw.v[528];
  workYaw.d[529] = workYaw.v[529];
  if (workYaw.d[529] < 0)
    workYaw.d[529] = settingsYaw.kkt_reg;
  else
    workYaw.d[529] += settingsYaw.kkt_reg;
  workYaw.d_inv[529] = 1/workYaw.d[529];
  workYaw.L[623] = (-workYaw.L[620]*workYaw.v[526]-workYaw.L[621]*workYaw.v[527]-workYaw.L[622]*workYaw.v[528])*workYaw.d_inv[529];
  workYaw.L[625] = (workYaw.KKT[1050]-workYaw.L[624]*workYaw.v[528])*workYaw.d_inv[529];
  workYaw.L[634] = (-workYaw.L[632]*workYaw.v[391])*workYaw.d_inv[529];
  workYaw.v[432] = workYaw.L[618]*workYaw.d[432];
  workYaw.v[433] = workYaw.L[619]*workYaw.d[433];
  workYaw.v[526] = workYaw.L[620]*workYaw.d[526];
  workYaw.v[527] = workYaw.L[621]*workYaw.d[527];
  workYaw.v[528] = workYaw.L[622]*workYaw.d[528];
  workYaw.v[529] = workYaw.L[623]*workYaw.d[529];
  workYaw.v[530] = 0-workYaw.L[618]*workYaw.v[432]-workYaw.L[619]*workYaw.v[433]-workYaw.L[620]*workYaw.v[526]-workYaw.L[621]*workYaw.v[527]-workYaw.L[622]*workYaw.v[528]-workYaw.L[623]*workYaw.v[529];
  workYaw.d[530] = workYaw.v[530];
  if (workYaw.d[530] > 0)
    workYaw.d[530] = -settingsYaw.kkt_reg;
  else
    workYaw.d[530] -= settingsYaw.kkt_reg;
  workYaw.d_inv[530] = 1/workYaw.d[530];
  workYaw.L[626] = (-workYaw.L[624]*workYaw.v[528]-workYaw.L[625]*workYaw.v[529])*workYaw.d_inv[530];
  workYaw.L[635] = (-workYaw.L[634]*workYaw.v[529])*workYaw.d_inv[530];
  workYaw.L[640] = (-workYaw.L[638]*workYaw.v[433])*workYaw.d_inv[530];
  workYaw.v[528] = workYaw.L[624]*workYaw.d[528];
  workYaw.v[529] = workYaw.L[625]*workYaw.d[529];
  workYaw.v[530] = workYaw.L[626]*workYaw.d[530];
  workYaw.v[531] = 0-workYaw.L[624]*workYaw.v[528]-workYaw.L[625]*workYaw.v[529]-workYaw.L[626]*workYaw.v[530];
  workYaw.d[531] = workYaw.v[531];
  if (workYaw.d[531] > 0)
    workYaw.d[531] = -settingsYaw.kkt_reg;
  else
    workYaw.d[531] -= settingsYaw.kkt_reg;
  workYaw.d_inv[531] = 1/workYaw.d[531];
  workYaw.L[629] = (workYaw.KKT[1051])*workYaw.d_inv[531];
  workYaw.L[636] = (-workYaw.L[634]*workYaw.v[529]-workYaw.L[635]*workYaw.v[530])*workYaw.d_inv[531];
  workYaw.L[641] = (-workYaw.L[640]*workYaw.v[530])*workYaw.d_inv[531];
  workYaw.v[182] = workYaw.L[627]*workYaw.d[182];
  workYaw.v[222] = workYaw.L[628]*workYaw.d[222];
  workYaw.v[531] = workYaw.L[629]*workYaw.d[531];
  workYaw.v[532] = workYaw.KKT[1052]-workYaw.L[627]*workYaw.v[182]-workYaw.L[628]*workYaw.v[222]-workYaw.L[629]*workYaw.v[531];
  workYaw.d[532] = workYaw.v[532];
  if (workYaw.d[532] < 0)
    workYaw.d[532] = settingsYaw.kkt_reg;
  else
    workYaw.d[532] += settingsYaw.kkt_reg;
  workYaw.d_inv[532] = 1/workYaw.d[532];
  workYaw.L[637] = (-workYaw.L[636]*workYaw.v[531])*workYaw.d_inv[532];
  workYaw.L[642] = (workYaw.KKT[1053]-workYaw.L[641]*workYaw.v[531])*workYaw.d_inv[532];
  workYaw.L[644] = (workYaw.KKT[1054])*workYaw.d_inv[532];
  workYaw.v[262] = workYaw.L[630]*workYaw.d[262];
  workYaw.v[302] = workYaw.L[631]*workYaw.d[302];
  workYaw.v[391] = workYaw.L[632]*workYaw.d[391];
  workYaw.v[392] = workYaw.L[633]*workYaw.d[392];
  workYaw.v[529] = workYaw.L[634]*workYaw.d[529];
  workYaw.v[530] = workYaw.L[635]*workYaw.d[530];
  workYaw.v[531] = workYaw.L[636]*workYaw.d[531];
  workYaw.v[532] = workYaw.L[637]*workYaw.d[532];
  workYaw.v[533] = workYaw.KKT[1055]-workYaw.L[630]*workYaw.v[262]-workYaw.L[631]*workYaw.v[302]-workYaw.L[632]*workYaw.v[391]-workYaw.L[633]*workYaw.v[392]-workYaw.L[634]*workYaw.v[529]-workYaw.L[635]*workYaw.v[530]-workYaw.L[636]*workYaw.v[531]-workYaw.L[637]*workYaw.v[532];
  workYaw.d[533] = workYaw.v[533];
  if (workYaw.d[533] < 0)
    workYaw.d[533] = settingsYaw.kkt_reg;
  else
    workYaw.d[533] += settingsYaw.kkt_reg;
  workYaw.d_inv[533] = 1/workYaw.d[533];
  workYaw.L[643] = (-workYaw.L[640]*workYaw.v[530]-workYaw.L[641]*workYaw.v[531]-workYaw.L[642]*workYaw.v[532])*workYaw.d_inv[533];
  workYaw.L[645] = (workYaw.KKT[1056]-workYaw.L[644]*workYaw.v[532])*workYaw.d_inv[533];
  workYaw.L[654] = (-workYaw.L[652]*workYaw.v[392])*workYaw.d_inv[533];
  workYaw.v[433] = workYaw.L[638]*workYaw.d[433];
  workYaw.v[434] = workYaw.L[639]*workYaw.d[434];
  workYaw.v[530] = workYaw.L[640]*workYaw.d[530];
  workYaw.v[531] = workYaw.L[641]*workYaw.d[531];
  workYaw.v[532] = workYaw.L[642]*workYaw.d[532];
  workYaw.v[533] = workYaw.L[643]*workYaw.d[533];
  workYaw.v[534] = 0-workYaw.L[638]*workYaw.v[433]-workYaw.L[639]*workYaw.v[434]-workYaw.L[640]*workYaw.v[530]-workYaw.L[641]*workYaw.v[531]-workYaw.L[642]*workYaw.v[532]-workYaw.L[643]*workYaw.v[533];
  workYaw.d[534] = workYaw.v[534];
  if (workYaw.d[534] > 0)
    workYaw.d[534] = -settingsYaw.kkt_reg;
  else
    workYaw.d[534] -= settingsYaw.kkt_reg;
  workYaw.d_inv[534] = 1/workYaw.d[534];
  workYaw.L[646] = (-workYaw.L[644]*workYaw.v[532]-workYaw.L[645]*workYaw.v[533])*workYaw.d_inv[534];
  workYaw.L[655] = (-workYaw.L[654]*workYaw.v[533])*workYaw.d_inv[534];
  workYaw.L[660] = (-workYaw.L[658]*workYaw.v[434])*workYaw.d_inv[534];
  workYaw.v[532] = workYaw.L[644]*workYaw.d[532];
  workYaw.v[533] = workYaw.L[645]*workYaw.d[533];
  workYaw.v[534] = workYaw.L[646]*workYaw.d[534];
  workYaw.v[535] = 0-workYaw.L[644]*workYaw.v[532]-workYaw.L[645]*workYaw.v[533]-workYaw.L[646]*workYaw.v[534];
  workYaw.d[535] = workYaw.v[535];
  if (workYaw.d[535] > 0)
    workYaw.d[535] = -settingsYaw.kkt_reg;
  else
    workYaw.d[535] -= settingsYaw.kkt_reg;
  workYaw.d_inv[535] = 1/workYaw.d[535];
  workYaw.L[649] = (workYaw.KKT[1057])*workYaw.d_inv[535];
  workYaw.L[656] = (-workYaw.L[654]*workYaw.v[533]-workYaw.L[655]*workYaw.v[534])*workYaw.d_inv[535];
  workYaw.L[661] = (-workYaw.L[660]*workYaw.v[534])*workYaw.d_inv[535];
  workYaw.v[183] = workYaw.L[647]*workYaw.d[183];
  workYaw.v[223] = workYaw.L[648]*workYaw.d[223];
  workYaw.v[535] = workYaw.L[649]*workYaw.d[535];
  workYaw.v[536] = workYaw.KKT[1058]-workYaw.L[647]*workYaw.v[183]-workYaw.L[648]*workYaw.v[223]-workYaw.L[649]*workYaw.v[535];
  workYaw.d[536] = workYaw.v[536];
  if (workYaw.d[536] < 0)
    workYaw.d[536] = settingsYaw.kkt_reg;
  else
    workYaw.d[536] += settingsYaw.kkt_reg;
  workYaw.d_inv[536] = 1/workYaw.d[536];
  workYaw.L[657] = (-workYaw.L[656]*workYaw.v[535])*workYaw.d_inv[536];
  workYaw.L[662] = (workYaw.KKT[1059]-workYaw.L[661]*workYaw.v[535])*workYaw.d_inv[536];
  workYaw.L[664] = (workYaw.KKT[1060])*workYaw.d_inv[536];
  workYaw.v[263] = workYaw.L[650]*workYaw.d[263];
  workYaw.v[303] = workYaw.L[651]*workYaw.d[303];
  workYaw.v[392] = workYaw.L[652]*workYaw.d[392];
  workYaw.v[393] = workYaw.L[653]*workYaw.d[393];
  workYaw.v[533] = workYaw.L[654]*workYaw.d[533];
  workYaw.v[534] = workYaw.L[655]*workYaw.d[534];
  workYaw.v[535] = workYaw.L[656]*workYaw.d[535];
  workYaw.v[536] = workYaw.L[657]*workYaw.d[536];
  workYaw.v[537] = workYaw.KKT[1061]-workYaw.L[650]*workYaw.v[263]-workYaw.L[651]*workYaw.v[303]-workYaw.L[652]*workYaw.v[392]-workYaw.L[653]*workYaw.v[393]-workYaw.L[654]*workYaw.v[533]-workYaw.L[655]*workYaw.v[534]-workYaw.L[656]*workYaw.v[535]-workYaw.L[657]*workYaw.v[536];
  workYaw.d[537] = workYaw.v[537];
  if (workYaw.d[537] < 0)
    workYaw.d[537] = settingsYaw.kkt_reg;
  else
    workYaw.d[537] += settingsYaw.kkt_reg;
  workYaw.d_inv[537] = 1/workYaw.d[537];
  workYaw.L[663] = (-workYaw.L[660]*workYaw.v[534]-workYaw.L[661]*workYaw.v[535]-workYaw.L[662]*workYaw.v[536])*workYaw.d_inv[537];
  workYaw.L[665] = (workYaw.KKT[1062]-workYaw.L[664]*workYaw.v[536])*workYaw.d_inv[537];
  workYaw.L[674] = (-workYaw.L[672]*workYaw.v[393])*workYaw.d_inv[537];
  workYaw.v[434] = workYaw.L[658]*workYaw.d[434];
  workYaw.v[435] = workYaw.L[659]*workYaw.d[435];
  workYaw.v[534] = workYaw.L[660]*workYaw.d[534];
  workYaw.v[535] = workYaw.L[661]*workYaw.d[535];
  workYaw.v[536] = workYaw.L[662]*workYaw.d[536];
  workYaw.v[537] = workYaw.L[663]*workYaw.d[537];
  workYaw.v[538] = 0-workYaw.L[658]*workYaw.v[434]-workYaw.L[659]*workYaw.v[435]-workYaw.L[660]*workYaw.v[534]-workYaw.L[661]*workYaw.v[535]-workYaw.L[662]*workYaw.v[536]-workYaw.L[663]*workYaw.v[537];
  workYaw.d[538] = workYaw.v[538];
  if (workYaw.d[538] > 0)
    workYaw.d[538] = -settingsYaw.kkt_reg;
  else
    workYaw.d[538] -= settingsYaw.kkt_reg;
  workYaw.d_inv[538] = 1/workYaw.d[538];
  workYaw.L[666] = (-workYaw.L[664]*workYaw.v[536]-workYaw.L[665]*workYaw.v[537])*workYaw.d_inv[538];
  workYaw.L[675] = (-workYaw.L[674]*workYaw.v[537])*workYaw.d_inv[538];
  workYaw.L[680] = (-workYaw.L[678]*workYaw.v[435])*workYaw.d_inv[538];
  workYaw.v[536] = workYaw.L[664]*workYaw.d[536];
  workYaw.v[537] = workYaw.L[665]*workYaw.d[537];
  workYaw.v[538] = workYaw.L[666]*workYaw.d[538];
  workYaw.v[539] = 0-workYaw.L[664]*workYaw.v[536]-workYaw.L[665]*workYaw.v[537]-workYaw.L[666]*workYaw.v[538];
  workYaw.d[539] = workYaw.v[539];
  if (workYaw.d[539] > 0)
    workYaw.d[539] = -settingsYaw.kkt_reg;
  else
    workYaw.d[539] -= settingsYaw.kkt_reg;
  workYaw.d_inv[539] = 1/workYaw.d[539];
  workYaw.L[669] = (workYaw.KKT[1063])*workYaw.d_inv[539];
  workYaw.L[676] = (-workYaw.L[674]*workYaw.v[537]-workYaw.L[675]*workYaw.v[538])*workYaw.d_inv[539];
  workYaw.L[681] = (-workYaw.L[680]*workYaw.v[538])*workYaw.d_inv[539];
  workYaw.v[184] = workYaw.L[667]*workYaw.d[184];
  workYaw.v[224] = workYaw.L[668]*workYaw.d[224];
  workYaw.v[539] = workYaw.L[669]*workYaw.d[539];
  workYaw.v[540] = workYaw.KKT[1064]-workYaw.L[667]*workYaw.v[184]-workYaw.L[668]*workYaw.v[224]-workYaw.L[669]*workYaw.v[539];
  workYaw.d[540] = workYaw.v[540];
  if (workYaw.d[540] < 0)
    workYaw.d[540] = settingsYaw.kkt_reg;
  else
    workYaw.d[540] += settingsYaw.kkt_reg;
  workYaw.d_inv[540] = 1/workYaw.d[540];
  workYaw.L[677] = (-workYaw.L[676]*workYaw.v[539])*workYaw.d_inv[540];
  workYaw.L[682] = (workYaw.KKT[1065]-workYaw.L[681]*workYaw.v[539])*workYaw.d_inv[540];
  workYaw.L[684] = (workYaw.KKT[1066])*workYaw.d_inv[540];
  workYaw.v[264] = workYaw.L[670]*workYaw.d[264];
  workYaw.v[304] = workYaw.L[671]*workYaw.d[304];
  workYaw.v[393] = workYaw.L[672]*workYaw.d[393];
  workYaw.v[394] = workYaw.L[673]*workYaw.d[394];
  workYaw.v[537] = workYaw.L[674]*workYaw.d[537];
  workYaw.v[538] = workYaw.L[675]*workYaw.d[538];
  workYaw.v[539] = workYaw.L[676]*workYaw.d[539];
  workYaw.v[540] = workYaw.L[677]*workYaw.d[540];
  workYaw.v[541] = workYaw.KKT[1067]-workYaw.L[670]*workYaw.v[264]-workYaw.L[671]*workYaw.v[304]-workYaw.L[672]*workYaw.v[393]-workYaw.L[673]*workYaw.v[394]-workYaw.L[674]*workYaw.v[537]-workYaw.L[675]*workYaw.v[538]-workYaw.L[676]*workYaw.v[539]-workYaw.L[677]*workYaw.v[540];
  workYaw.d[541] = workYaw.v[541];
  if (workYaw.d[541] < 0)
    workYaw.d[541] = settingsYaw.kkt_reg;
  else
    workYaw.d[541] += settingsYaw.kkt_reg;
  workYaw.d_inv[541] = 1/workYaw.d[541];
  workYaw.L[683] = (-workYaw.L[680]*workYaw.v[538]-workYaw.L[681]*workYaw.v[539]-workYaw.L[682]*workYaw.v[540])*workYaw.d_inv[541];
  workYaw.L[685] = (workYaw.KKT[1068]-workYaw.L[684]*workYaw.v[540])*workYaw.d_inv[541];
  workYaw.L[694] = (-workYaw.L[692]*workYaw.v[394])*workYaw.d_inv[541];
  workYaw.v[435] = workYaw.L[678]*workYaw.d[435];
  workYaw.v[436] = workYaw.L[679]*workYaw.d[436];
  workYaw.v[538] = workYaw.L[680]*workYaw.d[538];
  workYaw.v[539] = workYaw.L[681]*workYaw.d[539];
  workYaw.v[540] = workYaw.L[682]*workYaw.d[540];
  workYaw.v[541] = workYaw.L[683]*workYaw.d[541];
  workYaw.v[542] = 0-workYaw.L[678]*workYaw.v[435]-workYaw.L[679]*workYaw.v[436]-workYaw.L[680]*workYaw.v[538]-workYaw.L[681]*workYaw.v[539]-workYaw.L[682]*workYaw.v[540]-workYaw.L[683]*workYaw.v[541];
  workYaw.d[542] = workYaw.v[542];
  if (workYaw.d[542] > 0)
    workYaw.d[542] = -settingsYaw.kkt_reg;
  else
    workYaw.d[542] -= settingsYaw.kkt_reg;
  workYaw.d_inv[542] = 1/workYaw.d[542];
  workYaw.L[686] = (-workYaw.L[684]*workYaw.v[540]-workYaw.L[685]*workYaw.v[541])*workYaw.d_inv[542];
  workYaw.L[695] = (-workYaw.L[694]*workYaw.v[541])*workYaw.d_inv[542];
  workYaw.L[700] = (-workYaw.L[698]*workYaw.v[436])*workYaw.d_inv[542];
  workYaw.v[540] = workYaw.L[684]*workYaw.d[540];
  workYaw.v[541] = workYaw.L[685]*workYaw.d[541];
  workYaw.v[542] = workYaw.L[686]*workYaw.d[542];
  workYaw.v[543] = 0-workYaw.L[684]*workYaw.v[540]-workYaw.L[685]*workYaw.v[541]-workYaw.L[686]*workYaw.v[542];
  workYaw.d[543] = workYaw.v[543];
  if (workYaw.d[543] > 0)
    workYaw.d[543] = -settingsYaw.kkt_reg;
  else
    workYaw.d[543] -= settingsYaw.kkt_reg;
  workYaw.d_inv[543] = 1/workYaw.d[543];
  workYaw.L[689] = (workYaw.KKT[1069])*workYaw.d_inv[543];
  workYaw.L[696] = (-workYaw.L[694]*workYaw.v[541]-workYaw.L[695]*workYaw.v[542])*workYaw.d_inv[543];
  workYaw.L[701] = (-workYaw.L[700]*workYaw.v[542])*workYaw.d_inv[543];
  workYaw.v[185] = workYaw.L[687]*workYaw.d[185];
  workYaw.v[225] = workYaw.L[688]*workYaw.d[225];
  workYaw.v[543] = workYaw.L[689]*workYaw.d[543];
  workYaw.v[544] = workYaw.KKT[1070]-workYaw.L[687]*workYaw.v[185]-workYaw.L[688]*workYaw.v[225]-workYaw.L[689]*workYaw.v[543];
  workYaw.d[544] = workYaw.v[544];
  if (workYaw.d[544] < 0)
    workYaw.d[544] = settingsYaw.kkt_reg;
  else
    workYaw.d[544] += settingsYaw.kkt_reg;
  workYaw.d_inv[544] = 1/workYaw.d[544];
  workYaw.L[697] = (-workYaw.L[696]*workYaw.v[543])*workYaw.d_inv[544];
  workYaw.L[702] = (workYaw.KKT[1071]-workYaw.L[701]*workYaw.v[543])*workYaw.d_inv[544];
  workYaw.L[704] = (workYaw.KKT[1072])*workYaw.d_inv[544];
  workYaw.v[265] = workYaw.L[690]*workYaw.d[265];
  workYaw.v[305] = workYaw.L[691]*workYaw.d[305];
  workYaw.v[394] = workYaw.L[692]*workYaw.d[394];
  workYaw.v[395] = workYaw.L[693]*workYaw.d[395];
  workYaw.v[541] = workYaw.L[694]*workYaw.d[541];
  workYaw.v[542] = workYaw.L[695]*workYaw.d[542];
  workYaw.v[543] = workYaw.L[696]*workYaw.d[543];
  workYaw.v[544] = workYaw.L[697]*workYaw.d[544];
  workYaw.v[545] = workYaw.KKT[1073]-workYaw.L[690]*workYaw.v[265]-workYaw.L[691]*workYaw.v[305]-workYaw.L[692]*workYaw.v[394]-workYaw.L[693]*workYaw.v[395]-workYaw.L[694]*workYaw.v[541]-workYaw.L[695]*workYaw.v[542]-workYaw.L[696]*workYaw.v[543]-workYaw.L[697]*workYaw.v[544];
  workYaw.d[545] = workYaw.v[545];
  if (workYaw.d[545] < 0)
    workYaw.d[545] = settingsYaw.kkt_reg;
  else
    workYaw.d[545] += settingsYaw.kkt_reg;
  workYaw.d_inv[545] = 1/workYaw.d[545];
  workYaw.L[703] = (-workYaw.L[700]*workYaw.v[542]-workYaw.L[701]*workYaw.v[543]-workYaw.L[702]*workYaw.v[544])*workYaw.d_inv[545];
  workYaw.L[705] = (workYaw.KKT[1074]-workYaw.L[704]*workYaw.v[544])*workYaw.d_inv[545];
  workYaw.L[714] = (-workYaw.L[712]*workYaw.v[395])*workYaw.d_inv[545];
  workYaw.v[436] = workYaw.L[698]*workYaw.d[436];
  workYaw.v[437] = workYaw.L[699]*workYaw.d[437];
  workYaw.v[542] = workYaw.L[700]*workYaw.d[542];
  workYaw.v[543] = workYaw.L[701]*workYaw.d[543];
  workYaw.v[544] = workYaw.L[702]*workYaw.d[544];
  workYaw.v[545] = workYaw.L[703]*workYaw.d[545];
  workYaw.v[546] = 0-workYaw.L[698]*workYaw.v[436]-workYaw.L[699]*workYaw.v[437]-workYaw.L[700]*workYaw.v[542]-workYaw.L[701]*workYaw.v[543]-workYaw.L[702]*workYaw.v[544]-workYaw.L[703]*workYaw.v[545];
  workYaw.d[546] = workYaw.v[546];
  if (workYaw.d[546] > 0)
    workYaw.d[546] = -settingsYaw.kkt_reg;
  else
    workYaw.d[546] -= settingsYaw.kkt_reg;
  workYaw.d_inv[546] = 1/workYaw.d[546];
  workYaw.L[706] = (-workYaw.L[704]*workYaw.v[544]-workYaw.L[705]*workYaw.v[545])*workYaw.d_inv[546];
  workYaw.L[715] = (-workYaw.L[714]*workYaw.v[545])*workYaw.d_inv[546];
  workYaw.L[720] = (-workYaw.L[718]*workYaw.v[437])*workYaw.d_inv[546];
  workYaw.v[544] = workYaw.L[704]*workYaw.d[544];
  workYaw.v[545] = workYaw.L[705]*workYaw.d[545];
  workYaw.v[546] = workYaw.L[706]*workYaw.d[546];
  workYaw.v[547] = 0-workYaw.L[704]*workYaw.v[544]-workYaw.L[705]*workYaw.v[545]-workYaw.L[706]*workYaw.v[546];
  workYaw.d[547] = workYaw.v[547];
  if (workYaw.d[547] > 0)
    workYaw.d[547] = -settingsYaw.kkt_reg;
  else
    workYaw.d[547] -= settingsYaw.kkt_reg;
  workYaw.d_inv[547] = 1/workYaw.d[547];
  workYaw.L[709] = (workYaw.KKT[1075])*workYaw.d_inv[547];
  workYaw.L[716] = (-workYaw.L[714]*workYaw.v[545]-workYaw.L[715]*workYaw.v[546])*workYaw.d_inv[547];
  workYaw.L[721] = (-workYaw.L[720]*workYaw.v[546])*workYaw.d_inv[547];
  workYaw.v[186] = workYaw.L[707]*workYaw.d[186];
  workYaw.v[226] = workYaw.L[708]*workYaw.d[226];
  workYaw.v[547] = workYaw.L[709]*workYaw.d[547];
  workYaw.v[548] = workYaw.KKT[1076]-workYaw.L[707]*workYaw.v[186]-workYaw.L[708]*workYaw.v[226]-workYaw.L[709]*workYaw.v[547];
  workYaw.d[548] = workYaw.v[548];
  if (workYaw.d[548] < 0)
    workYaw.d[548] = settingsYaw.kkt_reg;
  else
    workYaw.d[548] += settingsYaw.kkt_reg;
  workYaw.d_inv[548] = 1/workYaw.d[548];
  workYaw.L[717] = (-workYaw.L[716]*workYaw.v[547])*workYaw.d_inv[548];
  workYaw.L[722] = (workYaw.KKT[1077]-workYaw.L[721]*workYaw.v[547])*workYaw.d_inv[548];
  workYaw.L[724] = (workYaw.KKT[1078])*workYaw.d_inv[548];
  workYaw.v[266] = workYaw.L[710]*workYaw.d[266];
  workYaw.v[306] = workYaw.L[711]*workYaw.d[306];
  workYaw.v[395] = workYaw.L[712]*workYaw.d[395];
  workYaw.v[396] = workYaw.L[713]*workYaw.d[396];
  workYaw.v[545] = workYaw.L[714]*workYaw.d[545];
  workYaw.v[546] = workYaw.L[715]*workYaw.d[546];
  workYaw.v[547] = workYaw.L[716]*workYaw.d[547];
  workYaw.v[548] = workYaw.L[717]*workYaw.d[548];
  workYaw.v[549] = workYaw.KKT[1079]-workYaw.L[710]*workYaw.v[266]-workYaw.L[711]*workYaw.v[306]-workYaw.L[712]*workYaw.v[395]-workYaw.L[713]*workYaw.v[396]-workYaw.L[714]*workYaw.v[545]-workYaw.L[715]*workYaw.v[546]-workYaw.L[716]*workYaw.v[547]-workYaw.L[717]*workYaw.v[548];
  workYaw.d[549] = workYaw.v[549];
  if (workYaw.d[549] < 0)
    workYaw.d[549] = settingsYaw.kkt_reg;
  else
    workYaw.d[549] += settingsYaw.kkt_reg;
  workYaw.d_inv[549] = 1/workYaw.d[549];
  workYaw.L[723] = (-workYaw.L[720]*workYaw.v[546]-workYaw.L[721]*workYaw.v[547]-workYaw.L[722]*workYaw.v[548])*workYaw.d_inv[549];
  workYaw.L[725] = (workYaw.KKT[1080]-workYaw.L[724]*workYaw.v[548])*workYaw.d_inv[549];
  workYaw.L[734] = (-workYaw.L[732]*workYaw.v[396])*workYaw.d_inv[549];
  workYaw.v[437] = workYaw.L[718]*workYaw.d[437];
  workYaw.v[438] = workYaw.L[719]*workYaw.d[438];
  workYaw.v[546] = workYaw.L[720]*workYaw.d[546];
  workYaw.v[547] = workYaw.L[721]*workYaw.d[547];
  workYaw.v[548] = workYaw.L[722]*workYaw.d[548];
  workYaw.v[549] = workYaw.L[723]*workYaw.d[549];
  workYaw.v[550] = 0-workYaw.L[718]*workYaw.v[437]-workYaw.L[719]*workYaw.v[438]-workYaw.L[720]*workYaw.v[546]-workYaw.L[721]*workYaw.v[547]-workYaw.L[722]*workYaw.v[548]-workYaw.L[723]*workYaw.v[549];
  workYaw.d[550] = workYaw.v[550];
  if (workYaw.d[550] > 0)
    workYaw.d[550] = -settingsYaw.kkt_reg;
  else
    workYaw.d[550] -= settingsYaw.kkt_reg;
  workYaw.d_inv[550] = 1/workYaw.d[550];
  workYaw.L[726] = (-workYaw.L[724]*workYaw.v[548]-workYaw.L[725]*workYaw.v[549])*workYaw.d_inv[550];
  workYaw.L[735] = (-workYaw.L[734]*workYaw.v[549])*workYaw.d_inv[550];
  workYaw.L[740] = (-workYaw.L[738]*workYaw.v[438])*workYaw.d_inv[550];
  workYaw.v[548] = workYaw.L[724]*workYaw.d[548];
  workYaw.v[549] = workYaw.L[725]*workYaw.d[549];
  workYaw.v[550] = workYaw.L[726]*workYaw.d[550];
  workYaw.v[551] = 0-workYaw.L[724]*workYaw.v[548]-workYaw.L[725]*workYaw.v[549]-workYaw.L[726]*workYaw.v[550];
  workYaw.d[551] = workYaw.v[551];
  if (workYaw.d[551] > 0)
    workYaw.d[551] = -settingsYaw.kkt_reg;
  else
    workYaw.d[551] -= settingsYaw.kkt_reg;
  workYaw.d_inv[551] = 1/workYaw.d[551];
  workYaw.L[729] = (workYaw.KKT[1081])*workYaw.d_inv[551];
  workYaw.L[736] = (-workYaw.L[734]*workYaw.v[549]-workYaw.L[735]*workYaw.v[550])*workYaw.d_inv[551];
  workYaw.L[741] = (-workYaw.L[740]*workYaw.v[550])*workYaw.d_inv[551];
  workYaw.v[187] = workYaw.L[727]*workYaw.d[187];
  workYaw.v[227] = workYaw.L[728]*workYaw.d[227];
  workYaw.v[551] = workYaw.L[729]*workYaw.d[551];
  workYaw.v[552] = workYaw.KKT[1082]-workYaw.L[727]*workYaw.v[187]-workYaw.L[728]*workYaw.v[227]-workYaw.L[729]*workYaw.v[551];
  workYaw.d[552] = workYaw.v[552];
  if (workYaw.d[552] < 0)
    workYaw.d[552] = settingsYaw.kkt_reg;
  else
    workYaw.d[552] += settingsYaw.kkt_reg;
  workYaw.d_inv[552] = 1/workYaw.d[552];
  workYaw.L[737] = (-workYaw.L[736]*workYaw.v[551])*workYaw.d_inv[552];
  workYaw.L[742] = (workYaw.KKT[1083]-workYaw.L[741]*workYaw.v[551])*workYaw.d_inv[552];
  workYaw.L[744] = (workYaw.KKT[1084])*workYaw.d_inv[552];
  workYaw.v[267] = workYaw.L[730]*workYaw.d[267];
  workYaw.v[307] = workYaw.L[731]*workYaw.d[307];
  workYaw.v[396] = workYaw.L[732]*workYaw.d[396];
  workYaw.v[397] = workYaw.L[733]*workYaw.d[397];
  workYaw.v[549] = workYaw.L[734]*workYaw.d[549];
  workYaw.v[550] = workYaw.L[735]*workYaw.d[550];
  workYaw.v[551] = workYaw.L[736]*workYaw.d[551];
  workYaw.v[552] = workYaw.L[737]*workYaw.d[552];
  workYaw.v[553] = workYaw.KKT[1085]-workYaw.L[730]*workYaw.v[267]-workYaw.L[731]*workYaw.v[307]-workYaw.L[732]*workYaw.v[396]-workYaw.L[733]*workYaw.v[397]-workYaw.L[734]*workYaw.v[549]-workYaw.L[735]*workYaw.v[550]-workYaw.L[736]*workYaw.v[551]-workYaw.L[737]*workYaw.v[552];
  workYaw.d[553] = workYaw.v[553];
  if (workYaw.d[553] < 0)
    workYaw.d[553] = settingsYaw.kkt_reg;
  else
    workYaw.d[553] += settingsYaw.kkt_reg;
  workYaw.d_inv[553] = 1/workYaw.d[553];
  workYaw.L[743] = (-workYaw.L[740]*workYaw.v[550]-workYaw.L[741]*workYaw.v[551]-workYaw.L[742]*workYaw.v[552])*workYaw.d_inv[553];
  workYaw.L[745] = (workYaw.KKT[1086]-workYaw.L[744]*workYaw.v[552])*workYaw.d_inv[553];
  workYaw.L[754] = (-workYaw.L[752]*workYaw.v[397])*workYaw.d_inv[553];
  workYaw.v[438] = workYaw.L[738]*workYaw.d[438];
  workYaw.v[439] = workYaw.L[739]*workYaw.d[439];
  workYaw.v[550] = workYaw.L[740]*workYaw.d[550];
  workYaw.v[551] = workYaw.L[741]*workYaw.d[551];
  workYaw.v[552] = workYaw.L[742]*workYaw.d[552];
  workYaw.v[553] = workYaw.L[743]*workYaw.d[553];
  workYaw.v[554] = 0-workYaw.L[738]*workYaw.v[438]-workYaw.L[739]*workYaw.v[439]-workYaw.L[740]*workYaw.v[550]-workYaw.L[741]*workYaw.v[551]-workYaw.L[742]*workYaw.v[552]-workYaw.L[743]*workYaw.v[553];
  workYaw.d[554] = workYaw.v[554];
  if (workYaw.d[554] > 0)
    workYaw.d[554] = -settingsYaw.kkt_reg;
  else
    workYaw.d[554] -= settingsYaw.kkt_reg;
  workYaw.d_inv[554] = 1/workYaw.d[554];
  workYaw.L[746] = (-workYaw.L[744]*workYaw.v[552]-workYaw.L[745]*workYaw.v[553])*workYaw.d_inv[554];
  workYaw.L[755] = (-workYaw.L[754]*workYaw.v[553])*workYaw.d_inv[554];
  workYaw.L[760] = (-workYaw.L[758]*workYaw.v[439])*workYaw.d_inv[554];
  workYaw.v[552] = workYaw.L[744]*workYaw.d[552];
  workYaw.v[553] = workYaw.L[745]*workYaw.d[553];
  workYaw.v[554] = workYaw.L[746]*workYaw.d[554];
  workYaw.v[555] = 0-workYaw.L[744]*workYaw.v[552]-workYaw.L[745]*workYaw.v[553]-workYaw.L[746]*workYaw.v[554];
  workYaw.d[555] = workYaw.v[555];
  if (workYaw.d[555] > 0)
    workYaw.d[555] = -settingsYaw.kkt_reg;
  else
    workYaw.d[555] -= settingsYaw.kkt_reg;
  workYaw.d_inv[555] = 1/workYaw.d[555];
  workYaw.L[749] = (workYaw.KKT[1087])*workYaw.d_inv[555];
  workYaw.L[756] = (-workYaw.L[754]*workYaw.v[553]-workYaw.L[755]*workYaw.v[554])*workYaw.d_inv[555];
  workYaw.L[761] = (-workYaw.L[760]*workYaw.v[554])*workYaw.d_inv[555];
  workYaw.v[188] = workYaw.L[747]*workYaw.d[188];
  workYaw.v[228] = workYaw.L[748]*workYaw.d[228];
  workYaw.v[555] = workYaw.L[749]*workYaw.d[555];
  workYaw.v[556] = workYaw.KKT[1088]-workYaw.L[747]*workYaw.v[188]-workYaw.L[748]*workYaw.v[228]-workYaw.L[749]*workYaw.v[555];
  workYaw.d[556] = workYaw.v[556];
  if (workYaw.d[556] < 0)
    workYaw.d[556] = settingsYaw.kkt_reg;
  else
    workYaw.d[556] += settingsYaw.kkt_reg;
  workYaw.d_inv[556] = 1/workYaw.d[556];
  workYaw.L[757] = (-workYaw.L[756]*workYaw.v[555])*workYaw.d_inv[556];
  workYaw.L[762] = (workYaw.KKT[1089]-workYaw.L[761]*workYaw.v[555])*workYaw.d_inv[556];
  workYaw.L[764] = (workYaw.KKT[1090])*workYaw.d_inv[556];
  workYaw.v[268] = workYaw.L[750]*workYaw.d[268];
  workYaw.v[308] = workYaw.L[751]*workYaw.d[308];
  workYaw.v[397] = workYaw.L[752]*workYaw.d[397];
  workYaw.v[398] = workYaw.L[753]*workYaw.d[398];
  workYaw.v[553] = workYaw.L[754]*workYaw.d[553];
  workYaw.v[554] = workYaw.L[755]*workYaw.d[554];
  workYaw.v[555] = workYaw.L[756]*workYaw.d[555];
  workYaw.v[556] = workYaw.L[757]*workYaw.d[556];
  workYaw.v[557] = workYaw.KKT[1091]-workYaw.L[750]*workYaw.v[268]-workYaw.L[751]*workYaw.v[308]-workYaw.L[752]*workYaw.v[397]-workYaw.L[753]*workYaw.v[398]-workYaw.L[754]*workYaw.v[553]-workYaw.L[755]*workYaw.v[554]-workYaw.L[756]*workYaw.v[555]-workYaw.L[757]*workYaw.v[556];
  workYaw.d[557] = workYaw.v[557];
  if (workYaw.d[557] < 0)
    workYaw.d[557] = settingsYaw.kkt_reg;
  else
    workYaw.d[557] += settingsYaw.kkt_reg;
  workYaw.d_inv[557] = 1/workYaw.d[557];
  workYaw.L[763] = (-workYaw.L[760]*workYaw.v[554]-workYaw.L[761]*workYaw.v[555]-workYaw.L[762]*workYaw.v[556])*workYaw.d_inv[557];
  workYaw.L[765] = (workYaw.KKT[1092]-workYaw.L[764]*workYaw.v[556])*workYaw.d_inv[557];
  workYaw.L[774] = (-workYaw.L[772]*workYaw.v[398])*workYaw.d_inv[557];
  workYaw.v[439] = workYaw.L[758]*workYaw.d[439];
  workYaw.v[440] = workYaw.L[759]*workYaw.d[440];
  workYaw.v[554] = workYaw.L[760]*workYaw.d[554];
  workYaw.v[555] = workYaw.L[761]*workYaw.d[555];
  workYaw.v[556] = workYaw.L[762]*workYaw.d[556];
  workYaw.v[557] = workYaw.L[763]*workYaw.d[557];
  workYaw.v[558] = 0-workYaw.L[758]*workYaw.v[439]-workYaw.L[759]*workYaw.v[440]-workYaw.L[760]*workYaw.v[554]-workYaw.L[761]*workYaw.v[555]-workYaw.L[762]*workYaw.v[556]-workYaw.L[763]*workYaw.v[557];
  workYaw.d[558] = workYaw.v[558];
  if (workYaw.d[558] > 0)
    workYaw.d[558] = -settingsYaw.kkt_reg;
  else
    workYaw.d[558] -= settingsYaw.kkt_reg;
  workYaw.d_inv[558] = 1/workYaw.d[558];
  workYaw.L[766] = (-workYaw.L[764]*workYaw.v[556]-workYaw.L[765]*workYaw.v[557])*workYaw.d_inv[558];
  workYaw.L[775] = (-workYaw.L[774]*workYaw.v[557])*workYaw.d_inv[558];
  workYaw.L[780] = (-workYaw.L[778]*workYaw.v[440])*workYaw.d_inv[558];
  workYaw.v[556] = workYaw.L[764]*workYaw.d[556];
  workYaw.v[557] = workYaw.L[765]*workYaw.d[557];
  workYaw.v[558] = workYaw.L[766]*workYaw.d[558];
  workYaw.v[559] = 0-workYaw.L[764]*workYaw.v[556]-workYaw.L[765]*workYaw.v[557]-workYaw.L[766]*workYaw.v[558];
  workYaw.d[559] = workYaw.v[559];
  if (workYaw.d[559] > 0)
    workYaw.d[559] = -settingsYaw.kkt_reg;
  else
    workYaw.d[559] -= settingsYaw.kkt_reg;
  workYaw.d_inv[559] = 1/workYaw.d[559];
  workYaw.L[769] = (workYaw.KKT[1093])*workYaw.d_inv[559];
  workYaw.L[776] = (-workYaw.L[774]*workYaw.v[557]-workYaw.L[775]*workYaw.v[558])*workYaw.d_inv[559];
  workYaw.L[781] = (-workYaw.L[780]*workYaw.v[558])*workYaw.d_inv[559];
  workYaw.v[189] = workYaw.L[767]*workYaw.d[189];
  workYaw.v[229] = workYaw.L[768]*workYaw.d[229];
  workYaw.v[559] = workYaw.L[769]*workYaw.d[559];
  workYaw.v[560] = workYaw.KKT[1094]-workYaw.L[767]*workYaw.v[189]-workYaw.L[768]*workYaw.v[229]-workYaw.L[769]*workYaw.v[559];
  workYaw.d[560] = workYaw.v[560];
  if (workYaw.d[560] < 0)
    workYaw.d[560] = settingsYaw.kkt_reg;
  else
    workYaw.d[560] += settingsYaw.kkt_reg;
  workYaw.d_inv[560] = 1/workYaw.d[560];
  workYaw.L[777] = (-workYaw.L[776]*workYaw.v[559])*workYaw.d_inv[560];
  workYaw.L[782] = (workYaw.KKT[1095]-workYaw.L[781]*workYaw.v[559])*workYaw.d_inv[560];
  workYaw.L[784] = (workYaw.KKT[1096])*workYaw.d_inv[560];
  workYaw.v[269] = workYaw.L[770]*workYaw.d[269];
  workYaw.v[309] = workYaw.L[771]*workYaw.d[309];
  workYaw.v[398] = workYaw.L[772]*workYaw.d[398];
  workYaw.v[399] = workYaw.L[773]*workYaw.d[399];
  workYaw.v[557] = workYaw.L[774]*workYaw.d[557];
  workYaw.v[558] = workYaw.L[775]*workYaw.d[558];
  workYaw.v[559] = workYaw.L[776]*workYaw.d[559];
  workYaw.v[560] = workYaw.L[777]*workYaw.d[560];
  workYaw.v[561] = workYaw.KKT[1097]-workYaw.L[770]*workYaw.v[269]-workYaw.L[771]*workYaw.v[309]-workYaw.L[772]*workYaw.v[398]-workYaw.L[773]*workYaw.v[399]-workYaw.L[774]*workYaw.v[557]-workYaw.L[775]*workYaw.v[558]-workYaw.L[776]*workYaw.v[559]-workYaw.L[777]*workYaw.v[560];
  workYaw.d[561] = workYaw.v[561];
  if (workYaw.d[561] < 0)
    workYaw.d[561] = settingsYaw.kkt_reg;
  else
    workYaw.d[561] += settingsYaw.kkt_reg;
  workYaw.d_inv[561] = 1/workYaw.d[561];
  workYaw.L[783] = (-workYaw.L[780]*workYaw.v[558]-workYaw.L[781]*workYaw.v[559]-workYaw.L[782]*workYaw.v[560])*workYaw.d_inv[561];
  workYaw.L[785] = (workYaw.KKT[1098]-workYaw.L[784]*workYaw.v[560])*workYaw.d_inv[561];
  workYaw.L[794] = (-workYaw.L[792]*workYaw.v[399])*workYaw.d_inv[561];
  workYaw.v[440] = workYaw.L[778]*workYaw.d[440];
  workYaw.v[441] = workYaw.L[779]*workYaw.d[441];
  workYaw.v[558] = workYaw.L[780]*workYaw.d[558];
  workYaw.v[559] = workYaw.L[781]*workYaw.d[559];
  workYaw.v[560] = workYaw.L[782]*workYaw.d[560];
  workYaw.v[561] = workYaw.L[783]*workYaw.d[561];
  workYaw.v[562] = 0-workYaw.L[778]*workYaw.v[440]-workYaw.L[779]*workYaw.v[441]-workYaw.L[780]*workYaw.v[558]-workYaw.L[781]*workYaw.v[559]-workYaw.L[782]*workYaw.v[560]-workYaw.L[783]*workYaw.v[561];
  workYaw.d[562] = workYaw.v[562];
  if (workYaw.d[562] > 0)
    workYaw.d[562] = -settingsYaw.kkt_reg;
  else
    workYaw.d[562] -= settingsYaw.kkt_reg;
  workYaw.d_inv[562] = 1/workYaw.d[562];
  workYaw.L[786] = (-workYaw.L[784]*workYaw.v[560]-workYaw.L[785]*workYaw.v[561])*workYaw.d_inv[562];
  workYaw.L[795] = (-workYaw.L[794]*workYaw.v[561])*workYaw.d_inv[562];
  workYaw.L[800] = (-workYaw.L[798]*workYaw.v[441])*workYaw.d_inv[562];
  workYaw.v[560] = workYaw.L[784]*workYaw.d[560];
  workYaw.v[561] = workYaw.L[785]*workYaw.d[561];
  workYaw.v[562] = workYaw.L[786]*workYaw.d[562];
  workYaw.v[563] = 0-workYaw.L[784]*workYaw.v[560]-workYaw.L[785]*workYaw.v[561]-workYaw.L[786]*workYaw.v[562];
  workYaw.d[563] = workYaw.v[563];
  if (workYaw.d[563] > 0)
    workYaw.d[563] = -settingsYaw.kkt_reg;
  else
    workYaw.d[563] -= settingsYaw.kkt_reg;
  workYaw.d_inv[563] = 1/workYaw.d[563];
  workYaw.L[789] = (workYaw.KKT[1099])*workYaw.d_inv[563];
  workYaw.L[796] = (-workYaw.L[794]*workYaw.v[561]-workYaw.L[795]*workYaw.v[562])*workYaw.d_inv[563];
  workYaw.L[801] = (-workYaw.L[800]*workYaw.v[562])*workYaw.d_inv[563];
  workYaw.v[190] = workYaw.L[787]*workYaw.d[190];
  workYaw.v[230] = workYaw.L[788]*workYaw.d[230];
  workYaw.v[563] = workYaw.L[789]*workYaw.d[563];
  workYaw.v[564] = workYaw.KKT[1100]-workYaw.L[787]*workYaw.v[190]-workYaw.L[788]*workYaw.v[230]-workYaw.L[789]*workYaw.v[563];
  workYaw.d[564] = workYaw.v[564];
  if (workYaw.d[564] < 0)
    workYaw.d[564] = settingsYaw.kkt_reg;
  else
    workYaw.d[564] += settingsYaw.kkt_reg;
  workYaw.d_inv[564] = 1/workYaw.d[564];
  workYaw.L[797] = (-workYaw.L[796]*workYaw.v[563])*workYaw.d_inv[564];
  workYaw.L[802] = (workYaw.KKT[1101]-workYaw.L[801]*workYaw.v[563])*workYaw.d_inv[564];
  workYaw.L[804] = (workYaw.KKT[1102])*workYaw.d_inv[564];
  workYaw.v[270] = workYaw.L[790]*workYaw.d[270];
  workYaw.v[310] = workYaw.L[791]*workYaw.d[310];
  workYaw.v[399] = workYaw.L[792]*workYaw.d[399];
  workYaw.v[400] = workYaw.L[793]*workYaw.d[400];
  workYaw.v[561] = workYaw.L[794]*workYaw.d[561];
  workYaw.v[562] = workYaw.L[795]*workYaw.d[562];
  workYaw.v[563] = workYaw.L[796]*workYaw.d[563];
  workYaw.v[564] = workYaw.L[797]*workYaw.d[564];
  workYaw.v[565] = workYaw.KKT[1103]-workYaw.L[790]*workYaw.v[270]-workYaw.L[791]*workYaw.v[310]-workYaw.L[792]*workYaw.v[399]-workYaw.L[793]*workYaw.v[400]-workYaw.L[794]*workYaw.v[561]-workYaw.L[795]*workYaw.v[562]-workYaw.L[796]*workYaw.v[563]-workYaw.L[797]*workYaw.v[564];
  workYaw.d[565] = workYaw.v[565];
  if (workYaw.d[565] < 0)
    workYaw.d[565] = settingsYaw.kkt_reg;
  else
    workYaw.d[565] += settingsYaw.kkt_reg;
  workYaw.d_inv[565] = 1/workYaw.d[565];
  workYaw.L[803] = (-workYaw.L[800]*workYaw.v[562]-workYaw.L[801]*workYaw.v[563]-workYaw.L[802]*workYaw.v[564])*workYaw.d_inv[565];
  workYaw.L[805] = (workYaw.KKT[1104]-workYaw.L[804]*workYaw.v[564])*workYaw.d_inv[565];
  workYaw.L[814] = (-workYaw.L[812]*workYaw.v[400])*workYaw.d_inv[565];
  workYaw.v[441] = workYaw.L[798]*workYaw.d[441];
  workYaw.v[442] = workYaw.L[799]*workYaw.d[442];
  workYaw.v[562] = workYaw.L[800]*workYaw.d[562];
  workYaw.v[563] = workYaw.L[801]*workYaw.d[563];
  workYaw.v[564] = workYaw.L[802]*workYaw.d[564];
  workYaw.v[565] = workYaw.L[803]*workYaw.d[565];
  workYaw.v[566] = 0-workYaw.L[798]*workYaw.v[441]-workYaw.L[799]*workYaw.v[442]-workYaw.L[800]*workYaw.v[562]-workYaw.L[801]*workYaw.v[563]-workYaw.L[802]*workYaw.v[564]-workYaw.L[803]*workYaw.v[565];
  workYaw.d[566] = workYaw.v[566];
  if (workYaw.d[566] > 0)
    workYaw.d[566] = -settingsYaw.kkt_reg;
  else
    workYaw.d[566] -= settingsYaw.kkt_reg;
  workYaw.d_inv[566] = 1/workYaw.d[566];
  workYaw.L[806] = (-workYaw.L[804]*workYaw.v[564]-workYaw.L[805]*workYaw.v[565])*workYaw.d_inv[566];
  workYaw.L[815] = (-workYaw.L[814]*workYaw.v[565])*workYaw.d_inv[566];
  workYaw.L[820] = (-workYaw.L[818]*workYaw.v[442])*workYaw.d_inv[566];
  workYaw.v[564] = workYaw.L[804]*workYaw.d[564];
  workYaw.v[565] = workYaw.L[805]*workYaw.d[565];
  workYaw.v[566] = workYaw.L[806]*workYaw.d[566];
  workYaw.v[567] = 0-workYaw.L[804]*workYaw.v[564]-workYaw.L[805]*workYaw.v[565]-workYaw.L[806]*workYaw.v[566];
  workYaw.d[567] = workYaw.v[567];
  if (workYaw.d[567] > 0)
    workYaw.d[567] = -settingsYaw.kkt_reg;
  else
    workYaw.d[567] -= settingsYaw.kkt_reg;
  workYaw.d_inv[567] = 1/workYaw.d[567];
  workYaw.L[809] = (workYaw.KKT[1105])*workYaw.d_inv[567];
  workYaw.L[816] = (-workYaw.L[814]*workYaw.v[565]-workYaw.L[815]*workYaw.v[566])*workYaw.d_inv[567];
  workYaw.L[821] = (-workYaw.L[820]*workYaw.v[566])*workYaw.d_inv[567];
  workYaw.v[191] = workYaw.L[807]*workYaw.d[191];
  workYaw.v[231] = workYaw.L[808]*workYaw.d[231];
  workYaw.v[567] = workYaw.L[809]*workYaw.d[567];
  workYaw.v[568] = workYaw.KKT[1106]-workYaw.L[807]*workYaw.v[191]-workYaw.L[808]*workYaw.v[231]-workYaw.L[809]*workYaw.v[567];
  workYaw.d[568] = workYaw.v[568];
  if (workYaw.d[568] < 0)
    workYaw.d[568] = settingsYaw.kkt_reg;
  else
    workYaw.d[568] += settingsYaw.kkt_reg;
  workYaw.d_inv[568] = 1/workYaw.d[568];
  workYaw.L[817] = (-workYaw.L[816]*workYaw.v[567])*workYaw.d_inv[568];
  workYaw.L[822] = (workYaw.KKT[1107]-workYaw.L[821]*workYaw.v[567])*workYaw.d_inv[568];
  workYaw.L[824] = (workYaw.KKT[1108])*workYaw.d_inv[568];
  workYaw.v[271] = workYaw.L[810]*workYaw.d[271];
  workYaw.v[311] = workYaw.L[811]*workYaw.d[311];
  workYaw.v[400] = workYaw.L[812]*workYaw.d[400];
  workYaw.v[401] = workYaw.L[813]*workYaw.d[401];
  workYaw.v[565] = workYaw.L[814]*workYaw.d[565];
  workYaw.v[566] = workYaw.L[815]*workYaw.d[566];
  workYaw.v[567] = workYaw.L[816]*workYaw.d[567];
  workYaw.v[568] = workYaw.L[817]*workYaw.d[568];
  workYaw.v[569] = workYaw.KKT[1109]-workYaw.L[810]*workYaw.v[271]-workYaw.L[811]*workYaw.v[311]-workYaw.L[812]*workYaw.v[400]-workYaw.L[813]*workYaw.v[401]-workYaw.L[814]*workYaw.v[565]-workYaw.L[815]*workYaw.v[566]-workYaw.L[816]*workYaw.v[567]-workYaw.L[817]*workYaw.v[568];
  workYaw.d[569] = workYaw.v[569];
  if (workYaw.d[569] < 0)
    workYaw.d[569] = settingsYaw.kkt_reg;
  else
    workYaw.d[569] += settingsYaw.kkt_reg;
  workYaw.d_inv[569] = 1/workYaw.d[569];
  workYaw.L[823] = (-workYaw.L[820]*workYaw.v[566]-workYaw.L[821]*workYaw.v[567]-workYaw.L[822]*workYaw.v[568])*workYaw.d_inv[569];
  workYaw.L[825] = (workYaw.KKT[1110]-workYaw.L[824]*workYaw.v[568])*workYaw.d_inv[569];
  workYaw.L[834] = (-workYaw.L[832]*workYaw.v[401])*workYaw.d_inv[569];
  workYaw.v[442] = workYaw.L[818]*workYaw.d[442];
  workYaw.v[443] = workYaw.L[819]*workYaw.d[443];
  workYaw.v[566] = workYaw.L[820]*workYaw.d[566];
  workYaw.v[567] = workYaw.L[821]*workYaw.d[567];
  workYaw.v[568] = workYaw.L[822]*workYaw.d[568];
  workYaw.v[569] = workYaw.L[823]*workYaw.d[569];
  workYaw.v[570] = 0-workYaw.L[818]*workYaw.v[442]-workYaw.L[819]*workYaw.v[443]-workYaw.L[820]*workYaw.v[566]-workYaw.L[821]*workYaw.v[567]-workYaw.L[822]*workYaw.v[568]-workYaw.L[823]*workYaw.v[569];
  workYaw.d[570] = workYaw.v[570];
  if (workYaw.d[570] > 0)
    workYaw.d[570] = -settingsYaw.kkt_reg;
  else
    workYaw.d[570] -= settingsYaw.kkt_reg;
  workYaw.d_inv[570] = 1/workYaw.d[570];
  workYaw.L[826] = (-workYaw.L[824]*workYaw.v[568]-workYaw.L[825]*workYaw.v[569])*workYaw.d_inv[570];
  workYaw.L[835] = (-workYaw.L[834]*workYaw.v[569])*workYaw.d_inv[570];
  workYaw.L[840] = (-workYaw.L[838]*workYaw.v[443])*workYaw.d_inv[570];
  workYaw.v[568] = workYaw.L[824]*workYaw.d[568];
  workYaw.v[569] = workYaw.L[825]*workYaw.d[569];
  workYaw.v[570] = workYaw.L[826]*workYaw.d[570];
  workYaw.v[571] = 0-workYaw.L[824]*workYaw.v[568]-workYaw.L[825]*workYaw.v[569]-workYaw.L[826]*workYaw.v[570];
  workYaw.d[571] = workYaw.v[571];
  if (workYaw.d[571] > 0)
    workYaw.d[571] = -settingsYaw.kkt_reg;
  else
    workYaw.d[571] -= settingsYaw.kkt_reg;
  workYaw.d_inv[571] = 1/workYaw.d[571];
  workYaw.L[829] = (workYaw.KKT[1111])*workYaw.d_inv[571];
  workYaw.L[836] = (-workYaw.L[834]*workYaw.v[569]-workYaw.L[835]*workYaw.v[570])*workYaw.d_inv[571];
  workYaw.L[841] = (-workYaw.L[840]*workYaw.v[570])*workYaw.d_inv[571];
  workYaw.v[192] = workYaw.L[827]*workYaw.d[192];
  workYaw.v[232] = workYaw.L[828]*workYaw.d[232];
  workYaw.v[571] = workYaw.L[829]*workYaw.d[571];
  workYaw.v[572] = workYaw.KKT[1112]-workYaw.L[827]*workYaw.v[192]-workYaw.L[828]*workYaw.v[232]-workYaw.L[829]*workYaw.v[571];
  workYaw.d[572] = workYaw.v[572];
  if (workYaw.d[572] < 0)
    workYaw.d[572] = settingsYaw.kkt_reg;
  else
    workYaw.d[572] += settingsYaw.kkt_reg;
  workYaw.d_inv[572] = 1/workYaw.d[572];
  workYaw.L[837] = (-workYaw.L[836]*workYaw.v[571])*workYaw.d_inv[572];
  workYaw.L[842] = (workYaw.KKT[1113]-workYaw.L[841]*workYaw.v[571])*workYaw.d_inv[572];
  workYaw.L[844] = (workYaw.KKT[1114])*workYaw.d_inv[572];
  workYaw.v[272] = workYaw.L[830]*workYaw.d[272];
  workYaw.v[312] = workYaw.L[831]*workYaw.d[312];
  workYaw.v[401] = workYaw.L[832]*workYaw.d[401];
  workYaw.v[402] = workYaw.L[833]*workYaw.d[402];
  workYaw.v[569] = workYaw.L[834]*workYaw.d[569];
  workYaw.v[570] = workYaw.L[835]*workYaw.d[570];
  workYaw.v[571] = workYaw.L[836]*workYaw.d[571];
  workYaw.v[572] = workYaw.L[837]*workYaw.d[572];
  workYaw.v[573] = workYaw.KKT[1115]-workYaw.L[830]*workYaw.v[272]-workYaw.L[831]*workYaw.v[312]-workYaw.L[832]*workYaw.v[401]-workYaw.L[833]*workYaw.v[402]-workYaw.L[834]*workYaw.v[569]-workYaw.L[835]*workYaw.v[570]-workYaw.L[836]*workYaw.v[571]-workYaw.L[837]*workYaw.v[572];
  workYaw.d[573] = workYaw.v[573];
  if (workYaw.d[573] < 0)
    workYaw.d[573] = settingsYaw.kkt_reg;
  else
    workYaw.d[573] += settingsYaw.kkt_reg;
  workYaw.d_inv[573] = 1/workYaw.d[573];
  workYaw.L[843] = (-workYaw.L[840]*workYaw.v[570]-workYaw.L[841]*workYaw.v[571]-workYaw.L[842]*workYaw.v[572])*workYaw.d_inv[573];
  workYaw.L[845] = (workYaw.KKT[1116]-workYaw.L[844]*workYaw.v[572])*workYaw.d_inv[573];
  workYaw.L[854] = (-workYaw.L[852]*workYaw.v[402])*workYaw.d_inv[573];
  workYaw.v[443] = workYaw.L[838]*workYaw.d[443];
  workYaw.v[444] = workYaw.L[839]*workYaw.d[444];
  workYaw.v[570] = workYaw.L[840]*workYaw.d[570];
  workYaw.v[571] = workYaw.L[841]*workYaw.d[571];
  workYaw.v[572] = workYaw.L[842]*workYaw.d[572];
  workYaw.v[573] = workYaw.L[843]*workYaw.d[573];
  workYaw.v[574] = 0-workYaw.L[838]*workYaw.v[443]-workYaw.L[839]*workYaw.v[444]-workYaw.L[840]*workYaw.v[570]-workYaw.L[841]*workYaw.v[571]-workYaw.L[842]*workYaw.v[572]-workYaw.L[843]*workYaw.v[573];
  workYaw.d[574] = workYaw.v[574];
  if (workYaw.d[574] > 0)
    workYaw.d[574] = -settingsYaw.kkt_reg;
  else
    workYaw.d[574] -= settingsYaw.kkt_reg;
  workYaw.d_inv[574] = 1/workYaw.d[574];
  workYaw.L[846] = (-workYaw.L[844]*workYaw.v[572]-workYaw.L[845]*workYaw.v[573])*workYaw.d_inv[574];
  workYaw.L[855] = (-workYaw.L[854]*workYaw.v[573])*workYaw.d_inv[574];
  workYaw.L[860] = (-workYaw.L[858]*workYaw.v[444])*workYaw.d_inv[574];
  workYaw.v[572] = workYaw.L[844]*workYaw.d[572];
  workYaw.v[573] = workYaw.L[845]*workYaw.d[573];
  workYaw.v[574] = workYaw.L[846]*workYaw.d[574];
  workYaw.v[575] = 0-workYaw.L[844]*workYaw.v[572]-workYaw.L[845]*workYaw.v[573]-workYaw.L[846]*workYaw.v[574];
  workYaw.d[575] = workYaw.v[575];
  if (workYaw.d[575] > 0)
    workYaw.d[575] = -settingsYaw.kkt_reg;
  else
    workYaw.d[575] -= settingsYaw.kkt_reg;
  workYaw.d_inv[575] = 1/workYaw.d[575];
  workYaw.L[849] = (workYaw.KKT[1117])*workYaw.d_inv[575];
  workYaw.L[856] = (-workYaw.L[854]*workYaw.v[573]-workYaw.L[855]*workYaw.v[574])*workYaw.d_inv[575];
  workYaw.L[861] = (-workYaw.L[860]*workYaw.v[574])*workYaw.d_inv[575];
  workYaw.v[193] = workYaw.L[847]*workYaw.d[193];
  workYaw.v[233] = workYaw.L[848]*workYaw.d[233];
  workYaw.v[575] = workYaw.L[849]*workYaw.d[575];
  workYaw.v[576] = workYaw.KKT[1118]-workYaw.L[847]*workYaw.v[193]-workYaw.L[848]*workYaw.v[233]-workYaw.L[849]*workYaw.v[575];
  workYaw.d[576] = workYaw.v[576];
  if (workYaw.d[576] < 0)
    workYaw.d[576] = settingsYaw.kkt_reg;
  else
    workYaw.d[576] += settingsYaw.kkt_reg;
  workYaw.d_inv[576] = 1/workYaw.d[576];
  workYaw.L[857] = (-workYaw.L[856]*workYaw.v[575])*workYaw.d_inv[576];
  workYaw.L[862] = (workYaw.KKT[1119]-workYaw.L[861]*workYaw.v[575])*workYaw.d_inv[576];
  workYaw.L[864] = (workYaw.KKT[1120])*workYaw.d_inv[576];
  workYaw.v[273] = workYaw.L[850]*workYaw.d[273];
  workYaw.v[313] = workYaw.L[851]*workYaw.d[313];
  workYaw.v[402] = workYaw.L[852]*workYaw.d[402];
  workYaw.v[403] = workYaw.L[853]*workYaw.d[403];
  workYaw.v[573] = workYaw.L[854]*workYaw.d[573];
  workYaw.v[574] = workYaw.L[855]*workYaw.d[574];
  workYaw.v[575] = workYaw.L[856]*workYaw.d[575];
  workYaw.v[576] = workYaw.L[857]*workYaw.d[576];
  workYaw.v[577] = workYaw.KKT[1121]-workYaw.L[850]*workYaw.v[273]-workYaw.L[851]*workYaw.v[313]-workYaw.L[852]*workYaw.v[402]-workYaw.L[853]*workYaw.v[403]-workYaw.L[854]*workYaw.v[573]-workYaw.L[855]*workYaw.v[574]-workYaw.L[856]*workYaw.v[575]-workYaw.L[857]*workYaw.v[576];
  workYaw.d[577] = workYaw.v[577];
  if (workYaw.d[577] < 0)
    workYaw.d[577] = settingsYaw.kkt_reg;
  else
    workYaw.d[577] += settingsYaw.kkt_reg;
  workYaw.d_inv[577] = 1/workYaw.d[577];
  workYaw.L[863] = (-workYaw.L[860]*workYaw.v[574]-workYaw.L[861]*workYaw.v[575]-workYaw.L[862]*workYaw.v[576])*workYaw.d_inv[577];
  workYaw.L[865] = (workYaw.KKT[1122]-workYaw.L[864]*workYaw.v[576])*workYaw.d_inv[577];
  workYaw.L[874] = (-workYaw.L[872]*workYaw.v[403])*workYaw.d_inv[577];
  workYaw.v[444] = workYaw.L[858]*workYaw.d[444];
  workYaw.v[445] = workYaw.L[859]*workYaw.d[445];
  workYaw.v[574] = workYaw.L[860]*workYaw.d[574];
  workYaw.v[575] = workYaw.L[861]*workYaw.d[575];
  workYaw.v[576] = workYaw.L[862]*workYaw.d[576];
  workYaw.v[577] = workYaw.L[863]*workYaw.d[577];
  workYaw.v[578] = 0-workYaw.L[858]*workYaw.v[444]-workYaw.L[859]*workYaw.v[445]-workYaw.L[860]*workYaw.v[574]-workYaw.L[861]*workYaw.v[575]-workYaw.L[862]*workYaw.v[576]-workYaw.L[863]*workYaw.v[577];
  workYaw.d[578] = workYaw.v[578];
  if (workYaw.d[578] > 0)
    workYaw.d[578] = -settingsYaw.kkt_reg;
  else
    workYaw.d[578] -= settingsYaw.kkt_reg;
  workYaw.d_inv[578] = 1/workYaw.d[578];
  workYaw.L[866] = (-workYaw.L[864]*workYaw.v[576]-workYaw.L[865]*workYaw.v[577])*workYaw.d_inv[578];
  workYaw.L[875] = (-workYaw.L[874]*workYaw.v[577])*workYaw.d_inv[578];
  workYaw.L[880] = (-workYaw.L[878]*workYaw.v[445])*workYaw.d_inv[578];
  workYaw.v[576] = workYaw.L[864]*workYaw.d[576];
  workYaw.v[577] = workYaw.L[865]*workYaw.d[577];
  workYaw.v[578] = workYaw.L[866]*workYaw.d[578];
  workYaw.v[579] = 0-workYaw.L[864]*workYaw.v[576]-workYaw.L[865]*workYaw.v[577]-workYaw.L[866]*workYaw.v[578];
  workYaw.d[579] = workYaw.v[579];
  if (workYaw.d[579] > 0)
    workYaw.d[579] = -settingsYaw.kkt_reg;
  else
    workYaw.d[579] -= settingsYaw.kkt_reg;
  workYaw.d_inv[579] = 1/workYaw.d[579];
  workYaw.L[869] = (workYaw.KKT[1123])*workYaw.d_inv[579];
  workYaw.L[876] = (-workYaw.L[874]*workYaw.v[577]-workYaw.L[875]*workYaw.v[578])*workYaw.d_inv[579];
  workYaw.L[881] = (-workYaw.L[880]*workYaw.v[578])*workYaw.d_inv[579];
  workYaw.v[194] = workYaw.L[867]*workYaw.d[194];
  workYaw.v[234] = workYaw.L[868]*workYaw.d[234];
  workYaw.v[579] = workYaw.L[869]*workYaw.d[579];
  workYaw.v[580] = workYaw.KKT[1124]-workYaw.L[867]*workYaw.v[194]-workYaw.L[868]*workYaw.v[234]-workYaw.L[869]*workYaw.v[579];
  workYaw.d[580] = workYaw.v[580];
  if (workYaw.d[580] < 0)
    workYaw.d[580] = settingsYaw.kkt_reg;
  else
    workYaw.d[580] += settingsYaw.kkt_reg;
  workYaw.d_inv[580] = 1/workYaw.d[580];
  workYaw.L[877] = (-workYaw.L[876]*workYaw.v[579])*workYaw.d_inv[580];
  workYaw.L[882] = (workYaw.KKT[1125]-workYaw.L[881]*workYaw.v[579])*workYaw.d_inv[580];
  workYaw.L[884] = (workYaw.KKT[1126])*workYaw.d_inv[580];
  workYaw.v[274] = workYaw.L[870]*workYaw.d[274];
  workYaw.v[314] = workYaw.L[871]*workYaw.d[314];
  workYaw.v[403] = workYaw.L[872]*workYaw.d[403];
  workYaw.v[404] = workYaw.L[873]*workYaw.d[404];
  workYaw.v[577] = workYaw.L[874]*workYaw.d[577];
  workYaw.v[578] = workYaw.L[875]*workYaw.d[578];
  workYaw.v[579] = workYaw.L[876]*workYaw.d[579];
  workYaw.v[580] = workYaw.L[877]*workYaw.d[580];
  workYaw.v[581] = workYaw.KKT[1127]-workYaw.L[870]*workYaw.v[274]-workYaw.L[871]*workYaw.v[314]-workYaw.L[872]*workYaw.v[403]-workYaw.L[873]*workYaw.v[404]-workYaw.L[874]*workYaw.v[577]-workYaw.L[875]*workYaw.v[578]-workYaw.L[876]*workYaw.v[579]-workYaw.L[877]*workYaw.v[580];
  workYaw.d[581] = workYaw.v[581];
  if (workYaw.d[581] < 0)
    workYaw.d[581] = settingsYaw.kkt_reg;
  else
    workYaw.d[581] += settingsYaw.kkt_reg;
  workYaw.d_inv[581] = 1/workYaw.d[581];
  workYaw.L[883] = (-workYaw.L[880]*workYaw.v[578]-workYaw.L[881]*workYaw.v[579]-workYaw.L[882]*workYaw.v[580])*workYaw.d_inv[581];
  workYaw.L[885] = (workYaw.KKT[1128]-workYaw.L[884]*workYaw.v[580])*workYaw.d_inv[581];
  workYaw.L[894] = (-workYaw.L[892]*workYaw.v[404])*workYaw.d_inv[581];
  workYaw.v[445] = workYaw.L[878]*workYaw.d[445];
  workYaw.v[446] = workYaw.L[879]*workYaw.d[446];
  workYaw.v[578] = workYaw.L[880]*workYaw.d[578];
  workYaw.v[579] = workYaw.L[881]*workYaw.d[579];
  workYaw.v[580] = workYaw.L[882]*workYaw.d[580];
  workYaw.v[581] = workYaw.L[883]*workYaw.d[581];
  workYaw.v[582] = 0-workYaw.L[878]*workYaw.v[445]-workYaw.L[879]*workYaw.v[446]-workYaw.L[880]*workYaw.v[578]-workYaw.L[881]*workYaw.v[579]-workYaw.L[882]*workYaw.v[580]-workYaw.L[883]*workYaw.v[581];
  workYaw.d[582] = workYaw.v[582];
  if (workYaw.d[582] > 0)
    workYaw.d[582] = -settingsYaw.kkt_reg;
  else
    workYaw.d[582] -= settingsYaw.kkt_reg;
  workYaw.d_inv[582] = 1/workYaw.d[582];
  workYaw.L[886] = (-workYaw.L[884]*workYaw.v[580]-workYaw.L[885]*workYaw.v[581])*workYaw.d_inv[582];
  workYaw.L[895] = (-workYaw.L[894]*workYaw.v[581])*workYaw.d_inv[582];
  workYaw.L[900] = (-workYaw.L[898]*workYaw.v[446])*workYaw.d_inv[582];
  workYaw.v[580] = workYaw.L[884]*workYaw.d[580];
  workYaw.v[581] = workYaw.L[885]*workYaw.d[581];
  workYaw.v[582] = workYaw.L[886]*workYaw.d[582];
  workYaw.v[583] = 0-workYaw.L[884]*workYaw.v[580]-workYaw.L[885]*workYaw.v[581]-workYaw.L[886]*workYaw.v[582];
  workYaw.d[583] = workYaw.v[583];
  if (workYaw.d[583] > 0)
    workYaw.d[583] = -settingsYaw.kkt_reg;
  else
    workYaw.d[583] -= settingsYaw.kkt_reg;
  workYaw.d_inv[583] = 1/workYaw.d[583];
  workYaw.L[889] = (workYaw.KKT[1129])*workYaw.d_inv[583];
  workYaw.L[896] = (-workYaw.L[894]*workYaw.v[581]-workYaw.L[895]*workYaw.v[582])*workYaw.d_inv[583];
  workYaw.L[901] = (-workYaw.L[900]*workYaw.v[582])*workYaw.d_inv[583];
  workYaw.v[195] = workYaw.L[887]*workYaw.d[195];
  workYaw.v[235] = workYaw.L[888]*workYaw.d[235];
  workYaw.v[583] = workYaw.L[889]*workYaw.d[583];
  workYaw.v[584] = workYaw.KKT[1130]-workYaw.L[887]*workYaw.v[195]-workYaw.L[888]*workYaw.v[235]-workYaw.L[889]*workYaw.v[583];
  workYaw.d[584] = workYaw.v[584];
  if (workYaw.d[584] < 0)
    workYaw.d[584] = settingsYaw.kkt_reg;
  else
    workYaw.d[584] += settingsYaw.kkt_reg;
  workYaw.d_inv[584] = 1/workYaw.d[584];
  workYaw.L[897] = (-workYaw.L[896]*workYaw.v[583])*workYaw.d_inv[584];
  workYaw.L[902] = (workYaw.KKT[1131]-workYaw.L[901]*workYaw.v[583])*workYaw.d_inv[584];
  workYaw.L[904] = (workYaw.KKT[1132])*workYaw.d_inv[584];
  workYaw.v[275] = workYaw.L[890]*workYaw.d[275];
  workYaw.v[315] = workYaw.L[891]*workYaw.d[315];
  workYaw.v[404] = workYaw.L[892]*workYaw.d[404];
  workYaw.v[405] = workYaw.L[893]*workYaw.d[405];
  workYaw.v[581] = workYaw.L[894]*workYaw.d[581];
  workYaw.v[582] = workYaw.L[895]*workYaw.d[582];
  workYaw.v[583] = workYaw.L[896]*workYaw.d[583];
  workYaw.v[584] = workYaw.L[897]*workYaw.d[584];
  workYaw.v[585] = workYaw.KKT[1133]-workYaw.L[890]*workYaw.v[275]-workYaw.L[891]*workYaw.v[315]-workYaw.L[892]*workYaw.v[404]-workYaw.L[893]*workYaw.v[405]-workYaw.L[894]*workYaw.v[581]-workYaw.L[895]*workYaw.v[582]-workYaw.L[896]*workYaw.v[583]-workYaw.L[897]*workYaw.v[584];
  workYaw.d[585] = workYaw.v[585];
  if (workYaw.d[585] < 0)
    workYaw.d[585] = settingsYaw.kkt_reg;
  else
    workYaw.d[585] += settingsYaw.kkt_reg;
  workYaw.d_inv[585] = 1/workYaw.d[585];
  workYaw.L[903] = (-workYaw.L[900]*workYaw.v[582]-workYaw.L[901]*workYaw.v[583]-workYaw.L[902]*workYaw.v[584])*workYaw.d_inv[585];
  workYaw.L[905] = (workYaw.KKT[1134]-workYaw.L[904]*workYaw.v[584])*workYaw.d_inv[585];
  workYaw.L[914] = (-workYaw.L[912]*workYaw.v[405])*workYaw.d_inv[585];
  workYaw.v[446] = workYaw.L[898]*workYaw.d[446];
  workYaw.v[447] = workYaw.L[899]*workYaw.d[447];
  workYaw.v[582] = workYaw.L[900]*workYaw.d[582];
  workYaw.v[583] = workYaw.L[901]*workYaw.d[583];
  workYaw.v[584] = workYaw.L[902]*workYaw.d[584];
  workYaw.v[585] = workYaw.L[903]*workYaw.d[585];
  workYaw.v[586] = 0-workYaw.L[898]*workYaw.v[446]-workYaw.L[899]*workYaw.v[447]-workYaw.L[900]*workYaw.v[582]-workYaw.L[901]*workYaw.v[583]-workYaw.L[902]*workYaw.v[584]-workYaw.L[903]*workYaw.v[585];
  workYaw.d[586] = workYaw.v[586];
  if (workYaw.d[586] > 0)
    workYaw.d[586] = -settingsYaw.kkt_reg;
  else
    workYaw.d[586] -= settingsYaw.kkt_reg;
  workYaw.d_inv[586] = 1/workYaw.d[586];
  workYaw.L[906] = (-workYaw.L[904]*workYaw.v[584]-workYaw.L[905]*workYaw.v[585])*workYaw.d_inv[586];
  workYaw.L[915] = (-workYaw.L[914]*workYaw.v[585])*workYaw.d_inv[586];
  workYaw.L[920] = (-workYaw.L[918]*workYaw.v[447])*workYaw.d_inv[586];
  workYaw.v[584] = workYaw.L[904]*workYaw.d[584];
  workYaw.v[585] = workYaw.L[905]*workYaw.d[585];
  workYaw.v[586] = workYaw.L[906]*workYaw.d[586];
  workYaw.v[587] = 0-workYaw.L[904]*workYaw.v[584]-workYaw.L[905]*workYaw.v[585]-workYaw.L[906]*workYaw.v[586];
  workYaw.d[587] = workYaw.v[587];
  if (workYaw.d[587] > 0)
    workYaw.d[587] = -settingsYaw.kkt_reg;
  else
    workYaw.d[587] -= settingsYaw.kkt_reg;
  workYaw.d_inv[587] = 1/workYaw.d[587];
  workYaw.L[909] = (workYaw.KKT[1135])*workYaw.d_inv[587];
  workYaw.L[916] = (-workYaw.L[914]*workYaw.v[585]-workYaw.L[915]*workYaw.v[586])*workYaw.d_inv[587];
  workYaw.L[921] = (-workYaw.L[920]*workYaw.v[586])*workYaw.d_inv[587];
  workYaw.v[196] = workYaw.L[907]*workYaw.d[196];
  workYaw.v[236] = workYaw.L[908]*workYaw.d[236];
  workYaw.v[587] = workYaw.L[909]*workYaw.d[587];
  workYaw.v[588] = workYaw.KKT[1136]-workYaw.L[907]*workYaw.v[196]-workYaw.L[908]*workYaw.v[236]-workYaw.L[909]*workYaw.v[587];
  workYaw.d[588] = workYaw.v[588];
  if (workYaw.d[588] < 0)
    workYaw.d[588] = settingsYaw.kkt_reg;
  else
    workYaw.d[588] += settingsYaw.kkt_reg;
  workYaw.d_inv[588] = 1/workYaw.d[588];
  workYaw.L[917] = (-workYaw.L[916]*workYaw.v[587])*workYaw.d_inv[588];
  workYaw.L[922] = (workYaw.KKT[1137]-workYaw.L[921]*workYaw.v[587])*workYaw.d_inv[588];
  workYaw.L[924] = (workYaw.KKT[1138])*workYaw.d_inv[588];
  workYaw.v[276] = workYaw.L[910]*workYaw.d[276];
  workYaw.v[316] = workYaw.L[911]*workYaw.d[316];
  workYaw.v[405] = workYaw.L[912]*workYaw.d[405];
  workYaw.v[406] = workYaw.L[913]*workYaw.d[406];
  workYaw.v[585] = workYaw.L[914]*workYaw.d[585];
  workYaw.v[586] = workYaw.L[915]*workYaw.d[586];
  workYaw.v[587] = workYaw.L[916]*workYaw.d[587];
  workYaw.v[588] = workYaw.L[917]*workYaw.d[588];
  workYaw.v[589] = workYaw.KKT[1139]-workYaw.L[910]*workYaw.v[276]-workYaw.L[911]*workYaw.v[316]-workYaw.L[912]*workYaw.v[405]-workYaw.L[913]*workYaw.v[406]-workYaw.L[914]*workYaw.v[585]-workYaw.L[915]*workYaw.v[586]-workYaw.L[916]*workYaw.v[587]-workYaw.L[917]*workYaw.v[588];
  workYaw.d[589] = workYaw.v[589];
  if (workYaw.d[589] < 0)
    workYaw.d[589] = settingsYaw.kkt_reg;
  else
    workYaw.d[589] += settingsYaw.kkt_reg;
  workYaw.d_inv[589] = 1/workYaw.d[589];
  workYaw.L[923] = (-workYaw.L[920]*workYaw.v[586]-workYaw.L[921]*workYaw.v[587]-workYaw.L[922]*workYaw.v[588])*workYaw.d_inv[589];
  workYaw.L[925] = (workYaw.KKT[1140]-workYaw.L[924]*workYaw.v[588])*workYaw.d_inv[589];
  workYaw.L[934] = (-workYaw.L[932]*workYaw.v[406])*workYaw.d_inv[589];
  workYaw.v[447] = workYaw.L[918]*workYaw.d[447];
  workYaw.v[448] = workYaw.L[919]*workYaw.d[448];
  workYaw.v[586] = workYaw.L[920]*workYaw.d[586];
  workYaw.v[587] = workYaw.L[921]*workYaw.d[587];
  workYaw.v[588] = workYaw.L[922]*workYaw.d[588];
  workYaw.v[589] = workYaw.L[923]*workYaw.d[589];
  workYaw.v[590] = 0-workYaw.L[918]*workYaw.v[447]-workYaw.L[919]*workYaw.v[448]-workYaw.L[920]*workYaw.v[586]-workYaw.L[921]*workYaw.v[587]-workYaw.L[922]*workYaw.v[588]-workYaw.L[923]*workYaw.v[589];
  workYaw.d[590] = workYaw.v[590];
  if (workYaw.d[590] > 0)
    workYaw.d[590] = -settingsYaw.kkt_reg;
  else
    workYaw.d[590] -= settingsYaw.kkt_reg;
  workYaw.d_inv[590] = 1/workYaw.d[590];
  workYaw.L[926] = (-workYaw.L[924]*workYaw.v[588]-workYaw.L[925]*workYaw.v[589])*workYaw.d_inv[590];
  workYaw.L[935] = (-workYaw.L[934]*workYaw.v[589])*workYaw.d_inv[590];
  workYaw.L[940] = (-workYaw.L[938]*workYaw.v[448])*workYaw.d_inv[590];
  workYaw.v[588] = workYaw.L[924]*workYaw.d[588];
  workYaw.v[589] = workYaw.L[925]*workYaw.d[589];
  workYaw.v[590] = workYaw.L[926]*workYaw.d[590];
  workYaw.v[591] = 0-workYaw.L[924]*workYaw.v[588]-workYaw.L[925]*workYaw.v[589]-workYaw.L[926]*workYaw.v[590];
  workYaw.d[591] = workYaw.v[591];
  if (workYaw.d[591] > 0)
    workYaw.d[591] = -settingsYaw.kkt_reg;
  else
    workYaw.d[591] -= settingsYaw.kkt_reg;
  workYaw.d_inv[591] = 1/workYaw.d[591];
  workYaw.L[929] = (workYaw.KKT[1141])*workYaw.d_inv[591];
  workYaw.L[936] = (-workYaw.L[934]*workYaw.v[589]-workYaw.L[935]*workYaw.v[590])*workYaw.d_inv[591];
  workYaw.L[941] = (-workYaw.L[940]*workYaw.v[590])*workYaw.d_inv[591];
  workYaw.v[197] = workYaw.L[927]*workYaw.d[197];
  workYaw.v[237] = workYaw.L[928]*workYaw.d[237];
  workYaw.v[591] = workYaw.L[929]*workYaw.d[591];
  workYaw.v[592] = workYaw.KKT[1142]-workYaw.L[927]*workYaw.v[197]-workYaw.L[928]*workYaw.v[237]-workYaw.L[929]*workYaw.v[591];
  workYaw.d[592] = workYaw.v[592];
  if (workYaw.d[592] < 0)
    workYaw.d[592] = settingsYaw.kkt_reg;
  else
    workYaw.d[592] += settingsYaw.kkt_reg;
  workYaw.d_inv[592] = 1/workYaw.d[592];
  workYaw.L[937] = (-workYaw.L[936]*workYaw.v[591])*workYaw.d_inv[592];
  workYaw.L[942] = (workYaw.KKT[1143]-workYaw.L[941]*workYaw.v[591])*workYaw.d_inv[592];
  workYaw.L[944] = (workYaw.KKT[1144])*workYaw.d_inv[592];
  workYaw.v[277] = workYaw.L[930]*workYaw.d[277];
  workYaw.v[317] = workYaw.L[931]*workYaw.d[317];
  workYaw.v[406] = workYaw.L[932]*workYaw.d[406];
  workYaw.v[407] = workYaw.L[933]*workYaw.d[407];
  workYaw.v[589] = workYaw.L[934]*workYaw.d[589];
  workYaw.v[590] = workYaw.L[935]*workYaw.d[590];
  workYaw.v[591] = workYaw.L[936]*workYaw.d[591];
  workYaw.v[592] = workYaw.L[937]*workYaw.d[592];
  workYaw.v[593] = workYaw.KKT[1145]-workYaw.L[930]*workYaw.v[277]-workYaw.L[931]*workYaw.v[317]-workYaw.L[932]*workYaw.v[406]-workYaw.L[933]*workYaw.v[407]-workYaw.L[934]*workYaw.v[589]-workYaw.L[935]*workYaw.v[590]-workYaw.L[936]*workYaw.v[591]-workYaw.L[937]*workYaw.v[592];
  workYaw.d[593] = workYaw.v[593];
  if (workYaw.d[593] < 0)
    workYaw.d[593] = settingsYaw.kkt_reg;
  else
    workYaw.d[593] += settingsYaw.kkt_reg;
  workYaw.d_inv[593] = 1/workYaw.d[593];
  workYaw.L[943] = (-workYaw.L[940]*workYaw.v[590]-workYaw.L[941]*workYaw.v[591]-workYaw.L[942]*workYaw.v[592])*workYaw.d_inv[593];
  workYaw.L[945] = (workYaw.KKT[1146]-workYaw.L[944]*workYaw.v[592])*workYaw.d_inv[593];
  workYaw.L[961] = (-workYaw.L[958]*workYaw.v[407])*workYaw.d_inv[593];
  workYaw.v[448] = workYaw.L[938]*workYaw.d[448];
  workYaw.v[449] = workYaw.L[939]*workYaw.d[449];
  workYaw.v[590] = workYaw.L[940]*workYaw.d[590];
  workYaw.v[591] = workYaw.L[941]*workYaw.d[591];
  workYaw.v[592] = workYaw.L[942]*workYaw.d[592];
  workYaw.v[593] = workYaw.L[943]*workYaw.d[593];
  workYaw.v[594] = 0-workYaw.L[938]*workYaw.v[448]-workYaw.L[939]*workYaw.v[449]-workYaw.L[940]*workYaw.v[590]-workYaw.L[941]*workYaw.v[591]-workYaw.L[942]*workYaw.v[592]-workYaw.L[943]*workYaw.v[593];
  workYaw.d[594] = workYaw.v[594];
  if (workYaw.d[594] > 0)
    workYaw.d[594] = -settingsYaw.kkt_reg;
  else
    workYaw.d[594] -= settingsYaw.kkt_reg;
  workYaw.d_inv[594] = 1/workYaw.d[594];
  workYaw.L[946] = (-workYaw.L[944]*workYaw.v[592]-workYaw.L[945]*workYaw.v[593])*workYaw.d_inv[594];
  workYaw.L[949] = (-workYaw.L[947]*workYaw.v[449])*workYaw.d_inv[594];
  workYaw.L[962] = (-workYaw.L[961]*workYaw.v[593])*workYaw.d_inv[594];
  workYaw.v[592] = workYaw.L[944]*workYaw.d[592];
  workYaw.v[593] = workYaw.L[945]*workYaw.d[593];
  workYaw.v[594] = workYaw.L[946]*workYaw.d[594];
  workYaw.v[595] = 0-workYaw.L[944]*workYaw.v[592]-workYaw.L[945]*workYaw.v[593]-workYaw.L[946]*workYaw.v[594];
  workYaw.d[595] = workYaw.v[595];
  if (workYaw.d[595] > 0)
    workYaw.d[595] = -settingsYaw.kkt_reg;
  else
    workYaw.d[595] -= settingsYaw.kkt_reg;
  workYaw.d_inv[595] = 1/workYaw.d[595];
  workYaw.L[950] = (-workYaw.L[949]*workYaw.v[594])*workYaw.d_inv[595];
  workYaw.L[953] = (workYaw.KKT[1147])*workYaw.d_inv[595];
  workYaw.L[963] = (-workYaw.L[961]*workYaw.v[593]-workYaw.L[962]*workYaw.v[594])*workYaw.d_inv[595];
  workYaw.v[449] = workYaw.L[947]*workYaw.d[449];
  workYaw.v[450] = workYaw.L[948]*workYaw.d[450];
  workYaw.v[594] = workYaw.L[949]*workYaw.d[594];
  workYaw.v[595] = workYaw.L[950]*workYaw.d[595];
  workYaw.v[596] = 0-workYaw.L[947]*workYaw.v[449]-workYaw.L[948]*workYaw.v[450]-workYaw.L[949]*workYaw.v[594]-workYaw.L[950]*workYaw.v[595];
  workYaw.d[596] = workYaw.v[596];
  if (workYaw.d[596] > 0)
    workYaw.d[596] = -settingsYaw.kkt_reg;
  else
    workYaw.d[596] -= settingsYaw.kkt_reg;
  workYaw.d_inv[596] = 1/workYaw.d[596];
  workYaw.L[954] = (workYaw.KKT[1148]-workYaw.L[953]*workYaw.v[595])*workYaw.d_inv[596];
  workYaw.L[964] = (-workYaw.L[962]*workYaw.v[594]-workYaw.L[963]*workYaw.v[595])*workYaw.d_inv[596];
  workYaw.L[972] = (-workYaw.L[971]*workYaw.v[450])*workYaw.d_inv[596];
  workYaw.v[597] = 0;
  workYaw.d[597] = workYaw.v[597];
  if (workYaw.d[597] > 0)
    workYaw.d[597] = -settingsYaw.kkt_reg;
  else
    workYaw.d[597] -= settingsYaw.kkt_reg;
  workYaw.d_inv[597] = 1/workYaw.d[597];
  workYaw.L[955] = (workYaw.KKT[1149])*workYaw.d_inv[597];
  workYaw.L[965] = (workYaw.KKT[1150])*workYaw.d_inv[597];
  workYaw.L[973] = (workYaw.KKT[1151])*workYaw.d_inv[597];
  workYaw.v[198] = workYaw.L[951]*workYaw.d[198];
  workYaw.v[238] = workYaw.L[952]*workYaw.d[238];
  workYaw.v[595] = workYaw.L[953]*workYaw.d[595];
  workYaw.v[596] = workYaw.L[954]*workYaw.d[596];
  workYaw.v[597] = workYaw.L[955]*workYaw.d[597];
  workYaw.v[598] = workYaw.KKT[1152]-workYaw.L[951]*workYaw.v[198]-workYaw.L[952]*workYaw.v[238]-workYaw.L[953]*workYaw.v[595]-workYaw.L[954]*workYaw.v[596]-workYaw.L[955]*workYaw.v[597];
  workYaw.d[598] = workYaw.v[598];
  if (workYaw.d[598] < 0)
    workYaw.d[598] = settingsYaw.kkt_reg;
  else
    workYaw.d[598] += settingsYaw.kkt_reg;
  workYaw.d_inv[598] = 1/workYaw.d[598];
  workYaw.L[966] = (-workYaw.L[963]*workYaw.v[595]-workYaw.L[964]*workYaw.v[596]-workYaw.L[965]*workYaw.v[597])*workYaw.d_inv[598];
  workYaw.L[974] = (-workYaw.L[972]*workYaw.v[596]-workYaw.L[973]*workYaw.v[597])*workYaw.d_inv[598];
  workYaw.v[278] = workYaw.L[956]*workYaw.d[278];
  workYaw.v[318] = workYaw.L[957]*workYaw.d[318];
  workYaw.v[407] = workYaw.L[958]*workYaw.d[407];
  workYaw.v[408] = workYaw.L[959]*workYaw.d[408];
  workYaw.v[410] = workYaw.L[960]*workYaw.d[410];
  workYaw.v[593] = workYaw.L[961]*workYaw.d[593];
  workYaw.v[594] = workYaw.L[962]*workYaw.d[594];
  workYaw.v[595] = workYaw.L[963]*workYaw.d[595];
  workYaw.v[596] = workYaw.L[964]*workYaw.d[596];
  workYaw.v[597] = workYaw.L[965]*workYaw.d[597];
  workYaw.v[598] = workYaw.L[966]*workYaw.d[598];
  workYaw.v[599] = workYaw.KKT[1153]-workYaw.L[956]*workYaw.v[278]-workYaw.L[957]*workYaw.v[318]-workYaw.L[958]*workYaw.v[407]-workYaw.L[959]*workYaw.v[408]-workYaw.L[960]*workYaw.v[410]-workYaw.L[961]*workYaw.v[593]-workYaw.L[962]*workYaw.v[594]-workYaw.L[963]*workYaw.v[595]-workYaw.L[964]*workYaw.v[596]-workYaw.L[965]*workYaw.v[597]-workYaw.L[966]*workYaw.v[598];
  workYaw.d[599] = workYaw.v[599];
  if (workYaw.d[599] < 0)
    workYaw.d[599] = settingsYaw.kkt_reg;
  else
    workYaw.d[599] += settingsYaw.kkt_reg;
  workYaw.d_inv[599] = 1/workYaw.d[599];
  workYaw.L[975] = (-workYaw.L[970]*workYaw.v[410]-workYaw.L[972]*workYaw.v[596]-workYaw.L[973]*workYaw.v[597]-workYaw.L[974]*workYaw.v[598])*workYaw.d_inv[599];
  workYaw.v[199] = workYaw.L[967]*workYaw.d[199];
  workYaw.v[239] = workYaw.L[968]*workYaw.d[239];
  workYaw.v[409] = workYaw.L[969]*workYaw.d[409];
  workYaw.v[410] = workYaw.L[970]*workYaw.d[410];
  workYaw.v[450] = workYaw.L[971]*workYaw.d[450];
  workYaw.v[596] = workYaw.L[972]*workYaw.d[596];
  workYaw.v[597] = workYaw.L[973]*workYaw.d[597];
  workYaw.v[598] = workYaw.L[974]*workYaw.d[598];
  workYaw.v[599] = workYaw.L[975]*workYaw.d[599];
  workYaw.v[600] = workYaw.KKT[1154]-workYaw.L[967]*workYaw.v[199]-workYaw.L[968]*workYaw.v[239]-workYaw.L[969]*workYaw.v[409]-workYaw.L[970]*workYaw.v[410]-workYaw.L[971]*workYaw.v[450]-workYaw.L[972]*workYaw.v[596]-workYaw.L[973]*workYaw.v[597]-workYaw.L[974]*workYaw.v[598]-workYaw.L[975]*workYaw.v[599];
  workYaw.d[600] = workYaw.v[600];
  if (workYaw.d[600] < 0)
    workYaw.d[600] = settingsYaw.kkt_reg;
  else
    workYaw.d[600] += settingsYaw.kkt_reg;
  workYaw.d_inv[600] = 1/workYaw.d[600];
#ifndef ZERO_LIBRARY_MODE
  if (settingsYaw.debug) {
    printf("Squared Frobenius for factorization is %.8g.\n", check_factorization_yaw());
  }
#endif
}
double check_factorization_yaw(void) {
  /* Returns the squared Frobenius norm of A - L*D*L'. */
  double temp, residual;
  /* Only check the lower triangle. */
  residual = 0;
  temp = workYaw.KKT[645]-1*workYaw.d[325]*1;
  residual += temp*temp;
  temp = workYaw.KKT[647]-1*workYaw.d[326]*1;
  residual += temp*temp;
  temp = workYaw.KKT[649]-1*workYaw.d[327]*1;
  residual += temp*temp;
  temp = workYaw.KKT[651]-1*workYaw.d[328]*1;
  residual += temp*temp;
  temp = workYaw.KKT[653]-1*workYaw.d[329]*1;
  residual += temp*temp;
  temp = workYaw.KKT[655]-1*workYaw.d[330]*1;
  residual += temp*temp;
  temp = workYaw.KKT[657]-1*workYaw.d[331]*1;
  residual += temp*temp;
  temp = workYaw.KKT[659]-1*workYaw.d[332]*1;
  residual += temp*temp;
  temp = workYaw.KKT[661]-1*workYaw.d[333]*1;
  residual += temp*temp;
  temp = workYaw.KKT[663]-1*workYaw.d[334]*1;
  residual += temp*temp;
  temp = workYaw.KKT[665]-1*workYaw.d[335]*1;
  residual += temp*temp;
  temp = workYaw.KKT[667]-1*workYaw.d[336]*1;
  residual += temp*temp;
  temp = workYaw.KKT[669]-1*workYaw.d[337]*1;
  residual += temp*temp;
  temp = workYaw.KKT[671]-1*workYaw.d[338]*1;
  residual += temp*temp;
  temp = workYaw.KKT[673]-1*workYaw.d[339]*1;
  residual += temp*temp;
  temp = workYaw.KKT[675]-1*workYaw.d[340]*1;
  residual += temp*temp;
  temp = workYaw.KKT[677]-1*workYaw.d[341]*1;
  residual += temp*temp;
  temp = workYaw.KKT[679]-1*workYaw.d[342]*1;
  residual += temp*temp;
  temp = workYaw.KKT[681]-1*workYaw.d[343]*1;
  residual += temp*temp;
  temp = workYaw.KKT[683]-1*workYaw.d[344]*1;
  residual += temp*temp;
  temp = workYaw.KKT[685]-1*workYaw.d[345]*1;
  residual += temp*temp;
  temp = workYaw.KKT[687]-1*workYaw.d[346]*1;
  residual += temp*temp;
  temp = workYaw.KKT[689]-1*workYaw.d[347]*1;
  residual += temp*temp;
  temp = workYaw.KKT[691]-1*workYaw.d[348]*1;
  residual += temp*temp;
  temp = workYaw.KKT[693]-1*workYaw.d[349]*1;
  residual += temp*temp;
  temp = workYaw.KKT[695]-1*workYaw.d[350]*1;
  residual += temp*temp;
  temp = workYaw.KKT[697]-1*workYaw.d[351]*1;
  residual += temp*temp;
  temp = workYaw.KKT[699]-1*workYaw.d[352]*1;
  residual += temp*temp;
  temp = workYaw.KKT[701]-1*workYaw.d[353]*1;
  residual += temp*temp;
  temp = workYaw.KKT[703]-1*workYaw.d[354]*1;
  residual += temp*temp;
  temp = workYaw.KKT[705]-1*workYaw.d[355]*1;
  residual += temp*temp;
  temp = workYaw.KKT[707]-1*workYaw.d[356]*1;
  residual += temp*temp;
  temp = workYaw.KKT[709]-1*workYaw.d[357]*1;
  residual += temp*temp;
  temp = workYaw.KKT[711]-1*workYaw.d[358]*1;
  residual += temp*temp;
  temp = workYaw.KKT[713]-1*workYaw.d[359]*1;
  residual += temp*temp;
  temp = workYaw.KKT[715]-1*workYaw.d[360]*1;
  residual += temp*temp;
  temp = workYaw.KKT[717]-1*workYaw.d[361]*1;
  residual += temp*temp;
  temp = workYaw.KKT[719]-1*workYaw.d[362]*1;
  residual += temp*temp;
  temp = workYaw.KKT[721]-1*workYaw.d[363]*1;
  residual += temp*temp;
  temp = workYaw.KKT[0]-1*workYaw.d[0]*1;
  residual += temp*temp;
  temp = workYaw.KKT[726]-1*workYaw.d[366]*1-workYaw.L[165]*workYaw.d[321]*workYaw.L[165];
  residual += temp*temp;
  temp = workYaw.KKT[815]-1*workYaw.d[411]*1-workYaw.L[215]*workYaw.d[161]*workYaw.L[215]-workYaw.L[216]*workYaw.d[201]*workYaw.L[216]-workYaw.L[217]*workYaw.d[322]*workYaw.L[217]-workYaw.L[218]*workYaw.d[370]*workYaw.L[218];
  residual += temp*temp;
  temp = workYaw.KKT[817]-1*workYaw.d[412]*1-workYaw.L[219]*workYaw.d[241]*workYaw.L[219]-workYaw.L[220]*workYaw.d[281]*workYaw.L[220]-workYaw.L[221]*workYaw.d[324]*workYaw.L[221]-workYaw.L[222]*workYaw.d[371]*workYaw.L[222];
  residual += temp*temp;
  temp = workYaw.KKT[819]-1*workYaw.d[413]*1-workYaw.L[223]*workYaw.d[370]*workYaw.L[223]-workYaw.L[224]*workYaw.d[411]*workYaw.L[224];
  residual += temp*temp;
  temp = workYaw.KKT[932]-1*workYaw.d[452]*1-workYaw.L[229]*workYaw.d[162]*workYaw.L[229]-workYaw.L[230]*workYaw.d[202]*workYaw.L[230]-workYaw.L[231]*workYaw.d[451]*workYaw.L[231];
  residual += temp*temp;
  temp = workYaw.KKT[935]-1*workYaw.d[453]*1-workYaw.L[232]*workYaw.d[242]*workYaw.L[232]-workYaw.L[233]*workYaw.d[282]*workYaw.L[233]-workYaw.L[234]*workYaw.d[371]*workYaw.L[234]-workYaw.L[235]*workYaw.d[372]*workYaw.L[235]-workYaw.L[236]*workYaw.d[412]*workYaw.L[236]-workYaw.L[237]*workYaw.d[451]*workYaw.L[237]-workYaw.L[238]*workYaw.d[452]*workYaw.L[238];
  residual += temp*temp;
  temp = workYaw.KKT[821]-1*workYaw.d[414]*1;
  residual += temp*temp;
  temp = workYaw.KKT[938]-1*workYaw.d[456]*1-workYaw.L[247]*workYaw.d[163]*workYaw.L[247]-workYaw.L[248]*workYaw.d[203]*workYaw.L[248]-workYaw.L[249]*workYaw.d[455]*workYaw.L[249];
  residual += temp*temp;
  temp = workYaw.KKT[941]-1*workYaw.d[457]*1-workYaw.L[250]*workYaw.d[243]*workYaw.L[250]-workYaw.L[251]*workYaw.d[283]*workYaw.L[251]-workYaw.L[252]*workYaw.d[372]*workYaw.L[252]-workYaw.L[253]*workYaw.d[373]*workYaw.L[253]-workYaw.L[254]*workYaw.d[453]*workYaw.L[254]-workYaw.L[256]*workYaw.d[455]*workYaw.L[256]-workYaw.L[255]*workYaw.d[454]*workYaw.L[255]-workYaw.L[257]*workYaw.d[456]*workYaw.L[257];
  residual += temp*temp;
  temp = workYaw.KKT[824]-1*workYaw.d[415]*1;
  residual += temp*temp;
  temp = workYaw.KKT[944]-1*workYaw.d[460]*1-workYaw.L[267]*workYaw.d[164]*workYaw.L[267]-workYaw.L[268]*workYaw.d[204]*workYaw.L[268]-workYaw.L[269]*workYaw.d[459]*workYaw.L[269];
  residual += temp*temp;
  temp = workYaw.KKT[947]-1*workYaw.d[461]*1-workYaw.L[270]*workYaw.d[244]*workYaw.L[270]-workYaw.L[271]*workYaw.d[284]*workYaw.L[271]-workYaw.L[272]*workYaw.d[373]*workYaw.L[272]-workYaw.L[273]*workYaw.d[374]*workYaw.L[273]-workYaw.L[274]*workYaw.d[457]*workYaw.L[274]-workYaw.L[276]*workYaw.d[459]*workYaw.L[276]-workYaw.L[275]*workYaw.d[458]*workYaw.L[275]-workYaw.L[277]*workYaw.d[460]*workYaw.L[277];
  residual += temp*temp;
  temp = workYaw.KKT[827]-1*workYaw.d[416]*1;
  residual += temp*temp;
  temp = workYaw.KKT[950]-1*workYaw.d[464]*1-workYaw.L[287]*workYaw.d[165]*workYaw.L[287]-workYaw.L[288]*workYaw.d[205]*workYaw.L[288]-workYaw.L[289]*workYaw.d[463]*workYaw.L[289];
  residual += temp*temp;
  temp = workYaw.KKT[953]-1*workYaw.d[465]*1-workYaw.L[290]*workYaw.d[245]*workYaw.L[290]-workYaw.L[291]*workYaw.d[285]*workYaw.L[291]-workYaw.L[292]*workYaw.d[374]*workYaw.L[292]-workYaw.L[293]*workYaw.d[375]*workYaw.L[293]-workYaw.L[294]*workYaw.d[461]*workYaw.L[294]-workYaw.L[296]*workYaw.d[463]*workYaw.L[296]-workYaw.L[295]*workYaw.d[462]*workYaw.L[295]-workYaw.L[297]*workYaw.d[464]*workYaw.L[297];
  residual += temp*temp;
  temp = workYaw.KKT[830]-1*workYaw.d[417]*1;
  residual += temp*temp;
  temp = workYaw.KKT[956]-1*workYaw.d[468]*1-workYaw.L[307]*workYaw.d[166]*workYaw.L[307]-workYaw.L[308]*workYaw.d[206]*workYaw.L[308]-workYaw.L[309]*workYaw.d[467]*workYaw.L[309];
  residual += temp*temp;
  temp = workYaw.KKT[959]-1*workYaw.d[469]*1-workYaw.L[310]*workYaw.d[246]*workYaw.L[310]-workYaw.L[311]*workYaw.d[286]*workYaw.L[311]-workYaw.L[312]*workYaw.d[375]*workYaw.L[312]-workYaw.L[313]*workYaw.d[376]*workYaw.L[313]-workYaw.L[314]*workYaw.d[465]*workYaw.L[314]-workYaw.L[316]*workYaw.d[467]*workYaw.L[316]-workYaw.L[315]*workYaw.d[466]*workYaw.L[315]-workYaw.L[317]*workYaw.d[468]*workYaw.L[317];
  residual += temp*temp;
  temp = workYaw.KKT[833]-1*workYaw.d[418]*1;
  residual += temp*temp;
  temp = workYaw.KKT[962]-1*workYaw.d[472]*1-workYaw.L[327]*workYaw.d[167]*workYaw.L[327]-workYaw.L[328]*workYaw.d[207]*workYaw.L[328]-workYaw.L[329]*workYaw.d[471]*workYaw.L[329];
  residual += temp*temp;
  temp = workYaw.KKT[965]-1*workYaw.d[473]*1-workYaw.L[330]*workYaw.d[247]*workYaw.L[330]-workYaw.L[331]*workYaw.d[287]*workYaw.L[331]-workYaw.L[332]*workYaw.d[376]*workYaw.L[332]-workYaw.L[333]*workYaw.d[377]*workYaw.L[333]-workYaw.L[334]*workYaw.d[469]*workYaw.L[334]-workYaw.L[336]*workYaw.d[471]*workYaw.L[336]-workYaw.L[335]*workYaw.d[470]*workYaw.L[335]-workYaw.L[337]*workYaw.d[472]*workYaw.L[337];
  residual += temp*temp;
  temp = workYaw.KKT[836]-1*workYaw.d[419]*1;
  residual += temp*temp;
  temp = workYaw.KKT[968]-1*workYaw.d[476]*1-workYaw.L[347]*workYaw.d[168]*workYaw.L[347]-workYaw.L[348]*workYaw.d[208]*workYaw.L[348]-workYaw.L[349]*workYaw.d[475]*workYaw.L[349];
  residual += temp*temp;
  temp = workYaw.KKT[971]-1*workYaw.d[477]*1-workYaw.L[350]*workYaw.d[248]*workYaw.L[350]-workYaw.L[351]*workYaw.d[288]*workYaw.L[351]-workYaw.L[352]*workYaw.d[377]*workYaw.L[352]-workYaw.L[353]*workYaw.d[378]*workYaw.L[353]-workYaw.L[354]*workYaw.d[473]*workYaw.L[354]-workYaw.L[356]*workYaw.d[475]*workYaw.L[356]-workYaw.L[355]*workYaw.d[474]*workYaw.L[355]-workYaw.L[357]*workYaw.d[476]*workYaw.L[357];
  residual += temp*temp;
  temp = workYaw.KKT[839]-1*workYaw.d[420]*1;
  residual += temp*temp;
  temp = workYaw.KKT[974]-1*workYaw.d[480]*1-workYaw.L[367]*workYaw.d[169]*workYaw.L[367]-workYaw.L[368]*workYaw.d[209]*workYaw.L[368]-workYaw.L[369]*workYaw.d[479]*workYaw.L[369];
  residual += temp*temp;
  temp = workYaw.KKT[977]-1*workYaw.d[481]*1-workYaw.L[370]*workYaw.d[249]*workYaw.L[370]-workYaw.L[371]*workYaw.d[289]*workYaw.L[371]-workYaw.L[372]*workYaw.d[378]*workYaw.L[372]-workYaw.L[373]*workYaw.d[379]*workYaw.L[373]-workYaw.L[374]*workYaw.d[477]*workYaw.L[374]-workYaw.L[376]*workYaw.d[479]*workYaw.L[376]-workYaw.L[375]*workYaw.d[478]*workYaw.L[375]-workYaw.L[377]*workYaw.d[480]*workYaw.L[377];
  residual += temp*temp;
  temp = workYaw.KKT[842]-1*workYaw.d[421]*1;
  residual += temp*temp;
  temp = workYaw.KKT[980]-1*workYaw.d[484]*1-workYaw.L[387]*workYaw.d[170]*workYaw.L[387]-workYaw.L[388]*workYaw.d[210]*workYaw.L[388]-workYaw.L[389]*workYaw.d[483]*workYaw.L[389];
  residual += temp*temp;
  temp = workYaw.KKT[983]-1*workYaw.d[485]*1-workYaw.L[390]*workYaw.d[250]*workYaw.L[390]-workYaw.L[391]*workYaw.d[290]*workYaw.L[391]-workYaw.L[392]*workYaw.d[379]*workYaw.L[392]-workYaw.L[393]*workYaw.d[380]*workYaw.L[393]-workYaw.L[394]*workYaw.d[481]*workYaw.L[394]-workYaw.L[396]*workYaw.d[483]*workYaw.L[396]-workYaw.L[395]*workYaw.d[482]*workYaw.L[395]-workYaw.L[397]*workYaw.d[484]*workYaw.L[397];
  residual += temp*temp;
  temp = workYaw.KKT[845]-1*workYaw.d[422]*1;
  residual += temp*temp;
  temp = workYaw.KKT[986]-1*workYaw.d[488]*1-workYaw.L[407]*workYaw.d[171]*workYaw.L[407]-workYaw.L[408]*workYaw.d[211]*workYaw.L[408]-workYaw.L[409]*workYaw.d[487]*workYaw.L[409];
  residual += temp*temp;
  temp = workYaw.KKT[989]-1*workYaw.d[489]*1-workYaw.L[410]*workYaw.d[251]*workYaw.L[410]-workYaw.L[411]*workYaw.d[291]*workYaw.L[411]-workYaw.L[412]*workYaw.d[380]*workYaw.L[412]-workYaw.L[413]*workYaw.d[381]*workYaw.L[413]-workYaw.L[414]*workYaw.d[485]*workYaw.L[414]-workYaw.L[416]*workYaw.d[487]*workYaw.L[416]-workYaw.L[415]*workYaw.d[486]*workYaw.L[415]-workYaw.L[417]*workYaw.d[488]*workYaw.L[417];
  residual += temp*temp;
  temp = workYaw.KKT[848]-1*workYaw.d[423]*1;
  residual += temp*temp;
  temp = workYaw.KKT[992]-1*workYaw.d[492]*1-workYaw.L[427]*workYaw.d[172]*workYaw.L[427]-workYaw.L[428]*workYaw.d[212]*workYaw.L[428]-workYaw.L[429]*workYaw.d[491]*workYaw.L[429];
  residual += temp*temp;
  temp = workYaw.KKT[995]-1*workYaw.d[493]*1-workYaw.L[430]*workYaw.d[252]*workYaw.L[430]-workYaw.L[431]*workYaw.d[292]*workYaw.L[431]-workYaw.L[432]*workYaw.d[381]*workYaw.L[432]-workYaw.L[433]*workYaw.d[382]*workYaw.L[433]-workYaw.L[434]*workYaw.d[489]*workYaw.L[434]-workYaw.L[436]*workYaw.d[491]*workYaw.L[436]-workYaw.L[435]*workYaw.d[490]*workYaw.L[435]-workYaw.L[437]*workYaw.d[492]*workYaw.L[437];
  residual += temp*temp;
  temp = workYaw.KKT[851]-1*workYaw.d[424]*1;
  residual += temp*temp;
  temp = workYaw.KKT[998]-1*workYaw.d[496]*1-workYaw.L[447]*workYaw.d[173]*workYaw.L[447]-workYaw.L[448]*workYaw.d[213]*workYaw.L[448]-workYaw.L[449]*workYaw.d[495]*workYaw.L[449];
  residual += temp*temp;
  temp = workYaw.KKT[1001]-1*workYaw.d[497]*1-workYaw.L[450]*workYaw.d[253]*workYaw.L[450]-workYaw.L[451]*workYaw.d[293]*workYaw.L[451]-workYaw.L[452]*workYaw.d[382]*workYaw.L[452]-workYaw.L[453]*workYaw.d[383]*workYaw.L[453]-workYaw.L[454]*workYaw.d[493]*workYaw.L[454]-workYaw.L[456]*workYaw.d[495]*workYaw.L[456]-workYaw.L[455]*workYaw.d[494]*workYaw.L[455]-workYaw.L[457]*workYaw.d[496]*workYaw.L[457];
  residual += temp*temp;
  temp = workYaw.KKT[854]-1*workYaw.d[425]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1004]-1*workYaw.d[500]*1-workYaw.L[467]*workYaw.d[174]*workYaw.L[467]-workYaw.L[468]*workYaw.d[214]*workYaw.L[468]-workYaw.L[469]*workYaw.d[499]*workYaw.L[469];
  residual += temp*temp;
  temp = workYaw.KKT[1007]-1*workYaw.d[501]*1-workYaw.L[470]*workYaw.d[254]*workYaw.L[470]-workYaw.L[471]*workYaw.d[294]*workYaw.L[471]-workYaw.L[472]*workYaw.d[383]*workYaw.L[472]-workYaw.L[473]*workYaw.d[384]*workYaw.L[473]-workYaw.L[474]*workYaw.d[497]*workYaw.L[474]-workYaw.L[476]*workYaw.d[499]*workYaw.L[476]-workYaw.L[475]*workYaw.d[498]*workYaw.L[475]-workYaw.L[477]*workYaw.d[500]*workYaw.L[477];
  residual += temp*temp;
  temp = workYaw.KKT[857]-1*workYaw.d[426]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1010]-1*workYaw.d[504]*1-workYaw.L[487]*workYaw.d[175]*workYaw.L[487]-workYaw.L[488]*workYaw.d[215]*workYaw.L[488]-workYaw.L[489]*workYaw.d[503]*workYaw.L[489];
  residual += temp*temp;
  temp = workYaw.KKT[1013]-1*workYaw.d[505]*1-workYaw.L[490]*workYaw.d[255]*workYaw.L[490]-workYaw.L[491]*workYaw.d[295]*workYaw.L[491]-workYaw.L[492]*workYaw.d[384]*workYaw.L[492]-workYaw.L[493]*workYaw.d[385]*workYaw.L[493]-workYaw.L[494]*workYaw.d[501]*workYaw.L[494]-workYaw.L[496]*workYaw.d[503]*workYaw.L[496]-workYaw.L[495]*workYaw.d[502]*workYaw.L[495]-workYaw.L[497]*workYaw.d[504]*workYaw.L[497];
  residual += temp*temp;
  temp = workYaw.KKT[860]-1*workYaw.d[427]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1016]-1*workYaw.d[508]*1-workYaw.L[507]*workYaw.d[176]*workYaw.L[507]-workYaw.L[508]*workYaw.d[216]*workYaw.L[508]-workYaw.L[509]*workYaw.d[507]*workYaw.L[509];
  residual += temp*temp;
  temp = workYaw.KKT[1019]-1*workYaw.d[509]*1-workYaw.L[510]*workYaw.d[256]*workYaw.L[510]-workYaw.L[511]*workYaw.d[296]*workYaw.L[511]-workYaw.L[512]*workYaw.d[385]*workYaw.L[512]-workYaw.L[513]*workYaw.d[386]*workYaw.L[513]-workYaw.L[514]*workYaw.d[505]*workYaw.L[514]-workYaw.L[516]*workYaw.d[507]*workYaw.L[516]-workYaw.L[515]*workYaw.d[506]*workYaw.L[515]-workYaw.L[517]*workYaw.d[508]*workYaw.L[517];
  residual += temp*temp;
  temp = workYaw.KKT[863]-1*workYaw.d[428]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1022]-1*workYaw.d[512]*1-workYaw.L[527]*workYaw.d[177]*workYaw.L[527]-workYaw.L[528]*workYaw.d[217]*workYaw.L[528]-workYaw.L[529]*workYaw.d[511]*workYaw.L[529];
  residual += temp*temp;
  temp = workYaw.KKT[1025]-1*workYaw.d[513]*1-workYaw.L[530]*workYaw.d[257]*workYaw.L[530]-workYaw.L[531]*workYaw.d[297]*workYaw.L[531]-workYaw.L[532]*workYaw.d[386]*workYaw.L[532]-workYaw.L[533]*workYaw.d[387]*workYaw.L[533]-workYaw.L[534]*workYaw.d[509]*workYaw.L[534]-workYaw.L[536]*workYaw.d[511]*workYaw.L[536]-workYaw.L[535]*workYaw.d[510]*workYaw.L[535]-workYaw.L[537]*workYaw.d[512]*workYaw.L[537];
  residual += temp*temp;
  temp = workYaw.KKT[866]-1*workYaw.d[429]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1028]-1*workYaw.d[516]*1-workYaw.L[547]*workYaw.d[178]*workYaw.L[547]-workYaw.L[548]*workYaw.d[218]*workYaw.L[548]-workYaw.L[549]*workYaw.d[515]*workYaw.L[549];
  residual += temp*temp;
  temp = workYaw.KKT[1031]-1*workYaw.d[517]*1-workYaw.L[550]*workYaw.d[258]*workYaw.L[550]-workYaw.L[551]*workYaw.d[298]*workYaw.L[551]-workYaw.L[552]*workYaw.d[387]*workYaw.L[552]-workYaw.L[553]*workYaw.d[388]*workYaw.L[553]-workYaw.L[554]*workYaw.d[513]*workYaw.L[554]-workYaw.L[556]*workYaw.d[515]*workYaw.L[556]-workYaw.L[555]*workYaw.d[514]*workYaw.L[555]-workYaw.L[557]*workYaw.d[516]*workYaw.L[557];
  residual += temp*temp;
  temp = workYaw.KKT[869]-1*workYaw.d[430]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1034]-1*workYaw.d[520]*1-workYaw.L[567]*workYaw.d[179]*workYaw.L[567]-workYaw.L[568]*workYaw.d[219]*workYaw.L[568]-workYaw.L[569]*workYaw.d[519]*workYaw.L[569];
  residual += temp*temp;
  temp = workYaw.KKT[1037]-1*workYaw.d[521]*1-workYaw.L[570]*workYaw.d[259]*workYaw.L[570]-workYaw.L[571]*workYaw.d[299]*workYaw.L[571]-workYaw.L[572]*workYaw.d[388]*workYaw.L[572]-workYaw.L[573]*workYaw.d[389]*workYaw.L[573]-workYaw.L[574]*workYaw.d[517]*workYaw.L[574]-workYaw.L[576]*workYaw.d[519]*workYaw.L[576]-workYaw.L[575]*workYaw.d[518]*workYaw.L[575]-workYaw.L[577]*workYaw.d[520]*workYaw.L[577];
  residual += temp*temp;
  temp = workYaw.KKT[872]-1*workYaw.d[431]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1040]-1*workYaw.d[524]*1-workYaw.L[587]*workYaw.d[180]*workYaw.L[587]-workYaw.L[588]*workYaw.d[220]*workYaw.L[588]-workYaw.L[589]*workYaw.d[523]*workYaw.L[589];
  residual += temp*temp;
  temp = workYaw.KKT[1043]-1*workYaw.d[525]*1-workYaw.L[590]*workYaw.d[260]*workYaw.L[590]-workYaw.L[591]*workYaw.d[300]*workYaw.L[591]-workYaw.L[592]*workYaw.d[389]*workYaw.L[592]-workYaw.L[593]*workYaw.d[390]*workYaw.L[593]-workYaw.L[594]*workYaw.d[521]*workYaw.L[594]-workYaw.L[596]*workYaw.d[523]*workYaw.L[596]-workYaw.L[595]*workYaw.d[522]*workYaw.L[595]-workYaw.L[597]*workYaw.d[524]*workYaw.L[597];
  residual += temp*temp;
  temp = workYaw.KKT[875]-1*workYaw.d[432]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1046]-1*workYaw.d[528]*1-workYaw.L[607]*workYaw.d[181]*workYaw.L[607]-workYaw.L[608]*workYaw.d[221]*workYaw.L[608]-workYaw.L[609]*workYaw.d[527]*workYaw.L[609];
  residual += temp*temp;
  temp = workYaw.KKT[1049]-1*workYaw.d[529]*1-workYaw.L[610]*workYaw.d[261]*workYaw.L[610]-workYaw.L[611]*workYaw.d[301]*workYaw.L[611]-workYaw.L[612]*workYaw.d[390]*workYaw.L[612]-workYaw.L[613]*workYaw.d[391]*workYaw.L[613]-workYaw.L[614]*workYaw.d[525]*workYaw.L[614]-workYaw.L[616]*workYaw.d[527]*workYaw.L[616]-workYaw.L[615]*workYaw.d[526]*workYaw.L[615]-workYaw.L[617]*workYaw.d[528]*workYaw.L[617];
  residual += temp*temp;
  temp = workYaw.KKT[878]-1*workYaw.d[433]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1052]-1*workYaw.d[532]*1-workYaw.L[627]*workYaw.d[182]*workYaw.L[627]-workYaw.L[628]*workYaw.d[222]*workYaw.L[628]-workYaw.L[629]*workYaw.d[531]*workYaw.L[629];
  residual += temp*temp;
  temp = workYaw.KKT[1055]-1*workYaw.d[533]*1-workYaw.L[630]*workYaw.d[262]*workYaw.L[630]-workYaw.L[631]*workYaw.d[302]*workYaw.L[631]-workYaw.L[632]*workYaw.d[391]*workYaw.L[632]-workYaw.L[633]*workYaw.d[392]*workYaw.L[633]-workYaw.L[634]*workYaw.d[529]*workYaw.L[634]-workYaw.L[636]*workYaw.d[531]*workYaw.L[636]-workYaw.L[635]*workYaw.d[530]*workYaw.L[635]-workYaw.L[637]*workYaw.d[532]*workYaw.L[637];
  residual += temp*temp;
  temp = workYaw.KKT[881]-1*workYaw.d[434]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1058]-1*workYaw.d[536]*1-workYaw.L[647]*workYaw.d[183]*workYaw.L[647]-workYaw.L[648]*workYaw.d[223]*workYaw.L[648]-workYaw.L[649]*workYaw.d[535]*workYaw.L[649];
  residual += temp*temp;
  temp = workYaw.KKT[1061]-1*workYaw.d[537]*1-workYaw.L[650]*workYaw.d[263]*workYaw.L[650]-workYaw.L[651]*workYaw.d[303]*workYaw.L[651]-workYaw.L[652]*workYaw.d[392]*workYaw.L[652]-workYaw.L[653]*workYaw.d[393]*workYaw.L[653]-workYaw.L[654]*workYaw.d[533]*workYaw.L[654]-workYaw.L[656]*workYaw.d[535]*workYaw.L[656]-workYaw.L[655]*workYaw.d[534]*workYaw.L[655]-workYaw.L[657]*workYaw.d[536]*workYaw.L[657];
  residual += temp*temp;
  temp = workYaw.KKT[884]-1*workYaw.d[435]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1064]-1*workYaw.d[540]*1-workYaw.L[667]*workYaw.d[184]*workYaw.L[667]-workYaw.L[668]*workYaw.d[224]*workYaw.L[668]-workYaw.L[669]*workYaw.d[539]*workYaw.L[669];
  residual += temp*temp;
  temp = workYaw.KKT[1067]-1*workYaw.d[541]*1-workYaw.L[670]*workYaw.d[264]*workYaw.L[670]-workYaw.L[671]*workYaw.d[304]*workYaw.L[671]-workYaw.L[672]*workYaw.d[393]*workYaw.L[672]-workYaw.L[673]*workYaw.d[394]*workYaw.L[673]-workYaw.L[674]*workYaw.d[537]*workYaw.L[674]-workYaw.L[676]*workYaw.d[539]*workYaw.L[676]-workYaw.L[675]*workYaw.d[538]*workYaw.L[675]-workYaw.L[677]*workYaw.d[540]*workYaw.L[677];
  residual += temp*temp;
  temp = workYaw.KKT[887]-1*workYaw.d[436]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1070]-1*workYaw.d[544]*1-workYaw.L[687]*workYaw.d[185]*workYaw.L[687]-workYaw.L[688]*workYaw.d[225]*workYaw.L[688]-workYaw.L[689]*workYaw.d[543]*workYaw.L[689];
  residual += temp*temp;
  temp = workYaw.KKT[1073]-1*workYaw.d[545]*1-workYaw.L[690]*workYaw.d[265]*workYaw.L[690]-workYaw.L[691]*workYaw.d[305]*workYaw.L[691]-workYaw.L[692]*workYaw.d[394]*workYaw.L[692]-workYaw.L[693]*workYaw.d[395]*workYaw.L[693]-workYaw.L[694]*workYaw.d[541]*workYaw.L[694]-workYaw.L[696]*workYaw.d[543]*workYaw.L[696]-workYaw.L[695]*workYaw.d[542]*workYaw.L[695]-workYaw.L[697]*workYaw.d[544]*workYaw.L[697];
  residual += temp*temp;
  temp = workYaw.KKT[890]-1*workYaw.d[437]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1076]-1*workYaw.d[548]*1-workYaw.L[707]*workYaw.d[186]*workYaw.L[707]-workYaw.L[708]*workYaw.d[226]*workYaw.L[708]-workYaw.L[709]*workYaw.d[547]*workYaw.L[709];
  residual += temp*temp;
  temp = workYaw.KKT[1079]-1*workYaw.d[549]*1-workYaw.L[710]*workYaw.d[266]*workYaw.L[710]-workYaw.L[711]*workYaw.d[306]*workYaw.L[711]-workYaw.L[712]*workYaw.d[395]*workYaw.L[712]-workYaw.L[713]*workYaw.d[396]*workYaw.L[713]-workYaw.L[714]*workYaw.d[545]*workYaw.L[714]-workYaw.L[716]*workYaw.d[547]*workYaw.L[716]-workYaw.L[715]*workYaw.d[546]*workYaw.L[715]-workYaw.L[717]*workYaw.d[548]*workYaw.L[717];
  residual += temp*temp;
  temp = workYaw.KKT[893]-1*workYaw.d[438]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1082]-1*workYaw.d[552]*1-workYaw.L[727]*workYaw.d[187]*workYaw.L[727]-workYaw.L[728]*workYaw.d[227]*workYaw.L[728]-workYaw.L[729]*workYaw.d[551]*workYaw.L[729];
  residual += temp*temp;
  temp = workYaw.KKT[1085]-1*workYaw.d[553]*1-workYaw.L[730]*workYaw.d[267]*workYaw.L[730]-workYaw.L[731]*workYaw.d[307]*workYaw.L[731]-workYaw.L[732]*workYaw.d[396]*workYaw.L[732]-workYaw.L[733]*workYaw.d[397]*workYaw.L[733]-workYaw.L[734]*workYaw.d[549]*workYaw.L[734]-workYaw.L[736]*workYaw.d[551]*workYaw.L[736]-workYaw.L[735]*workYaw.d[550]*workYaw.L[735]-workYaw.L[737]*workYaw.d[552]*workYaw.L[737];
  residual += temp*temp;
  temp = workYaw.KKT[896]-1*workYaw.d[439]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1088]-1*workYaw.d[556]*1-workYaw.L[747]*workYaw.d[188]*workYaw.L[747]-workYaw.L[748]*workYaw.d[228]*workYaw.L[748]-workYaw.L[749]*workYaw.d[555]*workYaw.L[749];
  residual += temp*temp;
  temp = workYaw.KKT[1091]-1*workYaw.d[557]*1-workYaw.L[750]*workYaw.d[268]*workYaw.L[750]-workYaw.L[751]*workYaw.d[308]*workYaw.L[751]-workYaw.L[752]*workYaw.d[397]*workYaw.L[752]-workYaw.L[753]*workYaw.d[398]*workYaw.L[753]-workYaw.L[754]*workYaw.d[553]*workYaw.L[754]-workYaw.L[756]*workYaw.d[555]*workYaw.L[756]-workYaw.L[755]*workYaw.d[554]*workYaw.L[755]-workYaw.L[757]*workYaw.d[556]*workYaw.L[757];
  residual += temp*temp;
  temp = workYaw.KKT[899]-1*workYaw.d[440]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1094]-1*workYaw.d[560]*1-workYaw.L[767]*workYaw.d[189]*workYaw.L[767]-workYaw.L[768]*workYaw.d[229]*workYaw.L[768]-workYaw.L[769]*workYaw.d[559]*workYaw.L[769];
  residual += temp*temp;
  temp = workYaw.KKT[1097]-1*workYaw.d[561]*1-workYaw.L[770]*workYaw.d[269]*workYaw.L[770]-workYaw.L[771]*workYaw.d[309]*workYaw.L[771]-workYaw.L[772]*workYaw.d[398]*workYaw.L[772]-workYaw.L[773]*workYaw.d[399]*workYaw.L[773]-workYaw.L[774]*workYaw.d[557]*workYaw.L[774]-workYaw.L[776]*workYaw.d[559]*workYaw.L[776]-workYaw.L[775]*workYaw.d[558]*workYaw.L[775]-workYaw.L[777]*workYaw.d[560]*workYaw.L[777];
  residual += temp*temp;
  temp = workYaw.KKT[902]-1*workYaw.d[441]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1100]-1*workYaw.d[564]*1-workYaw.L[787]*workYaw.d[190]*workYaw.L[787]-workYaw.L[788]*workYaw.d[230]*workYaw.L[788]-workYaw.L[789]*workYaw.d[563]*workYaw.L[789];
  residual += temp*temp;
  temp = workYaw.KKT[1103]-1*workYaw.d[565]*1-workYaw.L[790]*workYaw.d[270]*workYaw.L[790]-workYaw.L[791]*workYaw.d[310]*workYaw.L[791]-workYaw.L[792]*workYaw.d[399]*workYaw.L[792]-workYaw.L[793]*workYaw.d[400]*workYaw.L[793]-workYaw.L[794]*workYaw.d[561]*workYaw.L[794]-workYaw.L[796]*workYaw.d[563]*workYaw.L[796]-workYaw.L[795]*workYaw.d[562]*workYaw.L[795]-workYaw.L[797]*workYaw.d[564]*workYaw.L[797];
  residual += temp*temp;
  temp = workYaw.KKT[905]-1*workYaw.d[442]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1106]-1*workYaw.d[568]*1-workYaw.L[807]*workYaw.d[191]*workYaw.L[807]-workYaw.L[808]*workYaw.d[231]*workYaw.L[808]-workYaw.L[809]*workYaw.d[567]*workYaw.L[809];
  residual += temp*temp;
  temp = workYaw.KKT[1109]-1*workYaw.d[569]*1-workYaw.L[810]*workYaw.d[271]*workYaw.L[810]-workYaw.L[811]*workYaw.d[311]*workYaw.L[811]-workYaw.L[812]*workYaw.d[400]*workYaw.L[812]-workYaw.L[813]*workYaw.d[401]*workYaw.L[813]-workYaw.L[814]*workYaw.d[565]*workYaw.L[814]-workYaw.L[816]*workYaw.d[567]*workYaw.L[816]-workYaw.L[815]*workYaw.d[566]*workYaw.L[815]-workYaw.L[817]*workYaw.d[568]*workYaw.L[817];
  residual += temp*temp;
  temp = workYaw.KKT[908]-1*workYaw.d[443]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1112]-1*workYaw.d[572]*1-workYaw.L[827]*workYaw.d[192]*workYaw.L[827]-workYaw.L[828]*workYaw.d[232]*workYaw.L[828]-workYaw.L[829]*workYaw.d[571]*workYaw.L[829];
  residual += temp*temp;
  temp = workYaw.KKT[1115]-1*workYaw.d[573]*1-workYaw.L[830]*workYaw.d[272]*workYaw.L[830]-workYaw.L[831]*workYaw.d[312]*workYaw.L[831]-workYaw.L[832]*workYaw.d[401]*workYaw.L[832]-workYaw.L[833]*workYaw.d[402]*workYaw.L[833]-workYaw.L[834]*workYaw.d[569]*workYaw.L[834]-workYaw.L[836]*workYaw.d[571]*workYaw.L[836]-workYaw.L[835]*workYaw.d[570]*workYaw.L[835]-workYaw.L[837]*workYaw.d[572]*workYaw.L[837];
  residual += temp*temp;
  temp = workYaw.KKT[911]-1*workYaw.d[444]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1118]-1*workYaw.d[576]*1-workYaw.L[847]*workYaw.d[193]*workYaw.L[847]-workYaw.L[848]*workYaw.d[233]*workYaw.L[848]-workYaw.L[849]*workYaw.d[575]*workYaw.L[849];
  residual += temp*temp;
  temp = workYaw.KKT[1121]-1*workYaw.d[577]*1-workYaw.L[850]*workYaw.d[273]*workYaw.L[850]-workYaw.L[851]*workYaw.d[313]*workYaw.L[851]-workYaw.L[852]*workYaw.d[402]*workYaw.L[852]-workYaw.L[853]*workYaw.d[403]*workYaw.L[853]-workYaw.L[854]*workYaw.d[573]*workYaw.L[854]-workYaw.L[856]*workYaw.d[575]*workYaw.L[856]-workYaw.L[855]*workYaw.d[574]*workYaw.L[855]-workYaw.L[857]*workYaw.d[576]*workYaw.L[857];
  residual += temp*temp;
  temp = workYaw.KKT[914]-1*workYaw.d[445]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1124]-1*workYaw.d[580]*1-workYaw.L[867]*workYaw.d[194]*workYaw.L[867]-workYaw.L[868]*workYaw.d[234]*workYaw.L[868]-workYaw.L[869]*workYaw.d[579]*workYaw.L[869];
  residual += temp*temp;
  temp = workYaw.KKT[1127]-1*workYaw.d[581]*1-workYaw.L[870]*workYaw.d[274]*workYaw.L[870]-workYaw.L[871]*workYaw.d[314]*workYaw.L[871]-workYaw.L[872]*workYaw.d[403]*workYaw.L[872]-workYaw.L[873]*workYaw.d[404]*workYaw.L[873]-workYaw.L[874]*workYaw.d[577]*workYaw.L[874]-workYaw.L[876]*workYaw.d[579]*workYaw.L[876]-workYaw.L[875]*workYaw.d[578]*workYaw.L[875]-workYaw.L[877]*workYaw.d[580]*workYaw.L[877];
  residual += temp*temp;
  temp = workYaw.KKT[917]-1*workYaw.d[446]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1130]-1*workYaw.d[584]*1-workYaw.L[887]*workYaw.d[195]*workYaw.L[887]-workYaw.L[888]*workYaw.d[235]*workYaw.L[888]-workYaw.L[889]*workYaw.d[583]*workYaw.L[889];
  residual += temp*temp;
  temp = workYaw.KKT[1133]-1*workYaw.d[585]*1-workYaw.L[890]*workYaw.d[275]*workYaw.L[890]-workYaw.L[891]*workYaw.d[315]*workYaw.L[891]-workYaw.L[892]*workYaw.d[404]*workYaw.L[892]-workYaw.L[893]*workYaw.d[405]*workYaw.L[893]-workYaw.L[894]*workYaw.d[581]*workYaw.L[894]-workYaw.L[896]*workYaw.d[583]*workYaw.L[896]-workYaw.L[895]*workYaw.d[582]*workYaw.L[895]-workYaw.L[897]*workYaw.d[584]*workYaw.L[897];
  residual += temp*temp;
  temp = workYaw.KKT[920]-1*workYaw.d[447]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1136]-1*workYaw.d[588]*1-workYaw.L[907]*workYaw.d[196]*workYaw.L[907]-workYaw.L[908]*workYaw.d[236]*workYaw.L[908]-workYaw.L[909]*workYaw.d[587]*workYaw.L[909];
  residual += temp*temp;
  temp = workYaw.KKT[1139]-1*workYaw.d[589]*1-workYaw.L[910]*workYaw.d[276]*workYaw.L[910]-workYaw.L[911]*workYaw.d[316]*workYaw.L[911]-workYaw.L[912]*workYaw.d[405]*workYaw.L[912]-workYaw.L[913]*workYaw.d[406]*workYaw.L[913]-workYaw.L[914]*workYaw.d[585]*workYaw.L[914]-workYaw.L[916]*workYaw.d[587]*workYaw.L[916]-workYaw.L[915]*workYaw.d[586]*workYaw.L[915]-workYaw.L[917]*workYaw.d[588]*workYaw.L[917];
  residual += temp*temp;
  temp = workYaw.KKT[923]-1*workYaw.d[448]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1142]-1*workYaw.d[592]*1-workYaw.L[927]*workYaw.d[197]*workYaw.L[927]-workYaw.L[928]*workYaw.d[237]*workYaw.L[928]-workYaw.L[929]*workYaw.d[591]*workYaw.L[929];
  residual += temp*temp;
  temp = workYaw.KKT[1145]-1*workYaw.d[593]*1-workYaw.L[930]*workYaw.d[277]*workYaw.L[930]-workYaw.L[931]*workYaw.d[317]*workYaw.L[931]-workYaw.L[932]*workYaw.d[406]*workYaw.L[932]-workYaw.L[933]*workYaw.d[407]*workYaw.L[933]-workYaw.L[934]*workYaw.d[589]*workYaw.L[934]-workYaw.L[936]*workYaw.d[591]*workYaw.L[936]-workYaw.L[935]*workYaw.d[590]*workYaw.L[935]-workYaw.L[937]*workYaw.d[592]*workYaw.L[937];
  residual += temp*temp;
  temp = workYaw.KKT[926]-1*workYaw.d[449]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1152]-1*workYaw.d[598]*1-workYaw.L[951]*workYaw.d[198]*workYaw.L[951]-workYaw.L[952]*workYaw.d[238]*workYaw.L[952]-workYaw.L[953]*workYaw.d[595]*workYaw.L[953]-workYaw.L[955]*workYaw.d[597]*workYaw.L[955]-workYaw.L[954]*workYaw.d[596]*workYaw.L[954];
  residual += temp*temp;
  temp = workYaw.KKT[1153]-1*workYaw.d[599]*1-workYaw.L[956]*workYaw.d[278]*workYaw.L[956]-workYaw.L[957]*workYaw.d[318]*workYaw.L[957]-workYaw.L[958]*workYaw.d[407]*workYaw.L[958]-workYaw.L[959]*workYaw.d[408]*workYaw.L[959]-workYaw.L[965]*workYaw.d[597]*workYaw.L[965]-workYaw.L[961]*workYaw.d[593]*workYaw.L[961]-workYaw.L[960]*workYaw.d[410]*workYaw.L[960]-workYaw.L[963]*workYaw.d[595]*workYaw.L[963]-workYaw.L[962]*workYaw.d[594]*workYaw.L[962]-workYaw.L[964]*workYaw.d[596]*workYaw.L[964]-workYaw.L[966]*workYaw.d[598]*workYaw.L[966];
  residual += temp*temp;
  temp = workYaw.KKT[929]-1*workYaw.d[450]*1-workYaw.L[225]*workYaw.d[409]*workYaw.L[225];
  residual += temp*temp;
  temp = workYaw.KKT[1154]-1*workYaw.d[600]*1-workYaw.L[967]*workYaw.d[199]*workYaw.L[967]-workYaw.L[968]*workYaw.d[239]*workYaw.L[968]-workYaw.L[973]*workYaw.d[597]*workYaw.L[973]-workYaw.L[970]*workYaw.d[410]*workYaw.L[970]-workYaw.L[969]*workYaw.d[409]*workYaw.L[969]-workYaw.L[971]*workYaw.d[450]*workYaw.L[971]-workYaw.L[975]*workYaw.d[599]*workYaw.L[975]-workYaw.L[972]*workYaw.d[596]*workYaw.L[972]-workYaw.L[974]*workYaw.d[598]*workYaw.L[974];
  residual += temp*temp;
  temp = workYaw.KKT[732]-1*workYaw.d[369]*1-workYaw.L[168]*workYaw.d[279]*workYaw.L[168]-workYaw.L[169]*workYaw.d[319]*workYaw.L[169]-workYaw.L[170]*workYaw.d[365]*workYaw.L[170];
  residual += temp*temp;
  temp = workYaw.KKT[728]-1*workYaw.d[367]*1;
  residual += temp*temp;
  temp = workYaw.KKT[730]-1*workYaw.d[368]*1-workYaw.L[166]*workYaw.d[200]*workYaw.L[166]-workYaw.L[167]*workYaw.d[240]*workYaw.L[167];
  residual += temp*temp;
  temp = workYaw.KKT[723]-1*workYaw.d[364]*1-workYaw.L[161]*workYaw.d[280]*workYaw.L[161]-workYaw.L[162]*workYaw.d[320]*workYaw.L[162];
  residual += temp*temp;
  temp = workYaw.KKT[1]-1*workYaw.d[1]*1;
  residual += temp*temp;
  temp = workYaw.KKT[3]-1*workYaw.d[2]*1;
  residual += temp*temp;
  temp = workYaw.KKT[5]-1*workYaw.d[3]*1;
  residual += temp*temp;
  temp = workYaw.KKT[7]-1*workYaw.d[4]*1;
  residual += temp*temp;
  temp = workYaw.KKT[9]-1*workYaw.d[5]*1;
  residual += temp*temp;
  temp = workYaw.KKT[11]-1*workYaw.d[6]*1;
  residual += temp*temp;
  temp = workYaw.KKT[13]-1*workYaw.d[7]*1;
  residual += temp*temp;
  temp = workYaw.KKT[15]-1*workYaw.d[8]*1;
  residual += temp*temp;
  temp = workYaw.KKT[17]-1*workYaw.d[9]*1;
  residual += temp*temp;
  temp = workYaw.KKT[19]-1*workYaw.d[10]*1;
  residual += temp*temp;
  temp = workYaw.KKT[21]-1*workYaw.d[11]*1;
  residual += temp*temp;
  temp = workYaw.KKT[23]-1*workYaw.d[12]*1;
  residual += temp*temp;
  temp = workYaw.KKT[25]-1*workYaw.d[13]*1;
  residual += temp*temp;
  temp = workYaw.KKT[27]-1*workYaw.d[14]*1;
  residual += temp*temp;
  temp = workYaw.KKT[29]-1*workYaw.d[15]*1;
  residual += temp*temp;
  temp = workYaw.KKT[31]-1*workYaw.d[16]*1;
  residual += temp*temp;
  temp = workYaw.KKT[33]-1*workYaw.d[17]*1;
  residual += temp*temp;
  temp = workYaw.KKT[35]-1*workYaw.d[18]*1;
  residual += temp*temp;
  temp = workYaw.KKT[37]-1*workYaw.d[19]*1;
  residual += temp*temp;
  temp = workYaw.KKT[39]-1*workYaw.d[20]*1;
  residual += temp*temp;
  temp = workYaw.KKT[41]-1*workYaw.d[21]*1;
  residual += temp*temp;
  temp = workYaw.KKT[43]-1*workYaw.d[22]*1;
  residual += temp*temp;
  temp = workYaw.KKT[45]-1*workYaw.d[23]*1;
  residual += temp*temp;
  temp = workYaw.KKT[47]-1*workYaw.d[24]*1;
  residual += temp*temp;
  temp = workYaw.KKT[49]-1*workYaw.d[25]*1;
  residual += temp*temp;
  temp = workYaw.KKT[51]-1*workYaw.d[26]*1;
  residual += temp*temp;
  temp = workYaw.KKT[53]-1*workYaw.d[27]*1;
  residual += temp*temp;
  temp = workYaw.KKT[55]-1*workYaw.d[28]*1;
  residual += temp*temp;
  temp = workYaw.KKT[57]-1*workYaw.d[29]*1;
  residual += temp*temp;
  temp = workYaw.KKT[59]-1*workYaw.d[30]*1;
  residual += temp*temp;
  temp = workYaw.KKT[61]-1*workYaw.d[31]*1;
  residual += temp*temp;
  temp = workYaw.KKT[63]-1*workYaw.d[32]*1;
  residual += temp*temp;
  temp = workYaw.KKT[65]-1*workYaw.d[33]*1;
  residual += temp*temp;
  temp = workYaw.KKT[67]-1*workYaw.d[34]*1;
  residual += temp*temp;
  temp = workYaw.KKT[69]-1*workYaw.d[35]*1;
  residual += temp*temp;
  temp = workYaw.KKT[71]-1*workYaw.d[36]*1;
  residual += temp*temp;
  temp = workYaw.KKT[73]-1*workYaw.d[37]*1;
  residual += temp*temp;
  temp = workYaw.KKT[75]-1*workYaw.d[38]*1;
  residual += temp*temp;
  temp = workYaw.KKT[77]-1*workYaw.d[39]*1;
  residual += temp*temp;
  temp = workYaw.KKT[79]-1*workYaw.d[40]*1;
  residual += temp*temp;
  temp = workYaw.KKT[81]-1*workYaw.d[41]*1;
  residual += temp*temp;
  temp = workYaw.KKT[83]-1*workYaw.d[42]*1;
  residual += temp*temp;
  temp = workYaw.KKT[85]-1*workYaw.d[43]*1;
  residual += temp*temp;
  temp = workYaw.KKT[87]-1*workYaw.d[44]*1;
  residual += temp*temp;
  temp = workYaw.KKT[89]-1*workYaw.d[45]*1;
  residual += temp*temp;
  temp = workYaw.KKT[91]-1*workYaw.d[46]*1;
  residual += temp*temp;
  temp = workYaw.KKT[93]-1*workYaw.d[47]*1;
  residual += temp*temp;
  temp = workYaw.KKT[95]-1*workYaw.d[48]*1;
  residual += temp*temp;
  temp = workYaw.KKT[97]-1*workYaw.d[49]*1;
  residual += temp*temp;
  temp = workYaw.KKT[99]-1*workYaw.d[50]*1;
  residual += temp*temp;
  temp = workYaw.KKT[101]-1*workYaw.d[51]*1;
  residual += temp*temp;
  temp = workYaw.KKT[103]-1*workYaw.d[52]*1;
  residual += temp*temp;
  temp = workYaw.KKT[105]-1*workYaw.d[53]*1;
  residual += temp*temp;
  temp = workYaw.KKT[107]-1*workYaw.d[54]*1;
  residual += temp*temp;
  temp = workYaw.KKT[109]-1*workYaw.d[55]*1;
  residual += temp*temp;
  temp = workYaw.KKT[111]-1*workYaw.d[56]*1;
  residual += temp*temp;
  temp = workYaw.KKT[113]-1*workYaw.d[57]*1;
  residual += temp*temp;
  temp = workYaw.KKT[115]-1*workYaw.d[58]*1;
  residual += temp*temp;
  temp = workYaw.KKT[117]-1*workYaw.d[59]*1;
  residual += temp*temp;
  temp = workYaw.KKT[119]-1*workYaw.d[60]*1;
  residual += temp*temp;
  temp = workYaw.KKT[121]-1*workYaw.d[61]*1;
  residual += temp*temp;
  temp = workYaw.KKT[123]-1*workYaw.d[62]*1;
  residual += temp*temp;
  temp = workYaw.KKT[125]-1*workYaw.d[63]*1;
  residual += temp*temp;
  temp = workYaw.KKT[127]-1*workYaw.d[64]*1;
  residual += temp*temp;
  temp = workYaw.KKT[129]-1*workYaw.d[65]*1;
  residual += temp*temp;
  temp = workYaw.KKT[131]-1*workYaw.d[66]*1;
  residual += temp*temp;
  temp = workYaw.KKT[133]-1*workYaw.d[67]*1;
  residual += temp*temp;
  temp = workYaw.KKT[135]-1*workYaw.d[68]*1;
  residual += temp*temp;
  temp = workYaw.KKT[137]-1*workYaw.d[69]*1;
  residual += temp*temp;
  temp = workYaw.KKT[139]-1*workYaw.d[70]*1;
  residual += temp*temp;
  temp = workYaw.KKT[141]-1*workYaw.d[71]*1;
  residual += temp*temp;
  temp = workYaw.KKT[143]-1*workYaw.d[72]*1;
  residual += temp*temp;
  temp = workYaw.KKT[145]-1*workYaw.d[73]*1;
  residual += temp*temp;
  temp = workYaw.KKT[147]-1*workYaw.d[74]*1;
  residual += temp*temp;
  temp = workYaw.KKT[149]-1*workYaw.d[75]*1;
  residual += temp*temp;
  temp = workYaw.KKT[151]-1*workYaw.d[76]*1;
  residual += temp*temp;
  temp = workYaw.KKT[153]-1*workYaw.d[77]*1;
  residual += temp*temp;
  temp = workYaw.KKT[155]-1*workYaw.d[78]*1;
  residual += temp*temp;
  temp = workYaw.KKT[157]-1*workYaw.d[79]*1;
  residual += temp*temp;
  temp = workYaw.KKT[159]-1*workYaw.d[80]*1;
  residual += temp*temp;
  temp = workYaw.KKT[161]-1*workYaw.d[81]*1;
  residual += temp*temp;
  temp = workYaw.KKT[163]-1*workYaw.d[82]*1;
  residual += temp*temp;
  temp = workYaw.KKT[165]-1*workYaw.d[83]*1;
  residual += temp*temp;
  temp = workYaw.KKT[167]-1*workYaw.d[84]*1;
  residual += temp*temp;
  temp = workYaw.KKT[169]-1*workYaw.d[85]*1;
  residual += temp*temp;
  temp = workYaw.KKT[171]-1*workYaw.d[86]*1;
  residual += temp*temp;
  temp = workYaw.KKT[173]-1*workYaw.d[87]*1;
  residual += temp*temp;
  temp = workYaw.KKT[175]-1*workYaw.d[88]*1;
  residual += temp*temp;
  temp = workYaw.KKT[177]-1*workYaw.d[89]*1;
  residual += temp*temp;
  temp = workYaw.KKT[179]-1*workYaw.d[90]*1;
  residual += temp*temp;
  temp = workYaw.KKT[181]-1*workYaw.d[91]*1;
  residual += temp*temp;
  temp = workYaw.KKT[183]-1*workYaw.d[92]*1;
  residual += temp*temp;
  temp = workYaw.KKT[185]-1*workYaw.d[93]*1;
  residual += temp*temp;
  temp = workYaw.KKT[187]-1*workYaw.d[94]*1;
  residual += temp*temp;
  temp = workYaw.KKT[189]-1*workYaw.d[95]*1;
  residual += temp*temp;
  temp = workYaw.KKT[191]-1*workYaw.d[96]*1;
  residual += temp*temp;
  temp = workYaw.KKT[193]-1*workYaw.d[97]*1;
  residual += temp*temp;
  temp = workYaw.KKT[195]-1*workYaw.d[98]*1;
  residual += temp*temp;
  temp = workYaw.KKT[197]-1*workYaw.d[99]*1;
  residual += temp*temp;
  temp = workYaw.KKT[199]-1*workYaw.d[100]*1;
  residual += temp*temp;
  temp = workYaw.KKT[201]-1*workYaw.d[101]*1;
  residual += temp*temp;
  temp = workYaw.KKT[203]-1*workYaw.d[102]*1;
  residual += temp*temp;
  temp = workYaw.KKT[205]-1*workYaw.d[103]*1;
  residual += temp*temp;
  temp = workYaw.KKT[207]-1*workYaw.d[104]*1;
  residual += temp*temp;
  temp = workYaw.KKT[209]-1*workYaw.d[105]*1;
  residual += temp*temp;
  temp = workYaw.KKT[211]-1*workYaw.d[106]*1;
  residual += temp*temp;
  temp = workYaw.KKT[213]-1*workYaw.d[107]*1;
  residual += temp*temp;
  temp = workYaw.KKT[215]-1*workYaw.d[108]*1;
  residual += temp*temp;
  temp = workYaw.KKT[217]-1*workYaw.d[109]*1;
  residual += temp*temp;
  temp = workYaw.KKT[219]-1*workYaw.d[110]*1;
  residual += temp*temp;
  temp = workYaw.KKT[221]-1*workYaw.d[111]*1;
  residual += temp*temp;
  temp = workYaw.KKT[223]-1*workYaw.d[112]*1;
  residual += temp*temp;
  temp = workYaw.KKT[225]-1*workYaw.d[113]*1;
  residual += temp*temp;
  temp = workYaw.KKT[227]-1*workYaw.d[114]*1;
  residual += temp*temp;
  temp = workYaw.KKT[229]-1*workYaw.d[115]*1;
  residual += temp*temp;
  temp = workYaw.KKT[231]-1*workYaw.d[116]*1;
  residual += temp*temp;
  temp = workYaw.KKT[233]-1*workYaw.d[117]*1;
  residual += temp*temp;
  temp = workYaw.KKT[235]-1*workYaw.d[118]*1;
  residual += temp*temp;
  temp = workYaw.KKT[237]-1*workYaw.d[119]*1;
  residual += temp*temp;
  temp = workYaw.KKT[239]-1*workYaw.d[120]*1;
  residual += temp*temp;
  temp = workYaw.KKT[241]-1*workYaw.d[121]*1;
  residual += temp*temp;
  temp = workYaw.KKT[243]-1*workYaw.d[122]*1;
  residual += temp*temp;
  temp = workYaw.KKT[245]-1*workYaw.d[123]*1;
  residual += temp*temp;
  temp = workYaw.KKT[247]-1*workYaw.d[124]*1;
  residual += temp*temp;
  temp = workYaw.KKT[249]-1*workYaw.d[125]*1;
  residual += temp*temp;
  temp = workYaw.KKT[251]-1*workYaw.d[126]*1;
  residual += temp*temp;
  temp = workYaw.KKT[253]-1*workYaw.d[127]*1;
  residual += temp*temp;
  temp = workYaw.KKT[255]-1*workYaw.d[128]*1;
  residual += temp*temp;
  temp = workYaw.KKT[257]-1*workYaw.d[129]*1;
  residual += temp*temp;
  temp = workYaw.KKT[259]-1*workYaw.d[130]*1;
  residual += temp*temp;
  temp = workYaw.KKT[261]-1*workYaw.d[131]*1;
  residual += temp*temp;
  temp = workYaw.KKT[263]-1*workYaw.d[132]*1;
  residual += temp*temp;
  temp = workYaw.KKT[265]-1*workYaw.d[133]*1;
  residual += temp*temp;
  temp = workYaw.KKT[267]-1*workYaw.d[134]*1;
  residual += temp*temp;
  temp = workYaw.KKT[269]-1*workYaw.d[135]*1;
  residual += temp*temp;
  temp = workYaw.KKT[271]-1*workYaw.d[136]*1;
  residual += temp*temp;
  temp = workYaw.KKT[273]-1*workYaw.d[137]*1;
  residual += temp*temp;
  temp = workYaw.KKT[275]-1*workYaw.d[138]*1;
  residual += temp*temp;
  temp = workYaw.KKT[277]-1*workYaw.d[139]*1;
  residual += temp*temp;
  temp = workYaw.KKT[279]-1*workYaw.d[140]*1;
  residual += temp*temp;
  temp = workYaw.KKT[281]-1*workYaw.d[141]*1;
  residual += temp*temp;
  temp = workYaw.KKT[283]-1*workYaw.d[142]*1;
  residual += temp*temp;
  temp = workYaw.KKT[285]-1*workYaw.d[143]*1;
  residual += temp*temp;
  temp = workYaw.KKT[287]-1*workYaw.d[144]*1;
  residual += temp*temp;
  temp = workYaw.KKT[289]-1*workYaw.d[145]*1;
  residual += temp*temp;
  temp = workYaw.KKT[291]-1*workYaw.d[146]*1;
  residual += temp*temp;
  temp = workYaw.KKT[293]-1*workYaw.d[147]*1;
  residual += temp*temp;
  temp = workYaw.KKT[295]-1*workYaw.d[148]*1;
  residual += temp*temp;
  temp = workYaw.KKT[297]-1*workYaw.d[149]*1;
  residual += temp*temp;
  temp = workYaw.KKT[299]-1*workYaw.d[150]*1;
  residual += temp*temp;
  temp = workYaw.KKT[301]-1*workYaw.d[151]*1;
  residual += temp*temp;
  temp = workYaw.KKT[303]-1*workYaw.d[152]*1;
  residual += temp*temp;
  temp = workYaw.KKT[305]-1*workYaw.d[153]*1;
  residual += temp*temp;
  temp = workYaw.KKT[307]-1*workYaw.d[154]*1;
  residual += temp*temp;
  temp = workYaw.KKT[309]-1*workYaw.d[155]*1;
  residual += temp*temp;
  temp = workYaw.KKT[311]-1*workYaw.d[156]*1;
  residual += temp*temp;
  temp = workYaw.KKT[313]-1*workYaw.d[157]*1;
  residual += temp*temp;
  temp = workYaw.KKT[315]-1*workYaw.d[158]*1;
  residual += temp*temp;
  temp = workYaw.KKT[317]-1*workYaw.d[159]*1;
  residual += temp*temp;
  temp = workYaw.KKT[319]-1*workYaw.d[160]*1;
  residual += temp*temp;
  temp = workYaw.KKT[2]-workYaw.L[0]*workYaw.d[1]*1;
  residual += temp*temp;
  temp = workYaw.KKT[4]-workYaw.L[1]*workYaw.d[2]*1;
  residual += temp*temp;
  temp = workYaw.KKT[6]-workYaw.L[2]*workYaw.d[3]*1;
  residual += temp*temp;
  temp = workYaw.KKT[8]-workYaw.L[3]*workYaw.d[4]*1;
  residual += temp*temp;
  temp = workYaw.KKT[10]-workYaw.L[4]*workYaw.d[5]*1;
  residual += temp*temp;
  temp = workYaw.KKT[12]-workYaw.L[5]*workYaw.d[6]*1;
  residual += temp*temp;
  temp = workYaw.KKT[14]-workYaw.L[6]*workYaw.d[7]*1;
  residual += temp*temp;
  temp = workYaw.KKT[16]-workYaw.L[7]*workYaw.d[8]*1;
  residual += temp*temp;
  temp = workYaw.KKT[18]-workYaw.L[8]*workYaw.d[9]*1;
  residual += temp*temp;
  temp = workYaw.KKT[20]-workYaw.L[9]*workYaw.d[10]*1;
  residual += temp*temp;
  temp = workYaw.KKT[22]-workYaw.L[10]*workYaw.d[11]*1;
  residual += temp*temp;
  temp = workYaw.KKT[24]-workYaw.L[11]*workYaw.d[12]*1;
  residual += temp*temp;
  temp = workYaw.KKT[26]-workYaw.L[12]*workYaw.d[13]*1;
  residual += temp*temp;
  temp = workYaw.KKT[28]-workYaw.L[13]*workYaw.d[14]*1;
  residual += temp*temp;
  temp = workYaw.KKT[30]-workYaw.L[14]*workYaw.d[15]*1;
  residual += temp*temp;
  temp = workYaw.KKT[32]-workYaw.L[15]*workYaw.d[16]*1;
  residual += temp*temp;
  temp = workYaw.KKT[34]-workYaw.L[16]*workYaw.d[17]*1;
  residual += temp*temp;
  temp = workYaw.KKT[36]-workYaw.L[17]*workYaw.d[18]*1;
  residual += temp*temp;
  temp = workYaw.KKT[38]-workYaw.L[18]*workYaw.d[19]*1;
  residual += temp*temp;
  temp = workYaw.KKT[40]-workYaw.L[19]*workYaw.d[20]*1;
  residual += temp*temp;
  temp = workYaw.KKT[42]-workYaw.L[20]*workYaw.d[21]*1;
  residual += temp*temp;
  temp = workYaw.KKT[44]-workYaw.L[21]*workYaw.d[22]*1;
  residual += temp*temp;
  temp = workYaw.KKT[46]-workYaw.L[22]*workYaw.d[23]*1;
  residual += temp*temp;
  temp = workYaw.KKT[48]-workYaw.L[23]*workYaw.d[24]*1;
  residual += temp*temp;
  temp = workYaw.KKT[50]-workYaw.L[24]*workYaw.d[25]*1;
  residual += temp*temp;
  temp = workYaw.KKT[52]-workYaw.L[25]*workYaw.d[26]*1;
  residual += temp*temp;
  temp = workYaw.KKT[54]-workYaw.L[26]*workYaw.d[27]*1;
  residual += temp*temp;
  temp = workYaw.KKT[56]-workYaw.L[27]*workYaw.d[28]*1;
  residual += temp*temp;
  temp = workYaw.KKT[58]-workYaw.L[28]*workYaw.d[29]*1;
  residual += temp*temp;
  temp = workYaw.KKT[60]-workYaw.L[29]*workYaw.d[30]*1;
  residual += temp*temp;
  temp = workYaw.KKT[62]-workYaw.L[30]*workYaw.d[31]*1;
  residual += temp*temp;
  temp = workYaw.KKT[64]-workYaw.L[31]*workYaw.d[32]*1;
  residual += temp*temp;
  temp = workYaw.KKT[66]-workYaw.L[32]*workYaw.d[33]*1;
  residual += temp*temp;
  temp = workYaw.KKT[68]-workYaw.L[33]*workYaw.d[34]*1;
  residual += temp*temp;
  temp = workYaw.KKT[70]-workYaw.L[34]*workYaw.d[35]*1;
  residual += temp*temp;
  temp = workYaw.KKT[72]-workYaw.L[35]*workYaw.d[36]*1;
  residual += temp*temp;
  temp = workYaw.KKT[74]-workYaw.L[36]*workYaw.d[37]*1;
  residual += temp*temp;
  temp = workYaw.KKT[76]-workYaw.L[37]*workYaw.d[38]*1;
  residual += temp*temp;
  temp = workYaw.KKT[78]-workYaw.L[38]*workYaw.d[39]*1;
  residual += temp*temp;
  temp = workYaw.KKT[80]-workYaw.L[39]*workYaw.d[40]*1;
  residual += temp*temp;
  temp = workYaw.KKT[82]-workYaw.L[40]*workYaw.d[41]*1;
  residual += temp*temp;
  temp = workYaw.KKT[84]-workYaw.L[41]*workYaw.d[42]*1;
  residual += temp*temp;
  temp = workYaw.KKT[86]-workYaw.L[42]*workYaw.d[43]*1;
  residual += temp*temp;
  temp = workYaw.KKT[88]-workYaw.L[43]*workYaw.d[44]*1;
  residual += temp*temp;
  temp = workYaw.KKT[90]-workYaw.L[44]*workYaw.d[45]*1;
  residual += temp*temp;
  temp = workYaw.KKT[92]-workYaw.L[45]*workYaw.d[46]*1;
  residual += temp*temp;
  temp = workYaw.KKT[94]-workYaw.L[46]*workYaw.d[47]*1;
  residual += temp*temp;
  temp = workYaw.KKT[96]-workYaw.L[47]*workYaw.d[48]*1;
  residual += temp*temp;
  temp = workYaw.KKT[98]-workYaw.L[48]*workYaw.d[49]*1;
  residual += temp*temp;
  temp = workYaw.KKT[100]-workYaw.L[49]*workYaw.d[50]*1;
  residual += temp*temp;
  temp = workYaw.KKT[102]-workYaw.L[50]*workYaw.d[51]*1;
  residual += temp*temp;
  temp = workYaw.KKT[104]-workYaw.L[51]*workYaw.d[52]*1;
  residual += temp*temp;
  temp = workYaw.KKT[106]-workYaw.L[52]*workYaw.d[53]*1;
  residual += temp*temp;
  temp = workYaw.KKT[108]-workYaw.L[53]*workYaw.d[54]*1;
  residual += temp*temp;
  temp = workYaw.KKT[110]-workYaw.L[54]*workYaw.d[55]*1;
  residual += temp*temp;
  temp = workYaw.KKT[112]-workYaw.L[55]*workYaw.d[56]*1;
  residual += temp*temp;
  temp = workYaw.KKT[114]-workYaw.L[56]*workYaw.d[57]*1;
  residual += temp*temp;
  temp = workYaw.KKT[116]-workYaw.L[57]*workYaw.d[58]*1;
  residual += temp*temp;
  temp = workYaw.KKT[118]-workYaw.L[58]*workYaw.d[59]*1;
  residual += temp*temp;
  temp = workYaw.KKT[120]-workYaw.L[59]*workYaw.d[60]*1;
  residual += temp*temp;
  temp = workYaw.KKT[122]-workYaw.L[60]*workYaw.d[61]*1;
  residual += temp*temp;
  temp = workYaw.KKT[124]-workYaw.L[61]*workYaw.d[62]*1;
  residual += temp*temp;
  temp = workYaw.KKT[126]-workYaw.L[62]*workYaw.d[63]*1;
  residual += temp*temp;
  temp = workYaw.KKT[128]-workYaw.L[63]*workYaw.d[64]*1;
  residual += temp*temp;
  temp = workYaw.KKT[130]-workYaw.L[64]*workYaw.d[65]*1;
  residual += temp*temp;
  temp = workYaw.KKT[132]-workYaw.L[65]*workYaw.d[66]*1;
  residual += temp*temp;
  temp = workYaw.KKT[134]-workYaw.L[66]*workYaw.d[67]*1;
  residual += temp*temp;
  temp = workYaw.KKT[136]-workYaw.L[67]*workYaw.d[68]*1;
  residual += temp*temp;
  temp = workYaw.KKT[138]-workYaw.L[68]*workYaw.d[69]*1;
  residual += temp*temp;
  temp = workYaw.KKT[140]-workYaw.L[69]*workYaw.d[70]*1;
  residual += temp*temp;
  temp = workYaw.KKT[142]-workYaw.L[70]*workYaw.d[71]*1;
  residual += temp*temp;
  temp = workYaw.KKT[144]-workYaw.L[71]*workYaw.d[72]*1;
  residual += temp*temp;
  temp = workYaw.KKT[146]-workYaw.L[72]*workYaw.d[73]*1;
  residual += temp*temp;
  temp = workYaw.KKT[148]-workYaw.L[73]*workYaw.d[74]*1;
  residual += temp*temp;
  temp = workYaw.KKT[150]-workYaw.L[74]*workYaw.d[75]*1;
  residual += temp*temp;
  temp = workYaw.KKT[152]-workYaw.L[75]*workYaw.d[76]*1;
  residual += temp*temp;
  temp = workYaw.KKT[154]-workYaw.L[76]*workYaw.d[77]*1;
  residual += temp*temp;
  temp = workYaw.KKT[156]-workYaw.L[77]*workYaw.d[78]*1;
  residual += temp*temp;
  temp = workYaw.KKT[158]-workYaw.L[78]*workYaw.d[79]*1;
  residual += temp*temp;
  temp = workYaw.KKT[160]-workYaw.L[79]*workYaw.d[80]*1;
  residual += temp*temp;
  temp = workYaw.KKT[162]-workYaw.L[80]*workYaw.d[81]*1;
  residual += temp*temp;
  temp = workYaw.KKT[164]-workYaw.L[81]*workYaw.d[82]*1;
  residual += temp*temp;
  temp = workYaw.KKT[166]-workYaw.L[82]*workYaw.d[83]*1;
  residual += temp*temp;
  temp = workYaw.KKT[168]-workYaw.L[83]*workYaw.d[84]*1;
  residual += temp*temp;
  temp = workYaw.KKT[170]-workYaw.L[84]*workYaw.d[85]*1;
  residual += temp*temp;
  temp = workYaw.KKT[172]-workYaw.L[85]*workYaw.d[86]*1;
  residual += temp*temp;
  temp = workYaw.KKT[174]-workYaw.L[86]*workYaw.d[87]*1;
  residual += temp*temp;
  temp = workYaw.KKT[176]-workYaw.L[87]*workYaw.d[88]*1;
  residual += temp*temp;
  temp = workYaw.KKT[178]-workYaw.L[88]*workYaw.d[89]*1;
  residual += temp*temp;
  temp = workYaw.KKT[180]-workYaw.L[89]*workYaw.d[90]*1;
  residual += temp*temp;
  temp = workYaw.KKT[182]-workYaw.L[90]*workYaw.d[91]*1;
  residual += temp*temp;
  temp = workYaw.KKT[184]-workYaw.L[91]*workYaw.d[92]*1;
  residual += temp*temp;
  temp = workYaw.KKT[186]-workYaw.L[92]*workYaw.d[93]*1;
  residual += temp*temp;
  temp = workYaw.KKT[188]-workYaw.L[93]*workYaw.d[94]*1;
  residual += temp*temp;
  temp = workYaw.KKT[190]-workYaw.L[94]*workYaw.d[95]*1;
  residual += temp*temp;
  temp = workYaw.KKT[192]-workYaw.L[95]*workYaw.d[96]*1;
  residual += temp*temp;
  temp = workYaw.KKT[194]-workYaw.L[96]*workYaw.d[97]*1;
  residual += temp*temp;
  temp = workYaw.KKT[196]-workYaw.L[97]*workYaw.d[98]*1;
  residual += temp*temp;
  temp = workYaw.KKT[198]-workYaw.L[98]*workYaw.d[99]*1;
  residual += temp*temp;
  temp = workYaw.KKT[200]-workYaw.L[99]*workYaw.d[100]*1;
  residual += temp*temp;
  temp = workYaw.KKT[202]-workYaw.L[100]*workYaw.d[101]*1;
  residual += temp*temp;
  temp = workYaw.KKT[204]-workYaw.L[101]*workYaw.d[102]*1;
  residual += temp*temp;
  temp = workYaw.KKT[206]-workYaw.L[102]*workYaw.d[103]*1;
  residual += temp*temp;
  temp = workYaw.KKT[208]-workYaw.L[103]*workYaw.d[104]*1;
  residual += temp*temp;
  temp = workYaw.KKT[210]-workYaw.L[104]*workYaw.d[105]*1;
  residual += temp*temp;
  temp = workYaw.KKT[212]-workYaw.L[105]*workYaw.d[106]*1;
  residual += temp*temp;
  temp = workYaw.KKT[214]-workYaw.L[106]*workYaw.d[107]*1;
  residual += temp*temp;
  temp = workYaw.KKT[216]-workYaw.L[107]*workYaw.d[108]*1;
  residual += temp*temp;
  temp = workYaw.KKT[218]-workYaw.L[108]*workYaw.d[109]*1;
  residual += temp*temp;
  temp = workYaw.KKT[220]-workYaw.L[109]*workYaw.d[110]*1;
  residual += temp*temp;
  temp = workYaw.KKT[222]-workYaw.L[110]*workYaw.d[111]*1;
  residual += temp*temp;
  temp = workYaw.KKT[224]-workYaw.L[111]*workYaw.d[112]*1;
  residual += temp*temp;
  temp = workYaw.KKT[226]-workYaw.L[112]*workYaw.d[113]*1;
  residual += temp*temp;
  temp = workYaw.KKT[228]-workYaw.L[113]*workYaw.d[114]*1;
  residual += temp*temp;
  temp = workYaw.KKT[230]-workYaw.L[114]*workYaw.d[115]*1;
  residual += temp*temp;
  temp = workYaw.KKT[232]-workYaw.L[115]*workYaw.d[116]*1;
  residual += temp*temp;
  temp = workYaw.KKT[234]-workYaw.L[116]*workYaw.d[117]*1;
  residual += temp*temp;
  temp = workYaw.KKT[236]-workYaw.L[117]*workYaw.d[118]*1;
  residual += temp*temp;
  temp = workYaw.KKT[238]-workYaw.L[118]*workYaw.d[119]*1;
  residual += temp*temp;
  temp = workYaw.KKT[240]-workYaw.L[119]*workYaw.d[120]*1;
  residual += temp*temp;
  temp = workYaw.KKT[242]-workYaw.L[120]*workYaw.d[121]*1;
  residual += temp*temp;
  temp = workYaw.KKT[244]-workYaw.L[121]*workYaw.d[122]*1;
  residual += temp*temp;
  temp = workYaw.KKT[246]-workYaw.L[122]*workYaw.d[123]*1;
  residual += temp*temp;
  temp = workYaw.KKT[248]-workYaw.L[123]*workYaw.d[124]*1;
  residual += temp*temp;
  temp = workYaw.KKT[250]-workYaw.L[124]*workYaw.d[125]*1;
  residual += temp*temp;
  temp = workYaw.KKT[252]-workYaw.L[125]*workYaw.d[126]*1;
  residual += temp*temp;
  temp = workYaw.KKT[254]-workYaw.L[126]*workYaw.d[127]*1;
  residual += temp*temp;
  temp = workYaw.KKT[256]-workYaw.L[127]*workYaw.d[128]*1;
  residual += temp*temp;
  temp = workYaw.KKT[258]-workYaw.L[128]*workYaw.d[129]*1;
  residual += temp*temp;
  temp = workYaw.KKT[260]-workYaw.L[129]*workYaw.d[130]*1;
  residual += temp*temp;
  temp = workYaw.KKT[262]-workYaw.L[130]*workYaw.d[131]*1;
  residual += temp*temp;
  temp = workYaw.KKT[264]-workYaw.L[131]*workYaw.d[132]*1;
  residual += temp*temp;
  temp = workYaw.KKT[266]-workYaw.L[132]*workYaw.d[133]*1;
  residual += temp*temp;
  temp = workYaw.KKT[268]-workYaw.L[133]*workYaw.d[134]*1;
  residual += temp*temp;
  temp = workYaw.KKT[270]-workYaw.L[134]*workYaw.d[135]*1;
  residual += temp*temp;
  temp = workYaw.KKT[272]-workYaw.L[135]*workYaw.d[136]*1;
  residual += temp*temp;
  temp = workYaw.KKT[274]-workYaw.L[136]*workYaw.d[137]*1;
  residual += temp*temp;
  temp = workYaw.KKT[276]-workYaw.L[137]*workYaw.d[138]*1;
  residual += temp*temp;
  temp = workYaw.KKT[278]-workYaw.L[138]*workYaw.d[139]*1;
  residual += temp*temp;
  temp = workYaw.KKT[280]-workYaw.L[139]*workYaw.d[140]*1;
  residual += temp*temp;
  temp = workYaw.KKT[282]-workYaw.L[140]*workYaw.d[141]*1;
  residual += temp*temp;
  temp = workYaw.KKT[284]-workYaw.L[141]*workYaw.d[142]*1;
  residual += temp*temp;
  temp = workYaw.KKT[286]-workYaw.L[142]*workYaw.d[143]*1;
  residual += temp*temp;
  temp = workYaw.KKT[288]-workYaw.L[143]*workYaw.d[144]*1;
  residual += temp*temp;
  temp = workYaw.KKT[290]-workYaw.L[144]*workYaw.d[145]*1;
  residual += temp*temp;
  temp = workYaw.KKT[292]-workYaw.L[145]*workYaw.d[146]*1;
  residual += temp*temp;
  temp = workYaw.KKT[294]-workYaw.L[146]*workYaw.d[147]*1;
  residual += temp*temp;
  temp = workYaw.KKT[296]-workYaw.L[147]*workYaw.d[148]*1;
  residual += temp*temp;
  temp = workYaw.KKT[298]-workYaw.L[148]*workYaw.d[149]*1;
  residual += temp*temp;
  temp = workYaw.KKT[300]-workYaw.L[149]*workYaw.d[150]*1;
  residual += temp*temp;
  temp = workYaw.KKT[302]-workYaw.L[150]*workYaw.d[151]*1;
  residual += temp*temp;
  temp = workYaw.KKT[304]-workYaw.L[151]*workYaw.d[152]*1;
  residual += temp*temp;
  temp = workYaw.KKT[306]-workYaw.L[152]*workYaw.d[153]*1;
  residual += temp*temp;
  temp = workYaw.KKT[308]-workYaw.L[153]*workYaw.d[154]*1;
  residual += temp*temp;
  temp = workYaw.KKT[310]-workYaw.L[154]*workYaw.d[155]*1;
  residual += temp*temp;
  temp = workYaw.KKT[312]-workYaw.L[155]*workYaw.d[156]*1;
  residual += temp*temp;
  temp = workYaw.KKT[314]-workYaw.L[156]*workYaw.d[157]*1;
  residual += temp*temp;
  temp = workYaw.KKT[316]-workYaw.L[157]*workYaw.d[158]*1;
  residual += temp*temp;
  temp = workYaw.KKT[318]-workYaw.L[158]*workYaw.d[159]*1;
  residual += temp*temp;
  temp = workYaw.KKT[320]-workYaw.L[159]*workYaw.d[160]*1;
  residual += temp*temp;
  temp = workYaw.KKT[321]-workYaw.L[0]*workYaw.d[1]*workYaw.L[0]-1*workYaw.d[161]*1;
  residual += temp*temp;
  temp = workYaw.KKT[323]-workYaw.L[1]*workYaw.d[2]*workYaw.L[1]-1*workYaw.d[162]*1;
  residual += temp*temp;
  temp = workYaw.KKT[325]-workYaw.L[2]*workYaw.d[3]*workYaw.L[2]-1*workYaw.d[163]*1;
  residual += temp*temp;
  temp = workYaw.KKT[327]-workYaw.L[3]*workYaw.d[4]*workYaw.L[3]-1*workYaw.d[164]*1;
  residual += temp*temp;
  temp = workYaw.KKT[329]-workYaw.L[4]*workYaw.d[5]*workYaw.L[4]-1*workYaw.d[165]*1;
  residual += temp*temp;
  temp = workYaw.KKT[331]-workYaw.L[5]*workYaw.d[6]*workYaw.L[5]-1*workYaw.d[166]*1;
  residual += temp*temp;
  temp = workYaw.KKT[333]-workYaw.L[6]*workYaw.d[7]*workYaw.L[6]-1*workYaw.d[167]*1;
  residual += temp*temp;
  temp = workYaw.KKT[335]-workYaw.L[7]*workYaw.d[8]*workYaw.L[7]-1*workYaw.d[168]*1;
  residual += temp*temp;
  temp = workYaw.KKT[337]-workYaw.L[8]*workYaw.d[9]*workYaw.L[8]-1*workYaw.d[169]*1;
  residual += temp*temp;
  temp = workYaw.KKT[339]-workYaw.L[9]*workYaw.d[10]*workYaw.L[9]-1*workYaw.d[170]*1;
  residual += temp*temp;
  temp = workYaw.KKT[341]-workYaw.L[10]*workYaw.d[11]*workYaw.L[10]-1*workYaw.d[171]*1;
  residual += temp*temp;
  temp = workYaw.KKT[343]-workYaw.L[11]*workYaw.d[12]*workYaw.L[11]-1*workYaw.d[172]*1;
  residual += temp*temp;
  temp = workYaw.KKT[345]-workYaw.L[12]*workYaw.d[13]*workYaw.L[12]-1*workYaw.d[173]*1;
  residual += temp*temp;
  temp = workYaw.KKT[347]-workYaw.L[13]*workYaw.d[14]*workYaw.L[13]-1*workYaw.d[174]*1;
  residual += temp*temp;
  temp = workYaw.KKT[349]-workYaw.L[14]*workYaw.d[15]*workYaw.L[14]-1*workYaw.d[175]*1;
  residual += temp*temp;
  temp = workYaw.KKT[351]-workYaw.L[15]*workYaw.d[16]*workYaw.L[15]-1*workYaw.d[176]*1;
  residual += temp*temp;
  temp = workYaw.KKT[353]-workYaw.L[16]*workYaw.d[17]*workYaw.L[16]-1*workYaw.d[177]*1;
  residual += temp*temp;
  temp = workYaw.KKT[355]-workYaw.L[17]*workYaw.d[18]*workYaw.L[17]-1*workYaw.d[178]*1;
  residual += temp*temp;
  temp = workYaw.KKT[357]-workYaw.L[18]*workYaw.d[19]*workYaw.L[18]-1*workYaw.d[179]*1;
  residual += temp*temp;
  temp = workYaw.KKT[359]-workYaw.L[19]*workYaw.d[20]*workYaw.L[19]-1*workYaw.d[180]*1;
  residual += temp*temp;
  temp = workYaw.KKT[361]-workYaw.L[20]*workYaw.d[21]*workYaw.L[20]-1*workYaw.d[181]*1;
  residual += temp*temp;
  temp = workYaw.KKT[363]-workYaw.L[21]*workYaw.d[22]*workYaw.L[21]-1*workYaw.d[182]*1;
  residual += temp*temp;
  temp = workYaw.KKT[365]-workYaw.L[22]*workYaw.d[23]*workYaw.L[22]-1*workYaw.d[183]*1;
  residual += temp*temp;
  temp = workYaw.KKT[367]-workYaw.L[23]*workYaw.d[24]*workYaw.L[23]-1*workYaw.d[184]*1;
  residual += temp*temp;
  temp = workYaw.KKT[369]-workYaw.L[24]*workYaw.d[25]*workYaw.L[24]-1*workYaw.d[185]*1;
  residual += temp*temp;
  temp = workYaw.KKT[371]-workYaw.L[25]*workYaw.d[26]*workYaw.L[25]-1*workYaw.d[186]*1;
  residual += temp*temp;
  temp = workYaw.KKT[373]-workYaw.L[26]*workYaw.d[27]*workYaw.L[26]-1*workYaw.d[187]*1;
  residual += temp*temp;
  temp = workYaw.KKT[375]-workYaw.L[27]*workYaw.d[28]*workYaw.L[27]-1*workYaw.d[188]*1;
  residual += temp*temp;
  temp = workYaw.KKT[377]-workYaw.L[28]*workYaw.d[29]*workYaw.L[28]-1*workYaw.d[189]*1;
  residual += temp*temp;
  temp = workYaw.KKT[379]-workYaw.L[29]*workYaw.d[30]*workYaw.L[29]-1*workYaw.d[190]*1;
  residual += temp*temp;
  temp = workYaw.KKT[381]-workYaw.L[30]*workYaw.d[31]*workYaw.L[30]-1*workYaw.d[191]*1;
  residual += temp*temp;
  temp = workYaw.KKT[383]-workYaw.L[31]*workYaw.d[32]*workYaw.L[31]-1*workYaw.d[192]*1;
  residual += temp*temp;
  temp = workYaw.KKT[385]-workYaw.L[32]*workYaw.d[33]*workYaw.L[32]-1*workYaw.d[193]*1;
  residual += temp*temp;
  temp = workYaw.KKT[387]-workYaw.L[33]*workYaw.d[34]*workYaw.L[33]-1*workYaw.d[194]*1;
  residual += temp*temp;
  temp = workYaw.KKT[389]-workYaw.L[34]*workYaw.d[35]*workYaw.L[34]-1*workYaw.d[195]*1;
  residual += temp*temp;
  temp = workYaw.KKT[391]-workYaw.L[35]*workYaw.d[36]*workYaw.L[35]-1*workYaw.d[196]*1;
  residual += temp*temp;
  temp = workYaw.KKT[393]-workYaw.L[36]*workYaw.d[37]*workYaw.L[36]-1*workYaw.d[197]*1;
  residual += temp*temp;
  temp = workYaw.KKT[395]-workYaw.L[37]*workYaw.d[38]*workYaw.L[37]-1*workYaw.d[198]*1;
  residual += temp*temp;
  temp = workYaw.KKT[397]-workYaw.L[38]*workYaw.d[39]*workYaw.L[38]-1*workYaw.d[199]*1;
  residual += temp*temp;
  temp = workYaw.KKT[399]-workYaw.L[39]*workYaw.d[40]*workYaw.L[39]-1*workYaw.d[200]*1;
  residual += temp*temp;
  temp = workYaw.KKT[401]-workYaw.L[40]*workYaw.d[41]*workYaw.L[40]-1*workYaw.d[201]*1;
  residual += temp*temp;
  temp = workYaw.KKT[403]-workYaw.L[41]*workYaw.d[42]*workYaw.L[41]-1*workYaw.d[202]*1;
  residual += temp*temp;
  temp = workYaw.KKT[405]-workYaw.L[42]*workYaw.d[43]*workYaw.L[42]-1*workYaw.d[203]*1;
  residual += temp*temp;
  temp = workYaw.KKT[407]-workYaw.L[43]*workYaw.d[44]*workYaw.L[43]-1*workYaw.d[204]*1;
  residual += temp*temp;
  temp = workYaw.KKT[409]-workYaw.L[44]*workYaw.d[45]*workYaw.L[44]-1*workYaw.d[205]*1;
  residual += temp*temp;
  temp = workYaw.KKT[411]-workYaw.L[45]*workYaw.d[46]*workYaw.L[45]-1*workYaw.d[206]*1;
  residual += temp*temp;
  temp = workYaw.KKT[413]-workYaw.L[46]*workYaw.d[47]*workYaw.L[46]-1*workYaw.d[207]*1;
  residual += temp*temp;
  temp = workYaw.KKT[415]-workYaw.L[47]*workYaw.d[48]*workYaw.L[47]-1*workYaw.d[208]*1;
  residual += temp*temp;
  temp = workYaw.KKT[417]-workYaw.L[48]*workYaw.d[49]*workYaw.L[48]-1*workYaw.d[209]*1;
  residual += temp*temp;
  temp = workYaw.KKT[419]-workYaw.L[49]*workYaw.d[50]*workYaw.L[49]-1*workYaw.d[210]*1;
  residual += temp*temp;
  temp = workYaw.KKT[421]-workYaw.L[50]*workYaw.d[51]*workYaw.L[50]-1*workYaw.d[211]*1;
  residual += temp*temp;
  temp = workYaw.KKT[423]-workYaw.L[51]*workYaw.d[52]*workYaw.L[51]-1*workYaw.d[212]*1;
  residual += temp*temp;
  temp = workYaw.KKT[425]-workYaw.L[52]*workYaw.d[53]*workYaw.L[52]-1*workYaw.d[213]*1;
  residual += temp*temp;
  temp = workYaw.KKT[427]-workYaw.L[53]*workYaw.d[54]*workYaw.L[53]-1*workYaw.d[214]*1;
  residual += temp*temp;
  temp = workYaw.KKT[429]-workYaw.L[54]*workYaw.d[55]*workYaw.L[54]-1*workYaw.d[215]*1;
  residual += temp*temp;
  temp = workYaw.KKT[431]-workYaw.L[55]*workYaw.d[56]*workYaw.L[55]-1*workYaw.d[216]*1;
  residual += temp*temp;
  temp = workYaw.KKT[433]-workYaw.L[56]*workYaw.d[57]*workYaw.L[56]-1*workYaw.d[217]*1;
  residual += temp*temp;
  temp = workYaw.KKT[435]-workYaw.L[57]*workYaw.d[58]*workYaw.L[57]-1*workYaw.d[218]*1;
  residual += temp*temp;
  temp = workYaw.KKT[437]-workYaw.L[58]*workYaw.d[59]*workYaw.L[58]-1*workYaw.d[219]*1;
  residual += temp*temp;
  temp = workYaw.KKT[439]-workYaw.L[59]*workYaw.d[60]*workYaw.L[59]-1*workYaw.d[220]*1;
  residual += temp*temp;
  temp = workYaw.KKT[441]-workYaw.L[60]*workYaw.d[61]*workYaw.L[60]-1*workYaw.d[221]*1;
  residual += temp*temp;
  temp = workYaw.KKT[443]-workYaw.L[61]*workYaw.d[62]*workYaw.L[61]-1*workYaw.d[222]*1;
  residual += temp*temp;
  temp = workYaw.KKT[445]-workYaw.L[62]*workYaw.d[63]*workYaw.L[62]-1*workYaw.d[223]*1;
  residual += temp*temp;
  temp = workYaw.KKT[447]-workYaw.L[63]*workYaw.d[64]*workYaw.L[63]-1*workYaw.d[224]*1;
  residual += temp*temp;
  temp = workYaw.KKT[449]-workYaw.L[64]*workYaw.d[65]*workYaw.L[64]-1*workYaw.d[225]*1;
  residual += temp*temp;
  temp = workYaw.KKT[451]-workYaw.L[65]*workYaw.d[66]*workYaw.L[65]-1*workYaw.d[226]*1;
  residual += temp*temp;
  temp = workYaw.KKT[453]-workYaw.L[66]*workYaw.d[67]*workYaw.L[66]-1*workYaw.d[227]*1;
  residual += temp*temp;
  temp = workYaw.KKT[455]-workYaw.L[67]*workYaw.d[68]*workYaw.L[67]-1*workYaw.d[228]*1;
  residual += temp*temp;
  temp = workYaw.KKT[457]-workYaw.L[68]*workYaw.d[69]*workYaw.L[68]-1*workYaw.d[229]*1;
  residual += temp*temp;
  temp = workYaw.KKT[459]-workYaw.L[69]*workYaw.d[70]*workYaw.L[69]-1*workYaw.d[230]*1;
  residual += temp*temp;
  temp = workYaw.KKT[461]-workYaw.L[70]*workYaw.d[71]*workYaw.L[70]-1*workYaw.d[231]*1;
  residual += temp*temp;
  temp = workYaw.KKT[463]-workYaw.L[71]*workYaw.d[72]*workYaw.L[71]-1*workYaw.d[232]*1;
  residual += temp*temp;
  temp = workYaw.KKT[465]-workYaw.L[72]*workYaw.d[73]*workYaw.L[72]-1*workYaw.d[233]*1;
  residual += temp*temp;
  temp = workYaw.KKT[467]-workYaw.L[73]*workYaw.d[74]*workYaw.L[73]-1*workYaw.d[234]*1;
  residual += temp*temp;
  temp = workYaw.KKT[469]-workYaw.L[74]*workYaw.d[75]*workYaw.L[74]-1*workYaw.d[235]*1;
  residual += temp*temp;
  temp = workYaw.KKT[471]-workYaw.L[75]*workYaw.d[76]*workYaw.L[75]-1*workYaw.d[236]*1;
  residual += temp*temp;
  temp = workYaw.KKT[473]-workYaw.L[76]*workYaw.d[77]*workYaw.L[76]-1*workYaw.d[237]*1;
  residual += temp*temp;
  temp = workYaw.KKT[475]-workYaw.L[77]*workYaw.d[78]*workYaw.L[77]-1*workYaw.d[238]*1;
  residual += temp*temp;
  temp = workYaw.KKT[477]-workYaw.L[78]*workYaw.d[79]*workYaw.L[78]-1*workYaw.d[239]*1;
  residual += temp*temp;
  temp = workYaw.KKT[479]-workYaw.L[79]*workYaw.d[80]*workYaw.L[79]-1*workYaw.d[240]*1;
  residual += temp*temp;
  temp = workYaw.KKT[481]-workYaw.L[80]*workYaw.d[81]*workYaw.L[80]-1*workYaw.d[241]*1;
  residual += temp*temp;
  temp = workYaw.KKT[483]-workYaw.L[81]*workYaw.d[82]*workYaw.L[81]-1*workYaw.d[242]*1;
  residual += temp*temp;
  temp = workYaw.KKT[485]-workYaw.L[82]*workYaw.d[83]*workYaw.L[82]-1*workYaw.d[243]*1;
  residual += temp*temp;
  temp = workYaw.KKT[487]-workYaw.L[83]*workYaw.d[84]*workYaw.L[83]-1*workYaw.d[244]*1;
  residual += temp*temp;
  temp = workYaw.KKT[489]-workYaw.L[84]*workYaw.d[85]*workYaw.L[84]-1*workYaw.d[245]*1;
  residual += temp*temp;
  temp = workYaw.KKT[491]-workYaw.L[85]*workYaw.d[86]*workYaw.L[85]-1*workYaw.d[246]*1;
  residual += temp*temp;
  temp = workYaw.KKT[493]-workYaw.L[86]*workYaw.d[87]*workYaw.L[86]-1*workYaw.d[247]*1;
  residual += temp*temp;
  temp = workYaw.KKT[495]-workYaw.L[87]*workYaw.d[88]*workYaw.L[87]-1*workYaw.d[248]*1;
  residual += temp*temp;
  temp = workYaw.KKT[497]-workYaw.L[88]*workYaw.d[89]*workYaw.L[88]-1*workYaw.d[249]*1;
  residual += temp*temp;
  temp = workYaw.KKT[499]-workYaw.L[89]*workYaw.d[90]*workYaw.L[89]-1*workYaw.d[250]*1;
  residual += temp*temp;
  temp = workYaw.KKT[501]-workYaw.L[90]*workYaw.d[91]*workYaw.L[90]-1*workYaw.d[251]*1;
  residual += temp*temp;
  temp = workYaw.KKT[503]-workYaw.L[91]*workYaw.d[92]*workYaw.L[91]-1*workYaw.d[252]*1;
  residual += temp*temp;
  temp = workYaw.KKT[505]-workYaw.L[92]*workYaw.d[93]*workYaw.L[92]-1*workYaw.d[253]*1;
  residual += temp*temp;
  temp = workYaw.KKT[507]-workYaw.L[93]*workYaw.d[94]*workYaw.L[93]-1*workYaw.d[254]*1;
  residual += temp*temp;
  temp = workYaw.KKT[509]-workYaw.L[94]*workYaw.d[95]*workYaw.L[94]-1*workYaw.d[255]*1;
  residual += temp*temp;
  temp = workYaw.KKT[511]-workYaw.L[95]*workYaw.d[96]*workYaw.L[95]-1*workYaw.d[256]*1;
  residual += temp*temp;
  temp = workYaw.KKT[513]-workYaw.L[96]*workYaw.d[97]*workYaw.L[96]-1*workYaw.d[257]*1;
  residual += temp*temp;
  temp = workYaw.KKT[515]-workYaw.L[97]*workYaw.d[98]*workYaw.L[97]-1*workYaw.d[258]*1;
  residual += temp*temp;
  temp = workYaw.KKT[517]-workYaw.L[98]*workYaw.d[99]*workYaw.L[98]-1*workYaw.d[259]*1;
  residual += temp*temp;
  temp = workYaw.KKT[519]-workYaw.L[99]*workYaw.d[100]*workYaw.L[99]-1*workYaw.d[260]*1;
  residual += temp*temp;
  temp = workYaw.KKT[521]-workYaw.L[100]*workYaw.d[101]*workYaw.L[100]-1*workYaw.d[261]*1;
  residual += temp*temp;
  temp = workYaw.KKT[523]-workYaw.L[101]*workYaw.d[102]*workYaw.L[101]-1*workYaw.d[262]*1;
  residual += temp*temp;
  temp = workYaw.KKT[525]-workYaw.L[102]*workYaw.d[103]*workYaw.L[102]-1*workYaw.d[263]*1;
  residual += temp*temp;
  temp = workYaw.KKT[527]-workYaw.L[103]*workYaw.d[104]*workYaw.L[103]-1*workYaw.d[264]*1;
  residual += temp*temp;
  temp = workYaw.KKT[529]-workYaw.L[104]*workYaw.d[105]*workYaw.L[104]-1*workYaw.d[265]*1;
  residual += temp*temp;
  temp = workYaw.KKT[531]-workYaw.L[105]*workYaw.d[106]*workYaw.L[105]-1*workYaw.d[266]*1;
  residual += temp*temp;
  temp = workYaw.KKT[533]-workYaw.L[106]*workYaw.d[107]*workYaw.L[106]-1*workYaw.d[267]*1;
  residual += temp*temp;
  temp = workYaw.KKT[535]-workYaw.L[107]*workYaw.d[108]*workYaw.L[107]-1*workYaw.d[268]*1;
  residual += temp*temp;
  temp = workYaw.KKT[537]-workYaw.L[108]*workYaw.d[109]*workYaw.L[108]-1*workYaw.d[269]*1;
  residual += temp*temp;
  temp = workYaw.KKT[539]-workYaw.L[109]*workYaw.d[110]*workYaw.L[109]-1*workYaw.d[270]*1;
  residual += temp*temp;
  temp = workYaw.KKT[541]-workYaw.L[110]*workYaw.d[111]*workYaw.L[110]-1*workYaw.d[271]*1;
  residual += temp*temp;
  temp = workYaw.KKT[543]-workYaw.L[111]*workYaw.d[112]*workYaw.L[111]-1*workYaw.d[272]*1;
  residual += temp*temp;
  temp = workYaw.KKT[545]-workYaw.L[112]*workYaw.d[113]*workYaw.L[112]-1*workYaw.d[273]*1;
  residual += temp*temp;
  temp = workYaw.KKT[547]-workYaw.L[113]*workYaw.d[114]*workYaw.L[113]-1*workYaw.d[274]*1;
  residual += temp*temp;
  temp = workYaw.KKT[549]-workYaw.L[114]*workYaw.d[115]*workYaw.L[114]-1*workYaw.d[275]*1;
  residual += temp*temp;
  temp = workYaw.KKT[551]-workYaw.L[115]*workYaw.d[116]*workYaw.L[115]-1*workYaw.d[276]*1;
  residual += temp*temp;
  temp = workYaw.KKT[553]-workYaw.L[116]*workYaw.d[117]*workYaw.L[116]-1*workYaw.d[277]*1;
  residual += temp*temp;
  temp = workYaw.KKT[555]-workYaw.L[117]*workYaw.d[118]*workYaw.L[117]-1*workYaw.d[278]*1;
  residual += temp*temp;
  temp = workYaw.KKT[557]-workYaw.L[118]*workYaw.d[119]*workYaw.L[118]-1*workYaw.d[279]*1;
  residual += temp*temp;
  temp = workYaw.KKT[559]-workYaw.L[119]*workYaw.d[120]*workYaw.L[119]-1*workYaw.d[280]*1;
  residual += temp*temp;
  temp = workYaw.KKT[561]-workYaw.L[120]*workYaw.d[121]*workYaw.L[120]-1*workYaw.d[281]*1;
  residual += temp*temp;
  temp = workYaw.KKT[563]-workYaw.L[121]*workYaw.d[122]*workYaw.L[121]-1*workYaw.d[282]*1;
  residual += temp*temp;
  temp = workYaw.KKT[565]-workYaw.L[122]*workYaw.d[123]*workYaw.L[122]-1*workYaw.d[283]*1;
  residual += temp*temp;
  temp = workYaw.KKT[567]-workYaw.L[123]*workYaw.d[124]*workYaw.L[123]-1*workYaw.d[284]*1;
  residual += temp*temp;
  temp = workYaw.KKT[569]-workYaw.L[124]*workYaw.d[125]*workYaw.L[124]-1*workYaw.d[285]*1;
  residual += temp*temp;
  temp = workYaw.KKT[571]-workYaw.L[125]*workYaw.d[126]*workYaw.L[125]-1*workYaw.d[286]*1;
  residual += temp*temp;
  temp = workYaw.KKT[573]-workYaw.L[126]*workYaw.d[127]*workYaw.L[126]-1*workYaw.d[287]*1;
  residual += temp*temp;
  temp = workYaw.KKT[575]-workYaw.L[127]*workYaw.d[128]*workYaw.L[127]-1*workYaw.d[288]*1;
  residual += temp*temp;
  temp = workYaw.KKT[577]-workYaw.L[128]*workYaw.d[129]*workYaw.L[128]-1*workYaw.d[289]*1;
  residual += temp*temp;
  temp = workYaw.KKT[579]-workYaw.L[129]*workYaw.d[130]*workYaw.L[129]-1*workYaw.d[290]*1;
  residual += temp*temp;
  temp = workYaw.KKT[581]-workYaw.L[130]*workYaw.d[131]*workYaw.L[130]-1*workYaw.d[291]*1;
  residual += temp*temp;
  temp = workYaw.KKT[583]-workYaw.L[131]*workYaw.d[132]*workYaw.L[131]-1*workYaw.d[292]*1;
  residual += temp*temp;
  temp = workYaw.KKT[585]-workYaw.L[132]*workYaw.d[133]*workYaw.L[132]-1*workYaw.d[293]*1;
  residual += temp*temp;
  temp = workYaw.KKT[587]-workYaw.L[133]*workYaw.d[134]*workYaw.L[133]-1*workYaw.d[294]*1;
  residual += temp*temp;
  temp = workYaw.KKT[589]-workYaw.L[134]*workYaw.d[135]*workYaw.L[134]-1*workYaw.d[295]*1;
  residual += temp*temp;
  temp = workYaw.KKT[591]-workYaw.L[135]*workYaw.d[136]*workYaw.L[135]-1*workYaw.d[296]*1;
  residual += temp*temp;
  temp = workYaw.KKT[593]-workYaw.L[136]*workYaw.d[137]*workYaw.L[136]-1*workYaw.d[297]*1;
  residual += temp*temp;
  temp = workYaw.KKT[595]-workYaw.L[137]*workYaw.d[138]*workYaw.L[137]-1*workYaw.d[298]*1;
  residual += temp*temp;
  temp = workYaw.KKT[597]-workYaw.L[138]*workYaw.d[139]*workYaw.L[138]-1*workYaw.d[299]*1;
  residual += temp*temp;
  temp = workYaw.KKT[599]-workYaw.L[139]*workYaw.d[140]*workYaw.L[139]-1*workYaw.d[300]*1;
  residual += temp*temp;
  temp = workYaw.KKT[601]-workYaw.L[140]*workYaw.d[141]*workYaw.L[140]-1*workYaw.d[301]*1;
  residual += temp*temp;
  temp = workYaw.KKT[603]-workYaw.L[141]*workYaw.d[142]*workYaw.L[141]-1*workYaw.d[302]*1;
  residual += temp*temp;
  temp = workYaw.KKT[605]-workYaw.L[142]*workYaw.d[143]*workYaw.L[142]-1*workYaw.d[303]*1;
  residual += temp*temp;
  temp = workYaw.KKT[607]-workYaw.L[143]*workYaw.d[144]*workYaw.L[143]-1*workYaw.d[304]*1;
  residual += temp*temp;
  temp = workYaw.KKT[609]-workYaw.L[144]*workYaw.d[145]*workYaw.L[144]-1*workYaw.d[305]*1;
  residual += temp*temp;
  temp = workYaw.KKT[611]-workYaw.L[145]*workYaw.d[146]*workYaw.L[145]-1*workYaw.d[306]*1;
  residual += temp*temp;
  temp = workYaw.KKT[613]-workYaw.L[146]*workYaw.d[147]*workYaw.L[146]-1*workYaw.d[307]*1;
  residual += temp*temp;
  temp = workYaw.KKT[615]-workYaw.L[147]*workYaw.d[148]*workYaw.L[147]-1*workYaw.d[308]*1;
  residual += temp*temp;
  temp = workYaw.KKT[617]-workYaw.L[148]*workYaw.d[149]*workYaw.L[148]-1*workYaw.d[309]*1;
  residual += temp*temp;
  temp = workYaw.KKT[619]-workYaw.L[149]*workYaw.d[150]*workYaw.L[149]-1*workYaw.d[310]*1;
  residual += temp*temp;
  temp = workYaw.KKT[621]-workYaw.L[150]*workYaw.d[151]*workYaw.L[150]-1*workYaw.d[311]*1;
  residual += temp*temp;
  temp = workYaw.KKT[623]-workYaw.L[151]*workYaw.d[152]*workYaw.L[151]-1*workYaw.d[312]*1;
  residual += temp*temp;
  temp = workYaw.KKT[625]-workYaw.L[152]*workYaw.d[153]*workYaw.L[152]-1*workYaw.d[313]*1;
  residual += temp*temp;
  temp = workYaw.KKT[627]-workYaw.L[153]*workYaw.d[154]*workYaw.L[153]-1*workYaw.d[314]*1;
  residual += temp*temp;
  temp = workYaw.KKT[629]-workYaw.L[154]*workYaw.d[155]*workYaw.L[154]-1*workYaw.d[315]*1;
  residual += temp*temp;
  temp = workYaw.KKT[631]-workYaw.L[155]*workYaw.d[156]*workYaw.L[155]-1*workYaw.d[316]*1;
  residual += temp*temp;
  temp = workYaw.KKT[633]-workYaw.L[156]*workYaw.d[157]*workYaw.L[156]-1*workYaw.d[317]*1;
  residual += temp*temp;
  temp = workYaw.KKT[635]-workYaw.L[157]*workYaw.d[158]*workYaw.L[157]-1*workYaw.d[318]*1;
  residual += temp*temp;
  temp = workYaw.KKT[637]-workYaw.L[158]*workYaw.d[159]*workYaw.L[158]-1*workYaw.d[319]*1;
  residual += temp*temp;
  temp = workYaw.KKT[639]-workYaw.L[159]*workYaw.d[160]*workYaw.L[159]-1*workYaw.d[320]*1;
  residual += temp*temp;
  temp = workYaw.KKT[322]-1*workYaw.d[161]*workYaw.L[215];
  residual += temp*temp;
  temp = workYaw.KKT[324]-1*workYaw.d[162]*workYaw.L[229];
  residual += temp*temp;
  temp = workYaw.KKT[326]-1*workYaw.d[163]*workYaw.L[247];
  residual += temp*temp;
  temp = workYaw.KKT[328]-1*workYaw.d[164]*workYaw.L[267];
  residual += temp*temp;
  temp = workYaw.KKT[330]-1*workYaw.d[165]*workYaw.L[287];
  residual += temp*temp;
  temp = workYaw.KKT[332]-1*workYaw.d[166]*workYaw.L[307];
  residual += temp*temp;
  temp = workYaw.KKT[334]-1*workYaw.d[167]*workYaw.L[327];
  residual += temp*temp;
  temp = workYaw.KKT[336]-1*workYaw.d[168]*workYaw.L[347];
  residual += temp*temp;
  temp = workYaw.KKT[338]-1*workYaw.d[169]*workYaw.L[367];
  residual += temp*temp;
  temp = workYaw.KKT[340]-1*workYaw.d[170]*workYaw.L[387];
  residual += temp*temp;
  temp = workYaw.KKT[342]-1*workYaw.d[171]*workYaw.L[407];
  residual += temp*temp;
  temp = workYaw.KKT[344]-1*workYaw.d[172]*workYaw.L[427];
  residual += temp*temp;
  temp = workYaw.KKT[346]-1*workYaw.d[173]*workYaw.L[447];
  residual += temp*temp;
  temp = workYaw.KKT[348]-1*workYaw.d[174]*workYaw.L[467];
  residual += temp*temp;
  temp = workYaw.KKT[350]-1*workYaw.d[175]*workYaw.L[487];
  residual += temp*temp;
  temp = workYaw.KKT[352]-1*workYaw.d[176]*workYaw.L[507];
  residual += temp*temp;
  temp = workYaw.KKT[354]-1*workYaw.d[177]*workYaw.L[527];
  residual += temp*temp;
  temp = workYaw.KKT[356]-1*workYaw.d[178]*workYaw.L[547];
  residual += temp*temp;
  temp = workYaw.KKT[358]-1*workYaw.d[179]*workYaw.L[567];
  residual += temp*temp;
  temp = workYaw.KKT[360]-1*workYaw.d[180]*workYaw.L[587];
  residual += temp*temp;
  temp = workYaw.KKT[362]-1*workYaw.d[181]*workYaw.L[607];
  residual += temp*temp;
  temp = workYaw.KKT[364]-1*workYaw.d[182]*workYaw.L[627];
  residual += temp*temp;
  temp = workYaw.KKT[366]-1*workYaw.d[183]*workYaw.L[647];
  residual += temp*temp;
  temp = workYaw.KKT[368]-1*workYaw.d[184]*workYaw.L[667];
  residual += temp*temp;
  temp = workYaw.KKT[370]-1*workYaw.d[185]*workYaw.L[687];
  residual += temp*temp;
  temp = workYaw.KKT[372]-1*workYaw.d[186]*workYaw.L[707];
  residual += temp*temp;
  temp = workYaw.KKT[374]-1*workYaw.d[187]*workYaw.L[727];
  residual += temp*temp;
  temp = workYaw.KKT[376]-1*workYaw.d[188]*workYaw.L[747];
  residual += temp*temp;
  temp = workYaw.KKT[378]-1*workYaw.d[189]*workYaw.L[767];
  residual += temp*temp;
  temp = workYaw.KKT[380]-1*workYaw.d[190]*workYaw.L[787];
  residual += temp*temp;
  temp = workYaw.KKT[382]-1*workYaw.d[191]*workYaw.L[807];
  residual += temp*temp;
  temp = workYaw.KKT[384]-1*workYaw.d[192]*workYaw.L[827];
  residual += temp*temp;
  temp = workYaw.KKT[386]-1*workYaw.d[193]*workYaw.L[847];
  residual += temp*temp;
  temp = workYaw.KKT[388]-1*workYaw.d[194]*workYaw.L[867];
  residual += temp*temp;
  temp = workYaw.KKT[390]-1*workYaw.d[195]*workYaw.L[887];
  residual += temp*temp;
  temp = workYaw.KKT[392]-1*workYaw.d[196]*workYaw.L[907];
  residual += temp*temp;
  temp = workYaw.KKT[394]-1*workYaw.d[197]*workYaw.L[927];
  residual += temp*temp;
  temp = workYaw.KKT[396]-1*workYaw.d[198]*workYaw.L[951];
  residual += temp*temp;
  temp = workYaw.KKT[398]-1*workYaw.d[199]*workYaw.L[967];
  residual += temp*temp;
  temp = workYaw.KKT[400]-1*workYaw.d[200]*workYaw.L[166];
  residual += temp*temp;
  temp = workYaw.KKT[402]-1*workYaw.d[201]*workYaw.L[216];
  residual += temp*temp;
  temp = workYaw.KKT[404]-1*workYaw.d[202]*workYaw.L[230];
  residual += temp*temp;
  temp = workYaw.KKT[406]-1*workYaw.d[203]*workYaw.L[248];
  residual += temp*temp;
  temp = workYaw.KKT[408]-1*workYaw.d[204]*workYaw.L[268];
  residual += temp*temp;
  temp = workYaw.KKT[410]-1*workYaw.d[205]*workYaw.L[288];
  residual += temp*temp;
  temp = workYaw.KKT[412]-1*workYaw.d[206]*workYaw.L[308];
  residual += temp*temp;
  temp = workYaw.KKT[414]-1*workYaw.d[207]*workYaw.L[328];
  residual += temp*temp;
  temp = workYaw.KKT[416]-1*workYaw.d[208]*workYaw.L[348];
  residual += temp*temp;
  temp = workYaw.KKT[418]-1*workYaw.d[209]*workYaw.L[368];
  residual += temp*temp;
  temp = workYaw.KKT[420]-1*workYaw.d[210]*workYaw.L[388];
  residual += temp*temp;
  temp = workYaw.KKT[422]-1*workYaw.d[211]*workYaw.L[408];
  residual += temp*temp;
  temp = workYaw.KKT[424]-1*workYaw.d[212]*workYaw.L[428];
  residual += temp*temp;
  temp = workYaw.KKT[426]-1*workYaw.d[213]*workYaw.L[448];
  residual += temp*temp;
  temp = workYaw.KKT[428]-1*workYaw.d[214]*workYaw.L[468];
  residual += temp*temp;
  temp = workYaw.KKT[430]-1*workYaw.d[215]*workYaw.L[488];
  residual += temp*temp;
  temp = workYaw.KKT[432]-1*workYaw.d[216]*workYaw.L[508];
  residual += temp*temp;
  temp = workYaw.KKT[434]-1*workYaw.d[217]*workYaw.L[528];
  residual += temp*temp;
  temp = workYaw.KKT[436]-1*workYaw.d[218]*workYaw.L[548];
  residual += temp*temp;
  temp = workYaw.KKT[438]-1*workYaw.d[219]*workYaw.L[568];
  residual += temp*temp;
  temp = workYaw.KKT[440]-1*workYaw.d[220]*workYaw.L[588];
  residual += temp*temp;
  temp = workYaw.KKT[442]-1*workYaw.d[221]*workYaw.L[608];
  residual += temp*temp;
  temp = workYaw.KKT[444]-1*workYaw.d[222]*workYaw.L[628];
  residual += temp*temp;
  temp = workYaw.KKT[446]-1*workYaw.d[223]*workYaw.L[648];
  residual += temp*temp;
  temp = workYaw.KKT[448]-1*workYaw.d[224]*workYaw.L[668];
  residual += temp*temp;
  temp = workYaw.KKT[450]-1*workYaw.d[225]*workYaw.L[688];
  residual += temp*temp;
  temp = workYaw.KKT[452]-1*workYaw.d[226]*workYaw.L[708];
  residual += temp*temp;
  temp = workYaw.KKT[454]-1*workYaw.d[227]*workYaw.L[728];
  residual += temp*temp;
  temp = workYaw.KKT[456]-1*workYaw.d[228]*workYaw.L[748];
  residual += temp*temp;
  temp = workYaw.KKT[458]-1*workYaw.d[229]*workYaw.L[768];
  residual += temp*temp;
  temp = workYaw.KKT[460]-1*workYaw.d[230]*workYaw.L[788];
  residual += temp*temp;
  temp = workYaw.KKT[462]-1*workYaw.d[231]*workYaw.L[808];
  residual += temp*temp;
  temp = workYaw.KKT[464]-1*workYaw.d[232]*workYaw.L[828];
  residual += temp*temp;
  temp = workYaw.KKT[466]-1*workYaw.d[233]*workYaw.L[848];
  residual += temp*temp;
  temp = workYaw.KKT[468]-1*workYaw.d[234]*workYaw.L[868];
  residual += temp*temp;
  temp = workYaw.KKT[470]-1*workYaw.d[235]*workYaw.L[888];
  residual += temp*temp;
  temp = workYaw.KKT[472]-1*workYaw.d[236]*workYaw.L[908];
  residual += temp*temp;
  temp = workYaw.KKT[474]-1*workYaw.d[237]*workYaw.L[928];
  residual += temp*temp;
  temp = workYaw.KKT[476]-1*workYaw.d[238]*workYaw.L[952];
  residual += temp*temp;
  temp = workYaw.KKT[478]-1*workYaw.d[239]*workYaw.L[968];
  residual += temp*temp;
  temp = workYaw.KKT[480]-1*workYaw.d[240]*workYaw.L[167];
  residual += temp*temp;
  temp = workYaw.KKT[482]-1*workYaw.d[241]*workYaw.L[219];
  residual += temp*temp;
  temp = workYaw.KKT[484]-1*workYaw.d[242]*workYaw.L[232];
  residual += temp*temp;
  temp = workYaw.KKT[486]-1*workYaw.d[243]*workYaw.L[250];
  residual += temp*temp;
  temp = workYaw.KKT[488]-1*workYaw.d[244]*workYaw.L[270];
  residual += temp*temp;
  temp = workYaw.KKT[490]-1*workYaw.d[245]*workYaw.L[290];
  residual += temp*temp;
  temp = workYaw.KKT[492]-1*workYaw.d[246]*workYaw.L[310];
  residual += temp*temp;
  temp = workYaw.KKT[494]-1*workYaw.d[247]*workYaw.L[330];
  residual += temp*temp;
  temp = workYaw.KKT[496]-1*workYaw.d[248]*workYaw.L[350];
  residual += temp*temp;
  temp = workYaw.KKT[498]-1*workYaw.d[249]*workYaw.L[370];
  residual += temp*temp;
  temp = workYaw.KKT[500]-1*workYaw.d[250]*workYaw.L[390];
  residual += temp*temp;
  temp = workYaw.KKT[502]-1*workYaw.d[251]*workYaw.L[410];
  residual += temp*temp;
  temp = workYaw.KKT[504]-1*workYaw.d[252]*workYaw.L[430];
  residual += temp*temp;
  temp = workYaw.KKT[506]-1*workYaw.d[253]*workYaw.L[450];
  residual += temp*temp;
  temp = workYaw.KKT[508]-1*workYaw.d[254]*workYaw.L[470];
  residual += temp*temp;
  temp = workYaw.KKT[510]-1*workYaw.d[255]*workYaw.L[490];
  residual += temp*temp;
  temp = workYaw.KKT[512]-1*workYaw.d[256]*workYaw.L[510];
  residual += temp*temp;
  temp = workYaw.KKT[514]-1*workYaw.d[257]*workYaw.L[530];
  residual += temp*temp;
  temp = workYaw.KKT[516]-1*workYaw.d[258]*workYaw.L[550];
  residual += temp*temp;
  temp = workYaw.KKT[518]-1*workYaw.d[259]*workYaw.L[570];
  residual += temp*temp;
  temp = workYaw.KKT[520]-1*workYaw.d[260]*workYaw.L[590];
  residual += temp*temp;
  temp = workYaw.KKT[522]-1*workYaw.d[261]*workYaw.L[610];
  residual += temp*temp;
  temp = workYaw.KKT[524]-1*workYaw.d[262]*workYaw.L[630];
  residual += temp*temp;
  temp = workYaw.KKT[526]-1*workYaw.d[263]*workYaw.L[650];
  residual += temp*temp;
  temp = workYaw.KKT[528]-1*workYaw.d[264]*workYaw.L[670];
  residual += temp*temp;
  temp = workYaw.KKT[530]-1*workYaw.d[265]*workYaw.L[690];
  residual += temp*temp;
  temp = workYaw.KKT[532]-1*workYaw.d[266]*workYaw.L[710];
  residual += temp*temp;
  temp = workYaw.KKT[534]-1*workYaw.d[267]*workYaw.L[730];
  residual += temp*temp;
  temp = workYaw.KKT[536]-1*workYaw.d[268]*workYaw.L[750];
  residual += temp*temp;
  temp = workYaw.KKT[538]-1*workYaw.d[269]*workYaw.L[770];
  residual += temp*temp;
  temp = workYaw.KKT[540]-1*workYaw.d[270]*workYaw.L[790];
  residual += temp*temp;
  temp = workYaw.KKT[542]-1*workYaw.d[271]*workYaw.L[810];
  residual += temp*temp;
  temp = workYaw.KKT[544]-1*workYaw.d[272]*workYaw.L[830];
  residual += temp*temp;
  temp = workYaw.KKT[546]-1*workYaw.d[273]*workYaw.L[850];
  residual += temp*temp;
  temp = workYaw.KKT[548]-1*workYaw.d[274]*workYaw.L[870];
  residual += temp*temp;
  temp = workYaw.KKT[550]-1*workYaw.d[275]*workYaw.L[890];
  residual += temp*temp;
  temp = workYaw.KKT[552]-1*workYaw.d[276]*workYaw.L[910];
  residual += temp*temp;
  temp = workYaw.KKT[554]-1*workYaw.d[277]*workYaw.L[930];
  residual += temp*temp;
  temp = workYaw.KKT[556]-1*workYaw.d[278]*workYaw.L[956];
  residual += temp*temp;
  temp = workYaw.KKT[558]-1*workYaw.d[279]*workYaw.L[168];
  residual += temp*temp;
  temp = workYaw.KKT[560]-1*workYaw.d[280]*workYaw.L[161];
  residual += temp*temp;
  temp = workYaw.KKT[562]-1*workYaw.d[281]*workYaw.L[220];
  residual += temp*temp;
  temp = workYaw.KKT[564]-1*workYaw.d[282]*workYaw.L[233];
  residual += temp*temp;
  temp = workYaw.KKT[566]-1*workYaw.d[283]*workYaw.L[251];
  residual += temp*temp;
  temp = workYaw.KKT[568]-1*workYaw.d[284]*workYaw.L[271];
  residual += temp*temp;
  temp = workYaw.KKT[570]-1*workYaw.d[285]*workYaw.L[291];
  residual += temp*temp;
  temp = workYaw.KKT[572]-1*workYaw.d[286]*workYaw.L[311];
  residual += temp*temp;
  temp = workYaw.KKT[574]-1*workYaw.d[287]*workYaw.L[331];
  residual += temp*temp;
  temp = workYaw.KKT[576]-1*workYaw.d[288]*workYaw.L[351];
  residual += temp*temp;
  temp = workYaw.KKT[578]-1*workYaw.d[289]*workYaw.L[371];
  residual += temp*temp;
  temp = workYaw.KKT[580]-1*workYaw.d[290]*workYaw.L[391];
  residual += temp*temp;
  temp = workYaw.KKT[582]-1*workYaw.d[291]*workYaw.L[411];
  residual += temp*temp;
  temp = workYaw.KKT[584]-1*workYaw.d[292]*workYaw.L[431];
  residual += temp*temp;
  temp = workYaw.KKT[586]-1*workYaw.d[293]*workYaw.L[451];
  residual += temp*temp;
  temp = workYaw.KKT[588]-1*workYaw.d[294]*workYaw.L[471];
  residual += temp*temp;
  temp = workYaw.KKT[590]-1*workYaw.d[295]*workYaw.L[491];
  residual += temp*temp;
  temp = workYaw.KKT[592]-1*workYaw.d[296]*workYaw.L[511];
  residual += temp*temp;
  temp = workYaw.KKT[594]-1*workYaw.d[297]*workYaw.L[531];
  residual += temp*temp;
  temp = workYaw.KKT[596]-1*workYaw.d[298]*workYaw.L[551];
  residual += temp*temp;
  temp = workYaw.KKT[598]-1*workYaw.d[299]*workYaw.L[571];
  residual += temp*temp;
  temp = workYaw.KKT[600]-1*workYaw.d[300]*workYaw.L[591];
  residual += temp*temp;
  temp = workYaw.KKT[602]-1*workYaw.d[301]*workYaw.L[611];
  residual += temp*temp;
  temp = workYaw.KKT[604]-1*workYaw.d[302]*workYaw.L[631];
  residual += temp*temp;
  temp = workYaw.KKT[606]-1*workYaw.d[303]*workYaw.L[651];
  residual += temp*temp;
  temp = workYaw.KKT[608]-1*workYaw.d[304]*workYaw.L[671];
  residual += temp*temp;
  temp = workYaw.KKT[610]-1*workYaw.d[305]*workYaw.L[691];
  residual += temp*temp;
  temp = workYaw.KKT[612]-1*workYaw.d[306]*workYaw.L[711];
  residual += temp*temp;
  temp = workYaw.KKT[614]-1*workYaw.d[307]*workYaw.L[731];
  residual += temp*temp;
  temp = workYaw.KKT[616]-1*workYaw.d[308]*workYaw.L[751];
  residual += temp*temp;
  temp = workYaw.KKT[618]-1*workYaw.d[309]*workYaw.L[771];
  residual += temp*temp;
  temp = workYaw.KKT[620]-1*workYaw.d[310]*workYaw.L[791];
  residual += temp*temp;
  temp = workYaw.KKT[622]-1*workYaw.d[311]*workYaw.L[811];
  residual += temp*temp;
  temp = workYaw.KKT[624]-1*workYaw.d[312]*workYaw.L[831];
  residual += temp*temp;
  temp = workYaw.KKT[626]-1*workYaw.d[313]*workYaw.L[851];
  residual += temp*temp;
  temp = workYaw.KKT[628]-1*workYaw.d[314]*workYaw.L[871];
  residual += temp*temp;
  temp = workYaw.KKT[630]-1*workYaw.d[315]*workYaw.L[891];
  residual += temp*temp;
  temp = workYaw.KKT[632]-1*workYaw.d[316]*workYaw.L[911];
  residual += temp*temp;
  temp = workYaw.KKT[634]-1*workYaw.d[317]*workYaw.L[931];
  residual += temp*temp;
  temp = workYaw.KKT[636]-1*workYaw.d[318]*workYaw.L[957];
  residual += temp*temp;
  temp = workYaw.KKT[638]-1*workYaw.d[319]*workYaw.L[169];
  residual += temp*temp;
  temp = workYaw.KKT[640]-1*workYaw.d[320]*workYaw.L[162];
  residual += temp*temp;
  temp = workYaw.KKT[643]-workYaw.L[160]*workYaw.d[323]*1;
  residual += temp*temp;
  temp = workYaw.KKT[641]-1*workYaw.d[321]*workYaw.L[165];
  residual += temp*temp;
  temp = workYaw.KKT[642]-1*workYaw.d[322]*workYaw.L[217];
  residual += temp*temp;
  temp = workYaw.KKT[644]-1*workYaw.d[324]*workYaw.L[221];
  residual += temp*temp;
  temp = workYaw.KKT[646]-workYaw.L[172]*workYaw.d[325]*1;
  residual += temp*temp;
  temp = workYaw.KKT[727]-workYaw.L[171]*workYaw.d[366]*1;
  residual += temp*temp;
  temp = workYaw.KKT[816]-workYaw.L[226]*workYaw.d[411]*1;
  residual += temp*temp;
  temp = workYaw.KKT[737]-1*workYaw.d[371]*workYaw.L[222];
  residual += temp*temp;
  temp = workYaw.KKT[735]-1*workYaw.d[370]*workYaw.L[218];
  residual += temp*temp;
  temp = workYaw.KKT[818]-workYaw.L[227]*workYaw.d[412]*1;
  residual += temp*temp;
  temp = workYaw.KKT[736]-1*workYaw.d[370]*workYaw.L[223];
  residual += temp*temp;
  temp = workYaw.KKT[931]-1*workYaw.d[451]*workYaw.L[231];
  residual += temp*temp;
  temp = workYaw.KKT[738]-1*workYaw.d[371]*workYaw.L[234];
  residual += temp*temp;
  temp = workYaw.KKT[648]-workYaw.L[173]*workYaw.d[326]*1;
  residual += temp*temp;
  temp = workYaw.KKT[820]-workYaw.L[239]*workYaw.d[413]*1;
  residual += temp*temp;
  temp = workYaw.KKT[934]-workYaw.L[244]*workYaw.d[452]*1;
  residual += temp*temp;
  temp = workYaw.KKT[739]-1*workYaw.d[372]*workYaw.L[235];
  residual += temp*temp;
  temp = workYaw.KKT[933]-workYaw.L[242]*workYaw.d[452]*1-workYaw.L[241]*workYaw.d[451]*workYaw.L[231];
  residual += temp*temp;
  temp = workYaw.KKT[936]-workYaw.L[244]*workYaw.d[452]*workYaw.L[238]-workYaw.L[245]*workYaw.d[453]*1;
  residual += temp*temp;
  temp = workYaw.KKT[822]-workYaw.L[240]*workYaw.d[414]*1;
  residual += temp*temp;
  temp = workYaw.KKT[937]-1*workYaw.d[455]*workYaw.L[249];
  residual += temp*temp;
  temp = workYaw.KKT[740]-1*workYaw.d[372]*workYaw.L[252];
  residual += temp*temp;
  temp = workYaw.KKT[650]-workYaw.L[174]*workYaw.d[327]*1;
  residual += temp*temp;
  temp = workYaw.KKT[823]-workYaw.L[258]*workYaw.d[414]*1;
  residual += temp*temp;
  temp = workYaw.KKT[940]-workYaw.L[264]*workYaw.d[456]*1;
  residual += temp*temp;
  temp = workYaw.KKT[741]-1*workYaw.d[373]*workYaw.L[253];
  residual += temp*temp;
  temp = workYaw.KKT[939]-workYaw.L[262]*workYaw.d[456]*1-workYaw.L[261]*workYaw.d[455]*workYaw.L[249];
  residual += temp*temp;
  temp = workYaw.KKT[942]-workYaw.L[264]*workYaw.d[456]*workYaw.L[257]-workYaw.L[265]*workYaw.d[457]*1;
  residual += temp*temp;
  temp = workYaw.KKT[825]-workYaw.L[259]*workYaw.d[415]*1;
  residual += temp*temp;
  temp = workYaw.KKT[943]-1*workYaw.d[459]*workYaw.L[269];
  residual += temp*temp;
  temp = workYaw.KKT[742]-1*workYaw.d[373]*workYaw.L[272];
  residual += temp*temp;
  temp = workYaw.KKT[652]-workYaw.L[175]*workYaw.d[328]*1;
  residual += temp*temp;
  temp = workYaw.KKT[826]-workYaw.L[278]*workYaw.d[415]*1;
  residual += temp*temp;
  temp = workYaw.KKT[946]-workYaw.L[284]*workYaw.d[460]*1;
  residual += temp*temp;
  temp = workYaw.KKT[743]-1*workYaw.d[374]*workYaw.L[273];
  residual += temp*temp;
  temp = workYaw.KKT[945]-workYaw.L[282]*workYaw.d[460]*1-workYaw.L[281]*workYaw.d[459]*workYaw.L[269];
  residual += temp*temp;
  temp = workYaw.KKT[948]-workYaw.L[284]*workYaw.d[460]*workYaw.L[277]-workYaw.L[285]*workYaw.d[461]*1;
  residual += temp*temp;
  temp = workYaw.KKT[828]-workYaw.L[279]*workYaw.d[416]*1;
  residual += temp*temp;
  temp = workYaw.KKT[949]-1*workYaw.d[463]*workYaw.L[289];
  residual += temp*temp;
  temp = workYaw.KKT[744]-1*workYaw.d[374]*workYaw.L[292];
  residual += temp*temp;
  temp = workYaw.KKT[654]-workYaw.L[176]*workYaw.d[329]*1;
  residual += temp*temp;
  temp = workYaw.KKT[829]-workYaw.L[298]*workYaw.d[416]*1;
  residual += temp*temp;
  temp = workYaw.KKT[952]-workYaw.L[304]*workYaw.d[464]*1;
  residual += temp*temp;
  temp = workYaw.KKT[745]-1*workYaw.d[375]*workYaw.L[293];
  residual += temp*temp;
  temp = workYaw.KKT[951]-workYaw.L[302]*workYaw.d[464]*1-workYaw.L[301]*workYaw.d[463]*workYaw.L[289];
  residual += temp*temp;
  temp = workYaw.KKT[954]-workYaw.L[304]*workYaw.d[464]*workYaw.L[297]-workYaw.L[305]*workYaw.d[465]*1;
  residual += temp*temp;
  temp = workYaw.KKT[831]-workYaw.L[299]*workYaw.d[417]*1;
  residual += temp*temp;
  temp = workYaw.KKT[955]-1*workYaw.d[467]*workYaw.L[309];
  residual += temp*temp;
  temp = workYaw.KKT[746]-1*workYaw.d[375]*workYaw.L[312];
  residual += temp*temp;
  temp = workYaw.KKT[656]-workYaw.L[177]*workYaw.d[330]*1;
  residual += temp*temp;
  temp = workYaw.KKT[832]-workYaw.L[318]*workYaw.d[417]*1;
  residual += temp*temp;
  temp = workYaw.KKT[958]-workYaw.L[324]*workYaw.d[468]*1;
  residual += temp*temp;
  temp = workYaw.KKT[747]-1*workYaw.d[376]*workYaw.L[313];
  residual += temp*temp;
  temp = workYaw.KKT[957]-workYaw.L[322]*workYaw.d[468]*1-workYaw.L[321]*workYaw.d[467]*workYaw.L[309];
  residual += temp*temp;
  temp = workYaw.KKT[960]-workYaw.L[324]*workYaw.d[468]*workYaw.L[317]-workYaw.L[325]*workYaw.d[469]*1;
  residual += temp*temp;
  temp = workYaw.KKT[834]-workYaw.L[319]*workYaw.d[418]*1;
  residual += temp*temp;
  temp = workYaw.KKT[961]-1*workYaw.d[471]*workYaw.L[329];
  residual += temp*temp;
  temp = workYaw.KKT[748]-1*workYaw.d[376]*workYaw.L[332];
  residual += temp*temp;
  temp = workYaw.KKT[658]-workYaw.L[178]*workYaw.d[331]*1;
  residual += temp*temp;
  temp = workYaw.KKT[835]-workYaw.L[338]*workYaw.d[418]*1;
  residual += temp*temp;
  temp = workYaw.KKT[964]-workYaw.L[344]*workYaw.d[472]*1;
  residual += temp*temp;
  temp = workYaw.KKT[749]-1*workYaw.d[377]*workYaw.L[333];
  residual += temp*temp;
  temp = workYaw.KKT[963]-workYaw.L[342]*workYaw.d[472]*1-workYaw.L[341]*workYaw.d[471]*workYaw.L[329];
  residual += temp*temp;
  temp = workYaw.KKT[966]-workYaw.L[344]*workYaw.d[472]*workYaw.L[337]-workYaw.L[345]*workYaw.d[473]*1;
  residual += temp*temp;
  temp = workYaw.KKT[837]-workYaw.L[339]*workYaw.d[419]*1;
  residual += temp*temp;
  temp = workYaw.KKT[967]-1*workYaw.d[475]*workYaw.L[349];
  residual += temp*temp;
  temp = workYaw.KKT[750]-1*workYaw.d[377]*workYaw.L[352];
  residual += temp*temp;
  temp = workYaw.KKT[660]-workYaw.L[179]*workYaw.d[332]*1;
  residual += temp*temp;
  temp = workYaw.KKT[838]-workYaw.L[358]*workYaw.d[419]*1;
  residual += temp*temp;
  temp = workYaw.KKT[970]-workYaw.L[364]*workYaw.d[476]*1;
  residual += temp*temp;
  temp = workYaw.KKT[751]-1*workYaw.d[378]*workYaw.L[353];
  residual += temp*temp;
  temp = workYaw.KKT[969]-workYaw.L[362]*workYaw.d[476]*1-workYaw.L[361]*workYaw.d[475]*workYaw.L[349];
  residual += temp*temp;
  temp = workYaw.KKT[972]-workYaw.L[364]*workYaw.d[476]*workYaw.L[357]-workYaw.L[365]*workYaw.d[477]*1;
  residual += temp*temp;
  temp = workYaw.KKT[840]-workYaw.L[359]*workYaw.d[420]*1;
  residual += temp*temp;
  temp = workYaw.KKT[973]-1*workYaw.d[479]*workYaw.L[369];
  residual += temp*temp;
  temp = workYaw.KKT[752]-1*workYaw.d[378]*workYaw.L[372];
  residual += temp*temp;
  temp = workYaw.KKT[662]-workYaw.L[180]*workYaw.d[333]*1;
  residual += temp*temp;
  temp = workYaw.KKT[841]-workYaw.L[378]*workYaw.d[420]*1;
  residual += temp*temp;
  temp = workYaw.KKT[976]-workYaw.L[384]*workYaw.d[480]*1;
  residual += temp*temp;
  temp = workYaw.KKT[753]-1*workYaw.d[379]*workYaw.L[373];
  residual += temp*temp;
  temp = workYaw.KKT[975]-workYaw.L[382]*workYaw.d[480]*1-workYaw.L[381]*workYaw.d[479]*workYaw.L[369];
  residual += temp*temp;
  temp = workYaw.KKT[978]-workYaw.L[384]*workYaw.d[480]*workYaw.L[377]-workYaw.L[385]*workYaw.d[481]*1;
  residual += temp*temp;
  temp = workYaw.KKT[843]-workYaw.L[379]*workYaw.d[421]*1;
  residual += temp*temp;
  temp = workYaw.KKT[979]-1*workYaw.d[483]*workYaw.L[389];
  residual += temp*temp;
  temp = workYaw.KKT[754]-1*workYaw.d[379]*workYaw.L[392];
  residual += temp*temp;
  temp = workYaw.KKT[664]-workYaw.L[181]*workYaw.d[334]*1;
  residual += temp*temp;
  temp = workYaw.KKT[844]-workYaw.L[398]*workYaw.d[421]*1;
  residual += temp*temp;
  temp = workYaw.KKT[982]-workYaw.L[404]*workYaw.d[484]*1;
  residual += temp*temp;
  temp = workYaw.KKT[755]-1*workYaw.d[380]*workYaw.L[393];
  residual += temp*temp;
  temp = workYaw.KKT[981]-workYaw.L[402]*workYaw.d[484]*1-workYaw.L[401]*workYaw.d[483]*workYaw.L[389];
  residual += temp*temp;
  temp = workYaw.KKT[984]-workYaw.L[404]*workYaw.d[484]*workYaw.L[397]-workYaw.L[405]*workYaw.d[485]*1;
  residual += temp*temp;
  temp = workYaw.KKT[846]-workYaw.L[399]*workYaw.d[422]*1;
  residual += temp*temp;
  temp = workYaw.KKT[985]-1*workYaw.d[487]*workYaw.L[409];
  residual += temp*temp;
  temp = workYaw.KKT[756]-1*workYaw.d[380]*workYaw.L[412];
  residual += temp*temp;
  temp = workYaw.KKT[666]-workYaw.L[182]*workYaw.d[335]*1;
  residual += temp*temp;
  temp = workYaw.KKT[847]-workYaw.L[418]*workYaw.d[422]*1;
  residual += temp*temp;
  temp = workYaw.KKT[988]-workYaw.L[424]*workYaw.d[488]*1;
  residual += temp*temp;
  temp = workYaw.KKT[757]-1*workYaw.d[381]*workYaw.L[413];
  residual += temp*temp;
  temp = workYaw.KKT[987]-workYaw.L[422]*workYaw.d[488]*1-workYaw.L[421]*workYaw.d[487]*workYaw.L[409];
  residual += temp*temp;
  temp = workYaw.KKT[990]-workYaw.L[424]*workYaw.d[488]*workYaw.L[417]-workYaw.L[425]*workYaw.d[489]*1;
  residual += temp*temp;
  temp = workYaw.KKT[849]-workYaw.L[419]*workYaw.d[423]*1;
  residual += temp*temp;
  temp = workYaw.KKT[991]-1*workYaw.d[491]*workYaw.L[429];
  residual += temp*temp;
  temp = workYaw.KKT[758]-1*workYaw.d[381]*workYaw.L[432];
  residual += temp*temp;
  temp = workYaw.KKT[668]-workYaw.L[183]*workYaw.d[336]*1;
  residual += temp*temp;
  temp = workYaw.KKT[850]-workYaw.L[438]*workYaw.d[423]*1;
  residual += temp*temp;
  temp = workYaw.KKT[994]-workYaw.L[444]*workYaw.d[492]*1;
  residual += temp*temp;
  temp = workYaw.KKT[759]-1*workYaw.d[382]*workYaw.L[433];
  residual += temp*temp;
  temp = workYaw.KKT[993]-workYaw.L[442]*workYaw.d[492]*1-workYaw.L[441]*workYaw.d[491]*workYaw.L[429];
  residual += temp*temp;
  temp = workYaw.KKT[996]-workYaw.L[444]*workYaw.d[492]*workYaw.L[437]-workYaw.L[445]*workYaw.d[493]*1;
  residual += temp*temp;
  temp = workYaw.KKT[852]-workYaw.L[439]*workYaw.d[424]*1;
  residual += temp*temp;
  temp = workYaw.KKT[997]-1*workYaw.d[495]*workYaw.L[449];
  residual += temp*temp;
  temp = workYaw.KKT[760]-1*workYaw.d[382]*workYaw.L[452];
  residual += temp*temp;
  temp = workYaw.KKT[670]-workYaw.L[184]*workYaw.d[337]*1;
  residual += temp*temp;
  temp = workYaw.KKT[853]-workYaw.L[458]*workYaw.d[424]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1000]-workYaw.L[464]*workYaw.d[496]*1;
  residual += temp*temp;
  temp = workYaw.KKT[761]-1*workYaw.d[383]*workYaw.L[453];
  residual += temp*temp;
  temp = workYaw.KKT[999]-workYaw.L[462]*workYaw.d[496]*1-workYaw.L[461]*workYaw.d[495]*workYaw.L[449];
  residual += temp*temp;
  temp = workYaw.KKT[1002]-workYaw.L[464]*workYaw.d[496]*workYaw.L[457]-workYaw.L[465]*workYaw.d[497]*1;
  residual += temp*temp;
  temp = workYaw.KKT[855]-workYaw.L[459]*workYaw.d[425]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1003]-1*workYaw.d[499]*workYaw.L[469];
  residual += temp*temp;
  temp = workYaw.KKT[762]-1*workYaw.d[383]*workYaw.L[472];
  residual += temp*temp;
  temp = workYaw.KKT[672]-workYaw.L[185]*workYaw.d[338]*1;
  residual += temp*temp;
  temp = workYaw.KKT[856]-workYaw.L[478]*workYaw.d[425]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1006]-workYaw.L[484]*workYaw.d[500]*1;
  residual += temp*temp;
  temp = workYaw.KKT[763]-1*workYaw.d[384]*workYaw.L[473];
  residual += temp*temp;
  temp = workYaw.KKT[1005]-workYaw.L[482]*workYaw.d[500]*1-workYaw.L[481]*workYaw.d[499]*workYaw.L[469];
  residual += temp*temp;
  temp = workYaw.KKT[1008]-workYaw.L[484]*workYaw.d[500]*workYaw.L[477]-workYaw.L[485]*workYaw.d[501]*1;
  residual += temp*temp;
  temp = workYaw.KKT[858]-workYaw.L[479]*workYaw.d[426]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1009]-1*workYaw.d[503]*workYaw.L[489];
  residual += temp*temp;
  temp = workYaw.KKT[764]-1*workYaw.d[384]*workYaw.L[492];
  residual += temp*temp;
  temp = workYaw.KKT[674]-workYaw.L[186]*workYaw.d[339]*1;
  residual += temp*temp;
  temp = workYaw.KKT[859]-workYaw.L[498]*workYaw.d[426]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1012]-workYaw.L[504]*workYaw.d[504]*1;
  residual += temp*temp;
  temp = workYaw.KKT[765]-1*workYaw.d[385]*workYaw.L[493];
  residual += temp*temp;
  temp = workYaw.KKT[1011]-workYaw.L[502]*workYaw.d[504]*1-workYaw.L[501]*workYaw.d[503]*workYaw.L[489];
  residual += temp*temp;
  temp = workYaw.KKT[1014]-workYaw.L[504]*workYaw.d[504]*workYaw.L[497]-workYaw.L[505]*workYaw.d[505]*1;
  residual += temp*temp;
  temp = workYaw.KKT[861]-workYaw.L[499]*workYaw.d[427]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1015]-1*workYaw.d[507]*workYaw.L[509];
  residual += temp*temp;
  temp = workYaw.KKT[766]-1*workYaw.d[385]*workYaw.L[512];
  residual += temp*temp;
  temp = workYaw.KKT[676]-workYaw.L[187]*workYaw.d[340]*1;
  residual += temp*temp;
  temp = workYaw.KKT[862]-workYaw.L[518]*workYaw.d[427]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1018]-workYaw.L[524]*workYaw.d[508]*1;
  residual += temp*temp;
  temp = workYaw.KKT[767]-1*workYaw.d[386]*workYaw.L[513];
  residual += temp*temp;
  temp = workYaw.KKT[1017]-workYaw.L[522]*workYaw.d[508]*1-workYaw.L[521]*workYaw.d[507]*workYaw.L[509];
  residual += temp*temp;
  temp = workYaw.KKT[1020]-workYaw.L[524]*workYaw.d[508]*workYaw.L[517]-workYaw.L[525]*workYaw.d[509]*1;
  residual += temp*temp;
  temp = workYaw.KKT[864]-workYaw.L[519]*workYaw.d[428]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1021]-1*workYaw.d[511]*workYaw.L[529];
  residual += temp*temp;
  temp = workYaw.KKT[768]-1*workYaw.d[386]*workYaw.L[532];
  residual += temp*temp;
  temp = workYaw.KKT[678]-workYaw.L[188]*workYaw.d[341]*1;
  residual += temp*temp;
  temp = workYaw.KKT[865]-workYaw.L[538]*workYaw.d[428]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1024]-workYaw.L[544]*workYaw.d[512]*1;
  residual += temp*temp;
  temp = workYaw.KKT[769]-1*workYaw.d[387]*workYaw.L[533];
  residual += temp*temp;
  temp = workYaw.KKT[1023]-workYaw.L[542]*workYaw.d[512]*1-workYaw.L[541]*workYaw.d[511]*workYaw.L[529];
  residual += temp*temp;
  temp = workYaw.KKT[1026]-workYaw.L[544]*workYaw.d[512]*workYaw.L[537]-workYaw.L[545]*workYaw.d[513]*1;
  residual += temp*temp;
  temp = workYaw.KKT[867]-workYaw.L[539]*workYaw.d[429]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1027]-1*workYaw.d[515]*workYaw.L[549];
  residual += temp*temp;
  temp = workYaw.KKT[770]-1*workYaw.d[387]*workYaw.L[552];
  residual += temp*temp;
  temp = workYaw.KKT[680]-workYaw.L[189]*workYaw.d[342]*1;
  residual += temp*temp;
  temp = workYaw.KKT[868]-workYaw.L[558]*workYaw.d[429]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1030]-workYaw.L[564]*workYaw.d[516]*1;
  residual += temp*temp;
  temp = workYaw.KKT[771]-1*workYaw.d[388]*workYaw.L[553];
  residual += temp*temp;
  temp = workYaw.KKT[1029]-workYaw.L[562]*workYaw.d[516]*1-workYaw.L[561]*workYaw.d[515]*workYaw.L[549];
  residual += temp*temp;
  temp = workYaw.KKT[1032]-workYaw.L[564]*workYaw.d[516]*workYaw.L[557]-workYaw.L[565]*workYaw.d[517]*1;
  residual += temp*temp;
  temp = workYaw.KKT[870]-workYaw.L[559]*workYaw.d[430]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1033]-1*workYaw.d[519]*workYaw.L[569];
  residual += temp*temp;
  temp = workYaw.KKT[772]-1*workYaw.d[388]*workYaw.L[572];
  residual += temp*temp;
  temp = workYaw.KKT[682]-workYaw.L[190]*workYaw.d[343]*1;
  residual += temp*temp;
  temp = workYaw.KKT[871]-workYaw.L[578]*workYaw.d[430]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1036]-workYaw.L[584]*workYaw.d[520]*1;
  residual += temp*temp;
  temp = workYaw.KKT[773]-1*workYaw.d[389]*workYaw.L[573];
  residual += temp*temp;
  temp = workYaw.KKT[1035]-workYaw.L[582]*workYaw.d[520]*1-workYaw.L[581]*workYaw.d[519]*workYaw.L[569];
  residual += temp*temp;
  temp = workYaw.KKT[1038]-workYaw.L[584]*workYaw.d[520]*workYaw.L[577]-workYaw.L[585]*workYaw.d[521]*1;
  residual += temp*temp;
  temp = workYaw.KKT[873]-workYaw.L[579]*workYaw.d[431]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1039]-1*workYaw.d[523]*workYaw.L[589];
  residual += temp*temp;
  temp = workYaw.KKT[774]-1*workYaw.d[389]*workYaw.L[592];
  residual += temp*temp;
  temp = workYaw.KKT[684]-workYaw.L[191]*workYaw.d[344]*1;
  residual += temp*temp;
  temp = workYaw.KKT[874]-workYaw.L[598]*workYaw.d[431]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1042]-workYaw.L[604]*workYaw.d[524]*1;
  residual += temp*temp;
  temp = workYaw.KKT[775]-1*workYaw.d[390]*workYaw.L[593];
  residual += temp*temp;
  temp = workYaw.KKT[1041]-workYaw.L[602]*workYaw.d[524]*1-workYaw.L[601]*workYaw.d[523]*workYaw.L[589];
  residual += temp*temp;
  temp = workYaw.KKT[1044]-workYaw.L[604]*workYaw.d[524]*workYaw.L[597]-workYaw.L[605]*workYaw.d[525]*1;
  residual += temp*temp;
  temp = workYaw.KKT[876]-workYaw.L[599]*workYaw.d[432]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1045]-1*workYaw.d[527]*workYaw.L[609];
  residual += temp*temp;
  temp = workYaw.KKT[776]-1*workYaw.d[390]*workYaw.L[612];
  residual += temp*temp;
  temp = workYaw.KKT[686]-workYaw.L[192]*workYaw.d[345]*1;
  residual += temp*temp;
  temp = workYaw.KKT[877]-workYaw.L[618]*workYaw.d[432]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1048]-workYaw.L[624]*workYaw.d[528]*1;
  residual += temp*temp;
  temp = workYaw.KKT[777]-1*workYaw.d[391]*workYaw.L[613];
  residual += temp*temp;
  temp = workYaw.KKT[1047]-workYaw.L[622]*workYaw.d[528]*1-workYaw.L[621]*workYaw.d[527]*workYaw.L[609];
  residual += temp*temp;
  temp = workYaw.KKT[1050]-workYaw.L[624]*workYaw.d[528]*workYaw.L[617]-workYaw.L[625]*workYaw.d[529]*1;
  residual += temp*temp;
  temp = workYaw.KKT[879]-workYaw.L[619]*workYaw.d[433]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1051]-1*workYaw.d[531]*workYaw.L[629];
  residual += temp*temp;
  temp = workYaw.KKT[778]-1*workYaw.d[391]*workYaw.L[632];
  residual += temp*temp;
  temp = workYaw.KKT[688]-workYaw.L[193]*workYaw.d[346]*1;
  residual += temp*temp;
  temp = workYaw.KKT[880]-workYaw.L[638]*workYaw.d[433]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1054]-workYaw.L[644]*workYaw.d[532]*1;
  residual += temp*temp;
  temp = workYaw.KKT[779]-1*workYaw.d[392]*workYaw.L[633];
  residual += temp*temp;
  temp = workYaw.KKT[1053]-workYaw.L[642]*workYaw.d[532]*1-workYaw.L[641]*workYaw.d[531]*workYaw.L[629];
  residual += temp*temp;
  temp = workYaw.KKT[1056]-workYaw.L[644]*workYaw.d[532]*workYaw.L[637]-workYaw.L[645]*workYaw.d[533]*1;
  residual += temp*temp;
  temp = workYaw.KKT[882]-workYaw.L[639]*workYaw.d[434]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1057]-1*workYaw.d[535]*workYaw.L[649];
  residual += temp*temp;
  temp = workYaw.KKT[780]-1*workYaw.d[392]*workYaw.L[652];
  residual += temp*temp;
  temp = workYaw.KKT[690]-workYaw.L[194]*workYaw.d[347]*1;
  residual += temp*temp;
  temp = workYaw.KKT[883]-workYaw.L[658]*workYaw.d[434]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1060]-workYaw.L[664]*workYaw.d[536]*1;
  residual += temp*temp;
  temp = workYaw.KKT[781]-1*workYaw.d[393]*workYaw.L[653];
  residual += temp*temp;
  temp = workYaw.KKT[1059]-workYaw.L[662]*workYaw.d[536]*1-workYaw.L[661]*workYaw.d[535]*workYaw.L[649];
  residual += temp*temp;
  temp = workYaw.KKT[1062]-workYaw.L[664]*workYaw.d[536]*workYaw.L[657]-workYaw.L[665]*workYaw.d[537]*1;
  residual += temp*temp;
  temp = workYaw.KKT[885]-workYaw.L[659]*workYaw.d[435]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1063]-1*workYaw.d[539]*workYaw.L[669];
  residual += temp*temp;
  temp = workYaw.KKT[782]-1*workYaw.d[393]*workYaw.L[672];
  residual += temp*temp;
  temp = workYaw.KKT[692]-workYaw.L[195]*workYaw.d[348]*1;
  residual += temp*temp;
  temp = workYaw.KKT[886]-workYaw.L[678]*workYaw.d[435]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1066]-workYaw.L[684]*workYaw.d[540]*1;
  residual += temp*temp;
  temp = workYaw.KKT[783]-1*workYaw.d[394]*workYaw.L[673];
  residual += temp*temp;
  temp = workYaw.KKT[1065]-workYaw.L[682]*workYaw.d[540]*1-workYaw.L[681]*workYaw.d[539]*workYaw.L[669];
  residual += temp*temp;
  temp = workYaw.KKT[1068]-workYaw.L[684]*workYaw.d[540]*workYaw.L[677]-workYaw.L[685]*workYaw.d[541]*1;
  residual += temp*temp;
  temp = workYaw.KKT[888]-workYaw.L[679]*workYaw.d[436]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1069]-1*workYaw.d[543]*workYaw.L[689];
  residual += temp*temp;
  temp = workYaw.KKT[784]-1*workYaw.d[394]*workYaw.L[692];
  residual += temp*temp;
  temp = workYaw.KKT[694]-workYaw.L[196]*workYaw.d[349]*1;
  residual += temp*temp;
  temp = workYaw.KKT[889]-workYaw.L[698]*workYaw.d[436]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1072]-workYaw.L[704]*workYaw.d[544]*1;
  residual += temp*temp;
  temp = workYaw.KKT[785]-1*workYaw.d[395]*workYaw.L[693];
  residual += temp*temp;
  temp = workYaw.KKT[1071]-workYaw.L[702]*workYaw.d[544]*1-workYaw.L[701]*workYaw.d[543]*workYaw.L[689];
  residual += temp*temp;
  temp = workYaw.KKT[1074]-workYaw.L[704]*workYaw.d[544]*workYaw.L[697]-workYaw.L[705]*workYaw.d[545]*1;
  residual += temp*temp;
  temp = workYaw.KKT[891]-workYaw.L[699]*workYaw.d[437]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1075]-1*workYaw.d[547]*workYaw.L[709];
  residual += temp*temp;
  temp = workYaw.KKT[786]-1*workYaw.d[395]*workYaw.L[712];
  residual += temp*temp;
  temp = workYaw.KKT[696]-workYaw.L[197]*workYaw.d[350]*1;
  residual += temp*temp;
  temp = workYaw.KKT[892]-workYaw.L[718]*workYaw.d[437]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1078]-workYaw.L[724]*workYaw.d[548]*1;
  residual += temp*temp;
  temp = workYaw.KKT[787]-1*workYaw.d[396]*workYaw.L[713];
  residual += temp*temp;
  temp = workYaw.KKT[1077]-workYaw.L[722]*workYaw.d[548]*1-workYaw.L[721]*workYaw.d[547]*workYaw.L[709];
  residual += temp*temp;
  temp = workYaw.KKT[1080]-workYaw.L[724]*workYaw.d[548]*workYaw.L[717]-workYaw.L[725]*workYaw.d[549]*1;
  residual += temp*temp;
  temp = workYaw.KKT[894]-workYaw.L[719]*workYaw.d[438]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1081]-1*workYaw.d[551]*workYaw.L[729];
  residual += temp*temp;
  temp = workYaw.KKT[788]-1*workYaw.d[396]*workYaw.L[732];
  residual += temp*temp;
  temp = workYaw.KKT[698]-workYaw.L[198]*workYaw.d[351]*1;
  residual += temp*temp;
  temp = workYaw.KKT[895]-workYaw.L[738]*workYaw.d[438]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1084]-workYaw.L[744]*workYaw.d[552]*1;
  residual += temp*temp;
  temp = workYaw.KKT[789]-1*workYaw.d[397]*workYaw.L[733];
  residual += temp*temp;
  temp = workYaw.KKT[1083]-workYaw.L[742]*workYaw.d[552]*1-workYaw.L[741]*workYaw.d[551]*workYaw.L[729];
  residual += temp*temp;
  temp = workYaw.KKT[1086]-workYaw.L[744]*workYaw.d[552]*workYaw.L[737]-workYaw.L[745]*workYaw.d[553]*1;
  residual += temp*temp;
  temp = workYaw.KKT[897]-workYaw.L[739]*workYaw.d[439]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1087]-1*workYaw.d[555]*workYaw.L[749];
  residual += temp*temp;
  temp = workYaw.KKT[790]-1*workYaw.d[397]*workYaw.L[752];
  residual += temp*temp;
  temp = workYaw.KKT[700]-workYaw.L[199]*workYaw.d[352]*1;
  residual += temp*temp;
  temp = workYaw.KKT[898]-workYaw.L[758]*workYaw.d[439]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1090]-workYaw.L[764]*workYaw.d[556]*1;
  residual += temp*temp;
  temp = workYaw.KKT[791]-1*workYaw.d[398]*workYaw.L[753];
  residual += temp*temp;
  temp = workYaw.KKT[1089]-workYaw.L[762]*workYaw.d[556]*1-workYaw.L[761]*workYaw.d[555]*workYaw.L[749];
  residual += temp*temp;
  temp = workYaw.KKT[1092]-workYaw.L[764]*workYaw.d[556]*workYaw.L[757]-workYaw.L[765]*workYaw.d[557]*1;
  residual += temp*temp;
  temp = workYaw.KKT[900]-workYaw.L[759]*workYaw.d[440]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1093]-1*workYaw.d[559]*workYaw.L[769];
  residual += temp*temp;
  temp = workYaw.KKT[792]-1*workYaw.d[398]*workYaw.L[772];
  residual += temp*temp;
  temp = workYaw.KKT[702]-workYaw.L[200]*workYaw.d[353]*1;
  residual += temp*temp;
  temp = workYaw.KKT[901]-workYaw.L[778]*workYaw.d[440]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1096]-workYaw.L[784]*workYaw.d[560]*1;
  residual += temp*temp;
  temp = workYaw.KKT[793]-1*workYaw.d[399]*workYaw.L[773];
  residual += temp*temp;
  temp = workYaw.KKT[1095]-workYaw.L[782]*workYaw.d[560]*1-workYaw.L[781]*workYaw.d[559]*workYaw.L[769];
  residual += temp*temp;
  temp = workYaw.KKT[1098]-workYaw.L[784]*workYaw.d[560]*workYaw.L[777]-workYaw.L[785]*workYaw.d[561]*1;
  residual += temp*temp;
  temp = workYaw.KKT[903]-workYaw.L[779]*workYaw.d[441]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1099]-1*workYaw.d[563]*workYaw.L[789];
  residual += temp*temp;
  temp = workYaw.KKT[794]-1*workYaw.d[399]*workYaw.L[792];
  residual += temp*temp;
  temp = workYaw.KKT[704]-workYaw.L[201]*workYaw.d[354]*1;
  residual += temp*temp;
  temp = workYaw.KKT[904]-workYaw.L[798]*workYaw.d[441]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1102]-workYaw.L[804]*workYaw.d[564]*1;
  residual += temp*temp;
  temp = workYaw.KKT[795]-1*workYaw.d[400]*workYaw.L[793];
  residual += temp*temp;
  temp = workYaw.KKT[1101]-workYaw.L[802]*workYaw.d[564]*1-workYaw.L[801]*workYaw.d[563]*workYaw.L[789];
  residual += temp*temp;
  temp = workYaw.KKT[1104]-workYaw.L[804]*workYaw.d[564]*workYaw.L[797]-workYaw.L[805]*workYaw.d[565]*1;
  residual += temp*temp;
  temp = workYaw.KKT[906]-workYaw.L[799]*workYaw.d[442]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1105]-1*workYaw.d[567]*workYaw.L[809];
  residual += temp*temp;
  temp = workYaw.KKT[796]-1*workYaw.d[400]*workYaw.L[812];
  residual += temp*temp;
  temp = workYaw.KKT[706]-workYaw.L[202]*workYaw.d[355]*1;
  residual += temp*temp;
  temp = workYaw.KKT[907]-workYaw.L[818]*workYaw.d[442]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1108]-workYaw.L[824]*workYaw.d[568]*1;
  residual += temp*temp;
  temp = workYaw.KKT[797]-1*workYaw.d[401]*workYaw.L[813];
  residual += temp*temp;
  temp = workYaw.KKT[1107]-workYaw.L[822]*workYaw.d[568]*1-workYaw.L[821]*workYaw.d[567]*workYaw.L[809];
  residual += temp*temp;
  temp = workYaw.KKT[1110]-workYaw.L[824]*workYaw.d[568]*workYaw.L[817]-workYaw.L[825]*workYaw.d[569]*1;
  residual += temp*temp;
  temp = workYaw.KKT[909]-workYaw.L[819]*workYaw.d[443]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1111]-1*workYaw.d[571]*workYaw.L[829];
  residual += temp*temp;
  temp = workYaw.KKT[798]-1*workYaw.d[401]*workYaw.L[832];
  residual += temp*temp;
  temp = workYaw.KKT[708]-workYaw.L[203]*workYaw.d[356]*1;
  residual += temp*temp;
  temp = workYaw.KKT[910]-workYaw.L[838]*workYaw.d[443]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1114]-workYaw.L[844]*workYaw.d[572]*1;
  residual += temp*temp;
  temp = workYaw.KKT[799]-1*workYaw.d[402]*workYaw.L[833];
  residual += temp*temp;
  temp = workYaw.KKT[1113]-workYaw.L[842]*workYaw.d[572]*1-workYaw.L[841]*workYaw.d[571]*workYaw.L[829];
  residual += temp*temp;
  temp = workYaw.KKT[1116]-workYaw.L[844]*workYaw.d[572]*workYaw.L[837]-workYaw.L[845]*workYaw.d[573]*1;
  residual += temp*temp;
  temp = workYaw.KKT[912]-workYaw.L[839]*workYaw.d[444]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1117]-1*workYaw.d[575]*workYaw.L[849];
  residual += temp*temp;
  temp = workYaw.KKT[800]-1*workYaw.d[402]*workYaw.L[852];
  residual += temp*temp;
  temp = workYaw.KKT[710]-workYaw.L[204]*workYaw.d[357]*1;
  residual += temp*temp;
  temp = workYaw.KKT[913]-workYaw.L[858]*workYaw.d[444]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1120]-workYaw.L[864]*workYaw.d[576]*1;
  residual += temp*temp;
  temp = workYaw.KKT[801]-1*workYaw.d[403]*workYaw.L[853];
  residual += temp*temp;
  temp = workYaw.KKT[1119]-workYaw.L[862]*workYaw.d[576]*1-workYaw.L[861]*workYaw.d[575]*workYaw.L[849];
  residual += temp*temp;
  temp = workYaw.KKT[1122]-workYaw.L[864]*workYaw.d[576]*workYaw.L[857]-workYaw.L[865]*workYaw.d[577]*1;
  residual += temp*temp;
  temp = workYaw.KKT[915]-workYaw.L[859]*workYaw.d[445]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1123]-1*workYaw.d[579]*workYaw.L[869];
  residual += temp*temp;
  temp = workYaw.KKT[802]-1*workYaw.d[403]*workYaw.L[872];
  residual += temp*temp;
  temp = workYaw.KKT[712]-workYaw.L[205]*workYaw.d[358]*1;
  residual += temp*temp;
  temp = workYaw.KKT[916]-workYaw.L[878]*workYaw.d[445]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1126]-workYaw.L[884]*workYaw.d[580]*1;
  residual += temp*temp;
  temp = workYaw.KKT[803]-1*workYaw.d[404]*workYaw.L[873];
  residual += temp*temp;
  temp = workYaw.KKT[1125]-workYaw.L[882]*workYaw.d[580]*1-workYaw.L[881]*workYaw.d[579]*workYaw.L[869];
  residual += temp*temp;
  temp = workYaw.KKT[1128]-workYaw.L[884]*workYaw.d[580]*workYaw.L[877]-workYaw.L[885]*workYaw.d[581]*1;
  residual += temp*temp;
  temp = workYaw.KKT[918]-workYaw.L[879]*workYaw.d[446]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1129]-1*workYaw.d[583]*workYaw.L[889];
  residual += temp*temp;
  temp = workYaw.KKT[804]-1*workYaw.d[404]*workYaw.L[892];
  residual += temp*temp;
  temp = workYaw.KKT[714]-workYaw.L[206]*workYaw.d[359]*1;
  residual += temp*temp;
  temp = workYaw.KKT[919]-workYaw.L[898]*workYaw.d[446]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1132]-workYaw.L[904]*workYaw.d[584]*1;
  residual += temp*temp;
  temp = workYaw.KKT[805]-1*workYaw.d[405]*workYaw.L[893];
  residual += temp*temp;
  temp = workYaw.KKT[1131]-workYaw.L[902]*workYaw.d[584]*1-workYaw.L[901]*workYaw.d[583]*workYaw.L[889];
  residual += temp*temp;
  temp = workYaw.KKT[1134]-workYaw.L[904]*workYaw.d[584]*workYaw.L[897]-workYaw.L[905]*workYaw.d[585]*1;
  residual += temp*temp;
  temp = workYaw.KKT[921]-workYaw.L[899]*workYaw.d[447]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1135]-1*workYaw.d[587]*workYaw.L[909];
  residual += temp*temp;
  temp = workYaw.KKT[806]-1*workYaw.d[405]*workYaw.L[912];
  residual += temp*temp;
  temp = workYaw.KKT[716]-workYaw.L[207]*workYaw.d[360]*1;
  residual += temp*temp;
  temp = workYaw.KKT[922]-workYaw.L[918]*workYaw.d[447]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1138]-workYaw.L[924]*workYaw.d[588]*1;
  residual += temp*temp;
  temp = workYaw.KKT[807]-1*workYaw.d[406]*workYaw.L[913];
  residual += temp*temp;
  temp = workYaw.KKT[1137]-workYaw.L[922]*workYaw.d[588]*1-workYaw.L[921]*workYaw.d[587]*workYaw.L[909];
  residual += temp*temp;
  temp = workYaw.KKT[1140]-workYaw.L[924]*workYaw.d[588]*workYaw.L[917]-workYaw.L[925]*workYaw.d[589]*1;
  residual += temp*temp;
  temp = workYaw.KKT[924]-workYaw.L[919]*workYaw.d[448]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1141]-1*workYaw.d[591]*workYaw.L[929];
  residual += temp*temp;
  temp = workYaw.KKT[808]-1*workYaw.d[406]*workYaw.L[932];
  residual += temp*temp;
  temp = workYaw.KKT[718]-workYaw.L[208]*workYaw.d[361]*1;
  residual += temp*temp;
  temp = workYaw.KKT[925]-workYaw.L[938]*workYaw.d[448]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1144]-workYaw.L[944]*workYaw.d[592]*1;
  residual += temp*temp;
  temp = workYaw.KKT[809]-1*workYaw.d[407]*workYaw.L[933];
  residual += temp*temp;
  temp = workYaw.KKT[1143]-workYaw.L[942]*workYaw.d[592]*1-workYaw.L[941]*workYaw.d[591]*workYaw.L[929];
  residual += temp*temp;
  temp = workYaw.KKT[1146]-workYaw.L[944]*workYaw.d[592]*workYaw.L[937]-workYaw.L[945]*workYaw.d[593]*1;
  residual += temp*temp;
  temp = workYaw.KKT[927]-workYaw.L[939]*workYaw.d[449]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1147]-1*workYaw.d[595]*workYaw.L[953];
  residual += temp*temp;
  temp = workYaw.KKT[810]-1*workYaw.d[407]*workYaw.L[958];
  residual += temp*temp;
  temp = workYaw.KKT[720]-workYaw.L[209]*workYaw.d[362]*1;
  residual += temp*temp;
  temp = workYaw.KKT[928]-workYaw.L[947]*workYaw.d[449]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1149]-1*workYaw.d[597]*workYaw.L[955];
  residual += temp*temp;
  temp = workYaw.KKT[811]-1*workYaw.d[408]*workYaw.L[959];
  residual += temp*temp;
  temp = workYaw.KKT[1148]-1*workYaw.d[596]*workYaw.L[954]-workYaw.L[950]*workYaw.d[595]*workYaw.L[953];
  residual += temp*temp;
  temp = workYaw.KKT[1150]-1*workYaw.d[597]*workYaw.L[965];
  residual += temp*temp;
  temp = workYaw.KKT[930]-workYaw.L[948]*workYaw.d[450]*1;
  residual += temp*temp;
  temp = workYaw.KKT[1151]-1*workYaw.d[597]*workYaw.L[973];
  residual += temp*temp;
  temp = workYaw.KKT[733]-workYaw.L[210]*workYaw.d[369]*1;
  residual += temp*temp;
  temp = workYaw.KKT[722]-workYaw.L[163]*workYaw.d[363]*1;
  residual += temp*temp;
  temp = workYaw.KKT[812]-1*workYaw.d[409]*workYaw.L[225];
  residual += temp*temp;
  temp = workYaw.KKT[814]-1*workYaw.d[410]*workYaw.L[970];
  residual += temp*temp;
  temp = workYaw.KKT[725]-1*workYaw.d[365]*workYaw.L[170];
  residual += temp*temp;
  temp = workYaw.KKT[813]-1*workYaw.d[409]*workYaw.L[969];
  residual += temp*temp;
  temp = workYaw.KKT[734]-workYaw.L[213]*workYaw.d[369]*1;
  residual += temp*temp;
  temp = workYaw.KKT[729]-workYaw.L[211]*workYaw.d[367]*1;
  residual += temp*temp;
  temp = workYaw.KKT[731]-workYaw.L[212]*workYaw.d[368]*1;
  residual += temp*temp;
  temp = workYaw.KKT[724]-workYaw.L[164]*workYaw.d[364]*1;
  residual += temp*temp;
  return residual;
}
void matrix_multiply_yaw(double *result, double *source) {
  /* Finds result = A*source. */
  result[0] = workYaw.KKT[643]*source[483];
  result[1] = workYaw.KKT[645]*source[1]+workYaw.KKT[646]*source[486];
  result[2] = workYaw.KKT[647]*source[2]+workYaw.KKT[648]*source[489];
  result[3] = workYaw.KKT[649]*source[3]+workYaw.KKT[650]*source[492];
  result[4] = workYaw.KKT[651]*source[4]+workYaw.KKT[652]*source[495];
  result[5] = workYaw.KKT[653]*source[5]+workYaw.KKT[654]*source[498];
  result[6] = workYaw.KKT[655]*source[6]+workYaw.KKT[656]*source[501];
  result[7] = workYaw.KKT[657]*source[7]+workYaw.KKT[658]*source[504];
  result[8] = workYaw.KKT[659]*source[8]+workYaw.KKT[660]*source[507];
  result[9] = workYaw.KKT[661]*source[9]+workYaw.KKT[662]*source[510];
  result[10] = workYaw.KKT[663]*source[10]+workYaw.KKT[664]*source[513];
  result[11] = workYaw.KKT[665]*source[11]+workYaw.KKT[666]*source[516];
  result[12] = workYaw.KKT[667]*source[12]+workYaw.KKT[668]*source[519];
  result[13] = workYaw.KKT[669]*source[13]+workYaw.KKT[670]*source[522];
  result[14] = workYaw.KKT[671]*source[14]+workYaw.KKT[672]*source[525];
  result[15] = workYaw.KKT[673]*source[15]+workYaw.KKT[674]*source[528];
  result[16] = workYaw.KKT[675]*source[16]+workYaw.KKT[676]*source[531];
  result[17] = workYaw.KKT[677]*source[17]+workYaw.KKT[678]*source[534];
  result[18] = workYaw.KKT[679]*source[18]+workYaw.KKT[680]*source[537];
  result[19] = workYaw.KKT[681]*source[19]+workYaw.KKT[682]*source[540];
  result[20] = workYaw.KKT[683]*source[20]+workYaw.KKT[684]*source[543];
  result[21] = workYaw.KKT[685]*source[21]+workYaw.KKT[686]*source[546];
  result[22] = workYaw.KKT[687]*source[22]+workYaw.KKT[688]*source[549];
  result[23] = workYaw.KKT[689]*source[23]+workYaw.KKT[690]*source[552];
  result[24] = workYaw.KKT[691]*source[24]+workYaw.KKT[692]*source[555];
  result[25] = workYaw.KKT[693]*source[25]+workYaw.KKT[694]*source[558];
  result[26] = workYaw.KKT[695]*source[26]+workYaw.KKT[696]*source[561];
  result[27] = workYaw.KKT[697]*source[27]+workYaw.KKT[698]*source[564];
  result[28] = workYaw.KKT[699]*source[28]+workYaw.KKT[700]*source[567];
  result[29] = workYaw.KKT[701]*source[29]+workYaw.KKT[702]*source[570];
  result[30] = workYaw.KKT[703]*source[30]+workYaw.KKT[704]*source[573];
  result[31] = workYaw.KKT[705]*source[31]+workYaw.KKT[706]*source[576];
  result[32] = workYaw.KKT[707]*source[32]+workYaw.KKT[708]*source[579];
  result[33] = workYaw.KKT[709]*source[33]+workYaw.KKT[710]*source[582];
  result[34] = workYaw.KKT[711]*source[34]+workYaw.KKT[712]*source[585];
  result[35] = workYaw.KKT[713]*source[35]+workYaw.KKT[714]*source[588];
  result[36] = workYaw.KKT[715]*source[36]+workYaw.KKT[716]*source[591];
  result[37] = workYaw.KKT[717]*source[37]+workYaw.KKT[718]*source[594];
  result[38] = workYaw.KKT[719]*source[38]+workYaw.KKT[720]*source[597];
  result[39] = workYaw.KKT[721]*source[39]+workYaw.KKT[722]*source[600];
  result[40] = workYaw.KKT[0]*source[40];
  result[41] = workYaw.KKT[726]*source[41]+workYaw.KKT[641]*source[481]+workYaw.KKT[727]*source[484];
  result[42] = workYaw.KKT[815]*source[42]+workYaw.KKT[322]*source[321]+workYaw.KKT[402]*source[361]+workYaw.KKT[642]*source[482]+workYaw.KKT[816]*source[485]+workYaw.KKT[735]*source[484];
  result[43] = workYaw.KKT[817]*source[43]+workYaw.KKT[482]*source[401]+workYaw.KKT[562]*source[441]+workYaw.KKT[644]*source[483]+workYaw.KKT[737]*source[486]+workYaw.KKT[818]*source[485];
  result[44] = workYaw.KKT[819]*source[44]+workYaw.KKT[736]*source[484]+workYaw.KKT[820]*source[487];
  result[45] = workYaw.KKT[932]*source[45]+workYaw.KKT[324]*source[322]+workYaw.KKT[404]*source[362]+workYaw.KKT[931]*source[485]+workYaw.KKT[934]*source[488]+workYaw.KKT[933]*source[487];
  result[46] = workYaw.KKT[935]*source[46]+workYaw.KKT[484]*source[402]+workYaw.KKT[564]*source[442]+workYaw.KKT[738]*source[486]+workYaw.KKT[739]*source[489]+workYaw.KKT[936]*source[488];
  result[47] = workYaw.KKT[821]*source[47]+workYaw.KKT[822]*source[487]+workYaw.KKT[823]*source[490];
  result[48] = workYaw.KKT[938]*source[48]+workYaw.KKT[326]*source[323]+workYaw.KKT[406]*source[363]+workYaw.KKT[937]*source[488]+workYaw.KKT[940]*source[491]+workYaw.KKT[939]*source[490];
  result[49] = workYaw.KKT[941]*source[49]+workYaw.KKT[486]*source[403]+workYaw.KKT[566]*source[443]+workYaw.KKT[740]*source[489]+workYaw.KKT[741]*source[492]+workYaw.KKT[942]*source[491];
  result[50] = workYaw.KKT[824]*source[50]+workYaw.KKT[825]*source[490]+workYaw.KKT[826]*source[493];
  result[51] = workYaw.KKT[944]*source[51]+workYaw.KKT[328]*source[324]+workYaw.KKT[408]*source[364]+workYaw.KKT[943]*source[491]+workYaw.KKT[946]*source[494]+workYaw.KKT[945]*source[493];
  result[52] = workYaw.KKT[947]*source[52]+workYaw.KKT[488]*source[404]+workYaw.KKT[568]*source[444]+workYaw.KKT[742]*source[492]+workYaw.KKT[743]*source[495]+workYaw.KKT[948]*source[494];
  result[53] = workYaw.KKT[827]*source[53]+workYaw.KKT[828]*source[493]+workYaw.KKT[829]*source[496];
  result[54] = workYaw.KKT[950]*source[54]+workYaw.KKT[330]*source[325]+workYaw.KKT[410]*source[365]+workYaw.KKT[949]*source[494]+workYaw.KKT[952]*source[497]+workYaw.KKT[951]*source[496];
  result[55] = workYaw.KKT[953]*source[55]+workYaw.KKT[490]*source[405]+workYaw.KKT[570]*source[445]+workYaw.KKT[744]*source[495]+workYaw.KKT[745]*source[498]+workYaw.KKT[954]*source[497];
  result[56] = workYaw.KKT[830]*source[56]+workYaw.KKT[831]*source[496]+workYaw.KKT[832]*source[499];
  result[57] = workYaw.KKT[956]*source[57]+workYaw.KKT[332]*source[326]+workYaw.KKT[412]*source[366]+workYaw.KKT[955]*source[497]+workYaw.KKT[958]*source[500]+workYaw.KKT[957]*source[499];
  result[58] = workYaw.KKT[959]*source[58]+workYaw.KKT[492]*source[406]+workYaw.KKT[572]*source[446]+workYaw.KKT[746]*source[498]+workYaw.KKT[747]*source[501]+workYaw.KKT[960]*source[500];
  result[59] = workYaw.KKT[833]*source[59]+workYaw.KKT[834]*source[499]+workYaw.KKT[835]*source[502];
  result[60] = workYaw.KKT[962]*source[60]+workYaw.KKT[334]*source[327]+workYaw.KKT[414]*source[367]+workYaw.KKT[961]*source[500]+workYaw.KKT[964]*source[503]+workYaw.KKT[963]*source[502];
  result[61] = workYaw.KKT[965]*source[61]+workYaw.KKT[494]*source[407]+workYaw.KKT[574]*source[447]+workYaw.KKT[748]*source[501]+workYaw.KKT[749]*source[504]+workYaw.KKT[966]*source[503];
  result[62] = workYaw.KKT[836]*source[62]+workYaw.KKT[837]*source[502]+workYaw.KKT[838]*source[505];
  result[63] = workYaw.KKT[968]*source[63]+workYaw.KKT[336]*source[328]+workYaw.KKT[416]*source[368]+workYaw.KKT[967]*source[503]+workYaw.KKT[970]*source[506]+workYaw.KKT[969]*source[505];
  result[64] = workYaw.KKT[971]*source[64]+workYaw.KKT[496]*source[408]+workYaw.KKT[576]*source[448]+workYaw.KKT[750]*source[504]+workYaw.KKT[751]*source[507]+workYaw.KKT[972]*source[506];
  result[65] = workYaw.KKT[839]*source[65]+workYaw.KKT[840]*source[505]+workYaw.KKT[841]*source[508];
  result[66] = workYaw.KKT[974]*source[66]+workYaw.KKT[338]*source[329]+workYaw.KKT[418]*source[369]+workYaw.KKT[973]*source[506]+workYaw.KKT[976]*source[509]+workYaw.KKT[975]*source[508];
  result[67] = workYaw.KKT[977]*source[67]+workYaw.KKT[498]*source[409]+workYaw.KKT[578]*source[449]+workYaw.KKT[752]*source[507]+workYaw.KKT[753]*source[510]+workYaw.KKT[978]*source[509];
  result[68] = workYaw.KKT[842]*source[68]+workYaw.KKT[843]*source[508]+workYaw.KKT[844]*source[511];
  result[69] = workYaw.KKT[980]*source[69]+workYaw.KKT[340]*source[330]+workYaw.KKT[420]*source[370]+workYaw.KKT[979]*source[509]+workYaw.KKT[982]*source[512]+workYaw.KKT[981]*source[511];
  result[70] = workYaw.KKT[983]*source[70]+workYaw.KKT[500]*source[410]+workYaw.KKT[580]*source[450]+workYaw.KKT[754]*source[510]+workYaw.KKT[755]*source[513]+workYaw.KKT[984]*source[512];
  result[71] = workYaw.KKT[845]*source[71]+workYaw.KKT[846]*source[511]+workYaw.KKT[847]*source[514];
  result[72] = workYaw.KKT[986]*source[72]+workYaw.KKT[342]*source[331]+workYaw.KKT[422]*source[371]+workYaw.KKT[985]*source[512]+workYaw.KKT[988]*source[515]+workYaw.KKT[987]*source[514];
  result[73] = workYaw.KKT[989]*source[73]+workYaw.KKT[502]*source[411]+workYaw.KKT[582]*source[451]+workYaw.KKT[756]*source[513]+workYaw.KKT[757]*source[516]+workYaw.KKT[990]*source[515];
  result[74] = workYaw.KKT[848]*source[74]+workYaw.KKT[849]*source[514]+workYaw.KKT[850]*source[517];
  result[75] = workYaw.KKT[992]*source[75]+workYaw.KKT[344]*source[332]+workYaw.KKT[424]*source[372]+workYaw.KKT[991]*source[515]+workYaw.KKT[994]*source[518]+workYaw.KKT[993]*source[517];
  result[76] = workYaw.KKT[995]*source[76]+workYaw.KKT[504]*source[412]+workYaw.KKT[584]*source[452]+workYaw.KKT[758]*source[516]+workYaw.KKT[759]*source[519]+workYaw.KKT[996]*source[518];
  result[77] = workYaw.KKT[851]*source[77]+workYaw.KKT[852]*source[517]+workYaw.KKT[853]*source[520];
  result[78] = workYaw.KKT[998]*source[78]+workYaw.KKT[346]*source[333]+workYaw.KKT[426]*source[373]+workYaw.KKT[997]*source[518]+workYaw.KKT[1000]*source[521]+workYaw.KKT[999]*source[520];
  result[79] = workYaw.KKT[1001]*source[79]+workYaw.KKT[506]*source[413]+workYaw.KKT[586]*source[453]+workYaw.KKT[760]*source[519]+workYaw.KKT[761]*source[522]+workYaw.KKT[1002]*source[521];
  result[80] = workYaw.KKT[854]*source[80]+workYaw.KKT[855]*source[520]+workYaw.KKT[856]*source[523];
  result[81] = workYaw.KKT[1004]*source[81]+workYaw.KKT[348]*source[334]+workYaw.KKT[428]*source[374]+workYaw.KKT[1003]*source[521]+workYaw.KKT[1006]*source[524]+workYaw.KKT[1005]*source[523];
  result[82] = workYaw.KKT[1007]*source[82]+workYaw.KKT[508]*source[414]+workYaw.KKT[588]*source[454]+workYaw.KKT[762]*source[522]+workYaw.KKT[763]*source[525]+workYaw.KKT[1008]*source[524];
  result[83] = workYaw.KKT[857]*source[83]+workYaw.KKT[858]*source[523]+workYaw.KKT[859]*source[526];
  result[84] = workYaw.KKT[1010]*source[84]+workYaw.KKT[350]*source[335]+workYaw.KKT[430]*source[375]+workYaw.KKT[1009]*source[524]+workYaw.KKT[1012]*source[527]+workYaw.KKT[1011]*source[526];
  result[85] = workYaw.KKT[1013]*source[85]+workYaw.KKT[510]*source[415]+workYaw.KKT[590]*source[455]+workYaw.KKT[764]*source[525]+workYaw.KKT[765]*source[528]+workYaw.KKT[1014]*source[527];
  result[86] = workYaw.KKT[860]*source[86]+workYaw.KKT[861]*source[526]+workYaw.KKT[862]*source[529];
  result[87] = workYaw.KKT[1016]*source[87]+workYaw.KKT[352]*source[336]+workYaw.KKT[432]*source[376]+workYaw.KKT[1015]*source[527]+workYaw.KKT[1018]*source[530]+workYaw.KKT[1017]*source[529];
  result[88] = workYaw.KKT[1019]*source[88]+workYaw.KKT[512]*source[416]+workYaw.KKT[592]*source[456]+workYaw.KKT[766]*source[528]+workYaw.KKT[767]*source[531]+workYaw.KKT[1020]*source[530];
  result[89] = workYaw.KKT[863]*source[89]+workYaw.KKT[864]*source[529]+workYaw.KKT[865]*source[532];
  result[90] = workYaw.KKT[1022]*source[90]+workYaw.KKT[354]*source[337]+workYaw.KKT[434]*source[377]+workYaw.KKT[1021]*source[530]+workYaw.KKT[1024]*source[533]+workYaw.KKT[1023]*source[532];
  result[91] = workYaw.KKT[1025]*source[91]+workYaw.KKT[514]*source[417]+workYaw.KKT[594]*source[457]+workYaw.KKT[768]*source[531]+workYaw.KKT[769]*source[534]+workYaw.KKT[1026]*source[533];
  result[92] = workYaw.KKT[866]*source[92]+workYaw.KKT[867]*source[532]+workYaw.KKT[868]*source[535];
  result[93] = workYaw.KKT[1028]*source[93]+workYaw.KKT[356]*source[338]+workYaw.KKT[436]*source[378]+workYaw.KKT[1027]*source[533]+workYaw.KKT[1030]*source[536]+workYaw.KKT[1029]*source[535];
  result[94] = workYaw.KKT[1031]*source[94]+workYaw.KKT[516]*source[418]+workYaw.KKT[596]*source[458]+workYaw.KKT[770]*source[534]+workYaw.KKT[771]*source[537]+workYaw.KKT[1032]*source[536];
  result[95] = workYaw.KKT[869]*source[95]+workYaw.KKT[870]*source[535]+workYaw.KKT[871]*source[538];
  result[96] = workYaw.KKT[1034]*source[96]+workYaw.KKT[358]*source[339]+workYaw.KKT[438]*source[379]+workYaw.KKT[1033]*source[536]+workYaw.KKT[1036]*source[539]+workYaw.KKT[1035]*source[538];
  result[97] = workYaw.KKT[1037]*source[97]+workYaw.KKT[518]*source[419]+workYaw.KKT[598]*source[459]+workYaw.KKT[772]*source[537]+workYaw.KKT[773]*source[540]+workYaw.KKT[1038]*source[539];
  result[98] = workYaw.KKT[872]*source[98]+workYaw.KKT[873]*source[538]+workYaw.KKT[874]*source[541];
  result[99] = workYaw.KKT[1040]*source[99]+workYaw.KKT[360]*source[340]+workYaw.KKT[440]*source[380]+workYaw.KKT[1039]*source[539]+workYaw.KKT[1042]*source[542]+workYaw.KKT[1041]*source[541];
  result[100] = workYaw.KKT[1043]*source[100]+workYaw.KKT[520]*source[420]+workYaw.KKT[600]*source[460]+workYaw.KKT[774]*source[540]+workYaw.KKT[775]*source[543]+workYaw.KKT[1044]*source[542];
  result[101] = workYaw.KKT[875]*source[101]+workYaw.KKT[876]*source[541]+workYaw.KKT[877]*source[544];
  result[102] = workYaw.KKT[1046]*source[102]+workYaw.KKT[362]*source[341]+workYaw.KKT[442]*source[381]+workYaw.KKT[1045]*source[542]+workYaw.KKT[1048]*source[545]+workYaw.KKT[1047]*source[544];
  result[103] = workYaw.KKT[1049]*source[103]+workYaw.KKT[522]*source[421]+workYaw.KKT[602]*source[461]+workYaw.KKT[776]*source[543]+workYaw.KKT[777]*source[546]+workYaw.KKT[1050]*source[545];
  result[104] = workYaw.KKT[878]*source[104]+workYaw.KKT[879]*source[544]+workYaw.KKT[880]*source[547];
  result[105] = workYaw.KKT[1052]*source[105]+workYaw.KKT[364]*source[342]+workYaw.KKT[444]*source[382]+workYaw.KKT[1051]*source[545]+workYaw.KKT[1054]*source[548]+workYaw.KKT[1053]*source[547];
  result[106] = workYaw.KKT[1055]*source[106]+workYaw.KKT[524]*source[422]+workYaw.KKT[604]*source[462]+workYaw.KKT[778]*source[546]+workYaw.KKT[779]*source[549]+workYaw.KKT[1056]*source[548];
  result[107] = workYaw.KKT[881]*source[107]+workYaw.KKT[882]*source[547]+workYaw.KKT[883]*source[550];
  result[108] = workYaw.KKT[1058]*source[108]+workYaw.KKT[366]*source[343]+workYaw.KKT[446]*source[383]+workYaw.KKT[1057]*source[548]+workYaw.KKT[1060]*source[551]+workYaw.KKT[1059]*source[550];
  result[109] = workYaw.KKT[1061]*source[109]+workYaw.KKT[526]*source[423]+workYaw.KKT[606]*source[463]+workYaw.KKT[780]*source[549]+workYaw.KKT[781]*source[552]+workYaw.KKT[1062]*source[551];
  result[110] = workYaw.KKT[884]*source[110]+workYaw.KKT[885]*source[550]+workYaw.KKT[886]*source[553];
  result[111] = workYaw.KKT[1064]*source[111]+workYaw.KKT[368]*source[344]+workYaw.KKT[448]*source[384]+workYaw.KKT[1063]*source[551]+workYaw.KKT[1066]*source[554]+workYaw.KKT[1065]*source[553];
  result[112] = workYaw.KKT[1067]*source[112]+workYaw.KKT[528]*source[424]+workYaw.KKT[608]*source[464]+workYaw.KKT[782]*source[552]+workYaw.KKT[783]*source[555]+workYaw.KKT[1068]*source[554];
  result[113] = workYaw.KKT[887]*source[113]+workYaw.KKT[888]*source[553]+workYaw.KKT[889]*source[556];
  result[114] = workYaw.KKT[1070]*source[114]+workYaw.KKT[370]*source[345]+workYaw.KKT[450]*source[385]+workYaw.KKT[1069]*source[554]+workYaw.KKT[1072]*source[557]+workYaw.KKT[1071]*source[556];
  result[115] = workYaw.KKT[1073]*source[115]+workYaw.KKT[530]*source[425]+workYaw.KKT[610]*source[465]+workYaw.KKT[784]*source[555]+workYaw.KKT[785]*source[558]+workYaw.KKT[1074]*source[557];
  result[116] = workYaw.KKT[890]*source[116]+workYaw.KKT[891]*source[556]+workYaw.KKT[892]*source[559];
  result[117] = workYaw.KKT[1076]*source[117]+workYaw.KKT[372]*source[346]+workYaw.KKT[452]*source[386]+workYaw.KKT[1075]*source[557]+workYaw.KKT[1078]*source[560]+workYaw.KKT[1077]*source[559];
  result[118] = workYaw.KKT[1079]*source[118]+workYaw.KKT[532]*source[426]+workYaw.KKT[612]*source[466]+workYaw.KKT[786]*source[558]+workYaw.KKT[787]*source[561]+workYaw.KKT[1080]*source[560];
  result[119] = workYaw.KKT[893]*source[119]+workYaw.KKT[894]*source[559]+workYaw.KKT[895]*source[562];
  result[120] = workYaw.KKT[1082]*source[120]+workYaw.KKT[374]*source[347]+workYaw.KKT[454]*source[387]+workYaw.KKT[1081]*source[560]+workYaw.KKT[1084]*source[563]+workYaw.KKT[1083]*source[562];
  result[121] = workYaw.KKT[1085]*source[121]+workYaw.KKT[534]*source[427]+workYaw.KKT[614]*source[467]+workYaw.KKT[788]*source[561]+workYaw.KKT[789]*source[564]+workYaw.KKT[1086]*source[563];
  result[122] = workYaw.KKT[896]*source[122]+workYaw.KKT[897]*source[562]+workYaw.KKT[898]*source[565];
  result[123] = workYaw.KKT[1088]*source[123]+workYaw.KKT[376]*source[348]+workYaw.KKT[456]*source[388]+workYaw.KKT[1087]*source[563]+workYaw.KKT[1090]*source[566]+workYaw.KKT[1089]*source[565];
  result[124] = workYaw.KKT[1091]*source[124]+workYaw.KKT[536]*source[428]+workYaw.KKT[616]*source[468]+workYaw.KKT[790]*source[564]+workYaw.KKT[791]*source[567]+workYaw.KKT[1092]*source[566];
  result[125] = workYaw.KKT[899]*source[125]+workYaw.KKT[900]*source[565]+workYaw.KKT[901]*source[568];
  result[126] = workYaw.KKT[1094]*source[126]+workYaw.KKT[378]*source[349]+workYaw.KKT[458]*source[389]+workYaw.KKT[1093]*source[566]+workYaw.KKT[1096]*source[569]+workYaw.KKT[1095]*source[568];
  result[127] = workYaw.KKT[1097]*source[127]+workYaw.KKT[538]*source[429]+workYaw.KKT[618]*source[469]+workYaw.KKT[792]*source[567]+workYaw.KKT[793]*source[570]+workYaw.KKT[1098]*source[569];
  result[128] = workYaw.KKT[902]*source[128]+workYaw.KKT[903]*source[568]+workYaw.KKT[904]*source[571];
  result[129] = workYaw.KKT[1100]*source[129]+workYaw.KKT[380]*source[350]+workYaw.KKT[460]*source[390]+workYaw.KKT[1099]*source[569]+workYaw.KKT[1102]*source[572]+workYaw.KKT[1101]*source[571];
  result[130] = workYaw.KKT[1103]*source[130]+workYaw.KKT[540]*source[430]+workYaw.KKT[620]*source[470]+workYaw.KKT[794]*source[570]+workYaw.KKT[795]*source[573]+workYaw.KKT[1104]*source[572];
  result[131] = workYaw.KKT[905]*source[131]+workYaw.KKT[906]*source[571]+workYaw.KKT[907]*source[574];
  result[132] = workYaw.KKT[1106]*source[132]+workYaw.KKT[382]*source[351]+workYaw.KKT[462]*source[391]+workYaw.KKT[1105]*source[572]+workYaw.KKT[1108]*source[575]+workYaw.KKT[1107]*source[574];
  result[133] = workYaw.KKT[1109]*source[133]+workYaw.KKT[542]*source[431]+workYaw.KKT[622]*source[471]+workYaw.KKT[796]*source[573]+workYaw.KKT[797]*source[576]+workYaw.KKT[1110]*source[575];
  result[134] = workYaw.KKT[908]*source[134]+workYaw.KKT[909]*source[574]+workYaw.KKT[910]*source[577];
  result[135] = workYaw.KKT[1112]*source[135]+workYaw.KKT[384]*source[352]+workYaw.KKT[464]*source[392]+workYaw.KKT[1111]*source[575]+workYaw.KKT[1114]*source[578]+workYaw.KKT[1113]*source[577];
  result[136] = workYaw.KKT[1115]*source[136]+workYaw.KKT[544]*source[432]+workYaw.KKT[624]*source[472]+workYaw.KKT[798]*source[576]+workYaw.KKT[799]*source[579]+workYaw.KKT[1116]*source[578];
  result[137] = workYaw.KKT[911]*source[137]+workYaw.KKT[912]*source[577]+workYaw.KKT[913]*source[580];
  result[138] = workYaw.KKT[1118]*source[138]+workYaw.KKT[386]*source[353]+workYaw.KKT[466]*source[393]+workYaw.KKT[1117]*source[578]+workYaw.KKT[1120]*source[581]+workYaw.KKT[1119]*source[580];
  result[139] = workYaw.KKT[1121]*source[139]+workYaw.KKT[546]*source[433]+workYaw.KKT[626]*source[473]+workYaw.KKT[800]*source[579]+workYaw.KKT[801]*source[582]+workYaw.KKT[1122]*source[581];
  result[140] = workYaw.KKT[914]*source[140]+workYaw.KKT[915]*source[580]+workYaw.KKT[916]*source[583];
  result[141] = workYaw.KKT[1124]*source[141]+workYaw.KKT[388]*source[354]+workYaw.KKT[468]*source[394]+workYaw.KKT[1123]*source[581]+workYaw.KKT[1126]*source[584]+workYaw.KKT[1125]*source[583];
  result[142] = workYaw.KKT[1127]*source[142]+workYaw.KKT[548]*source[434]+workYaw.KKT[628]*source[474]+workYaw.KKT[802]*source[582]+workYaw.KKT[803]*source[585]+workYaw.KKT[1128]*source[584];
  result[143] = workYaw.KKT[917]*source[143]+workYaw.KKT[918]*source[583]+workYaw.KKT[919]*source[586];
  result[144] = workYaw.KKT[1130]*source[144]+workYaw.KKT[390]*source[355]+workYaw.KKT[470]*source[395]+workYaw.KKT[1129]*source[584]+workYaw.KKT[1132]*source[587]+workYaw.KKT[1131]*source[586];
  result[145] = workYaw.KKT[1133]*source[145]+workYaw.KKT[550]*source[435]+workYaw.KKT[630]*source[475]+workYaw.KKT[804]*source[585]+workYaw.KKT[805]*source[588]+workYaw.KKT[1134]*source[587];
  result[146] = workYaw.KKT[920]*source[146]+workYaw.KKT[921]*source[586]+workYaw.KKT[922]*source[589];
  result[147] = workYaw.KKT[1136]*source[147]+workYaw.KKT[392]*source[356]+workYaw.KKT[472]*source[396]+workYaw.KKT[1135]*source[587]+workYaw.KKT[1138]*source[590]+workYaw.KKT[1137]*source[589];
  result[148] = workYaw.KKT[1139]*source[148]+workYaw.KKT[552]*source[436]+workYaw.KKT[632]*source[476]+workYaw.KKT[806]*source[588]+workYaw.KKT[807]*source[591]+workYaw.KKT[1140]*source[590];
  result[149] = workYaw.KKT[923]*source[149]+workYaw.KKT[924]*source[589]+workYaw.KKT[925]*source[592];
  result[150] = workYaw.KKT[1142]*source[150]+workYaw.KKT[394]*source[357]+workYaw.KKT[474]*source[397]+workYaw.KKT[1141]*source[590]+workYaw.KKT[1144]*source[593]+workYaw.KKT[1143]*source[592];
  result[151] = workYaw.KKT[1145]*source[151]+workYaw.KKT[554]*source[437]+workYaw.KKT[634]*source[477]+workYaw.KKT[808]*source[591]+workYaw.KKT[809]*source[594]+workYaw.KKT[1146]*source[593];
  result[152] = workYaw.KKT[926]*source[152]+workYaw.KKT[927]*source[592]+workYaw.KKT[928]*source[595];
  result[153] = workYaw.KKT[1152]*source[153]+workYaw.KKT[396]*source[358]+workYaw.KKT[476]*source[398]+workYaw.KKT[1147]*source[593]+workYaw.KKT[1149]*source[596]+workYaw.KKT[1148]*source[595];
  result[154] = workYaw.KKT[1153]*source[154]+workYaw.KKT[556]*source[438]+workYaw.KKT[636]*source[478]+workYaw.KKT[810]*source[594]+workYaw.KKT[811]*source[597]+workYaw.KKT[1150]*source[596];
  result[155] = workYaw.KKT[929]*source[155]+workYaw.KKT[930]*source[595]+workYaw.KKT[812]*source[598];
  result[156] = workYaw.KKT[1154]*source[156]+workYaw.KKT[398]*source[359]+workYaw.KKT[478]*source[399]+workYaw.KKT[1151]*source[596]+workYaw.KKT[814]*source[599]+workYaw.KKT[813]*source[598];
  result[157] = workYaw.KKT[732]*source[157]+workYaw.KKT[558]*source[439]+workYaw.KKT[638]*source[479]+workYaw.KKT[733]*source[597]+workYaw.KKT[725]*source[600]+workYaw.KKT[734]*source[599];
  result[158] = workYaw.KKT[728]*source[158]+workYaw.KKT[729]*source[598];
  result[159] = workYaw.KKT[730]*source[159]+workYaw.KKT[400]*source[360]+workYaw.KKT[480]*source[400]+workYaw.KKT[731]*source[599];
  result[160] = workYaw.KKT[723]*source[160]+workYaw.KKT[560]*source[440]+workYaw.KKT[640]*source[480]+workYaw.KKT[724]*source[600];
  result[161] = workYaw.KKT[1]*source[161]+workYaw.KKT[2]*source[321];
  result[162] = workYaw.KKT[3]*source[162]+workYaw.KKT[4]*source[322];
  result[163] = workYaw.KKT[5]*source[163]+workYaw.KKT[6]*source[323];
  result[164] = workYaw.KKT[7]*source[164]+workYaw.KKT[8]*source[324];
  result[165] = workYaw.KKT[9]*source[165]+workYaw.KKT[10]*source[325];
  result[166] = workYaw.KKT[11]*source[166]+workYaw.KKT[12]*source[326];
  result[167] = workYaw.KKT[13]*source[167]+workYaw.KKT[14]*source[327];
  result[168] = workYaw.KKT[15]*source[168]+workYaw.KKT[16]*source[328];
  result[169] = workYaw.KKT[17]*source[169]+workYaw.KKT[18]*source[329];
  result[170] = workYaw.KKT[19]*source[170]+workYaw.KKT[20]*source[330];
  result[171] = workYaw.KKT[21]*source[171]+workYaw.KKT[22]*source[331];
  result[172] = workYaw.KKT[23]*source[172]+workYaw.KKT[24]*source[332];
  result[173] = workYaw.KKT[25]*source[173]+workYaw.KKT[26]*source[333];
  result[174] = workYaw.KKT[27]*source[174]+workYaw.KKT[28]*source[334];
  result[175] = workYaw.KKT[29]*source[175]+workYaw.KKT[30]*source[335];
  result[176] = workYaw.KKT[31]*source[176]+workYaw.KKT[32]*source[336];
  result[177] = workYaw.KKT[33]*source[177]+workYaw.KKT[34]*source[337];
  result[178] = workYaw.KKT[35]*source[178]+workYaw.KKT[36]*source[338];
  result[179] = workYaw.KKT[37]*source[179]+workYaw.KKT[38]*source[339];
  result[180] = workYaw.KKT[39]*source[180]+workYaw.KKT[40]*source[340];
  result[181] = workYaw.KKT[41]*source[181]+workYaw.KKT[42]*source[341];
  result[182] = workYaw.KKT[43]*source[182]+workYaw.KKT[44]*source[342];
  result[183] = workYaw.KKT[45]*source[183]+workYaw.KKT[46]*source[343];
  result[184] = workYaw.KKT[47]*source[184]+workYaw.KKT[48]*source[344];
  result[185] = workYaw.KKT[49]*source[185]+workYaw.KKT[50]*source[345];
  result[186] = workYaw.KKT[51]*source[186]+workYaw.KKT[52]*source[346];
  result[187] = workYaw.KKT[53]*source[187]+workYaw.KKT[54]*source[347];
  result[188] = workYaw.KKT[55]*source[188]+workYaw.KKT[56]*source[348];
  result[189] = workYaw.KKT[57]*source[189]+workYaw.KKT[58]*source[349];
  result[190] = workYaw.KKT[59]*source[190]+workYaw.KKT[60]*source[350];
  result[191] = workYaw.KKT[61]*source[191]+workYaw.KKT[62]*source[351];
  result[192] = workYaw.KKT[63]*source[192]+workYaw.KKT[64]*source[352];
  result[193] = workYaw.KKT[65]*source[193]+workYaw.KKT[66]*source[353];
  result[194] = workYaw.KKT[67]*source[194]+workYaw.KKT[68]*source[354];
  result[195] = workYaw.KKT[69]*source[195]+workYaw.KKT[70]*source[355];
  result[196] = workYaw.KKT[71]*source[196]+workYaw.KKT[72]*source[356];
  result[197] = workYaw.KKT[73]*source[197]+workYaw.KKT[74]*source[357];
  result[198] = workYaw.KKT[75]*source[198]+workYaw.KKT[76]*source[358];
  result[199] = workYaw.KKT[77]*source[199]+workYaw.KKT[78]*source[359];
  result[200] = workYaw.KKT[79]*source[200]+workYaw.KKT[80]*source[360];
  result[201] = workYaw.KKT[81]*source[201]+workYaw.KKT[82]*source[361];
  result[202] = workYaw.KKT[83]*source[202]+workYaw.KKT[84]*source[362];
  result[203] = workYaw.KKT[85]*source[203]+workYaw.KKT[86]*source[363];
  result[204] = workYaw.KKT[87]*source[204]+workYaw.KKT[88]*source[364];
  result[205] = workYaw.KKT[89]*source[205]+workYaw.KKT[90]*source[365];
  result[206] = workYaw.KKT[91]*source[206]+workYaw.KKT[92]*source[366];
  result[207] = workYaw.KKT[93]*source[207]+workYaw.KKT[94]*source[367];
  result[208] = workYaw.KKT[95]*source[208]+workYaw.KKT[96]*source[368];
  result[209] = workYaw.KKT[97]*source[209]+workYaw.KKT[98]*source[369];
  result[210] = workYaw.KKT[99]*source[210]+workYaw.KKT[100]*source[370];
  result[211] = workYaw.KKT[101]*source[211]+workYaw.KKT[102]*source[371];
  result[212] = workYaw.KKT[103]*source[212]+workYaw.KKT[104]*source[372];
  result[213] = workYaw.KKT[105]*source[213]+workYaw.KKT[106]*source[373];
  result[214] = workYaw.KKT[107]*source[214]+workYaw.KKT[108]*source[374];
  result[215] = workYaw.KKT[109]*source[215]+workYaw.KKT[110]*source[375];
  result[216] = workYaw.KKT[111]*source[216]+workYaw.KKT[112]*source[376];
  result[217] = workYaw.KKT[113]*source[217]+workYaw.KKT[114]*source[377];
  result[218] = workYaw.KKT[115]*source[218]+workYaw.KKT[116]*source[378];
  result[219] = workYaw.KKT[117]*source[219]+workYaw.KKT[118]*source[379];
  result[220] = workYaw.KKT[119]*source[220]+workYaw.KKT[120]*source[380];
  result[221] = workYaw.KKT[121]*source[221]+workYaw.KKT[122]*source[381];
  result[222] = workYaw.KKT[123]*source[222]+workYaw.KKT[124]*source[382];
  result[223] = workYaw.KKT[125]*source[223]+workYaw.KKT[126]*source[383];
  result[224] = workYaw.KKT[127]*source[224]+workYaw.KKT[128]*source[384];
  result[225] = workYaw.KKT[129]*source[225]+workYaw.KKT[130]*source[385];
  result[226] = workYaw.KKT[131]*source[226]+workYaw.KKT[132]*source[386];
  result[227] = workYaw.KKT[133]*source[227]+workYaw.KKT[134]*source[387];
  result[228] = workYaw.KKT[135]*source[228]+workYaw.KKT[136]*source[388];
  result[229] = workYaw.KKT[137]*source[229]+workYaw.KKT[138]*source[389];
  result[230] = workYaw.KKT[139]*source[230]+workYaw.KKT[140]*source[390];
  result[231] = workYaw.KKT[141]*source[231]+workYaw.KKT[142]*source[391];
  result[232] = workYaw.KKT[143]*source[232]+workYaw.KKT[144]*source[392];
  result[233] = workYaw.KKT[145]*source[233]+workYaw.KKT[146]*source[393];
  result[234] = workYaw.KKT[147]*source[234]+workYaw.KKT[148]*source[394];
  result[235] = workYaw.KKT[149]*source[235]+workYaw.KKT[150]*source[395];
  result[236] = workYaw.KKT[151]*source[236]+workYaw.KKT[152]*source[396];
  result[237] = workYaw.KKT[153]*source[237]+workYaw.KKT[154]*source[397];
  result[238] = workYaw.KKT[155]*source[238]+workYaw.KKT[156]*source[398];
  result[239] = workYaw.KKT[157]*source[239]+workYaw.KKT[158]*source[399];
  result[240] = workYaw.KKT[159]*source[240]+workYaw.KKT[160]*source[400];
  result[241] = workYaw.KKT[161]*source[241]+workYaw.KKT[162]*source[401];
  result[242] = workYaw.KKT[163]*source[242]+workYaw.KKT[164]*source[402];
  result[243] = workYaw.KKT[165]*source[243]+workYaw.KKT[166]*source[403];
  result[244] = workYaw.KKT[167]*source[244]+workYaw.KKT[168]*source[404];
  result[245] = workYaw.KKT[169]*source[245]+workYaw.KKT[170]*source[405];
  result[246] = workYaw.KKT[171]*source[246]+workYaw.KKT[172]*source[406];
  result[247] = workYaw.KKT[173]*source[247]+workYaw.KKT[174]*source[407];
  result[248] = workYaw.KKT[175]*source[248]+workYaw.KKT[176]*source[408];
  result[249] = workYaw.KKT[177]*source[249]+workYaw.KKT[178]*source[409];
  result[250] = workYaw.KKT[179]*source[250]+workYaw.KKT[180]*source[410];
  result[251] = workYaw.KKT[181]*source[251]+workYaw.KKT[182]*source[411];
  result[252] = workYaw.KKT[183]*source[252]+workYaw.KKT[184]*source[412];
  result[253] = workYaw.KKT[185]*source[253]+workYaw.KKT[186]*source[413];
  result[254] = workYaw.KKT[187]*source[254]+workYaw.KKT[188]*source[414];
  result[255] = workYaw.KKT[189]*source[255]+workYaw.KKT[190]*source[415];
  result[256] = workYaw.KKT[191]*source[256]+workYaw.KKT[192]*source[416];
  result[257] = workYaw.KKT[193]*source[257]+workYaw.KKT[194]*source[417];
  result[258] = workYaw.KKT[195]*source[258]+workYaw.KKT[196]*source[418];
  result[259] = workYaw.KKT[197]*source[259]+workYaw.KKT[198]*source[419];
  result[260] = workYaw.KKT[199]*source[260]+workYaw.KKT[200]*source[420];
  result[261] = workYaw.KKT[201]*source[261]+workYaw.KKT[202]*source[421];
  result[262] = workYaw.KKT[203]*source[262]+workYaw.KKT[204]*source[422];
  result[263] = workYaw.KKT[205]*source[263]+workYaw.KKT[206]*source[423];
  result[264] = workYaw.KKT[207]*source[264]+workYaw.KKT[208]*source[424];
  result[265] = workYaw.KKT[209]*source[265]+workYaw.KKT[210]*source[425];
  result[266] = workYaw.KKT[211]*source[266]+workYaw.KKT[212]*source[426];
  result[267] = workYaw.KKT[213]*source[267]+workYaw.KKT[214]*source[427];
  result[268] = workYaw.KKT[215]*source[268]+workYaw.KKT[216]*source[428];
  result[269] = workYaw.KKT[217]*source[269]+workYaw.KKT[218]*source[429];
  result[270] = workYaw.KKT[219]*source[270]+workYaw.KKT[220]*source[430];
  result[271] = workYaw.KKT[221]*source[271]+workYaw.KKT[222]*source[431];
  result[272] = workYaw.KKT[223]*source[272]+workYaw.KKT[224]*source[432];
  result[273] = workYaw.KKT[225]*source[273]+workYaw.KKT[226]*source[433];
  result[274] = workYaw.KKT[227]*source[274]+workYaw.KKT[228]*source[434];
  result[275] = workYaw.KKT[229]*source[275]+workYaw.KKT[230]*source[435];
  result[276] = workYaw.KKT[231]*source[276]+workYaw.KKT[232]*source[436];
  result[277] = workYaw.KKT[233]*source[277]+workYaw.KKT[234]*source[437];
  result[278] = workYaw.KKT[235]*source[278]+workYaw.KKT[236]*source[438];
  result[279] = workYaw.KKT[237]*source[279]+workYaw.KKT[238]*source[439];
  result[280] = workYaw.KKT[239]*source[280]+workYaw.KKT[240]*source[440];
  result[281] = workYaw.KKT[241]*source[281]+workYaw.KKT[242]*source[441];
  result[282] = workYaw.KKT[243]*source[282]+workYaw.KKT[244]*source[442];
  result[283] = workYaw.KKT[245]*source[283]+workYaw.KKT[246]*source[443];
  result[284] = workYaw.KKT[247]*source[284]+workYaw.KKT[248]*source[444];
  result[285] = workYaw.KKT[249]*source[285]+workYaw.KKT[250]*source[445];
  result[286] = workYaw.KKT[251]*source[286]+workYaw.KKT[252]*source[446];
  result[287] = workYaw.KKT[253]*source[287]+workYaw.KKT[254]*source[447];
  result[288] = workYaw.KKT[255]*source[288]+workYaw.KKT[256]*source[448];
  result[289] = workYaw.KKT[257]*source[289]+workYaw.KKT[258]*source[449];
  result[290] = workYaw.KKT[259]*source[290]+workYaw.KKT[260]*source[450];
  result[291] = workYaw.KKT[261]*source[291]+workYaw.KKT[262]*source[451];
  result[292] = workYaw.KKT[263]*source[292]+workYaw.KKT[264]*source[452];
  result[293] = workYaw.KKT[265]*source[293]+workYaw.KKT[266]*source[453];
  result[294] = workYaw.KKT[267]*source[294]+workYaw.KKT[268]*source[454];
  result[295] = workYaw.KKT[269]*source[295]+workYaw.KKT[270]*source[455];
  result[296] = workYaw.KKT[271]*source[296]+workYaw.KKT[272]*source[456];
  result[297] = workYaw.KKT[273]*source[297]+workYaw.KKT[274]*source[457];
  result[298] = workYaw.KKT[275]*source[298]+workYaw.KKT[276]*source[458];
  result[299] = workYaw.KKT[277]*source[299]+workYaw.KKT[278]*source[459];
  result[300] = workYaw.KKT[279]*source[300]+workYaw.KKT[280]*source[460];
  result[301] = workYaw.KKT[281]*source[301]+workYaw.KKT[282]*source[461];
  result[302] = workYaw.KKT[283]*source[302]+workYaw.KKT[284]*source[462];
  result[303] = workYaw.KKT[285]*source[303]+workYaw.KKT[286]*source[463];
  result[304] = workYaw.KKT[287]*source[304]+workYaw.KKT[288]*source[464];
  result[305] = workYaw.KKT[289]*source[305]+workYaw.KKT[290]*source[465];
  result[306] = workYaw.KKT[291]*source[306]+workYaw.KKT[292]*source[466];
  result[307] = workYaw.KKT[293]*source[307]+workYaw.KKT[294]*source[467];
  result[308] = workYaw.KKT[295]*source[308]+workYaw.KKT[296]*source[468];
  result[309] = workYaw.KKT[297]*source[309]+workYaw.KKT[298]*source[469];
  result[310] = workYaw.KKT[299]*source[310]+workYaw.KKT[300]*source[470];
  result[311] = workYaw.KKT[301]*source[311]+workYaw.KKT[302]*source[471];
  result[312] = workYaw.KKT[303]*source[312]+workYaw.KKT[304]*source[472];
  result[313] = workYaw.KKT[305]*source[313]+workYaw.KKT[306]*source[473];
  result[314] = workYaw.KKT[307]*source[314]+workYaw.KKT[308]*source[474];
  result[315] = workYaw.KKT[309]*source[315]+workYaw.KKT[310]*source[475];
  result[316] = workYaw.KKT[311]*source[316]+workYaw.KKT[312]*source[476];
  result[317] = workYaw.KKT[313]*source[317]+workYaw.KKT[314]*source[477];
  result[318] = workYaw.KKT[315]*source[318]+workYaw.KKT[316]*source[478];
  result[319] = workYaw.KKT[317]*source[319]+workYaw.KKT[318]*source[479];
  result[320] = workYaw.KKT[319]*source[320]+workYaw.KKT[320]*source[480];
  result[321] = workYaw.KKT[2]*source[161]+workYaw.KKT[321]*source[321]+workYaw.KKT[322]*source[42];
  result[322] = workYaw.KKT[4]*source[162]+workYaw.KKT[323]*source[322]+workYaw.KKT[324]*source[45];
  result[323] = workYaw.KKT[6]*source[163]+workYaw.KKT[325]*source[323]+workYaw.KKT[326]*source[48];
  result[324] = workYaw.KKT[8]*source[164]+workYaw.KKT[327]*source[324]+workYaw.KKT[328]*source[51];
  result[325] = workYaw.KKT[10]*source[165]+workYaw.KKT[329]*source[325]+workYaw.KKT[330]*source[54];
  result[326] = workYaw.KKT[12]*source[166]+workYaw.KKT[331]*source[326]+workYaw.KKT[332]*source[57];
  result[327] = workYaw.KKT[14]*source[167]+workYaw.KKT[333]*source[327]+workYaw.KKT[334]*source[60];
  result[328] = workYaw.KKT[16]*source[168]+workYaw.KKT[335]*source[328]+workYaw.KKT[336]*source[63];
  result[329] = workYaw.KKT[18]*source[169]+workYaw.KKT[337]*source[329]+workYaw.KKT[338]*source[66];
  result[330] = workYaw.KKT[20]*source[170]+workYaw.KKT[339]*source[330]+workYaw.KKT[340]*source[69];
  result[331] = workYaw.KKT[22]*source[171]+workYaw.KKT[341]*source[331]+workYaw.KKT[342]*source[72];
  result[332] = workYaw.KKT[24]*source[172]+workYaw.KKT[343]*source[332]+workYaw.KKT[344]*source[75];
  result[333] = workYaw.KKT[26]*source[173]+workYaw.KKT[345]*source[333]+workYaw.KKT[346]*source[78];
  result[334] = workYaw.KKT[28]*source[174]+workYaw.KKT[347]*source[334]+workYaw.KKT[348]*source[81];
  result[335] = workYaw.KKT[30]*source[175]+workYaw.KKT[349]*source[335]+workYaw.KKT[350]*source[84];
  result[336] = workYaw.KKT[32]*source[176]+workYaw.KKT[351]*source[336]+workYaw.KKT[352]*source[87];
  result[337] = workYaw.KKT[34]*source[177]+workYaw.KKT[353]*source[337]+workYaw.KKT[354]*source[90];
  result[338] = workYaw.KKT[36]*source[178]+workYaw.KKT[355]*source[338]+workYaw.KKT[356]*source[93];
  result[339] = workYaw.KKT[38]*source[179]+workYaw.KKT[357]*source[339]+workYaw.KKT[358]*source[96];
  result[340] = workYaw.KKT[40]*source[180]+workYaw.KKT[359]*source[340]+workYaw.KKT[360]*source[99];
  result[341] = workYaw.KKT[42]*source[181]+workYaw.KKT[361]*source[341]+workYaw.KKT[362]*source[102];
  result[342] = workYaw.KKT[44]*source[182]+workYaw.KKT[363]*source[342]+workYaw.KKT[364]*source[105];
  result[343] = workYaw.KKT[46]*source[183]+workYaw.KKT[365]*source[343]+workYaw.KKT[366]*source[108];
  result[344] = workYaw.KKT[48]*source[184]+workYaw.KKT[367]*source[344]+workYaw.KKT[368]*source[111];
  result[345] = workYaw.KKT[50]*source[185]+workYaw.KKT[369]*source[345]+workYaw.KKT[370]*source[114];
  result[346] = workYaw.KKT[52]*source[186]+workYaw.KKT[371]*source[346]+workYaw.KKT[372]*source[117];
  result[347] = workYaw.KKT[54]*source[187]+workYaw.KKT[373]*source[347]+workYaw.KKT[374]*source[120];
  result[348] = workYaw.KKT[56]*source[188]+workYaw.KKT[375]*source[348]+workYaw.KKT[376]*source[123];
  result[349] = workYaw.KKT[58]*source[189]+workYaw.KKT[377]*source[349]+workYaw.KKT[378]*source[126];
  result[350] = workYaw.KKT[60]*source[190]+workYaw.KKT[379]*source[350]+workYaw.KKT[380]*source[129];
  result[351] = workYaw.KKT[62]*source[191]+workYaw.KKT[381]*source[351]+workYaw.KKT[382]*source[132];
  result[352] = workYaw.KKT[64]*source[192]+workYaw.KKT[383]*source[352]+workYaw.KKT[384]*source[135];
  result[353] = workYaw.KKT[66]*source[193]+workYaw.KKT[385]*source[353]+workYaw.KKT[386]*source[138];
  result[354] = workYaw.KKT[68]*source[194]+workYaw.KKT[387]*source[354]+workYaw.KKT[388]*source[141];
  result[355] = workYaw.KKT[70]*source[195]+workYaw.KKT[389]*source[355]+workYaw.KKT[390]*source[144];
  result[356] = workYaw.KKT[72]*source[196]+workYaw.KKT[391]*source[356]+workYaw.KKT[392]*source[147];
  result[357] = workYaw.KKT[74]*source[197]+workYaw.KKT[393]*source[357]+workYaw.KKT[394]*source[150];
  result[358] = workYaw.KKT[76]*source[198]+workYaw.KKT[395]*source[358]+workYaw.KKT[396]*source[153];
  result[359] = workYaw.KKT[78]*source[199]+workYaw.KKT[397]*source[359]+workYaw.KKT[398]*source[156];
  result[360] = workYaw.KKT[80]*source[200]+workYaw.KKT[399]*source[360]+workYaw.KKT[400]*source[159];
  result[361] = workYaw.KKT[82]*source[201]+workYaw.KKT[401]*source[361]+workYaw.KKT[402]*source[42];
  result[362] = workYaw.KKT[84]*source[202]+workYaw.KKT[403]*source[362]+workYaw.KKT[404]*source[45];
  result[363] = workYaw.KKT[86]*source[203]+workYaw.KKT[405]*source[363]+workYaw.KKT[406]*source[48];
  result[364] = workYaw.KKT[88]*source[204]+workYaw.KKT[407]*source[364]+workYaw.KKT[408]*source[51];
  result[365] = workYaw.KKT[90]*source[205]+workYaw.KKT[409]*source[365]+workYaw.KKT[410]*source[54];
  result[366] = workYaw.KKT[92]*source[206]+workYaw.KKT[411]*source[366]+workYaw.KKT[412]*source[57];
  result[367] = workYaw.KKT[94]*source[207]+workYaw.KKT[413]*source[367]+workYaw.KKT[414]*source[60];
  result[368] = workYaw.KKT[96]*source[208]+workYaw.KKT[415]*source[368]+workYaw.KKT[416]*source[63];
  result[369] = workYaw.KKT[98]*source[209]+workYaw.KKT[417]*source[369]+workYaw.KKT[418]*source[66];
  result[370] = workYaw.KKT[100]*source[210]+workYaw.KKT[419]*source[370]+workYaw.KKT[420]*source[69];
  result[371] = workYaw.KKT[102]*source[211]+workYaw.KKT[421]*source[371]+workYaw.KKT[422]*source[72];
  result[372] = workYaw.KKT[104]*source[212]+workYaw.KKT[423]*source[372]+workYaw.KKT[424]*source[75];
  result[373] = workYaw.KKT[106]*source[213]+workYaw.KKT[425]*source[373]+workYaw.KKT[426]*source[78];
  result[374] = workYaw.KKT[108]*source[214]+workYaw.KKT[427]*source[374]+workYaw.KKT[428]*source[81];
  result[375] = workYaw.KKT[110]*source[215]+workYaw.KKT[429]*source[375]+workYaw.KKT[430]*source[84];
  result[376] = workYaw.KKT[112]*source[216]+workYaw.KKT[431]*source[376]+workYaw.KKT[432]*source[87];
  result[377] = workYaw.KKT[114]*source[217]+workYaw.KKT[433]*source[377]+workYaw.KKT[434]*source[90];
  result[378] = workYaw.KKT[116]*source[218]+workYaw.KKT[435]*source[378]+workYaw.KKT[436]*source[93];
  result[379] = workYaw.KKT[118]*source[219]+workYaw.KKT[437]*source[379]+workYaw.KKT[438]*source[96];
  result[380] = workYaw.KKT[120]*source[220]+workYaw.KKT[439]*source[380]+workYaw.KKT[440]*source[99];
  result[381] = workYaw.KKT[122]*source[221]+workYaw.KKT[441]*source[381]+workYaw.KKT[442]*source[102];
  result[382] = workYaw.KKT[124]*source[222]+workYaw.KKT[443]*source[382]+workYaw.KKT[444]*source[105];
  result[383] = workYaw.KKT[126]*source[223]+workYaw.KKT[445]*source[383]+workYaw.KKT[446]*source[108];
  result[384] = workYaw.KKT[128]*source[224]+workYaw.KKT[447]*source[384]+workYaw.KKT[448]*source[111];
  result[385] = workYaw.KKT[130]*source[225]+workYaw.KKT[449]*source[385]+workYaw.KKT[450]*source[114];
  result[386] = workYaw.KKT[132]*source[226]+workYaw.KKT[451]*source[386]+workYaw.KKT[452]*source[117];
  result[387] = workYaw.KKT[134]*source[227]+workYaw.KKT[453]*source[387]+workYaw.KKT[454]*source[120];
  result[388] = workYaw.KKT[136]*source[228]+workYaw.KKT[455]*source[388]+workYaw.KKT[456]*source[123];
  result[389] = workYaw.KKT[138]*source[229]+workYaw.KKT[457]*source[389]+workYaw.KKT[458]*source[126];
  result[390] = workYaw.KKT[140]*source[230]+workYaw.KKT[459]*source[390]+workYaw.KKT[460]*source[129];
  result[391] = workYaw.KKT[142]*source[231]+workYaw.KKT[461]*source[391]+workYaw.KKT[462]*source[132];
  result[392] = workYaw.KKT[144]*source[232]+workYaw.KKT[463]*source[392]+workYaw.KKT[464]*source[135];
  result[393] = workYaw.KKT[146]*source[233]+workYaw.KKT[465]*source[393]+workYaw.KKT[466]*source[138];
  result[394] = workYaw.KKT[148]*source[234]+workYaw.KKT[467]*source[394]+workYaw.KKT[468]*source[141];
  result[395] = workYaw.KKT[150]*source[235]+workYaw.KKT[469]*source[395]+workYaw.KKT[470]*source[144];
  result[396] = workYaw.KKT[152]*source[236]+workYaw.KKT[471]*source[396]+workYaw.KKT[472]*source[147];
  result[397] = workYaw.KKT[154]*source[237]+workYaw.KKT[473]*source[397]+workYaw.KKT[474]*source[150];
  result[398] = workYaw.KKT[156]*source[238]+workYaw.KKT[475]*source[398]+workYaw.KKT[476]*source[153];
  result[399] = workYaw.KKT[158]*source[239]+workYaw.KKT[477]*source[399]+workYaw.KKT[478]*source[156];
  result[400] = workYaw.KKT[160]*source[240]+workYaw.KKT[479]*source[400]+workYaw.KKT[480]*source[159];
  result[401] = workYaw.KKT[162]*source[241]+workYaw.KKT[481]*source[401]+workYaw.KKT[482]*source[43];
  result[402] = workYaw.KKT[164]*source[242]+workYaw.KKT[483]*source[402]+workYaw.KKT[484]*source[46];
  result[403] = workYaw.KKT[166]*source[243]+workYaw.KKT[485]*source[403]+workYaw.KKT[486]*source[49];
  result[404] = workYaw.KKT[168]*source[244]+workYaw.KKT[487]*source[404]+workYaw.KKT[488]*source[52];
  result[405] = workYaw.KKT[170]*source[245]+workYaw.KKT[489]*source[405]+workYaw.KKT[490]*source[55];
  result[406] = workYaw.KKT[172]*source[246]+workYaw.KKT[491]*source[406]+workYaw.KKT[492]*source[58];
  result[407] = workYaw.KKT[174]*source[247]+workYaw.KKT[493]*source[407]+workYaw.KKT[494]*source[61];
  result[408] = workYaw.KKT[176]*source[248]+workYaw.KKT[495]*source[408]+workYaw.KKT[496]*source[64];
  result[409] = workYaw.KKT[178]*source[249]+workYaw.KKT[497]*source[409]+workYaw.KKT[498]*source[67];
  result[410] = workYaw.KKT[180]*source[250]+workYaw.KKT[499]*source[410]+workYaw.KKT[500]*source[70];
  result[411] = workYaw.KKT[182]*source[251]+workYaw.KKT[501]*source[411]+workYaw.KKT[502]*source[73];
  result[412] = workYaw.KKT[184]*source[252]+workYaw.KKT[503]*source[412]+workYaw.KKT[504]*source[76];
  result[413] = workYaw.KKT[186]*source[253]+workYaw.KKT[505]*source[413]+workYaw.KKT[506]*source[79];
  result[414] = workYaw.KKT[188]*source[254]+workYaw.KKT[507]*source[414]+workYaw.KKT[508]*source[82];
  result[415] = workYaw.KKT[190]*source[255]+workYaw.KKT[509]*source[415]+workYaw.KKT[510]*source[85];
  result[416] = workYaw.KKT[192]*source[256]+workYaw.KKT[511]*source[416]+workYaw.KKT[512]*source[88];
  result[417] = workYaw.KKT[194]*source[257]+workYaw.KKT[513]*source[417]+workYaw.KKT[514]*source[91];
  result[418] = workYaw.KKT[196]*source[258]+workYaw.KKT[515]*source[418]+workYaw.KKT[516]*source[94];
  result[419] = workYaw.KKT[198]*source[259]+workYaw.KKT[517]*source[419]+workYaw.KKT[518]*source[97];
  result[420] = workYaw.KKT[200]*source[260]+workYaw.KKT[519]*source[420]+workYaw.KKT[520]*source[100];
  result[421] = workYaw.KKT[202]*source[261]+workYaw.KKT[521]*source[421]+workYaw.KKT[522]*source[103];
  result[422] = workYaw.KKT[204]*source[262]+workYaw.KKT[523]*source[422]+workYaw.KKT[524]*source[106];
  result[423] = workYaw.KKT[206]*source[263]+workYaw.KKT[525]*source[423]+workYaw.KKT[526]*source[109];
  result[424] = workYaw.KKT[208]*source[264]+workYaw.KKT[527]*source[424]+workYaw.KKT[528]*source[112];
  result[425] = workYaw.KKT[210]*source[265]+workYaw.KKT[529]*source[425]+workYaw.KKT[530]*source[115];
  result[426] = workYaw.KKT[212]*source[266]+workYaw.KKT[531]*source[426]+workYaw.KKT[532]*source[118];
  result[427] = workYaw.KKT[214]*source[267]+workYaw.KKT[533]*source[427]+workYaw.KKT[534]*source[121];
  result[428] = workYaw.KKT[216]*source[268]+workYaw.KKT[535]*source[428]+workYaw.KKT[536]*source[124];
  result[429] = workYaw.KKT[218]*source[269]+workYaw.KKT[537]*source[429]+workYaw.KKT[538]*source[127];
  result[430] = workYaw.KKT[220]*source[270]+workYaw.KKT[539]*source[430]+workYaw.KKT[540]*source[130];
  result[431] = workYaw.KKT[222]*source[271]+workYaw.KKT[541]*source[431]+workYaw.KKT[542]*source[133];
  result[432] = workYaw.KKT[224]*source[272]+workYaw.KKT[543]*source[432]+workYaw.KKT[544]*source[136];
  result[433] = workYaw.KKT[226]*source[273]+workYaw.KKT[545]*source[433]+workYaw.KKT[546]*source[139];
  result[434] = workYaw.KKT[228]*source[274]+workYaw.KKT[547]*source[434]+workYaw.KKT[548]*source[142];
  result[435] = workYaw.KKT[230]*source[275]+workYaw.KKT[549]*source[435]+workYaw.KKT[550]*source[145];
  result[436] = workYaw.KKT[232]*source[276]+workYaw.KKT[551]*source[436]+workYaw.KKT[552]*source[148];
  result[437] = workYaw.KKT[234]*source[277]+workYaw.KKT[553]*source[437]+workYaw.KKT[554]*source[151];
  result[438] = workYaw.KKT[236]*source[278]+workYaw.KKT[555]*source[438]+workYaw.KKT[556]*source[154];
  result[439] = workYaw.KKT[238]*source[279]+workYaw.KKT[557]*source[439]+workYaw.KKT[558]*source[157];
  result[440] = workYaw.KKT[240]*source[280]+workYaw.KKT[559]*source[440]+workYaw.KKT[560]*source[160];
  result[441] = workYaw.KKT[242]*source[281]+workYaw.KKT[561]*source[441]+workYaw.KKT[562]*source[43];
  result[442] = workYaw.KKT[244]*source[282]+workYaw.KKT[563]*source[442]+workYaw.KKT[564]*source[46];
  result[443] = workYaw.KKT[246]*source[283]+workYaw.KKT[565]*source[443]+workYaw.KKT[566]*source[49];
  result[444] = workYaw.KKT[248]*source[284]+workYaw.KKT[567]*source[444]+workYaw.KKT[568]*source[52];
  result[445] = workYaw.KKT[250]*source[285]+workYaw.KKT[569]*source[445]+workYaw.KKT[570]*source[55];
  result[446] = workYaw.KKT[252]*source[286]+workYaw.KKT[571]*source[446]+workYaw.KKT[572]*source[58];
  result[447] = workYaw.KKT[254]*source[287]+workYaw.KKT[573]*source[447]+workYaw.KKT[574]*source[61];
  result[448] = workYaw.KKT[256]*source[288]+workYaw.KKT[575]*source[448]+workYaw.KKT[576]*source[64];
  result[449] = workYaw.KKT[258]*source[289]+workYaw.KKT[577]*source[449]+workYaw.KKT[578]*source[67];
  result[450] = workYaw.KKT[260]*source[290]+workYaw.KKT[579]*source[450]+workYaw.KKT[580]*source[70];
  result[451] = workYaw.KKT[262]*source[291]+workYaw.KKT[581]*source[451]+workYaw.KKT[582]*source[73];
  result[452] = workYaw.KKT[264]*source[292]+workYaw.KKT[583]*source[452]+workYaw.KKT[584]*source[76];
  result[453] = workYaw.KKT[266]*source[293]+workYaw.KKT[585]*source[453]+workYaw.KKT[586]*source[79];
  result[454] = workYaw.KKT[268]*source[294]+workYaw.KKT[587]*source[454]+workYaw.KKT[588]*source[82];
  result[455] = workYaw.KKT[270]*source[295]+workYaw.KKT[589]*source[455]+workYaw.KKT[590]*source[85];
  result[456] = workYaw.KKT[272]*source[296]+workYaw.KKT[591]*source[456]+workYaw.KKT[592]*source[88];
  result[457] = workYaw.KKT[274]*source[297]+workYaw.KKT[593]*source[457]+workYaw.KKT[594]*source[91];
  result[458] = workYaw.KKT[276]*source[298]+workYaw.KKT[595]*source[458]+workYaw.KKT[596]*source[94];
  result[459] = workYaw.KKT[278]*source[299]+workYaw.KKT[597]*source[459]+workYaw.KKT[598]*source[97];
  result[460] = workYaw.KKT[280]*source[300]+workYaw.KKT[599]*source[460]+workYaw.KKT[600]*source[100];
  result[461] = workYaw.KKT[282]*source[301]+workYaw.KKT[601]*source[461]+workYaw.KKT[602]*source[103];
  result[462] = workYaw.KKT[284]*source[302]+workYaw.KKT[603]*source[462]+workYaw.KKT[604]*source[106];
  result[463] = workYaw.KKT[286]*source[303]+workYaw.KKT[605]*source[463]+workYaw.KKT[606]*source[109];
  result[464] = workYaw.KKT[288]*source[304]+workYaw.KKT[607]*source[464]+workYaw.KKT[608]*source[112];
  result[465] = workYaw.KKT[290]*source[305]+workYaw.KKT[609]*source[465]+workYaw.KKT[610]*source[115];
  result[466] = workYaw.KKT[292]*source[306]+workYaw.KKT[611]*source[466]+workYaw.KKT[612]*source[118];
  result[467] = workYaw.KKT[294]*source[307]+workYaw.KKT[613]*source[467]+workYaw.KKT[614]*source[121];
  result[468] = workYaw.KKT[296]*source[308]+workYaw.KKT[615]*source[468]+workYaw.KKT[616]*source[124];
  result[469] = workYaw.KKT[298]*source[309]+workYaw.KKT[617]*source[469]+workYaw.KKT[618]*source[127];
  result[470] = workYaw.KKT[300]*source[310]+workYaw.KKT[619]*source[470]+workYaw.KKT[620]*source[130];
  result[471] = workYaw.KKT[302]*source[311]+workYaw.KKT[621]*source[471]+workYaw.KKT[622]*source[133];
  result[472] = workYaw.KKT[304]*source[312]+workYaw.KKT[623]*source[472]+workYaw.KKT[624]*source[136];
  result[473] = workYaw.KKT[306]*source[313]+workYaw.KKT[625]*source[473]+workYaw.KKT[626]*source[139];
  result[474] = workYaw.KKT[308]*source[314]+workYaw.KKT[627]*source[474]+workYaw.KKT[628]*source[142];
  result[475] = workYaw.KKT[310]*source[315]+workYaw.KKT[629]*source[475]+workYaw.KKT[630]*source[145];
  result[476] = workYaw.KKT[312]*source[316]+workYaw.KKT[631]*source[476]+workYaw.KKT[632]*source[148];
  result[477] = workYaw.KKT[314]*source[317]+workYaw.KKT[633]*source[477]+workYaw.KKT[634]*source[151];
  result[478] = workYaw.KKT[316]*source[318]+workYaw.KKT[635]*source[478]+workYaw.KKT[636]*source[154];
  result[479] = workYaw.KKT[318]*source[319]+workYaw.KKT[637]*source[479]+workYaw.KKT[638]*source[157];
  result[480] = workYaw.KKT[320]*source[320]+workYaw.KKT[639]*source[480]+workYaw.KKT[640]*source[160];
  result[481] = workYaw.KKT[641]*source[41];
  result[482] = workYaw.KKT[642]*source[42];
  result[483] = workYaw.KKT[643]*source[0]+workYaw.KKT[644]*source[43];
  result[484] = workYaw.KKT[727]*source[41]+workYaw.KKT[735]*source[42]+workYaw.KKT[736]*source[44];
  result[485] = workYaw.KKT[816]*source[42]+workYaw.KKT[818]*source[43]+workYaw.KKT[931]*source[45];
  result[486] = workYaw.KKT[646]*source[1]+workYaw.KKT[737]*source[43]+workYaw.KKT[738]*source[46];
  result[487] = workYaw.KKT[820]*source[44]+workYaw.KKT[933]*source[45]+workYaw.KKT[822]*source[47];
  result[488] = workYaw.KKT[934]*source[45]+workYaw.KKT[936]*source[46]+workYaw.KKT[937]*source[48];
  result[489] = workYaw.KKT[648]*source[2]+workYaw.KKT[739]*source[46]+workYaw.KKT[740]*source[49];
  result[490] = workYaw.KKT[823]*source[47]+workYaw.KKT[939]*source[48]+workYaw.KKT[825]*source[50];
  result[491] = workYaw.KKT[940]*source[48]+workYaw.KKT[942]*source[49]+workYaw.KKT[943]*source[51];
  result[492] = workYaw.KKT[650]*source[3]+workYaw.KKT[741]*source[49]+workYaw.KKT[742]*source[52];
  result[493] = workYaw.KKT[826]*source[50]+workYaw.KKT[945]*source[51]+workYaw.KKT[828]*source[53];
  result[494] = workYaw.KKT[946]*source[51]+workYaw.KKT[948]*source[52]+workYaw.KKT[949]*source[54];
  result[495] = workYaw.KKT[652]*source[4]+workYaw.KKT[743]*source[52]+workYaw.KKT[744]*source[55];
  result[496] = workYaw.KKT[829]*source[53]+workYaw.KKT[951]*source[54]+workYaw.KKT[831]*source[56];
  result[497] = workYaw.KKT[952]*source[54]+workYaw.KKT[954]*source[55]+workYaw.KKT[955]*source[57];
  result[498] = workYaw.KKT[654]*source[5]+workYaw.KKT[745]*source[55]+workYaw.KKT[746]*source[58];
  result[499] = workYaw.KKT[832]*source[56]+workYaw.KKT[957]*source[57]+workYaw.KKT[834]*source[59];
  result[500] = workYaw.KKT[958]*source[57]+workYaw.KKT[960]*source[58]+workYaw.KKT[961]*source[60];
  result[501] = workYaw.KKT[656]*source[6]+workYaw.KKT[747]*source[58]+workYaw.KKT[748]*source[61];
  result[502] = workYaw.KKT[835]*source[59]+workYaw.KKT[963]*source[60]+workYaw.KKT[837]*source[62];
  result[503] = workYaw.KKT[964]*source[60]+workYaw.KKT[966]*source[61]+workYaw.KKT[967]*source[63];
  result[504] = workYaw.KKT[658]*source[7]+workYaw.KKT[749]*source[61]+workYaw.KKT[750]*source[64];
  result[505] = workYaw.KKT[838]*source[62]+workYaw.KKT[969]*source[63]+workYaw.KKT[840]*source[65];
  result[506] = workYaw.KKT[970]*source[63]+workYaw.KKT[972]*source[64]+workYaw.KKT[973]*source[66];
  result[507] = workYaw.KKT[660]*source[8]+workYaw.KKT[751]*source[64]+workYaw.KKT[752]*source[67];
  result[508] = workYaw.KKT[841]*source[65]+workYaw.KKT[975]*source[66]+workYaw.KKT[843]*source[68];
  result[509] = workYaw.KKT[976]*source[66]+workYaw.KKT[978]*source[67]+workYaw.KKT[979]*source[69];
  result[510] = workYaw.KKT[662]*source[9]+workYaw.KKT[753]*source[67]+workYaw.KKT[754]*source[70];
  result[511] = workYaw.KKT[844]*source[68]+workYaw.KKT[981]*source[69]+workYaw.KKT[846]*source[71];
  result[512] = workYaw.KKT[982]*source[69]+workYaw.KKT[984]*source[70]+workYaw.KKT[985]*source[72];
  result[513] = workYaw.KKT[664]*source[10]+workYaw.KKT[755]*source[70]+workYaw.KKT[756]*source[73];
  result[514] = workYaw.KKT[847]*source[71]+workYaw.KKT[987]*source[72]+workYaw.KKT[849]*source[74];
  result[515] = workYaw.KKT[988]*source[72]+workYaw.KKT[990]*source[73]+workYaw.KKT[991]*source[75];
  result[516] = workYaw.KKT[666]*source[11]+workYaw.KKT[757]*source[73]+workYaw.KKT[758]*source[76];
  result[517] = workYaw.KKT[850]*source[74]+workYaw.KKT[993]*source[75]+workYaw.KKT[852]*source[77];
  result[518] = workYaw.KKT[994]*source[75]+workYaw.KKT[996]*source[76]+workYaw.KKT[997]*source[78];
  result[519] = workYaw.KKT[668]*source[12]+workYaw.KKT[759]*source[76]+workYaw.KKT[760]*source[79];
  result[520] = workYaw.KKT[853]*source[77]+workYaw.KKT[999]*source[78]+workYaw.KKT[855]*source[80];
  result[521] = workYaw.KKT[1000]*source[78]+workYaw.KKT[1002]*source[79]+workYaw.KKT[1003]*source[81];
  result[522] = workYaw.KKT[670]*source[13]+workYaw.KKT[761]*source[79]+workYaw.KKT[762]*source[82];
  result[523] = workYaw.KKT[856]*source[80]+workYaw.KKT[1005]*source[81]+workYaw.KKT[858]*source[83];
  result[524] = workYaw.KKT[1006]*source[81]+workYaw.KKT[1008]*source[82]+workYaw.KKT[1009]*source[84];
  result[525] = workYaw.KKT[672]*source[14]+workYaw.KKT[763]*source[82]+workYaw.KKT[764]*source[85];
  result[526] = workYaw.KKT[859]*source[83]+workYaw.KKT[1011]*source[84]+workYaw.KKT[861]*source[86];
  result[527] = workYaw.KKT[1012]*source[84]+workYaw.KKT[1014]*source[85]+workYaw.KKT[1015]*source[87];
  result[528] = workYaw.KKT[674]*source[15]+workYaw.KKT[765]*source[85]+workYaw.KKT[766]*source[88];
  result[529] = workYaw.KKT[862]*source[86]+workYaw.KKT[1017]*source[87]+workYaw.KKT[864]*source[89];
  result[530] = workYaw.KKT[1018]*source[87]+workYaw.KKT[1020]*source[88]+workYaw.KKT[1021]*source[90];
  result[531] = workYaw.KKT[676]*source[16]+workYaw.KKT[767]*source[88]+workYaw.KKT[768]*source[91];
  result[532] = workYaw.KKT[865]*source[89]+workYaw.KKT[1023]*source[90]+workYaw.KKT[867]*source[92];
  result[533] = workYaw.KKT[1024]*source[90]+workYaw.KKT[1026]*source[91]+workYaw.KKT[1027]*source[93];
  result[534] = workYaw.KKT[678]*source[17]+workYaw.KKT[769]*source[91]+workYaw.KKT[770]*source[94];
  result[535] = workYaw.KKT[868]*source[92]+workYaw.KKT[1029]*source[93]+workYaw.KKT[870]*source[95];
  result[536] = workYaw.KKT[1030]*source[93]+workYaw.KKT[1032]*source[94]+workYaw.KKT[1033]*source[96];
  result[537] = workYaw.KKT[680]*source[18]+workYaw.KKT[771]*source[94]+workYaw.KKT[772]*source[97];
  result[538] = workYaw.KKT[871]*source[95]+workYaw.KKT[1035]*source[96]+workYaw.KKT[873]*source[98];
  result[539] = workYaw.KKT[1036]*source[96]+workYaw.KKT[1038]*source[97]+workYaw.KKT[1039]*source[99];
  result[540] = workYaw.KKT[682]*source[19]+workYaw.KKT[773]*source[97]+workYaw.KKT[774]*source[100];
  result[541] = workYaw.KKT[874]*source[98]+workYaw.KKT[1041]*source[99]+workYaw.KKT[876]*source[101];
  result[542] = workYaw.KKT[1042]*source[99]+workYaw.KKT[1044]*source[100]+workYaw.KKT[1045]*source[102];
  result[543] = workYaw.KKT[684]*source[20]+workYaw.KKT[775]*source[100]+workYaw.KKT[776]*source[103];
  result[544] = workYaw.KKT[877]*source[101]+workYaw.KKT[1047]*source[102]+workYaw.KKT[879]*source[104];
  result[545] = workYaw.KKT[1048]*source[102]+workYaw.KKT[1050]*source[103]+workYaw.KKT[1051]*source[105];
  result[546] = workYaw.KKT[686]*source[21]+workYaw.KKT[777]*source[103]+workYaw.KKT[778]*source[106];
  result[547] = workYaw.KKT[880]*source[104]+workYaw.KKT[1053]*source[105]+workYaw.KKT[882]*source[107];
  result[548] = workYaw.KKT[1054]*source[105]+workYaw.KKT[1056]*source[106]+workYaw.KKT[1057]*source[108];
  result[549] = workYaw.KKT[688]*source[22]+workYaw.KKT[779]*source[106]+workYaw.KKT[780]*source[109];
  result[550] = workYaw.KKT[883]*source[107]+workYaw.KKT[1059]*source[108]+workYaw.KKT[885]*source[110];
  result[551] = workYaw.KKT[1060]*source[108]+workYaw.KKT[1062]*source[109]+workYaw.KKT[1063]*source[111];
  result[552] = workYaw.KKT[690]*source[23]+workYaw.KKT[781]*source[109]+workYaw.KKT[782]*source[112];
  result[553] = workYaw.KKT[886]*source[110]+workYaw.KKT[1065]*source[111]+workYaw.KKT[888]*source[113];
  result[554] = workYaw.KKT[1066]*source[111]+workYaw.KKT[1068]*source[112]+workYaw.KKT[1069]*source[114];
  result[555] = workYaw.KKT[692]*source[24]+workYaw.KKT[783]*source[112]+workYaw.KKT[784]*source[115];
  result[556] = workYaw.KKT[889]*source[113]+workYaw.KKT[1071]*source[114]+workYaw.KKT[891]*source[116];
  result[557] = workYaw.KKT[1072]*source[114]+workYaw.KKT[1074]*source[115]+workYaw.KKT[1075]*source[117];
  result[558] = workYaw.KKT[694]*source[25]+workYaw.KKT[785]*source[115]+workYaw.KKT[786]*source[118];
  result[559] = workYaw.KKT[892]*source[116]+workYaw.KKT[1077]*source[117]+workYaw.KKT[894]*source[119];
  result[560] = workYaw.KKT[1078]*source[117]+workYaw.KKT[1080]*source[118]+workYaw.KKT[1081]*source[120];
  result[561] = workYaw.KKT[696]*source[26]+workYaw.KKT[787]*source[118]+workYaw.KKT[788]*source[121];
  result[562] = workYaw.KKT[895]*source[119]+workYaw.KKT[1083]*source[120]+workYaw.KKT[897]*source[122];
  result[563] = workYaw.KKT[1084]*source[120]+workYaw.KKT[1086]*source[121]+workYaw.KKT[1087]*source[123];
  result[564] = workYaw.KKT[698]*source[27]+workYaw.KKT[789]*source[121]+workYaw.KKT[790]*source[124];
  result[565] = workYaw.KKT[898]*source[122]+workYaw.KKT[1089]*source[123]+workYaw.KKT[900]*source[125];
  result[566] = workYaw.KKT[1090]*source[123]+workYaw.KKT[1092]*source[124]+workYaw.KKT[1093]*source[126];
  result[567] = workYaw.KKT[700]*source[28]+workYaw.KKT[791]*source[124]+workYaw.KKT[792]*source[127];
  result[568] = workYaw.KKT[901]*source[125]+workYaw.KKT[1095]*source[126]+workYaw.KKT[903]*source[128];
  result[569] = workYaw.KKT[1096]*source[126]+workYaw.KKT[1098]*source[127]+workYaw.KKT[1099]*source[129];
  result[570] = workYaw.KKT[702]*source[29]+workYaw.KKT[793]*source[127]+workYaw.KKT[794]*source[130];
  result[571] = workYaw.KKT[904]*source[128]+workYaw.KKT[1101]*source[129]+workYaw.KKT[906]*source[131];
  result[572] = workYaw.KKT[1102]*source[129]+workYaw.KKT[1104]*source[130]+workYaw.KKT[1105]*source[132];
  result[573] = workYaw.KKT[704]*source[30]+workYaw.KKT[795]*source[130]+workYaw.KKT[796]*source[133];
  result[574] = workYaw.KKT[907]*source[131]+workYaw.KKT[1107]*source[132]+workYaw.KKT[909]*source[134];
  result[575] = workYaw.KKT[1108]*source[132]+workYaw.KKT[1110]*source[133]+workYaw.KKT[1111]*source[135];
  result[576] = workYaw.KKT[706]*source[31]+workYaw.KKT[797]*source[133]+workYaw.KKT[798]*source[136];
  result[577] = workYaw.KKT[910]*source[134]+workYaw.KKT[1113]*source[135]+workYaw.KKT[912]*source[137];
  result[578] = workYaw.KKT[1114]*source[135]+workYaw.KKT[1116]*source[136]+workYaw.KKT[1117]*source[138];
  result[579] = workYaw.KKT[708]*source[32]+workYaw.KKT[799]*source[136]+workYaw.KKT[800]*source[139];
  result[580] = workYaw.KKT[913]*source[137]+workYaw.KKT[1119]*source[138]+workYaw.KKT[915]*source[140];
  result[581] = workYaw.KKT[1120]*source[138]+workYaw.KKT[1122]*source[139]+workYaw.KKT[1123]*source[141];
  result[582] = workYaw.KKT[710]*source[33]+workYaw.KKT[801]*source[139]+workYaw.KKT[802]*source[142];
  result[583] = workYaw.KKT[916]*source[140]+workYaw.KKT[1125]*source[141]+workYaw.KKT[918]*source[143];
  result[584] = workYaw.KKT[1126]*source[141]+workYaw.KKT[1128]*source[142]+workYaw.KKT[1129]*source[144];
  result[585] = workYaw.KKT[712]*source[34]+workYaw.KKT[803]*source[142]+workYaw.KKT[804]*source[145];
  result[586] = workYaw.KKT[919]*source[143]+workYaw.KKT[1131]*source[144]+workYaw.KKT[921]*source[146];
  result[587] = workYaw.KKT[1132]*source[144]+workYaw.KKT[1134]*source[145]+workYaw.KKT[1135]*source[147];
  result[588] = workYaw.KKT[714]*source[35]+workYaw.KKT[805]*source[145]+workYaw.KKT[806]*source[148];
  result[589] = workYaw.KKT[922]*source[146]+workYaw.KKT[1137]*source[147]+workYaw.KKT[924]*source[149];
  result[590] = workYaw.KKT[1138]*source[147]+workYaw.KKT[1140]*source[148]+workYaw.KKT[1141]*source[150];
  result[591] = workYaw.KKT[716]*source[36]+workYaw.KKT[807]*source[148]+workYaw.KKT[808]*source[151];
  result[592] = workYaw.KKT[925]*source[149]+workYaw.KKT[1143]*source[150]+workYaw.KKT[927]*source[152];
  result[593] = workYaw.KKT[1144]*source[150]+workYaw.KKT[1146]*source[151]+workYaw.KKT[1147]*source[153];
  result[594] = workYaw.KKT[718]*source[37]+workYaw.KKT[809]*source[151]+workYaw.KKT[810]*source[154];
  result[595] = workYaw.KKT[928]*source[152]+workYaw.KKT[1148]*source[153]+workYaw.KKT[930]*source[155];
  result[596] = workYaw.KKT[1149]*source[153]+workYaw.KKT[1150]*source[154]+workYaw.KKT[1151]*source[156];
  result[597] = workYaw.KKT[720]*source[38]+workYaw.KKT[811]*source[154]+workYaw.KKT[733]*source[157];
  result[598] = workYaw.KKT[812]*source[155]+workYaw.KKT[813]*source[156]+workYaw.KKT[729]*source[158];
  result[599] = workYaw.KKT[814]*source[156]+workYaw.KKT[734]*source[157]+workYaw.KKT[731]*source[159];
  result[600] = workYaw.KKT[722]*source[39]+workYaw.KKT[725]*source[157]+workYaw.KKT[724]*source[160];
}
double check_residual_yaw(double *target, double *multiplicand) {
  /* Returns the squared 2-norm of lhs - A*rhs. */
  /* Reuses v to find the residual. */
  int i;
  double residual;
  residual = 0;
  matrix_multiply_yaw(workYaw.v, multiplicand);
  for (i = 0; i < 161; i++) {
    residual += (target[i] - workYaw.v[i])*(target[i] - workYaw.v[i]);
  }
  return residual;
}
void fill_KKT_yaw(void) {
  workYaw.KKT[645] = 2*paramsYaw.R[0];
  workYaw.KKT[647] = 2*paramsYaw.R[0];
  workYaw.KKT[649] = 2*paramsYaw.R[0];
  workYaw.KKT[651] = 2*paramsYaw.R[0];
  workYaw.KKT[653] = 2*paramsYaw.R[0];
  workYaw.KKT[655] = 2*paramsYaw.R[0];
  workYaw.KKT[657] = 2*paramsYaw.R[0];
  workYaw.KKT[659] = 2*paramsYaw.R[0];
  workYaw.KKT[661] = 2*paramsYaw.R[0];
  workYaw.KKT[663] = 2*paramsYaw.R[0];
  workYaw.KKT[665] = 2*paramsYaw.R[0];
  workYaw.KKT[667] = 2*paramsYaw.R[0];
  workYaw.KKT[669] = 2*paramsYaw.R[0];
  workYaw.KKT[671] = 2*paramsYaw.R[0];
  workYaw.KKT[673] = 2*paramsYaw.R[0];
  workYaw.KKT[675] = 2*paramsYaw.R[0];
  workYaw.KKT[677] = 2*paramsYaw.R[0];
  workYaw.KKT[679] = 2*paramsYaw.R[0];
  workYaw.KKT[681] = 2*paramsYaw.R[0];
  workYaw.KKT[683] = 2*paramsYaw.R[0];
  workYaw.KKT[685] = 2*paramsYaw.R[0];
  workYaw.KKT[687] = 2*paramsYaw.R[0];
  workYaw.KKT[689] = 2*paramsYaw.R[0];
  workYaw.KKT[691] = 2*paramsYaw.R[0];
  workYaw.KKT[693] = 2*paramsYaw.R[0];
  workYaw.KKT[695] = 2*paramsYaw.R[0];
  workYaw.KKT[697] = 2*paramsYaw.R[0];
  workYaw.KKT[699] = 2*paramsYaw.R[0];
  workYaw.KKT[701] = 2*paramsYaw.R[0];
  workYaw.KKT[703] = 2*paramsYaw.R[0];
  workYaw.KKT[705] = 2*paramsYaw.R[0];
  workYaw.KKT[707] = 2*paramsYaw.R[0];
  workYaw.KKT[709] = 2*paramsYaw.R[0];
  workYaw.KKT[711] = 2*paramsYaw.R[0];
  workYaw.KKT[713] = 2*paramsYaw.R[0];
  workYaw.KKT[715] = 2*paramsYaw.R[0];
  workYaw.KKT[717] = 2*paramsYaw.R[0];
  workYaw.KKT[719] = 2*paramsYaw.R[0];
  workYaw.KKT[721] = 2*paramsYaw.R[0];
  workYaw.KKT[0] = 2*paramsYaw.R[0];
  workYaw.KKT[726] = 2*paramsYaw.Q[0];
  workYaw.KKT[815] = 2*paramsYaw.Q[1];
  workYaw.KKT[817] = 2*paramsYaw.Q[2];
  workYaw.KKT[819] = 2*paramsYaw.Q[0];
  workYaw.KKT[932] = 2*paramsYaw.Q[1];
  workYaw.KKT[935] = 2*paramsYaw.Q[2];
  workYaw.KKT[821] = 2*paramsYaw.Q[0];
  workYaw.KKT[938] = 2*paramsYaw.Q[1];
  workYaw.KKT[941] = 2*paramsYaw.Q[2];
  workYaw.KKT[824] = 2*paramsYaw.Q[0];
  workYaw.KKT[944] = 2*paramsYaw.Q[1];
  workYaw.KKT[947] = 2*paramsYaw.Q[2];
  workYaw.KKT[827] = 2*paramsYaw.Q[0];
  workYaw.KKT[950] = 2*paramsYaw.Q[1];
  workYaw.KKT[953] = 2*paramsYaw.Q[2];
  workYaw.KKT[830] = 2*paramsYaw.Q[0];
  workYaw.KKT[956] = 2*paramsYaw.Q[1];
  workYaw.KKT[959] = 2*paramsYaw.Q[2];
  workYaw.KKT[833] = 2*paramsYaw.Q[0];
  workYaw.KKT[962] = 2*paramsYaw.Q[1];
  workYaw.KKT[965] = 2*paramsYaw.Q[2];
  workYaw.KKT[836] = 2*paramsYaw.Q[0];
  workYaw.KKT[968] = 2*paramsYaw.Q[1];
  workYaw.KKT[971] = 2*paramsYaw.Q[2];
  workYaw.KKT[839] = 2*paramsYaw.Q[0];
  workYaw.KKT[974] = 2*paramsYaw.Q[1];
  workYaw.KKT[977] = 2*paramsYaw.Q[2];
  workYaw.KKT[842] = 2*paramsYaw.Q[0];
  workYaw.KKT[980] = 2*paramsYaw.Q[1];
  workYaw.KKT[983] = 2*paramsYaw.Q[2];
  workYaw.KKT[845] = 2*paramsYaw.Q[0];
  workYaw.KKT[986] = 2*paramsYaw.Q[1];
  workYaw.KKT[989] = 2*paramsYaw.Q[2];
  workYaw.KKT[848] = 2*paramsYaw.Q[0];
  workYaw.KKT[992] = 2*paramsYaw.Q[1];
  workYaw.KKT[995] = 2*paramsYaw.Q[2];
  workYaw.KKT[851] = 2*paramsYaw.Q[0];
  workYaw.KKT[998] = 2*paramsYaw.Q[1];
  workYaw.KKT[1001] = 2*paramsYaw.Q[2];
  workYaw.KKT[854] = 2*paramsYaw.Q[0];
  workYaw.KKT[1004] = 2*paramsYaw.Q[1];
  workYaw.KKT[1007] = 2*paramsYaw.Q[2];
  workYaw.KKT[857] = 2*paramsYaw.Q[0];
  workYaw.KKT[1010] = 2*paramsYaw.Q[1];
  workYaw.KKT[1013] = 2*paramsYaw.Q[2];
  workYaw.KKT[860] = 2*paramsYaw.Q[0];
  workYaw.KKT[1016] = 2*paramsYaw.Q[1];
  workYaw.KKT[1019] = 2*paramsYaw.Q[2];
  workYaw.KKT[863] = 2*paramsYaw.Q[0];
  workYaw.KKT[1022] = 2*paramsYaw.Q[1];
  workYaw.KKT[1025] = 2*paramsYaw.Q[2];
  workYaw.KKT[866] = 2*paramsYaw.Q[0];
  workYaw.KKT[1028] = 2*paramsYaw.Q[1];
  workYaw.KKT[1031] = 2*paramsYaw.Q[2];
  workYaw.KKT[869] = 2*paramsYaw.Q[0];
  workYaw.KKT[1034] = 2*paramsYaw.Q[1];
  workYaw.KKT[1037] = 2*paramsYaw.Q[2];
  workYaw.KKT[872] = 2*paramsYaw.Q[0];
  workYaw.KKT[1040] = 2*paramsYaw.Q[1];
  workYaw.KKT[1043] = 2*paramsYaw.Q[2];
  workYaw.KKT[875] = 2*paramsYaw.Q[0];
  workYaw.KKT[1046] = 2*paramsYaw.Q[1];
  workYaw.KKT[1049] = 2*paramsYaw.Q[2];
  workYaw.KKT[878] = 2*paramsYaw.Q[0];
  workYaw.KKT[1052] = 2*paramsYaw.Q[1];
  workYaw.KKT[1055] = 2*paramsYaw.Q[2];
  workYaw.KKT[881] = 2*paramsYaw.Q[0];
  workYaw.KKT[1058] = 2*paramsYaw.Q[1];
  workYaw.KKT[1061] = 2*paramsYaw.Q[2];
  workYaw.KKT[884] = 2*paramsYaw.Q[0];
  workYaw.KKT[1064] = 2*paramsYaw.Q[1];
  workYaw.KKT[1067] = 2*paramsYaw.Q[2];
  workYaw.KKT[887] = 2*paramsYaw.Q[0];
  workYaw.KKT[1070] = 2*paramsYaw.Q[1];
  workYaw.KKT[1073] = 2*paramsYaw.Q[2];
  workYaw.KKT[890] = 2*paramsYaw.Q[0];
  workYaw.KKT[1076] = 2*paramsYaw.Q[1];
  workYaw.KKT[1079] = 2*paramsYaw.Q[2];
  workYaw.KKT[893] = 2*paramsYaw.Q[0];
  workYaw.KKT[1082] = 2*paramsYaw.Q[1];
  workYaw.KKT[1085] = 2*paramsYaw.Q[2];
  workYaw.KKT[896] = 2*paramsYaw.Q[0];
  workYaw.KKT[1088] = 2*paramsYaw.Q[1];
  workYaw.KKT[1091] = 2*paramsYaw.Q[2];
  workYaw.KKT[899] = 2*paramsYaw.Q[0];
  workYaw.KKT[1094] = 2*paramsYaw.Q[1];
  workYaw.KKT[1097] = 2*paramsYaw.Q[2];
  workYaw.KKT[902] = 2*paramsYaw.Q[0];
  workYaw.KKT[1100] = 2*paramsYaw.Q[1];
  workYaw.KKT[1103] = 2*paramsYaw.Q[2];
  workYaw.KKT[905] = 2*paramsYaw.Q[0];
  workYaw.KKT[1106] = 2*paramsYaw.Q[1];
  workYaw.KKT[1109] = 2*paramsYaw.Q[2];
  workYaw.KKT[908] = 2*paramsYaw.Q[0];
  workYaw.KKT[1112] = 2*paramsYaw.Q[1];
  workYaw.KKT[1115] = 2*paramsYaw.Q[2];
  workYaw.KKT[911] = 2*paramsYaw.Q[0];
  workYaw.KKT[1118] = 2*paramsYaw.Q[1];
  workYaw.KKT[1121] = 2*paramsYaw.Q[2];
  workYaw.KKT[914] = 2*paramsYaw.Q[0];
  workYaw.KKT[1124] = 2*paramsYaw.Q[1];
  workYaw.KKT[1127] = 2*paramsYaw.Q[2];
  workYaw.KKT[917] = 2*paramsYaw.Q[0];
  workYaw.KKT[1130] = 2*paramsYaw.Q[1];
  workYaw.KKT[1133] = 2*paramsYaw.Q[2];
  workYaw.KKT[920] = 2*paramsYaw.Q[0];
  workYaw.KKT[1136] = 2*paramsYaw.Q[1];
  workYaw.KKT[1139] = 2*paramsYaw.Q[2];
  workYaw.KKT[923] = 2*paramsYaw.Q[0];
  workYaw.KKT[1142] = 2*paramsYaw.Q[1];
  workYaw.KKT[1145] = 2*paramsYaw.Q[2];
  workYaw.KKT[926] = 2*paramsYaw.Q[0];
  workYaw.KKT[1152] = 2*paramsYaw.Q[1];
  workYaw.KKT[1153] = 2*paramsYaw.Q[2];
  workYaw.KKT[929] = 2*paramsYaw.Q[0];
  workYaw.KKT[1154] = 2*paramsYaw.Q[1];
  workYaw.KKT[732] = 2*paramsYaw.Q[2];
  workYaw.KKT[728] = 2*paramsYaw.Q[0];
  workYaw.KKT[730] = 2*paramsYaw.Q[1];
  workYaw.KKT[723] = 2*paramsYaw.Q[2];
  workYaw.KKT[1] = workYaw.s_inv_z[0];
  workYaw.KKT[3] = workYaw.s_inv_z[1];
  workYaw.KKT[5] = workYaw.s_inv_z[2];
  workYaw.KKT[7] = workYaw.s_inv_z[3];
  workYaw.KKT[9] = workYaw.s_inv_z[4];
  workYaw.KKT[11] = workYaw.s_inv_z[5];
  workYaw.KKT[13] = workYaw.s_inv_z[6];
  workYaw.KKT[15] = workYaw.s_inv_z[7];
  workYaw.KKT[17] = workYaw.s_inv_z[8];
  workYaw.KKT[19] = workYaw.s_inv_z[9];
  workYaw.KKT[21] = workYaw.s_inv_z[10];
  workYaw.KKT[23] = workYaw.s_inv_z[11];
  workYaw.KKT[25] = workYaw.s_inv_z[12];
  workYaw.KKT[27] = workYaw.s_inv_z[13];
  workYaw.KKT[29] = workYaw.s_inv_z[14];
  workYaw.KKT[31] = workYaw.s_inv_z[15];
  workYaw.KKT[33] = workYaw.s_inv_z[16];
  workYaw.KKT[35] = workYaw.s_inv_z[17];
  workYaw.KKT[37] = workYaw.s_inv_z[18];
  workYaw.KKT[39] = workYaw.s_inv_z[19];
  workYaw.KKT[41] = workYaw.s_inv_z[20];
  workYaw.KKT[43] = workYaw.s_inv_z[21];
  workYaw.KKT[45] = workYaw.s_inv_z[22];
  workYaw.KKT[47] = workYaw.s_inv_z[23];
  workYaw.KKT[49] = workYaw.s_inv_z[24];
  workYaw.KKT[51] = workYaw.s_inv_z[25];
  workYaw.KKT[53] = workYaw.s_inv_z[26];
  workYaw.KKT[55] = workYaw.s_inv_z[27];
  workYaw.KKT[57] = workYaw.s_inv_z[28];
  workYaw.KKT[59] = workYaw.s_inv_z[29];
  workYaw.KKT[61] = workYaw.s_inv_z[30];
  workYaw.KKT[63] = workYaw.s_inv_z[31];
  workYaw.KKT[65] = workYaw.s_inv_z[32];
  workYaw.KKT[67] = workYaw.s_inv_z[33];
  workYaw.KKT[69] = workYaw.s_inv_z[34];
  workYaw.KKT[71] = workYaw.s_inv_z[35];
  workYaw.KKT[73] = workYaw.s_inv_z[36];
  workYaw.KKT[75] = workYaw.s_inv_z[37];
  workYaw.KKT[77] = workYaw.s_inv_z[38];
  workYaw.KKT[79] = workYaw.s_inv_z[39];
  workYaw.KKT[81] = workYaw.s_inv_z[40];
  workYaw.KKT[83] = workYaw.s_inv_z[41];
  workYaw.KKT[85] = workYaw.s_inv_z[42];
  workYaw.KKT[87] = workYaw.s_inv_z[43];
  workYaw.KKT[89] = workYaw.s_inv_z[44];
  workYaw.KKT[91] = workYaw.s_inv_z[45];
  workYaw.KKT[93] = workYaw.s_inv_z[46];
  workYaw.KKT[95] = workYaw.s_inv_z[47];
  workYaw.KKT[97] = workYaw.s_inv_z[48];
  workYaw.KKT[99] = workYaw.s_inv_z[49];
  workYaw.KKT[101] = workYaw.s_inv_z[50];
  workYaw.KKT[103] = workYaw.s_inv_z[51];
  workYaw.KKT[105] = workYaw.s_inv_z[52];
  workYaw.KKT[107] = workYaw.s_inv_z[53];
  workYaw.KKT[109] = workYaw.s_inv_z[54];
  workYaw.KKT[111] = workYaw.s_inv_z[55];
  workYaw.KKT[113] = workYaw.s_inv_z[56];
  workYaw.KKT[115] = workYaw.s_inv_z[57];
  workYaw.KKT[117] = workYaw.s_inv_z[58];
  workYaw.KKT[119] = workYaw.s_inv_z[59];
  workYaw.KKT[121] = workYaw.s_inv_z[60];
  workYaw.KKT[123] = workYaw.s_inv_z[61];
  workYaw.KKT[125] = workYaw.s_inv_z[62];
  workYaw.KKT[127] = workYaw.s_inv_z[63];
  workYaw.KKT[129] = workYaw.s_inv_z[64];
  workYaw.KKT[131] = workYaw.s_inv_z[65];
  workYaw.KKT[133] = workYaw.s_inv_z[66];
  workYaw.KKT[135] = workYaw.s_inv_z[67];
  workYaw.KKT[137] = workYaw.s_inv_z[68];
  workYaw.KKT[139] = workYaw.s_inv_z[69];
  workYaw.KKT[141] = workYaw.s_inv_z[70];
  workYaw.KKT[143] = workYaw.s_inv_z[71];
  workYaw.KKT[145] = workYaw.s_inv_z[72];
  workYaw.KKT[147] = workYaw.s_inv_z[73];
  workYaw.KKT[149] = workYaw.s_inv_z[74];
  workYaw.KKT[151] = workYaw.s_inv_z[75];
  workYaw.KKT[153] = workYaw.s_inv_z[76];
  workYaw.KKT[155] = workYaw.s_inv_z[77];
  workYaw.KKT[157] = workYaw.s_inv_z[78];
  workYaw.KKT[159] = workYaw.s_inv_z[79];
  workYaw.KKT[161] = workYaw.s_inv_z[80];
  workYaw.KKT[163] = workYaw.s_inv_z[81];
  workYaw.KKT[165] = workYaw.s_inv_z[82];
  workYaw.KKT[167] = workYaw.s_inv_z[83];
  workYaw.KKT[169] = workYaw.s_inv_z[84];
  workYaw.KKT[171] = workYaw.s_inv_z[85];
  workYaw.KKT[173] = workYaw.s_inv_z[86];
  workYaw.KKT[175] = workYaw.s_inv_z[87];
  workYaw.KKT[177] = workYaw.s_inv_z[88];
  workYaw.KKT[179] = workYaw.s_inv_z[89];
  workYaw.KKT[181] = workYaw.s_inv_z[90];
  workYaw.KKT[183] = workYaw.s_inv_z[91];
  workYaw.KKT[185] = workYaw.s_inv_z[92];
  workYaw.KKT[187] = workYaw.s_inv_z[93];
  workYaw.KKT[189] = workYaw.s_inv_z[94];
  workYaw.KKT[191] = workYaw.s_inv_z[95];
  workYaw.KKT[193] = workYaw.s_inv_z[96];
  workYaw.KKT[195] = workYaw.s_inv_z[97];
  workYaw.KKT[197] = workYaw.s_inv_z[98];
  workYaw.KKT[199] = workYaw.s_inv_z[99];
  workYaw.KKT[201] = workYaw.s_inv_z[100];
  workYaw.KKT[203] = workYaw.s_inv_z[101];
  workYaw.KKT[205] = workYaw.s_inv_z[102];
  workYaw.KKT[207] = workYaw.s_inv_z[103];
  workYaw.KKT[209] = workYaw.s_inv_z[104];
  workYaw.KKT[211] = workYaw.s_inv_z[105];
  workYaw.KKT[213] = workYaw.s_inv_z[106];
  workYaw.KKT[215] = workYaw.s_inv_z[107];
  workYaw.KKT[217] = workYaw.s_inv_z[108];
  workYaw.KKT[219] = workYaw.s_inv_z[109];
  workYaw.KKT[221] = workYaw.s_inv_z[110];
  workYaw.KKT[223] = workYaw.s_inv_z[111];
  workYaw.KKT[225] = workYaw.s_inv_z[112];
  workYaw.KKT[227] = workYaw.s_inv_z[113];
  workYaw.KKT[229] = workYaw.s_inv_z[114];
  workYaw.KKT[231] = workYaw.s_inv_z[115];
  workYaw.KKT[233] = workYaw.s_inv_z[116];
  workYaw.KKT[235] = workYaw.s_inv_z[117];
  workYaw.KKT[237] = workYaw.s_inv_z[118];
  workYaw.KKT[239] = workYaw.s_inv_z[119];
  workYaw.KKT[241] = workYaw.s_inv_z[120];
  workYaw.KKT[243] = workYaw.s_inv_z[121];
  workYaw.KKT[245] = workYaw.s_inv_z[122];
  workYaw.KKT[247] = workYaw.s_inv_z[123];
  workYaw.KKT[249] = workYaw.s_inv_z[124];
  workYaw.KKT[251] = workYaw.s_inv_z[125];
  workYaw.KKT[253] = workYaw.s_inv_z[126];
  workYaw.KKT[255] = workYaw.s_inv_z[127];
  workYaw.KKT[257] = workYaw.s_inv_z[128];
  workYaw.KKT[259] = workYaw.s_inv_z[129];
  workYaw.KKT[261] = workYaw.s_inv_z[130];
  workYaw.KKT[263] = workYaw.s_inv_z[131];
  workYaw.KKT[265] = workYaw.s_inv_z[132];
  workYaw.KKT[267] = workYaw.s_inv_z[133];
  workYaw.KKT[269] = workYaw.s_inv_z[134];
  workYaw.KKT[271] = workYaw.s_inv_z[135];
  workYaw.KKT[273] = workYaw.s_inv_z[136];
  workYaw.KKT[275] = workYaw.s_inv_z[137];
  workYaw.KKT[277] = workYaw.s_inv_z[138];
  workYaw.KKT[279] = workYaw.s_inv_z[139];
  workYaw.KKT[281] = workYaw.s_inv_z[140];
  workYaw.KKT[283] = workYaw.s_inv_z[141];
  workYaw.KKT[285] = workYaw.s_inv_z[142];
  workYaw.KKT[287] = workYaw.s_inv_z[143];
  workYaw.KKT[289] = workYaw.s_inv_z[144];
  workYaw.KKT[291] = workYaw.s_inv_z[145];
  workYaw.KKT[293] = workYaw.s_inv_z[146];
  workYaw.KKT[295] = workYaw.s_inv_z[147];
  workYaw.KKT[297] = workYaw.s_inv_z[148];
  workYaw.KKT[299] = workYaw.s_inv_z[149];
  workYaw.KKT[301] = workYaw.s_inv_z[150];
  workYaw.KKT[303] = workYaw.s_inv_z[151];
  workYaw.KKT[305] = workYaw.s_inv_z[152];
  workYaw.KKT[307] = workYaw.s_inv_z[153];
  workYaw.KKT[309] = workYaw.s_inv_z[154];
  workYaw.KKT[311] = workYaw.s_inv_z[155];
  workYaw.KKT[313] = workYaw.s_inv_z[156];
  workYaw.KKT[315] = workYaw.s_inv_z[157];
  workYaw.KKT[317] = workYaw.s_inv_z[158];
  workYaw.KKT[319] = workYaw.s_inv_z[159];
  workYaw.KKT[2] = 1;
  workYaw.KKT[4] = 1;
  workYaw.KKT[6] = 1;
  workYaw.KKT[8] = 1;
  workYaw.KKT[10] = 1;
  workYaw.KKT[12] = 1;
  workYaw.KKT[14] = 1;
  workYaw.KKT[16] = 1;
  workYaw.KKT[18] = 1;
  workYaw.KKT[20] = 1;
  workYaw.KKT[22] = 1;
  workYaw.KKT[24] = 1;
  workYaw.KKT[26] = 1;
  workYaw.KKT[28] = 1;
  workYaw.KKT[30] = 1;
  workYaw.KKT[32] = 1;
  workYaw.KKT[34] = 1;
  workYaw.KKT[36] = 1;
  workYaw.KKT[38] = 1;
  workYaw.KKT[40] = 1;
  workYaw.KKT[42] = 1;
  workYaw.KKT[44] = 1;
  workYaw.KKT[46] = 1;
  workYaw.KKT[48] = 1;
  workYaw.KKT[50] = 1;
  workYaw.KKT[52] = 1;
  workYaw.KKT[54] = 1;
  workYaw.KKT[56] = 1;
  workYaw.KKT[58] = 1;
  workYaw.KKT[60] = 1;
  workYaw.KKT[62] = 1;
  workYaw.KKT[64] = 1;
  workYaw.KKT[66] = 1;
  workYaw.KKT[68] = 1;
  workYaw.KKT[70] = 1;
  workYaw.KKT[72] = 1;
  workYaw.KKT[74] = 1;
  workYaw.KKT[76] = 1;
  workYaw.KKT[78] = 1;
  workYaw.KKT[80] = 1;
  workYaw.KKT[82] = 1;
  workYaw.KKT[84] = 1;
  workYaw.KKT[86] = 1;
  workYaw.KKT[88] = 1;
  workYaw.KKT[90] = 1;
  workYaw.KKT[92] = 1;
  workYaw.KKT[94] = 1;
  workYaw.KKT[96] = 1;
  workYaw.KKT[98] = 1;
  workYaw.KKT[100] = 1;
  workYaw.KKT[102] = 1;
  workYaw.KKT[104] = 1;
  workYaw.KKT[106] = 1;
  workYaw.KKT[108] = 1;
  workYaw.KKT[110] = 1;
  workYaw.KKT[112] = 1;
  workYaw.KKT[114] = 1;
  workYaw.KKT[116] = 1;
  workYaw.KKT[118] = 1;
  workYaw.KKT[120] = 1;
  workYaw.KKT[122] = 1;
  workYaw.KKT[124] = 1;
  workYaw.KKT[126] = 1;
  workYaw.KKT[128] = 1;
  workYaw.KKT[130] = 1;
  workYaw.KKT[132] = 1;
  workYaw.KKT[134] = 1;
  workYaw.KKT[136] = 1;
  workYaw.KKT[138] = 1;
  workYaw.KKT[140] = 1;
  workYaw.KKT[142] = 1;
  workYaw.KKT[144] = 1;
  workYaw.KKT[146] = 1;
  workYaw.KKT[148] = 1;
  workYaw.KKT[150] = 1;
  workYaw.KKT[152] = 1;
  workYaw.KKT[154] = 1;
  workYaw.KKT[156] = 1;
  workYaw.KKT[158] = 1;
  workYaw.KKT[160] = 1;
  workYaw.KKT[162] = 1;
  workYaw.KKT[164] = 1;
  workYaw.KKT[166] = 1;
  workYaw.KKT[168] = 1;
  workYaw.KKT[170] = 1;
  workYaw.KKT[172] = 1;
  workYaw.KKT[174] = 1;
  workYaw.KKT[176] = 1;
  workYaw.KKT[178] = 1;
  workYaw.KKT[180] = 1;
  workYaw.KKT[182] = 1;
  workYaw.KKT[184] = 1;
  workYaw.KKT[186] = 1;
  workYaw.KKT[188] = 1;
  workYaw.KKT[190] = 1;
  workYaw.KKT[192] = 1;
  workYaw.KKT[194] = 1;
  workYaw.KKT[196] = 1;
  workYaw.KKT[198] = 1;
  workYaw.KKT[200] = 1;
  workYaw.KKT[202] = 1;
  workYaw.KKT[204] = 1;
  workYaw.KKT[206] = 1;
  workYaw.KKT[208] = 1;
  workYaw.KKT[210] = 1;
  workYaw.KKT[212] = 1;
  workYaw.KKT[214] = 1;
  workYaw.KKT[216] = 1;
  workYaw.KKT[218] = 1;
  workYaw.KKT[220] = 1;
  workYaw.KKT[222] = 1;
  workYaw.KKT[224] = 1;
  workYaw.KKT[226] = 1;
  workYaw.KKT[228] = 1;
  workYaw.KKT[230] = 1;
  workYaw.KKT[232] = 1;
  workYaw.KKT[234] = 1;
  workYaw.KKT[236] = 1;
  workYaw.KKT[238] = 1;
  workYaw.KKT[240] = 1;
  workYaw.KKT[242] = 1;
  workYaw.KKT[244] = 1;
  workYaw.KKT[246] = 1;
  workYaw.KKT[248] = 1;
  workYaw.KKT[250] = 1;
  workYaw.KKT[252] = 1;
  workYaw.KKT[254] = 1;
  workYaw.KKT[256] = 1;
  workYaw.KKT[258] = 1;
  workYaw.KKT[260] = 1;
  workYaw.KKT[262] = 1;
  workYaw.KKT[264] = 1;
  workYaw.KKT[266] = 1;
  workYaw.KKT[268] = 1;
  workYaw.KKT[270] = 1;
  workYaw.KKT[272] = 1;
  workYaw.KKT[274] = 1;
  workYaw.KKT[276] = 1;
  workYaw.KKT[278] = 1;
  workYaw.KKT[280] = 1;
  workYaw.KKT[282] = 1;
  workYaw.KKT[284] = 1;
  workYaw.KKT[286] = 1;
  workYaw.KKT[288] = 1;
  workYaw.KKT[290] = 1;
  workYaw.KKT[292] = 1;
  workYaw.KKT[294] = 1;
  workYaw.KKT[296] = 1;
  workYaw.KKT[298] = 1;
  workYaw.KKT[300] = 1;
  workYaw.KKT[302] = 1;
  workYaw.KKT[304] = 1;
  workYaw.KKT[306] = 1;
  workYaw.KKT[308] = 1;
  workYaw.KKT[310] = 1;
  workYaw.KKT[312] = 1;
  workYaw.KKT[314] = 1;
  workYaw.KKT[316] = 1;
  workYaw.KKT[318] = 1;
  workYaw.KKT[320] = 1;
  workYaw.KKT[321] = workYaw.block_33[0];
  workYaw.KKT[323] = workYaw.block_33[0];
  workYaw.KKT[325] = workYaw.block_33[0];
  workYaw.KKT[327] = workYaw.block_33[0];
  workYaw.KKT[329] = workYaw.block_33[0];
  workYaw.KKT[331] = workYaw.block_33[0];
  workYaw.KKT[333] = workYaw.block_33[0];
  workYaw.KKT[335] = workYaw.block_33[0];
  workYaw.KKT[337] = workYaw.block_33[0];
  workYaw.KKT[339] = workYaw.block_33[0];
  workYaw.KKT[341] = workYaw.block_33[0];
  workYaw.KKT[343] = workYaw.block_33[0];
  workYaw.KKT[345] = workYaw.block_33[0];
  workYaw.KKT[347] = workYaw.block_33[0];
  workYaw.KKT[349] = workYaw.block_33[0];
  workYaw.KKT[351] = workYaw.block_33[0];
  workYaw.KKT[353] = workYaw.block_33[0];
  workYaw.KKT[355] = workYaw.block_33[0];
  workYaw.KKT[357] = workYaw.block_33[0];
  workYaw.KKT[359] = workYaw.block_33[0];
  workYaw.KKT[361] = workYaw.block_33[0];
  workYaw.KKT[363] = workYaw.block_33[0];
  workYaw.KKT[365] = workYaw.block_33[0];
  workYaw.KKT[367] = workYaw.block_33[0];
  workYaw.KKT[369] = workYaw.block_33[0];
  workYaw.KKT[371] = workYaw.block_33[0];
  workYaw.KKT[373] = workYaw.block_33[0];
  workYaw.KKT[375] = workYaw.block_33[0];
  workYaw.KKT[377] = workYaw.block_33[0];
  workYaw.KKT[379] = workYaw.block_33[0];
  workYaw.KKT[381] = workYaw.block_33[0];
  workYaw.KKT[383] = workYaw.block_33[0];
  workYaw.KKT[385] = workYaw.block_33[0];
  workYaw.KKT[387] = workYaw.block_33[0];
  workYaw.KKT[389] = workYaw.block_33[0];
  workYaw.KKT[391] = workYaw.block_33[0];
  workYaw.KKT[393] = workYaw.block_33[0];
  workYaw.KKT[395] = workYaw.block_33[0];
  workYaw.KKT[397] = workYaw.block_33[0];
  workYaw.KKT[399] = workYaw.block_33[0];
  workYaw.KKT[401] = workYaw.block_33[0];
  workYaw.KKT[403] = workYaw.block_33[0];
  workYaw.KKT[405] = workYaw.block_33[0];
  workYaw.KKT[407] = workYaw.block_33[0];
  workYaw.KKT[409] = workYaw.block_33[0];
  workYaw.KKT[411] = workYaw.block_33[0];
  workYaw.KKT[413] = workYaw.block_33[0];
  workYaw.KKT[415] = workYaw.block_33[0];
  workYaw.KKT[417] = workYaw.block_33[0];
  workYaw.KKT[419] = workYaw.block_33[0];
  workYaw.KKT[421] = workYaw.block_33[0];
  workYaw.KKT[423] = workYaw.block_33[0];
  workYaw.KKT[425] = workYaw.block_33[0];
  workYaw.KKT[427] = workYaw.block_33[0];
  workYaw.KKT[429] = workYaw.block_33[0];
  workYaw.KKT[431] = workYaw.block_33[0];
  workYaw.KKT[433] = workYaw.block_33[0];
  workYaw.KKT[435] = workYaw.block_33[0];
  workYaw.KKT[437] = workYaw.block_33[0];
  workYaw.KKT[439] = workYaw.block_33[0];
  workYaw.KKT[441] = workYaw.block_33[0];
  workYaw.KKT[443] = workYaw.block_33[0];
  workYaw.KKT[445] = workYaw.block_33[0];
  workYaw.KKT[447] = workYaw.block_33[0];
  workYaw.KKT[449] = workYaw.block_33[0];
  workYaw.KKT[451] = workYaw.block_33[0];
  workYaw.KKT[453] = workYaw.block_33[0];
  workYaw.KKT[455] = workYaw.block_33[0];
  workYaw.KKT[457] = workYaw.block_33[0];
  workYaw.KKT[459] = workYaw.block_33[0];
  workYaw.KKT[461] = workYaw.block_33[0];
  workYaw.KKT[463] = workYaw.block_33[0];
  workYaw.KKT[465] = workYaw.block_33[0];
  workYaw.KKT[467] = workYaw.block_33[0];
  workYaw.KKT[469] = workYaw.block_33[0];
  workYaw.KKT[471] = workYaw.block_33[0];
  workYaw.KKT[473] = workYaw.block_33[0];
  workYaw.KKT[475] = workYaw.block_33[0];
  workYaw.KKT[477] = workYaw.block_33[0];
  workYaw.KKT[479] = workYaw.block_33[0];
  workYaw.KKT[481] = workYaw.block_33[0];
  workYaw.KKT[483] = workYaw.block_33[0];
  workYaw.KKT[485] = workYaw.block_33[0];
  workYaw.KKT[487] = workYaw.block_33[0];
  workYaw.KKT[489] = workYaw.block_33[0];
  workYaw.KKT[491] = workYaw.block_33[0];
  workYaw.KKT[493] = workYaw.block_33[0];
  workYaw.KKT[495] = workYaw.block_33[0];
  workYaw.KKT[497] = workYaw.block_33[0];
  workYaw.KKT[499] = workYaw.block_33[0];
  workYaw.KKT[501] = workYaw.block_33[0];
  workYaw.KKT[503] = workYaw.block_33[0];
  workYaw.KKT[505] = workYaw.block_33[0];
  workYaw.KKT[507] = workYaw.block_33[0];
  workYaw.KKT[509] = workYaw.block_33[0];
  workYaw.KKT[511] = workYaw.block_33[0];
  workYaw.KKT[513] = workYaw.block_33[0];
  workYaw.KKT[515] = workYaw.block_33[0];
  workYaw.KKT[517] = workYaw.block_33[0];
  workYaw.KKT[519] = workYaw.block_33[0];
  workYaw.KKT[521] = workYaw.block_33[0];
  workYaw.KKT[523] = workYaw.block_33[0];
  workYaw.KKT[525] = workYaw.block_33[0];
  workYaw.KKT[527] = workYaw.block_33[0];
  workYaw.KKT[529] = workYaw.block_33[0];
  workYaw.KKT[531] = workYaw.block_33[0];
  workYaw.KKT[533] = workYaw.block_33[0];
  workYaw.KKT[535] = workYaw.block_33[0];
  workYaw.KKT[537] = workYaw.block_33[0];
  workYaw.KKT[539] = workYaw.block_33[0];
  workYaw.KKT[541] = workYaw.block_33[0];
  workYaw.KKT[543] = workYaw.block_33[0];
  workYaw.KKT[545] = workYaw.block_33[0];
  workYaw.KKT[547] = workYaw.block_33[0];
  workYaw.KKT[549] = workYaw.block_33[0];
  workYaw.KKT[551] = workYaw.block_33[0];
  workYaw.KKT[553] = workYaw.block_33[0];
  workYaw.KKT[555] = workYaw.block_33[0];
  workYaw.KKT[557] = workYaw.block_33[0];
  workYaw.KKT[559] = workYaw.block_33[0];
  workYaw.KKT[561] = workYaw.block_33[0];
  workYaw.KKT[563] = workYaw.block_33[0];
  workYaw.KKT[565] = workYaw.block_33[0];
  workYaw.KKT[567] = workYaw.block_33[0];
  workYaw.KKT[569] = workYaw.block_33[0];
  workYaw.KKT[571] = workYaw.block_33[0];
  workYaw.KKT[573] = workYaw.block_33[0];
  workYaw.KKT[575] = workYaw.block_33[0];
  workYaw.KKT[577] = workYaw.block_33[0];
  workYaw.KKT[579] = workYaw.block_33[0];
  workYaw.KKT[581] = workYaw.block_33[0];
  workYaw.KKT[583] = workYaw.block_33[0];
  workYaw.KKT[585] = workYaw.block_33[0];
  workYaw.KKT[587] = workYaw.block_33[0];
  workYaw.KKT[589] = workYaw.block_33[0];
  workYaw.KKT[591] = workYaw.block_33[0];
  workYaw.KKT[593] = workYaw.block_33[0];
  workYaw.KKT[595] = workYaw.block_33[0];
  workYaw.KKT[597] = workYaw.block_33[0];
  workYaw.KKT[599] = workYaw.block_33[0];
  workYaw.KKT[601] = workYaw.block_33[0];
  workYaw.KKT[603] = workYaw.block_33[0];
  workYaw.KKT[605] = workYaw.block_33[0];
  workYaw.KKT[607] = workYaw.block_33[0];
  workYaw.KKT[609] = workYaw.block_33[0];
  workYaw.KKT[611] = workYaw.block_33[0];
  workYaw.KKT[613] = workYaw.block_33[0];
  workYaw.KKT[615] = workYaw.block_33[0];
  workYaw.KKT[617] = workYaw.block_33[0];
  workYaw.KKT[619] = workYaw.block_33[0];
  workYaw.KKT[621] = workYaw.block_33[0];
  workYaw.KKT[623] = workYaw.block_33[0];
  workYaw.KKT[625] = workYaw.block_33[0];
  workYaw.KKT[627] = workYaw.block_33[0];
  workYaw.KKT[629] = workYaw.block_33[0];
  workYaw.KKT[631] = workYaw.block_33[0];
  workYaw.KKT[633] = workYaw.block_33[0];
  workYaw.KKT[635] = workYaw.block_33[0];
  workYaw.KKT[637] = workYaw.block_33[0];
  workYaw.KKT[639] = workYaw.block_33[0];
  workYaw.KKT[322] = 1;
  workYaw.KKT[324] = 1;
  workYaw.KKT[326] = 1;
  workYaw.KKT[328] = 1;
  workYaw.KKT[330] = 1;
  workYaw.KKT[332] = 1;
  workYaw.KKT[334] = 1;
  workYaw.KKT[336] = 1;
  workYaw.KKT[338] = 1;
  workYaw.KKT[340] = 1;
  workYaw.KKT[342] = 1;
  workYaw.KKT[344] = 1;
  workYaw.KKT[346] = 1;
  workYaw.KKT[348] = 1;
  workYaw.KKT[350] = 1;
  workYaw.KKT[352] = 1;
  workYaw.KKT[354] = 1;
  workYaw.KKT[356] = 1;
  workYaw.KKT[358] = 1;
  workYaw.KKT[360] = 1;
  workYaw.KKT[362] = 1;
  workYaw.KKT[364] = 1;
  workYaw.KKT[366] = 1;
  workYaw.KKT[368] = 1;
  workYaw.KKT[370] = 1;
  workYaw.KKT[372] = 1;
  workYaw.KKT[374] = 1;
  workYaw.KKT[376] = 1;
  workYaw.KKT[378] = 1;
  workYaw.KKT[380] = 1;
  workYaw.KKT[382] = 1;
  workYaw.KKT[384] = 1;
  workYaw.KKT[386] = 1;
  workYaw.KKT[388] = 1;
  workYaw.KKT[390] = 1;
  workYaw.KKT[392] = 1;
  workYaw.KKT[394] = 1;
  workYaw.KKT[396] = 1;
  workYaw.KKT[398] = 1;
  workYaw.KKT[400] = 1;
  workYaw.KKT[402] = -1;
  workYaw.KKT[404] = -1;
  workYaw.KKT[406] = -1;
  workYaw.KKT[408] = -1;
  workYaw.KKT[410] = -1;
  workYaw.KKT[412] = -1;
  workYaw.KKT[414] = -1;
  workYaw.KKT[416] = -1;
  workYaw.KKT[418] = -1;
  workYaw.KKT[420] = -1;
  workYaw.KKT[422] = -1;
  workYaw.KKT[424] = -1;
  workYaw.KKT[426] = -1;
  workYaw.KKT[428] = -1;
  workYaw.KKT[430] = -1;
  workYaw.KKT[432] = -1;
  workYaw.KKT[434] = -1;
  workYaw.KKT[436] = -1;
  workYaw.KKT[438] = -1;
  workYaw.KKT[440] = -1;
  workYaw.KKT[442] = -1;
  workYaw.KKT[444] = -1;
  workYaw.KKT[446] = -1;
  workYaw.KKT[448] = -1;
  workYaw.KKT[450] = -1;
  workYaw.KKT[452] = -1;
  workYaw.KKT[454] = -1;
  workYaw.KKT[456] = -1;
  workYaw.KKT[458] = -1;
  workYaw.KKT[460] = -1;
  workYaw.KKT[462] = -1;
  workYaw.KKT[464] = -1;
  workYaw.KKT[466] = -1;
  workYaw.KKT[468] = -1;
  workYaw.KKT[470] = -1;
  workYaw.KKT[472] = -1;
  workYaw.KKT[474] = -1;
  workYaw.KKT[476] = -1;
  workYaw.KKT[478] = -1;
  workYaw.KKT[480] = -1;
  workYaw.KKT[482] = 1;
  workYaw.KKT[484] = 1;
  workYaw.KKT[486] = 1;
  workYaw.KKT[488] = 1;
  workYaw.KKT[490] = 1;
  workYaw.KKT[492] = 1;
  workYaw.KKT[494] = 1;
  workYaw.KKT[496] = 1;
  workYaw.KKT[498] = 1;
  workYaw.KKT[500] = 1;
  workYaw.KKT[502] = 1;
  workYaw.KKT[504] = 1;
  workYaw.KKT[506] = 1;
  workYaw.KKT[508] = 1;
  workYaw.KKT[510] = 1;
  workYaw.KKT[512] = 1;
  workYaw.KKT[514] = 1;
  workYaw.KKT[516] = 1;
  workYaw.KKT[518] = 1;
  workYaw.KKT[520] = 1;
  workYaw.KKT[522] = 1;
  workYaw.KKT[524] = 1;
  workYaw.KKT[526] = 1;
  workYaw.KKT[528] = 1;
  workYaw.KKT[530] = 1;
  workYaw.KKT[532] = 1;
  workYaw.KKT[534] = 1;
  workYaw.KKT[536] = 1;
  workYaw.KKT[538] = 1;
  workYaw.KKT[540] = 1;
  workYaw.KKT[542] = 1;
  workYaw.KKT[544] = 1;
  workYaw.KKT[546] = 1;
  workYaw.KKT[548] = 1;
  workYaw.KKT[550] = 1;
  workYaw.KKT[552] = 1;
  workYaw.KKT[554] = 1;
  workYaw.KKT[556] = 1;
  workYaw.KKT[558] = 1;
  workYaw.KKT[560] = 1;
  workYaw.KKT[562] = -1;
  workYaw.KKT[564] = -1;
  workYaw.KKT[566] = -1;
  workYaw.KKT[568] = -1;
  workYaw.KKT[570] = -1;
  workYaw.KKT[572] = -1;
  workYaw.KKT[574] = -1;
  workYaw.KKT[576] = -1;
  workYaw.KKT[578] = -1;
  workYaw.KKT[580] = -1;
  workYaw.KKT[582] = -1;
  workYaw.KKT[584] = -1;
  workYaw.KKT[586] = -1;
  workYaw.KKT[588] = -1;
  workYaw.KKT[590] = -1;
  workYaw.KKT[592] = -1;
  workYaw.KKT[594] = -1;
  workYaw.KKT[596] = -1;
  workYaw.KKT[598] = -1;
  workYaw.KKT[600] = -1;
  workYaw.KKT[602] = -1;
  workYaw.KKT[604] = -1;
  workYaw.KKT[606] = -1;
  workYaw.KKT[608] = -1;
  workYaw.KKT[610] = -1;
  workYaw.KKT[612] = -1;
  workYaw.KKT[614] = -1;
  workYaw.KKT[616] = -1;
  workYaw.KKT[618] = -1;
  workYaw.KKT[620] = -1;
  workYaw.KKT[622] = -1;
  workYaw.KKT[624] = -1;
  workYaw.KKT[626] = -1;
  workYaw.KKT[628] = -1;
  workYaw.KKT[630] = -1;
  workYaw.KKT[632] = -1;
  workYaw.KKT[634] = -1;
  workYaw.KKT[636] = -1;
  workYaw.KKT[638] = -1;
  workYaw.KKT[640] = -1;
  workYaw.KKT[643] = -paramsYaw.Bf[0];
  workYaw.KKT[641] = 1;
  workYaw.KKT[642] = 1;
  workYaw.KKT[644] = 1;
  workYaw.KKT[646] = -paramsYaw.B[0];
  workYaw.KKT[727] = -paramsYaw.A[0];
  workYaw.KKT[816] = -paramsYaw.A[1];
  workYaw.KKT[737] = -paramsYaw.A[2];
  workYaw.KKT[735] = -paramsYaw.A[3];
  workYaw.KKT[818] = -paramsYaw.A[4];
  workYaw.KKT[736] = 1;
  workYaw.KKT[931] = 1;
  workYaw.KKT[738] = 1;
  workYaw.KKT[648] = -paramsYaw.B[0];
  workYaw.KKT[820] = -paramsYaw.A[0];
  workYaw.KKT[934] = -paramsYaw.A[1];
  workYaw.KKT[739] = -paramsYaw.A[2];
  workYaw.KKT[933] = -paramsYaw.A[3];
  workYaw.KKT[936] = -paramsYaw.A[4];
  workYaw.KKT[822] = 1;
  workYaw.KKT[937] = 1;
  workYaw.KKT[740] = 1;
  workYaw.KKT[650] = -paramsYaw.B[0];
  workYaw.KKT[823] = -paramsYaw.A[0];
  workYaw.KKT[940] = -paramsYaw.A[1];
  workYaw.KKT[741] = -paramsYaw.A[2];
  workYaw.KKT[939] = -paramsYaw.A[3];
  workYaw.KKT[942] = -paramsYaw.A[4];
  workYaw.KKT[825] = 1;
  workYaw.KKT[943] = 1;
  workYaw.KKT[742] = 1;
  workYaw.KKT[652] = -paramsYaw.B[0];
  workYaw.KKT[826] = -paramsYaw.A[0];
  workYaw.KKT[946] = -paramsYaw.A[1];
  workYaw.KKT[743] = -paramsYaw.A[2];
  workYaw.KKT[945] = -paramsYaw.A[3];
  workYaw.KKT[948] = -paramsYaw.A[4];
  workYaw.KKT[828] = 1;
  workYaw.KKT[949] = 1;
  workYaw.KKT[744] = 1;
  workYaw.KKT[654] = -paramsYaw.B[0];
  workYaw.KKT[829] = -paramsYaw.A[0];
  workYaw.KKT[952] = -paramsYaw.A[1];
  workYaw.KKT[745] = -paramsYaw.A[2];
  workYaw.KKT[951] = -paramsYaw.A[3];
  workYaw.KKT[954] = -paramsYaw.A[4];
  workYaw.KKT[831] = 1;
  workYaw.KKT[955] = 1;
  workYaw.KKT[746] = 1;
  workYaw.KKT[656] = -paramsYaw.B[0];
  workYaw.KKT[832] = -paramsYaw.A[0];
  workYaw.KKT[958] = -paramsYaw.A[1];
  workYaw.KKT[747] = -paramsYaw.A[2];
  workYaw.KKT[957] = -paramsYaw.A[3];
  workYaw.KKT[960] = -paramsYaw.A[4];
  workYaw.KKT[834] = 1;
  workYaw.KKT[961] = 1;
  workYaw.KKT[748] = 1;
  workYaw.KKT[658] = -paramsYaw.B[0];
  workYaw.KKT[835] = -paramsYaw.A[0];
  workYaw.KKT[964] = -paramsYaw.A[1];
  workYaw.KKT[749] = -paramsYaw.A[2];
  workYaw.KKT[963] = -paramsYaw.A[3];
  workYaw.KKT[966] = -paramsYaw.A[4];
  workYaw.KKT[837] = 1;
  workYaw.KKT[967] = 1;
  workYaw.KKT[750] = 1;
  workYaw.KKT[660] = -paramsYaw.B[0];
  workYaw.KKT[838] = -paramsYaw.A[0];
  workYaw.KKT[970] = -paramsYaw.A[1];
  workYaw.KKT[751] = -paramsYaw.A[2];
  workYaw.KKT[969] = -paramsYaw.A[3];
  workYaw.KKT[972] = -paramsYaw.A[4];
  workYaw.KKT[840] = 1;
  workYaw.KKT[973] = 1;
  workYaw.KKT[752] = 1;
  workYaw.KKT[662] = -paramsYaw.B[0];
  workYaw.KKT[841] = -paramsYaw.A[0];
  workYaw.KKT[976] = -paramsYaw.A[1];
  workYaw.KKT[753] = -paramsYaw.A[2];
  workYaw.KKT[975] = -paramsYaw.A[3];
  workYaw.KKT[978] = -paramsYaw.A[4];
  workYaw.KKT[843] = 1;
  workYaw.KKT[979] = 1;
  workYaw.KKT[754] = 1;
  workYaw.KKT[664] = -paramsYaw.B[0];
  workYaw.KKT[844] = -paramsYaw.A[0];
  workYaw.KKT[982] = -paramsYaw.A[1];
  workYaw.KKT[755] = -paramsYaw.A[2];
  workYaw.KKT[981] = -paramsYaw.A[3];
  workYaw.KKT[984] = -paramsYaw.A[4];
  workYaw.KKT[846] = 1;
  workYaw.KKT[985] = 1;
  workYaw.KKT[756] = 1;
  workYaw.KKT[666] = -paramsYaw.B[0];
  workYaw.KKT[847] = -paramsYaw.A[0];
  workYaw.KKT[988] = -paramsYaw.A[1];
  workYaw.KKT[757] = -paramsYaw.A[2];
  workYaw.KKT[987] = -paramsYaw.A[3];
  workYaw.KKT[990] = -paramsYaw.A[4];
  workYaw.KKT[849] = 1;
  workYaw.KKT[991] = 1;
  workYaw.KKT[758] = 1;
  workYaw.KKT[668] = -paramsYaw.B[0];
  workYaw.KKT[850] = -paramsYaw.A[0];
  workYaw.KKT[994] = -paramsYaw.A[1];
  workYaw.KKT[759] = -paramsYaw.A[2];
  workYaw.KKT[993] = -paramsYaw.A[3];
  workYaw.KKT[996] = -paramsYaw.A[4];
  workYaw.KKT[852] = 1;
  workYaw.KKT[997] = 1;
  workYaw.KKT[760] = 1;
  workYaw.KKT[670] = -paramsYaw.B[0];
  workYaw.KKT[853] = -paramsYaw.A[0];
  workYaw.KKT[1000] = -paramsYaw.A[1];
  workYaw.KKT[761] = -paramsYaw.A[2];
  workYaw.KKT[999] = -paramsYaw.A[3];
  workYaw.KKT[1002] = -paramsYaw.A[4];
  workYaw.KKT[855] = 1;
  workYaw.KKT[1003] = 1;
  workYaw.KKT[762] = 1;
  workYaw.KKT[672] = -paramsYaw.B[0];
  workYaw.KKT[856] = -paramsYaw.A[0];
  workYaw.KKT[1006] = -paramsYaw.A[1];
  workYaw.KKT[763] = -paramsYaw.A[2];
  workYaw.KKT[1005] = -paramsYaw.A[3];
  workYaw.KKT[1008] = -paramsYaw.A[4];
  workYaw.KKT[858] = 1;
  workYaw.KKT[1009] = 1;
  workYaw.KKT[764] = 1;
  workYaw.KKT[674] = -paramsYaw.B[0];
  workYaw.KKT[859] = -paramsYaw.A[0];
  workYaw.KKT[1012] = -paramsYaw.A[1];
  workYaw.KKT[765] = -paramsYaw.A[2];
  workYaw.KKT[1011] = -paramsYaw.A[3];
  workYaw.KKT[1014] = -paramsYaw.A[4];
  workYaw.KKT[861] = 1;
  workYaw.KKT[1015] = 1;
  workYaw.KKT[766] = 1;
  workYaw.KKT[676] = -paramsYaw.B[0];
  workYaw.KKT[862] = -paramsYaw.A[0];
  workYaw.KKT[1018] = -paramsYaw.A[1];
  workYaw.KKT[767] = -paramsYaw.A[2];
  workYaw.KKT[1017] = -paramsYaw.A[3];
  workYaw.KKT[1020] = -paramsYaw.A[4];
  workYaw.KKT[864] = 1;
  workYaw.KKT[1021] = 1;
  workYaw.KKT[768] = 1;
  workYaw.KKT[678] = -paramsYaw.B[0];
  workYaw.KKT[865] = -paramsYaw.A[0];
  workYaw.KKT[1024] = -paramsYaw.A[1];
  workYaw.KKT[769] = -paramsYaw.A[2];
  workYaw.KKT[1023] = -paramsYaw.A[3];
  workYaw.KKT[1026] = -paramsYaw.A[4];
  workYaw.KKT[867] = 1;
  workYaw.KKT[1027] = 1;
  workYaw.KKT[770] = 1;
  workYaw.KKT[680] = -paramsYaw.B[0];
  workYaw.KKT[868] = -paramsYaw.A[0];
  workYaw.KKT[1030] = -paramsYaw.A[1];
  workYaw.KKT[771] = -paramsYaw.A[2];
  workYaw.KKT[1029] = -paramsYaw.A[3];
  workYaw.KKT[1032] = -paramsYaw.A[4];
  workYaw.KKT[870] = 1;
  workYaw.KKT[1033] = 1;
  workYaw.KKT[772] = 1;
  workYaw.KKT[682] = -paramsYaw.B[0];
  workYaw.KKT[871] = -paramsYaw.A[0];
  workYaw.KKT[1036] = -paramsYaw.A[1];
  workYaw.KKT[773] = -paramsYaw.A[2];
  workYaw.KKT[1035] = -paramsYaw.A[3];
  workYaw.KKT[1038] = -paramsYaw.A[4];
  workYaw.KKT[873] = 1;
  workYaw.KKT[1039] = 1;
  workYaw.KKT[774] = 1;
  workYaw.KKT[684] = -paramsYaw.B[0];
  workYaw.KKT[874] = -paramsYaw.A[0];
  workYaw.KKT[1042] = -paramsYaw.A[1];
  workYaw.KKT[775] = -paramsYaw.A[2];
  workYaw.KKT[1041] = -paramsYaw.A[3];
  workYaw.KKT[1044] = -paramsYaw.A[4];
  workYaw.KKT[876] = 1;
  workYaw.KKT[1045] = 1;
  workYaw.KKT[776] = 1;
  workYaw.KKT[686] = -paramsYaw.B[0];
  workYaw.KKT[877] = -paramsYaw.A[0];
  workYaw.KKT[1048] = -paramsYaw.A[1];
  workYaw.KKT[777] = -paramsYaw.A[2];
  workYaw.KKT[1047] = -paramsYaw.A[3];
  workYaw.KKT[1050] = -paramsYaw.A[4];
  workYaw.KKT[879] = 1;
  workYaw.KKT[1051] = 1;
  workYaw.KKT[778] = 1;
  workYaw.KKT[688] = -paramsYaw.B[0];
  workYaw.KKT[880] = -paramsYaw.A[0];
  workYaw.KKT[1054] = -paramsYaw.A[1];
  workYaw.KKT[779] = -paramsYaw.A[2];
  workYaw.KKT[1053] = -paramsYaw.A[3];
  workYaw.KKT[1056] = -paramsYaw.A[4];
  workYaw.KKT[882] = 1;
  workYaw.KKT[1057] = 1;
  workYaw.KKT[780] = 1;
  workYaw.KKT[690] = -paramsYaw.B[0];
  workYaw.KKT[883] = -paramsYaw.A[0];
  workYaw.KKT[1060] = -paramsYaw.A[1];
  workYaw.KKT[781] = -paramsYaw.A[2];
  workYaw.KKT[1059] = -paramsYaw.A[3];
  workYaw.KKT[1062] = -paramsYaw.A[4];
  workYaw.KKT[885] = 1;
  workYaw.KKT[1063] = 1;
  workYaw.KKT[782] = 1;
  workYaw.KKT[692] = -paramsYaw.B[0];
  workYaw.KKT[886] = -paramsYaw.A[0];
  workYaw.KKT[1066] = -paramsYaw.A[1];
  workYaw.KKT[783] = -paramsYaw.A[2];
  workYaw.KKT[1065] = -paramsYaw.A[3];
  workYaw.KKT[1068] = -paramsYaw.A[4];
  workYaw.KKT[888] = 1;
  workYaw.KKT[1069] = 1;
  workYaw.KKT[784] = 1;
  workYaw.KKT[694] = -paramsYaw.B[0];
  workYaw.KKT[889] = -paramsYaw.A[0];
  workYaw.KKT[1072] = -paramsYaw.A[1];
  workYaw.KKT[785] = -paramsYaw.A[2];
  workYaw.KKT[1071] = -paramsYaw.A[3];
  workYaw.KKT[1074] = -paramsYaw.A[4];
  workYaw.KKT[891] = 1;
  workYaw.KKT[1075] = 1;
  workYaw.KKT[786] = 1;
  workYaw.KKT[696] = -paramsYaw.B[0];
  workYaw.KKT[892] = -paramsYaw.A[0];
  workYaw.KKT[1078] = -paramsYaw.A[1];
  workYaw.KKT[787] = -paramsYaw.A[2];
  workYaw.KKT[1077] = -paramsYaw.A[3];
  workYaw.KKT[1080] = -paramsYaw.A[4];
  workYaw.KKT[894] = 1;
  workYaw.KKT[1081] = 1;
  workYaw.KKT[788] = 1;
  workYaw.KKT[698] = -paramsYaw.B[0];
  workYaw.KKT[895] = -paramsYaw.A[0];
  workYaw.KKT[1084] = -paramsYaw.A[1];
  workYaw.KKT[789] = -paramsYaw.A[2];
  workYaw.KKT[1083] = -paramsYaw.A[3];
  workYaw.KKT[1086] = -paramsYaw.A[4];
  workYaw.KKT[897] = 1;
  workYaw.KKT[1087] = 1;
  workYaw.KKT[790] = 1;
  workYaw.KKT[700] = -paramsYaw.B[0];
  workYaw.KKT[898] = -paramsYaw.A[0];
  workYaw.KKT[1090] = -paramsYaw.A[1];
  workYaw.KKT[791] = -paramsYaw.A[2];
  workYaw.KKT[1089] = -paramsYaw.A[3];
  workYaw.KKT[1092] = -paramsYaw.A[4];
  workYaw.KKT[900] = 1;
  workYaw.KKT[1093] = 1;
  workYaw.KKT[792] = 1;
  workYaw.KKT[702] = -paramsYaw.B[0];
  workYaw.KKT[901] = -paramsYaw.A[0];
  workYaw.KKT[1096] = -paramsYaw.A[1];
  workYaw.KKT[793] = -paramsYaw.A[2];
  workYaw.KKT[1095] = -paramsYaw.A[3];
  workYaw.KKT[1098] = -paramsYaw.A[4];
  workYaw.KKT[903] = 1;
  workYaw.KKT[1099] = 1;
  workYaw.KKT[794] = 1;
  workYaw.KKT[704] = -paramsYaw.B[0];
  workYaw.KKT[904] = -paramsYaw.A[0];
  workYaw.KKT[1102] = -paramsYaw.A[1];
  workYaw.KKT[795] = -paramsYaw.A[2];
  workYaw.KKT[1101] = -paramsYaw.A[3];
  workYaw.KKT[1104] = -paramsYaw.A[4];
  workYaw.KKT[906] = 1;
  workYaw.KKT[1105] = 1;
  workYaw.KKT[796] = 1;
  workYaw.KKT[706] = -paramsYaw.B[0];
  workYaw.KKT[907] = -paramsYaw.A[0];
  workYaw.KKT[1108] = -paramsYaw.A[1];
  workYaw.KKT[797] = -paramsYaw.A[2];
  workYaw.KKT[1107] = -paramsYaw.A[3];
  workYaw.KKT[1110] = -paramsYaw.A[4];
  workYaw.KKT[909] = 1;
  workYaw.KKT[1111] = 1;
  workYaw.KKT[798] = 1;
  workYaw.KKT[708] = -paramsYaw.B[0];
  workYaw.KKT[910] = -paramsYaw.A[0];
  workYaw.KKT[1114] = -paramsYaw.A[1];
  workYaw.KKT[799] = -paramsYaw.A[2];
  workYaw.KKT[1113] = -paramsYaw.A[3];
  workYaw.KKT[1116] = -paramsYaw.A[4];
  workYaw.KKT[912] = 1;
  workYaw.KKT[1117] = 1;
  workYaw.KKT[800] = 1;
  workYaw.KKT[710] = -paramsYaw.B[0];
  workYaw.KKT[913] = -paramsYaw.A[0];
  workYaw.KKT[1120] = -paramsYaw.A[1];
  workYaw.KKT[801] = -paramsYaw.A[2];
  workYaw.KKT[1119] = -paramsYaw.A[3];
  workYaw.KKT[1122] = -paramsYaw.A[4];
  workYaw.KKT[915] = 1;
  workYaw.KKT[1123] = 1;
  workYaw.KKT[802] = 1;
  workYaw.KKT[712] = -paramsYaw.B[0];
  workYaw.KKT[916] = -paramsYaw.A[0];
  workYaw.KKT[1126] = -paramsYaw.A[1];
  workYaw.KKT[803] = -paramsYaw.A[2];
  workYaw.KKT[1125] = -paramsYaw.A[3];
  workYaw.KKT[1128] = -paramsYaw.A[4];
  workYaw.KKT[918] = 1;
  workYaw.KKT[1129] = 1;
  workYaw.KKT[804] = 1;
  workYaw.KKT[714] = -paramsYaw.B[0];
  workYaw.KKT[919] = -paramsYaw.A[0];
  workYaw.KKT[1132] = -paramsYaw.A[1];
  workYaw.KKT[805] = -paramsYaw.A[2];
  workYaw.KKT[1131] = -paramsYaw.A[3];
  workYaw.KKT[1134] = -paramsYaw.A[4];
  workYaw.KKT[921] = 1;
  workYaw.KKT[1135] = 1;
  workYaw.KKT[806] = 1;
  workYaw.KKT[716] = -paramsYaw.B[0];
  workYaw.KKT[922] = -paramsYaw.A[0];
  workYaw.KKT[1138] = -paramsYaw.A[1];
  workYaw.KKT[807] = -paramsYaw.A[2];
  workYaw.KKT[1137] = -paramsYaw.A[3];
  workYaw.KKT[1140] = -paramsYaw.A[4];
  workYaw.KKT[924] = 1;
  workYaw.KKT[1141] = 1;
  workYaw.KKT[808] = 1;
  workYaw.KKT[718] = -paramsYaw.B[0];
  workYaw.KKT[925] = -paramsYaw.A[0];
  workYaw.KKT[1144] = -paramsYaw.A[1];
  workYaw.KKT[809] = -paramsYaw.A[2];
  workYaw.KKT[1143] = -paramsYaw.A[3];
  workYaw.KKT[1146] = -paramsYaw.A[4];
  workYaw.KKT[927] = 1;
  workYaw.KKT[1147] = 1;
  workYaw.KKT[810] = 1;
  workYaw.KKT[720] = -paramsYaw.B[0];
  workYaw.KKT[928] = -paramsYaw.A[0];
  workYaw.KKT[1149] = -paramsYaw.A[1];
  workYaw.KKT[811] = -paramsYaw.A[2];
  workYaw.KKT[1148] = -paramsYaw.A[3];
  workYaw.KKT[1150] = -paramsYaw.A[4];
  workYaw.KKT[930] = 1;
  workYaw.KKT[1151] = 1;
  workYaw.KKT[733] = 1;
  workYaw.KKT[722] = -paramsYaw.B[0];
  workYaw.KKT[812] = -paramsYaw.A[0];
  workYaw.KKT[814] = -paramsYaw.A[1];
  workYaw.KKT[725] = -paramsYaw.A[2];
  workYaw.KKT[813] = -paramsYaw.A[3];
  workYaw.KKT[734] = -paramsYaw.A[4];
  workYaw.KKT[729] = 1;
  workYaw.KKT[731] = 1;
  workYaw.KKT[724] = 1;
}
