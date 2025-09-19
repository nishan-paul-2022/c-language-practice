/*
 * Purpose: Reads data of different types (char, string, int, float) from an input file
 *          ('files/05-input.txt') and writes them to an output file ('files/05-output.txt') with tab separation.
 * Topic: File I/O, Data Type Handling
 */

#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILENAME "files/05-input.txt"
#define OUTPUT_FILENAME "files/05-output.txt"
#define BUFFER_SIZE 100

// Print program header and information
void print_header() {
    printf("=== File Data Processor ===\n");
    printf("Reading from: %s\n", INPUT_FILENAME);
    printf("Writing to: %s\n", OUTPUT_FILENAME);
    printf("Expected format: char string integer float\n\n");
}

// Open input file with error handling
FILE* open_input_file() {
    FILE *file = fopen(INPUT_FILENAME, "r");
    if (file == NULL) {
        perror("Error opening input file");
    }
    return file;
}

// Open output file with error handling
FILE* open_output_file() {
    FILE *file = fopen(OUTPUT_FILENAME, "w");
    if (file == NULL) {
        perror("Error opening output file");
    }
    return file;
}

// Read data from input file
int read_file_data(FILE *file, char *first_char, char *string_buffer, int *integer_value, float *float_value) {
    if (fscanf(file, "%c %s %d %f", first_char, string_buffer, integer_value, float_value) != 4) {
        fprintf(stderr, "Invalid file format in '%s'\n", INPUT_FILENAME);
        return -1;
    }
    return 0;
}

// Write data to output file
int write_file_data(FILE *file, char first_char, const char *string_buffer, int integer_value, float float_value) {
    if (fprintf(file, "%c %s %d %.2f\n", first_char, string_buffer, integer_value, float_value) < 0) {
        perror("Error writing to output file");
        return -1;
    }
    return 0;
}

// Close file with error handling
int close_file(FILE *file, const char *filename) {
    if (fclose(file)) {
        fprintf(stderr, "Error closing file '%s'\n", filename);
        return -1;
    }
    return 0;
}

// Display the processed data
void display_data(char first_char, const char *string_buffer, int integer_value, float float_value) {
    printf("Data processed:\n");
    printf("Character: %c\n", first_char);
    printf("String: %s\n", string_buffer);
    printf("Integer: %d\n", integer_value);
    printf("Float: %.2f\n\n", float_value);
}

int main(void) {
    FILE *file_input, *file_output;
    char first_char;
    char string_buffer[BUFFER_SIZE];
    int integer_value;
    float float_value;

    print_header();

    file_input = open_input_file();
    if (file_input == NULL) {
        return 0;
    }

    if (read_file_data(file_input, &first_char, string_buffer, &integer_value, &float_value) == -1) {
        fclose(file_input);
        return 0;
    }

    fclose(file_input);

    display_data(first_char, string_buffer, integer_value, float_value);

    file_output = open_output_file();
    if (file_output == NULL) {
        return 0;
    }

    if (write_file_data(file_output, first_char, string_buffer, integer_value, float_value) == -1) {
        fclose(file_output);
        return 0;
    }

    if (close_file(file_output, OUTPUT_FILENAME) == -1) {
        return 0;
    }

    printf("Data copied from '%s' to '%s'\n", INPUT_FILENAME, OUTPUT_FILENAME);

    return 0;
}
