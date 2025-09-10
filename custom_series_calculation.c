/*
 * Purpose: Calculates a custom series based on user input using nested loops and mathematical operations.
 * Topic: Mathematical Series, Nested Loops, Floating-Point Arithmetic
 */

#include <stdio.h>
#include <math.h>

// Note: The original code included <conio.h> and used getch(), which are non-standard
// and typically used on DOS/Windows systems. These have been removed for broader compatibility.
// The calculation itself is a custom series and does not represent a standard mathematical series like e^x.

int main() {
    int input_x;            // User input value, used as the base for powers.
    int loop_counter_i;
    int loop_counter_j;
    float current_e_sum;    // Accumulates the sum of the series terms.
    float current_k_value;  // The value used in the pow(x, i) / y calculation.
    float y_update_value;   // Variable used in the update rule for 'y'.

    // Loop indefinitely to allow multiple runs without restarting the program.
    // A mechanism to break out of this loop would be needed for a practical application.
    while (1) {
        // Prompt the user to enter a value.
        printf("ENTER THE VALUE : ");
        
        // Read the integer input from the user.
        if (scanf("%d", &input_x) != 1) {
            fprintf(stderr, "Invalid input. Please enter an integer.\n");
            // Clear the input buffer in case of non-integer input
            while (getchar() != '\n' && !feof(stdin));
            break; // Exit loop on invalid input
        }

        // Initialize the sum and the starting value for 'y'.
        current_e_sum = 1.0f; // The series starts with 1.0.
        y_update_value = 1.0f; // Initial value for 'y' in the calculation.

        // Outer loop: iterates from i = 0 up to input_x.
        // This loop controls how many times the inner calculation block is performed.
        for (int outer_loop_counter = 0; outer_loop_counter <= input_x; outer_loop_counter++) {
            
            // Reset current_k_value to the value of y_update_value at the start of this outer iteration.
            current_k_value = y_update_value;
            
            // Inner loop: runs 10 times to calculate and print terms.
            // In each step, it calculates exp(-k) (or rather pow(x,i)/y) and updates k.
            // The original code used pow(x,i)/y, but the variable 'k' was used for the exponent in exp().
            // Let's stick to the original calculation: pow(x,i)/y.
            // The original code had 'k' being reset to 'l' (which is y_update_value here)
            // and then incremented by 0.1. This seems to be a misunderstanding of the original code's intent.
            // The original code was:
            // k = l; // k = y_update_value
            // for(j=1; j <=10; j++) { printf("%1.5lf ",exp(-k)); k = k + .1; }
            // This means it was printing exp(-k) for k = y_update_value, y_update_value+0.1, ..., y_update_value+0.9
            //
            // The code I'm processing now is:
            // e = e + pow(x,i)/y ;
            // y = y*y+1 ;
            // This is different. Let's follow this new logic.
            
            // Calculate the term: pow(input_x, outer_loop_counter) / y_update_value
            // Note: pow() returns a double.
            float term = pow((double)input_x, (double)outer_loop_counter) / y_update_value;
            
            // Add the calculated term to the sum.
            current_e_sum += term;

            // Update y_update_value for the next iteration of the outer loop.
            // The rule is y = y*y + 1.
            y_update_value = y_update_value * y_update_value + 1.0f;
        }
        
        // Print the final calculated sum for the given input_x.
        // The original code printed "%f\n", so we'll use that.
        printf("%f\n", current_e_sum);
        
        // The original code had an infinite loop and no way to break.
        // For demonstration, we'll break after one calculation.
        // If an infinite loop is desired, remove the 'break;' statement.
        break; 
    }

    // The original code had getch() here, which is non-standard.
    // Removed for compatibility.

    return 0;
}
