// Purpose: Demonstrates using ftell to get the current file position, typically used to find file size.
// Topic: File I/O (ftell, fseek)

#include <stdio.h>
#include <stdlib.h> // For EXIT_FAILURE, EXIT_SUCCESS, perror

int main() {
    FILE *file_ptr = NULL; // File pointer
    long int file_size;    // Variable to store the file size

    // --- File Preparation ---
    // The original code opens "# lab 6.docx". For a cleaner example, we'll use "lab6.txt".
    // We need to ensure the file exists and has some content for ftell to work correctly.
    const char *filename = "lab6.txt";

    // Open the file in write mode to create it or truncate it if it exists.
    FILE *prep_file = fopen(filename, "w");
    if (prep_file == NULL) {
        perror("Error preparing file for ftell demonstration");
        return EXIT_FAILURE;
    }
    // Write some sample data to the file. The size of this data will be reported by ftell.
    fprintf(prep_file, "This is some sample text for ftell demonstration.\n");
    fprintf(prep_file, "It contains multiple lines and characters.\n");
    fclose(prep_file); // Close the preparation file

    // --- File Operations ---
    // Open the file in read mode ("r")
    file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) {
        perror("Error opening file for ftell demonstration");
        return EXIT_FAILURE;
    }

    // Move the file position indicator to the end of the file.
    // SEEK_END means the offset is relative to the end of the file.
    // An offset of 0 means exactly at the end.
    if (fseek(file_ptr, 0, SEEK_END) != 0) {
        perror("Error seeking to end of file");
        fclose(file_ptr);
        return EXIT_FAILURE;
    }

    // Get the current file position indicator.
    // When the file pointer is at the end, ftell returns the size of the file in bytes.
    file_size = ftell(file_ptr);

    // Check if ftell returned an error (indicated by -1L)
    if (file_size == -1L) {
        perror("Error getting file position with ftell");
        fclose(file_ptr);
        return EXIT_FAILURE;
    }

    // Print the file size. Use %ld for long int.
    printf("The size of the file '%s' is: %ld bytes\n", filename, file_size);

    // Close the file
    if (fclose(file_ptr) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
