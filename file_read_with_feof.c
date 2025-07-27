/*
 * Purpose: Reads and prints a file line by line, demonstrating the use of feof()
 *          to detect the end of the file.
 * Topic: File I/O, End-of-File Handling
 */

#include <stdio.h>
#include <stdlib.h> // For EXIT_FAILURE

#define FILENAME "FH_feof.txt"
#define BUFFER_SIZE 100

int main(void) {
    FILE *file_handle;
    char line_buffer[BUFFER_SIZE];

    // Open the file in read mode
    file_handle = fopen(FILENAME, "r");
    if (file_handle == NULL) {
        perror("Error opening file for reading");
        // If the file doesn't exist, feof() will be true immediately after opening.
        // A more robust check would be to ensure the file exists or handle this case.
        // For this example, we assume the file might be empty or non-existent.
        // If it's non-existent, fopen returns NULL, and we exit.
        return EXIT_FAILURE;
    }

    // --- Corrected approach for reading a file line by line ---
    // The standard and safer way to read a file line by line is to check
    // the return value of fgets(). fgets() returns NULL when it encounters
    // an error or when the end of the file is reached before any characters
    // are read.

    printf("--- File Content ---\n");
    // Loop while fgets successfully reads a line.
    while (fgets(line_buffer, BUFFER_SIZE, file_handle) != NULL) {
        printf("%s", line_buffer); // Print the line read (fgets includes the newline)
    }
    printf("--- End of File Content ---\n");

    // After the loop, feof() can be checked to see if the loop terminated
    // specifically because the end of the file was reached.
    // feof() returns non-zero (true) if the end-of-file indicator is set.
    if (feof(file_handle)) {
        printf("End of file reached successfully.\n");
    } else {
        // This might happen if fgets failed for a reason other than EOF (e.g., read error).
        perror("An error occurred during file reading");
    }

    // Close the file
    if (fclose(file_handle) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    return 0; // Indicate successful execution
}
