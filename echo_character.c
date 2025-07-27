// Purpose: Reads a single character from standard input and echoes it back to standard output.
// Topic: Character Input/Output, getchar(), putchar()
#include <stdio.h>
#include <stdlib.h> // For EXIT_SUCCESS, EXIT_FAILURE

int main() {
    int input_char; // Use int to accommodate EOF

    printf("Enter a single character: ");

    // Read a single character from standard input
    input_char = getchar();

    // Check if getchar() returned an error or EOF
    if (input_char == EOF) {
        if (ferror(stdin)) {
            perror("Error reading character");
            return EXIT_FAILURE; // Indicate failure
        } else {
            // EOF was reached without an error, e.g., end of input stream
            printf("\nEnd of input reached.\n");
            return EXIT_SUCCESS; // Indicate success (graceful exit)
        }
    }

    // Echo the character back to standard output
    printf("You entered: ");
    putchar((char)input_char); // Cast back to char for putchar
    putchar('\n');

    return 0; // Indicate success
}
