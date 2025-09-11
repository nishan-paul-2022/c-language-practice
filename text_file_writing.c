/*
 * Purpose: Demonstrates writing different data types (string, character) to a text file using fprintf, fputs, and putc.
 * Topic: Text File I/O, Writing Data
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *output_file_ptr = NULL;
    const char *string_to_write = "This is a sample string.";
    char char_to_write = '!';
    int number_to_write = 12345;

    // Open the file for writing in text mode.
    // "w" mode truncates the file if it exists, or creates it if it doesn't.
    output_file_ptr = fopen("text_file_writing_example.txt", "w");
    if (output_file_ptr == NULL) {
        perror("Error opening file for writing");
        return 0;
    }

    // Write a formatted string using fprintf
    // fprintf is versatile and can write formatted data like numbers and strings.
    if (fprintf(output_file_ptr, "Formatted number: %d\n", number_to_write) < 0) {
        perror("Error writing formatted string with fprintf");
        fclose(output_file_ptr);
        return 0;
    }

    // Write a string using fputs
    // fputs writes a string but does not automatically append a newline.
    if (fputs("String written with fputs.\n", output_file_ptr) == EOF) {
        perror("Error writing string with fputs");
        fclose(output_file_ptr);
        return 0;
    }

    // Write a single character using putc
    // putc writes a single character.
    if (putc(char_to_write, output_file_ptr) == EOF) {
        perror("Error writing character with putc");
        fclose(output_file_ptr);
        return 0;
    }
    // Add a newline after the character for better readability in the file
    if (putc('\n', output_file_ptr) == EOF) {
        perror("Error writing newline after putc");
        fclose(output_file_ptr);
        return 0;
    }


    // Close the file
    fclose(output_file_ptr);

    printf("Successfully wrote to text_file_writing_example.txt\n");

    return 0;
}
