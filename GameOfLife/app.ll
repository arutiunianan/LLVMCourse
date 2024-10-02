; ModuleID = 'app.c'
source_filename = "app.c"
target datalayout = "e-m:o-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx11.0.0"

; Function Attrs: noinline nounwind optnone ssp uwtable
define i32 @countLivingNeighbors(i32 %0, i32 %1, i32* %2) #0 {
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32*, align 8
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  store i32 %0, i32* %4, align 4
  store i32 %1, i32* %5, align 4
  store i32* %2, i32** %6, align 8
  store i32 0, i32* %7, align 4
  %10 = load i32, i32* %4, align 4
  %11 = sub nsw i32 %10, 1
  store i32 %11, i32* %8, align 4
  br label %12

12:                                               ; preds = %65, %3
  %13 = load i32, i32* %8, align 4
  %14 = load i32, i32* %4, align 4
  %15 = add nsw i32 %14, 1
  %16 = icmp sle i32 %13, %15
  br i1 %16, label %17, label %68

17:                                               ; preds = %12
  %18 = load i32, i32* %8, align 4
  %19 = icmp slt i32 %18, 0
  br i1 %19, label %23, label %20

20:                                               ; preds = %17
  %21 = load i32, i32* %8, align 4
  %22 = icmp sge i32 %21, 512
  br i1 %22, label %23, label %24

23:                                               ; preds = %20, %17
  br label %65

24:                                               ; preds = %20
  %25 = load i32, i32* %5, align 4
  %26 = sub nsw i32 %25, 1
  store i32 %26, i32* %9, align 4
  br label %27

27:                                               ; preds = %61, %24
  %28 = load i32, i32* %9, align 4
  %29 = load i32, i32* %5, align 4
  %30 = add nsw i32 %29, 1
  %31 = icmp sle i32 %28, %30
  br i1 %31, label %32, label %64

32:                                               ; preds = %27
  %33 = load i32, i32* %9, align 4
  %34 = icmp slt i32 %33, 0
  br i1 %34, label %46, label %35

35:                                               ; preds = %32
  %36 = load i32, i32* %9, align 4
  %37 = icmp sge i32 %36, 256
  br i1 %37, label %46, label %38

38:                                               ; preds = %35
  %39 = load i32, i32* %8, align 4
  %40 = load i32, i32* %4, align 4
  %41 = icmp eq i32 %39, %40
  br i1 %41, label %42, label %47

42:                                               ; preds = %38
  %43 = load i32, i32* %9, align 4
  %44 = load i32, i32* %5, align 4
  %45 = icmp eq i32 %43, %44
  br i1 %45, label %46, label %47

46:                                               ; preds = %42, %35, %32
  br label %61

47:                                               ; preds = %42, %38
  %48 = load i32*, i32** %6, align 8
  %49 = load i32, i32* %8, align 4
  %50 = load i32, i32* %9, align 4
  %51 = mul nsw i32 %50, 512
  %52 = add nsw i32 %49, %51
  %53 = sext i32 %52 to i64
  %54 = getelementptr inbounds i32, i32* %48, i64 %53
  %55 = load i32, i32* %54, align 4
  %56 = icmp ne i32 %55, 0
  br i1 %56, label %57, label %60

57:                                               ; preds = %47
  %58 = load i32, i32* %7, align 4
  %59 = add nsw i32 %58, 1
  store i32 %59, i32* %7, align 4
  br label %60

60:                                               ; preds = %57, %47
  br label %61

61:                                               ; preds = %60, %46
  %62 = load i32, i32* %9, align 4
  %63 = add nsw i32 %62, 1
  store i32 %63, i32* %9, align 4
  br label %27, !llvm.loop !4

64:                                               ; preds = %27
  br label %65

65:                                               ; preds = %64, %23
  %66 = load i32, i32* %8, align 4
  %67 = add nsw i32 %66, 1
  store i32 %67, i32* %8, align 4
  br label %12, !llvm.loop !6

68:                                               ; preds = %12
  %69 = load i32, i32* %7, align 4
  ret i32 %69
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define void @updatePixel(i32 %0, i32 %1, i32* %2, i32* %3) #0 {
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32*, align 8
  %8 = alloca i32*, align 8
  %9 = alloca i32, align 4
  store i32 %0, i32* %5, align 4
  store i32 %1, i32* %6, align 4
  store i32* %2, i32** %7, align 8
  store i32* %3, i32** %8, align 8
  %10 = load i32, i32* %5, align 4
  %11 = load i32, i32* %6, align 4
  %12 = load i32*, i32** %7, align 8
  %13 = call i32 @countLivingNeighbors(i32 %10, i32 %11, i32* %12)
  store i32 %13, i32* %9, align 4
  %14 = load i32*, i32** %7, align 8
  %15 = load i32, i32* %5, align 4
  %16 = load i32, i32* %6, align 4
  %17 = mul nsw i32 %16, 512
  %18 = add nsw i32 %15, %17
  %19 = sext i32 %18 to i64
  %20 = getelementptr inbounds i32, i32* %14, i64 %19
  %21 = load i32, i32* %20, align 4
  %22 = icmp eq i32 %21, 1
  br i1 %22, label %23, label %40

