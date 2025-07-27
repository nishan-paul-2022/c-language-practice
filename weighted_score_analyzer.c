// Purpose: Calculates weighted scores from three input sets and then provides a frequency distribution of these scores.
// Topic: Arrays, Weighted Averages, Loops, Conditional Logic, Frequency Distribution

#include <stdio.h>
#include <stdlib.h> // For EXIT_FAILURE

int main() {
    int num_elements;           // Number of data points for each score set.
    int index;                  // Loop index for iterating through arrays.
    float first_set[100];       // Array to store the first set of scores (assuming max 100 elements for safety).
    float second_set[100];      // Array to store the second set of scores.
    float third_set[100];       // Array to store the third set of scores.
    int calculated_scores[100]; // Array to store the final calculated integer scores.

    int range_start, range_end; // Variables for defining score ranges.
    int count;                  // Counter for elements within a specific range or score.
    int score_value;            // Loop variable for iterating through all possible scores (0-100).

    printf("Enter the number of score sets to process (max 100): ");
    // Read the number of elements.
    if (scanf("%d", &num_elements) != 1 || num_elements <= 0 || num_elements > 100) {
        printf("Invalid input. Please enter a positive integer up to 100.\n");
        return EXIT_FAILURE;
    }

    // Consume the newline character left by scanf.
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Read the first set of scores.
    printf("Enter %d scores for the first set (separated by spaces):\n", num_elements);
    for (index = 0; index < num_elements; index++) {
        if (scanf("%f", &first_set[index]) != 1) {
            printf("Invalid input for first set at index %d.\n", index);
            return EXIT_FAILURE;
        }
        // Consume the newline character after each float input.
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // Read the second set of scores.
    printf("Enter %d scores for the second set (separated by spaces):\n", num_elements);
    for (index = 0; index < num_elements; index++) {
        if (scanf("%f", &second_set[index]) != 1) {
            printf("Invalid input for second set at index %d.\n", index);
            return EXIT_FAILURE;
        }
        // Consume the newline character after each float input.
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // Read the third set of scores.
    printf("Enter %d scores for the third set (separated by spaces):\n", num_elements);
    for (index = 0; index < num_elements; index++) {
        if (scanf("%f", &third_set[index]) != 1) {
            printf("Invalid input for third set at index %d.\n", index);
            return EXIT_FAILURE;
        }
        // Consume the newline character after each float input.
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // Calculate the weighted scores.
    printf("\nCalculated Scores:\n");
    for (index = 0; index < num_elements; index++) {
        // Calculate score with weights: 25% first, 25% second, 50% third.
        // Implicit conversion to int truncates decimal parts.
        calculated_scores[index] = (int)(first_set[index] * 0.25 + second_set[index] * 0.25 + third_set[index] * 0.50);
        printf("%d ", calculated_scores[index]);
    }
    printf("\n");

    // Categorize scores into ranges and count occurrences.
    printf("\nScore Distribution by Ranges:\n");
    // Iterate through score ranges (0-9, 10-19, ..., 90-99).
    // The loop condition ensures we cover ranges up to 90-99.
    for (range_start = 0, range_end = 10; range_start <= 90; range_start += 10, range_end += 10) {
        count = 0; // Reset count for each range.
        // Count how many calculated scores fall within the current range.
        for (index = 0; index < num_elements; index++) {
            if (calculated_scores[index] >= range_start && calculated_scores[index] < range_end) {
                count++;
            }
        }
        // Print the range and the count. Note: range_end-1 is used for display to show inclusive upper bound.
        printf("%d - %d : %d\n", range_start, range_end - 1, count);
    }

    // Frequency distribution of individual scores (0-100).
    printf("\nFrequency of Each Score (0-100):\n");
    // Iterate through each possible score from 0 to 100.
    for (score_value = 0; score_value <= 100; score_value++) {
        count = 0; // Reset count for each score value.
        // Count how many times the current score_value appears in the calculated scores.
        for (index = 0; index < num_elements; index++) {
            if (calculated_scores[index] == score_value) {
                count++;
            }
        }
        // Print the score value and its frequency.
        // %3d ensures the score value is right-aligned in a field of 3 characters.
        printf("%3d : %d\n", score_value, count);
    }

    return 0; // Indicate successful execution.
}
