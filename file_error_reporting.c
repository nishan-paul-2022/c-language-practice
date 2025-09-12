/*
 * Purpose: Demonstrates reporting file opening errors using perror.
 * Topic: File I/O, Error Handling, perror
 */

#include <stdio.h>
#include <stdlib.h>

FILE *attempt_file_open(const char *filename) {
    FILE *file_pointer = fopen(filename, "r");
    
    if (file_pointer == NULL) {
        perror("File operation error");
        return NULL;
    } else {
        printf("File '%s' opened successfully (and then closed).\n", filename);
        return file_pointer;
    }
}

void close_file(FILE *file_pointer) {
    if (file_pointer != NULL) {
        fclose(file_pointer);
    }
}

int main(void) {
    const char *filename = "files/11-input.txt";
    
    FILE *file_pointer = attempt_file_open(filename);
    
    if (file_pointer == NULL) {
        return 0;
    }
    
    close_file(file_pointer);
    return 0;
}
