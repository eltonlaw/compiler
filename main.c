#include <stdio.h>

int main(int argc, char* argv[]) {
    puts("========= MAIN START ============");
    if (argc == 1) {
        puts("No file input supplied");
        return 1;
    }
    else if (argc > 2) {
        puts("More than one file input supplied");
        return 1;
    }
    FILE * file; 
    file = fopen(argv[1], "r");
    char str[999];
    if (file) {
        while (fscanf(file, "%s", str) != EOF) {
            printf("%s", str);
        }
        puts("");
        fclose(file);
    }

    puts("========= MAIN END ==============");
    return 0;
}
