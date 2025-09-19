/*
 * Purpose: Reads strings from input and prints them.
 * Topic: String Input, Loop, Conditional Execution, Input Buffer Handling
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256 


int read_string(char *buffer, int max_length) {
    if (fgets(buffer, max_length, stdin) == NULL) {
        return -1; 
    }
    buffer[strcspn(buffer, "\n")] = 0; 
    return 0; 
}


void process_strings(int max_length) {
    char input[BUFFER_SIZE];
    while (1) {
        printf("Enter a string: ");
        if (read_string(input, max_length) == -1) {
            printf("Error reading input or end of input reached.\n");
            break;
        }

        printf("Entered string: %s\n", input);
    }
}

int main(void) {
    int max_string_length;

    printf("Enter the maximum length for strings (e.g., 50): ");
    if (scanf("%d", &max_string_length) == -1 || max_string_length <= 0 || max_string_length >= BUFFER_SIZE) {
        printf("Invalid length entered. Please enter a positive integer less than %d.\n", BUFFER_SIZE);
        return 0;
    }

    while (getchar() != '\n'); 

    printf("Enter strings. Press Ctrl+D (Unix/Linux) or Ctrl+Z (Windows) to end.\n");
    process_strings(max_string_length);

    return 0;
}
