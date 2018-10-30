# CHANGELOG

## 2018-10-29

Create Makefile targets for building, testing, distribution and installation:

- `make dist`: Creates a copy of the source code in a `cpiler-<VERSION>.tar.gz` file in `dist`.
- `make all`: Builds the binary, shouldn't need to call this since everything else does
- `make test`: Runs end to end tests
- `make install`: Install the built binary file to `/usr/local/bin` by default. Modify the `installdir` in the call to install somewhere else. (Ex. `sudo make installdir=/somewhere/else install`)

Moved `main.c` out of root and into a `./src` directory.

## 2018-10-25

Reads in one file and passses it to a function `next_token` that functionally outputs a stream of tokens.

    int next_token(FILE *filep, Token_t *token)

The first argument is just a regular FILE pointer, `next_token` will continuosly call `getc` on it until an `EOF` which will in turn send a signal to the `while` loop continuosly calling `next_token`. The other parameter `token` is a struct that has two properties, a `TokenType` (ex. `INT`, `RBRACE` etc.) and a string representing the value.

TODO: 1) In the tokenizing stage, tie in the token types to `next_token` 2) Setup the intermediate representation (probably an AST) and how data will be put in with each token. 3) Unit tests
