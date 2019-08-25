#define X first
#define Y second
const int INFN = 1e9+7;
const int MAXN = 1e4+5;
typedef pair<int,int> pii;
typedef vector<pii> vii;
bool seen[MAXN];
int E[MAXN];
vii G[MAXN];

class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        for (int i = 0; i <= n; ++i) {
            G[i].clear();
            seen[i] = false;
        }
        priority_queue<pii, vii, greater<pii>> pq;
        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            E[j] = wells[i];
            pq.emplace(E[j], j);
        }
        for (auto p: pipes) {
            int u = p[0];
            int v = p[1];
            int w = p[2];
            G[u].emplace_back(v, w);
            G[v].emplace_back(u, w);
        }

        // Prim's Algorithm
        int ret = 0;
        while (!pq.empty()) {
            pii cur = pq.top();
            pq.pop();
            if (seen[cur.Y]) continue;
            seen[cur.Y] = true;
            ret += E[cur.Y];
            for (auto nxt: G[cur.Y]) {
                if (E[nxt.X] > nxt.Y) {
                    E[nxt.X] = nxt.Y;
                    pq.emplace(E[nxt.X], nxt.X);
                }
            }
        }
        return ret;
    }
};
