#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
typedef vector<int> vin;
enum C {BLU, RED};
const int INFN = 1e9+7;
const int MAXN = 105;
int D[MAXN][2]; // distance
vin G[MAXN][2]; // graph
vin res;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                D[i][j] = INFN;
                G[i][j].clear();
            }
        }
        res.clear();
        for (auto& e: red_edges) {
            G[e[0]][RED].push_back(e[1]);
        }
        for (auto& e: blue_edges) {
            G[e[0]][BLU].push_back(e[1]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                auto& vec = G[i][j];
                sort(ALL(vec));
                vec.erase(unique(ALL(vec)), vec.end());
            }
        }
        bfs();
        res.reserve(n);
        for (int i = 0; i < n; ++i) {
            int d = min(D[i][BLU], D[i][RED]);
            res.push_back((d == INFN) ? -1 : d);
        }
        return res;
    }

private:
    void bfs() {
        queue<pair<int,int>> Q;
        D[0][BLU] = D[0][RED] = 0;
        Q.emplace(0, BLU);
        Q.emplace(0, RED);
        while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            int other = cur.y ^ 1;
            for (int nxt: G[cur.x][other]) {
                if (D[nxt][other] == INFN) {
                    D[nxt][other] = D[cur.x][cur.y] + 1;
                    Q.emplace(nxt, other);
                }
            }
        }
    }
};
