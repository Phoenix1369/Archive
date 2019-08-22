#include <algorithm>
#include <cstdio>
#include <cstring>
#include <numeric>
const int MAXN = 105;
const int MAXS = 20;
int idx[MAXN];
int  P[MAXN];
char S[MAXN][MAXS];
int N;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf(" %s%d", S[i], &P[i]);
    }
    std::iota(idx, idx+N, 0);
    std::sort(idx, idx+N, [&](int l, int r) {
        int scp = strcmp(S[l], S[r]);
        if (scp != 0) {
            return scp < 0;
        }
        return P[l] > P[r];
    });
    for (int i = 0; i < N; ++i) {
        printf("%d\n", idx[i] + 1);
    }
    return 0;
}
