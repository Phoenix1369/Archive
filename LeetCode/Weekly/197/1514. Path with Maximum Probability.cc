const double EPS = 1e-9;
const int MAXN = 1e4+5;
double D[MAXN];
int M, N;

struct Edge {
    int v;
    double w;
};
vector<Edge> G[MAXN];

struct State {
    int u;
    double d;

    bool operator < (const State& o) const {
        return o.d < d;
    }
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        N = n;
        M = edges.size();
        init();
        for (int i = 0; i < M; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = -log(succProb[i]);
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        return dijkstra(start, end);
    }

private:
    double dijkstra(int src, int snk) {
        priority_queue<State> Q;
        D[src] = 0.0;
        Q.push({src, D[src]});
        while (!Q.empty()) {
            State u = Q.top();
            Q.pop();
            if (u.u == snk) {
                return exp(-D[u.u]);
            }
            if (u.d > D[u.u]) {
                continue;
            }
            for (auto& nxt: G[u.u]) {
                if (D[nxt.v] > D[u.u] + nxt.w) {
                    D[nxt.v] = D[u.u] + nxt.w;
                    Q.push({nxt.v, D[nxt.v]});
                }
            }
        }
        return 0.0;
    }

    void init() {
        for (int i = 0; i < N; ++i) {
            D[i] = N * N;
            G[i].clear();
        }
    }
};
