/*
 * Purpose: Demonstrates file operations using "w+" mode (write and read).
 *          It truncates the file, writes user input, reads it back, and prints a substring of the read content.
 * Topic: File I/O, String Manipulation
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100
#define FILENAME "files/file_truncate_write_read_substring.txt"

int get_user_input(char *buffer, int buffer_size) {
    printf("Enter a string to write to the file: ");
    if (fgets(buffer, buffer_size, stdin) == NULL) {
        printf("Error reading input.\n");
        return -1;
    }
    return 0;
}

int write_to_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w+");
    if (file == NULL) {
        perror("Error opening file for writing");
        return -1;
    }

    if (fprintf(file, "%s", content) < 0) {
        perror("Error writing to file");
    }

    fclose(file);
    return 0;
}

int read_from_file(const char *filename, char *buffer, int buffer_size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        buffer[0] = '\0';
        return -1;
    }

    if (fgets(buffer, buffer_size, file) == NULL) {
        buffer[0] = '\0';
    }

    fclose(file);
    return 0;
}

int main(void) {
    char write_buffer[BUFFER_SIZE];
    char read_buffer[BUFFER_SIZE];

    if (get_user_input(write_buffer, BUFFER_SIZE) == -1) {
        return 0;
    }

    if (write_to_file(FILENAME, write_buffer) == -1) {
        return 0;
    }

    if (read_from_file(FILENAME, read_buffer, BUFFER_SIZE) == -1) {
        return 0;
    }

    if (read_buffer[0] != '\0') {
        printf("Content read from file: %s", read_buffer);

        if (strlen(read_buffer) > 5) {
            printf("Substring (from 6th character): %s", read_buffer + 5);
        } else {
            printf("String is too short to create a substring from the 6th character.\n");
        }
    } else {
        printf("Failed to read from file or file is empty.\n");
    }

    return 0;
}
