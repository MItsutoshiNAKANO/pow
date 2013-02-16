#
INCLUDES= -I$(top_builddir)/include
DEFS= -DLOCALEDIR=\"$(localedir)\" @DEFS@
AM_CFLAGS= -Wall -std=gnu99
bin_PROGRAMS = pow
pow_SOURCES= pow.c
pow_LDADD= -L$(top_builddir)/libpow -lpow -lm
