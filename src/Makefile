objects = main.o
main.o: main.c

build: $(objects)
	$(CC) $(CFLAGS) $(objects) -o $(package)
	@echo '*** src/Makefile $@'

all: build
	@echo '*** src/Makefile $@'

clean:
	-rm ./$(package)
	@echo '*** src/Makefile $@'
