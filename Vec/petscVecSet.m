function [errCode, toplevel] = petscVecSet(vec, val)
%Sets all components of a vector to a single scalar value.
%
%  errCode = petscVecSet(vec, val)
%
%  SEE ALSO: petscAssembleVec, petscDestroyVec
%
% PETSc C interface:
%   PetscErrorCode  VecSet(Vec x,PetscScalar alpha)
% http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecSet.html

%#codegen -args {PetscVec, PetscScalar(0)}

errCode = int32(-1);

if ~isempty(coder.target)
    t_vec = PetscVec(vec);

    errCode = coder.ceval('VecSet', t_vec, val);

    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('petsc:RuntimeError', 'VecSet returned error code %d\n', errCode)
    end
end
end

function test %#ok<DEFNU>
%!test
%! x = rand(10,1);
%!
%! vec_x = petscVecCreateFromArray(x);
%! errCode = petscVecSet(vec_x, 1);
%!
%! y = petscVecToArray(vec_x);
%! petscVecDestroy(vec_x);
%!
%! assert(errCode == 0 && isequal(y, ones(10,1)));
end
