/*
 * Purpose: Demonstrates file operations using "w+" mode (write and read).
 *          It truncates the file, writes user input, reads it back,
 *          and prints a substring of the read content.
 * Topic: File I/O, String Manipulation
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100
#define FILENAME "files/27-input.txt"

void write_to_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w+");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    if (fprintf(file, "%s", content) < 0) {
        perror("Error writing to file");
    }

    fclose(file);
}

void read_from_file(const char *filename, char *buffer, int buffer_size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        buffer[0] = '\0';
        return;
    }

    if (fgets(buffer, buffer_size, file) == NULL) {
        buffer[0] = '\0';
    }

    fclose(file);
}

int main(void) {
    char input_buffer[BUFFER_SIZE];
    char read_buffer[BUFFER_SIZE];

    printf("Enter a string to write to the file: ");
    if (fgets(input_buffer, BUFFER_SIZE, stdin) == NULL) {
        printf("Error reading input.\n");
        return 0;
    }

    write_to_file(FILENAME, input_buffer);

    read_from_file(FILENAME, read_buffer, BUFFER_SIZE);

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
