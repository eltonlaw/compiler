#include <stdio.h>
#include <ctype.h>

#include "lexer.h"
#include "util.h"

int next_token_value(FILE *fp, Token_t *token);
int next_token_type(Token_t *token);

int next_token(FILE *fp, Token_t *token) {
    /******  Main Wrapper Function ******/

    /* From `fp` get the next string */
    if (!(next_token_value(fp, token))) {
        LOGGER_DEBUG("next_token_value(): EOF encountered \n");
        return false;
    }
    /* Lookup return value from `next_token_value` */
    if (!(next_token_type(token))) {
        LOGGER_DEBUG("next_token_type(): Error encountered. \n");
        return false;
    }
    return true;
}

int next_token_value(FILE *fp, Token_t *token) {
    char in;
    int i = 0;
    /* Loop through each character in fp */
    while ((in = getc(fp)) != EOF) {
        LOGGER_DEBUG("getc(fp)=<%c>\n",in);
        if (isspace(in) || \
            in == ';' || \
            in == '{' || \
            in == '}' || \
            in == '(' || \
            in == ')') {
            if (i == 0) {
                /* If special character is first thing encountered*/
                token->value[0] = in;
                token->value[1] = '\0';
                break;
            } else {
                /* If special character isn't the first thing encountered*/
                fseek(fp, -1, SEEK_CUR); /* decrement fp */
                token->value[i] = '\0';
                break;
            }
        } else {
            /* If the token is something regular like
             * a letter, add it to the string and go
             * up an address
             */
            token->value[i++] = in;
        }
    }
    if (in == EOF) {
        return false;
    }
    return true;
}
int next_token_type(Token_t *token) {
    return true;
}
