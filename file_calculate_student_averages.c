/*
 * Purpose: Reads student scores from separate Bangla, Math, and English files,
 *          calculates the average score for each student, and writes the
 *          roll number and average to an result file.
 * Topic: File I/O, Data Processing, Basic Arithmetic
 */

#include <stdio.h>
#include <stdlib.h>

#define BANGLA_FILE "files/file_calculate_student_averages_bangla.txt"
#define MATH_FILE "files/file_calculate_student_averages_math.txt"
#define ENGLISH_FILE "files/file_calculate_student_averages_english.txt"
#define RESULT_FILE "files/file_calculate_student_averages_result.txt"

FILE* open_file(const char* filename, const char* mode, const char* description) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        fprintf(stderr, "Error opening %s file\n", description);
        perror(filename);
    }
    return file;
}

void close_all_files(FILE *bangla, FILE *math, FILE *english, FILE *result) {
    if (bangla) {
        fclose(bangla);
    }
    if (math) {
        fclose(math);
    }
    if (english) {
        fclose(english);
    }
    if (result) {
        fclose(result);
    }
}

float calculate_average(int bangla_score, int math_score, int english_score) {
    float average = (bangla_score + math_score + english_score) / 3.0;
    return average;
}

int read_score(FILE *file, int *roll_number, int *score, const char* subject) {
    if (fscanf(file, "%d %d", roll_number, score) == -1) {
        return -1;
    }
    return 0;
}

int write_result(FILE *result_file, int roll_number, float average_score) {
    if (fprintf(result_file, "%d %.2f\n", roll_number, average_score) == -1) {
        perror("Error writing to result file");
        return -1;
    }
    return 0;
}

void display_result(int roll_number, float average_score) {
    printf("Roll: %d, Average: %.2f\n", roll_number, average_score);
}

int process_student_scores(FILE *file_bangla, FILE *file_math, FILE *file_english, FILE *file_result) {
    int valid = 0;
    int roll_number, bangla_score, math_score, english_score;
    
    while (1) {
        int check_bangla = read_score(file_bangla, &roll_number, &bangla_score, "Bangla");
        int check_math = read_score(file_math, &roll_number, &math_score, "Math");
        int check_english = read_score(file_english, &roll_number, &english_score, "English");

        if (check_bangla == -1 || check_math == -1 || check_english == -1) {
            break;
        }
        
        float average_score = calculate_average(bangla_score, math_score, english_score);
        int check_result = write_result(file_result, roll_number, average_score);

        display_result(roll_number, average_score);
    }
    
    return 0;
}

int open_all_files(FILE **bangla, FILE **math, FILE **english, FILE **result) {
    *bangla = open_file(BANGLA_FILE, "r", "Bangla scores");
    if (*bangla == NULL) {
        return -1;
    }

    *math = open_file(MATH_FILE, "r", "Math scores");
    if (*math == NULL) {
        close_all_files(*bangla, NULL, NULL, NULL);
        return -1;
    }

    *english = open_file(ENGLISH_FILE, "r", "English scores");
    if (*english == NULL) {
        close_all_files(*bangla, *math, NULL, NULL);
        return -1;
    }

    *result = open_file(RESULT_FILE, "w", "result");
    if (*result == NULL) {
        close_all_files(*bangla, *math, *english, NULL);
        return -1;
    }
    
    return 0;
}

int main(void) {
    FILE *file_bangla, *file_math, *file_english, *file_result;

    if (open_all_files(&file_bangla, &file_math, &file_english, &file_result) == -1) {
        return 0;
    }

    process_student_scores(file_bangla, file_math, file_english, file_result);

    close_all_files(file_bangla, file_math, file_english, file_result);

    printf("\nAverage calculation complete. Results saved to '%s'.\n", RESULT_FILE);

    return 0;
}
