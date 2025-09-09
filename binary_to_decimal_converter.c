#include <stdio.h>
#include <string.h> // For strlen
#include <stdlib.h> // For exit, strtol (alternative for conversion)

// Function to calculate 2 raised to the power of exp efficiently using bit shifts.
// This avoids using the math.h pow() function which can be slower and less precise for integers.
long long int power_of_2(int exp) {
    if (exp < 0)
        return 0;      // Handle negative exponents if necessary, though not expected here.
    return 1LL << exp; // Left shift 1 by exp bits (equivalent to 2^exp)
}

int main() {
    int n;                  // Expected length of the binary string (though not strictly enforced by scanf %s)
    char binary_string[65]; // Buffer for the binary string. Max 64 bits + null terminator.
    int decimal_value;      // Stores the resulting decimal value
    int power_of_2_val;     // Stores the current power of 2

    // Loop indefinitely to continuously convert binary strings to decimal
    while (1) {
        // Read the expected length of the binary string.
        // Note: The original code used 'n' to declare a VLA and then read into it.
        // This is unsafe. We'll use a fixed-size buffer and read into it.
        if (scanf("%d", &n) != 1) {
            fprintf(stderr, "Invalid input for length. Exiting.\n");
            // Clear the input buffer in case of non-integer input
            while (getchar() != '\n' && !feof(stdin))
                ;
            break; // Exit loop on invalid length input
        }

        // Read the binary string.
        // "%64s" reads up to 64 characters to prevent buffer overflow, ensuring null termination.
        // It stops at whitespace.
        if (scanf("%64s", binary_string) != 1) {
            fprintf(stderr, "Invalid input for binary string. Exiting.\n");
            // Clear the input buffer in case of invalid string input
            while (getchar() != '\n' && !feof(stdin))
                ;
            break; // Exit loop on invalid binary string input
        }

        // Initialize decimal value and the power of 2 for the most significant bit
        decimal_value = 0;
        // The most significant bit is at index 0, and its power of 2 is n-1 (or strlen-1 if n is not accurate)
        // We'll use strlen for robustness as 'n' might not match the actual input length.
        int string_length = strlen(binary_string);
        power_of_2_val = string_length - 1;

        // Iterate through the binary string from left to right (most significant bit to least significant bit)
        for (int i = 0; i < string_length; i++) {
            // Convert the character '0' or '1' to its integer value
            int bit = binary_string[i] - '0';

            // Check if the character is indeed a binary digit (0 or 1)
            if (bit != 0 && bit != 1) {
                fprintf(stderr, "Invalid binary string detected. Contains non-binary characters. Exiting.\n");
                // Clear the rest of the line to prevent issues on next iteration
                while (getchar() != '\n' && !feof(stdin))
                    ;
                // Set decimal_value to -1 to indicate an error, or break/exit
                decimal_value = -1;
                break;
            }

            // Add the value of the current bit (bit * 2^power_of_2_val) to the decimal sum
            decimal_value += bit * power_of_2(power_of_2_val);

            // Decrement the power of 2 for the next bit
            power_of_2_val--;
        }

        // Print the resulting decimal value.
        // The original code printed two newlines, so we'll replicate that.
        if (decimal_value != -1) { // Only print if no error occurred
            printf("%d\n\n", decimal_value);
        }
        else {
            // If an error occurred (e.g., invalid binary string), we might want to print an error message
            // or just exit without printing a result. The loop will break anyway.
        }
    }

    return 0;
}
