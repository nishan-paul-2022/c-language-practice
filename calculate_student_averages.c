/*
 * Purpose: Reads student scores from separate Bangla, Math, and English files,
 *          calculates the average score for each student, and writes the
 *          roll number and average to an output file.
 * Topic: File I/O, Data Processing, Basic Arithmetic
 */

#include <stdio.h>
#include <stdlib.h>

#define BANGLA_FILE "files/03-bangla.txt"
#define MATH_FILE "files/03-math.txt"
#define ENGLISH_FILE "files/03-english.txt"
#define OUTPUT_FILE "files/03-output.txt"

int main(void) {
    FILE *file_bangla = fopen(BANGLA_FILE, "r");
    if (file_bangla == NULL) {
        perror("Error opening Bangla scores file");
        return 0;
    }

    FILE *file_math = fopen(MATH_FILE, "r");
    if (file_math == NULL) {
        perror("Error opening Math scores file");
        fclose(file_bangla);
        return 0;
    }

    FILE *file_english = fopen(ENGLISH_FILE, "r");
    if (file_english == NULL) {
        perror("Error opening English scores file");
        fclose(file_bangla);
        fclose(file_math);
        return 0;
    }

    FILE *file_output = fopen(OUTPUT_FILE, "w");
    if (file_output == NULL) {
        perror("Error opening output file");
        fclose(file_bangla);
        fclose(file_math);
        fclose(file_english);
        return 0;
    }

    // Read data and calculate averages
    int roll_number, bangla_score, math_score, english_score;
    while (fscanf(file_bangla, "%d %d", &roll_number, &bangla_score) == 2) {  // Read Bangla scores
        // Read corresponding scores from Math and English files
        if (fscanf(file_math, "%d %d", &roll_number, &math_score) != 2) {  // Read Math scores
            fprintf(stderr, "Warning: Mismatch or error reading Math score for roll %d. Skipping.\n", roll_number);
            // Attempt to read next line from English to maintain sync
            if (fscanf(file_english, "%d %d", &roll_number, &english_score) != 2) {
                 fprintf(stderr, "Warning: Mismatch or error reading English score for roll %d.\n", roll_number);
            }
            continue; // Skip to next iteration if Math read failed
        }
        if (fscanf(file_english, "%d %d", &roll_number, &english_score) != 2) {  // Read English scores
            fprintf(stderr, "Warning: Mismatch or error reading English score for roll %d. Skipping.\n", roll_number);
            continue; // Skip to next iteration if English read failed
        }

        // Calculate average score
        double average_score = (double)(bangla_score + math_score + english_score) / 3.0;

        // Print average to console
        printf("Roll: %d, Average: %.2lf\n", roll_number, average_score);

        // Write roll number and average to output file
        if (fprintf(file_output, "%d %.2lf\n", roll_number, average_score) < 0) {  // Write to output file
            perror("Error writing to output file");
        }
    }

    fclose(file_bangla);
    fclose(file_math);
    fclose(file_english);
    fclose(file_output);

    printf("\nAverage calculation complete. Results saved to '%s'.\n", OUTPUT_FILE);

    return 0;
}
