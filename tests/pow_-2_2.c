/** */
#include <stdlib.h>
#include "str2pow.h"

#define X "-2"
#define Y "2"
#define ANS 4.0

int
main(int argc, char *argv[])
{
  double d = str2pow(X, Y);
  if (d != ANS) {
    abort();
  } 
  exit(0);
}
