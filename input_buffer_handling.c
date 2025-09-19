/*
 * Purpose: Demonstrates reading input using fgets() and clearing the input buffer.
 * Topic: Input/Output, Buffer Handling
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int read_string(char *input_string) {
    printf("Enter a string: ");
    
    if (fgets(input_string, BUFFER_SIZE, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        clear_input_buffer();
        return -1;
    }
    
    clear_input_buffer();
    return 0;
}

int main(void) {
    char input_string[BUFFER_SIZE];
    int loop_count = 2;

    printf("This program will ask for input twice.\n");

    while (loop_count--) {
        if (read_string(input_string) == 0) {
            printf("Entered string: %s", input_string);
        }
    }

    printf("\nProgram finished.\n");
    return 0;
}
