#define ALL(x) (x).begin(), (x).end()
typedef vector<int> vin;
const int MAXN = 1005;
const int MAXP = 1e4 + 5;
bool seen[MAXN];
int px[MAXN];
int py[MAXN];
vin X[MAXP];
vin Y[MAXP];

class Solution {
    vector<vector<int>> G;
public:
    int removeStones(vector<vector<int>>& stones) {
        G = move(stones);
        for (int i = 0; i < MAXP; ++i) {
            X[i].clear();
            Y[i].clear();
        }
        int N = G.size();
        for (int i = 0; i < N; ++i) {
            X[G[i][0]].push_back(i);
            Y[G[i][1]].push_back(i);
            seen[i] = false;
        }
        for (int i = 0; i < MAXP; ++i) {
            sort(ALL(X[i]));
            sort(ALL(Y[i]));
            for (unsigned j = 0; j < X[i].size(); ++j) {
                px[X[i][j]] = j;
            }
            for (unsigned j = 0; j < Y[i].size(); ++j) {
                py[Y[i][j]] = j;
            }
        }
        int C = 0;
        for (int i = 0; i < N; ++i) if (!seen[i]) {
            dfs(i);
            ++C;
        }
        return (N - C);
    }

private:
    void dfs(int cur) {
        if (seen[cur]) {
            return;
        }
        seen[cur] = true;
        const vin& row = X[G[cur][0]];
        const vin& col = Y[G[cur][1]];
        if (py[cur] > 0) dfs(col[py[cur] - 1]);
        if (px[cur] + 1 < row.size()) dfs(row[px[cur] + 1]);
        if (py[cur] + 1 < col.size()) dfs(col[py[cur] + 1]);
        if (px[cur] > 0) dfs(row[px[cur] - 1]);
    }
};
