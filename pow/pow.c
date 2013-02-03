/** */
#include <stdio.h>
#include <stdlib.h>
#include "str2pow.h"

int
main(int argc, char *argv[])
{
  if (argc < 3) {
    fprintf(stderr ,"usage %s num num\n", argv[0]);
    exit(2);
  }
  double d = str2pow(argv[1], argv[2]);
  printf("%f\n", d);
  exit(0);
}
