/** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <locale.h>
#include <nl_types.h>
#include <getopt.h>
#include <config.h>
#include "str2pow.h"

static int
print_version(FILE *file)
{
  return fprintf(file, "%s %s\n", PACKAGE, VERSION);
}

static nl_catd cd;

static int
print_help (FILE *file)
{
  /* TRANSLATORS: --help output 1 (synopsis)     no-wrap */
  return
    fprintf(file,
	    catgets(cd, NL_SETD, 1,
		    "Usage: pow x y" "\n"
		    "or: pow [--help|--version]" "\n\n"
		    "The pow returns the value of x raised to the power of y ."
		    "\n\n\t"
		    "--help print this help message ." "\n\t"
		    "--version print version ." "\n\n"
		    "Examples: pow 2 3" "\n\n"
		    "Report bugs to: %s\n\n"
		    "Written by %s\n\n"
		    "Copyright (C) %s\n"
		    /*
		     * "See Also \n\t" "str2pow(3) pow(3)" "\n\n"
		     * "Environment" "\n\n"
		     * "Files" "\n\n"
		     * "other" "\n\n"
		     */),
	    PACKAGE_BUGREPORT, PACKAGE_BUGREPORT, PACKAGE_BUGREPORT);
}

int
main(int argc, char *argv[])
{
  cd = catopen("pow.cat", 0);

  if (!setlocale(LC_ALL, "")) {
    fprintf(stderr, "setlocale() error");
    exit(5);
  }

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
    print_help(stderr);
    exit(3);
  }
  double d = str2pow(argv[optind], argv[optind + 1]);
  if (printf("%g\n", d) <= 0) {
    int save_errno = errno;
    char *p = strerror(save_errno);
    fprintf(stderr ,"%s: output_error: %s, %d\n", argv[0], p, save_errno);
    exit(4);
  }
  exit(EXIT_SUCCESS);
}
