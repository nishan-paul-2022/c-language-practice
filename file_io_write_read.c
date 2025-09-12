/*
 * Purpose: Demonstrates writing characters to a file and then reading them back using 'w+' mode and rewind.
 * Topic: File I/O
 */

#include <stdio.h>
#include <stdlib.h>

int get_two_characters(char *char1, char *char2) {
    printf("Enter two characters separated by a space (e.g., a b): ");
    if (scanf("%c %c", char1, char2) != 2) {
        fprintf(stderr, "Error: Invalid input format.\n");
        return EXIT_FAILURE;
    }
    return 0;
}

int write_characters_to_file(const char *filename, char char1, char char2) {
    FILE *file_ptr = fopen(filename, "w+");
    if (file_ptr == NULL) {
        perror("Error opening file for writing");
        return EXIT_FAILURE;
    }

    if (putc(char1, file_ptr) == EOF) {
        perror("Error writing first character to file");
        fclose(file_ptr);
        return EXIT_FAILURE;
    }
    if (putc(char2, file_ptr) == EOF) {
        perror("Error writing second character to file");
        fclose(file_ptr);
        return EXIT_FAILURE;
    }

    fclose(file_ptr);

    return 0;
}

int read_characters_from_file(const char *filename, char *read_char1, char *read_char2) {
    FILE *file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) {
        perror("Error opening file for reading");
        return EXIT_FAILURE;
    }

    int temp_read_char1 = getc(file_ptr);
    if (temp_read_char1 == EOF) {
        if (ferror(file_ptr)) {
            perror("Error reading first character from file");
        } else {
            fprintf(stderr, "Error: Could not read first character from file.\n");
        }
        fclose(file_ptr);
        return EXIT_FAILURE;
    }
    *read_char1 = (char)temp_read_char1;

    int temp_read_char2 = getc(file_ptr);
    if (temp_read_char2 == EOF) {
        if (ferror(file_ptr)) {
            perror("Error reading second character from file");
        } else {
            fprintf(stderr, "Error: Could not read second character from file.\n");
        }
        fclose(file_ptr);
        return EXIT_FAILURE;
    }
    *read_char2 = (char)temp_read_char2;

    fclose(file_ptr);
    return 0;
}

int process_file_write_read() {
    char char1, char2;
    char read_char1, read_char2;
    const char *filename = "files/14-input.txt";

    if (get_two_characters(&char1, &char2)) {
        return 0;
    }

    if (write_characters_to_file(filename, char1, char2)) {
        return 0;
    }

    if (read_characters_from_file(filename, &read_char1, &read_char2)) {
        return 0;
    }

    printf("Characters read from file: %c %c\n", read_char1, read_char2);

    return 0;
}

int main(void) {
    process_file_write_read();
    return 0;
}
