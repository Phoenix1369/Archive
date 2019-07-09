#include <algorithm>
#include <cstdio>
const int MOD = 2019;
int L, R;

int solve() {
    if (R - L + 1 >= MOD) {
        return 0;
    }
    int ret = MOD;
    for (int i = L; i < R; ++i) {
        for (int j = L+1; j <= R; ++j) {
            int tmp = 1LL * i * j % MOD;
            ret = std::min(tmp, ret);
        }
    }
    return ret;
}

int main() {
    scanf(" %d%d", &L, &R);
    printf("%d\n", solve());
    return 0;
}
