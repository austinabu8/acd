#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_IDENTIFIER_LENGTH 100

// Function to check if the string is a valid identifier
int isIdentifier(const char *str) {
    // First character must be alphabetic or underscore
    if (!isalpha(str[0]) && str[0] != '_')
        return 0;

    // Remaining characters must be alphanumeric or underscore
    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_')
            return 0;
    }

    return 1;  // Valid identifier
}

int main() {
    char input[MAX_IDENTIFIER_LENGTH];

    // Get user input
    printf("Enter a token: ");
    scanf("%s", input);

    // Check and print result
    if (isIdentifier(input)) {
        printf("'%s' is a valid identifier.\n", input);
    } else {
        printf("'%s' is not a valid identifier.\n", input);
    }

    return 0;
}
