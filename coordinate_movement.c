/*
 * Purpose: Simulates movement on a 2D plane based on character commands.
 * Topic: Variables, Loops, Switch Statements, Input/Output
 */

#include <stdio.h>
#include <stdlib.h> // For exit() and EXIT_FAILURE

int main(void) {
    int currentX, currentY;
    char commandChar;

    // Prompt for and read the initial coordinates
    printf("Enter initial X and Y coordinates (e.g., 0 0): ");
    if (scanf("%d %d", &currentX, &currentY) != 2) {
        fprintf(stderr, "Error: Invalid input for initial coordinates.\n");
        return EXIT_FAILURE;
    }

    // Consume the newline character left by scanf
    while (getchar() != '\n');

    printf("\nEnter movement commands (r: right, l: left, u: up, d: down, s: stop):\n");

    // Loop to process movement commands
    while (1) { // Loop indefinitely until 's' is entered
        printf("Enter command: ");
        if (scanf(" %c", &commandChar) != 1) { // Note the space before %c to consume any leading whitespace/newlines
            fprintf(stderr, "Error: Failed to read command.\n");
            // Decide how to handle this error, perhaps break or return
            break; 
        }

        // Process the command using a switch statement
        switch (commandChar) {
            case 'r': // Move right
                currentX++;
                break;
            case 'l': // Move left
                currentX--;
                break;
            case 'u': // Move up
                currentY++;
                break;
            case 'd': // Move down
                currentY--;
                break;
            case 's': // Stop
                printf("Stopping simulation.\n");
                goto end_loop; // Exit the loop
            default: // Handle invalid commands
                printf("Invalid command '%c'. Please use r, l, u, d, or s.\n", commandChar);
                break;
        }
        // Optionally print current coordinates after each valid move
        // printf("Current position: (%d, %d)\n", currentX, currentY);
    }

end_loop:
    // Print the final coordinates
    printf("\nFinal coordinates: (%d, %d)\n", currentX, currentY);

    return 0;
}
