#include <stdio.h>
#include <string.h> // For strlen
#include <ctype.h>  // For isdigit

// Purpose: Reads a string and calculates the sum of all digit characters within it.
// Topic: Strings, Character Manipulation, Loops, Input/Output, Validation
int main() {
    char input_string[100]; // Buffer for the input string
    int string_length;
    int digit_sum = 0;
    int i;

    // Prompt user for input
    printf("Enter a string (digits will be summed): ");
    // Use fgets for safe string input
    if (fgets(input_string, sizeof(input_string), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1; // Indicate an error
    }

    // Remove trailing newline character if present from fgets
    string_length = strlen(input_string);
    if (string_length > 0 && input_string[string_length - 1] == '\n') {
        input_string[string_length - 1] = '\0';
        string_length--; // Update length
    }

    // Iterate through the string and sum up the digits
    for (i = 0; i < string_length; i++) {
        // Check if the current character is a digit
        if (isdigit(input_string[i])) {
            // Convert the digit character to an integer and add to the sum
            digit_sum += input_string[i] - '0';
        }
    }

    // Print the result
    printf("The sum of the digits in the string is: %d\n", digit_sum);

    return 0;
}
