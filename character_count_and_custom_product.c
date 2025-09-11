/*
 * Purpose: Reads an integer and a string, counts exclamation marks in the string,
 *          and performs a custom product calculation based on the integer and the count.
 * Topic: Input Handling (Mixed Types), String Iteration, Custom Calculation
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    int input_number;
    char input_string[100]; // Buffer for input string
    int exclamation_count = 0;
    long long result_product = 1; // Use long long to avoid overflow
    int current_n; // Changing value of n in loop
    int char_index;

    // Get user input
    printf("Enter an integer followed by a string (e.g., 5 Hello! World!!): ");

    // Read integer
    if (scanf("%d", &input_number) != 1) {
        printf("Error: Invalid integer input.\n");
        return 0;
    }

    // Consume newline character left in input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Read string with fgets (safer than scanf)
    if (fgets(input_string, sizeof(input_string), stdin) == NULL) {
        printf("Error: Invalid string input or end of file reached.\n");
        return 0;
    }

    // Count exclamation marks
    for (char_index = 0; input_string[char_index] != '\0'; char_index++) {
        if (input_string[char_index] == '!') {
            exclamation_count++;
        }
    }

    // Print input integer and exclamation count
    printf("Input integer: %d, Exclamation count: %d\n", input_number, exclamation_count);

    // Custom product calculation
    current_n = input_number;
    
    // Handle edge cases
    if (input_number <= 0) {
        printf("Input number is not positive, product calculation is not applicable.\n");
    } else if (exclamation_count == 0) {
        // Avoid infinite loop when exclamation_count is 0
        result_product = 1;
        printf("No exclamation marks found. Product calculation results in 1.\n");
    }
    else {
        // Perform product calculation
        while (current_n > 0) {
            result_product *= current_n;
            current_n -= exclamation_count;
        }
        // Print result
        printf("Custom product calculation result: %lld\n", result_product);
    }

    return 0;
}
