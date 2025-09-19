/*
 * Purpose: Demonstrates reading a single character from a text file and displaying it.
 * Topic: Text File I/O, Reading Data
 */

#include <stdio.h>
#include <stdlib.h>

FILE* open_file(const char *filename) {
    FILE *fp = fopen(filename, "r"); // Open file in text mode
    if (fp == NULL) {
        perror("Error opening file");
    }
    return fp;
}

int read_single_char(FILE *fp) {
    if (fp == NULL) {
        return EOF;
    }
    int c = getc(fp); // Read a single character
    if (c == EOF) {
        if (ferror(fp)) {
            perror("Error reading character");
        } else {
            printf("File is empty or cannot read first character.\n");
        }
    }
    return c;
}

void close_file(FILE *fp) {
    if (fp != NULL) {
        fclose(fp); // Close file
    }
}

int main(void) {
    const char *filename = "files/27-input.txt";
    FILE *file_ptr = open_file(filename);
    int char_read = read_single_char(file_ptr);
    
    if (char_read != EOF) {
        printf("First character read from file: %c\n", (char)char_read); // Display character
    }
    
    close_file(file_ptr);
    return 0;
}
