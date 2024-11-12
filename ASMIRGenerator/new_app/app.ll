; ModuleID = 'app.c'
source_filename = "app.c"
target datalayout = "e-m:o-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx11.0.0"

; Function Attrs: noreturn nounwind ssp uwtable
define void @app() local_unnamed_addr #0 {
  br label %1

1:                                                ; preds = %7, %0
  %2 = phi i32 [ 0, %0 ], [ %8, %7 ]
  br label %9

3:                                                ; preds = %4
  tail call void (...) @simFlush() #2
  br label %7

4:                                                ; preds = %9
  %5 = add nuw nsw i32 %2, 1
  %6 = icmp eq i32 %5, 512
  br i1 %6, label %3, label %7

7:                                                ; preds = %4, %3
  %8 = phi i32 [ %5, %4 ], [ 0, %3 ]
  br label %1

9:                                                ; preds = %9, %1
  %10 = phi i32 [ 0, %1 ], [ %19, %9 ]
  %11 = tail call i32 (...) @simRand() #2
  %12 = and i32 %11, 1
  %13 = icmp eq i32 %12, 0
  %14 = shl nuw nsw i32 %10, 9
  %15 = add nuw nsw i32 %14, %2
  %16 = shl nsw i32 %15, 7
  %17 = add nuw nsw i32 %16, 16711680
  %18 = select i1 %13, i32 -16777216, i32 %17
  tail call void @simPutPixel(i32 %2, i32 %10, i32 %18) #2
  %19 = add nuw nsw i32 %10, 1
  %20 = icmp eq i32 %19, 256
  br i1 %20, label %4, label %9
}

declare i32 @simRand(...) local_unnamed_addr #1

declare void @simPutPixel(i32, i32, i32) local_unnamed_addr #1

declare void @simFlush(...) local_unnamed_addr #1

attributes #0 = { noreturn nounwind ssp uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "darwin-stkchk-strong-link" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "probe-stack"="___chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "correctly-rounded-divide-sqrt-fp-math"="false" "darwin-stkchk-strong-link" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "probe-stack"="___chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind }

!llvm.module.flags = !{!0, !1, !2}
!llvm.ident = !{!3}

!0 = !{i32 2, !"SDK Version", [2 x i32] [i32 12, i32 1]}
!1 = !{i32 1, !"wchar_size", i32 4}
!2 = !{i32 7, !"PIC Level", i32 2}
!3 = !{!"Apple clang version 12.0.5 (clang-1205.0.22.11)"}
