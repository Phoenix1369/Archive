#include <algorithm>
#include <cstdio>
#include <map>
const int MAXN = 2e5+5;
const int MAXQ = 2e5+5;
int pos[MAXQ], R[MAXN];
int S[MAXN], T[MAXN], X[MAXN];  // Roadblocks
std::map<int,int> D;
int N, Q;

// R^2 with roadblocks = vertical lines
// People all have unit slope: y = x + D[i]

int main() {
    scanf(" %d%d", &N, &Q);
    for (int i = 0; i < N; ++i) {
        scanf(" %d%d%d", &S[i], &T[i], &X[i]);
        R[i] = i;
    }
    std::sort(R, R + N, [](int l, int r) {
        return X[l] != X[r] ? X[l] < X[r] : S[l] < S[r];
    });
    for (int i = 0; i < Q; ++i) {
        int d;
        scanf("%d", &d);
        D[d] = i;
        pos[i] = -1;
    }
    for (int i = 0; i < N; ++i) {
        auto lo = D.lower_bound(S[R[i]] - X[R[i]]);
        auto hi = D.lower_bound(T[R[i]] - X[R[i]]);
        for (auto jtr = lo; jtr != hi;) {
            pos[jtr->second] = X[R[i]];
            jtr = D.erase(jtr);
        }
    }
    for (int i = 0; i < Q; ++i) {
        printf("%d\n", pos[i]);
    }
    return 0;
}
