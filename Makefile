.PHONY: all build run test clear

all: build test

build:
	gcc -Werror -Wall main.c -o compiler

test:
	echo "hello world" >> "test.txt"
	./compiler.out "test.txt"
	rm "test.txt"

run:
	./compiler.out

clear:
	rm -f ./compiler.out
	clear
