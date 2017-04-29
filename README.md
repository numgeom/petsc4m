OVERVIEW
========

MPETSc is a MATLAB Interface for PETSc. It is m2c-compatible, which
means that it can be converted into C codes and also be compiled into
MEX functions or standalone applications using the M2C code suite and
MATLAB Coder.

MPETSc is flexible and easy to use. It offers one top-most function,
mptSolveCRS, and 9 other top-level functions. These functions support
accessing iterative solvers in PETSc directly from MATLAB without much
coding and the flexibility to control PETSc using options.  MPETSc
also offers about 150 low-level PETSc API functions, so that you can
also directly program in MATLAB using the PETSc API for prototyping
new algorithms. It depends on MMPI for some basic MPI calls.

The high-level MPETSc functions support two matrix formats: Sequential
AIJ and MPI AIJ. These formats tend to deliver good performance and
offer good inseparability with MATLAB. Other matrix formats, such as
dense and MPI Block AIJ, are accessible through the low-level
functions.

MPETSc supports Linux and Mac OS X. Microsoft Windows is currently not
supported (to be added).

NAMING AND NUMBERING CONVENTIONS
================================

Top-Level Functions
-----------------------

The top-level functions in MPETSc have the prefix mpt, and are all in
the MPETSc root directory. The array indices of top-level functions
are 1-based.  The character strings for the top-level functions do not
need to be null- terminated. These are consistent with the convention
of MATLAB.

For most users, mptSolveCRS is the only function one needs to use.

The following is an example code:
   % Set up a test matrix
   A = sprand(100,100,0.3);
   A = A + speye(100);
   [rowptr, colind, val] = crs_matrix(A); % This requires MSPACK
   b = rand(100,1);

   % Solve using default KSP solver and preconditioner
   [x,flag,relres,reshis,iter] = mptSolveCRS(rowptr, colind, val, b);

   % Solve using GMRES with Jacobi preconditioner with default options
   [x,flag,relres,iter,reshis] = mptSolveCRS(rowptr, colind, val, b, PETSC_KSPGMRES, ...
        0, int32(0), PETSC_PCJACOBI, 'right');

   % Solve using BiCGSTAB with Jacobi preconditioner as right preconditioner 
   % with relative tolerance 1.e-10 and a maximum of 100 iterations
   [x,flag,relres,iter,reshis] = mptSolveCRS(rowptr, colind, val, b, ...
        PETSC_KSPBCGS, 1.e-10, int32(100), PETSC_PCJACOBI, 'right');

   % Solve using SuperLU (assuming SuperLU was installed)
   [x,flag,relres,iter,reshis] = mptSolveCRS(rowptr, colind, val, b, ...
        PETSC_KSPPREONLY, 0, int32(0), PETSC_PCLU, PETSC_MATSOLVERSUPERLU);

When you start MATLAB with JVM enabled, mptSolveCRS will be compiled
into a standalone executable, and data exchange with MATLAB is done
through files. This helps to prevent your MATLAB session from crashing
due to  errors in PETSc. When JVM is disabled in MATLAB (i.e., when you
start MATLAB with the -nojvm option), then mptSolveCRS will call the
compiled mex files of the other high-level functions, and all the data
are passed in memory. This is useful for "product runs." In
both cases, petscInit and petscFinalize are called automatically, so
you do not need to call them manually.

The top-level functions use the low-level PETSc function along with
basic MATLAB features. These functions can be compiled into MEX
functions by themselves or be used in other M2C-compatible codes.

Low-Level Functions
-----------------------

The low-level functions in MPETSc allow accessing virtually all features
of PETSc in MATLAB. The indices for all low-level functions are 0-based,
and all the strings must be null-terminated.

There are three types of low-level functions in MPETSc. 
  * PETSc Functions: All functions have prefix petsc, such as petscMatCreate.
  * PETSc Constants: All constants have prefix PETSC_, such as PETSC_COMM_WORLD.
  * PETSc Data Types: All data types in MPETSc have prefix Petsc, such as 
         PetscMat, PetscVec, PetscKSP, etc. 

The first two types are useful for all users. These functions aid code
generation, so end-users typically do not need to access them in programming.
In particular, when specifying KSPType, PCType, MatType, VecType, etc.,
it is the best to use the constants defined by MPETSc instead of using 
character strings directly. These constants have the prefix PETSC_KSP, 
PETSC_PC, PETSC_MAT, and PETSC_VEC respectively. These names are all 
null-terminated strings, so you do not need to worry about null-terminating
them manually.

The functions for Mat, Vec, KSP, and PC are all located in the sub-directory
Mat/, Vec/, KSP/, and PC/, respectively. Most of these functions do not need to be 
used directly, except for the APIs for creating and destroying them. The other
functions are helpful for prototyping new algorithms or experimenting with
different matrix formats in PETSc.

The functions related to initialization, finalization, and options are in 
the sys/ subdirectory. 

Basic MPI Functions
-------------------

MPETSc uses a few basic MPI functions in the MMPI module, including

   mpi_Init mpi_Initialized 
   mpi_Comm_size mpi_Comm_rank 
   mpi_Finalize mpi_Finalized

Additional MPI features are available in MMPI.

LIMITATIONS
===========

Currently, when running MPETSc-based codes within MATLAB, you must disable
JVM by starting MATLAB using the command "matlab -nojvm". This is because 
PETSc's memory management seems to conflict with those of JVM and cause 
errors. (This may be fixed in the future by setting PETSc's error handler.)
For best practice, start one MATLAB session with JVM and Desktop enabled for
code development, and start another MATLAB session for running the code.

MPETSc does not support KSPRegister and PCRegister. You need to implement
these functions directly in C.