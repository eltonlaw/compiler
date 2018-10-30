.PHONY: clean $(distdir) $(distdir).tar.gz-check

dist: $(distdir).tar.gz-check

$(distdir).tar.gz-check: $(distdir).tar.gz
	tar -xvzf $(distdir).tar.gz
	cd $(distdir) && $(MAKE) all
	cd $(distdir) && $(MAKE) clean
	rm -r $(distdir)
	@echo '*** dist/Makefile distcheck'

$(distdir).tar.gz: $(distdir)
	tar -zcvf $(distdir).tar.gz $(distdir) 
	-rm -r $(distdir)
	@echo '*** dist/Makefile $@'

$(distdir): clean
	mkdir -p $(distdir)/src
	cp ../Makefile $(distdir)
	cp ../src/Makefile $(distdir)/src
	cp ../src/main.c $(distdir)/src
	@echo '*** dist/Makefile $@'

clean:
	-rm $(distdir).tar.gz >/dev/null 2>&1
	-rm -rf $(distdir) >/dev/null 2>&1
	@echo '*** dist/Makefile $@'
