/*
 * KSP/codegen/lib/petscKSPBuildResidual/petscKSPBuildResidual_mex.c
 *
 * Auxiliary code for mexFunction of petscKSPBuildResidual
 *
 * C source code generated by m2c.
 * %#m2c options: codegenArgs=-args {PetscKSP, PetscVec}  enableInline=1 withPetsc=1
 *
 */

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#else
#include "matrix.h"
#endif
/* Include the C file generated by codegen in lib mode */
#include "petscKSPBuildResidual.h"
#include "m2c.c"
/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

void petscKSPBuildResidual_api(const mxArray ** prhs, const mxArray **plhs) {

    struct0_T            ksp;
    struct0_T            v;
    mxArray              *_sub_mx1;

    int32_T              *   errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */

    if (!mxIsStruct(prhs[0]))
        mexErrMsgIdAndTxt("petscKSPBuildResidual:WrongInputType",
            "Input argument ksp has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[0])!=3)
        mexErrMsgIdAndTxt("petscKSPBuildResidual:InputStructWrongFields",
            "Input argument ksp has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscKSPBuildResidual:WrongSizeOfInputArg",
            "Argument ksp must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[0], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPBuildResidual:WrongInputStruct",
            "Input argument ksp does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscKSPBuildResidual:WrongInputType",
            "Input argument ksp.data has incorrect data type. uint8 is expected.");
    *(void**)&ksp.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)ksp.data, "ksp.data", 1);
    _sub_mx1 = mxGetField(prhs[0], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPBuildResidual:WrongInputStruct",
            "Input argument ksp does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscKSPBuildResidual:WrongInputType",
            "Input argument ksp.type has incorrect data type. char is expected.");
    *(void**)&ksp.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)ksp.type, "ksp.type", 2);
    _sub_mx1 = mxGetField(prhs[0], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPBuildResidual:WrongInputStruct",
            "Input argument ksp does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscKSPBuildResidual:WrongInputType",
            "Input argument ksp.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscKSPBuildResidual:WrongSizeOfInputArg",
            "Argument ksp.nitems should be a scalar.");
    ksp.nitems = *(int32_T*)mxGetData(_sub_mx1);

    if (!mxIsStruct(prhs[1]))
        mexErrMsgIdAndTxt("petscKSPBuildResidual:WrongInputType",
            "Input argument v has incorrect data type. struct is expected.");
    if (mxGetNumberOfFields(prhs[1])!=3)
        mexErrMsgIdAndTxt("petscKSPBuildResidual:InputStructWrongFields",
            "Input argument v has incorrect number of fields.");
    if (mxGetNumberOfElements(prhs[1]) != 1)
        mexErrMsgIdAndTxt("petscKSPBuildResidual:WrongSizeOfInputArg",
            "Argument v must contain 1 items.");

    _sub_mx1 = mxGetField(prhs[1], 0, "data");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPBuildResidual:WrongInputStruct",
            "Input argument v does not have the field data.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxUINT8_CLASS)
        mexErrMsgIdAndTxt("petscKSPBuildResidual:WrongInputType",
            "Input argument v.data has incorrect data type. uint8 is expected.");
    *(void**)&v.data = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)v.data, "v.data", 1);
    _sub_mx1 = mxGetField(prhs[1], 0, "type");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPBuildResidual:WrongInputStruct",
            "Input argument v does not have the field type.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxCHAR_CLASS)
        mexErrMsgIdAndTxt("petscKSPBuildResidual:WrongInputType",
            "Input argument v.type has incorrect data type. char is expected.");
    *(void**)&v.type = mxCalloc(1, sizeof(emxArray__common));
    alias_mxArray_to_emxArray(_sub_mx1, (emxArray__common*)v.type, "v.type", 2);
    _sub_mx1 = mxGetField(prhs[1], 0, "nitems");
    if (_sub_mx1==NULL)
        mexErrMsgIdAndTxt("petscKSPBuildResidual:WrongInputStruct",
            "Input argument v does not have the field nitems.");
    if (mxGetNumberOfElements(_sub_mx1) && mxGetClassID(_sub_mx1) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscKSPBuildResidual:WrongInputType",
            "Input argument v.nitems has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(_sub_mx1) != 1)
        mexErrMsgIdAndTxt("petscKSPBuildResidual:WrongSizeOfInputArg",
            "Argument v.nitems should be a scalar.");
    v.nitems = *(int32_T*)mxGetData(_sub_mx1);

    /* Preallocate output variables */
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[0], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[1], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscKSPBuildResidual_initialize();

    petscKSPBuildResidual(&ksp, &v, errCode, toplevel);

    petscKSPBuildResidual_terminate();

    /* Marshall out function outputs */
    /* Nothing to do for plhs[0] */
    /* Nothing to do for plhs[1] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)ksp.type); mxFree(ksp.type);
    free_emxArray((emxArray__common*)ksp.data); mxFree(ksp.data);

    free_emxArray((emxArray__common*)v.type); mxFree(v.type);
    free_emxArray((emxArray__common*)v.data); mxFree(v.data);

}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[2];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 2) {
        if (nlhs > 2)
            mexErrMsgIdAndTxt("petscKSPBuildResidual:TooManyOutputArguments","Too many output arguments for entry-point petscKSPBuildResidual.");
        /* Call the API function. */
        petscKSPBuildResidual_api(prhs, (const mxArray**)outputs);
    }
    else
        mexErrMsgIdAndTxt("petscKSPBuildResidual:WrongNumberOfInputs","Incorrect number of input variables for entry-point petscKSPBuildResidual.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}