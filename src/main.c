#include <stdio.h>
#include <string.h>

#include "lexer.h"


// List of pointers to token
// Expect something like: [INT, VARIABLE("main"), LPAREN, RPAREN, LBRACE, RETURN, INTEGER(0), RBRACE]

int main(int argc, char* argv[]) {
    puts("========= MAIN START ============");

    /* Check inputs */
    if (argc == 1) {
        fprintf(stderr, "%s", "No file input supplied.!\n");
        return 1;
    }
    else if (argc > 2) {
        fprintf(stderr, "%s", "More than one file input unsupported.!\n");
        return 1;
    }

    /* Read inputs */
    FILE * fp;  // file pointer
    fp = fopen(argv[1], "r");

    /* Check read in file */
    if (!fp) {
        fprintf(stderr, "%s %s", argv[1], ": File read failed!\n");
        return 1;
    }

    char v[100];
    Token_t default_token = {UNDEFINED, v, NULL};
    Token_t *token = &default_token;


    while (next_token(fp, token)) {
        fprintf(stdout, "Type: %u | Value: %s\n", token->type, token->value);
        fprintf(stdout, "------\n");
    }

    fprintf(stdout, "...Cleaning up resources\n");
    fclose(fp);

    puts("========= MAIN END ==============");
    return 0;
}


