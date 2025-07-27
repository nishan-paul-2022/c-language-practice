// Purpose: Demonstrates reading lines from standard input and calculating their lengths.
// Topic: String input and length calculation

#include <stdio.h>
#include <string.h>

int main(void) {
    char line_buffer[2000000]; // Buffer to store each line read from input
    int line_length;

    // Read lines from standard input until end-of-file or an error occurs
    // fgets is used instead of gets for safety, as gets is vulnerable to buffer overflows.
    while (fgets(line_buffer, sizeof(line_buffer), stdin) != NULL) {
        // Remove the trailing newline character if it exists, as fgets includes it.
        // This ensures strlen counts only the actual characters of the line.
        line_buffer[strcspn(line_buffer, "\n")] = 0;

        // Calculate the length of the string
        line_length = strlen(line_buffer);

        // Print the length of the line
        printf("Length: %d\n", line_length);
    }

    return 0; // Indicate successful execution
}
