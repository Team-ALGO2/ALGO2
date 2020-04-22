#include <stdio.h>

#include <string.h>
#include <math.h>

#define max 1000

int main(void) {
  
  /*
  Answer = a0 + (b0)
                -----
                a1 + (b1)
                    ------
                    a2 + (b2)
                        ------
                        etc.
  
  */

  double aN= 2;
  double a0 = 1;
  double b0 = 1;
  double bN = 1;
  
  double total;
  int i=200;

  // last 
  total = aN+ b0/aN;

  //middle
  for( i=i-1; i> 1; i--){
    total = aN+bN/total;
  }
  //first
  total = a0+bN/total;
 
  // This test is for sqrt root of 2

  printf("%.10lf", total);


  return 0;
}
