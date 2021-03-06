# Copyright (C) Microsoft Corporation. All rights reserved.
# Licensed under the MIT license. See COPYRIGHT in the project root for full license information.
add_custom_target(UnitTests)
set_target_properties(UnitTests PROPERTIES FOLDER "Tests")

if (APPLE)
  set(CMAKE_INSTALL_RPATH "@executable_path/../../lib")
else(UNIX)
  set(CMAKE_INSTALL_RPATH "\$ORIGIN/../../lib${LLVM_LIBDIR_SUFFIX}")
endif()

function(add_llvm_unittest test_dirname)
  add_unittest(UnitTests ${test_dirname} ${ARGN})
endfunction()

add_subdirectory(ADT)
add_subdirectory(Analysis)
add_subdirectory(AsmParser)
add_subdirectory(Bitcode)
add_subdirectory(CodeGen)
add_subdirectory(DebugInfo)
# add_subdirectory(ExecutionEngine) - HLSL Change - removed
add_subdirectory(IR)
add_subdirectory(LineEditor)
add_subdirectory(Linker)
add_subdirectory(MC)
add_subdirectory(Option)
add_subdirectory(ProfileData)
add_subdirectory(Support)
add_subdirectory(Transforms)
