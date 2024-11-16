# ASM IR generator

I created a new graphical [application](./new_app/app.c) that displays colored dots in random places on the screen:

![](./for_readme/game.gif)

For this application, I created a program in my assembly language and generated llvm ir for.

### Program run

```
clang++ $(llvm-config --cppflags --ldflags --libs) new_app/sim.c ASMIRGenerator1.cpp -lSDL2
./a.out app.s
```

```
clang++ $(llvm-config --cppflags --ldflags --libs) new_app/sim.c ASMIRGenerator2.cpp -lSDL2
./a.out app.s
```

## Versus-battle

Let's compare the one I generated [.ll file](./myIR1.ll) using functions in c:

```
set_coloful:                                      ; preds = %label_9
  call void @do_mov(i32 4, i32 2)
  call void @do_shl(i32 4, i32 9)
  call void @do_add(i32 4, i32 1)
  call void @do_shl(i32 4, i32 7)
  call void @do_addconst(i32 4, i32 16711680)
  br label %put_pixel
```

[.ll file](./myIR2.ll) without auxiliary с functions:

```
set_coloful:                                      ; preds = %label_9
  %7 = load i32, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 2), align 4
  store i32 %7, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 4), align 4
  %8 = load i32, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 4), align 4
  %9 = shl i32 %8, 9
  store i32 %9, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 4), align 4
  %10 = load i32, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 4), align 4
  %11 = load i32, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 1), align 4
  %12 = add i32 %10, %11
  store i32 %12, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 4), align 4
  %13 = load i32, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 4), align 4
  %14 = shl i32 %13, 7
  store i32 %14, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 4), align 4
  %15 = load i32, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 4), align 4
  %16 = load i32, ptr getelementptr ([30 x i32], ptr @regFile, i64 223722, i32 20), align 4
  %17 = add i32 %15, %16
  store i32 %17, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 4), align 4
  br label %put_pixel
```

Yes, the second option turned out to be more voluminous, but it is much closer to the generated one [.ll](./new_app/app.ll) file:)
