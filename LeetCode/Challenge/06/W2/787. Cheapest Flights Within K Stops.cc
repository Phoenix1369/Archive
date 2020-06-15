#define CLR(x) memset((x), 0x3f, sizeof (x))
const int INFN = 0x3f3f3f3f;
const int MAXN = 105;
int D[MAXN][MAXN];
int K, N;

struct Edge {
    int v, w;
};
vector<Edge> G[MAXN];

struct State {
    int c, d, u;
    
    bool operator < (const State& o) const {
        return (o.c < c);
    }
};

class Solution {
public:
    int findCheapestPrice(
        int n, vector<vector<int>>& flights, int src, int dst, int k
    ) {
        N = n;
        K = k;
        init();
        for (auto& f: flights) {
            int u = f[0];
            int v = f[1];
            int w = f[2];
            G[u].push_back({v, w});
        }
        return dijkstra(src, dst);
    }

private:
    int dijkstra(int a, int b) {
        priority_queue<State> Q;
        State src = {0, 0, a};
        D[src.u][src.d] = src.c;
        Q.push(src);
        while (!Q.empty()) {
            State u = Q.top();
            Q.pop();
            if ((u.d > K) || (u.c > D[u.u][u.d])) {
                continue;
            }
            for (const auto& nxt: G[u.u]) {
                State v = {u.c + nxt.w, u.d + 1, nxt.v};
                if (v.c >= D[v.u][v.d]) {
                    continue;
                }
                D[v.u][v.d] = v.c;
                Q.push(v);
            }
        }
        int ret = *min_element(D[b], D[b] + (K+1) + 1);
        return (ret != INFN) ? ret : -1;
    }

    void init() {
        CLR(D);
        for (int i = 0; i < N; ++i) {
            G[i].clear();
        }
    }
};
