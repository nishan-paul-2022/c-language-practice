/*
 * Purpose: Implements specific logic for loan sanctioning based on input values.
 * Topic: Input Processing, Conditional Logic, Financial Calculations (simplified/custom)
 */

#include <stdio.h>
#include <stdlib.h>

void clear_input_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int get_initial_inputs(double *input1, double *input2) {
    printf("Enter two numbers (e.g., 10000 20000): ");
    fflush(stdout);
    
    if (scanf("%lf %lf", input1, input2) != 2) {
        fprintf(stderr, "Invalid input for the first two numbers.\n");
        clear_input_buffer();
        return -1;
    }
    
    return 0;
}

int get_single_input(const char* prompt, double *value) {
    printf("%s", prompt);
    fflush(stdout);
    
    if (scanf("%lf", value) != 1) {
        fprintf(stderr, "Invalid input.\n");
        clear_input_buffer();
        return -1;
    }
    
    return 0;
}

int check_eligibility_condition(double input1, double input2) {
    return (input1 == 0.0 && input2 < 50000.0) || (input2 == 0.0 && input1 < 50000.0);
}

int is_third_input_exceeding_limit(double input3) {
    return input3 >= 50000.0;
}

double calculate_sanctioned_amount(double input1, double input2, double input3) {
    if ((input1 + input2 + input3) > 50000.0) {
        double sanctioned_amount = 50000.0 - input1 - input2;
        return (sanctioned_amount < 0) ? 0 : sanctioned_amount;
    } else {
        return input3;
    }
}

void display_loan_result(const char* message, double amount) {
    if (amount >= 0) {
        printf("%s %.2lf\n", message, amount);
    } else {
        printf("%s\n", message);
    }
}

int process_loan_application() {
    double input1, input2, input3;
    
    if (get_initial_inputs(&input1, &input2) == -1) {
        return -1;
    }
    
    if (check_eligibility_condition(input1, input2) == 0) {
        display_loan_result("No Loan", -1);
        return -1;
    }
    
    if (get_single_input("Enter a third number: ", &input3) == -1) {
        return -1;
    }
    
    if (is_third_input_exceeding_limit(input3)) {
        display_loan_result("No Loan", -1);
        return -1;
    }
    
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