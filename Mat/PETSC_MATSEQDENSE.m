function val = PETSC_MATSEQDENSE %#codegen
% Obtain PETSC constant MATSEQDENSE

coder.inline('always');

val = petscGetString('MATSEQDENSE');
end
