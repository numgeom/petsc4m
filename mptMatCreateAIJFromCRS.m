function [mat_out, toplevel] = mptMatCreateAIJFromCRS(row_ptr, col_ind, val, varargin)
% Creates a sparse matrix in PETSc using AIJ format from the CRS arrays format.
%
%    mat = mptMatCreateAIJFromCRS(row_ptr, col_ind, val)
%      creates a PETSc matrix using the default AIJ format. If there is only
%      one processor, it uses the sequential AIJ format. If there are more
%      than one processors, it uses the MPIAIJ format in PETSC_COMM_WORLD.
%
%      row_ptr:   starting pointers for each row (1-based)
%      col_ind:   column indices in each row (1-based)
%      vals:      values in each row
%
%    mat = mptMatCreateAIJFromCRS(row_ptr, col_ind, val, ncols, prefix)
%      ncols:     the global number of columns
%      prefix:    a character string specifics the prefix for the options.
%           If specified and is nonempty, the function will call
%           petscMatSetOptionsPrefix and then petscMatSetFromOptions
%           to set the matrix type. This can be used to created a parallel
%           matrix in PETSC_COMM_WORLD and set the local portion.
%
% SEE ALSO: mptMatAIJToCRS

%#codegen -args {coder.typeof(int32(0), [inf, 1]), coder.typeof(int32(0), [inf, 1]),
%#codegen coder.typeof(0, [inf, 1])} mptMatCreateAIJFromCRS_4args -args
%#codegen {coder.typeof(int32(0), [inf, 1]), coder.typeof(int32(0), [inf, 1]),
%#codegen coder.typeof(0, [inf, 1]), int32(0)} mptMatCreateAIJFromCRS_5args -args
%#codegen {coder.typeof(int32(0), [inf, 1]), coder.typeof(int32(0), [inf, 1]),
%#codegen coder.typeof(0, [inf, 1]), int32(0), coder.typeof(char(0), [1, inf])}

if nargin<3
    error('At least three arguments are required.');
end

n = int32(length(row_ptr)-1);

if nargin<4
    ncols = n;
else
    ncols = int32(varargin{1});
end

% Count the number of nonzeros per row
nnz = coder.nullcopy(zeros(n, 1, 'int32'));
for i=1:n
    nnz(i) = row_ptr(i+1)-row_ptr(i);
end

if nargin<5
    % Create default matrix using petscMatCreateSeqAIJ
    mat = petscMatCreateSeqAIJ(n, ncols, PETSC_DEFAULT, nnz);
    first_row = int32(0);
else
    mat = petscMatCreate;

    if isempty(varargin{2}) || ~varargin{2}(end)
        opts = varargin{2};
    else
        % Null-terminate the string
        opts = [varargin{2} char(0)];
    end
    petscMatSetOptionsPrefix(mat, opts);
    petscMatSetFromOptions(mat);
    petscMatSetSizes(mat, n, PETSC_DECIDE, PETSC_DETERMINE, ncols);
    % Since the matrix is may be parallel,
    first_row = petscMatGetOwnershipRange(mat);
end

% Set values row by row
for i=1:n
    jidx = col_ind(row_ptr(i):row_ptr(i+1)-1)-1;
    rowval = val(row_ptr(i):row_ptr(i+1)-1);
    
    petscMatSetValues(mat, int32(1), i+first_row-1, nnz(i), jidx, rowval);
end

% Call assembly
petscMatAssemblyBegin(mat);
petscMatAssemblyEnd(mat);

toplevel = nargout>1;
mat_out = PetscMat(mat, toplevel);

end

function test %#ok<DEFNU>
%!test
%! A = sprand(100,100,0.3);
%! [rowptr, colind, val] = crs_createFromSparse(A); % This requires NumGeom
%! mat = mptMatCreateAIJFromCRS(rowptr, colind, val);
%! [rowptr2, colind2, val2] = mptMatAIJToCRS(mat);
%! assert(isequal(rowptr, rowptr2) && isequal(colind, colind2) && isequal(val, val2));
end
