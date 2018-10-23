/*
 * Author: Ardel Alegre
 * UserID: cs30fac
 * StudentID: A15752566
 * Description: Function uses printChar.s and printLine.s to print out line by
 * line the windmill.
 * Date: October 17, 2018
 */

#include <stdio.h>
#include "pa1.h"


void displayWindmill( long height, char border, char filler, char windmill ) {
    printf("\n");
    //prints top of border
    for( int i = 1; i <= height + 2; i++ ) {
        printChar(border);
    }
    printf("\n");
    //Prints each line of the windmill
    for(int i = 0; i < height; i++) {
        printChar( border);
        printLine(i, height, windmill, filler);
        printChar( border );
        printf("\n");
    }
    //prints the bottom of th border
    for(int i = 1; i <= height + 2; i++ ) {
        printChar(border);
    }
    printf("\n");
    


}
