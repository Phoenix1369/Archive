#include <cstdio>
#define PROBLEM "class_treasurer"
#define SOLVE
const int MAXN = 1e6+5;
const int MOD = 1e9+7;
int two[MAXN];
char V[MAXN];
int K, N, T;

int solve() {
    // Greedily bribe from the back
    int D = 0;
    int ret = 0;
    for (int i = N; i >= 1; --i) {
        if (V[i] == 'A') {
            if (--D < 0) D = 0;
        } else { // V[i] == 'B'
            if (D >= K) {
                ret = (1LL * two[i] + ret) % MOD;
                if (--D < 0) D = 0;
            } else {
                ++D;
            }
        }
    }
    return ret;
}

void init() {
    two[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        two[i] = 2LL * two[i-1] % MOD;
    }
}

int main() {
#ifndef SOLVE
    freopen(PROBLEM "_sample_input.txt", "r", stdin);
#else
    freopen(PROBLEM ".txt", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);
#endif // SOLVE
    scanf("%d", &T);
    init();
    for (int t = 1; t <= T; ++t) {
        scanf(" %d%d", &N, &K);
        scanf(" %s", V + 1);
        printf("Case #%d: %d\n", t, solve());
    }
    return 0;
}
