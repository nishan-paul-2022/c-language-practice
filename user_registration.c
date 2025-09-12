/*
 * Purpose: Demonstrates user registration with nested structures, including password input and confirmation.
 * Topic: Structures, Nested Structures, String Handling, Input Validation, Password Masking
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Structure to hold birthdate information
struct BirthDate {
    int day;
    int month;
    int year;
};

// Structure to hold user registration form data
struct UserForm {
    char first_name[100];
    char last_name[100];
    char user_name[100];
    char password[100];
    char repeat_password[100];
    struct BirthDate birth_date; // Nested structure for birthdate
};

// Function to securely read a password, masking input with asterisks.
// It reads characters until Enter is pressed and stores them in pass_cpy.
// Returns 0 on success, 1 on buffer overflow.
int read_password(char pass_cpy[], int buffer_size) {
    char ch;
    int i = 0;

    // Read characters one by one until newline is encountered
    while ((ch = getchar()) != '\n') {
        // Check for buffer overflow before storing the character
        if (i < buffer_size - 1) { // Leave space for null terminator
            if (ch == '\b' || ch == 127) { // Handle backspace (ASCII 8 or 127)
                if (i > 0) {
                    putchar('\b'); // Move cursor back
                    putchar(' ');  // Overwrite character with space
                    putchar('\b'); // Move cursor back again
                    i--;
                }
            } else {
                putchar('*'); // Display asterisk for masked input
                pass_cpy[i] = ch;
                i++;
            }
        } else {
            // Buffer overflow detected
            fprintf(stderr, "\nError: Password too long. Maximum %d characters allowed.\n", buffer_size - 1);
            // Clear the rest of the input buffer to prevent issues with subsequent reads
            while ((ch = getchar()) != '\n' && ch != EOF);
            return 0;
        }
    }
    pass_cpy[i] = '\0'; // Null-terminate the password string
    printf("\n"); // Newline after password input
    return 0;
}

int main(void) {
    struct UserForm user_data;
    int password_input_status;

    printf("--- User Registration ---\n\n");

    // Get First Name
    printf("Enter your first name: ");
    if (fgets(user_data.first_name, sizeof(user_data.first_name), stdin) == NULL) {
        fprintf(stderr, "Error reading first name.\n");
        return 0;
    }
    user_data.first_name[strcspn(user_data.first_name, "\n")] = 0; // Remove trailing newline

    // Get Last Name
    printf("Enter your last name: ");
    if (fgets(user_data.last_name, sizeof(user_data.last_name), stdin) == NULL) {
        fprintf(stderr, "Error reading last name.\n");
        return 0;
    }
    user_data.last_name[strcspn(user_data.last_name, "\n")] = 0; // Remove trailing newline

    // Get Username
    printf("Enter your username: ");
    if (fgets(user_data.user_name, sizeof(user_data.user_name), stdin) == NULL) {
        fprintf(stderr, "Error reading username.\n");
        return 0;
    }
    user_data.user_name[strcspn(user_data.user_name, "\n")] = 0; // Remove trailing newline

    // Get and confirm Password
    printf("Enter password (max %d characters): ", (int)sizeof(user_data.password) - 1);
    password_input_status = read_password(user_data.password, sizeof(user_data.password));
    if (password_input_status) return 0; // Exit if password input failed

    printf("Confirm password: ");
    password_input_status = read_password(user_data.repeat_password, sizeof(user_data.repeat_password));
    if (password_input_status) return 0; // Exit if password confirmation failed

    // Check if passwords match
    if (strcmp(user_data.password, user_data.repeat_password)) {
        printf("Error: Passwords do not match.\n");
        return 0; // Exit if passwords don't match
    } else {
        printf("Passwords match.\n");
    }

    // Get Birthdate
    printf("Enter your birthdate:\n");
    
    // Get Day
    printf("\tDay: ");
    if (scanf("%d", &user_data.birth_date.day) != 1) {
        fprintf(stderr, "Error reading day.\n");
        return 0;
    }
    // Basic validation for day (can be more robust)
    if (user_data.birth_date.day < 1 || user_data.birth_date.day > 31) {
        printf("Warning: Day seems out of range.\n");
    }

    // Get Month
    printf("\tMonth: ");
    if (scanf("%d", &user_data.birth_date.month) != 1) {
        fprintf(stderr, "Error reading month.\n");
        return 0;
    }
    // Basic validation for month
    if (user_data.birth_date.month < 1 || user_data.birth_date.month > 12) {
        printf("Warning: Month seems out of range.\n");
    }

    // Get Year
    printf("\tYear: ");
    if (scanf("%d", &user_data.birth_date.year) != 1) {
        fprintf(stderr, "Error reading year.\n");
        return 0;
    }
    // Basic validation for year (e.g., not in the far future or past)
    if (user_data.birth_date.year < 1900 || user_data.birth_date.year > 2025) { // Example range
        printf("Warning: Year seems out of a typical range.\n");
    }
    
    // Consume any leftover newline character after scanf for integers
    // This is important if more string input were to follow.
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("\n--- Registration Successful ---\n");
    printf("Name: %s %s\n", user_data.first_name, user_data.last_name);
    printf("Username: %s\n", user_data.user_name);
    printf("Birthdate: %d/%d/%d\n", user_data.birth_date.day, user_data.birth_date.month, user_data.birth_date.year);

    return 0;
}
