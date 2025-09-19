/*
 * Purpose: Demonstrates writing and reading a structure to/from a binary file using fwrite and fread.
 * Topic: Structure, Binary File I/O
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[10];
    char college[10];
    char department[10];
    char year[10];
    char area[10];
} StudentData;

void write_structure(FILE *file_ptr, const StudentData *data) {
    if (fwrite(data, sizeof(StudentData), 1, file_ptr) != 1) {
        if (ferror(file_ptr)) perror("Error writing structure to file");
        else fprintf(stderr, "Incomplete write of structure.\n");
        fclose(file_ptr);
        exit(0);
    }
}

void read_structure(FILE *file_ptr, StudentData *data) {
    rewind(file_ptr);
    if (fread(data, sizeof(StudentData), 1, file_ptr) != 1) {
        if (ferror(file_ptr)) perror("Error reading structure from file");
        else fprintf(stderr, "Could not read structure.\n");
        fclose(file_ptr);
        exit(0);
    }
}

void print_student_data(const StudentData *data) {
    printf("Name: %s\n", data->name);
    printf("College: %s\n", data->college);
    printf("Department: %s\n", data->department);
    printf("Year: %s\n", data->year);
    printf("Area: %s\n", data->area);
}

int main(void) {
    StudentData data_write = {"UC", "Berkeley", "BAIR"};
    StudentData data_read;

    FILE *file_ptr = fopen("files/28-input.txt", "wb+");
    if (file_ptr == NULL) {
        perror("Error opening file");
        return 0;
    }

    write_structure(file_ptr, &data_write);
    read_structure(file_ptr, &data_read);
    print_student_data(&data_read);

    fclose(file_ptr);
    
    return 0;
}
