#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(pow, 0.2, ItSANgo@gmail.com)
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([pow/pow.c])
AC_CONFIG_HEADERS([config.h])

AM_PROG_LIBTOOL
AC_CONFIG_MACRO_DIR([m4])
AM_MISSING_PROG(HELP2MAN, help2man, $missing_dir)

IT_PROG_INTLTOOL([0.35.0])
GETTEXT_PACKAGE=${PACKAGE_NAME}
AC_SUBST(GETTEXT_PACKAGE)
AM_GLIB_GNU_GETTEXT
#AC_USE_SYSTEM_EXTENSIONS
#AM_GNU_GETTEXT


# Checks for programs.
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lm':
AC_CHECK_LIB([m], [main])
# FIXME: Replace `main' with a function in `-lpow':
AC_CHECK_LIB([pow], [main])

# Checks for header files.
AC_CHECK_HEADERS([libintl.h locale.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_STRTOD
AC_CHECK_FUNCS([pow setlocale strerror])

AC_CONFIG_FILES([Makefile
                 include/Makefile
                 libpow/Makefile
                 man/Makefile
                 man/ja/Makefile
                 msg/Makefile
                 po/Makefile.in
                 pow/Makefile
                 tests/Makefile])
AC_OUTPUT
