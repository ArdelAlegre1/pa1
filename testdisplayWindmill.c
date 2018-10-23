/*
 * Filename: testdisplayWindmill.c
 * Author: Ardel Alegre
 * Userid: cs30fac
 * StudentID: A15752566
 * Description: Unit test program to test the function displayWindmill().
 */ 

#include <stdio.h>

#include "pa1.h"
#include "test.h"

/*
 * Unit Test for displayWindmill.c (milestone) and displayWindmill.s (final)
 *
 * void displayWindmill( long height, char border, char filler, char windmill );
 *
 * Prints an ASCII-art windmill with width and height specified with the first
 * parameter using only the characters specified in the last three parameters.
 *
 * Please note this unit test is unable to determine if it was successful or
 * not. You must compare the output of this test with the output of the 
 * reference executable by passing the same parameters.
 */
void testdisplayWindmill( ) {

  (void) displayWindmill( 9, '!', ',', '#' );
  (void) displayWindmill( 11, '^', '.', 'L');
  (void) displayWindmill( 3, 'q', "_", "Q");

  /*
   * TODO: write more tests here
   *
   * Note: displayWindmill() is allowed to assume that height is odd and within a
   *       reasable range.
   */
}


int main( void ) {

  fprintf(stderr, "Running tests for displayWindmill...\n");
  testdisplayWindmill();
  fprintf(stderr, "Done running tests!\n");

  return 0;
}
