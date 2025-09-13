/*
 * Purpose: Calculates and prints the length of a given string.
 * Topic: String Manipulation, String Length Calculation, Input Validation
 */

#include <stdio.h>
#include <string.h>

void find_and_print_string_length() {
    char input_string[256];
    
    printf("Enter a string: ");

    if (fgets(input_string, sizeof(input_string), stdin) == NULL) {
        fprintf(stderr, "Error reading input string.\n");
        return;
    }

    input_string[strcspn(input_string, "\n")] = '\0'; // Remove trailing newline

    printf("String length: %zu\n", strlen(input_string));
}

int main(void) {
    find_and_print_string_length();
    return 0;
}
