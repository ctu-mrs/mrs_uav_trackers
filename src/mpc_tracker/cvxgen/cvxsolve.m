% Produced by CVXGEN, 2018-08-14 08:45:33 -0400.
% CVXGEN is Copyright (C) 2006-2017 Jacob Mattingley, jem@cvxgen.com.
% The code in this file is Copyright (C) 2006-2017 Jacob Mattingley.
% CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial
% applications without prior written permission from Jacob Mattingley.

% Filename: cvxsolve.m.
% Description: Solution file, via cvx, for use with sample.m.
function [vars, status] = cvxsolve(params, settings)
A = params.A;
Af = params.Af;
B = params.B;
Bf = params.Bf;
Q = params.Q;
R = params.R;
R2 = params.R2;
u_max_0 = params.u_max_0;
if isfield(params, 'u_max_1')
  u_max_1 = params.u_max_1;
elseif isfield(params, 'u_max')
  u_max_1 = params.u_max{1};
else
  error 'could not find u_max_1'
end
if isfield(params, 'u_max_2')
  u_max_2 = params.u_max_2;
elseif isfield(params, 'u_max')
  u_max_2 = params.u_max{2};
else
  error 'could not find u_max_2'
end
if isfield(params, 'u_max_3')
  u_max_3 = params.u_max_3;
elseif isfield(params, 'u_max')
  u_max_3 = params.u_max{3};
else
  error 'could not find u_max_3'
end
if isfield(params, 'u_max_4')
  u_max_4 = params.u_max_4;
elseif isfield(params, 'u_max')
  u_max_4 = params.u_max{4};
else
  error 'could not find u_max_4'
end
if isfield(params, 'u_max_5')
  u_max_5 = params.u_max_5;
elseif isfield(params, 'u_max')
  u_max_5 = params.u_max{5};
else
  error 'could not find u_max_5'
end
if isfield(params, 'u_max_6')
  u_max_6 = params.u_max_6;
elseif isfield(params, 'u_max')
  u_max_6 = params.u_max{6};
else
  error 'could not find u_max_6'
end
if isfield(params, 'u_max_7')
  u_max_7 = params.u_max_7;
elseif isfield(params, 'u_max')
  u_max_7 = params.u_max{7};
else
  error 'could not find u_max_7'
end
if isfield(params, 'u_max_8')
  u_max_8 = params.u_max_8;
elseif isfield(params, 'u_max')
  u_max_8 = params.u_max{8};
else
  error 'could not find u_max_8'
end
if isfield(params, 'u_max_9')
  u_max_9 = params.u_max_9;
elseif isfield(params, 'u_max')
  u_max_9 = params.u_max{9};
else
  error 'could not find u_max_9'
end
if isfield(params, 'u_max_10')
  u_max_10 = params.u_max_10;
elseif isfield(params, 'u_max')
  u_max_10 = params.u_max{10};
else
  error 'could not find u_max_10'
end
if isfield(params, 'u_max_11')
  u_max_11 = params.u_max_11;
elseif isfield(params, 'u_max')
  u_max_11 = params.u_max{11};
else
  error 'could not find u_max_11'
end
if isfield(params, 'u_max_12')
  u_max_12 = params.u_max_12;
elseif isfield(params, 'u_max')
  u_max_12 = params.u_max{12};
else
  error 'could not find u_max_12'
end
if isfield(params, 'u_max_13')
  u_max_13 = params.u_max_13;
elseif isfield(params, 'u_max')
  u_max_13 = params.u_max{13};
else
  error 'could not find u_max_13'
end
if isfield(params, 'u_max_14')
  u_max_14 = params.u_max_14;
elseif isfield(params, 'u_max')
  u_max_14 = params.u_max{14};
else
  error 'could not find u_max_14'
end
if isfield(params, 'u_max_15')
  u_max_15 = params.u_max_15;
elseif isfield(params, 'u_max')
  u_max_15 = params.u_max{15};
else
  error 'could not find u_max_15'
end
if isfield(params, 'u_max_16')
  u_max_16 = params.u_max_16;
elseif isfield(params, 'u_max')
  u_max_16 = params.u_max{16};
else
  error 'could not find u_max_16'
end
if isfield(params, 'u_max_17')
  u_max_17 = params.u_max_17;
elseif isfield(params, 'u_max')
  u_max_17 = params.u_max{17};
else
  error 'could not find u_max_17'
end
if isfield(params, 'u_max_18')
  u_max_18 = params.u_max_18;
elseif isfield(params, 'u_max')
  u_max_18 = params.u_max{18};
else
  error 'could not find u_max_18'
end
if isfield(params, 'u_max_19')
  u_max_19 = params.u_max_19;
elseif isfield(params, 'u_max')
  u_max_19 = params.u_max{19};
else
  error 'could not find u_max_19'
end
if isfield(params, 'u_max_20')
  u_max_20 = params.u_max_20;
elseif isfield(params, 'u_max')
  u_max_20 = params.u_max{20};
else
  error 'could not find u_max_20'
end
if isfield(params, 'u_max_21')
  u_max_21 = params.u_max_21;
elseif isfield(params, 'u_max')
  u_max_21 = params.u_max{21};
else
  error 'could not find u_max_21'
end
if isfield(params, 'u_max_22')
  u_max_22 = params.u_max_22;
elseif isfield(params, 'u_max')
  u_max_22 = params.u_max{22};
else
  error 'could not find u_max_22'
end
if isfield(params, 'u_max_23')
  u_max_23 = params.u_max_23;
elseif isfield(params, 'u_max')
  u_max_23 = params.u_max{23};
else
  error 'could not find u_max_23'
end
if isfield(params, 'u_max_24')
  u_max_24 = params.u_max_24;
elseif isfield(params, 'u_max')
  u_max_24 = params.u_max{24};
else
  error 'could not find u_max_24'
end
if isfield(params, 'u_max_25')
  u_max_25 = params.u_max_25;
elseif isfield(params, 'u_max')
  u_max_25 = params.u_max{25};
else
  error 'could not find u_max_25'
end
if isfield(params, 'u_max_26')
  u_max_26 = params.u_max_26;
elseif isfield(params, 'u_max')
  u_max_26 = params.u_max{26};
else
  error 'could not find u_max_26'
end
if isfield(params, 'u_max_27')
  u_max_27 = params.u_max_27;
elseif isfield(params, 'u_max')
  u_max_27 = params.u_max{27};
else
  error 'could not find u_max_27'
end
if isfield(params, 'u_max_28')
  u_max_28 = params.u_max_28;
elseif isfield(params, 'u_max')
  u_max_28 = params.u_max{28};
else
  error 'could not find u_max_28'
end
if isfield(params, 'u_max_29')
  u_max_29 = params.u_max_29;
elseif isfield(params, 'u_max')
  u_max_29 = params.u_max{29};
else
  error 'could not find u_max_29'
end
if isfield(params, 'u_max_30')
  u_max_30 = params.u_max_30;
elseif isfield(params, 'u_max')
  u_max_30 = params.u_max{30};
else
  error 'could not find u_max_30'
end
if isfield(params, 'u_max_31')
  u_max_31 = params.u_max_31;
elseif isfield(params, 'u_max')
  u_max_31 = params.u_max{31};
else
  error 'could not find u_max_31'
end
if isfield(params, 'u_max_32')
  u_max_32 = params.u_max_32;
elseif isfield(params, 'u_max')
  u_max_32 = params.u_max{32};
else
  error 'could not find u_max_32'
end
if isfield(params, 'u_max_33')
  u_max_33 = params.u_max_33;
elseif isfield(params, 'u_max')
  u_max_33 = params.u_max{33};
else
  error 'could not find u_max_33'
end
if isfield(params, 'u_max_34')
  u_max_34 = params.u_max_34;
elseif isfield(params, 'u_max')
  u_max_34 = params.u_max{34};
else
  error 'could not find u_max_34'
end
if isfield(params, 'u_max_35')
  u_max_35 = params.u_max_35;
elseif isfield(params, 'u_max')
  u_max_35 = params.u_max{35};
else
  error 'could not find u_max_35'
end
if isfield(params, 'u_max_36')
  u_max_36 = params.u_max_36;
elseif isfield(params, 'u_max')
  u_max_36 = params.u_max{36};
else
  error 'could not find u_max_36'
end
if isfield(params, 'u_max_37')
  u_max_37 = params.u_max_37;
elseif isfield(params, 'u_max')
  u_max_37 = params.u_max{37};
else
  error 'could not find u_max_37'
end
if isfield(params, 'u_max_38')
  u_max_38 = params.u_max_38;
elseif isfield(params, 'u_max')
  u_max_38 = params.u_max{38};
else
  error 'could not find u_max_38'
end
if isfield(params, 'u_max_39')
  u_max_39 = params.u_max_39;
elseif isfield(params, 'u_max')
  u_max_39 = params.u_max{39};
else
  error 'could not find u_max_39'
end
u_min_0 = params.u_min_0;
if isfield(params, 'u_min_1')
  u_min_1 = params.u_min_1;
elseif isfield(params, 'u_min')
  u_min_1 = params.u_min{1};
else
  error 'could not find u_min_1'
end
if isfield(params, 'u_min_2')
  u_min_2 = params.u_min_2;
elseif isfield(params, 'u_min')
  u_min_2 = params.u_min{2};
else
  error 'could not find u_min_2'
end
if isfield(params, 'u_min_3')
  u_min_3 = params.u_min_3;
elseif isfield(params, 'u_min')
  u_min_3 = params.u_min{3};
else
  error 'could not find u_min_3'
end
if isfield(params, 'u_min_4')
  u_min_4 = params.u_min_4;
elseif isfield(params, 'u_min')
  u_min_4 = params.u_min{4};
else
  error 'could not find u_min_4'
end
if isfield(params, 'u_min_5')
  u_min_5 = params.u_min_5;
elseif isfield(params, 'u_min')
  u_min_5 = params.u_min{5};
else
  error 'could not find u_min_5'
end
if isfield(params, 'u_min_6')
  u_min_6 = params.u_min_6;
elseif isfield(params, 'u_min')
  u_min_6 = params.u_min{6};
else
  error 'could not find u_min_6'
end
if isfield(params, 'u_min_7')
  u_min_7 = params.u_min_7;
elseif isfield(params, 'u_min')
  u_min_7 = params.u_min{7};
else
  error 'could not find u_min_7'
end
if isfield(params, 'u_min_8')
  u_min_8 = params.u_min_8;
elseif isfield(params, 'u_min')
  u_min_8 = params.u_min{8};
else
  error 'could not find u_min_8'
end
if isfield(params, 'u_min_9')
  u_min_9 = params.u_min_9;
elseif isfield(params, 'u_min')
  u_min_9 = params.u_min{9};
else
  error 'could not find u_min_9'
end
if isfield(params, 'u_min_10')
  u_min_10 = params.u_min_10;
elseif isfield(params, 'u_min')
  u_min_10 = params.u_min{10};
else
  error 'could not find u_min_10'
