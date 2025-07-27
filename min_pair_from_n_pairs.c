#include <stdio.h>
#include <limits.h> // For LLONG_MAX

int main() {
    int T; // Number of test cases
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int n; // Number of pairs to read
        scanf("%d", &n);

        long long int min_c = LLONG_MAX;
        long long int min_m_for_min_c = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            long long int c, m;
            // Read the pair of numbers
            // Added a space before %lld to consume any leftover whitespace, including newlines
            if (scanf(" %lld %lld", &c, &m) != 2) {
                // Handle potential input errors
                fprintf(stderr, "Error reading input for test case %d, pair %d\n", t, i + 1);
                // Depending on requirements, you might want to break or exit
                break; 
            }

            // Check if the current 'c' is smaller than the current minimum 'c'
            if (c < min_c) {
                min_c = c;
                min_m_for_min_c = m;
            } 
            // If 'c' is equal to the current minimum 'c', check if 'm' is smaller
            else if (c == min_c && m < min_m_for_min_c) {
                min_m_for_min_c = m;
            }
        }

        // Print the result for the current test case
        printf("Case %d: %lld %lld\n", t, min_c, min_m_for_min_c);
    }

    return 0;
}
