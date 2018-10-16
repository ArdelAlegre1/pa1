#include <stdio.h>

#include "pa1.h"
#include "test.h"


void testisOdd() {
    TEST( isOdd(1) == 1);
    TEST( isOdd(10001) == 1);
    TEST( isOdd(2) == 0);
    TEST( isOdd(8) == 0);
    TEST( isOdd(0) == 0);
}

int main() {
    fprintf(stderr, "Running test cases...\n");
    testisOdd();
    fprintf(stderr, "Tests complete\n");

    return 0;
}
