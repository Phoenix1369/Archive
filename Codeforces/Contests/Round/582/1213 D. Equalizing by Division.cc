#include <algorithm>
#include <cstdio>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef std::vector<int> vin;
const int LOGA = 18;
const int MAXA = 2e5+5;
const int MAXN = 2e5+5;
vin B[MAXA];
int A, K, N;

void process(int num) {
    int cnt = 0;
    while (num) {
        B[num].push_back(cnt);
        num /= 2;
        ++cnt;
    }
}

int solve() {
    int ret = LOGA * MAXN;
    for (int i = 1; i < MAXA; ++i) {
        if (B[i].size() < K) {
            continue;
        }
        std::sort(ALL(B[i]));
        int cost = 0;
        for (int j = 0; j < K; ++j) {
            cost += B[i][j];
        }
        ret = std::min(cost, ret);
    }
    return ret;
}

int main() {
    scanf(" %d%d", &N, &K);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A);
        process(A);
    }
    printf("%d\n", solve());
    return 0;
}
