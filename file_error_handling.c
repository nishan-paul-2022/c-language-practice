/*
 * Purpose: Demonstrates file error checking using ferror() and clearing error flags with clearerr().
 *          It attempts an invalid write operation on a read-only file stream
 *          to trigger an error, then checks and clears the error indicator.
 * Topic: File I/O, Error Handling
 */

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "FH_ferror.txt"

int main(void) {
    FILE *file_handle;
    char character_to_write = 'X';

    // Open the file in read mode. This is intentional to cause a write error.
    file_handle = fopen(FILENAME, "r");
    if (file_handle == NULL) {
        perror("Error opening file for reading");
        // If the file doesn't exist, fopen will fail
        // We can't proceed to test ferror without a valid file handle
        return EXIT_FAILURE;
    }

    // Attempt to write a character to the file opened in read mode.
    // This operation is expected to fail and set an error indicator.
    if (fputc(character_to_write, file_handle) == EOF) {
        // Check if a file error occurred after the write attempt
        if (ferror(file_handle) != 0) {
            // ferror() returns a non-zero value if an error indicator is set
            // The specific value might indicate the type of error, but often just checking non-zero is sufficient
            printf("An error occurred during write operation (as expected).\n");
            // Optionally, print the error code: printf("Error code: %d\n", ferror(file_handle));
        } else {
            // This case is unlikely if fputc returned EOF, but included for completeness
            printf("fputc failed, but ferror() did not report an error.\n");
        }
    } else {
        // This block should ideally not be reached if the file is opened in read mode
        printf("Unexpected success: fputc succeeded on a read-only stream.\n");
    }

    // Clear the error indicators for the file stream.
    // This resets the error flags, so subsequent ferror() calls will return 0.
    clearerr(file_handle);

    // Check the error indicator again after clearing
    if (ferror(file_handle) != 0) {
        // This should not happen after clearerr()
        printf("Error: ferror() still indicates an error after clearerr().\n");
    } else {
        printf("Error indicator cleared successfully.\n");
    }

    // Close the file
    if (fclose(file_handle) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    return 0;
}
