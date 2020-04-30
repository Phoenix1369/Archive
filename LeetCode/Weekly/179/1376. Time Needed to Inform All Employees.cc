const int MAXN = 1e5+5;
vector<int> G[MAXN];
vector<int> T;
int best, N;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        N = n;
        T = move(informTime);
        for (int i = 0; i < n; ++i) G[i].clear();
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) {
                G[manager[i]].push_back(i);
            }
        }
        best = 0;
        dfs(headID, 0);
        return best;
    }

private:
    void dfs(int u, int time) {
        if (G[u].empty()) {
            best = max(time, best);
        }
        time += T[u];
        for (int v: G[u]) {
            dfs(v, time);
        }
    }
};
