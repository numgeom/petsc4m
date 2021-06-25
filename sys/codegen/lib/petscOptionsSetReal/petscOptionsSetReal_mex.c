/*
 * sys/codegen/lib/petscOptionsSetReal/petscOptionsSetReal_mex.c
 *
 * Auxiliary code for mexFunction of petscOptionsSetReal
 *
 * C source code generated by m2c.
 * %#m2c options:59884092cc41a89ba47d5bc8834d8255
 *
 */

#include "mex.h"
#if !defined(MATLAB_MEX_FILE) && defined(printf)
#undef printf
#endif
/* Include the C header file generated by codegen in lib mode */
#include "petscOptionsSetReal.h"
#include "petscOptionsSetReal_types.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"


static void __petscOptionsSetReal_api(mxArray **plhs, const mxArray ** prhs) {
    emxArray_char_T      iname;
    real32_T             value;
    int32_T             *errCode;
    boolean_T           *toplevel;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscOptionsSetReal:WrongInputType",
            "Input argument iname has incorrect data type; char is expected.");
    if (mxGetNumberOfElements(prhs[0]) && mxGetDimensions(prhs[0])[0] != 1) 
        mexErrMsgIdAndTxt("petscOptionsSetReal:WrongSizeOfInputArg",
            "Dimension 1 of iname should be equal to 1.");
    alias_mxArray_to_emxArray(prhs[0], (emxArray__common *)(&iname), "iname", 2);

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxSINGLE_CLASS)
        mexErrMsgIdAndTxt("petscOptionsSetReal:WrongInputType",
            "Input argument value has incorrect data type; single is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscOptionsSetReal:WrongSizeOfInputArg",
            "Argument value should be a scalar.");
    value = *(real32_T*)mxGetData(prhs[1]);

    errCode = (int32_T*)mxMalloc(sizeof(int32_T));

    toplevel = (boolean_T*)mxMalloc(sizeof(boolean_T));

    /* Invoke the target function */
    petscOptionsSetReal(&iname, value, errCode, toplevel);

    /* Deallocate input and marshall out function outputs */
    free_emxArray((emxArray__common*)(&iname));
    /* Nothing to be done for value */
    plhs[0] = move_scalar_to_mxArray(errCode, mxINT32_CLASS);
    plhs[1] = move_scalar_to_mxArray(toplevel, mxLOGICAL_CLASS);

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[2] = {NULL, NULL};
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 2) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscOptionsSetReal:TooManyOutputArguments",
                "Too many output arguments for entry-point petscOptionsSetReal.\n");
        /* Call the API function. */
        __petscOptionsSetReal_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("petscOptionsSetReal:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point petscOptionsSetReal.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}
