#include <stdio.h>
#include <string.h>


typedef enum {
    // Types
    INT,

    // Delimiters
    SEMICOLON,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,

    // Keywords
    RETURN
} TokenValue;

typedef struct {
   TokenValue v;
} Token;

// List of pointers to token
// Expect something like: [INT, VARIABLE("main"), LPAREN, RPAREN, LBRACE, RETURN, INTEGER(0), RBRACE]
Token **token_list;

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
    }

    char in;
    while ((in = getc(fp)) != EOF) {
        printf("%c", in);
    }

    puts("========= MAIN END ==============");
    return 0;
}
