/*
 * Purpose: To multiply a given number by 100.
 * Topic: Basic I/O, Arithmetic
 */

#include <stdio.h>

double read_input_value() {
    double x;
    printf("Enter a value: ");
    scanf("%lf", &x);
    return x;
}

double multiply_by_100(double x) {
    return x * 100;
}

void display_result(double result) {
    printf("Result is %.2lf\n", result);
}

int main(void) {
    double x = read_input_value();
    double y = multiply_by_100(x);
    
    display_result(y);

    return 0;
}
