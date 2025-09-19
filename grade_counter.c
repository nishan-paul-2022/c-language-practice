/*
 * Purpose: Counts the number of scores falling into different grade categories.
 * Topic: Input Processing, Counting, Conditional Logic, Loop Refactoring
 */

#include <stdio.h>
#include <stdlib.h>

void categorize_score(double score, int *count_A_plus, int *count_A, int *count_A_minus, 
                      int *count_B, int *count_C, int *count_F) {
    if (score >= 80.0) {
        (*count_A_plus)++;
    } else if (score >= 70.0) {
        (*count_A)++;
    } else if (score >= 60.0) {
        (*count_A_minus)++;
    } else if (score >= 50.0) {
        (*count_B)++;
    } else if (score >= 40.0) {
        (*count_C)++;
    } else {
        (*count_F)++;
    }
}

int read_score(double *score) {
    printf("Enter score: ");
    if (scanf("%lf", score) != 1) {
        if (ferror(stdin)) {
            perror("Error reading input");
        } else {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
        }
        return -1;
    }
    return 0;
}

void display_summary(int count_A_plus, int count_A, int count_A_minus, 
                     int count_B, int count_C, int count_F) {
    printf("\n--- Grade Summary ---\n");
    printf("A+ (80-100): %d\n", count_A_plus);
    printf("A  (70-79):  %d\n", count_A);
    printf("A- (60-69):  %d\n", count_A_minus);
    printf("B  (50-59):  %d\n", count_B);
    printf("C  (40-49):  %d\n", count_C);
    printf("F  (0-39):   %d\n", count_F);
    printf("---------------------\n");
}

int main(void) {
    double score;
    int count_A_plus = 0;
    int count_A = 0;
    int count_A_minus = 0;
    int count_B = 0;
    int count_C = 0;
    int count_F = 0;

    printf("Enter scores between 0 and 100. Enter -1 to finish.\n");

    while (1) {
        if (read_score(&score) == -1) {
            continue;
        }

        if (score == -1.0) {
            break;
        }

        if (score >= 0.0 && score <= 100.0) {
            categorize_score(score, &count_A_plus, &count_A, &count_A_minus, &count_B, &count_C, &count_F);
        } else {
            printf("Score %.2f is out of the valid range (0-100).\n", score);
        }
    }

    display_summary(count_A_plus, count_A, count_A_minus, count_B, count_C, count_F);

    return 0;
}
