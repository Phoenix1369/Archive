#define ALL(x) (x).begin(), (x).end()

template <typename T>
using vec = vector<T>;

const int MAXW = 1005;
int M, N;

namespace {
// Union-Find (Disjoint Set)
vec<int> dsu;

void clear() {
    dsu.assign(N, 0);
    iota(ALL(dsu), 0);
}

int find(int p) {
    int q = p;
    while (q != dsu[q]) {
        q = dsu[q];
    }
    while (p != q) {
        int r = dsu[p];
        dsu[p] = q;
        p = r;
    }
    return p;
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
        return false;
    }
    dsu[a] = b;
    return true;
}
}   // end namespace

struct Edge {
    int u, v, i;

    bool bridge() const {
        return find(u) != find(v);
    }
};
vec<Edge> E[MAXW];

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n, vector<vector<int>>& edges
    ) {
        N = n;
        M = edges.size();
        init();
        for (int i = 0; i < M; ++i) {
            auto& e = edges[i];
            int u = e[0];
            int v = e[1];
            int w = e[2];
            E[w].push_back({u, v, i});
        }
        int K = filter_edges();
        return solve(K);
    }

private:
    int filter_edges() {
        int mst = 0;
        for (int w = 1; w < MAXW; ++w) {
            vec<Edge> keep;
            for (auto& e: E[w]) {
                if (e.bridge()) {
                    keep.push_back(move(e));
                }
            }
            E[w] = move(keep);
            for (auto& e: E[w]) {
                if (unite(e.u, e.v)) {
                    mst += w;
                }
            }
        }
        return mst;
    }

    void init() {
        for (int i = 1; i < MAXW; ++i) {
            E[i].clear();
        }
        clear();
    }

    int kruskal(int skip) {
        int mst = 0;
        clear();
        for (int w = 1; w < MAXW; ++w) {
            for (auto& e: E[w]) {
                if (e.i == skip) {
                    continue;
                }
                if (unite(e.u, e.v)) {
                    mst += w;
                }
            }
        }
        return mst;
    }

    vec<vec<int>> solve(int K) {
        vec<int> crit;
        vec<int> sudo;
        for (int w = 1; w < MAXW; ++w) {
            for (auto& e: E[w]) {
                int K2 = kruskal(e.i);
                if ((K2 > K) || e.bridge()) {
                    crit.push_back(e.i);
                } else {
                    sudo.push_back(e.i);
                }
            }
        }
        return {crit, sudo};
    }
};
