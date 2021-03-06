#include "petscPCFactorGetMatrix.h"
#include "petscPCFactorGetMatrix_types.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);

static void m2c_error(const emxArray_char_T *varargin_3);

static void b_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "PCFactorGetMatrix returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  const char *fmt;
  const char *msgid;
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected PC.\n";
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }
  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void petscPCFactorGetMatrix(const M2C_OpaqueType *pc, M2C_OpaqueType *mat,
                            int *errCode, boolean_T *toplevel)
{
  static const char cv[2] = {'P', 'C'};
  Mat arg;
  PC c_pc;
  char *ptr;
  emxArray_char_T *b_pc;
  int i;
  int sizepe;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  if (pc->type->size[1] == 2) {
    p = true;
  }
  if (p && (pc->type->size[1] != 0)) {
    sizepe = 0;
    exitg1 = false;
    while ((!exitg1) && (sizepe < 2)) {
      if (!(pc->type->data[sizepe] == cv[sizepe])) {
        p = false;
        exitg1 = true;
      } else {
        sizepe++;
      }
    }
  }
  b_p = (int)p;
  if (!b_p) {
    emxInit_char_T(&b_pc, 2);
    i = b_pc->size[0] * b_pc->size[1];
    b_pc->size[0] = 1;
    b_pc->size[1] = pc->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_pc, i);
    sizepe = pc->type->size[1];
    for (i = 0; i < sizepe; i++) {
      b_pc->data[i] = pc->type->data[i];
    }
    b_pc->data[pc->type->size[1]] = '\x00';
    m2c_error(b_pc);
    emxFree_char_T(&b_pc);
  }
  c_pc = *(PC *)(&pc->data->data[0]);
  *errCode = PCFactorGetMatrix(c_pc, &arg);
  sizepe = sizeof(Mat);
  i = mat->data->size[0];
  mat->data->size[0] = sizepe;
  emxEnsureCapacity_uint8_T(mat->data, i);
  i = mat->type->size[0] * mat->type->size[1];
  mat->type->size[0] = 1;
  mat->type->size[1] = 3;
  emxEnsureCapacity_char_T(mat->type, i);
  mat->type->data[0] = 'M';
  mat->type->data[1] = 'a';
  mat->type->data[2] = 't';
  mat->nitems = 1;
  ptr = (char *)(&arg);
  for (i = 0; i < sizepe; i++) {
    mat->data->data[i] = *(ptr);
    ptr = ptr + 1;
  }
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
  *toplevel = true;
}

void petscPCFactorGetMatrix_initialize(void)
{
}

void petscPCFactorGetMatrix_terminate(void)
{
}
