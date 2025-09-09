/*
 * Purpose: Reads a floating-point number, calculates its ceiling, and prints that many asterisks.
 * Topic: Floating-Point Numbers, Math Functions (ceil), Loops, Character Output, Input Handling
 */

#include <stdio.h>
#include <math.h>

int main() {
    float input_value;      // The floating-point number entered by the user
    int ceiling_value;      // The ceiling of the input_value
    int counter;
    const char PRINT_CHAR = '*'; // The character to print

    printf("Enter a floating-point number: ");
    
    // Read the input value and validate that it's a float
    if (scanf("%f", &input_value) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter a valid floating-point number.\n");
        // Clear the input buffer to prevent issues with subsequent reads
        while (getchar() != '\n'); 
        return 0;
    }

    // Calculate the ceiling of the input value
    // ceil() returns a double, so we cast it to an int for the loop count.
    // Note: For very large floats, casting to int might truncate if the value exceeds INT_MAX.
    // However, for typical inputs, this is fine.
    ceiling_value = (int)ceil(input_value);

    // Print asterisks based on the ceiling value
    // The loop runs from 0 up to (but not including) ceiling_value.
    // If ceiling_value is negative, the loop won't execute, which is correct.
    for (counter = 0; counter < ceiling_value; counter++) {
        printf("%c", PRINT_CHAR);
    }
    printf("\n"); // Print a newline at the end for better formatting

    return 0;
}
