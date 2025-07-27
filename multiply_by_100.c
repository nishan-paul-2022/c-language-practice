/*
 * Purpose: To multiply a given number by 100.
 * Topic: Basic I/O, Arithmetic
 */

#include <stdio.h>

int main() {
    double x, y;

    printf("Enter a value: ");
    scanf("%lf", &x);

    y = x * 100;

    printf("The result is: %lf\n", y);

    return 0;
}
