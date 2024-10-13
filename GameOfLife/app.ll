; ModuleID = 'app.c'
source_filename = "app.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: mustprogress nofree norecurse nosync nounwind willreturn memory(argmem: read) uwtable
define dso_local i32 @countLivingNeighbors(i32 noundef %0, i32 noundef %1, ptr nocapture noundef readonly %2) local_unnamed_addr #0 {
  %4 = add nsw i32 %0, -1
  %5 = add nsw i32 %1, -1
  %6 = icmp ugt i32 %4, 511
  br i1 %6, label %44, label %9

7:                                                ; preds = %102, %98, %71
  %8 = phi i32 [ %72, %71 ], [ %99, %98 ], [ %110, %102 ]
  ret i32 %8

9:                                                ; preds = %3
  %10 = icmp ugt i32 %5, 255
  br i1 %10, label %19, label %11

11:                                               ; preds = %9
  %12 = shl nuw nsw i32 %5, 9
  %13 = or disjoint i32 %12, %4
  %14 = zext nneg i32 %13 to i64
  %15 = getelementptr inbounds i32, ptr %2, i64 %14
  %16 = load i32, ptr %15, align 4, !tbaa !5
  %17 = icmp ne i32 %16, 0
  %18 = zext i1 %17 to i32
  br label %19

19:                                               ; preds = %9, %11
  %20 = phi i32 [ 0, %9 ], [ %18, %11 ]
  %21 = icmp ugt i32 %1, 255
  br i1 %21, label %31, label %22

22:                                               ; preds = %19
  %23 = shl nuw nsw i32 %1, 9
  %24 = or disjoint i32 %23, %4
  %25 = zext nneg i32 %24 to i64
  %26 = getelementptr inbounds i32, ptr %2, i64 %25
  %27 = load i32, ptr %26, align 4, !tbaa !5
  %28 = icmp ne i32 %27, 0
  %29 = zext i1 %28 to i32
  %30 = add nuw nsw i32 %20, %29
  br label %31

31:                                               ; preds = %22, %19
  %32 = phi i32 [ %20, %19 ], [ %30, %22 ]
  %33 = add nsw i32 %1, 1
  %34 = icmp ugt i32 %33, 255
  br i1 %34, label %44, label %35

35:                                               ; preds = %31
  %36 = shl nuw nsw i32 %33, 9
  %37 = or disjoint i32 %36, %4
  %38 = zext nneg i32 %37 to i64
  %39 = getelementptr inbounds i32, ptr %2, i64 %38
  %40 = load i32, ptr %39, align 4, !tbaa !5
  %41 = icmp ne i32 %40, 0
  %42 = zext i1 %41 to i32
  %43 = add nuw nsw i32 %32, %42
  br label %44

44:                                               ; preds = %3, %31, %35
  %45 = phi i32 [ 0, %3 ], [ %32, %31 ], [ %43, %35 ]
  %46 = icmp ugt i32 %0, 511
  br i1 %46, label %71, label %47

47:                                               ; preds = %44
  %48 = icmp ugt i32 %5, 255
  br i1 %48, label %58, label %49

49:                                               ; preds = %47
  %50 = shl nuw nsw i32 %5, 9
  %51 = or disjoint i32 %50, %0
  %52 = zext nneg i32 %51 to i64
  %53 = getelementptr inbounds i32, ptr %2, i64 %52
  %54 = load i32, ptr %53, align 4, !tbaa !5
  %55 = icmp ne i32 %54, 0
  %56 = zext i1 %55 to i32
  %57 = add nuw nsw i32 %45, %56
  br label %58

58:                                               ; preds = %49, %47
  %59 = phi i32 [ %45, %47 ], [ %57, %49 ]
  %60 = add nsw i32 %1, 1
  %61 = icmp ugt i32 %60, 255
  br i1 %61, label %71, label %62

62:                                               ; preds = %58
  %63 = shl nuw nsw i32 %60, 9
  %64 = or disjoint i32 %63, %0
  %65 = zext nneg i32 %64 to i64
  %66 = getelementptr inbounds i32, ptr %2, i64 %65
  %67 = load i32, ptr %66, align 4, !tbaa !5
  %68 = icmp ne i32 %67, 0
  %69 = zext i1 %68 to i32
  %70 = add nuw nsw i32 %59, %69
  br label %71

71:                                               ; preds = %62, %58, %44
  %72 = phi i32 [ %45, %44 ], [ %59, %58 ], [ %70, %62 ]
  %73 = add nsw i32 %0, 1
  %74 = icmp ugt i32 %73, 511
  br i1 %74, label %7, label %75

75:                                               ; preds = %71
  %76 = icmp ugt i32 %5, 255
  br i1 %76, label %86, label %77

