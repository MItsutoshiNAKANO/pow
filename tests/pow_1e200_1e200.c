/** */
#include <stdlib.h>
#include <math.h>
#include "str2pow.h"

#define X "1e200"
#define Y "1e200"

int
main(int argc, char *argv[])
{
  double d = str2pow(X, Y);
  if (isinf(d) != 1) {
    abort();
  } 
  exit(0);
}
