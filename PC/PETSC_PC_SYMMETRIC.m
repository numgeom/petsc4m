function val = PETSC_PC_SYMMETRIC %#codegen
% Obtain PETSC constant PC_SYMMETRIC

coder.inline('always');

val = petscGetEnum('PC_SYMMETRIC');
end
