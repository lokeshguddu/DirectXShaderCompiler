# Copyright (C) Microsoft Corporation. All rights reserved.
# Licensed under the MIT license. See COPYRIGHT in the project root for full license information.
set(LLVM_LINK_COMPONENTS Support MSSupport) # HLSL Change

add_tablegen(clang-tblgen CLANG
  ClangASTNodesEmitter.cpp
  ClangAttrEmitter.cpp
  ClangCommentCommandInfoEmitter.cpp
  ClangCommentHTMLNamedCharacterReferenceEmitter.cpp
  ClangCommentHTMLTagsEmitter.cpp
  ClangDiagnosticsEmitter.cpp
  ClangSACheckersEmitter.cpp
  NeonEmitter.cpp
  TableGen.cpp
  )
