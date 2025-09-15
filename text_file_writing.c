/*
 * Purpose: Demonstrates writing different data types (string, character) to a text file using fprintf, fputs, and putc.
 * Topic: Text File I/O, Writing Data
 */

#include <stdio.h>

#define FILENAME "files/29-input.txt"

FILE* open_file_for_writing(const char *filename) {
    FILE *fp = fopen(filename, "w");
    return fp;
}

int write_formatted_number() {
    FILE *fp = open_file_for_writing(FILENAME);
    if (fp == NULL) {
        return -1;
    }

    int number = 12345;
    if (fprintf(fp, "Formatted number: %d\n", number) < 0) {
        perror("Error writing with fprintf");
        return -1;
    }

    return 0;
}

int write_string() {
    FILE *fp = open_file_for_writing(FILENAME);
    if (fp == NULL) {
        return -1;
    }
    
    char str[] = "String written with fputs.\n";
    if (fputs(str, fp) == EOF) {
        perror("Error writing with fputs");
        return -1;
    }

    return 0;
}

int write_character() {
    FILE *fp = open_file_for_writing(FILENAME);
    if (fp == NULL) {
        return -1;
    }

    char ch = '!';
    if (putc(ch, fp) == EOF) {
        perror("Error writing with putc");
        return -1;
    }

    return 0;
}

int write_newline() {
    FILE *fp = open_file_for_writing(FILENAME);
    if (fp == NULL) {
        return -1;
    }

    if (putc('\n', fp) == EOF) {
        perror("Error writing newline with putc");
        return -1;
    }
    return 0;
}

int main(void) {
    write_formatted_number(); 
    write_string();
    write_character();
    write_newline();

    return 0;
}
