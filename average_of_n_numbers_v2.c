/*
 * Purpose: Reads a sequence of double values until a non-numeric value is entered,
 *          then calculates and prints the average of the entered numbers.
 * Topic: Loops, Input Handling, Floating-Point Numbers, Average Calculation
*/

#include <stdio.h>

int main(void) {
    double current_value;
    double sum_of_values = 0.0;
    int count = 0;

    printf("Enter a sequence of double values.\n");
    printf("Enter a non-numeric value to finish and see the average.\n");
    while (1) {
        printf("Enter value: ");
        if (scanf("%lf", &current_value) != 1) {
            while (getchar() != '\n'); // Clear input buffer
            break;
        }
        count++;
        sum_of_values += current_value;
    }

    if (count > 0) {
        double average = sum_of_values / count;
        printf("The average of the entered numbers is: %.2f\n", average);
    }

    return 0;
}
