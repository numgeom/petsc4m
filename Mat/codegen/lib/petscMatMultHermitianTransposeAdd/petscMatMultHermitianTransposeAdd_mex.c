/*
 * Mat/codegen/lib/petscMatMultHermitianTransposeAdd/petscMatMultHermitianTransposeAdd_mex.c
 *
 * Auxiliary code for mexFunction of petscMatMultHermitianTransposeAdd
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {PetscMat, PetscVec, PetscVec, PetscVec}  enableInline=1 withPetsc=1
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C file generated by codegen in lib mode */
#include "petscMatMultHermitianTransposeAdd.h"
#include "m2c.c"
/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

void petscMatMultHermitianTransposeAdd_api(const mxArray ** prhs, const mxArray **plhs) {

    struct0_T            A;
    struct0_T            v1;
    struct0_T            v2;
    struct0_T            v3;
    mxArray              *_sub_mx1;

    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputType",
            "Input argument A has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:InputStructWrongFields",
            "Input argument A has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongSizeOfInputArg",
            "Argument A must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputStruct",
            "Input argument A does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputType",
            "Input argument A.data has incorrect data type. uint8 is expected.");
    *(void**)&A.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)A.data, "A.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputStruct",
            "Input argument A does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputType",
            "Input argument A.type has incorrect data type. char is expected.");
    *(void**)&A.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)A.type, "A.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputStruct",
            "Input argument A does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputType",
            "Input argument A.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongSizeOfInputArg",
            "Argument A.nitems should be a scalar.");
    A.nitems = *(int32_T*)mxGetData(_sub_mx1);

    if (!mxIsStruct(prhs[1]))
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputType",
            "Input argument v1 has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[1])!=3)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:InputStructWrongFields",
            "Input argument v1 has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongSizeOfInputArg",
            "Argument v1 must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[1], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputStruct",
            "Input argument v1 does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputType",
            "Input argument v1.data has incorrect data type. uint8 is expected.");
    *(void**)&v1.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)v1.data, "v1.data", 1);
    _sub_mx1 = mxGetField(prhs[1], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputStruct",
            "Input argument v1 does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputType",
            "Input argument v1.type has incorrect data type. char is expected.");
    *(void**)&v1.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)v1.type, "v1.type", 2);
    _sub_mx1 = mxGetField(prhs[1], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputStruct",
            "Input argument v1 does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputType",
            "Input argument v1.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongSizeOfInputArg",
            "Argument v1.nitems should be a scalar.");
    v1.nitems = *(int32_T*)mxGetData(_sub_mx1);

    if (!mxIsStruct(prhs[2]))
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputType",
            "Input argument v2 has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[2])!=3)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:InputStructWrongFields",
            "Input argument v2 has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[2]) != 1)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongSizeOfInputArg",
            "Argument v2 must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[2], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputStruct",
            "Input argument v2 does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputType",
            "Input argument v2.data has incorrect data type. uint8 is expected.");
    *(void**)&v2.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)v2.data, "v2.data", 1);
    _sub_mx1 = mxGetField(prhs[2], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputStruct",
            "Input argument v2 does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputType",
            "Input argument v2.type has incorrect data type. char is expected.");
    *(void**)&v2.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)v2.type, "v2.type", 2);
    _sub_mx1 = mxGetField(prhs[2], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputStruct",
            "Input argument v2 does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputType",
            "Input argument v2.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongSizeOfInputArg",
            "Argument v2.nitems should be a scalar.");
    v2.nitems = *(int32_T*)mxGetData(_sub_mx1);

    if (!mxIsStruct(prhs[3]))
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputType",
            "Input argument v3 has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[3])!=3)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:InputStructWrongFields",
            "Input argument v3 has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[3]) != 1)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongSizeOfInputArg",
            "Argument v3 must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[3], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputStruct",
            "Input argument v3 does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputType",
            "Input argument v3.data has incorrect data type. uint8 is expected.");
    *(void**)&v3.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)v3.data, "v3.data", 1);
    _sub_mx1 = mxGetField(prhs[3], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputStruct",
            "Input argument v3 does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputType",
            "Input argument v3.type has incorrect data type. char is expected.");
    *(void**)&v3.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)v3.type, "v3.type", 2);
    _sub_mx1 = mxGetField(prhs[3], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputStruct",
            "Input argument v3 does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongInputType",
            "Input argument v3.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongSizeOfInputArg",
            "Argument v3.nitems should be a scalar.");
    v3.nitems = *(int32_T*)mxGetData(_sub_mx1);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[0], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[1], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscMatMultHermitianTransposeAdd_initialize();

    petscMatMultHermitianTransposeAdd(&A, &v1, &v2, &v3, errCode, toplevel);

    petscMatMultHermitianTransposeAdd_terminate();

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)A.type); mxFree(A.type);
    free_emxArray((emxArray__common*)A.data); mxFree(A.data);

    free_emxArray((emxArray__common*)v1.type); mxFree(v1.type);
    free_emxArray((emxArray__common*)v1.data); mxFree(v1.data);

    free_emxArray((emxArray__common*)v2.type); mxFree(v2.type);
    free_emxArray((emxArray__common*)v2.data); mxFree(v2.data);

    free_emxArray((emxArray__common*)v3.type); mxFree(v3.type);
    free_emxArray((emxArray__common*)v3.data); mxFree(v3.data);

}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[2];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 4) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:TooManyOutputArguments","Too many output arguments for entry-point petscMatMultHermitianTransposeAdd.");
        /* Call the API function. */
        petscMatMultHermitianTransposeAdd_api(prhs, (const mxArray**)outputs);
    }
    else
        mexErrMsgIdAndTxt("petscMatMultHermitianTransposeAdd:WrongNumberOfInputs","Incorrect number of input variables for entry-point petscMatMultHermitianTransposeAdd.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}