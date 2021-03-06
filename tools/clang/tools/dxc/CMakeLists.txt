# Copyright (C) Microsoft Corporation. All rights reserved.
# Licensed under the MIT license. See COPYRIGHT in the project root for full license information.
# Builds dxc.exe

find_package(DiaSDK REQUIRED) # Used for constants and declarations.

set( LLVM_LINK_COMPONENTS
  ${LLVM_TARGETS_TO_BUILD}
  dxcsupport
  HLSL
  Option     # option library
  Support    # just for assert and raw streams
  )

add_clang_executable(dxc
  dxc.cpp
#  dxr.rc
  )

target_link_libraries(dxc
  dxcompiler
  )

set_target_properties(dxc PROPERTIES VERSION ${CLANG_EXECUTABLE_VERSION})

include_directories(AFTER ${DIASDK_INCLUDE_DIRS})

add_dependencies(dxc dxcompiler)

if(UNIX)
  set(CLANGXX_LINK_OR_COPY create_symlink)
# Create a relative symlink
  set(dxc_binary "dxc${CMAKE_EXECUTABLE_SUFFIX}")
else()
  set(CLANGXX_LINK_OR_COPY copy)
  set(dxc_binary "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}/dxc${CMAKE_EXECUTABLE_SUFFIX}")
endif()

install(TARGETS dxc
  RUNTIME DESTINATION bin)

