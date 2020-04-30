const int MAXN = 105;
const int MAXT = 55;
double P[MAXN];
int T[MAXN];
bool leaf[MAXN];
vector<int> G[MAXN];
int N;

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        for (int i = 1; i <= n; ++i) {
            G[i].clear();
            P[i] = 0.0;
            T[i] = -1;
            leaf[i] = false;
        }
        for (auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        G[1].push_back(1);
        P[1] = 1.0;
        T[1] = 0;
        dfs(1, 0);
        if (T[target] == t) {
            return P[target];
        }
        if (leaf[target] && (t > T[target])) {
            return P[target];
        }
        return 0.0;
    }

private:
    void dfs(int u, int t) {
        if (G[u].size() == 1u) {
            leaf[u] = true;
            return;
        }
        double np = P[u] / (G[u].size() - 1u);
        int nt = t + 1;
        for (int v: G[u]) {
            if (T[v] < 0) {
                P[v] = np;
                T[v] = nt;
                dfs(v, nt);
            }
        }
    }
};
