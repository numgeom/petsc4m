#include "petscMatGetRow.h"
#include "m2c.h"
#include "petsc4m.h"

static void b_m2c_error(int varargin_3);
static void c_m2c_error(int varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "MatGetRow returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void c_m2c_error(int varargin_3)
{
  const char * msgid;
  const char * fmt;
  msgid = "petsc:RuntimeError";
  fmt = "MatRestoreRow returned error code %d\n";
  M2C_error(msgid, fmt, varargin_3);
}

static void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_uint8_T(&pStruct->data);
  emxFree_char_T(&pStruct->type);
}

static void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  emxInit_uint8_T(&pStruct->data, 1);
  emxInit_char_T(&pStruct->type, 2);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  const char * msgid;
  const char * fmt;
  int i1;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  msgid = "m2c_opaque_obj:WrongInput";
  fmt = "Incorrect data type %s. Expected Mat.\n";
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error(msgid, fmt, &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInitArray_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxInit_int32_T(pEmxArray, numDimensions);
}

void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxInit_real_T(pEmxArray, numDimensions);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

void petscMatGetRow(const struct0_T *mat, int row, int *ncols, emxArray_int32_T *
                    cols, emxArray_real_T *vals, int *errCode, boolean_T
                    *toplevel)
{
  boolean_T p;
  boolean_T b_p;
  int t_ncols;
  int exitg2;
  boolean_T exitg1;
  emxArray_char_T *b_mat;
  static const char cv0[3] = { 'M', 'a', 't' };

  emxArray_uint8_T *data;
  int i0;
  Mat t_mat;
  const int * t_cols;
  const double * t_vals;
  p = false;
  b_p = false;
  t_ncols = 0;
  do {
    exitg2 = 0;
    if (t_ncols < 2) {
      if (mat->type->size[t_ncols] != 1 + (t_ncols << 1)) {
        exitg2 = 1;
      } else {
        t_ncols++;
      }
    } else {
      b_p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (b_p && (!(mat->type->size[1] == 0))) {
    t_ncols = 0;
    exitg1 = false;
    while ((!exitg1) && (t_ncols < 3)) {
      if (!(mat->type->data[t_ncols] == cv0[t_ncols])) {
        b_p = false;
        exitg1 = true;
      } else {
        t_ncols++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_mat, 2);
    i0 = b_mat->size[0] * b_mat->size[1];
    b_mat->size[0] = 1;
    b_mat->size[1] = mat->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_mat, i0, (int)sizeof(char));
    t_ncols = mat->type->size[1];
    for (i0 = 0; i0 < t_ncols; i0++) {
      b_mat->data[b_mat->size[0] * i0] = mat->type->data[mat->type->size[0] * i0];
    }

    b_mat->data[b_mat->size[0] * mat->type->size[1]] = '\x00';
    m2c_error(b_mat);
    emxFree_char_T(&b_mat);
  }

  emxInit_uint8_T(&data, 1);
  i0 = data->size[0];
  data->size[0] = mat->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  t_ncols = mat->data->size[0];
  for (i0 = 0; i0 < t_ncols; i0++) {
    data->data[i0] = mat->data->data[i0];
  }

  t_mat = *(Mat*)(&data->data[0]);
  t_ncols = 0;
  *errCode = MatGetRow(t_mat, row, &t_ncols, &t_cols, &t_vals);
  *toplevel = true;
  emxFree_uint8_T(&data);
  if (*errCode != 0) {
    b_m2c_error(*errCode);
  }

  *ncols = t_ncols;
  i0 = cols->size[0];
  cols->size[0] = t_ncols;
  emxEnsureCapacity((emxArray__common *)cols, i0, (int)sizeof(int));
  i0 = vals->size[0];
  vals->size[0] = t_ncols;
  emxEnsureCapacity((emxArray__common *)vals, i0, (int)sizeof(double));
  memcpy(&cols->data[0], t_cols, t_ncols << 2);
  memcpy(&vals->data[0], t_vals, t_ncols << 3);
  *errCode = MatRestoreRow(t_mat, row, &t_ncols, &t_cols, &t_vals);
  if (*errCode != 0) {
    c_m2c_error(*errCode);
  }
}

void petscMatGetRow_initialize(void)
{
}

void petscMatGetRow_terminate(void)
{
}
