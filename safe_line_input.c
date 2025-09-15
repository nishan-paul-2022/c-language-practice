/*
 * Purpose: Safely reads multiple lines of input and prints them.
 * Topic: Safe String Input and Line Printing
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void read_and_print_lines(void) {
    char input_string[BUFFER_SIZE];

    printf("Enter strings (press Enter after each string, Ctrl+D or Ctrl+Z to end):\n");

    while (fgets(input_string, sizeof(input_string), stdin) != NULL) {
        input_string[strcspn(input_string, "\n")] = '\0';
        printf("%s\n", input_string);
    }

    if (ferror(stdin)) {
        fprintf(stderr, "Error: An input error occurred.\n");
    }
}

int main(void) {
    read_and_print_lines();
    return 0;
}
