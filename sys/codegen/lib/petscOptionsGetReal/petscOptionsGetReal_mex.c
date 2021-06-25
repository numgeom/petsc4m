/*
 * sys/codegen/lib/petscOptionsGetReal/petscOptionsGetReal_mex.c
 *
 * Auxiliary code for mexFunction of petscOptionsGetReal
 *
 * C source code generated by m2c.
 * %#m2c options:7cc619a861a838387ac4013cef1fba81
 *
 */

#include "mex.h"
#if !defined(MATLAB_MEX_FILE) && defined(printf)
#undef printf
#endif
/* Include the C header file generated by codegen in lib mode */
#include "petscOptionsGetReal.h"
#include "petscOptionsGetReal_types.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"


static void __petscOptionsGetReal_api(mxArray **plhs, const mxArray ** prhs) {
    emxArray_char_T      pre;
    emxArray_char_T      name;
    real32_T            *value;
    int32_T             *found;
    int32_T             *errCode;
    boolean_T           *toplevel;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscOptionsGetReal:WrongInputType",
            "Input argument pre has incorrect data type; char is expected.");
    if (mxGetNumberOfElements(prhs[0]) && mxGetDimensions(prhs[0])[0] != 1) 
        mexErrMsgIdAndTxt("petscOptionsGetReal:WrongSizeOfInputArg",
            "Dimension 1 of pre should be equal to 1.");
    alias_mxArray_to_emxArray(prhs[0], (emxArray__common *)(&pre), "pre", 2);

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscOptionsGetReal:WrongInputType",
            "Input argument name has incorrect data type; char is expected.");
    if (mxGetNumberOfElements(prhs[1]) && mxGetDimensions(prhs[1])[0] != 1) 
        mexErrMsgIdAndTxt("petscOptionsGetReal:WrongSizeOfInputArg",
            "Dimension 1 of name should be equal to 1.");
    alias_mxArray_to_emxArray(prhs[1], (emxArray__common *)(&name), "name", 2);

    value = (real32_T*)mxMalloc(sizeof(real32_T));

    found = (int32_T*)mxMalloc(sizeof(int32_T));

    errCode = (int32_T*)mxMalloc(sizeof(int32_T));

    toplevel = (boolean_T*)mxMalloc(sizeof(boolean_T));

    /* Invoke the target function */
    petscOptionsGetReal(&pre, &name, value, found, errCode, toplevel);

    /* Deallocate input and marshall out function outputs */
    free_emxArray((emxArray__common*)(&pre));
    free_emxArray((emxArray__common*)(&name));
    plhs[0] = move_scalar_to_mxArray(value, mxSINGLE_CLASS);
    plhs[1] = move_scalar_to_mxArray(found, mxINT32_CLASS);
    plhs[2] = move_scalar_to_mxArray(errCode, mxINT32_CLASS);
    plhs[3] = move_scalar_to_mxArray(toplevel, mxLOGICAL_CLASS);

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[4] = {NULL, NULL, NULL, NULL};
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 2) {
        if (nlhs > 4)
            mexErrMsgIdAndTxt("petscOptionsGetReal:TooManyOutputArguments",
                "Too many output arguments for entry-point petscOptionsGetReal.\n");
        /* Call the API function. */
        __petscOptionsGetReal_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("petscOptionsGetReal:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point petscOptionsGetReal.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}
