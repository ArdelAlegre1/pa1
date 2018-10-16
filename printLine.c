#include "pa1.h"
#include <math.h>
#define HALF_DIVISIOR 2

void printLine( long row, long height, char windmill, char filler ) {
    
    int col;
    int halfHeight = height / 2;
    int countLeftStart, countRightStart;
    char startChar, endChar, centerChar;

    if ( row < halfHeight ) {
        countLeftStart = row + 1;
        countRightStart = height/2 - row;
        startChar = windmill;
        endChar = filler;
        centerChar = filler;
    } 
    else if ( row == halfHeight ) {
        countLeftStart = halfHeight;
        countRightStart = halfHeight;
        startChar = filler;
        endChar = filler;
        centerChar = windmill;
    }
    else {
        countLeftStart = height - row - 1;
        countRightStart = row - height/2 - 1;
        startChar = filler;
        endChar = windmill;
        centerChar = filler;
    }

    for ( col = 0; col < countLeftStart; ++col ) {
        (void) printChar( startChar );
    }
    for ( col = countLeftStart; col < halfHeight; ++col ) {
        (void) printChar( endChar );
    }

    (void) printChar( centerChar );

    for ( col = 0; col < countRightStart; ++col ) {
        (void) printChar( startChar );
    }
    for (col = countRightStart; col < halfHeight; ++col ) {
        (void) printChar( endChar );
    }
}