77:                                               ; preds = %75
  %78 = shl nuw nsw i32 %5, 9
  %79 = or disjoint i32 %78, %73
  %80 = zext nneg i32 %79 to i64
  %81 = getelementptr inbounds i32, ptr %2, i64 %80
  %82 = load i32, ptr %81, align 4, !tbaa !5
  %83 = icmp ne i32 %82, 0
  %84 = zext i1 %83 to i32
  %85 = add nuw nsw i32 %72, %84
  br label %86

86:                                               ; preds = %75, %77
  %87 = phi i32 [ %72, %75 ], [ %85, %77 ]
  %88 = icmp ugt i32 %1, 255
  br i1 %88, label %98, label %89

89:                                               ; preds = %86
  %90 = shl nuw nsw i32 %1, 9
  %91 = or disjoint i32 %90, %73
  %92 = zext nneg i32 %91 to i64
  %93 = getelementptr inbounds i32, ptr %2, i64 %92
  %94 = load i32, ptr %93, align 4, !tbaa !5
  %95 = icmp ne i32 %94, 0
  %96 = zext i1 %95 to i32
  %97 = add nuw nsw i32 %87, %96
  br label %98

98:                                               ; preds = %89, %86
  %99 = phi i32 [ %87, %86 ], [ %97, %89 ]
  %100 = add nsw i32 %1, 1
  %101 = icmp ugt i32 %100, 255
  br i1 %101, label %7, label %102

102:                                              ; preds = %98
  %103 = shl nuw nsw i32 %100, 9
  %104 = or disjoint i32 %103, %73
  %105 = zext nneg i32 %104 to i64
  %106 = getelementptr inbounds i32, ptr %2, i64 %105
  %107 = load i32, ptr %106, align 4, !tbaa !5
  %108 = icmp ne i32 %107, 0
  %109 = zext i1 %108 to i32
  %110 = add nuw nsw i32 %99, %109
  br label %7
}

; Function Attrs: mustprogress nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.start.p0(i64 immarg, ptr nocapture) #1

; Function Attrs: mustprogress nofree norecurse nosync nounwind willreturn memory(argmem: readwrite) uwtable
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

; Function Attrs: mustprogress nofree norecurse nosync nounwind willreturn memory(argmem: readwrite) uwtable
define dso_local void @swapPixels(ptr nocapture noundef %0, ptr nocapture noundef %1) local_unnamed_addr #2 {
  %3 = load ptr, ptr %0, align 8, !tbaa !9
  %4 = load ptr, ptr %1, align 8, !tbaa !9
  store ptr %4, ptr %0, align 8, !tbaa !9
  store ptr %3, ptr %1, align 8, !tbaa !9
  ret void
}

; Function Attrs: noreturn nounwind uwtable
define dso_local void @gameOfLife(ptr nocapture noundef %0, ptr nocapture noundef %1) local_unnamed_addr #3 {
  br label %3

3:                                                ; preds = %2, %9
  %4 = phi ptr [ %0, %2 ], [ %5, %9 ]
  %5 = phi ptr [ %1, %2 ], [ %4, %9 ]
  br label %6

6:                                                ; preds = %3, %10
  %7 = phi i64 [ 0, %3 ], [ %11, %10 ]
  %8 = trunc i64 %7 to i32
  br label %13

9:                                                ; preds = %10
  tail call void (...) @simFlush() #6
  br label %3

10:                                               ; preds = %13
  %11 = add nuw nsw i64 %7, 1
  %12 = icmp eq i64 %11, 512
  br i1 %12, label %9, label %6, !llvm.loop !11

13:                                               ; preds = %6, %13
  %14 = phi i64 [ 0, %6 ], [ %31, %13 ]
  %15 = shl nuw nsw i64 %14, 9
  %16 = or disjoint i64 %15, %7
  %17 = getelementptr inbounds i32, ptr %4, i64 %16
  %18 = load i32, ptr %17, align 4, !tbaa !5
  %19 = icmp eq i32 %18, 0
  %20 = select i1 %19, i32 -16777216, i32 16711680
  %21 = trunc i64 %14 to i32
  tail call void @simPutPixel(i32 noundef %8, i32 noundef %21, i32 noundef %20) #6
  %22 = tail call i32 @countLivingNeighbors(i32 noundef %8, i32 noundef %21, ptr noundef %4)
  %23 = load i32, ptr %17, align 4, !tbaa !5
  %24 = icmp eq i32 %23, 1
  %25 = and i32 %22, -2
  %26 = icmp eq i32 %25, 2
  %27 = icmp eq i32 %22, 3
  %28 = select i1 %24, i1 %26, i1 %27
  %29 = zext i1 %28 to i32
  %30 = getelementptr inbounds i32, ptr %5, i64 %16
  store i32 %29, ptr %30, align 4
  %31 = add nuw nsw i64 %14, 1
  %32 = icmp eq i64 %31, 256
  br i1 %32, label %10, label %13, !llvm.loop !13
}

