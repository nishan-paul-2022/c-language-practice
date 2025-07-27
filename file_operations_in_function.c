/*
 * Purpose: Demonstrates passing strings to a function that appends ".txt" to a filename
 *          and opens the file with a specified mode.
 * Topic: Functions, File I/O, String Manipulation
 */

#include <stdio.h>
#include <stdlib.h> // For EXIT_FAILURE
#include <string.h> // For strcat and other string functions

#define FILENAME_BUFFER_SIZE 100
#define MODE_BUFFER_SIZE 10

/*
 * Function: open_file_with_extension
 * ----------------------------------
 * Appends ".txt" to the given filename and opens the file with the specified mode.
 *
 * name: Pointer to the character array containing the base filename.
 *       This buffer must be large enough to hold the base name + ".txt".
 * mode: Pointer to the character array containing the file opening mode (e.g., "r", "w", "a+").
 *
 * returns: A FILE pointer if the file was opened successfully, otherwise NULL.
 */
FILE* open_file_with_extension(char *filename_base, const char *mode) {
    char full_filename[FILENAME_BUFFER_SIZE];
    FILE *file_ptr;

    // Safely construct the full filename by appending ".txt"
    // Ensure the buffer is large enough to prevent overflow.
    if (snprintf(full_filename, FILENAME_BUFFER_SIZE, "%s.txt", filename_base) >= FILENAME_BUFFER_SIZE) {
        fprintf(stderr, "Error: Filename too long.\n");
        return NULL; // Indicate error due to filename length
    }

    // Open the file with the specified mode
    file_ptr = fopen(full_filename, mode);
    if (file_ptr == NULL) {
        perror("Error opening file");
        // Print the filename that failed to open for better debugging
        fprintf(stderr, "Failed to open file: %s with mode: %s\n", full_filename, mode);
    }
    
    return file_ptr;
}

int main(void) {
    char base_filename[FILENAME_BUFFER_SIZE];
    char file_mode[MODE_BUFFER_SIZE];
    FILE *file_handle;

    // Get the base filename from the user
    printf("Enter the base filename (without .txt): ");
    // Use fgets for safe input
    if (fgets(base_filename, FILENAME_BUFFER_SIZE, stdin) == NULL) {
        fprintf(stderr, "Error reading filename input.\n");
        return EXIT_FAILURE;
    }
    // Remove trailing newline character if present from fgets
    base_filename[strcspn(base_filename, "\n")] = 0;

    // Get the file mode from the user
    printf("Enter the file mode (e.g., r, w, a, r+, w+, a+): ");
    // Use fgets for safe input
    if (fgets(file_mode, MODE_BUFFER_SIZE, stdin) == NULL) {
        fprintf(stderr, "Error reading file mode input.\n");
        return EXIT_FAILURE;
    }
    // Remove trailing newline character if present from fgets
    file_mode[strcspn(file_mode, "\n")] = 0;

    // Call the function to open the file
    file_handle = open_file_with_extension(base_filename, file_mode);

    // Check if the file was opened successfully
    if (file_handle != NULL) {
        printf("File '%s.txt' opened successfully in mode '%s'.\n", base_filename, file_mode);
        // In a real application, you would now perform operations on the file.
        // For this example, we just close it.
        if (fclose(file_handle) != 0) {
            perror("Error closing file");
            return EXIT_FAILURE;
        }
    } else {
        // Error message is already printed by the open_file_with_extension function.
        return EXIT_FAILURE; // Indicate failure
    }

    return 0; // Indicate successful execution
}
