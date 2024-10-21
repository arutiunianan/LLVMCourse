# IR Generator

Created a program to generate IR in the order of description of LLVM IR

1. Context
2. IR Builder
3. Module:
    1. Global elements
    2. Create functions (external and internal) 
    3. Describe the internal functions
        1. Create all the base blocks
        2. Describe the basic blocks:
            1. Insert IRBuilder
            2. Create instructions
        3. Link PHI nodes (after all base blocks)


### Program run

```

clang++ $(llvm-config --cppflags --ldflags --libs) ../GameOfLife/sim.c IRGenerator.cpp -lSDL2 -I/usr/include/SDL2
./a.out

```

## Versus-battle

Let's compare the one I generated [.ll file](./myIR.ll):

```

define void @updatePixel(i32 %0, i32 %1, ptr %2, ptr %3) {
  %5 = call i32 @countLivingNeighbors(i32 %0, i32 %1, ptr %2)
  %6 = shl i32 %1, 9
  %7 = add nuw nsw i32 %6, %0
  %8 = sext i32 %7 to i64
  %9 = getelementptr i32, ptr %2, i64 %8
  %10 = load i32, ptr %9, align 4
  %11 = icmp eq i32 %10, 1
  %12 = and i32 %5, -2
  %13 = icmp eq i32 %12, 2
  %14 = icmp eq i32 %5, 3
  %15 = select i1 %11, i1 %13, i1 %14
  %16 = zext i1 %15 to i32
  %17 = getelementptr i32, ptr %3, i64 %8
  store i32 %16, ptr %17, align 4
  ret void
}

```

and the one generated earlier [.ll file](../GameOfLife/app.ll):

```
define dso_local void @updatePixel(i32 noundef %0, i32 noundef %1, ptr nocapture noundef readonly %2, ptr nocapture noundef writeonly %3) local_unnamed_addr #2 {
  %5 = tail call i32 @countLivingNeighbors(i32 noundef %0, i32 noundef %1, ptr noundef %2)
  %6 = shl nsw i32 %1, 9
  %7 = add nsw i32 %6, %0
  %8 = sext i32 %7 to i64
  %9 = getelementptr inbounds i32, ptr %2, i64 %8
  %10 = load i32, ptr %9, align 4, !tbaa !5
  %11 = icmp eq i32 %10, 1
  %12 = and i32 %5, -2
  %13 = icmp eq i32 %12, 2
  %14 = icmp eq i32 %5, 3
  %15 = select i1 %11, i1 %13, i1 %14
  %16 = zext i1 %15 to i32
  %17 = getelementptr inbounds i32, ptr %3, i64 %8
  store i32 %16, ptr %17, align 4
  ret void
}

```

As we can see, the differences are minimal and do not affect the operation of our graphical application in any way.