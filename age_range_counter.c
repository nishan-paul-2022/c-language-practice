/*
 * Purpose: Counts how many entered ages fall within a specific range (50-60).
 * Topic: Input/Output, Loops, Conditional Statements
 */

#include <stdio.h>

int main(void) {
    printf("Enter ages to count those between 50 and 60 (inclusive).\n");
    printf("Enter 0 to process the current batch and start a new one.\n");
    printf("Ctrl+D to exit the program.\n\n");

    
    while (1) {
        int count_in_range = 0; 

        printf("--- New Batch ---\n");
        int age;
        while (scanf("%d", &age) == 1) {
            if (age == 0) {
                break; 
            }

            if (age >= 50 && age <= 60) {
                count_in_range++;
            }
        }

        
        if (feof(stdin) || ferror(stdin)) {
            printf("\nExiting program.\n");
            break;
        }

        printf("Number of ages in range 50-60: %d\n\n", count_in_range);

        
        while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));
    }

    return 0;
}
