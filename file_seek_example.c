/*
 * Purpose: Demonstrates using fseek to manipulate file pointers for reading and writing.
 * Topic: File I/O (fseek, fputs, fscanf, sprintf)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "FH fseek.txt"
#define STRING_SIZE 100
#define FORMATTED_SIZE 256

int get_user_input(int *int1, int *int2, char *string) {
    printf("Enter an integer, another integer, and a string: ");
    if (scanf("%d %d %99s", int1, int2, string) != 3) {
        perror("Error reading input");
        return -1;
    }
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    return 0;
}

void format_data(char *buffer, int int1, int int2, const char *string) {
    sprintf(buffer, "%d %d %s", int1, int2, string);
}

FILE* open_file_write_read(const char *filename) {
    FILE *file_ptr = fopen(filename, "w+");
    if (file_ptr == NULL) {
        perror("Error opening file");
    }
    return file_ptr;
}

int write_to_file(FILE *file_ptr, const char *data) {
    if (fputs(data, file_ptr) == EOF) {
        perror("Error writing to file");
        return -1;
    }
    return 0;
}

int seek_file_position(FILE *file_ptr, long offset) {
    if (fseek(file_ptr, offset, SEEK_SET)) {
        perror("Error seeking in file");
        return -1;
    }
    return 0;
}

int read_from_position(FILE *file_ptr, char *buffer, int size) {
    if (fscanf(file_ptr, "%99[^\n]", buffer) != 1) {
        if (feof(file_ptr)) {
            fprintf(stderr, "Reached end of file or no matching data found after seeking.\n");
        } else {
            perror("Error reading from file after seeking");
        }
        return -1;
    }
    return 0;
}

void display_result(const char *buffer) {
    printf("String read after fseek: %s\n", buffer);
}

int close_file_safely(FILE *file_ptr) {
    if (fclose(file_ptr)) {
        perror("Error closing file");
        return -1;
    }
    return 0;
}

int main(void) {
    FILE *file_ptr = NULL;
    int input_int1, input_int2;
    char input_string[STRING_SIZE];
    char formatted_string[FORMATTED_SIZE];
    char read_string[STRING_SIZE];
    long int offset = 5;

    if (get_user_input(&input_int1, &input_int2, input_string)) {
        return 0;
    }

    format_data(formatted_string, input_int1, input_int2, input_string);

    file_ptr = open_file_write_read(FILENAME);
    if (file_ptr == NULL) {
        return 0;
    }

    if (write_to_file(file_ptr, formatted_string)) {
        fclose(file_ptr);
        return 0;
    }

    if (seek_file_position(file_ptr, offset)) {
        fclose(file_ptr);
        return 0;
    }

    if (read_from_position(file_ptr, read_string, STRING_SIZE)) {
        fclose(file_ptr);
        return 0;
    }

    display_result(read_string);

    if (close_file_safely(file_ptr)) {
        return 0;
    }

    return 0;
}
