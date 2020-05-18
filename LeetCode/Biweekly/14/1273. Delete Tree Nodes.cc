const int MAXN = 1e4+5;
vector<int> G[MAXN];
vector<int> S;
vector<int> V;
int N, ret;

class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int> parent, vector<int> value) {
        N = nodes;
        V = move(value);
        init();
        for (int i = 1; i < N; ++i) {
            G[parent[i]].push_back(i);
        }
        ret = N;
        dfs(0);
        return ret;
    }

private:
    void dfs(int u) {
        for (int v: G[u]) {
            dfs(v);
            S[u] += S[v];
            V[u] += V[v];
        }
        if (!V[u]) {
            ret -= S[u];
            S[u] = 0;
        }
    }
    
    void init() {
        S.assign(N, 1);
        for (int i = 0; i < N; ++i) {
            G[i].clear();
        }
    }
};
