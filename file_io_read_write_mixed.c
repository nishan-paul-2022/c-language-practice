/*
 * Purpose: Demonstrates reading various data types from user input, writing them to a file, and then reading them back from the file.
 * Topic: File I/O, Input/Output Functions, Data Types
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 100
#define MAX_STRING_LEN 100

int get_filename(char *filename) {
    printf("Enter filename (e.g., files/file_io_read_write_mixed.txt): ");
    if (fgets(filename, MAX_FILENAME_LEN, stdin) == NULL) {
        perror("Error reading filename");
        return 0;
    }
    filename[strcspn(filename, "\n")] = 0;
    return 0;
}

int get_user_inputs(char *input_string, char *read_char, int *input_int, float *input_float) {
    printf("Enter a string: ");
    if (fgets(input_string, MAX_STRING_LEN, stdin) == NULL) {
        perror("Error reading string");
        return 0;
    }
    input_string[strcspn(input_string, "\n")] = 0;

    printf("Enter a character: ");
    if (scanf(" %c", read_char) != 1) {
        perror("Error reading character");
        return 0;
    }
    while (getchar() != '\n');

    printf("Enter an integer (e.g., 123): ");
    if (scanf("%d", input_int) != 1) {
        perror("Error reading integer");
        return 0;
    }

    printf("Enter a float (e.g., 45.67): ");
    if (scanf("%f", input_float) != 1) {
        perror("Error reading integer and float");
        return 0;
    }

    while (getchar() != '\n');

    return 0;
}

int write_data_to_file(const char *filename, const char *input_string, char read_char, int input_int, float input_float) {
    FILE *file_ptr = fopen(filename, "w");
    if (file_ptr == NULL) {
        perror("Error opening file for writing");
        return 0;
    }

    if (fprintf(file_ptr, "%s\n", input_string) < 0) {
        perror("Error writing string to file");
        fclose(file_ptr);
        return 0;
    }
    if (fprintf(file_ptr, "%c\n", read_char) < 0) {
        perror("Error writing character to file");
        fclose(file_ptr);
        return 0;
    }
    if (fprintf(file_ptr, "%d\n", input_int) < 0) {
        perror("Error writing integer to file");
        fclose(file_ptr);
        return 0;
    }
    if (fprintf(file_ptr, "%f\n", input_float) < 0) {
        perror("Error writing float to file");
        fclose(file_ptr);
        return 0;
    }

    fclose(file_ptr);
    printf("Data written to '%s' successfully.\n", filename);
    return 0;
}

int read_data_from_file(const char *filename, char *read_string, char *read_char_from_file, int *read_int, float *read_float_from_file) {
    FILE *file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) {
        perror("Error opening file for reading");
        return -1;
    }

    if (fgets(read_string, MAX_STRING_LEN, file_ptr) == NULL) {
        perror("Error reading string from file");
        fclose(file_ptr);
        return -1;
    }
    read_string[strcspn(read_string, "\n")] = 0;

    if (fscanf(file_ptr, "%c", read_char_from_file) != 1) {
        perror("Error reading character from file");
        fclose(file_ptr);
        return -1;
    }
    if (fgetc(file_ptr) == EOF && ferror(file_ptr)) {
        perror("Error consuming newline after character read");
        fclose(file_ptr);
        return -1;
    }

    if (fscanf(file_ptr, "%d", read_int) != 1) {
        perror("Error reading integer from file");
        fclose(file_ptr);
        return -1;
    }
    if (fgetc(file_ptr) == EOF && ferror(file_ptr)) {
        perror("Error consuming newline after integer read");
        fclose(file_ptr);
        return -1;
    }

    if (fscanf(file_ptr, "%f", read_float_from_file) != 1) {
        perror("Error reading float from file");
        fclose(file_ptr);
        return -1;
    }

    fclose(file_ptr);

    return 0;
}

void display_read_data(const char *filename, const char *read_string, char read_char_from_file, int read_int, float read_float_from_file) {
    printf("\nReading data from '%s':\n", filename);
    printf("String: %s\n", read_string);
    printf("Character: %c\n", read_char_from_file);
    printf("Integer: %d\n", read_int);
    printf("Float: %.2f\n", read_float_from_file);
}

int process_file_io() {
    char filename[MAX_FILENAME_LEN];
    char input_string[MAX_STRING_LEN];
    char read_char;
    int input_int;
    float input_float;

    char read_string[MAX_STRING_LEN];
    char read_char_from_file;
    int read_int;
    float read_float_from_file;

    if (get_filename(filename)) {
        return 0;
    }
    if (get_user_inputs(input_string, &read_char, &input_int, &input_float)) {
        return 0;
    }
    if (write_data_to_file(filename, input_string, read_char, input_int, input_float)) {
        return 0;
    }
    if (read_data_from_file(filename, read_string, &read_char_from_file, &read_int, &read_float_from_file)) {
        return 0;
    }

    display_read_data(filename, read_string, read_char_from_file, read_int, read_float_from_file);
    
    return 0;
}

int main(void) {
    process_file_io();
    return 0;
}
