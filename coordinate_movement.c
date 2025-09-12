/*
 * Purpose: Simulates movement on a 2D plane based on character commands.
 * Topic: Variables, Loops, Switch Statements, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

// Clear input buffer
void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Print program header and instructions
void print_header(void) {
    printf("=== Coordinate Movement Simulator ===\n");
    printf("Navigate on a 2D grid using commands:\n");
    printf("r = right, l = left, u = up, d = down, s = stop\n\n");
}

// Read and validate initial coordinates
int read_initial_coordinates(int *x, int *y) {
    printf("Enter initial X and Y coordinates (format: x y): ");
    if (scanf("%d %d", x, y) != 2) {
        fprintf(stderr, "Error: Invalid input for coordinates.\n");
        return -1;
    }
    clear_input_buffer();
    return 0;
}

// Read movement command from user
int read_command(char *command) {
    printf("Enter command (r/l/u/d/s): ");
    if (scanf(" %c", command) != 1) {
        fprintf(stderr, "Error: Failed to read command.\n");
        return -1;
    }
    return 0;
}

// Process movement command and update coordinates
int process_command(char command, int *x, int *y) {
    switch (command) {
        case 'r':
            (*x)++;
            printf("Moved right to (%d, %d)\n", *x, *y);
            break;
        case 'l':
            (*x)--;
            printf("Moved left to (%d, %d)\n", *x, *y);
            break;
        case 'u':
            (*y)++;
            printf("Moved up to (%d, %d)\n", *x, *y);
            break;
        case 'd':
            (*y)--;
            printf("Moved down to (%d, %d)\n", *x, *y);
            break;
        case 's':
            printf("Stopping simulation.\n");
            return 0; // Signal to stop
        default:
            printf("Invalid command '%c'. Use r/l/u/d/s.\n", command);
            break;
    }
    return 0; // Continue processing
}

// Main simulation loop
void run_simulation(int *x, int *y) {
    char command;
    
    printf("\nStarting position: (%d, %d)\n", *x, *y);
    printf("Enter movement commands:\n");
    
    while (read_command(&command)) {
        if (!process_command(command, x, y)) {
            break; // Stop command received
        }
    }
}

// Display final results
void display_final_position(int x, int y) {
    printf("\nSimulation completed!\n");
    printf("Final coordinates: (%d, %d)\n", x, y);
}

int main(void) {
    int current_x, current_y;
    
    print_header();
    
    if (read_initial_coordinates(&current_x, &current_y) == -1) {
        return 0;
    }
    
    run_simulation(&current_x, &current_y);
    display_final_position(current_x, current_y);
    
    return 0;
}
