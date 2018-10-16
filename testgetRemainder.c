#include <stdio.h>

#include "pa1.h"
#include "test.h"

void testgetRemainder() {

    TEST(getRemainder( 12, 10 ) == 2);
    TEST(getRemainder( 10, 10 )==0);
    TEST(getRemainder( 8, 10 ) == 8);
    TEST(getRemainder( 102, 10 ) == 2);

}

int main(void) {
    fprintf(stderr, "Running tests for rangeCheck...\n");
    testgetRemainder();
    fprintf(stderr, "Tests complete\n");

    return 0;
}
