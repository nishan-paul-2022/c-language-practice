/*
 * Purpose: Calculates statistics (sum, count, average, min, max, range) for a series of double values.
 * Topic: Input/Output, Basic Statistics, Loops
 */

#include <stdio.h>

// Function to read values until EOF (Ctrl+D) is encountered
int read_values(double values[], int max_size) {
    double input;
    int count = 0;
    printf("--- INPUT VALUES ---\n");
    printf("Enter up to %d double values (Ctrl+D to finish input):\n", max_size);

    while (scanf("%lf", &input) != -1) {
        if (count < max_size) {
            values[count++] = input;
        } else {
            printf("[WARNING] Maximum input size reached (%d values).\n", max_size);
            break;
        }
    }

    return count;
}

// Function to calculate sum, min, max, average, and range
void calculate_statistics(double values[], int count, double *sum, double *average, double *min, double *max, double *range) {
    *sum = 0.0;
    if (count <= 0) return;

    *min = values[0];
    *max = values[0];

    for (int i = 0; i < count; i++) {
        *sum += values[i];
        if (values[i] > *max) *max = values[i];
        if (values[i] < *min) *min = values[i];
    }

    *average = *sum / count;
    *range = *max - *min;
}

// Function to display the statistics with clear titles
void display_statistics(double sum, int count, double average, double min, double max, double range) {
    printf("--- STATISTICS SUMMARY ---\n");
    printf("Total Sum of Values       : %.3lf\n", sum);
    printf("Number of Values Entered  : %d\n", count);
    printf("Average Value             : %.3lf\n", average);
    printf("Highest Value             : %.3lf\n", max);
    printf("Lowest Value              : %.3lf\n", min);
    printf("Range (Max - Min)         : %.3lf\n", range);
    printf("---------------------------\n");
}

int main(void) {

    // Step 1: Read values from user
    double values[1000];
    int count = read_values(values, 1000);

    if (count > 0) {
        double sum, average, min, max, range;
        // Step 2: Calculate statistics
        calculate_statistics(values, count, &sum, &average, &min, &max, &range);
        // Step 3: Display results with accurate titles
        display_statistics(sum, count, average, min, max, range);
    } else {
        printf("[INFO] No values were entered. Exiting program.\n");
    }

    return 0;
}
