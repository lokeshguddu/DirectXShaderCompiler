# Copyright (C) Microsoft Corporation. All rights reserved.
# Licensed under the MIT license. See COPYRIGHT in the project root for full license information.
set(LLVM_LINK_COMPONENTS
  Object
  Support
  )

add_llvm_tool(llvm-readobj
  ARMAttributeParser.cpp
  ARMWinEHPrinter.cpp
  COFFDumper.cpp
  ELFDumper.cpp
  Error.cpp
  llvm-readobj.cpp
  MachODumper.cpp
  ObjDumper.cpp
  StreamWriter.cpp
  Win64EHDumper.cpp
  )
