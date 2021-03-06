//===-- GCs.h - Garbage collector linkage hacks ---------------------------===//
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// GCs.h                                                                     //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// Licensed under the MIT license. See COPYRIGHT in the project root for     //
// full license information.                                                 //
//                                                                           //
// This file contains hack functions to force linking in the GC components.  //
//
///////////////////////////////////////////////////////////////////////////////

#ifndef LLVM_CODEGEN_GCS_H
#define LLVM_CODEGEN_GCS_H

namespace llvm {
class GCStrategy;
class GCMetadataPrinter;

/// FIXME: Collector instances are not useful on their own. These no longer
///        serve any purpose except to link in the plugins.

/// Creates a CoreCLR-compatible garbage collector.
void linkCoreCLRGC();

/// Creates an ocaml-compatible garbage collector.
void linkOcamlGC();

/// Creates an ocaml-compatible metadata printer.
void linkOcamlGCPrinter();

/// Creates an erlang-compatible garbage collector.
void linkErlangGC();

/// Creates an erlang-compatible metadata printer.
void linkErlangGCPrinter();

/// Creates a shadow stack garbage collector. This collector requires no code
/// generator support.
void linkShadowStackGC();

void linkStatepointExampleGC();
}

#endif
