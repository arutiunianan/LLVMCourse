; ModuleID = 'app.c'
source_filename = "app.c"
target datalayout = "e-m:o-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx11.0.0"

@.str = private unnamed_addr constant [24 x i8] c"../for_readme/1alb8.png\00", align 1
@.str.1 = private unnamed_addr constant [24 x i8] c"../for_readme/2alb8.png\00", align 1
@.str.2 = private unnamed_addr constant [24 x i8] c"../for_readme/3alb8.png\00", align 1
@.str.3 = private unnamed_addr constant [24 x i8] c"../for_readme/4alb8.png\00", align 1
@.str.4 = private unnamed_addr constant [24 x i8] c"../for_readme/5alb8.png\00", align 1

; Function Attrs: noinline nounwind optnone ssp uwtable
define void @app() #0 {
  %1 = alloca i8*, align 8
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  br label %7

7:                                                ; preds = %0, %51
  store i8* getelementptr inbounds ([24 x i8], [24 x i8]* @.str, i64 0, i64 0), i8** %1, align 8
  %8 = load i8*, i8** %1, align 8
  call void @simGetPic(i8* %8)
  store i32 0, i32* %2, align 4
  br label %9

9:                                                ; preds = %13, %7
  %10 = load i32, i32* %2, align 4
  %11 = icmp slt i32 %10, 350
  br i1 %11, label %12, label %16

12:                                               ; preds = %9
  call void (...) @simFlush()
  br label %13

13:                                               ; preds = %12
  %14 = load i32, i32* %2, align 4
  %15 = add nsw i32 %14, 1
  store i32 %15, i32* %2, align 4
  br label %9

16:                                               ; preds = %9
  store i8* getelementptr inbounds ([24 x i8], [24 x i8]* @.str.1, i64 0, i64 0), i8** %1, align 8
  %17 = load i8*, i8** %1, align 8
  call void @simGetPic(i8* %17)
  store i32 0, i32* %3, align 4
  br label %18

18:                                               ; preds = %21, %16
  %19 = load i32, i32* %3, align 4
  %20 = icmp slt i32 %19, 350
  br i1 %20, label %21, label %24

21:                                               ; preds = %18
  call void (...) @simFlush()
  %22 = load i32, i32* %3, align 4
  %23 = add nsw i32 %22, 1
  store i32 %23, i32* %3, align 4
  br label %18

24:                                               ; preds = %18
  store i8* getelementptr inbounds ([24 x i8], [24 x i8]* @.str.2, i64 0, i64 0), i8** %1, align 8
  %25 = load i8*, i8** %1, align 8
  call void @simGetPic(i8* %25)
  store i32 0, i32* %4, align 4
  br label %26

26:                                               ; preds = %30, %24
  %27 = load i32, i32* %4, align 4
  %28 = icmp slt i32 %27, 350
  br i1 %28, label %29, label %33

29:                                               ; preds = %26
  call void (...) @simFlush()
  br label %30

30:                                               ; preds = %29
  %31 = load i32, i32* %4, align 4
  %32 = add nsw i32 %31, 1
  store i32 %32, i32* %4, align 4
  br label %26

33:                                               ; preds = %26
  store i8* getelementptr inbounds ([24 x i8], [24 x i8]* @.str.3, i64 0, i64 0), i8** %1, align 8
  %34 = load i8*, i8** %1, align 8
  call void @simGetPic(i8* %34)
  store i32 0, i32* %5, align 4
  br label %35

35:                                               ; preds = %39, %33
  %36 = load i32, i32* %5, align 4
  %37 = icmp slt i32 %36, 350
  br i1 %37, label %38, label %42

38:                                               ; preds = %35
  call void (...) @simFlush()
  br label %39

39:                                               ; preds = %38
  %40 = load i32, i32* %5, align 4
  %41 = add nsw i32 %40, 1
  store i32 %41, i32* %5, align 4
  br label %35

42:                                               ; preds = %35
  store i8* getelementptr inbounds ([24 x i8], [24 x i8]* @.str.4, i64 0, i64 0), i8** %1, align 8
  %43 = load i8*, i8** %1, align 8
  call void @simGetPic(i8* %43)
  store i32 0, i32* %6, align 4
  br label %44

44:                                               ; preds = %48, %42
  %45 = load i32, i32* %6, align 4
  %46 = icmp slt i32 %45, 350
  br i1 %46, label %47, label %51

47:                                               ; preds = %44
  call void (...) @simFlush()
  br label %48

48:                                               ; preds = %47
  %49 = load i32, i32* %6, align 4
  %50 = add nsw i32 %49, 1
  store i32 %50, i32* %6, align 4
  br label %44

51:                                               ; preds = %44
  br label %7
}

declare void @simGetPic(i8*) #1

declare void @simFlush(...) #1

attributes #0 = { noinline nounwind optnone ssp uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "darwin-stkchk-strong-link" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "probe-stack"="___chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "correctly-rounded-divide-sqrt-fp-math"="false" "darwin-stkchk-strong-link" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "probe-stack"="___chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0, !1, !2}
!llvm.ident = !{!3}

!0 = !{i32 2, !"SDK Version", [2 x i32] [i32 12, i32 1]}
!1 = !{i32 1, !"wchar_size", i32 4}
!2 = !{i32 7, !"PIC Level", i32 2}
!3 = !{!"Apple clang version 12.0.5 (clang-1205.0.22.11)"}
