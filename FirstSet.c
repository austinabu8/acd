#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 10

void FIRST(char[], char);
void addToResultSet(char[], char);

int numOfProductions;
char productionSet[MAX][MAX];

int main() {
    int i;
    char choice;
    char c;
    char result[20];

    printf("How many number of productions? : ");
    scanf("%d", &numOfProductions);

    for (i = 0; i < numOfProductions; i++) {
        printf("Enter production Number %d : ", i + 1);
        scanf("%s", productionSet[i]);
    }

    do {
        printf("\nFind the FIRST of : ");
        scanf(" %c", &c);

        strcpy(result, "");  // Clear result before each computation
        FIRST(result, c);    // Compute FIRST and get result in array

        printf("\nFIRST(%c) = { ", c);
        for (i = 0; result[i] != '\0'; i++)
            printf("%c ", result[i]);
        printf("}\n");

        printf("Press 'y' to continue: ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

// Function to compute FIRST set of a non-terminal or terminal
void FIRST(char* Result, char c) {
    int i, j, k;
    char subResult[20];
    int foundEpsilon;

    // If c is terminal, FIRST(c) = {c}
    if (!isupper(c)) {
        addToResultSet(Result, c);
        return;
    }

    // If c is non-terminal
    for (i = 0; i < numOfProductions; i++) {
        if (productionSet[i][0] == c) {
            // If production is of the form A -> ε
            if (productionSet[i][2] == '$') {
                addToResultSet(Result, '$');
            } else {
                j = 2;
                while (productionSet[i][j] != '\0') {
                    foundEpsilon = 0;
                    strcpy(subResult, "");  // Clear subResult

                    FIRST(subResult, productionSet[i][j]);

                    // Add elements of subResult to Result
                    for (k = 0; subResult[k] != '\0'; k++) {
                        if (subResult[k] != '$')
                            addToResultSet(Result, subResult[k]);
                    }

                    // Check for epsilon in subResult
                    for (k = 0; subResult[k] != '\0'; k++) {
                        if (subResult[k] == '$') {
                            foundEpsilon = 1;
                            break;
                        }
                    }

                    // If no epsilon, stop checking next symbols
                    if (!foundEpsilon)
                        break;

                    j++;
                }

                // If ε is in FIRST(Y1), FIRST(Y2), ..., add ε
                if (productionSet[i][j] == '\0' && foundEpsilon) {
                    addToResultSet(Result, '$');
                }
            }
        }
    }
}

// Function to add character to result set without duplication
void addToResultSet(char Result[], char val) {
    int k;
    for (k = 0; Result[k] != '\0'; k++) {
        if (Result[k] == val)
            return;
    }
    Result[k] = val;
    Result[k + 1] = '\0';
}
