// Purpose: Reads a number 'x', then reads 'x' rows of 'x' double values each,
//          and prints the sum of values for each row.
// Topic: Nested Loops, Input/Output, Summation, Data Entry

#include <stdio.h>

int main() {
    int num_rows;
    int row_index, col_index;
    double row_sum = 0.0; // Initialize sum for the current row
    double value;         // Variable to store each input value

    printf("Enter the number of rows (and columns per row): ");
    // Read the number of rows and validate input
    if (scanf("%d", &num_rows) != 1) {
        printf("Error: Invalid input. Please enter an integer for the number of rows.\n");
        return 1; // Indicate an error
    }

    printf("\nEnter %d double values for each of the %d rows:\n", num_rows, num_rows);

    // Outer loop iterates through each row
    for (row_index = 1; row_index <= num_rows; row_index++) {
        row_sum = 0.0; // Reset sum for the new row

        printf("Enter %d values for row %d: ", num_rows, row_index);

        // Inner loop reads values for the current row
        for (col_index = 1; col_index <= num_rows; col_index++) {
            // Read each double value and validate input
            if (scanf("%lf", &value) != 1) {
                printf("\nError: Invalid input for value %d in row %d. Please enter a double.\n", col_index, row_index);
                return 1; // Indicate an error
            }
            row_sum += value; // Add the value to the current row's sum
        }

        // Print the sum of the current row
        printf("Sum of row %d: %.2lf\n", row_index, row_sum);
    }

    return 0;
}
