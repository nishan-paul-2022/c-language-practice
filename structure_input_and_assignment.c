/*
 * Purpose: Demonstrates reading user input into a string and assigning it to a structure member using functions, highlighting safe input practices.
 * Topic: Structures, String Input
 */

#include <stdio.h>
#include <string.h>


typedef struct {
    int integer_value;
    double double_value;
    char string_value[100];
} ExampleStructure;


void read_string(char *buffer, size_t size, const char *prompt) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0; 
    } else {
        fprintf(stderr, "Error reading input.\n");
        buffer[0] = '\0'; 
    }
}


void initialize_structure(ExampleStructure *s, int int_val, double dbl_val, const char *str_val) {
    s->integer_value = int_val;
    s->double_value = dbl_val;
    strcpy(s->string_value, str_val);
}


void print_structure(const ExampleStructure *s) {
    printf("Integer: %d\n", s->integer_value);
    printf("Double: %.2lf\n", s->double_value);
    printf("String: %s\n", s->string_value);
}

int main(void) {
    ExampleStructure my_struct;
    char input_string[100];

    
    read_string(input_string, sizeof(input_string), "Enter a string: ");

    
    initialize_structure(&my_struct, 10, 10.12345, input_string);

    
    print_structure(&my_struct);

    return 0;
}
