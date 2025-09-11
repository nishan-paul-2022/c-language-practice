/*
 * Purpose: Demonstrates reporting file opening errors using perror.
 * Topic: File I/O, Error Handling, perror
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *file_pointer; // Pointer to the file

    // Attempt to open "perror.txt" in read mode
    file_pointer = fopen("perror.txt", "r");

    // Check if the file opening failed
    if (file_pointer == NULL) {
        // If fopen failed, print a descriptive error message using perror
        // perror prepends the given string ("File operation error") with the system error message
        perror("File operation error");
        // Return failure status
        return 0;
    } else {
        // If the file was opened successfully, close it and return success
        // In a real scenario, you would perform operations on the file here
        fclose(file_pointer);
        printf("File 'perror.txt' opened successfully (and then closed).\n");
        return 0;
    }
}
