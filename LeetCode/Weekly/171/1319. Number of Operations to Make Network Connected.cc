const int MAXN = 1e5+5;
const int NOPE = -1;
vector<int> G[MAXN];
bool seen[MAXN];
int K, M, N;
int ret;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        N = n;
        M = connections.size();
        if (M < N-1) {
            return NOPE;
        }
        init();
        for (auto& e: connections) {
            int u = e[0];
            int v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for (int i = 0; i < N; ++i) {
            if (seen[i]) continue;
            dfs(i);
            ++ret;
        }
        --ret;
        return ret;
    }

private:
    void dfs(int cur) {
        if (seen[cur]) return;
        seen[cur] = true;
        for (int nxt: G[cur]) {
            dfs(nxt);
        }
    }
    
    void init() {
        K = 0;
        ret = 0;
        for (int i = 0; i < N; ++i) {
            G[i].clear();
            seen[i] = false;
        }
    }
};

/*
4
[[0,1],[0,2],[1,2]]
6
[[0,1],[0,2],[0,3],[1,2],[1,3]]
6
[[0,1],[0,2],[0,3],[1,2]]
5
[[0,1],[0,2],[3,4],[2,3]]
>> 1
>> 2
>> -1
>> 0
*/
