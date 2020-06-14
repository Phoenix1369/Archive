#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLR(x) memset((x), 0, sizeof (x))
#define MAXA 26

typedef int (*compare)(const char*, const char*);

int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int sa[MAXA];
    int sb[MAXA];
    CLR(sa);
    CLR(sb);
    for (const char *ptr = a; *ptr; ++ptr) sa[*ptr-'a'] = 1;
    for (const char *ptr = b; *ptr; ++ptr) sb[*ptr-'a'] = 1;
    int ca = 0;
    int cb = 0;
    for (int i = 0; i < MAXA; ++i) {
        ca += sa[i];
        cb += sb[i];
    }
    if (ca != cb) {
        return (ca < cb) ? -1 : +1;
    }
    return strcmp(a, b);
}

int sort_by_length(const char* a, const char* b) {
    int la = strlen(a);
    int lb = strlen(b);
    if (la != lb) {
        return (la < lb) ? -1 : +1;
    }
    return strcmp(a, b);
}

void merge(char** la, int ls, char** ra, int rs, compare cmp) {
    int sz = ls + rs;
    char** head = la;
    char** out = malloc(sz * sizeof (char *));
    int i=0, j=0, k=0;
    while ((i < ls) && (j < rs)) {
        if (cmp(la[i], ra[j]) <= 0) {
            out[k++] = la[i++];
        } else {
            out[k++] = ra[j++];
        }
    }
    while (i < ls) out[k++] = la[i++];
    while (j < rs) out[k++] = ra[j++];
    memcpy(head, out, sz * sizeof (char *));
}

void merge_sort(char** arr, int len, compare cmp) {
    if (len <= 1) return;
    int mid = len / 2;
    merge_sort(arr, mid, cmp);
    merge_sort(arr+mid, len-mid, cmp);
    merge(arr, mid, arr+mid, len-mid, cmp);
}

void string_sort(char** arr, const int len, compare cmp_func) {
    merge_sort(arr, len, cmp_func);
}
