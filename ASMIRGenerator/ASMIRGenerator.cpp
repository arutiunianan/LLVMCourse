#include "../GameOfLife/sim.h"
#include "reg.h"

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
#include <unordered_map>

using namespace llvm;

const int REG_FILE_SIZE = 8;
int REG_FILE[REG_FILE_SIZE];


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
    Module *module = new Module("top", context);
    IRBuilder<> builder(context);


    //[32 x i32] regFile = {0, 0, 0, 0}
    ArrayType *regFileType = ArrayType::get(builder.getInt32Ty(), REG_FILE_SIZE);
    module->getOrInsertGlobal("regFile", regFileType);
    GlobalVariable *regFile = module->getNamedGlobal("regFile");


    // declare void @main()
    FunctionType *funcType = FunctionType::get(builder.getVoidTy(), false);
    Function *mainFunc =
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
            if(!arg.compare("simPutPixel")) {
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
            !name.compare("je")) {
            input  >> arg;
            continue;
        }

        outs() << name << "\n";
        name = name.substr(0, name.size()-1);
        BBMap[name] = BasicBlock::Create(context, name, mainFunc);
    }
    input.close();
    /*input.open(argv[1]);

    Type* voidType = Type::getVoidTy(context);
    Type* int32Type = Type::getInt32Ty(context);



    ArrayRef<Type*> simPutPixelParamTypes = {int32Type, int32Type, int32Type};
    FunctionType* simPutPixelType =
        FunctionType::get(voidType, simPutPixelParamTypes, false);
    FunctionCallee simPutPixelFunc =
        module->getOrInsertFunction("simPutPixel", simPutPixelType);


    FunctionType* simFlushType = FunctionType::get(voidType, false);
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


    FunctionCallee doSELECTFunc =
        module->getOrInsertFunction("doSELECT", int32x4FuncType);
    FunctionCallee doCALLunc =
        module->getOrInsertFunction("doCALL", int32x4FuncType);

    FunctionCallee doADDFunc =
        module->getOrInsertFunction("doADD", int32x3FuncType);
    FunctionCallee doSHLFunc =
        module->getOrInsertFunction("doSHL", int32x3FuncType);
    FunctionCallee doORFunc =
        module->getOrInsertFunction("doOR", int32x3FuncType);
    FunctionCallee doANDFunc =
        module->getOrInsertFunction("doAND", int32x3FuncType);

    FunctionCallee doCMPFunc =
        module->getOrInsertFunction("doCMP", int32x2FuncType);
    FunctionCallee doEXT32Func =
        module->getOrInsertFunction("doEXT32", int32x2FuncType);
    FunctionCallee doSTOREFunc =
        module->getOrInsertFunction("doSTORE", int32x2FuncType);
    FunctionCallee doLOADFunc =
        module->getOrInsertFunction("doLOAD", int32x2FuncType);
    FunctionCallee doEXT64Func =
        module->getOrInsertFunction("doEXT64", int32x2FuncType);
    FunctionCallee doMOVFunc =
        module->getOrInsertFunction("doMOV", int32x2FuncType);

    FunctionCallee doJGFunc =
        module->getOrInsertFunction("doJG", int32FuncType);
    FunctionCallee doJEFunc =
        module->getOrInsertFunction("doJE", int32FuncType);
    FunctionCallee doINCFunc =
        module->getOrInsertFunction("doINC", int32FuncType);
    FunctionCallee doJUMPFunc =
        module->getOrInsertFunction("doJUMP", int32FuncType);
    FunctionCallee doRRETunc =
        module->getOrInsertFunction("doRRET", int32FuncType);
    FunctionCallee doDECFunc =
        module->getOrInsertFunction("doDEC", int32FuncType);
    FunctionCallee doJLEunc =
        module->getOrInsertFunction("doJLE", int32FuncType);
    FunctionCallee doJGEFunc =
        module->getOrInsertFunction("doJGE", int32FuncType);


    while (input >> name) {
        if (!name.compare("MOV")) {
            input >> arg;
            outs() << "\nMOV " << arg;

            input >> arg;
            Value* arg1 = builder.getInt32(std::stoi(arg.substr(1)));

            input >> arg;
            Value* arg2 = getArgumentValue(arg);

            Value *args[] = {arg1, arg2};
            builder.CreateCall(doMOVFunc, args);
            continue;
        }
    }*/
}