end
if isfield(params, 'u_min_11')
  u_min_11 = params.u_min_11;
elseif isfield(params, 'u_min')
  u_min_11 = params.u_min{11};
else
  error 'could not find u_min_11'
end
if isfield(params, 'u_min_12')
  u_min_12 = params.u_min_12;
elseif isfield(params, 'u_min')
  u_min_12 = params.u_min{12};
else
  error 'could not find u_min_12'
end
if isfield(params, 'u_min_13')
  u_min_13 = params.u_min_13;
elseif isfield(params, 'u_min')
  u_min_13 = params.u_min{13};
else
  error 'could not find u_min_13'
end
if isfield(params, 'u_min_14')
  u_min_14 = params.u_min_14;
elseif isfield(params, 'u_min')
  u_min_14 = params.u_min{14};
else
  error 'could not find u_min_14'
end
if isfield(params, 'u_min_15')
  u_min_15 = params.u_min_15;
elseif isfield(params, 'u_min')
  u_min_15 = params.u_min{15};
else
  error 'could not find u_min_15'
end
if isfield(params, 'u_min_16')
  u_min_16 = params.u_min_16;
elseif isfield(params, 'u_min')
  u_min_16 = params.u_min{16};
else
  error 'could not find u_min_16'
end
if isfield(params, 'u_min_17')
  u_min_17 = params.u_min_17;
elseif isfield(params, 'u_min')
  u_min_17 = params.u_min{17};
else
  error 'could not find u_min_17'
end
if isfield(params, 'u_min_18')
  u_min_18 = params.u_min_18;
elseif isfield(params, 'u_min')
  u_min_18 = params.u_min{18};
else
  error 'could not find u_min_18'
end
if isfield(params, 'u_min_19')
  u_min_19 = params.u_min_19;
elseif isfield(params, 'u_min')
  u_min_19 = params.u_min{19};
else
  error 'could not find u_min_19'
end
if isfield(params, 'u_min_20')
  u_min_20 = params.u_min_20;
elseif isfield(params, 'u_min')
  u_min_20 = params.u_min{20};
else
  error 'could not find u_min_20'
end
if isfield(params, 'u_min_21')
  u_min_21 = params.u_min_21;
elseif isfield(params, 'u_min')
  u_min_21 = params.u_min{21};
else
  error 'could not find u_min_21'
end
if isfield(params, 'u_min_22')
  u_min_22 = params.u_min_22;
elseif isfield(params, 'u_min')
  u_min_22 = params.u_min{22};
else
  error 'could not find u_min_22'
end
if isfield(params, 'u_min_23')
  u_min_23 = params.u_min_23;
elseif isfield(params, 'u_min')
  u_min_23 = params.u_min{23};
else
  error 'could not find u_min_23'
end
if isfield(params, 'u_min_24')
  u_min_24 = params.u_min_24;
elseif isfield(params, 'u_min')
  u_min_24 = params.u_min{24};
else
  error 'could not find u_min_24'
end
if isfield(params, 'u_min_25')
  u_min_25 = params.u_min_25;
elseif isfield(params, 'u_min')
  u_min_25 = params.u_min{25};
else
  error 'could not find u_min_25'
end
if isfield(params, 'u_min_26')
  u_min_26 = params.u_min_26;
elseif isfield(params, 'u_min')
  u_min_26 = params.u_min{26};
else
  error 'could not find u_min_26'
end
if isfield(params, 'u_min_27')
  u_min_27 = params.u_min_27;
elseif isfield(params, 'u_min')
  u_min_27 = params.u_min{27};
else
  error 'could not find u_min_27'
end
if isfield(params, 'u_min_28')
  u_min_28 = params.u_min_28;
elseif isfield(params, 'u_min')
  u_min_28 = params.u_min{28};
else
  error 'could not find u_min_28'
end
if isfield(params, 'u_min_29')
  u_min_29 = params.u_min_29;
elseif isfield(params, 'u_min')
  u_min_29 = params.u_min{29};
else
  error 'could not find u_min_29'
end
if isfield(params, 'u_min_30')
  u_min_30 = params.u_min_30;
elseif isfield(params, 'u_min')
  u_min_30 = params.u_min{30};
else
  error 'could not find u_min_30'
end
if isfield(params, 'u_min_31')
  u_min_31 = params.u_min_31;
elseif isfield(params, 'u_min')
  u_min_31 = params.u_min{31};
else
  error 'could not find u_min_31'
end
if isfield(params, 'u_min_32')
  u_min_32 = params.u_min_32;
elseif isfield(params, 'u_min')
  u_min_32 = params.u_min{32};
else
  error 'could not find u_min_32'
end
if isfield(params, 'u_min_33')
  u_min_33 = params.u_min_33;
elseif isfield(params, 'u_min')
  u_min_33 = params.u_min{33};
else
  error 'could not find u_min_33'
end
if isfield(params, 'u_min_34')
  u_min_34 = params.u_min_34;
elseif isfield(params, 'u_min')
  u_min_34 = params.u_min{34};
else
  error 'could not find u_min_34'
end
if isfield(params, 'u_min_35')
  u_min_35 = params.u_min_35;
elseif isfield(params, 'u_min')
  u_min_35 = params.u_min{35};
else
  error 'could not find u_min_35'
end
if isfield(params, 'u_min_36')
  u_min_36 = params.u_min_36;
elseif isfield(params, 'u_min')
  u_min_36 = params.u_min{36};
else
  error 'could not find u_min_36'
end
if isfield(params, 'u_min_37')
  u_min_37 = params.u_min_37;
elseif isfield(params, 'u_min')
  u_min_37 = params.u_min{37};
else
  error 'could not find u_min_37'
end
if isfield(params, 'u_min_38')
  u_min_38 = params.u_min_38;
elseif isfield(params, 'u_min')
  u_min_38 = params.u_min{38};
else
  error 'could not find u_min_38'
end
if isfield(params, 'u_min_39')
  u_min_39 = params.u_min_39;
elseif isfield(params, 'u_min')
  u_min_39 = params.u_min{39};
else
  error 'could not find u_min_39'
end
x_0 = params.x_0;
if isfield(params, 'x_max_2_1')
  x_max_2_1 = params.x_max_2_1;
elseif isfield(params, 'x_max_2')
  x_max_2_1 = params.x_max_2{1};
else
  error 'could not find x_max_2_1'
end
if isfield(params, 'x_max_2_2')
  x_max_2_2 = params.x_max_2_2;
elseif isfield(params, 'x_max_2')
  x_max_2_2 = params.x_max_2{2};
else
  error 'could not find x_max_2_2'
end
if isfield(params, 'x_max_2_3')
  x_max_2_3 = params.x_max_2_3;
elseif isfield(params, 'x_max_2')
  x_max_2_3 = params.x_max_2{3};
else
  error 'could not find x_max_2_3'
end
if isfield(params, 'x_max_2_4')
  x_max_2_4 = params.x_max_2_4;
elseif isfield(params, 'x_max_2')
  x_max_2_4 = params.x_max_2{4};
else
  error 'could not find x_max_2_4'
end
if isfield(params, 'x_max_2_5')
  x_max_2_5 = params.x_max_2_5;
elseif isfield(params, 'x_max_2')
  x_max_2_5 = params.x_max_2{5};
else
  error 'could not find x_max_2_5'
end
if isfield(params, 'x_max_2_6')
  x_max_2_6 = params.x_max_2_6;
elseif isfield(params, 'x_max_2')
  x_max_2_6 = params.x_max_2{6};
else
  error 'could not find x_max_2_6'
end
if isfield(params, 'x_max_2_7')
  x_max_2_7 = params.x_max_2_7;
elseif isfield(params, 'x_max_2')
  x_max_2_7 = params.x_max_2{7};
else
  error 'could not find x_max_2_7'
end
if isfield(params, 'x_max_2_8')
  x_max_2_8 = params.x_max_2_8;
elseif isfield(params, 'x_max_2')
  x_max_2_8 = params.x_max_2{8};
else
  error 'could not find x_max_2_8'
end
if isfield(params, 'x_max_2_9')
  x_max_2_9 = params.x_max_2_9;
elseif isfield(params, 'x_max_2')
  x_max_2_9 = params.x_max_2{9};
else
  error 'could not find x_max_2_9'
end
if isfield(params, 'x_max_2_10')
  x_max_2_10 = params.x_max_2_10;
elseif isfield(params, 'x_max_2')
  x_max_2_10 = params.x_max_2{10};
else
  error 'could not find x_max_2_10'
end
if isfield(params, 'x_max_2_11')
  x_max_2_11 = params.x_max_2_11;
elseif isfield(params, 'x_max_2')
  x_max_2_11 = params.x_max_2{11};
else
  error 'could not find x_max_2_11'
end
if isfield(params, 'x_max_2_12')
  x_max_2_12 = params.x_max_2_12;
elseif isfield(params, 'x_max_2')
  x_max_2_12 = params.x_max_2{12};
else
  error 'could not find x_max_2_12'
end
if isfield(params, 'x_max_2_13')
  x_max_2_13 = params.x_max_2_13;
elseif isfield(params, 'x_max_2')
  x_max_2_13 = params.x_max_2{13};
else
  error 'could not find x_max_2_13'
end
if isfield(params, 'x_max_2_14')
  x_max_2_14 = params.x_max_2_14;
elseif isfield(params, 'x_max_2')
  x_max_2_14 = params.x_max_2{14};
else
  error 'could not find x_max_2_14'
end
if isfield(params, 'x_max_2_15')
  x_max_2_15 = params.x_max_2_15;
elseif isfield(params, 'x_max_2')
  x_max_2_15 = params.x_max_2{15};
else
  error 'could not find x_max_2_15'
end
if isfield(params, 'x_max_2_16')
  x_max_2_16 = params.x_max_2_16;
elseif isfield(params, 'x_max_2')
  x_max_2_16 = params.x_max_2{16};
else
  error 'could not find x_max_2_16'
end
if isfield(params, 'x_max_2_17')
  x_max_2_17 = params.x_max_2_17;
elseif isfield(params, 'x_max_2')
  x_max_2_17 = params.x_max_2{17};
else
  error 'could not find x_max_2_17'
end
if isfield(params, 'x_max_2_18')
  x_max_2_18 = params.x_max_2_18;
elseif isfield(params, 'x_max_2')
  x_max_2_18 = params.x_max_2{18};
else
  error 'could not find x_max_2_18'
end
if isfield(params, 'x_max_2_19')
  x_max_2_19 = params.x_max_2_19;
elseif isfield(params, 'x_max_2')
  x_max_2_19 = params.x_max_2{19};
else
  error 'could not find x_max_2_19'
end
if isfield(params, 'x_max_2_20')
  x_max_2_20 = params.x_max_2_20;
elseif isfield(params, 'x_max_2')
  x_max_2_20 = params.x_max_2{20};
else
  error 'could not find x_max_2_20'
end
if isfield(params, 'x_max_2_21')
  x_max_2_21 = params.x_max_2_21;
