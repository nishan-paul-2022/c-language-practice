/*
 * Purpose: Demonstrates using ftell to get the current file position, typically used to find file size.
 * Topic: File I/O (ftell, fseek)
 */

#include <stdio.h>
#include <stdlib.h>

int create_sample_file(const char *filename) {
    FILE *prep_file = fopen(filename, "w");
    if (prep_file == NULL) {
        perror("Error preparing file for ftell demonstration");
        return -1;
    }
    
    fprintf(prep_file, "This is some sample text for ftell demonstration.\n");
    fprintf(prep_file, "It contains multiple lines and characters.\n");
    fclose(prep_file);
    return 0;
}

long int get_file_size(const char *filename) {
    FILE *file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) {
        perror("Error opening file for ftell demonstration");
        return -1L;
    }

    if (fseek(file_ptr, 0, SEEK_END)) {
        perror("Error seeking to end of file");
        fclose(file_ptr);
        return -1L;
    }

    long int file_size = ftell(file_ptr);
    if (file_size == -1L) {
        perror("Error getting file position with ftell");
        fclose(file_ptr);
        return -1L;
    }

    if (fclose(file_ptr)) {
        perror("Error closing file");
        return -1L;
    }

    return file_size;
}

void display_file_size(const char *filename, long int size) {
    printf("The size of the file '%s' is: %ld bytes\n", filename, size);
}

int main(void) {
    const char *filename = "lab6.txt";
    long int file_size;

    if (create_sample_file(filename)) {
        return 0;
    }

    file_size = get_file_size(filename);
    if (file_size == -1L) {
        return 0;
    }

    display_file_size(filename, file_size);

    return 0;
}
