// Purpose: Demonstrates copying a binary file byte by byte from one file to another.
// Topic: Binary File I/O, File Copying

#include <stdio.h>
#include <stdlib.h> // For exit()

int main() {
    FILE *source_file_ptr = NULL;
    FILE *destination_file_ptr = NULL;
    int byte_read;

    // Open the source file in binary read mode
    source_file_ptr = fopen("iron-Bat.jpg", "rb");
    if (source_file_ptr == NULL) {
        perror("Error opening source file");
        return 1; // Indicate an error
    }

    // Open the destination file in binary write mode
    destination_file_ptr = fopen("ironman+Batman.jpg", "wb");
    if (destination_file_ptr == NULL) {
        perror("Error opening destination file");
        fclose(source_file_ptr); // Close source file before exiting
        return 1; // Indicate an error
    }

    // Read from source file and write to destination file byte by byte
    // The loop condition can be written more concisely:
    // while ((byte_read = fgetc(source_file_ptr)) != EOF)
    while ((byte_read = fgetc(source_file_ptr)) != EOF) {
        if (fputc(byte_read, destination_file_ptr) == EOF) {
            perror("Error writing byte to destination file");
            fclose(source_file_ptr);
            fclose(destination_file_ptr);
            return 1;
        }
    }

    // Check if the loop terminated due to a read error
    if (ferror(source_file_ptr)) {
        perror("Error reading from source file");
        fclose(source_file_ptr);
        fclose(destination_file_ptr);
        return 1;
    }

    // Close the files
    fclose(source_file_ptr);
    fclose(destination_file_ptr);

    printf("File copied successfully from iron-Bat.jpg to ironman+Batman.jpg\n");

    return 0; // Indicate success
}
