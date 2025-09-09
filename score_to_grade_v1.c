/*
 * Purpose: Converts a numerical score into a letter grade using if-else if statements.
 * Topic: Input Processing, Conditional Logic (if-else if), Grading System
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    double score;

    printf("Enter scores (e.g., 85.5) or press Ctrl+D (Unix/Linux) or Ctrl+Z (Windows) to exit.\n");

    // Read scores until EOF is encountered or an input error occurs
    while (scanf("%lf", &score) == 1) {
        // Determine the letter grade based on the score
        if (score >= 80.0) {
            printf("Score %.2f -> Grade: A+\n", score);
        } else if (score >= 70.0 && score < 80.0) {
            printf("Score %.2f -> Grade: A\n", score);
        } else if (score >= 60.0 && score < 70.0) {
            printf("Score %.2f -> Grade: A-\n", score);
        } else if (score >= 50.0 && score < 60.0) {
            printf("Score %.2f -> Grade: B\n", score);
        } else if (score >= 40.0 && score < 50.0) {
            printf("Score %.2f -> Grade: C\n", score);
        } else if (score >= 0.0 && score < 40.0) { // Explicitly handle non-negative scores below 40
            printf("Score %.2f -> Grade: F\n", score);
        } else { // Handles negative scores
            printf("Score %.2f -> ERROR: Invalid score (negative value).\n", score);
        }
    }

    // Check if the loop terminated due to an error other than reaching EOF
    if (ferror(stdin)) {
        perror("Error reading input");
        return EXIT_FAILURE;
    }

    printf("Exiting program.\n");
    return 0;
}
