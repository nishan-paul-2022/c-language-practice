/*
 * Purpose: Reads an integer and a string, counts exclamation marks in the string,
 *          and performs a custom product calculation based on the integer and the count.
 * Topic: Input Handling (Mixed Types), String Iteration, Custom Calculation
 */

#include <stdio.h>
#include <string.h>

char* get_input_string(char* buffer, int size) {
    printf("Enter a string: ");
    if (fgets(buffer, size, stdin) == NULL) {
        printf("Error: Invalid string input or end of file reached.\n");
        return NULL;
    }
    return buffer;
}

int main(void) {
    char input_string[100];
    get_input_string(input_string, sizeof(input_string));

    // Check if input_string is NULL
    if (input_string == NULL) {
        printf("Failed to read string input.\n");
        return 0;
    }

    // Count exclamation marks
    int exclamation_count = 0;
    for (int char_index = 0; input_string[char_index] != '\0'; char_index++) {
        if (input_string[char_index] == '!') {
            exclamation_count++;
        }
    }

    printf("Exclamation count: %d\n",  exclamation_count);

    return 0;
}
