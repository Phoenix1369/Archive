#include <cstdio>
constexpr int MOD = 1e9+7;
int K, M, N;

constexpr int fpm(int base, int index) {
    int power = 1;
    while (index) {
        if (index & 1) {
            power = 1LL * base * power % MOD;
        }
        base = 1LL * base * base % MOD;
        index >>= 1;
    }
    return power;
}
constexpr int inv2 = fpm(2, MOD-2);

int ncr(int r) {
    // (N x M - 2) choose (K - 2)
    int n = (1LL * N * M % MOD + MOD - 2) % MOD;
    int c = 1;
    for (int i = 1; i <= r; ++i) {
        c = 1LL * c * (n - (i - 1)) % MOD * fpm(i, MOD-2) % MOD;
    }
    return c;
}

int sum(int n) { return 1LL * n * (n + 1) % MOD * inv2 % MOD; }

int main() {
    scanf(" %d%d%d", &N, &M, &K);
    int ret = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int b = N-i;
            ret = (1LL * sum(M-j-1) * b % MOD + ret) % MOD; // Forwards (>= i)
            ret = (1LL * sum(j) * (b-1) % MOD + ret) % MOD; // Backwards (> i)
            ret = (1LL * sum(b - 1) * M % MOD + ret) % MOD; // Downwards (all)
        }
    }
    ret = 1LL * ret * ncr(K-2) % MOD;
    printf("%d\n", ret);
    return 0;
}
