/*
 * Purpose: Demonstrates copying a binary file byte by byte from one file to another.
 * Topic: Binary File I/O, File Copying
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    char source_file_path[] = "files/01-img-a.jpg";
    char destination_file_path[] = "files/01-img-b.jpg";

    // Open source file in binary read mode
    FILE *source_file_ptr = fopen(source_file_path, "rb");
    if (source_file_ptr == NULL) {
        perror("Error opening source file");
        return 0;
    }

    // Open destination file in binary write mode
    FILE *destination_file_ptr = fopen(destination_file_path, "wb");
    if (destination_file_ptr == NULL) {
        perror("Error opening destination file");
        fclose(source_file_ptr);
        return 0;
    }

    // Copy bytes from source to destination until EOF
    int byte_read;
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

    // Close files
    fclose(source_file_ptr);
    fclose(destination_file_ptr);

    printf("File copied successfully from %s to %s\n", source_file_path, destination_file_path);

    return 0;
}
