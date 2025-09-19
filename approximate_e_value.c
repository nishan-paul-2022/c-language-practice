/*
 * Purpose: Approximates the value of Euler's number (e) using its Taylor series expansion.
 * Topic: Series Approximation, Mathematical Constants
 */

#include <stdio.h>

int main(void) {
    double e = 1.0; 
    double term = 1.0; 
    double factorial = 1.0; 
    int n = 1; 

    
    while (1) {
        factorial *= n; 
        term = 1.0 / factorial; 

        
        if (term < 0.000001) {
            break;
        }

        e += term; 
        n++; 

        printf("Term %d: %0.15lf\n", n, e);
    }

    
    printf("Approximated value of e: %0.15lf\n", e);

    return 0;
}
