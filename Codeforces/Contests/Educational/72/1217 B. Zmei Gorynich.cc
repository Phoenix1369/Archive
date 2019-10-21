#include <algorithm>
#include <cstdio>
int N, T, X;

int solve() {
    int best = 0;
    int maxD = 0;
    for (int i = 0; i < N; ++i) {
        int d, h;
        scanf(" %d%d", &d, &h);
        best = std::max(d - h, best);
        maxD = std::max(d, maxD);
    }
    if (maxD >= X) {
        return 1;
    } else if (best <= 0) {
        return -1;
    }
    return 1 + (X - maxD + best - 1) / best;
}

int main() {
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        scanf(" %d%d", &N, &X);
        printf("%d\n", solve());
    }
    return 0;
}
