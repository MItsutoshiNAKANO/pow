/** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "str2pow.h"

int
main(int argc, char *argv[])
{
  if (argc < 3) {
    fprintf(stderr ,"usage %s num num\n", argv[0]);
    exit(2);
  }
  double d = str2pow(argv[1], argv[2]);
  if (printf("%g\n", d) <= 0) {
    int save_errno = errno;
    char *p = strerror(save_errno);
    fprintf(stderr ,"%s: output_error: %s, %d\n", argv[0], p, save_errno);
    exit(3);
  }
  exit(0);
}
