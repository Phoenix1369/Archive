#include <algorithm>
#include <cstdio>
#include <numeric>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef long long lld;
const int MAXM = 2e5+5;
int I[MAXM];
int Q[MAXM];
lld R[MAXM];
int M, N;
int cnt;

struct Edge {
    int u, v, w;
    bool operator < (const Edge& o) const {
        return w < o.w;
    }
};
std::vector<Edge> E;

struct DisjointSet {
    int P[MAXM];
    int S[MAXM];
    lld pairs;

    void init() {
        std::iota(P+1, P+N+1, 1);
        std::fill(S+1, S+N+1, 1);
        pairs = 0LL;
    }

    int find(int x) {
        int y = x;
        while (P[y] != y) {
            y = P[y];
        }
        while (x != y) {
            int z = P[x];
            P[x] = y;
            x = z;
        }
        return x;
    }

    void unite(Edge e) {
        e.u = find(e.u);
        e.v = find(e.v);
        if (e.u != e.v) {
            pairs += 1LL * S[e.u] * S[e.v];
            if (S[e.u] < S[e.v]) {
                std::swap(e.u, e.v);
            }
            S[P[e.u]] += S[P[e.v]];
            P[e.v] = P[e.u];
        }   // Merge small v -> large u
    }
} dsu;

void solve() {
    std::sort(ALL(E));
    std::iota(I, I + M, 0);
    std::sort(I, I + M, [&](int i, int j) {
        return Q[i] < Q[j];
    });

    unsigned cur = 0u;
    dsu.init();
    for (int i = 0; i < M; ++i) {
        int j = I[i];
        while ((cur < E.size()) && (E[cur].w <= Q[j])) {
            dsu.unite(E[cur]);
            ++cur;
        }
        R[j] = dsu.pairs;
    }
}

int main() {
    scanf(" %d%d", &N, &M);
    for (int i = 1; i < N; ++i) {
        int u, v, w;
        scanf(" %d%d%d", &u, &v, &w);
        E.push_back({u, v, w});
    }
    for (int i = 0; i < M; ++i) {
        scanf("%d", &Q[i]);
    }
    solve();
    for (int i = 0; i < M; ++i) {
        printf("%lld ", R[i]);
    }
    return 0;
}
