/*
 * Purpose: Demonstrates safe string input using fgets.
* Topic: String input/output, fgets, Buffer management
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

int main(void) {
    printf("String Input with fgets() Demo\n");
    printf("==============================\n");
    
    char buffer[BUFFER_SIZE];

    printf("Enter a line of text: ");

    if (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        printf("Read with fgets(): %s\n", buffer);
    } else {
        printf("Error reading input\n");
    }
    
    return 0;
}
