/*
 * Purpose: Demonstrates passing strings to a function that appends ".txt" to a filename
 *          and opens the file with a specified mode.
 * Topic: Functions, File I/O, String Manipulation
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_BUFFER_SIZE 100
#define MODE_BUFFER_SIZE 10

// Appends ".txt" to filename and opens file with specified mode
FILE* open_file_with_extension(char *filename_base, const char *mode) {
    char full_filename[FILENAME_BUFFER_SIZE];
    FILE *file_ptr;

    // Construct full filename with ".txt" extension
    if (snprintf(full_filename, FILENAME_BUFFER_SIZE, "%s.txt", filename_base) >= FILENAME_BUFFER_SIZE) {
        fprintf(stderr, "Error: Filename too long.\n");
        return NULL;
    }

    // Open file with specified mode
    file_ptr = fopen(full_filename, mode);
    if (file_ptr == NULL) {
        perror("Error opening file");
        fprintf(stderr, "Failed to open file: %s with mode: %s\n", full_filename, mode);
    }
    
    return file_ptr;
}

// Get base filename from user input
int get_filename(char *buffer, int size) {
    printf("Enter the base filename (without .txt): ");
    if (fgets(buffer, size, stdin) == NULL) {
        fprintf(stderr, "Error reading filename input.\n");
        return -1;
    }
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline
    return 0;
}

// Get file mode from user input
int get_file_mode(char *buffer, int size) {
    printf("Enter the file mode (e.g., r, w, a, r+, w+, a+): ");
    if (fgets(buffer, size, stdin) == NULL) {
        fprintf(stderr, "Error reading file mode input.\n");
        return -1;
    }
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline
    return 0;
}

// Process file operation
int process_file_operation(const char *filename, const char *mode) {
    FILE *file_handle = open_file_with_extension((char*)filename, mode);
    
    if (file_handle != NULL) {
        printf("File '%s.txt' opened successfully in mode '%s'.\n", filename, mode);
        if (fclose(file_handle) != 0) {
            perror("Error closing file");
            return -1;
        }
        return 0;
    }
    return -1;
}

int main(void) {
    char base_filename[FILENAME_BUFFER_SIZE];
    char file_mode[MODE_BUFFER_SIZE];

    // Get user inputs
    if (get_filename(base_filename, FILENAME_BUFFER_SIZE) != 0) {
        return 0;
    }
    
    if (get_file_mode(file_mode, MODE_BUFFER_SIZE) != 0) {
        return 0;
    }

    // Process file operation
    if (process_file_operation(base_filename, file_mode) != 0) {
        return 0;
    }

    return 0;
}