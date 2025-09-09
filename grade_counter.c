/*
 * Purpose: Counts the number of scores falling into different grade categories.
 * Topic: Input Processing, Counting, Conditional Logic, Loop Refactoring
 */
#include <stdio.h>
#include <stdlib.h> // For EXIT_SUCCESS, EXIT_FAILURE

int main() {
    double score;
    int count_A_plus = 0;
    int count_A = 0;
    int count_A_minus = 0;
    int count_B = 0;
    int count_C = 0;
    int count_F = 0;

    printf("Enter scores between 0 and 100. Enter -1 to finish.\n");

    // Loop to read scores until -1 is entered or an input error occurs
    while (1) {
        printf("Enter score: ");
        // Read the score and check if input was successful
        if (scanf("%lf", &score) != 1) {
            // If scanf fails (e.g., non-numeric input), clear the input buffer
            // and report an error.
            if (ferror(stdin)) {
                perror("Error reading input");
            } else {
                fprintf(stderr, "Invalid input. Please enter a number.\n");
                // Clear the invalid input from the buffer
                while (getchar() != '\n');
            }
            continue; // Ask for input again
        }

        // Check for the termination condition
        if (score == -1.0) {
            break; // Exit the loop
        }

        // Process the score if it's within the valid range [0, 100]
        if (score >= 0.0 && score <= 100.0) {
            if (score >= 80.0) {
                count_A_plus++;
            } else if (score >= 70.0) {
                count_A++;
            } else if (score >= 60.0) {
                count_A_minus++;
            } else if (score >= 50.0) {
                count_B++;
            } else if (score >= 40.0) {
                count_C++;
            } else { // score >= 0.0 && score < 40.0
                count_F++;
            }
        } else {
            // Handle scores outside the valid range [0, 100]
            printf("ERROR: Score %.2f is out of the valid range (0-100).\n", score);
        }
    }

    // Print the final counts for each grade category
    printf("\n--- Grade Summary ---\n");
    printf("A+ (80-100): %d\n", count_A_plus);
    printf("A  (70-79):  %d\n", count_A);
    printf("A- (60-69):  %d\n", count_A_minus);
    printf("B  (50-59):  %d\n", count_B);
    printf("C  (40-49):  %d\n", count_C);
    printf("F  (0-39):   %d\n", count_F);
    printf("---------------------\n");

    return 0;
}
