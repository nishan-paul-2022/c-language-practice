/*
 * Purpose: Converts a numerical score into a letter grade based on a predefined scale.
 * Topic: Input Processing, Conditional Logic (Switch Statement), Grading System
 */

#include <stdio.h>

int main(void) {
    float score;
    int grade_level;

    printf("Enter scores (e.g., 85.5) or press Ctrl+D (Unix/Linux) or Ctrl+Z (Windows) to exit.\n");

    // Read scores until EOF or input error
    while (scanf("%f", &score) == 1) {
        grade_level = (int)(score / 10.0);

        switch (grade_level) {
            case 10:
            case 9:
            case 8:
                printf("Score %.2f -> Grade: A+\n", score);
                break;
            case 7:
                printf("Score %.2f -> Grade: A\n", score);
                break;
            case 6:
                printf("Score %.2f -> Grade: A-\n", score);
                break;
            case 5:
                printf("Score %.2f -> Grade: B\n", score);
                break;
            case 4:
                printf("Score %.2f -> Grade: C\n", score);
                break;
            case 3:
            case 2:
            case 1:
            case 0:
                printf("Score %.2f -> Grade: F\n", score);
                break;
            default:
                printf("Score %.2f -> ERROR: Invalid score or grade level.\n", score);
                break;
        }
    }

    if (ferror(stdin)) {
        perror("Error reading input");
        return 0;
    }

    printf("Exiting program.\n");
    return 0;
}
