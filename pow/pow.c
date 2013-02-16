/** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <locale.h>
// #include <nl_types.h>
#include <getopt.h>
#include <libintl.h>
#include <config.h>
#include "str2pow.h"

#define _(str) gettext (str)

enum exit_stat {
  EX_NORMAL, EX_SUBNORMAL, EX_ZERO, EX_MINUS_INFINITE, EX_INFINITE, EX_NAN,
  EX_ARGUMENTS, EX_OPTIONS, EX_LOCALE, EX_OUTPUT_ERROR
};

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
	    _("Usage: pow x y" "\n"
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
  if (!setlocale(LC_ALL, "")) {
    fprintf(stderr, _("setlocale() error"));
    exit(EX_LOCALE);
  }
  bindtextdomain(PACKAGE, LOCALEDIR);
  textdomain(PACKAGE);

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
      exit(EX_NORMAL);
      break;
    case 'h':
      print_help(stdout);
      exit(EX_NORMAL);
      break;
    default:
      lose += 1;
      break;
    }
  }

  if (lose) {
    print_help(stderr);
    exit(EX_OPTIONS);
  } 
  if (argc - optind < 2) {
    print_help(stderr);
    exit(EX_ARGUMENTS);
  }
  int ex = EX_NORMAL;
  double d = str2pow(argv[optind], argv[optind + 1]);
  switch (fpclassify(d)) {
  case FP_NAN:
    ex = EX_NAN;
    break;
  case FP_INFINITE:
    if (isinf(d) < 0) {
      ex = EX_MINUS_INFINITE;
    } else if (isinf(d) > 0) {
      ex = EX_INFINITE;
    } else {
      int save_errno = errno;
      printf("%g\n", d);
      fprintf(stderr,
	      _("Why this code was called?!\n"
		"%d:%s\n"), save_errno, strerror(save_errno));
      abort();
    }
    break;
  case FP_ZERO:
    ex = EX_ZERO;
    break;
  case FP_SUBNORMAL:
    ex = EX_SUBNORMAL;
    break;
  case FP_NORMAL:
    break;
  }

  if (printf("%g\n", d) <= 0) {
    int save_errno = errno;
    fprintf(stderr ,_("pow: output_error:%d: %s\n"), save_errno,
	    strerror(save_errno));
    exit(EX_OUTPUT_ERROR);
  }
  exit(ex);
}
