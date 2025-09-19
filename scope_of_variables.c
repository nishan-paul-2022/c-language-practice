/*
 * Purpose: Demonstrates the difference between local and global variables in C.
 * Topic: Scope of Variables
 */

#include <stdio.h>

int global = 1;

void initialize_global_var(int value) {
    global = value;
}

void modify_variables(int x) {
    x = x * 2;
    global = global + 10;
}

void display_values(int x, int y) {
    printf("local = %d | global = %d\n", x, y);
}

int main(void) {
    int local = 5;
    initialize_global_var(10);

    display_values(local, global);
    
    modify_variables(local);
    
    display_values(local, global);
    
    return 0;
}
