//===-------- EdgeBundles.h - Bundles of CFG edges --------------*- c++ -*-===//
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// EdgeBundles.h                                                             //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// Licensed under the MIT license. See COPYRIGHT in the project root for     //
// full license information.                                                 //
//                                                                           //
// The EdgeBundles analysis forms equivalence classes of CFG edges such that all//
// edges leaving a machine basic block are in the same bundle, and all edges //
// leaving a basic block are in the same bundle.                             //
//
///////////////////////////////////////////////////////////////////////////////

#ifndef LLVM_CODEGEN_EDGEBUNDLES_H
#define LLVM_CODEGEN_EDGEBUNDLES_H

#include "llvm/ADT/ArrayRef.h"
#include "llvm/ADT/IntEqClasses.h"
#include "llvm/ADT/Twine.h"
#include "llvm/CodeGen/MachineFunctionPass.h"

namespace llvm {

class EdgeBundles : public MachineFunctionPass {
  const MachineFunction *MF;

  /// EC - Each edge bundle is an equivalence class. The keys are:
  ///   2*BB->getNumber()   -> Ingoing bundle.
  ///   2*BB->getNumber()+1 -> Outgoing bundle.
  IntEqClasses EC;

  /// Blocks - Map each bundle to a list of basic block numbers.
  SmallVector<SmallVector<unsigned, 8>, 4> Blocks;

public:
  static char ID;
  EdgeBundles() : MachineFunctionPass(ID) {}

  /// getBundle - Return the ingoing (Out = false) or outgoing (Out = true)
  /// bundle number for basic block #N
  unsigned getBundle(unsigned N, bool Out) const { return EC[2 * N + Out]; }

  /// getNumBundles - Return the total number of bundles in the CFG.
  unsigned getNumBundles() const { return EC.getNumClasses(); }

  /// getBlocks - Return an array of blocks that are connected to Bundle.
  ArrayRef<unsigned> getBlocks(unsigned Bundle) const { return Blocks[Bundle]; }

  /// getMachineFunction - Return the last machine function computed.
  const MachineFunction *getMachineFunction() const { return MF; }

  /// view - Visualize the annotated bipartite CFG with Graphviz.
  void view() const;

private:
  bool runOnMachineFunction(MachineFunction&) override;
  void getAnalysisUsage(AnalysisUsage&) const override;
};

} // end namespace llvm

#endif
