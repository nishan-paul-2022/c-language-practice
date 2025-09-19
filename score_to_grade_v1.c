/*
 * Purpose: Converts a numerical score into a letter grade using if-else if statements.
 * Topic: Input Processing, Conditional Logic (if-else if), Grading System
 */

#include <stdio.h>

int main(void) {
    double score;

    printf("Enter scores (e.g., 85.5) or press Ctrl+D (Unix/Linux) or Ctrl+Z (Windows) to exit.\n");

    while (scanf("%lf", &score) == 1) {
        if (score >= 80.0) {
            printf("Score %.2f | Grade: A+\n", score);
        } else if (score >= 70.0) {
            printf("Score %.2f | Grade: A\n", score);
        } else if (score >= 60.0) {
            printf("Score %.2f | Grade: A-\n", score);
        } else if (score >= 50.0) {
            printf("Score %.2f | Grade: B\n", score);
        } else if (score >= 40.0) {
            printf("Score %.2f | Grade: C\n", score);
        } else if (score >= 0.0) {
            printf("Score %.2f | Grade: F\n", score);
        } else {
            printf("Score %.2f | Invalid score\n", score);
        }
    }

    if (ferror(stdin)) {
        perror("Error reading input");
        return 0;
    }

    printf("Exiting program.\n");
    
    return 0;
}
