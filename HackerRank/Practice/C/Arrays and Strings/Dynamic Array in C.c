#include <stdlib.h>

#define books total_number_of_books
#define pages total_number_of_pages

void insert_book(int x, int y) {
    int N = books[x];
    pages[x] = realloc(pages[x], (N+1) * sizeof (int *));
    pages[x][N] = y;
    ++books[x];
}

void init(int N) {
    books = calloc(N, sizeof (int));
    pages = calloc(N, sizeof (int *));
    for (int i = 0; i < N; ++i) {
        pages[i] = malloc(0 * sizeof (int));
    }
}
