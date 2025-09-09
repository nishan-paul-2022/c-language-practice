// Purpose: Reads a sequence of double values until a sentinel value (0.007) is entered,
// then calculates and prints the average, maximum, and minimum of the entered numbers.
// Topic: Loops, Input Handling, Floating-Point Numbers, Max/Min/Average Calculation

#include <stdio.h>
#include <math.h> // For potential use of fabs for tolerance comparison, though not strictly needed for sentinel

int main() {
    double current_value;       // The current number read from input
    double maximum_value = 0.0; // Stores the maximum value encountered
    double minimum_value = 0.0; // Stores the minimum value encountered
    double sum_of_values = 0.0; // Stores the sum of all valid numbers entered
    int count = 0;              // Counts the number of valid entries

    printf("Enter a sequence of double values.\n");
    printf("Enter 0.007 to finish and see the results.\n");
    printf("----------------------------------------\n");

    // Loop to read values until the sentinel value is entered
    while (1) {
        printf("Enter value: ");
        // Read the input value and check if scanf was successful
        if (scanf("%lf", &current_value) != 1) {
            fprintf(stderr, "Error: Invalid input. Please enter a valid double value.\n");
            // Clear the input buffer to prevent infinite loops on bad input
            while (getchar() != '\n'); 
            continue; // Skip to the next iteration
        }

        // Check for the sentinel value (0.007) to terminate the loop.
        // Direct comparison for floating-point numbers can be tricky due to precision.
        // For a specific sentinel like 0.007, direct comparison might be intended,
        // but using a small tolerance is generally safer for floating-point comparisons.
        // For this example, we'll use direct comparison as it's likely the intent.
        if (current_value == 0.007) {
            break; // Exit the loop if the sentinel value is entered
        }

        // Increment the count of valid numbers entered
        count++;

        // Initialize max and min with the first valid input
        if (count == 1) {
            maximum_value = current_value;
            minimum_value = current_value;
        } else {
            // Update maximum value if current_value is greater
            if (current_value > maximum_value) {
                maximum_value = current_value;
            }
            // Update minimum value if current_value is smaller
            if (current_value < minimum_value) {
                minimum_value = current_value;
            }
        }

        // Add the current value to the sum
        sum_of_values += current_value;
    }

    printf("\n----------------------------------------\n");

    // Calculate and print the results if at least one valid number was entered
    if (count > 0) {
        double average = sum_of_values / count;
        printf("Average: %.6f\n", average); // Print average with 6 decimal places
        printf("Maximum: %.6f\n", maximum_value); // Print max with 6 decimal places
        printf("Minimum: %.6f\n", minimum_value); // Print min with 6 decimal places
    } else {
        printf("No valid numbers were entered before the sentinel value.\n");
    }

    return 0;
}
