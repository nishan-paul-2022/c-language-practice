/*
 * Purpose: Generates and prints a numerical pattern based on a loop with floating-point increments.
 * Topic: Floating-point arithmetic, Loops, Conditional Logic, Pattern Generation
 */

#include <stdio.h>

int is_special_case(float value) {
    int integer_part = (int)(value * 10.0f);
    return (integer_part == 0 || integer_part == 10 || integer_part == 20);
}

void print_integer_pattern(float value) {
    int base_int = (int)(value * 10.0f) / 10;
    int incremented_int = base_int + 1;

    for (int j = 0; j < 3; j++) {
        printf("I=%d J=%d\n", base_int, incremented_int);
        incremented_int++;
    }
}

void print_float_pattern(float current_value) {
    float next_value = current_value + 1.0f;

    for (int j = 0; j < 3; j++) {
        printf("I=%.1f J=%.1f\n", current_value, next_value);
        next_value += 1.0f;
    }
}

void generate_pattern() {
    for (int i = 0; i <= 10; i++) {
        float current_value = i * 0.2f;

        if (is_special_case(current_value)) {
            print_integer_pattern(current_value);
        } else {
            print_float_pattern(current_value);
        }
    }
}

int main(void) {
    generate_pattern();
    return 0;
}
