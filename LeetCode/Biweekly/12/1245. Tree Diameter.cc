const int MAXN = 1e4+5;
const int NOPE = -1;
int dist[MAXN];
std::vector<int> G[MAXN];
int root;
int N;

class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        N = edges.size() + 1;
        init();

        for (auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }

        root = 1;
        reset();
        dfs(root);
        reset();
        dfs(root);
        return dist[root];
    }

private:
    void dfs(int cur) {
        for (int nxt: G[cur]) {
            if (dist[nxt] != NOPE) {
                continue;
            }
            dist[nxt] = dist[cur] + 1;
            dfs(nxt);
        }
        if (dist[cur] > dist[root]) {
            root = cur;
        }
    }

    void init() {
        for (int i = 0; i < N; ++i) {
            dist[i] = 0;
            G[i].clear();
        }
    }

    void reset() {
        for (int i = 0; i < N; ++i) {
            dist[i] = NOPE;
        }
        dist[root] = 0;
    }
};
