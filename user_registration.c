/*
 * Purpose: Collects user registration details and optionally son's information using nested structures.
 * Topic: Nested Structures, String Handling, Input Validation, Password Masking, Conditional Logic
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct birth_date {
    int day;
    int month;
    int year;
};

struct user_form {
    char first_name[100];
    char last_name[100];
    char user_name[100];
    char password[100];
    char repeat_password[100];
    struct birth_date birth_date;
};

void consume_newline(void) {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int read_password(char pass_cpy[], int buffer_size) {
    char ch;
    int i = 0;

    while ((ch = getchar()) != '\n') {
        if (i < buffer_size - 1) {
            if (ch == '\b' || ch == 127) {
                if (i > 0) {
                    putchar('\b'); putchar(' '); putchar('\b');
                    i--;
                }
            } else {
                putchar('*'); pass_cpy[i++] = ch;
            }
        } else {
            fprintf(stderr, "\nError: Password too long. Max %d characters.\n", buffer_size - 1);
            while ((ch = getchar()) != '\n' && ch != EOF);
            return 1;
        }
    }
    pass_cpy[i] = '\0';
    printf("\n");
    return 0;
}

int read_date(struct birth_date *date) {
    printf("\tDay: "); if (scanf("%d", &date->day) != 1) return 1;
    if (date->day < 1 || date->day > 31) printf("Warning: Day seems out of range (1-31).\n");
    consume_newline();

    printf("\tMonth: "); if (scanf("%d", &date->month) != 1) return 1;
    if (date->month < 1 || date->month > 12) printf("Warning: Month seems out of range (1-12).\n");
    consume_newline();

    printf("\tYear: "); if (scanf("%d", &date->year) != 1) return 1;
    if (date->year < 1900 || date->year > 2025) printf("Warning: Year seems out of range (1900-2025).\n");
    consume_newline();

    return 0;
}

void get_user_info(struct user_form *user) {
    printf("Enter your first name: ");
    fgets(user->first_name, sizeof(user->first_name), stdin);
    user->first_name[strcspn(user->first_name, "\n")] = 0;

    printf("Enter your last name: ");
    fgets(user->last_name, sizeof(user->last_name), stdin);
    user->last_name[strcspn(user->last_name, "\n")] = 0;

    printf("Enter your username: ");
    fgets(user->user_name, sizeof(user->user_name), stdin);
    user->user_name[strcspn(user->user_name, "\n")] = 0;

    printf("Enter password (max %d chars): ", (int)sizeof(user->password)-1);
    if (read_password(user->password, sizeof(user->password))) return;

    printf("Confirm password: ");
    if (read_password(user->repeat_password, sizeof(user->repeat_password))) return;

    if (strcmp(user->password, user->repeat_password)) {
        printf("Error: Passwords do not match.\n");
        return;
    } else {
        printf("Passwords match.\n");
    }

    printf("Enter your birth_date:\n");
    read_date(&user->birth_date);
}

void print_user_summary(const struct user_form *user) {
    printf("\n--- Thank you for your kind information! ---\n");
    printf("\n--- User Information Summary ---\n");
    printf("Name: %s %s\n", user->first_name, user->last_name);
    printf("Username: %s\n", user->user_name);
    printf("Birth Date: %d/%d/%d\n", user->birth_date.day, user->birth_date.month, user->birth_date.year);
}

int main(void) {
    printf("--- User Registration ---\n\n");
    struct user_form user_data;
    get_user_info(&user_data);
    print_user_summary(&user_data);
    return 0;
}
