/*
 * Purpose: Demonstrates the use of nested switch statements to handle different input ranges and values.
 * Topic: Switch Statements, Nested Control Flow, Type Casting (double to int)
 */

#include <stdio.h>
#include <stdlib.h> // For EXIT_FAILURE

int main() {
    double input_value;     // The initial floating-point input from the user.
    int scaled_value;       // The integer value derived from input_value / 10.
    int secondary_input;    // An integer input read based on the scaled_value.

    printf("Enter a floating-point number: ");
    // Read the floating-point input.
    if (scanf("%lf", &input_value) != 1) {
        printf("Invalid input. Please enter a valid floating-point number.\n");
        return EXIT_FAILURE;
    }

    // Consume the newline character left by scanf.
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Calculate a scaled integer value. Note the implicit conversion from double to int.
    // This truncates any fractional part. For example, 2.99 becomes 2, 3.0 becomes 3.
    scaled_value = input_value / 10.0;

    // Outer switch statement based on the scaled value.
    switch (scaled_value) {
        case 1: // Handles input_value from 10.0 up to (but not including) 20.0
        case 2: // Handles input_value from 20.0 up to (but not including) 30.0
        case 3: // Handles input_value from 30.0 up to (but not including) 40.0
            printf("Enter an integer (e.g., 20): ");
            // Read the secondary integer input.
            if (scanf("%d", &secondary_input) != 1) {
                printf("Invalid secondary input.\n");
                return EXIT_FAILURE;
            }
            // Consume the newline character.
            while ((c = getchar()) != '\n' && c != EOF);

            // Inner switch statement based on the secondary input.
            switch (secondary_input) {
                case 20:
                    printf("CAUGHT\n"); // Printed if secondary_input is exactly 20.
                    break;
                default:
                    printf("GOOD\n"); // Printed for any other integer input.
                    break;
            }
            break; // Break from the outer switch's case block.

        default: // Handles all other values of scaled_value (e.g., 0, 4, negative numbers, etc.)
            printf("F\n"); // Represents a default or 'F' grade/category.
            break;
    }

    return 0;
}
