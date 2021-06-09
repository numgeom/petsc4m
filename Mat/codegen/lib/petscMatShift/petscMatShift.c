#include "petscMatShift.h"
#include "petscMatShift_types.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);

static void m2c_error(const emxArray_char_T *varargin_3);

static void b_m2c_error(int varargin_3)
{
  const char *fmt;
  const char *msgid;
  msgid = "petsc:RuntimeError";
  fmt = "petscMatShift returned error code %d\n";
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
  fmt = "Incorrect data type %s. Expected Mat.\n";
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

void petscMatShift(const M2C_OpaqueType *Y, double a, int *errCode,
                   boolean_T *toplevel)
{
  static const char cv[3] = {'M', 'a', 't'};
  Mat mat;
  emxArray_char_T *b_Y;
  int i;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  if (Y->type->size[1] == 3) {
    p = true;
  }
  if (p && (Y->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(Y->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  b_p = (int)p;
  if (!b_p) {
    emxInit_char_T(&b_Y, 2);
    i = b_Y->size[0] * b_Y->size[1];
    b_Y->size[0] = 1;
    b_Y->size[1] = Y->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_Y, i);
    k = Y->type->size[1];
    for (i = 0; i < k; i++) {
      b_Y->data[i] = Y->type->data[i];
    }
    b_Y->data[Y->type->size[1]] = '\x00';
    m2c_error(b_Y);
    emxFree_char_T(&b_Y);
  }
  mat = *(Mat *)(&Y->data->data[0]);
  *errCode = MatShift(mat, a);
  *toplevel = true;
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }
}

void petscMatShift_initialize(void)
{
}

void petscMatShift_terminate(void)
{
}