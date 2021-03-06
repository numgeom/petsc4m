#ifndef PETSCMATGETINFO_TYPES_H
#define PETSCMATGETINFO_TYPES_H

#include "rtwtypes.h"

#ifndef typedef_PetscMatInfo
#define typedef_PetscMatInfo
typedef struct {
  double block_size;
  double nz_allocated;
  double nz_used;
  double nz_unneeded;
  double memory;
  double assemblies;
  double mallocs;
  double fill_ratio_given;
  double fill_ratio_needed;
  double factor_mallocs;
} PetscMatInfo;
#endif

#ifndef struct_emxArray_uint8_T
#define struct_emxArray_uint8_T
struct emxArray_uint8_T {
  unsigned char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif
#ifndef typedef_emxArray_uint8_T
#define typedef_emxArray_uint8_T
typedef struct emxArray_uint8_T emxArray_uint8_T;
#endif

#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T
struct emxArray_char_T {
  char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif
#ifndef typedef_emxArray_char_T
#define typedef_emxArray_char_T
typedef struct emxArray_char_T emxArray_char_T;
#endif

#ifndef typedef_M2C_OpaqueType
#define typedef_M2C_OpaqueType
typedef struct {
  emxArray_uint8_T *data;
  emxArray_char_T *type;
  int nitems;
} M2C_OpaqueType;
#endif

#endif
