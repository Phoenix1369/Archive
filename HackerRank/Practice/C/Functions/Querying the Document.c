#include <stdlib.h>
#include <string.h>

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {
    return kth_paragraph(document, m)[k-1];
}

char* kth_word_in_mth_sentence_of_nth_paragraph(
    char**** document, int k, int m, int n
) {
    return kth_sentence_in_mth_paragraph(document, m, n)[k-1];
}

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

char** get_sentence(char* text) {
    int N;
    char** sentence = split(text, ' ', &N);
    return sentence;
}

char*** get_paragraph(char* text) {
    int N;
    char** token = split(text, '.', &N);
    char*** paragraph = (char ***)malloc(N * sizeof (char **));
    for (int i = 0; i < N; ++i) {
        paragraph[i] = get_sentence(token[i]);
    }
    return paragraph;
}

char**** get_document(char* text) {
    int N;
    char** token = split(text, '\n', &N);
    char**** document = (char ****)malloc(N * sizeof (char ***));
    for (int i = 0; i < N; ++i) {
        document[i] = get_paragraph(token[i]);
    }
    return document;
}
