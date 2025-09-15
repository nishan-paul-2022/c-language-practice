/*
 * Purpose: Demonstrates the difference between local and global variables in C.
 * Topic: Scope of Variables
 */

#include <stdio.h>

int global_var = 1; // Global variable: accessible anywhere in the program

// Function to modify global and local variables
void modify_variables(int local_var_param) {
    local_var_param = local_var_param * 2; // Modify local copy
    global_var = global_var + 10; // Modify global variable
    printf("Inside function: global_var = %d, local_var_param = %d\n", global_var, local_var_param);
}

int main(void) {
    int local_var = 5; // Local variable for main

    global_var = 10; // Initialize global variable

    modify_variables(local_var); // Call function

    printf("In main after function call: global_var = %d, local_var = %d\n", global_var, local_var);

    return 0;
}
