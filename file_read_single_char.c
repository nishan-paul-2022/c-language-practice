/*
 * Purpose: Demonstrates reading a single character from a text file and displaying it.
 * Topic: Text File I/O, Reading Data
 */

#include <stdio.h>
#include <stdlib.h>

FILE* open_file(const char *filename) {
    FILE *fp = fopen(filename, "r"); 
    if (fp == NULL) {
        perror("Error opening file");
    }
    return fp;
}

int read_single_char(FILE *fp) {
    if (fp == NULL) {
        return EOF;
    }
    int c = getc(fp); 
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
        fclose(fp); 
    }
}

int main(void) {
    const char *filename = "files/file_read_single_char.txt";
    FILE *file_ptr = open_file(filename);
    int char_read = read_single_char(file_ptr);
    
    if (char_read != EOF) {
        printf("First character read from file: %c\n", (char)char_read); 
    }
    
    close_file(file_ptr);
    return 0;
}
