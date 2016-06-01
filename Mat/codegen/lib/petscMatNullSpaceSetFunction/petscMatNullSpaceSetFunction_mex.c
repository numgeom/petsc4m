/*
 * Mat/codegen/lib/petscMatNullSpaceSetFunction/petscMatNullSpaceSetFunction_mex.c
 *
 * Auxiliary code for mexFunction of petscMatNullSpaceSetFunction
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {PetscMatNullSpace, PetscMatNullSpaceRemoveFunc, m2c_opaque_ptr}  enableInline=1
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C file generated by codegen in lib mode */
#include "petscMatNullSpaceSetFunction.h"
#include "m2c.c"
/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

void petscMatNullSpaceSetFunction_api(const mxArray ** prhs, const mxArray **plhs) {

    struct0_T            nullSp;
    struct0_T            rmvFunc;
    struct1_T            ctx;
    mxArray              *_sub_mx1;

    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputType",
            "Input argument nullSp has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:InputStructWrongFields",
            "Input argument nullSp has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongSizeOfInputArg",
            "Argument nullSp must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputStruct",
            "Input argument nullSp does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputType",
            "Input argument nullSp.data has incorrect data type. uint8 is expected.");
    *(void**)&nullSp.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)nullSp.data, "nullSp.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputStruct",
            "Input argument nullSp does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputType",
            "Input argument nullSp.type has incorrect data type. char is expected.");
    *(void**)&nullSp.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)nullSp.type, "nullSp.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputStruct",
            "Input argument nullSp does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputType",
            "Input argument nullSp.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongSizeOfInputArg",
            "Argument nullSp.nitems should be a scalar.");
    nullSp.nitems = *(int32_T*)mxGetData(_sub_mx1);

    if (!mxIsStruct(prhs[1]))
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputType",
            "Input argument rmvFunc has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[1])!=3)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:InputStructWrongFields",
            "Input argument rmvFunc has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongSizeOfInputArg",
            "Argument rmvFunc must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[1], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputStruct",
            "Input argument rmvFunc does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputType",
            "Input argument rmvFunc.data has incorrect data type. uint8 is expected.");
    *(void**)&rmvFunc.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)rmvFunc.data, "rmvFunc.data", 1);
    _sub_mx1 = mxGetField(prhs[1], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputStruct",
            "Input argument rmvFunc does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputType",
            "Input argument rmvFunc.type has incorrect data type. char is expected.");
    *(void**)&rmvFunc.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)rmvFunc.type, "rmvFunc.type", 2);
    _sub_mx1 = mxGetField(prhs[1], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputStruct",
            "Input argument rmvFunc does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputType",
            "Input argument rmvFunc.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongSizeOfInputArg",
            "Argument rmvFunc.nitems should be a scalar.");
    rmvFunc.nitems = *(int32_T*)mxGetData(_sub_mx1);

    if (!mxIsStruct(prhs[2]))
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputType",
            "Input argument ctx has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[2])!=4)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:InputStructWrongFields",
            "Input argument ctx has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[2]) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongSizeOfInputArg",
            "Argument ctx must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[2], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputStruct",
            "Input argument ctx does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT64_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputType",
            "Input argument ctx.data has incorrect data type. uint64 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongSizeOfInputArg",
            "Argument ctx.data should be a scalar.");
    ctx.data = *(uint64_T*)mxGetData(_sub_mx1);
    _sub_mx1 = mxGetField(prhs[2], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputStruct",
            "Input argument ctx does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputType",
            "Input argument ctx.type has incorrect data type. char is expected.");
    *(void**)&ctx.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)ctx.type, "ctx.type", 2);
    _sub_mx1 = mxGetField(prhs[2], 0, "nbytes");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputStruct",
            "Input argument ctx does not have the field nbytes.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputType",
            "Input argument ctx.nbytes has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongSizeOfInputArg",
            "Argument ctx.nbytes should be a scalar.");
    ctx.nbytes = *(int32_T*)mxGetData(_sub_mx1);
    _sub_mx1 = mxGetField(prhs[2], 0, "offset");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputStruct",
            "Input argument ctx does not have the field offset.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongInputType",
            "Input argument ctx.offset has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongSizeOfInputArg",
            "Argument ctx.offset should be a scalar.");
    ctx.offset = *(int32_T*)mxGetData(_sub_mx1);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[0], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[1], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscMatNullSpaceSetFunction_initialize();

    petscMatNullSpaceSetFunction(&nullSp, &rmvFunc, &ctx, errCode, toplevel);

    petscMatNullSpaceSetFunction_terminate();

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)nullSp.type); mxFree(nullSp.type);
    free_emxArray((emxArray__common*)nullSp.data); mxFree(nullSp.data);

    free_emxArray((emxArray__common*)rmvFunc.type); mxFree(rmvFunc.type);
    free_emxArray((emxArray__common*)rmvFunc.data); mxFree(rmvFunc.data);

    free_emxArray((emxArray__common*)ctx.type); mxFree(ctx.type);

}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[2];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 3) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:TooManyOutputArguments","Too many output arguments for entry-point petscMatNullSpaceSetFunction.");
        /* Call the API function. */
        petscMatNullSpaceSetFunction_api(prhs, (const mxArray**)outputs);
    }
    else
        mexErrMsgIdAndTxt("petscMatNullSpaceSetFunction:WrongNumberOfInputs","Incorrect number of input variables for entry-point petscMatNullSpaceSetFunction.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}