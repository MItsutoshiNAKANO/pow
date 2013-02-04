/** */
#include <stdlib.h>
#include "str2pow.h"

#define X "3"
#define Y "2"
#define ANS 9.0

int
main(int argc, char *argv[])
{
  double d = str2pow(X, Y);
  if (d != ANS) {
    abort();
  } 
  exit(0);
}