elseif isfield(params, 'x_max_2')
  x_max_2_21 = params.x_max_2{21};
else
  error 'could not find x_max_2_21'
end
if isfield(params, 'x_max_2_22')
  x_max_2_22 = params.x_max_2_22;
elseif isfield(params, 'x_max_2')
  x_max_2_22 = params.x_max_2{22};
else
  error 'could not find x_max_2_22'
end
if isfield(params, 'x_max_2_23')
  x_max_2_23 = params.x_max_2_23;
elseif isfield(params, 'x_max_2')
  x_max_2_23 = params.x_max_2{23};
else
  error 'could not find x_max_2_23'
end
if isfield(params, 'x_max_2_24')
  x_max_2_24 = params.x_max_2_24;
elseif isfield(params, 'x_max_2')
  x_max_2_24 = params.x_max_2{24};
else
  error 'could not find x_max_2_24'
end
if isfield(params, 'x_max_2_25')
  x_max_2_25 = params.x_max_2_25;
elseif isfield(params, 'x_max_2')
  x_max_2_25 = params.x_max_2{25};
else
  error 'could not find x_max_2_25'
end
if isfield(params, 'x_max_2_26')
  x_max_2_26 = params.x_max_2_26;
elseif isfield(params, 'x_max_2')
  x_max_2_26 = params.x_max_2{26};
else
  error 'could not find x_max_2_26'
end
if isfield(params, 'x_max_2_27')
  x_max_2_27 = params.x_max_2_27;
elseif isfield(params, 'x_max_2')
  x_max_2_27 = params.x_max_2{27};
else
  error 'could not find x_max_2_27'
end
if isfield(params, 'x_max_2_28')
  x_max_2_28 = params.x_max_2_28;
elseif isfield(params, 'x_max_2')
  x_max_2_28 = params.x_max_2{28};
else
  error 'could not find x_max_2_28'
end
if isfield(params, 'x_max_2_29')
  x_max_2_29 = params.x_max_2_29;
elseif isfield(params, 'x_max_2')
  x_max_2_29 = params.x_max_2{29};
else
  error 'could not find x_max_2_29'
end
if isfield(params, 'x_max_2_30')
  x_max_2_30 = params.x_max_2_30;
elseif isfield(params, 'x_max_2')
  x_max_2_30 = params.x_max_2{30};
else
  error 'could not find x_max_2_30'
end
if isfield(params, 'x_max_2_31')
  x_max_2_31 = params.x_max_2_31;
elseif isfield(params, 'x_max_2')
  x_max_2_31 = params.x_max_2{31};
else
  error 'could not find x_max_2_31'
end
if isfield(params, 'x_max_2_32')
  x_max_2_32 = params.x_max_2_32;
elseif isfield(params, 'x_max_2')
  x_max_2_32 = params.x_max_2{32};
else
  error 'could not find x_max_2_32'
end
if isfield(params, 'x_max_2_33')
  x_max_2_33 = params.x_max_2_33;
elseif isfield(params, 'x_max_2')
  x_max_2_33 = params.x_max_2{33};
else
  error 'could not find x_max_2_33'
end
if isfield(params, 'x_max_2_34')
  x_max_2_34 = params.x_max_2_34;
elseif isfield(params, 'x_max_2')
  x_max_2_34 = params.x_max_2{34};
else
  error 'could not find x_max_2_34'
end
if isfield(params, 'x_max_2_35')
  x_max_2_35 = params.x_max_2_35;
elseif isfield(params, 'x_max_2')
  x_max_2_35 = params.x_max_2{35};
else
  error 'could not find x_max_2_35'
end
if isfield(params, 'x_max_2_36')
  x_max_2_36 = params.x_max_2_36;
elseif isfield(params, 'x_max_2')
  x_max_2_36 = params.x_max_2{36};
else
  error 'could not find x_max_2_36'
end
if isfield(params, 'x_max_2_37')
  x_max_2_37 = params.x_max_2_37;
elseif isfield(params, 'x_max_2')
  x_max_2_37 = params.x_max_2{37};
else
  error 'could not find x_max_2_37'
end
if isfield(params, 'x_max_2_38')
  x_max_2_38 = params.x_max_2_38;
elseif isfield(params, 'x_max_2')
  x_max_2_38 = params.x_max_2{38};
else
  error 'could not find x_max_2_38'
end
if isfield(params, 'x_max_2_39')
  x_max_2_39 = params.x_max_2_39;
elseif isfield(params, 'x_max_2')
  x_max_2_39 = params.x_max_2{39};
else
  error 'could not find x_max_2_39'
end
if isfield(params, 'x_max_2_40')
  x_max_2_40 = params.x_max_2_40;
elseif isfield(params, 'x_max_2')
  x_max_2_40 = params.x_max_2{40};
else
  error 'could not find x_max_2_40'
end
if isfield(params, 'x_max_3_1')
  x_max_3_1 = params.x_max_3_1;
elseif isfield(params, 'x_max_3')
  x_max_3_1 = params.x_max_3{1};
else
  error 'could not find x_max_3_1'
end
if isfield(params, 'x_max_3_2')
  x_max_3_2 = params.x_max_3_2;
elseif isfield(params, 'x_max_3')
  x_max_3_2 = params.x_max_3{2};
else
  error 'could not find x_max_3_2'
end
if isfield(params, 'x_max_3_3')
  x_max_3_3 = params.x_max_3_3;
elseif isfield(params, 'x_max_3')
  x_max_3_3 = params.x_max_3{3};
else
  error 'could not find x_max_3_3'
end
if isfield(params, 'x_max_3_4')
  x_max_3_4 = params.x_max_3_4;
elseif isfield(params, 'x_max_3')
  x_max_3_4 = params.x_max_3{4};
else
  error 'could not find x_max_3_4'
end
if isfield(params, 'x_max_3_5')
  x_max_3_5 = params.x_max_3_5;
elseif isfield(params, 'x_max_3')
  x_max_3_5 = params.x_max_3{5};
else
  error 'could not find x_max_3_5'
end
if isfield(params, 'x_max_3_6')
  x_max_3_6 = params.x_max_3_6;
elseif isfield(params, 'x_max_3')
  x_max_3_6 = params.x_max_3{6};
else
  error 'could not find x_max_3_6'
end
if isfield(params, 'x_max_3_7')
  x_max_3_7 = params.x_max_3_7;
elseif isfield(params, 'x_max_3')
  x_max_3_7 = params.x_max_3{7};
else
  error 'could not find x_max_3_7'
end
if isfield(params, 'x_max_3_8')
  x_max_3_8 = params.x_max_3_8;
elseif isfield(params, 'x_max_3')
  x_max_3_8 = params.x_max_3{8};
else
  error 'could not find x_max_3_8'
end
if isfield(params, 'x_max_3_9')
  x_max_3_9 = params.x_max_3_9;
elseif isfield(params, 'x_max_3')
  x_max_3_9 = params.x_max_3{9};
else
  error 'could not find x_max_3_9'
end
if isfield(params, 'x_max_3_10')
  x_max_3_10 = params.x_max_3_10;
elseif isfield(params, 'x_max_3')
  x_max_3_10 = params.x_max_3{10};
else
  error 'could not find x_max_3_10'
end
if isfield(params, 'x_max_3_11')
  x_max_3_11 = params.x_max_3_11;
elseif isfield(params, 'x_max_3')
  x_max_3_11 = params.x_max_3{11};
else
  error 'could not find x_max_3_11'
end
if isfield(params, 'x_max_3_12')
  x_max_3_12 = params.x_max_3_12;
elseif isfield(params, 'x_max_3')
  x_max_3_12 = params.x_max_3{12};
else
  error 'could not find x_max_3_12'
end
if isfield(params, 'x_max_3_13')
  x_max_3_13 = params.x_max_3_13;
elseif isfield(params, 'x_max_3')
  x_max_3_13 = params.x_max_3{13};
else
  error 'could not find x_max_3_13'
end
if isfield(params, 'x_max_3_14')
  x_max_3_14 = params.x_max_3_14;
elseif isfield(params, 'x_max_3')
  x_max_3_14 = params.x_max_3{14};
else
  error 'could not find x_max_3_14'
end
if isfield(params, 'x_max_3_15')
  x_max_3_15 = params.x_max_3_15;
elseif isfield(params, 'x_max_3')
  x_max_3_15 = params.x_max_3{15};
else
  error 'could not find x_max_3_15'
end
if isfield(params, 'x_max_3_16')
  x_max_3_16 = params.x_max_3_16;
elseif isfield(params, 'x_max_3')
  x_max_3_16 = params.x_max_3{16};
else
  error 'could not find x_max_3_16'
end
if isfield(params, 'x_max_3_17')
  x_max_3_17 = params.x_max_3_17;
elseif isfield(params, 'x_max_3')
  x_max_3_17 = params.x_max_3{17};
else
  error 'could not find x_max_3_17'
end
if isfield(params, 'x_max_3_18')
  x_max_3_18 = params.x_max_3_18;
elseif isfield(params, 'x_max_3')
  x_max_3_18 = params.x_max_3{18};
else
  error 'could not find x_max_3_18'
end
if isfield(params, 'x_max_3_19')
  x_max_3_19 = params.x_max_3_19;
elseif isfield(params, 'x_max_3')
  x_max_3_19 = params.x_max_3{19};
else
  error 'could not find x_max_3_19'
end
if isfield(params, 'x_max_3_20')
  x_max_3_20 = params.x_max_3_20;
elseif isfield(params, 'x_max_3')
  x_max_3_20 = params.x_max_3{20};
else
  error 'could not find x_max_3_20'
end
if isfield(params, 'x_max_3_21')
  x_max_3_21 = params.x_max_3_21;
elseif isfield(params, 'x_max_3')
  x_max_3_21 = params.x_max_3{21};
else
  error 'could not find x_max_3_21'
end
if isfield(params, 'x_max_3_22')
  x_max_3_22 = params.x_max_3_22;
elseif isfield(params, 'x_max_3')
  x_max_3_22 = params.x_max_3{22};
else
  error 'could not find x_max_3_22'
end
if isfield(params, 'x_max_3_23')
  x_max_3_23 = params.x_max_3_23;
elseif isfield(params, 'x_max_3')
  x_max_3_23 = params.x_max_3{23};
else
  error 'could not find x_max_3_23'
end
if isfield(params, 'x_max_3_24')
  x_max_3_24 = params.x_max_3_24;
elseif isfield(params, 'x_max_3')
  x_max_3_24 = params.x_max_3{24};
else
  error 'could not find x_max_3_24'
end
if isfield(params, 'x_max_3_25')
  x_max_3_25 = params.x_max_3_25;
elseif isfield(params, 'x_max_3')
  x_max_3_25 = params.x_max_3{25};
else
  error 'could not find x_max_3_25'
end
if isfield(params, 'x_max_3_26')
  x_max_3_26 = params.x_max_3_26;
elseif isfield(params, 'x_max_3')
  x_max_3_26 = params.x_max_3{26};
else
  error 'could not find x_max_3_26'
