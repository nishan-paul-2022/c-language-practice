/*
 * Purpose: Converts binary strings to their decimal equivalents
 * Topic: Binary conversion, String processing, Bit manipulation
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Calculate 2^exp using bit shifts for efficiency
long long int power_of_2(int exp) {
    if (exp < 0)
        return 0; // Handle negative exponents
    return 1LL << exp; // Left shift 1 by exp bits (equivalent to 2^exp)
}

int main() {
    int n;
    char binary_string[65]; // Max 64 bits + null terminator
    int decimal_value;
    int power_of_2_val;

    while (1) {
        printf("Enter the length of the binary string (or any non-integer to exit): ");
        if (scanf("%d", &n) != 1) {
            fprintf(stderr, "\nInvalid input for length. Exiting.\n");
            // Clear the input buffer in case of non-integer input
            while (getchar() != '\n' && !feof(stdin))
                ;
            break;
        }

        printf("Enter the binary string: ");
        if (scanf("%64s", binary_string) != 1) {
            fprintf(stderr, "Invalid input for binary string. Exiting.\n");
            // Clear the input buffer in case of invalid string input
            while (getchar() != '\n' && !feof(stdin))
                ;
            break;
        }

        decimal_value = 0;
        int string_length = strlen(binary_string);
        power_of_2_val = string_length - 1;

        for (int i = 0; i < string_length; i++) {
            // Convert the character '0' or '1' to its integer value
            int bit = binary_string[i] - '0';

            // Check if the character is indeed a binary digit (0 or 1)
            if (bit != 0 && bit != 1) {
                fprintf(stderr, "Invalid binary string detected. Contains non-binary characters. Exiting.\n");
                // Clear the rest of the line to prevent issues on next iteration
                while (getchar() != '\n' && !feof(stdin))
                    ;
                decimal_value = -1;
                break;
            }

            decimal_value += bit * power_of_2(power_of_2_val);

            power_of_2_val--;
        }

        if (decimal_value != -1) {
            printf("Binary: %s -> Decimal: %d\n\n", binary_string, decimal_value);
        }
        else {
        }
    }

    return 0;
}
