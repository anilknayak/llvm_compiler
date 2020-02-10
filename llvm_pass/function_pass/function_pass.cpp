#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
using namespace llvm;

namespace {
  struct InvokeFunctionPass : public FunctionPass {
    static char ID;
    InvokeFunctionPass() : FunctionPass(ID) {}

    virtual bool runOnFunction(Function &F) {
      errs() << "Invoked function called " << F.getName() << "!\n";
      return false;
    }
  };
}

char InvokeFunctionPass::ID = 0;

// Automatically enable the pass.
static void registerInvokeFunctionPass(const PassManagerBuilder &,
                         legacy::PassManagerBase &PM) {
  PM.add(new InvokeFunctionPass());
}
static RegisterStandardPasses
  RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
                 registerInvokeFunctionPass);