end
if isfield(params, 'x_max_3_27')
  x_max_3_27 = params.x_max_3_27;
elseif isfield(params, 'x_max_3')
  x_max_3_27 = params.x_max_3{27};
else
  error 'could not find x_max_3_27'
end
if isfield(params, 'x_max_3_28')
  x_max_3_28 = params.x_max_3_28;
elseif isfield(params, 'x_max_3')
  x_max_3_28 = params.x_max_3{28};
else
  error 'could not find x_max_3_28'
end
if isfield(params, 'x_max_3_29')
  x_max_3_29 = params.x_max_3_29;
elseif isfield(params, 'x_max_3')
  x_max_3_29 = params.x_max_3{29};
else
  error 'could not find x_max_3_29'
end
if isfield(params, 'x_max_3_30')
  x_max_3_30 = params.x_max_3_30;
elseif isfield(params, 'x_max_3')
  x_max_3_30 = params.x_max_3{30};
else
  error 'could not find x_max_3_30'
end
if isfield(params, 'x_max_3_31')
  x_max_3_31 = params.x_max_3_31;
elseif isfield(params, 'x_max_3')
  x_max_3_31 = params.x_max_3{31};
else
  error 'could not find x_max_3_31'
end
if isfield(params, 'x_max_3_32')
  x_max_3_32 = params.x_max_3_32;
elseif isfield(params, 'x_max_3')
  x_max_3_32 = params.x_max_3{32};
else
  error 'could not find x_max_3_32'
end
if isfield(params, 'x_max_3_33')
  x_max_3_33 = params.x_max_3_33;
elseif isfield(params, 'x_max_3')
  x_max_3_33 = params.x_max_3{33};
else
  error 'could not find x_max_3_33'
end
if isfield(params, 'x_max_3_34')
  x_max_3_34 = params.x_max_3_34;
elseif isfield(params, 'x_max_3')
  x_max_3_34 = params.x_max_3{34};
else
  error 'could not find x_max_3_34'
end
if isfield(params, 'x_max_3_35')
  x_max_3_35 = params.x_max_3_35;
elseif isfield(params, 'x_max_3')
  x_max_3_35 = params.x_max_3{35};
else
  error 'could not find x_max_3_35'
end
if isfield(params, 'x_max_3_36')
  x_max_3_36 = params.x_max_3_36;
elseif isfield(params, 'x_max_3')
  x_max_3_36 = params.x_max_3{36};
else
  error 'could not find x_max_3_36'
end
if isfield(params, 'x_max_3_37')
  x_max_3_37 = params.x_max_3_37;
elseif isfield(params, 'x_max_3')
  x_max_3_37 = params.x_max_3{37};
else
  error 'could not find x_max_3_37'
end
if isfield(params, 'x_max_3_38')
  x_max_3_38 = params.x_max_3_38;
elseif isfield(params, 'x_max_3')
  x_max_3_38 = params.x_max_3{38};
else
  error 'could not find x_max_3_38'
end
if isfield(params, 'x_max_3_39')
  x_max_3_39 = params.x_max_3_39;
elseif isfield(params, 'x_max_3')
  x_max_3_39 = params.x_max_3{39};
else
  error 'could not find x_max_3_39'
end
if isfield(params, 'x_max_3_40')
  x_max_3_40 = params.x_max_3_40;
elseif isfield(params, 'x_max_3')
  x_max_3_40 = params.x_max_3{40};
else
  error 'could not find x_max_3_40'
end
if isfield(params, 'x_min_2_1')
  x_min_2_1 = params.x_min_2_1;
elseif isfield(params, 'x_min_2')
  x_min_2_1 = params.x_min_2{1};
else
  error 'could not find x_min_2_1'
end
if isfield(params, 'x_min_2_2')
  x_min_2_2 = params.x_min_2_2;
elseif isfield(params, 'x_min_2')
  x_min_2_2 = params.x_min_2{2};
else
  error 'could not find x_min_2_2'
end
if isfield(params, 'x_min_2_3')
  x_min_2_3 = params.x_min_2_3;
elseif isfield(params, 'x_min_2')
  x_min_2_3 = params.x_min_2{3};
else
  error 'could not find x_min_2_3'
end
if isfield(params, 'x_min_2_4')
  x_min_2_4 = params.x_min_2_4;
elseif isfield(params, 'x_min_2')
  x_min_2_4 = params.x_min_2{4};
else
  error 'could not find x_min_2_4'
end
if isfield(params, 'x_min_2_5')
  x_min_2_5 = params.x_min_2_5;
elseif isfield(params, 'x_min_2')
  x_min_2_5 = params.x_min_2{5};
else
  error 'could not find x_min_2_5'
end
if isfield(params, 'x_min_2_6')
  x_min_2_6 = params.x_min_2_6;
elseif isfield(params, 'x_min_2')
  x_min_2_6 = params.x_min_2{6};
else
  error 'could not find x_min_2_6'
end
if isfield(params, 'x_min_2_7')
  x_min_2_7 = params.x_min_2_7;
elseif isfield(params, 'x_min_2')
  x_min_2_7 = params.x_min_2{7};
else
  error 'could not find x_min_2_7'
end
if isfield(params, 'x_min_2_8')
  x_min_2_8 = params.x_min_2_8;
elseif isfield(params, 'x_min_2')
  x_min_2_8 = params.x_min_2{8};
else
  error 'could not find x_min_2_8'
end
if isfield(params, 'x_min_2_9')
  x_min_2_9 = params.x_min_2_9;
elseif isfield(params, 'x_min_2')
  x_min_2_9 = params.x_min_2{9};
else
  error 'could not find x_min_2_9'
end
if isfield(params, 'x_min_2_10')
  x_min_2_10 = params.x_min_2_10;
elseif isfield(params, 'x_min_2')
  x_min_2_10 = params.x_min_2{10};
else
  error 'could not find x_min_2_10'
end
if isfield(params, 'x_min_2_11')
  x_min_2_11 = params.x_min_2_11;
elseif isfield(params, 'x_min_2')
  x_min_2_11 = params.x_min_2{11};
else
  error 'could not find x_min_2_11'
end
if isfield(params, 'x_min_2_12')
  x_min_2_12 = params.x_min_2_12;
elseif isfield(params, 'x_min_2')
  x_min_2_12 = params.x_min_2{12};
else
  error 'could not find x_min_2_12'
end
if isfield(params, 'x_min_2_13')
  x_min_2_13 = params.x_min_2_13;
elseif isfield(params, 'x_min_2')
  x_min_2_13 = params.x_min_2{13};
else
  error 'could not find x_min_2_13'
end
if isfield(params, 'x_min_2_14')
  x_min_2_14 = params.x_min_2_14;
elseif isfield(params, 'x_min_2')
  x_min_2_14 = params.x_min_2{14};
else
  error 'could not find x_min_2_14'
end
if isfield(params, 'x_min_2_15')
  x_min_2_15 = params.x_min_2_15;
elseif isfield(params, 'x_min_2')
  x_min_2_15 = params.x_min_2{15};
else
  error 'could not find x_min_2_15'
end
if isfield(params, 'x_min_2_16')
  x_min_2_16 = params.x_min_2_16;
elseif isfield(params, 'x_min_2')
  x_min_2_16 = params.x_min_2{16};
else
  error 'could not find x_min_2_16'
end
if isfield(params, 'x_min_2_17')
  x_min_2_17 = params.x_min_2_17;
elseif isfield(params, 'x_min_2')
  x_min_2_17 = params.x_min_2{17};
else
  error 'could not find x_min_2_17'
end
if isfield(params, 'x_min_2_18')
  x_min_2_18 = params.x_min_2_18;
elseif isfield(params, 'x_min_2')
  x_min_2_18 = params.x_min_2{18};
else
  error 'could not find x_min_2_18'
end
if isfield(params, 'x_min_2_19')
  x_min_2_19 = params.x_min_2_19;
elseif isfield(params, 'x_min_2')
  x_min_2_19 = params.x_min_2{19};
else
  error 'could not find x_min_2_19'
end
if isfield(params, 'x_min_2_20')
  x_min_2_20 = params.x_min_2_20;
elseif isfield(params, 'x_min_2')
  x_min_2_20 = params.x_min_2{20};
else
  error 'could not find x_min_2_20'
end
if isfield(params, 'x_min_2_21')
  x_min_2_21 = params.x_min_2_21;
elseif isfield(params, 'x_min_2')
  x_min_2_21 = params.x_min_2{21};
else
  error 'could not find x_min_2_21'
end
if isfield(params, 'x_min_2_22')
  x_min_2_22 = params.x_min_2_22;
elseif isfield(params, 'x_min_2')
  x_min_2_22 = params.x_min_2{22};
else
  error 'could not find x_min_2_22'
end
if isfield(params, 'x_min_2_23')
  x_min_2_23 = params.x_min_2_23;
elseif isfield(params, 'x_min_2')
  x_min_2_23 = params.x_min_2{23};
else
  error 'could not find x_min_2_23'
end
if isfield(params, 'x_min_2_24')
  x_min_2_24 = params.x_min_2_24;
elseif isfield(params, 'x_min_2')
  x_min_2_24 = params.x_min_2{24};
else
  error 'could not find x_min_2_24'
end
if isfield(params, 'x_min_2_25')
  x_min_2_25 = params.x_min_2_25;
elseif isfield(params, 'x_min_2')
  x_min_2_25 = params.x_min_2{25};
else
  error 'could not find x_min_2_25'
end
if isfield(params, 'x_min_2_26')
  x_min_2_26 = params.x_min_2_26;
elseif isfield(params, 'x_min_2')
  x_min_2_26 = params.x_min_2{26};
else
  error 'could not find x_min_2_26'
end
if isfield(params, 'x_min_2_27')
  x_min_2_27 = params.x_min_2_27;
elseif isfield(params, 'x_min_2')
  x_min_2_27 = params.x_min_2{27};
else
  error 'could not find x_min_2_27'
end
if isfield(params, 'x_min_2_28')
  x_min_2_28 = params.x_min_2_28;
elseif isfield(params, 'x_min_2')
  x_min_2_28 = params.x_min_2{28};
else
  error 'could not find x_min_2_28'
end
if isfield(params, 'x_min_2_29')
  x_min_2_29 = params.x_min_2_29;
elseif isfield(params, 'x_min_2')
  x_min_2_29 = params.x_min_2{29};
else
  error 'could not find x_min_2_29'
end
if isfield(params, 'x_min_2_30')
  x_min_2_30 = params.x_min_2_30;
elseif isfield(params, 'x_min_2')
  x_min_2_30 = params.x_min_2{30};
else
  error 'could not find x_min_2_30'
end
if isfield(params, 'x_min_2_31')
  x_min_2_31 = params.x_min_2_31;
elseif isfield(params, 'x_min_2')
  x_min_2_31 = params.x_min_2{31};
else
  error 'could not find x_min_2_31'
end
if isfield(params, 'x_min_2_32')
  x_min_2_32 = params.x_min_2_32;
