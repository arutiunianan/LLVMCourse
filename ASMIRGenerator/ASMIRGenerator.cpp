#include "commands.h"

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

    outs() << "\n#[FILE]:\nBBs:";

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

        outs() << name << "\n";
        name = name.substr(0, name.size()-1);
        BBMap[name] = BasicBlock::Create(context, name, mainFunc);
    }
    input.close();
    input.open(argv[1]);

    Type* voidType = Type::getVoidTy(context);
    Type* int32Type = Type::getInt32Ty(context);



    ArrayRef<Type*> simPutPixelParamTypes = {int32Type, int32Type, int32Type};
    FunctionType* simPutPixelType =
        FunctionType::get(voidType, simPutPixelParamTypes, false);
    FunctionCallee simPutPixelFunc =
        module->getOrInsertFunction("simPutPixel", simPutPixelType);


    FunctionType* simFlushType = FunctionType::get(voidType, {voidType}, false);
    FunctionCallee simFlushFunc =
        module->getOrInsertFunction("simFlush", simFlushType);

    FunctionType* simRandType = FunctionType::get(Type::getInt32Ty(context), {voidType}, false);
    FunctionCallee simRandFunc =
        module->getOrInsertFunction("simRand", simRandType);



    // Funcions types
    FunctionType* voidFuncType = FunctionType::get(voidType, false);
    ArrayRef<Type*> int32x4Types = {Type::getInt32Ty(context),
                                    Type::getInt32Ty(context),
                                    Type::getInt32Ty(context),
                                    Type::getInt32Ty(context)};

    ArrayRef<Type*> int32x3Types = {Type::getInt32Ty(context),
                                    Type::getInt32Ty(context),
                                    Type::getInt32Ty(context)};

    ArrayRef<Type*> int32x2Types = {Type::getInt32Ty(context),
                                    Type::getInt32Ty(context)};
    
    ArrayRef<Type*> int32Types   = {Type::getInt32Ty(context)};

    ArrayRef<Type*> voidTypes    = {Type::getVoidTy(context)};

    FunctionType* int32x4FuncType =
       FunctionType::get(voidType, int32x4Types, false);
    FunctionType* int32x3FuncType =
       FunctionType::get(voidType, int32x3Types, false);
    FunctionType* int32x2FuncType =
        FunctionType::get(voidType, int32x2Types, false);
    FunctionType* int32FuncType =
        FunctionType::get(voidType, int32Types, false);
    


    FunctionCallee do_callsimPutPixelFunc =
        module->getOrInsertFunction("do_callsimPutPixel", int32x3FuncType);

    FunctionCallee do_movFunc =
        module->getOrInsertFunction("do_mov", int32x2FuncType);
    FunctionCallee do_movconstFunc =
        module->getOrInsertFunction("do_movconst", int32x2FuncType);
    FunctionCallee do_andFunc =
        module->getOrInsertFunction("do_and", int32x2FuncType);
    FunctionCallee do_cmpFunc =
        module->getOrInsertFunction("do_cmp", int32x2FuncType);
    FunctionCallee do_shlFunc =
        module->getOrInsertFunction("do_shl", int32x2FuncType);
    FunctionCallee do_addFunc =
        module->getOrInsertFunction("do_add", int32x2FuncType);
    FunctionCallee do_addconstFunc =
        module->getOrInsertFunction("do_addconst", int32x2FuncType);

    FunctionCallee do_callsimRandFunc =
        module->getOrInsertFunction("do_callsimRand", int32FuncType);
    FunctionCallee do_incFunc =
        module->getOrInsertFunction("do_inc", int32FuncType);

    FunctionCallee do_callsimFlushFunc =
        module->getOrInsertFunction("do_callsimFlush", voidFuncType);


    //input >> name;
    while (input >> name) {
        if (!name.compare("mov")) {
            outs() << "\nmov ";
            
            input >> arg;
            Value* arg1 = builder.getInt32(std::stoi(arg.substr(1)));

            input >> arg;
            if (arg[0] == 'R') {
                Value* arg2 = builder.getInt32(std::stoi(arg.substr(1)));
                Value *args[] = {arg1, arg2};
                builder.CreateCall(do_movFunc, args);
            }
            else {
                Value* arg2 = ConstantInt::get(Type::getInt32Ty(context), std::stoi(arg));
                Value *args[] = {arg1, arg2};
                builder.CreateCall(do_movconstFunc, args);
            }
            continue;
        }
        
        if (!name.compare("and")) {
            outs() << "\nand ";

            input >> arg;
            Value* arg1 = builder.getInt32(std::stoi(arg.substr(1)));

            input >> arg;
            Value* arg2 = ConstantInt::get(Type::getInt32Ty(context), std::stoi(arg));

            Value *args[] = {arg1, arg2};
            builder.CreateCall(do_andFunc, args);
            continue;
        }

        if (!name.compare("cmp")) {
            outs() << "\ncmp ";

            input >> arg;
            Value* arg1 = builder.getInt32(std::stoi(arg.substr(1)));

            input >> arg;
            Value* arg2 = ConstantInt::get(Type::getInt32Ty(context), std::stoi(arg));
            
            Value *args[] = {arg1, arg2};
            builder.CreateCall(do_cmpFunc, args);
            continue;
        }

        if (!name.compare("shl")) {
            outs() << "\nshl ";

            input >> arg;
            Value* arg1 = builder.getInt32(std::stoi(arg.substr(1)));

            input >> arg;
            Value* arg2 = ConstantInt::get(Type::getInt32Ty(context), std::stoi(arg));
            
            Value *args[] = {arg1, arg2};
            builder.CreateCall(do_shlFunc, args);
            continue;
        }

        if (!name.compare("add")) {
            outs() << "\nadd ";

            input >> arg;
            Value* arg1 = builder.getInt32(std::stoi(arg.substr(1)));

            input >> arg;
            if (arg[0] == 'R') {
                Value* arg2 = builder.getInt32(std::stoi(arg.substr(1)));
                Value *args[] = {arg1, arg2};
                builder.CreateCall(do_addFunc, args);
            }
            else {
                Value* arg2 = ConstantInt::get(Type::getInt32Ty(context), std::stoi(arg));
                Value *args[] = {arg1, arg2};
                builder.CreateCall(do_addconstFunc, args);
            }
            continue;
        }

        if (!name.compare("call")) {
            outs() << "\ncall ";
            input >> arg;

            if (!arg.compare("simFlush")) {
                builder.CreateCall(do_callsimFlushFunc);
            }
            if (!arg.compare("simRand")) {
                input >> arg;
                Value* arg1 = builder.getInt32(std::stoi(arg.substr(1)));
                Value *args[] = {arg1};
                builder.CreateCall(do_callsimRandFunc, args);
            }
            if (!arg.compare("simPutPixel")) {
                input >> arg;
                Value* arg1 = builder.getInt32(std::stoi(arg.substr(1)));
                
                input >> arg;
                Value* arg2 = builder.getInt32(std::stoi(arg.substr(1)));
                
                input >> arg;
                Value* arg3 = builder.getInt32(std::stoi(arg.substr(1)));
                
                Value *args[] = {arg1, arg2, arg3};
                builder.CreateCall(do_callsimPutPixelFunc, args);
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
            outs() << "\ninc ";

            input >> arg;
            Value* arg1 = builder.getInt32(std::stoi(arg.substr(1)));

            Value *args[] = {arg1};
            builder.CreateCall(do_incFunc, args);
            continue;
        }
    }


    outs() << "\n#[LLVM IR]:\n";
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
/*
    ee->addGlobalMapping(regFile, (void *)REG_FILE);
    ee->finalizeObject();

    simInit();

    ArrayRef<GenericValue> noargs;
    ee->runFunction(mainFunc, noargs);
    outs() << "#[Code was run]\n";

    simExit();
    return EXIT_SUCCESS;*/
}
