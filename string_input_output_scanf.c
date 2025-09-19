/*
 * Purpose: Demonstrates string input using scanf with different format specifiers.
 * Topic: Formatted String Input with scanf() and Format Specifiers
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void read_single_word() {
    char str1[BUFFER_SIZE];

    printf("Enter a single word (no spaces): ");

    if (scanf("%s", str1) == 1) {
        printf("Read with %%s: %s\n", str1);
    }

    clear_input_buffer();
}

void read_full_line() {
    char str2[BUFFER_SIZE];

    printf("Enter text with spaces (press Enter to finish): ");
    
    if (scanf("%[^\n]", str2) == 1) {
        printf("Read with %%[^\\n]: %s\n", str2);
    } else {
        printf("No input received\n");
    }
    
    clear_input_buffer();
}

int main(void) {
    printf("String Input with scanf() Demo\n");
    printf("==============================\n");

    read_single_word();
    read_full_line() ;
    
    return 0;
}
