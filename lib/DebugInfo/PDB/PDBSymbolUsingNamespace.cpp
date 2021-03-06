//===- PDBSymbolUsingNamespace.cpp - ------------------- --------*- C++ -*-===//
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// PDBSymbolUsingNamespace.cpp                                               //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// Licensed under the MIT license. See COPYRIGHT in the project root for     //
// full license information.                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "llvm/DebugInfo/PDB/PDBSymbolUsingNamespace.h"

#include "llvm/DebugInfo/PDB/PDBSymbol.h"
#include "llvm/DebugInfo/PDB/PDBSymDumper.h"

#include <utility>

using namespace llvm;

PDBSymbolUsingNamespace::PDBSymbolUsingNamespace(
    const IPDBSession &PDBSession, std::unique_ptr<IPDBRawSymbol> Symbol)
    : PDBSymbol(PDBSession, std::move(Symbol)) {}

void PDBSymbolUsingNamespace::dump(PDBSymDumper &Dumper) const {
  Dumper.dump(*this);
}
