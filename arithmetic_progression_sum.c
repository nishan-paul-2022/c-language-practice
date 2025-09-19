/*
 * Purpose: Calculates the sum of the first 'n' terms of an arithmetic progression.
 *          The progression starts at 2 and has a common difference of 4.
 * Topic: Arithmetic Progression, Loops, Summation, Input/Output
 */

#include <stdio.h>

int main(void) {
    int num_terms;
    long int current_term = 2; 
    long int total_sum = 0; 

    
    printf("Enter the number of terms for the arithmetic progression (starting with 2, difference of 4): ");
    if (scanf("%d", &num_terms) != 1) {
        printf("Invalid input. Please enter an integer for the number of terms.\n");
        return 0;
    }

    
    if (num_terms < 0) {
        printf("Number of terms cannot be negative.\n");
        return 0;
    }

    
    for (int i = 0; i < num_terms; i++) {
        total_sum += current_term; 
        current_term += 4; 
    }

    printf("The sum of the first %d terms is %ld\n", num_terms, total_sum);

    return 0;
}
