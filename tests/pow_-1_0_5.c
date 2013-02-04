/** */
#include <stdlib.h>
#include <math.h>
#include "str2pow.h"

#define X "-1"
#define Y "0.5"
int
main(int argc, char *argv[])
{
  double d = str2pow(X, Y);
  if (!isnan(d)) {
    abort();
  } 
  exit(0);
}
