#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "pa1.h"
#include "pa1Strings.h"
#include "test.h"

int main( int argc, char *argv[] ) {
    if(argc != 5) {
        printf("%d", argc);
        printf(STR_USAGE, argv[0], HEIGHT_MIN, HEIGHT_MAX, ASCII_MIN, ASCII_MAX, ASCII_MIN, ASCII_MAX, ASCII_MIN, ASCII_MAX);
        return(EXIT_FAILURE);
    }
    errno = 0;
    char *ptr;
    long ret;
    int pass = 1;
    char str[BUFSIZ];
    int e = 1;
    ret = strtol(argv[1], &ptr, 10);
    //printf("%d\n", *ptr);
    if (*ptr != '\0') {
        fprintf(stderr, STR_ERR_NOT_INT, STR_HEIGHT, argv[1]);
        pass = 0;
        e = 0;

    }
    if(pass == 1) {
        if(errno != 0) {
            snprintf(str, BUFSIZ, STR_ERR_CONVERTING, STR_HEIGHT, argv[1], BASE);
            perror(str);
            e = 0;
        }
        if(rangeCheck(ret, HEIGHT_MIN, HEIGHT_MAX) == 0) {
            fprintf(stderr, STR_ERR_NUM_RANGE, STR_HEIGHT, ret, HEIGHT_MIN,
                HEIGHT_MAX);
            e = 0;
        }
        if(isOdd(ret) == 0) {
            fprintf(stderr, STR_ERR_ODD, STR_HEIGHT, ret);
            e = 0;
        }
    }
    pass = 1;
    if(strlen(argv[2]) > 1) {
        fprintf(stderr, STR_ERR_SINGLE_CHAR, STR_BORDER_CHAR, argv[2]);
        pass = 0;
        e = 0;
    }
    if(pass == 1) {
        if(rangeCheck(*argv[2], ASCII_MIN, ASCII_MAX) == 0) {
            fprintf(stderr, STR_ERR_ASCII_RANGE, STR_BORDER_CHAR, *argv[2], 
            ASCII_MIN, ASCII_MAX);
            e = 0;

        }
    }

    pass = 1;
    if(strlen(argv[3]) > 1) {
        fprintf(stderr, STR_ERR_SINGLE_CHAR, STR_FILLER_CHAR, argv[3]);
        pass = 0;
        e = 0;
    }
    if(pass == 1) {
        if(rangeCheck(*argv[3], ASCII_MIN, ASCII_MAX) == 0) {
            fprintf(stderr, STR_ERR_ASCII_RANGE, STR_FILLER_CHAR, *argv[3], 
            ASCII_MIN, ASCII_MAX);
            e = 0;
        }
    }
    
    pass = 1;
    if(strlen(argv[4]) > 1) {
        fprintf(stderr, STR_ERR_SINGLE_CHAR, argv[0], STR_WINDMILL_CHAR);
        pass = 0;
        e = 0;
    }
    if(pass == 1) {
        if(rangeCheck(*argv[4], ASCII_MIN, ASCII_MAX) == 0) {
            fprintf(stderr, STR_ERR_ASCII_RANGE, STR_WINDMILL_CHAR, *argv[4], 
            ASCII_MIN, ASCII_MAX);
            e = 0;
        }
    }
    if(*argv[2] == *argv[4]) {
        fprintf(stderr, STR_ERR_BORDER_WINDMILL_DIFF, *argv[2], *argv[4]); 
        e = 0;
    }
    if(*argv[3] == *argv[4]) {
        fprintf(stderr, STR_ERR_FILLER_WINDMILL_DIFF, *argv[3], *argv[4]);
        e = 0;
    }
    if(e == 0) {
        return EXIT_FAILURE;
    }


    displayWindmill(ret, *argv[2], *argv[3], *argv[4]);
  
    return 0;



}



