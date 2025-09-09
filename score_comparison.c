/*
 * Purpose: Compares two sets of scores (or values) based on specific sum conditions.
 * Topic: Basic Input/Output, Loops, Conditional Logic
 */

#include <stdio.h>

int main() {
    int num_test_cases; // Number of test cases
    int i;

    // Read the number of test cases
    scanf("%d", &num_test_cases);

    // Process each test case
    for (i = 0; i < num_test_cases; i++) {
        int team1_score_part1, team1_score_part2, team1_score_part3, team1_score_part4;
        int team2_score_part1, team2_score_part2, team2_score_part3, team2_score_part4;

        // Read scores for Team 1 (or first entity)
        scanf("%d %d %d %d", &team1_score_part1, &team1_score_part2, &team1_score_part3, &team1_score_part4);
        // Read scores for Team 2 (or second entity)
        scanf("%d %d %d %d", &team2_score_part1, &team2_score_part2, &team2_score_part3, &team2_score_part4);

        // Check the combined condition
        // Assuming (part1 + part2) represents one aspect of performance
        // and (part3 + part4) represents another.
        // The condition checks if the first aspect is greater than the second for both teams.
        if ((team1_score_part1 + team1_score_part2 > team1_score_part3 + team1_score_part4) &&
            (team2_score_part1 + team2_score_part2 > team2_score_part3 + team2_score_part4)) {
            printf("Banglawash\n"); // Output for a specific winning condition
        } else {
            printf("Miss\n"); // Output for other conditions
        }
    }

    return 0;
}
