# CHANGELOG

## 2018-10-31

Fixed issue with the left and right braces. With this, whenever a type of whitespace, type of bracket or semicolon is encountered, it automatically ends the token value and sets the pointer back so the special character is included. `fseek` was used to move the file pointer back an iteration. The `SEEK_CUR` macro is used whose value is the address of the current pointer. The `-1` represents moving the `filep` one element backward.

    fseek(filep, -1, SEEK_CUR); 

Here's the current output of the test:

    ./cpiler test_1.txt
    ========= MAIN START ============
    getc(filep)=<i>
    getc(filep)=<n>
    getc(filep)=<t>
    getc(filep)=< >
    TOKEN: Type: 6 | Value: 'int'
    ------                     
    getc(filep)=< >
    TOKEN: Type: 6 | Value: ' '
    ------                     
    getc(filep)=<m>
    getc(filep)=<a>
    getc(filep)=<i>
    getc(filep)=<n>
    getc(filep)=<(>
    TOKEN: Type: 6 | Value: 'main'
    ------         
    getc(filep)=<(>
    TOKEN: Type: 6 | Value: '('     
    ------
    getc(filep)=<)>
    TOKEN: Type: 6 | Value: ')'
    ------
    getc(filep)=< >
    TOKEN: Type: 6 | Value: ' '
    ------
    getc(filep)=<{>
    TOKEN: Type: 6 | Value: '{'
    ------
    getc(filep)=< >
    TOKEN: Type: 6 | Value: ' '
    ------
    getc(filep)=<r>
    getc(filep)=<e>
    ...

Need to work on the token type next.

## 2018-10-30

Seperate `main.c`. Issue found with the left and right braces, the `next_token` function diffrentiates tokens by whitespace currently. Maybe don't use a `switch...case` and swap in with `mpc` or some regex. Maybe use the `isspace` function instead of checking for ' ' and `\n` .

    ./cpiler test_1.txt
    ========= MAIN START ============
    <i> encountered   
    <n> encountered
    <t> encountered
    whitespace encountered
    Type: 6 | Value: int
    ------         
    <m> encountered
    <a> encountered
    <i> encountered       
    <n> encountered        
    lparen encountered
    Type: 6 | Value: main
    ------                
    rparen encountered
    Type: 6 | Value:
    ------         
    whitespace encountered
    Type: 6 | Value:  
    ------
    <{> encountered         
    whitespace encountered           
    Type: 6 | Value: {      
    ------                                               
    <r> encountered
    <e> encountered    
    <t> encountered
    ...

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
