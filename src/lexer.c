#include <stdio.h>
#include <ctype.h>

#include "lexer.h"
#include "util.h"

int next_token(FILE *filep, Token_t *token) {
    char in;
    int i = 0;
    // static long int pos = 0;
    while ((in = getc(filep)) != EOF) {
        // pos += 1;
        // printf("<%c>: pos=%ld\n",in, pos);
        fprintf(stdout, "getc(filep)=<%c>\n",in);
        if (isspace(in) || \
            in == ';' || \
            in == '{' || \
            in == '}' || \
            in == '(' || \
            in == ')') {
            if (i == 0) {
                token->value[0] = in;
                token->value[1] = '\0';
                return true;
            } else {
                // pos -= 1;
                // fseek(filep, pos, SEEK_SET); 
                fseek(filep, -1, SEEK_CUR); 
                token->value[i] = '\0';
                return true;
            }
        } else {
            token->value[i++] = in;
        }
    }
    return false;
}
