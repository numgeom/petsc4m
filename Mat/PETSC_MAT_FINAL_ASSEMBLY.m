function val = PETSC_MAT_FINAL_ASSEMBLY %#codegen
% Obtain PETSC constant MAT_FINAL_ASSEMBLY

coder.inline('always');

val = petscGetEnum('MAT_FINAL_ASSEMBLY');
end
