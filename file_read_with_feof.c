/*
 * Purpose: Reads and prints a file line by line, demonstrating the use of feof()
 *          to detect the end of the file.
 * Topic: File I/O, End-of-File Handling
 */

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "files/20-input.txt"
#define BUFFER_SIZE 100

FILE* open_file_for_reading(const char *filename) {
    FILE *file_handle = fopen(filename, "r");
    if (file_handle == NULL) {
        perror("Error opening file for reading");
    }
    return file_handle;
}

void read_and_print_file(FILE *file_handle) {
    char line_buffer[BUFFER_SIZE];
    
    printf("--- File Content ---\n");
    
    while (fgets(line_buffer, BUFFER_SIZE, file_handle) != NULL) {
        printf("%s", line_buffer);
    }
    
    printf("--- End of File Content ---\n");
}

void check_file_status(FILE *file_handle) {
    if (feof(file_handle)) {
        printf("End of file reached successfully.\n");
    } else {
        perror("An error occurred during file reading");
    }
}

int close_file_safely(FILE *file_handle) {
    if (fclose(file_handle)) {
        perror("Error closing file");
        return -1;
    }
    return 0;
}

int main(void) {
    FILE *file_handle;

    file_handle = open_file_for_reading(FILENAME);
    if (file_handle == NULL) {
        return 0;
    }

    read_and_print_file(file_handle);

    check_file_status(file_handle);

    if (close_file_safely(file_handle)) {
        return 0;
    }

    return 0;
}
