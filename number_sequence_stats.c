/*
 * Purpose: Reads a sequence of double values until a sentinel value (0.007) is entered, then calculates and prints the average, maximum, and minimum of the entered numbers.
 * Topic: Loops, Input Handling, Floating-Point Numbers, Max/Min/Average Calculation
 */

#include <stdio.h>
#include <math.h>

void print_instructions() {
    printf("Enter a sequence of double values.\n");
    printf("Enter 0.007 to finish and see the results.\n");
    printf("----------------------------------------\n");
}

int read_double_value(double *value) {
    printf("Enter value: ");
    if (scanf("%lf", value) != 1) {
        fprintf(stderr, "Invalid input. Please enter a valid double value.\n");
        while (getchar() != '\n'); // Clear input buffer
        return -1;
    }
    return 0;
}

void update_statistics(double value, double *max_value, double *min_value, double *sum, int count) {
    if (count == 1) {
        *max_value = value;
        *min_value = value;
    } else {
        if (value > *max_value) {
            *max_value = value;
        }
        if (value < *min_value) {
            *min_value = value;
        }
    }
    *sum += value;
}

void print_results(int count, double sum, double max_value, double min_value) {
    printf("\n----------------------------------------\n");
    if (count > 0) {
        double average = sum / count;
        printf("Average: %.6f\n", average);
        printf("Maximum: %.6f\n", max_value);
        printf("Minimum: %.6f\n", min_value);
    } else {
        printf("No valid numbers were entered before the sentinel value.\n");
    }
}

int main(void) {
    double current_value;
    double maximum_value = 0.0;
    double minimum_value = 0.0;
    double sum_of_values = 0.0;
    int count = 0;

    print_instructions();

    while (1) {
        if (read_double_value(&current_value) == -1) {
            continue;
        }

        if (current_value == 0.007) {
            break;
        }

        count++;
        update_statistics(current_value, &maximum_value, &minimum_value, &sum_of_values, count);
    }

    print_results(count, sum_of_values, maximum_value, minimum_value);

    return 0;
}
