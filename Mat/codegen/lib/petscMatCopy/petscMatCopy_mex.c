/*
 * Mat/codegen/lib/petscMatCopy/petscMatCopy_mex.c
 *
 * Auxiliary code for mexFunction of petscMatCopy
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {PetscMat, PetscMat, int32(0)} petscMatCopy_2args -args {PetscMat, PetscMat}  enableInline=1
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C file generated by codegen in lib mode */
#include "petscMatCopy.h"
#include "m2c.c"
/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

void petscMatCopy_api(const mxArray ** prhs, const mxArray **plhs) {

    struct0_T            A;
    struct0_T            B;
    mxArray              *_sub_mx1;

    int32_T              mstr;
    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscMatCopy:WrongInputType",
            "Input argument A has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscMatCopy:InputStructWrongFields",
            "Input argument A has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscMatCopy:WrongSizeOfInputArg",
            "Argument A must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatCopy:WrongInputStruct",
            "Input argument A does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscMatCopy:WrongInputType",
            "Input argument A.data has incorrect data type. uint8 is expected.");
    *(void**)&A.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)A.data, "A.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatCopy:WrongInputStruct",
            "Input argument A does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscMatCopy:WrongInputType",
            "Input argument A.type has incorrect data type. char is expected.");
    *(void**)&A.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)A.type, "A.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatCopy:WrongInputStruct",
            "Input argument A does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatCopy:WrongInputType",
            "Input argument A.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatCopy:WrongSizeOfInputArg",
            "Argument A.nitems should be a scalar.");
    A.nitems = *(int32_T*)mxGetData(_sub_mx1);

    if (!mxIsStruct(prhs[1]))
        mexErrMsgIdAndTxt("petscMatCopy:WrongInputType",
            "Input argument B has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[1])!=3)
        mexErrMsgIdAndTxt("petscMatCopy:InputStructWrongFields",
            "Input argument B has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscMatCopy:WrongSizeOfInputArg",
            "Argument B must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[1], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatCopy:WrongInputStruct",
            "Input argument B does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscMatCopy:WrongInputType",
            "Input argument B.data has incorrect data type. uint8 is expected.");
    *(void**)&B.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)B.data, "B.data", 1);
    _sub_mx1 = mxGetField(prhs[1], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatCopy:WrongInputStruct",
            "Input argument B does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscMatCopy:WrongInputType",
            "Input argument B.type has incorrect data type. char is expected.");
    *(void**)&B.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)B.type, "B.type", 2);
    _sub_mx1 = mxGetField(prhs[1], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatCopy:WrongInputStruct",
            "Input argument B does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatCopy:WrongInputType",
            "Input argument B.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatCopy:WrongSizeOfInputArg",
            "Argument B.nitems should be a scalar.");
    B.nitems = *(int32_T*)mxGetData(_sub_mx1);
    if (mxGetNumberOfElements(prhs[2]) && mxGetClassID(prhs[2]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatCopy:WrongInputType",
            "Input argument mstr has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(prhs[2]) != 1)
        mexErrMsgIdAndTxt("petscMatCopy:WrongSizeOfInputArg",
            "Argument mstr should be a scalar.");
    mstr = *(int32_T*)mxGetData(prhs[2]);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[0], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[1], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscMatCopy_initialize();

    petscMatCopy(&A, &B, mstr, errCode, toplevel);

    petscMatCopy_terminate();

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)A.type); mxFree(A.type);
    free_emxArray((emxArray__common*)A.data); mxFree(A.data);

    free_emxArray((emxArray__common*)B.type); mxFree(B.type);
    free_emxArray((emxArray__common*)B.data); mxFree(B.data);

}
void petscMatCopy_2args_api(const mxArray ** prhs, const mxArray **plhs) {

    struct0_T            A;
    struct0_T            B;
    mxArray              *_sub_mx1;

    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscMatCopy_2args:WrongInputType",
            "Input argument A has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscMatCopy_2args:InputStructWrongFields",
            "Input argument A has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscMatCopy_2args:WrongSizeOfInputArg",
            "Argument A must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatCopy_2args:WrongInputStruct",
            "Input argument A does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscMatCopy_2args:WrongInputType",
            "Input argument A.data has incorrect data type. uint8 is expected.");
    *(void**)&A.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)A.data, "A.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatCopy_2args:WrongInputStruct",
            "Input argument A does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscMatCopy_2args:WrongInputType",
            "Input argument A.type has incorrect data type. char is expected.");
    *(void**)&A.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)A.type, "A.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatCopy_2args:WrongInputStruct",
            "Input argument A does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatCopy_2args:WrongInputType",
            "Input argument A.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatCopy_2args:WrongSizeOfInputArg",
            "Argument A.nitems should be a scalar.");
    A.nitems = *(int32_T*)mxGetData(_sub_mx1);

    if (!mxIsStruct(prhs[1]))
        mexErrMsgIdAndTxt("petscMatCopy_2args:WrongInputType",
            "Input argument B has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[1])!=3)
        mexErrMsgIdAndTxt("petscMatCopy_2args:InputStructWrongFields",
            "Input argument B has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscMatCopy_2args:WrongSizeOfInputArg",
            "Argument B must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[1], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatCopy_2args:WrongInputStruct",
            "Input argument B does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscMatCopy_2args:WrongInputType",
            "Input argument B.data has incorrect data type. uint8 is expected.");
    *(void**)&B.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)B.data, "B.data", 1);
    _sub_mx1 = mxGetField(prhs[1], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatCopy_2args:WrongInputStruct",
            "Input argument B does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscMatCopy_2args:WrongInputType",
            "Input argument B.type has incorrect data type. char is expected.");
    *(void**)&B.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)B.type, "B.type", 2);
    _sub_mx1 = mxGetField(prhs[1], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatCopy_2args:WrongInputStruct",
            "Input argument B does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatCopy_2args:WrongInputType",
            "Input argument B.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatCopy_2args:WrongSizeOfInputArg",
            "Argument B.nitems should be a scalar.");
    B.nitems = *(int32_T*)mxGetData(_sub_mx1);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[0], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[1], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscMatCopy_initialize();

    petscMatCopy_2args(&A, &B, errCode, toplevel);

    petscMatCopy_terminate();

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)A.type); mxFree(A.type);
    free_emxArray((emxArray__common*)A.data); mxFree(A.data);

    free_emxArray((emxArray__common*)B.type); mxFree(B.type);
    free_emxArray((emxArray__common*)B.data); mxFree(B.data);

}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[2];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 3) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscMatCopy:TooManyOutputArguments","Too many output arguments for entry-point petscMatCopy.");
        /* Call the API function. */
        petscMatCopy_api(prhs, (const mxArray**)outputs);
    }
    else if (nrhs == 2) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscMatCopy_2args:TooManyOutputArguments","Too many output arguments for entry-point petscMatCopy_2args.");
        /* Call the API function. */
        petscMatCopy_2args_api(prhs, (const mxArray**)outputs);
    }
    else
        mexErrMsgIdAndTxt("petscMatCopy:WrongNumberOfInputs","Incorrect number of input variables for entry-point petscMatCopy.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}