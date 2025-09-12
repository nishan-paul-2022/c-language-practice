/*
 * Purpose: Calculates a custom series based on user input using nested loops and mathematical operations.
 * Topic: Mathematical Series, Nested Loops, Floating-Point Arithmetic
 */

#include <stdio.h>
#include <math.h>

float calculate_custom_series(int x) {
    float sum = 1.0f;
    float y = 1.0f;
    
    for (int i = 0; i <= x; i++) {
        float term = pow((double)x, (double)i) / y;
        sum += term;
        y = y * y + 1.0f;
    }
    
    return sum;
}

int get_user_input() {
    int x;
    printf("Enter value for custom series calculation: ");
    
    if (scanf("%d", &x) != 1) {
        fprintf(stderr, "Invalid input. Please enter an integer.\n");
        while (getchar() != '\n' && !feof(stdin));
        return -1; // Error indicator
    }
    
    return x;
}

void display_result(float result) {
    printf("Result of custom series calculation: %f\n", result);
}

int main(void) {
    int input_value = get_user_input();
    
    if (input_value == -1) {
        return 1; // Exit on invalid input
    }
    
    float result = calculate_custom_series(input_value);
    display_result(result);
    
    return 0;
}
