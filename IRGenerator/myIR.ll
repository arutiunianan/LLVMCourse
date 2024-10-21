; ModuleID = 'app.c'
source_filename = "app.c"

declare void @simPutPixel(i32, i32, i32)

declare void @simFlush(void)

declare i32 @simRand(void)

define i32 @countLivingNeighbors(i32 %0, i32 %1, ptr %2) {
  %4 = add i32 %0, -1
  %5 = add i32 %1, -1
  %6 = icmp ugt i32 %4, 511
  br i1 %6, label %44, label %9

7:                                                ; preds = %102, %98, %71
  %8 = phi i32 [ %72, %71 ], [ %99, %98 ], [ %110, %102 ]
  ret i32 %8

9:                                                ; preds = %3
  %10 = icmp ugt i32 %5, 255
  br i1 %10, label %19, label %11

11:                                               ; preds = %9
  %12 = shl i32 %5, 9
  %13 = or i32 %12, %4
  %14 = zext i32 %13 to i64
  %15 = getelementptr i32, ptr %2, i64 %14
  %16 = load i32, ptr %15, align 4
  %17 = icmp ne i32 %16, 0
  %18 = zext i1 %17 to i32
  br label %19

19:                                               ; preds = %11, %9
  %20 = phi i32 [ 0, %9 ], [ %18, %11 ]
  %21 = icmp ugt i32 %1, 255
  br i1 %21, label %31, label %22

22:                                               ; preds = %19
  %23 = shl i32 %1, 9
  %24 = or i32 %23, %4
  %25 = zext i32 %24 to i64
  %26 = getelementptr i32, ptr %2, i64 %25
  %27 = load i32, ptr %26, align 4
  %28 = icmp ne i32 %27, 0
  %29 = zext i1 %28 to i32
  %30 = add nuw nsw i32 %20, %29
  br label %31

31:                                               ; preds = %22, %19
  %32 = phi i32 [ %20, %19 ], [ %30, %22 ]
  %33 = add i32 %1, 1
  %34 = icmp ugt i32 %33, 255
  br i1 %34, label %44, label %35

35:                                               ; preds = %31
  %36 = shl i32 %33, 9
  %37 = or i32 %36, %4
  %38 = zext i32 %37 to i64
  %39 = getelementptr i32, ptr %2, i64 %38
  %40 = load i32, ptr %39, align 4
  %41 = icmp ne i32 %40, 0
  %42 = zext i1 %41 to i32
  %43 = add nuw nsw i32 %32, %42
  br label %44

44:                                               ; preds = %35, %31, %3
  %45 = phi i32 [ 0, %3 ], [ %32, %31 ], [ %43, %35 ]
  %46 = icmp ugt i32 %0, 511
  br i1 %46, label %71, label %47

47:                                               ; preds = %44
  %48 = icmp ugt i32 %5, 255
  br i1 %48, label %58, label %49

49:                                               ; preds = %47
  %50 = shl i32 %5, 9
  %51 = or i32 %50, %0
  %52 = zext i32 %51 to i64
  %53 = getelementptr i32, ptr %2, i64 %52
  %54 = load i32, ptr %53, align 4
  %55 = icmp ne i32 %54, 0
  %56 = zext i1 %55 to i32
  %57 = add nuw nsw i32 %45, %56
  br label %58

58:                                               ; preds = %49, %47
  %59 = phi i32 [ %45, %47 ], [ %57, %49 ]
  %60 = add i32 %1, 1
  %61 = icmp ugt i32 %60, 255
  br i1 %61, label %71, label %62

62:                                               ; preds = %58
  %63 = shl i32 %60, 9
  %64 = or i32 %63, %0
  %65 = zext i32 %64 to i64
  %66 = getelementptr i32, ptr %2, i64 %65
  %67 = load i32, ptr %66, align 4
  %68 = icmp ne i32 %67, 0
  %69 = zext i1 %68 to i32
  %70 = add nuw nsw i32 %59, %69
  br label %71

71:                                               ; preds = %62, %58, %44
  %72 = phi i32 [ %45, %44 ], [ %59, %58 ], [ %70, %62 ]
  %73 = add i32 %0, 1
  %74 = icmp ugt i32 %73, 511
  br i1 %74, label %7, label %75

75:                                               ; preds = %71
  %76 = icmp ugt i32 %5, 255
  br i1 %76, label %86, label %77

77:                                               ; preds = %75
  %78 = shl i32 %5, 9
  %79 = or i32 %78, %73
  %80 = zext i32 %79 to i64
  %81 = getelementptr i32, ptr %2, i64 %80
  %82 = load i32, ptr %81, align 4
  %83 = icmp ne i32 %82, 0
  %84 = zext i1 %83 to i32
  %85 = add nuw nsw i32 %72, %84
  br label %86

86:                                               ; preds = %77, %75
  %87 = phi i32 [ %72, %75 ], [ %85, %77 ]
  %88 = icmp ugt i32 %1, 255
  br i1 %88, label %98, label %89

89:                                               ; preds = %86
  %90 = shl i32 %1, 9
  %91 = or i32 %90, %73
  %92 = zext i32 %91 to i64
  %93 = getelementptr i32, ptr %2, i64 %92
  %94 = load i32, ptr %93, align 4
  %95 = icmp ne i32 %94, 0
  %96 = zext i1 %95 to i32
  %97 = add nuw nsw i32 %87, %96
  br label %98

98:                                               ; preds = %89, %86
  %99 = phi i32 [ %87, %86 ], [ %97, %89 ]
  %100 = add i32 %1, 1
  %101 = icmp ugt i32 %100, 255
  br i1 %101, label %7, label %102

102:                                              ; preds = %98
  %103 = shl i32 %100, 9
  %104 = or i32 %103, %73
  %105 = zext i32 %104 to i64
  %106 = getelementptr i32, ptr %2, i64 %105
  %107 = load i32, ptr %106, align 4
  %108 = icmp ne i32 %107, 0
  %109 = zext i1 %108 to i32
  %110 = add nuw nsw i32 %99, %109
  br label %7
}

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

