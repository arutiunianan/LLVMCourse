; ModuleID = 'top'
source_filename = "top"

@regFile = external global [30 x i32]

define void @main() {
app:
  call void @do_movconst(i32 1, i32 0)
  br label %label_1

label_1:                                          ; preds = %label_7, %app
  call void @do_movconst(i32 2, i32 0)
  br label %label_9

label_9:                                          ; preds = %put_pixel, %label_1
  call void @do_callsimRand(i32 3)
  call void @do_and(i32 3, i32 1)
  call void @do_cmp(i32 3, i32 0)
  %0 = load i32, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 29), align 4
  %1 = trunc i32 %0 to i1
  br i1 %1, label %set_black, label %set_coloful

set_coloful:                                      ; preds = %label_9
  call void @do_mov(i32 4, i32 2)
  call void @do_shl(i32 4, i32 9)
  call void @do_add(i32 4, i32 1)
  call void @do_shl(i32 4, i32 7)
  call void @do_addconst(i32 4, i32 16711680)
  br label %put_pixel

set_black:                                        ; preds = %label_9
  call void @do_movconst(i32 4, i32 -16777216)
  br label %put_pixel

put_pixel:                                        ; preds = %set_black, %set_coloful
  call void @do_callsimPutPixel(i32 1, i32 2, i32 4)
  call void @do_inc(i32 2)
  call void @do_cmp(i32 2, i32 256)
  %2 = load i32, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 29), align 4
  %3 = trunc i32 %2 to i1
  br i1 %3, label %label_4, label %label_9

label_4:                                          ; preds = %put_pixel
  call void @do_inc(i32 1)
  call void @do_cmp(i32 1, i32 512)
  %4 = load i32, ptr getelementptr inbounds ([30 x i32], ptr @regFile, i32 0, i32 29), align 4
  %5 = trunc i32 %4 to i1
  br i1 %5, label %flush, label %label_7

flush:                                            ; preds = %label_4
  call void @do_callsimFlush()
  call void @do_movconst(i32 1, i32 0)
  br label %label_7

label_7:                                          ; preds = %flush, %label_4
  br label %label_1
}

declare void @do_callsimPutPixel(i32, i32, i32)

declare void @do_mov(i32, i32)

declare void @do_movconst(i32, i32)

declare void @do_and(i32, i32)

declare void @do_cmp(i32, i32)

declare void @do_shl(i32, i32)

declare void @do_add(i32, i32)

declare void @do_addconst(i32, i32)

declare void @do_callsimRand(i32)

declare void @do_inc(i32)

declare void @do_callsimFlush()
