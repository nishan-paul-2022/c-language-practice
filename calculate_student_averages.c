/*
 * Purpose: Reads student scores from separate Bangla, Math, and English files,
*          calculates the average score for each student, and writes the
 *          roll number and average to an output file.
 * Topic: File I/O, Data Processing, Basic Arithmetic
 */

#include <stdio.h>
#include <stdlib.h>

// Define input and output filenames
#define BANGLA_FILE "bangla.txt"
#define MATH_FILE "math.txt"
#define ENGLISH_FILE "english.txt"
#define OUTPUT_FILE "FH_average.txt"

int main(void) {
    FILE *file_bangla, *file_math, *file_english, *file_output;
    double average_score;
    int roll_number;
    int bangla_score, math_score, english_score;

    // Open input files
    file_bangla = fopen(BANGLA_FILE, "r");
    if (file_bangla == NULL) {
        perror("Error opening Bangla scores file");
        return EXIT_FAILURE;
    }

    file_math = fopen(MATH_FILE, "r");
    if (file_math == NULL) {
        perror("Error opening Math scores file");
        fclose(file_bangla);
        return EXIT_FAILURE;
    }

    file_english = fopen(ENGLISH_FILE, "r");
    if (file_english == NULL) {
        perror("Error opening English scores file");
        fclose(file_bangla);
        fclose(file_math);
        return EXIT_FAILURE;
    }

    // Open output file
    file_output = fopen(OUTPUT_FILE, "w");
    if (file_output == NULL) {
        perror("Error opening output file");
        fclose(file_bangla);
        fclose(file_math);
        fclose(file_english);
        return EXIT_FAILURE;
    }

    // Read data and calculate averages
    // Loop continues as long as we can read roll and Bangla score
    // Assumes data in all files is synchronized by roll number
    while (fscanf(file_bangla, "%d %d", &roll_number, &bangla_score) == 2) {
        // Read corresponding scores from Math and English files
        if (fscanf(file_math, "%d %d", &roll_number, &math_score) != 2) {
            fprintf(stderr, "Warning: Mismatch or error reading Math score for roll %d. Skipping.\n", roll_number);
            // Attempt to read next line from English to maintain sync
            if (fscanf(file_english, "%d %d", &roll_number, &english_score) != 2) {
                 fprintf(stderr, "Warning: Mismatch or error reading English score for roll %d.\n", roll_number);
            }
            continue; // Skip to next iteration if Math read failed
        }
        if (fscanf(file_english, "%d %d", &roll_number, &english_score) != 2) {
            fprintf(stderr, "Warning: Mismatch or error reading English score for roll %d. Skipping.\n", roll_number);
            continue; // Skip to next iteration if English read failed
        }

        // Calculate average score
        average_score = (double)(bangla_score + math_score + english_score) / 3.0;

        // Print average to console
        printf("Roll: %d, Average: %.2lf\n", roll_number, average_score);

        // Write roll number and average to output file
        if (fprintf(file_output, "%d %.2lf\n", roll_number, average_score) < 0) {
            perror("Error writing to output file");
        }
    }

    // Close all files
    fclose(file_bangla);
    fclose(file_math);
    fclose(file_english);
    fclose(file_output);

    printf("\nAverage calculation complete. Results saved to '%s'.\n", OUTPUT_FILE);

    return 0;
}
