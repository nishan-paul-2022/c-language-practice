/*
 * Purpose: Calculates statistics (sum, count, average, min, max, range) for a series of double values.
 * Topic: Input/Output, Basic Statistics, Loops
 */

#include <stdio.h>

int main(void) {
    double value;
    double sum = 0.0;
    double highest_value = 0.0;
    double lowest_value = 0.0;
    int count = 0;

    printf("Enter values (enter 0.1 to terminate input):\n");

    // Loop to read values until the sentinel value 0.1 is entered
    while (scanf("%lf", &value) == 1) {
        if (value == 0.1) {
            break; // Terminate input if sentinel value is found
        }

        count++;

        if (count == 1) {
            highest_value = value;
            lowest_value = value;
        } else {
            if (value > highest_value) {
                highest_value = value;
            }
            if (value < lowest_value) {
                lowest_value = value;
            }
        }
        sum += value;
    }

    if (count > 0) {
        printf("TOTAL VALUE %.3lf\n", sum);
        printf("TOTAL COMPANY %d\n", count);
        printf("AVERAGE VALUE %.3lf\n", sum / count);
        printf("Highest value %.3lf, Lowest value %.3lf, Range %.3lf\n", highest_value, lowest_value, highest_value - lowest_value);
    } else {
        printf("No values were entered.\n");
    }

    return 0;
}