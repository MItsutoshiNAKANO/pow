/** */
#include <stdlib.h>
#include <math.h>
#include "str2pow.h"

double
str2pow(const char  *xs, const char *ys)
{
  char *p;
  double x = strtod(xs, &p);
  double y = strtod(ys, &p);
  return pow(x, y);
}
