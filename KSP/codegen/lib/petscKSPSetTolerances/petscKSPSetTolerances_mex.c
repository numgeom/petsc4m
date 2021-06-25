/*
 * KSP/codegen/lib/petscKSPSetTolerances/petscKSPSetTolerances_mex.c
 *
 * Auxiliary code for mexFunction of petscKSPSetTolerances
 *
 * C source code generated by m2c.
 * %#m2c options:f33cc3c8153b0381f012cf0a72a00b92
 *
 */

#include "mex.h"
#if !defined(MATLAB_MEX_FILE) && defined(printf)
#undef printf
#endif
/* Include the C header file generated by codegen in lib mode */
#include "petscKSPSetTolerances.h"
#include "petscKSPSetTolerances_types.h"
#include "m2c.c"

/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"


static void marshallin_const_M2C_OpaqueType(M2C_OpaqueType *pStruct, const mxArray *mx, const char *mname) {
    mxArray             *sub_mx;

    if (!mxIsStruct(mx))
        M2C_error("marshallin_const_M2C_OpaqueType:WrongType",
            "Input argument %s has incorrect data type; struct is expected.", mname);
    if (!mxGetField(mx, 0, "data"))
        M2C_error("marshallin_const_M2C_OpaqueType:WrongType",
            "Input argument %s is missing the field data.", mname);
    if (!mxGetField(mx, 0, "type"))
        M2C_error("marshallin_const_M2C_OpaqueType:WrongType",
            "Input argument %s is missing the field type.", mname);
    if (!mxGetField(mx, 0, "nitems"))
        M2C_error("marshallin_const_M2C_OpaqueType:WrongType",
            "Input argument %s is missing the field nitems.", mname);
    if (mxGetNumberOfFields(mx) > 3)
        M2C_warn("marshallin_const_M2C_OpaqueType:ExtraFields",
            "Extra fields in %s and are ignored.", mname);

    sub_mx = mxGetField(mx, 0, "data");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_M2C_OpaqueType:WrongInputType",
            "Input argument data has incorrect data type; uint8 is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[1] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_M2C_OpaqueType:WrongSizeOfInputArg",
            "Dimension 2 of data should be equal to 1.");
    pStruct->data = (emxArray_uint8_T*)mxMalloc(sizeof(emxArray_uint8_T));
    init_emxArray((emxArray__common*)(pStruct->data), 1);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->data), "data", 1);

    sub_mx = mxGetField(mx, 0, "type");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_M2C_OpaqueType:WrongInputType",
            "Input argument type has incorrect data type; char is expected.");
    if (mxGetNumberOfElements(sub_mx) && mxGetDimensions(sub_mx)[0] != 1) 
        mexErrMsgIdAndTxt("marshallin_const_M2C_OpaqueType:WrongSizeOfInputArg",
            "Dimension 1 of type should be equal to 1.");
    pStruct->type = (emxArray_char_T*)mxMalloc(sizeof(emxArray_char_T));
    init_emxArray((emxArray__common*)(pStruct->type), 2);
    alias_mxArray_to_emxArray(sub_mx, (emxArray__common *)(pStruct->type), "type", 2);

    sub_mx = mxGetField(mx, 0, "nitems");
    if (mxGetNumberOfElements(sub_mx) && mxGetClassID(sub_mx) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("marshallin_const_M2C_OpaqueType:WrongInputType",
            "Input argument nitems has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(sub_mx) != 1)
        mexErrMsgIdAndTxt("marshallin_const_M2C_OpaqueType:WrongSizeOfInputArg",
            "Argument nitems should be a scalar.");
    pStruct->nitems = *(int32_T*)mxGetData(sub_mx);
}
static void destroy_M2C_OpaqueType(M2C_OpaqueType *pStruct) {

    free_emxArray((emxArray__common*)(pStruct->data));
    mxFree(pStruct->data);

    free_emxArray((emxArray__common*)(pStruct->type));
    mxFree(pStruct->type);


}


static void __petscKSPSetTolerances_api(mxArray **plhs, const mxArray ** prhs) {
    M2C_OpaqueType       ksp;
    real32_T             rtol;
    real32_T             abstol;
    real32_T             dtol;
    int32_T              maxits;
    int32_T             *errCode;
    boolean_T           *toplevel;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("petscKSPSetTolerances:WrongInputType",
            "Input argument ksp has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscKSPSetTolerances:WrongSizeOfInputArg",
            "Argument ksp should be a scalar.");
    marshallin_const_M2C_OpaqueType(&ksp, prhs[0], "ksp");

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxSINGLE_CLASS)
        mexErrMsgIdAndTxt("petscKSPSetTolerances:WrongInputType",
            "Input argument rtol has incorrect data type; single is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscKSPSetTolerances:WrongSizeOfInputArg",
            "Argument rtol should be a scalar.");
    rtol = *(real32_T*)mxGetData(prhs[1]);

    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxSINGLE_CLASS)
        mexErrMsgIdAndTxt("petscKSPSetTolerances:WrongInputType",
            "Input argument abstol has incorrect data type; single is expected.");
    if (mxGetNumberOfElements(prhs[2]) != 1)
        mexErrMsgIdAndTxt("petscKSPSetTolerances:WrongSizeOfInputArg",
            "Argument abstol should be a scalar.");
    abstol = *(real32_T*)mxGetData(prhs[2]);

    if (mxGetNumberOfElements(prhs[3]) && mxGetClassID(prhs[3]) != mxSINGLE_CLASS)
        mexErrMsgIdAndTxt("petscKSPSetTolerances:WrongInputType",
            "Input argument dtol has incorrect data type; single is expected.");
    if (mxGetNumberOfElements(prhs[3]) != 1)
        mexErrMsgIdAndTxt("petscKSPSetTolerances:WrongSizeOfInputArg",
            "Argument dtol should be a scalar.");
    dtol = *(real32_T*)mxGetData(prhs[3]);

    if (mxGetNumberOfElements(prhs[4]) && mxGetClassID(prhs[4]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscKSPSetTolerances:WrongInputType",
            "Input argument maxits has incorrect data type; int32 is expected.");
    if (mxGetNumberOfElements(prhs[4]) != 1)
        mexErrMsgIdAndTxt("petscKSPSetTolerances:WrongSizeOfInputArg",
            "Argument maxits should be a scalar.");
    maxits = *(int32_T*)mxGetData(prhs[4]);

    errCode = (int32_T*)mxMalloc(sizeof(int32_T));

    toplevel = (boolean_T*)mxMalloc(sizeof(boolean_T));

    /* Invoke the target function */
    petscKSPSetTolerances(&ksp, rtol, abstol, dtol, maxits, errCode, toplevel);

    /* Deallocate input and marshall out function outputs */
    destroy_M2C_OpaqueType(&ksp);
    /* Nothing to be done for rtol */
    /* Nothing to be done for abstol */
    /* Nothing to be done for dtol */
    /* Nothing to be done for maxits */
    plhs[0] = move_scalar_to_mxArray(errCode, mxINT32_CLASS);
    plhs[1] = move_scalar_to_mxArray(toplevel, mxLOGICAL_CLASS);

}

