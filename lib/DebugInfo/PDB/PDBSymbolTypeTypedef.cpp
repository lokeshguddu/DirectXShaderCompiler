//===- PDBSymbolTypeTypedef.cpp ---------------------------------*- C++ -*-===//
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// PDBSymbolTypeTypedef.cpp                                                  //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// Licensed under the MIT license. See COPYRIGHT in the project root for     //
// full license information.                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "llvm/DebugInfo/PDB/PDBSymbolTypeTypedef.h"

#include "llvm/DebugInfo/PDB/PDBSymDumper.h"

#include <utility>

using namespace llvm;

PDBSymbolTypeTypedef::PDBSymbolTypeTypedef(
    const IPDBSession &PDBSession, std::unique_ptr<IPDBRawSymbol> Symbol)
    : PDBSymbol(PDBSession, std::move(Symbol)) {}

void PDBSymbolTypeTypedef::dump(PDBSymDumper &Dumper) const {
  Dumper.dump(*this);
}
