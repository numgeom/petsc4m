/*
 * KSP/codegen/lib/petscKSPSolve/petscKSPSolve_mex.c
 *
 * Auxiliary code for mexFunction of petscKSPSolve
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {PetscKSP, PetscVec, PetscVec} petscKSPSolve_2args -args {PetscKSP, PetscVec}  enableInline=1 withPetsc=1
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C file generated by codegen in lib mode */
#include "petscKSPSolve.h"
#include "m2c.c"
/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

void petscKSPSolve_api(const mxArray ** prhs, const mxArray **plhs) {

    struct0_T            ksp;
    struct0_T            b;
    struct0_T            x;
    mxArray              *_sub_mx1;

    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscKSPSolve:WrongInputType",
            "Input argument ksp has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscKSPSolve:InputStructWrongFields",
            "Input argument ksp has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongSizeOfInputArg",
            "Argument ksp must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongInputStruct",
            "Input argument ksp does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongInputType",
            "Input argument ksp.data has incorrect data type. uint8 is expected.");
    *(void**)&ksp.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)ksp.data, "ksp.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongInputStruct",
            "Input argument ksp does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongInputType",
            "Input argument ksp.type has incorrect data type. char is expected.");
    *(void**)&ksp.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)ksp.type, "ksp.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongInputStruct",
            "Input argument ksp does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongInputType",
            "Input argument ksp.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongSizeOfInputArg",
            "Argument ksp.nitems should be a scalar.");
    ksp.nitems = *(int32_T*)mxGetData(_sub_mx1);

    if (!mxIsStruct(prhs[1]))
        mexErrMsgIdAndTxt("petscKSPSolve:WrongInputType",
            "Input argument b has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[1])!=3)
        mexErrMsgIdAndTxt("petscKSPSolve:InputStructWrongFields",
            "Input argument b has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongSizeOfInputArg",
            "Argument b must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[1], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongInputStruct",
            "Input argument b does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongInputType",
            "Input argument b.data has incorrect data type. uint8 is expected.");
    *(void**)&b.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)b.data, "b.data", 1);
    _sub_mx1 = mxGetField(prhs[1], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongInputStruct",
            "Input argument b does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongInputType",
            "Input argument b.type has incorrect data type. char is expected.");
    *(void**)&b.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)b.type, "b.type", 2);
    _sub_mx1 = mxGetField(prhs[1], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongInputStruct",
            "Input argument b does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongInputType",
            "Input argument b.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongSizeOfInputArg",
            "Argument b.nitems should be a scalar.");
    b.nitems = *(int32_T*)mxGetData(_sub_mx1);

    if (!mxIsStruct(prhs[2]))
        mexErrMsgIdAndTxt("petscKSPSolve:WrongInputType",
            "Input argument x has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[2])!=3)
        mexErrMsgIdAndTxt("petscKSPSolve:InputStructWrongFields",
            "Input argument x has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[2]) != 1)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongSizeOfInputArg",
            "Argument x must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[2], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongInputStruct",
            "Input argument x does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongInputType",
            "Input argument x.data has incorrect data type. uint8 is expected.");
    *(void**)&x.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)x.data, "x.data", 1);
    _sub_mx1 = mxGetField(prhs[2], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongInputStruct",
            "Input argument x does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongInputType",
            "Input argument x.type has incorrect data type. char is expected.");
    *(void**)&x.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)x.type, "x.type", 2);
    _sub_mx1 = mxGetField(prhs[2], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongInputStruct",
            "Input argument x does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongInputType",
            "Input argument x.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscKSPSolve:WrongSizeOfInputArg",
            "Argument x.nitems should be a scalar.");
    x.nitems = *(int32_T*)mxGetData(_sub_mx1);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[0], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[1], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscKSPSolve_initialize();

    petscKSPSolve(&ksp, &b, &x, errCode, toplevel);

    petscKSPSolve_terminate();

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)ksp.type); mxFree(ksp.type);
    free_emxArray((emxArray__common*)ksp.data); mxFree(ksp.data);

    free_emxArray((emxArray__common*)b.type); mxFree(b.type);
    free_emxArray((emxArray__common*)b.data); mxFree(b.data);

    free_emxArray((emxArray__common*)x.type); mxFree(x.type);
    free_emxArray((emxArray__common*)x.data); mxFree(x.data);

}
void petscKSPSolve_2args_api(const mxArray ** prhs, const mxArray **plhs) {

    struct0_T            ksp;
    struct0_T            b;
    mxArray              *_sub_mx1;

    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscKSPSolve_2args:WrongInputType",
            "Input argument ksp has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscKSPSolve_2args:InputStructWrongFields",
            "Input argument ksp has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscKSPSolve_2args:WrongSizeOfInputArg",
            "Argument ksp must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPSolve_2args:WrongInputStruct",
            "Input argument ksp does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscKSPSolve_2args:WrongInputType",
            "Input argument ksp.data has incorrect data type. uint8 is expected.");
    *(void**)&ksp.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)ksp.data, "ksp.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPSolve_2args:WrongInputStruct",
            "Input argument ksp does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscKSPSolve_2args:WrongInputType",
            "Input argument ksp.type has incorrect data type. char is expected.");
    *(void**)&ksp.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)ksp.type, "ksp.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPSolve_2args:WrongInputStruct",
            "Input argument ksp does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscKSPSolve_2args:WrongInputType",
            "Input argument ksp.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscKSPSolve_2args:WrongSizeOfInputArg",
            "Argument ksp.nitems should be a scalar.");
    ksp.nitems = *(int32_T*)mxGetData(_sub_mx1);

    if (!mxIsStruct(prhs[1]))
        mexErrMsgIdAndTxt("petscKSPSolve_2args:WrongInputType",
            "Input argument b has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[1])!=3)
        mexErrMsgIdAndTxt("petscKSPSolve_2args:InputStructWrongFields",
            "Input argument b has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscKSPSolve_2args:WrongSizeOfInputArg",
            "Argument b must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[1], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPSolve_2args:WrongInputStruct",
            "Input argument b does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscKSPSolve_2args:WrongInputType",
            "Input argument b.data has incorrect data type. uint8 is expected.");
    *(void**)&b.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)b.data, "b.data", 1);
    _sub_mx1 = mxGetField(prhs[1], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPSolve_2args:WrongInputStruct",
            "Input argument b does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscKSPSolve_2args:WrongInputType",
            "Input argument b.type has incorrect data type. char is expected.");
    *(void**)&b.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)b.type, "b.type", 2);
    _sub_mx1 = mxGetField(prhs[1], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPSolve_2args:WrongInputStruct",
            "Input argument b does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscKSPSolve_2args:WrongInputType",
            "Input argument b.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscKSPSolve_2args:WrongSizeOfInputArg",
            "Argument b.nitems should be a scalar.");
    b.nitems = *(int32_T*)mxGetData(_sub_mx1);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[0], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[1], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscKSPSolve_initialize();

    petscKSPSolve_2args(&ksp, &b, errCode, toplevel);

    petscKSPSolve_terminate();

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)ksp.type); mxFree(ksp.type);
    free_emxArray((emxArray__common*)ksp.data); mxFree(ksp.data);

    free_emxArray((emxArray__common*)b.type); mxFree(b.type);
    free_emxArray((emxArray__common*)b.data); mxFree(b.data);

}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[2];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 3) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscKSPSolve:TooManyOutputArguments","Too many output arguments for entry-point petscKSPSolve.");
        /* Call the API function. */
        petscKSPSolve_api(prhs, (const mxArray**)outputs);
    }
    else if (nrhs == 2) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscKSPSolve_2args:TooManyOutputArguments","Too many output arguments for entry-point petscKSPSolve_2args.");
        /* Call the API function. */
        petscKSPSolve_2args_api(prhs, (const mxArray**)outputs);
    }
    else
        mexErrMsgIdAndTxt("petscKSPSolve:WrongNumberOfInputs","Incorrect number of input variables for entry-point petscKSPSolve.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}