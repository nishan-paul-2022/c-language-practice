/*
 * Purpose: Plot exponential and Gaussian decay functions using ASCII visualization
 * Topic: Mathematical Functions, Exponential Decay, Gaussian Function, ASCII Plotting
 */

#include <stdio.h>
#include <math.h>

void plot_function(double x, double a, char symbol) {
    double y = 50.0 * exp(-a * x);
    int scaled = (int)y;
    for (int i = 0; i < scaled; i++) {
        printf(" ");
    }
    printf("%c\n", symbol);
}

void plot_gaussian(double x, double a, char symbol) {
    double y = 50.0 * exp(-a * x * x / 2.0);
    int scaled = (int)y;
    for (int i = 0; i < scaled; i++) {
        printf(" ");
    }
    printf("%c\n", symbol);
}

int main(void) {
    const double decay_constant = 0.4;
    
    for (double x = 0.0; x <= 5.0; x += 0.25) {
        plot_function(x, decay_constant, '1');
        plot_gaussian(x, decay_constant, '2');
    }
    
    return 0;
}
