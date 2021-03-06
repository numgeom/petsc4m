function [mat_out, errCode, toplevel] = petscMatDuplicate(mat_in, op)
%Duplicates a matrix including the non-zero structure.
%
%  [mat_out, errCode] = petscMatDuplicate(mat_in, op) creates a new matrix,
%  where op can be either PETSC_MAT_DO_NOT_COPY_VALUES or PETSC_MAT_COPY_VALUES, 
%  cause it to copy the numerical values in the matrix PETSC_MAT_SHARE_NONZERO_PATTERN 
%  to share the nonzero patterns with the previous matrix and not copy them.
%
%  SEE ALSO: petscMatCopy, petscMatDestroy, petscMatCreate
%
% PETSc C interface:
%   Duplicates a matrix including the non-zero structure.
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatDuplicate.html

%#codegen -args {PetscMat, int32(0)}

errCode = int32(-1);

if ~isempty(coder.target)
    t_mat_out = coder.opaque('Mat');
    
    errCode = coder.ceval('MatDuplicate', PetscMat(mat_in), op, ...
        coder.wref(t_mat_out));
    
    toplevel = nargout>2;
    mat_out = PetscMat(t_mat_out, toplevel);

    if errCode && (toplevel || m2c_debug)
        m2c_error('Petsc4m:petscMatDuplicate:RuntimeError', 'MatDuplicate returned error code %d\n', errCode)
    end
end
end
