/*
 * Purpose: Copies the content of an input file to an output file by reading it 
 *          character by character after determining the file size using fseek() and ftell().
 * Topic: File I/O, File Manipulation
 */

#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILENAME "files/file_copy_char_by_char_a.txt"
#define OUTPUT_FILENAME "files/file_copy_char_by_char_b.txt"

void print_header() {
    printf("=== File Copier ===\n");
    printf("Source: %s\n", INPUT_FILENAME);
    printf("Destination: %s\n\n", OUTPUT_FILENAME);
}

FILE* open_input_file() {
    FILE *file = fopen(INPUT_FILENAME, "r");
    if (file == NULL) {
        perror("Error opening input file");
        fprintf(stderr, "Please ensure '%s' exists.\n", INPUT_FILENAME);
    }
    return file;
}

FILE* open_output_file() {
    FILE *file = fopen(OUTPUT_FILENAME, "w");
    if (file == NULL) {
        perror("Error opening output file");
    }
    return file;
}

long get_file_size(FILE *file) {
    if (fseek(file, 0, SEEK_END)) {
        perror("Error seeking to end of file");
        return -1;
    }
    
    long size = ftell(file);
    if (size == -1) {
        perror("Error getting file size");
        return -1;
    }
    
    if (fseek(file, 0, SEEK_SET)) {
        perror("Error seeking to beginning of file");
        return -1;
    }
    
    return size;
}

int copy_file_content(FILE *input, FILE *output, long file_size) {
    char character;
    long bytes_copied = 0;
    
    printf("Copying %ld bytes...\n", file_size);
    
    while (file_size > 0) {
        character = fgetc(input);
        
        if (character == EOF) {
            if (ferror(input)) {
                perror("Error reading from input file");
                return -1;
            } else if (feof(input)) {
                printf("Reached EOF earlier than expected\n");
                break;
            }
        }
        
        if (fputc(character, output) == EOF) {
            perror("Error writing to output file");
            return 0;
        }
        
        file_size--;
        bytes_copied++;
    }
    
    printf("Successfully copied %ld bytes\n", bytes_copied);
    
    return 0;
}

int close_file(FILE *file, const char *filename) {
    if (fclose(file)) {
        fprintf(stderr, "Error closing %s\n", filename);
        return -1;
    }
    return 0;
}

int main(void) {
    FILE *input_file, *output_file;
    long file_size;
    
    print_header();
    
    input_file = open_input_file();
    if (input_file == NULL) {
        return 0;
    }
    
    file_size = get_file_size(input_file);
    if (file_size == -1) {
        fclose(input_file);
        return 0;
    }
    
    printf("Input file size: %ld bytes\n", file_size);
    
    output_file = open_output_file();
    if (output_file == NULL) {
        fclose(input_file);
        return 0;
    }
    
    if (copy_file_content(input_file, output_file, file_size) == -1) {
        close_file(input_file, "input file");
        close_file(output_file, "output file");
        return 0;
    }
    
    close_file(input_file, "input file");
    close_file(output_file, "output file");
    
    printf("\nFile copy operation completed successfully!\n");
    
    return 0;
}
