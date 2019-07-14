#include <algorithm>
#include <cstdio>
#define PROBLEM "on_the_run"
#define SOLVE
const int MAXN = 305;
int A, B, K, M, N, T;
int p[3];

bool exec(int t) {
    scanf(" %d%d%d", &N, &M, &K);
    for (int i = 0; i <= K; ++i) {
        scanf(" %d%d", &A, &B);
        p[i] = (A + B) & 1;
    }
    if (K == 1) {
        return false;
    }
    return (p[0] == p[1]) && (p[0] == p[2]);
}

int main() {
#ifndef SOLVE
    freopen(PROBLEM "_sample_input.txt", "r", stdin);
#else
    freopen(PROBLEM ".txt", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);
#endif // SOLVE
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: %c\n", t, exec(t) ? 'Y' : 'N');
    }
    return 0;
}
