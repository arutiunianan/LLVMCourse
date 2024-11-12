#include "new_app/sim.h"

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

void do_mov(int arg1, int arg2) {
    REG_FILE[arg1] = REG_FILE[arg2];
}

void do_movconst(int arg1, int arg2) {
    REG_FILE[arg1] = arg2;
}

void do_and(int arg1, int arg2) {
    REG_FILE[arg1] = REG_FILE[arg1] & arg2;
}

void do_cmp(int arg1, int arg2) {
    REG_FILE[REG_FILE_SIZE - 1] = REG_FILE[arg1] == arg2;
}

void do_shl(int arg1, int arg2) {
    REG_FILE[arg1] = REG_FILE[arg1] << arg2;
}

void do_add(int arg1, int arg2) {
    REG_FILE[arg1] = REG_FILE[arg1] + REG_FILE[arg2];
}

void do_addconst(int arg1, int arg2) {
    REG_FILE[arg1] = REG_FILE[arg1] + arg2;
}

void do_inc(int arg1) {
    REG_FILE[arg1] = REG_FILE[arg1] + 1;
}

void do_callsimPutPixel(int arg1, int arg2, int arg3) {
    simPutPixel(REG_FILE[arg1], REG_FILE[arg2], REG_FILE[arg3]);
}

void do_callsimRand(int arg1) {
    REG_FILE[arg1] = simRand();
}

void do_callsimFlush(int arg1) {
    simFlush();
}