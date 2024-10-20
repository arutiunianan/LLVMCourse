#include "llvm/ExecutionEngine/ExecutionEngine.h" 
#include "llvm/ExecutionEngine/GenericValue.h"   
#include "llvm/IR/IRBuilder.h"                   
#include "llvm/IR/LLVMContext.h"                 
#include "llvm/IR/Module.h"                      
#include "llvm/Support/TargetSelect.h"           
#include "llvm/Support/raw_ostream.h"            

#include "../GameOfLife/sim.h" 

using namespace llvm;

int main() {
    LLVMContext context;

    Module* module = new Module("app.c", context);
    IRBuilder<> builder(context);

    Type* voidType = Type::getVoidTy(context);

    ArrayRef<Type*> simPutPixelParamTypes = {Type::getInt32Ty(context),
                                             Type::getInt32Ty(context),
                                             Type::getInt32Ty(context)};
    FunctionType* simPutPixelType = 
        FunctionType::get(voidType, simPutPixelParamTypes, false);
    FunctionCallee simPutPixelFunc =
        module->getOrInsertFunction("simPutPixel", simPutPixelType);

    FunctionType* simFlushType = 
        FunctionType::get(voidType, {voidType}, false);
    FunctionCallee simFlushFunc =
        module->getOrInsertFunction("simFlush", simFlushType);

    FunctionType* simRandType = 
        FunctionType::get(Type::getInt32Ty(context), {voidType}, false);
    FunctionCallee simRandFunc =
        module->getOrInsertFunction("simRand", simFlushType);



//------------------------------ countLivingNeighbors ------------------------------
    FunctionType* countLivingNeighborsFuncType = 
        FunctionType::get(builder.getInt32Ty(), {builder.getInt32Ty(), 
                                                builder.getInt32Ty(),
                                                builder.getInt32PtrTy()}, 
                                                false);
    Function* countLivingNeighborsFunc =
        Function::Create(countLivingNeighborsFuncType, Function::ExternalLinkage, 
                         "countLivingNeighbors", module);

    Function::arg_iterator сargs = countLivingNeighborsFunc->arg_begin();
    Value* count0 = сargs; //%0
    Value* count1 = ++сargs; //%1
    Value* count2 = ++сargs; //%2

    BasicBlock* CBB0 = BasicBlock::Create(context, "", countLivingNeighborsFunc);
    BasicBlock* CBB7 = BasicBlock::Create(context, "", countLivingNeighborsFunc);
    BasicBlock* CBB9 = BasicBlock::Create(context, "", countLivingNeighborsFunc);
    BasicBlock* CBB11 = BasicBlock::Create(context, "", countLivingNeighborsFunc);
    BasicBlock* CBB19 = BasicBlock::Create(context, "", countLivingNeighborsFunc);
    BasicBlock* CBB22 = BasicBlock::Create(context, "", countLivingNeighborsFunc);
    BasicBlock* CBB31 = BasicBlock::Create(context, "", countLivingNeighborsFunc);
    BasicBlock* CBB35 = BasicBlock::Create(context, "", countLivingNeighborsFunc);
    BasicBlock* CBB44 = BasicBlock::Create(context, "", countLivingNeighborsFunc);
    BasicBlock* CBB47 = BasicBlock::Create(context, "", countLivingNeighborsFunc);
    BasicBlock* CBB49 = BasicBlock::Create(context, "", countLivingNeighborsFunc);
    BasicBlock* CBB58 = BasicBlock::Create(context, "", countLivingNeighborsFunc);
    BasicBlock* CBB62 = BasicBlock::Create(context, "", countLivingNeighborsFunc);
    BasicBlock* CBB71 = BasicBlock::Create(context, "", countLivingNeighborsFunc);
    BasicBlock* CBB75 = BasicBlock::Create(context, "", countLivingNeighborsFunc);
    BasicBlock* CBB77 = BasicBlock::Create(context, "", countLivingNeighborsFunc);
    BasicBlock* CBB86 = BasicBlock::Create(context, "", countLivingNeighborsFunc);
    BasicBlock* CBB89 = BasicBlock::Create(context, "", countLivingNeighborsFunc);
    BasicBlock* CBB98 = BasicBlock::Create(context, "", countLivingNeighborsFunc);
    BasicBlock* CBB102 = BasicBlock::Create(context, "", countLivingNeighborsFunc);

//------------------------------ %0 ------------------------------
    builder.SetInsertPoint(CBB0);
    //%4 = add nsw i32 %0, -1
    Value* count4 = builder.CreateAdd
        (count0, ConstantInt::get(context, APInt(32, -1)))
    //%5 = add nsw i32 %1, -1
    Value* count5 = builder.CreateAdd
        (count1, ConstantInt::get(context, APInt(32, -1)))
    //%6 = icmp ugt i32 %4, 511
    Value* count6 = builder.CreateICmpUGT
        (count4, ConstantInt::get(context, APInt(32, 511)));
    //br i1 %6, label %44, label %9
    builder.CreateCondBr(count6, CBB44, CBB9);
//----------------------------------------------------------------

//------------------------------ %7 ------------------------------
    builder.SetInsertPoint(CBB7);
    //%8 = phi i32 [ %72, %71 ], [ %99, %98 ], [ %110, %102 ]
    PHINode count8 = builder.CreatePHI(builder.getInt32Ty(), 3);
    //ret i32 %8
    builder.CreateRet(count8);
//----------------------------------------------------------------

//------------------------------ %9 ------------------------------
    builder.SetInsertPoint(CBB9);
    //%10 = icmp ugt i32 %5, 255
    Value* count6 = builder.CreateICmpUGT
        (count5, ConstantInt::get(context, APInt(32, 255)));
    //br i1 %10, label %19, label %11
    builder.CreateCondBr(count10, CBB19, CBB11);
//----------------------------------------------------------------

//------------------------------ %11 ------------------------------
    builder.SetInsertPoint(CBB11);
    //%12 = shl nuw nsw i32 %5, 9
    Value* count12 = builder.CreateShl
        (count6, ConstantInt::get(context, APInt(32, 9)));
    //%13 = or disjoint i32 %12, %4
    Value* count13 = builder.CreateBinOr(count12, count4);
    //%14 = zext nneg i32 %13 to i64
    Value* count14 = builder.CreateZExt
        (count13, Type::getInt64Ty(context));
    //%15 = getelementptr inbounds i32, ptr %2, i64 %14
    Value* count15 = builder.CreateGEP
        (Type::getInt32Ty(context), count2, count14);
    //%16 = load i32, ptr %15, align 4, !tbaa !5
    Value* count16 = builder.CreateLoad
        (Type::getInt32Ty(context), count15);
    //%17 = icmp ne i32 %16, 0
    Value* count17 = builder.CreateICmpNE
        (count16, ConstantInt::get(Type::getInt32Ty(context), 0));
    //%18 = zext i1 %17 to i32
    Value* count18 = builder.CreateZExt
        (count17, Type::getInt32Ty(context));
    //br label %19
    builder.CreateCondBr(CBB19);
//----------------------------------------------------------------

//------------------------------ %19 ------------------------------
    builder.SetInsertPoint(CBB19);
    //%20 = phi i32 [ 0, %9 ], [ %18, %11 ]
    PHINode count20 = builder.CreatePHI(builder.getInt32Ty(), 2);
    //%21 = icmp ugt i32 %1, 255
    Value* count21 = builder.CreateICmpUGT
        (count1, ConstantInt::get(context, APInt(32, 255)));
    //br i1 %21, label %31, label %22
    builder.CreateCondBr(count21, CBB31, CBB22);
//----------------------------------------------------------------

//------------------------------ %22 ------------------------------
    builder.SetInsertPoint(CBB22);
    //%23 = shl nuw nsw i32 %1, 9
    Value* count12 = builder.CreateShl
        (count1, ConstantInt::get(context, APInt(32, 9)));
    //%24 = or disjoint i32 %23, %4
    Value* count13 = builder.CreateBinOr(count23, count4);
    //%25 = zext nneg i32 %24 to i64
    Value* count14 = builder.CreateZExt
        (count24, Type::getInt64Ty(context));
    //%26 = getelementptr inbounds i32, ptr %2, i64 %25
    Value* count15 = builder.CreateGEP
        (Type::getInt32Ty(context), count2, count25);
    //%27 = load i32, ptr %26, align 4, !tbaa !5
    Value* count16 = builder.CreateLoad
        (Type::getInt32Ty(context), count26);
    //%28 = icmp ne i32 %27, 0
    Value* count17 = builder.CreateICmpNE
        (count27, ConstantInt::get(Type::getInt32Ty(context), 0));
    //%29 = zext i1 %28 to i32
    Value* count18 = builder.CreateZExt
        (count28, Type::getInt32Ty(context));
    //%30 = add nuw nsw i32 %20, %29
    Value* count30 = builder.CreateAdd
        (count20, count29, "", true, true);
    //br label %31
    builder.CreateCondBr(CBB31);
//----------------------------------------------------------------

//------------------------------ %31 ------------------------------
    builder.SetInsertPoint(CBB31);
    //%32 = phi i32 [ %20, %19 ], [ %30, %22 ]
    PHINode count32 = builder.CreatePHI(builder.getInt32Ty(), 2);
    //%33 = add nsw i32 %1, 1
    Value* coun33 = builder.CreateAdd
        (count1, ConstantInt::get(context, APInt(32, 1)))
    //%34 = icmp ugt i32 %33, 255
    Value* count34 = builder.CreateICmpUGT
        (count33, ConstantInt::get(context, APInt(32, 255)));
    //br i1 %34, label %44, label %35
    builder.CreateCondBr(count34, CBB44, CBB35);
//----------------------------------------------------------------

//------------------------------ %35 ------------------------------
    builder.SetInsertPoint(CBB35);
    //%36 = shl nuw nsw i32 %33, 9
    Value* count36 = builder.CreateShl
        (count33, ConstantInt::get(context, APInt(32, 9)));
    //%37 = or disjoint i32 %36, %4
    Value* count37 = builder.CreateBinOr(count36, count4);
    //%38 = zext nneg i32 %37 to i64
    Value* count38 = builder.CreateZExt
        (count37, Type::getInt64Ty(context));
    //%39 = getelementptr inbounds i32, ptr %2, i64 %38
    Value* count39 = builder.CreateGEP
        (Type::getInt32Ty(context), count2, count38);
    //%40 = load i32, ptr %39, align 4, !tbaa !5
    Value* count40 = builder.CreateLoad
        (Type::getInt32Ty(context), count39);
    //%41 = icmp ne i32 %40, 0
    Value* count41 = builder.CreateICmpNE
        (count40, ConstantInt::get(Type::getInt32Ty(context), 0));
    //%42 = zext i1 %41 to i32
    Value* count42 = builder.CreateZExt
        (count41, Type::getInt32Ty(context));
    //%43 = add nuw nsw i32 %32, %42
    Value* count43 = builder.CreateAdd
        (count32, count42, "", true, true);
    //br label %44
    builder.CreateCondBr(CBB44);
//----------------------------------------------------------------

//------------------------------ %44 ------------------------------
    builder.SetInsertPoint(CBB44);
    //%45 = phi i32 [ 0, %3 ], [ %32, %31 ], [ %43, %35 ]
    PHINode count45 = builder.CreatePHI(builder.getInt32Ty(), 3);
    //%46 = icmp ugt i32 %0, 511
    Value* count46 = builder.CreateICmpUGT
        (count0, ConstantInt::get(context, APInt(32, 511)));
    //br i1 %46, label %71, label %47
    builder.CreateCondBr(count46, CBB71, CBB47);
//----------------------------------------------------------------

//------------------------------ %47 ------------------------------
    builder.SetInsertPoint(CBB47);
    //%48 = icmp ugt i32 %5, 255
    Value* count48 = builder.CreateICmpUGT
        (count5, ConstantInt::get(context, APInt(32, 255)));
    //br i1 %48, label %58, label %49
    builder.CreateCondBr(count48, CBB58, CBB49);
//----------------------------------------------------------------

//------------------------------ %49 ------------------------------
    builder.SetInsertPoint(CBB49);
    //%50 = shl nuw nsw i32 %5, 9
    Value* count50 = builder.CreateShl
        (count5, ConstantInt::get(context, APInt(32, 9)));
    //%51 = or disjoint i32 %50, %0
    Value* count51 = builder.CreateBinOr(count50, count0);
    //%52 = zext nneg i32 %51 to i64
    Value* count52 = builder.CreateZExt
        (count50, Type::getInt64Ty(context));
    //%53 = getelementptr inbounds i32, ptr %2, i64 %52
    Value* count53 = builder.CreateGEP
        (Type::getInt32Ty(context), count2, count52);
    //%54 = load i32, ptr %53, align 4, !tbaa !5
    Value* count54 = builder.CreateLoad
        (Type::getInt32Ty(context), count53);
    //%55 = icmp ne i32 %54, 0
    Value* count55 = builder.CreateICmpNE
        (count54, ConstantInt::get(Type::getInt32Ty(context), 0));
    //%56 = zext i1 %55 to i32
    Value* count56 = builder.CreateZExt
        (count55, Type::getInt32Ty(context));
    //%57 = add nuw nsw i32 %45, %56
    Value* count57 = builder.CreateAdd
        (count45, count56, "", true, true);
    //br label %58
    builder.CreateCondBr(CBB58);
//----------------------------------------------------------------

//------------------------------ %58 ------------------------------
    builder.SetInsertPoint(CBB58);
    //%59 = phi i32 [ %45, %47 ], [ %57, %49 ]
    PHINode count59 = builder.CreatePHI(builder.getInt32Ty(), 2);
    //%60 = add nsw i32 %1, 1
    Value* count60 = builder.CreateAdd
        (count1, ConstantInt::get(context, APInt(32, 1)))
    //%61 = icmp ugt i32 %60, 255
    Value* count61 = builder.CreateICmpUGT
        (count60, ConstantInt::get(context, APInt(32, 255)));
    //br i1 %61, label %71, label %62
    builder.CreateCondBr(count61, CBB71, CBB61);
//----------------------------------------------------------------

//------------------------------ %62 ------------------------------
    builder.SetInsertPoint(CBB62);
    //%63 = shl nuw nsw i32 %60, 9
    Value* count63 = builder.CreateShl
        (count60, ConstantInt::get(context, APInt(32, 9)));
    //%64 = or disjoint i32 %63, %0
    Value* count64 = builder.CreateBinOr(count63, count0);
    //%65 = zext nneg i32 %64 to i64
    Value* count65 = builder.CreateZExt
        (count64, Type::getInt64Ty(context));
    //%66 = getelementptr inbounds i32, ptr %2, i64 %65
    Value* count66 = builder.CreateGEP
        (Type::getInt32Ty(context), count2, count65);
    //%67 = load i32, ptr %66, align 4, !tbaa !5
    Value* count67 = builder.CreateLoad
        (Type::getInt32Ty(context), count66);
    //%68 = icmp ne i32 %67, 0
    Value* count68 = builder.CreateICmpNE
        (count67, ConstantInt::get(Type::getInt32Ty(context), 0));
    //%69 = zext i1 %68 to i32
    Value* count69 = builder.CreateZExt
        (count68, Type::getInt32Ty(context));
    //%70 = add nuw nsw i32 %59, %69
    Value* count70 = builder.CreateAdd
        (count59, count69, "", true, true);
    //br label %71
    builder.CreateBr(CBB71);
//----------------------------------------------------------------

//------------------------------ %71 ------------------------------
    builder.SetInsertPoint(CBB71);
    //%72 = phi i32 [ %45, %44 ], [ %59, %58 ], [ %70, %62 ]
    PHINode* count72 = builder.CreatePHI(builder.getInt32Ty(), 3);
    //%73 = add nsw i32 %0, 1
    Value* count73 = builder.CreateAdd
        (count0, ConstantInt::get(context, APInt(32, 1)));
    //%74 = icmp ugt i32 %73, 511
    Value* count74 = builder.CreateICmpUGT
        (count73, ConstantInt::get(context, APInt(32, 511)));
    //br i1 %74, label %7, label %75
    builder.CreateCondBr(count74, CBB7, CBB75);
//----------------------------------------------------------------

//------------------------------ %75 ------------------------------
    builder.SetInsertPoint(CBB75);
    //%76 = icmp ugt i32 %5, 255
    Value* count76 = builder.CreateICmpUGT
        (count5, ConstantInt::get(context, APInt(32, 255)));
    //br i1 %76, label %86, label %77
    builder.CreateCondBr(count76, CBB86, CBB77);
//----------------------------------------------------------------


//------------------------------ %77 ------------------------------
    builder.SetInsertPoint(CBB77);
    //%78 = shl nuw nsw i32 %5, 9
    Value* count78 = builder.CreateShl
        (count5, ConstantInt::get(context, APInt(32, 9)));
    //%79 = or disjoint i32 %78, %73
    Value* count79 = builder.CreateBinOr(count78, count73);
    //%80 = zext nneg i32 %79 to i64
    Value* count80 = builder.CreateZExt
        (count79, Type::getInt64Ty(context));
    //%81 = getelementptr inbounds i32, ptr %2, i64 %80
    Value* count81 = builder.CreateGEP
        (Type::getInt32Ty(context), count2, count80);
    //%82 = load i32, ptr %81, align 4, !tbaa !5
    Value* count82 = builder.CreateLoad
        (Type::getInt32Ty(context), count81);
    //%83 = icmp ne i32 %82, 0
    Value* count83 = builder.CreateICmpNE
        (count82, ConstantInt::get(Type::getInt32Ty(context), 0));
    //%84 = zext i1 %83 to i32
    Value* count84 = builder.CreateZExt
        (count83, Type::getInt32Ty(context));
    //%85 = add nuw nsw i32 %72, %84
    Value* count85 = builder.CreateAdd
        (count72, count84, "", true, true);
    //br label %86
    builder.CreateBr(CBB86);
//----------------------------------------------------------------

//------------------------------ %86 ------------------------------
    builder.SetInsertPoint(CBB86);
    //%87 = phi i32 [ %72, %75 ], [ %85, %77 ]
    PHINode* count87 = builder.CreatePHI(builder.getInt32Ty(), 2);

    //%88 = icmp ugt i32 %1, 255
    Value* count88 = builder.CreateICmpUGT
        (count1, ConstantInt::get(context, APInt(32, 255)));
    //br i1 %88, label %98, label %89
    builder.CreateCondBr(count88, CBB98, CBB89);
//----------------------------------------------------------------

//------------------------------ %89 ------------------------------
    builder.SetInsertPoint(CBB89);
    //%90 = shl nuw nsw i32 %1, 9
    Value* count90 = builder.CreateShl
        (count1, ConstantInt::get(context, APInt(32, 9)));
    //%91 = or disjoint i32 %90, %73
    Value* count91 = builder.CreateBinOr(count90, count73);
    //%92 = zext nneg i32 %91 to i64
    Value* count92 = builder.CreateZExt
        (count91, Type::getInt64Ty(context));
    //%93 = getelementptr inbounds i32, ptr %2, i64 %92
    Value* count93 = builder.CreateGEP
        (Type::getInt32Ty(context), count2, count92);
    //%94 = load i32, ptr %93, align 4, !tbaa !5
    Value* count94 = builder.CreateLoad
        (Type::getInt32Ty(context), count93);
    //%95 = icmp ne i32 %94, 0
    Value* count95 = builder.CreateICmpNE
        (count94, ConstantInt::get(Type::getInt32Ty(context), 0));
    //%96 = zext i1 %95 to i32
    Value* count96 = builder.CreateZExt
        (count95, Type::getInt32Ty(context));
    //%97 = add nuw nsw i32 %87, %96
    Value* count97 = builder.CreateAdd
        (count87, count96, "", true, true);
    //br label %98
    builder.CreateBr(CBB98);
//----------------------------------------------------------------

//------------------------------ %98 ------------------------------
    builder.SetInsertPoint(CBB98);
    //%99 = phi i32 [ %87, %86 ], [ %97, %89 ]
    PHINode* count99 = builder.CreatePHI(builder.getInt32Ty(), 2);
    //%100 = add nsw i32 %1, 1
    Value* count100 = builder.CreateAdd
        (count1, ConstantInt::get(context, APInt(32, 1)));
    //%101 = icmp ugt i32 %100, 255
    Value* count101 = builder.CreateICmpUGT
    (count100, ConstantInt::get(context, APInt(32, 255)));
    //br i1 %101, label %7, label %102
    builder.CreateCondBr(count101, CBB7, CBB102);
//----------------------------------------------------------------

//------------------------------ %102 ------------------------------
    builder.SetInsertPoint(CBB102);
    //%103 = shl nuw nsw i32 %100, 9
    Value* count103 = builder.CreateShl
        (count100, ConstantInt::get(context, APInt(32, 9)));
    //%104 = or disjoint i32 %103, %73
    Value* count104 = builder.CreateBinOr(count103, count73);
    //%105 = zext nneg i32 %104 to i64
    Value* count105 = builder.CreateZExt
        (count104, Type::getInt64Ty(context));
    //%106 = getelementptr inbounds i32, ptr %2, i64 %105
    Value* count106 = builder.CreateGEP
        (Type::getInt32Ty(context), count2, count105);
    //%107 = load i32, ptr %106, align 4, !tbaa !5
    Value* count107 = builder.CreateLoad
    (Type::getInt32Ty(context), count106);
    //%108 = icmp ne i32 %107, 0
    Value* count108 = builder.CreateICmpNE
       (count107, ConstantInt::get(Type::getInt32Ty(context), 0));
    //%109 = zext i1 %108 to i32
    Value* count109 = builder.CreateZExt
        (count108, Type::getInt32Ty(context));
    //%110 = add nuw nsw i32 %99, %109
    Value* count110 = builder.CreateAdd
        (count99, count109, "", true, true);
    //br label %7
    builder.CreateBr(CBB7);
//----------------------------------------------------------------

    count8->addIncoming(count72, CBB71);
    count8->addIncoming(count99, CBB98);
    count8->addIncoming(count110, CBB102);
    count11->addIncoming
        (ConstantInt::get(Type::getInt32Ty(context), 0), CBB9);
    count11->addIncoming(count99, CBB98);
    count32->addIncoming(count20, CBB19);
    count32->addIncoming(count30, CBB22);
    count45->addIncoming
        (ConstantInt::get(Type::getInt32Ty(context), 0), count3);
    count45->addIncoming(count32, CBB31);
    count45->addIncoming(count43, CBB35);
    count59->addIncoming(count45, CBB47);
    count59->addIncoming(count57, CBB49);
    count72->addIncoming(count45, CBB44);
    count72->addIncoming(count59, CBB58);
    count72->addIncoming(count70, CBB62);
    count87->addIncoming(count72, CBB75);
    count87->addIncoming(count85, CBB77);
    count99->addIncoming(count87, CBB86);
    count99->addIncoming(count97, CBB89);






//------------------------------ updatePixel ------------------------------
    FunctionType* updatePixelFuncType = 
        FunctionType::get(builder.getVoidTy(), {builder.getInt32Ty(), 
                                                builder.getInt32Ty(),
                                                builder.getInt32PtrTy(),
                                                builder.getInt32PtrTy()}, 
                                                false);
    Function* updatePixelFunc =
        Function::Create(updatePixelFuncType, Function::ExternalLinkage, 
                         "updatePixel", module);

    Function::arg_iterator uargs = updatePixelFunc->arg_begin();
    Value* update0 = uargs; //%0
    Value* update1 = ++uargs; //%1
    Value* update2 = ++uargs; //%2
    Value* update3 = ++uargs; //%3

    BasicBlock* UBB0 = BasicBlock::Create(context, "", updatePixelFunc);

//------------------------------ %0 ------------------------------
    builder.SetInsertPoint(UBB0);
    //%5 = tail call i32 @countLivingNeighbors(i32 noundef %0, i32 noundef %1, ptr noundef %2)
    Value* update5 = builder.CreateCall
        (countLivingNeighborsFunc, {update0, update1, update2});
    //%6 = shl nsw i32 %1, 9
    Value* update6 = builder.CreateShl
        (update1, ConstantInt::get(context, APInt(32, 9)));
    //%7 = add nsw i32 %6, %0
    Value* update7 = builder.CreateAdd
        (update6, update0, "", true, true);
    //%8 = sext i32 %7 to i64
    Value* update8 = builder.CreateSExt
        (update7, Type::getInt64Ty(context));
    //%9 = getelementptr inbounds i32, ptr %2, i64 %8
    Value* update9 = builder.CreateGEP
        (Type::getInt32Ty(context), update2, update8);
    //%10 = load i32, ptr %9, align 4, !tbaa !5
    Value* update10 = builder.CreateLoad
        (Type::getInt32Ty(context), update9);
    //%11 = icmp eq i32 %10, 1
    Value* update11 = builder.CreateICmpEQ
        (update10, ConstantInt::get(Type::getInt32Ty(context), 1));
    //%12 = and i32 %5, -2
    Value* update12 = builder.CreateAnd
        (update5, ConstantInt::get(Type::getInt32Ty(context), -2));
    //%13 = icmp eq i32 %12, 2
    Value* update13 = builder.CreateICmpEQ
        (update12, ConstantInt::get(Type::getInt32Ty(context), 2));
    //%14 = icmp eq i32 %5, 3
    Value* update14 = builder.CreateICmpEQ
        (update5, ConstantInt::get(Type::getInt32Ty(context), 3));
    //%15 = select i1 %11, i1 %13, i1 %14
    Value* update15 = builder.CreateSelect
        (update11, update13, update14);
    //%16 = zext i1 %15 to i32
    Value* update16 = builder.CreateZExt
        (update15, Type::getInt32Ty(context));
    //%17 = getelementptr inbounds i32, ptr %3, i64 %8
    Value* update17 = builder.CreateGEP
        (Type::getInt32Ty(context), update3, update8);
    //store i32 %16, ptr %17, align 4
    builder.CreateStore(update16, update17, false);
    //ret void
    builder.CreateRetVoid();
//----------------------------------------------------------------





//------------------------------ swapPixels ------------------------------
    FunctionType* swapPixelsFuncType = 
        FunctionType::get(builder.getVoidTy(), 
                          {builder.getInt32PtrTy()->getPointerTo(),
                           builder.getInt32PtrTy()->getPointerTo()}, 
                          false);
    Function* swapPixelsFunc =
        Function::Create(swapPixelsFuncType, Function::ExternalLinkage, 
                         "swapPixels", module);

    Function::arg_iterator sargs = swapPixelsFunc->arg_begin();
    Value* swap0 = sargs; //%0
    Value* swap1 = ++sargs; //%1

    BasicBlock* SBB0 = BasicBlock::Create(context, "", swapPixelsFunc);

//------------------------------ %0 ------------------------------
    builder.SetInsertPoint(SBB0);
    //%3 = load ptr, ptr %0, align 8, !tbaa !9
    Value* swap3 = builder.CreateLoad
        (Type::getInt8PtrTy(context), swap0, "", false, 
         8, nullptr, nullptr, 9);
    //%4 = load ptr, ptr %1, align 8, !tbaa !9
    Value* swap4 = builder.CreateLoad
        (Type::getInt8PtrTy(context), swap1, "", false, 
         8, nullptr, nullptr, 9);
    //store ptr %4, ptr %0, align 8, !tbaa !9
    builder.CreateStore(swap4, swap0, false, 8, nullptr, nullptr, 9);
    //store ptr %3, ptr %1, align 8, !tbaa !9
    builder.CreateStore(swap3, swap1, false, 8, nullptr, nullptr, 9);
    //ret void
    builder.CreateRetVoid();
//----------------------------------------------------------------






//------------------------------ gameOfLife ------------------------------
    FunctionType* gameOfLifeFuncType = 
        FunctionType::get(builder.getVoidTy(), 
                          {builder.getInt32PtrTy(),
                           builder.getInt32PtrTy()}, 
                          false);
    Function* gameOfLifeFunc =
        Function::Create(gameOfLifeFuncType, Function::ExternalLinkage, 
                         "gameOfLife", module);

    Function::arg_iterator gargs = gameOfLifeFunc->arg_begin();
    Value* game0 = gargs; //%0
    Value* game1 = ++gargs; //%1

    BasicBlock* GBB0 = BasicBlock::Create(context, "", gameOfLifeFunc);
    BasicBlock* GBB3 = BasicBlock::Create(context, "", gameOfLifeFunc);
    BasicBlock* GBB6 = BasicBlock::Create(context, "", gameOfLifeFunc);
    BasicBlock* GBB10 = BasicBlock::Create(context, "", gameOfLifeFunc);
    BasicBlock* GBB13 = BasicBlock::Create(context, "", gameOfLifeFunc);

//------------------------------ %0 ------------------------------
    builder.SetInsertPoint(GBB0);
    //br label %3
    builder.CreateCondBr(GBB3);
//----------------------------------------------------------------

//------------------------------ %3 ------------------------------
    builder.SetInsertPoint(GBB3);
    //%4 = phi ptr [ %0, %2 ], [ %5, %9 ]
    PHINode* game4 = builder.CreatePHI
        (Type::getInt8PtrTy(context), 2);
    //%5 = phi ptr [ %1, %2 ], [ %4, %9 ]
    PHINode* game5 = builder.CreatePHI
        (Type::getInt8PtrTy(context), 2);
    //br label %6
    builder.CreateBr(GBB6);
//----------------------------------------------------------------

//------------------------------ %6 ------------------------------
    builder.SetInsertPoint(GBB6);
    //%7 = phi i64 [ 0, %3 ], [ %11, %10 ]
    PHINode* game7 = builder.CreatePHI(Type::getInt64Ty(context), 2);
    //%8 = trunc i64 %7 to i32
    Value* game8 = builder.CreateTrunc
        (game7, Type::getInt32Ty(context));
    //br label %13
    builder.CreateBr(GBB13);
//----------------------------------------------------------------

//------------------------------ %9 ------------------------------
    builder.SetInsertPoint(GBB9);
    //tail call void (...) @simFlush() #6
    builder.CreateCall(simFlushFunc, {});
    //br label %3
    builder.CreateBr(GBB3);
//----------------------------------------------------------------

//------------------------------ %10 ------------------------------
    builder.SetInsertPoint(GBB10);
    //%11 = add nuw nsw i64 %7, 1
    Value* game11 = builder.CreateAdd
        (game7, ConstantInt::get(Type::getInt64Ty(context), 1), "", 
         true, true);
    //%12 = icmp eq i64 %11, 512
    Value* game12 = builder.CreateICmpEQ
        (game11, ConstantInt::get(Type::getInt64Ty(context), 512));
    //br i1 %12, label %9, label %6, !llvm.loop !11
    builder.CreateCondBr(game12, GBB9, GBB6);
//----------------------------------------------------------------

//------------------------------ %13 ------------------------------
    builder.SetInsertPoint(GBB13);
    //%14 = phi i64 [ 0, %6 ], [ %31, %13 ]
    PHINode* game14 = builder.CreatePHI
        (Type::getInt64Ty(context), 2);
    //%15 = shl nuw nsw i64 %14, 9
    Value* game15 = builder.CreateShl
        (game14, ConstantInt::get(Type::getInt64Ty(context), 9));
    //%16 = or disjoint i64 %15, %7
    Value* game16 = builder.CreateBinOr(game15, game7);
    //%17 = getelementptr inbounds i32, ptr %4, i64 %16
    Value* game17 = builder.CreateGEP
        (Type::getInt32Ty(context), game4, game16);
    //%18 = load i32, ptr %17, align 4, !tbaa !5
    Value* game18 = builder.CreateLoad
        (Type::getInt32Ty(context), game17, "", 
         false, 4, nullptr, nullptr, 5);
    //%19 = icmp eq i32 %18, 0
    Value* game19 = builder.CreateICmpEQ
        (game18, ConstantInt::get(Type::getInt32Ty(context), 0));
    //%20 = select i1 %19, i32 -16777216, i32 16711680
    Value* game20 = builder.CreateSelect
        (game19, ConstantInt::get(Type::getInt32Ty(context), -16777216), 
         ConstantInt::get(Type::getInt32Ty(context), 16711680));
    //%21 = trunc i64 %14 to i32
    Value* game21 = builder.CreateTrunc
        (game14, Type::getInt32Ty(context));
    //tail call void @simPutPixel(i32 noundef %8, i32 noundef %21, i32 noundef %20) #6
    builder.CreateCall(simPutPixelFunc, {game8, game21, game20});
    //%22 = tail call i32 @countLivingNeighbors(i32 noundef %8, i32 noundef %21, ptr noundef %4)
    Value* game22 = builder.CreateCall
        (countLivingNeighborsFunc, {game8, game21, game4});
    //%23 = load i32, ptr %17, align 4, !tbaa !5
    Value* game23 = builder.CreateLoad
        (Type::getInt32Ty(context), game17, "", 
         false, 4, nullptr, nullptr, 5);
    //%24 = icmp eq i32 %23, 1
    Value* game24 = builder.CreateICmpEQ
        (game23, ConstantInt::get(Type::getInt32Ty(context), 1));
    //%25 = and i32 %22, -2
    Value* game25 = builder.CreateAnd
        (game22, ConstantInt::get(Type::getInt32Ty(context), -2));
    //%26 = icmp eq i32 %25, 2
    Value* game26 = builder.CreateICmpEQ
        (game25, ConstantInt::get(Type::getInt32Ty(context), 2));
    //%27 = icmp eq i32 %22, 3
    Value* game27 = builder.CreateICmpEQ
        (game22, ConstantInt::get(Type::getInt32Ty(context), 3));
    //%28 = select i1 %24, i1 %26, i1 %27
    Value* game28 = builder.CreateSelect(game24, game26, game27);
    //%29 = zext i1 %28 to i32
    Value* game29 = builder.CreateZExt(game28, Type::getInt32Ty(context));
    //%30 = getelementptr inbounds i32, ptr %5, i64 %16
    Value* game30 = builder.CreateGEP
        (Type::getInt32Ty(context), game5, game16);
    //store i32 %29, ptr %30, align 4
    builder.CreateStore(game29, game30, false, 4);
    //%31 = add nuw nsw i64 %14, 1
    Value* game31 = builder.CreateAdd
        (game14, ConstantInt::get(Type::getInt64Ty(context), 1), "", 
         true, true);
    //%32 = icmp eq i64 %31, 256
    Value* game32 = builder.CreateICmpEQ
        (game31, ConstantInt::get(Type::getInt64Ty(context), 256));
    //br i1 %32, label %10, label %13, !llvm.loop !13
    builder.CreateCondBr(game32, GBB10, GBB13);
//----------------------------------------------------------------

    game4->addIncoming(game0, GBB2);
    game4->addIncoming(game5, GBB9);
    game5->addIncoming(game1, GBB2);
    game5->addIncoming(game4, GBB9);
    game7->addIncoming(ConstantInt::get(Type::getInt64Ty(context), 0));
    game7->addIncoming(game11, GBB10);
    game14->addIncoming(ConstantInt::get(Type::getInt64Ty(context), 0), GBB6);
    game14->addIncoming(game31, GBB13);






//------------------------------ app ------------------------------
    FunctionType* appFuncType = 
        FunctionType::get(builder.getVoidTy(), 
                          {builder.getInt32PtrTy()->getPointerTo(),
                           builder.getInt32PtrTy()->getPointerTo()}, 
                          false);
    Function* appFunc =
        Function::Create(appFuncType, Function::ExternalLinkage, 
                         "app", module);

    BasicBlock* ABB0 = BasicBlock::Create(context, "", appFunc);
    BasicBlock* ABB3 = BasicBlock::Create(context, "", appFunc);
    BasicBlock* ABB5 = BasicBlock::Create(context, "", appFunc);
    BasicBlock* ABB8 = BasicBlock::Create(context, "", appFunc);
    BasicBlock* ABB11 = BasicBlock::Create(context, "", appFunc);
    BasicBlock* ABB12 = BasicBlock::Create(context, "", appFunc);
    BasicBlock* ABB15 = BasicBlock::Create(context, "", appFunc);
    BasicBlock* ABB35 = BasicBlock::Create(context, "", appFunc);
    BasicBlock* ABB38 = BasicBlock::Create(context, "", appFunc);

//------------------------------ %0 ------------------------------
    builder.SetInsertPoint(ABB0);
    //%1 = alloca [512 x [256 x i32]], align 16
    Value* app1 = builder.CreateAlloca
        (ArrayType::get(ArrayType::get(Type::getInt32Ty(context),
                                       256), 512), 16);
    //%2 = alloca [512 x [256 x i32]], align 16
    Value* app2 = builder.CreateAlloca
        (ArrayType::get(ArrayType::get(Type::getInt32Ty(context), 
                                       256), 512), 16);
    //call void @llvm.lifetime.start.p0(i64 524288, ptr nonnull %1) #6
    builder.CreateCall(intrinsic::lifetime_start, 
        {ConstantInt::get(Type::getInt64Ty(context), 524288),
         app1});
    //call void @llvm.memset.p0.i64(ptr noundef nonnull align 16 dereferenceable(524288) %1, i8 0, i64 524288, i1 false)
    builder.CreateCall(intrinsic::memset,
        {app1,
        ConstantInt::get(Type::getInt8Ty(context), 0),
        ConstantInt::get(Type::getInt64Ty(context), 524288),
        ConstantInt::get(Type::getInt1Ty(context), false)});
    //call void @llvm.lifetime.start.p0(i64 524288, ptr nonnull %2) #6
    builder.CreateCall(intrinsic::lifetime_start, 
        {ConstantInt::get(Type::getInt64Ty(context), 524288),
         app2});
    //call void @llvm.memset.p0.i64(ptr noundef nonnull align 16 dereferenceable(524288) %2, i8 0, i64 524288, i1 false)
    builder.CreateCall(intrinsic::memset,
        {app2,
        ConstantInt::get(Type::getInt8Ty(context), 0),
        ConstantInt::get(Type::getInt64Ty(context), 524288),
        ConstantInt::get(Type::getInt1Ty(context), false)});
    //br label %3
    builder.CreateBr(ABB3);
//----------------------------------------------------------------

//------------------------------ %3 ------------------------------
    builder.SetInsertPoint(ABB3);
    //%4 = phi i64 [ 0, %0 ], [ %36, %35 ]
    PHINode* app4 = builder.CreatePHI
        (Type::getInt64Ty(context), 2);
    //br label %38
    builder.CreateBr(ABB38);
//----------------------------------------------------------------

//------------------------------ %5 ------------------------------
    builder.SetInsertPoint(ABB5);
    //%6 = phi ptr [ %7, %11 ], [ %1, %35 ]
    PHINode* app6 = builder.CreatePHI
        (Type::getInt8PtrTy(context), 2);
    //%7 = phi ptr [ %6, %11 ], [ %2, %35 ]
    PHINode* app7 = builder.CreatePHI
        (Type::getInt8PtrTy(context), 2);
    //br label %8
    builder.CreateBr(ABB8);
//----------------------------------------------------------------

//------------------------------ %8 ------------------------------
    builder.SetInsertPoint(ABB8);
    //%9 = phi i64 [ 0, %5 ], [ %13, %12 ]
    PHINode* app9 = builder.CreatePHI
        (Type::getInt64Ty(context), 2);
    //%10 = trunc i64 %9 to i32
    Value* app10 = builder.CreateTrunc
        (app9, Type::getInt32Ty(context));
    //br label %15
    builder.CreateBr(ABB15);
//----------------------------------------------------------------

//------------------------------ %11 ------------------------------
    builder.SetInsertPoint(ABB11);
    //tail call void (...) @simFlush() #6
    builder.CreateCall(simFlushFunc, {});
    //br label %5
    builder.CreateBr(ABB5);
//----------------------------------------------------------------

//------------------------------ %12 ------------------------------
    builder.SetInsertPoint(ABB12);
    //%13 = add nuw nsw i64 %9, 1
    Value* app13 = builder.CreateAdd
        (app9, ConstantInt::get(Type::getInt64Ty(context), 1),
         "", true, true);
    //%14 = icmp eq i64 %13, 512
    Value* app14 = builder.CreateICmpEQ
        (app13, ConstantInt::get(Type::getInt64Ty(context), 512));
    //br i1 %14, label %11, label %8, !llvm.loop !11
    builder.CreateCondBr(app14, ABB11, ABB8);
//----------------------------------------------------------------

//------------------------------ %15 ------------------------------
    builder.SetInsertPoint(ABB15);
    //%16 = phi i64 [ 0, %8 ], [ %33, %15 ]
    PHINode* app16 = builder.CreatePHI
        (Type::getInt64Ty(context), 2);
    //%17 = shl nuw nsw i64 %16, 9
    Value* app17 = builder.CreateShl
        (app16, ConstantInt::get(Type::getInt64Ty(context), 9));
    //%18 = add nuw nsw i64 %17, %9
    Value* app18 = builder.CreateAdd
        (app17, app9, "", true, true);
    //%19 = getelementptr inbounds i32, ptr %6, i64 %18
    Value* app19 = builder.CreateGEP
        (Type::getInt32Ty(context), app6, app18);
    //%20 = load i32, ptr %19, align 4, !tbaa !5
    Value* app20 = builder.CreateLoad
        (Type::getInt32Ty(context), app19);
    //%21 = icmp eq i32 %20, 0
    Value* app21 = builder.CreateICmpEQ
        (app20, ConstantInt::get(Type::getInt32Ty(context), 0));
    //%22 = select i1 %21, i32 -16777216, i32 16711680
    Value* app22 = builder.CreateSelect(app21,
        ConstantInt::get(Type::getInt32Ty(context), -16777216),
        ConstantInt::get(Type::getInt32Ty(context), 16711680));
    //%23 = trunc i64 %16 to i32
    Value* app23 = builder.CreateTrunc
        (app16, Type::getInt32Ty(context));
    //tail call void @simPutPixel(i32 noundef %10, i32 noundef %23, i32 noundef %22) #6
    builder.CreateCall(simPutPixelFunc, 
                       {app10, app23, app22});
    //%24 = call i32 @countLivingNeighbors(i32 noundef %10, i32 noundef %23, ptr noundef nonnull %6)
    Value* app24 = builder.CreateCall
        (countLivingNeighborsFunc, {app10, app23, app6});
    //%25 = load i32, ptr %19, align 4, !tbaa !5
    Value* app25 = builder.CreateLoad
        (Type::getInt32Ty(context), app19);
    //%26 = icmp eq i32 %25, 1
    Value* app26 = builder.CreateICmpEQ
        (app25, ConstantInt::get(Type::getInt32Ty(context), 1));
    //%27 = and i32 %24, -2
    Value* app27 = builder.CreateAnd
        (app24, ConstantInt::get(Type::getInt32Ty(context), -2));
    //%28 = icmp eq i32 %27, 2
    Value* app28 = builder.CreateICmpEQ
        (app27, ConstantInt::get(Type::getInt32Ty(context), 2));
    //%29 = icmp eq i32 %24, 3
    Value* app29 = builder.CreateICmpEQ
        (app24, ConstantInt::get(Type::getInt32Ty(context), 3));
    //%30 = select i1 %26, i1 %28, i1 %29
    Value* app30 = builder.CreateSelect(app26, app28, app29);
    //%31 = zext i1 %30 to i32
    Value* app31 = builder.CreateZExt
        (app30, Type::getInt32Ty(context));
    //%32 = getelementptr inbounds i32, ptr %7, i64 %18
    Value* app32 = builder.CreateGEP
        (Type::getInt32Ty(context), app7, app18);
    //store i32 %31, ptr %32, align 4
    builder.CreateStore(app31, app32);
    //%33 = add nuw nsw i64 %16, 1
    Value* app33 = builder.CreateAdd
        (app16, ConstantInt::get(Type::getInt64Ty(context), 1), 
         "", true, true);
    //%34 = icmp eq i64 %33, 256
    Value* app34 = builder.CreateICmpEQ
        (app33, ConstantInt::get(Type::getInt64Ty(context), 256));
    //br i1 %34, label %12, label %15, !llvm.loop !13
    builder.CreateCondBr(app34, ABB12, ABB15);
//----------------------------------------------------------------

//------------------------------ %35 ------------------------------
    builder.SetInsertPoint(ABB35);
    //%36 = add nuw nsw i64 %4, 1
    Value* app36 = builder.CreateAdd
        (app4, ConstantInt::get(Type::getInt64Ty(context), 1), 
         "", true, true);
    //%37 = icmp eq i64 %36, 512
    Value* app37 = builder.CreateICmpEQ
        (app36, ConstantInt::get(Type::getInt64Ty(context), 512));
    //br i1 %37, label %5, label %3, !llvm.loop !14
    builder.CreateCondBr(app37, ABB5, ABB3);
//----------------------------------------------------------------

//------------------------------ %38 ------------------------------
    builder.SetInsertPoint(ABB38);
    //%39 = phi i64 [ 0, %3 ], [ %43, %38 ]
    PHINode* app39 = builder.CreatePHI(Type::getInt64Ty(context), 2);
    //%40 = tail call i32 (...) @simRand() #6
    Value* app40 = builder.CreateCall(simRandFunc, {});
    //%41 = getelementptr inbounds [512 x [256 x i32]], ptr %1, i64 0, i64 %4, i64 %39
    Value* app41 = builder.CreateGEP
        (ArrayType::get(Type::getInt32Ty(context), 256), app1, 
         {ConstantInt::get(Type::getInt64Ty(context), 0), app4, app39});
    //store i32 %40, ptr %41, align 4, !tbaa !5
    builder.CreateStore(app40, app41);
    //%42 = getelementptr inbounds [512 x [256 x i32]], ptr %2, i64 0, i64 %4, i64 %39
    Value* app42 = builder.CreateGEP
        (ArrayType::get(Type::getInt32Ty(context), 256), app2, 
         {ConstantInt::get(Type::getInt64Ty(context), 0), app4, app39});
    //store i32 %40, ptr %42, align 4, !tbaa !5
    builder.CreateStore(app40, app42);
    //%43 = add nuw nsw i64 %39, 1
    Value* app43 = builder.CreateAdd
        (app39, ConstantInt::get(Type::getInt64Ty(context), 1), 
         "", true, true);
    //%44 = icmp eq i64 %43, 256
    Value* app44 = builder.CreateICmpEQ
        (app43, ConstantInt::get(Type::getInt64Ty(context), 256));
    //br i1 %44, label %35, label %38, !llvm.loop !15
    builder.CreateCondBr(app44, ABB35, ABB38);
//----------------------------------------------------------------

    app4->addIncoming(ConstantInt::get(Type::getInt64Ty(context), 0), ABB0);
    app4->addIncoming(app36, ABB35);
    app6->addIncoming(app7, ABB11);
    app6->addIncoming(app1, ABB35);
    app7->addIncoming(app6, ABB11);
    app7->addIncoming(app2, ABB35);
    app9->addIncoming(ConstantInt::get(Type::getInt64Ty(context), 0), ABB5);
    app9->addIncoming(app13, ABB12);
    app16->addIncoming(ConstantInt::get(Type::getInt64Ty(context), 0), ABB8);
    app16->addIncoming(app33, ABB15);
    app39->addIncoming(ConstantInt::get(Type::getInt64Ty(context), 0), ABB3);
    app39->addIncoming(app43, ABB38);

//----------------------------------------------------------------


    module->print(outs(), nullptr);

    outs() << "Running code...\n";
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();

    ExecutionEngine* ee = EngineBuilder(std::unique_ptr<Module>(module)).create();
    ee->InstallLazyFunctionCreator([&](const std::string& fnName) -> void* {
        if (fnName == "simPutPixel") {
            return reinterpret_cast<void *>(simPutPixel);
        }
        if (fnName == "simFlush") {
            return reinterpret_cast<void *>(simFlush);
        }
        if (fnName == "simRand") {
            return reinterpret_cast<void *>(simRand);
        }
        return nullptr;
    });
    ee->finalizeObject();

    simInit();

    ArrayRef<GenericValue> noargs;
    GenericValue v = ee->runFunction(appFunc, noargs);
    outs() << "Code was run.\n";

    simExit();
    return EXIT_SUCCESS;
}