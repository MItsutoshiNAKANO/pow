/** */
#include <stdlib.h>
#include "str2pow.h"

#define X "-2"
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
