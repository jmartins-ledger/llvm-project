cmake -S llvm -B build \
    -G 'Unix Makefiles' \
    -DLLVM_ENABLE_PROJECTS='clang' \
    -DLLVM_ENABLE_RUNTIMES='compiler-rt' \
    -DCMAKE_BUILD_TYPE='Release' \
    -DLLVM_TARGETS_TO_BUILD='X86' || exit

