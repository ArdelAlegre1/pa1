    .cpu        cortex-a53
    .syntax     unified
    .equ        FP_OFFSET, 4
    .global     isOdd
    .text
    .align      2

isOdd:
    push        {fp, lr} 
    add         fp, sp, FP_OFFSET

    mov         r1, 2
    bl          getRemainder

    sub         sp, fp, FP_OFFSET
    pop        {fp, pc}
