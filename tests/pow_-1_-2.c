/** */
#include <stdlib.h>
#include "str2pow.h"

#define X "-1"
#define Y "-2"
#define ANS 1.0

int
main(int argc, char *argv[])
{
  double d = str2pow(X, Y);
  if (d != ANS) {
    abort();
  } 
  exit(0);
}
