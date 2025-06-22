#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n, m = 0, p, i = 0, j = 0;
char a[10][10], followResult[10];

// Function declarations
void follow(char c);
void first(char c);
void addToResult(char c);

int main() {
    int choice;
    char c, ch;

    printf("Enter the number of productions: ");
    scanf("%d", &n);

    printf("Enter %d productions\n(Production with multiple terms should be given as separate productions)\n", n);

    // Input productions
    for (i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    // Loop to find FOLLOW of different non-terminals
    do {
        m = 0;  // Reset result index
        printf("Find FOLLOW of --> ");
        scanf(" %c", &c);

        follow(c);

        // Output FOLLOW set
        printf("FOLLOW(%c) = { ", c);
        for (i = 0; i < m; i++)
            printf("%c ", followResult[i]);
        printf("}\n");

        printf("Do you want to continue (Press 1 to continue)? ");
        scanf("%d", &choice);
    } while (choice == 1);

    return 0;
}

// Function to compute FOLLOW set of non-terminal 'c'
void follow(char c) {
    // Rule 1: Add '$' if it's the start symbol
    if (a[0][0] == c)
        addToResult('$');

    // Traverse all productions
    for (i = 0; i < n; i++) {
        for (j = 2; j < strlen(a[i]); j++) {
            if (a[i][j] == c) {
                // If non-terminal is followed by another symbol
                if (a[i][j + 1] != '\0') {
                    first(a[i][j + 1]);
                }

                // If it's at the end or followed by epsilon-producing symbol
                if (a[i][j + 1] == '\0' && c != a[i][0]) {
                    follow(a[i][0]);
                }
            }
        }
    }
}

// Function to compute FIRST set (used for FOLLOW computation)
void first(char c) {
    int k;

    // If terminal, add to FOLLOW result
    if (!isupper(c)) {
        addToResult(c);
        return;
    }

    // If non-terminal, find FIRST from its productions
    for (k = 0; k < n; k++) {
        if (a[k][0] == c) {
            // If production is epsilon
            if (a[k][2] == '#') {
                follow(a[k][0]);
            }
            // If terminal at beginning
            else if (islower(a[k][2])) {
                addToResult(a[k][2]);
            }
            // If another non-terminal
            else {
                first(a[k][2]);
            }
        }
    }
}

// Function to add symbol to FOLLOW result set
void addToResult(char c) {
    int i;
    for (i = 0; i < m; i++) {
        if (followResult[i] == c)
            return;  // Already exists
    }
    followResult[m++] = c;
}
