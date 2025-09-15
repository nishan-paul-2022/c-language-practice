/*
 * Purpose: Calculates the Euclidean magnitude (length) of a 3D vector.
 * Topic: Floating-point Arithmetic, Math Functions (sqrt), Input/Output Formatting, Functions
 */

#include <stdio.h>
#include <math.h>

// Function to calculate magnitude of a 3D vector
double vector_magnitude(double x, double y, double z) {
    return sqrt(x*x + y*y + z*z);
}

// Function to process a single test case
void process_test_case(int case_num) {
    double x, y, z;
    printf("Enter components of vector for test case %d (x y z): ", case_num);
    if (scanf("%lf %lf %lf", &x, &y, &z) != 3) {
        printf("[ERROR] Invalid input for vector components.\n");
        return;
    }
    double mag = vector_magnitude(x, y, z);
    printf("Magnitude of vector: %.2lf\n\n", mag);
}

int main(void) {
    int num_test_cases;

    printf("--- 3D Vector Magnitude Calculator ---\n\n");
    printf("Enter number of test cases: ");
    if (scanf("%d", &num_test_cases) != 1 || num_test_cases <= 0) {
        printf("[ERROR] Invalid number of test cases.\n");
        return 0;
    }

    for (int i = 1; i <= num_test_cases; i++) {
        process_test_case(i);
    }

    return 0;
}
