#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
using namespace llvm;

namespace {
  struct MutableFunctionPass : public FunctionPass {
    static char ID;
    MutableFunctionPass() : FunctionPass(ID) {}

    virtual bool runOnFunction(Function &F) {
     for (auto &B : F) {
        for (auto &I : B) {
          if (auto *op = dyn_cast<BinaryOperator>(&I)) {
            // Insert at the point where the instruction `op` appears.
            IRBuilder<> builder(op);

            // Make a multiply with the same operands as `op`.
            Value *lhs = op->getOperand(0);
            Value *rhs = op->getOperand(1);
            Value *mul = builder.CreateMul(lhs, rhs);

            // Everywhere the old instruction was used as an operand, use our
            // new multiply instruction instead.
            // +, -, / everything get overridden with * operation.
            for (auto &U : op->uses()) {
              User *user = U.getUser();  // A User is anything with operands.
              user->setOperand(U.getOperandNo(), mul);
            }

            // We modified the code.
            return true;
          }
        }
      }
      return false;
    }
  };
}

char MutableFunctionPass::ID = 0;

// Automatically enable the pass.
static void registerMutableFunctionPass(const PassManagerBuilder &,
                         legacy::PassManagerBase &PM) {
  PM.add(new MutableFunctionPass());
}
static RegisterStandardPasses
  RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
                 registerMutableFunctionPass);