elseif isfield(params, 'x_min_2')
  x_min_2_32 = params.x_min_2{32};
else
  error 'could not find x_min_2_32'
end
if isfield(params, 'x_min_2_33')
  x_min_2_33 = params.x_min_2_33;
elseif isfield(params, 'x_min_2')
  x_min_2_33 = params.x_min_2{33};
else
  error 'could not find x_min_2_33'
end
if isfield(params, 'x_min_2_34')
  x_min_2_34 = params.x_min_2_34;
elseif isfield(params, 'x_min_2')
  x_min_2_34 = params.x_min_2{34};
else
  error 'could not find x_min_2_34'
end
if isfield(params, 'x_min_2_35')
  x_min_2_35 = params.x_min_2_35;
elseif isfield(params, 'x_min_2')
  x_min_2_35 = params.x_min_2{35};
else
  error 'could not find x_min_2_35'
end
if isfield(params, 'x_min_2_36')
  x_min_2_36 = params.x_min_2_36;
elseif isfield(params, 'x_min_2')
  x_min_2_36 = params.x_min_2{36};
else
  error 'could not find x_min_2_36'
end
if isfield(params, 'x_min_2_37')
  x_min_2_37 = params.x_min_2_37;
elseif isfield(params, 'x_min_2')
  x_min_2_37 = params.x_min_2{37};
else
  error 'could not find x_min_2_37'
end
if isfield(params, 'x_min_2_38')
  x_min_2_38 = params.x_min_2_38;
elseif isfield(params, 'x_min_2')
  x_min_2_38 = params.x_min_2{38};
else
  error 'could not find x_min_2_38'
end
if isfield(params, 'x_min_2_39')
  x_min_2_39 = params.x_min_2_39;
elseif isfield(params, 'x_min_2')
  x_min_2_39 = params.x_min_2{39};
else
  error 'could not find x_min_2_39'
end
if isfield(params, 'x_min_2_40')
  x_min_2_40 = params.x_min_2_40;
elseif isfield(params, 'x_min_2')
  x_min_2_40 = params.x_min_2{40};
else
  error 'could not find x_min_2_40'
end
if isfield(params, 'x_min_3_1')
  x_min_3_1 = params.x_min_3_1;
elseif isfield(params, 'x_min_3')
  x_min_3_1 = params.x_min_3{1};
else
  error 'could not find x_min_3_1'
end
if isfield(params, 'x_min_3_2')
  x_min_3_2 = params.x_min_3_2;
elseif isfield(params, 'x_min_3')
  x_min_3_2 = params.x_min_3{2};
else
  error 'could not find x_min_3_2'
end
if isfield(params, 'x_min_3_3')
  x_min_3_3 = params.x_min_3_3;
elseif isfield(params, 'x_min_3')
  x_min_3_3 = params.x_min_3{3};
else
  error 'could not find x_min_3_3'
end
if isfield(params, 'x_min_3_4')
  x_min_3_4 = params.x_min_3_4;
elseif isfield(params, 'x_min_3')
  x_min_3_4 = params.x_min_3{4};
else
  error 'could not find x_min_3_4'
end
if isfield(params, 'x_min_3_5')
  x_min_3_5 = params.x_min_3_5;
elseif isfield(params, 'x_min_3')
  x_min_3_5 = params.x_min_3{5};
else
  error 'could not find x_min_3_5'
end
if isfield(params, 'x_min_3_6')
  x_min_3_6 = params.x_min_3_6;
elseif isfield(params, 'x_min_3')
  x_min_3_6 = params.x_min_3{6};
else
  error 'could not find x_min_3_6'
end
if isfield(params, 'x_min_3_7')
  x_min_3_7 = params.x_min_3_7;
elseif isfield(params, 'x_min_3')
  x_min_3_7 = params.x_min_3{7};
else
  error 'could not find x_min_3_7'
end
if isfield(params, 'x_min_3_8')
  x_min_3_8 = params.x_min_3_8;
elseif isfield(params, 'x_min_3')
  x_min_3_8 = params.x_min_3{8};
else
  error 'could not find x_min_3_8'
end
if isfield(params, 'x_min_3_9')
  x_min_3_9 = params.x_min_3_9;
elseif isfield(params, 'x_min_3')
  x_min_3_9 = params.x_min_3{9};
else
  error 'could not find x_min_3_9'
end
if isfield(params, 'x_min_3_10')
  x_min_3_10 = params.x_min_3_10;
elseif isfield(params, 'x_min_3')
  x_min_3_10 = params.x_min_3{10};
else
  error 'could not find x_min_3_10'
end
if isfield(params, 'x_min_3_11')
  x_min_3_11 = params.x_min_3_11;
elseif isfield(params, 'x_min_3')
  x_min_3_11 = params.x_min_3{11};
else
  error 'could not find x_min_3_11'
end
if isfield(params, 'x_min_3_12')
  x_min_3_12 = params.x_min_3_12;
elseif isfield(params, 'x_min_3')
  x_min_3_12 = params.x_min_3{12};
else
  error 'could not find x_min_3_12'
end
if isfield(params, 'x_min_3_13')
  x_min_3_13 = params.x_min_3_13;
elseif isfield(params, 'x_min_3')
  x_min_3_13 = params.x_min_3{13};
else
  error 'could not find x_min_3_13'
end
if isfield(params, 'x_min_3_14')
  x_min_3_14 = params.x_min_3_14;
elseif isfield(params, 'x_min_3')
  x_min_3_14 = params.x_min_3{14};
else
  error 'could not find x_min_3_14'
end
if isfield(params, 'x_min_3_15')
  x_min_3_15 = params.x_min_3_15;
elseif isfield(params, 'x_min_3')
  x_min_3_15 = params.x_min_3{15};
else
  error 'could not find x_min_3_15'
end
if isfield(params, 'x_min_3_16')
  x_min_3_16 = params.x_min_3_16;
elseif isfield(params, 'x_min_3')
  x_min_3_16 = params.x_min_3{16};
else
  error 'could not find x_min_3_16'
end
if isfield(params, 'x_min_3_17')
  x_min_3_17 = params.x_min_3_17;
elseif isfield(params, 'x_min_3')
  x_min_3_17 = params.x_min_3{17};
else
  error 'could not find x_min_3_17'
end
if isfield(params, 'x_min_3_18')
  x_min_3_18 = params.x_min_3_18;
elseif isfield(params, 'x_min_3')
  x_min_3_18 = params.x_min_3{18};
else
  error 'could not find x_min_3_18'
end
if isfield(params, 'x_min_3_19')
  x_min_3_19 = params.x_min_3_19;
elseif isfield(params, 'x_min_3')
  x_min_3_19 = params.x_min_3{19};
else
  error 'could not find x_min_3_19'
end
if isfield(params, 'x_min_3_20')
  x_min_3_20 = params.x_min_3_20;
elseif isfield(params, 'x_min_3')
  x_min_3_20 = params.x_min_3{20};
else
  error 'could not find x_min_3_20'
end
if isfield(params, 'x_min_3_21')
  x_min_3_21 = params.x_min_3_21;
elseif isfield(params, 'x_min_3')
  x_min_3_21 = params.x_min_3{21};
else
  error 'could not find x_min_3_21'
end
if isfield(params, 'x_min_3_22')
  x_min_3_22 = params.x_min_3_22;
elseif isfield(params, 'x_min_3')
  x_min_3_22 = params.x_min_3{22};
else
  error 'could not find x_min_3_22'
end
if isfield(params, 'x_min_3_23')
  x_min_3_23 = params.x_min_3_23;
elseif isfield(params, 'x_min_3')
  x_min_3_23 = params.x_min_3{23};
else
  error 'could not find x_min_3_23'
end
if isfield(params, 'x_min_3_24')
  x_min_3_24 = params.x_min_3_24;
elseif isfield(params, 'x_min_3')
  x_min_3_24 = params.x_min_3{24};
else
  error 'could not find x_min_3_24'
end
if isfield(params, 'x_min_3_25')
  x_min_3_25 = params.x_min_3_25;
elseif isfield(params, 'x_min_3')
  x_min_3_25 = params.x_min_3{25};
else
  error 'could not find x_min_3_25'
end
if isfield(params, 'x_min_3_26')
  x_min_3_26 = params.x_min_3_26;
elseif isfield(params, 'x_min_3')
  x_min_3_26 = params.x_min_3{26};
else
  error 'could not find x_min_3_26'
end
if isfield(params, 'x_min_3_27')
  x_min_3_27 = params.x_min_3_27;
elseif isfield(params, 'x_min_3')
  x_min_3_27 = params.x_min_3{27};
else
  error 'could not find x_min_3_27'
end
if isfield(params, 'x_min_3_28')
  x_min_3_28 = params.x_min_3_28;
elseif isfield(params, 'x_min_3')
  x_min_3_28 = params.x_min_3{28};
else
  error 'could not find x_min_3_28'
end
if isfield(params, 'x_min_3_29')
  x_min_3_29 = params.x_min_3_29;
elseif isfield(params, 'x_min_3')
  x_min_3_29 = params.x_min_3{29};
else
  error 'could not find x_min_3_29'
end
if isfield(params, 'x_min_3_30')
  x_min_3_30 = params.x_min_3_30;
elseif isfield(params, 'x_min_3')
  x_min_3_30 = params.x_min_3{30};
else
  error 'could not find x_min_3_30'
end
if isfield(params, 'x_min_3_31')
  x_min_3_31 = params.x_min_3_31;
elseif isfield(params, 'x_min_3')
  x_min_3_31 = params.x_min_3{31};
else
  error 'could not find x_min_3_31'
end
if isfield(params, 'x_min_3_32')
  x_min_3_32 = params.x_min_3_32;
elseif isfield(params, 'x_min_3')
  x_min_3_32 = params.x_min_3{32};
else
  error 'could not find x_min_3_32'
end
if isfield(params, 'x_min_3_33')
  x_min_3_33 = params.x_min_3_33;
elseif isfield(params, 'x_min_3')
  x_min_3_33 = params.x_min_3{33};
else
  error 'could not find x_min_3_33'
end
if isfield(params, 'x_min_3_34')
  x_min_3_34 = params.x_min_3_34;
elseif isfield(params, 'x_min_3')
  x_min_3_34 = params.x_min_3{34};
else
  error 'could not find x_min_3_34'
end
if isfield(params, 'x_min_3_35')
  x_min_3_35 = params.x_min_3_35;
elseif isfield(params, 'x_min_3')
  x_min_3_35 = params.x_min_3{35};
else
  error 'could not find x_min_3_35'
end
if isfield(params, 'x_min_3_36')
  x_min_3_36 = params.x_min_3_36;
elseif isfield(params, 'x_min_3')
  x_min_3_36 = params.x_min_3{36};
else
  error 'could not find x_min_3_36'
end
if isfield(params, 'x_min_3_37')
  x_min_3_37 = params.x_min_3_37;
elseif isfield(params, 'x_min_3')
  x_min_3_37 = params.x_min_3{37};
else
  error 'could not find x_min_3_37'
