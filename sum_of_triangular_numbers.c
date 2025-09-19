/*
 * Purpose: Calculates the n-th triangular number.
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

int calculate_n_th_triangular_number(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * (i + 1) / 2;
        printf("%d: %d\n", i, sum);
    }
    printf("\n");
    return sum;
}

int main(void) {
    int n = read_positive_int("Enter a positive integer: ");
    if (n == -1) {
        return 0;
    }

    int sum = calculate_n_th_triangular_number(n);

    printf("%d-th triangular number is %d.\n", n, sum);

    return 0;
}
