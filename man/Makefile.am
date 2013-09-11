#
SUBDIRS= ja
CLEANFILES= pow.1
EXTRA_DIST= str2pow.3
man_MANS= $(EXTRA_DIST) $(CLEANFILES)
POW_COMMAND= $(top_builddir)/pow/pow
$(CLEANFILES): $(POW_COMMAND) $(common_mandeps)
	$(HELP2MAN) $(POW_COMMAND) >$@
