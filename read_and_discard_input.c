/*
 * Purpose: Demonstrates input reading with scanf format specifiers that read until a specific character and discard subsequent characters.
 *          Includes visualization of how input is processed and discarded.
 * Topic: String Input Handling, Format Specifiers, Input Buffer Management
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char input_buffer[11]; 
    char remaning_buffer[11];
    int ch;

    printf("Example: Enter a string containing numbers and letters, including '6' somewhere in it.\n");
    printf("Input will be read up to '6' (max 10 chars) and the next 6 characters will be discarded.\n");
    printf("Enter string: ");

    
    if (scanf("%10[^6]", input_buffer) != 1) {
        input_buffer[0] = '\0'; 
    }

    
    printf("\n--- Input Processing Result ---\n");
    printf("Read characters (stopped at '6'): '%s'\n", input_buffer);
    scanf("%10s", remaning_buffer);
    printf("Entered characters after '6': '%s'\n", remaning_buffer);

    return 0;
}
