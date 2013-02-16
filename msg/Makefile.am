#

locale_ = ja.cat

GENCAT= gencat

.msg.cat:
	@echo "$(GENCAT) $@ $<"; \
	$(GENCAT)t-$@ $< && mv t-$@ $@
