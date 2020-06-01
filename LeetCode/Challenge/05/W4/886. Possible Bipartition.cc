const int MAXN = 2005;
vector<int> G[MAXN];
int C[MAXN];

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        for (int i = 1; i <= N; ++i) {
            G[i].clear();
            C[i] = 0;
        }
        for (auto& e: dislikes) {
            int u = e[0];
            int v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for (int i = 1; i <= N; ++i) {
            if (C[i]) continue;
            C[i] = 1;
            if (!dfs(i)) {
                return false;
            }
        }
        return true;
    }

private:
    bool dfs(int u) {
        for (auto v: G[u]) {
            if (C[v] == C[u]) return false;
            if (C[v]) continue;
            C[v] = C[u] * -1;
            if (!dfs(v)) {
                return false;
            }
        }
        return true;
    }
};
