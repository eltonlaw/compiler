.PHONY: all build run test clear

all: build test

build:
	clang -g -Werror -Wall main.c -o compiler

test: build
	./compiler "test_1.txt"

run:
	./compiler

clear:
	rm -f ./compiler
	clear
