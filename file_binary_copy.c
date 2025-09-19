/*
 * Purpose: Demonstrates copying a binary file byte by byte from one file to another.
 * Topic: Binary File I/O, File Copying
 */

#include <stdio.h>
#include <stdlib.h>

FILE* open_file(const char *filepath, const char *mode) {
    FILE *file_pointer = fopen(filepath, mode);

    if (file_pointer == NULL) {
        perror("Error opening file");
    }
    
    return file_pointer;
}

int copy_file_bytes(FILE *source, FILE *destination) {
    int byte_read;
    
    while ((byte_read = fgetc(source)) != EOF) {
        if (fputc(byte_read, destination) == EOF) {
            perror("Error writing byte to destination file");
            return -1;
        }
    }
    
    if (ferror(source)) {
        perror("Error reading from source file");
        return -1;
    }
    
    return 0;
}

void close_file(FILE *file_pointer) {
    if (file_pointer != NULL) {
        fclose(file_pointer);
    }
}

int main(void) {
    char source_file_path[] = "files/01-img-a.jpg";
    char destination_file_path[] = "files/01-img-b.jpg";
    
    FILE *source_file_pointer = open_file(source_file_path, "rb");
    if (source_file_pointer == NULL) {
        return 0;
    }
    
    FILE *destination_file_pointer = open_file(destination_file_path, "wb");
    if (destination_file_pointer == NULL) {
        close_file(source_file_pointer);
        return 0;
    }
    
    if (copy_file_bytes(source_file_pointer, destination_file_pointer) == 0) {
        printf("File copied successfully from %s to %s\n", source_file_path, destination_file_path);
    }
    
    close_file(source_file_pointer);
    close_file(destination_file_pointer);
    
    return 0;
}