23:                                               ; preds = %4
  %24 = load i32, i32* %9, align 4
  %25 = icmp ne i32 %24, 2
  br i1 %25, label %26, label %29

26:                                               ; preds = %23
  %27 = load i32, i32* %9, align 4
  %28 = icmp ne i32 %27, 3
  br label %29

29:                                               ; preds = %26, %23
  %30 = phi i1 [ false, %23 ], [ %28, %26 ]
  %31 = zext i1 %30 to i64
  %32 = select i1 %30, i32 0, i32 1
  %33 = load i32*, i32** %8, align 8
  %34 = load i32, i32* %5, align 4
  %35 = load i32, i32* %6, align 4
  %36 = mul nsw i32 %35, 512
  %37 = add nsw i32 %34, %36
  %38 = sext i32 %37 to i64
  %39 = getelementptr inbounds i32, i32* %33, i64 %38
  store i32 %32, i32* %39, align 4
  br label %52

40:                                               ; preds = %4
  %41 = load i32, i32* %9, align 4
  %42 = icmp ne i32 %41, 3
  %43 = zext i1 %42 to i64
  %44 = select i1 %42, i32 0, i32 1
  %45 = load i32*, i32** %8, align 8
  %46 = load i32, i32* %5, align 4
  %47 = load i32, i32* %6, align 4
  %48 = mul nsw i32 %47, 512
  %49 = add nsw i32 %46, %48
  %50 = sext i32 %49 to i64
  %51 = getelementptr inbounds i32, i32* %45, i64 %50
  store i32 %44, i32* %51, align 4
  br label %52

52:                                               ; preds = %40, %29
  ret void
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define void @swapPixels(i32** %0, i32** %1) #0 {
  %3 = alloca i32**, align 8
  %4 = alloca i32**, align 8
  %5 = alloca i32*, align 8
  store i32** %0, i32*** %3, align 8
  store i32** %1, i32*** %4, align 8
  %6 = load i32**, i32*** %3, align 8
  %7 = load i32*, i32** %6, align 8
  store i32* %7, i32** %5, align 8
  %8 = load i32**, i32*** %4, align 8
  %9 = load i32*, i32** %8, align 8
  %10 = load i32**, i32*** %3, align 8
  store i32* %9, i32** %10, align 8
  %11 = load i32*, i32** %5, align 8
  %12 = load i32**, i32*** %4, align 8
  store i32* %11, i32** %12, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define void @gameOfLife(i32* %0, i32* %1) #0 {
  %3 = alloca i32*, align 8
  %4 = alloca i32*, align 8
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  store i32* %0, i32** %3, align 8
  store i32* %1, i32** %4, align 8
  br label %7

7:                                                ; preds = %2, %40
  store i32 0, i32* %5, align 4
  br label %8

8:                                                ; preds = %37, %7
  %9 = load i32, i32* %5, align 4
  %10 = icmp slt i32 %9, 512
  br i1 %10, label %11, label %40

11:                                               ; preds = %8
  store i32 0, i32* %6, align 4
  br label %12

12:                                               ; preds = %33, %11
  %13 = load i32, i32* %6, align 4
  %14 = icmp slt i32 %13, 256
  br i1 %14, label %15, label %36

15:                                               ; preds = %12
  %16 = load i32, i32* %5, align 4
  %17 = load i32, i32* %6, align 4
  %18 = load i32*, i32** %3, align 8
  %19 = load i32, i32* %5, align 4
  %20 = load i32, i32* %6, align 4
  %21 = mul nsw i32 %20, 512
  %22 = add nsw i32 %19, %21
  %23 = sext i32 %22 to i64
  %24 = getelementptr inbounds i32, i32* %18, i64 %23
  %25 = load i32, i32* %24, align 4
  %26 = icmp ne i32 %25, 0
  %27 = zext i1 %26 to i64
  %28 = select i1 %26, i32 16711680, i32 -16777216
  call void @simPutPixel(i32 %16, i32 %17, i32 %28)
  %29 = load i32, i32* %5, align 4
  %30 = load i32, i32* %6, align 4
  %31 = load i32*, i32** %3, align 8
  %32 = load i32*, i32** %4, align 8
  call void @updatePixel(i32 %29, i32 %30, i32* %31, i32* %32)
  br label %33

33:                                               ; preds = %15
  %34 = load i32, i32* %6, align 4
  %35 = add nsw i32 %34, 1
  store i32 %35, i32* %6, align 4
  br label %12, !llvm.loop !7

36:                                               ; preds = %12
  br label %37

