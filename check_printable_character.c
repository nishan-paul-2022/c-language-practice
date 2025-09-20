/*
 * Purpose: Reads integers and checks if each corresponds to a printable ASCII character.
 * Topic: Input/Output, Character Handling, Loops, Conditional Statements
 */

#include <stdio.h>
#include <ctype.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void print_program_header() {
    printf("=== Printable Character Checker ===\n");
    printf("This program checks if ASCII values represent printable characters.\n");
    printf("Enter ASCII values (integers) to check. Invalid input will exit.\n");
}

int read_integer(int *value) {
    printf("Enter an ASCII value (integer): ");
    
    if (scanf("%d", value) != 1) {
        fprintf(stderr, "\nInvalid input. Program terminated.\n");
        clear_input_buffer();
        return -1;
    }
    
    return 0;
}

void check_printable(int ascii_value) {
    const char *result = isprint(ascii_value) ? "" : "not ";
    printf("ASCII %d is %sprintable\n\n", ascii_value, result);
}

int main(void) {
    int input_value;
    
    print_program_header();
    
    while (read_integer(&input_value) == 0) {
        check_printable(input_value);
    }
    
    printf("Thanks for using the Printable Character Checker!\n");
    return 0;
}
