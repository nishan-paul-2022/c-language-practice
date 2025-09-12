/*
 * Purpose: Continuously reads integers and checks if each corresponds to a printable ASCII character.
 * Topic: Input/Output, Character Handling, Loops, Conditional Statements
 */

#include <stdio.h>
#include <ctype.h>

// Clears input buffer until newline or EOF
void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Prints program title and instructions
void print_program_header(void) {
    printf("=== Printable Character Checker ===\n");
    printf("This program checks if ASCII values represent printable characters.\n");
    printf("Enter ASCII values (integers) to check. Invalid input will exit.\n");
}

// Reads an integer from input with validation and prompt
int read_integer(int *value) {
    printf("Enter an ASCII value (integer): ");
    
    if (scanf("%d", value) != 1) {
        fprintf(stderr, "\nError: Invalid input. Program terminated.\n");
        clear_input_buffer();
        return 0;
    }
    return 1;
}

// Checks if value represents a printable character and prints result
void check_printable(int ascii_value) {
    const char *result = isprint(ascii_value) ? "" : "not ";
    printf("ASCII %d is %sprintable\n\n", ascii_value, result);
}

int main(void) {
    int input_value;
    
    print_program_header();
    
    // Process input values until invalid input or EOF
    while (read_integer(&input_value)) {
        check_printable(input_value);
    }
    
    printf("Thank you for using the Printable Character Checker!\n");
    return 0;
}
