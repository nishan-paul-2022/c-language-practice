/*
 * Purpose: Demonstrates swapping structure contents using pointers based on a condition, with function-based input/output handling.
 * Topic: Structures, Pointers to Structures, Functions, String Handling
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    char phone[100];
    int age;
} Person;

void swap_persons_by_age(Person *person1, Person *person2) {
    if (person2->age > person1->age) {
        Person temp_person = *person2;
        *person2 = *person1;
        *person1 = temp_person;
    }
}

void input_person(Person *person, int person_number) {
    printf("\nEnter details for Person %d:\n", person_number);
    printf("Name: ");
    scanf("%99s", person->name);
    printf("Phone: ");
    scanf("%99s", person->phone);
    printf("Age: ");
    scanf("%d", &person->age);
}

void print_person(const Person *person, int person_number) {
    printf("\nDetails of Person %d:\n", person_number);
    printf("Name: %s\n", person->name);
    printf("Phone: %s\n", person->phone);
    printf("Age: %d\n", person->age);
}

int main(void) {
    Person person1, person2;
    
    input_person(&person1, 1);
    input_person(&person2, 2);
    
    swap_persons_by_age(&person1, &person2);

    print_person(&person1, 1);
    print_person(&person2, 2);

    return 0;
}
