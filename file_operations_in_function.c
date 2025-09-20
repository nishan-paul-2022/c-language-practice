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

FILE* open_file_with_extension(char *filename_base, const char *mode) {
    char full_filename[FILENAME_BUFFER_SIZE];
    FILE *file_ptr;

    if (snprintf(full_filename, FILENAME_BUFFER_SIZE, "%s.txt", filename_base) >= FILENAME_BUFFER_SIZE) {
        fprintf(stderr, "Filename too long.\n");
        return NULL;
    }

    file_ptr = fopen(full_filename, mode);
    if (file_ptr == NULL) {
        perror("Error opening file");
        fprintf(stderr, "Failed to open file: %s with mode: %s\n", full_filename, mode);
    }
    
    return file_ptr;
}

int get_filename(char *buffer, int size) {
    printf("Enter base filename (e.g., files/file_operations_in_function): ");
    if (fgets(buffer, size, stdin) == NULL) {
        fprintf(stderr, "Error reading filename input.\n");
        return -1;
    }
    buffer[strcspn(buffer, "\n")] = 0;
    return 0;
}

int get_file_mode(char *buffer, int size) {
    printf("Enter file mode (r, w, a, r+, w+, a+): ");
    if (fgets(buffer, size, stdin) == NULL) {
        fprintf(stderr, "Error reading file mode input.\n");
        return -1;
    }
    buffer[strcspn(buffer, "\n")] = 0;
    return 0;
}

int process_file_operation(const char *filename, const char *mode) {
    FILE *file_handle = open_file_with_extension((char*)filename, mode);
    
    if (file_handle == NULL) {
        return -1;
    } else {
        printf("File '%s.txt' opened successfully in mode '%s'.\n", filename, mode);
        if (fclose(file_handle) == -1) {
            perror("Error closing file.");
            return -1;
        } else {
            return 0;
        }
    }
}

int main(void) {
    char base_filename[FILENAME_BUFFER_SIZE];
    char file_mode[MODE_BUFFER_SIZE];

    if (get_filename(base_filename, FILENAME_BUFFER_SIZE)) {
        return 0;
    }
    
    if (get_file_mode(file_mode, MODE_BUFFER_SIZE)) {
        return 0;
    }

    if (process_file_operation(base_filename, file_mode)) {
        return 0;
    }

    return 0;
}
