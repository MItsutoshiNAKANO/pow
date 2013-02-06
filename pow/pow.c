/** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <getopt.h>
#include <config.h>
#include "str2pow.h"

static int
print_version(FILE *file)
{
  return fprintf(file, "%s %s\n", PACKAGE, VERSION);
}

static int
print_help (FILE *file)
{
  /* TRANSLATORS: --help output 1 (synopsis)     no-wrap */
  return
    fprintf(file,
	    "Usage: pow x y" "\n"
	    "or: pow [--help|--version]" "\n\n"
	    "The pow returns the value of x raised to the power of y ." "\n\n\t"
	    "--help print this help message ." "\n\t"
	    "--version print version ." "\n\n"
	    "Examples: pow 2 3" "\n\n"
	    "Report bugs to: "  PACKAGE_BUGREPORT "\n\n"

	    /*
	    "Author: " PACKAGE_BUGREPORT "\n\n"
	    "COPYRIGHT:" "\n\n"
	    "SEE ALSO:" "\n"
	    "ENVIRONMENT:" "\n\n"
	    "FILES:" "\n\n"
	    "other:" "\n\n"
	    */
	    );
}



int
main(int argc, char *argv[])
{
  static const struct option longopts[] = {
    { "help", no_argument, NULL, 'h' },
    { "version", no_argument, NULL, 'v' },
    { NULL, 0, NULL, 0 }
  };
  int lose = 0, optc;
  while ((optc = getopt_long (argc, argv, "hv", longopts, NULL)) != -1) {
    switch (optc) {
    case 'v':
      print_version(stdout);
      exit(EXIT_SUCCESS);
      break;
    case 'h':
      print_help(stdout);
      exit(EXIT_SUCCESS);
      break;
    default:
      lose = 1;
      break;
    }
  }

  if (lose || argc - optind < 2) {
    fprintf(stderr ,"usage %s num num\n", argv[0]);
    print_help(stderr);
    exit(2);
  }
  double d = str2pow(argv[optind], argv[optind + 1]);
  if (printf("%g\n", d) <= 0) {
    int save_errno = errno;
    char *p = strerror(save_errno);
    fprintf(stderr ,"%s: output_error: %s, %d\n", argv[0], p, save_errno);
    exit(3);
  }
  exit(EXIT_SUCCESS);
}
