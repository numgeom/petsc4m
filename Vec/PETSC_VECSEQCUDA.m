function val = PETSC_VECSEQCUDA %#codegen
% Obtain PETSC constant VECSEQCUDA

coder.inline('always');

val = petscGetString('VECSEQCUDA');
end
