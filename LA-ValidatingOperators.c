#include <stdio.h>
#include <string.h>

#define MAX_OPERATOR_LENGTH 3

// Function to check if a token is a valid C operator
int isOperator(const char *str) {
    const char *operators[] = {
        "+", "-", "*", "/", "%", "++", "--", "=", "+=", "-=", "*=", "/=", "%=",
        "==", "!=", "<", ">", "<=", ">=", "&&", "||", "!", "&", "|", "^", "~", "<<", ">>"
    };

    int numOperators = sizeof(operators) / sizeof(operators[0]);

    // Check the input against each valid operator
    for (int i = 0; i < numOperators; i++) {
        if (strcmp(str, operators[i]) == 0)
            return 1; // Match found
    }

    return 0; // Not a valid operator
}

int main() {
    char input[MAX_OPERATOR_LENGTH];

    // Prompt the user for input
    printf("Enter a token: ");
    scanf("%s", input);

    // Check if the token is a valid operator
    if (isOperator(input)) {
        printf("'%s' is a valid operator.\n", input);
    } else {
        printf("'%s' is not a valid operator.\n", input);
    }

    return 0;
}