37:                                               ; preds = %36
  %38 = load i32, i32* %5, align 4
  %39 = add nsw i32 %38, 1
  store i32 %39, i32* %5, align 4
  br label %8, !llvm.loop !8

40:                                               ; preds = %8
  call void @swapPixels(i32** %3, i32** %4)
  call void (...) @simFlush()
  br label %7
}

declare void @simPutPixel(i32, i32, i32) #1

declare void @simFlush(...) #1

; Function Attrs: noinline nounwind optnone ssp uwtable
define void @app() #0 {
  %1 = alloca [512 x [256 x i32]], align 16
  %2 = alloca [512 x [256 x i32]], align 16
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = bitcast [512 x [256 x i32]]* %1 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %5, i8 0, i64 524288, i1 false)
  %6 = bitcast [512 x [256 x i32]]* %2 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %6, i8 0, i64 524288, i1 false)
  store i32 0, i32* %3, align 4
  br label %7

7:                                                ; preds = %39, %0
  %8 = load i32, i32* %3, align 4
  %9 = icmp slt i32 %8, 512
  br i1 %9, label %10, label %42

10:                                               ; preds = %7
  store i32 0, i32* %4, align 4
  br label %11

11:                                               ; preds = %35, %10
  %12 = load i32, i32* %4, align 4
  %13 = icmp slt i32 %12, 256
  br i1 %13, label %14, label %38

14:                                               ; preds = %11
  %15 = call i32 (...) @simRand()
  %16 = load i32, i32* %3, align 4
  %17 = sext i32 %16 to i64
  %18 = getelementptr inbounds [512 x [256 x i32]], [512 x [256 x i32]]* %1, i64 0, i64 %17
  %19 = load i32, i32* %4, align 4
  %20 = sext i32 %19 to i64
  %21 = getelementptr inbounds [256 x i32], [256 x i32]* %18, i64 0, i64 %20
  store i32 %15, i32* %21, align 4
  %22 = load i32, i32* %3, align 4
  %23 = sext i32 %22 to i64
  %24 = getelementptr inbounds [512 x [256 x i32]], [512 x [256 x i32]]* %1, i64 0, i64 %23
  %25 = load i32, i32* %4, align 4
  %26 = sext i32 %25 to i64
  %27 = getelementptr inbounds [256 x i32], [256 x i32]* %24, i64 0, i64 %26
  %28 = load i32, i32* %27, align 4
  %29 = load i32, i32* %3, align 4
  %30 = sext i32 %29 to i64
  %31 = getelementptr inbounds [512 x [256 x i32]], [512 x [256 x i32]]* %2, i64 0, i64 %30
  %32 = load i32, i32* %4, align 4
  %33 = sext i32 %32 to i64
  %34 = getelementptr inbounds [256 x i32], [256 x i32]* %31, i64 0, i64 %33
  store i32 %28, i32* %34, align 4
  br label %35

35:                                               ; preds = %14
  %36 = load i32, i32* %4, align 4
  %37 = add nsw i32 %36, 1
  store i32 %37, i32* %4, align 4
  br label %11, !llvm.loop !9

38:                                               ; preds = %11
  br label %39

39:                                               ; preds = %38
  %40 = load i32, i32* %3, align 4
  %41 = add nsw i32 %40, 1
  store i32 %41, i32* %3, align 4
  br label %7, !llvm.loop !10

42:                                               ; preds = %7
  %43 = getelementptr inbounds [512 x [256 x i32]], [512 x [256 x i32]]* %1, i64 0, i64 0
  %44 = bitcast [256 x i32]* %43 to i32*
  %45 = getelementptr inbounds [512 x [256 x i32]], [512 x [256 x i32]]* %2, i64 0, i64 0
  %46 = bitcast [256 x i32]* %45 to i32*
  call void @gameOfLife(i32* %44, i32* %46)
  ret void
}

; Function Attrs: argmemonly nofree nosync nounwind willreturn writeonly
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #2

declare i32 @simRand(...) #1

attributes #0 = { noinline nounwind optnone ssp uwtable "darwin-stkchk-strong-link" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "probe-stack"="___chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "tune-cpu"="generic" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "darwin-stkchk-strong-link" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "probe-stack"="___chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "tune-cpu"="generic" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { argmemonly nofree nosync nounwind willreturn writeonly }

!llvm.module.flags = !{!0, !1, !2}
!llvm.ident = !{!3}

!0 = !{i32 2, !"SDK Version", [2 x i32] [i32 11, i32 3]}
!1 = !{i32 1, !"wchar_size", i32 4}
!2 = !{i32 7, !"PIC Level", i32 2}
!3 = !{!"Apple clang version 13.0.0 (clang-1300.0.29.3)"}
!4 = distinct !{!4, !5}
!5 = !{!"llvm.loop.mustprogress"}
!6 = distinct !{!6, !5}
!7 = distinct !{!7, !5}
!8 = distinct !{!8, !5}
!9 = distinct !{!9, !5}
!10 = distinct !{!10, !5}
