#!/usr/bin/python

def replace( filename ):
    with open(filename, 'r') as file :
        filedata = file.read()
        filedata = filedata.replace('Params', 'Params1d')
        filedata = filedata.replace('params', 'params1d')
        filedata = filedata.replace('Vars', 'Vars1d')
        filedata = filedata.replace('vars', 'vars1d')
        filedata = filedata.replace('Settings', 'Settings1d')
        filedata = filedata.replace('settings', 'settings1d')
        filedata = filedata.replace('Workspace', 'Workspace1d')
        filedata = filedata.replace('work', 'work1d')


        filedata = filedata.replace('ldl_solve(', 'ldl_solve1d(');
        filedata = filedata.replace('ldl_factor(', 'ldl_factor1d(');
        filedata = filedata.replace('check_factorization(', 'check_factorization1d(');
        filedata = filedata.replace('matrix_multiply(', 'matrix_multiply1d(');
        filedata = filedata.replace('check_residual(', 'check_residual1d(');
        filedata = filedata.replace('fill_KKT(', 'fill_KKT1d(');
  
        filedata = filedata.replace('multbymA(', 'multbymA1d(')
        filedata = filedata.replace('multbymATmultbymAT(', 'multbymATmultbymAT1d(')
        filedata = filedata.replace('multbymG(', 'multbymG1d(')
        filedata = filedata.replace('multbymGT(', 'multbymGT1d(')
        filedata = filedata.replace('multbyP(', 'multbyP1d(')
        filedata = filedata.replace('fillq(', 'fillq1d(')
        filedata = filedata.replace('fillh(', 'fillh1d(')
        filedata = filedata.replace('fillb(', 'fillb1d(')
        filedata = filedata.replace('pre_ops(', 'pre_ops1d(')
        filedata = filedata.replace('eval_gap(', 'eval_gap1d(')
        filedata = filedata.replace('set_defaults(', 'set_defaults1d(')
        filedata = filedata.replace('setup_pointers(', 'setup_pointers1d(')
        filedata = filedata.replace('setup_indexed_params1d(', 'setup_indexed_params1d1d(')
        filedata = filedata.replace('setup_indexed_optvars1d(', 'setup_indexed_optvars1d1d(')
        filedata = filedata.replace('setup_indexing(', 'setup_indexing1d(')
        filedata = filedata.replace('set_start(', 'set_start1d(')
        filedata = filedata.replace('eval_objv(', 'eval_objv1d(')
        filedata = filedata.replace('fillrhs_aff(', 'fillrhs_aff1d(')
        filedata = filedata.replace('fillrhs_cc(', 'fillrhs_cc1d(')
        filedata = filedata.replace('refine(', 'refine1d(')
        filedata = filedata.replace('calc_ineq_resid_squared(', 'calc_ineq_resid_squared1d(')
        filedata = filedata.replace('calc_eq_resid_squared(', 'calc_eq_resid_squared1d(')
        filedata = filedata.replace('better_start(', 'better_start1d(')
        filedata = filedata.replace('fillrhs_start(', 'fillrhs_start1d(')
        filedata = filedata.replace('solve(', 'solve1d(')
        filedata = filedata.replace('main(', 'main1d(')
        filedata = filedata.replace('load_default_data(', 'load_default_data1d(')
        filedata = filedata.replace('tic(', 'tic1d(')
        filedata = filedata.replace('toc(', 'toc1d(')
        filedata = filedata.replace('tocq(', 'tocq1d(')
        filedata = filedata.replace('printmatrix(', 'printmatrix1d(')
        filedata = filedata.replace('unif(', 'unif1d(')
        filedata = filedata.replace('ran1(', 'ran11d(')
        filedata = filedata.replace('randn_internal(', 'randn_internal1d(')
        filedata = filedata.replace('randn(', 'randn1d(')
        filedata = filedata.replace('reset_rand(', 'reset_rand1d(')
        
    with open(filename, 'w') as file :
        file.write(filedata)

replace("solver.h")
replace("solver.c")
replace("csolve.c")
replace("ldl.c")
replace("matrix_support.c")
replace("util.c")
