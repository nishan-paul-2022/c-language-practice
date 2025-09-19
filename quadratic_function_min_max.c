/*
 * Purpose: Analyze quadratic function to find min/max values and perform calculations.
 * Topic: Quadratic Functions, Mathematical Analysis, Numerical Computation
 */

#include <stdio.h>
#include <math.h>

#define START_X 0
#define END_X 100
#define COEFF_A 0.01
#define COEFF_B -0.8
#define COEFF_C 40.0

// Calculate quadratic function value
double quadratic_function(int x) {
    double y = COEFF_A * x * x + COEFF_B * x + COEFF_C;
    return y;
}

// Find theoretical vertex of parabola
double find_vertex_x() {
    double vertex = -COEFF_B / (2.0 * COEFF_A);
    return vertex;
}

// Calculate discriminant-based result
double calculate_D(double y_value) {
    double term = 4000.0 - y_value * 100.0;
    double discriminant = 6400.0 - 4.0 * term;
    
    if (discriminant < 0) {
        printf("Warning: Negative discriminant (%.2f)\n", discriminant);
        return 0.0;
    }
    
    return sqrt(discriminant);
}

int main(void) {
    printf("Quadratic Function Analysis\n");
    printf("===========================\n\n");

    printf("Function: y = 0.01x² - 0.8x + 40\n");
    printf("Range: x = %d to %d\n\n", START_X, END_X);
    
    // Theoretical analysis
    double vertex_x = find_vertex_x();
    double vertex_y = quadratic_function((int)vertex_x);
    printf("Theoretical vertex: x = %.1f, y = %.2f\n\n", vertex_x, vertex_y);
    
    // Find min/max through iteration
    double min_y = quadratic_function(START_X);
    double max_y = quadratic_function(START_X);
    int min_x = START_X, max_x = START_X;
    
    printf("Analyzing function values:\n");
    
    for (int x = START_X; x <= END_X; x++) {
        double y = quadratic_function(x);
        
        if (y < min_y) {
            min_y = y;
            min_x = x;
        }
        if (y > max_y) {
            max_y = y;
            max_x = x;
        }
        
        // Show key points
        if (x == START_X || x == END_X || x == (int)vertex_x || 
            x % 20 == 0) {
            printf("  x = %3d: y = %6.2f\n", x, y);
        }
    }
    
    printf("\nResults:\n");
    printf("Minimum: y = %.2f at x = %d\n", min_y, min_x);
    printf("Maximum: y = %.2f at x = %d\n", max_y, max_x);
    
    // Calculate D values
    double D1 = calculate_D(min_y);
    double D2 = calculate_D(max_y);
    
    printf("\nCalculations:\n");
    printf("D1 = √(6400 - 4(4000 - %.2f×100)) = %.2f\n", min_y, D1);
    printf("D2 = √(6400 - 4(4000 - %.2f×100)) = %.2f\n", max_y, D2);
    
    // Final results
    double result1 = 4.0 + 0.05 * D1;
    double result2 = 4.0 + 0.05 * D2;
    
    printf("\nFinal Results:\n");
    printf("4 + 0.05×D1 = 4 + 0.05×%.2f = %.2f\n", D1, result1);
    printf("4 + 0.05×D2 = 4 + 0.05×%.2f = %.2f\n", D2, result2);
    
    // Original format output
    printf("\nOriginal Format Output:\n");
    printf("%.2f, %.2f\n", min_y, max_y);
    printf("%.0f, %.0f\n", result1, result2);
    
    return 0;
}
