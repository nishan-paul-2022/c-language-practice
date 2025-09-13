/*
 * Purpose: Find the minimum pair from n pairs of numbers in multiple test cases.
 * Topic: Algorithm for finding lexicographically smallest pair based on first element, with tie-breaking by second element
 */

#include <stdio.h>
#include <limits.h>

int read_pair(long long int *c, long long int *m, int test_case, int pair_num) {
    if (scanf(" %lld %lld", c, m) != 2) {
        fprintf(stderr, "Error reading input for test case %d, pair %d\n", test_case, pair_num);
        return -1;
    }
    return 0;
}

void update_minimum_pair(long long int c, long long int m, 
                        long long int *min_c, long long int *min_m_for_min_c) {
    if (c < *min_c) {
        *min_c = c;
        *min_m_for_min_c = m;
    } 
    else if (c == *min_c && m < *min_m_for_min_c) {
        *min_m_for_min_c = m;
    }
}

void process_test_case(int test_case_num) {
    int n;
    long long int min_c = LLONG_MAX;
    long long int min_m_for_min_c = LLONG_MAX;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        long long int c, m;
        if (read_pair(&c, &m, test_case_num, i + 1) == -1) {
            break;
        }
        update_minimum_pair(c, m, &min_c, &min_m_for_min_c);
    }
    
    printf("Case %d: %lld %lld\n", test_case_num, min_c, min_m_for_min_c);
}

int main(void) {
    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        process_test_case(i);
    }

    return 0;
}
