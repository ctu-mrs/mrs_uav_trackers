#!/usr/bin/python

def replace( filename ):
    with open(filename, 'r') as file :
        filedata = file.read()
        filedata = filedata.replace(' Params', ' Params1d')
        filedata = filedata.replace(' params', ' params1d')
        filedata = filedata.replace(' Vars', ' Vars1d')
        filedata = filedata.replace(' vars', ' vars1d')
        filedata = filedata.replace(' Settings', ' Settings1d')
        filedata = filedata.replace(' settings', ' settings1d')
        filedata = filedata.replace(' Workspace', ' Workspace1d')
        filedata = filedata.replace(' work', ' work1d')
    with open(filename, 'w') as file :
        file.write(filedata)

replace("solver.h")
replace("solver.c")
replace("csolve.c")
replace("ldl.c")
replace("matrix_support.c")
replace("util.c")
