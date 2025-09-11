/*
 * Purpose: Reads data of different types (char, string, int, float) from an input file
 *          ('a.txt') and writes them to an output file ('new.txt') with tab separation.
 * Topic: File I/O, Data Type Handling
 */

#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILENAME "a.txt"
#define OUTPUT_FILENAME "new.txt"
#define BUFFER_SIZE 100 // For string reading

int main(void) {
    FILE *file_input, *file_output;
    char first_char;
    char string_buffer[BUFFER_SIZE];
    int integer_value;
    float float_value;

    // Open the input file in read mode
    file_input = fopen(INPUT_FILENAME, "r");
    if (file_input == NULL) {
        perror("Error opening input file");
        return 0;
    }

    // Read data from the input file.
    // The format string "%c %[^\n] %d %f" reads:
    // %c: a single character into first_char.
    // ' ': skips any whitespace.
    // %[^\n]: reads characters into string_buffer until a newline is encountered.
    // ' ': skips any whitespace.
    // %d: reads an integer into integer_value.
    // ' ': skips any whitespace.
    // %f: reads a float into float_value.
    // It's crucial that the input file adheres strictly to this format.
    if (fscanf(file_input, "%c %[^\n] %d %f", &first_char, string_buffer, &integer_value, &float_value) != 4) {
        // Check if all 4 items were successfully read.
        fprintf(stderr, "Error: Could not read all expected data from '%s'. Check file format.\n", INPUT_FILENAME);
        fclose(file_input);
        return 0;
    }

    // Close the input file as we have read all necessary data.
    fclose(file_input);

    // Open the output file in write mode
    file_output = fopen(OUTPUT_FILENAME, "w");
    if (file_output == NULL) {
        perror("Error opening output file");
        return 0;
    }

    // Write the read data to the output file, separated by tabs.
    if (fprintf(file_output, "%c\t%s\t%d\t%.6f\n", first_char, string_buffer, integer_value, float_value) < 0) {
        perror("Error writing to output file");
        fclose(file_output);
        return 0;
    }

    // Close the output file
    if (fclose(file_output) != 0) {
        perror("Error closing output file");
        return 0;
    }

    printf("Data successfully copied from '%s' to '%s'.\n", INPUT_FILENAME, OUTPUT_FILENAME);

    return 0;
}
