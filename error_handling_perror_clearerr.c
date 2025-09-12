/*
 * Purpose: Demonstrates the use of `perror` to print system error messages and `clearerr` to clear stream error indicators.
 * Topic: Error Handling, Standard Library Functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

FILE *attempt_file_open(const char *filename) {
    FILE *file_ptr = fopen(filename, "r");
    
    if (file_ptr == NULL) {
        perror("Error opening file (first call)");
        
        printf("fopen failed, so clearerr() was not called on a valid file pointer.\n");
        
        perror("Error after clearerr attempt (second call)");
    } else {
        printf("Successfully opened file '%s'.\n", filename);
    }
    
    return file_ptr;
}

void close_file(FILE *file_ptr) {
    if (file_ptr != NULL) {
        fclose(file_ptr);
    }
}

int main(void) {
    const char *filename = "files/07-input.txt";
    
    FILE *file_ptr = attempt_file_open(filename);
    close_file(file_ptr);
    
    return 0;
}
