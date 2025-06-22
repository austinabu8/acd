#include <stdio.h>
#include <string.h>

#define MAX_COMMENT_LENGTH 100

// Function to check if the given string is a valid comment
int isComment(const char *str) {
    int len = strlen(str);

    // Check for single-line comment (//...)
    if (len >= 2 && str[0] == '/' && str[1] == '/') {
        return 1;
    }

    // Check for multi-line comment (/* ... */)
    if (len >= 4 && str[0] == '/' && str[1] == '*' &&
        str[len - 2] == '*' && str[len - 1] == '/') {
        return 1;
    }

    return 0;
}

int main() {
    char input[MAX_COMMENT_LENGTH];

    // Prompt for input
    printf("Enter a token: ");
    scanf(" %[^\n]", input);  // Accept input with spaces until newline

    // Check and display result
    if (isComment(input)) {
        printf("'%s' is a valid comment.\n", input);
    } else {
        printf("'%s' is not a valid comment.\n", input);
    }

    return 0;
}
