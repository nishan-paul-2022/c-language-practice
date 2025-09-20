/*
 * Purpose: Reads a floating-point number as a string to reliably extract the last digit of the integer and fractional parts.
 * Topic: String Manipulation, Character Handling
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int get_last_integer_digit(const char *str, char **dot_pos) {
    *dot_pos = strchr(str, '.');
    if (*dot_pos != NULL) { 
        if (*dot_pos > str) {
            
            return (*(*dot_pos - 1)) - '0';
        } else {
            
            return 0;
        }
    } else { 
        int len = strlen(str);
        if (len > 0) {
            return str[len - 1] - '0';
        }
    }
    return 0; 
}

int get_last_fractional_digit(const char *dot_pos) {
    if (dot_pos != NULL) {
        int len = strlen(dot_pos);
        if (len > 1) {
            
            return dot_pos[len - 1] - '0';
        }
    }
    return 0; 
}

int main(void) {
    char input_str[100];
    char *dot_position = NULL;

    printf("Enter a floating-point value (e.g., 123.45): ");
    scanf("%s", input_str);

    int last_int_digit = get_last_integer_digit(input_str, &dot_position);
    int last_frac_digit = get_last_fractional_digit(dot_position);

    printf("The last digit of the integer part is: %d\n", last_int_digit);
    printf("The last digit of the fractional part is: %d\n", last_frac_digit);

    return 0;
}
