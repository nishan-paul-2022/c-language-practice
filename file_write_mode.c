/*
 * Purpose: Demonstrates writing different data types (string, character) to a text file using fprintf, fputs, putc.
 * Topic: Text File I/O, Writing Data
 */

#include <stdio.h>

#define FILENAME "files/file_write_mode.txt"

FILE* open_file_for_writing(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file.");
    }
    return fp;
}

FILE* open_file_for_appending(const char *filename) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        perror("Error opening file for append.");
    }
    return fp;
}

void close_file(FILE *fp) {
    if (fp != NULL) {
        fclose(fp);
    }
}

int write_number() {
    FILE *fp = open_file_for_writing(FILENAME);
    if (fp == NULL) {
        return -1;
    }

    int number = 123456789;
    if (fprintf(fp, "%d\n", number) < 0) {
        perror("Error writing with fprintf.");
        close_file(fp);
        return -1;
    }

    close_file(fp);
    return 0;
}

int write_string() {
    FILE *fp = open_file_for_appending(FILENAME);
    if (fp == NULL) {
        return -1;
    }
    
    char str[] = "A promise was once made, that promise will be kept.\n";
    if (fputs(str, fp) == EOF) {
        perror("Error writing with fputs");
        close_file(fp);
        return -1;
    }

    close_file(fp);
    return 0;
}

int write_character() {
    FILE *fp = open_file_for_appending(FILENAME);
    if (fp == NULL) {
        return -1;
    }

    char ch = 'X';
    if (putc(ch, fp) == EOF) {
        perror("Error writing with putc.");
        close_file(fp);
        return -1;
    }

    close_file(fp);
    return 0;
}

int write_newline() {
    FILE *fp = open_file_for_appending(FILENAME);
    if (fp == NULL) {
        return -1;
    }

    if (putc('\n', fp) == EOF) {
        perror("Error writing newline with putc.");
        close_file(fp);
        return -1;
    }
    
    close_file(fp);
    return 0;
}

int main(void) {
    if (write_number() == -1) {
        return 0;
    }
    
    if (write_string() == -1) {
        return 0;
    }
    
    if (write_character() == -1) {
        return 0;
    }
    
    if (write_newline() == -1) {
        return 0;
    }

    printf("File written successfully to %s.\n", FILENAME);

    return 0;
}
