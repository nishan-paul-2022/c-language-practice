/*
 * Purpose: Reads password from user, masking input with asterisks, and stores it securely.
 * Topic: Terminal Input, Password Masking, Character Handling, POSIX Terminal Control
 */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

// Function to read password from user, masking input with asterisks
// Returns 0 on success, and -1 on failure
int read_password_masked(char password[], int max_len) {
    struct termios old_tio, new_tio;
    char character;
    int i = 0;

    // Get current terminal settings
    if (tcgetattr(STDIN_FILENO, &old_tio) != 0) {
        perror("tcgetattr");
        return -1; // Indicate failure
    }

    // Copy current settings to new settings
    new_tio = old_tio;

    // Disable echo mode: characters typed will not be displayed
    new_tio.c_lflag &= (~ECHO);

    // Apply new terminal settings
    if (tcsetattr(STDIN_FILENO, TCSANOW, &new_tio) != 0) {
        perror("tcsetattr");
        return -1; // Indicate failure
    }

    printf("Enter password: ");
    fflush(stdout); // Ensure prompt is displayed

    // Read characters until Enter key (ASCII 13 or '\n') is pressed
    while (i < max_len - 1) { // Leave space for null terminator
        // Read single character without waiting for newline
        // Using read() is more portable than getch() in POSIX
        if (read(STDIN_FILENO, &character, 1) != 1) {
            // Restore terminal settings before returning on error
            tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
            perror("read");
            return -1; // Indicate failure
        }

        if (character == '\n' || character == 13) { // Enter key
            break; // Exit loop
        }

        putchar('*'); // Display asterisk for masked input
        password[i] = character;
        i++;
    }

    password[i] = '\0'; // Null-terminate the password string
    putchar('\n'); // Move to the next line after password entry

    // Restore original terminal settings
    if (tcsetattr(STDIN_FILENO, TCSANOW, &old_tio) != 0) {
        perror("tcsetattr");
        // Even if restoring fails, we should try to return the password
    }

    return 0;
}

int main(void) {
    char user_password[100]; // Buffer to store password

    if (read_password_masked(user_password, sizeof(user_password)) == 0) {
        printf("Password entered: %s\n", user_password); // Display entered password (for demonstration)
        // In a real application, you would compare this password, not display it
        return EXIT_SUCCESS;
    } else {
        fprintf(stderr, "Failed to read password.\n");
        return EXIT_FAILURE;
    }
}
