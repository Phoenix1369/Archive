#include <cstdio>
#include <cstring>
const int MAXS = 2e5+5;
char S[MAXS];
int  Z[MAXS];
int N, T;

void count_zeroes() {
    Z[0] = 0;
    for (int i = 1; i <= N; ++i) {
        if (S[i] == '0') {
            Z[i] = Z[i-1] + 1;
        } else {
            Z[i] = 0;
        }
    }
}

int size(int num) {
    int cnt = 0;
    while (num) {
        num >>= 1;
        ++cnt;
    }
    return cnt;
}

int solve() {
    int K = size(N);
    int ret = 0;
    for (int k = 1; k <= K; ++k) {
        int mask = (1 << k) - 1;
        int sub = 0;
        for (int i = 1; i <= N; ++i) {
            sub <<= 1;
            sub |= (S[i] - '0');
            sub &= mask;
            if (i < k) continue;
            if (sub == k) {
                ++ret;
            } else if ((sub > K) && (k == K) && (sub <= k + Z[i-k])) {
                ++ret;
            }
        }
    }
    return ret;
}

int main() {
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        scanf("%s", S+1);
        N = strlen(S+1);
        count_zeroes();
        printf("%d\n", solve());
    }
    return 0;
}
