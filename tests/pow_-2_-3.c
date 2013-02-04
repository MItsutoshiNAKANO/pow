/** */
#include <stdlib.h>
#include "str2pow.h"

#define X "-2"
#define Y "-3"
#define ANS -0.125

int
main(int argc, char *argv[])
{
  double d = str2pow(X, Y);
  if (d != ANS) {
    abort();
  } 
  exit(0);
}
