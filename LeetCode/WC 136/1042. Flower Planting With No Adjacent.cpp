const int MAXC = 5;
typedef vector<int> vin;

class Solution {
    vector<vin> G;
    vin res;

public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        G.clear();
        G.resize(N);
        for (auto e: paths) {
            --e[0], --e[1];
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        res.clear();
        res.resize(N, 0);
        for (int i = 0; i < N; ++i) {
            dfs(i);
        }
        return res;
    }

private:
    void dfs(int cur) {
        if (res[cur]) {
            return;
        }
        bool used[MAXC]{ };
        for (auto nxt: G[cur]) if (res[nxt]) {
            used[res[nxt]] = true;
        }
        for (int i = 1; i < MAXC; ++i) if (!used[i]) {
            res[cur] = i;
            break;
        }
        for (auto nxt: G[cur]) {
            dfs(nxt);
        }
    }
};

