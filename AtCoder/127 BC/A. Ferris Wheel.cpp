#include <cstdio>

int main() {
    int A, B;
    scanf(" %d%d", &A, &B);
    printf("%d\n", (A >= 13) ? B : (A >= 6) ? (B / 2) : 0);
    return 0;
}
