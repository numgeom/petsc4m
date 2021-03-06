function [vec, errCode, toplevel] = petscVecDestroy(vec)
%Frees space taken by a vector.
%
%  [vec, errCode] = petscVecDestroy(vec)
%
%  SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleVec,
%
% PETSc C interface:
%   PetscErrorCode VecDestroy(Vec *A)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDestroy.html

%#codegen -args {PetscVec}

errCode = int32(-1);

if ~isempty(coder.target)
    t_vec = PetscVec(vec);
    
    errCode = coder.ceval('VecDestroy', coder.ref(t_vec));
    
    toplevel = nargout>2;
    vec = PetscVec(t_vec, toplevel);

    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecDestroy returned error code %d\n', errCode)
    end
end
end
