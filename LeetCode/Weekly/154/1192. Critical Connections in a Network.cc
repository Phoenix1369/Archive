const int MAXN = 1e5+5;
const int NOPE = -1;
const int ROOT = 0;
typedef vector<int> vin;
vector<vin> ret;
int dfsid[MAXN];
int dfslo[MAXN];
vin G[MAXN];
int up[MAXN];
int dfscnt;
int N;

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        N = n;
        init();
        for (auto edge: connections) {
            int u = edge[0];
            int v = edge[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        up[ROOT] = ROOT;
        dfs(ROOT);
        return ret;
    }
    
private:
    void dfs(int cur) {       
        dfsid[cur] = dfscnt++;
        dfslo[cur] = dfsid[cur];
        int w = dfslo[cur];
        for (auto nxt: G[cur]) {
            if (dfslo[nxt] == NOPE) {
                up[nxt] = cur;
                dfs(nxt);
                if (dfslo[nxt] > dfslo[cur]) {
                    ret.push_back({cur, nxt});
                }
                w = min(dfslo[nxt], w);
            } else if (nxt != up[cur]) {
                w = min(dfslo[nxt], w);
            }
        }
        dfslo[cur] = w;
    }
    
    void init() {
        dfscnt = 0;
        for (int i = 0; i < N; ++i) {
            dfsid[i] = NOPE;
            dfslo[i] = NOPE;
            G[i].clear();
            up[i] = NOPE;
        }
        ret.clear();
    }
};
