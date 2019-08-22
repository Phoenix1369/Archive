#include <cstdio>
const int MAXM = 10;
int P[MAXM], S[MAXM];
int M, N;

int bitcount_mod2(int n) {
    return n ? __builtin_popcount(n) & 1 : 0;
}

bool good(int mask) {
    for (int i = 0; i < M; ++i) {
        if (bitcount_mod2(mask & S[i]) != P[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    scanf(" %d%d", &N, &M);
    for (int i = 0; i < M; ++i) {
        int K, s;
        S[i] = 0;
        scanf("%d", &K);
        for (int j = 0; j < K; ++j) {
            scanf("%d", &s);
            S[i] |= 1 << (s-1);
        }
    }
    for (int i = 0; i < M; ++i) {
        scanf("%d", &P[i]);
        P[i] &= 1;
    }
    int L = 1 << N;
    int ret = 0;
    for (int mask = 0; mask < L; ++mask) {
        if (good(mask)) ++ret;
    }
    printf("%d\n", ret);
    return 0;
}
