/*
 * Purpose: Demonstrates file operations using "r+" mode (read and write).
 *          It reads content from a file up to a delimiter, prints it,
 *          then overwrites the beginning of the file with new content.
 * Topic: File I/O
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 100
#define FILENAME "files/22-input.txt"

FILE* open_file_read_write(const char *filename) {
    FILE *file_ptr = fopen(filename, "r+");
    if (file_ptr == NULL) {
        perror("Error opening file in 'r+' mode. Ensure the file exists.");
    }
    return file_ptr;
}

int read_file_content(FILE *file_ptr, char *buffer, int size) {
    if (fgets(buffer, size, file_ptr) == NULL) {
        if (feof(file_ptr)) {
            printf("File '%s' is empty or no data to read.\n", FILENAME);
        } else {
            perror("Error reading from file");
        }
        return -1;
    }
    return 0;
}

void display_content(const char *buffer) {
    printf("Content read from file: %s", buffer);
}

int seek_to_beginning(FILE *file_ptr) {
    if (fseek(file_ptr, 0, SEEK_SET)) {
        perror("Error seeking to beginning of file for writing");
        return -1;
    }
    return 0;
}

int write_to_file(FILE *file_ptr, const char *str) {
    if (fprintf(file_ptr, "%s", str) < 0) {
        perror("Error writing to file");
        return -1;
    }
    return 0;
}

int close_file_safely(FILE *file_ptr) {
    if (fclose(file_ptr)) {
        perror("Error closing file");
        return -1;
    }
    return 0;
}

void display_success_message() {
    printf("Successfully read from and wrote to '%s'.\n", FILENAME);
}

int main(void) {
    FILE *file_read_write;
    char read_buffer[BUFFER_SIZE];
    const char *write_string = "GOOGLE ";

    file_read_write = open_file_read_write(FILENAME);
    if (file_read_write == NULL) {
        return 0;
    }

    if (read_file_content(file_read_write, read_buffer, BUFFER_SIZE)) {
        fclose(file_read_write);
        return 0;
    }

    display_content(read_buffer);

    if (seek_to_beginning(file_read_write)) {
        fclose(file_read_write);
        return 0;
    }

    if (write_to_file(file_read_write, write_string)) {
        fclose(file_read_write);
        return 0;
    }

    if (close_file_safely(file_read_write)) {
        return 0;
    }

    display_success_message();

    return 0;
}
