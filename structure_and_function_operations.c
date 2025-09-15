/*
 * Purpose: Demonstrates passing structures to functions and returning structures from functions.
 * Topic: Structures, Functions, Pass-by-Value, Return-by-Value
 */

#include <stdio.h>

typedef struct {
    int integer_part;
    float float_part;
} NumericData;

NumericData add_numeric_data(NumericData data1, NumericData data2) {
    NumericData result;
    result.integer_part = data1.integer_part + data2.integer_part;
    result.float_part = data1.float_part + data2.float_part;
    return result;
}

void print_numeric_data(const NumericData *data) {
    printf("Result: Integer = %d, Float = %.2f\n", data->integer_part, data->float_part);
}

int main(void) {
    NumericData operand1 = {100, 3.14159f};
    NumericData operand2 = operand1;
    NumericData sum_result = add_numeric_data(operand1, operand2);

    print_numeric_data(&sum_result);

    return 0;
}
