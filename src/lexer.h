#ifndef lexer_h
#define lexer_h

#include "util.h"

typedef enum TokenType TokenType;
typedef struct Token_t Token_t;
typedef struct TokenList_t TokenList_t;
int next_token(FILE *filep, Token_t *token);

enum TokenType {
    // Types
    VALUE,

    // Delimiters
    SEMICOLON,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    UNDEFINED,

    // Keywords
    RETURN
};

struct Token_t {
   TokenType type;
   char *value;
   Token_t *next_token;
};

#endif
