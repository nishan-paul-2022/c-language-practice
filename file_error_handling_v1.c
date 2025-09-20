/*
 * Purpose: Demonstrates file error checking using ferror() and clearing error flags with clearerr().
 *          It attempts an invalid write operation on a read-only file stream
 *          to trigger an error, then checks and clears the error indicator.
 * Topic: File I/O, Error Handling
 */

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "files/file_error_handling_v1.txt"

FILE *open_file_read_only(const char *filename) {
    FILE *file_handle = fopen(filename, "r");
    
    if (file_handle == NULL) {
        perror("Error opening file for reading");
    }
    
    return file_handle;
}

void attempt_write_and_check_error(FILE *file_handle, char character) {
    if (fputc(character, file_handle) == EOF) {
        if (ferror(file_handle)) {
            printf("An error occurred during write operation (as expected).\n");
        } else {
            printf("fputc failed, but ferror() did not report an error.\n");
        }
    } else {
        printf("Unexpected fputc succeeded on a read-only stream.\n");
    }
}

void clear_and_check_error(FILE *file_handle) {
    clearerr(file_handle);
    
    if (ferror(file_handle)) {
        printf("ferror() still indicates an error after clearerr().\n");
    } else {
        printf("Error indicator cleared successfully.\n");
    }
}

void close_file(FILE *file_handle) {
    if (fclose(file_handle)) {
        perror("Error closing file");
    }
}

int main(void) {
    char character_to_write = 'X';
    
    FILE *file_handle = open_file_read_only(FILENAME);
    if (file_handle == NULL) {
        return 0;
    }
    
    attempt_write_and_check_error(file_handle, character_to_write);
    clear_and_check_error(file_handle);
    close_file(file_handle);
    
    return 0;
}