define void @swapPixels(ptr %0, ptr %1) {
  %3 = load ptr, ptr %0, align 8
  %4 = load ptr, ptr %1, align 8
  store ptr %4, ptr %0, align 8
  store ptr %3, ptr %1, align 8
  ret void
}

define void @gameOfLife(ptr %0, ptr %1) {
  br label %3

3:                                                ; preds = %9, %2
  %4 = phi ptr [ %0, %2 ], [ %5, %9 ]
  %5 = phi ptr [ %1, %2 ], [ %4, %9 ]
  br label %6

6:                                                ; preds = %10, %3
  %7 = phi i64 [ 0, %3 ], [ %11, %10 ]
  %8 = trunc i64 %7 to i32
  br label %13

9:                                                ; preds = %10
  call void @simFlush()
  br label %3

10:                                               ; preds = %13
  %11 = add nuw nsw i64 %7, 1
  %12 = icmp eq i64 %11, 512
  br i1 %12, label %9, label %6

13:                                               ; preds = %13, %6
  %14 = phi i64 [ 0, %6 ], [ %31, %13 ]
  %15 = shl i64 %14, 9
  %16 = or i64 %15, %7
  %17 = getelementptr i32, ptr %4, i64 %16
  %18 = load i32, ptr %17, align 4
  %19 = icmp eq i32 %18, 0
  %20 = select i1 %19, i32 -16777216, i32 16711680
  %21 = trunc i64 %14 to i32
  call void @simPutPixel(i32 %8, i32 %21, i32 %20)
  %22 = call i32 @countLivingNeighbors(i32 %8, i32 %21, ptr %4)
  %23 = load i32, ptr %17, align 4
  %24 = icmp eq i32 %23, 1
  %25 = and i32 %22, -2
  %26 = icmp eq i32 %25, 2
  %27 = icmp eq i32 %22, 3
  %28 = select i1 %24, i1 %26, i1 %27
  %29 = zext i1 %28 to i32
  %30 = getelementptr i32, ptr %5, i64 %16
  store i32 %29, ptr %30, align 4
  %31 = add nuw nsw i64 %14, 1
  %32 = icmp eq i64 %31, 256
  br i1 %32, label %10, label %13
}

define void @app() {
  %1 = alloca [512 x [256 x i32]], align 4
  %2 = alloca [512 x [256 x i32]], align 4
  br label %3

3:                                                ; preds = %35, %0
  %4 = phi i64 [ 0, %0 ], [ %36, %35 ]
  br label %38

5:                                                ; preds = %35, %11
  %6 = phi ptr [ %7, %11 ], [ %1, %35 ]
  %7 = phi ptr [ %6, %11 ], [ %2, %35 ]
  br label %8

8:                                                ; preds = %12, %5
  %9 = phi i64 [ 0, %5 ], [ %13, %12 ]
  %10 = trunc i64 %9 to i32
  br label %15

11:                                               ; preds = %12
  call void @simFlush()
  br label %5

12:                                               ; preds = %15
  %13 = add nuw nsw i64 %9, 1
  %14 = icmp eq i64 %13, 512
  br i1 %14, label %11, label %8

15:                                               ; preds = %15, %8
  %16 = phi i64 [ 0, %8 ], [ %33, %15 ]
  %17 = shl i64 %16, 9
  %18 = add nuw nsw i64 %17, %9
  %19 = getelementptr i32, ptr %6, i64 %18
  %20 = load i32, ptr %19, align 4
  %21 = icmp eq i32 %20, 0
  %22 = select i1 %21, i32 -16777216, i32 16711680
  %23 = trunc i64 %16 to i32
  call void @simPutPixel(i32 %10, i32 %23, i32 %22)
  %24 = call i32 @countLivingNeighbors(i32 %10, i32 %23, ptr %6)
  %25 = load i32, ptr %19, align 4
  %26 = icmp eq i32 %25, 1
  %27 = and i32 %24, -2
  %28 = icmp eq i32 %27, 2
  %29 = icmp eq i32 %24, 3
  %30 = select i1 %26, i1 %28, i1 %29
  %31 = zext i1 %30 to i32
  %32 = getelementptr i32, ptr %7, i64 %18
  store i32 %31, ptr %32, align 4
  %33 = add nuw nsw i64 %16, 1
  %34 = icmp eq i64 %33, 256
  br i1 %34, label %12, label %15

35:                                               ; preds = %38
  %36 = add nuw nsw i64 %4, 1
  %37 = icmp eq i64 %36, 512
  br i1 %37, label %5, label %3

38:                                               ; preds = %38, %3
  %39 = phi i64 [ 0, %3 ], [ %43, %38 ]
  %40 = call i32 @simRand()
  %41 = getelementptr [512 x [256 x i32]], ptr %1, i64 0, i64 %4, i64 %39
  store i32 %40, ptr %41, align 4
  %42 = getelementptr [512 x [256 x i32]], ptr %2, i64 0, i64 %4, i64 %39
  store i32 %40, ptr %42, align 4
  %43 = add nuw nsw i64 %39, 1
  %44 = icmp eq i64 %43, 256
  br i1 %44, label %35, label %38
}
