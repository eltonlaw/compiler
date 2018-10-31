objects = main.o lexer.o

# Targets will recompile anytime there are changes to the following files
main.o: main.c lexer.h util.h
lexer.o: lexer.c lexer.h util.h

build: $(objects)
	$(CC) $(CFLAGS) -o $(package) $(objects)
	@echo '*** src/Makefile $@'

all: build
	@echo '*** src/Makefile $@'

clean:
	-rm ./*.o
	-rm ./$(package)
	@echo '*** src/Makefile $@'
