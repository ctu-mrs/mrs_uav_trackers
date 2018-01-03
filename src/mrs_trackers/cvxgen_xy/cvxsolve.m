% Produced by CVXGEN, 2018-01-03 10:43:03 -0500.
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
x_0 = params.x_0;
x_aprx_max_1 = params.x_aprx_max_1;
x_aprx_min_1 = params.x_aprx_min_1;
x_max_2 = params.x_max_2;
x_max_3 = params.x_max_3;
x_min_2 = params.x_min_2;
x_min_3 = params.x_min_3;
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
  variable x_1(6, 1);
  variable x_2(6, 1);
  variable x_3(6, 1);
  variable x_4(6, 1);
  variable x_5(6, 1);
  variable x_6(6, 1);
  variable x_7(6, 1);
  variable x_8(6, 1);
  variable x_9(6, 1);
  variable x_10(6, 1);
  variable x_11(6, 1);
  variable x_12(6, 1);
  variable x_13(6, 1);
  variable x_14(6, 1);
  variable x_15(6, 1);
  variable x_16(6, 1);
  variable x_17(6, 1);
  variable x_18(6, 1);
  variable x_19(6, 1);
  variable x_20(6, 1);
  variable x_21(6, 1);
  variable x_22(6, 1);
  variable x_23(6, 1);
  variable x_24(6, 1);
  variable x_25(6, 1);
  variable x_26(6, 1);
  variable x_27(6, 1);
  variable x_28(6, 1);
  variable x_29(6, 1);
  variable x_30(6, 1);
  variable x_31(6, 1);
  variable x_32(6, 1);
  variable x_33(6, 1);
  variable x_34(6, 1);
  variable x_35(6, 1);
  variable x_36(6, 1);
  variable x_37(6, 1);
  variable x_38(6, 1);
  variable x_39(6, 1);
  variable x_40(6, 1);
  variable u_1(2, 1);
  variable u_2(2, 1);
  variable u_3(2, 1);
  variable u_4(2, 1);
  variable u_5(2, 1);
  variable u_6(2, 1);
  variable u_7(2, 1);
  variable u_8(2, 1);
  variable u_9(2, 1);
  variable u_10(2, 1);
  variable u_11(2, 1);
  variable u_12(2, 1);
  variable u_13(2, 1);
  variable u_14(2, 1);
  variable u_15(2, 1);
  variable u_16(2, 1);
  variable u_17(2, 1);
  variable u_18(2, 1);
  variable u_19(2, 1);
  variable u_20(2, 1);
  variable u_21(2, 1);
  variable u_22(2, 1);
  variable u_23(2, 1);
  variable u_24(2, 1);
  variable u_25(2, 1);
  variable u_26(2, 1);
  variable u_27(2, 1);
  variable u_28(2, 1);
  variable u_29(2, 1);
  variable u_30(2, 1);
  variable u_31(2, 1);
  variable u_32(2, 1);
  variable u_33(2, 1);
  variable u_34(2, 1);
  variable u_35(2, 1);
  variable u_36(2, 1);
  variable u_37(2, 1);
  variable u_38(2, 1);
  variable u_39(2, 1);
  variable u_40(2, 1);
  variable u_0(2, 1);

  minimize(quad_form(x_1 - x_ss_1, Q) + quad_form(x_2 - x_ss_2, Q) + quad_form(x_3 - x_ss_3, Q) + quad_form(x_4 - x_ss_4, Q) + quad_form(x_5 - x_ss_5, Q) + quad_form(x_6 - x_ss_6, Q) + quad_form(x_7 - x_ss_7, Q) + quad_form(x_8 - x_ss_8, Q) + quad_form(x_9 - x_ss_9, Q) + quad_form(x_10 - x_ss_10, Q) + quad_form(x_11 - x_ss_11, Q) + quad_form(x_12 - x_ss_12, Q) + quad_form(x_13 - x_ss_13, Q) + quad_form(x_14 - x_ss_14, Q) + quad_form(x_15 - x_ss_15, Q) + quad_form(x_16 - x_ss_16, Q) + quad_form(x_17 - x_ss_17, Q) + quad_form(x_18 - x_ss_18, Q) + quad_form(x_19 - x_ss_19, Q) + quad_form(x_20 - x_ss_20, Q) + quad_form(x_21 - x_ss_21, Q) + quad_form(x_22 - x_ss_22, Q) + quad_form(x_23 - x_ss_23, Q) + quad_form(x_24 - x_ss_24, Q) + quad_form(x_25 - x_ss_25, Q) + quad_form(x_26 - x_ss_26, Q) + quad_form(x_27 - x_ss_27, Q) + quad_form(x_28 - x_ss_28, Q) + quad_form(x_29 - x_ss_29, Q) + quad_form(x_30 - x_ss_30, Q) + quad_form(x_31 - x_ss_31, Q) + quad_form(x_32 - x_ss_32, Q) + quad_form(x_33 - x_ss_33, Q) + quad_form(x_34 - x_ss_34, Q) + quad_form(x_35 - x_ss_35, Q) + quad_form(x_36 - x_ss_36, Q) + quad_form(x_37 - x_ss_37, Q) + quad_form(x_38 - x_ss_38, Q) + quad_form(x_39 - x_ss_39, Q) + quad_form(x_40 - x_ss_40, Q) + quad_form(u_1, R) + quad_form(u_2, R) + quad_form(u_3, R) + quad_form(u_4, R) + quad_form(u_5, R) + quad_form(u_6, R) + quad_form(u_7, R) + quad_form(u_8, R) + quad_form(u_9, R) + quad_form(u_10, R) + quad_form(u_11, R) + quad_form(u_12, R) + quad_form(u_13, R) + quad_form(u_14, R) + quad_form(u_15, R) + quad_form(u_16, R) + quad_form(u_17, R) + quad_form(u_18, R) + quad_form(u_19, R) + quad_form(u_20, R) + quad_form(u_21, R) + quad_form(u_22, R) + quad_form(u_23, R) + quad_form(u_24, R) + quad_form(u_25, R) + quad_form(u_26, R) + quad_form(u_27, R) + quad_form(u_28, R) + quad_form(u_29, R) + quad_form(u_30, R) + quad_form(u_31, R) + quad_form(u_32, R) + quad_form(u_33, R) + quad_form(u_34, R) + quad_form(u_35, R) + quad_form(u_36, R) + quad_form(u_37, R) + quad_form(u_38, R) + quad_form(u_39, R) + quad_form(u_40, R));
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
    x_1(2) <= x_max_2;
    x_2(2) <= x_max_2;
    x_3(2) <= x_max_2;
    x_4(2) <= x_max_2;
    x_5(2) <= x_max_2;
    x_6(2) <= x_max_2;
    x_7(2) <= x_max_2;
    x_8(2) <= x_max_2;
    x_9(2) <= x_max_2;
    x_10(2) <= x_max_2;
    x_11(2) <= x_max_2;
    x_12(2) <= x_max_2;
    x_13(2) <= x_max_2;
    x_14(2) <= x_max_2;
    x_15(2) <= x_max_2;
    x_16(2) <= x_max_2;
    x_17(2) <= x_max_2;
    x_18(2) <= x_max_2;
    x_19(2) <= x_max_2;
    x_20(2) <= x_max_2;
    x_21(2) <= x_max_2;
    x_22(2) <= x_max_2;
    x_23(2) <= x_max_2;
    x_24(2) <= x_max_2;
    x_25(2) <= x_max_2;
    x_26(2) <= x_max_2;
    x_27(2) <= x_max_2;
    x_28(2) <= x_max_2;
    x_29(2) <= x_max_2;
    x_30(2) <= x_max_2;
    x_31(2) <= x_max_2;
    x_32(2) <= x_max_2;
    x_33(2) <= x_max_2;
    x_34(2) <= x_max_2;
    x_35(2) <= x_max_2;
    x_36(2) <= x_max_2;
    x_37(2) <= x_max_2;
    x_38(2) <= x_max_2;
    x_39(2) <= x_max_2;
    x_40(2) <= x_max_2;
    x_1(3) <= x_max_3;
    x_2(3) <= x_max_3;
    x_3(3) <= x_max_3;
    x_4(3) <= x_max_3;
    x_5(3) <= x_max_3;
    x_6(3) <= x_max_3;
    x_7(3) <= x_max_3;
    x_8(3) <= x_max_3;
    x_9(3) <= x_max_3;
    x_10(3) <= x_max_3;
    x_11(3) <= x_max_3;
    x_12(3) <= x_max_3;
    x_13(3) <= x_max_3;
    x_14(3) <= x_max_3;
    x_15(3) <= x_max_3;
    x_16(3) <= x_max_3;
    x_17(3) <= x_max_3;
    x_18(3) <= x_max_3;
    x_19(3) <= x_max_3;
    x_20(3) <= x_max_3;
    x_21(3) <= x_max_3;
    x_22(3) <= x_max_3;
    x_23(3) <= x_max_3;
    x_24(3) <= x_max_3;
    x_25(3) <= x_max_3;
    x_26(3) <= x_max_3;
    x_27(3) <= x_max_3;
    x_28(3) <= x_max_3;
    x_29(3) <= x_max_3;
    x_30(3) <= x_max_3;
    x_31(3) <= x_max_3;
    x_32(3) <= x_max_3;
    x_33(3) <= x_max_3;
    x_34(3) <= x_max_3;
    x_35(3) <= x_max_3;
    x_36(3) <= x_max_3;
    x_37(3) <= x_max_3;
    x_38(3) <= x_max_3;
    x_39(3) <= x_max_3;
    x_40(3) <= x_max_3;
    x_1(2) >= x_min_2;
    x_2(2) >= x_min_2;
    x_3(2) >= x_min_2;
    x_4(2) >= x_min_2;
    x_5(2) >= x_min_2;
    x_6(2) >= x_min_2;
    x_7(2) >= x_min_2;
    x_8(2) >= x_min_2;
    x_9(2) >= x_min_2;
    x_10(2) >= x_min_2;
    x_11(2) >= x_min_2;
    x_12(2) >= x_min_2;
    x_13(2) >= x_min_2;
    x_14(2) >= x_min_2;
    x_15(2) >= x_min_2;
    x_16(2) >= x_min_2;
    x_17(2) >= x_min_2;
    x_18(2) >= x_min_2;
    x_19(2) >= x_min_2;
    x_20(2) >= x_min_2;
    x_21(2) >= x_min_2;
    x_22(2) >= x_min_2;
    x_23(2) >= x_min_2;
    x_24(2) >= x_min_2;
    x_25(2) >= x_min_2;
    x_26(2) >= x_min_2;
    x_27(2) >= x_min_2;
    x_28(2) >= x_min_2;
    x_29(2) >= x_min_2;
    x_30(2) >= x_min_2;
    x_31(2) >= x_min_2;
    x_32(2) >= x_min_2;
    x_33(2) >= x_min_2;
    x_34(2) >= x_min_2;
    x_35(2) >= x_min_2;
    x_36(2) >= x_min_2;
    x_37(2) >= x_min_2;
    x_38(2) >= x_min_2;
    x_39(2) >= x_min_2;
    x_40(2) >= x_min_2;
    x_1(3) >= x_min_3;
    x_2(3) >= x_min_3;
    x_3(3) >= x_min_3;
    x_4(3) >= x_min_3;
    x_5(3) >= x_min_3;
    x_6(3) >= x_min_3;
    x_7(3) >= x_min_3;
    x_8(3) >= x_min_3;
    x_9(3) >= x_min_3;
    x_10(3) >= x_min_3;
    x_11(3) >= x_min_3;
    x_12(3) >= x_min_3;
    x_13(3) >= x_min_3;
    x_14(3) >= x_min_3;
    x_15(3) >= x_min_3;
    x_16(3) >= x_min_3;
    x_17(3) >= x_min_3;
    x_18(3) >= x_min_3;
    x_19(3) >= x_min_3;
    x_20(3) >= x_min_3;
    x_21(3) >= x_min_3;
    x_22(3) >= x_min_3;
    x_23(3) >= x_min_3;
    x_24(3) >= x_min_3;
    x_25(3) >= x_min_3;
    x_26(3) >= x_min_3;
    x_27(3) >= x_min_3;
    x_28(3) >= x_min_3;
    x_29(3) >= x_min_3;
    x_30(3) >= x_min_3;
    x_31(3) >= x_min_3;
    x_32(3) >= x_min_3;
    x_33(3) >= x_min_3;
    x_34(3) >= x_min_3;
    x_35(3) >= x_min_3;
    x_36(3) >= x_min_3;
    x_37(3) >= x_min_3;
    x_38(3) >= x_min_3;
    x_39(3) >= x_min_3;
    x_40(3) >= x_min_3;
    x_1(5) <= x_max_2;
    x_2(5) <= x_max_2;
    x_3(5) <= x_max_2;
    x_4(5) <= x_max_2;
    x_5(5) <= x_max_2;
    x_6(5) <= x_max_2;
    x_7(5) <= x_max_2;
    x_8(5) <= x_max_2;
    x_9(5) <= x_max_2;
    x_10(5) <= x_max_2;
    x_11(5) <= x_max_2;
    x_12(5) <= x_max_2;
    x_13(5) <= x_max_2;
    x_14(5) <= x_max_2;
    x_15(5) <= x_max_2;
    x_16(5) <= x_max_2;
    x_17(5) <= x_max_2;
    x_18(5) <= x_max_2;
    x_19(5) <= x_max_2;
    x_20(5) <= x_max_2;
    x_21(5) <= x_max_2;
    x_22(5) <= x_max_2;
    x_23(5) <= x_max_2;
    x_24(5) <= x_max_2;
    x_25(5) <= x_max_2;
    x_26(5) <= x_max_2;
    x_27(5) <= x_max_2;
    x_28(5) <= x_max_2;
    x_29(5) <= x_max_2;
    x_30(5) <= x_max_2;
    x_31(5) <= x_max_2;
    x_32(5) <= x_max_2;
    x_33(5) <= x_max_2;
    x_34(5) <= x_max_2;
    x_35(5) <= x_max_2;
    x_36(5) <= x_max_2;
    x_37(5) <= x_max_2;
    x_38(5) <= x_max_2;
    x_39(5) <= x_max_2;
    x_40(5) <= x_max_2;
    x_1(6) <= x_max_3;
    x_2(6) <= x_max_3;
    x_3(6) <= x_max_3;
    x_4(6) <= x_max_3;
    x_5(6) <= x_max_3;
    x_6(6) <= x_max_3;
    x_7(6) <= x_max_3;
    x_8(6) <= x_max_3;
    x_9(6) <= x_max_3;
    x_10(6) <= x_max_3;
    x_11(6) <= x_max_3;
    x_12(6) <= x_max_3;
    x_13(6) <= x_max_3;
    x_14(6) <= x_max_3;
    x_15(6) <= x_max_3;
    x_16(6) <= x_max_3;
    x_17(6) <= x_max_3;
    x_18(6) <= x_max_3;
    x_19(6) <= x_max_3;
    x_20(6) <= x_max_3;
    x_21(6) <= x_max_3;
    x_22(6) <= x_max_3;
    x_23(6) <= x_max_3;
    x_24(6) <= x_max_3;
    x_25(6) <= x_max_3;
    x_26(6) <= x_max_3;
    x_27(6) <= x_max_3;
    x_28(6) <= x_max_3;
    x_29(6) <= x_max_3;
    x_30(6) <= x_max_3;
    x_31(6) <= x_max_3;
    x_32(6) <= x_max_3;
    x_33(6) <= x_max_3;
    x_34(6) <= x_max_3;
    x_35(6) <= x_max_3;
    x_36(6) <= x_max_3;
    x_37(6) <= x_max_3;
    x_38(6) <= x_max_3;
    x_39(6) <= x_max_3;
    x_40(6) <= x_max_3;
    x_1(5) >= x_min_2;
    x_2(5) >= x_min_2;
    x_3(5) >= x_min_2;
    x_4(5) >= x_min_2;
    x_5(5) >= x_min_2;
    x_6(5) >= x_min_2;
    x_7(5) >= x_min_2;
    x_8(5) >= x_min_2;
    x_9(5) >= x_min_2;
    x_10(5) >= x_min_2;
    x_11(5) >= x_min_2;
    x_12(5) >= x_min_2;
    x_13(5) >= x_min_2;
    x_14(5) >= x_min_2;
    x_15(5) >= x_min_2;
    x_16(5) >= x_min_2;
    x_17(5) >= x_min_2;
    x_18(5) >= x_min_2;
    x_19(5) >= x_min_2;
    x_20(5) >= x_min_2;
    x_21(5) >= x_min_2;
    x_22(5) >= x_min_2;
    x_23(5) >= x_min_2;
    x_24(5) >= x_min_2;
    x_25(5) >= x_min_2;
    x_26(5) >= x_min_2;
    x_27(5) >= x_min_2;
    x_28(5) >= x_min_2;
    x_29(5) >= x_min_2;
    x_30(5) >= x_min_2;
    x_31(5) >= x_min_2;
    x_32(5) >= x_min_2;
    x_33(5) >= x_min_2;
    x_34(5) >= x_min_2;
    x_35(5) >= x_min_2;
    x_36(5) >= x_min_2;
    x_37(5) >= x_min_2;
    x_38(5) >= x_min_2;
    x_39(5) >= x_min_2;
    x_40(5) >= x_min_2;
    x_1(6) >= x_min_3;
    x_2(6) >= x_min_3;
    x_3(6) >= x_min_3;
    x_4(6) >= x_min_3;
    x_5(6) >= x_min_3;
    x_6(6) >= x_min_3;
    x_7(6) >= x_min_3;
    x_8(6) >= x_min_3;
    x_9(6) >= x_min_3;
    x_10(6) >= x_min_3;
    x_11(6) >= x_min_3;
    x_12(6) >= x_min_3;
    x_13(6) >= x_min_3;
    x_14(6) >= x_min_3;
    x_15(6) >= x_min_3;
    x_16(6) >= x_min_3;
    x_17(6) >= x_min_3;
    x_18(6) >= x_min_3;
    x_19(6) >= x_min_3;
    x_20(6) >= x_min_3;
    x_21(6) >= x_min_3;
    x_22(6) >= x_min_3;
    x_23(6) >= x_min_3;
    x_24(6) >= x_min_3;
    x_25(6) >= x_min_3;
    x_26(6) >= x_min_3;
    x_27(6) >= x_min_3;
    x_28(6) >= x_min_3;
    x_29(6) >= x_min_3;
    x_30(6) >= x_min_3;
    x_31(6) >= x_min_3;
    x_32(6) >= x_min_3;
    x_33(6) >= x_min_3;
    x_34(6) >= x_min_3;
    x_35(6) >= x_min_3;
    x_36(6) >= x_min_3;
    x_37(6) >= x_min_3;
    x_38(6) >= x_min_3;
    x_39(6) >= x_min_3;
    x_40(6) >= x_min_3;
    x_1(2) + x_1(5) <= x_aprx_max_1;
    x_2(2) + x_2(5) <= x_aprx_max_1;
    x_3(2) + x_3(5) <= x_aprx_max_1;
    x_4(2) + x_4(5) <= x_aprx_max_1;
    x_5(2) + x_5(5) <= x_aprx_max_1;
    x_6(2) + x_6(5) <= x_aprx_max_1;
    x_7(2) + x_7(5) <= x_aprx_max_1;
    x_8(2) + x_8(5) <= x_aprx_max_1;
    x_9(2) + x_9(5) <= x_aprx_max_1;
    x_10(2) + x_10(5) <= x_aprx_max_1;
    x_11(2) + x_11(5) <= x_aprx_max_1;
    x_12(2) + x_12(5) <= x_aprx_max_1;
    x_13(2) + x_13(5) <= x_aprx_max_1;
    x_14(2) + x_14(5) <= x_aprx_max_1;
    x_15(2) + x_15(5) <= x_aprx_max_1;
    x_16(2) + x_16(5) <= x_aprx_max_1;
    x_17(2) + x_17(5) <= x_aprx_max_1;
    x_18(2) + x_18(5) <= x_aprx_max_1;
    x_19(2) + x_19(5) <= x_aprx_max_1;
    x_20(2) + x_20(5) <= x_aprx_max_1;
    x_21(2) + x_21(5) <= x_aprx_max_1;
    x_22(2) + x_22(5) <= x_aprx_max_1;
    x_23(2) + x_23(5) <= x_aprx_max_1;
    x_24(2) + x_24(5) <= x_aprx_max_1;
    x_25(2) + x_25(5) <= x_aprx_max_1;
    x_26(2) + x_26(5) <= x_aprx_max_1;
    x_27(2) + x_27(5) <= x_aprx_max_1;
    x_28(2) + x_28(5) <= x_aprx_max_1;
    x_29(2) + x_29(5) <= x_aprx_max_1;
    x_30(2) + x_30(5) <= x_aprx_max_1;
    x_31(2) + x_31(5) <= x_aprx_max_1;
    x_32(2) + x_32(5) <= x_aprx_max_1;
    x_33(2) + x_33(5) <= x_aprx_max_1;
    x_34(2) + x_34(5) <= x_aprx_max_1;
    x_35(2) + x_35(5) <= x_aprx_max_1;
    x_36(2) + x_36(5) <= x_aprx_max_1;
    x_37(2) + x_37(5) <= x_aprx_max_1;
    x_38(2) + x_38(5) <= x_aprx_max_1;
    x_39(2) + x_39(5) <= x_aprx_max_1;
    x_40(2) + x_40(5) <= x_aprx_max_1;
    x_1(2) + x_1(5) >= x_aprx_min_1;
    x_2(2) + x_2(5) >= x_aprx_min_1;
    x_3(2) + x_3(5) >= x_aprx_min_1;
    x_4(2) + x_4(5) >= x_aprx_min_1;
    x_5(2) + x_5(5) >= x_aprx_min_1;
    x_6(2) + x_6(5) >= x_aprx_min_1;
    x_7(2) + x_7(5) >= x_aprx_min_1;
    x_8(2) + x_8(5) >= x_aprx_min_1;
    x_9(2) + x_9(5) >= x_aprx_min_1;
    x_10(2) + x_10(5) >= x_aprx_min_1;
    x_11(2) + x_11(5) >= x_aprx_min_1;
    x_12(2) + x_12(5) >= x_aprx_min_1;
    x_13(2) + x_13(5) >= x_aprx_min_1;
    x_14(2) + x_14(5) >= x_aprx_min_1;
    x_15(2) + x_15(5) >= x_aprx_min_1;
    x_16(2) + x_16(5) >= x_aprx_min_1;
    x_17(2) + x_17(5) >= x_aprx_min_1;
    x_18(2) + x_18(5) >= x_aprx_min_1;
    x_19(2) + x_19(5) >= x_aprx_min_1;
    x_20(2) + x_20(5) >= x_aprx_min_1;
    x_21(2) + x_21(5) >= x_aprx_min_1;
    x_22(2) + x_22(5) >= x_aprx_min_1;
    x_23(2) + x_23(5) >= x_aprx_min_1;
    x_24(2) + x_24(5) >= x_aprx_min_1;
    x_25(2) + x_25(5) >= x_aprx_min_1;
    x_26(2) + x_26(5) >= x_aprx_min_1;
    x_27(2) + x_27(5) >= x_aprx_min_1;
    x_28(2) + x_28(5) >= x_aprx_min_1;
    x_29(2) + x_29(5) >= x_aprx_min_1;
    x_30(2) + x_30(5) >= x_aprx_min_1;
    x_31(2) + x_31(5) >= x_aprx_min_1;
    x_32(2) + x_32(5) >= x_aprx_min_1;
    x_33(2) + x_33(5) >= x_aprx_min_1;
    x_34(2) + x_34(5) >= x_aprx_min_1;
    x_35(2) + x_35(5) >= x_aprx_min_1;
    x_36(2) + x_36(5) >= x_aprx_min_1;
    x_37(2) + x_37(5) >= x_aprx_min_1;
    x_38(2) + x_38(5) >= x_aprx_min_1;
    x_39(2) + x_39(5) >= x_aprx_min_1;
    x_40(2) + x_40(5) >= x_aprx_min_1;
    x_1(2) - x_1(5) <= x_aprx_max_1;
    x_2(2) - x_2(5) <= x_aprx_max_1;
    x_3(2) - x_3(5) <= x_aprx_max_1;
    x_4(2) - x_4(5) <= x_aprx_max_1;
    x_5(2) - x_5(5) <= x_aprx_max_1;
    x_6(2) - x_6(5) <= x_aprx_max_1;
    x_7(2) - x_7(5) <= x_aprx_max_1;
    x_8(2) - x_8(5) <= x_aprx_max_1;
    x_9(2) - x_9(5) <= x_aprx_max_1;
    x_10(2) - x_10(5) <= x_aprx_max_1;
    x_11(2) - x_11(5) <= x_aprx_max_1;
    x_12(2) - x_12(5) <= x_aprx_max_1;
    x_13(2) - x_13(5) <= x_aprx_max_1;
    x_14(2) - x_14(5) <= x_aprx_max_1;
    x_15(2) - x_15(5) <= x_aprx_max_1;
    x_16(2) - x_16(5) <= x_aprx_max_1;
    x_17(2) - x_17(5) <= x_aprx_max_1;
    x_18(2) - x_18(5) <= x_aprx_max_1;
    x_19(2) - x_19(5) <= x_aprx_max_1;
    x_20(2) - x_20(5) <= x_aprx_max_1;
    x_21(2) - x_21(5) <= x_aprx_max_1;
    x_22(2) - x_22(5) <= x_aprx_max_1;
    x_23(2) - x_23(5) <= x_aprx_max_1;
    x_24(2) - x_24(5) <= x_aprx_max_1;
    x_25(2) - x_25(5) <= x_aprx_max_1;
    x_26(2) - x_26(5) <= x_aprx_max_1;
    x_27(2) - x_27(5) <= x_aprx_max_1;
    x_28(2) - x_28(5) <= x_aprx_max_1;
    x_29(2) - x_29(5) <= x_aprx_max_1;
    x_30(2) - x_30(5) <= x_aprx_max_1;
    x_31(2) - x_31(5) <= x_aprx_max_1;
    x_32(2) - x_32(5) <= x_aprx_max_1;
    x_33(2) - x_33(5) <= x_aprx_max_1;
    x_34(2) - x_34(5) <= x_aprx_max_1;
    x_35(2) - x_35(5) <= x_aprx_max_1;
    x_36(2) - x_36(5) <= x_aprx_max_1;
    x_37(2) - x_37(5) <= x_aprx_max_1;
    x_38(2) - x_38(5) <= x_aprx_max_1;
    x_39(2) - x_39(5) <= x_aprx_max_1;
    x_40(2) - x_40(5) <= x_aprx_max_1;
    x_1(2) - x_1(5) >= x_aprx_min_1;
    x_2(2) - x_2(5) >= x_aprx_min_1;
    x_3(2) - x_3(5) >= x_aprx_min_1;
    x_4(2) - x_4(5) >= x_aprx_min_1;
    x_5(2) - x_5(5) >= x_aprx_min_1;
    x_6(2) - x_6(5) >= x_aprx_min_1;
    x_7(2) - x_7(5) >= x_aprx_min_1;
    x_8(2) - x_8(5) >= x_aprx_min_1;
    x_9(2) - x_9(5) >= x_aprx_min_1;
    x_10(2) - x_10(5) >= x_aprx_min_1;
    x_11(2) - x_11(5) >= x_aprx_min_1;
    x_12(2) - x_12(5) >= x_aprx_min_1;
    x_13(2) - x_13(5) >= x_aprx_min_1;
    x_14(2) - x_14(5) >= x_aprx_min_1;
    x_15(2) - x_15(5) >= x_aprx_min_1;
    x_16(2) - x_16(5) >= x_aprx_min_1;
    x_17(2) - x_17(5) >= x_aprx_min_1;
    x_18(2) - x_18(5) >= x_aprx_min_1;
    x_19(2) - x_19(5) >= x_aprx_min_1;
    x_20(2) - x_20(5) >= x_aprx_min_1;
    x_21(2) - x_21(5) >= x_aprx_min_1;
    x_22(2) - x_22(5) >= x_aprx_min_1;
    x_23(2) - x_23(5) >= x_aprx_min_1;
    x_24(2) - x_24(5) >= x_aprx_min_1;
    x_25(2) - x_25(5) >= x_aprx_min_1;
    x_26(2) - x_26(5) >= x_aprx_min_1;
    x_27(2) - x_27(5) >= x_aprx_min_1;
    x_28(2) - x_28(5) >= x_aprx_min_1;
    x_29(2) - x_29(5) >= x_aprx_min_1;
    x_30(2) - x_30(5) >= x_aprx_min_1;
    x_31(2) - x_31(5) >= x_aprx_min_1;
    x_32(2) - x_32(5) >= x_aprx_min_1;
    x_33(2) - x_33(5) >= x_aprx_min_1;
    x_34(2) - x_34(5) >= x_aprx_min_1;
    x_35(2) - x_35(5) >= x_aprx_min_1;
    x_36(2) - x_36(5) >= x_aprx_min_1;
    x_37(2) - x_37(5) >= x_aprx_min_1;
    x_38(2) - x_38(5) >= x_aprx_min_1;
    x_39(2) - x_39(5) >= x_aprx_min_1;
    x_40(2) - x_40(5) >= x_aprx_min_1;
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
vars.u_40 = u_40;
vars.u{40} = u_40;
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
