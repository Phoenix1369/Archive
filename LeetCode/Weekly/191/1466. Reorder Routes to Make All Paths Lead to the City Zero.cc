const int MAXN = 5e4+5;
bool seen[MAXN];
int N, ret;

struct Edge {
    int v, w;
};
vector<Edge> G[MAXN];

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        N = n;
        for (int i = 0; i < N; ++i) {
            G[i].clear();
            seen[i] = false;
        }
        for (auto& e: connections) {
            int u = e[0];
            int v = e[1];
            G[u].push_back({v, 1});
            G[v].push_back({u, 0});
        }
        ret = 0;
        dfs(0);
        return ret;
    }

private:
    void dfs(int u) {
        seen[u] = true;
        for (auto& nxt: G[u]) {
            if (seen[nxt.v]) continue;
            ret += nxt.w;
            dfs(nxt.v);
        }
    }
};