end
if isfield(params, 'x_min_3_38')
  x_min_3_38 = params.x_min_3_38;
elseif isfield(params, 'x_min_3')
  x_min_3_38 = params.x_min_3{38};
else
  error 'could not find x_min_3_38'
end
if isfield(params, 'x_min_3_39')
  x_min_3_39 = params.x_min_3_39;
elseif isfield(params, 'x_min_3')
  x_min_3_39 = params.x_min_3{39};
else
  error 'could not find x_min_3_39'
end
if isfield(params, 'x_min_3_40')
  x_min_3_40 = params.x_min_3_40;
elseif isfield(params, 'x_min_3')
  x_min_3_40 = params.x_min_3{40};
else
  error 'could not find x_min_3_40'
end
if isfield(params, 'x_ss_1')
  x_ss_1 = params.x_ss_1;
elseif isfield(params, 'x_ss')
  x_ss_1 = params.x_ss{1};
else
  error 'could not find x_ss_1'
end
if isfield(params, 'x_ss_2')
  x_ss_2 = params.x_ss_2;
elseif isfield(params, 'x_ss')
  x_ss_2 = params.x_ss{2};
else
  error 'could not find x_ss_2'
end
if isfield(params, 'x_ss_3')
  x_ss_3 = params.x_ss_3;
elseif isfield(params, 'x_ss')
  x_ss_3 = params.x_ss{3};
else
  error 'could not find x_ss_3'
end
if isfield(params, 'x_ss_4')
  x_ss_4 = params.x_ss_4;
elseif isfield(params, 'x_ss')
  x_ss_4 = params.x_ss{4};
else
  error 'could not find x_ss_4'
end
if isfield(params, 'x_ss_5')
  x_ss_5 = params.x_ss_5;
elseif isfield(params, 'x_ss')
  x_ss_5 = params.x_ss{5};
else
  error 'could not find x_ss_5'
end
if isfield(params, 'x_ss_6')
  x_ss_6 = params.x_ss_6;
elseif isfield(params, 'x_ss')
  x_ss_6 = params.x_ss{6};
else
  error 'could not find x_ss_6'
end
if isfield(params, 'x_ss_7')
  x_ss_7 = params.x_ss_7;
elseif isfield(params, 'x_ss')
  x_ss_7 = params.x_ss{7};
else
  error 'could not find x_ss_7'
end
if isfield(params, 'x_ss_8')
  x_ss_8 = params.x_ss_8;
elseif isfield(params, 'x_ss')
  x_ss_8 = params.x_ss{8};
else
  error 'could not find x_ss_8'
end
if isfield(params, 'x_ss_9')
  x_ss_9 = params.x_ss_9;
elseif isfield(params, 'x_ss')
  x_ss_9 = params.x_ss{9};
else
  error 'could not find x_ss_9'
end
if isfield(params, 'x_ss_10')
  x_ss_10 = params.x_ss_10;
elseif isfield(params, 'x_ss')
  x_ss_10 = params.x_ss{10};
else
  error 'could not find x_ss_10'
end
if isfield(params, 'x_ss_11')
  x_ss_11 = params.x_ss_11;
elseif isfield(params, 'x_ss')
  x_ss_11 = params.x_ss{11};
else
  error 'could not find x_ss_11'
end
if isfield(params, 'x_ss_12')
  x_ss_12 = params.x_ss_12;
elseif isfield(params, 'x_ss')
  x_ss_12 = params.x_ss{12};
else
  error 'could not find x_ss_12'
end
if isfield(params, 'x_ss_13')
  x_ss_13 = params.x_ss_13;
elseif isfield(params, 'x_ss')
  x_ss_13 = params.x_ss{13};
else
  error 'could not find x_ss_13'
end
if isfield(params, 'x_ss_14')
  x_ss_14 = params.x_ss_14;
elseif isfield(params, 'x_ss')
  x_ss_14 = params.x_ss{14};
else
  error 'could not find x_ss_14'
end
if isfield(params, 'x_ss_15')
  x_ss_15 = params.x_ss_15;
elseif isfield(params, 'x_ss')
  x_ss_15 = params.x_ss{15};
else
  error 'could not find x_ss_15'
end
if isfield(params, 'x_ss_16')
  x_ss_16 = params.x_ss_16;
elseif isfield(params, 'x_ss')
  x_ss_16 = params.x_ss{16};
else
  error 'could not find x_ss_16'
end
if isfield(params, 'x_ss_17')
  x_ss_17 = params.x_ss_17;
elseif isfield(params, 'x_ss')
  x_ss_17 = params.x_ss{17};
else
  error 'could not find x_ss_17'
end
if isfield(params, 'x_ss_18')
  x_ss_18 = params.x_ss_18;
elseif isfield(params, 'x_ss')
  x_ss_18 = params.x_ss{18};
else
  error 'could not find x_ss_18'
end
if isfield(params, 'x_ss_19')
  x_ss_19 = params.x_ss_19;
elseif isfield(params, 'x_ss')
  x_ss_19 = params.x_ss{19};
else
  error 'could not find x_ss_19'
end
if isfield(params, 'x_ss_20')
  x_ss_20 = params.x_ss_20;
elseif isfield(params, 'x_ss')
  x_ss_20 = params.x_ss{20};
else
  error 'could not find x_ss_20'
end
if isfield(params, 'x_ss_21')
  x_ss_21 = params.x_ss_21;
elseif isfield(params, 'x_ss')
  x_ss_21 = params.x_ss{21};
else
  error 'could not find x_ss_21'
end
if isfield(params, 'x_ss_22')
  x_ss_22 = params.x_ss_22;
elseif isfield(params, 'x_ss')
  x_ss_22 = params.x_ss{22};
else
  error 'could not find x_ss_22'
end
if isfield(params, 'x_ss_23')
  x_ss_23 = params.x_ss_23;
elseif isfield(params, 'x_ss')
  x_ss_23 = params.x_ss{23};
else
  error 'could not find x_ss_23'
end
if isfield(params, 'x_ss_24')
  x_ss_24 = params.x_ss_24;
elseif isfield(params, 'x_ss')
  x_ss_24 = params.x_ss{24};
else
  error 'could not find x_ss_24'
end
if isfield(params, 'x_ss_25')
  x_ss_25 = params.x_ss_25;
elseif isfield(params, 'x_ss')
  x_ss_25 = params.x_ss{25};
else
  error 'could not find x_ss_25'
end
if isfield(params, 'x_ss_26')
  x_ss_26 = params.x_ss_26;
elseif isfield(params, 'x_ss')
  x_ss_26 = params.x_ss{26};
else
  error 'could not find x_ss_26'
end
if isfield(params, 'x_ss_27')
  x_ss_27 = params.x_ss_27;
elseif isfield(params, 'x_ss')
  x_ss_27 = params.x_ss{27};
else
  error 'could not find x_ss_27'
end
if isfield(params, 'x_ss_28')
  x_ss_28 = params.x_ss_28;
elseif isfield(params, 'x_ss')
  x_ss_28 = params.x_ss{28};
else
  error 'could not find x_ss_28'
end
if isfield(params, 'x_ss_29')
  x_ss_29 = params.x_ss_29;
elseif isfield(params, 'x_ss')
  x_ss_29 = params.x_ss{29};
else
  error 'could not find x_ss_29'
end
if isfield(params, 'x_ss_30')
  x_ss_30 = params.x_ss_30;
elseif isfield(params, 'x_ss')
  x_ss_30 = params.x_ss{30};
else
  error 'could not find x_ss_30'
end
if isfield(params, 'x_ss_31')
  x_ss_31 = params.x_ss_31;
elseif isfield(params, 'x_ss')
  x_ss_31 = params.x_ss{31};
else
  error 'could not find x_ss_31'
end
if isfield(params, 'x_ss_32')
  x_ss_32 = params.x_ss_32;
elseif isfield(params, 'x_ss')
  x_ss_32 = params.x_ss{32};
else
  error 'could not find x_ss_32'
end
if isfield(params, 'x_ss_33')
  x_ss_33 = params.x_ss_33;
elseif isfield(params, 'x_ss')
  x_ss_33 = params.x_ss{33};
else
  error 'could not find x_ss_33'
end
if isfield(params, 'x_ss_34')
  x_ss_34 = params.x_ss_34;
elseif isfield(params, 'x_ss')
  x_ss_34 = params.x_ss{34};
else
  error 'could not find x_ss_34'
end
if isfield(params, 'x_ss_35')
  x_ss_35 = params.x_ss_35;
elseif isfield(params, 'x_ss')
  x_ss_35 = params.x_ss{35};
else
  error 'could not find x_ss_35'
end
if isfield(params, 'x_ss_36')
  x_ss_36 = params.x_ss_36;
elseif isfield(params, 'x_ss')
  x_ss_36 = params.x_ss{36};
else
  error 'could not find x_ss_36'
end
if isfield(params, 'x_ss_37')
  x_ss_37 = params.x_ss_37;
elseif isfield(params, 'x_ss')
  x_ss_37 = params.x_ss{37};
else
  error 'could not find x_ss_37'
end
if isfield(params, 'x_ss_38')
  x_ss_38 = params.x_ss_38;
elseif isfield(params, 'x_ss')
  x_ss_38 = params.x_ss{38};
else
  error 'could not find x_ss_38'
end
if isfield(params, 'x_ss_39')
  x_ss_39 = params.x_ss_39;
elseif isfield(params, 'x_ss')
  x_ss_39 = params.x_ss{39};
else
  error 'could not find x_ss_39'
end
if isfield(params, 'x_ss_40')
  x_ss_40 = params.x_ss_40;
elseif isfield(params, 'x_ss')
  x_ss_40 = params.x_ss{40};
else
  error 'could not find x_ss_40'
