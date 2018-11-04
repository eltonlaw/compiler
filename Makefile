.PHONY: all clean build dist test test_1 test_2 install uninstall
export

CC = clang
CFLAGS = -g -O0 -Werror -Wall
installdir = /usr/local/bin
package = cpiler
version = 0.0.1
distdir = $(package)-$(version)

all clean build main.o:
	cd src && $(MAKE) $@
	@echo '*** Makefile $@'

dist: build
	cd dist && $(MAKE) $@
	@echo '*** Makefile $@'

test test_1 test_2 test_0_input test_2_input: build
	cp src/$(package) test/$(package)
	cd test && $(MAKE) $@
	-rm test/$(package)
	@echo '*** Makefile $@'

install: build
	chmod +x src/$(package)
	cp src/$(package) $(installdir)
	@echo '*** Makefile $@'

uninstall:
	rm $(installdir)/cpiler
	@echo '*** Makefile $@'
