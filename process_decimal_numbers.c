/*
 * Purpose: Reads three decimal numbers, finds the maximum number of decimal places, scales them to integers, finds their GCD, and performs a final calculation.
 * Topic: Floating-Point Numbers, Integer Conversion, GCD, Basic Arithmetic
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of decimal places in a double.
// It repeatedly multiplies the number by 10 until it becomes an integer.
// Returns the number of multiplications performed.
long long count_decimal_places(double num) {
    if (num == 0.0) return 0; // Special case for zero

    long long decimal_places = 0;
    // Use a small epsilon for floating point comparison to avoid precision issues
    // However, for typical decimal inputs, direct comparison might be sufficient.
    // Let's stick to the original logic for now, assuming standard decimal inputs.
    while (num != (long long)num) {
        num *= 10.0;
        decimal_places++;
        // Add a safeguard against infinite loops for non-terminating decimals or very large numbers
        if (decimal_places > 15) { // Arbitrary limit to prevent infinite loops
            fprintf(stderr, "Warning: Number might have too many decimal places or is not terminating.\n");
            return decimal_places; // Return current count
        }
    }
    return decimal_places;
}

// Function to multiply a double by 10, 'power' times.
// Returns the result as a long long integer.
long long scale_number(double num, long long power) {
    for (long long i = 0; i < power; ++i) {
        num *= 10.0;
    }
    // Cast to long long, truncating any remaining fractional part.
    // This assumes the scaling was sufficient to make it an integer.
    return (long long)num;
}

// Function to calculate the Greatest Common Divisor (GCD) of two numbers using recursion.
long long calculate_gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return calculate_gcd(b, a % b);
    }
}

// Function to calculate 10 raised to the power of 'exp'.
long long power_of_10(int exp) {
    long long result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= 10;
    }
    return result;
}

int main(void) {
    double input_numbers[3];
    long long scaled_integers[3];
    long long max_decimal_places = 0;
    long long scaling_factor;
    long long common_divisor;

    // Get input from the user
    printf("Enter three decimal numbers separated by commas (e.g., 1.23, 4.5, 6.789): ");
    if (scanf("%lf, %lf, %lf", &input_numbers[0], &input_numbers[1], &input_numbers[2]) != 3) {
        fprintf(stderr, "Error: Invalid input format. Please use the specified format.\n");
        return 0;
    }

    // --- Determine the maximum number of decimal places ---
    // Find the maximum number of decimal places among the three input numbers.
    max_decimal_places = count_decimal_places(input_numbers[0]);
    long long dp1 = count_decimal_places(input_numbers[1]);
    long long dp2 = count_decimal_places(input_numbers[2]);

    if (dp1 > max_decimal_places) max_decimal_places = dp1;
    if (dp2 > max_decimal_places) max_decimal_places = dp2;

    // Calculate the scaling factor (10 raised to the power of max_decimal_places)
    scaling_factor = power_of_10(max_decimal_places);

    // Scale the input numbers to convert them into integers
    scaled_integers[0] = scale_number(input_numbers[0], max_decimal_places);
    scaled_integers[1] = scale_number(input_numbers[1], max_decimal_places);
    scaled_integers[2] = scale_number(input_numbers[2], max_decimal_places);

    // --- Calculate the GCD of the scaled integers ---
    // Find the GCD of the three scaled integers.
    // The loop calculates gcd(y[0], y[1], y[2]) and stores it in scaled_integers[2].
    common_divisor = scaled_integers[0]; // Start with the first scaled integer
    common_divisor = calculate_gcd(common_divisor, scaled_integers[1]);
    common_divisor = calculate_gcd(common_divisor, scaled_integers[2]);

    // --- Perform the final calculation ---
    // The original code calculated l = (double) y[i]/k, where y[i] was the GCD and k was the scaling factor.
    // This results in GCD(scaled_numbers) / 10^max_decimal_places.
    // We will replicate this calculation with descriptive variable names.
    double final_result = (double)common_divisor / scaling_factor;

    // Print the result
    printf("Maximum decimal places: %lld\n", max_decimal_places);
    printf("Scaling factor (10^%lld): %lld\n", max_decimal_places, scaling_factor);
    printf("Scaled integers: %lld, %lld, %lld\n", scaled_integers[0], scaled_integers[1], scaled_integers[2]);
    printf("GCD of scaled integers: %lld\n", common_divisor);
    printf("Final result (GCD / Scaling Factor): %lf\n", final_result);

    return 0;
}