end
cvx_begin
  % Caution: automatically generated by cvxgen. May be incorrect.
  variable x_1(3, 1);
  variable x_2(3, 1);
  variable x_3(3, 1);
  variable x_4(3, 1);
  variable x_5(3, 1);
  variable x_6(3, 1);
  variable x_7(3, 1);
  variable x_8(3, 1);
  variable x_9(3, 1);
  variable x_10(3, 1);
  variable x_11(3, 1);
  variable x_12(3, 1);
  variable x_13(3, 1);
  variable x_14(3, 1);
  variable x_15(3, 1);
  variable x_16(3, 1);
  variable x_17(3, 1);
  variable x_18(3, 1);
  variable x_19(3, 1);
  variable x_20(3, 1);
  variable x_21(3, 1);
  variable x_22(3, 1);
  variable x_23(3, 1);
  variable x_24(3, 1);
  variable x_25(3, 1);
  variable x_26(3, 1);
  variable x_27(3, 1);
  variable x_28(3, 1);
  variable x_29(3, 1);
  variable x_30(3, 1);
  variable x_31(3, 1);
  variable x_32(3, 1);
  variable x_33(3, 1);
  variable x_34(3, 1);
  variable x_35(3, 1);
  variable x_36(3, 1);
  variable x_37(3, 1);
  variable x_38(3, 1);
  variable x_39(3, 1);
  variable x_40(3, 1);
  variable u_1;
  variable u_2;
  variable u_3;
  variable u_4;
  variable u_5;
  variable u_6;
  variable u_7;
  variable u_8;
  variable u_9;
  variable u_10;
  variable u_11;
  variable u_12;
  variable u_13;
  variable u_14;
  variable u_15;
  variable u_16;
  variable u_17;
  variable u_18;
  variable u_19;
  variable u_20;
  variable u_21;
  variable u_22;
  variable u_23;
  variable u_24;
  variable u_25;
  variable u_26;
  variable u_27;
  variable u_28;
  variable u_29;
  variable u_30;
  variable u_31;
  variable u_32;
  variable u_33;
  variable u_34;
  variable u_35;
  variable u_36;
  variable u_37;
  variable u_38;
  variable u_39;
  variable u_0;

  minimize(quad_form(x_1 - x_ss_1, Q) + quad_form(x_2 - x_ss_2, Q) + quad_form(x_3 - x_ss_3, Q) + quad_form(x_4 - x_ss_4, Q) + quad_form(x_5 - x_ss_5, Q) + quad_form(x_6 - x_ss_6, Q) + quad_form(x_7 - x_ss_7, Q) + quad_form(x_8 - x_ss_8, Q) + quad_form(x_9 - x_ss_9, Q) + quad_form(x_10 - x_ss_10, Q) + quad_form(x_11 - x_ss_11, Q) + quad_form(x_12 - x_ss_12, Q) + quad_form(x_13 - x_ss_13, Q) + quad_form(x_14 - x_ss_14, Q) + quad_form(x_15 - x_ss_15, Q) + quad_form(x_16 - x_ss_16, Q) + quad_form(x_17 - x_ss_17, Q) + quad_form(x_18 - x_ss_18, Q) + quad_form(x_19 - x_ss_19, Q) + quad_form(x_20 - x_ss_20, Q) + quad_form(x_21 - x_ss_21, Q) + quad_form(x_22 - x_ss_22, Q) + quad_form(x_23 - x_ss_23, Q) + quad_form(x_24 - x_ss_24, Q) + quad_form(x_25 - x_ss_25, Q) + quad_form(x_26 - x_ss_26, Q) + quad_form(x_27 - x_ss_27, Q) + quad_form(x_28 - x_ss_28, Q) + quad_form(x_29 - x_ss_29, Q) + quad_form(x_30 - x_ss_30, Q) + quad_form(x_31 - x_ss_31, Q) + quad_form(x_32 - x_ss_32, Q) + quad_form(x_33 - x_ss_33, Q) + quad_form(x_34 - x_ss_34, Q) + quad_form(x_35 - x_ss_35, Q) + quad_form(x_36 - x_ss_36, Q) + quad_form(x_37 - x_ss_37, Q) + quad_form(x_38 - x_ss_38, Q) + quad_form(x_39 - x_ss_39, Q) + quad_form(x_40 - x_ss_40, Q) + quad_form(u_1, R) + quad_form(u_2, R) + quad_form(u_3, R) + quad_form(u_4, R) + quad_form(u_5, R) + quad_form(u_6, R) + quad_form(u_7, R) + quad_form(u_8, R) + quad_form(u_9, R) + quad_form(u_10, R) + quad_form(u_11, R) + quad_form(u_12, R) + quad_form(u_13, R) + quad_form(u_14, R) + quad_form(u_15, R) + quad_form(u_16, R) + quad_form(u_17, R) + quad_form(u_18, R) + quad_form(u_19, R) + quad_form(u_20, R) + quad_form(u_21, R) + quad_form(u_22, R) + quad_form(u_23, R) + quad_form(u_24, R) + quad_form(u_25, R) + quad_form(u_26, R) + quad_form(u_27, R) + quad_form(u_28, R) + quad_form(u_29, R) + quad_form(u_30, R) + quad_form(u_31, R) + quad_form(u_32, R) + quad_form(u_33, R) + quad_form(u_34, R) + quad_form(u_35, R) + quad_form(u_36, R) + quad_form(u_37, R) + quad_form(u_38, R) + quad_form(u_39, R) + quad_form(u_0, R2));
  subject to
    x_1 == Af*x_0 + Bf*u_0;
    x_2 == A*x_1 + B*u_1;
    x_3 == A*x_2 + B*u_2;
    x_4 == A*x_3 + B*u_3;
    x_5 == A*x_4 + B*u_4;
    x_6 == A*x_5 + B*u_5;
    x_7 == A*x_6 + B*u_6;
    x_8 == A*x_7 + B*u_7;
    x_9 == A*x_8 + B*u_8;
    x_10 == A*x_9 + B*u_9;
    x_11 == A*x_10 + B*u_10;
    x_12 == A*x_11 + B*u_11;
    x_13 == A*x_12 + B*u_12;
    x_14 == A*x_13 + B*u_13;
    x_15 == A*x_14 + B*u_14;
    x_16 == A*x_15 + B*u_15;
    x_17 == A*x_16 + B*u_16;
    x_18 == A*x_17 + B*u_17;
    x_19 == A*x_18 + B*u_18;
    x_20 == A*x_19 + B*u_19;
    x_21 == A*x_20 + B*u_20;
    x_22 == A*x_21 + B*u_21;
    x_23 == A*x_22 + B*u_22;
    x_24 == A*x_23 + B*u_23;
    x_25 == A*x_24 + B*u_24;
    x_26 == A*x_25 + B*u_25;
    x_27 == A*x_26 + B*u_26;
    x_28 == A*x_27 + B*u_27;
    x_29 == A*x_28 + B*u_28;
    x_30 == A*x_29 + B*u_29;
    x_31 == A*x_30 + B*u_30;
    x_32 == A*x_31 + B*u_31;
    x_33 == A*x_32 + B*u_32;
    x_34 == A*x_33 + B*u_33;
    x_35 == A*x_34 + B*u_34;
    x_36 == A*x_35 + B*u_35;
    x_37 == A*x_36 + B*u_36;
    x_38 == A*x_37 + B*u_37;
    x_39 == A*x_38 + B*u_38;
    x_40 == A*x_39 + B*u_39;
    x_1(2) <= x_max_2_1;
    x_2(2) <= x_max_2_2;
    x_3(2) <= x_max_2_3;
    x_4(2) <= x_max_2_4;
    x_5(2) <= x_max_2_5;
    x_6(2) <= x_max_2_6;
    x_7(2) <= x_max_2_7;
    x_8(2) <= x_max_2_8;
    x_9(2) <= x_max_2_9;
    x_10(2) <= x_max_2_10;
    x_11(2) <= x_max_2_11;
    x_12(2) <= x_max_2_12;
    x_13(2) <= x_max_2_13;
    x_14(2) <= x_max_2_14;
    x_15(2) <= x_max_2_15;
    x_16(2) <= x_max_2_16;
    x_17(2) <= x_max_2_17;
    x_18(2) <= x_max_2_18;
    x_19(2) <= x_max_2_19;
    x_20(2) <= x_max_2_20;
    x_21(2) <= x_max_2_21;
    x_22(2) <= x_max_2_22;
    x_23(2) <= x_max_2_23;
    x_24(2) <= x_max_2_24;
    x_25(2) <= x_max_2_25;
    x_26(2) <= x_max_2_26;
    x_27(2) <= x_max_2_27;
    x_28(2) <= x_max_2_28;
    x_29(2) <= x_max_2_29;
    x_30(2) <= x_max_2_30;
    x_31(2) <= x_max_2_31;
    x_32(2) <= x_max_2_32;
    x_33(2) <= x_max_2_33;
    x_34(2) <= x_max_2_34;
    x_35(2) <= x_max_2_35;
    x_36(2) <= x_max_2_36;
    x_37(2) <= x_max_2_37;
    x_38(2) <= x_max_2_38;
    x_39(2) <= x_max_2_39;
    x_40(2) <= x_max_2_40;
    x_1(2) >= -x_min_2_1;
    x_2(2) >= -x_min_2_2;
    x_3(2) >= -x_min_2_3;
    x_4(2) >= -x_min_2_4;
    x_5(2) >= -x_min_2_5;
    x_6(2) >= -x_min_2_6;
    x_7(2) >= -x_min_2_7;
    x_8(2) >= -x_min_2_8;
    x_9(2) >= -x_min_2_9;
    x_10(2) >= -x_min_2_10;
    x_11(2) >= -x_min_2_11;
    x_12(2) >= -x_min_2_12;
    x_13(2) >= -x_min_2_13;
    x_14(2) >= -x_min_2_14;
    x_15(2) >= -x_min_2_15;
    x_16(2) >= -x_min_2_16;
    x_17(2) >= -x_min_2_17;
    x_18(2) >= -x_min_2_18;
    x_19(2) >= -x_min_2_19;
    x_20(2) >= -x_min_2_20;
    x_21(2) >= -x_min_2_21;
    x_22(2) >= -x_min_2_22;
    x_23(2) >= -x_min_2_23;
    x_24(2) >= -x_min_2_24;
    x_25(2) >= -x_min_2_25;
    x_26(2) >= -x_min_2_26;
    x_27(2) >= -x_min_2_27;
    x_28(2) >= -x_min_2_28;
    x_29(2) >= -x_min_2_29;
    x_30(2) >= -x_min_2_30;
    x_31(2) >= -x_min_2_31;
    x_32(2) >= -x_min_2_32;
    x_33(2) >= -x_min_2_33;
    x_34(2) >= -x_min_2_34;
    x_35(2) >= -x_min_2_35;
    x_36(2) >= -x_min_2_36;
    x_37(2) >= -x_min_2_37;
    x_38(2) >= -x_min_2_38;
    x_39(2) >= -x_min_2_39;
    x_40(2) >= -x_min_2_40;
    x_1(3) <= x_max_3_1;
    x_2(3) <= x_max_3_2;
    x_3(3) <= x_max_3_3;
    x_4(3) <= x_max_3_4;
    x_5(3) <= x_max_3_5;
    x_6(3) <= x_max_3_6;
    x_7(3) <= x_max_3_7;
    x_8(3) <= x_max_3_8;
    x_9(3) <= x_max_3_9;
    x_10(3) <= x_max_3_10;
    x_11(3) <= x_max_3_11;
    x_12(3) <= x_max_3_12;
    x_13(3) <= x_max_3_13;
    x_14(3) <= x_max_3_14;
    x_15(3) <= x_max_3_15;
    x_16(3) <= x_max_3_16;
    x_17(3) <= x_max_3_17;
    x_18(3) <= x_max_3_18;
    x_19(3) <= x_max_3_19;
    x_20(3) <= x_max_3_20;
    x_21(3) <= x_max_3_21;
    x_22(3) <= x_max_3_22;
    x_23(3) <= x_max_3_23;
    x_24(3) <= x_max_3_24;
    x_25(3) <= x_max_3_25;
    x_26(3) <= x_max_3_26;
    x_27(3) <= x_max_3_27;
    x_28(3) <= x_max_3_28;
    x_29(3) <= x_max_3_29;
    x_30(3) <= x_max_3_30;
    x_31(3) <= x_max_3_31;
    x_32(3) <= x_max_3_32;
    x_33(3) <= x_max_3_33;
    x_34(3) <= x_max_3_34;
    x_35(3) <= x_max_3_35;
    x_36(3) <= x_max_3_36;
    x_37(3) <= x_max_3_37;
    x_38(3) <= x_max_3_38;
    x_39(3) <= x_max_3_39;
    x_40(3) <= x_max_3_40;
    x_1(3) >= -x_min_3_1;
    x_2(3) >= -x_min_3_2;
    x_3(3) >= -x_min_3_3;
    x_4(3) >= -x_min_3_4;
    x_5(3) >= -x_min_3_5;
    x_6(3) >= -x_min_3_6;
    x_7(3) >= -x_min_3_7;
    x_8(3) >= -x_min_3_8;
    x_9(3) >= -x_min_3_9;
    x_10(3) >= -x_min_3_10;
    x_11(3) >= -x_min_3_11;
    x_12(3) >= -x_min_3_12;
    x_13(3) >= -x_min_3_13;
    x_14(3) >= -x_min_3_14;
    x_15(3) >= -x_min_3_15;
    x_16(3) >= -x_min_3_16;
    x_17(3) >= -x_min_3_17;
    x_18(3) >= -x_min_3_18;
    x_19(3) >= -x_min_3_19;
    x_20(3) >= -x_min_3_20;
    x_21(3) >= -x_min_3_21;
    x_22(3) >= -x_min_3_22;
    x_23(3) >= -x_min_3_23;
    x_24(3) >= -x_min_3_24;
    x_25(3) >= -x_min_3_25;
    x_26(3) >= -x_min_3_26;
    x_27(3) >= -x_min_3_27;
    x_28(3) >= -x_min_3_28;
    x_29(3) >= -x_min_3_29;
    x_30(3) >= -x_min_3_30;
    x_31(3) >= -x_min_3_31;
    x_32(3) >= -x_min_3_32;
    x_33(3) >= -x_min_3_33;
    x_34(3) >= -x_min_3_34;
    x_35(3) >= -x_min_3_35;
    x_36(3) >= -x_min_3_36;
    x_37(3) >= -x_min_3_37;
    x_38(3) >= -x_min_3_38;
    x_39(3) >= -x_min_3_39;
    x_40(3) >= -x_min_3_40;
    u_0(1) <= u_max_0;
    u_1(1) <= u_max_1;
    u_2(1) <= u_max_2;
    u_3(1) <= u_max_3;
    u_4(1) <= u_max_4;
    u_5(1) <= u_max_5;
    u_6(1) <= u_max_6;
    u_7(1) <= u_max_7;
    u_8(1) <= u_max_8;
    u_9(1) <= u_max_9;
    u_10(1) <= u_max_10;
    u_11(1) <= u_max_11;
    u_12(1) <= u_max_12;
    u_13(1) <= u_max_13;
    u_14(1) <= u_max_14;
    u_15(1) <= u_max_15;
    u_16(1) <= u_max_16;
    u_17(1) <= u_max_17;
    u_18(1) <= u_max_18;
    u_19(1) <= u_max_19;
    u_20(1) <= u_max_20;
    u_21(1) <= u_max_21;
    u_22(1) <= u_max_22;
    u_23(1) <= u_max_23;
    u_24(1) <= u_max_24;
    u_25(1) <= u_max_25;
    u_26(1) <= u_max_26;
    u_27(1) <= u_max_27;
    u_28(1) <= u_max_28;
    u_29(1) <= u_max_29;
    u_30(1) <= u_max_30;
    u_31(1) <= u_max_31;
    u_32(1) <= u_max_32;
    u_33(1) <= u_max_33;
    u_34(1) <= u_max_34;
    u_35(1) <= u_max_35;
    u_36(1) <= u_max_36;
    u_37(1) <= u_max_37;
    u_38(1) <= u_max_38;
    u_39(1) <= u_max_39;
    u_0(1) >= -u_min_0;
    u_1(1) >= -u_min_1;
    u_2(1) >= -u_min_2;
    u_3(1) >= -u_min_3;
    u_4(1) >= -u_min_4;
    u_5(1) >= -u_min_5;
    u_6(1) >= -u_min_6;
    u_7(1) >= -u_min_7;
    u_8(1) >= -u_min_8;
    u_9(1) >= -u_min_9;
    u_10(1) >= -u_min_10;
    u_11(1) >= -u_min_11;
    u_12(1) >= -u_min_12;
    u_13(1) >= -u_min_13;
    u_14(1) >= -u_min_14;
    u_15(1) >= -u_min_15;
    u_16(1) >= -u_min_16;
    u_17(1) >= -u_min_17;
    u_18(1) >= -u_min_18;
    u_19(1) >= -u_min_19;
    u_20(1) >= -u_min_20;
    u_21(1) >= -u_min_21;
    u_22(1) >= -u_min_22;
    u_23(1) >= -u_min_23;
    u_24(1) >= -u_min_24;
    u_25(1) >= -u_min_25;
    u_26(1) >= -u_min_26;
    u_27(1) >= -u_min_27;
    u_28(1) >= -u_min_28;
    u_29(1) >= -u_min_29;
    u_30(1) >= -u_min_30;
    u_31(1) >= -u_min_31;
    u_32(1) >= -u_min_32;
    u_33(1) >= -u_min_33;
    u_34(1) >= -u_min_34;
    u_35(1) >= -u_min_35;
    u_36(1) >= -u_min_36;
    u_37(1) >= -u_min_37;
    u_38(1) >= -u_min_38;
    u_39(1) >= -u_min_39;
