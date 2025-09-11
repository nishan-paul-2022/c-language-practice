/*
 * Purpose: Continuously reads integers and checks if each corresponds to a printable ASCII character.
 * Topic: Input/Output, Character Handling, Loops, Conditional Statements
 */

#include <stdio.h>
#include <ctype.h>

int main(void) {
    int input_value; // Integer input (ASCII value)

    // Continuously check input values
    while (1) {
        // Read integer from standard input
        if (scanf("%d", &input_value) != 1) {
            // Handle invalid input by clearing buffer and exiting
            fprintf(stderr, "Invalid input. Exiting.\n");
            // Clear input line to prevent infinite loops
            while (getchar() != '\n' && !feof(stdin));
            break;
        }

        // Check if integer corresponds to printable character using isprint()
        // isprint() returns non-zero for printable characters (letters, digits, punctuation, space)
        if (isprint(input_value)) {
            printf("1\n"); // Output 1 if printable
        } else {
            printf("0\n"); // Output 0 if not printable
        }
    }

    return 0;
}
