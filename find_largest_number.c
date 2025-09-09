// Purpose: Finds the largest among three double-precision floating-point numbers.
// Topic: Input Processing, Conditional Statements, Finding Maximum Value
#include <stdio.h>
#include <stdlib.h> // For EXIT_SUCCESS, EXIT_FAILURE

int main() {
    double num1, num2, num3;
    double largest;

    printf("Enter three numbers separated by commas (e.g., '10.5, 20.2, 5.8'):\n");

    // Read three numbers from standard input, expecting the format "num1, num2, num3"
    if (scanf("%lf, %lf, %lf", &num1, &num2, &num3) == 3) {

        // Find the largest number using a series of comparisons
        largest = num1; // Assume num1 is the largest initially

        if (num2 > largest) {
            largest = num2; // If num2 is larger, update largest
        }
        if (num3 > largest) {
            largest = num3; // If num3 is larger, update largest
        }

        // Print the largest number
        printf("The largest number is: %.2lf\n", largest);

        return 0;
    } else {
        // Handle cases where the input format is incorrect or EOF is reached prematurely
        fprintf(stderr, "Error: Invalid input format. Please use 'number, number, number'.\n");
        // Clear the input buffer in case of partial reads or invalid characters
        while (getchar() != '\n');
        return EXIT_FAILURE; // Indicate failure
    }
}
