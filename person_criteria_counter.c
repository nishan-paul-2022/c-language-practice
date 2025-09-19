/*
 * Purpose: Counts the number of persons meeting specific criteria (weight < 50 and height > 170).
 * Topic: Input Processing, Loops, Conditional Statements, Counting
 */
#include <stdio.h>
#include <stdlib.h>

int get_number_of_persons() {
    int num_persons;
    printf("Enter the number of persons: ");
    
    if (scanf("%d", &num_persons) != 1) {
        fprintf(stderr, "Invalid input for the number of persons.\n");
        while (getchar() != '\n');
        return -1;
    }
    
    if (num_persons < 0) {
        fprintf(stderr, "Number of persons cannot be negative.\n");
        return -1;
    }
    
    return num_persons;
}

int get_person_data(int person_number, int *weight, int *height) {
    printf("Person %d: ", person_number);
    
    if (scanf("%d %d", weight, height) != 2) {
        fprintf(stderr, "\nInvalid input for weight and height for person %d.\n", person_number);
        while (getchar() != '\n');
        return -1;
    }
    
    return 0;
}

int is_countable(int weight, int height) {
    return (weight < 50 && height > 170);
}

void display_person_status(int is_valid) {
    printf("  -> %s\n", is_valid ? "Countable" : "Not countable");
}

void display_final_count(int count) {
    printf("\nTotal number of countable persons: %d\n", count);
}

int main(void) {
    int num_persons = get_number_of_persons();
    if (num_persons == -1) {
        return 0;
    }
    
    int countable_persons_count = 0;
    
    printf("Enter weight and height for each person:\n");
    
    for (int person_index = 0; person_index < num_persons; ++person_index) {
        int weight, height;
        
        if (get_person_data(person_index + 1, &weight, &height) == -1) {
            return 0;
        }
        
        if (is_countable(weight, height)) {
            countable_persons_count++;
            display_person_status(1);
        } else {
            display_person_status(0);
        }
    }
    
    display_final_count(countable_persons_count);
    
    return 0;
}
