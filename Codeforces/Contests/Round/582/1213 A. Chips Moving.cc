#include <algorithm>
#include <cstdio>
const int MAXC = 2;
int cnt[MAXC]{ };
int N, x;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &x);
        ++cnt[x & 1];
    }
    printf("%d\n", *std::min_element(cnt, cnt + MAXC));
    return 0;
}
