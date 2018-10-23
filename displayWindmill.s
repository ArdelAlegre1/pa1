/* 
 * Author: Ardel Alegre
 * AccountID: cs30fac
 * StudentID: A15752566
 * Date: October 22, 2018
 * Description: displayWindmill() take TODO and outputs the
 * line corresponding to the row.
 */
@Standard Prologue
        .cpu        cortex-a53
        .syntax     unified
        .equ        FP_OFFSET, 4
        .section    .rodata
fmt:    .asciz      "\n"
        .global     displayWindmill
        .text
        .align      2

displayWindmill:
        push        {fp, lr}
        add         fp, sp, FP_OFFSET
        
        mov         r4, 0           @r4 = i
        mov         r5, r0          @r5 = height
        mov         r6, r1          @r6 = border
        mov         r7, r2          @r7 = filler
        mov         r8, r3          @r8 = windmill
        add         r9, r5, 2       @r9 = height + 2

@ Print empty Line
        ldr         r0, =fmt
        bl          printf
@for loop from 1 to height + 2 inclusive and call printChar(border)
        
        mov         r4, 1
        cmp         r4, r9
        bgt         end_top
top_border:
        bl          printChar
        
        add         r4, r4, 1
        cmp         r4, r9
        ble         top_border

end_top:
    
@ Print "\n"
        ldr         r0, =fmt
        bl          printf

    
@For loop from 0 to height exclusive 
        mov         r4, 0
        cmp         r4, r5
        bge         end_windmill
windmill:
    @printChar(border)
        mov         r0, r6
        bl          printChar
    @printLine(i, height, windmill, filler);
        mov         r0, r4
        mov         r1, r5
        mov         r2, r3
        mov         r3, r2
        bl          printLine
    @printChar(border);
        mov         r0, r6
        bl          printChar

        add         r4, r4, 1
        cmp         r4, r5
        blt         windmill
end_windmill:   

@another for loop from 1 to height + 2 inclusive printChar(border)
        mov         r0, r6

        mov         r4, 1
        cmp         r4, r9
        bgt         end_bottom
bottom:
        bl           printChar

        add          r4, r4, 1
        cmp          r4, r9
        ble          bottom
end_bottom:

@print empty line "\n"
        
        ldr         r0, =fmt
        bl          printf

    
@Standard Epilogue
    sub         sp, fp, FP_OFFSET
    pop         {fp, pc}
