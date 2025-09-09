/*
 * Purpose: Reverses a given string, including spaces.
 * Topic: Strings, Loops, Character Swapping, Input/Output
 */

#include <stdio.h>
#include <string.h>

int main() {
    int num_test_cases; // Number of test cases
    int i;

    // Read the number of test cases
    scanf("%d", &num_test_cases);

    // Consume the newline character left by scanf("%d")
    // This is crucial because scanf("%[^\n]") will read until a newline,
    // and if the newline from the previous scanf is still in the buffer,
    // it will read an empty string.
    getchar();

    // Process each test case
    for (i = 0; i < num_test_cases; i++) {
        char input_string[1000]; // Buffer to store the input string
        int string_length;       // Length of the input string
        int left_index, right_index; // Pointers for swapping
        char temp_char;          // Temporary variable for swapping

        // Read the entire line (including spaces) until a newline character
        scanf("%[^\n]", input_string);
        // Consume the newline character left by scanf("%[^\n]") for the next iteration
        getchar();

        string_length = strlen(input_string);

        // Reverse the string using two pointers
        left_index = 0;
        right_index = string_length - 1;

        while (left_index < right_index) {
            temp_char = input_string[left_index];
            input_string[left_index] = input_string[right_index];
            input_string[right_index] = temp_char;

            left_index++;
            right_index--;
        }

        // Print the reversed string
        printf("%s\n", input_string);
    }

    return 0;
}
