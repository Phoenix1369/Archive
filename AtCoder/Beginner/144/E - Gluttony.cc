#include <algorithm>
#include <cstdio>
#include <functional>
typedef long long lld;
const int MAXN = 2e5+5;
int A[MAXN];
int F[MAXN];
lld K;
int N;

bool f(lld x) {
    lld sum = 0LL;
    for (int i = 0; i < N; ++i) {
        lld prod = 1LL * A[i] * F[i];
        if (prod > x) {
            lld B = x / F[i];
            sum += (A[i] - B);
            if (sum > K) {
                return false;
            }
        }
    }
    return (sum <= K);
}

int main() {
    scanf(" %d%lld", &N, &K);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &F[i]);
    }
    std::sort(A, A+N);
    std::sort(F, F+N, std::greater<int>());
    lld lo = 0;
    lld hi = 0;
    for (int i = 0; i < N; ++i) {
        hi = std::max(1LL * A[i] * F[i], hi);
    }
    while (lo < hi) {
        lld x = (lo + hi) / 2;
        if (f(x)) {
            hi = x;
        } else {
            lo = x + 1;
        }
    }
    printf("%lld\n", lo);
    return 0;
}
