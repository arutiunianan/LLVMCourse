; ModuleID = 'top'
source_filename = "top"

@regFile = external global [30 x i32]

define void @main() {
app:
  store i32 0, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 1), align 4
  br label %label_1

label_1:                                          ; preds = %label_7, %app
  store i32 0, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 2), align 4
  br label %label_9

label_9:                                          ; preds = %put_pixel, %label_1
  %0 = call i32 @simRand()
  store i32 %0, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 3), align 4
  %1 = load i32, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 3), align 4
  %2 = and i32 %1, 1
  store i32 %2, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 3), align 4
  %3 = load i32, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 3), align 4
  %4 = icmp eq i32 %3, 0
  store i1 %4, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 29), align 1
  %5 = load i32, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 29), align 4
  %6 = trunc i32 %5 to i1
  br i1 %6, label %set_black, label %set_coloful

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

set_black:                                        ; preds = %label_9
  store i32 -16777216, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 4), align 4
  br label %put_pixel

put_pixel:                                        ; preds = %set_black, %set_coloful
  %18 = load i32, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 1), align 4
  %19 = load i32, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 2), align 4
  %20 = load i32, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 4), align 4
  call void @simPutPixel(i32 %18, i32 %19, i32 %20)
  %21 = load i32, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 2), align 4
  %22 = add i32 %21, 1
  store i32 %22, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 2), align 4
  %23 = load i32, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 2), align 4
  %24 = icmp eq i32 %23, 256
  store i1 %24, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 29), align 1
  %25 = load i32, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 29), align 4
  %26 = trunc i32 %25 to i1
  br i1 %26, label %label_4, label %label_9

label_4:                                          ; preds = %put_pixel
  %27 = load i32, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 1), align 4
  %28 = add i32 %27, 1
  store i32 %28, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 1), align 4
  %29 = load i32, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 1), align 4
  %30 = icmp eq i32 %29, 512
  store i1 %30, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 29), align 1
  %31 = load i32, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 29), align 4
  %32 = trunc i32 %31 to i1
  br i1 %32, label %flush, label %label_7

flush:                                            ; preds = %label_4
  call void @simFlush()
  store i32 0, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 1), align 4
  br label %label_7

label_7:                                          ; preds = %flush, %label_4
  br label %label_1
}

declare void @simPutPixel(i32, i32, i32)

declare void @simFlush()

declare i32 @simRand(void)

