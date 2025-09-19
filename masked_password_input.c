/*
 * Purpose: Reads password from user, masking input with asterisks, and stores it securely.
 * Topic: Terminal Input, Password Masking, Character Handling, POSIX Terminal Control
 */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

int read_password_masked(char password[], int max_len) {
    struct termios old_tio;
    if (tcgetattr(STDIN_FILENO, &old_tio)) {
        perror("tcgetattr");
        return -1;
    }

    struct termios new_tio = old_tio;
    new_tio.c_lflag &= (~ECHO);
    if (tcsetattr(STDIN_FILENO, TCSANOW, &new_tio)) {
        perror("tcsetattr");
        return -1;
    }

    printf("Enter password: ");
    fflush(stdout);

    int i = 0;
    while (i < max_len - 1) {
        char character;
        if (read(STDIN_FILENO, &character, 1) != 1) {
            tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
            perror("read");
            return -1;
        }

        if (character == '\n' || character == 13) {
            break;
        }

        putchar('*');
        password[i] = character;
        i++;
    }

    password[i] = '\0';
    putchar('\n');

    if (tcsetattr(STDIN_FILENO, TCSANOW, &old_tio)) {
        perror("tcsetattr");
    }

    return 0;
}

int main(void) {
    char user_password[100];

    if (read_password_masked(user_password, sizeof(user_password)) == 0) {
        printf("Entered password: %s\n", user_password);
        return 0;
    } else {
        fprintf(stderr, "Failed to read password.\n");
        return 0;
    }
}
