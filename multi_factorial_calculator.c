/*
 * Purpose: Calculates the multi-factorial (n!!!...k times) of a number,
 *          where k is determined by the number of exclamation marks in the input string.
 * Topic: String Parsing, Loops, Arithmetic Operations
 */

#include <stdio.h>  // Required for printf, scanf, sscanf
#include <string.h> // Required for strlen (though not directly used, good for string ops)
#include <stdlib.h> // Required for atoi (alternative to sscanf for number parsing)

int main() {
    int number;         // The base number for factorial calculation
    int k_value = 0;    // Represents 'k' in k-factorial (number of exclamation marks)
    int i;              // Loop counter
    long long int result = 1; // Stores the calculated multi-factorial result (using long long for larger values)
    char input_string[100]; // Buffer to read the entire input line

    // Prompt user for input and read the entire line including spaces and exclamation marks
    printf("Enter a number followed by exclamation marks (e.g., 5!!): ");
    scanf("%[^\n]", input_string);

    // Count the number of exclamation marks to determine 'k'
    for (i = 0; input_string[i] != '\0'; i++) {
        if (input_string[i] == '!') {
            k_value++;
        }
    }

    // Parse the integer part of the string into 'number'
    // sscanf is used here to extract the integer before any '!'
    sscanf(input_string, "%d", &number);

    // If no exclamation marks are found, default k_value to 1 for standard factorial
    if (k_value == 0) {
        k_value = 1;
    }

    // Calculate the multi-factorial
    // The loop decrements by 'k_value' in each step
    for (i = number; i >= 1; i -= k_value) {
        result *= i;
    }

    // Print the calculated result
    printf("The multi-factorial is: %lld\n", result);

    return 0;
}
