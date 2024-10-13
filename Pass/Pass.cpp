#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Type.h"
#include "llvm/Passes/OptimizationLevel.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"

using namespace llvm;

FunctionType* getLoggerType(LLVMContext &Ctx) {
    PointerType* ArgType = Type::getInt8Ty(Ctx)->getPointerTo();
    return FunctionType::get(Type::getVoidTy(Ctx), ArrayRef<Type *>{ArgType, ArgType}, false);
}

struct MyPass : public PassInfoMixin<MyPass> {
    PreservedAnalyses run(Module &M, ModuleAnalysisManager &AM) {
        LLVMContext& Context = M.getContext();
        FunctionCallee traceFunc = M.getOrInsertFunction("trace", getLoggerType(Context));
        IRBuilder<> builder(Context);

        auto NotLogger = [](const Function &F) {
            return F.getName() != "trace";
        };
        for (auto& F : make_filter_range(M, NotLogger)) {
            for (auto& B : F) {
                for (auto& I : B) {
                    if (I.getOpcodeName() == "phi") {
                        continue;
                    }
                    
                    for (auto& U : I.uses()) {
                        User* user = U.getUser();
                        if (Instruction* userinst = dyn_cast<Instruction>(user)) {
                            builder.SetInsertPoint(&I);
                            Constant *OpcodeName = builder.CreateGlobalStringPtr(I.getOpcodeName());
                            Constant *OpcodeName1 = builder.CreateGlobalStringPtr(userinst->getOpcodeName());
              builder.CreateCall(traceFunc, ArrayRef<Value *>{OpcodeName, OpcodeName1});
                        }
                    }
                }
            }
        }
        return PreservedAnalyses::all();
    }
};


extern "C" LLVM_ATTRIBUTE_WEAK PassPluginLibraryInfo llvmGetPassPluginInfo() {
  const auto callback = [](PassBuilder &PB) {
    PB.registerOptimizerLastEPCallback([&](ModulePassManager &MPM, auto) {
      MPM.addPass(MyPass{});
      return true;
    });
  };

  return {LLVM_PLUGIN_API_VERSION, "MyPlugin", "0.0.1", callback};
}
