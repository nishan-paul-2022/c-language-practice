/*
 * Purpose: Calculates and prints the exponential of a given number (e^x).
 * Topic: Mathematical Functions, Exponential Calculation
 */

#include <stdio.h>
#include <math.h>

float calculate_exponential(float base_value) {
    return exp(base_value);
}

void display_result(float base_value, float result) {
    printf("The result of e^%.1f is %f\n", base_value, result);
}

int main(void) {
    float base_value;

    printf("Enter the base value: ");
    scanf("%f", &base_value);

    float result = calculate_exponential(base_value);
    
    display_result(base_value, result);
    
    return 0;
}
