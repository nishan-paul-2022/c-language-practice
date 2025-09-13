/* 
 * Purpose: Reads a floating-point number, calculates its ceiling, and prints that many asterisks. 
 * Topic: Floating-Point Numbers, Math Functions (ceil), Loops, Character Output, Input Handling 
 */

#include <stdio.h>
#include <math.h>

float get_float_input(const char *prompt) {
    float value;
    printf("%s", prompt);
    if (scanf("%f", &value) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter a floating-point number.\n");
        while (getchar() != '\n');
        return NAN;
    }
    return value;
}

void print_chars(char ch, int count) {
    for (int i = 0; i < count; i++) {
        printf("%c", ch);
    }
    printf("\n");
}

int main(void) {
    float input_value = get_float_input("Enter a floating-point number: ");
    if (isnan(input_value)) {
        return 0;
    }

    int ceiling_value = (int)ceil(input_value);
    print_chars('*', ceiling_value);

    return 0;
}
