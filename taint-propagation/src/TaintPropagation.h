//===- TaintPropagation.cpp - Propagate taint values -----*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
//===----------------------------------------------------------------------===//
//
// This file implements a transform pass that attaches !taint metadata
// to instructions. For a given instruction, the metadata, if present, indicates
// the set of tainted operands before this instruction executed.
//
//===----------------------------------------------------------------------===//

#ifndef TAINTPROPAGATION_H
#define TAINTPROPAGATION_H

#include "llvm/IR/Module.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Transforms/Utils/UnifyFunctionExitNodes.h"

class TaintPropagationLegacyPass : public llvm::ModulePass {
public:
  using TaintMap =
      llvm::DenseMap<llvm::Instruction *, llvm::SmallVector<llvm::Value *>>;

  static char ID;

  void getAnalysisUsage(llvm::AnalysisUsage &AU) const override {
    // AU.addRequired<llvm::UnifyFunctionExitNodes>();
  }

  TaintPropagationLegacyPass() : ModulePass(ID) {}

  bool runOnModule(llvm::Module &M) override;
  TaintMap getTaintMap() { return TaintData; }

private:
  TaintMap TaintData;
};
#endif // TAINTPROPAGATION_H
