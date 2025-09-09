// Purpose: Demonstrates writing and reading a structure to/from a binary file using fwrite and fread.
// Topic: Structure, Binary File I/O

#include <stdio.h>
#include <stdlib.h> // For exit()
#include <string.h> // For strcpy and NULL

// Define a structure to hold data
typedef struct {
    char name[10];
    char college[10];
    char department[10];
    char year[10];
    char area[10];
} StudentData;

int main() {
    FILE *file_ptr;
    StudentData data_to_write = {"nishan", "cuet", "cse", "16", "ai"};
    StudentData data_read;

    // Open the file for writing and reading in binary mode.
    // "wb+" mode truncates the file if it exists, or creates it if it doesn't.
    // Using binary mode is important for fwrite/fread to avoid text translations.
    file_ptr = fopen("FH fwrite & fread.txt", "wb+");
    if (file_ptr == NULL) {
        perror("Error opening file for writing");
        return 0;
    }

    // Write the structure to the file
    size_t items_written = fwrite(&data_to_write, sizeof(StudentData), 1, file_ptr);
    if (items_written != 1) {
        if (ferror(file_ptr)) {
            perror("Error writing structure to file");
        } else {
            fprintf(stderr, "Error: Incomplete write of structure to file.\n");
        }
        fclose(file_ptr);
        return 1;
    }

    // Rewind the file pointer to the beginning of the file to read what was written.
    rewind(file_ptr);

    // Read the structure back from the file
    size_t items_read = fread(&data_read, sizeof(StudentData), 1, file_ptr);
    if (items_read != 1) {
        if (ferror(file_ptr)) {
            perror("Error reading structure from file");
        } else {
            fprintf(stderr, "Error: Could not read structure from file.\n");
        }
        fclose(file_ptr);
        return 1;
    }

    // Print the members of the structure
    // Using %s assumes the data read is null-terminated.
    // If the original strings were exactly 9 characters long, they might not have been null-terminated
    // by strcpy if they filled the buffer. However, the provided strings are shorter.
    printf("Name: %s\n", data_read.name);
    printf("College: %s\n", data_read.college);
    printf("Department: %s\n", data_read.department);
    printf("Year: %s\n", data_read.year);
    printf("Area: %s\n", data_read.area);

    // Close the file
    fclose(file_ptr);

    return 0; // Indicate success
}
