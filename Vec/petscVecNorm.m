function [nrm, errCode, toplevel] = petscVecNorm(x, type, nrm)
%Computes the vector norm.
%
%  [nrm, errCode, toplevel] = petscVecNorm(x, type) computes the norm of
%     vector x of the given type, where type can be PETSC_NORM_1,
%     PETSC_NORM_2 or PETSC_NORM_INFINITY.
%
%  [nrm, errCode, toplevel] = petscVecNorm(x, type, nrm) allows also
%     use PETSC_NORM_1_AND_2. In this case, nrm must be given as an input
%     of size 2-by-1.
%
%  SEE ALSO: petscMatNorm
%
% PETSc C interface:
%   PetscErrorCode  VecNorm(Vec x,NormType type,PetscReal *val)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecNorm.html

%#codegen -args {PetscVec, int32(0), coder.typeof(0, [2,1])}
%#codegen petscVecNorm_2args -args {PetscVec, int32(0)}

errCode = int32(-1);

if ~coder.target('MATLAB')
    if nargin==2
        nrm = double(0);
    end
    errCode = coder.ceval('VecNorm', PetscVec(x), type, coder.wref(nrm));
    
    toplevel = nargout>2;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecNorm returned error code %d\n', errCode)
    end
end
end
