#include <stdbool.h>
#include <stdio.h>
#include "cima.h"

#define MAX_LENGTH 10
#define N_TESTCASES_TIENE_CIMA 10
#define N_TESTCASES_CIMA 10

void test_tiene_cima(void);
void test_cima(void);

int main() {
    test_tiene_cima();
    test_cima();

    return 0;
}

void test_tiene_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        bool result;
    };

    struct testcase tests[N_TESTCASES_TIENE_CIMA] = {
      { {8}, 1, false },
      { {2,9,1}, 3, true},
      { {4,2,3}, 3, false},
      { {4,2,9}, 3, false},
      { {10, 11, 12, 9, 8}, 5, true},
      { {0, 2, 9, 8, 10}, 5, false},
      { {4, 5, 2}, 3, true},
      { {2, 9, 2}, 3, true},
      { {9,10}, 2, false},
      { {6, 5}, 2, false},
    };
    bool result;

    printf("TESTING tiene_cima\n");

    for (int i=0; i < N_TESTCASES_TIENE_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = tiene_cima(tests[i].a, tests[i].length);

        if (result != tests[i].result) {
            printf("FAILED\n");
        } else {
            printf("OK\n");
        }
    }
}

void test_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        int result;
    };

    struct testcase tests[N_TESTCASES_CIMA] = {
        { {8}, 1, 0 },
        { {2, 4}, 2, 1},
        { {10, 12, 13, 5, 4}, 5, 2},
        { {2, 4, 1}, 3, 1},
        { {8, 10, 11, 12, 7}, 5, 3},
        { {10, 14, 13}, 3, 1},
        { {14}, 1, 0},
        { {1, 2, 1}, 3, 1},
        { {1, 3, 1}, 3, 1},
        { {1, 3, 5, 7, 2}, 5, 3},

        // COMPLETAR!!

    };
    int result;

    printf("TESTING cima\n");

    for (int i=0; i < N_TESTCASES_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = cima(tests[i].a, tests[i].length);

        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED. got %d expected %d\n", result, tests[i].result);
        }
    }
}