cvx_end
vars.u_0 = u_0;
vars.u_1 = u_1;
vars.u{1} = u_1;
vars.u_2 = u_2;
vars.u{2} = u_2;
vars.u_3 = u_3;
vars.u{3} = u_3;
vars.u_4 = u_4;
vars.u{4} = u_4;
vars.u_5 = u_5;
vars.u{5} = u_5;
vars.u_6 = u_6;
vars.u{6} = u_6;
vars.u_7 = u_7;
vars.u{7} = u_7;
vars.u_8 = u_8;
vars.u{8} = u_8;
vars.u_9 = u_9;
vars.u{9} = u_9;
vars.u_10 = u_10;
vars.u{10} = u_10;
vars.u_11 = u_11;
vars.u{11} = u_11;
vars.u_12 = u_12;
vars.u{12} = u_12;
vars.u_13 = u_13;
vars.u{13} = u_13;
vars.u_14 = u_14;
vars.u{14} = u_14;
vars.u_15 = u_15;
vars.u{15} = u_15;
vars.u_16 = u_16;
vars.u{16} = u_16;
vars.u_17 = u_17;
vars.u{17} = u_17;
vars.u_18 = u_18;
vars.u{18} = u_18;
vars.u_19 = u_19;
vars.u{19} = u_19;
vars.u_20 = u_20;
vars.u{20} = u_20;
vars.u_21 = u_21;
vars.u{21} = u_21;
vars.u_22 = u_22;
vars.u{22} = u_22;
vars.u_23 = u_23;
vars.u{23} = u_23;
vars.u_24 = u_24;
vars.u{24} = u_24;
vars.u_25 = u_25;
vars.u{25} = u_25;
vars.u_26 = u_26;
vars.u{26} = u_26;
vars.u_27 = u_27;
vars.u{27} = u_27;
vars.u_28 = u_28;
vars.u{28} = u_28;
vars.u_29 = u_29;
vars.u{29} = u_29;
vars.u_30 = u_30;
vars.u{30} = u_30;
vars.u_31 = u_31;
vars.u{31} = u_31;
vars.u_32 = u_32;
vars.u{32} = u_32;
vars.u_33 = u_33;
vars.u{33} = u_33;
vars.u_34 = u_34;
vars.u{34} = u_34;
vars.u_35 = u_35;
vars.u{35} = u_35;
vars.u_36 = u_36;
vars.u{36} = u_36;
vars.u_37 = u_37;
vars.u{37} = u_37;
vars.u_38 = u_38;
vars.u{38} = u_38;
vars.u_39 = u_39;
vars.u{39} = u_39;
vars.x_1 = x_1;
vars.x{1} = x_1;
vars.x_2 = x_2;
vars.x{2} = x_2;
vars.x_3 = x_3;
vars.x{3} = x_3;
vars.x_4 = x_4;
vars.x{4} = x_4;
vars.x_5 = x_5;
vars.x{5} = x_5;
vars.x_6 = x_6;
vars.x{6} = x_6;
vars.x_7 = x_7;
vars.x{7} = x_7;
vars.x_8 = x_8;
vars.x{8} = x_8;
vars.x_9 = x_9;
vars.x{9} = x_9;
vars.x_10 = x_10;
vars.x{10} = x_10;
vars.x_11 = x_11;
vars.x{11} = x_11;
vars.x_12 = x_12;
vars.x{12} = x_12;
vars.x_13 = x_13;
vars.x{13} = x_13;
vars.x_14 = x_14;
vars.x{14} = x_14;
vars.x_15 = x_15;
vars.x{15} = x_15;
vars.x_16 = x_16;
vars.x{16} = x_16;
vars.x_17 = x_17;
vars.x{17} = x_17;
vars.x_18 = x_18;
vars.x{18} = x_18;
vars.x_19 = x_19;
vars.x{19} = x_19;
vars.x_20 = x_20;
vars.x{20} = x_20;
vars.x_21 = x_21;
vars.x{21} = x_21;
vars.x_22 = x_22;
vars.x{22} = x_22;
vars.x_23 = x_23;
vars.x{23} = x_23;
vars.x_24 = x_24;
vars.x{24} = x_24;
vars.x_25 = x_25;
vars.x{25} = x_25;
vars.x_26 = x_26;
vars.x{26} = x_26;
vars.x_27 = x_27;
vars.x{27} = x_27;
vars.x_28 = x_28;
vars.x{28} = x_28;
vars.x_29 = x_29;
vars.x{29} = x_29;
vars.x_30 = x_30;
vars.x{30} = x_30;
vars.x_31 = x_31;
vars.x{31} = x_31;
vars.x_32 = x_32;
vars.x{32} = x_32;
vars.x_33 = x_33;
vars.x{33} = x_33;
vars.x_34 = x_34;
vars.x{34} = x_34;
vars.x_35 = x_35;
vars.x{35} = x_35;
vars.x_36 = x_36;
vars.x{36} = x_36;
vars.x_37 = x_37;
vars.x{37} = x_37;
vars.x_38 = x_38;
vars.x{38} = x_38;
vars.x_39 = x_39;
vars.x{39} = x_39;
vars.x_40 = x_40;
vars.x{40} = x_40;
status.cvx_status = cvx_status;
% Provide a drop-in replacement for csolve.
status.optval = cvx_optval;
status.converged = strcmp(cvx_status, 'Solved');
