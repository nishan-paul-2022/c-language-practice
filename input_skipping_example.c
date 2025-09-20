/*
 * Purpose: Demonstrates reading multiple integers from input, including skipping one.
 * Topic: Input/Output (scanf), Format Specifiers, Variable Declaration
 */

#include <stdio.h>

int readAndCalculateProduct() {
    printf("Enter three integers (e.g., 10 20 30): ");
    int num1, num2;
    int items_read = scanf("%d %d %*d", &num1, &num2); 

    if (items_read == 2) {
        printf("Entered two integers: %d and %d\n", num1, num2);
        printf("Product of %d and %d is: %d\n", num1, num2, num1 * num2);
        return 0; 
    } else {
        printf("Invalid input. Please enter three integers separated by spaces.\n");
        return -1; 
    }
}

int main(void) {
    readAndCalculateProduct();
    return 0;
}
