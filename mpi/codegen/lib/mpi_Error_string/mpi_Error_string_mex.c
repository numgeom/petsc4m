/*
 * mpi/codegen/lib/mpi_Error_string/mpi_Error_string_mex.c
 *
 * Auxiliary code for mexFunction of mpi_Error_string
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {int32(0)}  enableInline=1 withPetsc=1
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C file generated by codegen in lib mode */
#include "mpi_Error_string.h"
#include "m2c.c"
/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

void mpi_Error_string_api(const mxArray ** prhs, const mxArray **plhs) {

    emxArray_char_T      msg;

    int32_T              errcode;
    int32_T              *info;
    boolean_T            *toplevel;

    /* Marshall in function inputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("mpi_Error_string:WrongInputType",
            "Input argument errcode has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("mpi_Error_string:WrongSizeOfInputArg",
            "Argument errcode should be a scalar.");
    errcode = *(int32_T*)mxGetData(prhs[0]);

    /* Preallocate output variables */
    init_emxArray((emxArray__common*)&msg, 2);
    {mwSize l_size[] = {1, 1};
    *(void **)&info = prealloc_mxArray((mxArray**)&plhs[1], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[2], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    mpi_Error_string_initialize();

    mpi_Error_string(errcode, &msg, info, toplevel);

    mpi_Error_string_terminate();

    /* Marshall out function outputs */
    plhs[0] = move_emxArray_to_mxArray((emxArray__common*)&msg, mxCHAR_CLASS);
    /* Nothing to do for plhs[1] */
    /* Nothing to do for plhs[2] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)&msg);
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[3];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 1) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("mpi_Error_string:TooManyOutputArguments","Too many output arguments for entry-point mpi_Error_string.");
        /* Call the API function. */
        mpi_Error_string_api(prhs, (const mxArray**)outputs);
    }
    else
        mexErrMsgIdAndTxt("mpi_Error_string:WrongNumberOfInputs","Incorrect number of input variables for entry-point mpi_Error_string.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}