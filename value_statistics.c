/*
 * Purpose: Calculates statistics (sum, count, average, min, max, range) for a series of double values.
 * Topic: Input/Output, Basic Statistics, Loops
 */

#include <stdio.h>
#include <stdlib.h>

int read_values(double values[], int max_size) {
    printf("--- INPUT VALUES ---\n");

    double input;
    int count = 0;

    printf("Enter up to %d double values (Ctrl+D to finish input):\n", max_size);

    while (scanf("%lf", &input) != -1) {
        if (count < max_size) {
            values[count++] = input;
        } else {
            printf("Maximum input size reached (%d values).\n", max_size);
            break;
        }
    }

    return count;
}

void calculate_statistics(double values[], int count, double *sum, double *average, double *min, double *max, double *range) {
    *sum = 0.0;
    *min = values[0];
    *max = values[0];

    for (int i = 0; i < count; i++) {
        *sum += values[i];
        if (values[i] > *max) {
            *max = values[i];
        }
        if (values[i] < *min) {
            *min = values[i];
        }
    }

    *average = *sum / count;
    *range = *max - *min;
}

void display_statistics(double sum, int count, double average, double min, double max, double range) {
    printf("--- STATISTICS SUMMARY ---\n");

    printf("Total Sum of Values       : %.2lf\n", sum);
    printf("Number of Values Entered  : %d\n", count);
    printf("Average Value             : %.3lf\n", average);
    printf("Highest Value             : %.3lf\n", max);
    printf("Lowest Value              : %.3lf\n", min);
    printf("Range (Max - Min)         : %.3lf\n", range);
    printf("---------------------------\n");
}

int main(void) {
    double values[1000];
    int count = read_values(values, 1000);

    if (count > 0) {
        double sum, average, min, max, range;
        calculate_statistics(values, count, &sum, &average, &min, &max, &range);
        display_statistics(sum, count, average, min, max, range);
    } else {
        printf("No values were entered. Exiting program.\n");
    }

    return 0;
}
