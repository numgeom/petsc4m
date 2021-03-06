#ifndef PETSCMATSETVALUES_H
#define PETSCMATSETVALUES_H

#include "petscMatSetValues_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void petscMatSetValues(const M2C_OpaqueType *mat, int ni,
                              const emxArray_int32_T *ix, int nj,
                              const emxArray_int32_T *jx,
                              const emxArray_real_T *v, int iroa, int *errCode,
                              boolean_T *toplevel);

extern void petscMatSetValues_Insert(const M2C_OpaqueType *mat, int ni,
                                     const emxArray_int32_T *ix, int nj,
                                     const emxArray_int32_T *jx,
                                     const emxArray_real_T *v, int *errCode,
                                     boolean_T *toplevel);

extern void petscMatSetValues_initialize(void);

extern void petscMatSetValues_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
