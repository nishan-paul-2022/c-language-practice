/*
 * Purpose: Reads and prints multiple lines of text entered by the user until end-of-file or error.
 * Topic: String Input/Output, Reading Multiple Lines, Input Safety
 */

#include <stdio.h>
#include <string.h>

int read_buffer_size(int max_size) {
    int size;
    printf("Enter the maximum string length for each line (e.g., 255): "); 
    if (scanf("%d", &size) != 1 || size <= 0 || size >= max_size) {
        fprintf(stderr, "Invalid buffer size entered. Using default buffer size of %d.\n", max_size - 1);
        size = max_size - 1; 
    }
    while (getchar() != '\n'); 
    return size;
}

void read_and_print_lines(int buffer_size) {
    char input_string[256]; 
    printf("Enter lines of text (Ctrl+D/Ctrl+Z to end input):\n");
    while (fgets(input_string, sizeof(input_string), stdin) != NULL) {
        input_string[strcspn(input_string, "\n")] = 0; 
        printf("%s\n", input_string); 
    }
    if (ferror(stdin)) {
        fprintf(stderr, "An error occurred during input.\n");
    }
}

int main(void) {
    int buffer_size = read_buffer_size(sizeof(char) * 256);
    read_and_print_lines(buffer_size);
    return 0;
}
