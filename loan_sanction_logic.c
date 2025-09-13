/*
 * Purpose: Implements specific logic for loan sanctioning based on input values.
 * Topic: Input Processing, Conditional Logic, Financial Calculations (simplified/custom)
 */

#include <stdio.h>
#include <stdlib.h>

// Function to clear input buffer
void clear_input_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Function to validate and get initial inputs
int get_initial_inputs(double *input1, double *input2) {
    printf("Enter two numbers (e.g., 10000 20000): ");
    fflush(stdout);
    
    if (scanf("%lf %lf", input1, input2) != 2) {
        fprintf(stderr, "Error: Invalid input for the first two numbers.\n");
        clear_input_buffer();
        return -1;
    }
    
    return 0;
}

// Function to validate a single double input
int get_single_input(const char* prompt, double *value) {
    printf("%s", prompt);
    fflush(stdout);
    
    if (scanf("%lf", value) != 1) {
        fprintf(stderr, "Error: Invalid input.\n");
        clear_input_buffer();
        return -1;
    }
    
    return 0;
}

// Function to check eligibility condition
int check_eligibility_condition(double input1, double input2) {
    return (input1 == 0.0 && input2 < 50000.0) || (input2 == 0.0 && input1 < 50000.0);
}

// Function to check if third input exceeds limit
int is_third_input_exceeding_limit(double input3) {
    return input3 >= 50000.0;
}

// Function to calculate sanctioned amount
double calculate_sanctioned_amount(double input1, double input2, double input3) {
    if ((input1 + input2 + input3) > 50000.0) {
        double sanctioned_amount = 50000.0 - input1 - input2;
        return (sanctioned_amount < 0) ? 0 : sanctioned_amount;
    } else {
        return input3;
    }
}

// Function to display loan result
void display_loan_result(const char* message, double amount) {
    if (amount >= 0) {
        printf("%s %.2lf\n", message, amount);
    } else {
        printf("%s\n", message);
    }
}

// Function to process loan application
int process_loan_application() {
    double input1, input2, input3;
    
    // Get initial inputs
    if (get_initial_inputs(&input1, &input2) == -1) {
        return -1;
    }
    
    // Check eligibility
    if (check_eligibility_condition(input1, input2) == 0) {
        display_loan_result("No Loan", -1);
        return -1;
    }
    
    // Get third input
    if (get_single_input("Enter a third number: ", &input3) == -1) {
        return -1;
    }
    
    // Check if third input exceeds limit
    if (is_third_input_exceeding_limit(input3)) {
        display_loan_result("No Loan", -1);
        return -1;
    }
    
    // Calculate and display sanctioned amount
    if (input3 < 50000.0) {
        double sanctioned_amount = calculate_sanctioned_amount(input1, input2, input3);
        display_loan_result("Sanctioned Loan", sanctioned_amount);
    }
    
    return 0;
}

int main(void) {
    process_loan_application();
    return 0;
}