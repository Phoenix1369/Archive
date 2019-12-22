#include <cmath>
#include <cstdio>
typedef long long lld;
lld N;

lld solve() {
    int S = sqrt(N);
    for (int i = S; i >= 1; --i) {
        if ((N % i) != 0) {
            continue;
        }
        lld j = N / i;
        return (i + j - 2);
    }
    return -1;
}

int main() {
    scanf("%lld", &N);
    printf("%lld\n", solve());
    return 0;
}
