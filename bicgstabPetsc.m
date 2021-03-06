function varargout = bicgstabPetsc(varargin)
% Solves a sparse system using BiCGStab and a right-preconditioner
%
% Syntax:
%    x = bicgstabPetsc(A, b) solves a sparse linear system using PETSc's BiCGStab
%    solver with a right preconditioner. Matrix A can be in MATLAB's built-in
%    sparse format or in CRS rormat created using crs_matrix. The default 
%    preconditioner is ILU0.
%
%    x = bicgstabPetsc(rowptr, colind, vals, b) takes a matrix in the CRS
%    format instead of MATLAB's built-in sparse format.
%
%    x = bicgstabPetsc(A, b, rtol, maxiter)
%    x = bicgstabPetsc(rowptr, colind, vals, b, rtol, maxiter) 
%    allows you to specify the relative tolerance and the maximum number 
%    of iterations. Their default values are 1.e-5 and 10000, respectively. 
%    Use 0 or [] to preserve default values of rtol and maxiter.
%
%    x = bicgstabPetsc(A, b, rtol, maxiter, x0)
%    x = bicgstabPetsc(rowptr, colind, vals, b, rtol, maxiter, x0)
%    takes an initial solution in x0. Use 0 or [] to preserve the default 
%    initial solution (all zeros).
%
%    x = bicgstabPetsc(A, b, rtol, maxit, x0, pctype, opts)
%    x = bicgstabPetsc(rowptr, colind, vals, b, rtol, maxit, x0, pctype)
%    allows you to specify a preconditioner (such as PETSC_PCHYPRE) and its
%    options in a string (such as '-pc_hypre_boomeramg_coarsen_type HMIS').
%    
%    [x, flag, relres, iter, reshis, times] = bicgstabPetsc(...)
%    returns the solution vector x, the flag (KSPConvergedReason), relative
%    residual, number of iterations, history of residual used in convergence
%    test (typically preconditioned residual), and the execution times in
%    setup and solve.
%
% SEE ALSO: bicgstabHypre, bicgstabPetsc, petscSolveCRS

if nargin==0
    help bicgstabPetsc
    return;
end

if issparse(varargin{1})
    [Arows, Acols, Avals] = crs_matrix(varargin{1});
    next_index = 2;
elseif isstruct(varargin{1})
    Arows = varargin{1}.row_ptr;
    Acols = varargin{1}.col_ind;
    Avals = varargin{1}.val;
    next_index = 2;
else
    Arows = varargin{1};
    Acols = varargin{2};
    Avals = varargin{3};
    next_index = 4;
end

if nargin<next_index
    error('The right hand-side must be specified');
else
    b = varargin{next_index};
end

if nargin >= next_index + 1 && ~isempty(varargin{next_index + 1})
    rtol = varargin{next_index + 1};
else
    rtol = PetscReal(0);
end

if nargin >= next_index + 2 && ~isempty(varargin{next_index + 2})
    maxiter = int32(varargin{next_index + 2});
else
    maxiter = int32(0);
end

if nargin >= next_index + 3 && ~isempty(varargin{next_index + 3})
    x0 = varargin{next_index + 3};
else
    x0 = PetscScalar(zeros(0, 1));
end

if nargin >= next_index + 4 && ~isempty(varargin{next_index + 4})
    pctype = varargin{next_index + 4};
else
    pctype = '';
end

if nargin >= next_index + 5 && ~isempty(varargin{next_index + 5})
    opts = varargin{next_index + 5};
else
    opts = '';
end

[varargout{1:nargout}] = petscSolveCRS(Arows, Acols, PetscScalar(Avals), ...
    PetscScalar(b), PETSC_KSPBCGS, PetscReal(rtol), maxiter, pctype, 'right', PetscScalar(x0), opts);
end

function test %#ok<DEFNU>
%!test
%!shared A, b
%! % system('gd-get -q -O -p 0ByTwsK5_Tl_PemN0QVlYem11Y00 fem2d"*".mat');
%! s = load('fem2d_cd.mat');
%! A = s.A;
%! s = load('fem2d_vec_cd.mat');
%! b = s.b;
%! rtol = 10*eps(class(PetscReal(0))).^(1/2);

%! [x,flag,relres,iter,reshis,times] = bicgstabPetsc(A, b, [], rtol);
%! assert(norm(b - A*double(x)) < rtol * norm(b))

end
