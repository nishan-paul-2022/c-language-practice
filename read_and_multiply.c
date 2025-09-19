/*
 * Purpose: Reads two integers from input in a specific format ("input X*Y") and prints their product.
 * Topic: Formatted Input, Arithmetic Operations
 */

#include <stdio.h>
#include <stdlib.h>

long long calculate_product(int a, int b) {
    return (long long)a * b; 
}

int read_input(int *x, int *y) {
    printf("Enter input in the format 'X*Y': ");
    return scanf("%d*%d", x, y);
}

int main(void) {
    int num1, num2;
    if (read_input(&num1, &num2) == 2) {
        long long product = calculate_product(num1, num2);
        printf("The product of %d and %d is %lld\n", num1, num2, product);
    } else {
        fprintf(stderr, "Invalid input format. Please use 'input X*Y'.\n");
        while (getchar() != '\n'); 
    }

    return 0;
}
