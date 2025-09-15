/*
 * Purpose: Calculates the sum of the first n triangular numbers.
 * Topic: Loops and Mathematical Series (Triangular Numbers)
 */

#include <stdio.h>

int read_positive_int(const char *prompt) {
    int n;
    printf("%s", prompt);
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return -1;
    }
    return n;
}

int sum_first_n_triangular_numbers(int n) {
    int sum = 0;
    for (int k = 1; k <= n; k++) {
        sum += k * (k + 1) / 2;
    }
    return sum;
}

int main(void) {
    int n = read_positive_int("Enter a positive integer (n): ");
    if (n == -1) {
        return 0;
    }

    int sum = sum_first_n_triangular_numbers(n);

    printf("The sum of the first %d triangular numbers is: %d\n", n, sum);

    return 0;
}
