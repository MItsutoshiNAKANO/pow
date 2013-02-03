#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(pow, 0, ItSANgo@gmail.com)
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([pow/pow.c])
AC_CONFIG_HEADERS([config.h])

AM_PROG_LIBTOOL
AC_CONFIG_MACRO_DIR([m4])

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
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_STRTOD
AC_CHECK_FUNCS([pow])

AC_CONFIG_FILES([Makefile
                 include/Makefile
                 libpow/Makefile
                 pow/Makefile])
AC_OUTPUT