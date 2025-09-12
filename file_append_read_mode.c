/*
 * Purpose: Demonstrates file operations using "a+" mode (append and read).
 *          It reads a line from input, appends it to a file,
 *          then reads from the file up to a specified delimiter and prints it.
 * Topic: File I/O, String Handling
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 100
#define FILENAME "files/08-input.txt"

int get_user_input(char *input_buffer, int buffer_size) {
    printf("Enter a line of text to append to the file: ");
    
    if (fgets(input_buffer, buffer_size, stdin) == NULL) {
        printf("Error reading input.\n");
        return -1; 
    }
    return 0;
}

FILE *open_file_append_read(const char *filename) {
    FILE *file_ptr = fopen(filename, "a+");
    
    if (file_ptr == NULL) {
        perror("Error opening file in 'a+' mode");
    }
    return file_ptr;
}

int append_to_file(FILE *file_ptr, const char *input_buffer) {
    if (fprintf(file_ptr, "\n%s", input_buffer) < 0) {
        perror("Error writing to file");
        return -1;
    }
    return 0;
}

int seek_to_beginning(FILE *file_ptr) {
    if (fseek(file_ptr, 0, SEEK_SET)) {
        perror("Error seeking to beginning of file");
        return -1;
    }
    return 0;
}

void read_and_display_file_content(FILE *file_ptr) {
    char read_buffer[BUFFER_SIZE];
    printf("File content:\n");
    printf("------------------------\n");
    
    // Loop through the file, reading and printing each line
    while (fgets(read_buffer, BUFFER_SIZE, file_ptr) != NULL) {
        printf("%s", read_buffer);
    }
    
    if (ferror(file_ptr)) {
        perror("Error reading from file");
    }
    printf("------------------------\n");
}

void close_file(FILE *file_ptr) {
    if (fclose(file_ptr)) {
        perror("Error closing file");
    }
}

int main(void) {
    char input_buffer[BUFFER_SIZE];
    char read_buffer[BUFFER_SIZE];
    
    if (get_user_input(input_buffer, BUFFER_SIZE) == -1) {
        return 0;
    }
    
    FILE *file_append_read = open_file_append_read(FILENAME);
    if (file_append_read == NULL) {
        return 0;
    }
    
    if (append_to_file(file_append_read, input_buffer) == -1) {
        close_file(file_append_read);
        return 0;
    }
    
    if (seek_to_beginning(file_append_read) == -1) {
        close_file(file_append_read);
        return 0;
    }
    
    read_and_display_file_content(file_append_read);
    
    close_file(file_append_read);
    
    return 0;
}
