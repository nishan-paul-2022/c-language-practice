/*
 * Purpose: Prints a triangular pattern of sequential numbers and calculates their sum.
 * Topic: Nested Loops and Pattern Generation
 */

#include <stdio.h>

int read_positive_integer(const char *prompt) {
    int n;

    printf("%s", prompt);

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return -1;
    }

    return n;
}

int print_triangular_pattern_and_sum(int rows) {
    int current = 0;
    int total_sum = 0;

    printf("Triangular number pattern:\n");

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            current++;
            printf("%d ", current);
            total_sum += current;
        }
        
        printf("\n");
    }

    return total_sum;
}

int main(void) {
    int rows = read_positive_integer("Enter a positive integer (determines the number of rows in the pattern): ");
    if (rows == -1) {
        return 0;
    }

    int total = print_triangular_pattern_and_sum(rows);
    printf("\nSum of all numbers in the pattern: %d\n", total);

    return 0;
}
