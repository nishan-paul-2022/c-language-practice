/*
 * Purpose: Reads three decimal numbers, finds the maximum number of decimal places, scales them to integers, finds their GCD, and performs a final calculation.
 * Topic: Floating-Point Numbers, Integer Conversion, GCD, Basic Arithmetic
*/

#include <stdio.h>
#include <stdlib.h>

long long count_decimal_places(double num) {
    if (num == 0.0) {
        return 0;
    }

    long long decimal_places = 0;
    while (num != (long long)num) {
        num *= 10.0;
        decimal_places++;
        if (decimal_places > 15) {
            return decimal_places; 
        }
    }

    return decimal_places;
}

long long scale_number(double num, long long power) {
    for (long long i = 0; i < power; i++) {
        num *= 10.0;
    }
    return (long long)num;
}

long long calculate_gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return calculate_gcd(b, a % b);
}

long long power_of_10(int exp) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
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

    printf("Enter three decimal numbers separated by commas (e.g., 1.23,4.5,6.789): ");
    if (scanf("%lf,%lf,%lf", &input_numbers[0], &input_numbers[1], &input_numbers[2]) != 3) {
        fprintf(stderr, "Invalid input format.\n");
        return 0;
    }
    
    max_decimal_places = count_decimal_places(input_numbers[0]);
    long long dp1 = count_decimal_places(input_numbers[1]);
    long long dp2 = count_decimal_places(input_numbers[2]);
    if (dp1 > max_decimal_places) {
        max_decimal_places = dp1;
    }
    if (dp2 > max_decimal_places) {
        max_decimal_places = dp2;
    }

    scaling_factor = power_of_10(max_decimal_places);
    
    for (int i = 0; i < 3; i++) {
        scaled_integers[i] = scale_number(input_numbers[i], max_decimal_places);
    }

    common_divisor = calculate_gcd(scaled_integers[0], scaled_integers[1]);
    common_divisor = calculate_gcd(common_divisor, scaled_integers[2]);
    
    double final_result = (double)common_divisor / scaling_factor;

    printf("Maximum decimal places: %lld\n", max_decimal_places);
    printf("Scaling factor (10^%lld): %lld\n", max_decimal_places, scaling_factor);
    printf("Scaled integers: %lld, %lld, %lld\n", scaled_integers[0], scaled_integers[1], scaled_integers[2]);
    printf("GCD of scaled integers: %lld\n", common_divisor);
    printf("Final result (GCD / Scaling Factor): %lf\n", final_result);

    return 0;
}
