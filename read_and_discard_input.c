/*
 * Purpose: Demonstrate input reading with scanf format specifiers that read until a specific character and discard subsequent characters.
 *          Includes visualization of how input is processed and discarded.
 * Topic: String Input Handling, Format Specifiers, Input Buffer Management
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char input_buffer[11]; // Buffer: 10 chars + null terminator
    char remaning_buffer[11];
    int ch;

    printf("Example: Enter a string containing numbers and letters, including '6' somewhere in it.\n");
    printf("Input will be read up to '6' (max 10 chars) and the next 6 characters will be discarded.\n");
    printf("Enter your string: ");

    // Read up to 10 characters until '6' is encountered
    if (scanf("%10[^6]", input_buffer) != 1) {
        input_buffer[0] = '\0'; // On failure, assign empty string
    }

    // Show input processing
    printf("\n--- Input Processing Result ---\n");
    printf("Read characters (stopped at '6'): '%s'\n", input_buffer);
    scanf("%10s", remaning_buffer);
    printf("You entered: '%s'\n", remaning_buffer);

    return 0;
}
