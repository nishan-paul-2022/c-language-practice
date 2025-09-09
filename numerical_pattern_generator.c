#include <stdio.h>

// Purpose: Generates and prints a numerical pattern based on a loop with floating-point increments.
// Topic: Floating-point arithmetic, Loops, Conditional Logic, Pattern Generation
int main() {
    float current_value; // Represents 'a' in the original code
    int integer_part;    // Represents 'b' in the original code
    float next_value;    // Represents 'f' in the original code
    int base_int;        // Represents 'c' in the original code
    int incremented_int; // Represents 'e' in the original code
    int i;               // Loop counter for the main loop

    // The outer loop iterates 11 times (from i=0 to i=10)
    // current_value starts at 0.0 and increases by 0.2 in each iteration.
    for (i = 0; i <= 10; i++) {
        current_value = i * 0.2f; // Calculate current_value for this iteration

        // Calculate an intermediate integer value based on current_value
        // This is equivalent to original 'A = a*10' and 'b = (int)A'
        integer_part = (int)(current_value * 10.0f);

        // Check if the integer_part is a multiple of 10 (0, 10, 20)
        if (integer_part == 0 || integer_part == 10 || integer_part == 20) {
            // Special case: For values like 0.0, 1.0, 2.0
            base_int = integer_part / 10; // This will be 0, 1, or 2
            incremented_int = base_int + 1; // Start the second number from base_int + 1

            // Print a pattern 3 times
            for (int j = 0; j < 3; j++) {
                printf("I=%d J=%d\n", base_int, incremented_int);
                incremented_int++; // Increment J for the next print
            }
        } else {
            // General case: For other values
            next_value = current_value + 1.0f; // Calculate the second float value

            // Print a pattern 3 times
            for (int j = 0; j < 3; j++) {
                // Print with one decimal place for clarity
                printf("I=%.1f J=%.1f\n", current_value, next_value);
                next_value += 1.0f; // Increment J by 1.0 for the next print
            }
        }
    }

    return 0;
}
