#include <algorithm>
#include <cstdio>
typedef long long lld;
const int MAXL = 1001;
int cnt[MAXL];
int pre[MAXL];
int L, N;

void init() {
    for (int i = 0; i < MAXL; ++i) {
        cnt[i] = 0;
    }
}

lld solve() {
    pre[0] = cnt[0];
    for (int i = 1; i < MAXL; ++i) {
        pre[i] = pre[i-1] + cnt[i];
    }
    lld sum = 0;
    for (int i = 1; i < MAXL; ++i) {
        if (!cnt[i]) continue;
        for (int j = i; j < MAXL; ++j) {
            if (!cnt[j]) continue;
            int k = std::min(i+j, MAXL) - 1;
            if (i == j) {
                sum += 1LL * cnt[i] * (cnt[j] - 1) / 2 * (pre[k] - pre[j])
                    +  1LL * cnt[i] * (cnt[j] - 1) * (cnt[j] - 2) / 6;
            } else {
                sum += 1LL * cnt[i] * cnt[j] * (pre[k] - pre[j])
                    +  1LL * cnt[i] * cnt[j] * (cnt[j] - 1) / 2;
            }
        }
    }
    return sum;
}

int main() {
    scanf("%d", &N);
    init();
    for (int i = 0; i < N; ++i) {
        scanf("%d", &L);
        ++cnt[L];
    }
    printf("%lld\n", solve());
    return 0;
}
