/*
 * Purpose: Calculates and prints the roots of a quadratic equation (ax^2 + bx + c = 0).
 *          Handles cases for real and distinct, real and equal, and complex roots.
 * Topic: Conditional Statements, Mathematical Functions (sqrt), Floating-point Arithmetic
 */

#include <stdio.h> // Required for printf and scanf
#include <math.h>  // Required for sqrt()

int main() {
    float a, b, c; // Coefficients of the quadratic equation
    float discriminant; // Discriminant (b*b - 4*a*c)
    float root1, root2; // Variables to store the roots
    float real_part, imaginary_part; // For complex roots

    // Prompt user for input
    printf("Enter the coefficients a, b, and c (e.g., 1.0 5.0 6.0): \n");
    scanf("%f %f %f", &a, &b, &c);

    // Check if 'a' is zero, which means it's not a quadratic equation
    if (a == 0) {
        printf("Error: 'a' cannot be zero for a quadratic equation.\n");
    } else {
        // Calculate the discriminant
        discriminant = b * b - 4 * a * c;

        // Case 1: Discriminant is positive (real and distinct roots)
        if (discriminant > 0) {
            root1 = (-b + sqrt(discriminant)) / (2 * a);
            root2 = (-b - sqrt(discriminant)) / (2 * a);
            printf("The roots are real and distinct:\n");
            printf("Root 1 = %.3f\n", root1);
            printf("Root 2 = %.3f\n", root2);
        }
        // Case 2: Discriminant is zero (real and equal roots)
        else if (discriminant == 0) {
            root1 = root2 = -b / (2 * a);
            printf("The roots are real and equal:\n");
            printf("Root 1 = Root 2 = %.3f\n", root1);
        }
        // Case 3: Discriminant is negative (complex roots)
        else {
            real_part = -b / (2 * a);
            imaginary_part = sqrt(-discriminant) / (2 * a);
            printf("The roots are complex and conjugate:\n");
            printf("Root 1 = %.3f + %.3fi\n", real_part, imaginary_part);
            printf("Root 2 = %.3f - %.3fi\n", real_part, imaginary_part);
        }
    }

    return 0;
}
