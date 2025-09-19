#include <stdio.h>
#include <string.h>
#include <ctype.h>

int get_test_cases(void) {
    int num_test_cases;
    printf("Enter the number of test cases: ");
    if (scanf("%d", &num_test_cases) != 1) {
        printf("Invalid input for number of test cases.\n");
        return -1;
    }
    return num_test_cases;
}

int get_string_input(char *input_string, int case_number) {
    printf("Enter string %d: ", case_number);
    if (scanf("%99s", input_string) != 1) {
        printf("Invalid input for string.\n");
        return -1;
    }
    return 0;
}

void convert_to_lowercase(char *string) {
    int string_length = strlen(string);
    for (int i = 0; i < string_length; i++) {
        string[i] = tolower(string[i]);
    }
}

int is_palindrome(const char *string) {
    int string_length = strlen(string);
    int left_index = 0;
    int right_index = string_length - 1;

    while (left_index < right_index) {
        if (string[left_index] != string[right_index]) {
            return -1; // Not a palindrome
        }
        left_index++;
        right_index--;
    }

    return 0; // Palindrome
}

void display_result(const char *string, int palindrome_result) {
    if (palindrome_result == 0) {
        printf("String '%s' is a palindrome.\n", string);
    } else {
        printf("String '%s' is not a palindrome.\n", string);
    }
}

void process_test_cases(int num_test_cases) {
    for (int i = 0; i < num_test_cases; i++) {
        char input_string[100];
        if (get_string_input(input_string, i + 1) == -1) {
            continue;
        }

        convert_to_lowercase(input_string);
        int result = is_palindrome(input_string);
        display_result(input_string, result);
    }
}

int main(void) {
    int num_test_cases = get_test_cases();
    if (num_test_cases == -1) {
        return 0;
    }

    process_test_cases(num_test_cases);
    return 0;
}
