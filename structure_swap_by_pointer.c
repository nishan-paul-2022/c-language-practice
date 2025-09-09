/*
 * Purpose: Demonstrates swapping structure contents using pointers based on a condition.
 * Topic: Structures, Pointers to Structures, Functions, String Handling
 */

#include <stdio.h>
#include <string.h> // Required for strcpy

// Define a structure to hold person's information
struct Person {
    char name[100];      // Name of the person
    char phone[100];     // Phone number of the person
    int age;             // Age of the person
};

// Function to swap two Person structures if person2's age is greater than person1's age.
// It takes pointers to the structures to modify them directly.
void swap_persons_by_age(struct Person *person1, struct Person *person2) {
    // Check if person2's age is greater than person1's age
    if (person2->age > person1->age) {
        // Temporary structure to hold data during swap
        struct Person temp_person;

        // Copy data from person2 to temp_person
        strcpy(temp_person.name, person2->name);
        strcpy(temp_person.phone, person2->phone);
        temp_person.age = person2->age;

        // Copy data from person1 to person2
        strcpy(person2->name, person1->name);
        strcpy(person2->phone, person1->phone);
        person2->age = person1->age;

        // Copy data from temp_person to person1
        strcpy(person1->name, temp_person.name);
        strcpy(person1->phone, temp_person.phone);
        person1->age = temp_person.age;
    }
}

int main() {
    // Declare two Person structures and pointers to them
    struct Person person1;
    struct Person person2;
    struct Person *ptr_person1 = &person1;
    struct Person *ptr_person2 = &person2;

    // Input for the first person
    printf("Enter details for Person 1:\n");
    printf("Name: ");
    // Use scanf with a width specifier to prevent buffer overflow
    scanf("%99s", ptr_person1->name);
    printf("Phone: ");
    scanf("%99s", ptr_person1->phone);
    printf("Age: ");
    scanf("%d", &ptr_person1->age);

    // Input for the second person
    printf("\nEnter details for Person 2:\n");
    printf("Name: ");
    scanf("%99s", ptr_person2->name);
    printf("Phone: ");
    scanf("%99s", ptr_person2->phone);
    printf("Age: ");
    scanf("%d", &ptr_person2->age);

    // Call the swap function
    swap_persons_by_age(ptr_person1, ptr_person2);

    // Output the details of the first person
    printf("\nDetails of Person 1 after potential swap:\n");
    printf("Name: %s\n", ptr_person1->name);
    printf("Phone: %s\n", ptr_person1->phone);
    printf("Age: %d\n", ptr_person1->age);

    // Output the details of the second person
    printf("\nDetails of Person 2 after potential swap:\n");
    printf("Name: %s\n", ptr_person2->name);
    printf("Phone: %s\n", ptr_person2->phone);
    printf("Age: %d\n", ptr_person2->age);

    return 0;
}
