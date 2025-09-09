/*
 * Purpose: Calculates and prints the roots of a quadratic equation (ax^2 + bx + c = 0).
 *          This is an alternative implementation to demonstrate different ways to structure the logic.
 * Topic: Conditional Statements, Mathematical Functions (sqrt), Floating-point Arithmetic
 */

#include <stdio.h>
#include <math.h>

int main() {
    float coeff_a, coeff_b, coeff_c; // Coefficients of the quadratic equation
    float discriminant; // Discriminant (b*b - 4*a*c)
    float root_real_part, root_imaginary_part; // For complex roots
    float root1, root2; // For real roots

    // Prompt user for input
    printf("Enter the coefficients a, b, and c (e.g., 1.0 5.0 6.0): ");
    scanf("%f %f %f", &coeff_a, &coeff_b, &coeff_c);

    // Check if 'a' is zero. If so, it's not a quadratic equation.
    if (coeff_a == 0) {
        printf("Error: Coefficient 'a' cannot be zero for a quadratic equation.\n");
    } else {
        // Calculate the discriminant
        discriminant = coeff_b * coeff_b - 4 * coeff_a * coeff_c;

        // Case 1: Discriminant is positive (real and distinct roots)
        if (discriminant > 0) {
            root1 = (-coeff_b + sqrt(discriminant)) / (2 * coeff_a);
            root2 = (-coeff_b - sqrt(discriminant)) / (2 * coeff_a);
            printf("The roots are real and distinct:\n");
            printf("Root 1 = %.3f\n", root1);
            printf("Root 2 = %.3f\n", root2);
        }
        // Case 2: Discriminant is zero (real and equal roots)
        else if (discriminant == 0) {
            root1 = root2 = -coeff_b / (2 * coeff_a);
            printf("The roots are real and equal:\n");
            printf("Root 1 = Root 2 = %.3f\n", root1);
        }
        // Case 3: Discriminant is negative (complex roots)
        else {
            // Calculate the real and imaginary parts
            root_real_part = -coeff_b / (2 * coeff_a);
            root_imaginary_part = sqrt(-discriminant) / (2 * coeff_a); // Use -discriminant as discriminant is negative

            printf("The roots are complex and conjugate:\n");
            printf("Root 1 = %.3f + %.3fi\n", root_real_part, root_imaginary_part);
            printf("Root 2 = %.3f - %.3fi\n", root_real_part, root_imaginary_part);
        }
    }

    return 0;
}
