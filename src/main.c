#include <stdio.h>
#include <string.h>

#include "util.h"
#include "lexer.h"

int main(int argc, char* argv[]) {
    puts("========= MAIN START ============");

    /* Check inputs */
    if (argc == 1) {
        puts("No file input supplied.");
        return 0; /* nonzero return values for `main()`*/
    }
    else if (argc > 2) {
        puts("More than one file input unsupported.");
        return 0; /* nonzero return values for `main()`*/
    }

    /* Read inputs */
    FILE * fp;  /* file pointer */
    fp = fopen(argv[1], "rb");

    /* Check read in file */
    if (!fp) {
        LOGGER_CRITICAL("%s %s", argv[1], ": File read failed!\n");
        return 1; /* nonzero return values for `main()`*/
    }

    char v[100];
    Token_t default_token = {UNDEFINED, v, NULL};
    Token_t *token = &default_token;

    while (next_token(fp, token)) {
        LOGGER_DEBUG("TOKEN: Type: %u | Value: '%s'\n", token->type, token->value);
        token->value[100] = '\0';
    }

    LOGGER_DEBUG("...Cleaning up resources\n");
    fclose(fp);

    puts("========= MAIN END ==============");
    return 0;
}
