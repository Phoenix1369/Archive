#include <stdlib.h>
#include <string.h>

char** split(char* text, char delim, int* size) {
    int N = 0;
    char** list = malloc(N * sizeof (char *));
    char* ptr = strtok(text, &delim);
    while (ptr != NULL) {
        ++N;
        list = realloc(list, N * sizeof (char *));
        list[N-1] = ptr;
        ptr = strtok(NULL, &delim);
    }
    *size = N;
    return list;
}

struct word get_word(char* text) {
    struct word* w = malloc(sizeof (struct word));
    w->data = text;
    return *w;
}

struct sentence get_sentence(char* text) {
    int N;
    char** token = split(text, ' ', &N);
    struct sentence* sen = malloc(sizeof (struct sentence));
    sen->data = malloc(N * sizeof (struct word));
    sen->word_count = N;
    for (int i = 0; i < N; ++i) {
        sen->data[i] = get_word(token[i]);
    }
    return *sen;
}

struct paragraph get_paragraph(char* text) {
    int N;
    char** token = split(text, '.', &N);
    struct paragraph* par = malloc(sizeof (struct paragraph));
    par->data = malloc(N * sizeof (struct sentence));
    par->sentence_count = N;
    for (int i = 0; i < N; ++i) {
        par->data[i] = get_sentence(token[i]);
    }
    return *par;
}

struct document get_document(char* text) {
    int N;
    char** token = split(text, '\n', &N);
    struct document* doc = malloc(sizeof (struct document));
    doc->data = malloc(N * sizeof (struct paragraph));
    doc->paragraph_count = N;
    for (int i = 0; i < N; ++i) {
        doc->data[i] = get_paragraph(token[i]);
    }
    return *doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(
    struct document Doc, int k, int m, int n
) {
    return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(
    struct document Doc, int k, int m
) {
    return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k-1];
}
