#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"

#include <fstream>
#include <iostream>

#include "new_app/sim.h"

using namespace llvm;

const int REG_FILE_SIZE = 30;
int REG_FILE[REG_FILE_SIZE] = {0};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        outs() << "[ERROR] Need 1 argument: file with assembler code\n";
        return 1;
    }
    std::ifstream input;
    input.open(argv[1]);
    if (!input.is_open()) {
        outs() << "[ERROR] Can't open " << argv[1] << "\n";
        return 1;
    }

    LLVMContext context;
    // ; ModuleID = 'top'
    // source_filename = "top"
    Module* module = new Module("top", context);
    IRBuilder<> builder(context);


    //[32 x i32] regFile = {0, 0, 0, 0}
    ArrayType* regFileType = ArrayType::get(builder.getInt32Ty(), REG_FILE_SIZE);
    module->getOrInsertGlobal("regFile", regFileType);
    GlobalVariable* regFile = module->getNamedGlobal("regFile");


    // declare void @main()
    FunctionType* funcType = FunctionType::get(builder.getVoidTy(), false);
    Function* mainFunc =
        Function::Create(funcType, Function::ExternalLinkage, "main", module);

    std::string name;
    std::string arg, arg1, arg2, arg3, arg4;
    std::unordered_map<std::string, BasicBlock *> BBMap;

    Type* voidType = Type::getVoidTy(context);
    Type* int32Type = Type::getInt32Ty(context);

    // declare void @simPutPixel(i32 noundef, i32 noundef, i32 noundef)
    ArrayRef<Type*> simPutPixelParamTypes = {int32Type, int32Type, int32Type};
    FunctionType* simPutPixelType =
        FunctionType::get(voidType, simPutPixelParamTypes, false);
    FunctionCallee simPutPixelFunc =
        module->getOrInsertFunction("simPutPixel", simPutPixelType);

    // declare void @simFlush(...)
    FunctionType* simFlushType = FunctionType::get(voidType, false);
    FunctionCallee simFlushFunc =
        module->getOrInsertFunction("simFlush", simFlushType);

    FunctionType* simRandType = FunctionType::get(Type::getInt32Ty(context), {voidType}, false);
    FunctionCallee simRandFunc =
        module->getOrInsertFunction("simRand", simRandType);


    while (input >> name) {
        if (!name.compare("call")) {
            input >> arg;
            if(!arg.compare("simPutPixel")) {
                input >> arg >> arg >> arg;
            }
            if(!arg.compare("simRand")) {
                input >> arg;
            }
            continue;
        }
        if (!name.compare("mov") || !name.compare("and") || 
            !name.compare("cmp") || !name.compare("shl") ||
            !name.compare("add")) {
            input >> arg >> arg;
            continue;
        }
        if (!name.compare("jmp") || !name.compare("inc") ||
            !name.compare("je")  || !name.compare("jne")) {
            input  >> arg;
            continue;
        }

        name = name.substr(0, name.size()-1);
        BBMap[name] = BasicBlock::Create(context, name, mainFunc);
    }
    input.close();
    input.open(argv[1]);

    while (input >> name) {
        if (!name.compare("mov")) {
            
            input >> arg;
            Value* arg1 = builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                     std::stoi(arg.substr(1)));
            

            input >> arg;
            if (arg[0] == 'R') {
                Value* arg2 = builder.CreateLoad(int32Type, 
                                                 builder.CreateConstGEP2_32(regFileType, 
                                                                            regFile, 0,
                                                 std::stoi(arg.substr(1))));
                builder.CreateStore(arg2, arg1);
            }
            else {
                Value* arg2 = ConstantInt::get(Type::getInt32Ty(context), std::stoi(arg));
                builder.CreateStore(arg2, arg1);
            }
            continue;
        }
        
        if (!name.compare("and")) {

            input >> arg;
            Value* arg1 = builder.CreateLoad(int32Type, 
                                             builder.CreateConstGEP2_32(regFileType, 
                                                                        regFile, 0,
                                             std::stoi(arg.substr(1))));
            std::string args;
            input >> args;
            Value* arg2 = ConstantInt::get(Type::getInt32Ty(context), std::stoi(args));

            Value* arg3 = builder.CreateAnd(arg1, arg2);

            Value* arg4 = builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                std::stoi(arg.substr(1)));

            builder.CreateStore(arg3, arg4);
            continue;
        }

        if (!name.compare("cmp")) {

            input >> arg;
            Value* arg1 = builder.CreateLoad(int32Type, 
                                             builder.CreateConstGEP2_32(regFileType, 
                                                                        regFile, 0,
                                             std::stoi(arg.substr(1))));

            input >> arg;
            Value* arg2 = ConstantInt::get(Type::getInt32Ty(context), std::stoi(arg));

            Value* arg3 = builder.CreateICmpEQ(arg1, arg2);

            Value* arg4 = builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                     REG_FILE_SIZE - 1);

            builder.CreateStore(arg3, arg4);
            continue;
        }

        if (!name.compare("shl")) {

            input >> arg;
            Value* arg1 = builder.CreateLoad(int32Type, 
                                             builder.CreateConstGEP2_32(regFileType, 
                                                                        regFile, 0,
                                             std::stoi(arg.substr(1))));

            std::string args;
            input >> args;
            Value* arg2 = ConstantInt::get(Type::getInt32Ty(context), std::stoi(args));
            
            Value* arg3 = builder.CreateShl(arg1, arg2);

            Value* arg4 = builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                     std::stoi(arg.substr(1)));

            builder.CreateStore(arg3, arg4);
            continue;
        }

        if (!name.compare("add")) {

            input >> arg;
            Value* arg1 = builder.CreateLoad(int32Type, 
                                             builder.CreateConstGEP2_32(regFileType, 
                                                                        regFile, 0,
                                             std::stoi(arg.substr(1))));

            std::string args;
            input >> args;
            if (arg[0] == 'R') {
                Value* arg2 = builder.CreateLoad(int32Type, 
                                                 builder.CreateConstGEP2_32(regFileType, 
                                                                            regFile, 0,
                                                 std::stoi(args.substr(1))));

                Value* arg3 = builder.CreateAdd(arg1, arg2);

                Value* arg4 = builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                         std::stoi(arg.substr(1)));
                builder.CreateStore(arg3, arg4);
            }
            else {
                Value* arg2 = ConstantInt::get(Type::getInt32Ty(context), std::stoi(args));

                Value* arg3 = builder.CreateAdd(arg1, arg2);

                Value* arg4 = builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                         std::stoi(arg.substr(1)));
                builder.CreateStore(arg3, arg4);
            }
            continue;
        }

        if (!name.compare("call")) {

            input >> arg;

            if (!arg.compare("simFlush")) {
                builder.CreateCall(simFlushFunc);
            }
            if (!arg.compare("simRand")) {
                input >> arg;
                Value* arg1 = builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                         std::stoi(arg.substr(1)));
                
                Value* arg2 = builder.CreateCall(simRandFunc, {});
                builder.CreateStore(arg2, arg1);
            }
            if (!arg.compare("simPutPixel")) {
                input >> arg;
                Value* arg1 = builder.CreateLoad(int32Type, 
                                                 builder.CreateConstGEP2_32(regFileType, 
                                                                            regFile, 0,
                                                 std::stoi(arg.substr(1))));
                
                input >> arg;
                Value* arg2 = builder.CreateLoad(int32Type, 
                                                 builder.CreateConstGEP2_32(regFileType, 
                                                                            regFile, 0,
                                                 std::stoi(arg.substr(1))));
                
                input >> arg;
                Value* arg3 = builder.CreateLoad(int32Type, 
                                                 builder.CreateConstGEP2_32(regFileType, 
                                                                            regFile, 0,
                                                 std::stoi(arg.substr(1))));
                
                builder.CreateCall(simPutPixelFunc, {arg1, arg2, arg3});
            }
            continue;
        }

        if (!name.compare("je")) {
            input >> arg1 >> arg2;

            Value *reg_p = builder.CreateConstGEP2_32(regFileType, regFile, 
                                                      0, REG_FILE_SIZE - 1);
            Value *reg_i1 = builder.CreateTrunc(builder.CreateLoad(int32Type, 
                                                                   reg_p),
                                                builder.getInt1Ty());
            std::string label = arg2.substr(0, arg2.size()-1);
            builder.CreateCondBr(reg_i1, BBMap[arg1], BBMap[label]);
            builder.SetInsertPoint(BBMap[label]);

            continue;
        }

        if (!name.compare("jne")) {
            input >> arg1 >> arg2;

            Value *reg_p = builder.CreateConstGEP2_32(regFileType, regFile, 
                                                      0, REG_FILE_SIZE - 1);
            Value *reg_i1 = builder.CreateTrunc(builder.CreateLoad(int32Type, 
                                                                   reg_p),
                                                builder.getInt1Ty());
            std::string label = arg2.substr(0, arg2.size()-1);
            builder.CreateCondBr(reg_i1, BBMap[label], BBMap[arg1]);
            builder.SetInsertPoint(BBMap[label]);

            continue;
        }

        if (!name.compare("jmp")) {
            input >> arg1;

            builder.CreateBr(BBMap[arg1]);
            builder.SetInsertPoint(BBMap[arg1]);

            continue;
        }

        if (!name.compare("inc")) {

            input >> arg;
            Value* arg1 = builder.CreateLoad(int32Type, 
                                             builder.CreateConstGEP2_32(regFileType, 
                                                                        regFile, 0,
                                             std::stoi(arg.substr(1))));

            Value* arg2 = ConstantInt::get(Type::getInt32Ty(context), 1);
                
            Value* arg3 = builder.CreateAdd(arg1, arg2);

            Value* arg4 = builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                     std::stoi(arg.substr(1)));
            builder.CreateStore(arg3, arg4);
            continue;
        }

        name = name.substr(0, name.size()-1);
        builder.SetInsertPoint(BBMap[name]);
    }


    module->print(outs(), nullptr);
    outs() << "\n";
    bool verif = verifyFunction(*mainFunc, &outs());
    outs() << "[VERIFICATION] " << (!verif ? "OK\n\n" : "FAIL\n\n");

    outs() << "\n#[Running code]\n";
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();

    ExecutionEngine *ee = EngineBuilder(std::unique_ptr<Module>(module)).create();
    ee->InstallLazyFunctionCreator([=](const std::string &fnName) -> void * {
    if (fnName == "simFlush") {
      return reinterpret_cast<void *>(simFlush);
    }
    if (fnName == "simPutPixel") {
      return reinterpret_cast<void *>(simPutPixel);
    }
    if (fnName == "simRand") {
      return reinterpret_cast<void *>(simRand);
    }
    return nullptr;
    });

    ee->addGlobalMapping(regFile, (void *)REG_FILE);
    ee->finalizeObject();

    simInit();

    ArrayRef<GenericValue> noargs;
    ee->runFunction(mainFunc, noargs);
    outs() << "#[Code was run]\n";

    simExit();
    return EXIT_SUCCESS;
}
