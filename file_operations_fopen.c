/*
 * Purpose: Demonstrates basic file opening, writing, and closing operations.
 * Topic: File I/O (fopen, fprintf, fclose)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void consume_newline() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int get_filename_and_mode(char *filename, char *mode) {
    printf("Enter the filename (e.g., files/file_operations_fopen.txt): ");
    if (scanf("%100s", filename) != 1) {
        perror("Error reading filename");
        return -1;
    }
    consume_newline();

    printf("Enter the file mode (e.g., 'w', 'a', 'r'): ");
    if (scanf("%99s", mode) != 1) {
        perror("Error reading file mode");
        return -1;
    }
    consume_newline();
    
    return 0;
}

int get_data_inputs(char *input_string, char *input_char, int *input_int, float *input_float) {
    int c;
    
    printf("Enter a string to write to the file: ");
    if (fgets(input_string, 100, stdin) == NULL) {
        perror("Error reading string");
        return -1;
    }
    size_t len_string = strlen(input_string);
    if (len_string > 0 && input_string[len_string - 1] == '\n') {
        input_string[len_string - 1] = '\0';
    }

    printf("Enter a single character: ");
    if (scanf(" %c", input_char) != 1) {
        perror("Error reading character");
        return -1;
    }
    consume_newline();

    printf("Enter an integer: ");
    if (scanf("%d", input_int) != 1) {
        perror("Error reading integer");
        return -1;
    }
    consume_newline();

    printf("Enter a float: ");
    if (scanf("%f", input_float) != 1) {
        perror("Error reading float");
        return -1;
    }
    consume_newline();
    
    return 0;
}

int write_data_to_file(const char *filename, const char *mode, const char *input_string, char input_char, int input_int, float input_float) {
    FILE *file_pointer = fopen(filename, mode);
    
    if (file_pointer == NULL) {
        perror("Error opening file");
        return -1;
    }

    fprintf(file_pointer, "String: %s\n", input_string);
    fprintf(file_pointer, "Character: %c\n", input_char);
    fprintf(file_pointer, "Integer: %d\n", input_int);
    fprintf(file_pointer, "Float: %f\n", input_float);

    if (fclose(file_pointer)) {
        perror("Error closing file");
        return -1;
    }

    return 0;
}

int main(void) {
    char filename[100];
    char mode[100];
    char input_string[100];
    char input_char;
    int input_int;
    float input_float;

    if (get_filename_and_mode(filename, mode) == -1) {
        return 0;
    }

    if (get_data_inputs(input_string, &input_char, &input_int, &input_float) == -1) {
        return 0;
    }

    if (write_data_to_file(filename, mode, input_string, input_char, input_int, input_float) == -1) {
        return 0;
    }

    printf("Data successfully written to '%s' in mode '%s'.\n", filename, mode);
    
    return 0;
}
