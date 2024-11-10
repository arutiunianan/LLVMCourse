#include "../GameOfLife/sim.h"

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
uint32_t REG_FILE[REG_FILE_SIZE];

std::string create_label(std::string myString) {
  outs() << "\n" <<"making label:" << myString << "\n";
  return myString.substr(0, myString.size()-1);
}

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
    ArrayType *regFileType = ArrayType::get(Type::getInt32Ty(context), REG_FILE_SIZE);
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
        if (!name.compare("CALL")) {
            input >> arg;
            if(!arg.compare("simPutPixel") || !arg.compare("countLivingNeighbors")) {
                input >> arg >> arg >> arg;
            }
            continue;
        }
        if (!name.compare("ADD") || !name.compare("SHL") || 
            !name.compare("OR")  || !name.compare("AND")) {
            input >> arg >> arg >> arg;
            continue;
        }
        if (!name.compare("CMP")   || !name.compare("EXT32") ||
            !name.compare("STORE") || !name.compare("LOAD")  ||
            !name.compare("EXT64") || !name.compare("MOV")) {
            input >> arg >> arg;
            continue;
        }
        if (!name.compare("JG")   || !name.compare("JE")  ||
            !name.compare("INC")  || !name.compare("JMP") ||
            !name.compare("RRET") || !name.compare("DEC") ||
            !name.compare("JLE")  || !name.compare("JGE")) {
            input  >> arg;
            continue;
        }
        if (!name.compare("RET")) {
            continue;
        }

        name = create_label(name);
        BBMap[name] = BasicBlock::Create(context, name, mainFunc);
    }

}
