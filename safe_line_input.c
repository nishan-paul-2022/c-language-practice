/*
 * Purpose: Safely reads multiple lines of input and prints them.
 * Topic: Safe String Input and Line Printing
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void read_and_print_lines() {
    char input_string[BUFFER_SIZE];
    int count = 0;

    printf("Enter strings (press Enter after each string, Ctrl+D or Ctrl+Z to end):\n");

    while (fgets(input_string, sizeof(input_string), stdin) != NULL) {
        count++;
        input_string[strcspn(input_string, "\n")] = '\0';
        printf("Case %d: %s\n", count, input_string);
    }

    if (ferror(stdin)) {
        fprintf(stderr, "Error occurred.\n");
    }
}

int main(void) {
    read_and_print_lines();
    
    return 0;
}
