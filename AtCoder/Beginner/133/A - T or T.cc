#include <algorithm>
#include <cstdio>
int A, B, N;

int main() {
    scanf(" %d%d%d", &N, &A, &B);
    printf("%d\n", std::min(N * A, B));
    return 0;
}
