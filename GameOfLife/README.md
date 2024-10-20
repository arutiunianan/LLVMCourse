# Game of life

Implementing my Game of life graphics application and generating IR for [app.c](./app.c)

### Program run

```
clang start.c sim.c app.c -lSDL2
./a.out
```

### IR generation
```
clang -S -emit-llvm app.c -o app.ll
```

### The result of my application:)
![](./for_readme/game.gif)