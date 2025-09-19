/*
 * Purpose: Calculates weighted scores from three input sets and provides a frequency distribution.
 * Topic: Arrays, Weighted Averages, Loops, Functions, Frequency Distribution
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100

void consume_newline() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void read_scores(float scores[], int n, const char *set_name) {
    printf("Enter %d scores for %s set:\n", n, set_name);

    for (int i = 0; i < n; i++) {
        if (scanf("%f", &scores[i]) != 1) {
            printf("Invalid input for %s set at index %d.\n", set_name, i);
            exit(0);
        }

        consume_newline();
    }
}

void calculate_weighted_scores(float first[], float second[], float third[], int weighted[], int n) {
    for (int i = 0; i < n; i++) {
        weighted[i] = (int)(first[i] * 0.25 + second[i] * 0.25 + third[i] * 0.50);
    }
}

void print_scores(int scores[], int n) {
    printf("\nCalculated Scores: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", scores[i]);
    }

    printf("\n");
}

void print_score_ranges(int scores[], int n) {
    printf("\nScore Distribution by Ranges:\n");

    for (int range_start = 0; range_start <= 90; range_start += 10) {
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (scores[i] >= range_start && scores[i] < range_start + 10) {
                count++;
            }
        }

        if (count) {
            printf("%2d - %2d : %d\n", range_start, range_start + 9, count);
        }
    }
}

void print_score_frequency(int scores[], int n) {
    printf("\nFrequency of Each Score (0-100):\n");

    for (int value = 0; value <= 100; value++) {
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (scores[i] == value) {
                count++;
            }
        }

        if (count) {
            printf("%d : %d\n", value, count);
        }
    }
}

int main(void) {
    int num_elements;
    float first_set[MAX_ELEMENTS], second_set[MAX_ELEMENTS], third_set[MAX_ELEMENTS];
    int weighted_scores[MAX_ELEMENTS];

    printf("Enter the number of score sets to process (max %d): ", MAX_ELEMENTS);

    if (scanf("%d", &num_elements) != 1 || num_elements <= 0 || num_elements > MAX_ELEMENTS) {
        printf("Invalid input. Enter a positive integer up to %d.\n", MAX_ELEMENTS);
        return 0;
    }

    consume_newline();

    read_scores(first_set, num_elements, "first");
    read_scores(second_set, num_elements, "second");
    read_scores(third_set, num_elements, "third");

    calculate_weighted_scores(first_set, second_set, third_set, weighted_scores, num_elements);
    
    print_scores(weighted_scores, num_elements);
    print_score_ranges(weighted_scores, num_elements);
    print_score_frequency(weighted_scores, num_elements);

    return 0;
}
