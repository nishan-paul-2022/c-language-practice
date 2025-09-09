// Purpose: Calculates and prints the exponential of a given number (e^x).
// Topic: Mathematical Functions, Exponential Calculation

#include <stdio.h>
#include <math.h> // For the exp() function

int main(void) {
    float base_value = 3.0f; // The base value for the exponential calculation
    float result;            // Variable to store the result

    // Calculate e raised to the power of base_value
    result = exp(base_value);

    // Print the result
    printf("The result of e^%.1f is %f\n", base_value, result);

    return 0;
}
