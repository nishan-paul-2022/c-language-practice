/*
 * Purpose: Demonstrates writing a character using `fputc` and reading it back, with corrected file handling.
 * Topic: Text File I/O, Character I/O
 */

#include <stdio.h>
#include <stdlib.h>

FILE *open_file_write_read(const char *filename) {
    FILE *file_ptr = fopen(filename, "w+");
    
    if (file_ptr == NULL) {
        perror("Error opening file for writing/reading");
    }
    return file_ptr;
}

int write_character_to_file(FILE *file_ptr, char character) {
    if (fputc(character, file_ptr) == EOF) {
        perror("Error writing character to file");
        return 0;
    }
    printf("Wrote character '%c' to file.\n", character);
    return 1;
}

int read_character_from_file(FILE *file_ptr) {
    rewind(file_ptr);
    
    int char_read = getc(file_ptr);
    
    if (char_read == EOF) {
        if (ferror(file_ptr)) {
            perror("Error reading character from file");
        } else {
            printf("File is empty or could not read the first character after writing.\n");
        }
        return EOF;
    }
    
    printf("Read character '%c' from file.\n", (char)char_read);
    return char_read;
}

void close_file(FILE *file_ptr) {
    if (file_ptr != NULL) {
        fclose(file_ptr);
    }
}

int main(void) {
    char char_to_write = 'A';
    
    FILE *file_ptr = open_file_write_read("files/12-input.txt");
    if (file_ptr == NULL) {
        return 0;
    }
    
    if (!write_character_to_file(file_ptr, char_to_write)) {
        close_file(file_ptr);
        return 0;
    }
    
    if (read_character_from_file(file_ptr) == EOF) {
        close_file(file_ptr);
        return 0;
    }
    
    close_file(file_ptr);
    
    return 0;
}