declare void @simPutPixel(i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #4

declare void @simFlush(...) local_unnamed_addr #4

; Function Attrs: noreturn nounwind uwtable
define dso_local void @app() local_unnamed_addr #3 {
  %1 = alloca [512 x [256 x i32]], align 16
  %2 = alloca [512 x [256 x i32]], align 16
  call void @llvm.lifetime.start.p0(i64 524288, ptr nonnull %1) #6
  call void @llvm.memset.p0.i64(ptr noundef nonnull align 16 dereferenceable(524288) %1, i8 0, i64 524288, i1 false)
  call void @llvm.lifetime.start.p0(i64 524288, ptr nonnull %2) #6
  call void @llvm.memset.p0.i64(ptr noundef nonnull align 16 dereferenceable(524288) %2, i8 0, i64 524288, i1 false)
  br label %3

3:                                                ; preds = %0, %35
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
  tail call void (...) @simFlush() #6
  br label %5

12:                                               ; preds = %15
  %13 = add nuw nsw i64 %9, 1
  %14 = icmp eq i64 %13, 512
  br i1 %14, label %11, label %8, !llvm.loop !11

15:                                               ; preds = %15, %8
  %16 = phi i64 [ 0, %8 ], [ %33, %15 ]
  %17 = shl nuw nsw i64 %16, 9
  %18 = add nuw nsw i64 %17, %9
  %19 = getelementptr inbounds i32, ptr %6, i64 %18
  %20 = load i32, ptr %19, align 4, !tbaa !5
  %21 = icmp eq i32 %20, 0
  %22 = select i1 %21, i32 -16777216, i32 16711680
  %23 = trunc i64 %16 to i32
  tail call void @simPutPixel(i32 noundef %10, i32 noundef %23, i32 noundef %22) #6
  %24 = call i32 @countLivingNeighbors(i32 noundef %10, i32 noundef %23, ptr noundef nonnull %6)
  %25 = load i32, ptr %19, align 4, !tbaa !5
  %26 = icmp eq i32 %25, 1
  %27 = and i32 %24, -2
  %28 = icmp eq i32 %27, 2
  %29 = icmp eq i32 %24, 3
  %30 = select i1 %26, i1 %28, i1 %29
  %31 = zext i1 %30 to i32
  %32 = getelementptr inbounds i32, ptr %7, i64 %18
  store i32 %31, ptr %32, align 4
  %33 = add nuw nsw i64 %16, 1
  %34 = icmp eq i64 %33, 256
  br i1 %34, label %12, label %15, !llvm.loop !13

35:                                               ; preds = %38
  %36 = add nuw nsw i64 %4, 1
  %37 = icmp eq i64 %36, 512
  br i1 %37, label %5, label %3, !llvm.loop !14

38:                                               ; preds = %3, %38
  %39 = phi i64 [ 0, %3 ], [ %43, %38 ]
  %40 = tail call i32 (...) @simRand() #6
  %41 = getelementptr inbounds [512 x [256 x i32]], ptr %1, i64 0, i64 %4, i64 %39
  store i32 %40, ptr %41, align 4, !tbaa !5
  %42 = getelementptr inbounds [512 x [256 x i32]], ptr %2, i64 0, i64 %4, i64 %39
  store i32 %40, ptr %42, align 4, !tbaa !5
  %43 = add nuw nsw i64 %39, 1
  %44 = icmp eq i64 %43, 256
  br i1 %44, label %35, label %38, !llvm.loop !15
}

; Function Attrs: mustprogress nocallback nofree nounwind willreturn memory(argmem: write)
declare void @llvm.memset.p0.i64(ptr nocapture writeonly, i8, i64, i1 immarg) #5

declare i32 @simRand(...) local_unnamed_addr #4

attributes #0 = { mustprogress nofree norecurse nosync nounwind willreturn memory(argmem: read) uwtable "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { mustprogress nocallback nofree nosync nounwind willreturn memory(argmem: readwrite) }
attributes #2 = { mustprogress nofree norecurse nosync nounwind willreturn memory(argmem: readwrite) uwtable "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { noreturn nounwind uwtable "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #5 = { mustprogress nocallback nofree nounwind willreturn memory(argmem: write) }
attributes #6 = { nounwind }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{!"Ubuntu clang version 18.1.3 (1ubuntu1)"}
!5 = !{!6, !6, i64 0}
!6 = !{!"int", !7, i64 0}
!7 = !{!"omnipotent char", !8, i64 0}
!8 = !{!"Simple C/C++ TBAA"}
!9 = !{!10, !10, i64 0}
!10 = !{!"any pointer", !7, i64 0}
!11 = distinct !{!11, !12}
!12 = !{!"llvm.loop.mustprogress"}
!13 = distinct !{!13, !12}
!14 = distinct !{!14, !12}
!15 = distinct !{!15, !12}
