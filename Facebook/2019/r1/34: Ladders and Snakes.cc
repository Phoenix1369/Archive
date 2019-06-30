#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#define MEM(x, y) memset((x), (y), sizeof(x))
#define PROBLEM "ladders_and_snakes"
#define SOLVE
const int INFN = 2.5e8 + 5;
const int MAXN = 55;
const int MX2N = MAXN << 1;
const int MAXG = MAXN + MAXN*MAXN + 5;  // ladders + split-edge + src + snk
int cur[MX2N], prv[MX2N];   // intervals
std::set<int> cY;
int H, N, T;

struct Ladder {
    int X, A, B;

    bool operator < (const Ladder& other) const {
        return (X != other.X) ? (X < other.X) : (A < other.A);
    }
} L[MAXN];
int adj[MX2N];  // Immediately adjacent ladders

// Maximum Flow: Dinic's Algorithm
const int SRC = 0;
const int SNK = MAXG - 1;

struct Edge {
    int to, rel, f, cap;
};  // rel: index of reverse-edge
std::vector<Edge> graph[MAXG];

int dist[MAXG]; // BFS Layering
int gptr[MAXG]; // Graph Pointers
int queu[MAXG]; // BFS Queue
int qh, qt;

void add_edge(int u, int v, int cap) {
    int szu = graph[u].size();
    int szv = graph[v].size();
    Edge u_v = { v, szv, 0, cap};
    Edge v_u = { u, szu, cap, cap};
    graph[u].push_back(u_v);
    graph[v].push_back(v_u);
}

bool bfs() {
    // Exists residual path from src to snk.
    MEM(dist, -1);
    dist[SRC] = 0;

    qh = qt = 0;
    queu[qt++] = SRC;
    while (qh < qt) {
        int cur = queu[qh++];
        for (auto& nxt: graph[cur]) {
            if ((dist[nxt.to] == -1) && (nxt.f < nxt.cap)) {
                dist[nxt.to] = dist[cur] + 1;
                queu[qt++] = nxt.to;
            }
        }
    }
    return (dist[SNK] != -1);
}

int dfs(int cur, int flow) {
    // Augments flow towards snk
    if (cur == SNK) {
        return flow;
    }
    int len = graph[cur].size();
    for (int& i = gptr[cur]; i < len; ++i) {
        Edge& nxt = graph[cur][i];
        if (nxt.f >= nxt.cap) {
            continue;
        }
        if (dist[nxt.to] == dist[cur] + 1) {
            // Follow BFS shortest path
            int diff = dfs(nxt.to, std::min(flow, nxt.cap - nxt.f));
            if (diff <= 0) {
                continue;
            }
            nxt.f += diff;
            graph[nxt.to][nxt.rel].f -= diff;
            return diff;
        }
    }
    return 0;
}

int dinics() {
    if (!bfs()) {
        return 0;
    }
    int flow = 0;
    do {
        MEM(gptr, 0);
        while (int res = dfs(SRC, INFN)) {
            flow += res;
        }
    } while (bfs());

    if (flow >= INFN) {
        return -1;
    }
    return flow;
}

int solve() {
    // Coordinate compression
    int K = 0;
    for (auto& itr: cY) {
        if (K) {
            cur[K-1] = itr;
        }
        prv[K++] = itr;
    }

    // Build flow network
    int P = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < K; ++j) {
            if ((L[i].A <= prv[j]) && (cur[j] <= L[i].B)) {
                if (adj[j] != -1) {
                    int u = adj[j];
                    int v = i;
                    int weight = std::min(cur[j], H-1) - std::max(prv[j], 1);
                    if (weight > 0) {
                        add_edge(u, v, weight);
                        // Anti-parallel Edges!
                        // Split one direction across a dummy node.
                        ++P;
                        add_edge(v, N + P, weight);
                        add_edge(N + P, u, weight);
                    }
                    // Ignore zero-width edges: may be freely blocked.
                }
                adj[j] = i;
            }
        }
        if (L[i].A == 0) {
            add_edge(SRC, i, INFN);
        }
        if (L[i].B == H) {
            add_edge(i, SNK, INFN);
        }
    }
    return dinics();
}

void init() {
    cY.clear();
    cY.insert(0);
    cY.insert(H);
    for (int i = 0; i < MX2N; ++i) {
        adj[i] = -1;
    }
    for (int i = 0; i < MAXG; ++i) {
        graph[i].clear();
    }
}

int main() {
#ifndef SOLVE
    freopen(PROBLEM "_sample_input.txt", "r", stdin);
#else
    freopen(PROBLEM ".txt", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);
#endif // SOLVE
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf(" %d%d", &N, &H);
        init();
        for (int i = 1; i <= N; ++i) {
            scanf(" %d%d%d", &L[i].X, &L[i].A, &L[i].B);
            cY.insert(L[i].A);
            cY.insert(L[i].B);
        }
        std::sort(L+1, L+N+1);
        printf("Case #%d: %d\n", t, solve());
    }
    return 0;
}
