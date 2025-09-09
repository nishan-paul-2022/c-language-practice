#include <stdio.h>

int main() {
    int num_asterisks; // The number of asterisks to print, as entered by the user.
    int i;             // Loop counter.

    // Prompt the user to enter the desired number of asterisks.
    printf("ENTER THE NUMBER OF ASTERISKS TO PRINT: ");
    
    // Read the integer input from the user.
    if (scanf("%d", &num_asterisks) != 1) {
        fprintf(stderr, "Invalid input. Please enter an integer.\n");
        // Clear the input buffer in case of non-integer input
        while (getchar() != '\n' && !feof(stdin));
        return 1; // Indicate an error
    }

    // Print a newline character for better formatting after the input prompt.
    printf("\n");

    // Loop 'num_asterisks' times to print the asterisks.
    for (i = 0; i < num_asterisks; i++) {
        // Print an asterisk followed by a space.
        printf(" * ");
    }
    
    // Print a final newline character after all asterisks have been printed.
    printf("\n");

    return 0;
}
