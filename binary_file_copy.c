/*
 * Purpose: Demonstrates copying a binary file byte by byte from one file to another.
 * Topic: Binary File I/O, File Copying
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *source_file_ptr = NULL; // Source file handle for reading
    FILE *destination_file_ptr = NULL; // Destination file handle for writing
    int byte_read; // Storage for each byte read from source

    // Open source file in binary read mode
    source_file_ptr = fopen("files/img-01.jpg", "rb");
    if (source_file_ptr == NULL) {
        perror("Error opening source file");
        return 0;
    }

    // Open destination file in binary write mode
    destination_file_ptr = fopen("files/img-02.jpg", "wb");
    if (destination_file_ptr == NULL) {
        perror("Error opening destination file");
        fclose(source_file_ptr);
        return 0;
    }

    // Copy bytes from source to destination until EOF
    while ((byte_read = fgetc(source_file_ptr)) != EOF) {
        // Write byte to destination file
        if (fputc(byte_read, destination_file_ptr) == EOF) {
            perror("Error writing byte to destination file");
            fclose(source_file_ptr);
            fclose(destination_file_ptr);
            return 0;
        }
    }

    // Verify loop termination was due to EOF, not read error
    if (ferror(source_file_ptr)) {
        perror("Error reading from source file");
        fclose(source_file_ptr);
        fclose(destination_file_ptr);
        return 0;
    }

    // Close both file handles
    fclose(source_file_ptr);
    fclose(destination_file_ptr);

    printf("File copied successfully from files/img-01.jpg to files/img-02.jpg\n");

    return 0;
}
