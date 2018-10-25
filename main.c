#include <stdio.h>
#include <string.h>

enum bool {false, true};

typedef enum {
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
} TokenType;

typedef struct {
   TokenType type;
   char *value;
} Token_t;

// List of pointers to token
// Expect something like: [INT, VARIABLE("main"), LPAREN, RPAREN, LBRACE, RETURN, INTEGER(0), RBRACE]

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

int main(int argc, char* argv[]) {
    puts("========= MAIN START ============");
    if (argc == 1) {
        fprintf(stderr, "%s", "No file input supplied.!\n");
        return 1;
    }
    else if (argc > 2) { // FIXME: Allow multiple files
        fprintf(stderr, "%s", "More than one file input unsupported.!\n");
        return 1;
    }

    // Read the passed in file as a FILE object
    FILE * fp;  // file pointer
    fp = fopen(argv[1], "r");

    if (!fp) {
        fprintf(stderr, "%s %s", argv[1], ": File read failed!\n");
        return 1;
    }

    char v[100];
    Token_t default_token = {UNDEFINED, v} ;
    Token_t *token = &default_token ;

    while (next_token(fp, token)) {
        fprintf(stdout, "TOKEN: %s\n", token->value);
        fprintf(stdout, "------\n");
    }


    // fprintf(stdout, "...Cleaning up resources\n");
    fclose(fp);

    puts("========= MAIN END ==============");
    return 0;
}
