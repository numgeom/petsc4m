/*
 * Vec/codegen/lib/petscVecCreateSeq/petscVecCreateSeq_mex.c
 *
 * Auxiliary code for mexFunction of petscVecCreateSeq
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
#include "petscVecCreateSeq.h"
#include "m2c.c"
/* Include declaration of some helper functions. */
#include "lib2mex_helper.c"

void petscVecCreateSeq_api(const mxArray ** prhs, const mxArray **plhs) {

    struct0_T            vec;
    mxArray              *_sub_mx1;

    int32_T              n;
    int32_T              *errCode;
    boolean_T            *toplevel;

    /* Marshall in function inputs */
    if (mxGetNumberOfElements(prhs[0]) && mxGetClassID(prhs[0]) != mxINT32_CLASS)
        mexErrMsgIdAndTxt("petscVecCreateSeq:WrongInputType",
            "Input argument n has incorrect data type. int32 is expected.");
    if (mxGetNumberOfElements(prhs[0]) != 1)
        mexErrMsgIdAndTxt("petscVecCreateSeq:WrongSizeOfInputArg",
            "Argument n should be a scalar.");
    n = *(int32_T*)mxGetData(prhs[0]);

    /* Preallocate output variables */
    *(void **)&vec.data = mxCalloc(1, sizeof(emxArray__common));    init_emxArray((emxArray__common*)vec.data, 1);
    *(void **)&vec.type = mxCalloc(1, sizeof(emxArray__common));    init_emxArray((emxArray__common*)vec.type, 2);
    {mwSize l_size[] = {1, 1};
    *(void **)&errCode = prealloc_mxArray((mxArray**)&plhs[1], mxINT32_CLASS, 2, l_size); }
    {mwSize l_size[] = {1, 1};
    *(void **)&toplevel = prealloc_mxArray((mxArray**)&plhs[2], mxLOGICAL_CLASS, 2, l_size); }

    /* Invoke the target function */
    petscVecCreateSeq_initialize();

    petscVecCreateSeq(n, &vec, errCode, toplevel);

    petscVecCreateSeq_terminate();

    /* Marshall out function outputs */
    {const char *_fields[] = { "data", "type", "nitems",  ""};
    int32_T _one=1;
    plhs[0] = create_struct_mxArray(1, &_one, 3, _fields);}
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 0, move_emxArray_to_mxArray((emxArray__common*)vec.data, mxUINT8_CLASS));
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 1, move_emxArray_to_mxArray((emxArray__common*)vec.type, mxCHAR_CLASS));
    mxSetFieldByNumber((mxArray*)(plhs[0]), 0, 2, copy_scalar_to_mxArray(&vec.nitems, mxINT32_CLASS));
    /* Nothing to do for plhs[1] */
    /* Nothing to do for plhs[2] */

    /* Free temporary variables */
    free_emxArray((emxArray__common*)vec.type); mxFree(vec.type);
    free_emxArray((emxArray__common*)vec.data); mxFree(vec.data);

}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Temporary copy for mex outputs. */
    mxArray *outputs[3];
    int i;
    int nOutputs = (nlhs < 1 ? 1 : nlhs);

    if (nrhs == 1) {
        if (nlhs > 3)
            mexErrMsgIdAndTxt("petscVecCreateSeq:TooManyOutputArguments","Too many output arguments for entry-point petscVecCreateSeq.");
        /* Call the API function. */
        petscVecCreateSeq_api(prhs, (const mxArray**)outputs);
    }
    else
        mexErrMsgIdAndTxt("petscVecCreateSeq:WrongNumberOfInputs","Incorrect number of input variables for entry-point petscVecCreateSeq.");

    /* Copy over outputs to the caller. */
    for (i = 0; i < nOutputs; ++i) {
        plhs[i] = outputs[i];
    }
}