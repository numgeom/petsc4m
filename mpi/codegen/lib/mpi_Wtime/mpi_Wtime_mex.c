/*
 * mpi/codegen/lib/mpi_Wtime/mpi_Wtime_mex.c
 *
 * Auxiliary code for mexFunction of mpi_Wtime
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {}  enableInline=1
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C file generated by codegen in lib mode */
#include "mpi_Wtime.h"
#include "m2c.c"
/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

void mpi_Wtime_api(const mxArray ** prhs, const mxArray **plhs) {

    real64_T             secs;

    /* Preallocate output variables */

    /* Invoke the target function */
    mpi_Wtime_initialize();

    secs = mpi_Wtime();

    mpi_Wtime_terminate();

    /* Marshall out function outputs */
    plhs[0] = copy_scalar_to_mxArray(&secs, mxDOUBLE_CLASS);

}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    if (nrhs == 0) {
        if (nlhs > 1)
            mexErrMsgIdAndTxt("mpi_Wtime:TooManyOutputArguments","Too many output arguments for entry-point mpi_Wtime.");
        /* Call the API function. */
        mpi_Wtime_api(prhs, (const mxArray**)plhs);
    }
    else
        mexErrMsgIdAndTxt("mpi_Wtime:WrongNumberOfInputs","Incorrect number of input variables for entry-point mpi_Wtime.");
}