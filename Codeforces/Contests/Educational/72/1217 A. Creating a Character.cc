#include <algorithm>
#include <cstdio>
int e, i, s;
int T;

int solve() {
    int diff = std::min(e, std::max(i - s, 0));
    s += diff;
    e -= diff;
    if (s < i) return 0;
    if (s == i) return (e + 1) / 2;
    diff = s - i;
    if (diff > e) return e + 1;
    return e - (e - diff) / 2;
}

int main() {
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        scanf(" %d%d%d", &s, &i, &e);
        printf("%d\n", solve());
    }
    return 0;
}
