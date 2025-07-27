// Purpose: Simulates a donation collection process, accumulating and reporting the total.
// Topic: Basic Input/Output, Loops, Accumulation

#include <stdio.h>

int main() {
    int num_donations; // Number of donation entries to process
    int donation_amount; // Amount for each individual donation
    int total_donations = 0; // Accumulator for the total sum of donations
    int i;

    // Read the total number of donation entries
    scanf("%d", &num_donations);

    // Loop through each donation entry
    for (i = 0; i < num_donations; i++) {
        printf("donate "); // Prompt for donation
        scanf("%d", &donation_amount); // Read the donation amount

        total_donations += donation_amount; // Add to the running total

        printf("report\n%d\n", total_donations); // Report the current total
    }

    return 0; // Indicate successful execution
}
