/*
 *
 */
    .cpu    cortex-a53
    .syntax unified
    .equ    FP_OFFSET, 18 
    .global getRemainder
    .text
    .align  2

getRemainder:
    push    {fp, lr}
    add     fp, sp, FP_OFFSET

    cmp     r0, r1
    blt     end_loop

    loop:

        sub     r0, r0, r1
        
        cmp     r0, r1
        bge     loop

    end_loop:

    sub     sp,fp, FP_OFFSET
    pop     {fp,pc}
