#include <stdio.h>
#include <math.h>

int main(void) {
    int input_limit;        // User-defined limit for the outer loop
    int outer_loop_counter; // Counter for the outer loop
    float current_k;        // The value for which exp(-k) is calculated
    int inner_loop_counter; // Counter for the inner loop
    float k_start_value;    // Starting value of k for each outer loop iteration

    // Loop indefinitely to allow multiple runs without restarting the program
    while (1) {
        // Prompt the user to enter a limit for the outer loop
        printf("Enter the limit for the outer loop: ");
        scanf("%d", &input_limit);

        // Initialize k_start_value to 0.0
        k_start_value = 0.0f;

        // Outer loop: iterates from 0 up to the user-provided limit 'input_limit'
        for (outer_loop_counter = 0; outer_loop_counter <= input_limit; outer_loop_counter++) {
            
            // Reset current_k to the starting value for this outer loop iteration
            current_k = k_start_value;
            
            // Inner loop: prints 10 values of exp(-k) for each outer loop iteration
            for (inner_loop_counter = 0; inner_loop_counter < 10; inner_loop_counter++) {
                // Calculate exp(-k) and print it, formatted to 5 decimal places
                printf("%1.5f ", exp(-current_k));
                
                // Increment k by 0.1 for the next iteration
                current_k += 0.1f;
            }
            // Print a newline after each block of 10 values
            printf("\n");
            
            // Increment the starting point for k for the next outer loop iteration
            k_start_value += 1.0f;
        }
        
        // Print two newlines after all blocks of values have been printed
        printf("\n\n");
        
        // Break after one execution for practical purposes
        break;
    }

    return 0;
}
