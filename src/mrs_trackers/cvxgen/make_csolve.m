<<<<<<< HEAD
% Produced by CVXGEN, 2018-01-03 04:19:29 -0500.
=======
% Produced by CVXGEN, 2017-12-28 05:21:14 -0500.
>>>>>>> 4b7c700f248a3235bb36ee77228279091af2a5f5
% CVXGEN is Copyright (C) 2006-2017 Jacob Mattingley, jem@cvxgen.com.
% The code in this file is Copyright (C) 2006-2017 Jacob Mattingley.
% CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial
% applications without prior written permission from Jacob Mattingley.

% Filename: make_csolve.m.
% Description: Calls mex to generate the csolve mex file.
%mex -v csolve.c ldl.c matrix_support.c solver.c util.c
mex csolve.c ldl.c matrix_support.c solver.c util.c
