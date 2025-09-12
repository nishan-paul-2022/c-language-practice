/*
 * Purpose: Reads and prints a file line by line, demonstrating the use of feof()
 *          to detect the end of the file.
 * Topic: File I/O, End-of-File Handling
 */

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "FH_feof.txt"
#define BUFFER_SIZE 100

// Open file for reading
FILE* open_file_for_reading(const char *filename) {
    FILE *file_handle = fopen(filename, "r");
    if (file_handle == NULL) {
        perror("Error opening file for reading");
    }
    return file_handle;
}

// Read and print file content line by line
void read_and_print_file(FILE *file_handle) {
    char line_buffer[BUFFER_SIZE];
    
    printf("--- File Content ---\n");
    
    // Read lines using fgets until end of file
    while (fgets(line_buffer, BUFFER_SIZE, file_handle) != NULL) {
        printf("%s", line_buffer); // fgets includes newline
    }
    
    printf("--- End of File Content ---\n");
}

// Check and report file reading status
void check_file_status(FILE *file_handle) {
    if (feof(file_handle)) {
        printf("End of file reached successfully.\n");
    } else {
        perror("An error occurred during file reading");
    }
}

// Close file with error checking
int close_file_safely(FILE *file_handle) {
    if (fclose(file_handle)) {
        perror("Error closing file");
        return -1;
    }
    return 0;
}

int main(void) {
    FILE *file_handle;

    // Open file
    file_handle = open_file_for_reading(FILENAME);
    if (file_handle == NULL) {
        return 0;
    }

    // Read and print file content
    read_and_print_file(file_handle);

    // Check file reading status
    check_file_status(file_handle);

    // Close file
    if (close_file_safely(file_handle)) {
        return 0;
    }

    return 0;
}
