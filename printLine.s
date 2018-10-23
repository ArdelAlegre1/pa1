/* 
 * Author: Ardel Alegre
 * AccountID: cs30fac
 * StudentID: A15752566
 * Date: October 22, 2018
 * Description: printLine() take TODO and outputs the
 * line corresponding to the row.
 */
@Standard Prologue
        .cpu        cortex-a53
        .syntax     unified
        .equ        FP_OFFSET, 4
        .section    .rodata
        .global     printLine
        .text
        .align      2

printLine:

    push        {fp, lr}
    add         fp, sp, FP_OFFSET
    
    mov         r4, 0       @r4 = col
    mov         r6, 2
    sdiv        r5, r1, r6  @r5 = halfHeight
    mov         r6, 0       @r6 = countLeftStart
    mov         r7, 0       @r7 = countRightStart
    mov         r8, 0       @r8 = startChar
    mov         r9, 0       @r9 = endChar
    mov         r10, 0      @r10 = center Char
@if else statements

    cmp         r0, r5
    beq         else_if

    cmp         r0, r5
    bgt         else

    add         r6, r0, 1
    sub         r7, r5, r0
    mov         r8, r2
    mov         r9, r3
    mov         r10, r3

    b           end_else_if

else_if:
    mov         r6, r5
    mov         r7, r5
    mov         r8, r3
    mov         r9, r3
    mov         r10, r2
    b           end_else_if

else:
    sub         r6, r1, r0
    sub         r6, r6, 1
    sub         r7, r0, r5
    sub         r7, r7, 1
    mov         r8, r3
    mov         r9, r2
    mov         r10, r3

end_else_if:
    
@forloops
    cmp         r4, r6
    bge         end_loop
    mov         r0, r8
loop:
    bl          printChar

    add         r4, r4, 1
    cmp         r4, r6
    blt         loop

end_loop:

    mov         r0,r9
loops:
    bl          printChar

    add         r4, r4, 1
    cmp         r4, r5
    blt         loops
@print center char
    mov         r0, r10
    bl          printChar
    
    mov         r4, 0
    cmp         r4, r7
    bge         end_loop3
    mov         r0, r8
loop3:
    bl          printChar

    add         r4, r4, 1
    cmp         r4, r7
    blt         loop3

end_loop3:

    mov         r0, r9
loop4:
    bl          printf

    add         r4, r4, 1
    cmp         r4, r5
    blt         loop4
    
@Standard Epilogue
    sub         sp, fp, FP_OFFSET
    pop         {fp, pc}
