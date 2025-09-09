// Purpose: Converts a string of digits into its integer representation.
// Topic: String to Integer Conversion, Basic Input/Output

#include <stdio.h>
#include <string.h> // For strlen
#include <math.h>   // For pow

int main() {
    int numTestCases;
    char inputString[100]; // Increased buffer size for safety
    int strLength;
    int powerOf10Exponent;
    int decimalValue;
    int digitValue;
    int i, j;

    // Read the number of test cases
    if (scanf("%d", &numTestCases) != 1) {
        fprintf(stderr, "Error reading number of test cases.\n");
        return 0;
    }
    // Consume the newline character after reading the integer
    while (getchar() != '\n');

    // Process each test case
    for (i = 1; i <= numTestCases; i++) {
        // Read the input string safely
        if (fgets(inputString, sizeof(inputString), stdin) == NULL) {
            fprintf(stderr, "Error reading input string for test case %d.\n", i);
            continue; // Skip to the next test case
        }

        // Remove trailing newline character if present
        inputString[strcspn(inputString, "\n")] = 0;

        strLength = strlen(inputString);
        powerOf10Exponent = strLength - 1;
        decimalValue = 0;

        // Convert the string to an integer
        for (j = 0; j < strLength; j++) {
            // Ensure the character is a digit
            if (inputString[j] >= '0' && inputString[j] <= '9') {
                digitValue = inputString[j] - '0';
                // Calculate the place value and add to the decimal value
                // Note: Using pow can be computationally expensive and may introduce floating-point inaccuracies.
                // A more efficient approach would be to multiply by 10 in each iteration.
                decimalValue += digitValue * (int)pow(10, powerOf10Exponent);
                powerOf10Exponent--;
            } else {
                fprintf(stderr, "Warning: Non-digit character '%c' found in input string for test case %d. Skipping character.\n", inputString[j], i);
                // If non-digit characters should invalidate the input, handle that here.
                // For this example, we'll just skip the character and continue.
            }
        }
        printf("%d\n", decimalValue);
    }

    return 0;
}
