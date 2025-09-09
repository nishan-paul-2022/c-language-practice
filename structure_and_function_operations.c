// Purpose: Demonstrates passing structures to functions and returning structures from functions.
// Topic: Structures, Functions, Pass-by-Value, Return-by-Value

#include <stdio.h>
#include <string.h> // Included for completeness, though not strictly used in this example.

// Define a structure to hold an integer and a float
typedef struct {
    int integer_part;   // The integer component
    float float_part;   // The floating-point component
} NumericData;

// Function to add two NumericData structures.
// It takes two structures by value and returns a new structure containing the sum.
NumericData add_numeric_data(NumericData data1, NumericData data2) {
    NumericData result; // Structure to hold the sum

    // Add the integer parts
    result.integer_part = data1.integer_part + data2.integer_part;
    // Add the float parts
    result.float_part = data1.float_part + data2.float_part;

    return result; // Return the resulting structure
}

// Function to print the contents of a NumericData structure.
// It takes a pointer to the structure for efficiency.
void print_numeric_data(NumericData *data) {
    // Print the integer and float parts, formatting the float to two decimal places.
    printf("Result: Integer = %d, Float = %.2f\n", data->integer_part, data->float_part);
}

int main() {
    NumericData operand1, operand2, sum_result;

    // Initialize the first operand
    operand1.integer_part = 100;
    operand1.float_part = 3.14159f; // Using 'f' suffix for float literal

    // Assign operand1 to operand2 (creates a copy)
    operand2 = operand1;

    // Call the add function, passing operands by value, and store the returned structure
    sum_result = add_numeric_data(operand1, operand2);

    // Print the result using the print function
    print_numeric_data(&sum_result);

    return 0;
}
