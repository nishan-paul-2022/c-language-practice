/*
 * Purpose: Converts binary strings to their decimal equivalents
 * Topic: Binary conversion, String processing, Bit manipulation
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Calculate 2^exp using bit shifts
int power_of_2(int exp) {
    if (exp < 0) {
        return 0;
    }
    return 1LL << exp;
}

void clear_input_buffer() {
    while (getchar() != '\n' && !feof(stdin));
}

int is_valid_binary(const char *binary_string) {
    int string_length = strlen(binary_string);
    
    for (int i = 0; i < string_length; i++) {
        if (binary_string[i] != '0' && binary_string[i] != '1') {
            return -1;
        }
    }

    return 0;
}

int binary_to_decimal(const char *binary_string) {
    int string_length = strlen(binary_string);
    int power = string_length - 1;
    int decimal_value = 0;
    
    for (int i = 0; i < string_length; i++) {
        int bit = binary_string[i] - '0';
        decimal_value += bit * power_of_2(power);
        power--;
    }
    
    return decimal_value;
}

int get_binary_input(char *binary_string) {
    int n;
    printf("Enter the length of the binary string (or any non-integer to exit): ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "\nInvalid input for length. Exiting.\n");
        clear_input_buffer();
        return -1;
    }
    
    printf("Enter the binary string: ");
    if (scanf("%64s", binary_string) != 1) {
        fprintf(stderr, "Invalid input for binary string. Exiting.\n");
        clear_input_buffer();
        return -1;
    }
    
    return 0;
}

int main(void) {
    char binary_string[65];
    
    while (1) {
        if (get_binary_input(binary_string) == -1) {
            break;
        }
        
        if (is_valid_binary(binary_string) == -1) {
            fprintf(stderr, "Invalid binary string detected. Contains non-binary characters.\n\n");
            clear_input_buffer();
            continue;
        }
        
        int decimal_value = binary_to_decimal(binary_string);
        printf("Binary: %s -> Decimal: %d\n\n", binary_string, decimal_value);
    }
    
    return 0;
}
