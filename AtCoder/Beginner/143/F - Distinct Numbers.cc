#include <cstdio>
typedef long long lld;
const int MAXN = 3e5+5;
int C[MAXN];
lld D[MAXN];
lld pre[MAXN];  // PSA of C ordered by D.
int F[MAXN];
int A, N;

void init() {
    for (int i = 0; i <= N; ++i) {
        C[i] = 0;
        D[i] = 0;
        pre[i] = 0;
    }
}

int main() {
    scanf("%d", &N);
    init();
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &A);
        ++C[A];
    }
    for (int i = 1; i <= N; ++i) {
        ++D[C[i]];
    }
    for (int i = 1; i <= N; ++i) {
        pre[i] = 1LL * i * D[i] + pre[i-1];
        D[i] += D[i-1];
    }
    F[0] = N;
    for (int i = 1; i <= N; ++i) {
        F[i] = (pre[i] + i * (D[N] - D[i])) / i;
    }
    int K = N;
    int t = 1;
    while (K >= 0) {
        while ((t <= N) && (F[K] >= t)) {
            printf("%d\n", K);
            ++t;
        }
        --K;
    }
    return 0;
}
