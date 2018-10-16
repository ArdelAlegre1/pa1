/*
 * Filename: testrangeCheck.c
 * Author: Ardel Alegre
 * Userid: cs30fac  A15752566
 * Description: Unit test program to test the function rangeCheck().
 * Date: 10/15/18
 * Sources of Help: stackoverflow
 */ 

#include <stdio.h>

#include "pa1.h"
#include "test.h"

/*
 * Unit Test for rangeCheck.s
 *
 * long rangeCheck( long value, long minRange, long maxRange );
 *
 * Checks to see if value is within the range of minRange to maxRange,
 * inclusive.
 *
 * Returns -1 if minRange > maxRange.
 * Returns 1 if value is between minRange and maxRange (inclusive).
 * Returns 0 otherwise.
 */
void testrangeCheck( ) {

  /* Test around 0 */
  TEST( rangeCheck( 0, 0, 1 ) == 1 );
  TEST( rangeCheck( 0, 0, 0 ) == -1 );
  TEST( rangeCheck( 0, 0, -1 ) == -1 );

  TEST( rangeCheck( 3, 5, 7 ) == 0 );
  TEST( rangeCheck( 10, 5, 7) == 0);
  TEST( rangeCheck(5, 5, 7) == 1);
  TEST( rangeCheck(7, 5, 5) == 0);

  /*
   * TODO: YOU MUST WRITE MORE TEST CASES FOR FULL POINTS!
   *
   * Some things to think about are error cases, extreme cases, normal cases,
   * abnormal cases, etc.
   */
}


int main( void ) {

  fprintf(stderr, "Running tests for rangeCheck...\n");
  testrangeCheck();
  fprintf(stderr, "Done running tests!\n");

  return 0;
}
