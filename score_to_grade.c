// Purpose: Converts a numerical score into a letter grade based on a predefined scale.
// Topic: Input Processing, Conditional Logic (Switch Statement), Grading System
#include <stdio.h>
#include <stdlib.h> // For EXIT_SUCCESS, EXIT_FAILURE

int main() {
    float score;
    int grade_level;

    printf("Enter scores (e.g., 85.5) or press Ctrl+D (Unix/Linux) or Ctrl+Z (Windows) to exit.\n");

    // Read scores until EOF is encountered or an input error occurs
    while (scanf("%f", &score) == 1) {
        // Calculate the grade level based on score / 10
        // This logic maps scores to integer ranges for the switch statement.
        // For example, a score of 95.5 results in grade_level = 9.
        grade_level = (int)(score / 10.0);

        // Determine the letter grade based on the grade_level
        switch (grade_level) {
            case 10: // Scores 100-109 (or potentially higher if score is very large)
            case 9:  // Scores 90-99
            case 8:  // Scores 80-89
                printf("Score %.2f -> Grade: A+\n", score);
                break;
            case 7:  // Scores 70-79
                printf("Score %.2f -> Grade: A\n", score);
                break;
            case 6:  // Scores 60-69
                printf("Score %.2f -> Grade: A-\n", score);
                break;
            case 5:  // Scores 50-59
                printf("Score %.2f -> Grade: B\n", score);
                break;
            case 4:  // Scores 40-49
                printf("Score %.2f -> Grade: C\n", score);
                break;
            case 3:  // Scores 30-39
            case 2:  // Scores 20-29
            case 1:  // Scores 10-19
            case 0:  // Scores 0-9
                printf("Score %.2f -> Grade: F\n", score);
                break;
            default: // Handles negative scores or scores that result in grade_level >= 11
                // Note: If score is 100.0, grade_level is 10. If score is 109.9, grade_level is 10.
                // If score is 110.0, grade_level is 11, which falls into default.
                printf("Score %.2f -> ERROR: Invalid score or grade level.\n", score);
                break;
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
