#include <stdio.h>
#include <string.h>

#define MAX_SIZE 255

int main() {
    
    char input[MAX_SIZE];
    fgets(input, MAX_SIZE, stdin);

    char * newline = strchr(input, '\n');
    if (newline != NULL) {
        *newline = '\0';
    }

    printf("%s!", input);

    return 0;
}