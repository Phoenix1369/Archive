#include <string.h>

void swap(char** a, char** b) {
    if (*a == *b) return;
    char* tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(char** s, int lo, int hi) {
    while (lo < hi) {
        swap(s + lo, s + hi);
        ++lo;
        --hi;
    }
}

int next_permutation(int n, char **s) {
    int i = n-1;
    while ((i > 0) && (strcmp(s[i-1], s[i]) >= 0)) --i;
    if (i == 0) {
        return 0;
    }
    --i;
    int j = n-1;
    while (strcmp(s[i], s[j]) >= 0) --j;
    swap(s + i, s + j);
    reverse(s, i + 1, n - 1);
    return 1;
}
