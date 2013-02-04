/** */
#include <stdlib.h>
#include "str2pow.h"

#define X "2"
#define Y "0.5"
#define ANS_A 1.4142
#define ANS_B 1.4143

int
main(int argc, char *argv[])
{
  double d = str2pow(X, Y);
  if (d < ANS_A) {
    abort();
  } 
  if (d > ANS_B) {
    abort();
  } 
  exit(0);
}
