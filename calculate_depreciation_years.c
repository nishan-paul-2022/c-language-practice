/*
 * Purpose: Calculates the time (in years) for an asset to depreciate from initial value to target value using logarithmic depreciation model.
 * Topic: Financial calculations - Asset depreciation
*/

#include <stdio.h>
#include <math.h>

int main(void) {
    double initial_cost;
    double depreciation_rate;
    double target_value;

    printf("Enter initial cost, depreciation rate, and target value (e.g., 10000.0, 0.10, 5000.0): ");
    if (scanf("%lf, %lf, %lf", &initial_cost, &depreciation_rate, &target_value) != 3) {
        fprintf(stderr, "Invalid input format. Please enter values as 'initial_cost, depreciation_rate, target_value'.\n");
        return 0;
    }

    
    if (initial_cost <= 0 || depreciation_rate <= 0 || depreciation_rate >= 1 || target_value <= 0 || target_value > initial_cost) {
        fprintf(stderr, "Invalid input values for depreciation calculation.\n");
        return 0;
    }

    
    double years_to_depreciate = log(target_value / initial_cost) / log(1.0 - depreciation_rate);

    printf("Years to depreciate from %.2lf to %.2lf at %.2lf%% rate: %lf\n",
           initial_cost, target_value, depreciation_rate * 100, years_to_depreciate);

    return 0;
}
