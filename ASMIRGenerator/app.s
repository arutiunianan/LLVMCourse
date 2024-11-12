app:
    mov R1 0
    jmp label_1

label_1:
    mov R2 0
    
label_9:
    call simRand R3
    and R3 1
    cmp R3 0
    je set_black

    mov R4 R2
    shl R4 9
    add R4 R1
    shl R4 7
    add R4 16711680
    jmp put_pixel

set_black:
    mov R4 -16777216

put_pixel:
    call simPutPixel R1 R2 R4

    inc R2
    cmp R2 256
    je label_4

    jmp label_9

label_4:
    inc R1
    cmp R1 512
    je flush

    jmp label_7

flush:
    call simFlush
    mov R1, 0
    
label_7:
    jmp label_1