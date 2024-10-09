#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/raw_ostream.h"
#include <fstream>
using namespace llvm;

struct MyPass : public PassInfoMixin<MyPass> {
  PreservedAnalyses run(Module &M, ModuleAnalysisManager &AM) {
    for (auto& F : M) {
        for (auto& B : F) {
            for (auto& I : B) {
                if (I.getOpcodeName() == "phi") {
                  continue;
                }
                for (auto& U : I.uses()) {
                    User* user = U.getUser();
                    if(Instruction* userinst = cast<Instruction>(user)) {
                      //unsigned opcode = userinst->getOpcode();
                      //std::string opcodeName = inst->getOpcodeName(opcode);
                      outs() << I.getOpcodeName() << " -> " << userinst->getOpcodeName() << "\n";
                    }
                }
            }
        }
    }
    return PreservedAnalyses::all();
  };
};

PassPluginLibraryInfo getPassPluginInfo() {
  const auto callback = [](PassBuilder &PB) {
    PB.registerOptimizerLastEPCallback([&](ModulePassManager &MPM, auto) {
      MPM.addPass(MyPass{});
      return true;
    });
  };

  return {LLVM_PLUGIN_API_VERSION, "MyPlugin", "0.0.1", callback};
};

extern "C" LLVM_ATTRIBUTE_WEAK PassPluginLibraryInfo llvmGetPassPluginInfo() {
  return getPassPluginInfo();
}
