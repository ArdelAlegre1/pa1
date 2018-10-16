#include <stdio.h>

#include "pa1.h"




void displayWindmill( long height, char border, char filler, char windmill ) {
    for( int i = 1; i <= height + 2; i++ ) {
        printChar(border);
    }
    printf("\n");
    for(int i = 0; i < height; i++) {
        printChar( border);
        printLine(i, height, windmill, filler);
        printChar( border );
        printf("\n");
    }
    for(int i = 1; i <= height + 2; i++ ) {
        printChar(border);
    }
    printf("\n");
    


}
