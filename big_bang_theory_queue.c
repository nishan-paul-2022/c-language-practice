/*
 * Purpose: Solves a problem where a sequence of names repeats with doubling frequency.
 * Topic: Loops, Arrays, Large Integers (long long int), Problem Solving
 */

#include <stdio.h>
#include <string.h>

long long find_position_in_current_block(long long position) {
    long long current_block_size = 1;
    
    while (current_block_size * 5 < position) {
        position -= current_block_size * 5;
        current_block_size *= 2;
    }

    long long name_index = (position - 1) / current_block_size;
    
    return name_index;
}

void get_name_at_position(long long position, char *result) {
    char names[5][100] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    long long name_index = find_position_in_current_block(position);
    strcpy(result, names[name_index]);
}

int main(void) {
    long long n_th_person;
    char result_name[100];

    printf("Enter the N-th person's position: ");
    scanf("%lld", &n_th_person);

    get_name_at_position(n_th_person, result_name);
    printf("Name of the N-th person: %s\n", result_name);

    return 0;
}
