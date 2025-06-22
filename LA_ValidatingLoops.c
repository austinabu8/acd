#include <stdio.h>
#include <string.h>

#define MAX_STATEMENT_LENGTH 100

// Function to check if the given string is a valid looping statement
int isLoopingStatement(const char *str) {
    const char *loopingStatements[] = {"for", "while", "do"};
    int numStatements = sizeof(loopingStatements) / sizeof(loopingStatements[0]);

    // Check the input against each looping statement
    for (int i = 0; i < numStatements; i++) {
        if (strcmp(str, loopingStatements[i]) == 0)
            return 1; // Valid looping statement
    }

    return 0; // Not a valid looping statement
}

int main() {
    char input[MAX_STATEMENT_LENGTH];

    // Prompt the user for a token
    printf("Enter a token: ");
    scanf("%s", input);

    // Check and print the result
    if (isLoopingStatement(input)) {
        printf("'%s' is a valid looping statement.\n", input);
    } else {
        printf("'%s' is not a valid looping statement.\n", input);
    }

    return 0;
}
