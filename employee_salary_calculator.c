/*
 * Purpose: Calculates an employee's total salary based on sales, commission, and bonus.
 * Topic: Basic I/O, Floating-point Arithmetic
 */

#include <stdio.h>

float get_computers_sold(void) {
    float num_computers_sold;
    printf("Enter the number of computers sold: ");
    scanf("%f", &num_computers_sold);
    return num_computers_sold;
}

float get_computer_price(void) {
    float computer_price;
    printf("Enter the price per computer: ");
    scanf("%f", &computer_price);
    return computer_price;
}

float calculate_commission(float total_sales) {
    return (total_sales * 2) / 100;
}

float calculate_bonus(float num_computers) {
    return num_computers * 200;
}

float calculate_total_salary(float commission, float bonus) {
    float base_salary = 1500.0;
    return base_salary + bonus + commission;
}

void display_salary(float total_salary) {
    printf("The total salary should be %.2f\n", total_salary);
}

int main(void) {
    float num_computers_sold = get_computers_sold();
    float computer_price = get_computer_price();
    
    float total_sales_money = num_computers_sold * computer_price;
    float commission_amount = calculate_commission(total_sales_money);
    float bonus_amount = calculate_bonus(num_computers_sold);
    float total_salary = calculate_total_salary(commission_amount, bonus_amount);
    
    display_salary(total_salary);
    
    return 0;
}
