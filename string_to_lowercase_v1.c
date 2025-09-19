/*
 * Purpose: Converts all uppercase letters in a string to lowercase.
 * Topic: String Manipulation, Character Conversion, Input Validation
 */

#include <stdio.h>
#include <string.h>

void clear_input_buffer() {
    while (getchar() != '\n');
}

int get_buffer_size(int max_size) {
    int buffer_size;
    printf("Enter the maximum string length (e.g., 255 for a buffer of 256):\n");
    
    if (scanf("%d", &buffer_size) != 1 || buffer_size <= 0 || buffer_size >= max_size) {
        fprintf(stderr, "Invalid buffer size entered. Using default buffer size of %d.\n", max_size - 1);
        buffer_size = max_size - 1;
    }
    clear_input_buffer();
    return buffer_size;
}

int get_input_string(char *input_string, int buffer_size, int max_buffer_size) {
    printf("Enter a string (max %d characters):\n", buffer_size);
    
    if (fgets(input_string, max_buffer_size, stdin) == NULL) {
        fprintf(stderr, "Error reading input string.\n");
        return -1;
    }
    
    input_string[strcspn(input_string, "\n")] = 0; 
    
    return 0;
}

int validate_string_length(const char *input_string, int buffer_size) {
    int str_length = strlen(input_string);
    
    if (str_length > buffer_size) {
        printf("Input string exceeds the specified buffer size.\n");
        return -1;
    }

    return 0;
}

void convert_to_lowercase(char *input_string) {
    for (int char_index = 0; input_string[char_index] != '\0'; char_index++) {
        if (input_string[char_index] >= 'A' && input_string[char_index] <= 'Z') {
            input_string[char_index] = input_string[char_index] + 32; 
        }
    }
}

void display_result(const char *input_string) {
    printf("%s\n", input_string);
}

int main(void) {
    char input_string[256];
    const int max_buffer_size = sizeof(input_string);
    
    int buffer_size = get_buffer_size(max_buffer_size);
    
    if (get_input_string(input_string, buffer_size, max_buffer_size) == 0 && validate_string_length(input_string, buffer_size) == 0) {
        convert_to_lowercase(input_string);
        display_result(input_string);
    }
    
    return 0;
}