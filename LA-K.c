#include <stdio.h>
#include <string.h>

#define MAX_KEYWORD_LENGTH 32
#define MAX_KEYWORDS 32

// List of all C keywords
const char *keywords[MAX_KEYWORDS] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};

// Function to check if the token is a keyword
int isKeyword(const char *str) {
    for (int i = 0; i < MAX_KEYWORDS; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;  // Valid keyword
    }
    return 0;  // Not a keyword
}

int main() {
    char input[MAX_KEYWORD_LENGTH];

    // Prompt the user for input
    printf("Enter a token: ");
    scanf("%s", input);

    // Check and display the result
    if (isKeyword(input)) {
        printf("'%s' is a valid keyword.\n", input);
    } else {
        printf("'%s' is not a valid keyword.\n", input);
    }

    return 0;
}
