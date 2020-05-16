const int MAXN = 1e5+5;
vector<int> G[MAXN];
vector<bool> leaf;
bool seen[MAXN];
int N, ret;

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        N = n;
        leaf = move(hasApple);
        init();
        for (auto e: edges) {
            int u = e[0];
            int v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(0);
        return ret;
    }

private:
    bool dfs(int u) {
        if (seen[u]) {
            return false;
        }
        seen[u] = true;
        for (int v: G[u]) {
            if (dfs(v)) {
                ret += 2;
                leaf[u] = true;
            }
        }
        return leaf[u];
    }
    
    void init() {
        for (int i = 0; i < N; ++i) {
            G[i].clear();
            seen[i] = false;
        }
        ret = 0;
    }
};
