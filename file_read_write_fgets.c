/*
 * Purpose: Demonstrates reading a string from user input, writing it to a file,
 *          and then reading it back from the file using fgets.
 * Topic: File I/O (fopen, fputs, fgets, fclose)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100
#define FILENAME "FH function (fgets).txt"

int get_user_input(char *buffer, int size) {
    printf("Enter a string: ");
    if (fgets(buffer, size, stdin) == NULL) {
        perror("Error reading user input");
        return -1;
    }
    buffer[strcspn(buffer, "\n")] = '\0';
    return 0;
}

int write_string_to_file(const char *filename, const char *str) {
    FILE *output_file_ptr = fopen(filename, "w");
    if (output_file_ptr == NULL) {
        perror("Error opening file for writing");
        return -1;
    }

    if (fputs(str, output_file_ptr) == EOF) {
        perror("Error writing string to file");
        fclose(output_file_ptr);
        return -1;
    }

    if (fclose(output_file_ptr)) {
        perror("Error closing file after writing");
        return -1;
    }
    
    return 0;
}

int read_string_from_file(const char *filename, char *buffer, int size) {
    FILE *input_file_ptr = fopen(filename, "r");
    if (input_file_ptr == NULL) {
        perror("Error opening file for reading");
        return -1;
    }

    if (fgets(buffer, size, input_file_ptr) == NULL) {
        if (feof(input_file_ptr)) {
            fprintf(stderr, "Reached end of file unexpectedly while reading.\n");
        } else {
            perror("Error reading string from file");
        }
        fclose(input_file_ptr);
        return -1;
    }

    if (fclose(input_file_ptr)) {
        perror("Error closing file after reading");
        return -1;
    }

    return 0;
}

void display_read_string(const char *str) {
    printf("String read from file: ");
    puts(str);
}

int main(void) {
    char user_input_string[BUFFER_SIZE];
    char read_string[BUFFER_SIZE];

    if (get_user_input(user_input_string, BUFFER_SIZE)) {
        return 0;
    }

    if (write_string_to_file(FILENAME, user_input_string)) {
        return 0;
    }

    if (read_string_from_file(FILENAME, read_string, BUFFER_SIZE)) {
        return 0;
    }

    display_read_string(read_string);

    return 0;
}
