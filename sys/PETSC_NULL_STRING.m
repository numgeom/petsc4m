function obj = PETSC_NULL_STRING %#codegen
% Obtain PETSC constant NULL of type char *

coder.inline('always');

obj = petscGetString('PETSC_NULL_STRING');
end
