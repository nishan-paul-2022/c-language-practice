// Purpose: Demonstrates the difference between local and global variables in C.
// Topic: Scope of Variables

#include <stdio.h>

// Global variable: accessible from anywhere in the program.
int global_var = 1;

// Function to demonstrate modification of global and local variables.
void modify_variables(int local_var_param) {
    // Modify the local variable passed as a parameter.
    local_var_param = local_var_param * 2;
    // Modify the global variable.
    global_var = global_var + 10;
    // Print the values of global_var and the modified local_var_param.
    printf("Inside function: global_var = %d, local_var_param = %d\n", global_var, local_var_param);
}

int main() {
    // Local variable: accessible only within the main function.
    int local_var = 5;

    // Initialize the global variable.
    global_var = 10;

    // Call the function to modify variables.
    modify_variables(local_var);

    // Print the values of global_var and local_var after the function call.
    // Note that local_var in main remains unchanged because the function received a copy.
    printf("In main after function call: global_var = %d, local_var = %d\n", global_var, local_var);

    return 0;
}
