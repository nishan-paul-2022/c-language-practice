/*
 * Purpose: Reads a text file and writes its content in reverse order to a new file.
 * Topic: File I/O, File Reversal
 */

#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILENAME "files/23-input.txt"
#define OUTPUT_FILENAME "files/23-output.txt"

FILE* open_input_file(const char *filename) {
    FILE *input_file = fopen(filename, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return NULL;
    }
    printf("Input file %s opened successfully for reading.\n", filename);
    return input_file;
}

FILE* open_output_file(const char *filename) {
    FILE *output_file = fopen(filename, "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        return NULL;
    }
    printf("Output file %s opened successfully for writing.\n", filename);
    return output_file;
}

long get_file_size(FILE *file) {
    if (fseek(file, 0, SEEK_END)) {
        perror("Error seeking to end of input file");
        return -1;
    }

    long file_size = ftell(file);
    if (file_size == -1) {
        perror("Error getting file size");
        return -1;
    }

    return file_size;
}

int reverse_file_content(FILE *input_file, FILE *output_file, long file_size) {
    char character;
    long i;

    for (i = file_size - 1; i >= 0; i--) {
        if (fseek(input_file, i, SEEK_SET)) {
            perror("Error seeking within input file");
            return -1;
        }

        character = fgetc(input_file);
        if (character == EOF && ferror(input_file)) {
            perror("Error reading character from input file");
            return -1;
        }

        if (fputc(character, output_file) == EOF) {
            perror("Error writing character to output file");
            return -1;
        }
    }

    return 0;
}

void close_files(FILE *input_file, FILE *output_file) {
    if (input_file) fclose(input_file);
    if (output_file) fclose(output_file);
}

void display_success_message(void) {
    printf("File content reversed successfully.\n");
}

int main(void) {
    FILE *input_file = NULL;
    FILE *output_file = NULL;
    long file_size;

    input_file = open_input_file(INPUT_FILENAME);
    if (input_file == NULL) {
        return 0;
    }

    file_size = get_file_size(input_file);
    if (file_size == -1) {
        close_files(input_file, NULL);
        return 0;
    }

    output_file = open_output_file(OUTPUT_FILENAME);
    if (output_file == NULL) {
        close_files(input_file, NULL);
        return 0;
    }

    if (reverse_file_content(input_file, output_file, file_size)) {
        close_files(input_file, output_file);
        return 0;
    }

    display_success_message();

    close_files(input_file, output_file);

    return 0;
}
