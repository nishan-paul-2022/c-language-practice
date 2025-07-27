/*
 * Purpose: Reads an integer and repeatedly extracts its last digits by taking modulo with increasing powers of 10.
 * Topic: Loops, Arithmetic Operators (Modulo), Basic I/O
 */

#include <stdio.h> // Required for printf and scanf
#include <math.h>  // Required for pow (though integer multiplication is preferred for powers of 10)

int main() {
    int input_number; // The integer number input by the user
    int extracted_digits; // Variable to store the extracted digits
    long long int power_of_10; // Represents 10, 100, 1000, etc. (using long long to prevent overflow)

    // Loop to continuously read integers until scanf fails (e.g., EOF or invalid input)
    printf("Enter integers one by one (e.g., 12345). Press Ctrl+D (Unix/Linux) or Ctrl+Z (Windows) to stop.\n");
    while (scanf("%d", &input_number) == 1) { // Check if 1 item was successfully read
        printf("Processing number: %d\n", input_number);

        // Loop to extract digits using modulo with increasing powers of 10
        // Start with 10, then 100, 1000, etc.
        for (power_of_10 = 10; power_of_10 <= input_number * 10; power_of_10 *= 10) {
            extracted_digits = input_number % power_of_10;
            printf("  Digits (modulo %lld): %d\n", power_of_10, extracted_digits);
        }
        printf("  Original number: %d\n\n", input_number);
    }

    printf("Input stopped or invalid input received.\n");

    return 0; // Indicate successful execution
}
