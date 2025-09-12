/*
 * Purpose: Converts a decimal integer to its binary representation.
 * Topic: Loops, Arithmetic Operations, Number Systems, Arrays
 */

#include <stdio.h>

int convert_to_binary(int decimal, int binary_digits[]) {
    if (decimal == 0) {
        binary_digits[0] = 0;
        return 1;
    }

    int i = 0;
    while (decimal > 0) {
        binary_digits[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
    
    return i;
}

void print_binary(int binary_digits[], int length) {
    printf("Binary: ");
    for (int j = length - 1; j >= 0; j--) {
        printf("%d", binary_digits[j]);
    }
    printf("\n\n");
}

int get_decimal_input() {
    int decimal_number;
    printf("Enter a non-negative decimal integer (or Ctrl+D to exit): ");
    
    if (scanf("%d", &decimal_number) != 1) {
        return -1;
    }
    
    return decimal_number;
}

void process_decimal_to_binary() {
    int decimal_number;
    int binary_digits[32];

    while ((decimal_number = get_decimal_input()) != -1) {
        if (decimal_number < 0) {
            printf("Please enter a non-negative integer.\n");
            continue;
        }

        int binary_length = convert_to_binary(decimal_number, binary_digits);
        print_binary(binary_digits, binary_length);
    }

    printf("\nExiting program.\n");
}

int main(void) {
    process_decimal_to_binary();
    return 0;
}
