// Purpose: Demonstrates a basic function that takes an integer argument, performs a calculation, and returns the result.
// Topic: Functions, Parameters, Return Values, Basic Arithmetic

#include <stdio.h>
#include <stdlib.h> // For exit()

// Function to multiply an integer by 10.
// Takes an integer as input and returns the result.
int multiply_by_ten(int input_value) {
    return input_value * 10;
}

int main() {
    int input_for_function = 4;
    int function_result;

    // Call the function with a specific value
    function_result = multiply_by_ten(input_for_function);

    // Print the result returned by the function
    printf("The result of multiplying %d by 10 is: %d\n", input_for_function, function_result);

    return 0; // Indicate successful execution
}
