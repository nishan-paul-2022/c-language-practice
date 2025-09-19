/*
 * Purpose: Multiplies given number.
 * Topic: Basic I/O, Arithmetic
 */

#include <stdio.h>
#include <stdlib.h>

double read_input_value() {
    double v;
    printf("Enter a value: ");
    scanf("%lf", &v);
    return v;
}

int read_number_of_times() {
    int n;
    printf("Enter the number of times to multiply: ");
    scanf("%d", &n);
    return n;
}

double* read_values(int n) {
    double* values = (double*)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%lf", &values[i]);
    }
    
    return values;
}

void multiply_number(double v, double values[], int n) {
    for (int i = 0; i < n; i++) {
        double result = v * values[i];
        printf("%.2lf x %.2lf = %.2lf\n", v, values[i], result);
    }
}

int main(void) {
    double v = read_input_value();
    int n = read_number_of_times();
    double* values = read_values(n);

    multiply_number(v, values, n);
    
    free(values);

    return 0;
}