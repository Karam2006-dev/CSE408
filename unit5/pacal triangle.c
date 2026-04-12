#include <stdio.h>

int main() {
    int rows, i, j, space, coef = 1;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for (i = 0; i < rows; i++) {
        // Print leading spaces to create the triangle shape
        for (space = 1; space <= rows - i; space++) {
            printf("  ");
        }

        for (j = 0; j <= i; j++) {
            if (j == 0 || i == 0) {
                coef = 1; // The first element of every row is always 1
            } else {
                // Binomial coefficient update formula: C(i, j) = C(i, j-1) * (i-j+1)/j
                coef = coef * (i - j + 1) / j;
            }
            printf("%4d", coef);
        }
        printf("\n"); // Move to the next row
    }

    return 0;
}
