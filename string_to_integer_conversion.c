/*
 * Purpose: Converts a string of digits into its integer representation.
 * Topic: String to Integer Conversion, Basic Input/Output
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int num_test_cases;
    char input_string[100]; // Increased buffer size for safety
    int str_length;
    int power_of_10_exponent;
    int decimal_value;
    int digit_value;
    int i, j;

    // Read the number of test cases
    if (scanf("%d", &num_test_cases) != 1) {
        fprintf(stderr, "Error reading number of test cases.\n");
        return 0;
    }
    // Consume the newline character after reading the integer
    while (getchar() != '\n');

    // Process each test case
    for (i = 1; i <= num_test_cases; i++) {
        // Read the input string safely
        if (fgets(input_string, sizeof(input_string), stdin) == NULL) {
            fprintf(stderr, "Error reading input string for test case %d.\n", i);
            continue; // Skip to the next test case
        }

        // Remove trailing newline character if present
        input_string[strcspn(input_string, "\n")] = 0;

        str_length = strlen(input_string);
        power_of_10_exponent = str_length - 1;
        decimal_value = 0;

        // Convert the string to an integer
        for (j = 0; j < str_length; j++) {
            // Ensure the character is a digit
            if (input_string[j] >= '0' && input_string[j] <= '9') {
                digit_value = input_string[j] - '0';
                // Calculate the place value and add to the decimal value
                // Note: Using pow can be computationally expensive and may introduce floating-point inaccuracies.
                // A more efficient approach would be to multiply by 10 in each iteration.
                decimal_value += digit_value * (int)pow(10, power_of_10_exponent);
                power_of_10_exponent--;
            } else {
                fprintf(stderr, "Warning: Non-digit character '%c' found in input string for test case %d. Skipping character.\n", input_string[j], i);
                // If non-digit characters should invalidate the input, handle that here.
                // For this example, we'll just skip the character and continue.
            }
        }
        printf("%d\n", decimal_value);
    }

    return 0;
}