static void __petscKSPSetTolerances_2args_api(mxArray **plhs, const mxArray ** prhs) {
    M2C_OpaqueType       ksp;
    real32_T             rtol;
    int32_T             *errCode;
    boolean_T           *toplevel;

    /* Marshall in inputs and preallocate outputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxSTRUCT_CLASS)
        mexErrMsgIdAndTxt("petscKSPSetTolerances_2args:WrongInputType",
            "Input argument ksp has incorrect data type; struct is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscKSPSetTolerances_2args:WrongSizeOfInputArg",
            "Argument ksp should be a scalar.");
    marshallin_const_M2C_OpaqueType(&ksp, prhs[0], "ksp");

    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxSINGLE_CLASS)
        mexErrMsgIdAndTxt("petscKSPSetTolerances_2args:WrongInputType",
            "Input argument rtol has incorrect data type; single is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscKSPSetTolerances_2args:WrongSizeOfInputArg",
            "Argument rtol should be a scalar.");
    rtol = *(real32_T*)mxGetData(prhs[1]);

    errCode = (int32_T*)mxMalloc(sizeof(int32_T));

    toplevel = (boolean_T*)mxMalloc(sizeof(boolean_T));

    /* Invoke the target function */
    petscKSPSetTolerances_2args(&ksp, rtol, errCode, toplevel);

    /* Deallocate input and marshall out function outputs */
    destroy_M2C_OpaqueType(&ksp);
    /* Nothing to be done for rtol */
    plhs[0] = move_scalar_to_mxArray(errCode, mxINT32_CLASS);
    plhs[1] = move_scalar_to_mxArray(toplevel, mxLOGICAL_CLASS);

}


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[2] = {NULL, NULL};
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 5) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscKSPSetTolerances:TooManyOutputArguments",
                "Too many output arguments for entry-point petscKSPSetTolerances.\n");
        /* Call the API function. */
        __petscKSPSetTolerances_api(outputs, prhs);
    }
    else if (nrhs == 2) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscKSPSetTolerances_2args:TooManyOutputArguments",
                "Too many output arguments for entry-point petscKSPSetTolerances_2args.\n");
        /* Call the API function. */
        __petscKSPSetTolerances_2args_api(outputs, prhs);
    }
    else
        mexErrMsgIdAndTxt("petscKSPSetTolerances:WrongNumberOfInputs",
            "Incorrect number of input variables for entry-point petscKSPSetTolerances.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}
