/*
 * Purpose: Collects user registration details and optionally son's information using nested structures.
 * Topic: Nested Structures, String Handling, Input Validation, Password Masking, Conditional Logic
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h> // For character handling functions

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
    struct BirthDate birth_date; // Nested structure for user's birthdate
};

// Structure to hold son's information
struct SonInfo {
    struct BirthDate son_birth_date; // Nested structure for son's birthdate
    char phone[50]; // Phone number
    char address[150]; // Home address
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

// Helper function to consume any leftover newline character in the input buffer
void consume_newline() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to read a date, with basic validation
int read_date(struct BirthDate *date) {
    printf("\tDay: ");
    if (scanf("%d", &date->day) != 1) {
        fprintf(stderr, "Error reading day.\n");
        return 0;
    }
    if (date->day < 1 || date->day > 31) {
        printf("Warning: Day seems out of range (1-31).\n");
    }

    consume_newline(); // Consume newline after day

    printf("\tMonth: ");
    if (scanf("%d", &date->month) != 1) {
        fprintf(stderr, "Error reading month.\n");
        return 0;
    }
    if (date->month < 1 || date->month > 12) {
        printf("Warning: Month seems out of range (1-12).\n");
    }

    consume_newline(); // Consume newline after month

    printf("\tYear: ");
    if (scanf("%d", &date->year) != 1) {
        fprintf(stderr, "Error reading year.\n");
        return 0;
    }
    // Example year validation range
    if (date->year < 1900 || date->year > 2025) {
        printf("Warning: Year seems out of a typical range (1900-2025).\n");
    }
    
    consume_newline(); // Consume newline after year
    return 0;
}

int main() {
    struct UserForm user_data;
    struct SonInfo son_data;
    int password_input_status;
    char has_son;

    printf("--- User Registration ---\n\n");

    // Get User's First Name
    printf("Enter your first name: ");
    if (fgets(user_data.first_name, sizeof(user_data.first_name), stdin) == NULL) {
        fprintf(stderr, "Error reading first name.\n");
        return 0;
    }
    user_data.first_name[strcspn(user_data.first_name, "\n")] = 0; // Remove trailing newline

    // Get User's Last Name
    printf("Enter your last name: ");
    if (fgets(user_data.last_name, sizeof(user_data.last_name), stdin) == NULL) {
        fprintf(stderr, "Error reading last name.\n");
        return 0;
    }
    user_data.last_name[strcspn(user_data.last_name, "\n")] = 0; // Remove trailing newline

    // Get User's Username
    printf("Enter your username: ");
    if (fgets(user_data.user_name, sizeof(user_data.user_name), stdin) == NULL) {
        fprintf(stderr, "Error reading username.\n");
        return 0;
    }
    user_data.user_name[strcspn(user_data.user_name, "\n")] = 0; // Remove trailing newline

    // Get and confirm User's Password
    printf("Enter password (max %d characters): ", (int)sizeof(user_data.password) - 1);
    password_input_status = read_password(user_data.password, sizeof(user_data.password));
    if (password_input_status != 0) return 0;

    printf("Confirm password: ");
    password_input_status = read_password(user_data.repeat_password, sizeof(user_data.repeat_password));
    if (password_input_status != 0) return 0;

    // Check if passwords match
    if (strcmp(user_data.password, user_data.repeat_password) != 0) {
        printf("Error: Passwords do not match.\n");
        return 0;
    } else {
        printf("Passwords match.\n");
    }

    // Get User's Birthdate
    printf("Enter your birthdate:\n");
    if (read_date(&user_data.birth_date) != 0) return 0;

    // Ask about having a son
    printf("Do you have a son? (Y/N): ");
    // Read the single character response, consuming the newline afterwards
    if (scanf(" %c", &has_son) != 1) { // Note the space before %c to consume leading whitespace/newline
        fprintf(stderr, "Error reading son information query.\n");
        return 0;
    }
    consume_newline(); // Consume the newline after reading the character

    // If the user has a son, collect his information
    if (has_son == 'Y' || has_son == 'y') {
        printf("Enter your son's birthdate:\n");
        if (read_date(&son_data.son_birth_date) != 0) return 0;

        // Get Son's Phone Number
        printf("Enter your son's phone number: ");
        if (fgets(son_data.phone, sizeof(son_data.phone), stdin) == NULL) {
            fprintf(stderr, "Error reading son's phone number.\n");
            return 0;
        }
        son_data.phone[strcspn(son_data.phone, "\n")] = 0; // Remove trailing newline

        // Get Son's Home Address
        printf("Enter your son's home address: ");
        if (fgets(son_data.address, sizeof(son_data.address), stdin) == NULL) {
            fprintf(stderr, "Error reading son's home address.\n");
            return 0;
        }
        son_data.address[strcspn(son_data.address, "\n")] = 0; // Remove trailing newline
        
        printf("\n--- Thank you for your kind information! ---\n");
    } else {
        printf("\n--- Thank you for your kind information! ---\n");
    }

    // Display collected user information (excluding son's details for brevity here)
    printf("\n--- User Information Summary ---\n");
    printf("Name: %s %s\n", user_data.first_name, user_data.last_name);
    printf("Username: %s\n", user_data.user_name);
    printf("Birthdate: %d/%d/%d\n", user_data.birth_date.day, user_data.birth_date.month, user_data.birth_date.year);

    return 0;
}
