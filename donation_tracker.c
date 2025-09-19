/*
 * Purpose: Simulates a donation collection process, accumulating and reporting the total.
 * Topic: Basic Input/Output, Loops, Accumulation
 */

#include <stdio.h>

int get_donation_count() {
    int num_donations;
    printf("Enter number of donations: ");
    scanf("%d", &num_donations);
    return num_donations;
}

int get_donation_amount() {
    int donation_amount;
    printf("donate ");
    scanf("%d", &donation_amount);
    return donation_amount;
}

void report_total(int total) {
    printf("report %d\n", total);
}

void process_donations(int num_donations) {
    int total_donations = 0;
    
    for (int i = 0; i < num_donations; i++) {
        int donation_amount = get_donation_amount();
        total_donations += donation_amount;
        report_total(total_donations);
    }
}

int main(void) {
    int num_donations = get_donation_count();
    process_donations(num_donations);
    return 0;
}
