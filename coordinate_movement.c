/*
 * Purpose: Simulates movement on a 2D plane based on character commands.
 * Topic: Variables, Loops, Switch Statements, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int current_x, current_y;
    char command_char;

    // Prompt for and read the initial coordinates
    printf("Enter initial X and Y coordinates (e.g., 0 0): ");
    if (scanf("%d %d", &current_x, &current_y) != 2) {
        fprintf(stderr, "Error: Invalid input for initial coordinates.\n");
        return 0;
    }

    // Consume the newline character left by scanf
    while (getchar() != '\n');

    printf("\nEnter movement commands (r: right, l: left, u: up, d: down, s: stop):\n");

    // Loop to process movement commands
    while (1) { // Loop indefinitely until 's' is entered
        printf("Enter command: ");
        if (scanf(" %c", &command_char) != 1) { // Note the space before %c to consume any leading whitespace/newlines
            fprintf(stderr, "Error: Failed to read command.\n");
            break;
        }

        // Process the command using a switch statement
        switch (command_char) {
            case 'r': // Move right
                current_x++;
                break;
            case 'l': // Move left
                current_x--;
                break;
            case 'u': // Move up
                current_y++;
                break;
            case 'd': // Move down
                current_y--;
                break;
            case 's': // Stop
                printf("Stopping simulation.\n");
                goto end_loop; // Exit the loop
            default: // Handle invalid commands
                printf("Invalid command '%c'. Please use r, l, u, d, or s.\n", command_char);
                break;
        }
        // Optionally print current coordinates after each valid move
        // printf("Current position: (%d, %d)\n", current_x, current_y);
    }

end_loop:
    // Print the final coordinates
    printf("\nFinal coordinates: (%d, %d)\n", current_x, current_y);

    return 0;
}
