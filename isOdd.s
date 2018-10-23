/*
 * Author: Ardel Alegre
 * UserID:cs30fac
 * StudentID: A15752566
 *Description: Function takes one paramter and returns 1 if the paramter is odd
 *and 0 if it is even.
 */
   
   
@Standard prologue   
    .cpu        cortex-a53
    .syntax     unified
    .equ        FP_OFFSET, 4
    .global     isOdd
    .text
    .align      2

isOdd:
    push        {fp, lr} 
    add         fp, sp, FP_OFFSET

    mov         r1, 2               @puts the value 2 into r1
    bl          getRemainder        @gets remainder of parameter and 2. 1 if odd
                                    @0 if even

    cmp         r0, 0               @checks if return is greater than 0
    bge         end_if
    
    mov         r1, -1
    mul         r0, r0, r1          @if return is less than 0 it make it positiv

    end_if:
    
@Standard Epilogue
    sub         sp, fp, FP_OFFSET
    pop        {fp, pc}
