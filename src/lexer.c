#include <stdio.h>
#include "lexer.h"


int next_token(FILE *filep, Token_t *token) {
    char in;
    int i=0;
    while ((in = getc(filep)) != EOF) {
        switch (in) {
            case ' ':
                fprintf(stdout, "whitespace encountered\n");
                token->value[i] = '\0';
                return true;
            case '(':
                fprintf(stdout, "lparen encountered\n");
                token->value[i] = '\0';
                return true;
            case ')':
                fprintf(stdout, "rparen encountered\n");
                token->value[i] = '\0';
                return true;
            case '\n':
                fprintf(stdout, "new line encountered\n");
                token->value[i] = '\0';
                return true;
            default:
                fprintf(stdout, "<%c> encountered\n", in);
                token->value[i] = in;
                i += 1;
                break;

        }
        // printf("<%c>: blah \n", in);
    }
    return false;
}
