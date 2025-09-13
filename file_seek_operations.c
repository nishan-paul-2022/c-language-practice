/*
 * Purpose: Demonstrates various uses of fseek with different whence values (SEEK_CUR) and data types.
 * Topic: File I/O (fseek, fgets, fscanf, puts, printf, sprintf)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "FH fseek.txt"
#define BUFFER_SIZE 100
#define FORMATTED_SIZE 256

int get_user_input(int *num1, int *num2, char *string) {
    printf("Enter an integer, another integer, and a string: ");
    if (scanf("%d %d %99s", num1, num2, string) != 3) {
        perror("Error reading input");
        return -1;
    }
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    return 0;
}

void format_input_data(char *buffer, int num1, int num2, const char *string) {
    sprintf(buffer, "%d %d %s", num1, num2, string);
}

int create_sample_file(const char *filename) {
    FILE *file_ptr = fopen(filename, "w");
    if (file_ptr == NULL) {
        perror("Error creating sample file");
        return -1;
    }
    
    fprintf(file_ptr, "SampleString12345 10 20 30 40 50\n");
    fclose(file_ptr);
    printf("Created %s with sample data...\n", filename);
    return 0;
}

FILE* open_file_for_reading(const char *filename) {
    FILE *file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) {
        perror("Error opening file for reading");
        if (create_sample_file(filename) == 0) {
            file_ptr = fopen(filename, "r");
            if (file_ptr == NULL) {
                perror("Error reopening file for reading");
            }
        }
    }
    return file_ptr;
}

int first_seek_and_read(FILE *file_ptr, char *buffer, int size) {
    if (fseek(file_ptr, sizeof(char) * 3, SEEK_CUR)) {
        perror("Error seeking in file (first seek)");
        return -1;
    }

    if (fgets(buffer, size, file_ptr) == NULL) {
        if (feof(file_ptr)) {
            fprintf(stderr, "Reached end of file while reading after first seek.\n");
        } else {
            perror("Error reading string after first seek");
        }
        return -1;
    }
    
    return 0;
}

int second_seek_and_read_integers(FILE *file_ptr, int *num1, int *num2, int *num3) {
    if (fseek(file_ptr, sizeof(char) * 5, SEEK_CUR)) {
        perror("Error seeking in file (second seek)");
        return -1;
    }

    if (fscanf(file_ptr, "%d %d %d", num1, num2, num3) != 3) {
        if (feof(file_ptr)) {
            fprintf(stderr, "Reached end of file or invalid format for first integer read after second seek.\n");
        } else {
            perror("Error reading first set of integers after second seek");
        }
        return -1;
    }
    
    return 0;
}

int backward_seek(FILE *file_ptr) {
    if (fseek(file_ptr, -sizeof(char) * 1, SEEK_CUR)) {
        perror("Error seeking backward in file");
        return -1;
    }
    return 0;
}

int fourth_seek_and_read(FILE *file_ptr, int *num4, int *num5, int *num3) {
    if (fseek(file_ptr, sizeof(int) * 2, SEEK_CUR)) {
        perror("Error seeking in file (fourth seek)");
        return -1;
    }

    if (fscanf(file_ptr, "%d %d %d", num4, num5, num3) != 3) {
        if (feof(file_ptr)) {
            fprintf(stderr, "Reached end of file or invalid format for second integer read after fourth seek.\n");
        } else {
            perror("Error reading second set of integers after fourth seek");
        }
        return -1;
    }
    
    return 0;
}

void display_first_read_result(const char *buffer) {
    printf("String read after first fseek (skipping 3 chars): %s", buffer);
}

void display_second_read_result(int num1, int num2, int num3) {
    printf("Integers read after second fseek: %d %d %d\n", num1, num2, num3);
}

void display_fourth_read_result(int num4, int num5, int num3) {
    printf("Integers read after fourth fseek: %d %d %d\n", num4, num5, num3);
}

int close_file_safely(FILE *file_ptr) {
    if (fclose(file_ptr)) {
        perror("Error closing file");
        return -1;
    }
    return 0;
}

int main(void) {
    FILE *file_ptr = NULL;
    char input_buffer_s[BUFFER_SIZE];
    char input_buffer_t[BUFFER_SIZE];
    char formatted_string[FORMATTED_SIZE];
    int num1, num2, num3, num4, num5;

    if (get_user_input(&num1, &num2, input_buffer_s)) {
        return 0;
    }

    format_input_data(formatted_string, num1, num2, input_buffer_s);

    file_ptr = open_file_for_reading(FILENAME);
    if (file_ptr == NULL) {
        return 0;
    }

    if (first_seek_and_read(file_ptr, input_buffer_t, BUFFER_SIZE)) {
        close_file_safely(file_ptr);
        return 0;
    }
    display_first_read_result(input_buffer_t);

    if (second_seek_and_read_integers(file_ptr, &num1, &num2, &num3)) {
        close_file_safely(file_ptr);
        return 0;
    }
    display_second_read_result(num1, num2, num3);

    if (backward_seek(file_ptr)) {
        close_file_safely(file_ptr);
        return 0;
    }

    if (fourth_seek_and_read(file_ptr, &num4, &num5, &num3)) {
        close_file_safely(file_ptr);
        return 0;
    }
    display_fourth_read_result(num4, num5, num3);

    if (close_file_safely(file_ptr)) {
        return 0;
    }

    return 0;
}
