/*
 * Vec/codegen/lib/petscVecNorm/petscVecNorm_mex.c
 *
 * Auxiliary code for mexFunction of petscVecNorm
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {PetscVec, int32(0), coder.typeof(0, [2,1])} petscVecNorm_2args -args {PetscVec, int32(0)}  enableInline=1
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C file generated by codegen in lib mode */
#include "petscVecNorm.h"
#include "m2c.c"
/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

void petscVecNorm_api(const mxArray ** prhs, const mxArray **plhs) {

    struct0_T            x;
    mxArray              *_sub_mx1;

    int32_T              type;
    real64_T             *nrm;
    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscVecNorm:WrongInputType",
            "Input argument x has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscVecNorm:InputStructWrongFields",
            "Input argument x has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscVecNorm:WrongSizeOfInputArg",
            "Argument x must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscVecNorm:WrongInputStruct",
            "Input argument x does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscVecNorm:WrongInputType",
            "Input argument x.data has incorrect data type. uint8 is expected.");
    *(void**)&x.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)x.data, "x.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscVecNorm:WrongInputStruct",
            "Input argument x does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscVecNorm:WrongInputType",
            "Input argument x.type has incorrect data type. char is expected.");
    *(void**)&x.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)x.type, "x.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscVecNorm:WrongInputStruct",
            "Input argument x does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscVecNorm:WrongInputType",
            "Input argument x.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscVecNorm:WrongSizeOfInputArg",
            "Argument x.nitems should be a scalar.");
    x.nitems = *(int32_T*)mxGetData(_sub_mx1);
    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscVecNorm:WrongInputType",
            "Input argument type has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscVecNorm:WrongSizeOfInputArg",
            "Argument type should be a scalar.");
    type = *(int32_T*)mxGetData(prhs[1]);
    plhs[0] = mxDuplicateArray(prhs[2]);
    if (mxGetNumberOfElements(plhs[0]) && mxGetClassID(plhs[0]) != mxDOUBLE_CLASS)
        mexErrMsgIdAndTxt("petscVecNorm:WrongInputType",
            "Input argument nrm has incorrect data type. double is expected.");
    if (mxGetNumberOfElements(plhs[0]) != 2)
        mexErrMsgIdAndTxt("petscVecNorm:WrongSizeOfInputArg",
            "Argument nrm must contain 2 numbers.");
    nrm = (real64_T*)mxGetData(plhs[0]);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[1], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[2], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscVecNorm_initialize();

    petscVecNorm(&x, type, nrm, errCode, toplevel);

    petscVecNorm_terminate();

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */
    /* Nothing to do for plhs[2] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)x.type); mxFree(x.type);
    free_emxArray((emxArray__common*)x.data); mxFree(x.data);

}
void petscVecNorm_2args_api(const mxArray ** prhs, const mxArray **plhs) {

    struct0_T            x;
    mxArray              *_sub_mx1;

    int32_T              type;
    real64_T             *nrm;
    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscVecNorm_2args:WrongInputType",
            "Input argument x has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscVecNorm_2args:InputStructWrongFields",
            "Input argument x has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscVecNorm_2args:WrongSizeOfInputArg",
            "Argument x must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscVecNorm_2args:WrongInputStruct",
            "Input argument x does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscVecNorm_2args:WrongInputType",
            "Input argument x.data has incorrect data type. uint8 is expected.");
    *(void**)&x.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)x.data, "x.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscVecNorm_2args:WrongInputStruct",
            "Input argument x does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscVecNorm_2args:WrongInputType",
            "Input argument x.type has incorrect data type. char is expected.");
    *(void**)&x.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)x.type, "x.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscVecNorm_2args:WrongInputStruct",
            "Input argument x does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscVecNorm_2args:WrongInputType",
            "Input argument x.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscVecNorm_2args:WrongSizeOfInputArg",
            "Argument x.nitems should be a scalar.");
    x.nitems = *(int32_T*)mxGetData(_sub_mx1);
    if (mxGetNumberOfElements(prhs[1]) && mxGetClassID(prhs[1]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscVecNorm_2args:WrongInputType",
            "Input argument type has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscVecNorm_2args:WrongSizeOfInputArg",
            "Argument type should be a scalar.");
    type = *(int32_T*)mxGetData(prhs[1]);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&nrm = prealloc_mxArray((mxArray**)&plhs[0], mxDOUBLE_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[1], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[2], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscVecNorm_initialize();

    petscVecNorm_2args(&x, type, nrm, errCode, toplevel);

    petscVecNorm_terminate();

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */
    /* Nothing to do for plhs[2] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)x.type); mxFree(x.type);
    free_emxArray((emxArray__common*)x.data); mxFree(x.data);

}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[3];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 3) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("petscVecNorm:TooManyOutputArguments","Too many output arguments for entry-point petscVecNorm.");
        /* Call the API function. */
        petscVecNorm_api(prhs, (const mxArray**)outputs);
    }
    else if (nrhs == 2) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("petscVecNorm_2args:TooManyOutputArguments","Too many output arguments for entry-point petscVecNorm_2args.");
        /* Call the API function. */
        petscVecNorm_2args_api(prhs, (const mxArray**)outputs);
    }
    else
        mexErrMsgIdAndTxt("petscVecNorm:WrongNumberOfInputs","Incorrect number of input variables for entry-point petscVecNorm.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}