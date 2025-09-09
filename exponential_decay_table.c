#include <stdio.h>
#include <math.h>

int main() {
    int input_limit;        // User-defined limit for the outer loop.
    int outer_loop_counter; // Counter for the outer loop (controls repetitions).
    float current_k;        // The value for which exp(-k) is calculated.
    int inner_loop_counter; // Counter for the inner loop (prints 10 values per outer iteration).
    float k_start_value;    // Stores the starting value of k for each outer loop iteration.

    // Loop indefinitely to allow multiple runs without restarting the program.
    // A mechanism to break out of this loop would be needed for a practical application.
    while (1) {
        // Prompt the user to enter a limit for the outer loop.
        // This determines how many sets of 10 exp(-k) values will be printed.
        scanf("%d", &input_limit);

        // Initialize k_start_value to 0.0. This variable will be incremented
        // in the outer loop to provide different starting points for k.
        k_start_value = 0.0f; 

        // Outer loop: iterates from 0 up to the user-provided limit 'input_limit'.
        // This loop controls how many blocks of 10 exp(-k) values are printed.
        for (outer_loop_counter = 0; outer_loop_counter <= input_limit; outer_loop_counter++) {
            
            // Reset current_k to the starting value for this outer loop iteration.
            current_k = k_start_value;
            
            // Inner loop: prints 10 values of exp(-k) for each outer loop iteration.
            // k increments by 0.1 in each step of this inner loop.
            for (inner_loop_counter = 0; inner_loop_counter < 10; inner_loop_counter++) {
                // Calculate exp(-k) and print it, formatted to 5 decimal places.
                printf("%1.5f ", exp(-current_k));
                
                // Increment k by 0.1 for the next iteration.
                current_k += 0.1f;
            }
            // Print a newline after each block of 10 values.
            printf("\n");
            
            // Increment the starting point for k for the next outer loop iteration.
            k_start_value += 1.0f;
        }
        
        // Print two newlines after all blocks of values have been printed for a given input_limit.
        printf("\n\n");
        
        // The original code had an infinite loop. To make it practical for this context,
        // we'll break after one execution. Remove this break if an infinite loop is desired.
        break; 
    }

    // The original code had getch() here, which is non-standard.
    // Removed for compatibility.

    return 0;
}
