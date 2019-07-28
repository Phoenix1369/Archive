#include <algorithm>
#include <cstdio>

int main() {
    int M, N;
    scanf(" %d%d", &N, &M);
    int a = 1, b = N;
    for (int i = 0; i < M; ++i) {
        int L, R;
        scanf(" %d%d", &L, &R);
        a = std::max(L, a);
        b = std::min(R, b);
    }
    printf("%d\n", std::max(b - a + 1, 0));
    return 0;
}
