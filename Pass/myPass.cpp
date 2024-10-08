#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instruction.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
using namespace llvm;

namespace {
    struct MyPass: public FunctionPass {
        static char ID;
        MyPass(): FunctionPass(ID) {}

        virtual bool runOnFunction(Function& F) {
            outs() << F.getName() << "\n";
            /*for(auto& B: F) {
                for(auto& I: B) {
                    outs() << I.getOpcodeName() << "\n"; 
                }
            }*/
            return false;
        }
    };
}


char MyPass::ID = 0;


static void registerMyPass(const PassManagerBuilder &,
                         legacy::PassManagerBase &PM) {
  PM.add(new MyPass());
}
static RegisterStandardPasses
  RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
                 registerMyPass);